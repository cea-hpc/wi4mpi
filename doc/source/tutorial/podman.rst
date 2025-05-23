Applying Wi4MPI to RedHat container runtime: Podman
===================================================

Learning objectives
-------------------

With these hands-on exercises, participants will learn:

- How to build and execute osu-microbenchmarks into a Podman container using Wi4MPI in preload mode
- How to build and execute osu-microbenchmarks into a Podman container using Wi4MPI in interface mode
- In particular, how to switch between different MPI implementations at runtime thanks to Wi4MPI

Once participants complete these exercises, they will be able to build and launch Podman containers using Wi4MPI in their own environments.

Podman
^^^^^^

Podman is a software tool that you can use to create, run, and manage containers on a Linux operating system. It does not require a daemon to be running in the background, and is similar to Docker in its capabilities for working with containers.
All information in this tutorial can be used with Docker in the same way.
Other tools like Singularity or Apptainer should work too but require more adaptations.

In this document, *host* refers to your own computer (laptop, desktop, cluster...) and *container* refers to
a Podman instance process.

Podman is available through many common package managers such as `pacman`, `apk`, `yum` or `apt`.

See https://podman.io/getting-started/installation

Using Wi4MPI Preload mode with Podman
-------------------------------------

During this tutorial, one will use Podman `--env` and `--volume` options
to link applications inside containers against the MPI implementation available on
the host system.

We present the most direct method for using Wi4MPI to this purpose. More advanced methods 
are available such as using the `wi4mpi.cfg` configuration file override or containers/hosts
system tunings which require more complex examples and explanations.

MPICH containers executed by OpenMPI host
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Let's take the following Dockerfile, which contains osu-microbenchmarks compiled with MPICH:

.. code-block:: docker

   # File name : Dockerfile
   # Build with Podman:
   #
   #   podman build -t omb-mpich .
   #
   # and execute:
   #
   #   podman run omb-mpich mpirun -n 2 osu_bw

   FROM ubuntu:20.04

   # Set the timezone to Paris
   ENV TZ=Europe/Paris
   RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

   ARG OSU_VERSION=5.6.2

   # Install dependencies
   RUN apt-get update && apt-get install -y \
       build-essential \
       git \
       libhwloc-dev \
       make \
       mpich \
       tzdata \
       wget

   # Download and extract osu-benchmarks
   RUN wget https://mvapich.cse.ohio-state.edu/download/mvapich/osu-micro-benchmarks-${OSU_VERSION}.tar.gz && \
       tar xzf osu-micro-benchmarks-${OSU_VERSION}.tar.gz && \
       rm osu-micro-benchmarks-${OSU_VERSION}.tar.gz

   # Build osu-benchmarks
   WORKDIR /osu-micro-benchmarks-${OSU_VERSION}
   RUN ./configure CC=mpicc CXX=mpicxx && \
       make

   # Install osu-benchmarks
   RUN make install && \
       ln -s /usr/local/libexec/osu-micro-benchmarks/mpi/*/* /usr/bin/

   # Create a non-root user named "poduser"
   RUN useradd --create-home --shell /bin/bash poduser

   # Set the working directory to the installation directory
   WORKDIR /

   # Run the container as the "poduser" user
   USER poduser

Then, build and execute it with podman:

.. code-block:: bash

   podman build -t omb-mpich .
   podman run omb-mpich mpirun -n 2 osu_bw

The expected output looks something like this:

.. code-block:: bash

   # OSU MPI Bandwidth Test v5.6.2
   # Size      Bandwidth (MB/s)
   1                       1.31
   2                       3.65
   4                       8.07
   8                      14.39
   [...]

Building containers can take several minutes depending on your computer and network.
This container can be executed with the host system OpenMPI and Wi4MPI as follows:

.. code-block:: bash

   spack unload -a
   spack load openmpi
   spack load wi4mpi

   export OPENMPI_ROOT=/path/to/openmpi

   podman run \
       --volume ${SPACK_ROOT}:${SPACK_ROOT} \
       --env WI4MPI_ROOT=${WI4MPI_ROOT} \
       --env PATH=${PATH} \
       --env OPENMPI_ROOT=${OPENMPI_ROOT} \
       omb-mpich mpirun -F mpich -T openmpi -n 2 -- osu_bw

The idea is to propagate the host environment into the container one, then one should see
a similar output:

.. code-block:: bash

   You are using Wi4MPI-4.0.0 in the preload mode from MPICH to OMPI
   # OSU MPI Bandwidth Test v5.6.2
   # Size      Bandwidth (MB/s)
   1                       6.50
   2                      12.95
   4                      26.23
   8                      52.32

OpenMPI containers executed by MPICH host
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Let's take the following Dockerfile, which contains osu-microbenchmarks compiled with OpenMPI:

.. code-block:: Dockerfile

   # Build with Podman:
   #
   #   podman build -t omb-openmpi .
   #
   # and execute:
   #
   #   podman run omb-openmpi mpirun -n 2 osu_bw

   FROM ubuntu:20.04

   # Set the timezone to Paris
   ENV TZ=Europe/Paris
   RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

   ARG OSU_VERSION=5.6.2

   # Install dependencies
   RUN apt-get update && apt-get install -y \
       build-essential \
       git \
       libhwloc-dev \
       make \
       openmpi-bin \
       tzdata \
       wget

   # Download and extract osu-benchmarks
   RUN wget https://mvapich.cse.ohio-state.edu/download/mvapich/osu-micro-benchmarks-${OSU_VERSION}.tar.gz && \
       tar xzf osu-micro-benchmarks-${OSU_VERSION}.tar.gz && \
       rm osu-micro-benchmarks-${OSU_VERSION}.tar.gz

   # Build osu-benchmarks
   WORKDIR /osu-micro-benchmarks-${OSU_VERSION}
   RUN ./configure CC=mpicc CXX=mpicxx && \
       make

   # Install osu-benchmarks
   RUN make install && \
       ln -s /usr/local/libexec/osu-micro-benchmarks/mpi/*/* /usr/bin/

   # Create a non-root user named "poduser"
   RUN useradd --create-home --shell /bin/bash poduser

   # Set the working directory to the installation directory
   WORKDIR /

   # Run the container as the "poduser" user
   USER poduser

   # Workaround for OpenMPI and Docker compat'
   ENV OMPI_MCA_btl_vader_single_copy_mechanism=none

Then, build and execute it with podman:

.. code-block:: bash

   podman build -t omb-openmpi .
   podman run omb-openmpi mpirun -n 2 osu_bw

One should see the following output:

.. code-block:: bash

   # OSU MPI Bandwidth Test v5.6.2
   # Size      Bandwidth (MB/s)
   1                       1.70
   2                       3.14
   4                      10.92
   8                      22.67

Building containers could take time depending of your computer and network.
This container can be executed using the host's MPICH and Wi4MPI:

.. code-block:: bash

   spack unload -a
   spack load mpich
   spack load wi4mpi

   export MPICH_ROOT=/path/to/mpich

   podman run \
       --volume ${SPACK_ROOT}:${SPACK_ROOT} \
       --env WI4MPI_ROOT=${WI4MPI_ROOT} \
       --env PATH=${PATH} \
       --env MPICH_ROOT=${MPICH_ROOT} \
       omb-openmpi mpirun -F openmpi -T mpich -n 2 -- osu_bw

The goal is to propagate the host environment variables into the container's environment. Doing so should produce an output similar to:

.. code-block:: bash

   You are using Wi4MPI-4.0.0 in the preload mode from OMPI to MPICH
   # OSU MPI Bandwidth Test v5.6.2
   # Size      Bandwidth (MB/s)
   1                       2.60
   2                       5.29
   4                      10.60
   8                      20.80

.. note:: 
   The following message can be safely ignored:
   `Symbol 'ompi_mpi_comm_world' has different size in shared object, consider re-linking`

Using Wi4MPI Interface mode with Podman
---------------------------------------

Below is a Dockerfile containing osu-microbenchmarks, compiled with Wi4MPI:

.. code-block:: dockerfile

   # Build with Podman:
   #
   #   podman build -t omb-wi4mpi .
   #
   # and execute:
   #
   #   podman run omb-wi4mpi mpirun -n 2 -- osu_bw

   FROM ubuntu:20.04

   ARG OSU_VERSION=5.6.2

   # Enable bash "source" in RUN Docker instruction
   RUN rm /bin/sh && ln -s /bin/bash /bin/sh

   # Install Spack dependencies
   RUN apt-get update && apt-get install -y \
       build-essential git gfortran \
       curl wget \
       python3-pip

   # Install Spack
   RUN git clone https://github.com/spack/spack.git /opt/spack
   RUN /opt/spack/bin/spack compiler find

   # Set up Spack environment
   ENV SPACK_ROOT=/opt/spack
   ENV PATH=${SPACK_ROOT}/bin:${PATH}
   ENV MANPATH=${SPACK_ROOT}/share/man:${MANPATH}

   # Install Wi4MPI
   RUN spack install wi4mpi

   # Download and extract osu-benchmarks
   RUN wget https://mvapich.cse.ohio-state.edu/download/mvapich/osu-micro-benchmarks-${OSU_VERSION}.tar.gz && \
       tar xzf osu-micro-benchmarks-${OSU_VERSION}.tar.gz && \
       rm osu-micro-benchmarks-${OSU_VERSION}.tar.gz

   # Build osu-benchmarks with Wi4MPI
   WORKDIR /osu-micro-benchmarks-${OSU_VERSION}

   ## Workaround patch mpicc for configure in interface mode (issue #45) ## [BEGIN] ##
   RUN source /opt/spack/share/spack/setup-env.sh && \
       spack load wi4mpi && \
       sed -i 's@WI4MPI_LDFLAGS="-L${WI4MPI_ROOT}/lib -lmpi"@WI4MPI_LDFLAGS="-L${WI4MPI_ROOT}/lib -Wl,--push-state,--as-needed -lmpi -Wl,--pop-state"@' $(which mpicc)
   ## [END] ##

   ## See github issue #46 for more details about ld "--no-as-needed" option
   RUN source /opt/spack/share/spack/setup-env.sh && \
       spack load wi4mpi && \
       ./configure CC=mpicc CXX=mpicxx LDFLAGS="-Wl,--no-as-needed" && \
       make

   # Install osu-benchmarks
   RUN make install && \
       ln -s /usr/local/libexec/osu-micro-benchmarks/mpi/*/* /usr/bin/

   # Source Spack and Wi4MPI before any command
   RUN echo "#!/bin/bash" > /entrypoint.sh
   RUN echo "source /opt/spack/share/spack/setup-env.sh" >> /entrypoint.sh
   RUN echo "spack load wi4mpi" >> /entrypoint.sh
   RUN echo '$@' >> /entrypoint.sh
   RUN chmod +x /entrypoint.sh
   ENTRYPOINT ["/entrypoint.sh"]

   # Create a non-root user named "poduser"
   RUN useradd --create-home --shell /bin/bash poduser

   # Set the working directory to the installation directory
   WORKDIR /

   # Run the container as the "poduser" user
   USER poduser

.. note::
   If you encounter the error `undefined reference to dlopen`, add `LDFLAGS=-Wl,--no-as-needed` (see issue #46 for details).

To build and run the container using Podman:

.. code-block:: bash

   podman build -t omb-wi4mpi .
   podman run omb-wi4mpi mpirun -n 2 -- osu_bw

Building containers might take some time depending on your computer's performance and your network speed.
But, there no MPI implementation inside the container, so we need to mount the host one and
explain to Wi4MPI how to use it.

This container can be executed with the host system MPICH as follow:

.. code-block:: bash

   spack unload -a
   spack load mpich
   export MPICH_ROOT=/path/to/mpich

   podman run \
       --volume ${SPACK_ROOT}:${SPACK_ROOT} \
       --env PATH=${PATH} \
       --env MPICH_ROOT=${MPICH_ROOT} \
       omb-wi4mpi mpirun -T mpich -n 2 -- osu_bw

The idea is to propagate the host environment into the container one, then one should see
a similar output:

.. code-block:: bash

   You are using Wi4MPI-4.0.0 in the  interface mode from Interface to MPICH
   # OSU MPI Bandwidth Test v5.6.2
   # Size      Bandwidth (MB/s)
   1                       2.49
   2                       5.03
   4                      10.23
   8                      20.41

.. note::
   1. The host system does not require Wi4MPI for this translation; the container's Wi4MPI is utilized.
   2. The warning message `Symbol 'ompi_mpi_comm_world' has different size in shared object, consider re-linking` can be disregarded.

Here is the same execution with OpenMPI host:

.. code-block:: bash

   spack unload -a
   spack load openmpi
   export OPENMPI_ROOT=/path/to/openmpi

   podman run \
       --volume ${SPACK_ROOT}:${SPACK_ROOT} \
       --env PATH=${PATH} \
       --env OPENMPI_ROOT=${OPENMPI_ROOT} \
       omb-wi4mpi mpirun -T openmpi -n 2 -- osu_bw

With the above configuration, expect an output similar to:

.. code-block:: bash

   You are using Wi4MPI-4.0.0 in the interface mode from Interface to OMPI
   # OSU MPI Bandwidth Test v5.6.2
   # Size      Bandwidth (MB/s)
   1                       3.66
   2                       7.63
   4                      15.32
   8                      30.95


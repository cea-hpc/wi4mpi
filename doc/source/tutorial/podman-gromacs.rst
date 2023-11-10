Applying Wi4MPI to a Gromacs Podman container
=============================================

Learning objectives
-------------------

With these hands-on exercises, participants will learn:

- how to build and execute Gromacs into a Podman container using Wi4MPI in preload mode
- how to build and execute Gromacs into a Podman container using Wi4MPI in interface mode
- in particular, how to switch between different MPI implementations at runtime thanks to Wi4MPI

Once participants complete these exercises, they will be able to build and launch Podman containers using Wi4MPI in their own environments.

Podman
------

Podman is a software tool that you can use to create, run, and manage containers on a Linux operating system. It does not require a daemon to be running in the background, and is similar to Docker in its capabilities for working with containers.
All informations in this tutorial can be used with Docker in the same way.
Others tools like Singularity or Apptainer should work too but require more adaptations.

In this document, ``host`` refers to your own computer (laptop, desktop, cluster...) and ``container`` refers to a Podman instance process.

Using Wi4MPI Preload mode with Podman
-------------------------------------

During this tutorial, one will use Podman ``--env`` and ``--volume`` options to link applications inside containers against the MPI implementation available on the host system.

We present the most direct method for using wi4mpi to this purpose. More advanced methods are available such as using the ``wi4mpi.cfg`` configuration file override or containers/hosts system tunings which require more complex examples and explanations.

MPICH containers executed by OpenMPI host
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Let's take the following Dockerfile, which contains Gromacs compiled with MPICH:

.. code-block:: dockerfile

   # File name : Dockerfile
   # Build with Podman:
   #
   #   podman build -t gromacs-mpich .
   #
   # and execute:
   #
   #   podman run gromacs-mpich mpirun -n 2 gmx_mpi mdrun -v -resethway -nsteps 10000 -ntomp 2 -s benchMEM.tpr

   FROM ubuntu:22.04

   # Set the timezone to Paris
   ENV TZ=Europe/Paris
   RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

   ARG GROMACS_VERSION=2023

   # Install dependencies
   RUN apt-get update && apt-get install -y \
       build-essential \
       git \
       libhwloc-dev \
       make \
       mpich \
       tzdata \
       wget \
       cmake \
       zip

   # Download and extract Gromacs
   RUN wget https://ftp.gromacs.org/gromacs/gromacs-${GROMACS_VERSION}.tar.gz && \
       tar xzf gromacs-${GROMACS_VERSION}.tar.gz && \
       rm gromacs-${GROMACS_VERSION}.tar.gz

   # Build Gromacs
   WORKDIR /gromacs-${GROMACS_VERSION}
   RUN mkdir build && cd build && \
       cmake /gromacs-${GROMACS_VERSION}/ -DCMAKE_INSTALL_PREFIX=/gromacs-${GROMACS_VERSION}/install -DGMX_MPI=on -DGMX_BUILD_OWN_FFTW=ON && \
       make install && \
       ln -s /gromacs-${GROMACS_VERSION}/install/bin/* /usr/bin/

   # Create a non-root user named "poduser"
   RUN useradd --create-home --shell /bin/bash poduser

   # Set the working directory to the installation directory
   WORKDIR /home/poduser

   # Run the container as the "poduser" user
   USER poduser

   RUN echo "source /gromacs-${GROMACS_VERSION}/install/bin/GMXRC.bash" >> ~/.bashrc

   # Get Gromacs benchmark (benchMEM.tpr file)
   RUN wget https://www.mpinat.mpg.de/benchMEM && \
       unzip benchMEM

Then, build and execute it with podman:

.. code-block:: bash

   podman build -t gromacs-mpich .
   podman run gromacs-mpich mpirun -n 2 gmx_mpi mdrun -v -resethway -nsteps 10000 -ntomp 2 -s benchMEM.tpr

The expected output looks something like this:

.. code-block:: bash

   [...]
                  Core t (s)   Wall t (s)        (%)
          Time:      777.843      194.461      400.0
                    (ns/day)    (hour/ns)
   Performance:        4.444        5.401

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
       gromacs-mpich mpirun -F mpich -T openmpi -n 2 -- gmx_mpi mdrun -v -resethway -nsteps 10000 -ntomp 2 -s benchMEM.tpr

The idea is to propagate the host environment into the container one, then you should see a similar output:

.. code-block:: bash

   [...]
               Core t (s)   Wall t (s)        (%)
       Time:      777.843      194.461      400.0
                 (ns/day)    (hour/ns)
   Performance:        4.444        5.401

OpenMPI containers executed by MPICH host
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Let's take the following Dockerfile, which contains Gromacs compiled with OpenMPI:

.. code-block:: dockerfile

   # Build with Podman:
   #
   #   podman build -t gromacs-openmpi .
   #
   # and execute:
   #
   #   podman run gromacs-openmpi mpirun -n 2 gmx_mpi mdrun -v -resethway -nsteps 10000 -ntomp 2 -s benchMEM.tpr
   #
   FROM ubuntu:22.04
   ...
   RUN wget https://www.mpinat.mpg.de/benchMEM && \
       unzip benchMEM

Then, build and execute it with podman:

.. code-block:: bash

   podman build -t gromacs-openmpi .
   podman run gromacs-openmpi mpirun -n 2 gmx_mpi mdrun -v -resethway -nsteps 10000 -ntomp 2 -s benchMEM.tpr

One should see the following output:

.. code-block:: bash

   [...]
               Core t (s)   Wall t (s)        (%)
       Time:      777.843      194.461      400.0
                 (ns/day)    (hour/ns)
   Performance:        4.444        5.401

Building containers could take time depending on your computer and network.
This container can be executed with the host system OpenMPI and Wi4MPI as follows:

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
       gromacs-openmpi mpirun -F openmpi -T mpich -n 2 -- gmx_mpi mdrun -v -resethway -nsteps 10000 -ntomp 2 -s benchMEM.tpr

The idea is to propagate the host environment into the container. One should then observe an output similar to:

.. code-block:: bash

   [...]
               Core t (s)   Wall t (s)        (%)
       Time:      777.843      194.461      400.0
                 (ns/day)    (hour/ns)
   Performance:        4.444        5.401

.. note::

   The following message can be ignored: `gmx_mpi: Symbol `ompi_mpi_comm_world' has different size in shared object, consider re-linking`.

Using Wi4MPI Interface mode with Podman
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Let's take the following Dockerfile, which contains osu-microbenchmarks compiled with Wi4MPI:

.. code-block:: dockerfile

   FROM ubuntu:22.04

   # Enable bash "source" in RUN Docker instruction
   RUN rm /bin/sh && ln -s /bin/bash /bin/sh

   # Set the timezone to Paris
   ENV TZ=Europe/Paris
   RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

   ARG GROMACS_VERSION=2023

   # Install Spack an Gromacs dependencies
   RUN apt-get update && apt-get install -y \
       build-essential git gfortran \
       curl wget \
       python3-pip cmake zip

   # Install Spack
   RUN git clone https://github.com/spack/spack.git /opt/spack
   RUN /opt/spack/bin/spack compiler find

   # Set up Spack environment
   ENV SPACK_ROOT=/opt/spack
   ENV PATH=${SPACK_ROOT}/bin:${PATH}
   ENV MANPATH=${SPACK_ROOT}/share/man:${MANPATH}

   # Install Wi4MPI
   RUN spack install wi4mpi

   # Download and extract Gromacs
   RUN wget https://ftp.gromacs.org/gromacs/gromacs-${GROMACS_VERSION}.tar.gz && \
       tar xzf gromacs-${GROMACS_VERSION}.tar.gz && \
       rm gromacs-${GROMACS_VERSION}.tar.gz

   # Build Gromacs
   WORKDIR /gromacs-${GROMACS_VERSION}

   ## Workaround patch mpicc for configure in interface mode (issue #45) ## [BEGIN] ##
   RUN source /opt/spack/share/spack/setup-env.sh && \
       spack load wi4mpi && \
       sed -i 's@WI4MPI_LDFLAGS="-L${WI4MPI_ROOT}/lib -lmpi"@WI4MPI_LDFLAGS="-L${WI4MPI_ROOT}/lib -Wl,--push-state,--as-needed -lmpi -Wl,--pop-state"@' $(which mpicc)
   ## [END] ##

   # Build Gromacs with Wi4MPI compiler
   RUN mkdir build && cd build && \
       source /opt/spack/share/spack/setup-env.sh && \
       spack load wi4mpi && \
       cmake /gromacs-${GROMACS_VERSION}/ -DCMAKE_INSTALL_PREFIX=/gromacs-${GROMACS_VERSION}/install -DGMX_MPI=on -DGMX_BUILD_OWN_FFTW=ON && \
       make install && \
       ln -s /gromacs-${GROMACS_VERSION}/install/bin/* /usr/bin/

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
   WORKDIR /home/poduser

   # Run the container as the "poduser" user
   USER poduser

   RUN echo "source /gromacs-${GROMACS_VERSION}/install/bin/GMXRC.bash" >> ~/.bashrc

   # Get Gromacs benchmark (benchMEM.tpr file)
   RUN wget https://www.mpinat.mpg.de/benchMEM && \
       unzip benchMEM

.. note::

   If you encounter the `undefined reference to dlopen` error, add `LDFLAGS=-Wl,--no-as-needed` (see issue #46)

Then, build and execute it with podman:

.. code-block:: bash

   podman build -t gromacs-wi4mpi .
   podman run gromacs-wi4mpi mpirun -n 2 -- gmx_mpi mdrun -v -resethway -nsteps 10000 -ntomp 2 -s benchMEM.tpr

Building containers could take time depending on your computer and network.
To import the pre-built image, execute the following:

.. code-block:: bash

   wget https://url/to/gromacs-wi4mpi-img.tar.gz
   podman import gromacs-wi4mpi-img.tar.gz gromacs-wi4mpi

A pure Wi4MPI container cannot function independently since it does not contain an internal MPI implementation. Therefore, it's necessary to mount the MPI from the host system and instruct Wi4MPI on its usage.

Executing with MPICH Host System
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Execute the container using the MPICH from the host system as shown:

.. code-block:: bash

   spack unload -a
   spack load mpich

   export MPICH_ROOT=/path/to/mpich

   podman run \
       --volume ${SPACK_ROOT}:${SPACK_ROOT} \
       --env PATH=${PATH} \
       --env MPICH_ROOT=${MPICH_ROOT} \
       gromacs-wi4mpi mpirun -T mpich -n 2 -- gmx_mpi mdrun -v -resethway -nsteps 10000 -ntomp 2 -s benchMEM.tpr

Once executed, you should see an output similar to:

.. code-block:: bash

   [...]
               Core t (s)   Wall t (s)        (%)
       Time:      777.843      194.461      400.0
                 (ns/day)    (hour/ns)
   Performance:        4.444        5.401

.. note::

   The host system doesn't need to have Wi4MPI installed; the container's implementation is used for translation.

.. warning::

   You can safely ignore the following message: `Symbol 'ompi_mpi_comm_world' has different size in shared object, consider re-linking`.

Executing with OpenMPI Host System
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

For execution using the OpenMPI host, follow these steps:

.. code-block:: bash

   spack unload -a
   spack load openmpi

   export OPENMPI_ROOT=/path/to/openmpi

   podman run \
       --volume ${SPACK_ROOT}:${SPACK_ROOT} \
       --env PATH=${PATH} \
       --env OPENMPI_ROOT=${OPENMPI_ROOT} \
       gromacs-wi4mpi mpirun -T openmpi -n 2 -- gmx_mpi mdrun -v -resethway -nsteps 10000 -ntomp 2 -s benchMEM.tpr

And the expected output remains the same:

.. code-block:: bash

   [...]
               Core t (s)   Wall t (s)        (%)
       Time:      777.843      194.461      400.0
                 (ns/day)    (hour/ns)
   Performance:        4.444        5.401


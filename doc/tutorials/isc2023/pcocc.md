*This is a **sample** of our ISC23 submission Module 3:
Applying Wi4MPI to key use cases in HPC. It is not intended to be the final and complete module.* 

# Applying Wi4MPI to CEA's container runtime: pcocc

## Learning objectives

With these hands-on exercises, participants will learn:

 -  how to build and execute OSU microbenchmarks into a PCOCC container using Wi4MPI in preload mode
 -  in particular, how to switch between different MPI implementations at runtime thanks to Wi4MPI

Once participants complete these exercises, they will be able to build and launch PCOCC containers using Wi4MPI in their own environments.

### Warning

For disambiguation, modules from Environment Modules will be referred to as 'modules' in the following, and modules for pcocc will be referred to as 'PCOCC modules'.

## PCOCC

PCOCC (pronounced peacock) stands for Private Cloud On a Compute Cluster. It allows users to launch containers as well as to host clusters of VMs (Virtual Machines) on compute nodes. This can be used to facilitate deployment of applications by packaging them as container images or virtual appliances, or to setup custom environments for development or test purposes. Container images built with popular tools such as Docker or Podman can be launched interactively or within Slurm jobs. Clusters of VM can be instanciated on the fly with a single command which allocates the necessary resources to host the virtual machines, including private Ethernet and/or InfiniBand networks, creates temporary disk images from the selected templates (using CoW) and instantiates as many virtual machines as required. Facilities are provided to replicate the host environment and access user directories from the VMs or to create new VM templates from scratch. 

## PCOCC modules

It is possible to create PCOCC modules to configure easily container environments and to ease their integration into the host environment.

PCOCC modules are yaml structures that can define different properties:
 - `mount`: to mount files or directories into the container
 - `env`: to define environment variables
 - `pathprefix`: to update path environment variables
 - `inherits`: do declare inheritance from another PCOCC module

They are defined with the following syntax:

```yaml
modules:
  module1:
    <...>

  module2:
    <...>
```

And they are used as followed:

```bash
pcocc run -M module1 <...>
```

## PCOCC containers configuration for network and scheduler

To be fully compatible with the network and the scheduler available on your system, you can define custom PCOCC modules.

For example, using InfiniBand network and SLURM scheduler, you can define PCOCC modules that would look like the following:

 - for SLURM:
```yaml
    slurm:
        env:
            - 're(SLURM.*)'
            - 're(PMI.*)'
        mounts:
            libslurm:
                source: /usr/lib64/libslurm.so.<version>
                destination: /pcocc/lib/pmi/libslurm.so.<version>
            slurmspool:
                source: /var/spool/slurmd/
            libevent:
                source: /lib64/libevent-2.1.so.<version>
                destination: /pcocc/lib/pmi/libevent-2.1.so.<version>
            libevent-core:
                source: /lib64/libevent_core-2.1.so.<version>
                destination: /pcocc/lib/pmi/libevent_core-2.1.so.<version>
            libevent_pthread:
                source: /lib64/libevent_pthreads-2.1.so.<version>
                destination: /pcocc/lib/pmi/libevent_pthreads-2.1.so.<version>
            hwloc-sys:
                source: /usr/lib64/libhwloc.so.<version>
                destination: /pcocc/lib/pmi/libhwloc.so.<version>
            libtdl:
                source: /usr/lib64/libltdl.so.<version>
                destination: /pcocc/lib/pmi/libltdl.so.<version>
        pathprefix:
            - LD_LIBRARY_PATH=/pcocc/lib/pmi/:<path-to-pmi-root>/lib
```

 - for InfiniBand:
```
    infiniband:
        mounts:
            verbsconfdir:
                source: /etc/libibverbs.d
            verbs_rdmacm:
                source: /usr/lib64/librdmacm.so.<version>
                destination: /pcocc/lib/verbs/librdmacm.so.<version>
            verbs_mlx5:
                source: /usr/lib64/libmlx5.so.<version>
                destination: /pcocc/lib/verbs/libmlx5.so.<version>
            verbs_mlx5_rdma:
                source: /usr/lib64/libibverbs/libmlx5-rdmav34.so
                destination: /pcocc/lib/verbs/libmlx5-rdmav34.so
            verbs:
                source: /usr/lib64/libibverbs.so.<version>
                destination: /pcocc/lib/verbs/libibverbs.so.<version>
            libnl3:
                source: /lib64/libnl-3.so.<version>
                destination: /pcocc/lib/verbs/libnl-3.so.<version>
            libnl3route:
                source: /lib64/libnl-route-3.so.<version>
                destination: /pcocc/lib/verbs/libnl-route-3.so.<version>
            libpciaccess:
                source: /lib64/libpciaccess.so.<version>
                destination: /pcocc/lib/verbs/libpciaccess.so.<version>
            libxml2:
                source: /lib64/libxml2.so.<version>
                destination: /pcocc/lib/verbs/libxml2.so.<version>
            libnuma:
                source: /lib64/libnuma.so.<version>
                destination: /pcocc/lib/verbs/libnuma.so.<version>
            dev:
                source: /dev/infiniband/
                options: ["dev"]
            knem:
                source: /dev/knem
                options: ["dev"]
        pathprefix:
            - LD_LIBRARY_PATH=/pcocc/lib/verbs/
            - LD_LIBRARY_PATH=/opt/mellanox/mxm/lib/
```

## Requirements for Wi4MPI

Running PCOCC containers through Wi4MPI requires the creation of a specific PCOCC module with some adaptations:
- inheritance from network and scheduler PCOCC modules (for example `slurm` and `infiniband` PCOCC modules defined above)
- `hwloc` topo file (which are also needed for Open MPI modules)
- environment variables to setup Wi4MPI (usually defined in Wi4MPI module)
- environment variables for Open MPI (usually defined in Open MPI module)
- environment variables for UCX if using IB (usually defined in UCX module)
- `LD_PRELOAD` for Wi4MPI to bypass links and force Wi4MPI usage
- update of `LD_LIBRARY_PATH` and `PATH` variables

### Example of an MPICH to Open MPI pcocc module:

This translates to the following PCOCC module to go from MPICH to Open MPI with Wi4MPI:
```yaml
  wi4mpi-from-mpich-to-ompi:
    inherits:
       - slurm
       - infiniband
    mounts:
      hwloc-xml:
        source: /etc/hwloc-<hwloc-version>.xml
    env:
      #WI4MPI
       - WI4MPI_TO=OpenMPI-4.1.4
       - WI4MPI_F77=ifort
       - WI4MPI_CXX=icpc
       - WI4MPI_FROM=MPICH-4.0.0
       - WI4MPI_WRAPPER_LIB=<path-to-wi4mpi-root>/lib_OMPI/libwi4mpi_OMPI.so
       - WI4MPI_RUN_MPI_F_LIB=<path-to-openmpi-root>/lib/libmpi_mpifh.so
       - WI4MPI_FC=ifort
       - MPI_WI4MPI_LIBDIR=<path-to-wi4mpi-root>/lib
       - FEATURE_WI4MPI_MPI_COMPILER_TOOLCHAIN=
       - WI4MPI_RUN_MPI_C_LIB=<path-to-openmpi-root>/lib/libmpi.so
       - MPI_WI4MPI_TOOLCHAIN=
       - FEATURE_WI4MPI_FROM_INTELMPI_TOOLCHAIN=
       - MPI_WI4MPI_EXEDIR=<path-to-wi4mpi-root>/bin
       - MPI_WI4MPI_ROOT=<path-to-wi4mpi-root>
       - WI4MPI_APP_INCLUDES=<path-to-wi4mpi-root>/INTERNAL/preload/include/MPICH_OMPI
       - FLAVOR_WI4MPI_TOOLCHAIN=
       - WI4MPI_RUN_MPIIO_LIB=<path-to-openmpi-root>/lib/libmpi.so
       - WI4MPI_CC=icc
       - WI4MPI_VERSION=3.6.4
       - WI4MPI_ROOT=<path-to-wi4mpi-root>
       - FEATURE_WI4MPI_TO_OPENMPI_TOOLCHAIN=
       - WI4MPI_RUN_MPIIO_F_LIB=<path-to-openmpi-root>/lib/libmpi_mpifh.so
       - WI4MPI_RUN_MPIIO_C_LIB=<path-to-openmpi-root>/lib/libmpi.so
      #Open MPI & UCX
       - OMPI_MCA_mca_base_param_files=<path-to-openmpi-configfiles>/openmpi-mca-params.conf
       - OMPI_MCA_btl_openib_device_param_files=<path-to-openmpi-configfiles>/mca-btl-openib-device-params.ini
       - ROMIO_HINTS=<path-to-openmpi-configfiles>/romio-hints
       - <UCX configuration environment variables (eg UCX_RC_MLX5_SL or UCX_TLS)>
    pathprefix:
       - "LD_PRELOAD='<path-to-wi4mpi-root>/libexec/wi4mpi/libwi4mpi_MPICH_OMPI.so \
                     <path-to-openmpi-root>/lib/libmpi.so \
                     <path-to-openmpi-root>/lib/libmpi_mpifh.so'"
       - "LD_LIBRARY_PATH=<path-to-wi4mpi-root>/lib:\
                          <path-to-wi4mpi-root>/libexec/wi4mpi/fakelibCXX:\
                          <path-to-wi4mpi-root>/libexec/wi4mpi/fakelibMPICH:\
                          <path-to-ucx-root>/lib:\
                          <path-to-openmpi-root>/lib:\
                          <path-to-openmpi-root>/lib/openmpi"
```

A good practice is to have all paths that appear in `LD_LIBRARY_PATH` when you are using the target MPI locally in the `LD_LIBRARY_PATH` injected inside the container.

### Usage

It may then be used as follows:
```bash
pcocc run -I <image> -M wi4mpi-from-mpich-to-ompi <...>
```

## Building and importing a container

In many cases, the cluster you will access running PCOCC won't have a direct Internet access. It is thus advised to build locally your container image in the standard OCI format with your favorite tool (Docker, Podman...).

You can build your container using the following Dockerfile:
```dockerfile
FROM ubuntu:20.04

# Set the timezone to Paris
ENV TZ=Europe/Paris
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

ARG OSU_VERSION=5.7.0

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

# Create a non-root user named "ctruser"
RUN useradd --create-home --shell /bin/bash ctruser

# Set the working directory to the installation directory
WORKDIR /

# Run the container as the "ctruser" user
USER ctruser
```

Once your image is built, it can be saved; for example using:

```bash
docker save osu-mpich > osu-mpich.tar
```

or:

```bash
podman save osu-mpich -o osu-mpich.tar
```

And then it can be imported within PCOCC:

```bash
pcocc image import docker-archive:osu-mpich.tar user:osu-mpich
```

## Running a MPICH container in an Open MPI host

Once the image is available and the PCOCC modules are properly defined, the container embedding MPICH can be launched on a host using Open MPI with the following:

```bash
pcocc run -I osu-mpich -M wi4mpi-from-mpich-to-ompi mpirun -F mpich -T openmpi -n 2 -- osu_bw
```

You should get a similar output:

```bash
You are using Wi4MPI-3.6.4 with the mode preload From MPICH To OMPI
# OSU MPI Bandwidth Test v5.7
# Size      Bandwidth (MB/s)
1                       6.50
2                      12.95
4                      26.23
8                      52.32
```
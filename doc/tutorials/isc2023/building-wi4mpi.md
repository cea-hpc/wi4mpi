*This is a **sample** of our ISC23 submission Module 2: Changing MPI libraries dynamically with Wi4MPI. It is not intended to be the final and complete module.*

# How to install Wi4MPI

## Learning objectives

With these hands-on exercises, participants will learn:
 - how to configure their environment in preparation for Wi4MPI installation
 - how to install Wi4MPI using the Spack package manager
 - how to configure Wi4MPI in their environment to efficiently use the library

Once participants complete these exercises, they will have a working Wi4MPI environment ready to use.

## Installing Wi4MPI using Spack

Wi4MPI is available through Spack and the Spack package is updated with each new version.

### Setup

To install Wi4MPI, one needs to first install a compiler supporting C, C++ and Fortran, given that these compilers are needed for MPI compilation. For example:

 - Debian-like distro:
 
```bash
(sudo) % apt install gcc-11 gc++-11 gfortran-11
```

 - RHEL-like distro:
 
```bash
(sudo) % yum install gcc gcc-gc++ gcc-gfortran
```

### Spack installation

Then, install and configure Spack using the compilers previously installed:

```bash
git clone https://github.com/spack/spack
source spack/share/spack/setup-env.sh
spack compiler find
```

Once Spack is configured, you can install Wi4MPI and an alternative MPI implementation:

```bash
spack install wi4mpi ^openmpi
spack install mpich
```

### Wi4MPI configuration

Once Wi4MPI and the different MPI implementations are installed, Wi4MPI needs to be configured. To do so, the paths to the available MPI implementations need to be specified:

```bash
spack load wi4mpi
echo 'OPENMPI_DEFAULT_ROOT="</path/to/openmpi/root>"' >> $WI4MPI_ROOT/etc/wi4mpi.cfg
echo 'MPICH_DEFAULT_ROOT="</path/to/mpich/root>"' >> $WI4MPI_ROOT/etc/wi4mpi.cfg
```

The above paths need to be updated with the actual paths on your system.


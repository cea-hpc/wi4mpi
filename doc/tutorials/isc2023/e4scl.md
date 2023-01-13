*This is a **sample** of our ISC23 submission Module 3:
Applying Wi4MPI to key use cases in HPC. It is not intended to be the final and complete module.* 

#  Applying Wi4MPI to the US Exascale Computing Project: E4S-CL

<!--
# Wi4MPI
Wi4MPI is an initialism for *wrapper interface for MPI*. It acts as an additional layer of abstraction between the MPI library used by an application and the system-native MPI libraries. This allows it to dynamically translate MPI calls between otherwise incompatible implementations. For example, it can run an OpenMPI application on a system with MVAPICH2 libraries. 
-->

Wi4MPI supports two modes of operation: preload and interface. In preload mode, the library is attached to an already-built application with `LD_PRELOAD` and translates calls made by the MPI interface the application was compiled against to the MPI interface present on the system. In interface mode, the application is linked directly against Wi4MPI and has no specific native MPI implementation.

We will be using Wi4MPI in preload mode in this guide.

## E4S-CL
E4S-CL is a container launch tool created as part of E4S and is intended to make it easier to launch containerized MPI applications. Containers are launched with *profiles* which contain a list of host-MPI to container-MPI libraries to bind in when running the container.

E4S-CL has integrated Wi4MPI support and will manage launching a container with Wi4MPI in preload mode.

## Installation and set-up

### Install E4S-CL
The simplest method to install E4S-CL is to install it into a Python virtual environment. This requires Python 3.7 or later.
```
mkdir ~/e4s-cl && cd ~/e4s-cl
python3 -m venv .
source bin/activate
pip3 install https://github.com/E4S-Project/e4s-cl/archive/refs/tags/v1.0.1.tar.gz
```


### Install Wi4MPI
Installing Wi4MPI is a little more involved. We will need to build it from source and install it into a location we can access. 
```
mkdir ~/wi4mpi
wget https://github.com/cea-hpc/wi4mpi/archive/refs/tags/v3.6.4.tar.gz
tar -xvf v3.6.4.tar.gz
cd wi4mpi-3.6.4/
mkdir build && cd build
cmake3 -DWI4MPI_COMPILER=GNU -DCMAKE_INSTALL_PREFIX=~/wi4mpi ../
make
make install
```


### Create a container image
Next, we will create a container image with an MPI application in it to use with E4S-CL and Wi4MPI using the following `Dockerfile`. 

```Dockerfile
FROM centos:7

RUN yum update -y && yum install -y make wget tar git curl gcc-gfortran gcc-c++ openmpi3-devel
RUN source /etc/profile \
    && module load mpi/openmpi3-x86_64 \
    && mkdir -p /opt/mpiBench /tmp/build \
    && cd /tmp/build \
    && git clone https://github.com/LLNL/mpiBench.git \
    && cd mpiBench \
    && make \
    && cp ./mpiBench /opt/mpiBench \
    && cd /opt/mpiBench \
    && rm -rf /tmp/build

WORKDIR /opt/mpiBench
```

Once the container is built, we need to convert it to Singularity format.
```
podman build -t mpibench-ompi .
podman save -o mpibench-ompi.tar mpibench-ompi
singularity build mpibench-ompi.sif docker-archive:mpibench-ompi.tar
```

## Creating an E4S-CL launch profile
E4S-CL works with launch profiles which inform it about which libraries need to be bound in to a container.
Configuration data, including profiles, is stored at `~/.local/e4s_cl/`.

Ideally, the application used to generate a profile should be the same as the containerized application. This is not always possible though. At minimum, the proxy application used for profile generation should be written in the same language as the real application. For example, generating a profile with a proxy application written in C may not work for running an application built with C++.

### Profile generation
We will be using the same application as inside the container for profile generation.

First, download and build mpiBench:
```
git clone https://github.com/LLNL/mpiBench.git
cd mpiBench
make
```

Next, we'll run mpiBench with E4S-CL to detect a profile:
```
e4s-cl profile detect -p host-mv2 srun -n 2 ./mpiBench
```
Note: In this example, the host system uses the SLURM scheduler and provides a MVAPICH2 MPI implementation. The MPI launch command will vary depending on your scheduler.

### Adding Wi4MPI
Next we'll update the generated profile to set a default launch backend (Singularity) and a default path to Wi4MPI.
```
e4s-cl profile edit host-mv2 --backend singularity --wi4mpi=~/wi4mpi
```

## Container launch
Once the profile is in place, we can launch the container image we created earlier with E4S-CL.

```bash
e4s-cl launch --profile host-mv2 \
              --from openmpi \
              --image ~/mpibench-ompi.sif \
              srun -p pdebug -N 2 -n 4 \
              ./mpiBench
```

Here's a brief summary of the meaning of each of the launch parameters used above:
| Option       | Meaning |
| ---          | ---      |
| `--profile`  | Name of the launch profile to use |
| `--from`     | Specifies which MPI implementation is present inside the container |
| `srun ...`   | This specifies which arguments to use with the MPI launcher. This is executed outside of the container. Note that the `srun` arguments you give to E4S-cl may need to have a space between the flag and the argument. For example, `-N2` rather than `-N 2` will result in a syntax error and `-ppdebug` rather than `-p pdebug` will quietly cause the job to be scheduled to the default queue rather than `pdebug`. |
| `./mpiBench` | Specifies the binary inside the container to launch. Relative to the `WORKDIR` in the original `Dockerfile`. |

If all goes well, you should see the output of `mpiBench` once the containers are set up by E4S-CL.

*This is a **sample** of our ISC23 submission Module 2: Changing MPI libraries dynamically with Wi4MPI. It is not intended to be the final and complete module.*

# Translating MPI dynamically using Preload mode

## Learning objectives

With these hands-on exercises, participants will learn:
 - how to execute simple programs using Wi4MPI in preload mode
 - in particular, how to switch between different MPI implementations at runtime thanks to Wi4MPI
 - how to execute benchmarks and measure Wi4MPI performance
 - how to use Wi4MPI preload mode with Slurm

With these exercises, participants will also observe ABI incompatibility directly.

Once participants complete these exercises, they will be able to launch programs using Wi4MPI in their own environments.

## Running MPI "Hello world"

We will use a simple "Hello world!" program written in C:

```C
#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);

    int size, rank;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);

    printf("Hello world from processor %s, rank %d out of %d processors\n",
           processor_name, rank, size);

    MPI_Finalize();
}

```

### Compilation and first execution

The previous program may be compiled using MPICH:

```bash
spack unload -a
spack load mpich
mpicc hello.c -o hello
```

and executed:

```bash
mpirun -np 4 ./hello
```

### Switching MPI implementations using Wi4MPI

You can check that ABI-compatibility is still an issue (!):

```bash
spack unload -a
spack load openmpi
mpirun -np 4 ./hello
```

It is then possible to use OpenMPI to run this program successfully with Wi4MPI; to do so, you'll need to specify the `-F` and `-T` options to `mpirun`. `-F` (*from*) specifies which MPI implementation was used to compiled the program whereas `-T` (*to*) specifies which MPI implementation to use:

```bash
spack unload -a
spack load wi4mpi
mpirun -F mpich -T openmpi -np 4 ./hello
```

## OSU Micro Benchmarks

First, you will need to get OSU Micro Benchmarks:

```bash
wget https://mvapich.cse.ohio-state.edu/download/mvapich/osu-micro-benchmarks-5.9.tar.gz
tar xf osu-micro-benchmarks-5.9.tar.gz
```

### Compiling OMB with MPICH and first execution

It is straightforward to compile the OSU Micro Benchmarks:

```bash
spack unload -a
spack load mpich
cd osu-micro-benchmarks-5.9
./configure CC=mpicc CXX=mpicxx
make -j
```

Several benchmarks may be executed to assert the usability and overhead of Wi4MPI:

```bash
mpirun -np 4 mpi/startup/osu_init
mpirun -np 2 mpi/pt2pt/osu_bibw
mpirun -np 4 mpi/collective/osu_allreduce
```

You can note the results as reference for the next execution using Wi4MPI.

```bash
# OSU MPI Init Test v5.6.2
nprocs: 4, min: 67 ms, max: 67 ms, avg: 67 ms

# OSU MPI Bi-Directional Bandwidth Test v5.6.2
# Size      Bandwidth (MB/s)
1                       2.10
2                       5.52
4                      12.39
8                      28.51

# OSU MPI Allreduce Latency Test v5.6.2
# Size       Avg Latency(us)
4                       1.40
8                       1.08
16                      1.18
32                      0.92
```

### Switching MPI implementations using Wi4MPI

```bash
spack unload mpich
spack load wi4mpi
mpirun -F mpich -T openmpi -np 4 mpi/startup/osu_init
mpirun -F mpich -T openmpi -np 2 mpi/pt2pt/osu_bibw
mpirun -F mpich -T openmpi -np 4 mpi/collective/osu_allreduce
```

Note the performance using Wi4MPI switching from one MPI implementation to the other.

```bash
You are using Wi4MPI-3.6.0 with the mode preload From MPICH To OMPI

# OSU MPI Init Test v5.6.2
nprocs: 4, min: 540 ms, max: 542 ms, avg: 541 ms

# OSU MPI Bi-Directional Bandwidth Test v5.6.2
# Size      Bandwidth (MB/s)
1                       2.55
2                       5.03
4                      12.76
8                      29.26

# OSU MPI Allreduce Latency Test v5.6.2
# Size       Avg Latency(us)
4                       0.85
8                       0.62
16                      0.65
32                      0.66
64                      0.67
```

## Wi4MPI Preload mode with Slurm

Wi4MPI is able to translate MPI implementations without its own mpirun or wi4mpi wrappers.
Using the Slurm srun command directly on your executable is a powerful tool.
For this tutorial we use bash export but we recommand writing dedicated TCL Module files.

### From MPICH to OpenMPI by srun

With an OMB suite compiled with MPICH, the following lines show you how to run it with OpenMPI via srun.

```bash
spack unload -a
spack load openmpi
spack load wi4mpi

export OPENMPI_ROOT=/path/to/openmpi

export WI4MPI_FROM=MPICH
export WI4MPI_TO=OMPI
export WI4MPI_RUN_MPI_C_LIB=${OPENMPI_ROOT}/lib/libmpi.so
export WI4MPI_RUN_MPI_F_LIB=${OPENMPI_ROOT}/lib/libmpi_mpifh.so
export WI4MPI_RUN_MPIIO_C_LIB=${WI4MPI_RUN_MPI_C_LIB}
export WI4MPI_RUN_MPIIO_F_LIB=${WI4MPI_RUN_MPI_F_LIB}
export LD_PRELOAD=${WI4MPI_ROOT}/libexec/wi4mpi/libwi4mpi_${WI4MPI_FROM}_${WI4MPI_TO}.so:${WI4MPI_RUN_MPI_C_LIB}

srun -n 4 mpi/startup/osu_hello
```

The different `WI4MPI_*` variables are listed in the documentation.

If the translation works, you should have this kind of output:

```bash
You are using Wi4MPI-3.6.4 with the mode preload From MPICH To OMPI
# OSU MPI Hello World Test v7.0
This is a test with 4 processes
```

### From OpenMPI to MPICH by srun

With an OMB suite compiled with OpenMPI, the following lines show you how to run it with MPICH via srun.

```bash
spack unload -a
spack load mpich
spack load wi4mpi

export MPICH_ROOT=/path/to/mpich

export WI4MPI_FROM=OMPI
export WI4MPI_TO=MPICH
export WI4MPI_RUN_MPI_C_LIB=${MPICH_ROOT}/lib/libmpi.so
export WI4MPI_RUN_MPI_F_LIB=${MPICH_ROOT}/lib/libmpifort.so
export WI4MPI_RUN_MPIIO_C_LIB=${WI4MPI_RUN_MPI_C_LIB}
export WI4MPI_RUN_MPIIO_F_LIB=${WI4MPI_RUN_MPI_F_LIB}
export LD_PRELOAD=${WI4MPI_ROOT}/libexec/wi4mpi/libwi4mpi_${WI4MPI_FROM}_${WI4MPI_TO}.so:${WI4MPI_RUN_MPI_C_LIB}

srun -n 4 mpi/startup/osu_hello
```

The different `WI4MPI_*` variables are listed in the documentation.

If the translation works, you should have this kind of output:

```bash
You are using Wi4MPI-3.6.4 with the mode preload From OMPI To MPICH
# OSU MPI Hello World Test v7.0
This is a test with 4 processes
```

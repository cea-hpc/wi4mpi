*This is a **sample** of our ISC23 submission Module 2: Changing MPI libraries dynamically with Wi4MPI. It is not intended to be the final and complete module.*

# Translating MPI dynamically using Interface mode

## Learning objectives

With these hands-on exercises, participants will learn:
 - how to build and execute simple programs using Wi4MPI in interface mode
 - in particular, how to switch between different MPI implementations at runtime thanks to Wi4MPI
 - how to execute benchmarks and measure Wi4MPI performance
 - how to use Wi4MPI interface mode with Slurm

Once participants complete these exercises, they will be able to build and launch programs using Wi4MPI in their own environments.

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

The previous program may be compiled using Wi4MPI:

```bash
spack unload -a
spack load wi4mpi
mpicc hello.c -o hello
```

and executed:

```bash
mpirun -np 4 ./hello
```

Here, Wi4MPI should tell you to set `WI4MPI_TO` variable, or use mpirun with `-T` option.
Be sure to *only* have wi4mpi loaded in your Spack environment (neither mpich nor openmpi) and
your `wi4mpi.cfg` file up to date.

### Switching MPI implementations using Wi4MPI

A program built with Wi4MPI cannot be executed by itself.
It is then possible to use OpenMPI or MPICH to run this program successfully with Wi4MPI; to do so, you'll need to specify the `-T` option to `mpirun`. `-T` (*to*) specifies which MPI implementation to use:

```bash
spack unload -a
spack load wi4mpi
mpirun -T openmpi -np 4 ./hello
```

or:

```bash
spack unload -a
spack load wi4mpi
mpirun -T mpich -np 4 ./hello
```

## OSU Micro Benchmarks

First, you will need to get the OSU Micro Benchmarks:

```bash
wget https://mvapich.cse.ohio-state.edu/download/mvapich/osu-micro-benchmarks-5.9.tar.gz
tar xf osu-micro-benchmarks-5.9.tar.gz
```

### Compiling OMB with Wi4MPI and first execution

It is straightforward to compile the OSU Micro Benchmarks and run it with MPICH or OpenMPI:

```bash
spack unload -a
spack load wi4mpi
cd osu-micro-benchmarks-5.9
./configure CC=mpicc CXX=mpicxx
make -j
```

Several benchmarks may be executed to assert the usability and overhead of Wi4MPI:

```bash
mpirun -T mpich -np 4 mpi/startup/osu_init
mpirun -T mpich -np 2 mpi/pt2pt/osu_bibw
mpirun -T mpich -np 4 mpi/collective/osu_allreduce
```

You can note the results as reference for the next execution using Wi4MPI.

### Switching MPI implementations using Wi4MPI

With OpenMPI:

```bash
mpirun -T openmpi -np 4 mpi/startup/osu_init
mpirun -T openmpi -np 2 mpi/pt2pt/osu_bibw
mpirun -T openmpi -np 4 mpi/collective/osu_allreduce
```

or with MPICH:

```bash
mpirun -T mpich -np 4 mpi/startup/osu_init
mpirun -T mpich -np 2 mpi/pt2pt/osu_bibw
mpirun -T mpich -np 4 mpi/collective/osu_allreduce
```

Note the performance using Wi4MPI switching from one MPI implementation to the other.

## Wi4MPI Preload mode with Slurm

Wi4MPI is able to translate MPI implementations without its own mpirun or wi4mpi wrappers.
Using the Slurm srun command directly on your executable is a powerful tool.
For this tutorial we use bash export but we recommand writing dedicated TCL Module files.

### From Wi4MPI to OpenMPI by srun

With an OMB suite compiled with Wi4MPI Interface mode, the following lines show you how to run it with OpenMPI via srun.

```bash
spack unload -a
spack load openmpi
spack load wi4mpi

export LD_LIBRARY_PATH=${WI4MPI_ROOT}/lib:${LD_LIBRARY_PATH}
export WI4MPI_TO=OMPI
export WI4MPI_RUN_MPI_C_LIB=/path/to/openmpi/lib/libmpi.so
export WI4MPI_RUN_MPI_F_LIB=/path/to/openmpi/lib/libmpi_mpifh.so
export WI4MPI_RUN_MPIIO_C_LIB=${WI4MPI_RUN_MPI_C_LIB}
export WI4MPI_RUN_MPIIO_F_LIB=${WI4MPI_RUN_MPI_F_LIB}
export WI4MPI_WRAPPER_LIB=/path/to/wi4mpi/lib_${WI4MPI_TO}/libwi4mpi_${WI4MPI_TO}.so

srun -n 4 mpi/startup/osu_hello
```

The different `WI4MPI_*` variables are listed in the documentation.

If the translation works, you should have this kind of output:

```bash
You are using Wi4MPI-3.6.4 with the mode interface From Interface To OMPI
# OSU MPI Hello World Test v7.0
This is a test with 4 processes
```

### From Wi4MPI to MPICH by srun

With an OMB suite compiled with Wi4MPI Interface mode, the following lines show you how to run it with MPICH via srun.

```bash
spack unload -a
spack load mpich
spack load wi4mpi

export LD_LIBRARY_PATH=${WI4MPI_ROOT}/lib:${LD_LIBRARY_PATH}
export WI4MPI_TO=MPICH
export WI4MPI_RUN_MPI_C_LIB=/path/to/mpich/lib/libmpi.so
export WI4MPI_RUN_MPI_F_LIB=/path/to/mpich/lib/libmpifort.so
export WI4MPI_RUN_MPIIO_C_LIB=${WI4MPI_RUN_MPI_C_LIB}
export WI4MPI_RUN_MPIIO_F_LIB=${WI4MPI_RUN_MPI_F_LIB}
export WI4MPI_WRAPPER_LIB=/path/to/wi4mpi/lib_${WI4MPI_TO}/libwi4mpi_${WI4MPI_TO}.so

srun -n 4 mpi/startup/osu_hello
```

The different `WI4MPI_*` variables are listed in the documentation.

If the translation works, you should have this kind of output:

```bash
You are using Wi4MPI-3.6.4 with the mode interface From Interface To MPICH
# OSU MPI Hello World Test v7.0
This is a test with 4 processes
```

#!/bin/bash

source ../etc/batch.cfg || exit 1

export WI4MPI_ROOT
export WI4MPI_CC
export WI4MPI_TO
export WI4MPI_WRAPPER_LIB
export WI4MPI_RUN_MPI_C_LIB
export WI4MPI_RUN_MPI_F_LIB
export LD_LIBRARY_PATH=${WI4MPI_ROOT}/lib:${LD_LIBRARY_PATH}
export PATH=${WI4MPI_ROOT}/bin:${PATH}

${WI4MPI_ROOT}/bin/mpicc mpi_init.c -o mpi_init.mpicc
${WI4MPI_MPRUN} ${WI4MPI_NPROC} ${WI4MPI_NCORE} ${WI4MPI_PARTITION} ${WI4MPI_EXTRA_OPTS} ./mpi_init.mpicc

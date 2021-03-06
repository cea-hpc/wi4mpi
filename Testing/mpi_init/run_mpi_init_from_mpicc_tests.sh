#!/bin/bash

source ../etc/mpivars.sh || exit 1

${WI4MPI_ROOT}/bin/mpicc mpi_init.c -o mpi_init.mpicc
${WI4MPI_MPRUN} ${WI4MPI_NPROC} ${WI4MPI_NCORE} ${WI4MPI_PARTITION} ${WI4MPI_EXTRA_OPTS} ./mpi_init.mpicc

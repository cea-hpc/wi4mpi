#!/bin/bash

source ../etc/mpivars.sh || exit 1


${WI4MPI_ROOT}/bin/mpif90 mpi_init.f90 -o mpi_init.mpif90
${WI4MPI_MPRUN} ${WI4MPI_NPROC} ${WI4MPI_NCORE} ${WI4MPI_PARTITION} ${WI4MPI_EXTRA_OPTS} ./mpi_init.mpif90

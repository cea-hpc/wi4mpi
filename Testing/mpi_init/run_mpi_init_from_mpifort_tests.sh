#!/bin/bash

source ../etc/batch.cfg || exit 1

export WI4MPI_ROOT
export WI4MPI_FC
export WI4MPI_TO
export LD_LIBRARY_PATH=${WI4MPI_ROOT}/lib:${LD_LIBRARY_PATH}
export PATH=${WI4MPI_ROOT}/bin:${PATH}

${WI4MPI_ROOT}/bin/mpifort mpi_init.f -o mpi_init.mpifort
${WI4MPI_MPRUN} ${WI4MPI_NPROC} ${WI4MPI_NCORE} ${WI4MPI_PARTITION} ${WI4MPI_EXTRA_OPTS} ./mpi_init.mpifort

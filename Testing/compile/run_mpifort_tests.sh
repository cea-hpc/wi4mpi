#!/bin/bash

source ../etc/batch.cfg || exit 1

export WI4MPI_ROOT
export WI4MPI_FC
${WI4MPI_ROOT}/bin/mpifort mpi_init.f

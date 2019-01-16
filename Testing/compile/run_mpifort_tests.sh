#!/bin/bash

source ../etc/mpivars.sh || exit 1

${WI4MPI_ROOT}/bin/mpifort mpi_init.f

#!/bin/bash

source ../etc/batch.cfg || exit 1

export WI4MPI_ROOT
export WI4MPI_TO
export PATH=${WI4MPI_ROOT}/bin:${PATH}

${WI4MPI_ROOT}/bin/mpirun -n 4 hostname

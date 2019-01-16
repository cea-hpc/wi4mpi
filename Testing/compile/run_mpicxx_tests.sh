#!/bin/bash

source ../etc/mpivars.sh || exit 1

${WI4MPI_ROOT}/bin/mpicxx mpi_init.cpp

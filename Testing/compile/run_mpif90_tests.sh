#!/bin/bash

source ../etc/mpivars.sh || exit 1

${WI4MPI_ROOT}/bin/mpif90 mpi_init.f90

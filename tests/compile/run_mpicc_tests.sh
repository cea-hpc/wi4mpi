#!/bin/bash

source ../etc/batch.cfg || exit 1

export WI4MPI_ROOT
export WI4MPI_CC
${WI4MPI_ROOT}/bin/mpicc mpi_init.c

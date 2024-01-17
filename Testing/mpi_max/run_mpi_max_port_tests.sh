#!/bin/bash

source ../etc/mpivars.sh || exit 1


${WI4MPI_ROOT}/bin/mpicc port-client.c -o client
${WI4MPI_ROOT}/bin/mpicc port-server.c -o server
${TESTMPI_ROOT}/bin/mpirun -n 1 wi4mpi -t openmpi ./server : -n 1 wi4mpi -t openmpi ./client

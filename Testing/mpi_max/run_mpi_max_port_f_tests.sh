#!/bin/bash

source ../etc/mpivars.sh || exit 1


${WI4MPI_ROOT}/bin/mpif90 port-client.f90 -o client_f
${WI4MPI_ROOT}/bin/mpif90 port-server.f90 -o server_f
${TESTMPI_ROOT}/bin/mpirun -n 1 wi4mpi -t openmpi ./server_f : -n 1 wi4mpi -t openmpi ./client_f

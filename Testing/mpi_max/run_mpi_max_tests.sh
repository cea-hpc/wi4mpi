#!/bin/bash

source ../etc/mpivars.sh || exit 1


${WI4MPI_ROOT}/bin/mpicc main.c -o main_max
${WI4MPI_ROOT}/bin/mpicc info.c -o info_max
${WI4MPI_ROOT}/bin/mpicc fileview.c -o fileview_max
${WI4MPI_MPRUN} -n 1 ${WI4MPI_NCORE} ${WI4MPI_PARTITION} ${WI4MPI_EXTRA_OPTS} ./main_max
${WI4MPI_MPRUN} -n 1 ${WI4MPI_NCORE} ${WI4MPI_PARTITION} ${WI4MPI_EXTRA_OPTS} ./info_max
${WI4MPI_MPRUN} -n 1 ${WI4MPI_NCORE} ${WI4MPI_PARTITION} ${WI4MPI_EXTRA_OPTS} ./fileview_max

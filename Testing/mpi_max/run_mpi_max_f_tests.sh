#!/bin/bash

source ../etc/mpivars.sh || exit 1


${WI4MPI_ROOT}/bin/mpif90 main.f90 -o main_max_f
${WI4MPI_ROOT}/bin/mpif90 info.f90 -o info_max_f
${WI4MPI_ROOT}/bin/mpif90 fileview.f90 -o fileview_max_f
${WI4MPI_MPRUN} -n 1 ${WI4MPI_NCORE} ${WI4MPI_PARTITION} ${WI4MPI_EXTRA_OPTS} ./main_max_f
${WI4MPI_MPRUN} -n 1 ${WI4MPI_NCORE} ${WI4MPI_PARTITION} ${WI4MPI_EXTRA_OPTS} ./info_max_f
${WI4MPI_MPRUN} -n 1 ${WI4MPI_NCORE} ${WI4MPI_PARTITION} ${WI4MPI_EXTRA_OPTS} ./fileview_max_f

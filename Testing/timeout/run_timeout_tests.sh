#!/bin/bash

source ../etc/mpivars.sh || exit 1


mpicc timeout_slow_add.c -o timeout_slow_add

export WI4MPI_Reduce_timeout=1
${WI4MPI_MPRUN} ${WI4MPI_NPROC} ${WI4MPI_NCORE} ${WI4MPI_PARTITION} ${WI4MPI_EXTRA_OPTS} ./timeout_slow_add &> timeout_slow_add.log

grep -q 'processus .* on host .* has reached a timeout' timeout_slow_add.log

echo $?

#!/bin/bash

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

export WI4MPI_ROOT=$(readlink -f ${SCRIPT_DIR}/../../)

source ${WI4MPI_ROOT}/etc/wi4mpi.cfg
export WI4MPI_VERSION # obtained by wi4mpi.cfg

export PATH=${WI4MPI_ROOT}/bin:$PATH

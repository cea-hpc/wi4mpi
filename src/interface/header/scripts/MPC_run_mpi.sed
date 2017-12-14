######################################################
# Apply exceptions for _MPC header run_mpi.          #
#                                                    #
# USAGE : sed -i -f MPC_run_mpi.sed run_mpi.h        #
#                                                    #
# Written by Adrien Cotte <adrien.cotte@eolen.com>   #
######################################################

# Add missing MPI_ERR_RMA
/#define R_MPI_ERR_RMA_CONFLICT/{
    i#define R_MPI_ERR_RMA_RANGE MPC_ERR_UNKNOWN
    i#define R_MPI_ERR_RMA_ATTACH MPC_ERR_UNKNOWN
    i#define R_MPI_ERR_RMA_SHARED MPC_ERR_UNKNOWN
}

# Add include "run_mpio.h" at the end of file
$a\#include "run_mpio.h"

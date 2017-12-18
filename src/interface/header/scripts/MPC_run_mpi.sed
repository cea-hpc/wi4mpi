######################################################
# Apply exceptions for _MPC header run_mpi.          #
#                                                    #
# USAGE : sed -i -f MPC_run_mpi.sed run_mpi.h        #
#                                                    #
# Written by Adrien Cotte <adrien.cotte@eolen.com>   #
######################################################

# Add missing MPI_ERR_RMA
/#define R_MPI_ERR_RMA_CONFLICT/{
    i#define R_MPI_ERR_RMA_RANGE 74
    i#define R_MPI_ERR_RMA_ATTACH 75
    i#define R_MPI_ERR_RMA_SHARED 76
}

# Add include "run_mpio.h" at the end of file
$a\#include "run_mpio.h"

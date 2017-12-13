######################################################
# Apply exceptions for _MPC header run_mpi.          #
#                                                    #
# USAGE : sed -i -f MPC_run_mpi.sed run_mpi.h        #
#                                                    #
# Written by Adrien Cotte <adrien.cotte@eolen.com>   #
######################################################

# Add include "run_mpio.h" at the end of file
$a\#include "run_mpio.h"

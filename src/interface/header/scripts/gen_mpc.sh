#!/bin/bash

####################################################
# This script generates MPC headers                #
#   => wi4mpi/interface/headers/_MPC/*.h           #
#                                                  #
# Written by Adrien Cotte <adrien.cotte@eolen.com> #
####################################################

dir_source='mpc_headers'
dir_target='_MPC'
mkdir -p $dir_target

# Get app_mpi.h from _INTEL
cp ../_INTEL/app_mpi.h $dir_target

# Apply common sed
sed -f MPI_to_RMPI.sed $dir_source/mpc_mpi.h > $dir_target/run_mpi.h
sed -f MPI_to_RMPI.sed $dir_source/mpio.h > $dir_target/run_mpio.h

# Apply MPC exceptions sed
sed -i -f MPC_run_mpi.sed $dir_target/run_mpi.h
sed -i -f MPC_app_mpi.sed $dir_target/app_mpi.h

cp $dir_source/{mpcmp.h,sctk_types.h} $dir_target

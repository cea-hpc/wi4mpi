#!/bin/bash

#############################################################
# Generate '#define MPI_XXX <value>' from list to res.      #
# Usefull for headers/_MPC/wrapper_f.h                      #
#                                                           #
# Written by Adrien Cotte <adrien.cotte@eolen.com>          #
#############################################################

list='MPI_XXX.list'
out='get_MPI_XXX.f90'
exe=${out%%.f90}
res=${list%%.list}.res

echo "program $exe" > $out
echo '  use mpi' >> $out
xargs -a $list -n 1 -I '%' -- echo "  print *, '#define %', % " >> $out
echo 'end program' >> $out

# Run program with MPC to get MPI_MODE_XXX values
mpc_ifort $out -o $exe
mpcrun -m=pthread -l=srun --opt="-A assist@standard -p haswell" -n=1 ./$exe > $res

#!/bin/bash

#############################################################
# Generate '#define MPI_MAX_XXX <value>' from list to res.  #
# Usefull for func_char_fort.c                              #
#                                                           #
# Written by Adrien Cotte <adrien.cotte@eolen.com>          #
#############################################################

list='MPI_MAX.list'
out='get_MPI_MAX.f90'
exe=${out%%.f90}
res=${list%%.list}.res

echo "program $exe" > $out
echo '  use mpi' >> $out
xargs -a $list -n 1 -I '%' -- echo "  print *, '#define %', % " >> $out
echo 'end program' >> $out

# Run program with MPC to get MPI_MAX_XXX values
mpc_ifort $out -o $exe
mpcrun -m=pthread -l=srun --opt="-A assist@standard -p haswell" -n=1 ./$exe > $res

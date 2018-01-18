#!/bin/bash

#################################################################
# Merge multiple static libraries into one.                     #
#                                                               #
# USAGE : ./assemble_sym.sh libmpi.a libmpi_a.a libwi4mpi_*_a.a #
#                                                               #
# Written by Vincent Ducrot and Adrien Cotte                    #
#################################################################

mkdir tmp_object_static
cd tmp_object_static

lib_name=$1
shift 1
while (( "$#" )); do
    mkdir $1
    cd $1
    ar -x ../../$1
    rm ../../$1
    cd ..
    shift 1
done

ar cr ../$lib_name */*.o
cd ..
rm -rf tmp_object_static

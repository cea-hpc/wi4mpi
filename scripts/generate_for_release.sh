#!/bin/bash
#
# This script executes the generator with the default argument for release tarballs
#
wi4mpi_dir=.
export PYTHONPATH=$PYTHONPATH:$wi4mpi_dir/src/generator
cd $wi4mpi_dir
./src/generator/generator.py \
    --interface_header_dir=$wi4mpi_dir/build/src/interface/header \
    --preload_header_dir=$wi4mpi_dir/build/src/preload/header \
    --c_preload_gen_dir=$wi4mpi_dir/build/src/preload/gen \
    --c_interface_gen_dir=$wi4mpi_dir/build/src/interface/gen \
    --openmpi_version=1.8.8 \
    --intelmpi_version=20.0.0 \
    --mpich_version=3.1.2

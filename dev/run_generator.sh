#!/bin/bash

export PYTHONPATH=$PYTHONPATH:$wi4mpi_dir/lib
cd $wi4mpi_dir
./lib/generator.py \
    --interface_header_dir=$dir_gen_interface \
    --preload_header_dir=$dir_gen_preload \
    --c_preload_gen_dir=$dir_gen_c_preload \
    --c_interface_gen_dir=$dir_gen_c_interface \
    --openmpi_version=$GENERATOR_OPENMPI_VERSION

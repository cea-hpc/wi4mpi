#!/bin/bash

if [[ $GENERATOR_BUILD_WITH_GENERATED_HEADERS == 1 ]]; then
    cp -r $dir_gen_preload/* $wi4mpi_dir/src/preload/header/.
    cp -r $dir_gen_interface/* $wi4mpi_dir/src/interface/header/.
fi
if [[ $GENERATOR_RUN == 0 ]]; then
    echo "The generator did not run. Define the following directories:"
    read -p "Define dir_gen_c_preload: " dir_gen_c_preload
    read -p "Define dir_gen_c_interface: " dir_gen_c_interface
fi
cp $dir_gen_c_preload/mpi_translation_c.c $wi4mpi_dir/src/preload/gen/mpi_translation_c.c
cp $dir_gen_c_interface/mpi_translation_c.c $wi4mpi_dir/src/interface/gen/mpi_translation_c.c
cp $dir_gen_c_interface/interface_c.c $wi4mpi_dir/src/interface/gen/.
wi4mpi_build_prefix=$(mktemp -d)
wi4mpi_install_prefix=$(mktemp -d)
export wi4mpi_build_prefix wi4mpi_install_prefix
echo -e "\033[35m[=====================================]\n| Build   prefix: $wi4mpi_build_prefix |\n| Install prefix: $wi4mpi_install_prefix |\n[=====================================]\n\033[0m"
cd $wi4mpi_build_prefix
cmake \
 -DCMAKE_INSTALL_PREFIX=$wi4mpi_install_prefix\
 -DWI4MPI_COMPILER=GNU \
 $wi4mpi_dir
make -j 4 && make install

#!/bin/bash

function usage() {
    cat << EOF

Usage: $0 [-g <GENERATOR_RUN>]
          [-b <GENERATOR_TEST_BUILD>]
          [-d <GENERATOR_TEST_HEADER>]
          [-o <GENERATOR_OPENMPI_VERSION>]
          [-m <GENERATOR_MPICH_VERSION>]
          [-t <GENERATOR_BUILD_WITH_GENERATED_HEADERS>]


Options:
  -g <GENERATOR_RUN>: Boolean (1)/0. Execute ./lib/generator.py; copie les fichiers générés
  -b <GENERATOR_TEST_BUILD>: Boolean (1)/0. Compile Wi4mpi
  -d <GENERATOR_TEST_HEADER>: Boolean (1)/0. Compare les headers interface, preload aux références
  -o <GENERATOR_OPENMPI_VERSION>: String number version of the OpenMPI base header to use in the generator. Default: 1.8.8. Available: 1.8.8, 2.1.6, 4.1.6, 5.0.3
  -m <GENERATOR_MPICH_VERSION>: String number version of the MPICH base header to use in the generator. Default: 3.1.2. Available: 3.1.2, 3.4.3, 4.2.0
  -t <GENERATOR_BUILD_WITH_GENERATED_HEADERS>: Boolean 1/(0). Copy generated headers in wi4mpi sources before the compilation. They replace reference headers.

EOF
}


while getopts ":g:b:d:o:t:m:h" opt; do
    case ${opt} in
        g )
            GENERATOR_RUN="$OPTARG"
            ;;
        b )
            GENERATOR_TEST_BUILD="$OPTARG"
            ;;
        d)
            GENERATOR_TEST_HEADER="$OPTARG"
            ;;
        o)
            GENERATOR_OPENMPI_VERSION="$OPTARG"
            ;;
        m)
            GENERATOR_MPICH_VERSION="$OPTARG"
            ;;
        t)
            GENERATOR_BUILD_WITH_GENERATED_HEADERS="$OPTARG"
            ;;
        h )
            usage
            exit 0
            ;;
        \? )
            echo "Option invalide: -$OPTARG" >&2
            exit 1
            ;;
    esac
done

shift $((OPTIND -1))

## Script parameters

export GENERATOR_RUN=${GENERATOR_RUN-1} # Execute ./lib/generator.py; copie les fichiers générés
export GENERATOR_TEST_BUILD=${GENERATOR_TEST_BUILD-1} # Compile Wi4mpi
export GENERATOR_TEST_HEADER=${GENERATOR_TEST_HEADER-1} # Compare les headers interface, preload aux références
export GENERATOR_OPENMPI_VERSION=${GENERATOR_OPENMPI_VERSION-1.8.8}
export GENERATOR_MPICH_VERSION=${GENERATOR_MPICH_VERSION-3.1.2}
export GENERATOR_BUILD_WITH_GENERATED_HEADERS=${GENERATOR_BUILD_WITH_GENERATED_HEADERS-0}

## Variables

export _dir="${1-$(realpath "$(dirname "$0")")}"
export wi4mpi_dir="$_dir/.."
export dir_gen_c_preload=${GENERATOR_DIR_GEN_C_PRELOAD-$(mktemp -d)}
export dir_gen_c_interface=${GENERATOR_DIR_GEN_C_INTERFACE-$(mktemp -d)}
export dir_gen_interface=${GENERATOR_DIR_GEN_INTERFACE-$(mktemp -d)}
export dir_gen_preload=${GENERATOR_DIR_GEN_PRELOAD-$(mktemp -d)}

## Environment

if [[ $MODULES_COLLECTION_TARGET == "inti.Rhel_8__x86_64" ]]; then
    module restore $wi4mpi_dir/dev/wi4mpi_dev.inti.Rhel_8__x86_64
fi

## Generator

if [[ $GENERATOR_RUN == 1 ]]; then
    $_dir/run_generator.sh
fi

## Headers comparison

if [[ $GENERATOR_TEST_HEADER == 1 ]]; then
    if [[ $GENERATOR_RUN == 0 ]]; then
        echo "The generator will not run. Only comparison will be performed."
        read -p "Define dir_gen_interface: " dir_gen_interface
        read -p "Define dir_gen_preload: " dir_gen_preload
        export dir_gen_interface dir_gen_preload
    fi
    $_dir/run_test_headers.sh
fi

## Build

if [[ $GENERATOR_TEST_BUILD == 1 ]]; then
    $_dir/run_build.sh
fi

## Results

if [[ $GENERATOR_TEST_BUILD == 1 ]]; then
    echo -e "\033[35m
    * Build prefix: $wi4mpi_build_prefix
    * Install prefix: $wi4mpi_install_prefix\033[0m"
fi
if [[ $GENERATOR_RUN == 1 ]]; then
    echo -e "\033[35m
    * Interface header directory: $dir_gen_interface
    * Preload header directory: $dir_gen_preload
    * Preload C code directory: $dir_gen_c_preload
    * Interface C code directory: $dir_gen_c_interface\033[0m"
fi

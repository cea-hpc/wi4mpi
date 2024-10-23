#!/bin/bash
#
# This script is intended to centralize the execution of wi4mpi development tests.
# It is initially designed to configure the environment to run the header generator
# and compare the generation to the files already present in the sources.
# Here are the currently available features:
# -g <GENERATOR_RUN>: enables (1) or disables (0) the execution of the generator
# -b <GENERATOR_TEST_BUILD>: enables (1) or disables (0) the cmake and make phases of the wi4mpi build
# -d <GENERATOR_TEST_HEADER>: enables (1) or disables (0) the comparison between the generated headers and those already present in the sources
# -o <GENERATOR_OPENMPI_VERSION>: version of the OpenMPI used by the generator
# -m <GENERATOR_MPICH_VERSION>: version of the MPICH used by the generator
# -i <GENERATOR_INTELMPI_VERSION>: version of the IntelMPI used by the generator
# -t <GENERATOR_BUILD_WITH_GENERATED_HEADERS>: enables (1) or disables (0) the copy of generated headers into the src
# -c <GENERATOR_BUILD_WITH_GENERATED_CODE>: enables (1) or disables (0) the copy of the generated code into the src
#
set -e

function usage() {
    cat << EOF

Usage: $0 [-g <GENERATOR_RUN>]
          [-b <GENERATOR_TEST_BUILD>]
          [-d <GENERATOR_TEST_HEADER>]
          [-o <GENERATOR_OPENMPI_VERSION>]
          [-m <GENERATOR_MPICH_VERSION>]
          [-i <GENERATOR_INTELMPI_VERSION>]
          [-t <GENERATOR_BUILD_WITH_GENERATED_HEADERS>]
          [-c <GENERATOR_BUILD_WITH_GENERATED_CODE>]

Options:
  -g <GENERATOR_RUN>: Boolean (1)/0. Execute ./lib/generator.py; copies the generated files
  -b <GENERATOR_TEST_BUILD>: Boolean (1)/0. Compile Wi4mpi
  -d <GENERATOR_TEST_HEADER>: Boolean 1/(0). Compare the interface headers, preload to the references
  -o <GENERATOR_OPENMPI_VERSION>: String number version of the OpenMPI base header to use in the generator. Default: 1.8.8. Available: 1.8.8, 2.1.6, 4.1.6, 5.0.3
  -m <GENERATOR_MPICH_VERSION>: String number version of the MPICH base header to use in the generator. Default: 3.1.2. Available: 3.1.2, 3.4.3, 4.2.0
  -i <GENERATOR_INTELMPI_VERSION>: String number version of the IntelMPI base header to use in the generator. Default: 20.0.0. Available: 20.0.0, 24.0.0
  -t <GENERATOR_BUILD_WITH_GENERATED_HEADERS>: Boolean 1/(0). Copy generated headers into Wi4mpi sources before the compilation. They will replace reference headers.
  -c <GENERATOR_BUILD_WITH_GENERATED_CODE>: Boolean 1/(0). Copy generated code in wi4mpi sources before the compilation.



EOF
}


while getopts ":g:b:d:o:t:m:i:c:h" opt; do
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
        i)
            GENERATOR_INTELMPI_VERSION="$OPTARG"
            ;;
        t)
            GENERATOR_BUILD_WITH_GENERATED_HEADERS="$OPTARG"
            ;;
        c)
            GENERATOR_BUILD_WITH_GENERATED_CODE="$OPTARG"
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

## Script settings

export GENERATOR_RUN=${GENERATOR_RUN-1} # Execute ./lib/generator.py
export GENERATOR_TEST_BUILD=${GENERATOR_TEST_BUILD-1} # Compile Wi4mpi
export GENERATOR_TEST_HEADER=${GENERATOR_TEST_HEADER-0} # Compare the interface headers, preload to the references
export GENERATOR_OPENMPI_VERSION=${GENERATOR_OPENMPI_VERSION-1.8.8}
export GENERATOR_MPICH_VERSION=${GENERATOR_MPICH_VERSION-3.1.2}
export GENERATOR_INTELMPI_VERSION=${GENERATOR_INTELMPI_VERSION-20.0.0}
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
        read -p "Directory where the code generated for the interface mode is located: " dir_gen_interface
        read -p "Directory where the code generated for the preload mode is located: " dir_gen_preload
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

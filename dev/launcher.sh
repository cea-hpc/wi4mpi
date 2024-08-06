#!/bin/bash

function usage() {
	cat << EOF

Usage: $0 [-g <GENERATOR_RUN>] [-b <GENERATOR_TEST_BUILD>] [-d <GENERATOR_TEST_HEADER>]


Options:
  -g <GENERATOR_RUN>: Boolean 1/0. Execute ./lib/generator.py; copie les fichiers générés
  -b <GENERATOR_TEST_BUILD>: Boolean 1/0. Compile Wi4mpi
  -d <GENERATOR_TEST_HEADER>: Boolean 1/0. Compare les headers interface, preload aux références

EOF
}


while getopts ":g:b:c:h" opt; do
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

## Variables

export _dir="${1-$(realpath "$(dirname "$0")")}"
export wi4mpi_dir="$_dir/.."
export dir_gen_c_preload=$(mktemp -d)
export dir_gen_c_interface=$(mktemp -d)
export dir_gen_interface=$(mktemp -d)
export dir_gen_preload=$(mktemp -d)

## Environment

module restore $wi4mpi_dir/dev/wi4mpi_dev.inti.Rhel_8__x86_64

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

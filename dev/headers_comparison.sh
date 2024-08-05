#!/bin/bash

module purge
module load gnu mpi/openmpi python3/3.11 llvm

GENERATOR_TEST_BUILD=${GENERATOR_TEST_BUILD-1}
GENERATOR_TEST_HEADER=${GENERATOR_TEST_HEADER-1}
GENERATOR_RUN=${GENERATOR_RUN-1}

_dir="${1-$(realpath "$(dirname "$0")")}"


function diff_gen_ref() {
file_gen=$1
file_ref=$2
diff -q $file_gen $file_ref &> /dev/null
if [[ $? == 0 ]]; then
  echo -e "\033[32;1mLes fichiers sont identiques: $file_gen $file_ref\033[0m"
  return 0
else
  echo -e "\033[31;1mLes fichiers sont différents: $file_gen $file_ref\033[0m"
  nbr_of_lines_only_gen=$(diff $file_gen $file_ref | grep "^<" | wc -l)
  nbr_of_lines_only_ref=$(diff $file_gen $file_ref | grep "^>" | wc -l)
  echo -e "\033[31mNombre de lignes uniquement dans $file_gen: $nbr_of_lines_only_gen"
  echo -e "Nombre de lignes uniquement dans $file_ref: $nbr_of_lines_only_ref"
  echo -e "Nombre total de lignes différentes: $((nbr_of_lines_only_gen + nbr_of_lines_only_ref))\033[0m"
  return 1
fi
}


dir_gen_c_preload=$(mktemp -d)
dir_gen_c_interface=$(mktemp -d)
wi4mpi_dir="$_dir/.."
dir_ref_interface="$_dir/../src/interface/header"
dir_gen_interface=$(mktemp -d)
dir_ref_preload="$_dir/../src/preload/header"
dir_gen_preload=$(mktemp -d)

file_ref_ompi_run_mpi=$dir_ref_interface/_OMPI/run_mpi.h
file_ref_intel_run_mpi=$dir_ref_interface/_INTEL/run_mpi.h
file_ref_mpc_run_mpi=$dir_ref_interface/_MPC/run_mpi.h
file_ref_mpich_run_mpi=$dir_ref_interface/_MPICH/run_mpi.h

file_ref_ompi_app_mpi=$dir_ref_interface/_OMPI/app_mpi.h
file_ref_intel_app_mpi=$dir_ref_interface/_INTEL/app_mpi.h
file_ref_mpc_app_mpi=$dir_ref_interface/_MPC/app_mpi.h
file_ref_mpich_app_mpi=$dir_ref_interface/_MPICH/app_mpi.h

file_ref_intel_run_mpio=$dir_ref_interface/_INTEL/run_mpio.h
file_ref_mpc_run_mpio=$dir_ref_interface/_MPC/run_mpio.h
file_ref_mpich_run_mpio=$dir_ref_interface/_MPICH/run_mpio.h

file_ref_ompi_wrapper_f=$dir_ref_interface/_OMPI/wrapper_f.h
file_ref_intel_wrapper_f=$dir_ref_interface/_INTEL/wrapper_f.h
file_ref_mpc_wrapper_f=$dir_ref_interface/_MPC/wrapper_f.h
file_ref_mpich_wrapper_f=$dir_ref_interface/_MPICH/wrapper_f.h

file_gen_ompi_run_mpi=$dir_gen_interface/_OMPI/run_mpi.h
file_gen_intel_run_mpi=$dir_gen_interface/_INTEL/run_mpi.h
file_gen_mpc_run_mpi=$dir_gen_interface/_MPC/run_mpi.h
file_gen_mpich_run_mpi=$dir_gen_interface/_MPICH/run_mpi.h

file_gen_ompi_app_mpi=$dir_gen_interface/_OMPI/app_mpi.h
file_gen_intel_app_mpi=$dir_gen_interface/_INTEL/app_mpi.h
file_gen_mpc_app_mpi=$dir_gen_interface/_MPC/app_mpi.h
file_gen_mpich_app_mpi=$dir_gen_interface/_MPICH/app_mpi.h

file_gen_intel_run_mpio=$dir_gen_interface/_INTEL/run_mpio.h
file_gen_mpc_run_mpio=$dir_gen_interface/_MPC/run_mpio.h
file_gen_mpich_run_mpio=$dir_gen_interface/_MPICH/run_mpio.h

file_gen_ompi_wrapper_f=$dir_gen_interface/_OMPI/wrapper_f.h
file_gen_intel_wrapper_f=$dir_gen_interface/_INTEL/wrapper_f.h
file_gen_mpc_wrapper_f=$dir_gen_interface/_MPC/wrapper_f.h
file_gen_mpich_wrapper_f=$dir_gen_interface/_MPICH/wrapper_f.h

file_ref_intel_intel_run_mpi=$dir_ref_preload/INTEL_INTEL/run_mpi.h
file_gen_intel_intel_run_mpi=$dir_gen_preload/INTEL_INTEL/run_mpi.h
file_ref_intel_mpich_run_mpi=$dir_ref_preload/INTEL_MPICH/run_mpi.h
file_gen_intel_mpich_run_mpi=$dir_gen_preload/INTEL_MPICH/run_mpi.h
file_ref_mpich_mpich_run_mpi=$dir_ref_preload/MPICH_MPICH/run_mpi.h
file_gen_mpich_mpich_run_mpi=$dir_gen_preload/MPICH_MPICH/run_mpi.h
file_ref_mpich_intel_run_mpi=$dir_ref_preload/MPICH_INTEL/run_mpi.h
file_gen_mpich_intel_run_mpi=$dir_gen_preload/MPICH_INTEL/run_mpi.h

file_ref_intel_intel_app_mpi=$dir_ref_preload/INTEL_INTEL/app_mpi.h
file_gen_intel_intel_app_mpi=$dir_gen_preload/INTEL_INTEL/app_mpi.h
file_ref_intel_mpich_app_mpi=$dir_ref_preload/INTEL_MPICH/app_mpi.h
file_gen_intel_mpich_app_mpi=$dir_gen_preload/INTEL_MPICH/app_mpi.h
file_ref_mpich_mpich_app_mpi=$dir_ref_preload/MPICH_MPICH/app_mpi.h
file_gen_mpich_mpich_app_mpi=$dir_gen_preload/MPICH_MPICH/app_mpi.h
file_ref_mpich_intel_app_mpi=$dir_ref_preload/MPICH_INTEL/app_mpi.h
file_gen_mpich_intel_app_mpi=$dir_gen_preload/MPICH_INTEL/app_mpi.h

file_ref_intel_intel_app_mpio=$dir_ref_preload/INTEL_INTEL/app_mpio.h
file_gen_intel_intel_app_mpio=$dir_gen_preload/INTEL_INTEL/app_mpio.h
file_ref_intel_mpich_app_mpio=$dir_ref_preload/INTEL_MPICH/app_mpio.h
file_gen_intel_mpich_app_mpio=$dir_gen_preload/INTEL_MPICH/app_mpio.h
file_ref_mpich_mpich_app_mpio=$dir_ref_preload/MPICH_MPICH/app_mpio.h
file_gen_mpich_mpich_app_mpio=$dir_gen_preload/MPICH_MPICH/app_mpio.h
file_ref_mpich_intel_app_mpio=$dir_ref_preload/MPICH_INTEL/app_mpio.h
file_gen_mpich_intel_app_mpio=$dir_gen_preload/MPICH_INTEL/app_mpio.h

file_ref_intel_intel_run_mpio=$dir_ref_preload/INTEL_INTEL/run_mpio.h
file_gen_intel_intel_run_mpio=$dir_gen_preload/INTEL_INTEL/run_mpio.h
file_ref_intel_mpich_run_mpio=$dir_ref_preload/INTEL_MPICH/run_mpio.h
file_gen_intel_mpich_run_mpio=$dir_gen_preload/INTEL_MPICH/run_mpio.h
file_ref_mpich_mpich_run_mpio=$dir_ref_preload/MPICH_MPICH/run_mpio.h
file_gen_mpich_mpich_run_mpio=$dir_gen_preload/MPICH_MPICH/run_mpio.h
file_ref_mpich_intel_run_mpio=$dir_ref_preload/MPICH_INTEL/run_mpio.h
file_gen_mpich_intel_run_mpio=$dir_gen_preload/MPICH_INTEL/run_mpio.h

file_ref_intel_intel_wrapper_f=$dir_ref_preload/INTEL_INTEL/wrapper_f.h
file_gen_intel_intel_wrapper_f=$dir_gen_preload/INTEL_INTEL/wrapper_f.h
file_ref_intel_mpich_wrapper_f=$dir_ref_preload/INTEL_MPICH/wrapper_f.h
file_gen_intel_mpich_wrapper_f=$dir_gen_preload/INTEL_MPICH/wrapper_f.h
file_ref_mpich_mpich_wrapper_f=$dir_ref_preload/MPICH_MPICH/wrapper_f.h
file_gen_mpich_mpich_wrapper_f=$dir_gen_preload/MPICH_MPICH/wrapper_f.h
file_ref_mpich_intel_wrapper_f=$dir_ref_preload/MPICH_INTEL/wrapper_f.h
file_gen_mpich_intel_wrapper_f=$dir_gen_preload/MPICH_INTEL/wrapper_f.h

file_ref_intel_ompi_app_mpi=$dir_ref_preload/INTEL_OMPI/app_mpi.h
file_gen_intel_ompi_app_mpi=$dir_gen_preload/INTEL_OMPI/app_mpi.h
file_ref_mpich_ompi_app_mpi=$dir_ref_preload/MPICH_OMPI/app_mpi.h
file_gen_mpich_ompi_app_mpi=$dir_gen_preload/MPICH_OMPI/app_mpi.h

file_ref_intel_ompi_app_mpio=$dir_ref_preload/INTEL_OMPI/app_mpio.h
file_gen_intel_ompi_app_mpio=$dir_gen_preload/INTEL_OMPI/app_mpio.h
file_ref_mpich_ompi_app_mpio=$dir_ref_preload/MPICH_OMPI/app_mpio.h
file_gen_mpich_ompi_app_mpio=$dir_gen_preload/MPICH_OMPI/app_mpio.h

file_ref_intel_ompi_run_mpi=$dir_ref_preload/INTEL_OMPI/run_mpi.h
file_gen_intel_ompi_run_mpi=$dir_gen_preload/INTEL_OMPI/run_mpi.h
file_ref_mpich_ompi_run_mpi=$dir_ref_preload/MPICH_OMPI/run_mpi.h
file_gen_mpich_ompi_run_mpi=$dir_gen_preload/MPICH_OMPI/run_mpi.h

file_ref_intel_ompi_wrapper_f=$dir_ref_preload/INTEL_OMPI/wrapper_f.h
file_gen_intel_ompi_wrapper_f=$dir_gen_preload/INTEL_OMPI/wrapper_f.h
file_ref_mpich_ompi_wrapper_f=$dir_ref_preload/MPICH_OMPI/wrapper_f.h
file_gen_mpich_ompi_wrapper_f=$dir_gen_preload/MPICH_OMPI/wrapper_f.h

file_ref_ompi_intel_app_mpi=$dir_ref_preload/OMPI_INTEL/app_mpi.h
file_gen_ompi_intel_app_mpi=$dir_gen_preload/OMPI_INTEL/app_mpi.h
file_ref_ompi_mpich_app_mpi=$dir_ref_preload/OMPI_MPICH/app_mpi.h
file_gen_ompi_mpich_app_mpi=$dir_gen_preload/OMPI_MPICH/app_mpi.h

file_ref_ompi_intel_run_mpi=$dir_ref_preload/OMPI_INTEL/run_mpi.h
file_gen_ompi_intel_run_mpi=$dir_gen_preload/OMPI_INTEL/run_mpi.h
file_ref_ompi_mpich_run_mpi=$dir_ref_preload/OMPI_MPICH/run_mpi.h
file_gen_ompi_mpich_run_mpi=$dir_gen_preload/OMPI_MPICH/run_mpi.h

file_ref_ompi_intel_wrapper_f=$dir_ref_preload/OMPI_INTEL/wrapper_f.h
file_gen_ompi_intel_wrapper_f=$dir_gen_preload/OMPI_INTEL/wrapper_f.h
file_ref_ompi_mpich_wrapper_f=$dir_ref_preload/OMPI_MPICH/wrapper_f.h
file_gen_ompi_mpich_wrapper_f=$dir_gen_preload/OMPI_MPICH/wrapper_f.h

file_ref_ompi_intel_run_mpio=$dir_ref_preload/OMPI_INTEL/run_mpio.h
file_gen_ompi_intel_run_mpio=$dir_gen_preload/OMPI_INTEL/run_mpio.h
file_ref_ompi_mpich_run_mpio=$dir_ref_preload/OMPI_MPICH/run_mpio.h
file_gen_ompi_mpich_run_mpio=$dir_gen_preload/OMPI_MPICH/run_mpio.h

file_gen_ompi_ompi_run_mpi=$dir_gen_preload/OMPI_OMPI/run_mpi.h
file_gen_ompi_ompi_app_mpi=$dir_gen_preload/OMPI_OMPI/app_mpi.h
file_gen_ompi_ompi_wrapper_f=$dir_gen_preload/OMPI_OMPI/wrapper_f.h

file_ref_ompi_ompi_run_mpi=$dir_ref_preload/OMPI_OMPI/run_mpi.h
file_ref_ompi_ompi_app_mpi=$dir_ref_preload/OMPI_OMPI/app_mpi.h
file_ref_ompi_ompi_wrapper_f=$dir_ref_preload/OMPI_OMPI/wrapper_f.h

declare -A compare_match
declare -A result

compare_match["OMPI_run_mpi"]="$file_gen_ompi_run_mpi $file_ref_ompi_run_mpi"
compare_match["OMPI_app_mpi"]="$file_gen_ompi_app_mpi $file_ref_ompi_app_mpi"
compare_match["OMPI_wrapper_f"]="$file_gen_ompi_wrapper_f $file_ref_ompi_wrapper_f"

compare_match["INTEL_run_mpi"]="$file_gen_intel_run_mpi $file_ref_intel_run_mpi"
compare_match["INTEL_app_mpi"]="$file_gen_intel_app_mpi $file_ref_intel_app_mpi"
compare_match["INTEL_run_mpio"]="$file_gen_intel_run_mpio $file_ref_intel_run_mpio"
compare_match["INTEL_wrapper_f"]="$file_gen_intel_wrapper_f $file_ref_intel_wrapper_f"

compare_match["MPC_run_mpi"]="$file_gen_mpc_run_mpi $file_ref_mpc_run_mpi"
compare_match["MPC_app_mpi"]="$file_gen_mpc_app_mpi $file_ref_mpc_app_mpi"
compare_match["MPC_run_mpio"]="$file_gen_mpc_run_mpio $file_ref_mpc_run_mpio"
compare_match["MPC_wrapper_f"]="$file_gen_mpc_wrapper_f $file_ref_mpc_wrapper_f"

compare_match["MPICH_run_mpi"]="$file_gen_mpich_run_mpi $file_ref_mpich_run_mpi"
compare_match["MPICH_app_mpi"]="$file_gen_mpich_app_mpi $file_ref_mpich_app_mpi"
compare_match["MPICH_run_mpio"]="$file_gen_mpich_run_mpio $file_ref_mpich_run_mpio"
compare_match["MPICH_wrapper_f"]="$file_gen_mpich_wrapper_f $file_ref_mpich_wrapper_f"

compare_match["INTEL_INTEL_run_mpi"]="$file_gen_intel_intel_run_mpi $file_ref_intel_intel_run_mpi"
compare_match["INTEL_MPICH_run_mpi"]="$file_gen_intel_mpich_run_mpi $file_ref_intel_mpich_run_mpi"
compare_match["MPICH_MPICH_run_mpi"]="$file_gen_mpich_mpich_run_mpi $file_ref_mpich_mpich_run_mpi"
compare_match["MPICH_INTEL_run_mpi"]="$file_gen_mpich_intel_run_mpi $file_ref_mpich_intel_run_mpi"

compare_match["INTEL_INTEL_app_mpi"]="$file_gen_intel_intel_app_mpi $file_ref_intel_intel_app_mpi"
compare_match["INTEL_MPICH_app_mpi"]="$file_gen_intel_mpich_app_mpi $file_ref_intel_mpich_app_mpi"
compare_match["MPICH_MPICH_app_mpi"]="$file_gen_mpich_mpich_app_mpi $file_ref_mpich_mpich_app_mpi"
compare_match["MPICH_INTEL_app_mpi"]="$file_gen_mpich_intel_app_mpi $file_ref_mpich_intel_app_mpi"

compare_match["INTEL_INTEL_app_mpio"]="$file_gen_intel_intel_app_mpio $file_ref_intel_intel_app_mpio"
compare_match["INTEL_MPICH_app_mpio"]="$file_gen_intel_mpich_app_mpio $file_ref_intel_mpich_app_mpio"
compare_match["MPICH_MPICH_app_mpio"]="$file_gen_mpich_mpich_app_mpio $file_ref_mpich_mpich_app_mpio"
compare_match["MPICH_INTEL_app_mpio"]="$file_gen_mpich_intel_app_mpio $file_ref_mpich_intel_app_mpio"

compare_match["INTEL_INTEL_run_mpio"]="$file_gen_intel_intel_run_mpio $file_ref_intel_intel_run_mpio"
compare_match["INTEL_MPICH_run_mpio"]="$file_gen_intel_mpich_run_mpio $file_ref_intel_mpich_run_mpio"
compare_match["MPICH_MPICH_run_mpio"]="$file_gen_mpich_mpich_run_mpio $file_ref_mpich_mpich_run_mpio"
compare_match["MPICH_INTEL_run_mpio"]="$file_gen_mpich_intel_run_mpio $file_ref_mpich_intel_run_mpio"

compare_match["INTEL_INTEL_wrapper_f"]="$file_gen_intel_intel_wrapper_f $file_ref_intel_intel_wrapper_f"
compare_match["INTEL_MPICH_wrapper_f"]="$file_gen_intel_mpich_wrapper_f $file_ref_intel_mpich_wrapper_f"
compare_match["MPICH_MPICH_wrapper_f"]="$file_gen_mpich_mpich_wrapper_f $file_ref_mpich_mpich_wrapper_f"
compare_match["MPICH_INTEL_wrapper_f"]="$file_gen_mpich_intel_wrapper_f $file_ref_mpich_intel_wrapper_f"

compare_match["INTEL_OMPI_app_mpi"]="$file_gen_intel_ompi_app_mpi $file_ref_intel_ompi_app_mpi"
compare_match["MPICH_OMPI_app_mpi"]="$file_gen_mpich_ompi_app_mpi $file_ref_mpich_ompi_app_mpi"

compare_match["INTEL_OMPI_app_mpio"]="$file_gen_intel_ompi_app_mpio $file_ref_intel_ompi_app_mpio"
compare_match["MPICH_OMPI_app_mpio"]="$file_gen_mpich_ompi_app_mpio $file_ref_mpich_ompi_app_mpio"

compare_match["INTEL_OMPI_run_mpi"]="$file_gen_intel_ompi_run_mpi $file_ref_intel_ompi_run_mpi"
compare_match["MPICH_OMPI_run_mpi"]="$file_gen_mpich_ompi_run_mpi $file_ref_mpich_ompi_run_mpi"

compare_match["INTEL_OMPI_wrapper_f"]="$file_gen_intel_ompi_wrapper_f $file_ref_intel_ompi_wrapper_f"
compare_match["MPICH_OMPI_wrapper_f"]="$file_gen_mpich_ompi_wrapper_f $file_ref_mpich_ompi_wrapper_f"

compare_match["OMPI_INTEL_app_mpi"]="$file_gen_ompi_intel_app_mpi $file_ref_ompi_intel_app_mpi"
compare_match["OMPI_MPICH_app_mpi"]="$file_gen_ompi_mpich_app_mpi $file_ref_ompi_mpich_app_mpi"

compare_match["OMPI_INTEL_run_mpi"]="$file_gen_ompi_intel_run_mpi $file_ref_ompi_intel_run_mpi"
compare_match["OMPI_MPICH_run_mpi"]="$file_gen_ompi_mpich_run_mpi $file_ref_ompi_mpich_run_mpi"

compare_match["OMPI_INTEL_wrapper_f"]="$file_gen_ompi_intel_wrapper_f $file_ref_ompi_intel_wrapper_f"
compare_match["OMPI_MPICH_wrapper_f"]="$file_gen_ompi_mpich_wrapper_f $file_ref_ompi_mpich_wrapper_f"

compare_match["OMPI_INTEL_run_mpio"]="$file_gen_ompi_intel_run_mpio $file_ref_ompi_intel_run_mpio"
compare_match["OMPI_MPICH_run_mpio"]="$file_gen_ompi_mpich_run_mpio $file_ref_ompi_mpich_run_mpio"

compare_match["OMPI_OMPI_run_mpi"]="$file_gen_ompi_ompi_run_mpi $file_ref_ompi_ompi_run_mpi"
compare_match["OMPI_OMPI_app_mpi"]="$file_gen_ompi_ompi_app_mpi $file_ref_ompi_ompi_app_mpi"
compare_match["OMPI_OMPI_wrapper_f"]="$file_gen_ompi_ompi_wrapper_f $file_ref_ompi_ompi_wrapper_f"

sorted_step=(
"OMPI_run_mpi"
"OMPI_app_mpi"
"OMPI_wrapper_f"
"INTEL_run_mpi"
"INTEL_app_mpi"
"INTEL_run_mpio"
"INTEL_wrapper_f"
"MPC_run_mpi"
"MPC_app_mpi"
"MPC_run_mpio"
"MPC_wrapper_f"
"MPICH_run_mpi"
"MPICH_app_mpi"
"MPICH_run_mpio"
"MPICH_wrapper_f"
"INTEL_INTEL_run_mpi"
"INTEL_MPICH_run_mpi"
"MPICH_MPICH_run_mpi"
"MPICH_INTEL_run_mpi"
"INTEL_INTEL_app_mpi"
"INTEL_MPICH_app_mpi"
"MPICH_MPICH_app_mpi"
"MPICH_INTEL_app_mpi"
"INTEL_INTEL_app_mpio"
"INTEL_MPICH_app_mpio"
"MPICH_MPICH_app_mpio"
"MPICH_INTEL_app_mpio"
"INTEL_INTEL_run_mpio"
"INTEL_MPICH_run_mpio"
"MPICH_MPICH_run_mpio"
"MPICH_INTEL_run_mpio"
"INTEL_INTEL_wrapper_f"
"INTEL_MPICH_wrapper_f"
"MPICH_MPICH_wrapper_f"
"MPICH_INTEL_wrapper_f"
"INTEL_OMPI_app_mpi"
"MPICH_OMPI_app_mpi"
"INTEL_OMPI_app_mpio"
"MPICH_OMPI_app_mpio"
"INTEL_OMPI_run_mpi"
"MPICH_OMPI_run_mpi"
"INTEL_OMPI_wrapper_f"
"MPICH_OMPI_wrapper_f"
"OMPI_INTEL_app_mpi"
"OMPI_MPICH_app_mpi"
"OMPI_INTEL_run_mpi"
"OMPI_MPICH_run_mpi"
"OMPI_INTEL_wrapper_f"
"OMPI_MPICH_wrapper_f"
"OMPI_INTEL_run_mpio"
"OMPI_MPICH_run_mpio"
"OMPI_OMPI_run_mpi"
"OMPI_OMPI_app_mpi"
"OMPI_OMPI_wrapper_f"
)

rm -rf \
$dir_gen_interface/_MPC \
$dir_gen_interface/_OMPI \
$dir_gen_interface/_INTEL \
$dir_gen_interface/_MPICH \
$dir_gen_preload/INTEL_INTEL \
$dir_gen_preload/INTEL_MPICH \
$dir_gen_preload/MPICH_MPICH \
$dir_gen_preload/MPICH_INTEL \
$dir_gen_preload/INTEL_OMPI \
$dir_gen_preload/MPICH_OMPI \
$dir_gen_preload/OMPI_INTEL \
$dir_gen_preload/OMPI_MPICH

if [[ $GENERATOR_RUN == 1 ]]; then
export PYTHONPATH=$PYTHONPATH:$wi4mpi_dir/lib
cd $wi4mpi_dir
./lib/generator.py --interface_header_dir=$dir_gen_interface --preload_header_dir=$dir_gen_preload --c_preload_gen_dir=$dir_gen_c_preload --c_interface_gen_dir=$dir_gen_c_interface
fi

if [[ $GENERATOR_TEST_HEADER == 1 && $GENERATOR_RUN == 1 ]]; then
echo "-------------------------------------------------------------------------------------"
for step in "${sorted_step[@]}"; do
  _files=(${compare_match[$step]})
  _file_gen=${_files[0]}
  _file_ref=${_files[1]}
  _compare=0
  _msg="\033[1m* step $step\033[0m\n"
  if [[ -f $_file_gen ]]; then
    _msg+="Generated file detected\n"
  else
    _msg+="\033[33mGenerated file '$_file_gen' is missed \033[0m\n"
    _compare=$((_compare+1))
  fi
  if [[ -f $_file_ref ]]; then
    _msg+="Reference file detected\n"
  else
    _msg+="Reference file missed\n"
    _compare=$((_compare+2))
  fi
  echo -e "$_msg"
  if [[ $_compare == 0 ]]; then
    diff_gen_ref ${compare_match[$step]}
    result[$step]="$?"
  else
    result[$step]="2"
  fi
  echo
  echo "-------------------------------------------------------------------------------------"
done

string_return=(
  "\033[32mPASSED\033[0m"
  "\033[31mFAILED\033[0m"
  "\033[33mMISSED\033[0m"
)
_msg=""
validation=0
for step in "${sorted_step[@]}"; do
  res=${result[$step]}
  _msg+="$step:${string_return[$res]}\n"
  validation=$((validation + res))
done
echo -e $_msg | column -t -s ":"
if [[ $validation == 0 ]]; then
  echo -e "\033[32m[========]\n| PASSED |\n[========]\n\033[0m"
else
  echo -e "\033[31m[========]\n| FAILED |\n[========]\n\033[0m"
  exit 1
fi
fi

if [[ $GENERATOR_TEST_BUILD == 1 ]]; then
    if [[ $GENERATOR_RUN == 1 ]]; then
        cp $dir_gen_c_preload/test_c_gen_preload.c $wi4mpi_dir/src/preload/gen/mpi_translation_c.c
        cp $dir_gen_c_interface/test_c_gen_interface.c $wi4mpi_dir/src/interface/gen/mpi_translation_c.c
        cp $dir_gen_c_interface/interface_c.c $wi4mpi_dir/src/interface/gen/.
    fi
wi4mpi_build_prefix=$(mktemp -d)
wi4mpi_install_prefix=$(mktemp -d)
echo -e "\033[35m[=====================================]\n| Build   prefix: $wi4mpi_build_prefix |\n| Install prefix: $wi4mpi_install_prefix |\n[=====================================]\n\033[0m"
cd $wi4mpi_build_prefix
cmake \
 -DCMAKE_INSTALL_PREFIX=$wi4mpi_install_prefix\
 -DWI4MPI_COMPILER=GNU \
 $wi4mpi_dir
make -j 4 && make install
echo -e "\033[35m
  * Build prefix: $wi4mpi_build_prefix
  * Install prefix: $wi4mpi_install_prefix
  * Interface header directory: $dir_gen_interface
  * Preload header directory: $dir_gen_preload
  * Preload C code directory: $dir_gen_c_preload
  * Interface C code directory: $dir_gen_c_interface
\033[0m"
else
echo -e "\033[35m
  * Interface header directory: $dir_gen_interface
  * Preload header directory: $dir_gen_preload
  * Preload C code directory: $dir_gen_c_preload
  * Interface C code directory: $dir_gen_c_interface
\033[0m"
fi

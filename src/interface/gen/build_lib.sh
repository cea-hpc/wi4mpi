#!/bin/bash
rm *.o ../../common/*.o
for i in '../../common/new_utils_vcd.c'  '../../common/new_utils_fn.c' '../../common/asm_jit.c' '../../common/func_char_fort.c'  dlsym_global.c init_f2c.c test_generation_wrapper.c wrapper.c ;do
 icc -g -c $i -I/usr/include -I. -I../header/OMPI_$1/ -I../../common/ -DOMPI_$1 -DIFORT_CALL -Dompi_$2  -fPIC -std=c99 -D_GNU_SOURCE -DDEBUG -o ${i}_$1.o;
done
rm wi4mpi2_${1}.a
 ar cr wi4mpi2_${1}.a *.o ../../common/*.o
 rm rename_sym; for i in `nm wi4mpi2_${1}.a |grep -e '[0123456890abcdef]* [CTWbrtDB]' |sed /\.eh_frame*/d|sed s/[0123456789abcdef]*\ [CTWbrtDB]\ // `;do echo $i INTERF_2_${1}_$i >>rename_sym;done;sort -u rename_sym>tmp;cat tmp|sed -e /.*MPI_UNWEIGHTED/D  -e /^in_w/D > rename_sym
 objcopy --redefine-syms rename_sym wi4mpi2_${1}.a 
# objcopy   --strip-unneeded wi4mpi2_${1}.a 
ranlib wi4mpi2_${1}.a


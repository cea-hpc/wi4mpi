#!/bin/bash
 rm rename_sym_$1; for i in `nm $1 |grep -e '[0123456890abcdef]* [CTWbrtDB]' |sed /\.eh_frame*/d|sed s/[0123456789abcdef]*\ [CTWbrtDB]\ // `;do echo $i INTERF_2_${2}_$i >>rename_sym_$1;done;sort -u rename_sym_$1>tmp_$1;cat tmp_$1|sed -e /.*MPI_UNWEIGHTED/D  -e /^in_w/D > rename_sym_$1
 objcopy --redefine-syms rename_sym_$1 $1
#rm  rename_sym_$1
rm tmp_$1


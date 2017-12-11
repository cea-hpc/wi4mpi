#!/bin/bash
mkdir tmp_object_static
cd tmp_object_static
mkdir $2
mkdir $3
mkdir $4
cd $2
ar -x ../../$2
cd ../$3
ar -x ../../$3
cd ../$4
ar -x ../../$4
cd ..

ar cr ../$1 $2/*.o $3/*.o $4/*.o
cd ..
rm -rf tmp_object_static
rm $2 $3 $4


mkdir -p lib_static/interface/header/OMPI_$1
mkdir -p lib_static/common

mkdir -p lib_static/interface/gen
for i in `cat static_sources_$1`;
do 
#cat $i |sed -e s/A_MPI/INTERF_2_${1}_MPI/g -e  s/A_f_MPI/INTERF_2_${1}_f_MPI/g -e s/'A_##'/INTERF_2_${1}_\#\#/g -e s/R_MPI/INTERNAL_${1}_MPI/g -e  s/R_f_MPI/INTERNAL_${1}_f_MPI/g -e s/'R_##'/INTERNAL_${1}_\#\#/g > lib_static_$1/$i
cp $i lib_static/$i
done


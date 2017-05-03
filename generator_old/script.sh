python gen_wrapper_fort.py /ccc/products/openmpi-1.8.8/default /ccc/products/openmpi-1.8.8/default/ > wrapper_f.h
cp wrapper_f.h ../src/preload/header/OMPI_OMPI/wrapper_f.h 
python gen_wrapper_fort.py /ccc/products/openmpi-1.8.8/default /ccc/products/intelmpi-5.1.3.181/default/intel64/  > wrapper_f.h
cp wrapper_f.h ../src/preload/header/OMPI_INTEL/wrapper_f.h 
python gen_wrapper_fort.py /ccc/products/intelmpi-5.1.3.181/default/intel64/ /ccc/products/openmpi-1.8.8/default/ > wrapper_f.h
cp wrapper_f.h ../src/preload/header/INTEL_OMPI/wrapper_f.h 
python gen_wrapper_fort.py /ccc/products/intelmpi-5.1.3.181/default/intel64/ /ccc/products/intelmpi-5.1.3.181/default/intel64/ > wrapper_f.h
cp wrapper_f.h ../src/preload/header/INTEL_INTEL/wrapper_f.h 

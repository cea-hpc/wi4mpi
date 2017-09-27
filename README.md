# WI4MPI                                                                        

This is **WI4MPI**, Wrapper Interface For MPI performing a lightweight translation of MPI constants and MPI objects from an MPI implementation to another one.

WI4MPI provides two different modes:

Preload :
![alt tag](docs/Preload.png)

Interface :
![alt tag](docs/Interface.png)

## Installation

### Prerequisites

 In order to deploy WI4MPI you’ll need the following prerequisites:

* A C and Fortran compiler
* An MPI implementation such as [OpenMPI](https://www.open-mpi.org/)

 Please note that WI4MPI has been tested on GNU/Linux only, you may contact us if you have any requirement for improved portability.

### Compilation

To compile WI4MPI you may follow these simple steps invoking cmake:

```
$ mkdir BUILD ; cd BUILD
$ cmake -DCMAKE_INSTALL_PREFIX=/path-install/wi4mpi-%version /path/to/wi4mpi/source/root
$ make -j 4 && make install                          
```                                                           
At this point WI4MPI should be correctly installed and the « wi4mpi » command should be present (depending on your prefix) at the following location: WI4MPI dedicated launcher if available in /path-install/wi4mpi-%version/bin/wi4mpi

## Quick Start

The launcher command allows an easy use of the library. But before invoking this wrapper you must specify the path to your different MPI implementations in the *wi4mpi.cfg* configuration file located at : /install-path/wi4mpi-%version/etc/wi4mpi.cfg

```
Usage: [MPIRUN] [MPIRUN_OPTION]... wi4mpi [option].. PROGRAM [PROGRAM_OPTION]...
  Option:
    -f FROM      the MPI implementation the PROGRAM was compiled with
    -t TARGET    the MPI implementation you want the PROGRAM to be run on

The -f option (FROM) is optional. If not provided, the interface mode is chosen.
```

## Usage Examples

For example, to run from OpenMPI over IntelMPI, simply put the *wi4mpi* wrapper command before the program you want to invoke, this while preserving the original parameters. The *wi4mpi* commands takes two arguments a source implementation (-f) and a target implementation (-t).

```
$ mpirun -np 4 wi4mpi -f openmpi -t intelmpi mpi_hello.exe
You are using Wi4MPI-%version with the mode preload From OMPI To INTEL
Hello_world 0
Hello_world 2
Hello_world 3
Hello_world 1
```

You may also ignore the « -f » option, in this case *wi4mpi* runs in the interface mode, note that the « -t » option is compulsory.  

Please refer to the following section for explanations on the interface mode.

```
$ mpirun -np 4 wi4mpi -t intelmpi mpi_hello.exe
You are using Wi4MPI-%version with the mode interface From Interface To IntelMPI-2017.0.2.174
Hello_world 0
Hello_world 1
Hello_world 2
Hello_world 3
```

## Configuration for the Interface Mode

In the interface mode, the user specifies at runtime the target MPI implementation. Nevertheless, it is possible to specify a default MPI target implementation at application compilation thanks to the following option.

```
-wi4mpi_default_run_path    set a default MPI conversion
                            for the user application.
                            accepted values :
                              - OMPI
                              - IMPI
```
For example, to set the conversion Interface to OpenMPI please proceed as follows:

```
$ WI4MPI_CC=icc/gcc WI4MPI_ROOT=/path/to/wi4mpi/root mpicc -wi4mpi_default_run_path OMPI test.c -o init

mpirun -np 4 ./init
```

With the interface mode, wi4mpi provide an embedded mode where the binary file can be moved from a cluster to another one without compilation process. The only rule is to have IntelMPI/MPICH/MVAPICH or OpenMPI/BullxMPI available the system.

```
coming soon
```

## Configuration

This section presents the configuration variables supported by *wi4mpi*. They specify different modes and conversion models.

### Environment Variables
                                                                                                    
WI4MPI supported environment variables are the following:                                                                                         
                                                                                                        
  **WI4MPI_ROOT**: reference to the root wi4mpi installation                                        
  **WI4MPI_CC**: reference C compiler used by wi4mpi                                                                               
  **WI4MPI_FC**: reference Fortran compiler used by wi4mpi                                   
  **WI4MPI_CXX**: reference C++ compiler used by wi4mpi                                                                                  
  **WI4MPI_RUN_MPI_C_LIB**:Path to the underlying run MPI implementation for C libraries 
  **WI4MPI_RUN_MPI_F_LIB**: Path to Fortran libraries for the underlying run MPI implementation                                                                                                   
  **WI4MPI_WRAPPER_LIB**: Path to the wrapper library called by the interface             
  **WI4MPI_APP_INCLUDES**: Path to the internal includes used by the « JIT trick » to handle user function                                                                                            
  **WI4MPI_COMPILE_OPT**: Options passed during JIT compilation                          
  **WI4MPI_INTERNAL_INCLUDE**: Path to the internal include needed by JIT                 
  **WI4MPI_FROM**: defines FROM which MPI implementation the application has been compiled   
  **WI4MPI_TO**: defines the desired Runtime MPI implementation                            

### Preload settings                                                                                    
                                                                                                        
Here are some examples of setting to drive WI4MPI. In the following exemples, {FROM} and {TO} can take as value OMPI or INTEL depending on the choosen conversion

```
export WI4MPI_RUN_MPI_C_LIB="/path/to/MPI-runtime-implementation/libmpi.so"                             
export WI4MPI_RUN_MPI_F_LIB="/path/to/MPI-runtime-implementation/libmpi_mpifh.so"                       
export LD_PRELOAD="path_to_wi4mpi_install/libexec/libwi4mpi_{FROM}_{TO}.so $WI4MPI_RUN_MPI_F_LIB $WI4MPI
_RUN_MPI_C_LIB"                                                                                         
export WI4MPI_APP_INCLUDES="/path/to/wi4mpi/INTERNAL/preload/include/{FROM}_{TO}"  
                     
if OpenMPI --> OpenMPI                                                                                  

  export LD_LIBRARY_PATH="path_to_wi4mpi_install/libexec/fakelibCXX:$LD_LIBRARY_PATH"                   
  WI4MPI_COMPILE_OPT "-Dompi_ompi -DOMPI_OMPI"                                                          

else if OpenMPI --> IntelMPI                                                                            

  export LD_LIBRARY_PATH="path_to_wi4mpi_install/libexec/fakelibCXX:path_to_wi4mpi_install/libexec/fakel
ibOMPI:$LD_LIBRARY_PATH"                                                                                
  WI4MPI_COMPILE_OPT "-Dompi_mpich -DOMPI_INTEL"                                                        

else if IntelMPI --> IntelMPI                                                                           

  export LD_LIBRARY_PATH="path_to_wi4mpi_install/libexec/fakelibCXX:$LD_LIBRARY_PATH"                   
  WI4MPI_COMPILE_OPT "-Dmpich_mpich -DINTEL_INTEL"                                                      

else if IntelMPI --> OpenMPI                                                                            

  export LD_LIBRARY_PATH="path_to_wi4mpi_install/libexec/fakelibCXX:path_to_wi4mpi_install/libexec/fakel
ibINTEL:$LD_LIBRARY_PATH"                                                                               
  WI4MPI_COMPILE_OPT "-Dmpich_ompi -DINTEL_OMPI"                                                        
```
### Interface settings                                                                               
                                                                                                        
Here are some examples of environment variables to drive WI4MPI. In these examples, {FROM} and {TO} can take as a value OMPI or INTEL depending on the chosen conversion.                     
                                                                                                        
```
export WI4MPI_INTERNAL_INCLUDES="path_to_install/INTERNAL/include"                                      
export WI4MPI_ROOT="/path_to_wi4mpi_install_root"                                                       
export WI4MPI_CC=icc                                                                                    
export WI4MPI_FC=ifort                                                                                  
export WI4MPI_CXX=icpc                                                                                  
export WI4MPI_RUN_MPI_C_LIB="/path/to/MPI-runtime-implementation/libmpi.so"                             
export WI4MPI_RUN_MPI_F_LIB="/path/to/MPI-runtime-implementation/libmpi_mpifh.so"                       
export WI4MPI_WRAPPER_LIB="path_to_wi4mpi_install/lib_IMPI/libwi4mpi_CCC_{TO}.so"                       
export WI4MPI_APP_INCLUDES="path_to_install/INTERNAL/interface/include/{FROM}_{TO}"                     
export LD_LIBRARY_PATH="path_to_install/lib:$LD_LIBRARY_PATH"                                           

if CCC --> IntelMPI                                                                                     
  export WI4MPI_COMPILE_OPT="-Dompi_ompi -DOMPI_OMPI"                                                   

else if CCC --> OpenMPI                                                                                 

  export WI4MPI_COMPILE_OPT="-Dompi_mpich -DOMPI_INTEL"                                                 
```

## Contributing

Fell free to contact the authors if you want to contribute or request a feature.

## Authors

* vincent.ducrot.tgcc@cea.fr
* tony.delforge.tgcc@cea.fr 
 
## Contact

* bruno.froge@cea.fr  
* marc.perache@cea.fr 

## Website

[CEA-HPC](http://www-hpc.cea.fr/)

## License

Copyright 2015-2017 CEA/DAM/DIF<br />
<br />
WI4MPI is distributed under the CeCILL-C. See the included files <br />
Licence_CeCILL-C_V1-en.txt (English version) and <br />
Licence_CeCILL-C_V1-fr.txt (French version) or visit  <br />
http://www.cecill.info for details.

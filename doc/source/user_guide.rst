.. role:: math(raw)
   :format: html latex
..

User Guide
**********

Introduction
============

MPI is a standard in HPC community which allows a simple use of
clusters. Nowadays, there are several implementation (OpenMPI, BullxMPI,
MPT, IntelMPI, MPC, ...) each of which involves a specific ABI
(Application Binary Interface) for an application compiled with a
specific MPI implementation. With wi4mpi, an application compiled with
an alpha MPI implementation can be run under a beta MPI implementation
without any compilation protocol and any concern about the ABI (Preload
version). WI4MPI can also be seen as a dedicated MPI implementation;
This time, the application is compiled against the wi4mpi library
(libmpi.so) with the dedicated wrapper (mpicc,mpif90...) meant for that
purpose, and can be run under any other MPI implementation (Interface
Version).

Installation
============

The installation procedure is simply consists of a CMake make install
sequence.

.. code-block:: console

    mkdir BUILD ; cd BUILD
    cmake -DCMAKE_INSTALL_PREFIX=/path/to/install/dir ..
    make
    make install

CMAKE specific variables
-------------------------

- WI4MPI\_DEBUG:boolean

  | Activate some debug information. Useful for WI4MPI and applications developer.
  | Replace deprecated use of WI4MPI\_RELEASE=DEBUG.

-  WI4MPI\_COMPILER:string (deprecated)

   Indicate which compiler is used to compiled WI4MPI. Possible
   options: GCC(default), INTEL, PGI, LLVM, ARMCLANG, FUJITSU.

   This option is deprecated. Standard CMake procedure for compiler detection can
   now be used, by setting environment variable CC, CXX and FC or
   by using CMake's CMAKE\_<lang>\_COMPILER options.

-  OPENMPI\_ROOT
   
   Open MPI root dir, put in wi4mpi.cfg, could be added
   manually, optional value. This variable is required for Testing, one
   must add -DOPENMPI\_ROOT=/path/to/openmpi option.

-  INTELMPI\_ROOT
   
   Intel MPI root dir, put in wi4mpi.cfg, could be added
   manually, optional value.

-  MPC\_ROOT
   
   MPC root dir, put in wi4mpi.cfg, could be added manually,
   optional value.

-  MPICH\_ROOT
   
   MPICH root dir, put in wi4mpi.cfg, could be added
   manually, optional value.

-  WI4MPI\_RELEASE (deprecated)

   Indicate the Wi4MPI state set for the installation:

    - DEBUG: -DDEBUG is provided to activate some debug information. Useful for WI4MPI and applications developer.
    - NORMAL: -g is provided
    - RELEASE: -g is not provided

   This option is deprecated. Use of standard cmake build types and WI4MPI\_DEBUG option supersede this.
   Here is the equivalent usage:

        - DEBUG: ``-DWI4MPI_DEBUG=ON``
        - NORMAL: default, equivalent to ``-DCMAKE_BUILD_TYPE=RelWithDebInfo``
        - RELEASE: ``-DCMAKE_BUILD_TYPE=Release``

Both version (interface and preload) of wi4mpi are compiled and
installed into the CMAKE\_INSTALL\_PREFIX directory provided during the
CMake initialisation.

Usage
=====

As said in the introduction WI4MPI can be use with two different modes:

- INTERFACE

    The application is compiled using the mpi wrapper available
    within WI4MPI

        - Interface -> OpenMPI 
        - Interface -> IntelMPI 
        - Interface -> MPICH/MVAPICH 
        - Interface -> MPC 

- PRELOAD

    The application is compiled using the mpi
    wrapper available within common MPI Implementation Several conversions
    can be performed by wi4mpi.

        - Interface -> OpenMPI 
        - Interface -> IntelMPI 
        - Interface -> MPICH/MVAPICH 
        - Interface -> MPC 
        - OpenMPI -> OpenMPI 
        - OpenMPI -> IntelMPI 
        - OpenMPI -> MPICH/MVAPICH 
        - OpenMPI -> MPC 
        - IntelMPI -> OpenMPI 
        - IntelMPI -> IntelMPI 
        - IntelMPI -> MPICH/MVAPICH 
        - IntelMPI -> MPC 
        - MPICH/MVAPICH -> OpenMPI 
        - MPICH/MVAPICH -> IntelMPI 
        - MPICH/MVAPICH -> MPICH/MVAPICH 
        - MPICH/MVAPICH -> MPC

Quick start
-----------

WI4MPI dedicated launcher available in
/path-install/wi4mpi-%version/bin/wi4mpi allow an easy use of the
library. To work, users only have to set the path to the different MPI
implementation installation in
/path-install/wi4mpi-%version/etc/wi4mpi.cfg configuration file.

But, an mpirun command is also provided for more use.

.. code-block:: console

    Usage: mpirun [MPIRUN_TARGET_OPTIONS] -- [PROGRAM] [PROGRAM_OPTIONS]
    Advanced options:
        -F | -from | --from {FROM}      The MPI implementation from which PROGRAM was compiled with
        -T | -to | --to {TARGET}        The MPI implementation to which PROGRAM will be run

    The -F FROM option is optional. If not provided, the interface mode is chosen.

Example

.. code-block:: console

    mpirun -np 4 -F openmpi -T intelmpi mpi_hello.exe

In this example wi4mpi understand that mpi_hello.exe is a binary file compiled with OpenMPI, which is run under IntelMPI.

TGCC integration
----------------

WI4MPI is available on the TGCC via its module environment. All the
environment settings detailed in the next section is hide by a system of
flavor and features specific to the center. The flavor indicates the
kind of the installation chosen by the users, on the other hand, the
features are used to set one of the chosen conversion we highlight in
the previous section.

(Flavors et features are modulefiles) Concerning the flavors:

::

    - flavor/wi4mpi/{installation_type} : {installation_type} can be debug or standard

Concerning the features:

::

    - feature/wi4mpi/to/{MPI}/{version} : indicates the desired MPI version for the runtime ({MPI} can take two value OpenMPI or IntelMPI).
    - feature/wi4mpi/from/{MPI}/{version} : indicates the MPI version used to compiled the binary ELF file ({MPI} can take two value OpenMPI or IntelMPI). This features is not prerequisites, if not loaded (which is the default behaviour), the user is using WI4MPI in the interface.

Default behavior example:

::

    $ module load mpi/wi4mpi/%version
    load module flavor/wi4mpi/standard (wi4mpi flavor)                                                  #Default installation is standard
    load module feature/wi4mpi/to/openmpi/1.8.8 (WI4MPI feature to openmpi 1.8.8)                       #Default conversion is Interface -> OpenMPI/1.8.8 (since no module feature/wi4mpi/from is loaded, the wi4mpi mode is interface)
    load module feature/wi4mpi/mpi_compiler/intel (Wi4MPI compiler feature)                             #Default compiler use by mpi wrapper (mpicc,mpicxx,mpif90,...) within WI4MPI are Intel compilers
    load module wi4mpi/3.3.0 (Wi4MPI with openmpi/1.8.8)

    In this example, WI4MPI assume that the application is compiled with its own library libmpi.so

    To simply change the conversion "module switch feature/wi4mpi/to/intelmpi/2017"

To activate the preload mode example:

::

    $ module load mpi/wi4mpi/%version
    $ module load feature/wi4mpi/from/intelmpi/2017
    load module feature/wi4mpi/from/intelmpi/2017 (WI4MPI feature from intelmpi 2017)

Environment settings
--------------------

All variable used by WI4MPI to configure the library according to the
different modes and conversions.

- WI4MPI\_ROOT : reference to root wi4mpi installation 
- WI4MPI\_CC : reference C compiler used by wi4mpi 
- WI4MPI\_FC : reference Fortran compiler used by wi4mpi 
- WI4MPI\_CXX : reference C++ compiler used by wi4mpi 
- WI4MPI\_RUN\_MPI\_C\_LIB : reference the path to the underlying run MPI implementation path C library 
- WI4MPI\_RUN\_MPI\_F\_LIB : reference the path to the underlying run MPI implementation path Fortran library 
- WI4MPI\_RUN\_MPIIO\_C\_LIB : reference the path to the underlying run MPI-IO implementation path C library 
- WI4MPI\_RUN\_MPIIO\_F\_LIB : reference the path to the underlying run MPI-IO implementation path Fortran library 
- WI4MPI\_WRAPPER\_LIB : reference the path to the wrapper library call by the interface 
- WI4MPI\_APP\_INCLUDES : reference the path to the internal include used by the jit trick to handle user function 
- WI4MPI\_COMPILE\_OPT : reference the option passed during jit compilation 
- WI4MPI\_INTERNAL\_INCLUDE : reference the path to the internal include necessary to jit 
- WI4MPI\_FROM : reference FROM which MPI implementation the application has been compiled 
- WI4MPI\_TO : reference the desired Runtime MPI implementation 
- LD\_PRELOAD : see man 
- LD\_LIBRARY\_PATH : see man

Preload settings
~~~~~~~~~~~~~~~~

{FROM} and {TO} can take as value OMPI or INTEL depending on the chosen
conversion.

.. code-block:: bash

    export WI4MPI_RUN_MPI_C_LIB="/path/to/MPI-runtime-implementation/libmpi.so"
    export WI4MPI_RUN_MPI_F_LIB="/path/to/MPI-runtime-implementation/libmpi_mpifh.so"
    export WI4MPI_RUN_MPIIO_C_LIB="/path/to/MPIIO-runtime-implementation/libmpi.so"
    export WI4MPI_RUN_MPIIO_F_LIB="/path/to/MPIIO-runtime-implementation/libmpi_mpifh.so"
    export LD_PRELOAD="path_to_wi4mpi_install/libexec/libwi4mpi_{FROM}_{TO}.so $WI4MPI_RUN_MPI_F_LIB $WI4MPI_RUN_MPI_C_LIB"
    export WI4MPI_APP_INCLUDES="/path/to/wi4mpi/INTERNAL/preload/include/{FROM}_{TO}"
    #if OpenMPI --> OpenMPI
        export LD_LIBRARY_PATH="path_to_wi4mpi_install/libexec/fakelibCXX:$LD_LIBRARY_PATH"
        #WI4MPI_COMPILE_OPT "-DOMPI_OMPI"
    #else if OpenMPI --> IntelMPI
        export LD_LIBRARY_PATH="path_to_wi4mpi_install/libexec/fakelibCXX:path_to_wi4mpi_install/libexec/fakelibOMPI:$LD_LIBRARY_PATH"
        #WI4MPI_COMPILE_OPT "-DOMPI_INTEL"
    #else if IntelMPI --> IntelMPI
        export LD_LIBRARY_PATH="path_to_wi4mpi_install/libexec/fakelibCXX:$LD_LIBRARY_PATH"
        #WI4MPI_COMPILE_OPT "-DINTEL_INTEL"
    #else if IntelMPI --> OpenMPI
        export LD_LIBRARY_PATH="path_to_wi4mpi_install/libexec/fakelibCXX:path_to_wi4mpi_install/libexec/fakelibINTEL:$LD_LIBRARY_PATH"
        #WI4MPI_COMPILE_OPT "-DINTEL_OMPI"

Interface settings
~~~~~~~~~~~~~~~~~~

{FROM} and {TO} can take as value OMPI or INTEL depending on the chosen
conversion

.. code-block:: bash

    export WI4MPI_INTERNAL_INCLUDES="path_to_install/INTERNAL/include"
    export WI4MPI_ROOT="/path_to_wi4mpi_install_root"
    export WI4MPI_CC=icc
    export WI4MPI_FC=ifort
    export WI4MPI_CXX=icpc
    export WI4MPI_RUN_MPI_C_LIB="/path/to/MPI-runtime-implementation/libmpi.so"
    export WI4MPI_RUN_MPI_F_LIB="/path/to/MPI-runtime-implementation/libmpi_mpifh.so"
    export WI4MPI_RUN_MPIIO_C_LIB="/path/to/MPI-runtime-implementation/libmpi.so"
    export WI4MPI_RUN_MPIIO_F_LIB="/path/to/MPI-runtime-implementation/libmpi_mpifh.so"
    export WI4MPI_WRAPPER_LIB="path_to_wi4mpi_install/lib_IMPI/libwi4mpi_CCC_{TO}.so"
    export WI4MPI_APP_INCLUDES="path_to_install/INTERNAL/interface/include/{FROM}_{TO}"
    export LD_LIBRARY_PATH="path_to_install/lib:$LD_LIBRARY_PATH"
    #if Interface --> IntelMPI
        export WI4MPI_COMPILE_OPT="-D_OMPI"
    #else if Interface --> OpenMPI
        export WI4MPI_COMPILE_OPT="-D_INTEL"

WI4MPI features
---------------

Default Conversion Mode
~~~~~~~~~~~~~~~~~~~~~~~

During compilation time of the application, users are able to set a
default conversion using WI4MPI compiling wrapper by providing the
-wi4mpi\_default\_run\_path option.

example:

    mpicc -wi4mpi\_default\_run\_path OMPI hello.c -o hello

Two values can be passed with -wi4mpi\_default\_run\_path:

    - OMPI : set the default conversion to \_INTEL
    - IMPI : set the default conversion to \_OMPI

The runtime MPI library used is the ones referenced in the
etc/wi4mpi.cfg file, but be aware that they can be overidden using the
WI4MPI\_RUN\_MPI\_C\_LIB, and WI4MPI\_RUN\_MPI\_F\_LIB environment
variables as follow.

    WI4MPI\_RUN\_MPI\_C\_LIB="/path" WI4MPI\_RUN\_MPI\_F\_LIB="/path" mpicc -wi4mpi\_default\_run\_path OMPI hello.c -o hello

When the environment is set, the default conversion is not taken in
account.

Static Mode
~~~~~~~~~~~

There is a static mode in wi4mpi : this mode need to use the interface header and link to libmpi.a. All conversion are embedded and two environment variable specify the conversion type : WI4MPI_STATIC_TARGET_TYPE_F for Fortran conversion and WI4MPI_STATIC_TARGET_TYPE for C/C++ conversion; supported value are : OMPI and INTEL.

Use is the following

    set WI4MPI_RUN_MPI_C_LIB,WI4MPI_RUN_MPI_F_LIB to respective target library
    set WI4MPI_STATIC_TARGET_TYPE,WI4MPI_STATIC_TARGET_TYPE_F to conversion type according to target library.
    run executable.

Extended Debug Mode
~~~~~~~~~~~~~~~~~~~

As seen before, one is able to compile Wi4MPI with debug symbols thanks
to "-DWI4MPI\_RELEASE=DEBUG". Moreover, this setting enable an extended
debug mode. This feature allow to select any MPI function and print
input/ouput values after each call. One can select functions with
"WI4\_debug=1" environment variable (WI4MPI\_Init\_debut,
WI4MPI\_Allreduce\_debug...).

Examples:

::

    $ mpirun -n 1 ./hello
    You are using Wi4MPI-3.3.0a with the mode interface From Interface To OpenMPI-2.0.4
    Hello from 1/1

    $ WI4MPI_Init_debug=1 mpirun -n 1 ./hello
    You are using Wi4MPI-3.3.0a with the mode interface From Interface To OpenMPI-2.0.4
    MPI_Init :
    {
    argc : 1,
    argv : [
    ./hello.wmpi
    ]
    ,
    error/return : 0
    }
    Hello from 1/1

Debug output print respects JSON format in order to be easily parsed.

Timeout Helper Thread
~~~~~~~~~~~~~~~~~~~~~

For any reason you may want to kill a process which has passed too many
time into a function. Wi4MPI allow you to add a timeout to any MPI
function with "WI4\_timeout=" environment variables
(WI4MPI\_Init\_timeout, WI4MPI\_Allreduce\_timeout...).

This feature is only supported on GNU/Linux.

Examples:

::

    $ mpirun -n 1 ./hello
    You are using Wi4MPI-3.3.0a with the mode interface From Interface To OpenMPI-2.0.4
    Hello from 1/1

    $ WI4MPI_Init_timeout=1 mpirun -n 1 ./hello
    Wi4MPI error: process 25572 on host r0login has reached a timeout!
    Aborted

Developers words
================

First of all thanks a lot for using the wi4mpi software. Nevertheless be
aware that this software is still under development and that some bugs
may remain. If you encounter one of them, don't hesitate to contact one
of the authors and so to participate to the software robustness. Second,
wi4mpi is compatible with the 3.1 MPI norm. Don't hesitate to
participate :-)

https://github.com/cea-hpc/wi4mpi

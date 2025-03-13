.. role:: math(raw)
   :format: html latex
..

User Guide
**********

Introduction
============

MPI (Message Passing Interface) is a widely used standard in the HPC community
that enables efficient communication in distributed computing environments.
Today, multiple MPI implementations exist, including Open MPI, MPICH, IntelMPI,
or MPC, each with its own Application Binary Interface (ABI). As a result, an
application compiled with one MPI implementation is not directly compatible
with another without recompilation.

WI4MPI addresses this limitation by allowing an application compiled with an
"alpha" MPI implementation to run seamlessly under a "beta" MPI implementation—
without requiring recompilation or ABI compatibility adjustments (Preload
Version).

Preload Mode illustration:

.. image:: ../img/Preload.png
   :alt: Preload Mode Illustration

Additionally, WI4MPI can function as a dedicated MPI implementation. In this
mode, applications are compiled against the WI4MPI library (`libmpi.so`) using
its dedicated wrappers (e.g., `mpicc`, `mpif90`). These applications can then
run on any MPI implementation, ensuring broader compatibility (Interface
Version).

Interface Mode illustration:

.. image:: ../img/Interface.png
   :alt: Interface Mode Illustration

Installation
============

The installation process consists of a standard CMake build and installation sequence.
The release archive contains pre-generated code to simplify the build process.

.. code-block:: bash

    tar xf wi4mpi-x.y.z.tar
    cd wi4mpi/build
    cmake -DCMAKE_INSTALL_PREFIX=/path/to/install/dir ..
    make
    make install

If you are building from the Git repository or need to regenerate the code,
enable the `WI4MPI_GENERATOR` option as follows:

.. code-block:: bash

    git clone https://github.com/cea-hpc/wi4mpi.git
    mkdir -p wi4mpi/build
    cd wi4mpi/build
    cmake -DWI4MPI_GENERATOR=ON \
          -DCMAKE_INSTALL_PREFIX=/path/to/install/dir ..
    make
    make install

CMake Configuration Options
---------------------------

The following CMake variables can be used to configure the build:

- **WI4MPI_GENERATOR** (*boolean*)

  Enables code generation before building.

  **Default:** `OFF`

- **WI4MPI_GENERATOR_MPI_NORM** (*string*)

  Specifies the MPI standard version for the generated code.
  
  **Default:** `3.1`
  **Supported versions:** `1.0`, `1.1`, `1.2`, `2.0`, `2.1`, `2.2`, `3.0`, `3.1`, `4.0`

- **WI4MPI_GENERATOR_OPENMPI_VERSION** (*string*)

  Specifies the Open MPI header version used during code generation.
  
  **Default:** `1.8.8`
  **Supported versions:** `1.8.8`, `2.1.6`, `4.1.6`, `5.0.3`

- **WI4MPI_GENERATOR_MPICH_VERSION** (*string*)

  Specifies the MPICH header version used during code generation.

  **Default:** `3.1.2`
  **Supported versions:** `3.1.2`, `3.4.3`, `4.2.0`

- **WI4MPI_GENERATOR_INTELMPI_VERSION** (*string*)

  Specifies the Intel MPI header version used during code generation.
  
  **Default:** `20.0.0`
  **Supported versions:** `20.0.0`, `24.0.0`

- **WI4MPI_DEBUG** (*boolean*)

  Activates debug information. Useful for WI4MPI and application developers.

  **Default:** `OFF`

- **WI4MPI_COMPILER** (*string, deprecated*)

  Indicates which compiler is used to compile WI4MPI.

  **Default:** `GCC`
  **Supported options:** `GCC`, `INTEL`, `PGI`, `LLVM`, `ARMCLANG`, `FUJITSU`

  This option is deprecated. Use standard CMake compiler detection instead by
  setting environment variables `CC`, `CXX`, and `FC`, or by using `CMAKE_<lang>_COMPILER`.

- **OPENMPI_ROOT** (*path*)

  Specifies the Open MPI root directory.

  **Default:** *(none)*

  Optional value, manually added to `wi4mpi.cfg`. Required for testing.

- **INTELMPI_ROOT** (*path*)

  Specifies the Intel MPI root directory.

  **Default:** *(none)*

  Optional value, manually added to `wi4mpi.cfg`.

- **MPC_ROOT** (*path*)

  Specifies the MPC root directory.

  **Default:** *(none)*

  Optional value, manually added to `wi4mpi.cfg`.

- **MPICH_ROOT** (*path*)

  Specifies the MPICH root directory.

  **Default:** *(none)*

  Optional value, manually added to `wi4mpi.cfg`.

- **WI4MPI_RELEASE** (*string*)

  Indicates the build state of WI4MPI.

  **Default:** `NORMAL`
  **Supported options:**

  - `DEBUG`: Adds `-DDEBUG` to activate debug information.
  - `NORMAL`: Adds `-g`.
  - `RELEASE`: Does not add `-g`.

  This option is deprecated. Use standard CMake build types or the `WI4MPI_DEBUG` option instead:

  - `DEBUG`: `-DWI4MPI_DEBUG=ON`
  - `NORMAL`: Default, equivalent to `-DCMAKE_BUILD_TYPE=RelWithDebInfo`
  - `RELEASE`: `-DCMAKE_BUILD_TYPE=Release`

Both interface and preload versions of WI4MPI are compiled and installed into the
`CMAKE_INSTALL_PREFIX` directory provided during CMake initialization.

Usage
=====

WI4MPI can be used in two different modes:

- **INTERFACE mode**

  Applications are compiled directly using WI4MPI's MPI wrappers.

  Supported targets:

  - Interface → OpenMPI
  - Interface → IntelMPI
  - Interface → MPICH/MVAPICH
  - Interface → MPC

- **PRELOAD mode**

  Applications are compiled using the native MPI wrappers from a standard MPI implementation.
  WI4MPI handles conversions at runtime.

  Supported conversions:

  - Interface → OpenMPI, IntelMPI, MPICH/MVAPICH, MPC
  - OpenMPI → OpenMPI, IntelMPI, MPICH/MVAPICH, MPC
  - IntelMPI → OpenMPI, IntelMPI, MPICH/MVAPICH, MPC
  - MPICH/MVAPICH → OpenMPI, IntelMPI, MPICH/MVAPICH, MPC

Moreover, Wi4MPI could be used with dedicated launchers wrappers (`mpirun` & `wi4mpi`) or 
by settings environment variables.

For a more step-by-step document, look at:

  - :ref:`tutorial`
  - :ref:`tutorial_preload`
  - :ref:`tutorial_interface`

Running MPI programs with WI4MPI launchers
------------------------------------------

The easiest way to begin is the `mpirun` command provided by Wi4MPI:

.. code-block:: console

    Usage: mpirun [MPIRUN_TARGET_OPTIONS] -- [PROGRAM] [PROGRAM_OPTIONS]

    Advanced options:
      -F | -from | --from {FROM}    MPI implementation PROGRAM was compiled with
      -T | -to   | --to   {TARGET}  MPI implementation to run PROGRAM with

The `-F` option is optional; if omitted, Interface mode is selected by default.

Example:

.. code-block:: console

    mpirun -np 4 -F openmpi -T intelmpi mpi_hello.exe

In this example, `mpi_hello.exe` is an OpenMPI binary executed under IntelMPI.

But, WI4MPI provides directly a dedicated launcher located at:

.. code-block:: bash

    /path-install/wi4mpi-%version/bin/wi4mpi

Configure the paths to your MPI installations in:

.. code-block:: bash

    /path-install/wi4mpi-%version/etc/wi4mpi.cfg

Run it with your `TO` mpirun launcher.
For example:

.. code-block:: bash

    /path/to/openmpi/mpirun wi4mpi -f openmpi -t intelmpi mpi_hello.exe

Or with Slurm launcher:

.. code-block:: bash

    srun wi4mpi -f openmpi -t intelmpi mpi_hello.exe

Running Wi4MPI with environment varibales
-----------------------------------------

WI4MPI is configurable 100% with environment variables:

- ``WI4MPI_ROOT``: WI4MPI root installation path
- ``WI4MPI_CC``: C compiler used by WI4MPI
- ``WI4MPI_FC``: Fortran compiler used by WI4MPI
- ``WI4MPI_CXX``: C++ compiler used by WI4MPI
- ``WI4MPI_RUN_MPI_C_LIB``: Path to runtime MPI C library
- ``WI4MPI_RUN_MPI_F_LIB``: Path to runtime MPI Fortran library
- ``WI4MPI_RUN_MPIIO_C_LIB``: Path to runtime MPI-IO C library
- ``WI4MPI_RUN_MPIIO_F_LIB``: Path to runtime MPI-IO Fortran library
- ``WI4MPI_WRAPPER_LIB``: Path to interface wrapper library
- ``WI4MPI_APP_INCLUDES``: Path to internal includes for JIT compilation
- ``WI4MPI_COMPILE_OPT``: Compilation options for JIT compilation
- ``WI4MPI_INTERNAL_INCLUDE``: Internal include path needed for JIT
- ``WI4MPI_FROM``: MPI implementation used at compile-time
- ``WI4MPI_TO``: Target MPI implementation at runtime
- ``LD_PRELOAD``: Library preload mechanism (see ``man ld.so``)
- ``LD_LIBRARY_PATH``: Library search path (see ``man ld.so``)

Preload settings
~~~~~~~~~~~~~~~~

For a more step-by-step document, look at :ref:`tutorial_preload`.

Set `{FROM}` and `{TO}` as `OMPI` or `INTEL` according to your conversion needs.

Example configuration:

.. code-block:: bash

    # Example: OpenMPI → IntelMPI

    export WI4MPI_RUN_MPI_C_LIB="/path/to/runtime/libmpi.so"
    export WI4MPI_RUN_MPI_F_LIB="/path/to/runtime/libmpi_mpifh.so"
    export WI4MPI_RUN_MPIIO_C_LIB="/path/to/runtime/libmpi.so"
    export WI4MPI_RUN_MPIIO_F_LIB="/path/to/runtime/libmpi_mpifh.so"
    export WI4MPI_APP_INCLUDES="path_to_wi4mpi/INTERNAL/preload/include/{FROM}_{TO}"

    export LD_PRELOAD="path_to_wi4mpi/libexec/libwi4mpi_{FROM}_{TO}.so $WI4MPI_RUN_MPI_F_LIB $WI4MPI_RUN_MPI_C_LIB"
    export LD_LIBRARY_PATH="path_to_wi4mpi/libexec/fakelibCXX:path_to_wi4mpi/libexec/fakelibOMPI:$LD_LIBRARY_PATH"

Interface settings
~~~~~~~~~~~~~~~~~~

For a more step-by-step document, look at :ref:`tutorial_interface`.

Set `{FROM}` and `{TO}` as `OMPI` or `INTEL` according to your conversion needs.

Example configuration:

.. code-block:: bash

    # Example: Interface → IntelMPI

    export WI4MPI_ROOT="/path_to_wi4mpi_install_root"
    
    export WI4MPI_CC=icc
    export WI4MPI_FC=ifort
    export WI4MPI_CXX=icpc

    export WI4MPI_RUN_MPI_C_LIB="/path/to/runtime/libmpi.so"
    export WI4MPI_RUN_MPI_F_LIB="/path/to/runtime/libmpi_mpifh.so"
    export WI4MPI_RUN_MPIIO_C_LIB="/path/to/runtime/libmpi.so"
    export WI4MPI_RUN_MPIIO_F_LIB="/path/to/runtime/libmpi_mpifh.so"
    
    export WI4MPI_WRAPPER_LIB="path_to_wi4mpi/lib_IMPI/libwi4mpi_CCC_{TO}.so"
    export WI4MPI_APP_INCLUDES="path_to_wi4mpi/INTERNAL/interface/include/{FROM}_{TO}"
    export WI4MPI_INTERNAL_INCLUDES="path_to_wi4mpi/INTERNAL/include"

    export LD_LIBRARY_PATH="path_to_wi4mpi/lib:$LD_LIBRARY_PATH"

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

Developers' Note
================

Thank you for using WI4MPI! This software is actively developed and maintained,
but you might still encounter some issues. If you find any bugs or have suggestions,
please feel free to contact us or contribute directly via our GitHub repository.
Your feedback and contributions greatly help us improve the robustness and usability of WI4MPI.

Contribute here: https://github.com/cea-hpc/wi4mpi


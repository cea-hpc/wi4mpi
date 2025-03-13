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

Running Wi4MPI with environment variables
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


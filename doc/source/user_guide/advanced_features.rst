WI4MPI advanced features
========================

Default Conversion Mode
-----------------------

When compiling applications, users can set a default MPI implementation for runtime conversions using the WI4MPI wrapper's ``-wi4mpi_default_run_path`` option.

Usage example:

.. code-block:: console

    mpicc -wi4mpi_default_run_path OMPI hello.c -o hello

Available options for ``-wi4mpi_default_run_path``:

- ``OMPI``: Default runtime conversion to IntelMPI
- ``IMPI``: Default runtime conversion to OpenMPI

The runtime MPI libraries are configured in the ``etc/wi4mpi.cfg`` file. They can also be overridden at compile-time by setting the environment variables:

.. code-block:: bash

    export WI4MPI_RUN_MPI_C_LIB="/path/to/mpi_c_lib"
    export WI4MPI_RUN_MPI_F_LIB="/path/to/mpi_f_lib"

    mpicc -wi4mpi_default_run_path OMPI hello.c -o hello

Note: Environment variables take precedence over the default conversion settings.

Static Mode
-----------

WI4MPI supports a static mode, where conversions are embedded directly into the binary. Applications must be compiled using the WI4MPI interface headers and linked against ``libmpi.a``. Conversions are set at runtime through environment variables:

- ``WI4MPI_STATIC_TARGET_TYPE`` (for C/C++)
- ``WI4MPI_STATIC_TARGET_TYPE_F`` (for Fortran)

Accepted values are ``OMPI`` or ``INTEL``.

Usage example:

.. code-block:: bash

    export WI4MPI_RUN_MPI_C_LIB="/path/to/mpi_c_lib"
    export WI4MPI_RUN_MPI_F_LIB="/path/to/mpi_f_lib"
    export WI4MPI_STATIC_TARGET_TYPE="OMPI"
    export WI4MPI_STATIC_TARGET_TYPE_F="OMPI"

    ./your_executable

Extended Debug Mode
-------------------

WI4MPI offers an extended debug mode when compiled with debug symbols (``-DWI4MPI_DEBUG=ON``). This feature provides detailed tracing of MPI function calls, printing input and output parameters in JSON format for easy parsing. Individual functions can be selectively debugged by setting corresponding environment variables ``WI4MPI_{mpi-function}_debug``:

- ``WI4MPI_Init_debug=1``
- ``WI4MPI_Allreduce_debug=1``
- ``WI4MPI_Alltoall_debug=1``
- ``WI4MPI_XXX_debug=1``
- etc ...

Example usage:

.. code-block:: bash

    WI4MPI_Init_debug=1 mpirun -n 1 ./hello

.. code-block:: console

    You are using Wi4MPI-4.0.0 in the interface mode from Interface to OpenMPI-2.0.4

    MPI_Init :
    {
      "argc": 1,
      "argv": ["./hello.wmpi"],
      "error/return": 0
    }

    Hello from 1/1

Timeout Helper Thread
---------------------

WI4MPI allows you to set timeouts on individual MPI function calls, helping you identify and terminate functions exceeding expected execution times. This feature is controlled by environment variables (e.g., ``WI4MPI_Init_timeout``, ``WI4MPI_Allreduce_timeout``).

Note: Timeout functionality is available only on GNU/Linux systems.

Example usage:

.. code-block:: bash

    WI4MPI_Init_timeout=1 mpirun -n 1 ./hello

.. code-block:: console

    Wi4MPI error: process 25572 on host r0login has reached a timeout!
    Aborted


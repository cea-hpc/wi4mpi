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

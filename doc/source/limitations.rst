Known limitations
*****************

MPI C++ bindings
================

We do not support the obsolete C++ bindings of MPI, they were remove in MPI 3.0.

| Even if your code is not using them, we encountered issue with OpenMPI and NVHPC where some symbols were still included in the binary and prevented the use of Wi4MPI because of undefined symbols.
| Therefore, we recommend defining those macros when compiling C++ code to ensure none of the bindings leaks into the binary, even when you don't make use of it:

    - OMPI_SKIP_MPICXX for OpenMPI
    - MPICH_SKIP_MPICXX for MPICH and IntelMPI

MPI_MAX_* constants for strings size
====================================

MPI defines constants for the maximum length of some strings. Since their values can be different between the application side and the runtime side, truncation might happen.

This could provoke issues with some routines because the strings might have different values between what the application sees and what the runtime expects.

MPI_MAX_PORT_NAME
-----------------

Because port names are given by the runtime, if truncation happens the application will get a string that won't be usable in functions expecting a port name.

MPI_MAX_INFO_KEY
----------------

Since key-value pairs in an MPI_Info object have a maximum length, truncation of the key might happen when setting one. Thus you could have an MPI_Info object with unexpected behaviour.

MPI_MAX_INFO_VAL
----------------

The MPI standard discourage the allocation of a string with this size, allowing it to be very big. Thus we defer to the runtime the size check.
It means that a value might not be accepted when setting it, even if the application checked that it is less than MPI_MAX_INFO_VAL.

Other constants
---------------

Since other constants are either for information (type, window and communicator's name, processor name and library version string) or with only a portable subset (datarep of file views), their truncation is less at risk of provoking issues in their uses.

Support of MPIX_ Functions
==========================

MPIX_ functions represent experimental or extended features that are not part of the
official MPI standard. These functions are provided by some MPI implementations to explore
new capabilities or optimizations that may be considered for future inclusion in the MPI
standard. However, the availability and behavior of MPIX_ functions can vary significantly
between different MPI implementations, leading to potential portability and compatibility
issues.

Wi4MPI is designed to provide a high degree of portability and interoperability between
different MPI implementations, facilitating the development and execution of MPI
applications across a diverse range of HPC environments. To maintain this level of
compatibility and to ensure a stable and predictable behavior of MPI applications, **Wi4MPI
does not fully support MPIX_ functions**; this support is provided on a case-by-case basis.
At momment, **MPIX_Query_cuda_support** is supported. The support of other functions will
be evaluated on demand.


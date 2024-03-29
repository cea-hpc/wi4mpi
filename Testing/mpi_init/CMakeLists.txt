project (mpi_init)
cmake_minimum_required (VERSION 3.0.0)

# Copy source files
set (LIST_FILES mpi_init.c mpi_init.cpp mpi_init.f mpi_init.f90)
foreach (F ${LIST_FILES})
    file (COPY ${CMAKE_CURRENT_SOURCE_DIR}/${F}
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
endforeach ()

# Add tests
set (LIST_MPI_COMPILERS mpicc mpicxx mpic++ mpifort mpif77 mpif90)
foreach (COMP ${LIST_MPI_COMPILERS})
    file (COPY ${CMAKE_CURRENT_SOURCE_DIR}/run_mpi_init_from_${COMP}_tests.sh
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
    add_test (NAME mpi_init_from_${COMP}
        COMMAND bash ${CMAKE_CURRENT_BINARY_DIR}/run_mpi_init_from_${COMP}_tests.sh
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
endforeach ()

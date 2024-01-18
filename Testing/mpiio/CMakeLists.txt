project (mpiio)
cmake_minimum_required (VERSION 3.0.0)

# Add tests
file (COPY ${CMAKE_CURRENT_SOURCE_DIR}/run_mpi_file_open_tests.sh
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file (COPY ${CMAKE_CURRENT_SOURCE_DIR}/mpi_file_open.c
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
add_test (NAME mpi_file_open COMMAND bash ${CMAKE_CURRENT_BINARY_DIR}/run_mpi_file_open_tests.sh
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
set_tests_properties (mpi_file_open PROPERTIES TIMEOUT 30)

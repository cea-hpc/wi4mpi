project (mpirun)
cmake_minimum_required (VERSION 3.0.0)

# Add tests
file (COPY ${CMAKE_CURRENT_SOURCE_DIR}/run_mpirun_tests.sh
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
add_test (NAME mpirun COMMAND bash ${CMAKE_CURRENT_BINARY_DIR}/run_mpirun_tests.sh
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

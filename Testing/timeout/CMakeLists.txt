project (timeout)
cmake_minimum_required (VERSION 2.8)

file (COPY ${CMAKE_CURRENT_SOURCE_DIR}/timeout_slow_add.c
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file (COPY ${CMAKE_CURRENT_SOURCE_DIR}/run_timeout_tests.sh
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_test (NAME MPI_Reduce_timeout
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/run_timeout_tests.sh
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
set_tests_properties (MPI_Reduce_timeout PROPERTIES PASS_REGULAR_EXPRESSION 0
    TIMEOUT 30)

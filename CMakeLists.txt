cmake_minimum_required(VERSION 3.1.0)

if(${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.17")
# Specifies the logging level used by the message() command.
# The valid log levels are ERROR, WARNING, NOTICE, STATUS (default), VERBOSE, DEBUG, or TRACE.
set(CMAKE_MESSAGE_LOG_LEVEL WARNING CACHE STRING "Specifies the logging level used by the message() command.")
endif()

if(${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.13")
# Remove all progress messages regarding rules: example "[ x%] Built C object ..."
set(CMAKE_RULE_MESSAGES OFF CACHE STRING "Remove all progress messages regarding rules.")
else()
set(RULE_MESSAGES OFF)
endif()

if(${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.4")
# Remove all progress messages regarding targets: example "[ x%] Built target ..."
set(CMAKE_TARGET_MESSAGES OFF CACHE STRING "Remove all progress messages regarding targets.")
endif()

# NEVER: Removes all progress messages regarding installed files
# LAZY: Removes all progress messages regarding updated installed files
# ALWAYS: Displays all progress messages regarding installed files
set(CMAKE_INSTALL_MESSAGE NEVER CACHE STRING "Manage progres messages regarding installed files. Values are: NEVER, LAZY, ALWAYS")

if(POLICY CMP0054)
    cmake_policy(SET CMP0054 NEW)
endif()
if(POLICY CMP0057)
    CMAKE_POLICY(SET CMP0057 NEW)
endif()

enable_language(C CXX Fortran)
project(wi4mpi)

set(VERSION_MAJOR 3)
set(VERSION_MINOR 7)
set(VERSION_PATCH 1)

set(WI4MPI_VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})

#Path to CMake Module
set(CMAKE_MODULE_PATH
     ${CMAKE_MODULE_PATH}
     ${CMAKE_CURRENT_DIR}/cmake
   )

option(WI4MPI_DEBUG "Add debug printing in the wrapped calls")
option(WI4MPI_JIT "Use JIT compilation for user-provided stuff (required gcc in the PATH at run time")
option(WI4MPI_TIMEOUT "Activate timeout")
option(WI4MPI_GENERATOR "Enable generation of sources (headers and code)" OFF)
set(WI4MPI_GENERATOR_OPENMPI_VERSION "1.8.8" CACHE STRING "Version number of OpenMPI")
set(WI4MPI_GENERATOR_INTELMPI_VERSION "20.0.0" CACHE STRING "Version number of IntelMPI")
set(WI4MPI_GENERATOR_MPICH_VERSION "3.1.2" CACHE STRING "Version number of MPICH")
set(WI4MPI_GENERATOR_MPI_NORM "3.1" CACHE STRING "Version number of MPI norm to use")

#The Rpath Strikes Back
set(CMAKE_SKIP_RPATH TRUE)
#Default RPATH Settings 
###############################################################################
## use, i.e. don't skip the full RPATH for the build tree                     #
set(CMAKE_SKIP_BUILD_RPATH  FALSE)                                            #
#                                                                             #
## when building, don't use the install RPATH already                         #
## (but later on when installing)                                             #
set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)                                     #
#                                                                             #
## the RPATH to be used when installing                                       #
set(CMAKE_INSTALL_RPATH "")                                                   #
#                                                                             #
## don't add the automatically determined parts of the RPATH                  #
## which point to directories outside the build tree to the install RPATH     #
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH FALSE)                                  #
###############################################################################

if(WI4MPI_TIMEOUT MATCHES ON)
  if(CMAKE_SYSTEM_NAME MATCHES Linux)
    set(WI4MPI_TIMEOUT ON)
    add_definitions(-DTIMEOUT_SUPPORT)
  else()
    set(WI4MPI_TIMEOUT OFF)
  endif()
endif()
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

if(CMAKE_C_COMPILER_ID MATCHES "(GNU|Intel|Clang)")
    add_compile_options(-fcommon)
endif()
if(CMAKE_Fortran_COMPILER_ID MATCHES "Intel")
    add_definitions(-DIFORT_CALL)
elseif(CMAKE_Fortran_COMPILER_ID STREQUAL "Flang")
    add_definitions(-DFLANG_CALL)
elseif(CMAKE_Fortran_COMPILER_ID MATCHES "(PGI|NVHPC)")
    add_definitions(-DPGI_CALL)
elseif(CMAKE_Fortran_COMPILER_ID MATCHES "(GNU|Fujitsu)")
    add_definitions(-DGFORT_CALL)
else()
    message(FATAL_ERROR "Unsupported fortran compiler: ${CMAKE_Fortran_COMPILER}")
endif()
add_compile_options(-shared -fPIC)

# Allow implicit declartion with clang
# FIXME: we should properly declare/include to not have to use that
if(CMAKE_C_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wno-error=implicit-function-declaration)
endif()

#Define the compiling option according to the chosen release
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()
if(CMAKE_BUILD_TYPE MATCHES RelWithDebInfo)
    set(WI4MPI_DEBUG ON)
endif()
if(WI4MPI_JIT)
    set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()

set(CMAKE_C_FLAGS_RELWITHDEBINFO  "-g -O3")
set(CMAKE_C_FLAGS_RELEASE "-w -O3")

if(WI4MPI_DEBUG)
    add_definitions(-DDEBUG)
endif()
if(WI4MPI_JIT)
    add_definitions(-D_WI4MPI_GCC_JIT)
endif()

set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)
find_program(BASHPATH bash NO_DEFAULT_PATH PATHS /bin /usr/bin /usr/local/bin)
if(BASHPATH STREQUAL "BASHPATH-NOTFOUND")
    message(FATAL_ERROR "Bash shell not found. It is required for running wi4mpi.")
endif()
if(${CMAKE_VERSION} VERSION_LESS "3.17.0")
    if(NOT CMAKE_THREAD_LIBS_INIT)
        message(FATAL_ERROR "Be sure to have Pthread available on your system")
    endif()
else()
    if(NOT Threads_FOUND)
        message(FATAL_ERROR "Be sure to have Pthread available on your system")
    endif()
endif()

if(WI4MPI_GENERATOR)
  message(STATUS "Header and code generator is enabled.")
  find_package(Python3 COMPONENTS Interpreter REQUIRED)
  set(PYTHONPATH "${CMAKE_SOURCE_DIR}/src/generator:$ENV{PYTHONPATH}")
  message(STATUS "Updated PYTHONPATH: ${PYTHONPATH}")
  set(dir_gen_c_interface "${CMAKE_BINARY_DIR}/src/interface/gen")
  set(dir_gen_c_preload "${CMAKE_BINARY_DIR}/src/preload/gen")
  set(dir_gen_interface "${CMAKE_BINARY_DIR}/src/interface/header")
  set(dir_gen_preload "${CMAKE_BINARY_DIR}/src/preload/header")
  message(STATUS "Running header and code generator with arguments")
  message(STATUS "--interface_header_dir=${dir_gen_interface}")
  message(STATUS "--preload_header_dir=${dir_gen_preload}")
  message(STATUS "--c_preload_gen_dir=${dir_gen_c_preload}")
  message(STATUS "--c_interface_gen_dir=${dir_gen_c_interface}")
  message(STATUS "--openmpi_version=${WI4MPI_GENERATOR_OPENMPI_VERSION}")
  message(STATUS "--intelmpi_version=${WI4MPI_GENERATOR_INTELMPI_VERSION}")
  message(STATUS "--mpich_version=${WI4MPI_GENERATOR_MPICH_VERSION}")
  message(STATUS "--mpi_norm=${WI4MPI_GENERATOR_MPI_NORM}")
  message(STATUS "Option: set WI4MPI_GENERATOR_OPENMPI_VERSION to an OpenMPI available version: 1.8.8 2.1.6 4.1.6 5.0.3")
  message(STATUS "Option: set WI4MPI_GENERATOR_INTELMPI_VERSION to an IntelMPI available version: 20.0.0 24.0.0")
  message(STATUS "Option: set WI4MPI_GENERATOR_MPICH_VERSION to an MPICH available version: 3.1.2 3.4.3 4.2.0")
  message(STATUS "Option: set WI4MPI_GENERATOR_MPI_NORM to an available version: 1.0, 1.1, 1.2, 2.0, 2.1, 2.2, 3.0, 3.1, 4.0")
  execute_process(
      COMMAND python3 ${CMAKE_SOURCE_DIR}/src/generator/generator.py
                --interface_header_dir="${dir_gen_interface}"
                --preload_header_dir="${dir_gen_preload}"
                --c_preload_gen_dir="${dir_gen_c_preload}"
                --c_interface_gen_dir="${dir_gen_c_interface}"
                --openmpi_version="${WI4MPI_GENERATOR_OPENMPI_VERSION}"
                --intelmpi_version="${WI4MPI_GENERATOR_INTELMPI_VERSION}"
                --mpich_version="${WI4MPI_GENERATOR_MPICH_VERSION}"
                --mpi_norm="${WI4MPI_GENERATOR_MPI_NORM}"
      RESULT_VARIABLE is_generator_ok
  )
  if(NOT "${is_generator_ok}" STREQUAL "0")
    message(
      FATAL_ERROR
        "Generator failed."
    )
  endif()
  set(WI4MPI_GENDIR "${CMAKE_BINARY_DIR}/src")
else()
    message(STATUS "Header and code generator is disabled. Set WI4MPI_GENERATOR to ON to activate it.")
  set(WI4MPI_GENDIR "${CMAKE_SOURCE_DIR}/build/src")
endif()

#Copy share
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/share DESTINATION .)

#Source subdirectory
add_subdirectory(src)
enable_testing ()
add_subdirectory(Testing)

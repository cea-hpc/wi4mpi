cmake_minimum_required(VERSION 3.1.0)

if(${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.17")
# Specifies the logging level used by the message() command.
# The valid log levels are ERROR, WARNING, NOTICE, STATUS (default), VERBOSE, DEBUG, or TRACE.
set(CMAKE_MESSAGE_LOG_LEVEL WARNING CACHE STRING "Specifies logging level used by message() command (Default: WARNING)")
endif()

if(${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.13")
# Remove all progress messages regarding rules: example "[ x%] Built C object ..."
set(CMAKE_RULE_MESSAGES OFF CACHE STRING "Remove all progress messages about rules (Defaykt: OFF)")
else()
set(RULE_MESSAGES OFF)
endif()

if(${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.4")
# Remove all progress messages regarding targets: example "[ x%] Built target ..."
set(CMAKE_TARGET_MESSAGES OFF CACHE STRING "Remove all progress messages about targets (Default: OFF)")
endif()

# NEVER: Removes all progress messages regarding installed files
# LAZY: Removes all progress messages regarding updated installed files
# ALWAYS: Displays all progress messages regarding installed files
set(CMAKE_INSTALL_MESSAGE NEVER CACHE STRING "Manage progress messages about installed files (NEVER, LAZY, ALWAYS; default: NEVER)")

if(POLICY CMP0054)
    cmake_policy(SET CMP0054 NEW)
endif()
if(POLICY CMP0057)
    CMAKE_POLICY(SET CMP0057 NEW)
endif()

enable_language(C CXX Fortran)
project(wi4mpi)

set(VERSION_MAJOR 4)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)

set(WI4MPI_VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})

#Path to CMake Module
set(CMAKE_MODULE_PATH
     ${CMAKE_MODULE_PATH}
     ${CMAKE_CURRENT_DIR}/cmake
   )

option(WI4MPI_DEBUG "Add debug printing in the wrapped calls")
option(WI4MPI_JIT "Use JIT compilation for user-provided stuff (requires gcc in the PATH at runtime")
option(WI4MPI_TIMEOUT "Activate timeout")
option(WI4MPI_GENERATOR "Enable sources generation (headers and code)" OFF)
set(WI4MPI_GENERATOR_OPENMPI_VERSION "4.1.6" CACHE STRING "Open MPI version")
set(WI4MPI_GENERATOR_INTELMPI_VERSION "20.0.0" CACHE STRING "Intel MPI version")
set(WI4MPI_GENERATOR_MPICH_VERSION "4.2.0" CACHE STRING "MPICH version")
set(WI4MPI_GENERATOR_MPI_NORM "3.1" CACHE STRING "MPI norm version")

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

if(CMAKE_C_COMPILER_ID MATCHES "(GCC|GNU|Intel|Clang|gcc|gnu|intel|clang)")
    add_compile_options(-fcommon)
endif()
if(CMAKE_Fortran_COMPILER_ID MATCHES "(Intel|intel)")
    add_definitions(-DIFORT_CALL)
elseif(CMAKE_Fortran_COMPILER_ID STREQUAL "(Flang|flang)")
    add_definitions(-DFLANG_CALL)
elseif(CMAKE_Fortran_COMPILER_ID MATCHES "(PGI|NVHPC|pgi|nvhpc)")
    add_definitions(-DPGI_CALL)
elseif(CMAKE_Fortran_COMPILER_ID MATCHES "(GCC|GNU|Fujitsu|gcc|gnu|fujitsu)")
    add_definitions(-DGFORT_CALL)
else()
    message(FATAL_ERROR "Unsupported Fortran compiler: ${CMAKE_Fortran_COMPILER}")
endif()
add_compile_options(-shared -fPIC)

# Allow implicit declartion with clang
# FIXME: we should properly declare/include to not have to use that
if(CMAKE_C_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wno-error=implicit-function-declaration)
endif()

#Define the compiling option according to the chosen release
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
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
    message(FATAL_ERROR "Bash shell not found. It is required for running Wi4MPI.")
endif()
if(${CMAKE_VERSION} VERSION_LESS "3.17.0")
    if(NOT CMAKE_THREAD_LIBS_INIT)
        message(FATAL_ERROR "Make sure to have Pthread available on your system")
    endif()
else()
    if(NOT Threads_FOUND)
        message(FATAL_ERROR "Make sure to have Pthread available on your system")
    endif()
endif()

if(WI4MPI_GENERATOR)
  message(STATUS "Headers and code generation is enabled.")
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
  message(STATUS "Option: set WI4MPI_GENERATOR_OPENMPI_VERSION to a given Open MPI version (available versions: 1.8.8, 2.1.6, 4.1.6, 5.0.3)")
  message(STATUS "Option: set WI4MPI_GENERATOR_INTELMPI_VERSION to a given Intel MPI version (available versions: 20.0.0, 24.0.0)")
  message(STATUS "Option: set WI4MPI_GENERATOR_MPICH_VERSION to a given MPICH version (available versions: 3.1.2, 3.4.3, 4.2.0)")
  message(STATUS "Option: set WI4MPI_GENERATOR_MPI_NORM to a given version (available versions: 1.0, 1.1, 1.2, 2.0, 2.1, 2.2, 3.0, 3.1, 4.0)")
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
    message(STATUS "Headers and code generation is disabled. Set WI4MPI_GENERATOR to ON to activate it.")
  set(WI4MPI_GENDIR "${CMAKE_SOURCE_DIR}/build/src")
  if (NOT "${CMAKE_SOURCE_DIR}/build" STREQUAL "${CMAKE_BINARY_DIR}")
    message(FATAL_ERROR "Building without using the generator is only supported in the build directory inside the source directory")
  endif()
  set(GENERATED_FILES
    src/interface/gen/interface_c.c
    src/interface/gen/mpi_translation_c.c
    src/interface/gen/interface_fort.c
    src/interface/gen/mpi_translation_fort.c
    src/interface/header/_INTEL/run_mpi.h
    src/interface/header/_INTEL/run_mpio.h
    src/interface/header/_INTEL/wrapper_f.h
    src/interface/header/_INTEL/app_mpi.h
    src/interface/header/_MPC/run_mpi.h
    src/interface/header/_MPC/mpcmp.h
    src/interface/header/_MPC/run_mpio.h
    src/interface/header/_MPC/wrapper_f.h
    src/interface/header/_MPC/sctk_types.h
    src/interface/header/_MPC/app_mpi.h
    src/interface/header/_OMPI/run_mpi.h
    src/interface/header/_OMPI/wrapper_f.h
    src/interface/header/_OMPI/app_mpi.h
    src/interface/header/_MPICH/run_mpi.h
    src/interface/header/_MPICH/run_mpio.h
    src/interface/header/_MPICH/wrapper_f.h
    src/interface/header/_MPICH/app_mpi.h
    src/preload/gen/mpi_translation_c.c
    src/preload/gen/mpi_translation_fort.c
    src/preload/header/MPICH_INTEL/run_mpi.h
    src/preload/header/MPICH_INTEL/app_mpio.h
    src/preload/header/MPICH_INTEL/run_mpio.h
    src/preload/header/MPICH_INTEL/wrapper_f.h
    src/preload/header/MPICH_INTEL/app_mpi.h
    src/preload/header/OMPI_INTEL/run_mpi.h
    src/preload/header/OMPI_INTEL/run_mpio.h
    src/preload/header/OMPI_INTEL/wrapper_f.h
    src/preload/header/OMPI_INTEL/app_mpi.h
    src/preload/header/MPICH_OMPI/run_mpi.h
    src/preload/header/MPICH_OMPI/app_mpio.h
    src/preload/header/MPICH_OMPI/wrapper_f.h
    src/preload/header/MPICH_OMPI/app_mpi.h
    src/preload/header/OMPI_OMPI/run_mpi.h
    src/preload/header/OMPI_OMPI/wrapper_f.h
    src/preload/header/OMPI_OMPI/app_mpi.h
    src/preload/header/INTEL_OMPI/run_mpi.h
    src/preload/header/INTEL_OMPI/app_mpio.h
    src/preload/header/INTEL_OMPI/wrapper_f.h
    src/preload/header/INTEL_OMPI/app_mpi.h
    src/preload/header/INTEL_MPICH/run_mpi.h
    src/preload/header/INTEL_MPICH/app_mpio.h
    src/preload/header/INTEL_MPICH/run_mpio.h
    src/preload/header/INTEL_MPICH/wrapper_f.h
    src/preload/header/INTEL_MPICH/app_mpi.h
    src/preload/header/INTEL_INTEL/run_mpi.h
    src/preload/header/INTEL_INTEL/app_mpio.h
    src/preload/header/INTEL_INTEL/run_mpio.h
    src/preload/header/INTEL_INTEL/wrapper_f.h
    src/preload/header/INTEL_INTEL/app_mpi.h
    src/preload/header/OMPI_MPICH/run_mpi.h
    src/preload/header/OMPI_MPICH/run_mpio.h
    src/preload/header/OMPI_MPICH/wrapper_f.h
    src/preload/header/OMPI_MPICH/app_mpi.h
    src/preload/header/MPICH_MPICH/run_mpi.h
    src/preload/header/MPICH_MPICH/app_mpio.h
    src/preload/header/MPICH_MPICH/run_mpio.h
    src/preload/header/MPICH_MPICH/wrapper_f.h
    src/preload/header/MPICH_MPICH/app_mpi.h
  )
  foreach(gen_file ${GENERATED_FILES})
    if (NOT EXISTS "${gen_file}")
      message(FATAL_ERROR "Some generated files are missing, consider using the generator")
    endif()
  endforeach()
endif()

#Copy share
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/share DESTINATION .)

#Source subdirectory
add_subdirectory(src)
enable_testing ()
add_subdirectory(Testing)

cmake_minimum_required(VERSION 3.1.0)
#Default compiler for wi4mpi
if(WI4MPI_COMPILER)
    message(DEPRECATION "WI4MPI_COMPILER is deprecated. Set environment variables CC, CXX and FC, or use CMAKE_<lang>_COMPILER cmake's option instead.")
endif()
#Define common options according to the selected compiler
if(WI4MPI_COMPILER MATCHES GCC OR WI4MPI_COMPILER MATCHES GNU)
    # GNU value is deprecated
    set(CMAKE_C_COMPILER "gcc")
    set(CMAKE_CXX_COMPILER "g++")
    set(CMAKE_Fortran_COMPILER "gfortran")
elseif(WI4MPI_COMPILER MATCHES INTEL)
    set(CMAKE_C_COMPILER "icc")
    set(CMAKE_CXX_COMPILER "icpc")
    set(CMAKE_Fortran_COMPILER "ifort")
elseif(WI4MPI_COMPILER MATCHES PGI)
    set(CMAKE_C_COMPILER "pgcc")
    set(CMAKE_CXX_COMPILER "pgc++")
    set(CMAKE_Fortran_COMPILER "pgfortran")
elseif(WI4MPI_COMPILER MATCHES LLVM)
    set(CMAKE_C_COMPILER "clang")
    set(CMAKE_CXX_COMPILER "clang++")
    set(CMAKE_Fortran_COMPILER "flang")
elseif(WI4MPI_COMPILER MATCHES ARMCLANG)
    set(CMAKE_C_COMPILER "armclang")
    set(CMAKE_CXX_COMPILER "armclang++")
    set(CMAKE_Fortran_COMPILER "armflang")
elseif(WI4MPI_COMPILER MATCHES FUJITSU)
    set(CMAKE_C_COMPILER "fcc")
    set(CMAKE_CXX_COMPILER "FCC")
    set(CMAKE_Fortran_COMPILER "frt")
    # Force CMake to detect Fujitsu MPI Library, must be called BEFORE Find MPI
    set(MPI_C_COMPILER "mpifcc" CACHE STRING "" FORCE)
    set(MPI_CXX_COMPILER "mpiFCC" CACHE STRING "" FORCE)
    set(MPI_Fortran_COMPILER "mpifrt" CACHE STRING "" FORCE)
endif()

if(WI4MPI_RELEASE)
    message(DEPRECATION "WI4MPI_REALESE is deprecated. Use CMAKE_BUILD_TYPE, and options WI4MPI_DEBUG and WI4MPI_JIT instead.")
endif()
if(POLICY CMP0054)
    cmake_policy(SET CMP0054 NEW)
endif()
if(POLICY CMP0057)
    CMAKE_POLICY(SET CMP0057 NEW)
endif()

enable_language(C CXX Fortran)
project(wi4mpi)

set(VERSION_MAJOR 3)
set(VERSION_MINOR 6)
set(VERSION_PATCH 4)

set(WI4MPI_VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})

#Path to CMake Module
set(CMAKE_MODULE_PATH
     ${CMAKE_MODULE_PATH}
     ${CMAKE_CURRENT_DIR}/cmake
   )

option(WI4MPI_DEBUG "Add debug printing in the wrapped calls")
option(WI4MPI_JIT "Use JIT compilation for user-provided stuff (required gcc in the PATH at run time")

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

if(CMAKE_SYSTEM_NAME MATCHES Linux)
    set(WI4MPI_TIMEOUT ON)
    add_definitions(-DTIMEOUT_SUPPORT)
else()
    set(WI4MPI_TIMEOUT OFF)
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
if(WI4MPI_RELEASE MATCHES DEBUG)
   set(CMAKE_BUILD_TYPE "RelWithDebInfo")
   set(WI4MPI_DEBUG ON)
elseif(WI4MPI_RELEASE MATCHES RELEASE)
    set(CMAKE_BUILD_TYPE "Release")
elseif(WI4MPI_RELEASE MATCHES GCC_JIT)
    set(CMAKE_BUILD_TYPE "RelWithDebInfo")
    set(WI4MPI_JIT ON)
elseif(WI4MPI_RELEASE MATCHES NORMAL)
    set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()

set(CMAKE_C_FLAGS_RELWITHDEBINFO  "-g -O3")
set(CMAKE_C_FLAGS_RELEASE "-O3")
if(WI4MPI_DEBUG)
    add_definitions(-DDEBUG)
endif()
if(WI4MPI_JIT)
    add_definitions(-D_WI4MPI_GCC_JIT)
endif()

set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)
find_program(BASHPATH bash NO_DEFAULT_PATH PATHS /bin /usr/bin /usr/local/bin)
if(BATHPATH STREQUAL "BATHPATH-NOTFOUND")
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

#Setting wi4mpi.cfg
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/etc/wi4mpi.cfg.in ${CMAKE_CURRENT_BINARY_DIR}/wi4mpi.cfg)

#Copy share
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/share DESTINATION .)

#Source subdirectory
add_subdirectory(src)
enable_testing ()
add_subdirectory(Testing)

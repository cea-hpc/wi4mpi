cmake_minimum_required(VERSION 3.1.0)
#Default compiler for wi4mpi
if(NOT WI4MPI_COMPILER)
    set(WI4MPI_COMPILER GCC)
endif()
#Define common options according to the selected compiler
if(WI4MPI_COMPILER MATCHES GCC OR WI4MPI_COMPILER MATCHES GNU)
    # GNU value is deprecated
    if(WI4MPI_COMPILER MATCHES GNU)
    message(DEPRECATION "The GNU value for WI4MPI_COMPILER is deprecated and will be removed in the future; use GCC instead. However, for reasons of backward compatibility, the GNU syntax is still valid for now.")
    endif()
    set(CC "gcc")
    set(CXX "g++")
    set(FC "gfortran")
elseif(WI4MPI_COMPILER MATCHES INTEL)
    set(CC "icc")
    set(CXX "icpc")
    set(FC "ifort")
elseif(WI4MPI_COMPILER MATCHES PGI)
    set(CC "pgcc")
    set(CXX "pgc++")
    set(FC "pgfortran")
elseif(WI4MPI_COMPILER MATCHES LLVM)
    set(CC "clang")
    set(CXX "clang++")
    set(FC "flang")
elseif(WI4MPI_COMPILER MATCHES ARMCLANG)
    set(CC "armclang")
    set(CXX "armclang++")
    set(FC "armflang")
elseif(WI4MPI_COMPILER MATCHES FUJITSU)
    set(CC "fcc")
    set(CXX "FCC")
    set(FC "frt")
    # Force CMake to detect Fujitsu compilers, must be called BEFORE enable_language(Fortran)
    set(CMAKE_Fortran_COMPILER "frt" CACHE STRING "" FORCE)
    # Force CMake to detect Fujitsu MPI Library, must be called BEFORE Find MPI
    set(MPI_C_COMPILER "mpifcc" CACHE STRING "" FORCE)
    set(MPI_CXX_COMPILER "mpiFCC" CACHE STRING "" FORCE)
    set(MPI_Fortran_COMPILER "mpifrt" CACHE STRING "" FORCE)
endif()

# Check presence of CC, CXX and FC compilers
# If nothing is found, the result will be <VAR>-NOTFOUND
find_program(CC_PATH "${CC}")
if("${CC_PATH}" MATCHES "CC_PATH-NOTFOUND")
    message(FATAL_ERROR "C compiler not found in PATH!
    Current value of CC is: ${CC}")
endif()
find_program(CXX_PATH "${CXX}")
if("${CXX_PATH}" MATCHES "CXX_PATH-NOTFOUND")
    message(FATAL_ERROR "C++ compiler not found in PATH!
    Current value of CXX is: ${CXX}")
endif()
find_program(FC_PATH "${FC}")
if("${FC_PATH}" MATCHES "FC_PATH-NOTFOUND")
    message(FATAL_ERROR "Fortran compiler not found in PATH!
    Current value of FC is: ${FC}")
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
else()
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

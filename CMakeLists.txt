cmake_minimum_required(VERSION 2.8.0)
project(wi4mpi)
enable_language(C CXX Fortran)

set(VERSION_MAJOR 3)
set(VERSION_MINOR 4)
set(VERSION_PATCH 0)

set(WI4MPI_VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})

#Path to CMake Module
set(CMAKE_MODULE_PATH
     ${CMAKE_MODULE_PATH}
     ${CMAKE_CURRENT_DIR}/cmake
   )


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

#Default compiler for wi4mpi
if(NOT WI4MPI_COMPILER)
   set(WI4MPI_COMPILER INTEL)
endif()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DTIMEOUT_SUPPORT")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DTIMEOUT_SUPPORT")
#Define common options according to the selected compiler
if(WI4MPI_COMPILER MATCHES GNU)
    set(CMAKE_C_FLAGS_NORMAL  "${CMAKE_C_FLAGS} -g -O3 -fPIC -shared -pthread")
    set(CMAKE_C_FLAGS_DEBUG   "${CMAKE_C_FLAGS} -g -O3 -fPIC -shared -pthread -DDEBUG")
    set(CMAKE_C_FLAGS_GCC_JIT "${CMAKE_C_FLAGS} -g -O3 -fPIC -shared -pthread -D_WI4MPI_GCC_JIT")
    set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS} -O3 -fPIC -shared -pthread")
    set(WI4MPI_FORT_CALL "-DGFORT_CALL")
    set(CC "gcc")
    set(CXX "g++")
    set(FC "gfortran")
elseif(WI4MPI_COMPILER MATCHES INTEL)
    set(CMAKE_C_FLAGS_NORMAL  "${CMAKE_C_FLAGS} -g -O3 -fPIC -shared -pthread")
    set(CMAKE_C_FLAGS_DEBUG   "${CMAKE_C_FLAGS} -g -O3 -fPIC -shared -pthread -DDEBUG")
    set(CMAKE_C_FLAGS_GCC_JIT "${CMAKE_C_FLAGS} -g -O3 -fPIC -shared -pthread -D_WI4MPI_GCC_JIT")
    set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS} -O3 -fPIC -shared -pthread")
    set(WI4MPI_FORT_CALL "-DIFORT_CALL")
    set(CC "icc")
    set(CXX "icpc")
    set(FC "ifort")
elseif(WI4MPI_COMPILER MATCHES PGI)
    set(CMAKE_C_FLAGS_NORMAL  "${CMAKE_C_FLAGS} -g -O3 -c11 -fPIC -shared")
    set(CMAKE_C_FLAGS_DEBUG   "${CMAKE_C_FLAGS} -g -O3 -c11 -fPIC -shared -DDEBUG")
    set(CMAKE_C_FLAGS_GCC_JIT "${CMAKE_C_FLAGS} -g -O3 -c11 -fPIC -shared -D_WI4MPI_GCC_JIT")
    set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS} -O3 -c11 -fPIC -shared")
    set(WI4MPI_FORT_CALL "-DPGI_CALL")
    set(CC "pgcc")
    set(CXX "pgc++")
    set(FC "pgfortran")
elseif(WI4MPI_COMPILER MATCHES LLVM)
    set(CMAKE_C_FLAGS_NORMAL  "${CMAKE_C_FLAGS} -g -O3 -fPIC -shared")
    set(CMAKE_C_FLAGS_DEBUG   "${CMAKE_C_FLAGS} -g -O3 -fPIC -shared -DDEBUG")
    set(CMAKE_C_FLAGS_GCC_JIT "${CMAKE_C_FLAGS} -g -O3 -fPIC -shared -D_WI4MPI_GCC_JIT")
    set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS} -O3 -fPIC -shared")
    set(WI4MPI_FORT_CALL "-DFLANG_CALL")
    set(CC "clang")
    set(CXX "clang++")
    set(FC "flang")
elseif(WI4MPI_COMPILER MATCHES ARMCLANG)
    set(CMAKE_C_FLAGS_NORMAL  "${CMAKE_C_FLAGS} -g -O3 -fPIC -shared")
    set(CMAKE_C_FLAGS_DEBUG   "${CMAKE_C_FLAGS} -g -O3 -fPIC -shared -DDEBUG")
    set(CMAKE_C_FLAGS_GCC_JIT "${CMAKE_C_FLAGS} -g -O3 -fPIC -shared -D_WI4MPI_GCC_JIT")
    set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS} -O3 -fPIC -shared")
    set(WI4MPI_FORT_CALL "-DFLANG_CALL")
    set(CC "armclang")
    set(CXX "armclang++")
    set(FC "armflang")
endif()

#Define the compiling option according to the choosen realease
if(WI4MPI_REALEASE MATCHES DEBUG)
   set(WI4MPI_FLAGS ${CMAKE_C_FLAGS_DEBUG})
elseif(WI4MPI_REALEASE MATCHES RELEASE)
   set(WI4MPI_FLAGS ${CMAKE_C_FLAGS_RELEASE})
elseif(WI4MPI_REALEASE MATCHES GCC_JIT)
     set(WI4MPI_FLAGS ${CMAKE_C_FLAGS_GCC_JIT})
else()
   set(WI4MPI_FLAGS ${CMAKE_C_FLAGS_NORMAL})
endif()

find_package(MPI REQUIRED) 
if(MPI_C_FOUND AND MPI_Fortran_FOUND) #Need to be OpenMPI
    execute_process(COMMAND "${MPI_C_COMPILER}" -show
                    OUTPUT_VARIABLE ERR_VAR1
                    OUTPUT_FILE "compiler_out"
                    ERROR_QUIET)
    execute_process(COMMAND "grep" openmpi
                    INPUT_FILE "compiler_out"
                    OUTPUT_VARIABLE ERR_VAR2
                    RESULT_VARIABLE COMMAND_RESULT1
                    ERROR_QUIET)
    #execute_process(COMMAND "${MPI_C_COMPILER}" -show
    #                COMMAND "grep" -io openmpi
    #                 RESULT_VARIABLE RV)
    #message(STATUS "res command : ${ERR_VAR2}")
    if(NOT ERR_VAR2)
      message(FATAL_ERROR "Be sure to have an OpenMPI librarie in your PATH")
    endif()
        get_filename_component(OPENMPI_ROOT ${MPI_C_INCLUDE_PATH} DIRECTORY)
endif()

find_package(Threads)
if(NOT CMAKE_THREAD_LIBS_INIT)
    message(FATAL_ERROR "Be sure to have Pthread available on you system")
endif()

#Setting wi4mpi.cfg
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/etc/wi4mpi.cfg.in ${CMAKE_CURRENT_BINARY_DIR}/wi4mpi.cfg)


#Source subdirectory
add_subdirectory(src)
enable_testing ()
add_subdirectory(Testing)

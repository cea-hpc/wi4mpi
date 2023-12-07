cmake_minimum_required(VERSION 3.0.0)
project(wi4mpi)

if(POLICY CMP0054)
    cmake_policy(SET CMP0054 NEW)
endif()
if(POLICY CMP0057)
    CMAKE_POLICY(SET CMP0057 NEW)
endif()

set(VERSION_MAJOR 3)
set(VERSION_MINOR 6)
set(VERSION_PATCH 4)

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
    set(WI4MPI_COMPILER GCC)
endif()
if(CMAKE_SYSTEM_NAME MATCHES Linux)
    set(WI4MPI_TIMEOUT ON)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DTIMEOUT_SUPPORT")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DTIMEOUT_SUPPORT")
else()
    set(WI4MPI_TIMEOUT OFF)
endif()
#Define common options according to the selected compiler
if(WI4MPI_COMPILER MATCHES GCC)
    set(CMAKE_C_FLAGS_NORMAL  "${CMAKE_C_FLAGS} -g -O3 -fPIC -shared -pthread")
    set(CMAKE_C_FLAGS_DEBUG   "${CMAKE_C_FLAGS} -g -O3 -fPIC -shared -pthread -DDEBUG")
    set(CMAKE_C_FLAGS_GCC_JIT "${CMAKE_C_FLAGS} -g -O3 -fPIC -shared -pthread -D_WI4MPI_GCC_JIT")
    set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS} -O3 -fPIC -shared -pthread")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fcommon")
    set(WI4MPI_FORT_CALL "-DGFORT_CALL")
    set(CC "gcc")
    set(CXX "g++")
    set(FC "gfortran")
elseif(WI4MPI_COMPILER MATCHES GNU)
    # GNU value is deprecated
    message(DEPRECATION "The GNU value for WI4MPI_COMPILER is deprecated and will be removed in the future; use GCC instead. However, for reasons of backward compatibility, the GNU syntax is still valid for now.")
    set(CMAKE_C_FLAGS_NORMAL  "${CMAKE_C_FLAGS} -g -O3 -fPIC -shared -pthread")
    set(CMAKE_C_FLAGS_DEBUG   "${CMAKE_C_FLAGS} -g -O3 -fPIC -shared -pthread -DDEBUG")
    set(CMAKE_C_FLAGS_GCC_JIT "${CMAKE_C_FLAGS} -g -O3 -fPIC -shared -pthread -D_WI4MPI_GCC_JIT")
    set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS} -O3 -fPIC -shared -pthread")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fcommon")
    set(WI4MPI_FORT_CALL "-DGFORT_CALL")
    set(CC "gcc")
    set(CXX "g++")
    set(FC "gfortran")
elseif(WI4MPI_COMPILER MATCHES INTEL)
    set(CMAKE_C_FLAGS_NORMAL  "${CMAKE_C_FLAGS} -g -O3 -fPIC -shared -pthread")
    set(CMAKE_C_FLAGS_DEBUG   "${CMAKE_C_FLAGS} -g -O3 -fPIC -shared -pthread -DDEBUG")
    set(CMAKE_C_FLAGS_GCC_JIT "${CMAKE_C_FLAGS} -g -O3 -fPIC -shared -pthread -D_WI4MPI_GCC_JIT")
    set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS} -O3 -fPIC -shared -pthread")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fcommon")
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
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fcommon")
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
elseif(WI4MPI_COMPILER MATCHES FUJITSU)
    set(CMAKE_C_FLAGS_NORMAL  "${CMAKE_C_FLAGS} -g -O3 -fPIC -shared -pthread")
    set(CMAKE_C_FLAGS_DEBUG   "${CMAKE_C_FLAGS} -g -O3 -fPIC -shared -pthread -DDEBUG")
    set(CMAKE_C_FLAGS_GCC_JIT "${CMAKE_C_FLAGS} -g -O3 -fPIC -shared -pthread -D_WI4MPI_GCC_JIT")
    set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS} -O3 -fPIC -shared -pthread")
    set(WI4MPI_FORT_CALL "-DGFORT_CALL")
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
enable_language(C CXX Fortran)

#Define the compiling option according to the chosen release
if(WI4MPI_RELEASE MATCHES DEBUG)
   set(WI4MPI_FLAGS ${CMAKE_C_FLAGS_DEBUG})
elseif(WI4MPI_RELEASE MATCHES RELEASE)
   set(WI4MPI_FLAGS ${CMAKE_C_FLAGS_RELEASE})
elseif(WI4MPI_RELEASE MATCHES GCC_JIT)
     set(WI4MPI_FLAGS ${CMAKE_C_FLAGS_GCC_JIT})
else()
   set(WI4MPI_FLAGS ${CMAKE_C_FLAGS_NORMAL})
endif()


find_package(Threads)
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

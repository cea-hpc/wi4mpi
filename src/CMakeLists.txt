set(CMAKE_C_COMPILER ${CC})
set(CMAKE_Fortran_COMPILER ${FC})

#Sources list
#------------
#libmpi.so (wi4mpi side)
file(GLOB SOURCE_WI4MPI_SO
     interface/gen/interface_test.c
     interface/gen/interface_fort.c
    )  
#libwi4mpi_CCC_*.so
file(GLOB_RECURSE SOURCE_WI4MPI_INTERFACE
    interface/gen/test_generation_wrapper.c
    interface/gen/wrapper.c
    interface/gen/c2f_f2c.c
    common/new_utils.c      
    common/new_utils_fn.c 
    common/func_char_fort.c
    interface/manual/dlsym_global.c
)
#mpi.mod
file(GLOB_RECURSE SOURCE_WI4MPI_MODULE
     interface/module/mpi.f90
     interface/module/mpi_constants.f90
     interface/module/mpi_sizeof.f90
     interface/module/test_bk.f90
)

#libwi4mpi_FROM_TO.so
file(GLOB SOURCE_WI4MPI_PRELOAD
    preload/gen/test_generation_wrapper.c
    preload/gen/wrapper.c
    preload/gen/c2f_f2c.c
    common/new_utils.c
    common/new_utils_fn.c
    common/func_char_fort.c
)

#empty
file(GLOB SOURCE_WI4MPI_EMPTY
    preload/gen/lib_empty.c
)

###############
## INTERFACE ## 
###############

#Interface Libraries
#-------------------

add_library(mpi SHARED ${SOURCE_WI4MPI_SO})
add_library(wi4mpi_CCC_OMPI SHARED ${SOURCE_WI4MPI_INTERFACE}) 
add_library(wi4mpi_CCC_INTEL SHARED  ${SOURCE_WI4MPI_INTERFACE})
add_library(mpi_mod MODULE ${SOURCE_WI4MPI_MODULE})

#Headers
#-------

target_include_directories(mpi PRIVATE interface/manual)
target_include_directories(wi4mpi_CCC_OMPI
                           PRIVATE common
                           PRIVATE interface/header/OMPI_OMPI
                          )
target_include_directories(wi4mpi_CCC_INTEL
                           PRIVATE common
                           PRIVATE interface/header/OMPI_INTEL
                          )

#Flags
#-----

set_target_properties(mpi
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL}"
                     )
set_target_properties(wi4mpi_CCC_OMPI
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -DOMPI_OMPI -D__MPI__COMPILE__ -D_GNU_SOURCE -Dompi_ompi"
                     )
set_target_properties(wi4mpi_CCC_INTEL
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -DOMPI_INTEL -D_GNU_SOURCE -Dompi_mpich"
                     )

#############
## PRELOAD ##
#############

#Preload Libraries
#-----------------

add_library(wi4mpi_INTEL_INTEL SHARED ${SOURCE_WI4MPI_PRELOAD})
add_library(wi4mpi_INTEL_OMPI SHARED ${SOURCE_WI4MPI_PRELOAD})
add_library(wi4mpi_OMPI_INTEL SHARED ${SOURCE_WI4MPI_PRELOAD})
add_library(wi4mpi_OMPI_OMPI SHARED ${SOURCE_WI4MPI_PRELOAD})
#Empty libraries
add_library(mpifort.so.12 SHARED ${SOURCE_WI4MPI_EMPTY})
add_library(mpi.so.12 SHARED ${SOURCE_WI4MPI_EMPTY})
add_library(mpi.so.1 SHARED ${SOURCE_WI4MPI_EMPTY})
add_library(mpi_f77.so.1 SHARED ${SOURCE_WI4MPI_EMPTY})
add_library(mpi_f90.so.1 SHARED ${SOURCE_WI4MPI_EMPTY})
add_library(mpi_mpifh.so.2 SHARED ${SOURCE_WI4MPI_EMPTY})
add_library(mpi_cxx.so.1 SHARED ${SOURCE_WI4MPI_EMPTY})
add_library(mpi_cxx.so.12 SHARED ${SOURCE_WI4MPI_EMPTY})
add_library(mpigf.so.4 SHARED ${SOURCE_WI4MPI_EMPTY})
add_library(mpi_mt.so.4 SHARED ${SOURCE_WI4MPI_EMPTY})

#Headers
#-------

target_include_directories(wi4mpi_INTEL_INTEL
                           PRIVATE common
                           PRIVATE preload/header/INTEL_INTEL)
target_include_directories(wi4mpi_INTEL_OMPI
                           PRIVATE common
                           PRIVATE preload/header/INTEL_OMPI)
target_include_directories(wi4mpi_OMPI_INTEL
                           PRIVATE common
                           PRIVATE preload/header/OMPI_INTEL)
target_include_directories(wi4mpi_OMPI_OMPI
                           PRIVATE common
                           PRIVATE preload/header/OMPI_OMPI)

#Flags
#-----

set_target_properties(wi4mpi_INTEL_INTEL
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_GNU_SOURCE -DINTEL_INTEL -Dmpich_mpich"
)
set_target_properties(wi4mpi_INTEL_OMPI
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_GNU_SOURCE -DINTEL_OMPI -Dmpich_ompi"
)

set_target_properties(wi4mpi_OMPI_INTEL
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_GNU_SOURCE -DOMPI_INTEL -Dompi_mpich"
)
set_target_properties(wi4mpi_OMPI_OMPI
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_GNU_SOURCE -DOMPI_OMPI -Dompi_ompi"
)

set_target_properties(mpifort.so.12 
                      mpi.so.12
                      mpi.so.1
                      mpi_f77.so.1
                      mpi_f90.so.1
                      mpi_mpifh.so.2
                      mpi_cxx.so.1
                      mpi_cxx.so.12 
                      mpigf.so.4
                      mpi_mt.so.4
                      mpi_cxx.so.1
                      mpi_cxx.so.12 
                      mpigf.so.4
                      mpi_mt.so.4
PROPERTIES COMPILE_FLAGS "-shared -fPIC")


# Link options
#-------------

target_link_libraries(wi4mpi_INTEL_OMPI ${MPI_C_LIBRARIES})

# Installation specs
#-------------------

#Preload libraries
#-----------------
install(TARGETS 
        wi4mpi_INTEL_INTEL
        wi4mpi_INTEL_OMPI
        wi4mpi_OMPI_INTEL
        wi4mpi_OMPI_OMPI
        LIBRARY DESTINATION libexec/wi4mpi)

#fakelibCXX
install(TARGETS
        mpi_cxx.so.1
        mpi_cxx.so.12
        LIBRARY DESTINATION libexec/wi4mpi/fakelibCXX)

#fakelibINTEL
install(TARGETS
        mpi.so.12
        mpi.so.1
        mpigf.so.4
        mpi_mt.so.4
        LIBRARY DESTINATION libexec/wi4mpi/fakelibINTEL)

#fakelibOMPI
install(TARGETS
        mpi_f77.so.1
        mpi_f90.so.1
        mpi_mpifh.so.2
        mpi.so.1
        LIBRARY DESTINATION libexec/wi4mpi/fakelibOMPI)

#Interface libraries
#-------------------
install(TARGETS
        mpi
        LIBRARY DESTINATION lib)
install(TARGETS
        wi4mpi_CCC_OMPI 
        LIBRARY DESTINATION lib_OMPI)
install(TARGETS
        wi4mpi_CCC_INTEL
        LIBRARY DESTINATION lib_IMPI)

#Headers
#-------

install(FILES 
        interface/lib_cccmpi/include/mpi.h
        interface/lib_cccmpi/include/mpif-common.h	 
        interface/lib_cccmpi/include/mpif-config.h	 
        interface/lib_cccmpi/include/mpif-mpi-io.h	 
        interface/lib_cccmpi/include/mpif.h       	 
        interface/lib_cccmpi/include/mpif-handles.h 
        interface/lib_cccmpi/include/mpif-constants.h
        interface/lib_cccmpi/include/mpif-io-constants.h
        interface/lib_cccmpi/include/mpif-io-handles.h
        interface/lib_cccmpi/include/mpif-externals.h
        interface/lib_cccmpi/include/mpif-sentinels.h
        interface/lib_cccmpi/include/mpif-sizeof.h
        ${CMAKE_BINARY_DIR}/src/mpi.mod	 		 
        ${CMAKE_BINARY_DIR}/src/mpi_base.mod	 
        ${CMAKE_BINARY_DIR}/src/mpi_constants.mod
        ${CMAKE_BINARY_DIR}/src/mpi_sizeofs.mod DESTINATION include
        PERMISSIONS WORLD_READ OWNER_WRITE GROUP_WRITE WORLD_EXECUTE
)

#Bin
#---
install(FILES 
        interface/lib_cccmpi/bin/mpicc
        interface/lib_cccmpi/bin/mpicxx
        interface/lib_cccmpi/bin/mpic++
        interface/lib_cccmpi/bin/mpif77
        interface/lib_cccmpi/bin/mpif90
        interface/lib_cccmpi/bin/mpirun DESTINATION bin
        PERMISSIONS WORLD_READ WORLD_EXECUTE OWNER_WRITE GROUP_WRITE
)

install(FILES
        preload/bin/wi4mpi DESTINATION bin
        PERMISSIONS WORLD_READ WORLD_EXECUTE OWNER_WRITE GROUP_WRITE
)

set(CMAKE_C_COMPILER ${CC})
set(CMAKE_Fortran_COMPILER ${FC})

#Sources list
#------------
#libmpi.so (wi4mpi side)
file(GLOB SOURCE_WI4MPI_SO
     interface/gen/interface_c.c
     interface/gen/interface_fort.c
    )  
#libwi4mpi_CCC_*.so
file(GLOB_RECURSE SOURCE_WI4MPI_INTERFACE
    interface/gen/mpi_translation_c.c
#    interface/gen/mpi_translation_fort.c
#    interface/gen/c2f_f2c.c
#    interface/gen/mpi_translation_c2f_f2c_init.c
    common/engine.c      
    common/engine_fn.c 
#    common/func_char_fort.c
#		common/asm_jit.c
    interface/manual/dlsym_global.c
)
#mpi.mod
file(GLOB_RECURSE SOURCE_WI4MPI_MODULE
     interface/module/mpi.f90
     interface/module/mpi_constants.f90
     interface/module/mpi_sizeof.f90
     interface/module/mpi_base.f90
)
###############
## INTERFACE ## 
###############

#Interface Libraries
#-------------------

add_library(mpi SHARED ${SOURCE_WI4MPI_SO})
add_library(wi4mpi_CCC_OMPI SHARED ${SOURCE_WI4MPI_INTERFACE}) 
add_library(wi4mpi_CCC_INTEL SHARED  ${SOURCE_WI4MPI_INTERFACE})
#add_library(mpi_mod MODULE ${SOURCE_WI4MPI_MODULE})

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

#Link options
#------------

target_link_libraries(wi4mpi_CCC_OMPI ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(wi4mpi_CCC_INTEL ${CMAKE_THREAD_LIBS_INIT})

# Installation specs
#-------------------

# Listing headers to be installed
#COMMON
list(APPEND LIST_INTERNAL_COMMON_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/common/func_char_fort.h")
list(APPEND LIST_INTERNAL_COMMON_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/common/manual_wrapper.h")
list(APPEND LIST_INTERNAL_COMMON_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/common/mappers.h")
list(APPEND LIST_INTERNAL_COMMON_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/common/engine_fn.h")
list(APPEND LIST_INTERNAL_COMMON_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/common/engine.h")
list(APPEND LIST_INTERNAL_COMMON_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/common/optimisation.h")
list(APPEND LIST_INTERNAL_COMMON_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/common/thread_safety.h")
list(APPEND LIST_INTERNAL_COMMON_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/common/uthash.h")
list(APPEND LIST_INTERNAL_COMMON_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/common/utils.h")

install(FILES ${LIST_INTERNAL_COMMON_HEADER} DESTINATION INTERNAL/include)
#INTERFACE
	#OMPI_OMPI
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_O "${CMAKE_CURRENT_SOURCE_DIR}/interface/header/OMPI_OMPI/wrapper_f.h")
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_O "${CMAKE_CURRENT_SOURCE_DIR}/interface/header/OMPI_OMPI/app_mpi.h")
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_O "${CMAKE_CURRENT_SOURCE_DIR}/interface/header/OMPI_OMPI/run_mpi.h")
	#OMPI_INTEL
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_I "${CMAKE_CURRENT_SOURCE_DIR}/interface/header/OMPI_INTEL/wrapper_f.h")
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_I "${CMAKE_CURRENT_SOURCE_DIR}/interface/header/OMPI_INTEL/app_mpi.h")
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_I "${CMAKE_CURRENT_SOURCE_DIR}/interface/header/OMPI_INTEL/run_mpi.h")
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_I "${CMAKE_CURRENT_SOURCE_DIR}/interface/header/OMPI_INTEL/run_mpio.h")

install(FILES ${LIST_INTERNAL_INTERFACE_HEADER_O_O} DESTINATION INTERNAL/interface/include/OMPI_OMPI)
install(FILES ${LIST_INTERNAL_INTERFACE_HEADER_O_I} DESTINATION INTERNAL/interface/include/OMPI_INTEL)

#Interface libraries
#-------------------
install(TARGETS
        mpi
        LIBRARY DESTINATION lib
				PERMISSIONS WORLD_READ WORLD_EXECUTE OWNER_READ OWNER_EXECUTE OWNER_WRITE GROUP_WRITE GROUP_READ GROUP_EXECUTE
)
install(TARGETS
        wi4mpi_CCC_OMPI 
        LIBRARY DESTINATION lib_OMPI
				PERMISSIONS WORLD_READ WORLD_EXECUTE OWNER_READ OWNER_EXECUTE OWNER_WRITE GROUP_WRITE GROUP_READ GROUP_EXECUTE
)
install(TARGETS
        wi4mpi_CCC_INTEL
        LIBRARY DESTINATION lib_IMPI
				PERMISSIONS WORLD_READ WORLD_EXECUTE OWNER_READ OWNER_EXECUTE OWNER_WRITE GROUP_WRITE GROUP_READ GROUP_EXECUTE
)

#Headers
#-------

install(FILES 
        interface/interface_utils/include/mpi.h
        interface/interface_utils/include/mpif-common.h	 
        interface/interface_utils/include/mpif-config.h	 
        interface/interface_utils/include/mpif-mpi-io.h	 
        interface/interface_utils/include/mpif.h       	 
        interface/interface_utils/include/mpif-handles.h 
        interface/interface_utils/include/mpif-constants.h
        interface/interface_utils/include/mpif-io-constants.h
        interface/interface_utils/include/mpif-io-handles.h
        interface/interface_utils/include/mpif-externals.h
        interface/interface_utils/include/mpif-sentinels.h
        #${CMAKE_BINARY_DIR}/src/mpi.mod	 		 
        #${CMAKE_BINARY_DIR}/src/mpi_base.mod	 
        #${CMAKE_BINARY_DIR}/src/mpi_constants.mod
        #${CMAKE_BINARY_DIR}/src/mpi_sizeofs.mod
 DESTINATION include
        PERMISSIONS WORLD_READ WORLD_EXECUTE OWNER_READ OWNER_EXECUTE OWNER_WRITE GROUP_WRITE GROUP_READ GROUP_EXECUTE
)

install(DIRECTORY
        interface/interface_utils/include/gnu
        interface/interface_utils/include/intel DESTINATION include
)

#Bin
#---
install(FILES 
        interface/interface_utils/bin/mpicc
        interface/interface_utils/bin/mpicxx
        interface/interface_utils/bin/mpic++
        interface/interface_utils/bin/mpif77
        interface/interface_utils/bin/mpif90
        interface/interface_utils/bin/mpirun DESTINATION bin
        PERMISSIONS WORLD_READ WORLD_EXECUTE OWNER_READ OWNER_EXECUTE OWNER_WRITE GROUP_WRITE GROUP_READ GROUP_EXECUTE
)

install(FILES
        preload/bin/wi4mpi DESTINATION bin
        PERMISSIONS WORLD_READ WORLD_EXECUTE OWNER_READ OWNER_EXECUTE OWNER_WRITE GROUP_WRITE GROUP_READ GROUP_EXECUTE
)

#Wi4mpi config
#-------------

install(FILES
				${CMAKE_CURRENT_BINARY_DIR}/../wi4mpi.cfg DESTINATION etc
				PERMISSIONS WORLD_READ WORLD_EXECUTE OWNER_READ OWNER_EXECUTE OWNER_WRITE GROUP_WRITE GROUP_READ GROUP_EXECUTE
)

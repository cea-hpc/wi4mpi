set(CMAKE_C_COMPILER ${CC})
set(CMAKE_Fortran_COMPILER ${FC})

#Sources list
#------------
#libmpi.so (wi4mpi side)
file(GLOB SOURCE_WI4MPI_SO
     interface/gen/interface_c.c
     interface/gen/interface_fort.c
    )  
#libwi4mpi_*.so
file(GLOB_RECURSE SOURCE_WI4MPI_INTERFACE
    interface/gen/mpi_translation_c.c
    interface/gen/mpi_translation_fort.c
    interface/gen/c2f_f2c.c
    interface/gen/mpi_translation_c2f_f2c_init.c
    common/engine.c      
    common/engine_fn.c 
    common/func_char_fort.c
		common/asm_jit.c
    interface/manual/dlsym_global.c
)
#mpi.mod
file(GLOB_RECURSE SOURCE_WI4MPI_MODULE
     interface/module/mpi.f90
     interface/module/mpi_constants.f90
     interface/module/mpi_sizeof.f90
     interface/module/mpi_base.f90
)

#libwi4mpi_FROM_TO.so
file(GLOB SOURCE_WI4MPI_PRELOAD
    preload/gen/mpi_translation_c.c
    preload/gen/mpi_translation_fort.c
    preload/gen/c2f_f2c.c
		common/engine.c
    common/engine_fn.c
    common/func_char_fort.c
		common/asm_jit.c
)

#empty
file(GLOB SOURCE_WI4MPI_EMPTY
    preload/gen/lib_empty.c
)

#wi4mpi_preload_profiling
file(GLOB SOURCE_WI4MPI_PROFILING
		common/wi4mpi_debugger.c
)


####################
# WI4MPI_PROFILING #
####################

add_library(wi4mpi_profiling_OMPI SHARED ${SOURCE_WI4MPI_PROFILING})
add_library(wi4mpi_profiling_IMPI SHARED ${SOURCE_WI4MPI_PROFILING})

target_include_directories(wi4mpi_profiling_OMPI 
													 PRIVATE common
													 PRIVATE interface/header/_OMPI)
target_include_directories(wi4mpi_profiling_IMPI
													 PRIVATE common
													 PRIVATE interface/header/_INTEL)

set_target_properties(wi4mpi_profiling_OMPI 
											PROPERTIES
											COMPILE_FLAGS "${WI4MPI_FLAGS}")
set_target_properties(wi4mpi_profiling_IMPI 
											PROPERTIES
											COMPILE_FLAGS "${WI4MPI_FLAGS}")


install(TARGETS 
        wi4mpi_profiling_OMPI
        LIBRARY DESTINATION lib
        PERMISSIONS WORLD_READ WORLD_EXECUTE OWNER_READ OWNER_EXECUTE OWNER_WRITE GROUP_WRITE GROUP_READ GROUP_EXECUTE
)
install(TARGETS 
        wi4mpi_profiling_IMPI
        LIBRARY DESTINATION lib
        PERMISSIONS WORLD_READ WORLD_EXECUTE OWNER_READ OWNER_EXECUTE OWNER_WRITE GROUP_WRITE GROUP_READ GROUP_EXECUTE
)

###############
## INTERFACE ## 
###############

#Interface Libraries
#-------------------

add_library(mpi SHARED ${SOURCE_WI4MPI_SO})
add_library(wi4mpi_OMPI SHARED ${SOURCE_WI4MPI_INTERFACE}) 
add_library(wi4mpi_INTEL SHARED  ${SOURCE_WI4MPI_INTERFACE})
add_library(mpi_mod MODULE ${SOURCE_WI4MPI_MODULE})

add_library(mpi_a STATIC ${SOURCE_WI4MPI_SO})
add_library(wi4mpi_OMPI_a STATIC ${SOURCE_WI4MPI_INTERFACE}) 
add_library(wi4mpi_INTEL_a STATIC  ${SOURCE_WI4MPI_INTERFACE})

#dependencies
#-----------

add_dependencies(mpi_a wi4mpi_INTEL_a)
add_dependencies(mpi_a wi4mpi_OMPI_a)

#Headers
#-------

target_include_directories(mpi PRIVATE interface/manual)
target_include_directories(wi4mpi_OMPI
                           PRIVATE common
                           PRIVATE interface/header/_OMPI
                          )
target_include_directories(wi4mpi_INTEL
                           PRIVATE common
                           PRIVATE interface/header/_INTEL
                          )

target_include_directories(mpi_a PRIVATE interface/manual)
target_include_directories(wi4mpi_OMPI_a
                           PRIVATE common
                           PRIVATE interface/header/_OMPI
                          )
target_include_directories(wi4mpi_INTEL_a
                           PRIVATE common
                           PRIVATE interface/header/_INTEL
                          )

#Flags
#-----

set_target_properties(mpi
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL}"
                     )
set_target_properties(wi4mpi_OMPI
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_OMPI -D__MPI__COMPILE__ -D_GNU_SOURCE"
                     )
set_target_properties(wi4mpi_INTEL
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_INTEL -D_GNU_SOURCE"
                     )

set_target_properties(mpi_a
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -DWI4MPI_STATIC"
                     )
set_target_properties(wi4mpi_OMPI_a
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_OMPI -D__MPI__COMPILE__ -D_GNU_SOURCE -DWI4MPI_STATIC"
                     )
set_target_properties(wi4mpi_INTEL_a
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_INTEL -D_GNU_SOURCE -DWI4MPI_STATIC"
                     )

if(FC MATCHES gfortran) 
set_target_properties(mpi_mod
                      PROPERTIES
                      COMPILE_FLAGS "-ffree-line-length-0"
                     )

#Link options
#------------

target_link_libraries(wi4mpi_OMPI ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(wi4mpi_INTEL ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(wi4mpi_OMPI_a ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(wi4mpi_INTEL_a ${CMAKE_THREAD_LIBS_INIT})

#Custom command
#--------------

add_custom_command(TARGET wi4mpi_INTEL_a 
                    POST_BUILD
                   COMMAND  ${CMAKE_SOURCE_DIR}/scripts/rename_sym.sh libwi4mpi_INTEL_a.a "INTEL"
                   #WORKING_DIRECTORY ${CMAKE_BUILD_FILES_DIRECTORY}
                    )
message(status ${CMAKE_CURRENT_BINARY_DIR})
add_custom_command(TARGET wi4mpi_OMPI_a 
                    POST_BUILD
                  COMMAND  ${CMAKE_SOURCE_DIR}/scripts/rename_sym.sh libwi4mpi_OMPI_a.a "OMPI"
                    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}

                )
add_custom_command(TARGET mpi_a 
                POST_BUILD
                COMMAND ${CMAKE_SOURCE_DIR}/scripts/assemble_sym.sh libmpi.a libmpi_a.a libwi4mpi_INTEL_a.a libwi4mpi_OMPI_a.a
                    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}

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
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_GNU_SOURCE -DINTEL_INTEL"
)
set_target_properties(wi4mpi_INTEL_OMPI
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_GNU_SOURCE -DINTEL_OMPI "
)

set_target_properties(wi4mpi_OMPI_INTEL
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_GNU_SOURCE -DOMPI_INTEL"
)
set_target_properties(wi4mpi_OMPI_OMPI
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_GNU_SOURCE -DOMPI_OMPI"
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

target_link_libraries(wi4mpi_INTEL_OMPI ${MPI_C_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(wi4mpi_INTEL_INTEL ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(wi4mpi_OMPI_OMPI ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(wi4mpi_OMPI_INTEL ${CMAKE_THREAD_LIBS_INIT})

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
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_O "${CMAKE_CURRENT_SOURCE_DIR}/interface/header/_OMPI/wrapper_f.h")
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_O "${CMAKE_CURRENT_SOURCE_DIR}/interface/header/_OMPI/app_mpi.h")
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_O "${CMAKE_CURRENT_SOURCE_DIR}/interface/header/_OMPI/run_mpi.h")
	#OMPI_INTEL
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_I "${CMAKE_CURRENT_SOURCE_DIR}/interface/header/_INTEL/wrapper_f.h")
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_I "${CMAKE_CURRENT_SOURCE_DIR}/interface/header/_INTEL/app_mpi.h")
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_I "${CMAKE_CURRENT_SOURCE_DIR}/interface/header/_INTEL/run_mpi.h")
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_I "${CMAKE_CURRENT_SOURCE_DIR}/interface/header/_INTEL/run_mpio.h")

install(FILES ${LIST_INTERNAL_INTERFACE_HEADER_O_O} DESTINATION INTERNAL/interface/include/_OMPI)
install(FILES ${LIST_INTERNAL_INTERFACE_HEADER_O_I} DESTINATION INTERNAL/interface/include/_INTEL)
#PRELOAD
	#OMPI_OMPI
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_O_O "${CMAKE_CURRENT_SOURCE_DIR}/preload/header/OMPI_OMPI/wrapper_f.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_O_O "${CMAKE_CURRENT_SOURCE_DIR}/preload/header/OMPI_OMPI/app_mpi.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_O_O "${CMAKE_CURRENT_SOURCE_DIR}/preload/header/OMPI_OMPI/run_mpi.h")
	#OMPI_INTEL
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_O_I "${CMAKE_CURRENT_SOURCE_DIR}/preload/header/OMPI_INTEL/wrapper_f.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_O_I "${CMAKE_CURRENT_SOURCE_DIR}/preload/header/OMPI_INTEL/app_mpi.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_O_I "${CMAKE_CURRENT_SOURCE_DIR}/preload/header/OMPI_INTEL/run_mpi.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_O_I "${CMAKE_CURRENT_SOURCE_DIR}/preload/header/OMPI_INTEL/run_mpio.h")
	#INTEL_OMPI
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_I_O "${CMAKE_CURRENT_SOURCE_DIR}/preload/header/INTEL_OMPI/wrapper_f.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_I_O "${CMAKE_CURRENT_SOURCE_DIR}/preload/header/INTEL_OMPI/app_mpi.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_I_O "${CMAKE_CURRENT_SOURCE_DIR}/preload/header/INTEL_OMPI/app_mpio.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_I_O "${CMAKE_CURRENT_SOURCE_DIR}/preload/header/INTEL_OMPI/run_mpi.h")
	#INTEL_INTEL
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_I_I "${CMAKE_CURRENT_SOURCE_DIR}/preload/header/INTEL_INTEL/wrapper_f.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_I_I "${CMAKE_CURRENT_SOURCE_DIR}/preload/header/INTEL_INTEL/app_mpi.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_I_I "${CMAKE_CURRENT_SOURCE_DIR}/preload/header/INTEL_INTEL/app_mpio.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_I_I "${CMAKE_CURRENT_SOURCE_DIR}/preload/header/INTEL_INTEL/run_mpi.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_I_I "${CMAKE_CURRENT_SOURCE_DIR}/preload/header/INTEL_INTEL/run_mpio.h")
				
install(FILES ${LIST_INTERNAL_PRELOAD_HEADER_O_O} DESTINATION INTERNAL/preload/include/OMPI_OMPI) 
install(FILES ${LIST_INTERNAL_PRELOAD_HEADER_O_I} DESTINATION INTERNAL/preload/include/OMPI_INTEL) 
install(FILES ${LIST_INTERNAL_PRELOAD_HEADER_I_O} DESTINATION INTERNAL/preload/include/INTEL_OMPI) 
install(FILES ${LIST_INTERNAL_PRELOAD_HEADER_I_I} DESTINATION INTERNAL/preload/include/INTEL_INTEL) 
#Preload libraries
#-----------------
install(TARGETS 
        wi4mpi_INTEL_INTEL
        wi4mpi_INTEL_OMPI
        wi4mpi_OMPI_INTEL
        wi4mpi_OMPI_OMPI
        LIBRARY DESTINATION libexec/wi4mpi
				PERMISSIONS WORLD_READ WORLD_EXECUTE OWNER_READ OWNER_EXECUTE OWNER_WRITE GROUP_WRITE GROUP_READ GROUP_EXECUTE
)


#fakelibCXX
install(FILES ${CMAKE_BINARY_DIR}/src/libmpi_cxx.so.1.so DESTINATION libexec/wi4mpi/fakelibCXX
				RENAME libmpi_cxx.so.1
				PERMISSIONS WORLD_READ WORLD_EXECUTE OWNER_READ OWNER_EXECUTE OWNER_WRITE GROUP_WRITE GROUP_READ GROUP_EXECUTE
)

install(FILES ${CMAKE_BINARY_DIR}/src/libmpi_cxx.so.12.so DESTINATION libexec/wi4mpi/fakelibCXX
				RENAME libmpi_cxx.so.12
				PERMISSIONS WORLD_READ WORLD_EXECUTE OWNER_READ OWNER_EXECUTE OWNER_WRITE GROUP_WRITE GROUP_READ GROUP_EXECUTE
)

install(FILES ${CMAKE_BINARY_DIR}/src/libmpi_cxx.so.12.so DESTINATION libexec/wi4mpi/fakelibCXX
				RENAME libmpicxx.so.12
				PERMISSIONS WORLD_READ WORLD_EXECUTE OWNER_READ OWNER_EXECUTE OWNER_WRITE GROUP_WRITE GROUP_READ GROUP_EXECUTE
)

#fakelibINTEL
install(FILES ${CMAKE_BINARY_DIR}/src/libmpigf.so.4.so DESTINATION libexec/wi4mpi/fakelibINTEL
				RENAME libmpigf.so.4
				PERMISSIONS WORLD_READ WORLD_EXECUTE OWNER_READ OWNER_EXECUTE OWNER_WRITE GROUP_WRITE GROUP_READ GROUP_EXECUTE
)
install(FILES ${CMAKE_BINARY_DIR}/src/libmpi_mt.so.4.so DESTINATION libexec/wi4mpi/fakelibINTEL
				RENAME libmpi_mt.so.4
				PERMISSIONS WORLD_READ WORLD_EXECUTE OWNER_READ OWNER_EXECUTE OWNER_WRITE GROUP_WRITE GROUP_READ GROUP_EXECUTE
)
install(FILES ${CMAKE_BINARY_DIR}/src/libmpi.so.12.so DESTINATION libexec/wi4mpi/fakelibINTEL
				RENAME libmpi.so.12
				PERMISSIONS WORLD_READ WORLD_EXECUTE OWNER_READ OWNER_EXECUTE OWNER_WRITE GROUP_WRITE GROUP_READ GROUP_EXECUTE
)
install(FILES ${CMAKE_BINARY_DIR}/src/libmpi.so.1.so DESTINATION libexec/wi4mpi/fakelibINTEL
				RENAME libmpifort.so.12
				PERMISSIONS WORLD_READ WORLD_EXECUTE OWNER_READ OWNER_EXECUTE OWNER_WRITE GROUP_WRITE GROUP_READ GROUP_EXECUTE
)

#fakelibOMPI
install(FILES ${CMAKE_BINARY_DIR}/src/libmpi_f77.so.1.so	 DESTINATION libexec/wi4mpi/fakelibOMPI
				RENAME libmpi_f77.so.1
				PERMISSIONS WORLD_READ WORLD_EXECUTE OWNER_READ OWNER_EXECUTE OWNER_WRITE GROUP_WRITE GROUP_READ GROUP_EXECUTE
)	
install(FILES ${CMAKE_BINARY_DIR}/src/libmpi_f90.so.1.so	 DESTINATION libexec/wi4mpi/fakelibOMPI
				RENAME	libmpi_f90.so.1
				PERMISSIONS WORLD_READ WORLD_EXECUTE OWNER_READ OWNER_EXECUTE OWNER_WRITE GROUP_WRITE GROUP_READ GROUP_EXECUTE
)
install(FILES ${CMAKE_BINARY_DIR}/src/libmpi_mpifh.so.2.so DESTINATION libexec/wi4mpi/fakelibOMPI
				RENAME	libmpi_mpifh.so.2
				PERMISSIONS WORLD_READ WORLD_EXECUTE OWNER_READ OWNER_EXECUTE OWNER_WRITE GROUP_WRITE GROUP_READ GROUP_EXECUTE
)
install(FILES ${CMAKE_BINARY_DIR}/src/libmpi.so.1.so			 DESTINATION libexec/wi4mpi/fakelibOMPI
				RENAME	libmpi.so.1
				PERMISSIONS WORLD_READ WORLD_EXECUTE OWNER_READ OWNER_EXECUTE OWNER_WRITE GROUP_WRITE GROUP_READ GROUP_EXECUTE
)
				

#Interface libraries
#-------------------
install(TARGETS
        mpi
        LIBRARY DESTINATION lib
				PERMISSIONS WORLD_READ WORLD_EXECUTE OWNER_READ OWNER_EXECUTE OWNER_WRITE GROUP_WRITE GROUP_READ GROUP_EXECUTE
)
install(TARGETS
        wi4mpi_OMPI 
        LIBRARY DESTINATION lib_OMPI
				PERMISSIONS WORLD_READ WORLD_EXECUTE OWNER_READ OWNER_EXECUTE OWNER_WRITE GROUP_WRITE GROUP_READ GROUP_EXECUTE
)
install(TARGETS
        wi4mpi_INTEL
        LIBRARY DESTINATION lib_IMPI
				PERMISSIONS WORLD_READ WORLD_EXECUTE OWNER_READ OWNER_EXECUTE OWNER_WRITE GROUP_WRITE GROUP_READ GROUP_EXECUTE
)
install(FILES ${CMAKE_BINARY_DIR}/src/libmpi.a
				DESTINATION lib
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
        ${CMAKE_BINARY_DIR}/src/mpi.mod	 		 
        ${CMAKE_BINARY_DIR}/src/mpi_base.mod	 
        ${CMAKE_BINARY_DIR}/src/mpi_constants.mod
        ${CMAKE_BINARY_DIR}/src/mpi_sizeofs.mod DESTINATION include
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

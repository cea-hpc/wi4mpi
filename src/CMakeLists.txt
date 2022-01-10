set(CMAKE_C_COMPILER ${CC})
set(CMAKE_CXX_COMPILER ${CXX})
set(CMAKE_Fortran_COMPILER ${FC})

message(STATUS "Project compiler C/C++ : ${CC}/${CXX} && Fortran: ${FC}")

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
    common/helper.c
    common/debug_printer.c
    common/override.c
    common/mpi_translation_c2f_f2c_init.c
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
    common/override.c
    common/helper.c
    common/debug_printer.c
    common/mpi_translation_c2f_f2c_init.c
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
add_library(wi4mpi_profiling_INTEL SHARED ${SOURCE_WI4MPI_PROFILING})
add_library(wi4mpi_profiling_MPICH SHARED ${SOURCE_WI4MPI_PROFILING})
add_library(wi4mpi_profiling_MPC SHARED ${SOURCE_WI4MPI_PROFILING})

target_include_directories(wi4mpi_profiling_OMPI 
                                                     PRIVATE common
                                                     PRIVATE interface/header/_OMPI)
target_include_directories(wi4mpi_profiling_INTEL
                                                     PRIVATE common
                                                     PRIVATE interface/header/_INTEL)
target_include_directories(wi4mpi_profiling_MPICH
                                                     PRIVATE common
                                                     PRIVATE interface/header/_MPICH)
target_include_directories(wi4mpi_profiling_MPC
                                                     PRIVATE common
                                                     PRIVATE
                                                     interface/header/_MPC)

set_target_properties(wi4mpi_profiling_OMPI 
                                            PROPERTIES
                                            COMPILE_FLAGS "${WI4MPI_FLAGS}")
set_target_properties(wi4mpi_profiling_INTEL 
                                            PROPERTIES
                                            COMPILE_FLAGS "${WI4MPI_FLAGS}")
set_target_properties(wi4mpi_profiling_MPICH 
                                            PROPERTIES
                                            COMPILE_FLAGS "${WI4MPI_FLAGS}")
set_target_properties(wi4mpi_profiling_MPC 
                                            PROPERTIES
                                            COMPILE_FLAGS "${WI4MPI_FLAGS}")


install(TARGETS 
        wi4mpi_profiling_OMPI
        LIBRARY DESTINATION lib
        PERMISSIONS WORLD_READ WORLD_EXECUTE OWNER_READ OWNER_EXECUTE OWNER_WRITE GROUP_WRITE GROUP_READ GROUP_EXECUTE
)
install(TARGETS 
        wi4mpi_profiling_INTEL
        LIBRARY DESTINATION lib
        PERMISSIONS WORLD_READ WORLD_EXECUTE OWNER_READ OWNER_EXECUTE OWNER_WRITE GROUP_WRITE GROUP_READ GROUP_EXECUTE
)
install(TARGETS 
        wi4mpi_profiling_MPICH
        LIBRARY DESTINATION lib
        PERMISSIONS WORLD_READ WORLD_EXECUTE OWNER_READ OWNER_EXECUTE OWNER_WRITE GROUP_WRITE GROUP_READ GROUP_EXECUTE
)
install(TARGETS 
        wi4mpi_profiling_MPC
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
add_library(wi4mpi_MPICH SHARED  ${SOURCE_WI4MPI_INTERFACE})
add_library(wi4mpi_MPC SHARED  ${SOURCE_WI4MPI_INTERFACE})
add_library(mpi_mod MODULE ${SOURCE_WI4MPI_MODULE})

add_library(mpi_a STATIC ${SOURCE_WI4MPI_SO})
add_library(wi4mpi_OMPI_a STATIC ${SOURCE_WI4MPI_INTERFACE}) 
add_library(wi4mpi_INTEL_a STATIC  ${SOURCE_WI4MPI_INTERFACE})
add_library(wi4mpi_MPICH_a STATIC  ${SOURCE_WI4MPI_INTERFACE})
add_library(wi4mpi_MPC_a STATIC  ${SOURCE_WI4MPI_INTERFACE})

#dependencies
#-----------

add_dependencies(mpi_a wi4mpi_INTEL_a)
add_dependencies(mpi_a wi4mpi_MPICH_a)
add_dependencies(mpi_a wi4mpi_OMPI_a)
add_dependencies(mpi_a wi4mpi_MPC_a)

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
target_include_directories(wi4mpi_MPICH
                           PRIVATE common
                           PRIVATE interface/header/_MPICH
                          )
target_include_directories(wi4mpi_MPC
                           PRIVATE common
                           PRIVATE interface/header/_MPC
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
target_include_directories(wi4mpi_MPICH_a
                           PRIVATE common
                           PRIVATE interface/header/_MPICH
                          )
target_include_directories(wi4mpi_MPC_a
                           PRIVATE common
                           PRIVATE interface/header/_MPC
                          )

#Flags
#-----

set_target_properties(mpi
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL}"
                     )
if(CMAKE_C_COMPILER STREQUAL "icc")
set_target_properties(wi4mpi_OMPI
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_OMPI -D__MPI__COMPILE__ -D_GNU_SOURCE"
                     )
set_target_properties(wi4mpi_INTEL
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_INTEL -D_GNU_SOURCE"
                     )
set_target_properties(wi4mpi_MPICH
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_INTEL -D_GNU_SOURCE"
                     )
set_target_properties(wi4mpi_MPC
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_MPC -D_GNU_SOURCE"
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
set_target_properties(wi4mpi_MPICH_a
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_INTEL -D_GNU_SOURCE -DWI4MPI_STATIC"
                     )
set_target_properties(wi4mpi_MPC_a
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_MPC -D_GNU_SOURCE -DWI4MPI_STATIC"
                     )
endif()
if(CMAKE_C_COMPILER STREQUAL "gcc") 
set_target_properties(wi4mpi_OMPI
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_OMPI -D__MPI__COMPILE__ -D_GNU_SOURCE"
                     )
set_target_properties(wi4mpi_INTEL
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_INTEL -D_GNU_SOURCE"
                     )
set_target_properties(wi4mpi_MPICH
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_INTEL -D_GNU_SOURCE"
                     )
set_target_properties(wi4mpi_MPC
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_MPC -D_GNU_SOURCE"
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
set_target_properties(wi4mpi_MPICH_a
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_INTEL -D_GNU_SOURCE -DWI4MPI_STATIC"
                     )
set_target_properties(wi4mpi_MPC_a
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_MPC -D_GNU_SOURCE -DWI4MPI_STATIC"
                     )
endif()
if(CMAKE_C_COMPILER STREQUAL "pgcc")
set_target_properties(wi4mpi_OMPI
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -c11 -D_OMPI -D__MPI__COMPILE__ -D_GNU_SOURCE"
                     )
set_target_properties(wi4mpi_INTEL
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -c11 -D_INTEL -D_GNU_SOURCE"
                     )
set_target_properties(wi4mpi_MPICH
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -c11 -D_INTEL -D_GNU_SOURCE"
                     )
set_target_properties(wi4mpi_MPC
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -c11 -D_MPC -D_GNU_SOURCE"
                     )

set_target_properties(mpi_a
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -DWI4MPI_STATIC"
                     )
set_target_properties(wi4mpi_OMPI_a
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -c11 -D_OMPI -D__MPI__COMPILE__ -D_GNU_SOURCE -DWI4MPI_STATIC"
                     )
set_target_properties(wi4mpi_INTEL_a
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -c11 -D_INTEL -D_GNU_SOURCE -DWI4MPI_STATIC"
                     )
set_target_properties(wi4mpi_MPICH_a
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -c11 -D_INTEL -D_GNU_SOURCE -DWI4MPI_STATIC"
                     )
set_target_properties(wi4mpi_MPC_a
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -c11 -D_MPC -D_GNU_SOURCE -DWI4MPI_STATIC"
                     )
endif()
if(CMAKE_C_COMPILER MATCHES ".*clang")
set_target_properties(wi4mpi_OMPI
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_OMPI -D__MPI__COMPILE__ -D_GNU_SOURCE"
                     )
set_target_properties(wi4mpi_INTEL
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_INTEL -D_GNU_SOURCE"
                     )
set_target_properties(wi4mpi_MPICH
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_INTEL -D_GNU_SOURCE"
                     )
set_target_properties(wi4mpi_MPC
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_MPC -D_GNU_SOURCE"
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
set_target_properties(wi4mpi_MPICH_a
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_INTEL -D_GNU_SOURCE -DWI4MPI_STATIC"
                     )
set_target_properties(wi4mpi_MPC_a
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_MPC -D_GNU_SOURCE -DWI4MPI_STATIC"
                     )
endif()
if(CMAKE_C_COMPILER STREQUAL "fcc")
set_target_properties(wi4mpi_OMPI
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_OMPI -D__MPI__COMPILE__ -D_GNU_SOURCE"
                     )
set_target_properties(wi4mpi_INTEL
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_INTEL -D_GNU_SOURCE"
                     )
set_target_properties(wi4mpi_MPICH
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_INTEL -D_GNU_SOURCE"
                     )
set_target_properties(wi4mpi_MPC
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_MPC -D_GNU_SOURCE"
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
set_target_properties(wi4mpi_MPICH_a
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_INTEL -D_GNU_SOURCE -DWI4MPI_STATIC"
                     )
set_target_properties(wi4mpi_MPC_a
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_MPC -D_GNU_SOURCE -DWI4MPI_STATIC"
                     )
endif()

if(CMAKE_Fortran_COMPILER STREQUAL gfortran) 
set_target_properties(mpi_mod
                      PROPERTIES
                      COMPILE_FLAGS "-ffree-line-length-0"
                     )
endif()

#Link options
#------------

target_link_libraries(wi4mpi_OMPI ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(wi4mpi_INTEL ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(wi4mpi_MPICH ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(wi4mpi_MPC ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(wi4mpi_OMPI_a ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(wi4mpi_INTEL_a ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(wi4mpi_MPICH_a ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(wi4mpi_MPC_a ${CMAKE_THREAD_LIBS_INIT})

#Custom command
#--------------

message(status ${CMAKE_CURRENT_BINARY_DIR})
add_custom_command(TARGET wi4mpi_INTEL_a 
                    POST_BUILD
                   COMMAND  ${CMAKE_SOURCE_DIR}/scripts/rename_sym.sh libwi4mpi_INTEL_a.a "INTEL"
                   #WORKING_DIRECTORY ${CMAKE_BUILD_FILES_DIRECTORY}
                    )
add_custom_command(TARGET wi4mpi_MPICH_a 
                    POST_BUILD
                   COMMAND  ${CMAKE_SOURCE_DIR}/scripts/rename_sym.sh libwi4mpi_MPICH_a.a "MPICH"
                   #WORKING_DIRECTORY ${CMAKE_BUILD_FILES_DIRECTORY}
                    )
message(status ${CMAKE_CURRENT_BINARY_DIR})
add_custom_command(TARGET wi4mpi_OMPI_a 
                    POST_BUILD
                  COMMAND  ${CMAKE_SOURCE_DIR}/scripts/rename_sym.sh libwi4mpi_OMPI_a.a "OMPI"
                    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}

                )
message(status ${CMAKE_CURRENT_BINARY_DIR})
add_custom_command(TARGET wi4mpi_MPC_a 
                    POST_BUILD
                  COMMAND  ${CMAKE_SOURCE_DIR}/scripts/rename_sym.sh libwi4mpi_MPC_a.a "MPC"
                    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}

                )
message(status ${CMAKE_CURRENT_BINARY_DIR})
add_custom_command(TARGET mpi_a 
                POST_BUILD
                COMMAND ${CMAKE_SOURCE_DIR}/scripts/assemble_sym.sh libmpi.a libmpi_a.a libwi4mpi_INTEL_a.a libwi4mpi_MPICH_a.a libwi4mpi_OMPI_a.a libwi4mpi_MPC_a.a
                    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                )


#############
## PRELOAD ##
#############

#Preload Libraries
#-----------------

add_library(wi4mpi_INTEL_INTEL SHARED ${SOURCE_WI4MPI_PRELOAD})
add_library(wi4mpi_INTEL_OMPI SHARED ${SOURCE_WI4MPI_PRELOAD})
add_library(wi4mpi_INTEL_MPICH SHARED ${SOURCE_WI4MPI_PRELOAD})
add_library(wi4mpi_OMPI_OMPI SHARED ${SOURCE_WI4MPI_PRELOAD})
add_library(wi4mpi_OMPI_INTEL SHARED ${SOURCE_WI4MPI_PRELOAD})
add_library(wi4mpi_OMPI_MPICH SHARED ${SOURCE_WI4MPI_PRELOAD})
add_library(wi4mpi_MPICH_MPICH SHARED ${SOURCE_WI4MPI_PRELOAD})
add_library(wi4mpi_MPICH_OMPI SHARED ${SOURCE_WI4MPI_PRELOAD})
add_library(wi4mpi_MPICH_INTEL SHARED ${SOURCE_WI4MPI_PRELOAD})
#Empty libraries
set(LIST_FAKEINTEL mpi mpifort mpigf mpi_mt)
set(LIST_FAKEINTEL_MAJOR 4 5 12)
set(LIST_FAKEOMPI mpi mpi_mpifh mpi_usempif08 mpi_usempi_ignore_tkr)
set(LIST_FAKEOMPI_MAJOR 1 20 40)
set(LIST_FAKECXX mpicxx mpi_cxx)
set(LIST_FAKECXX_MAJOR ${LIST_FAKEINTEL_MAJOR} ${LIST_FAKEOMPI_MAJOR})
foreach(LIB ${LIST_FAKECXX})
    foreach(MAJOR ${LIST_FAKECXX_MAJOR})
        add_library(${LIB}${MAJOR} SHARED ${SOURCE_WI4MPI_EMPTY})
        set_target_properties(${LIB}${MAJOR} PROPERTIES OUTPUT_NAME ${LIB} SOVERSION ${MAJOR})
    endforeach(MAJOR)
endforeach(LIB)
foreach(LIB ${LIST_FAKEINTEL})
    foreach(MAJOR ${LIST_FAKEINTEL_MAJOR})
        add_library(${LIB}${MAJOR} SHARED ${SOURCE_WI4MPI_EMPTY})
        set_target_properties(${LIB}${MAJOR} PROPERTIES OUTPUT_NAME ${LIB} SOVERSION ${MAJOR})
    endforeach(MAJOR)
endforeach(LIB)
foreach(LIB ${LIST_FAKEOMPI})
    foreach(MAJOR ${LIST_FAKEOMPI_MAJOR})
        add_library(${LIB}${MAJOR} SHARED ${SOURCE_WI4MPI_EMPTY})
        set_target_properties(${LIB}${MAJOR} PROPERTIES OUTPUT_NAME ${LIB} SOVERSION ${MAJOR})
    endforeach(MAJOR)
endforeach(LIB)

#Headers
#-------

target_include_directories(wi4mpi_INTEL_INTEL
                           PRIVATE common
                           PRIVATE preload/header/INTEL_INTEL)
target_include_directories(wi4mpi_INTEL_MPICH
                           PRIVATE common
                           PRIVATE preload/header/INTEL_MPICH)
target_include_directories(wi4mpi_INTEL_OMPI
                           PRIVATE common
                           PRIVATE preload/header/INTEL_OMPI)
target_include_directories(wi4mpi_MPICH_INTEL
                           PRIVATE common
                           PRIVATE preload/header/MPICH_INTEL)
target_include_directories(wi4mpi_MPICH_MPICH
                           PRIVATE common
                           PRIVATE preload/header/MPICH_MPICH)
target_include_directories(wi4mpi_MPICH_OMPI
                           PRIVATE common
                           PRIVATE preload/header/MPICH_OMPI)
target_include_directories(wi4mpi_OMPI_OMPI
                           PRIVATE common
                           PRIVATE preload/header/OMPI_OMPI)
target_include_directories(wi4mpi_OMPI_INTEL
                           PRIVATE common
                           PRIVATE preload/header/OMPI_INTEL)
target_include_directories(wi4mpi_OMPI_MPICH
                           PRIVATE common
                           PRIVATE preload/header/OMPI_MPICH)

#Flags
#-----

if(CMAKE_C_COMPILER STREQUAL "icc")
set_target_properties(wi4mpi_INTEL_INTEL
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_GNU_SOURCE -DINTEL_INTEL"
)
set_target_properties(wi4mpi_INTEL_OMPI
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_GNU_SOURCE -DINTEL_OMPI "
)
set_target_properties(wi4mpi_INTEL_MPICH
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_GNU_SOURCE -DINTEL_INTEL "
)

set_target_properties(wi4mpi_MPICH_INTEL
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_GNU_SOURCE -DINTEL_INTEL"
)
set_target_properties(wi4mpi_MPICH_OMPI
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_GNU_SOURCE -DINTEL_OMPI "
)
set_target_properties(wi4mpi_MPICH_MPICH
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_GNU_SOURCE -DINTEL_INTEL "
)

set_target_properties(wi4mpi_OMPI_INTEL
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_GNU_SOURCE -DOMPI_INTEL"
)
set_target_properties(wi4mpi_OMPI_MPICH
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_GNU_SOURCE -DOMPI_INTEL"
)
set_target_properties(wi4mpi_OMPI_OMPI
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_GNU_SOURCE -DOMPI_OMPI"
)
endif()
if(CMAKE_C_COMPILER STREQUAL "gcc")
set_target_properties(wi4mpi_INTEL_INTEL
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_GNU_SOURCE -DINTEL_INTEL"
)
set_target_properties(wi4mpi_INTEL_OMPI
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_GNU_SOURCE -DINTEL_OMPI "
)
set_target_properties(wi4mpi_INTEL_MPICH
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_GNU_SOURCE -DINTEL_INTEL "
)

set_target_properties(wi4mpi_MPICH_INTEL
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_GNU_SOURCE -DINTEL_INTEL"
)
set_target_properties(wi4mpi_MPICH_OMPI
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_GNU_SOURCE -DINTEL_OMPI "
)
set_target_properties(wi4mpi_MPICH_MPICH
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_GNU_SOURCE -DINTEL_INTEL "
)

set_target_properties(wi4mpi_OMPI_INTEL
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_GNU_SOURCE -DOMPI_INTEL"
)
set_target_properties(wi4mpi_OMPI_MPICH
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_GNU_SOURCE -DOMPI_INTEL"
)
set_target_properties(wi4mpi_OMPI_OMPI
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_GNU_SOURCE -DOMPI_OMPI"
)
endif()
if(CMAKE_C_COMPILER STREQUAL "pgcc")
set_target_properties(wi4mpi_INTEL_INTEL
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -c99 -D_GNU_SOURCE -DINTEL_INTEL"
)
set_target_properties(wi4mpi_INTEL_OMPI
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -c99 -D_GNU_SOURCE -DINTEL_OMPI "
)
set_target_properties(wi4mpi_INTEL_MPICH
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -c99 -D_GNU_SOURCE -DINTEL_INTEL "
)

set_target_properties(wi4mpi_MPICH_INTEL
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -c99 -D_GNU_SOURCE -DINTEL_INTEL"
)
set_target_properties(wi4mpi_MPICH_OMPI
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -c99 -D_GNU_SOURCE -DINTEL_OMPI "
)
set_target_properties(wi4mpi_MPICH_MPICH
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -c99 -D_GNU_SOURCE -DINTEL_INTEL "
)

set_target_properties(wi4mpi_OMPI_INTEL
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -c99 -D_GNU_SOURCE -DOMPI_INTEL"
)
set_target_properties(wi4mpi_OMPI_MPICH
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -c99 -D_GNU_SOURCE -DOMPI_INTEL"
)
set_target_properties(wi4mpi_OMPI_OMPI
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -c99 -D_GNU_SOURCE -DOMPI_OMPI"
)
endif()
if(CMAKE_C_COMPILER MATCHES ".*clang")
set_target_properties(wi4mpi_INTEL_INTEL
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c11 -D_GNU_SOURCE -DINTEL_INTEL"
)
set_target_properties(wi4mpi_INTEL_OMPI
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c11 -D_GNU_SOURCE -DINTEL_OMPI "
)
set_target_properties(wi4mpi_INTEL_MPICH
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c11 -D_GNU_SOURCE -DINTEL_INTEL "
)

set_target_properties(wi4mpi_MPICH_INTEL
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c11 -D_GNU_SOURCE -DINTEL_INTEL"
)
set_target_properties(wi4mpi_MPICH_OMPI
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c11 -D_GNU_SOURCE -DINTEL_OMPI "
)
set_target_properties(wi4mpi_MPICH_MPICH
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c11 -D_GNU_SOURCE -DINTEL_INTEL "
)

set_target_properties(wi4mpi_OMPI_INTEL
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c11 -D_GNU_SOURCE -DOMPI_INTEL"
)
set_target_properties(wi4mpi_OMPI_MPICH
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c11 -D_GNU_SOURCE -DOMPI_INTEL"
)
set_target_properties(wi4mpi_OMPI_OMPI
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c11 -D_GNU_SOURCE -DOMPI_OMPI"
)
endif()
if(CMAKE_C_COMPILER STREQUAL "fcc")
set_target_properties(wi4mpi_INTEL_INTEL
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_GNU_SOURCE -DINTEL_INTEL"
)
set_target_properties(wi4mpi_INTEL_OMPI
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_GNU_SOURCE -DINTEL_OMPI "
)
set_target_properties(wi4mpi_INTEL_MPICH
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_GNU_SOURCE -DINTEL_INTEL "
)

set_target_properties(wi4mpi_MPICH_INTEL
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_GNU_SOURCE -DINTEL_INTEL"
)
set_target_properties(wi4mpi_MPICH_OMPI
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_GNU_SOURCE -DINTEL_OMPI "
)
set_target_properties(wi4mpi_MPICH_MPICH
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_GNU_SOURCE -DINTEL_INTEL "
)

set_target_properties(wi4mpi_OMPI_INTEL
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_GNU_SOURCE -DOMPI_INTEL"
)
set_target_properties(wi4mpi_OMPI_MPICH
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_GNU_SOURCE -DOMPI_INTEL"
)
set_target_properties(wi4mpi_OMPI_OMPI
                      PROPERTIES
                      COMPILE_FLAGS "${WI4MPI_FLAGS} ${WI4MPI_FORT_CALL} -std=c99 -D_GNU_SOURCE -DOMPI_OMPI"
)
endif()

foreach(LIB ${LIST_FAKECXX})
    foreach(MAJOR ${LIST_FAKECXX_MAJOR})
        set_target_properties(${LIB}${MAJOR} PROPERTIES COMPILE_FLAGS "-shared -fPIC")
    endforeach(MAJOR)
endforeach(LIB)
foreach(LIB ${LIST_FAKEINTEL})
    foreach(MAJOR ${LIST_FAKEINTEL_MAJOR})
        set_target_properties(${LIB}${MAJOR} PROPERTIES COMPILE_FLAGS "-shared -fPIC")
    endforeach(MAJOR)
endforeach(LIB)
foreach(LIB ${LIST_FAKEOMPI})
    foreach(MAJOR ${LIST_FAKEOMPI_MAJOR})
        set_target_properties(${LIB}${MAJOR} PROPERTIES COMPILE_FLAGS "-shared -fPIC")
    endforeach(MAJOR)
endforeach(LIB)

# Link options
#-------------

target_link_libraries(wi4mpi_INTEL_OMPI ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(wi4mpi_INTEL_INTEL ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(wi4mpi_INTEL_MPICH ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(wi4mpi_MPICH_OMPI ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(wi4mpi_MPICH_INTEL ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(wi4mpi_MPICH_MPICH ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(wi4mpi_OMPI_OMPI ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(wi4mpi_OMPI_INTEL ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(wi4mpi_OMPI_MPICH ${CMAKE_THREAD_LIBS_INIT})

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
    #_OMPI
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_O "${CMAKE_CURRENT_SOURCE_DIR}/interface/header/_OMPI/wrapper_f.h")
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_O "${CMAKE_CURRENT_SOURCE_DIR}/interface/header/_OMPI/app_mpi.h")
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_O "${CMAKE_CURRENT_SOURCE_DIR}/interface/header/_OMPI/run_mpi.h")
    #_INTEL
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_I "${CMAKE_CURRENT_SOURCE_DIR}/interface/header/_INTEL/wrapper_f.h")
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_I "${CMAKE_CURRENT_SOURCE_DIR}/interface/header/_INTEL/app_mpi.h")
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_I "${CMAKE_CURRENT_SOURCE_DIR}/interface/header/_INTEL/run_mpi.h")
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_I "${CMAKE_CURRENT_SOURCE_DIR}/interface/header/_INTEL/run_mpio.h")
    #_MPICH
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_II "${CMAKE_CURRENT_SOURCE_DIR}/interface/header/_MPICH/wrapper_f.h")
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_II "${CMAKE_CURRENT_SOURCE_DIR}/interface/header/_MPICH/app_mpi.h")
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_II "${CMAKE_CURRENT_SOURCE_DIR}/interface/header/_MPICH/run_mpi.h")
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_II "${CMAKE_CURRENT_SOURCE_DIR}/interface/header/_MPICH/run_mpio.h")
    #_MPC
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_M "${CMAKE_CURRENT_SOURCE_DIR}/interface/header/_MPC/wrapper_f.h")
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_M "${CMAKE_CURRENT_SOURCE_DIR}/interface/header/_MPC/app_mpi.h")
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_M "${CMAKE_CURRENT_SOURCE_DIR}/interface/header/_MPC/run_mpi.h")
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_M "${CMAKE_CURRENT_SOURCE_DIR}/interface/header/_MPC/run_mpio.h")
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_M "${CMAKE_CURRENT_SOURCE_DIR}/interface/header/_MPC/mpcmp.h")
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_M "${CMAKE_CURRENT_SOURCE_DIR}/interface/header/_MPC/sctk_types.h")
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_M "${CMAKE_CURRENT_SOURCE_DIR}/interface/header/_MPC/wrapper_f.h")

install(FILES ${LIST_INTERNAL_INTERFACE_HEADER_O_O} DESTINATION INTERNAL/interface/include/_OMPI)
install(FILES ${LIST_INTERNAL_INTERFACE_HEADER_O_I} DESTINATION INTERNAL/interface/include/_INTEL)
install(FILES ${LIST_INTERNAL_INTERFACE_HEADER_O_II} DESTINATION INTERNAL/interface/include/_MPICH)
install(FILES ${LIST_INTERNAL_INTERFACE_HEADER_O_M} DESTINATION INTERNAL/interface/include/_MPC)
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
    #OMPI_MPICH
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_O_II "${CMAKE_CURRENT_SOURCE_DIR}/preload/header/OMPI_MPICH/wrapper_f.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_O_II "${CMAKE_CURRENT_SOURCE_DIR}/preload/header/OMPI_MPICH/app_mpi.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_O_II "${CMAKE_CURRENT_SOURCE_DIR}/preload/header/OMPI_MPICH/run_mpi.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_O_II "${CMAKE_CURRENT_SOURCE_DIR}/preload/header/OMPI_MPICH/run_mpio.h")
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
    #INTEL_INTEL
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_I_II "${CMAKE_CURRENT_SOURCE_DIR}/preload/header/INTEL_INTEL/wrapper_f.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_I_II "${CMAKE_CURRENT_SOURCE_DIR}/preload/header/INTEL_INTEL/app_mpi.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_I_II "${CMAKE_CURRENT_SOURCE_DIR}/preload/header/INTEL_INTEL/app_mpio.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_I_II "${CMAKE_CURRENT_SOURCE_DIR}/preload/header/INTEL_INTEL/run_mpi.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_I_II "${CMAKE_CURRENT_SOURCE_DIR}/preload/header/INTEL_INTEL/run_mpio.h")
    #MPICH_INTEL
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_II_II "${CMAKE_CURRENT_SOURCE_DIR}/preload/header/MPICH_INTEL/wrapper_f.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_II_II "${CMAKE_CURRENT_SOURCE_DIR}/preload/header/MPICH_INTEL/app_mpi.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_II_II "${CMAKE_CURRENT_SOURCE_DIR}/preload/header/MPICH_INTEL/app_mpio.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_II_II "${CMAKE_CURRENT_SOURCE_DIR}/preload/header/MPICH_INTEL/run_mpi.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_II_II "${CMAKE_CURRENT_SOURCE_DIR}/preload/header/MPICH_INTEL/run_mpio.h")
    #MPICH_INTEL
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_II_I "${CMAKE_CURRENT_SOURCE_DIR}/preload/header/MPICH_INTEL/wrapper_f.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_II_I "${CMAKE_CURRENT_SOURCE_DIR}/preload/header/MPICH_INTEL/app_mpi.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_II_I "${CMAKE_CURRENT_SOURCE_DIR}/preload/header/MPICH_INTEL/app_mpio.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_II_I "${CMAKE_CURRENT_SOURCE_DIR}/preload/header/MPICH_INTEL/run_mpi.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_II_I "${CMAKE_CURRENT_SOURCE_DIR}/preload/header/MPICH_INTEL/run_mpio.h")
    #MPICH_OMPI
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_II_O "${CMAKE_CURRENT_SOURCE_DIR}/preload/header/MPICH_OMPI/wrapper_f.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_II_O "${CMAKE_CURRENT_SOURCE_DIR}/preload/header/MPICH_OMPI/app_mpi.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_II_O "${CMAKE_CURRENT_SOURCE_DIR}/preload/header/MPICH_OMPI/app_mpio.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_II_O "${CMAKE_CURRENT_SOURCE_DIR}/preload/header/MPICH_OMPI/run_mpi.h")
                
install(FILES ${LIST_INTERNAL_PRELOAD_HEADER_O_O} DESTINATION INTERNAL/preload/include/OMPI_OMPI) 
install(FILES ${LIST_INTERNAL_PRELOAD_HEADER_O_I} DESTINATION INTERNAL/preload/include/OMPI_INTEL) 
install(FILES ${LIST_INTERNAL_PRELOAD_HEADER_O_II} DESTINATION INTERNAL/preload/include/OMPI_MPICH) 
install(FILES ${LIST_INTERNAL_PRELOAD_HEADER_I_O} DESTINATION INTERNAL/preload/include/INTEL_OMPI) 
install(FILES ${LIST_INTERNAL_PRELOAD_HEADER_I_I} DESTINATION INTERNAL/preload/include/INTEL_INTEL) 
install(FILES ${LIST_INTERNAL_PRELOAD_HEADER_I_II} DESTINATION INTERNAL/preload/include/INTEL_MPICH) 
install(FILES ${LIST_INTERNAL_PRELOAD_HEADER_II_O} DESTINATION INTERNAL/preload/include/MPICH_OMPI) 
install(FILES ${LIST_INTERNAL_PRELOAD_HEADER_II_I} DESTINATION INTERNAL/preload/include/MPICH_INTEL) 
install(FILES ${LIST_INTERNAL_PRELOAD_HEADER_II_II} DESTINATION INTERNAL/preload/include/MPICH_MPICH) 

#Preload libraries
#-----------------
install(TARGETS 
        wi4mpi_INTEL_INTEL
        wi4mpi_INTEL_MPICH
        wi4mpi_INTEL_OMPI
        wi4mpi_MPICH_INTEL
        wi4mpi_MPICH_MPICH
        wi4mpi_MPICH_OMPI
        wi4mpi_OMPI_INTEL
        wi4mpi_OMPI_MPICH
        wi4mpi_OMPI_OMPI
        LIBRARY DESTINATION libexec/wi4mpi
                PERMISSIONS WORLD_READ WORLD_EXECUTE OWNER_READ OWNER_EXECUTE OWNER_WRITE GROUP_WRITE GROUP_READ GROUP_EXECUTE
)

foreach(LIB ${LIST_FAKECXX})
    foreach(MAJOR ${LIST_FAKECXX_MAJOR})
        install(FILES ${CMAKE_BINARY_DIR}/src/lib${LIB}.so.${MAJOR}
            DESTINATION libexec/wi4mpi/fakelibCXX
            RENAME lib${LIB}.so.${MAJOR}
            PERMISSIONS WORLD_READ WORLD_EXECUTE
                OWNER_READ OWNER_EXECUTE OWNER_WRITE
                GROUP_WRITE GROUP_READ GROUP_EXECUTE
        )
    endforeach(MAJOR)
endforeach(LIB)
foreach(LIB ${LIST_FAKEINTEL})
    foreach(MAJOR ${LIST_FAKEINTEL_MAJOR})
        install(FILES ${CMAKE_BINARY_DIR}/src/lib${LIB}.so.${MAJOR}
            DESTINATION libexec/wi4mpi/fakelibINTEL
            RENAME lib${LIB}.so.${MAJOR}
            PERMISSIONS WORLD_READ WORLD_EXECUTE
                OWNER_READ OWNER_EXECUTE OWNER_WRITE
                GROUP_WRITE GROUP_READ GROUP_EXECUTE
        )
    endforeach(MAJOR)
endforeach(LIB)
foreach(LIB ${LIST_FAKEINTEL})
    foreach(MAJOR ${LIST_FAKEINTEL_MAJOR})
        install(FILES ${CMAKE_BINARY_DIR}/src/lib${LIB}.so.${MAJOR}
            DESTINATION libexec/wi4mpi/fakelibMPICH
            RENAME lib${LIB}.so.${MAJOR}
            PERMISSIONS WORLD_READ WORLD_EXECUTE
                OWNER_READ OWNER_EXECUTE OWNER_WRITE
                GROUP_WRITE GROUP_READ GROUP_EXECUTE
        )
    endforeach(MAJOR)
endforeach(LIB)
foreach(LIB ${LIST_FAKEOMPI})
    foreach(MAJOR ${LIST_FAKEOMPI_MAJOR})
        install(FILES ${CMAKE_BINARY_DIR}/src/lib${LIB}.so.${MAJOR} DESTINATION libexec/wi4mpi/fakelibOMPI
            RENAME lib${LIB}.so.${MAJOR}
                PERMISSIONS WORLD_READ WORLD_EXECUTE OWNER_READ OWNER_EXECUTE OWNER_WRITE GROUP_WRITE GROUP_READ GROUP_EXECUTE
                )
        endforeach(MAJOR)
endforeach(LIB)

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
        LIBRARY DESTINATION lib_INTEL
                PERMISSIONS WORLD_READ WORLD_EXECUTE OWNER_READ OWNER_EXECUTE OWNER_WRITE GROUP_WRITE GROUP_READ GROUP_EXECUTE
)
install(TARGETS
        wi4mpi_MPICH
        LIBRARY DESTINATION lib_MPICH
                PERMISSIONS WORLD_READ WORLD_EXECUTE OWNER_READ OWNER_EXECUTE OWNER_WRITE GROUP_WRITE GROUP_READ GROUP_EXECUTE
)
install(TARGETS
        wi4mpi_MPC
        LIBRARY DESTINATION lib_MPC
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
        interface/interface_utils/bin/mpifort
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

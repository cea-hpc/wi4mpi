get_filename_component(C_COMPILER_NAME ${CMAKE_C_COMPILER} NAME)
get_filename_component(CXX_COMPILER_NAME ${CMAKE_CXX_COMPILER} NAME)
get_filename_component(FC_COMPILER_NAME ${CMAKE_Fortran_COMPILER} NAME)
message(STATUS "Project compiler C/C++ : ${C_COMPILER_NAME}/${CXX_COMPILER_NAME} && Fortran: ${FC_COMPILER_NAME}")

#Sources list
#------------
#libmpi.so (wi4mpi side)
file(GLOB SOURCE_WI4MPI_SO
     ${WI4MPI_GENDIR}/interface/gen/interface_c.c
     ${WI4MPI_GENDIR}/interface/gen/interface_fort.c
    )  
#libwi4mpi_*.so
file(GLOB_RECURSE SOURCE_WI4MPI_INTERFACE
    ${WI4MPI_GENDIR}/interface/gen/mpi_translation_c.c
    ${WI4MPI_GENDIR}/interface/gen/mpi_translation_fort.c
    interface/gen/c2f_f2c.c
    common/debug_printer.c
    common/override.c
    common/mpi_translation_c2f_f2c_init.c
    common/engine.c      
    common/engine_fn.c 
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
    ${WI4MPI_GENDIR}/preload/gen/mpi_translation_c.c
    ${WI4MPI_GENDIR}/preload/gen/mpi_translation_fort.c
    preload/gen/c2f_f2c.c
    common/override.c
    common/debug_printer.c
    common/mpi_translation_c2f_f2c_init.c
    common/engine.c
    common/engine_fn.c
    common/asm_jit.c
)

if(WI4MPI_TIMEOUT)
    list(APPEND SOURCE_WI4MPI_INTERFACE "common/helper.c")
    list(APPEND SOURCE_WI4MPI_PRELOAD "common/helper.c")
endif()

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
                                                     PRIVATE ${WI4MPI_GENDIR}/interface/header/_OMPI)
target_include_directories(wi4mpi_profiling_INTEL
                                                     PRIVATE common
                                                     PRIVATE ${WI4MPI_GENDIR}/interface/header/_INTEL)
target_include_directories(wi4mpi_profiling_MPICH
                                                     PRIVATE common
                                                     PRIVATE ${WI4MPI_GENDIR}/interface/header/_MPICH)
target_include_directories(wi4mpi_profiling_MPC
                                                     PRIVATE common
                                                     PRIVATE
                                                     ${WI4MPI_GENDIR}/interface/header/_MPC)



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
                           PRIVATE ${WI4MPI_GENDIR}/interface/header/_OMPI
                           PRIVATE interface/gen
                          )
target_include_directories(wi4mpi_INTEL
                           PRIVATE common
                           PRIVATE ${WI4MPI_GENDIR}/interface/header/_INTEL
                           PRIVATE interface/gen
                          )
target_include_directories(wi4mpi_MPICH
                           PRIVATE common
                           PRIVATE ${WI4MPI_GENDIR}/interface/header/_MPICH
                           PRIVATE interface/gen
                          )
target_include_directories(wi4mpi_MPC
                           PRIVATE common
                           PRIVATE ${WI4MPI_GENDIR}/interface/header/_MPC
                           PRIVATE interface/gen
                          )

target_include_directories(mpi_a PRIVATE interface/manual)
target_include_directories(wi4mpi_OMPI_a
                           PRIVATE common
                           PRIVATE ${WI4MPI_GENDIR}/interface/header/_OMPI
                           PRIVATE interface/gen
                          )
target_include_directories(wi4mpi_INTEL_a
                           PRIVATE common
                           PRIVATE ${WI4MPI_GENDIR}/interface/header/_INTEL
                           PRIVATE interface/gen
                          )
target_include_directories(wi4mpi_MPICH_a
                           PRIVATE common
                           PRIVATE ${WI4MPI_GENDIR}/interface/header/_MPICH
                           PRIVATE interface/gen
                          )
target_include_directories(wi4mpi_MPC_a
                           PRIVATE common
                           PRIVATE ${WI4MPI_GENDIR}/interface/header/_MPC
                           PRIVATE interface/gen
                          )

#Flags
#-----

target_compile_definitions(wi4mpi_OMPI PRIVATE _OMPI __MPI__COMPILE__)
target_compile_definitions(wi4mpi_INTEL PRIVATE _INTEL)
target_compile_definitions(wi4mpi_MPICH PRIVATE _INTEL)
target_compile_definitions(wi4mpi_MPC PRIVATE _MPC)

target_compile_definitions(mpi_a PRIVATE WI4MPI_STATIC)
target_compile_definitions(wi4mpi_OMPI_a PRIVATE _OMPI __MPI__COMPILE__ WI4MPI_STATIC)
target_compile_definitions(wi4mpi_INTEL_a PRIVATE _INTEL WI4MPI_STATIC)
target_compile_definitions(wi4mpi_MPICH_a PRIVATE _INTEL WI4MPI_STATIC)
target_compile_definitions(wi4mpi_MPC_a PRIVATE _MPC WI4MPI_STATIC)

if(CMAKE_Fortran_COMPILER_ID STREQUAL "GNU") 
set_target_properties(mpi_mod
                      PROPERTIES
                      COMPILE_FLAGS "-ffree-line-length-0"
                     )
endif()

#Link options
#------------

foreach(lib wi4mpi_OMPI wi4mpi_INTEL wi4mpi_MPICH wi4mpi_MPC wi4mpi_OMPI_a wi4mpi_INTEL_a wi4mpi_MPICH_a wi4mpi_MPC_a)
    target_link_libraries(${lib} Threads::Threads)
    target_link_libraries(${lib} dl)
endforeach()

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
set(LIST_FAKEINTEL mpi mpifort mpigf mpi_mt fmpich mpichcxx mpichf90 mpich)
set(LIST_FAKEINTEL_MAJOR 4 5 12)
set(LIST_FAKEOMPI mpi mpi_mpifh mpi_usempif08 mpi_usempi_ignore_tkr libopen-rte libopen-pal)
set(LIST_FAKEOMPI_MAJOR 1 20 40 80)
set(LIST_FAKECXX mpicxx mpi_cxx)
set(LIST_FAKECXX_MAJOR ${LIST_FAKEINTEL_MAJOR} ${LIST_FAKEOMPI_MAJOR})
foreach(LIB ${LIST_FAKECXX})
    foreach(MAJOR ${LIST_FAKECXX_MAJOR})
        add_library(${LIB}${MAJOR} SHARED ${SOURCE_WI4MPI_EMPTY})
        set_target_properties(${LIB}${MAJOR} PROPERTIES
            LIBRARY_OUTPUT_NAME ${LIB}
            LIBRARY_OUTPUT_DIRECTORY MAJOR_${MAJOR}
            SOVERSION ${MAJOR})
    endforeach(MAJOR)
endforeach(LIB)
foreach(LIB ${LIST_FAKEINTEL})
    foreach(MAJOR ${LIST_FAKEINTEL_MAJOR})
        add_library(${LIB}${MAJOR} SHARED ${SOURCE_WI4MPI_EMPTY})
        set_target_properties(${LIB}${MAJOR} PROPERTIES
            LIBRARY_OUTPUT_NAME ${LIB}
            LIBRARY_OUTPUT_DIRECTORY MAJOR_${MAJOR}
            SOVERSION ${MAJOR})
    endforeach(MAJOR)
endforeach(LIB)
foreach(LIB ${LIST_FAKEOMPI})
    foreach(MAJOR ${LIST_FAKEOMPI_MAJOR})
        add_library(${LIB}${MAJOR} SHARED ${SOURCE_WI4MPI_EMPTY})
        set_target_properties(${LIB}${MAJOR} PROPERTIES
            LIBRARY_OUTPUT_NAME ${LIB}
            LIBRARY_OUTPUT_DIRECTORY MAJOR_${MAJOR}
            SOVERSION ${MAJOR})
    endforeach(MAJOR)
endforeach(LIB)

#Headers
#-------

target_include_directories(wi4mpi_INTEL_INTEL
                           PRIVATE common
                           PRIVATE ${WI4MPI_GENDIR}/preload/header/INTEL_INTEL)
target_include_directories(wi4mpi_INTEL_MPICH
                           PRIVATE common
                           PRIVATE ${WI4MPI_GENDIR}/preload/header/INTEL_MPICH)
target_include_directories(wi4mpi_INTEL_OMPI
                           PRIVATE common
                           PRIVATE ${WI4MPI_GENDIR}/preload/header/INTEL_OMPI)
target_include_directories(wi4mpi_MPICH_INTEL
                           PRIVATE common
                           PRIVATE ${WI4MPI_GENDIR}/preload/header/MPICH_INTEL)
target_include_directories(wi4mpi_MPICH_MPICH
                           PRIVATE common
                           PRIVATE ${WI4MPI_GENDIR}/preload/header/MPICH_MPICH)
target_include_directories(wi4mpi_MPICH_OMPI
                           PRIVATE common
                           PRIVATE ${WI4MPI_GENDIR}/preload/header/MPICH_OMPI)
target_include_directories(wi4mpi_OMPI_OMPI
                           PRIVATE common
                           PRIVATE ${WI4MPI_GENDIR}/preload/header/OMPI_OMPI)
target_include_directories(wi4mpi_OMPI_INTEL
                           PRIVATE common
                           PRIVATE ${WI4MPI_GENDIR}/preload/header/OMPI_INTEL)
target_include_directories(wi4mpi_OMPI_MPICH
                           PRIVATE common
                           PRIVATE ${WI4MPI_GENDIR}/preload/header/OMPI_MPICH)

#Flags
#-----

target_compile_definitions(wi4mpi_INTEL_INTEL PRIVATE INTEL_INTEL)
target_compile_definitions(wi4mpi_INTEL_OMPI PRIVATE INTEL_OMPI)
target_compile_definitions(wi4mpi_INTEL_MPICH PRIVATE INTEL_INTEL)

target_compile_definitions(wi4mpi_MPICH_INTEL PRIVATE INTEL_INTEL)
target_compile_definitions(wi4mpi_MPICH_OMPI PRIVATE INTEL_OMPI)
target_compile_definitions(wi4mpi_MPICH_MPICH PRIVATE INTEL_INTEL)

target_compile_definitions(wi4mpi_OMPI_INTEL PRIVATE OMPI_INTEL)
target_compile_definitions(wi4mpi_OMPI_MPICH PRIVATE OMPI_INTEL)
target_compile_definitions(wi4mpi_OMPI_OMPI PRIVATE OMPI_OMPI)

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

foreach(lib wi4mpi_INTEL_OMPI wi4mpi_INTEL_INTEL wi4mpi_INTEL_MPICH wi4mpi_MPICH_OMPI wi4mpi_MPICH_INTEL wi4mpi_MPICH_MPICH wi4mpi_OMPI_OMPI wi4mpi_OMPI_INTEL wi4mpi_OMPI_MPICH)
    target_link_libraries(${lib} Threads::Threads)
endforeach()

# Installation specs
#-------------------

# Listing headers to be installed
#COMMON
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
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_O "${WI4MPI_GENDIR}/interface/header/_OMPI/wrapper_f.h")
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_O "${WI4MPI_GENDIR}/interface/header/_OMPI/app_mpi.h")
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_O "${WI4MPI_GENDIR}/interface/header/_OMPI/run_mpi.h")
    #_INTEL
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_I "${WI4MPI_GENDIR}/interface/header/_INTEL/wrapper_f.h")
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_I "${WI4MPI_GENDIR}/interface/header/_INTEL/app_mpi.h")
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_I "${WI4MPI_GENDIR}/interface/header/_INTEL/run_mpi.h")
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_I "${WI4MPI_GENDIR}/interface/header/_INTEL/run_mpio.h")
    #_MPICH
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_II "${WI4MPI_GENDIR}/interface/header/_MPICH/wrapper_f.h")
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_II "${WI4MPI_GENDIR}/interface/header/_MPICH/app_mpi.h")
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_II "${WI4MPI_GENDIR}/interface/header/_MPICH/run_mpi.h")
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_II "${WI4MPI_GENDIR}/interface/header/_MPICH/run_mpio.h")
    #_MPC
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_M "${WI4MPI_GENDIR}/interface/header/_MPC/wrapper_f.h")
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_M "${WI4MPI_GENDIR}/interface/header/_MPC/app_mpi.h")
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_M "${WI4MPI_GENDIR}/interface/header/_MPC/run_mpi.h")
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_M "${WI4MPI_GENDIR}/interface/header/_MPC/run_mpio.h")
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_M "${WI4MPI_GENDIR}/interface/header/_MPC/mpcmp.h")
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_M "${WI4MPI_GENDIR}/interface/header/_MPC/sctk_types.h")
list(APPEND LIST_INTERNAL_INTERFACE_HEADER_O_M "${WI4MPI_GENDIR}/interface/header/_MPC/wrapper_f.h")

install(FILES ${LIST_INTERNAL_INTERFACE_HEADER_O_O} DESTINATION INTERNAL/interface/include/_OMPI)
install(FILES ${LIST_INTERNAL_INTERFACE_HEADER_O_I} DESTINATION INTERNAL/interface/include/_INTEL)
install(FILES ${LIST_INTERNAL_INTERFACE_HEADER_O_II} DESTINATION INTERNAL/interface/include/_MPICH)
install(FILES ${LIST_INTERNAL_INTERFACE_HEADER_O_M} DESTINATION INTERNAL/interface/include/_MPC)
#PRELOAD
    #OMPI_OMPI
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_O_O "${WI4MPI_GENDIR}/preload/header/OMPI_OMPI/wrapper_f.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_O_O "${WI4MPI_GENDIR}/preload/header/OMPI_OMPI/app_mpi.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_O_O "${WI4MPI_GENDIR}/preload/header/OMPI_OMPI/run_mpi.h")
    #OMPI_INTEL
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_O_I "${WI4MPI_GENDIR}/preload/header/OMPI_INTEL/wrapper_f.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_O_I "${WI4MPI_GENDIR}/preload/header/OMPI_INTEL/app_mpi.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_O_I "${WI4MPI_GENDIR}/preload/header/OMPI_INTEL/run_mpi.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_O_I "${WI4MPI_GENDIR}/preload/header/OMPI_INTEL/run_mpio.h")
    #OMPI_MPICH
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_O_II "${WI4MPI_GENDIR}/preload/header/OMPI_MPICH/wrapper_f.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_O_II "${WI4MPI_GENDIR}/preload/header/OMPI_MPICH/app_mpi.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_O_II "${WI4MPI_GENDIR}/preload/header/OMPI_MPICH/run_mpi.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_O_II "${WI4MPI_GENDIR}/preload/header/OMPI_MPICH/run_mpio.h")
    #INTEL_OMPI
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_I_O "${WI4MPI_GENDIR}/preload/header/INTEL_OMPI/wrapper_f.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_I_O "${WI4MPI_GENDIR}/preload/header/INTEL_OMPI/app_mpi.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_I_O "${WI4MPI_GENDIR}/preload/header/INTEL_OMPI/app_mpio.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_I_O "${WI4MPI_GENDIR}/preload/header/INTEL_OMPI/run_mpi.h")
    #INTEL_INTEL
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_I_I "${WI4MPI_GENDIR}/preload/header/INTEL_INTEL/wrapper_f.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_I_I "${WI4MPI_GENDIR}/preload/header/INTEL_INTEL/app_mpi.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_I_I "${WI4MPI_GENDIR}/preload/header/INTEL_INTEL/app_mpio.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_I_I "${WI4MPI_GENDIR}/preload/header/INTEL_INTEL/run_mpi.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_I_I "${WI4MPI_GENDIR}/preload/header/INTEL_INTEL/run_mpio.h")
    #INTEL_INTEL
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_I_II "${WI4MPI_GENDIR}/preload/header/INTEL_INTEL/wrapper_f.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_I_II "${WI4MPI_GENDIR}/preload/header/INTEL_INTEL/app_mpi.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_I_II "${WI4MPI_GENDIR}/preload/header/INTEL_INTEL/app_mpio.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_I_II "${WI4MPI_GENDIR}/preload/header/INTEL_INTEL/run_mpi.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_I_II "${WI4MPI_GENDIR}/preload/header/INTEL_INTEL/run_mpio.h")
    #MPICH_INTEL
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_II_II "${WI4MPI_GENDIR}/preload/header/MPICH_INTEL/wrapper_f.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_II_II "${WI4MPI_GENDIR}/preload/header/MPICH_INTEL/app_mpi.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_II_II "${WI4MPI_GENDIR}/preload/header/MPICH_INTEL/app_mpio.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_II_II "${WI4MPI_GENDIR}/preload/header/MPICH_INTEL/run_mpi.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_II_II "${WI4MPI_GENDIR}/preload/header/MPICH_INTEL/run_mpio.h")
    #MPICH_INTEL
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_II_I "${WI4MPI_GENDIR}/preload/header/MPICH_INTEL/wrapper_f.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_II_I "${WI4MPI_GENDIR}/preload/header/MPICH_INTEL/app_mpi.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_II_I "${WI4MPI_GENDIR}/preload/header/MPICH_INTEL/app_mpio.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_II_I "${WI4MPI_GENDIR}/preload/header/MPICH_INTEL/run_mpi.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_II_I "${WI4MPI_GENDIR}/preload/header/MPICH_INTEL/run_mpio.h")
    #MPICH_OMPI
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_II_O "${WI4MPI_GENDIR}/preload/header/MPICH_OMPI/wrapper_f.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_II_O "${WI4MPI_GENDIR}/preload/header/MPICH_OMPI/app_mpi.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_II_O "${WI4MPI_GENDIR}/preload/header/MPICH_OMPI/app_mpio.h")
list(APPEND LIST_INTERNAL_PRELOAD_HEADER_II_O "${WI4MPI_GENDIR}/preload/header/MPICH_OMPI/run_mpi.h")
                
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
        install(FILES ${CMAKE_BINARY_DIR}/src/MAJOR_${MAJOR}/lib${LIB}.so.${MAJOR}
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
        install(FILES ${CMAKE_BINARY_DIR}/src/MAJOR_${MAJOR}/lib${LIB}.so.${MAJOR}
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
        install(FILES ${CMAKE_BINARY_DIR}/src/MAJOR_${MAJOR}/lib${LIB}.so.${MAJOR}
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
        install(FILES ${CMAKE_BINARY_DIR}/src/MAJOR_${MAJOR}/lib${LIB}.so.${MAJOR}
            DESTINATION libexec/wi4mpi/fakelibOMPI
            RENAME lib${LIB}.so.${MAJOR}
            PERMISSIONS WORLD_READ WORLD_EXECUTE
                OWNER_READ OWNER_EXECUTE OWNER_WRITE
                GROUP_WRITE GROUP_READ GROUP_EXECUTE
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
        resources/bin/mpicc
        resources/bin/mpicxx
        resources/bin/mpic++
        resources/bin/mpifort
        resources/bin/mpif77
        resources/bin/mpif90
        resources/bin/mpiexec
        resources/bin/mpirun DESTINATION bin
        PERMISSIONS WORLD_READ WORLD_EXECUTE OWNER_READ OWNER_EXECUTE OWNER_WRITE GROUP_WRITE GROUP_READ GROUP_EXECUTE
)

install(FILES
        resources/bin/wi4mpi DESTINATION bin
        PERMISSIONS WORLD_READ WORLD_EXECUTE OWNER_READ OWNER_EXECUTE OWNER_WRITE GROUP_WRITE GROUP_READ GROUP_EXECUTE
)
if(NOT BASHPATH STREQUAL "/bin/bash")
    # Ugly work-around bash install path on FreeBSD
    install(CODE "execute_process(COMMAND sed -i \"\" s+/bin/bash+${BASHPATH}+ wi4mpi mpicc mpirun WORKING_DIRECTORY ${CMAKE_INSTALL_PREFIX}/bin)")
endif()

#Wi4mpi config
#-------------

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/resources/etc/wi4mpi.cfg.in ${CMAKE_CURRENT_BINARY_DIR}/wi4mpi.cfg)
install(FILES
                ${CMAKE_CURRENT_BINARY_DIR}/wi4mpi.cfg DESTINATION etc
                PERMISSIONS WORLD_READ WORLD_EXECUTE OWNER_READ OWNER_EXECUTE OWNER_WRITE GROUP_WRITE GROUP_READ GROUP_EXECUTE
)

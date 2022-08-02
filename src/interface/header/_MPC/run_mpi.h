/* ############################# MPC License ############################## */
/* # Wed Nov 19 15:19:19 CET 2008                                         # */
/* # Copyright or (C) or Copr. Commissariat a l'Energie Atomique          # */
/* #                                                                      # */
/* # IDDN.FR.001.230040.000.S.P.2007.000.10000                            # */
/* # This file is part of the MPC Runtime.                                # */
/* #                                                                      # */
/* # This software is governed by the CeCILL-C license under French law   # */
/* # and abiding by the rules of distribution of free software.  You can  # */
/* # use, modify and/ or redistribute the software under the terms of     # */
/* # the CeCILL-C license as circulated by CEA, CNRS and INRIA at the     # */
/* # following URL http://www.cecill.info.                                # */
/* #                                                                      # */
/* # The fact that you are presently reading this means that you have     # */
/* # had knowledge of the CeCILL-C license and that you accept its        # */
/* # terms.                                                               # */
/* #                                                                      # */
/* # Authors:                                                             # */
/* #   - PERACHE Marc marc.perache@cea.fr                                 # */
/* #   - JAEGER Julien julien.jaeger@cea.fr                               # */
/* #   - BESNARD Jean-Baptiste jbbesnard@paratools.fr                     # */
/* #                                                                      # */
/* ######################################################################## */
#ifndef __SCTK_MPC_MPI_H_
#define __SCTK_MPC_MPI_H_

#include <stdlib.h>
#include <string.h>
#include <mpcmp.h>


#ifndef MPC_NO_AUTO_MAIN_REDEF
	#undef main
	#ifdef __cplusplus
		#define main long mpc_user_main_dummy__ (); extern "C" int mpc_user_main__
	#else
		#define main mpc_user_main__
	#endif
#endif



#ifdef __cplusplus
extern "C"
{
#endif

#define R_MPI_VERSION    3
#define R_MPI_SUBVERSION    1

#define R_MPI_CART (-2)
#define R_MPI_GRAPH (-3)
#define R_MPI_DIST_GRAPH (-4)

/* Results of the compare operations. */
#define R_MPI_IDENT     0
#define R_MPI_CONGRUENT 1
#define R_MPI_SIMILAR   2
#define R_MPI_UNEQUAL   3

#define R_MPI_LOCK_EXCLUSIVE  234
#define R_MPI_LOCK_SHARED     235

/* Other constants */
#define R_MPI_UNWEIGHTED ((void *) 2)
#define R_MPI_WEIGHTS_EMPTY ((void *) 3)

/************************************************************************/
/* R_MPI_* to MPC_* converters                                            */
/************************************************************************/

/* Misc */
#define R_MPI_MAX_PROCESSOR_NAME MPC_MAX_PROCESSOR_NAME
#define R_MPI_MAX_NAME_STRING MPC_MAX_OBJECT_NAME
#define R_MPI_MAX_OBJECT_NAME MPC_MAX_OBJECT_NAME
#define R_MPI_MAX_LIBRARY_VERSION_STRING MPC_MAX_LIBRARY_VERSION_STRING
/* Communication Parameters */
#define R_MPI_SOURCE MPC_SOURCE
#define R_MPI_TAG MPC_TAG
#define R_MPI_UNDEFINED MPC_UNDEFINED
#define R_MPI_REQUEST_NULL ((R_MPI_Request)-1)
#define R_MPI_COMM_WORLD MPC_COMM_WORLD
#define R_MPI_STATUS_IGNORE MPC_STATUS_IGNORE
#define R_MPI_STATUSES_IGNORE MPC_STATUSES_IGNORE
#define R_MPI_ANY_TAG MPC_ANY_TAG
#define R_MPI_ANY_SOURCE MPC_ANY_SOURCE
#define R_MPI_PROC_NULL MPC_PROC_NULL
#define R_MPI_COMM_NULL MPC_COMM_NULL
#define R_MPI_ROOT MPC_ROOT
#define R_MPI_IN_PLACE MPC_IN_PLACE
#define R_MPI_BOTTOM MPC_BOTTOM
#define R_MPI_COMM_SELF MPC_COMM_SELF

/* Error Handling */
#define R_MPI_SUCCESS MPC_SUCCESS
#define R_MPI_ERROR MPC_ERROR
#define R_MPI_MAX_ERROR_STRING MPC_MAX_ERROR_STRING
#define R_MPI_ERR_BUFFER MPC_ERR_BUFFER
#define R_MPI_ERR_COUNT MPC_ERR_COUNT
#define R_MPI_ERR_TYPE MPC_ERR_TYPE
#define R_MPI_ERR_TAG MPC_ERR_TAG
#define R_MPI_ERR_COMM MPC_ERR_COMM
#define R_MPI_ERR_RANK MPC_ERR_RANK
#define R_MPI_ERR_REQUEST MPC_ERR_REQUEST
#define R_MPI_ERR_ROOT MPC_ERR_ROOT
#define R_MPI_ERR_GROUP MPC_ERR_GROUP
#define R_MPI_ERR_OP MPC_ERR_OP
#define R_MPI_ERR_TOPOLOGY MPC_ERR_TOPOLOGY
#define R_MPI_ERR_DIMS MPC_ERR_DIMS
#define R_MPI_ERR_ARG MPC_ERR_ARG
#define R_MPI_ERR_UNKNOWN MPC_ERR_UNKNOWN
#define R_MPI_ERR_TRUNCATE MPC_ERR_TRUNCATE
#define R_MPI_ERR_OTHER MPC_ERR_OTHER
#define R_MPI_ERR_INTERN MPC_ERR_INTERN
#define R_MPI_ERR_IN_STATUS MPC_ERR_IN_STATUS
#define R_MPI_ERR_PENDING MPC_ERR_PENDING
#define R_MPI_ERR_KEYVAL MPC_ERR_KEYVAL
#define R_MPI_ERR_NO_MEM MPC_ERR_NO_MEM
#define R_MPI_ERR_BASE MPC_ERR_BASE
#define R_MPI_ERR_INFO_KEY MPC_ERR_INFO_KEY
#define R_MPI_ERR_INFO_VALUE MPC_ERR_INFO_VALUE
#define R_MPI_ERR_INFO_NOKEY MPC_ERR_INFO_NOKEY
#define R_MPI_ERR_SPAWN MPC_ERR_SPAWN
#define R_MPI_ERR_PORT MPC_ERR_PORT
#define R_MPI_ERR_SERVICE MPC_ERR_SERVICE
#define R_MPI_ERR_NAME MPC_ERR_NAME
#define R_MPI_ERR_WIN MPC_ERR_WIN
#define R_MPI_ERR_SIZE MPC_ERR_SIZE
#define R_MPI_ERR_DISP MPC_ERR_DISP
#define R_MPI_ERR_INFO MPC_ERR_INFO
#define R_MPI_ERR_LOCKTYPE MPC_ERR_LOCKTYPE
#define R_MPI_ERR_ASSERT MPC_ERR_ASSERT
#define R_MPI_ERR_RMA_RANGE 74
#define R_MPI_ERR_RMA_ATTACH 75
#define R_MPI_ERR_RMA_SHARED 76
#define R_MPI_ERR_RMA_CONFLICT MPC_ERR_RMA_CONFLICT
#define R_MPI_ERR_RMA_SYNC MPC_ERR_RMA_SYNC
#define R_MPI_ERR_RMA_FLAVOR MPC_ERR_RMA_FLAVOR
#define R_MPI_ERR_FILE MPC_ERR_FILE
#define R_MPI_ERR_NOT_SAME MPC_ERR_NOT_SAME
#define R_MPI_ERR_AMODE MPC_ERR_AMODE
#define R_MPI_ERR_UNSUPPORTED_DATAREP MPC_ERR_UNSUPPORTED_DATAREP
#define R_MPI_ERR_UNSUPPORTED_OPERATION MPC_ERR_UNSUPPORTED_OPERATION
#define R_MPI_ERR_NO_SUCH_FILE MPC_ERR_NO_SUCH_FILE
#define R_MPI_ERR_FILE_EXISTS MPC_ERR_FILE_EXISTS
#define R_MPI_ERR_BAD_FILE MPC_ERR_BAD_FILE
#define R_MPI_ERR_ACCESS MPC_ERR_ACCESS
#define R_MPI_ERR_NO_SPACE MPC_ERR_NO_SPACE
#define R_MPI_ERR_QUOTA MPC_ERR_QUOTA
#define R_MPI_ERR_READ_ONLY MPC_ERR_READ_ONLY
#define R_MPI_ERR_FILE_IN_USE MPC_ERR_FILE_IN_USE
#define R_MPI_ERR_DUP_DATAREP MPC_ERR_DUP_DATAREP
#define R_MPI_ERR_CONVERSION MPC_ERR_CONVERSION
#define R_MPI_ERR_IO MPC_ERR_IO
#define R_MPI_ERR_LASTCODE MPC_ERR_LASTCODE
#define R_MPI_NOT_IMPLEMENTED MPC_NOT_IMPLEMENTED
#define MPIR_ERRORS_THROW_EXCEPTIONS MPCR_ERRORS_THROW_EXCEPTIONS
/* R_MPI_T Errors */
#define R_MPI_T_ERR_MEMORY MPC_T_ERR_MEMORY
#define R_MPI_T_ERR_NOT_INITIALIZED MPC_T_ERR_NOT_INITIALIZED
#define R_MPI_T_ERR_CANNOT_INIT MPC_T_ERR_CANNOT_INIT
#define R_MPI_T_ERR_INVALID_INDEX MPC_T_ERR_INVALID_INDEX
#define R_MPI_T_ERR_INVALID_ITEM MPC_T_ERR_INVALID_ITEM
#define R_MPI_T_ERR_INVALID_HANDLE MPC_T_ERR_INVALID_HANDLE
#define R_MPI_T_ERR_OUT_OF_HANDLES MPC_T_ERR_OUT_OF_HANDLES
#define R_MPI_T_ERR_OUT_OF_SESSIONS MPC_T_ERR_OUT_OF_SESSIONS
#define R_MPI_T_ERR_INVALID_SESSION MPC_T_ERR_INVALID_SESSION
#define R_MPI_T_ERR_CVAR_SET_NOT_NOW MPC_T_ERR_CVAR_SET_NOT_NOW
#define R_MPI_T_ERR_CVAR_SET_NEVER MPC_T_ERR_CVAR_SET_NEVER
#define R_MPI_T_ERR_PVAR_NO_STARTSTOP MPC_T_ERR_PVAR_NO_STARTSTOP
#define R_MPI_T_ERR_PVAR_NO_WRITE MPC_T_ERR_PVAR_NO_WRITE
#define R_MPI_T_ERR_PVAR_NO_ATOMIC MPC_T_ERR_PVAR_NO_ATOMIC
#define R_MPI_T_ERR_INVALID_NAME MPC_T_ERR_INVALID_NAME

/* Data-type Handling */
#define R_MPI_DATATYPE_NULL MPC_DATATYPE_NULL
#define R_MPI_UB MPC_UB
#define R_MPI_LB MPC_LB
#define R_MPI_CHAR MPC_CHAR
#define R_MPI_BYTE MPC_BYTE
#define R_MPI_SHORT MPC_SHORT
#define R_MPI_INT MPC_INT

/* Support for R_MPI_INTEGER */
#define R_MPI_INTEGER MPC_INTEGER
#ifndef NOHAVE_ASSERT_H
#define R_MPI_INTEGER1 MPC_INTEGER1
#define R_MPI_INTEGER2 MPC_INTEGER2
#define R_MPI_INTEGER4 MPC_INTEGER4
#define R_MPI_INTEGER8 MPC_INTEGER8
#endif

/* Basic data-types */
#define R_MPI_LONG MPC_LONG
#define R_MPI_LONG_INT MPC_LONG_INT
#define R_MPI_FLOAT MPC_FLOAT
#define R_MPI_DOUBLE MPC_DOUBLE
#define R_MPI_UNSIGNED_CHAR MPC_UNSIGNED_CHAR
#define R_MPI_UNSIGNED_SHORT MPC_UNSIGNED_SHORT
#define R_MPI_UNSIGNED MPC_UNSIGNED
#define R_MPI_UNSIGNED_LONG MPC_UNSIGNED_LONG
#define R_MPI_LONG_DOUBLE MPC_LONG_DOUBLE
#define R_MPI_LONG_LONG_INT MPC_LONG_LONG_INT
#define R_MPI_LONG_LONG MPC_LONG_LONG
#define R_MPI_UNSIGNED_LONG_LONG_INT MPC_UNSIGNED_LONG_LONG_INT
#define R_MPI_UNSIGNED_LONG_LONG MPC_UNSIGNED_LONG_LONG
#define R_MPI_PACKED MPC_PACKED
#define R_MPI_FLOAT_INT MPC_FLOAT_INT
#define R_MPI_DOUBLE_INT MPC_DOUBLE_INT
#define R_MPI_LONG_DOUBLE_INT MPC_LONG_DOUBLE_INT
#define R_MPI_SHORT_INT MPC_SHORT_INT
#define R_MPI_2INT MPC_2INT
#define R_MPI_2FLOAT MPC_2FLOAT
#define R_MPI_COMPLEX MPC_COMPLEX
#define R_MPI_DOUBLE_COMPLEX MPC_DOUBLE_COMPLEX
#define R_MPI_2DOUBLE_PRECISION MPC_2DOUBLE_PRECISION
#define R_MPI_LOGICAL MPC_LOGICAL
#define R_MPI_REAL4 MPC_REAL4
#define R_MPI_REAL8 MPC_REAL8
#define R_MPI_REAL16 MPC_REAL16
#define R_MPI_SIGNED_CHAR MPC_SIGNED_CHAR
#define R_MPI_LONG_DOUBLE_INT MPC_LONG_DOUBLE_INT
#define R_MPI_REAL MPC_REAL
#define R_MPI_INT8_T MPC_INT8_T
#define R_MPI_UINT8_T MPC_UINT8_T
#define R_MPI_INT16_T MPC_INT16_T
#define R_MPI_UINT16_T MPC_UINT16_T
#define R_MPI_INT32_T MPC_INT32_T
#define R_MPI_UINT32_T MPC_UINT32_T
#define R_MPI_INT64_T MPC_INT64_T
#define R_MPI_UINT64_T MPC_UINT64_T
#define R_MPI_COMPLEX8 MPC_COMPLEX8
#define R_MPI_COMPLEX16 MPC_COMPLEX16
#define R_MPI_COMPLEX32 MPC_COMPLEX32
#define R_MPI_WCHAR MPC_WCHAR
#define R_MPI_INTEGER16 MPC_INTEGER16
#define R_MPI_AINT MPC_AINT
#define R_MPI_OFFSET MPC_OFFSET
#define R_MPI_COUNT MPC_COUNT
#define R_MPI_C_BOOL MPC_C_BOOL
#define R_MPI_C_COMPLEX MPC_C_COMPLEX
#define R_MPI_C_FLOAT_COMPLEX MPC_C_FLOAT_COMPLEX
#define R_MPI_C_DOUBLE_COMPLEX MPC_C_DOUBLE_COMPLEX
#define R_MPI_C_LONG_DOUBLE_COMPLEX MPC_C_LONG_DOUBLE_COMPLEX
#define R_MPI_CHARACTER MPC_CHARACTER
#define R_MPI_DOUBLE_PRECISION MPC_DOUBLE_PRECISION

#define R_MPI_2INTEGER MPC_2INTEGER
#define R_MPI_2REAL MPC_2REAL
/* Datatype decoders */

#define R_MPI_COMBINER_UNKNOWN MPC_COMBINER_UNKNOWN
#define R_MPI_COMBINER_NAMED MPC_COMBINER_NAMED
#define R_MPI_COMBINER_DUP MPC_COMBINER_DUP
#define R_MPI_COMBINER_CONTIGUOUS MPC_COMBINER_CONTIGUOUS
#define R_MPI_COMBINER_VECTOR MPC_COMBINER_VECTOR
#define R_MPI_COMBINER_HVECTOR MPC_COMBINER_HVECTOR
#define R_MPI_COMBINER_INDEXED MPC_COMBINER_INDEXED
#define R_MPI_COMBINER_HINDEXED MPC_COMBINER_HINDEXED
#define R_MPI_COMBINER_INDEXED_BLOCK MPC_COMBINER_INDEXED_BLOCK
#define R_MPI_COMBINER_HINDEXED_BLOCK MPC_COMBINER_HINDEXED_BLOCK
#define R_MPI_COMBINER_STRUCT MPC_COMBINER_STRUCT
#define R_MPI_COMBINER_SUBARRAY MPC_COMBINER_SUBARRAY
#define R_MPI_COMBINER_DARRAY MPC_COMBINER_DARRAY
#define R_MPI_COMBINER_F90_REAL MPC_COMBINER_F90_REAL
#define R_MPI_COMBINER_F90_COMPLEX MPC_COMBINER_F90_COMPLEX
#define R_MPI_COMBINER_F90_INTEGER MPC_COMBINER_F90_INTEGER
#define R_MPI_COMBINER_RESIZED MPC_COMBINER_RESIZED

/* Predefined MPI datatypes corresponding to both C and Fortran datatypes */

#define R_MPI_CXX_BOOL MPC_CXX_BOOL
#define R_MPI_CXX_FLOAT_COMPLEX MPC_CXX_FLOAT_COMPLEX
#define R_MPI_CXX_DOUBLE_COMPLEX MPC_CXX_DOUBLE_COMPLEX
#define R_MPI_CXX_LONG_DOUBLE_COMPLEX MPC_CXX_LONG_DOUBLE_COMPLEX

/* These are deprecated MPI 1.0 constants in MPI 3.0
 * however they are never returned by get envelope but as ROMIO uses them */
 
#define R_MPI_COMBINER_HINDEXED_INTEGER MPC_COMBINER_HINDEXED_INTEGER
#define R_MPI_COMBINER_STRUCT_INTEGER MPC_COMBINER_STRUCT_INTEGER
#define R_MPI_COMBINER_HVECTOR_INTEGER MPC_COMBINER_HVECTOR_INTEGER


/************************************************************************/
/* R_MPI_* Defines                                                        */
/************************************************************************/

/* Data-type classes */
#define R_MPI_TYPECLASS_INTEGER 1
#define R_MPI_TYPECLASS_REAL 2
#define R_MPI_TYPECLASS_COMPLEX 3

/* Threading Level */
#define R_MPI_THREAD_SINGLE 0
#define R_MPI_THREAD_FUNNELED 1
#define R_MPI_THREAD_SERIALIZED 2
#define  R_MPI_THREAD_MULTIPLE 3

/* Basic Ops */
#define R_MPI_SUM 0
#define R_MPI_MAX 1
#define R_MPI_MIN 2
#define R_MPI_PROD 3
#define R_MPI_LAND 4
#define R_MPI_BAND 5
#define R_MPI_LOR 6
#define R_MPI_BOR 7
#define R_MPI_LXOR 8
#define R_MPI_BXOR 9
#define R_MPI_MINLOC 10
#define R_MPI_MAXLOC 11
#define R_MPI_REPLACE 13
#define R_MPI_NO_OP 14
#define MAX_MPI_DEFINED_OP 13
#define R_MPI_OP_NULL ((R_MPI_Op)-1)


/* Group Handling */
#define R_MPI_GROUP_EMPTY ((R_MPI_Group)0)
#define R_MPI_GROUP_NULL ((R_MPI_Group)-1)

/* R_MPI_Info definitions */
/* Matches the one of R_MPI_INFO_NULL @ mpc_mpi.h:207 */
#define R_MPI_INFO_NULL (-1)
#define R_MPI_INFO_ENV (0)
/* Maximum length for keys and values
* they are both defined for MPC and MPI variants */
/*1 MB */
#define R_MPI_MAX_INFO_VAL 1024
#define R_MPI_MAX_INFO_KEY 255

/* Other Null Handles */
#define R_MPI_WIN_NULL ((R_MPI_Win)-1)
#define R_MPI_MESSAGE_NULL ((R_MPI_Message) R_MPI_REQUEST_NULL)
#define R_MPI_MESSAGE_NO_PROC -2

#ifdef ROMIO_COMP
#define R_MPI_FILE_NULL ((void *)0)
#endif 

#define R_MPI_BSEND_OVERHEAD (2*sizeof(mpi_buffer_overhead_t))

#define R_MPI_ERRHANDLER_NULL MPC_ERRHANDLER_NULL
#define R_MPI_ERRORS_RETURN MPC_ERRORS_RETURN       /* 1234 in Fortran */
#define R_MPI_ERRORS_ARE_FATAL MPC_ERRORS_ARE_FATAL /* 1235 in Fortran */

#define R_MPI_KEYVAL_INVALID MPC_KEYVAL_INVALID

#define R_MPI_NULL_DELETE_FN ((R_MPI_Delete_function *)MPC_Mpi_null_delete_fn)
#define R_MPI_NULL_COPY_FN ((R_MPI_Copy_function *)MPC_Mpi_null_copy_fn)
#define R_MPI_DUP_FN ((R_MPI_Copy_function *)MPC_Mpi_dup_fn)

#define R_MPI_TYPE_NULL_DELETE_FN ((R_MPI_Delete_function *)MPC_Mpi_type_null_delete_fn)
#define R_MPI_TYPE_NULL_COPY_FN ((R_MPI_Copy_function *)MPC_Mpi_type_null_copy_fn)
#define R_MPI_TYPE_DUP_FN ((R_MPI_Copy_function *)MPC_Mpi_type_dup_fn)

#define R_MPI_COMM_NULL_DELETE_FN ((R_MPI_Delete_function *)MPC_Mpi_comm_null_delete_fn)
#define R_MPI_COMM_NULL_COPY_FN ((R_MPI_Copy_function *)MPC_Mpi_comm_null_copy_fn)
#define R_MPI_COMM_DUP_FN ((R_MPI_Copy_function *)MPC_Mpi_comm_dup_fn)

#define R_MPI_WIN_NULL_DELETE_FN ((R_MPI_Delete_function *)MPC_Mpi_win_null_delete_fn)
#define R_MPI_WIN_NULL_COPY_FN ((R_MPI_Copy_function *)MPC_Mpi_win_null_copy_fn)
#define R_MPI_WIN_DUP_FN ((R_MPI_Copy_function *)MPC_Mpi_win_dup_fn)

#define R_MPI_TAG_UB 0
#define R_MPI_HOST 1
#define R_MPI_IO 2
#define R_MPI_WTIME_IS_GLOBAL 3
#define R_MPI_APPNUM 4
#define R_MPI_UNIVERSE_SIZE 5
#define R_MPI_LASTUSEDCODE 6
#define R_MPI_MAX_KEY_DEFINED 7

/* In addition, there are 5 predefined window attributes that are
 *    defined for every window */
#define R_MPI_WIN_MODEL 0
#define R_MPI_WIN_BASE          1
#define R_MPI_WIN_SIZE          2
#define R_MPI_WIN_DISP_UNIT     3
#define R_MPI_WIN_CREATE_FLAVOR 4

/* Ordering defines */
#define R_MPI_DISTRIBUTE_DFLT_DARG 100
#define R_MPI_DISTRIBUTE_BLOCK 101
#define R_MPI_DISTRIBUTE_CYCLIC 102
#define R_MPI_DISTRIBUTE_NONE 1

#define R_MPI_ORDER_C 200
#define R_MPI_ORDER_FORTRAN 201

/* Halo */
#define R_MPI_HALO_NULL (-1)

/* for comm_split method */
#define R_MPI_COMM_TYPE_SHARED MPC_COMM_TYPE_SHARED
#define R_MPI_COMM_TYPE_SHARED_TR MPC_COMM_TYPE_SHARED_TR
#define R_MPI_COMM_TYPE_SOCKET MPC_COMM_TYPE_SOCKET
#define R_MPI_COMM_TYPE_SOCKET_TR MPC_COMM_TYPE_SOCKET_TR
#define R_MPI_COMM_TYPE_NUMA MPC_COMM_TYPE_NUMA
#define R_MPI_COMM_TYPE_NUMA_TR MPC_COMM_TYPE_NUMA_TR
#define R_MPI_COMM_TYPE_MPC_PROCESS MPC_COMM_TYPE_MPC_PROCESS
#define R_MPI_COMM_TYPE_MPC_PROCESS_TR MPC_COMM_TYPE_MPC_PROCESS_TR

/*
* * MPI-2 One-Sided Communications asserts
*/

/* asserts for one-sided communication */
#define R_MPI_MODE_NOCHECK      1
#define R_MPI_MODE_NOSTORE      2
#define R_MPI_MODE_NOPUT 4
#define R_MPI_MODE_NOPRECEDE 8
#define R_MPI_MODE_NOSUCCEED 16

#define R_MPI_WIN_FLAVOR_CREATE        1
#define R_MPI_WIN_FLAVOR_ALLOCATE      2
#define R_MPI_WIN_FLAVOR_DYNAMIC       3
#define R_MPI_WIN_FLAVOR_SHARED        4

#define R_MPI_WIN_UNIFIED              0
#define R_MPI_WIN_SEPARATE             1

/* Others definitions */
#define R_MPI_MAX_PORT_NAME      256
#define R_MPI_ARGV_NULL (char **)0
#define R_MPI_ARGVS_NULL (char ***)0
#define R_MPI_ERRCODES_IGNORE (int *)0

/* Error not implemented */
#define R_MPIX_ERR_PROC_FAILED          101 /* Process failure */
#define R_MPIX_ERR_PROC_FAILED_PENDING  102 /* A failure has caused this request
                                           * to be pending */
#define R_MPIX_ERR_REVOKED              103 /* The communciation object has been revoked */
#define MPICH_ERR_LAST_MPIX           103


/************************************************************************/
/*  Type Definitions                                                    */
/************************************************************************/

typedef MPC_Datatype R_MPI_Datatype; /* unsigned int */
typedef MPC_Comm R_MPI_Comm; /* unsigned int */
typedef int R_MPI_Request;
typedef MPC_Aint R_MPI_Aint; /* long */
typedef int R_MPI_Errhandler;
typedef MPC_User_function R_MPI_User_function;
typedef int R_MPI_Op;
typedef int R_MPI_Group;
typedef MPC_Status R_MPI_Status;
typedef MPC_Handler_function R_MPI_Handler_function;
typedef int R_MPI_Fint;

/* MPI type combiner */
typedef MPC_Type_combiner R_MPI_Type_combiner;

/* R_MPI_Info Definitions */
typedef MPC_Info R_MPI_Info;

/* Copy Functions */
typedef int (R_MPI_Copy_function) (R_MPI_Comm, int, void *, void *, void *, int *);
typedef int (R_MPI_Delete_function) (R_MPI_Comm, int, void *, void *);

/* Generalized requests functions */
typedef int R_MPI_Grequest_query_function( void * extra_state, R_MPI_Status *status );
typedef int R_MPI_Grequest_cancel_function( void * extra_state, int complete );
typedef int R_MPI_Grequest_free_function( void * extra_state );

/* Extended Generalized Requests Functions */
typedef int R_MPIX_Grequest_poll_fn(void * extra_arg, R_MPI_Status *status);

/* Extended Generalized Request Class */
typedef int R_MPIX_Grequest_class;
typedef int R_MPIX_Grequest_wait_fn(int count, void **array_of_states, double, R_MPI_Status *status);

/* Halo */
typedef int R_MPI_Halo;
typedef int R_MPI_Halo_exchange;

/* NOT IMPLEMENTED >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
typedef int R_MPI_Win;
typedef long R_MPI_Count;

typedef MPC_Message R_MPI_Message;

/* added in MPI-2.2 */
typedef void (R_MPI_File_errhandler_function)(void*, int *, ...);
/* names that were added in MPI-2.0 and deprecated in MPI-2.2 */
typedef R_MPI_File_errhandler_function R_MPI_File_errhandler_fn;
 
/* C functions */
//~ typedef void (MPC_Handler_function) ( R_MPI_Comm *, int *, ... );
typedef int (R_MPI_Comm_copy_attr_function)(R_MPI_Comm, int, void *, void *, void *, int *);
typedef int (R_MPI_Comm_delete_attr_function)(R_MPI_Comm, int, void *, void *);

typedef MPC_Type_copy_attr_function R_MPI_Type_copy_attr_function;
typedef MPC_Type_delete_attr_function R_MPI_Type_delete_attr_function;

typedef int (R_MPI_Win_copy_attr_function)(R_MPI_Win, int, void *, void *, void *,int *);
typedef int (R_MPI_Win_delete_attr_function)(R_MPI_Win, int, void *, void *);
/* added in MPI-2.2 */
typedef void (R_MPI_Comm_errhandler_function)(R_MPI_Comm *, int *, ...);
typedef void (R_MPI_Win_errhandler_function)(R_MPI_Win *, int *, ...);
/* names that were added in MPI-2.0 and deprecated in MPI-2.2 */
typedef R_MPI_Comm_errhandler_function R_MPI_Comm_errhandler_fn;
typedef R_MPI_Win_errhandler_function R_MPI_Win_errhandler_fn;
/* END OF NOT IMPLEMENTED <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

typedef struct
{
	int size;
	R_MPI_Request request;
} mpi_buffer_overhead_t;

/************************************************************************/
/*  MPI Interface                                                       */
/*                                                                      */  
/* /!\ Be careful to update the PMPI interface if                       */
/*      you are adding or updating something here                       */
/*      you also have to define the weak symbol                         */
/*      bindings in mpi_weak.h                                          */
/************************************************************************/



/* Init and Finalize */
int R_MPI_Init_thread (int *, char ***, int, int *);  
int R_MPI_Init (int *, char ***);
int R_MPI_Finalize (void);
int R_MPI_Finalized (int *);
int R_MPI_Initialized (int *);

/* Error Handling */
void R_MPI_Default_error (R_MPI_Comm * comm, int *error, char *msg, char *file, int line);
void R_MPI_Abort_error (R_MPI_Comm * comm, int *error, char *msg, char *file, int line);
void R_MPI_Return_error (R_MPI_Comm * comm, int *error, ...);
int R_MPI_Errhandler_create (R_MPI_Handler_function *, R_MPI_Errhandler *);
int R_MPI_Errhandler_set (R_MPI_Comm, R_MPI_Errhandler);
int R_MPI_Errhandler_get (R_MPI_Comm, R_MPI_Errhandler *);
int R_MPI_Errhandler_free (R_MPI_Errhandler *);
int R_MPI_Error_string (int, char *, int *);
int R_MPI_Error_class (int, int *);
int R_MPI_Abort (R_MPI_Comm, int);

/* NOT IMPLEMENTED >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
int MPC_Mpi_null_delete_fn( R_MPI_Datatype datatype, int type_keyval, void* attribute_val_out, void* extra_state );
int MPC_Mpi_null_copy_fn( R_MPI_Comm comm, int comm_keyval, void* extra_state, void* attribute_val_in, void* attribute_val_out, int* flag );
int MPC_Mpi_dup_fn( R_MPI_Comm comm, int comm_keyval, void* extra_state, void* attribute_val_in, void* attribute_val_out, int* flag );

/* type */
int MPC_Mpi_type_null_delete_fn( R_MPI_Datatype datatype, int type_keyval, void* attribute_val_out, void* extra_state );
int MPC_Mpi_type_null_copy_fn( R_MPI_Comm comm, int comm_keyval, void* extra_state, void* attribute_val_in, void* attribute_val_out, int* flag );
int MPC_Mpi_type_dup_fn( R_MPI_Comm comm, int comm_keyval, void* extra_state, void* attribute_val_in, void* attribute_val_out, int* flag );

/* comm */
int MPC_Mpi_comm_null_delete_fn( R_MPI_Datatype datatype, int type_keyval, void* attribute_val_out, void* extra_state );
int MPC_Mpi_comm_null_copy_fn( R_MPI_Comm comm, int comm_keyval, void* extra_state, void* attribute_val_in, void* attribute_val_out, int* flag );
int MPC_Mpi_comm_dup_fn( R_MPI_Comm comm, int comm_keyval, void* extra_state, void* attribute_val_in, void* attribute_val_out, int* flag );

/* win */
int MPC_Mpi_win_null_delete_fn( R_MPI_Datatype datatype, int type_keyval, void* attribute_val_out, void* extra_state );
int MPC_Mpi_win_null_copy_fn( R_MPI_Comm comm, int comm_keyval, void* extra_state, void* attribute_val_in, void* attribute_val_out, int* flag );
int MPC_Mpi_win_dup_fn( R_MPI_Comm comm, int comm_keyval, void* extra_state, void* attribute_val_in, void* attribute_val_out, int* flag );
/* END OF NOT IMPLEMENTED <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* Point to Point communications */
int R_MPI_Send (void *, int, R_MPI_Datatype, int, int, R_MPI_Comm);
int R_MPI_Recv (void *, int, R_MPI_Datatype, int, int, R_MPI_Comm, R_MPI_Status *);
int R_MPI_Get_count (R_MPI_Status *, R_MPI_Datatype, int *);
int R_MPI_Bsend (void *, int, R_MPI_Datatype, int, int, R_MPI_Comm);
int R_MPI_Ssend (void *, int, R_MPI_Datatype, int, int, R_MPI_Comm);
int R_MPI_Rsend (void *, int, R_MPI_Datatype, int, int, R_MPI_Comm);
int R_MPI_Buffer_attach (void *, int);
int R_MPI_Buffer_detach (void *, int *);
int R_MPI_Isend (void *, int, R_MPI_Datatype, int, int, R_MPI_Comm, R_MPI_Request *);
int R_MPI_Ibsend (void *, int, R_MPI_Datatype, int, int, R_MPI_Comm, R_MPI_Request *);
int R_MPI_Issend (void *, int, R_MPI_Datatype, int, int, R_MPI_Comm, R_MPI_Request *);
int R_MPI_Irsend (void *, int, R_MPI_Datatype, int, int, R_MPI_Comm, R_MPI_Request *);
int R_MPI_Irecv (void *, int, R_MPI_Datatype, int, int, R_MPI_Comm, R_MPI_Request *);
int R_MPI_Wait (R_MPI_Request *, R_MPI_Status *);
int R_MPI_Test (R_MPI_Request *, int *, R_MPI_Status *);
int R_MPI_Request_free (R_MPI_Request *);
int R_MPI_Waitany (int, R_MPI_Request *, int *, R_MPI_Status *);
int R_MPI_Testany (int, R_MPI_Request *, int *, int *, R_MPI_Status *);
int R_MPI_Waitall (int, R_MPI_Request *, R_MPI_Status *);
int R_MPI_Testall (int, R_MPI_Request *, int *, R_MPI_Status *);
int R_MPI_Waitsome (int, R_MPI_Request *, int *, int *, R_MPI_Status *);
int R_MPI_Testsome (int, R_MPI_Request *, int *, int *, R_MPI_Status *);
int R_MPI_Iprobe (int, int, R_MPI_Comm, int *, R_MPI_Status *);
int R_MPI_Probe (int, int, R_MPI_Comm, R_MPI_Status *);
int R_MPI_Cancel (R_MPI_Request *);
int R_MPI_Send_init (void *, int, R_MPI_Datatype, int, int, R_MPI_Comm,  R_MPI_Request *);
int R_MPI_Bsend_init (void *, int, R_MPI_Datatype, int, int, R_MPI_Comm,  R_MPI_Request *);
int R_MPI_Ssend_init (void *, int, R_MPI_Datatype, int, int, R_MPI_Comm,  R_MPI_Request *);
int R_MPI_Rsend_init (void *, int, R_MPI_Datatype, int, int, R_MPI_Comm, R_MPI_Request *);
int R_MPI_Recv_init (void *, int, R_MPI_Datatype, int, int, R_MPI_Comm,  R_MPI_Request *);
int R_MPI_Start (R_MPI_Request *);
int R_MPI_Startall (int, R_MPI_Request *);
int R_MPI_Sendrecv (void *, int, R_MPI_Datatype, int, int, void *, int,  R_MPI_Datatype, int, int, R_MPI_Comm, R_MPI_Status *);
int R_MPI_Sendrecv_replace (void *, int, R_MPI_Datatype, int, int, int, int, R_MPI_Comm, R_MPI_Status *);
  
/* Status Modification and query */
int R_MPI_Status_set_elements(R_MPI_Status *, R_MPI_Datatype , int );
int R_MPI_Status_set_elements_x(R_MPI_Status *, R_MPI_Datatype , R_MPI_Count );
int R_MPI_Status_set_cancelled (R_MPI_Status *, int);
int R_MPI_Request_get_status (R_MPI_Request, int *, R_MPI_Status *);
int R_MPI_Test_cancelled (R_MPI_Status *, int *);

/* Datatype Management & Packs */
int R_MPI_Type_contiguous (int, R_MPI_Datatype, R_MPI_Datatype *);
int R_MPI_Type_vector (int, int, int, R_MPI_Datatype, R_MPI_Datatype *);
int R_MPI_Type_hvector (int, int, R_MPI_Aint, R_MPI_Datatype, R_MPI_Datatype *);
int R_MPI_Type_create_hvector (int, int, R_MPI_Aint, R_MPI_Datatype, R_MPI_Datatype *);
int R_MPI_Type_indexed (int, int *, int *, R_MPI_Datatype, R_MPI_Datatype *);
int R_MPI_Type_hindexed (int, int *, R_MPI_Aint *, R_MPI_Datatype, R_MPI_Datatype *);
int R_MPI_Type_create_hindexed (int, int *, R_MPI_Aint *, R_MPI_Datatype, R_MPI_Datatype *);
int R_MPI_Type_create_indexed_block(int count, int blocklength, int indices[], R_MPI_Datatype old_type, R_MPI_Datatype *newtype);
int R_MPI_Type_create_hindexed_block(int count, int blocklength, R_MPI_Aint indices[], R_MPI_Datatype old_type, R_MPI_Datatype *newtype);
int R_MPI_Type_struct (int, int *, R_MPI_Aint *, R_MPI_Datatype *, R_MPI_Datatype *);
int R_MPI_Type_create_struct (int, int *, R_MPI_Aint *, R_MPI_Datatype *, R_MPI_Datatype *);
int R_MPI_Address (void *, R_MPI_Aint *);
int R_MPI_Get_address(void *location, R_MPI_Aint *address);
/* We could add __attribute__((deprecated)) to routines like R_MPI_Type_extent */
int R_MPI_Type_extent (R_MPI_Datatype, R_MPI_Aint *);
/* See the 1.1 version of the Standard.  The standard made an
unfortunate choice here, however, it is the standard.  The size returned
by R_MPI_Type_size is specified as an int, not an R_MPI_Aint */
int R_MPI_Type_size (R_MPI_Datatype, int *);
/* R_MPI_Type_count was withdrawn in MPI 1.1 */
int R_MPI_Type_lb (R_MPI_Datatype, R_MPI_Aint *);
int R_MPI_Type_ub (R_MPI_Datatype, R_MPI_Aint *);
int R_MPI_Type_commit (R_MPI_Datatype *);
int R_MPI_Type_free (R_MPI_Datatype *);
int R_MPI_Get_elements (R_MPI_Status *, R_MPI_Datatype, int *);
int R_MPI_Type_match_size(int typeclass, int size, R_MPI_Datatype *rtype);
int R_MPI_Pack (void *, int, R_MPI_Datatype, void *, int, int *, R_MPI_Comm);
int R_MPI_Unpack (void *, int, int *, void *, int, R_MPI_Datatype, R_MPI_Comm);
int R_MPI_Pack_size (int, R_MPI_Datatype, R_MPI_Comm, int *);
int R_MPI_Type_set_name( R_MPI_Datatype datatype, char *name );
int R_MPI_Type_get_name( R_MPI_Datatype datatype, char *name, int * resultlen );
int R_MPI_Type_dup( R_MPI_Datatype old_type, R_MPI_Datatype *newtype );
int R_MPI_Type_get_extent(R_MPI_Datatype datatype, R_MPI_Aint *lb, R_MPI_Aint *extent);
int R_MPI_Type_get_true_extent(R_MPI_Datatype datatype, R_MPI_Aint *true_lb, R_MPI_Aint *true_extent);
int R_MPI_Type_get_envelope(R_MPI_Datatype datatype, int *num_integers, int *num_addresses, int *num_datatypes, int *combiner);
int R_MPI_Type_get_contents( R_MPI_Datatype datatype, 
			   int max_integers,
			   int max_addresses,
			   int max_datatypes,
			   int array_of_integers[],
			   R_MPI_Aint array_of_addresses[],
			   R_MPI_Datatype array_of_datatypes[]);
int R_MPI_Type_size_x(R_MPI_Datatype datatype, R_MPI_Count *size);
int R_MPI_Type_get_extent_x(R_MPI_Datatype datatype, R_MPI_Count *lb, R_MPI_Count *extent);
int R_MPI_Type_get_true_extent_x(R_MPI_Datatype datatype, R_MPI_Count *true_lb, R_MPI_Count *true_extent);
int R_MPI_Get_elements_x (R_MPI_Status * status, R_MPI_Datatype datatype, R_MPI_Count *elements);
int R_MPI_Type_create_darray (int size,
			     int rank,
			     int ndims,
			     int array_of_gsizes[],
			     int array_of_distribs[],
			     int array_of_dargs[],
			     int array_of_psizes[],
			     int order,
			     R_MPI_Datatype oldtype,
			     R_MPI_Datatype *newtype);
int R_MPI_Type_create_subarray (int ndims,
			       int array_of_sizes[],
			       int array_of_subsizes[],
			       int array_of_starts[],
			       int order,
			       R_MPI_Datatype oldtype,
			       R_MPI_Datatype * new_type);
int R_MPI_Type_create_resized (R_MPI_Datatype, R_MPI_Aint , R_MPI_Aint , R_MPI_Datatype *);
int R_MPI_Pack_external_size (char *datarep , int incount, R_MPI_Datatype datatype, R_MPI_Aint *size);
int R_MPI_Pack_external (char *datarep , void *inbuf, int incount, R_MPI_Datatype datatype, void * outbuf, R_MPI_Aint outsize, R_MPI_Aint * position);
int R_MPI_Unpack_external (char * datarep, void * inbuf, R_MPI_Aint insize, R_MPI_Aint * position, void * outbuf, int outcount, R_MPI_Datatype datatype);

/* Collective Operations */
int R_MPI_Barrier (R_MPI_Comm);
int R_MPI_Bcast (void *, int, R_MPI_Datatype, int, R_MPI_Comm);
int R_MPI_Gather (void *, int, R_MPI_Datatype, void *, int, R_MPI_Datatype, int, R_MPI_Comm);
int R_MPI_Gatherv (void *, int, R_MPI_Datatype, void *, int *, int *, R_MPI_Datatype, int, R_MPI_Comm);
int R_MPI_Scatter (void *, int, R_MPI_Datatype, void *, int, R_MPI_Datatype, int, R_MPI_Comm);
int R_MPI_Scatterv (void *, int *, int *, R_MPI_Datatype, void *, int, R_MPI_Datatype, int, R_MPI_Comm);
int R_MPI_Allgather (void *, int, R_MPI_Datatype, void *, int, R_MPI_Datatype, R_MPI_Comm);
int R_MPI_Allgatherv (void *, int, R_MPI_Datatype, void *, int *, int *, R_MPI_Datatype, R_MPI_Comm);
int R_MPI_Alltoall (void *, int, R_MPI_Datatype, void *, int, R_MPI_Datatype, R_MPI_Comm);
int R_MPI_Alltoallv (void *, int *, int *, R_MPI_Datatype, void *, int *, int *, R_MPI_Datatype, R_MPI_Comm);
int R_MPI_Exscan (void *, void *, int, R_MPI_Datatype, R_MPI_Op, R_MPI_Comm);
int R_MPI_Reduce (void *, void *, int, R_MPI_Datatype, R_MPI_Op, int, R_MPI_Comm);
int R_MPI_Allreduce (void *, void *, int, R_MPI_Datatype, R_MPI_Op, R_MPI_Comm);
int R_MPI_Reduce_scatter (void *, void *, int *, R_MPI_Datatype, R_MPI_Op, R_MPI_Comm);
int R_MPI_Reduce_scatter_block(void *, void *, int , R_MPI_Datatype , R_MPI_Op , R_MPI_Comm );
int R_MPI_Scan (void *, void *, int, R_MPI_Datatype, R_MPI_Op, R_MPI_Comm);

/* Non Blocking Collectives Operations */
int R_MPI_Iallreduce (void *sendbuf, void *recvbuf, int count,R_MPI_Datatype datatype, R_MPI_Op op, R_MPI_Comm comm,R_MPI_Request *request);
int R_MPI_Ibarrier(R_MPI_Comm comm, R_MPI_Request *request);
int R_MPI_Ibcast(void *buffer, int count, R_MPI_Datatype datatype, int root, R_MPI_Comm comm, R_MPI_Request *request);
int R_MPI_Igather(void *sendbuf, int sendcount, R_MPI_Datatype sendtype,void *recvbuf, int recvcount, R_MPI_Datatype recvtype,int root, R_MPI_Comm comm, R_MPI_Request *request);
int R_MPI_Igatherv(void *sendbuf, int sendcount, R_MPI_Datatype sendtype, void *recvbuf, int recvcounts[], int displs[], R_MPI_Datatype recvtype, int root, R_MPI_Comm comm, R_MPI_Request *request);
int R_MPI_Iscatter(void *sendbuf, int sendcount, R_MPI_Datatype sendtype, void *recvbuf, int recvcount, R_MPI_Datatype recvtype, int root, R_MPI_Comm comm, R_MPI_Request *request);
int R_MPI_Iscatterv(void *sendbuf, int sendcounts[], int displs[], R_MPI_Datatype sendtype, void *recvbuf, int recvcount, R_MPI_Datatype recvtype, int root, R_MPI_Comm comm, R_MPI_Request *request);
int R_MPI_Iallgather(void *sendbuf, int sendcount, R_MPI_Datatype sendtype, void *recvbuf, int recvcount, R_MPI_Datatype recvtype, R_MPI_Comm comm, R_MPI_Request *request);
int R_MPI_Iallgatherv(void *sendbuf, int sendcount, R_MPI_Datatype sendtype, void *recvbuf, int recvcounts[], int displs[], R_MPI_Datatype recvtype, R_MPI_Comm comm, R_MPI_Request *request);
int R_MPI_Ialltoall(void *sendbuf, int sendcount, R_MPI_Datatype sendtype, void *recvbuf, int recvcount, R_MPI_Datatype recvtype, R_MPI_Comm comm, R_MPI_Request *request);
int R_MPI_Ialltoallv(void *sendbuf, int sendcounts[], int sdispls[], R_MPI_Datatype sendtype, void *recvbuf, int recvcounts[], int rdispls[], R_MPI_Datatype recvtype, R_MPI_Comm comm, R_MPI_Request *request);
int R_MPI_Ialltoallw(void *sendbuf, int sendcounts[], int sdispls[], R_MPI_Datatype sendtypes[], void *recvbuf, int recvcounts[], int rdispls[], R_MPI_Datatype recvtypes[], R_MPI_Comm comm, R_MPI_Request *request);
int R_MPI_Ireduce(void *sendbuf, void *recvbuf, int count, R_MPI_Datatype datatype, R_MPI_Op op, int root, R_MPI_Comm comm, R_MPI_Request *request);
int R_MPI_Ireduce_scatter(void *sendbuf, void *recvbuf, int recvcounts[], R_MPI_Datatype datatype, R_MPI_Op op, R_MPI_Comm comm, R_MPI_Request *request);
int R_MPI_Ireduce_scatter_block(void *sendbuf, void *recvbuf, int recvcount, R_MPI_Datatype datatype, R_MPI_Op op, R_MPI_Comm comm, R_MPI_Request *request);
int R_MPI_Iscan(void *sendbuf, void *recvbuf, int count, R_MPI_Datatype datatype, R_MPI_Op op, R_MPI_Comm comm, R_MPI_Request *request);
int R_MPI_Iexscan(void *sendbuf, void *recvbuf, int count, R_MPI_Datatype datatype, R_MPI_Op op, R_MPI_Comm comm, R_MPI_Request *request);

/* Operations */
int R_MPI_Op_create (R_MPI_User_function *, int, R_MPI_Op *);
int R_MPI_Op_free (R_MPI_Op *);

/* Group Management */
int R_MPI_Group_size (R_MPI_Group, int *);
int R_MPI_Group_rank (R_MPI_Group, int *);
int R_MPI_Group_translate_ranks (R_MPI_Group, int, int *, R_MPI_Group, int *);
int R_MPI_Group_compare (R_MPI_Group, R_MPI_Group, int *);
int R_MPI_Comm_group (R_MPI_Comm, R_MPI_Group *);
int R_MPI_Group_union (R_MPI_Group, R_MPI_Group, R_MPI_Group *);
int R_MPI_Group_intersection (R_MPI_Group, R_MPI_Group, R_MPI_Group *);
int R_MPI_Group_difference (R_MPI_Group, R_MPI_Group, R_MPI_Group *);
int R_MPI_Group_incl (R_MPI_Group, int, int *, R_MPI_Group *);
int R_MPI_Group_excl (R_MPI_Group, int, int *, R_MPI_Group *);
int R_MPI_Group_range_incl (R_MPI_Group, int, int[][3], R_MPI_Group *);
int R_MPI_Group_range_excl (R_MPI_Group, int, int[][3], R_MPI_Group *);
int R_MPI_Group_free (R_MPI_Group *);
  
/* Communicators and Intercommunicators */
int R_MPI_Comm_size (R_MPI_Comm, int *);
int R_MPI_Comm_rank (R_MPI_Comm, int *);
int R_MPI_Comm_compare (R_MPI_Comm, R_MPI_Comm, int *);
int R_MPI_Comm_dup (R_MPI_Comm, R_MPI_Comm *);
int R_MPI_Comm_create (R_MPI_Comm, R_MPI_Group, R_MPI_Comm *);
int R_MPI_Comm_split (R_MPI_Comm, int, int, R_MPI_Comm *);
int R_MPI_Comm_free (R_MPI_Comm *);
int R_MPI_Comm_test_inter (R_MPI_Comm, int *);
int R_MPI_Comm_remote_size (R_MPI_Comm, int *);
int R_MPI_Comm_remote_group (R_MPI_Comm, R_MPI_Group *);
int R_MPI_Intercomm_create (R_MPI_Comm, int, R_MPI_Comm, int, int, R_MPI_Comm *);
int R_MPI_Intercomm_merge (R_MPI_Comm, int, R_MPI_Comm *);

/* Keyval and Attr */
int R_MPI_Keyval_create (R_MPI_Copy_function *, R_MPI_Delete_function *, int *, void *);
int R_MPI_Keyval_free (int *);
int R_MPI_Attr_put (R_MPI_Comm, int, void *);
int R_MPI_Attr_get (R_MPI_Comm, int, void *, int *);
int R_MPI_Attr_delete (R_MPI_Comm, int);
int R_MPI_Attr_get_fortran(R_MPI_Comm comm, int keyval, int *attr_value, int *flag);

/* Topology Management */
int R_MPI_Topo_test (R_MPI_Comm, int *);

int R_MPI_Dims_create (int, int, int *);

int R_MPI_Graph_create (R_MPI_Comm, int, int *, int *, int, R_MPI_Comm *);
int R_MPI_Graphdims_get (R_MPI_Comm, int *, int *);
int R_MPI_Graph_get (R_MPI_Comm, int, int, int *, int *);
int R_MPI_Graph_neighbors_count (R_MPI_Comm, int, int *);
int R_MPI_Graph_neighbors (R_MPI_Comm, int, int, int *);
int R_MPI_Graph_map (R_MPI_Comm, int, int *, int *, int *);  

int R_MPI_Cart_create (R_MPI_Comm, int, int *, int *, int, R_MPI_Comm *);
int R_MPI_Cart_get (R_MPI_Comm, int, int *, int *, int *);
int R_MPI_Cart_rank (R_MPI_Comm, int *, int *);
int R_MPI_Cart_coords (R_MPI_Comm, int, int, int *);
int R_MPI_Cart_shift (R_MPI_Comm, int, int, int *, int *);
int R_MPI_Cart_sub (R_MPI_Comm, int *, R_MPI_Comm *);
int R_MPI_Cart_map (R_MPI_Comm, int, int *, int *, int *);
int R_MPI_Cartdim_get (R_MPI_Comm, int *);

/* Getters */
int R_MPI_Get_processor_name (char *, int *);
int R_MPI_Get_version (int *, int *);
double R_MPI_Wtime (void);
double R_MPI_Wtick (void);
int R_MPI_Query_thread (int *);

/* Profiling */
  
  int R_MPIX_Swap(void **sendrecv_buf , int remote_rank, R_MPI_Count size , R_MPI_Comm comm);
  int R_MPIX_Exchange(void **send_buf , void **recvbuff, int remote_rank, R_MPI_Count size , R_MPI_Comm comm);
 
/* Halo */

int R_MPIX_Halo_cell_init( R_MPI_Halo * halo, char * label, R_MPI_Datatype type, int count );
int R_MPIX_Halo_cell_release( R_MPI_Halo * halo );

int R_MPIX_Halo_cell_set( R_MPI_Halo halo, void * ptr );
int R_MPIX_Halo_cell_get( R_MPI_Halo halo, void ** ptr );

/* Halo Exchange */

int R_MPIX_Halo_exchange_init( R_MPI_Halo_exchange * ex );
int R_MPIX_Halo_exchange_release( R_MPI_Halo_exchange * ex );

int R_MPIX_Halo_exchange_commit( R_MPI_Halo_exchange ex );
int R_MPIX_Halo_exchange( R_MPI_Halo_exchange ex );
int R_MPIX_Halo_iexchange( R_MPI_Halo_exchange ex );
int R_MPIX_Halo_iexchange_wait( R_MPI_Halo_exchange ex );
int R_MPIX_Halo_cell_bind_local( R_MPI_Halo_exchange ex, R_MPI_Halo halo );
int R_MPIX_Halo_cell_bind_remote( R_MPI_Halo_exchange ex, R_MPI_Halo halo, int remote, char * remote_label );
 
/* Note that we may need to define a @PCONTROL_LIST@ depending on whether
stdargs are supported */
int R_MPI_Pcontrol (const int, ...);

/* Communicator Naming (MPI-2 functions) */
int R_MPI_Comm_get_name (R_MPI_Comm, char *, int *);
int R_MPI_Comm_set_name (R_MPI_Comm, char *);

/* Fortran Converters */
R_MPI_Comm R_MPI_Comm_f2c(R_MPI_Fint comm);
R_MPI_Fint R_MPI_Comm_c2f(R_MPI_Comm comm);
R_MPI_Datatype R_MPI_Type_f2c(R_MPI_Fint datatype);
R_MPI_Fint R_MPI_Type_c2f(R_MPI_Datatype datatype);
R_MPI_Group R_MPI_Group_f2c(R_MPI_Fint group);
R_MPI_Fint R_MPI_Group_c2f(R_MPI_Group group);
R_MPI_Request R_MPI_Request_f2c(R_MPI_Fint request);
R_MPI_Fint R_MPI_Request_c2f(R_MPI_Request request);
R_MPI_Win R_MPI_Win_f2c(R_MPI_Fint win);
R_MPI_Fint R_MPI_Win_c2f(R_MPI_Win win);
R_MPI_Op R_MPI_Op_f2c(R_MPI_Fint op);
R_MPI_Fint R_MPI_Op_c2f(R_MPI_Op op);
R_MPI_Info R_MPI_Info_f2c(R_MPI_Fint info);
R_MPI_Fint R_MPI_Info_c2f(R_MPI_Info info);
R_MPI_Errhandler R_MPI_Errhandler_f2c(R_MPI_Fint errhandler);
R_MPI_Fint R_MPI_Errhandler_c2f(R_MPI_Errhandler errhandler);
  
/* Neighbors collectives */
int R_MPI_Neighbor_allgather(void *sendbuf, int sendcount, R_MPI_Datatype sendtype, void *recvbuf, int recvcount, R_MPI_Datatype recvtype, R_MPI_Comm comm);
int R_MPI_Neighbor_allgatherv(void *sendbuf, int sendcount, R_MPI_Datatype sendtype, void *recvbuf, int recvcounts[], int displs[], R_MPI_Datatype recvtype, R_MPI_Comm comm);
int R_MPI_Neighbor_alltoall(void *sendbuf, int sendcount, R_MPI_Datatype sendtype, void *recvbuf, int recvcount, R_MPI_Datatype recvtype, R_MPI_Comm comm);
int R_MPI_Neighbor_alltoallv(void *sendbuf, int sendcounts[], int sdispls[], R_MPI_Datatype sendtype, void *recvbuf, int recvcounts[], int rdispls[], R_MPI_Datatype recvtype, R_MPI_Comm comm);
int R_MPI_Neighbor_alltoallw(void *sendbuf, int sendcounts[], R_MPI_Aint sdispls[], R_MPI_Datatype sendtypes[], void *recvbuf, int recvcounts[], R_MPI_Aint rdispls[], R_MPI_Datatype recvtypes[], R_MPI_Comm comm);

/* MPI Info Management */
int R_MPI_Info_set( R_MPI_Info, char *, char * );
int R_MPI_Info_free( R_MPI_Info * );
int R_MPI_Info_create( R_MPI_Info * );
int R_MPI_Info_delete( R_MPI_Info , char * );
int R_MPI_Info_get(R_MPI_Info , char *, int , char *, int *);
int R_MPI_Info_dup( R_MPI_Info , R_MPI_Info * );
int R_MPI_Info_get_nkeys (R_MPI_Info, int *);
int R_MPI_Info_get_nthkey (R_MPI_Info, int, char *);
int R_MPI_Info_get_valuelen (R_MPI_Info, char *, int *, int *);

/* Generalized Requests */
int R_MPI_Grequest_start( R_MPI_Grequest_query_function *query_fn,
			R_MPI_Grequest_free_function * free_fn,
			R_MPI_Grequest_cancel_function * cancel_fn,
			void *extra_state,
			R_MPI_Request * request);
int R_MPI_Grequest_complete(  R_MPI_Request request); 

/* Extended Generalized Requests */
int R_MPIX_Grequest_start(R_MPI_Grequest_query_function *query_fn,
			R_MPI_Grequest_free_function * free_fn,
			R_MPI_Grequest_cancel_function * cancel_fn, 
			R_MPIX_Grequest_poll_fn * poll_fn, 
			void *extra_state, 
			R_MPI_Request * request);

/* Extended Generalized Request Class */
int R_MPIX_Grequest_class_create( R_MPI_Grequest_query_function * query_fn,
				R_MPI_Grequest_cancel_function * cancel_fn,
				R_MPI_Grequest_free_function * free_fn,
				R_MPIX_Grequest_poll_fn * poll_fn,
				R_MPIX_Grequest_wait_fn * wait_fn,
				R_MPIX_Grequest_class * new_class );
int R_MPIX_Grequest_class_allocate( R_MPIX_Grequest_class target_class, void *extra_state, R_MPI_Request *request );

/* Dummy One-Sided Communications */

int R_MPI_Free_mem (void *ptr);
int R_MPI_Alloc_mem(R_MPI_Aint size, R_MPI_Info info, void *baseptr);

/************************************************************************/
/* The MPI Tools Interface R_MPI_T                                        */
/************************************************************************/

/** R_MPI_T Verbosity levels */

typedef enum {

  MPC_T_VERBOSITY_NONE = 0,

  R_MPI_T_VERBOSITY_USER_BASIC,
  R_MPI_T_VERBOSITY_USER_DETAIL,
  R_MPI_T_VERBOSITY_USER_ALL,

  R_MPI_T_VERBOSITY_TUNER_BASIC,
  R_MPI_T_VERBOSITY_TUNER_DETAIL,
  R_MPI_T_VERBOSITY_TUNER_ALL,

  R_MPI_T_VERBOSITY_MPIDEV_BASIC,
  R_MPI_T_VERBOSITY_MPIDEV_DETAIL,
  R_MPI_T_VERBOSITY_MPIDEV_ALL

} MPC_T_verbosity;

/** R_MPI_T Binding to object */

typedef enum {

  R_MPI_T_BIND_NO_OBJECT = 0,
  R_MPI_T_BIND_MPI_COMM,
  R_MPI_T_BIND_MPI_DATATYPE,
  R_MPI_T_BIND_MPI_ERRHANDLER,
  R_MPI_T_BIND_MPI_FILE,
  R_MPI_T_BIND_MPI_GROUP,
  R_MPI_T_BIND_MPI_OP,
  R_MPI_T_BIND_MPI_REQUEST,
  R_MPI_T_BIND_MPI_WIN,
  R_MPI_T_BIND_MPI_MESSAGE,
  R_MPI_T_BIND_MPI_INFO
} MPC_T_binding;

/** Initialization and Finalization */
#define R_MPI_T_ERR_INVALID_NAME      73  /* Name doesn't match */
#define R_MPI_T_ERR_INVALID           74  /* Generic error code for MPI_T added in MPI-3.1 */

/** Initialize the R_MPI_T environment
* @arg required The level of thread safety required
* @arg provided The level of thread safety provided
* @return MPI Error
*/
int R_MPI_T_init_thread(int required, int *provided);

/** Close the R_MPI_T Context
* @note R_MPI_T does refcounting
* @return MPI Error
*/
int R_MPI_T_finalize(void);

/** R_MPI_T Enum */

#define R_MPI_T_ENUM_NULL ((R_MPI_T_enum)NULL)

/* One-Sided Communications */
int R_MPI_Win_set_attr(R_MPI_Win, int, void *);
int R_MPI_Win_get_attr(R_MPI_Win, int, void *, int *);
int R_MPI_Win_free_keyval(int *);
int R_MPI_Win_delete_attr(R_MPI_Win, int);
int R_MPI_Win_create_keyval(R_MPI_Win_copy_attr_function *,
                          R_MPI_Win_delete_attr_function *, int *, void *);
int R_MPI_Win_create(void *, R_MPI_Aint, int, R_MPI_Info, R_MPI_Comm, R_MPI_Win *);
int R_MPI_Win_free(R_MPI_Win *);
int R_MPI_Win_wait(R_MPI_Win);
int R_MPI_Accumulate(void *, int, R_MPI_Datatype, int, R_MPI_Aint, int, R_MPI_Datatype,
                   R_MPI_Op, R_MPI_Win);
int R_MPI_Get(void *, int, R_MPI_Datatype, int, R_MPI_Aint, int, R_MPI_Datatype,
            R_MPI_Win);
int R_MPI_Put(void *, int, R_MPI_Datatype, int, R_MPI_Aint, int, R_MPI_Datatype,
            R_MPI_Win);
int R_MPI_Win_complete(R_MPI_Win);
int R_MPI_Win_fence(int, R_MPI_Win);
int R_MPI_Win_get_group(R_MPI_Win, R_MPI_Group *);
int R_MPI_Win_lock(int, int, int, R_MPI_Win);
int R_MPI_Win_post(R_MPI_Group, int, R_MPI_Win);
int R_MPI_Win_start(R_MPI_Group, int, R_MPI_Win);
int R_MPI_Win_test(R_MPI_Win, int *);
int R_MPI_Win_unlock(int, R_MPI_Win);
int R_MPI_Win_allocate(R_MPI_Aint, int, R_MPI_Info, R_MPI_Comm, void *, R_MPI_Win *);
int R_MPI_Win_set_name(R_MPI_Win, char *);
int R_MPI_Win_get_name(R_MPI_Win, char *, int *);
int R_MPI_Win_set_errhandler(R_MPI_Win, R_MPI_Errhandler);
int R_MPI_Win_get_errhandler(R_MPI_Win, R_MPI_Errhandler *);
int R_MPI_Win_call_errhandler(R_MPI_Win win, int errorcode);
int R_MPI_Win_allocate_shared(R_MPI_Aint, int, R_MPI_Info, R_MPI_Comm, void *,
                            R_MPI_Win *);
int R_MPI_Win_create_errhandler(R_MPI_Win_errhandler_function *, R_MPI_Errhandler *);
int R_MPI_Win_create_dynamic(R_MPI_Info, R_MPI_Comm, R_MPI_Win *);
int R_MPI_Win_shared_query(R_MPI_Win, int, R_MPI_Aint *, int *, void *);
int R_MPI_Win_lock_all(int, R_MPI_Win);
int R_MPI_Win_unlock_all(R_MPI_Win win);
int R_MPI_Win_sync(R_MPI_Win win);
int R_MPI_Win_attach(R_MPI_Win, void *, R_MPI_Aint);
int R_MPI_Win_detach(R_MPI_Win, void *);
int R_MPI_Win_flush(int, R_MPI_Win);
int R_MPI_Win_flush_all(R_MPI_Win);
int R_MPI_Win_set_info(R_MPI_Win, R_MPI_Info);
int R_MPI_Win_get_info(R_MPI_Win, R_MPI_Info *);
int R_MPI_Get_accumulate(void *, int, R_MPI_Datatype, void *, int,
                       R_MPI_Datatype, int, R_MPI_Aint, int, R_MPI_Datatype, R_MPI_Op,
                       R_MPI_Win);
int R_MPI_Fetch_and_op(void *, void *, R_MPI_Datatype, int, R_MPI_Aint, R_MPI_Op,
                     R_MPI_Win);
int R_MPI_Compare_and_swap(void *, void *, void *, R_MPI_Datatype, int,
                         R_MPI_Aint, R_MPI_Win);
int R_MPI_Rput(void *, int, R_MPI_Datatype, int, R_MPI_Aint, int, R_MPI_Datatype,
             R_MPI_Win, R_MPI_Request *);
int R_MPI_Rget(void *, int, R_MPI_Datatype, int, R_MPI_Aint, int, R_MPI_Datatype,
             R_MPI_Win, R_MPI_Request *);
int R_MPI_Raccumulate(void *, int, R_MPI_Datatype, int, R_MPI_Aint, int,
                    R_MPI_Datatype, R_MPI_Op, R_MPI_Win, R_MPI_Request *);
int R_MPI_Rget_accumulate(void *, int, R_MPI_Datatype, void *, int,
                        R_MPI_Datatype, int, R_MPI_Aint, int, R_MPI_Datatype, R_MPI_Op,
                        R_MPI_Win, R_MPI_Request *);
/** Internal storage class (see mpit_internal.h) */
struct MPC_T_enum;

/** MPI Storage (just a pointer as no Fortran) */
typedef struct MPC_T_enum *R_MPI_T_enum;

/** Retrieve informations about an enum
* @arg enumtype The enumeration to be queried
* @arg num The number of objects in the enum
* @arg name Where to return the string containing the enum name
* @arg name_len Length of the buffer for "name"
* @return MPI Error
*/
int R_MPI_T_enum_get_info(R_MPI_T_enum enumtype, int *num, char *name,
                        int *name_len);

/** Retrieve and element in the enum
* @arg enumtype The enumeration to be queried
* @arg index ID of the value to be queried
* @arg name Name of the value to be queried
* @arg name_len Length of the target buffer
* @return MPI Error R_MPI_T_ERR_INVALID_INDEX (if out of range)
*/
int R_MPI_T_enum_get_item(R_MPI_T_enum enumtype, int index, int *value, char *name,
                        int *name_len);

/** Control Variables (CVAR) */

/** Get the number of control variables
* @arg num_cvar Number of control variables
* @return MPI Error
*/
int R_MPI_T_cvar_get_num(int *num_cvar);

/** This defines the scope of a cvar */
typedef enum {
  R_MPI_T_SCOPE_CONSTANT, /*<< Readonly value does not change */
  R_MPI_T_SCOPE_READONLY, /*<< Readonly can change but cannot be changed */
  R_MPI_T_SCOPE_LOCAL,    /*<< Can be writable as a local operation */
  R_MPI_T_SCOPE_GROUP,    /*<< Can be writable in a group of processes */
  R_MPI_T_SCOPE_GROUP_EQ, /*<< Can be writable in a group of processes requiring
                           the same value */
  R_MPI_T_SCOPE_ALL,      /*<< Can be writable in all connected processes */
  R_MPI_T_SCOPE_ALL_EQ,   /*<< Can be writable in all connected processes with the
                           same value */
} MPC_T_cvar_scope;

/** Retrieve the infos from a CVAR
* @arg cvar_index The CVAR to querry
* @arg name The name of the CVAR
* @arg name_len Length of the target buffer
* @arg verbosity The verbosity level of this CVAR \ref MPC_T_Verbosity
* @arg datatype The datatype returned by the CVAR
* @arg enumtype The enumtype (optionnal) for description
* @arg desc The description of the control variable
* @arg desc_len THe length of the desc buffer
* @arg bind Type of MPI object the variable is bound (see \ref MPC_T_Bind)
* @arg scope Scope in which this variable can be manipulated (\ref
* MPC_T_CVAR_scope)
* @return MPI Error
*/
int R_MPI_T_cvar_get_info(int cvar_index, char *name, int *name_len,
                        int *verbosity, R_MPI_Datatype *datatype,
                        R_MPI_T_enum *enumtype, char *desc, int *desc_len,
                        int *bind, int *scope);

/** Get the index of a CVAR from its name
* @arg name Name of the target CVAR
* @arg cvar_index Index of the target CVAR
* @return R_MPI_T_ERR_INVALID_NAME if not found
*/
int R_MPI_T_cvar_get_index(char *name, int *cvar_index);

/** Forward declaration of the VAR container */

struct MPC_T_data;

/** CVAR Handles */

#define R_MPI_T_CVAR_HANDLE_NULL ((R_MPI_T_cvar_handle)NULL)

typedef struct MPC_T_cvar *R_MPI_T_cvar_handle;

/** Allocate a CVAR handle
* @arg cvar_index Target CVAR index
* @arg obj_handle Target MPI handle
* @arg handle Handle to be created
* @arg count Number of elements used to represent this variable
* @return MPI Error
*/
int R_MPI_T_cvar_handle_alloc(int cvar_index, void *obj_handle,
                            R_MPI_T_cvar_handle *handle, int *count);

/** Free a CVAR handle
* @arg handle Handle to be freed
* @return MPI Error
*/
int R_MPI_T_cvar_handle_free(R_MPI_T_cvar_handle *handle);

/** CVAR access */

/** Read a control variables
* @arg handle A handle to a given CVAR
* @arg buff Pointer to where to store the content
* @return MPI Error
*/
int R_MPI_T_cvar_read(R_MPI_T_cvar_handle handle, void *buff);

/** Write a control variable
* @arg handle A handle to a given CVAR
* @arg buff The data to be written
* @return MPI Error
*/
int R_MPI_T_cvar_write(R_MPI_T_cvar_handle handle, void *buff);

/** Performance variables (PVAR) */

typedef enum {
  MPC_T_PVAR_CLASS_NONE,          /**<< Internal value to catch uninitialized */
  R_MPI_T_PVAR_CLASS_STATE,         /**<< A set of discrete states */
  R_MPI_T_PVAR_CLASS_LEVEL,         /**<< Utilization of a ressource */
  R_MPI_T_PVAR_CLASS_SIZE,          /**<< The size of a ressource */
  R_MPI_T_PVAR_CLASS_PERCENTAGE,    /**<< The percentage of a ressource use */
  R_MPI_T_PVAR_CLASS_HIGHWATERMARK, /**<< High use of a ressource */
  R_MPI_T_PVAR_CLASS_LOWWATERMARK,  /**<< Low use of a ressource */
  R_MPI_T_PVAR_CLASS_COUNTER,       /**<< Number of occurences of an event */
  R_MPI_T_PVAR_CLASS_AGGREGATE,     /**<< Aggregated value of ressource */
  R_MPI_T_PVAR_CLASS_TIMER,  /**<< Aggregate time spent executing something */
  R_MPI_T_PVAR_CLASS_GENERIC /**<< A generic class */
} MPC_T_pvar_class;

/** Get the number of PVAR
* @arg num_pvar Number of PVAR
* @return MPI Error
*/
int R_MPI_T_pvar_get_num(int *num_pvar);

/** Get the informations associated with a PVAR
* @arg pvar_index Index of the target PVAR
* @arg name Name of the PVAR
* @arg name_len Length of the target buffer for name
* @arg verbosity Verbosity level associated with this PVAR
* @arg var_class Class of the PVAR (see \ref MPC_T_pvar_class )
* @arg datatype Datatype associated with this PVAR
* @arg desc Description of the PVAR
* @arg desc_lenght Lenght of the desc buffer
* @arg bind Binding of this PVAR
* @arg readonly Whether this PVAR is readlonly
* @arg continuous Whether the PVAR variable can be started and stopped
* @arg atomic Whether the PVAR can be attomically read and set
* @return MPI Error
*/
int R_MPI_T_pvar_get_info(int pvar_index, char *name, int *name_len,
                        int *verbosity, int *var_class, R_MPI_Datatype *datatype,
                        R_MPI_T_enum *enumtype, char *desc, int *desc_len,
                        int *bind, int *readonly, int *continuous, int *atomic);

/** Get the index of a PVAR by name
* @arg name Name to look for
* @arg var_class Class of the PVAR
* @arg pvar_index Index of the PVAR found
* @return R_MPI_T_ERR_INVALID_NAME if not found
*/
int R_MPI_T_pvar_get_index(char *name, int var_class, int *pvar_index);

/*** Performance experiment sessions */

/* Forward declaration of the session container */
struct MPC_T_session;

#define R_MPI_T_PVAR_SESSION_NULL (-2)

typedef int R_MPI_T_pvar_session;

/** Create a PVAR performance sessions
* @arg session The session to create
* @return MPI Erorr
*/
int R_MPI_T_pvar_session_create(R_MPI_T_pvar_session *session);

/** Free a PVAR performance session
* @arg session to be freed
* @return MPI Error
*/
int R_MPI_T_pvar_session_free(R_MPI_T_pvar_session *session);

/** PVAR Handle allocation */

#define R_MPI_T_PVAR_ALL_HANDLES ((R_MPI_T_pvar_handle)-1)
#define R_MPI_T_PVAR_HANDLE_NULL ((R_MPI_T_pvar_handle)NULL)

typedef struct MPC_T_pvar_handle *R_MPI_T_pvar_handle;

/** Allocate a new PVAR handle
* @arg session Which session to bind the handle to
* @arg pvar_index Index of the PVAR to bind
* @arg obj_handle Reference to the MPI object to bind to
* @arg handle New PVAR handle
* @arg count Number of elements used to represent the variable
* @return MPI Error
*/
int R_MPI_T_pvar_handle_alloc(R_MPI_T_pvar_session session, int pvar_index,
                            void *obj_handle, R_MPI_T_pvar_handle *handle,
                            int *count);

/** Release a PVAR handle
* @arg handle PVAR handle to free
* @return MPI Error
*/
int R_MPI_T_pvar_handle_free(R_MPI_T_pvar_session session,
                           R_MPI_T_pvar_handle *handle);

/** PVAR start and stop */

/** Start a performance variable
* @arg session The performance experiment section to start
* @arg handle The handle of the performance variable
* @return MPI Error
*/
int R_MPI_T_pvar_start(R_MPI_T_pvar_session session, R_MPI_T_pvar_handle handle);

/** Stop and MPIT PVAR
* @arg session The performance experiment section
* @arg handle The handle to manipulate
*/
int R_MPI_T_pvar_stop(R_MPI_T_pvar_session session, R_MPI_T_pvar_handle handle);

/** PVAR Read and write */

/** Read the value associated with a PVAR
 * @arg session Performance experiment session to read from
 * @arg handle Handle of the performance variable
 * @arg buff Storage location where to write to
 * @return MPI Error
 */
int R_MPI_T_pvar_read(R_MPI_T_pvar_session session, R_MPI_T_pvar_handle handle,
                    void *buff);

/** Read and reset the value associated with a PVAR
 * @arg session Performance experiment session to read from
 * @arg handle Handle of the performance variable
 * @arg buff Storage location where to write to
 * @return MPI Error
 */
int R_MPI_T_pvar_readreset(R_MPI_T_pvar_session session, R_MPI_T_pvar_handle handle,
                         void *buff);
/** Write the value associated with a PVAR
 * @arg session Performance experiment session to read from
 * @arg handle Handle of the performance variable
 * @arg buff Storage location where to read from
 * @return MPI Error
 */
int R_MPI_T_pvar_write(R_MPI_T_pvar_session session, R_MPI_T_pvar_handle handle,
                     void *buff);
/** Reset the value associated with a PVAR
 * @arg session Performance experiment session to read from
 * @arg handle Handle of the performance variable
 * @return MPI Error
 */
int R_MPI_T_pvar_reset(R_MPI_T_pvar_session session, R_MPI_T_pvar_handle handle);

/** Variable categorization */

/** Query the number of categories
 * @arg num_cat The number of categories
 * @return MPI Error
 */
int R_MPI_T_category_get_num(int *num_cat);

/** Query infos related to a category
 * @arg cat_index Category to be queried
 * @arg name Name of the category
 * @arg name_len Buffer length for the name of the category
 * @arg desc Description of the category
 * @arg desc_len Length of the buffer for description of the category
 * @arg num_cvars Number of control varaibles in the category
 * @arg num_pvars Number of performance variables in the category
 * @arg num_categories Number of categories inside the category
 * @return MPI Error
 */
int R_MPI_T_category_get_info(int cat_index, char *name, int *name_len,
                            char *desc, int *desc_len, int *num_cvars,
                            int *num_pvars, int *num_categories);

/** Get index of a category by name
 * @arg name Name to querry
 * @arg Index of the category
 * @return R_MPI_T_ERR_INVALID_NAME if not found
 */
int R_MPI_T_category_get_index(char *name, int *cat_index);

/** Get the CVARS in a given category
 * @arg cat_index THe index of the target category
 * @arg len The length of the indices array
 * @arg indices Array filled with the indices of the CVARS
 * @return MPI Error
 */
int R_MPI_T_category_get_cvars(int cat_index, int len, int indices[]);

/** Get the PVARS in a given category
 * @arg cat_index THe index of the target category
 * @arg len The length of the indices array
 * @arg indices Array filled with the indices of the PVARS
 * @return MPI Error
 */
int R_MPI_T_category_get_pvars(int cat_index, int len, int indices[]);

/** Get the categories in a given category
 * @arg cat_index THe index of the target category
 * @arg len The length of the indices array
 * @arg indices Array filled with the indices of the categories
 * @return MPI Error
 */
int R_MPI_T_category_get_categories(int cat_index, int len, int indices[]);

/** Check wether category information changed
 * @arg stamp Value identifying the generation of categories
 * @return MPI Error
 */
int R_MPI_T_category_changed(int *stamp);

/*** THE END OF THE MPI TOOLS INTERFACE */

/************************************************************************/
/*  PMPI Profiling Interface                                            */
/************************************************************************/
#if !defined(R_MPI_BUILD_PROFILING)
/* Init and Finalize */
int R_PMPI_Init_thread (int *, char ***, int, int *);  
int R_PMPI_Init (int *, char ***);
int R_PMPI_Finalize (void);
int R_PMPI_Finalized (int *);
int R_PMPI_Initialized (int *);

/* Error Handling */
void R_PMPI_Default_error (R_MPI_Comm * comm, int *error, char *msg, char *file, int line);
void R_PMPI_Abort_error (R_MPI_Comm * comm, int *error, char *msg, char *file, int line);
void R_PMPI_Return_error (R_MPI_Comm * comm, int *error, ...);
int R_PMPI_Errhandler_create (R_MPI_Handler_function *, R_MPI_Errhandler *);
int R_PMPI_Errhandler_set (R_MPI_Comm, R_MPI_Errhandler);
int R_PMPI_Errhandler_get (R_MPI_Comm, R_MPI_Errhandler *);
int R_PMPI_Errhandler_free (R_MPI_Errhandler *);
int R_PMPI_Error_string (int, char *, int *);
int R_PMPI_Error_class (int, int *);
int R_PMPI_Abort (R_MPI_Comm, int);

/* Point to Point communications */
int R_PMPI_Send (void *, int, R_MPI_Datatype, int, int, R_MPI_Comm);
int R_PMPI_Recv (void *, int, R_MPI_Datatype, int, int, R_MPI_Comm, R_MPI_Status *);
int R_PMPI_Get_count (R_MPI_Status *, R_MPI_Datatype, int *);
int R_PMPI_Bsend (void *, int, R_MPI_Datatype, int, int, R_MPI_Comm);
int R_PMPI_Ssend (void *, int, R_MPI_Datatype, int, int, R_MPI_Comm);
int R_PMPI_Rsend (void *, int, R_MPI_Datatype, int, int, R_MPI_Comm);
int R_PMPI_Buffer_attach (void *, int);
int R_PMPI_Buffer_detach (void *, int *);
int R_PMPI_Isend (void *, int, R_MPI_Datatype, int, int, R_MPI_Comm, R_MPI_Request *);
int R_PMPI_Ibsend (void *, int, R_MPI_Datatype, int, int, R_MPI_Comm, R_MPI_Request *);
int R_PMPI_Issend (void *, int, R_MPI_Datatype, int, int, R_MPI_Comm, R_MPI_Request *);
int R_PMPI_Irsend (void *, int, R_MPI_Datatype, int, int, R_MPI_Comm, R_MPI_Request *);
int R_PMPI_Irecv (void *, int, R_MPI_Datatype, int, int, R_MPI_Comm, R_MPI_Request *);
int R_PMPI_Wait (R_MPI_Request *, R_MPI_Status *);
int R_PMPI_Test (R_MPI_Request *, int *, R_MPI_Status *);
int R_PMPI_Request_free (R_MPI_Request *);
int R_PMPI_Waitany (int, R_MPI_Request *, int *, R_MPI_Status *);
int R_PMPI_Testany (int, R_MPI_Request *, int *, int *, R_MPI_Status *);
int R_PMPI_Waitall (int, R_MPI_Request *, R_MPI_Status *);
int R_PMPI_Testall (int, R_MPI_Request *, int *, R_MPI_Status *);
int R_PMPI_Waitsome (int, R_MPI_Request *, int *, int *, R_MPI_Status *);
int R_PMPI_Testsome (int, R_MPI_Request *, int *, int *, R_MPI_Status *);
int R_PMPI_Iprobe (int, int, R_MPI_Comm, int *, R_MPI_Status *);
int R_PMPI_Probe (int, int, R_MPI_Comm, R_MPI_Status *);
int R_PMPI_Test_cancelled (R_MPI_Status *, int *);
int R_PMPI_Send_init (void *, int, R_MPI_Datatype, int, int, R_MPI_Comm,  R_MPI_Request *);
int R_PMPI_Bsend_init (void *, int, R_MPI_Datatype, int, int, R_MPI_Comm,  R_MPI_Request *);
int R_PMPI_Ssend_init (void *, int, R_MPI_Datatype, int, int, R_MPI_Comm,  R_MPI_Request *);
int R_PMPI_Rsend_init (void *, int, R_MPI_Datatype, int, int, R_MPI_Comm, R_MPI_Request *);
int R_PMPI_Recv_init (void *, int, R_MPI_Datatype, int, int, R_MPI_Comm,  R_MPI_Request *);
int R_PMPI_Start (R_MPI_Request *);
int R_PMPI_Startall (int, R_MPI_Request *);
int R_PMPI_Sendrecv (void *, int, R_MPI_Datatype, int, int, void *, int,  R_MPI_Datatype, int, int, R_MPI_Comm, R_MPI_Status *);
int R_PMPI_Sendrecv_replace (void *, int, R_MPI_Datatype, int, int, int, int, R_MPI_Comm, R_MPI_Status *);

/* Status Modification and query */
int R_PMPI_Status_set_elements(R_MPI_Status *, R_MPI_Datatype , int );
int R_PMPI_Status_set_elements_x(R_MPI_Status *, R_MPI_Datatype , R_MPI_Count );
int R_PMPI_Status_set_cancelled (R_MPI_Status *, int);
int R_PMPI_Request_get_status (R_MPI_Request, int *, R_MPI_Status *);
int R_PMPI_Test_cancelled (R_MPI_Status *, int *);

/* Datatype Management & Packs */
int R_PMPI_Type_contiguous (int, R_MPI_Datatype, R_MPI_Datatype *);
int R_PMPI_Type_vector (int, int, int, R_MPI_Datatype, R_MPI_Datatype *);
int R_PMPI_Type_hvector (int, int, R_MPI_Aint, R_MPI_Datatype, R_MPI_Datatype *);
int R_PMPI_Type_create_hvector (int, int, R_MPI_Aint, R_MPI_Datatype, R_MPI_Datatype *);
int R_PMPI_Type_indexed (int, int *, int *, R_MPI_Datatype, R_MPI_Datatype *);
int R_PMPI_Type_hindexed (int, int *, R_MPI_Aint *, R_MPI_Datatype, R_MPI_Datatype *);
int R_PMPI_Type_create_indexed_block(int count, int blocklength, int indices[], R_MPI_Datatype old_type, R_MPI_Datatype *newtype);
int R_PMPI_Type_create_hindexed_block(int count, int blocklength, R_MPI_Aint indices[], R_MPI_Datatype old_type, R_MPI_Datatype *newtype);
int R_PMPI_Type_create_hindexed (int, int *, R_MPI_Aint *, R_MPI_Datatype, R_MPI_Datatype *);
int R_PMPI_Type_struct (int, int *, R_MPI_Aint *, R_MPI_Datatype *, R_MPI_Datatype *);
int R_PMPI_Type_create_struct (int, int *, R_MPI_Aint *, R_MPI_Datatype *, R_MPI_Datatype *);
int R_PMPI_Address (void *, R_MPI_Aint *);
int R_PMPI_Get_address( void *location, R_MPI_Aint *address);
/* We could add __attribute__((deprecated)) to routines like R_MPI_Type_extent */
int R_PMPI_Type_get_extent(R_MPI_Datatype datatype, R_MPI_Aint *lb, R_MPI_Aint *extent);
/* See the 1.1 version of the Standard.  The standard made an
unfortunate choice here, however, it is the standard.  The size returned
by R_MPI_Type_size is specified as an int, not an R_MPI_Aint */
int R_PMPI_Type_size (R_MPI_Datatype, int *);
/* R_MPI_Type_count was withdrawn in MPI 1.1 */
int R_PMPI_Type_lb (R_MPI_Datatype, R_MPI_Aint *);
int R_PMPI_Type_ub (R_MPI_Datatype, R_MPI_Aint *);
int R_PMPI_Type_commit (R_MPI_Datatype *);
int R_PMPI_Type_free (R_MPI_Datatype *);
int R_PMPI_Get_elements (R_MPI_Status *, R_MPI_Datatype, int *);
int R_PMPI_Type_match_size(int typeclass, int size, R_MPI_Datatype *rtype);
int R_PMPI_Pack (void *, int, R_MPI_Datatype, void *, int, int *, R_MPI_Comm);
int R_PMPI_Unpack (void *, int, int *, void *, int, R_MPI_Datatype, R_MPI_Comm);
int R_PMPI_Pack_size (int, R_MPI_Datatype, R_MPI_Comm, int *);
int R_PMPI_Type_set_name( R_MPI_Datatype datatype, char *name );
int R_PMPI_Type_get_name( R_MPI_Datatype datatype, char *name, int * resultlen );
int R_PMPI_Type_dup( R_MPI_Datatype old_type, R_MPI_Datatype *newtype );
int R_PMPI_Type_extent(R_MPI_Datatype datatype, R_MPI_Aint *extent);
int R_PMPI_Type_get_true_extent(R_MPI_Datatype datatype, R_MPI_Aint *true_lb, R_MPI_Aint *true_extent);
int R_PMPI_Type_get_envelope(R_MPI_Datatype datatype, int *num_integers, int *num_addresses, int *num_datatypes, int *combiner);
int R_PMPI_Type_get_contents( R_MPI_Datatype datatype, 
		       	    int max_integers,
			    int max_addresses,
			    int max_datatypes,
			    int array_of_integers[],
			    R_MPI_Aint array_of_addresses[],
			    R_MPI_Datatype array_of_datatypes[]);
int R_PMPI_Type_size_x(R_MPI_Datatype datatype, R_MPI_Count *size);
int R_PMPI_Type_get_extent_x(R_MPI_Datatype datatype, R_MPI_Count *lb, R_MPI_Count *extent);
int R_PMPI_Type_get_true_extent_x(R_MPI_Datatype datatype, R_MPI_Count *true_lb, R_MPI_Count *true_extent);
int R_PMPI_Get_elements_x (R_MPI_Status * status, R_MPI_Datatype datatype, R_MPI_Count *elements);
int R_PMPI_Type_create_darray (int size,
			     int rank,
			     int ndims,
			     int array_of_gsizes[],
			     int array_of_distribs[],
			     int array_of_dargs[],
			     int array_of_psizes[],
			     int order,
			     R_MPI_Datatype oldtype,
			     R_MPI_Datatype *newtype);
int R_PMPI_Type_create_subarray (int ndims,
			       int array_of_sizes[],
			       int array_of_subsizes[],
			       int array_of_starts[],
			       int order,
			       R_MPI_Datatype oldtype,
			       R_MPI_Datatype * new_type);

int R_PMPI_Pack_external_size (char *, int, R_MPI_Datatype, R_MPI_Aint *);
int R_PMPI_Pack_external (char *, void *, int, R_MPI_Datatype, void *, R_MPI_Aint, R_MPI_Aint *);
int R_PMPI_Unpack_external (char *, void *, R_MPI_Aint, R_MPI_Aint *, void *, int, R_MPI_Datatype);

/* Collective Operations */
int R_PMPI_Barrier (R_MPI_Comm);
int R_PMPI_Bcast (void *, int, R_MPI_Datatype, int, R_MPI_Comm);
int R_PMPI_Gather (void *, int, R_MPI_Datatype, void *, int, R_MPI_Datatype, int, R_MPI_Comm);
int R_PMPI_Gatherv (void *, int, R_MPI_Datatype, void *, int *, int *, R_MPI_Datatype, int, R_MPI_Comm);
int R_PMPI_Scatter (void *, int, R_MPI_Datatype, void *, int, R_MPI_Datatype, int, R_MPI_Comm);
int R_PMPI_Scatterv (void *, int *, int *, R_MPI_Datatype, void *, int, R_MPI_Datatype, int, R_MPI_Comm);
int R_PMPI_Allgather (void *, int, R_MPI_Datatype, void *, int, R_MPI_Datatype, R_MPI_Comm);
int R_PMPI_Allgatherv (void *, int, R_MPI_Datatype, void *, int *, int *, R_MPI_Datatype, R_MPI_Comm);
int R_PMPI_Alltoall (void *, int, R_MPI_Datatype, void *, int, R_MPI_Datatype, R_MPI_Comm);
int R_PMPI_Alltoallv (void *, int *, int *, R_MPI_Datatype, void *, int *, int *, R_MPI_Datatype, R_MPI_Comm);
int R_PMPI_Exscan (void *, void *, int, R_MPI_Datatype, R_MPI_Op, R_MPI_Comm);
int R_PMPI_Reduce (void *, void *, int, R_MPI_Datatype, R_MPI_Op, int, R_MPI_Comm);
int R_PMPI_Allreduce (void *, void *, int, R_MPI_Datatype, R_MPI_Op, R_MPI_Comm);
int R_PMPI_Reduce_scatter (void *, void *, int *, R_MPI_Datatype, R_MPI_Op, R_MPI_Comm);
int R_PMPI_Reduce_scatter_block(void *, void *, int , R_MPI_Datatype , R_MPI_Op , R_MPI_Comm );
int R_PMPI_Scan (void *, void *, int, R_MPI_Datatype, R_MPI_Op, R_MPI_Comm);

/* Non Blocking Collectives Operations */
int R_PMPI_Iallreduce (void *sendbuf, void *recvbuf, int count,R_MPI_Datatype datatype, R_MPI_Op op, R_MPI_Comm comm,R_MPI_Request *request);
int R_PMPI_Ibarrier(R_MPI_Comm comm, R_MPI_Request *request);
int R_PMPI_Ibcast(void *buffer, int count, R_MPI_Datatype datatype, int root, R_MPI_Comm comm, R_MPI_Request *request);
int R_PMPI_Igather(void *sendbuf, int sendcount, R_MPI_Datatype sendtype,void *recvbuf, int recvcount, R_MPI_Datatype recvtype,int root, R_MPI_Comm comm, R_MPI_Request *request);
int R_PMPI_Igatherv(void *sendbuf, int sendcount, R_MPI_Datatype sendtype, void *recvbuf, int recvcounts[], int displs[], R_MPI_Datatype recvtype, int root, R_MPI_Comm comm, R_MPI_Request *request);
int R_PMPI_Iscatter(void *sendbuf, int sendcount, R_MPI_Datatype sendtype, void *recvbuf, int recvcount, R_MPI_Datatype recvtype, int root, R_MPI_Comm comm, R_MPI_Request *request);
int R_PMPI_Iscatterv(void *sendbuf, int sendcounts[], int displs[], R_MPI_Datatype sendtype, void *recvbuf, int recvcount, R_MPI_Datatype recvtype, int root, R_MPI_Comm comm, R_MPI_Request *request);
int R_PMPI_Iallgather(void *sendbuf, int sendcount, R_MPI_Datatype sendtype, void *recvbuf, int recvcount, R_MPI_Datatype recvtype, R_MPI_Comm comm, R_MPI_Request *request);
int R_PMPI_Iallgatherv(void *sendbuf, int sendcount, R_MPI_Datatype sendtype, void *recvbuf, int recvcounts[], int displs[], R_MPI_Datatype recvtype, R_MPI_Comm comm, R_MPI_Request *request);
int R_PMPI_Ialltoall(void *sendbuf, int sendcount, R_MPI_Datatype sendtype, void *recvbuf, int recvcount, R_MPI_Datatype recvtype, R_MPI_Comm comm, R_MPI_Request *request);
int R_PMPI_Ialltoallv(void *sendbuf, int sendcounts[], int sdispls[], R_MPI_Datatype sendtype, void *recvbuf, int recvcounts[], int rdispls[], R_MPI_Datatype recvtype, R_MPI_Comm comm, R_MPI_Request *request);
int R_PMPI_Ialltoallw(void *sendbuf, int sendcounts[], int sdispls[], R_MPI_Datatype sendtypes[], void *recvbuf, int recvcounts[], int rdispls[], R_MPI_Datatype recvtypes[], R_MPI_Comm comm, R_MPI_Request *request);
int R_PMPI_Ireduce(void *sendbuf, void *recvbuf, int count, R_MPI_Datatype datatype, R_MPI_Op op, int root, R_MPI_Comm comm, R_MPI_Request *request);
int R_PMPI_Ireduce_scatter(void *sendbuf, void *recvbuf, int recvcounts[], R_MPI_Datatype datatype, R_MPI_Op op, R_MPI_Comm comm, R_MPI_Request *request);
int R_PMPI_Ireduce_scatter_block(void *sendbuf, void *recvbuf, int recvcount, R_MPI_Datatype datatype, R_MPI_Op op, R_MPI_Comm comm, R_MPI_Request *request);
int R_PMPI_Iscan(void *sendbuf, void *recvbuf, int count, R_MPI_Datatype datatype, R_MPI_Op op, R_MPI_Comm comm, R_MPI_Request *request);
int R_PMPI_Iexscan(void *sendbuf, void *recvbuf, int count, R_MPI_Datatype datatype, R_MPI_Op op, R_MPI_Comm comm, R_MPI_Request *request);


/* Operations */
int R_PMPI_Op_create (R_MPI_User_function *, int, R_MPI_Op *);
int R_PMPI_Op_free (R_MPI_Op *);

/* Group Management */
int R_PMPI_Group_size (R_MPI_Group, int *);
int R_PMPI_Group_rank (R_MPI_Group, int *);
int R_PMPI_Group_translate_ranks (R_MPI_Group, int, int *, R_MPI_Group, int *);
int R_PMPI_Group_compare (R_MPI_Group, R_MPI_Group, int *);
int R_PMPI_Comm_group (R_MPI_Comm, R_MPI_Group *);
int R_PMPI_Group_union (R_MPI_Group, R_MPI_Group, R_MPI_Group *);
int R_PMPI_Group_intersection (R_MPI_Group, R_MPI_Group, R_MPI_Group *);
int R_PMPI_Group_difference (R_MPI_Group, R_MPI_Group, R_MPI_Group *);
int R_PMPI_Group_incl (R_MPI_Group, int, int *, R_MPI_Group *);
int R_PMPI_Group_excl (R_MPI_Group, int, int *, R_MPI_Group *);
int R_PMPI_Group_range_incl (R_MPI_Group, int, int[][3], R_MPI_Group *);
int R_PMPI_Group_range_excl (R_MPI_Group, int, int[][3], R_MPI_Group *);
int R_PMPI_Group_free (R_MPI_Group *);
  
/* Communicators and Intercommunicators */
int R_PMPI_Comm_size (R_MPI_Comm, int *);
int R_PMPI_Comm_rank (R_MPI_Comm, int *);
int R_PMPI_Comm_compare (R_MPI_Comm, R_MPI_Comm, int *);
int R_PMPI_Comm_dup (R_MPI_Comm, R_MPI_Comm *);
int R_PMPI_Comm_split_type(R_MPI_Comm, int, int, R_MPI_Info, R_MPI_Comm *);
int R_PMPI_Comm_create (R_MPI_Comm, R_MPI_Group, R_MPI_Comm *);
int R_PMPI_Comm_split (R_MPI_Comm, int, int, R_MPI_Comm *);
int R_PMPI_Comm_free (R_MPI_Comm *);
int R_PMPI_Comm_test_inter (R_MPI_Comm, int *);
int R_PMPI_Comm_remote_size (R_MPI_Comm, int *);
int R_PMPI_Comm_remote_group (R_MPI_Comm, R_MPI_Group *);
int R_PMPI_Intercomm_create (R_MPI_Comm, int, R_MPI_Comm, int, int, R_MPI_Comm *);
int R_PMPI_Intercomm_merge (R_MPI_Comm, int, R_MPI_Comm *);
int R_PMPI_Comm_set_errhandler(R_MPI_Comm comm, R_MPI_Errhandler errhandler);
int R_PMPI_Comm_call_errhandler( R_MPI_Comm comm, int errorcode );
  
/* Keyval and Attr */
int R_PMPI_Keyval_create (R_MPI_Copy_function *, R_MPI_Delete_function *, int *, void *);
int R_PMPI_Keyval_free (int *);
int R_PMPI_Attr_put (R_MPI_Comm, int, void *);
int R_PMPI_Attr_get (R_MPI_Comm, int, void *, int *);
int R_PMPI_Attr_delete (R_MPI_Comm, int);
int R_PMPI_Attr_get_fortran(R_MPI_Comm comm, int keyval, int *attr_value,
                          int *flag);

/* Topology Management */
int R_PMPI_Topo_test (R_MPI_Comm, int *);

int R_PMPI_Dims_create (int, int, int *);

int R_PMPI_Graph_create (R_MPI_Comm, int, int *, int *, int, R_MPI_Comm *);
int R_PMPI_Graphdims_get (R_MPI_Comm, int *, int *);
int R_PMPI_Graph_get (R_MPI_Comm, int, int, int *, int *);
int R_PMPI_Graph_neighbors_count (R_MPI_Comm, int, int *);
int R_PMPI_Graph_neighbors (R_MPI_Comm, int, int, int *);
int R_PMPI_Graph_map (R_MPI_Comm, int, int *, int *, int *);  

int R_PMPI_Cart_create (R_MPI_Comm, int, int *, int *, int, R_MPI_Comm *);
int R_PMPI_Cart_get (R_MPI_Comm, int, int *, int *, int *);
int R_PMPI_Cart_rank (R_MPI_Comm, int *, int *);
int R_PMPI_Cart_coords (R_MPI_Comm, int, int, int *);
int R_PMPI_Cart_shift (R_MPI_Comm, int, int, int *, int *);
int R_PMPI_Cart_sub (R_MPI_Comm, int *, R_MPI_Comm *);
int R_PMPI_Cart_map (R_MPI_Comm, int, int *, int *, int *);
int R_PMPI_Cartdim_get (R_MPI_Comm, int *);

/* Getters */
int R_PMPI_Get_processor_name (char *, int *);
int R_PMPI_Get_version (int *, int *);
double R_PMPI_Wtime (void);
double R_PMPI_Wtick (void);
int R_PMPI_Query_thread (int *);

/* Profiling */
/* Note that we may need to define a @PCONTROL_LIST@ depending on whether
stdargs are supported */
int R_PMPI_Pcontrol (const int, ...);

/* Communicator Naming (MPI-2 functions) */
int R_PMPI_Comm_get_name (R_MPI_Comm, char *, int *);
int R_PMPI_Comm_set_name (R_MPI_Comm, char *);

/* Fortran Converters */
R_MPI_Comm R_PMPI_Comm_f2c(R_MPI_Fint comm);
R_MPI_Fint R_PMPI_Comm_c2f(R_MPI_Comm comm);
R_MPI_Datatype R_PMPI_Type_f2c(R_MPI_Fint datatype);
R_MPI_Fint R_PMPI_Type_c2f(R_MPI_Datatype datatype);
R_MPI_Group R_PMPI_Group_f2c(R_MPI_Fint group);
R_MPI_Fint R_PMPI_Group_c2f(R_MPI_Group group);
R_MPI_Request R_PMPI_Request_f2c(R_MPI_Fint request);
R_MPI_Fint R_PMPI_Request_c2f(R_MPI_Request request);
R_MPI_Win R_PMPI_Win_f2c(R_MPI_Fint win);
R_MPI_Fint R_PMPI_Win_c2f(R_MPI_Win win);
R_MPI_Op R_PMPI_Op_f2c(R_MPI_Fint op);
R_MPI_Fint R_PMPI_Op_c2f(R_MPI_Op op);
R_MPI_Info R_PMPI_Info_f2c(R_MPI_Fint info);
R_MPI_Fint R_PMPI_Info_c2f(R_MPI_Info info);
R_MPI_Errhandler R_PMPI_Errhandler_f2c(R_MPI_Fint errhandler);
R_MPI_Fint R_PMPI_Errhandler_c2f(R_MPI_Errhandler errhandler);
  
/* Neighbors collectives */
int R_PMPI_Neighbor_allgather(void *sendbuf, int sendcount, R_MPI_Datatype sendtype, void *recvbuf, int recvcount, R_MPI_Datatype recvtype, R_MPI_Comm comm);
int R_PMPI_Neighbor_allgatherv(void *sendbuf, int sendcount, R_MPI_Datatype sendtype, void *recvbuf, int recvcounts[], int displs[], R_MPI_Datatype recvtype, R_MPI_Comm comm);
int R_PMPI_Neighbor_alltoall(void *sendbuf, int sendcount, R_MPI_Datatype sendtype, void *recvbuf, int recvcount, R_MPI_Datatype recvtype, R_MPI_Comm comm);
int R_PMPI_Neighbor_alltoallv(void *sendbuf, int sendcounts[], int sdispls[], R_MPI_Datatype sendtype, void *recvbuf, int recvcounts[], int rdispls[], R_MPI_Datatype recvtype, R_MPI_Comm comm);
int R_PMPI_Neighbor_alltoallw(void *sendbuf, int sendcounts[], R_MPI_Aint sdispls[], R_MPI_Datatype sendtypes[], void *recvbuf, int recvcounts[], R_MPI_Aint rdispls[], R_MPI_Datatype recvtypes[], R_MPI_Comm comm);

/* MPI Info Management */
int R_PMPI_Info_set( R_MPI_Info, const char *, const char * );
int R_PMPI_Info_free( R_MPI_Info * );
int R_PMPI_Info_create( R_MPI_Info * );
int R_PMPI_Info_delete( R_MPI_Info , const char * );
int R_PMPI_Info_get(R_MPI_Info , const char *, int , char *, int *);
int R_PMPI_Info_dup( R_MPI_Info , R_MPI_Info * );
int R_PMPI_Info_get_nkeys (R_MPI_Info, int *);
int R_PMPI_Info_get_nthkey (R_MPI_Info, int, char *);
int R_PMPI_Info_get_valuelen (R_MPI_Info, char *, int *, int *);

/* Generalized Requests */
int R_PMPI_Grequest_start( R_MPI_Grequest_query_function *query_fn,
			R_MPI_Grequest_free_function * free_fn,
			R_MPI_Grequest_cancel_function * cancel_fn,
			void *extra_state,
			R_MPI_Request * request);
int R_PMPI_Grequest_complete(  R_MPI_Request request); 

/* Extended Generalized Requests */
int R_PMPIX_Grequest_start(R_MPI_Grequest_query_function *query_fn,
			R_MPI_Grequest_free_function * free_fn,
			R_MPI_Grequest_cancel_function * cancel_fn, 
			R_MPIX_Grequest_poll_fn * poll_fn, 
			void *extra_state, 
			R_MPI_Request * request);

/* Extended Generalized Request Class */
int R_PMPIX_Grequest_class_create( R_MPI_Grequest_query_function * query_fn,
				R_MPI_Grequest_free_function * free_fn,
				R_MPI_Grequest_cancel_function * cancel_fn,
				R_MPIX_Grequest_poll_fn * poll_fn,
				R_MPIX_Grequest_wait_fn * wait_fn,
				R_MPIX_Grequest_class * new_class );
int R_PMPIX_Grequest_class_allocate( R_MPIX_Grequest_class  target_class, void *extra_state, R_MPI_Request *request );

/* Dummy One-Sided Communications */

int R_PMPI_Free_mem (void *ptr);
int R_PMPI_Alloc_mem(R_MPI_Aint size, R_MPI_Info info, void *baseptr);


/* Halo */

int R_PMPIX_Halo_cell_init( R_MPI_Halo * halo, char * label, R_MPI_Datatype type, int count );
int R_PMPIX_Halo_cell_release( R_MPI_Halo * halo );

int R_PMPIX_Halo_cell_set( R_MPI_Halo halo, void * ptr );
int R_PMPIX_Halo_cell_get( R_MPI_Halo halo, void ** ptr );

/* Halo Exchange */

int R_PMPIX_Halo_exchange_init( R_MPI_Halo_exchange * ex );
int R_PMPIX_Halo_exchange_release( R_MPI_Halo_exchange * ex );

int R_PMPIX_Halo_exchange_commit( R_MPI_Halo_exchange ex );
int R_PMPIX_Halo_exchange( R_MPI_Halo_exchange ex );
int R_PMPIX_Halo_iexchange( R_MPI_Halo_exchange ex );
int R_PMPIX_Halo_iexchange_wait( R_MPI_Halo_exchange ex );
int R_PMPIX_Halo_cell_bind_local( R_MPI_Halo_exchange ex, R_MPI_Halo halo );
int R_PMPIX_Halo_cell_bind_remote( R_MPI_Halo_exchange ex, R_MPI_Halo halo, int remote, char * remote_label );

/* This is the MPI Tools Interface */

int R_PMPI_T_init_thread(int required, int *provided);
int R_PMPI_T_finalize(void);
int R_PMPI_T_enum_get_info(R_MPI_T_enum enumtype, int *num, char *name,
                         int *name_len);
int R_PMPI_T_enum_get_item(R_MPI_T_enum enumtype, int index, int *value, char *name,
                         int *name_len);
int R_PMPI_T_cvar_get_num(int *num_cvar);
int R_PMPI_T_cvar_get_info(int cvar_index, char *name, int *name_len,
                         int *verbosity, R_MPI_Datatype *datatype,
                         R_MPI_T_enum *enumtype, char *desc, int *desc_len,
                         int *bind, int *scope);
int R_PMPI_T_cvar_get_index(const char *name, int *cvar_index);
int R_PMPI_T_cvar_handle_alloc(int cvar_index, void *obj_handle,
                             R_MPI_T_cvar_handle *handle, int *count);
int R_PMPI_T_cvar_handle_free(R_MPI_T_cvar_handle *handle);
int R_PMPI_T_cvar_read(R_MPI_T_cvar_handle handle, void *buff);
int R_PMPI_T_cvar_write(R_MPI_T_cvar_handle handle, const void *buff);
int R_PMPI_T_pvar_get_num(int *num_pvar);
int R_PMPI_T_pvar_get_info(int pvar_index, char *name, int *name_len,
                         int *verbosity, int *var_class, R_MPI_Datatype *datatype,
                         R_MPI_T_enum *enumtype, char *desc, int *desc_len,
                         int *bind, int *readonly, int *continuous,
                         int *atomic);
int R_PMPI_T_pvar_get_index(char *name, int *pvar_class, int *pvar_index);
int R_PMPI_T_pvar_session_create(R_MPI_T_pvar_session *session);
int R_PMPI_T_pvar_session_free(R_MPI_T_pvar_session *session);
int R_PMPI_T_pvar_handle(R_MPI_T_pvar_session session, int pvar_index,
                       void *obj_handle, R_MPI_T_pvar_handle *handle, int *count);

int R_PMPI_T_pvar_handle_free(R_MPI_T_pvar_session session,
                            R_MPI_T_pvar_handle *handle);
int R_PMPI_T_pvar_start(R_MPI_T_pvar_session session, R_MPI_T_pvar_handle handle);
int R_PMPI_T_pvar_stop(R_MPI_T_pvar_session session, R_MPI_T_pvar_handle handle);
int R_PMPI_T_pvar_read(R_MPI_T_pvar_session session, R_MPI_T_pvar_handle handle,
                     void *buff);
int R_PMPI_T_pvar_readreset(R_MPI_T_pvar_session session, R_MPI_T_pvar_handle handle,
                          void *buff);
int R_PMPI_T_pvar_write(R_MPI_T_pvar_session session, R_MPI_T_pvar_handle handle,
                      const void *buff);
int R_PMPI_T_pvar_reset(R_MPI_T_pvar_session session, R_MPI_T_pvar_handle handle);
int R_PMPI_T_category_get_num(int *num_cat);
int R_PMPI_T_category_get_info(int cat_index, char *name, int *name_len,
                             char *desc, int *desc_len, int *num_cvars,
                             int *num_pvars, int *num_categories);
int R_PMPI_T_category_get_index(char *name, int *cat_index);
int R_PMPI_T_category_get_cvars(int cat_index, int len, int indices[]);
int R_PMPI_T_category_get_pvars(int cat_index, int len, int indices[]);
int R_PMPI_T_category_get_categories(int cat_index, int len, int indices[]);
int R_PMPI_T_category_changed(int *stamp);

/* probe and cancel */
int R_PMPI_Mprobe(int, int, R_MPI_Comm, R_MPI_Message *, R_MPI_Status *);
int R_PMPI_Mrecv(void *, int, R_MPI_Datatype, R_MPI_Message *, R_MPI_Status *);
int R_PMPI_Imrecv(void *, int, R_MPI_Datatype, R_MPI_Message *, R_MPI_Request *);
int R_PMPI_Improbe(int, int, R_MPI_Comm, int *, R_MPI_Message *, R_MPI_Status *);

/* One-Sided Communications */
int R_PMPI_Win_set_attr(R_MPI_Win, int, void *);
int R_PMPI_Win_get_attr(R_MPI_Win, int, void *, int *);
int R_PMPI_Win_free_keyval(int *);
int R_PMPI_Win_delete_attr(R_MPI_Win, int);
int R_PMPI_Win_create_keyval(R_MPI_Win_copy_attr_function *,
                           R_MPI_Win_delete_attr_function *, int *, void *);
int R_PMPI_Win_create(void *, R_MPI_Aint, int, R_MPI_Info, R_MPI_Comm, R_MPI_Win *);
int R_PMPI_Win_free(R_MPI_Win *);
int R_PMPI_Win_wait(R_MPI_Win);
int R_PMPI_Accumulate(const void *, int, R_MPI_Datatype, int, R_MPI_Aint, int,
                    R_MPI_Datatype, R_MPI_Op, R_MPI_Win);
int R_PMPI_Get(void *, int, R_MPI_Datatype, int, R_MPI_Aint, int, R_MPI_Datatype,
             R_MPI_Win);
int R_PMPI_Put(const void *, int, R_MPI_Datatype, int, R_MPI_Aint, int, R_MPI_Datatype,
             R_MPI_Win);
int R_PMPI_Win_complete(R_MPI_Win);
int R_PMPI_Win_fence(int, R_MPI_Win);
int R_PMPI_Win_get_group(R_MPI_Win, R_MPI_Group *);
int R_PMPI_Win_lock(int, int, int, R_MPI_Win);
int R_PMPI_Win_post(R_MPI_Group, int, R_MPI_Win);
int R_PMPI_Win_start(R_MPI_Group, int, R_MPI_Win);
int R_PMPI_Win_test(R_MPI_Win, int *);
int R_PMPI_Win_unlock(int, R_MPI_Win);
int R_PMPI_Win_allocate(R_MPI_Aint, int, R_MPI_Info, R_MPI_Comm, void *, R_MPI_Win *);
int R_PMPI_Win_set_name(R_MPI_Win, const char *);
int R_PMPI_Win_get_name(R_MPI_Win, char *, int *);
int R_PMPI_Win_set_errhandler(R_MPI_Win, R_MPI_Errhandler);
int R_PMPI_Win_get_errhandler(R_MPI_Win, R_MPI_Errhandler *);
int R_PMPI_Win_call_errhandler(R_MPI_Win win, int errorcode);
int R_PMPI_Win_allocate_shared(R_MPI_Aint, int, R_MPI_Info, R_MPI_Comm, void *,
                             R_MPI_Win *);
int R_PMPI_Win_create_errhandler(R_MPI_Win_errhandler_function *, R_MPI_Errhandler *);
int R_PMPI_Win_create_dynamic(R_MPI_Info, R_MPI_Comm, R_MPI_Win *);
int R_PMPI_Win_shared_query(R_MPI_Win, int, R_MPI_Aint *, int *, void *);
int R_PMPI_Win_lock_all(int, R_MPI_Win);
int R_PMPI_Win_unlock_all(R_MPI_Win win);
int R_PMPI_Win_sync(R_MPI_Win win);
int R_PMPI_Win_attach(R_MPI_Win, void *, R_MPI_Aint);
int R_PMPI_Win_detach(R_MPI_Win, const void *);
int R_PMPI_Win_flush(int, R_MPI_Win);
int R_PMPI_Win_flush_all(R_MPI_Win);
int R_PMPI_Win_set_info(R_MPI_Win, R_MPI_Info);
int R_PMPI_Win_get_info(R_MPI_Win, R_MPI_Info *);
int R_PMPI_Get_accumulate(const void *, int, R_MPI_Datatype, void *, int,
                        R_MPI_Datatype, int, R_MPI_Aint, int, R_MPI_Datatype, R_MPI_Op,
                        R_MPI_Win);
int R_PMPI_Fetch_and_op(const void *, void *, R_MPI_Datatype, int, R_MPI_Aint, R_MPI_Op,
                      R_MPI_Win);
int R_PMPI_Compare_and_swap(const void *, const void *, void *, R_MPI_Datatype, int,
                          R_MPI_Aint, R_MPI_Win);
int R_PMPI_Rput(const void *, int, R_MPI_Datatype, int, R_MPI_Aint, int, R_MPI_Datatype,
              R_MPI_Win, R_MPI_Request *);
int R_PMPI_Rget(void *, int, R_MPI_Datatype, int, R_MPI_Aint, int, R_MPI_Datatype,
              R_MPI_Win, R_MPI_Request *);
int R_PMPI_Raccumulate(const void *, int, R_MPI_Datatype, int, R_MPI_Aint, int,
                     R_MPI_Datatype, R_MPI_Op, R_MPI_Win, R_MPI_Request *);
int R_PMPI_Rget_accumulate(const void *, int, R_MPI_Datatype, void *, int,
                         R_MPI_Datatype, int, R_MPI_Aint, int, R_MPI_Datatype, R_MPI_Op,
                         R_MPI_Win, R_MPI_Request *);

#endif /* R_MPI_BUILD_PROFILING */

/************************************************************************/
/*  NOT IMPLEMENTED                                                     */
/************************************************************************/

/* Datatype Handling & Packs */
int R_MPI_Type_dup(R_MPI_Datatype , R_MPI_Datatype *);
int R_MPI_Type_get_name(R_MPI_Datatype , char *, int *);
int R_MPI_Type_create_resized (R_MPI_Datatype, R_MPI_Aint , R_MPI_Aint , R_MPI_Datatype *);
int R_MPI_Type_get_true_extent(R_MPI_Datatype , R_MPI_Aint *, R_MPI_Aint *);
int R_MPI_Type_get_extent(R_MPI_Datatype , R_MPI_Aint *, R_MPI_Aint *);
int R_MPI_Type_free_keyval (int *);
int R_MPI_Type_create_keyval (R_MPI_Type_copy_attr_function *, R_MPI_Type_delete_attr_function *, int *, void *);
int R_MPI_Type_delete_attr (R_MPI_Datatype, int);
int R_MPI_Type_set_attr (R_MPI_Datatype, int, void *);
int R_MPI_Type_get_attr (R_MPI_Datatype, int, void *, int *);
int R_MPI_Type_create_indexed_block (int, int, int *, R_MPI_Datatype, R_MPI_Datatype *);
int R_MPI_Type_get_envelope (R_MPI_Datatype, int *, int *, int *, int *);
int R_MPI_Type_get_contents (R_MPI_Datatype, int, int, int, int *, R_MPI_Aint *, R_MPI_Datatype *);

int R_MPI_Get_address (void *, R_MPI_Aint *);
int R_MPI_Type_size_x(R_MPI_Datatype , R_MPI_Count *);
int R_MPI_Type_get_extent_x(R_MPI_Datatype , R_MPI_Count *, R_MPI_Count *);
int R_MPI_Type_get_true_extent_x(R_MPI_Datatype , R_MPI_Count *, R_MPI_Count *);
int R_MPI_Type_match_size (int, int, R_MPI_Datatype *);


/* Communicator Management */
int R_MPI_Comm_set_errhandler(R_MPI_Comm , R_MPI_Errhandler );
int R_MPI_Comm_free_keyval (int *);
int R_MPI_Comm_delete_attr (R_MPI_Comm, int);
int R_MPI_Comm_call_errhandler (R_MPI_Comm, int);
int R_MPI_Comm_create_keyval (R_MPI_Comm_copy_attr_function *, R_MPI_Comm_delete_attr_function *, int *, void *);
int R_MPI_Comm_delete_attr (R_MPI_Comm, int);
int R_MPI_Comm_get_attr (R_MPI_Comm, int, void *, int *);
int R_MPI_Comm_set_attr (R_MPI_Comm, int, void *);
int R_MPI_Comm_dup_with_info(R_MPI_Comm , R_MPI_Info , R_MPI_Comm * );
int R_MPI_Comm_split_type(R_MPI_Comm , int , int , R_MPI_Info , R_MPI_Comm * );
int R_MPI_Comm_set_info(R_MPI_Comm , R_MPI_Info );
int R_MPI_Comm_get_info(R_MPI_Comm , R_MPI_Info * );
int R_MPI_Comm_call_errhandler (R_MPI_Comm, int);
int R_MPI_Comm_get_errhandler(R_MPI_Comm , R_MPI_Errhandler *);
int R_MPI_Comm_create_errhandler (R_MPI_Comm_errhandler_fn *, R_MPI_Errhandler *);
int R_MPI_Comm_idup(R_MPI_Comm comm, R_MPI_Comm *newcomm, R_MPI_Request *request);
int R_MPI_Comm_create_group(R_MPI_Comm , R_MPI_Group , int , R_MPI_Comm * );
int R_MPI_Comm_set_errhandler(R_MPI_Comm , R_MPI_Errhandler );

/* Process Creation and Management */
int R_MPI_Close_port (char *);
int R_MPI_Comm_accept (char *, R_MPI_Info, int, R_MPI_Comm, R_MPI_Comm *);
int R_MPI_Comm_connect(char *, R_MPI_Info , int , R_MPI_Comm , R_MPI_Comm *);
int R_MPI_Comm_disconnect (R_MPI_Comm *);
int R_MPI_Comm_get_parent (R_MPI_Comm *);
int R_MPI_Comm_join (int, R_MPI_Comm *);
int R_MPI_Comm_spawn (char *, char *[], int, R_MPI_Info, int, R_MPI_Comm, R_MPI_Comm *, int[]);
int R_MPI_Comm_spawn_multiple (int, char *[], char **[], int[], R_MPI_Info[], int, R_MPI_Comm, R_MPI_Comm *, int[]);
int R_MPI_Lookup_name(char *, R_MPI_Info , char *);
int R_MPI_Open_port (R_MPI_Info, char *);
int R_MPI_Publish_name (char *, R_MPI_Info, char *);
int R_MPI_Unpublish_name (char *, R_MPI_Info, char *);
  
/* Error Management */
int R_MPI_Add_error_class (int *);
int R_MPI_Add_error_code (int, int *);
int R_MPI_Add_error_string (int, char *);

/* Getters */
int R_MPI_Is_thread_main (int *);
int R_MPI_Query_thread (int *);
int R_MPI_Get_library_version(char *, int *);
  
/* Collectives */
int R_MPI_Reduce_scatter_block(void *, void *, int , R_MPI_Datatype , R_MPI_Op , R_MPI_Comm );
int R_MPI_Reduce_local(void *, void *, int, R_MPI_Datatype, R_MPI_Op);

/* Extended Collective Operations */
int R_MPI_Alltoallw (void *, int[], int[], R_MPI_Datatype[], void *, int[], int[], R_MPI_Datatype[], R_MPI_Comm);

/* dist graph operations */
int R_MPI_Dist_graph_neighbors_count(R_MPI_Comm , int *, int *, int *);
int R_MPI_Dist_graph_neighbors(R_MPI_Comm , int , int [], int [], int , int [], int []);
int R_MPI_Dist_graph_create(R_MPI_Comm , int , int [], int [], int [],int [],R_MPI_Info , int , R_MPI_Comm *);
int R_MPI_Dist_graph_create_adjacent(R_MPI_Comm ,int , int [], int [],int , int [], int [],R_MPI_Info , int , R_MPI_Comm *);

/* MPIX methods */
int R_MPIX_Comm_failure_ack( R_MPI_Comm  );
int R_MPIX_Comm_failure_get_acked( R_MPI_Comm , R_MPI_Group * );
int R_MPIX_Comm_agree(R_MPI_Comm , int *);
int R_MPIX_Comm_revoke(R_MPI_Comm );
int R_MPIX_Comm_shrink(R_MPI_Comm , R_MPI_Comm *);

/* probe and cancel */
int R_MPI_Mprobe(int , int , R_MPI_Comm , R_MPI_Message *, R_MPI_Status *);
int R_MPI_Mrecv(void *, int , R_MPI_Datatype , R_MPI_Message *, R_MPI_Status *);
int R_MPI_Imrecv(void *, int , R_MPI_Datatype , R_MPI_Message *, R_MPI_Request *);
int R_MPI_Improbe(int , int , R_MPI_Comm , int *, R_MPI_Message *, R_MPI_Status *);
/************************************************************************/
/* END NOT IMPLEMENTED                                                     */
/************************************************************************/


/* For ROMIO compatibility */
#define MPICH_ATTR_POINTER_WITH_TYPE_TAG(a,b) 
#define R_MPI_AINT_FMT_HEX_SPEC "%X"

#ifdef __cplusplus
}
#endif
#endif /* __SCTK_MPC_MPI_H_ */
#include "run_mpio.h"

#ifndef R_MPI_FILE_DEFINED
typedef struct ADIOI_FileD *R_MPI_File;
#endif
/* Error handling */
int R_MPI_File_create_errhandler(R_MPI_File_errhandler_function *, R_MPI_Errhandler *);
int R_PMPI_File_create_errhandler(R_MPI_File_errhandler_function *file_errhandler_fn, R_MPI_Errhandler *errhandler);
int R_MPI_File_call_errhandler(R_MPI_File fh , int );

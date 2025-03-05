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

#define MPI_VERSION    3
#define MPI_SUBVERSION    1

#define MPI_CART (-2)
#define MPI_GRAPH (-3)
#define MPI_DIST_GRAPH (-4)

/* Results of the compare operations. */
#define MPI_IDENT     0
#define MPI_CONGRUENT 1
#define MPI_SIMILAR   2
#define MPI_UNEQUAL   3

#define MPI_LOCK_EXCLUSIVE  234
#define MPI_LOCK_SHARED     235

/* Other constants */
#define MPI_UNWEIGHTED ((void *) 2)
#define MPI_WEIGHTS_EMPTY ((void *) 3)

/************************************************************************/
/* MPI_* to MPC_* converters                                            */
/************************************************************************/

/* Misc */
#define MPI_MAX_PROCESSOR_NAME MPC_MAX_PROCESSOR_NAME
#define MPI_MAX_NAME_STRING MPC_MAX_OBJECT_NAME
#define MPI_MAX_OBJECT_NAME MPC_MAX_OBJECT_NAME
#define MPI_MAX_LIBRARY_VERSION_STRING MPC_MAX_LIBRARY_VERSION_STRING
/* Communication Parameters */
#define MPI_SOURCE MPC_SOURCE
#define MPI_TAG MPC_TAG
#define MPI_UNDEFINED MPC_UNDEFINED
#define MPI_REQUEST_NULL ((MPI_Request)-1)
#define MPI_COMM_WORLD MPC_COMM_WORLD
#define MPI_STATUS_IGNORE MPC_STATUS_IGNORE
#define MPI_STATUSES_IGNORE MPC_STATUSES_IGNORE
#define MPI_ANY_TAG MPC_ANY_TAG
#define MPI_ANY_SOURCE MPC_ANY_SOURCE
#define MPI_PROC_NULL MPC_PROC_NULL
#define MPI_COMM_NULL MPC_COMM_NULL
#define MPI_ROOT MPC_ROOT
#define MPI_IN_PLACE MPC_IN_PLACE
#define MPI_BOTTOM MPC_BOTTOM
#define MPI_COMM_SELF MPC_COMM_SELF

/* Error Handling */
#define MPI_SUCCESS MPC_SUCCESS
#define MPI_ERROR MPC_ERROR
#define MPI_MAX_ERROR_STRING MPC_MAX_ERROR_STRING
#define MPI_ERR_BUFFER MPC_ERR_BUFFER
#define MPI_ERR_COUNT MPC_ERR_COUNT
#define MPI_ERR_TYPE MPC_ERR_TYPE
#define MPI_ERR_TAG MPC_ERR_TAG
#define MPI_ERR_COMM MPC_ERR_COMM
#define MPI_ERR_RANK MPC_ERR_RANK
#define MPI_ERR_REQUEST MPC_ERR_REQUEST
#define MPI_ERR_ROOT MPC_ERR_ROOT
#define MPI_ERR_GROUP MPC_ERR_GROUP
#define MPI_ERR_OP MPC_ERR_OP
#define MPI_ERR_TOPOLOGY MPC_ERR_TOPOLOGY
#define MPI_ERR_DIMS MPC_ERR_DIMS
#define MPI_ERR_ARG MPC_ERR_ARG
#define MPI_ERR_UNKNOWN MPC_ERR_UNKNOWN
#define MPI_ERR_TRUNCATE MPC_ERR_TRUNCATE
#define MPI_ERR_OTHER MPC_ERR_OTHER
#define MPI_ERR_INTERN MPC_ERR_INTERN
#define MPI_ERR_IN_STATUS MPC_ERR_IN_STATUS
#define MPI_ERR_PENDING MPC_ERR_PENDING
#define MPI_ERR_KEYVAL MPC_ERR_KEYVAL
#define MPI_ERR_NO_MEM MPC_ERR_NO_MEM
#define MPI_ERR_BASE MPC_ERR_BASE
#define MPI_ERR_INFO_KEY MPC_ERR_INFO_KEY
#define MPI_ERR_INFO_VALUE MPC_ERR_INFO_VALUE
#define MPI_ERR_INFO_NOKEY MPC_ERR_INFO_NOKEY
#define MPI_ERR_SPAWN MPC_ERR_SPAWN
#define MPI_ERR_PORT MPC_ERR_PORT
#define MPI_ERR_SERVICE MPC_ERR_SERVICE
#define MPI_ERR_NAME MPC_ERR_NAME
#define MPI_ERR_WIN MPC_ERR_WIN
#define MPI_ERR_SIZE MPC_ERR_SIZE
#define MPI_ERR_DISP MPC_ERR_DISP
#define MPI_ERR_INFO MPC_ERR_INFO
#define MPI_ERR_LOCKTYPE MPC_ERR_LOCKTYPE
#define MPI_ERR_ASSERT MPC_ERR_ASSERT
#define MPI_ERR_RMA_CONFLICT MPC_ERR_RMA_CONFLICT
#define MPI_ERR_RMA_SYNC MPC_ERR_RMA_SYNC
#define MPI_ERR_RMA_FLAVOR MPC_ERR_RMA_FLAVOR
#define MPI_ERR_FILE MPC_ERR_FILE
#define MPI_ERR_NOT_SAME MPC_ERR_NOT_SAME
#define MPI_ERR_AMODE MPC_ERR_AMODE
#define MPI_ERR_UNSUPPORTED_DATAREP MPC_ERR_UNSUPPORTED_DATAREP
#define MPI_ERR_UNSUPPORTED_OPERATION MPC_ERR_UNSUPPORTED_OPERATION
#define MPI_ERR_NO_SUCH_FILE MPC_ERR_NO_SUCH_FILE
#define MPI_ERR_FILE_EXISTS MPC_ERR_FILE_EXISTS
#define MPI_ERR_BAD_FILE MPC_ERR_BAD_FILE
#define MPI_ERR_ACCESS MPC_ERR_ACCESS
#define MPI_ERR_NO_SPACE MPC_ERR_NO_SPACE
#define MPI_ERR_QUOTA MPC_ERR_QUOTA
#define MPI_ERR_READ_ONLY MPC_ERR_READ_ONLY
#define MPI_ERR_FILE_IN_USE MPC_ERR_FILE_IN_USE
#define MPI_ERR_DUP_DATAREP MPC_ERR_DUP_DATAREP
#define MPI_ERR_CONVERSION MPC_ERR_CONVERSION
#define MPI_ERR_IO MPC_ERR_IO
#define MPI_ERR_LASTCODE MPC_ERR_LASTCODE
#define MPI_NOT_IMPLEMENTED MPC_NOT_IMPLEMENTED
#define MPIR_ERRORS_THROW_EXCEPTIONS MPCR_ERRORS_THROW_EXCEPTIONS
/* MPI_T Errors */
#define MPI_T_ERR_MEMORY MPC_T_ERR_MEMORY
#define MPI_T_ERR_NOT_INITIALIZED MPC_T_ERR_NOT_INITIALIZED
#define MPI_T_ERR_CANNOT_INIT MPC_T_ERR_CANNOT_INIT
#define MPI_T_ERR_INVALID_INDEX MPC_T_ERR_INVALID_INDEX
#define MPI_T_ERR_INVALID_ITEM MPC_T_ERR_INVALID_ITEM
#define MPI_T_ERR_INVALID_HANDLE MPC_T_ERR_INVALID_HANDLE
#define MPI_T_ERR_OUT_OF_HANDLES MPC_T_ERR_OUT_OF_HANDLES
#define MPI_T_ERR_OUT_OF_SESSIONS MPC_T_ERR_OUT_OF_SESSIONS
#define MPI_T_ERR_INVALID_SESSION MPC_T_ERR_INVALID_SESSION
#define MPI_T_ERR_CVAR_SET_NOT_NOW MPC_T_ERR_CVAR_SET_NOT_NOW
#define MPI_T_ERR_CVAR_SET_NEVER MPC_T_ERR_CVAR_SET_NEVER
#define MPI_T_ERR_PVAR_NO_STARTSTOP MPC_T_ERR_PVAR_NO_STARTSTOP
#define MPI_T_ERR_PVAR_NO_WRITE MPC_T_ERR_PVAR_NO_WRITE
#define MPI_T_ERR_PVAR_NO_ATOMIC MPC_T_ERR_PVAR_NO_ATOMIC
#define MPI_T_ERR_INVALID_NAME MPC_T_ERR_INVALID_NAME

/* Data-type Handling */
#define MPI_DATATYPE_NULL MPC_DATATYPE_NULL
#define MPI_UB MPC_UB
#define MPI_LB MPC_LB
#define MPI_CHAR MPC_CHAR
#define MPI_BYTE MPC_BYTE
#define MPI_SHORT MPC_SHORT
#define MPI_INT MPC_INT

/* Support for MPI_INTEGER */
#define MPI_INTEGER MPC_INTEGER
#ifndef NOHAVE_ASSERT_H
#define MPI_INTEGER1 MPC_INTEGER1
#define MPI_INTEGER2 MPC_INTEGER2
#define MPI_INTEGER4 MPC_INTEGER4
#define MPI_INTEGER8 MPC_INTEGER8
#endif

/* Basic data-types */
#define MPI_LONG MPC_LONG
#define MPI_LONG_INT MPC_LONG_INT
#define MPI_FLOAT MPC_FLOAT
#define MPI_DOUBLE MPC_DOUBLE
#define MPI_UNSIGNED_CHAR MPC_UNSIGNED_CHAR
#define MPI_UNSIGNED_SHORT MPC_UNSIGNED_SHORT
#define MPI_UNSIGNED MPC_UNSIGNED
#define MPI_UNSIGNED_LONG MPC_UNSIGNED_LONG
#define MPI_LONG_DOUBLE MPC_LONG_DOUBLE
#define MPI_LONG_LONG_INT MPC_LONG_LONG_INT
#define MPI_LONG_LONG MPC_LONG_LONG
#define MPI_UNSIGNED_LONG_LONG_INT MPC_UNSIGNED_LONG_LONG_INT
#define MPI_UNSIGNED_LONG_LONG MPC_UNSIGNED_LONG_LONG
#define MPI_PACKED MPC_PACKED
#define MPI_FLOAT_INT MPC_FLOAT_INT
#define MPI_DOUBLE_INT MPC_DOUBLE_INT
#define MPI_LONG_DOUBLE_INT MPC_LONG_DOUBLE_INT
#define MPI_SHORT_INT MPC_SHORT_INT
#define MPI_2INT MPC_2INT
#define MPI_2FLOAT MPC_2FLOAT
#define MPI_COMPLEX MPC_COMPLEX
#define MPI_DOUBLE_COMPLEX MPC_DOUBLE_COMPLEX
#define MPI_2DOUBLE_PRECISION MPC_2DOUBLE_PRECISION
#define MPI_LOGICAL MPC_LOGICAL
#define MPI_REAL4 MPC_REAL4
#define MPI_REAL8 MPC_REAL8
#define MPI_REAL16 MPC_REAL16
#define MPI_SIGNED_CHAR MPC_SIGNED_CHAR
#define MPI_LONG_DOUBLE_INT MPC_LONG_DOUBLE_INT
#define MPI_REAL MPC_REAL
#define MPI_INT8_T MPC_INT8_T
#define MPI_UINT8_T MPC_UINT8_T
#define MPI_INT16_T MPC_INT16_T
#define MPI_UINT16_T MPC_UINT16_T
#define MPI_INT32_T MPC_INT32_T
#define MPI_UINT32_T MPC_UINT32_T
#define MPI_INT64_T MPC_INT64_T
#define MPI_UINT64_T MPC_UINT64_T
#define MPI_COMPLEX8 MPC_COMPLEX8
#define MPI_COMPLEX16 MPC_COMPLEX16
#define MPI_COMPLEX32 MPC_COMPLEX32
#define MPI_WCHAR MPC_WCHAR
#define MPI_INTEGER16 MPC_INTEGER16
#define MPI_AINT MPC_AINT
#define MPI_OFFSET MPC_OFFSET
#define MPI_COUNT MPC_COUNT
#define MPI_C_BOOL MPC_C_BOOL
#define MPI_C_COMPLEX MPC_C_COMPLEX
#define MPI_C_FLOAT_COMPLEX MPC_C_FLOAT_COMPLEX
#define MPI_C_DOUBLE_COMPLEX MPC_C_DOUBLE_COMPLEX
#define MPI_C_LONG_DOUBLE_COMPLEX MPC_C_LONG_DOUBLE_COMPLEX
#define MPI_CHARACTER MPC_CHARACTER
#define MPI_DOUBLE_PRECISION MPC_DOUBLE_PRECISION

#define MPI_2INTEGER MPC_2INTEGER
#define MPI_2REAL MPC_2REAL
/* Datatype decoders */

#define MPI_COMBINER_UNKNOWN MPC_COMBINER_UNKNOWN
#define MPI_COMBINER_NAMED MPC_COMBINER_NAMED
#define MPI_COMBINER_DUP MPC_COMBINER_DUP
#define MPI_COMBINER_CONTIGUOUS MPC_COMBINER_CONTIGUOUS
#define MPI_COMBINER_VECTOR MPC_COMBINER_VECTOR
#define MPI_COMBINER_HVECTOR MPC_COMBINER_HVECTOR
#define MPI_COMBINER_INDEXED MPC_COMBINER_INDEXED
#define MPI_COMBINER_HINDEXED MPC_COMBINER_HINDEXED
#define MPI_COMBINER_INDEXED_BLOCK MPC_COMBINER_INDEXED_BLOCK
#define MPI_COMBINER_HINDEXED_BLOCK MPC_COMBINER_HINDEXED_BLOCK
#define MPI_COMBINER_STRUCT MPC_COMBINER_STRUCT
#define MPI_COMBINER_SUBARRAY MPC_COMBINER_SUBARRAY
#define MPI_COMBINER_DARRAY MPC_COMBINER_DARRAY
#define MPI_COMBINER_F90_REAL MPC_COMBINER_F90_REAL
#define MPI_COMBINER_F90_COMPLEX MPC_COMBINER_F90_COMPLEX
#define MPI_COMBINER_F90_INTEGER MPC_COMBINER_F90_INTEGER
#define MPI_COMBINER_RESIZED MPC_COMBINER_RESIZED

/* Predefined MPI datatypes corresponding to both C and Fortran datatypes */

#define MPI_CXX_BOOL MPC_CXX_BOOL
#define MPI_CXX_FLOAT_COMPLEX MPC_CXX_FLOAT_COMPLEX
#define MPI_CXX_DOUBLE_COMPLEX MPC_CXX_DOUBLE_COMPLEX
#define MPI_CXX_LONG_DOUBLE_COMPLEX MPC_CXX_LONG_DOUBLE_COMPLEX

/* These are deprecated MPI 1.0 constants in MPI 3.0
 * however they are never returned by get envelope but as ROMIO uses them */
 
#define MPI_COMBINER_HINDEXED_INTEGER MPC_COMBINER_HINDEXED_INTEGER
#define MPI_COMBINER_STRUCT_INTEGER MPC_COMBINER_STRUCT_INTEGER
#define MPI_COMBINER_HVECTOR_INTEGER MPC_COMBINER_HVECTOR_INTEGER


/************************************************************************/
/* MPI_* Defines                                                        */
/************************************************************************/

/* Data-type classes */
#define MPI_TYPECLASS_INTEGER 1
#define MPI_TYPECLASS_REAL 2
#define MPI_TYPECLASS_COMPLEX 3

/* Threading Level */
#define MPI_THREAD_SINGLE 0
#define MPI_THREAD_FUNNELED 1
#define MPI_THREAD_SERIALIZED 2
#define  MPI_THREAD_MULTIPLE 3

/* Basic Ops */
#define MPI_SUM 0
#define MPI_MAX 1
#define MPI_MIN 2
#define MPI_PROD 3
#define MPI_LAND 4
#define MPI_BAND 5
#define MPI_LOR 6
#define MPI_BOR 7
#define MPI_LXOR 8
#define MPI_BXOR 9
#define MPI_MINLOC 10
#define MPI_MAXLOC 11
#define MPI_REPLACE 13
#define MPI_NO_OP 14
#define MAX_MPI_DEFINED_OP 13
#define MPI_OP_NULL ((MPI_Op)-1)


/* Group Handling */
#define MPI_GROUP_EMPTY ((MPI_Group)0)
#define MPI_GROUP_NULL ((MPI_Group)-1)

/* MPI_Info definitions */
/* Matches the one of MPI_INFO_NULL @ mpc_mpi.h:207 */
#define MPI_INFO_NULL (-1)
#define MPI_INFO_ENV (0)
/* Maximum length for keys and values
* they are both defined for MPC and MPI variants */
/*1 MB */
#define MPI_MAX_INFO_VAL 1024
#define MPI_MAX_INFO_KEY 255

/* Other Null Handles */
#define MPI_WIN_NULL ((MPI_Win)-1)
#define MPI_MESSAGE_NULL ((MPI_Message) MPI_REQUEST_NULL)
#define MPI_MESSAGE_NO_PROC -2

#ifdef ROMIO_COMP
#define MPI_FILE_NULL ((void *)0)
#endif 

#define MPI_BSEND_OVERHEAD (2*sizeof(mpi_buffer_overhead_t))

#define MPI_ERRHANDLER_NULL MPC_ERRHANDLER_NULL
#define MPI_ERRORS_RETURN MPC_ERRORS_RETURN       /* 1234 in Fortran */
#define MPI_ERRORS_ARE_FATAL MPC_ERRORS_ARE_FATAL /* 1235 in Fortran */

#define MPI_KEYVAL_INVALID MPC_KEYVAL_INVALID

#define MPI_NULL_DELETE_FN ((MPI_Delete_function *)MPC_Mpi_null_delete_fn)
#define MPI_NULL_COPY_FN ((MPI_Copy_function *)MPC_Mpi_null_copy_fn)
#define MPI_DUP_FN ((MPI_Copy_function *)MPC_Mpi_dup_fn)

#define MPI_TYPE_NULL_DELETE_FN ((MPI_Delete_function *)MPC_Mpi_type_null_delete_fn)
#define MPI_TYPE_NULL_COPY_FN ((MPI_Copy_function *)MPC_Mpi_type_null_copy_fn)
#define MPI_TYPE_DUP_FN ((MPI_Copy_function *)MPC_Mpi_type_dup_fn)

#define MPI_COMM_NULL_DELETE_FN ((MPI_Delete_function *)MPC_Mpi_comm_null_delete_fn)
#define MPI_COMM_NULL_COPY_FN ((MPI_Copy_function *)MPC_Mpi_comm_null_copy_fn)
#define MPI_COMM_DUP_FN ((MPI_Copy_function *)MPC_Mpi_comm_dup_fn)

#define MPI_WIN_NULL_DELETE_FN ((MPI_Delete_function *)MPC_Mpi_win_null_delete_fn)
#define MPI_WIN_NULL_COPY_FN ((MPI_Copy_function *)MPC_Mpi_win_null_copy_fn)
#define MPI_WIN_DUP_FN ((MPI_Copy_function *)MPC_Mpi_win_dup_fn)

#define MPI_TAG_UB 0
#define MPI_HOST 1
#define MPI_IO 2
#define MPI_WTIME_IS_GLOBAL 3
#define MPI_APPNUM 4
#define MPI_UNIVERSE_SIZE 5
#define MPI_LASTUSEDCODE 6
#define MPI_MAX_KEY_DEFINED 7

/* In addition, there are 5 predefined window attributes that are
 *    defined for every window */
#define MPI_WIN_MODEL 0
#define MPI_WIN_BASE          1
#define MPI_WIN_SIZE          2
#define MPI_WIN_DISP_UNIT     3
#define MPI_WIN_CREATE_FLAVOR 4

/* Ordering defines */
#define MPI_DISTRIBUTE_DFLT_DARG 100
#define MPI_DISTRIBUTE_BLOCK 101
#define MPI_DISTRIBUTE_CYCLIC 102
#define MPI_DISTRIBUTE_NONE 1

#define MPI_ORDER_C 200
#define MPI_ORDER_FORTRAN 201

/* Halo */
#define MPI_HALO_NULL (-1)

/* for comm_split method */
#define MPI_COMM_TYPE_SHARED MPC_COMM_TYPE_SHARED
#define MPI_COMM_TYPE_SHARED_TR MPC_COMM_TYPE_SHARED_TR
#define MPI_COMM_TYPE_SOCKET MPC_COMM_TYPE_SOCKET
#define MPI_COMM_TYPE_SOCKET_TR MPC_COMM_TYPE_SOCKET_TR
#define MPI_COMM_TYPE_NUMA MPC_COMM_TYPE_NUMA
#define MPI_COMM_TYPE_NUMA_TR MPC_COMM_TYPE_NUMA_TR
#define MPI_COMM_TYPE_MPC_PROCESS MPC_COMM_TYPE_MPC_PROCESS
#define MPI_COMM_TYPE_MPC_PROCESS_TR MPC_COMM_TYPE_MPC_PROCESS_TR

/*
* * MPI-2 One-Sided Communications asserts
*/

/* asserts for one-sided communication */
#define MPI_MODE_NOCHECK      1
#define MPI_MODE_NOSTORE      2
#define MPI_MODE_NOPUT 4
#define MPI_MODE_NOPRECEDE 8
#define MPI_MODE_NOSUCCEED 16

#define MPI_WIN_FLAVOR_CREATE        1
#define MPI_WIN_FLAVOR_ALLOCATE      2
#define MPI_WIN_FLAVOR_DYNAMIC       3
#define MPI_WIN_FLAVOR_SHARED        4

#define MPI_WIN_UNIFIED              0
#define MPI_WIN_SEPARATE             1

/* Others definitions */
#define MPI_MAX_PORT_NAME      256
#define MPI_ARGV_NULL (char **)0
#define MPI_ARGVS_NULL (char ***)0
#define MPI_ERRCODES_IGNORE (int *)0

/* Error not implemented */
#define MPIX_ERR_PROC_FAILED          101 /* Process failure */
#define MPIX_ERR_PROC_FAILED_PENDING  102 /* A failure has caused this request
                                           * to be pending */
#define MPIX_ERR_REVOKED              103 /* The communciation object has been revoked */
#define MPICH_ERR_LAST_MPIX           103


/************************************************************************/
/*  Type Definitions                                                    */
/************************************************************************/

typedef MPC_Datatype MPI_Datatype; /* unsigned int */
typedef MPC_Comm MPI_Comm; /* unsigned int */
typedef int MPI_Request;
typedef MPC_Aint MPI_Aint; /* long */
typedef int MPI_Errhandler;
typedef MPC_User_function MPI_User_function;
typedef int MPI_Op;
typedef int MPI_Group;
typedef MPC_Status MPI_Status;
typedef MPC_Handler_function MPI_Handler_function;
typedef int MPI_Fint;

/* MPI type combiner */
typedef MPC_Type_combiner MPI_Type_combiner;

/* MPI_Info Definitions */
typedef MPC_Info MPI_Info;

/* Copy Functions */
typedef int (MPI_Copy_function) (MPI_Comm, int, void *, void *, void *, int *);
typedef int (MPI_Delete_function) (MPI_Comm, int, void *, void *);

/* Generalized requests functions */
typedef int MPI_Grequest_query_function( void * extra_state, MPI_Status *status );
typedef int MPI_Grequest_cancel_function( void * extra_state, int complete );
typedef int MPI_Grequest_free_function( void * extra_state );

/* Extended Generalized Requests Functions */
typedef int MPIX_Grequest_poll_fn(void * extra_arg, MPI_Status *status);

/* Extended Generalized Request Class */
typedef int MPIX_Grequest_class;
typedef int MPIX_Grequest_wait_fn(int count, void **array_of_states, double, MPI_Status *status);

/* Halo */
typedef int MPI_Halo;
typedef int MPI_Halo_exchange;

/* NOT IMPLEMENTED >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
typedef int MPI_Win;
typedef long MPI_Count;

typedef MPC_Message MPI_Message;

/* added in MPI-2.2 */
typedef void (MPI_File_errhandler_function)(void *, int *, ...);
/* names that were added in MPI-2.0 and deprecated in MPI-2.2 */
typedef MPI_File_errhandler_function MPI_File_errhandler_fn;
 
/* C functions */
//~ typedef void (MPC_Handler_function) ( MPI_Comm *, int *, ... );
typedef int (MPI_Comm_copy_attr_function)(MPI_Comm, int, void *, void *, void *, int *);
typedef int (MPI_Comm_delete_attr_function)(MPI_Comm, int, void *, void *);

typedef MPC_Type_copy_attr_function MPI_Type_copy_attr_function;
typedef MPC_Type_delete_attr_function MPI_Type_delete_attr_function;

typedef int (MPI_Win_copy_attr_function)(MPI_Win, int, void *, void *, void *,int *);
typedef int (MPI_Win_delete_attr_function)(MPI_Win, int, void *, void *);
/* added in MPI-2.2 */
typedef void (MPI_Comm_errhandler_function)(MPI_Comm *, int *, ...);
typedef void (MPI_Win_errhandler_function)(MPI_Win *, int *, ...);
/* names that were added in MPI-2.0 and deprecated in MPI-2.2 */
typedef MPI_Comm_errhandler_function MPI_Comm_errhandler_fn;
typedef MPI_Win_errhandler_function MPI_Win_errhandler_fn;
/* END OF NOT IMPLEMENTED <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

typedef struct
{
	int size;
	MPI_Request request;
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
int MPI_Init_thread (int *, char ***, int, int *);  
int MPI_Init (int *, char ***);
int MPI_Finalize (void);
int MPI_Finalized (int *);
int MPI_Initialized (int *);

/* Error Handling */
void MPI_Default_error (MPI_Comm * comm, int *error, char *msg, char *file, int line);
void MPI_Abort_error (MPI_Comm * comm, int *error, char *msg, char *file, int line);
void MPI_Return_error (MPI_Comm * comm, int *error, ...);
int MPI_Errhandler_create (MPI_Handler_function *, MPI_Errhandler *);
int MPI_Errhandler_set (MPI_Comm, MPI_Errhandler);
int MPI_Errhandler_get (MPI_Comm, MPI_Errhandler *);
int MPI_Errhandler_free (MPI_Errhandler *);
int MPI_Error_string (int, char *, int *);
int MPI_Error_class (int, int *);
int MPI_Abort (MPI_Comm, int);

/* NOT IMPLEMENTED >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
int MPC_Mpi_null_delete_fn( MPI_Datatype datatype, int type_keyval, void* attribute_val_out, void* extra_state );
int MPC_Mpi_null_copy_fn( MPI_Comm comm, int comm_keyval, void* extra_state, void* attribute_val_in, void* attribute_val_out, int* flag );
int MPC_Mpi_dup_fn( MPI_Comm comm, int comm_keyval, void* extra_state, void* attribute_val_in, void* attribute_val_out, int* flag );

/* type */
int MPC_Mpi_type_null_delete_fn( MPI_Datatype datatype, int type_keyval, void* attribute_val_out, void* extra_state );
int MPC_Mpi_type_null_copy_fn( MPI_Comm comm, int comm_keyval, void* extra_state, void* attribute_val_in, void* attribute_val_out, int* flag );
int MPC_Mpi_type_dup_fn( MPI_Comm comm, int comm_keyval, void* extra_state, void* attribute_val_in, void* attribute_val_out, int* flag );

/* comm */
int MPC_Mpi_comm_null_delete_fn( MPI_Datatype datatype, int type_keyval, void* attribute_val_out, void* extra_state );
int MPC_Mpi_comm_null_copy_fn( MPI_Comm comm, int comm_keyval, void* extra_state, void* attribute_val_in, void* attribute_val_out, int* flag );
int MPC_Mpi_comm_dup_fn( MPI_Comm comm, int comm_keyval, void* extra_state, void* attribute_val_in, void* attribute_val_out, int* flag );

/* win */
int MPC_Mpi_win_null_delete_fn( MPI_Datatype datatype, int type_keyval, void* attribute_val_out, void* extra_state );
int MPC_Mpi_win_null_copy_fn( MPI_Comm comm, int comm_keyval, void* extra_state, void* attribute_val_in, void* attribute_val_out, int* flag );
int MPC_Mpi_win_dup_fn( MPI_Comm comm, int comm_keyval, void* extra_state, void* attribute_val_in, void* attribute_val_out, int* flag );
/* END OF NOT IMPLEMENTED <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* Point to Point communications */
int MPI_Send (void *, int, MPI_Datatype, int, int, MPI_Comm);
int MPI_Recv (void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Status *);
int MPI_Get_count (MPI_Status *, MPI_Datatype, int *);
int MPI_Bsend (void *, int, MPI_Datatype, int, int, MPI_Comm);
int MPI_Ssend (void *, int, MPI_Datatype, int, int, MPI_Comm);
int MPI_Rsend (void *, int, MPI_Datatype, int, int, MPI_Comm);
int MPI_Buffer_attach (void *, int);
int MPI_Buffer_detach (void *, int *);
int MPI_Isend (void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);
int MPI_Ibsend (void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);
int MPI_Issend (void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);
int MPI_Irsend (void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);
int MPI_Irecv (void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);
int MPI_Wait (MPI_Request *, MPI_Status *);
int MPI_Test (MPI_Request *, int *, MPI_Status *);
int MPI_Request_free (MPI_Request *);
int MPI_Waitany (int, MPI_Request *, int *, MPI_Status *);
int MPI_Testany (int, MPI_Request *, int *, int *, MPI_Status *);
int MPI_Waitall (int, MPI_Request *, MPI_Status *);
int MPI_Testall (int, MPI_Request *, int *, MPI_Status *);
int MPI_Waitsome (int, MPI_Request *, int *, int *, MPI_Status *);
int MPI_Testsome (int, MPI_Request *, int *, int *, MPI_Status *);
int MPI_Iprobe (int, int, MPI_Comm, int *, MPI_Status *);
int MPI_Probe (int, int, MPI_Comm, MPI_Status *);
int MPI_Cancel (MPI_Request *);
int MPI_Send_init (void *, int, MPI_Datatype, int, int, MPI_Comm,  MPI_Request *);
int MPI_Bsend_init (void *, int, MPI_Datatype, int, int, MPI_Comm,  MPI_Request *);
int MPI_Ssend_init (void *, int, MPI_Datatype, int, int, MPI_Comm,  MPI_Request *);
int MPI_Rsend_init (void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);
int MPI_Recv_init (void *, int, MPI_Datatype, int, int, MPI_Comm,  MPI_Request *);
int MPI_Start (MPI_Request *);
int MPI_Startall (int, MPI_Request *);
int MPI_Sendrecv (void *, int, MPI_Datatype, int, int, void *, int,  MPI_Datatype, int, int, MPI_Comm, MPI_Status *);
int MPI_Sendrecv_replace (void *, int, MPI_Datatype, int, int, int, int, MPI_Comm, MPI_Status *);
  
/* Status Modification and query */
int MPI_Status_set_elements(MPI_Status *, MPI_Datatype , int );
int MPI_Status_set_elements_x(MPI_Status *, MPI_Datatype , MPI_Count );
int MPI_Status_set_cancelled (MPI_Status *, int);
int MPI_Request_get_status (MPI_Request, int *, MPI_Status *);
int MPI_Test_cancelled (MPI_Status *, int *);

/* Datatype Management & Packs */
int MPI_Type_contiguous (int, MPI_Datatype, MPI_Datatype *);
int MPI_Type_vector (int, int, int, MPI_Datatype, MPI_Datatype *);
int MPI_Type_hvector (int, int, MPI_Aint, MPI_Datatype, MPI_Datatype *);
int MPI_Type_create_hvector (int, int, MPI_Aint, MPI_Datatype, MPI_Datatype *);
int MPI_Type_indexed (int, int *, int *, MPI_Datatype, MPI_Datatype *);
int MPI_Type_hindexed (int, int *, MPI_Aint *, MPI_Datatype, MPI_Datatype *);
int MPI_Type_create_hindexed (int, int *, MPI_Aint *, MPI_Datatype, MPI_Datatype *);
int MPI_Type_create_indexed_block(int count, int blocklength, int indices[], MPI_Datatype old_type, MPI_Datatype *newtype);
int MPI_Type_create_hindexed_block(int count, int blocklength, MPI_Aint indices[], MPI_Datatype old_type, MPI_Datatype *newtype);
int MPI_Type_struct (int, int *, MPI_Aint *, MPI_Datatype *, MPI_Datatype *);
int MPI_Type_create_struct (int, int *, MPI_Aint *, MPI_Datatype *, MPI_Datatype *);
int MPI_Address (void *, MPI_Aint *);
int MPI_Get_address(void *location, MPI_Aint *address);
/* We could add __attribute__((deprecated)) to routines like MPI_Type_extent */
int MPI_Type_extent (MPI_Datatype, MPI_Aint *);
/* See the 1.1 version of the Standard.  The standard made an
unfortunate choice here, however, it is the standard.  The size returned
by MPI_Type_size is specified as an int, not an MPI_Aint */
int MPI_Type_size (MPI_Datatype, int *);
/* MPI_Type_count was withdrawn in MPI 1.1 */
int MPI_Type_lb (MPI_Datatype, MPI_Aint *);
int MPI_Type_ub (MPI_Datatype, MPI_Aint *);
int MPI_Type_commit (MPI_Datatype *);
int MPI_Type_free (MPI_Datatype *);
int MPI_Get_elements (MPI_Status *, MPI_Datatype, int *);
int MPI_Type_match_size(int typeclass, int size, MPI_Datatype *rtype);
int MPI_Pack (void *, int, MPI_Datatype, void *, int, int *, MPI_Comm);
int MPI_Unpack (void *, int, int *, void *, int, MPI_Datatype, MPI_Comm);
int MPI_Pack_size (int, MPI_Datatype, MPI_Comm, int *);
int MPI_Type_set_name( MPI_Datatype datatype, char *name );
int MPI_Type_get_name( MPI_Datatype datatype, char *name, int * resultlen );
int MPI_Type_dup( MPI_Datatype old_type, MPI_Datatype *newtype );
int MPI_Type_get_extent(MPI_Datatype datatype, MPI_Aint *lb, MPI_Aint *extent);
int MPI_Type_get_true_extent(MPI_Datatype datatype, MPI_Aint *true_lb, MPI_Aint *true_extent);
int MPI_Type_get_envelope(MPI_Datatype datatype, int *num_integers, int *num_addresses, int *num_datatypes, int *combiner);
int MPI_Type_get_contents( MPI_Datatype datatype, 
			   int max_integers,
			   int max_addresses,
			   int max_datatypes,
			   int array_of_integers[],
			   MPI_Aint array_of_addresses[],
			   MPI_Datatype array_of_datatypes[]);
int MPI_Type_size_x(MPI_Datatype datatype, MPI_Count *size);
int MPI_Type_get_extent_x(MPI_Datatype datatype, MPI_Count *lb, MPI_Count *extent);
int MPI_Type_get_true_extent_x(MPI_Datatype datatype, MPI_Count *true_lb, MPI_Count *true_extent);
int MPI_Get_elements_x (MPI_Status * status, MPI_Datatype datatype, MPI_Count *elements);
int MPI_Type_create_darray (int size,
			     int rank,
			     int ndims,
			     int array_of_gsizes[],
			     int array_of_distribs[],
			     int array_of_dargs[],
			     int array_of_psizes[],
			     int order,
			     MPI_Datatype oldtype,
			     MPI_Datatype *newtype);
int MPI_Type_create_subarray (int ndims,
			       int array_of_sizes[],
			       int array_of_subsizes[],
			       int array_of_starts[],
			       int order,
			       MPI_Datatype oldtype,
			       MPI_Datatype * new_type);
int MPI_Type_create_resized (MPI_Datatype, MPI_Aint , MPI_Aint , MPI_Datatype *);
int MPI_Pack_external_size (char *datarep , int incount, MPI_Datatype datatype, MPI_Aint *size);
int MPI_Pack_external (char *datarep , void *inbuf, int incount, MPI_Datatype datatype, void * outbuf, MPI_Aint outsize, MPI_Aint * position);
int MPI_Unpack_external (char * datarep, void * inbuf, MPI_Aint insize, MPI_Aint * position, void * outbuf, int outcount, MPI_Datatype datatype);

/* Collective Operations */
int MPI_Barrier (MPI_Comm);
int MPI_Bcast (void *, int, MPI_Datatype, int, MPI_Comm);
int MPI_Gather (void *, int, MPI_Datatype, void *, int, MPI_Datatype, int, MPI_Comm);
int MPI_Gatherv (void *, int, MPI_Datatype, void *, int *, int *, MPI_Datatype, int, MPI_Comm);
int MPI_Scatter (void *, int, MPI_Datatype, void *, int, MPI_Datatype, int, MPI_Comm);
int MPI_Scatterv (void *, int *, int *, MPI_Datatype, void *, int, MPI_Datatype, int, MPI_Comm);
int MPI_Allgather (void *, int, MPI_Datatype, void *, int, MPI_Datatype, MPI_Comm);
int MPI_Allgatherv (void *, int, MPI_Datatype, void *, int *, int *, MPI_Datatype, MPI_Comm);
int MPI_Alltoall (void *, int, MPI_Datatype, void *, int, MPI_Datatype, MPI_Comm);
int MPI_Alltoallv (void *, int *, int *, MPI_Datatype, void *, int *, int *, MPI_Datatype, MPI_Comm);
int MPI_Exscan (void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm);
int MPI_Reduce (void *, void *, int, MPI_Datatype, MPI_Op, int, MPI_Comm);
int MPI_Allreduce (void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm);
int MPI_Reduce_scatter (void *, void *, int *, MPI_Datatype, MPI_Op, MPI_Comm);
int MPI_Reduce_scatter_block(void *, void *, int , MPI_Datatype , MPI_Op , MPI_Comm );
int MPI_Scan (void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm);

/* Non Blocking Collectives Operations */
int MPI_Iallreduce (void *sendbuf, void *recvbuf, int count,MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,MPI_Request *request);
int MPI_Ibarrier(MPI_Comm comm, MPI_Request *request);
int MPI_Ibcast(void *buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm, MPI_Request *request);
int MPI_Igather(void *sendbuf, int sendcount, MPI_Datatype sendtype,void *recvbuf, int recvcount, MPI_Datatype recvtype,int root, MPI_Comm comm, MPI_Request *request);
int MPI_Igatherv(void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcounts[], int displs[], MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request);
int MPI_Iscatter(void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request);
int MPI_Iscatterv(void *sendbuf, int sendcounts[], int displs[], MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request);
int MPI_Iallgather(void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request);
int MPI_Iallgatherv(void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcounts[], int displs[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request);
int MPI_Ialltoall(void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request);
int MPI_Ialltoallv(void *sendbuf, int sendcounts[], int sdispls[], MPI_Datatype sendtype, void *recvbuf, int recvcounts[], int rdispls[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request);
int MPI_Ialltoallw(void *sendbuf, int sendcounts[], int sdispls[], MPI_Datatype sendtypes[], void *recvbuf, int recvcounts[], int rdispls[], MPI_Datatype recvtypes[], MPI_Comm comm, MPI_Request *request);
int MPI_Ireduce(void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm, MPI_Request *request);
int MPI_Ireduce_scatter(void *sendbuf, void *recvbuf, int recvcounts[], MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request);
int MPI_Ireduce_scatter_block(void *sendbuf, void *recvbuf, int recvcount, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request);
int MPI_Iscan(void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request);
int MPI_Iexscan(void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request);

/* Operations */
int MPI_Op_create (MPI_User_function *, int, MPI_Op *);
int MPI_Op_free (MPI_Op *);

/* Group Management */
int MPI_Group_size (MPI_Group, int *);
int MPI_Group_rank (MPI_Group, int *);
int MPI_Group_translate_ranks (MPI_Group, int, int *, MPI_Group, int *);
int MPI_Group_compare (MPI_Group, MPI_Group, int *);
int MPI_Comm_group (MPI_Comm, MPI_Group *);
int MPI_Group_union (MPI_Group, MPI_Group, MPI_Group *);
int MPI_Group_intersection (MPI_Group, MPI_Group, MPI_Group *);
int MPI_Group_difference (MPI_Group, MPI_Group, MPI_Group *);
int MPI_Group_incl (MPI_Group, int, int *, MPI_Group *);
int MPI_Group_excl (MPI_Group, int, int *, MPI_Group *);
int MPI_Group_range_incl (MPI_Group, int, int[][3], MPI_Group *);
int MPI_Group_range_excl (MPI_Group, int, int[][3], MPI_Group *);
int MPI_Group_free (MPI_Group *);
  
/* Communicators and Intercommunicators */
int MPI_Comm_size (MPI_Comm, int *);
int MPI_Comm_rank (MPI_Comm, int *);
int MPI_Comm_compare (MPI_Comm, MPI_Comm, int *);
int MPI_Comm_dup (MPI_Comm, MPI_Comm *);
int MPI_Comm_create (MPI_Comm, MPI_Group, MPI_Comm *);
int MPI_Comm_split (MPI_Comm, int, int, MPI_Comm *);
int MPI_Comm_free (MPI_Comm *);
int MPI_Comm_test_inter (MPI_Comm, int *);
int MPI_Comm_remote_size (MPI_Comm, int *);
int MPI_Comm_remote_group (MPI_Comm, MPI_Group *);
int MPI_Intercomm_create (MPI_Comm, int, MPI_Comm, int, int, MPI_Comm *);
int MPI_Intercomm_merge (MPI_Comm, int, MPI_Comm *);

/* Keyval and Attr */
int MPI_Keyval_create (MPI_Copy_function *, MPI_Delete_function *, int *, void *);
int MPI_Keyval_free (int *);
int MPI_Attr_put (MPI_Comm, int, void *);
int MPI_Attr_get (MPI_Comm, int, void *, int *);
int MPI_Attr_delete (MPI_Comm, int);
int MPI_Attr_get_fortran(MPI_Comm comm, int keyval, int *attr_value, int *flag);

/* Topology Management */
int MPI_Topo_test (MPI_Comm, int *);

int MPI_Dims_create (int, int, int *);

int MPI_Graph_create (MPI_Comm, int, int *, int *, int, MPI_Comm *);
int MPI_Graphdims_get (MPI_Comm, int *, int *);
int MPI_Graph_get (MPI_Comm, int, int, int *, int *);
int MPI_Graph_neighbors_count (MPI_Comm, int, int *);
int MPI_Graph_neighbors (MPI_Comm, int, int, int *);
int MPI_Graph_map (MPI_Comm, int, int *, int *, int *);  

int MPI_Cart_create (MPI_Comm, int, int *, int *, int, MPI_Comm *);
int MPI_Cart_get (MPI_Comm, int, int *, int *, int *);
int MPI_Cart_rank (MPI_Comm, int *, int *);
int MPI_Cart_coords (MPI_Comm, int, int, int *);
int MPI_Cart_shift (MPI_Comm, int, int, int *, int *);
int MPI_Cart_sub (MPI_Comm, int *, MPI_Comm *);
int MPI_Cart_map (MPI_Comm, int, int *, int *, int *);
int MPI_Cartdim_get (MPI_Comm, int *);

/* Getters */
int MPI_Get_processor_name (char *, int *);
int MPI_Get_version (int *, int *);
double MPI_Wtime (void);
double MPI_Wtick (void);
int MPI_Query_thread (int *);

/* Profiling */
  
  int MPIX_Swap(void **sendrecv_buf , int remote_rank, MPI_Count size , MPI_Comm comm);
  int MPIX_Exchange(void **send_buf , void **recvbuff, int remote_rank, MPI_Count size , MPI_Comm comm);
 
/* Halo */

int MPIX_Halo_cell_init( MPI_Halo * halo, char * label, MPI_Datatype type, int count );
int MPIX_Halo_cell_release( MPI_Halo * halo );

int MPIX_Halo_cell_set( MPI_Halo halo, void * ptr );
int MPIX_Halo_cell_get( MPI_Halo halo, void ** ptr );

/* Halo Exchange */

int MPIX_Halo_exchange_init( MPI_Halo_exchange * ex );
int MPIX_Halo_exchange_release( MPI_Halo_exchange * ex );

int MPIX_Halo_exchange_commit( MPI_Halo_exchange ex );
int MPIX_Halo_exchange( MPI_Halo_exchange ex );
int MPIX_Halo_iexchange( MPI_Halo_exchange ex );
int MPIX_Halo_iexchange_wait( MPI_Halo_exchange ex );
int MPIX_Halo_cell_bind_local( MPI_Halo_exchange ex, MPI_Halo halo );
int MPIX_Halo_cell_bind_remote( MPI_Halo_exchange ex, MPI_Halo halo, int remote, char * remote_label );
 
/* Note that we may need to define a @PCONTROL_LIST@ depending on whether
stdargs are supported */
int MPI_Pcontrol (const int, ...);

/* Communicator Naming (MPI-2 functions) */
int MPI_Comm_get_name (MPI_Comm, char *, int *);
int MPI_Comm_set_name (MPI_Comm, char *);

/* Fortran Converters */
MPI_Comm MPI_Comm_f2c(MPI_Fint comm);
MPI_Fint MPI_Comm_c2f(MPI_Comm comm);
MPI_Datatype MPI_Type_f2c(MPI_Fint datatype);
MPI_Fint MPI_Type_c2f(MPI_Datatype datatype);
MPI_Group MPI_Group_f2c(MPI_Fint group);
MPI_Fint MPI_Group_c2f(MPI_Group group);
MPI_Request MPI_Request_f2c(MPI_Fint request);
MPI_Fint MPI_Request_c2f(MPI_Request request);
MPI_Win MPI_Win_f2c(MPI_Fint win);
MPI_Fint MPI_Win_c2f(MPI_Win win);
MPI_Op MPI_Op_f2c(MPI_Fint op);
MPI_Fint MPI_Op_c2f(MPI_Op op);
MPI_Info MPI_Info_f2c(MPI_Fint info);
MPI_Fint MPI_Info_c2f(MPI_Info info);
MPI_Errhandler MPI_Errhandler_f2c(MPI_Fint errhandler);
MPI_Fint MPI_Errhandler_c2f(MPI_Errhandler errhandler);
  
/* Neighbors collectives */
int MPI_Neighbor_allgather(void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm);
int MPI_Neighbor_allgatherv(void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcounts[], int displs[], MPI_Datatype recvtype, MPI_Comm comm);
int MPI_Neighbor_alltoall(void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm);
int MPI_Neighbor_alltoallv(void *sendbuf, int sendcounts[], int sdispls[], MPI_Datatype sendtype, void *recvbuf, int recvcounts[], int rdispls[], MPI_Datatype recvtype, MPI_Comm comm);
int MPI_Neighbor_alltoallw(void *sendbuf, int sendcounts[], MPI_Aint sdispls[], MPI_Datatype sendtypes[], void *recvbuf, int recvcounts[], MPI_Aint rdispls[], MPI_Datatype recvtypes[], MPI_Comm comm);

/* MPI Info Management */
int MPI_Info_set( MPI_Info, const char *, const char * );
int MPI_Info_free( MPI_Info * );
int MPI_Info_create( MPI_Info * );
int MPI_Info_delete( MPI_Info , const char * );
int MPI_Info_get(MPI_Info , const char *, int , char *, int *);
int MPI_Info_dup( MPI_Info , MPI_Info * );
int MPI_Info_get_nkeys (MPI_Info, int *);
int MPI_Info_get_nthkey (MPI_Info, int, char *);
int MPI_Info_get_valuelen (MPI_Info, char *, int *, int *);

/* Generalized Requests */
int MPI_Grequest_start( MPI_Grequest_query_function *query_fn,
			MPI_Grequest_free_function * free_fn,
			MPI_Grequest_cancel_function * cancel_fn,
			void *extra_state,
			MPI_Request * request);
int MPI_Grequest_complete(  MPI_Request request); 

/* Extended Generalized Requests */
int MPIX_Grequest_start(MPI_Grequest_query_function *query_fn,
			MPI_Grequest_free_function * free_fn,
			MPI_Grequest_cancel_function * cancel_fn, 
			MPIX_Grequest_poll_fn * poll_fn, 
			void *extra_state, 
			MPI_Request * request);

/* Extended Generalized Request Class */
int MPIX_Grequest_class_create( MPI_Grequest_query_function * query_fn,
				MPI_Grequest_cancel_function * cancel_fn,
				MPI_Grequest_free_function * free_fn,
				MPIX_Grequest_poll_fn * poll_fn,
				MPIX_Grequest_wait_fn * wait_fn,
				MPIX_Grequest_class * new_class );
int MPIX_Grequest_class_allocate( MPIX_Grequest_class target_class, void *extra_state, MPI_Request *request );

/* Dummy One-Sided Communications */

int MPI_Free_mem (void *ptr);
int MPI_Alloc_mem(MPI_Aint size, MPI_Info info, void *baseptr);

/************************************************************************/
/* The MPI Tools Interface MPI_T                                        */
/************************************************************************/

/** MPI_T Verbosity levels */

typedef enum {

  MPC_T_VERBOSITY_NONE = 0,

  MPI_T_VERBOSITY_USER_BASIC,
  MPI_T_VERBOSITY_USER_DETAIL,
  MPI_T_VERBOSITY_USER_ALL,

  MPI_T_VERBOSITY_TUNER_BASIC,
  MPI_T_VERBOSITY_TUNER_DETAIL,
  MPI_T_VERBOSITY_TUNER_ALL,

  MPI_T_VERBOSITY_MPIDEV_BASIC,
  MPI_T_VERBOSITY_MPIDEV_DETAIL,
  MPI_T_VERBOSITY_MPIDEV_ALL

} MPC_T_verbosity;

/** MPI_T Binding to object */

typedef enum {

  MPI_T_BIND_NO_OBJECT = 0,
  MPI_T_BIND_MPI_COMM,
  MPI_T_BIND_MPI_DATATYPE,
  MPI_T_BIND_MPI_ERRHANDLER,
  MPI_T_BIND_MPI_FILE,
  MPI_T_BIND_MPI_GROUP,
  MPI_T_BIND_MPI_OP,
  MPI_T_BIND_MPI_REQUEST,
  MPI_T_BIND_MPI_WIN,
  MPI_T_BIND_MPI_MESSAGE,
  MPI_T_BIND_MPI_INFO
} MPC_T_binding;

/** Initialization and Finalization */

/** Initialize the MPI_T environment
* @arg required The level of thread safety required
* @arg provided The level of thread safety provided
* @return MPI Error
*/
int MPI_T_init_thread(int required, int *provided);

/** Close the MPI_T Context
* @note MPI_T does refcounting
* @return MPI Error
*/
int MPI_T_finalize(void);

/** MPI_T Enum */

#define MPI_T_ENUM_NULL ((MPI_T_enum)NULL)

/* One-Sided Communications */
int MPI_Win_set_attr(MPI_Win, int, void *);
int MPI_Win_get_attr(MPI_Win, int, void *, int *);
int MPI_Win_free_keyval(int *);
int MPI_Win_delete_attr(MPI_Win, int);
int MPI_Win_create_keyval(MPI_Win_copy_attr_function *,
                          MPI_Win_delete_attr_function *, int *, void *);
int MPI_Win_create(void *, MPI_Aint, int, MPI_Info, MPI_Comm, MPI_Win *);
int MPI_Win_free(MPI_Win *);
int MPI_Win_wait(MPI_Win);
int MPI_Accumulate(void *, int, MPI_Datatype, int, MPI_Aint, int, MPI_Datatype,
                   MPI_Op, MPI_Win);
int MPI_Get(void *, int, MPI_Datatype, int, MPI_Aint, int, MPI_Datatype,
            MPI_Win);
int MPI_Put(void *, int, MPI_Datatype, int, MPI_Aint, int, MPI_Datatype,
            MPI_Win);
int MPI_Win_complete(MPI_Win);
int MPI_Win_fence(int, MPI_Win);
int MPI_Win_get_group(MPI_Win, MPI_Group *);
int MPI_Win_lock(int, int, int, MPI_Win);
int MPI_Win_post(MPI_Group, int, MPI_Win);
int MPI_Win_start(MPI_Group, int, MPI_Win);
int MPI_Win_test(MPI_Win, int *);
int MPI_Win_unlock(int, MPI_Win);
int MPI_Win_allocate(MPI_Aint, int, MPI_Info, MPI_Comm, void *, MPI_Win *);
int MPI_Win_set_name(MPI_Win, const char *);
int MPI_Win_get_name(MPI_Win, char *, int *);
int MPI_Win_set_errhandler(MPI_Win, MPI_Errhandler);
int MPI_Win_get_errhandler(MPI_Win, MPI_Errhandler *);
int MPI_Win_call_errhandler(MPI_Win win, int errorcode);
int MPI_Win_allocate_shared(MPI_Aint, int, MPI_Info, MPI_Comm, void *,
                            MPI_Win *);
int MPI_Win_create_errhandler(MPI_Win_errhandler_function *, MPI_Errhandler *);
int MPI_Win_create_dynamic(MPI_Info, MPI_Comm, MPI_Win *);
int MPI_Win_shared_query(MPI_Win, int, MPI_Aint *, int *, void *);
int MPI_Win_lock_all(int, MPI_Win);
int MPI_Win_unlock_all(MPI_Win win);
int MPI_Win_sync(MPI_Win win);
int MPI_Win_attach(MPI_Win, void *, MPI_Aint);
int MPI_Win_detach(MPI_Win, const void *);
int MPI_Win_flush(int, MPI_Win);
int MPI_Win_flush_all(MPI_Win);
int MPI_Win_set_info(MPI_Win, MPI_Info);
int MPI_Win_get_info(MPI_Win, MPI_Info *);
int MPI_Get_accumulate(const void *, int, MPI_Datatype, void *, int,
                       MPI_Datatype, int, MPI_Aint, int, MPI_Datatype, MPI_Op,
                       MPI_Win);
int MPI_Fetch_and_op(const void *, void *, MPI_Datatype, int, MPI_Aint, MPI_Op,
                     MPI_Win);
int MPI_Compare_and_swap(const void *, const void *, void *, MPI_Datatype, int,
                         MPI_Aint, MPI_Win);
int MPI_Rput(const void *, int, MPI_Datatype, int, MPI_Aint, int, MPI_Datatype,
             MPI_Win, MPI_Request *);
int MPI_Rget(void *, int, MPI_Datatype, int, MPI_Aint, int, MPI_Datatype,
             MPI_Win, MPI_Request *);
int MPI_Raccumulate(const void *, int, MPI_Datatype, int, MPI_Aint, int,
                    MPI_Datatype, MPI_Op, MPI_Win, MPI_Request *);
int MPI_Rget_accumulate(const void *, int, MPI_Datatype, void *, int,
                        MPI_Datatype, int, MPI_Aint, int, MPI_Datatype, MPI_Op,
                        MPI_Win, MPI_Request *);
/** Internal storage class (see mpit_internal.h) */
struct MPC_T_enum;

/** MPI Storage (just a pointer as no Fortran) */
typedef struct MPC_T_enum *MPI_T_enum;

/** Retrieve informations about an enum
* @arg enumtype The enumeration to be queried
* @arg num The number of objects in the enum
* @arg name Where to return the string containing the enum name
* @arg name_len Length of the buffer for "name"
* @return MPI Error
*/
int MPI_T_enum_get_info(MPI_T_enum enumtype, int *num, char *name,
                        int *name_len);

/** Retrieve and element in the enum
* @arg enumtype The enumeration to be queried
* @arg index ID of the value to be queried
* @arg name Name of the value to be queried
* @arg name_len Length of the target buffer
* @return MPI Error MPI_T_ERR_INVALID_INDEX (if out of range)
*/
int MPI_T_enum_get_item(MPI_T_enum enumtype, int index, int *value, char *name,
                        int *name_len);

/** Control Variables (CVAR) */

/** Get the number of control variables
* @arg num_cvar Number of control variables
* @return MPI Error
*/
int MPI_T_cvar_get_num(int *num_cvar);

/** This defines the scope of a cvar */
typedef enum {
  MPI_T_SCOPE_CONSTANT, /*<< Readonly value does not change */
  MPI_T_SCOPE_READONLY, /*<< Readonly can change but cannot be changed */
  MPI_T_SCOPE_LOCAL,    /*<< Can be writable as a local operation */
  MPI_T_SCOPE_GROUP,    /*<< Can be writable in a group of processes */
  MPI_T_SCOPE_GROUP_EQ, /*<< Can be writable in a group of processes requiring
                           the same value */
  MPI_T_SCOPE_ALL,      /*<< Can be writable in all connected processes */
  MPI_T_SCOPE_ALL_EQ,   /*<< Can be writable in all connected processes with the
                           same value */
} MPC_T_cvar_scope;

/** Retrieve the infos from a CVAR
* @arg cvar_index The CVAR to query
* @arg name The name of the CVAR
* @arg name_len Length of the target buffer
* @arg verbosity The verbosity level of this CVAR \ref MPC_T_Verbosity
* @arg datatype The datatype returned by the CVAR
* @arg enumtype The enumtype (optional) for description
* @arg desc The description of the control variable
* @arg desc_len The length of the desc buffer
* @arg bind Type of MPI object the variable is bound (see \ref MPC_T_Bind)
* @arg scope Scope in which this variable can be manipulated (\ref
* MPC_T_CVAR_scope)
* @return MPI Error
*/
int MPI_T_cvar_get_info(int cvar_index, char *name, int *name_len,
                        int *verbosity, MPI_Datatype *datatype,
                        MPI_T_enum *enumtype, char *desc, int *desc_len,
                        int *bind, int *scope);

/** Get the index of a CVAR from its name
* @arg name Name of the target CVAR
* @arg cvar_index Index of the target CVAR
* @return MPI_T_ERR_INVALID_NAME if not found
*/
int MPI_T_cvar_get_index(const char *name, int *cvar_index);

/** Forward declaration of the VAR container */

struct MPC_T_data;

/** CVAR Handles */

#define MPI_T_CVAR_HANDLE_NULL ((MPI_T_cvar_handle)NULL)

typedef struct MPC_T_cvar *MPI_T_cvar_handle;

/** Allocate a CVAR handle
* @arg cvar_index Target CVAR index
* @arg obj_handle Target MPI handle
* @arg handle Handle to be created
* @arg count Number of elements used to represent this variable
* @return MPI Error
*/
int MPI_T_cvar_handle_alloc(int cvar_index, void *obj_handle,
                            MPI_T_cvar_handle *handle, int *count);

/** Free a CVAR handle
* @arg handle Handle to be freed
* @return MPI Error
*/
int MPI_T_cvar_handle_free(MPI_T_cvar_handle *handle);

/** CVAR access */

/** Read a control variables
* @arg handle A handle to a given CVAR
* @arg buff Pointer to where to store the content
* @return MPI Error
*/
int MPI_T_cvar_read(MPI_T_cvar_handle handle, void *buff);

/** Write a control variable
* @arg handle A handle to a given CVAR
* @arg buff The data to be written
* @return MPI Error
*/
int MPI_T_cvar_write(MPI_T_cvar_handle handle, const void *buff);

/** Performance variables (PVAR) */

typedef enum {
  MPC_T_PVAR_CLASS_NONE,          /**<< Internal value to catch uninitialized */
  MPI_T_PVAR_CLASS_STATE,         /**<< A set of discrete states */
  MPI_T_PVAR_CLASS_LEVEL,         /**<< Utilization of a ressource */
  MPI_T_PVAR_CLASS_SIZE,          /**<< The size of a ressource */
  MPI_T_PVAR_CLASS_PERCENTAGE,    /**<< The percentage of a ressource use */
  MPI_T_PVAR_CLASS_HIGHWATERMARK, /**<< High use of a ressource */
  MPI_T_PVAR_CLASS_LOWWATERMARK,  /**<< Low use of a ressource */
  MPI_T_PVAR_CLASS_COUNTER,       /**<< Number of occurences of an event */
  MPI_T_PVAR_CLASS_AGGREGATE,     /**<< Aggregated value of ressource */
  MPI_T_PVAR_CLASS_TIMER,  /**<< Aggregate time spent executing something */
  MPI_T_PVAR_CLASS_GENERIC /**<< A generic class */
} MPC_T_pvar_class;

/** Get the number of PVAR
* @arg num_pvar Number of PVAR
* @return MPI Error
*/
int MPI_T_pvar_get_num(int *num_pvar);

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
int MPI_T_pvar_get_info(int pvar_index, char *name, int *name_len,
                        int *verbosity, int *var_class, MPI_Datatype *datatype,
                        MPI_T_enum *enumtype, char *desc, int *desc_len,
                        int *bind, int *readonly, int *continuous, int *atomic);

/** Get the index of a PVAR by name
* @arg name Name to look for
* @arg var_class Class of the PVAR
* @arg pvar_index Index of the PVAR found
* @return MPI_T_ERR_INVALID_NAME if not found
*/
int MPI_T_pvar_get_index(char *name, int *pvar_class, int *pvar_index);

/*** Performance experiment sessions */

/* Forward declaration of the session container */
struct MPC_T_session;

#define MPI_T_PVAR_SESSION_NULL (-2)

typedef int MPI_T_pvar_session;

/** Create a PVAR performance sessions
* @arg session The session to create
* @return MPI Erorr
*/
int MPI_T_pvar_session_create(MPI_T_pvar_session *session);

/** Free a PVAR performance session
* @arg session to be freed
* @return MPI Error
*/
int MPI_T_pvar_session_free(MPI_T_pvar_session *session);

/** PVAR Handle allocation */

#define MPI_T_PVAR_ALL_HANDLES ((MPI_T_pvar_handle)-1)
#define MPI_T_PVAR_HANDLE_NULL ((MPI_T_pvar_handle)NULL)

typedef struct MPC_T_pvar_handle *MPI_T_pvar_handle;

/** Allocate a new PVAR handle
* @arg session Which session to bind the handle to
* @arg pvar_index Index of the PVAR to bind
* @arg obj_handle Reference to the MPI object to bind to
* @arg handle New PVAR handle
* @arg count Number of elements used to represent the variable
* @return MPI Error
*/
int MPI_T_pvar_handle_alloc(MPI_T_pvar_session session, int pvar_index,
                            void *obj_handle, MPI_T_pvar_handle *handle,
                            int *count);

/** Release a PVAR handle
* @arg handle PVAR handle to free
* @return MPI Error
*/
int MPI_T_pvar_handle_free(MPI_T_pvar_session session,
                           MPI_T_pvar_handle *handle);

/** PVAR start and stop */

/** Start a performance variable
* @arg session The performance experiment section to start
* @arg handle The handle of the performance variable
* @return MPI Error
*/
int MPI_T_pvar_start(MPI_T_pvar_session session, MPI_T_pvar_handle handle);

/** Stop and MPIT PVAR
* @arg session The performance experiment section
* @arg handle The handle to manipulate
*/
int MPI_T_pvar_stop(MPI_T_pvar_session session, MPI_T_pvar_handle handle);

/** PVAR Read and write */

/** Read the value associated with a PVAR
 * @arg session Performance experiment session to read from
 * @arg handle Handle of the performance variable
 * @arg buff Storage location where to write to
 * @return MPI Error
 */
int MPI_T_pvar_read(MPI_T_pvar_session session, MPI_T_pvar_handle handle,
                    void *buff);

/** Read and reset the value associated with a PVAR
 * @arg session Performance experiment session to read from
 * @arg handle Handle of the performance variable
 * @arg buff Storage location where to write to
 * @return MPI Error
 */
int MPI_T_pvar_readreset(MPI_T_pvar_session session, MPI_T_pvar_handle handle,
                         void *buff);
/** Write the value associated with a PVAR
 * @arg session Performance experiment session to read from
 * @arg handle Handle of the performance variable
 * @arg buff Storage location where to read from
 * @return MPI Error
 */
int MPI_T_pvar_write(MPI_T_pvar_session session, MPI_T_pvar_handle handle,
                     const void *buff);
/** Reset the value associated with a PVAR
 * @arg session Performance experiment session to read from
 * @arg handle Handle of the performance variable
 * @return MPI Error
 */
int MPI_T_pvar_reset(MPI_T_pvar_session session, MPI_T_pvar_handle handle);

/** Variable categorization */

/** Query the number of categories
 * @arg num_cat The number of categories
 * @return MPI Error
 */
int MPI_T_category_get_num(int *num_cat);

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
int MPI_T_category_get_info(int cat_index, char *name, int *name_len,
                            char *desc, int *desc_len, int *num_cvars,
                            int *num_pvars, int *num_categories);

/** Get index of a category by name
 * @arg name Name to query
 * @arg Index of the category
 * @return MPI_T_ERR_INVALID_NAME if not found
 */
int MPI_T_category_get_index(char *name, int *cat_index);

/** Get the CVARS in a given category
 * @arg cat_index The index of the target category
 * @arg len The length of the indices array
 * @arg indices Array filled with the indices of the CVARS
 * @return MPI Error
 */
int MPI_T_category_get_cvars(int cat_index, int len, int indices[]);

/** Get the PVARS in a given category
 * @arg cat_index The index of the target category
 * @arg len The length of the indices array
 * @arg indices Array filled with the indices of the PVARS
 * @return MPI Error
 */
int MPI_T_category_get_pvars(int cat_index, int len, int indices[]);

/** Get the categories in a given category
 * @arg cat_index The index of the target category
 * @arg len The length of the indices array
 * @arg indices Array filled with the indices of the categories
 * @return MPI Error
 */
int MPI_T_category_get_categories(int cat_index, int len, int indices[]);

/** Check wether category information changed
 * @arg stamp Value identifying the generation of categories
 * @return MPI Error
 */
int MPI_T_category_changed(int *stamp);

/*** THE END OF THE MPI TOOLS INTERFACE */

/************************************************************************/
/*  PMPI Profiling Interface                                            */
/************************************************************************/
#if !defined(MPI_BUILD_PROFILING)
/* Init and Finalize */
int PMPI_Init_thread (int *, char ***, int, int *);  
int PMPI_Init (int *, char ***);
int PMPI_Finalize (void);
int PMPI_Finalized (int *);
int PMPI_Initialized (int *);

/* Error Handling */
void PMPI_Default_error (MPI_Comm * comm, int *error, char *msg, char *file, int line);
void PMPI_Abort_error (MPI_Comm * comm, int *error, char *msg, char *file, int line);
void PMPI_Return_error (MPI_Comm * comm, int *error, ...);
int PMPI_Errhandler_create (MPI_Handler_function *, MPI_Errhandler *);
int PMPI_Errhandler_set (MPI_Comm, MPI_Errhandler);
int PMPI_Errhandler_get (MPI_Comm, MPI_Errhandler *);
int PMPI_Errhandler_free (MPI_Errhandler *);
int PMPI_Error_string (int, char *, int *);
int PMPI_Error_class (int, int *);
int PMPI_Abort (MPI_Comm, int);

/* Point to Point communications */
int PMPI_Send (void *, int, MPI_Datatype, int, int, MPI_Comm);
int PMPI_Recv (void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Status *);
int PMPI_Get_count (MPI_Status *, MPI_Datatype, int *);
int PMPI_Bsend (void *, int, MPI_Datatype, int, int, MPI_Comm);
int PMPI_Ssend (void *, int, MPI_Datatype, int, int, MPI_Comm);
int PMPI_Rsend (void *, int, MPI_Datatype, int, int, MPI_Comm);
int PMPI_Buffer_attach (void *, int);
int PMPI_Buffer_detach (void *, int *);
int PMPI_Isend (void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);
int PMPI_Ibsend (void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);
int PMPI_Issend (void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);
int PMPI_Irsend (void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);
int PMPI_Irecv (void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);
int PMPI_Wait (MPI_Request *, MPI_Status *);
int PMPI_Test (MPI_Request *, int *, MPI_Status *);
int PMPI_Request_free (MPI_Request *);
int PMPI_Waitany (int, MPI_Request *, int *, MPI_Status *);
int PMPI_Testany (int, MPI_Request *, int *, int *, MPI_Status *);
int PMPI_Waitall (int, MPI_Request *, MPI_Status *);
int PMPI_Testall (int, MPI_Request *, int *, MPI_Status *);
int PMPI_Waitsome (int, MPI_Request *, int *, int *, MPI_Status *);
int PMPI_Testsome (int, MPI_Request *, int *, int *, MPI_Status *);
int PMPI_Iprobe (int, int, MPI_Comm, int *, MPI_Status *);
int PMPI_Probe (int, int, MPI_Comm, MPI_Status *);
int PMPI_Test_cancelled (MPI_Status *, int *);
int PMPI_Send_init (void *, int, MPI_Datatype, int, int, MPI_Comm,  MPI_Request *);
int PMPI_Bsend_init (void *, int, MPI_Datatype, int, int, MPI_Comm,  MPI_Request *);
int PMPI_Ssend_init (void *, int, MPI_Datatype, int, int, MPI_Comm,  MPI_Request *);
int PMPI_Rsend_init (void *, int, MPI_Datatype, int, int, MPI_Comm, MPI_Request *);
int PMPI_Recv_init (void *, int, MPI_Datatype, int, int, MPI_Comm,  MPI_Request *);
int PMPI_Start (MPI_Request *);
int PMPI_Startall (int, MPI_Request *);
int PMPI_Sendrecv (void *, int, MPI_Datatype, int, int, void *, int,  MPI_Datatype, int, int, MPI_Comm, MPI_Status *);
int PMPI_Sendrecv_replace (void *, int, MPI_Datatype, int, int, int, int, MPI_Comm, MPI_Status *);

/* Status Modification and query */
int PMPI_Status_set_elements(MPI_Status *, MPI_Datatype , int );
int PMPI_Status_set_elements_x(MPI_Status *, MPI_Datatype , MPI_Count );
int PMPI_Status_set_cancelled (MPI_Status *, int);
int PMPI_Request_get_status (MPI_Request, int *, MPI_Status *);
int PMPI_Test_cancelled (MPI_Status *, int *);

/* Datatype Management & Packs */
int PMPI_Type_contiguous (int, MPI_Datatype, MPI_Datatype *);
int PMPI_Type_vector (int, int, int, MPI_Datatype, MPI_Datatype *);
int PMPI_Type_hvector (int, int, MPI_Aint, MPI_Datatype, MPI_Datatype *);
int PMPI_Type_create_hvector (int, int, MPI_Aint, MPI_Datatype, MPI_Datatype *);
int PMPI_Type_indexed (int, int *, int *, MPI_Datatype, MPI_Datatype *);
int PMPI_Type_hindexed (int, int *, MPI_Aint *, MPI_Datatype, MPI_Datatype *);
int PMPI_Type_create_indexed_block(int count, int blocklength, int indices[], MPI_Datatype old_type, MPI_Datatype *newtype);
int PMPI_Type_create_hindexed_block(int count, int blocklength, MPI_Aint indices[], MPI_Datatype old_type, MPI_Datatype *newtype);
int PMPI_Type_create_hindexed (int, int *, MPI_Aint *, MPI_Datatype, MPI_Datatype *);
int PMPI_Type_struct (int, int *, MPI_Aint *, MPI_Datatype *, MPI_Datatype *);
int PMPI_Type_create_struct (int, int *, MPI_Aint *, MPI_Datatype *, MPI_Datatype *);
int PMPI_Address (void *, MPI_Aint *);
int PMPI_Get_address( void *location, MPI_Aint *address);
/* We could add __attribute__((deprecated)) to routines like MPI_Type_extent */
int PMPI_Type_get_extent(MPI_Datatype datatype, MPI_Aint *lb, MPI_Aint *extent);
/* See the 1.1 version of the Standard.  The standard made an
unfortunate choice here, however, it is the standard.  The size returned
by MPI_Type_size is specified as an int, not an MPI_Aint */
int PMPI_Type_size (MPI_Datatype, int *);
/* MPI_Type_count was withdrawn in MPI 1.1 */
int PMPI_Type_lb (MPI_Datatype, MPI_Aint *);
int PMPI_Type_ub (MPI_Datatype, MPI_Aint *);
int PMPI_Type_commit (MPI_Datatype *);
int PMPI_Type_free (MPI_Datatype *);
int PMPI_Get_elements (MPI_Status *, MPI_Datatype, int *);
int PMPI_Type_match_size(int typeclass, int size, MPI_Datatype *rtype);
int PMPI_Pack (void *, int, MPI_Datatype, void *, int, int *, MPI_Comm);
int PMPI_Unpack (void *, int, int *, void *, int, MPI_Datatype, MPI_Comm);
int PMPI_Pack_size (int, MPI_Datatype, MPI_Comm, int *);
int PMPI_Type_set_name( MPI_Datatype datatype, char *name );
int PMPI_Type_get_name( MPI_Datatype datatype, char *name, int * resultlen );
int PMPI_Type_dup( MPI_Datatype old_type, MPI_Datatype *newtype );
int PMPI_Type_extent(MPI_Datatype datatype, MPI_Aint *extent);
int PMPI_Type_get_true_extent(MPI_Datatype datatype, MPI_Aint *true_lb, MPI_Aint *true_extent);
int PMPI_Type_get_envelope(MPI_Datatype datatype, int *num_integers, int *num_addresses, int *num_datatypes, int *combiner);
int PMPI_Type_get_contents( MPI_Datatype datatype, 
		       	    int max_integers,
			    int max_addresses,
			    int max_datatypes,
			    int array_of_integers[],
			    MPI_Aint array_of_addresses[],
			    MPI_Datatype array_of_datatypes[]);
int PMPI_Type_size_x(MPI_Datatype datatype, MPI_Count *size);
int PMPI_Type_get_extent_x(MPI_Datatype datatype, MPI_Count *lb, MPI_Count *extent);
int PMPI_Type_get_true_extent_x(MPI_Datatype datatype, MPI_Count *true_lb, MPI_Count *true_extent);
int PMPI_Get_elements_x (MPI_Status * status, MPI_Datatype datatype, MPI_Count *elements);
int PMPI_Type_create_darray (int size,
			     int rank,
			     int ndims,
			     int array_of_gsizes[],
			     int array_of_distribs[],
			     int array_of_dargs[],
			     int array_of_psizes[],
			     int order,
			     MPI_Datatype oldtype,
			     MPI_Datatype *newtype);
int PMPI_Type_create_subarray (int ndims,
			       int array_of_sizes[],
			       int array_of_subsizes[],
			       int array_of_starts[],
			       int order,
			       MPI_Datatype oldtype,
			       MPI_Datatype * new_type);

int PMPI_Pack_external_size (char *, int, MPI_Datatype, MPI_Aint *);
int PMPI_Pack_external (char *, void *, int, MPI_Datatype, void *, MPI_Aint, MPI_Aint *);
int PMPI_Unpack_external (char *, void *, MPI_Aint, MPI_Aint *, void *, int, MPI_Datatype);

/* Collective Operations */
int PMPI_Barrier (MPI_Comm);
int PMPI_Bcast (void *, int, MPI_Datatype, int, MPI_Comm);
int PMPI_Gather (void *, int, MPI_Datatype, void *, int, MPI_Datatype, int, MPI_Comm);
int PMPI_Gatherv (void *, int, MPI_Datatype, void *, int *, int *, MPI_Datatype, int, MPI_Comm);
int PMPI_Scatter (void *, int, MPI_Datatype, void *, int, MPI_Datatype, int, MPI_Comm);
int PMPI_Scatterv (void *, int *, int *, MPI_Datatype, void *, int, MPI_Datatype, int, MPI_Comm);
int PMPI_Allgather (void *, int, MPI_Datatype, void *, int, MPI_Datatype, MPI_Comm);
int PMPI_Allgatherv (void *, int, MPI_Datatype, void *, int *, int *, MPI_Datatype, MPI_Comm);
int PMPI_Alltoall (void *, int, MPI_Datatype, void *, int, MPI_Datatype, MPI_Comm);
int PMPI_Alltoallv (void *, int *, int *, MPI_Datatype, void *, int *, int *, MPI_Datatype, MPI_Comm);
int PMPI_Exscan (void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm);
int PMPI_Reduce (void *, void *, int, MPI_Datatype, MPI_Op, int, MPI_Comm);
int PMPI_Allreduce (void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm);
int PMPI_Reduce_scatter (void *, void *, int *, MPI_Datatype, MPI_Op, MPI_Comm);
int PMPI_Reduce_scatter_block(void *, void *, int , MPI_Datatype , MPI_Op , MPI_Comm );
int PMPI_Scan (void *, void *, int, MPI_Datatype, MPI_Op, MPI_Comm);

/* Non Blocking Collectives Operations */
int PMPI_Iallreduce (void *sendbuf, void *recvbuf, int count,MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,MPI_Request *request);
int PMPI_Ibarrier(MPI_Comm comm, MPI_Request *request);
int PMPI_Ibcast(void *buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm, MPI_Request *request);
int PMPI_Igather(void *sendbuf, int sendcount, MPI_Datatype sendtype,void *recvbuf, int recvcount, MPI_Datatype recvtype,int root, MPI_Comm comm, MPI_Request *request);
int PMPI_Igatherv(void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcounts[], int displs[], MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request);
int PMPI_Iscatter(void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request);
int PMPI_Iscatterv(void *sendbuf, int sendcounts[], int displs[], MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm, MPI_Request *request);
int PMPI_Iallgather(void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request);
int PMPI_Iallgatherv(void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcounts[], int displs[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request);
int PMPI_Ialltoall(void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request);
int PMPI_Ialltoallv(void *sendbuf, int sendcounts[], int sdispls[], MPI_Datatype sendtype, void *recvbuf, int recvcounts[], int rdispls[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request);
int PMPI_Ialltoallw(void *sendbuf, int sendcounts[], int sdispls[], MPI_Datatype sendtypes[], void *recvbuf, int recvcounts[], int rdispls[], MPI_Datatype recvtypes[], MPI_Comm comm, MPI_Request *request);
int PMPI_Ireduce(void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm, MPI_Request *request);
int PMPI_Ireduce_scatter(void *sendbuf, void *recvbuf, int recvcounts[], MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request);
int PMPI_Ireduce_scatter_block(void *sendbuf, void *recvbuf, int recvcount, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request);
int PMPI_Iscan(void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request);
int PMPI_Iexscan(void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm, MPI_Request *request);


/* Operations */
int PMPI_Op_create (MPI_User_function *, int, MPI_Op *);
int PMPI_Op_free (MPI_Op *);

/* Group Management */
int PMPI_Group_size (MPI_Group, int *);
int PMPI_Group_rank (MPI_Group, int *);
int PMPI_Group_translate_ranks (MPI_Group, int, int *, MPI_Group, int *);
int PMPI_Group_compare (MPI_Group, MPI_Group, int *);
int PMPI_Comm_group (MPI_Comm, MPI_Group *);
int PMPI_Group_union (MPI_Group, MPI_Group, MPI_Group *);
int PMPI_Group_intersection (MPI_Group, MPI_Group, MPI_Group *);
int PMPI_Group_difference (MPI_Group, MPI_Group, MPI_Group *);
int PMPI_Group_incl (MPI_Group, int, int *, MPI_Group *);
int PMPI_Group_excl (MPI_Group, int, int *, MPI_Group *);
int PMPI_Group_range_incl (MPI_Group, int, int[][3], MPI_Group *);
int PMPI_Group_range_excl (MPI_Group, int, int[][3], MPI_Group *);
int PMPI_Group_free (MPI_Group *);
  
/* Communicators and Intercommunicators */
int PMPI_Comm_size (MPI_Comm, int *);
int PMPI_Comm_rank (MPI_Comm, int *);
int PMPI_Comm_compare (MPI_Comm, MPI_Comm, int *);
int PMPI_Comm_dup (MPI_Comm, MPI_Comm *);
int PMPI_Comm_split_type(MPI_Comm, int, int, MPI_Info, MPI_Comm *);
int PMPI_Comm_create (MPI_Comm, MPI_Group, MPI_Comm *);
int PMPI_Comm_split (MPI_Comm, int, int, MPI_Comm *);
int PMPI_Comm_free (MPI_Comm *);
int PMPI_Comm_test_inter (MPI_Comm, int *);
int PMPI_Comm_remote_size (MPI_Comm, int *);
int PMPI_Comm_remote_group (MPI_Comm, MPI_Group *);
int PMPI_Intercomm_create (MPI_Comm, int, MPI_Comm, int, int, MPI_Comm *);
int PMPI_Intercomm_merge (MPI_Comm, int, MPI_Comm *);
int PMPI_Comm_set_errhandler(MPI_Comm comm, MPI_Errhandler errhandler);
int PMPI_Comm_call_errhandler( MPI_Comm comm, int errorcode );
  
/* Keyval and Attr */
int PMPI_Keyval_create (MPI_Copy_function *, MPI_Delete_function *, int *, void *);
int PMPI_Keyval_free (int *);
int PMPI_Attr_put (MPI_Comm, int, void *);
int PMPI_Attr_get (MPI_Comm, int, void *, int *);
int PMPI_Attr_delete (MPI_Comm, int);
int PMPI_Attr_get_fortran(MPI_Comm comm, int keyval, int *attr_value,
                          int *flag);

/* Topology Management */
int PMPI_Topo_test (MPI_Comm, int *);

int PMPI_Dims_create (int, int, int *);

int PMPI_Graph_create (MPI_Comm, int, int *, int *, int, MPI_Comm *);
int PMPI_Graphdims_get (MPI_Comm, int *, int *);
int PMPI_Graph_get (MPI_Comm, int, int, int *, int *);
int PMPI_Graph_neighbors_count (MPI_Comm, int, int *);
int PMPI_Graph_neighbors (MPI_Comm, int, int, int *);
int PMPI_Graph_map (MPI_Comm, int, int *, int *, int *);  

int PMPI_Cart_create (MPI_Comm, int, int *, int *, int, MPI_Comm *);
int PMPI_Cart_get (MPI_Comm, int, int *, int *, int *);
int PMPI_Cart_rank (MPI_Comm, int *, int *);
int PMPI_Cart_coords (MPI_Comm, int, int, int *);
int PMPI_Cart_shift (MPI_Comm, int, int, int *, int *);
int PMPI_Cart_sub (MPI_Comm, int *, MPI_Comm *);
int PMPI_Cart_map (MPI_Comm, int, int *, int *, int *);
int PMPI_Cartdim_get (MPI_Comm, int *);

/* Getters */
int PMPI_Get_processor_name (char *, int *);
int PMPI_Get_version (int *, int *);
double PMPI_Wtime (void);
double PMPI_Wtick (void);
int PMPI_Query_thread (int *);

/* Profiling */
/* Note that we may need to define a @PCONTROL_LIST@ depending on whether
stdargs are supported */
int PMPI_Pcontrol (const int, ...);

/* Communicator Naming (MPI-2 functions) */
int PMPI_Comm_get_name (MPI_Comm, char *, int *);
int PMPI_Comm_set_name (MPI_Comm, char *);

/* Fortran Converters */
MPI_Comm PMPI_Comm_f2c(MPI_Fint comm);
MPI_Fint PMPI_Comm_c2f(MPI_Comm comm);
MPI_Datatype PMPI_Type_f2c(MPI_Fint datatype);
MPI_Fint PMPI_Type_c2f(MPI_Datatype datatype);
MPI_Group PMPI_Group_f2c(MPI_Fint group);
MPI_Fint PMPI_Group_c2f(MPI_Group group);
MPI_Request PMPI_Request_f2c(MPI_Fint request);
MPI_Fint PMPI_Request_c2f(MPI_Request request);
MPI_Win PMPI_Win_f2c(MPI_Fint win);
MPI_Fint PMPI_Win_c2f(MPI_Win win);
MPI_Op PMPI_Op_f2c(MPI_Fint op);
MPI_Fint PMPI_Op_c2f(MPI_Op op);
MPI_Info PMPI_Info_f2c(MPI_Fint info);
MPI_Fint PMPI_Info_c2f(MPI_Info info);
MPI_Errhandler PMPI_Errhandler_f2c(MPI_Fint errhandler);
MPI_Fint PMPI_Errhandler_c2f(MPI_Errhandler errhandler);
  
/* Neighbors collectives */
int PMPI_Neighbor_allgather(void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm);
int PMPI_Neighbor_allgatherv(void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcounts[], int displs[], MPI_Datatype recvtype, MPI_Comm comm);
int PMPI_Neighbor_alltoall(void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm);
int PMPI_Neighbor_alltoallv(void *sendbuf, int sendcounts[], int sdispls[], MPI_Datatype sendtype, void *recvbuf, int recvcounts[], int rdispls[], MPI_Datatype recvtype, MPI_Comm comm);
int PMPI_Neighbor_alltoallw(void *sendbuf, int sendcounts[], MPI_Aint sdispls[], MPI_Datatype sendtypes[], void *recvbuf, int recvcounts[], MPI_Aint rdispls[], MPI_Datatype recvtypes[], MPI_Comm comm);

/* MPI Info Management */
int PMPI_Info_set( MPI_Info, const char *, const char * );
int PMPI_Info_free( MPI_Info * );
int PMPI_Info_create( MPI_Info * );
int PMPI_Info_delete( MPI_Info , const char * );
int PMPI_Info_get(MPI_Info , const char *, int , char *, int *);
int PMPI_Info_dup( MPI_Info , MPI_Info * );
int PMPI_Info_get_nkeys (MPI_Info, int *);
int PMPI_Info_get_nthkey (MPI_Info, int, char *);
int PMPI_Info_get_valuelen (MPI_Info, char *, int *, int *);

/* Generalized Requests */
int PMPI_Grequest_start( MPI_Grequest_query_function *query_fn,
			MPI_Grequest_free_function * free_fn,
			MPI_Grequest_cancel_function * cancel_fn,
			void *extra_state,
			MPI_Request * request);
int PMPI_Grequest_complete(  MPI_Request request); 

/* Extended Generalized Requests */
int PMPIX_Grequest_start(MPI_Grequest_query_function *query_fn,
			MPI_Grequest_free_function * free_fn,
			MPI_Grequest_cancel_function * cancel_fn, 
			MPIX_Grequest_poll_fn * poll_fn, 
			void *extra_state, 
			MPI_Request * request);

/* Extended Generalized Request Class */
int PMPIX_Grequest_class_create( MPI_Grequest_query_function * query_fn,
				MPI_Grequest_free_function * free_fn,
				MPI_Grequest_cancel_function * cancel_fn,
				MPIX_Grequest_poll_fn * poll_fn,
				MPIX_Grequest_wait_fn * wait_fn,
				MPIX_Grequest_class * new_class );
int PMPIX_Grequest_class_allocate( MPIX_Grequest_class  target_class, void *extra_state, MPI_Request *request );

/* Dummy One-Sided Communications */

int PMPI_Free_mem (void *ptr);
int PMPI_Alloc_mem(MPI_Aint size, MPI_Info info, void *baseptr);


/* Halo */

int PMPIX_Halo_cell_init( MPI_Halo * halo, char * label, MPI_Datatype type, int count );
int PMPIX_Halo_cell_release( MPI_Halo * halo );

int PMPIX_Halo_cell_set( MPI_Halo halo, void * ptr );
int PMPIX_Halo_cell_get( MPI_Halo halo, void ** ptr );

/* Halo Exchange */

int PMPIX_Halo_exchange_init( MPI_Halo_exchange * ex );
int PMPIX_Halo_exchange_release( MPI_Halo_exchange * ex );

int PMPIX_Halo_exchange_commit( MPI_Halo_exchange ex );
int PMPIX_Halo_exchange( MPI_Halo_exchange ex );
int PMPIX_Halo_iexchange( MPI_Halo_exchange ex );
int PMPIX_Halo_iexchange_wait( MPI_Halo_exchange ex );
int PMPIX_Halo_cell_bind_local( MPI_Halo_exchange ex, MPI_Halo halo );
int PMPIX_Halo_cell_bind_remote( MPI_Halo_exchange ex, MPI_Halo halo, int remote, char * remote_label );

/* This is the MPI Tools Interface */

int PMPI_T_init_thread(int required, int *provided);
int PMPI_T_finalize(void);
int PMPI_T_enum_get_info(MPI_T_enum enumtype, int *num, char *name,
                         int *name_len);
int PMPI_T_enum_get_item(MPI_T_enum enumtype, int index, int *value, char *name,
                         int *name_len);
int PMPI_T_cvar_get_num(int *num_cvar);
int PMPI_T_cvar_get_info(int cvar_index, char *name, int *name_len,
                         int *verbosity, MPI_Datatype *datatype,
                         MPI_T_enum *enumtype, char *desc, int *desc_len,
                         int *bind, int *scope);
int PMPI_T_cvar_get_index(const char *name, int *cvar_index);
int PMPI_T_cvar_handle_alloc(int cvar_index, void *obj_handle,
                             MPI_T_cvar_handle *handle, int *count);
int PMPI_T_cvar_handle_free(MPI_T_cvar_handle *handle);
int PMPI_T_cvar_read(MPI_T_cvar_handle handle, void *buff);
int PMPI_T_cvar_write(MPI_T_cvar_handle handle, const void *buff);
int PMPI_T_pvar_get_num(int *num_pvar);
int PMPI_T_pvar_get_info(int pvar_index, char *name, int *name_len,
                         int *verbosity, int *var_class, MPI_Datatype *datatype,
                         MPI_T_enum *enumtype, char *desc, int *desc_len,
                         int *bind, int *readonly, int *continuous,
                         int *atomic);
int PMPI_T_pvar_get_index(char *name, int *pvar_class, int *pvar_index);
int PMPI_T_pvar_session_create(MPI_T_pvar_session *session);
int PMPI_T_pvar_session_free(MPI_T_pvar_session *session);
int PMPI_T_pvar_handle(MPI_T_pvar_session session, int pvar_index,
                       void *obj_handle, MPI_T_pvar_handle *handle, int *count);

int PMPI_T_pvar_handle_free(MPI_T_pvar_session session,
                            MPI_T_pvar_handle *handle);
int PMPI_T_pvar_start(MPI_T_pvar_session session, MPI_T_pvar_handle handle);
int PMPI_T_pvar_stop(MPI_T_pvar_session session, MPI_T_pvar_handle handle);
int PMPI_T_pvar_read(MPI_T_pvar_session session, MPI_T_pvar_handle handle,
                     void *buff);
int PMPI_T_pvar_readreset(MPI_T_pvar_session session, MPI_T_pvar_handle handle,
                          void *buff);
int PMPI_T_pvar_write(MPI_T_pvar_session session, MPI_T_pvar_handle handle,
                      const void *buff);
int PMPI_T_pvar_reset(MPI_T_pvar_session session, MPI_T_pvar_handle handle);
int PMPI_T_category_get_num(int *num_cat);
int PMPI_T_category_get_info(int cat_index, char *name, int *name_len,
                             char *desc, int *desc_len, int *num_cvars,
                             int *num_pvars, int *num_categories);
int PMPI_T_category_get_index(char *name, int *cat_index);
int PMPI_T_category_get_cvars(int cat_index, int len, int indices[]);
int PMPI_T_category_get_pvars(int cat_index, int len, int indices[]);
int PMPI_T_category_get_categories(int cat_index, int len, int indices[]);
int PMPI_T_category_changed(int *stamp);

/* probe and cancel */
int PMPI_Mprobe(int, int, MPI_Comm, MPI_Message *, MPI_Status *);
int PMPI_Mrecv(void *, int, MPI_Datatype, MPI_Message *, MPI_Status *);
int PMPI_Imrecv(void *, int, MPI_Datatype, MPI_Message *, MPI_Request *);
int PMPI_Improbe(int, int, MPI_Comm, int *, MPI_Message *, MPI_Status *);

/* One-Sided Communications */
int PMPI_Win_set_attr(MPI_Win, int, void *);
int PMPI_Win_get_attr(MPI_Win, int, void *, int *);
int PMPI_Win_free_keyval(int *);
int PMPI_Win_delete_attr(MPI_Win, int);
int PMPI_Win_create_keyval(MPI_Win_copy_attr_function *,
                           MPI_Win_delete_attr_function *, int *, void *);
int PMPI_Win_create(void *, MPI_Aint, int, MPI_Info, MPI_Comm, MPI_Win *);
int PMPI_Win_free(MPI_Win *);
int PMPI_Win_wait(MPI_Win);
int PMPI_Accumulate(const void *, int, MPI_Datatype, int, MPI_Aint, int,
                    MPI_Datatype, MPI_Op, MPI_Win);
int PMPI_Get(void *, int, MPI_Datatype, int, MPI_Aint, int, MPI_Datatype,
             MPI_Win);
int PMPI_Put(const void *, int, MPI_Datatype, int, MPI_Aint, int, MPI_Datatype,
             MPI_Win);
int PMPI_Win_complete(MPI_Win);
int PMPI_Win_fence(int, MPI_Win);
int PMPI_Win_get_group(MPI_Win, MPI_Group *);
int PMPI_Win_lock(int, int, int, MPI_Win);
int PMPI_Win_post(MPI_Group, int, MPI_Win);
int PMPI_Win_start(MPI_Group, int, MPI_Win);
int PMPI_Win_test(MPI_Win, int *);
int PMPI_Win_unlock(int, MPI_Win);
int PMPI_Win_allocate(MPI_Aint, int, MPI_Info, MPI_Comm, void *, MPI_Win *);
int PMPI_Win_set_name(MPI_Win, const char *);
int PMPI_Win_get_name(MPI_Win, char *, int *);
int PMPI_Win_set_errhandler(MPI_Win, MPI_Errhandler);
int PMPI_Win_get_errhandler(MPI_Win, MPI_Errhandler *);
int PMPI_Win_call_errhandler(MPI_Win win, int errorcode);
int PMPI_Win_allocate_shared(MPI_Aint, int, MPI_Info, MPI_Comm, void *,
                             MPI_Win *);
int PMPI_Win_create_errhandler(MPI_Win_errhandler_function *, MPI_Errhandler *);
int PMPI_Win_create_dynamic(MPI_Info, MPI_Comm, MPI_Win *);
int PMPI_Win_shared_query(MPI_Win, int, MPI_Aint *, int *, void *);
int PMPI_Win_lock_all(int, MPI_Win);
int PMPI_Win_unlock_all(MPI_Win win);
int PMPI_Win_sync(MPI_Win win);
int PMPI_Win_attach(MPI_Win, void *, MPI_Aint);
int PMPI_Win_detach(MPI_Win, const void *);
int PMPI_Win_flush(int, MPI_Win);
int PMPI_Win_flush_all(MPI_Win);
int PMPI_Win_set_info(MPI_Win, MPI_Info);
int PMPI_Win_get_info(MPI_Win, MPI_Info *);
int PMPI_Get_accumulate(const void *, int, MPI_Datatype, void *, int,
                        MPI_Datatype, int, MPI_Aint, int, MPI_Datatype, MPI_Op,
                        MPI_Win);
int PMPI_Fetch_and_op(const void *, void *, MPI_Datatype, int, MPI_Aint, MPI_Op,
                      MPI_Win);
int PMPI_Compare_and_swap(const void *, const void *, void *, MPI_Datatype, int,
                          MPI_Aint, MPI_Win);
int PMPI_Rput(const void *, int, MPI_Datatype, int, MPI_Aint, int, MPI_Datatype,
              MPI_Win, MPI_Request *);
int PMPI_Rget(void *, int, MPI_Datatype, int, MPI_Aint, int, MPI_Datatype,
              MPI_Win, MPI_Request *);
int PMPI_Raccumulate(const void *, int, MPI_Datatype, int, MPI_Aint, int,
                     MPI_Datatype, MPI_Op, MPI_Win, MPI_Request *);
int PMPI_Rget_accumulate(const void *, int, MPI_Datatype, void *, int,
                         MPI_Datatype, int, MPI_Aint, int, MPI_Datatype, MPI_Op,
                         MPI_Win, MPI_Request *);

#endif /* MPI_BUILD_PROFILING */

/************************************************************************/
/*  NOT IMPLEMENTED                                                     */
/************************************************************************/

/* Datatype Handling & Packs */
int MPI_Type_dup(MPI_Datatype , MPI_Datatype *);
int MPI_Type_get_name(MPI_Datatype , char *, int *);
int MPI_Type_create_resized (MPI_Datatype, MPI_Aint , MPI_Aint , MPI_Datatype *);
int MPI_Type_get_true_extent(MPI_Datatype , MPI_Aint *, MPI_Aint *);
int MPI_Type_get_extent(MPI_Datatype , MPI_Aint *, MPI_Aint *);
int MPI_Type_free_keyval (int *);
int MPI_Type_create_keyval (MPI_Type_copy_attr_function *, MPI_Type_delete_attr_function *, int *, void *);
int MPI_Type_delete_attr (MPI_Datatype, int);
int MPI_Type_set_attr (MPI_Datatype, int, void *);
int MPI_Type_get_attr (MPI_Datatype, int, void *, int *);
int MPI_Type_create_indexed_block (int, int, int *, MPI_Datatype, MPI_Datatype *);
int MPI_Type_get_envelope (MPI_Datatype, int *, int *, int *, int *);
int MPI_Type_get_contents (MPI_Datatype, int, int, int, int *, MPI_Aint *, MPI_Datatype *);

int MPI_Get_address (void *, MPI_Aint *);
int MPI_Type_size_x(MPI_Datatype , MPI_Count *);
int MPI_Type_get_extent_x(MPI_Datatype , MPI_Count *, MPI_Count *);
int MPI_Type_get_true_extent_x(MPI_Datatype , MPI_Count *, MPI_Count *);
int MPI_Type_match_size (int, int, MPI_Datatype *);


/* Communicator Management */
int MPI_Comm_set_errhandler(MPI_Comm , MPI_Errhandler );
int MPI_Comm_free_keyval (int *);
int MPI_Comm_delete_attr (MPI_Comm, int);
int MPI_Comm_call_errhandler (MPI_Comm, int);
int MPI_Comm_create_keyval (MPI_Comm_copy_attr_function *, MPI_Comm_delete_attr_function *, int *, void *);
int MPI_Comm_delete_attr (MPI_Comm, int);
int MPI_Comm_get_attr (MPI_Comm, int, void *, int *);
int MPI_Comm_set_attr (MPI_Comm, int, void *);
int MPI_Comm_dup_with_info(MPI_Comm , MPI_Info , MPI_Comm * );
int MPI_Comm_split_type(MPI_Comm , int , int , MPI_Info , MPI_Comm * );
int MPI_Comm_set_info(MPI_Comm , MPI_Info );
int MPI_Comm_get_info(MPI_Comm , MPI_Info * );
int MPI_Comm_call_errhandler (MPI_Comm, int);
int MPI_Comm_get_errhandler(MPI_Comm , MPI_Errhandler *);
int MPI_Comm_create_errhandler (MPI_Comm_errhandler_fn *, MPI_Errhandler *);
int MPI_Comm_idup(MPI_Comm comm, MPI_Comm *newcomm, MPI_Request *request);
int MPI_Comm_create_group(MPI_Comm , MPI_Group , int , MPI_Comm * );
int MPI_Comm_set_errhandler(MPI_Comm , MPI_Errhandler );

/* Process Creation and Management */
int MPI_Close_port (char *);
int MPI_Comm_accept (char *, MPI_Info, int, MPI_Comm, MPI_Comm *);
int MPI_Comm_connect(const char *, MPI_Info , int , MPI_Comm , MPI_Comm *);
int MPI_Comm_disconnect (MPI_Comm *);
int MPI_Comm_get_parent (MPI_Comm *);
int MPI_Comm_join (int, MPI_Comm *);
int MPI_Comm_spawn (char *, char *[], int, MPI_Info, int, MPI_Comm, MPI_Comm *, int[]);
int MPI_Comm_spawn_multiple (int, char *[], char **[], int[], MPI_Info[], int, MPI_Comm, MPI_Comm *, int[]);
int MPI_Lookup_name(const char *, MPI_Info , char *);
int MPI_Open_port (MPI_Info, char *);
int MPI_Publish_name (char *, MPI_Info, char *);
int MPI_Unpublish_name (char *, MPI_Info, char *);
  
/* Error Management */
int MPI_Add_error_class (int *);
int MPI_Add_error_code (int, int *);
int MPI_Add_error_string (int, char *);

/* Getters */
int MPI_Is_thread_main (int *);
int MPI_Query_thread (int *);
int MPI_Get_library_version(char *, int *);
  
/* Collectives */
int MPI_Reduce_scatter_block(void *, void *, int , MPI_Datatype , MPI_Op , MPI_Comm );
int MPI_Reduce_local(const void *, void *, int, MPI_Datatype, MPI_Op);

/* Extended Collective Operations */
int MPI_Alltoallw (void *, int[], int[], MPI_Datatype[], void *, int[], int[], MPI_Datatype[], MPI_Comm);

/* dist graph operations */
int MPI_Dist_graph_neighbors_count(MPI_Comm , int *, int *, int *);
int MPI_Dist_graph_neighbors(MPI_Comm , int , int [], int [], int , int [], int []);
int MPI_Dist_graph_create(MPI_Comm , int , const int [],const int [], const int [],const int [],MPI_Info , int , MPI_Comm *);
int MPI_Dist_graph_create_adjacent(MPI_Comm ,int , const int [],const int [],int , const int [],const int [],MPI_Info , int , MPI_Comm *);

/* Error handling */
int MPI_File_create_errhandler(MPI_File_errhandler_function *, MPI_Errhandler *);
int PMPI_File_create_errhandler(MPI_File_errhandler_function *file_errhandler_fn, MPI_Errhandler *errhandler);
int MPI_File_call_errhandler(void * , int );

/* MPIX methods */
int MPIX_Comm_failure_ack( MPI_Comm  );
int MPIX_Comm_failure_get_acked( MPI_Comm , MPI_Group * );
int MPIX_Comm_agree(MPI_Comm , int *);
int MPIX_Comm_revoke(MPI_Comm );
int MPIX_Comm_shrink(MPI_Comm , MPI_Comm *);

/* probe and cancel */
int MPI_Mprobe(int , int , MPI_Comm , MPI_Message *, MPI_Status *);
int MPI_Mrecv(void *, int , MPI_Datatype , MPI_Message *, MPI_Status *);
int MPI_Imrecv(void *, int , MPI_Datatype , MPI_Message *, MPI_Request *);
int MPI_Improbe(int , int , MPI_Comm , int *, MPI_Message *, MPI_Status *);
/************************************************************************/
/* END NOT IMPLEMENTED                                                     */
/************************************************************************/


/* For ROMIO compatibility */
#define MPICH_ATTR_POINTER_WITH_TYPE_TAG(a,b) 
#define MPI_AINT_FMT_HEX_SPEC "%X"

#ifdef __cplusplus
}
#endif
#endif /* __SCTK_MPC_MPI_H_ */

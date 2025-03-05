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
/* #                                                                      # */
/* ######################################################################## */
#ifndef __mpc__H
#define __mpc__H

#ifdef __cplusplus
extern "C"
{
#endif

/* #include "mpcthread.h" */
/* #include "mpcalloc.h" */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sctk_types.h>

  int PMPC_Main (int argc, char **argv);
  int PMPC_User_Main (int argc, char **argv);

#define MPC_THREAD_SINGLE 0
#define MPC_THREAD_FUNNELED 1
#define MPC_THREAD_SERIALIZED 2
#define  MPC_THREAD_MULTIPLE 3

  
  
#define SCTK_COMMON_DATA_TYPE_COUNT 70
#define SCTK_USER_DATA_TYPES_MAX 4000
#define SCTK_DERIVED_DATATYPE_BASE (SCTK_COMMON_DATA_TYPE_COUNT + SCTK_USER_DATA_TYPES_MAX)
  
/** \brief Macro to obtain the total number of datatypes */
#define MPC_TYPE_COUNT                                                         \
  (SCTK_COMMON_DATA_TYPE_COUNT + 2 * SCTK_USER_DATA_TYPES_MAX)

  typedef int MPC_Message;

  typedef sctk_msg_count_t mpc_msg_count;

  typedef unsigned int mpc_pack_indexes_t;
  typedef long mpc_pack_absolute_indexes_t;
  typedef long MPC_Aint;
  typedef long MPC_Count;
  typedef sctk_communicator_t MPC_Comm;

  typedef struct {
    int task_nb;
    /* Task list rank are valid in COMM_WORLD  */
    int *task_list_in_global_ranks;
} MPC_Group_t;

typedef MPC_Group_t *MPC_Group;

extern const MPC_Group_t mpc_group_empty;
extern const MPC_Group_t mpc_group_null;

#define MPC_GROUP_EMPTY &mpc_group_empty
#define MPC_GROUP_NULL ((MPC_Group)NULL)

/* #define MPC_STATUS_SIZE 80 */
/* #define MPC_REQUEST_SIZE 30 */

/* Has to match an sctk_datatype_t */
typedef sctk_datatype_t MPC_Datatype;

typedef void(MPC_Handler_function)(void *, int *, ...);
typedef int MPC_Errhandler;

/** Reduction Operations */
typedef sctk_Op_f MPC_Op_f;
typedef sctk_Op_User_function MPC_User_function;
typedef sctk_Op MPC_Op;
#define MPC_OP_INIT {NULL,NULL}

typedef sctk_status_t MPC_Status;
#define MPC_STATUS_INIT {MPC_ANY_SOURCE,MPC_ANY_TAG,MPC_SUCCESS,0,0}

struct sctk_thread_ptp_message_s;


/** Generalized requests functions **/
typedef sctk_Grequest_query_function MPC_Grequest_query_function;
typedef sctk_Grequest_cancel_function MPC_Grequest_cancel_function;
typedef sctk_Grequest_free_function MPC_Grequest_free_function;
/** Extended Generalized requests functions **/
typedef sctk_Grequest_poll_fn MPCX_Grequest_poll_fn;
typedef sctk_Grequest_wait_fn MPCX_Grequest_wait_fn;
/** Generalized Request classes **/
typedef sctk_Request_class MPCX_Request_class;

/** MPC Requests */
typedef sctk_request_t MPC_Request;
extern MPC_Request mpc_request_null;

#define MPC_REQUEST_NULL mpc_request_null

#define MPC_COMM_WORLD SCTK_COMM_WORLD
#define MPC_COMM_SELF SCTK_COMM_SELF
#define MPC_COMM_NULL SCTK_COMM_NULL
#define MPC_SUCCESS SCTK_SUCCESS

#define MPC_UNDEFINED (-1)
/* Communication argument parameters */
#define MPC_ERR_BUFFER                  1  /* Invalid buffer pointer */
#define MPC_ERR_COUNT                   2  /* Invalid count argument */
#define MPC_ERR_TYPE                    3  /* Invalid datatype argument */
#define MPC_ERR_TAG                     4  /* Invalid tag argument */
#define MPC_ERR_COMM                    5  /* Invalid communicator */
#define MPC_ERR_RANK                    6  /* Invalid rank */
#define MPC_ERR_ROOT                    8  /* Invalid root */
#define MPC_ERR_TRUNCATE               15  /* Message truncated on receive */
#define MPC_ERR_NOT_SAME               39  /* Collective argument not identical on all processess,
                                              or collective routines called in a different order
																							by different processes */

/* MPC Objects (other than COMM) */
#define MPC_ERR_GROUP                   9  /* Invalid group */
#define MPC_ERR_OP                     10  /* Invalid operation */
#define MPC_ERR_REQUEST                 7  /* Invalid mpc_request handle */

/* Special topology argument parameters */
#define MPC_ERR_TOPOLOGY               11  /* Invalid topology */
#define MPC_ERR_DIMS                   12	 /* Invalid dimension argument */

/* All other arguments.  This is a class with many kinds */
#define MPC_ERR_ARG                    13  /* Invalid argument */
#define MPC_ERR_PORT                   27  /* Invalid port name passed to MPI_COMM_CONNECT */
#define MPC_ERR_SERVICE                28  /* Invalid service name passed to MPI_UNPUBLISH_NAME */
#define MPC_ERR_NAME                   29  /* Invalid service name passed to MPI_LOOKUP_NAME */
#define MPC_ERR_WIN                    30  /* Invalid win argument */
#define MPC_ERR_SIZE                   31  /* Invalid size argument */
#define MPC_ERR_DISP                   32  /* Invalid disp argument */
#define MPC_ERR_INFO                   33  /* Invalid info argument */
#define MPC_ERR_LOCKTYPE               34  /* Invalid locktype argument */
#define MPC_ERR_ASSERT                 35  /* Invalid assert argument */

/* Error on File handling*/
#define MPC_ERR_FILE                   38  /* Invalid file handle */
#define MPC_ERR_AMODE                  40  /* Error related to the amode passed to MPI_FILE_OPEN */
#define MPC_ERR_UNSUPPORTED_DATAREP    41  /* Unsupported datarep passed to MPI_FILE_SET_VIEW */
#define MPC_ERR_NO_SUCH_FILE           43  /* File does not exist */
#define MPC_ERR_FILE_EXISTS            44  /* File exists */
#define MPC_ERR_BAD_FILE               45  /* Invalid file name (e.g., path name too long) */
#define MPC_ERR_ACCESS                 46  /* Permission denied */
#define MPC_ERR_READ_ONLY              49  /* Read-only file or file system */
#define MPC_ERR_FILE_IN_USE            50  /* File operation could not completed, as the file is
                                              currently open by some process */
#define MPC_ERR_IO                     53  /* Other I/O error */

/* Multiple completion has two special error classes */
#define MPC_ERR_IN_STATUS              18  /* Look in status for error value */
#define MPC_ERR_PENDING                19  /* Pending request */

/* Error with comm attributes (keyval) */
#define MPC_ERR_KEYVAL	               20  /* Invalid keyval has been passed */
#define MPC_ERR_INFO_KEY               23  /* Key onger than MPI_MAX_INFO_KEY */
#define MPC_ERR_INFO_VALUE             24  /* Value longer than MPI_MAX_INFO_VAL */
#define MPC_ERR_INFO_NOKEY             25  /* Invalid key passed to MPI_INFO_DELETE */

/* Error with memory */
#define MPC_ERR_NO_MEM 		             21  /* MPI_ALLOC_MEM failed because memory is exhausted */
#define MPC_ERR_BASE                   22  /* Invalid base passed to MPI_FREE_MEM */

/* Other errors that are not simply an invalid argument */
#define MPC_ERR_SPAWN                  26  /* Error in spawning processes */
#define MPC_ERR_RMA_CONFLICT               36  /* Conflicting accesses to window */
#define MPC_ERR_RMA_SYNC                   37  /* Wrong synchronization of RMA calls */
#define MPC_ERR_UNSUPPORTED_OPERATION  42  /* Unsupported operation, such as seeking on a file which
                                              supports sequential access only*/
#define MPC_ERR_NO_SPACE               47  /* Not enough space */
#define MPC_ERR_QUOTA                  48  /* Quota exceeded */
#define MPC_ERR_DUP_DATAREP            51  /* Conversion functions could not be regiestered because a
																							data representation identifier that was already defined
																							was passed to MPI_REGISTER_DATAREP */
#define MPC_ERR_CONVERSION             52  /* An error occured in a user supplied data conversion function */
#define MPC_ERR_OTHER                  16  /* Other error; use Error_string */

#define MPC_ERR_UNKNOWN                14  /* Unknown error */
#define MPC_ERR_INTERN                 17  /* Internal error code    */

#define MPCR_ERRORS_THROW_EXCEPTIONS   55

#define MPC_NOT_IMPLEMENTED            56

#define MPC_ERR_RMA_FLAVOR 57 /* Wrong type of RMA window */

/* HOLE @ 58 */

#define MPC_T_ERR_MEMORY 59          /* Out of memory */
#define MPC_T_ERR_NOT_INITIALIZED 60 /* Interface not initialized */
#define MPC_T_ERR_CANNOT_INIT                                                  \
  61 /* Interface not in the state to                                          \
        be initialized */
#define MPC_T_ERR_INVALID_INDEX                                                \
  62                                  /* The index is invalid or               \
                                         has been deleted  */
#define MPC_T_ERR_INVALID_ITEM 63     /* Item index queried is out of range */
#define MPC_T_ERR_INVALID_HANDLE 64   /* The handle is invalid */
#define MPC_T_ERR_OUT_OF_HANDLES 65   /* No more handles available */
#define MPC_T_ERR_OUT_OF_SESSIONS 66  /* No more sessions available */
#define MPC_T_ERR_INVALID_SESSION 67  /* Session argument is not valid */
#define MPC_T_ERR_CVAR_SET_NOT_NOW 68 /* Cvar can't be set at this moment */
#define MPC_T_ERR_CVAR_SET_NEVER                                               \
  69                                   /* Cvar can't be set until              \
                                           end of execution */
#define MPC_T_ERR_PVAR_NO_STARTSTOP 70 /* Pvar can't be started or stopped */
#define MPC_T_ERR_PVAR_NO_WRITE 71     /* Pvar can't be written or reset */
#define MPC_T_ERR_PVAR_NO_ATOMIC 72    /* Pvar can't be R/W atomically */
#define MPC_T_ERR_INVALID_NAME 73      /* Requested name is invalid */
#define MPC_ERR_LASTCODE 74

#define MPC_STATUS_IGNORE NULL
#define MPC_STATUSES_IGNORE NULL
#define MPC_ANY_TAG SCTK_ANY_TAG
#define MPC_ANY_SOURCE SCTK_ANY_SOURCE
#define MPC_PROC_NULL SCTK_PROC_NULL
#define MPC_MAX_PROCESSOR_NAME 255
#define MPC_ROOT -4
#define MPC_MAX_OBJECT_NAME 256
#define MPC_MAX_LIBRARY_VERSION_STRING 8192

/* Type Keyval Defines */

#define MPC_KEYVAL_INVALID -1

#define MPC_ERRHANDLER_NULL -1
#define MPC_ERRORS_RETURN -6
#define MPC_ERRORS_ARE_FATAL -7
#define MPC_TYPE_NULL_DELETE_FN (NULL)
#define MPC_TYPE_NULL_COPY_FN (NULL)
#define MPC_TYPE_NULL_DUP_FN ((void *)0x3)

/********************************************************************/
/*Special TAGS                                                      */
/********************************************************************/
#define MPC_GATHERV_TAG -2
#define MPC_GATHER_TAG -3
#define MPC_SCATTERV_TAG -4
#define MPC_SCATTER_TAG -5
#define MPC_ALLTOALL_TAG -6
#define MPC_ALLTOALLV_TAG -7
#define MPC_ALLTOALLW_TAG -8
#define MPC_BROADCAST_TAG -9
#define MPC_BARRIER_TAG -10
#define MPC_ALLGATHER_TAG -11
#define MPC_ALLGATHERV_TAG -12
#define MPC_REDUCE_TAG -13
#define MPC_ALLREDUCE_TAG -14
#define MPC_REDUCE_SCATTER_TAG -15
#define MPC_REDUCE_SCATTER_BLOCK_TAG -16
#define MPC_SCAN_TAG -17
#define MPC_EXSCAN_TAG -18
#define MPC_IBARRIER_TAG -19
#define MPC_IBCAST_TAG -20
#define MPC_IGATHER_TAG -21
#define MPC_IGATHERV_TAG -22
#define MPC_ISCATTER_TAG -23
#define MPC_ISCATTERV_TAG -24
#define MPC_IALLGATHER_TAG -25
#define MPC_IALLGATHERV_TAG -26
#define MPC_IALLTOALL_TAG -27
#define MPC_IALLTOALLV_TAG -28
#define MPC_IALLTOALLW_TAG -29
#define MPC_IREDUCE_TAG -30
#define MPC_IALLREDUCE_TAG -31
#define MPC_IREDUCE_SCATTER_TAG -32
#define MPC_IREDUCE_SCATTER_BLOCK_TAG -33
#define MPC_ISCAN_TAG -34
#define MPC_IEXSCAN_TAG -35
#define MPC_COPY_TAG -36
/* TAG of minimum value */
#define MPC_LAST_TAG -37



/* Here we define the type of an MPC_Info as an int
 * this type is alliased to MPI_Info at mpc_mpi.h:224
 */
typedef int MPC_Info;

#define MPC_CREATE_INTERN_FUNC(name) extern  const MPC_Op MPC_##name

MPC_CREATE_INTERN_FUNC (SUM);
MPC_CREATE_INTERN_FUNC (MAX);
MPC_CREATE_INTERN_FUNC (MIN);
MPC_CREATE_INTERN_FUNC (PROD);
MPC_CREATE_INTERN_FUNC (LAND);
MPC_CREATE_INTERN_FUNC (BAND);
MPC_CREATE_INTERN_FUNC (LOR);
MPC_CREATE_INTERN_FUNC (BOR);
MPC_CREATE_INTERN_FUNC (LXOR);
MPC_CREATE_INTERN_FUNC (BXOR);
MPC_CREATE_INTERN_FUNC (MINLOC);
MPC_CREATE_INTERN_FUNC (MAXLOC);

    /*TYPES*/
#define MPC_DATATYPE_NULL ((MPC_Datatype)-1)
#define MPC_UB ((MPC_Datatype)-2)
#define MPC_LB ((MPC_Datatype)-3)
#define MPC_PACKED 0
#define MPC_BYTE 1
#define MPC_SHORT 2
#define MPC_INT 3
#define MPC_LONG 4
#define MPC_FLOAT 5
#define MPC_DOUBLE 6
#define MPC_UNSIGNED_CHAR  7
#define MPC_UNSIGNED_SHORT 8
#define MPC_UNSIGNED  9
#define MPC_UNSIGNED_LONG  10
#define MPC_LONG_DOUBLE  11
#define MPC_LONG_LONG 12
#define MPC_CHAR 13
#define MPC_LOGICAL 22
#define MPC_INTEGER1 24
#define MPC_INTEGER2 25
#define MPC_INTEGER4 26
#define MPC_INTEGER8 27
#define MPC_REAL4 28
#define MPC_REAL8 29
#define MPC_REAL16 30
#define MPC_SIGNED_CHAR 31
#define MPC_UNSIGNED_LONG_LONG 33
#define MPC_INT8_T 34
#define MPC_UINT8_T 35
#define MPC_INT16_T 36
#define MPC_UINT16_T 37
#define MPC_INT32_T 38
#define MPC_UINT32_T 39
#define MPC_INT64_T 40
#define MPC_UINT64_T 41
#define MPC_WCHAR 45
#define MPC_INTEGER16 46
#define MPC_AINT 49
#define MPC_OFFSET 50
#define MPC_COUNT 51
#define MPC_LONG_LONG_INT 52
#define MPC_C_BOOL 53
#define MPC_CHARACTER 54
#define MPC_INTEGER 55
#define MPC_REAL 56
#define MPC_DOUBLE_PRECISION 57
#define MPC_UNSIGNED_LONG_LONG_INT  58

/* for comm_split method */
#define MPC_COMM_TYPE_SHARED 1
#define MPC_COMM_TYPE_SHARED_TR 2
#define MPC_COMM_TYPE_SOCKET 3
#define MPC_COMM_TYPE_SOCKET_TR 4
#define MPC_COMM_TYPE_NUMA 5
#define MPC_COMM_TYPE_NUMA_TR 6
#define MPC_COMM_TYPE_MPC_PROCESS 7
#define MPC_COMM_TYPE_MPC_PROCESS_TR 8

/* BE VERY CAREFUL HERE /!\/!\/!\/!\/!\/!\/!\/!\
 *  You have to note that these types
 *  are offseted of SCTK_DERIVED_DATATYPE_BASE
 *  actually making them derived ones.
 *  As common ones they are initialized in
 *  \ref sctk_common_datatype_init however
 *  they are derived ones !
 * 
 * See how the value is incremented and how MPC_STRUCT_DATATYPE_COUNT
 * is the last value plus 1.
 * 
 */
#define MPC_FLOAT_INT (SCTK_DERIVED_DATATYPE_BASE)
#define MPC_LONG_INT (SCTK_DERIVED_DATATYPE_BASE + 1)
#define MPC_DOUBLE_INT  (SCTK_DERIVED_DATATYPE_BASE + 2)
#define MPC_SHORT_INT  (SCTK_DERIVED_DATATYPE_BASE + 3)
#define MPC_2INT  (SCTK_DERIVED_DATATYPE_BASE + 4)
#define MPC_2FLOAT  (SCTK_DERIVED_DATATYPE_BASE + 5)
#define MPC_COMPLEX  (SCTK_DERIVED_DATATYPE_BASE + 6)
#define MPC_2DOUBLE_PRECISION  (SCTK_DERIVED_DATATYPE_BASE + 7)
#define MPC_LONG_DOUBLE_INT  (SCTK_DERIVED_DATATYPE_BASE + 8)
#define MPC_COMPLEX8  (SCTK_DERIVED_DATATYPE_BASE + 9)
#define MPC_COMPLEX16  (SCTK_DERIVED_DATATYPE_BASE + 10)
#define MPC_COMPLEX32  (SCTK_DERIVED_DATATYPE_BASE + 11)
#define MPC_DOUBLE_COMPLEX  (SCTK_DERIVED_DATATYPE_BASE + 12)
#define MPC_2INTEGER (SCTK_DERIVED_DATATYPE_BASE + 13)
#define MPC_2REAL (SCTK_DERIVED_DATATYPE_BASE + 14)

/* /!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\
 * If you change anything in this section update MPC_STRUCT_DATATYPE_COUNT
 * otherwise the first derived datatype created
 * will overwrite your last datatype
 * /!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\
 */
#define MPC_STRUCT_DATATYPE_COUNT 15

/* Aliased struct data-types */
#define MPC_C_COMPLEX MPC_COMPLEX
#define MPC_C_FLOAT_COMPLEX MPC_COMPLEX8
#define MPC_C_DOUBLE_COMPLEX MPC_COMPLEX16
#define MPC_C_LONG_DOUBLE_COMPLEX MPC_COMPLEX32

/* Predefined MPI datatypes corresponding to both C and Fortran datatypes */
#define MPC_CXX_BOOL 59
#define MPC_CXX_FLOAT_COMPLEX MPC_COMPLEX8
#define MPC_CXX_DOUBLE_COMPLEX MPC_COMPLEX16
#define MPC_CXX_LONG_DOUBLE_COMPLEX MPC_COMPLEX32

/* Datatype decoders */

typedef enum {
  MPC_COMBINER_UNKNOWN = 0,
  MPC_COMBINER_NAMED = 1,
  MPC_COMBINER_DUP = 2,
  MPC_COMBINER_CONTIGUOUS = 3,
  MPC_COMBINER_VECTOR = 4,
  MPC_COMBINER_HVECTOR = 5,
  MPC_COMBINER_INDEXED = 6,
  MPC_COMBINER_HINDEXED = 7,
  MPC_COMBINER_INDEXED_BLOCK = 8,
  MPC_COMBINER_HINDEXED_BLOCK = 9,
  MPC_COMBINER_STRUCT = 10,
  MPC_COMBINER_SUBARRAY = 11,
  MPC_COMBINER_DARRAY = 12,
  MPC_COMBINER_F90_REAL = 13,
  MPC_COMBINER_F90_COMPLEX = 14,
  MPC_COMBINER_F90_INTEGER = 15,
  MPC_COMBINER_RESIZED = 16,
  /* *_INTEGER COMBINER ARE DEPRECATED
   * in MPI 3.0 consequently they
   * are never returned by get_envelope */
  MPC_COMBINER_HINDEXED_INTEGER = 17,
  MPC_COMBINER_STRUCT_INTEGER = 18,
  MPC_COMBINER_HVECTOR_INTEGER = 19,
  MPC_COMBINER_DUMMY,
  MPC_COMBINER_COUNT__
} MPC_Type_combiner;

/*Initialisation */
int MPC_Init(int *argc, char ***argv);
int MPC_Init_thread(int *argc, char ***argv, int required, int *provided);
int MPC_Query_thread(int *provided);
int MPC_Initialized(int *flag);
int MPC_Finalize(void);
int MPC_Abort(MPC_Comm, int);

typedef enum {
  MPC_HAVE_OPTION_HLS,
  MPC_HAVE_OPTION_ETLS_COW,
  MPC_HAVE_OPTION_ETLS_OPTIMIZED,
  MPC_HAVE_OPTION_END
} MPC_Config_Status_t;

int MPC_Config_Status(MPC_Config_Status_t option);
void MPC_Config_Status_Print(FILE *fd);
char *MPC_Config_Status_Name(MPC_Config_Status_t option);

/* MPI Topology informations */
int MPC_Comm_rank(MPC_Comm comm, int *rank);
int MPC_Comm_size(MPC_Comm comm, int *size);
int MPC_Comm_remote_size(MPC_Comm comm, int *size);
int MPC_Comm_test_inter(MPC_Comm comm, int *flag);

/* Node topology */
int MPC_Node_rank(int *rank);
int MPC_Node_number(int *number);

/* Processors topology */
int MPC_Processor_rank(int *rank);
int MPC_Processor_number(int *number);

/* Process global numbering */
int MPC_Process_rank(int *rank);
int MPC_Process_number(int *number);

/* Process local numbering */
int MPC_Local_process_rank(int *rank);
int MPC_Local_process_number(int *number);

/* Task global topology */
int MPC_Task_rank(int *rank);
int MPC_Task_number(int *number);

/* Task local topology */
int MPC_Local_task_rank(int *rank);
int MPC_Local_task_number(int *number);

int MPC_Get_multithreading(char *name, int size);
int MPC_Get_networking(char *name, int size);
int MPC_Get_processor_name(char *name, int *resultlen);

/*Collective operations */
int MPC_Barrier(MPC_Comm comm);
int MPC_Bcast(void *buffer, mpc_msg_count count, MPC_Datatype datatype,
              int root, MPC_Comm comm);
int MPC_Allreduce(void *sendbuf, void *recvbuf, mpc_msg_count count,
                  MPC_Datatype datatype, MPC_Op op, MPC_Comm comm);
int MPC_Reduce(void *sendbuf, void *recvbuf, mpc_msg_count count,
               MPC_Datatype datatype, MPC_Op op, int root, MPC_Comm comm);
int MPC_Op_create(MPC_User_function *, int, MPC_Op *);
int MPC_Op_free(MPC_Op *);

/*P-t-P Communications */
int MPC_Isend(void *buf, mpc_msg_count count, MPC_Datatype datatype, int dest,
              int tag, MPC_Comm comm, MPC_Request *request);
int MPC_Ibsend(void *, mpc_msg_count, MPC_Datatype, int, int, MPC_Comm,
               MPC_Request *);
int MPC_Issend(void *, mpc_msg_count, MPC_Datatype, int, int, MPC_Comm,
               MPC_Request *);
int MPC_Irsend(void *, mpc_msg_count, MPC_Datatype, int, int, MPC_Comm,
               MPC_Request *);

int MPC_Irecv(void *buf, mpc_msg_count count, MPC_Datatype datatype, int source,
              int tag, MPC_Comm comm, MPC_Request *request);

int MPC_Wait(MPC_Request *request, MPC_Status *status);
int MPC_Waitall(mpc_msg_count, MPC_Request *, MPC_Status *);
int MPC_Waitsome(mpc_msg_count, MPC_Request *, mpc_msg_count *, mpc_msg_count *,
                 MPC_Status *);
int MPC_Waitany(mpc_msg_count count, MPC_Request array_of_requests[],
                mpc_msg_count *index, MPC_Status *status);
int MPC_Wait_pending(MPC_Comm comm);
int MPC_Wait_pending_all_comm(void);

int MPC_Test(MPC_Request *, int *, MPC_Status *);
int MPC_Test_no_check(MPC_Request *, int *, MPC_Status *);
int MPC_Test_check(MPC_Request *, int *, MPC_Status *);

int MPC_Iprobe(int, int, MPC_Comm, int *, MPC_Status *);
int MPC_Probe(int, int, MPC_Comm, MPC_Status *);
int MPC_Get_count(MPC_Status *, MPC_Datatype, mpc_msg_count *);

int MPC_Send(void *, mpc_msg_count, MPC_Datatype, int, int, MPC_Comm);
int MPC_Bsend(void *, mpc_msg_count, MPC_Datatype, int, int, MPC_Comm);
int MPC_Ssend(void *, mpc_msg_count, MPC_Datatype, int, int, MPC_Comm);
int MPC_Rsend(void *, mpc_msg_count, MPC_Datatype, int, int, MPC_Comm);
int MPC_Recv(void *, mpc_msg_count, MPC_Datatype, int, int, MPC_Comm,
             MPC_Status *);

int MPC_Sendrecv(void *, mpc_msg_count, MPC_Datatype, int, int, void *,
                 mpc_msg_count, MPC_Datatype, int, int, MPC_Comm, MPC_Status *);

/*Status */
int MPC_Cancel(MPC_Request *);

/*Gather */
int MPC_Gather(void *, mpc_msg_count, MPC_Datatype, void *, mpc_msg_count,
               MPC_Datatype, int, MPC_Comm);
int MPC_Gatherv(void *, mpc_msg_count, MPC_Datatype, void *, mpc_msg_count *,
                mpc_msg_count *, MPC_Datatype, int, MPC_Comm);
int MPC_Allgather(void *, mpc_msg_count, MPC_Datatype, void *, mpc_msg_count,
                  MPC_Datatype, MPC_Comm);
int MPC_Allgatherv(void *, mpc_msg_count, MPC_Datatype, void *, mpc_msg_count *,
                   mpc_msg_count *, MPC_Datatype, MPC_Comm);

/*Scatter */
int MPC_Scatter(void *, mpc_msg_count, MPC_Datatype, void *, mpc_msg_count,
                MPC_Datatype, int, MPC_Comm);
int MPC_Scatterv(void *, mpc_msg_count *, mpc_msg_count *, MPC_Datatype, void *,
                 mpc_msg_count, MPC_Datatype, int, MPC_Comm);

/*Alltoall */
int MPC_Alltoall(void *, mpc_msg_count, MPC_Datatype, void *, mpc_msg_count,
                 MPC_Datatype, MPC_Comm);
int MPC_Alltoallv(void *, mpc_msg_count *, mpc_msg_count *, MPC_Datatype,
                  void *, mpc_msg_count *, mpc_msg_count *, MPC_Datatype,
                  MPC_Comm);

/*Informations */
int MPC_Get_processor_name(char *, int *);

/*Groups */
int MPC_Comm_group(MPC_Comm, MPC_Group *);
int MPC_Comm_remote_group(MPC_Comm, MPC_Group *);
int MPC_Group_free(MPC_Group *);
int MPC_Group_incl(MPC_Group, int, int *, MPC_Group *);
int MPC_Group_difference(MPC_Group, MPC_Group, MPC_Group *);

/*Communicators */
int MPC_Convert_to_intercomm(MPC_Comm comm, MPC_Group group);
int MPC_Comm_create_list(MPC_Comm, int *list, int nb_elem, MPC_Comm *);
int MPC_Comm_create(MPC_Comm, MPC_Group, MPC_Comm *);
int MPC_Comm_free(MPC_Comm *);
int MPC_Comm_dup(MPC_Comm, MPC_Comm *);
int MPC_Comm_split(MPC_Comm, int, int, MPC_Comm *);

/*Error_handler */
#define MPC_MAX_ERROR_STRING 512
  void MPC_Default_error (MPC_Comm * comm, int *error, char *msg,
			  char *file, int line);
  void MPC_Return_error (MPC_Comm * comm, int *error, ...);
  int MPC_Errhandler_create (MPC_Handler_function *, MPC_Errhandler *);
  int MPC_Errhandler_set (MPC_Comm, MPC_Errhandler);
  int MPC_Errhandler_get (MPC_Comm, MPC_Errhandler *);
  int MPC_Errhandler_free (MPC_Errhandler *);
  int MPC_Error_string (int, char *, int *);
  int MPC_Error_class (int, int *);

  /*Timing */
  double MPC_Wtime (void);
  double MPC_Wtick (void);

  /*Types */
  int MPC_Type_size (MPC_Datatype, size_t *);
  int MPC_Type_is_allocated (MPC_Datatype datatype, int * flag );
  int MPC_Type_hcontiguous (MPC_Datatype *, size_t);
  int MPC_Type_free (MPC_Datatype * datatype);
  int MPC_Type_dup( MPC_Datatype old_type, MPC_Datatype * new_type ); 
  int MPC_Type_set_name( MPC_Datatype datatype, char *name );
  int MPC_Type_get_name( MPC_Datatype datatype, char *name, int * resultlen );
  int MPC_Type_get_envelope(MPC_Datatype datatype, int *num_integers, int *num_addresses, int *num_datatypes, int *combiner);
  int MPC_Type_get_contents( MPC_Datatype datatype, 
			     int max_integers,
			     int max_addresses,
			     int max_datatypes,
			     int array_of_integers[],
			     MPC_Aint array_of_addresses[],
			     MPC_Datatype array_of_datatypes[]);
  int MPC_Type_commit( MPC_Datatype * type );
  int MPCX_Type_debug( MPC_Datatype type );

  typedef int(MPC_Type_copy_attr_function)(MPC_Datatype old_type,
                                           int type_keyval, void *extra_state,
                                           void *attribute_val_in,
                                           void *attribute_val_out, int *flag);
  typedef int(MPC_Type_delete_attr_function)(MPC_Datatype datatype,
                                             int type_keyval,
                                             void *attribute_val,
                                             void *extra_state);

  /*MPC specific function */
  int MPC_Copy_in_buffer (void *inbuffer, void *outbuffer, MPC_Datatype datatype);
  int MPC_Copy_from_buffer (void *inbuffer, void *outbuffer, MPC_Datatype datatype);

  int MPC_Derived_datatype (MPC_Datatype * datatype,
			    mpc_pack_absolute_indexes_t * begins,
			    mpc_pack_absolute_indexes_t * ends,
			    MPC_Datatype * types,
			    unsigned long count,
			    mpc_pack_absolute_indexes_t lb, int is_lb,
			    mpc_pack_absolute_indexes_t ub, int is_ub);

  
  int MPC_Type_get_true_extent(MPC_Datatype datatype, MPC_Aint *true_lb, MPC_Aint *true_extent);
  
  int MPC_Type_convert_to_derived( MPC_Datatype in_datatype, MPC_Datatype * out_datatype );
  int MPC_Type_use (MPC_Datatype datatype);
/*   int MPC_Get_keys (void **keys); */
/*   int MPC_Set_keys (void *keys); */
/*   int MPC_Get_requests (void **requests); */
/*   int MPC_Set_requests (void *requests); */
/*   int MPC_Get_groups (void **groups); */
/*   int MPC_Set_groups (void *groups); */
/*   int MPC_Get_errors (void **errors); */
/*   int MPC_Set_errors (void *errors); */
/*   int MPC_Set_buffers (void *buffers); */
/*   int MPC_Get_buffers (void **buffers); */
/*   int MPC_Get_comm_type (void **comm_type); */
/*   int MPC_Set_comm_type (void *comm_type); */
/*   int MPC_Get_op (void **op); */
/*   int MPC_Set_op (void *op); */


  /*Requests */
  int MPC_Request_free (MPC_Request *);

  /*Scheduling */
  int MPC_Proceed (void);
  int MPC_Checkpoint (void);
  int MPC_Checkpoint_timed (unsigned int sec, MPC_Comm comm);
  int MPC_Migrate (void);
  int MPC_Restart (int rank);
  int MPC_Restarted (int *flag);

  typedef struct
  {
    int virtual_cpuid;
    double usage;
  } MPC_Activity_t;

  int MPC_Get_activity (int nb_item, MPC_Activity_t * tab,
			double *process_act);
  int MPC_Move_to (int process, int cpuid);

  /*Packs */
  int MPC_Open_pack (MPC_Request * request);
  int MPC_Default_pack (mpc_msg_count count,
			mpc_pack_indexes_t * begins,
			mpc_pack_indexes_t * ends, MPC_Request * request);
  int
    MPC_Default_pack_absolute (mpc_msg_count count,
			       mpc_pack_absolute_indexes_t * begins,
			       mpc_pack_absolute_indexes_t * ends,
			       MPC_Request * request);
  int MPC_Add_pack (void *buf, mpc_msg_count count,
		    mpc_pack_indexes_t * begins,
		    mpc_pack_indexes_t * ends, MPC_Datatype datatype,
		    MPC_Request * request);
  int
    MPC_Add_pack_absolute (void *buf, mpc_msg_count count,
			   mpc_pack_absolute_indexes_t * begins,
			   mpc_pack_absolute_indexes_t * ends,
			   MPC_Datatype datatype, MPC_Request * request);

  int MPC_Add_pack_default (void *buf, MPC_Datatype datatype,
			    MPC_Request * request);
  int
    MPC_Add_pack_default_absolute (void *buf, MPC_Datatype datatype,
				   MPC_Request * request);
  int MPC_Isend_pack (int dest, int tag, MPC_Comm comm,
		      MPC_Request * request);
  int MPC_Irecv_pack (int source, int tag, MPC_Comm comm,
		      MPC_Request * request);
  void *tmp_malloc (size_t size);



  /* MPI Info management */
 
/* Matches the one of MPI_INFO_NULL @ mpc_mpi.h:207 */
#define MPC_INFO_NULL (-1)
/* Maximum length for keys and values
 * they are both defined for MPC and MPI variants */
/*1 MB */
#define MPC_MAX_INFO_VAL 1048576
#define MPC_MAX_INFO_KEY 256

  
  int MPC_Info_set( MPC_Info, const char *, const char * );
  int MPC_Info_free( MPC_Info * );
  int MPC_Info_create( MPC_Info * );
  int MPC_Info_delete( MPC_Info , const char * );
  int MPC_Info_get(MPC_Info , const char *, int , char *, int *);
  int MPC_Info_dup( MPC_Info , MPC_Info * );
  int MPC_Info_get_nkeys (MPC_Info, int *);
  int MPC_Info_get_nthkey (MPC_Info, int, char *);
  int MPC_Info_get_valuelen (MPC_Info, char *, int *, int *);


/* Generalized Requests */

  int MPC_Grequest_start(MPC_Grequest_query_function *query_fn,
                         MPC_Grequest_free_function *free_fn,
                         MPC_Grequest_cancel_function *cancel_fn,
                         void *extra_state, MPC_Request *request);

  int MPC_Grequest_complete(MPC_Request request);

  /* Extended Generalized Requests */

  int MPCX_Grequest_start(MPC_Grequest_query_function *query_fn,
                          MPC_Grequest_free_function *free_fn,
                          MPC_Grequest_cancel_function *cancel_fn,
                          MPCX_Grequest_poll_fn *poll_fn, void *extra_state,
                          MPC_Request *request);

  /* Extended Generalized Requests Classes */

  int MPCX_GRequest_class_create(MPC_Grequest_query_function *query_fn,
                                 MPC_Grequest_cancel_function *cancel_fn,
                                 MPC_Grequest_free_function *free_fn,
                                 MPCX_Grequest_poll_fn *poll_fn,
                                 MPCX_Grequest_wait_fn *wait_fn,
                                 MPCX_Request_class *new_class);

  int MPCX_Grequest_class_allocate(MPCX_Request_class target_class,
                                   void *extra_state, MPC_Request *request);

  /* Status Modification and query */
  int MPC_Status_set_elements(MPC_Status *, MPC_Datatype, int);
  int MPC_Status_set_elements_x(MPC_Status *, MPC_Datatype, MPC_Count);
  int MPC_Status_set_cancelled(MPC_Status *, int);
  int MPC_Request_get_status(MPC_Request, int *, MPC_Status *);
  int MPC_Test_cancelled(MPC_Status *, int *);

  /*MPI compatibility*/
#define MPC_BSEND_OVERHEAD 0
#define MPC_BOTTOM ((void*)0)
#define MPC_IN_PLACE SCTK_IN_PLACE




    /* Profiling Functions */

    /*Initialisation */
  int PMPC_Init (int *argc, char ***argv);
  int PMPC_Init_thread (int *argc, char ***argv, int required, int *provided);
  int MPC_Init_thread (int *argc, char ***argv, int required, int *provided);
  int PMPC_Initialized (int *flag);
  int PMPC_Finalize (void);
  int PMPC_Abort (MPC_Comm, int);
  int PMPC_Query_thread (int *provided);

  /*Topology informations */
  int PMPC_Comm_rank (MPC_Comm comm, int *rank);
  int PMPC_Comm_size (MPC_Comm comm, int *size);
  int PMPC_Comm_remote_size (MPC_Comm comm, int *size);
  int PMPC_Comm_test_inter (MPC_Comm comm, int *flag);
  int PMPC_Node_rank (int *rank);
  int PMPC_Node_number (int *number);
  int PMPC_Processor_rank (int *rank);
  int PMPC_Processor_number (int *number);
  int PMPC_Process_rank (int *rank);
  int PMPC_Process_number (int *number);
  int PMPC_Local_process_rank (int *rank);
  int PMPC_Local_process_number (int *rank);
  int PMPC_Get_multithreading (char *name, int size);
  int PMPC_Get_networking (char *name, int size);
  int PMPC_Get_processor_name (char *name, int *resultlen);


  /*Collective operations */
  int PMPC_Barrier (MPC_Comm comm);
  int PMPC_Bcast (void *buffer, mpc_msg_count count, MPC_Datatype datatype,
		 int root, MPC_Comm comm);
  int PMPC_Allreduce (void *sendbuf, void *recvbuf, mpc_msg_count count,
		     MPC_Datatype datatype, MPC_Op op, MPC_Comm comm);
  int PMPC_Reduce (void *sendbuf, void *recvbuf, mpc_msg_count count,
		  MPC_Datatype datatype, MPC_Op op, int root, MPC_Comm comm);
  int PMPC_Op_create (MPC_User_function *, int, MPC_Op *);
  int PMPC_Op_free (MPC_Op *);



  /*P-t-P Communications */
  int PMPC_Isend (void *buf, mpc_msg_count count, MPC_Datatype datatype,
		 int dest, int tag, MPC_Comm comm, MPC_Request * request);
  int PMPC_Ibsend (void *, mpc_msg_count, MPC_Datatype, int, int, MPC_Comm,
		  MPC_Request *);
  int PMPC_Issend (void *, mpc_msg_count, MPC_Datatype, int, int, MPC_Comm,
		  MPC_Request *);
  int PMPC_Irsend (void *, mpc_msg_count, MPC_Datatype, int, int, MPC_Comm,
		  MPC_Request *);

  int PMPC_Irecv (void *buf, mpc_msg_count count, MPC_Datatype datatype,
		 int source, int tag, MPC_Comm comm, MPC_Request * request);

  int PMPC_Wait (MPC_Request * request, MPC_Status * status);
  int PMPC_Waitall (mpc_msg_count, MPC_Request *, MPC_Status *);
  int PMPC_Waitsome (mpc_msg_count, MPC_Request *, mpc_msg_count *,
		    mpc_msg_count *, MPC_Status *);
  int PMPC_Waitany (mpc_msg_count count, MPC_Request array_of_requests[],
		   mpc_msg_count * index, MPC_Status * status);
  int PMPC_Wait_pending (MPC_Comm comm);
  int PMPC_Wait_pending_all_comm (void);

  int PMPC_Test (MPC_Request *, int *, MPC_Status *);
  int PMPC_Test_no_check (MPC_Request *, int *, MPC_Status *);
  int PMPC_Test_check (MPC_Request *, int *, MPC_Status *);

  int PMPC_Iprobe (int, int, MPC_Comm, int *, MPC_Status *);
  int PMPC_Probe (int, int, MPC_Comm, MPC_Status *);
  int PMPC_Get_count (MPC_Status *, MPC_Datatype, mpc_msg_count *);

  int PMPC_Send (void *, mpc_msg_count, MPC_Datatype, int, int, MPC_Comm);
  int PMPC_Bsend (void *, mpc_msg_count, MPC_Datatype, int, int, MPC_Comm);
  int PMPC_Ssend (void *, mpc_msg_count, MPC_Datatype, int, int, MPC_Comm);
  int PMPC_Rsend (void *, mpc_msg_count, MPC_Datatype, int, int, MPC_Comm);
  int PMPC_Recv (void *, mpc_msg_count, MPC_Datatype, int, int, MPC_Comm,
		MPC_Status *);

  int PMPC_Sendrecv (void *, mpc_msg_count, MPC_Datatype, int, int, void *,
		    mpc_msg_count, MPC_Datatype, int, int, MPC_Comm,
		    MPC_Status *);

  /*Status */
  int PMPC_Cancel (MPC_Request *);

  /*Gather */
  int PMPC_Gather (void *, mpc_msg_count, MPC_Datatype, void *,
		  mpc_msg_count, MPC_Datatype, int, MPC_Comm);
  int PMPC_Gatherv (void *, mpc_msg_count, MPC_Datatype, void *,
		   mpc_msg_count *, mpc_msg_count *, MPC_Datatype, int,
		   MPC_Comm);
  int PMPC_Allgather (void *, mpc_msg_count, MPC_Datatype, void *,
		     mpc_msg_count, MPC_Datatype, MPC_Comm);
  int PMPC_Allgatherv (void *, mpc_msg_count, MPC_Datatype, void *,
		      mpc_msg_count *, mpc_msg_count *, MPC_Datatype,
		      MPC_Comm);

  /*Scatter */
  int PMPC_Scatter (void *, mpc_msg_count, MPC_Datatype, void *,
		   mpc_msg_count, MPC_Datatype, int, MPC_Comm);
  int PMPC_Scatterv (void *, mpc_msg_count *, mpc_msg_count *,
		    MPC_Datatype, void *, mpc_msg_count, MPC_Datatype,
		    int, MPC_Comm);

  /*Alltoall */
  int PMPC_Alltoall (void *, mpc_msg_count, MPC_Datatype, void *,
		    mpc_msg_count, MPC_Datatype, MPC_Comm);
  int PMPC_Alltoallv (void *, mpc_msg_count *, mpc_msg_count *,
		     MPC_Datatype, void *, mpc_msg_count *,
		     mpc_msg_count *, MPC_Datatype, MPC_Comm);
  int PMPC_Alltoallw (const void *, const mpc_msg_count *, const mpc_msg_count *,
		     const MPC_Datatype *, void *, const mpc_msg_count *,
		     const mpc_msg_count *, const MPC_Datatype *, MPC_Comm);

  /*Groups */
  int PMPC_Comm_group (MPC_Comm, MPC_Group *);
  int PMPC_Comm_remote_group (MPC_Comm, MPC_Group *);
  int PMPC_Group_free (MPC_Group *);
  int PMPC_Group_incl (MPC_Group, int, int *, MPC_Group *);
  int PMPC_Group_difference (MPC_Group, MPC_Group, MPC_Group *);

  /*Communicators */
  int PMPC_Convert_to_intercomm (MPC_Comm comm, MPC_Group group);
  int PMPC_Comm_create_list (MPC_Comm, int *list, int nb_elem, MPC_Comm *);
  int PMPC_Comm_create (MPC_Comm, MPC_Group, MPC_Comm *);
  int PMPC_Intercomm_create (MPC_Comm local_comm, int local_leader, MPC_Comm peer_comm, int remote_leader, int tag, MPC_Comm * newintercomm);
  int PMPC_Comm_create_from_intercomm (MPC_Comm, MPC_Group, MPC_Comm *);
  int PMPC_Comm_free (MPC_Comm *);
  int PMPC_Comm_dup (MPC_Comm, MPC_Comm *);
  int PMPC_Comm_split (MPC_Comm, int, int, MPC_Comm *);

  /*Error_handler */
  void PMPC_Default_error (MPC_Comm * comm, int *error, char *msg,
			  char *file, int line);
  void PMPC_Return_error (MPC_Comm * comm, int *error, ...);

  int PMPC_Errhandler_create (MPC_Handler_function *, MPC_Errhandler *);
  int PMPC_Errhandler_set (MPC_Comm, MPC_Errhandler);
  int PMPC_Errhandler_get (MPC_Comm, MPC_Errhandler *);
  int PMPC_Errhandler_free (MPC_Errhandler *);
  int PMPC_Error_string (int, char *, int *);
  int PMPC_Error_class (int, int *);

  /*Timing */
  double PMPC_Wtime (void);
  double PMPC_Wtick (void);

  /*Types */
  int PMPC_Type_size (MPC_Datatype, size_t *);
  int PMPC_Type_is_allocated (MPC_Datatype datatype, int * flag );
  int PMPC_Type_flag_padded(MPC_Datatype datatype);
  int PMPC_Type_hcontiguous (MPC_Datatype *outtype, size_t count, MPC_Datatype *data_in);
  int __MPC_Barrier (MPC_Comm comm);
  int PMPC_Type_free (MPC_Datatype * datatype);
  int PMPC_Type_dup( MPC_Datatype old_type, MPC_Datatype * new_type ); 
  int PMPC_Type_set_name( MPC_Datatype datatype, char *name );
  int PMPC_Type_get_name( MPC_Datatype datatype, char *name, int * resultlen );
  int PMPC_Type_get_envelope(MPC_Datatype datatype, int *num_integers, int *num_addresses, int *num_datatypes, int *combiner);
  int PMPC_Type_get_contents( MPC_Datatype datatype, 
			      int max_integers,
			      int max_addresses,
			      int max_datatypes,
			      int array_of_integers[],
			      MPC_Aint array_of_addresses[],
			      MPC_Datatype array_of_datatypes[]);
  int PMPC_Type_commit( MPC_Datatype * type );

  /* Types Keyval handling */
  int PMPC_Type_free_keyval(int *type_keyval);
  int PMPC_Type_create_keyval(MPC_Type_copy_attr_function *copy,
                              MPC_Type_delete_attr_function *deletef,
                              int *type_keyval, void *extra_state);
  int PMPC_Type_delete_attr(MPC_Datatype datatype, int type_keyval);
  int PMPC_Type_set_attr(MPC_Datatype datatype, int type_keyval,
                         void *attribute_val);
  int PMPC_Type_get_attr(MPC_Datatype datatype, int attribute_val,
                         void *type_keyval, int *flag);

  /*MPC specific function */
  int PMPC_Copy_in_buffer (void *inbuffer, void *outbuffer, MPC_Datatype datatype);
  int PMPC_Copy_from_buffer (void *inbuffer, void *outbuffer, MPC_Datatype datatype);

  struct Datatype_External_context;
  int PMPC_Derived_datatype (MPC_Datatype * datatype,
			    mpc_pack_absolute_indexes_t * begins,
			    mpc_pack_absolute_indexes_t * ends,
			    MPC_Datatype * types,
			    unsigned long count,
			    mpc_pack_absolute_indexes_t lb, int is_lb,
			    mpc_pack_absolute_indexes_t ub, int is_ub,
			    struct Datatype_External_context *ectx );

  int PMPC_Type_get_true_extent(MPC_Datatype datatype, MPC_Aint *true_lb, MPC_Aint *true_extent);
  int PMPC_Type_convert_to_derived( MPC_Datatype in_datatype, MPC_Datatype * out_datatype );
  int PMPC_Type_use (MPC_Datatype datatype);
/*   int PMPC_Get_keys (void **keys); */
/*   int PMPC_Set_keys (void *keys); */
/*   int PMPC_Get_requests (void **requests); */
/*   int PMPC_Set_requests (void *requests); */
/*   int PMPC_Get_groups (void **groups); */
/*   int PMPC_Set_groups (void *groups); */
/*   int PMPC_Get_errors (void **errors); */
/*   int PMPC_Set_errors (void *errors); */
/*   int PMPC_Set_buffers (void *buffers); */
/*   int PMPC_Get_buffers (void **buffers); */
/*   int PMPC_Get_comm_type (void **comm_type); */
/*   int PMPC_Set_comm_type (void *comm_type); */
/*   int PMPC_Get_op (void **op); */
/*   int PMPC_Set_op (void *op); */


  /*Requests */
  int PMPC_Request_free (MPC_Request *);

  /*Scheduling */
  int PMPC_Proceed (void);
  int PMPC_Checkpoint (void);
  int PMPC_Checkpoint_timed (unsigned int sec, MPC_Comm comm);
  int PMPC_Migrate (void);
  int PMPC_Restart (int rank);
  int PMPC_Restarted (int *flag);

  int PMPC_Get_activity (int nb_item, MPC_Activity_t * tab,
			double *process_act);
  int PMPC_Move_to (int process, int cpuid);

  /*Packs */
  int PMPC_Open_pack (MPC_Request * request);
  int PMPC_Default_pack (mpc_msg_count count,
			mpc_pack_indexes_t * begins,
			mpc_pack_indexes_t * ends, MPC_Request * request);
  int PMPC__Default_pack_absolute (mpc_msg_count count,
			       mpc_pack_absolute_indexes_t * begins,
			       mpc_pack_absolute_indexes_t * ends,
			       MPC_Request * request);
  int PMPC_Add_pack (void *buf, mpc_msg_count count,
		    mpc_pack_indexes_t * begins,
		    mpc_pack_indexes_t * ends, MPC_Datatype datatype,
		    MPC_Request * request);
  int PMPC_Add_pack_absolute (void *buf, mpc_msg_count count,
			   mpc_pack_absolute_indexes_t * begins,
			   mpc_pack_absolute_indexes_t * ends,
			   MPC_Datatype datatype, MPC_Request * request);

  int PMPC_Add_pack_default (void *buf, MPC_Datatype datatype,
			    MPC_Request * request);
  int PMPC__Add_pack_default_absolute (void *buf, MPC_Datatype datatype,
				   MPC_Request * request);
  int PMPC_Isend_pack (int dest, int tag, MPC_Comm comm,
		      MPC_Request * request);
  int PMPC_Irecv_pack (int source, int tag, MPC_Comm comm,
		      MPC_Request * request);


  /* MPI Info management */
  
  int PMPC_Info_set( MPC_Info, const char *, const char * );
  int PMPC_Info_free( MPC_Info * );
  int PMPC_Info_create( MPC_Info * );
  int PMPC_Info_delete( MPC_Info , const char * );
  int PMPC_Info_get(MPC_Info , const char *, int , char *, int *);
  int PMPC_Info_dup( MPC_Info , MPC_Info * );
  int PMPC_Info_get_nkeys (MPC_Info, int *);
  int PMPC_Info_get_nthkey (MPC_Info, int, char *);
  int PMPC_Info_get_valuelen (MPC_Info, char *, int *, int *);

  /* Generalized Requests */

  int PMPC_Grequest_start( MPC_Grequest_query_function *query_fr, MPC_Grequest_free_function * free_fn,
						  MPC_Grequest_cancel_function * cancel_fn, void *extra_state, MPC_Request * request);
    
  int PMPC_Grequest_complete(  MPC_Request request); 

  /* Extended Generalized Requests */

  int PMPCX_Grequest_start(MPC_Grequest_query_function *query_fn,
                          MPC_Grequest_free_function * free_fn,
                          MPC_Grequest_cancel_function * cancel_fn, 
                          MPCX_Grequest_poll_fn * poll_fn, 
                          void *extra_state, 
                          MPC_Request * request);

  /* Extended Generalized Requests Classes */
  int PMPCX_GRequest_class_create( MPC_Grequest_query_function * query_fn,
				   MPC_Grequest_cancel_function * cancel_fn,
				   MPC_Grequest_free_function * free_fn,
				   MPCX_Grequest_poll_fn * poll_fn,
				   MPCX_Grequest_wait_fn * wait_fn,
				   MPCX_Request_class * new_class );
  
  int PMPCX_Grequest_class_allocate( MPCX_Request_class target_class, void *extra_state, MPC_Request *request );

  /* Status Modification and query */
  int PMPC_Status_set_elements(MPC_Status *, MPC_Datatype , int );
  int PMPC_Status_set_elements_x(MPC_Status *, MPC_Datatype , MPC_Count );
  int PMPC_Status_set_cancelled (MPC_Status *, int);
  int PMPC_Request_get_status (MPC_Request, int *, MPC_Status *);
  int PMPC_Test_cancelled (MPC_Status *, int *);
  
  /* Send/Recv message using the signalization network */
  void MPC_Send_signalization_network(int dest_process, int tag, void *buff, size_t size);
  void MPC_Recv_signalization_network(int src_process, int tag, void *buff, size_t size);

#ifdef __cplusplus
}
#endif
#endif

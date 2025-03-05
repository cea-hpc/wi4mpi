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
/* #   - BESNARD Jean-Baptiste jbbesnard@paratools.fr                     # */
/* #                                                                      # */
/* ######################################################################## */
#ifndef SCTK_TYPES_H
#define SCTK_TYPES_H
/************************** HEADERS **************************/
#include <stdlib.h>
/************************** TYPES **************************/
/** define the communicator number type **/
typedef int sctk_communicator_t;
/** define a data-type **/
typedef int sctk_datatype_t;
/** Message count **/
typedef int sctk_msg_count_t;
/** A message header to be put in the request **/
typedef struct{
	int source;
	int destination;
	int destination_task;
	int source_task;
	int message_tag;
	sctk_communicator_t communicator;
	sctk_msg_count_t msg_size;
}sctk_header_t;
/** Status Definition **/
typedef struct
{
	int MPC_SOURCE;		/**< Source of the Message */
	int MPC_TAG;		/**< Tag of the message */
	int MPC_ERROR;		/**< Did we encounter an error */
	int cancelled;		/**< Was the message canceled */
	sctk_msg_count_t size;	/**< Size of the message */
} sctk_status_t;
/** Generalized requests functions **/
typedef int sctk_Grequest_query_function( void * extra_state, sctk_status_t *status );
typedef int sctk_Grequest_cancel_function( void * extra_state, int complete );
typedef int sctk_Grequest_free_function( void * extra_state );
/** Extended Generalized requests functions **/
typedef int sctk_Grequest_poll_fn( void * extra_state , sctk_status_t * status );
typedef int sctk_Grequest_wait_fn( int count, void ** array_of_states, double timeout, sctk_status_t * status );
/** Generalized Request classes **/
typedef int sctk_Request_class;
/** Request definition **/
typedef struct
{
  volatile int request_type;
  volatile sctk_header_t header;
  volatile int completion_flag;
  struct sctk_thread_ptp_message_s *msg;
  int is_null;
  int need_check_in_wait;
  int truncated;
  int status_error;
  /* Generalized Request context  */
  sctk_Grequest_query_function *query_fn;
  sctk_Grequest_cancel_function *cancel_fn;
  sctk_Grequest_free_function *free_fn;
  void *extra_state;
  /* Extended Request */
  sctk_Grequest_poll_fn *poll_fn;
  sctk_Grequest_wait_fn *wait_fn;
  /* MPI_Grequest_complete takes a copy of the struct
   * not a reference however we have to change a value
   * in the source struct which is being pulled therefore
   * we have to do this hack by saving a pointer to the
   * request inside the request */
  void *pointer_to_source_request;
  /* This is a pointer to the shadow request */
  void *pointer_to_shadow_request;
  /* This is a pointer to the registered memory region
   * in order to unpin when request completes */
  void *ptr_to_pin_ctx;
} sctk_request_t;

/** Reduction Operations **/
typedef void (*sctk_Op_f) (const void *, void *, size_t, sctk_datatype_t);
typedef void (sctk_Op_User_function) (void *, void *, int *, sctk_datatype_t *);

typedef struct
{
	sctk_Op_f func;
	sctk_Op_User_function *u_func;
} sctk_Op;

/** RDMA windows */
typedef int sctk_window_t;

typedef enum {
  RDMA_SUM,
  RDMA_INC,
  RDMA_DEC,
  RDMA_MIN,
  RDMA_MAX,
  RDMA_PROD,
  RDMA_LAND,
  RDMA_BAND,
  RDMA_LOR,
  RDMA_BOR,
  RDMA_LXOR,
  RDMA_BXOR
} RDMA_op;

typedef enum {
  RDMA_TYPE_CHAR,
  RDMA_TYPE_DOUBLE,
  RDMA_TYPE_FLOAT,
  RDMA_TYPE_INT,
  RDMA_TYPE_LONG,
  RDMA_TYPE_LONG_DOUBLE,
  RDMA_TYPE_LONG_LONG,
  RDMA_TYPE_LONG_LONG_INT,
  RDMA_TYPE_SHORT,
  RDMA_TYPE_SIGNED_CHAR,
  RDMA_TYPE_UNSIGNED,
  RDMA_TYPE_UNSIGNED_CHAR,
  RDMA_TYPE_UNSIGNED_LONG,
  RDMA_TYPE_UNSIGNED_LONG_LONG,
  RDMA_TYPE_UNSIGNED_SHORT,
  RDMA_TYPE_WCHAR,
  RDMA_TYPE_AINT
} RDMA_type;

size_t RDMA_type_size( RDMA_type type );


/************************** MACROS *************************/
/** define the MPI_COMM_WORLD internal communicator number **/
#define SCTK_COMM_WORLD 0
/** define the MPI_COMM_SELF internal communicator number **/
#define SCTK_COMM_SELF 1
/** Define the NULL communicator number */
#define SCTK_COMM_NULL  ((sctk_communicator_t)(-1))
/** Define the NULL error handler */
#define SCTK_ERRHANDLER_NULL 0
/** Not using datatypes */
#define SCTK_DATATYPE_IGNORE ((sctk_datatype_t)0)
/** In place collectives **/
#define SCTK_IN_PLACE ((void*)-1)
/** PROC_NULL **/
#define SCTK_PROC_NULL -2
/** SUCCESS and ERROR **/
#define SCTK_SUCCESS 0
/** Wildcards **/
#define SCTK_ANY_TAG -1
#define SCTK_ANY_SOURCE -1
#define SCTK_ANY_COMM -99

#endif /* SCTK_TYPES_H */

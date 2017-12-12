//############################# Wi4MPI License ###########################
//# `04/04/2016`                                                         #
//# Copyright or (C) or Copr. Commissariat a l'Energie Atomique          #
//#                                                                      #
//# IDDN.FR.001.210022.000.S.P.2014.000.10800                            #
//# This file is part of the Wi4MPI library.                             #
//#                                                                      #
//# This software is governed by the CeCILL-C license under French law   #
//# and abiding by the rules of distribution of free software. You can   #
//# use, modify and/ or redistribute the software under the terms of     #
//# the CeCILL-C license as circulated by CEA, CNRS and INRIA at the     #
//# following URL http://www.cecill.info.                                #
//#                                                                      #
//# The fact that you are presently reading this means that you have     #
//# had knowledge of the CeCILL-C license and that you accept its        #
//# terms.                                                               #
//#                                                                      #
//# Authors:                                                             #
//#   - Delforge Tony <tony.delforge.tgcc@cea.fr>                        #
//#   - Ducrot Vincent <vincent.ducrot.tgcc@cea.fr>                      #
//#                                                                      #
//########################################################################


#ifndef NEW_UTILS_H
#define NEW_UTILS_H
#include "thread_safety.h"
#include "run_mpi.h"
#include "app_mpi.h"
#include "optimisation.h"
#include <assert.h>
#include <limits.h>
#include <string.h>
#include "uthash.h"
#if defined(OMPI_INTEL) || defined(_INTEL)
extern char ompi_mpi_comm_null[];
extern char ompi_mpi_comm_self[];
extern char ompi_mpi_comm_world[];
extern char ompi_mpi_2cplex[];
extern char ompi_mpi_2dblcplex[];
extern char ompi_mpi_2dblprec[];
extern char ompi_mpi_2int[];
extern char ompi_mpi_2integer[];
extern char ompi_mpi_2real[];
extern char ompi_mpi_aint[];
extern char ompi_mpi_byte[];
extern char ompi_mpi_c_bool[];
extern char ompi_mpi_c_complex[];
extern char ompi_mpi_c_double_complex[];
extern char ompi_mpi_c_float_complex[];
extern char ompi_mpi_c_long_double_complex[];
extern char ompi_mpi_char[];
extern char ompi_mpi_character[];
extern char ompi_mpi_complex16[];
extern char ompi_mpi_complex32[];
extern char ompi_mpi_complex8[];
extern char ompi_mpi_cplex[];
extern char ompi_mpi_cxx_bool[];
extern char ompi_mpi_cxx_cplex[];
extern char ompi_mpi_cxx_dblcplex[];
extern char ompi_mpi_cxx_ldblcplex[];
extern char ompi_mpi_datatype_null[];
extern char ompi_mpi_dblcplex[];
extern char ompi_mpi_dblprec[];
extern char ompi_mpi_double[];
extern char ompi_mpi_double_int[];
extern char ompi_mpi_float[];
extern char ompi_mpi_float_int[];
extern char ompi_mpi_int16_t[];
extern char ompi_mpi_int32_t[];
extern char ompi_mpi_int64_t[];
extern char ompi_mpi_int8_t[];
extern char ompi_mpi_int[];
extern char ompi_mpi_integer16[];
extern char ompi_mpi_integer1[];
extern char ompi_mpi_integer2[];
extern char ompi_mpi_integer4[];
extern char ompi_mpi_integer8[];
extern char ompi_mpi_integer[];
extern char ompi_mpi_lb[];
extern char ompi_mpi_ldblcplex[];
extern char ompi_mpi_logical1[];
extern char ompi_mpi_logical2[];
extern char ompi_mpi_logical4[];
extern char ompi_mpi_logical8[];
extern char ompi_mpi_logical[];
extern char ompi_mpi_long[];
extern char ompi_mpi_long_double[];
extern char ompi_mpi_long_int[];
extern char ompi_mpi_long_long_int[];
extern char ompi_mpi_longdbl_int[];
extern char ompi_mpi_offset[];
extern char ompi_mpi_count[];
extern char ompi_message_null[];
extern char ompi_mpi_packed[];
extern char ompi_mpi_real16[];
extern char ompi_mpi_real2[];
extern char ompi_mpi_real4[];
extern char ompi_mpi_real8[];
extern char ompi_mpi_real[];
extern char ompi_mpi_short[];
extern char ompi_mpi_short_int[];
extern char ompi_mpi_signed_char[];
extern char ompi_mpi_ub[];
extern char ompi_mpi_uint16_t[];
extern char ompi_mpi_uint32_t[];
extern char ompi_mpi_uint64_t[];
extern char ompi_mpi_uint8_t[];
extern char ompi_mpi_unsigned[];
extern char ompi_mpi_unsigned_char[];
extern char ompi_mpi_unsigned_long[];
extern char ompi_mpi_unsigned_long_long[];
extern char ompi_mpi_unsigned_short[];
extern char ompi_mpi_wchar[];
extern char ompi_mpi_errhandler_null[];
extern char ompi_mpi_errors_are_fatal[];
extern char ompi_mpi_errors_return[];
extern char ompi_mpi_file_null[];
extern char ompi_mpi_group_empty[];
extern char ompi_mpi_group_null[];
extern char ompi_mpi_info_null[];
extern char ompi_mpi_op_band[];
extern char ompi_mpi_op_bor[];
extern char ompi_mpi_op_bxor[];
extern char ompi_mpi_op_land[];
extern char ompi_mpi_op_lor[];
extern char ompi_mpi_op_lxor[];
extern char ompi_mpi_op_max[];
extern char ompi_mpi_op_maxloc[];
extern char ompi_mpi_op_min[];
extern char ompi_mpi_op_minloc[];
extern char ompi_mpi_op_null[];
extern char ompi_mpi_op_prod[];
extern char ompi_mpi_op_replace[];
extern char ompi_mpi_op_sum[];
extern char ompi_request_null[];
extern char ompi_mpi_win_null[];
extern char ompi_message_no_proc[];
#include "run_mpio.h"
#endif
/*  Memcpy if application structure is large enough */
void *wi4mpi_alloc(size_t size);
void wi4mpi_free(void *ptr);

#define HASHTABLE_NO_OPT_NO_FORTRAN_DECL(type,varname,mpi_null)  \
typedef struct { \
  A_##type a_##varname##_key; \
  R_##type r_##varname##_value; \
  UT_hash_handle hh; \
} varname##_translation_t; \
 \
typedef struct {R_##type C;int idx;} type##_container;\
void varname##_translation_init(void) ;\
/*  ADD  */  \
void varname##_translation_add_const(A_##type a_mpi_##varname, R_##type mpi_##varname)   ;\
  \
int varname##_translation_is_const(A_##type a_mpi_##varname)  ;\
 \
/*  GET  */  \
void varname##_translation_get(A_##type a_mpi_##varname, R_##type *mpi_##varname) ;  \
/*  GET_KEY */  \
varname##_translation_t* varname##_translation_get_key_from_const(R_##type mpi_##varname, A_##type *a_mpi_##varname);  \
  \
varname##_translation_t*  varname##_translation_get_key_from_value(R_##type mpi_##varname, A_##type *a_mpi_##varname);  \
\
/* DEL */  \
void varname##_translation_del(A_##type * a_mpi_##varname)  ; \
void varname##_translation_del_f(int a_mpi_##varname)  ; \
  \
void varname##_translation_update(A_##type * a_mpi_##varname, R_##type mpi_##varname) ;  \
void varname##_translation_update_alloc(A_##type * a_mpi_##varname, R_##type mpi_##varname) ; \
  \
int varname##_translation_get_size()   ;\
  \
void varname##_translation_free_all();  




#define HASHTABLE_NO_OPTI_DECL(type, varname, mpi_null)   \
typedef struct { \
  A_##type a_##varname##_key; \
  R_##type r_##varname##_value; \
  UT_hash_handle hh; \
} varname##_translation_t; \
 \
typedef struct {int fort;R_##type C;int idx;} type##_container;\
void varname##_translation_init(void) ;\
/*  ADD  */  \
void varname##_translation_add_const(A_##type a_mpi_##varname, R_##type mpi_##varname) ;  \
int varname##_translation_is_const(A_##type a_mpi_##varname)  ;\
/*  GET  */  \
void varname##_translation_get(A_##type a_mpi_##varname, R_##type *mpi_##varname);   \
void varname##_translation_get_f(int a_mpi_##varname, int *mpi_##varname) ; \
/*  GET_KEY */  \
varname##_translation_t* varname##_translation_get_key_from_const(R_##type mpi_##varname, A_##type *a_mpi_##varname) ; \
  \
varname##_translation_t*  varname##_translation_get_key_from_value(R_##type mpi_##varname, A_##type *a_mpi_##varname) ;  \
/* DEL */  \
void varname##_translation_del(A_##type * a_mpi_##varname) ;  \
void varname##_translation_del_f(int a_mpi_##varname) ;  \
  \
void varname##_translation_update(A_##type * a_mpi_##varname, R_##type mpi_##varname) ;  \
void varname##_translation_update_f(int mpi_##varname, int *a_mpi_##varname) ;  \
void varname##_translation_update_alloc_f(int mpi_##varname,int * a_mpi_##varname) ;\
void varname##_translation_update_alloc(A_##type * a_mpi_##varname, R_##type mpi_##varname) ;  \
int varname##_translation_get_size() ;  \
void varname##_translation_free_all() ;  

#define HASHTABLE_NO_OPT_NO_FORTRAN_FUNC_DECL(type,varname,mpi_null)  \
typedef struct { \
  A_##type a_##varname##_key; \
  R_##type r_##varname##_value; \
  UT_hash_handle hh; \
} varname##_translation_t; \
 \
typedef struct {R_##type C;int idx;void *func_ptr} type##_container;\
/*  lock_init  */  \
void varname##_translation_init(void) ;\
/*  ADD  */  \
void varname##_translation_add_const(A_##type a_mpi_##varname, R_##type mpi_##varname) ; \
  \
int varname##_translation_is_const(A_##type a_mpi_##varname) ; \
 \
/*  GET  */  \
void varname##_translation_get(A_##type a_mpi_##varname, R_##type *mpi_##varname) ; \
/*  GET_KEY */  \
varname##_translation_t* varname##_translation_get_key_from_const(R_##type mpi_##varname, A_##type *a_mpi_##varname) ;  \
  \
varname##_translation_t*  varname##_translation_get_key_from_value(R_##type mpi_##varname, A_##type *a_mpi_##varname) ;  \
void varname##_translation_add_funtion_ref(A_##type a_mpi_##varname,void *fn);\
/* DEL */  \
void varname##_translation_del(A_##type * a_mpi_##varname) ; \
void varname##_translation_del_f(int a_mpi_##varname) ;  \
  \
void varname##_translation_update(A_##type * a_mpi_##varname, R_##type mpi_##varname) ;  \
void varname##_translation_update_alloc(A_##type * a_mpi_##varname, R_##type mpi_##varname) ;  \
  \
int varname##_translation_get_size() ;  \
  \
void varname##_translation_free_all() ;  




#define HASHTABLE_NO_OPTI_FUNC_DECL(type, varname, mpi_null)   \
typedef struct { \
  A_##type a_##varname##_key; \
  R_##type r_##varname##_value; \
  UT_hash_handle hh; \
} varname##_translation_t; \
typedef struct {int fort;R_##type C;int idx;void *func_ptr} type##_container;\
void varname##_translation_init(void) ;\
/*  ADD  */  \
void varname##_translation_add_const(A_##type a_mpi_##varname, R_##type mpi_##varname) ; \
  \
int varname##_translation_is_const(A_##type a_mpi_##varname) ; \
 \
/*  GET  */  \
void varname##_translation_get(A_##type a_mpi_##varname, R_##type *mpi_##varname) ; \
void varname##_translation_add_funtion_ref(A_##type a_mpi_##varname,void *fn);\
void varname##_translation_get_f(int a_mpi_##varname, int *mpi_##varname) ;  \
/*  GET_KEY */  \
varname##_translation_t* varname##_translation_get_key_from_const(R_##type mpi_##varname, A_##type *a_mpi_##varname) ;  \
  \
varname##_translation_t*  varname##_translation_get_key_from_value(R_##type mpi_##varname, A_##type *a_mpi_##varname) ;  \
/* DEL */  \
void varname##_translation_del(A_##type * a_mpi_##varname) ; \
void varname##_translation_del_f(int a_mpi_##varname) ;  \
void varname##_translation_update(A_##type * a_mpi_##varname, R_##type mpi_##varname) ;  \
void varname##_translation_update_f(int mpi_##varname, int *a_mpi_##varname) ; \
void varname##_translation_update_alloc_f(int mpi_##varname,int * a_mpi_##varname) ; \
void varname##_translation_update_alloc(A_##type * a_mpi_##varname, R_##type mpi_##varname) ;  \
int varname##_translation_get_size() ; \
void varname##_translation_free_all() ;  \

#define NO_TABLE_NO_OPTI_DECL(type, varname, mpi_null)   \
void varname##_translation_add_const(A_##type a_mpi_##varname, R_##type mpi_##varname) ;  \
void varname##_translation_get_f(int a_mpi_##varname, int *mpi_##varname) ; \
void varname##_translation_del(A_##type * a_mpi_##varname)  ;\
void varname##_translation_del_f(int a_mpi_##varname) ;  \
void varname##_translation_update(A_##type * a_mpi_##varname, R_##type mpi_##varname) ; \
void varname##_translation_update_f(int mpi_##varname,int * a_mpi_##varname ) ;  \
void varname##_translation_update_alloc_f(int mpi_##varname,int * a_mpi_##varname)  ; \
int varname##_translation_get_size();  \
void varname##_translation_free_all() ; \

typedef int A_MPI_Keyval;
typedef int R_MPI_Keyval;
typedef int A_MPI_Error;
typedef int R_MPI_Error;
NO_TABLE_NO_OPTI_DECL(MPI_Error,error,MPI_SUCCESS);
NO_TABLE_NO_OPTI_DECL(MPI_Keyval,keyval,0);
/* Communicator */
/* Communicator */
HASHTABLE_NO_OPTI_DECL(MPI_Comm,communicator, R_MPI_COMM_NULL);

/* Datatype */
typedef R_MPI_Datatype R_MPI_Type;
typedef A_MPI_Datatype A_MPI_Type;
HASHTABLE_NO_OPTI_DECL(MPI_Type,datatype, R_MPI_DATATYPE_NULL);

/* Errhandler */
HASHTABLE_NO_OPTI_DECL(MPI_Errhandler,errhandler, R_MPI_ERRHANDLER_NULL);

/* Op */
HASHTABLE_NO_OPTI_DECL(MPI_Op,operation, R_MPI_OP_NULL);

/* Group */
HASHTABLE_NO_OPTI_DECL(MPI_Group,group, R_MPI_GROUP_NULL);

/* Win */
HASHTABLE_NO_OPTI_DECL(MPI_Win,win, R_MPI_WIN_NULL);

/* Message */
HASHTABLE_NO_OPTI_DECL(MPI_Message,message, R_MPI_MESSAGE_NULL);

/* MPI_T_enum */
HASHTABLE_NO_OPT_NO_FORTRAN_DECL(MPI_T_enum, t_enum, R_MPI_T_ENUM_NULL);

/* MPI_T_cvar_handle */
HASHTABLE_NO_OPT_NO_FORTRAN_DECL(MPI_T_cvar_handle, cvar_handle, R_MPI_T_CVAR_HANDLE_NULL);

/* MPI_T_pvar_handle */
HASHTABLE_NO_OPT_NO_FORTRAN_DECL(MPI_T_pvar_handle, pvar_handle, R_MPI_T_PVAR_HANDLE_NULL);

/*  MPI_T_pvar_session*/
//#if HASHTABLE_OPTI_SESSION
//HASHTABLE_OPTI(MPI_T_pvar_session, pvar_session);
//#else
//HASHTABLE_NO_OPTI(MPI_T_pvar_session, pvar_session, R_MPI_T_PVAR_SESSION_NULL);
//#endif

/* Request */

/*  ADD  */
typedef struct {
    A_MPI_Request a_request_key;
    R_MPI_Request r_request_value;
    UT_hash_handle hh;
} request_translation_t;
void request_translation_add_const(A_MPI_Request a_mpi_request, R_MPI_Request mpi_request) ;
/*   True hashtables  */
typedef struct {
    R_MPI_Request Creq;
    int           Freq;
    int           nb;
}__WI4MPI_req_container;
void request_translation_init();
/*  GET  */
void request_translation_get_f(int a_mpi_request, int *mpi_request) ;
void request_translation_get(A_MPI_Request a_mpi_request, R_MPI_Request *mpi_request, int* non_blocking) ;

int request_translation_get_key_from_const(R_MPI_Request mpi_request, A_MPI_Request *a_mpi_request) ;
/* DEL */
void request_translation_del(A_MPI_Request * a_mpi_request) ;
void request_translation_del_f(int a_mpi_request) ;  \
void request_translation_update_f(int mpi_request,int * a_mpi_request) ;
/* UPDATE */
void request_translation_update(A_MPI_Request * a_mpi_request, R_MPI_Request mpi_request, int non_blocking) ;
void request_translation_update_alloc_f(int mpi_request,int * a_mpi_request) ;

int request_translation_get_size() ;
void request_translation_free_all() ;

//#if WRAPPER_MPI_VERSION > 21
/* File */
#if HASHTABLE_OPTI_FILE
HASHTABLE_OPTI_DECL(MPI_File,file);
#else
HASHTABLE_NO_OPTI_DECL(MPI_File,file, R_MPI_FILE_NULL);
#endif

/* Info */
#if HASHTABLE_OPTI_INFO
HASHTABLE_OPTI_DECL(MPI_Info,info);
#else
HASHTABLE_NO_OPTI_DECL(MPI_Info,info, R_MPI_INFO_NULL);
#endif

//#endif
#endif

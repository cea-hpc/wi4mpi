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



#ifndef MAPPERS_HEADERS
#define MAPPERS_HEADERS

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <dlfcn.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#ifndef EXTERN_ALLOCATED
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
#endif
#endif
//#include <pthread.h>
#include "app_mpi.h" // A_MPI_ && A_PMPI_ (Souche MPI Source)
#include "run_mpi.h" // R_MPI_ && R_PMPI_ (Souche MPI Cible)
// Rajouter un ifdef

#ifdef INTEL_INTEL
      #include "run_mpio.h" // mpi.h from intel implementation doesn't contain MPI-IO routines.
      #include "app_mpio.h" // mpi.h from intel implementation doesn't contain MPI-IO routines.
#elif INTEL_OMPI
      #include "app_mpio.h"
#elif defined(OMPI_INTEL) || defined(_INTEL)
      #include "run_mpio.h"
#endif

#include "engine.h"
#include "engine_fn.h"
 
/*ADIOS CONST*/
//#include "adio_extern.h"  // header which contain the value of ADIO_same_amode

//#define A_ADIO_same_amode (A_MPI_Op) (0x58000001)
//#define A_UNDEFINED_OP (A_MPI_Op) (0X98000000)A_MPI_Op) (0x58000002)
//#define A_ADIO_MIN (A_MPI_Op) (0x58000002)

#define MIN(a,b) ((a<b)? a : b)
#define MAX(a,b) ((a>b)? a : b)

#define const 

#define gen_hash_conv(NAME,TYPE,NAME2) \
static inline void  NAME##_conv_a2r(A_##TYPE *ca,R_##TYPE *cr)\
{\
NAME2##_translation_get(*ca,cr);\
}\
static inline void NAME##_conv_r2a(A_##TYPE  *ca,R_##TYPE  *cr)\
{\
NAME2##_translation_update(ca,*cr);\
}\
static inline void NAME##_conv_r2a_static(A_##TYPE  *ca,R_##TYPE  *cr)\
{\
NAME2##_translation_get_key_from_value(*cr,ca);\
}\
static inline void NAME##_conv_r2a_uninitialized(A_##TYPE *ca,R_##TYPE *cr)\
{\
NAME2##_translation_update_alloc(ca,*cr);\
}

#define case_R_A(name)  \
  case R_MPI_##name:          \
    return A_MPI_##name
#define case_A_R(name)  \
  case A_MPI_##name:      \
    return R_MPI_##name
static inline void my_keyval_a2r(int *keyval,int *keyval_tmp)
{
    switch(*keyval)
{
    case A_MPI_TAG_UB:                *keyval_tmp=R_MPI_TAG_UB         ;break;
    case A_MPI_HOST:                  *keyval_tmp=R_MPI_HOST           ;break;
    case A_MPI_IO:                    *keyval_tmp=R_MPI_IO             ;break;
    case A_MPI_WTIME_IS_GLOBAL:       *keyval_tmp=R_MPI_WTIME_IS_GLOBAL;break;
    case A_MPI_APPNUM:                *keyval_tmp=R_MPI_APPNUM         ;break;
    case A_MPI_LASTUSEDCODE:          *keyval_tmp=R_MPI_LASTUSEDCODE   ;break;
    case A_MPI_UNIVERSE_SIZE:         *keyval_tmp=R_MPI_UNIVERSE_SIZE  ;break;
    case A_MPI_WIN_BASE:              *keyval_tmp=R_MPI_WIN_BASE       ;break;
    case A_MPI_WIN_SIZE:              *keyval_tmp=R_MPI_WIN_SIZE       ;break;
    case A_MPI_WIN_DISP_UNIT:         *keyval_tmp=R_MPI_WIN_DISP_UNIT  ;break;
    case A_MPI_WIN_CREATE_FLAVOR:     *keyval_tmp=R_MPI_WIN_CREATE_FLAVOR  ;break;
    case A_MPI_WIN_MODEL:             *keyval_tmp=R_MPI_WIN_MODEL  ;break;


    default: /*We may want to check the keyval hash table*/
            *keyval_tmp=*keyval;
}}

static inline void my_keyval_r2a(int *keyval,int *keyval_tmp)
{
    switch(*keyval_tmp)
{
    case  R_MPI_TAG_UB         : *keyval=A_MPI_TAG_UB         ;break;
    case  R_MPI_HOST           : *keyval=A_MPI_HOST           ;break;
    case  R_MPI_IO             : *keyval=A_MPI_IO             ;break;
    case  R_MPI_WTIME_IS_GLOBAL: *keyval=A_MPI_WTIME_IS_GLOBAL;break;
    case  R_MPI_APPNUM         : *keyval=A_MPI_APPNUM         ;break;
    case  R_MPI_LASTUSEDCODE   : *keyval=A_MPI_LASTUSEDCODE   ;break;
    case  R_MPI_UNIVERSE_SIZE  : *keyval=A_MPI_UNIVERSE_SIZE  ;break;
#if !defined(_MPC) && !defined(OMPI_MPC) && !defined(INTEL_MPC) && !defined(MPC_MPC)
/* MPC-3.2.0 defines those variables at the same value than others above */
    case  R_MPI_WIN_BASE       : *keyval=A_MPI_WIN_BASE       ;break;
    case  R_MPI_WIN_SIZE       : *keyval=A_MPI_WIN_SIZE       ;break;
    case  R_MPI_WIN_DISP_UNIT  : *keyval=A_MPI_WIN_DISP_UNIT  ;break;
    case  R_MPI_WIN_CREATE_FLAVOR:     *keyval_tmp=A_MPI_WIN_CREATE_FLAVOR  ;break;
    case  R_MPI_WIN_MODEL:             *keyval_tmp=A_MPI_WIN_MODEL  ;break;
#endif
    default: /*We may want to check the keyval hash table*/
            *keyval=*keyval_tmp;
}}
//int in_w=0;
//__thread int in_w=0;
static inline void const_buffer_conv_a2r(void** buf,void** buf_tmp)
{
  if(*buf == (void*) A_MPI_IN_PLACE)
    *buf_tmp= (void*) R_MPI_IN_PLACE;

  else if( *buf == (void*) A_MPI_BOTTOM )
    *buf_tmp= (void*) R_MPI_BOTTOM;  
  else 
    //memcpy(buf_tmp, buf, sizeof(void*));
    *buf_tmp=*buf;
}

static inline void buffer_conv_a2r(void** buf,void** buf_tmp)
{
  if(*buf == (void*) A_MPI_IN_PLACE)
      *buf_tmp= (void*) R_MPI_IN_PLACE;
            
  else if( *buf == (void*) A_MPI_BOTTOM )
      *buf_tmp= (void*) R_MPI_BOTTOM;  
  else 
     //memcpy(buf_tmp, buf, sizeof(void*));
     *buf_tmp=*buf;
}

static inline void buffer_conv_r2a(void **buf_tmp, void **buf)
{
   if(*buf == (void*) R_MPI_IN_PLACE)
    *buf= (void*) A_MPI_IN_PLACE;
  
  else if( *buf == (void*) R_MPI_BOTTOM )
    *buf= (void*) A_MPI_BOTTOM;
  
  else 
     //memcpy(buf_tmp, buf, sizeof(void*));
     *buf=*buf_tmp;
 
}

/* Mappers Comm a2r - r2a */
gen_hash_conv(comm,MPI_Comm,communicator)

/* Mappers Datatype a2r - r2a */
gen_hash_conv(datatype,MPI_Datatype,datatype)

/* Mappers Tag a2r - r2a*/
static inline void tag_conv_a2r(int* tag,int* tag_tmp)
{
  switch (*tag)
  {
    case A_MPI_ANY_TAG:
      *tag_tmp=R_MPI_ANY_TAG;
    break;
#if R_MPI_ANY_TAG != A_MPI_ANY_TAG      
    case R_MPI_ANY_TAG:
      *tag_tmp=A_MPI_ANY_TAG;
    break;
#endif
    default:
      *tag_tmp=*tag;
    break;
  }
}

static inline void tag_conv_r2a(int* tag,int* tag_tmp)
{
  switch (*tag_tmp)
  {
    case R_MPI_ANY_TAG:
      *tag=A_MPI_ANY_TAG;
    break;
 #if R_MPI_ANY_TAG != A_MPI_ANY_TAG           
    case A_MPI_ANY_TAG:
      *tag=R_MPI_ANY_TAG;
    break;
#endif
    default:
      *tag=*tag_tmp;
    break;
  }
}

/* Mappers Error a2r -r2a */
static inline int error_code_conv_r2a(int ret_tmp)
{
  switch (ret_tmp)
  {
      /* Utils && pt2pt bloquant-non bloquant */
      case_R_A(SUCCESS);
      case_R_A(ERR_OTHER);
      case_R_A(ERR_COMM);
	    case_R_A(ERR_ARG);
      case_R_A(ERR_TYPE);
	    case_R_A(ERR_COUNT);
      case_R_A(ERR_TAG);
      case_R_A(ERR_RANK);
  	  case_R_A(ERR_INTERN); /*MPICH*/
	    case_R_A(ERR_REQUEST);
	    case_R_A(ERR_IN_STATUS);
	    case_R_A(ERR_TRUNCATE);
	    case_R_A(ERR_BUFFER);
	    case_R_A(ERR_ROOT);
	    case_R_A(ERR_OP);
       case_R_A(ERR_GROUP);
       case_R_A(ERR_TOPOLOGY);
       case_R_A(ERR_DIMS);
       case_R_A(ERR_UNKNOWN);
       case_R_A(ERR_PENDING);
       case_R_A(ERR_ASSERT);
       case_R_A(ERR_BASE);
       case_R_A(ERR_DISP);
       case_R_A(ERR_INFO_KEY);
       case_R_A(ERR_INFO_NOKEY);
       case_R_A(ERR_INFO_VALUE);
       case_R_A(ERR_INFO);
       case_R_A(ERR_KEYVAL);
       case_R_A(ERR_LOCKTYPE);
       case_R_A(ERR_NAME);
       case_R_A(ERR_NO_MEM);
       case_R_A(ERR_PORT);
       case_R_A(ERR_RMA_CONFLICT);
       case_R_A(ERR_RMA_SYNC);
       case_R_A(ERR_SERVICE);
       case_R_A(ERR_SIZE);
       case_R_A(ERR_SPAWN);
       case_R_A(ERR_WIN);
       //case_R_A(ERR_LASTCODE);
       case_A_R(ERR_RMA_RANGE);
       case_A_R(ERR_RMA_ATTACH);
       case_A_R(ERR_RMA_SHARED);
       case_R_A(ERR_RMA_FLAVOR);
	
	  default:
         return ret_tmp;
  }
}

static inline int error_code_conv_a2r(int ret_tmp)
{
  switch (ret_tmp)
  {
      case_A_R(SUCCESS);
      case_A_R(ERR_OTHER);
      case_A_R(ERR_COMM);
      case_A_R(ERR_ARG);
      case_A_R(ERR_TYPE);
	    case_A_R(ERR_COUNT);
      case_A_R(ERR_TAG);
      case_A_R(ERR_RANK);
 	    case_A_R(ERR_INTERN); /*MPICH*/
	    case_A_R(ERR_REQUEST);
	    case_A_R(ERR_IN_STATUS);
	    case_A_R(ERR_TRUNCATE);
	    case_A_R(ERR_BUFFER);
	    case_A_R(ERR_ROOT);
	    case_A_R(ERR_OP);
       case_A_R(ERR_GROUP);
       case_A_R(ERR_TOPOLOGY);
       case_A_R(ERR_DIMS);
       case_A_R(ERR_UNKNOWN);   
       case_A_R(ERR_PENDING);
       case_A_R(ERR_ASSERT);
       case_A_R(ERR_BASE);
       case_A_R(ERR_DISP);
       case_A_R(ERR_INFO_KEY);
       case_A_R(ERR_INFO_NOKEY);
       case_A_R(ERR_INFO_VALUE);
       case_A_R(ERR_INFO);
       case_A_R(ERR_KEYVAL);
       case_A_R(ERR_LOCKTYPE);
       case_A_R(ERR_NAME);
       case_A_R(ERR_NO_MEM);
       case_A_R(ERR_PORT);
       case_A_R(ERR_RMA_CONFLICT);
       case_A_R(ERR_RMA_SYNC);
       case_A_R(ERR_SERVICE);
       case_A_R(ERR_SIZE);
       case_A_R(ERR_SPAWN);
       case_A_R(ERR_WIN);
       //case_A_R(ERR_LASTCODE);
       case_A_R(ERR_RMA_RANGE);
       case_A_R(ERR_RMA_ATTACH);	
       case_A_R(ERR_RMA_SHARED); 
       case_A_R(ERR_RMA_FLAVOR);        
     default:
         return ret_tmp;
  }
}

/* Mappers Source a2r - r2a */

static inline void source_conv_a2r(int *source,int *source_tmp)
{
  switch(*source)
  {
      case A_MPI_ANY_SOURCE:
        *source_tmp=R_MPI_ANY_SOURCE;
        break;
      
      case A_MPI_PROC_NULL:
        *source_tmp=R_MPI_PROC_NULL;
        break;
      
      default:
        if(*source == R_MPI_PROC_NULL || *source == R_MPI_ANY_SOURCE)
          *source_tmp = -424242; //OpenMPI
        else
           *source_tmp = *source;
      break;
  }

}

static inline void source_conv_r2a(int *source,int *source_tmp)
{
  switch(*source_tmp)
  {
    case R_MPI_ANY_SOURCE:
      *source=A_MPI_ANY_SOURCE;
      break;
      
    case R_MPI_PROC_NULL:
      *source=A_MPI_PROC_NULL;
      break;
      
    default:
        *source = *source_tmp; //OpenMPI
      break;
  }
  
}

/*Mappers Dest a2r - r2a*/

static inline void dest_conv_a2r(int *dest,int *dest_tmp)
{
  switch(*dest)
  {
    case A_MPI_ANY_SOURCE:
      *dest_tmp=R_MPI_ANY_SOURCE;
       break;

    case A_MPI_PROC_NULL:
      *dest_tmp=R_MPI_PROC_NULL;
      break;

    default:
       if(*dest == R_MPI_PROC_NULL || *dest == R_MPI_ANY_SOURCE)
        *dest_tmp = -424242; //OpenMPI
       else
        *dest_tmp = *dest;
    break;
  }
}

static inline void dest_conv_r2a(int *dest,int *dest_tmp)
{
  switch(*dest_tmp)
  {
    case R_MPI_ANY_SOURCE:
      *dest=A_MPI_ANY_SOURCE;
      break;

    case R_MPI_PROC_NULL:
      *dest=A_MPI_PROC_NULL;
      break;

    default:
      *dest = *dest_tmp; //OpenMPI
      break;
 }
}

/*Mappers Status a2r - r2a*/

static inline void status_prt_conv_a2r(A_MPI_Status **status_tmp, R_MPI_Status **status)
{
  if(*status_tmp == (A_MPI_Status*)A_MPI_STATUS_IGNORE)
  {
    *status = (R_MPI_Status*)R_MPI_STATUS_IGNORE;
  } 
  else 
  { 
	source_conv_a2r(&((**status_tmp).A_MPI_SOURCE),&((**status).R_MPI_SOURCE));   
	tag_conv_a2r(&((**status_tmp).A_MPI_TAG),&((**status).R_MPI_TAG));
	(*status)->R_MPI_ERROR = error_code_conv_a2r(((**status_tmp).A_MPI_ERROR));

	#if defined(OMPI_OMPI) || defined(_OMPI)
		(*status)->_ucount = (*status_tmp)->_ucount;
		(*status)->_cancelled = (*status_tmp)->_cancelled;
  #elif INTEL_INTEL
    (*status)->count_lo = (*status_tmp)->count_lo;
    (*status)->count_hi_and_cancelled = (*status_tmp)->count_hi_and_cancelled;
  #elif MPC_MPC
    (*status)->size = (*status_tmp)->size;
    (*status)->cancelled = (*status_tmp)->cancelled;
	 #elif HPMPI_HPMPI
    (*status)->st_cancel = (*status_tmp)->st_cancel;
    (*status)->st_count = (*status_tmp)->st_count;
  #elif INTEL_OMPI
		(*status)->_ucount = ((((size_t)((*status_tmp)->count_hi_and_cancelled)) >> 1) << sizeof(int)*8) 
					   + ((unsigned int)(*status_tmp)->count_lo);
		(*status)->_cancelled = ((*status_tmp)->count_hi_and_cancelled) & 1;
 	#elif defined(OMPI_INTEL) || defined(_INTEL)
    /* Decoupage de count */

		(*status)->count_lo = ((*status_tmp)->_ucount) & ~(((size_t)-1) << 32);
		(*status)->count_hi_and_cancelled &= 1;
		(*status)->count_hi_and_cancelled |= (int) (((*status_tmp)->_ucount) >> sizeof(int)*8 << 1);
		
    /* Set de cancelled*/
		(*status)->count_hi_and_cancelled &= ~1; 
		(*status)->count_hi_and_cancelled |= (*status_tmp)->_cancelled;
  #elif INTEL_MPC
    (*status)->size = ((((int)((*status_tmp)->count_hi_and_cancelled)) >> 1) << sizeof(int)*8)
                 + ((int)(*status_tmp)->count_lo);
    (*status)->cancelled = ((*status_tmp)->count_hi_and_cancelled) & 1;
  #elif MPC_INTEL
    /* Decoupage de count */

    (*status)->count_lo = (*status_tmp)->size;
    (*status)->count_hi_and_cancelled &= 1;
    (*status)->count_hi_and_cancelled |= (int) (((*status_tmp)->size) >> sizeof(int)*8 << 1);

    /* Set de cancelled*/
    (*status)->count_hi_and_cancelled &= ~1; 
    (*status)->count_hi_and_cancelled |= (*status_tmp)->cancelled;
  #elif defined(OMPI_MPC) || defined(_MPC)
    (*status)->size = (*status_tmp)->_ucount;
    (*status)->cancelled = (*status_tmp)->_cancelled;
  #elif MPC_OMPI
    (*status)->_ucount = (*status_tmp)->size;
    (*status)->_cancelled = (*status_tmp)->cancelled;
  #elif INTEL_HPMPI
    (*status)->st_count=((((long long)((*status_tmp)->count_hi_and_cancelled)) >> 1) << sizeof(int)*8)
                     + ((long long)(*status_tmp)->count_lo);
    (*status)->st_cancel=((*status_tmp)->count_hi_and_cancelled) & 1;
  #elif HPMPI_INTEL
    /* Decoupage de count */

		(*status)->count_lo = ((*status_tmp)->st_count) & ~(((long long)-1) << 32);
		(*status)->count_hi_and_cancelled &= 1;
		(*status)->count_hi_and_cancelled |= (int) (((*status_tmp)->st_count) >> sizeof(int)*8 << 1);
		
    /* Set de cancelled*/
		(*status)->count_hi_and_cancelled &= ~1; 
		(*status)->count_hi_and_cancelled |= (*status_tmp)->st_cancel;
  #elif defined(OMPI_HPMPI) || defined(_HPMPI)
    (*status)->st_count= (long long)((*status_tmp)->_ucount);
    (*status)->st_cancelled = (*status_tmp)->_cancelled;
  #elif HPMPI_OMPI
    (*status)->_ucount = (size_t)((*status_tmp)->st_count);
    (*status)->_cancelled = (*status_tmp)->st_cancel;
  #elif MPC_HPMPI
    (*status)->st_count= (long long)((*status_tmp)->size);
    (*status)->st_cancelled = (*status_tmp)->_cancelled;
  #elif HPMPI_MPC
    (*status)->size = (int)((*status_tmp)->st_count);
    (*status)->cancelled = (*status_tmp)->st_cancel;
	#endif
  }
}

static void status_prt_conv_r2a(A_MPI_Status **status, R_MPI_Status **status_tmp)
{
  if(*status == (A_MPI_Status*)A_MPI_STATUS_IGNORE) //here: status and not status_tmp
  {                                                 //evenif r2a; otherwise segfault for
                                                    //obvious reasons : tying to acces to  
    *status = (A_MPI_Status*)A_MPI_STATUS_IGNORE;   // non allocated struct in the else
  }
  else 
  {
    source_conv_r2a(&((**status).A_MPI_SOURCE), (&((**status_tmp).R_MPI_SOURCE)));
    tag_conv_r2a(&((**status).A_MPI_TAG), &((**status_tmp).R_MPI_TAG));
    (**status).A_MPI_ERROR = error_code_conv_r2a(((**status_tmp).R_MPI_ERROR));
   
    #if defined(OMPI_OMPI) || defined(_OMPI)
        (*status)->_ucount = (*status_tmp)->_ucount;
	      (*status)->_cancelled = (*status_tmp)->_cancelled;
    #elif INTEL_INTEL
        (*status)->count_lo = (*status_tmp)->count_lo;
        (*status)->count_hi_and_cancelled = (*status_tmp)->count_hi_and_cancelled;
    #elif MPC_MPC
        (*status)->size = (*status_tmp)->size;
        (*status)->cancelled = (*status_tmp)->cancelled;
   #elif HPMPI_HPMPI
        (*status)->st_cancel = (*status_tmp)->st_cancel;
        (*status)->st_count = (*status_tmp)->st_count;
   #elif INTEL_OMPI
	  /* Découpage de cout*/

	    (*status)->count_lo = ((*status_tmp)->_ucount) & ~(((size_t)-1) << 32);
	    (*status)->count_hi_and_cancelled &= 1;
	    (*status)->count_hi_and_cancelled |= (int) (((*status_tmp)->_ucount) >> sizeof(int)*8 << 1);
	  
    /* Set de cancelled*/
	    (*status)->count_hi_and_cancelled &= ~1; 
	    (*status)->count_hi_and_cancelled |= (*status_tmp)->_cancelled;
    #elif defined(OMPI_INTEL) || (_INTEL)
      (*status)->_ucount = (((((size_t)((*status_tmp)->count_hi_and_cancelled)) >> 1) << sizeof(int)*8) 
	  				+ ((unsigned int)((*status_tmp)->count_lo)));
	    (*status)->_cancelled = ((*status_tmp)->count_hi_and_cancelled) & 1;
    #elif INTEL_MPC
      (*status)->count_lo = (*status_tmp)->size;
      (*status)->count_hi_and_cancelled &= 1;
      (*status)->count_hi_and_cancelled |= (int) (((*status_tmp)->size) >> sizeof(int)*8 << 1);

      (*status)->count_hi_and_cancelled &= ~1;
      (*status)->count_hi_and_cancelled |= (*status_tmp)->cancelled;
    #elif MPC_INTEL
      (*status)->size = ((((size_t)((*status_tmp)->count_hi_and_cancelled)) >> 1) << sizeof(int)*8)
                       + ((unsigned int)(*status_tmp)->count_lo);
      (*status)->cancelled = ((*status_tmp)->count_hi_and_cancelled) & 1;
    #elif defined(OMPI_MPC) || defined(_MPC)
      (*status)->_ucount = (*status_tmp)->size;
      (*status)->_cancelled = (*status_tmp)->cancelled;
    #elif MPC_OMPI
      (*status)->size = (*status_tmp)->_ucount;
      (*status)->cancelled = (*status_tmp)->_cancelled;
    #elif INTEL_HPMPI
      (*status)->count_lo = (int)((*status_tmp)->st_count);
      (*status)->count_hi_and_cancelled &= 1;
      (*status)->count_hi_and_cancelled |= (int) (((*status_tmp)->st_count) >> sizeof(int)*8 << 1);

      (*status)->count_hi_and_cancelled &= ~1;
      (*status)->count_hi_and_cancelled |= (*status_tmp)->st_cancel; 
    #elif HPMPI_INTEL
      (*status)->st_count = (((((long long)((*status_tmp)->count_hi_and_cancelled)) >> 1) << sizeof(int)*8) 
	  				+ ((unsigned int)((*status_tmp)->count_lo)));
	    (*status)->st_cancel = ((*status_tmp)->count_hi_and_cancelled) & 1;
    #elif defined(OMPI_HPMPI) || defined(_HPMPI)
      (*status)->_ucount = (size_t)((*status_tmp)->st_count);
      (*status)->_cancelled = (*status_tmp)->st_cancel;
    #elif HPMPI_OMPI
      (*status)->st_count = (long long)((*status_tmp)->_ucount);
      (*status)->st_cancel = (*status_tmp)->_cancelled;
    #elif MPC_HPMPI
      (*status)->size = (int)((*status_tmp)->st_count);
      (*status)->cancelled = (*status_tmp)->st_cancel;
    #elif HPMPI_MPC
      (*status)->st_count = (long long)((*status_tmp)->size);
      (*status)->st_cancel = (*status_tmp)->cancelled;
    #endif
  }
}

static inline void status_tab_conv_r2a(A_MPI_Status *status, R_MPI_Status *status_tmp)
{ 
  if(status == (A_MPI_Status*)A_MPI_STATUS_IGNORE) //here: status and not status_tmp
  {                                                //for the same reason than previously
    status = (A_MPI_Status*)A_MPI_STATUS_IGNORE;   //MPI_STATUS_IGNORE
  }
  else
  { 
    source_conv_r2a(&((*status).A_MPI_SOURCE), (&((*status_tmp).R_MPI_SOURCE)));
    tag_conv_r2a(&((*status).A_MPI_TAG), &((*status_tmp).R_MPI_TAG));
    (*status).A_MPI_ERROR = error_code_conv_r2a(((*status_tmp).R_MPI_ERROR));
   
    #if defined(OMPI_OMPI) || defined(_OMPI)
      (status)->_ucount = (status_tmp)->_ucount;
      (status)->_cancelled = (status_tmp)->_cancelled;
    #elif INTEL_INTEL
      (status)->count_lo = (status_tmp)->count_lo;
      (status)->count_hi_and_cancelled = (status_tmp)->count_hi_and_cancelled;
    #elif MPC_MPC
      (status)->size = (status_tmp)->size;
      (status)->cancelled = (status_tmp)->cancelled;
    #elif HPMPI_HPMPI
      (status)->st_cancel = (status_tmp)->st_cancel;
      (status)->st_count = (status_tmp)->st_count;
    #elif INTEL_OMPI

      (status)->count_lo = ((status_tmp)->_ucount) & ~(((size_t)-1) << 32);
      (status)->count_hi_and_cancelled &= 1;
      (status)->count_hi_and_cancelled |= (int) (((status_tmp)->_ucount) >> sizeof(int)*8 << 1);
      /* Set de cancelled*/
      (status)->count_hi_and_cancelled &= ~1; 
      (status)->count_hi_and_cancelled |= (status_tmp)->_cancelled;
    #elif defined(OMPI_INTEL) || defined(_INTEL)
        (status)->_ucount = (((((size_t)((status_tmp)->count_hi_and_cancelled)) >> 1) << sizeof(int)*8)
                    + ((unsigned int)((status_tmp)->count_lo)));
        (status)->_cancelled = ((status_tmp)->count_hi_and_cancelled) & 1;
    #elif INTEL_MPC
      (status)->count_lo = (status_tmp)->size;
      (status)->count_hi_and_cancelled &= 1;
      (status)->count_hi_and_cancelled |= (int) (((status_tmp)->size) >> sizeof(int)*8 << 1);

      (status)->count_hi_and_cancelled &= ~1;
      (status)->count_hi_and_cancelled |= (status_tmp)->cancelled;
    #elif MPC_INTEL
      (status)->size = ((((size_t)((status_tmp)->count_hi_and_cancelled)) >> 1) << sizeof(int)*8)
                      + ((unsigned int)(status_tmp)->count_lo);
      (status)->cancelled = ((status_tmp)->count_hi_and_cancelled) & 1;
    #elif defined(OMPI_MPC) || defined(_MPC)
      (status)->_ucount = (status_tmp)->size;
      (status)->_cancelled = (status_tmp)->cancelled;
    #elif MPC_OMPI
      (status)->size = (status_tmp)->_ucount;
      (status)->cancelled = (status_tmp)->_cancelled;
    #elif INTEL_HPMPI
      (status)->count_lo = (int)((status_tmp)->st_count);
      (status)->count_hi_and_cancelled &= 1;
      (status)->count_hi_and_cancelled |= (int) (((status_tmp)->st_count) >> sizeof(int)*8 << 1);

      (status)->count_hi_and_cancelled &= ~1;
      (status)->count_hi_and_cancelled |= (status_tmp)->st_cancel; 
    #elif HPMPI_INTEL
      (status)->st_count = (((((long long)((status_tmp)->count_hi_and_cancelled)) >> 1) << sizeof(int)*8) 
	  	 		+ ((unsigned int)((*status_tmp)->count_lo)));
	    (status)->st_cancel = ((status_tmp)->count_hi_and_cancelled) & 1;
    #elif defined(OMPI_HPMPI) || defined(_HPMPI)
      (status)->_ucount = (size_t)((status_tmp)->st_count);
      (status)->_cancelled = (status_tmp)->st_cancel;
    #elif HPMPI_OMPI
      (status)->st_count = (long long)((status_tmp)->_ucount);
      (status)->st_cancel = (status_tmp)->_cancelled;
    #elif MPC_HPMPI
      (status)->size = (int)((status_tmp)->st_count);
      (status)->cancelled = (status_tmp)->st_cancel;
    #elif HPMPI_MPC
      (status)->st_count = (long long)((status_tmp)->size);
      (status)->st_cancel = (status_tmp)->cancelled;
    #endif
  }
}

static inline void int_ptr_conv_a2r(int **argc,int **argc_tmp)
{
    *argc_tmp=*argc;
	//inutile  
}

static inline void char_ppp_conv_a2r(char ****argv,char ****argv_tmp)
{
    *argv_tmp=*argv;
  	//inutile
}

static inline void int_ptr_conv_r2a(int **rank_tmp,int **rank)
{
    **rank_tmp=**rank;
  	//inutile
}

static inline void int_conv_a2r(int *count, int *count_tmp)
{
    *count_tmp=*count;
}


/* Request converter a2r - r2a for non blocking communication*/
static inline void request_ptr_conv_r2a(A_MPI_Request **request, R_MPI_Request **request_tmp)
{
    int non_blocking = 1;
    request_translation_update(*request,**request_tmp, non_blocking);
}

static inline void request_ptr_conv_a2r(A_MPI_Request **request, R_MPI_Request **request_tmp)
{
   int non_blocking;
   request_translation_get(**request, *request_tmp, &non_blocking);
}

/* Request converter a2r - r2a for non blocking communication (array)*/
static inline void request_tab_conv_r2a(A_MPI_Request *request, R_MPI_Request *request_tmp)
{         
    int non_blocking = 1;
    request_translation_update(request,*request_tmp, non_blocking);
}
             
static inline void request_tab_conv_a2r(A_MPI_Request *request, R_MPI_Request *request_tmp)
{
   int non_blocking;
   request_translation_get(*request, request_tmp, &non_blocking);
}   

/* Request converter a2r - r2a for persistent request */

static inline void request_pers_ptr_conv_r2a(A_MPI_Request **request, R_MPI_Request **request_tmp)
{
    int non_blocking = 0;
    request_translation_update(*request,**request_tmp, non_blocking);
}

static inline void request_pers_ptr_conv_a2r(A_MPI_Request **request, R_MPI_Request **request_tmp)
{
   int non_blocking;
   request_translation_get(**request, *request_tmp, &non_blocking);
}

/*Special mapper r2a (use by MPI_Cancel)*/
/*Need to know which kind of request we have to update*/
static inline void request_cancel_r2a(A_MPI_Request **request, R_MPI_Request **request_tmp)
{
  int non_blocking;
  
  R_MPI_Request request_ltmp_intra;
  R_MPI_Request *request_tmp_intra=&request_ltmp_intra;

  request_translation_get(**request, request_tmp_intra, &non_blocking);
  request_translation_update(*request,**request_tmp, non_blocking);
}

/* Mappers for deleting a request from the hashtable*/
/*Non-blocking request */
static inline void request_ptr_delete(A_MPI_Request **request, R_MPI_Request ** request_tmp)
{
  int non_blocking;

  R_MPI_Request request_ltmp_intra;
  R_MPI_Request *request_tmp_intra=&request_ltmp_intra;

  request_translation_get(**request, request_tmp_intra, &non_blocking);
  if(non_blocking == 1)
    request_translation_del(*request);

  **request = A_MPI_REQUEST_NULL;
}

static inline void request_array_delete(A_MPI_Request *request, R_MPI_Request *request_tmp)
{
 int non_blocking;

 R_MPI_Request request_ltmp_intra;
 R_MPI_Request *request_tmp_intra=&request_ltmp_intra;

 request_translation_get(*request, request_tmp_intra, &non_blocking);
 if(non_blocking == 1)
  request_translation_del(request);

 *request = A_MPI_REQUEST_NULL;
}

/*Persistent request*/
static inline void request_pers_ptr_delete(A_MPI_Request **request, R_MPI_Request ** request_tmp)
{
  int non_blocking;

  R_MPI_Request request_ltmp_intra;
  R_MPI_Request *request_tmp_intra=&request_ltmp_intra;

  request_translation_get(**request, request_tmp_intra, &non_blocking);
  if(non_blocking == 0)
    request_translation_del(*request);

  **request = A_MPI_REQUEST_NULL;
}


static inline void request_pers_array_delete(A_MPI_Request *request, R_MPI_Request * request_tmp)
{
  int non_blocking;

  R_MPI_Request request_ltmp_intra;
  R_MPI_Request *request_tmp_intra=&request_ltmp_intra;

  request_translation_get(*request, request_tmp_intra, &non_blocking);
  if(non_blocking == 0)
    request_translation_del(request);

  *request = A_MPI_REQUEST_NULL;
}

#include <sys/mman.h>
#if !defined (_WI4MPI_GCC_JIT)
extern int user_func_resolved(void *a,void *b,int *c,R_MPI_Datatype *d,void (*pf)(void *in,void *out,int *len,A_MPI_Datatype *data_type));
extern void user_fn_wrapper_template(void *a,void *b,int *c,R_MPI_Datatype *d,void (*pf)(void *in,void *out,int *len,A_MPI_Datatype *data_type));
#endif
static inline void reduce_user_fn_a2r(A_MPI_User_function **fa,R_MPI_User_function **fr)
{
  void *fh;
    char fname[256];
    char command[4096];
    char soname[256];
    char func_name[512];
    char **func_name2;
    int rank;
#if defined (_WI4MPI_GCC_JIT)
    R_MPI_Comm_rank(R_MPI_COMM_WORLD,&rank);
    sprintf(fname,"/tmp/.jit.user_func.%p_%d.c",*fa,rank);
    sprintf(soname,"/tmp/.jit.user_func.%p_%d.so",*fa,rank);
    if( access( soname, F_OK ) == -1 )
    {
        sprintf(command,"gcc -shared -fPIC -I$WI4MPI_INTERNAL_INCLUDES -I$WI4MPI_APP_INCLUDES $WI4MPI_COMPILE_OPT -o %s %s",soname,fname);
        FILE *ff=fopen(fname,"w");
        fprintf(ff,"#include \"mappers.h\"\n void wrapped_%p(void *in,void *out,int *len,R_MPI_Datatype *data_type){ A_MPI_Datatype ndata_type;datatype_conv_r2a(&ndata_type,data_type); ((A_MPI_User_function*)%p)(in,out,len,&ndata_type);}",*fa,*fa);
        fclose(ff);
        system(command);
    }
    sprintf(func_name,"wrapped_%p",*fa);
    if(!(fh=dlopen(soname,RTLD_LOCAL|RTLD_NOW)))
    {
        printf("%s\n",dlerror());
    }
    *fr=dlsym(fh,func_name);
   if(!*fr)
   {
      fprintf(stderr,"error in loading wrapped user function %s \n",func_name);
   }
#elif !defined(_WI4MPI_GCC_JIT)
    
    void* ptr = mmap(0, 1024,
                   PROT_READ | PROT_WRITE | PROT_EXEC,
                   MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    memcpy(((char *)ptr+0x10),user_fn_wrapper_template,0x100);

    ((void **)ptr)[0]=*fa;
    
    ((void **)ptr)[1]=user_func_resolved;
    *fr=ptr+0x10;
#endif
}

#if !defined(_WI4MPI_GCC_JIT)
extern int datarep_extent_func_resolved(R_MPI_Datatype a, R_MPI_Aint *b, void *c, int (*pf)(A_MPI_Datatype data_type, A_MPI_Aint *file_extent, void *extra_state));
extern void user_datarep_extent_function_template(R_MPI_Datatype a, R_MPI_Aint *b, void *c, int (*pf)(A_MPI_Datatype data_type, A_MPI_Aint *file_extent, void *extra_state));

static inline void datarep_extent_function_converter_a2r(A_MPI_Datarep_extent_function **fa, R_MPI_Datarep_extent_function **fr)
{
	void* ptr = mmap(0, 1024,
                   PROT_READ | PROT_WRITE | PROT_EXEC,
                   MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    memcpy(((char *)ptr+0x10),user_datarep_extent_function_template,0x100);

    ((void **)ptr)[0]=*fa;

    ((void **)ptr)[1]=datarep_extent_func_resolved;
    *fr=ptr+0x10;
}

extern int datarep_conversion_func_resolved(void *a, R_MPI_Datatype b, int c, void *d, R_MPI_Offset e, void *f, int (*pf)(void *userbuf, A_MPI_Datatype datatype, int count, void *filebuf, A_MPI_Offset posistion, void *extra_state));
extern void user_datarep_conversion_function_template(void *a, R_MPI_Datatype b, int c, void *d, R_MPI_Offset e, void *f, int (*pf)(void *userbuf, A_MPI_Datatype datatype, int count, void *filebuf, A_MPI_Offset posistion, void *extra_state));

static inline void datarep_conversion_function_a2r(A_MPI_Datarep_conversion_function **fa,R_MPI_Datarep_conversion_function **fr)
{
	void* ptr = mmap(0, 1024,
                   PROT_READ | PROT_WRITE | PROT_EXEC,
                   MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    memcpy(((char *)ptr+0x10),user_datarep_conversion_function_template,0x100);

    ((void **)ptr)[0]=*fa;

    ((void **)ptr)[1]=datarep_conversion_func_resolved;
    *fr=ptr+0x10;
}

extern int user_qrequest_query_function_template(void *a, R_MPI_Status *b, int (*pf)(void *extra_state, A_MPI_Status *status));
extern int qrequest_query_func_resolved(void *a, R_MPI_Status *b, int (*pf)(void *extra_state, A_MPI_Status *status));

static inline void grequest_query_fn_a2r(A_MPI_Grequest_query_function **fa, R_MPI_Grequest_query_function **fr)
{
  void* ptr = mmap(0, 1024,
                   PROT_READ | PROT_WRITE | PROT_EXEC,
                   MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    memcpy(((char *)ptr+0x10),user_qrequest_query_function_template,0x100);

    ((void **)ptr)[0]=*fa;

    ((void **)ptr)[1]=qrequest_query_func_resolved;
    *fr=ptr+0x10;
}

#endif
/* OP converter a2r - r2a */

static A_MPI_User_function* ptr_user_func = NULL;
static A_MPI_Comm_errhandler_function *ptr_comm_fn_handler = NULL;
static A_MPI_Handler_function *ptr_handler_fn = NULL;
static A_MPI_Datarep_conversion_function *ptr_read_conversion_fn = NULL;
static A_MPI_Datarep_conversion_function *ptr_write_conversion_fn = NULL;
static A_MPI_Datarep_extent_function *ptr_extent_fn = NULL;
static A_MPI_Win_copy_attr_function *ptr_win_copy_fn = NULL;
static A_MPI_Win_delete_attr_function *ptr_win_dlt_fn = NULL;
static A_MPI_Grequest_query_function *ptr_grq_query_fn = NULL;
static A_MPI_Type_copy_attr_function *ptr_type_cpy_attr_fn = NULL;
static A_MPI_Type_delete_attr_function *ptr_type_dlt_attr_fn = NULL;

//gen_hash_conv(op,MPI_Op,operation)
static inline void op_conv_a2r(A_MPI_Op * op, R_MPI_Op * op_tmp)
{
  A_MPI_User_function * function;
  int type_op=0;
  
  if((*op == A_MPI_OP_NULL	) ||
     (*op == A_MPI_MAX		) ||
     (*op == A_MPI_MIN		) ||
     (*op == A_MPI_SUM		) ||
     (*op == A_MPI_PROD		) ||
     (*op == A_MPI_LAND		) ||
     (*op == A_MPI_BAND		) ||
     (*op == A_MPI_LOR		) ||
     (*op == A_MPI_BOR		) ||
     (*op == A_MPI_LXOR		) ||
     (*op == A_MPI_BXOR		) ||
     (*op == A_MPI_MINLOC	) ||
     (*op == A_MPI_MAXLOC	) || 
     (*op == A_MPI_REPLACE	) ) 
        type_op =1;
  
  //case where a collective is called by R_MPI implementation itself
  //example MPICH use MPI_Allreduce in MPI_File_open in order to make sure
  //that all process open the file with the same mode: MPI_OP = ADIO_same_mode = MPI_MAX
  //Works only for OMPI_INTEL MPI_File_open
  //if((*op == A_ADIO_same_amode) ||
  //   (*op == A_UNDEFINED_OP   ) ||
  //   (*op == A_ADIO_MIN       )) 
  //      type_op = 2;

  if(type_op==1)
    operation_translation_get(*op,op_tmp);
  else if(type_op == 2)
    operation_translation_get(*op,op_tmp);
  else if(type_op == 0)
  {
    operation_translation_get(*op,op_tmp);
  /*  operation_fn_translation_get(*op, &function);
    if (function != NULL)
    {
      ptr_user_func = function;
    }*/
  }
}

static inline void op_conv_r2a(A_MPI_Op * op, R_MPI_Op * op_tmp)
{
  int type_op=0;
   if((*op_tmp == R_MPI_OP_NULL	) ||
     (*op_tmp == R_MPI_MAX		) ||
     (*op_tmp == R_MPI_MIN		) ||
     (*op_tmp == R_MPI_SUM		) ||
     (*op_tmp == R_MPI_PROD		) ||
     (*op_tmp == R_MPI_LAND		) ||
     (*op_tmp == R_MPI_BAND		) ||
     (*op_tmp == R_MPI_LOR		) ||
     (*op_tmp == R_MPI_BOR		) ||
     (*op_tmp == R_MPI_LXOR		) ||
     (*op_tmp == R_MPI_BXOR		) ||
     (*op_tmp == R_MPI_MINLOC	) ||
     (*op_tmp == R_MPI_MAXLOC	) ||  
     (*op_tmp == R_MPI_REPLACE) )  
        type_op =1;
 
  if(type_op==1) 
    operation_translation_update(op,*op_tmp);
  else
  {
     operation_translation_update(op,*op_tmp);
//     operation_fn_translation_update(*op,ptr_user_func);
  }

}

/* Errhandler converter a2r - r2a */

static inline void errhandler_conv_a2r(A_MPI_Errhandler *errhandler, R_MPI_Errhandler *errhandler_tmp)
{
  errhandler_translation_get(*errhandler, errhandler_tmp);
}

// for create
//comm
static inline void errhandler_comm_ptr_conv_r2a(A_MPI_Errhandler **errhandler, R_MPI_Errhandler **errhandler_tmp) 
{
  errhandler_translation_update(*errhandler, **errhandler_tmp);
  errhandler_fn_translation_update(**errhandler, ptr_comm_fn_handler);
}
//deprecated one
static inline void errhandler_ptr_conv_r2a(A_MPI_Errhandler **errhandler, R_MPI_Errhandler **errhandler_tmp)
{
    if(**errhandler_tmp==R_MPI_ERRORS_ARE_FATAL)
    {
        **errhandler=A_MPI_ERRORS_ARE_FATAL;
        return;

    }
    if(**errhandler_tmp==R_MPI_ERRORS_RETURN)
    {
        **errhandler=A_MPI_ERRORS_RETURN;
        return;

    }
    if(**errhandler_tmp==R_MPI_ERRHANDLER_NULL)
    {
        **errhandler=A_MPI_ERRHANDLER_NULL;
        return;

    }
  errhandler_translation_update(*errhandler, **errhandler_tmp);
  errhandler_fn_translation_update(**errhandler, ptr_handler_fn);
}
//dell
static inline void errhandler_del(A_MPI_Errhandler *errhandler, R_MPI_Errhandler *errhandler_tmp)
{
  errhandler_translation_del(errhandler);
  *errhandler = A_MPI_ERRHANDLER_NULL;
}



/* Message coverter a2r - r2a */

gen_hash_conv(message,MPI_Message,message);
//#ifdef INTEL_INTEL
//
//static inline void message_ptr_conv_a2r(A_MPI_Message **message, R_MPI_Message **message_tmp)
//{
//  if(*message == (A_MPI_Message*)A_MPI_MESSAGE_NULL)
//    *message_tmp = (R_MPI_Message*)R_MPI_MESSAGE_NULL;
//  else if(*message == (A_MPI_Message*)A_MPI_MESSAGE_NO_PROC)
//    *message_tmp = (R_MPI_Message*)R_MPI_MESSAGE_NO_PROC;
//  else *message_tmp = *message;
//}
//
//static inline void message_ptr_conv_r2a(A_MPI_Message **message, R_MPI_Message **message_tmp)
//{
//  if(*message_tmp == (R_MPI_Message*)R_MPI_MESSAGE_NULL)
//    *message = (A_MPI_Message*)A_MPI_MESSAGE_NULL;
//  else if(*message_tmp == (R_MPI_Message*)R_MPI_MESSAGE_NO_PROC)
//    *message = (A_MPI_Message*)A_MPI_MESSAGE_NO_PROC;
//  else *message = *message_tmp;
//}
//
//#endif

/* Group coonverter a2r - r2a */

gen_hash_conv(group,MPI_Group,group);

/* Info converter a2r - r2a */

gen_hash_conv(info,MPI_Info,info);


/* Topo_status converter r2a */
static inline void topo_status_mapper(int * status, int* status_tmp)
{
  switch(*status_tmp)
  {
    case R_MPI_GRAPH:
      *status= A_MPI_GRAPH;
       break;

    case R_MPI_CART:
      *status= A_MPI_CART;
      break;

    default:
      *status = A_MPI_UNDEFINED;
      break;
  }
}

/* split_type (MPI_Comm_split_type)*/

static inline void splittype_conv_a2r(int * split_type, int * split_type_tmp)
{
   if(*split_type == A_MPI_UNDEFINED)
      *split_type_tmp = R_MPI_UNDEFINED;
   else if (*split_type == A_MPI_COMM_TYPE_SHARED)
      *split_type_tmp = R_MPI_COMM_TYPE_SHARED;
   else *split_type_tmp = *split_type;
}

static inline void splittype_conv_r2a(int * split_type, int * split_type_tmp)
{
   if(*split_type_tmp == R_MPI_UNDEFINED)
      *split_type = A_MPI_UNDEFINED;
   else if (*split_type_tmp == R_MPI_COMM_TYPE_SHARED)
      *split_type = A_MPI_COMM_TYPE_SHARED;
   else *split_type = *split_type_tmp;
}

/* MPI_Win */

gen_hash_conv(win,MPI_Win,win);

/*RMA assertions mode */

static inline void assert_mode_a2r(int *assert, int *assert_tmp)
{
   if(*assert & A_MPI_MODE_NOCHECK  )
     *assert_tmp |= R_MPI_MODE_NOCHECK; 
   if(*assert & A_MPI_MODE_NOPRECEDE)
     *assert_tmp |= R_MPI_MODE_NOPRECEDE ;
   if(*assert & A_MPI_MODE_NOPUT    )
     *assert_tmp |= R_MPI_MODE_NOPUT ;
   if(*assert & A_MPI_MODE_NOSTORE  )
     *assert_tmp |= R_MPI_MODE_NOSTORE;
   if(*assert & A_MPI_MODE_NOSUCCEED)
     *assert_tmp |= R_MPI_MODE_NOSUCCEED ;
   if(*assert == 0)
      *assert_tmp =0;
}

static inline void assert_mode_r2a(int *assert, int *assert_tmp)
{
  if(*assert_tmp & R_MPI_MODE_NOCHECK  )
     *assert |=  A_MPI_MODE_NOCHECK; 
   if(*assert_tmp & R_MPI_MODE_NOPRECEDE)
     *assert |= A_MPI_MODE_NOPRECEDE ;
   if(*assert_tmp & R_MPI_MODE_NOPUT    )
     *assert |= A_MPI_MODE_NOPUT ;
   if(*assert_tmp & R_MPI_MODE_NOSTORE  )
     *assert |= A_MPI_MODE_NOSTORE; 
   if(*assert_tmp & R_MPI_MODE_NOSUCCEED)
     *assert |= A_MPI_MODE_NOSUCCEED ;
   if(*assert ==0)
      *assert = 0;
}

/* Lock type */

static inline void lock_conv_a2r(int *lock_type, int *lock_type_tmp)
{
   switch(*lock_type)
   {
      case A_MPI_LOCK_EXCLUSIVE:
         *lock_type_tmp= R_MPI_LOCK_EXCLUSIVE;
         break;
      case A_MPI_LOCK_SHARED:   
          *lock_type_tmp= R_MPI_LOCK_SHARED;
          break;
   }   
}

static inline void lock_conv_r2a(int *lock_type, int *lock_type_tmp)
{
    switch(*lock_type_tmp)
    {
        case R_MPI_LOCK_EXCLUSIVE:
            *lock_type= A_MPI_LOCK_EXCLUSIVE;
            break;
        case R_MPI_LOCK_SHARED:   
            *lock_type= A_MPI_LOCK_SHARED;
            break;
    }
}

/* Win keyval's attributes */

static inline void win_attr_flavor_conv_a2r(int *attr, int *attr_tmp)
{
   switch (*attr)
   {
      /* keyval MPI_WIN_CREATE_FLAVOR */
      case A_MPI_WIN_FLAVOR_CREATE:
         *attr_tmp = R_MPI_WIN_FLAVOR_CREATE; 
      case A_MPI_WIN_FLAVOR_ALLOCATE:
         *attr_tmp = R_MPI_WIN_FLAVOR_ALLOCATE; 
      case A_MPI_WIN_FLAVOR_DYNAMIC :
         *attr_tmp = R_MPI_WIN_FLAVOR_DYNAMIC; 
      case A_MPI_WIN_FLAVOR_SHARED  :
         *attr_tmp = R_MPI_WIN_FLAVOR_SHARED;
      
      default: /* in case this is an user's attribute or a non constant var (need to check the behavior)*/
         *attr_tmp = *attr;
   }
}

static inline void win_attr_flavor_conv_r2a(int *attr, int *attr_tmp)
{
    switch (*attr_tmp)
    {
        /* keyval MPI_WIN_CREATE_FLAVOR */
        case R_MPI_WIN_FLAVOR_CREATE:
            *attr = A_MPI_WIN_FLAVOR_CREATE; 
        case R_MPI_WIN_FLAVOR_ALLOCATE:
            *attr = A_MPI_WIN_FLAVOR_ALLOCATE; 
        case R_MPI_WIN_FLAVOR_DYNAMIC :
            *attr = A_MPI_WIN_FLAVOR_DYNAMIC; 
        case R_MPI_WIN_FLAVOR_SHARED  :
            *attr = A_MPI_WIN_FLAVOR_SHARED;
        
        default: /* in case this is an user's attribute or a non constant var (need to check the behavior)*/
            *attr = *attr_tmp;
    }
}

static inline void win_attr_model_conv_a2r(int *attr, int *attr_tmp)
{
   switch (*attr)
   {
      /* keyval MPI_WIN_MODEL */
      case A_MPI_WIN_UNIFIED  :
         *attr_tmp = R_MPI_WIN_UNIFIED;
      case A_MPI_WIN_SEPARATE  :
         *attr_tmp = R_MPI_WIN_SEPARATE;

      default: /* in case this is an user's attribute or a non constant var (need to check the behavior)*/
         *attr_tmp = *attr;
   }
}

static inline void win_attr_model_conv_r2a(int *attr, int *attr_tmp)
{
    switch (*attr_tmp)
    {
       /* keyval MPI_WIN_MODEL */
        case A_MPI_WIN_UNIFIED  :
            *attr_tmp = R_MPI_WIN_UNIFIED;
        case A_MPI_WIN_SEPARATE  :
            *attr_tmp = R_MPI_WIN_SEPARATE;

        default: /* in case this is an user's attribute or a non constant var (need to check the behavior)*/
            *attr = *attr_tmp;
    }
}

/* Win converter */

static inline void weight_conv_a2r(int ** buf,int** buf_tmp)
{
  if(*buf == (void*) A_MPI_UNWEIGHTED)
      *buf_tmp= (void*) R_MPI_UNWEIGHTED;
            
  else if( *buf == (void*) A_MPI_WEIGHTS_EMPTY )
      *buf_tmp= (void*) R_MPI_WEIGHTS_EMPTY;  
  else 
     //memcpy(buf_tmp, buf, sizeof(void*));
     *buf_tmp=*buf;
}

static inline void weight_conv_r2a(int **buf_tmp, int **buf)
{
   if(*buf == (void*) R_MPI_UNWEIGHTED)
    *buf= (void*) A_MPI_UNWEIGHTED;
  
  else if( *buf == (void*) R_MPI_WEIGHTS_EMPTY )
    *buf= (void*) A_MPI_WEIGHTS_EMPTY;
  
  else 
     //memcpy(buf_tmp, buf, sizeof(void*));
     *buf=*buf_tmp;
}

/* Other */
/*
R_MPI_TYPECLASS_REAL 
R_MPI_TYPECLASS_INTEGER
R_MPI_TYPECLASS_COMPLEX
*/

static inline void typeclass_conv_a2r(int *typeclass, int *typeclass_tmp)
{
   switch(*typeclass)
   {
      case A_MPI_TYPECLASS_REAL:
         *typeclass_tmp= R_MPI_TYPECLASS_REAL;
         break;
      case A_MPI_TYPECLASS_INTEGER:
         *typeclass_tmp= R_MPI_TYPECLASS_INTEGER;
         break;
      case A_MPI_TYPECLASS_COMPLEX:
         *typeclass_tmp= R_MPI_TYPECLASS_COMPLEX;
         break;

   } 
}
static inline void typeclass_conv_r2a(int *typeclass, int *typeclass_tmp)
{
   switch(*typeclass_tmp)
   {
      case R_MPI_TYPECLASS_REAL:
         *typeclass= A_MPI_TYPECLASS_REAL;
         break;
      case R_MPI_TYPECLASS_INTEGER:
         *typeclass= A_MPI_TYPECLASS_INTEGER;
         break;
      case R_MPI_TYPECLASS_COMPLEX:
         *typeclass= A_MPI_TYPECLASS_COMPLEX;
         break;
   }
}

/* MPI_T */

gen_hash_conv(t_enum, MPI_T_enum, t_enum);
gen_hash_conv(cvar_handle, MPI_T_cvar_handle, cvar_handle);
gen_hash_conv(pvar_handle, MPI_T_pvar_handle, pvar_handle);
//gen_hash_conv(pvar_session, MPI_T_pvar_session, pvar_session);

/* MPI-IO */

/* Amode converter a2r - r2a */
static inline void amode_conv_a2r(int *amode, int *amode_tmp)
{
  if(*amode & A_MPI_MODE_RDONLY)
    *amode_tmp |= R_MPI_MODE_RDONLY;
  if(*amode & A_MPI_MODE_RDWR)
    *amode_tmp |= R_MPI_MODE_RDWR;
  if(*amode & A_MPI_MODE_WRONLY)
    *amode_tmp |= R_MPI_MODE_WRONLY;
  if(*amode & A_MPI_MODE_CREATE)
    *amode_tmp |= R_MPI_MODE_CREATE;
  if(*amode & A_MPI_MODE_EXCL)
    *amode_tmp |= R_MPI_MODE_EXCL;
  if(*amode & A_MPI_MODE_DELETE_ON_CLOSE)
    *amode_tmp |= R_MPI_MODE_DELETE_ON_CLOSE;
  if(*amode & A_MPI_MODE_UNIQUE_OPEN)
    *amode_tmp |= R_MPI_MODE_UNIQUE_OPEN;
  if(*amode & A_MPI_MODE_SEQUENTIAL)
    *amode_tmp |= R_MPI_MODE_SEQUENTIAL;
  if(*amode & A_MPI_MODE_APPEND)
    *amode_tmp |= R_MPI_MODE_APPEND;
}

static inline void amode_conv_r2a(int *amode, int *amode_tmp)
{
  if(*amode_tmp & A_MPI_MODE_RDONLY)
    *amode |= R_MPI_MODE_RDONLY;
  if(*amode_tmp & A_MPI_MODE_RDWR)
    *amode |= R_MPI_MODE_RDWR;
  if(*amode_tmp & A_MPI_MODE_WRONLY)
    *amode |= R_MPI_MODE_WRONLY;
  if(*amode_tmp & A_MPI_MODE_CREATE)
    *amode |= R_MPI_MODE_CREATE;
  if(*amode_tmp & A_MPI_MODE_EXCL)
    *amode |= R_MPI_MODE_EXCL;
  if(*amode_tmp & A_MPI_MODE_DELETE_ON_CLOSE)
    *amode |= R_MPI_MODE_DELETE_ON_CLOSE;
  if(*amode_tmp & A_MPI_MODE_UNIQUE_OPEN)
    *amode |= R_MPI_MODE_UNIQUE_OPEN;
  if(*amode_tmp & A_MPI_MODE_SEQUENTIAL)
    *amode |= R_MPI_MODE_SEQUENTIAL;
  if(*amode_tmp & A_MPI_MODE_APPEND)
    *amode |= R_MPI_MODE_APPEND;
}

/* File converter a2r - r2a */
gen_hash_conv(file,MPI_File,file);


static inline void order_conv_a2r(int *order,int *order_tmp)
{
   if(A_MPI_ORDER_FORTRAN==*order)
   {
      *order_tmp=(int )R_MPI_ORDER_FORTRAN;
   }
   else if(A_MPI_ORDER_C==*order)
   {
      *order_tmp=(int )R_MPI_ORDER_C;
   }
}

static inline void order2_conv_a2r(int *order,int *order_tmp)
{
   if(A_MPI_DISTRIBUTE_DFLT_DARG==*order)
   {
      *order_tmp=(int )R_MPI_DISTRIBUTE_DFLT_DARG;
   }
   else if(A_MPI_DISTRIBUTE_BLOCK==*order)
   {
      *order_tmp=(int )R_MPI_DISTRIBUTE_BLOCK;
   }
   else if(A_MPI_DISTRIBUTE_CYCLIC==*order)
   {
      *order_tmp=(int )R_MPI_DISTRIBUTE_CYCLIC;
   }
   else if(A_MPI_DISTRIBUTE_NONE==*order)
   {
      *order_tmp=(int )R_MPI_DISTRIBUTE_NONE;
   }
   else
      *order_tmp=*order;
}

#endif /*MAPPERS_HEADERS */

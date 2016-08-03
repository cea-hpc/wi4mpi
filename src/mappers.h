//############################# Wi4MPI License ###########################
//# `04/04/2016`                                                         #
//# Copyright or (C) or Copr. Commissariat a l'Energie Atomique          #
//#                                                                      #
//# IDDN.FR.001.210022.001.S.P.2014.000.10800                            #
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

#include <stdarg.h>
//#include <pthread.h>
#include "app_mpi.h" // A_MPI_ && A_PMPI_ (Souche MPI Source)
#include "run_mpi.h" // R_MPI_ && R_PMPI_ (Souche MPI Cible)
// Rajouter un ifdef

#ifdef INTEL_INTEL
      #include "run_mpio.h" // mpi.h from intel implementation doesn't contain MPI-IO routines.
      #include "app_mpio.h" // mpi.h from intel implementation doesn't contain MPI-IO routines.
#elif INTEL_OMPI
      #include "app_mpio.h"
#elif OMPI_INTEL
      #include "run_mpio.h"
#endif

#include "new_utils.h"
#include "new_utils_fn.h"
 
/*ADIOS CONST*/
//#include "adio_extern.h"  // header which contain the value of ADIO_same_amode

//#define A_ADIO_same_amode (A_MPI_Op) (0x58000001)
//#define A_UNDEFINED_OP (A_MPI_Op) (0X98000000)A_MPI_Op) (0x58000002)
//#define A_ADIO_MIN (A_MPI_Op) (0x58000002)

#define MIN(a,b) ((a<b)? a : b)
#define MAX(a,b) ((a>b)? a : b)

#define const 
//#ifdef OMPI_INTEL
//	#define A_OMPI 1
//	#define R_INTEL 1
//#elif INTEL_OMPI
//	#define A_INTEL 1
//	#define R_OMPI 1
//#elif OMPI_OMPI
//	#define A_OMPI 1
//	#define R_OMPI 1
//#endif

#define gen_hash_conv(NAME,TYPE,NAME2) \
static inline void  NAME##_conv_a2r(A_##TYPE *ca,R_##TYPE *cr)\
{\
NAME2##_translation_get(*ca,cr);\
}\
static inline void NAME##_conv_r2a(A_##TYPE *ca,R_##TYPE *cr)\
{\
NAME2##_translation_update(ca,*cr);\
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
       case_R_A(ERR_LASTCODE);


	
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
       case_A_R(ERR_LASTCODE);

	
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

	#ifdef OMPI_OMPI 
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
					   + ((size_t)(*status_tmp)->count_lo);
		(*status)->_cancelled = ((*status_tmp)->count_hi_and_cancelled) & 1;
 	#elif OMPI_INTEL
    /* Decoupage de count */

		(*status)->count_lo = ((*status_tmp)->_ucount) & ~(((size_t)-1) << 31);
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
  #elif OMPI_MPC
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

		(*status)->count_lo = ((*status_tmp)->st_count) & ~(((long long)-1) << 31);
		(*status)->count_hi_and_cancelled &= 1;
		(*status)->count_hi_and_cancelled |= (int) (((*status_tmp)->st_count) >> sizeof(int)*8 << 1);
		
    /* Set de cancelled*/
		(*status)->count_hi_and_cancelled &= ~1; 
		(*status)->count_hi_and_cancelled |= (*status_tmp)->st_cancel;
  #elif OMPI_HPMPI
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
   
    #ifdef OMPI_OMPI 
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

	    (*status)->count_lo = ((*status_tmp)->_ucount) & ~(((size_t)-1) << 31);
	    (*status)->count_hi_and_cancelled &= 1;
	    (*status)->count_hi_and_cancelled |= (int) (((*status_tmp)->_ucount) >> sizeof(int)*8 << 1);
	  
    /* Set de cancelled*/
	    (*status)->count_hi_and_cancelled &= ~1; 
	    (*status)->count_hi_and_cancelled |= (*status_tmp)->_cancelled;
    #elif OMPI_INTEL
      (*status)->_ucount = (((((size_t)((*status_tmp)->count_hi_and_cancelled)) >> 1) << sizeof(int)*8) 
	  				+ ((size_t)((*status_tmp)->count_lo)));
	    (*status)->_cancelled = ((*status_tmp)->count_hi_and_cancelled) & 1;
    #elif INTEL_MPC
      (*status)->count_lo = (*status_tmp)->size;
      (*status)->count_hi_and_cancelled &= 1;
      (*status)->count_hi_and_cancelled |= (int) (((*status_tmp)->size) >> sizeof(int)*8 << 1);

      (*status)->count_hi_and_cancelled &= ~1;
      (*status)->count_hi_and_cancelled |= (*status_tmp)->cancelled;
    #elif MPC_INTEL
      (*status)->size = ((((size_t)((*status_tmp)->count_hi_and_cancelled)) >> 1) << sizeof(int)*8)
                       + ((size_t)(*status_tmp)->count_lo);
      (*status)->cancelled = ((*status_tmp)->count_hi_and_cancelled) & 1;
    #elif OMPI_MPC
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
	  				+ ((size_t)((*status_tmp)->count_lo)));
	    (*status)->st_cancel = ((*status_tmp)->count_hi_and_cancelled) & 1;
    #elif OMPI_HPMPI
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
   
    #ifdef OMPI_OMPI 
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

      (status)->count_lo = ((status_tmp)->_ucount) & ~(((size_t)-1) << 31);
      (status)->count_hi_and_cancelled &= 1;
      (status)->count_hi_and_cancelled |= (int) (((status_tmp)->_ucount) >> sizeof(int)*8 << 1);
      /* Set de cancelled*/
      (status)->count_hi_and_cancelled &= ~1; 
      (status)->count_hi_and_cancelled |= (status_tmp)->_cancelled;
    #elif OMPI_INTEL
        (status)->_ucount = (((((size_t)((status_tmp)->count_hi_and_cancelled)) >> 1) << sizeof(int)*8)
                    + ((size_t)((status_tmp)->count_lo)));
        (status)->_cancelled = ((status_tmp)->count_hi_and_cancelled) & 1;
    #elif INTEL_MPC
      (status)->count_lo = (status_tmp)->size;
      (status)->count_hi_and_cancelled &= 1;
      (status)->count_hi_and_cancelled |= (int) (((status_tmp)->size) >> sizeof(int)*8 << 1);

      (status)->count_hi_and_cancelled &= ~1;
      (status)->count_hi_and_cancelled |= (status_tmp)->cancelled;
    #elif MPC_INTEL
      (status)->size = ((((size_t)((status_tmp)->count_hi_and_cancelled)) >> 1) << sizeof(int)*8)
                      + ((size_t)(status_tmp)->count_lo);
      (status)->cancelled = ((status_tmp)->count_hi_and_cancelled) & 1;
    #elif OMPI_MPC
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
	  	 		+ ((size_t)((status_tmp)->count_lo)));
	    (status)->st_cancel = ((status_tmp)->count_hi_and_cancelled) & 1;
    #elif OMPI_HPMPI
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

/* OP converter a2r - r2a */

static A_MPI_User_function* ptr_user_func = NULL;
static A_MPI_Comm_errhandler_function *ptr_comm_fn_handler = NULL;
static A_MPI_Handler_function *ptr_handler_fn = NULL;
static A_MPI_Datarep_conversion_function *ptr_read_conversion_fn = NULL;
static A_MPI_Datarep_conversion_function *ptr_write_conversion_fn = NULL;
static A_MPI_Datarep_extent_function *ptr_extent_fn = NULL;


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
    operation_fn_translation_get(*op, &function);
    if (function != NULL)
    {
      ptr_user_func = function;
    }
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
     operation_fn_translation_update(*op,ptr_user_func);
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

#ifdef INTEL_INTEL

static inline void message_ptr_conv_a2r(A_MPI_Message **message, R_MPI_Message **message_tmp)
{
  if(*message == (A_MPI_Message*)A_MPI_MESSAGE_NULL)
    *message_tmp = (R_MPI_Message*)R_MPI_MESSAGE_NULL;
  else if(*message == (A_MPI_Message*)A_MPI_MESSAGE_NO_PROC)
    *message_tmp = (R_MPI_Message*)R_MPI_MESSAGE_NO_PROC;
  else *message_tmp = *message;
}

static inline void message_ptr_conv_r2a(A_MPI_Message **message, R_MPI_Message **message_tmp)
{
  if(*message_tmp == (R_MPI_Message*)R_MPI_MESSAGE_NULL)
    *message = (A_MPI_Message*)A_MPI_MESSAGE_NULL;
  else if(*message_tmp == (R_MPI_Message*)R_MPI_MESSAGE_NO_PROC)
    *message = (A_MPI_Message*)A_MPI_MESSAGE_NO_PROC;
  else *message = *message_tmp;
}

#endif

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

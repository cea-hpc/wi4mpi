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


#ifndef MANUAL_WRAPPER_H
#define MANUAL_WRAPPER_H

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <dlfcn.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "wrapper_f.h"
#include "func_char_fort.h"
extern __thread int in_w;

#ifndef IFORT_CALL
#define IFORT_CALL
#endif
static inline void status_a2r(int *ca,int *cr){
    source_a2r(&ca[A_f_MPI_SOURCE-1],&cr[R_f_MPI_SOURCE-1]);
    cr[R_f_MPI_TAG-1]=ca[A_f_MPI_TAG-1];
    error_a2r(&ca[R_f_MPI_ERROR-1],&cr[A_f_MPI_ERROR-1]);
#ifdef INTEL_INTEL 
    cr[0]=ca[0];
    cr[1]=ca[1];
    
#endif
#if defined(OMPI_OMPI) || defined(_OMPI)
    cr[3]=ca[3];
    cr[4]=ca[4];
    cr[5]=ca[5];
#endif
#if defined(OMPI_INTEL) || defined(_INTEL)
    cr[0]=(ca[3]<<1)+ca[5];
    cr[1]=ca[4];
    
#endif
#ifdef INTEL_OMPI 
    cr[3]=(ca[0]>>1);
    cr[4]=ca[1];
    cr[5]=(ca[0]&1);
#endif
}
static inline void status_r2a(int *ca,int *cr){
    source_r2a(&ca[A_f_MPI_SOURCE-1],&cr[R_f_MPI_SOURCE-1]);
//    printf("%d %d %d %d %d %d\n",cr[0],cr[1],cr[2],cr[3],cr[4],cr[5]);    
    //ca[A_MPI_SOURCE-1]=cr[R_MPI_SOURCE-1];
    ca[A_f_MPI_TAG-1]=   cr[R_f_MPI_TAG-1];
    error_r2a(&ca[A_f_MPI_ERROR-1],&cr[R_f_MPI_ERROR-1]);
//    printf("%d %d %d %d %d\n",ca[0],ca[1],ca[2],ca[3],ca[4]);    
#ifdef INTEL_INTEL 
    ca[0]=cr[0];
    ca[1]=cr[1];
    
#endif
#if defined(OMPI_OMPI) || defined(_OMPI)
    ca[3]=cr[3];
    ca[4]=cr[4];
    ca[5]=cr[5];
#endif
#ifdef INTEL_OMPI 
    ca[1]=cr[4];
    ca[0]=(cr[3]<<1)+cr[5];
#endif
#if defined(OMPI_INTEL) || defined(_INTEL)
    ca[3]=(cr[0]>>1);
    ca[4]=cr[1];
    ca[5]=(cr[0]&1);
#endif
    //printf("%d %d %d %d %d\n",ca[0],ca[1],ca[2],ca[3],ca[4]);    
}
static inline void buffer_a2r(void **ca,void **cr)
{
    //printf("%p %p %p\n",*ca,A_MPI_BOTTOM,A_MPI_IN_PLACE);
    if(((int*)(*ca))==A_f_MPI_BOTTOM)
    {
        *cr=(void *)R_f_MPI_BOTTOM;
    }
    else
        if(((int*)(*ca))==A_f_MPI_IN_PLACE)
        {
            *cr=(void *)R_f_MPI_IN_PLACE;
        }
        else
            *cr=*ca;   
    

}
static inline void buffer_r2a(void **ca,void **cr)
{
    if(((int*)(*cr))==R_f_MPI_BOTTOM)
    {
        *ca=(void *)A_f_MPI_BOTTOM;
    }
    else
        if(((int*)(*cr))==R_f_MPI_IN_PLACE)
        {
            *ca=(void *)A_f_MPI_IN_PLACE;
        }
        else
            *ca=*cr;   
}
static inline void wrapper_user_func(void *iv,void *iov,int *len,int *dat)
{
    int dat_tmp;
    datatype_r2a(&dat_tmp,dat);
    //printf("datatype %d %d\n",*dat,dat_tmp);
    ((void (*)(int *n,int *,int *,int *))User_fct_g_ptr)(iv,iov,len,&dat_tmp);
}
static inline void err_handler_wrap_func(int *comm,int *ier,...)
{
    int comm_tmp,ier_tmp;
    void (*err_handler_func)(int *comm,int *ier,...);
    //printf("comm %d %d\n",comm_tmp,*comm);
    comm_r2a(&comm_tmp,comm);
   error_r2a(&ier_tmp,ier);
    communicator_f_fn_translation_get(*comm,(void**)&err_handler_func);
    //printf("comm %d %d\n",comm_tmp,*comm);
    err_handler_func(&comm_tmp,&ier_tmp,"",NULL);
}
static inline void handler_fct_ptr_conv_a2r(void **fct,void **fct_tmp)
{
    *fct_tmp=err_handler_wrap_func;
}
static inline void copy_ptr_converter_a2r(void **fct,void **fct_tmp)
{
    
           *fct_tmp=*fct;
}
static inline void errhandler_set_func(int comm,int errhandler)
{
    void *func;
 if(errhandler!=R_f_MPI_ERRORS_ARE_FATAL &&errhandler!=R_f_MPI_ERRORS_RETURN &&errhandler!=R_f_MPI_ERRHANDLER_NULL)
 {      errhandler_f_fn_translation_get(errhandler,&func);
        //printf("%d\n%p %d\n",errhandler,func,comm);
       communicator_f_fn_translation_update(comm,func);
}
}
#if !defined (_WI4MPI_GCC_JIT)
 #include <sys/mman.h>

extern int user_func_resolved_fort(void *a,void *b,int *c,int *d,void (*pf)(void *in,void *out,int *len,int *data_type));
extern void user_fn_wrapper_template_fort(void *a,void *b,int *c,int *d,void (*pf)(void *in,void *out,int *len,int *data_type));
#endif

static inline void user_fct_ptr_conv_a2r(void **fa,void **fr)
{
  // User_fct_g_ptr=*fct;
  // *fct_tmp=(void*)wrapper_user_func;
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
      //fprintf(stderr,"gcc -shared -fPIC -I$WI4MPI_INTERNAL_INCLUDES -I$WI4MPI_APP_INCLUDES $WI4MPI_COMPILE_OPT -o %s %s",soname,fname);
      FILE *ff=fopen(fname,"w");
      fprintf(ff,
      "#include \"wrapper_f.h\"\n void wrapped_%p(void *in,void *out,int *len,int *data_type){ int ndata_type;datatype_r2a(&ndata_type,data_type); ((void (*)(int *n,int *,int *,int *))%p)(in,out,len,&ndata_type);}"
      ,*fa,*fa);
      
      fclose(ff);
      system(command);
    }
    sprintf(func_name,"wrapped_%p",*fa);
    if(!(fh=dlopen(soname,RTLD_LOCAL|RTLD_NOW)))
    {
        printf("%s\n",dlerror());
    }
    *fr=dlsym(fh,func_name);

    
#elif !defined(_WI4MPI_GCC_JIT)
    
    void* ptr = mmap(0, 1024,
                   PROT_READ | PROT_WRITE | PROT_EXEC,
                   MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    memcpy(((char *)ptr+0x10),user_fn_wrapper_template_fort,0x100);

    ((void **)ptr)[0]=*fa;
    
    ((void **)ptr)[1]=user_func_resolved_fort;
    *fr=ptr+0x10;
#endif
}

#if defined(OMPI_OMPI) || defined(OMPI_MPC) || defined(_OMPI) || defined(_MPC)
#define A_f_MPI_MODE_NOCHECK     1
#define A_f_MPI_MODE_NOPRECEDE   2
#define A_f_MPI_MODE_NOPUT       4
#define A_f_MPI_MODE_NOSTORE     8
#define A_f_MPI_MODE_NOSUCCEED   16
#define R_f_MPI_MODE_NOCHECK     1
#define R_f_MPI_MODE_NOPRECEDE   2
#define R_f_MPI_MODE_NOPUT       4
#define R_f_MPI_MODE_NOSTORE     8
#define R_f_MPI_MODE_NOSUCCEED   16

#elif defined(OMPI_INTEL) || defined(MPC_INTEL) || defined(_INTEL)
#define A_f_MPI_MODE_NOCHECK     1
#define A_f_MPI_MODE_NOPRECEDE   2
#define A_f_MPI_MODE_NOPUT       4
#define A_f_MPI_MODE_NOSTORE     8
#define A_f_MPI_MODE_NOSUCCEED   16
#define R_f_MPI_MODE_NOCHECK     1024
#define R_f_MPI_MODE_NOPRECEDE   2048
#define R_f_MPI_MODE_NOPUT       4096
#define R_f_MPI_MODE_NOSTORE     8192
#define R_f_MPI_MODE_NOSUCCEED   16384

#elif INTEL_INTEL
#define A_f_MPI_MODE_NOCHECK     1024
#define A_f_MPI_MODE_NOPRECEDE   2048
#define A_f_MPI_MODE_NOPUT       4096
#define A_f_MPI_MODE_NOSTORE     8192
#define A_f_MPI_MODE_NOSUCCEED   16384
#define R_f_MPI_MODE_NOCHECK     1024
#define R_f_MPI_MODE_NOPRECEDE   2048
#define R_f_MPI_MODE_NOPUT       4096
#define R_f_MPI_MODE_NOSTORE     8192
#define R_f_MPI_MODE_NOSUCCEED   16384

#elif defined(INTEL_OMPI) || defined(INTEL_MPC)
#define A_f_MPI_MODE_NOCHECK     1024
#define A_f_MPI_MODE_NOPRECEDE   2048
#define A_f_MPI_MODE_NOPUT       4096
#define A_f_MPI_MODE_NOSTORE     8192
#define A_f_MPI_MODE_NOSUCCEED   16384
#define R_f_MPI_MODE_NOCHECK     1
#define R_f_MPI_MODE_NOPRECEDE   2
#define R_f_MPI_MODE_NOPUT       4
#define R_f_MPI_MODE_NOSTORE     8
#define R_f_MPI_MODE_NOSUCCEED   16
#endif

static inline void win_assert_mode_a2r(int *assert, int *assert_tmp)
{
   if(*assert & A_f_MPI_MODE_NOCHECK  )
     *assert_tmp |= R_f_MPI_MODE_NOCHECK; 
   if(*assert & A_f_MPI_MODE_NOPRECEDE)
     *assert_tmp |= R_f_MPI_MODE_NOPRECEDE ;
   if(*assert & A_f_MPI_MODE_NOPUT    )
     *assert_tmp |= R_f_MPI_MODE_NOPUT ;
   if(*assert & A_f_MPI_MODE_NOSTORE  )
     *assert_tmp |= R_f_MPI_MODE_NOSTORE;
   if(*assert & A_f_MPI_MODE_NOSUCCEED)
     *assert_tmp |= R_f_MPI_MODE_NOSUCCEED ;
   if(*assert == 0)
      *assert_tmp =0;
}

static inline void win_assert_mode_r2a(int *assert, int *assert_tmp)
{
  if(*assert_tmp & R_f_MPI_MODE_NOCHECK  )
     *assert |=  A_f_MPI_MODE_NOCHECK; 
   if(*assert_tmp & R_f_MPI_MODE_NOPRECEDE)
     *assert |= A_f_MPI_MODE_NOPRECEDE ;
   if(*assert_tmp & R_f_MPI_MODE_NOPUT    )
     *assert |= A_f_MPI_MODE_NOPUT ;
   if(*assert_tmp & R_f_MPI_MODE_NOSTORE  )
     *assert |= A_f_MPI_MODE_NOSTORE; 
   if(*assert_tmp & R_f_MPI_MODE_NOSUCCEED)
     *assert |= A_f_MPI_MODE_NOSUCCEED ;
   if(*assert ==0)
      *assert = 0;
}

static inline void weight_a2r(int **buf,int **buf_tmp)
{
  if((int*) *buf == A_f_MPI_UNWEIGHTED)
      *buf_tmp= (void *)R_f_MPI_UNWEIGHTED;
            
  else if((int*) *buf == A_f_MPI_WEIGHTS_EMPTY )
      *buf_tmp= (void *)R_f_MPI_WEIGHTS_EMPTY;  
  else 
     //memcpy(buf_tmp, buf, sizeof(void*));
     *buf_tmp=*buf;
}
static inline void weight_r2a(int **buf,int **buf_tmp)
{
  if((int *) *buf_tmp ==  R_f_MPI_UNWEIGHTED)
    *buf=  (void *) A_f_MPI_UNWEIGHTED;
  
  else if((int *) *buf_tmp == R_f_MPI_WEIGHTS_EMPTY )
    *buf=  (void *) A_f_MPI_WEIGHTS_EMPTY;
  
  else 
     //memcpy(buf_tmp, buf, sizeof);
     *buf=*buf_tmp;
}

// As soon openmpi fix this bug, the number will be replaced by the constants
static inline void win_flavor_a2r(int *attr, int *attr_tmp)
{
switch (*attr)
   {
      /* keyval MPI_WIN_CREATE_FLAVOR */
      case 1 : 
         *attr_tmp = 1; 
      case 2 :
         *attr_tmp = 2; 
      case 3 :
         *attr_tmp = 3; 
      case 4 :
         *attr_tmp = 4;
      
      default: /* in case this is an user's attribute or a non constant var (need to check the behavior)*/
         *attr_tmp = *attr;
   }
}
// As soon openmpi fix this bug, the number will be replaced by the constants
static inline void win_flavor_r2a(int *attr, int *attr_tmp)
{
switch (*attr_tmp)
   {
      /* keyval MPI_WIN_CREATE_FLAVOR */
      case 1 : 
         *attr = 1; 
      case 2 :
         *attr = 2; 
      case 3 :
         *attr = 3; 
      case 4 :
         *attr = 4;
      
      default: /* in case this is an user's attribute or a non constant var (need to check the behavior)*/
         *attr = *attr_tmp;
   }
}


#endif /*MANUAL_WRAPPER_H*/

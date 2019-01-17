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
//#   - Delforge Tony <tony.delforge.tgccAcea.fr>                        #
//#   - Ducrot Vincent <vincent.ducrot.tgccAcea.fr>                      #
//#   - Cotte Adrien <adrien.cotte.tgccAcea.fr>                          #
//#                                                                      #
//########################################################################




#ifndef MANUAL_WRAPPER_H
#define MANUAL_WRAPPER_H

#include "wrapper_f.h"

extern __thread int in_w;

#define IFORT_CALL
void status_a2r(int *ca,int *cr){
    source_a2r(&ca[A_f_MPI_SOURCE-1],&cr[R_f_MPI_SOURCE-1]);
    cr[R_f_MPI_TAG-1]=ca[A_f_MPI_TAG-1];
    error_a2r(&ca[R_f_MPI_ERROR-1],&cr[A_f_MPI_ERROR-1]);
#ifdef mpich_mpich 
    cr[0]=ca[0];
    cr[1]=ca[1];
    
#endif
#ifdef ompi_ompi
    cr[3]=ca[3];
    cr[4]=ca[4];
    cr[5]=ca[5];
#endif
#ifdef ompi_mpich
    cr[0]=(ca[3]<<1)+ca[5];
    cr[1]=ca[4];
    
#endif
#ifdef mpich_ompi 
    cr[3]=(ca[0]>>1);
    cr[4]=ca[1];
    cr[5]=(ca[0]&1);
#endif
}
void status_r2a(int *ca,int *cr){
    source_r2a(&ca[A_f_MPI_SOURCE-1],&cr[R_f_MPI_SOURCE-1]);
//    printf("%d %d %d %d %d %d\n",cr[0],cr[1],cr[2],cr[3],cr[4],cr[5]);    
    //ca[A_MPI_SOURCE-1]=cr[R_MPI_SOURCE-1];
    ca[A_f_MPI_TAG-1]=   cr[R_f_MPI_TAG-1];
    error_r2a(&ca[A_f_MPI_ERROR-1],&cr[R_f_MPI_ERROR-1]);
//    printf("%d %d %d %d %d\n",ca[0],ca[1],ca[2],ca[3],ca[4]);    
#ifdef mpich_mpich 
    ca[0]=cr[0];
    ca[1]=cr[1];
    
#endif
#ifdef ompi_ompi
    ca[3]=cr[3];
    ca[4]=cr[4];
    ca[5]=cr[5];
#endif
#ifdef mpich_ompi 
    ca[1]=cr[4];
    ca[0]=(cr[3]<<1)+cr[5];
#endif
#ifdef ompi_mpich
    ca[3]=(cr[0]>>1);
    ca[4]=cr[1];
    ca[5]=(cr[0]&1);
#endif
    //printf("%d %d %d %d %d\n",ca[0],ca[1],ca[2],ca[3],ca[4]);    
}
void buffer_a2r(void **ca,void **cr)
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
void buffer_r2a(void **ca,void **cr)
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
void wrapper_user_func(void *iv,void *iov,int *len,int *dat)
{
    int dat_tmp;
    datatype_r2a(&dat_tmp,dat);
    //printf("datatype %d %d\n",*dat,dat_tmp);
    ((void (*)(int *n,int *,int *,int *))User_fct_g_ptr)(iv,iov,len,&dat_tmp);
}
void err_handler_wrap_func(int *comm,int *ier,...)
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
void handler_fct_ptr_conv_a2r(void **fct,void **fct_tmp)
{
    *fct_tmp=err_handler_wrap_func;
}
void copy_ptr_converter_a2r(void **fct,void **fct_tmp)
{
    
           *fct_tmp=*fct;
}
void errhandler_set_func(int comm,int errhandler)
{
    void *func;
 if(errhandler!=R_f_MPI_ERRORS_ARE_FATAL &&errhandler!=R_f_MPI_ERRORS_RETURN &&errhandler!=R_f_MPI_ERRHANDLER_NULL)
 {      errhandler_f_fn_translation_get(errhandler,&func);
        //printf("%d\n%p %d\n",errhandler,func,comm);
       communicator_f_fn_translation_update(comm,func);
}
}
void user_fct_ptr_conv_a2r(void **fct,void **fct_tmp)
{
   User_fct_g_ptr=*fct;
   *fct_tmp=(void*)wrapper_user_func;
}
#include "engine.h"
void  mpi_get_processor_name_(char *,int *,int *,int);

void  mpi_get_processor_name__(char *,int *,int *,int);

void  pmpi_get_processor_name_(char *,int *,int *,int);

void  pmpi_get_processor_name__(char *,int *,int *,int);

void  pmpi_get_processor_name_(char *,int *,int *,int);

#define A_f_MPI_Get_processor_name _PMPI_Get_processor_name
#pragma weak mpi_get_processor_name_=_PMPI_Get_processor_name
#pragma weak mpi_get_processor_name__=_PMPI_Get_processor_name
#pragma weak pmpi_get_processor_name__=_PMPI_Get_processor_name
void  (*_LOCAL_MPI_Get_processor_name)(char *,int *,int *i,int);
#ifdef IFORT_CALL
void (*_LOCAL_MPI_Get_processor_name)(char *,int *,int *i,int);
#elif GFORT_CALL
void (*_LOCAL_MPI_Get_processor_name)(char *,int,int *,int *i);
#endif

#ifdef ompi_mpich
#define R_f_MPI_MAX_PROCESSOR_NAME 127
#define A_f_MPI_MAX_PROCESSOR_NAME 255
#endif

#ifdef mpich_mpich
#define R_f_MPI_MAX_PROCESSOR_NAME 127
#define A_f_MPI_MAX_PROCESSOR_NAME 127
#endif
#ifdef ompi_ompi
#define R_f_MPI_MAX_PROCESSOR_NAME 255
#define A_f_MPI_MAX_PROCESSOR_NAME 255
#endif
#ifdef mpich_ompi
#define R_f_MPI_MAX_PROCESSOR_NAME 255
#define A_f_MPI_MAX_PROCESSOR_NAME 127
#endif
#ifdef IFORT_CALL
void  A_f_MPI_Get_processor_name(char * name,int * resultlen,int * ret,int namelen)
#elif GFORT_CALL
void  A_f_MPI_Get_processor_name(char * name,int namelen,int * resultlen,int * ret)
#endif
{
#ifdef DEBUG
printf("entre : A_f_MPI_Get_processor_name\n");
#endif
in_w=1;

int  ret_tmp=0;
char tmp_name[R_f_MPI_MAX_PROCESSOR_NAME+2];
//printf("MPI_Get_processor_name\n");
#ifdef IFORT_CALL
_LOCAL_MPI_Get_processor_name(tmp_name,resultlen,&ret_tmp,R_f_MPI_MAX_PROCESSOR_NAME);
#elif GFORT_CALL
_LOCAL_MPI_Get_processor_name(tmp_name,R_f_MPI_MAX_PROCESSOR_NAME,resultlen,&ret_tmp);
#endif
//printf("before conv MPI_Get_processor_name %d %d\n",*ret,ret_tmp);
tmp_name[*resultlen]='\0';
strncpy(name,tmp_name,R_f_MPI_MAX_PROCESSOR_NAME);
error_r2a(ret,&ret_tmp);

//printf("end MPI_Get_processor_name %d %d\n",*ret,ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Get_processor_name\n");
#endif

}
void  mpi_error_string_(int *,char *,int *,int *);

void  mpi_error_string__(int *,char *,int *,int *);

void  pmpi_error_string_(int *,char *,int *,int *);

void  pmpi_error_string__(int *,char *,int *,int *);

void  pmpi_error_string_(int *,char *,int *,int *);
#ifdef ompi_mpich
#define R_f_MPI_MAX_ERROR_STRING 511
#define A_f_MPI_MAX_ERROR_STRING 255
#endif

#ifdef mpich_mpich
#define R_f_MPI_MAX_ERROR_STRING 511
#define A_f_MPI_MAX_ERROR_STRING 511
#endif
#ifdef ompi_ompi
#define R_f_MPI_MAX_ERROR_STRING 255
#define A_f_MPI_MAX_ERROR_STRING 255
#endif
#ifdef mpich_ompi
#define R_f_MPI_MAX_ERROR_STRING 255
#define A_f_MPI_MAX_ERROR_STRING 511
#endif
#define A_f_MPI_Error_string _PMPI_Error_string
#pragma weak mpi_error_string_=_PMPI_Error_string
#pragma weak mpi_error_string__=_PMPI_Error_string
#pragma weak pmpi_error_string__=_PMPI_Error_string
#ifdef IFORT_CALL
void  (*_LOCAL_MPI_Error_string)(int * errorcode,char * string,int * resultlen,int * ret,int reslen);
#elif GFORT_CALL
void  (*_LOCAL_MPI_Error_string)(int * errorcode,int reslen,char * string,int * resultlen,int * ret);
#endif
//void  (*local_error_string_)(int *,char *,int,int *,int *);
//void  (local_mpi_error_string_)(int *i,char *j,int n,int *k,int *l)
//{
//    printf("error_str_int\n");
//    _LOCAL_MPI_Error_string(i,j,n,k,l);
//    printf("error_str_out\n");
//}
//void  f_mpi_error_string_(int *,char *,int,int *,int *);

#ifdef IFORT_CALL
void  A_f_MPI_Error_string(int * errorcode,char * string,int * resultlen,int * ret,int reslen)
#elif GFORT_CALL
void  A_f_MPI_Error_string(int * errorcode,int reslen,char * string,int * resultlen,int * ret)
#endif
{
#ifdef DEBUG
printf("entre : A_f_MPI_Error_string\n");
#endif
in_w=1;

int errorcode_tmp=*errorcode;
int  ret_tmp=0;
char string_tmp[R_MPI_MAX_ERROR_STRING+2];
//error_a2r(errorcode,&errorcode_tmp);
//printf("coucou\n");
#ifdef IFORT_CALL
    _LOCAL_MPI_Error_string(&errorcode_tmp,string_tmp,resultlen,&ret_tmp,R_f_MPI_MAX_ERROR_STRING);
#elif GFORT_CALL
    _LOCAL_MPI_Error_string(&errorcode_tmp,R_MPI_MAX_ERROR_STRING,string_tmp,resultlen,&ret_tmp);
#endif
//    f_mpi_error_string_(errorcode,string,resultlen,ret);
string_tmp[*resultlen]='\0';
strncpy(string,string_tmp,A_MPI_MAX_ERROR_STRING);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Error_string\n");
#endif

/*int mlen=R_MPI_MAX_ERROR_STRING+1;
printf("MPI_Error_string\n");
int errorcode_tmp;
//char string_tmp[R_MPI_MAX_ERROR_STRING+1];
error_a2r(errorcode,&errorcode_tmp);
printf("after alloc",*ret,ret_tmp);
// _LOCAL_MPI_Error_string( &errorcode_tmp, gstr_tmp, resultlen, &ret_tmp);
printf("before conv MPI_Error_string %d %d\n",*ret,ret_tmp);
error_r2a(ret,&ret_tmp);
mlen=(R_MPI_MAX_ERROR_STRING>A_MPI_MAX_ERROR_STRING?A_MPI_MAX_ERROR_STRING:R_MPI_MAX_ERROR_STRING);
//str_r2a_(string,&mlen,gstr_tmp);
//string_tmp[255]='\0';
//strcpy(string,string_tmp);
printf("end MPI_Error_string %d %d\n",*ret,ret_tmp);
*/}

void  mpi_file_open_(int*, char *,int *,int *,int*,int);

void  mpi_file_open__(int*, char *,int *,int *,int*,int);

void  pmpi_file_open_(int*, char *,int *,int *,int*,int);

void  pmpi_file_open__(int*, char *,int *,int *,int*,int);

void  pmpi_file_open_(int*, char *,int *,int *,int*,int);

#define A_f_MPI_File_open _PMPI_File_open
#pragma weak mpi_file_open_=_PMPI_File_open
#pragma weak mpi_file_open__=_PMPI_File_open
#pragma weak pmpi_file_open__=_PMPI_File_open
void  (*_LOCAL_MPI_File_open)(int *, char*, int*, int*, int*, int*,int);
#ifdef IFORT_CALL
void (*_LOCAL_MPI_File_open)(int *, char*, int*, int*, int*,int*, int);
#elif GFORT_CALL
void (*_LOCAL_MPI_File_open)(int *, char*, int, int*, int*,int*, int*);
#endif
#ifdef IFORT_CALL
A_f_MPI_File_open(int* comm, char *filename, int* amode,int* info, int *fh,int *ret, int filenamelen)
#elif GFORT_CALL
A_f_MPI_File_open(int* comm, char *filename, int filenamelen, int* amode,int* info, int *fh,int* ret)
#endif
{
#ifdef DEBUG
printf("entre : A_f_MPI_File_open\n");
#endif
in_w=1;

//printf("entre: MPI_File_open\n");
int comm_tmp;
int info_tmp=0;
int ret_tmp=0;
comm_a2r(comm,&comm_tmp);
//printf("apres comm_a2r\n");
info_a2r(info,&info_tmp);
//printf("Avant appel comm %d_%d | info %d_%d | filename %s\n",*comm,comm_tmp,*info,info_tmp,filename);
#ifdef IFORT_CALL
_LOCAL_MPI_File_open(&comm_tmp, filename, amode, &info_tmp, fh, &ret_tmp, filenamelen);
#elif GFORT_CALL
_LOCAL_MPI_File_open(&comm_tmp, filename, filenamelen, amode, &info_tmp, &ret_tmp, fh);
#endif
error_r2a(ret,&ret_tmp);
//printf("sort: MPI_File_open\n");
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_File_open\n");
#endif

}

void  mpi_file_set_view_(int *,int*,int *,int *,char **,int *,int *);

void  mpi_file_set_view__(int *,int*,int *,int *,char **,int *,int *);

void  pmpi_file_set_view_(int *,int*,int *,int *,char **,int *,int *);

void  pmpi_file_set_view__(int *,int*,int *,int *,char **,int *,int *);

void  pmpi_file_set_view_(int *,int*,int *,int *,char **,int *,int *);

#define A_f_MPI_File_set_view _PMPI_File_set_view
#pragma weak mpi_file_set_view_=_PMPI_File_set_view
#pragma weak mpi_file_set_view__=_PMPI_File_set_view
#pragma weak pmpi_file_set_view__=_PMPI_File_set_view
void  (*_LOCAL_MPI_File_set_view)(int *,int*,int *,int *,char *,int *,int *,int);
#ifdef IFORT_CALL
void  (*_LOCAL_MPI_File_set_view)(int *,int*,int *,int *,char *,int *,int *,int);
#elif GFORT_CALL
void  (*_LOCAL_MPI_File_set_view)(int *,int*,int *,int *,char *,int,int *,int *);
#endif

#ifdef IFORT_CALL
void  A_f_MPI_File_set_view(int * fh,int* disp,int * etype,int * filetype,char *datarep,int * info,int * ret,int datareplen)
#elif GFORT_CALL
void  A_f_MPI_File_set_view(int * fh,int* disp,int * etype,int * filetype,char *datarep,int datareplen, int * info,int * ret)
#endif
{
#ifdef DEBUG
printf("entre : A_f_MPI_File_set_view\n");
#endif
in_w=1;

int  ret_tmp=0;

int etype_tmp;
int filetype_tmp;
int info_tmp;
datatype_a2r(etype,&etype_tmp);
datatype_a2r(filetype,&filetype_tmp);
info_a2r(info,&info_tmp);
#ifdef IFORT_CALL
 _LOCAL_MPI_File_set_view( fh, disp, &etype_tmp, &filetype_tmp, datarep, &info_tmp, &ret_tmp, datareplen);
#elif GFORT_CALL
 _LOCAL_MPI_File_set_view( fh, disp, &etype_tmp, &filetype_tmp, datarep, datareplen,&info_tmp, &ret_tmp);
#endif
 error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_File_set_view\n");
#endif

}

void  mpi_file_get_view_(int *,int*,int *,int *,char *,int*,int);

void  mpi_file_get_view__(int *,int*,int *,int *,char*,int*,int);

void  pmpi_file_get_view_(int *,int*,int *,int *,char *,int*,int );

void  pmpi_file_get_view__(int *,int*,int *,int *,char *,int*,int );

void  pmpi_file_get_view_(int *,int*,int *,int *,char *,int*,int );

#define A_f_MPI_File_get_view _PMPI_File_get_view
#pragma weak mpi_file_get_view_=_PMPI_File_get_view
#pragma weak mpi_file_get_view__=_PMPI_File_get_view
#pragma weak pmpi_file_get_view__=_PMPI_File_get_view
void  (*_LOCAL_MPI_File_get_view)(int *,int*,int *,int *,char *,int*,int );
#ifdef IFORT_CALL
void  (*_LOCAL_MPI_File_get_view)(int *,int*,int *,int *,char *,int*,int );
#elif GFORT_CALL
void  (*_LOCAL_MPI_File_get_view)(int *,int*,int *,int *,char *,int, int* );
#endif

#ifdef IFORT_CALL
void  A_f_MPI_File_get_view(int * fh,int* disp,int * etype,int * filetype,char *datarep,int * ret,int datareplen)
#elif GFORT_CALL
void  A_f_MPI_File_get_view(int * fh,int* disp,int * etype,int * filetype,char *datarep,int datareplen,int * ret)
#endif
{
#ifdef DEBUG
printf("entre : A_f_MPI_File_get_view\n");
#endif
in_w=1;

int  ret_tmp=0;

int etype_tmp;
int filetype_tmp;
datatype_a2r(etype,&etype_tmp);
datatype_a2r(filetype,&filetype_tmp);
#ifdef IFORT_CALL
 _LOCAL_MPI_File_get_view( fh, disp, &etype_tmp, &filetype_tmp, datarep, &ret_tmp, datareplen);
#elif GFORT_CALL
 _LOCAL_MPI_File_get_view( fh, disp, &etype_tmp, &filetype_tmp, datarep, datareplen, &ret_tmp);
#endif
 error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_File_get_view\n");
#endif

}

void  mpi_file_delete_(char *,int *,int *);

void  mpi_file_delete__(char *,int *,int *);

void  pmpi_file_delete_(char *,int *,int *);

void  pmpi_file_delete__(char*,int *,int *);

void  pmpi_file_delete_(char *,int *,int *);

#define A_f_MPI_File_delete _PMPI_File_delete
#pragma weak mpi_file_delete_=_PMPI_File_delete
#pragma weak mpi_file_delete__=_PMPI_File_delete
#pragma weak pmpi_file_delete__=_PMPI_File_delete
void  (*_LOCAL_MPI_File_delete)(char *,int *,int *,int);
#ifdef IFORT_CALL
void  (*_LOCAL_MPI_File_delete)(char *,int *,int *,int);
#elif GFORT_CALL
void  (*_LOCAL_MPI_File_delete)(char *,int,int *,int *);
#endif
#ifdef IFORT_CALL
void  A_f_MPI_File_delete(char * filename,int * info,int * ret,int filenamelen)
#elif GFORT_CALL
void  A_f_MPI_File_delete(char * filename,int filenamelen,int * info,int * ret)
#elif GFORT_CALL
#endif
{
#ifdef DEBUG
printf("entre : A_f_MPI_File_delete\n");
#endif
in_w=1;

int  ret_tmp=0;

int info_tmp;
info_a2r(info,&info_tmp);
#ifdef IFORT_CALL
 _LOCAL_MPI_File_delete( filename, &info_tmp, &ret_tmp, filenamelen);
#elif GFORT_CALL
 _LOCAL_MPI_File_delete( filename, &info_tmp,filenamelen, &ret_tmp);
#endif
 error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_File_delete\n");
#endif

}

void  mpi_info_delete_(int *,char *,int *);

void  mpi_info_delete__(int *,char *,int *);

void  pmpi_info_delete_(int *,char *,int *);

void  pmpi_info_delete__(int *,char *,int *);

void  pmpi_info_delete_(int *,char *,int *);

#define A_f_MPI_Info_delete _PMPI_Info_delete
#pragma weak mpi_info_delete_=_PMPI_Info_delete
#pragma weak mpi_info_delete__=_PMPI_Info_delete
#pragma weak pmpi_info_delete__=_PMPI_Info_delete
void  (*_LOCAL_MPI_Info_delete)(int *,char *,int *,int);
#ifdef IFORT_CALL
void  (*_LOCAL_MPI_Info_delete)(int *,char *,int *,int);
#elif GFORT_CALL
void  (*_LOCAL_MPI_Info_delete)(int *,char *,int,int *);
#endif
#ifdef IFORT_CALL
void  A_f_MPI_Info_delete(int * info,char * key,int * ret,int keylen)
#elif GFORT_CALL
void  A_f_MPI_Info_delete(int * info,char * key,int keylen,int * ret)
#endif
{
#ifdef DEBUG
printf("entre : A_f_MPI_Info_delete\n");
#endif
in_w=1;

int  ret_tmp=0;

int info_tmp;
info_a2r(info,&info_tmp);
#ifdef IFORT_CALL
 _LOCAL_MPI_Info_delete( &info_tmp, key, &ret_tmp,keylen);
#elif GFORT_CALL
 _LOCAL_MPI_Info_delete( &info_tmp, key, keylen, &ret_tmp);
#endif
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Info_delete\n");
#endif

}

void  mpi_info_get_(int *,char *,int *,char *,int *,int *);

void  mpi_info_get__(int *,char *,int *,char *,int *,int *);

void  pmpi_info_get_(int *,char *,int *,char *,int *,int *);

void  pmpi_info_get__(int *,char *,int *,char *,int *,int *);

void  pmpi_info_get_(int *,char *,int *,char *,int *,int *);

#define A_f_MPI_Info_get _PMPI_Info_get
#pragma weak mpi_info_get_=_PMPI_Info_get
#pragma weak mpi_info_get__=_PMPI_Info_get
#pragma weak pmpi_info_get__=_PMPI_Info_get
void  (*_LOCAL_MPI_Info_get)(int *,char *,int *,char *,int *,int *,int,int);
#ifdef IFORT_CALL
void  (*_LOCAL_MPI_Info_get)(int *,char *,int *,char *,int *,int *,int,int);
#elif GFORT_CALL
void  (*_LOCAL_MPI_Info_get)(int *,char *,int ,int *,char *,int,int *,int *);
#endif

#ifdef IFORT_CALL
void  A_f_MPI_Info_get(int * info,char * key,int * valuelen,char * value,int * flag,int * ret, int keylen, int valuelen_)
#elif GFORT_CALL
void  A_f_MPI_Info_get(int * info,char * key, int keylen,int * valuelen,char * value, int valuelen_, int * flag,int * ret)
#endif
{
#ifdef DEBUG
printf("entre : A_f_MPI_Info_get\n");
#endif
in_w=1;

int  ret_tmp=0;

int info_tmp;
info_a2r(info,&info_tmp);
#ifdef IFORT_CALL
 _LOCAL_MPI_Info_get( &info_tmp, key, valuelen, value, flag, &ret_tmp, keylen, valuelen_);
#elif GFORT_CALL
 _LOCAL_MPI_Info_get( &info_tmp, key, keylen,valuelen, value, valuelen_, flag, &ret_tmp);
#endif
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Info_get\n");
#endif

}

void  mpi_info_get_nthkey_(int *,int *,char *,int *);

void  mpi_info_get_nthkey__(int *,int *,char *,int *);

void  pmpi_info_get_nthkey_(int *,int *,char *,int *);

void  pmpi_info_get_nthkey__(int *,int *,char *,int *);

void  pmpi_info_get_nthkey_(int *,int *,char *,int *);

#define A_f_MPI_Info_get_nthkey _PMPI_Info_get_nthkey
#pragma weak mpi_info_get_nthkey_=_PMPI_Info_get_nthkey
#pragma weak mpi_info_get_nthkey__=_PMPI_Info_get_nthkey
#pragma weak pmpi_info_get_nthkey__=_PMPI_Info_get_nthkey
void  (*_LOCAL_MPI_Info_get_nthkey)(int *,int *,char *,int *,int);
#ifdef IFORT_CALL
void  (*_LOCAL_MPI_Info_get_nthkey)(int *,int *,char *,int *,int);
#elif GFORT_CALL
void  (*_LOCAL_MPI_Info_get_nthkey)(int *,int *,char *,int,int *);
#endif
#ifdef IFORT_CALL
void  A_f_MPI_Info_get_nthkey(int * info,int * n,char * key,int * ret,int keylen)
#elif GFORT_CALL
void  A_f_MPI_Info_get_nthkey(int * info,int * n,char * key,int keylen,int * ret)
#endif
{
#ifdef DEBUG
printf("entre : A_f_MPI_Info_get_nthkey\n");
#endif
in_w=1;


int  ret_tmp=0;

int info_tmp;
info_a2r(info,&info_tmp);
#ifdef IFORT_CALL
 _LOCAL_MPI_Info_get_nthkey( &info_tmp, n, key, &ret_tmp,keylen);
#elif GFORT_CALL
 _LOCAL_MPI_Info_get_nthkey( &info_tmp, n, key, keylen, &ret_tmp);
#endif
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Info_get_nthkey\n");
#endif

}


void  mpi_info_get_valuelen_(int *,char *,int *,int *,int *);

void  mpi_info_get_valuelen__(int *,char *,int *,int *,int *);

void  pmpi_info_get_valuelen_(int *,char *,int *,int *,int *);

void  pmpi_info_get_valuelen__(int *,char *,int *,int *,int *);

void  pmpi_info_get_valuelen_(int *,char *,int *,int *,int *);

#define A_f_MPI_Info_get_valuelen _PMPI_Info_get_valuelen
#pragma weak mpi_info_get_valuelen_=_PMPI_Info_get_valuelen
#pragma weak mpi_info_get_valuelen__=_PMPI_Info_get_valuelen
#pragma weak pmpi_info_get_valuelen__=_PMPI_Info_get_valuelen
void  (*_LOCAL_MPI_Info_get_valuelen)(int *,char *,int *,int *,int *,int);
#ifdef IFORT_CALL
void  (*_LOCAL_MPI_Info_get_valuelen)(int *,char *,int *,int *,int *,int);
#elif GFORT_CALL
void  (*_LOCAL_MPI_Info_get_valuelen)(int *,char *,int,int *,int *,int *);
#endif

#ifdef IFORT_CALL
void  A_f_MPI_Info_get_valuelen(int * info,char * key,int * valuelen,int * flag,int * ret,int keylen)
#elif GFORT_CALL
void  A_f_MPI_Info_get_valuelen(int * info,char * key,int keylen,int * valuelen,int * flag,int * ret)
#endif
{
#ifdef DEBUG
printf("entre : A_f_MPI_Info_get_valuelen\n");
#endif
in_w=1;

int  ret_tmp=0;

int info_tmp;
info_a2r(info,&info_tmp);
#ifdef IFORT_CALL
 _LOCAL_MPI_Info_get_valuelen( &info_tmp, key, valuelen, flag, &ret_tmp, keylen);
#elif GFORT_CALL
 _LOCAL_MPI_Info_get_valuelen( &info_tmp, key, keylen, valuelen, flag, &ret_tmp);
#endif
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Info_get_valuelen\n");
#endif

}

void  mpi_info_set_(int *,char *,char *,int *);

void  mpi_info_set__(int *,char *,char*,int *);

void  pmpi_info_set_(int *,char *,char *,int *);

void  pmpi_info_set__(int *,char *,char *,int *);

void  pmpi_info_set_(int *,char *,char *,int *);

#define A_f_MPI_Info_set _PMPI_Info_set
#pragma weak mpi_info_set_=_PMPI_Info_set
#pragma weak mpi_info_set__=_PMPI_Info_set
#pragma weak pmpi_info_set__=_PMPI_Info_set
void  (*_LOCAL_MPI_Info_set)(int *,char *,char *,int *,int, int);
#ifdef IFORT_CALL
void  (*_LOCAL_MPI_Info_set)(int *,char *,char *,int *,int,int);
#elif GFORT_CALL
void  (*_LOCAL_MPI_Info_set)(int *,char *,int,char *,int,int *);
#endif
#ifdef IFORT_CALL
void  A_f_MPI_Info_set(int * info,char * key,char * value,int * ret,int keylen,int valuelen)
#elif GFORT_CALL
void  A_f_MPI_Info_set(int * info,char * key,int keylen,char * value,int valuelen,int * ret)
#endif
{
#ifdef DEBUG
printf("entre : A_f_MPI_Info_set\n");
#endif
in_w=1;

int  ret_tmp=0;

int info_tmp;
info_a2r(info,&info_tmp);
#ifdef IFORT_CALL
 _LOCAL_MPI_Info_set( &info_tmp, key, value, &ret_tmp, keylen, valuelen);
#elif GFORT_CALL
 _LOCAL_MPI_Info_set( &info_tmp, key, keylen, value, valuelen, &ret_tmp);
#endif
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Info_set\n");
#endif

}

#endif /*MANUAL_WRAPPER_H*/

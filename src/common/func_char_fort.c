//############################# Wi4MPI License ###########################
//# `04/04/2016`                                                         #
//# Copyright or (C) or Copr. Commissariat a l'Energie Atomique          #
//#                                                                      #
//# IDDN.FR.001.210022.000.S.P.2014.000.10800                            #
//# This file is part of the Wi4MPI library.                             #
//#                                                                      #
//# SPDX-License-Identifier: BSD-3-Clause OR CeCILL-B                    #
//#                                                                      #
//#                                                                      #
//# Authors:                                                             #
//#   - Delforge Tony <tony.delforge.tgcc@cea.fr>                        #
//#   - Ducrot Vincent <vincent.ducrot.tgcc@cea.fr>                      #
//#   - Juilly Kevin <kevin.juilly.tgcc@cea.fr>                          #
//#                                                                      #
//########################################################################

#include "manual_wrapper.h"
#include "engine.h"
#include "mappers.h"
#include "fort_common.h"
#include <stdbool.h>

static inline void fstring_max_conv_r2a(char *name, char *name_tmp, fort_string_length app_size, int resultlen) {
    if (resultlen < app_size) {
        strncpy(name, name_tmp, resultlen);
        memset(name+resultlen, ' ', app_size-resultlen);
    } else {
        strncpy(name, name_tmp, app_size);
    }
}

// spaces in keys and values for MPI_Info are ignored, but not in other strings.
// remove_leading allow to ignore leading spaces for key/value, in case the actual string fit in the runtime when ignoring leading spaces but not with them.
static inline void fstring_max_conv_a2r(char *name, char *name_tmp, fort_string_length app_size, fort_string_length run_size, bool remove_leading) {
    if (remove_leading) {
        int i=0;
        while (i < app_size && name[i] == ' ') i++;
        name+=i;
        app_size-=i;
    }
    if (run_size <= app_size) {
        strncpy(name_tmp, name, run_size);
    } else {
        strncpy(name_tmp, name, app_size);
        memset(name_tmp+app_size, ' ', run_size-app_size);
    }
}


void  mpi_get_processor_name_(char *,int *,int *,fort_string_length);

void  mpi_get_processor_name__(char *,int *,int *,fort_string_length);

void  pmpi_get_processor_name_(char *,int *,int *,fort_string_length);

void  pmpi_get_processor_name__(char *,int *,int *,fort_string_length);

#pragma weak mpi_get_processor_name_=A_f_MPI_Get_processor_name
#pragma weak mpi_get_processor_name__=A_f_MPI_Get_processor_name
#pragma weak pmpi_get_processor_name_=A_f_MPI_Get_processor_name
#pragma weak pmpi_get_processor_name__=A_f_MPI_Get_processor_name
void (*_LOCAL_MPI_Get_processor_name)(char *,int *,int *i,fort_string_length);

void  A_f_MPI_Get_processor_name(char * name,int * resultlen,int * ret,fort_string_length namelen)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Get_processor_name\n");
#endif
in_w=1;

int  ret_tmp=0;
char tmp_name[R_MPI_MAX_PROCESSOR_NAME-1];
int resultlen_tmp;

_LOCAL_MPI_Get_processor_name(tmp_name,&resultlen_tmp, &ret_tmp, R_MPI_MAX_PROCESSOR_NAME - 1);

fstring_max_conv_r2a(name, tmp_name, namelen, resultlen_tmp);
length_max_conv_r2a(resultlen, &resultlen_tmp, A_MPI_MAX_PROCESSOR_NAME, R_MPI_MAX_PROCESSOR_NAME);
error_r2a(ret,&ret_tmp);

in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Get_processor_name\n");
#endif

}
void  mpi_error_string_(int *,char *,int *,int *, fort_string_length);

void  mpi_error_string__(int *,char *,int *,int *, fort_string_length);

void  pmpi_error_string_(int *,char *,int *,int *, fort_string_length);

void  pmpi_error_string__(int *,char *,int *,int *, fort_string_length);

#pragma weak mpi_error_string_=A_f_MPI_Error_string
#pragma weak mpi_error_string__=A_f_MPI_Error_string
#pragma weak pmpi_error_string_=A_f_MPI_Error_string
#pragma weak pmpi_error_string__=A_f_MPI_Error_string
void  (*_LOCAL_MPI_Error_string)(int * errorcode,char * string,int * resultlen,int * ret,fort_string_length);

void  A_f_MPI_Error_string(int * errorcode,char * string,int * resultlen,int * ret,fort_string_length string_len)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Error_string\n");
#endif
in_w=1;

int errorcode_tmp=*errorcode;
int  ret_tmp=0;
char string_tmp[R_MPI_MAX_ERROR_STRING-1];
int resultlen_tmp;
error_a2r(errorcode,&errorcode_tmp);
    _LOCAL_MPI_Error_string(&errorcode_tmp,string_tmp,&resultlen_tmp,&ret_tmp,R_MPI_MAX_ERROR_STRING-1);

fstring_max_conv_r2a(string, string_tmp, string_len, resultlen_tmp);
length_max_conv_r2a(resultlen, &resultlen_tmp, A_MPI_MAX_ERROR_STRING, R_MPI_MAX_ERROR_STRING);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Error_string\n");
#endif
}

void  mpi_file_open_(int*, char *,int *,int *,int*, int *,fort_string_length);

void  mpi_file_open__(int*, char *,int *,int *,int*, int *,fort_string_length);

void  pmpi_file_open_(int*, char *,int *,int *,int*, int *,fort_string_length);

void  pmpi_file_open__(int*, char *,int *,int *,int*, int *,fort_string_length);

void  pmpi_file_open_(int*, char *,int *,int *,int*, int *,fort_string_length);

#pragma weak mpi_file_open_=A_f_MPI_File_open
#pragma weak mpi_file_open__=A_f_MPI_File_open
#pragma weak pmpi_file_open_=A_f_MPI_File_open
#pragma weak pmpi_file_open__=A_f_MPI_File_open
void (*_LOCAL_MPI_File_open)(int *, char*, int*, int*, int*,int*, fort_string_length);
void A_f_MPI_File_open(int* comm, char *filename, int* amode,int* info, int *fh,int *ret, fort_string_length filenamelen)
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
_LOCAL_MPI_File_open(&comm_tmp, filename, amode, &info_tmp, fh, &ret_tmp, filenamelen);
error_r2a(ret,&ret_tmp);
//printf("sort: MPI_File_open\n");
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_File_open\n");
#endif

}

void  mpi_file_set_view_(int *,int*,int *,int *,char **,int *,int *, fort_string_length);

void  mpi_file_set_view__(int *,int*,int *,int *,char **,int *,int *, fort_string_length);

void  pmpi_file_set_view_(int *,int*,int *,int *,char **,int *,int *, fort_string_length);

void  pmpi_file_set_view__(int *,int*,int *,int *,char **,int *,int *, fort_string_length);

#pragma weak mpi_file_set_view_=A_f_MPI_File_set_view
#pragma weak mpi_file_set_view__=A_f_MPI_File_set_view
#pragma weak pmpi_file_set_view_=A_f_MPI_File_set_view
#pragma weak pmpi_file_set_view__=A_f_MPI_File_set_view
void  (*_LOCAL_MPI_File_set_view)(int *,int*,int *,int *,char *,int *,int *,fort_string_length);

void  A_f_MPI_File_set_view(int * fh,int* disp,int * etype,int * filetype,char *datarep,int * info,int * ret,fort_string_length datareplen)
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
char tmp_name[R_MPI_MAX_DATAREP_STRING-1];
fstring_max_conv_a2r(datarep, tmp_name, datareplen, R_MPI_MAX_DATAREP_STRING-1, false);
 _LOCAL_MPI_File_set_view( fh, disp, &etype_tmp, &filetype_tmp, tmp_name, &info_tmp, &ret_tmp, R_MPI_MAX_DATAREP_STRING-1);
 error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_File_set_view\n");
#endif

}

void  mpi_file_get_view_(int *,int*,int *,int *,char *,int*,fort_string_length);

void  mpi_file_get_view__(int *,int*,int *,int *,char*,int*,fort_string_length);

void  pmpi_file_get_view_(int *,int*,int *,int *,char *,int*,fort_string_length );

void  pmpi_file_get_view__(int *,int*,int *,int *,char *,int*,fort_string_length );

#pragma weak mpi_file_get_view_=A_f_MPI_File_get_view
#pragma weak mpi_file_get_view__=A_f_MPI_File_get_view
#pragma weak pmpi_file_get_view_=A_f_MPI_File_get_view
#pragma weak pmpi_file_get_view__=A_f_MPI_File_get_view
void  (*_LOCAL_MPI_File_get_view)(int *,int*,int *,int *,char *,int*,fort_string_length );

void  A_f_MPI_File_get_view(int * fh,int* disp,int * etype,int * filetype,char *datarep,int * ret,fort_string_length datareplen)
{
#ifdef DEBUG
printf("entre : A_f_MPI_File_get_view\n");
#endif
in_w=1;

int  ret_tmp=0;

int etype_tmp;
int filetype_tmp;
char tmp_name[R_MPI_MAX_DATAREP_STRING-1];
 _LOCAL_MPI_File_get_view( fh, disp, &etype_tmp, &filetype_tmp, tmp_name, &ret_tmp, R_MPI_MAX_DATAREP_STRING-1);
datatype_r2a(etype,&etype_tmp);
datatype_r2a(filetype,&filetype_tmp);
 fstring_max_conv_r2a(datarep, tmp_name, datareplen, R_MPI_MAX_DATAREP_STRING-1);
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

//#define A_f_MPI_File_delete _PMPI_File_delete
//#pragma weak mpi_file_delete_=_PMPI_File_delete
//#pragma weak mpi_file_delete__=_PMPI_File_delete
//#pragma weak pmpi_file_delete__=_PMPI_File_delete
#if defined(IFORT_CALL) || defined(PGI_CALL) || defined(FLANG_CALL) || (defined(GFORT_CALL) && __GNUC__ < 8)
void  (*_LOCAL_MPI_File_delete)(char *,int *,int *,int);
#elif defined(GFORT_CALL) && __GNUC__ >= 8
void  (*_LOCAL_MPI_File_delete)(char *,int *,int *,size_t);
#endif
#if defined(IFORT_CALL) || defined(PGI_CALL) || defined(FLANG_CALL) || (defined(GFORT_CALL) && __GNUC__ < 8)
void  A_f_MPI_File_delete(char * filename,int * info,int * ret,int filenamelen)
#elif defined(GFORT_CALL) && __GNUC__ >= 8
void  A_f_MPI_File_delete(char * filename,int * info,int * ret,size_t filenamelen)
#elif defined(GFORT_CALL)
#endif
{
#ifdef DEBUG
printf("entre : A_f_MPI_File_delete\n");
#endif
in_w=1;

int  ret_tmp=0;

int info_tmp;
info_a2r(info,&info_tmp);
 _LOCAL_MPI_File_delete( filename, &info_tmp, &ret_tmp, filenamelen);
 error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_File_delete\n");
#endif

}

void  mpi_info_delete_(int *,char *,int *, fort_string_length);

void  mpi_info_delete__(int *,char *,int *, fort_string_length);

void  pmpi_info_delete_(int *,char *,int *, fort_string_length);

void  pmpi_info_delete__(int *,char *,int *, fort_string_length);

void  pmpi_info_delete_(int *,char *,int *, fort_string_length);

#pragma weak mpi_info_delete_=A_f_MPI_Info_delete
#pragma weak mpi_info_delete__=A_f_MPI_Info_delete
#pragma weak pmpi_info_delete_=A_f_MPI_Info_delete
#pragma weak pmpi_info_delete__=A_f_MPI_Info_delete
void  (*_LOCAL_MPI_Info_delete)(int *,char *,int *,fort_string_length);
void  A_f_MPI_Info_delete(int * info,char * key,int * ret,fort_string_length keylen)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Info_delete\n");
#endif
in_w=1;

int  ret_tmp=0;
char key_tmp[R_MPI_MAX_INFO_KEY-1];
fstring_max_conv_a2r(key, key_tmp, keylen, R_MPI_MAX_INFO_KEY-1, true);

int info_tmp;
info_a2r(info,&info_tmp);
 _LOCAL_MPI_Info_delete( &info_tmp, key_tmp, &ret_tmp,R_MPI_MAX_INFO_KEY-1);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Info_delete\n");
#endif

}

void  mpi_info_get_(int *,char *,int *,char *,int *,int *, fort_string_length, fort_string_length);

void  mpi_info_get__(int *,char *,int *,char *,int *,int *, fort_string_length, fort_string_length);

void  pmpi_info_get_(int *,char *,int *,char *,int *,int *, fort_string_length, fort_string_length);

void  pmpi_info_get__(int *,char *,int *,char *,int *,int *, fort_string_length, fort_string_length);

#pragma weak mpi_info_get_=A_f_MPI_Info_get
#pragma weak mpi_info_get__=A_f_MPI_Info_get
#pragma weak pmpi_info_get_=A_f_MPI_Info_get
#pragma weak pmpi_info_get__=A_f_MPI_Info_get
void  (*_LOCAL_MPI_Info_get)(int *,char *,int *,char *,int *,int *,fort_string_length,fort_string_length);

void  A_f_MPI_Info_get(int * info,char * key,int * valuelen,char * value,int * flag,int * ret, fort_string_length keylen, fort_string_length valuelen_)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Info_get\n");
#endif
in_w=1;

int  ret_tmp=0;

int info_tmp;
info_a2r(info,&info_tmp);
char key_tmp[R_MPI_MAX_INFO_KEY-1];
fstring_max_conv_a2r(key, key_tmp, keylen, R_MPI_MAX_INFO_KEY-1, true);

 _LOCAL_MPI_Info_get( &info_tmp, key_tmp, valuelen, value, flag, &ret_tmp, R_MPI_MAX_INFO_KEY-1, valuelen_);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Info_get\n");
#endif

}

void  mpi_info_get_nthkey_(int *,int *,char *,int *, fort_string_length);

void  mpi_info_get_nthkey__(int *,int *,char *,int *, fort_string_length);

void  pmpi_info_get_nthkey_(int *,int *,char *,int *, fort_string_length);

void  pmpi_info_get_nthkey__(int *,int *,char *,int *, fort_string_length);

#pragma weak mpi_info_get_nthkey_=A_f_MPI_Info_get_nthkey
#pragma weak mpi_info_get_nthkey__=A_f_MPI_Info_get_nthkey
#pragma weak pmpi_info_get_nthkey_=A_f_MPI_Info_get_nthkey
#pragma weak pmpi_info_get_nthkey__=A_f_MPI_Info_get_nthkey
void  (*_LOCAL_MPI_Info_get_nthkey)(int *,int *,char *,int *,fort_string_length);
void  A_f_MPI_Info_get_nthkey(int * info,int * n,char * key,int * ret,fort_string_length keylen)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Info_get_nthkey\n");
#endif
in_w=1;


int  ret_tmp=0;

int info_tmp;
char key_tmp[R_MPI_MAX_INFO_KEY-1];
info_a2r(info,&info_tmp);
 _LOCAL_MPI_Info_get_nthkey( &info_tmp, n, key_tmp, &ret_tmp,R_MPI_MAX_INFO_KEY-1);
 fstring_max_conv_r2a(key, key_tmp, keylen, R_MPI_MAX_INFO_KEY-1);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Info_get_nthkey\n");
#endif

}


void  mpi_info_get_valuelen_(int *,char *,int *,int *,int *, fort_string_length);

void  mpi_info_get_valuelen__(int *,char *,int *,int *,int *, fort_string_length);

void  pmpi_info_get_valuelen_(int *,char *,int *,int *,int *, fort_string_length);

void  pmpi_info_get_valuelen__(int *,char *,int *,int *,int *, fort_string_length);

#pragma weak mpi_info_get_valuelen_=A_f_MPI_Info_get_valuelen
#pragma weak mpi_info_get_valuelen__=A_f_MPI_Info_get_valuelen
#pragma weak pmpi_info_get_valuelen_=A_f_MPI_Info_get_valuelen
#pragma weak pmpi_info_get_valuelen__=A_f_MPI_Info_get_valuelen
void  (*_LOCAL_MPI_Info_get_valuelen)(int *,char *,int *,int *,int *,fort_string_length);

void  A_f_MPI_Info_get_valuelen(int * info,char * key,int * valuelen,int * flag,int * ret,fort_string_length keylen)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Info_get_valuelen\n");
#endif
in_w=1;

int  ret_tmp=0;

int info_tmp;
info_a2r(info,&info_tmp);
char key_tmp[R_MPI_MAX_INFO_KEY-1];
fstring_max_conv_a2r(key, key_tmp, keylen, R_MPI_MAX_INFO_KEY-1, true);
 _LOCAL_MPI_Info_get_valuelen( &info_tmp, key_tmp, valuelen, flag, &ret_tmp, R_MPI_MAX_INFO_KEY-1);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Info_get_valuelen\n");
#endif

}

void  mpi_info_set_(int *,char *,char *,int *, fort_string_length, fort_string_length);

void  mpi_info_set__(int *,char *,char*,int *, fort_string_length, fort_string_length);

void  pmpi_info_set_(int *,char *,char *,int *, fort_string_length, fort_string_length);

void  pmpi_info_set__(int *,char *,char *,int *, fort_string_length, fort_string_length);

#pragma weak mpi_info_set_=A_f_MPI_Info_set
#pragma weak mpi_info_set__=A_f_MPI_Info_set
#pragma weak pmpi_info_set_=A_f_MPI_Info_set
#pragma weak pmpi_info_set__=A_f_MPI_Info_set
void  (*_LOCAL_MPI_Info_set)(int *,char *,char *,int *,fort_string_length,fort_string_length);
void  A_f_MPI_Info_set(int * info,char * key,char * value,int * ret,fort_string_length keylen,fort_string_length valuelen)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Info_set\n");
#endif
in_w=1;

int  ret_tmp=0;
char key_tmp[R_MPI_MAX_INFO_KEY-1];
fstring_max_conv_a2r(key, key_tmp, keylen, R_MPI_MAX_INFO_KEY-1, true);

int info_tmp;
info_a2r(info,&info_tmp);
 _LOCAL_MPI_Info_set( &info_tmp, key_tmp, value, &ret_tmp, R_MPI_MAX_INFO_KEY-1, valuelen);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Info_set\n");
#endif

}

void  mpi_win_get_name_(int *,char *,int *, int *, fort_string_length);

void  mpi_win_get_name__(int *,char *,int*,int *, fort_string_length);

void  pmpi_win_get_name_(int *,char *,int*,int *, fort_string_length);

void  pmpi_win_get_name__(int *,char *,int*,int *, fort_string_length);


#pragma weak mpi_win_get_name_=A_f_MPI_Win_get_name
#pragma weak mpi_win_get_name__=A_f_MPI_Win_get_name
#pragma weak pmpi_win_get_name_=A_f_MPI_Win_get_name
#pragma weak pmpi_win_get_name__=A_f_MPI_Win_get_name
void  (*_LOCAL_MPI_Win_get_name)(int *,char *,int *,int*,fort_string_length);
void  A_f_MPI_Win_get_name(int * win,char * win_name, int *resultlen, int *ret, fort_string_length win_name_len)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Win_get_name\n");
#endif
in_w=1;

int  ret_tmp=0;

int win_tmp;
fwin_a2r(win,&win_tmp);
char tmp_name[R_MPI_MAX_OBJECT_NAME-1];
int resultlen_tmp;

 _LOCAL_MPI_Win_get_name( &win_tmp, tmp_name, &resultlen_tmp, &ret_tmp, R_MPI_MAX_OBJECT_NAME-1);

fstring_max_conv_r2a(win_name, tmp_name, win_name_len, resultlen_tmp);
length_max_conv_r2a(resultlen, &resultlen_tmp, A_MPI_MAX_OBJECT_NAME, R_MPI_MAX_OBJECT_NAME);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Win_get_name\n");
#endif

}

//MPI_Comm_get_name(MPI_Comm comm, char *comm_name, int *resultlen)
void  mpi_comm_get_name_(int *,char *,int *, int *, fort_string_length);

void  mpi_comm_get_name__(int *,char *,int*,int *, fort_string_length);

void  pmpi_comm_get_name_(int *,char *,int*,int *, fort_string_length);

void  pmpi_comm_get_name__(int *,char *,int*,int *, fort_string_length);

#pragma weak mpi_comm_get_name_=A_f_MPI_Comm_get_name
#pragma weak mpi_comm_get_name__=A_f_MPI_Comm_get_name
#pragma weak pmpi_comm_get_name_=A_f_MPI_Comm_get_name
#pragma weak pmpi_comm_get_name__=A_f_MPI_Comm_get_name
void  (*_LOCAL_MPI_Comm_get_name)(int *,char *,int *,int*,fort_string_length);
void  A_f_MPI_Comm_get_name(int * comm,char * comm_name, int *resultlen, int *ret, fort_string_length comm_name_len)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Comm_get_name\n");
#endif
in_w=1;

int  ret_tmp=0;

int comm_tmp;
comm_a2r(comm,&comm_tmp);
char tmp_name[R_MPI_MAX_OBJECT_NAME-1];
int resultlen_tmp;

 _LOCAL_MPI_Comm_get_name( &comm_tmp, tmp_name, &resultlen_tmp, &ret_tmp, R_MPI_MAX_OBJECT_NAME-1);

fstring_max_conv_r2a(comm_name, tmp_name, comm_name_len, resultlen_tmp);
length_max_conv_r2a(resultlen, &resultlen_tmp, A_MPI_MAX_OBJECT_NAME, R_MPI_MAX_OBJECT_NAME);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Comm_get_name\n");
#endif

}

//MPI_Comm_set_name(MPI_Comm comm, const char *comm_name)
void  mpi_comm_set_name_(int *,char *,int * , fort_string_length);

void  mpi_comm_set_name__(int *,char *,int* , fort_string_length);

void  pmpi_comm_set_name_(int *,char *,int* , fort_string_length);

void  pmpi_comm_set_name__(int *,char *,int*, fort_string_length);


#pragma weak mpi_comm_set_name_=A_f_MPI_Comm_set_name
#pragma weak mpi_comm_set_name__=A_f_MPI_Comm_set_name
#pragma weak pmpi_comm_set_name_=A_f_MPI_Comm_set_name
#pragma weak pmpi_comm_set_name__=A_f_MPI_Comm_set_name
void  (*_LOCAL_MPI_Comm_set_name)(int *,char *,int *,fort_string_length);
void  A_f_MPI_Comm_set_name(int * comm,char * comm_name, int *ret, fort_string_length comm_name_len)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Comm_set_name\n");
#endif
in_w=1;

int  ret_tmp=0;

int comm_tmp;
comm_a2r(comm,&comm_tmp);
char tmp_name[R_MPI_MAX_OBJECT_NAME-1];
fstring_max_conv_a2r(comm_name, tmp_name, comm_name_len, R_MPI_MAX_OBJECT_NAME-1, false);
 _LOCAL_MPI_Comm_set_name( &comm_tmp, tmp_name, &ret_tmp, R_MPI_MAX_OBJECT_NAME-1);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Comm_set_name\n");
#endif

}
//MPI_Comm_spawn(const char *command, char *argv[], int maxprocs,
//MPI_Info info, int root, MPI_Comm comm, MPI_Comm *intercomm,
//int array_of_errcodes[])
void  mpi_comm_spawn_(char *, char *, int *, int *, int *, int *, int *, int*, int*);

void  mpi_comm_spawn__(char *, char *, int *, int *, int *, int *, int *, int*, int*);

void  pmpi_comm_spawn_(char *, char *, int *, int *, int *, int *, int *, int*, int*);

void  pmpi_comm_spawn__(char *, char *, int *, int *, int *, int *, int *, int*, int*);

void  pmpi_comm_spawn_(char *, char *, int *, int *, int *, int *, int *, int*, int*);

//#define A_f_MPI_Comm_spawn _PMPI_Comm_spawn
//#pragma weak mpi_comm_spawn_=_PMPI_Comm_spawn
//#pragma weak mpi_comm_spawn__=_PMPI_Comm_spawn
//#pragma weak pmpi_comm_spawn__=_PMPI_Comm_spawn
#if defined(IFORT_CALL) || defined(PGI_CALL) || defined(FLANG_CALL) || (defined(GFORT_CALL) && __GNUC__ < 8)
void  (*_LOCAL_MPI_Comm_spawn)(char *, char *, int *, int *, int *, int *, int *, int*, int*, int, int);
#elif defined(GFORT_CALL) && __GNUC__ >= 8
void  (*_LOCAL_MPI_Comm_spawn)(char *, char *, int *, int *, int *, int *, int *, int*, int*, size_t, size_t);
#endif
#if defined(IFORT_CALL) || defined(PGI_CALL) || defined(FLANG_CALL) || (defined(GFORT_CALL) && __GNUC__ < 8)
void  A_f_MPI_Comm_spawn(char *command, char *argv, int *maxprocs, int *info, int *root, int *comm, int *intercomm, int *array_of_errcodes, int *ret,int command_len, int argv_len)
#elif defined(GFORT_CALL) && __GNUC__ >= 8
void  A_f_MPI_Comm_spawn(char *command, char *argv, int *maxprocs, int *info, int *root, int *comm, int *intercomm, int *array_of_errcodes, int *ret,size_t command_len, size_t argv_len)
#endif
{
#ifdef DEBUG
printf("entre : A_f_MPI_Comm_spawn\n");
#endif
in_w=1;

int  ret_tmp=0;

int info_tmp;
info_a2r(info,&info_tmp);
int root_tmp;
rank_mapper_a2r(root, &root_tmp);
int comm_tmp;
comm_a2r(comm,&comm_tmp);
int intercomm_tmp;

 _LOCAL_MPI_Comm_spawn(command, argv, maxprocs, &info_tmp, &root_tmp,&comm_tmp, &intercomm_tmp, array_of_errcodes, &ret_tmp,command_len,argv_len);
comm_r2a(intercomm,&intercomm_tmp);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Comm_spawn\n");
#endif

}

//MPI_Type_get_name(MPI_Datatype datatype, char *type_name,int *resultlen)
void  mpi_type_get_name_(int *,char *,int *, int *, fort_string_length);

void  mpi_type_get_name__(int *,char *,int*,int *, fort_string_length);

void  pmpi_type_get_name_(int *,char *,int*,int *, fort_string_length);

void  pmpi_type_get_name__(int *,char *,int*,int *, fort_string_length);

#pragma weak mpi_type_get_name_=A_f_MPI_Type_get_name
#pragma weak mpi_type_get_name__=A_f_MPI_Type_get_name
#pragma weak pmpi_type_get_name_=A_f_MPI_Type_get_name
#pragma weak pmpi_type_get_name__=A_f_MPI_Type_get_name
void  (*_LOCAL_MPI_Type_get_name)(int *,char *,int *,int*,fort_string_length);
void  A_f_MPI_Type_get_name(int * datatype,char * type_name, int *resultlen, int *ret, fort_string_length type_name_len)
{
#ifdef DEBUG
#endif
in_w=1;

int  ret_tmp=0;

int datatype_tmp;
datatype_a2r(datatype,&datatype_tmp);
char tmp_name[R_MPI_MAX_OBJECT_NAME-1];
int resultlen_tmp;

 _LOCAL_MPI_Type_get_name( &datatype_tmp, tmp_name, &resultlen_tmp, &ret_tmp, R_MPI_MAX_OBJECT_NAME-1);

fstring_max_conv_r2a(type_name, tmp_name, type_name_len, resultlen_tmp);
length_max_conv_r2a(resultlen, &resultlen_tmp, A_MPI_MAX_OBJECT_NAME, R_MPI_MAX_OBJECT_NAME);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
#endif

}

//MPI_Type_set_name(MPI_Datatype datatype, const char *type_name)
void  mpi_type_set_name_(int *,char *,int *, fort_string_length);

void  mpi_type_set_name__(int *,char *,int*, fort_string_length);

void  pmpi_type_set_name_(int *,char *,int*, fort_string_length);

void  pmpi_type_set_name__(int *,char *,int*, fort_string_length);

#pragma weak mpi_type_set_name_=A_f_MPI_Type_set_name
#pragma weak mpi_type_set_name__=A_f_MPI_Type_set_name
#pragma weak pmpi_type_set_name_=A_f_MPI_Type_set_name
#pragma weak pmpi_type_set_name__=A_f_MPI_Type_set_name
void  (*_LOCAL_MPI_Type_set_name)(int *,char *,int*,fort_string_length);
void  A_f_MPI_Type_set_name(int * datatype,char * type_name, int *ret, fort_string_length type_name_len)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Type_set_name\n");
#endif
in_w=1;

int  ret_tmp=0;

int datatype_tmp;
datatype_a2r(datatype,&datatype_tmp);
char tmp_name[R_MPI_MAX_OBJECT_NAME-1];
fstring_max_conv_a2r(type_name, tmp_name, type_name_len, R_MPI_MAX_OBJECT_NAME-1, false);
 _LOCAL_MPI_Type_set_name( &datatype_tmp, tmp_name, &ret_tmp, R_MPI_MAX_OBJECT_NAME-1);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Type_set_name\n");
#endif

}
//MPI_Add_error_string(int errorcode, const char *string)
void  mpi_add_error_string_(int *,char *,int *, fort_string_length);

void  mpi_add_error_string__(int *,char *,int*, fort_string_length);

void  pmpi_add_error_string_(int *,char *,int*, fort_string_length);

void  pmpi_add_error_string__(int *,char *,int*, fort_string_length);

#pragma weak mpi_add_error_string_=A_f_MPI_Add_error_string
#pragma weak mpi_add_error_string__=A_f_MPI_Add_error_string
#pragma weak pmpi_add_error_string_=A_f_MPI_Add_error_string
#pragma weak pmpi_add_error_string__=A_f_MPI_Add_error_string
void  (*_LOCAL_MPI_Add_error_string)(int *,char *,int*,fort_string_length);
void  A_f_MPI_Add_error_string(int * errorcode,char * string, int *ret, fort_string_length string_len)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Add_error_string\n");
#endif
in_w=1;

int  ret_tmp=0;

int errorcode_tmp;
error_a2r(errorcode,&errorcode_tmp);
char tmp_name[R_MPI_MAX_ERROR_STRING-1];
fstring_max_conv_a2r(string, tmp_name, string_len, R_MPI_MAX_ERROR_STRING-1, false);
 _LOCAL_MPI_Add_error_string( &errorcode_tmp, tmp_name, &ret_tmp, R_MPI_MAX_ERROR_STRING-1);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Add_error_string\n");
#endif

}

//MPI_Close_port(const char *port_name)
void  mpi_close_port_(char *,int *, fort_string_length);

void  mpi_close_port__(char *,int*, fort_string_length);

void  pmpi_close_port_(char *,int*, fort_string_length);

void  pmpi_close_port__(char *,int*, fort_string_length);

#pragma weak mpi_close_port_=A_f_MPI_Close_port
#pragma weak mpi_close_port__=A_f_MPI_Close_port
#pragma weak pmpi_close_port_=A_f_MPI_Close_port
#pragma weak pmpi_close_port__=A_f_MPI_Close_port
void  (*_LOCAL_MPI_Close_port)(char *,int*,fort_string_length);
void  A_f_MPI_Close_port(char * string, int *ret, fort_string_length string_len)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Close_port\n");
#endif
in_w=1;

int  ret_tmp=0;
char tmp_name[R_MPI_MAX_PORT_NAME-1];
fstring_max_conv_a2r(string, tmp_name, string_len, R_MPI_MAX_PORT_NAME-1, false);

 _LOCAL_MPI_Close_port(tmp_name, &ret_tmp, R_MPI_MAX_PORT_NAME-1);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Close_port\n");
#endif

}

void  mpi_get_library_version_(char *  ,int*,int*, fort_string_length);

void  mpi_get_library_version__(char * ,int*,int*, fort_string_length);

void  pmpi_get_library_version_(char * ,int*,int*, fort_string_length);

void  pmpi_get_library_version__(char *,int*,int*, fort_string_length);

#pragma weak mpi_get_library_version_=A_f_MPI_Get_library_version
#pragma weak mpi_get_library_version__=A_f_MPI_Get_library_version
#pragma weak pmpi_get_library_version_=A_f_MPI_Get_library_version
#pragma weak pmpi_get_library_version__=A_f_MPI_Get_library_version
void  (*_LOCAL_MPI_Get_library_version)(char *,int*,int*,fort_string_length);
void  A_f_MPI_Get_library_version(char * version, int *resultlen, int *ret, fort_string_length version_len)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Get_library_version\n");
#endif
in_w=1;

int  ret_tmp=0;
char tmp_version[R_MPI_MAX_LIBRARY_VERSION_STRING-1];
int tmp_resultlen;

_LOCAL_MPI_Get_library_version(tmp_version, &tmp_resultlen, &ret_tmp, sizeof(tmp_version));

fstring_max_conv_r2a(version, tmp_version, version_len, tmp_resultlen);
length_max_conv_r2a(resultlen, &tmp_resultlen, A_MPI_MAX_LIBRARY_VERSION_STRING, R_MPI_MAX_LIBRARY_VERSION_STRING);
error_r2a(ret,&ret_tmp);

in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Get_library_version\n");
#endif

}

//MPI_Open_port(MPI_Info info, char *port_name)
void  mpi_open_port_(int *  ,char*,int*, fort_string_length);

void  mpi_open_port__(int * ,char*,int*, fort_string_length);

void  pmpi_open_port_(int * ,char*,int*, fort_string_length);

void  pmpi_open_port__(int *,char*,int*, fort_string_length);

#pragma weak mpi_open_port_=A_f_MPI_Open_port
#pragma weak mpi_open_port__=A_f_MPI_Open_port
#pragma weak pmpi_open_port_=A_f_MPI_Open_port
#pragma weak pmpi_open_port__=A_f_MPI_Open_port
void  (*_LOCAL_MPI_Open_port)(int *,char*, int*,fort_string_length);
void  A_f_MPI_Open_port(int * info, char *port_name, int *ret, fort_string_length port_name_len)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Open_port\n");
#endif
in_w=1;

int  ret_tmp=0;
int info_tmp;
info_a2r(info, &info_tmp);
char tmp_name[R_MPI_MAX_PORT_NAME-1];

 _LOCAL_MPI_Open_port(&info_tmp, tmp_name, &ret_tmp, R_MPI_MAX_PORT_NAME-1);
 fstring_max_conv_r2a(port_name, tmp_name, port_name_len, R_MPI_MAX_PORT_NAME-1);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Open_port\n");
#endif

}

//MPI_Publish_name(const char *service_name, MPI_Info info,const char *port_name)
void  mpi_publish_name_(char*,int*,char*,int*, fort_string_length, fort_string_length);

void  mpi_publish_name__(char*,int*,char*,int*, fort_string_length, fort_string_length);

void  pmpi_publish_name_(char*,int*,char*,int*, fort_string_length, fort_string_length);

void  pmpi_publish_name__(char*,int*,char*,int*, fort_string_length, fort_string_length);

#pragma weak mpi_publish_name_=A_f_MPI_Publish_name
#pragma weak mpi_publish_name__=A_f_MPI_Publish_name
#pragma weak pmpi_publish_name_=A_f_MPI_Publish_name
#pragma weak pmpi_publish_name__=A_f_MPI_Publish_name
void  (*_LOCAL_MPI_Publish_name)(char *,int*, char*,int*,fort_string_length,fort_string_length);
void  A_f_MPI_Publish_name(char *service_name, int *info, char *port_name, int *ret, fort_string_length service_name_len, fort_string_length port_name_len)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Publish_name\n");
#endif
in_w=1;

int  ret_tmp=0;
int info_tmp;
info_a2r(info, &info_tmp);
char tmp_name[R_MPI_MAX_PORT_NAME-1];
fstring_max_conv_a2r(port_name, tmp_name, port_name_len, R_MPI_MAX_PORT_NAME-1, false);

 _LOCAL_MPI_Publish_name(service_name, &info_tmp, tmp_name, &ret_tmp,service_name_len, R_MPI_MAX_PORT_NAME-1);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Publish_name\n");
#endif

}

//MPI_Unpublish_name(const char *service_name, MPI_Info info,const char *port_name)
void  mpi_unpublish_name_(char*,int*,char*,int*, fort_string_length, fort_string_length);

void  mpi_unpublish_name__(char*,int*,char*,int*, fort_string_length, fort_string_length);

void  pmpi_unpublish_name_(char*,int*,char*,int*, fort_string_length, fort_string_length);

void  pmpi_unpublish_name__(char*,int*,char*,int*, fort_string_length, fort_string_length);

#pragma weak mpi_unpublish_name_=A_f_MPI_Unpublish_name
#pragma weak mpi_unpublish_name__=A_f_MPI_Unpublish_name
#pragma weak pmpi_unpublish_name_=A_f_MPI_Unpublish_name
#pragma weak pmpi_unpublish_name__=A_f_MPI_Unpublish_name
void  (*_LOCAL_MPI_Unpublish_name)(char *,int*, char*,int*,fort_string_length,fort_string_length);
void  A_f_MPI_Unpublish_name(char *service_name, int *info, char *port_name, int *ret, fort_string_length service_name_len, fort_string_length port_name_len)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Unpublish_name\n");
#endif
in_w=1;

int  ret_tmp=0;
int info_tmp;
info_a2r(info, &info_tmp);
char tmp_name[R_MPI_MAX_PORT_NAME-1];
fstring_max_conv_a2r(port_name, tmp_name, port_name_len, R_MPI_MAX_PORT_NAME-1, false);

 _LOCAL_MPI_Unpublish_name(service_name, &info_tmp, tmp_name, &ret_tmp,service_name_len, R_MPI_MAX_PORT_NAME-1);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Unpublish_name\n");
#endif

}

//MPI_Win_set_name(MPI_Win win, const char *win_name)
void  mpi_win_set_name_(int *, char *, int*, fort_string_length);

void  mpi_win_set_name__(int *, char *, int*, fort_string_length);

void  pmpi_win_set_name_(int *, char *, int*, fort_string_length);

void  pmpi_win_set_name__(int *, char *, int*, fort_string_length);

#pragma weak mpi_win_set_name_=A_f_MPI_Win_set_name
#pragma weak mpi_win_set_name__=A_f_MPI_Win_set_name
#pragma weak pmpi_win_set_name_=A_f_MPI_Win_set_name
#pragma weak pmpi_win_set_name__=A_f_MPI_Win_set_name
void  (*_LOCAL_MPI_Win_set_name)(int *, char *, int*, fort_string_length);
void  A_f_MPI_Win_set_name(int *win, char *win_name, int *ret, fort_string_length win_name_len)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Win_set_name\n");
#endif
in_w=1;

int  ret_tmp=0;
int win_tmp;
fwin_a2r(win, &win_tmp);
char tmp_name[R_MPI_MAX_OBJECT_NAME-1];
fstring_max_conv_a2r(win_name, tmp_name, win_name_len, R_MPI_MAX_OBJECT_NAME-1, false);

 _LOCAL_MPI_Win_set_name(&win_tmp, tmp_name, &ret_tmp, R_MPI_MAX_OBJECT_NAME-1);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Win_set_name\n");
#endif

}

//MPI_Lookup_name(const char *service_name, MPI_Info info,char *port_name)
void  mpi_lookup_name_(char *, int*, char *, int*, fort_string_length, fort_string_length);

void  mpi_lookup_name__(char *, int*, char *, int*, fort_string_length, fort_string_length);

void  pmpi_lookup_name_(char *, int*, char *, int*, fort_string_length, fort_string_length);

void  pmpi_lookup_name__(char *, int*, char *, int*, fort_string_length, fort_string_length);

#pragma weak mpi_lookup_name_=A_f_MPI_Lookup_name
#pragma weak mpi_lookup_name__=A_f_MPI_Lookup_name
#pragma weak pmpi_lookup_name_=A_f_MPI_Lookup_name
#pragma weak pmpi_lookup_name__=A_f_MPI_Lookup_name
void  (*_LOCAL_MPI_Lookup_name)(char*, int*, char *, int*, fort_string_length, fort_string_length);
void  A_f_MPI_Lookup_name(char *service_name, int *info, char *port_name, int *ret, fort_string_length service_name_len, fort_string_length port_name_len)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Lookup_name\n");
#endif
in_w=1;

int  ret_tmp=0;
int info_tmp;
info_a2r(info, &info_tmp);
char tmp_name[R_MPI_MAX_PORT_NAME-1];

 _LOCAL_MPI_Lookup_name(service_name, &info_tmp, tmp_name, &ret_tmp, service_name_len, R_MPI_MAX_PORT_NAME-1);
 fstring_max_conv_r2a(port_name, tmp_name, port_name_len, R_MPI_MAX_PORT_NAME-1);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Lookup_name\n");
#endif

}
void mpi_comm_accept_(char *, int *, int *, int *, int *, int *, fort_string_length);

void mpi_comm_accept__(char *, int *, int *, int *, int *, int *, fort_string_length);

void pmpi_comm_accept_(char *, int *, int *, int *, int *, int *, fort_string_length);

void pmpi_comm_accept__(char *, int *, int *, int *, int *, int *, fort_string_length);

#pragma weak mpi_comm_accept_ = A_f_MPI_Comm_accept
#pragma weak mpi_comm_accept__ = A_f_MPI_Comm_accept
#pragma weak pmpi_comm_accept_ = A_f_MPI_Comm_accept
#pragma weak pmpi_comm_accept__ = A_f_MPI_Comm_accept
void (*_LOCAL_MPI_Comm_accept)(char *, int *, int *, int *, int *, int *, fort_string_length);

void A_f_MPI_Comm_accept(char *port_name, int *info, int *root, int *comm,
                         int *newcomm, int *ret, fort_string_length port_name_len) {
#ifdef DEBUG
printf("entre : A_f_MPI_Comm_accept\n");
#endif
  in_w = 1;
  int ret_tmp = 0;

  int info_tmp;
  int root_tmp;
  int comm_tmp;
  int newcomm_tmp;
  info_a2r(info, &info_tmp);
  rank_mapper_a2r(root, &root_tmp);
  comm_a2r(comm, &comm_tmp);
  char tmp_name[R_MPI_MAX_PORT_NAME-1];
  fstring_max_conv_a2r(port_name, tmp_name, port_name_len, R_MPI_MAX_PORT_NAME-1, false);
  _LOCAL_MPI_Comm_accept(tmp_name, &info_tmp, &root_tmp, &comm_tmp,
                         &newcomm_tmp, &ret_tmp, R_MPI_MAX_PORT_NAME-1);
  if (ret_tmp == R_f_MPI_SUCCESS)
    comm_r2a(newcomm, &newcomm_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
printf("sort : A_f_MPI_Comm_accept\n");
#endif
}

void mpi_comm_connect_(char *, int *, int *, int *, int *, int *, fort_string_length);

void mpi_comm_connect__(char *, int *, int *, int *, int *, int *, fort_string_length);

void pmpi_comm_connect_(char *, int *, int *, int *, int *, int *, fort_string_length);

void pmpi_comm_connect__(char *, int *, int *, int *, int *, int *, fort_string_length);

#pragma weak mpi_comm_connect_ = A_f_MPI_Comm_connect
#pragma weak mpi_comm_connect__ = A_f_MPI_Comm_connect
#pragma weak pmpi_comm_connect_ = A_f_MPI_Comm_connect
#pragma weak pmpi_comm_connect__ = A_f_MPI_Comm_connect
void (*_LOCAL_MPI_Comm_connect)(char *, int *, int *, int *, int *, int *, fort_string_length);

void A_f_MPI_Comm_connect(char *port_name, int *info, int *root, int *comm,
                          int *newcomm, int *ret, fort_string_length port_name_len) {
#ifdef DEBUG
printf("entre : A_f_MPI_Comm_connect\n");
#endif
  in_w = 1;
  int ret_tmp = 0;

  int info_tmp;
  int root_tmp;
  int comm_tmp;
  int newcomm_tmp;
  info_a2r(info, &info_tmp);
  rank_mapper_a2r(root, &root_tmp);
  comm_a2r(comm, &comm_tmp);
  char tmp_name[R_MPI_MAX_PORT_NAME-1];
  fstring_max_conv_a2r(port_name, tmp_name, port_name_len, R_MPI_MAX_PORT_NAME-1, false);
  _LOCAL_MPI_Comm_connect(tmp_name, &info_tmp, &root_tmp, &comm_tmp,
                          &newcomm_tmp, &ret_tmp, R_MPI_MAX_PORT_NAME-1);
  if (ret_tmp == R_f_MPI_SUCCESS)
    comm_r2a(newcomm, &newcomm_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
printf("sort : A_f_MPI_Comm_connect\n");
#endif
}
//MPI_Pack_external(const char datarep[], const void *inbuf, int incount,MPI_Datatype datatype, void *outbuf, MPI_Aint outsize,MPI_Aint *position)
void  mpi_pack_external_(char *, void*, int, int*, void*, size_t, size_t *, int*);
                                                 
void  mpi_pack_external__(char *, void*, int, int*, void*, size_t, size_t *, int*);
                                          
void  pmpi_pack_external_(char *, void*, int, int*, void*, size_t, size_t *, int*);
                                          
void  pmpi_pack_external__(char *, void*, int, int*, void*, size_t, size_t *, int*);
                                                 
void  pmpi_pack_external_(char *, void*, int, int*, void*, size_t, size_t *, int*);

//#define A_f_MPI_Pack_external _PMPI_Pack_external
//#pragma weak mpi_pack_external_=_PMPI_Pack_external
//#pragma weak mpi_pack_external__=_PMPI_Pack_external
//#pragma weak pmpi_pack_external__=_PMPI_Pack_external
#if defined(IFORT_CALL) || defined(PGI_CALL) || defined(FLANG_CALL) || (defined(GFORT_CALL) && __GNUC__ < 8)
void  (*_LOCAL_MPI_Pack_external)(char *, void*, int, int*, void*, size_t, size_t *, int *, int);
#elif defined(GFORT_CALL) && __GNUC__ >= 8
void  (*_LOCAL_MPI_Pack_external)(char *, void*, int, int*, void*, size_t, size_t *, int *, size_t);
#endif
#if defined(IFORT_CALL) || defined(PGI_CALL) || defined(FLANG_CALL) || (defined(GFORT_CALL) && __GNUC__ < 8)
void  A_f_MPI_Pack_external(char *datarep, void *inbuf, int count, int *datatype, void *outbuf, size_t outsize, size_t *position, int *ret, int datarep_len)
#elif defined(GFORT_CALL) && __GNUC__ >= 8
void  A_f_MPI_Pack_external(char *datarep, void *inbuf, int count, int *datatype, void *outbuf, size_t outsize, size_t *position, int *ret, size_t datarep_len)
#endif
{
#ifdef DEBUG
printf("entre : A_f_MPI_Pack_external\n");
#endif
in_w=1;

int  ret_tmp=0;
int datatype_tmp;
datatype_a2r(datatype, &datatype_tmp);

 _LOCAL_MPI_Pack_external(datarep, inbuf, count, &datatype_tmp, outbuf, outsize, position, &ret_tmp, datarep_len);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Pack_external\n");
#endif

}
//MPI_Pack_external_size(const char datarep[], int incount,MPI_Datatype datatype, MPI_Aint *size)
void  mpi_pack_external_size_(char *, int, int *, size_t *, int *);
                                                 
void  mpi_pack_external_size__(char *, int, int *, size_t *, int *);
                                          
void  pmpi_pack_external_size_(char *, int, int *, size_t *, int *);
                                          
void  pmpi_pack_external_size__(char *, int, int *, size_t *, int *);
                                                 
void  pmpi_pack_external_size_(char *, int, int *, size_t *, int *);

//#define A_f_MPI_Pack_external_size _PMPI_Pack_external_size
//#pragma weak mpi_pack_external_size_=_PMPI_Pack_external_size
//#pragma weak mpi_pack_external_size__=_PMPI_Pack_external_size
//#pragma weak pmpi_pack_external_size__=_PMPI_Pack_external_size
#if defined(IFORT_CALL) || defined(PGI_CALL) || defined(FLANG_CALL) || (defined(GFORT_CALL) && __GNUC__ < 8)
void  (*_LOCAL_MPI_Pack_external_size)(char *, int, int *, size_t *, int *, int);
#elif defined(GFORT_CALL) && __GNUC__ >= 8
void  (*_LOCAL_MPI_Pack_external_size)(char *, int, int *, size_t *, int *, size_t);
#endif
#if defined(IFORT_CALL) || defined(PGI_CALL) || defined(FLANG_CALL) || (defined(GFORT_CALL) && __GNUC__ < 8)
void  A_f_MPI_Pack_external_size(char *datarep, int count, int *datatype, size_t *size, int *ret, int datarep_len)
#elif defined(GFORT_CALL) && __GNUC__ >= 8
void  A_f_MPI_Pack_external_size(char *datarep, int count, int *datatype, size_t *size, int *ret, size_t datarep_len)
#endif
{
#ifdef DEBUG
printf("entre : A_f_MPI_Pack_external_size\n");
#endif
in_w=1;

int  ret_tmp=0;
int datatype_tmp;
datatype_a2r(datatype, &datatype_tmp);

 _LOCAL_MPI_Pack_external_size(datarep, count, &datatype_tmp, size, &ret_tmp, datarep_len);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Pack_external_size\n");
#endif

}
//MPI_Unpack_external(const char datarep[], const void *inbuf,MPI_Aint insize, MPI_Aint *position, void *outbuf,int outcount, MPI_Datatype datatype)
void  mpi_unpack_external_(char *, void *, size_t, size_t *, void *, int, int *, int *);
                                                 
void  mpi_unpack_external__(char *, void *, size_t, size_t *, void *, int, int *, int *);
                                          
void  pmpi_unpack_external_(char *, void *, size_t, size_t *, void *, int, int *, int *);
                                          
void  pmpi_unpack_external__(char *, void *, size_t, size_t *, void *, int, int *, int *);
                                                 
void  pmpi_unpack_external_(char *, void *, size_t, size_t *, void *, int, int *, int *);

//#define A_f_MPI_Unpack_external _PMPI_Unpack_external
//#pragma weak mpi_unpack_external_=_PMPI_Unpack_external
//#pragma weak mpi_unpack_external__=_PMPI_Unpack_external
//#pragma weak pmpi_unpack_external__=_PMPI_Unpack_external
#if defined(IFORT_CALL) || defined(PGI_CALL) || defined(FLANG_CALL) || (defined(GFORT_CALL) && __GNUC__ < 8)
void  (*_LOCAL_MPI_Unpack_external)(char *, void *, size_t, size_t *, void *, int, int *, int *, int);
#elif defined(GFORT_CALL) && __GNUC__ >= 8
void  (*_LOCAL_MPI_Unpack_external)(char *, void *, size_t, size_t *, void *, int, int *, int *, size_t);
#endif
#if defined(IFORT_CALL) || defined(PGI_CALL) || defined(FLANG_CALL) || (defined(GFORT_CALL) && __GNUC__ < 8)
void  A_f_MPI_Unpack_external(char *datarep, void *inbuf, size_t insize, size_t *position, void *outbuf, int outcount, int *datatype, int *ret, int datarep_len)
#elif defined(GFORT_CALL) && __GNUC__ >= 8
void  A_f_MPI_Unpack_external(char *datarep, void *inbuf, size_t insize, size_t *position, void *outbuf, int outcount, int *datatype, int *ret, size_t datarep_len)
#endif
{
#ifdef DEBUG
printf("entre : A_f_MPI_Unpack_external\n");
#endif
in_w=1;

int  ret_tmp=0;
int datatype_tmp;
datatype_a2r(datatype, &datatype_tmp);

 _LOCAL_MPI_Unpack_external(datarep, inbuf, insize, position, outbuf, outcount, &datatype_tmp, &ret_tmp, datarep_len);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Unpack_external\n");
#endif

}
//void  mpi_register_datarep_(char **,void*,void*,void*,void *,int *,int );
//
//void  mpi_register_datarep__(char **,void*,void*,void*,void *,int *, int );
//
//void  pmpi_register_datarep_(char **,void*,void*,void*,void *,int *, int );
//
//void  pmpi_register_datarep__(char **,void*,void*,void*,void *,int *, int );
//
//void  pmpi_register_datarep_(char **,void*,void*,void*,void *,int *, int );
//
//#define A_f_MPI_Register_datarep _PMPI_Register_datarep
//#pragma weak mpi_register_datarep_=_PMPI_Register_datarep
//#pragma weak mpi_register_datarep__=_PMPI_Register_datarep
//#pragma weak pmpi_register_datarep__=_PMPI_Register_datarep
//void  (*_LOCAL_MPI_Register_datarep)(char **,void*,void*,void*,void *,int *);
//
//void  A_f_MPI_Register_datarep(char ** datarep,void* read_conversion_fn,void* write_conversion_fn,void* dtype_file_extent_fn,void * extra_state,int * ret)
//{
//#ifdef DEBUG
//printf("entre : A_f_MPI_Register_datarep\n");
//#endif
//in_w=1;
//int ret_tmp=0;
//int comm=R_f_MPI_COMM_WORLD;
//int errorcode=7;
//fprintf(stderr, "Not implemented yet\n");
//_LOCAL_MPI_Abort( &comm, &errorcode, &ret_tmp);
//error_r2a(ret,&ret_tmp);
//in_w=0;
//#ifdef DEBUG
//printf("sort : A_f_MPI_Register_datarep\n");
//#endif
//}

//MPI_Comm_spawn_multiple(int count, char *array_of_commands[],
//char **array_of_argv[], const int array_of_maxprocs[],
//const MPI_Info array_of_info[], int root, MPI_Comm comm,
//MPI_Comm *intercomm, int array_of_errcodes[])
//void  mpi_comm_spawn_multiple_(char *, char *, int *, int *, int *, int *, int *, int*, int*);
//
//void  mpi_comm_spawn_multiple__(char *, char *, int *, int *, int *, int *, int *, int*, int*);
//
//void  pmpi_comm_spawn_multiple_(char *, char *, int *, int *, int *, int *, int *, int*, int*);
//
//void  pmpi_comm_spawn_multiple__(char *, char *, int *, int *, int *, int *, int *, int*, int*);
//
//void  pmpi_comm_spawn_multiple_(char *, char *, int *, int *, int *, int *, int *, int*, int*);
//
//#define A_f_MPI_Comm_spawn_multiple _PMPI_Comm_spawn_multiple
//#pragma weak mpi_comm_spawn_multiple_=_PMPI_Comm_spawn_multiple
//#pragma weak mpi_comm_spawn_multiple__=_PMPI_Comm_spawn_multiple
//#pragma weak pmpi_comm_spawn_multiple__=_PMPI_Comm_spawn_multiple
//void  (*_LOCAL_MPI_Comm_spawn_multiple)(char *, char *, int *, int *, int *, int *, int *, int*, int*, int, int);
//#if defined(IFORT_CALL) || defined(PGI_CALL) || defined(FLANG_CALL)
//void  (*_LOCAL_MPI_Comm_spawn_multiple)(char *, char *, int *, int *, int *, int *, int *, int*, int*, int, int);
//#elif defined(GFORT_CALL)
//void  (*_LOCAL_MPI_Comm_spawn_multiple)(char *, int, char *, int, int *, int *, int *, int *, int *, int*, int*);
//#endif
//#if defined(IFORT_CALL) || defined(PGI_CALL) || defined(FLANG_CALL)
//void  A_f_MPI_Comm_spawn_multiple(char *command, char *argv, int *maxprocs, int *info, int *root, int *comm, int *intercomm, int *array_of_errcodes, int *ret,int command_len, int argv_len)
//#elif defined(GFORT_CALL)
//void  A_f_MPI_Comm_spawn_multiple(char *command, int command_len, char *argv, int argv_len, int *maxprocs, int *info, int *root, int *comm, int *intercomm, int *array_of_errcodes, int *ret)
//#endif
//{
//#ifdef DEBUG
//printf("entre : A_f_MPI_Comm_spawn_multiple\n");
//#endif
//in_w=1;
//
//int  ret_tmp=0;
//
//int info_tmp;
//info_a2r(info,&info_tmp);
//int root_tmp;
//rank_mapper_a2r(root, &root_tmp);
//int comm_tmp;
//comm_a2r(comm,&comm_tmp);
//int intercomm_tmp;
//
//#if defined(IFORT_CALL) || defined(PGI_CALL) || defined(FLANG_CALL)
// _LOCAL_MPI_Comm_spawn_multiple(command, argv, maxprocs, &info_tmp, &root_tmp,&comm_tmp, &intercomm_tmp, array_of_errcodes, &ret_tmp,command_len,argv_len);
//#elif defined(GFORT_CALL)
// _LOCAL_MPI_Comm_spawn_multiple(command, command_len, argv,argv_len, maxprocs, &info_tmp, &root_tmp,&comm_tmp, &intercomm_tmp, array_of_errcodes, &ret_tmp);
//#endif
//comm_r2a(intercomm,&intercomm_tmp);
//error_r2a(ret,&ret_tmp);
//in_w=0;
//#ifdef DEBUG
//printf("sort : A_f_MPI_Info_set\n");
//#endif
//
//}

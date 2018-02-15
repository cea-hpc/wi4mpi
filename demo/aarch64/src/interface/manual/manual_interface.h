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


#ifndef MANUAL_INTERFACE_H
#define MANUAL_INTERFACE_H

void mpi_get_processor_name_(char *,int *,int *,int);

void mpi_get_processor_name__(char *,int *,int *,int);

void pmpi_get_processor_name__(char *,int,int *,int *);


#pragma weak mpi_get_processor_name_=pmpi_get_processor_name_
#pragma weak mpi_get_processor_name__=pmpi_get_processor_name_
#pragma weak pmpi_get_processor_name__=pmpi_get_processor_name_
#ifdef IFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Get_processor_name)(char *,int *,int *,int);
#elif GFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Get_processor_name)(char *,int,int *,int *);
#endif
#ifdef IFORT_CALL
void  pmpi_get_processor_name_(char * name,int * resultlen,int * ret,int namelen)
#elif GFORT_CALL
void pmpi_get_processor_name_(char * name,int namelen,int * resultlen,int * ret)
#endif
{
#ifdef DEBUG
printf("entre : f_MPI_Get_processor_name (interface) \n");
#endif
#ifdef IFORT_CALL
INTERFACE_F_LOCAL_MPI_Get_processor_name(name,resultlen,ret,namelen);
#elif GFORT_CALL
INTERFACE_F_LOCAL_MPI_Get_processor_name(name,namelen,resultlen,ret);
#endif
#ifdef DEBUG
printf("sort : f_MPI_Get_processor_name (interface) \n");
#endif
}
#ifdef IFORT_CALL

void  mpi_error_string_(int *,char *,int *,int *,int);

void  mpi_error_string__(int *,char *,int *,int *,int);

void  pmpi_error_string_(int *,char *,int *,int *,int);

void  pmpi_error_string__(int *,char *,int *,int *,int);

void  pmpi_error_string_(int *,char *,int *,int *,int);
#elif GFORT_CALL
void  mpi_error_string_(int *,char *,int,int *,int *);

void  mpi_error_string__(int *,char *,int,int *,int *);

void  pmpi_error_string_(int *,char *,int,int *,int *);

void  pmpi_error_string__(int *,char *,int,int *,int *);

void  pmpi_error_string_(int *,char *,int,int *,int *);

#endif
#pragma weak mpi_error_string_=pmpi_error_string_
#pragma weak mpi_error_string__=pmpi_error_string_
#pragma weak pmpi_error_string__=pmpi_error_string_

#ifdef IFORT_CALL
void  (*INTERFACE_F_LOCAL_MPI_Error_string)(int * errorcode,char * string,int * resultlen,int * ret,int reslen);
#elif GFORT_CALL
void  (*INTERFACE_F_LOCAL_MPI_Error_string)(int * errorcode,int reslen,char * string,int * resultlen,int * ret);
#endif

#ifdef IFORT_CALL
void pmpi_error_string_(int * errorcode,char * string,int * resultlen,int * ret,int reslen)
#elif GFORT_CALL
void pmpi_error_string_(int * errorcode,char * string,int reslen,int * resultlen,int * ret)
#endif
{
#ifdef DEBUG
printf("entre : f_MPI_Error_string (interface) \n");
#endif
#ifdef IFORT_CALL
    INTERFACE_F_LOCAL_MPI_Error_string(errorcode,string,resultlen,ret,reslen);
#elif GFORT_CALL
    INTERFACE_F_LOCAL_MPI_Error_string(errorcode,string,reslen,resultlen,ret);
#endif
#ifdef DEBUG
printf("sort : f_MPI_Error_string (interface) \n");
#endif
}

#ifdef IFORT_CALL

void  mpi_file_open__(int*, char *,int *,int *,int*,int);

void  mpi_file_open_(int*, char *,int *,int *,int*,int);

void  pmpi_file_open_(int*, char *,int *,int *,int*,int);

void  pmpi_file_open__(int*, char *,int *,int *,int*,int);

void  pmpi_file_open_(int*, char *,int *,int *,int*,int);

#elif GFORT_CALL

void  mpi_file_open_(int*, char *, int, int *,int *,int*);

void  mpi_file_open__(int*, char *, int,int *,int *,int*);

void  pmpi_file_open_(int*, char *, int,int *,int *,int*);

void  pmpi_file_open__(int*, char *, int,int *,int *,int*);

void  pmpi_file_open_(int*, char *, int,int *,int *,int*);

#endif
#define A_f_MPI_File_open _PMPI_File_open
#pragma weak mpi_file_open_=_PMPI_File_open
#pragma weak mpi_file_open__=_PMPI_File_open
#pragma weak pmpi_file_open__=_PMPI_File_open

#ifdef IFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_File_open)(int *, char*, int*, int*, int*,int*, int);
#elif GFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_File_open)(int *, char*, int, int*, int*,int*, int*);
#endif
#ifdef IFORT_CALL
A_f_MPI_File_open(int* comm, char *filename, int* amode,int* info, int *fh,int *ret, int filenamelen)
#elif GFORT_CALL
A_f_MPI_File_open(int* comm, char *filename, int filenamelen, int* amode,int* info, int *fh,int* ret)
#endif
{
#ifdef DEBUG
printf("entre : f_MPI_File_open (interface) \n");
#endif
#ifdef IFORT_CALL
INTERFACE_F_LOCAL_MPI_File_open(comm, filename, amode, info, fh, ret, filenamelen);
#elif GFORT_CALL
INTERFACE_F_LOCAL_MPI_File_open(comm, filename, filenamelen, amode, info, ret, fh);
#endif
#ifdef DEBUG
printf("sort : f_MPI_File_open (interface) \n");
#endif

}

#ifdef IFORT_CALL
void  mpi_file_set_view_(int *,int*,int *,int *,char *,int *,int *,int);

void  mpi_file_set_view__(int *,int*,int *,int *,char *,int *,int *,int);

void  pmpi_file_set_view_(int *,int*,int *,int *,char *,int *,int *,int);

void  pmpi_file_set_view__(int *,int*,int *,int *,char *,int *,int *,int);

void  pmpi_file_set_view_(int *,int*,int *,int *,char *,int *,int *,int);

#elif GFORT_CALL

void  mpi_file_set_view_(int *,int*,int *,int *,char *, int,int *,int *);

void  mpi_file_set_view__(int *,int*,int *,int *,char *, int,int *,int *);

void  pmpi_file_set_view_(int *,int*,int *,int *,char *, int,int *,int *);

void  pmpi_file_set_view__(int *,int*,int *,int *,char *, int,int *,int *);

void  pmpi_file_set_view_(int *,int*,int *,int *,char *, int,int *,int *);


#endif
#define A_f_MPI_File_set_view _PMPI_File_set_view
#pragma weak mpi_file_set_view_=_PMPI_File_set_view
#pragma weak mpi_file_set_view__=_PMPI_File_set_view
#pragma weak pmpi_file_set_view__=_PMPI_File_set_view

#ifdef IFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_File_set_view)(int *,int*,int *,int *,char *,int *,int *,int);
#elif GFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_File_set_view)(int *,int*,int *,int *,char *,int,int *,int *);
#endif
#ifdef IFORT_CALL
A_f_MPI_File_set_view(int * fh,int* disp,int * etype,int * filetype,char *datarep,int * info,int * ret,int datareplen)
#elif GFORT_CALL
A_f_MPI_File_set_view(int * fh,int* disp,int * etype,int * filetype,char *datarep,int datareplen, int *info,int * ret)
#endif
{
#ifdef DEBUG
printf("entre : f_MPI_File_set_view (interface) \n");
#endif
#ifdef IFORT_CALL
INTERFACE_F_LOCAL_MPI_File_set_view(fh, disp, etype, filetype, datarep, info, ret, datareplen);
#elif GFORT_CALL
INTERFACE_F_LOCAL_MPI_File_set_view(fh, disp, etype, filetype, datarep, datareplen,info, ret);
#endif
#ifdef DEBUG
printf("sort : f_MPI_File_set_view (interface) \n");
#endif
}

#ifdef IFORT_CALL

void  mpi_file_get_view_(int *,int*,int *,int *,char *,int*,int);

void  mpi_file_get_view__(int *,int*,int *,int *,char *,int*,int);

void  pmpi_file_get_view_(int *,int*,int *,int *,char *,int*,int);

void  pmpi_file_get_view__(int *,int*,int *,int *,char *,int*,int);

void  pmpi_file_get_view_(int *,int*,int *,int *,char *,int*,int);

#elif GFORT_CALL

void  mpi_file_get_view_(int *,int*,int *,int *,char *, int,int*);

void  mpi_file_get_view__(int *,int*,int *,int *,char *, int,int*);

void  pmpi_file_get_view_(int *,int*,int *,int *,char *, int,int*);

void  pmpi_file_get_view__(int *,int*,int *,int *,char *, int,int*);

void  pmpi_file_get_view_(int *,int*,int *,int *,char *, int,int*);


#endif
#define A_f_MPI_File_get_view _PMPI_File_get_view
#pragma weak mpi_file_get_view_=_PMPI_File_get_view
#pragma weak mpi_file_get_view__=_PMPI_File_get_view
#pragma weak pmpi_file_get_view__=_PMPI_File_get_view

#ifdef IFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_File_get_view)(int *,int*,int *,int *,char *,int *,int);
#elif GFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_File_get_view)(int *,int*,int *,int *,char *,int,int *);
#endif
#ifdef IFORT_CALL
A_f_MPI_File_get_view(int * fh,int* disp,int * etype,int * filetype,char *datarep,int * ret,int datareplen)
#elif GFORT_CALL
A_f_MPI_File_get_view(int * fh,int* disp,int * etype,int * filetype,char *datarep,int datareplen,int * ret)
#endif
{
#ifdef DEBUG
printf("entre : f_MPI_File_get_view (interface) \n");
#endif
#ifdef IFORT_CALL
INTERFACE_F_LOCAL_MPI_File_get_view(fh, disp, etype, filetype, datarep, ret, datareplen);
#elif GFORT_CALL
INTERFACE_F_LOCAL_MPI_File_get_view(fh, disp, etype, filetype, datarep, datareplen,ret);
#endif
#ifdef DEBUG
printf("sort : f_MPI_File_get_view (interface) \n");
#endif
}

#ifdef IFORT_CALL

void  mpi_file_delete_(char *,int *,int *,int);

void  mpi_file_delete__(char *,int *,int *,int);

void  pmpi_file_delete_(char *,int *,int *,int);

void  pmpi_file_delete__(char *,int *,int *,int);

void  pmpi_file_delete_(char *,int *,int *,int);

#elif GFORT_CALL

void  mpi_file_delete_(char *,int,int *,int *);

void  mpi_file_delete__(char *,int,int *,int *);

void  pmpi_file_delete_(char *,int,int *,int *);

void  pmpi_file_delete__(char *,int,int *,int *);

void  pmpi_file_delete_(char *,int,int *,int *);


#endif
#define A_f_MPI_File_delete _PMPI_File_delete
#pragma weak mpi_file_delete_=_PMPI_File_delete
#pragma weak mpi_file_delete__=_PMPI_File_delete
#pragma weak pmpi_file_delete__=_PMPI_File_delete

#ifdef IFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_File_delete)(char *,int *,int *,int);
#elif GFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_File_delete)(char *,int,int *,int *);
#endif
#ifdef IFORT_CALL
A_f_MPI_File_delete(char * filename,int * info,int * ret,int filenamelen)
#elif GFORT_CALL
A_f_MPI_File_delete(char * filename,int filenamelen,int * info,int * ret)
#endif
{
#ifdef DEBUG
printf("entre : f_MPI_File_delete (interface) \n");
#endif
#ifdef IFORT_CALL
INTERFACE_F_LOCAL_MPI_File_delete(filename, info, ret, filenamelen);
#elif GFORT_CALL
INTERFACE_F_LOCAL_MPI_File_delete(filename, filenamelen, info, ret);
#endif
#ifdef DEBUG
printf("sort : f_MPI_File_delete (interface) \n");
#endif
}
#ifdef IFORT_CALL

void  mpi_info_get_(int *,char *,int *,char *,int *,int *, int, int);

void  mpi_info_get__(int *,char *,int *,char *,int *,int *, int, int);

void  pmpi_info_get_(int *,char *,int *,char *,int *,int *, int, int);

void  pmpi_info_get__(int *,char *,int *,char *,int *,int *, int, int);

void  pmpi_info_get_(int *,char *,int *,char *,int *,int *, int, int);

#elif GFORT_CALL

void  mpi_info_get_(int *,char *, int,int *,char *, int,int *,int *);

void  mpi_info_get__(int *,char *, int,int *,char *, int,int *,int *);

void  pmpi_info_get_(int *,char *, int,int *,char *, int,int *,int *);

void  pmpi_info_get__(int *,char *, int,int *,char *, int,int *,int *);

void  pmpi_info_get_(int *,char *, int,int *,char *, int,int *,int *);


#endif
#define A_f_MPI_Info_get _PMPI_Info_get
#pragma weak mpi_info_get_=_PMPI_Info_get
#pragma weak mpi_info_get__=_PMPI_Info_get
#pragma weak pmpi_info_get__=_PMPI_Info_get

#ifdef IFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Info_get)(int *,char *,int *,char *,int *,int *, int, int);
#elif GFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Info_get)(int *,char *, int,int *,char *, int,int *,int *);
#endif
#ifdef IFORT_CALL
A_f_MPI_Info_get(int * info,char * key,int * valuelen,char * value,int * flag,int * ret, int keylen, int valuelen_)
#elif GFORT_CALL
A_f_MPI_Info_get(int * info,char * key, int keylen,int * valuelen,char * value, int valuelen_, int * flag,int * ret)
#endif
{
#ifdef DEBUG
printf("entre : f_MPI_Info_get (interface) \n");
#endif
#ifdef IFORT_CALL
INTERFACE_F_LOCAL_MPI_Info_get(info, key, valuelen, value, flag, ret, keylen, valuelen_);
#elif GFORT_CALL
INTERFACE_F_LOCAL_MPI_Info_get(info, key, keylen,valuelen, value, valuelen_, flag, ret);
#endif
#ifdef DEBUG
printf("sort : f_MPI_Info_get (interface) \n");
#endif
}
#ifdef IFORT_CALL

void  mpi_info_get_nthkey_(int *,int *,char *,int *, int);

void  mpi_info_get_nthkey__(int *,int *,char *,int *, int);

void  pmpi_info_get_nthkey_(int *,int *,char *,int *, int);

void  pmpi_info_get_nthkey__(int *,int *,char *,int *, int);

void  pmpi_info_get_nthkey_(int *,int *,char *,int *, int);

#elif GFORT_CALL

void  mpi_info_get_nthkey_(int *,int *,char *, int,int *);

void  mpi_info_get_nthkey__(int *,int *,char *, int,int *);

void  pmpi_info_get_nthkey_(int *,int *,char *, int,int *);

void  pmpi_info_get_nthkey__(int *,int *,char *, int,int *);

void  pmpi_info_get_nthkey_(int *,int *,char *, int,int *);


#endif
#define A_f_MPI_Info_get_nthkey _PMPI_Info_get_nthkey
#pragma weak mpi_info_get_nthkey_=_PMPI_Info_get_nthkey
#pragma weak mpi_info_get_nthkey__=_PMPI_Info_get_nthkey
#pragma weak pmpi_info_get_nthkey__=_PMPI_Info_get_nthkey

#ifdef IFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Info_get_nthkey)(int *,int *,char *,int *, int);
#elif GFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Info_get_nthkey)(int *,int *,char *, int,int *);
#endif
#ifdef IFORT_CALL
A_f_MPI_Info_get_nthkey(int * info,int * n,char * key,int * ret,int keylen)
#elif GFORT_CALL
A_f_MPI_Info_get_nthkey(int * info,int * n,char * key,int keylen,int * ret)
#endif
{
#ifdef DEBUG
printf("entre : f_MPI_Info_get_nthkey (interface) \n");
#endif
#ifdef IFORT_CALL
INTERFACE_F_LOCAL_MPI_Info_get_nthkey(info, n, key, ret,keylen);
#elif GFORT_CALL
INTERFACE_F_LOCAL_MPI_Info_get_nthkey(info, n, key, keylen, ret);
#endif
#ifdef DEBUG
printf("sort : f_MPI_Info_get_nthkey (interface) \n");
#endif
}
#ifdef IFORT_CALL

void  mpi_info_get_valuelen_(int *,char *,int *,int *,int *,int);

void  mpi_info_get_valuelen__(int *,char *,int *,int *,int *,int);

void  pmpi_info_get_valuelen_(int *,char *,int *,int *,int *,int);

void  pmpi_info_get_valuelen__(int *,char *,int *,int *,int *,int);

void  pmpi_info_get_valuelen_(int *,char *,int *,int *,int *,int);

#elif GFORT_CALL

void  mpi_info_get_valuelen_(int *,char *, int,int *,int *,int *);

void  mpi_info_get_valuelen__(int *,char *, int,int *,int *,int *);

void  pmpi_info_get_valuelen_(int *,char *, int,int *,int *,int *);

void  pmpi_info_get_valuelen__(int *,char *, int,int *,int *,int *);

void  pmpi_info_get_valuelen_(int *,char *, int,int *,int *,int *);


#endif
#define A_f_MPI_Info_get_valuelen _PMPI_Info_get_valuelen
#pragma weak mpi_info_get_valuelen_=_PMPI_Info_get_valuelen
#pragma weak mpi_info_get_valuelen__=_PMPI_Info_get_valuelen
#pragma weak pmpi_info_get_valuelen__=_PMPI_Info_get_valuelen

#ifdef IFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Info_get_valuelen)(int *,char *,int *,int *,int *,int);
#elif GFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Info_get_valuelen)(int *,char *,int,int *,int *,int *);
#endif
#ifdef IFORT_CALL
A_f_MPI_Info_get_valuelen(int * info,char * key,int * valuelen,int * flag,int * ret,int keylen)
#elif GFORT_CALL
A_f_MPI_Info_get_valuelen(int * info,char * key,int keylen,int * valuelen,int * flag,int * ret)
#endif
{
#ifdef DEBUG
printf("entre : f_MPI_Info_get_valuelen (interface) \n");
#endif
#ifdef IFORT_CALL
INTERFACE_F_LOCAL_MPI_Info_get_valuelen(info, key, valuelen, flag, ret, keylen);
#elif GFORT_CALL
INTERFACE_F_LOCAL_MPI_Info_get_valuelen(info, key, keylen, valuelen, flag, ret);
#endif
#ifdef DEBUG
printf("sort : f_MPI_Info_get_valuelen (interface) \n");
#endif
}

#ifdef IFORT_CALL

void  mpi_info_set_(int *,char *,char *,int *, int, int);

void  mpi_info_set__(int *,char *,char *,int *, int, int);

void  pmpi_info_set_(int *,char *,char *,int *, int, int);

void  pmpi_info_set__(int *,char *,char *,int *, int, int);

void  pmpi_info_set_(int *,char *,char *,int *, int, int);

#elif GFORT_CALL

void  mpi_info_set_(int *,char *, int,char *, int, int *);

void  mpi_info_set__(int *,char *, int,char *, int, int *);

void  pmpi_info_set_(int *,char *, int,char *, int, int *);

void  pmpi_info_set__(int *,char *, int,char *, int, int *);

void  pmpi_info_set_(int *,char *, int,char *, int, int *);


#endif
#define A_f_MPI_Info_set _PMPI_Info_set
#pragma weak mpi_info_set_=_PMPI_Info_set
#pragma weak mpi_info_set__=_PMPI_Info_set
#pragma weak pmpi_info_set__=_PMPI_Info_set

#ifdef IFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Info_set)(int *,char *,char *,int *, int, int);
#elif GFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Info_set)(int *,char *, int,char *, int, int *);
#endif
#ifdef IFORT_CALL
A_f_MPI_Info_set(int * info,char * key,char * value,int * ret,int keylen,int valuelen)
#elif GFORT_CALL
A_f_MPI_Info_set(int * info,char * key,int keylen,char * value,int valuelen,int * ret)
#endif
{
#ifdef DEBUG
printf("entre : f_MPI_Info_set (interface) \n");
#endif
#ifdef IFORT_CALL
INTERFACE_F_LOCAL_MPI_Info_set(info, key, value, ret, keylen, valuelen);
#elif GFORT_CALL
INTERFACE_F_LOCAL_MPI_Info_set(info, key, keylen, value, valuelen, ret);
#endif
#ifdef DEBUG
printf("sort : f_MPI_Info_set (interface) \n");
#endif
}

#ifdef IFORT_CALL

void  mpi_win_get_name_(int *,char *,int *, int *, int);

void  mpi_win_get_name__(int *,char *,int *, int *, int);

void  pmpi_win_get_name_(int *,char *,int *, int *, int);

void  pmpi_win_get_name__(int *,char *,int *, int *, int);

void  pmpi_win_get_name_(int *,char *,int *, int *, int);

#elif GFORT_CALL

void  mpi_win_get_name_(int *,char *, int,int *, int *);

void  mpi_win_get_name__(int *,char *, int,int *, int *);

void  pmpi_win_get_name_(int *,char *, int,int *, int *);

void  pmpi_win_get_name__(int *,char *, int,int *, int *);

void  pmpi_win_get_name_(int *,char *, int,int *, int *);


#endif
#define A_f_MPI_Win_get_name _PMPI_Win_get_name
#pragma weak mpi_win_get_name_=_PMPI_Win_get_name
#pragma weak mpi_win_get_name__=_PMPI_Win_get_name
#pragma weak pmpi_win_get_name__=_PMPI_Win_get_name

#ifdef IFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Win_get_name)(int *,char *,int *, int *, int);
#elif GFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Win_get_name)(int *,char *, int,int *, int *);
#endif
#ifdef IFORT_CALL
A_f_MPI_Win_get_name(int * win,char * win_name, int *resultlen, int *ret, int win_name_len)
#elif GFORT_CALL
A_f_MPI_Win_get_name(int * win,char * win_name, int win_name_len, int *resultlen, int * ret)
#endif
{
#ifdef DEBUG
printf("entre : f_MPI_Win_get_name (interface) \n");
#endif
#ifdef IFORT_CALL
INTERFACE_F_LOCAL_MPI_Win_get_name(win, win_name, resultlen, ret, win_name_len);
#elif GFORT_CALL
INTERFACE_F_LOCAL_MPI_Win_get_name(win, win_name, win_name_len, resultlen, ret);
#endif
#ifdef DEBUG
printf("sort : f_MPI_Win_get_name (interface) \n");
#endif
}
#ifdef IFORT_CALL

void  mpi_comm_get_name_(int *,char *,int *, int *, int);

void  mpi_comm_get_name__(int *,char *,int *, int *, int);

void  pmpi_comm_get_name_(int *,char *,int *, int *, int);

void  pmpi_comm_get_name__(int *,char *,int *, int *, int);

void  pmpi_comm_get_name_(int *,char *,int *, int *, int);

#elif GFORT_CALL

void  mpi_comm_get_name_(int *,char *, int,int *, int *);

void  mpi_comm_get_name__(int *,char *, int,int *, int *);

void  pmpi_comm_get_name_(int *,char *, int,int *, int *);

void  pmpi_comm_get_name__(int *,char *, int,int *, int *);

void  pmpi_comm_get_name_(int *,char *, int,int *, int *);


#endif
#define A_f_MPI_Comm_get_name _PMPI_Comm_get_name
#pragma weak mpi_comm_get_name_=_PMPI_Comm_get_name
#pragma weak mpi_comm_get_name__=_PMPI_Comm_get_name
#pragma weak pmpi_comm_get_name__=_PMPI_Comm_get_name

#ifdef IFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Comm_get_name)(int *,char *,int *, int *, int);
#elif GFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Comm_get_name)(int *,char *, int,int *, int *);
#endif
#ifdef IFORT_CALL
A_f_MPI_Comm_get_name(int * comm,char * comm_name, int *resultlen, int *ret, int comm_name_len)
#elif GFORT_CALL
A_f_MPI_Comm_get_name(int * comm,char * comm_name, int comm_name_len, int *resultlen, int * ret)
#endif
{
#ifdef DEBUG
printf("entre : f_MPI_Comm_get_name (interface) \n");
#endif
#ifdef IFORT_CALL
INTERFACE_F_LOCAL_MPI_Comm_get_name(comm, comm_name, resultlen, ret, comm_name_len);
#elif GFORT_CALL
INTERFACE_F_LOCAL_MPI_Comm_get_name(comm, comm_name, comm_name_len, resultlen, ret);
#endif
#ifdef DEBUG
printf("sort : f_MPI_Comm_get_name (interface) \n");
#endif
}
#ifdef IFORT_CALL

void  mpi_comm_set_name_(int *,char *,int *, int);

void  mpi_comm_set_name__(int *,char *,int *, int);

void  pmpi_comm_set_name_(int *,char *,int *, int);

void  pmpi_comm_set_name__(int *,char *,int *, int);

void  pmpi_comm_set_name_(int *,char *,int *, int);

#elif GFORT_CALL

void  mpi_comm_set_name_(int *,char *, int,int *);

void  mpi_comm_set_name__(int *,char *, int,int *);

void  pmpi_comm_set_name_(int *,char *, int,int *);

void  pmpi_comm_set_name__(int *,char *, int,int *);

void  pmpi_comm_set_name_(int *,char *, int,int *);


#endif
#define A_f_MPI_Comm_set_name _PMPI_Comm_set_name
#pragma weak mpi_comm_set_name_=_PMPI_Comm_set_name
#pragma weak mpi_comm_set_name__=_PMPI_Comm_set_name
#pragma weak pmpi_comm_set_name__=_PMPI_Comm_set_name

#ifdef IFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Comm_set_name)(int *,char *,int *, int);
#elif GFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Comm_set_name)(int *,char *, int,int *);
#endif
#ifdef IFORT_CALL
A_f_MPI_Comm_set_name(int * comm,char * comm_name, int *ret, int comm_name_len)
#elif GFORT_CALL
A_f_MPI_Comm_set_name(int * comm,char * comm_name, int comm_name_len, int *ret)
#endif
{
#ifdef DEBUG
printf("entre : f_MPI_Comm_set_name (interface) \n");
#endif
#ifdef IFORT_CALL
INTERFACE_F_LOCAL_MPI_Comm_set_name(comm, comm_name, ret, comm_name_len);
#elif GFORT_CALL
INTERFACE_F_LOCAL_MPI_Comm_set_name(comm, comm_name, comm_name_len, ret);
#endif
#ifdef DEBUG
printf("sort : f_MPI_Comm_set_name (interface) \n");
#endif
}

#ifdef IFORT_CALL

void  mpi_comm_spawn_(char *, char *, int *, int *, int *, int *, int *, int*, int*,int,int);

void  mpi_comm_spawn__(char *, char *, int *, int *, int *, int *, int *, int*, int*,int,int);

void  pmpi_comm_spawn_(char *, char *, int *, int *, int *, int *, int *, int*, int*,int,int);

void  pmpi_comm_spawn__(char *, char *, int *, int *, int *, int *, int *, int*, int*,int,int);

void  pmpi_comm_spawn_(char *, char *, int *, int *, int *, int *, int *, int*, int*,int,int);

#elif GFORT_CALL

void  mpi_comm_spawn_(char *, int, char *, int, int *, int *, int *, int *, int *, int*, int*);

void  mpi_comm_spawn__(char *, int, char *, int, int *, int *, int *, int *, int *, int*, int*);

void  pmpi_comm_spawn_(char *, int, char *, int, int *, int *, int *, int *, int *, int*, int*);

void  pmpi_comm_spawn__(char *, int, char *, int, int *, int *, int *, int *, int *, int*, int*);

void  pmpi_comm_spawn_(char *, int, char *, int, int *, int *, int *, int *, int *, int*, int*);


#endif
#define A_f_MPI_Comm_spawn _PMPI_Comm_spawn
#pragma weak mpi_comm_spawn_=_PMPI_Comm_spawn
#pragma weak mpi_comm_spawn__=_PMPI_Comm_spawn
#pragma weak pmpi_comm_spawn__=_PMPI_Comm_spawn

#ifdef IFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Comm_spawn)(char *, char *, int *, int *, int *, int *, int *, int*, int*,int,int);
#elif GFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Comm_spawn)(char *, int, char *, int, int *, int *, int *, int *, int *, int*, int*);
#endif
#ifdef IFORT_CALL
A_f_MPI_Comm_spawn(char *command, char *argv, int *maxprocs, int *info, int *root, int *comm, int *intercomm, int *array_of_errcodes, int *ret,int command_len, int argv_len)
#elif GFORT_CALL
A_f_MPI_Comm_spawn(char *command, int command_len, char *argv, int argv_len, int *maxprocs, int *info, int *root, int *comm, int *intercomm, int *array_of_errcodes, int *ret)
#endif
{
#ifdef DEBUG
printf("entre : f_MPI_Comm_spawn (interface) \n");
#endif
#ifdef IFORT_CALL
INTERFACE_F_LOCAL_MPI_Comm_spawn(command, argv, maxprocs, info, root,comm, intercomm, array_of_errcodes, ret,command_len,argv_len);
#elif GFORT_CALL
INTERFACE_F_LOCAL_MPI_Comm_spawn(command, command_len, argv,argv_len, maxprocs, info, root,comm, intercomm, array_of_errcodes, ret);
#endif
#ifdef DEBUG
printf("sort : f_MPI_Comm_spawn (interface) \n");
#endif
}

#ifdef IFORT_CALL

void  mpi_type_get_name_(int *,char *,int *, int *,int);

void  mpi_type_get_name__(int *,char *,int *, int *,int);

void  pmpi_type_get_name_(int *,char *,int *, int *,int);

void  pmpi_type_get_name__(int *,char *,int *, int *,int);

void  pmpi_type_get_name_(int *,char *,int *, int *,int);

#elif GFORT_CALL

void  mpi_type_get_name_(int *,char *, int,int *, int *);

void  mpi_type_get_name__(int *,char *, int,int *, int *);

void  pmpi_type_get_name_(int *,char *, int,int *, int *);

void  pmpi_type_get_name__(int *,char *, int,int *, int *);

void  pmpi_type_get_name_(int *,char *, int,int *, int *);


#endif
#define A_f_MPI_Type_get_name _PMPI_Type_get_name
#pragma weak mpi_type_get_name_=_PMPI_Type_get_name
#pragma weak mpi_type_get_name__=_PMPI_Type_get_name
#pragma weak pmpi_type_get_name__=_PMPI_Type_get_name

#ifdef IFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Type_get_name)(int *,char *,int *, int *,int);
#elif GFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Type_get_name)(int *,char *, int,int *, int *);
#endif
#ifdef IFORT_CALL
A_f_MPI_Type_get_name(int * datatype,char * type_name, int *resultlen, int *ret, int type_name_len)
#elif GFORT_CALL
A_f_MPI_Type_get_name(int * datatype,char * type_name, int type_name_len, int *resultlen, int *ret)
#endif
{
#ifdef DEBUG
printf("entre : f_MPI_Type_get_name (interface) \n");
#endif
#ifdef IFORT_CALL
INTERFACE_F_LOCAL_MPI_Type_get_name(datatype, type_name, resultlen, ret, type_name_len);
#elif GFORT_CALL
INTERFACE_F_LOCAL_MPI_Type_get_name(datatype, type_name, type_name_len, resultlen, ret);
#endif
#ifdef DEBUG
printf("sort : f_MPI_Type_get_name (interface) \n");
#endif
}

#ifdef IFORT_CALL

void  mpi_type_set_name_(int *,char *,int *,int);

void  mpi_type_set_name__(int *,char *,int *,int);

void  pmpi_type_set_name_(int *,char *,int *,int);

void  pmpi_type_set_name__(int *,char *,int *,int);

void  pmpi_type_set_name_(int *,char *,int *,int);

#elif GFORT_CALL

void  mpi_type_set_name_(int *,char *,int,int *);

void  mpi_type_set_name__(int *,char *,int,int *);

void  pmpi_type_set_name_(int *,char *,int,int *);

void  pmpi_type_set_name__(int *,char *,int,int *);

void  pmpi_type_set_name_(int *,char *,int,int *);


#endif
#define A_f_MPI_Type_set_name _PMPI_Type_set_name
#pragma weak mpi_type_set_name_=_PMPI_Type_set_name
#pragma weak mpi_type_set_name__=_PMPI_Type_set_name
#pragma weak pmpi_type_set_name__=_PMPI_Type_set_name

#ifdef IFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Type_set_name)(int *,char *,int *,int);
#elif GFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Type_set_name)(int *,char *,int,int *);
#endif
#ifdef IFORT_CALL
A_f_MPI_Type_set_name(int * datatype,char * type_name, int *ret, int type_name_len)
#elif GFORT_CALL
A_f_MPI_Type_set_name(int * datatype,char * type_name, int type_name_len, int *ret)
#endif
{
#ifdef DEBUG
printf("entre : f_MPI_Type_set_name (interface) \n");
#endif
#ifdef IFORT_CALL
INTERFACE_F_LOCAL_MPI_Type_set_name(datatype, type_name, ret, type_name_len);
#elif GFORT_CALL
INTERFACE_F_LOCAL_MPI_Type_set_name(datatype, type_name, type_name_len, ret);
#endif
#ifdef DEBUG
printf("sort : f_MPI_Type_set_name (interface) \n");
#endif
}

#ifdef IFORT_CALL

void  mpi_add_error_string_(int *,char *,int *,int);

void  mpi_add_error_string__(int *,char *,int *,int);

void  pmpi_add_error_string_(int *,char *,int *,int);

void  pmpi_add_error_string__(int *,char *,int *,int);

void  pmpi_add_error_string_(int *,char *,int *,int);

#elif GFORT_CALL

void  mpi_add_error_string_(int *,char *,int,int *);

void  mpi_add_error_string__(int *,char *,int,int *);

void  pmpi_add_error_string_(int *,char *,int,int *);

void  pmpi_add_error_string__(int *,char *,int,int *);

void  pmpi_add_error_string_(int *,char *,int,int *);


#endif
#define A_f_MPI_Add_error_string _PMPI_Add_error_string
#pragma weak mpi_add_error_string_=_PMPI_Add_error_string
#pragma weak mpi_add_error_string__=_PMPI_Add_error_string
#pragma weak pmpi_add_error_string__=_PMPI_Add_error_string

#ifdef IFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Add_error_string)(int *,char *,int *,int);
#elif GFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Add_error_string)(int *,char *,int,int *);
#endif
#ifdef IFORT_CALL
A_f_MPI_Add_error_string(int * errorcode,char * string, int *ret, int string_len)
#elif GFORT_CALL
A_f_MPI_Add_error_string(int * errorcode,char * string, int string_len, int *ret)
#endif
{
#ifdef DEBUG
printf("entre : f_MPI_Add_error_string (interface) \n");
#endif
#ifdef IFORT_CALL
INTERFACE_F_LOCAL_MPI_Add_error_string(errorcode, string, ret, string_len);
#elif GFORT_CALL
INTERFACE_F_LOCAL_MPI_Add_error_string(errorcode, string, string_len, ret);
#endif
#ifdef DEBUG
printf("sort : f_MPI_Add_error_string (interface) \n");
#endif
}

#ifdef IFORT_CALL

void  mpi_close_port_(char *,int *,int);

void  mpi_close_port__(char *,int *,int);

void  pmpi_close_port_(char *,int *,int);

void  pmpi_close_port__(char *,int *,int);

void  pmpi_close_port_(char *,int *,int);

#elif GFORT_CALL

void  mpi_close_port_(char * ,int,int *);

void  mpi_close_port__(char * ,int,int *);

void  pmpi_close_port_(char * ,int,int *);

void  pmpi_close_port__(char * ,int,int *);

void  pmpi_close_port_(char * ,int,int *);


#endif
#define A_f_MPI_Close_port _PMPI_Close_port
#pragma weak mpi_close_port_=_PMPI_Close_port
#pragma weak mpi_close_port__=_PMPI_Close_port
#pragma weak pmpi_close_port__=_PMPI_Close_port

#ifdef IFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Close_port)(char *,int *,int);
#elif GFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Close_port)(char *,int,int *);
#endif
#ifdef IFORT_CALL
A_f_MPI_Close_port(char * string, int *ret, int string_len)
#elif GFORT_CALL
A_f_MPI_Close_port(char * string, int string_len, int *ret)
#endif
{
#ifdef DEBUG
printf("entre : f_MPI_Close_port (interface) \n");
#endif
#ifdef IFORT_CALL
INTERFACE_F_LOCAL_MPI_Close_port(string, ret, string_len);
#elif GFORT_CALL
INTERFACE_F_LOCAL_MPI_Close_port(string, string_len, ret);
#endif
#ifdef DEBUG
printf("sort : f_MPI_Close_port (interface) \n");
#endif
}

#ifdef IFORT_CALL

void  mpi_get_library_version_(char *, int*, int*, int);

void  mpi_get_library_version__(char *, int*, int*, int);

void  pmpi_get_library_version_(char *, int*, int*, int);

void  pmpi_get_library_version__(char *, int*, int*, int);

void  pmpi_get_library_version_(char *, int*, int*, int);

#elif GFORT_CALL

void  mpi_get_library_version_(char *, int*, int*, int);

void  mpi_get_library_version__(char *, int*, int*, int);

void  pmpi_get_library_version_(char *, int*, int*, int);

void  pmpi_get_library_version__(char *, int*, int*, int);

void  pmpi_get_library_version_(char *, int*, int*, int);


#endif
#define A_f_MPI_Get_library_version _PMPI_Get_library_version
#pragma weak mpi_get_library_version_=_PMPI_Get_library_version
#pragma weak mpi_get_library_version__=_PMPI_Get_library_version
#pragma weak pmpi_get_library_version__=_PMPI_Get_library_version

#ifdef IFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Get_library_version)(char *, int*, int*, int);
#elif GFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Get_library_version)(char *, int*, int*, int);
#endif
#ifdef IFORT_CALL
A_f_MPI_Get_library_version(char * version, int *resultlen, int *ret, int version_len)
#elif GFORT_CALL
A_f_MPI_Get_library_version(char * version, int version_len, int *resultlen, int *ret)
#endif
{
#ifdef DEBUG
printf("entre : f_MPI_Get_library_version (interface) \n");
#endif
#ifdef IFORT_CALL
INTERFACE_F_LOCAL_MPI_Get_library_version(version, resultlen,ret, version_len);
#elif GFORT_CALL
INTERFACE_F_LOCAL_MPI_Get_library_version(version, version_len,resultlen, ret);
#endif
#ifdef DEBUG
printf("sort : f_MPI_Get_library_version (interface) \n");
#endif
}

#ifdef IFORT_CALL

void  mpi_open_port_(int *,char*,int*,int);

void  mpi_open_port__(int *,char*,int*,int);

void  pmpi_open_port_(int *,char*,int*,int);

void  pmpi_open_port__(int *,char*,int*,int);

void  pmpi_open_port_(int *,char*,int*,int);

#elif GFORT_CALL

void  mpi_open_port_(int *,char*,int,int*);

void  mpi_open_port__(int *,char*,int,int*);

void  pmpi_open_port_(int *,char*,int,int*);

void  pmpi_open_port__(int *,char*,int,int*);

void  pmpi_open_port_(int *,char*,int,int*);


#endif
#define A_f_MPI_Open_port _PMPI_Open_port
#pragma weak mpi_open_port_=_PMPI_Open_port
#pragma weak mpi_open_port__=_PMPI_Open_port
#pragma weak pmpi_open_port__=_PMPI_Open_port

#ifdef IFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Open_port)(int *,char*,int*,int);
#elif GFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Open_port)(int *,char*,int,int*);
#endif
#ifdef IFORT_CALL
A_f_MPI_Open_port(int * info, char *port_name, int *ret, int port_name_len)
#elif GFORT_CALL
A_f_MPI_Open_port(int * info, char *port_name, int port_name_len, int *ret)
#endif
{
#ifdef DEBUG
printf("entre : f_MPI_Open_port (interface) \n");
#endif
#ifdef IFORT_CALL
INTERFACE_F_LOCAL_MPI_Open_port(info, port_name, ret, port_name_len);
#elif GFORT_CALL
INTERFACE_F_LOCAL_MPI_Open_port(info, port_name, port_name_len, ret);
#endif
#ifdef DEBUG
printf("sort : f_MPI_Open_port (interface) \n");
#endif
}

#ifdef IFORT_CALL

void  mpi_publish_name_(char*,int*,char*,int*,int,int);

void  mpi_publish_name__(char*,int*,char*,int*,int,int);

void  pmpi_publish_name_(char*,int*,char*,int*,int,int);

void  pmpi_publish_name__(char*,int*,char*,int*,int,int);

void  pmpi_publish_name_(char*,int*,char*,int*,int,int);

#elif GFORT_CALL

void  mpi_publish_name_(char*,int,int*,char*,int,int*);

void  mpi_publish_name__(char*,int,int*,char*,int,int*);

void  pmpi_publish_name_(char*,int,int*,char*,int,int*);

void  pmpi_publish_name__(char*,int,int*,char*,int,int*);

void  pmpi_publish_name_(char*,int,int*,char*,int,int*);


#endif
#define A_f_MPI_Publish_name _PMPI_Publish_name
#pragma weak mpi_publish_name_=_PMPI_Publish_name
#pragma weak mpi_publish_name__=_PMPI_Publish_name
#pragma weak pmpi_publish_name__=_PMPI_Publish_name

#ifdef IFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Publish_name)(char*,int*,char*,int*,int,int);
#elif GFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Publish_name)(char*,int,int*,char*,int,int*);
#endif
#ifdef IFORT_CALL
A_f_MPI_Publish_name(char *service_name, int *info, char *port_name, int *ret, int service_name_len, int port_name_len)
#elif GFORT_CALL
A_f_MPI_Publish_name(char *service_name, int service_name_len, int *info, char *port_name, int port_name_len, int *ret)
#endif
{
#ifdef DEBUG
printf("entre : f_MPI_Publish_name (interface) \n");
#endif
#ifdef IFORT_CALL
INTERFACE_F_LOCAL_MPI_Publish_name(service_name, info, port_name, ret,service_name_len, port_name_len);
#elif GFORT_CALL
INTERFACE_F_LOCAL_MPI_Publish_name(service_name,service_name_len , info, port_name, port_name_len, ret);
#endif
#ifdef DEBUG
printf("sort : f_MPI_Publish_name (interface) \n");
#endif
}

#ifdef IFORT_CALL

void  mpi_unpublish_name_(char*,int*,char*,int*,int,int);

void  mpi_unpublish_name__(char*,int*,char*,int*,int,int);

void  pmpi_unpublish_name_(char*,int*,char*,int*,int,int);

void  pmpi_unpublish_name__(char*,int*,char*,int*,int,int);

void  pmpi_unpublish_name_(char*,int*,char*,int*,int,int);

#elif GFORT_CALL

void  mpi_unpublish_name_(char*,int,int*,char*,int,int*);

void  mpi_unpublish_name__(char*,int,int*,char*,int,int*);

void  pmpi_unpublish_name_(char*,int,int*,char*,int,int*);

void  pmpi_unpublish_name__(char*,int,int*,char*,int,int*);

void  pmpi_unpublish_name_(char*,int,int*,char*,int,int*);


#endif
#define A_f_MPI_Unpublish_name _PMPI_Unpublish_name
#pragma weak mpi_unpublish_name_=_PMPI_Unpublish_name
#pragma weak mpi_unpublish_name__=_PMPI_Unpublish_name
#pragma weak pmpi_unpublish_name__=_PMPI_Unpublish_name

#ifdef IFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Unpublish_name)(char*,int*,char*,int*,int,int);
#elif GFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Unpublish_name)(char*,int,int*,char*,int,int*);
#endif
#ifdef IFORT_CALL
A_f_MPI_Unpublish_name(char *service_name, int *info, char *port_name, int *ret, int service_name_len, int port_name_len)
#elif GFORT_CALL
A_f_MPI_Unpublish_name(char *service_name, int service_name_len, int *info, char *port_name, int port_name_len, int *ret)
#endif
{
#ifdef DEBUG
printf("entre : f_MPI_Unpublish_name (interface) \n");
#endif
#ifdef IFORT_CALL
INTERFACE_F_LOCAL_MPI_Unpublish_name(service_name, info, port_name, ret,service_name_len, port_name_len);
#elif GFORT_CALL
INTERFACE_F_LOCAL_MPI_Unpublish_name(service_name,service_name_len , info, port_name, port_name_len, ret);
#endif
#ifdef DEBUG
printf("sort : f_MPI_Unpublish_name (interface) \n");
#endif
}

#ifdef IFORT_CALL

void  mpi_win_set_name_(int *, char *, int*, int);

void  mpi_win_set_name__(int *, char *, int*, int);

void  pmpi_win_set_name_(int *, char *, int*, int);

void  pmpi_win_set_name__(int *, char *, int*, int);

void  pmpi_win_set_name_(int *, char *, int*, int);

#elif GFORT_CALL

void  mpi_win_set_name_(int *, char *, int, int*);

void  mpi_win_set_name__(int *, char *, int, int*);

void  pmpi_win_set_name_(int *, char *, int, int*);

void  pmpi_win_set_name__(int *, char *, int, int*);

void  pmpi_win_set_name_(int *, char *, int, int*);


#endif
#define A_f_MPI_Win_set_name _PMPI_Win_set_name
#pragma weak mpi_win_set_name_=_PMPI_Win_set_name
#pragma weak mpi_win_set_name__=_PMPI_Win_set_name
#pragma weak pmpi_win_set_name__=_PMPI_Win_set_name

#ifdef IFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Win_set_name)(int *, char *, int*, int);
#elif GFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Win_set_name)(int *, char *, int, int*);
#endif
#ifdef IFORT_CALL
A_f_MPI_Win_set_name(int *win, char *win_name, int *ret, int win_name_len)
#elif GFORT_CALL
A_f_MPI_Win_set_name(int *win, char *win_name, int win_name_len, int *ret)
#endif
{
#ifdef DEBUG
printf("entre : f_MPI_Win_set_name (interface) \n");
#endif
#ifdef IFORT_CALL
INTERFACE_F_LOCAL_MPI_Win_set_name(win, win_name, ret, win_name_len);
#elif GFORT_CALL
INTERFACE_F_LOCAL_MPI_Win_set_name(win, win_name, win_name_len, ret);
#endif
#ifdef DEBUG
printf("sort : f_MPI_Win_set_name (interface) \n");
#endif
}

#ifdef IFORT_CALL

void  mpi_lookup_name_(char *, int*, char *, int*, int, int);

void  mpi_lookup_name__(char *, int*, char *, int*, int, int);

void  pmpi_lookup_name_(char *, int*, char *, int*, int, int);

void  pmpi_lookup_name__(char *, int*, char *, int*, int, int);

void  pmpi_lookup_name_(char *, int*, char *, int*, int, int);

#elif GFORT_CALL

void  mpi_lookup_name_(char *, int, int*, char *, int, int*);

void  mpi_lookup_name__(char *, int, int*, char *, int, int*);

void  pmpi_lookup_name_(char *, int, int*, char *, int, int*);

void  pmpi_lookup_name__(char *, int, int*, char *, int, int*);

void  pmpi_lookup_name_(char *, int, int*, char *, int, int*);


#endif
#define A_f_MPI_Lookup_name _PMPI_Lookup_name
#pragma weak mpi_lookup_name_=_PMPI_Lookup_name
#pragma weak mpi_lookup_name__=_PMPI_Lookup_name
#pragma weak pmpi_lookup_name__=_PMPI_Lookup_name

#ifdef IFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Lookup_name)(char *, int*, char *, int*, int, int);
#elif GFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Lookup_name)(char *, int, int*, char *, int, int*);
#endif
#ifdef IFORT_CALL
A_f_MPI_Lookup_name(char *service_name, int *info, char *port_name, int *ret, int service_name_len, int port_name_len)
#elif GFORT_CALL
A_f_MPI_Lookup_name(char *service_name, int service_name_len, int *info, char *port_name, int port_name_len, int *ret)
#endif
{
#ifdef DEBUG
printf("entre : f_MPI_Lookup_name (interface) \n");
#endif
#ifdef IFORT_CALL
INTERFACE_F_LOCAL_MPI_Lookup_name(service_name, info, port_name, ret, service_name_len, port_name_len);
#elif GFORT_CALL
INTERFACE_F_LOCAL_MPI_Lookup_name(service_name, service_name_len, info, port_name, port_name_len, ret);
#endif
#ifdef DEBUG
printf("sort : f_MPI_Lookup_name (interface) \n");
#endif
}

#ifdef IFORT_CALL

void  mpi_pack_external_(char *, void*, int, int*, void*, size_t, size_t *, int*,int);

void  mpi_pack_external__(char *, void*, int, int*, void*, size_t, size_t *, int*,int);

void  pmpi_pack_external_(char *, void*, int, int*, void*, size_t, size_t *, int*,int);

void  pmpi_pack_external__(char *, void*, int, int*, void*, size_t, size_t *, int*,int);

void  pmpi_pack_external_(char *, void*, int, int*, void*, size_t, size_t *, int*,int);

#elif GFORT_CALL

void  mpi_pack_external_(char *,int, void*, int, int*, void*, size_t, size_t *, int*);

void  mpi_pack_external__(char *,int, void*, int, int*, void*, size_t, size_t *, int*);

void  pmpi_pack_external_(char *,int, void*, int, int*, void*, size_t, size_t *, int*);

void  pmpi_pack_external__(char *,int, void*, int, int*, void*, size_t, size_t *, int*);

void  pmpi_pack_external_(char *,int, void*, int, int*, void*, size_t, size_t *, int*);


#endif
#define A_f_MPI_Pack_external _PMPI_Pack_external
#pragma weak mpi_pack_external_=_PMPI_Pack_external
#pragma weak mpi_pack_external__=_PMPI_Pack_external
#pragma weak pmpi_pack_external__=_PMPI_Pack_external

#ifdef IFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Pack_external)(char *, void*, int, int*, void*, size_t, size_t *, int*,int);
#elif GFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Pack_external)(char *,int, void*, int, int*, void*, size_t, size_t *, int*);
#endif
#ifdef IFORT_CALL
A_f_MPI_Pack_external(char *datarep, void *inbuf, int count, int *datatype, void *outbuf, size_t outsize, size_t *position, int *ret, int datarep_len)
#elif GFORT_CALL
A_f_MPI_Pack_external(char *datarep, int datarep_len, void *inbuf, int count, int *datatype, void *outbuf, size_t outsize, size_t *position, int *ret)
#endif
{
#ifdef DEBUG
printf("entre : f_MPI_Pack_external (interface) \n");
#endif
#ifdef IFORT_CALL
INTERFACE_F_LOCAL_MPI_Pack_external(datarep, inbuf, count, datatype, outbuf, outsize, position, ret, datarep_len);
#elif GFORT_CALL
INTERFACE_F_LOCAL_MPI_Pack_external(datarep, datarep_len, inbuf, count, datatype, outbuf, outsize, position, ret);
#endif
#ifdef DEBUG
printf("sort : f_MPI_Pack_external (interface) \n");
#endif
}

#ifdef IFORT_CALL

void  mpi_pack_external_size_(char *, int, int *, size_t *, int *,int);

void  mpi_pack_external_size__(char *, int, int *, size_t *, int *,int);

void  pmpi_pack_external_size_(char *, int, int *, size_t *, int *,int);

void  pmpi_pack_external_size__(char *, int, int *, size_t *, int *,int);

void  pmpi_pack_external_size_(char *, int, int *, size_t *, int *,int);

#elif GFORT_CALL

void  mpi_pack_external_size_(char *,int, int, int *, size_t *, int *);

void  mpi_pack_external_size__(char *,int, int, int *, size_t *, int *);

void  pmpi_pack_external_size_(char *,int, int, int *, size_t *, int *);

void  pmpi_pack_external_size__(char *,int, int, int *, size_t *, int *);

void  pmpi_pack_external_size_(char *,int, int, int *, size_t *, int *);


#endif
#define A_f_MPI_Pack_external_size _PMPI_Pack_external_size
#pragma weak mpi_pack_external_size_=_PMPI_Pack_external_size
#pragma weak mpi_pack_external_size__=_PMPI_Pack_external_size
#pragma weak pmpi_pack_external_size__=_PMPI_Pack_external_size

#ifdef IFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Pack_external_size)(char *, int, int *, size_t *, int *,int);
#elif GFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Pack_external_size)(char *,int, int, int *, size_t *, int *);
#endif
#ifdef IFORT_CALL
A_f_MPI_Pack_external_size(char *datarep, int count, int *datatype, size_t *size, int *ret, int datarep_len)
#elif GFORT_CALL
A_f_MPI_Pack_external_size(char *datarep, int datarep_len, int count, int *datatype, size_t *size, int *ret)
#endif
{
#ifdef DEBUG
printf("entre : f_MPI_Pack_external_size (interface) \n");
#endif
#ifdef IFORT_CALL
INTERFACE_F_LOCAL_MPI_Pack_external_size(datarep, count, datatype, size, ret, datarep_len);
#elif GFORT_CALL
INTERFACE_F_LOCAL_MPI_Pack_external_size(datarep, datarep_len, count, datatype, size, ret);
#endif
#ifdef DEBUG
printf("sort : f_MPI_Pack_external_size (interface) \n");
#endif
}

#ifdef IFORT_CALL

void  mpi_unpack_external_(char *, void *, size_t, size_t *, void *, int, int *, int *,int);

void  mpi_unpack_external__(char *, void *, size_t, size_t *, void *, int, int *, int *,int);

void  pmpi_unpack_external_(char *, void *, size_t, size_t *, void *, int, int *, int *,int);

void  pmpi_unpack_external__(char *, void *, size_t, size_t *, void *, int, int *, int *,int);

void  pmpi_unpack_external_(char *, void *, size_t, size_t *, void *, int, int *, int *,int);

#elif GFORT_CALL

void  mpi_unpack_external_(char *,int, void *, size_t, size_t *, void *, int, int *, int *);

void  mpi_unpack_external__(char *,int, void *, size_t, size_t *, void *, int, int *, int *);

void  pmpi_unpack_external_(char *,int, void *, size_t, size_t *, void *, int, int *, int *);

void  pmpi_unpack_external__(char *,int, void *, size_t, size_t *, void *, int, int *, int *);

void  pmpi_unpack_external_(char *,int, void *, size_t, size_t *, void *, int, int *, int *);


#endif
#define A_f_MPI_Unpack_external _PMPI_Unpack_external
#pragma weak mpi_unpack_external_=_PMPI_Unpack_external
#pragma weak mpi_unpack_external__=_PMPI_Unpack_external
#pragma weak pmpi_unpack_external__=_PMPI_Unpack_external

#ifdef IFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Unpack_external)(char *, void *, size_t, size_t *, void *, int, int *, int *,int);
#elif GFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Unpack_external)(char *,int, void *, size_t, size_t *, void *, int, int *, int *);
#endif
#ifdef IFORT_CALL
A_f_MPI_Unpack_external(char *datarep, void *inbuf, size_t insize, size_t *position, void *outbuf, int outcount, int *datatype, int *ret, int datarep_len)
#elif GFORT_CALL
A_f_MPI_Unpack_external(char *datarep, int datarep_len, void *inbuf, size_t insize, size_t *position, void *outbuf, int outcount, int *datatype, int *ret)
#endif
{
#ifdef DEBUG
printf("entre : f_MPI_Unpack_external (interface) \n");
#endif
#ifdef IFORT_CALL
INTERFACE_F_LOCAL_MPI_Unpack_external(datarep, inbuf, insize, position, outbuf, outcount, datatype, ret, datarep_len);
#elif GFORT_CALL
INTERFACE_F_LOCAL_MPI_Unpack_external(datarep, datarep_len, inbuf, insize, position, outbuf, outcount, datatype, ret);
#endif
#ifdef DEBUG
printf("sort : f_MPI_Unpack_external (interface) \n");
#endif
}

#ifdef IFORT_CALL

void  mpi_info_delete_(int *,char *,int *, int);

void  mpi_info_delete__(int *,char *,int *, int);

void  pmpi_info_delete_(int *,char *,int *, int);

void  pmpi_info_delete__(int *,char *,int *, int);

void  pmpi_info_delete_(int *,char *,int *, int);

#elif GFORT_CALL

void  mpi_info_delete_(int *,char *, int,int *);

void  mpi_info_delete__(int *,char *, int,int *);

void  pmpi_info_delete_(int *,char *, int,int *);

void  pmpi_info_delete__(int *,char *, int,int *);

void  pmpi_info_delete_(int *,char *, int,int *);


#endif
#define A_f_MPI_Info_delete _PMPI_Info_delete
#pragma weak mpi_info_delete_=_PMPI_Info_delete
#pragma weak mpi_info_delete__=_PMPI_Info_delete
#pragma weak pmpi_info_delete__=_PMPI_Info_delete

#ifdef IFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Info_delete)(int *,char *,int *, int);
#elif GFORT_CALL
void (*INTERFACE_F_LOCAL_MPI_Info_delete)(int *,char *, int,int *);
#endif
#ifdef IFORT_CALL
A_f_MPI_Info_delete(int * info,char * key,int * ret,int keylen)
#elif GFORT_CALL
A_f_MPI_Info_delete(int * info,char * key,int keylen,int * ret)
#endif
{
#ifdef DEBUG
printf("entre : f_MPI_Info_delete (interface) \n");
#endif
#ifdef IFORT_CALL
INTERFACE_F_LOCAL_MPI_Info_delete(info, key, ret,keylen);
#elif GFORT_CALL
INTERFACE_F_LOCAL_MPI_Info_delete(info, key, keylen,ret);
#endif
#ifdef DEBUG
printf("sort : f_MPI_Info_delete (interface) \n");
#endif
}
#endif /*MANUAL_WRAPPER_H*/
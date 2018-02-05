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

#ifndef FUNC_CHAR_FORT
#define FUNC_CHAR_FORT

#if defined(IFORT_CALL) || defined(PGI_CALL) || defined(FLANG_CALL)
void (*_LOCAL_MPI_Get_processor_name)(char *,int *,int *i,int);
#elif defined(GFORT_CALL)
void (*_LOCAL_MPI_Get_processor_name)(char *,int,int *,int *i);
#endif
#if defined(IFORT_CALL) || defined(PGI_CALL) || defined(FLANG_CALL)
void  (*_LOCAL_MPI_Error_string)(int * errorcode,char * string,int * resultlen,int * ret,int reslen);
#elif defined(GFORT_CALL)
void  (*_LOCAL_MPI_Error_string)(int * errorcode,int reslen,char * string,int * resultlen,int * ret);
#endif
#if defined(IFORT_CALL) || defined(PGI_CALL) || defined(FLANG_CALL)
void (*_LOCAL_MPI_File_open)(int *, char*, int*, int*, int*,int*, int);
#elif defined(GFORT_CALL)
void (*_LOCAL_MPI_File_open)(int *, char*, int, int*, int*,int*, int*);
#endif
#if defined(IFORT_CALL) || defined(PGI_CALL) || defined(FLANG_CALL)
void  (*_LOCAL_MPI_File_set_view)(int *,int*,int *,int *,char *,int *,int *,int);
#elif defined(GFORT_CALL)
void  (*_LOCAL_MPI_File_set_view)(int *,int*,int *,int *,char *,int,int *,int *);
#endif
#if defined(IFORT_CALL) || defined(PGI_CALL) || defined(FLANG_CALL)
void  (*_LOCAL_MPI_File_get_view)(int *,int*,int *,int *,char *,int*,int );
#elif defined(GFORT_CALL)
void  (*_LOCAL_MPI_File_get_view)(int *,int*,int *,int *,char *,int, int* );
#endif
#if defined(IFORT_CALL) || defined(PGI_CALL) || defined(FLANG_CALL)
void  (*_LOCAL_MPI_File_delete)(char *,int *,int *,int);
#elif defined(GFORT_CALL)
void  (*_LOCAL_MPI_File_delete)(char *,int,int *,int *);
#endif
#if defined(IFORT_CALL) || defined(PGI_CALL) || defined(FLANG_CALL)
void  (*_LOCAL_MPI_Info_delete)(int *,char *,int *,int);
#elif defined(GFORT_CALL)
void  (*_LOCAL_MPI_Info_delete)(int *,char *,int,int *);
#endif
#if defined(IFORT_CALL) || defined(PGI_CALL) || defined(FLANG_CALL)
void  (*_LOCAL_MPI_Info_get)(int *,char *,int *,char *,int *,int *,int,int);
#elif defined(GFORT_CALL)
void  (*_LOCAL_MPI_Info_get)(int *,char *,int ,int *,char *,int,int *,int *);
#endif
#if defined(IFORT_CALL) || defined(PGI_CALL) || defined(FLANG_CALL)
void  (*_LOCAL_MPI_Info_get_nthkey)(int *,int *,char *,int *,int);
#elif defined(GFORT_CALL)
void  (*_LOCAL_MPI_Info_get_nthkey)(int *,int *,char *,int,int *);
#endif
#if defined(IFORT_CALL) || defined(PGI_CALL) || defined(FLANG_CALL)
void  (*_LOCAL_MPI_Info_get_valuelen)(int *,char *,int *,int *,int *,int);
#elif defined(GFORT_CALL)
void  (*_LOCAL_MPI_Info_get_valuelen)(int *,char *,int,int *,int *,int *);
#endif
#if defined(IFORT_CALL) || defined(PGI_CALL) || defined(FLANG_CALL)
void  (*_LOCAL_MPI_Info_set)(int *,char *,char *,int *,int,int);
#elif defined(GFORT_CALL)
void  (*_LOCAL_MPI_Info_set)(int *,char *,int,char *,int,int *);
#endif
#if defined(IFORT_CALL) || defined(PGI_CALL) || defined(FLANG_CALL)
void  (*_LOCAL_MPI_Win_get_name)(int *,char *,int *,int*,int);
#elif defined(GFORT_CALL)
void  (*_LOCAL_MPI_Win_get_name)(int *,char *,int, int *,int *);
#endif
#if defined(IFORT_CALL) || defined(PGI_CALL) || defined(FLANG_CALL)
void  (*_LOCAL_MPI_Comm_get_name)(int *,char *,int *,int*,int);
#elif defined(GFORT_CALL)
void  (*_LOCAL_MPI_Comm_get_name)(int *,char *,int, int *,int *);
#endif
#if defined(IFORT_CALL) || defined(PGI_CALL) || defined(FLANG_CALL)
void  (*_LOCAL_MPI_Comm_set_name)(int *,char *,int *,int);
#elif defined(GFORT_CALL)
void  (*_LOCAL_MPI_Comm_set_name)(int *,char *,int,int *);
#endif
#if defined(IFORT_CALL) || defined(PGI_CALL) || defined(FLANG_CALL)
void  (*_LOCAL_MPI_Comm_spawn)(char *, char *, int *, int *, int *, int *, int *, int*, int*, int, int);
#elif defined(GFORT_CALL)
void  (*_LOCAL_MPI_Comm_spawn)(char *, int, char *, int, int *, int *, int *, int *, int *, int*, int*);
#endif
#if defined(IFORT_CALL) || defined(PGI_CALL) || defined(FLANG_CALL)
void  (*_LOCAL_MPI_Type_get_name)(int *,char *,int *,int*,int);
#elif defined(GFORT_CALL)
void  (*_LOCAL_MPI_Type_get_name)(int *,char *,int, int *,int *);
#endif
#if defined(IFORT_CALL) || defined(PGI_CALL) || defined(FLANG_CALL)
void  (*_LOCAL_MPI_Type_set_name)(int *,char *,int*,int);
#elif defined(GFORT_CALL)
void  (*_LOCAL_MPI_Type_set_name)(int *,char *,int, int *);
#endif
#if defined(IFORT_CALL) || defined(PGI_CALL) || defined(FLANG_CALL)
void  (*_LOCAL_MPI_Add_error_string)(int *,char *,int*,int);
#elif defined(GFORT_CALL)
void  (*_LOCAL_MPI_Add_error_string)(int *,char *,int, int *);
#endif
#if defined(IFORT_CALL) || defined(PGI_CALL) || defined(FLANG_CALL)
void  (*_LOCAL_MPI_Close_port)(char *,int*,int);
#elif defined(GFORT_CALL)
void  (*_LOCAL_MPI_Close_port)(char *,int, int *);
#endif
#if defined(IFORT_CALL) || defined(PGI_CALL) || defined(FLANG_CALL)
void  (*_LOCAL_MPI_Get_library_version)(char *,int*,int*,int);
#elif defined(GFORT_CALL)
void  (*_LOCAL_MPI_Get_library_version)(char *,int, int *,int *);
#endif
#if defined(IFORT_CALL) || defined(PGI_CALL) || defined(FLANG_CALL)
void  (*_LOCAL_MPI_Open_port)(int *,char*, int*,int);
#elif defined(GFORT_CALL)
void  (*_LOCAL_MPI_Open_port)(int *,char*, int,int*);
#endif
#if defined(IFORT_CALL) || defined(PGI_CALL) || defined(FLANG_CALL)
void  (*_LOCAL_MPI_Publish_name)(char *,int*, char*,int*,int,int);
#elif defined(GFORT_CALL)
void  (*_LOCAL_MPI_Publish_name)(char *, int, int*, char,int,int*);
#endif
#if defined(IFORT_CALL) || defined(PGI_CALL) || defined(FLANG_CALL)
void  (*_LOCAL_MPI_Unpublish_name)(char *,int*, char*,int*,int,int);
#elif defined(GFORT_CALL)
void  (*_LOCAL_MPI_Unpublish_name)(char *, int, int*, char,int,int*);
#endif
#if defined(IFORT_CALL) || defined(PGI_CALL) || defined(FLANG_CALL)
void  (*_LOCAL_MPI_Win_set_name)(int *, char *, int*, int);
#elif defined(GFORT_CALL)
void  (*_LOCAL_MPI_Win_set_name)(int *, char *,int,  int*);
#endif
#if defined(IFORT_CALL) || defined(PGI_CALL) || defined(FLANG_CALL)
void  (*_LOCAL_MPI_Lookup_name)(char*, int*, char *, int*, int, int);
#elif defined(GFORT_CALL)
void  (*_LOCAL_MPI_Lookup_name)(char*, int, int *, char*, int ,int*);
#endif
#if defined(IFORT_CALL) || defined(PGI_CALL) || defined(FLANG_CALL)
void  (*_LOCAL_MPI_Pack_external)(char *, void*, int, int*, void*, size_t, size_t *, int *, int);
#elif defined(GFORT_CALL)
void  (*_LOCAL_MPI_Pack_external)(char *, int, void*, int, int*, void*, size_t, size_t *, int*);
#endif
#if defined(IFORT_CALL) || defined(PGI_CALL) || defined(FLANG_CALL)
void  (*_LOCAL_MPI_Pack_external_size)(char *, int, int *, size_t *, int *, int);
#elif defined(GFORT_CALL)
void  (*_LOCAL_MPI_Pack_external_size)(char *, int, int, int *, size_t *, int *);
#endif
#if defined(IFORT_CALL) || defined(PGI_CALL) || defined(FLANG_CALL)
void  (*_LOCAL_MPI_Unpack_external)(char *, void *, size_t, size_t *, void *, int, int *, int *, int);
#elif defined(GFORT_CALL)
void  (*_LOCAL_MPI_Unpack_external)(char *, int, void *, size_t, size_t *, void *, int, int *, int *);
#endif

#endif /*FUNC_CHAR_FORT*/

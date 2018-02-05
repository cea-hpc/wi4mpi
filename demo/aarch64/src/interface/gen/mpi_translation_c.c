//############################# Wi4MPI License ###########################
//# `04/04/2016`                                                         #
//# Copyright or (C) or Copr. Commissariat a l'Energie Atomique         #
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
/*
 * This code is full generated
 */
#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#define allocate_global 1
#include <stdio.h>
#include <dlfcn.h>
#include "wrapper_f.h"
/*ompi constante*/
int WI4MPI_errhandler_key;
#if defined(OMPI_OMPI)
extern char ompi_mpi_comm_null;
extern char ompi_mpi_comm_self;
extern char ompi_mpi_comm_world;
extern char ompi_mpi_2cplex;
extern char ompi_mpi_2dblcplex;
extern char ompi_mpi_2dblprec;
extern char ompi_mpi_2int;
extern char ompi_mpi_2integer;
extern char ompi_mpi_2real;
extern char ompi_mpi_aint;
extern char ompi_mpi_byte;
extern char ompi_mpi_c_bool;
extern char ompi_mpi_c_complex;
extern char ompi_mpi_c_double_complex;
extern char ompi_mpi_c_float_complex;
extern char ompi_mpi_c_long_double_complex;
extern char ompi_mpi_char;
extern char ompi_mpi_character;
extern char ompi_mpi_complex16;
extern char ompi_mpi_complex32;
extern char ompi_mpi_complex8;
extern char ompi_mpi_cplex;
extern char ompi_mpi_cxx_bool;
extern char ompi_mpi_cxx_cplex;
extern char ompi_mpi_cxx_dblcplex;
extern char ompi_mpi_cxx_ldblcplex;
extern char ompi_mpi_datatype_null;
extern char ompi_mpi_dblcplex;
extern char ompi_mpi_dblprec;
extern char ompi_mpi_double;
extern char ompi_mpi_double_int;
extern char ompi_mpi_float;
extern char ompi_mpi_float_int;
extern char ompi_mpi_int16_t;
extern char ompi_mpi_int32_t;
extern char ompi_mpi_int64_t;
extern char ompi_mpi_int8_t;
extern char ompi_mpi_int;
extern char ompi_mpi_integer16;
extern char ompi_mpi_integer1;
extern char ompi_mpi_integer2;
extern char ompi_mpi_integer4;
extern char ompi_mpi_integer8;
extern char ompi_mpi_integer;
extern char ompi_mpi_lb;
extern char ompi_mpi_ldblcplex;
extern char ompi_mpi_logical1;
extern char ompi_mpi_logical2;
extern char ompi_mpi_logical4;
extern char ompi_mpi_logical8;
extern char ompi_mpi_logical;
extern char ompi_mpi_long;
extern char ompi_mpi_long_double;
extern char ompi_mpi_long_int;
extern char ompi_mpi_long_long_int;
extern char ompi_mpi_longdbl_int;
extern char ompi_mpi_offset;
extern char ompi_mpi_count;
extern char ompi_message_null;
extern char ompi_mpi_packed;
extern char ompi_mpi_real16;
extern char ompi_mpi_real2;
extern char ompi_mpi_real4;
extern char ompi_mpi_real8;
extern char ompi_mpi_real;
extern char ompi_mpi_short;
extern char ompi_mpi_short_int;
extern char ompi_mpi_signed_char;
extern char ompi_mpi_ub;
extern char ompi_mpi_uint16_t;
extern char ompi_mpi_uint32_t;
extern char ompi_mpi_uint64_t;
extern char ompi_mpi_uint8_t;
extern char ompi_mpi_unsigned;
extern char ompi_mpi_unsigned_char;
extern char ompi_mpi_unsigned_long;
extern char ompi_mpi_unsigned_long_long;
extern char ompi_mpi_unsigned_short;
extern char ompi_mpi_wchar;
extern char ompi_mpi_errhandler_null;
extern char ompi_mpi_errors_are_fatal;
extern char ompi_mpi_errors_return;
extern char ompi_mpi_file_null;
extern char ompi_mpi_group_empty;
extern char ompi_mpi_group_null;
extern char ompi_mpi_info_null;
extern char ompi_mpi_op_band;
extern char ompi_mpi_op_bor;
extern char ompi_mpi_op_bxor;
extern char ompi_mpi_op_land;
extern char ompi_mpi_op_lor;
extern char ompi_mpi_op_lxor;
extern char ompi_mpi_op_max;
extern char ompi_mpi_op_maxloc;
extern char ompi_mpi_op_min;
extern char ompi_mpi_op_minloc;
extern char ompi_mpi_op_null;
extern char ompi_mpi_op_prod;
extern char ompi_mpi_op_replace;
extern char ompi_mpi_op_sum;
extern char ompi_request_null;
extern char ompi_mpi_win_null;
extern char ompi_message_no_proc;
#endif
#if defined(OMPI_INTEL)
char ompi_mpi_comm_null[1024];
char ompi_mpi_comm_self[1024];
char ompi_mpi_comm_world[1024];
char ompi_mpi_2cplex[512];
char ompi_mpi_2dblcplex[512];
char ompi_mpi_2dblprec[512];
char ompi_mpi_2int[512];
char ompi_mpi_2integer[512];
char ompi_mpi_2real[512];
char ompi_mpi_aint[512];
char ompi_mpi_byte[512];
char ompi_mpi_c_bool[512];
char ompi_mpi_c_complex[512];
char ompi_mpi_c_double_complex[512];
char ompi_mpi_c_float_complex[512];
char ompi_mpi_c_long_double_complex[512];
char ompi_mpi_char[512];
char ompi_mpi_character[512];
char ompi_mpi_complex16[512];
char ompi_mpi_complex32[512];
char ompi_mpi_complex8[512];
char ompi_mpi_cplex[512];
char ompi_mpi_cxx_bool[512];
char ompi_mpi_cxx_cplex[512];
char ompi_mpi_cxx_dblcplex[512];
char ompi_mpi_cxx_ldblcplex[512];
char ompi_mpi_datatype_null[512];
char ompi_mpi_dblcplex[512];
char ompi_mpi_dblprec[512];
char ompi_mpi_double[512];
char ompi_mpi_double_int[512];
char ompi_mpi_float[512];
char ompi_mpi_float_int[512];
char ompi_mpi_int16_t[512];
char ompi_mpi_int32_t[512];
char ompi_mpi_int64_t[512];
char ompi_mpi_int8_t[512];
char ompi_mpi_int[512];
char ompi_mpi_integer16[512];
char ompi_mpi_integer1[512];
char ompi_mpi_integer2[512];
char ompi_mpi_integer4[512];
char ompi_mpi_integer8[512];
char ompi_mpi_integer[512];
char ompi_mpi_lb[512];
char ompi_mpi_ldblcplex[512];
char ompi_mpi_logical1[512];
char ompi_mpi_logical2[512];
char ompi_mpi_logical4[512];
char ompi_mpi_logical8[512];
char ompi_mpi_logical[512];
char ompi_mpi_long[512];
char ompi_mpi_long_double[512];
char ompi_mpi_long_int[512];
char ompi_mpi_long_long_int[512];
char ompi_mpi_longdbl_int[512];
char ompi_mpi_offset[512];
char ompi_mpi_count[512];
char ompi_message_null[512];
char ompi_mpi_packed[512];
char ompi_mpi_real16[512];
char ompi_mpi_real2[512];
char ompi_mpi_real4[512];
char ompi_mpi_real8[512];
char ompi_mpi_real[512];
char ompi_mpi_short[512];
char ompi_mpi_short_int[512];
char ompi_mpi_signed_char[512];
char ompi_mpi_ub[512];
char ompi_mpi_uint16_t[512];
char ompi_mpi_uint32_t[512];
char ompi_mpi_uint64_t[512];
char ompi_mpi_uint8_t[512];
char ompi_mpi_unsigned[512];
char ompi_mpi_unsigned_char[512];
char ompi_mpi_unsigned_long[512];
char ompi_mpi_unsigned_long_long[512];
char ompi_mpi_unsigned_short[512];
char ompi_mpi_wchar[512];
char ompi_mpi_errhandler_null[1024];
char ompi_mpi_errors_are_fatal[1024];
char ompi_mpi_errors_return[1024];
char ompi_mpi_file_null[1536];
char ompi_mpi_group_empty[256];
char ompi_mpi_group_null[256];
char ompi_mpi_info_null[256];
char ompi_mpi_op_band[2048];
char ompi_mpi_op_bor[2048];
char ompi_mpi_op_bxor[2048];
char ompi_mpi_op_land[2048];
char ompi_mpi_op_lor[2048];
char ompi_mpi_op_lxor[2048];
char ompi_mpi_op_max[2048];
char ompi_mpi_op_maxloc[2048];
char ompi_mpi_op_min[2048];
char ompi_mpi_op_minloc[2048];
char ompi_mpi_op_null[2048];
char ompi_mpi_op_prod[2048];
char ompi_mpi_op_replace[2048];
char ompi_mpi_op_sum[2048];
char ompi_request_null[256];
char ompi_mpi_win_null[512];
char ompi_message_no_proc[512];
#endif

#define EXTERN_ALLOCATED 1
#include "mappers.h"

//#include "c2f_f2c.h"
extern __thread int in_w;
int MPI_Send(void * buf,int count,A_MPI_Datatype datatype,int dest,int tag,A_MPI_Comm comm);
int (*LOCAL_MPI_Send)(void *,int,R_MPI_Datatype,int,int,R_MPI_Comm);

__asm__(
".global CCMPI_Send\n"
".weak MPI_Send\n"
".set MPI_Send,CCMPI_Send\n"
".extern in_w\n"
".extern A_MPI_Send\n"
".extern R_MPI_Send\n"
".type CCMPI_Send,@function\n"
".text\n"
"CCMPI_Send:\n"
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Send\n"
"b A_MPI_Send\n"
"inwrap_MPI_Send:\n"
"b R_MPI_Send\n"
);

int A_MPI_Send(void * buf,int count,A_MPI_Datatype datatype,int dest,int tag,A_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : A_MPI_Send\n");
#endif
in_w=1;

void * buf_tmp;
const_buffer_conv_a2r(&buf,&buf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
int dest_tmp;
dest_conv_a2r(&dest,&dest_tmp);
int tag_tmp;
tag_conv_a2r(&tag,&tag_tmp);
R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
int ret_tmp= LOCAL_MPI_Send( buf_tmp, count, datatype_tmp, dest_tmp, tag_tmp, comm_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Send\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Send(void * buf,int count,R_MPI_Datatype datatype,int dest,int tag,R_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : R_MPI_Send\n");
#endif
int ret_tmp= LOCAL_MPI_Send( buf, count, datatype, dest, tag, comm);
#ifdef DEBUG
printf("sort : R_MPI_Send\n");
#endif
return ret_tmp;
}
int MPI_Recv(void * buf,int count,A_MPI_Datatype datatype,int source,int tag,A_MPI_Comm comm,A_MPI_Status * status);
int (*LOCAL_MPI_Recv)(void *,int,R_MPI_Datatype,int,int,R_MPI_Comm,R_MPI_Status *);

__asm__(
".global CCMPI_Recv\n"
".weak MPI_Recv\n"
".set MPI_Recv,CCMPI_Recv\n"
".extern in_w\n"
".extern A_MPI_Recv\n"
".extern R_MPI_Recv\n"
".type CCMPI_Recv,@function\n"
".text\n"
"CCMPI_Recv:\n"
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Recv\n"
"b A_MPI_Recv\n"
"inwrap_MPI_Recv:\n"
"b R_MPI_Recv\n"
);

int A_MPI_Recv(void * buf,int count,A_MPI_Datatype datatype,int source,int tag,A_MPI_Comm comm,A_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : A_MPI_Recv\n");
#endif
in_w=1;

void * buf_tmp;
buffer_conv_a2r(&buf,&buf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
int source_tmp;
source_conv_a2r(&source,&source_tmp);
int tag_tmp;
tag_conv_a2r(&tag,&tag_tmp);
R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
R_MPI_Status  status_ltmp;
R_MPI_Status * status_tmp=&status_ltmp;
int ret_tmp= LOCAL_MPI_Recv( buf_tmp, count, datatype_tmp, source_tmp, tag_tmp, comm_tmp, status_tmp);
buffer_conv_r2a(&buf,&buf_tmp);
status_prt_conv_r2a(&status,&status_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Recv\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Recv(void * buf,int count,R_MPI_Datatype datatype,int source,int tag,R_MPI_Comm comm,R_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : R_MPI_Recv\n");
#endif
int ret_tmp= LOCAL_MPI_Recv( buf, count, datatype, source, tag, comm, status);
#ifdef DEBUG
printf("sort : R_MPI_Recv\n");
#endif
return ret_tmp;
}

int MPI_Alltoall(void * sendbuf,int sendcount,A_MPI_Datatype sendtype,void * recvbuf,int recvcount,A_MPI_Datatype recvtype,A_MPI_Comm comm);
int (*LOCAL_MPI_Alltoall)(void *,int,R_MPI_Datatype,void *,int,R_MPI_Datatype,R_MPI_Comm);


__asm__(
".global CCMPI_Alltoall\n"
".weak MPI_Alltoall\n"
".set MPI_Alltoall,CCMPI_Alltoall\n"
".extern in_w\n"
".extern A_MPI_Alltoall\n"
".extern R_MPI_Alltoall\n"
".type CCMPI_Alltoall,@function\n"
".text\n"
"CCMPI_Alltoall:\n"
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Alltoall\n"
"b A_MPI_Alltoall\n"
"inwrap_MPI_Alltoall:\n"
"b R_MPI_Alltoall\n"
);

int A_MPI_Alltoall(void * sendbuf,int sendcount,A_MPI_Datatype sendtype,void * recvbuf,int recvcount,A_MPI_Datatype recvtype,A_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : A_MPI_Alltoall\n");
#endif
in_w=1;

void * sendbuf_tmp;
const_buffer_conv_a2r(&sendbuf,&sendbuf_tmp);


R_MPI_Datatype sendtype_tmp;
datatype_conv_a2r(&sendtype,&sendtype_tmp);
void * recvbuf_tmp;
buffer_conv_a2r(&recvbuf,&recvbuf_tmp);


R_MPI_Datatype recvtype_tmp;
datatype_conv_a2r(&recvtype,&recvtype_tmp);
R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
int ret_tmp= LOCAL_MPI_Alltoall( sendbuf_tmp, sendcount, sendtype_tmp, recvbuf_tmp, recvcount, recvtype_tmp, comm_tmp);
buffer_conv_r2a(&recvbuf,&recvbuf_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Alltoall\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Alltoall(void * sendbuf,int sendcount,R_MPI_Datatype sendtype,void * recvbuf,int recvcount,R_MPI_Datatype recvtype,R_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : R_MPI_Alltoall\n");
#endif
int ret_tmp= LOCAL_MPI_Alltoall( sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm);
#ifdef DEBUG
printf("sort : R_MPI_Alltoall\n");
#endif
return ret_tmp;
}

int MPI_Init(int * argc,char *** argv);
int (*LOCAL_MPI_Init)(int *,char ***);

__asm__(
".global CCMPI_Init\n"
".weak MPI_Init\n"
".set MPI_Init,CCMPI_Init\n"
".extern in_w\n"
".extern A_MPI_Init\n"
".extern R_MPI_Init\n"
".type CCMPI_Init,@function\n"
".text\n"
"CCMPI_Init:\n"
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Init\n"
"b A_MPI_Init\n"
"inwrap_MPI_Init:\n"
"b R_MPI_Init\n"
);

int A_MPI_Init(int * argc,char *** argv)
{
#ifdef DEBUG
printf("entre : A_MPI_Init\n");
#endif
in_w=1;





int ret_tmp= LOCAL_MPI_Init( argc, argv);
int wi4mpi_rank;
R_MPI_Comm_rank(R_MPI_COMM_WORLD,&wi4mpi_rank);
if(wi4mpi_rank==0)
	fprintf(stdout,"You are using Wi4MPI-%s with the mode interface From Interface To %s\n", getenv("WI4MPI_VERSION"), getenv("WI4MPI_TO"));
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Init\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Init(int * argc,char *** argv)
{
#ifdef DEBUG
printf("entre : R_MPI_Init\n");
#endif
int ret_tmp= LOCAL_MPI_Init( argc, argv);
#ifdef DEBUG
printf("sort : R_MPI_Init\n");
#endif
return ret_tmp;
}
int MPI_Comm_rank(A_MPI_Comm comm,int * rank);
int (*LOCAL_MPI_Comm_rank)(R_MPI_Comm,int *);

__asm__(
".global CCMPI_Comm_rank\n"
".weak MPI_Comm_rank\n"
".set MPI_Comm_rank,CCMPI_Comm_rank\n"
".extern in_w\n"
".extern A_MPI_Comm_rank\n"
".extern R_MPI_Comm_rank\n"
".type CCMPI_Comm_rank,@function\n"
".text\n"
"CCMPI_Comm_rank:\n"
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Comm_rank\n"
"b A_MPI_Comm_rank\n"
"inwrap_MPI_Comm_rank:\n"
"b R_MPI_Comm_rank\n"
);

int A_MPI_Comm_rank(A_MPI_Comm comm,int * rank)
{
#ifdef DEBUG
printf("entre : A_MPI_Comm_rank\n");
#endif
in_w=1;

R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);

int ret_tmp= LOCAL_MPI_Comm_rank( comm_tmp, rank);

in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Comm_rank\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Comm_rank(R_MPI_Comm comm,int * rank)
{
#ifdef DEBUG
printf("entre : R_MPI_Comm_rank\n");
#endif
int ret_tmp= LOCAL_MPI_Comm_rank( comm, rank);
#ifdef DEBUG
printf("sort : R_MPI_Comm_rank\n");
#endif
return ret_tmp;
}
int MPI_Comm_size(A_MPI_Comm comm,int * size);
int (*LOCAL_MPI_Comm_size)(R_MPI_Comm,int *);

__asm__(
".global CCMPI_Comm_size\n"
".weak MPI_Comm_size\n"
".set MPI_Comm_size,CCMPI_Comm_size\n"
".extern in_w\n"
".extern A_MPI_Comm_size\n"
".extern R_MPI_Comm_size\n"
".type CCMPI_Comm_size,@function\n"
".text\n"
"CCMPI_Comm_size:\n"
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Comm_size\n"
"b A_MPI_Comm_size\n"
"inwrap_MPI_Comm_size:\n"
"b R_MPI_Comm_size\n"
);

int A_MPI_Comm_size(A_MPI_Comm comm,int * size)
{
#ifdef DEBUG
printf("entre : A_MPI_Comm_size\n");
#endif
in_w=1;

R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);

int ret_tmp= LOCAL_MPI_Comm_size( comm_tmp, size);

in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Comm_size\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Comm_size(R_MPI_Comm comm,int * size)
{
#ifdef DEBUG
printf("entre : R_MPI_Comm_size\n");
#endif
int ret_tmp= LOCAL_MPI_Comm_size( comm, size);
#ifdef DEBUG
printf("sort : R_MPI_Comm_size\n");
#endif
return ret_tmp;
}
int MPI_Finalize( );
int (*LOCAL_MPI_Finalize)();

__asm__(
".global CCMPI_Finalize\n"
".weak MPI_Finalize\n"
".set MPI_Finalize,CCMPI_Finalize\n"
".extern in_w\n"
".extern A_MPI_Finalize\n"
".extern R_MPI_Finalize\n"
".type CCMPI_Finalize,@function\n"
".text\n"
"CCMPI_Finalize:\n"
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Finalize\n"
"b A_MPI_Finalize\n"
"inwrap_MPI_Finalize:\n"
"b R_MPI_Finalize\n"
);

int A_MPI_Finalize( )
{
#ifdef DEBUG
printf("entre : A_MPI_Finalize\n");
#endif
in_w=1;

int ret_tmp= LOCAL_MPI_Finalize( );
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Finalize\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Finalize( )
{
#ifdef DEBUG
printf("entre : R_MPI_Finalize\n");
#endif
int ret_tmp= LOCAL_MPI_Finalize( );
#ifdef DEBUG
printf("sort : R_MPI_Finalize\n");
#endif
return ret_tmp;
}
int MPI_Reduce(void * sendbuf,void * recvbuf,int count,A_MPI_Datatype datatype,A_MPI_Op op,int root,A_MPI_Comm comm);
int (*LOCAL_MPI_Reduce)(void *,void *,int,R_MPI_Datatype,R_MPI_Op,int,R_MPI_Comm);

__asm__(
".global CCMPI_Reduce\n"
".weak MPI_Reduce\n"
".set MPI_Reduce,CCMPI_Reduce\n"
".extern in_w\n"
".extern A_MPI_Reduce\n"
".extern R_MPI_Reduce\n"
".type CCMPI_Reduce,@function\n"
".text\n"
"CCMPI_Reduce:\n"
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Reduce\n"
"b A_MPI_Reduce\n"
"inwrap_MPI_Reduce:\n"
"b R_MPI_Reduce\n"
);

int A_MPI_Reduce(void * sendbuf,void * recvbuf,int count,A_MPI_Datatype datatype,A_MPI_Op op,int root,A_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : A_MPI_Reduce\n");
#endif
in_w=1;

void * sendbuf_tmp;
const_buffer_conv_a2r(&sendbuf,&sendbuf_tmp);
void * recvbuf_tmp;
buffer_conv_a2r(&recvbuf,&recvbuf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
R_MPI_Op op_tmp;
op_conv_a2r(&op,&op_tmp);


R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
int ret_tmp= LOCAL_MPI_Reduce( sendbuf_tmp, recvbuf_tmp, count, datatype_tmp, op_tmp, root, comm_tmp);
buffer_conv_r2a(&recvbuf,&recvbuf_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Reduce\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Reduce(void * sendbuf,void * recvbuf,int count,R_MPI_Datatype datatype,R_MPI_Op op,int root,R_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : R_MPI_Reduce\n");
#endif
int ret_tmp= LOCAL_MPI_Reduce( sendbuf, recvbuf, count, datatype, op, root, comm);
#ifdef DEBUG
printf("sort : R_MPI_Reduce\n");
#endif
return ret_tmp;
}
void init_global(void *);
void init_f2c(void *);
void wrapper_init_f(void);
#ifdef WI4MPI_STATIC
#define WATTR
#else
#define WATTR __attribute__((constructor)) 
#endif
WATTR void wrapper_init(void) {
void *lib_handle=dlopen(getenv("WI4MPI_RUN_MPI_C_LIB"),RTLD_NOW|RTLD_GLOBAL);
LOCAL_MPI_Send=dlsym(lib_handle,"PMPI_Send");
LOCAL_MPI_Recv=dlsym(lib_handle,"PMPI_Recv");
LOCAL_MPI_Alltoall=dlsym(lib_handle,"PMPI_Alltoall");
LOCAL_MPI_Comm_size=dlsym(lib_handle,"PMPI_Comm_size");
LOCAL_MPI_Comm_rank=dlsym(lib_handle,"PMPI_Comm_rank");
LOCAL_MPI_Init=dlsym(lib_handle,"PMPI_Init");
LOCAL_MPI_Finalize=dlsym(lib_handle,"PMPI_Finalize");
LOCAL_MPI_Reduce=dlsym(lib_handle,"PMPI_Reduce");
#ifdef OMPI_OMPI
init_global(lib_handle);
#elif OMPI_INTEL
R_MPI_UNWEIGHTED=dlsym(lib_handle,"MPI_UNWEIGHTED");
R_MPI_WEIGHTS_EMPTY=dlsym(lib_handle,"MPI_WEIGHTS_EMPTY");
MPI_UNWEIGHTED=dlsym(lib_handle,"MPI_UNWEIGHTED");
MPI_WEIGHTS_EMPTY=dlsym(lib_handle,"MPI_WEIGHTS_EMPTY");
#endif
datatype_translation_init();
communicator_translation_init();
request_translation_init();
operation_translation_init();
group_translation_init();
errhandler_translation_init();
file_translation_init();
info_translation_init();
win_translation_init();
message_translation_init();
t_enum_translation_init();
cvar_handle_translation_init();
pvar_handle_translation_init();
//pvar_session_translation_init();
//DATATYPE
datatype_translation_add_const(A_MPI_DATATYPE_NULL, R_MPI_DATATYPE_NULL);
datatype_translation_add_const(A_MPI_CHAR, R_MPI_CHAR);
datatype_translation_add_const(A_MPI_SIGNED_CHAR, R_MPI_SIGNED_CHAR);
datatype_translation_add_const(A_MPI_UNSIGNED_CHAR, R_MPI_UNSIGNED_CHAR);
datatype_translation_add_const(A_MPI_BYTE, R_MPI_BYTE);
datatype_translation_add_const(A_MPI_WCHAR, R_MPI_WCHAR);
datatype_translation_add_const(A_MPI_SHORT, R_MPI_SHORT);
datatype_translation_add_const(A_MPI_UNSIGNED_SHORT, R_MPI_UNSIGNED_SHORT);
datatype_translation_add_const(A_MPI_INT, R_MPI_INT);
datatype_translation_add_const(A_MPI_UNSIGNED, R_MPI_UNSIGNED);
datatype_translation_add_const(A_MPI_LONG, R_MPI_LONG);
datatype_translation_add_const(A_MPI_UNSIGNED_LONG, R_MPI_UNSIGNED_LONG);
datatype_translation_add_const(A_MPI_FLOAT, R_MPI_FLOAT);
datatype_translation_add_const(A_MPI_DOUBLE, R_MPI_DOUBLE);
datatype_translation_add_const(A_MPI_LONG_DOUBLE, R_MPI_LONG_DOUBLE);
datatype_translation_add_const(A_MPI_LONG_LONG_INT, R_MPI_LONG_LONG_INT);
datatype_translation_add_const(A_MPI_UNSIGNED_LONG_LONG, R_MPI_UNSIGNED_LONG_LONG);
datatype_translation_add_const(A_MPI_LONG_LONG, R_MPI_LONG_LONG);
datatype_translation_add_const(A_MPI_UB, R_MPI_UB);
datatype_translation_add_const(A_MPI_LB, R_MPI_LB);
datatype_translation_add_const(A_MPI_PACKED, R_MPI_PACKED);
datatype_translation_add_const(A_MPI_2INT, R_MPI_2INT);
datatype_translation_add_const(A_MPI_LONG_INT, R_MPI_LONG_INT);
datatype_translation_add_const(A_MPI_SHORT_INT, R_MPI_SHORT_INT);
datatype_translation_add_const(A_MPI_DOUBLE_INT, R_MPI_DOUBLE_INT);
datatype_translation_add_const(A_MPI_FLOAT_INT, R_MPI_FLOAT_INT);
datatype_translation_add_const(A_MPI_LONG_DOUBLE_INT, R_MPI_LONG_DOUBLE_INT);
datatype_translation_add_const(A_MPI_CHARACTER, R_MPI_CHARACTER);
datatype_translation_add_const(A_MPI_LOGICAL, R_MPI_LOGICAL);
datatype_translation_add_const(A_MPI_DOUBLE_COMPLEX, R_MPI_DOUBLE_COMPLEX);
datatype_translation_add_const(A_MPI_COMPLEX, R_MPI_COMPLEX);
datatype_translation_add_const(A_MPI_INTEGER, R_MPI_INTEGER);
datatype_translation_add_const(A_MPI_REAL, R_MPI_REAL);
datatype_translation_add_const(A_MPI_DOUBLE_PRECISION,R_MPI_DOUBLE_PRECISION);
/*New datatypes from the MPI 2.2 standard*/
datatype_translation_add_const(A_MPI_INT8_T               ,R_MPI_INT8_T               );
datatype_translation_add_const(A_MPI_UINT8_T              ,R_MPI_UINT8_T              );
datatype_translation_add_const(A_MPI_INT16_T              ,R_MPI_INT16_T              );
datatype_translation_add_const(A_MPI_UINT16_T             ,R_MPI_UINT16_T             );
datatype_translation_add_const(A_MPI_INT32_T              ,R_MPI_INT32_T              );
datatype_translation_add_const(A_MPI_UINT32_T             ,R_MPI_UINT32_T             );
datatype_translation_add_const(A_MPI_INT64_T              ,R_MPI_INT64_T              );
datatype_translation_add_const(A_MPI_UINT64_T             ,R_MPI_UINT64_T             );
datatype_translation_add_const(A_MPI_AINT                 ,R_MPI_AINT                 );
datatype_translation_add_const(A_MPI_OFFSET               ,R_MPI_OFFSET               );
datatype_translation_add_const(A_MPI_C_BOOL               ,R_MPI_C_BOOL               );
datatype_translation_add_const(A_MPI_C_COMPLEX            ,R_MPI_C_COMPLEX            );
datatype_translation_add_const(A_MPI_C_FLOAT_COMPLEX      ,R_MPI_C_FLOAT_COMPLEX      );
datatype_translation_add_const(A_MPI_C_DOUBLE_COMPLEX     ,R_MPI_C_DOUBLE_COMPLEX     );
datatype_translation_add_const(A_MPI_C_LONG_DOUBLE_COMPLEX,R_MPI_C_LONG_DOUBLE_COMPLEX);
datatype_translation_add_const(A_MPI_CXX_BOOL             ,R_MPI_CXX_BOOL             );
datatype_translation_add_const(A_MPI_CXX_FLOAT_COMPLEX    ,R_MPI_CXX_FLOAT_COMPLEX    );
datatype_translation_add_const(A_MPI_CXX_DOUBLE_COMPLEX   ,R_MPI_CXX_DOUBLE_COMPLEX   );
datatype_translation_add_const(A_MPI_CXX_LONG_DOUBLE_COMPLEX,R_MPI_CXX_LONG_DOUBLE_COMPLEX);
/*New datatypes from the 3.0 standard*/
//datatype_translation_add_const(A_MPI_COUNT,R_MPI_COUNT);
//COMM
communicator_translation_add_const(A_MPI_COMM_WORLD, R_MPI_COMM_WORLD);
communicator_translation_add_const(A_MPI_COMM_SELF, R_MPI_COMM_SELF);
communicator_translation_add_const(A_MPI_COMM_NULL, R_MPI_COMM_NULL);
//REQUEST
request_translation_add_const(A_MPI_REQUEST_NULL, R_MPI_REQUEST_NULL);
//OP
operation_translation_add_const(A_MPI_OP_NULL, R_MPI_OP_NULL);
operation_translation_add_const(A_MPI_MAX, R_MPI_MAX);
operation_translation_add_const(A_MPI_MIN, R_MPI_MIN);
operation_translation_add_const(A_MPI_SUM, R_MPI_SUM);
operation_translation_add_const(A_MPI_PROD, R_MPI_PROD);
operation_translation_add_const(A_MPI_MAXLOC, R_MPI_MAXLOC);
operation_translation_add_const(A_MPI_MINLOC, R_MPI_MINLOC);
operation_translation_add_const(A_MPI_BAND, R_MPI_BAND);
operation_translation_add_const(A_MPI_BOR, R_MPI_BOR);
operation_translation_add_const(A_MPI_BXOR, R_MPI_BXOR);
operation_translation_add_const(A_MPI_LAND, R_MPI_LAND);
operation_translation_add_const(A_MPI_LOR, R_MPI_LOR);
operation_translation_add_const(A_MPI_LXOR, R_MPI_LXOR);
operation_translation_add_const(A_MPI_REPLACE, R_MPI_REPLACE);
//operation_translation_add_const(A_MPI_SAME_MODE, R_MPI_SAME_MODE);
//GROUP
group_translation_add_const(A_MPI_GROUP_NULL, R_MPI_GROUP_NULL);
group_translation_add_const(A_MPI_GROUP_EMPTY, R_MPI_GROUP_EMPTY);
//ERRHANDLER
errhandler_translation_add_const(A_MPI_ERRHANDLER_NULL,R_MPI_ERRHANDLER_NULL);
errhandler_translation_add_const(A_MPI_ERRORS_ARE_FATAL,R_MPI_ERRORS_ARE_FATAL);
errhandler_translation_add_const(A_MPI_ERRORS_RETURN, R_MPI_ERRORS_RETURN);
//FILE
file_translation_add_const(A_MPI_FILE_NULL, R_MPI_FILE_NULL);
//INFO
info_translation_add_const(A_MPI_INFO_NULL, R_MPI_INFO_NULL);
//WIN
win_translation_add_const(A_MPI_WIN_NULL, R_MPI_WIN_NULL);
//MESSAGE
message_translation_add_const(A_MPI_MESSAGE_NULL,R_MPI_MESSAGE_NULL);
message_translation_add_const(A_MPI_MESSAGE_NO_PROC,R_MPI_MESSAGE_NO_PROC);
//MPI_T
t_enum_translation_add_const(A_MPI_T_ENUM_NULL,R_MPI_T_ENUM_NULL);
cvar_handle_translation_add_const(A_MPI_T_CVAR_HANDLE_NULL,R_MPI_T_CVAR_HANDLE_NULL);
pvar_handle_translation_add_const(A_MPI_T_PVAR_HANDLE_NULL,R_MPI_T_PVAR_HANDLE_NULL);
//pvar_session_translation_add_const(A_MPI_T_PVAR_SESSION_NULL,R_MPI_T_PVAR_SESSION_NULL);
//init_f2c(lib_handle);
WI4MPI_errhandler_key=R_MPI_KEYVAL_INVALID;
}

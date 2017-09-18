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
#include <stdlib.h>
#define _GNU_SOURCE
#include <stdio.h>
#include <dlfcn.h>
#include "manual_interface.h"
void *mpi_comm_null_copy_fn_=NULL;
void *mpi_win_dup_fn_=NULL;
void *mpi_null_copy_fn_=NULL;
void *mpi_comm_null_delete_fn_=NULL;
void *mpi_comm_dup_fn_=NULL;
void *mpi_type_null_copy_fn_=NULL;
void *mpi_null_delete_fn_=NULL;
void *mpi_dup_fn_=NULL;
void *mpi_conversion_fn_null_=NULL;
void *mpi_win_null_delete_fn_=NULL;
void *mpi_type_null_delete_fn_=NULL;
void *mpi_type_dup_fn_=NULL;
void *mpi_win_null_copy_fn_=NULL;
/*ompi constante*/

char wi4mpi_mode_f[]="";

void  mpi_pcontrol_(int * level,int * ret);
#pragma weak mpi_pcontrol_=pmpi_pcontrol_
void  (*INTERFACE_F_LOCAL_MPI_Pcontrol)(int *,int *);

void pmpi_pcontrol_(int * level,int * ret){

return  INTERFACE_F_LOCAL_MPI_Pcontrol( level, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Pcontrol)(int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Pcontrol)(int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_send_(void * buf,int * count,int * datatype,int * dest,int * tag,int * comm,int * ret);
#pragma weak mpi_send_=pmpi_send_
void  (*INTERFACE_F_LOCAL_MPI_Send)(void *,int *,int *,int *,int *,int *,int *);

void pmpi_send_(void * buf,int * count,int * datatype,int * dest,int * tag,int * comm,int * ret){

return  INTERFACE_F_LOCAL_MPI_Send(buf, count,datatype,dest,tag,comm, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Send)(void *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Send)(void *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_recv_(void * buf,int * count,int * datatype,int * source,int * tag,int * comm,int * status,int * ret);
#pragma weak mpi_recv_=pmpi_recv_
void  (*INTERFACE_F_LOCAL_MPI_Recv)(void *,int *,int *,int *,int *,int *,int *,int *);

void pmpi_recv_(void * buf,int * count,int * datatype,int * source,int * tag,int * comm,int * status,int * ret){

return  INTERFACE_F_LOCAL_MPI_Recv(buf, count,datatype,source,tag,comm,status, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Recv)(void *,int *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Recv)(void *,int *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_get_count_(int * status,int * datatype,int * count,int * ret);
#pragma weak mpi_get_count_=pmpi_get_count_
void  (*INTERFACE_F_LOCAL_MPI_Get_count)(int *,int *,int *,int *);

void pmpi_get_count_(int * status,int * datatype,int * count,int * ret){

return  INTERFACE_F_LOCAL_MPI_Get_count(status,datatype, count, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Get_count)(int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Get_count)(int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_bsend_(void * buf,int * count,int * datatype,int * dest,int * tag,int * comm,int * ret);
#pragma weak mpi_bsend_=pmpi_bsend_
void  (*INTERFACE_F_LOCAL_MPI_Bsend)(void *,int *,int *,int *,int *,int *,int *);

void pmpi_bsend_(void * buf,int * count,int * datatype,int * dest,int * tag,int * comm,int * ret){

return  INTERFACE_F_LOCAL_MPI_Bsend(buf, count,datatype,dest,tag,comm, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Bsend)(void *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Bsend)(void *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_ssend_(void * buf,int * count,int * datatype,int * dest,int * tag,int * comm,int * ret);
#pragma weak mpi_ssend_=pmpi_ssend_
void  (*INTERFACE_F_LOCAL_MPI_Ssend)(void *,int *,int *,int *,int *,int *,int *);

void pmpi_ssend_(void * buf,int * count,int * datatype,int * dest,int * tag,int * comm,int * ret){

return  INTERFACE_F_LOCAL_MPI_Ssend(buf, count,datatype,dest,tag,comm, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Ssend)(void *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Ssend)(void *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_rsend_(void * buf,int * count,int * datatype,int * dest,int * tag,int * comm,int * ret);
#pragma weak mpi_rsend_=pmpi_rsend_
void  (*INTERFACE_F_LOCAL_MPI_Rsend)(void *,int *,int *,int *,int *,int *,int *);

void pmpi_rsend_(void * buf,int * count,int * datatype,int * dest,int * tag,int * comm,int * ret){

return  INTERFACE_F_LOCAL_MPI_Rsend(buf, count,datatype,dest,tag,comm, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Rsend)(void *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Rsend)(void *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_buffer_attach_(void * buffer,int * size,int * ret);
#pragma weak mpi_buffer_attach_=pmpi_buffer_attach_
void  (*INTERFACE_F_LOCAL_MPI_Buffer_attach)(void *,int *,int *);

void pmpi_buffer_attach_(void * buffer,int * size,int * ret){

return  INTERFACE_F_LOCAL_MPI_Buffer_attach(buffer, size, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Buffer_attach)(void *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Buffer_attach)(void *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_buffer_detach_(void * buffer_addr,int * size,int * ret);
#pragma weak mpi_buffer_detach_=pmpi_buffer_detach_
void  (*INTERFACE_F_LOCAL_MPI_Buffer_detach)(void *,int *,int *);

void pmpi_buffer_detach_(void * buffer_addr,int * size,int * ret){

return  INTERFACE_F_LOCAL_MPI_Buffer_detach(buffer_addr, size, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Buffer_detach)(void *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Buffer_detach)(void *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_isend_(void * buf,int * count,int * datatype,int * dest,int * tag,int * comm,int * request,int * ret);
#pragma weak mpi_isend_=pmpi_isend_
void  (*INTERFACE_F_LOCAL_MPI_Isend)(void *,int *,int *,int *,int *,int *,int *,int *);

void pmpi_isend_(void * buf,int * count,int * datatype,int * dest,int * tag,int * comm,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Isend(buf, count,datatype,dest,tag,comm,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Isend)(void *,int *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Isend)(void *,int *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_ibsend_(void * buf,int * count,int * datatype,int * dest,int * tag,int * comm,int * request,int * ret);
#pragma weak mpi_ibsend_=pmpi_ibsend_
void  (*INTERFACE_F_LOCAL_MPI_Ibsend)(void *,int *,int *,int *,int *,int *,int *,int *);

void pmpi_ibsend_(void * buf,int * count,int * datatype,int * dest,int * tag,int * comm,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Ibsend(buf, count,datatype,dest,tag,comm,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Ibsend)(void *,int *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Ibsend)(void *,int *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_issend_(void * buf,int * count,int * datatype,int * dest,int * tag,int * comm,int * request,int * ret);
#pragma weak mpi_issend_=pmpi_issend_
void  (*INTERFACE_F_LOCAL_MPI_Issend)(void *,int *,int *,int *,int *,int *,int *,int *);

void pmpi_issend_(void * buf,int * count,int * datatype,int * dest,int * tag,int * comm,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Issend(buf, count,datatype,dest,tag,comm,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Issend)(void *,int *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Issend)(void *,int *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_irsend_(void * buf,int * count,int * datatype,int * dest,int * tag,int * comm,int * request,int * ret);
#pragma weak mpi_irsend_=pmpi_irsend_
void  (*INTERFACE_F_LOCAL_MPI_Irsend)(void *,int *,int *,int *,int *,int *,int *,int *);

void pmpi_irsend_(void * buf,int * count,int * datatype,int * dest,int * tag,int * comm,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Irsend(buf, count,datatype,dest,tag,comm,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Irsend)(void *,int *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Irsend)(void *,int *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_irecv_(void * buf,int * count,int * datatype,int * source,int * tag,int * comm,int * request,int * ret);
#pragma weak mpi_irecv_=pmpi_irecv_
void  (*INTERFACE_F_LOCAL_MPI_Irecv)(void *,int *,int *,int *,int *,int *,int *,int *);

void pmpi_irecv_(void * buf,int * count,int * datatype,int * source,int * tag,int * comm,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Irecv(buf, count,datatype,source,tag,comm,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Irecv)(void *,int *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Irecv)(void *,int *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_wait_(int * request,int * status,int * ret);
#pragma weak mpi_wait_=pmpi_wait_
void  (*INTERFACE_F_LOCAL_MPI_Wait)(int *,int *,int *);

void pmpi_wait_(int * request,int * status,int * ret){

return  INTERFACE_F_LOCAL_MPI_Wait(request,status, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Wait)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Wait)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_test_(int * request,int * flag,int * status,int * ret);
#pragma weak mpi_test_=pmpi_test_
void  (*INTERFACE_F_LOCAL_MPI_Test)(int *,int *,int *,int *);

void pmpi_test_(int * request,int * flag,int * status,int * ret){

return  INTERFACE_F_LOCAL_MPI_Test(request, flag,status, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Test)(int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Test)(int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_request_free_(int * request,int * ret);
#pragma weak mpi_request_free_=pmpi_request_free_
void  (*INTERFACE_F_LOCAL_MPI_Request_free)(int *,int *);

void pmpi_request_free_(int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Request_free(request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Request_free)(int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Request_free)(int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_iprobe_(int * source,int * tag,int * comm,int * flag,int * status,int * ret);
#pragma weak mpi_iprobe_=pmpi_iprobe_
void  (*INTERFACE_F_LOCAL_MPI_Iprobe)(int *,int *,int *,int *,int *,int *);

void pmpi_iprobe_(int * source,int * tag,int * comm,int * flag,int * status,int * ret){

return  INTERFACE_F_LOCAL_MPI_Iprobe(source,tag,comm, flag,status, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Iprobe)(int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Iprobe)(int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_probe_(int * source,int * tag,int * comm,int * status,int * ret);
#pragma weak mpi_probe_=pmpi_probe_
void  (*INTERFACE_F_LOCAL_MPI_Probe)(int *,int *,int *,int *,int *);

void pmpi_probe_(int * source,int * tag,int * comm,int * status,int * ret){

return  INTERFACE_F_LOCAL_MPI_Probe(source,tag,comm,status, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Probe)(int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Probe)(int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_cancel_(int * request,int * ret);
#pragma weak mpi_cancel_=pmpi_cancel_
void  (*INTERFACE_F_LOCAL_MPI_Cancel)(int *,int *);

void pmpi_cancel_(int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Cancel(request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Cancel)(int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Cancel)(int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_test_cancelled_(int * status,int * flag,int * ret);
#pragma weak mpi_test_cancelled_=pmpi_test_cancelled_
void  (*INTERFACE_F_LOCAL_MPI_Test_cancelled)(int *,int *,int *);

void pmpi_test_cancelled_(int * status,int * flag,int * ret){

return  INTERFACE_F_LOCAL_MPI_Test_cancelled(status, flag, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Test_cancelled)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Test_cancelled)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_send_init_(void * buf,int * count,int * datatype,int * dest,int * tag,int * comm,int * request,int * ret);
#pragma weak mpi_send_init_=pmpi_send_init_
void  (*INTERFACE_F_LOCAL_MPI_Send_init)(void *,int *,int *,int *,int *,int *,int *,int *);

void pmpi_send_init_(void * buf,int * count,int * datatype,int * dest,int * tag,int * comm,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Send_init(buf, count,datatype,dest,tag,comm,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Send_init)(void *,int *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Send_init)(void *,int *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_bsend_init_(void * buf,int * count,int * datatype,int * dest,int * tag,int * comm,int * request,int * ret);
#pragma weak mpi_bsend_init_=pmpi_bsend_init_
void  (*INTERFACE_F_LOCAL_MPI_Bsend_init)(void *,int *,int *,int *,int *,int *,int *,int *);

void pmpi_bsend_init_(void * buf,int * count,int * datatype,int * dest,int * tag,int * comm,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Bsend_init(buf, count,datatype,dest,tag,comm,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Bsend_init)(void *,int *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Bsend_init)(void *,int *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_ssend_init_(void * buf,int * count,int * datatype,int * dest,int * tag,int * comm,int * request,int * ret);
#pragma weak mpi_ssend_init_=pmpi_ssend_init_
void  (*INTERFACE_F_LOCAL_MPI_Ssend_init)(void *,int *,int *,int *,int *,int *,int *,int *);

void pmpi_ssend_init_(void * buf,int * count,int * datatype,int * dest,int * tag,int * comm,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Ssend_init(buf, count,datatype,dest,tag,comm,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Ssend_init)(void *,int *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Ssend_init)(void *,int *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_rsend_init_(void * buf,int * count,int * datatype,int * dest,int * tag,int * comm,int * request,int * ret);
#pragma weak mpi_rsend_init_=pmpi_rsend_init_
void  (*INTERFACE_F_LOCAL_MPI_Rsend_init)(void *,int *,int *,int *,int *,int *,int *,int *);

void pmpi_rsend_init_(void * buf,int * count,int * datatype,int * dest,int * tag,int * comm,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Rsend_init(buf, count,datatype,dest,tag,comm,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Rsend_init)(void *,int *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Rsend_init)(void *,int *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_recv_init_(void * buf,int * count,int * datatype,int * source,int * tag,int * comm,int * request,int * ret);
#pragma weak mpi_recv_init_=pmpi_recv_init_
void  (*INTERFACE_F_LOCAL_MPI_Recv_init)(void *,int *,int *,int *,int *,int *,int *,int *);

void pmpi_recv_init_(void * buf,int * count,int * datatype,int * source,int * tag,int * comm,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Recv_init(buf, count,datatype,source,tag,comm,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Recv_init)(void *,int *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Recv_init)(void *,int *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_start_(int * request,int * ret);
#pragma weak mpi_start_=pmpi_start_
void  (*INTERFACE_F_LOCAL_MPI_Start)(int *,int *);

void pmpi_start_(int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Start(request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Start)(int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Start)(int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_sendrecv_(void * sendbuf,int * sendcount,int * sendtype,int * dest,int * sendtag,void * recvbuf,int * recvcount,int * recvtype,int * source,int * recvtag,int * comm,int * status,int * ret);
#pragma weak mpi_sendrecv_=pmpi_sendrecv_
void  (*INTERFACE_F_LOCAL_MPI_Sendrecv)(void *,int *,int *,int *,int *,void *,int *,int *,int *,int *,int *,int *,int *);

void pmpi_sendrecv_(void * sendbuf,int * sendcount,int * sendtype,int * dest,int * sendtag,void * recvbuf,int * recvcount,int * recvtype,int * source,int * recvtag,int * comm,int * status,int * ret){

return  INTERFACE_F_LOCAL_MPI_Sendrecv(sendbuf, sendcount,sendtype,dest,sendtag,recvbuf, recvcount,recvtype,source,recvtag,comm,status, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Sendrecv)(void *,int *,int *,int *,int *,void *,int *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Sendrecv)(void *,int *,int *,int *,int *,void *,int *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_sendrecv_replace_(void * buf,int * count,int * datatype,int * dest,int * sendtag,int * source,int * recvtag,int * comm,int * status,int * ret);
#pragma weak mpi_sendrecv_replace_=pmpi_sendrecv_replace_
void  (*INTERFACE_F_LOCAL_MPI_Sendrecv_replace)(void *,int *,int *,int *,int *,int *,int *,int *,int *,int *);

void pmpi_sendrecv_replace_(void * buf,int * count,int * datatype,int * dest,int * sendtag,int * source,int * recvtag,int * comm,int * status,int * ret){

return  INTERFACE_F_LOCAL_MPI_Sendrecv_replace(buf, count,datatype,dest,sendtag,source,recvtag,comm,status, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Sendrecv_replace)(void *,int *,int *,int *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Sendrecv_replace)(void *,int *,int *,int *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_type_contiguous_(int * count,int * oldtype,int * newtype,int * ret);
#pragma weak mpi_type_contiguous_=pmpi_type_contiguous_
void  (*INTERFACE_F_LOCAL_MPI_Type_contiguous)(int *,int *,int *,int *);

void pmpi_type_contiguous_(int * count,int * oldtype,int * newtype,int * ret){

return  INTERFACE_F_LOCAL_MPI_Type_contiguous( count,oldtype,newtype, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Type_contiguous)(int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Type_contiguous)(int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_type_vector_(int * count,int * blocklength,int * stride,int * oldtype,int * newtype,int * ret);
#pragma weak mpi_type_vector_=pmpi_type_vector_
void  (*INTERFACE_F_LOCAL_MPI_Type_vector)(int *,int *,int *,int *,int *,int *);

void pmpi_type_vector_(int * count,int * blocklength,int * stride,int * oldtype,int * newtype,int * ret){

return  INTERFACE_F_LOCAL_MPI_Type_vector( count, blocklength, stride,oldtype,newtype, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Type_vector)(int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Type_vector)(int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_type_hvector_(int * count,int * blocklength,size_t * stride,int * oldtype,int * newtype,int * ret);
#pragma weak mpi_type_hvector_=pmpi_type_hvector_
void  (*INTERFACE_F_LOCAL_MPI_Type_hvector)(int *,int *,size_t *,int *,int *,int *);

void pmpi_type_hvector_(int * count,int * blocklength,size_t * stride,int * oldtype,int * newtype,int * ret){

return  INTERFACE_F_LOCAL_MPI_Type_hvector( count, blocklength, stride,oldtype,newtype, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Type_hvector)(int *,int *,size_t *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Type_hvector)(int *,int *,size_t *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_type_indexed_(int * count,int * array_of_blocklengths,int * array_of_displacements,int * oldtype,int * newtype,int * ret);
#pragma weak mpi_type_indexed_=pmpi_type_indexed_
void  (*INTERFACE_F_LOCAL_MPI_Type_indexed)(int *,int *,int *,int *,int *,int *);

void pmpi_type_indexed_(int * count,int * array_of_blocklengths,int * array_of_displacements,int * oldtype,int * newtype,int * ret){

return  INTERFACE_F_LOCAL_MPI_Type_indexed( count, array_of_blocklengths, array_of_displacements,oldtype,newtype, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Type_indexed)(int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Type_indexed)(int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_type_hindexed_(int * count,int * array_of_blocklengths,size_t * array_of_displacements,int * oldtype,int * newtype,int * ret);
#pragma weak mpi_type_hindexed_=pmpi_type_hindexed_
void  (*INTERFACE_F_LOCAL_MPI_Type_hindexed)(int *,int *,size_t *,int *,int *,int *);

void pmpi_type_hindexed_(int * count,int * array_of_blocklengths,size_t * array_of_displacements,int * oldtype,int * newtype,int * ret){

return  INTERFACE_F_LOCAL_MPI_Type_hindexed( count, array_of_blocklengths, array_of_displacements,oldtype,newtype, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Type_hindexed)(int *,int *,size_t *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Type_hindexed)(int *,int *,size_t *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_type_struct_(int * count,int * array_of_blocklengths,size_t * array_of_displacements,int * array_of_types,int * newtype,int * ret);
#pragma weak mpi_type_struct_=pmpi_type_struct_
void  (*INTERFACE_F_LOCAL_MPI_Type_struct)(int *,int *,size_t *,int *,int *,int *);

void pmpi_type_struct_(int * count,int * array_of_blocklengths,size_t * array_of_displacements,int * array_of_types,int * newtype,int * ret){

return  INTERFACE_F_LOCAL_MPI_Type_struct( count, array_of_blocklengths, array_of_displacements,array_of_types,newtype, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Type_struct)(int *,int *,size_t *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Type_struct)(int *,int *,size_t *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_address_(void * location,size_t * address,int * ret);
#pragma weak mpi_address_=pmpi_address_
void  (*INTERFACE_F_LOCAL_MPI_Address)(void *,size_t *,int *);

void pmpi_address_(void * location,size_t * address,int * ret){

return  INTERFACE_F_LOCAL_MPI_Address(location, address, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Address)(void *,size_t *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Address)(void *,size_t *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_type_extent_(int * datatype,size_t * extent,int * ret);
#pragma weak mpi_type_extent_=pmpi_type_extent_
void  (*INTERFACE_F_LOCAL_MPI_Type_extent)(int *,size_t *,int *);

void pmpi_type_extent_(int * datatype,size_t * extent,int * ret){

return  INTERFACE_F_LOCAL_MPI_Type_extent(datatype, extent, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Type_extent)(int *,size_t *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Type_extent)(int *,size_t *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_type_size_(int * datatype,int * size,int * ret);
#pragma weak mpi_type_size_=pmpi_type_size_
void  (*INTERFACE_F_LOCAL_MPI_Type_size)(int *,int *,int *);

void pmpi_type_size_(int * datatype,int * size,int * ret){

return  INTERFACE_F_LOCAL_MPI_Type_size(datatype, size, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Type_size)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Type_size)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_type_lb_(int * datatype,size_t * displacement,int * ret);
#pragma weak mpi_type_lb_=pmpi_type_lb_
void  (*INTERFACE_F_LOCAL_MPI_Type_lb)(int *,size_t *,int *);

void pmpi_type_lb_(int * datatype,size_t * displacement,int * ret){

return  INTERFACE_F_LOCAL_MPI_Type_lb(datatype, displacement, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Type_lb)(int *,size_t *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Type_lb)(int *,size_t *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_type_ub_(int * datatype,size_t * displacement,int * ret);
#pragma weak mpi_type_ub_=pmpi_type_ub_
void  (*INTERFACE_F_LOCAL_MPI_Type_ub)(int *,size_t *,int *);

void pmpi_type_ub_(int * datatype,size_t * displacement,int * ret){

return  INTERFACE_F_LOCAL_MPI_Type_ub(datatype, displacement, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Type_ub)(int *,size_t *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Type_ub)(int *,size_t *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_type_commit_(int * datatype,int * ret);
#pragma weak mpi_type_commit_=pmpi_type_commit_
void  (*INTERFACE_F_LOCAL_MPI_Type_commit)(int *,int *);

void pmpi_type_commit_(int * datatype,int * ret){

return  INTERFACE_F_LOCAL_MPI_Type_commit(datatype, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Type_commit)(int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Type_commit)(int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_type_free_(int * datatype,int * ret);
#pragma weak mpi_type_free_=pmpi_type_free_
void  (*INTERFACE_F_LOCAL_MPI_Type_free)(int *,int *);

void pmpi_type_free_(int * datatype,int * ret){

return  INTERFACE_F_LOCAL_MPI_Type_free(datatype, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Type_free)(int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Type_free)(int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_get_elements_(int * status,int * datatype,int * count,int * ret);
#pragma weak mpi_get_elements_=pmpi_get_elements_
void  (*INTERFACE_F_LOCAL_MPI_Get_elements)(int *,int *,int *,int *);

void pmpi_get_elements_(int * status,int * datatype,int * count,int * ret){

return  INTERFACE_F_LOCAL_MPI_Get_elements(status,datatype, count, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Get_elements)(int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Get_elements)(int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_pack_(void * inbuf,int * incount,int * datatype,void * outbuf,int * outsize,int * position,int * comm,int * ret);
#pragma weak mpi_pack_=pmpi_pack_
void  (*INTERFACE_F_LOCAL_MPI_Pack)(void *,int *,int *,void *,int *,int *,int *,int *);

void pmpi_pack_(void * inbuf,int * incount,int * datatype,void * outbuf,int * outsize,int * position,int * comm,int * ret){

return  INTERFACE_F_LOCAL_MPI_Pack(inbuf, incount,datatype,outbuf, outsize, position,comm, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Pack)(void *,int *,int *,void *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Pack)(void *,int *,int *,void *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_unpack_(void * inbuf,int * insize,int * position,void * outbuf,int * outcount,int * datatype,int * comm,int * ret);
#pragma weak mpi_unpack_=pmpi_unpack_
void  (*INTERFACE_F_LOCAL_MPI_Unpack)(void *,int *,int *,void *,int *,int *,int *,int *);

void pmpi_unpack_(void * inbuf,int * insize,int * position,void * outbuf,int * outcount,int * datatype,int * comm,int * ret){

return  INTERFACE_F_LOCAL_MPI_Unpack(inbuf, insize, position,outbuf, outcount,datatype,comm, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Unpack)(void *,int *,int *,void *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Unpack)(void *,int *,int *,void *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_pack_size_(int * incount,int * datatype,int * comm,int * size,int * ret);
#pragma weak mpi_pack_size_=pmpi_pack_size_
void  (*INTERFACE_F_LOCAL_MPI_Pack_size)(int *,int *,int *,int *,int *);

void pmpi_pack_size_(int * incount,int * datatype,int * comm,int * size,int * ret){

return  INTERFACE_F_LOCAL_MPI_Pack_size( incount,datatype,comm, size, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Pack_size)(int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Pack_size)(int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_barrier_(int * comm,int * ret);
#pragma weak mpi_barrier_=pmpi_barrier_
void  (*INTERFACE_F_LOCAL_MPI_Barrier)(int *,int *);

void pmpi_barrier_(int * comm,int * ret){

return  INTERFACE_F_LOCAL_MPI_Barrier(comm, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Barrier)(int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Barrier)(int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_bcast_(void * buffer,int * count,int * datatype,int * root,int * comm,int * ret);
#pragma weak mpi_bcast_=pmpi_bcast_
void  (*INTERFACE_F_LOCAL_MPI_Bcast)(void *,int *,int *,int *,int *,int *);

void pmpi_bcast_(void * buffer,int * count,int * datatype,int * root,int * comm,int * ret){

return  INTERFACE_F_LOCAL_MPI_Bcast(buffer, count,datatype, root,comm, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Bcast)(void *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Bcast)(void *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_gather_(void * sendbuf,int * sendcount,int * sendtype,void * recvbuf,int * recvcount,int * recvtype,int * root,int * comm,int * ret);
#pragma weak mpi_gather_=pmpi_gather_
void  (*INTERFACE_F_LOCAL_MPI_Gather)(void *,int *,int *,void *,int *,int *,int *,int *,int *);

void pmpi_gather_(void * sendbuf,int * sendcount,int * sendtype,void * recvbuf,int * recvcount,int * recvtype,int * root,int * comm,int * ret){

return  INTERFACE_F_LOCAL_MPI_Gather(sendbuf, sendcount,sendtype,recvbuf, recvcount,recvtype, root,comm, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Gather)(void *,int *,int *,void *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Gather)(void *,int *,int *,void *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_gatherv_(void * sendbuf,int * sendcount,int * sendtype,void * recvbuf,int * recvcounts,int * displs,int * recvtype,int * root,int * comm,int * ret);
#pragma weak mpi_gatherv_=pmpi_gatherv_
void  (*INTERFACE_F_LOCAL_MPI_Gatherv)(void *,int *,int *,void *,int *,int *,int *,int *,int *,int *);

void pmpi_gatherv_(void * sendbuf,int * sendcount,int * sendtype,void * recvbuf,int * recvcounts,int * displs,int * recvtype,int * root,int * comm,int * ret){

return  INTERFACE_F_LOCAL_MPI_Gatherv(sendbuf, sendcount,sendtype,recvbuf, recvcounts, displs,recvtype, root,comm, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Gatherv)(void *,int *,int *,void *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Gatherv)(void *,int *,int *,void *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_scatter_(void * sendbuf,int * sendcount,int * sendtype,void * recvbuf,int * recvcount,int * recvtype,int * root,int * comm,int * ret);
#pragma weak mpi_scatter_=pmpi_scatter_
void  (*INTERFACE_F_LOCAL_MPI_Scatter)(void *,int *,int *,void *,int *,int *,int *,int *,int *);

void pmpi_scatter_(void * sendbuf,int * sendcount,int * sendtype,void * recvbuf,int * recvcount,int * recvtype,int * root,int * comm,int * ret){

return  INTERFACE_F_LOCAL_MPI_Scatter(sendbuf, sendcount,sendtype,recvbuf, recvcount,recvtype, root,comm, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Scatter)(void *,int *,int *,void *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Scatter)(void *,int *,int *,void *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_scatterv_(void * sendbuf,int * sendcounts,int * displs,int * sendtype,void * recvbuf,int * recvcount,int * recvtype,int * root,int * comm,int * ret);
#pragma weak mpi_scatterv_=pmpi_scatterv_
void  (*INTERFACE_F_LOCAL_MPI_Scatterv)(void *,int *,int *,int *,void *,int *,int *,int *,int *,int *);

void pmpi_scatterv_(void * sendbuf,int * sendcounts,int * displs,int * sendtype,void * recvbuf,int * recvcount,int * recvtype,int * root,int * comm,int * ret){

return  INTERFACE_F_LOCAL_MPI_Scatterv(sendbuf, sendcounts, displs,sendtype,recvbuf, recvcount,recvtype, root,comm, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Scatterv)(void *,int *,int *,int *,void *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Scatterv)(void *,int *,int *,int *,void *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_allgather_(void * sendbuf,int * sendcount,int * sendtype,void * recvbuf,int * recvcount,int * recvtype,int * comm,int * ret);
#pragma weak mpi_allgather_=pmpi_allgather_
void  (*INTERFACE_F_LOCAL_MPI_Allgather)(void *,int *,int *,void *,int *,int *,int *,int *);

void pmpi_allgather_(void * sendbuf,int * sendcount,int * sendtype,void * recvbuf,int * recvcount,int * recvtype,int * comm,int * ret){

return  INTERFACE_F_LOCAL_MPI_Allgather(sendbuf, sendcount,sendtype,recvbuf, recvcount,recvtype,comm, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Allgather)(void *,int *,int *,void *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Allgather)(void *,int *,int *,void *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_allgatherv_(void * sendbuf,int * sendcount,int * sendtype,void * recvbuf,int * recvcounts,int * displs,int * recvtype,int * comm,int * ret);
#pragma weak mpi_allgatherv_=pmpi_allgatherv_
void  (*INTERFACE_F_LOCAL_MPI_Allgatherv)(void *,int *,int *,void *,int *,int *,int *,int *,int *);

void pmpi_allgatherv_(void * sendbuf,int * sendcount,int * sendtype,void * recvbuf,int * recvcounts,int * displs,int * recvtype,int * comm,int * ret){

return  INTERFACE_F_LOCAL_MPI_Allgatherv(sendbuf, sendcount,sendtype,recvbuf, recvcounts, displs,recvtype,comm, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Allgatherv)(void *,int *,int *,void *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Allgatherv)(void *,int *,int *,void *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_alltoall_(void * sendbuf,int * sendcount,int * sendtype,void * recvbuf,int * recvcount,int * recvtype,int * comm,int * ret);
#pragma weak mpi_alltoall_=pmpi_alltoall_
void  (*INTERFACE_F_LOCAL_MPI_Alltoall)(void *,int *,int *,void *,int *,int *,int *,int *);

void pmpi_alltoall_(void * sendbuf,int * sendcount,int * sendtype,void * recvbuf,int * recvcount,int * recvtype,int * comm,int * ret){

return  INTERFACE_F_LOCAL_MPI_Alltoall(sendbuf, sendcount,sendtype,recvbuf, recvcount,recvtype,comm, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Alltoall)(void *,int *,int *,void *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Alltoall)(void *,int *,int *,void *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_alltoallv_(void * sendbuf,int * sendcounts,int * sdispls,int * sendtype,void * recvbuf,int * recvcounts,int * rdispls,int * recvtype,int * comm,int * ret);
#pragma weak mpi_alltoallv_=pmpi_alltoallv_
void  (*INTERFACE_F_LOCAL_MPI_Alltoallv)(void *,int *,int *,int *,void *,int *,int *,int *,int *,int *);

void pmpi_alltoallv_(void * sendbuf,int * sendcounts,int * sdispls,int * sendtype,void * recvbuf,int * recvcounts,int * rdispls,int * recvtype,int * comm,int * ret){

return  INTERFACE_F_LOCAL_MPI_Alltoallv(sendbuf, sendcounts, sdispls,sendtype,recvbuf, recvcounts, rdispls,recvtype,comm, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Alltoallv)(void *,int *,int *,int *,void *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Alltoallv)(void *,int *,int *,int *,void *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_exscan_(void * sendbuf,void * recvbuf,int * count,int * datatype,int * op,int * comm,int * ret);
#pragma weak mpi_exscan_=pmpi_exscan_
void  (*INTERFACE_F_LOCAL_MPI_Exscan)(void *,void *,int *,int *,int *,int *,int *);

void pmpi_exscan_(void * sendbuf,void * recvbuf,int * count,int * datatype,int * op,int * comm,int * ret){

return  INTERFACE_F_LOCAL_MPI_Exscan(sendbuf,recvbuf, count,datatype,op,comm, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Exscan)(void *,void *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Exscan)(void *,void *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_reduce_(void * sendbuf,void * recvbuf,int * count,int * datatype,int * op,int * root,int * comm,int * ret);
#pragma weak mpi_reduce_=pmpi_reduce_
void  (*INTERFACE_F_LOCAL_MPI_Reduce)(void *,void *,int *,int *,int *,int *,int *,int *);

void pmpi_reduce_(void * sendbuf,void * recvbuf,int * count,int * datatype,int * op,int * root,int * comm,int * ret){

return  INTERFACE_F_LOCAL_MPI_Reduce(sendbuf,recvbuf, count,datatype,op, root,comm, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Reduce)(void *,void *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Reduce)(void *,void *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_op_create_(void * user_fn,int * commute,int * op,int * ret);
#pragma weak mpi_op_create_=pmpi_op_create_
void  (*INTERFACE_F_LOCAL_MPI_Op_create)(void *,int *,int *,int *);

void pmpi_op_create_(void * user_fn,int * commute,int * op,int * ret){

return  INTERFACE_F_LOCAL_MPI_Op_create(user_fn, commute,op, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Op_create)(void *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Op_create)(void *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_op_free_(int * op,int * ret);
#pragma weak mpi_op_free_=pmpi_op_free_
void  (*INTERFACE_F_LOCAL_MPI_Op_free)(int *,int *);

void pmpi_op_free_(int * op,int * ret){

return  INTERFACE_F_LOCAL_MPI_Op_free(op, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Op_free)(int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Op_free)(int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_allreduce_(void * sendbuf,void * recvbuf,int * count,int * datatype,int * op,int * comm,int * ret);
#pragma weak mpi_allreduce_=pmpi_allreduce_
void  (*INTERFACE_F_LOCAL_MPI_Allreduce)(void *,void *,int *,int *,int *,int *,int *);

void pmpi_allreduce_(void * sendbuf,void * recvbuf,int * count,int * datatype,int * op,int * comm,int * ret){

return  INTERFACE_F_LOCAL_MPI_Allreduce(sendbuf,recvbuf, count,datatype,op,comm, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Allreduce)(void *,void *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Allreduce)(void *,void *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_scan_(void * sendbuf,void * recvbuf,int * count,int * datatype,int * op,int * comm,int * ret);
#pragma weak mpi_scan_=pmpi_scan_
void  (*INTERFACE_F_LOCAL_MPI_Scan)(void *,void *,int *,int *,int *,int *,int *);

void pmpi_scan_(void * sendbuf,void * recvbuf,int * count,int * datatype,int * op,int * comm,int * ret){

return  INTERFACE_F_LOCAL_MPI_Scan(sendbuf,recvbuf, count,datatype,op,comm, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Scan)(void *,void *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Scan)(void *,void *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_group_size_(int * group,int * size,int * ret);
#pragma weak mpi_group_size_=pmpi_group_size_
void  (*INTERFACE_F_LOCAL_MPI_Group_size)(int *,int *,int *);

void pmpi_group_size_(int * group,int * size,int * ret){

return  INTERFACE_F_LOCAL_MPI_Group_size(group, size, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Group_size)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Group_size)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_group_rank_(int * group,int * rank,int * ret);
#pragma weak mpi_group_rank_=pmpi_group_rank_
void  (*INTERFACE_F_LOCAL_MPI_Group_rank)(int *,int *,int *);

void pmpi_group_rank_(int * group,int * rank,int * ret){

return  INTERFACE_F_LOCAL_MPI_Group_rank(group, rank, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Group_rank)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Group_rank)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_group_compare_(int * group1,int * group2,int * result,int * ret);
#pragma weak mpi_group_compare_=pmpi_group_compare_
void  (*INTERFACE_F_LOCAL_MPI_Group_compare)(int *,int *,int *,int *);

void pmpi_group_compare_(int * group1,int * group2,int * result,int * ret){

return  INTERFACE_F_LOCAL_MPI_Group_compare(group1,group2, result, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Group_compare)(int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Group_compare)(int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_comm_group_(int * comm,int * group,int * ret);
#pragma weak mpi_comm_group_=pmpi_comm_group_
void  (*INTERFACE_F_LOCAL_MPI_Comm_group)(int *,int *,int *);

void pmpi_comm_group_(int * comm,int * group,int * ret){

return  INTERFACE_F_LOCAL_MPI_Comm_group(comm,group, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Comm_group)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Comm_group)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_group_union_(int * group1,int * group2,int * newgroup,int * ret);
#pragma weak mpi_group_union_=pmpi_group_union_
void  (*INTERFACE_F_LOCAL_MPI_Group_union)(int *,int *,int *,int *);

void pmpi_group_union_(int * group1,int * group2,int * newgroup,int * ret){

return  INTERFACE_F_LOCAL_MPI_Group_union(group1,group2,newgroup, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Group_union)(int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Group_union)(int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_group_intersection_(int * group1,int * group2,int * newgroup,int * ret);
#pragma weak mpi_group_intersection_=pmpi_group_intersection_
void  (*INTERFACE_F_LOCAL_MPI_Group_intersection)(int *,int *,int *,int *);

void pmpi_group_intersection_(int * group1,int * group2,int * newgroup,int * ret){

return  INTERFACE_F_LOCAL_MPI_Group_intersection(group1,group2,newgroup, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Group_intersection)(int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Group_intersection)(int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_group_difference_(int * group1,int * group2,int * newgroup,int * ret);
#pragma weak mpi_group_difference_=pmpi_group_difference_
void  (*INTERFACE_F_LOCAL_MPI_Group_difference)(int *,int *,int *,int *);

void pmpi_group_difference_(int * group1,int * group2,int * newgroup,int * ret){

return  INTERFACE_F_LOCAL_MPI_Group_difference(group1,group2,newgroup, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Group_difference)(int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Group_difference)(int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_group_free_(int * group,int * ret);
#pragma weak mpi_group_free_=pmpi_group_free_
void  (*INTERFACE_F_LOCAL_MPI_Group_free)(int *,int *);

void pmpi_group_free_(int * group,int * ret){

return  INTERFACE_F_LOCAL_MPI_Group_free(group, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Group_free)(int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Group_free)(int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_comm_size_(int * comm,int * size,int * ret);
#pragma weak mpi_comm_size_=pmpi_comm_size_
void  (*INTERFACE_F_LOCAL_MPI_Comm_size)(int *,int *,int *);

void pmpi_comm_size_(int * comm,int * size,int * ret){

return  INTERFACE_F_LOCAL_MPI_Comm_size(comm, size, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Comm_size)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Comm_size)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_comm_rank_(int * comm,int * rank,int * ret);
#pragma weak mpi_comm_rank_=pmpi_comm_rank_
void  (*INTERFACE_F_LOCAL_MPI_Comm_rank)(int *,int *,int *);

void pmpi_comm_rank_(int * comm,int * rank,int * ret){

return  INTERFACE_F_LOCAL_MPI_Comm_rank(comm, rank, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Comm_rank)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Comm_rank)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_comm_compare_(int * comm1,int * comm2,int * result,int * ret);
#pragma weak mpi_comm_compare_=pmpi_comm_compare_
void  (*INTERFACE_F_LOCAL_MPI_Comm_compare)(int *,int *,int *,int *);

void pmpi_comm_compare_(int * comm1,int * comm2,int * result,int * ret){

return  INTERFACE_F_LOCAL_MPI_Comm_compare(comm1,comm2, result, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Comm_compare)(int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Comm_compare)(int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_comm_dup_(int * comm,int * newcomm,int * ret);
#pragma weak mpi_comm_dup_=pmpi_comm_dup_
void  (*INTERFACE_F_LOCAL_MPI_Comm_dup)(int *,int *,int *);

void pmpi_comm_dup_(int * comm,int * newcomm,int * ret){

return  INTERFACE_F_LOCAL_MPI_Comm_dup(comm,newcomm, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Comm_dup)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Comm_dup)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_comm_dup_with_info_(int * comm,int * info,int * newcomm,int * ret);
#pragma weak mpi_comm_dup_with_info_=pmpi_comm_dup_with_info_
void  (*INTERFACE_F_LOCAL_MPI_Comm_dup_with_info)(int *,int *,int *,int *);

void pmpi_comm_dup_with_info_(int * comm,int * info,int * newcomm,int * ret){

return  INTERFACE_F_LOCAL_MPI_Comm_dup_with_info(comm,info,newcomm, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Comm_dup_with_info)(int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Comm_dup_with_info)(int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_comm_create_(int * comm,int * group,int * newcomm,int * ret);
#pragma weak mpi_comm_create_=pmpi_comm_create_
void  (*INTERFACE_F_LOCAL_MPI_Comm_create)(int *,int *,int *,int *);

void pmpi_comm_create_(int * comm,int * group,int * newcomm,int * ret){

return  INTERFACE_F_LOCAL_MPI_Comm_create(comm,group,newcomm, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Comm_create)(int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Comm_create)(int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_comm_split_(int * comm,int * color,int * key,int * newcomm,int * ret);
#pragma weak mpi_comm_split_=pmpi_comm_split_
void  (*INTERFACE_F_LOCAL_MPI_Comm_split)(int *,int *,int *,int *,int *);

void pmpi_comm_split_(int * comm,int * color,int * key,int * newcomm,int * ret){

return  INTERFACE_F_LOCAL_MPI_Comm_split(comm, color, key,newcomm, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Comm_split)(int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Comm_split)(int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_comm_free_(int * comm,int * ret);
#pragma weak mpi_comm_free_=pmpi_comm_free_
void  (*INTERFACE_F_LOCAL_MPI_Comm_free)(int *,int *);

void pmpi_comm_free_(int * comm,int * ret){

return  INTERFACE_F_LOCAL_MPI_Comm_free(comm, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Comm_free)(int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Comm_free)(int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_comm_test_inter_(int * comm,int * flag,int * ret);
#pragma weak mpi_comm_test_inter_=pmpi_comm_test_inter_
void  (*INTERFACE_F_LOCAL_MPI_Comm_test_inter)(int *,int *,int *);

void pmpi_comm_test_inter_(int * comm,int * flag,int * ret){

return  INTERFACE_F_LOCAL_MPI_Comm_test_inter(comm, flag, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Comm_test_inter)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Comm_test_inter)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_comm_remote_size_(int * comm,int * size,int * ret);
#pragma weak mpi_comm_remote_size_=pmpi_comm_remote_size_
void  (*INTERFACE_F_LOCAL_MPI_Comm_remote_size)(int *,int *,int *);

void pmpi_comm_remote_size_(int * comm,int * size,int * ret){

return  INTERFACE_F_LOCAL_MPI_Comm_remote_size(comm, size, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Comm_remote_size)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Comm_remote_size)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_comm_remote_group_(int * comm,int * group,int * ret);
#pragma weak mpi_comm_remote_group_=pmpi_comm_remote_group_
void  (*INTERFACE_F_LOCAL_MPI_Comm_remote_group)(int *,int *,int *);

void pmpi_comm_remote_group_(int * comm,int * group,int * ret){

return  INTERFACE_F_LOCAL_MPI_Comm_remote_group(comm,group, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Comm_remote_group)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Comm_remote_group)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_intercomm_create_(int * local_comm,int * local_leader,int * peer_comm,int * remote_leader,int * tag,int * newintercomm,int * ret);
#pragma weak mpi_intercomm_create_=pmpi_intercomm_create_
void  (*INTERFACE_F_LOCAL_MPI_Intercomm_create)(int *,int *,int *,int *,int *,int *,int *);

void pmpi_intercomm_create_(int * local_comm,int * local_leader,int * peer_comm,int * remote_leader,int * tag,int * newintercomm,int * ret){

return  INTERFACE_F_LOCAL_MPI_Intercomm_create(local_comm, local_leader,peer_comm, remote_leader,tag,newintercomm, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Intercomm_create)(int *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Intercomm_create)(int *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_intercomm_merge_(int * intercomm,int * high,int * newintracomm,int * ret);
#pragma weak mpi_intercomm_merge_=pmpi_intercomm_merge_
void  (*INTERFACE_F_LOCAL_MPI_Intercomm_merge)(int *,int *,int *,int *);

void pmpi_intercomm_merge_(int * intercomm,int * high,int * newintracomm,int * ret){

return  INTERFACE_F_LOCAL_MPI_Intercomm_merge(intercomm, high,newintracomm, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Intercomm_merge)(int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Intercomm_merge)(int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_keyval_create_(void * copy_fn,void * delete_fn,int * keyval,void * extra_state,int * ret);
#pragma weak mpi_keyval_create_=pmpi_keyval_create_
void  (*INTERFACE_F_LOCAL_MPI_Keyval_create)(void *,void *,int *,void *,int *);

void pmpi_keyval_create_(void * copy_fn,void * delete_fn,int * keyval,void * extra_state,int * ret){

return  INTERFACE_F_LOCAL_MPI_Keyval_create(copy_fn,delete_fn, keyval,extra_state, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Keyval_create)(void *,void *,int *,void *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Keyval_create)(void *,void *,int *,void *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_keyval_free_(int * keyval,int * ret);
#pragma weak mpi_keyval_free_=pmpi_keyval_free_
void  (*INTERFACE_F_LOCAL_MPI_Keyval_free)(int *,int *);

void pmpi_keyval_free_(int * keyval,int * ret){

return  INTERFACE_F_LOCAL_MPI_Keyval_free( keyval, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Keyval_free)(int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Keyval_free)(int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_attr_put_(int * comm,int * keyval,int * attribute_val,int * ret);
#pragma weak mpi_attr_put_=pmpi_attr_put_
void  (*INTERFACE_F_LOCAL_MPI_Attr_put)(int *,int *,int *,int *);

void pmpi_attr_put_(int * comm,int * keyval,int * attribute_val,int * ret){

return  INTERFACE_F_LOCAL_MPI_Attr_put(comm, keyval, attribute_val, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Attr_put)(int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Attr_put)(int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_attr_get_(int * comm,int * keyval,int * attribute_val,int * flag,int * ret);
#pragma weak mpi_attr_get_=pmpi_attr_get_
void  (*INTERFACE_F_LOCAL_MPI_Attr_get)(int *,int *,int *,int *,int *);

void pmpi_attr_get_(int * comm,int * keyval,int * attribute_val,int * flag,int * ret){

return  INTERFACE_F_LOCAL_MPI_Attr_get(comm,keyval, attribute_val, flag, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Attr_get)(int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Attr_get)(int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_attr_delete_(int * comm,int * keyval,int * ret);
#pragma weak mpi_attr_delete_=pmpi_attr_delete_
void  (*INTERFACE_F_LOCAL_MPI_Attr_delete)(int *,int *,int *);

void pmpi_attr_delete_(int * comm,int * keyval,int * ret){

return  INTERFACE_F_LOCAL_MPI_Attr_delete(comm,keyval, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Attr_delete)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Attr_delete)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_topo_test_(int * comm,int * status,int * ret);
#pragma weak mpi_topo_test_=pmpi_topo_test_
void  (*INTERFACE_F_LOCAL_MPI_Topo_test)(int *,int *,int *);

void pmpi_topo_test_(int * comm,int * status,int * ret){

return  INTERFACE_F_LOCAL_MPI_Topo_test(comm,status, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Topo_test)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Topo_test)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_graphdims_get_(int * comm,int * nnodes,int * nedges,int * ret);
#pragma weak mpi_graphdims_get_=pmpi_graphdims_get_
void  (*INTERFACE_F_LOCAL_MPI_Graphdims_get)(int *,int *,int *,int *);

void pmpi_graphdims_get_(int * comm,int * nnodes,int * nedges,int * ret){

return  INTERFACE_F_LOCAL_MPI_Graphdims_get(comm, nnodes, nedges, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Graphdims_get)(int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Graphdims_get)(int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_cartdim_get_(int * comm,int * ndims,int * ret);
#pragma weak mpi_cartdim_get_=pmpi_cartdim_get_
void  (*INTERFACE_F_LOCAL_MPI_Cartdim_get)(int *,int *,int *);

void pmpi_cartdim_get_(int * comm,int * ndims,int * ret){

return  INTERFACE_F_LOCAL_MPI_Cartdim_get(comm, ndims, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Cartdim_get)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Cartdim_get)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_graph_neighbors_count_(int * comm,int * rank,int * nneighbors,int * ret);
#pragma weak mpi_graph_neighbors_count_=pmpi_graph_neighbors_count_
void  (*INTERFACE_F_LOCAL_MPI_Graph_neighbors_count)(int *,int *,int *,int *);

void pmpi_graph_neighbors_count_(int * comm,int * rank,int * nneighbors,int * ret){

return  INTERFACE_F_LOCAL_MPI_Graph_neighbors_count(comm, rank, nneighbors, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Graph_neighbors_count)(int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Graph_neighbors_count)(int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_cart_shift_(int * comm,int * direction,int * disp,int * rank_source,int * rank_dest,int * ret);
#pragma weak mpi_cart_shift_=pmpi_cart_shift_
void  (*INTERFACE_F_LOCAL_MPI_Cart_shift)(int *,int *,int *,int *,int *,int *);

void pmpi_cart_shift_(int * comm,int * direction,int * disp,int * rank_source,int * rank_dest,int * ret){

return  INTERFACE_F_LOCAL_MPI_Cart_shift(comm, direction, disp, rank_source, rank_dest, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Cart_shift)(int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Cart_shift)(int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_get_version_(int * version,int * subversion,int * ret);
#pragma weak mpi_get_version_=pmpi_get_version_
void  (*INTERFACE_F_LOCAL_MPI_Get_version)(int *,int *,int *);

void pmpi_get_version_(int * version,int * subversion,int * ret){

return  INTERFACE_F_LOCAL_MPI_Get_version( version, subversion, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Get_version)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Get_version)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_errhandler_create_(void * function,int * errhandler,int * ret);
#pragma weak mpi_errhandler_create_=pmpi_errhandler_create_
void  (*INTERFACE_F_LOCAL_MPI_Errhandler_create)(void *,int *,int *);

void pmpi_errhandler_create_(void * function,int * errhandler,int * ret){

return  INTERFACE_F_LOCAL_MPI_Errhandler_create(function,errhandler, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Errhandler_create)(void *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Errhandler_create)(void *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_errhandler_set_(int * comm,int * errhandler,int * ret);
#pragma weak mpi_errhandler_set_=pmpi_errhandler_set_
void  (*INTERFACE_F_LOCAL_MPI_Errhandler_set)(int *,int *,int *);

void pmpi_errhandler_set_(int * comm,int * errhandler,int * ret){

return  INTERFACE_F_LOCAL_MPI_Errhandler_set(comm,errhandler, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Errhandler_set)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Errhandler_set)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_errhandler_get_(int * comm,int * errhandler,int * ret);
#pragma weak mpi_errhandler_get_=pmpi_errhandler_get_
void  (*INTERFACE_F_LOCAL_MPI_Errhandler_get)(int *,int *,int *);

void pmpi_errhandler_get_(int * comm,int * errhandler,int * ret){

return  INTERFACE_F_LOCAL_MPI_Errhandler_get(comm,errhandler, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Errhandler_get)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Errhandler_get)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_errhandler_free_(int * errhandler,int * ret);
#pragma weak mpi_errhandler_free_=pmpi_errhandler_free_
void  (*INTERFACE_F_LOCAL_MPI_Errhandler_free)(int *,int *);

void pmpi_errhandler_free_(int * errhandler,int * ret){

return  INTERFACE_F_LOCAL_MPI_Errhandler_free(errhandler, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Errhandler_free)(int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Errhandler_free)(int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_error_class_(int * errorcode,int * errorclass,int * ret);
#pragma weak mpi_error_class_=pmpi_error_class_
void  (*INTERFACE_F_LOCAL_MPI_Error_class)(int *,int *,int *);

void pmpi_error_class_(int * errorcode,int * errorclass,int * ret){

return  INTERFACE_F_LOCAL_MPI_Error_class(errorcode,errorclass, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Error_class)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Error_class)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_initialized_(int * flag,int * ret);
#pragma weak mpi_initialized_=pmpi_initialized_
void  (*INTERFACE_F_LOCAL_MPI_Initialized)(int *,int *);

void pmpi_initialized_(int * flag,int * ret){

return  INTERFACE_F_LOCAL_MPI_Initialized( flag, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Initialized)(int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Initialized)(int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_abort_(int * comm,int * errorcode,int * ret);
#pragma weak mpi_abort_=pmpi_abort_
void  (*INTERFACE_F_LOCAL_MPI_Abort)(int *,int *,int *);

void pmpi_abort_(int * comm,int * errorcode,int * ret){

return  INTERFACE_F_LOCAL_MPI_Abort(comm,errorcode, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Abort)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Abort)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_init_(int * ret);
#pragma weak mpi_init_=pmpi_init_
void  (*INTERFACE_F_LOCAL_MPI_Init)(int *);

void pmpi_init_(int * ret){

return  INTERFACE_F_LOCAL_MPI_Init( ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Init)(int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Init)(int *);
#endif /*WI4MPI_STATIC*/
void  mpi_comm_accept_(char * port_name,int * info,int * root,int * comm,int * newcomm,int * ret);
#pragma weak mpi_comm_accept_=pmpi_comm_accept_
void  (*INTERFACE_F_LOCAL_MPI_Comm_accept)(char *,int *,int *,int *,int *,int *);

void pmpi_comm_accept_(char * port_name,int * info,int * root,int * comm,int * newcomm,int * ret){

return  INTERFACE_F_LOCAL_MPI_Comm_accept( port_name,info,root,comm,newcomm, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Comm_accept)(char *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Comm_accept)(char *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_comm_connect_(char * port_name,int * info,int * root,int * comm,int * newcomm,int * ret);
#pragma weak mpi_comm_connect_=pmpi_comm_connect_
void  (*INTERFACE_F_LOCAL_MPI_Comm_connect)(char *,int *,int *,int *,int *,int *);

void pmpi_comm_connect_(char * port_name,int * info,int * root,int * comm,int * newcomm,int * ret){

return  INTERFACE_F_LOCAL_MPI_Comm_connect( port_name,info,root,comm,newcomm, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Comm_connect)(char *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Comm_connect)(char *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_comm_disconnect_(int * comm,int * ret);
#pragma weak mpi_comm_disconnect_=pmpi_comm_disconnect_
void  (*INTERFACE_F_LOCAL_MPI_Comm_disconnect)(int *,int *);

void pmpi_comm_disconnect_(int * comm,int * ret){

return  INTERFACE_F_LOCAL_MPI_Comm_disconnect(comm, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Comm_disconnect)(int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Comm_disconnect)(int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_comm_get_parent_(int * parent,int * ret);
#pragma weak mpi_comm_get_parent_=pmpi_comm_get_parent_
void  (*INTERFACE_F_LOCAL_MPI_Comm_get_parent)(int *,int *);

void pmpi_comm_get_parent_(int * parent,int * ret){

return  INTERFACE_F_LOCAL_MPI_Comm_get_parent(parent, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Comm_get_parent)(int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Comm_get_parent)(int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_comm_join_(int * fd,int * intercomm,int * ret);
#pragma weak mpi_comm_join_=pmpi_comm_join_
void  (*INTERFACE_F_LOCAL_MPI_Comm_join)(int *,int *,int *);

void pmpi_comm_join_(int * fd,int * intercomm,int * ret){

return  INTERFACE_F_LOCAL_MPI_Comm_join( fd,intercomm, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Comm_join)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Comm_join)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_comm_set_info_(int * comm,int * info,int * ret);
#pragma weak mpi_comm_set_info_=pmpi_comm_set_info_
void  (*INTERFACE_F_LOCAL_MPI_Comm_set_info)(int *,int *,int *);

void pmpi_comm_set_info_(int * comm,int * info,int * ret){

return  INTERFACE_F_LOCAL_MPI_Comm_set_info(comm,info, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Comm_set_info)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Comm_set_info)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_comm_get_info_(int * comm,int * info,int * ret);
#pragma weak mpi_comm_get_info_=pmpi_comm_get_info_
void  (*INTERFACE_F_LOCAL_MPI_Comm_get_info)(int *,int *,int *);

void pmpi_comm_get_info_(int * comm,int * info,int * ret){

return  INTERFACE_F_LOCAL_MPI_Comm_get_info(comm,info, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Comm_get_info)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Comm_get_info)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_accumulate_(void * origin_addr,int * origin_count,int * origin_datatype,int * target_rank,size_t * target_disp,int * target_count,int * target_datatype,int * op,int * win,int * ret);
#pragma weak mpi_accumulate_=pmpi_accumulate_
void  (*INTERFACE_F_LOCAL_MPI_Accumulate)(void *,int *,int *,int *,size_t *,int *,int *,int *,int *,int *);

void pmpi_accumulate_(void * origin_addr,int * origin_count,int * origin_datatype,int * target_rank,size_t * target_disp,int * target_count,int * target_datatype,int * op,int * win,int * ret){

return  INTERFACE_F_LOCAL_MPI_Accumulate(origin_addr, origin_count,origin_datatype,target_rank, target_disp, target_count,target_datatype,op,win, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Accumulate)(void *,int *,int *,int *,size_t *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Accumulate)(void *,int *,int *,int *,size_t *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_get_(void * origin_addr,int * origin_count,int * origin_datatype,int * target_rank,size_t * target_disp,int * target_count,int * target_datatype,int * win,int * ret);
#pragma weak mpi_get_=pmpi_get_
void  (*INTERFACE_F_LOCAL_MPI_Get)(void *,int *,int *,int *,size_t *,int *,int *,int *,int *);

void pmpi_get_(void * origin_addr,int * origin_count,int * origin_datatype,int * target_rank,size_t * target_disp,int * target_count,int * target_datatype,int * win,int * ret){

return  INTERFACE_F_LOCAL_MPI_Get(origin_addr, origin_count,origin_datatype,target_rank, target_disp, target_count,target_datatype,win, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Get)(void *,int *,int *,int *,size_t *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Get)(void *,int *,int *,int *,size_t *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_put_(void * origin_addr,int * origin_count,int * origin_datatype,int * target_rank,size_t * target_disp,int * target_count,int * target_datatype,int * win,int * ret);
#pragma weak mpi_put_=pmpi_put_
void  (*INTERFACE_F_LOCAL_MPI_Put)(void *,int *,int *,int *,size_t *,int *,int *,int *,int *);

void pmpi_put_(void * origin_addr,int * origin_count,int * origin_datatype,int * target_rank,size_t * target_disp,int * target_count,int * target_datatype,int * win,int * ret){

return  INTERFACE_F_LOCAL_MPI_Put(origin_addr, origin_count,origin_datatype,target_rank, target_disp, target_count,target_datatype,win, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Put)(void *,int *,int *,int *,size_t *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Put)(void *,int *,int *,int *,size_t *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_win_complete_(int * win,int * ret);
#pragma weak mpi_win_complete_=pmpi_win_complete_
void  (*INTERFACE_F_LOCAL_MPI_Win_complete)(int *,int *);

void pmpi_win_complete_(int * win,int * ret){

return  INTERFACE_F_LOCAL_MPI_Win_complete(win, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Win_complete)(int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Win_complete)(int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_win_create_(void * base,size_t * size,int * disp_unit,int * info,int * comm,int * win,int * ret);
#pragma weak mpi_win_create_=pmpi_win_create_
void  (*INTERFACE_F_LOCAL_MPI_Win_create)(void *,size_t *,int *,int *,int *,int *,int *);

void pmpi_win_create_(void * base,size_t * size,int * disp_unit,int * info,int * comm,int * win,int * ret){

return  INTERFACE_F_LOCAL_MPI_Win_create(base, size, disp_unit,info,comm,win, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Win_create)(void *,size_t *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Win_create)(void *,size_t *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_win_fence_(int * assert,int * win,int * ret);
#pragma weak mpi_win_fence_=pmpi_win_fence_
void  (*INTERFACE_F_LOCAL_MPI_Win_fence)(int *,int *,int *);

void pmpi_win_fence_(int * assert,int * win,int * ret){

return  INTERFACE_F_LOCAL_MPI_Win_fence(assert,win, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Win_fence)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Win_fence)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_win_free_(int * win,int * ret);
#pragma weak mpi_win_free_=pmpi_win_free_
void  (*INTERFACE_F_LOCAL_MPI_Win_free)(int *,int *);

void pmpi_win_free_(int * win,int * ret){

return  INTERFACE_F_LOCAL_MPI_Win_free(win, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Win_free)(int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Win_free)(int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_win_get_group_(int * win,int * group,int * ret);
#pragma weak mpi_win_get_group_=pmpi_win_get_group_
void  (*INTERFACE_F_LOCAL_MPI_Win_get_group)(int *,int *,int *);

void pmpi_win_get_group_(int * win,int * group,int * ret){

return  INTERFACE_F_LOCAL_MPI_Win_get_group(win,group, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Win_get_group)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Win_get_group)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_win_lock_(int * lock_type,int * rank,int * assert,int * win,int * ret);
#pragma weak mpi_win_lock_=pmpi_win_lock_
void  (*INTERFACE_F_LOCAL_MPI_Win_lock)(int *,int *,int *,int *,int *);

void pmpi_win_lock_(int * lock_type,int * rank,int * assert,int * win,int * ret){

return  INTERFACE_F_LOCAL_MPI_Win_lock(lock_type,rank,assert,win, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Win_lock)(int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Win_lock)(int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_win_post_(int * group,int * assert,int * win,int * ret);
#pragma weak mpi_win_post_=pmpi_win_post_
void  (*INTERFACE_F_LOCAL_MPI_Win_post)(int *,int *,int *,int *);

void pmpi_win_post_(int * group,int * assert,int * win,int * ret){

return  INTERFACE_F_LOCAL_MPI_Win_post(group,assert,win, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Win_post)(int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Win_post)(int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_win_start_(int * group,int * assert,int * win,int * ret);
#pragma weak mpi_win_start_=pmpi_win_start_
void  (*INTERFACE_F_LOCAL_MPI_Win_start)(int *,int *,int *,int *);

void pmpi_win_start_(int * group,int * assert,int * win,int * ret){

return  INTERFACE_F_LOCAL_MPI_Win_start(group,assert,win, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Win_start)(int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Win_start)(int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_win_test_(int * win,int * flag,int * ret);
#pragma weak mpi_win_test_=pmpi_win_test_
void  (*INTERFACE_F_LOCAL_MPI_Win_test)(int *,int *,int *);

void pmpi_win_test_(int * win,int * flag,int * ret){

return  INTERFACE_F_LOCAL_MPI_Win_test(win, flag, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Win_test)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Win_test)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_win_unlock_(int * rank,int * win,int * ret);
#pragma weak mpi_win_unlock_=pmpi_win_unlock_
void  (*INTERFACE_F_LOCAL_MPI_Win_unlock)(int *,int *,int *);

void pmpi_win_unlock_(int * rank,int * win,int * ret){

return  INTERFACE_F_LOCAL_MPI_Win_unlock(rank,win, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Win_unlock)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Win_unlock)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_win_wait_(int * win,int * ret);
#pragma weak mpi_win_wait_=pmpi_win_wait_
void  (*INTERFACE_F_LOCAL_MPI_Win_wait)(int *,int *);

void pmpi_win_wait_(int * win,int * ret){

return  INTERFACE_F_LOCAL_MPI_Win_wait(win, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Win_wait)(int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Win_wait)(int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_win_allocate_(size_t * size,int * disp_unit,int * info,int * comm,void * baseptr,int * win,int * ret);
#pragma weak mpi_win_allocate_=pmpi_win_allocate_
void  (*INTERFACE_F_LOCAL_MPI_Win_allocate)(size_t *,int *,int *,int *,void *,int *,int *);

void pmpi_win_allocate_(size_t * size,int * disp_unit,int * info,int * comm,void * baseptr,int * win,int * ret){

return  INTERFACE_F_LOCAL_MPI_Win_allocate( size, disp_unit,info, comm,baseptr,win, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Win_allocate)(size_t *,int *,int *,int *,void *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Win_allocate)(size_t *,int *,int *,int *,void *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_win_allocate_shared_(size_t * size,int * disp_unit,int * info,int * comm,void * baseptr,int * win,int * ret);
#pragma weak mpi_win_allocate_shared_=pmpi_win_allocate_shared_
void  (*INTERFACE_F_LOCAL_MPI_Win_allocate_shared)(size_t *,int *,int *,int *,void *,int *,int *);

void pmpi_win_allocate_shared_(size_t * size,int * disp_unit,int * info,int * comm,void * baseptr,int * win,int * ret){

return  INTERFACE_F_LOCAL_MPI_Win_allocate_shared( size, disp_unit,info,comm,baseptr,win, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Win_allocate_shared)(size_t *,int *,int *,int *,void *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Win_allocate_shared)(size_t *,int *,int *,int *,void *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_win_shared_query_(int * win,int * rank,size_t * size,int * disp_unit,void * baseptr,int * ret);
#pragma weak mpi_win_shared_query_=pmpi_win_shared_query_
void  (*INTERFACE_F_LOCAL_MPI_Win_shared_query)(int *,int *,size_t *,int *,void *,int *);

void pmpi_win_shared_query_(int * win,int * rank,size_t * size,int * disp_unit,void * baseptr,int * ret){

return  INTERFACE_F_LOCAL_MPI_Win_shared_query(win, rank, size, disp_unit,baseptr, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Win_shared_query)(int *,int *,size_t *,int *,void *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Win_shared_query)(int *,int *,size_t *,int *,void *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_win_create_dynamic_(int * info,int * comm,int * win,int * ret);
#pragma weak mpi_win_create_dynamic_=pmpi_win_create_dynamic_
void  (*INTERFACE_F_LOCAL_MPI_Win_create_dynamic)(int *,int *,int *,int *);

void pmpi_win_create_dynamic_(int * info,int * comm,int * win,int * ret){

return  INTERFACE_F_LOCAL_MPI_Win_create_dynamic(info,comm,win, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Win_create_dynamic)(int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Win_create_dynamic)(int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_win_attach_(int * win,void * base,size_t * size,int * ret);
#pragma weak mpi_win_attach_=pmpi_win_attach_
void  (*INTERFACE_F_LOCAL_MPI_Win_attach)(int *,void *,size_t *,int *);

void pmpi_win_attach_(int * win,void * base,size_t * size,int * ret){

return  INTERFACE_F_LOCAL_MPI_Win_attach(win,base, size, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Win_attach)(int *,void *,size_t *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Win_attach)(int *,void *,size_t *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_win_detach_(int * win,void * base,int * ret);
#pragma weak mpi_win_detach_=pmpi_win_detach_
void  (*INTERFACE_F_LOCAL_MPI_Win_detach)(int *,void *,int *);

void pmpi_win_detach_(int * win,void * base,int * ret){

return  INTERFACE_F_LOCAL_MPI_Win_detach(win,base, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Win_detach)(int *,void *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Win_detach)(int *,void *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_win_get_info_(int * win,int * info_used,int * ret);
#pragma weak mpi_win_get_info_=pmpi_win_get_info_
void  (*INTERFACE_F_LOCAL_MPI_Win_get_info)(int *,int *,int *);

void pmpi_win_get_info_(int * win,int * info_used,int * ret){

return  INTERFACE_F_LOCAL_MPI_Win_get_info(win,info_used, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Win_get_info)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Win_get_info)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_win_set_info_(int * win,int * info,int * ret);
#pragma weak mpi_win_set_info_=pmpi_win_set_info_
void  (*INTERFACE_F_LOCAL_MPI_Win_set_info)(int *,int *,int *);

void pmpi_win_set_info_(int * win,int * info,int * ret){

return  INTERFACE_F_LOCAL_MPI_Win_set_info(win,info, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Win_set_info)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Win_set_info)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_get_accumulate_(void * origin_addr,int * origin_count,int * origin_datatype,void * result_addr,int * result_count,int * result_datatype,int * target_rank,size_t * target_disp,int * target_count,int * target_datatype,int * op,int * win,int * ret);
#pragma weak mpi_get_accumulate_=pmpi_get_accumulate_
void  (*INTERFACE_F_LOCAL_MPI_Get_accumulate)(void *,int *,int *,void *,int *,int *,int *,size_t *,int *,int *,int *,int *,int *);

void pmpi_get_accumulate_(void * origin_addr,int * origin_count,int * origin_datatype,void * result_addr,int * result_count,int * result_datatype,int * target_rank,size_t * target_disp,int * target_count,int * target_datatype,int * op,int * win,int * ret){

return  INTERFACE_F_LOCAL_MPI_Get_accumulate(origin_addr, origin_count,origin_datatype,result_addr, result_count,result_datatype,target_rank, target_disp, target_count,target_datatype,op,win, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Get_accumulate)(void *,int *,int *,void *,int *,int *,int *,size_t *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Get_accumulate)(void *,int *,int *,void *,int *,int *,int *,size_t *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_fetch_and_op_(void * origin_addr,void * result_addr,int * datatype,int * target_rank,size_t * target_disp,int * op,int * win,int * ret);
#pragma weak mpi_fetch_and_op_=pmpi_fetch_and_op_
void  (*INTERFACE_F_LOCAL_MPI_Fetch_and_op)(void *,void *,int *,int *,size_t *,int *,int *,int *);

void pmpi_fetch_and_op_(void * origin_addr,void * result_addr,int * datatype,int * target_rank,size_t * target_disp,int * op,int * win,int * ret){

return  INTERFACE_F_LOCAL_MPI_Fetch_and_op(origin_addr,result_addr,datatype,target_rank, target_disp,op,win, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Fetch_and_op)(void *,void *,int *,int *,size_t *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Fetch_and_op)(void *,void *,int *,int *,size_t *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_compare_and_swap_(void * origin_addr,void * compare_addr,void * result_addr,int * datatype,int * target_rank,size_t * target_disp,int * win,int * ret);
#pragma weak mpi_compare_and_swap_=pmpi_compare_and_swap_
void  (*INTERFACE_F_LOCAL_MPI_Compare_and_swap)(void *,void *,void *,int *,int *,size_t *,int *,int *);

void pmpi_compare_and_swap_(void * origin_addr,void * compare_addr,void * result_addr,int * datatype,int * target_rank,size_t * target_disp,int * win,int * ret){

return  INTERFACE_F_LOCAL_MPI_Compare_and_swap(origin_addr,compare_addr,result_addr,datatype,target_rank, target_disp,win, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Compare_and_swap)(void *,void *,void *,int *,int *,size_t *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Compare_and_swap)(void *,void *,void *,int *,int *,size_t *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_rput_(void * origin_addr,int * origin_count,int * origin_datatype,int * target_rank,size_t * target_disp,int * target_count,int * target_datatype,int * win,int * request,int * ret);
#pragma weak mpi_rput_=pmpi_rput_
void  (*INTERFACE_F_LOCAL_MPI_Rput)(void *,int *,int *,int *,size_t *,int *,int *,int *,int *,int *);

void pmpi_rput_(void * origin_addr,int * origin_count,int * origin_datatype,int * target_rank,size_t * target_disp,int * target_count,int * target_datatype,int * win,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Rput(origin_addr, origin_count,origin_datatype,target_rank, target_disp, target_count,target_datatype,win,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Rput)(void *,int *,int *,int *,size_t *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Rput)(void *,int *,int *,int *,size_t *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_rget_(void * origin_addr,int * origin_count,int * origin_datatype,int * target_rank,size_t * target_disp,int * target_count,int * target_datatype,int * win,int * request,int * ret);
#pragma weak mpi_rget_=pmpi_rget_
void  (*INTERFACE_F_LOCAL_MPI_Rget)(void *,int *,int *,int *,size_t *,int *,int *,int *,int *,int *);

void pmpi_rget_(void * origin_addr,int * origin_count,int * origin_datatype,int * target_rank,size_t * target_disp,int * target_count,int * target_datatype,int * win,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Rget(origin_addr, origin_count,origin_datatype,target_rank, target_disp, target_count,target_datatype,win,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Rget)(void *,int *,int *,int *,size_t *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Rget)(void *,int *,int *,int *,size_t *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_raccumulate_(void * origin_addr,int * origin_count,int * origin_datatype,int * target_rank,size_t * target_disp,int * target_count,int * target_datatype,int * op,int * win,int * request,int * ret);
#pragma weak mpi_raccumulate_=pmpi_raccumulate_
void  (*INTERFACE_F_LOCAL_MPI_Raccumulate)(void *,int *,int *,int *,size_t *,int *,int *,int *,int *,int *,int *);

void pmpi_raccumulate_(void * origin_addr,int * origin_count,int * origin_datatype,int * target_rank,size_t * target_disp,int * target_count,int * target_datatype,int * op,int * win,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Raccumulate(origin_addr, origin_count,origin_datatype,target_rank, target_disp, target_count,target_datatype,op,win,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Raccumulate)(void *,int *,int *,int *,size_t *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Raccumulate)(void *,int *,int *,int *,size_t *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_rget_accumulate_(void * origin_addr,int * origin_count,int * origin_datatype,void * result_addr,int * result_count,int * result_datatype,int * target_rank,size_t * target_disp,int * target_count,int * target_datatype,int * op,int * win,int * request,int * ret);
#pragma weak mpi_rget_accumulate_=pmpi_rget_accumulate_
void  (*INTERFACE_F_LOCAL_MPI_Rget_accumulate)(void *,int *,int *,void *,int *,int *,int *,size_t *,int *,int *,int *,int *,int *,int *);

void pmpi_rget_accumulate_(void * origin_addr,int * origin_count,int * origin_datatype,void * result_addr,int * result_count,int * result_datatype,int * target_rank,size_t * target_disp,int * target_count,int * target_datatype,int * op,int * win,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Rget_accumulate(origin_addr, origin_count,origin_datatype,result_addr, result_count,result_datatype,target_rank, target_disp, target_count,target_datatype,op,win,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Rget_accumulate)(void *,int *,int *,void *,int *,int *,int *,size_t *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Rget_accumulate)(void *,int *,int *,void *,int *,int *,int *,size_t *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_win_lock_all_(int * assert,int * win,int * ret);
#pragma weak mpi_win_lock_all_=pmpi_win_lock_all_
void  (*INTERFACE_F_LOCAL_MPI_Win_lock_all)(int *,int *,int *);

void pmpi_win_lock_all_(int * assert,int * win,int * ret){

return  INTERFACE_F_LOCAL_MPI_Win_lock_all(assert,win, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Win_lock_all)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Win_lock_all)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_win_unlock_all_(int * win,int * ret);
#pragma weak mpi_win_unlock_all_=pmpi_win_unlock_all_
void  (*INTERFACE_F_LOCAL_MPI_Win_unlock_all)(int *,int *);

void pmpi_win_unlock_all_(int * win,int * ret){

return  INTERFACE_F_LOCAL_MPI_Win_unlock_all(win, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Win_unlock_all)(int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Win_unlock_all)(int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_win_flush_(int * rank,int * win,int * ret);
#pragma weak mpi_win_flush_=pmpi_win_flush_
void  (*INTERFACE_F_LOCAL_MPI_Win_flush)(int *,int *,int *);

void pmpi_win_flush_(int * rank,int * win,int * ret){

return  INTERFACE_F_LOCAL_MPI_Win_flush(rank,win, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Win_flush)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Win_flush)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_win_flush_all_(int * win,int * ret);
#pragma weak mpi_win_flush_all_=pmpi_win_flush_all_
void  (*INTERFACE_F_LOCAL_MPI_Win_flush_all)(int *,int *);

void pmpi_win_flush_all_(int * win,int * ret){

return  INTERFACE_F_LOCAL_MPI_Win_flush_all(win, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Win_flush_all)(int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Win_flush_all)(int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_win_flush_local_(int * rank,int * win,int * ret);
#pragma weak mpi_win_flush_local_=pmpi_win_flush_local_
void  (*INTERFACE_F_LOCAL_MPI_Win_flush_local)(int *,int *,int *);

void pmpi_win_flush_local_(int * rank,int * win,int * ret){

return  INTERFACE_F_LOCAL_MPI_Win_flush_local(rank,win, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Win_flush_local)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Win_flush_local)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_win_flush_local_all_(int * win,int * ret);
#pragma weak mpi_win_flush_local_all_=pmpi_win_flush_local_all_
void  (*INTERFACE_F_LOCAL_MPI_Win_flush_local_all)(int *,int *);

void pmpi_win_flush_local_all_(int * win,int * ret){

return  INTERFACE_F_LOCAL_MPI_Win_flush_local_all(win, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Win_flush_local_all)(int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Win_flush_local_all)(int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_win_sync_(int * win,int * ret);
#pragma weak mpi_win_sync_=pmpi_win_sync_
void  (*INTERFACE_F_LOCAL_MPI_Win_sync)(int *,int *);

void pmpi_win_sync_(int * win,int * ret){

return  INTERFACE_F_LOCAL_MPI_Win_sync(win, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Win_sync)(int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Win_sync)(int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_add_error_class_(int * errorclass,int * ret);
#pragma weak mpi_add_error_class_=pmpi_add_error_class_
void  (*INTERFACE_F_LOCAL_MPI_Add_error_class)(int *,int *);

void pmpi_add_error_class_(int * errorclass,int * ret){

return  INTERFACE_F_LOCAL_MPI_Add_error_class(errorclass, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Add_error_class)(int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Add_error_class)(int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_add_error_code_(int * errorclass,int * errorcode,int * ret);
#pragma weak mpi_add_error_code_=pmpi_add_error_code_
void  (*INTERFACE_F_LOCAL_MPI_Add_error_code)(int *,int *,int *);

void pmpi_add_error_code_(int * errorclass,int * errorcode,int * ret){

return  INTERFACE_F_LOCAL_MPI_Add_error_code( errorclass,errorcode, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Add_error_code)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Add_error_code)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_comm_call_errhandler_(int * comm,int * errorcode,int * ret);
#pragma weak mpi_comm_call_errhandler_=pmpi_comm_call_errhandler_
void  (*INTERFACE_F_LOCAL_MPI_Comm_call_errhandler)(int *,int *,int *);

void pmpi_comm_call_errhandler_(int * comm,int * errorcode,int * ret){

return  INTERFACE_F_LOCAL_MPI_Comm_call_errhandler(comm,errorcode, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Comm_call_errhandler)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Comm_call_errhandler)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_comm_create_keyval_(void * comm_copy_attr_fn,void * comm_delete_attr_fn,int * comm_keyval,void * extra_state,int * ret);
#pragma weak mpi_comm_create_keyval_=pmpi_comm_create_keyval_
void  (*INTERFACE_F_LOCAL_MPI_Comm_create_keyval)(void *,void *,int *,void *,int *);

void pmpi_comm_create_keyval_(void * comm_copy_attr_fn,void * comm_delete_attr_fn,int * comm_keyval,void * extra_state,int * ret){

return  INTERFACE_F_LOCAL_MPI_Comm_create_keyval(comm_copy_attr_fn,comm_delete_attr_fn,comm_keyval,extra_state, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Comm_create_keyval)(void *,void *,int *,void *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Comm_create_keyval)(void *,void *,int *,void *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_comm_delete_attr_(int * comm,int * comm_keyval,int * ret);
#pragma weak mpi_comm_delete_attr_=pmpi_comm_delete_attr_
void  (*INTERFACE_F_LOCAL_MPI_Comm_delete_attr)(int *,int *,int *);

void pmpi_comm_delete_attr_(int * comm,int * comm_keyval,int * ret){

return  INTERFACE_F_LOCAL_MPI_Comm_delete_attr(comm,comm_keyval, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Comm_delete_attr)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Comm_delete_attr)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_comm_free_keyval_(int * comm_keyval,int * ret);
#pragma weak mpi_comm_free_keyval_=pmpi_comm_free_keyval_
void  (*INTERFACE_F_LOCAL_MPI_Comm_free_keyval)(int *,int *);

void pmpi_comm_free_keyval_(int * comm_keyval,int * ret){

return  INTERFACE_F_LOCAL_MPI_Comm_free_keyval(comm_keyval, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Comm_free_keyval)(int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Comm_free_keyval)(int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_comm_get_attr_(int * comm,int * comm_keyval,void * attribute_val,int * flag,int * ret);
#pragma weak mpi_comm_get_attr_=pmpi_comm_get_attr_
void  (*INTERFACE_F_LOCAL_MPI_Comm_get_attr)(int *,int *,void *,int *,int *);

void pmpi_comm_get_attr_(int * comm,int * comm_keyval,void * attribute_val,int * flag,int * ret){

return  INTERFACE_F_LOCAL_MPI_Comm_get_attr(comm,comm_keyval,attribute_val, flag, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Comm_get_attr)(int *,int *,void *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Comm_get_attr)(int *,int *,void *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_comm_set_attr_(int * comm,int * comm_keyval,void * attribute_val,int * ret);
#pragma weak mpi_comm_set_attr_=pmpi_comm_set_attr_
void  (*INTERFACE_F_LOCAL_MPI_Comm_set_attr)(int *,int *,void *,int *);

void pmpi_comm_set_attr_(int * comm,int * comm_keyval,void * attribute_val,int * ret){

return  INTERFACE_F_LOCAL_MPI_Comm_set_attr(comm,comm_keyval,attribute_val, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Comm_set_attr)(int *,int *,void *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Comm_set_attr)(int *,int *,void *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_call_errhandler_(int * fh,int * errorcode,int * ret);
#pragma weak mpi_file_call_errhandler_=pmpi_file_call_errhandler_
void  (*INTERFACE_F_LOCAL_MPI_File_call_errhandler)(int *,int *,int *);

void pmpi_file_call_errhandler_(int * fh,int * errorcode,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_call_errhandler( fh,errorcode, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_call_errhandler)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_call_errhandler)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_grequest_complete_(int * request,int * ret);
#pragma weak mpi_grequest_complete_=pmpi_grequest_complete_
void  (*INTERFACE_F_LOCAL_MPI_Grequest_complete)(int *,int *);

void pmpi_grequest_complete_(int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Grequest_complete(request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Grequest_complete)(int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Grequest_complete)(int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_grequest_start_(void * query_fn,void * free_fn,void * cancel_fn,void * extra_state,int * request,int * ret);
#pragma weak mpi_grequest_start_=pmpi_grequest_start_
void  (*INTERFACE_F_LOCAL_MPI_Grequest_start)(void *,void *,void *,void *,int *,int *);

void pmpi_grequest_start_(void * query_fn,void * free_fn,void * cancel_fn,void * extra_state,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Grequest_start(query_fn,free_fn,cancel_fn,extra_state,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Grequest_start)(void *,void *,void *,void *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Grequest_start)(void *,void *,void *,void *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_init_thread_(int * required,int * provided,int * ret);
#pragma weak mpi_init_thread_=pmpi_init_thread_
void  (*INTERFACE_F_LOCAL_MPI_Init_thread)(int *,int *,int *);

void pmpi_init_thread_(int * required,int * provided,int * ret){

return  INTERFACE_F_LOCAL_MPI_Init_thread( required, provided, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Init_thread)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Init_thread)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_is_thread_main_(int * flag,int * ret);
#pragma weak mpi_is_thread_main_=pmpi_is_thread_main_
void  (*INTERFACE_F_LOCAL_MPI_Is_thread_main)(int *,int *);

void pmpi_is_thread_main_(int * flag,int * ret){

return  INTERFACE_F_LOCAL_MPI_Is_thread_main( flag, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Is_thread_main)(int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Is_thread_main)(int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_query_thread_(int * provided,int * ret);
#pragma weak mpi_query_thread_=pmpi_query_thread_
void  (*INTERFACE_F_LOCAL_MPI_Query_thread)(int *,int *);

void pmpi_query_thread_(int * provided,int * ret){

return  INTERFACE_F_LOCAL_MPI_Query_thread( provided, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Query_thread)(int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Query_thread)(int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_status_set_cancelled_(int * status,int * flag,int * ret);
#pragma weak mpi_status_set_cancelled_=pmpi_status_set_cancelled_
void  (*INTERFACE_F_LOCAL_MPI_Status_set_cancelled)(int *,int *,int *);

void pmpi_status_set_cancelled_(int * status,int * flag,int * ret){

return  INTERFACE_F_LOCAL_MPI_Status_set_cancelled(status, flag, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Status_set_cancelled)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Status_set_cancelled)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_status_set_elements_(int * status,int * datatype,int * count,int * ret);
#pragma weak mpi_status_set_elements_=pmpi_status_set_elements_
void  (*INTERFACE_F_LOCAL_MPI_Status_set_elements)(int *,int *,int *,int *);

void pmpi_status_set_elements_(int * status,int * datatype,int * count,int * ret){

return  INTERFACE_F_LOCAL_MPI_Status_set_elements(status,datatype, count, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Status_set_elements)(int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Status_set_elements)(int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_type_create_keyval_(void * type_copy_attr_fn,void * type_delete_attr_fn,int * type_keyval,void * extra_state,int * ret);
#pragma weak mpi_type_create_keyval_=pmpi_type_create_keyval_
void  (*INTERFACE_F_LOCAL_MPI_Type_create_keyval)(void *,void *,int *,void *,int *);

void pmpi_type_create_keyval_(void * type_copy_attr_fn,void * type_delete_attr_fn,int * type_keyval,void * extra_state,int * ret){

return  INTERFACE_F_LOCAL_MPI_Type_create_keyval(type_copy_attr_fn,type_delete_attr_fn,type_keyval,extra_state, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Type_create_keyval)(void *,void *,int *,void *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Type_create_keyval)(void *,void *,int *,void *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_type_delete_attr_(int * datatype,int * type_keyval,int * ret);
#pragma weak mpi_type_delete_attr_=pmpi_type_delete_attr_
void  (*INTERFACE_F_LOCAL_MPI_Type_delete_attr)(int *,int *,int *);

void pmpi_type_delete_attr_(int * datatype,int * type_keyval,int * ret){

return  INTERFACE_F_LOCAL_MPI_Type_delete_attr(datatype,type_keyval, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Type_delete_attr)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Type_delete_attr)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_type_dup_(int * oldtype,int * newtype,int * ret);
#pragma weak mpi_type_dup_=pmpi_type_dup_
void  (*INTERFACE_F_LOCAL_MPI_Type_dup)(int *,int *,int *);

void pmpi_type_dup_(int * oldtype,int * newtype,int * ret){

return  INTERFACE_F_LOCAL_MPI_Type_dup(oldtype,newtype, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Type_dup)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Type_dup)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_type_free_keyval_(int * type_keyval,int * ret);
#pragma weak mpi_type_free_keyval_=pmpi_type_free_keyval_
void  (*INTERFACE_F_LOCAL_MPI_Type_free_keyval)(int *,int *);

void pmpi_type_free_keyval_(int * type_keyval,int * ret){

return  INTERFACE_F_LOCAL_MPI_Type_free_keyval(type_keyval, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Type_free_keyval)(int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Type_free_keyval)(int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_type_get_attr_(int * datatype,int * type_keyval,void * attribute_val,int * flag,int * ret);
#pragma weak mpi_type_get_attr_=pmpi_type_get_attr_
void  (*INTERFACE_F_LOCAL_MPI_Type_get_attr)(int *,int *,void *,int *,int *);

void pmpi_type_get_attr_(int * datatype,int * type_keyval,void * attribute_val,int * flag,int * ret){

return  INTERFACE_F_LOCAL_MPI_Type_get_attr(datatype,type_keyval,attribute_val, flag, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Type_get_attr)(int *,int *,void *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Type_get_attr)(int *,int *,void *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_type_get_envelope_(int * datatype,int * num_integers,int * num_addresses,int * num_datatypes,int * combiner,int * ret);
#pragma weak mpi_type_get_envelope_=pmpi_type_get_envelope_
void  (*INTERFACE_F_LOCAL_MPI_Type_get_envelope)(int *,int *,int *,int *,int *,int *);

void pmpi_type_get_envelope_(int * datatype,int * num_integers,int * num_addresses,int * num_datatypes,int * combiner,int * ret){

return  INTERFACE_F_LOCAL_MPI_Type_get_envelope(datatype, num_integers, num_addresses, num_datatypes, combiner, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Type_get_envelope)(int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Type_get_envelope)(int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_type_set_attr_(int * datatype,int * type_keyval,void * attribute_val,int * ret);
#pragma weak mpi_type_set_attr_=pmpi_type_set_attr_
void  (*INTERFACE_F_LOCAL_MPI_Type_set_attr)(int *,int *,void *,int *);

void pmpi_type_set_attr_(int * datatype,int * type_keyval,void * attribute_val,int * ret){

return  INTERFACE_F_LOCAL_MPI_Type_set_attr(datatype,type_keyval,attribute_val, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Type_set_attr)(int *,int *,void *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Type_set_attr)(int *,int *,void *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_type_match_size_(int * typeclass,int * size,int * datatype,int * ret);
#pragma weak mpi_type_match_size_=pmpi_type_match_size_
void  (*INTERFACE_F_LOCAL_MPI_Type_match_size)(int *,int *,int *,int *);

void pmpi_type_match_size_(int * typeclass,int * size,int * datatype,int * ret){

return  INTERFACE_F_LOCAL_MPI_Type_match_size( typeclass, size,datatype, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Type_match_size)(int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Type_match_size)(int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_win_call_errhandler_(int * win,int * errorcode,int * ret);
#pragma weak mpi_win_call_errhandler_=pmpi_win_call_errhandler_
void  (*INTERFACE_F_LOCAL_MPI_Win_call_errhandler)(int *,int *,int *);

void pmpi_win_call_errhandler_(int * win,int * errorcode,int * ret){

return  INTERFACE_F_LOCAL_MPI_Win_call_errhandler(win,errorcode, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Win_call_errhandler)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Win_call_errhandler)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_win_create_keyval_(void * win_copy_attr_fn,void * win_delete_attr_fn,int * win_keyval,void * extra_state,int * ret);
#pragma weak mpi_win_create_keyval_=pmpi_win_create_keyval_
void  (*INTERFACE_F_LOCAL_MPI_Win_create_keyval)(void *,void *,int *,void *,int *);

void pmpi_win_create_keyval_(void * win_copy_attr_fn,void * win_delete_attr_fn,int * win_keyval,void * extra_state,int * ret){

return  INTERFACE_F_LOCAL_MPI_Win_create_keyval(win_copy_attr_fn,win_delete_attr_fn,win_keyval,extra_state, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Win_create_keyval)(void *,void *,int *,void *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Win_create_keyval)(void *,void *,int *,void *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_win_delete_attr_(int * win,int * win_keyval,int * ret);
#pragma weak mpi_win_delete_attr_=pmpi_win_delete_attr_
void  (*INTERFACE_F_LOCAL_MPI_Win_delete_attr)(int *,int *,int *);

void pmpi_win_delete_attr_(int * win,int * win_keyval,int * ret){

return  INTERFACE_F_LOCAL_MPI_Win_delete_attr(win,win_keyval, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Win_delete_attr)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Win_delete_attr)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_win_free_keyval_(int * win_keyval,int * ret);
#pragma weak mpi_win_free_keyval_=pmpi_win_free_keyval_
void  (*INTERFACE_F_LOCAL_MPI_Win_free_keyval)(int *,int *);

void pmpi_win_free_keyval_(int * win_keyval,int * ret){

return  INTERFACE_F_LOCAL_MPI_Win_free_keyval(win_keyval, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Win_free_keyval)(int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Win_free_keyval)(int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_win_get_attr_(int * win,int * win_keyval,void * attribute_val,int * flag,int * ret);
#pragma weak mpi_win_get_attr_=pmpi_win_get_attr_
void  (*INTERFACE_F_LOCAL_MPI_Win_get_attr)(int *,int *,void *,int *,int *);

void pmpi_win_get_attr_(int * win,int * win_keyval,void * attribute_val,int * flag,int * ret){

return  INTERFACE_F_LOCAL_MPI_Win_get_attr(win,win_keyval,attribute_val, flag, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Win_get_attr)(int *,int *,void *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Win_get_attr)(int *,int *,void *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_win_set_attr_(int * win,int * win_keyval,void * attribute_val,int * ret);
#pragma weak mpi_win_set_attr_=pmpi_win_set_attr_
void  (*INTERFACE_F_LOCAL_MPI_Win_set_attr)(int *,int *,void *,int *);

void pmpi_win_set_attr_(int * win,int * win_keyval,void * attribute_val,int * ret){

return  INTERFACE_F_LOCAL_MPI_Win_set_attr(win,win_keyval,attribute_val, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Win_set_attr)(int *,int *,void *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Win_set_attr)(int *,int *,void *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_alloc_mem_(size_t * size,int * info,void * baseptr,int * ret);
#pragma weak mpi_alloc_mem_=pmpi_alloc_mem_
void  (*INTERFACE_F_LOCAL_MPI_Alloc_mem)(size_t *,int *,void *,int *);

void pmpi_alloc_mem_(size_t * size,int * info,void * baseptr,int * ret){

return  INTERFACE_F_LOCAL_MPI_Alloc_mem( size,info,baseptr, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Alloc_mem)(size_t *,int *,void *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Alloc_mem)(size_t *,int *,void *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_comm_create_errhandler_(void * comm_errhandler_fn,int * errhandler,int * ret);
#pragma weak mpi_comm_create_errhandler_=pmpi_comm_create_errhandler_
void  (*INTERFACE_F_LOCAL_MPI_Comm_create_errhandler)(void *,int *,int *);

void pmpi_comm_create_errhandler_(void * comm_errhandler_fn,int * errhandler,int * ret){

return  INTERFACE_F_LOCAL_MPI_Comm_create_errhandler(comm_errhandler_fn,errhandler, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Comm_create_errhandler)(void *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Comm_create_errhandler)(void *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_comm_get_errhandler_(int * comm,int * errhandler,int * ret);
#pragma weak mpi_comm_get_errhandler_=pmpi_comm_get_errhandler_
void  (*INTERFACE_F_LOCAL_MPI_Comm_get_errhandler)(int *,int *,int *);

void pmpi_comm_get_errhandler_(int * comm,int * errhandler,int * ret){

return  INTERFACE_F_LOCAL_MPI_Comm_get_errhandler(comm,errhandler, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Comm_get_errhandler)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Comm_get_errhandler)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_comm_set_errhandler_(int * comm,int * errhandler,int * ret);
#pragma weak mpi_comm_set_errhandler_=pmpi_comm_set_errhandler_
void  (*INTERFACE_F_LOCAL_MPI_Comm_set_errhandler)(int *,int *,int *);

void pmpi_comm_set_errhandler_(int * comm,int * errhandler,int * ret){

return  INTERFACE_F_LOCAL_MPI_Comm_set_errhandler(comm,errhandler, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Comm_set_errhandler)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Comm_set_errhandler)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_create_errhandler_(void * file_errhandler_fn,int * errhandler,int * ret);
#pragma weak mpi_file_create_errhandler_=pmpi_file_create_errhandler_
void  (*INTERFACE_F_LOCAL_MPI_File_create_errhandler)(void *,int *,int *);

void pmpi_file_create_errhandler_(void * file_errhandler_fn,int * errhandler,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_create_errhandler(file_errhandler_fn,errhandler, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_create_errhandler)(void *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_create_errhandler)(void *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_get_errhandler_(int * file,int * errhandler,int * ret);
#pragma weak mpi_file_get_errhandler_=pmpi_file_get_errhandler_
void  (*INTERFACE_F_LOCAL_MPI_File_get_errhandler)(int *,int *,int *);

void pmpi_file_get_errhandler_(int * file,int * errhandler,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_get_errhandler( file,errhandler, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_get_errhandler)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_get_errhandler)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_set_errhandler_(int * file,int * errhandler,int * ret);
#pragma weak mpi_file_set_errhandler_=pmpi_file_set_errhandler_
void  (*INTERFACE_F_LOCAL_MPI_File_set_errhandler)(int *,int *,int *);

void pmpi_file_set_errhandler_(int * file,int * errhandler,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_set_errhandler( file,errhandler, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_set_errhandler)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_set_errhandler)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_finalized_(int * flag,int * ret);
#pragma weak mpi_finalized_=pmpi_finalized_
void  (*INTERFACE_F_LOCAL_MPI_Finalized)(int *,int *);

void pmpi_finalized_(int * flag,int * ret){

return  INTERFACE_F_LOCAL_MPI_Finalized( flag, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Finalized)(int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Finalized)(int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_free_mem_(void * base,int * ret);
#pragma weak mpi_free_mem_=pmpi_free_mem_
void  (*INTERFACE_F_LOCAL_MPI_Free_mem)(void *,int *);

void pmpi_free_mem_(void * base,int * ret){

return  INTERFACE_F_LOCAL_MPI_Free_mem(base, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Free_mem)(void *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Free_mem)(void *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_get_address_(void * location,size_t * address,int * ret);
#pragma weak mpi_get_address_=pmpi_get_address_
void  (*INTERFACE_F_LOCAL_MPI_Get_address)(void *,size_t *,int *);

void pmpi_get_address_(void * location,size_t * address,int * ret){

return  INTERFACE_F_LOCAL_MPI_Get_address(location, address, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Get_address)(void *,size_t *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Get_address)(void *,size_t *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_info_create_(int * info,int * ret);
#pragma weak mpi_info_create_=pmpi_info_create_
void  (*INTERFACE_F_LOCAL_MPI_Info_create)(int *,int *);

void pmpi_info_create_(int * info,int * ret){

return  INTERFACE_F_LOCAL_MPI_Info_create(info, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Info_create)(int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Info_create)(int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_info_dup_(int * info,int * newinfo,int * ret);
#pragma weak mpi_info_dup_=pmpi_info_dup_
void  (*INTERFACE_F_LOCAL_MPI_Info_dup)(int *,int *,int *);

void pmpi_info_dup_(int * info,int * newinfo,int * ret){

return  INTERFACE_F_LOCAL_MPI_Info_dup(info,newinfo, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Info_dup)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Info_dup)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_info_free_(int * info,int * ret);
#pragma weak mpi_info_free_=pmpi_info_free_
void  (*INTERFACE_F_LOCAL_MPI_Info_free)(int *,int *);

void pmpi_info_free_(int * info,int * ret){

return  INTERFACE_F_LOCAL_MPI_Info_free(info, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Info_free)(int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Info_free)(int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_info_get_nkeys_(int * info,int * nkeys,int * ret);
#pragma weak mpi_info_get_nkeys_=pmpi_info_get_nkeys_
void  (*INTERFACE_F_LOCAL_MPI_Info_get_nkeys)(int *,int *,int *);

void pmpi_info_get_nkeys_(int * info,int * nkeys,int * ret){

return  INTERFACE_F_LOCAL_MPI_Info_get_nkeys(info, nkeys, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Info_get_nkeys)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Info_get_nkeys)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_request_get_status_(int * request,int * flag,int * status,int * ret);
#pragma weak mpi_request_get_status_=pmpi_request_get_status_
void  (*INTERFACE_F_LOCAL_MPI_Request_get_status)(int *,int *,int *,int *);

void pmpi_request_get_status_(int * request,int * flag,int * status,int * ret){

return  INTERFACE_F_LOCAL_MPI_Request_get_status(request, flag,status, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Request_get_status)(int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Request_get_status)(int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_type_create_hvector_(int * count,int * blocklength,size_t * stride,int * oldtype,int * newtype,int * ret);
#pragma weak mpi_type_create_hvector_=pmpi_type_create_hvector_
void  (*INTERFACE_F_LOCAL_MPI_Type_create_hvector)(int *,int *,size_t *,int *,int *,int *);

void pmpi_type_create_hvector_(int * count,int * blocklength,size_t * stride,int * oldtype,int * newtype,int * ret){

return  INTERFACE_F_LOCAL_MPI_Type_create_hvector( count, blocklength, stride,oldtype,newtype, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Type_create_hvector)(int *,int *,size_t *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Type_create_hvector)(int *,int *,size_t *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_type_create_resized_(int * oldtype,size_t * lb,size_t * extent,int * newtype,int * ret);
#pragma weak mpi_type_create_resized_=pmpi_type_create_resized_
void  (*INTERFACE_F_LOCAL_MPI_Type_create_resized)(int *,size_t *,size_t *,int *,int *);

void pmpi_type_create_resized_(int * oldtype,size_t * lb,size_t * extent,int * newtype,int * ret){

return  INTERFACE_F_LOCAL_MPI_Type_create_resized(oldtype, lb, extent,newtype, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Type_create_resized)(int *,size_t *,size_t *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Type_create_resized)(int *,size_t *,size_t *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_type_get_extent_(int * datatype,size_t * lb,size_t * extent,int * ret);
#pragma weak mpi_type_get_extent_=pmpi_type_get_extent_
void  (*INTERFACE_F_LOCAL_MPI_Type_get_extent)(int *,size_t *,size_t *,int *);

void pmpi_type_get_extent_(int * datatype,size_t * lb,size_t * extent,int * ret){

return  INTERFACE_F_LOCAL_MPI_Type_get_extent(datatype, lb, extent, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Type_get_extent)(int *,size_t *,size_t *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Type_get_extent)(int *,size_t *,size_t *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_type_get_true_extent_(int * datatype,size_t * true_lb,size_t * true_extent,int * ret);
#pragma weak mpi_type_get_true_extent_=pmpi_type_get_true_extent_
void  (*INTERFACE_F_LOCAL_MPI_Type_get_true_extent)(int *,size_t *,size_t *,int *);

void pmpi_type_get_true_extent_(int * datatype,size_t * true_lb,size_t * true_extent,int * ret){

return  INTERFACE_F_LOCAL_MPI_Type_get_true_extent(datatype, true_lb, true_extent, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Type_get_true_extent)(int *,size_t *,size_t *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Type_get_true_extent)(int *,size_t *,size_t *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_win_create_errhandler_(void * win_errhandler_fn,int * errhandler,int * ret);
#pragma weak mpi_win_create_errhandler_=pmpi_win_create_errhandler_
void  (*INTERFACE_F_LOCAL_MPI_Win_create_errhandler)(void *,int *,int *);

void pmpi_win_create_errhandler_(void * win_errhandler_fn,int * errhandler,int * ret){

return  INTERFACE_F_LOCAL_MPI_Win_create_errhandler(win_errhandler_fn,errhandler, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Win_create_errhandler)(void *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Win_create_errhandler)(void *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_win_get_errhandler_(int * win,int * errhandler,int * ret);
#pragma weak mpi_win_get_errhandler_=pmpi_win_get_errhandler_
void  (*INTERFACE_F_LOCAL_MPI_Win_get_errhandler)(int *,int *,int *);

void pmpi_win_get_errhandler_(int * win,int * errhandler,int * ret){

return  INTERFACE_F_LOCAL_MPI_Win_get_errhandler(win,errhandler, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Win_get_errhandler)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Win_get_errhandler)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_win_set_errhandler_(int * win,int * errhandler,int * ret);
#pragma weak mpi_win_set_errhandler_=pmpi_win_set_errhandler_
void  (*INTERFACE_F_LOCAL_MPI_Win_set_errhandler)(int *,int *,int *);

void pmpi_win_set_errhandler_(int * win,int * errhandler,int * ret){

return  INTERFACE_F_LOCAL_MPI_Win_set_errhandler(win,errhandler, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Win_set_errhandler)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Win_set_errhandler)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_type_create_f90_integer_(int * range,int * newtype,int * ret);
#pragma weak mpi_type_create_f90_integer_=pmpi_type_create_f90_integer_
void  (*INTERFACE_F_LOCAL_MPI_Type_create_f90_integer)(int *,int *,int *);

void pmpi_type_create_f90_integer_(int * range,int * newtype,int * ret){

return  INTERFACE_F_LOCAL_MPI_Type_create_f90_integer( range,newtype, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Type_create_f90_integer)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Type_create_f90_integer)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_type_create_f90_real_(int * precision,int * range,int * newtype,int * ret);
#pragma weak mpi_type_create_f90_real_=pmpi_type_create_f90_real_
void  (*INTERFACE_F_LOCAL_MPI_Type_create_f90_real)(int *,int *,int *,int *);

void pmpi_type_create_f90_real_(int * precision,int * range,int * newtype,int * ret){

return  INTERFACE_F_LOCAL_MPI_Type_create_f90_real( precision, range,newtype, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Type_create_f90_real)(int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Type_create_f90_real)(int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_type_create_f90_complex_(int * precision,int * range,int * newtype,int * ret);
#pragma weak mpi_type_create_f90_complex_=pmpi_type_create_f90_complex_
void  (*INTERFACE_F_LOCAL_MPI_Type_create_f90_complex)(int *,int *,int *,int *);

void pmpi_type_create_f90_complex_(int * precision,int * range,int * newtype,int * ret){

return  INTERFACE_F_LOCAL_MPI_Type_create_f90_complex( precision, range,newtype, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Type_create_f90_complex)(int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Type_create_f90_complex)(int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_reduce_local_(void * inbuf,void * inoutbuf,int * count,int * datatype,int * op,int * ret);
#pragma weak mpi_reduce_local_=pmpi_reduce_local_
void  (*INTERFACE_F_LOCAL_MPI_Reduce_local)(void *,void *,int *,int *,int *,int *);

void pmpi_reduce_local_(void * inbuf,void * inoutbuf,int * count,int * datatype,int * op,int * ret){

return  INTERFACE_F_LOCAL_MPI_Reduce_local(inbuf,inoutbuf, count,datatype,op, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Reduce_local)(void *,void *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Reduce_local)(void *,void *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_op_commutative_(int * op,int * commute,int * ret);
#pragma weak mpi_op_commutative_=pmpi_op_commutative_
void  (*INTERFACE_F_LOCAL_MPI_Op_commutative)(int *,int *,int *);

void pmpi_op_commutative_(int * op,int * commute,int * ret){

return  INTERFACE_F_LOCAL_MPI_Op_commutative(op, commute, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Op_commutative)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Op_commutative)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_reduce_scatter_block_(void * sendbuf,void * recvbuf,int * recvcount,int * datatype,int * op,int * comm,int * ret);
#pragma weak mpi_reduce_scatter_block_=pmpi_reduce_scatter_block_
void  (*INTERFACE_F_LOCAL_MPI_Reduce_scatter_block)(void *,void *,int *,int *,int *,int *,int *);

void pmpi_reduce_scatter_block_(void * sendbuf,void * recvbuf,int * recvcount,int * datatype,int * op,int * comm,int * ret){

return  INTERFACE_F_LOCAL_MPI_Reduce_scatter_block(sendbuf,recvbuf, recvcount,datatype,op,comm, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Reduce_scatter_block)(void *,void *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Reduce_scatter_block)(void *,void *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_dist_graph_neighbors_count_(int * comm,int * indegree,int * outdegree,int * weighted,int * ret);
#pragma weak mpi_dist_graph_neighbors_count_=pmpi_dist_graph_neighbors_count_
void  (*INTERFACE_F_LOCAL_MPI_Dist_graph_neighbors_count)(int *,int *,int *,int *,int *);

void pmpi_dist_graph_neighbors_count_(int * comm,int * indegree,int * outdegree,int * weighted,int * ret){

return  INTERFACE_F_LOCAL_MPI_Dist_graph_neighbors_count(comm, indegree, outdegree, weighted, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Dist_graph_neighbors_count)(int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Dist_graph_neighbors_count)(int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_improbe_(int * source,int * tag,int * comm,int * flag,int * message,int * status,int * ret);
#pragma weak mpi_improbe_=pmpi_improbe_
void  (*INTERFACE_F_LOCAL_MPI_Improbe)(int *,int *,int *,int *,int *,int *,int *);

void pmpi_improbe_(int * source,int * tag,int * comm,int * flag,int * message,int * status,int * ret){

return  INTERFACE_F_LOCAL_MPI_Improbe(source,tag,comm, flag,message,status, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Improbe)(int *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Improbe)(int *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_imrecv_(void * buf,int * count,int * datatype,int * message,int * request,int * ret);
#pragma weak mpi_imrecv_=pmpi_imrecv_
void  (*INTERFACE_F_LOCAL_MPI_Imrecv)(void *,int *,int *,int *,int *,int *);

void pmpi_imrecv_(void * buf,int * count,int * datatype,int * message,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Imrecv(buf, count,datatype,message,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Imrecv)(void *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Imrecv)(void *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_mprobe_(int * source,int * tag,int * comm,int * message,int * status,int * ret);
#pragma weak mpi_mprobe_=pmpi_mprobe_
void  (*INTERFACE_F_LOCAL_MPI_Mprobe)(int *,int *,int *,int *,int *,int *);

void pmpi_mprobe_(int * source,int * tag,int * comm,int * message,int * status,int * ret){

return  INTERFACE_F_LOCAL_MPI_Mprobe(source,tag,comm,message,status, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Mprobe)(int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Mprobe)(int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_mrecv_(void * buf,int * count,int * datatype,int * message,int * status,int * ret);
#pragma weak mpi_mrecv_=pmpi_mrecv_
void  (*INTERFACE_F_LOCAL_MPI_Mrecv)(void *,int *,int *,int *,int *,int *);

void pmpi_mrecv_(void * buf,int * count,int * datatype,int * message,int * status,int * ret){

return  INTERFACE_F_LOCAL_MPI_Mrecv(buf, count,datatype,message,status, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Mrecv)(void *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Mrecv)(void *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_comm_idup_(int * comm,int * newcomm,int * request,int * ret);
#pragma weak mpi_comm_idup_=pmpi_comm_idup_
void  (*INTERFACE_F_LOCAL_MPI_Comm_idup)(int *,int *,int *,int *);

void pmpi_comm_idup_(int * comm,int * newcomm,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Comm_idup(comm,newcomm,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Comm_idup)(int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Comm_idup)(int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_ibarrier_(int * comm,int * request,int * ret);
#pragma weak mpi_ibarrier_=pmpi_ibarrier_
void  (*INTERFACE_F_LOCAL_MPI_Ibarrier)(int *,int *,int *);

void pmpi_ibarrier_(int * comm,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Ibarrier(comm,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Ibarrier)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Ibarrier)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_ibcast_(void * buffer,int * count,int * datatype,int * root,int * comm,int * request,int * ret);
#pragma weak mpi_ibcast_=pmpi_ibcast_
void  (*INTERFACE_F_LOCAL_MPI_Ibcast)(void *,int *,int *,int *,int *,int *,int *);

void pmpi_ibcast_(void * buffer,int * count,int * datatype,int * root,int * comm,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Ibcast(buffer, count,datatype, root,comm,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Ibcast)(void *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Ibcast)(void *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_igather_(void * sendbuf,int * sendcount,int * sendtype,void * recvbuf,int * recvcount,int * recvtype,int * root,int * comm,int * request,int * ret);
#pragma weak mpi_igather_=pmpi_igather_
void  (*INTERFACE_F_LOCAL_MPI_Igather)(void *,int *,int *,void *,int *,int *,int *,int *,int *,int *);

void pmpi_igather_(void * sendbuf,int * sendcount,int * sendtype,void * recvbuf,int * recvcount,int * recvtype,int * root,int * comm,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Igather(sendbuf, sendcount,sendtype,recvbuf, recvcount,recvtype, root,comm,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Igather)(void *,int *,int *,void *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Igather)(void *,int *,int *,void *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_iscatter_(void * sendbuf,int * sendcount,int * sendtype,void * recvbuf,int * recvcount,int * recvtype,int * root,int * comm,int * request,int * ret);
#pragma weak mpi_iscatter_=pmpi_iscatter_
void  (*INTERFACE_F_LOCAL_MPI_Iscatter)(void *,int *,int *,void *,int *,int *,int *,int *,int *,int *);

void pmpi_iscatter_(void * sendbuf,int * sendcount,int * sendtype,void * recvbuf,int * recvcount,int * recvtype,int * root,int * comm,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Iscatter(sendbuf, sendcount,sendtype,recvbuf, recvcount,recvtype, root,comm,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Iscatter)(void *,int *,int *,void *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Iscatter)(void *,int *,int *,void *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_iallgather_(void * sendbuf,int * sendcount,int * sendtype,void * recvbuf,int * recvcount,int * recvtype,int * comm,int * request,int * ret);
#pragma weak mpi_iallgather_=pmpi_iallgather_
void  (*INTERFACE_F_LOCAL_MPI_Iallgather)(void *,int *,int *,void *,int *,int *,int *,int *,int *);

void pmpi_iallgather_(void * sendbuf,int * sendcount,int * sendtype,void * recvbuf,int * recvcount,int * recvtype,int * comm,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Iallgather(sendbuf, sendcount,sendtype,recvbuf, recvcount,recvtype,comm,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Iallgather)(void *,int *,int *,void *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Iallgather)(void *,int *,int *,void *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_ialltoall_(void * sendbuf,int * sendcount,int * sendtype,void * recvbuf,int * recvcount,int * recvtype,int * comm,int * request,int * ret);
#pragma weak mpi_ialltoall_=pmpi_ialltoall_
void  (*INTERFACE_F_LOCAL_MPI_Ialltoall)(void *,int *,int *,void *,int *,int *,int *,int *,int *);

void pmpi_ialltoall_(void * sendbuf,int * sendcount,int * sendtype,void * recvbuf,int * recvcount,int * recvtype,int * comm,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Ialltoall(sendbuf, sendcount,sendtype,recvbuf, recvcount,recvtype,comm,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Ialltoall)(void *,int *,int *,void *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Ialltoall)(void *,int *,int *,void *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_ireduce_(void * sendbuf,void * recvbuf,int * count,int * datatype,int * op,int * root,int * comm,int * request,int * ret);
#pragma weak mpi_ireduce_=pmpi_ireduce_
void  (*INTERFACE_F_LOCAL_MPI_Ireduce)(void *,void *,int *,int *,int *,int *,int *,int *,int *);

void pmpi_ireduce_(void * sendbuf,void * recvbuf,int * count,int * datatype,int * op,int * root,int * comm,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Ireduce(sendbuf,recvbuf, count,datatype,op, root,comm,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Ireduce)(void *,void *,int *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Ireduce)(void *,void *,int *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_iallreduce_(void * sendbuf,void * recvbuf,int * count,int * datatype,int * op,int * comm,int * request,int * ret);
#pragma weak mpi_iallreduce_=pmpi_iallreduce_
void  (*INTERFACE_F_LOCAL_MPI_Iallreduce)(void *,void *,int *,int *,int *,int *,int *,int *);

void pmpi_iallreduce_(void * sendbuf,void * recvbuf,int * count,int * datatype,int * op,int * comm,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Iallreduce(sendbuf,recvbuf, count,datatype,op,comm,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Iallreduce)(void *,void *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Iallreduce)(void *,void *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_ireduce_scatter_block_(void * sendbuf,void * recvbuf,int * recvcount,int * datatype,int * op,int * comm,int * request,int * ret);
#pragma weak mpi_ireduce_scatter_block_=pmpi_ireduce_scatter_block_
void  (*INTERFACE_F_LOCAL_MPI_Ireduce_scatter_block)(void *,void *,int *,int *,int *,int *,int *,int *);

void pmpi_ireduce_scatter_block_(void * sendbuf,void * recvbuf,int * recvcount,int * datatype,int * op,int * comm,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Ireduce_scatter_block(sendbuf,recvbuf,recvcount,datatype,op,comm,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Ireduce_scatter_block)(void *,void *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Ireduce_scatter_block)(void *,void *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_iscan_(void * sendbuf,void * recvbuf,int * count,int * datatype,int * op,int * comm,int * request,int * ret);
#pragma weak mpi_iscan_=pmpi_iscan_
void  (*INTERFACE_F_LOCAL_MPI_Iscan)(void *,void *,int *,int *,int *,int *,int *,int *);

void pmpi_iscan_(void * sendbuf,void * recvbuf,int * count,int * datatype,int * op,int * comm,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Iscan(sendbuf,recvbuf, count,datatype,op,comm,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Iscan)(void *,void *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Iscan)(void *,void *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_iexscan_(void * sendbuf,void * recvbuf,int * count,int * datatype,int * op,int * comm,int * request,int * ret);
#pragma weak mpi_iexscan_=pmpi_iexscan_
void  (*INTERFACE_F_LOCAL_MPI_Iexscan)(void *,void *,int *,int *,int *,int *,int *,int *);

void pmpi_iexscan_(void * sendbuf,void * recvbuf,int * count,int * datatype,int * op,int * comm,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Iexscan(sendbuf,recvbuf, count,datatype,op,comm,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Iexscan)(void *,void *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Iexscan)(void *,void *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_ineighbor_allgather_(void * sendbuf,int * sendcount,int * sendtype,void * recvbuf,int * recvcount,int * recvtype,int * comm,int * request,int * ret);
#pragma weak mpi_ineighbor_allgather_=pmpi_ineighbor_allgather_
void  (*INTERFACE_F_LOCAL_MPI_Ineighbor_allgather)(void *,int *,int *,void *,int *,int *,int *,int *,int *);

void pmpi_ineighbor_allgather_(void * sendbuf,int * sendcount,int * sendtype,void * recvbuf,int * recvcount,int * recvtype,int * comm,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Ineighbor_allgather(sendbuf, sendcount,sendtype,recvbuf, recvcount,recvtype,comm,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Ineighbor_allgather)(void *,int *,int *,void *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Ineighbor_allgather)(void *,int *,int *,void *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_ineighbor_alltoall_(void * sendbuf,int * sendcount,int * sendtype,void * recvbuf,int * recvcount,int * recvtype,int * comm,int * request,int * ret);
#pragma weak mpi_ineighbor_alltoall_=pmpi_ineighbor_alltoall_
void  (*INTERFACE_F_LOCAL_MPI_Ineighbor_alltoall)(void *,int *,int *,void *,int *,int *,int *,int *,int *);

void pmpi_ineighbor_alltoall_(void * sendbuf,int * sendcount,int * sendtype,void * recvbuf,int * recvcount,int * recvtype,int * comm,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Ineighbor_alltoall(sendbuf, sendcount,sendtype,recvbuf, recvcount,recvtype,comm,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Ineighbor_alltoall)(void *,int *,int *,void *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Ineighbor_alltoall)(void *,int *,int *,void *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_neighbor_allgather_(void * sendbuf,int * sendcount,int * sendtype,void * recvbuf,int * recvcount,int * recvtype,int * comm,int * ret);
#pragma weak mpi_neighbor_allgather_=pmpi_neighbor_allgather_
void  (*INTERFACE_F_LOCAL_MPI_Neighbor_allgather)(void *,int *,int *,void *,int *,int *,int *,int *);

void pmpi_neighbor_allgather_(void * sendbuf,int * sendcount,int * sendtype,void * recvbuf,int * recvcount,int * recvtype,int * comm,int * ret){

return  INTERFACE_F_LOCAL_MPI_Neighbor_allgather(sendbuf, sendcount,sendtype,recvbuf, recvcount,recvtype,comm, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Neighbor_allgather)(void *,int *,int *,void *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Neighbor_allgather)(void *,int *,int *,void *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_neighbor_alltoall_(void * sendbuf,int * sendcount,int * sendtype,void * recvbuf,int * recvcount,int * recvtype,int * comm,int * ret);
#pragma weak mpi_neighbor_alltoall_=pmpi_neighbor_alltoall_
void  (*INTERFACE_F_LOCAL_MPI_Neighbor_alltoall)(void *,int *,int *,void *,int *,int *,int *,int *);

void pmpi_neighbor_alltoall_(void * sendbuf,int * sendcount,int * sendtype,void * recvbuf,int * recvcount,int * recvtype,int * comm,int * ret){

return  INTERFACE_F_LOCAL_MPI_Neighbor_alltoall(sendbuf, sendcount,sendtype,recvbuf, recvcount,recvtype,comm, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Neighbor_alltoall)(void *,int *,int *,void *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Neighbor_alltoall)(void *,int *,int *,void *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_comm_split_type_(int * comm,int * split_type,int * key,int * info,int * newcomm,int * ret);
#pragma weak mpi_comm_split_type_=pmpi_comm_split_type_
void  (*INTERFACE_F_LOCAL_MPI_Comm_split_type)(int *,int *,int *,int *,int *,int *);

void pmpi_comm_split_type_(int * comm,int * split_type,int * key,int * info,int * newcomm,int * ret){

return  INTERFACE_F_LOCAL_MPI_Comm_split_type(comm, split_type, key,info,newcomm, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Comm_split_type)(int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Comm_split_type)(int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_get_elements_x_(int * status,int * datatype,int * count,int * ret);
#pragma weak mpi_get_elements_x_=pmpi_get_elements_x_
void  (*INTERFACE_F_LOCAL_MPI_Get_elements_x)(int *,int *,int *,int *);

void pmpi_get_elements_x_(int * status,int * datatype,int * count,int * ret){

return  INTERFACE_F_LOCAL_MPI_Get_elements_x(status,datatype, count, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Get_elements_x)(int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Get_elements_x)(int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_status_set_elements_x_(int * status,int * datatype,int * count,int * ret);
#pragma weak mpi_status_set_elements_x_=pmpi_status_set_elements_x_
void  (*INTERFACE_F_LOCAL_MPI_Status_set_elements_x)(int *,int *,int *,int *);

void pmpi_status_set_elements_x_(int * status,int * datatype,int * count,int * ret){

return  INTERFACE_F_LOCAL_MPI_Status_set_elements_x(status,datatype, count, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Status_set_elements_x)(int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Status_set_elements_x)(int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_type_get_extent_x_(int * datatype,int * lb,int * extent,int * ret);
#pragma weak mpi_type_get_extent_x_=pmpi_type_get_extent_x_
void  (*INTERFACE_F_LOCAL_MPI_Type_get_extent_x)(int *,int *,int *,int *);

void pmpi_type_get_extent_x_(int * datatype,int * lb,int * extent,int * ret){

return  INTERFACE_F_LOCAL_MPI_Type_get_extent_x(datatype, lb, extent, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Type_get_extent_x)(int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Type_get_extent_x)(int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_type_get_true_extent_x_(int * datatype,int * lb,int * extent,int * ret);
#pragma weak mpi_type_get_true_extent_x_=pmpi_type_get_true_extent_x_
void  (*INTERFACE_F_LOCAL_MPI_Type_get_true_extent_x)(int *,int *,int *,int *);

void pmpi_type_get_true_extent_x_(int * datatype,int * lb,int * extent,int * ret){

return  INTERFACE_F_LOCAL_MPI_Type_get_true_extent_x(datatype, lb, extent, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Type_get_true_extent_x)(int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Type_get_true_extent_x)(int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_type_size_x_(int * datatype,int * size,int * ret);
#pragma weak mpi_type_size_x_=pmpi_type_size_x_
void  (*INTERFACE_F_LOCAL_MPI_Type_size_x)(int *,int *,int *);

void pmpi_type_size_x_(int * datatype,int * size,int * ret){

return  INTERFACE_F_LOCAL_MPI_Type_size_x(datatype, size, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Type_size_x)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Type_size_x)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_comm_create_group_(int * comm,int * group,int * tag,int * newcomm,int * ret);
#pragma weak mpi_comm_create_group_=pmpi_comm_create_group_
void  (*INTERFACE_F_LOCAL_MPI_Comm_create_group)(int *,int *,int *,int *,int *);

void pmpi_comm_create_group_(int * comm,int * group,int * tag,int * newcomm,int * ret){

return  INTERFACE_F_LOCAL_MPI_Comm_create_group(comm,group,tag,newcomm, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Comm_create_group)(int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Comm_create_group)(int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_close_(int * fh,int * ret);
#pragma weak mpi_file_close_=pmpi_file_close_
void  (*INTERFACE_F_LOCAL_MPI_File_close)(int *,int *);

void pmpi_file_close_(int * fh,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_close( fh, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_close)(int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_close)(int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_set_size_(int * fh,int* size,int * ret);
#pragma weak mpi_file_set_size_=pmpi_file_set_size_
void  (*INTERFACE_F_LOCAL_MPI_File_set_size)(int *,int*,int *);

void pmpi_file_set_size_(int * fh,int* size,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_set_size( fh, size, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_set_size)(int *,int*,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_set_size)(int *,int*,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_preallocate_(int * fh,int* size,int * ret);
#pragma weak mpi_file_preallocate_=pmpi_file_preallocate_
void  (*INTERFACE_F_LOCAL_MPI_File_preallocate)(int *,int*,int *);

void pmpi_file_preallocate_(int * fh,int* size,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_preallocate( fh, size, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_preallocate)(int *,int*,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_preallocate)(int *,int*,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_get_size_(int * fh,int* size,int * ret);
#pragma weak mpi_file_get_size_=pmpi_file_get_size_
void  (*INTERFACE_F_LOCAL_MPI_File_get_size)(int *,int*,int *);

void pmpi_file_get_size_(int * fh,int* size,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_get_size( fh, size, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_get_size)(int *,int*,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_get_size)(int *,int*,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_get_group_(int * fh,int * group,int * ret);
#pragma weak mpi_file_get_group_=pmpi_file_get_group_
void  (*INTERFACE_F_LOCAL_MPI_File_get_group)(int *,int *,int *);

void pmpi_file_get_group_(int * fh,int * group,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_get_group( fh,group, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_get_group)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_get_group)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_get_amode_(int * fh,int * amode,int * ret);
#pragma weak mpi_file_get_amode_=pmpi_file_get_amode_
void  (*INTERFACE_F_LOCAL_MPI_File_get_amode)(int *,int *,int *);

void pmpi_file_get_amode_(int * fh,int * amode,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_get_amode( fh, amode, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_get_amode)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_get_amode)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_set_info_(int * fh,int * info,int * ret);
#pragma weak mpi_file_set_info_=pmpi_file_set_info_
void  (*INTERFACE_F_LOCAL_MPI_File_set_info)(int *,int *,int *);

void pmpi_file_set_info_(int * fh,int * info,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_set_info( fh,info, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_set_info)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_set_info)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_get_info_(int * fh,int * info_used,int * ret);
#pragma weak mpi_file_get_info_=pmpi_file_get_info_
void  (*INTERFACE_F_LOCAL_MPI_File_get_info)(int *,int *,int *);

void pmpi_file_get_info_(int * fh,int * info_used,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_get_info( fh,info_used, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_get_info)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_get_info)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_read_at_(int * fh,int* offset,void * buf,int * count,int * datatype,int * status,int * ret);
#pragma weak mpi_file_read_at_=pmpi_file_read_at_
void  (*INTERFACE_F_LOCAL_MPI_File_read_at)(int *,int*,void *,int *,int *,int *,int *);

void pmpi_file_read_at_(int * fh,int* offset,void * buf,int * count,int * datatype,int * status,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_read_at( fh, offset,buf, count,datatype,status, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_read_at)(int *,int*,void *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_read_at)(int *,int*,void *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_read_at_all_(int * fh,int* offset,void *  buf,int * count,int * datatype,int * status,int * ret);
#pragma weak mpi_file_read_at_all_=pmpi_file_read_at_all_
void  (*INTERFACE_F_LOCAL_MPI_File_read_at_all)(int *,int*,void *,int *,int *,int *,int *);

void pmpi_file_read_at_all_(int * fh,int* offset,void *  buf,int * count,int * datatype,int * status,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_read_at_all( fh, offset, buf, count,datatype,status, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_read_at_all)(int *,int*,void *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_read_at_all)(int *,int*,void *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_write_at_(int * fh,int* offset,void *  buf,int * count,int * datatype,int * status,int * ret);
#pragma weak mpi_file_write_at_=pmpi_file_write_at_
void  (*INTERFACE_F_LOCAL_MPI_File_write_at)(int *,int*,void *,int *,int *,int *,int *);

void pmpi_file_write_at_(int * fh,int* offset,void *  buf,int * count,int * datatype,int * status,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_write_at( fh, offset, buf, count,datatype,status, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_write_at)(int *,int*,void *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_write_at)(int *,int*,void *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_write_at_all_(int * fh,int* offset,void * buf,int * count,int * datatype,int * status,int * ret);
#pragma weak mpi_file_write_at_all_=pmpi_file_write_at_all_
void  (*INTERFACE_F_LOCAL_MPI_File_write_at_all)(int *,int*,void *,int *,int *,int *,int *);

void pmpi_file_write_at_all_(int * fh,int* offset,void * buf,int * count,int * datatype,int * status,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_write_at_all( fh, offset,buf, count,datatype,status, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_write_at_all)(int *,int*,void *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_write_at_all)(int *,int*,void *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_iread_at_(int * fh,int* offset,void * buf,int * count,int * datatype,int * request,int * ret);
#pragma weak mpi_file_iread_at_=pmpi_file_iread_at_
void  (*INTERFACE_F_LOCAL_MPI_File_iread_at)(int *,int*,void *,int *,int *,int *,int *);

void pmpi_file_iread_at_(int * fh,int* offset,void * buf,int * count,int * datatype,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_iread_at( fh, offset,buf, count,datatype,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_iread_at)(int *,int*,void *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_iread_at)(int *,int*,void *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_iwrite_at_(int * fh,int* offset,void * buf,int * count,int * datatype,int * request,int * ret);
#pragma weak mpi_file_iwrite_at_=pmpi_file_iwrite_at_
void  (*INTERFACE_F_LOCAL_MPI_File_iwrite_at)(int *,int*,void *,int *,int *,int *,int *);

void pmpi_file_iwrite_at_(int * fh,int* offset,void * buf,int * count,int * datatype,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_iwrite_at( fh, offset,buf, count,datatype,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_iwrite_at)(int *,int*,void *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_iwrite_at)(int *,int*,void *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_read_(int * fh,void * buf,int * count,int * datatype,int * status,int * ret);
#pragma weak mpi_file_read_=pmpi_file_read_
void  (*INTERFACE_F_LOCAL_MPI_File_read)(int *,void *,int *,int *,int *,int *);

void pmpi_file_read_(int * fh,void * buf,int * count,int * datatype,int * status,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_read( fh,buf, count,datatype,status, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_read)(int *,void *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_read)(int *,void *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_read_all_(int * fh,void * buf,int * count,int * datatype,int * status,int * ret);
#pragma weak mpi_file_read_all_=pmpi_file_read_all_
void  (*INTERFACE_F_LOCAL_MPI_File_read_all)(int *,void *,int *,int *,int *,int *);

void pmpi_file_read_all_(int * fh,void * buf,int * count,int * datatype,int * status,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_read_all( fh,buf, count,datatype,status, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_read_all)(int *,void *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_read_all)(int *,void *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_write_(int * fh,void * buf,int * count,int * datatype,int * status,int * ret);
#pragma weak mpi_file_write_=pmpi_file_write_
void  (*INTERFACE_F_LOCAL_MPI_File_write)(int *,void *,int *,int *,int *,int *);

void pmpi_file_write_(int * fh,void * buf,int * count,int * datatype,int * status,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_write( fh,buf, count,datatype,status, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_write)(int *,void *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_write)(int *,void *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_write_all_(int * fh,void * buf,int * count,int * datatype,int * status,int * ret);
#pragma weak mpi_file_write_all_=pmpi_file_write_all_
void  (*INTERFACE_F_LOCAL_MPI_File_write_all)(int *,void *,int *,int *,int *,int *);

void pmpi_file_write_all_(int * fh,void * buf,int * count,int * datatype,int * status,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_write_all( fh,buf, count,datatype,status, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_write_all)(int *,void *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_write_all)(int *,void *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_iread_(int * fh,void * buf,int * count,int * datatype,int * request,int * ret);
#pragma weak mpi_file_iread_=pmpi_file_iread_
void  (*INTERFACE_F_LOCAL_MPI_File_iread)(int *,void *,int *,int *,int *,int *);

void pmpi_file_iread_(int * fh,void * buf,int * count,int * datatype,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_iread( fh,buf, count,datatype,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_iread)(int *,void *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_iread)(int *,void *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_iwrite_(int * fh,void * buf,int * count,int * datatype,int * request,int * ret);
#pragma weak mpi_file_iwrite_=pmpi_file_iwrite_
void  (*INTERFACE_F_LOCAL_MPI_File_iwrite)(int *,void *,int *,int *,int *,int *);

void pmpi_file_iwrite_(int * fh,void * buf,int * count,int * datatype,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_iwrite( fh,buf,count,datatype,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_iwrite)(int *,void *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_iwrite)(int *,void *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_seek_(int * fh,int* offset,int * whence,int * ret);
#pragma weak mpi_file_seek_=pmpi_file_seek_
void  (*INTERFACE_F_LOCAL_MPI_File_seek)(int *,int*,int *,int *);

void pmpi_file_seek_(int * fh,int* offset,int * whence,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_seek( fh, offset, whence, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_seek)(int *,int*,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_seek)(int *,int*,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_get_position_(int * fh,int* offset,int * ret);
#pragma weak mpi_file_get_position_=pmpi_file_get_position_
void  (*INTERFACE_F_LOCAL_MPI_File_get_position)(int *,int*,int *);

void pmpi_file_get_position_(int * fh,int* offset,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_get_position( fh, offset, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_get_position)(int *,int*,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_get_position)(int *,int*,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_get_byte_offset_(int * fh,int* offset,int* disp,int * ret);
#pragma weak mpi_file_get_byte_offset_=pmpi_file_get_byte_offset_
void  (*INTERFACE_F_LOCAL_MPI_File_get_byte_offset)(int *,int*,int*,int *);

void pmpi_file_get_byte_offset_(int * fh,int* offset,int* disp,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_get_byte_offset( fh, offset, disp, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_get_byte_offset)(int *,int*,int*,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_get_byte_offset)(int *,int*,int*,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_read_shared_(int * fh,void * buf,int * count,int * datatype,int * status,int * ret);
#pragma weak mpi_file_read_shared_=pmpi_file_read_shared_
void  (*INTERFACE_F_LOCAL_MPI_File_read_shared)(int *,void *,int *,int *,int *,int *);

void pmpi_file_read_shared_(int * fh,void * buf,int * count,int * datatype,int * status,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_read_shared( fh,buf, count,datatype,status, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_read_shared)(int *,void *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_read_shared)(int *,void *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_write_shared_(int * fh,void * buf,int * count,int * datatype,int * status,int * ret);
#pragma weak mpi_file_write_shared_=pmpi_file_write_shared_
void  (*INTERFACE_F_LOCAL_MPI_File_write_shared)(int *,void *,int *,int *,int *,int *);

void pmpi_file_write_shared_(int * fh,void * buf,int * count,int * datatype,int * status,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_write_shared( fh,buf, count,datatype,status, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_write_shared)(int *,void *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_write_shared)(int *,void *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_iread_shared_(int * fh,void * buf,int * count,int * datatype,int * request,int * ret);
#pragma weak mpi_file_iread_shared_=pmpi_file_iread_shared_
void  (*INTERFACE_F_LOCAL_MPI_File_iread_shared)(int *,void *,int *,int *,int *,int *);

void pmpi_file_iread_shared_(int * fh,void * buf,int * count,int * datatype,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_iread_shared( fh,buf, count,datatype,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_iread_shared)(int *,void *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_iread_shared)(int *,void *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_iwrite_shared_(int * fh,void * buf,int * count,int * datatype,int * request,int * ret);
#pragma weak mpi_file_iwrite_shared_=pmpi_file_iwrite_shared_
void  (*INTERFACE_F_LOCAL_MPI_File_iwrite_shared)(int *,void *,int *,int *,int *,int *);

void pmpi_file_iwrite_shared_(int * fh,void * buf,int * count,int * datatype,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_iwrite_shared( fh,buf, count,datatype,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_iwrite_shared)(int *,void *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_iwrite_shared)(int *,void *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_read_ordered_(int * fh,void * buf,int * count,int * datatype,int * status,int * ret);
#pragma weak mpi_file_read_ordered_=pmpi_file_read_ordered_
void  (*INTERFACE_F_LOCAL_MPI_File_read_ordered)(int *,void *,int *,int *,int *,int *);

void pmpi_file_read_ordered_(int * fh,void * buf,int * count,int * datatype,int * status,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_read_ordered( fh,buf, count,datatype,status, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_read_ordered)(int *,void *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_read_ordered)(int *,void *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_write_ordered_(int * fh,void * buf,int * count,int * datatype,int * status,int * ret);
#pragma weak mpi_file_write_ordered_=pmpi_file_write_ordered_
void  (*INTERFACE_F_LOCAL_MPI_File_write_ordered)(int *,void *,int *,int *,int *,int *);

void pmpi_file_write_ordered_(int * fh,void * buf,int * count,int * datatype,int * status,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_write_ordered( fh,buf, count,datatype,status, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_write_ordered)(int *,void *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_write_ordered)(int *,void *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_seek_shared_(int * fh,int* offset,int * whence,int * ret);
#pragma weak mpi_file_seek_shared_=pmpi_file_seek_shared_
void  (*INTERFACE_F_LOCAL_MPI_File_seek_shared)(int *,int*,int *,int *);

void pmpi_file_seek_shared_(int * fh,int* offset,int * whence,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_seek_shared( fh, offset, whence, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_seek_shared)(int *,int*,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_seek_shared)(int *,int*,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_get_position_shared_(int * fh,int* offset,int * ret);
#pragma weak mpi_file_get_position_shared_=pmpi_file_get_position_shared_
void  (*INTERFACE_F_LOCAL_MPI_File_get_position_shared)(int *,int*,int *);

void pmpi_file_get_position_shared_(int * fh,int* offset,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_get_position_shared( fh, offset, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_get_position_shared)(int *,int*,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_get_position_shared)(int *,int*,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_read_at_all_begin_(int * fh,int* offset,void * buf,int * count,int * datatype,int * ret);
#pragma weak mpi_file_read_at_all_begin_=pmpi_file_read_at_all_begin_
void  (*INTERFACE_F_LOCAL_MPI_File_read_at_all_begin)(int *,int*,void *,int *,int *,int *);

void pmpi_file_read_at_all_begin_(int * fh,int* offset,void * buf,int * count,int * datatype,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_read_at_all_begin( fh, offset,buf, count,datatype, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_read_at_all_begin)(int *,int*,void *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_read_at_all_begin)(int *,int*,void *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_read_at_all_end_(int * fh,void * buf,int * status,int * ret);
#pragma weak mpi_file_read_at_all_end_=pmpi_file_read_at_all_end_
void  (*INTERFACE_F_LOCAL_MPI_File_read_at_all_end)(int *,void *,int *,int *);

void pmpi_file_read_at_all_end_(int * fh,void * buf,int * status,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_read_at_all_end( fh,buf,status, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_read_at_all_end)(int *,void *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_read_at_all_end)(int *,void *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_write_at_all_begin_(int * fh,int* offset,void * buf,int * count,int * datatype,int * ret);
#pragma weak mpi_file_write_at_all_begin_=pmpi_file_write_at_all_begin_
void  (*INTERFACE_F_LOCAL_MPI_File_write_at_all_begin)(int *,int*,void *,int *,int *,int *);

void pmpi_file_write_at_all_begin_(int * fh,int* offset,void * buf,int * count,int * datatype,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_write_at_all_begin( fh, offset,buf, count,datatype, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_write_at_all_begin)(int *,int*,void *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_write_at_all_begin)(int *,int*,void *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_write_at_all_end_(int * fh,void * buf,int * status,int * ret);
#pragma weak mpi_file_write_at_all_end_=pmpi_file_write_at_all_end_
void  (*INTERFACE_F_LOCAL_MPI_File_write_at_all_end)(int *,void *,int *,int *);

void pmpi_file_write_at_all_end_(int * fh,void * buf,int * status,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_write_at_all_end( fh,buf,status, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_write_at_all_end)(int *,void *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_write_at_all_end)(int *,void *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_read_all_begin_(int * fh,void * buf,int * count,int * datatype,int * ret);
#pragma weak mpi_file_read_all_begin_=pmpi_file_read_all_begin_
void  (*INTERFACE_F_LOCAL_MPI_File_read_all_begin)(int *,void *,int *,int *,int *);

void pmpi_file_read_all_begin_(int * fh,void * buf,int * count,int * datatype,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_read_all_begin( fh,buf, count,datatype, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_read_all_begin)(int *,void *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_read_all_begin)(int *,void *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_read_all_end_(int * fh,void * buf,int * status,int * ret);
#pragma weak mpi_file_read_all_end_=pmpi_file_read_all_end_
void  (*INTERFACE_F_LOCAL_MPI_File_read_all_end)(int *,void *,int *,int *);

void pmpi_file_read_all_end_(int * fh,void * buf,int * status,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_read_all_end( fh,buf,status, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_read_all_end)(int *,void *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_read_all_end)(int *,void *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_write_all_begin_(int * fh,void * buf,int * count,int * datatype,int * ret);
#pragma weak mpi_file_write_all_begin_=pmpi_file_write_all_begin_
void  (*INTERFACE_F_LOCAL_MPI_File_write_all_begin)(int *,void *,int *,int *,int *);

void pmpi_file_write_all_begin_(int * fh,void * buf,int * count,int * datatype,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_write_all_begin( fh,buf,count,datatype, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_write_all_begin)(int *,void *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_write_all_begin)(int *,void *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_write_all_end_(int * fh,void * buf,int * status,int * ret);
#pragma weak mpi_file_write_all_end_=pmpi_file_write_all_end_
void  (*INTERFACE_F_LOCAL_MPI_File_write_all_end)(int *,void *,int *,int *);

void pmpi_file_write_all_end_(int * fh,void * buf,int * status,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_write_all_end( fh,buf,status, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_write_all_end)(int *,void *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_write_all_end)(int *,void *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_read_ordered_begin_(int * fh,void * buf,int * count,int * datatype,int * ret);
#pragma weak mpi_file_read_ordered_begin_=pmpi_file_read_ordered_begin_
void  (*INTERFACE_F_LOCAL_MPI_File_read_ordered_begin)(int *,void *,int *,int *,int *);

void pmpi_file_read_ordered_begin_(int * fh,void * buf,int * count,int * datatype,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_read_ordered_begin( fh,buf, count,datatype, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_read_ordered_begin)(int *,void *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_read_ordered_begin)(int *,void *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_read_ordered_end_(int * fh,void * buf,int * status,int * ret);
#pragma weak mpi_file_read_ordered_end_=pmpi_file_read_ordered_end_
void  (*INTERFACE_F_LOCAL_MPI_File_read_ordered_end)(int *,void *,int *,int *);

void pmpi_file_read_ordered_end_(int * fh,void * buf,int * status,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_read_ordered_end( fh,buf,status, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_read_ordered_end)(int *,void *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_read_ordered_end)(int *,void *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_write_ordered_begin_(int * fh,void * buf,int * count,int * datatype,int * ret);
#pragma weak mpi_file_write_ordered_begin_=pmpi_file_write_ordered_begin_
void  (*INTERFACE_F_LOCAL_MPI_File_write_ordered_begin)(int *,void *,int *,int *,int *);

void pmpi_file_write_ordered_begin_(int * fh,void * buf,int * count,int * datatype,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_write_ordered_begin( fh,buf, count,datatype, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_write_ordered_begin)(int *,void *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_write_ordered_begin)(int *,void *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_write_ordered_end_(int * fh,void * buf,int * status,int * ret);
#pragma weak mpi_file_write_ordered_end_=pmpi_file_write_ordered_end_
void  (*INTERFACE_F_LOCAL_MPI_File_write_ordered_end)(int *,void *,int *,int *);

void pmpi_file_write_ordered_end_(int * fh,void * buf,int * status,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_write_ordered_end( fh,buf,status, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_write_ordered_end)(int *,void *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_write_ordered_end)(int *,void *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_get_type_extent_(int * fh,int * datatype,size_t * extent,int * ret);
#pragma weak mpi_file_get_type_extent_=pmpi_file_get_type_extent_
void  (*INTERFACE_F_LOCAL_MPI_File_get_type_extent)(int *,int *,size_t *,int *);

void pmpi_file_get_type_extent_(int * fh,int * datatype,size_t * extent,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_get_type_extent( fh,datatype, extent, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_get_type_extent)(int *,int *,size_t *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_get_type_extent)(int *,int *,size_t *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_set_atomicity_(int * fh,int * flag,int * ret);
#pragma weak mpi_file_set_atomicity_=pmpi_file_set_atomicity_
void  (*INTERFACE_F_LOCAL_MPI_File_set_atomicity)(int *,int *,int *);

void pmpi_file_set_atomicity_(int * fh,int * flag,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_set_atomicity( fh, flag, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_set_atomicity)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_set_atomicity)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_get_atomicity_(int * fh,int * flag,int * ret);
#pragma weak mpi_file_get_atomicity_=pmpi_file_get_atomicity_
void  (*INTERFACE_F_LOCAL_MPI_File_get_atomicity)(int *,int *,int *);

void pmpi_file_get_atomicity_(int * fh,int * flag,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_get_atomicity( fh, flag, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_get_atomicity)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_get_atomicity)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_sync_(int * fh,int * ret);
#pragma weak mpi_file_sync_=pmpi_file_sync_
void  (*INTERFACE_F_LOCAL_MPI_File_sync)(int *,int *);

void pmpi_file_sync_(int * fh,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_sync( fh, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_sync)(int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_sync)(int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_wtime_(double * ret);
#pragma weak mpi_wtime_=pmpi_wtime_
void  (*INTERFACE_F_LOCAL_MPI_Wtime)(double *);

void pmpi_wtime_(double * ret){

return  INTERFACE_F_LOCAL_MPI_Wtime( ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Wtime)(double *);
extern  (*INTERF_2_INTEL_A_f_MPI_Wtime)(double *);
#endif /*WI4MPI_STATIC*/
void  mpi_wtick_(double * ret);
#pragma weak mpi_wtick_=pmpi_wtick_
void  (*INTERFACE_F_LOCAL_MPI_Wtick)(double *);

void pmpi_wtick_(double * ret){

return  INTERFACE_F_LOCAL_MPI_Wtick( ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Wtick)(double *);
extern  (*INTERF_2_INTEL_A_f_MPI_Wtick)(double *);
#endif /*WI4MPI_STATIC*/
void  mpi_finalize_(int * ret);
#pragma weak mpi_finalize_=pmpi_finalize_
void  (*INTERFACE_F_LOCAL_MPI_Finalize)(int *);

void pmpi_finalize_(int * ret){

return  INTERFACE_F_LOCAL_MPI_Finalize( ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Finalize)(int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Finalize)(int *);
#endif /*WI4MPI_STATIC*/
void  mpi_waitany_(int * count,int * array_of_requests,int * indx,int * status,int * ret);
#pragma weak mpi_waitany_=pmpi_waitany_
void  (*INTERFACE_F_LOCAL_MPI_Waitany)(int *,int *,int *,int *,int *);

void pmpi_waitany_(int * count,int * array_of_requests,int * indx,int * status,int * ret){

return  INTERFACE_F_LOCAL_MPI_Waitany( count,array_of_requests, indx,status, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Waitany)(int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Waitany)(int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_testany_(int * count,int * array_of_requests,int * indx,int * flag,int * status,int * ret);
#pragma weak mpi_testany_=pmpi_testany_
void  (*INTERFACE_F_LOCAL_MPI_Testany)(int *,int *,int *,int *,int *,int *);

void pmpi_testany_(int * count,int * array_of_requests,int * indx,int * flag,int * status,int * ret){

return  INTERFACE_F_LOCAL_MPI_Testany( count,array_of_requests, indx, flag,status, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Testany)(int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Testany)(int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_waitall_(int * count,int * array_of_requests,int * array_of_statuses,int * ret);
#pragma weak mpi_waitall_=pmpi_waitall_
void  (*INTERFACE_F_LOCAL_MPI_Waitall)(int *,int *,int *,int *);

void pmpi_waitall_(int * count,int * array_of_requests,int * array_of_statuses,int * ret){

return  INTERFACE_F_LOCAL_MPI_Waitall( count,array_of_requests,array_of_statuses, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Waitall)(int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Waitall)(int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_testall_(int * count,int * array_of_requests,int * flag,int * array_of_statuses,int * ret);
#pragma weak mpi_testall_=pmpi_testall_
void  (*INTERFACE_F_LOCAL_MPI_Testall)(int *,int *,int *,int *,int *);

void pmpi_testall_(int * count,int * array_of_requests,int * flag,int * array_of_statuses,int * ret){

return  INTERFACE_F_LOCAL_MPI_Testall( count,array_of_requests, flag,array_of_statuses, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Testall)(int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Testall)(int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_waitsome_(int * incount,int * array_of_requests,int * outcount,int * array_of_indices,int * array_of_statuses,int * ret);
#pragma weak mpi_waitsome_=pmpi_waitsome_
void  (*INTERFACE_F_LOCAL_MPI_Waitsome)(int *,int *,int *,int *,int *,int *);

void pmpi_waitsome_(int * incount,int * array_of_requests,int * outcount,int * array_of_indices,int * array_of_statuses,int * ret){

return  INTERFACE_F_LOCAL_MPI_Waitsome( incount,array_of_requests, outcount, array_of_indices,array_of_statuses, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Waitsome)(int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Waitsome)(int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_testsome_(int * incount,int * array_of_requests,int * outcount,int * array_of_indices,int * array_of_statuses,int * ret);
#pragma weak mpi_testsome_=pmpi_testsome_
void  (*INTERFACE_F_LOCAL_MPI_Testsome)(int *,int *,int *,int *,int *,int *);

void pmpi_testsome_(int * incount,int * array_of_requests,int * outcount,int * array_of_indices,int * array_of_statuses,int * ret){

return  INTERFACE_F_LOCAL_MPI_Testsome( incount,array_of_requests, outcount, array_of_indices,array_of_statuses, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Testsome)(int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Testsome)(int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_startall_(int * count,int * array_of_requests,int * ret);
#pragma weak mpi_startall_=pmpi_startall_
void  (*INTERFACE_F_LOCAL_MPI_Startall)(int *,int *,int *);

void pmpi_startall_(int * count,int * array_of_requests,int * ret){

return  INTERFACE_F_LOCAL_MPI_Startall( count,array_of_requests, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Startall)(int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Startall)(int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_alltoallw_(void * sendbuf,int * sendcounts,int * sdispls,int * sendtypes,void * recvbuf,int * recvcounts,int * rdispls,int * recvtypes,int * comm,int * ret);
#pragma weak mpi_alltoallw_=pmpi_alltoallw_
void  (*INTERFACE_F_LOCAL_MPI_Alltoallw)(void *,int *,int *,int *,void *,int *,int *,int *,int *,int *);

void pmpi_alltoallw_(void * sendbuf,int * sendcounts,int * sdispls,int * sendtypes,void * recvbuf,int * recvcounts,int * rdispls,int * recvtypes,int * comm,int * ret){

return  INTERFACE_F_LOCAL_MPI_Alltoallw(sendbuf, sendcounts, sdispls,sendtypes,recvbuf, recvcounts, rdispls,recvtypes,comm, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Alltoallw)(void *,int *,int *,int *,void *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Alltoallw)(void *,int *,int *,int *,void *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_reduce_scatter_(void * sendbuf,void * recvbuf,int * recvcounts,int * datatype,int * op,int * comm,int * ret);
#pragma weak mpi_reduce_scatter_=pmpi_reduce_scatter_
void  (*INTERFACE_F_LOCAL_MPI_Reduce_scatter)(void *,void *,int *,int *,int *,int *,int *);

void pmpi_reduce_scatter_(void * sendbuf,void * recvbuf,int * recvcounts,int * datatype,int * op,int * comm,int * ret){

return  INTERFACE_F_LOCAL_MPI_Reduce_scatter(sendbuf,recvbuf, recvcounts,datatype,op,comm, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Reduce_scatter)(void *,void *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Reduce_scatter)(void *,void *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_group_translate_ranks_(int * group1,int * n,int * ranks1,int * group2,int * ranks2,int * ret);
#pragma weak mpi_group_translate_ranks_=pmpi_group_translate_ranks_
void  (*INTERFACE_F_LOCAL_MPI_Group_translate_ranks)(int *,int *,int *,int *,int *,int *);

void pmpi_group_translate_ranks_(int * group1,int * n,int * ranks1,int * group2,int * ranks2,int * ret){

return  INTERFACE_F_LOCAL_MPI_Group_translate_ranks(group1, n, ranks1,group2, ranks2, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Group_translate_ranks)(int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Group_translate_ranks)(int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_group_incl_(int * group,int * n,int * ranks,int * newgroup,int * ret);
#pragma weak mpi_group_incl_=pmpi_group_incl_
void  (*INTERFACE_F_LOCAL_MPI_Group_incl)(int *,int *,int *,int *,int *);

void pmpi_group_incl_(int * group,int * n,int * ranks,int * newgroup,int * ret){

return  INTERFACE_F_LOCAL_MPI_Group_incl(group, n, ranks,newgroup, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Group_incl)(int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Group_incl)(int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_group_excl_(int * group,int * n,int * ranks,int * newgroup,int * ret);
#pragma weak mpi_group_excl_=pmpi_group_excl_
void  (*INTERFACE_F_LOCAL_MPI_Group_excl)(int *,int *,int *,int *,int *);

void pmpi_group_excl_(int * group,int * n,int * ranks,int * newgroup,int * ret){

return  INTERFACE_F_LOCAL_MPI_Group_excl(group, n, ranks,newgroup, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Group_excl)(int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Group_excl)(int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_group_range_incl_(int * group,int * n,int * ranges,int * newgroup,int * ret);
#pragma weak mpi_group_range_incl_=pmpi_group_range_incl_
void  (*INTERFACE_F_LOCAL_MPI_Group_range_incl)(int *,int *,int *,int *,int *);

void pmpi_group_range_incl_(int * group,int * n,int * ranges,int * newgroup,int * ret){

return  INTERFACE_F_LOCAL_MPI_Group_range_incl(group, n, ranges,newgroup, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Group_range_incl)(int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Group_range_incl)(int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_group_range_excl_(int * group,int * n,int * ranges,int * newgroup,int * ret);
#pragma weak mpi_group_range_excl_=pmpi_group_range_excl_
void  (*INTERFACE_F_LOCAL_MPI_Group_range_excl)(int *,int *,int *,int *,int *);

void pmpi_group_range_excl_(int * group,int * n,int * ranges,int * newgroup,int * ret){

return  INTERFACE_F_LOCAL_MPI_Group_range_excl(group, n, ranges,newgroup, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Group_range_excl)(int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Group_range_excl)(int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_cart_create_(int * comm_old,int * ndims,int * dims,int * periods,int * reorder,int * comm_cart,int * ret);
#pragma weak mpi_cart_create_=pmpi_cart_create_
void  (*INTERFACE_F_LOCAL_MPI_Cart_create)(int *,int *,int *,int *,int *,int *,int *);

void pmpi_cart_create_(int * comm_old,int * ndims,int * dims,int * periods,int * reorder,int * comm_cart,int * ret){

return  INTERFACE_F_LOCAL_MPI_Cart_create(comm_old, ndims, dims, periods, reorder,comm_cart, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Cart_create)(int *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Cart_create)(int *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_dims_create_(int * nnodes,int * ndims,int * dims,int * ret);
#pragma weak mpi_dims_create_=pmpi_dims_create_
void  (*INTERFACE_F_LOCAL_MPI_Dims_create)(int *,int *,int *,int *);

void pmpi_dims_create_(int * nnodes,int * ndims,int * dims,int * ret){

return  INTERFACE_F_LOCAL_MPI_Dims_create( nnodes, ndims, dims, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Dims_create)(int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Dims_create)(int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_graph_create_(int * comm_old,int * nnodes,int * indx,int * edges,int * reorder,int * comm_graph,int * ret);
#pragma weak mpi_graph_create_=pmpi_graph_create_
void  (*INTERFACE_F_LOCAL_MPI_Graph_create)(int *,int *,int *,int *,int *,int *,int *);

void pmpi_graph_create_(int * comm_old,int * nnodes,int * indx,int * edges,int * reorder,int * comm_graph,int * ret){

return  INTERFACE_F_LOCAL_MPI_Graph_create(comm_old, nnodes, indx, edges, reorder,comm_graph, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Graph_create)(int *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Graph_create)(int *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_graph_get_(int * comm,int * maxindex,int * maxedges,int * indx,int * edges,int * ret);
#pragma weak mpi_graph_get_=pmpi_graph_get_
void  (*INTERFACE_F_LOCAL_MPI_Graph_get)(int *,int *,int *,int *,int *,int *);

void pmpi_graph_get_(int * comm,int * maxindex,int * maxedges,int * indx,int * edges,int * ret){

return  INTERFACE_F_LOCAL_MPI_Graph_get(comm, maxindex, maxedges, indx, edges, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Graph_get)(int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Graph_get)(int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_cart_get_(int * comm,int * maxdims,int * dims,int * periods,int * coords,int * ret);
#pragma weak mpi_cart_get_=pmpi_cart_get_
void  (*INTERFACE_F_LOCAL_MPI_Cart_get)(int *,int *,int *,int *,int *,int *);

void pmpi_cart_get_(int * comm,int * maxdims,int * dims,int * periods,int * coords,int * ret){

return  INTERFACE_F_LOCAL_MPI_Cart_get(comm, maxdims, dims, periods, coords, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Cart_get)(int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Cart_get)(int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_cart_rank_(int * comm,int * coords,int * rank,int * ret);
#pragma weak mpi_cart_rank_=pmpi_cart_rank_
void  (*INTERFACE_F_LOCAL_MPI_Cart_rank)(int *,int *,int *,int *);

void pmpi_cart_rank_(int * comm,int * coords,int * rank,int * ret){

return  INTERFACE_F_LOCAL_MPI_Cart_rank(comm, coords, rank, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Cart_rank)(int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Cart_rank)(int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_cart_coords_(int * comm,int * rank,int * maxdims,int * coords,int * ret);
#pragma weak mpi_cart_coords_=pmpi_cart_coords_
void  (*INTERFACE_F_LOCAL_MPI_Cart_coords)(int *,int *,int *,int *,int *);

void pmpi_cart_coords_(int * comm,int * rank,int * maxdims,int * coords,int * ret){

return  INTERFACE_F_LOCAL_MPI_Cart_coords(comm, rank, maxdims, coords, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Cart_coords)(int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Cart_coords)(int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_graph_neighbors_(int * comm,int * rank,int * maxneighbors,int * neighbors,int * ret);
#pragma weak mpi_graph_neighbors_=pmpi_graph_neighbors_
void  (*INTERFACE_F_LOCAL_MPI_Graph_neighbors)(int *,int *,int *,int *,int *);

void pmpi_graph_neighbors_(int * comm,int * rank,int * maxneighbors,int * neighbors,int * ret){

return  INTERFACE_F_LOCAL_MPI_Graph_neighbors(comm, rank, maxneighbors, neighbors, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Graph_neighbors)(int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Graph_neighbors)(int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_cart_sub_(int * comm,int * remain_dims,int * newcomm,int * ret);
#pragma weak mpi_cart_sub_=pmpi_cart_sub_
void  (*INTERFACE_F_LOCAL_MPI_Cart_sub)(int *,int *,int *,int *);

void pmpi_cart_sub_(int * comm,int * remain_dims,int * newcomm,int * ret){

return  INTERFACE_F_LOCAL_MPI_Cart_sub(comm, remain_dims,newcomm, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Cart_sub)(int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Cart_sub)(int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_cart_map_(int * comm,int * ndims,int * dims,int * periods,int * newrank,int * ret);
#pragma weak mpi_cart_map_=pmpi_cart_map_
void  (*INTERFACE_F_LOCAL_MPI_Cart_map)(int *,int *,int *,int *,int *,int *);

void pmpi_cart_map_(int * comm,int * ndims,int * dims,int * periods,int * newrank,int * ret){

return  INTERFACE_F_LOCAL_MPI_Cart_map(comm, ndims, dims, periods, newrank, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Cart_map)(int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Cart_map)(int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_graph_map_(int * comm,int * nnodes,int * indx,int * edges,int * newrank,int * ret);
#pragma weak mpi_graph_map_=pmpi_graph_map_
void  (*INTERFACE_F_LOCAL_MPI_Graph_map)(int *,int *,int *,int *,int *,int *);

void pmpi_graph_map_(int * comm,int * nnodes,int * indx,int * edges,int * newrank,int * ret){

return  INTERFACE_F_LOCAL_MPI_Graph_map(comm, nnodes, indx, edges, newrank, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Graph_map)(int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Graph_map)(int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_type_get_contents_(int * datatype,int * max_integers,int * max_addresses,int * max_datatypes,int * array_of_integers,size_t * array_of_addresses,int * array_of_datatypes,int * ret);
#pragma weak mpi_type_get_contents_=pmpi_type_get_contents_
void  (*INTERFACE_F_LOCAL_MPI_Type_get_contents)(int *,int *,int *,int *,int *,size_t *,int *,int *);

void pmpi_type_get_contents_(int * datatype,int * max_integers,int * max_addresses,int * max_datatypes,int * array_of_integers,size_t * array_of_addresses,int * array_of_datatypes,int * ret){

return  INTERFACE_F_LOCAL_MPI_Type_get_contents(datatype, max_integers, max_addresses, max_datatypes, array_of_integers, array_of_addresses,array_of_datatypes, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Type_get_contents)(int *,int *,int *,int *,int *,size_t *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Type_get_contents)(int *,int *,int *,int *,int *,size_t *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_type_create_darray_(int * size,int * rank,int * ndims,int * array_of_gsizes,int * array_of_distribs,int * array_of_dargs,int * array_of_psizes,int * order,int * oldtype,int * newtype,int * ret);
#pragma weak mpi_type_create_darray_=pmpi_type_create_darray_
void  (*INTERFACE_F_LOCAL_MPI_Type_create_darray)(int *,int *,int *,int *,int *,int *,int *,int *,int *,int *,int *);

void pmpi_type_create_darray_(int * size,int * rank,int * ndims,int * array_of_gsizes,int * array_of_distribs,int * array_of_dargs,int * array_of_psizes,int * order,int * oldtype,int * newtype,int * ret){

return  INTERFACE_F_LOCAL_MPI_Type_create_darray( size, rank, ndims, array_of_gsizes, array_of_distribs, array_of_dargs, array_of_psizes,order,oldtype,newtype, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Type_create_darray)(int *,int *,int *,int *,int *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Type_create_darray)(int *,int *,int *,int *,int *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_type_create_hindexed_(int * count,int * array_of_blocklengths,size_t * array_of_displacements,int * oldtype,int * newtype,int * ret);
#pragma weak mpi_type_create_hindexed_=pmpi_type_create_hindexed_
void  (*INTERFACE_F_LOCAL_MPI_Type_create_hindexed)(int *,int *,size_t *,int *,int *,int *);

void pmpi_type_create_hindexed_(int * count,int * array_of_blocklengths,size_t * array_of_displacements,int * oldtype,int * newtype,int * ret){

return  INTERFACE_F_LOCAL_MPI_Type_create_hindexed( count, array_of_blocklengths, array_of_displacements,oldtype,newtype, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Type_create_hindexed)(int *,int *,size_t *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Type_create_hindexed)(int *,int *,size_t *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_type_create_indexed_block_(int * count,int * blocklength,int * array_of_displacements,int * oldtype,int * newtype,int * ret);
#pragma weak mpi_type_create_indexed_block_=pmpi_type_create_indexed_block_
void  (*INTERFACE_F_LOCAL_MPI_Type_create_indexed_block)(int *,int *,int *,int *,int *,int *);

void pmpi_type_create_indexed_block_(int * count,int * blocklength,int * array_of_displacements,int * oldtype,int * newtype,int * ret){

return  INTERFACE_F_LOCAL_MPI_Type_create_indexed_block( count, blocklength, array_of_displacements,oldtype,newtype, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Type_create_indexed_block)(int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Type_create_indexed_block)(int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_type_create_hindexed_block_(int * count,int * blocklength,size_t * array_of_displacements,int * oldtype,int * newtype,int * ret);
#pragma weak mpi_type_create_hindexed_block_=pmpi_type_create_hindexed_block_
void  (*INTERFACE_F_LOCAL_MPI_Type_create_hindexed_block)(int *,int *,size_t *,int *,int *,int *);

void pmpi_type_create_hindexed_block_(int * count,int * blocklength,size_t * array_of_displacements,int * oldtype,int * newtype,int * ret){

return  INTERFACE_F_LOCAL_MPI_Type_create_hindexed_block( count, blocklength, array_of_displacements,oldtype,newtype, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Type_create_hindexed_block)(int *,int *,size_t *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Type_create_hindexed_block)(int *,int *,size_t *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_type_create_struct_(int * count,int * array_of_blocklengths,size_t * array_of_displacements,int * array_of_types,int * newtype,int * ret);
#pragma weak mpi_type_create_struct_=pmpi_type_create_struct_
void  (*INTERFACE_F_LOCAL_MPI_Type_create_struct)(int *,int *,size_t *,int *,int *,int *);

void pmpi_type_create_struct_(int * count,int * array_of_blocklengths,size_t * array_of_displacements,int * array_of_types,int * newtype,int * ret){

return  INTERFACE_F_LOCAL_MPI_Type_create_struct( count, array_of_blocklengths, array_of_displacements,array_of_types,newtype, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Type_create_struct)(int *,int *,size_t *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Type_create_struct)(int *,int *,size_t *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_type_create_subarray_(int * ndims,int * array_of_sizes,int * array_of_subsizes,int * array_of_starts,int * order,int * oldtype,int * newtype,int * ret);
#pragma weak mpi_type_create_subarray_=pmpi_type_create_subarray_
void  (*INTERFACE_F_LOCAL_MPI_Type_create_subarray)(int *,int *,int *,int *,int *,int *,int *,int *);

void pmpi_type_create_subarray_(int * ndims,int * array_of_sizes,int * array_of_subsizes,int * array_of_starts,int * order,int * oldtype,int * newtype,int * ret){

return  INTERFACE_F_LOCAL_MPI_Type_create_subarray( ndims, array_of_sizes, array_of_subsizes, array_of_starts,order,oldtype,newtype, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Type_create_subarray)(int *,int *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Type_create_subarray)(int *,int *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_dist_graph_create_adjacent_(int * comm_old,int * indegree,int * sources,int * sourceweights,int * outdegree,int * destinations,int * destweights,int * info,int * reorder,int * comm_dist_graph,int * ret);
#pragma weak mpi_dist_graph_create_adjacent_=pmpi_dist_graph_create_adjacent_
void  (*INTERFACE_F_LOCAL_MPI_Dist_graph_create_adjacent)(int *,int *,int *,int *,int *,int *,int *,int *,int *,int *,int *);

void pmpi_dist_graph_create_adjacent_(int * comm_old,int * indegree,int * sources,int * sourceweights,int * outdegree,int * destinations,int * destweights,int * info,int * reorder,int * comm_dist_graph,int * ret){

return  INTERFACE_F_LOCAL_MPI_Dist_graph_create_adjacent(comm_old, indegree, sources,sourceweights, outdegree, destinations,destweights,info, reorder,comm_dist_graph, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Dist_graph_create_adjacent)(int *,int *,int *,int *,int *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Dist_graph_create_adjacent)(int *,int *,int *,int *,int *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_dist_graph_create_(int * comm_old,int * n,int * sources,int * degrees,int * destinations,int * weights,int * info,int * reorder,int * comm_dist_graph,int * ret);
#pragma weak mpi_dist_graph_create_=pmpi_dist_graph_create_
void  (*INTERFACE_F_LOCAL_MPI_Dist_graph_create)(int *,int *,int *,int *,int *,int *,int *,int *,int *,int *);

void pmpi_dist_graph_create_(int * comm_old,int * n,int * sources,int * degrees,int * destinations,int * weights,int * info,int * reorder,int * comm_dist_graph,int * ret){

return  INTERFACE_F_LOCAL_MPI_Dist_graph_create(comm_old, n, sources, degrees, destinations,weights,info, reorder,comm_dist_graph, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Dist_graph_create)(int *,int *,int *,int *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Dist_graph_create)(int *,int *,int *,int *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_dist_graph_neighbors_(int * comm,int * maxindegree,int * sources,int * sourceweights,int * maxoutdegree,int * destinations,int * destweights,int * ret);
#pragma weak mpi_dist_graph_neighbors_=pmpi_dist_graph_neighbors_
void  (*INTERFACE_F_LOCAL_MPI_Dist_graph_neighbors)(int *,int *,int *,int *,int *,int *,int *,int *);

void pmpi_dist_graph_neighbors_(int * comm,int * maxindegree,int * sources,int * sourceweights,int * maxoutdegree,int * destinations,int * destweights,int * ret){

return  INTERFACE_F_LOCAL_MPI_Dist_graph_neighbors(comm, maxindegree, sources,sourceweights, maxoutdegree, destinations,destweights, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Dist_graph_neighbors)(int *,int *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Dist_graph_neighbors)(int *,int *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_igatherv_(void * sendbuf,int * sendcount,int * sendtype,void * recvbuf,int * recvcounts,int * displs,int * recvtype,int * root,int * comm,int * request,int * ret);
#pragma weak mpi_igatherv_=pmpi_igatherv_
void  (*INTERFACE_F_LOCAL_MPI_Igatherv)(void *,int *,int *,void *,int *,int *,int *,int *,int *,int *,int *);

void pmpi_igatherv_(void * sendbuf,int * sendcount,int * sendtype,void * recvbuf,int * recvcounts,int * displs,int * recvtype,int * root,int * comm,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Igatherv(sendbuf, sendcount,sendtype,recvbuf, recvcounts, displs,recvtype, root,comm,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Igatherv)(void *,int *,int *,void *,int *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Igatherv)(void *,int *,int *,void *,int *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_iscatterv_(void * sendbuf,int * sendcounts,int * displs,int * sendtype,void * recvbuf,int * recvcount,int * recvtype,int * root,int * comm,int * request,int * ret);
#pragma weak mpi_iscatterv_=pmpi_iscatterv_
void  (*INTERFACE_F_LOCAL_MPI_Iscatterv)(void *,int *,int *,int *,void *,int *,int *,int *,int *,int *,int *);

void pmpi_iscatterv_(void * sendbuf,int * sendcounts,int * displs,int * sendtype,void * recvbuf,int * recvcount,int * recvtype,int * root,int * comm,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Iscatterv(sendbuf, sendcounts, displs,sendtype,recvbuf, recvcount,recvtype, root,comm,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Iscatterv)(void *,int *,int *,int *,void *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Iscatterv)(void *,int *,int *,int *,void *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_iallgatherv_(void * sendbuf,int * sendcount,int * sendtype,void * recvbuf,int * recvcounts,int * displs,int * recvtype,int * comm,int * request,int * ret);
#pragma weak mpi_iallgatherv_=pmpi_iallgatherv_
void  (*INTERFACE_F_LOCAL_MPI_Iallgatherv)(void *,int *,int *,void *,int *,int *,int *,int *,int *,int *);

void pmpi_iallgatherv_(void * sendbuf,int * sendcount,int * sendtype,void * recvbuf,int * recvcounts,int * displs,int * recvtype,int * comm,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Iallgatherv(sendbuf, sendcount,sendtype,recvbuf, recvcounts, displs,recvtype,comm,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Iallgatherv)(void *,int *,int *,void *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Iallgatherv)(void *,int *,int *,void *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_ialltoallv_(void * sendbuf,int * sendcounts,int * sdispls,int * sendtype,void * recvbuf,int * recvcounts,int * rdispls,int * recvtype,int * comm,int * request,int * ret);
#pragma weak mpi_ialltoallv_=pmpi_ialltoallv_
void  (*INTERFACE_F_LOCAL_MPI_Ialltoallv)(void *,int *,int *,int *,void *,int *,int *,int *,int *,int *,int *);

void pmpi_ialltoallv_(void * sendbuf,int * sendcounts,int * sdispls,int * sendtype,void * recvbuf,int * recvcounts,int * rdispls,int * recvtype,int * comm,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Ialltoallv(sendbuf, sendcounts, sdispls,sendtype,recvbuf, recvcounts, rdispls,recvtype,comm,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Ialltoallv)(void *,int *,int *,int *,void *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Ialltoallv)(void *,int *,int *,int *,void *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_ialltoallw_(void * sendbuf,int * sendcounts,int * sdispls,int * sendtypes,void * recvbuf,int * recvcounts,int * rdispls,int * recvtypes,int * comm,int * request,int * ret);
#pragma weak mpi_ialltoallw_=pmpi_ialltoallw_
void  (*INTERFACE_F_LOCAL_MPI_Ialltoallw)(void *,int *,int *,int *,void *,int *,int *,int *,int *,int *,int *);

void pmpi_ialltoallw_(void * sendbuf,int * sendcounts,int * sdispls,int * sendtypes,void * recvbuf,int * recvcounts,int * rdispls,int * recvtypes,int * comm,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Ialltoallw(sendbuf, sendcounts, sdispls,sendtypes,recvbuf, recvcounts, rdispls,recvtypes,comm,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Ialltoallw)(void *,int *,int *,int *,void *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Ialltoallw)(void *,int *,int *,int *,void *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_ireduce_scatter_(void * sendbuf,void * recvbuf,int * recvcounts,int * datatype,int * op,int * comm,int * request,int * ret);
#pragma weak mpi_ireduce_scatter_=pmpi_ireduce_scatter_
void  (*INTERFACE_F_LOCAL_MPI_Ireduce_scatter)(void *,void *,int *,int *,int *,int *,int *,int *);

void pmpi_ireduce_scatter_(void * sendbuf,void * recvbuf,int * recvcounts,int * datatype,int * op,int * comm,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Ireduce_scatter(sendbuf,recvbuf, recvcounts,datatype,op,comm,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Ireduce_scatter)(void *,void *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Ireduce_scatter)(void *,void *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_ineighbor_allgatherv_(void * sendbuf,int * sendcount,int * sendtype,void * recvbuf,int * recvcounts,int * displs,int * recvtype,int * comm,int * request,int * ret);
#pragma weak mpi_ineighbor_allgatherv_=pmpi_ineighbor_allgatherv_
void  (*INTERFACE_F_LOCAL_MPI_Ineighbor_allgatherv)(void *,int *,int *,void *,int *,int *,int *,int *,int *,int *);

void pmpi_ineighbor_allgatherv_(void * sendbuf,int * sendcount,int * sendtype,void * recvbuf,int * recvcounts,int * displs,int * recvtype,int * comm,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Ineighbor_allgatherv(sendbuf, sendcount,sendtype,recvbuf, recvcounts, displs,recvtype,comm,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Ineighbor_allgatherv)(void *,int *,int *,void *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Ineighbor_allgatherv)(void *,int *,int *,void *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_ineighbor_alltoallv_(void * sendbuf,int * sendcounts,int * sdispls,int * sendtype,void * recvbuf,int * recvcounts,int * rdispls,int * recvtype,int * comm,int * request,int * ret);
#pragma weak mpi_ineighbor_alltoallv_=pmpi_ineighbor_alltoallv_
void  (*INTERFACE_F_LOCAL_MPI_Ineighbor_alltoallv)(void *,int *,int *,int *,void *,int *,int *,int *,int *,int *,int *);

void pmpi_ineighbor_alltoallv_(void * sendbuf,int * sendcounts,int * sdispls,int * sendtype,void * recvbuf,int * recvcounts,int * rdispls,int * recvtype,int * comm,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Ineighbor_alltoallv(sendbuf, sendcounts, sdispls,sendtype,recvbuf, recvcounts, rdispls,recvtype,comm,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Ineighbor_alltoallv)(void *,int *,int *,int *,void *,int *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Ineighbor_alltoallv)(void *,int *,int *,int *,void *,int *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_ineighbor_alltoallw_(void * sendbuf,int * sendcounts,size_t * sdispls,int * sendtypes,void * recvbuf,int * recvcounts,size_t * rdispls,int * recvtypes,int * comm,int * request,int * ret);
#pragma weak mpi_ineighbor_alltoallw_=pmpi_ineighbor_alltoallw_
void  (*INTERFACE_F_LOCAL_MPI_Ineighbor_alltoallw)(void *,int *,size_t *,int *,void *,int *,size_t *,int *,int *,int *,int *);

void pmpi_ineighbor_alltoallw_(void * sendbuf,int * sendcounts,size_t * sdispls,int * sendtypes,void * recvbuf,int * recvcounts,size_t * rdispls,int * recvtypes,int * comm,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_Ineighbor_alltoallw(sendbuf, sendcounts, sdispls,sendtypes,recvbuf, recvcounts, rdispls,recvtypes,comm,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Ineighbor_alltoallw)(void *,int *,size_t *,int *,void *,int *,size_t *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Ineighbor_alltoallw)(void *,int *,size_t *,int *,void *,int *,size_t *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_neighbor_allgatherv_(void * sendbuf,int * sendcount,int * sendtype,void * recvbuf,int * recvcounts,int * displs,int * recvtype,int * comm,int * ret);
#pragma weak mpi_neighbor_allgatherv_=pmpi_neighbor_allgatherv_
void  (*INTERFACE_F_LOCAL_MPI_Neighbor_allgatherv)(void *,int *,int *,void *,int *,int *,int *,int *,int *);

void pmpi_neighbor_allgatherv_(void * sendbuf,int * sendcount,int * sendtype,void * recvbuf,int * recvcounts,int * displs,int * recvtype,int * comm,int * ret){

return  INTERFACE_F_LOCAL_MPI_Neighbor_allgatherv(sendbuf, sendcount,sendtype,recvbuf, recvcounts, displs,recvtype,comm, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Neighbor_allgatherv)(void *,int *,int *,void *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Neighbor_allgatherv)(void *,int *,int *,void *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_neighbor_alltoallv_(void * sendbuf,int * sendcounts,int * sdispls,int * sendtype,void * recvbuf,int * recvcounts,int * rdispls,int * recvtype,int * comm,int * ret);
#pragma weak mpi_neighbor_alltoallv_=pmpi_neighbor_alltoallv_
void  (*INTERFACE_F_LOCAL_MPI_Neighbor_alltoallv)(void *,int *,int *,int *,void *,int *,int *,int *,int *,int *);

void pmpi_neighbor_alltoallv_(void * sendbuf,int * sendcounts,int * sdispls,int * sendtype,void * recvbuf,int * recvcounts,int * rdispls,int * recvtype,int * comm,int * ret){

return  INTERFACE_F_LOCAL_MPI_Neighbor_alltoallv(sendbuf, sendcounts, sdispls,sendtype,recvbuf, recvcounts, rdispls,recvtype,comm, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Neighbor_alltoallv)(void *,int *,int *,int *,void *,int *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Neighbor_alltoallv)(void *,int *,int *,int *,void *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_neighbor_alltoallw_(void * sendbuf,int * sendcounts,size_t * sdispls,int * sendtypes,void * recvbuf,int * recvcounts,size_t * rdispls,int * recvtypes,int * comm,int * ret);
#pragma weak mpi_neighbor_alltoallw_=pmpi_neighbor_alltoallw_
void  (*INTERFACE_F_LOCAL_MPI_Neighbor_alltoallw)(void *,int *,size_t *,int *,void *,int *,size_t *,int *,int *,int *);

void pmpi_neighbor_alltoallw_(void * sendbuf,int * sendcounts,size_t * sdispls,int * sendtypes,void * recvbuf,int * recvcounts,size_t * rdispls,int * recvtypes,int * comm,int * ret){

return  INTERFACE_F_LOCAL_MPI_Neighbor_alltoallw(sendbuf, sendcounts, sdispls,sendtypes,recvbuf, recvcounts, rdispls,recvtypes,comm, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Neighbor_alltoallw)(void *,int *,size_t *,int *,void *,int *,size_t *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_Neighbor_alltoallw)(void *,int *,size_t *,int *,void *,int *,size_t *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_iwrite_all_(int * fh,void * buf,int * count,int * datatype,int * request,int * ret);
#pragma weak mpi_file_iwrite_all_=pmpi_file_iwrite_all_
void  (*INTERFACE_F_LOCAL_MPI_File_iwrite_all)(int *,void *,int *,int *,int *,int *);

void pmpi_file_iwrite_all_(int * fh,void * buf,int * count,int * datatype,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_iwrite_all( fh,buf, count,datatype,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_iwrite_all)(int *,void *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_iwrite_all)(int *,void *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_iwrite_at_all_(int * fh,int* offset,void * buf,int * count,int * datatype,int * request,int * ret);
#pragma weak mpi_file_iwrite_at_all_=pmpi_file_iwrite_at_all_
void  (*INTERFACE_F_LOCAL_MPI_File_iwrite_at_all)(int *,int*,void *,int *,int *,int *,int *);

void pmpi_file_iwrite_at_all_(int * fh,int* offset,void * buf,int * count,int * datatype,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_iwrite_at_all( fh, offset,buf, count,datatype,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_iwrite_at_all)(int *,int*,void *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_iwrite_at_all)(int *,int*,void *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_aint_add_(size_t * base,size_t * disp,size_t * ret);
#pragma weak mpi_aint_add_=pmpi_aint_add_
void  (*INTERFACE_F_LOCAL_MPI_Aint_add)(size_t *,size_t *,size_t *);

void pmpi_aint_add_(size_t * base,size_t * disp,size_t * ret){

return  INTERFACE_F_LOCAL_MPI_Aint_add( base, disp, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Aint_add)(size_t *,size_t *,size_t *);
extern  (*INTERF_2_INTEL_A_f_MPI_Aint_add)(size_t *,size_t *,size_t *);
#endif /*WI4MPI_STATIC*/
void  mpi_aint_diff_(size_t * addr1,size_t * addr2,size_t * ret);
#pragma weak mpi_aint_diff_=pmpi_aint_diff_
void  (*INTERFACE_F_LOCAL_MPI_Aint_diff)(size_t *,size_t *,size_t *);

void pmpi_aint_diff_(size_t * addr1,size_t * addr2,size_t * ret){

return  INTERFACE_F_LOCAL_MPI_Aint_diff( addr1, addr2, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_Aint_diff)(size_t *,size_t *,size_t *);
extern  (*INTERF_2_INTEL_A_f_MPI_Aint_diff)(size_t *,size_t *,size_t *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_iread_all_(int * fh,void * buf,int * count,int * datatype,int * request,int * ret);
#pragma weak mpi_file_iread_all_=pmpi_file_iread_all_
void  (*INTERFACE_F_LOCAL_MPI_File_iread_all)(int *,void *,int *,int *,int *,int *);

void pmpi_file_iread_all_(int * fh,void * buf,int * count,int * datatype,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_iread_all( fh,buf, count,datatype,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_iread_all)(int *,void *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_iread_all)(int *,void *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
void  mpi_file_iread_at_all_(int * fh,int* offset,void * buf,int * count,int * datatype,int * request,int * ret);
#pragma weak mpi_file_iread_at_all_=pmpi_file_iread_at_all_
void  (*INTERFACE_F_LOCAL_MPI_File_iread_at_all)(int *,int*,void *,int *,int *,int *,int *);

void pmpi_file_iread_at_all_(int * fh,int* offset,void * buf,int * count,int * datatype,int * request,int * ret){

return  INTERFACE_F_LOCAL_MPI_File_iread_at_all( fh, offset,buf, count,datatype,request, ret);
}

#ifdef WI4MPI_STATIC
extern  (*INTERF_2_OMPI_A_f_MPI_File_iread_at_all)(int *,int*,void *,int *,int *,int *,int *);
extern  (*INTERF_2_INTEL_A_f_MPI_File_iread_at_all)(int *,int*,void *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/
#ifdef WI4MPI_STATIC
extern void (INTERF_2_OMPI_A_f_MPI_Error_string)(void);
extern void (INTERF_2_OMPI_A_f_MPI_Get_processor_name)(void);
extern void (INTERF_2_OMPI_A_f_MPI_File_open)(void);
extern void (INTERF_2_OMPI_A_f_MPI_File_set_view)(void);
extern void (INTERF_2_OMPI_A_f_MPI_File_get_view)(void);
extern void (INTERF_2_OMPI_A_f_MPI_File_delete)(void);
extern void (INTERF_2_OMPI_A_f_MPI_Info_delete)(void);
extern void (INTERF_2_OMPI_A_f_MPI_Info_get)(void);
extern void (INTERF_2_OMPI_A_f_MPI_Info_get_nthkey)(void);
extern void (INTERF_2_OMPI_A_f_MPI_Info_get_valuelen)(void);
extern void (INTERF_2_OMPI_A_f_MPI_Info_set)(void);
extern void (INTERF_2_OMPI_A_f_MPI_Win_get_name)(void);
extern void (INTERF_2_OMPI_A_f_MPI_Win_set_name)(void);
extern void (INTERF_2_OMPI_A_f_MPI_Comm_spawn)(void);
extern void (INTERF_2_OMPI_A_f_MPI_Comm_get_name)(void);
extern void (INTERF_2_OMPI_A_f_MPI_Comm_set_name)(void);
extern void (INTERF_2_OMPI_A_f_MPI_Type_get_name)(void);
extern void (INTERF_2_OMPI_A_f_MPI_Type_set_name)(void);
extern void (INTERF_2_OMPI_A_f_MPI_Add_error_string)(void);
extern void (INTERF_2_OMPI_A_f_MPI_Close_port)(void);
extern void (INTERF_2_OMPI_A_f_MPI_Get_library_version)(void);
extern void (INTERF_2_OMPI_A_f_MPI_Open_port)(void);
extern void (INTERF_2_OMPI_A_f_MPI_Publish_name)(void);
extern void (INTERF_2_OMPI_A_f_MPI_Unpublish_name)(void);
extern void (INTERF_2_OMPI_A_f_MPI_Lookup_name)(void);
extern void (INTERF_2_OMPI_A_f_MPI_Pack_external)(void);
extern void (INTERF_2_OMPI_A_f_MPI_Pack_external_size)(void);
extern void (INTERF_2_OMPI_A_f_MPI_Unpack_external)(void);
extern void (INTERF_2_INTEL_A_f_MPI_Error_string)(void);
extern void (INTERF_2_INTEL_A_f_MPI_Get_processor_name)(void);
extern void (INTERF_2_INTEL_A_f_MPI_File_open)(void);
extern void (INTERF_2_INTEL_A_f_MPI_File_set_view)(void);
extern void (INTERF_2_INTEL_A_f_MPI_File_get_view)(void);
extern void (INTERF_2_INTEL_A_f_MPI_File_delete)(void);
extern void (INTERF_2_INTEL_A_f_MPI_Info_delete)(void);
extern void (INTERF_2_INTEL_A_f_MPI_Info_get)(void);
extern void (INTERF_2_INTEL_A_f_MPI_Info_get_nthkey)(void);
extern void (INTERF_2_INTEL_A_f_MPI_Info_get_valuelen)(void);
extern void (INTERF_2_INTEL_A_f_MPI_Info_set)(void);
extern void (INTERF_2_INTEL_A_f_MPI_Win_get_name)(void);
extern void (INTERF_2_INTEL_A_f_MPI_Win_set_name)(void);
extern void (INTERF_2_INTEL_A_f_MPI_Comm_spawn)(void);
extern void (INTERF_2_INTEL_A_f_MPI_Comm_get_name)(void);
extern void (INTERF_2_INTEL_A_f_MPI_Comm_set_name)(void);
extern void (INTERF_2_INTEL_A_f_MPI_Type_get_name)(void);
extern void (INTERF_2_INTEL_A_f_MPI_Type_set_name)(void);
extern void (INTERF_2_INTEL_A_f_MPI_Add_error_string)(void);
extern void (INTERF_2_INTEL_A_f_MPI_Close_port)(void);
extern void (INTERF_2_INTEL_A_f_MPI_Get_library_version)(void);
extern void (INTERF_2_INTEL_A_f_MPI_Open_port)(void);
extern void (INTERF_2_INTEL_A_f_MPI_Publish_name)(void);
extern void (INTERF_2_INTEL_A_f_MPI_Unpublish_name)(void);
extern void (INTERF_2_INTEL_A_f_MPI_Lookup_name)(void);
extern void (INTERF_2_INTEL_A_f_MPI_Pack_external)(void);
extern void (INTERF_2_INTEL_A_f_MPI_Pack_external_size)(void);
extern void (INTERF_2_INTEL_A_f_MPI_Unpack_external)(void);
#endif /*WI4MPI_STATIC*/
extern int wi4mpi__init__C;
int wi4mpi__init__F=0;
__attribute__((constructor)) void wrapper_interface_f(void) {
if(wi4mpi__init__F!=0)
    return;
else
    wi4mpi__init__F=1;
if(wi4mpi__init__C==0)
    wrapper_interface();
#ifndef WI4MPI_STATIC
#define to_string(name) #name
#define handle_loader(name)\
INTERFACE_F_LOCAL_##name=dlsym(interface_handle,to_string(CC##name))

#else
#define handle_loader(name,MPI_TARGET)\
INTERFACE_F_LOCAL_##name=&MPI_TARGET##name

#endif /*WI4MPI_STATIC*/
#ifndef WI4MPI_STATIC
void *interface_handle_f;
if(getenv("WI4MPI_WRAPPER_LIB") != NULL)
{
	interface_handle_f=dlopen(getenv("WI4MPI_WRAPPER_LIB"),RTLD_NOW|RTLD_GLOBAL);
}
else
{
	if(strcmp(wi4mpi_mode_f,"") != 0)
	{
		interface_handle_f=dlopen(wi4mpi_mode_f,RTLD_NOW|RTLD_GLOBAL);
	}
	else
	{
		fprintf(stderr,"Please provide either WI4MPI_WRAPPER_LIB environment or compile with -wi4mpi_default_run_paths\n");
		exit(1);
	}
}
if(!interface_handle_f)
{
	printf("Dlopen failed to open WI4MPI librarie.\nerror :%s\n",dlerror());
	exit(1);
}
INTERFACE_F_LOCAL_MPI_Pcontrol=dlsym(interface_handle_f,"A_f_MPI_Pcontrol");
INTERFACE_F_LOCAL_MPI_Send=dlsym(interface_handle_f,"A_f_MPI_Send");
INTERFACE_F_LOCAL_MPI_Recv=dlsym(interface_handle_f,"A_f_MPI_Recv");
INTERFACE_F_LOCAL_MPI_Get_count=dlsym(interface_handle_f,"A_f_MPI_Get_count");
INTERFACE_F_LOCAL_MPI_Bsend=dlsym(interface_handle_f,"A_f_MPI_Bsend");
INTERFACE_F_LOCAL_MPI_Ssend=dlsym(interface_handle_f,"A_f_MPI_Ssend");
INTERFACE_F_LOCAL_MPI_Rsend=dlsym(interface_handle_f,"A_f_MPI_Rsend");
INTERFACE_F_LOCAL_MPI_Buffer_attach=dlsym(interface_handle_f,"A_f_MPI_Buffer_attach");
INTERFACE_F_LOCAL_MPI_Buffer_detach=dlsym(interface_handle_f,"A_f_MPI_Buffer_detach");
INTERFACE_F_LOCAL_MPI_Isend=dlsym(interface_handle_f,"A_f_MPI_Isend");
INTERFACE_F_LOCAL_MPI_Ibsend=dlsym(interface_handle_f,"A_f_MPI_Ibsend");
INTERFACE_F_LOCAL_MPI_Issend=dlsym(interface_handle_f,"A_f_MPI_Issend");
INTERFACE_F_LOCAL_MPI_Irsend=dlsym(interface_handle_f,"A_f_MPI_Irsend");
INTERFACE_F_LOCAL_MPI_Irecv=dlsym(interface_handle_f,"A_f_MPI_Irecv");
INTERFACE_F_LOCAL_MPI_Wait=dlsym(interface_handle_f,"A_f_MPI_Wait");
INTERFACE_F_LOCAL_MPI_Test=dlsym(interface_handle_f,"A_f_MPI_Test");
INTERFACE_F_LOCAL_MPI_Request_free=dlsym(interface_handle_f,"A_f_MPI_Request_free");
INTERFACE_F_LOCAL_MPI_Iprobe=dlsym(interface_handle_f,"A_f_MPI_Iprobe");
INTERFACE_F_LOCAL_MPI_Probe=dlsym(interface_handle_f,"A_f_MPI_Probe");
INTERFACE_F_LOCAL_MPI_Cancel=dlsym(interface_handle_f,"A_f_MPI_Cancel");
INTERFACE_F_LOCAL_MPI_Test_cancelled=dlsym(interface_handle_f,"A_f_MPI_Test_cancelled");
INTERFACE_F_LOCAL_MPI_Send_init=dlsym(interface_handle_f,"A_f_MPI_Send_init");
INTERFACE_F_LOCAL_MPI_Bsend_init=dlsym(interface_handle_f,"A_f_MPI_Bsend_init");
INTERFACE_F_LOCAL_MPI_Ssend_init=dlsym(interface_handle_f,"A_f_MPI_Ssend_init");
INTERFACE_F_LOCAL_MPI_Rsend_init=dlsym(interface_handle_f,"A_f_MPI_Rsend_init");
INTERFACE_F_LOCAL_MPI_Recv_init=dlsym(interface_handle_f,"A_f_MPI_Recv_init");
INTERFACE_F_LOCAL_MPI_Start=dlsym(interface_handle_f,"A_f_MPI_Start");
INTERFACE_F_LOCAL_MPI_Sendrecv=dlsym(interface_handle_f,"A_f_MPI_Sendrecv");
INTERFACE_F_LOCAL_MPI_Sendrecv_replace=dlsym(interface_handle_f,"A_f_MPI_Sendrecv_replace");
INTERFACE_F_LOCAL_MPI_Type_contiguous=dlsym(interface_handle_f,"A_f_MPI_Type_contiguous");
INTERFACE_F_LOCAL_MPI_Type_vector=dlsym(interface_handle_f,"A_f_MPI_Type_vector");
INTERFACE_F_LOCAL_MPI_Type_hvector=dlsym(interface_handle_f,"A_f_MPI_Type_hvector");
INTERFACE_F_LOCAL_MPI_Type_indexed=dlsym(interface_handle_f,"A_f_MPI_Type_indexed");
INTERFACE_F_LOCAL_MPI_Type_hindexed=dlsym(interface_handle_f,"A_f_MPI_Type_hindexed");
INTERFACE_F_LOCAL_MPI_Type_struct=dlsym(interface_handle_f,"A_f_MPI_Type_struct");
INTERFACE_F_LOCAL_MPI_Address=dlsym(interface_handle_f,"A_f_MPI_Address");
INTERFACE_F_LOCAL_MPI_Type_extent=dlsym(interface_handle_f,"A_f_MPI_Type_extent");
INTERFACE_F_LOCAL_MPI_Type_size=dlsym(interface_handle_f,"A_f_MPI_Type_size");
INTERFACE_F_LOCAL_MPI_Type_lb=dlsym(interface_handle_f,"A_f_MPI_Type_lb");
INTERFACE_F_LOCAL_MPI_Type_ub=dlsym(interface_handle_f,"A_f_MPI_Type_ub");
INTERFACE_F_LOCAL_MPI_Type_commit=dlsym(interface_handle_f,"A_f_MPI_Type_commit");
INTERFACE_F_LOCAL_MPI_Type_free=dlsym(interface_handle_f,"A_f_MPI_Type_free");
INTERFACE_F_LOCAL_MPI_Get_elements=dlsym(interface_handle_f,"A_f_MPI_Get_elements");
INTERFACE_F_LOCAL_MPI_Pack=dlsym(interface_handle_f,"A_f_MPI_Pack");
INTERFACE_F_LOCAL_MPI_Unpack=dlsym(interface_handle_f,"A_f_MPI_Unpack");
INTERFACE_F_LOCAL_MPI_Pack_size=dlsym(interface_handle_f,"A_f_MPI_Pack_size");
INTERFACE_F_LOCAL_MPI_Barrier=dlsym(interface_handle_f,"A_f_MPI_Barrier");
INTERFACE_F_LOCAL_MPI_Bcast=dlsym(interface_handle_f,"A_f_MPI_Bcast");
INTERFACE_F_LOCAL_MPI_Gather=dlsym(interface_handle_f,"A_f_MPI_Gather");
INTERFACE_F_LOCAL_MPI_Gatherv=dlsym(interface_handle_f,"A_f_MPI_Gatherv");
INTERFACE_F_LOCAL_MPI_Scatter=dlsym(interface_handle_f,"A_f_MPI_Scatter");
INTERFACE_F_LOCAL_MPI_Scatterv=dlsym(interface_handle_f,"A_f_MPI_Scatterv");
INTERFACE_F_LOCAL_MPI_Allgather=dlsym(interface_handle_f,"A_f_MPI_Allgather");
INTERFACE_F_LOCAL_MPI_Allgatherv=dlsym(interface_handle_f,"A_f_MPI_Allgatherv");
INTERFACE_F_LOCAL_MPI_Alltoall=dlsym(interface_handle_f,"A_f_MPI_Alltoall");
INTERFACE_F_LOCAL_MPI_Alltoallv=dlsym(interface_handle_f,"A_f_MPI_Alltoallv");
INTERFACE_F_LOCAL_MPI_Exscan=dlsym(interface_handle_f,"A_f_MPI_Exscan");
INTERFACE_F_LOCAL_MPI_Reduce=dlsym(interface_handle_f,"A_f_MPI_Reduce");
INTERFACE_F_LOCAL_MPI_Op_create=dlsym(interface_handle_f,"A_f_MPI_Op_create");
INTERFACE_F_LOCAL_MPI_Op_free=dlsym(interface_handle_f,"A_f_MPI_Op_free");
INTERFACE_F_LOCAL_MPI_Allreduce=dlsym(interface_handle_f,"A_f_MPI_Allreduce");
INTERFACE_F_LOCAL_MPI_Scan=dlsym(interface_handle_f,"A_f_MPI_Scan");
INTERFACE_F_LOCAL_MPI_Group_size=dlsym(interface_handle_f,"A_f_MPI_Group_size");
INTERFACE_F_LOCAL_MPI_Group_rank=dlsym(interface_handle_f,"A_f_MPI_Group_rank");
INTERFACE_F_LOCAL_MPI_Group_compare=dlsym(interface_handle_f,"A_f_MPI_Group_compare");
INTERFACE_F_LOCAL_MPI_Comm_group=dlsym(interface_handle_f,"A_f_MPI_Comm_group");
INTERFACE_F_LOCAL_MPI_Group_union=dlsym(interface_handle_f,"A_f_MPI_Group_union");
INTERFACE_F_LOCAL_MPI_Group_intersection=dlsym(interface_handle_f,"A_f_MPI_Group_intersection");
INTERFACE_F_LOCAL_MPI_Group_difference=dlsym(interface_handle_f,"A_f_MPI_Group_difference");
INTERFACE_F_LOCAL_MPI_Group_free=dlsym(interface_handle_f,"A_f_MPI_Group_free");
INTERFACE_F_LOCAL_MPI_Comm_size=dlsym(interface_handle_f,"A_f_MPI_Comm_size");
INTERFACE_F_LOCAL_MPI_Comm_rank=dlsym(interface_handle_f,"A_f_MPI_Comm_rank");
INTERFACE_F_LOCAL_MPI_Comm_compare=dlsym(interface_handle_f,"A_f_MPI_Comm_compare");
INTERFACE_F_LOCAL_MPI_Comm_dup=dlsym(interface_handle_f,"A_f_MPI_Comm_dup");
INTERFACE_F_LOCAL_MPI_Comm_dup_with_info=dlsym(interface_handle_f,"A_f_MPI_Comm_dup_with_info");
INTERFACE_F_LOCAL_MPI_Comm_create=dlsym(interface_handle_f,"A_f_MPI_Comm_create");
INTERFACE_F_LOCAL_MPI_Comm_split=dlsym(interface_handle_f,"A_f_MPI_Comm_split");
INTERFACE_F_LOCAL_MPI_Comm_free=dlsym(interface_handle_f,"A_f_MPI_Comm_free");
INTERFACE_F_LOCAL_MPI_Comm_test_inter=dlsym(interface_handle_f,"A_f_MPI_Comm_test_inter");
INTERFACE_F_LOCAL_MPI_Comm_remote_size=dlsym(interface_handle_f,"A_f_MPI_Comm_remote_size");
INTERFACE_F_LOCAL_MPI_Comm_remote_group=dlsym(interface_handle_f,"A_f_MPI_Comm_remote_group");
INTERFACE_F_LOCAL_MPI_Intercomm_create=dlsym(interface_handle_f,"A_f_MPI_Intercomm_create");
INTERFACE_F_LOCAL_MPI_Intercomm_merge=dlsym(interface_handle_f,"A_f_MPI_Intercomm_merge");
INTERFACE_F_LOCAL_MPI_Keyval_create=dlsym(interface_handle_f,"A_f_MPI_Keyval_create");
INTERFACE_F_LOCAL_MPI_Keyval_free=dlsym(interface_handle_f,"A_f_MPI_Keyval_free");
INTERFACE_F_LOCAL_MPI_Attr_put=dlsym(interface_handle_f,"A_f_MPI_Attr_put");
INTERFACE_F_LOCAL_MPI_Attr_get=dlsym(interface_handle_f,"A_f_MPI_Attr_get");
INTERFACE_F_LOCAL_MPI_Attr_delete=dlsym(interface_handle_f,"A_f_MPI_Attr_delete");
INTERFACE_F_LOCAL_MPI_Topo_test=dlsym(interface_handle_f,"A_f_MPI_Topo_test");
INTERFACE_F_LOCAL_MPI_Graphdims_get=dlsym(interface_handle_f,"A_f_MPI_Graphdims_get");
INTERFACE_F_LOCAL_MPI_Cartdim_get=dlsym(interface_handle_f,"A_f_MPI_Cartdim_get");
INTERFACE_F_LOCAL_MPI_Graph_neighbors_count=dlsym(interface_handle_f,"A_f_MPI_Graph_neighbors_count");
INTERFACE_F_LOCAL_MPI_Cart_shift=dlsym(interface_handle_f,"A_f_MPI_Cart_shift");
INTERFACE_F_LOCAL_MPI_Get_version=dlsym(interface_handle_f,"A_f_MPI_Get_version");
INTERFACE_F_LOCAL_MPI_Errhandler_create=dlsym(interface_handle_f,"A_f_MPI_Errhandler_create");
INTERFACE_F_LOCAL_MPI_Errhandler_set=dlsym(interface_handle_f,"A_f_MPI_Errhandler_set");
INTERFACE_F_LOCAL_MPI_Errhandler_get=dlsym(interface_handle_f,"A_f_MPI_Errhandler_get");
INTERFACE_F_LOCAL_MPI_Errhandler_free=dlsym(interface_handle_f,"A_f_MPI_Errhandler_free");
INTERFACE_F_LOCAL_MPI_Error_class=dlsym(interface_handle_f,"A_f_MPI_Error_class");
INTERFACE_F_LOCAL_MPI_Initialized=dlsym(interface_handle_f,"A_f_MPI_Initialized");
INTERFACE_F_LOCAL_MPI_Abort=dlsym(interface_handle_f,"A_f_MPI_Abort");
INTERFACE_F_LOCAL_MPI_Init=dlsym(interface_handle_f,"A_f_MPI_Init");
INTERFACE_F_LOCAL_MPI_Comm_accept=dlsym(interface_handle_f,"A_f_MPI_Comm_accept");
INTERFACE_F_LOCAL_MPI_Comm_connect=dlsym(interface_handle_f,"A_f_MPI_Comm_connect");
INTERFACE_F_LOCAL_MPI_Comm_disconnect=dlsym(interface_handle_f,"A_f_MPI_Comm_disconnect");
INTERFACE_F_LOCAL_MPI_Comm_get_parent=dlsym(interface_handle_f,"A_f_MPI_Comm_get_parent");
INTERFACE_F_LOCAL_MPI_Comm_join=dlsym(interface_handle_f,"A_f_MPI_Comm_join");
INTERFACE_F_LOCAL_MPI_Comm_set_info=dlsym(interface_handle_f,"A_f_MPI_Comm_set_info");
INTERFACE_F_LOCAL_MPI_Comm_get_info=dlsym(interface_handle_f,"A_f_MPI_Comm_get_info");
INTERFACE_F_LOCAL_MPI_Accumulate=dlsym(interface_handle_f,"A_f_MPI_Accumulate");
INTERFACE_F_LOCAL_MPI_Get=dlsym(interface_handle_f,"A_f_MPI_Get");
INTERFACE_F_LOCAL_MPI_Put=dlsym(interface_handle_f,"A_f_MPI_Put");
INTERFACE_F_LOCAL_MPI_Win_complete=dlsym(interface_handle_f,"A_f_MPI_Win_complete");
INTERFACE_F_LOCAL_MPI_Win_create=dlsym(interface_handle_f,"A_f_MPI_Win_create");
INTERFACE_F_LOCAL_MPI_Win_fence=dlsym(interface_handle_f,"A_f_MPI_Win_fence");
INTERFACE_F_LOCAL_MPI_Win_free=dlsym(interface_handle_f,"A_f_MPI_Win_free");
INTERFACE_F_LOCAL_MPI_Win_get_group=dlsym(interface_handle_f,"A_f_MPI_Win_get_group");
INTERFACE_F_LOCAL_MPI_Win_lock=dlsym(interface_handle_f,"A_f_MPI_Win_lock");
INTERFACE_F_LOCAL_MPI_Win_post=dlsym(interface_handle_f,"A_f_MPI_Win_post");
INTERFACE_F_LOCAL_MPI_Win_start=dlsym(interface_handle_f,"A_f_MPI_Win_start");
INTERFACE_F_LOCAL_MPI_Win_test=dlsym(interface_handle_f,"A_f_MPI_Win_test");
INTERFACE_F_LOCAL_MPI_Win_unlock=dlsym(interface_handle_f,"A_f_MPI_Win_unlock");
INTERFACE_F_LOCAL_MPI_Win_wait=dlsym(interface_handle_f,"A_f_MPI_Win_wait");
INTERFACE_F_LOCAL_MPI_Win_allocate=dlsym(interface_handle_f,"A_f_MPI_Win_allocate");
INTERFACE_F_LOCAL_MPI_Win_allocate_shared=dlsym(interface_handle_f,"A_f_MPI_Win_allocate_shared");
INTERFACE_F_LOCAL_MPI_Win_shared_query=dlsym(interface_handle_f,"A_f_MPI_Win_shared_query");
INTERFACE_F_LOCAL_MPI_Win_create_dynamic=dlsym(interface_handle_f,"A_f_MPI_Win_create_dynamic");
INTERFACE_F_LOCAL_MPI_Win_attach=dlsym(interface_handle_f,"A_f_MPI_Win_attach");
INTERFACE_F_LOCAL_MPI_Win_detach=dlsym(interface_handle_f,"A_f_MPI_Win_detach");
INTERFACE_F_LOCAL_MPI_Win_get_info=dlsym(interface_handle_f,"A_f_MPI_Win_get_info");
INTERFACE_F_LOCAL_MPI_Win_set_info=dlsym(interface_handle_f,"A_f_MPI_Win_set_info");
INTERFACE_F_LOCAL_MPI_Get_accumulate=dlsym(interface_handle_f,"A_f_MPI_Get_accumulate");
INTERFACE_F_LOCAL_MPI_Fetch_and_op=dlsym(interface_handle_f,"A_f_MPI_Fetch_and_op");
INTERFACE_F_LOCAL_MPI_Compare_and_swap=dlsym(interface_handle_f,"A_f_MPI_Compare_and_swap");
INTERFACE_F_LOCAL_MPI_Rput=dlsym(interface_handle_f,"A_f_MPI_Rput");
INTERFACE_F_LOCAL_MPI_Rget=dlsym(interface_handle_f,"A_f_MPI_Rget");
INTERFACE_F_LOCAL_MPI_Raccumulate=dlsym(interface_handle_f,"A_f_MPI_Raccumulate");
INTERFACE_F_LOCAL_MPI_Rget_accumulate=dlsym(interface_handle_f,"A_f_MPI_Rget_accumulate");
INTERFACE_F_LOCAL_MPI_Win_lock_all=dlsym(interface_handle_f,"A_f_MPI_Win_lock_all");
INTERFACE_F_LOCAL_MPI_Win_unlock_all=dlsym(interface_handle_f,"A_f_MPI_Win_unlock_all");
INTERFACE_F_LOCAL_MPI_Win_flush=dlsym(interface_handle_f,"A_f_MPI_Win_flush");
INTERFACE_F_LOCAL_MPI_Win_flush_all=dlsym(interface_handle_f,"A_f_MPI_Win_flush_all");
INTERFACE_F_LOCAL_MPI_Win_flush_local=dlsym(interface_handle_f,"A_f_MPI_Win_flush_local");
INTERFACE_F_LOCAL_MPI_Win_flush_local_all=dlsym(interface_handle_f,"A_f_MPI_Win_flush_local_all");
INTERFACE_F_LOCAL_MPI_Win_sync=dlsym(interface_handle_f,"A_f_MPI_Win_sync");
INTERFACE_F_LOCAL_MPI_Add_error_class=dlsym(interface_handle_f,"A_f_MPI_Add_error_class");
INTERFACE_F_LOCAL_MPI_Add_error_code=dlsym(interface_handle_f,"A_f_MPI_Add_error_code");
INTERFACE_F_LOCAL_MPI_Comm_call_errhandler=dlsym(interface_handle_f,"A_f_MPI_Comm_call_errhandler");
INTERFACE_F_LOCAL_MPI_Comm_create_keyval=dlsym(interface_handle_f,"A_f_MPI_Comm_create_keyval");
INTERFACE_F_LOCAL_MPI_Comm_delete_attr=dlsym(interface_handle_f,"A_f_MPI_Comm_delete_attr");
INTERFACE_F_LOCAL_MPI_Comm_free_keyval=dlsym(interface_handle_f,"A_f_MPI_Comm_free_keyval");
INTERFACE_F_LOCAL_MPI_Comm_get_attr=dlsym(interface_handle_f,"A_f_MPI_Comm_get_attr");
INTERFACE_F_LOCAL_MPI_Comm_set_attr=dlsym(interface_handle_f,"A_f_MPI_Comm_set_attr");
INTERFACE_F_LOCAL_MPI_File_call_errhandler=dlsym(interface_handle_f,"A_f_MPI_File_call_errhandler");
INTERFACE_F_LOCAL_MPI_Grequest_complete=dlsym(interface_handle_f,"A_f_MPI_Grequest_complete");
INTERFACE_F_LOCAL_MPI_Grequest_start=dlsym(interface_handle_f,"A_f_MPI_Grequest_start");
INTERFACE_F_LOCAL_MPI_Init_thread=dlsym(interface_handle_f,"A_f_MPI_Init_thread");
INTERFACE_F_LOCAL_MPI_Is_thread_main=dlsym(interface_handle_f,"A_f_MPI_Is_thread_main");
INTERFACE_F_LOCAL_MPI_Query_thread=dlsym(interface_handle_f,"A_f_MPI_Query_thread");
INTERFACE_F_LOCAL_MPI_Status_set_cancelled=dlsym(interface_handle_f,"A_f_MPI_Status_set_cancelled");
INTERFACE_F_LOCAL_MPI_Status_set_elements=dlsym(interface_handle_f,"A_f_MPI_Status_set_elements");
INTERFACE_F_LOCAL_MPI_Type_create_keyval=dlsym(interface_handle_f,"A_f_MPI_Type_create_keyval");
INTERFACE_F_LOCAL_MPI_Type_delete_attr=dlsym(interface_handle_f,"A_f_MPI_Type_delete_attr");
INTERFACE_F_LOCAL_MPI_Type_dup=dlsym(interface_handle_f,"A_f_MPI_Type_dup");
INTERFACE_F_LOCAL_MPI_Type_free_keyval=dlsym(interface_handle_f,"A_f_MPI_Type_free_keyval");
INTERFACE_F_LOCAL_MPI_Type_get_attr=dlsym(interface_handle_f,"A_f_MPI_Type_get_attr");
INTERFACE_F_LOCAL_MPI_Type_get_envelope=dlsym(interface_handle_f,"A_f_MPI_Type_get_envelope");
INTERFACE_F_LOCAL_MPI_Type_set_attr=dlsym(interface_handle_f,"A_f_MPI_Type_set_attr");
INTERFACE_F_LOCAL_MPI_Type_match_size=dlsym(interface_handle_f,"A_f_MPI_Type_match_size");
INTERFACE_F_LOCAL_MPI_Win_call_errhandler=dlsym(interface_handle_f,"A_f_MPI_Win_call_errhandler");
INTERFACE_F_LOCAL_MPI_Win_create_keyval=dlsym(interface_handle_f,"A_f_MPI_Win_create_keyval");
INTERFACE_F_LOCAL_MPI_Win_delete_attr=dlsym(interface_handle_f,"A_f_MPI_Win_delete_attr");
INTERFACE_F_LOCAL_MPI_Win_free_keyval=dlsym(interface_handle_f,"A_f_MPI_Win_free_keyval");
INTERFACE_F_LOCAL_MPI_Win_get_attr=dlsym(interface_handle_f,"A_f_MPI_Win_get_attr");
INTERFACE_F_LOCAL_MPI_Win_set_attr=dlsym(interface_handle_f,"A_f_MPI_Win_set_attr");
INTERFACE_F_LOCAL_MPI_Alloc_mem=dlsym(interface_handle_f,"A_f_MPI_Alloc_mem");
INTERFACE_F_LOCAL_MPI_Comm_create_errhandler=dlsym(interface_handle_f,"A_f_MPI_Comm_create_errhandler");
INTERFACE_F_LOCAL_MPI_Comm_get_errhandler=dlsym(interface_handle_f,"A_f_MPI_Comm_get_errhandler");
INTERFACE_F_LOCAL_MPI_Comm_set_errhandler=dlsym(interface_handle_f,"A_f_MPI_Comm_set_errhandler");
INTERFACE_F_LOCAL_MPI_File_create_errhandler=dlsym(interface_handle_f,"A_f_MPI_File_create_errhandler");
INTERFACE_F_LOCAL_MPI_File_get_errhandler=dlsym(interface_handle_f,"A_f_MPI_File_get_errhandler");
INTERFACE_F_LOCAL_MPI_File_set_errhandler=dlsym(interface_handle_f,"A_f_MPI_File_set_errhandler");
INTERFACE_F_LOCAL_MPI_Finalized=dlsym(interface_handle_f,"A_f_MPI_Finalized");
INTERFACE_F_LOCAL_MPI_Free_mem=dlsym(interface_handle_f,"A_f_MPI_Free_mem");
INTERFACE_F_LOCAL_MPI_Get_address=dlsym(interface_handle_f,"A_f_MPI_Get_address");
INTERFACE_F_LOCAL_MPI_Info_create=dlsym(interface_handle_f,"A_f_MPI_Info_create");
INTERFACE_F_LOCAL_MPI_Info_dup=dlsym(interface_handle_f,"A_f_MPI_Info_dup");
INTERFACE_F_LOCAL_MPI_Info_free=dlsym(interface_handle_f,"A_f_MPI_Info_free");
INTERFACE_F_LOCAL_MPI_Info_get_nkeys=dlsym(interface_handle_f,"A_f_MPI_Info_get_nkeys");
INTERFACE_F_LOCAL_MPI_Request_get_status=dlsym(interface_handle_f,"A_f_MPI_Request_get_status");
INTERFACE_F_LOCAL_MPI_Type_create_hvector=dlsym(interface_handle_f,"A_f_MPI_Type_create_hvector");
INTERFACE_F_LOCAL_MPI_Type_create_resized=dlsym(interface_handle_f,"A_f_MPI_Type_create_resized");
INTERFACE_F_LOCAL_MPI_Type_get_extent=dlsym(interface_handle_f,"A_f_MPI_Type_get_extent");
INTERFACE_F_LOCAL_MPI_Type_get_true_extent=dlsym(interface_handle_f,"A_f_MPI_Type_get_true_extent");
INTERFACE_F_LOCAL_MPI_Win_create_errhandler=dlsym(interface_handle_f,"A_f_MPI_Win_create_errhandler");
INTERFACE_F_LOCAL_MPI_Win_get_errhandler=dlsym(interface_handle_f,"A_f_MPI_Win_get_errhandler");
INTERFACE_F_LOCAL_MPI_Win_set_errhandler=dlsym(interface_handle_f,"A_f_MPI_Win_set_errhandler");
INTERFACE_F_LOCAL_MPI_Type_create_f90_integer=dlsym(interface_handle_f,"A_f_MPI_Type_create_f90_integer");
INTERFACE_F_LOCAL_MPI_Type_create_f90_real=dlsym(interface_handle_f,"A_f_MPI_Type_create_f90_real");
INTERFACE_F_LOCAL_MPI_Type_create_f90_complex=dlsym(interface_handle_f,"A_f_MPI_Type_create_f90_complex");
INTERFACE_F_LOCAL_MPI_Reduce_local=dlsym(interface_handle_f,"A_f_MPI_Reduce_local");
INTERFACE_F_LOCAL_MPI_Op_commutative=dlsym(interface_handle_f,"A_f_MPI_Op_commutative");
INTERFACE_F_LOCAL_MPI_Reduce_scatter_block=dlsym(interface_handle_f,"A_f_MPI_Reduce_scatter_block");
INTERFACE_F_LOCAL_MPI_Dist_graph_neighbors_count=dlsym(interface_handle_f,"A_f_MPI_Dist_graph_neighbors_count");
INTERFACE_F_LOCAL_MPI_Improbe=dlsym(interface_handle_f,"A_f_MPI_Improbe");
INTERFACE_F_LOCAL_MPI_Imrecv=dlsym(interface_handle_f,"A_f_MPI_Imrecv");
INTERFACE_F_LOCAL_MPI_Mprobe=dlsym(interface_handle_f,"A_f_MPI_Mprobe");
INTERFACE_F_LOCAL_MPI_Mrecv=dlsym(interface_handle_f,"A_f_MPI_Mrecv");
INTERFACE_F_LOCAL_MPI_Comm_idup=dlsym(interface_handle_f,"A_f_MPI_Comm_idup");
INTERFACE_F_LOCAL_MPI_Ibarrier=dlsym(interface_handle_f,"A_f_MPI_Ibarrier");
INTERFACE_F_LOCAL_MPI_Ibcast=dlsym(interface_handle_f,"A_f_MPI_Ibcast");
INTERFACE_F_LOCAL_MPI_Igather=dlsym(interface_handle_f,"A_f_MPI_Igather");
INTERFACE_F_LOCAL_MPI_Iscatter=dlsym(interface_handle_f,"A_f_MPI_Iscatter");
INTERFACE_F_LOCAL_MPI_Iallgather=dlsym(interface_handle_f,"A_f_MPI_Iallgather");
INTERFACE_F_LOCAL_MPI_Ialltoall=dlsym(interface_handle_f,"A_f_MPI_Ialltoall");
INTERFACE_F_LOCAL_MPI_Ireduce=dlsym(interface_handle_f,"A_f_MPI_Ireduce");
INTERFACE_F_LOCAL_MPI_Iallreduce=dlsym(interface_handle_f,"A_f_MPI_Iallreduce");
INTERFACE_F_LOCAL_MPI_Ireduce_scatter_block=dlsym(interface_handle_f,"A_f_MPI_Ireduce_scatter_block");
INTERFACE_F_LOCAL_MPI_Iscan=dlsym(interface_handle_f,"A_f_MPI_Iscan");
INTERFACE_F_LOCAL_MPI_Iexscan=dlsym(interface_handle_f,"A_f_MPI_Iexscan");
INTERFACE_F_LOCAL_MPI_Ineighbor_allgather=dlsym(interface_handle_f,"A_f_MPI_Ineighbor_allgather");
INTERFACE_F_LOCAL_MPI_Ineighbor_alltoall=dlsym(interface_handle_f,"A_f_MPI_Ineighbor_alltoall");
INTERFACE_F_LOCAL_MPI_Neighbor_allgather=dlsym(interface_handle_f,"A_f_MPI_Neighbor_allgather");
INTERFACE_F_LOCAL_MPI_Neighbor_alltoall=dlsym(interface_handle_f,"A_f_MPI_Neighbor_alltoall");
INTERFACE_F_LOCAL_MPI_Comm_split_type=dlsym(interface_handle_f,"A_f_MPI_Comm_split_type");
INTERFACE_F_LOCAL_MPI_Get_elements_x=dlsym(interface_handle_f,"A_f_MPI_Get_elements_x");
INTERFACE_F_LOCAL_MPI_Status_set_elements_x=dlsym(interface_handle_f,"A_f_MPI_Status_set_elements_x");
INTERFACE_F_LOCAL_MPI_Type_get_extent_x=dlsym(interface_handle_f,"A_f_MPI_Type_get_extent_x");
INTERFACE_F_LOCAL_MPI_Type_get_true_extent_x=dlsym(interface_handle_f,"A_f_MPI_Type_get_true_extent_x");
INTERFACE_F_LOCAL_MPI_Type_size_x=dlsym(interface_handle_f,"A_f_MPI_Type_size_x");
INTERFACE_F_LOCAL_MPI_Comm_create_group=dlsym(interface_handle_f,"A_f_MPI_Comm_create_group");
INTERFACE_F_LOCAL_MPI_File_close=dlsym(interface_handle_f,"A_f_MPI_File_close");
INTERFACE_F_LOCAL_MPI_File_set_size=dlsym(interface_handle_f,"A_f_MPI_File_set_size");
INTERFACE_F_LOCAL_MPI_File_preallocate=dlsym(interface_handle_f,"A_f_MPI_File_preallocate");
INTERFACE_F_LOCAL_MPI_File_get_size=dlsym(interface_handle_f,"A_f_MPI_File_get_size");
INTERFACE_F_LOCAL_MPI_File_get_group=dlsym(interface_handle_f,"A_f_MPI_File_get_group");
INTERFACE_F_LOCAL_MPI_File_get_amode=dlsym(interface_handle_f,"A_f_MPI_File_get_amode");
INTERFACE_F_LOCAL_MPI_File_set_info=dlsym(interface_handle_f,"A_f_MPI_File_set_info");
INTERFACE_F_LOCAL_MPI_File_get_info=dlsym(interface_handle_f,"A_f_MPI_File_get_info");
INTERFACE_F_LOCAL_MPI_File_read_at=dlsym(interface_handle_f,"A_f_MPI_File_read_at");
INTERFACE_F_LOCAL_MPI_File_read_at_all=dlsym(interface_handle_f,"A_f_MPI_File_read_at_all");
INTERFACE_F_LOCAL_MPI_File_write_at=dlsym(interface_handle_f,"A_f_MPI_File_write_at");
INTERFACE_F_LOCAL_MPI_File_write_at_all=dlsym(interface_handle_f,"A_f_MPI_File_write_at_all");
INTERFACE_F_LOCAL_MPI_File_iread_at=dlsym(interface_handle_f,"A_f_MPI_File_iread_at");
INTERFACE_F_LOCAL_MPI_File_iwrite_at=dlsym(interface_handle_f,"A_f_MPI_File_iwrite_at");
INTERFACE_F_LOCAL_MPI_File_read=dlsym(interface_handle_f,"A_f_MPI_File_read");
INTERFACE_F_LOCAL_MPI_File_read_all=dlsym(interface_handle_f,"A_f_MPI_File_read_all");
INTERFACE_F_LOCAL_MPI_File_write=dlsym(interface_handle_f,"A_f_MPI_File_write");
INTERFACE_F_LOCAL_MPI_File_write_all=dlsym(interface_handle_f,"A_f_MPI_File_write_all");
INTERFACE_F_LOCAL_MPI_File_iread=dlsym(interface_handle_f,"A_f_MPI_File_iread");
INTERFACE_F_LOCAL_MPI_File_iwrite=dlsym(interface_handle_f,"A_f_MPI_File_iwrite");
INTERFACE_F_LOCAL_MPI_File_seek=dlsym(interface_handle_f,"A_f_MPI_File_seek");
INTERFACE_F_LOCAL_MPI_File_get_position=dlsym(interface_handle_f,"A_f_MPI_File_get_position");
INTERFACE_F_LOCAL_MPI_File_get_byte_offset=dlsym(interface_handle_f,"A_f_MPI_File_get_byte_offset");
INTERFACE_F_LOCAL_MPI_File_read_shared=dlsym(interface_handle_f,"A_f_MPI_File_read_shared");
INTERFACE_F_LOCAL_MPI_File_write_shared=dlsym(interface_handle_f,"A_f_MPI_File_write_shared");
INTERFACE_F_LOCAL_MPI_File_iread_shared=dlsym(interface_handle_f,"A_f_MPI_File_iread_shared");
INTERFACE_F_LOCAL_MPI_File_iwrite_shared=dlsym(interface_handle_f,"A_f_MPI_File_iwrite_shared");
INTERFACE_F_LOCAL_MPI_File_read_ordered=dlsym(interface_handle_f,"A_f_MPI_File_read_ordered");
INTERFACE_F_LOCAL_MPI_File_write_ordered=dlsym(interface_handle_f,"A_f_MPI_File_write_ordered");
INTERFACE_F_LOCAL_MPI_File_seek_shared=dlsym(interface_handle_f,"A_f_MPI_File_seek_shared");
INTERFACE_F_LOCAL_MPI_File_get_position_shared=dlsym(interface_handle_f,"A_f_MPI_File_get_position_shared");
INTERFACE_F_LOCAL_MPI_File_read_at_all_begin=dlsym(interface_handle_f,"A_f_MPI_File_read_at_all_begin");
INTERFACE_F_LOCAL_MPI_File_read_at_all_end=dlsym(interface_handle_f,"A_f_MPI_File_read_at_all_end");
INTERFACE_F_LOCAL_MPI_File_write_at_all_begin=dlsym(interface_handle_f,"A_f_MPI_File_write_at_all_begin");
INTERFACE_F_LOCAL_MPI_File_write_at_all_end=dlsym(interface_handle_f,"A_f_MPI_File_write_at_all_end");
INTERFACE_F_LOCAL_MPI_File_read_all_begin=dlsym(interface_handle_f,"A_f_MPI_File_read_all_begin");
INTERFACE_F_LOCAL_MPI_File_read_all_end=dlsym(interface_handle_f,"A_f_MPI_File_read_all_end");
INTERFACE_F_LOCAL_MPI_File_write_all_begin=dlsym(interface_handle_f,"A_f_MPI_File_write_all_begin");
INTERFACE_F_LOCAL_MPI_File_write_all_end=dlsym(interface_handle_f,"A_f_MPI_File_write_all_end");
INTERFACE_F_LOCAL_MPI_File_read_ordered_begin=dlsym(interface_handle_f,"A_f_MPI_File_read_ordered_begin");
INTERFACE_F_LOCAL_MPI_File_read_ordered_end=dlsym(interface_handle_f,"A_f_MPI_File_read_ordered_end");
INTERFACE_F_LOCAL_MPI_File_write_ordered_begin=dlsym(interface_handle_f,"A_f_MPI_File_write_ordered_begin");
INTERFACE_F_LOCAL_MPI_File_write_ordered_end=dlsym(interface_handle_f,"A_f_MPI_File_write_ordered_end");
INTERFACE_F_LOCAL_MPI_File_get_type_extent=dlsym(interface_handle_f,"A_f_MPI_File_get_type_extent");
INTERFACE_F_LOCAL_MPI_File_set_atomicity=dlsym(interface_handle_f,"A_f_MPI_File_set_atomicity");
INTERFACE_F_LOCAL_MPI_File_get_atomicity=dlsym(interface_handle_f,"A_f_MPI_File_get_atomicity");
INTERFACE_F_LOCAL_MPI_File_sync=dlsym(interface_handle_f,"A_f_MPI_File_sync");
INTERFACE_F_LOCAL_MPI_Wtime=dlsym(interface_handle_f,"A_f_MPI_Wtime");
INTERFACE_F_LOCAL_MPI_Wtick=dlsym(interface_handle_f,"A_f_MPI_Wtick");
INTERFACE_F_LOCAL_MPI_Finalize=dlsym(interface_handle_f,"A_f_MPI_Finalize");
INTERFACE_F_LOCAL_MPI_Waitany=dlsym(interface_handle_f,"A_f_MPI_Waitany");
INTERFACE_F_LOCAL_MPI_Testany=dlsym(interface_handle_f,"A_f_MPI_Testany");
INTERFACE_F_LOCAL_MPI_Waitall=dlsym(interface_handle_f,"A_f_MPI_Waitall");
INTERFACE_F_LOCAL_MPI_Testall=dlsym(interface_handle_f,"A_f_MPI_Testall");
INTERFACE_F_LOCAL_MPI_Waitsome=dlsym(interface_handle_f,"A_f_MPI_Waitsome");
INTERFACE_F_LOCAL_MPI_Testsome=dlsym(interface_handle_f,"A_f_MPI_Testsome");
INTERFACE_F_LOCAL_MPI_Startall=dlsym(interface_handle_f,"A_f_MPI_Startall");
INTERFACE_F_LOCAL_MPI_Alltoallw=dlsym(interface_handle_f,"A_f_MPI_Alltoallw");
INTERFACE_F_LOCAL_MPI_Reduce_scatter=dlsym(interface_handle_f,"A_f_MPI_Reduce_scatter");
INTERFACE_F_LOCAL_MPI_Group_translate_ranks=dlsym(interface_handle_f,"A_f_MPI_Group_translate_ranks");
INTERFACE_F_LOCAL_MPI_Group_incl=dlsym(interface_handle_f,"A_f_MPI_Group_incl");
INTERFACE_F_LOCAL_MPI_Group_excl=dlsym(interface_handle_f,"A_f_MPI_Group_excl");
INTERFACE_F_LOCAL_MPI_Group_range_incl=dlsym(interface_handle_f,"A_f_MPI_Group_range_incl");
INTERFACE_F_LOCAL_MPI_Group_range_excl=dlsym(interface_handle_f,"A_f_MPI_Group_range_excl");
INTERFACE_F_LOCAL_MPI_Cart_create=dlsym(interface_handle_f,"A_f_MPI_Cart_create");
INTERFACE_F_LOCAL_MPI_Dims_create=dlsym(interface_handle_f,"A_f_MPI_Dims_create");
INTERFACE_F_LOCAL_MPI_Graph_create=dlsym(interface_handle_f,"A_f_MPI_Graph_create");
INTERFACE_F_LOCAL_MPI_Graph_get=dlsym(interface_handle_f,"A_f_MPI_Graph_get");
INTERFACE_F_LOCAL_MPI_Cart_get=dlsym(interface_handle_f,"A_f_MPI_Cart_get");
INTERFACE_F_LOCAL_MPI_Cart_rank=dlsym(interface_handle_f,"A_f_MPI_Cart_rank");
INTERFACE_F_LOCAL_MPI_Cart_coords=dlsym(interface_handle_f,"A_f_MPI_Cart_coords");
INTERFACE_F_LOCAL_MPI_Graph_neighbors=dlsym(interface_handle_f,"A_f_MPI_Graph_neighbors");
INTERFACE_F_LOCAL_MPI_Cart_sub=dlsym(interface_handle_f,"A_f_MPI_Cart_sub");
INTERFACE_F_LOCAL_MPI_Cart_map=dlsym(interface_handle_f,"A_f_MPI_Cart_map");
INTERFACE_F_LOCAL_MPI_Graph_map=dlsym(interface_handle_f,"A_f_MPI_Graph_map");
INTERFACE_F_LOCAL_MPI_Type_get_contents=dlsym(interface_handle_f,"A_f_MPI_Type_get_contents");
INTERFACE_F_LOCAL_MPI_Type_create_darray=dlsym(interface_handle_f,"A_f_MPI_Type_create_darray");
INTERFACE_F_LOCAL_MPI_Type_create_hindexed=dlsym(interface_handle_f,"A_f_MPI_Type_create_hindexed");
INTERFACE_F_LOCAL_MPI_Type_create_indexed_block=dlsym(interface_handle_f,"A_f_MPI_Type_create_indexed_block");
INTERFACE_F_LOCAL_MPI_Type_create_hindexed_block=dlsym(interface_handle_f,"A_f_MPI_Type_create_hindexed_block");
INTERFACE_F_LOCAL_MPI_Type_create_struct=dlsym(interface_handle_f,"A_f_MPI_Type_create_struct");
INTERFACE_F_LOCAL_MPI_Type_create_subarray=dlsym(interface_handle_f,"A_f_MPI_Type_create_subarray");
INTERFACE_F_LOCAL_MPI_Dist_graph_create_adjacent=dlsym(interface_handle_f,"A_f_MPI_Dist_graph_create_adjacent");
INTERFACE_F_LOCAL_MPI_Dist_graph_create=dlsym(interface_handle_f,"A_f_MPI_Dist_graph_create");
INTERFACE_F_LOCAL_MPI_Dist_graph_neighbors=dlsym(interface_handle_f,"A_f_MPI_Dist_graph_neighbors");
INTERFACE_F_LOCAL_MPI_Igatherv=dlsym(interface_handle_f,"A_f_MPI_Igatherv");
INTERFACE_F_LOCAL_MPI_Iscatterv=dlsym(interface_handle_f,"A_f_MPI_Iscatterv");
INTERFACE_F_LOCAL_MPI_Iallgatherv=dlsym(interface_handle_f,"A_f_MPI_Iallgatherv");
INTERFACE_F_LOCAL_MPI_Ialltoallv=dlsym(interface_handle_f,"A_f_MPI_Ialltoallv");
INTERFACE_F_LOCAL_MPI_Ialltoallw=dlsym(interface_handle_f,"A_f_MPI_Ialltoallw");
INTERFACE_F_LOCAL_MPI_Ireduce_scatter=dlsym(interface_handle_f,"A_f_MPI_Ireduce_scatter");
INTERFACE_F_LOCAL_MPI_Ineighbor_allgatherv=dlsym(interface_handle_f,"A_f_MPI_Ineighbor_allgatherv");
INTERFACE_F_LOCAL_MPI_Ineighbor_alltoallv=dlsym(interface_handle_f,"A_f_MPI_Ineighbor_alltoallv");
INTERFACE_F_LOCAL_MPI_Ineighbor_alltoallw=dlsym(interface_handle_f,"A_f_MPI_Ineighbor_alltoallw");
INTERFACE_F_LOCAL_MPI_Neighbor_allgatherv=dlsym(interface_handle_f,"A_f_MPI_Neighbor_allgatherv");
INTERFACE_F_LOCAL_MPI_Neighbor_alltoallv=dlsym(interface_handle_f,"A_f_MPI_Neighbor_alltoallv");
INTERFACE_F_LOCAL_MPI_Neighbor_alltoallw=dlsym(interface_handle_f,"A_f_MPI_Neighbor_alltoallw");
INTERFACE_F_LOCAL_MPI_File_iwrite_all=dlsym(interface_handle_f,"A_f_MPI_File_iwrite_all");
INTERFACE_F_LOCAL_MPI_File_iwrite_at_all=dlsym(interface_handle_f,"A_f_MPI_File_iwrite_at_all");
INTERFACE_F_LOCAL_MPI_Aint_add=dlsym(interface_handle_f,"A_f_MPI_Aint_add");
INTERFACE_F_LOCAL_MPI_Aint_diff=dlsym(interface_handle_f,"A_f_MPI_Aint_diff");
INTERFACE_F_LOCAL_MPI_File_iread_all=dlsym(interface_handle_f,"A_f_MPI_File_iread_all");
INTERFACE_F_LOCAL_MPI_File_iread_at_all=dlsym(interface_handle_f,"A_f_MPI_File_iread_at_all");
INTERFACE_F_LOCAL_MPI_Error_string=dlsym(interface_handle_f, "A_f_MPI_Error_string");
INTERFACE_F_LOCAL_MPI_Get_processor_name=dlsym(interface_handle_f, "A_f_MPI_Get_processor_name");
INTERFACE_F_LOCAL_MPI_File_open=dlsym(interface_handle_f, "A_f_MPI_File_open");
INTERFACE_F_LOCAL_MPI_File_set_view=dlsym(interface_handle_f, "A_f_MPI_File_set_view");
INTERFACE_F_LOCAL_MPI_File_get_view=dlsym(interface_handle_f, "A_f_MPI_File_get_view");
INTERFACE_F_LOCAL_MPI_File_delete=dlsym(interface_handle_f, "A_f_MPI_File_delete");
INTERFACE_F_LOCAL_MPI_Info_delete=dlsym(interface_handle_f, "A_f_MPI_Info_delete");
INTERFACE_F_LOCAL_MPI_Info_get=dlsym(interface_handle_f, "A_f_MPI_Info_get");
INTERFACE_F_LOCAL_MPI_Info_get_nthkey=dlsym(interface_handle_f, "A_f_MPI_Info_get_nthkey");
INTERFACE_F_LOCAL_MPI_Info_get_valuelen=dlsym(interface_handle_f, "A_f_MPI_Info_get_valuelen");
INTERFACE_F_LOCAL_MPI_Info_set=dlsym(interface_handle_f, "A_f_MPI_Info_set");
INTERFACE_F_LOCAL_MPI_Win_get_name=dlsym(interface_handle_f, "A_f_MPI_Win_get_name");
INTERFACE_F_LOCAL_MPI_Win_set_name=dlsym(interface_handle_f, "A_f_MPI_Win_set_name");
INTERFACE_F_LOCAL_MPI_Comm_get_name=dlsym(interface_handle_f, "A_f_MPI_Comm_get_name");
INTERFACE_F_LOCAL_MPI_Comm_set_name=dlsym(interface_handle_f, "A_f_MPI_Comm_set_name");
INTERFACE_F_LOCAL_MPI_Comm_spawn=dlsym(interface_handle_f, "A_f_MPI_Comm_spawn");
INTERFACE_F_LOCAL_MPI_Type_get_name=dlsym(interface_handle_f, "A_f_MPI_Type_get_name");
INTERFACE_F_LOCAL_MPI_Type_set_name=dlsym(interface_handle_f, "A_f_MPI_Type_set_name");
INTERFACE_F_LOCAL_MPI_Add_error_string=dlsym(interface_handle_f, "A_f_MPI_Add_error_string");
INTERFACE_F_LOCAL_MPI_Close_port=dlsym(interface_handle_f, "A_f_MPI_Close_port");
INTERFACE_F_LOCAL_MPI_Get_library_version=dlsym(interface_handle_f, "A_f_MPI_Get_library_version");
INTERFACE_F_LOCAL_MPI_Open_port=dlsym(interface_handle_f, "A_f_MPI_Open_port");
INTERFACE_F_LOCAL_MPI_Publish_name=dlsym(interface_handle_f, "A_f_MPI_Publish_name");
INTERFACE_F_LOCAL_MPI_Unpublish_name=dlsym(interface_handle_f, "A_f_MPI_Unpublish_name");
INTERFACE_F_LOCAL_MPI_Lookup_name=dlsym(interface_handle_f, "A_f_MPI_Lookup_name");
INTERFACE_F_LOCAL_MPI_Pack_external=dlsym(interface_handle_f, "A_f_MPI_Pack_external");
INTERFACE_F_LOCAL_MPI_Pack_external_size=dlsym(interface_handle_f, "A_f_MPI_Pack_external_size");
INTERFACE_F_LOCAL_MPI_Unpack_external=dlsym(interface_handle_f, "A_f_MPI_Unpack_external");
#else
char *target=getenv("WI4MPI_STATIC_TARGET_TYPE");
if(target&&!strcmp(target,"OMPI")){
handle_loader(MPI_Pcontrol,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Send,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Recv,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Get_count,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Bsend,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Ssend,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Rsend,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Buffer_attach,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Buffer_detach,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Isend,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Ibsend,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Issend,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Irsend,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Irecv,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Wait,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Test,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Request_free,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Iprobe,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Probe,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Cancel,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Test_cancelled,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Send_init,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Bsend_init,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Ssend_init,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Rsend_init,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Recv_init,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Start,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Sendrecv,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Sendrecv_replace,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Type_contiguous,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Type_vector,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Type_hvector,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Type_indexed,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Type_hindexed,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Type_struct,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Address,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Type_extent,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Type_size,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Type_lb,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Type_ub,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Type_commit,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Type_free,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Get_elements,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Pack,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Unpack,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Pack_size,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Barrier,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Bcast,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Gather,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Gatherv,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Scatter,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Scatterv,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Allgather,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Allgatherv,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Alltoall,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Alltoallv,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Exscan,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Reduce,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Op_create,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Op_free,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Allreduce,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Scan,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Group_size,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Group_rank,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Group_compare,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Comm_group,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Group_union,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Group_intersection,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Group_difference,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Group_free,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Comm_size,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Comm_rank,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Comm_compare,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Comm_dup,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Comm_dup_with_info,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Comm_create,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Comm_split,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Comm_free,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Comm_test_inter,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Comm_remote_size,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Comm_remote_group,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Intercomm_create,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Intercomm_merge,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Keyval_create,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Keyval_free,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Attr_put,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Attr_get,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Attr_delete,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Topo_test,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Graphdims_get,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Cartdim_get,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Graph_neighbors_count,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Cart_shift,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Get_version,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Errhandler_create,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Errhandler_set,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Errhandler_get,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Errhandler_free,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Error_class,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Initialized,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Abort,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Init,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Comm_accept,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Comm_connect,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Comm_disconnect,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Comm_get_parent,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Comm_join,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Comm_set_info,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Comm_get_info,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Accumulate,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Get,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Put,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Win_complete,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Win_create,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Win_fence,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Win_free,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Win_get_group,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Win_lock,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Win_post,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Win_start,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Win_test,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Win_unlock,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Win_wait,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Win_allocate,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Win_allocate_shared,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Win_shared_query,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Win_create_dynamic,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Win_attach,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Win_detach,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Win_get_info,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Win_set_info,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Get_accumulate,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Fetch_and_op,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Compare_and_swap,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Rput,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Rget,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Raccumulate,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Rget_accumulate,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Win_lock_all,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Win_unlock_all,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Win_flush,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Win_flush_all,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Win_flush_local,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Win_flush_local_all,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Win_sync,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Add_error_class,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Add_error_code,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Comm_call_errhandler,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Comm_create_keyval,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Comm_delete_attr,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Comm_free_keyval,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Comm_get_attr,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Comm_set_attr,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_call_errhandler,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Grequest_complete,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Grequest_start,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Init_thread,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Is_thread_main,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Query_thread,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Status_set_cancelled,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Status_set_elements,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Type_create_keyval,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Type_delete_attr,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Type_dup,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Type_free_keyval,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Type_get_attr,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Type_get_envelope,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Type_set_attr,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Type_match_size,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Win_call_errhandler,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Win_create_keyval,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Win_delete_attr,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Win_free_keyval,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Win_get_attr,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Win_set_attr,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Alloc_mem,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Comm_create_errhandler,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Comm_get_errhandler,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Comm_set_errhandler,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_create_errhandler,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_get_errhandler,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_set_errhandler,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Finalized,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Free_mem,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Get_address,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Info_create,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Info_dup,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Info_free,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Info_get_nkeys,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Request_get_status,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Type_create_hvector,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Type_create_resized,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Type_get_extent,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Type_get_true_extent,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Win_create_errhandler,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Win_get_errhandler,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Win_set_errhandler,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Type_create_f90_integer,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Type_create_f90_real,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Type_create_f90_complex,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Reduce_local,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Op_commutative,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Reduce_scatter_block,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Dist_graph_neighbors_count,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Improbe,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Imrecv,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Mprobe,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Mrecv,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Comm_idup,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Ibarrier,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Ibcast,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Igather,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Iscatter,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Iallgather,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Ialltoall,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Ireduce,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Iallreduce,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Ireduce_scatter_block,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Iscan,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Iexscan,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Ineighbor_allgather,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Ineighbor_alltoall,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Neighbor_allgather,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Neighbor_alltoall,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Comm_split_type,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Get_elements_x,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Status_set_elements_x,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Type_get_extent_x,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Type_get_true_extent_x,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Type_size_x,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Comm_create_group,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_close,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_set_size,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_preallocate,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_get_size,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_get_group,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_get_amode,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_set_info,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_get_info,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_read_at,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_read_at_all,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_write_at,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_write_at_all,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_iread_at,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_iwrite_at,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_read,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_read_all,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_write,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_write_all,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_iread,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_iwrite,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_seek,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_get_position,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_get_byte_offset,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_read_shared,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_write_shared,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_iread_shared,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_iwrite_shared,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_read_ordered,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_write_ordered,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_seek_shared,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_get_position_shared,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_read_at_all_begin,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_read_at_all_end,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_write_at_all_begin,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_write_at_all_end,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_read_all_begin,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_read_all_end,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_write_all_begin,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_write_all_end,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_read_ordered_begin,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_read_ordered_end,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_write_ordered_begin,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_write_ordered_end,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_get_type_extent,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_set_atomicity,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_get_atomicity,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_sync,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Wtime,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Wtick,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Finalize,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Waitany,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Testany,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Waitall,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Testall,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Waitsome,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Testsome,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Startall,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Alltoallw,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Reduce_scatter,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Group_translate_ranks,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Group_incl,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Group_excl,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Group_range_incl,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Group_range_excl,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Cart_create,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Dims_create,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Graph_create,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Graph_get,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Cart_get,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Cart_rank,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Cart_coords,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Graph_neighbors,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Cart_sub,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Cart_map,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Graph_map,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Type_get_contents,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Type_create_darray,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Type_create_hindexed,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Type_create_indexed_block,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Type_create_hindexed_block,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Type_create_struct,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Type_create_subarray,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Dist_graph_create_adjacent,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Dist_graph_create,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Dist_graph_neighbors,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Igatherv,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Iscatterv,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Iallgatherv,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Ialltoallv,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Ialltoallw,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Ireduce_scatter,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Ineighbor_allgatherv,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Ineighbor_alltoallv,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Ineighbor_alltoallw,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Neighbor_allgatherv,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Neighbor_alltoallv,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Neighbor_alltoallw,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_iwrite_all,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_iwrite_at_all,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Aint_add,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Aint_diff,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_iread_all,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_iread_at_all,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Error_string,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Get_processor_name,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_open,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_set_view,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_get_view,INTERF_2_OMPI_A_f_);
handle_loader(MPI_File_delete,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Info_delete,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Info_get,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Info_get_nthkey,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Info_get_valuelen,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Info_set,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Win_get_name,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Win_set_name,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Comm_get_name,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Comm_set_name,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Comm_spawn,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Type_get_name,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Type_set_name,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Add_error_string,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Close_port,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Get_library_version,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Open_port,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Publish_name,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Unpublish_name,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Lookup_name,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Pack_external,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Pack_external_size,INTERF_2_OMPI_A_f_);
handle_loader(MPI_Unpack_external,INTERF_2_OMPI_A_f_);
}else
if(target&&!strcmp(target,"INTEL")){
handle_loader(MPI_Pcontrol,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Send,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Recv,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Get_count,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Bsend,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Ssend,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Rsend,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Buffer_attach,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Buffer_detach,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Isend,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Ibsend,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Issend,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Irsend,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Irecv,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Wait,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Test,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Request_free,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Iprobe,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Probe,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Cancel,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Test_cancelled,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Send_init,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Bsend_init,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Ssend_init,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Rsend_init,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Recv_init,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Start,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Sendrecv,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Sendrecv_replace,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Type_contiguous,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Type_vector,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Type_hvector,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Type_indexed,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Type_hindexed,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Type_struct,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Address,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Type_extent,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Type_size,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Type_lb,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Type_ub,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Type_commit,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Type_free,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Get_elements,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Pack,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Unpack,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Pack_size,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Barrier,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Bcast,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Gather,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Gatherv,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Scatter,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Scatterv,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Allgather,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Allgatherv,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Alltoall,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Alltoallv,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Exscan,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Reduce,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Op_create,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Op_free,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Allreduce,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Scan,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Group_size,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Group_rank,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Group_compare,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Comm_group,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Group_union,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Group_intersection,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Group_difference,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Group_free,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Comm_size,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Comm_rank,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Comm_compare,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Comm_dup,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Comm_dup_with_info,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Comm_create,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Comm_split,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Comm_free,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Comm_test_inter,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Comm_remote_size,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Comm_remote_group,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Intercomm_create,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Intercomm_merge,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Keyval_create,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Keyval_free,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Attr_put,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Attr_get,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Attr_delete,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Topo_test,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Graphdims_get,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Cartdim_get,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Graph_neighbors_count,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Cart_shift,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Get_version,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Errhandler_create,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Errhandler_set,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Errhandler_get,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Errhandler_free,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Error_class,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Initialized,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Abort,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Init,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Comm_accept,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Comm_connect,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Comm_disconnect,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Comm_get_parent,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Comm_join,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Comm_set_info,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Comm_get_info,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Accumulate,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Get,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Put,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Win_complete,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Win_create,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Win_fence,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Win_free,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Win_get_group,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Win_lock,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Win_post,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Win_start,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Win_test,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Win_unlock,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Win_wait,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Win_allocate,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Win_allocate_shared,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Win_shared_query,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Win_create_dynamic,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Win_attach,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Win_detach,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Win_get_info,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Win_set_info,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Get_accumulate,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Fetch_and_op,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Compare_and_swap,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Rput,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Rget,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Raccumulate,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Rget_accumulate,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Win_lock_all,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Win_unlock_all,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Win_flush,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Win_flush_all,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Win_flush_local,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Win_flush_local_all,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Win_sync,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Add_error_class,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Add_error_code,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Comm_call_errhandler,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Comm_create_keyval,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Comm_delete_attr,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Comm_free_keyval,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Comm_get_attr,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Comm_set_attr,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_call_errhandler,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Grequest_complete,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Grequest_start,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Init_thread,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Is_thread_main,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Query_thread,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Status_set_cancelled,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Status_set_elements,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Type_create_keyval,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Type_delete_attr,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Type_dup,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Type_free_keyval,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Type_get_attr,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Type_get_envelope,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Type_set_attr,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Type_match_size,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Win_call_errhandler,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Win_create_keyval,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Win_delete_attr,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Win_free_keyval,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Win_get_attr,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Win_set_attr,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Alloc_mem,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Comm_create_errhandler,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Comm_get_errhandler,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Comm_set_errhandler,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_create_errhandler,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_get_errhandler,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_set_errhandler,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Finalized,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Free_mem,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Get_address,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Info_create,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Info_dup,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Info_free,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Info_get_nkeys,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Request_get_status,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Type_create_hvector,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Type_create_resized,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Type_get_extent,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Type_get_true_extent,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Win_create_errhandler,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Win_get_errhandler,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Win_set_errhandler,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Type_create_f90_integer,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Type_create_f90_real,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Type_create_f90_complex,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Reduce_local,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Op_commutative,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Reduce_scatter_block,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Dist_graph_neighbors_count,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Improbe,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Imrecv,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Mprobe,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Mrecv,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Comm_idup,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Ibarrier,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Ibcast,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Igather,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Iscatter,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Iallgather,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Ialltoall,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Ireduce,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Iallreduce,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Ireduce_scatter_block,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Iscan,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Iexscan,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Ineighbor_allgather,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Ineighbor_alltoall,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Neighbor_allgather,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Neighbor_alltoall,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Comm_split_type,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Get_elements_x,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Status_set_elements_x,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Type_get_extent_x,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Type_get_true_extent_x,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Type_size_x,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Comm_create_group,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_close,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_set_size,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_preallocate,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_get_size,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_get_group,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_get_amode,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_set_info,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_get_info,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_read_at,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_read_at_all,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_write_at,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_write_at_all,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_iread_at,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_iwrite_at,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_read,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_read_all,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_write,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_write_all,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_iread,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_iwrite,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_seek,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_get_position,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_get_byte_offset,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_read_shared,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_write_shared,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_iread_shared,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_iwrite_shared,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_read_ordered,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_write_ordered,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_seek_shared,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_get_position_shared,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_read_at_all_begin,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_read_at_all_end,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_write_at_all_begin,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_write_at_all_end,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_read_all_begin,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_read_all_end,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_write_all_begin,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_write_all_end,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_read_ordered_begin,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_read_ordered_end,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_write_ordered_begin,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_write_ordered_end,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_get_type_extent,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_set_atomicity,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_get_atomicity,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_sync,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Wtime,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Wtick,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Finalize,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Waitany,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Testany,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Waitall,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Testall,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Waitsome,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Testsome,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Startall,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Alltoallw,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Reduce_scatter,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Group_translate_ranks,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Group_incl,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Group_excl,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Group_range_incl,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Group_range_excl,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Cart_create,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Dims_create,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Graph_create,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Graph_get,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Cart_get,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Cart_rank,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Cart_coords,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Graph_neighbors,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Cart_sub,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Cart_map,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Graph_map,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Type_get_contents,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Type_create_darray,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Type_create_hindexed,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Type_create_indexed_block,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Type_create_hindexed_block,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Type_create_struct,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Type_create_subarray,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Dist_graph_create_adjacent,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Dist_graph_create,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Dist_graph_neighbors,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Igatherv,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Iscatterv,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Iallgatherv,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Ialltoallv,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Ialltoallw,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Ireduce_scatter,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Ineighbor_allgatherv,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Ineighbor_alltoallv,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Ineighbor_alltoallw,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Neighbor_allgatherv,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Neighbor_alltoallv,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Neighbor_alltoallw,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_iwrite_all,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_iwrite_at_all,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Aint_add,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Aint_diff,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_iread_all,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_iread_at_all,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Error_string,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Get_processor_name,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_open,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_set_view,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_get_view,INTERF_2_INTEL_A_f_);
handle_loader(MPI_File_delete,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Info_delete,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Info_get,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Info_get_nthkey,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Info_get_valuelen,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Info_set,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Win_get_name,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Win_set_name,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Comm_get_name,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Comm_set_name,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Comm_spawn,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Type_get_name,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Type_set_name,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Add_error_string,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Close_port,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Get_library_version,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Open_port,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Publish_name,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Unpublish_name,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Lookup_name,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Pack_external,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Pack_external_size,INTERF_2_INTEL_A_f_);
handle_loader(MPI_Unpack_external,INTERF_2_INTEL_A_f_);
}else
{printf("no valid WI4MPI_STATIC_TARGET_TYPE defined\n");exit(1);}
#endif
}

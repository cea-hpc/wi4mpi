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
 * This code is fully generated
 */
#include <stdlib.h>
#define _GNU_SOURCE
#include <stdio.h>
#include <dlfcn.h>
#include "mpi.h"

char wi4mpi_mode[]="";

__thread int in_w;
/*ompi constante*/
int MPI_Comm_create_keyval
(MPI_Copy_function * copy_fn,MPI_Delete_function * delete_fn,int * keyval,void * extra_state);
#pragma weak MPI_Comm_create_keyval=PMPI_Comm_create_keyval
int (*INTERFACE_LOCAL_MPI_Comm_create_keyval)(MPI_Copy_function *,MPI_Delete_function *,int *,void *);
int PMPI_Comm_create_keyval(MPI_Copy_function * copy_fn,MPI_Delete_function * delete_fn,int * keyval,void * extra_state)
{
#ifdef DEBUF
 printf("entre : MPI_Comm_create_keyval (interface)\n");
#endif
 int ret_tmp = INTERFACE_LOCAL_MPI_Comm_create_keyval( copy_fn, delete_fn, keyval, extra_state);
#ifdef DEBUG
 printf("sort : MPI_Comm_create_keyval (interface)\n");
#endif
 return ret_tmp;
}

int MPI_Keyval_create(MPI_Copy_function * copy_fn,MPI_Delete_function * delete_fn,int * keyval,void * extra_state);
#pragma weak MPI_Keyval_create=PMPI_Keyval_create
int (*INTERFACE_LOCAL_MPI_Keyval_create)(MPI_Copy_function *,MPI_Delete_function *,int *,void *);
int PMPI_Keyval_create(MPI_Copy_function * copy_fn,MPI_Delete_function * delete_fn,int * keyval,void * extra_state)
{
#ifdef DEBUG
    printf("entre : MPI_keyval_create (interface)\n");
#endif
    int ret_tmp = INTERFACE_LOCAL_MPI_Keyval_create(copy_fn, delete_fn, keyval, extra_state);
#ifdef DEBUG    
    printf("sort: MPI_keyval_create (interface)\n");
#endif
    return ret_tmp;
}

int MPI_Comm_free_keyval(int *comm_keyval);
#pragma weak MPI_Comm_free_keyval=PMPI_Comm_free_keyval
int (*INTERFACE_LOCAL_MPI_Comm_free_keyval)(int *);
int PMPI_Comm_free_keyval(int * comm_keyval)
{
#ifdef DEBUG
     printf("entre : MPI_Comm_free_keyval (interface)\n");
#endif
     int ret_tmp = INTERFACE_LOCAL_MPI_Comm_free_keyval(comm_keyval);
#ifdef DEBUG
     printf("sort : MPI_Comm_free_keyval (interface)\n");
#endif
     return ret_tmp;
}

int MPI_Keyval_free(int *keyval);
#pragma weak MPI_Keyval_free=PMPI_Keyval_free
int (*INTERFACE_LOCAL_MPI_Keyval_free)(int *);
int PMPI_Keyval_free(int * keyval)
{
#ifdef DEBUG
      printf("entre : MPI_Keyval_free (interface) \n");
#endif      
      int ret_tmp = INTERFACE_LOCAL_MPI_Keyval_free(keyval);
#ifdef DEBUG      
      printf("sort : MPI_Keyval_free (interface) \n");
#endif      
      return ret_tmp;
}
int MPI_Win_get_attr(MPI_Win win,int win_keyval,void * attribute_val,int * flag);
#pragma weak MPI_Win_get_attr=PMPI_Win_get_attr
int (*INTERFACE_LOCAL_MPI_Win_get_attr)(MPI_Win,int,void *,int *);

int PMPI_Win_get_attr(MPI_Win win,int win_keyval,void * attribute_val,int * flag)
{
#ifdef DEBUG
printf("entre : PMPI_Win_get_attr (interface) \n");
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Win_get_attr( win, win_keyval, attribute_val, flag);
#ifdef DEBUG
printf("sort : PMPI_Win_get_attr (interface)\n");
#endif
return ret_tmp;
}
int MPI_Win_set_attr(MPI_Win win,int win_keyval,void * attribute_val);
#pragma weak MPI_Win_set_attr=PMPI_Win_set_attr
int (*INTERFACE_LOCAL_MPI_Win_set_attr)(MPI_Win,int,void *);

int PMPI_Win_set_attr(MPI_Win win,int win_keyval,void * attribute_val)
{
#ifdef DEBUG
printf("entre : PMPI_Win_set_attr (interface) \n");
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Win_set_attr( win, win_keyval, attribute_val);
#ifdef DEBUG
printf("sort : PMPI_Win_set_attr (interface)\n");
#endif
return ret_tmp;
}

int MPI_Pcontrol(int level,...);
#pragma weak MPI_Pcontrol=PMPI_Pcontrol
int (*INTERFACE_LOCAL_MPI_Pcontrol)(int,...);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Pcontrol(int,...);
extern int INTERF_2_INTEL_CCMPI_Pcontrol(int,...);
#endif /*WI4MPI_STATIC*/

int PMPI_Pcontrol(int level,...)
{
	return MPI_SUCCESS;
}
int MPI_Send(void * buf,int count,MPI_Datatype datatype,int dest,int tag,MPI_Comm comm);
#pragma weak MPI_Send=PMPI_Send
int (*INTERFACE_LOCAL_MPI_Send)(void *,int,MPI_Datatype,int,int,MPI_Comm);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Send(void *,int,MPI_Datatype,int,int,MPI_Comm);
extern int INTERF_2_INTEL_CCMPI_Send(void *,int,MPI_Datatype,int,int,MPI_Comm);
#endif /*WI4MPI_STATIC*/

int PMPI_Send(void * buf,int count,MPI_Datatype datatype,int dest,int tag,MPI_Comm comm)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Send( buf, count, datatype, dest, tag, comm);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Recv(void * buf,int count,MPI_Datatype datatype,int source,int tag,MPI_Comm comm,MPI_Status * status);
#pragma weak MPI_Recv=PMPI_Recv
int (*INTERFACE_LOCAL_MPI_Recv)(void *,int,MPI_Datatype,int,int,MPI_Comm,MPI_Status *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Recv(void *,int,MPI_Datatype,int,int,MPI_Comm,MPI_Status *);
extern int INTERF_2_INTEL_CCMPI_Recv(void *,int,MPI_Datatype,int,int,MPI_Comm,MPI_Status *);
#endif /*WI4MPI_STATIC*/

int PMPI_Recv(void * buf,int count,MPI_Datatype datatype,int source,int tag,MPI_Comm comm,MPI_Status * status)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Recv( buf, count, datatype, source, tag, comm, status);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Get_count(MPI_Status * status,MPI_Datatype datatype,int * count);
#pragma weak MPI_Get_count=PMPI_Get_count
int (*INTERFACE_LOCAL_MPI_Get_count)(MPI_Status *,MPI_Datatype,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Get_count(MPI_Status *,MPI_Datatype,int *);
extern int INTERF_2_INTEL_CCMPI_Get_count(MPI_Status *,MPI_Datatype,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Get_count(MPI_Status * status,MPI_Datatype datatype,int * count)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Get_count( status, datatype, count);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Bsend(void * buf,int count,MPI_Datatype datatype,int dest,int tag,MPI_Comm comm);
#pragma weak MPI_Bsend=PMPI_Bsend
int (*INTERFACE_LOCAL_MPI_Bsend)(void *,int,MPI_Datatype,int,int,MPI_Comm);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Bsend(void *,int,MPI_Datatype,int,int,MPI_Comm);
extern int INTERF_2_INTEL_CCMPI_Bsend(void *,int,MPI_Datatype,int,int,MPI_Comm);
#endif /*WI4MPI_STATIC*/

int PMPI_Bsend(void * buf,int count,MPI_Datatype datatype,int dest,int tag,MPI_Comm comm)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Bsend( buf, count, datatype, dest, tag, comm);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Ssend(void * buf,int count,MPI_Datatype datatype,int dest,int tag,MPI_Comm comm);
#pragma weak MPI_Ssend=PMPI_Ssend
int (*INTERFACE_LOCAL_MPI_Ssend)(void *,int,MPI_Datatype,int,int,MPI_Comm);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Ssend(void *,int,MPI_Datatype,int,int,MPI_Comm);
extern int INTERF_2_INTEL_CCMPI_Ssend(void *,int,MPI_Datatype,int,int,MPI_Comm);
#endif /*WI4MPI_STATIC*/

int PMPI_Ssend(void * buf,int count,MPI_Datatype datatype,int dest,int tag,MPI_Comm comm)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Ssend( buf, count, datatype, dest, tag, comm);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Rsend(void * buf,int count,MPI_Datatype datatype,int dest,int tag,MPI_Comm comm);
#pragma weak MPI_Rsend=PMPI_Rsend
int (*INTERFACE_LOCAL_MPI_Rsend)(void *,int,MPI_Datatype,int,int,MPI_Comm);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Rsend(void *,int,MPI_Datatype,int,int,MPI_Comm);
extern int INTERF_2_INTEL_CCMPI_Rsend(void *,int,MPI_Datatype,int,int,MPI_Comm);
#endif /*WI4MPI_STATIC*/

int PMPI_Rsend(void * buf,int count,MPI_Datatype datatype,int dest,int tag,MPI_Comm comm)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Rsend( buf, count, datatype, dest, tag, comm);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Buffer_attach(void * buffer,int size);
#pragma weak MPI_Buffer_attach=PMPI_Buffer_attach
int (*INTERFACE_LOCAL_MPI_Buffer_attach)(void *,int);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Buffer_attach(void *,int);
extern int INTERF_2_INTEL_CCMPI_Buffer_attach(void *,int);
#endif /*WI4MPI_STATIC*/

int PMPI_Buffer_attach(void * buffer,int size)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Buffer_attach( buffer, size);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Buffer_detach(void * buffer_addr,int * size);
#pragma weak MPI_Buffer_detach=PMPI_Buffer_detach
int (*INTERFACE_LOCAL_MPI_Buffer_detach)(void *,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Buffer_detach(void *,int *);
extern int INTERF_2_INTEL_CCMPI_Buffer_detach(void *,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Buffer_detach(void * buffer_addr,int * size)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Buffer_detach( buffer_addr, size);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Isend(void * buf,int count,MPI_Datatype datatype,int dest,int tag,MPI_Comm comm,MPI_Request * request);
#pragma weak MPI_Isend=PMPI_Isend
int (*INTERFACE_LOCAL_MPI_Isend)(void *,int,MPI_Datatype,int,int,MPI_Comm,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Isend(void *,int,MPI_Datatype,int,int,MPI_Comm,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Isend(void *,int,MPI_Datatype,int,int,MPI_Comm,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Isend(void * buf,int count,MPI_Datatype datatype,int dest,int tag,MPI_Comm comm,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Isend( buf, count, datatype, dest, tag, comm, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Ibsend(void * buf,int count,MPI_Datatype datatype,int dest,int tag,MPI_Comm comm,MPI_Request * request);
#pragma weak MPI_Ibsend=PMPI_Ibsend
int (*INTERFACE_LOCAL_MPI_Ibsend)(void *,int,MPI_Datatype,int,int,MPI_Comm,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Ibsend(void *,int,MPI_Datatype,int,int,MPI_Comm,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Ibsend(void *,int,MPI_Datatype,int,int,MPI_Comm,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Ibsend(void * buf,int count,MPI_Datatype datatype,int dest,int tag,MPI_Comm comm,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Ibsend( buf, count, datatype, dest, tag, comm, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Issend(void * buf,int count,MPI_Datatype datatype,int dest,int tag,MPI_Comm comm,MPI_Request * request);
#pragma weak MPI_Issend=PMPI_Issend
int (*INTERFACE_LOCAL_MPI_Issend)(void *,int,MPI_Datatype,int,int,MPI_Comm,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Issend(void *,int,MPI_Datatype,int,int,MPI_Comm,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Issend(void *,int,MPI_Datatype,int,int,MPI_Comm,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Issend(void * buf,int count,MPI_Datatype datatype,int dest,int tag,MPI_Comm comm,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Issend( buf, count, datatype, dest, tag, comm, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Irsend(void * buf,int count,MPI_Datatype datatype,int dest,int tag,MPI_Comm comm,MPI_Request * request);
#pragma weak MPI_Irsend=PMPI_Irsend
int (*INTERFACE_LOCAL_MPI_Irsend)(void *,int,MPI_Datatype,int,int,MPI_Comm,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Irsend(void *,int,MPI_Datatype,int,int,MPI_Comm,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Irsend(void *,int,MPI_Datatype,int,int,MPI_Comm,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Irsend(void * buf,int count,MPI_Datatype datatype,int dest,int tag,MPI_Comm comm,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Irsend( buf, count, datatype, dest, tag, comm, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Irecv(void * buf,int count,MPI_Datatype datatype,int source,int tag,MPI_Comm comm,MPI_Request * request);
#pragma weak MPI_Irecv=PMPI_Irecv
int (*INTERFACE_LOCAL_MPI_Irecv)(void *,int,MPI_Datatype,int,int,MPI_Comm,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Irecv(void *,int,MPI_Datatype,int,int,MPI_Comm,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Irecv(void *,int,MPI_Datatype,int,int,MPI_Comm,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Irecv(void * buf,int count,MPI_Datatype datatype,int source,int tag,MPI_Comm comm,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Irecv( buf, count, datatype, source, tag, comm, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Wait(MPI_Request * request,MPI_Status * status);
#pragma weak MPI_Wait=PMPI_Wait
int (*INTERFACE_LOCAL_MPI_Wait)(MPI_Request *,MPI_Status *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Wait(MPI_Request *,MPI_Status *);
extern int INTERF_2_INTEL_CCMPI_Wait(MPI_Request *,MPI_Status *);
#endif /*WI4MPI_STATIC*/

int PMPI_Wait(MPI_Request * request,MPI_Status * status)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Wait( request, status);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Test(MPI_Request * request,int * flag,MPI_Status * status);
#pragma weak MPI_Test=PMPI_Test
int (*INTERFACE_LOCAL_MPI_Test)(MPI_Request *,int *,MPI_Status *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Test(MPI_Request *,int *,MPI_Status *);
extern int INTERF_2_INTEL_CCMPI_Test(MPI_Request *,int *,MPI_Status *);
#endif /*WI4MPI_STATIC*/

int PMPI_Test(MPI_Request * request,int * flag,MPI_Status * status)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Test( request, flag, status);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Request_free(MPI_Request * request);
#pragma weak MPI_Request_free=PMPI_Request_free
int (*INTERFACE_LOCAL_MPI_Request_free)(MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Request_free(MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Request_free(MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Request_free(MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Request_free( request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Iprobe(int source,int tag,MPI_Comm comm,int * flag,MPI_Status * status);
#pragma weak MPI_Iprobe=PMPI_Iprobe
int (*INTERFACE_LOCAL_MPI_Iprobe)(int,int,MPI_Comm,int *,MPI_Status *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Iprobe(int,int,MPI_Comm,int *,MPI_Status *);
extern int INTERF_2_INTEL_CCMPI_Iprobe(int,int,MPI_Comm,int *,MPI_Status *);
#endif /*WI4MPI_STATIC*/

int PMPI_Iprobe(int source,int tag,MPI_Comm comm,int * flag,MPI_Status * status)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Iprobe( source, tag, comm, flag, status);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Probe(int source,int tag,MPI_Comm comm,MPI_Status * status);
#pragma weak MPI_Probe=PMPI_Probe
int (*INTERFACE_LOCAL_MPI_Probe)(int,int,MPI_Comm,MPI_Status *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Probe(int,int,MPI_Comm,MPI_Status *);
extern int INTERF_2_INTEL_CCMPI_Probe(int,int,MPI_Comm,MPI_Status *);
#endif /*WI4MPI_STATIC*/

int PMPI_Probe(int source,int tag,MPI_Comm comm,MPI_Status * status)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Probe( source, tag, comm, status);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Cancel(MPI_Request * request);
#pragma weak MPI_Cancel=PMPI_Cancel
int (*INTERFACE_LOCAL_MPI_Cancel)(MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Cancel(MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Cancel(MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Cancel(MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Cancel( request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Test_cancelled(MPI_Status * status,int * flag);
#pragma weak MPI_Test_cancelled=PMPI_Test_cancelled
int (*INTERFACE_LOCAL_MPI_Test_cancelled)(MPI_Status *,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Test_cancelled(MPI_Status *,int *);
extern int INTERF_2_INTEL_CCMPI_Test_cancelled(MPI_Status *,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Test_cancelled(MPI_Status * status,int * flag)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Test_cancelled( status, flag);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Send_init(void * buf,int count,MPI_Datatype datatype,int dest,int tag,MPI_Comm comm,MPI_Request * request);
#pragma weak MPI_Send_init=PMPI_Send_init
int (*INTERFACE_LOCAL_MPI_Send_init)(void *,int,MPI_Datatype,int,int,MPI_Comm,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Send_init(void *,int,MPI_Datatype,int,int,MPI_Comm,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Send_init(void *,int,MPI_Datatype,int,int,MPI_Comm,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Send_init(void * buf,int count,MPI_Datatype datatype,int dest,int tag,MPI_Comm comm,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Send_init( buf, count, datatype, dest, tag, comm, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Bsend_init(void * buf,int count,MPI_Datatype datatype,int dest,int tag,MPI_Comm comm,MPI_Request * request);
#pragma weak MPI_Bsend_init=PMPI_Bsend_init
int (*INTERFACE_LOCAL_MPI_Bsend_init)(void *,int,MPI_Datatype,int,int,MPI_Comm,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Bsend_init(void *,int,MPI_Datatype,int,int,MPI_Comm,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Bsend_init(void *,int,MPI_Datatype,int,int,MPI_Comm,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Bsend_init(void * buf,int count,MPI_Datatype datatype,int dest,int tag,MPI_Comm comm,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Bsend_init( buf, count, datatype, dest, tag, comm, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Ssend_init(void * buf,int count,MPI_Datatype datatype,int dest,int tag,MPI_Comm comm,MPI_Request * request);
#pragma weak MPI_Ssend_init=PMPI_Ssend_init
int (*INTERFACE_LOCAL_MPI_Ssend_init)(void *,int,MPI_Datatype,int,int,MPI_Comm,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Ssend_init(void *,int,MPI_Datatype,int,int,MPI_Comm,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Ssend_init(void *,int,MPI_Datatype,int,int,MPI_Comm,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Ssend_init(void * buf,int count,MPI_Datatype datatype,int dest,int tag,MPI_Comm comm,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Ssend_init( buf, count, datatype, dest, tag, comm, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Rsend_init(void * buf,int count,MPI_Datatype datatype,int dest,int tag,MPI_Comm comm,MPI_Request * request);
#pragma weak MPI_Rsend_init=PMPI_Rsend_init
int (*INTERFACE_LOCAL_MPI_Rsend_init)(void *,int,MPI_Datatype,int,int,MPI_Comm,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Rsend_init(void *,int,MPI_Datatype,int,int,MPI_Comm,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Rsend_init(void *,int,MPI_Datatype,int,int,MPI_Comm,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Rsend_init(void * buf,int count,MPI_Datatype datatype,int dest,int tag,MPI_Comm comm,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Rsend_init( buf, count, datatype, dest, tag, comm, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Recv_init(void * buf,int count,MPI_Datatype datatype,int source,int tag,MPI_Comm comm,MPI_Request * request);
#pragma weak MPI_Recv_init=PMPI_Recv_init
int (*INTERFACE_LOCAL_MPI_Recv_init)(void *,int,MPI_Datatype,int,int,MPI_Comm,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Recv_init(void *,int,MPI_Datatype,int,int,MPI_Comm,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Recv_init(void *,int,MPI_Datatype,int,int,MPI_Comm,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Recv_init(void * buf,int count,MPI_Datatype datatype,int source,int tag,MPI_Comm comm,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Recv_init( buf, count, datatype, source, tag, comm, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Start(MPI_Request * request);
#pragma weak MPI_Start=PMPI_Start
int (*INTERFACE_LOCAL_MPI_Start)(MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Start(MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Start(MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Start(MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Start( request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Sendrecv(void * sendbuf,int sendcount,MPI_Datatype sendtype,int dest,int sendtag,void * recvbuf,int recvcount,MPI_Datatype recvtype,int source,int recvtag,MPI_Comm comm,MPI_Status * status);
#pragma weak MPI_Sendrecv=PMPI_Sendrecv
int (*INTERFACE_LOCAL_MPI_Sendrecv)(void *,int,MPI_Datatype,int,int,void *,int,MPI_Datatype,int,int,MPI_Comm,MPI_Status *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Sendrecv(void *,int,MPI_Datatype,int,int,void *,int,MPI_Datatype,int,int,MPI_Comm,MPI_Status *);
extern int INTERF_2_INTEL_CCMPI_Sendrecv(void *,int,MPI_Datatype,int,int,void *,int,MPI_Datatype,int,int,MPI_Comm,MPI_Status *);
#endif /*WI4MPI_STATIC*/

int PMPI_Sendrecv(void * sendbuf,int sendcount,MPI_Datatype sendtype,int dest,int sendtag,void * recvbuf,int recvcount,MPI_Datatype recvtype,int source,int recvtag,MPI_Comm comm,MPI_Status * status)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Sendrecv( sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, recvtype, source, recvtag, comm, status);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Sendrecv_replace(void * buf,int count,MPI_Datatype datatype,int dest,int sendtag,int source,int recvtag,MPI_Comm comm,MPI_Status * status);
#pragma weak MPI_Sendrecv_replace=PMPI_Sendrecv_replace
int (*INTERFACE_LOCAL_MPI_Sendrecv_replace)(void *,int,MPI_Datatype,int,int,int,int,MPI_Comm,MPI_Status *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Sendrecv_replace(void *,int,MPI_Datatype,int,int,int,int,MPI_Comm,MPI_Status *);
extern int INTERF_2_INTEL_CCMPI_Sendrecv_replace(void *,int,MPI_Datatype,int,int,int,int,MPI_Comm,MPI_Status *);
#endif /*WI4MPI_STATIC*/

int PMPI_Sendrecv_replace(void * buf,int count,MPI_Datatype datatype,int dest,int sendtag,int source,int recvtag,MPI_Comm comm,MPI_Status * status)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Sendrecv_replace( buf, count, datatype, dest, sendtag, source, recvtag, comm, status);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Type_contiguous(int count,MPI_Datatype oldtype,MPI_Datatype * newtype);
#pragma weak MPI_Type_contiguous=PMPI_Type_contiguous
int (*INTERFACE_LOCAL_MPI_Type_contiguous)(int,MPI_Datatype,MPI_Datatype *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Type_contiguous(int,MPI_Datatype,MPI_Datatype *);
extern int INTERF_2_INTEL_CCMPI_Type_contiguous(int,MPI_Datatype,MPI_Datatype *);
#endif /*WI4MPI_STATIC*/

int PMPI_Type_contiguous(int count,MPI_Datatype oldtype,MPI_Datatype * newtype)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Type_contiguous( count, oldtype, newtype);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Type_vector(int count,int blocklength,int stride,MPI_Datatype oldtype,MPI_Datatype * newtype);
#pragma weak MPI_Type_vector=PMPI_Type_vector
int (*INTERFACE_LOCAL_MPI_Type_vector)(int,int,int,MPI_Datatype,MPI_Datatype *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Type_vector(int,int,int,MPI_Datatype,MPI_Datatype *);
extern int INTERF_2_INTEL_CCMPI_Type_vector(int,int,int,MPI_Datatype,MPI_Datatype *);
#endif /*WI4MPI_STATIC*/

int PMPI_Type_vector(int count,int blocklength,int stride,MPI_Datatype oldtype,MPI_Datatype * newtype)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Type_vector( count, blocklength, stride, oldtype, newtype);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Type_hvector(int count,int blocklength,MPI_Aint stride,MPI_Datatype oldtype,MPI_Datatype * newtype);
#pragma weak MPI_Type_hvector=PMPI_Type_hvector
int (*INTERFACE_LOCAL_MPI_Type_hvector)(int,int,MPI_Aint,MPI_Datatype,MPI_Datatype *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Type_hvector(int,int,MPI_Aint,MPI_Datatype,MPI_Datatype *);
extern int INTERF_2_INTEL_CCMPI_Type_hvector(int,int,MPI_Aint,MPI_Datatype,MPI_Datatype *);
#endif /*WI4MPI_STATIC*/

int PMPI_Type_hvector(int count,int blocklength,MPI_Aint stride,MPI_Datatype oldtype,MPI_Datatype * newtype)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Type_hvector( count, blocklength, stride, oldtype, newtype);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Type_indexed(int count,int * array_of_blocklengths,int * array_of_displacements,MPI_Datatype oldtype,MPI_Datatype * newtype);
#pragma weak MPI_Type_indexed=PMPI_Type_indexed
int (*INTERFACE_LOCAL_MPI_Type_indexed)(int,int *,int *,MPI_Datatype,MPI_Datatype *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Type_indexed(int,int *,int *,MPI_Datatype,MPI_Datatype *);
extern int INTERF_2_INTEL_CCMPI_Type_indexed(int,int *,int *,MPI_Datatype,MPI_Datatype *);
#endif /*WI4MPI_STATIC*/

int PMPI_Type_indexed(int count,int * array_of_blocklengths,int * array_of_displacements,MPI_Datatype oldtype,MPI_Datatype * newtype)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Type_indexed( count, array_of_blocklengths, array_of_displacements, oldtype, newtype);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Type_hindexed(int count,int * array_of_blocklengths,MPI_Aint * array_of_displacements,MPI_Datatype oldtype,MPI_Datatype * newtype);
#pragma weak MPI_Type_hindexed=PMPI_Type_hindexed
int (*INTERFACE_LOCAL_MPI_Type_hindexed)(int,int *,MPI_Aint *,MPI_Datatype,MPI_Datatype *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Type_hindexed(int,int *,MPI_Aint *,MPI_Datatype,MPI_Datatype *);
extern int INTERF_2_INTEL_CCMPI_Type_hindexed(int,int *,MPI_Aint *,MPI_Datatype,MPI_Datatype *);
#endif /*WI4MPI_STATIC*/

int PMPI_Type_hindexed(int count,int * array_of_blocklengths,MPI_Aint * array_of_displacements,MPI_Datatype oldtype,MPI_Datatype * newtype)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Type_hindexed( count, array_of_blocklengths, array_of_displacements, oldtype, newtype);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Type_struct(int count,int * array_of_blocklengths,MPI_Aint * array_of_displacements,MPI_Datatype array_of_types[],MPI_Datatype * newtype);
#pragma weak MPI_Type_struct=PMPI_Type_struct
int (*INTERFACE_LOCAL_MPI_Type_struct)(int,int *,MPI_Aint *,MPI_Datatype *,MPI_Datatype *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Type_struct(int,int *,MPI_Aint *,MPI_Datatype *,MPI_Datatype *);
extern int INTERF_2_INTEL_CCMPI_Type_struct(int,int *,MPI_Aint *,MPI_Datatype *,MPI_Datatype *);
#endif /*WI4MPI_STATIC*/

int PMPI_Type_struct(int count,int * array_of_blocklengths,MPI_Aint * array_of_displacements,MPI_Datatype array_of_types[],MPI_Datatype * newtype)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Type_struct( count, array_of_blocklengths, array_of_displacements, array_of_types, newtype);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Address(void * location,MPI_Aint * address);
#pragma weak MPI_Address=PMPI_Address
int (*INTERFACE_LOCAL_MPI_Address)(void *,MPI_Aint *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Address(void *,MPI_Aint *);
extern int INTERF_2_INTEL_CCMPI_Address(void *,MPI_Aint *);
#endif /*WI4MPI_STATIC*/

int PMPI_Address(void * location,MPI_Aint * address)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Address( location, address);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Type_extent(MPI_Datatype datatype,MPI_Aint * extent);
#pragma weak MPI_Type_extent=PMPI_Type_extent
int (*INTERFACE_LOCAL_MPI_Type_extent)(MPI_Datatype,MPI_Aint *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Type_extent(MPI_Datatype,MPI_Aint *);
extern int INTERF_2_INTEL_CCMPI_Type_extent(MPI_Datatype,MPI_Aint *);
#endif /*WI4MPI_STATIC*/

int PMPI_Type_extent(MPI_Datatype datatype,MPI_Aint * extent)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Type_extent( datatype, extent);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Type_size(MPI_Datatype datatype,int * size);
#pragma weak MPI_Type_size=PMPI_Type_size
int (*INTERFACE_LOCAL_MPI_Type_size)(MPI_Datatype,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Type_size(MPI_Datatype,int *);
extern int INTERF_2_INTEL_CCMPI_Type_size(MPI_Datatype,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Type_size(MPI_Datatype datatype,int * size)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Type_size( datatype, size);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Type_lb(MPI_Datatype datatype,MPI_Aint * displacement);
#pragma weak MPI_Type_lb=PMPI_Type_lb
int (*INTERFACE_LOCAL_MPI_Type_lb)(MPI_Datatype,MPI_Aint *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Type_lb(MPI_Datatype,MPI_Aint *);
extern int INTERF_2_INTEL_CCMPI_Type_lb(MPI_Datatype,MPI_Aint *);
#endif /*WI4MPI_STATIC*/

int PMPI_Type_lb(MPI_Datatype datatype,MPI_Aint * displacement)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Type_lb( datatype, displacement);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Type_ub(MPI_Datatype datatype,MPI_Aint * displacement);
#pragma weak MPI_Type_ub=PMPI_Type_ub
int (*INTERFACE_LOCAL_MPI_Type_ub)(MPI_Datatype,MPI_Aint *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Type_ub(MPI_Datatype,MPI_Aint *);
extern int INTERF_2_INTEL_CCMPI_Type_ub(MPI_Datatype,MPI_Aint *);
#endif /*WI4MPI_STATIC*/

int PMPI_Type_ub(MPI_Datatype datatype,MPI_Aint * displacement)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Type_ub( datatype, displacement);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Type_commit(MPI_Datatype * datatype);
#pragma weak MPI_Type_commit=PMPI_Type_commit
int (*INTERFACE_LOCAL_MPI_Type_commit)(MPI_Datatype *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Type_commit(MPI_Datatype *);
extern int INTERF_2_INTEL_CCMPI_Type_commit(MPI_Datatype *);
#endif /*WI4MPI_STATIC*/

int PMPI_Type_commit(MPI_Datatype * datatype)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Type_commit( datatype);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Type_free(MPI_Datatype * datatype);
#pragma weak MPI_Type_free=PMPI_Type_free
int (*INTERFACE_LOCAL_MPI_Type_free)(MPI_Datatype *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Type_free(MPI_Datatype *);
extern int INTERF_2_INTEL_CCMPI_Type_free(MPI_Datatype *);
#endif /*WI4MPI_STATIC*/

int PMPI_Type_free(MPI_Datatype * datatype)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Type_free( datatype);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Get_elements(MPI_Status * status,MPI_Datatype datatype,int * count);
#pragma weak MPI_Get_elements=PMPI_Get_elements
int (*INTERFACE_LOCAL_MPI_Get_elements)(MPI_Status *,MPI_Datatype,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Get_elements(MPI_Status *,MPI_Datatype,int *);
extern int INTERF_2_INTEL_CCMPI_Get_elements(MPI_Status *,MPI_Datatype,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Get_elements(MPI_Status * status,MPI_Datatype datatype,int * count)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Get_elements( status, datatype, count);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Pack(void * inbuf,int incount,MPI_Datatype datatype,void * outbuf,int outsize,int * position,MPI_Comm comm);
#pragma weak MPI_Pack=PMPI_Pack
int (*INTERFACE_LOCAL_MPI_Pack)(void *,int,MPI_Datatype,void *,int,int *,MPI_Comm);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Pack(void *,int,MPI_Datatype,void *,int,int *,MPI_Comm);
extern int INTERF_2_INTEL_CCMPI_Pack(void *,int,MPI_Datatype,void *,int,int *,MPI_Comm);
#endif /*WI4MPI_STATIC*/

int PMPI_Pack(void * inbuf,int incount,MPI_Datatype datatype,void * outbuf,int outsize,int * position,MPI_Comm comm)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Pack( inbuf, incount, datatype, outbuf, outsize, position, comm);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Unpack(void * inbuf,int insize,int * position,void * outbuf,int outcount,MPI_Datatype datatype,MPI_Comm comm);
#pragma weak MPI_Unpack=PMPI_Unpack
int (*INTERFACE_LOCAL_MPI_Unpack)(void *,int,int *,void *,int,MPI_Datatype,MPI_Comm);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Unpack(void *,int,int *,void *,int,MPI_Datatype,MPI_Comm);
extern int INTERF_2_INTEL_CCMPI_Unpack(void *,int,int *,void *,int,MPI_Datatype,MPI_Comm);
#endif /*WI4MPI_STATIC*/

int PMPI_Unpack(void * inbuf,int insize,int * position,void * outbuf,int outcount,MPI_Datatype datatype,MPI_Comm comm)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Unpack( inbuf, insize, position, outbuf, outcount, datatype, comm);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Pack_size(int incount,MPI_Datatype datatype,MPI_Comm comm,int * size);
#pragma weak MPI_Pack_size=PMPI_Pack_size
int (*INTERFACE_LOCAL_MPI_Pack_size)(int,MPI_Datatype,MPI_Comm,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Pack_size(int,MPI_Datatype,MPI_Comm,int *);
extern int INTERF_2_INTEL_CCMPI_Pack_size(int,MPI_Datatype,MPI_Comm,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Pack_size(int incount,MPI_Datatype datatype,MPI_Comm comm,int * size)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Pack_size( incount, datatype, comm, size);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Barrier(MPI_Comm comm);
#pragma weak MPI_Barrier=PMPI_Barrier
int (*INTERFACE_LOCAL_MPI_Barrier)(MPI_Comm);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Barrier(MPI_Comm);
extern int INTERF_2_INTEL_CCMPI_Barrier(MPI_Comm);
#endif /*WI4MPI_STATIC*/

int PMPI_Barrier(MPI_Comm comm)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Barrier( comm);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Bcast(void * buffer,int count,MPI_Datatype datatype,int root,MPI_Comm comm);
#pragma weak MPI_Bcast=PMPI_Bcast
int (*INTERFACE_LOCAL_MPI_Bcast)(void *,int,MPI_Datatype,int,MPI_Comm);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Bcast(void *,int,MPI_Datatype,int,MPI_Comm);
extern int INTERF_2_INTEL_CCMPI_Bcast(void *,int,MPI_Datatype,int,MPI_Comm);
#endif /*WI4MPI_STATIC*/

int PMPI_Bcast(void * buffer,int count,MPI_Datatype datatype,int root,MPI_Comm comm)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Bcast( buffer, count, datatype, root, comm);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Gather(void * sendbuf,int sendcount,MPI_Datatype sendtype,void * recvbuf,int recvcount,MPI_Datatype recvtype,int root,MPI_Comm comm);
#pragma weak MPI_Gather=PMPI_Gather
int (*INTERFACE_LOCAL_MPI_Gather)(void *,int,MPI_Datatype,void *,int,MPI_Datatype,int,MPI_Comm);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Gather(void *,int,MPI_Datatype,void *,int,MPI_Datatype,int,MPI_Comm);
extern int INTERF_2_INTEL_CCMPI_Gather(void *,int,MPI_Datatype,void *,int,MPI_Datatype,int,MPI_Comm);
#endif /*WI4MPI_STATIC*/

int PMPI_Gather(void * sendbuf,int sendcount,MPI_Datatype sendtype,void * recvbuf,int recvcount,MPI_Datatype recvtype,int root,MPI_Comm comm)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Gather( sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Gatherv(void * sendbuf,int sendcount,MPI_Datatype sendtype,void * recvbuf,int * recvcounts,int * displs,MPI_Datatype recvtype,int root,MPI_Comm comm);
#pragma weak MPI_Gatherv=PMPI_Gatherv
int (*INTERFACE_LOCAL_MPI_Gatherv)(void *,int,MPI_Datatype,void *,int *,int *,MPI_Datatype,int,MPI_Comm);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Gatherv(void *,int,MPI_Datatype,void *,int *,int *,MPI_Datatype,int,MPI_Comm);
extern int INTERF_2_INTEL_CCMPI_Gatherv(void *,int,MPI_Datatype,void *,int *,int *,MPI_Datatype,int,MPI_Comm);
#endif /*WI4MPI_STATIC*/

int PMPI_Gatherv(void * sendbuf,int sendcount,MPI_Datatype sendtype,void * recvbuf,int * recvcounts,int * displs,MPI_Datatype recvtype,int root,MPI_Comm comm)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Gatherv( sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Scatter(void * sendbuf,int sendcount,MPI_Datatype sendtype,void * recvbuf,int recvcount,MPI_Datatype recvtype,int root,MPI_Comm comm);
#pragma weak MPI_Scatter=PMPI_Scatter
int (*INTERFACE_LOCAL_MPI_Scatter)(void *,int,MPI_Datatype,void *,int,MPI_Datatype,int,MPI_Comm);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Scatter(void *,int,MPI_Datatype,void *,int,MPI_Datatype,int,MPI_Comm);
extern int INTERF_2_INTEL_CCMPI_Scatter(void *,int,MPI_Datatype,void *,int,MPI_Datatype,int,MPI_Comm);
#endif /*WI4MPI_STATIC*/

int PMPI_Scatter(void * sendbuf,int sendcount,MPI_Datatype sendtype,void * recvbuf,int recvcount,MPI_Datatype recvtype,int root,MPI_Comm comm)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Scatter( sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Scatterv(void * sendbuf,int * sendcounts,int * displs,MPI_Datatype sendtype,void * recvbuf,int recvcount,MPI_Datatype recvtype,int root,MPI_Comm comm);
#pragma weak MPI_Scatterv=PMPI_Scatterv
int (*INTERFACE_LOCAL_MPI_Scatterv)(void *,int *,int *,MPI_Datatype,void *,int,MPI_Datatype,int,MPI_Comm);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Scatterv(void *,int *,int *,MPI_Datatype,void *,int,MPI_Datatype,int,MPI_Comm);
extern int INTERF_2_INTEL_CCMPI_Scatterv(void *,int *,int *,MPI_Datatype,void *,int,MPI_Datatype,int,MPI_Comm);
#endif /*WI4MPI_STATIC*/

int PMPI_Scatterv(void * sendbuf,int * sendcounts,int * displs,MPI_Datatype sendtype,void * recvbuf,int recvcount,MPI_Datatype recvtype,int root,MPI_Comm comm)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Scatterv( sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Allgather(void * sendbuf,int sendcount,MPI_Datatype sendtype,void * recvbuf,int recvcount,MPI_Datatype recvtype,MPI_Comm comm);
#pragma weak MPI_Allgather=PMPI_Allgather
int (*INTERFACE_LOCAL_MPI_Allgather)(void *,int,MPI_Datatype,void *,int,MPI_Datatype,MPI_Comm);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Allgather(void *,int,MPI_Datatype,void *,int,MPI_Datatype,MPI_Comm);
extern int INTERF_2_INTEL_CCMPI_Allgather(void *,int,MPI_Datatype,void *,int,MPI_Datatype,MPI_Comm);
#endif /*WI4MPI_STATIC*/

int PMPI_Allgather(void * sendbuf,int sendcount,MPI_Datatype sendtype,void * recvbuf,int recvcount,MPI_Datatype recvtype,MPI_Comm comm)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Allgather( sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Allgatherv(void * sendbuf,int sendcount,MPI_Datatype sendtype,void * recvbuf,int * recvcounts,int * displs,MPI_Datatype recvtype,MPI_Comm comm);
#pragma weak MPI_Allgatherv=PMPI_Allgatherv
int (*INTERFACE_LOCAL_MPI_Allgatherv)(void *,int,MPI_Datatype,void *,int *,int *,MPI_Datatype,MPI_Comm);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Allgatherv(void *,int,MPI_Datatype,void *,int *,int *,MPI_Datatype,MPI_Comm);
extern int INTERF_2_INTEL_CCMPI_Allgatherv(void *,int,MPI_Datatype,void *,int *,int *,MPI_Datatype,MPI_Comm);
#endif /*WI4MPI_STATIC*/

int PMPI_Allgatherv(void * sendbuf,int sendcount,MPI_Datatype sendtype,void * recvbuf,int * recvcounts,int * displs,MPI_Datatype recvtype,MPI_Comm comm)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Allgatherv( sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Alltoall(void * sendbuf,int sendcount,MPI_Datatype sendtype,void * recvbuf,int recvcount,MPI_Datatype recvtype,MPI_Comm comm);
#pragma weak MPI_Alltoall=PMPI_Alltoall
int (*INTERFACE_LOCAL_MPI_Alltoall)(void *,int,MPI_Datatype,void *,int,MPI_Datatype,MPI_Comm);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Alltoall(void *,int,MPI_Datatype,void *,int,MPI_Datatype,MPI_Comm);
extern int INTERF_2_INTEL_CCMPI_Alltoall(void *,int,MPI_Datatype,void *,int,MPI_Datatype,MPI_Comm);
#endif /*WI4MPI_STATIC*/

int PMPI_Alltoall(void * sendbuf,int sendcount,MPI_Datatype sendtype,void * recvbuf,int recvcount,MPI_Datatype recvtype,MPI_Comm comm)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Alltoall( sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Alltoallv(void * sendbuf,int * sendcounts,int * sdispls,MPI_Datatype sendtype,void * recvbuf,int * recvcounts,int * rdispls,MPI_Datatype recvtype,MPI_Comm comm);
#pragma weak MPI_Alltoallv=PMPI_Alltoallv
int (*INTERFACE_LOCAL_MPI_Alltoallv)(void *,int *,int *,MPI_Datatype,void *,int *,int *,MPI_Datatype,MPI_Comm);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Alltoallv(void *,int *,int *,MPI_Datatype,void *,int *,int *,MPI_Datatype,MPI_Comm);
extern int INTERF_2_INTEL_CCMPI_Alltoallv(void *,int *,int *,MPI_Datatype,void *,int *,int *,MPI_Datatype,MPI_Comm);
#endif /*WI4MPI_STATIC*/

int PMPI_Alltoallv(void * sendbuf,int * sendcounts,int * sdispls,MPI_Datatype sendtype,void * recvbuf,int * recvcounts,int * rdispls,MPI_Datatype recvtype,MPI_Comm comm)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Alltoallv( sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Exscan(void * sendbuf,void * recvbuf,int count,MPI_Datatype datatype,MPI_Op op,MPI_Comm comm);
#pragma weak MPI_Exscan=PMPI_Exscan
int (*INTERFACE_LOCAL_MPI_Exscan)(void *,void *,int,MPI_Datatype,MPI_Op,MPI_Comm);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Exscan(void *,void *,int,MPI_Datatype,MPI_Op,MPI_Comm);
extern int INTERF_2_INTEL_CCMPI_Exscan(void *,void *,int,MPI_Datatype,MPI_Op,MPI_Comm);
#endif /*WI4MPI_STATIC*/

int PMPI_Exscan(void * sendbuf,void * recvbuf,int count,MPI_Datatype datatype,MPI_Op op,MPI_Comm comm)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Exscan( sendbuf, recvbuf, count, datatype, op, comm);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Reduce(void * sendbuf,void * recvbuf,int count,MPI_Datatype datatype,MPI_Op op,int root,MPI_Comm comm);
#pragma weak MPI_Reduce=PMPI_Reduce
int (*INTERFACE_LOCAL_MPI_Reduce)(void *,void *,int,MPI_Datatype,MPI_Op,int,MPI_Comm);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Reduce(void *,void *,int,MPI_Datatype,MPI_Op,int,MPI_Comm);
extern int INTERF_2_INTEL_CCMPI_Reduce(void *,void *,int,MPI_Datatype,MPI_Op,int,MPI_Comm);
#endif /*WI4MPI_STATIC*/

int PMPI_Reduce(void * sendbuf,void * recvbuf,int count,MPI_Datatype datatype,MPI_Op op,int root,MPI_Comm comm)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Reduce( sendbuf, recvbuf, count, datatype, op, root, comm);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Op_create(MPI_User_function * user_fn,int commute,MPI_Op * op);
#pragma weak MPI_Op_create=PMPI_Op_create
int (*INTERFACE_LOCAL_MPI_Op_create)(MPI_User_function *,int,MPI_Op *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Op_create(MPI_User_function *,int,MPI_Op *);
extern int INTERF_2_INTEL_CCMPI_Op_create(MPI_User_function *,int,MPI_Op *);
#endif /*WI4MPI_STATIC*/

int PMPI_Op_create(MPI_User_function * user_fn,int commute,MPI_Op * op)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Op_create( user_fn, commute, op);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Op_free(MPI_Op * op);
#pragma weak MPI_Op_free=PMPI_Op_free
int (*INTERFACE_LOCAL_MPI_Op_free)(MPI_Op *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Op_free(MPI_Op *);
extern int INTERF_2_INTEL_CCMPI_Op_free(MPI_Op *);
#endif /*WI4MPI_STATIC*/

int PMPI_Op_free(MPI_Op * op)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Op_free( op);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Allreduce(void * sendbuf,void * recvbuf,int count,MPI_Datatype datatype,MPI_Op op,MPI_Comm comm);
#pragma weak MPI_Allreduce=PMPI_Allreduce
int (*INTERFACE_LOCAL_MPI_Allreduce)(void *,void *,int,MPI_Datatype,MPI_Op,MPI_Comm);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Allreduce(void *,void *,int,MPI_Datatype,MPI_Op,MPI_Comm);
extern int INTERF_2_INTEL_CCMPI_Allreduce(void *,void *,int,MPI_Datatype,MPI_Op,MPI_Comm);
#endif /*WI4MPI_STATIC*/

int PMPI_Allreduce(void * sendbuf,void * recvbuf,int count,MPI_Datatype datatype,MPI_Op op,MPI_Comm comm)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Allreduce( sendbuf, recvbuf, count, datatype, op, comm);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Scan(void * sendbuf,void * recvbuf,int count,MPI_Datatype datatype,MPI_Op op,MPI_Comm comm);
#pragma weak MPI_Scan=PMPI_Scan
int (*INTERFACE_LOCAL_MPI_Scan)(void *,void *,int,MPI_Datatype,MPI_Op,MPI_Comm);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Scan(void *,void *,int,MPI_Datatype,MPI_Op,MPI_Comm);
extern int INTERF_2_INTEL_CCMPI_Scan(void *,void *,int,MPI_Datatype,MPI_Op,MPI_Comm);
#endif /*WI4MPI_STATIC*/

int PMPI_Scan(void * sendbuf,void * recvbuf,int count,MPI_Datatype datatype,MPI_Op op,MPI_Comm comm)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Scan( sendbuf, recvbuf, count, datatype, op, comm);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Group_size(MPI_Group group,int * size);
#pragma weak MPI_Group_size=PMPI_Group_size
int (*INTERFACE_LOCAL_MPI_Group_size)(MPI_Group,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Group_size(MPI_Group,int *);
extern int INTERF_2_INTEL_CCMPI_Group_size(MPI_Group,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Group_size(MPI_Group group,int * size)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Group_size( group, size);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Group_rank(MPI_Group group,int * rank);
#pragma weak MPI_Group_rank=PMPI_Group_rank
int (*INTERFACE_LOCAL_MPI_Group_rank)(MPI_Group,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Group_rank(MPI_Group,int *);
extern int INTERF_2_INTEL_CCMPI_Group_rank(MPI_Group,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Group_rank(MPI_Group group,int * rank)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Group_rank( group, rank);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Group_compare(MPI_Group group1,MPI_Group group2,int * result);
#pragma weak MPI_Group_compare=PMPI_Group_compare
int (*INTERFACE_LOCAL_MPI_Group_compare)(MPI_Group,MPI_Group,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Group_compare(MPI_Group,MPI_Group,int *);
extern int INTERF_2_INTEL_CCMPI_Group_compare(MPI_Group,MPI_Group,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Group_compare(MPI_Group group1,MPI_Group group2,int * result)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Group_compare( group1, group2, result);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Comm_group(MPI_Comm comm,MPI_Group * group);
#pragma weak MPI_Comm_group=PMPI_Comm_group
int (*INTERFACE_LOCAL_MPI_Comm_group)(MPI_Comm,MPI_Group *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Comm_group(MPI_Comm,MPI_Group *);
extern int INTERF_2_INTEL_CCMPI_Comm_group(MPI_Comm,MPI_Group *);
#endif /*WI4MPI_STATIC*/

int PMPI_Comm_group(MPI_Comm comm,MPI_Group * group)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Comm_group( comm, group);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Group_union(MPI_Group group1,MPI_Group group2,MPI_Group * newgroup);
#pragma weak MPI_Group_union=PMPI_Group_union
int (*INTERFACE_LOCAL_MPI_Group_union)(MPI_Group,MPI_Group,MPI_Group *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Group_union(MPI_Group,MPI_Group,MPI_Group *);
extern int INTERF_2_INTEL_CCMPI_Group_union(MPI_Group,MPI_Group,MPI_Group *);
#endif /*WI4MPI_STATIC*/

int PMPI_Group_union(MPI_Group group1,MPI_Group group2,MPI_Group * newgroup)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Group_union( group1, group2, newgroup);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Group_intersection(MPI_Group group1,MPI_Group group2,MPI_Group * newgroup);
#pragma weak MPI_Group_intersection=PMPI_Group_intersection
int (*INTERFACE_LOCAL_MPI_Group_intersection)(MPI_Group,MPI_Group,MPI_Group *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Group_intersection(MPI_Group,MPI_Group,MPI_Group *);
extern int INTERF_2_INTEL_CCMPI_Group_intersection(MPI_Group,MPI_Group,MPI_Group *);
#endif /*WI4MPI_STATIC*/

int PMPI_Group_intersection(MPI_Group group1,MPI_Group group2,MPI_Group * newgroup)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Group_intersection( group1, group2, newgroup);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Group_difference(MPI_Group group1,MPI_Group group2,MPI_Group * newgroup);
#pragma weak MPI_Group_difference=PMPI_Group_difference
int (*INTERFACE_LOCAL_MPI_Group_difference)(MPI_Group,MPI_Group,MPI_Group *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Group_difference(MPI_Group,MPI_Group,MPI_Group *);
extern int INTERF_2_INTEL_CCMPI_Group_difference(MPI_Group,MPI_Group,MPI_Group *);
#endif /*WI4MPI_STATIC*/

int PMPI_Group_difference(MPI_Group group1,MPI_Group group2,MPI_Group * newgroup)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Group_difference( group1, group2, newgroup);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Group_free(MPI_Group * group);
#pragma weak MPI_Group_free=PMPI_Group_free
int (*INTERFACE_LOCAL_MPI_Group_free)(MPI_Group *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Group_free(MPI_Group *);
extern int INTERF_2_INTEL_CCMPI_Group_free(MPI_Group *);
#endif /*WI4MPI_STATIC*/

int PMPI_Group_free(MPI_Group * group)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Group_free( group);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Comm_size(MPI_Comm comm,int * size);
#pragma weak MPI_Comm_size=PMPI_Comm_size
int (*INTERFACE_LOCAL_MPI_Comm_size)(MPI_Comm,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Comm_size(MPI_Comm,int *);
extern int INTERF_2_INTEL_CCMPI_Comm_size(MPI_Comm,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Comm_size(MPI_Comm comm,int * size)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Comm_size( comm, size);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Comm_rank(MPI_Comm comm,int * rank);
#pragma weak MPI_Comm_rank=PMPI_Comm_rank
int (*INTERFACE_LOCAL_MPI_Comm_rank)(MPI_Comm,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Comm_rank(MPI_Comm,int *);
extern int INTERF_2_INTEL_CCMPI_Comm_rank(MPI_Comm,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Comm_rank(MPI_Comm comm,int * rank)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Comm_rank( comm, rank);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Comm_compare(MPI_Comm comm1,MPI_Comm comm2,int * result);
#pragma weak MPI_Comm_compare=PMPI_Comm_compare
int (*INTERFACE_LOCAL_MPI_Comm_compare)(MPI_Comm,MPI_Comm,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Comm_compare(MPI_Comm,MPI_Comm,int *);
extern int INTERF_2_INTEL_CCMPI_Comm_compare(MPI_Comm,MPI_Comm,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Comm_compare(MPI_Comm comm1,MPI_Comm comm2,int * result)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Comm_compare( comm1, comm2, result);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Comm_dup(MPI_Comm comm,MPI_Comm * newcomm);
#pragma weak MPI_Comm_dup=PMPI_Comm_dup
int (*INTERFACE_LOCAL_MPI_Comm_dup)(MPI_Comm,MPI_Comm *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Comm_dup(MPI_Comm,MPI_Comm *);
extern int INTERF_2_INTEL_CCMPI_Comm_dup(MPI_Comm,MPI_Comm *);
#endif /*WI4MPI_STATIC*/

int PMPI_Comm_dup(MPI_Comm comm,MPI_Comm * newcomm)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Comm_dup( comm, newcomm);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Comm_dup_with_info(MPI_Comm comm,MPI_Info info,MPI_Comm * newcomm);
#pragma weak MPI_Comm_dup_with_info=PMPI_Comm_dup_with_info
int (*INTERFACE_LOCAL_MPI_Comm_dup_with_info)(MPI_Comm,MPI_Info,MPI_Comm *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Comm_dup_with_info(MPI_Comm,MPI_Info,MPI_Comm *);
extern int INTERF_2_INTEL_CCMPI_Comm_dup_with_info(MPI_Comm,MPI_Info,MPI_Comm *);
#endif /*WI4MPI_STATIC*/

int PMPI_Comm_dup_with_info(MPI_Comm comm,MPI_Info info,MPI_Comm * newcomm)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Comm_dup_with_info( comm, info, newcomm);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Comm_create(MPI_Comm comm,MPI_Group group,MPI_Comm * newcomm);
#pragma weak MPI_Comm_create=PMPI_Comm_create
int (*INTERFACE_LOCAL_MPI_Comm_create)(MPI_Comm,MPI_Group,MPI_Comm *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Comm_create(MPI_Comm,MPI_Group,MPI_Comm *);
extern int INTERF_2_INTEL_CCMPI_Comm_create(MPI_Comm,MPI_Group,MPI_Comm *);
#endif /*WI4MPI_STATIC*/

int PMPI_Comm_create(MPI_Comm comm,MPI_Group group,MPI_Comm * newcomm)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Comm_create( comm, group, newcomm);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Comm_split(MPI_Comm comm,int color,int key,MPI_Comm * newcomm);
#pragma weak MPI_Comm_split=PMPI_Comm_split
int (*INTERFACE_LOCAL_MPI_Comm_split)(MPI_Comm,int,int,MPI_Comm *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Comm_split(MPI_Comm,int,int,MPI_Comm *);
extern int INTERF_2_INTEL_CCMPI_Comm_split(MPI_Comm,int,int,MPI_Comm *);
#endif /*WI4MPI_STATIC*/

int PMPI_Comm_split(MPI_Comm comm,int color,int key,MPI_Comm * newcomm)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Comm_split( comm, color, key, newcomm);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Comm_free(MPI_Comm * comm);
#pragma weak MPI_Comm_free=PMPI_Comm_free
int (*INTERFACE_LOCAL_MPI_Comm_free)(MPI_Comm *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Comm_free(MPI_Comm *);
extern int INTERF_2_INTEL_CCMPI_Comm_free(MPI_Comm *);
#endif /*WI4MPI_STATIC*/

int PMPI_Comm_free(MPI_Comm * comm)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Comm_free( comm);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Comm_test_inter(MPI_Comm comm,int * flag);
#pragma weak MPI_Comm_test_inter=PMPI_Comm_test_inter
int (*INTERFACE_LOCAL_MPI_Comm_test_inter)(MPI_Comm,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Comm_test_inter(MPI_Comm,int *);
extern int INTERF_2_INTEL_CCMPI_Comm_test_inter(MPI_Comm,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Comm_test_inter(MPI_Comm comm,int * flag)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Comm_test_inter( comm, flag);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Comm_remote_size(MPI_Comm comm,int * size);
#pragma weak MPI_Comm_remote_size=PMPI_Comm_remote_size
int (*INTERFACE_LOCAL_MPI_Comm_remote_size)(MPI_Comm,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Comm_remote_size(MPI_Comm,int *);
extern int INTERF_2_INTEL_CCMPI_Comm_remote_size(MPI_Comm,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Comm_remote_size(MPI_Comm comm,int * size)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Comm_remote_size( comm, size);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Comm_remote_group(MPI_Comm comm,MPI_Group * group);
#pragma weak MPI_Comm_remote_group=PMPI_Comm_remote_group
int (*INTERFACE_LOCAL_MPI_Comm_remote_group)(MPI_Comm,MPI_Group *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Comm_remote_group(MPI_Comm,MPI_Group *);
extern int INTERF_2_INTEL_CCMPI_Comm_remote_group(MPI_Comm,MPI_Group *);
#endif /*WI4MPI_STATIC*/

int PMPI_Comm_remote_group(MPI_Comm comm,MPI_Group * group)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Comm_remote_group( comm, group);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Intercomm_create(MPI_Comm local_comm,int local_leader,MPI_Comm peer_comm,int remote_leader,int tag,MPI_Comm * newintercomm);
#pragma weak MPI_Intercomm_create=PMPI_Intercomm_create
int (*INTERFACE_LOCAL_MPI_Intercomm_create)(MPI_Comm,int,MPI_Comm,int,int,MPI_Comm *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Intercomm_create(MPI_Comm,int,MPI_Comm,int,int,MPI_Comm *);
extern int INTERF_2_INTEL_CCMPI_Intercomm_create(MPI_Comm,int,MPI_Comm,int,int,MPI_Comm *);
#endif /*WI4MPI_STATIC*/

int PMPI_Intercomm_create(MPI_Comm local_comm,int local_leader,MPI_Comm peer_comm,int remote_leader,int tag,MPI_Comm * newintercomm)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Intercomm_create( local_comm, local_leader, peer_comm, remote_leader, tag, newintercomm);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Intercomm_merge(MPI_Comm intercomm,int high,MPI_Comm * newintracomm);
#pragma weak MPI_Intercomm_merge=PMPI_Intercomm_merge
int (*INTERFACE_LOCAL_MPI_Intercomm_merge)(MPI_Comm,int,MPI_Comm *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Intercomm_merge(MPI_Comm,int,MPI_Comm *);
extern int INTERF_2_INTEL_CCMPI_Intercomm_merge(MPI_Comm,int,MPI_Comm *);
#endif /*WI4MPI_STATIC*/

int PMPI_Intercomm_merge(MPI_Comm intercomm,int high,MPI_Comm * newintracomm)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Intercomm_merge( intercomm, high, newintracomm);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Attr_put(MPI_Comm comm,int keyval,void * attribute_val);
#pragma weak MPI_Attr_put=PMPI_Attr_put
int (*INTERFACE_LOCAL_MPI_Attr_put)(MPI_Comm,int,void *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Attr_put(MPI_Comm,int,void *);
extern int INTERF_2_INTEL_CCMPI_Attr_put(MPI_Comm,int,void *);
#endif /*WI4MPI_STATIC*/

int PMPI_Attr_put(MPI_Comm comm,int keyval,void * attribute_val)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Attr_put( comm, keyval, attribute_val);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Attr_get(MPI_Comm comm,int keyval,void * attribute_val,int * flag);
#pragma weak MPI_Attr_get=PMPI_Attr_get
int (*INTERFACE_LOCAL_MPI_Attr_get)(MPI_Comm,int,void *,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Attr_get(MPI_Comm,int,void *,int *);
extern int INTERF_2_INTEL_CCMPI_Attr_get(MPI_Comm,int,void *,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Attr_get(MPI_Comm comm,int keyval,void * attribute_val,int * flag)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Attr_get( comm, keyval, attribute_val, flag);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Attr_delete(MPI_Comm comm,int keyval);
#pragma weak MPI_Attr_delete=PMPI_Attr_delete
int (*INTERFACE_LOCAL_MPI_Attr_delete)(MPI_Comm,int);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Attr_delete(MPI_Comm,int);
extern int INTERF_2_INTEL_CCMPI_Attr_delete(MPI_Comm,int);
#endif /*WI4MPI_STATIC*/

int PMPI_Attr_delete(MPI_Comm comm,int keyval)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Attr_delete( comm, keyval);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Topo_test(MPI_Comm comm,int * status);
#pragma weak MPI_Topo_test=PMPI_Topo_test
int (*INTERFACE_LOCAL_MPI_Topo_test)(MPI_Comm,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Topo_test(MPI_Comm,int *);
extern int INTERF_2_INTEL_CCMPI_Topo_test(MPI_Comm,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Topo_test(MPI_Comm comm,int * status)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Topo_test( comm, status);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Graphdims_get(MPI_Comm comm,int * nnodes,int * nedges);
#pragma weak MPI_Graphdims_get=PMPI_Graphdims_get
int (*INTERFACE_LOCAL_MPI_Graphdims_get)(MPI_Comm,int *,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Graphdims_get(MPI_Comm,int *,int *);
extern int INTERF_2_INTEL_CCMPI_Graphdims_get(MPI_Comm,int *,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Graphdims_get(MPI_Comm comm,int * nnodes,int * nedges)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Graphdims_get( comm, nnodes, nedges);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Cartdim_get(MPI_Comm comm,int * ndims);
#pragma weak MPI_Cartdim_get=PMPI_Cartdim_get
int (*INTERFACE_LOCAL_MPI_Cartdim_get)(MPI_Comm,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Cartdim_get(MPI_Comm,int *);
extern int INTERF_2_INTEL_CCMPI_Cartdim_get(MPI_Comm,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Cartdim_get(MPI_Comm comm,int * ndims)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Cartdim_get( comm, ndims);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Graph_neighbors_count(MPI_Comm comm,int rank,int * nneighbors);
#pragma weak MPI_Graph_neighbors_count=PMPI_Graph_neighbors_count
int (*INTERFACE_LOCAL_MPI_Graph_neighbors_count)(MPI_Comm,int,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Graph_neighbors_count(MPI_Comm,int,int *);
extern int INTERF_2_INTEL_CCMPI_Graph_neighbors_count(MPI_Comm,int,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Graph_neighbors_count(MPI_Comm comm,int rank,int * nneighbors)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Graph_neighbors_count( comm, rank, nneighbors);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Cart_shift(MPI_Comm comm,int direction,int disp,int * rank_source,int * rank_dest);
#pragma weak MPI_Cart_shift=PMPI_Cart_shift
int (*INTERFACE_LOCAL_MPI_Cart_shift)(MPI_Comm,int,int,int *,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Cart_shift(MPI_Comm,int,int,int *,int *);
extern int INTERF_2_INTEL_CCMPI_Cart_shift(MPI_Comm,int,int,int *,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Cart_shift(MPI_Comm comm,int direction,int disp,int * rank_source,int * rank_dest)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Cart_shift( comm, direction, disp, rank_source, rank_dest);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Get_processor_name(char * name,int * resultlen);
#pragma weak MPI_Get_processor_name=PMPI_Get_processor_name
int (*INTERFACE_LOCAL_MPI_Get_processor_name)(char *,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Get_processor_name(char *,int *);
extern int INTERF_2_INTEL_CCMPI_Get_processor_name(char *,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Get_processor_name(char * name,int * resultlen)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Get_processor_name( name, resultlen);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Get_version(int * version,int * subversion);
#pragma weak MPI_Get_version=PMPI_Get_version
int (*INTERFACE_LOCAL_MPI_Get_version)(int *,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Get_version(int *,int *);
extern int INTERF_2_INTEL_CCMPI_Get_version(int *,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Get_version(int * version,int * subversion)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Get_version( version, subversion);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Get_library_version(char * version,int * resultlen);
#pragma weak MPI_Get_library_version=PMPI_Get_library_version
int (*INTERFACE_LOCAL_MPI_Get_library_version)(char *,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Get_library_version(char *,int *);
extern int INTERF_2_INTEL_CCMPI_Get_library_version(char *,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Get_library_version(char * version,int * resultlen)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Get_library_version( version, resultlen);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Errhandler_create(MPI_Handler_function * function,MPI_Errhandler * errhandler);
#pragma weak MPI_Errhandler_create=PMPI_Errhandler_create
int (*INTERFACE_LOCAL_MPI_Errhandler_create)(MPI_Handler_function *,MPI_Errhandler *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Errhandler_create(MPI_Handler_function *,MPI_Errhandler *);
extern int INTERF_2_INTEL_CCMPI_Errhandler_create(MPI_Handler_function *,MPI_Errhandler *);
#endif /*WI4MPI_STATIC*/

int PMPI_Errhandler_create(MPI_Handler_function * function,MPI_Errhandler * errhandler)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Errhandler_create( function, errhandler);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Errhandler_set(MPI_Comm comm,MPI_Errhandler errhandler);
#pragma weak MPI_Errhandler_set=PMPI_Errhandler_set
int (*INTERFACE_LOCAL_MPI_Errhandler_set)(MPI_Comm,MPI_Errhandler);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Errhandler_set(MPI_Comm,MPI_Errhandler);
extern int INTERF_2_INTEL_CCMPI_Errhandler_set(MPI_Comm,MPI_Errhandler);
#endif /*WI4MPI_STATIC*/

int PMPI_Errhandler_set(MPI_Comm comm,MPI_Errhandler errhandler)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Errhandler_set( comm, errhandler);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Errhandler_get(MPI_Comm comm,MPI_Errhandler * errhandler);
#pragma weak MPI_Errhandler_get=PMPI_Errhandler_get
int (*INTERFACE_LOCAL_MPI_Errhandler_get)(MPI_Comm,MPI_Errhandler *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Errhandler_get(MPI_Comm,MPI_Errhandler *);
extern int INTERF_2_INTEL_CCMPI_Errhandler_get(MPI_Comm,MPI_Errhandler *);
#endif /*WI4MPI_STATIC*/

int PMPI_Errhandler_get(MPI_Comm comm,MPI_Errhandler * errhandler)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Errhandler_get( comm, errhandler);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Errhandler_free(MPI_Errhandler * errhandler);
#pragma weak MPI_Errhandler_free=PMPI_Errhandler_free
int (*INTERFACE_LOCAL_MPI_Errhandler_free)(MPI_Errhandler *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Errhandler_free(MPI_Errhandler *);
extern int INTERF_2_INTEL_CCMPI_Errhandler_free(MPI_Errhandler *);
#endif /*WI4MPI_STATIC*/

int PMPI_Errhandler_free(MPI_Errhandler * errhandler)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Errhandler_free( errhandler);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Error_string(int errorcode,char * string,int * resultlen);
#pragma weak MPI_Error_string=PMPI_Error_string
int (*INTERFACE_LOCAL_MPI_Error_string)(int,char *,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Error_string(int,char *,int *);
extern int INTERF_2_INTEL_CCMPI_Error_string(int,char *,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Error_string(int errorcode,char * string,int * resultlen)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Error_string( errorcode, string, resultlen);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Error_class(int errorcode,int * errorclass);
#pragma weak MPI_Error_class=PMPI_Error_class
int (*INTERFACE_LOCAL_MPI_Error_class)(int,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Error_class(int,int *);
extern int INTERF_2_INTEL_CCMPI_Error_class(int,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Error_class(int errorcode,int * errorclass)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Error_class( errorcode, errorclass);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Initialized(int * flag);
#pragma weak MPI_Initialized=PMPI_Initialized
int (*INTERFACE_LOCAL_MPI_Initialized)(int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Initialized(int *);
extern int INTERF_2_INTEL_CCMPI_Initialized(int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Initialized(int * flag)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Initialized( flag);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Abort(MPI_Comm comm,int errorcode);
#pragma weak MPI_Abort=PMPI_Abort
int (*INTERFACE_LOCAL_MPI_Abort)(MPI_Comm,int);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Abort(MPI_Comm,int);
extern int INTERF_2_INTEL_CCMPI_Abort(MPI_Comm,int);
#endif /*WI4MPI_STATIC*/

int PMPI_Abort(MPI_Comm comm,int errorcode)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Abort( comm, errorcode);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Init(int * argc,char *** argv);
#pragma weak MPI_Init=PMPI_Init
int (*INTERFACE_LOCAL_MPI_Init)(int *,char ***);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Init(int *,char ***);
extern int INTERF_2_INTEL_CCMPI_Init(int *,char ***);
#endif /*WI4MPI_STATIC*/

int PMPI_Init(int * argc,char *** argv)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Init( argc, argv);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Close_port(char * port_name);
#pragma weak MPI_Close_port=PMPI_Close_port
int (*INTERFACE_LOCAL_MPI_Close_port)(char *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Close_port(char *);
extern int INTERF_2_INTEL_CCMPI_Close_port(char *);
#endif /*WI4MPI_STATIC*/

int PMPI_Close_port(char * port_name)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Close_port( port_name);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Comm_accept(char * port_name,MPI_Info info,int root,MPI_Comm comm,MPI_Comm * newcomm);
#pragma weak MPI_Comm_accept=PMPI_Comm_accept
int (*INTERFACE_LOCAL_MPI_Comm_accept)(char *,MPI_Info,int,MPI_Comm,MPI_Comm *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Comm_accept(char *,MPI_Info,int,MPI_Comm,MPI_Comm *);
extern int INTERF_2_INTEL_CCMPI_Comm_accept(char *,MPI_Info,int,MPI_Comm,MPI_Comm *);
#endif /*WI4MPI_STATIC*/

int PMPI_Comm_accept(char * port_name,MPI_Info info,int root,MPI_Comm comm,MPI_Comm * newcomm)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Comm_accept( port_name, info, root, comm, newcomm);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Comm_connect(char * port_name,MPI_Info info,int root,MPI_Comm comm,MPI_Comm * newcomm);
#pragma weak MPI_Comm_connect=PMPI_Comm_connect
int (*INTERFACE_LOCAL_MPI_Comm_connect)(char *,MPI_Info,int,MPI_Comm,MPI_Comm *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Comm_connect(char *,MPI_Info,int,MPI_Comm,MPI_Comm *);
extern int INTERF_2_INTEL_CCMPI_Comm_connect(char *,MPI_Info,int,MPI_Comm,MPI_Comm *);
#endif /*WI4MPI_STATIC*/

int PMPI_Comm_connect(char * port_name,MPI_Info info,int root,MPI_Comm comm,MPI_Comm * newcomm)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Comm_connect( port_name, info, root, comm, newcomm);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Comm_disconnect(MPI_Comm * comm);
#pragma weak MPI_Comm_disconnect=PMPI_Comm_disconnect
int (*INTERFACE_LOCAL_MPI_Comm_disconnect)(MPI_Comm *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Comm_disconnect(MPI_Comm *);
extern int INTERF_2_INTEL_CCMPI_Comm_disconnect(MPI_Comm *);
#endif /*WI4MPI_STATIC*/

int PMPI_Comm_disconnect(MPI_Comm * comm)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Comm_disconnect( comm);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Comm_get_parent(MPI_Comm * parent);
#pragma weak MPI_Comm_get_parent=PMPI_Comm_get_parent
int (*INTERFACE_LOCAL_MPI_Comm_get_parent)(MPI_Comm *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Comm_get_parent(MPI_Comm *);
extern int INTERF_2_INTEL_CCMPI_Comm_get_parent(MPI_Comm *);
#endif /*WI4MPI_STATIC*/

int PMPI_Comm_get_parent(MPI_Comm * parent)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Comm_get_parent( parent);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Comm_join(int fd,MPI_Comm * intercomm);
#pragma weak MPI_Comm_join=PMPI_Comm_join
int (*INTERFACE_LOCAL_MPI_Comm_join)(int,MPI_Comm *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Comm_join(int,MPI_Comm *);
extern int INTERF_2_INTEL_CCMPI_Comm_join(int,MPI_Comm *);
#endif /*WI4MPI_STATIC*/

int PMPI_Comm_join(int fd,MPI_Comm * intercomm)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Comm_join( fd, intercomm);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Lookup_name(char * service_name,MPI_Info info,char * port_name);
#pragma weak MPI_Lookup_name=PMPI_Lookup_name
int (*INTERFACE_LOCAL_MPI_Lookup_name)(char *,MPI_Info,char *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Lookup_name(char *,MPI_Info,char *);
extern int INTERF_2_INTEL_CCMPI_Lookup_name(char *,MPI_Info,char *);
#endif /*WI4MPI_STATIC*/

int PMPI_Lookup_name(char * service_name,MPI_Info info,char * port_name)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Lookup_name( service_name, info, port_name);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Open_port(MPI_Info info,char * port_name);
#pragma weak MPI_Open_port=PMPI_Open_port
int (*INTERFACE_LOCAL_MPI_Open_port)(MPI_Info,char *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Open_port(MPI_Info,char *);
extern int INTERF_2_INTEL_CCMPI_Open_port(MPI_Info,char *);
#endif /*WI4MPI_STATIC*/

int PMPI_Open_port(MPI_Info info,char * port_name)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Open_port( info, port_name);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Publish_name(char * service_name,MPI_Info info,char * port_name);
#pragma weak MPI_Publish_name=PMPI_Publish_name
int (*INTERFACE_LOCAL_MPI_Publish_name)(char *,MPI_Info,char *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Publish_name(char *,MPI_Info,char *);
extern int INTERF_2_INTEL_CCMPI_Publish_name(char *,MPI_Info,char *);
#endif /*WI4MPI_STATIC*/

int PMPI_Publish_name(char * service_name,MPI_Info info,char * port_name)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Publish_name( service_name, info, port_name);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Unpublish_name(char * service_name,MPI_Info info,char * port_name);
#pragma weak MPI_Unpublish_name=PMPI_Unpublish_name
int (*INTERFACE_LOCAL_MPI_Unpublish_name)(char *,MPI_Info,char *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Unpublish_name(char *,MPI_Info,char *);
extern int INTERF_2_INTEL_CCMPI_Unpublish_name(char *,MPI_Info,char *);
#endif /*WI4MPI_STATIC*/

int PMPI_Unpublish_name(char * service_name,MPI_Info info,char * port_name)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Unpublish_name( service_name, info, port_name);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Comm_set_info(MPI_Comm comm,MPI_Info info);
#pragma weak MPI_Comm_set_info=PMPI_Comm_set_info
int (*INTERFACE_LOCAL_MPI_Comm_set_info)(MPI_Comm,MPI_Info);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Comm_set_info(MPI_Comm,MPI_Info);
extern int INTERF_2_INTEL_CCMPI_Comm_set_info(MPI_Comm,MPI_Info);
#endif /*WI4MPI_STATIC*/

int PMPI_Comm_set_info(MPI_Comm comm,MPI_Info info)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Comm_set_info( comm, info);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Comm_get_info(MPI_Comm comm,MPI_Info * info);
#pragma weak MPI_Comm_get_info=PMPI_Comm_get_info
int (*INTERFACE_LOCAL_MPI_Comm_get_info)(MPI_Comm,MPI_Info *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Comm_get_info(MPI_Comm,MPI_Info *);
extern int INTERF_2_INTEL_CCMPI_Comm_get_info(MPI_Comm,MPI_Info *);
#endif /*WI4MPI_STATIC*/

int PMPI_Comm_get_info(MPI_Comm comm,MPI_Info * info)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Comm_get_info( comm, info);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Accumulate(void * origin_addr,int origin_count,MPI_Datatype origin_datatype,int target_rank,MPI_Aint target_disp,int target_count,MPI_Datatype target_datatype,MPI_Op op,MPI_Win win);
#pragma weak MPI_Accumulate=PMPI_Accumulate
int (*INTERFACE_LOCAL_MPI_Accumulate)(void *,int,MPI_Datatype,int,MPI_Aint,int,MPI_Datatype,MPI_Op,MPI_Win);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Accumulate(void *,int,MPI_Datatype,int,MPI_Aint,int,MPI_Datatype,MPI_Op,MPI_Win);
extern int INTERF_2_INTEL_CCMPI_Accumulate(void *,int,MPI_Datatype,int,MPI_Aint,int,MPI_Datatype,MPI_Op,MPI_Win);
#endif /*WI4MPI_STATIC*/

int PMPI_Accumulate(void * origin_addr,int origin_count,MPI_Datatype origin_datatype,int target_rank,MPI_Aint target_disp,int target_count,MPI_Datatype target_datatype,MPI_Op op,MPI_Win win)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Accumulate( origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Get(void * origin_addr,int origin_count,MPI_Datatype origin_datatype,int target_rank,MPI_Aint target_disp,int target_count,MPI_Datatype target_datatype,MPI_Win win);
#pragma weak MPI_Get=PMPI_Get
int (*INTERFACE_LOCAL_MPI_Get)(void *,int,MPI_Datatype,int,MPI_Aint,int,MPI_Datatype,MPI_Win);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Get(void *,int,MPI_Datatype,int,MPI_Aint,int,MPI_Datatype,MPI_Win);
extern int INTERF_2_INTEL_CCMPI_Get(void *,int,MPI_Datatype,int,MPI_Aint,int,MPI_Datatype,MPI_Win);
#endif /*WI4MPI_STATIC*/

int PMPI_Get(void * origin_addr,int origin_count,MPI_Datatype origin_datatype,int target_rank,MPI_Aint target_disp,int target_count,MPI_Datatype target_datatype,MPI_Win win)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Get( origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Put(void * origin_addr,int origin_count,MPI_Datatype origin_datatype,int target_rank,MPI_Aint target_disp,int target_count,MPI_Datatype target_datatype,MPI_Win win);
#pragma weak MPI_Put=PMPI_Put
int (*INTERFACE_LOCAL_MPI_Put)(void *,int,MPI_Datatype,int,MPI_Aint,int,MPI_Datatype,MPI_Win);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Put(void *,int,MPI_Datatype,int,MPI_Aint,int,MPI_Datatype,MPI_Win);
extern int INTERF_2_INTEL_CCMPI_Put(void *,int,MPI_Datatype,int,MPI_Aint,int,MPI_Datatype,MPI_Win);
#endif /*WI4MPI_STATIC*/

int PMPI_Put(void * origin_addr,int origin_count,MPI_Datatype origin_datatype,int target_rank,MPI_Aint target_disp,int target_count,MPI_Datatype target_datatype,MPI_Win win)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Put( origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Win_complete(MPI_Win win);
#pragma weak MPI_Win_complete=PMPI_Win_complete
int (*INTERFACE_LOCAL_MPI_Win_complete)(MPI_Win);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Win_complete(MPI_Win);
extern int INTERF_2_INTEL_CCMPI_Win_complete(MPI_Win);
#endif /*WI4MPI_STATIC*/

int PMPI_Win_complete(MPI_Win win)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Win_complete( win);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Win_create(void * base,MPI_Aint size,int disp_unit,MPI_Info info,MPI_Comm comm,MPI_Win * win);
#pragma weak MPI_Win_create=PMPI_Win_create
int (*INTERFACE_LOCAL_MPI_Win_create)(void *,MPI_Aint,int,MPI_Info,MPI_Comm,MPI_Win *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Win_create(void *,MPI_Aint,int,MPI_Info,MPI_Comm,MPI_Win *);
extern int INTERF_2_INTEL_CCMPI_Win_create(void *,MPI_Aint,int,MPI_Info,MPI_Comm,MPI_Win *);
#endif /*WI4MPI_STATIC*/

int PMPI_Win_create(void * base,MPI_Aint size,int disp_unit,MPI_Info info,MPI_Comm comm,MPI_Win * win)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Win_create( base, size, disp_unit, info, comm, win);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Win_fence(int assert,MPI_Win win);
#pragma weak MPI_Win_fence=PMPI_Win_fence
int (*INTERFACE_LOCAL_MPI_Win_fence)(int,MPI_Win);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Win_fence(int,MPI_Win);
extern int INTERF_2_INTEL_CCMPI_Win_fence(int,MPI_Win);
#endif /*WI4MPI_STATIC*/

int PMPI_Win_fence(int assert,MPI_Win win)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Win_fence( assert, win);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Win_free(MPI_Win * win);
#pragma weak MPI_Win_free=PMPI_Win_free
int (*INTERFACE_LOCAL_MPI_Win_free)(MPI_Win *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Win_free(MPI_Win *);
extern int INTERF_2_INTEL_CCMPI_Win_free(MPI_Win *);
#endif /*WI4MPI_STATIC*/

int PMPI_Win_free(MPI_Win * win)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Win_free( win);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Win_get_group(MPI_Win win,MPI_Group * group);
#pragma weak MPI_Win_get_group=PMPI_Win_get_group
int (*INTERFACE_LOCAL_MPI_Win_get_group)(MPI_Win,MPI_Group *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Win_get_group(MPI_Win,MPI_Group *);
extern int INTERF_2_INTEL_CCMPI_Win_get_group(MPI_Win,MPI_Group *);
#endif /*WI4MPI_STATIC*/

int PMPI_Win_get_group(MPI_Win win,MPI_Group * group)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Win_get_group( win, group);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Win_lock(int lock_type,int rank,int assert,MPI_Win win);
#pragma weak MPI_Win_lock=PMPI_Win_lock
int (*INTERFACE_LOCAL_MPI_Win_lock)(int,int,int,MPI_Win);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Win_lock(int,int,int,MPI_Win);
extern int INTERF_2_INTEL_CCMPI_Win_lock(int,int,int,MPI_Win);
#endif /*WI4MPI_STATIC*/

int PMPI_Win_lock(int lock_type,int rank,int assert,MPI_Win win)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Win_lock( lock_type, rank, assert, win);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Win_post(MPI_Group group,int assert,MPI_Win win);
#pragma weak MPI_Win_post=PMPI_Win_post
int (*INTERFACE_LOCAL_MPI_Win_post)(MPI_Group,int,MPI_Win);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Win_post(MPI_Group,int,MPI_Win);
extern int INTERF_2_INTEL_CCMPI_Win_post(MPI_Group,int,MPI_Win);
#endif /*WI4MPI_STATIC*/

int PMPI_Win_post(MPI_Group group,int assert,MPI_Win win)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Win_post( group, assert, win);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Win_start(MPI_Group group,int assert,MPI_Win win);
#pragma weak MPI_Win_start=PMPI_Win_start
int (*INTERFACE_LOCAL_MPI_Win_start)(MPI_Group,int,MPI_Win);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Win_start(MPI_Group,int,MPI_Win);
extern int INTERF_2_INTEL_CCMPI_Win_start(MPI_Group,int,MPI_Win);
#endif /*WI4MPI_STATIC*/

int PMPI_Win_start(MPI_Group group,int assert,MPI_Win win)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Win_start( group, assert, win);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Win_test(MPI_Win win,int * flag);
#pragma weak MPI_Win_test=PMPI_Win_test
int (*INTERFACE_LOCAL_MPI_Win_test)(MPI_Win,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Win_test(MPI_Win,int *);
extern int INTERF_2_INTEL_CCMPI_Win_test(MPI_Win,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Win_test(MPI_Win win,int * flag)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Win_test( win, flag);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Win_unlock(int rank,MPI_Win win);
#pragma weak MPI_Win_unlock=PMPI_Win_unlock
int (*INTERFACE_LOCAL_MPI_Win_unlock)(int,MPI_Win);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Win_unlock(int,MPI_Win);
extern int INTERF_2_INTEL_CCMPI_Win_unlock(int,MPI_Win);
#endif /*WI4MPI_STATIC*/

int PMPI_Win_unlock(int rank,MPI_Win win)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Win_unlock( rank, win);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Win_wait(MPI_Win win);
#pragma weak MPI_Win_wait=PMPI_Win_wait
int (*INTERFACE_LOCAL_MPI_Win_wait)(MPI_Win);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Win_wait(MPI_Win);
extern int INTERF_2_INTEL_CCMPI_Win_wait(MPI_Win);
#endif /*WI4MPI_STATIC*/

int PMPI_Win_wait(MPI_Win win)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Win_wait( win);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Win_allocate(MPI_Aint size,int disp_unit,MPI_Info info,MPI_Comm comm,void * baseptr,MPI_Win * win);
#pragma weak MPI_Win_allocate=PMPI_Win_allocate
int (*INTERFACE_LOCAL_MPI_Win_allocate)(MPI_Aint,int,MPI_Info,MPI_Comm,void *,MPI_Win *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Win_allocate(MPI_Aint,int,MPI_Info,MPI_Comm,void *,MPI_Win *);
extern int INTERF_2_INTEL_CCMPI_Win_allocate(MPI_Aint,int,MPI_Info,MPI_Comm,void *,MPI_Win *);
#endif /*WI4MPI_STATIC*/

int PMPI_Win_allocate(MPI_Aint size,int disp_unit,MPI_Info info,MPI_Comm comm,void * baseptr,MPI_Win * win)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Win_allocate( size, disp_unit, info, comm, baseptr, win);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Win_allocate_shared(MPI_Aint size,int disp_unit,MPI_Info info,MPI_Comm comm,void * baseptr,MPI_Win * win);
#pragma weak MPI_Win_allocate_shared=PMPI_Win_allocate_shared
int (*INTERFACE_LOCAL_MPI_Win_allocate_shared)(MPI_Aint,int,MPI_Info,MPI_Comm,void *,MPI_Win *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Win_allocate_shared(MPI_Aint,int,MPI_Info,MPI_Comm,void *,MPI_Win *);
extern int INTERF_2_INTEL_CCMPI_Win_allocate_shared(MPI_Aint,int,MPI_Info,MPI_Comm,void *,MPI_Win *);
#endif /*WI4MPI_STATIC*/

int PMPI_Win_allocate_shared(MPI_Aint size,int disp_unit,MPI_Info info,MPI_Comm comm,void * baseptr,MPI_Win * win)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Win_allocate_shared( size, disp_unit, info, comm, baseptr, win);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Win_shared_query(MPI_Win win,int rank,MPI_Aint * size,int * disp_unit,void * baseptr);
#pragma weak MPI_Win_shared_query=PMPI_Win_shared_query
int (*INTERFACE_LOCAL_MPI_Win_shared_query)(MPI_Win,int,MPI_Aint *,int *,void *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Win_shared_query(MPI_Win,int,MPI_Aint *,int *,void *);
extern int INTERF_2_INTEL_CCMPI_Win_shared_query(MPI_Win,int,MPI_Aint *,int *,void *);
#endif /*WI4MPI_STATIC*/

int PMPI_Win_shared_query(MPI_Win win,int rank,MPI_Aint * size,int * disp_unit,void * baseptr)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Win_shared_query( win, rank, size, disp_unit, baseptr);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Win_create_dynamic(MPI_Info info,MPI_Comm comm,MPI_Win * win);
#pragma weak MPI_Win_create_dynamic=PMPI_Win_create_dynamic
int (*INTERFACE_LOCAL_MPI_Win_create_dynamic)(MPI_Info,MPI_Comm,MPI_Win *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Win_create_dynamic(MPI_Info,MPI_Comm,MPI_Win *);
extern int INTERF_2_INTEL_CCMPI_Win_create_dynamic(MPI_Info,MPI_Comm,MPI_Win *);
#endif /*WI4MPI_STATIC*/

int PMPI_Win_create_dynamic(MPI_Info info,MPI_Comm comm,MPI_Win * win)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Win_create_dynamic( info, comm, win);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Win_attach(MPI_Win win,void * base,MPI_Aint size);
#pragma weak MPI_Win_attach=PMPI_Win_attach
int (*INTERFACE_LOCAL_MPI_Win_attach)(MPI_Win,void *,MPI_Aint);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Win_attach(MPI_Win,void *,MPI_Aint);
extern int INTERF_2_INTEL_CCMPI_Win_attach(MPI_Win,void *,MPI_Aint);
#endif /*WI4MPI_STATIC*/

int PMPI_Win_attach(MPI_Win win,void * base,MPI_Aint size)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Win_attach( win, base, size);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Win_detach(MPI_Win win,void * base);
#pragma weak MPI_Win_detach=PMPI_Win_detach
int (*INTERFACE_LOCAL_MPI_Win_detach)(MPI_Win,void *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Win_detach(MPI_Win,void *);
extern int INTERF_2_INTEL_CCMPI_Win_detach(MPI_Win,void *);
#endif /*WI4MPI_STATIC*/

int PMPI_Win_detach(MPI_Win win,void * base)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Win_detach( win, base);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Win_get_info(MPI_Win win,MPI_Info * info_used);
#pragma weak MPI_Win_get_info=PMPI_Win_get_info
int (*INTERFACE_LOCAL_MPI_Win_get_info)(MPI_Win,MPI_Info *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Win_get_info(MPI_Win,MPI_Info *);
extern int INTERF_2_INTEL_CCMPI_Win_get_info(MPI_Win,MPI_Info *);
#endif /*WI4MPI_STATIC*/

int PMPI_Win_get_info(MPI_Win win,MPI_Info * info_used)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Win_get_info( win, info_used);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Win_set_info(MPI_Win win,MPI_Info info);
#pragma weak MPI_Win_set_info=PMPI_Win_set_info
int (*INTERFACE_LOCAL_MPI_Win_set_info)(MPI_Win,MPI_Info);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Win_set_info(MPI_Win,MPI_Info);
extern int INTERF_2_INTEL_CCMPI_Win_set_info(MPI_Win,MPI_Info);
#endif /*WI4MPI_STATIC*/

int PMPI_Win_set_info(MPI_Win win,MPI_Info info)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Win_set_info( win, info);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Get_accumulate(void * origin_addr,int origin_count,MPI_Datatype origin_datatype,void * result_addr,int result_count,MPI_Datatype result_datatype,int target_rank,MPI_Aint target_disp,int target_count,MPI_Datatype target_datatype,MPI_Op op,MPI_Win win);
#pragma weak MPI_Get_accumulate=PMPI_Get_accumulate
int (*INTERFACE_LOCAL_MPI_Get_accumulate)(void *,int,MPI_Datatype,void *,int,MPI_Datatype,int,MPI_Aint,int,MPI_Datatype,MPI_Op,MPI_Win);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Get_accumulate(void *,int,MPI_Datatype,void *,int,MPI_Datatype,int,MPI_Aint,int,MPI_Datatype,MPI_Op,MPI_Win);
extern int INTERF_2_INTEL_CCMPI_Get_accumulate(void *,int,MPI_Datatype,void *,int,MPI_Datatype,int,MPI_Aint,int,MPI_Datatype,MPI_Op,MPI_Win);
#endif /*WI4MPI_STATIC*/

int PMPI_Get_accumulate(void * origin_addr,int origin_count,MPI_Datatype origin_datatype,void * result_addr,int result_count,MPI_Datatype result_datatype,int target_rank,MPI_Aint target_disp,int target_count,MPI_Datatype target_datatype,MPI_Op op,MPI_Win win)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Get_accumulate( origin_addr, origin_count, origin_datatype, result_addr, result_count, result_datatype, target_rank, target_disp, target_count, target_datatype, op, win);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Fetch_and_op(void * origin_addr,void * result_addr,MPI_Datatype datatype,int target_rank,MPI_Aint target_disp,MPI_Op op,MPI_Win win);
#pragma weak MPI_Fetch_and_op=PMPI_Fetch_and_op
int (*INTERFACE_LOCAL_MPI_Fetch_and_op)(void *,void *,MPI_Datatype,int,MPI_Aint,MPI_Op,MPI_Win);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Fetch_and_op(void *,void *,MPI_Datatype,int,MPI_Aint,MPI_Op,MPI_Win);
extern int INTERF_2_INTEL_CCMPI_Fetch_and_op(void *,void *,MPI_Datatype,int,MPI_Aint,MPI_Op,MPI_Win);
#endif /*WI4MPI_STATIC*/

int PMPI_Fetch_and_op(void * origin_addr,void * result_addr,MPI_Datatype datatype,int target_rank,MPI_Aint target_disp,MPI_Op op,MPI_Win win)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Fetch_and_op( origin_addr, result_addr, datatype, target_rank, target_disp, op, win);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Compare_and_swap(void * origin_addr,void * compare_addr,void * result_addr,MPI_Datatype datatype,int target_rank,MPI_Aint target_disp,MPI_Win win);
#pragma weak MPI_Compare_and_swap=PMPI_Compare_and_swap
int (*INTERFACE_LOCAL_MPI_Compare_and_swap)(void *,void *,void *,MPI_Datatype,int,MPI_Aint,MPI_Win);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Compare_and_swap(void *,void *,void *,MPI_Datatype,int,MPI_Aint,MPI_Win);
extern int INTERF_2_INTEL_CCMPI_Compare_and_swap(void *,void *,void *,MPI_Datatype,int,MPI_Aint,MPI_Win);
#endif /*WI4MPI_STATIC*/

int PMPI_Compare_and_swap(void * origin_addr,void * compare_addr,void * result_addr,MPI_Datatype datatype,int target_rank,MPI_Aint target_disp,MPI_Win win)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Compare_and_swap( origin_addr, compare_addr, result_addr, datatype, target_rank, target_disp, win);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Rput(void * origin_addr,int origin_count,MPI_Datatype origin_datatype,int target_rank,MPI_Aint target_disp,int target_count,MPI_Datatype target_datatype,MPI_Win win,MPI_Request * request);
#pragma weak MPI_Rput=PMPI_Rput
int (*INTERFACE_LOCAL_MPI_Rput)(void *,int,MPI_Datatype,int,MPI_Aint,int,MPI_Datatype,MPI_Win,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Rput(void *,int,MPI_Datatype,int,MPI_Aint,int,MPI_Datatype,MPI_Win,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Rput(void *,int,MPI_Datatype,int,MPI_Aint,int,MPI_Datatype,MPI_Win,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Rput(void * origin_addr,int origin_count,MPI_Datatype origin_datatype,int target_rank,MPI_Aint target_disp,int target_count,MPI_Datatype target_datatype,MPI_Win win,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Rput( origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Rget(void * origin_addr,int origin_count,MPI_Datatype origin_datatype,int target_rank,MPI_Aint target_disp,int target_count,MPI_Datatype target_datatype,MPI_Win win,MPI_Request * request);
#pragma weak MPI_Rget=PMPI_Rget
int (*INTERFACE_LOCAL_MPI_Rget)(void *,int,MPI_Datatype,int,MPI_Aint,int,MPI_Datatype,MPI_Win,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Rget(void *,int,MPI_Datatype,int,MPI_Aint,int,MPI_Datatype,MPI_Win,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Rget(void *,int,MPI_Datatype,int,MPI_Aint,int,MPI_Datatype,MPI_Win,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Rget(void * origin_addr,int origin_count,MPI_Datatype origin_datatype,int target_rank,MPI_Aint target_disp,int target_count,MPI_Datatype target_datatype,MPI_Win win,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Rget( origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Raccumulate(void * origin_addr,int origin_count,MPI_Datatype origin_datatype,int target_rank,MPI_Aint target_disp,int target_count,MPI_Datatype target_datatype,MPI_Op op,MPI_Win win,MPI_Request * request);
#pragma weak MPI_Raccumulate=PMPI_Raccumulate
int (*INTERFACE_LOCAL_MPI_Raccumulate)(void *,int,MPI_Datatype,int,MPI_Aint,int,MPI_Datatype,MPI_Op,MPI_Win,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Raccumulate(void *,int,MPI_Datatype,int,MPI_Aint,int,MPI_Datatype,MPI_Op,MPI_Win,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Raccumulate(void *,int,MPI_Datatype,int,MPI_Aint,int,MPI_Datatype,MPI_Op,MPI_Win,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Raccumulate(void * origin_addr,int origin_count,MPI_Datatype origin_datatype,int target_rank,MPI_Aint target_disp,int target_count,MPI_Datatype target_datatype,MPI_Op op,MPI_Win win,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Raccumulate( origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Rget_accumulate(void * origin_addr,int origin_count,MPI_Datatype origin_datatype,void * result_addr,int result_count,MPI_Datatype result_datatype,int target_rank,MPI_Aint target_disp,int target_count,MPI_Datatype target_datatype,MPI_Op op,MPI_Win win,MPI_Request * request);
#pragma weak MPI_Rget_accumulate=PMPI_Rget_accumulate
int (*INTERFACE_LOCAL_MPI_Rget_accumulate)(void *,int,MPI_Datatype,void *,int,MPI_Datatype,int,MPI_Aint,int,MPI_Datatype,MPI_Op,MPI_Win,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Rget_accumulate(void *,int,MPI_Datatype,void *,int,MPI_Datatype,int,MPI_Aint,int,MPI_Datatype,MPI_Op,MPI_Win,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Rget_accumulate(void *,int,MPI_Datatype,void *,int,MPI_Datatype,int,MPI_Aint,int,MPI_Datatype,MPI_Op,MPI_Win,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Rget_accumulate(void * origin_addr,int origin_count,MPI_Datatype origin_datatype,void * result_addr,int result_count,MPI_Datatype result_datatype,int target_rank,MPI_Aint target_disp,int target_count,MPI_Datatype target_datatype,MPI_Op op,MPI_Win win,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Rget_accumulate( origin_addr, origin_count, origin_datatype, result_addr, result_count, result_datatype, target_rank, target_disp, target_count, target_datatype, op, win, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Win_lock_all(int assert,MPI_Win win);
#pragma weak MPI_Win_lock_all=PMPI_Win_lock_all
int (*INTERFACE_LOCAL_MPI_Win_lock_all)(int,MPI_Win);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Win_lock_all(int,MPI_Win);
extern int INTERF_2_INTEL_CCMPI_Win_lock_all(int,MPI_Win);
#endif /*WI4MPI_STATIC*/

int PMPI_Win_lock_all(int assert,MPI_Win win)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Win_lock_all( assert, win);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Win_unlock_all(MPI_Win win);
#pragma weak MPI_Win_unlock_all=PMPI_Win_unlock_all
int (*INTERFACE_LOCAL_MPI_Win_unlock_all)(MPI_Win);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Win_unlock_all(MPI_Win);
extern int INTERF_2_INTEL_CCMPI_Win_unlock_all(MPI_Win);
#endif /*WI4MPI_STATIC*/

int PMPI_Win_unlock_all(MPI_Win win)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Win_unlock_all( win);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Win_flush(int rank,MPI_Win win);
#pragma weak MPI_Win_flush=PMPI_Win_flush
int (*INTERFACE_LOCAL_MPI_Win_flush)(int,MPI_Win);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Win_flush(int,MPI_Win);
extern int INTERF_2_INTEL_CCMPI_Win_flush(int,MPI_Win);
#endif /*WI4MPI_STATIC*/

int PMPI_Win_flush(int rank,MPI_Win win)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Win_flush( rank, win);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Win_flush_all(MPI_Win win);
#pragma weak MPI_Win_flush_all=PMPI_Win_flush_all
int (*INTERFACE_LOCAL_MPI_Win_flush_all)(MPI_Win);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Win_flush_all(MPI_Win);
extern int INTERF_2_INTEL_CCMPI_Win_flush_all(MPI_Win);
#endif /*WI4MPI_STATIC*/

int PMPI_Win_flush_all(MPI_Win win)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Win_flush_all( win);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Win_flush_local(int rank,MPI_Win win);
#pragma weak MPI_Win_flush_local=PMPI_Win_flush_local
int (*INTERFACE_LOCAL_MPI_Win_flush_local)(int,MPI_Win);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Win_flush_local(int,MPI_Win);
extern int INTERF_2_INTEL_CCMPI_Win_flush_local(int,MPI_Win);
#endif /*WI4MPI_STATIC*/

int PMPI_Win_flush_local(int rank,MPI_Win win)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Win_flush_local( rank, win);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Win_flush_local_all(MPI_Win win);
#pragma weak MPI_Win_flush_local_all=PMPI_Win_flush_local_all
int (*INTERFACE_LOCAL_MPI_Win_flush_local_all)(MPI_Win);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Win_flush_local_all(MPI_Win);
extern int INTERF_2_INTEL_CCMPI_Win_flush_local_all(MPI_Win);
#endif /*WI4MPI_STATIC*/

int PMPI_Win_flush_local_all(MPI_Win win)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Win_flush_local_all( win);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Win_sync(MPI_Win win);
#pragma weak MPI_Win_sync=PMPI_Win_sync
int (*INTERFACE_LOCAL_MPI_Win_sync)(MPI_Win);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Win_sync(MPI_Win);
extern int INTERF_2_INTEL_CCMPI_Win_sync(MPI_Win);
#endif /*WI4MPI_STATIC*/

int PMPI_Win_sync(MPI_Win win)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Win_sync( win);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Add_error_class(int * errorclass);
#pragma weak MPI_Add_error_class=PMPI_Add_error_class
int (*INTERFACE_LOCAL_MPI_Add_error_class)(int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Add_error_class(int *);
extern int INTERF_2_INTEL_CCMPI_Add_error_class(int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Add_error_class(int * errorclass)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Add_error_class( errorclass);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Add_error_code(int errorclass,int * errorcode);
#pragma weak MPI_Add_error_code=PMPI_Add_error_code
int (*INTERFACE_LOCAL_MPI_Add_error_code)(int,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Add_error_code(int,int *);
extern int INTERF_2_INTEL_CCMPI_Add_error_code(int,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Add_error_code(int errorclass,int * errorcode)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Add_error_code( errorclass, errorcode);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Add_error_string(int errorcode,char * string);
#pragma weak MPI_Add_error_string=PMPI_Add_error_string
int (*INTERFACE_LOCAL_MPI_Add_error_string)(int,char *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Add_error_string(int,char *);
extern int INTERF_2_INTEL_CCMPI_Add_error_string(int,char *);
#endif /*WI4MPI_STATIC*/

int PMPI_Add_error_string(int errorcode,char * string)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Add_error_string( errorcode, string);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Comm_call_errhandler(MPI_Comm comm,int errorcode);
#pragma weak MPI_Comm_call_errhandler=PMPI_Comm_call_errhandler
int (*INTERFACE_LOCAL_MPI_Comm_call_errhandler)(MPI_Comm,int);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Comm_call_errhandler(MPI_Comm,int);
extern int INTERF_2_INTEL_CCMPI_Comm_call_errhandler(MPI_Comm,int);
#endif /*WI4MPI_STATIC*/

int PMPI_Comm_call_errhandler(MPI_Comm comm,int errorcode)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Comm_call_errhandler( comm, errorcode);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Comm_delete_attr(MPI_Comm comm,int comm_keyval);
#pragma weak MPI_Comm_delete_attr=PMPI_Comm_delete_attr
int (*INTERFACE_LOCAL_MPI_Comm_delete_attr)(MPI_Comm,int);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Comm_delete_attr(MPI_Comm,int);
extern int INTERF_2_INTEL_CCMPI_Comm_delete_attr(MPI_Comm,int);
#endif /*WI4MPI_STATIC*/

int PMPI_Comm_delete_attr(MPI_Comm comm,int comm_keyval)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Comm_delete_attr( comm, comm_keyval);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Comm_get_attr(MPI_Comm comm,int comm_keyval,void * attribute_val,int * flag);
#pragma weak MPI_Comm_get_attr=PMPI_Comm_get_attr
int (*INTERFACE_LOCAL_MPI_Comm_get_attr)(MPI_Comm,int,void *,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Comm_get_attr(MPI_Comm,int,void *,int *);
extern int INTERF_2_INTEL_CCMPI_Comm_get_attr(MPI_Comm,int,void *,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Comm_get_attr(MPI_Comm comm,int comm_keyval,void * attribute_val,int * flag)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Comm_get_attr( comm, comm_keyval, attribute_val, flag);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Comm_get_name(MPI_Comm comm,char * comm_name,int * resultlen);
#pragma weak MPI_Comm_get_name=PMPI_Comm_get_name
int (*INTERFACE_LOCAL_MPI_Comm_get_name)(MPI_Comm,char *,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Comm_get_name(MPI_Comm,char *,int *);
extern int INTERF_2_INTEL_CCMPI_Comm_get_name(MPI_Comm,char *,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Comm_get_name(MPI_Comm comm,char * comm_name,int * resultlen)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Comm_get_name( comm, comm_name, resultlen);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Comm_set_attr(MPI_Comm comm,int comm_keyval,void * attribute_val);
#pragma weak MPI_Comm_set_attr=PMPI_Comm_set_attr
int (*INTERFACE_LOCAL_MPI_Comm_set_attr)(MPI_Comm,int,void *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Comm_set_attr(MPI_Comm,int,void *);
extern int INTERF_2_INTEL_CCMPI_Comm_set_attr(MPI_Comm,int,void *);
#endif /*WI4MPI_STATIC*/

int PMPI_Comm_set_attr(MPI_Comm comm,int comm_keyval,void * attribute_val)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Comm_set_attr( comm, comm_keyval, attribute_val);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Comm_set_name(MPI_Comm comm,char * comm_name);
#pragma weak MPI_Comm_set_name=PMPI_Comm_set_name
int (*INTERFACE_LOCAL_MPI_Comm_set_name)(MPI_Comm,char *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Comm_set_name(MPI_Comm,char *);
extern int INTERF_2_INTEL_CCMPI_Comm_set_name(MPI_Comm,char *);
#endif /*WI4MPI_STATIC*/

int PMPI_Comm_set_name(MPI_Comm comm,char * comm_name)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Comm_set_name( comm, comm_name);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_call_errhandler(MPI_File fh,int errorcode);
#pragma weak MPI_File_call_errhandler=PMPI_File_call_errhandler
int (*INTERFACE_LOCAL_MPI_File_call_errhandler)(MPI_File,int);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_call_errhandler(MPI_File,int);
extern int INTERF_2_INTEL_CCMPI_File_call_errhandler(MPI_File,int);
#endif /*WI4MPI_STATIC*/

int PMPI_File_call_errhandler(MPI_File fh,int errorcode)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_call_errhandler( fh, errorcode);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Grequest_complete(MPI_Request request);
#pragma weak MPI_Grequest_complete=PMPI_Grequest_complete
int (*INTERFACE_LOCAL_MPI_Grequest_complete)(MPI_Request);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Grequest_complete(MPI_Request);
extern int INTERF_2_INTEL_CCMPI_Grequest_complete(MPI_Request);
#endif /*WI4MPI_STATIC*/

int PMPI_Grequest_complete(MPI_Request request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Grequest_complete( request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Grequest_start(MPI_Grequest_query_function * query_fn,MPI_Grequest_free_function * free_fn,MPI_Grequest_cancel_function * cancel_fn,void * extra_state,MPI_Request * request);
#pragma weak MPI_Grequest_start=PMPI_Grequest_start
int (*INTERFACE_LOCAL_MPI_Grequest_start)(MPI_Grequest_query_function *,MPI_Grequest_free_function *,MPI_Grequest_cancel_function *,void *,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Grequest_start(MPI_Grequest_query_function *,MPI_Grequest_free_function *,MPI_Grequest_cancel_function *,void *,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Grequest_start(MPI_Grequest_query_function *,MPI_Grequest_free_function *,MPI_Grequest_cancel_function *,void *,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Grequest_start(MPI_Grequest_query_function * query_fn,MPI_Grequest_free_function * free_fn,MPI_Grequest_cancel_function * cancel_fn,void * extra_state,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Grequest_start( query_fn, free_fn, cancel_fn, extra_state, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Init_thread(int * argc,char *** argv,int required,int * provided);
#pragma weak MPI_Init_thread=PMPI_Init_thread
int (*INTERFACE_LOCAL_MPI_Init_thread)(int *,char ***,int,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Init_thread(int *,char ***,int,int *);
extern int INTERF_2_INTEL_CCMPI_Init_thread(int *,char ***,int,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Init_thread(int * argc,char *** argv,int required,int * provided)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Init_thread( argc, argv, required, provided);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Is_thread_main(int * flag);
#pragma weak MPI_Is_thread_main=PMPI_Is_thread_main
int (*INTERFACE_LOCAL_MPI_Is_thread_main)(int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Is_thread_main(int *);
extern int INTERF_2_INTEL_CCMPI_Is_thread_main(int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Is_thread_main(int * flag)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Is_thread_main( flag);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Query_thread(int * provided);
#pragma weak MPI_Query_thread=PMPI_Query_thread
int (*INTERFACE_LOCAL_MPI_Query_thread)(int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Query_thread(int *);
extern int INTERF_2_INTEL_CCMPI_Query_thread(int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Query_thread(int * provided)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Query_thread( provided);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Status_set_cancelled(MPI_Status * status,int flag);
#pragma weak MPI_Status_set_cancelled=PMPI_Status_set_cancelled
int (*INTERFACE_LOCAL_MPI_Status_set_cancelled)(MPI_Status *,int);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Status_set_cancelled(MPI_Status *,int);
extern int INTERF_2_INTEL_CCMPI_Status_set_cancelled(MPI_Status *,int);
#endif /*WI4MPI_STATIC*/

int PMPI_Status_set_cancelled(MPI_Status * status,int flag)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Status_set_cancelled( status, flag);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Status_set_elements(MPI_Status * status,MPI_Datatype datatype,int count);
#pragma weak MPI_Status_set_elements=PMPI_Status_set_elements
int (*INTERFACE_LOCAL_MPI_Status_set_elements)(MPI_Status *,MPI_Datatype,int);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Status_set_elements(MPI_Status *,MPI_Datatype,int);
extern int INTERF_2_INTEL_CCMPI_Status_set_elements(MPI_Status *,MPI_Datatype,int);
#endif /*WI4MPI_STATIC*/

int PMPI_Status_set_elements(MPI_Status * status,MPI_Datatype datatype,int count)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Status_set_elements( status, datatype, count);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Type_create_keyval(MPI_Type_copy_attr_function * type_copy_attr_fn,MPI_Type_delete_attr_function * type_delete_attr_fn,int * type_keyval,void * extra_state);
#pragma weak MPI_Type_create_keyval=PMPI_Type_create_keyval
int (*INTERFACE_LOCAL_MPI_Type_create_keyval)(MPI_Type_copy_attr_function *,MPI_Type_delete_attr_function *,int *,void *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Type_create_keyval(MPI_Type_copy_attr_function *,MPI_Type_delete_attr_function *,int *,void *);
extern int INTERF_2_INTEL_CCMPI_Type_create_keyval(MPI_Type_copy_attr_function *,MPI_Type_delete_attr_function *,int *,void *);
#endif /*WI4MPI_STATIC*/

int PMPI_Type_create_keyval(MPI_Type_copy_attr_function * type_copy_attr_fn,MPI_Type_delete_attr_function * type_delete_attr_fn,int * type_keyval,void * extra_state)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Type_create_keyval( type_copy_attr_fn, type_delete_attr_fn, type_keyval, extra_state);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Type_delete_attr(MPI_Datatype datatype,int type_keyval);
#pragma weak MPI_Type_delete_attr=PMPI_Type_delete_attr
int (*INTERFACE_LOCAL_MPI_Type_delete_attr)(MPI_Datatype,int);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Type_delete_attr(MPI_Datatype,int);
extern int INTERF_2_INTEL_CCMPI_Type_delete_attr(MPI_Datatype,int);
#endif /*WI4MPI_STATIC*/

int PMPI_Type_delete_attr(MPI_Datatype datatype,int type_keyval)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Type_delete_attr( datatype, type_keyval);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Type_dup(MPI_Datatype oldtype,MPI_Datatype * newtype);
#pragma weak MPI_Type_dup=PMPI_Type_dup
int (*INTERFACE_LOCAL_MPI_Type_dup)(MPI_Datatype,MPI_Datatype *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Type_dup(MPI_Datatype,MPI_Datatype *);
extern int INTERF_2_INTEL_CCMPI_Type_dup(MPI_Datatype,MPI_Datatype *);
#endif /*WI4MPI_STATIC*/

int PMPI_Type_dup(MPI_Datatype oldtype,MPI_Datatype * newtype)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Type_dup( oldtype, newtype);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Type_free_keyval(int * type_keyval);
#pragma weak MPI_Type_free_keyval=PMPI_Type_free_keyval
int (*INTERFACE_LOCAL_MPI_Type_free_keyval)(int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Type_free_keyval(int *);
extern int INTERF_2_INTEL_CCMPI_Type_free_keyval(int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Type_free_keyval(int * type_keyval)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Type_free_keyval( type_keyval);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Type_get_attr(MPI_Datatype datatype,int type_keyval,void * attribute_val,int * flag);
#pragma weak MPI_Type_get_attr=PMPI_Type_get_attr
int (*INTERFACE_LOCAL_MPI_Type_get_attr)(MPI_Datatype,int,void *,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Type_get_attr(MPI_Datatype,int,void *,int *);
extern int INTERF_2_INTEL_CCMPI_Type_get_attr(MPI_Datatype,int,void *,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Type_get_attr(MPI_Datatype datatype,int type_keyval,void * attribute_val,int * flag)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Type_get_attr( datatype, type_keyval, attribute_val, flag);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Type_get_envelope(MPI_Datatype datatype,int * num_integers,int * num_addresses,int * num_datatypes,int * combiner);
#pragma weak MPI_Type_get_envelope=PMPI_Type_get_envelope
int (*INTERFACE_LOCAL_MPI_Type_get_envelope)(MPI_Datatype,int *,int *,int *,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Type_get_envelope(MPI_Datatype,int *,int *,int *,int *);
extern int INTERF_2_INTEL_CCMPI_Type_get_envelope(MPI_Datatype,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Type_get_envelope(MPI_Datatype datatype,int * num_integers,int * num_addresses,int * num_datatypes,int * combiner)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Type_get_envelope( datatype, num_integers, num_addresses, num_datatypes, combiner);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Type_get_name(MPI_Datatype datatype,char * type_name,int * resultlen);
#pragma weak MPI_Type_get_name=PMPI_Type_get_name
int (*INTERFACE_LOCAL_MPI_Type_get_name)(MPI_Datatype,char *,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Type_get_name(MPI_Datatype,char *,int *);
extern int INTERF_2_INTEL_CCMPI_Type_get_name(MPI_Datatype,char *,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Type_get_name(MPI_Datatype datatype,char * type_name,int * resultlen)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Type_get_name( datatype, type_name, resultlen);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Type_set_attr(MPI_Datatype datatype,int type_keyval,void * attribute_val);
#pragma weak MPI_Type_set_attr=PMPI_Type_set_attr
int (*INTERFACE_LOCAL_MPI_Type_set_attr)(MPI_Datatype,int,void *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Type_set_attr(MPI_Datatype,int,void *);
extern int INTERF_2_INTEL_CCMPI_Type_set_attr(MPI_Datatype,int,void *);
#endif /*WI4MPI_STATIC*/

int PMPI_Type_set_attr(MPI_Datatype datatype,int type_keyval,void * attribute_val)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Type_set_attr( datatype, type_keyval, attribute_val);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Type_set_name(MPI_Datatype datatype,char * type_name);
#pragma weak MPI_Type_set_name=PMPI_Type_set_name
int (*INTERFACE_LOCAL_MPI_Type_set_name)(MPI_Datatype,char *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Type_set_name(MPI_Datatype,char *);
extern int INTERF_2_INTEL_CCMPI_Type_set_name(MPI_Datatype,char *);
#endif /*WI4MPI_STATIC*/

int PMPI_Type_set_name(MPI_Datatype datatype,char * type_name)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Type_set_name( datatype, type_name);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Type_match_size(int typeclass,int size,MPI_Datatype * datatype);
#pragma weak MPI_Type_match_size=PMPI_Type_match_size
int (*INTERFACE_LOCAL_MPI_Type_match_size)(int,int,MPI_Datatype *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Type_match_size(int,int,MPI_Datatype *);
extern int INTERF_2_INTEL_CCMPI_Type_match_size(int,int,MPI_Datatype *);
#endif /*WI4MPI_STATIC*/

int PMPI_Type_match_size(int typeclass,int size,MPI_Datatype * datatype)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Type_match_size( typeclass, size, datatype);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Win_call_errhandler(MPI_Win win,int errorcode);
#pragma weak MPI_Win_call_errhandler=PMPI_Win_call_errhandler
int (*INTERFACE_LOCAL_MPI_Win_call_errhandler)(MPI_Win,int);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Win_call_errhandler(MPI_Win,int);
extern int INTERF_2_INTEL_CCMPI_Win_call_errhandler(MPI_Win,int);
#endif /*WI4MPI_STATIC*/

int PMPI_Win_call_errhandler(MPI_Win win,int errorcode)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Win_call_errhandler( win, errorcode);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Win_create_keyval(MPI_Win_copy_attr_function * win_copy_attr_fn,MPI_Win_delete_attr_function * win_delete_attr_fn,int * win_keyval,void * extra_state);
#pragma weak MPI_Win_create_keyval=PMPI_Win_create_keyval
int (*INTERFACE_LOCAL_MPI_Win_create_keyval)(MPI_Win_copy_attr_function *,MPI_Win_delete_attr_function *,int *,void *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Win_create_keyval(MPI_Win_copy_attr_function *,MPI_Win_delete_attr_function *,int *,void *);
extern int INTERF_2_INTEL_CCMPI_Win_create_keyval(MPI_Win_copy_attr_function *,MPI_Win_delete_attr_function *,int *,void *);
#endif /*WI4MPI_STATIC*/

int PMPI_Win_create_keyval(MPI_Win_copy_attr_function * win_copy_attr_fn,MPI_Win_delete_attr_function * win_delete_attr_fn,int * win_keyval,void * extra_state)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Win_create_keyval( win_copy_attr_fn, win_delete_attr_fn, win_keyval, extra_state);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Win_delete_attr(MPI_Win win,int win_keyval);
#pragma weak MPI_Win_delete_attr=PMPI_Win_delete_attr
int (*INTERFACE_LOCAL_MPI_Win_delete_attr)(MPI_Win,int);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Win_delete_attr(MPI_Win,int);
extern int INTERF_2_INTEL_CCMPI_Win_delete_attr(MPI_Win,int);
#endif /*WI4MPI_STATIC*/

int PMPI_Win_delete_attr(MPI_Win win,int win_keyval)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Win_delete_attr( win, win_keyval);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Win_free_keyval(int * win_keyval);
#pragma weak MPI_Win_free_keyval=PMPI_Win_free_keyval
int (*INTERFACE_LOCAL_MPI_Win_free_keyval)(int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Win_free_keyval(int *);
extern int INTERF_2_INTEL_CCMPI_Win_free_keyval(int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Win_free_keyval(int * win_keyval)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Win_free_keyval( win_keyval);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Win_get_name(MPI_Win win,char * win_name,int * resultlen);
#pragma weak MPI_Win_get_name=PMPI_Win_get_name
int (*INTERFACE_LOCAL_MPI_Win_get_name)(MPI_Win,char *,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Win_get_name(MPI_Win,char *,int *);
extern int INTERF_2_INTEL_CCMPI_Win_get_name(MPI_Win,char *,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Win_get_name(MPI_Win win,char * win_name,int * resultlen)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Win_get_name( win, win_name, resultlen);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Win_set_name(MPI_Win win,char * win_name);
#pragma weak MPI_Win_set_name=PMPI_Win_set_name
int (*INTERFACE_LOCAL_MPI_Win_set_name)(MPI_Win,char *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Win_set_name(MPI_Win,char *);
extern int INTERF_2_INTEL_CCMPI_Win_set_name(MPI_Win,char *);
#endif /*WI4MPI_STATIC*/

int PMPI_Win_set_name(MPI_Win win,char * win_name)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Win_set_name( win, win_name);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Alloc_mem(MPI_Aint size,MPI_Info info,void * baseptr);
#pragma weak MPI_Alloc_mem=PMPI_Alloc_mem
int (*INTERFACE_LOCAL_MPI_Alloc_mem)(MPI_Aint,MPI_Info,void *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Alloc_mem(MPI_Aint,MPI_Info,void *);
extern int INTERF_2_INTEL_CCMPI_Alloc_mem(MPI_Aint,MPI_Info,void *);
#endif /*WI4MPI_STATIC*/

int PMPI_Alloc_mem(MPI_Aint size,MPI_Info info,void * baseptr)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Alloc_mem( size, info, baseptr);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Comm_create_errhandler(MPI_Comm_errhandler_function * comm_errhandler_fn,MPI_Errhandler * errhandler);
#pragma weak MPI_Comm_create_errhandler=PMPI_Comm_create_errhandler
int (*INTERFACE_LOCAL_MPI_Comm_create_errhandler)(MPI_Comm_errhandler_function *,MPI_Errhandler *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Comm_create_errhandler(MPI_Comm_errhandler_function *,MPI_Errhandler *);
extern int INTERF_2_INTEL_CCMPI_Comm_create_errhandler(MPI_Comm_errhandler_function *,MPI_Errhandler *);
#endif /*WI4MPI_STATIC*/

int PMPI_Comm_create_errhandler(MPI_Comm_errhandler_function * comm_errhandler_fn,MPI_Errhandler * errhandler)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Comm_create_errhandler( comm_errhandler_fn, errhandler);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Comm_get_errhandler(MPI_Comm comm,MPI_Errhandler * errhandler);
#pragma weak MPI_Comm_get_errhandler=PMPI_Comm_get_errhandler
int (*INTERFACE_LOCAL_MPI_Comm_get_errhandler)(MPI_Comm,MPI_Errhandler *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Comm_get_errhandler(MPI_Comm,MPI_Errhandler *);
extern int INTERF_2_INTEL_CCMPI_Comm_get_errhandler(MPI_Comm,MPI_Errhandler *);
#endif /*WI4MPI_STATIC*/

int PMPI_Comm_get_errhandler(MPI_Comm comm,MPI_Errhandler * errhandler)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Comm_get_errhandler( comm, errhandler);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Comm_set_errhandler(MPI_Comm comm,MPI_Errhandler errhandler);
#pragma weak MPI_Comm_set_errhandler=PMPI_Comm_set_errhandler
int (*INTERFACE_LOCAL_MPI_Comm_set_errhandler)(MPI_Comm,MPI_Errhandler);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Comm_set_errhandler(MPI_Comm,MPI_Errhandler);
extern int INTERF_2_INTEL_CCMPI_Comm_set_errhandler(MPI_Comm,MPI_Errhandler);
#endif /*WI4MPI_STATIC*/

int PMPI_Comm_set_errhandler(MPI_Comm comm,MPI_Errhandler errhandler)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Comm_set_errhandler( comm, errhandler);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_create_errhandler(MPI_File_errhandler_function * file_errhandler_fn,MPI_Errhandler * errhandler);
#pragma weak MPI_File_create_errhandler=PMPI_File_create_errhandler
int (*INTERFACE_LOCAL_MPI_File_create_errhandler)(MPI_File_errhandler_function *,MPI_Errhandler *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_create_errhandler(MPI_File_errhandler_function *,MPI_Errhandler *);
extern int INTERF_2_INTEL_CCMPI_File_create_errhandler(MPI_File_errhandler_function *,MPI_Errhandler *);
#endif /*WI4MPI_STATIC*/

int PMPI_File_create_errhandler(MPI_File_errhandler_function * file_errhandler_fn,MPI_Errhandler * errhandler)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_create_errhandler( file_errhandler_fn, errhandler);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_get_errhandler(MPI_File file,MPI_Errhandler * errhandler);
#pragma weak MPI_File_get_errhandler=PMPI_File_get_errhandler
int (*INTERFACE_LOCAL_MPI_File_get_errhandler)(MPI_File,MPI_Errhandler *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_get_errhandler(MPI_File,MPI_Errhandler *);
extern int INTERF_2_INTEL_CCMPI_File_get_errhandler(MPI_File,MPI_Errhandler *);
#endif /*WI4MPI_STATIC*/

int PMPI_File_get_errhandler(MPI_File file,MPI_Errhandler * errhandler)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_get_errhandler( file, errhandler);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_set_errhandler(MPI_File file,MPI_Errhandler errhandler);
#pragma weak MPI_File_set_errhandler=PMPI_File_set_errhandler
int (*INTERFACE_LOCAL_MPI_File_set_errhandler)(MPI_File,MPI_Errhandler);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_set_errhandler(MPI_File,MPI_Errhandler);
extern int INTERF_2_INTEL_CCMPI_File_set_errhandler(MPI_File,MPI_Errhandler);
#endif /*WI4MPI_STATIC*/

int PMPI_File_set_errhandler(MPI_File file,MPI_Errhandler errhandler)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_set_errhandler( file, errhandler);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Finalized(int * flag);
#pragma weak MPI_Finalized=PMPI_Finalized
int (*INTERFACE_LOCAL_MPI_Finalized)(int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Finalized(int *);
extern int INTERF_2_INTEL_CCMPI_Finalized(int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Finalized(int * flag)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Finalized( flag);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Free_mem(void * base);
#pragma weak MPI_Free_mem=PMPI_Free_mem
int (*INTERFACE_LOCAL_MPI_Free_mem)(void *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Free_mem(void *);
extern int INTERF_2_INTEL_CCMPI_Free_mem(void *);
#endif /*WI4MPI_STATIC*/

int PMPI_Free_mem(void * base)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Free_mem( base);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Get_address(void * location,MPI_Aint * address);
#pragma weak MPI_Get_address=PMPI_Get_address
int (*INTERFACE_LOCAL_MPI_Get_address)(void *,MPI_Aint *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Get_address(void *,MPI_Aint *);
extern int INTERF_2_INTEL_CCMPI_Get_address(void *,MPI_Aint *);
#endif /*WI4MPI_STATIC*/

int PMPI_Get_address(void * location,MPI_Aint * address)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Get_address( location, address);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Info_create(MPI_Info * info);
#pragma weak MPI_Info_create=PMPI_Info_create
int (*INTERFACE_LOCAL_MPI_Info_create)(MPI_Info *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Info_create(MPI_Info *);
extern int INTERF_2_INTEL_CCMPI_Info_create(MPI_Info *);
#endif /*WI4MPI_STATIC*/

int PMPI_Info_create(MPI_Info * info)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Info_create( info);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Info_delete(MPI_Info info,char * key);
#pragma weak MPI_Info_delete=PMPI_Info_delete
int (*INTERFACE_LOCAL_MPI_Info_delete)(MPI_Info,char *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Info_delete(MPI_Info,char *);
extern int INTERF_2_INTEL_CCMPI_Info_delete(MPI_Info,char *);
#endif /*WI4MPI_STATIC*/

int PMPI_Info_delete(MPI_Info info,char * key)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Info_delete( info, key);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Info_dup(MPI_Info info,MPI_Info * newinfo);
#pragma weak MPI_Info_dup=PMPI_Info_dup
int (*INTERFACE_LOCAL_MPI_Info_dup)(MPI_Info,MPI_Info *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Info_dup(MPI_Info,MPI_Info *);
extern int INTERF_2_INTEL_CCMPI_Info_dup(MPI_Info,MPI_Info *);
#endif /*WI4MPI_STATIC*/

int PMPI_Info_dup(MPI_Info info,MPI_Info * newinfo)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Info_dup( info, newinfo);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Info_free(MPI_Info * info);
#pragma weak MPI_Info_free=PMPI_Info_free
int (*INTERFACE_LOCAL_MPI_Info_free)(MPI_Info *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Info_free(MPI_Info *);
extern int INTERF_2_INTEL_CCMPI_Info_free(MPI_Info *);
#endif /*WI4MPI_STATIC*/

int PMPI_Info_free(MPI_Info * info)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Info_free( info);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Info_get(MPI_Info info,char * key,int valuelen,char * value,int * flag);
#pragma weak MPI_Info_get=PMPI_Info_get
int (*INTERFACE_LOCAL_MPI_Info_get)(MPI_Info,char *,int,char *,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Info_get(MPI_Info,char *,int,char *,int *);
extern int INTERF_2_INTEL_CCMPI_Info_get(MPI_Info,char *,int,char *,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Info_get(MPI_Info info,char * key,int valuelen,char * value,int * flag)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Info_get( info, key, valuelen, value, flag);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Info_get_nkeys(MPI_Info info,int * nkeys);
#pragma weak MPI_Info_get_nkeys=PMPI_Info_get_nkeys
int (*INTERFACE_LOCAL_MPI_Info_get_nkeys)(MPI_Info,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Info_get_nkeys(MPI_Info,int *);
extern int INTERF_2_INTEL_CCMPI_Info_get_nkeys(MPI_Info,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Info_get_nkeys(MPI_Info info,int * nkeys)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Info_get_nkeys( info, nkeys);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Info_get_nthkey(MPI_Info info,int n,char * key);
#pragma weak MPI_Info_get_nthkey=PMPI_Info_get_nthkey
int (*INTERFACE_LOCAL_MPI_Info_get_nthkey)(MPI_Info,int,char *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Info_get_nthkey(MPI_Info,int,char *);
extern int INTERF_2_INTEL_CCMPI_Info_get_nthkey(MPI_Info,int,char *);
#endif /*WI4MPI_STATIC*/

int PMPI_Info_get_nthkey(MPI_Info info,int n,char * key)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Info_get_nthkey( info, n, key);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Info_get_valuelen(MPI_Info info,char * key,int * valuelen,int * flag);
#pragma weak MPI_Info_get_valuelen=PMPI_Info_get_valuelen
int (*INTERFACE_LOCAL_MPI_Info_get_valuelen)(MPI_Info,char *,int *,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Info_get_valuelen(MPI_Info,char *,int *,int *);
extern int INTERF_2_INTEL_CCMPI_Info_get_valuelen(MPI_Info,char *,int *,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Info_get_valuelen(MPI_Info info,char * key,int * valuelen,int * flag)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Info_get_valuelen( info, key, valuelen, flag);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Info_set(MPI_Info info,char * key,char * value);
#pragma weak MPI_Info_set=PMPI_Info_set
int (*INTERFACE_LOCAL_MPI_Info_set)(MPI_Info,char *,char *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Info_set(MPI_Info,char *,char *);
extern int INTERF_2_INTEL_CCMPI_Info_set(MPI_Info,char *,char *);
#endif /*WI4MPI_STATIC*/

int PMPI_Info_set(MPI_Info info,char * key,char * value)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Info_set( info, key, value);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Request_get_status(MPI_Request request,int * flag,MPI_Status * status);
#pragma weak MPI_Request_get_status=PMPI_Request_get_status
int (*INTERFACE_LOCAL_MPI_Request_get_status)(MPI_Request,int *,MPI_Status *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Request_get_status(MPI_Request,int *,MPI_Status *);
extern int INTERF_2_INTEL_CCMPI_Request_get_status(MPI_Request,int *,MPI_Status *);
#endif /*WI4MPI_STATIC*/

int PMPI_Request_get_status(MPI_Request request,int * flag,MPI_Status * status)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Request_get_status( request, flag, status);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Type_create_hvector(int count,int blocklength,MPI_Aint stride,MPI_Datatype oldtype,MPI_Datatype * newtype);
#pragma weak MPI_Type_create_hvector=PMPI_Type_create_hvector
int (*INTERFACE_LOCAL_MPI_Type_create_hvector)(int,int,MPI_Aint,MPI_Datatype,MPI_Datatype *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Type_create_hvector(int,int,MPI_Aint,MPI_Datatype,MPI_Datatype *);
extern int INTERF_2_INTEL_CCMPI_Type_create_hvector(int,int,MPI_Aint,MPI_Datatype,MPI_Datatype *);
#endif /*WI4MPI_STATIC*/

int PMPI_Type_create_hvector(int count,int blocklength,MPI_Aint stride,MPI_Datatype oldtype,MPI_Datatype * newtype)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Type_create_hvector( count, blocklength, stride, oldtype, newtype);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Type_create_resized(MPI_Datatype oldtype,MPI_Aint lb,MPI_Aint extent,MPI_Datatype * newtype);
#pragma weak MPI_Type_create_resized=PMPI_Type_create_resized
int (*INTERFACE_LOCAL_MPI_Type_create_resized)(MPI_Datatype,MPI_Aint,MPI_Aint,MPI_Datatype *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Type_create_resized(MPI_Datatype,MPI_Aint,MPI_Aint,MPI_Datatype *);
extern int INTERF_2_INTEL_CCMPI_Type_create_resized(MPI_Datatype,MPI_Aint,MPI_Aint,MPI_Datatype *);
#endif /*WI4MPI_STATIC*/

int PMPI_Type_create_resized(MPI_Datatype oldtype,MPI_Aint lb,MPI_Aint extent,MPI_Datatype * newtype)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Type_create_resized( oldtype, lb, extent, newtype);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Type_get_extent(MPI_Datatype datatype,MPI_Aint * lb,MPI_Aint * extent);
#pragma weak MPI_Type_get_extent=PMPI_Type_get_extent
int (*INTERFACE_LOCAL_MPI_Type_get_extent)(MPI_Datatype,MPI_Aint *,MPI_Aint *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Type_get_extent(MPI_Datatype,MPI_Aint *,MPI_Aint *);
extern int INTERF_2_INTEL_CCMPI_Type_get_extent(MPI_Datatype,MPI_Aint *,MPI_Aint *);
#endif /*WI4MPI_STATIC*/

int PMPI_Type_get_extent(MPI_Datatype datatype,MPI_Aint * lb,MPI_Aint * extent)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Type_get_extent( datatype, lb, extent);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Type_get_true_extent(MPI_Datatype datatype,MPI_Aint * true_lb,MPI_Aint * true_extent);
#pragma weak MPI_Type_get_true_extent=PMPI_Type_get_true_extent
int (*INTERFACE_LOCAL_MPI_Type_get_true_extent)(MPI_Datatype,MPI_Aint *,MPI_Aint *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Type_get_true_extent(MPI_Datatype,MPI_Aint *,MPI_Aint *);
extern int INTERF_2_INTEL_CCMPI_Type_get_true_extent(MPI_Datatype,MPI_Aint *,MPI_Aint *);
#endif /*WI4MPI_STATIC*/

int PMPI_Type_get_true_extent(MPI_Datatype datatype,MPI_Aint * true_lb,MPI_Aint * true_extent)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Type_get_true_extent( datatype, true_lb, true_extent);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Win_create_errhandler(MPI_Win_errhandler_function * win_errhandler_fn,MPI_Errhandler * errhandler);
#pragma weak MPI_Win_create_errhandler=PMPI_Win_create_errhandler
int (*INTERFACE_LOCAL_MPI_Win_create_errhandler)(MPI_Win_errhandler_function *,MPI_Errhandler *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Win_create_errhandler(MPI_Win_errhandler_function *,MPI_Errhandler *);
extern int INTERF_2_INTEL_CCMPI_Win_create_errhandler(MPI_Win_errhandler_function *,MPI_Errhandler *);
#endif /*WI4MPI_STATIC*/

int PMPI_Win_create_errhandler(MPI_Win_errhandler_function * win_errhandler_fn,MPI_Errhandler * errhandler)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Win_create_errhandler( win_errhandler_fn, errhandler);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Win_get_errhandler(MPI_Win win,MPI_Errhandler * errhandler);
#pragma weak MPI_Win_get_errhandler=PMPI_Win_get_errhandler
int (*INTERFACE_LOCAL_MPI_Win_get_errhandler)(MPI_Win,MPI_Errhandler *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Win_get_errhandler(MPI_Win,MPI_Errhandler *);
extern int INTERF_2_INTEL_CCMPI_Win_get_errhandler(MPI_Win,MPI_Errhandler *);
#endif /*WI4MPI_STATIC*/

int PMPI_Win_get_errhandler(MPI_Win win,MPI_Errhandler * errhandler)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Win_get_errhandler( win, errhandler);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Win_set_errhandler(MPI_Win win,MPI_Errhandler errhandler);
#pragma weak MPI_Win_set_errhandler=PMPI_Win_set_errhandler
int (*INTERFACE_LOCAL_MPI_Win_set_errhandler)(MPI_Win,MPI_Errhandler);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Win_set_errhandler(MPI_Win,MPI_Errhandler);
extern int INTERF_2_INTEL_CCMPI_Win_set_errhandler(MPI_Win,MPI_Errhandler);
#endif /*WI4MPI_STATIC*/

int PMPI_Win_set_errhandler(MPI_Win win,MPI_Errhandler errhandler)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Win_set_errhandler( win, errhandler);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Type_create_f90_integer(int range,MPI_Datatype * newtype);
#pragma weak MPI_Type_create_f90_integer=PMPI_Type_create_f90_integer
int (*INTERFACE_LOCAL_MPI_Type_create_f90_integer)(int,MPI_Datatype *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Type_create_f90_integer(int,MPI_Datatype *);
extern int INTERF_2_INTEL_CCMPI_Type_create_f90_integer(int,MPI_Datatype *);
#endif /*WI4MPI_STATIC*/

int PMPI_Type_create_f90_integer(int range,MPI_Datatype * newtype)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Type_create_f90_integer( range, newtype);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Type_create_f90_real(int precision,int range,MPI_Datatype * newtype);
#pragma weak MPI_Type_create_f90_real=PMPI_Type_create_f90_real
int (*INTERFACE_LOCAL_MPI_Type_create_f90_real)(int,int,MPI_Datatype *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Type_create_f90_real(int,int,MPI_Datatype *);
extern int INTERF_2_INTEL_CCMPI_Type_create_f90_real(int,int,MPI_Datatype *);
#endif /*WI4MPI_STATIC*/

int PMPI_Type_create_f90_real(int precision,int range,MPI_Datatype * newtype)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Type_create_f90_real( precision, range, newtype);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Type_create_f90_complex(int precision,int range,MPI_Datatype * newtype);
#pragma weak MPI_Type_create_f90_complex=PMPI_Type_create_f90_complex
int (*INTERFACE_LOCAL_MPI_Type_create_f90_complex)(int,int,MPI_Datatype *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Type_create_f90_complex(int,int,MPI_Datatype *);
extern int INTERF_2_INTEL_CCMPI_Type_create_f90_complex(int,int,MPI_Datatype *);
#endif /*WI4MPI_STATIC*/

int PMPI_Type_create_f90_complex(int precision,int range,MPI_Datatype * newtype)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Type_create_f90_complex( precision, range, newtype);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Reduce_local(void * inbuf,void * inoutbuf,int count,MPI_Datatype datatype,MPI_Op op);
#pragma weak MPI_Reduce_local=PMPI_Reduce_local
int (*INTERFACE_LOCAL_MPI_Reduce_local)(void *,void *,int,MPI_Datatype,MPI_Op);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Reduce_local(void *,void *,int,MPI_Datatype,MPI_Op);
extern int INTERF_2_INTEL_CCMPI_Reduce_local(void *,void *,int,MPI_Datatype,MPI_Op);
#endif /*WI4MPI_STATIC*/

int PMPI_Reduce_local(void * inbuf,void * inoutbuf,int count,MPI_Datatype datatype,MPI_Op op)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Reduce_local( inbuf, inoutbuf, count, datatype, op);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Op_commutative(MPI_Op op,int * commute);
#pragma weak MPI_Op_commutative=PMPI_Op_commutative
int (*INTERFACE_LOCAL_MPI_Op_commutative)(MPI_Op,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Op_commutative(MPI_Op,int *);
extern int INTERF_2_INTEL_CCMPI_Op_commutative(MPI_Op,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Op_commutative(MPI_Op op,int * commute)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Op_commutative( op, commute);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Reduce_scatter_block(void * sendbuf,void * recvbuf,int recvcount,MPI_Datatype datatype,MPI_Op op,MPI_Comm comm);
#pragma weak MPI_Reduce_scatter_block=PMPI_Reduce_scatter_block
int (*INTERFACE_LOCAL_MPI_Reduce_scatter_block)(void *,void *,int,MPI_Datatype,MPI_Op,MPI_Comm);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Reduce_scatter_block(void *,void *,int,MPI_Datatype,MPI_Op,MPI_Comm);
extern int INTERF_2_INTEL_CCMPI_Reduce_scatter_block(void *,void *,int,MPI_Datatype,MPI_Op,MPI_Comm);
#endif /*WI4MPI_STATIC*/

int PMPI_Reduce_scatter_block(void * sendbuf,void * recvbuf,int recvcount,MPI_Datatype datatype,MPI_Op op,MPI_Comm comm)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Reduce_scatter_block( sendbuf, recvbuf, recvcount, datatype, op, comm);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Dist_graph_neighbors_count(MPI_Comm comm,int * indegree,int * outdegree,int * weighted);
#pragma weak MPI_Dist_graph_neighbors_count=PMPI_Dist_graph_neighbors_count
int (*INTERFACE_LOCAL_MPI_Dist_graph_neighbors_count)(MPI_Comm,int *,int *,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Dist_graph_neighbors_count(MPI_Comm,int *,int *,int *);
extern int INTERF_2_INTEL_CCMPI_Dist_graph_neighbors_count(MPI_Comm,int *,int *,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Dist_graph_neighbors_count(MPI_Comm comm,int * indegree,int * outdegree,int * weighted)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Dist_graph_neighbors_count( comm, indegree, outdegree, weighted);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Status_c2f(MPI_Status * c_status,MPI_Fint * f_status);
#pragma weak MPI_Status_c2f=PMPI_Status_c2f
int (*INTERFACE_LOCAL_MPI_Status_c2f)(MPI_Status *,MPI_Fint *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Status_c2f(MPI_Status *,MPI_Fint *);
extern int INTERF_2_INTEL_CCMPI_Status_c2f(MPI_Status *,MPI_Fint *);
#endif /*WI4MPI_STATIC*/

int PMPI_Status_c2f(MPI_Status * c_status,MPI_Fint * f_status)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Status_c2f( c_status, f_status);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Status_f2c(MPI_Fint * f_status,MPI_Status * c_status);
#pragma weak MPI_Status_f2c=PMPI_Status_f2c
int (*INTERFACE_LOCAL_MPI_Status_f2c)(MPI_Fint *,MPI_Status *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Status_f2c(MPI_Fint *,MPI_Status *);
extern int INTERF_2_INTEL_CCMPI_Status_f2c(MPI_Fint *,MPI_Status *);
#endif /*WI4MPI_STATIC*/

int PMPI_Status_f2c(MPI_Fint * f_status,MPI_Status * c_status)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Status_f2c( f_status, c_status);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Improbe(int source,int tag,MPI_Comm comm,int * flag,MPI_Message * message,MPI_Status * status);
#pragma weak MPI_Improbe=PMPI_Improbe
int (*INTERFACE_LOCAL_MPI_Improbe)(int,int,MPI_Comm,int *,MPI_Message *,MPI_Status *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Improbe(int,int,MPI_Comm,int *,MPI_Message *,MPI_Status *);
extern int INTERF_2_INTEL_CCMPI_Improbe(int,int,MPI_Comm,int *,MPI_Message *,MPI_Status *);
#endif /*WI4MPI_STATIC*/

int PMPI_Improbe(int source,int tag,MPI_Comm comm,int * flag,MPI_Message * message,MPI_Status * status)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Improbe( source, tag, comm, flag, message, status);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Imrecv(void * buf,int count,MPI_Datatype datatype,MPI_Message * message,MPI_Request * request);
#pragma weak MPI_Imrecv=PMPI_Imrecv
int (*INTERFACE_LOCAL_MPI_Imrecv)(void *,int,MPI_Datatype,MPI_Message *,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Imrecv(void *,int,MPI_Datatype,MPI_Message *,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Imrecv(void *,int,MPI_Datatype,MPI_Message *,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Imrecv(void * buf,int count,MPI_Datatype datatype,MPI_Message * message,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Imrecv( buf, count, datatype, message, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Mprobe(int source,int tag,MPI_Comm comm,MPI_Message * message,MPI_Status * status);
#pragma weak MPI_Mprobe=PMPI_Mprobe
int (*INTERFACE_LOCAL_MPI_Mprobe)(int,int,MPI_Comm,MPI_Message *,MPI_Status *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Mprobe(int,int,MPI_Comm,MPI_Message *,MPI_Status *);
extern int INTERF_2_INTEL_CCMPI_Mprobe(int,int,MPI_Comm,MPI_Message *,MPI_Status *);
#endif /*WI4MPI_STATIC*/

int PMPI_Mprobe(int source,int tag,MPI_Comm comm,MPI_Message * message,MPI_Status * status)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Mprobe( source, tag, comm, message, status);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Mrecv(void * buf,int count,MPI_Datatype datatype,MPI_Message * message,MPI_Status * status);
#pragma weak MPI_Mrecv=PMPI_Mrecv
int (*INTERFACE_LOCAL_MPI_Mrecv)(void *,int,MPI_Datatype,MPI_Message *,MPI_Status *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Mrecv(void *,int,MPI_Datatype,MPI_Message *,MPI_Status *);
extern int INTERF_2_INTEL_CCMPI_Mrecv(void *,int,MPI_Datatype,MPI_Message *,MPI_Status *);
#endif /*WI4MPI_STATIC*/

int PMPI_Mrecv(void * buf,int count,MPI_Datatype datatype,MPI_Message * message,MPI_Status * status)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Mrecv( buf, count, datatype, message, status);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Comm_idup(MPI_Comm comm,MPI_Comm * newcomm,MPI_Request * request);
#pragma weak MPI_Comm_idup=PMPI_Comm_idup
int (*INTERFACE_LOCAL_MPI_Comm_idup)(MPI_Comm,MPI_Comm *,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Comm_idup(MPI_Comm,MPI_Comm *,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Comm_idup(MPI_Comm,MPI_Comm *,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Comm_idup(MPI_Comm comm,MPI_Comm * newcomm,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Comm_idup( comm, newcomm, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Ibarrier(MPI_Comm comm,MPI_Request * request);
#pragma weak MPI_Ibarrier=PMPI_Ibarrier
int (*INTERFACE_LOCAL_MPI_Ibarrier)(MPI_Comm,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Ibarrier(MPI_Comm,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Ibarrier(MPI_Comm,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Ibarrier(MPI_Comm comm,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Ibarrier( comm, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Ibcast(void * buffer,int count,MPI_Datatype datatype,int root,MPI_Comm comm,MPI_Request * request);
#pragma weak MPI_Ibcast=PMPI_Ibcast
int (*INTERFACE_LOCAL_MPI_Ibcast)(void *,int,MPI_Datatype,int,MPI_Comm,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Ibcast(void *,int,MPI_Datatype,int,MPI_Comm,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Ibcast(void *,int,MPI_Datatype,int,MPI_Comm,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Ibcast(void * buffer,int count,MPI_Datatype datatype,int root,MPI_Comm comm,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Ibcast( buffer, count, datatype, root, comm, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Igather(void * sendbuf,int sendcount,MPI_Datatype sendtype,void * recvbuf,int recvcount,MPI_Datatype recvtype,int root,MPI_Comm comm,MPI_Request * request);
#pragma weak MPI_Igather=PMPI_Igather
int (*INTERFACE_LOCAL_MPI_Igather)(void *,int,MPI_Datatype,void *,int,MPI_Datatype,int,MPI_Comm,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Igather(void *,int,MPI_Datatype,void *,int,MPI_Datatype,int,MPI_Comm,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Igather(void *,int,MPI_Datatype,void *,int,MPI_Datatype,int,MPI_Comm,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Igather(void * sendbuf,int sendcount,MPI_Datatype sendtype,void * recvbuf,int recvcount,MPI_Datatype recvtype,int root,MPI_Comm comm,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Igather( sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Iscatter(void * sendbuf,int sendcount,MPI_Datatype sendtype,void * recvbuf,int recvcount,MPI_Datatype recvtype,int root,MPI_Comm comm,MPI_Request * request);
#pragma weak MPI_Iscatter=PMPI_Iscatter
int (*INTERFACE_LOCAL_MPI_Iscatter)(void *,int,MPI_Datatype,void *,int,MPI_Datatype,int,MPI_Comm,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Iscatter(void *,int,MPI_Datatype,void *,int,MPI_Datatype,int,MPI_Comm,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Iscatter(void *,int,MPI_Datatype,void *,int,MPI_Datatype,int,MPI_Comm,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Iscatter(void * sendbuf,int sendcount,MPI_Datatype sendtype,void * recvbuf,int recvcount,MPI_Datatype recvtype,int root,MPI_Comm comm,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Iscatter( sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Iallgather(void * sendbuf,int sendcount,MPI_Datatype sendtype,void * recvbuf,int recvcount,MPI_Datatype recvtype,MPI_Comm comm,MPI_Request * request);
#pragma weak MPI_Iallgather=PMPI_Iallgather
int (*INTERFACE_LOCAL_MPI_Iallgather)(void *,int,MPI_Datatype,void *,int,MPI_Datatype,MPI_Comm,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Iallgather(void *,int,MPI_Datatype,void *,int,MPI_Datatype,MPI_Comm,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Iallgather(void *,int,MPI_Datatype,void *,int,MPI_Datatype,MPI_Comm,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Iallgather(void * sendbuf,int sendcount,MPI_Datatype sendtype,void * recvbuf,int recvcount,MPI_Datatype recvtype,MPI_Comm comm,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Iallgather( sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Ialltoall(void * sendbuf,int sendcount,MPI_Datatype sendtype,void * recvbuf,int recvcount,MPI_Datatype recvtype,MPI_Comm comm,MPI_Request * request);
#pragma weak MPI_Ialltoall=PMPI_Ialltoall
int (*INTERFACE_LOCAL_MPI_Ialltoall)(void *,int,MPI_Datatype,void *,int,MPI_Datatype,MPI_Comm,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Ialltoall(void *,int,MPI_Datatype,void *,int,MPI_Datatype,MPI_Comm,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Ialltoall(void *,int,MPI_Datatype,void *,int,MPI_Datatype,MPI_Comm,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Ialltoall(void * sendbuf,int sendcount,MPI_Datatype sendtype,void * recvbuf,int recvcount,MPI_Datatype recvtype,MPI_Comm comm,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Ialltoall( sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Ireduce(void * sendbuf,void * recvbuf,int count,MPI_Datatype datatype,MPI_Op op,int root,MPI_Comm comm,MPI_Request * request);
#pragma weak MPI_Ireduce=PMPI_Ireduce
int (*INTERFACE_LOCAL_MPI_Ireduce)(void *,void *,int,MPI_Datatype,MPI_Op,int,MPI_Comm,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Ireduce(void *,void *,int,MPI_Datatype,MPI_Op,int,MPI_Comm,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Ireduce(void *,void *,int,MPI_Datatype,MPI_Op,int,MPI_Comm,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Ireduce(void * sendbuf,void * recvbuf,int count,MPI_Datatype datatype,MPI_Op op,int root,MPI_Comm comm,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Ireduce( sendbuf, recvbuf, count, datatype, op, root, comm, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Iallreduce(void * sendbuf,void * recvbuf,int count,MPI_Datatype datatype,MPI_Op op,MPI_Comm comm,MPI_Request * request);
#pragma weak MPI_Iallreduce=PMPI_Iallreduce
int (*INTERFACE_LOCAL_MPI_Iallreduce)(void *,void *,int,MPI_Datatype,MPI_Op,MPI_Comm,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Iallreduce(void *,void *,int,MPI_Datatype,MPI_Op,MPI_Comm,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Iallreduce(void *,void *,int,MPI_Datatype,MPI_Op,MPI_Comm,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Iallreduce(void * sendbuf,void * recvbuf,int count,MPI_Datatype datatype,MPI_Op op,MPI_Comm comm,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Iallreduce( sendbuf, recvbuf, count, datatype, op, comm, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Ireduce_scatter_block(void * sendbuf,void * recvbuf,int recvcount,MPI_Datatype datatype,MPI_Op op,MPI_Comm comm,MPI_Request * request);
#pragma weak MPI_Ireduce_scatter_block=PMPI_Ireduce_scatter_block
int (*INTERFACE_LOCAL_MPI_Ireduce_scatter_block)(void *,void *,int,MPI_Datatype,MPI_Op,MPI_Comm,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Ireduce_scatter_block(void *,void *,int,MPI_Datatype,MPI_Op,MPI_Comm,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Ireduce_scatter_block(void *,void *,int,MPI_Datatype,MPI_Op,MPI_Comm,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Ireduce_scatter_block(void * sendbuf,void * recvbuf,int recvcount,MPI_Datatype datatype,MPI_Op op,MPI_Comm comm,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Ireduce_scatter_block( sendbuf, recvbuf, recvcount, datatype, op, comm, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Iscan(void * sendbuf,void * recvbuf,int count,MPI_Datatype datatype,MPI_Op op,MPI_Comm comm,MPI_Request * request);
#pragma weak MPI_Iscan=PMPI_Iscan
int (*INTERFACE_LOCAL_MPI_Iscan)(void *,void *,int,MPI_Datatype,MPI_Op,MPI_Comm,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Iscan(void *,void *,int,MPI_Datatype,MPI_Op,MPI_Comm,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Iscan(void *,void *,int,MPI_Datatype,MPI_Op,MPI_Comm,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Iscan(void * sendbuf,void * recvbuf,int count,MPI_Datatype datatype,MPI_Op op,MPI_Comm comm,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Iscan( sendbuf, recvbuf, count, datatype, op, comm, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Iexscan(void * sendbuf,void * recvbuf,int count,MPI_Datatype datatype,MPI_Op op,MPI_Comm comm,MPI_Request * request);
#pragma weak MPI_Iexscan=PMPI_Iexscan
int (*INTERFACE_LOCAL_MPI_Iexscan)(void *,void *,int,MPI_Datatype,MPI_Op,MPI_Comm,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Iexscan(void *,void *,int,MPI_Datatype,MPI_Op,MPI_Comm,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Iexscan(void *,void *,int,MPI_Datatype,MPI_Op,MPI_Comm,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Iexscan(void * sendbuf,void * recvbuf,int count,MPI_Datatype datatype,MPI_Op op,MPI_Comm comm,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Iexscan( sendbuf, recvbuf, count, datatype, op, comm, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Ineighbor_allgather(void * sendbuf,int sendcount,MPI_Datatype sendtype,void * recvbuf,int recvcount,MPI_Datatype recvtype,MPI_Comm comm,MPI_Request * request);
#pragma weak MPI_Ineighbor_allgather=PMPI_Ineighbor_allgather
int (*INTERFACE_LOCAL_MPI_Ineighbor_allgather)(void *,int,MPI_Datatype,void *,int,MPI_Datatype,MPI_Comm,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Ineighbor_allgather(void *,int,MPI_Datatype,void *,int,MPI_Datatype,MPI_Comm,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Ineighbor_allgather(void *,int,MPI_Datatype,void *,int,MPI_Datatype,MPI_Comm,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Ineighbor_allgather(void * sendbuf,int sendcount,MPI_Datatype sendtype,void * recvbuf,int recvcount,MPI_Datatype recvtype,MPI_Comm comm,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Ineighbor_allgather( sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Ineighbor_alltoall(void * sendbuf,int sendcount,MPI_Datatype sendtype,void * recvbuf,int recvcount,MPI_Datatype recvtype,MPI_Comm comm,MPI_Request * request);
#pragma weak MPI_Ineighbor_alltoall=PMPI_Ineighbor_alltoall
int (*INTERFACE_LOCAL_MPI_Ineighbor_alltoall)(void *,int,MPI_Datatype,void *,int,MPI_Datatype,MPI_Comm,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Ineighbor_alltoall(void *,int,MPI_Datatype,void *,int,MPI_Datatype,MPI_Comm,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Ineighbor_alltoall(void *,int,MPI_Datatype,void *,int,MPI_Datatype,MPI_Comm,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Ineighbor_alltoall(void * sendbuf,int sendcount,MPI_Datatype sendtype,void * recvbuf,int recvcount,MPI_Datatype recvtype,MPI_Comm comm,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Ineighbor_alltoall( sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Neighbor_allgather(void * sendbuf,int sendcount,MPI_Datatype sendtype,void * recvbuf,int recvcount,MPI_Datatype recvtype,MPI_Comm comm);
#pragma weak MPI_Neighbor_allgather=PMPI_Neighbor_allgather
int (*INTERFACE_LOCAL_MPI_Neighbor_allgather)(void *,int,MPI_Datatype,void *,int,MPI_Datatype,MPI_Comm);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Neighbor_allgather(void *,int,MPI_Datatype,void *,int,MPI_Datatype,MPI_Comm);
extern int INTERF_2_INTEL_CCMPI_Neighbor_allgather(void *,int,MPI_Datatype,void *,int,MPI_Datatype,MPI_Comm);
#endif /*WI4MPI_STATIC*/

int PMPI_Neighbor_allgather(void * sendbuf,int sendcount,MPI_Datatype sendtype,void * recvbuf,int recvcount,MPI_Datatype recvtype,MPI_Comm comm)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Neighbor_allgather( sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Neighbor_alltoall(void * sendbuf,int sendcount,MPI_Datatype sendtype,void * recvbuf,int recvcount,MPI_Datatype recvtype,MPI_Comm comm);
#pragma weak MPI_Neighbor_alltoall=PMPI_Neighbor_alltoall
int (*INTERFACE_LOCAL_MPI_Neighbor_alltoall)(void *,int,MPI_Datatype,void *,int,MPI_Datatype,MPI_Comm);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Neighbor_alltoall(void *,int,MPI_Datatype,void *,int,MPI_Datatype,MPI_Comm);
extern int INTERF_2_INTEL_CCMPI_Neighbor_alltoall(void *,int,MPI_Datatype,void *,int,MPI_Datatype,MPI_Comm);
#endif /*WI4MPI_STATIC*/

int PMPI_Neighbor_alltoall(void * sendbuf,int sendcount,MPI_Datatype sendtype,void * recvbuf,int recvcount,MPI_Datatype recvtype,MPI_Comm comm)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Neighbor_alltoall( sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Comm_split_type(MPI_Comm comm,int split_type,int key,MPI_Info info,MPI_Comm * newcomm);
#pragma weak MPI_Comm_split_type=PMPI_Comm_split_type
int (*INTERFACE_LOCAL_MPI_Comm_split_type)(MPI_Comm,int,int,MPI_Info,MPI_Comm *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Comm_split_type(MPI_Comm,int,int,MPI_Info,MPI_Comm *);
extern int INTERF_2_INTEL_CCMPI_Comm_split_type(MPI_Comm,int,int,MPI_Info,MPI_Comm *);
#endif /*WI4MPI_STATIC*/

int PMPI_Comm_split_type(MPI_Comm comm,int split_type,int key,MPI_Info info,MPI_Comm * newcomm)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Comm_split_type( comm, split_type, key, info, newcomm);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Get_elements_x(MPI_Status * status,MPI_Datatype datatype,MPI_Count * count);
#pragma weak MPI_Get_elements_x=PMPI_Get_elements_x
int (*INTERFACE_LOCAL_MPI_Get_elements_x)(MPI_Status *,MPI_Datatype,MPI_Count *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Get_elements_x(MPI_Status *,MPI_Datatype,MPI_Count *);
extern int INTERF_2_INTEL_CCMPI_Get_elements_x(MPI_Status *,MPI_Datatype,MPI_Count *);
#endif /*WI4MPI_STATIC*/

int PMPI_Get_elements_x(MPI_Status * status,MPI_Datatype datatype,MPI_Count * count)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Get_elements_x( status, datatype, count);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Status_set_elements_x(MPI_Status * status,MPI_Datatype datatype,MPI_Count count);
#pragma weak MPI_Status_set_elements_x=PMPI_Status_set_elements_x
int (*INTERFACE_LOCAL_MPI_Status_set_elements_x)(MPI_Status *,MPI_Datatype,MPI_Count);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Status_set_elements_x(MPI_Status *,MPI_Datatype,MPI_Count);
extern int INTERF_2_INTEL_CCMPI_Status_set_elements_x(MPI_Status *,MPI_Datatype,MPI_Count);
#endif /*WI4MPI_STATIC*/

int PMPI_Status_set_elements_x(MPI_Status * status,MPI_Datatype datatype,MPI_Count count)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Status_set_elements_x( status, datatype, count);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Type_get_extent_x(MPI_Datatype datatype,MPI_Count * lb,MPI_Count * extent);
#pragma weak MPI_Type_get_extent_x=PMPI_Type_get_extent_x
int (*INTERFACE_LOCAL_MPI_Type_get_extent_x)(MPI_Datatype,MPI_Count *,MPI_Count *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Type_get_extent_x(MPI_Datatype,MPI_Count *,MPI_Count *);
extern int INTERF_2_INTEL_CCMPI_Type_get_extent_x(MPI_Datatype,MPI_Count *,MPI_Count *);
#endif /*WI4MPI_STATIC*/

int PMPI_Type_get_extent_x(MPI_Datatype datatype,MPI_Count * lb,MPI_Count * extent)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Type_get_extent_x( datatype, lb, extent);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Type_get_true_extent_x(MPI_Datatype datatype,MPI_Count * lb,MPI_Count * extent);
#pragma weak MPI_Type_get_true_extent_x=PMPI_Type_get_true_extent_x
int (*INTERFACE_LOCAL_MPI_Type_get_true_extent_x)(MPI_Datatype,MPI_Count *,MPI_Count *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Type_get_true_extent_x(MPI_Datatype,MPI_Count *,MPI_Count *);
extern int INTERF_2_INTEL_CCMPI_Type_get_true_extent_x(MPI_Datatype,MPI_Count *,MPI_Count *);
#endif /*WI4MPI_STATIC*/

int PMPI_Type_get_true_extent_x(MPI_Datatype datatype,MPI_Count * lb,MPI_Count * extent)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Type_get_true_extent_x( datatype, lb, extent);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Type_size_x(MPI_Datatype datatype,MPI_Count * size);
#pragma weak MPI_Type_size_x=PMPI_Type_size_x
int (*INTERFACE_LOCAL_MPI_Type_size_x)(MPI_Datatype,MPI_Count *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Type_size_x(MPI_Datatype,MPI_Count *);
extern int INTERF_2_INTEL_CCMPI_Type_size_x(MPI_Datatype,MPI_Count *);
#endif /*WI4MPI_STATIC*/

int PMPI_Type_size_x(MPI_Datatype datatype,MPI_Count * size)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Type_size_x( datatype, size);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Comm_create_group(MPI_Comm comm,MPI_Group group,int tag,MPI_Comm * newcomm);
#pragma weak MPI_Comm_create_group=PMPI_Comm_create_group
int (*INTERFACE_LOCAL_MPI_Comm_create_group)(MPI_Comm,MPI_Group,int,MPI_Comm *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Comm_create_group(MPI_Comm,MPI_Group,int,MPI_Comm *);
extern int INTERF_2_INTEL_CCMPI_Comm_create_group(MPI_Comm,MPI_Group,int,MPI_Comm *);
#endif /*WI4MPI_STATIC*/

int PMPI_Comm_create_group(MPI_Comm comm,MPI_Group group,int tag,MPI_Comm * newcomm)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Comm_create_group( comm, group, tag, newcomm);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_T_init_thread(int required,int * provided);
#pragma weak MPI_T_init_thread=PMPI_T_init_thread
int (*INTERFACE_LOCAL_MPI_T_init_thread)(int,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_T_init_thread(int,int *);
extern int INTERF_2_INTEL_CCMPI_T_init_thread(int,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_T_init_thread(int required,int * provided)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_T_init_thread( required, provided);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_T_enum_get_info(MPI_T_enum enumtype,int * num,char * name,int * name_len);
#pragma weak MPI_T_enum_get_info=PMPI_T_enum_get_info
int (*INTERFACE_LOCAL_MPI_T_enum_get_info)(MPI_T_enum,int *,char *,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_T_enum_get_info(MPI_T_enum,int *,char *,int *);
extern int INTERF_2_INTEL_CCMPI_T_enum_get_info(MPI_T_enum,int *,char *,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_T_enum_get_info(MPI_T_enum enumtype,int * num,char * name,int * name_len)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_T_enum_get_info( enumtype, num, name, name_len);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_T_enum_get_item(MPI_T_enum enumtype,int indx,int * value,char * name,int * name_len);
#pragma weak MPI_T_enum_get_item=PMPI_T_enum_get_item
int (*INTERFACE_LOCAL_MPI_T_enum_get_item)(MPI_T_enum,int,int *,char *,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_T_enum_get_item(MPI_T_enum,int,int *,char *,int *);
extern int INTERF_2_INTEL_CCMPI_T_enum_get_item(MPI_T_enum,int,int *,char *,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_T_enum_get_item(MPI_T_enum enumtype,int indx,int * value,char * name,int * name_len)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_T_enum_get_item( enumtype, indx, value, name, name_len);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_T_cvar_get_num(int * num_cvar);
#pragma weak MPI_T_cvar_get_num=PMPI_T_cvar_get_num
int (*INTERFACE_LOCAL_MPI_T_cvar_get_num)(int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_T_cvar_get_num(int *);
extern int INTERF_2_INTEL_CCMPI_T_cvar_get_num(int *);
#endif /*WI4MPI_STATIC*/

int PMPI_T_cvar_get_num(int * num_cvar)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_T_cvar_get_num( num_cvar);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_T_cvar_get_info(int cvar_index,char * name,int * name_len,int * verbosity,MPI_Datatype * datatype,MPI_T_enum * enumtype,char * desc,int * desc_len,int * binding,int * scope);
#pragma weak MPI_T_cvar_get_info=PMPI_T_cvar_get_info
int (*INTERFACE_LOCAL_MPI_T_cvar_get_info)(int,char *,int *,int *,MPI_Datatype *,MPI_T_enum *,char *,int *,int *,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_T_cvar_get_info(int,char *,int *,int *,MPI_Datatype *,MPI_T_enum *,char *,int *,int *,int *);
extern int INTERF_2_INTEL_CCMPI_T_cvar_get_info(int,char *,int *,int *,MPI_Datatype *,MPI_T_enum *,char *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_T_cvar_get_info(int cvar_index,char * name,int * name_len,int * verbosity,MPI_Datatype * datatype,MPI_T_enum * enumtype,char * desc,int * desc_len,int * binding,int * scope)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_T_cvar_get_info( cvar_index, name, name_len, verbosity, datatype, enumtype, desc, desc_len, binding, scope);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_T_cvar_handle_alloc(int cvar_index,void * obj_handle,MPI_T_cvar_handle * handle,int * count);
#pragma weak MPI_T_cvar_handle_alloc=PMPI_T_cvar_handle_alloc
int (*INTERFACE_LOCAL_MPI_T_cvar_handle_alloc)(int,void *,MPI_T_cvar_handle *,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_T_cvar_handle_alloc(int,void *,MPI_T_cvar_handle *,int *);
extern int INTERF_2_INTEL_CCMPI_T_cvar_handle_alloc(int,void *,MPI_T_cvar_handle *,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_T_cvar_handle_alloc(int cvar_index,void * obj_handle,MPI_T_cvar_handle * handle,int * count)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_T_cvar_handle_alloc( cvar_index, obj_handle, handle, count);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_T_cvar_handle_free(MPI_T_cvar_handle * handle);
#pragma weak MPI_T_cvar_handle_free=PMPI_T_cvar_handle_free
int (*INTERFACE_LOCAL_MPI_T_cvar_handle_free)(MPI_T_cvar_handle *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_T_cvar_handle_free(MPI_T_cvar_handle *);
extern int INTERF_2_INTEL_CCMPI_T_cvar_handle_free(MPI_T_cvar_handle *);
#endif /*WI4MPI_STATIC*/

int PMPI_T_cvar_handle_free(MPI_T_cvar_handle * handle)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_T_cvar_handle_free( handle);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_T_cvar_read(MPI_T_cvar_handle handle,void * buf);
#pragma weak MPI_T_cvar_read=PMPI_T_cvar_read
int (*INTERFACE_LOCAL_MPI_T_cvar_read)(MPI_T_cvar_handle,void *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_T_cvar_read(MPI_T_cvar_handle,void *);
extern int INTERF_2_INTEL_CCMPI_T_cvar_read(MPI_T_cvar_handle,void *);
#endif /*WI4MPI_STATIC*/

int PMPI_T_cvar_read(MPI_T_cvar_handle handle,void * buf)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_T_cvar_read( handle, buf);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_T_cvar_write(MPI_T_cvar_handle handle,void * buf);
#pragma weak MPI_T_cvar_write=PMPI_T_cvar_write
int (*INTERFACE_LOCAL_MPI_T_cvar_write)(MPI_T_cvar_handle,void *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_T_cvar_write(MPI_T_cvar_handle,void *);
extern int INTERF_2_INTEL_CCMPI_T_cvar_write(MPI_T_cvar_handle,void *);
#endif /*WI4MPI_STATIC*/

int PMPI_T_cvar_write(MPI_T_cvar_handle handle,void * buf)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_T_cvar_write( handle, buf);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_T_pvar_get_num(int * num_pvar);
#pragma weak MPI_T_pvar_get_num=PMPI_T_pvar_get_num
int (*INTERFACE_LOCAL_MPI_T_pvar_get_num)(int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_T_pvar_get_num(int *);
extern int INTERF_2_INTEL_CCMPI_T_pvar_get_num(int *);
#endif /*WI4MPI_STATIC*/

int PMPI_T_pvar_get_num(int * num_pvar)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_T_pvar_get_num( num_pvar);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_T_pvar_get_info(int pvar_index,char * name,int * name_len,int * verbosity,int * var_class,MPI_Datatype * datatype,MPI_T_enum * enumtype,char * desc,int * desc_len,int * binding,int * readonly,int * continuous,int * atomic);
#pragma weak MPI_T_pvar_get_info=PMPI_T_pvar_get_info
int (*INTERFACE_LOCAL_MPI_T_pvar_get_info)(int,char *,int *,int *,int *,MPI_Datatype *,MPI_T_enum *,char *,int *,int *,int *,int *,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_T_pvar_get_info(int,char *,int *,int *,int *,MPI_Datatype *,MPI_T_enum *,char *,int *,int *,int *,int *,int *);
extern int INTERF_2_INTEL_CCMPI_T_pvar_get_info(int,char *,int *,int *,int *,MPI_Datatype *,MPI_T_enum *,char *,int *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_T_pvar_get_info(int pvar_index,char * name,int * name_len,int * verbosity,int * var_class,MPI_Datatype * datatype,MPI_T_enum * enumtype,char * desc,int * desc_len,int * binding,int * readonly,int * continuous,int * atomic)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_T_pvar_get_info( pvar_index, name, name_len, verbosity, var_class, datatype, enumtype, desc, desc_len, binding, readonly, continuous, atomic);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_T_pvar_session_create(MPI_T_pvar_session * session);
#pragma weak MPI_T_pvar_session_create=PMPI_T_pvar_session_create
int (*INTERFACE_LOCAL_MPI_T_pvar_session_create)(MPI_T_pvar_session *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_T_pvar_session_create(MPI_T_pvar_session *);
extern int INTERF_2_INTEL_CCMPI_T_pvar_session_create(MPI_T_pvar_session *);
#endif /*WI4MPI_STATIC*/

int PMPI_T_pvar_session_create(MPI_T_pvar_session * session)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_T_pvar_session_create( session);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_T_pvar_session_free(MPI_T_pvar_session * session);
#pragma weak MPI_T_pvar_session_free=PMPI_T_pvar_session_free
int (*INTERFACE_LOCAL_MPI_T_pvar_session_free)(MPI_T_pvar_session *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_T_pvar_session_free(MPI_T_pvar_session *);
extern int INTERF_2_INTEL_CCMPI_T_pvar_session_free(MPI_T_pvar_session *);
#endif /*WI4MPI_STATIC*/

int PMPI_T_pvar_session_free(MPI_T_pvar_session * session)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_T_pvar_session_free( session);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_T_pvar_handle_alloc(MPI_T_pvar_session session,int pvar_index,void * obj_handle,MPI_T_pvar_handle * handle,int * count);
#pragma weak MPI_T_pvar_handle_alloc=PMPI_T_pvar_handle_alloc
int (*INTERFACE_LOCAL_MPI_T_pvar_handle_alloc)(MPI_T_pvar_session,int,void *,MPI_T_pvar_handle *,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_T_pvar_handle_alloc(MPI_T_pvar_session,int,void *,MPI_T_pvar_handle *,int *);
extern int INTERF_2_INTEL_CCMPI_T_pvar_handle_alloc(MPI_T_pvar_session,int,void *,MPI_T_pvar_handle *,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_T_pvar_handle_alloc(MPI_T_pvar_session session,int pvar_index,void * obj_handle,MPI_T_pvar_handle * handle,int * count)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_T_pvar_handle_alloc( session, pvar_index, obj_handle, handle, count);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_T_pvar_handle_free(MPI_T_pvar_session session,MPI_T_pvar_handle * handle);
#pragma weak MPI_T_pvar_handle_free=PMPI_T_pvar_handle_free
int (*INTERFACE_LOCAL_MPI_T_pvar_handle_free)(MPI_T_pvar_session,MPI_T_pvar_handle *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_T_pvar_handle_free(MPI_T_pvar_session,MPI_T_pvar_handle *);
extern int INTERF_2_INTEL_CCMPI_T_pvar_handle_free(MPI_T_pvar_session,MPI_T_pvar_handle *);
#endif /*WI4MPI_STATIC*/

int PMPI_T_pvar_handle_free(MPI_T_pvar_session session,MPI_T_pvar_handle * handle)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_T_pvar_handle_free( session, handle);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_T_pvar_start(MPI_T_pvar_session session,MPI_T_pvar_handle handle);
#pragma weak MPI_T_pvar_start=PMPI_T_pvar_start
int (*INTERFACE_LOCAL_MPI_T_pvar_start)(MPI_T_pvar_session,MPI_T_pvar_handle);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_T_pvar_start(MPI_T_pvar_session,MPI_T_pvar_handle);
extern int INTERF_2_INTEL_CCMPI_T_pvar_start(MPI_T_pvar_session,MPI_T_pvar_handle);
#endif /*WI4MPI_STATIC*/

int PMPI_T_pvar_start(MPI_T_pvar_session session,MPI_T_pvar_handle handle)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_T_pvar_start( session, handle);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_T_pvar_stop(MPI_T_pvar_session session,MPI_T_pvar_handle handle);
#pragma weak MPI_T_pvar_stop=PMPI_T_pvar_stop
int (*INTERFACE_LOCAL_MPI_T_pvar_stop)(MPI_T_pvar_session,MPI_T_pvar_handle);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_T_pvar_stop(MPI_T_pvar_session,MPI_T_pvar_handle);
extern int INTERF_2_INTEL_CCMPI_T_pvar_stop(MPI_T_pvar_session,MPI_T_pvar_handle);
#endif /*WI4MPI_STATIC*/

int PMPI_T_pvar_stop(MPI_T_pvar_session session,MPI_T_pvar_handle handle)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_T_pvar_stop( session, handle);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_T_pvar_read(MPI_T_pvar_session session,MPI_T_pvar_handle handle,void * buf);
#pragma weak MPI_T_pvar_read=PMPI_T_pvar_read
int (*INTERFACE_LOCAL_MPI_T_pvar_read)(MPI_T_pvar_session,MPI_T_pvar_handle,void *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_T_pvar_read(MPI_T_pvar_session,MPI_T_pvar_handle,void *);
extern int INTERF_2_INTEL_CCMPI_T_pvar_read(MPI_T_pvar_session,MPI_T_pvar_handle,void *);
#endif /*WI4MPI_STATIC*/

int PMPI_T_pvar_read(MPI_T_pvar_session session,MPI_T_pvar_handle handle,void * buf)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_T_pvar_read( session, handle, buf);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_T_pvar_write(MPI_T_pvar_session session,MPI_T_pvar_handle handle,void * buf);
#pragma weak MPI_T_pvar_write=PMPI_T_pvar_write
int (*INTERFACE_LOCAL_MPI_T_pvar_write)(MPI_T_pvar_session,MPI_T_pvar_handle,void *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_T_pvar_write(MPI_T_pvar_session,MPI_T_pvar_handle,void *);
extern int INTERF_2_INTEL_CCMPI_T_pvar_write(MPI_T_pvar_session,MPI_T_pvar_handle,void *);
#endif /*WI4MPI_STATIC*/

int PMPI_T_pvar_write(MPI_T_pvar_session session,MPI_T_pvar_handle handle,void * buf)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_T_pvar_write( session, handle, buf);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_T_pvar_reset(MPI_T_pvar_session session,MPI_T_pvar_handle handle);
#pragma weak MPI_T_pvar_reset=PMPI_T_pvar_reset
int (*INTERFACE_LOCAL_MPI_T_pvar_reset)(MPI_T_pvar_session,MPI_T_pvar_handle);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_T_pvar_reset(MPI_T_pvar_session,MPI_T_pvar_handle);
extern int INTERF_2_INTEL_CCMPI_T_pvar_reset(MPI_T_pvar_session,MPI_T_pvar_handle);
#endif /*WI4MPI_STATIC*/

int PMPI_T_pvar_reset(MPI_T_pvar_session session,MPI_T_pvar_handle handle)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_T_pvar_reset( session, handle);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_T_pvar_readreset(MPI_T_pvar_session session,MPI_T_pvar_handle handle,void * buf);
#pragma weak MPI_T_pvar_readreset=PMPI_T_pvar_readreset
int (*INTERFACE_LOCAL_MPI_T_pvar_readreset)(MPI_T_pvar_session,MPI_T_pvar_handle,void *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_T_pvar_readreset(MPI_T_pvar_session,MPI_T_pvar_handle,void *);
extern int INTERF_2_INTEL_CCMPI_T_pvar_readreset(MPI_T_pvar_session,MPI_T_pvar_handle,void *);
#endif /*WI4MPI_STATIC*/

int PMPI_T_pvar_readreset(MPI_T_pvar_session session,MPI_T_pvar_handle handle,void * buf)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_T_pvar_readreset( session, handle, buf);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_T_category_get_num(int * num_cat);
#pragma weak MPI_T_category_get_num=PMPI_T_category_get_num
int (*INTERFACE_LOCAL_MPI_T_category_get_num)(int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_T_category_get_num(int *);
extern int INTERF_2_INTEL_CCMPI_T_category_get_num(int *);
#endif /*WI4MPI_STATIC*/

int PMPI_T_category_get_num(int * num_cat)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_T_category_get_num( num_cat);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_T_category_get_info(int cat_index,char * name,int * name_len,char * desc,int * desc_len,int * num_cvars,int * num_pvars,int * num_categories);
#pragma weak MPI_T_category_get_info=PMPI_T_category_get_info
int (*INTERFACE_LOCAL_MPI_T_category_get_info)(int,char *,int *,char *,int *,int *,int *,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_T_category_get_info(int,char *,int *,char *,int *,int *,int *,int *);
extern int INTERF_2_INTEL_CCMPI_T_category_get_info(int,char *,int *,char *,int *,int *,int *,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_T_category_get_info(int cat_index,char * name,int * name_len,char * desc,int * desc_len,int * num_cvars,int * num_pvars,int * num_categories)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_T_category_get_info( cat_index, name, name_len, desc, desc_len, num_cvars, num_pvars, num_categories);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_open(MPI_Comm comm,char * filename,int amode,MPI_Info info,MPI_File * fh);
#pragma weak MPI_File_open=PMPI_File_open
int (*INTERFACE_LOCAL_MPI_File_open)(MPI_Comm,char *,int,MPI_Info,MPI_File *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_open(MPI_Comm,char *,int,MPI_Info,MPI_File *);
extern int INTERF_2_INTEL_CCMPI_File_open(MPI_Comm,char *,int,MPI_Info,MPI_File *);
#endif /*WI4MPI_STATIC*/

int PMPI_File_open(MPI_Comm comm,char * filename,int amode,MPI_Info info,MPI_File * fh)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_open( comm, filename, amode, info, fh);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_close(MPI_File * fh);
#pragma weak MPI_File_close=PMPI_File_close
int (*INTERFACE_LOCAL_MPI_File_close)(MPI_File *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_close(MPI_File *);
extern int INTERF_2_INTEL_CCMPI_File_close(MPI_File *);
#endif /*WI4MPI_STATIC*/

int PMPI_File_close(MPI_File * fh)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_close( fh);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_delete(char * filename,MPI_Info info);
#pragma weak MPI_File_delete=PMPI_File_delete
int (*INTERFACE_LOCAL_MPI_File_delete)(char *,MPI_Info);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_delete(char *,MPI_Info);
extern int INTERF_2_INTEL_CCMPI_File_delete(char *,MPI_Info);
#endif /*WI4MPI_STATIC*/

int PMPI_File_delete(char * filename,MPI_Info info)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_delete( filename, info);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_set_size(MPI_File fh,MPI_Offset size);
#pragma weak MPI_File_set_size=PMPI_File_set_size
int (*INTERFACE_LOCAL_MPI_File_set_size)(MPI_File,MPI_Offset);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_set_size(MPI_File,MPI_Offset);
extern int INTERF_2_INTEL_CCMPI_File_set_size(MPI_File,MPI_Offset);
#endif /*WI4MPI_STATIC*/

int PMPI_File_set_size(MPI_File fh,MPI_Offset size)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_set_size( fh, size);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_preallocate(MPI_File fh,MPI_Offset size);
#pragma weak MPI_File_preallocate=PMPI_File_preallocate
int (*INTERFACE_LOCAL_MPI_File_preallocate)(MPI_File,MPI_Offset);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_preallocate(MPI_File,MPI_Offset);
extern int INTERF_2_INTEL_CCMPI_File_preallocate(MPI_File,MPI_Offset);
#endif /*WI4MPI_STATIC*/

int PMPI_File_preallocate(MPI_File fh,MPI_Offset size)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_preallocate( fh, size);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_get_size(MPI_File fh,MPI_Offset * size);
#pragma weak MPI_File_get_size=PMPI_File_get_size
int (*INTERFACE_LOCAL_MPI_File_get_size)(MPI_File,MPI_Offset *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_get_size(MPI_File,MPI_Offset *);
extern int INTERF_2_INTEL_CCMPI_File_get_size(MPI_File,MPI_Offset *);
#endif /*WI4MPI_STATIC*/

int PMPI_File_get_size(MPI_File fh,MPI_Offset * size)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_get_size( fh, size);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_get_group(MPI_File fh,MPI_Group * group);
#pragma weak MPI_File_get_group=PMPI_File_get_group
int (*INTERFACE_LOCAL_MPI_File_get_group)(MPI_File,MPI_Group *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_get_group(MPI_File,MPI_Group *);
extern int INTERF_2_INTEL_CCMPI_File_get_group(MPI_File,MPI_Group *);
#endif /*WI4MPI_STATIC*/

int PMPI_File_get_group(MPI_File fh,MPI_Group * group)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_get_group( fh, group);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_get_amode(MPI_File fh,int * amode);
#pragma weak MPI_File_get_amode=PMPI_File_get_amode
int (*INTERFACE_LOCAL_MPI_File_get_amode)(MPI_File,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_get_amode(MPI_File,int *);
extern int INTERF_2_INTEL_CCMPI_File_get_amode(MPI_File,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_File_get_amode(MPI_File fh,int * amode)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_get_amode( fh, amode);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_set_info(MPI_File fh,MPI_Info info);
#pragma weak MPI_File_set_info=PMPI_File_set_info
int (*INTERFACE_LOCAL_MPI_File_set_info)(MPI_File,MPI_Info);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_set_info(MPI_File,MPI_Info);
extern int INTERF_2_INTEL_CCMPI_File_set_info(MPI_File,MPI_Info);
#endif /*WI4MPI_STATIC*/

int PMPI_File_set_info(MPI_File fh,MPI_Info info)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_set_info( fh, info);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_get_info(MPI_File fh,MPI_Info * info_used);
#pragma weak MPI_File_get_info=PMPI_File_get_info
int (*INTERFACE_LOCAL_MPI_File_get_info)(MPI_File,MPI_Info *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_get_info(MPI_File,MPI_Info *);
extern int INTERF_2_INTEL_CCMPI_File_get_info(MPI_File,MPI_Info *);
#endif /*WI4MPI_STATIC*/

int PMPI_File_get_info(MPI_File fh,MPI_Info * info_used)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_get_info( fh, info_used);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_set_view(MPI_File fh,MPI_Offset disp,MPI_Datatype etype,MPI_Datatype filetype,char * datarep,MPI_Info info);
#pragma weak MPI_File_set_view=PMPI_File_set_view
int (*INTERFACE_LOCAL_MPI_File_set_view)(MPI_File,MPI_Offset,MPI_Datatype,MPI_Datatype,char *,MPI_Info);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_set_view(MPI_File,MPI_Offset,MPI_Datatype,MPI_Datatype,char *,MPI_Info);
extern int INTERF_2_INTEL_CCMPI_File_set_view(MPI_File,MPI_Offset,MPI_Datatype,MPI_Datatype,char *,MPI_Info);
#endif /*WI4MPI_STATIC*/

int PMPI_File_set_view(MPI_File fh,MPI_Offset disp,MPI_Datatype etype,MPI_Datatype filetype,char * datarep,MPI_Info info)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_set_view( fh, disp, etype, filetype, datarep, info);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_get_view(MPI_File fh,MPI_Offset * disp,MPI_Datatype * etype,MPI_Datatype * filetype,char * datarep);
#pragma weak MPI_File_get_view=PMPI_File_get_view
int (*INTERFACE_LOCAL_MPI_File_get_view)(MPI_File,MPI_Offset *,MPI_Datatype *,MPI_Datatype *,char *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_get_view(MPI_File,MPI_Offset *,MPI_Datatype *,MPI_Datatype *,char *);
extern int INTERF_2_INTEL_CCMPI_File_get_view(MPI_File,MPI_Offset *,MPI_Datatype *,MPI_Datatype *,char *);
#endif /*WI4MPI_STATIC*/

int PMPI_File_get_view(MPI_File fh,MPI_Offset * disp,MPI_Datatype * etype,MPI_Datatype * filetype,char * datarep)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_get_view( fh, disp, etype, filetype, datarep);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_read_at(MPI_File fh,MPI_Offset offset,void * buf,int count,MPI_Datatype datatype,MPI_Status * status);
#pragma weak MPI_File_read_at=PMPI_File_read_at
int (*INTERFACE_LOCAL_MPI_File_read_at)(MPI_File,MPI_Offset,void *,int,MPI_Datatype,MPI_Status *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_read_at(MPI_File,MPI_Offset,void *,int,MPI_Datatype,MPI_Status *);
extern int INTERF_2_INTEL_CCMPI_File_read_at(MPI_File,MPI_Offset,void *,int,MPI_Datatype,MPI_Status *);
#endif /*WI4MPI_STATIC*/

int PMPI_File_read_at(MPI_File fh,MPI_Offset offset,void * buf,int count,MPI_Datatype datatype,MPI_Status * status)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_read_at( fh, offset, buf, count, datatype, status);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_read_at_all(MPI_File fh,MPI_Offset offset,void * buf,int count,MPI_Datatype datatype,MPI_Status * status);
#pragma weak MPI_File_read_at_all=PMPI_File_read_at_all
int (*INTERFACE_LOCAL_MPI_File_read_at_all)(MPI_File,MPI_Offset,void *,int,MPI_Datatype,MPI_Status *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_read_at_all(MPI_File,MPI_Offset,void *,int,MPI_Datatype,MPI_Status *);
extern int INTERF_2_INTEL_CCMPI_File_read_at_all(MPI_File,MPI_Offset,void *,int,MPI_Datatype,MPI_Status *);
#endif /*WI4MPI_STATIC*/

int PMPI_File_read_at_all(MPI_File fh,MPI_Offset offset,void * buf,int count,MPI_Datatype datatype,MPI_Status * status)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_read_at_all( fh, offset, buf, count, datatype, status);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_write_at(MPI_File fh,MPI_Offset offset,void * buf,int count,MPI_Datatype datatype,MPI_Status * status);
#pragma weak MPI_File_write_at=PMPI_File_write_at
int (*INTERFACE_LOCAL_MPI_File_write_at)(MPI_File,MPI_Offset,void *,int,MPI_Datatype,MPI_Status *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_write_at(MPI_File,MPI_Offset,void *,int,MPI_Datatype,MPI_Status *);
extern int INTERF_2_INTEL_CCMPI_File_write_at(MPI_File,MPI_Offset,void *,int,MPI_Datatype,MPI_Status *);
#endif /*WI4MPI_STATIC*/

int PMPI_File_write_at(MPI_File fh,MPI_Offset offset,void * buf,int count,MPI_Datatype datatype,MPI_Status * status)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_write_at( fh, offset, buf, count, datatype, status);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_write_at_all(MPI_File fh,MPI_Offset offset,void * buf,int count,MPI_Datatype datatype,MPI_Status * status);
#pragma weak MPI_File_write_at_all=PMPI_File_write_at_all
int (*INTERFACE_LOCAL_MPI_File_write_at_all)(MPI_File,MPI_Offset,void *,int,MPI_Datatype,MPI_Status *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_write_at_all(MPI_File,MPI_Offset,void *,int,MPI_Datatype,MPI_Status *);
extern int INTERF_2_INTEL_CCMPI_File_write_at_all(MPI_File,MPI_Offset,void *,int,MPI_Datatype,MPI_Status *);
#endif /*WI4MPI_STATIC*/

int PMPI_File_write_at_all(MPI_File fh,MPI_Offset offset,void * buf,int count,MPI_Datatype datatype,MPI_Status * status)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_write_at_all( fh, offset, buf, count, datatype, status);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_iread_at(MPI_File fh,MPI_Offset offset,void * buf,int count,MPI_Datatype datatype,MPI_Request * request);
#pragma weak MPI_File_iread_at=PMPI_File_iread_at
int (*INTERFACE_LOCAL_MPI_File_iread_at)(MPI_File,MPI_Offset,void *,int,MPI_Datatype,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_iread_at(MPI_File,MPI_Offset,void *,int,MPI_Datatype,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_File_iread_at(MPI_File,MPI_Offset,void *,int,MPI_Datatype,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_File_iread_at(MPI_File fh,MPI_Offset offset,void * buf,int count,MPI_Datatype datatype,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_iread_at( fh, offset, buf, count, datatype, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_iwrite_at(MPI_File fh,MPI_Offset offset,void * buf,int count,MPI_Datatype datatype,MPI_Request * request);
#pragma weak MPI_File_iwrite_at=PMPI_File_iwrite_at
int (*INTERFACE_LOCAL_MPI_File_iwrite_at)(MPI_File,MPI_Offset,void *,int,MPI_Datatype,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_iwrite_at(MPI_File,MPI_Offset,void *,int,MPI_Datatype,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_File_iwrite_at(MPI_File,MPI_Offset,void *,int,MPI_Datatype,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_File_iwrite_at(MPI_File fh,MPI_Offset offset,void * buf,int count,MPI_Datatype datatype,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_iwrite_at( fh, offset, buf, count, datatype, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_read(MPI_File fh,void * buf,int count,MPI_Datatype datatype,MPI_Status * status);
#pragma weak MPI_File_read=PMPI_File_read
int (*INTERFACE_LOCAL_MPI_File_read)(MPI_File,void *,int,MPI_Datatype,MPI_Status *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_read(MPI_File,void *,int,MPI_Datatype,MPI_Status *);
extern int INTERF_2_INTEL_CCMPI_File_read(MPI_File,void *,int,MPI_Datatype,MPI_Status *);
#endif /*WI4MPI_STATIC*/

int PMPI_File_read(MPI_File fh,void * buf,int count,MPI_Datatype datatype,MPI_Status * status)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_read( fh, buf, count, datatype, status);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_read_all(MPI_File fh,void * buf,int count,MPI_Datatype datatype,MPI_Status * status);
#pragma weak MPI_File_read_all=PMPI_File_read_all
int (*INTERFACE_LOCAL_MPI_File_read_all)(MPI_File,void *,int,MPI_Datatype,MPI_Status *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_read_all(MPI_File,void *,int,MPI_Datatype,MPI_Status *);
extern int INTERF_2_INTEL_CCMPI_File_read_all(MPI_File,void *,int,MPI_Datatype,MPI_Status *);
#endif /*WI4MPI_STATIC*/

int PMPI_File_read_all(MPI_File fh,void * buf,int count,MPI_Datatype datatype,MPI_Status * status)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_read_all( fh, buf, count, datatype, status);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_write(MPI_File fh,void * buf,int count,MPI_Datatype datatype,MPI_Status * status);
#pragma weak MPI_File_write=PMPI_File_write
int (*INTERFACE_LOCAL_MPI_File_write)(MPI_File,void *,int,MPI_Datatype,MPI_Status *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_write(MPI_File,void *,int,MPI_Datatype,MPI_Status *);
extern int INTERF_2_INTEL_CCMPI_File_write(MPI_File,void *,int,MPI_Datatype,MPI_Status *);
#endif /*WI4MPI_STATIC*/

int PMPI_File_write(MPI_File fh,void * buf,int count,MPI_Datatype datatype,MPI_Status * status)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_write( fh, buf, count, datatype, status);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_write_all(MPI_File fh,void * buf,int count,MPI_Datatype datatype,MPI_Status * status);
#pragma weak MPI_File_write_all=PMPI_File_write_all
int (*INTERFACE_LOCAL_MPI_File_write_all)(MPI_File,void *,int,MPI_Datatype,MPI_Status *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_write_all(MPI_File,void *,int,MPI_Datatype,MPI_Status *);
extern int INTERF_2_INTEL_CCMPI_File_write_all(MPI_File,void *,int,MPI_Datatype,MPI_Status *);
#endif /*WI4MPI_STATIC*/

int PMPI_File_write_all(MPI_File fh,void * buf,int count,MPI_Datatype datatype,MPI_Status * status)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_write_all( fh, buf, count, datatype, status);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_iread(MPI_File fh,void * buf,int count,MPI_Datatype datatype,MPI_Request * request);
#pragma weak MPI_File_iread=PMPI_File_iread
int (*INTERFACE_LOCAL_MPI_File_iread)(MPI_File,void *,int,MPI_Datatype,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_iread(MPI_File,void *,int,MPI_Datatype,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_File_iread(MPI_File,void *,int,MPI_Datatype,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_File_iread(MPI_File fh,void * buf,int count,MPI_Datatype datatype,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_iread( fh, buf, count, datatype, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_iwrite(MPI_File fh,void * buf,int count,MPI_Datatype datatype,MPI_Request * request);
#pragma weak MPI_File_iwrite=PMPI_File_iwrite
int (*INTERFACE_LOCAL_MPI_File_iwrite)(MPI_File,void *,int,MPI_Datatype,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_iwrite(MPI_File,void *,int,MPI_Datatype,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_File_iwrite(MPI_File,void *,int,MPI_Datatype,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_File_iwrite(MPI_File fh,void * buf,int count,MPI_Datatype datatype,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_iwrite( fh, buf, count, datatype, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_seek(MPI_File fh,MPI_Offset offset,int whence);
#pragma weak MPI_File_seek=PMPI_File_seek
int (*INTERFACE_LOCAL_MPI_File_seek)(MPI_File,MPI_Offset,int);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_seek(MPI_File,MPI_Offset,int);
extern int INTERF_2_INTEL_CCMPI_File_seek(MPI_File,MPI_Offset,int);
#endif /*WI4MPI_STATIC*/

int PMPI_File_seek(MPI_File fh,MPI_Offset offset,int whence)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_seek( fh, offset, whence);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_get_position(MPI_File fh,MPI_Offset * offset);
#pragma weak MPI_File_get_position=PMPI_File_get_position
int (*INTERFACE_LOCAL_MPI_File_get_position)(MPI_File,MPI_Offset *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_get_position(MPI_File,MPI_Offset *);
extern int INTERF_2_INTEL_CCMPI_File_get_position(MPI_File,MPI_Offset *);
#endif /*WI4MPI_STATIC*/

int PMPI_File_get_position(MPI_File fh,MPI_Offset * offset)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_get_position( fh, offset);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_get_byte_offset(MPI_File fh,MPI_Offset offset,MPI_Offset * disp);
#pragma weak MPI_File_get_byte_offset=PMPI_File_get_byte_offset
int (*INTERFACE_LOCAL_MPI_File_get_byte_offset)(MPI_File,MPI_Offset,MPI_Offset *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_get_byte_offset(MPI_File,MPI_Offset,MPI_Offset *);
extern int INTERF_2_INTEL_CCMPI_File_get_byte_offset(MPI_File,MPI_Offset,MPI_Offset *);
#endif /*WI4MPI_STATIC*/

int PMPI_File_get_byte_offset(MPI_File fh,MPI_Offset offset,MPI_Offset * disp)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_get_byte_offset( fh, offset, disp);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_read_shared(MPI_File fh,void * buf,int count,MPI_Datatype datatype,MPI_Status * status);
#pragma weak MPI_File_read_shared=PMPI_File_read_shared
int (*INTERFACE_LOCAL_MPI_File_read_shared)(MPI_File,void *,int,MPI_Datatype,MPI_Status *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_read_shared(MPI_File,void *,int,MPI_Datatype,MPI_Status *);
extern int INTERF_2_INTEL_CCMPI_File_read_shared(MPI_File,void *,int,MPI_Datatype,MPI_Status *);
#endif /*WI4MPI_STATIC*/

int PMPI_File_read_shared(MPI_File fh,void * buf,int count,MPI_Datatype datatype,MPI_Status * status)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_read_shared( fh, buf, count, datatype, status);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_write_shared(MPI_File fh,void * buf,int count,MPI_Datatype datatype,MPI_Status * status);
#pragma weak MPI_File_write_shared=PMPI_File_write_shared
int (*INTERFACE_LOCAL_MPI_File_write_shared)(MPI_File,void *,int,MPI_Datatype,MPI_Status *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_write_shared(MPI_File,void *,int,MPI_Datatype,MPI_Status *);
extern int INTERF_2_INTEL_CCMPI_File_write_shared(MPI_File,void *,int,MPI_Datatype,MPI_Status *);
#endif /*WI4MPI_STATIC*/

int PMPI_File_write_shared(MPI_File fh,void * buf,int count,MPI_Datatype datatype,MPI_Status * status)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_write_shared( fh, buf, count, datatype, status);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_iread_shared(MPI_File fh,void * buf,int count,MPI_Datatype datatype,MPI_Request * request);
#pragma weak MPI_File_iread_shared=PMPI_File_iread_shared
int (*INTERFACE_LOCAL_MPI_File_iread_shared)(MPI_File,void *,int,MPI_Datatype,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_iread_shared(MPI_File,void *,int,MPI_Datatype,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_File_iread_shared(MPI_File,void *,int,MPI_Datatype,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_File_iread_shared(MPI_File fh,void * buf,int count,MPI_Datatype datatype,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_iread_shared( fh, buf, count, datatype, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_iwrite_shared(MPI_File fh,void * buf,int count,MPI_Datatype datatype,MPI_Request * request);
#pragma weak MPI_File_iwrite_shared=PMPI_File_iwrite_shared
int (*INTERFACE_LOCAL_MPI_File_iwrite_shared)(MPI_File,void *,int,MPI_Datatype,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_iwrite_shared(MPI_File,void *,int,MPI_Datatype,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_File_iwrite_shared(MPI_File,void *,int,MPI_Datatype,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_File_iwrite_shared(MPI_File fh,void * buf,int count,MPI_Datatype datatype,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_iwrite_shared( fh, buf, count, datatype, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_read_ordered(MPI_File fh,void * buf,int count,MPI_Datatype datatype,MPI_Status * status);
#pragma weak MPI_File_read_ordered=PMPI_File_read_ordered
int (*INTERFACE_LOCAL_MPI_File_read_ordered)(MPI_File,void *,int,MPI_Datatype,MPI_Status *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_read_ordered(MPI_File,void *,int,MPI_Datatype,MPI_Status *);
extern int INTERF_2_INTEL_CCMPI_File_read_ordered(MPI_File,void *,int,MPI_Datatype,MPI_Status *);
#endif /*WI4MPI_STATIC*/

int PMPI_File_read_ordered(MPI_File fh,void * buf,int count,MPI_Datatype datatype,MPI_Status * status)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_read_ordered( fh, buf, count, datatype, status);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_write_ordered(MPI_File fh,void * buf,int count,MPI_Datatype datatype,MPI_Status * status);
#pragma weak MPI_File_write_ordered=PMPI_File_write_ordered
int (*INTERFACE_LOCAL_MPI_File_write_ordered)(MPI_File,void *,int,MPI_Datatype,MPI_Status *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_write_ordered(MPI_File,void *,int,MPI_Datatype,MPI_Status *);
extern int INTERF_2_INTEL_CCMPI_File_write_ordered(MPI_File,void *,int,MPI_Datatype,MPI_Status *);
#endif /*WI4MPI_STATIC*/

int PMPI_File_write_ordered(MPI_File fh,void * buf,int count,MPI_Datatype datatype,MPI_Status * status)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_write_ordered( fh, buf, count, datatype, status);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_seek_shared(MPI_File fh,MPI_Offset offset,int whence);
#pragma weak MPI_File_seek_shared=PMPI_File_seek_shared
int (*INTERFACE_LOCAL_MPI_File_seek_shared)(MPI_File,MPI_Offset,int);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_seek_shared(MPI_File,MPI_Offset,int);
extern int INTERF_2_INTEL_CCMPI_File_seek_shared(MPI_File,MPI_Offset,int);
#endif /*WI4MPI_STATIC*/

int PMPI_File_seek_shared(MPI_File fh,MPI_Offset offset,int whence)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_seek_shared( fh, offset, whence);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_get_position_shared(MPI_File fh,MPI_Offset * offset);
#pragma weak MPI_File_get_position_shared=PMPI_File_get_position_shared
int (*INTERFACE_LOCAL_MPI_File_get_position_shared)(MPI_File,MPI_Offset *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_get_position_shared(MPI_File,MPI_Offset *);
extern int INTERF_2_INTEL_CCMPI_File_get_position_shared(MPI_File,MPI_Offset *);
#endif /*WI4MPI_STATIC*/

int PMPI_File_get_position_shared(MPI_File fh,MPI_Offset * offset)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_get_position_shared( fh, offset);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_read_at_all_begin(MPI_File fh,MPI_Offset offset,void * buf,int count,MPI_Datatype datatype);
#pragma weak MPI_File_read_at_all_begin=PMPI_File_read_at_all_begin
int (*INTERFACE_LOCAL_MPI_File_read_at_all_begin)(MPI_File,MPI_Offset,void *,int,MPI_Datatype);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_read_at_all_begin(MPI_File,MPI_Offset,void *,int,MPI_Datatype);
extern int INTERF_2_INTEL_CCMPI_File_read_at_all_begin(MPI_File,MPI_Offset,void *,int,MPI_Datatype);
#endif /*WI4MPI_STATIC*/

int PMPI_File_read_at_all_begin(MPI_File fh,MPI_Offset offset,void * buf,int count,MPI_Datatype datatype)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_read_at_all_begin( fh, offset, buf, count, datatype);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_read_at_all_end(MPI_File fh,void * buf,MPI_Status * status);
#pragma weak MPI_File_read_at_all_end=PMPI_File_read_at_all_end
int (*INTERFACE_LOCAL_MPI_File_read_at_all_end)(MPI_File,void *,MPI_Status *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_read_at_all_end(MPI_File,void *,MPI_Status *);
extern int INTERF_2_INTEL_CCMPI_File_read_at_all_end(MPI_File,void *,MPI_Status *);
#endif /*WI4MPI_STATIC*/

int PMPI_File_read_at_all_end(MPI_File fh,void * buf,MPI_Status * status)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_read_at_all_end( fh, buf, status);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_write_at_all_begin(MPI_File fh,MPI_Offset offset,void * buf,int count,MPI_Datatype datatype);
#pragma weak MPI_File_write_at_all_begin=PMPI_File_write_at_all_begin
int (*INTERFACE_LOCAL_MPI_File_write_at_all_begin)(MPI_File,MPI_Offset,void *,int,MPI_Datatype);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_write_at_all_begin(MPI_File,MPI_Offset,void *,int,MPI_Datatype);
extern int INTERF_2_INTEL_CCMPI_File_write_at_all_begin(MPI_File,MPI_Offset,void *,int,MPI_Datatype);
#endif /*WI4MPI_STATIC*/

int PMPI_File_write_at_all_begin(MPI_File fh,MPI_Offset offset,void * buf,int count,MPI_Datatype datatype)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_write_at_all_begin( fh, offset, buf, count, datatype);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_write_at_all_end(MPI_File fh,void * buf,MPI_Status * status);
#pragma weak MPI_File_write_at_all_end=PMPI_File_write_at_all_end
int (*INTERFACE_LOCAL_MPI_File_write_at_all_end)(MPI_File,void *,MPI_Status *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_write_at_all_end(MPI_File,void *,MPI_Status *);
extern int INTERF_2_INTEL_CCMPI_File_write_at_all_end(MPI_File,void *,MPI_Status *);
#endif /*WI4MPI_STATIC*/

int PMPI_File_write_at_all_end(MPI_File fh,void * buf,MPI_Status * status)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_write_at_all_end( fh, buf, status);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_read_all_begin(MPI_File fh,void * buf,int count,MPI_Datatype datatype);
#pragma weak MPI_File_read_all_begin=PMPI_File_read_all_begin
int (*INTERFACE_LOCAL_MPI_File_read_all_begin)(MPI_File,void *,int,MPI_Datatype);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_read_all_begin(MPI_File,void *,int,MPI_Datatype);
extern int INTERF_2_INTEL_CCMPI_File_read_all_begin(MPI_File,void *,int,MPI_Datatype);
#endif /*WI4MPI_STATIC*/

int PMPI_File_read_all_begin(MPI_File fh,void * buf,int count,MPI_Datatype datatype)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_read_all_begin( fh, buf, count, datatype);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_read_all_end(MPI_File fh,void * buf,MPI_Status * status);
#pragma weak MPI_File_read_all_end=PMPI_File_read_all_end
int (*INTERFACE_LOCAL_MPI_File_read_all_end)(MPI_File,void *,MPI_Status *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_read_all_end(MPI_File,void *,MPI_Status *);
extern int INTERF_2_INTEL_CCMPI_File_read_all_end(MPI_File,void *,MPI_Status *);
#endif /*WI4MPI_STATIC*/

int PMPI_File_read_all_end(MPI_File fh,void * buf,MPI_Status * status)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_read_all_end( fh, buf, status);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_write_all_begin(MPI_File fh,void * buf,int count,MPI_Datatype datatype);
#pragma weak MPI_File_write_all_begin=PMPI_File_write_all_begin
int (*INTERFACE_LOCAL_MPI_File_write_all_begin)(MPI_File,void *,int,MPI_Datatype);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_write_all_begin(MPI_File,void *,int,MPI_Datatype);
extern int INTERF_2_INTEL_CCMPI_File_write_all_begin(MPI_File,void *,int,MPI_Datatype);
#endif /*WI4MPI_STATIC*/

int PMPI_File_write_all_begin(MPI_File fh,void * buf,int count,MPI_Datatype datatype)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_write_all_begin( fh, buf, count, datatype);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_write_all_end(MPI_File fh,void * buf,MPI_Status * status);
#pragma weak MPI_File_write_all_end=PMPI_File_write_all_end
int (*INTERFACE_LOCAL_MPI_File_write_all_end)(MPI_File,void *,MPI_Status *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_write_all_end(MPI_File,void *,MPI_Status *);
extern int INTERF_2_INTEL_CCMPI_File_write_all_end(MPI_File,void *,MPI_Status *);
#endif /*WI4MPI_STATIC*/

int PMPI_File_write_all_end(MPI_File fh,void * buf,MPI_Status * status)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_write_all_end( fh, buf, status);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_read_ordered_begin(MPI_File fh,void * buf,int count,MPI_Datatype datatype);
#pragma weak MPI_File_read_ordered_begin=PMPI_File_read_ordered_begin
int (*INTERFACE_LOCAL_MPI_File_read_ordered_begin)(MPI_File,void *,int,MPI_Datatype);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_read_ordered_begin(MPI_File,void *,int,MPI_Datatype);
extern int INTERF_2_INTEL_CCMPI_File_read_ordered_begin(MPI_File,void *,int,MPI_Datatype);
#endif /*WI4MPI_STATIC*/

int PMPI_File_read_ordered_begin(MPI_File fh,void * buf,int count,MPI_Datatype datatype)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_read_ordered_begin( fh, buf, count, datatype);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_read_ordered_end(MPI_File fh,void * buf,MPI_Status * status);
#pragma weak MPI_File_read_ordered_end=PMPI_File_read_ordered_end
int (*INTERFACE_LOCAL_MPI_File_read_ordered_end)(MPI_File,void *,MPI_Status *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_read_ordered_end(MPI_File,void *,MPI_Status *);
extern int INTERF_2_INTEL_CCMPI_File_read_ordered_end(MPI_File,void *,MPI_Status *);
#endif /*WI4MPI_STATIC*/

int PMPI_File_read_ordered_end(MPI_File fh,void * buf,MPI_Status * status)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_read_ordered_end( fh, buf, status);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_write_ordered_begin(MPI_File fh,void * buf,int count,MPI_Datatype datatype);
#pragma weak MPI_File_write_ordered_begin=PMPI_File_write_ordered_begin
int (*INTERFACE_LOCAL_MPI_File_write_ordered_begin)(MPI_File,void *,int,MPI_Datatype);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_write_ordered_begin(MPI_File,void *,int,MPI_Datatype);
extern int INTERF_2_INTEL_CCMPI_File_write_ordered_begin(MPI_File,void *,int,MPI_Datatype);
#endif /*WI4MPI_STATIC*/

int PMPI_File_write_ordered_begin(MPI_File fh,void * buf,int count,MPI_Datatype datatype)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_write_ordered_begin( fh, buf, count, datatype);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_write_ordered_end(MPI_File fh,void * buf,MPI_Status * status);
#pragma weak MPI_File_write_ordered_end=PMPI_File_write_ordered_end
int (*INTERFACE_LOCAL_MPI_File_write_ordered_end)(MPI_File,void *,MPI_Status *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_write_ordered_end(MPI_File,void *,MPI_Status *);
extern int INTERF_2_INTEL_CCMPI_File_write_ordered_end(MPI_File,void *,MPI_Status *);
#endif /*WI4MPI_STATIC*/

int PMPI_File_write_ordered_end(MPI_File fh,void * buf,MPI_Status * status)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_write_ordered_end( fh, buf, status);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_get_type_extent(MPI_File fh,MPI_Datatype datatype,MPI_Aint * extent);
#pragma weak MPI_File_get_type_extent=PMPI_File_get_type_extent
int (*INTERFACE_LOCAL_MPI_File_get_type_extent)(MPI_File,MPI_Datatype,MPI_Aint *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_get_type_extent(MPI_File,MPI_Datatype,MPI_Aint *);
extern int INTERF_2_INTEL_CCMPI_File_get_type_extent(MPI_File,MPI_Datatype,MPI_Aint *);
#endif /*WI4MPI_STATIC*/

int PMPI_File_get_type_extent(MPI_File fh,MPI_Datatype datatype,MPI_Aint * extent)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_get_type_extent( fh, datatype, extent);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Register_datarep(char * datarep,MPI_Datarep_conversion_function * read_conversion_fn,MPI_Datarep_conversion_function * write_conversion_fn,MPI_Datarep_extent_function * dtype_file_extent_fn,void * extra_state);
#pragma weak MPI_Register_datarep=PMPI_Register_datarep
int (*INTERFACE_LOCAL_MPI_Register_datarep)(char *,MPI_Datarep_conversion_function *,MPI_Datarep_conversion_function *,MPI_Datarep_extent_function *,void *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Register_datarep(char *,MPI_Datarep_conversion_function *,MPI_Datarep_conversion_function *,MPI_Datarep_extent_function *,void *);
extern int INTERF_2_INTEL_CCMPI_Register_datarep(char *,MPI_Datarep_conversion_function *,MPI_Datarep_conversion_function *,MPI_Datarep_extent_function *,void *);
#endif /*WI4MPI_STATIC*/

int PMPI_Register_datarep(char * datarep,MPI_Datarep_conversion_function * read_conversion_fn,MPI_Datarep_conversion_function * write_conversion_fn,MPI_Datarep_extent_function * dtype_file_extent_fn,void * extra_state)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Register_datarep( datarep, read_conversion_fn, write_conversion_fn, dtype_file_extent_fn, extra_state);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_set_atomicity(MPI_File fh,int flag);
#pragma weak MPI_File_set_atomicity=PMPI_File_set_atomicity
int (*INTERFACE_LOCAL_MPI_File_set_atomicity)(MPI_File,int);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_set_atomicity(MPI_File,int);
extern int INTERF_2_INTEL_CCMPI_File_set_atomicity(MPI_File,int);
#endif /*WI4MPI_STATIC*/

int PMPI_File_set_atomicity(MPI_File fh,int flag)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_set_atomicity( fh, flag);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_get_atomicity(MPI_File fh,int * flag);
#pragma weak MPI_File_get_atomicity=PMPI_File_get_atomicity
int (*INTERFACE_LOCAL_MPI_File_get_atomicity)(MPI_File,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_get_atomicity(MPI_File,int *);
extern int INTERF_2_INTEL_CCMPI_File_get_atomicity(MPI_File,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_File_get_atomicity(MPI_File fh,int * flag)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_get_atomicity( fh, flag);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_sync(MPI_File fh);
#pragma weak MPI_File_sync=PMPI_File_sync
int (*INTERFACE_LOCAL_MPI_File_sync)(MPI_File);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_sync(MPI_File);
extern int INTERF_2_INTEL_CCMPI_File_sync(MPI_File);
#endif /*WI4MPI_STATIC*/

int PMPI_File_sync(MPI_File fh)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_sync( fh);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_T_finalize( );
#pragma weak MPI_T_finalize=PMPI_T_finalize
int (*INTERFACE_LOCAL_MPI_T_finalize)();
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_T_finalize();
extern int INTERF_2_INTEL_CCMPI_T_finalize();
#endif /*WI4MPI_STATIC*/

int PMPI_T_finalize( )
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_T_finalize( );

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
double MPI_Wtime( );
#pragma weak MPI_Wtime=PMPI_Wtime
double (*INTERFACE_LOCAL_MPI_Wtime)();
#ifdef WI4MPI_STATIC
extern double INTERF_2_OMPI_CCMPI_Wtime();
extern double INTERF_2_INTEL_CCMPI_Wtime();
#endif /*WI4MPI_STATIC*/

double PMPI_Wtime( )
{
#ifdef TIMEOUT_SUPPORT
#endif
double ret_tmp= INTERFACE_LOCAL_MPI_Wtime( );

double ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
double MPI_Wtick( );
#pragma weak MPI_Wtick=PMPI_Wtick
double (*INTERFACE_LOCAL_MPI_Wtick)();
#ifdef WI4MPI_STATIC
extern double INTERF_2_OMPI_CCMPI_Wtick();
extern double INTERF_2_INTEL_CCMPI_Wtick();
#endif /*WI4MPI_STATIC*/

double PMPI_Wtick( )
{
#ifdef TIMEOUT_SUPPORT
#endif
double ret_tmp= INTERFACE_LOCAL_MPI_Wtick( );

double ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Finalize( );
#pragma weak MPI_Finalize=PMPI_Finalize
int (*INTERFACE_LOCAL_MPI_Finalize)();
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Finalize();
extern int INTERF_2_INTEL_CCMPI_Finalize();
#endif /*WI4MPI_STATIC*/

int PMPI_Finalize( )
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Finalize( );

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Waitany(int count,MPI_Request array_of_requests[],int * indx,MPI_Status * status);
#pragma weak MPI_Waitany=PMPI_Waitany
int (*INTERFACE_LOCAL_MPI_Waitany)(int,MPI_Request *,int *,MPI_Status *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Waitany(int,MPI_Request *,int *,MPI_Status *);
extern int INTERF_2_INTEL_CCMPI_Waitany(int,MPI_Request *,int *,MPI_Status *);
#endif /*WI4MPI_STATIC*/

int PMPI_Waitany(int count,MPI_Request array_of_requests[],int * indx,MPI_Status * status)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Waitany( count, array_of_requests, indx, status);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Testany(int count,MPI_Request array_of_requests[],int * indx,int * flag,MPI_Status * status);
#pragma weak MPI_Testany=PMPI_Testany
int (*INTERFACE_LOCAL_MPI_Testany)(int,MPI_Request *,int *,int *,MPI_Status *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Testany(int,MPI_Request *,int *,int *,MPI_Status *);
extern int INTERF_2_INTEL_CCMPI_Testany(int,MPI_Request *,int *,int *,MPI_Status *);
#endif /*WI4MPI_STATIC*/

int PMPI_Testany(int count,MPI_Request array_of_requests[],int * indx,int * flag,MPI_Status * status)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Testany( count, array_of_requests, indx, flag, status);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Waitall(int count,MPI_Request array_of_requests[],MPI_Status array_of_statuses[]);
#pragma weak MPI_Waitall=PMPI_Waitall
int (*INTERFACE_LOCAL_MPI_Waitall)(int,MPI_Request *,MPI_Status *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Waitall(int,MPI_Request *,MPI_Status *);
extern int INTERF_2_INTEL_CCMPI_Waitall(int,MPI_Request *,MPI_Status *);
#endif /*WI4MPI_STATIC*/

int PMPI_Waitall(int count,MPI_Request array_of_requests[],MPI_Status array_of_statuses[])
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Waitall( count, array_of_requests, array_of_statuses);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Testall(int count,MPI_Request array_of_requests[],int * flag,MPI_Status array_of_statuses[]);
#pragma weak MPI_Testall=PMPI_Testall
int (*INTERFACE_LOCAL_MPI_Testall)(int,MPI_Request *,int *,MPI_Status *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Testall(int,MPI_Request *,int *,MPI_Status *);
extern int INTERF_2_INTEL_CCMPI_Testall(int,MPI_Request *,int *,MPI_Status *);
#endif /*WI4MPI_STATIC*/

int PMPI_Testall(int count,MPI_Request array_of_requests[],int * flag,MPI_Status array_of_statuses[])
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Testall( count, array_of_requests, flag, array_of_statuses);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Waitsome(int incount,MPI_Request array_of_requests[],int * outcount,int array_of_indices[],MPI_Status array_of_statuses[]);
#pragma weak MPI_Waitsome=PMPI_Waitsome
int (*INTERFACE_LOCAL_MPI_Waitsome)(int,MPI_Request *,int *,int *,MPI_Status *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Waitsome(int,MPI_Request *,int *,int *,MPI_Status *);
extern int INTERF_2_INTEL_CCMPI_Waitsome(int,MPI_Request *,int *,int *,MPI_Status *);
#endif /*WI4MPI_STATIC*/

int PMPI_Waitsome(int incount,MPI_Request array_of_requests[],int * outcount,int array_of_indices[],MPI_Status array_of_statuses[])
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Waitsome( incount, array_of_requests, outcount, array_of_indices, array_of_statuses);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Testsome(int incount,MPI_Request array_of_requests[],int * outcount,int array_of_indices[],MPI_Status array_of_statuses[]);
#pragma weak MPI_Testsome=PMPI_Testsome
int (*INTERFACE_LOCAL_MPI_Testsome)(int,MPI_Request *,int *,int *,MPI_Status *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Testsome(int,MPI_Request *,int *,int *,MPI_Status *);
extern int INTERF_2_INTEL_CCMPI_Testsome(int,MPI_Request *,int *,int *,MPI_Status *);
#endif /*WI4MPI_STATIC*/

int PMPI_Testsome(int incount,MPI_Request array_of_requests[],int * outcount,int array_of_indices[],MPI_Status array_of_statuses[])
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Testsome( incount, array_of_requests, outcount, array_of_indices, array_of_statuses);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Startall(int count,MPI_Request array_of_requests[]);
#pragma weak MPI_Startall=PMPI_Startall
int (*INTERFACE_LOCAL_MPI_Startall)(int,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Startall(int,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Startall(int,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Startall(int count,MPI_Request array_of_requests[])
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Startall( count, array_of_requests);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Alltoallw(void * sendbuf,int sendcounts[],int sdispls[],MPI_Datatype sendtypes[],void * recvbuf,int recvcounts[],int rdispls[],MPI_Datatype recvtypes[],MPI_Comm comm);
#pragma weak MPI_Alltoallw=PMPI_Alltoallw
int (*INTERFACE_LOCAL_MPI_Alltoallw)(void *,int *,int *,MPI_Datatype *,void *,int *,int *,MPI_Datatype *,MPI_Comm);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Alltoallw(void *,int *,int *,MPI_Datatype *,void *,int *,int *,MPI_Datatype *,MPI_Comm);
extern int INTERF_2_INTEL_CCMPI_Alltoallw(void *,int *,int *,MPI_Datatype *,void *,int *,int *,MPI_Datatype *,MPI_Comm);
#endif /*WI4MPI_STATIC*/

int PMPI_Alltoallw(void * sendbuf,int sendcounts[],int sdispls[],MPI_Datatype sendtypes[],void * recvbuf,int recvcounts[],int rdispls[],MPI_Datatype recvtypes[],MPI_Comm comm)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Alltoallw( sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Reduce_scatter(void * sendbuf,void * recvbuf,int recvcounts[],MPI_Datatype datatype,MPI_Op op,MPI_Comm comm);
#pragma weak MPI_Reduce_scatter=PMPI_Reduce_scatter
int (*INTERFACE_LOCAL_MPI_Reduce_scatter)(void *,void *,int *,MPI_Datatype,MPI_Op,MPI_Comm);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Reduce_scatter(void *,void *,int *,MPI_Datatype,MPI_Op,MPI_Comm);
extern int INTERF_2_INTEL_CCMPI_Reduce_scatter(void *,void *,int *,MPI_Datatype,MPI_Op,MPI_Comm);
#endif /*WI4MPI_STATIC*/

int PMPI_Reduce_scatter(void * sendbuf,void * recvbuf,int recvcounts[],MPI_Datatype datatype,MPI_Op op,MPI_Comm comm)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Reduce_scatter( sendbuf, recvbuf, recvcounts, datatype, op, comm);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Group_translate_ranks(MPI_Group group1,int n,int ranks1[],MPI_Group group2,int ranks2[]);
#pragma weak MPI_Group_translate_ranks=PMPI_Group_translate_ranks
int (*INTERFACE_LOCAL_MPI_Group_translate_ranks)(MPI_Group,int,int *,MPI_Group,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Group_translate_ranks(MPI_Group,int,int *,MPI_Group,int *);
extern int INTERF_2_INTEL_CCMPI_Group_translate_ranks(MPI_Group,int,int *,MPI_Group,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Group_translate_ranks(MPI_Group group1,int n,int ranks1[],MPI_Group group2,int ranks2[])
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Group_translate_ranks( group1, n, ranks1, group2, ranks2);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Group_incl(MPI_Group group,int n,int ranks[],MPI_Group * newgroup);
#pragma weak MPI_Group_incl=PMPI_Group_incl
int (*INTERFACE_LOCAL_MPI_Group_incl)(MPI_Group,int,int *,MPI_Group *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Group_incl(MPI_Group,int,int *,MPI_Group *);
extern int INTERF_2_INTEL_CCMPI_Group_incl(MPI_Group,int,int *,MPI_Group *);
#endif /*WI4MPI_STATIC*/

int PMPI_Group_incl(MPI_Group group,int n,int ranks[],MPI_Group * newgroup)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Group_incl( group, n, ranks, newgroup);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Group_excl(MPI_Group group,int n,int ranks[],MPI_Group * newgroup);
#pragma weak MPI_Group_excl=PMPI_Group_excl
int (*INTERFACE_LOCAL_MPI_Group_excl)(MPI_Group,int,int *,MPI_Group *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Group_excl(MPI_Group,int,int *,MPI_Group *);
extern int INTERF_2_INTEL_CCMPI_Group_excl(MPI_Group,int,int *,MPI_Group *);
#endif /*WI4MPI_STATIC*/

int PMPI_Group_excl(MPI_Group group,int n,int ranks[],MPI_Group * newgroup)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Group_excl( group, n, ranks, newgroup);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Group_range_incl(MPI_Group group,int n,int ranges[][3],MPI_Group * newgroup);
#pragma weak MPI_Group_range_incl=PMPI_Group_range_incl
int (*INTERFACE_LOCAL_MPI_Group_range_incl)(MPI_Group,int,int[][3],MPI_Group *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Group_range_incl(MPI_Group,int,int[][3],MPI_Group *);
extern int INTERF_2_INTEL_CCMPI_Group_range_incl(MPI_Group,int,int[][3],MPI_Group *);
#endif /*WI4MPI_STATIC*/

int PMPI_Group_range_incl(MPI_Group group,int n,int ranges[][3],MPI_Group * newgroup)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Group_range_incl( group, n, ranges, newgroup);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Group_range_excl(MPI_Group group,int n,int ranges[][3],MPI_Group * newgroup);
#pragma weak MPI_Group_range_excl=PMPI_Group_range_excl
int (*INTERFACE_LOCAL_MPI_Group_range_excl)(MPI_Group,int,int[][3],MPI_Group *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Group_range_excl(MPI_Group,int,int[][3],MPI_Group *);
extern int INTERF_2_INTEL_CCMPI_Group_range_excl(MPI_Group,int,int[][3],MPI_Group *);
#endif /*WI4MPI_STATIC*/

int PMPI_Group_range_excl(MPI_Group group,int n,int ranges[][3],MPI_Group * newgroup)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Group_range_excl( group, n, ranges, newgroup);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Cart_create(MPI_Comm comm_old,int ndims,int dims[],int periods[],int reorder,MPI_Comm * comm_cart);
#pragma weak MPI_Cart_create=PMPI_Cart_create
int (*INTERFACE_LOCAL_MPI_Cart_create)(MPI_Comm,int,int *,int *,int,MPI_Comm *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Cart_create(MPI_Comm,int,int *,int *,int,MPI_Comm *);
extern int INTERF_2_INTEL_CCMPI_Cart_create(MPI_Comm,int,int *,int *,int,MPI_Comm *);
#endif /*WI4MPI_STATIC*/

int PMPI_Cart_create(MPI_Comm comm_old,int ndims,int dims[],int periods[],int reorder,MPI_Comm * comm_cart)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Cart_create( comm_old, ndims, dims, periods, reorder, comm_cart);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Dims_create(int nnodes,int ndims,int dims[]);
#pragma weak MPI_Dims_create=PMPI_Dims_create
int (*INTERFACE_LOCAL_MPI_Dims_create)(int,int,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Dims_create(int,int,int *);
extern int INTERF_2_INTEL_CCMPI_Dims_create(int,int,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Dims_create(int nnodes,int ndims,int dims[])
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Dims_create( nnodes, ndims, dims);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Graph_create(MPI_Comm comm_old,int nnodes,int indx[],int edges[],int reorder,MPI_Comm * comm_graph);
#pragma weak MPI_Graph_create=PMPI_Graph_create
int (*INTERFACE_LOCAL_MPI_Graph_create)(MPI_Comm,int,int *,int *,int,MPI_Comm *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Graph_create(MPI_Comm,int,int *,int *,int,MPI_Comm *);
extern int INTERF_2_INTEL_CCMPI_Graph_create(MPI_Comm,int,int *,int *,int,MPI_Comm *);
#endif /*WI4MPI_STATIC*/

int PMPI_Graph_create(MPI_Comm comm_old,int nnodes,int indx[],int edges[],int reorder,MPI_Comm * comm_graph)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Graph_create( comm_old, nnodes, indx, edges, reorder, comm_graph);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Graph_get(MPI_Comm comm,int maxindex,int maxedges,int indx[],int edges[]);
#pragma weak MPI_Graph_get=PMPI_Graph_get
int (*INTERFACE_LOCAL_MPI_Graph_get)(MPI_Comm,int,int,int *,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Graph_get(MPI_Comm,int,int,int *,int *);
extern int INTERF_2_INTEL_CCMPI_Graph_get(MPI_Comm,int,int,int *,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Graph_get(MPI_Comm comm,int maxindex,int maxedges,int indx[],int edges[])
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Graph_get( comm, maxindex, maxedges, indx, edges);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Cart_get(MPI_Comm comm,int maxdims,int dims[],int periods[],int coords[]);
#pragma weak MPI_Cart_get=PMPI_Cart_get
int (*INTERFACE_LOCAL_MPI_Cart_get)(MPI_Comm,int,int *,int *,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Cart_get(MPI_Comm,int,int *,int *,int *);
extern int INTERF_2_INTEL_CCMPI_Cart_get(MPI_Comm,int,int *,int *,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Cart_get(MPI_Comm comm,int maxdims,int dims[],int periods[],int coords[])
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Cart_get( comm, maxdims, dims, periods, coords);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Cart_rank(MPI_Comm comm,int coords[],int * rank);
#pragma weak MPI_Cart_rank=PMPI_Cart_rank
int (*INTERFACE_LOCAL_MPI_Cart_rank)(MPI_Comm,int *,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Cart_rank(MPI_Comm,int *,int *);
extern int INTERF_2_INTEL_CCMPI_Cart_rank(MPI_Comm,int *,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Cart_rank(MPI_Comm comm,int coords[],int * rank)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Cart_rank( comm, coords, rank);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Cart_coords(MPI_Comm comm,int rank,int maxdims,int coords[]);
#pragma weak MPI_Cart_coords=PMPI_Cart_coords
int (*INTERFACE_LOCAL_MPI_Cart_coords)(MPI_Comm,int,int,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Cart_coords(MPI_Comm,int,int,int *);
extern int INTERF_2_INTEL_CCMPI_Cart_coords(MPI_Comm,int,int,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Cart_coords(MPI_Comm comm,int rank,int maxdims,int coords[])
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Cart_coords( comm, rank, maxdims, coords);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Graph_neighbors(MPI_Comm comm,int rank,int maxneighbors,int neighbors[]);
#pragma weak MPI_Graph_neighbors=PMPI_Graph_neighbors
int (*INTERFACE_LOCAL_MPI_Graph_neighbors)(MPI_Comm,int,int,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Graph_neighbors(MPI_Comm,int,int,int *);
extern int INTERF_2_INTEL_CCMPI_Graph_neighbors(MPI_Comm,int,int,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Graph_neighbors(MPI_Comm comm,int rank,int maxneighbors,int neighbors[])
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Graph_neighbors( comm, rank, maxneighbors, neighbors);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Cart_sub(MPI_Comm comm,int remain_dims[],MPI_Comm * newcomm);
#pragma weak MPI_Cart_sub=PMPI_Cart_sub
int (*INTERFACE_LOCAL_MPI_Cart_sub)(MPI_Comm,int *,MPI_Comm *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Cart_sub(MPI_Comm,int *,MPI_Comm *);
extern int INTERF_2_INTEL_CCMPI_Cart_sub(MPI_Comm,int *,MPI_Comm *);
#endif /*WI4MPI_STATIC*/

int PMPI_Cart_sub(MPI_Comm comm,int remain_dims[],MPI_Comm * newcomm)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Cart_sub( comm, remain_dims, newcomm);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Cart_map(MPI_Comm comm,int ndims,int dims[],int periods[],int * newrank);
#pragma weak MPI_Cart_map=PMPI_Cart_map
int (*INTERFACE_LOCAL_MPI_Cart_map)(MPI_Comm,int,int *,int *,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Cart_map(MPI_Comm,int,int *,int *,int *);
extern int INTERF_2_INTEL_CCMPI_Cart_map(MPI_Comm,int,int *,int *,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Cart_map(MPI_Comm comm,int ndims,int dims[],int periods[],int * newrank)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Cart_map( comm, ndims, dims, periods, newrank);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Graph_map(MPI_Comm comm,int nnodes,int indx[],int edges[],int * newrank);
#pragma weak MPI_Graph_map=PMPI_Graph_map
int (*INTERFACE_LOCAL_MPI_Graph_map)(MPI_Comm,int,int *,int *,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Graph_map(MPI_Comm,int,int *,int *,int *);
extern int INTERF_2_INTEL_CCMPI_Graph_map(MPI_Comm,int,int *,int *,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Graph_map(MPI_Comm comm,int nnodes,int indx[],int edges[],int * newrank)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Graph_map( comm, nnodes, indx, edges, newrank);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Comm_spawn(char * command,char * argv[],int maxprocs,MPI_Info info,int root,MPI_Comm comm,MPI_Comm * intercomm,int array_of_errcodes[]);
#pragma weak MPI_Comm_spawn=PMPI_Comm_spawn
int (*INTERFACE_LOCAL_MPI_Comm_spawn)(char *,char * *,int,MPI_Info,int,MPI_Comm,MPI_Comm *,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Comm_spawn(char *,char * *,int,MPI_Info,int,MPI_Comm,MPI_Comm *,int *);
extern int INTERF_2_INTEL_CCMPI_Comm_spawn(char *,char * *,int,MPI_Info,int,MPI_Comm,MPI_Comm *,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Comm_spawn(char * command,char * argv[],int maxprocs,MPI_Info info,int root,MPI_Comm comm,MPI_Comm * intercomm,int array_of_errcodes[])
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Comm_spawn( command, argv, maxprocs, info, root, comm, intercomm, array_of_errcodes);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Comm_spawn_multiple(int count,char * array_of_commands[],char ** array_of_argv[],int array_of_maxprocs[],MPI_Info array_of_info[],int root,MPI_Comm comm,MPI_Comm * intercomm,int array_of_errcodes[]);
#pragma weak MPI_Comm_spawn_multiple=PMPI_Comm_spawn_multiple
int (*INTERFACE_LOCAL_MPI_Comm_spawn_multiple)(int,char * *,char ** *,int *,MPI_Info *,int,MPI_Comm,MPI_Comm *,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Comm_spawn_multiple(int,char * *,char ** *,int *,MPI_Info *,int,MPI_Comm,MPI_Comm *,int *);
extern int INTERF_2_INTEL_CCMPI_Comm_spawn_multiple(int,char * *,char ** *,int *,MPI_Info *,int,MPI_Comm,MPI_Comm *,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Comm_spawn_multiple(int count,char * array_of_commands[],char ** array_of_argv[],int array_of_maxprocs[],MPI_Info array_of_info[],int root,MPI_Comm comm,MPI_Comm * intercomm,int array_of_errcodes[])
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Comm_spawn_multiple( count, array_of_commands, array_of_argv, array_of_maxprocs, array_of_info, root, comm, intercomm, array_of_errcodes);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Type_get_contents(MPI_Datatype datatype,int max_integers,int max_addresses,int max_datatypes,int array_of_integers[],MPI_Aint array_of_addresses[],MPI_Datatype array_of_datatypes[]);
#pragma weak MPI_Type_get_contents=PMPI_Type_get_contents
int (*INTERFACE_LOCAL_MPI_Type_get_contents)(MPI_Datatype,int,int,int,int *,MPI_Aint *,MPI_Datatype *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Type_get_contents(MPI_Datatype,int,int,int,int *,MPI_Aint *,MPI_Datatype *);
extern int INTERF_2_INTEL_CCMPI_Type_get_contents(MPI_Datatype,int,int,int,int *,MPI_Aint *,MPI_Datatype *);
#endif /*WI4MPI_STATIC*/

int PMPI_Type_get_contents(MPI_Datatype datatype,int max_integers,int max_addresses,int max_datatypes,int array_of_integers[],MPI_Aint array_of_addresses[],MPI_Datatype array_of_datatypes[])
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Type_get_contents( datatype, max_integers, max_addresses, max_datatypes, array_of_integers, array_of_addresses, array_of_datatypes);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Pack_external(char datarep[],void * inbuf,int incount,MPI_Datatype datatype,void * outbuf,MPI_Aint outsize,MPI_Aint * position);
#pragma weak MPI_Pack_external=PMPI_Pack_external
int (*INTERFACE_LOCAL_MPI_Pack_external)(char *,void *,int,MPI_Datatype,void *,MPI_Aint,MPI_Aint *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Pack_external(char *,void *,int,MPI_Datatype,void *,MPI_Aint,MPI_Aint *);
extern int INTERF_2_INTEL_CCMPI_Pack_external(char *,void *,int,MPI_Datatype,void *,MPI_Aint,MPI_Aint *);
#endif /*WI4MPI_STATIC*/

int PMPI_Pack_external(char datarep[],void * inbuf,int incount,MPI_Datatype datatype,void * outbuf,MPI_Aint outsize,MPI_Aint * position)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Pack_external( datarep, inbuf, incount, datatype, outbuf, outsize, position);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Pack_external_size(char datarep[],int incount,MPI_Datatype datatype,MPI_Aint * size);
#pragma weak MPI_Pack_external_size=PMPI_Pack_external_size
int (*INTERFACE_LOCAL_MPI_Pack_external_size)(char *,int,MPI_Datatype,MPI_Aint *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Pack_external_size(char *,int,MPI_Datatype,MPI_Aint *);
extern int INTERF_2_INTEL_CCMPI_Pack_external_size(char *,int,MPI_Datatype,MPI_Aint *);
#endif /*WI4MPI_STATIC*/

int PMPI_Pack_external_size(char datarep[],int incount,MPI_Datatype datatype,MPI_Aint * size)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Pack_external_size( datarep, incount, datatype, size);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Type_create_darray(int size,int rank,int ndims,int array_of_gsizes[],int array_of_distribs[],int array_of_dargs[],int array_of_psizes[],int order,MPI_Datatype oldtype,MPI_Datatype * newtype);
#pragma weak MPI_Type_create_darray=PMPI_Type_create_darray
int (*INTERFACE_LOCAL_MPI_Type_create_darray)(int,int,int,int *,int *,int *,int *,int,MPI_Datatype,MPI_Datatype *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Type_create_darray(int,int,int,int *,int *,int *,int *,int,MPI_Datatype,MPI_Datatype *);
extern int INTERF_2_INTEL_CCMPI_Type_create_darray(int,int,int,int *,int *,int *,int *,int,MPI_Datatype,MPI_Datatype *);
#endif /*WI4MPI_STATIC*/

int PMPI_Type_create_darray(int size,int rank,int ndims,int array_of_gsizes[],int array_of_distribs[],int array_of_dargs[],int array_of_psizes[],int order,MPI_Datatype oldtype,MPI_Datatype * newtype)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Type_create_darray( size, rank, ndims, array_of_gsizes, array_of_distribs, array_of_dargs, array_of_psizes, order, oldtype, newtype);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Type_create_hindexed(int count,int array_of_blocklengths[],MPI_Aint array_of_displacements[],MPI_Datatype oldtype,MPI_Datatype * newtype);
#pragma weak MPI_Type_create_hindexed=PMPI_Type_create_hindexed
int (*INTERFACE_LOCAL_MPI_Type_create_hindexed)(int,int *,MPI_Aint *,MPI_Datatype,MPI_Datatype *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Type_create_hindexed(int,int *,MPI_Aint *,MPI_Datatype,MPI_Datatype *);
extern int INTERF_2_INTEL_CCMPI_Type_create_hindexed(int,int *,MPI_Aint *,MPI_Datatype,MPI_Datatype *);
#endif /*WI4MPI_STATIC*/

int PMPI_Type_create_hindexed(int count,int array_of_blocklengths[],MPI_Aint array_of_displacements[],MPI_Datatype oldtype,MPI_Datatype * newtype)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Type_create_hindexed( count, array_of_blocklengths, array_of_displacements, oldtype, newtype);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Type_create_indexed_block(int count,int blocklength,int array_of_displacements[],MPI_Datatype oldtype,MPI_Datatype * newtype);
#pragma weak MPI_Type_create_indexed_block=PMPI_Type_create_indexed_block
int (*INTERFACE_LOCAL_MPI_Type_create_indexed_block)(int,int,int *,MPI_Datatype,MPI_Datatype *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Type_create_indexed_block(int,int,int *,MPI_Datatype,MPI_Datatype *);
extern int INTERF_2_INTEL_CCMPI_Type_create_indexed_block(int,int,int *,MPI_Datatype,MPI_Datatype *);
#endif /*WI4MPI_STATIC*/

int PMPI_Type_create_indexed_block(int count,int blocklength,int array_of_displacements[],MPI_Datatype oldtype,MPI_Datatype * newtype)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Type_create_indexed_block( count, blocklength, array_of_displacements, oldtype, newtype);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Type_create_hindexed_block(int count,int blocklength,MPI_Aint array_of_displacements[],MPI_Datatype oldtype,MPI_Datatype * newtype);
#pragma weak MPI_Type_create_hindexed_block=PMPI_Type_create_hindexed_block
int (*INTERFACE_LOCAL_MPI_Type_create_hindexed_block)(int,int,MPI_Aint *,MPI_Datatype,MPI_Datatype *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Type_create_hindexed_block(int,int,MPI_Aint *,MPI_Datatype,MPI_Datatype *);
extern int INTERF_2_INTEL_CCMPI_Type_create_hindexed_block(int,int,MPI_Aint *,MPI_Datatype,MPI_Datatype *);
#endif /*WI4MPI_STATIC*/

int PMPI_Type_create_hindexed_block(int count,int blocklength,MPI_Aint array_of_displacements[],MPI_Datatype oldtype,MPI_Datatype * newtype)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Type_create_hindexed_block( count, blocklength, array_of_displacements, oldtype, newtype);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Type_create_struct(int count,int array_of_blocklengths[],MPI_Aint array_of_displacements[],MPI_Datatype array_of_types[],MPI_Datatype * newtype);
#pragma weak MPI_Type_create_struct=PMPI_Type_create_struct
int (*INTERFACE_LOCAL_MPI_Type_create_struct)(int,int *,MPI_Aint *,MPI_Datatype *,MPI_Datatype *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Type_create_struct(int,int *,MPI_Aint *,MPI_Datatype *,MPI_Datatype *);
extern int INTERF_2_INTEL_CCMPI_Type_create_struct(int,int *,MPI_Aint *,MPI_Datatype *,MPI_Datatype *);
#endif /*WI4MPI_STATIC*/

int PMPI_Type_create_struct(int count,int array_of_blocklengths[],MPI_Aint array_of_displacements[],MPI_Datatype array_of_types[],MPI_Datatype * newtype)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Type_create_struct( count, array_of_blocklengths, array_of_displacements, array_of_types, newtype);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Type_create_subarray(int ndims,int array_of_sizes[],int array_of_subsizes[],int array_of_starts[],int order,MPI_Datatype oldtype,MPI_Datatype * newtype);
#pragma weak MPI_Type_create_subarray=PMPI_Type_create_subarray
int (*INTERFACE_LOCAL_MPI_Type_create_subarray)(int,int *,int *,int *,int,MPI_Datatype,MPI_Datatype *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Type_create_subarray(int,int *,int *,int *,int,MPI_Datatype,MPI_Datatype *);
extern int INTERF_2_INTEL_CCMPI_Type_create_subarray(int,int *,int *,int *,int,MPI_Datatype,MPI_Datatype *);
#endif /*WI4MPI_STATIC*/

int PMPI_Type_create_subarray(int ndims,int array_of_sizes[],int array_of_subsizes[],int array_of_starts[],int order,MPI_Datatype oldtype,MPI_Datatype * newtype)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Type_create_subarray( ndims, array_of_sizes, array_of_subsizes, array_of_starts, order, oldtype, newtype);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Unpack_external(char datarep[],void * inbuf,MPI_Aint insize,MPI_Aint * position,void * outbuf,int outcount,MPI_Datatype datatype);
#pragma weak MPI_Unpack_external=PMPI_Unpack_external
int (*INTERFACE_LOCAL_MPI_Unpack_external)(char *,void *,MPI_Aint,MPI_Aint *,void *,int,MPI_Datatype);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Unpack_external(char *,void *,MPI_Aint,MPI_Aint *,void *,int,MPI_Datatype);
extern int INTERF_2_INTEL_CCMPI_Unpack_external(char *,void *,MPI_Aint,MPI_Aint *,void *,int,MPI_Datatype);
#endif /*WI4MPI_STATIC*/

int PMPI_Unpack_external(char datarep[],void * inbuf,MPI_Aint insize,MPI_Aint * position,void * outbuf,int outcount,MPI_Datatype datatype)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Unpack_external( datarep, inbuf, insize, position, outbuf, outcount, datatype);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Dist_graph_create_adjacent(MPI_Comm comm_old,int indegree,int sources[],int * sourceweights,int outdegree,int destinations[],int * destweights,MPI_Info info,int reorder,MPI_Comm * comm_dist_graph);
#pragma weak MPI_Dist_graph_create_adjacent=PMPI_Dist_graph_create_adjacent
int (*INTERFACE_LOCAL_MPI_Dist_graph_create_adjacent)(MPI_Comm,int,int *,int *,int,int *,int *,MPI_Info,int,MPI_Comm *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Dist_graph_create_adjacent(MPI_Comm,int,int *,int *,int,int *,int *,MPI_Info,int,MPI_Comm *);
extern int INTERF_2_INTEL_CCMPI_Dist_graph_create_adjacent(MPI_Comm,int,int *,int *,int,int *,int *,MPI_Info,int,MPI_Comm *);
#endif /*WI4MPI_STATIC*/

int PMPI_Dist_graph_create_adjacent(MPI_Comm comm_old,int indegree,int sources[],int * sourceweights,int outdegree,int destinations[],int * destweights,MPI_Info info,int reorder,MPI_Comm * comm_dist_graph)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Dist_graph_create_adjacent( comm_old, indegree, sources, sourceweights, outdegree, destinations, destweights, info, reorder, comm_dist_graph);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Dist_graph_create(MPI_Comm comm_old,int n,int sources[],int degrees[],int destinations[],int * weights,MPI_Info info,int reorder,MPI_Comm * comm_dist_graph);
#pragma weak MPI_Dist_graph_create=PMPI_Dist_graph_create
int (*INTERFACE_LOCAL_MPI_Dist_graph_create)(MPI_Comm,int,int *,int *,int *,int *,MPI_Info,int,MPI_Comm *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Dist_graph_create(MPI_Comm,int,int *,int *,int *,int *,MPI_Info,int,MPI_Comm *);
extern int INTERF_2_INTEL_CCMPI_Dist_graph_create(MPI_Comm,int,int *,int *,int *,int *,MPI_Info,int,MPI_Comm *);
#endif /*WI4MPI_STATIC*/

int PMPI_Dist_graph_create(MPI_Comm comm_old,int n,int sources[],int degrees[],int destinations[],int * weights,MPI_Info info,int reorder,MPI_Comm * comm_dist_graph)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Dist_graph_create( comm_old, n, sources, degrees, destinations, weights, info, reorder, comm_dist_graph);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Dist_graph_neighbors(MPI_Comm comm,int maxindegree,int sources[],int * sourceweights,int maxoutdegree,int destinations[],int * destweights);
#pragma weak MPI_Dist_graph_neighbors=PMPI_Dist_graph_neighbors
int (*INTERFACE_LOCAL_MPI_Dist_graph_neighbors)(MPI_Comm,int,int *,int *,int,int *,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Dist_graph_neighbors(MPI_Comm,int,int *,int *,int,int *,int *);
extern int INTERF_2_INTEL_CCMPI_Dist_graph_neighbors(MPI_Comm,int,int *,int *,int,int *,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_Dist_graph_neighbors(MPI_Comm comm,int maxindegree,int sources[],int * sourceweights,int maxoutdegree,int destinations[],int * destweights)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Dist_graph_neighbors( comm, maxindegree, sources, sourceweights, maxoutdegree, destinations, destweights);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Igatherv(void * sendbuf,int sendcount,MPI_Datatype sendtype,void * recvbuf,int recvcounts[],int displs[],MPI_Datatype recvtype,int root,MPI_Comm comm,MPI_Request * request);
#pragma weak MPI_Igatherv=PMPI_Igatherv
int (*INTERFACE_LOCAL_MPI_Igatherv)(void *,int,MPI_Datatype,void *,int *,int *,MPI_Datatype,int,MPI_Comm,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Igatherv(void *,int,MPI_Datatype,void *,int *,int *,MPI_Datatype,int,MPI_Comm,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Igatherv(void *,int,MPI_Datatype,void *,int *,int *,MPI_Datatype,int,MPI_Comm,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Igatherv(void * sendbuf,int sendcount,MPI_Datatype sendtype,void * recvbuf,int recvcounts[],int displs[],MPI_Datatype recvtype,int root,MPI_Comm comm,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Igatherv( sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Iscatterv(void * sendbuf,int sendcounts[],int * displs,MPI_Datatype sendtype,void * recvbuf,int recvcount,MPI_Datatype recvtype,int root,MPI_Comm comm,MPI_Request * request);
#pragma weak MPI_Iscatterv=PMPI_Iscatterv
int (*INTERFACE_LOCAL_MPI_Iscatterv)(void *,int *,int *,MPI_Datatype,void *,int,MPI_Datatype,int,MPI_Comm,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Iscatterv(void *,int *,int *,MPI_Datatype,void *,int,MPI_Datatype,int,MPI_Comm,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Iscatterv(void *,int *,int *,MPI_Datatype,void *,int,MPI_Datatype,int,MPI_Comm,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Iscatterv(void * sendbuf,int sendcounts[],int * displs,MPI_Datatype sendtype,void * recvbuf,int recvcount,MPI_Datatype recvtype,int root,MPI_Comm comm,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Iscatterv( sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Iallgatherv(void * sendbuf,int sendcount,MPI_Datatype sendtype,void * recvbuf,int recvcounts[],int displs[],MPI_Datatype recvtype,MPI_Comm comm,MPI_Request * request);
#pragma weak MPI_Iallgatherv=PMPI_Iallgatherv
int (*INTERFACE_LOCAL_MPI_Iallgatherv)(void *,int,MPI_Datatype,void *,int *,int *,MPI_Datatype,MPI_Comm,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Iallgatherv(void *,int,MPI_Datatype,void *,int *,int *,MPI_Datatype,MPI_Comm,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Iallgatherv(void *,int,MPI_Datatype,void *,int *,int *,MPI_Datatype,MPI_Comm,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Iallgatherv(void * sendbuf,int sendcount,MPI_Datatype sendtype,void * recvbuf,int recvcounts[],int displs[],MPI_Datatype recvtype,MPI_Comm comm,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Iallgatherv( sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Ialltoallv(void * sendbuf,int * sendcounts,int * sdispls,MPI_Datatype sendtype,void * recvbuf,int * recvcounts,int * rdispls,MPI_Datatype recvtype,MPI_Comm comm,MPI_Request * request);
#pragma weak MPI_Ialltoallv=PMPI_Ialltoallv
int (*INTERFACE_LOCAL_MPI_Ialltoallv)(void *,int *,int *,MPI_Datatype,void *,int *,int *,MPI_Datatype,MPI_Comm,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Ialltoallv(void *,int *,int *,MPI_Datatype,void *,int *,int *,MPI_Datatype,MPI_Comm,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Ialltoallv(void *,int *,int *,MPI_Datatype,void *,int *,int *,MPI_Datatype,MPI_Comm,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Ialltoallv(void * sendbuf,int * sendcounts,int * sdispls,MPI_Datatype sendtype,void * recvbuf,int * recvcounts,int * rdispls,MPI_Datatype recvtype,MPI_Comm comm,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Ialltoallv( sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Ialltoallw(void * sendbuf,int sendcounts[],int sdispls[],MPI_Datatype sendtypes[],void * recvbuf,int recvcounts[],int rdispls[],MPI_Datatype recvtypes[],MPI_Comm comm,MPI_Request * request);
#pragma weak MPI_Ialltoallw=PMPI_Ialltoallw
int (*INTERFACE_LOCAL_MPI_Ialltoallw)(void *,int *,int *,MPI_Datatype *,void *,int *,int *,MPI_Datatype *,MPI_Comm,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Ialltoallw(void *,int *,int *,MPI_Datatype *,void *,int *,int *,MPI_Datatype *,MPI_Comm,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Ialltoallw(void *,int *,int *,MPI_Datatype *,void *,int *,int *,MPI_Datatype *,MPI_Comm,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Ialltoallw(void * sendbuf,int sendcounts[],int sdispls[],MPI_Datatype sendtypes[],void * recvbuf,int recvcounts[],int rdispls[],MPI_Datatype recvtypes[],MPI_Comm comm,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Ialltoallw( sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Ireduce_scatter(void * sendbuf,void * recvbuf,int recvcounts[],MPI_Datatype datatype,MPI_Op op,MPI_Comm comm,MPI_Request * request);
#pragma weak MPI_Ireduce_scatter=PMPI_Ireduce_scatter
int (*INTERFACE_LOCAL_MPI_Ireduce_scatter)(void *,void *,int *,MPI_Datatype,MPI_Op,MPI_Comm,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Ireduce_scatter(void *,void *,int *,MPI_Datatype,MPI_Op,MPI_Comm,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Ireduce_scatter(void *,void *,int *,MPI_Datatype,MPI_Op,MPI_Comm,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Ireduce_scatter(void * sendbuf,void * recvbuf,int recvcounts[],MPI_Datatype datatype,MPI_Op op,MPI_Comm comm,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Ireduce_scatter( sendbuf, recvbuf, recvcounts, datatype, op, comm, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Ineighbor_allgatherv(void * sendbuf,int sendcount,MPI_Datatype sendtype,void * recvbuf,int recvcounts[],int displs[],MPI_Datatype recvtype,MPI_Comm comm,MPI_Request * request);
#pragma weak MPI_Ineighbor_allgatherv=PMPI_Ineighbor_allgatherv
int (*INTERFACE_LOCAL_MPI_Ineighbor_allgatherv)(void *,int,MPI_Datatype,void *,int *,int *,MPI_Datatype,MPI_Comm,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Ineighbor_allgatherv(void *,int,MPI_Datatype,void *,int *,int *,MPI_Datatype,MPI_Comm,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Ineighbor_allgatherv(void *,int,MPI_Datatype,void *,int *,int *,MPI_Datatype,MPI_Comm,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Ineighbor_allgatherv(void * sendbuf,int sendcount,MPI_Datatype sendtype,void * recvbuf,int recvcounts[],int displs[],MPI_Datatype recvtype,MPI_Comm comm,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Ineighbor_allgatherv( sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Ineighbor_alltoallv(void * sendbuf,int sendcounts[],int sdispls[],MPI_Datatype sendtype,void * recvbuf,int recvcounts[],int rdispls[],MPI_Datatype recvtype,MPI_Comm comm,MPI_Request * request);
#pragma weak MPI_Ineighbor_alltoallv=PMPI_Ineighbor_alltoallv
int (*INTERFACE_LOCAL_MPI_Ineighbor_alltoallv)(void *,int *,int *,MPI_Datatype,void *,int *,int *,MPI_Datatype,MPI_Comm,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Ineighbor_alltoallv(void *,int *,int *,MPI_Datatype,void *,int *,int *,MPI_Datatype,MPI_Comm,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Ineighbor_alltoallv(void *,int *,int *,MPI_Datatype,void *,int *,int *,MPI_Datatype,MPI_Comm,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Ineighbor_alltoallv(void * sendbuf,int sendcounts[],int sdispls[],MPI_Datatype sendtype,void * recvbuf,int recvcounts[],int rdispls[],MPI_Datatype recvtype,MPI_Comm comm,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Ineighbor_alltoallv( sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Ineighbor_alltoallw(void * sendbuf,int sendcounts[],MPI_Aint sdispls[],MPI_Datatype sendtypes[],void * recvbuf,int recvcounts[],MPI_Aint rdispls[],MPI_Datatype recvtypes[],MPI_Comm comm,MPI_Request * request);
#pragma weak MPI_Ineighbor_alltoallw=PMPI_Ineighbor_alltoallw
int (*INTERFACE_LOCAL_MPI_Ineighbor_alltoallw)(void *,int *,MPI_Aint *,MPI_Datatype *,void *,int *,MPI_Aint *,MPI_Datatype *,MPI_Comm,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Ineighbor_alltoallw(void *,int *,MPI_Aint *,MPI_Datatype *,void *,int *,MPI_Aint *,MPI_Datatype *,MPI_Comm,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_Ineighbor_alltoallw(void *,int *,MPI_Aint *,MPI_Datatype *,void *,int *,MPI_Aint *,MPI_Datatype *,MPI_Comm,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_Ineighbor_alltoallw(void * sendbuf,int sendcounts[],MPI_Aint sdispls[],MPI_Datatype sendtypes[],void * recvbuf,int recvcounts[],MPI_Aint rdispls[],MPI_Datatype recvtypes[],MPI_Comm comm,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Ineighbor_alltoallw( sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Neighbor_allgatherv(void * sendbuf,int sendcount,MPI_Datatype sendtype,void * recvbuf,int recvcounts[],int displs[],MPI_Datatype recvtype,MPI_Comm comm);
#pragma weak MPI_Neighbor_allgatherv=PMPI_Neighbor_allgatherv
int (*INTERFACE_LOCAL_MPI_Neighbor_allgatherv)(void *,int,MPI_Datatype,void *,int *,int *,MPI_Datatype,MPI_Comm);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Neighbor_allgatherv(void *,int,MPI_Datatype,void *,int *,int *,MPI_Datatype,MPI_Comm);
extern int INTERF_2_INTEL_CCMPI_Neighbor_allgatherv(void *,int,MPI_Datatype,void *,int *,int *,MPI_Datatype,MPI_Comm);
#endif /*WI4MPI_STATIC*/

int PMPI_Neighbor_allgatherv(void * sendbuf,int sendcount,MPI_Datatype sendtype,void * recvbuf,int recvcounts[],int displs[],MPI_Datatype recvtype,MPI_Comm comm)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Neighbor_allgatherv( sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Neighbor_alltoallv(void * sendbuf,int sendcounts[],int sdispls[],MPI_Datatype sendtype,void * recvbuf,int recvcounts[],int rdispls[],MPI_Datatype recvtype,MPI_Comm comm);
#pragma weak MPI_Neighbor_alltoallv=PMPI_Neighbor_alltoallv
int (*INTERFACE_LOCAL_MPI_Neighbor_alltoallv)(void *,int *,int *,MPI_Datatype,void *,int *,int *,MPI_Datatype,MPI_Comm);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Neighbor_alltoallv(void *,int *,int *,MPI_Datatype,void *,int *,int *,MPI_Datatype,MPI_Comm);
extern int INTERF_2_INTEL_CCMPI_Neighbor_alltoallv(void *,int *,int *,MPI_Datatype,void *,int *,int *,MPI_Datatype,MPI_Comm);
#endif /*WI4MPI_STATIC*/

int PMPI_Neighbor_alltoallv(void * sendbuf,int sendcounts[],int sdispls[],MPI_Datatype sendtype,void * recvbuf,int recvcounts[],int rdispls[],MPI_Datatype recvtype,MPI_Comm comm)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Neighbor_alltoallv( sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Neighbor_alltoallw(void * sendbuf,int sendcounts[],MPI_Aint sdispls[],MPI_Datatype sendtypes[],void * recvbuf,int recvcounts[],MPI_Aint rdispls[],MPI_Datatype recvtypes[],MPI_Comm comm);
#pragma weak MPI_Neighbor_alltoallw=PMPI_Neighbor_alltoallw
int (*INTERFACE_LOCAL_MPI_Neighbor_alltoallw)(void *,int *,MPI_Aint *,MPI_Datatype *,void *,int *,MPI_Aint *,MPI_Datatype *,MPI_Comm);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Neighbor_alltoallw(void *,int *,MPI_Aint *,MPI_Datatype *,void *,int *,MPI_Aint *,MPI_Datatype *,MPI_Comm);
extern int INTERF_2_INTEL_CCMPI_Neighbor_alltoallw(void *,int *,MPI_Aint *,MPI_Datatype *,void *,int *,MPI_Aint *,MPI_Datatype *,MPI_Comm);
#endif /*WI4MPI_STATIC*/

int PMPI_Neighbor_alltoallw(void * sendbuf,int sendcounts[],MPI_Aint sdispls[],MPI_Datatype sendtypes[],void * recvbuf,int recvcounts[],MPI_Aint rdispls[],MPI_Datatype recvtypes[],MPI_Comm comm)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Neighbor_alltoallw( sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_T_category_get_cvars(int cat_index,int len,int indices[]);
#pragma weak MPI_T_category_get_cvars=PMPI_T_category_get_cvars
int (*INTERFACE_LOCAL_MPI_T_category_get_cvars)(int,int,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_T_category_get_cvars(int,int,int *);
extern int INTERF_2_INTEL_CCMPI_T_category_get_cvars(int,int,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_T_category_get_cvars(int cat_index,int len,int indices[])
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_T_category_get_cvars( cat_index, len, indices);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_T_category_get_pvars(int cat_index,int len,int indices[]);
#pragma weak MPI_T_category_get_pvars=PMPI_T_category_get_pvars
int (*INTERFACE_LOCAL_MPI_T_category_get_pvars)(int,int,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_T_category_get_pvars(int,int,int *);
extern int INTERF_2_INTEL_CCMPI_T_category_get_pvars(int,int,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_T_category_get_pvars(int cat_index,int len,int indices[])
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_T_category_get_pvars( cat_index, len, indices);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_T_category_get_categories(int cat_index,int len,int indices[]);
#pragma weak MPI_T_category_get_categories=PMPI_T_category_get_categories
int (*INTERFACE_LOCAL_MPI_T_category_get_categories)(int,int,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_T_category_get_categories(int,int,int *);
extern int INTERF_2_INTEL_CCMPI_T_category_get_categories(int,int,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_T_category_get_categories(int cat_index,int len,int indices[])
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_T_category_get_categories( cat_index, len, indices);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_iwrite_all(MPI_File fh,void * buf,int count,MPI_Datatype datatype,MPI_Request * request);
#pragma weak MPI_File_iwrite_all=PMPI_File_iwrite_all
int (*INTERFACE_LOCAL_MPI_File_iwrite_all)(MPI_File,void *,int,MPI_Datatype,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_iwrite_all(MPI_File,void *,int,MPI_Datatype,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_File_iwrite_all(MPI_File,void *,int,MPI_Datatype,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_File_iwrite_all(MPI_File fh,void * buf,int count,MPI_Datatype datatype,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_iwrite_all( fh, buf, count, datatype, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_iwrite_at_all(MPI_File fh,MPI_Offset offset,void * buf,int count,MPI_Datatype datatype,MPI_Request * request);
#pragma weak MPI_File_iwrite_at_all=PMPI_File_iwrite_at_all
int (*INTERFACE_LOCAL_MPI_File_iwrite_at_all)(MPI_File,MPI_Offset,void *,int,MPI_Datatype,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_iwrite_at_all(MPI_File,MPI_Offset,void *,int,MPI_Datatype,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_File_iwrite_at_all(MPI_File,MPI_Offset,void *,int,MPI_Datatype,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_File_iwrite_at_all(MPI_File fh,MPI_Offset offset,void * buf,int count,MPI_Datatype datatype,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_iwrite_at_all( fh, offset, buf, count, datatype, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
MPI_Fint MPI_Group_c2f(MPI_Group group);
#pragma weak MPI_Group_c2f=PMPI_Group_c2f
MPI_Fint (*INTERFACE_LOCAL_MPI_Group_c2f)(MPI_Group);
#ifdef WI4MPI_STATIC
extern MPI_Fint INTERF_2_OMPI_CCMPI_Group_c2f(MPI_Group);
extern MPI_Fint INTERF_2_INTEL_CCMPI_Group_c2f(MPI_Group);
#endif /*WI4MPI_STATIC*/

MPI_Fint PMPI_Group_c2f(MPI_Group group)
{
#ifdef TIMEOUT_SUPPORT
#endif
MPI_Fint ret_tmp= INTERFACE_LOCAL_MPI_Group_c2f( group);

MPI_Fint ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
MPI_Group MPI_Group_f2c(MPI_Fint group);
#pragma weak MPI_Group_f2c=PMPI_Group_f2c
MPI_Group (*INTERFACE_LOCAL_MPI_Group_f2c)(MPI_Fint);
#ifdef WI4MPI_STATIC
extern MPI_Group INTERF_2_OMPI_CCMPI_Group_f2c(MPI_Fint);
extern MPI_Group INTERF_2_INTEL_CCMPI_Group_f2c(MPI_Fint);
#endif /*WI4MPI_STATIC*/

MPI_Group PMPI_Group_f2c(MPI_Fint group)
{
#ifdef TIMEOUT_SUPPORT
#endif
MPI_Group ret_tmp= INTERFACE_LOCAL_MPI_Group_f2c( group);

MPI_Group ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
MPI_Fint MPI_Info_c2f(MPI_Info info);
#pragma weak MPI_Info_c2f=PMPI_Info_c2f
MPI_Fint (*INTERFACE_LOCAL_MPI_Info_c2f)(MPI_Info);
#ifdef WI4MPI_STATIC
extern MPI_Fint INTERF_2_OMPI_CCMPI_Info_c2f(MPI_Info);
extern MPI_Fint INTERF_2_INTEL_CCMPI_Info_c2f(MPI_Info);
#endif /*WI4MPI_STATIC*/

MPI_Fint PMPI_Info_c2f(MPI_Info info)
{
#ifdef TIMEOUT_SUPPORT
#endif
MPI_Fint ret_tmp= INTERFACE_LOCAL_MPI_Info_c2f( info);

MPI_Fint ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
MPI_Info MPI_Info_f2c(MPI_Fint info);
#pragma weak MPI_Info_f2c=PMPI_Info_f2c
MPI_Info (*INTERFACE_LOCAL_MPI_Info_f2c)(MPI_Fint);
#ifdef WI4MPI_STATIC
extern MPI_Info INTERF_2_OMPI_CCMPI_Info_f2c(MPI_Fint);
extern MPI_Info INTERF_2_INTEL_CCMPI_Info_f2c(MPI_Fint);
#endif /*WI4MPI_STATIC*/

MPI_Info PMPI_Info_f2c(MPI_Fint info)
{
#ifdef TIMEOUT_SUPPORT
#endif
MPI_Info ret_tmp= INTERFACE_LOCAL_MPI_Info_f2c( info);

MPI_Info ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
MPI_Fint MPI_Errhandler_c2f(MPI_Errhandler errhandler);
#pragma weak MPI_Errhandler_c2f=PMPI_Errhandler_c2f
MPI_Fint (*INTERFACE_LOCAL_MPI_Errhandler_c2f)(MPI_Errhandler);
#ifdef WI4MPI_STATIC
extern MPI_Fint INTERF_2_OMPI_CCMPI_Errhandler_c2f(MPI_Errhandler);
extern MPI_Fint INTERF_2_INTEL_CCMPI_Errhandler_c2f(MPI_Errhandler);
#endif /*WI4MPI_STATIC*/

MPI_Fint PMPI_Errhandler_c2f(MPI_Errhandler errhandler)
{
#ifdef TIMEOUT_SUPPORT
#endif
MPI_Fint ret_tmp= INTERFACE_LOCAL_MPI_Errhandler_c2f( errhandler);

MPI_Fint ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
MPI_Errhandler MPI_Errhandler_f2c(MPI_Fint errhandler);
#pragma weak MPI_Errhandler_f2c=PMPI_Errhandler_f2c
MPI_Errhandler (*INTERFACE_LOCAL_MPI_Errhandler_f2c)(MPI_Fint);
#ifdef WI4MPI_STATIC
extern MPI_Errhandler INTERF_2_OMPI_CCMPI_Errhandler_f2c(MPI_Fint);
extern MPI_Errhandler INTERF_2_INTEL_CCMPI_Errhandler_f2c(MPI_Fint);
#endif /*WI4MPI_STATIC*/

MPI_Errhandler PMPI_Errhandler_f2c(MPI_Fint errhandler)
{
#ifdef TIMEOUT_SUPPORT
#endif
MPI_Errhandler ret_tmp= INTERFACE_LOCAL_MPI_Errhandler_f2c( errhandler);

MPI_Errhandler ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
MPI_Fint MPI_Message_c2f(MPI_Message message);
#pragma weak MPI_Message_c2f=PMPI_Message_c2f
MPI_Fint (*INTERFACE_LOCAL_MPI_Message_c2f)(MPI_Message);
#ifdef WI4MPI_STATIC
extern MPI_Fint INTERF_2_OMPI_CCMPI_Message_c2f(MPI_Message);
extern MPI_Fint INTERF_2_INTEL_CCMPI_Message_c2f(MPI_Message);
#endif /*WI4MPI_STATIC*/

MPI_Fint PMPI_Message_c2f(MPI_Message message)
{
#ifdef TIMEOUT_SUPPORT
#endif
MPI_Fint ret_tmp= INTERFACE_LOCAL_MPI_Message_c2f( message);

MPI_Fint ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
MPI_Message MPI_Message_f2c(MPI_Fint message);
#pragma weak MPI_Message_f2c=PMPI_Message_f2c
MPI_Message (*INTERFACE_LOCAL_MPI_Message_f2c)(MPI_Fint);
#ifdef WI4MPI_STATIC
extern MPI_Message INTERF_2_OMPI_CCMPI_Message_f2c(MPI_Fint);
extern MPI_Message INTERF_2_INTEL_CCMPI_Message_f2c(MPI_Fint);
#endif /*WI4MPI_STATIC*/

MPI_Message PMPI_Message_f2c(MPI_Fint message)
{
#ifdef TIMEOUT_SUPPORT
#endif
MPI_Message ret_tmp= INTERFACE_LOCAL_MPI_Message_f2c( message);

MPI_Message ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
MPI_Fint MPI_Op_c2f(MPI_Op op);
#pragma weak MPI_Op_c2f=PMPI_Op_c2f
MPI_Fint (*INTERFACE_LOCAL_MPI_Op_c2f)(MPI_Op);
#ifdef WI4MPI_STATIC
extern MPI_Fint INTERF_2_OMPI_CCMPI_Op_c2f(MPI_Op);
extern MPI_Fint INTERF_2_INTEL_CCMPI_Op_c2f(MPI_Op);
#endif /*WI4MPI_STATIC*/

MPI_Fint PMPI_Op_c2f(MPI_Op op)
{
#ifdef TIMEOUT_SUPPORT
#endif
MPI_Fint ret_tmp= INTERFACE_LOCAL_MPI_Op_c2f( op);

MPI_Fint ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
MPI_Op MPI_Op_f2c(MPI_Fint op);
#pragma weak MPI_Op_f2c=PMPI_Op_f2c
MPI_Op (*INTERFACE_LOCAL_MPI_Op_f2c)(MPI_Fint);
#ifdef WI4MPI_STATIC
extern MPI_Op INTERF_2_OMPI_CCMPI_Op_f2c(MPI_Fint);
extern MPI_Op INTERF_2_INTEL_CCMPI_Op_f2c(MPI_Fint);
#endif /*WI4MPI_STATIC*/

MPI_Op PMPI_Op_f2c(MPI_Fint op)
{
#ifdef TIMEOUT_SUPPORT
#endif
MPI_Op ret_tmp= INTERFACE_LOCAL_MPI_Op_f2c( op);

MPI_Op ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
MPI_Fint MPI_Request_c2f(MPI_Request request);
#pragma weak MPI_Request_c2f=PMPI_Request_c2f
MPI_Fint (*INTERFACE_LOCAL_MPI_Request_c2f)(MPI_Request);
#ifdef WI4MPI_STATIC
extern MPI_Fint INTERF_2_OMPI_CCMPI_Request_c2f(MPI_Request);
extern MPI_Fint INTERF_2_INTEL_CCMPI_Request_c2f(MPI_Request);
#endif /*WI4MPI_STATIC*/

MPI_Fint PMPI_Request_c2f(MPI_Request request)
{
#ifdef TIMEOUT_SUPPORT
#endif
MPI_Fint ret_tmp= INTERFACE_LOCAL_MPI_Request_c2f( request);

MPI_Fint ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
MPI_Request MPI_Request_f2c(MPI_Fint request);
#pragma weak MPI_Request_f2c=PMPI_Request_f2c
MPI_Request (*INTERFACE_LOCAL_MPI_Request_f2c)(MPI_Fint);
#ifdef WI4MPI_STATIC
extern MPI_Request INTERF_2_OMPI_CCMPI_Request_f2c(MPI_Fint);
extern MPI_Request INTERF_2_INTEL_CCMPI_Request_f2c(MPI_Fint);
#endif /*WI4MPI_STATIC*/

MPI_Request PMPI_Request_f2c(MPI_Fint request)
{
#ifdef TIMEOUT_SUPPORT
#endif
MPI_Request ret_tmp= INTERFACE_LOCAL_MPI_Request_f2c( request);

MPI_Request ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_T_category_get_index(char * name,int * cat_index);
#pragma weak MPI_T_category_get_index=PMPI_T_category_get_index
int (*INTERFACE_LOCAL_MPI_T_category_get_index)(char *,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_T_category_get_index(char *,int *);
extern int INTERF_2_INTEL_CCMPI_T_category_get_index(char *,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_T_category_get_index(char * name,int * cat_index)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_T_category_get_index( name, cat_index);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_T_cvar_get_index(char * name,int * cvar_index);
#pragma weak MPI_T_cvar_get_index=PMPI_T_cvar_get_index
int (*INTERFACE_LOCAL_MPI_T_cvar_get_index)(char *,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_T_cvar_get_index(char *,int *);
extern int INTERF_2_INTEL_CCMPI_T_cvar_get_index(char *,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_T_cvar_get_index(char * name,int * cvar_index)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_T_cvar_get_index( name, cvar_index);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_T_pvar_get_index(char * name,int var_class,int * pvar_index);
#pragma weak MPI_T_pvar_get_index=PMPI_T_pvar_get_index
int (*INTERFACE_LOCAL_MPI_T_pvar_get_index)(char *,int,int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_T_pvar_get_index(char *,int,int *);
extern int INTERF_2_INTEL_CCMPI_T_pvar_get_index(char *,int,int *);
#endif /*WI4MPI_STATIC*/

int PMPI_T_pvar_get_index(char * name,int var_class,int * pvar_index)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_T_pvar_get_index( name, var_class, pvar_index);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Type_c2f(MPI_Datatype datatype);
#pragma weak MPI_Type_c2f=PMPI_Type_c2f
int (*INTERFACE_LOCAL_MPI_Type_c2f)(MPI_Datatype);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Type_c2f(MPI_Datatype);
extern int INTERF_2_INTEL_CCMPI_Type_c2f(MPI_Datatype);
#endif /*WI4MPI_STATIC*/

int PMPI_Type_c2f(MPI_Datatype datatype)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Type_c2f( datatype);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
MPI_Datatype MPI_Type_f2c(MPI_Fint datatype);
#pragma weak MPI_Type_f2c=PMPI_Type_f2c
MPI_Datatype (*INTERFACE_LOCAL_MPI_Type_f2c)(MPI_Fint);
#ifdef WI4MPI_STATIC
extern MPI_Datatype INTERF_2_OMPI_CCMPI_Type_f2c(MPI_Fint);
extern MPI_Datatype INTERF_2_INTEL_CCMPI_Type_f2c(MPI_Fint);
#endif /*WI4MPI_STATIC*/

MPI_Datatype PMPI_Type_f2c(MPI_Fint datatype)
{
#ifdef TIMEOUT_SUPPORT
#endif
MPI_Datatype ret_tmp= INTERFACE_LOCAL_MPI_Type_f2c( datatype);

MPI_Datatype ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_Win_c2f(MPI_Win win);
#pragma weak MPI_Win_c2f=PMPI_Win_c2f
int (*INTERFACE_LOCAL_MPI_Win_c2f)(MPI_Win);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Win_c2f(MPI_Win);
extern int INTERF_2_INTEL_CCMPI_Win_c2f(MPI_Win);
#endif /*WI4MPI_STATIC*/

int PMPI_Win_c2f(MPI_Win win)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_Win_c2f( win);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
MPI_Win MPI_Win_f2c(MPI_Fint win);
#pragma weak MPI_Win_f2c=PMPI_Win_f2c
MPI_Win (*INTERFACE_LOCAL_MPI_Win_f2c)(MPI_Fint);
#ifdef WI4MPI_STATIC
extern MPI_Win INTERF_2_OMPI_CCMPI_Win_f2c(MPI_Fint);
extern MPI_Win INTERF_2_INTEL_CCMPI_Win_f2c(MPI_Fint);
#endif /*WI4MPI_STATIC*/

MPI_Win PMPI_Win_f2c(MPI_Fint win)
{
#ifdef TIMEOUT_SUPPORT
#endif
MPI_Win ret_tmp= INTERFACE_LOCAL_MPI_Win_f2c( win);

MPI_Win ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
MPI_Aint MPI_Aint_add(MPI_Aint base,MPI_Aint disp);
#pragma weak MPI_Aint_add=PMPI_Aint_add
MPI_Aint (*INTERFACE_LOCAL_MPI_Aint_add)(MPI_Aint,MPI_Aint);
#ifdef WI4MPI_STATIC
extern MPI_Aint INTERF_2_OMPI_CCMPI_Aint_add(MPI_Aint,MPI_Aint);
extern MPI_Aint INTERF_2_INTEL_CCMPI_Aint_add(MPI_Aint,MPI_Aint);
#endif /*WI4MPI_STATIC*/

MPI_Aint PMPI_Aint_add(MPI_Aint base,MPI_Aint disp)
{
#ifdef TIMEOUT_SUPPORT
#endif
MPI_Aint ret_tmp= INTERFACE_LOCAL_MPI_Aint_add( base, disp);

MPI_Aint ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
MPI_Aint MPI_Aint_diff(MPI_Aint addr1,MPI_Aint addr2);
#pragma weak MPI_Aint_diff=PMPI_Aint_diff
MPI_Aint (*INTERFACE_LOCAL_MPI_Aint_diff)(MPI_Aint,MPI_Aint);
#ifdef WI4MPI_STATIC
extern MPI_Aint INTERF_2_OMPI_CCMPI_Aint_diff(MPI_Aint,MPI_Aint);
extern MPI_Aint INTERF_2_INTEL_CCMPI_Aint_diff(MPI_Aint,MPI_Aint);
#endif /*WI4MPI_STATIC*/

MPI_Aint PMPI_Aint_diff(MPI_Aint addr1,MPI_Aint addr2)
{
#ifdef TIMEOUT_SUPPORT
#endif
MPI_Aint ret_tmp= INTERFACE_LOCAL_MPI_Aint_diff( addr1, addr2);

MPI_Aint ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
MPI_Fint MPI_Comm_c2f(MPI_Comm comm);
#pragma weak MPI_Comm_c2f=PMPI_Comm_c2f
MPI_Fint (*INTERFACE_LOCAL_MPI_Comm_c2f)(MPI_Comm);
#ifdef WI4MPI_STATIC
extern MPI_Fint INTERF_2_OMPI_CCMPI_Comm_c2f(MPI_Comm);
extern MPI_Fint INTERF_2_INTEL_CCMPI_Comm_c2f(MPI_Comm);
#endif /*WI4MPI_STATIC*/

MPI_Fint PMPI_Comm_c2f(MPI_Comm comm)
{
#ifdef TIMEOUT_SUPPORT
#endif
MPI_Fint ret_tmp= INTERFACE_LOCAL_MPI_Comm_c2f( comm);

MPI_Fint ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
MPI_Comm MPI_Comm_f2c(MPI_Fint comm);
#pragma weak MPI_Comm_f2c=PMPI_Comm_f2c
MPI_Comm (*INTERFACE_LOCAL_MPI_Comm_f2c)(MPI_Fint);
#ifdef WI4MPI_STATIC
extern MPI_Comm INTERF_2_OMPI_CCMPI_Comm_f2c(MPI_Fint);
extern MPI_Comm INTERF_2_INTEL_CCMPI_Comm_f2c(MPI_Fint);
#endif /*WI4MPI_STATIC*/

MPI_Comm PMPI_Comm_f2c(MPI_Fint comm)
{
#ifdef TIMEOUT_SUPPORT
#endif
MPI_Comm ret_tmp= INTERFACE_LOCAL_MPI_Comm_f2c( comm);

MPI_Comm ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
MPI_Fint MPI_File_c2f(MPI_File file);
#pragma weak MPI_File_c2f=PMPI_File_c2f
MPI_Fint (*INTERFACE_LOCAL_MPI_File_c2f)(MPI_File);
#ifdef WI4MPI_STATIC
extern MPI_Fint INTERF_2_OMPI_CCMPI_File_c2f(MPI_File);
extern MPI_Fint INTERF_2_INTEL_CCMPI_File_c2f(MPI_File);
#endif /*WI4MPI_STATIC*/

MPI_Fint PMPI_File_c2f(MPI_File file)
{
#ifdef TIMEOUT_SUPPORT
#endif
MPI_Fint ret_tmp= INTERFACE_LOCAL_MPI_File_c2f( file);

MPI_Fint ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
MPI_File MPI_File_f2c(MPI_Fint file);
#pragma weak MPI_File_f2c=PMPI_File_f2c
MPI_File (*INTERFACE_LOCAL_MPI_File_f2c)(MPI_Fint);
#ifdef WI4MPI_STATIC
extern MPI_File INTERF_2_OMPI_CCMPI_File_f2c(MPI_Fint);
extern MPI_File INTERF_2_INTEL_CCMPI_File_f2c(MPI_Fint);
#endif /*WI4MPI_STATIC*/

MPI_File PMPI_File_f2c(MPI_Fint file)
{
#ifdef TIMEOUT_SUPPORT
#endif
MPI_File ret_tmp= INTERFACE_LOCAL_MPI_File_f2c( file);

MPI_File ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_iread_all(MPI_File fh,void * buf,int count,MPI_Datatype datatype,MPI_Request * request);
#pragma weak MPI_File_iread_all=PMPI_File_iread_all
int (*INTERFACE_LOCAL_MPI_File_iread_all)(MPI_File,void *,int,MPI_Datatype,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_iread_all(MPI_File,void *,int,MPI_Datatype,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_File_iread_all(MPI_File,void *,int,MPI_Datatype,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_File_iread_all(MPI_File fh,void * buf,int count,MPI_Datatype datatype,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_iread_all( fh, buf, count, datatype, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_File_iread_at_all(MPI_File fh,MPI_Offset offset,void * buf,int count,MPI_Datatype datatype,MPI_Request * request);
#pragma weak MPI_File_iread_at_all=PMPI_File_iread_at_all
int (*INTERFACE_LOCAL_MPI_File_iread_at_all)(MPI_File,MPI_Offset,void *,int,MPI_Datatype,MPI_Request *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_File_iread_at_all(MPI_File,MPI_Offset,void *,int,MPI_Datatype,MPI_Request *);
extern int INTERF_2_INTEL_CCMPI_File_iread_at_all(MPI_File,MPI_Offset,void *,int,MPI_Datatype,MPI_Request *);
#endif /*WI4MPI_STATIC*/

int PMPI_File_iread_at_all(MPI_File fh,MPI_Offset offset,void * buf,int count,MPI_Datatype datatype,MPI_Request * request)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_File_iread_at_all( fh, offset, buf, count, datatype, request);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
int MPI_T_category_changed(int * stamp);
#pragma weak MPI_T_category_changed=PMPI_T_category_changed
int (*INTERFACE_LOCAL_MPI_T_category_changed)(int *);
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_T_category_changed(int *);
extern int INTERF_2_INTEL_CCMPI_T_category_changed(int *);
#endif /*WI4MPI_STATIC*/

int PMPI_T_category_changed(int * stamp)
{
#ifdef TIMEOUT_SUPPORT
#endif
int ret_tmp= INTERFACE_LOCAL_MPI_T_category_changed( stamp);

int ret=ret_tmp;#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
}
#ifdef WI4MPI_STATIC
extern int INTERF_2_OMPI_CCMPI_Keyval_create(MPI_Copy_function *copy_fn,MPI_Delete_function *delete_fn,int *keyval, void *extra_state);
extern int INTERF_2_OMPI_CCMPI_Keyval_free(int *);
extern int INTERF_2_OMPI_CCMPI_Comm_create_keyval(MPI_Copy_function *copy_fn,MPI_Delete_function *delete_fn,int *keyval, void *extra_state);
extern int INTERF_2_OMPI_CCMPI_Comm_free_keyval(int *);
extern int INTERF_2_OMPI_CCMPI_Win_get_attr(MPI_Win, int, void *, int *);
extern int INTERF_2_OMPI_CCMPI_Win_set_attr(MPI_Win, int, void *);
extern int INTERF_2_INTEL_CCMPI_Keyval_create(MPI_Copy_function *copy_fn,MPI_Delete_function *delete_fn,int *keyval, void *extra_state);
extern int INTERF_2_INTEL_CCMPI_Keyval_free(int *);
extern int INTERF_2_INTEL_CCMPI_Comm_create_keyval(MPI_Copy_function *copy_fn,MPI_Delete_function *delete_fn,int *keyval, void *extra_state);
extern int INTERF_2_INTEL_CCMPI_Comm_free_keyval(int *);
extern int INTERF_2_INTEL_CCMPI_Win_get_attr(MPI_Win, int, void *, int *);
extern int INTERF_2_INTEL_CCMPI_Win_set_attr(MPI_Win, int, void *);
#endif /*WI4MPI_STATIC*/
int wi4mpi__init__C=0;
extern int wi4mpi__init__F;
__attribute__((constructor)) void wrapper_interface(void) {
if(wi4mpi__init__C!=0)
    return;
else
    wi4mpi__init__C=1;
if(wi4mpi__init__F==0)
    wrapper_interface_f();
#ifndef WI4MPI_STATIC
#define to_string(name) #name
#define handle_loader(name)\
INTERFACE_LOCAL_##name=dlsym(interface_handle,to_string(CC##name))

#else
#define handle_loader(name,MPI_TARGET)\
INTERFACE_LOCAL_##name=&MPI_TARGET##name

#endif /*WI4MPI_STATIC*/
void *interface_handle;
#ifndef WI4MPI_STATIC
if(getenv("WI4MPI_WRAPPER_LIB") != NULL)
	interface_handle=dlopen(getenv("WI4MPI_WRAPPER_LIB"),RTLD_NOW|RTLD_GLOBAL);
else
{
	if(strcmp(wi4mpi_mode,"") != 0)
	{
		interface_handle=dlopen(wi4mpi_mode,RTLD_NOW|RTLD_GLOBAL);
	}
	else
	{
		fprintf(stderr,"Please provide either WI4MPI_WRAPPER_LIB environment or compile with -wi4mpi_default_run_paths\n");
		exit(1);
	}
}
if(!interface_handle)
{
	printf("Dlopen failed to open WI4MPI librarie.\nerror :%s\n",dlerror());
	exit(1);
}
handle_loader(MPI_Keyval_create);handle_loader(MPI_Keyval_free);
handle_loader(MPI_Comm_create_keyval);
handle_loader(MPI_Comm_free_keyval);
handle_loader(MPI_Win_get_attr);
handle_loader(MPI_Win_set_attr);
handle_loader(MPI_Pcontrol);
handle_loader(MPI_Send);
handle_loader(MPI_Recv);
handle_loader(MPI_Get_count);
handle_loader(MPI_Bsend);
handle_loader(MPI_Ssend);
handle_loader(MPI_Rsend);
handle_loader(MPI_Buffer_attach);
handle_loader(MPI_Buffer_detach);
handle_loader(MPI_Isend);
handle_loader(MPI_Ibsend);
handle_loader(MPI_Issend);
handle_loader(MPI_Irsend);
handle_loader(MPI_Irecv);
handle_loader(MPI_Wait);
handle_loader(MPI_Test);
handle_loader(MPI_Request_free);
handle_loader(MPI_Iprobe);
handle_loader(MPI_Probe);
handle_loader(MPI_Cancel);
handle_loader(MPI_Test_cancelled);
handle_loader(MPI_Send_init);
handle_loader(MPI_Bsend_init);
handle_loader(MPI_Ssend_init);
handle_loader(MPI_Rsend_init);
handle_loader(MPI_Recv_init);
handle_loader(MPI_Start);
handle_loader(MPI_Sendrecv);
handle_loader(MPI_Sendrecv_replace);
handle_loader(MPI_Type_contiguous);
handle_loader(MPI_Type_vector);
handle_loader(MPI_Type_hvector);
handle_loader(MPI_Type_indexed);
handle_loader(MPI_Type_hindexed);
handle_loader(MPI_Type_struct);
handle_loader(MPI_Address);
handle_loader(MPI_Type_extent);
handle_loader(MPI_Type_size);
handle_loader(MPI_Type_lb);
handle_loader(MPI_Type_ub);
handle_loader(MPI_Type_commit);
handle_loader(MPI_Type_free);
handle_loader(MPI_Get_elements);
handle_loader(MPI_Pack);
handle_loader(MPI_Unpack);
handle_loader(MPI_Pack_size);
handle_loader(MPI_Barrier);
handle_loader(MPI_Bcast);
handle_loader(MPI_Gather);
handle_loader(MPI_Gatherv);
handle_loader(MPI_Scatter);
handle_loader(MPI_Scatterv);
handle_loader(MPI_Allgather);
handle_loader(MPI_Allgatherv);
handle_loader(MPI_Alltoall);
handle_loader(MPI_Alltoallv);
handle_loader(MPI_Exscan);
handle_loader(MPI_Reduce);
handle_loader(MPI_Op_create);
handle_loader(MPI_Op_free);
handle_loader(MPI_Allreduce);
handle_loader(MPI_Scan);
handle_loader(MPI_Group_size);
handle_loader(MPI_Group_rank);
handle_loader(MPI_Group_compare);
handle_loader(MPI_Comm_group);
handle_loader(MPI_Group_union);
handle_loader(MPI_Group_intersection);
handle_loader(MPI_Group_difference);
handle_loader(MPI_Group_free);
handle_loader(MPI_Comm_size);
handle_loader(MPI_Comm_rank);
handle_loader(MPI_Comm_compare);
handle_loader(MPI_Comm_dup);
handle_loader(MPI_Comm_dup_with_info);
handle_loader(MPI_Comm_create);
handle_loader(MPI_Comm_split);
handle_loader(MPI_Comm_free);
handle_loader(MPI_Comm_test_inter);
handle_loader(MPI_Comm_remote_size);
handle_loader(MPI_Comm_remote_group);
handle_loader(MPI_Intercomm_create);
handle_loader(MPI_Intercomm_merge);
handle_loader(MPI_Attr_put);
handle_loader(MPI_Attr_get);
handle_loader(MPI_Attr_delete);
handle_loader(MPI_Topo_test);
handle_loader(MPI_Graphdims_get);
handle_loader(MPI_Cartdim_get);
handle_loader(MPI_Graph_neighbors_count);
handle_loader(MPI_Cart_shift);
handle_loader(MPI_Get_processor_name);
handle_loader(MPI_Get_version);
handle_loader(MPI_Get_library_version);
handle_loader(MPI_Errhandler_create);
handle_loader(MPI_Errhandler_set);
handle_loader(MPI_Errhandler_get);
handle_loader(MPI_Errhandler_free);
handle_loader(MPI_Error_string);
handle_loader(MPI_Error_class);
handle_loader(MPI_Initialized);
handle_loader(MPI_Abort);
handle_loader(MPI_Init);
handle_loader(MPI_Close_port);
handle_loader(MPI_Comm_accept);
handle_loader(MPI_Comm_connect);
handle_loader(MPI_Comm_disconnect);
handle_loader(MPI_Comm_get_parent);
handle_loader(MPI_Comm_join);
handle_loader(MPI_Lookup_name);
handle_loader(MPI_Open_port);
handle_loader(MPI_Publish_name);
handle_loader(MPI_Unpublish_name);
handle_loader(MPI_Comm_set_info);
handle_loader(MPI_Comm_get_info);
handle_loader(MPI_Accumulate);
handle_loader(MPI_Get);
handle_loader(MPI_Put);
handle_loader(MPI_Win_complete);
handle_loader(MPI_Win_create);
handle_loader(MPI_Win_fence);
handle_loader(MPI_Win_free);
handle_loader(MPI_Win_get_group);
handle_loader(MPI_Win_lock);
handle_loader(MPI_Win_post);
handle_loader(MPI_Win_start);
handle_loader(MPI_Win_test);
handle_loader(MPI_Win_unlock);
handle_loader(MPI_Win_wait);
handle_loader(MPI_Win_allocate);
handle_loader(MPI_Win_allocate_shared);
handle_loader(MPI_Win_shared_query);
handle_loader(MPI_Win_create_dynamic);
handle_loader(MPI_Win_attach);
handle_loader(MPI_Win_detach);
handle_loader(MPI_Win_get_info);
handle_loader(MPI_Win_set_info);
handle_loader(MPI_Get_accumulate);
handle_loader(MPI_Fetch_and_op);
handle_loader(MPI_Compare_and_swap);
handle_loader(MPI_Rput);
handle_loader(MPI_Rget);
handle_loader(MPI_Raccumulate);
handle_loader(MPI_Rget_accumulate);
handle_loader(MPI_Win_lock_all);
handle_loader(MPI_Win_unlock_all);
handle_loader(MPI_Win_flush);
handle_loader(MPI_Win_flush_all);
handle_loader(MPI_Win_flush_local);
handle_loader(MPI_Win_flush_local_all);
handle_loader(MPI_Win_sync);
handle_loader(MPI_Add_error_class);
handle_loader(MPI_Add_error_code);
handle_loader(MPI_Add_error_string);
handle_loader(MPI_Comm_call_errhandler);
handle_loader(MPI_Comm_delete_attr);
handle_loader(MPI_Comm_get_attr);
handle_loader(MPI_Comm_get_name);
handle_loader(MPI_Comm_set_attr);
handle_loader(MPI_Comm_set_name);
handle_loader(MPI_File_call_errhandler);
handle_loader(MPI_Grequest_complete);
handle_loader(MPI_Grequest_start);
handle_loader(MPI_Init_thread);
handle_loader(MPI_Is_thread_main);
handle_loader(MPI_Query_thread);
handle_loader(MPI_Status_set_cancelled);
handle_loader(MPI_Status_set_elements);
handle_loader(MPI_Type_create_keyval);
handle_loader(MPI_Type_delete_attr);
handle_loader(MPI_Type_dup);
handle_loader(MPI_Type_free_keyval);
handle_loader(MPI_Type_get_attr);
handle_loader(MPI_Type_get_envelope);
handle_loader(MPI_Type_get_name);
handle_loader(MPI_Type_set_attr);
handle_loader(MPI_Type_set_name);
handle_loader(MPI_Type_match_size);
handle_loader(MPI_Win_call_errhandler);
handle_loader(MPI_Win_create_keyval);
handle_loader(MPI_Win_delete_attr);
handle_loader(MPI_Win_free_keyval);
handle_loader(MPI_Win_get_name);
handle_loader(MPI_Win_set_name);
handle_loader(MPI_Alloc_mem);
handle_loader(MPI_Comm_create_errhandler);
handle_loader(MPI_Comm_get_errhandler);
handle_loader(MPI_Comm_set_errhandler);
handle_loader(MPI_File_create_errhandler);
handle_loader(MPI_File_get_errhandler);
handle_loader(MPI_File_set_errhandler);
handle_loader(MPI_Finalized);
handle_loader(MPI_Free_mem);
handle_loader(MPI_Get_address);
handle_loader(MPI_Info_create);
handle_loader(MPI_Info_delete);
handle_loader(MPI_Info_dup);
handle_loader(MPI_Info_free);
handle_loader(MPI_Info_get);
handle_loader(MPI_Info_get_nkeys);
handle_loader(MPI_Info_get_nthkey);
handle_loader(MPI_Info_get_valuelen);
handle_loader(MPI_Info_set);
handle_loader(MPI_Request_get_status);
handle_loader(MPI_Type_create_hvector);
handle_loader(MPI_Type_create_resized);
handle_loader(MPI_Type_get_extent);
handle_loader(MPI_Type_get_true_extent);
handle_loader(MPI_Win_create_errhandler);
handle_loader(MPI_Win_get_errhandler);
handle_loader(MPI_Win_set_errhandler);
handle_loader(MPI_Type_create_f90_integer);
handle_loader(MPI_Type_create_f90_real);
handle_loader(MPI_Type_create_f90_complex);
handle_loader(MPI_Reduce_local);
handle_loader(MPI_Op_commutative);
handle_loader(MPI_Reduce_scatter_block);
handle_loader(MPI_Dist_graph_neighbors_count);
handle_loader(MPI_Status_c2f);
handle_loader(MPI_Status_f2c);
handle_loader(MPI_Improbe);
handle_loader(MPI_Imrecv);
handle_loader(MPI_Mprobe);
handle_loader(MPI_Mrecv);
handle_loader(MPI_Comm_idup);
handle_loader(MPI_Ibarrier);
handle_loader(MPI_Ibcast);
handle_loader(MPI_Igather);
handle_loader(MPI_Iscatter);
handle_loader(MPI_Iallgather);
handle_loader(MPI_Ialltoall);
handle_loader(MPI_Ireduce);
handle_loader(MPI_Iallreduce);
handle_loader(MPI_Ireduce_scatter_block);
handle_loader(MPI_Iscan);
handle_loader(MPI_Iexscan);
handle_loader(MPI_Ineighbor_allgather);
handle_loader(MPI_Ineighbor_alltoall);
handle_loader(MPI_Neighbor_allgather);
handle_loader(MPI_Neighbor_alltoall);
handle_loader(MPI_Comm_split_type);
handle_loader(MPI_Get_elements_x);
handle_loader(MPI_Status_set_elements_x);
handle_loader(MPI_Type_get_extent_x);
handle_loader(MPI_Type_get_true_extent_x);
handle_loader(MPI_Type_size_x);
handle_loader(MPI_Comm_create_group);
handle_loader(MPI_T_init_thread);
handle_loader(MPI_T_enum_get_info);
handle_loader(MPI_T_enum_get_item);
handle_loader(MPI_T_cvar_get_num);
handle_loader(MPI_T_cvar_get_info);
handle_loader(MPI_T_cvar_handle_alloc);
handle_loader(MPI_T_cvar_handle_free);
handle_loader(MPI_T_cvar_read);
handle_loader(MPI_T_cvar_write);
handle_loader(MPI_T_pvar_get_num);
handle_loader(MPI_T_pvar_get_info);
handle_loader(MPI_T_pvar_session_create);
handle_loader(MPI_T_pvar_session_free);
handle_loader(MPI_T_pvar_handle_alloc);
handle_loader(MPI_T_pvar_handle_free);
handle_loader(MPI_T_pvar_start);
handle_loader(MPI_T_pvar_stop);
handle_loader(MPI_T_pvar_read);
handle_loader(MPI_T_pvar_write);
handle_loader(MPI_T_pvar_reset);
handle_loader(MPI_T_pvar_readreset);
handle_loader(MPI_T_category_get_num);
handle_loader(MPI_T_category_get_info);
handle_loader(MPI_File_open);
handle_loader(MPI_File_close);
handle_loader(MPI_File_delete);
handle_loader(MPI_File_set_size);
handle_loader(MPI_File_preallocate);
handle_loader(MPI_File_get_size);
handle_loader(MPI_File_get_group);
handle_loader(MPI_File_get_amode);
handle_loader(MPI_File_set_info);
handle_loader(MPI_File_get_info);
handle_loader(MPI_File_set_view);
handle_loader(MPI_File_get_view);
handle_loader(MPI_File_read_at);
handle_loader(MPI_File_read_at_all);
handle_loader(MPI_File_write_at);
handle_loader(MPI_File_write_at_all);
handle_loader(MPI_File_iread_at);
handle_loader(MPI_File_iwrite_at);
handle_loader(MPI_File_read);
handle_loader(MPI_File_read_all);
handle_loader(MPI_File_write);
handle_loader(MPI_File_write_all);
handle_loader(MPI_File_iread);
handle_loader(MPI_File_iwrite);
handle_loader(MPI_File_seek);
handle_loader(MPI_File_get_position);
handle_loader(MPI_File_get_byte_offset);
handle_loader(MPI_File_read_shared);
handle_loader(MPI_File_write_shared);
handle_loader(MPI_File_iread_shared);
handle_loader(MPI_File_iwrite_shared);
handle_loader(MPI_File_read_ordered);
handle_loader(MPI_File_write_ordered);
handle_loader(MPI_File_seek_shared);
handle_loader(MPI_File_get_position_shared);
handle_loader(MPI_File_read_at_all_begin);
handle_loader(MPI_File_read_at_all_end);
handle_loader(MPI_File_write_at_all_begin);
handle_loader(MPI_File_write_at_all_end);
handle_loader(MPI_File_read_all_begin);
handle_loader(MPI_File_read_all_end);
handle_loader(MPI_File_write_all_begin);
handle_loader(MPI_File_write_all_end);
handle_loader(MPI_File_read_ordered_begin);
handle_loader(MPI_File_read_ordered_end);
handle_loader(MPI_File_write_ordered_begin);
handle_loader(MPI_File_write_ordered_end);
handle_loader(MPI_File_get_type_extent);
handle_loader(MPI_Register_datarep);
handle_loader(MPI_File_set_atomicity);
handle_loader(MPI_File_get_atomicity);
handle_loader(MPI_File_sync);
handle_loader(MPI_T_finalize);
handle_loader(MPI_Wtime);
handle_loader(MPI_Wtick);
handle_loader(MPI_Finalize);
handle_loader(MPI_Waitany);
handle_loader(MPI_Testany);
handle_loader(MPI_Waitall);
handle_loader(MPI_Testall);
handle_loader(MPI_Waitsome);
handle_loader(MPI_Testsome);
handle_loader(MPI_Startall);
handle_loader(MPI_Alltoallw);
handle_loader(MPI_Reduce_scatter);
handle_loader(MPI_Group_translate_ranks);
handle_loader(MPI_Group_incl);
handle_loader(MPI_Group_excl);
handle_loader(MPI_Group_range_incl);
handle_loader(MPI_Group_range_excl);
handle_loader(MPI_Cart_create);
handle_loader(MPI_Dims_create);
handle_loader(MPI_Graph_create);
handle_loader(MPI_Graph_get);
handle_loader(MPI_Cart_get);
handle_loader(MPI_Cart_rank);
handle_loader(MPI_Cart_coords);
handle_loader(MPI_Graph_neighbors);
handle_loader(MPI_Cart_sub);
handle_loader(MPI_Cart_map);
handle_loader(MPI_Graph_map);
handle_loader(MPI_Comm_spawn);
handle_loader(MPI_Comm_spawn_multiple);
handle_loader(MPI_Type_get_contents);
handle_loader(MPI_Pack_external);
handle_loader(MPI_Pack_external_size);
handle_loader(MPI_Type_create_darray);
handle_loader(MPI_Type_create_hindexed);
handle_loader(MPI_Type_create_indexed_block);
handle_loader(MPI_Type_create_hindexed_block);
handle_loader(MPI_Type_create_struct);
handle_loader(MPI_Type_create_subarray);
handle_loader(MPI_Unpack_external);
handle_loader(MPI_Dist_graph_create_adjacent);
handle_loader(MPI_Dist_graph_create);
handle_loader(MPI_Dist_graph_neighbors);
handle_loader(MPI_Igatherv);
handle_loader(MPI_Iscatterv);
handle_loader(MPI_Iallgatherv);
handle_loader(MPI_Ialltoallv);
handle_loader(MPI_Ialltoallw);
handle_loader(MPI_Ireduce_scatter);
handle_loader(MPI_Ineighbor_allgatherv);
handle_loader(MPI_Ineighbor_alltoallv);
handle_loader(MPI_Ineighbor_alltoallw);
handle_loader(MPI_Neighbor_allgatherv);
handle_loader(MPI_Neighbor_alltoallv);
handle_loader(MPI_Neighbor_alltoallw);
handle_loader(MPI_T_category_get_cvars);
handle_loader(MPI_T_category_get_pvars);
handle_loader(MPI_T_category_get_categories);
handle_loader(MPI_File_iwrite_all);
handle_loader(MPI_File_iwrite_at_all);
handle_loader(MPI_Group_c2f);
handle_loader(MPI_Group_f2c);
handle_loader(MPI_Info_c2f);
handle_loader(MPI_Info_f2c);
handle_loader(MPI_Errhandler_c2f);
handle_loader(MPI_Errhandler_f2c);
handle_loader(MPI_Message_c2f);
handle_loader(MPI_Message_f2c);
handle_loader(MPI_Op_c2f);
handle_loader(MPI_Op_f2c);
handle_loader(MPI_Request_c2f);
handle_loader(MPI_Request_f2c);
handle_loader(MPI_T_category_get_index);
handle_loader(MPI_T_cvar_get_index);
handle_loader(MPI_T_pvar_get_index);
handle_loader(MPI_Type_c2f);
handle_loader(MPI_Type_f2c);
handle_loader(MPI_Win_c2f);
handle_loader(MPI_Win_f2c);
handle_loader(MPI_Aint_add);
handle_loader(MPI_Aint_diff);
handle_loader(MPI_Comm_c2f);
handle_loader(MPI_Comm_f2c);
handle_loader(MPI_File_c2f);
handle_loader(MPI_File_f2c);
handle_loader(MPI_File_iread_all);
handle_loader(MPI_File_iread_at_all);
handle_loader(MPI_T_category_changed);

#else
char *target_inter=getenv("WI4MPI_STATIC_TARGET_TYPE");
if(target_inter&&!strcmp(target_inter,"OMPI")){
handle_loader(MPI_Keyval_create,INTERF_2_OMPI_CC);handle_loader(MPI_Keyval_free,INTERF_2_OMPI_CC);
handle_loader(MPI_Comm_create_keyval,INTERF_2_OMPI_CC);
handle_loader(MPI_Comm_free_keyval,INTERF_2_OMPI_CC);
handle_loader(MPI_Win_get_attr,INTERF_2_OMPI_CC);
handle_loader(MPI_Win_set_attr,INTERF_2_OMPI_CC);
handle_loader(MPI_Pcontrol,INTERF_2_OMPI_CC);
handle_loader(MPI_Send,INTERF_2_OMPI_CC);
handle_loader(MPI_Recv,INTERF_2_OMPI_CC);
handle_loader(MPI_Get_count,INTERF_2_OMPI_CC);
handle_loader(MPI_Bsend,INTERF_2_OMPI_CC);
handle_loader(MPI_Ssend,INTERF_2_OMPI_CC);
handle_loader(MPI_Rsend,INTERF_2_OMPI_CC);
handle_loader(MPI_Buffer_attach,INTERF_2_OMPI_CC);
handle_loader(MPI_Buffer_detach,INTERF_2_OMPI_CC);
handle_loader(MPI_Isend,INTERF_2_OMPI_CC);
handle_loader(MPI_Ibsend,INTERF_2_OMPI_CC);
handle_loader(MPI_Issend,INTERF_2_OMPI_CC);
handle_loader(MPI_Irsend,INTERF_2_OMPI_CC);
handle_loader(MPI_Irecv,INTERF_2_OMPI_CC);
handle_loader(MPI_Wait,INTERF_2_OMPI_CC);
handle_loader(MPI_Test,INTERF_2_OMPI_CC);
handle_loader(MPI_Request_free,INTERF_2_OMPI_CC);
handle_loader(MPI_Iprobe,INTERF_2_OMPI_CC);
handle_loader(MPI_Probe,INTERF_2_OMPI_CC);
handle_loader(MPI_Cancel,INTERF_2_OMPI_CC);
handle_loader(MPI_Test_cancelled,INTERF_2_OMPI_CC);
handle_loader(MPI_Send_init,INTERF_2_OMPI_CC);
handle_loader(MPI_Bsend_init,INTERF_2_OMPI_CC);
handle_loader(MPI_Ssend_init,INTERF_2_OMPI_CC);
handle_loader(MPI_Rsend_init,INTERF_2_OMPI_CC);
handle_loader(MPI_Recv_init,INTERF_2_OMPI_CC);
handle_loader(MPI_Start,INTERF_2_OMPI_CC);
handle_loader(MPI_Sendrecv,INTERF_2_OMPI_CC);
handle_loader(MPI_Sendrecv_replace,INTERF_2_OMPI_CC);
handle_loader(MPI_Type_contiguous,INTERF_2_OMPI_CC);
handle_loader(MPI_Type_vector,INTERF_2_OMPI_CC);
handle_loader(MPI_Type_hvector,INTERF_2_OMPI_CC);
handle_loader(MPI_Type_indexed,INTERF_2_OMPI_CC);
handle_loader(MPI_Type_hindexed,INTERF_2_OMPI_CC);
handle_loader(MPI_Type_struct,INTERF_2_OMPI_CC);
handle_loader(MPI_Address,INTERF_2_OMPI_CC);
handle_loader(MPI_Type_extent,INTERF_2_OMPI_CC);
handle_loader(MPI_Type_size,INTERF_2_OMPI_CC);
handle_loader(MPI_Type_lb,INTERF_2_OMPI_CC);
handle_loader(MPI_Type_ub,INTERF_2_OMPI_CC);
handle_loader(MPI_Type_commit,INTERF_2_OMPI_CC);
handle_loader(MPI_Type_free,INTERF_2_OMPI_CC);
handle_loader(MPI_Get_elements,INTERF_2_OMPI_CC);
handle_loader(MPI_Pack,INTERF_2_OMPI_CC);
handle_loader(MPI_Unpack,INTERF_2_OMPI_CC);
handle_loader(MPI_Pack_size,INTERF_2_OMPI_CC);
handle_loader(MPI_Barrier,INTERF_2_OMPI_CC);
handle_loader(MPI_Bcast,INTERF_2_OMPI_CC);
handle_loader(MPI_Gather,INTERF_2_OMPI_CC);
handle_loader(MPI_Gatherv,INTERF_2_OMPI_CC);
handle_loader(MPI_Scatter,INTERF_2_OMPI_CC);
handle_loader(MPI_Scatterv,INTERF_2_OMPI_CC);
handle_loader(MPI_Allgather,INTERF_2_OMPI_CC);
handle_loader(MPI_Allgatherv,INTERF_2_OMPI_CC);
handle_loader(MPI_Alltoall,INTERF_2_OMPI_CC);
handle_loader(MPI_Alltoallv,INTERF_2_OMPI_CC);
handle_loader(MPI_Exscan,INTERF_2_OMPI_CC);
handle_loader(MPI_Reduce,INTERF_2_OMPI_CC);
handle_loader(MPI_Op_create,INTERF_2_OMPI_CC);
handle_loader(MPI_Op_free,INTERF_2_OMPI_CC);
handle_loader(MPI_Allreduce,INTERF_2_OMPI_CC);
handle_loader(MPI_Scan,INTERF_2_OMPI_CC);
handle_loader(MPI_Group_size,INTERF_2_OMPI_CC);
handle_loader(MPI_Group_rank,INTERF_2_OMPI_CC);
handle_loader(MPI_Group_compare,INTERF_2_OMPI_CC);
handle_loader(MPI_Comm_group,INTERF_2_OMPI_CC);
handle_loader(MPI_Group_union,INTERF_2_OMPI_CC);
handle_loader(MPI_Group_intersection,INTERF_2_OMPI_CC);
handle_loader(MPI_Group_difference,INTERF_2_OMPI_CC);
handle_loader(MPI_Group_free,INTERF_2_OMPI_CC);
handle_loader(MPI_Comm_size,INTERF_2_OMPI_CC);
handle_loader(MPI_Comm_rank,INTERF_2_OMPI_CC);
handle_loader(MPI_Comm_compare,INTERF_2_OMPI_CC);
handle_loader(MPI_Comm_dup,INTERF_2_OMPI_CC);
handle_loader(MPI_Comm_dup_with_info,INTERF_2_OMPI_CC);
handle_loader(MPI_Comm_create,INTERF_2_OMPI_CC);
handle_loader(MPI_Comm_split,INTERF_2_OMPI_CC);
handle_loader(MPI_Comm_free,INTERF_2_OMPI_CC);
handle_loader(MPI_Comm_test_inter,INTERF_2_OMPI_CC);
handle_loader(MPI_Comm_remote_size,INTERF_2_OMPI_CC);
handle_loader(MPI_Comm_remote_group,INTERF_2_OMPI_CC);
handle_loader(MPI_Intercomm_create,INTERF_2_OMPI_CC);
handle_loader(MPI_Intercomm_merge,INTERF_2_OMPI_CC);
handle_loader(MPI_Attr_put,INTERF_2_OMPI_CC);
handle_loader(MPI_Attr_get,INTERF_2_OMPI_CC);
handle_loader(MPI_Attr_delete,INTERF_2_OMPI_CC);
handle_loader(MPI_Topo_test,INTERF_2_OMPI_CC);
handle_loader(MPI_Graphdims_get,INTERF_2_OMPI_CC);
handle_loader(MPI_Cartdim_get,INTERF_2_OMPI_CC);
handle_loader(MPI_Graph_neighbors_count,INTERF_2_OMPI_CC);
handle_loader(MPI_Cart_shift,INTERF_2_OMPI_CC);
handle_loader(MPI_Get_processor_name,INTERF_2_OMPI_CC);
handle_loader(MPI_Get_version,INTERF_2_OMPI_CC);
handle_loader(MPI_Get_library_version,INTERF_2_OMPI_CC);
handle_loader(MPI_Errhandler_create,INTERF_2_OMPI_CC);
handle_loader(MPI_Errhandler_set,INTERF_2_OMPI_CC);
handle_loader(MPI_Errhandler_get,INTERF_2_OMPI_CC);
handle_loader(MPI_Errhandler_free,INTERF_2_OMPI_CC);
handle_loader(MPI_Error_string,INTERF_2_OMPI_CC);
handle_loader(MPI_Error_class,INTERF_2_OMPI_CC);
handle_loader(MPI_Initialized,INTERF_2_OMPI_CC);
handle_loader(MPI_Abort,INTERF_2_OMPI_CC);
handle_loader(MPI_Init,INTERF_2_OMPI_CC);
handle_loader(MPI_Close_port,INTERF_2_OMPI_CC);
handle_loader(MPI_Comm_accept,INTERF_2_OMPI_CC);
handle_loader(MPI_Comm_connect,INTERF_2_OMPI_CC);
handle_loader(MPI_Comm_disconnect,INTERF_2_OMPI_CC);
handle_loader(MPI_Comm_get_parent,INTERF_2_OMPI_CC);
handle_loader(MPI_Comm_join,INTERF_2_OMPI_CC);
handle_loader(MPI_Lookup_name,INTERF_2_OMPI_CC);
handle_loader(MPI_Open_port,INTERF_2_OMPI_CC);
handle_loader(MPI_Publish_name,INTERF_2_OMPI_CC);
handle_loader(MPI_Unpublish_name,INTERF_2_OMPI_CC);
handle_loader(MPI_Comm_set_info,INTERF_2_OMPI_CC);
handle_loader(MPI_Comm_get_info,INTERF_2_OMPI_CC);
handle_loader(MPI_Accumulate,INTERF_2_OMPI_CC);
handle_loader(MPI_Get,INTERF_2_OMPI_CC);
handle_loader(MPI_Put,INTERF_2_OMPI_CC);
handle_loader(MPI_Win_complete,INTERF_2_OMPI_CC);
handle_loader(MPI_Win_create,INTERF_2_OMPI_CC);
handle_loader(MPI_Win_fence,INTERF_2_OMPI_CC);
handle_loader(MPI_Win_free,INTERF_2_OMPI_CC);
handle_loader(MPI_Win_get_group,INTERF_2_OMPI_CC);
handle_loader(MPI_Win_lock,INTERF_2_OMPI_CC);
handle_loader(MPI_Win_post,INTERF_2_OMPI_CC);
handle_loader(MPI_Win_start,INTERF_2_OMPI_CC);
handle_loader(MPI_Win_test,INTERF_2_OMPI_CC);
handle_loader(MPI_Win_unlock,INTERF_2_OMPI_CC);
handle_loader(MPI_Win_wait,INTERF_2_OMPI_CC);
handle_loader(MPI_Win_allocate,INTERF_2_OMPI_CC);
handle_loader(MPI_Win_allocate_shared,INTERF_2_OMPI_CC);
handle_loader(MPI_Win_shared_query,INTERF_2_OMPI_CC);
handle_loader(MPI_Win_create_dynamic,INTERF_2_OMPI_CC);
handle_loader(MPI_Win_attach,INTERF_2_OMPI_CC);
handle_loader(MPI_Win_detach,INTERF_2_OMPI_CC);
handle_loader(MPI_Win_get_info,INTERF_2_OMPI_CC);
handle_loader(MPI_Win_set_info,INTERF_2_OMPI_CC);
handle_loader(MPI_Get_accumulate,INTERF_2_OMPI_CC);
handle_loader(MPI_Fetch_and_op,INTERF_2_OMPI_CC);
handle_loader(MPI_Compare_and_swap,INTERF_2_OMPI_CC);
handle_loader(MPI_Rput,INTERF_2_OMPI_CC);
handle_loader(MPI_Rget,INTERF_2_OMPI_CC);
handle_loader(MPI_Raccumulate,INTERF_2_OMPI_CC);
handle_loader(MPI_Rget_accumulate,INTERF_2_OMPI_CC);
handle_loader(MPI_Win_lock_all,INTERF_2_OMPI_CC);
handle_loader(MPI_Win_unlock_all,INTERF_2_OMPI_CC);
handle_loader(MPI_Win_flush,INTERF_2_OMPI_CC);
handle_loader(MPI_Win_flush_all,INTERF_2_OMPI_CC);
handle_loader(MPI_Win_flush_local,INTERF_2_OMPI_CC);
handle_loader(MPI_Win_flush_local_all,INTERF_2_OMPI_CC);
handle_loader(MPI_Win_sync,INTERF_2_OMPI_CC);
handle_loader(MPI_Add_error_class,INTERF_2_OMPI_CC);
handle_loader(MPI_Add_error_code,INTERF_2_OMPI_CC);
handle_loader(MPI_Add_error_string,INTERF_2_OMPI_CC);
handle_loader(MPI_Comm_call_errhandler,INTERF_2_OMPI_CC);
handle_loader(MPI_Comm_delete_attr,INTERF_2_OMPI_CC);
handle_loader(MPI_Comm_get_attr,INTERF_2_OMPI_CC);
handle_loader(MPI_Comm_get_name,INTERF_2_OMPI_CC);
handle_loader(MPI_Comm_set_attr,INTERF_2_OMPI_CC);
handle_loader(MPI_Comm_set_name,INTERF_2_OMPI_CC);
handle_loader(MPI_File_call_errhandler,INTERF_2_OMPI_CC);
handle_loader(MPI_Grequest_complete,INTERF_2_OMPI_CC);
handle_loader(MPI_Grequest_start,INTERF_2_OMPI_CC);
handle_loader(MPI_Init_thread,INTERF_2_OMPI_CC);
handle_loader(MPI_Is_thread_main,INTERF_2_OMPI_CC);
handle_loader(MPI_Query_thread,INTERF_2_OMPI_CC);
handle_loader(MPI_Status_set_cancelled,INTERF_2_OMPI_CC);
handle_loader(MPI_Status_set_elements,INTERF_2_OMPI_CC);
handle_loader(MPI_Type_create_keyval,INTERF_2_OMPI_CC);
handle_loader(MPI_Type_delete_attr,INTERF_2_OMPI_CC);
handle_loader(MPI_Type_dup,INTERF_2_OMPI_CC);
handle_loader(MPI_Type_free_keyval,INTERF_2_OMPI_CC);
handle_loader(MPI_Type_get_attr,INTERF_2_OMPI_CC);
handle_loader(MPI_Type_get_envelope,INTERF_2_OMPI_CC);
handle_loader(MPI_Type_get_name,INTERF_2_OMPI_CC);
handle_loader(MPI_Type_set_attr,INTERF_2_OMPI_CC);
handle_loader(MPI_Type_set_name,INTERF_2_OMPI_CC);
handle_loader(MPI_Type_match_size,INTERF_2_OMPI_CC);
handle_loader(MPI_Win_call_errhandler,INTERF_2_OMPI_CC);
handle_loader(MPI_Win_create_keyval,INTERF_2_OMPI_CC);
handle_loader(MPI_Win_delete_attr,INTERF_2_OMPI_CC);
handle_loader(MPI_Win_free_keyval,INTERF_2_OMPI_CC);
handle_loader(MPI_Win_get_name,INTERF_2_OMPI_CC);
handle_loader(MPI_Win_set_name,INTERF_2_OMPI_CC);
handle_loader(MPI_Alloc_mem,INTERF_2_OMPI_CC);
handle_loader(MPI_Comm_create_errhandler,INTERF_2_OMPI_CC);
handle_loader(MPI_Comm_get_errhandler,INTERF_2_OMPI_CC);
handle_loader(MPI_Comm_set_errhandler,INTERF_2_OMPI_CC);
handle_loader(MPI_File_create_errhandler,INTERF_2_OMPI_CC);
handle_loader(MPI_File_get_errhandler,INTERF_2_OMPI_CC);
handle_loader(MPI_File_set_errhandler,INTERF_2_OMPI_CC);
handle_loader(MPI_Finalized,INTERF_2_OMPI_CC);
handle_loader(MPI_Free_mem,INTERF_2_OMPI_CC);
handle_loader(MPI_Get_address,INTERF_2_OMPI_CC);
handle_loader(MPI_Info_create,INTERF_2_OMPI_CC);
handle_loader(MPI_Info_delete,INTERF_2_OMPI_CC);
handle_loader(MPI_Info_dup,INTERF_2_OMPI_CC);
handle_loader(MPI_Info_free,INTERF_2_OMPI_CC);
handle_loader(MPI_Info_get,INTERF_2_OMPI_CC);
handle_loader(MPI_Info_get_nkeys,INTERF_2_OMPI_CC);
handle_loader(MPI_Info_get_nthkey,INTERF_2_OMPI_CC);
handle_loader(MPI_Info_get_valuelen,INTERF_2_OMPI_CC);
handle_loader(MPI_Info_set,INTERF_2_OMPI_CC);
handle_loader(MPI_Request_get_status,INTERF_2_OMPI_CC);
handle_loader(MPI_Type_create_hvector,INTERF_2_OMPI_CC);
handle_loader(MPI_Type_create_resized,INTERF_2_OMPI_CC);
handle_loader(MPI_Type_get_extent,INTERF_2_OMPI_CC);
handle_loader(MPI_Type_get_true_extent,INTERF_2_OMPI_CC);
handle_loader(MPI_Win_create_errhandler,INTERF_2_OMPI_CC);
handle_loader(MPI_Win_get_errhandler,INTERF_2_OMPI_CC);
handle_loader(MPI_Win_set_errhandler,INTERF_2_OMPI_CC);
handle_loader(MPI_Type_create_f90_integer,INTERF_2_OMPI_CC);
handle_loader(MPI_Type_create_f90_real,INTERF_2_OMPI_CC);
handle_loader(MPI_Type_create_f90_complex,INTERF_2_OMPI_CC);
handle_loader(MPI_Reduce_local,INTERF_2_OMPI_CC);
handle_loader(MPI_Op_commutative,INTERF_2_OMPI_CC);
handle_loader(MPI_Reduce_scatter_block,INTERF_2_OMPI_CC);
handle_loader(MPI_Dist_graph_neighbors_count,INTERF_2_OMPI_CC);
handle_loader(MPI_Status_c2f,INTERF_2_OMPI_CC);
handle_loader(MPI_Status_f2c,INTERF_2_OMPI_CC);
handle_loader(MPI_Improbe,INTERF_2_OMPI_CC);
handle_loader(MPI_Imrecv,INTERF_2_OMPI_CC);
handle_loader(MPI_Mprobe,INTERF_2_OMPI_CC);
handle_loader(MPI_Mrecv,INTERF_2_OMPI_CC);
handle_loader(MPI_Comm_idup,INTERF_2_OMPI_CC);
handle_loader(MPI_Ibarrier,INTERF_2_OMPI_CC);
handle_loader(MPI_Ibcast,INTERF_2_OMPI_CC);
handle_loader(MPI_Igather,INTERF_2_OMPI_CC);
handle_loader(MPI_Iscatter,INTERF_2_OMPI_CC);
handle_loader(MPI_Iallgather,INTERF_2_OMPI_CC);
handle_loader(MPI_Ialltoall,INTERF_2_OMPI_CC);
handle_loader(MPI_Ireduce,INTERF_2_OMPI_CC);
handle_loader(MPI_Iallreduce,INTERF_2_OMPI_CC);
handle_loader(MPI_Ireduce_scatter_block,INTERF_2_OMPI_CC);
handle_loader(MPI_Iscan,INTERF_2_OMPI_CC);
handle_loader(MPI_Iexscan,INTERF_2_OMPI_CC);
handle_loader(MPI_Ineighbor_allgather,INTERF_2_OMPI_CC);
handle_loader(MPI_Ineighbor_alltoall,INTERF_2_OMPI_CC);
handle_loader(MPI_Neighbor_allgather,INTERF_2_OMPI_CC);
handle_loader(MPI_Neighbor_alltoall,INTERF_2_OMPI_CC);
handle_loader(MPI_Comm_split_type,INTERF_2_OMPI_CC);
handle_loader(MPI_Get_elements_x,INTERF_2_OMPI_CC);
handle_loader(MPI_Status_set_elements_x,INTERF_2_OMPI_CC);
handle_loader(MPI_Type_get_extent_x,INTERF_2_OMPI_CC);
handle_loader(MPI_Type_get_true_extent_x,INTERF_2_OMPI_CC);
handle_loader(MPI_Type_size_x,INTERF_2_OMPI_CC);
handle_loader(MPI_Comm_create_group,INTERF_2_OMPI_CC);
handle_loader(MPI_T_init_thread,INTERF_2_OMPI_CC);
handle_loader(MPI_T_enum_get_info,INTERF_2_OMPI_CC);
handle_loader(MPI_T_enum_get_item,INTERF_2_OMPI_CC);
handle_loader(MPI_T_cvar_get_num,INTERF_2_OMPI_CC);
handle_loader(MPI_T_cvar_get_info,INTERF_2_OMPI_CC);
handle_loader(MPI_T_cvar_handle_alloc,INTERF_2_OMPI_CC);
handle_loader(MPI_T_cvar_handle_free,INTERF_2_OMPI_CC);
handle_loader(MPI_T_cvar_read,INTERF_2_OMPI_CC);
handle_loader(MPI_T_cvar_write,INTERF_2_OMPI_CC);
handle_loader(MPI_T_pvar_get_num,INTERF_2_OMPI_CC);
handle_loader(MPI_T_pvar_get_info,INTERF_2_OMPI_CC);
handle_loader(MPI_T_pvar_session_create,INTERF_2_OMPI_CC);
handle_loader(MPI_T_pvar_session_free,INTERF_2_OMPI_CC);
handle_loader(MPI_T_pvar_handle_alloc,INTERF_2_OMPI_CC);
handle_loader(MPI_T_pvar_handle_free,INTERF_2_OMPI_CC);
handle_loader(MPI_T_pvar_start,INTERF_2_OMPI_CC);
handle_loader(MPI_T_pvar_stop,INTERF_2_OMPI_CC);
handle_loader(MPI_T_pvar_read,INTERF_2_OMPI_CC);
handle_loader(MPI_T_pvar_write,INTERF_2_OMPI_CC);
handle_loader(MPI_T_pvar_reset,INTERF_2_OMPI_CC);
handle_loader(MPI_T_pvar_readreset,INTERF_2_OMPI_CC);
handle_loader(MPI_T_category_get_num,INTERF_2_OMPI_CC);
handle_loader(MPI_T_category_get_info,INTERF_2_OMPI_CC);
handle_loader(MPI_File_open,INTERF_2_OMPI_CC);
handle_loader(MPI_File_close,INTERF_2_OMPI_CC);
handle_loader(MPI_File_delete,INTERF_2_OMPI_CC);
handle_loader(MPI_File_set_size,INTERF_2_OMPI_CC);
handle_loader(MPI_File_preallocate,INTERF_2_OMPI_CC);
handle_loader(MPI_File_get_size,INTERF_2_OMPI_CC);
handle_loader(MPI_File_get_group,INTERF_2_OMPI_CC);
handle_loader(MPI_File_get_amode,INTERF_2_OMPI_CC);
handle_loader(MPI_File_set_info,INTERF_2_OMPI_CC);
handle_loader(MPI_File_get_info,INTERF_2_OMPI_CC);
handle_loader(MPI_File_set_view,INTERF_2_OMPI_CC);
handle_loader(MPI_File_get_view,INTERF_2_OMPI_CC);
handle_loader(MPI_File_read_at,INTERF_2_OMPI_CC);
handle_loader(MPI_File_read_at_all,INTERF_2_OMPI_CC);
handle_loader(MPI_File_write_at,INTERF_2_OMPI_CC);
handle_loader(MPI_File_write_at_all,INTERF_2_OMPI_CC);
handle_loader(MPI_File_iread_at,INTERF_2_OMPI_CC);
handle_loader(MPI_File_iwrite_at,INTERF_2_OMPI_CC);
handle_loader(MPI_File_read,INTERF_2_OMPI_CC);
handle_loader(MPI_File_read_all,INTERF_2_OMPI_CC);
handle_loader(MPI_File_write,INTERF_2_OMPI_CC);
handle_loader(MPI_File_write_all,INTERF_2_OMPI_CC);
handle_loader(MPI_File_iread,INTERF_2_OMPI_CC);
handle_loader(MPI_File_iwrite,INTERF_2_OMPI_CC);
handle_loader(MPI_File_seek,INTERF_2_OMPI_CC);
handle_loader(MPI_File_get_position,INTERF_2_OMPI_CC);
handle_loader(MPI_File_get_byte_offset,INTERF_2_OMPI_CC);
handle_loader(MPI_File_read_shared,INTERF_2_OMPI_CC);
handle_loader(MPI_File_write_shared,INTERF_2_OMPI_CC);
handle_loader(MPI_File_iread_shared,INTERF_2_OMPI_CC);
handle_loader(MPI_File_iwrite_shared,INTERF_2_OMPI_CC);
handle_loader(MPI_File_read_ordered,INTERF_2_OMPI_CC);
handle_loader(MPI_File_write_ordered,INTERF_2_OMPI_CC);
handle_loader(MPI_File_seek_shared,INTERF_2_OMPI_CC);
handle_loader(MPI_File_get_position_shared,INTERF_2_OMPI_CC);
handle_loader(MPI_File_read_at_all_begin,INTERF_2_OMPI_CC);
handle_loader(MPI_File_read_at_all_end,INTERF_2_OMPI_CC);
handle_loader(MPI_File_write_at_all_begin,INTERF_2_OMPI_CC);
handle_loader(MPI_File_write_at_all_end,INTERF_2_OMPI_CC);
handle_loader(MPI_File_read_all_begin,INTERF_2_OMPI_CC);
handle_loader(MPI_File_read_all_end,INTERF_2_OMPI_CC);
handle_loader(MPI_File_write_all_begin,INTERF_2_OMPI_CC);
handle_loader(MPI_File_write_all_end,INTERF_2_OMPI_CC);
handle_loader(MPI_File_read_ordered_begin,INTERF_2_OMPI_CC);
handle_loader(MPI_File_read_ordered_end,INTERF_2_OMPI_CC);
handle_loader(MPI_File_write_ordered_begin,INTERF_2_OMPI_CC);
handle_loader(MPI_File_write_ordered_end,INTERF_2_OMPI_CC);
handle_loader(MPI_File_get_type_extent,INTERF_2_OMPI_CC);
handle_loader(MPI_Register_datarep,INTERF_2_OMPI_CC);
handle_loader(MPI_File_set_atomicity,INTERF_2_OMPI_CC);
handle_loader(MPI_File_get_atomicity,INTERF_2_OMPI_CC);
handle_loader(MPI_File_sync,INTERF_2_OMPI_CC);
handle_loader(MPI_T_finalize,INTERF_2_OMPI_CC);
handle_loader(MPI_Wtime,INTERF_2_OMPI_CC);
handle_loader(MPI_Wtick,INTERF_2_OMPI_CC);
handle_loader(MPI_Finalize,INTERF_2_OMPI_CC);
handle_loader(MPI_Waitany,INTERF_2_OMPI_CC);
handle_loader(MPI_Testany,INTERF_2_OMPI_CC);
handle_loader(MPI_Waitall,INTERF_2_OMPI_CC);
handle_loader(MPI_Testall,INTERF_2_OMPI_CC);
handle_loader(MPI_Waitsome,INTERF_2_OMPI_CC);
handle_loader(MPI_Testsome,INTERF_2_OMPI_CC);
handle_loader(MPI_Startall,INTERF_2_OMPI_CC);
handle_loader(MPI_Alltoallw,INTERF_2_OMPI_CC);
handle_loader(MPI_Reduce_scatter,INTERF_2_OMPI_CC);
handle_loader(MPI_Group_translate_ranks,INTERF_2_OMPI_CC);
handle_loader(MPI_Group_incl,INTERF_2_OMPI_CC);
handle_loader(MPI_Group_excl,INTERF_2_OMPI_CC);
handle_loader(MPI_Group_range_incl,INTERF_2_OMPI_CC);
handle_loader(MPI_Group_range_excl,INTERF_2_OMPI_CC);
handle_loader(MPI_Cart_create,INTERF_2_OMPI_CC);
handle_loader(MPI_Dims_create,INTERF_2_OMPI_CC);
handle_loader(MPI_Graph_create,INTERF_2_OMPI_CC);
handle_loader(MPI_Graph_get,INTERF_2_OMPI_CC);
handle_loader(MPI_Cart_get,INTERF_2_OMPI_CC);
handle_loader(MPI_Cart_rank,INTERF_2_OMPI_CC);
handle_loader(MPI_Cart_coords,INTERF_2_OMPI_CC);
handle_loader(MPI_Graph_neighbors,INTERF_2_OMPI_CC);
handle_loader(MPI_Cart_sub,INTERF_2_OMPI_CC);
handle_loader(MPI_Cart_map,INTERF_2_OMPI_CC);
handle_loader(MPI_Graph_map,INTERF_2_OMPI_CC);
handle_loader(MPI_Comm_spawn,INTERF_2_OMPI_CC);
handle_loader(MPI_Comm_spawn_multiple,INTERF_2_OMPI_CC);
handle_loader(MPI_Type_get_contents,INTERF_2_OMPI_CC);
handle_loader(MPI_Pack_external,INTERF_2_OMPI_CC);
handle_loader(MPI_Pack_external_size,INTERF_2_OMPI_CC);
handle_loader(MPI_Type_create_darray,INTERF_2_OMPI_CC);
handle_loader(MPI_Type_create_hindexed,INTERF_2_OMPI_CC);
handle_loader(MPI_Type_create_indexed_block,INTERF_2_OMPI_CC);
handle_loader(MPI_Type_create_hindexed_block,INTERF_2_OMPI_CC);
handle_loader(MPI_Type_create_struct,INTERF_2_OMPI_CC);
handle_loader(MPI_Type_create_subarray,INTERF_2_OMPI_CC);
handle_loader(MPI_Unpack_external,INTERF_2_OMPI_CC);
handle_loader(MPI_Dist_graph_create_adjacent,INTERF_2_OMPI_CC);
handle_loader(MPI_Dist_graph_create,INTERF_2_OMPI_CC);
handle_loader(MPI_Dist_graph_neighbors,INTERF_2_OMPI_CC);
handle_loader(MPI_Igatherv,INTERF_2_OMPI_CC);
handle_loader(MPI_Iscatterv,INTERF_2_OMPI_CC);
handle_loader(MPI_Iallgatherv,INTERF_2_OMPI_CC);
handle_loader(MPI_Ialltoallv,INTERF_2_OMPI_CC);
handle_loader(MPI_Ialltoallw,INTERF_2_OMPI_CC);
handle_loader(MPI_Ireduce_scatter,INTERF_2_OMPI_CC);
handle_loader(MPI_Ineighbor_allgatherv,INTERF_2_OMPI_CC);
handle_loader(MPI_Ineighbor_alltoallv,INTERF_2_OMPI_CC);
handle_loader(MPI_Ineighbor_alltoallw,INTERF_2_OMPI_CC);
handle_loader(MPI_Neighbor_allgatherv,INTERF_2_OMPI_CC);
handle_loader(MPI_Neighbor_alltoallv,INTERF_2_OMPI_CC);
handle_loader(MPI_Neighbor_alltoallw,INTERF_2_OMPI_CC);
handle_loader(MPI_T_category_get_cvars,INTERF_2_OMPI_CC);
handle_loader(MPI_T_category_get_pvars,INTERF_2_OMPI_CC);
handle_loader(MPI_T_category_get_categories,INTERF_2_OMPI_CC);
handle_loader(MPI_File_iwrite_all,INTERF_2_OMPI_CC);
handle_loader(MPI_File_iwrite_at_all,INTERF_2_OMPI_CC);
handle_loader(MPI_Group_c2f,INTERF_2_OMPI_CC);
handle_loader(MPI_Group_f2c,INTERF_2_OMPI_CC);
handle_loader(MPI_Info_c2f,INTERF_2_OMPI_CC);
handle_loader(MPI_Info_f2c,INTERF_2_OMPI_CC);
handle_loader(MPI_Errhandler_c2f,INTERF_2_OMPI_CC);
handle_loader(MPI_Errhandler_f2c,INTERF_2_OMPI_CC);
handle_loader(MPI_Message_c2f,INTERF_2_OMPI_CC);
handle_loader(MPI_Message_f2c,INTERF_2_OMPI_CC);
handle_loader(MPI_Op_c2f,INTERF_2_OMPI_CC);
handle_loader(MPI_Op_f2c,INTERF_2_OMPI_CC);
handle_loader(MPI_Request_c2f,INTERF_2_OMPI_CC);
handle_loader(MPI_Request_f2c,INTERF_2_OMPI_CC);
handle_loader(MPI_T_category_get_index,INTERF_2_OMPI_CC);
handle_loader(MPI_T_cvar_get_index,INTERF_2_OMPI_CC);
handle_loader(MPI_T_pvar_get_index,INTERF_2_OMPI_CC);
handle_loader(MPI_Type_c2f,INTERF_2_OMPI_CC);
handle_loader(MPI_Type_f2c,INTERF_2_OMPI_CC);
handle_loader(MPI_Win_c2f,INTERF_2_OMPI_CC);
handle_loader(MPI_Win_f2c,INTERF_2_OMPI_CC);
handle_loader(MPI_Aint_add,INTERF_2_OMPI_CC);
handle_loader(MPI_Aint_diff,INTERF_2_OMPI_CC);
handle_loader(MPI_Comm_c2f,INTERF_2_OMPI_CC);
handle_loader(MPI_Comm_f2c,INTERF_2_OMPI_CC);
handle_loader(MPI_File_c2f,INTERF_2_OMPI_CC);
handle_loader(MPI_File_f2c,INTERF_2_OMPI_CC);
handle_loader(MPI_File_iread_all,INTERF_2_OMPI_CC);
handle_loader(MPI_File_iread_at_all,INTERF_2_OMPI_CC);
handle_loader(MPI_T_category_changed,INTERF_2_OMPI_CC);
INTERF_2_OMPI_wrapper_init();
INTERF_2_OMPI_wrapper_init_f();
}else{
if(target_inter&&!strcmp(target_inter,"INTEL")){
handle_loader(MPI_Keyval_create,INTERF_2_INTEL_CC);handle_loader(MPI_Keyval_free,INTERF_2_INTEL_CC);
handle_loader(MPI_Comm_create_keyval,INTERF_2_INTEL_CC);
handle_loader(MPI_Comm_free_keyval,INTERF_2_INTEL_CC);
handle_loader(MPI_Win_get_attr,INTERF_2_INTEL_CC);
handle_loader(MPI_Win_set_attr,INTERF_2_INTEL_CC);
handle_loader(MPI_Pcontrol,INTERF_2_INTEL_CC);
handle_loader(MPI_Send,INTERF_2_INTEL_CC);
handle_loader(MPI_Recv,INTERF_2_INTEL_CC);
handle_loader(MPI_Get_count,INTERF_2_INTEL_CC);
handle_loader(MPI_Bsend,INTERF_2_INTEL_CC);
handle_loader(MPI_Ssend,INTERF_2_INTEL_CC);
handle_loader(MPI_Rsend,INTERF_2_INTEL_CC);
handle_loader(MPI_Buffer_attach,INTERF_2_INTEL_CC);
handle_loader(MPI_Buffer_detach,INTERF_2_INTEL_CC);
handle_loader(MPI_Isend,INTERF_2_INTEL_CC);
handle_loader(MPI_Ibsend,INTERF_2_INTEL_CC);
handle_loader(MPI_Issend,INTERF_2_INTEL_CC);
handle_loader(MPI_Irsend,INTERF_2_INTEL_CC);
handle_loader(MPI_Irecv,INTERF_2_INTEL_CC);
handle_loader(MPI_Wait,INTERF_2_INTEL_CC);
handle_loader(MPI_Test,INTERF_2_INTEL_CC);
handle_loader(MPI_Request_free,INTERF_2_INTEL_CC);
handle_loader(MPI_Iprobe,INTERF_2_INTEL_CC);
handle_loader(MPI_Probe,INTERF_2_INTEL_CC);
handle_loader(MPI_Cancel,INTERF_2_INTEL_CC);
handle_loader(MPI_Test_cancelled,INTERF_2_INTEL_CC);
handle_loader(MPI_Send_init,INTERF_2_INTEL_CC);
handle_loader(MPI_Bsend_init,INTERF_2_INTEL_CC);
handle_loader(MPI_Ssend_init,INTERF_2_INTEL_CC);
handle_loader(MPI_Rsend_init,INTERF_2_INTEL_CC);
handle_loader(MPI_Recv_init,INTERF_2_INTEL_CC);
handle_loader(MPI_Start,INTERF_2_INTEL_CC);
handle_loader(MPI_Sendrecv,INTERF_2_INTEL_CC);
handle_loader(MPI_Sendrecv_replace,INTERF_2_INTEL_CC);
handle_loader(MPI_Type_contiguous,INTERF_2_INTEL_CC);
handle_loader(MPI_Type_vector,INTERF_2_INTEL_CC);
handle_loader(MPI_Type_hvector,INTERF_2_INTEL_CC);
handle_loader(MPI_Type_indexed,INTERF_2_INTEL_CC);
handle_loader(MPI_Type_hindexed,INTERF_2_INTEL_CC);
handle_loader(MPI_Type_struct,INTERF_2_INTEL_CC);
handle_loader(MPI_Address,INTERF_2_INTEL_CC);
handle_loader(MPI_Type_extent,INTERF_2_INTEL_CC);
handle_loader(MPI_Type_size,INTERF_2_INTEL_CC);
handle_loader(MPI_Type_lb,INTERF_2_INTEL_CC);
handle_loader(MPI_Type_ub,INTERF_2_INTEL_CC);
handle_loader(MPI_Type_commit,INTERF_2_INTEL_CC);
handle_loader(MPI_Type_free,INTERF_2_INTEL_CC);
handle_loader(MPI_Get_elements,INTERF_2_INTEL_CC);
handle_loader(MPI_Pack,INTERF_2_INTEL_CC);
handle_loader(MPI_Unpack,INTERF_2_INTEL_CC);
handle_loader(MPI_Pack_size,INTERF_2_INTEL_CC);
handle_loader(MPI_Barrier,INTERF_2_INTEL_CC);
handle_loader(MPI_Bcast,INTERF_2_INTEL_CC);
handle_loader(MPI_Gather,INTERF_2_INTEL_CC);
handle_loader(MPI_Gatherv,INTERF_2_INTEL_CC);
handle_loader(MPI_Scatter,INTERF_2_INTEL_CC);
handle_loader(MPI_Scatterv,INTERF_2_INTEL_CC);
handle_loader(MPI_Allgather,INTERF_2_INTEL_CC);
handle_loader(MPI_Allgatherv,INTERF_2_INTEL_CC);
handle_loader(MPI_Alltoall,INTERF_2_INTEL_CC);
handle_loader(MPI_Alltoallv,INTERF_2_INTEL_CC);
handle_loader(MPI_Exscan,INTERF_2_INTEL_CC);
handle_loader(MPI_Reduce,INTERF_2_INTEL_CC);
handle_loader(MPI_Op_create,INTERF_2_INTEL_CC);
handle_loader(MPI_Op_free,INTERF_2_INTEL_CC);
handle_loader(MPI_Allreduce,INTERF_2_INTEL_CC);
handle_loader(MPI_Scan,INTERF_2_INTEL_CC);
handle_loader(MPI_Group_size,INTERF_2_INTEL_CC);
handle_loader(MPI_Group_rank,INTERF_2_INTEL_CC);
handle_loader(MPI_Group_compare,INTERF_2_INTEL_CC);
handle_loader(MPI_Comm_group,INTERF_2_INTEL_CC);
handle_loader(MPI_Group_union,INTERF_2_INTEL_CC);
handle_loader(MPI_Group_intersection,INTERF_2_INTEL_CC);
handle_loader(MPI_Group_difference,INTERF_2_INTEL_CC);
handle_loader(MPI_Group_free,INTERF_2_INTEL_CC);
handle_loader(MPI_Comm_size,INTERF_2_INTEL_CC);
handle_loader(MPI_Comm_rank,INTERF_2_INTEL_CC);
handle_loader(MPI_Comm_compare,INTERF_2_INTEL_CC);
handle_loader(MPI_Comm_dup,INTERF_2_INTEL_CC);
handle_loader(MPI_Comm_dup_with_info,INTERF_2_INTEL_CC);
handle_loader(MPI_Comm_create,INTERF_2_INTEL_CC);
handle_loader(MPI_Comm_split,INTERF_2_INTEL_CC);
handle_loader(MPI_Comm_free,INTERF_2_INTEL_CC);
handle_loader(MPI_Comm_test_inter,INTERF_2_INTEL_CC);
handle_loader(MPI_Comm_remote_size,INTERF_2_INTEL_CC);
handle_loader(MPI_Comm_remote_group,INTERF_2_INTEL_CC);
handle_loader(MPI_Intercomm_create,INTERF_2_INTEL_CC);
handle_loader(MPI_Intercomm_merge,INTERF_2_INTEL_CC);
handle_loader(MPI_Attr_put,INTERF_2_INTEL_CC);
handle_loader(MPI_Attr_get,INTERF_2_INTEL_CC);
handle_loader(MPI_Attr_delete,INTERF_2_INTEL_CC);
handle_loader(MPI_Topo_test,INTERF_2_INTEL_CC);
handle_loader(MPI_Graphdims_get,INTERF_2_INTEL_CC);
handle_loader(MPI_Cartdim_get,INTERF_2_INTEL_CC);
handle_loader(MPI_Graph_neighbors_count,INTERF_2_INTEL_CC);
handle_loader(MPI_Cart_shift,INTERF_2_INTEL_CC);
handle_loader(MPI_Get_processor_name,INTERF_2_INTEL_CC);
handle_loader(MPI_Get_version,INTERF_2_INTEL_CC);
handle_loader(MPI_Get_library_version,INTERF_2_INTEL_CC);
handle_loader(MPI_Errhandler_create,INTERF_2_INTEL_CC);
handle_loader(MPI_Errhandler_set,INTERF_2_INTEL_CC);
handle_loader(MPI_Errhandler_get,INTERF_2_INTEL_CC);
handle_loader(MPI_Errhandler_free,INTERF_2_INTEL_CC);
handle_loader(MPI_Error_string,INTERF_2_INTEL_CC);
handle_loader(MPI_Error_class,INTERF_2_INTEL_CC);
handle_loader(MPI_Initialized,INTERF_2_INTEL_CC);
handle_loader(MPI_Abort,INTERF_2_INTEL_CC);
handle_loader(MPI_Init,INTERF_2_INTEL_CC);
handle_loader(MPI_Close_port,INTERF_2_INTEL_CC);
handle_loader(MPI_Comm_accept,INTERF_2_INTEL_CC);
handle_loader(MPI_Comm_connect,INTERF_2_INTEL_CC);
handle_loader(MPI_Comm_disconnect,INTERF_2_INTEL_CC);
handle_loader(MPI_Comm_get_parent,INTERF_2_INTEL_CC);
handle_loader(MPI_Comm_join,INTERF_2_INTEL_CC);
handle_loader(MPI_Lookup_name,INTERF_2_INTEL_CC);
handle_loader(MPI_Open_port,INTERF_2_INTEL_CC);
handle_loader(MPI_Publish_name,INTERF_2_INTEL_CC);
handle_loader(MPI_Unpublish_name,INTERF_2_INTEL_CC);
handle_loader(MPI_Comm_set_info,INTERF_2_INTEL_CC);
handle_loader(MPI_Comm_get_info,INTERF_2_INTEL_CC);
handle_loader(MPI_Accumulate,INTERF_2_INTEL_CC);
handle_loader(MPI_Get,INTERF_2_INTEL_CC);
handle_loader(MPI_Put,INTERF_2_INTEL_CC);
handle_loader(MPI_Win_complete,INTERF_2_INTEL_CC);
handle_loader(MPI_Win_create,INTERF_2_INTEL_CC);
handle_loader(MPI_Win_fence,INTERF_2_INTEL_CC);
handle_loader(MPI_Win_free,INTERF_2_INTEL_CC);
handle_loader(MPI_Win_get_group,INTERF_2_INTEL_CC);
handle_loader(MPI_Win_lock,INTERF_2_INTEL_CC);
handle_loader(MPI_Win_post,INTERF_2_INTEL_CC);
handle_loader(MPI_Win_start,INTERF_2_INTEL_CC);
handle_loader(MPI_Win_test,INTERF_2_INTEL_CC);
handle_loader(MPI_Win_unlock,INTERF_2_INTEL_CC);
handle_loader(MPI_Win_wait,INTERF_2_INTEL_CC);
handle_loader(MPI_Win_allocate,INTERF_2_INTEL_CC);
handle_loader(MPI_Win_allocate_shared,INTERF_2_INTEL_CC);
handle_loader(MPI_Win_shared_query,INTERF_2_INTEL_CC);
handle_loader(MPI_Win_create_dynamic,INTERF_2_INTEL_CC);
handle_loader(MPI_Win_attach,INTERF_2_INTEL_CC);
handle_loader(MPI_Win_detach,INTERF_2_INTEL_CC);
handle_loader(MPI_Win_get_info,INTERF_2_INTEL_CC);
handle_loader(MPI_Win_set_info,INTERF_2_INTEL_CC);
handle_loader(MPI_Get_accumulate,INTERF_2_INTEL_CC);
handle_loader(MPI_Fetch_and_op,INTERF_2_INTEL_CC);
handle_loader(MPI_Compare_and_swap,INTERF_2_INTEL_CC);
handle_loader(MPI_Rput,INTERF_2_INTEL_CC);
handle_loader(MPI_Rget,INTERF_2_INTEL_CC);
handle_loader(MPI_Raccumulate,INTERF_2_INTEL_CC);
handle_loader(MPI_Rget_accumulate,INTERF_2_INTEL_CC);
handle_loader(MPI_Win_lock_all,INTERF_2_INTEL_CC);
handle_loader(MPI_Win_unlock_all,INTERF_2_INTEL_CC);
handle_loader(MPI_Win_flush,INTERF_2_INTEL_CC);
handle_loader(MPI_Win_flush_all,INTERF_2_INTEL_CC);
handle_loader(MPI_Win_flush_local,INTERF_2_INTEL_CC);
handle_loader(MPI_Win_flush_local_all,INTERF_2_INTEL_CC);
handle_loader(MPI_Win_sync,INTERF_2_INTEL_CC);
handle_loader(MPI_Add_error_class,INTERF_2_INTEL_CC);
handle_loader(MPI_Add_error_code,INTERF_2_INTEL_CC);
handle_loader(MPI_Add_error_string,INTERF_2_INTEL_CC);
handle_loader(MPI_Comm_call_errhandler,INTERF_2_INTEL_CC);
handle_loader(MPI_Comm_delete_attr,INTERF_2_INTEL_CC);
handle_loader(MPI_Comm_get_attr,INTERF_2_INTEL_CC);
handle_loader(MPI_Comm_get_name,INTERF_2_INTEL_CC);
handle_loader(MPI_Comm_set_attr,INTERF_2_INTEL_CC);
handle_loader(MPI_Comm_set_name,INTERF_2_INTEL_CC);
handle_loader(MPI_File_call_errhandler,INTERF_2_INTEL_CC);
handle_loader(MPI_Grequest_complete,INTERF_2_INTEL_CC);
handle_loader(MPI_Grequest_start,INTERF_2_INTEL_CC);
handle_loader(MPI_Init_thread,INTERF_2_INTEL_CC);
handle_loader(MPI_Is_thread_main,INTERF_2_INTEL_CC);
handle_loader(MPI_Query_thread,INTERF_2_INTEL_CC);
handle_loader(MPI_Status_set_cancelled,INTERF_2_INTEL_CC);
handle_loader(MPI_Status_set_elements,INTERF_2_INTEL_CC);
handle_loader(MPI_Type_create_keyval,INTERF_2_INTEL_CC);
handle_loader(MPI_Type_delete_attr,INTERF_2_INTEL_CC);
handle_loader(MPI_Type_dup,INTERF_2_INTEL_CC);
handle_loader(MPI_Type_free_keyval,INTERF_2_INTEL_CC);
handle_loader(MPI_Type_get_attr,INTERF_2_INTEL_CC);
handle_loader(MPI_Type_get_envelope,INTERF_2_INTEL_CC);
handle_loader(MPI_Type_get_name,INTERF_2_INTEL_CC);
handle_loader(MPI_Type_set_attr,INTERF_2_INTEL_CC);
handle_loader(MPI_Type_set_name,INTERF_2_INTEL_CC);
handle_loader(MPI_Type_match_size,INTERF_2_INTEL_CC);
handle_loader(MPI_Win_call_errhandler,INTERF_2_INTEL_CC);
handle_loader(MPI_Win_create_keyval,INTERF_2_INTEL_CC);
handle_loader(MPI_Win_delete_attr,INTERF_2_INTEL_CC);
handle_loader(MPI_Win_free_keyval,INTERF_2_INTEL_CC);
handle_loader(MPI_Win_get_name,INTERF_2_INTEL_CC);
handle_loader(MPI_Win_set_name,INTERF_2_INTEL_CC);
handle_loader(MPI_Alloc_mem,INTERF_2_INTEL_CC);
handle_loader(MPI_Comm_create_errhandler,INTERF_2_INTEL_CC);
handle_loader(MPI_Comm_get_errhandler,INTERF_2_INTEL_CC);
handle_loader(MPI_Comm_set_errhandler,INTERF_2_INTEL_CC);
handle_loader(MPI_File_create_errhandler,INTERF_2_INTEL_CC);
handle_loader(MPI_File_get_errhandler,INTERF_2_INTEL_CC);
handle_loader(MPI_File_set_errhandler,INTERF_2_INTEL_CC);
handle_loader(MPI_Finalized,INTERF_2_INTEL_CC);
handle_loader(MPI_Free_mem,INTERF_2_INTEL_CC);
handle_loader(MPI_Get_address,INTERF_2_INTEL_CC);
handle_loader(MPI_Info_create,INTERF_2_INTEL_CC);
handle_loader(MPI_Info_delete,INTERF_2_INTEL_CC);
handle_loader(MPI_Info_dup,INTERF_2_INTEL_CC);
handle_loader(MPI_Info_free,INTERF_2_INTEL_CC);
handle_loader(MPI_Info_get,INTERF_2_INTEL_CC);
handle_loader(MPI_Info_get_nkeys,INTERF_2_INTEL_CC);
handle_loader(MPI_Info_get_nthkey,INTERF_2_INTEL_CC);
handle_loader(MPI_Info_get_valuelen,INTERF_2_INTEL_CC);
handle_loader(MPI_Info_set,INTERF_2_INTEL_CC);
handle_loader(MPI_Request_get_status,INTERF_2_INTEL_CC);
handle_loader(MPI_Type_create_hvector,INTERF_2_INTEL_CC);
handle_loader(MPI_Type_create_resized,INTERF_2_INTEL_CC);
handle_loader(MPI_Type_get_extent,INTERF_2_INTEL_CC);
handle_loader(MPI_Type_get_true_extent,INTERF_2_INTEL_CC);
handle_loader(MPI_Win_create_errhandler,INTERF_2_INTEL_CC);
handle_loader(MPI_Win_get_errhandler,INTERF_2_INTEL_CC);
handle_loader(MPI_Win_set_errhandler,INTERF_2_INTEL_CC);
handle_loader(MPI_Type_create_f90_integer,INTERF_2_INTEL_CC);
handle_loader(MPI_Type_create_f90_real,INTERF_2_INTEL_CC);
handle_loader(MPI_Type_create_f90_complex,INTERF_2_INTEL_CC);
handle_loader(MPI_Reduce_local,INTERF_2_INTEL_CC);
handle_loader(MPI_Op_commutative,INTERF_2_INTEL_CC);
handle_loader(MPI_Reduce_scatter_block,INTERF_2_INTEL_CC);
handle_loader(MPI_Dist_graph_neighbors_count,INTERF_2_INTEL_CC);
handle_loader(MPI_Status_c2f,INTERF_2_INTEL_CC);
handle_loader(MPI_Status_f2c,INTERF_2_INTEL_CC);
handle_loader(MPI_Improbe,INTERF_2_INTEL_CC);
handle_loader(MPI_Imrecv,INTERF_2_INTEL_CC);
handle_loader(MPI_Mprobe,INTERF_2_INTEL_CC);
handle_loader(MPI_Mrecv,INTERF_2_INTEL_CC);
handle_loader(MPI_Comm_idup,INTERF_2_INTEL_CC);
handle_loader(MPI_Ibarrier,INTERF_2_INTEL_CC);
handle_loader(MPI_Ibcast,INTERF_2_INTEL_CC);
handle_loader(MPI_Igather,INTERF_2_INTEL_CC);
handle_loader(MPI_Iscatter,INTERF_2_INTEL_CC);
handle_loader(MPI_Iallgather,INTERF_2_INTEL_CC);
handle_loader(MPI_Ialltoall,INTERF_2_INTEL_CC);
handle_loader(MPI_Ireduce,INTERF_2_INTEL_CC);
handle_loader(MPI_Iallreduce,INTERF_2_INTEL_CC);
handle_loader(MPI_Ireduce_scatter_block,INTERF_2_INTEL_CC);
handle_loader(MPI_Iscan,INTERF_2_INTEL_CC);
handle_loader(MPI_Iexscan,INTERF_2_INTEL_CC);
handle_loader(MPI_Ineighbor_allgather,INTERF_2_INTEL_CC);
handle_loader(MPI_Ineighbor_alltoall,INTERF_2_INTEL_CC);
handle_loader(MPI_Neighbor_allgather,INTERF_2_INTEL_CC);
handle_loader(MPI_Neighbor_alltoall,INTERF_2_INTEL_CC);
handle_loader(MPI_Comm_split_type,INTERF_2_INTEL_CC);
handle_loader(MPI_Get_elements_x,INTERF_2_INTEL_CC);
handle_loader(MPI_Status_set_elements_x,INTERF_2_INTEL_CC);
handle_loader(MPI_Type_get_extent_x,INTERF_2_INTEL_CC);
handle_loader(MPI_Type_get_true_extent_x,INTERF_2_INTEL_CC);
handle_loader(MPI_Type_size_x,INTERF_2_INTEL_CC);
handle_loader(MPI_Comm_create_group,INTERF_2_INTEL_CC);
handle_loader(MPI_T_init_thread,INTERF_2_INTEL_CC);
handle_loader(MPI_T_enum_get_info,INTERF_2_INTEL_CC);
handle_loader(MPI_T_enum_get_item,INTERF_2_INTEL_CC);
handle_loader(MPI_T_cvar_get_num,INTERF_2_INTEL_CC);
handle_loader(MPI_T_cvar_get_info,INTERF_2_INTEL_CC);
handle_loader(MPI_T_cvar_handle_alloc,INTERF_2_INTEL_CC);
handle_loader(MPI_T_cvar_handle_free,INTERF_2_INTEL_CC);
handle_loader(MPI_T_cvar_read,INTERF_2_INTEL_CC);
handle_loader(MPI_T_cvar_write,INTERF_2_INTEL_CC);
handle_loader(MPI_T_pvar_get_num,INTERF_2_INTEL_CC);
handle_loader(MPI_T_pvar_get_info,INTERF_2_INTEL_CC);
handle_loader(MPI_T_pvar_session_create,INTERF_2_INTEL_CC);
handle_loader(MPI_T_pvar_session_free,INTERF_2_INTEL_CC);
handle_loader(MPI_T_pvar_handle_alloc,INTERF_2_INTEL_CC);
handle_loader(MPI_T_pvar_handle_free,INTERF_2_INTEL_CC);
handle_loader(MPI_T_pvar_start,INTERF_2_INTEL_CC);
handle_loader(MPI_T_pvar_stop,INTERF_2_INTEL_CC);
handle_loader(MPI_T_pvar_read,INTERF_2_INTEL_CC);
handle_loader(MPI_T_pvar_write,INTERF_2_INTEL_CC);
handle_loader(MPI_T_pvar_reset,INTERF_2_INTEL_CC);
handle_loader(MPI_T_pvar_readreset,INTERF_2_INTEL_CC);
handle_loader(MPI_T_category_get_num,INTERF_2_INTEL_CC);
handle_loader(MPI_T_category_get_info,INTERF_2_INTEL_CC);
handle_loader(MPI_File_open,INTERF_2_INTEL_CC);
handle_loader(MPI_File_close,INTERF_2_INTEL_CC);
handle_loader(MPI_File_delete,INTERF_2_INTEL_CC);
handle_loader(MPI_File_set_size,INTERF_2_INTEL_CC);
handle_loader(MPI_File_preallocate,INTERF_2_INTEL_CC);
handle_loader(MPI_File_get_size,INTERF_2_INTEL_CC);
handle_loader(MPI_File_get_group,INTERF_2_INTEL_CC);
handle_loader(MPI_File_get_amode,INTERF_2_INTEL_CC);
handle_loader(MPI_File_set_info,INTERF_2_INTEL_CC);
handle_loader(MPI_File_get_info,INTERF_2_INTEL_CC);
handle_loader(MPI_File_set_view,INTERF_2_INTEL_CC);
handle_loader(MPI_File_get_view,INTERF_2_INTEL_CC);
handle_loader(MPI_File_read_at,INTERF_2_INTEL_CC);
handle_loader(MPI_File_read_at_all,INTERF_2_INTEL_CC);
handle_loader(MPI_File_write_at,INTERF_2_INTEL_CC);
handle_loader(MPI_File_write_at_all,INTERF_2_INTEL_CC);
handle_loader(MPI_File_iread_at,INTERF_2_INTEL_CC);
handle_loader(MPI_File_iwrite_at,INTERF_2_INTEL_CC);
handle_loader(MPI_File_read,INTERF_2_INTEL_CC);
handle_loader(MPI_File_read_all,INTERF_2_INTEL_CC);
handle_loader(MPI_File_write,INTERF_2_INTEL_CC);
handle_loader(MPI_File_write_all,INTERF_2_INTEL_CC);
handle_loader(MPI_File_iread,INTERF_2_INTEL_CC);
handle_loader(MPI_File_iwrite,INTERF_2_INTEL_CC);
handle_loader(MPI_File_seek,INTERF_2_INTEL_CC);
handle_loader(MPI_File_get_position,INTERF_2_INTEL_CC);
handle_loader(MPI_File_get_byte_offset,INTERF_2_INTEL_CC);
handle_loader(MPI_File_read_shared,INTERF_2_INTEL_CC);
handle_loader(MPI_File_write_shared,INTERF_2_INTEL_CC);
handle_loader(MPI_File_iread_shared,INTERF_2_INTEL_CC);
handle_loader(MPI_File_iwrite_shared,INTERF_2_INTEL_CC);
handle_loader(MPI_File_read_ordered,INTERF_2_INTEL_CC);
handle_loader(MPI_File_write_ordered,INTERF_2_INTEL_CC);
handle_loader(MPI_File_seek_shared,INTERF_2_INTEL_CC);
handle_loader(MPI_File_get_position_shared,INTERF_2_INTEL_CC);
handle_loader(MPI_File_read_at_all_begin,INTERF_2_INTEL_CC);
handle_loader(MPI_File_read_at_all_end,INTERF_2_INTEL_CC);
handle_loader(MPI_File_write_at_all_begin,INTERF_2_INTEL_CC);
handle_loader(MPI_File_write_at_all_end,INTERF_2_INTEL_CC);
handle_loader(MPI_File_read_all_begin,INTERF_2_INTEL_CC);
handle_loader(MPI_File_read_all_end,INTERF_2_INTEL_CC);
handle_loader(MPI_File_write_all_begin,INTERF_2_INTEL_CC);
handle_loader(MPI_File_write_all_end,INTERF_2_INTEL_CC);
handle_loader(MPI_File_read_ordered_begin,INTERF_2_INTEL_CC);
handle_loader(MPI_File_read_ordered_end,INTERF_2_INTEL_CC);
handle_loader(MPI_File_write_ordered_begin,INTERF_2_INTEL_CC);
handle_loader(MPI_File_write_ordered_end,INTERF_2_INTEL_CC);
handle_loader(MPI_File_get_type_extent,INTERF_2_INTEL_CC);
handle_loader(MPI_Register_datarep,INTERF_2_INTEL_CC);
handle_loader(MPI_File_set_atomicity,INTERF_2_INTEL_CC);
handle_loader(MPI_File_get_atomicity,INTERF_2_INTEL_CC);
handle_loader(MPI_File_sync,INTERF_2_INTEL_CC);
handle_loader(MPI_T_finalize,INTERF_2_INTEL_CC);
handle_loader(MPI_Wtime,INTERF_2_INTEL_CC);
handle_loader(MPI_Wtick,INTERF_2_INTEL_CC);
handle_loader(MPI_Finalize,INTERF_2_INTEL_CC);
handle_loader(MPI_Waitany,INTERF_2_INTEL_CC);
handle_loader(MPI_Testany,INTERF_2_INTEL_CC);
handle_loader(MPI_Waitall,INTERF_2_INTEL_CC);
handle_loader(MPI_Testall,INTERF_2_INTEL_CC);
handle_loader(MPI_Waitsome,INTERF_2_INTEL_CC);
handle_loader(MPI_Testsome,INTERF_2_INTEL_CC);
handle_loader(MPI_Startall,INTERF_2_INTEL_CC);
handle_loader(MPI_Alltoallw,INTERF_2_INTEL_CC);
handle_loader(MPI_Reduce_scatter,INTERF_2_INTEL_CC);
handle_loader(MPI_Group_translate_ranks,INTERF_2_INTEL_CC);
handle_loader(MPI_Group_incl,INTERF_2_INTEL_CC);
handle_loader(MPI_Group_excl,INTERF_2_INTEL_CC);
handle_loader(MPI_Group_range_incl,INTERF_2_INTEL_CC);
handle_loader(MPI_Group_range_excl,INTERF_2_INTEL_CC);
handle_loader(MPI_Cart_create,INTERF_2_INTEL_CC);
handle_loader(MPI_Dims_create,INTERF_2_INTEL_CC);
handle_loader(MPI_Graph_create,INTERF_2_INTEL_CC);
handle_loader(MPI_Graph_get,INTERF_2_INTEL_CC);
handle_loader(MPI_Cart_get,INTERF_2_INTEL_CC);
handle_loader(MPI_Cart_rank,INTERF_2_INTEL_CC);
handle_loader(MPI_Cart_coords,INTERF_2_INTEL_CC);
handle_loader(MPI_Graph_neighbors,INTERF_2_INTEL_CC);
handle_loader(MPI_Cart_sub,INTERF_2_INTEL_CC);
handle_loader(MPI_Cart_map,INTERF_2_INTEL_CC);
handle_loader(MPI_Graph_map,INTERF_2_INTEL_CC);
handle_loader(MPI_Comm_spawn,INTERF_2_INTEL_CC);
handle_loader(MPI_Comm_spawn_multiple,INTERF_2_INTEL_CC);
handle_loader(MPI_Type_get_contents,INTERF_2_INTEL_CC);
handle_loader(MPI_Pack_external,INTERF_2_INTEL_CC);
handle_loader(MPI_Pack_external_size,INTERF_2_INTEL_CC);
handle_loader(MPI_Type_create_darray,INTERF_2_INTEL_CC);
handle_loader(MPI_Type_create_hindexed,INTERF_2_INTEL_CC);
handle_loader(MPI_Type_create_indexed_block,INTERF_2_INTEL_CC);
handle_loader(MPI_Type_create_hindexed_block,INTERF_2_INTEL_CC);
handle_loader(MPI_Type_create_struct,INTERF_2_INTEL_CC);
handle_loader(MPI_Type_create_subarray,INTERF_2_INTEL_CC);
handle_loader(MPI_Unpack_external,INTERF_2_INTEL_CC);
handle_loader(MPI_Dist_graph_create_adjacent,INTERF_2_INTEL_CC);
handle_loader(MPI_Dist_graph_create,INTERF_2_INTEL_CC);
handle_loader(MPI_Dist_graph_neighbors,INTERF_2_INTEL_CC);
handle_loader(MPI_Igatherv,INTERF_2_INTEL_CC);
handle_loader(MPI_Iscatterv,INTERF_2_INTEL_CC);
handle_loader(MPI_Iallgatherv,INTERF_2_INTEL_CC);
handle_loader(MPI_Ialltoallv,INTERF_2_INTEL_CC);
handle_loader(MPI_Ialltoallw,INTERF_2_INTEL_CC);
handle_loader(MPI_Ireduce_scatter,INTERF_2_INTEL_CC);
handle_loader(MPI_Ineighbor_allgatherv,INTERF_2_INTEL_CC);
handle_loader(MPI_Ineighbor_alltoallv,INTERF_2_INTEL_CC);
handle_loader(MPI_Ineighbor_alltoallw,INTERF_2_INTEL_CC);
handle_loader(MPI_Neighbor_allgatherv,INTERF_2_INTEL_CC);
handle_loader(MPI_Neighbor_alltoallv,INTERF_2_INTEL_CC);
handle_loader(MPI_Neighbor_alltoallw,INTERF_2_INTEL_CC);
handle_loader(MPI_T_category_get_cvars,INTERF_2_INTEL_CC);
handle_loader(MPI_T_category_get_pvars,INTERF_2_INTEL_CC);
handle_loader(MPI_T_category_get_categories,INTERF_2_INTEL_CC);
handle_loader(MPI_File_iwrite_all,INTERF_2_INTEL_CC);
handle_loader(MPI_File_iwrite_at_all,INTERF_2_INTEL_CC);
handle_loader(MPI_Group_c2f,INTERF_2_INTEL_CC);
handle_loader(MPI_Group_f2c,INTERF_2_INTEL_CC);
handle_loader(MPI_Info_c2f,INTERF_2_INTEL_CC);
handle_loader(MPI_Info_f2c,INTERF_2_INTEL_CC);
handle_loader(MPI_Errhandler_c2f,INTERF_2_INTEL_CC);
handle_loader(MPI_Errhandler_f2c,INTERF_2_INTEL_CC);
handle_loader(MPI_Message_c2f,INTERF_2_INTEL_CC);
handle_loader(MPI_Message_f2c,INTERF_2_INTEL_CC);
handle_loader(MPI_Op_c2f,INTERF_2_INTEL_CC);
handle_loader(MPI_Op_f2c,INTERF_2_INTEL_CC);
handle_loader(MPI_Request_c2f,INTERF_2_INTEL_CC);
handle_loader(MPI_Request_f2c,INTERF_2_INTEL_CC);
handle_loader(MPI_T_category_get_index,INTERF_2_INTEL_CC);
handle_loader(MPI_T_cvar_get_index,INTERF_2_INTEL_CC);
handle_loader(MPI_T_pvar_get_index,INTERF_2_INTEL_CC);
handle_loader(MPI_Type_c2f,INTERF_2_INTEL_CC);
handle_loader(MPI_Type_f2c,INTERF_2_INTEL_CC);
handle_loader(MPI_Win_c2f,INTERF_2_INTEL_CC);
handle_loader(MPI_Win_f2c,INTERF_2_INTEL_CC);
handle_loader(MPI_Aint_add,INTERF_2_INTEL_CC);
handle_loader(MPI_Aint_diff,INTERF_2_INTEL_CC);
handle_loader(MPI_Comm_c2f,INTERF_2_INTEL_CC);
handle_loader(MPI_Comm_f2c,INTERF_2_INTEL_CC);
handle_loader(MPI_File_c2f,INTERF_2_INTEL_CC);
handle_loader(MPI_File_f2c,INTERF_2_INTEL_CC);
handle_loader(MPI_File_iread_all,INTERF_2_INTEL_CC);
handle_loader(MPI_File_iread_at_all,INTERF_2_INTEL_CC);
handle_loader(MPI_T_category_changed,INTERF_2_INTEL_CC);
INTERF_2_INTEL_wrapper_init();
INTERF_2_INTEL_wrapper_init_f();
}else{
printf("no target library defined conversion cannot be choosen\n" );
exit(1);

}
}
#endif
wrapper_interface_f();
}

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
#include "wrapper_f.h"
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
extern __thread int in_w;
void mpi_send_(void *, int *, int *, int *, int *, int *, int *);

void mpi_send__(void *, int *, int *, int *, int *, int *, int *);

void pmpi_send_(void *, int *, int *, int *, int *, int *, int *);

void pmpi_send__(void *, int *, int *, int *, int *, int *, int *);

void pmpi_send_(void *, int *, int *, int *, int *, int *, int *);

#define A_f_MPI_Send _PMPI_Send
#pragma weak mpi_send_ = _PMPI_Send
#pragma weak mpi_send__ = _PMPI_Send
#pragma weak pmpi_send__ = _PMPI_Send
extern long long WI4MPI_Send_timeout;
void (*_LOCAL_MPI_Send)(void *, int *, int *, int *, int *, int *, int *);

void A_f_MPI_Send(void *buf, int *count, int *datatype, int *dest, int *tag,
                  int *comm, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Send\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Send_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  int dest_tmp;
  int tag_tmp;
  int comm_tmp;
  buffer_a2r(&buf, &buf_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  rank_mapper_a2r(dest, &dest_tmp);
  tag_a2r(tag, &tag_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Send(buf_tmp, count, &datatype_tmp, &dest_tmp, &tag_tmp, &comm_tmp,
                  &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Send\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_recv_(void *, int *, int *, int *, int *, int *, int *, int *);

void mpi_recv__(void *, int *, int *, int *, int *, int *, int *, int *);

void pmpi_recv_(void *, int *, int *, int *, int *, int *, int *, int *);

void pmpi_recv__(void *, int *, int *, int *, int *, int *, int *, int *);

void pmpi_recv_(void *, int *, int *, int *, int *, int *, int *, int *);

#define A_f_MPI_Recv _PMPI_Recv
#pragma weak mpi_recv_ = _PMPI_Recv
#pragma weak mpi_recv__ = _PMPI_Recv
#pragma weak pmpi_recv__ = _PMPI_Recv
extern long long WI4MPI_Recv_timeout;
void (*_LOCAL_MPI_Recv)(void *, int *, int *, int *, int *, int *, int *,
                        int *);

void A_f_MPI_Recv(void *buf, int *count, int *datatype, int *source, int *tag,
                  int *comm, int *status, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Recv\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Recv_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  int source_tmp;
  int tag_tmp;
  int comm_tmp;
  int status_tmp1[R_f_MPI_STATUS_SIZE + 1];
  int *status_tmp =
      (status == A_f_MPI_STATUS_IGNORE ? R_f_MPI_STATUS_IGNORE : status_tmp1);
  buffer_a2r(&buf, &buf_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  source_a2r(source, &source_tmp);
  tag_a2r(tag, &tag_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Recv(buf_tmp, count, &datatype_tmp, &source_tmp, &tag_tmp,
                  &comm_tmp, status_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&buf, &buf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    if (status != A_f_MPI_STATUS_IGNORE)
      status_r2a(status, status_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Recv\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_get_count_(int *, int *, int *, int *);

void mpi_get_count__(int *, int *, int *, int *);

void pmpi_get_count_(int *, int *, int *, int *);

void pmpi_get_count__(int *, int *, int *, int *);

void pmpi_get_count_(int *, int *, int *, int *);

#define A_f_MPI_Get_count _PMPI_Get_count
#pragma weak mpi_get_count_ = _PMPI_Get_count
#pragma weak mpi_get_count__ = _PMPI_Get_count
#pragma weak pmpi_get_count__ = _PMPI_Get_count
extern long long WI4MPI_Get_count_timeout;
void (*_LOCAL_MPI_Get_count)(int *, int *, int *, int *);

void A_f_MPI_Get_count(int *status, int *datatype, int *count, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Get_count\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Get_count_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int status_tmp1[R_f_MPI_STATUS_SIZE + 1];
  int *status_tmp =
      (status == A_f_MPI_STATUS_IGNORE ? R_f_MPI_STATUS_IGNORE : status_tmp1);
  int datatype_tmp;
  status_a2r(status, status_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_Get_count(status_tmp, &datatype_tmp, count, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Get_count\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_bsend_(void *, int *, int *, int *, int *, int *, int *);

void mpi_bsend__(void *, int *, int *, int *, int *, int *, int *);

void pmpi_bsend_(void *, int *, int *, int *, int *, int *, int *);

void pmpi_bsend__(void *, int *, int *, int *, int *, int *, int *);

void pmpi_bsend_(void *, int *, int *, int *, int *, int *, int *);

#define A_f_MPI_Bsend _PMPI_Bsend
#pragma weak mpi_bsend_ = _PMPI_Bsend
#pragma weak mpi_bsend__ = _PMPI_Bsend
#pragma weak pmpi_bsend__ = _PMPI_Bsend
extern long long WI4MPI_Bsend_timeout;
void (*_LOCAL_MPI_Bsend)(void *, int *, int *, int *, int *, int *, int *);

void A_f_MPI_Bsend(void *buf, int *count, int *datatype, int *dest, int *tag,
                   int *comm, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Bsend\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Bsend_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  int dest_tmp;
  int tag_tmp;
  int comm_tmp;
  buffer_a2r(&buf, &buf_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  rank_mapper_a2r(dest, &dest_tmp);
  tag_a2r(tag, &tag_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Bsend(buf_tmp, count, &datatype_tmp, &dest_tmp, &tag_tmp,
                   &comm_tmp, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Bsend\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_ssend_(void *, int *, int *, int *, int *, int *, int *);

void mpi_ssend__(void *, int *, int *, int *, int *, int *, int *);

void pmpi_ssend_(void *, int *, int *, int *, int *, int *, int *);

void pmpi_ssend__(void *, int *, int *, int *, int *, int *, int *);

void pmpi_ssend_(void *, int *, int *, int *, int *, int *, int *);

#define A_f_MPI_Ssend _PMPI_Ssend
#pragma weak mpi_ssend_ = _PMPI_Ssend
#pragma weak mpi_ssend__ = _PMPI_Ssend
#pragma weak pmpi_ssend__ = _PMPI_Ssend
extern long long WI4MPI_Ssend_timeout;
void (*_LOCAL_MPI_Ssend)(void *, int *, int *, int *, int *, int *, int *);

void A_f_MPI_Ssend(void *buf, int *count, int *datatype, int *dest, int *tag,
                   int *comm, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Ssend\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Ssend_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  int dest_tmp;
  int tag_tmp;
  int comm_tmp;
  buffer_a2r(&buf, &buf_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  rank_mapper_a2r(dest, &dest_tmp);
  tag_a2r(tag, &tag_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Ssend(buf_tmp, count, &datatype_tmp, &dest_tmp, &tag_tmp,
                   &comm_tmp, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Ssend\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_rsend_(void *, int *, int *, int *, int *, int *, int *);

void mpi_rsend__(void *, int *, int *, int *, int *, int *, int *);

void pmpi_rsend_(void *, int *, int *, int *, int *, int *, int *);

void pmpi_rsend__(void *, int *, int *, int *, int *, int *, int *);

void pmpi_rsend_(void *, int *, int *, int *, int *, int *, int *);

#define A_f_MPI_Rsend _PMPI_Rsend
#pragma weak mpi_rsend_ = _PMPI_Rsend
#pragma weak mpi_rsend__ = _PMPI_Rsend
#pragma weak pmpi_rsend__ = _PMPI_Rsend
extern long long WI4MPI_Rsend_timeout;
void (*_LOCAL_MPI_Rsend)(void *, int *, int *, int *, int *, int *, int *);

void A_f_MPI_Rsend(void *buf, int *count, int *datatype, int *dest, int *tag,
                   int *comm, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Rsend\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Rsend_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  int dest_tmp;
  int tag_tmp;
  int comm_tmp;
  buffer_a2r(&buf, &buf_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  rank_mapper_a2r(dest, &dest_tmp);
  tag_a2r(tag, &tag_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Rsend(buf_tmp, count, &datatype_tmp, &dest_tmp, &tag_tmp,
                   &comm_tmp, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Rsend\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_buffer_attach_(void *, int *, int *);

void mpi_buffer_attach__(void *, int *, int *);

void pmpi_buffer_attach_(void *, int *, int *);

void pmpi_buffer_attach__(void *, int *, int *);

void pmpi_buffer_attach_(void *, int *, int *);

#define A_f_MPI_Buffer_attach _PMPI_Buffer_attach
#pragma weak mpi_buffer_attach_ = _PMPI_Buffer_attach
#pragma weak mpi_buffer_attach__ = _PMPI_Buffer_attach
#pragma weak pmpi_buffer_attach__ = _PMPI_Buffer_attach
extern long long WI4MPI_Buffer_attach_timeout;
void (*_LOCAL_MPI_Buffer_attach)(void *, int *, int *);

void A_f_MPI_Buffer_attach(void *buffer, int *size, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Buffer_attach\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Buffer_attach_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buffer_tmp = buffer;
  buffer_a2r(&buffer, &buffer_tmp);
  _LOCAL_MPI_Buffer_attach(buffer_tmp, size, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Buffer_attach\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_buffer_detach_(void *, int *, int *);

void mpi_buffer_detach__(void *, int *, int *);

void pmpi_buffer_detach_(void *, int *, int *);

void pmpi_buffer_detach__(void *, int *, int *);

void pmpi_buffer_detach_(void *, int *, int *);

#define A_f_MPI_Buffer_detach _PMPI_Buffer_detach
#pragma weak mpi_buffer_detach_ = _PMPI_Buffer_detach
#pragma weak mpi_buffer_detach__ = _PMPI_Buffer_detach
#pragma weak pmpi_buffer_detach__ = _PMPI_Buffer_detach
extern long long WI4MPI_Buffer_detach_timeout;
void (*_LOCAL_MPI_Buffer_detach)(void *, int *, int *);

void A_f_MPI_Buffer_detach(void *buffer_addr, int *size, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Buffer_detach\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Buffer_detach_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buffer_addr_tmp = buffer_addr;
  _LOCAL_MPI_Buffer_detach(buffer_addr_tmp, size, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&buffer_addr, &buffer_addr_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Buffer_detach\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_isend_(void *, int *, int *, int *, int *, int *, int *, int *);

void mpi_isend__(void *, int *, int *, int *, int *, int *, int *, int *);

void pmpi_isend_(void *, int *, int *, int *, int *, int *, int *, int *);

void pmpi_isend__(void *, int *, int *, int *, int *, int *, int *, int *);

void pmpi_isend_(void *, int *, int *, int *, int *, int *, int *, int *);

#define A_f_MPI_Isend _PMPI_Isend
#pragma weak mpi_isend_ = _PMPI_Isend
#pragma weak mpi_isend__ = _PMPI_Isend
#pragma weak pmpi_isend__ = _PMPI_Isend
extern long long WI4MPI_Isend_timeout;
void (*_LOCAL_MPI_Isend)(void *, int *, int *, int *, int *, int *, int *,
                         int *);

void A_f_MPI_Isend(void *buf, int *count, int *datatype, int *dest, int *tag,
                   int *comm, int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Isend\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Isend_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  int dest_tmp;
  int tag_tmp;
  int comm_tmp;
  int request_tmp;
  buffer_a2r(&buf, &buf_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  rank_mapper_a2r(dest, &dest_tmp);
  tag_a2r(tag, &tag_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Isend(buf_tmp, count, &datatype_tmp, &dest_tmp, &tag_tmp,
                   &comm_tmp, &request_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Isend\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_ibsend_(void *, int *, int *, int *, int *, int *, int *, int *);

void mpi_ibsend__(void *, int *, int *, int *, int *, int *, int *, int *);

void pmpi_ibsend_(void *, int *, int *, int *, int *, int *, int *, int *);

void pmpi_ibsend__(void *, int *, int *, int *, int *, int *, int *, int *);

void pmpi_ibsend_(void *, int *, int *, int *, int *, int *, int *, int *);

#define A_f_MPI_Ibsend _PMPI_Ibsend
#pragma weak mpi_ibsend_ = _PMPI_Ibsend
#pragma weak mpi_ibsend__ = _PMPI_Ibsend
#pragma weak pmpi_ibsend__ = _PMPI_Ibsend
extern long long WI4MPI_Ibsend_timeout;
void (*_LOCAL_MPI_Ibsend)(void *, int *, int *, int *, int *, int *, int *,
                          int *);

void A_f_MPI_Ibsend(void *buf, int *count, int *datatype, int *dest, int *tag,
                    int *comm, int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Ibsend\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Ibsend_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  int dest_tmp;
  int tag_tmp;
  int comm_tmp;
  int request_tmp;
  buffer_a2r(&buf, &buf_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  rank_mapper_a2r(dest, &dest_tmp);
  tag_a2r(tag, &tag_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Ibsend(buf_tmp, count, &datatype_tmp, &dest_tmp, &tag_tmp,
                    &comm_tmp, &request_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Ibsend\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_issend_(void *, int *, int *, int *, int *, int *, int *, int *);

void mpi_issend__(void *, int *, int *, int *, int *, int *, int *, int *);

void pmpi_issend_(void *, int *, int *, int *, int *, int *, int *, int *);

void pmpi_issend__(void *, int *, int *, int *, int *, int *, int *, int *);

void pmpi_issend_(void *, int *, int *, int *, int *, int *, int *, int *);

#define A_f_MPI_Issend _PMPI_Issend
#pragma weak mpi_issend_ = _PMPI_Issend
#pragma weak mpi_issend__ = _PMPI_Issend
#pragma weak pmpi_issend__ = _PMPI_Issend
extern long long WI4MPI_Issend_timeout;
void (*_LOCAL_MPI_Issend)(void *, int *, int *, int *, int *, int *, int *,
                          int *);

void A_f_MPI_Issend(void *buf, int *count, int *datatype, int *dest, int *tag,
                    int *comm, int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Issend\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Issend_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  int dest_tmp;
  int tag_tmp;
  int comm_tmp;
  int request_tmp;
  buffer_a2r(&buf, &buf_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  rank_mapper_a2r(dest, &dest_tmp);
  tag_a2r(tag, &tag_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Issend(buf_tmp, count, &datatype_tmp, &dest_tmp, &tag_tmp,
                    &comm_tmp, &request_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Issend\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_irsend_(void *, int *, int *, int *, int *, int *, int *, int *);

void mpi_irsend__(void *, int *, int *, int *, int *, int *, int *, int *);

void pmpi_irsend_(void *, int *, int *, int *, int *, int *, int *, int *);

void pmpi_irsend__(void *, int *, int *, int *, int *, int *, int *, int *);

void pmpi_irsend_(void *, int *, int *, int *, int *, int *, int *, int *);

#define A_f_MPI_Irsend _PMPI_Irsend
#pragma weak mpi_irsend_ = _PMPI_Irsend
#pragma weak mpi_irsend__ = _PMPI_Irsend
#pragma weak pmpi_irsend__ = _PMPI_Irsend
extern long long WI4MPI_Irsend_timeout;
void (*_LOCAL_MPI_Irsend)(void *, int *, int *, int *, int *, int *, int *,
                          int *);

void A_f_MPI_Irsend(void *buf, int *count, int *datatype, int *dest, int *tag,
                    int *comm, int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Irsend\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Irsend_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  int dest_tmp;
  int tag_tmp;
  int comm_tmp;
  int request_tmp;
  buffer_a2r(&buf, &buf_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  rank_mapper_a2r(dest, &dest_tmp);
  tag_a2r(tag, &tag_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Irsend(buf_tmp, count, &datatype_tmp, &dest_tmp, &tag_tmp,
                    &comm_tmp, &request_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Irsend\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_irecv_(void *, int *, int *, int *, int *, int *, int *, int *);

void mpi_irecv__(void *, int *, int *, int *, int *, int *, int *, int *);

void pmpi_irecv_(void *, int *, int *, int *, int *, int *, int *, int *);

void pmpi_irecv__(void *, int *, int *, int *, int *, int *, int *, int *);

void pmpi_irecv_(void *, int *, int *, int *, int *, int *, int *, int *);

#define A_f_MPI_Irecv _PMPI_Irecv
#pragma weak mpi_irecv_ = _PMPI_Irecv
#pragma weak mpi_irecv__ = _PMPI_Irecv
#pragma weak pmpi_irecv__ = _PMPI_Irecv
extern long long WI4MPI_Irecv_timeout;
void (*_LOCAL_MPI_Irecv)(void *, int *, int *, int *, int *, int *, int *,
                         int *);

void A_f_MPI_Irecv(void *buf, int *count, int *datatype, int *source, int *tag,
                   int *comm, int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Irecv\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Irecv_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  int source_tmp;
  int tag_tmp;
  int comm_tmp;
  int request_tmp;
  datatype_a2r(datatype, &datatype_tmp);
  source_a2r(source, &source_tmp);
  tag_a2r(tag, &tag_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Irecv(buf_tmp, count, &datatype_tmp, &source_tmp, &tag_tmp,
                   &comm_tmp, &request_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&buf, &buf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Irecv\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_wait_(int *, int *, int *);

void mpi_wait__(int *, int *, int *);

void pmpi_wait_(int *, int *, int *);

void pmpi_wait__(int *, int *, int *);

void pmpi_wait_(int *, int *, int *);

#define A_f_MPI_Wait _PMPI_Wait
#pragma weak mpi_wait_ = _PMPI_Wait
#pragma weak mpi_wait__ = _PMPI_Wait
#pragma weak pmpi_wait__ = _PMPI_Wait
extern long long WI4MPI_Wait_timeout;
void (*_LOCAL_MPI_Wait)(int *, int *, int *);

void A_f_MPI_Wait(int *request, int *status, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Wait\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Wait_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int request_tmp;
  int status_tmp1[R_f_MPI_STATUS_SIZE + 1];
  int *status_tmp =
      (status == A_f_MPI_STATUS_IGNORE ? R_f_MPI_STATUS_IGNORE : status_tmp1);
  request_a2r(request, &request_tmp);
  _LOCAL_MPI_Wait(&request_tmp, status_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    if (status != A_f_MPI_STATUS_IGNORE)
      status_r2a(status, status_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Wait\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_test_(int *, int *, int *, int *);

void mpi_test__(int *, int *, int *, int *);

void pmpi_test_(int *, int *, int *, int *);

void pmpi_test__(int *, int *, int *, int *);

void pmpi_test_(int *, int *, int *, int *);

#define A_f_MPI_Test _PMPI_Test
#pragma weak mpi_test_ = _PMPI_Test
#pragma weak mpi_test__ = _PMPI_Test
#pragma weak pmpi_test__ = _PMPI_Test
extern long long WI4MPI_Test_timeout;
void (*_LOCAL_MPI_Test)(int *, int *, int *, int *);

void A_f_MPI_Test(int *request, int *flag, int *status, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Test\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Test_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int request_tmp;
  int status_tmp1[R_f_MPI_STATUS_SIZE + 1];
  int *status_tmp =
      (status == A_f_MPI_STATUS_IGNORE ? R_f_MPI_STATUS_IGNORE : status_tmp1);
  request_a2r(request, &request_tmp);
  _LOCAL_MPI_Test(&request_tmp, flag, status_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    if (status != A_f_MPI_STATUS_IGNORE)
      status_r2a(status, status_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Test\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_request_free_(int *, int *);

void mpi_request_free__(int *, int *);

void pmpi_request_free_(int *, int *);

void pmpi_request_free__(int *, int *);

void pmpi_request_free_(int *, int *);

#define A_f_MPI_Request_free _PMPI_Request_free
#pragma weak mpi_request_free_ = _PMPI_Request_free
#pragma weak mpi_request_free__ = _PMPI_Request_free
#pragma weak pmpi_request_free__ = _PMPI_Request_free
extern long long WI4MPI_Request_free_timeout;
void (*_LOCAL_MPI_Request_free)(int *, int *);

void A_f_MPI_Request_free(int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Request_free\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Request_free_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int request_tmp;
  request_a2r(request, &request_tmp);
  _LOCAL_MPI_Request_free(&request_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Request_free\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_iprobe_(int *, int *, int *, int *, int *, int *);

void mpi_iprobe__(int *, int *, int *, int *, int *, int *);

void pmpi_iprobe_(int *, int *, int *, int *, int *, int *);

void pmpi_iprobe__(int *, int *, int *, int *, int *, int *);

void pmpi_iprobe_(int *, int *, int *, int *, int *, int *);

#define A_f_MPI_Iprobe _PMPI_Iprobe
#pragma weak mpi_iprobe_ = _PMPI_Iprobe
#pragma weak mpi_iprobe__ = _PMPI_Iprobe
#pragma weak pmpi_iprobe__ = _PMPI_Iprobe
extern long long WI4MPI_Iprobe_timeout;
void (*_LOCAL_MPI_Iprobe)(int *, int *, int *, int *, int *, int *);

void A_f_MPI_Iprobe(int *source, int *tag, int *comm, int *flag, int *status,
                    int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Iprobe\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Iprobe_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int source_tmp;
  int tag_tmp;
  int comm_tmp;
  int status_tmp1[R_f_MPI_STATUS_SIZE + 1];
  int *status_tmp =
      (status == A_f_MPI_STATUS_IGNORE ? R_f_MPI_STATUS_IGNORE : status_tmp1);
  source_a2r(source, &source_tmp);
  tag_a2r(tag, &tag_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Iprobe(&source_tmp, &tag_tmp, &comm_tmp, flag, status_tmp,
                    &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    if (status != A_f_MPI_STATUS_IGNORE)
      status_r2a(status, status_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Iprobe\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_probe_(int *, int *, int *, int *, int *);

void mpi_probe__(int *, int *, int *, int *, int *);

void pmpi_probe_(int *, int *, int *, int *, int *);

void pmpi_probe__(int *, int *, int *, int *, int *);

void pmpi_probe_(int *, int *, int *, int *, int *);

#define A_f_MPI_Probe _PMPI_Probe
#pragma weak mpi_probe_ = _PMPI_Probe
#pragma weak mpi_probe__ = _PMPI_Probe
#pragma weak pmpi_probe__ = _PMPI_Probe
extern long long WI4MPI_Probe_timeout;
void (*_LOCAL_MPI_Probe)(int *, int *, int *, int *, int *);

void A_f_MPI_Probe(int *source, int *tag, int *comm, int *status, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Probe\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Probe_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int source_tmp;
  int tag_tmp;
  int comm_tmp;
  int status_tmp1[R_f_MPI_STATUS_SIZE + 1];
  int *status_tmp =
      (status == A_f_MPI_STATUS_IGNORE ? R_f_MPI_STATUS_IGNORE : status_tmp1);
  source_a2r(source, &source_tmp);
  tag_a2r(tag, &tag_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Probe(&source_tmp, &tag_tmp, &comm_tmp, status_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    if (status != A_f_MPI_STATUS_IGNORE)
      status_r2a(status, status_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Probe\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_cancel_(int *, int *);

void mpi_cancel__(int *, int *);

void pmpi_cancel_(int *, int *);

void pmpi_cancel__(int *, int *);

void pmpi_cancel_(int *, int *);

#define A_f_MPI_Cancel _PMPI_Cancel
#pragma weak mpi_cancel_ = _PMPI_Cancel
#pragma weak mpi_cancel__ = _PMPI_Cancel
#pragma weak pmpi_cancel__ = _PMPI_Cancel
extern long long WI4MPI_Cancel_timeout;
void (*_LOCAL_MPI_Cancel)(int *, int *);

void A_f_MPI_Cancel(int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Cancel\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Cancel_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int request_tmp;
  request_a2r(request, &request_tmp);
  _LOCAL_MPI_Cancel(&request_tmp, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Cancel\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_test_cancelled_(int *, int *, int *);

void mpi_test_cancelled__(int *, int *, int *);

void pmpi_test_cancelled_(int *, int *, int *);

void pmpi_test_cancelled__(int *, int *, int *);

void pmpi_test_cancelled_(int *, int *, int *);

#define A_f_MPI_Test_cancelled _PMPI_Test_cancelled
#pragma weak mpi_test_cancelled_ = _PMPI_Test_cancelled
#pragma weak mpi_test_cancelled__ = _PMPI_Test_cancelled
#pragma weak pmpi_test_cancelled__ = _PMPI_Test_cancelled
extern long long WI4MPI_Test_cancelled_timeout;
void (*_LOCAL_MPI_Test_cancelled)(int *, int *, int *);

void A_f_MPI_Test_cancelled(int *status, int *flag, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Test_cancelled\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Test_cancelled_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int status_tmp1[R_f_MPI_STATUS_SIZE + 1];
  int *status_tmp =
      (status == A_f_MPI_STATUS_IGNORE ? R_f_MPI_STATUS_IGNORE : status_tmp1);
  status_a2r(status, status_tmp);
  _LOCAL_MPI_Test_cancelled(status_tmp, flag, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Test_cancelled\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_send_init_(void *, int *, int *, int *, int *, int *, int *, int *);

void mpi_send_init__(void *, int *, int *, int *, int *, int *, int *, int *);

void pmpi_send_init_(void *, int *, int *, int *, int *, int *, int *, int *);

void pmpi_send_init__(void *, int *, int *, int *, int *, int *, int *, int *);

void pmpi_send_init_(void *, int *, int *, int *, int *, int *, int *, int *);

#define A_f_MPI_Send_init _PMPI_Send_init
#pragma weak mpi_send_init_ = _PMPI_Send_init
#pragma weak mpi_send_init__ = _PMPI_Send_init
#pragma weak pmpi_send_init__ = _PMPI_Send_init
extern long long WI4MPI_Send_init_timeout;
void (*_LOCAL_MPI_Send_init)(void *, int *, int *, int *, int *, int *, int *,
                             int *);

void A_f_MPI_Send_init(void *buf, int *count, int *datatype, int *dest,
                       int *tag, int *comm, int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Send_init\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Send_init_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  int dest_tmp;
  int tag_tmp;
  int comm_tmp;
  int request_tmp;
  buffer_a2r(&buf, &buf_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  rank_mapper_a2r(dest, &dest_tmp);
  tag_a2r(tag, &tag_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Send_init(buf_tmp, count, &datatype_tmp, &dest_tmp, &tag_tmp,
                       &comm_tmp, &request_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Send_init\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_bsend_init_(void *, int *, int *, int *, int *, int *, int *, int *);

void mpi_bsend_init__(void *, int *, int *, int *, int *, int *, int *, int *);

void pmpi_bsend_init_(void *, int *, int *, int *, int *, int *, int *, int *);

void pmpi_bsend_init__(void *, int *, int *, int *, int *, int *, int *, int *);

void pmpi_bsend_init_(void *, int *, int *, int *, int *, int *, int *, int *);

#define A_f_MPI_Bsend_init _PMPI_Bsend_init
#pragma weak mpi_bsend_init_ = _PMPI_Bsend_init
#pragma weak mpi_bsend_init__ = _PMPI_Bsend_init
#pragma weak pmpi_bsend_init__ = _PMPI_Bsend_init
extern long long WI4MPI_Bsend_init_timeout;
void (*_LOCAL_MPI_Bsend_init)(void *, int *, int *, int *, int *, int *, int *,
                              int *);

void A_f_MPI_Bsend_init(void *buf, int *count, int *datatype, int *dest,
                        int *tag, int *comm, int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Bsend_init\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Bsend_init_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  int dest_tmp;
  int tag_tmp;
  int comm_tmp;
  int request_tmp;
  buffer_a2r(&buf, &buf_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  rank_mapper_a2r(dest, &dest_tmp);
  tag_a2r(tag, &tag_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Bsend_init(buf_tmp, count, &datatype_tmp, &dest_tmp, &tag_tmp,
                        &comm_tmp, &request_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Bsend_init\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_ssend_init_(void *, int *, int *, int *, int *, int *, int *, int *);

void mpi_ssend_init__(void *, int *, int *, int *, int *, int *, int *, int *);

void pmpi_ssend_init_(void *, int *, int *, int *, int *, int *, int *, int *);

void pmpi_ssend_init__(void *, int *, int *, int *, int *, int *, int *, int *);

void pmpi_ssend_init_(void *, int *, int *, int *, int *, int *, int *, int *);

#define A_f_MPI_Ssend_init _PMPI_Ssend_init
#pragma weak mpi_ssend_init_ = _PMPI_Ssend_init
#pragma weak mpi_ssend_init__ = _PMPI_Ssend_init
#pragma weak pmpi_ssend_init__ = _PMPI_Ssend_init
extern long long WI4MPI_Ssend_init_timeout;
void (*_LOCAL_MPI_Ssend_init)(void *, int *, int *, int *, int *, int *, int *,
                              int *);

void A_f_MPI_Ssend_init(void *buf, int *count, int *datatype, int *dest,
                        int *tag, int *comm, int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Ssend_init\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Ssend_init_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  int dest_tmp;
  int tag_tmp;
  int comm_tmp;
  int request_tmp;
  buffer_a2r(&buf, &buf_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  rank_mapper_a2r(dest, &dest_tmp);
  tag_a2r(tag, &tag_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Ssend_init(buf_tmp, count, &datatype_tmp, &dest_tmp, &tag_tmp,
                        &comm_tmp, &request_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Ssend_init\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_rsend_init_(void *, int *, int *, int *, int *, int *, int *, int *);

void mpi_rsend_init__(void *, int *, int *, int *, int *, int *, int *, int *);

void pmpi_rsend_init_(void *, int *, int *, int *, int *, int *, int *, int *);

void pmpi_rsend_init__(void *, int *, int *, int *, int *, int *, int *, int *);

void pmpi_rsend_init_(void *, int *, int *, int *, int *, int *, int *, int *);

#define A_f_MPI_Rsend_init _PMPI_Rsend_init
#pragma weak mpi_rsend_init_ = _PMPI_Rsend_init
#pragma weak mpi_rsend_init__ = _PMPI_Rsend_init
#pragma weak pmpi_rsend_init__ = _PMPI_Rsend_init
extern long long WI4MPI_Rsend_init_timeout;
void (*_LOCAL_MPI_Rsend_init)(void *, int *, int *, int *, int *, int *, int *,
                              int *);

void A_f_MPI_Rsend_init(void *buf, int *count, int *datatype, int *dest,
                        int *tag, int *comm, int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Rsend_init\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Rsend_init_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  int dest_tmp;
  int tag_tmp;
  int comm_tmp;
  int request_tmp;
  buffer_a2r(&buf, &buf_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  rank_mapper_a2r(dest, &dest_tmp);
  tag_a2r(tag, &tag_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Rsend_init(buf_tmp, count, &datatype_tmp, &dest_tmp, &tag_tmp,
                        &comm_tmp, &request_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Rsend_init\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_recv_init_(void *, int *, int *, int *, int *, int *, int *, int *);

void mpi_recv_init__(void *, int *, int *, int *, int *, int *, int *, int *);

void pmpi_recv_init_(void *, int *, int *, int *, int *, int *, int *, int *);

void pmpi_recv_init__(void *, int *, int *, int *, int *, int *, int *, int *);

void pmpi_recv_init_(void *, int *, int *, int *, int *, int *, int *, int *);

#define A_f_MPI_Recv_init _PMPI_Recv_init
#pragma weak mpi_recv_init_ = _PMPI_Recv_init
#pragma weak mpi_recv_init__ = _PMPI_Recv_init
#pragma weak pmpi_recv_init__ = _PMPI_Recv_init
extern long long WI4MPI_Recv_init_timeout;
void (*_LOCAL_MPI_Recv_init)(void *, int *, int *, int *, int *, int *, int *,
                             int *);

void A_f_MPI_Recv_init(void *buf, int *count, int *datatype, int *source,
                       int *tag, int *comm, int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Recv_init\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Recv_init_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  int source_tmp;
  int tag_tmp;
  int comm_tmp;
  int request_tmp;
  datatype_a2r(datatype, &datatype_tmp);
  source_a2r(source, &source_tmp);
  tag_a2r(tag, &tag_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Recv_init(buf_tmp, count, &datatype_tmp, &source_tmp, &tag_tmp,
                       &comm_tmp, &request_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&buf, &buf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Recv_init\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_start_(int *, int *);

void mpi_start__(int *, int *);

void pmpi_start_(int *, int *);

void pmpi_start__(int *, int *);

void pmpi_start_(int *, int *);

#define A_f_MPI_Start _PMPI_Start
#pragma weak mpi_start_ = _PMPI_Start
#pragma weak mpi_start__ = _PMPI_Start
#pragma weak pmpi_start__ = _PMPI_Start
extern long long WI4MPI_Start_timeout;
void (*_LOCAL_MPI_Start)(int *, int *);

void A_f_MPI_Start(int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Start\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Start_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int request_tmp;
  request_a2r(request, &request_tmp);
  _LOCAL_MPI_Start(&request_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Start\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_sendrecv_(void *, int *, int *, int *, int *, void *, int *, int *,
                   int *, int *, int *, int *, int *);

void mpi_sendrecv__(void *, int *, int *, int *, int *, void *, int *, int *,
                    int *, int *, int *, int *, int *);

void pmpi_sendrecv_(void *, int *, int *, int *, int *, void *, int *, int *,
                    int *, int *, int *, int *, int *);

void pmpi_sendrecv__(void *, int *, int *, int *, int *, void *, int *, int *,
                     int *, int *, int *, int *, int *);

void pmpi_sendrecv_(void *, int *, int *, int *, int *, void *, int *, int *,
                    int *, int *, int *, int *, int *);

#define A_f_MPI_Sendrecv _PMPI_Sendrecv
#pragma weak mpi_sendrecv_ = _PMPI_Sendrecv
#pragma weak mpi_sendrecv__ = _PMPI_Sendrecv
#pragma weak pmpi_sendrecv__ = _PMPI_Sendrecv
extern long long WI4MPI_Sendrecv_timeout;
void (*_LOCAL_MPI_Sendrecv)(void *, int *, int *, int *, int *, void *, int *,
                            int *, int *, int *, int *, int *, int *);

void A_f_MPI_Sendrecv(void *sendbuf, int *sendcount, int *sendtype, int *dest,
                      int *sendtag, void *recvbuf, int *recvcount,
                      int *recvtype, int *source, int *recvtag, int *comm,
                      int *status, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Sendrecv\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Sendrecv_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *sendbuf_tmp = sendbuf;
  int sendtype_tmp;
  int dest_tmp;
  int sendtag_tmp;
  void *recvbuf_tmp = recvbuf;
  int recvtype_tmp;
  int source_tmp;
  int recvtag_tmp;
  int comm_tmp;
  int status_tmp1[R_f_MPI_STATUS_SIZE + 1];
  int *status_tmp =
      (status == A_f_MPI_STATUS_IGNORE ? R_f_MPI_STATUS_IGNORE : status_tmp1);
  buffer_a2r(&sendbuf, &sendbuf_tmp);
  datatype_a2r(sendtype, &sendtype_tmp);
  rank_mapper_a2r(dest, &dest_tmp);
  tag_a2r(sendtag, &sendtag_tmp);
  datatype_a2r(recvtype, &recvtype_tmp);
  source_a2r(source, &source_tmp);
  tag_a2r(recvtag, &recvtag_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Sendrecv(sendbuf_tmp, sendcount, &sendtype_tmp, &dest_tmp,
                      &sendtag_tmp, recvbuf_tmp, recvcount, &recvtype_tmp,
                      &source_tmp, &recvtag_tmp, &comm_tmp, status_tmp,
                      &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&recvbuf, &recvbuf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    if (status != A_f_MPI_STATUS_IGNORE)
      status_r2a(status, status_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Sendrecv\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_sendrecv_replace_(void *, int *, int *, int *, int *, int *, int *,
                           int *, int *, int *);

void mpi_sendrecv_replace__(void *, int *, int *, int *, int *, int *, int *,
                            int *, int *, int *);

void pmpi_sendrecv_replace_(void *, int *, int *, int *, int *, int *, int *,
                            int *, int *, int *);

void pmpi_sendrecv_replace__(void *, int *, int *, int *, int *, int *, int *,
                             int *, int *, int *);

void pmpi_sendrecv_replace_(void *, int *, int *, int *, int *, int *, int *,
                            int *, int *, int *);

#define A_f_MPI_Sendrecv_replace _PMPI_Sendrecv_replace
#pragma weak mpi_sendrecv_replace_ = _PMPI_Sendrecv_replace
#pragma weak mpi_sendrecv_replace__ = _PMPI_Sendrecv_replace
#pragma weak pmpi_sendrecv_replace__ = _PMPI_Sendrecv_replace
extern long long WI4MPI_Sendrecv_replace_timeout;
void (*_LOCAL_MPI_Sendrecv_replace)(void *, int *, int *, int *, int *, int *,
                                    int *, int *, int *, int *);

void A_f_MPI_Sendrecv_replace(void *buf, int *count, int *datatype, int *dest,
                              int *sendtag, int *source, int *recvtag,
                              int *comm, int *status, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Sendrecv_replace\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Sendrecv_replace_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  int dest_tmp;
  int sendtag_tmp;
  int source_tmp;
  int recvtag_tmp;
  int comm_tmp;
  int status_tmp1[R_f_MPI_STATUS_SIZE + 1];
  int *status_tmp =
      (status == A_f_MPI_STATUS_IGNORE ? R_f_MPI_STATUS_IGNORE : status_tmp1);
  buffer_a2r(&buf, &buf_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  rank_mapper_a2r(dest, &dest_tmp);
  tag_a2r(sendtag, &sendtag_tmp);
  source_a2r(source, &source_tmp);
  tag_a2r(recvtag, &recvtag_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Sendrecv_replace(buf_tmp, count, &datatype_tmp, &dest_tmp,
                              &sendtag_tmp, &source_tmp, &recvtag_tmp,
                              &comm_tmp, status_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&buf, &buf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    if (status != A_f_MPI_STATUS_IGNORE)
      status_r2a(status, status_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Sendrecv_replace\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_type_contiguous_(int *, int *, int *, int *);

void mpi_type_contiguous__(int *, int *, int *, int *);

void pmpi_type_contiguous_(int *, int *, int *, int *);

void pmpi_type_contiguous__(int *, int *, int *, int *);

void pmpi_type_contiguous_(int *, int *, int *, int *);

#define A_f_MPI_Type_contiguous _PMPI_Type_contiguous
#pragma weak mpi_type_contiguous_ = _PMPI_Type_contiguous
#pragma weak mpi_type_contiguous__ = _PMPI_Type_contiguous
#pragma weak pmpi_type_contiguous__ = _PMPI_Type_contiguous
extern long long WI4MPI_Type_contiguous_timeout;
void (*_LOCAL_MPI_Type_contiguous)(int *, int *, int *, int *);

void A_f_MPI_Type_contiguous(int *count, int *oldtype, int *newtype, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Type_contiguous\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Type_contiguous_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int oldtype_tmp;
  int newtype_tmp;
  datatype_a2r(oldtype, &oldtype_tmp);
  _LOCAL_MPI_Type_contiguous(count, &oldtype_tmp, &newtype_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    datatype_r2a(newtype, &newtype_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Type_contiguous\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_type_vector_(int *, int *, int *, int *, int *, int *);

void mpi_type_vector__(int *, int *, int *, int *, int *, int *);

void pmpi_type_vector_(int *, int *, int *, int *, int *, int *);

void pmpi_type_vector__(int *, int *, int *, int *, int *, int *);

void pmpi_type_vector_(int *, int *, int *, int *, int *, int *);

#define A_f_MPI_Type_vector _PMPI_Type_vector
#pragma weak mpi_type_vector_ = _PMPI_Type_vector
#pragma weak mpi_type_vector__ = _PMPI_Type_vector
#pragma weak pmpi_type_vector__ = _PMPI_Type_vector
extern long long WI4MPI_Type_vector_timeout;
void (*_LOCAL_MPI_Type_vector)(int *, int *, int *, int *, int *, int *);

void A_f_MPI_Type_vector(int *count, int *blocklength, int *stride,
                         int *oldtype, int *newtype, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Type_vector\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Type_vector_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int oldtype_tmp;
  int newtype_tmp;
  datatype_a2r(oldtype, &oldtype_tmp);
  _LOCAL_MPI_Type_vector(count, blocklength, stride, &oldtype_tmp, &newtype_tmp,
                         &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    datatype_r2a(newtype, &newtype_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Type_vector\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_type_hvector_(int *, int *, size_t *, int *, int *, int *);

void mpi_type_hvector__(int *, int *, size_t *, int *, int *, int *);

void pmpi_type_hvector_(int *, int *, size_t *, int *, int *, int *);

void pmpi_type_hvector__(int *, int *, size_t *, int *, int *, int *);

void pmpi_type_hvector_(int *, int *, size_t *, int *, int *, int *);

#define A_f_MPI_Type_hvector _PMPI_Type_hvector
#pragma weak mpi_type_hvector_ = _PMPI_Type_hvector
#pragma weak mpi_type_hvector__ = _PMPI_Type_hvector
#pragma weak pmpi_type_hvector__ = _PMPI_Type_hvector
extern long long WI4MPI_Type_hvector_timeout;
void (*_LOCAL_MPI_Type_hvector)(int *, int *, size_t *, int *, int *, int *);

void A_f_MPI_Type_hvector(int *count, int *blocklength, size_t *stride,
                          int *oldtype, int *newtype, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Type_hvector\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Type_hvector_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int oldtype_tmp;
  int newtype_tmp;
  datatype_a2r(oldtype, &oldtype_tmp);
  _LOCAL_MPI_Type_hvector(count, blocklength, stride, &oldtype_tmp,
                          &newtype_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    datatype_r2a(newtype, &newtype_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Type_hvector\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_type_indexed_(int *, int *, int *, int *, int *, int *);

void mpi_type_indexed__(int *, int *, int *, int *, int *, int *);

void pmpi_type_indexed_(int *, int *, int *, int *, int *, int *);

void pmpi_type_indexed__(int *, int *, int *, int *, int *, int *);

void pmpi_type_indexed_(int *, int *, int *, int *, int *, int *);

#define A_f_MPI_Type_indexed _PMPI_Type_indexed
#pragma weak mpi_type_indexed_ = _PMPI_Type_indexed
#pragma weak mpi_type_indexed__ = _PMPI_Type_indexed
#pragma weak pmpi_type_indexed__ = _PMPI_Type_indexed
extern long long WI4MPI_Type_indexed_timeout;
void (*_LOCAL_MPI_Type_indexed)(int *, int *, int *, int *, int *, int *);

void A_f_MPI_Type_indexed(int *count, int *array_of_blocklengths,
                          int *array_of_displacements, int *oldtype,
                          int *newtype, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Type_indexed\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Type_indexed_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int oldtype_tmp;
  int newtype_tmp;
  datatype_a2r(oldtype, &oldtype_tmp);
  _LOCAL_MPI_Type_indexed(count, array_of_blocklengths, array_of_displacements,
                          &oldtype_tmp, &newtype_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    datatype_r2a(newtype, &newtype_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Type_indexed\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_type_hindexed_(int *, int *, size_t *, int *, int *, int *);

void mpi_type_hindexed__(int *, int *, size_t *, int *, int *, int *);

void pmpi_type_hindexed_(int *, int *, size_t *, int *, int *, int *);

void pmpi_type_hindexed__(int *, int *, size_t *, int *, int *, int *);

void pmpi_type_hindexed_(int *, int *, size_t *, int *, int *, int *);

#define A_f_MPI_Type_hindexed _PMPI_Type_hindexed
#pragma weak mpi_type_hindexed_ = _PMPI_Type_hindexed
#pragma weak mpi_type_hindexed__ = _PMPI_Type_hindexed
#pragma weak pmpi_type_hindexed__ = _PMPI_Type_hindexed
extern long long WI4MPI_Type_hindexed_timeout;
void (*_LOCAL_MPI_Type_hindexed)(int *, int *, size_t *, int *, int *, int *);

void A_f_MPI_Type_hindexed(int *count, int *array_of_blocklengths,
                           size_t *array_of_displacements, int *oldtype,
                           int *newtype, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Type_hindexed\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Type_hindexed_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int oldtype_tmp;
  int newtype_tmp;
  datatype_a2r(oldtype, &oldtype_tmp);
  _LOCAL_MPI_Type_hindexed(count, array_of_blocklengths, array_of_displacements,
                           &oldtype_tmp, &newtype_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    datatype_r2a(newtype, &newtype_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Type_hindexed\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_type_struct_(int *, int *, size_t *, int *, int *, int *);

void mpi_type_struct__(int *, int *, size_t *, int *, int *, int *);

void pmpi_type_struct_(int *, int *, size_t *, int *, int *, int *);

void pmpi_type_struct__(int *, int *, size_t *, int *, int *, int *);

void pmpi_type_struct_(int *, int *, size_t *, int *, int *, int *);

#define A_f_MPI_Type_struct _PMPI_Type_struct
#pragma weak mpi_type_struct_ = _PMPI_Type_struct
#pragma weak mpi_type_struct__ = _PMPI_Type_struct
#pragma weak pmpi_type_struct__ = _PMPI_Type_struct
extern long long WI4MPI_Type_struct_timeout;
void (*_LOCAL_MPI_Type_struct)(int *, int *, size_t *, int *, int *, int *);

void A_f_MPI_Type_struct(int *count, int *array_of_blocklengths,
                         size_t *array_of_displacements, int *array_of_types,
                         int *newtype, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Type_struct\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Type_struct_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int *array_of_types_tmp = (int *)wi4mpi_alloc((*count) * 1 * sizeof(int));
  int newtype_tmp;
  for (int i = 0; i < *count; i++)
    datatype_a2r(&array_of_types[i * 1], &array_of_types_tmp[i * 1]);
  _LOCAL_MPI_Type_struct(count, array_of_blocklengths, array_of_displacements,
                         array_of_types_tmp, &newtype_tmp, &ret_tmp);
  wi4mpi_free(array_of_types_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    datatype_r2a(newtype, &newtype_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Type_struct\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_address_(void *, size_t *, int *);

void mpi_address__(void *, size_t *, int *);

void pmpi_address_(void *, size_t *, int *);

void pmpi_address__(void *, size_t *, int *);

void pmpi_address_(void *, size_t *, int *);

#define A_f_MPI_Address _PMPI_Address
#pragma weak mpi_address_ = _PMPI_Address
#pragma weak mpi_address__ = _PMPI_Address
#pragma weak pmpi_address__ = _PMPI_Address
extern long long WI4MPI_Address_timeout;
void (*_LOCAL_MPI_Address)(void *, size_t *, int *);

void A_f_MPI_Address(void *location, size_t *address, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Address\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Address_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *location_tmp = location;
  buffer_a2r(&location, &location_tmp);
  _LOCAL_MPI_Address(location_tmp, address, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Address\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_type_extent_(int *, size_t *, int *);

void mpi_type_extent__(int *, size_t *, int *);

void pmpi_type_extent_(int *, size_t *, int *);

void pmpi_type_extent__(int *, size_t *, int *);

void pmpi_type_extent_(int *, size_t *, int *);

#define A_f_MPI_Type_extent _PMPI_Type_extent
#pragma weak mpi_type_extent_ = _PMPI_Type_extent
#pragma weak mpi_type_extent__ = _PMPI_Type_extent
#pragma weak pmpi_type_extent__ = _PMPI_Type_extent
extern long long WI4MPI_Type_extent_timeout;
void (*_LOCAL_MPI_Type_extent)(int *, size_t *, int *);

void A_f_MPI_Type_extent(int *datatype, size_t *extent, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Type_extent\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Type_extent_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int datatype_tmp;
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_Type_extent(&datatype_tmp, extent, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Type_extent\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_type_size_(int *, int *, int *);

void mpi_type_size__(int *, int *, int *);

void pmpi_type_size_(int *, int *, int *);

void pmpi_type_size__(int *, int *, int *);

void pmpi_type_size_(int *, int *, int *);

#define A_f_MPI_Type_size _PMPI_Type_size
#pragma weak mpi_type_size_ = _PMPI_Type_size
#pragma weak mpi_type_size__ = _PMPI_Type_size
#pragma weak pmpi_type_size__ = _PMPI_Type_size
extern long long WI4MPI_Type_size_timeout;
void (*_LOCAL_MPI_Type_size)(int *, int *, int *);

void A_f_MPI_Type_size(int *datatype, int *size, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Type_size\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Type_size_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int datatype_tmp;
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_Type_size(&datatype_tmp, size, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Type_size\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_type_lb_(int *, size_t *, int *);

void mpi_type_lb__(int *, size_t *, int *);

void pmpi_type_lb_(int *, size_t *, int *);

void pmpi_type_lb__(int *, size_t *, int *);

void pmpi_type_lb_(int *, size_t *, int *);

#define A_f_MPI_Type_lb _PMPI_Type_lb
#pragma weak mpi_type_lb_ = _PMPI_Type_lb
#pragma weak mpi_type_lb__ = _PMPI_Type_lb
#pragma weak pmpi_type_lb__ = _PMPI_Type_lb
extern long long WI4MPI_Type_lb_timeout;
void (*_LOCAL_MPI_Type_lb)(int *, size_t *, int *);

void A_f_MPI_Type_lb(int *datatype, size_t *displacement, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Type_lb\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Type_lb_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int datatype_tmp;
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_Type_lb(&datatype_tmp, displacement, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Type_lb\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_type_ub_(int *, size_t *, int *);

void mpi_type_ub__(int *, size_t *, int *);

void pmpi_type_ub_(int *, size_t *, int *);

void pmpi_type_ub__(int *, size_t *, int *);

void pmpi_type_ub_(int *, size_t *, int *);

#define A_f_MPI_Type_ub _PMPI_Type_ub
#pragma weak mpi_type_ub_ = _PMPI_Type_ub
#pragma weak mpi_type_ub__ = _PMPI_Type_ub
#pragma weak pmpi_type_ub__ = _PMPI_Type_ub
extern long long WI4MPI_Type_ub_timeout;
void (*_LOCAL_MPI_Type_ub)(int *, size_t *, int *);

void A_f_MPI_Type_ub(int *datatype, size_t *displacement, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Type_ub\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Type_ub_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int datatype_tmp;
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_Type_ub(&datatype_tmp, displacement, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Type_ub\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_type_commit_(int *, int *);

void mpi_type_commit__(int *, int *);

void pmpi_type_commit_(int *, int *);

void pmpi_type_commit__(int *, int *);

void pmpi_type_commit_(int *, int *);

#define A_f_MPI_Type_commit _PMPI_Type_commit
#pragma weak mpi_type_commit_ = _PMPI_Type_commit
#pragma weak mpi_type_commit__ = _PMPI_Type_commit
#pragma weak pmpi_type_commit__ = _PMPI_Type_commit
extern long long WI4MPI_Type_commit_timeout;
void (*_LOCAL_MPI_Type_commit)(int *, int *);

void A_f_MPI_Type_commit(int *datatype, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Type_commit\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Type_commit_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int datatype_tmp;
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_Type_commit(&datatype_tmp, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Type_commit\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_type_free_(int *, int *);

void mpi_type_free__(int *, int *);

void pmpi_type_free_(int *, int *);

void pmpi_type_free__(int *, int *);

void pmpi_type_free_(int *, int *);

#define A_f_MPI_Type_free _PMPI_Type_free
#pragma weak mpi_type_free_ = _PMPI_Type_free
#pragma weak mpi_type_free__ = _PMPI_Type_free
#pragma weak pmpi_type_free__ = _PMPI_Type_free
extern long long WI4MPI_Type_free_timeout;
void (*_LOCAL_MPI_Type_free)(int *, int *);

void A_f_MPI_Type_free(int *datatype, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Type_free\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Type_free_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int datatype_tmp;
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_Type_free(&datatype_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    datatype_r2a(datatype, &datatype_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Type_free\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_get_elements_(int *, int *, int *, int *);

void mpi_get_elements__(int *, int *, int *, int *);

void pmpi_get_elements_(int *, int *, int *, int *);

void pmpi_get_elements__(int *, int *, int *, int *);

void pmpi_get_elements_(int *, int *, int *, int *);

#define A_f_MPI_Get_elements _PMPI_Get_elements
#pragma weak mpi_get_elements_ = _PMPI_Get_elements
#pragma weak mpi_get_elements__ = _PMPI_Get_elements
#pragma weak pmpi_get_elements__ = _PMPI_Get_elements
extern long long WI4MPI_Get_elements_timeout;
void (*_LOCAL_MPI_Get_elements)(int *, int *, int *, int *);

void A_f_MPI_Get_elements(int *status, int *datatype, int *count, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Get_elements\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Get_elements_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int status_tmp1[R_f_MPI_STATUS_SIZE + 1];
  int *status_tmp =
      (status == A_f_MPI_STATUS_IGNORE ? R_f_MPI_STATUS_IGNORE : status_tmp1);
  int datatype_tmp;
  status_a2r(status, status_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_Get_elements(status_tmp, &datatype_tmp, count, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Get_elements\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_pack_(void *, int *, int *, void *, int *, int *, int *, int *);

void mpi_pack__(void *, int *, int *, void *, int *, int *, int *, int *);

void pmpi_pack_(void *, int *, int *, void *, int *, int *, int *, int *);

void pmpi_pack__(void *, int *, int *, void *, int *, int *, int *, int *);

void pmpi_pack_(void *, int *, int *, void *, int *, int *, int *, int *);

#define A_f_MPI_Pack _PMPI_Pack
#pragma weak mpi_pack_ = _PMPI_Pack
#pragma weak mpi_pack__ = _PMPI_Pack
#pragma weak pmpi_pack__ = _PMPI_Pack
extern long long WI4MPI_Pack_timeout;
void (*_LOCAL_MPI_Pack)(void *, int *, int *, void *, int *, int *, int *,
                        int *);

void A_f_MPI_Pack(void *inbuf, int *incount, int *datatype, void *outbuf,
                  int *outsize, int *position, int *comm, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Pack\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Pack_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *inbuf_tmp = inbuf;
  int datatype_tmp;
  void *outbuf_tmp = outbuf;
  int comm_tmp;
  buffer_a2r(&inbuf, &inbuf_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Pack(inbuf_tmp, incount, &datatype_tmp, outbuf_tmp, outsize,
                  position, &comm_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&outbuf, &outbuf_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Pack\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_unpack_(void *, int *, int *, void *, int *, int *, int *, int *);

void mpi_unpack__(void *, int *, int *, void *, int *, int *, int *, int *);

void pmpi_unpack_(void *, int *, int *, void *, int *, int *, int *, int *);

void pmpi_unpack__(void *, int *, int *, void *, int *, int *, int *, int *);

void pmpi_unpack_(void *, int *, int *, void *, int *, int *, int *, int *);

#define A_f_MPI_Unpack _PMPI_Unpack
#pragma weak mpi_unpack_ = _PMPI_Unpack
#pragma weak mpi_unpack__ = _PMPI_Unpack
#pragma weak pmpi_unpack__ = _PMPI_Unpack
extern long long WI4MPI_Unpack_timeout;
void (*_LOCAL_MPI_Unpack)(void *, int *, int *, void *, int *, int *, int *,
                          int *);

void A_f_MPI_Unpack(void *inbuf, int *insize, int *position, void *outbuf,
                    int *outcount, int *datatype, int *comm, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Unpack\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Unpack_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *inbuf_tmp = inbuf;
  void *outbuf_tmp = outbuf;
  int datatype_tmp;
  int comm_tmp;
  buffer_a2r(&inbuf, &inbuf_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Unpack(inbuf_tmp, insize, position, outbuf_tmp, outcount,
                    &datatype_tmp, &comm_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&outbuf, &outbuf_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Unpack\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_pack_size_(int *, int *, int *, int *, int *);

void mpi_pack_size__(int *, int *, int *, int *, int *);

void pmpi_pack_size_(int *, int *, int *, int *, int *);

void pmpi_pack_size__(int *, int *, int *, int *, int *);

void pmpi_pack_size_(int *, int *, int *, int *, int *);

#define A_f_MPI_Pack_size _PMPI_Pack_size
#pragma weak mpi_pack_size_ = _PMPI_Pack_size
#pragma weak mpi_pack_size__ = _PMPI_Pack_size
#pragma weak pmpi_pack_size__ = _PMPI_Pack_size
extern long long WI4MPI_Pack_size_timeout;
void (*_LOCAL_MPI_Pack_size)(int *, int *, int *, int *, int *);

void A_f_MPI_Pack_size(int *incount, int *datatype, int *comm, int *size,
                       int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Pack_size\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Pack_size_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int datatype_tmp;
  int comm_tmp;
  datatype_a2r(datatype, &datatype_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Pack_size(incount, &datatype_tmp, &comm_tmp, size, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Pack_size\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_barrier_(int *, int *);

void mpi_barrier__(int *, int *);

void pmpi_barrier_(int *, int *);

void pmpi_barrier__(int *, int *);

void pmpi_barrier_(int *, int *);

#define A_f_MPI_Barrier _PMPI_Barrier
#pragma weak mpi_barrier_ = _PMPI_Barrier
#pragma weak mpi_barrier__ = _PMPI_Barrier
#pragma weak pmpi_barrier__ = _PMPI_Barrier
extern long long WI4MPI_Barrier_timeout;
void (*_LOCAL_MPI_Barrier)(int *, int *);

void A_f_MPI_Barrier(int *comm, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Barrier\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Barrier_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Barrier(&comm_tmp, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Barrier\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_bcast_(void *, int *, int *, int *, int *, int *);

void mpi_bcast__(void *, int *, int *, int *, int *, int *);

void pmpi_bcast_(void *, int *, int *, int *, int *, int *);

void pmpi_bcast__(void *, int *, int *, int *, int *, int *);

void pmpi_bcast_(void *, int *, int *, int *, int *, int *);

#define A_f_MPI_Bcast _PMPI_Bcast
#pragma weak mpi_bcast_ = _PMPI_Bcast
#pragma weak mpi_bcast__ = _PMPI_Bcast
#pragma weak pmpi_bcast__ = _PMPI_Bcast
extern long long WI4MPI_Bcast_timeout;
void (*_LOCAL_MPI_Bcast)(void *, int *, int *, int *, int *, int *);

void A_f_MPI_Bcast(void *buffer, int *count, int *datatype, int *root,
                   int *comm, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Bcast\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Bcast_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buffer_tmp = buffer;
  int datatype_tmp;
  int comm_tmp;
  buffer_a2r(&buffer, &buffer_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Bcast(buffer_tmp, count, &datatype_tmp, root, &comm_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&buffer, &buffer_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Bcast\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_gather_(void *, int *, int *, void *, int *, int *, int *, int *,
                 int *);

void mpi_gather__(void *, int *, int *, void *, int *, int *, int *, int *,
                  int *);

void pmpi_gather_(void *, int *, int *, void *, int *, int *, int *, int *,
                  int *);

void pmpi_gather__(void *, int *, int *, void *, int *, int *, int *, int *,
                   int *);

void pmpi_gather_(void *, int *, int *, void *, int *, int *, int *, int *,
                  int *);

#define A_f_MPI_Gather _PMPI_Gather
#pragma weak mpi_gather_ = _PMPI_Gather
#pragma weak mpi_gather__ = _PMPI_Gather
#pragma weak pmpi_gather__ = _PMPI_Gather
extern long long WI4MPI_Gather_timeout;
void (*_LOCAL_MPI_Gather)(void *, int *, int *, void *, int *, int *, int *,
                          int *, int *);

void A_f_MPI_Gather(void *sendbuf, int *sendcount, int *sendtype, void *recvbuf,
                    int *recvcount, int *recvtype, int *root, int *comm,
                    int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Gather\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Gather_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *sendbuf_tmp = sendbuf;
  int sendtype_tmp;
  void *recvbuf_tmp = recvbuf;
  int recvtype_tmp;
  int comm_tmp;
  buffer_a2r(&sendbuf, &sendbuf_tmp);
  datatype_a2r(sendtype, &sendtype_tmp);
  buffer_a2r(&recvbuf, &recvbuf_tmp);
  datatype_a2r(recvtype, &recvtype_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Gather(sendbuf_tmp, sendcount, &sendtype_tmp, recvbuf_tmp,
                    recvcount, &recvtype_tmp, root, &comm_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&recvbuf, &recvbuf_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Gather\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_gatherv_(void *, int *, int *, void *, int *, int *, int *, int *,
                  int *, int *);

void mpi_gatherv__(void *, int *, int *, void *, int *, int *, int *, int *,
                   int *, int *);

void pmpi_gatherv_(void *, int *, int *, void *, int *, int *, int *, int *,
                   int *, int *);

void pmpi_gatherv__(void *, int *, int *, void *, int *, int *, int *, int *,
                    int *, int *);

void pmpi_gatherv_(void *, int *, int *, void *, int *, int *, int *, int *,
                   int *, int *);

#define A_f_MPI_Gatherv _PMPI_Gatherv
#pragma weak mpi_gatherv_ = _PMPI_Gatherv
#pragma weak mpi_gatherv__ = _PMPI_Gatherv
#pragma weak pmpi_gatherv__ = _PMPI_Gatherv
extern long long WI4MPI_Gatherv_timeout;
void (*_LOCAL_MPI_Gatherv)(void *, int *, int *, void *, int *, int *, int *,
                           int *, int *, int *);

void A_f_MPI_Gatherv(void *sendbuf, int *sendcount, int *sendtype,
                     void *recvbuf, int *recvcounts, int *displs, int *recvtype,
                     int *root, int *comm, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Gatherv\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Gatherv_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *sendbuf_tmp = sendbuf;
  int sendtype_tmp;
  void *recvbuf_tmp = recvbuf;
  int recvtype_tmp;
  int comm_tmp;
  buffer_a2r(&sendbuf, &sendbuf_tmp);
  datatype_a2r(sendtype, &sendtype_tmp);
  buffer_a2r(&recvbuf, &recvbuf_tmp);
  datatype_a2r(recvtype, &recvtype_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Gatherv(sendbuf_tmp, sendcount, &sendtype_tmp, recvbuf_tmp,
                     recvcounts, displs, &recvtype_tmp, root, &comm_tmp,
                     &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&recvbuf, &recvbuf_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Gatherv\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_scatter_(void *, int *, int *, void *, int *, int *, int *, int *,
                  int *);

void mpi_scatter__(void *, int *, int *, void *, int *, int *, int *, int *,
                   int *);

void pmpi_scatter_(void *, int *, int *, void *, int *, int *, int *, int *,
                   int *);

void pmpi_scatter__(void *, int *, int *, void *, int *, int *, int *, int *,
                    int *);

void pmpi_scatter_(void *, int *, int *, void *, int *, int *, int *, int *,
                   int *);

#define A_f_MPI_Scatter _PMPI_Scatter
#pragma weak mpi_scatter_ = _PMPI_Scatter
#pragma weak mpi_scatter__ = _PMPI_Scatter
#pragma weak pmpi_scatter__ = _PMPI_Scatter
extern long long WI4MPI_Scatter_timeout;
void (*_LOCAL_MPI_Scatter)(void *, int *, int *, void *, int *, int *, int *,
                           int *, int *);

void A_f_MPI_Scatter(void *sendbuf, int *sendcount, int *sendtype,
                     void *recvbuf, int *recvcount, int *recvtype, int *root,
                     int *comm, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Scatter\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Scatter_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *sendbuf_tmp = sendbuf;
  int sendtype_tmp;
  void *recvbuf_tmp = recvbuf;
  int recvtype_tmp;
  int comm_tmp;
  buffer_a2r(&sendbuf, &sendbuf_tmp);
  datatype_a2r(sendtype, &sendtype_tmp);
  buffer_a2r(&recvbuf, &recvbuf_tmp);
  datatype_a2r(recvtype, &recvtype_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Scatter(sendbuf_tmp, sendcount, &sendtype_tmp, recvbuf_tmp,
                     recvcount, &recvtype_tmp, root, &comm_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&recvbuf, &recvbuf_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Scatter\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_scatterv_(void *, int *, int *, int *, void *, int *, int *, int *,
                   int *, int *);

void mpi_scatterv__(void *, int *, int *, int *, void *, int *, int *, int *,
                    int *, int *);

void pmpi_scatterv_(void *, int *, int *, int *, void *, int *, int *, int *,
                    int *, int *);

void pmpi_scatterv__(void *, int *, int *, int *, void *, int *, int *, int *,
                     int *, int *);

void pmpi_scatterv_(void *, int *, int *, int *, void *, int *, int *, int *,
                    int *, int *);

#define A_f_MPI_Scatterv _PMPI_Scatterv
#pragma weak mpi_scatterv_ = _PMPI_Scatterv
#pragma weak mpi_scatterv__ = _PMPI_Scatterv
#pragma weak pmpi_scatterv__ = _PMPI_Scatterv
extern long long WI4MPI_Scatterv_timeout;
void (*_LOCAL_MPI_Scatterv)(void *, int *, int *, int *, void *, int *, int *,
                            int *, int *, int *);

void A_f_MPI_Scatterv(void *sendbuf, int *sendcounts, int *displs,
                      int *sendtype, void *recvbuf, int *recvcount,
                      int *recvtype, int *root, int *comm, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Scatterv\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Scatterv_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *sendbuf_tmp = sendbuf;
  int sendtype_tmp;
  void *recvbuf_tmp = recvbuf;
  int recvtype_tmp;
  int comm_tmp;
  buffer_a2r(&sendbuf, &sendbuf_tmp);
  datatype_a2r(sendtype, &sendtype_tmp);
  buffer_a2r(&recvbuf, &recvbuf_tmp);
  datatype_a2r(recvtype, &recvtype_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Scatterv(sendbuf_tmp, sendcounts, displs, &sendtype_tmp,
                      recvbuf_tmp, recvcount, &recvtype_tmp, root, &comm_tmp,
                      &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&recvbuf, &recvbuf_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Scatterv\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_allgather_(void *, int *, int *, void *, int *, int *, int *, int *);

void mpi_allgather__(void *, int *, int *, void *, int *, int *, int *, int *);

void pmpi_allgather_(void *, int *, int *, void *, int *, int *, int *, int *);

void pmpi_allgather__(void *, int *, int *, void *, int *, int *, int *, int *);

void pmpi_allgather_(void *, int *, int *, void *, int *, int *, int *, int *);

#define A_f_MPI_Allgather _PMPI_Allgather
#pragma weak mpi_allgather_ = _PMPI_Allgather
#pragma weak mpi_allgather__ = _PMPI_Allgather
#pragma weak pmpi_allgather__ = _PMPI_Allgather
extern long long WI4MPI_Allgather_timeout;
void (*_LOCAL_MPI_Allgather)(void *, int *, int *, void *, int *, int *, int *,
                             int *);

void A_f_MPI_Allgather(void *sendbuf, int *sendcount, int *sendtype,
                       void *recvbuf, int *recvcount, int *recvtype, int *comm,
                       int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Allgather\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Allgather_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *sendbuf_tmp = sendbuf;
  int sendtype_tmp;
  void *recvbuf_tmp = recvbuf;
  int recvtype_tmp;
  int comm_tmp;
  buffer_a2r(&sendbuf, &sendbuf_tmp);
  datatype_a2r(sendtype, &sendtype_tmp);
  buffer_a2r(&recvbuf, &recvbuf_tmp);
  datatype_a2r(recvtype, &recvtype_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Allgather(sendbuf_tmp, sendcount, &sendtype_tmp, recvbuf_tmp,
                       recvcount, &recvtype_tmp, &comm_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&recvbuf, &recvbuf_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Allgather\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_allgatherv_(void *, int *, int *, void *, int *, int *, int *, int *,
                     int *);

void mpi_allgatherv__(void *, int *, int *, void *, int *, int *, int *, int *,
                      int *);

void pmpi_allgatherv_(void *, int *, int *, void *, int *, int *, int *, int *,
                      int *);

void pmpi_allgatherv__(void *, int *, int *, void *, int *, int *, int *, int *,
                       int *);

void pmpi_allgatherv_(void *, int *, int *, void *, int *, int *, int *, int *,
                      int *);

#define A_f_MPI_Allgatherv _PMPI_Allgatherv
#pragma weak mpi_allgatherv_ = _PMPI_Allgatherv
#pragma weak mpi_allgatherv__ = _PMPI_Allgatherv
#pragma weak pmpi_allgatherv__ = _PMPI_Allgatherv
extern long long WI4MPI_Allgatherv_timeout;
void (*_LOCAL_MPI_Allgatherv)(void *, int *, int *, void *, int *, int *, int *,
                              int *, int *);

void A_f_MPI_Allgatherv(void *sendbuf, int *sendcount, int *sendtype,
                        void *recvbuf, int *recvcounts, int *displs,
                        int *recvtype, int *comm, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Allgatherv\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Allgatherv_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *sendbuf_tmp = sendbuf;
  int sendtype_tmp;
  void *recvbuf_tmp = recvbuf;
  int recvtype_tmp;
  int comm_tmp;
  buffer_a2r(&sendbuf, &sendbuf_tmp);
  datatype_a2r(sendtype, &sendtype_tmp);
  buffer_a2r(&recvbuf, &recvbuf_tmp);
  datatype_a2r(recvtype, &recvtype_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Allgatherv(sendbuf_tmp, sendcount, &sendtype_tmp, recvbuf_tmp,
                        recvcounts, displs, &recvtype_tmp, &comm_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&recvbuf, &recvbuf_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Allgatherv\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_alltoall_(void *, int *, int *, void *, int *, int *, int *, int *);

void mpi_alltoall__(void *, int *, int *, void *, int *, int *, int *, int *);

void pmpi_alltoall_(void *, int *, int *, void *, int *, int *, int *, int *);

void pmpi_alltoall__(void *, int *, int *, void *, int *, int *, int *, int *);

void pmpi_alltoall_(void *, int *, int *, void *, int *, int *, int *, int *);

#define A_f_MPI_Alltoall _PMPI_Alltoall
#pragma weak mpi_alltoall_ = _PMPI_Alltoall
#pragma weak mpi_alltoall__ = _PMPI_Alltoall
#pragma weak pmpi_alltoall__ = _PMPI_Alltoall
extern long long WI4MPI_Alltoall_timeout;
void (*_LOCAL_MPI_Alltoall)(void *, int *, int *, void *, int *, int *, int *,
                            int *);

void A_f_MPI_Alltoall(void *sendbuf, int *sendcount, int *sendtype,
                      void *recvbuf, int *recvcount, int *recvtype, int *comm,
                      int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Alltoall\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Alltoall_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *sendbuf_tmp = sendbuf;
  int sendtype_tmp;
  void *recvbuf_tmp = recvbuf;
  int recvtype_tmp;
  int comm_tmp;
  buffer_a2r(&sendbuf, &sendbuf_tmp);
  datatype_a2r(sendtype, &sendtype_tmp);
  buffer_a2r(&recvbuf, &recvbuf_tmp);
  datatype_a2r(recvtype, &recvtype_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Alltoall(sendbuf_tmp, sendcount, &sendtype_tmp, recvbuf_tmp,
                      recvcount, &recvtype_tmp, &comm_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&recvbuf, &recvbuf_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Alltoall\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_alltoallv_(void *, int *, int *, int *, void *, int *, int *, int *,
                    int *, int *);

void mpi_alltoallv__(void *, int *, int *, int *, void *, int *, int *, int *,
                     int *, int *);

void pmpi_alltoallv_(void *, int *, int *, int *, void *, int *, int *, int *,
                     int *, int *);

void pmpi_alltoallv__(void *, int *, int *, int *, void *, int *, int *, int *,
                      int *, int *);

void pmpi_alltoallv_(void *, int *, int *, int *, void *, int *, int *, int *,
                     int *, int *);

#define A_f_MPI_Alltoallv _PMPI_Alltoallv
#pragma weak mpi_alltoallv_ = _PMPI_Alltoallv
#pragma weak mpi_alltoallv__ = _PMPI_Alltoallv
#pragma weak pmpi_alltoallv__ = _PMPI_Alltoallv
extern long long WI4MPI_Alltoallv_timeout;
void (*_LOCAL_MPI_Alltoallv)(void *, int *, int *, int *, void *, int *, int *,
                             int *, int *, int *);

void A_f_MPI_Alltoallv(void *sendbuf, int *sendcounts, int *sdispls,
                       int *sendtype, void *recvbuf, int *recvcounts,
                       int *rdispls, int *recvtype, int *comm, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Alltoallv\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Alltoallv_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *sendbuf_tmp = sendbuf;
  int sendtype_tmp;
  void *recvbuf_tmp = recvbuf;
  int recvtype_tmp;
  int comm_tmp;
  buffer_a2r(&sendbuf, &sendbuf_tmp);
  datatype_a2r(sendtype, &sendtype_tmp);
  buffer_a2r(&recvbuf, &recvbuf_tmp);
  datatype_a2r(recvtype, &recvtype_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Alltoallv(sendbuf_tmp, sendcounts, sdispls, &sendtype_tmp,
                       recvbuf_tmp, recvcounts, rdispls, &recvtype_tmp,
                       &comm_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&recvbuf, &recvbuf_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Alltoallv\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_exscan_(void *, void *, int *, int *, int *, int *, int *);

void mpi_exscan__(void *, void *, int *, int *, int *, int *, int *);

void pmpi_exscan_(void *, void *, int *, int *, int *, int *, int *);

void pmpi_exscan__(void *, void *, int *, int *, int *, int *, int *);

void pmpi_exscan_(void *, void *, int *, int *, int *, int *, int *);

#define A_f_MPI_Exscan _PMPI_Exscan
#pragma weak mpi_exscan_ = _PMPI_Exscan
#pragma weak mpi_exscan__ = _PMPI_Exscan
#pragma weak pmpi_exscan__ = _PMPI_Exscan
extern long long WI4MPI_Exscan_timeout;
void (*_LOCAL_MPI_Exscan)(void *, void *, int *, int *, int *, int *, int *);

void A_f_MPI_Exscan(void *sendbuf, void *recvbuf, int *count, int *datatype,
                    int *op, int *comm, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Exscan\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Exscan_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *sendbuf_tmp = sendbuf;
  void *recvbuf_tmp = recvbuf;
  int datatype_tmp;
  int op_tmp;
  int comm_tmp;
  buffer_a2r(&sendbuf, &sendbuf_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  operator_a2r(op, &op_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Exscan(sendbuf_tmp, recvbuf_tmp, count, &datatype_tmp, &op_tmp,
                    &comm_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&recvbuf, &recvbuf_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Exscan\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_reduce_(void *, void *, int *, int *, int *, int *, int *, int *);

void mpi_reduce__(void *, void *, int *, int *, int *, int *, int *, int *);

void pmpi_reduce_(void *, void *, int *, int *, int *, int *, int *, int *);

void pmpi_reduce__(void *, void *, int *, int *, int *, int *, int *, int *);

void pmpi_reduce_(void *, void *, int *, int *, int *, int *, int *, int *);

#define A_f_MPI_Reduce _PMPI_Reduce
#pragma weak mpi_reduce_ = _PMPI_Reduce
#pragma weak mpi_reduce__ = _PMPI_Reduce
#pragma weak pmpi_reduce__ = _PMPI_Reduce
extern long long WI4MPI_Reduce_timeout;
void (*_LOCAL_MPI_Reduce)(void *, void *, int *, int *, int *, int *, int *,
                          int *);

void A_f_MPI_Reduce(void *sendbuf, void *recvbuf, int *count, int *datatype,
                    int *op, int *root, int *comm, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Reduce\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Reduce_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *sendbuf_tmp = sendbuf;
  void *recvbuf_tmp = recvbuf;
  int datatype_tmp;
  int op_tmp;
  int comm_tmp;
  buffer_a2r(&sendbuf, &sendbuf_tmp);
  buffer_a2r(&recvbuf, &recvbuf_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  operator_a2r(op, &op_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Reduce(sendbuf_tmp, recvbuf_tmp, count, &datatype_tmp, &op_tmp,
                    root, &comm_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&recvbuf, &recvbuf_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Reduce\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_op_create_(void *, int *, int *, int *);

void mpi_op_create__(void *, int *, int *, int *);

void pmpi_op_create_(void *, int *, int *, int *);

void pmpi_op_create__(void *, int *, int *, int *);

void pmpi_op_create_(void *, int *, int *, int *);

#define A_f_MPI_Op_create _PMPI_Op_create
#pragma weak mpi_op_create_ = _PMPI_Op_create
#pragma weak mpi_op_create__ = _PMPI_Op_create
#pragma weak pmpi_op_create__ = _PMPI_Op_create
extern long long WI4MPI_Op_create_timeout;
void (*_LOCAL_MPI_Op_create)(void *, int *, int *, int *);

void A_f_MPI_Op_create(void *user_fn, int *commute, int *op, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Op_create\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Op_create_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *user_fn_tmp = user_fn;
  int op_tmp;
  user_fct_ptr_conv_a2r(&user_fn, &user_fn_tmp);
  _LOCAL_MPI_Op_create(user_fn_tmp, commute, &op_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    operator_r2a(op, &op_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Op_create\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_op_free_(int *, int *);

void mpi_op_free__(int *, int *);

void pmpi_op_free_(int *, int *);

void pmpi_op_free__(int *, int *);

void pmpi_op_free_(int *, int *);

#define A_f_MPI_Op_free _PMPI_Op_free
#pragma weak mpi_op_free_ = _PMPI_Op_free
#pragma weak mpi_op_free__ = _PMPI_Op_free
#pragma weak pmpi_op_free__ = _PMPI_Op_free
extern long long WI4MPI_Op_free_timeout;
void (*_LOCAL_MPI_Op_free)(int *, int *);

void A_f_MPI_Op_free(int *op, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Op_free\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Op_free_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int op_tmp;
  operator_del_a2r(op, &op_tmp);
  _LOCAL_MPI_Op_free(&op_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    operator_del_r2a(op, &op_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Op_free\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_allreduce_(void *, void *, int *, int *, int *, int *, int *);

void mpi_allreduce__(void *, void *, int *, int *, int *, int *, int *);

void pmpi_allreduce_(void *, void *, int *, int *, int *, int *, int *);

void pmpi_allreduce__(void *, void *, int *, int *, int *, int *, int *);

void pmpi_allreduce_(void *, void *, int *, int *, int *, int *, int *);

#define A_f_MPI_Allreduce _PMPI_Allreduce
#pragma weak mpi_allreduce_ = _PMPI_Allreduce
#pragma weak mpi_allreduce__ = _PMPI_Allreduce
#pragma weak pmpi_allreduce__ = _PMPI_Allreduce
extern long long WI4MPI_Allreduce_timeout;
void (*_LOCAL_MPI_Allreduce)(void *, void *, int *, int *, int *, int *, int *);

void A_f_MPI_Allreduce(void *sendbuf, void *recvbuf, int *count, int *datatype,
                       int *op, int *comm, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Allreduce\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Allreduce_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *sendbuf_tmp = sendbuf;
  void *recvbuf_tmp = recvbuf;
  int datatype_tmp;
  int op_tmp;
  int comm_tmp;
  buffer_a2r(&sendbuf, &sendbuf_tmp);
  buffer_a2r(&recvbuf, &recvbuf_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  operator_a2r(op, &op_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Allreduce(sendbuf_tmp, recvbuf_tmp, count, &datatype_tmp, &op_tmp,
                       &comm_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&recvbuf, &recvbuf_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Allreduce\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_scan_(void *, void *, int *, int *, int *, int *, int *);

void mpi_scan__(void *, void *, int *, int *, int *, int *, int *);

void pmpi_scan_(void *, void *, int *, int *, int *, int *, int *);

void pmpi_scan__(void *, void *, int *, int *, int *, int *, int *);

void pmpi_scan_(void *, void *, int *, int *, int *, int *, int *);

#define A_f_MPI_Scan _PMPI_Scan
#pragma weak mpi_scan_ = _PMPI_Scan
#pragma weak mpi_scan__ = _PMPI_Scan
#pragma weak pmpi_scan__ = _PMPI_Scan
extern long long WI4MPI_Scan_timeout;
void (*_LOCAL_MPI_Scan)(void *, void *, int *, int *, int *, int *, int *);

void A_f_MPI_Scan(void *sendbuf, void *recvbuf, int *count, int *datatype,
                  int *op, int *comm, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Scan\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Scan_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *sendbuf_tmp = sendbuf;
  void *recvbuf_tmp = recvbuf;
  int datatype_tmp;
  int op_tmp;
  int comm_tmp;
  buffer_a2r(&sendbuf, &sendbuf_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  operator_a2r(op, &op_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Scan(sendbuf_tmp, recvbuf_tmp, count, &datatype_tmp, &op_tmp,
                  &comm_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&recvbuf, &recvbuf_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Scan\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_group_size_(int *, int *, int *);

void mpi_group_size__(int *, int *, int *);

void pmpi_group_size_(int *, int *, int *);

void pmpi_group_size__(int *, int *, int *);

void pmpi_group_size_(int *, int *, int *);

#define A_f_MPI_Group_size _PMPI_Group_size
#pragma weak mpi_group_size_ = _PMPI_Group_size
#pragma weak mpi_group_size__ = _PMPI_Group_size
#pragma weak pmpi_group_size__ = _PMPI_Group_size
extern long long WI4MPI_Group_size_timeout;
void (*_LOCAL_MPI_Group_size)(int *, int *, int *);

void A_f_MPI_Group_size(int *group, int *size, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Group_size\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Group_size_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int group_tmp;
  group_a2r(group, &group_tmp);
  _LOCAL_MPI_Group_size(&group_tmp, size, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Group_size\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_group_rank_(int *, int *, int *);

void mpi_group_rank__(int *, int *, int *);

void pmpi_group_rank_(int *, int *, int *);

void pmpi_group_rank__(int *, int *, int *);

void pmpi_group_rank_(int *, int *, int *);

#define A_f_MPI_Group_rank _PMPI_Group_rank
#pragma weak mpi_group_rank_ = _PMPI_Group_rank
#pragma weak mpi_group_rank__ = _PMPI_Group_rank
#pragma weak pmpi_group_rank__ = _PMPI_Group_rank
extern long long WI4MPI_Group_rank_timeout;
void (*_LOCAL_MPI_Group_rank)(int *, int *, int *);

void A_f_MPI_Group_rank(int *group, int *rank, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Group_rank\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Group_rank_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int group_tmp;
  group_a2r(group, &group_tmp);
  _LOCAL_MPI_Group_rank(&group_tmp, rank, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Group_rank\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_group_compare_(int *, int *, int *, int *);

void mpi_group_compare__(int *, int *, int *, int *);

void pmpi_group_compare_(int *, int *, int *, int *);

void pmpi_group_compare__(int *, int *, int *, int *);

void pmpi_group_compare_(int *, int *, int *, int *);

#define A_f_MPI_Group_compare _PMPI_Group_compare
#pragma weak mpi_group_compare_ = _PMPI_Group_compare
#pragma weak mpi_group_compare__ = _PMPI_Group_compare
#pragma weak pmpi_group_compare__ = _PMPI_Group_compare
extern long long WI4MPI_Group_compare_timeout;
void (*_LOCAL_MPI_Group_compare)(int *, int *, int *, int *);

void A_f_MPI_Group_compare(int *group1, int *group2, int *result, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Group_compare\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Group_compare_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int group1_tmp;
  int group2_tmp;
  group_a2r(group1, &group1_tmp);
  group_a2r(group2, &group2_tmp);
  _LOCAL_MPI_Group_compare(&group1_tmp, &group2_tmp, result, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Group_compare\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_comm_group_(int *, int *, int *);

void mpi_comm_group__(int *, int *, int *);

void pmpi_comm_group_(int *, int *, int *);

void pmpi_comm_group__(int *, int *, int *);

void pmpi_comm_group_(int *, int *, int *);

#define A_f_MPI_Comm_group _PMPI_Comm_group
#pragma weak mpi_comm_group_ = _PMPI_Comm_group
#pragma weak mpi_comm_group__ = _PMPI_Comm_group
#pragma weak pmpi_comm_group__ = _PMPI_Comm_group
extern long long WI4MPI_Comm_group_timeout;
void (*_LOCAL_MPI_Comm_group)(int *, int *, int *);

void A_f_MPI_Comm_group(int *comm, int *group, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Comm_group\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Comm_group_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  int group_tmp;
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Comm_group(&comm_tmp, &group_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    group_r2a(group, &group_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Comm_group\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_group_union_(int *, int *, int *, int *);

void mpi_group_union__(int *, int *, int *, int *);

void pmpi_group_union_(int *, int *, int *, int *);

void pmpi_group_union__(int *, int *, int *, int *);

void pmpi_group_union_(int *, int *, int *, int *);

#define A_f_MPI_Group_union _PMPI_Group_union
#pragma weak mpi_group_union_ = _PMPI_Group_union
#pragma weak mpi_group_union__ = _PMPI_Group_union
#pragma weak pmpi_group_union__ = _PMPI_Group_union
extern long long WI4MPI_Group_union_timeout;
void (*_LOCAL_MPI_Group_union)(int *, int *, int *, int *);

void A_f_MPI_Group_union(int *group1, int *group2, int *newgroup, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Group_union\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Group_union_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int group1_tmp;
  int group2_tmp;
  int newgroup_tmp;
  group_a2r(group1, &group1_tmp);
  group_a2r(group2, &group2_tmp);
  _LOCAL_MPI_Group_union(&group1_tmp, &group2_tmp, &newgroup_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    group_r2a(newgroup, &newgroup_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Group_union\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_group_intersection_(int *, int *, int *, int *);

void mpi_group_intersection__(int *, int *, int *, int *);

void pmpi_group_intersection_(int *, int *, int *, int *);

void pmpi_group_intersection__(int *, int *, int *, int *);

void pmpi_group_intersection_(int *, int *, int *, int *);

#define A_f_MPI_Group_intersection _PMPI_Group_intersection
#pragma weak mpi_group_intersection_ = _PMPI_Group_intersection
#pragma weak mpi_group_intersection__ = _PMPI_Group_intersection
#pragma weak pmpi_group_intersection__ = _PMPI_Group_intersection
extern long long WI4MPI_Group_intersection_timeout;
void (*_LOCAL_MPI_Group_intersection)(int *, int *, int *, int *);

void A_f_MPI_Group_intersection(int *group1, int *group2, int *newgroup,
                                int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Group_intersection\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Group_intersection_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int group1_tmp;
  int group2_tmp;
  int newgroup_tmp;
  group_a2r(group1, &group1_tmp);
  group_a2r(group2, &group2_tmp);
  _LOCAL_MPI_Group_intersection(&group1_tmp, &group2_tmp, &newgroup_tmp,
                                &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    group_r2a(newgroup, &newgroup_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Group_intersection\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_group_difference_(int *, int *, int *, int *);

void mpi_group_difference__(int *, int *, int *, int *);

void pmpi_group_difference_(int *, int *, int *, int *);

void pmpi_group_difference__(int *, int *, int *, int *);

void pmpi_group_difference_(int *, int *, int *, int *);

#define A_f_MPI_Group_difference _PMPI_Group_difference
#pragma weak mpi_group_difference_ = _PMPI_Group_difference
#pragma weak mpi_group_difference__ = _PMPI_Group_difference
#pragma weak pmpi_group_difference__ = _PMPI_Group_difference
extern long long WI4MPI_Group_difference_timeout;
void (*_LOCAL_MPI_Group_difference)(int *, int *, int *, int *);

void A_f_MPI_Group_difference(int *group1, int *group2, int *newgroup,
                              int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Group_difference\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Group_difference_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int group1_tmp;
  int group2_tmp;
  int newgroup_tmp;
  group_a2r(group1, &group1_tmp);
  group_a2r(group2, &group2_tmp);
  _LOCAL_MPI_Group_difference(&group1_tmp, &group2_tmp, &newgroup_tmp,
                              &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    group_r2a(newgroup, &newgroup_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Group_difference\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_group_free_(int *, int *);

void mpi_group_free__(int *, int *);

void pmpi_group_free_(int *, int *);

void pmpi_group_free__(int *, int *);

void pmpi_group_free_(int *, int *);

#define A_f_MPI_Group_free _PMPI_Group_free
#pragma weak mpi_group_free_ = _PMPI_Group_free
#pragma weak mpi_group_free__ = _PMPI_Group_free
#pragma weak pmpi_group_free__ = _PMPI_Group_free
extern long long WI4MPI_Group_free_timeout;
void (*_LOCAL_MPI_Group_free)(int *, int *);

void A_f_MPI_Group_free(int *group, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Group_free\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Group_free_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int group_tmp;
  group_a2r(group, &group_tmp);
  _LOCAL_MPI_Group_free(&group_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    group_r2a(group, &group_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Group_free\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_comm_size_(int *, int *, int *);

void mpi_comm_size__(int *, int *, int *);

void pmpi_comm_size_(int *, int *, int *);

void pmpi_comm_size__(int *, int *, int *);

void pmpi_comm_size_(int *, int *, int *);

#define A_f_MPI_Comm_size _PMPI_Comm_size
#pragma weak mpi_comm_size_ = _PMPI_Comm_size
#pragma weak mpi_comm_size__ = _PMPI_Comm_size
#pragma weak pmpi_comm_size__ = _PMPI_Comm_size
extern long long WI4MPI_Comm_size_timeout;
void (*_LOCAL_MPI_Comm_size)(int *, int *, int *);

void A_f_MPI_Comm_size(int *comm, int *size, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Comm_size\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Comm_size_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Comm_size(&comm_tmp, size, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Comm_size\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_comm_rank_(int *, int *, int *);

void mpi_comm_rank__(int *, int *, int *);

void pmpi_comm_rank_(int *, int *, int *);

void pmpi_comm_rank__(int *, int *, int *);

void pmpi_comm_rank_(int *, int *, int *);

#define A_f_MPI_Comm_rank _PMPI_Comm_rank
#pragma weak mpi_comm_rank_ = _PMPI_Comm_rank
#pragma weak mpi_comm_rank__ = _PMPI_Comm_rank
#pragma weak pmpi_comm_rank__ = _PMPI_Comm_rank
extern long long WI4MPI_Comm_rank_timeout;
void (*_LOCAL_MPI_Comm_rank)(int *, int *, int *);

void A_f_MPI_Comm_rank(int *comm, int *rank, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Comm_rank\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Comm_rank_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Comm_rank(&comm_tmp, rank, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Comm_rank\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_comm_compare_(int *, int *, int *, int *);

void mpi_comm_compare__(int *, int *, int *, int *);

void pmpi_comm_compare_(int *, int *, int *, int *);

void pmpi_comm_compare__(int *, int *, int *, int *);

void pmpi_comm_compare_(int *, int *, int *, int *);

#define A_f_MPI_Comm_compare _PMPI_Comm_compare
#pragma weak mpi_comm_compare_ = _PMPI_Comm_compare
#pragma weak mpi_comm_compare__ = _PMPI_Comm_compare
#pragma weak pmpi_comm_compare__ = _PMPI_Comm_compare
extern long long WI4MPI_Comm_compare_timeout;
void (*_LOCAL_MPI_Comm_compare)(int *, int *, int *, int *);

void A_f_MPI_Comm_compare(int *comm1, int *comm2, int *result, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Comm_compare\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Comm_compare_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm1_tmp;
  int comm2_tmp;
  comm_a2r(comm1, &comm1_tmp);
  comm_a2r(comm2, &comm2_tmp);
  _LOCAL_MPI_Comm_compare(&comm1_tmp, &comm2_tmp, result, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Comm_compare\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_comm_dup_(int *, int *, int *);

void mpi_comm_dup__(int *, int *, int *);

void pmpi_comm_dup_(int *, int *, int *);

void pmpi_comm_dup__(int *, int *, int *);

void pmpi_comm_dup_(int *, int *, int *);

#define A_f_MPI_Comm_dup _PMPI_Comm_dup
#pragma weak mpi_comm_dup_ = _PMPI_Comm_dup
#pragma weak mpi_comm_dup__ = _PMPI_Comm_dup
#pragma weak pmpi_comm_dup__ = _PMPI_Comm_dup
extern long long WI4MPI_Comm_dup_timeout;
void (*_LOCAL_MPI_Comm_dup)(int *, int *, int *);

void A_f_MPI_Comm_dup(int *comm, int *newcomm, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Comm_dup\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Comm_dup_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  int newcomm_tmp;
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Comm_dup(&comm_tmp, &newcomm_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    comm_r2a(newcomm, &newcomm_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Comm_dup\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_comm_dup_with_info_(int *, int *, int *, int *);

void mpi_comm_dup_with_info__(int *, int *, int *, int *);

void pmpi_comm_dup_with_info_(int *, int *, int *, int *);

void pmpi_comm_dup_with_info__(int *, int *, int *, int *);

void pmpi_comm_dup_with_info_(int *, int *, int *, int *);

#define A_f_MPI_Comm_dup_with_info _PMPI_Comm_dup_with_info
#pragma weak mpi_comm_dup_with_info_ = _PMPI_Comm_dup_with_info
#pragma weak mpi_comm_dup_with_info__ = _PMPI_Comm_dup_with_info
#pragma weak pmpi_comm_dup_with_info__ = _PMPI_Comm_dup_with_info
extern long long WI4MPI_Comm_dup_with_info_timeout;
void (*_LOCAL_MPI_Comm_dup_with_info)(int *, int *, int *, int *);

void A_f_MPI_Comm_dup_with_info(int *comm, int *info, int *newcomm, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Comm_dup_with_info\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Comm_dup_with_info_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  int info_tmp;
  int newcomm_tmp;
  comm_a2r(comm, &comm_tmp);
  info_a2r(info, &info_tmp);
  _LOCAL_MPI_Comm_dup_with_info(&comm_tmp, &info_tmp, &newcomm_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    comm_r2a(newcomm, &newcomm_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Comm_dup_with_info\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_comm_create_(int *, int *, int *, int *);

void mpi_comm_create__(int *, int *, int *, int *);

void pmpi_comm_create_(int *, int *, int *, int *);

void pmpi_comm_create__(int *, int *, int *, int *);

void pmpi_comm_create_(int *, int *, int *, int *);

#define A_f_MPI_Comm_create _PMPI_Comm_create
#pragma weak mpi_comm_create_ = _PMPI_Comm_create
#pragma weak mpi_comm_create__ = _PMPI_Comm_create
#pragma weak pmpi_comm_create__ = _PMPI_Comm_create
extern long long WI4MPI_Comm_create_timeout;
void (*_LOCAL_MPI_Comm_create)(int *, int *, int *, int *);

void A_f_MPI_Comm_create(int *comm, int *group, int *newcomm, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Comm_create\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Comm_create_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  int group_tmp;
  int newcomm_tmp;
  comm_a2r(comm, &comm_tmp);
  group_a2r(group, &group_tmp);
  _LOCAL_MPI_Comm_create(&comm_tmp, &group_tmp, &newcomm_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    comm_r2a(newcomm, &newcomm_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Comm_create\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_comm_split_(int *, int *, int *, int *, int *);

void mpi_comm_split__(int *, int *, int *, int *, int *);

void pmpi_comm_split_(int *, int *, int *, int *, int *);

void pmpi_comm_split__(int *, int *, int *, int *, int *);

void pmpi_comm_split_(int *, int *, int *, int *, int *);

#define A_f_MPI_Comm_split _PMPI_Comm_split
#pragma weak mpi_comm_split_ = _PMPI_Comm_split
#pragma weak mpi_comm_split__ = _PMPI_Comm_split
#pragma weak pmpi_comm_split__ = _PMPI_Comm_split
extern long long WI4MPI_Comm_split_timeout;
void (*_LOCAL_MPI_Comm_split)(int *, int *, int *, int *, int *);

void A_f_MPI_Comm_split(int *comm, int *color, int *key, int *newcomm,
                        int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Comm_split\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Comm_split_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  int newcomm_tmp;
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Comm_split(&comm_tmp, color, key, &newcomm_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    comm_r2a(newcomm, &newcomm_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Comm_split\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_comm_free_(int *, int *);

void mpi_comm_free__(int *, int *);

void pmpi_comm_free_(int *, int *);

void pmpi_comm_free__(int *, int *);

void pmpi_comm_free_(int *, int *);

#define A_f_MPI_Comm_free _PMPI_Comm_free
#pragma weak mpi_comm_free_ = _PMPI_Comm_free
#pragma weak mpi_comm_free__ = _PMPI_Comm_free
#pragma weak pmpi_comm_free__ = _PMPI_Comm_free
extern long long WI4MPI_Comm_free_timeout;
void (*_LOCAL_MPI_Comm_free)(int *, int *);

void A_f_MPI_Comm_free(int *comm, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Comm_free\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Comm_free_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Comm_free(&comm_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    comm_r2a(comm, &comm_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Comm_free\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_comm_test_inter_(int *, int *, int *);

void mpi_comm_test_inter__(int *, int *, int *);

void pmpi_comm_test_inter_(int *, int *, int *);

void pmpi_comm_test_inter__(int *, int *, int *);

void pmpi_comm_test_inter_(int *, int *, int *);

#define A_f_MPI_Comm_test_inter _PMPI_Comm_test_inter
#pragma weak mpi_comm_test_inter_ = _PMPI_Comm_test_inter
#pragma weak mpi_comm_test_inter__ = _PMPI_Comm_test_inter
#pragma weak pmpi_comm_test_inter__ = _PMPI_Comm_test_inter
extern long long WI4MPI_Comm_test_inter_timeout;
void (*_LOCAL_MPI_Comm_test_inter)(int *, int *, int *);

void A_f_MPI_Comm_test_inter(int *comm, int *flag, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Comm_test_inter\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Comm_test_inter_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Comm_test_inter(&comm_tmp, flag, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Comm_test_inter\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_comm_remote_size_(int *, int *, int *);

void mpi_comm_remote_size__(int *, int *, int *);

void pmpi_comm_remote_size_(int *, int *, int *);

void pmpi_comm_remote_size__(int *, int *, int *);

void pmpi_comm_remote_size_(int *, int *, int *);

#define A_f_MPI_Comm_remote_size _PMPI_Comm_remote_size
#pragma weak mpi_comm_remote_size_ = _PMPI_Comm_remote_size
#pragma weak mpi_comm_remote_size__ = _PMPI_Comm_remote_size
#pragma weak pmpi_comm_remote_size__ = _PMPI_Comm_remote_size
extern long long WI4MPI_Comm_remote_size_timeout;
void (*_LOCAL_MPI_Comm_remote_size)(int *, int *, int *);

void A_f_MPI_Comm_remote_size(int *comm, int *size, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Comm_remote_size\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Comm_remote_size_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Comm_remote_size(&comm_tmp, size, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Comm_remote_size\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_comm_remote_group_(int *, int *, int *);

void mpi_comm_remote_group__(int *, int *, int *);

void pmpi_comm_remote_group_(int *, int *, int *);

void pmpi_comm_remote_group__(int *, int *, int *);

void pmpi_comm_remote_group_(int *, int *, int *);

#define A_f_MPI_Comm_remote_group _PMPI_Comm_remote_group
#pragma weak mpi_comm_remote_group_ = _PMPI_Comm_remote_group
#pragma weak mpi_comm_remote_group__ = _PMPI_Comm_remote_group
#pragma weak pmpi_comm_remote_group__ = _PMPI_Comm_remote_group
extern long long WI4MPI_Comm_remote_group_timeout;
void (*_LOCAL_MPI_Comm_remote_group)(int *, int *, int *);

void A_f_MPI_Comm_remote_group(int *comm, int *group, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Comm_remote_group\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Comm_remote_group_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  int group_tmp;
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Comm_remote_group(&comm_tmp, &group_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    group_r2a(group, &group_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Comm_remote_group\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_intercomm_create_(int *, int *, int *, int *, int *, int *, int *);

void mpi_intercomm_create__(int *, int *, int *, int *, int *, int *, int *);

void pmpi_intercomm_create_(int *, int *, int *, int *, int *, int *, int *);

void pmpi_intercomm_create__(int *, int *, int *, int *, int *, int *, int *);

void pmpi_intercomm_create_(int *, int *, int *, int *, int *, int *, int *);

#define A_f_MPI_Intercomm_create _PMPI_Intercomm_create
#pragma weak mpi_intercomm_create_ = _PMPI_Intercomm_create
#pragma weak mpi_intercomm_create__ = _PMPI_Intercomm_create
#pragma weak pmpi_intercomm_create__ = _PMPI_Intercomm_create
extern long long WI4MPI_Intercomm_create_timeout;
void (*_LOCAL_MPI_Intercomm_create)(int *, int *, int *, int *, int *, int *,
                                    int *);

void A_f_MPI_Intercomm_create(int *local_comm, int *local_leader,
                              int *peer_comm, int *remote_leader, int *tag,
                              int *newintercomm, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Intercomm_create\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Intercomm_create_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int local_comm_tmp;
  int peer_comm_tmp;
  int tag_tmp;
  int newintercomm_tmp;
  comm_a2r(local_comm, &local_comm_tmp);
  comm_a2r(peer_comm, &peer_comm_tmp);
  tag_a2r(tag, &tag_tmp);
  _LOCAL_MPI_Intercomm_create(&local_comm_tmp, local_leader, &peer_comm_tmp,
                              remote_leader, &tag_tmp, &newintercomm_tmp,
                              &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    comm_r2a(newintercomm, &newintercomm_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Intercomm_create\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_intercomm_merge_(int *, int *, int *, int *);

void mpi_intercomm_merge__(int *, int *, int *, int *);

void pmpi_intercomm_merge_(int *, int *, int *, int *);

void pmpi_intercomm_merge__(int *, int *, int *, int *);

void pmpi_intercomm_merge_(int *, int *, int *, int *);

#define A_f_MPI_Intercomm_merge _PMPI_Intercomm_merge
#pragma weak mpi_intercomm_merge_ = _PMPI_Intercomm_merge
#pragma weak mpi_intercomm_merge__ = _PMPI_Intercomm_merge
#pragma weak pmpi_intercomm_merge__ = _PMPI_Intercomm_merge
extern long long WI4MPI_Intercomm_merge_timeout;
void (*_LOCAL_MPI_Intercomm_merge)(int *, int *, int *, int *);

void A_f_MPI_Intercomm_merge(int *intercomm, int *high, int *newintracomm,
                             int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Intercomm_merge\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Intercomm_merge_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int intercomm_tmp;
  int newintracomm_tmp;
  comm_a2r(intercomm, &intercomm_tmp);
  _LOCAL_MPI_Intercomm_merge(&intercomm_tmp, high, &newintracomm_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    comm_r2a(newintracomm, &newintracomm_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Intercomm_merge\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_keyval_create_(void *, void *, int *, void *, int *);

void mpi_keyval_create__(void *, void *, int *, void *, int *);

void pmpi_keyval_create_(void *, void *, int *, void *, int *);

void pmpi_keyval_create__(void *, void *, int *, void *, int *);

void pmpi_keyval_create_(void *, void *, int *, void *, int *);

#define A_f_MPI_Keyval_create _PMPI_Keyval_create
#pragma weak mpi_keyval_create_ = _PMPI_Keyval_create
#pragma weak mpi_keyval_create__ = _PMPI_Keyval_create
#pragma weak pmpi_keyval_create__ = _PMPI_Keyval_create
extern long long WI4MPI_Keyval_create_timeout;
void (*_LOCAL_MPI_Keyval_create)(void *, void *, int *, void *, int *);

void A_f_MPI_Keyval_create(void *copy_fn, void *delete_fn, int *keyval,
                           void *extra_state, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Keyval_create\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Keyval_create_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *copy_fn_tmp = copy_fn;
  void *delete_fn_tmp = delete_fn;
  void *extra_state_tmp = extra_state;
  copy_ptr_converter_a2r(&copy_fn, &copy_fn_tmp);
  delete_ptr_converter_a2r(&delete_fn, &delete_fn_tmp);
  buffer_a2r(&extra_state, &extra_state_tmp);
  _LOCAL_MPI_Keyval_create(copy_fn_tmp, delete_fn_tmp, keyval, extra_state_tmp,
                           &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Keyval_create\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_keyval_free_(int *, int *);

void mpi_keyval_free__(int *, int *);

void pmpi_keyval_free_(int *, int *);

void pmpi_keyval_free__(int *, int *);

void pmpi_keyval_free_(int *, int *);

#define A_f_MPI_Keyval_free _PMPI_Keyval_free
#pragma weak mpi_keyval_free_ = _PMPI_Keyval_free
#pragma weak mpi_keyval_free__ = _PMPI_Keyval_free
#pragma weak pmpi_keyval_free__ = _PMPI_Keyval_free
extern long long WI4MPI_Keyval_free_timeout;
void (*_LOCAL_MPI_Keyval_free)(int *, int *);

void A_f_MPI_Keyval_free(int *keyval, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Keyval_free\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Keyval_free_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_Keyval_free(keyval, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS) {
    *keyval = A_MPI_KEYVAL_INVALID;
  }

  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Keyval_free\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_attr_put_(int *, int *, int *, int *);

void mpi_attr_put__(int *, int *, int *, int *);

void pmpi_attr_put_(int *, int *, int *, int *);

void pmpi_attr_put__(int *, int *, int *, int *);

void pmpi_attr_put_(int *, int *, int *, int *);

#define A_f_MPI_Attr_put _PMPI_Attr_put
#pragma weak mpi_attr_put_ = _PMPI_Attr_put
#pragma weak mpi_attr_put__ = _PMPI_Attr_put
#pragma weak pmpi_attr_put__ = _PMPI_Attr_put
extern long long WI4MPI_Attr_put_timeout;
void (*_LOCAL_MPI_Attr_put)(int *, int *, int *, int *);

void A_f_MPI_Attr_put(int *comm, int *keyval, int *attribute_val, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Attr_put\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Attr_put_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Attr_put(&comm_tmp, keyval, attribute_val, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Attr_put\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_attr_get_(int *, int *, int *, int *, int *);

void mpi_attr_get__(int *, int *, int *, int *, int *);

void pmpi_attr_get_(int *, int *, int *, int *, int *);

void pmpi_attr_get__(int *, int *, int *, int *, int *);

void pmpi_attr_get_(int *, int *, int *, int *, int *);

#define A_f_MPI_Attr_get _PMPI_Attr_get
#pragma weak mpi_attr_get_ = _PMPI_Attr_get
#pragma weak mpi_attr_get__ = _PMPI_Attr_get
#pragma weak pmpi_attr_get__ = _PMPI_Attr_get
extern long long WI4MPI_Attr_get_timeout;
void (*_LOCAL_MPI_Attr_get)(int *, int *, int *, int *, int *);

void A_f_MPI_Attr_get(int *comm, int *keyval, int *attribute_val, int *flag,
                      int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Attr_get\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Attr_get_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  int keyval_tmp;
  comm_a2r(comm, &comm_tmp);
  keyval_a2r(keyval, &keyval_tmp);
  _LOCAL_MPI_Attr_get(&comm_tmp, &keyval_tmp, attribute_val, flag, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Attr_get\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_attr_delete_(int *, int *, int *);

void mpi_attr_delete__(int *, int *, int *);

void pmpi_attr_delete_(int *, int *, int *);

void pmpi_attr_delete__(int *, int *, int *);

void pmpi_attr_delete_(int *, int *, int *);

#define A_f_MPI_Attr_delete _PMPI_Attr_delete
#pragma weak mpi_attr_delete_ = _PMPI_Attr_delete
#pragma weak mpi_attr_delete__ = _PMPI_Attr_delete
#pragma weak pmpi_attr_delete__ = _PMPI_Attr_delete
extern long long WI4MPI_Attr_delete_timeout;
void (*_LOCAL_MPI_Attr_delete)(int *, int *, int *);

void A_f_MPI_Attr_delete(int *comm, int *keyval, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Attr_delete\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Attr_delete_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  int keyval_tmp;
  comm_a2r(comm, &comm_tmp);
  keyval_a2r(keyval, &keyval_tmp);
  _LOCAL_MPI_Attr_delete(&comm_tmp, &keyval_tmp, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Attr_delete\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_topo_test_(int *, int *, int *);

void mpi_topo_test__(int *, int *, int *);

void pmpi_topo_test_(int *, int *, int *);

void pmpi_topo_test__(int *, int *, int *);

void pmpi_topo_test_(int *, int *, int *);

#define A_f_MPI_Topo_test _PMPI_Topo_test
#pragma weak mpi_topo_test_ = _PMPI_Topo_test
#pragma weak mpi_topo_test__ = _PMPI_Topo_test
#pragma weak pmpi_topo_test__ = _PMPI_Topo_test
extern long long WI4MPI_Topo_test_timeout;
void (*_LOCAL_MPI_Topo_test)(int *, int *, int *);

void A_f_MPI_Topo_test(int *comm, int *status, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Topo_test\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Topo_test_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  int status_tmp1[R_f_MPI_STATUS_SIZE + 1];
  int *status_tmp =
      (status == A_f_MPI_STATUS_IGNORE ? R_f_MPI_STATUS_IGNORE : status_tmp1);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Topo_test(&comm_tmp, status_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    if (status != A_f_MPI_STATUS_IGNORE)
      topo_status_r2a(status, status_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Topo_test\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_graphdims_get_(int *, int *, int *, int *);

void mpi_graphdims_get__(int *, int *, int *, int *);

void pmpi_graphdims_get_(int *, int *, int *, int *);

void pmpi_graphdims_get__(int *, int *, int *, int *);

void pmpi_graphdims_get_(int *, int *, int *, int *);

#define A_f_MPI_Graphdims_get _PMPI_Graphdims_get
#pragma weak mpi_graphdims_get_ = _PMPI_Graphdims_get
#pragma weak mpi_graphdims_get__ = _PMPI_Graphdims_get
#pragma weak pmpi_graphdims_get__ = _PMPI_Graphdims_get
extern long long WI4MPI_Graphdims_get_timeout;
void (*_LOCAL_MPI_Graphdims_get)(int *, int *, int *, int *);

void A_f_MPI_Graphdims_get(int *comm, int *nnodes, int *nedges, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Graphdims_get\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Graphdims_get_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Graphdims_get(&comm_tmp, nnodes, nedges, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Graphdims_get\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_cartdim_get_(int *, int *, int *);

void mpi_cartdim_get__(int *, int *, int *);

void pmpi_cartdim_get_(int *, int *, int *);

void pmpi_cartdim_get__(int *, int *, int *);

void pmpi_cartdim_get_(int *, int *, int *);

#define A_f_MPI_Cartdim_get _PMPI_Cartdim_get
#pragma weak mpi_cartdim_get_ = _PMPI_Cartdim_get
#pragma weak mpi_cartdim_get__ = _PMPI_Cartdim_get
#pragma weak pmpi_cartdim_get__ = _PMPI_Cartdim_get
extern long long WI4MPI_Cartdim_get_timeout;
void (*_LOCAL_MPI_Cartdim_get)(int *, int *, int *);

void A_f_MPI_Cartdim_get(int *comm, int *ndims, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Cartdim_get\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Cartdim_get_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Cartdim_get(&comm_tmp, ndims, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Cartdim_get\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_graph_neighbors_count_(int *, int *, int *, int *);

void mpi_graph_neighbors_count__(int *, int *, int *, int *);

void pmpi_graph_neighbors_count_(int *, int *, int *, int *);

void pmpi_graph_neighbors_count__(int *, int *, int *, int *);

void pmpi_graph_neighbors_count_(int *, int *, int *, int *);

#define A_f_MPI_Graph_neighbors_count _PMPI_Graph_neighbors_count
#pragma weak mpi_graph_neighbors_count_ = _PMPI_Graph_neighbors_count
#pragma weak mpi_graph_neighbors_count__ = _PMPI_Graph_neighbors_count
#pragma weak pmpi_graph_neighbors_count__ = _PMPI_Graph_neighbors_count
extern long long WI4MPI_Graph_neighbors_count_timeout;
void (*_LOCAL_MPI_Graph_neighbors_count)(int *, int *, int *, int *);

void A_f_MPI_Graph_neighbors_count(int *comm, int *rank, int *nneighbors,
                                   int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Graph_neighbors_count\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Graph_neighbors_count_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Graph_neighbors_count(&comm_tmp, rank, nneighbors, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Graph_neighbors_count\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_cart_shift_(int *, int *, int *, int *, int *, int *);

void mpi_cart_shift__(int *, int *, int *, int *, int *, int *);

void pmpi_cart_shift_(int *, int *, int *, int *, int *, int *);

void pmpi_cart_shift__(int *, int *, int *, int *, int *, int *);

void pmpi_cart_shift_(int *, int *, int *, int *, int *, int *);

#define A_f_MPI_Cart_shift _PMPI_Cart_shift
#pragma weak mpi_cart_shift_ = _PMPI_Cart_shift
#pragma weak mpi_cart_shift__ = _PMPI_Cart_shift
#pragma weak pmpi_cart_shift__ = _PMPI_Cart_shift
extern long long WI4MPI_Cart_shift_timeout;
void (*_LOCAL_MPI_Cart_shift)(int *, int *, int *, int *, int *, int *);

void A_f_MPI_Cart_shift(int *comm, int *direction, int *disp, int *rank_source,
                        int *rank_dest, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Cart_shift\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Cart_shift_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Cart_shift(&comm_tmp, direction, disp, rank_source, rank_dest,
                        &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Cart_shift\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_get_version_(int *, int *, int *);

void mpi_get_version__(int *, int *, int *);

void pmpi_get_version_(int *, int *, int *);

void pmpi_get_version__(int *, int *, int *);

void pmpi_get_version_(int *, int *, int *);

#define A_f_MPI_Get_version _PMPI_Get_version
#pragma weak mpi_get_version_ = _PMPI_Get_version
#pragma weak mpi_get_version__ = _PMPI_Get_version
#pragma weak pmpi_get_version__ = _PMPI_Get_version
extern long long WI4MPI_Get_version_timeout;
void (*_LOCAL_MPI_Get_version)(int *, int *, int *);

void A_f_MPI_Get_version(int *version, int *subversion, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Get_version\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Get_version_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_Get_version(version, subversion, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Get_version\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_errhandler_create_(void *, int *, int *);

void mpi_errhandler_create__(void *, int *, int *);

void pmpi_errhandler_create_(void *, int *, int *);

void pmpi_errhandler_create__(void *, int *, int *);

void pmpi_errhandler_create_(void *, int *, int *);

#define A_f_MPI_Errhandler_create _PMPI_Errhandler_create
#pragma weak mpi_errhandler_create_ = _PMPI_Errhandler_create
#pragma weak mpi_errhandler_create__ = _PMPI_Errhandler_create
#pragma weak pmpi_errhandler_create__ = _PMPI_Errhandler_create
extern long long WI4MPI_Errhandler_create_timeout;
void (*_LOCAL_MPI_Errhandler_create)(void *, int *, int *);

void A_f_MPI_Errhandler_create(void *function, int *errhandler, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Errhandler_create\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Errhandler_create_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *function_tmp = function;
  int errhandler_tmp;
  handler_fct_ptr_conv_a2r(&function, &function_tmp);
  _LOCAL_MPI_Errhandler_create(function_tmp, &errhandler_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    errhandler_converter_r2a(errhandler, &errhandler_tmp);
  errhandler_f_fn_translation_update(errhandler_tmp, function);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Errhandler_create\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_errhandler_set_(int *, int *, int *);

void mpi_errhandler_set__(int *, int *, int *);

void pmpi_errhandler_set_(int *, int *, int *);

void pmpi_errhandler_set__(int *, int *, int *);

void pmpi_errhandler_set_(int *, int *, int *);

#define A_f_MPI_Errhandler_set _PMPI_Errhandler_set
#pragma weak mpi_errhandler_set_ = _PMPI_Errhandler_set
#pragma weak mpi_errhandler_set__ = _PMPI_Errhandler_set
#pragma weak pmpi_errhandler_set__ = _PMPI_Errhandler_set
extern long long WI4MPI_Errhandler_set_timeout;
void (*_LOCAL_MPI_Errhandler_set)(int *, int *, int *);

void A_f_MPI_Errhandler_set(int *comm, int *errhandler, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Errhandler_set\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Errhandler_set_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  int errhandler_tmp;
  comm_a2r(comm, &comm_tmp);
  errhandler_converter_a2r(errhandler, &errhandler_tmp);
  _LOCAL_MPI_Errhandler_set(&comm_tmp, &errhandler_tmp, &ret_tmp);
  errhandler_set_func(comm_tmp, errhandler_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Errhandler_set\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_errhandler_get_(int *, int *, int *);

void mpi_errhandler_get__(int *, int *, int *);

void pmpi_errhandler_get_(int *, int *, int *);

void pmpi_errhandler_get__(int *, int *, int *);

void pmpi_errhandler_get_(int *, int *, int *);

#define A_f_MPI_Errhandler_get _PMPI_Errhandler_get
#pragma weak mpi_errhandler_get_ = _PMPI_Errhandler_get
#pragma weak mpi_errhandler_get__ = _PMPI_Errhandler_get
#pragma weak pmpi_errhandler_get__ = _PMPI_Errhandler_get
extern long long WI4MPI_Errhandler_get_timeout;
void (*_LOCAL_MPI_Errhandler_get)(int *, int *, int *);

void A_f_MPI_Errhandler_get(int *comm, int *errhandler, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Errhandler_get\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Errhandler_get_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  int errhandler_tmp;
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Errhandler_get(&comm_tmp, &errhandler_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    errhandler_converter_r2a(errhandler, &errhandler_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Errhandler_get\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_errhandler_free_(int *, int *);

void mpi_errhandler_free__(int *, int *);

void pmpi_errhandler_free_(int *, int *);

void pmpi_errhandler_free__(int *, int *);

void pmpi_errhandler_free_(int *, int *);

#define A_f_MPI_Errhandler_free _PMPI_Errhandler_free
#pragma weak mpi_errhandler_free_ = _PMPI_Errhandler_free
#pragma weak mpi_errhandler_free__ = _PMPI_Errhandler_free
#pragma weak pmpi_errhandler_free__ = _PMPI_Errhandler_free
extern long long WI4MPI_Errhandler_free_timeout;
void (*_LOCAL_MPI_Errhandler_free)(int *, int *);

void A_f_MPI_Errhandler_free(int *errhandler, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Errhandler_free\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Errhandler_free_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int errhandler_tmp;
  errhandler_converter_a2r(errhandler, &errhandler_tmp);
  errhandler_f_fn_translation_del(errhandler_tmp);
  _LOCAL_MPI_Errhandler_free(&errhandler_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS) {
    errhandler_f_fn_translation_del(errhandler_tmp);
    errhandler_converter_r2a(errhandler, &errhandler_tmp);
  }
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Errhandler_free\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_error_class_(int *, int *, int *);

void mpi_error_class__(int *, int *, int *);

void pmpi_error_class_(int *, int *, int *);

void pmpi_error_class__(int *, int *, int *);

void pmpi_error_class_(int *, int *, int *);

#define A_f_MPI_Error_class _PMPI_Error_class
#pragma weak mpi_error_class_ = _PMPI_Error_class
#pragma weak mpi_error_class__ = _PMPI_Error_class
#pragma weak pmpi_error_class__ = _PMPI_Error_class
extern long long WI4MPI_Error_class_timeout;
void (*_LOCAL_MPI_Error_class)(int *, int *, int *);

void A_f_MPI_Error_class(int *errorcode, int *errorclass, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Error_class\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Error_class_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int errorcode_tmp;
  int errorclass_tmp;
  error_a2r(errorcode, &errorcode_tmp);
  _LOCAL_MPI_Error_class(&errorcode_tmp, &errorclass_tmp, &ret_tmp);
  error_r2a(errorclass, &errorclass_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Error_class\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_initialized_(int *, int *);

void mpi_initialized__(int *, int *);

void pmpi_initialized_(int *, int *);

void pmpi_initialized__(int *, int *);

void pmpi_initialized_(int *, int *);

#define A_f_MPI_Initialized _PMPI_Initialized
#pragma weak mpi_initialized_ = _PMPI_Initialized
#pragma weak mpi_initialized__ = _PMPI_Initialized
#pragma weak pmpi_initialized__ = _PMPI_Initialized
extern long long WI4MPI_Initialized_timeout;
void (*_LOCAL_MPI_Initialized)(int *, int *);

void A_f_MPI_Initialized(int *flag, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Initialized\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Initialized_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_Initialized(flag, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Initialized\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_abort_(int *, int *, int *);

void mpi_abort__(int *, int *, int *);

void pmpi_abort_(int *, int *, int *);

void pmpi_abort__(int *, int *, int *);

void pmpi_abort_(int *, int *, int *);

#define A_f_MPI_Abort _PMPI_Abort
#pragma weak mpi_abort_ = _PMPI_Abort
#pragma weak mpi_abort__ = _PMPI_Abort
#pragma weak pmpi_abort__ = _PMPI_Abort
extern long long WI4MPI_Abort_timeout;
void (*_LOCAL_MPI_Abort)(int *, int *, int *);

void A_f_MPI_Abort(int *comm, int *errorcode, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Abort\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Abort_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  int errorcode_tmp;
  comm_a2r(comm, &comm_tmp);
  error_a2r(errorcode, &errorcode_tmp);
  _LOCAL_MPI_Abort(&comm_tmp, &errorcode_tmp, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Abort\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_init_(int *);

void mpi_init__(int *);

void pmpi_init_(int *);

void pmpi_init__(int *);

void pmpi_init_(int *);

#define A_f_MPI_Init _PMPI_Init
#pragma weak mpi_init_ = _PMPI_Init
#pragma weak mpi_init__ = _PMPI_Init
#pragma weak pmpi_init__ = _PMPI_Init
extern long long WI4MPI_Init_timeout;
void (*_LOCAL_MPI_Init)(int *);

void A_f_MPI_Init(int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Init\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Init_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_Init(&ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Init\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_comm_accept_(char *, int *, int *, int *, int *, int *);

void mpi_comm_accept__(char *, int *, int *, int *, int *, int *);

void pmpi_comm_accept_(char *, int *, int *, int *, int *, int *);

void pmpi_comm_accept__(char *, int *, int *, int *, int *, int *);

void pmpi_comm_accept_(char *, int *, int *, int *, int *, int *);

#define A_f_MPI_Comm_accept _PMPI_Comm_accept
#pragma weak mpi_comm_accept_ = _PMPI_Comm_accept
#pragma weak mpi_comm_accept__ = _PMPI_Comm_accept
#pragma weak pmpi_comm_accept__ = _PMPI_Comm_accept
extern long long WI4MPI_Comm_accept_timeout;
void (*_LOCAL_MPI_Comm_accept)(char *, int *, int *, int *, int *, int *);

void A_f_MPI_Comm_accept(char *port_name, int *info, int *root, int *comm,
                         int *newcomm, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Comm_accept\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Comm_accept_timeout);
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
  _LOCAL_MPI_Comm_accept(port_name, &info_tmp, &root_tmp, &comm_tmp,
                         &newcomm_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    comm_r2a(newcomm, &newcomm_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Comm_accept\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_comm_connect_(char *, int *, int *, int *, int *, int *);

void mpi_comm_connect__(char *, int *, int *, int *, int *, int *);

void pmpi_comm_connect_(char *, int *, int *, int *, int *, int *);

void pmpi_comm_connect__(char *, int *, int *, int *, int *, int *);

void pmpi_comm_connect_(char *, int *, int *, int *, int *, int *);

#define A_f_MPI_Comm_connect _PMPI_Comm_connect
#pragma weak mpi_comm_connect_ = _PMPI_Comm_connect
#pragma weak mpi_comm_connect__ = _PMPI_Comm_connect
#pragma weak pmpi_comm_connect__ = _PMPI_Comm_connect
extern long long WI4MPI_Comm_connect_timeout;
void (*_LOCAL_MPI_Comm_connect)(char *, int *, int *, int *, int *, int *);

void A_f_MPI_Comm_connect(char *port_name, int *info, int *root, int *comm,
                          int *newcomm, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Comm_connect\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Comm_connect_timeout);
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
  _LOCAL_MPI_Comm_connect(port_name, &info_tmp, &root_tmp, &comm_tmp,
                          &newcomm_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    comm_r2a(newcomm, &newcomm_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Comm_connect\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_comm_disconnect_(int *, int *);

void mpi_comm_disconnect__(int *, int *);

void pmpi_comm_disconnect_(int *, int *);

void pmpi_comm_disconnect__(int *, int *);

void pmpi_comm_disconnect_(int *, int *);

#define A_f_MPI_Comm_disconnect _PMPI_Comm_disconnect
#pragma weak mpi_comm_disconnect_ = _PMPI_Comm_disconnect
#pragma weak mpi_comm_disconnect__ = _PMPI_Comm_disconnect
#pragma weak pmpi_comm_disconnect__ = _PMPI_Comm_disconnect
extern long long WI4MPI_Comm_disconnect_timeout;
void (*_LOCAL_MPI_Comm_disconnect)(int *, int *);

void A_f_MPI_Comm_disconnect(int *comm, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Comm_disconnect\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Comm_disconnect_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Comm_disconnect(&comm_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    comm_r2a(comm, &comm_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Comm_disconnect\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_comm_get_parent_(int *, int *);

void mpi_comm_get_parent__(int *, int *);

void pmpi_comm_get_parent_(int *, int *);

void pmpi_comm_get_parent__(int *, int *);

void pmpi_comm_get_parent_(int *, int *);

#define A_f_MPI_Comm_get_parent _PMPI_Comm_get_parent
#pragma weak mpi_comm_get_parent_ = _PMPI_Comm_get_parent
#pragma weak mpi_comm_get_parent__ = _PMPI_Comm_get_parent
#pragma weak pmpi_comm_get_parent__ = _PMPI_Comm_get_parent
extern long long WI4MPI_Comm_get_parent_timeout;
void (*_LOCAL_MPI_Comm_get_parent)(int *, int *);

void A_f_MPI_Comm_get_parent(int *parent, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Comm_get_parent\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Comm_get_parent_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int parent_tmp;
  _LOCAL_MPI_Comm_get_parent(&parent_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    comm_r2a(parent, &parent_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Comm_get_parent\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_comm_join_(int *, int *, int *);

void mpi_comm_join__(int *, int *, int *);

void pmpi_comm_join_(int *, int *, int *);

void pmpi_comm_join__(int *, int *, int *);

void pmpi_comm_join_(int *, int *, int *);

#define A_f_MPI_Comm_join _PMPI_Comm_join
#pragma weak mpi_comm_join_ = _PMPI_Comm_join
#pragma weak mpi_comm_join__ = _PMPI_Comm_join
#pragma weak pmpi_comm_join__ = _PMPI_Comm_join
extern long long WI4MPI_Comm_join_timeout;
void (*_LOCAL_MPI_Comm_join)(int *, int *, int *);

void A_f_MPI_Comm_join(int *fd, int *intercomm, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Comm_join\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Comm_join_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int intercomm_tmp;
  _LOCAL_MPI_Comm_join(fd, &intercomm_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    comm_r2a(intercomm, &intercomm_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Comm_join\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_comm_set_info_(int *, int *, int *);

void mpi_comm_set_info__(int *, int *, int *);

void pmpi_comm_set_info_(int *, int *, int *);

void pmpi_comm_set_info__(int *, int *, int *);

void pmpi_comm_set_info_(int *, int *, int *);

#define A_f_MPI_Comm_set_info _PMPI_Comm_set_info
#pragma weak mpi_comm_set_info_ = _PMPI_Comm_set_info
#pragma weak mpi_comm_set_info__ = _PMPI_Comm_set_info
#pragma weak pmpi_comm_set_info__ = _PMPI_Comm_set_info
extern long long WI4MPI_Comm_set_info_timeout;
void (*_LOCAL_MPI_Comm_set_info)(int *, int *, int *);

void A_f_MPI_Comm_set_info(int *comm, int *info, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Comm_set_info\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Comm_set_info_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  int info_tmp;
  comm_a2r(comm, &comm_tmp);
  info_a2r(info, &info_tmp);
  _LOCAL_MPI_Comm_set_info(&comm_tmp, &info_tmp, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Comm_set_info\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_comm_get_info_(int *, int *, int *);

void mpi_comm_get_info__(int *, int *, int *);

void pmpi_comm_get_info_(int *, int *, int *);

void pmpi_comm_get_info__(int *, int *, int *);

void pmpi_comm_get_info_(int *, int *, int *);

#define A_f_MPI_Comm_get_info _PMPI_Comm_get_info
#pragma weak mpi_comm_get_info_ = _PMPI_Comm_get_info
#pragma weak mpi_comm_get_info__ = _PMPI_Comm_get_info
#pragma weak pmpi_comm_get_info__ = _PMPI_Comm_get_info
extern long long WI4MPI_Comm_get_info_timeout;
void (*_LOCAL_MPI_Comm_get_info)(int *, int *, int *);

void A_f_MPI_Comm_get_info(int *comm, int *info, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Comm_get_info\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Comm_get_info_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  int info_tmp;
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Comm_get_info(&comm_tmp, &info_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    info_r2a(info, &info_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Comm_get_info\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_accumulate_(void *, int *, int *, int *, size_t *, int *, int *, int *,
                     int *, int *);

void mpi_accumulate__(void *, int *, int *, int *, size_t *, int *, int *,
                      int *, int *, int *);

void pmpi_accumulate_(void *, int *, int *, int *, size_t *, int *, int *,
                      int *, int *, int *);

void pmpi_accumulate__(void *, int *, int *, int *, size_t *, int *, int *,
                       int *, int *, int *);

void pmpi_accumulate_(void *, int *, int *, int *, size_t *, int *, int *,
                      int *, int *, int *);

#define A_f_MPI_Accumulate _PMPI_Accumulate
#pragma weak mpi_accumulate_ = _PMPI_Accumulate
#pragma weak mpi_accumulate__ = _PMPI_Accumulate
#pragma weak pmpi_accumulate__ = _PMPI_Accumulate
extern long long WI4MPI_Accumulate_timeout;
void (*_LOCAL_MPI_Accumulate)(void *, int *, int *, int *, size_t *, int *,
                              int *, int *, int *, int *);

void A_f_MPI_Accumulate(void *origin_addr, int *origin_count,
                        int *origin_datatype, int *target_rank,
                        size_t *target_disp, int *target_count,
                        int *target_datatype, int *op, int *win, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Accumulate\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Accumulate_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *origin_addr_tmp = origin_addr;
  int origin_datatype_tmp;
  int target_rank_tmp;
  int target_datatype_tmp;
  int op_tmp;
  int win_tmp;
  buffer_a2r(&origin_addr, &origin_addr_tmp);
  datatype_a2r(origin_datatype, &origin_datatype_tmp);
  rank_mapper_a2r(target_rank, &target_rank_tmp);
  datatype_a2r(target_datatype, &target_datatype_tmp);
  operator_a2r(op, &op_tmp);
  fwin_a2r(win, &win_tmp);
  _LOCAL_MPI_Accumulate(origin_addr_tmp, origin_count, &origin_datatype_tmp,
                        &target_rank_tmp, target_disp, target_count,
                        &target_datatype_tmp, &op_tmp, &win_tmp, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Accumulate\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_get_(void *, int *, int *, int *, size_t *, int *, int *, int *,
              int *);

void mpi_get__(void *, int *, int *, int *, size_t *, int *, int *, int *,
               int *);

void pmpi_get_(void *, int *, int *, int *, size_t *, int *, int *, int *,
               int *);

void pmpi_get__(void *, int *, int *, int *, size_t *, int *, int *, int *,
                int *);

void pmpi_get_(void *, int *, int *, int *, size_t *, int *, int *, int *,
               int *);

#define A_f_MPI_Get _PMPI_Get
#pragma weak mpi_get_ = _PMPI_Get
#pragma weak mpi_get__ = _PMPI_Get
#pragma weak pmpi_get__ = _PMPI_Get
extern long long WI4MPI_Get_timeout;
void (*_LOCAL_MPI_Get)(void *, int *, int *, int *, size_t *, int *, int *,
                       int *, int *);

void A_f_MPI_Get(void *origin_addr, int *origin_count, int *origin_datatype,
                 int *target_rank, size_t *target_disp, int *target_count,
                 int *target_datatype, int *win, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Get\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Get_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *origin_addr_tmp = origin_addr;
  int origin_datatype_tmp;
  int target_rank_tmp;
  int target_datatype_tmp;
  int win_tmp;
  datatype_a2r(origin_datatype, &origin_datatype_tmp);
  rank_mapper_a2r(target_rank, &target_rank_tmp);
  datatype_a2r(target_datatype, &target_datatype_tmp);
  fwin_a2r(win, &win_tmp);
  _LOCAL_MPI_Get(origin_addr_tmp, origin_count, &origin_datatype_tmp,
                 &target_rank_tmp, target_disp, target_count,
                 &target_datatype_tmp, &win_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&origin_addr, &origin_addr_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Get\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_put_(void *, int *, int *, int *, size_t *, int *, int *, int *,
              int *);

void mpi_put__(void *, int *, int *, int *, size_t *, int *, int *, int *,
               int *);

void pmpi_put_(void *, int *, int *, int *, size_t *, int *, int *, int *,
               int *);

void pmpi_put__(void *, int *, int *, int *, size_t *, int *, int *, int *,
                int *);

void pmpi_put_(void *, int *, int *, int *, size_t *, int *, int *, int *,
               int *);

#define A_f_MPI_Put _PMPI_Put
#pragma weak mpi_put_ = _PMPI_Put
#pragma weak mpi_put__ = _PMPI_Put
#pragma weak pmpi_put__ = _PMPI_Put
extern long long WI4MPI_Put_timeout;
void (*_LOCAL_MPI_Put)(void *, int *, int *, int *, size_t *, int *, int *,
                       int *, int *);

void A_f_MPI_Put(void *origin_addr, int *origin_count, int *origin_datatype,
                 int *target_rank, size_t *target_disp, int *target_count,
                 int *target_datatype, int *win, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Put\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Put_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *origin_addr_tmp = origin_addr;
  int origin_datatype_tmp;
  int target_rank_tmp;
  int target_datatype_tmp;
  int win_tmp;
  buffer_a2r(&origin_addr, &origin_addr_tmp);
  datatype_a2r(origin_datatype, &origin_datatype_tmp);
  rank_mapper_a2r(target_rank, &target_rank_tmp);
  datatype_a2r(target_datatype, &target_datatype_tmp);
  fwin_a2r(win, &win_tmp);
  _LOCAL_MPI_Put(origin_addr_tmp, origin_count, &origin_datatype_tmp,
                 &target_rank_tmp, target_disp, target_count,
                 &target_datatype_tmp, &win_tmp, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Put\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_win_complete_(int *, int *);

void mpi_win_complete__(int *, int *);

void pmpi_win_complete_(int *, int *);

void pmpi_win_complete__(int *, int *);

void pmpi_win_complete_(int *, int *);

#define A_f_MPI_Win_complete _PMPI_Win_complete
#pragma weak mpi_win_complete_ = _PMPI_Win_complete
#pragma weak mpi_win_complete__ = _PMPI_Win_complete
#pragma weak pmpi_win_complete__ = _PMPI_Win_complete
extern long long WI4MPI_Win_complete_timeout;
void (*_LOCAL_MPI_Win_complete)(int *, int *);

void A_f_MPI_Win_complete(int *win, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Win_complete\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Win_complete_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int win_tmp;
  fwin_a2r(win, &win_tmp);
  _LOCAL_MPI_Win_complete(&win_tmp, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Win_complete\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_win_create_(void *, size_t *, int *, int *, int *, int *, int *);

void mpi_win_create__(void *, size_t *, int *, int *, int *, int *, int *);

void pmpi_win_create_(void *, size_t *, int *, int *, int *, int *, int *);

void pmpi_win_create__(void *, size_t *, int *, int *, int *, int *, int *);

void pmpi_win_create_(void *, size_t *, int *, int *, int *, int *, int *);

#define A_f_MPI_Win_create _PMPI_Win_create
#pragma weak mpi_win_create_ = _PMPI_Win_create
#pragma weak mpi_win_create__ = _PMPI_Win_create
#pragma weak pmpi_win_create__ = _PMPI_Win_create
extern long long WI4MPI_Win_create_timeout;
void (*_LOCAL_MPI_Win_create)(void *, size_t *, int *, int *, int *, int *,
                              int *);

void A_f_MPI_Win_create(void *base, size_t *size, int *disp_unit, int *info,
                        int *comm, int *win, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Win_create\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Win_create_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *base_tmp = base;
  int info_tmp;
  int comm_tmp;
  int win_tmp;
  buffer_a2r(&base, &base_tmp);
  info_a2r(info, &info_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Win_create(base_tmp, size, disp_unit, &info_tmp, &comm_tmp,
                        &win_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    fwin_r2a(win, &win_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Win_create\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_win_fence_(int *, int *, int *);

void mpi_win_fence__(int *, int *, int *);

void pmpi_win_fence_(int *, int *, int *);

void pmpi_win_fence__(int *, int *, int *);

void pmpi_win_fence_(int *, int *, int *);

#define A_f_MPI_Win_fence _PMPI_Win_fence
#pragma weak mpi_win_fence_ = _PMPI_Win_fence
#pragma weak mpi_win_fence__ = _PMPI_Win_fence
#pragma weak pmpi_win_fence__ = _PMPI_Win_fence
extern long long WI4MPI_Win_fence_timeout;
void (*_LOCAL_MPI_Win_fence)(int *, int *, int *);

void A_f_MPI_Win_fence(int *assert, int *win, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Win_fence\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Win_fence_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int assert_tmp;
  int win_tmp;
  win_assert_mode_a2r(assert, &assert_tmp);
  fwin_a2r(win, &win_tmp);
  _LOCAL_MPI_Win_fence(&assert_tmp, &win_tmp, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Win_fence\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_win_free_(int *, int *);

void mpi_win_free__(int *, int *);

void pmpi_win_free_(int *, int *);

void pmpi_win_free__(int *, int *);

void pmpi_win_free_(int *, int *);

#define A_f_MPI_Win_free _PMPI_Win_free
#pragma weak mpi_win_free_ = _PMPI_Win_free
#pragma weak mpi_win_free__ = _PMPI_Win_free
#pragma weak pmpi_win_free__ = _PMPI_Win_free
extern long long WI4MPI_Win_free_timeout;
void (*_LOCAL_MPI_Win_free)(int *, int *);

void A_f_MPI_Win_free(int *win, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Win_free\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Win_free_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int win_tmp;
  fwin_a2r(win, &win_tmp);
  _LOCAL_MPI_Win_free(&win_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    fwin_r2a(win, &win_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Win_free\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_win_get_group_(int *, int *, int *);

void mpi_win_get_group__(int *, int *, int *);

void pmpi_win_get_group_(int *, int *, int *);

void pmpi_win_get_group__(int *, int *, int *);

void pmpi_win_get_group_(int *, int *, int *);

#define A_f_MPI_Win_get_group _PMPI_Win_get_group
#pragma weak mpi_win_get_group_ = _PMPI_Win_get_group
#pragma weak mpi_win_get_group__ = _PMPI_Win_get_group
#pragma weak pmpi_win_get_group__ = _PMPI_Win_get_group
extern long long WI4MPI_Win_get_group_timeout;
void (*_LOCAL_MPI_Win_get_group)(int *, int *, int *);

void A_f_MPI_Win_get_group(int *win, int *group, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Win_get_group\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Win_get_group_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int win_tmp;
  int group_tmp;
  fwin_a2r(win, &win_tmp);
  _LOCAL_MPI_Win_get_group(&win_tmp, &group_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    group_r2a(group, &group_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Win_get_group\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_win_lock_(int *, int *, int *, int *, int *);

void mpi_win_lock__(int *, int *, int *, int *, int *);

void pmpi_win_lock_(int *, int *, int *, int *, int *);

void pmpi_win_lock__(int *, int *, int *, int *, int *);

void pmpi_win_lock_(int *, int *, int *, int *, int *);

#define A_f_MPI_Win_lock _PMPI_Win_lock
#pragma weak mpi_win_lock_ = _PMPI_Win_lock
#pragma weak mpi_win_lock__ = _PMPI_Win_lock
#pragma weak pmpi_win_lock__ = _PMPI_Win_lock
extern long long WI4MPI_Win_lock_timeout;
void (*_LOCAL_MPI_Win_lock)(int *, int *, int *, int *, int *);

void A_f_MPI_Win_lock(int *lock_type, int *rank, int *assert, int *win,
                      int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Win_lock\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Win_lock_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int lock_type_tmp;
  int rank_tmp;
  int assert_tmp;
  int win_tmp;
  win_lock_a2r(lock_type, &lock_type_tmp);
  rank_mapper_a2r(rank, &rank_tmp);
  win_assert_mode_a2r(assert, &assert_tmp);
  fwin_a2r(win, &win_tmp);
  _LOCAL_MPI_Win_lock(&lock_type_tmp, &rank_tmp, &assert_tmp, &win_tmp,
                      &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Win_lock\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_win_post_(int *, int *, int *, int *);

void mpi_win_post__(int *, int *, int *, int *);

void pmpi_win_post_(int *, int *, int *, int *);

void pmpi_win_post__(int *, int *, int *, int *);

void pmpi_win_post_(int *, int *, int *, int *);

#define A_f_MPI_Win_post _PMPI_Win_post
#pragma weak mpi_win_post_ = _PMPI_Win_post
#pragma weak mpi_win_post__ = _PMPI_Win_post
#pragma weak pmpi_win_post__ = _PMPI_Win_post
extern long long WI4MPI_Win_post_timeout;
void (*_LOCAL_MPI_Win_post)(int *, int *, int *, int *);

void A_f_MPI_Win_post(int *group, int *assert, int *win, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Win_post\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Win_post_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int group_tmp;
  int assert_tmp;
  int win_tmp;
  group_a2r(group, &group_tmp);
  win_assert_mode_a2r(assert, &assert_tmp);
  fwin_a2r(win, &win_tmp);
  _LOCAL_MPI_Win_post(&group_tmp, &assert_tmp, &win_tmp, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Win_post\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_win_start_(int *, int *, int *, int *);

void mpi_win_start__(int *, int *, int *, int *);

void pmpi_win_start_(int *, int *, int *, int *);

void pmpi_win_start__(int *, int *, int *, int *);

void pmpi_win_start_(int *, int *, int *, int *);

#define A_f_MPI_Win_start _PMPI_Win_start
#pragma weak mpi_win_start_ = _PMPI_Win_start
#pragma weak mpi_win_start__ = _PMPI_Win_start
#pragma weak pmpi_win_start__ = _PMPI_Win_start
extern long long WI4MPI_Win_start_timeout;
void (*_LOCAL_MPI_Win_start)(int *, int *, int *, int *);

void A_f_MPI_Win_start(int *group, int *assert, int *win, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Win_start\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Win_start_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int group_tmp;
  int assert_tmp;
  int win_tmp;
  group_a2r(group, &group_tmp);
  win_assert_mode_a2r(assert, &assert_tmp);
  fwin_a2r(win, &win_tmp);
  _LOCAL_MPI_Win_start(&group_tmp, &assert_tmp, &win_tmp, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Win_start\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_win_test_(int *, int *, int *);

void mpi_win_test__(int *, int *, int *);

void pmpi_win_test_(int *, int *, int *);

void pmpi_win_test__(int *, int *, int *);

void pmpi_win_test_(int *, int *, int *);

#define A_f_MPI_Win_test _PMPI_Win_test
#pragma weak mpi_win_test_ = _PMPI_Win_test
#pragma weak mpi_win_test__ = _PMPI_Win_test
#pragma weak pmpi_win_test__ = _PMPI_Win_test
extern long long WI4MPI_Win_test_timeout;
void (*_LOCAL_MPI_Win_test)(int *, int *, int *);

void A_f_MPI_Win_test(int *win, int *flag, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Win_test\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Win_test_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int win_tmp;
  fwin_a2r(win, &win_tmp);
  _LOCAL_MPI_Win_test(&win_tmp, flag, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Win_test\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_win_unlock_(int *, int *, int *);

void mpi_win_unlock__(int *, int *, int *);

void pmpi_win_unlock_(int *, int *, int *);

void pmpi_win_unlock__(int *, int *, int *);

void pmpi_win_unlock_(int *, int *, int *);

#define A_f_MPI_Win_unlock _PMPI_Win_unlock
#pragma weak mpi_win_unlock_ = _PMPI_Win_unlock
#pragma weak mpi_win_unlock__ = _PMPI_Win_unlock
#pragma weak pmpi_win_unlock__ = _PMPI_Win_unlock
extern long long WI4MPI_Win_unlock_timeout;
void (*_LOCAL_MPI_Win_unlock)(int *, int *, int *);

void A_f_MPI_Win_unlock(int *rank, int *win, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Win_unlock\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Win_unlock_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int rank_tmp;
  int win_tmp;
  rank_mapper_a2r(rank, &rank_tmp);
  fwin_a2r(win, &win_tmp);
  _LOCAL_MPI_Win_unlock(&rank_tmp, &win_tmp, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Win_unlock\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_win_wait_(int *, int *);

void mpi_win_wait__(int *, int *);

void pmpi_win_wait_(int *, int *);

void pmpi_win_wait__(int *, int *);

void pmpi_win_wait_(int *, int *);

#define A_f_MPI_Win_wait _PMPI_Win_wait
#pragma weak mpi_win_wait_ = _PMPI_Win_wait
#pragma weak mpi_win_wait__ = _PMPI_Win_wait
#pragma weak pmpi_win_wait__ = _PMPI_Win_wait
extern long long WI4MPI_Win_wait_timeout;
void (*_LOCAL_MPI_Win_wait)(int *, int *);

void A_f_MPI_Win_wait(int *win, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Win_wait\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Win_wait_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int win_tmp;
  fwin_a2r(win, &win_tmp);
  _LOCAL_MPI_Win_wait(&win_tmp, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Win_wait\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_win_allocate_(size_t *, int *, int *, int *, void *, int *, int *);

void mpi_win_allocate__(size_t *, int *, int *, int *, void *, int *, int *);

void pmpi_win_allocate_(size_t *, int *, int *, int *, void *, int *, int *);

void pmpi_win_allocate__(size_t *, int *, int *, int *, void *, int *, int *);

void pmpi_win_allocate_(size_t *, int *, int *, int *, void *, int *, int *);

#define A_f_MPI_Win_allocate _PMPI_Win_allocate
#pragma weak mpi_win_allocate_ = _PMPI_Win_allocate
#pragma weak mpi_win_allocate__ = _PMPI_Win_allocate
#pragma weak pmpi_win_allocate__ = _PMPI_Win_allocate
extern long long WI4MPI_Win_allocate_timeout;
void (*_LOCAL_MPI_Win_allocate)(size_t *, int *, int *, int *, void *, int *,
                                int *);

void A_f_MPI_Win_allocate(size_t *size, int *disp_unit, int *info, int *comm,
                          void *baseptr, int *win, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Win_allocate\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Win_allocate_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int info_tmp;
  void *baseptr_tmp = baseptr;
  int win_tmp;
  info_a2r(info, &info_tmp);
  _LOCAL_MPI_Win_allocate(size, disp_unit, &info_tmp, comm, baseptr_tmp,
                          &win_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&baseptr, &baseptr_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    fwin_r2a(win, &win_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Win_allocate\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_win_allocate_shared_(size_t *, int *, int *, int *, void *, int *,
                              int *);

void mpi_win_allocate_shared__(size_t *, int *, int *, int *, void *, int *,
                               int *);

void pmpi_win_allocate_shared_(size_t *, int *, int *, int *, void *, int *,
                               int *);

void pmpi_win_allocate_shared__(size_t *, int *, int *, int *, void *, int *,
                                int *);

void pmpi_win_allocate_shared_(size_t *, int *, int *, int *, void *, int *,
                               int *);

#define A_f_MPI_Win_allocate_shared _PMPI_Win_allocate_shared
#pragma weak mpi_win_allocate_shared_ = _PMPI_Win_allocate_shared
#pragma weak mpi_win_allocate_shared__ = _PMPI_Win_allocate_shared
#pragma weak pmpi_win_allocate_shared__ = _PMPI_Win_allocate_shared
extern long long WI4MPI_Win_allocate_shared_timeout;
void (*_LOCAL_MPI_Win_allocate_shared)(size_t *, int *, int *, int *, void *,
                                       int *, int *);

void A_f_MPI_Win_allocate_shared(size_t *size, int *disp_unit, int *info,
                                 int *comm, void *baseptr, int *win, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Win_allocate_shared\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Win_allocate_shared_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int info_tmp;
  int comm_tmp;
  void *baseptr_tmp = baseptr;
  int win_tmp;
  info_a2r(info, &info_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Win_allocate_shared(size, disp_unit, &info_tmp, &comm_tmp,
                                 baseptr_tmp, &win_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&baseptr, &baseptr_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    fwin_r2a(win, &win_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Win_allocate_shared\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_win_shared_query_(int *, int *, size_t *, int *, void *, int *);

void mpi_win_shared_query__(int *, int *, size_t *, int *, void *, int *);

void pmpi_win_shared_query_(int *, int *, size_t *, int *, void *, int *);

void pmpi_win_shared_query__(int *, int *, size_t *, int *, void *, int *);

void pmpi_win_shared_query_(int *, int *, size_t *, int *, void *, int *);

#define A_f_MPI_Win_shared_query _PMPI_Win_shared_query
#pragma weak mpi_win_shared_query_ = _PMPI_Win_shared_query
#pragma weak mpi_win_shared_query__ = _PMPI_Win_shared_query
#pragma weak pmpi_win_shared_query__ = _PMPI_Win_shared_query
extern long long WI4MPI_Win_shared_query_timeout;
void (*_LOCAL_MPI_Win_shared_query)(int *, int *, size_t *, int *, void *,
                                    int *);

void A_f_MPI_Win_shared_query(int *win, int *rank, size_t *size, int *disp_unit,
                              void *baseptr, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Win_shared_query\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Win_shared_query_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int win_tmp;
  void *baseptr_tmp = baseptr;
  fwin_a2r(win, &win_tmp);
  _LOCAL_MPI_Win_shared_query(&win_tmp, rank, size, disp_unit, baseptr_tmp,
                              &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&baseptr, &baseptr_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Win_shared_query\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_win_create_dynamic_(int *, int *, int *, int *);

void mpi_win_create_dynamic__(int *, int *, int *, int *);

void pmpi_win_create_dynamic_(int *, int *, int *, int *);

void pmpi_win_create_dynamic__(int *, int *, int *, int *);

void pmpi_win_create_dynamic_(int *, int *, int *, int *);

#define A_f_MPI_Win_create_dynamic _PMPI_Win_create_dynamic
#pragma weak mpi_win_create_dynamic_ = _PMPI_Win_create_dynamic
#pragma weak mpi_win_create_dynamic__ = _PMPI_Win_create_dynamic
#pragma weak pmpi_win_create_dynamic__ = _PMPI_Win_create_dynamic
extern long long WI4MPI_Win_create_dynamic_timeout;
void (*_LOCAL_MPI_Win_create_dynamic)(int *, int *, int *, int *);

void A_f_MPI_Win_create_dynamic(int *info, int *comm, int *win, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Win_create_dynamic\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Win_create_dynamic_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int info_tmp;
  int comm_tmp;
  int win_tmp;
  info_a2r(info, &info_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Win_create_dynamic(&info_tmp, &comm_tmp, &win_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    fwin_r2a(win, &win_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Win_create_dynamic\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_win_attach_(int *, void *, size_t *, int *);

void mpi_win_attach__(int *, void *, size_t *, int *);

void pmpi_win_attach_(int *, void *, size_t *, int *);

void pmpi_win_attach__(int *, void *, size_t *, int *);

void pmpi_win_attach_(int *, void *, size_t *, int *);

#define A_f_MPI_Win_attach _PMPI_Win_attach
#pragma weak mpi_win_attach_ = _PMPI_Win_attach
#pragma weak mpi_win_attach__ = _PMPI_Win_attach
#pragma weak pmpi_win_attach__ = _PMPI_Win_attach
extern long long WI4MPI_Win_attach_timeout;
void (*_LOCAL_MPI_Win_attach)(int *, void *, size_t *, int *);

void A_f_MPI_Win_attach(int *win, void *base, size_t *size, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Win_attach\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Win_attach_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int win_tmp;
  void *base_tmp = base;
  fwin_a2r(win, &win_tmp);
  buffer_a2r(&base, &base_tmp);
  _LOCAL_MPI_Win_attach(&win_tmp, base_tmp, size, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Win_attach\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_win_detach_(int *, void *, int *);

void mpi_win_detach__(int *, void *, int *);

void pmpi_win_detach_(int *, void *, int *);

void pmpi_win_detach__(int *, void *, int *);

void pmpi_win_detach_(int *, void *, int *);

#define A_f_MPI_Win_detach _PMPI_Win_detach
#pragma weak mpi_win_detach_ = _PMPI_Win_detach
#pragma weak mpi_win_detach__ = _PMPI_Win_detach
#pragma weak pmpi_win_detach__ = _PMPI_Win_detach
extern long long WI4MPI_Win_detach_timeout;
void (*_LOCAL_MPI_Win_detach)(int *, void *, int *);

void A_f_MPI_Win_detach(int *win, void *base, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Win_detach\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Win_detach_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int win_tmp;
  void *base_tmp = base;
  fwin_a2r(win, &win_tmp);
  buffer_a2r(&base, &base_tmp);
  _LOCAL_MPI_Win_detach(&win_tmp, base_tmp, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Win_detach\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_win_get_info_(int *, int *, int *);

void mpi_win_get_info__(int *, int *, int *);

void pmpi_win_get_info_(int *, int *, int *);

void pmpi_win_get_info__(int *, int *, int *);

void pmpi_win_get_info_(int *, int *, int *);

#define A_f_MPI_Win_get_info _PMPI_Win_get_info
#pragma weak mpi_win_get_info_ = _PMPI_Win_get_info
#pragma weak mpi_win_get_info__ = _PMPI_Win_get_info
#pragma weak pmpi_win_get_info__ = _PMPI_Win_get_info
extern long long WI4MPI_Win_get_info_timeout;
void (*_LOCAL_MPI_Win_get_info)(int *, int *, int *);

void A_f_MPI_Win_get_info(int *win, int *info_used, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Win_get_info\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Win_get_info_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int win_tmp;
  int info_used_tmp;
  fwin_a2r(win, &win_tmp);
  _LOCAL_MPI_Win_get_info(&win_tmp, &info_used_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    info_r2a(info_used, &info_used_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Win_get_info\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_win_set_info_(int *, int *, int *);

void mpi_win_set_info__(int *, int *, int *);

void pmpi_win_set_info_(int *, int *, int *);

void pmpi_win_set_info__(int *, int *, int *);

void pmpi_win_set_info_(int *, int *, int *);

#define A_f_MPI_Win_set_info _PMPI_Win_set_info
#pragma weak mpi_win_set_info_ = _PMPI_Win_set_info
#pragma weak mpi_win_set_info__ = _PMPI_Win_set_info
#pragma weak pmpi_win_set_info__ = _PMPI_Win_set_info
extern long long WI4MPI_Win_set_info_timeout;
void (*_LOCAL_MPI_Win_set_info)(int *, int *, int *);

void A_f_MPI_Win_set_info(int *win, int *info, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Win_set_info\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Win_set_info_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int win_tmp;
  int info_tmp;
  fwin_a2r(win, &win_tmp);
  info_a2r(info, &info_tmp);
  _LOCAL_MPI_Win_set_info(&win_tmp, &info_tmp, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Win_set_info\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_get_accumulate_(void *, int *, int *, void *, int *, int *, int *,
                         size_t *, int *, int *, int *, int *, int *);

void mpi_get_accumulate__(void *, int *, int *, void *, int *, int *, int *,
                          size_t *, int *, int *, int *, int *, int *);

void pmpi_get_accumulate_(void *, int *, int *, void *, int *, int *, int *,
                          size_t *, int *, int *, int *, int *, int *);

void pmpi_get_accumulate__(void *, int *, int *, void *, int *, int *, int *,
                           size_t *, int *, int *, int *, int *, int *);

void pmpi_get_accumulate_(void *, int *, int *, void *, int *, int *, int *,
                          size_t *, int *, int *, int *, int *, int *);

#define A_f_MPI_Get_accumulate _PMPI_Get_accumulate
#pragma weak mpi_get_accumulate_ = _PMPI_Get_accumulate
#pragma weak mpi_get_accumulate__ = _PMPI_Get_accumulate
#pragma weak pmpi_get_accumulate__ = _PMPI_Get_accumulate
extern long long WI4MPI_Get_accumulate_timeout;
void (*_LOCAL_MPI_Get_accumulate)(void *, int *, int *, void *, int *, int *,
                                  int *, size_t *, int *, int *, int *, int *,
                                  int *);

void A_f_MPI_Get_accumulate(void *origin_addr, int *origin_count,
                            int *origin_datatype, void *result_addr,
                            int *result_count, int *result_datatype,
                            int *target_rank, size_t *target_disp,
                            int *target_count, int *target_datatype, int *op,
                            int *win, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Get_accumulate\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Get_accumulate_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *origin_addr_tmp = origin_addr;
  int origin_datatype_tmp;
  void *result_addr_tmp = result_addr;
  int result_datatype_tmp;
  int target_rank_tmp;
  int target_datatype_tmp;
  int op_tmp;
  int win_tmp;
  buffer_a2r(&origin_addr, &origin_addr_tmp);
  datatype_a2r(origin_datatype, &origin_datatype_tmp);
  buffer_a2r(&result_addr, &result_addr_tmp);
  datatype_a2r(result_datatype, &result_datatype_tmp);
  rank_mapper_a2r(target_rank, &target_rank_tmp);
  datatype_a2r(target_datatype, &target_datatype_tmp);
  operator_a2r(op, &op_tmp);
  fwin_a2r(win, &win_tmp);
  _LOCAL_MPI_Get_accumulate(origin_addr_tmp, origin_count, &origin_datatype_tmp,
                            result_addr_tmp, result_count, &result_datatype_tmp,
                            &target_rank_tmp, target_disp, target_count,
                            &target_datatype_tmp, &op_tmp, &win_tmp, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Get_accumulate\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_fetch_and_op_(void *, void *, int *, int *, size_t *, int *, int *,
                       int *);

void mpi_fetch_and_op__(void *, void *, int *, int *, size_t *, int *, int *,
                        int *);

void pmpi_fetch_and_op_(void *, void *, int *, int *, size_t *, int *, int *,
                        int *);

void pmpi_fetch_and_op__(void *, void *, int *, int *, size_t *, int *, int *,
                         int *);

void pmpi_fetch_and_op_(void *, void *, int *, int *, size_t *, int *, int *,
                        int *);

#define A_f_MPI_Fetch_and_op _PMPI_Fetch_and_op
#pragma weak mpi_fetch_and_op_ = _PMPI_Fetch_and_op
#pragma weak mpi_fetch_and_op__ = _PMPI_Fetch_and_op
#pragma weak pmpi_fetch_and_op__ = _PMPI_Fetch_and_op
extern long long WI4MPI_Fetch_and_op_timeout;
void (*_LOCAL_MPI_Fetch_and_op)(void *, void *, int *, int *, size_t *, int *,
                                int *, int *);

void A_f_MPI_Fetch_and_op(void *origin_addr, void *result_addr, int *datatype,
                          int *target_rank, size_t *target_disp, int *op,
                          int *win, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Fetch_and_op\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Fetch_and_op_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *origin_addr_tmp = origin_addr;
  void *result_addr_tmp = result_addr;
  int datatype_tmp;
  int target_rank_tmp;
  int op_tmp;
  int win_tmp;
  buffer_a2r(&origin_addr, &origin_addr_tmp);
  buffer_a2r(&result_addr, &result_addr_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  rank_mapper_a2r(target_rank, &target_rank_tmp);
  operator_a2r(op, &op_tmp);
  fwin_a2r(win, &win_tmp);
  _LOCAL_MPI_Fetch_and_op(origin_addr_tmp, result_addr_tmp, &datatype_tmp,
                          &target_rank_tmp, target_disp, &op_tmp, &win_tmp,
                          &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&result_addr, &result_addr_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Fetch_and_op\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_compare_and_swap_(void *, void *, void *, int *, int *, size_t *,
                           int *, int *);

void mpi_compare_and_swap__(void *, void *, void *, int *, int *, size_t *,
                            int *, int *);

void pmpi_compare_and_swap_(void *, void *, void *, int *, int *, size_t *,
                            int *, int *);

void pmpi_compare_and_swap__(void *, void *, void *, int *, int *, size_t *,
                             int *, int *);

void pmpi_compare_and_swap_(void *, void *, void *, int *, int *, size_t *,
                            int *, int *);

#define A_f_MPI_Compare_and_swap _PMPI_Compare_and_swap
#pragma weak mpi_compare_and_swap_ = _PMPI_Compare_and_swap
#pragma weak mpi_compare_and_swap__ = _PMPI_Compare_and_swap
#pragma weak pmpi_compare_and_swap__ = _PMPI_Compare_and_swap
extern long long WI4MPI_Compare_and_swap_timeout;
void (*_LOCAL_MPI_Compare_and_swap)(void *, void *, void *, int *, int *,
                                    size_t *, int *, int *);

void A_f_MPI_Compare_and_swap(void *origin_addr, void *compare_addr,
                              void *result_addr, int *datatype,
                              int *target_rank, size_t *target_disp, int *win,
                              int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Compare_and_swap\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Compare_and_swap_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *origin_addr_tmp = origin_addr;
  void *compare_addr_tmp = compare_addr;
  void *result_addr_tmp = result_addr;
  int datatype_tmp;
  int target_rank_tmp;
  int win_tmp;
  buffer_a2r(&origin_addr, &origin_addr_tmp);
  buffer_a2r(&compare_addr, &compare_addr_tmp);
  buffer_a2r(&result_addr, &result_addr_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  rank_mapper_a2r(target_rank, &target_rank_tmp);
  fwin_a2r(win, &win_tmp);
  _LOCAL_MPI_Compare_and_swap(origin_addr_tmp, compare_addr_tmp,
                              result_addr_tmp, &datatype_tmp, &target_rank_tmp,
                              target_disp, &win_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&result_addr, &result_addr_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Compare_and_swap\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_rput_(void *, int *, int *, int *, size_t *, int *, int *, int *,
               int *, int *);

void mpi_rput__(void *, int *, int *, int *, size_t *, int *, int *, int *,
                int *, int *);

void pmpi_rput_(void *, int *, int *, int *, size_t *, int *, int *, int *,
                int *, int *);

void pmpi_rput__(void *, int *, int *, int *, size_t *, int *, int *, int *,
                 int *, int *);

void pmpi_rput_(void *, int *, int *, int *, size_t *, int *, int *, int *,
                int *, int *);

#define A_f_MPI_Rput _PMPI_Rput
#pragma weak mpi_rput_ = _PMPI_Rput
#pragma weak mpi_rput__ = _PMPI_Rput
#pragma weak pmpi_rput__ = _PMPI_Rput
extern long long WI4MPI_Rput_timeout;
void (*_LOCAL_MPI_Rput)(void *, int *, int *, int *, size_t *, int *, int *,
                        int *, int *, int *);

void A_f_MPI_Rput(void *origin_addr, int *origin_count, int *origin_datatype,
                  int *target_rank, size_t *target_disp, int *target_count,
                  int *target_datatype, int *win, int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Rput\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Rput_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *origin_addr_tmp = origin_addr;
  int origin_datatype_tmp;
  int target_rank_tmp;
  int target_datatype_tmp;
  int win_tmp;
  int request_tmp;
  buffer_a2r(&origin_addr, &origin_addr_tmp);
  datatype_a2r(origin_datatype, &origin_datatype_tmp);
  rank_mapper_a2r(target_rank, &target_rank_tmp);
  datatype_a2r(target_datatype, &target_datatype_tmp);
  fwin_a2r(win, &win_tmp);
  _LOCAL_MPI_Rput(origin_addr_tmp, origin_count, &origin_datatype_tmp,
                  &target_rank_tmp, target_disp, target_count,
                  &target_datatype_tmp, &win_tmp, &request_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Rput\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_rget_(void *, int *, int *, int *, size_t *, int *, int *, int *,
               int *, int *);

void mpi_rget__(void *, int *, int *, int *, size_t *, int *, int *, int *,
                int *, int *);

void pmpi_rget_(void *, int *, int *, int *, size_t *, int *, int *, int *,
                int *, int *);

void pmpi_rget__(void *, int *, int *, int *, size_t *, int *, int *, int *,
                 int *, int *);

void pmpi_rget_(void *, int *, int *, int *, size_t *, int *, int *, int *,
                int *, int *);

#define A_f_MPI_Rget _PMPI_Rget
#pragma weak mpi_rget_ = _PMPI_Rget
#pragma weak mpi_rget__ = _PMPI_Rget
#pragma weak pmpi_rget__ = _PMPI_Rget
extern long long WI4MPI_Rget_timeout;
void (*_LOCAL_MPI_Rget)(void *, int *, int *, int *, size_t *, int *, int *,
                        int *, int *, int *);

void A_f_MPI_Rget(void *origin_addr, int *origin_count, int *origin_datatype,
                  int *target_rank, size_t *target_disp, int *target_count,
                  int *target_datatype, int *win, int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Rget\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Rget_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *origin_addr_tmp = origin_addr;
  int origin_datatype_tmp;
  int target_rank_tmp;
  int target_datatype_tmp;
  int win_tmp;
  int request_tmp;
  buffer_a2r(&origin_addr, &origin_addr_tmp);
  datatype_a2r(origin_datatype, &origin_datatype_tmp);
  rank_mapper_a2r(target_rank, &target_rank_tmp);
  datatype_a2r(target_datatype, &target_datatype_tmp);
  fwin_a2r(win, &win_tmp);
  _LOCAL_MPI_Rget(origin_addr_tmp, origin_count, &origin_datatype_tmp,
                  &target_rank_tmp, target_disp, target_count,
                  &target_datatype_tmp, &win_tmp, &request_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Rget\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_raccumulate_(void *, int *, int *, int *, size_t *, int *, int *,
                      int *, int *, int *, int *);

void mpi_raccumulate__(void *, int *, int *, int *, size_t *, int *, int *,
                       int *, int *, int *, int *);

void pmpi_raccumulate_(void *, int *, int *, int *, size_t *, int *, int *,
                       int *, int *, int *, int *);

void pmpi_raccumulate__(void *, int *, int *, int *, size_t *, int *, int *,
                        int *, int *, int *, int *);

void pmpi_raccumulate_(void *, int *, int *, int *, size_t *, int *, int *,
                       int *, int *, int *, int *);

#define A_f_MPI_Raccumulate _PMPI_Raccumulate
#pragma weak mpi_raccumulate_ = _PMPI_Raccumulate
#pragma weak mpi_raccumulate__ = _PMPI_Raccumulate
#pragma weak pmpi_raccumulate__ = _PMPI_Raccumulate
extern long long WI4MPI_Raccumulate_timeout;
void (*_LOCAL_MPI_Raccumulate)(void *, int *, int *, int *, size_t *, int *,
                               int *, int *, int *, int *, int *);

void A_f_MPI_Raccumulate(void *origin_addr, int *origin_count,
                         int *origin_datatype, int *target_rank,
                         size_t *target_disp, int *target_count,
                         int *target_datatype, int *op, int *win, int *request,
                         int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Raccumulate\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Raccumulate_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *origin_addr_tmp = origin_addr;
  int origin_datatype_tmp;
  int target_rank_tmp;
  int target_datatype_tmp;
  int op_tmp;
  int win_tmp;
  int request_tmp;
  buffer_a2r(&origin_addr, &origin_addr_tmp);
  datatype_a2r(origin_datatype, &origin_datatype_tmp);
  rank_mapper_a2r(target_rank, &target_rank_tmp);
  datatype_a2r(target_datatype, &target_datatype_tmp);
  operator_a2r(op, &op_tmp);
  fwin_a2r(win, &win_tmp);
  _LOCAL_MPI_Raccumulate(origin_addr_tmp, origin_count, &origin_datatype_tmp,
                         &target_rank_tmp, target_disp, target_count,
                         &target_datatype_tmp, &op_tmp, &win_tmp, &request_tmp,
                         &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Raccumulate\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_rget_accumulate_(void *, int *, int *, void *, int *, int *, int *,
                          size_t *, int *, int *, int *, int *, int *, int *);

void mpi_rget_accumulate__(void *, int *, int *, void *, int *, int *, int *,
                           size_t *, int *, int *, int *, int *, int *, int *);

void pmpi_rget_accumulate_(void *, int *, int *, void *, int *, int *, int *,
                           size_t *, int *, int *, int *, int *, int *, int *);

void pmpi_rget_accumulate__(void *, int *, int *, void *, int *, int *, int *,
                            size_t *, int *, int *, int *, int *, int *, int *);

void pmpi_rget_accumulate_(void *, int *, int *, void *, int *, int *, int *,
                           size_t *, int *, int *, int *, int *, int *, int *);

#define A_f_MPI_Rget_accumulate _PMPI_Rget_accumulate
#pragma weak mpi_rget_accumulate_ = _PMPI_Rget_accumulate
#pragma weak mpi_rget_accumulate__ = _PMPI_Rget_accumulate
#pragma weak pmpi_rget_accumulate__ = _PMPI_Rget_accumulate
extern long long WI4MPI_Rget_accumulate_timeout;
void (*_LOCAL_MPI_Rget_accumulate)(void *, int *, int *, void *, int *, int *,
                                   int *, size_t *, int *, int *, int *, int *,
                                   int *, int *);

void A_f_MPI_Rget_accumulate(void *origin_addr, int *origin_count,
                             int *origin_datatype, void *result_addr,
                             int *result_count, int *result_datatype,
                             int *target_rank, size_t *target_disp,
                             int *target_count, int *target_datatype, int *op,
                             int *win, int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Rget_accumulate\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Rget_accumulate_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *origin_addr_tmp = origin_addr;
  int origin_datatype_tmp;
  void *result_addr_tmp = result_addr;
  int result_datatype_tmp;
  int target_rank_tmp;
  int target_datatype_tmp;
  int op_tmp;
  int win_tmp;
  int request_tmp;
  buffer_a2r(&origin_addr, &origin_addr_tmp);
  datatype_a2r(origin_datatype, &origin_datatype_tmp);
  buffer_a2r(&result_addr, &result_addr_tmp);
  datatype_a2r(result_datatype, &result_datatype_tmp);
  rank_mapper_a2r(target_rank, &target_rank_tmp);
  datatype_a2r(target_datatype, &target_datatype_tmp);
  operator_a2r(op, &op_tmp);
  fwin_a2r(win, &win_tmp);
  _LOCAL_MPI_Rget_accumulate(
      origin_addr_tmp, origin_count, &origin_datatype_tmp, result_addr_tmp,
      result_count, &result_datatype_tmp, &target_rank_tmp, target_disp,
      target_count, &target_datatype_tmp, &op_tmp, &win_tmp, &request_tmp,
      &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Rget_accumulate\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_win_lock_all_(int *, int *, int *);

void mpi_win_lock_all__(int *, int *, int *);

void pmpi_win_lock_all_(int *, int *, int *);

void pmpi_win_lock_all__(int *, int *, int *);

void pmpi_win_lock_all_(int *, int *, int *);

#define A_f_MPI_Win_lock_all _PMPI_Win_lock_all
#pragma weak mpi_win_lock_all_ = _PMPI_Win_lock_all
#pragma weak mpi_win_lock_all__ = _PMPI_Win_lock_all
#pragma weak pmpi_win_lock_all__ = _PMPI_Win_lock_all
extern long long WI4MPI_Win_lock_all_timeout;
void (*_LOCAL_MPI_Win_lock_all)(int *, int *, int *);

void A_f_MPI_Win_lock_all(int *assert, int *win, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Win_lock_all\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Win_lock_all_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int assert_tmp;
  int win_tmp;
  win_assert_mode_a2r(assert, &assert_tmp);
  fwin_a2r(win, &win_tmp);
  _LOCAL_MPI_Win_lock_all(&assert_tmp, &win_tmp, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Win_lock_all\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_win_unlock_all_(int *, int *);

void mpi_win_unlock_all__(int *, int *);

void pmpi_win_unlock_all_(int *, int *);

void pmpi_win_unlock_all__(int *, int *);

void pmpi_win_unlock_all_(int *, int *);

#define A_f_MPI_Win_unlock_all _PMPI_Win_unlock_all
#pragma weak mpi_win_unlock_all_ = _PMPI_Win_unlock_all
#pragma weak mpi_win_unlock_all__ = _PMPI_Win_unlock_all
#pragma weak pmpi_win_unlock_all__ = _PMPI_Win_unlock_all
extern long long WI4MPI_Win_unlock_all_timeout;
void (*_LOCAL_MPI_Win_unlock_all)(int *, int *);

void A_f_MPI_Win_unlock_all(int *win, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Win_unlock_all\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Win_unlock_all_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int win_tmp;
  fwin_a2r(win, &win_tmp);
  _LOCAL_MPI_Win_unlock_all(&win_tmp, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Win_unlock_all\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_win_flush_(int *, int *, int *);

void mpi_win_flush__(int *, int *, int *);

void pmpi_win_flush_(int *, int *, int *);

void pmpi_win_flush__(int *, int *, int *);

void pmpi_win_flush_(int *, int *, int *);

#define A_f_MPI_Win_flush _PMPI_Win_flush
#pragma weak mpi_win_flush_ = _PMPI_Win_flush
#pragma weak mpi_win_flush__ = _PMPI_Win_flush
#pragma weak pmpi_win_flush__ = _PMPI_Win_flush
extern long long WI4MPI_Win_flush_timeout;
void (*_LOCAL_MPI_Win_flush)(int *, int *, int *);

void A_f_MPI_Win_flush(int *rank, int *win, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Win_flush\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Win_flush_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int rank_tmp;
  int win_tmp;
  rank_mapper_a2r(rank, &rank_tmp);
  fwin_a2r(win, &win_tmp);
  _LOCAL_MPI_Win_flush(&rank_tmp, &win_tmp, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Win_flush\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_win_flush_all_(int *, int *);

void mpi_win_flush_all__(int *, int *);

void pmpi_win_flush_all_(int *, int *);

void pmpi_win_flush_all__(int *, int *);

void pmpi_win_flush_all_(int *, int *);

#define A_f_MPI_Win_flush_all _PMPI_Win_flush_all
#pragma weak mpi_win_flush_all_ = _PMPI_Win_flush_all
#pragma weak mpi_win_flush_all__ = _PMPI_Win_flush_all
#pragma weak pmpi_win_flush_all__ = _PMPI_Win_flush_all
extern long long WI4MPI_Win_flush_all_timeout;
void (*_LOCAL_MPI_Win_flush_all)(int *, int *);

void A_f_MPI_Win_flush_all(int *win, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Win_flush_all\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Win_flush_all_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int win_tmp;
  fwin_a2r(win, &win_tmp);
  _LOCAL_MPI_Win_flush_all(&win_tmp, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Win_flush_all\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_win_flush_local_(int *, int *, int *);

void mpi_win_flush_local__(int *, int *, int *);

void pmpi_win_flush_local_(int *, int *, int *);

void pmpi_win_flush_local__(int *, int *, int *);

void pmpi_win_flush_local_(int *, int *, int *);

#define A_f_MPI_Win_flush_local _PMPI_Win_flush_local
#pragma weak mpi_win_flush_local_ = _PMPI_Win_flush_local
#pragma weak mpi_win_flush_local__ = _PMPI_Win_flush_local
#pragma weak pmpi_win_flush_local__ = _PMPI_Win_flush_local
extern long long WI4MPI_Win_flush_local_timeout;
void (*_LOCAL_MPI_Win_flush_local)(int *, int *, int *);

void A_f_MPI_Win_flush_local(int *rank, int *win, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Win_flush_local\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Win_flush_local_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int rank_tmp;
  int win_tmp;
  rank_mapper_a2r(rank, &rank_tmp);
  fwin_a2r(win, &win_tmp);
  _LOCAL_MPI_Win_flush_local(&rank_tmp, &win_tmp, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Win_flush_local\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_win_flush_local_all_(int *, int *);

void mpi_win_flush_local_all__(int *, int *);

void pmpi_win_flush_local_all_(int *, int *);

void pmpi_win_flush_local_all__(int *, int *);

void pmpi_win_flush_local_all_(int *, int *);

#define A_f_MPI_Win_flush_local_all _PMPI_Win_flush_local_all
#pragma weak mpi_win_flush_local_all_ = _PMPI_Win_flush_local_all
#pragma weak mpi_win_flush_local_all__ = _PMPI_Win_flush_local_all
#pragma weak pmpi_win_flush_local_all__ = _PMPI_Win_flush_local_all
extern long long WI4MPI_Win_flush_local_all_timeout;
void (*_LOCAL_MPI_Win_flush_local_all)(int *, int *);

void A_f_MPI_Win_flush_local_all(int *win, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Win_flush_local_all\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Win_flush_local_all_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int win_tmp;
  fwin_a2r(win, &win_tmp);
  _LOCAL_MPI_Win_flush_local_all(&win_tmp, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Win_flush_local_all\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_win_sync_(int *, int *);

void mpi_win_sync__(int *, int *);

void pmpi_win_sync_(int *, int *);

void pmpi_win_sync__(int *, int *);

void pmpi_win_sync_(int *, int *);

#define A_f_MPI_Win_sync _PMPI_Win_sync
#pragma weak mpi_win_sync_ = _PMPI_Win_sync
#pragma weak mpi_win_sync__ = _PMPI_Win_sync
#pragma weak pmpi_win_sync__ = _PMPI_Win_sync
extern long long WI4MPI_Win_sync_timeout;
void (*_LOCAL_MPI_Win_sync)(int *, int *);

void A_f_MPI_Win_sync(int *win, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Win_sync\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Win_sync_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int win_tmp;
  fwin_a2r(win, &win_tmp);
  _LOCAL_MPI_Win_sync(&win_tmp, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Win_sync\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_add_error_class_(int *, int *);

void mpi_add_error_class__(int *, int *);

void pmpi_add_error_class_(int *, int *);

void pmpi_add_error_class__(int *, int *);

void pmpi_add_error_class_(int *, int *);

#define A_f_MPI_Add_error_class _PMPI_Add_error_class
#pragma weak mpi_add_error_class_ = _PMPI_Add_error_class
#pragma weak mpi_add_error_class__ = _PMPI_Add_error_class
#pragma weak pmpi_add_error_class__ = _PMPI_Add_error_class
extern long long WI4MPI_Add_error_class_timeout;
void (*_LOCAL_MPI_Add_error_class)(int *, int *);

void A_f_MPI_Add_error_class(int *errorclass, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Add_error_class\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Add_error_class_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int errorclass_tmp;
  _LOCAL_MPI_Add_error_class(&errorclass_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    error_r2a(errorclass, &errorclass_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Add_error_class\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_add_error_code_(int *, int *, int *);

void mpi_add_error_code__(int *, int *, int *);

void pmpi_add_error_code_(int *, int *, int *);

void pmpi_add_error_code__(int *, int *, int *);

void pmpi_add_error_code_(int *, int *, int *);

#define A_f_MPI_Add_error_code _PMPI_Add_error_code
#pragma weak mpi_add_error_code_ = _PMPI_Add_error_code
#pragma weak mpi_add_error_code__ = _PMPI_Add_error_code
#pragma weak pmpi_add_error_code__ = _PMPI_Add_error_code
extern long long WI4MPI_Add_error_code_timeout;
void (*_LOCAL_MPI_Add_error_code)(int *, int *, int *);

void A_f_MPI_Add_error_code(int *errorclass, int *errorcode, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Add_error_code\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Add_error_code_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int errorcode_tmp;
  _LOCAL_MPI_Add_error_code(errorclass, &errorcode_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    error_r2a(errorcode, &errorcode_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Add_error_code\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_comm_call_errhandler_(int *, int *, int *);

void mpi_comm_call_errhandler__(int *, int *, int *);

void pmpi_comm_call_errhandler_(int *, int *, int *);

void pmpi_comm_call_errhandler__(int *, int *, int *);

void pmpi_comm_call_errhandler_(int *, int *, int *);

#define A_f_MPI_Comm_call_errhandler _PMPI_Comm_call_errhandler
#pragma weak mpi_comm_call_errhandler_ = _PMPI_Comm_call_errhandler
#pragma weak mpi_comm_call_errhandler__ = _PMPI_Comm_call_errhandler
#pragma weak pmpi_comm_call_errhandler__ = _PMPI_Comm_call_errhandler
extern long long WI4MPI_Comm_call_errhandler_timeout;
void (*_LOCAL_MPI_Comm_call_errhandler)(int *, int *, int *);

void A_f_MPI_Comm_call_errhandler(int *comm, int *errorcode, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Comm_call_errhandler\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Comm_call_errhandler_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  int errorcode_tmp;
  comm_a2r(comm, &comm_tmp);
  error_a2r(errorcode, &errorcode_tmp);
  _LOCAL_MPI_Comm_call_errhandler(&comm_tmp, &errorcode_tmp, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Comm_call_errhandler\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_comm_delete_attr_(int *, int *, int *);

void mpi_comm_delete_attr__(int *, int *, int *);

void pmpi_comm_delete_attr_(int *, int *, int *);

void pmpi_comm_delete_attr__(int *, int *, int *);

void pmpi_comm_delete_attr_(int *, int *, int *);

#define A_f_MPI_Comm_delete_attr _PMPI_Comm_delete_attr
#pragma weak mpi_comm_delete_attr_ = _PMPI_Comm_delete_attr
#pragma weak mpi_comm_delete_attr__ = _PMPI_Comm_delete_attr
#pragma weak pmpi_comm_delete_attr__ = _PMPI_Comm_delete_attr
extern long long WI4MPI_Comm_delete_attr_timeout;
void (*_LOCAL_MPI_Comm_delete_attr)(int *, int *, int *);

void A_f_MPI_Comm_delete_attr(int *comm, int *comm_keyval, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Comm_delete_attr\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Comm_delete_attr_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  int comm_keyval_tmp;
  comm_a2r(comm, &comm_tmp);
  keyval_a2r(comm_keyval, &comm_keyval_tmp);
  _LOCAL_MPI_Comm_delete_attr(&comm_tmp, &comm_keyval_tmp, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Comm_delete_attr\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_comm_get_attr_(int *, int *, void *, int *, int *);

void mpi_comm_get_attr__(int *, int *, void *, int *, int *);

void pmpi_comm_get_attr_(int *, int *, void *, int *, int *);

void pmpi_comm_get_attr__(int *, int *, void *, int *, int *);

void pmpi_comm_get_attr_(int *, int *, void *, int *, int *);

#define A_f_MPI_Comm_get_attr _PMPI_Comm_get_attr
#pragma weak mpi_comm_get_attr_ = _PMPI_Comm_get_attr
#pragma weak mpi_comm_get_attr__ = _PMPI_Comm_get_attr
#pragma weak pmpi_comm_get_attr__ = _PMPI_Comm_get_attr
extern long long WI4MPI_Comm_get_attr_timeout;
void (*_LOCAL_MPI_Comm_get_attr)(int *, int *, void *, int *, int *);

void A_f_MPI_Comm_get_attr(int *comm, int *comm_keyval, void *attribute_val,
                           int *flag, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Comm_get_attr\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Comm_get_attr_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  int comm_keyval_tmp;
  void *attribute_val_tmp = attribute_val;
  comm_a2r(comm, &comm_tmp);
  keyval_a2r(comm_keyval, &comm_keyval_tmp);
  _LOCAL_MPI_Comm_get_attr(&comm_tmp, &comm_keyval_tmp, attribute_val_tmp, flag,
                           &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&attribute_val, &attribute_val_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Comm_get_attr\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_comm_set_attr_(int *, int *, void *, int *);

void mpi_comm_set_attr__(int *, int *, void *, int *);

void pmpi_comm_set_attr_(int *, int *, void *, int *);

void pmpi_comm_set_attr__(int *, int *, void *, int *);

void pmpi_comm_set_attr_(int *, int *, void *, int *);

#define A_f_MPI_Comm_set_attr _PMPI_Comm_set_attr
#pragma weak mpi_comm_set_attr_ = _PMPI_Comm_set_attr
#pragma weak mpi_comm_set_attr__ = _PMPI_Comm_set_attr
#pragma weak pmpi_comm_set_attr__ = _PMPI_Comm_set_attr
extern long long WI4MPI_Comm_set_attr_timeout;
void (*_LOCAL_MPI_Comm_set_attr)(int *, int *, void *, int *);

void A_f_MPI_Comm_set_attr(int *comm, int *comm_keyval, void *attribute_val,
                           int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Comm_set_attr\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Comm_set_attr_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  int comm_keyval_tmp;
  void *attribute_val_tmp = attribute_val;
  comm_a2r(comm, &comm_tmp);
  keyval_a2r(comm_keyval, &comm_keyval_tmp);
  buffer_a2r(&attribute_val, &attribute_val_tmp);
  _LOCAL_MPI_Comm_set_attr(&comm_tmp, &comm_keyval_tmp, attribute_val_tmp,
                           &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Comm_set_attr\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_init_thread_(int *, int *, int *);

void mpi_init_thread__(int *, int *, int *);

void pmpi_init_thread_(int *, int *, int *);

void pmpi_init_thread__(int *, int *, int *);

void pmpi_init_thread_(int *, int *, int *);

#define A_f_MPI_Init_thread _PMPI_Init_thread
#pragma weak mpi_init_thread_ = _PMPI_Init_thread
#pragma weak mpi_init_thread__ = _PMPI_Init_thread
#pragma weak pmpi_init_thread__ = _PMPI_Init_thread
extern long long WI4MPI_Init_thread_timeout;
void (*_LOCAL_MPI_Init_thread)(int *, int *, int *);

void A_f_MPI_Init_thread(int *required, int *provided, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Init_thread\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Init_thread_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_Init_thread(required, provided, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Init_thread\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_is_thread_main_(int *, int *);

void mpi_is_thread_main__(int *, int *);

void pmpi_is_thread_main_(int *, int *);

void pmpi_is_thread_main__(int *, int *);

void pmpi_is_thread_main_(int *, int *);

#define A_f_MPI_Is_thread_main _PMPI_Is_thread_main
#pragma weak mpi_is_thread_main_ = _PMPI_Is_thread_main
#pragma weak mpi_is_thread_main__ = _PMPI_Is_thread_main
#pragma weak pmpi_is_thread_main__ = _PMPI_Is_thread_main
extern long long WI4MPI_Is_thread_main_timeout;
void (*_LOCAL_MPI_Is_thread_main)(int *, int *);

void A_f_MPI_Is_thread_main(int *flag, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Is_thread_main\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Is_thread_main_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_Is_thread_main(flag, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Is_thread_main\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_query_thread_(int *, int *);

void mpi_query_thread__(int *, int *);

void pmpi_query_thread_(int *, int *);

void pmpi_query_thread__(int *, int *);

void pmpi_query_thread_(int *, int *);

#define A_f_MPI_Query_thread _PMPI_Query_thread
#pragma weak mpi_query_thread_ = _PMPI_Query_thread
#pragma weak mpi_query_thread__ = _PMPI_Query_thread
#pragma weak pmpi_query_thread__ = _PMPI_Query_thread
extern long long WI4MPI_Query_thread_timeout;
void (*_LOCAL_MPI_Query_thread)(int *, int *);

void A_f_MPI_Query_thread(int *provided, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Query_thread\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Query_thread_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_Query_thread(provided, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Query_thread\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_status_set_cancelled_(int *, int *, int *);

void mpi_status_set_cancelled__(int *, int *, int *);

void pmpi_status_set_cancelled_(int *, int *, int *);

void pmpi_status_set_cancelled__(int *, int *, int *);

void pmpi_status_set_cancelled_(int *, int *, int *);

#define A_f_MPI_Status_set_cancelled _PMPI_Status_set_cancelled
#pragma weak mpi_status_set_cancelled_ = _PMPI_Status_set_cancelled
#pragma weak mpi_status_set_cancelled__ = _PMPI_Status_set_cancelled
#pragma weak pmpi_status_set_cancelled__ = _PMPI_Status_set_cancelled
extern long long WI4MPI_Status_set_cancelled_timeout;
void (*_LOCAL_MPI_Status_set_cancelled)(int *, int *, int *);

void A_f_MPI_Status_set_cancelled(int *status, int *flag, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Status_set_cancelled\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Status_set_cancelled_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int status_tmp1[R_f_MPI_STATUS_SIZE + 1];
  int *status_tmp =
      (status == A_f_MPI_STATUS_IGNORE ? R_f_MPI_STATUS_IGNORE : status_tmp1);
  status_a2r(status, status_tmp);
  _LOCAL_MPI_Status_set_cancelled(status_tmp, flag, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Status_set_cancelled\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_status_set_elements_(int *, int *, int *, int *);

void mpi_status_set_elements__(int *, int *, int *, int *);

void pmpi_status_set_elements_(int *, int *, int *, int *);

void pmpi_status_set_elements__(int *, int *, int *, int *);

void pmpi_status_set_elements_(int *, int *, int *, int *);

#define A_f_MPI_Status_set_elements _PMPI_Status_set_elements
#pragma weak mpi_status_set_elements_ = _PMPI_Status_set_elements
#pragma weak mpi_status_set_elements__ = _PMPI_Status_set_elements
#pragma weak pmpi_status_set_elements__ = _PMPI_Status_set_elements
extern long long WI4MPI_Status_set_elements_timeout;
void (*_LOCAL_MPI_Status_set_elements)(int *, int *, int *, int *);

void A_f_MPI_Status_set_elements(int *status, int *datatype, int *count,
                                 int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Status_set_elements\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Status_set_elements_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int status_tmp1[R_f_MPI_STATUS_SIZE + 1];
  int *status_tmp =
      (status == A_f_MPI_STATUS_IGNORE ? R_f_MPI_STATUS_IGNORE : status_tmp1);
  int datatype_tmp;
  status_a2r(status, status_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_Status_set_elements(status_tmp, &datatype_tmp, count, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Status_set_elements\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_type_delete_attr_(int *, int *, int *);

void mpi_type_delete_attr__(int *, int *, int *);

void pmpi_type_delete_attr_(int *, int *, int *);

void pmpi_type_delete_attr__(int *, int *, int *);

void pmpi_type_delete_attr_(int *, int *, int *);

#define A_f_MPI_Type_delete_attr _PMPI_Type_delete_attr
#pragma weak mpi_type_delete_attr_ = _PMPI_Type_delete_attr
#pragma weak mpi_type_delete_attr__ = _PMPI_Type_delete_attr
#pragma weak pmpi_type_delete_attr__ = _PMPI_Type_delete_attr
extern long long WI4MPI_Type_delete_attr_timeout;
void (*_LOCAL_MPI_Type_delete_attr)(int *, int *, int *);

void A_f_MPI_Type_delete_attr(int *datatype, int *type_keyval, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Type_delete_attr\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Type_delete_attr_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int datatype_tmp;
  int type_keyval_tmp;
  datatype_a2r(datatype, &datatype_tmp);
  keyval_a2r(type_keyval, &type_keyval_tmp);
  _LOCAL_MPI_Type_delete_attr(&datatype_tmp, &type_keyval_tmp, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Type_delete_attr\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_type_dup_(int *, int *, int *);

void mpi_type_dup__(int *, int *, int *);

void pmpi_type_dup_(int *, int *, int *);

void pmpi_type_dup__(int *, int *, int *);

void pmpi_type_dup_(int *, int *, int *);

#define A_f_MPI_Type_dup _PMPI_Type_dup
#pragma weak mpi_type_dup_ = _PMPI_Type_dup
#pragma weak mpi_type_dup__ = _PMPI_Type_dup
#pragma weak pmpi_type_dup__ = _PMPI_Type_dup
extern long long WI4MPI_Type_dup_timeout;
void (*_LOCAL_MPI_Type_dup)(int *, int *, int *);

void A_f_MPI_Type_dup(int *oldtype, int *newtype, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Type_dup\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Type_dup_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int oldtype_tmp;
  int newtype_tmp;
  datatype_a2r(oldtype, &oldtype_tmp);
  _LOCAL_MPI_Type_dup(&oldtype_tmp, &newtype_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    datatype_r2a(newtype, &newtype_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Type_dup\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_type_free_keyval_(int *, int *);

void mpi_type_free_keyval__(int *, int *);

void pmpi_type_free_keyval_(int *, int *);

void pmpi_type_free_keyval__(int *, int *);

void pmpi_type_free_keyval_(int *, int *);

#define A_f_MPI_Type_free_keyval _PMPI_Type_free_keyval
#pragma weak mpi_type_free_keyval_ = _PMPI_Type_free_keyval
#pragma weak mpi_type_free_keyval__ = _PMPI_Type_free_keyval
#pragma weak pmpi_type_free_keyval__ = _PMPI_Type_free_keyval
extern long long WI4MPI_Type_free_keyval_timeout;
void (*_LOCAL_MPI_Type_free_keyval)(int *, int *);

void A_f_MPI_Type_free_keyval(int *type_keyval, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Type_free_keyval\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Type_free_keyval_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int type_keyval_tmp;
  keyval_a2r(type_keyval, &type_keyval_tmp);
  _LOCAL_MPI_Type_free_keyval(&type_keyval_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    keyval_r2a(type_keyval, &type_keyval_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Type_free_keyval\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_type_get_attr_(int *, int *, void *, int *, int *);

void mpi_type_get_attr__(int *, int *, void *, int *, int *);

void pmpi_type_get_attr_(int *, int *, void *, int *, int *);

void pmpi_type_get_attr__(int *, int *, void *, int *, int *);

void pmpi_type_get_attr_(int *, int *, void *, int *, int *);

#define A_f_MPI_Type_get_attr _PMPI_Type_get_attr
#pragma weak mpi_type_get_attr_ = _PMPI_Type_get_attr
#pragma weak mpi_type_get_attr__ = _PMPI_Type_get_attr
#pragma weak pmpi_type_get_attr__ = _PMPI_Type_get_attr
extern long long WI4MPI_Type_get_attr_timeout;
void (*_LOCAL_MPI_Type_get_attr)(int *, int *, void *, int *, int *);

void A_f_MPI_Type_get_attr(int *datatype, int *type_keyval, void *attribute_val,
                           int *flag, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Type_get_attr\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Type_get_attr_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int datatype_tmp;
  int type_keyval_tmp;
  void *attribute_val_tmp = attribute_val;
  datatype_a2r(datatype, &datatype_tmp);
  keyval_a2r(type_keyval, &type_keyval_tmp);
  _LOCAL_MPI_Type_get_attr(&datatype_tmp, &type_keyval_tmp, attribute_val_tmp,
                           flag, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&attribute_val, &attribute_val_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Type_get_attr\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_type_get_envelope_(int *, int *, int *, int *, int *, int *);

void mpi_type_get_envelope__(int *, int *, int *, int *, int *, int *);

void pmpi_type_get_envelope_(int *, int *, int *, int *, int *, int *);

void pmpi_type_get_envelope__(int *, int *, int *, int *, int *, int *);

void pmpi_type_get_envelope_(int *, int *, int *, int *, int *, int *);

#define A_f_MPI_Type_get_envelope _PMPI_Type_get_envelope
#pragma weak mpi_type_get_envelope_ = _PMPI_Type_get_envelope
#pragma weak mpi_type_get_envelope__ = _PMPI_Type_get_envelope
#pragma weak pmpi_type_get_envelope__ = _PMPI_Type_get_envelope
extern long long WI4MPI_Type_get_envelope_timeout;
void (*_LOCAL_MPI_Type_get_envelope)(int *, int *, int *, int *, int *, int *);

void A_f_MPI_Type_get_envelope(int *datatype, int *num_integers,
                               int *num_addresses, int *num_datatypes,
                               int *combiner, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Type_get_envelope\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Type_get_envelope_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int datatype_tmp;
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_Type_get_envelope(&datatype_tmp, num_integers, num_addresses,
                               num_datatypes, combiner, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Type_get_envelope\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_type_set_attr_(int *, int *, void *, int *);

void mpi_type_set_attr__(int *, int *, void *, int *);

void pmpi_type_set_attr_(int *, int *, void *, int *);

void pmpi_type_set_attr__(int *, int *, void *, int *);

void pmpi_type_set_attr_(int *, int *, void *, int *);

#define A_f_MPI_Type_set_attr _PMPI_Type_set_attr
#pragma weak mpi_type_set_attr_ = _PMPI_Type_set_attr
#pragma weak mpi_type_set_attr__ = _PMPI_Type_set_attr
#pragma weak pmpi_type_set_attr__ = _PMPI_Type_set_attr
extern long long WI4MPI_Type_set_attr_timeout;
void (*_LOCAL_MPI_Type_set_attr)(int *, int *, void *, int *);

void A_f_MPI_Type_set_attr(int *datatype, int *type_keyval, void *attribute_val,
                           int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Type_set_attr\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Type_set_attr_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int datatype_tmp;
  int type_keyval_tmp;
  void *attribute_val_tmp = attribute_val;
  datatype_a2r(datatype, &datatype_tmp);
  keyval_a2r(type_keyval, &type_keyval_tmp);
  buffer_a2r(&attribute_val, &attribute_val_tmp);
  _LOCAL_MPI_Type_set_attr(&datatype_tmp, &type_keyval_tmp, attribute_val_tmp,
                           &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Type_set_attr\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_type_match_size_(int *, int *, int *, int *);

void mpi_type_match_size__(int *, int *, int *, int *);

void pmpi_type_match_size_(int *, int *, int *, int *);

void pmpi_type_match_size__(int *, int *, int *, int *);

void pmpi_type_match_size_(int *, int *, int *, int *);

#define A_f_MPI_Type_match_size _PMPI_Type_match_size
#pragma weak mpi_type_match_size_ = _PMPI_Type_match_size
#pragma weak mpi_type_match_size__ = _PMPI_Type_match_size
#pragma weak pmpi_type_match_size__ = _PMPI_Type_match_size
extern long long WI4MPI_Type_match_size_timeout;
void (*_LOCAL_MPI_Type_match_size)(int *, int *, int *, int *);

void A_f_MPI_Type_match_size(int *typeclass, int *size, int *datatype,
                             int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Type_match_size\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Type_match_size_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int datatype_tmp;
  _LOCAL_MPI_Type_match_size(typeclass, size, &datatype_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    datatype_r2a(datatype, &datatype_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Type_match_size\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_alloc_mem_(size_t *, int *, void *, int *);

void mpi_alloc_mem__(size_t *, int *, void *, int *);

void pmpi_alloc_mem_(size_t *, int *, void *, int *);

void pmpi_alloc_mem__(size_t *, int *, void *, int *);

void pmpi_alloc_mem_(size_t *, int *, void *, int *);

#define A_f_MPI_Alloc_mem _PMPI_Alloc_mem
#pragma weak mpi_alloc_mem_ = _PMPI_Alloc_mem
#pragma weak mpi_alloc_mem__ = _PMPI_Alloc_mem
#pragma weak pmpi_alloc_mem__ = _PMPI_Alloc_mem
extern long long WI4MPI_Alloc_mem_timeout;
void (*_LOCAL_MPI_Alloc_mem)(size_t *, int *, void *, int *);

void A_f_MPI_Alloc_mem(size_t *size, int *info, void *baseptr, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Alloc_mem\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Alloc_mem_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int info_tmp;
  void *baseptr_tmp = baseptr;
  info_a2r(info, &info_tmp);
  _LOCAL_MPI_Alloc_mem(size, &info_tmp, baseptr_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&baseptr, &baseptr_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Alloc_mem\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_comm_create_errhandler_(void *, int *, int *);

void mpi_comm_create_errhandler__(void *, int *, int *);

void pmpi_comm_create_errhandler_(void *, int *, int *);

void pmpi_comm_create_errhandler__(void *, int *, int *);

void pmpi_comm_create_errhandler_(void *, int *, int *);

#define A_f_MPI_Comm_create_errhandler _PMPI_Comm_create_errhandler
#pragma weak mpi_comm_create_errhandler_ = _PMPI_Comm_create_errhandler
#pragma weak mpi_comm_create_errhandler__ = _PMPI_Comm_create_errhandler
#pragma weak pmpi_comm_create_errhandler__ = _PMPI_Comm_create_errhandler
extern long long WI4MPI_Comm_create_errhandler_timeout;
void (*_LOCAL_MPI_Comm_create_errhandler)(void *, int *, int *);

void A_f_MPI_Comm_create_errhandler(void *comm_errhandler_fn, int *errhandler,
                                    int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Comm_create_errhandler\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Comm_create_errhandler_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *comm_errhandler_fn_tmp = comm_errhandler_fn;
  int errhandler_tmp;
  handler_fct_ptr_conv_a2r(&comm_errhandler_fn, &comm_errhandler_fn_tmp);
  _LOCAL_MPI_Comm_create_errhandler(comm_errhandler_fn_tmp, &errhandler_tmp,
                                    &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    errhandler_converter_r2a(errhandler, &errhandler_tmp);
  errhandler_f_fn_translation_update(errhandler_tmp, comm_errhandler_fn);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Comm_create_errhandler\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_comm_get_errhandler_(int *, int *, int *);

void mpi_comm_get_errhandler__(int *, int *, int *);

void pmpi_comm_get_errhandler_(int *, int *, int *);

void pmpi_comm_get_errhandler__(int *, int *, int *);

void pmpi_comm_get_errhandler_(int *, int *, int *);

#define A_f_MPI_Comm_get_errhandler _PMPI_Comm_get_errhandler
#pragma weak mpi_comm_get_errhandler_ = _PMPI_Comm_get_errhandler
#pragma weak mpi_comm_get_errhandler__ = _PMPI_Comm_get_errhandler
#pragma weak pmpi_comm_get_errhandler__ = _PMPI_Comm_get_errhandler
extern long long WI4MPI_Comm_get_errhandler_timeout;
void (*_LOCAL_MPI_Comm_get_errhandler)(int *, int *, int *);

void A_f_MPI_Comm_get_errhandler(int *comm, int *errhandler, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Comm_get_errhandler\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Comm_get_errhandler_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  int errhandler_tmp;
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Comm_get_errhandler(&comm_tmp, &errhandler_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    errhandler_converter_r2a(errhandler, &errhandler_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Comm_get_errhandler\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_comm_set_errhandler_(int *, int *, int *);

void mpi_comm_set_errhandler__(int *, int *, int *);

void pmpi_comm_set_errhandler_(int *, int *, int *);

void pmpi_comm_set_errhandler__(int *, int *, int *);

void pmpi_comm_set_errhandler_(int *, int *, int *);

#define A_f_MPI_Comm_set_errhandler _PMPI_Comm_set_errhandler
#pragma weak mpi_comm_set_errhandler_ = _PMPI_Comm_set_errhandler
#pragma weak mpi_comm_set_errhandler__ = _PMPI_Comm_set_errhandler
#pragma weak pmpi_comm_set_errhandler__ = _PMPI_Comm_set_errhandler
extern long long WI4MPI_Comm_set_errhandler_timeout;
void (*_LOCAL_MPI_Comm_set_errhandler)(int *, int *, int *);

void A_f_MPI_Comm_set_errhandler(int *comm, int *errhandler, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Comm_set_errhandler\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Comm_set_errhandler_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  int errhandler_tmp;
  comm_a2r(comm, &comm_tmp);
  errhandler_converter_a2r(errhandler, &errhandler_tmp);
  _LOCAL_MPI_Comm_set_errhandler(&comm_tmp, &errhandler_tmp, &ret_tmp);
  errhandler_set_func(comm_tmp, errhandler_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Comm_set_errhandler\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_get_errhandler_(int *, int *, int *);

void mpi_file_get_errhandler__(int *, int *, int *);

void pmpi_file_get_errhandler_(int *, int *, int *);

void pmpi_file_get_errhandler__(int *, int *, int *);

void pmpi_file_get_errhandler_(int *, int *, int *);

#define A_f_MPI_File_get_errhandler _PMPI_File_get_errhandler
#pragma weak mpi_file_get_errhandler_ = _PMPI_File_get_errhandler
#pragma weak mpi_file_get_errhandler__ = _PMPI_File_get_errhandler
#pragma weak pmpi_file_get_errhandler__ = _PMPI_File_get_errhandler
extern long long WI4MPI_File_get_errhandler_timeout;
void (*_LOCAL_MPI_File_get_errhandler)(int *, int *, int *);

void A_f_MPI_File_get_errhandler(int *file, int *errhandler, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_get_errhandler\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_get_errhandler_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int errhandler_tmp;
  _LOCAL_MPI_File_get_errhandler(file, &errhandler_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    errhandler_converter_r2a(errhandler, &errhandler_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_get_errhandler\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_set_errhandler_(int *, int *, int *);

void mpi_file_set_errhandler__(int *, int *, int *);

void pmpi_file_set_errhandler_(int *, int *, int *);

void pmpi_file_set_errhandler__(int *, int *, int *);

void pmpi_file_set_errhandler_(int *, int *, int *);

#define A_f_MPI_File_set_errhandler _PMPI_File_set_errhandler
#pragma weak mpi_file_set_errhandler_ = _PMPI_File_set_errhandler
#pragma weak mpi_file_set_errhandler__ = _PMPI_File_set_errhandler
#pragma weak pmpi_file_set_errhandler__ = _PMPI_File_set_errhandler
extern long long WI4MPI_File_set_errhandler_timeout;
void (*_LOCAL_MPI_File_set_errhandler)(int *, int *, int *);

void A_f_MPI_File_set_errhandler(int *file, int *errhandler, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_set_errhandler\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_set_errhandler_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int errhandler_tmp;
  errhandler_converter_a2r(errhandler, &errhandler_tmp);
  _LOCAL_MPI_File_set_errhandler(file, &errhandler_tmp, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_set_errhandler\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_finalized_(int *, int *);

void mpi_finalized__(int *, int *);

void pmpi_finalized_(int *, int *);

void pmpi_finalized__(int *, int *);

void pmpi_finalized_(int *, int *);

#define A_f_MPI_Finalized _PMPI_Finalized
#pragma weak mpi_finalized_ = _PMPI_Finalized
#pragma weak mpi_finalized__ = _PMPI_Finalized
#pragma weak pmpi_finalized__ = _PMPI_Finalized
extern long long WI4MPI_Finalized_timeout;
void (*_LOCAL_MPI_Finalized)(int *, int *);

void A_f_MPI_Finalized(int *flag, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Finalized\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Finalized_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_Finalized(flag, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Finalized\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_free_mem_(void *, int *);

void mpi_free_mem__(void *, int *);

void pmpi_free_mem_(void *, int *);

void pmpi_free_mem__(void *, int *);

void pmpi_free_mem_(void *, int *);

#define A_f_MPI_Free_mem _PMPI_Free_mem
#pragma weak mpi_free_mem_ = _PMPI_Free_mem
#pragma weak mpi_free_mem__ = _PMPI_Free_mem
#pragma weak pmpi_free_mem__ = _PMPI_Free_mem
extern long long WI4MPI_Free_mem_timeout;
void (*_LOCAL_MPI_Free_mem)(void *, int *);

void A_f_MPI_Free_mem(void *base, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Free_mem\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Free_mem_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *base_tmp = base;
  buffer_a2r(&base, &base_tmp);
  _LOCAL_MPI_Free_mem(base_tmp, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Free_mem\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_get_address_(void *, size_t *, int *);

void mpi_get_address__(void *, size_t *, int *);

void pmpi_get_address_(void *, size_t *, int *);

void pmpi_get_address__(void *, size_t *, int *);

void pmpi_get_address_(void *, size_t *, int *);

#define A_f_MPI_Get_address _PMPI_Get_address
#pragma weak mpi_get_address_ = _PMPI_Get_address
#pragma weak mpi_get_address__ = _PMPI_Get_address
#pragma weak pmpi_get_address__ = _PMPI_Get_address
extern long long WI4MPI_Get_address_timeout;
void (*_LOCAL_MPI_Get_address)(void *, size_t *, int *);

void A_f_MPI_Get_address(void *location, size_t *address, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Get_address\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Get_address_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *location_tmp = location;
  buffer_a2r(&location, &location_tmp);
  _LOCAL_MPI_Get_address(location_tmp, address, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Get_address\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_info_create_(int *, int *);

void mpi_info_create__(int *, int *);

void pmpi_info_create_(int *, int *);

void pmpi_info_create__(int *, int *);

void pmpi_info_create_(int *, int *);

#define A_f_MPI_Info_create _PMPI_Info_create
#pragma weak mpi_info_create_ = _PMPI_Info_create
#pragma weak mpi_info_create__ = _PMPI_Info_create
#pragma weak pmpi_info_create__ = _PMPI_Info_create
extern long long WI4MPI_Info_create_timeout;
void (*_LOCAL_MPI_Info_create)(int *, int *);

void A_f_MPI_Info_create(int *info, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Info_create\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Info_create_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int info_tmp;
  _LOCAL_MPI_Info_create(&info_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    info_r2a(info, &info_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Info_create\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_info_dup_(int *, int *, int *);

void mpi_info_dup__(int *, int *, int *);

void pmpi_info_dup_(int *, int *, int *);

void pmpi_info_dup__(int *, int *, int *);

void pmpi_info_dup_(int *, int *, int *);

#define A_f_MPI_Info_dup _PMPI_Info_dup
#pragma weak mpi_info_dup_ = _PMPI_Info_dup
#pragma weak mpi_info_dup__ = _PMPI_Info_dup
#pragma weak pmpi_info_dup__ = _PMPI_Info_dup
extern long long WI4MPI_Info_dup_timeout;
void (*_LOCAL_MPI_Info_dup)(int *, int *, int *);

void A_f_MPI_Info_dup(int *info, int *newinfo, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Info_dup\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Info_dup_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int info_tmp;
  int newinfo_tmp;
  info_a2r(info, &info_tmp);
  _LOCAL_MPI_Info_dup(&info_tmp, &newinfo_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    info_r2a(newinfo, &newinfo_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Info_dup\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_info_free_(int *, int *);

void mpi_info_free__(int *, int *);

void pmpi_info_free_(int *, int *);

void pmpi_info_free__(int *, int *);

void pmpi_info_free_(int *, int *);

#define A_f_MPI_Info_free _PMPI_Info_free
#pragma weak mpi_info_free_ = _PMPI_Info_free
#pragma weak mpi_info_free__ = _PMPI_Info_free
#pragma weak pmpi_info_free__ = _PMPI_Info_free
extern long long WI4MPI_Info_free_timeout;
void (*_LOCAL_MPI_Info_free)(int *, int *);

void A_f_MPI_Info_free(int *info, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Info_free\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Info_free_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int info_tmp;
  info_a2r(info, &info_tmp);
  _LOCAL_MPI_Info_free(&info_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    info_r2a(info, &info_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Info_free\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_info_get_nkeys_(int *, int *, int *);

void mpi_info_get_nkeys__(int *, int *, int *);

void pmpi_info_get_nkeys_(int *, int *, int *);

void pmpi_info_get_nkeys__(int *, int *, int *);

void pmpi_info_get_nkeys_(int *, int *, int *);

#define A_f_MPI_Info_get_nkeys _PMPI_Info_get_nkeys
#pragma weak mpi_info_get_nkeys_ = _PMPI_Info_get_nkeys
#pragma weak mpi_info_get_nkeys__ = _PMPI_Info_get_nkeys
#pragma weak pmpi_info_get_nkeys__ = _PMPI_Info_get_nkeys
extern long long WI4MPI_Info_get_nkeys_timeout;
void (*_LOCAL_MPI_Info_get_nkeys)(int *, int *, int *);

void A_f_MPI_Info_get_nkeys(int *info, int *nkeys, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Info_get_nkeys\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Info_get_nkeys_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int info_tmp;
  info_a2r(info, &info_tmp);
  _LOCAL_MPI_Info_get_nkeys(&info_tmp, nkeys, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Info_get_nkeys\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_request_get_status_(int *, int *, int *, int *);

void mpi_request_get_status__(int *, int *, int *, int *);

void pmpi_request_get_status_(int *, int *, int *, int *);

void pmpi_request_get_status__(int *, int *, int *, int *);

void pmpi_request_get_status_(int *, int *, int *, int *);

#define A_f_MPI_Request_get_status _PMPI_Request_get_status
#pragma weak mpi_request_get_status_ = _PMPI_Request_get_status
#pragma weak mpi_request_get_status__ = _PMPI_Request_get_status
#pragma weak pmpi_request_get_status__ = _PMPI_Request_get_status
extern long long WI4MPI_Request_get_status_timeout;
void (*_LOCAL_MPI_Request_get_status)(int *, int *, int *, int *);

void A_f_MPI_Request_get_status(int *request, int *flag, int *status,
                                int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Request_get_status\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Request_get_status_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int request_tmp;
  int status_tmp1[R_f_MPI_STATUS_SIZE + 1];
  int *status_tmp =
      (status == A_f_MPI_STATUS_IGNORE ? R_f_MPI_STATUS_IGNORE : status_tmp1);
  request_a2r(request, &request_tmp);
  _LOCAL_MPI_Request_get_status(&request_tmp, flag, status_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    if (status != A_f_MPI_STATUS_IGNORE)
      status_r2a(status, status_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Request_get_status\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_type_create_hvector_(int *, int *, size_t *, int *, int *, int *);

void mpi_type_create_hvector__(int *, int *, size_t *, int *, int *, int *);

void pmpi_type_create_hvector_(int *, int *, size_t *, int *, int *, int *);

void pmpi_type_create_hvector__(int *, int *, size_t *, int *, int *, int *);

void pmpi_type_create_hvector_(int *, int *, size_t *, int *, int *, int *);

#define A_f_MPI_Type_create_hvector _PMPI_Type_create_hvector
#pragma weak mpi_type_create_hvector_ = _PMPI_Type_create_hvector
#pragma weak mpi_type_create_hvector__ = _PMPI_Type_create_hvector
#pragma weak pmpi_type_create_hvector__ = _PMPI_Type_create_hvector
extern long long WI4MPI_Type_create_hvector_timeout;
void (*_LOCAL_MPI_Type_create_hvector)(int *, int *, size_t *, int *, int *,
                                       int *);

void A_f_MPI_Type_create_hvector(int *count, int *blocklength, size_t *stride,
                                 int *oldtype, int *newtype, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Type_create_hvector\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Type_create_hvector_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int oldtype_tmp;
  int newtype_tmp;
  datatype_a2r(oldtype, &oldtype_tmp);
  _LOCAL_MPI_Type_create_hvector(count, blocklength, stride, &oldtype_tmp,
                                 &newtype_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    datatype_r2a(newtype, &newtype_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Type_create_hvector\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_type_create_resized_(int *, size_t *, size_t *, int *, int *);

void mpi_type_create_resized__(int *, size_t *, size_t *, int *, int *);

void pmpi_type_create_resized_(int *, size_t *, size_t *, int *, int *);

void pmpi_type_create_resized__(int *, size_t *, size_t *, int *, int *);

void pmpi_type_create_resized_(int *, size_t *, size_t *, int *, int *);

#define A_f_MPI_Type_create_resized _PMPI_Type_create_resized
#pragma weak mpi_type_create_resized_ = _PMPI_Type_create_resized
#pragma weak mpi_type_create_resized__ = _PMPI_Type_create_resized
#pragma weak pmpi_type_create_resized__ = _PMPI_Type_create_resized
extern long long WI4MPI_Type_create_resized_timeout;
void (*_LOCAL_MPI_Type_create_resized)(int *, size_t *, size_t *, int *, int *);

void A_f_MPI_Type_create_resized(int *oldtype, size_t *lb, size_t *extent,
                                 int *newtype, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Type_create_resized\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Type_create_resized_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int oldtype_tmp;
  int newtype_tmp;
  datatype_a2r(oldtype, &oldtype_tmp);
  _LOCAL_MPI_Type_create_resized(&oldtype_tmp, lb, extent, &newtype_tmp,
                                 &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    datatype_r2a(newtype, &newtype_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Type_create_resized\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_type_get_extent_(int *, size_t *, size_t *, int *);

void mpi_type_get_extent__(int *, size_t *, size_t *, int *);

void pmpi_type_get_extent_(int *, size_t *, size_t *, int *);

void pmpi_type_get_extent__(int *, size_t *, size_t *, int *);

void pmpi_type_get_extent_(int *, size_t *, size_t *, int *);

#define A_f_MPI_Type_get_extent _PMPI_Type_get_extent
#pragma weak mpi_type_get_extent_ = _PMPI_Type_get_extent
#pragma weak mpi_type_get_extent__ = _PMPI_Type_get_extent
#pragma weak pmpi_type_get_extent__ = _PMPI_Type_get_extent
extern long long WI4MPI_Type_get_extent_timeout;
void (*_LOCAL_MPI_Type_get_extent)(int *, size_t *, size_t *, int *);

void A_f_MPI_Type_get_extent(int *datatype, size_t *lb, size_t *extent,
                             int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Type_get_extent\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Type_get_extent_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int datatype_tmp;
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_Type_get_extent(&datatype_tmp, lb, extent, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Type_get_extent\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_type_get_true_extent_(int *, size_t *, size_t *, int *);

void mpi_type_get_true_extent__(int *, size_t *, size_t *, int *);

void pmpi_type_get_true_extent_(int *, size_t *, size_t *, int *);

void pmpi_type_get_true_extent__(int *, size_t *, size_t *, int *);

void pmpi_type_get_true_extent_(int *, size_t *, size_t *, int *);

#define A_f_MPI_Type_get_true_extent _PMPI_Type_get_true_extent
#pragma weak mpi_type_get_true_extent_ = _PMPI_Type_get_true_extent
#pragma weak mpi_type_get_true_extent__ = _PMPI_Type_get_true_extent
#pragma weak pmpi_type_get_true_extent__ = _PMPI_Type_get_true_extent
extern long long WI4MPI_Type_get_true_extent_timeout;
void (*_LOCAL_MPI_Type_get_true_extent)(int *, size_t *, size_t *, int *);

void A_f_MPI_Type_get_true_extent(int *datatype, size_t *true_lb,
                                  size_t *true_extent, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Type_get_true_extent\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Type_get_true_extent_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int datatype_tmp;
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_Type_get_true_extent(&datatype_tmp, true_lb, true_extent,
                                  &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Type_get_true_extent\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_type_create_f90_integer_(int *, int *, int *);

void mpi_type_create_f90_integer__(int *, int *, int *);

void pmpi_type_create_f90_integer_(int *, int *, int *);

void pmpi_type_create_f90_integer__(int *, int *, int *);

void pmpi_type_create_f90_integer_(int *, int *, int *);

#define A_f_MPI_Type_create_f90_integer _PMPI_Type_create_f90_integer
#pragma weak mpi_type_create_f90_integer_ = _PMPI_Type_create_f90_integer
#pragma weak mpi_type_create_f90_integer__ = _PMPI_Type_create_f90_integer
#pragma weak pmpi_type_create_f90_integer__ = _PMPI_Type_create_f90_integer
extern long long WI4MPI_Type_create_f90_integer_timeout;
void (*_LOCAL_MPI_Type_create_f90_integer)(int *, int *, int *);

void A_f_MPI_Type_create_f90_integer(int *range, int *newtype, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Type_create_f90_integer\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Type_create_f90_integer_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int newtype_tmp;
  _LOCAL_MPI_Type_create_f90_integer(range, &newtype_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    datatype_r2a(newtype, &newtype_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Type_create_f90_integer\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_type_create_f90_real_(int *, int *, int *, int *);

void mpi_type_create_f90_real__(int *, int *, int *, int *);

void pmpi_type_create_f90_real_(int *, int *, int *, int *);

void pmpi_type_create_f90_real__(int *, int *, int *, int *);

void pmpi_type_create_f90_real_(int *, int *, int *, int *);

#define A_f_MPI_Type_create_f90_real _PMPI_Type_create_f90_real
#pragma weak mpi_type_create_f90_real_ = _PMPI_Type_create_f90_real
#pragma weak mpi_type_create_f90_real__ = _PMPI_Type_create_f90_real
#pragma weak pmpi_type_create_f90_real__ = _PMPI_Type_create_f90_real
extern long long WI4MPI_Type_create_f90_real_timeout;
void (*_LOCAL_MPI_Type_create_f90_real)(int *, int *, int *, int *);

void A_f_MPI_Type_create_f90_real(int *precision, int *range, int *newtype,
                                  int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Type_create_f90_real\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Type_create_f90_real_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int newtype_tmp;
  _LOCAL_MPI_Type_create_f90_real(precision, range, &newtype_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    datatype_r2a(newtype, &newtype_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Type_create_f90_real\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_type_create_f90_complex_(int *, int *, int *, int *);

void mpi_type_create_f90_complex__(int *, int *, int *, int *);

void pmpi_type_create_f90_complex_(int *, int *, int *, int *);

void pmpi_type_create_f90_complex__(int *, int *, int *, int *);

void pmpi_type_create_f90_complex_(int *, int *, int *, int *);

#define A_f_MPI_Type_create_f90_complex _PMPI_Type_create_f90_complex
#pragma weak mpi_type_create_f90_complex_ = _PMPI_Type_create_f90_complex
#pragma weak mpi_type_create_f90_complex__ = _PMPI_Type_create_f90_complex
#pragma weak pmpi_type_create_f90_complex__ = _PMPI_Type_create_f90_complex
extern long long WI4MPI_Type_create_f90_complex_timeout;
void (*_LOCAL_MPI_Type_create_f90_complex)(int *, int *, int *, int *);

void A_f_MPI_Type_create_f90_complex(int *precision, int *range, int *newtype,
                                     int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Type_create_f90_complex\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Type_create_f90_complex_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int newtype_tmp;
  _LOCAL_MPI_Type_create_f90_complex(precision, range, &newtype_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    datatype_r2a(newtype, &newtype_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Type_create_f90_complex\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_reduce_local_(void *, void *, int *, int *, int *, int *);

void mpi_reduce_local__(void *, void *, int *, int *, int *, int *);

void pmpi_reduce_local_(void *, void *, int *, int *, int *, int *);

void pmpi_reduce_local__(void *, void *, int *, int *, int *, int *);

void pmpi_reduce_local_(void *, void *, int *, int *, int *, int *);

#define A_f_MPI_Reduce_local _PMPI_Reduce_local
#pragma weak mpi_reduce_local_ = _PMPI_Reduce_local
#pragma weak mpi_reduce_local__ = _PMPI_Reduce_local
#pragma weak pmpi_reduce_local__ = _PMPI_Reduce_local
extern long long WI4MPI_Reduce_local_timeout;
void (*_LOCAL_MPI_Reduce_local)(void *, void *, int *, int *, int *, int *);

void A_f_MPI_Reduce_local(void *inbuf, void *inoutbuf, int *count,
                          int *datatype, int *op, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Reduce_local\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Reduce_local_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *inbuf_tmp = inbuf;
  void *inoutbuf_tmp = inoutbuf;
  int datatype_tmp;
  int op_tmp;
  buffer_a2r(&inbuf, &inbuf_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  operator_a2r(op, &op_tmp);
  _LOCAL_MPI_Reduce_local(inbuf_tmp, inoutbuf_tmp, count, &datatype_tmp,
                          &op_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&inoutbuf, &inoutbuf_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Reduce_local\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_op_commutative_(int *, int *, int *);

void mpi_op_commutative__(int *, int *, int *);

void pmpi_op_commutative_(int *, int *, int *);

void pmpi_op_commutative__(int *, int *, int *);

void pmpi_op_commutative_(int *, int *, int *);

#define A_f_MPI_Op_commutative _PMPI_Op_commutative
#pragma weak mpi_op_commutative_ = _PMPI_Op_commutative
#pragma weak mpi_op_commutative__ = _PMPI_Op_commutative
#pragma weak pmpi_op_commutative__ = _PMPI_Op_commutative
extern long long WI4MPI_Op_commutative_timeout;
void (*_LOCAL_MPI_Op_commutative)(int *, int *, int *);

void A_f_MPI_Op_commutative(int *op, int *commute, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Op_commutative\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Op_commutative_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int op_tmp;
  operator_a2r(op, &op_tmp);
  _LOCAL_MPI_Op_commutative(&op_tmp, commute, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Op_commutative\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_reduce_scatter_block_(void *, void *, int *, int *, int *, int *,
                               int *);

void mpi_reduce_scatter_block__(void *, void *, int *, int *, int *, int *,
                                int *);

void pmpi_reduce_scatter_block_(void *, void *, int *, int *, int *, int *,
                                int *);

void pmpi_reduce_scatter_block__(void *, void *, int *, int *, int *, int *,
                                 int *);

void pmpi_reduce_scatter_block_(void *, void *, int *, int *, int *, int *,
                                int *);

#define A_f_MPI_Reduce_scatter_block _PMPI_Reduce_scatter_block
#pragma weak mpi_reduce_scatter_block_ = _PMPI_Reduce_scatter_block
#pragma weak mpi_reduce_scatter_block__ = _PMPI_Reduce_scatter_block
#pragma weak pmpi_reduce_scatter_block__ = _PMPI_Reduce_scatter_block
extern long long WI4MPI_Reduce_scatter_block_timeout;
void (*_LOCAL_MPI_Reduce_scatter_block)(void *, void *, int *, int *, int *,
                                        int *, int *);

void A_f_MPI_Reduce_scatter_block(void *sendbuf, void *recvbuf, int *recvcount,
                                  int *datatype, int *op, int *comm, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Reduce_scatter_block\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Reduce_scatter_block_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *sendbuf_tmp = sendbuf;
  void *recvbuf_tmp = recvbuf;
  int datatype_tmp;
  int op_tmp;
  int comm_tmp;
  buffer_a2r(&sendbuf, &sendbuf_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  operator_a2r(op, &op_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Reduce_scatter_block(sendbuf_tmp, recvbuf_tmp, recvcount,
                                  &datatype_tmp, &op_tmp, &comm_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&recvbuf, &recvbuf_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Reduce_scatter_block\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_dist_graph_neighbors_count_(int *, int *, int *, int *, int *);

void mpi_dist_graph_neighbors_count__(int *, int *, int *, int *, int *);

void pmpi_dist_graph_neighbors_count_(int *, int *, int *, int *, int *);

void pmpi_dist_graph_neighbors_count__(int *, int *, int *, int *, int *);

void pmpi_dist_graph_neighbors_count_(int *, int *, int *, int *, int *);

#define A_f_MPI_Dist_graph_neighbors_count _PMPI_Dist_graph_neighbors_count
#pragma weak mpi_dist_graph_neighbors_count_ = _PMPI_Dist_graph_neighbors_count
#pragma weak mpi_dist_graph_neighbors_count__ = _PMPI_Dist_graph_neighbors_count
#pragma weak pmpi_dist_graph_neighbors_count__ =                               \
    _PMPI_Dist_graph_neighbors_count
extern long long WI4MPI_Dist_graph_neighbors_count_timeout;
void (*_LOCAL_MPI_Dist_graph_neighbors_count)(int *, int *, int *, int *,
                                              int *);

void A_f_MPI_Dist_graph_neighbors_count(int *comm, int *indegree,
                                        int *outdegree, int *weighted,
                                        int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Dist_graph_neighbors_count\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Dist_graph_neighbors_count_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Dist_graph_neighbors_count(&comm_tmp, indegree, outdegree,
                                        weighted, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Dist_graph_neighbors_count\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_improbe_(int *, int *, int *, int *, int *, int *, int *);

void mpi_improbe__(int *, int *, int *, int *, int *, int *, int *);

void pmpi_improbe_(int *, int *, int *, int *, int *, int *, int *);

void pmpi_improbe__(int *, int *, int *, int *, int *, int *, int *);

void pmpi_improbe_(int *, int *, int *, int *, int *, int *, int *);

#define A_f_MPI_Improbe _PMPI_Improbe
#pragma weak mpi_improbe_ = _PMPI_Improbe
#pragma weak mpi_improbe__ = _PMPI_Improbe
#pragma weak pmpi_improbe__ = _PMPI_Improbe
extern long long WI4MPI_Improbe_timeout;
void (*_LOCAL_MPI_Improbe)(int *, int *, int *, int *, int *, int *, int *);

void A_f_MPI_Improbe(int *source, int *tag, int *comm, int *flag, int *message,
                     int *status, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Improbe\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Improbe_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int source_tmp;
  int tag_tmp;
  int comm_tmp;
  int message_tmp;
  int status_tmp1[R_f_MPI_STATUS_SIZE + 1];
  int *status_tmp =
      (status == A_f_MPI_STATUS_IGNORE ? R_f_MPI_STATUS_IGNORE : status_tmp1);
  source_a2r(source, &source_tmp);
  tag_a2r(tag, &tag_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Improbe(&source_tmp, &tag_tmp, &comm_tmp, flag, &message_tmp,
                     status_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    message_r2a(message, &message_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    if (status != A_f_MPI_STATUS_IGNORE)
      status_r2a(status, status_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Improbe\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_imrecv_(void *, int *, int *, int *, int *, int *);

void mpi_imrecv__(void *, int *, int *, int *, int *, int *);

void pmpi_imrecv_(void *, int *, int *, int *, int *, int *);

void pmpi_imrecv__(void *, int *, int *, int *, int *, int *);

void pmpi_imrecv_(void *, int *, int *, int *, int *, int *);

#define A_f_MPI_Imrecv _PMPI_Imrecv
#pragma weak mpi_imrecv_ = _PMPI_Imrecv
#pragma weak mpi_imrecv__ = _PMPI_Imrecv
#pragma weak pmpi_imrecv__ = _PMPI_Imrecv
extern long long WI4MPI_Imrecv_timeout;
void (*_LOCAL_MPI_Imrecv)(void *, int *, int *, int *, int *, int *);

void A_f_MPI_Imrecv(void *buf, int *count, int *datatype, int *message,
                    int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Imrecv\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Imrecv_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  int message_tmp;
  int request_tmp;
  datatype_a2r(datatype, &datatype_tmp);
  message_a2r(message, &message_tmp);
  _LOCAL_MPI_Imrecv(buf_tmp, count, &datatype_tmp, &message_tmp, &request_tmp,
                    &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&buf, &buf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    message_r2a(message, &message_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Imrecv\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_mprobe_(int *, int *, int *, int *, int *, int *);

void mpi_mprobe__(int *, int *, int *, int *, int *, int *);

void pmpi_mprobe_(int *, int *, int *, int *, int *, int *);

void pmpi_mprobe__(int *, int *, int *, int *, int *, int *);

void pmpi_mprobe_(int *, int *, int *, int *, int *, int *);

#define A_f_MPI_Mprobe _PMPI_Mprobe
#pragma weak mpi_mprobe_ = _PMPI_Mprobe
#pragma weak mpi_mprobe__ = _PMPI_Mprobe
#pragma weak pmpi_mprobe__ = _PMPI_Mprobe
extern long long WI4MPI_Mprobe_timeout;
void (*_LOCAL_MPI_Mprobe)(int *, int *, int *, int *, int *, int *);

void A_f_MPI_Mprobe(int *source, int *tag, int *comm, int *message, int *status,
                    int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Mprobe\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Mprobe_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int source_tmp;
  int tag_tmp;
  int comm_tmp;
  int message_tmp;
  int status_tmp1[R_f_MPI_STATUS_SIZE + 1];
  int *status_tmp =
      (status == A_f_MPI_STATUS_IGNORE ? R_f_MPI_STATUS_IGNORE : status_tmp1);
  source_a2r(source, &source_tmp);
  tag_a2r(tag, &tag_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Mprobe(&source_tmp, &tag_tmp, &comm_tmp, &message_tmp, status_tmp,
                    &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    message_r2a(message, &message_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    if (status != A_f_MPI_STATUS_IGNORE)
      status_r2a(status, status_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Mprobe\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_mrecv_(void *, int *, int *, int *, int *, int *);

void mpi_mrecv__(void *, int *, int *, int *, int *, int *);

void pmpi_mrecv_(void *, int *, int *, int *, int *, int *);

void pmpi_mrecv__(void *, int *, int *, int *, int *, int *);

void pmpi_mrecv_(void *, int *, int *, int *, int *, int *);

#define A_f_MPI_Mrecv _PMPI_Mrecv
#pragma weak mpi_mrecv_ = _PMPI_Mrecv
#pragma weak mpi_mrecv__ = _PMPI_Mrecv
#pragma weak pmpi_mrecv__ = _PMPI_Mrecv
extern long long WI4MPI_Mrecv_timeout;
void (*_LOCAL_MPI_Mrecv)(void *, int *, int *, int *, int *, int *);

void A_f_MPI_Mrecv(void *buf, int *count, int *datatype, int *message,
                   int *status, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Mrecv\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Mrecv_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  int message_tmp;
  int status_tmp1[R_f_MPI_STATUS_SIZE + 1];
  int *status_tmp =
      (status == A_f_MPI_STATUS_IGNORE ? R_f_MPI_STATUS_IGNORE : status_tmp1);
  datatype_a2r(datatype, &datatype_tmp);
  message_a2r(message, &message_tmp);
  _LOCAL_MPI_Mrecv(buf_tmp, count, &datatype_tmp, &message_tmp, status_tmp,
                   &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&buf, &buf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    message_r2a(message, &message_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    if (status != A_f_MPI_STATUS_IGNORE)
      status_r2a(status, status_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Mrecv\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_comm_idup_(int *, int *, int *, int *);

void mpi_comm_idup__(int *, int *, int *, int *);

void pmpi_comm_idup_(int *, int *, int *, int *);

void pmpi_comm_idup__(int *, int *, int *, int *);

void pmpi_comm_idup_(int *, int *, int *, int *);

#define A_f_MPI_Comm_idup _PMPI_Comm_idup
#pragma weak mpi_comm_idup_ = _PMPI_Comm_idup
#pragma weak mpi_comm_idup__ = _PMPI_Comm_idup
#pragma weak pmpi_comm_idup__ = _PMPI_Comm_idup
extern long long WI4MPI_Comm_idup_timeout;
void (*_LOCAL_MPI_Comm_idup)(int *, int *, int *, int *);

void A_f_MPI_Comm_idup(int *comm, int *newcomm, int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Comm_idup\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Comm_idup_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  int newcomm_tmp;
  int request_tmp;
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Comm_idup(&comm_tmp, &newcomm_tmp, &request_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    comm_r2a(newcomm, &newcomm_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Comm_idup\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_ibarrier_(int *, int *, int *);

void mpi_ibarrier__(int *, int *, int *);

void pmpi_ibarrier_(int *, int *, int *);

void pmpi_ibarrier__(int *, int *, int *);

void pmpi_ibarrier_(int *, int *, int *);

#define A_f_MPI_Ibarrier _PMPI_Ibarrier
#pragma weak mpi_ibarrier_ = _PMPI_Ibarrier
#pragma weak mpi_ibarrier__ = _PMPI_Ibarrier
#pragma weak pmpi_ibarrier__ = _PMPI_Ibarrier
extern long long WI4MPI_Ibarrier_timeout;
void (*_LOCAL_MPI_Ibarrier)(int *, int *, int *);

void A_f_MPI_Ibarrier(int *comm, int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Ibarrier\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Ibarrier_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  int request_tmp;
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Ibarrier(&comm_tmp, &request_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Ibarrier\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_ibcast_(void *, int *, int *, int *, int *, int *, int *);

void mpi_ibcast__(void *, int *, int *, int *, int *, int *, int *);

void pmpi_ibcast_(void *, int *, int *, int *, int *, int *, int *);

void pmpi_ibcast__(void *, int *, int *, int *, int *, int *, int *);

void pmpi_ibcast_(void *, int *, int *, int *, int *, int *, int *);

#define A_f_MPI_Ibcast _PMPI_Ibcast
#pragma weak mpi_ibcast_ = _PMPI_Ibcast
#pragma weak mpi_ibcast__ = _PMPI_Ibcast
#pragma weak pmpi_ibcast__ = _PMPI_Ibcast
extern long long WI4MPI_Ibcast_timeout;
void (*_LOCAL_MPI_Ibcast)(void *, int *, int *, int *, int *, int *, int *);

void A_f_MPI_Ibcast(void *buffer, int *count, int *datatype, int *root,
                    int *comm, int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Ibcast\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Ibcast_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buffer_tmp = buffer;
  int datatype_tmp;
  int comm_tmp;
  int request_tmp;
  buffer_a2r(&buffer, &buffer_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Ibcast(buffer_tmp, count, &datatype_tmp, root, &comm_tmp,
                    &request_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&buffer, &buffer_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Ibcast\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_igather_(void *, int *, int *, void *, int *, int *, int *, int *,
                  int *, int *);

void mpi_igather__(void *, int *, int *, void *, int *, int *, int *, int *,
                   int *, int *);

void pmpi_igather_(void *, int *, int *, void *, int *, int *, int *, int *,
                   int *, int *);

void pmpi_igather__(void *, int *, int *, void *, int *, int *, int *, int *,
                    int *, int *);

void pmpi_igather_(void *, int *, int *, void *, int *, int *, int *, int *,
                   int *, int *);

#define A_f_MPI_Igather _PMPI_Igather
#pragma weak mpi_igather_ = _PMPI_Igather
#pragma weak mpi_igather__ = _PMPI_Igather
#pragma weak pmpi_igather__ = _PMPI_Igather
extern long long WI4MPI_Igather_timeout;
void (*_LOCAL_MPI_Igather)(void *, int *, int *, void *, int *, int *, int *,
                           int *, int *, int *);

void A_f_MPI_Igather(void *sendbuf, int *sendcount, int *sendtype,
                     void *recvbuf, int *recvcount, int *recvtype, int *root,
                     int *comm, int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Igather\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Igather_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *sendbuf_tmp = sendbuf;
  int sendtype_tmp;
  void *recvbuf_tmp = recvbuf;
  int recvtype_tmp;
  int comm_tmp;
  int request_tmp;
  buffer_a2r(&sendbuf, &sendbuf_tmp);
  datatype_a2r(sendtype, &sendtype_tmp);
  buffer_a2r(&recvbuf, &recvbuf_tmp);
  datatype_a2r(recvtype, &recvtype_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Igather(sendbuf_tmp, sendcount, &sendtype_tmp, recvbuf_tmp,
                     recvcount, &recvtype_tmp, root, &comm_tmp, &request_tmp,
                     &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&recvbuf, &recvbuf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Igather\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_iscatter_(void *, int *, int *, void *, int *, int *, int *, int *,
                   int *, int *);

void mpi_iscatter__(void *, int *, int *, void *, int *, int *, int *, int *,
                    int *, int *);

void pmpi_iscatter_(void *, int *, int *, void *, int *, int *, int *, int *,
                    int *, int *);

void pmpi_iscatter__(void *, int *, int *, void *, int *, int *, int *, int *,
                     int *, int *);

void pmpi_iscatter_(void *, int *, int *, void *, int *, int *, int *, int *,
                    int *, int *);

#define A_f_MPI_Iscatter _PMPI_Iscatter
#pragma weak mpi_iscatter_ = _PMPI_Iscatter
#pragma weak mpi_iscatter__ = _PMPI_Iscatter
#pragma weak pmpi_iscatter__ = _PMPI_Iscatter
extern long long WI4MPI_Iscatter_timeout;
void (*_LOCAL_MPI_Iscatter)(void *, int *, int *, void *, int *, int *, int *,
                            int *, int *, int *);

void A_f_MPI_Iscatter(void *sendbuf, int *sendcount, int *sendtype,
                      void *recvbuf, int *recvcount, int *recvtype, int *root,
                      int *comm, int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Iscatter\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Iscatter_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *sendbuf_tmp = sendbuf;
  int sendtype_tmp;
  void *recvbuf_tmp = recvbuf;
  int recvtype_tmp;
  int comm_tmp;
  int request_tmp;
  buffer_a2r(&sendbuf, &sendbuf_tmp);
  datatype_a2r(sendtype, &sendtype_tmp);
  buffer_a2r(&recvbuf, &recvbuf_tmp);
  datatype_a2r(recvtype, &recvtype_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Iscatter(sendbuf_tmp, sendcount, &sendtype_tmp, recvbuf_tmp,
                      recvcount, &recvtype_tmp, root, &comm_tmp, &request_tmp,
                      &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&recvbuf, &recvbuf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Iscatter\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_iallgather_(void *, int *, int *, void *, int *, int *, int *, int *,
                     int *);

void mpi_iallgather__(void *, int *, int *, void *, int *, int *, int *, int *,
                      int *);

void pmpi_iallgather_(void *, int *, int *, void *, int *, int *, int *, int *,
                      int *);

void pmpi_iallgather__(void *, int *, int *, void *, int *, int *, int *, int *,
                       int *);

void pmpi_iallgather_(void *, int *, int *, void *, int *, int *, int *, int *,
                      int *);

#define A_f_MPI_Iallgather _PMPI_Iallgather
#pragma weak mpi_iallgather_ = _PMPI_Iallgather
#pragma weak mpi_iallgather__ = _PMPI_Iallgather
#pragma weak pmpi_iallgather__ = _PMPI_Iallgather
extern long long WI4MPI_Iallgather_timeout;
void (*_LOCAL_MPI_Iallgather)(void *, int *, int *, void *, int *, int *, int *,
                              int *, int *);

void A_f_MPI_Iallgather(void *sendbuf, int *sendcount, int *sendtype,
                        void *recvbuf, int *recvcount, int *recvtype, int *comm,
                        int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Iallgather\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Iallgather_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *sendbuf_tmp = sendbuf;
  int sendtype_tmp;
  void *recvbuf_tmp = recvbuf;
  int recvtype_tmp;
  int comm_tmp;
  int request_tmp;
  buffer_a2r(&sendbuf, &sendbuf_tmp);
  datatype_a2r(sendtype, &sendtype_tmp);
  buffer_a2r(&recvbuf, &recvbuf_tmp);
  datatype_a2r(recvtype, &recvtype_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Iallgather(sendbuf_tmp, sendcount, &sendtype_tmp, recvbuf_tmp,
                        recvcount, &recvtype_tmp, &comm_tmp, &request_tmp,
                        &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&recvbuf, &recvbuf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Iallgather\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_ialltoall_(void *, int *, int *, void *, int *, int *, int *, int *,
                    int *);

void mpi_ialltoall__(void *, int *, int *, void *, int *, int *, int *, int *,
                     int *);

void pmpi_ialltoall_(void *, int *, int *, void *, int *, int *, int *, int *,
                     int *);

void pmpi_ialltoall__(void *, int *, int *, void *, int *, int *, int *, int *,
                      int *);

void pmpi_ialltoall_(void *, int *, int *, void *, int *, int *, int *, int *,
                     int *);

#define A_f_MPI_Ialltoall _PMPI_Ialltoall
#pragma weak mpi_ialltoall_ = _PMPI_Ialltoall
#pragma weak mpi_ialltoall__ = _PMPI_Ialltoall
#pragma weak pmpi_ialltoall__ = _PMPI_Ialltoall
extern long long WI4MPI_Ialltoall_timeout;
void (*_LOCAL_MPI_Ialltoall)(void *, int *, int *, void *, int *, int *, int *,
                             int *, int *);

void A_f_MPI_Ialltoall(void *sendbuf, int *sendcount, int *sendtype,
                       void *recvbuf, int *recvcount, int *recvtype, int *comm,
                       int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Ialltoall\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Ialltoall_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *sendbuf_tmp = sendbuf;
  int sendtype_tmp;
  void *recvbuf_tmp = recvbuf;
  int recvtype_tmp;
  int comm_tmp;
  int request_tmp;
  buffer_a2r(&sendbuf, &sendbuf_tmp);
  datatype_a2r(sendtype, &sendtype_tmp);
  buffer_a2r(&recvbuf, &recvbuf_tmp);
  datatype_a2r(recvtype, &recvtype_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Ialltoall(sendbuf_tmp, sendcount, &sendtype_tmp, recvbuf_tmp,
                       recvcount, &recvtype_tmp, &comm_tmp, &request_tmp,
                       &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&recvbuf, &recvbuf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Ialltoall\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_ireduce_(void *, void *, int *, int *, int *, int *, int *, int *,
                  int *);

void mpi_ireduce__(void *, void *, int *, int *, int *, int *, int *, int *,
                   int *);

void pmpi_ireduce_(void *, void *, int *, int *, int *, int *, int *, int *,
                   int *);

void pmpi_ireduce__(void *, void *, int *, int *, int *, int *, int *, int *,
                    int *);

void pmpi_ireduce_(void *, void *, int *, int *, int *, int *, int *, int *,
                   int *);

#define A_f_MPI_Ireduce _PMPI_Ireduce
#pragma weak mpi_ireduce_ = _PMPI_Ireduce
#pragma weak mpi_ireduce__ = _PMPI_Ireduce
#pragma weak pmpi_ireduce__ = _PMPI_Ireduce
extern long long WI4MPI_Ireduce_timeout;
void (*_LOCAL_MPI_Ireduce)(void *, void *, int *, int *, int *, int *, int *,
                           int *, int *);

void A_f_MPI_Ireduce(void *sendbuf, void *recvbuf, int *count, int *datatype,
                     int *op, int *root, int *comm, int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Ireduce\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Ireduce_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *sendbuf_tmp = sendbuf;
  void *recvbuf_tmp = recvbuf;
  int datatype_tmp;
  int op_tmp;
  int comm_tmp;
  int request_tmp;
  buffer_a2r(&sendbuf, &sendbuf_tmp);
  buffer_a2r(&recvbuf, &recvbuf_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  operator_a2r(op, &op_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Ireduce(sendbuf_tmp, recvbuf_tmp, count, &datatype_tmp, &op_tmp,
                     root, &comm_tmp, &request_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&recvbuf, &recvbuf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Ireduce\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_iallreduce_(void *, void *, int *, int *, int *, int *, int *, int *);

void mpi_iallreduce__(void *, void *, int *, int *, int *, int *, int *, int *);

void pmpi_iallreduce_(void *, void *, int *, int *, int *, int *, int *, int *);

void pmpi_iallreduce__(void *, void *, int *, int *, int *, int *, int *,
                       int *);

void pmpi_iallreduce_(void *, void *, int *, int *, int *, int *, int *, int *);

#define A_f_MPI_Iallreduce _PMPI_Iallreduce
#pragma weak mpi_iallreduce_ = _PMPI_Iallreduce
#pragma weak mpi_iallreduce__ = _PMPI_Iallreduce
#pragma weak pmpi_iallreduce__ = _PMPI_Iallreduce
extern long long WI4MPI_Iallreduce_timeout;
void (*_LOCAL_MPI_Iallreduce)(void *, void *, int *, int *, int *, int *, int *,
                              int *);

void A_f_MPI_Iallreduce(void *sendbuf, void *recvbuf, int *count, int *datatype,
                        int *op, int *comm, int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Iallreduce\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Iallreduce_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *sendbuf_tmp = sendbuf;
  void *recvbuf_tmp = recvbuf;
  int datatype_tmp;
  int op_tmp;
  int comm_tmp;
  int request_tmp;
  buffer_a2r(&sendbuf, &sendbuf_tmp);
  buffer_a2r(&recvbuf, &recvbuf_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  operator_a2r(op, &op_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Iallreduce(sendbuf_tmp, recvbuf_tmp, count, &datatype_tmp, &op_tmp,
                        &comm_tmp, &request_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&recvbuf, &recvbuf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Iallreduce\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_ireduce_scatter_block_(void *, void *, int *, int *, int *, int *,
                                int *, int *);

void mpi_ireduce_scatter_block__(void *, void *, int *, int *, int *, int *,
                                 int *, int *);

void pmpi_ireduce_scatter_block_(void *, void *, int *, int *, int *, int *,
                                 int *, int *);

void pmpi_ireduce_scatter_block__(void *, void *, int *, int *, int *, int *,
                                  int *, int *);

void pmpi_ireduce_scatter_block_(void *, void *, int *, int *, int *, int *,
                                 int *, int *);

#define A_f_MPI_Ireduce_scatter_block _PMPI_Ireduce_scatter_block
#pragma weak mpi_ireduce_scatter_block_ = _PMPI_Ireduce_scatter_block
#pragma weak mpi_ireduce_scatter_block__ = _PMPI_Ireduce_scatter_block
#pragma weak pmpi_ireduce_scatter_block__ = _PMPI_Ireduce_scatter_block
extern long long WI4MPI_Ireduce_scatter_block_timeout;
void (*_LOCAL_MPI_Ireduce_scatter_block)(void *, void *, int *, int *, int *,
                                         int *, int *, int *);

void A_f_MPI_Ireduce_scatter_block(void *sendbuf, void *recvbuf, int *recvcount,
                                   int *datatype, int *op, int *comm,
                                   int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Ireduce_scatter_block\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Ireduce_scatter_block_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *sendbuf_tmp = sendbuf;
  void *recvbuf_tmp = recvbuf;
  int recvcount_tmp;
  int datatype_tmp;
  int op_tmp;
  int comm_tmp;
  int request_tmp;
  buffer_a2r(&sendbuf, &sendbuf_tmp);
  tag_a2r(recvcount, &recvcount_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  operator_a2r(op, &op_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Ireduce_scatter_block(sendbuf_tmp, recvbuf_tmp, &recvcount_tmp,
                                   &datatype_tmp, &op_tmp, &comm_tmp,
                                   &request_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&recvbuf, &recvbuf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Ireduce_scatter_block\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_iscan_(void *, void *, int *, int *, int *, int *, int *, int *);

void mpi_iscan__(void *, void *, int *, int *, int *, int *, int *, int *);

void pmpi_iscan_(void *, void *, int *, int *, int *, int *, int *, int *);

void pmpi_iscan__(void *, void *, int *, int *, int *, int *, int *, int *);

void pmpi_iscan_(void *, void *, int *, int *, int *, int *, int *, int *);

#define A_f_MPI_Iscan _PMPI_Iscan
#pragma weak mpi_iscan_ = _PMPI_Iscan
#pragma weak mpi_iscan__ = _PMPI_Iscan
#pragma weak pmpi_iscan__ = _PMPI_Iscan
extern long long WI4MPI_Iscan_timeout;
void (*_LOCAL_MPI_Iscan)(void *, void *, int *, int *, int *, int *, int *,
                         int *);

void A_f_MPI_Iscan(void *sendbuf, void *recvbuf, int *count, int *datatype,
                   int *op, int *comm, int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Iscan\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Iscan_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *sendbuf_tmp = sendbuf;
  void *recvbuf_tmp = recvbuf;
  int datatype_tmp;
  int op_tmp;
  int comm_tmp;
  int request_tmp;
  buffer_a2r(&sendbuf, &sendbuf_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  operator_a2r(op, &op_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Iscan(sendbuf_tmp, recvbuf_tmp, count, &datatype_tmp, &op_tmp,
                   &comm_tmp, &request_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&recvbuf, &recvbuf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Iscan\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_iexscan_(void *, void *, int *, int *, int *, int *, int *, int *);

void mpi_iexscan__(void *, void *, int *, int *, int *, int *, int *, int *);

void pmpi_iexscan_(void *, void *, int *, int *, int *, int *, int *, int *);

void pmpi_iexscan__(void *, void *, int *, int *, int *, int *, int *, int *);

void pmpi_iexscan_(void *, void *, int *, int *, int *, int *, int *, int *);

#define A_f_MPI_Iexscan _PMPI_Iexscan
#pragma weak mpi_iexscan_ = _PMPI_Iexscan
#pragma weak mpi_iexscan__ = _PMPI_Iexscan
#pragma weak pmpi_iexscan__ = _PMPI_Iexscan
extern long long WI4MPI_Iexscan_timeout;
void (*_LOCAL_MPI_Iexscan)(void *, void *, int *, int *, int *, int *, int *,
                           int *);

void A_f_MPI_Iexscan(void *sendbuf, void *recvbuf, int *count, int *datatype,
                     int *op, int *comm, int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Iexscan\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Iexscan_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *sendbuf_tmp = sendbuf;
  void *recvbuf_tmp = recvbuf;
  int datatype_tmp;
  int op_tmp;
  int comm_tmp;
  int request_tmp;
  buffer_a2r(&sendbuf, &sendbuf_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  operator_a2r(op, &op_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Iexscan(sendbuf_tmp, recvbuf_tmp, count, &datatype_tmp, &op_tmp,
                     &comm_tmp, &request_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&recvbuf, &recvbuf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Iexscan\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_ineighbor_allgather_(void *, int *, int *, void *, int *, int *, int *,
                              int *, int *);

void mpi_ineighbor_allgather__(void *, int *, int *, void *, int *, int *,
                               int *, int *, int *);

void pmpi_ineighbor_allgather_(void *, int *, int *, void *, int *, int *,
                               int *, int *, int *);

void pmpi_ineighbor_allgather__(void *, int *, int *, void *, int *, int *,
                                int *, int *, int *);

void pmpi_ineighbor_allgather_(void *, int *, int *, void *, int *, int *,
                               int *, int *, int *);

#define A_f_MPI_Ineighbor_allgather _PMPI_Ineighbor_allgather
#pragma weak mpi_ineighbor_allgather_ = _PMPI_Ineighbor_allgather
#pragma weak mpi_ineighbor_allgather__ = _PMPI_Ineighbor_allgather
#pragma weak pmpi_ineighbor_allgather__ = _PMPI_Ineighbor_allgather
extern long long WI4MPI_Ineighbor_allgather_timeout;
void (*_LOCAL_MPI_Ineighbor_allgather)(void *, int *, int *, void *, int *,
                                       int *, int *, int *, int *);

void A_f_MPI_Ineighbor_allgather(void *sendbuf, int *sendcount, int *sendtype,
                                 void *recvbuf, int *recvcount, int *recvtype,
                                 int *comm, int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Ineighbor_allgather\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Ineighbor_allgather_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *sendbuf_tmp = sendbuf;
  int sendtype_tmp;
  void *recvbuf_tmp = recvbuf;
  int recvtype_tmp;
  int comm_tmp;
  int request_tmp;
  buffer_a2r(&sendbuf, &sendbuf_tmp);
  datatype_a2r(sendtype, &sendtype_tmp);
  datatype_a2r(recvtype, &recvtype_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Ineighbor_allgather(sendbuf_tmp, sendcount, &sendtype_tmp,
                                 recvbuf_tmp, recvcount, &recvtype_tmp,
                                 &comm_tmp, &request_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&recvbuf, &recvbuf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Ineighbor_allgather\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_ineighbor_alltoall_(void *, int *, int *, void *, int *, int *, int *,
                             int *, int *);

void mpi_ineighbor_alltoall__(void *, int *, int *, void *, int *, int *, int *,
                              int *, int *);

void pmpi_ineighbor_alltoall_(void *, int *, int *, void *, int *, int *, int *,
                              int *, int *);

void pmpi_ineighbor_alltoall__(void *, int *, int *, void *, int *, int *,
                               int *, int *, int *);

void pmpi_ineighbor_alltoall_(void *, int *, int *, void *, int *, int *, int *,
                              int *, int *);

#define A_f_MPI_Ineighbor_alltoall _PMPI_Ineighbor_alltoall
#pragma weak mpi_ineighbor_alltoall_ = _PMPI_Ineighbor_alltoall
#pragma weak mpi_ineighbor_alltoall__ = _PMPI_Ineighbor_alltoall
#pragma weak pmpi_ineighbor_alltoall__ = _PMPI_Ineighbor_alltoall
extern long long WI4MPI_Ineighbor_alltoall_timeout;
void (*_LOCAL_MPI_Ineighbor_alltoall)(void *, int *, int *, void *, int *,
                                      int *, int *, int *, int *);

void A_f_MPI_Ineighbor_alltoall(void *sendbuf, int *sendcount, int *sendtype,
                                void *recvbuf, int *recvcount, int *recvtype,
                                int *comm, int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Ineighbor_alltoall\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Ineighbor_alltoall_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *sendbuf_tmp = sendbuf;
  int sendtype_tmp;
  void *recvbuf_tmp = recvbuf;
  int recvtype_tmp;
  int comm_tmp;
  int request_tmp;
  buffer_a2r(&sendbuf, &sendbuf_tmp);
  datatype_a2r(sendtype, &sendtype_tmp);
  datatype_a2r(recvtype, &recvtype_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Ineighbor_alltoall(sendbuf_tmp, sendcount, &sendtype_tmp,
                                recvbuf_tmp, recvcount, &recvtype_tmp,
                                &comm_tmp, &request_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&recvbuf, &recvbuf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Ineighbor_alltoall\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_neighbor_allgather_(void *, int *, int *, void *, int *, int *, int *,
                             int *);

void mpi_neighbor_allgather__(void *, int *, int *, void *, int *, int *, int *,
                              int *);

void pmpi_neighbor_allgather_(void *, int *, int *, void *, int *, int *, int *,
                              int *);

void pmpi_neighbor_allgather__(void *, int *, int *, void *, int *, int *,
                               int *, int *);

void pmpi_neighbor_allgather_(void *, int *, int *, void *, int *, int *, int *,
                              int *);

#define A_f_MPI_Neighbor_allgather _PMPI_Neighbor_allgather
#pragma weak mpi_neighbor_allgather_ = _PMPI_Neighbor_allgather
#pragma weak mpi_neighbor_allgather__ = _PMPI_Neighbor_allgather
#pragma weak pmpi_neighbor_allgather__ = _PMPI_Neighbor_allgather
extern long long WI4MPI_Neighbor_allgather_timeout;
void (*_LOCAL_MPI_Neighbor_allgather)(void *, int *, int *, void *, int *,
                                      int *, int *, int *);

void A_f_MPI_Neighbor_allgather(void *sendbuf, int *sendcount, int *sendtype,
                                void *recvbuf, int *recvcount, int *recvtype,
                                int *comm, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Neighbor_allgather\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Neighbor_allgather_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *sendbuf_tmp = sendbuf;
  int sendtype_tmp;
  void *recvbuf_tmp = recvbuf;
  int recvtype_tmp;
  int comm_tmp;
  buffer_a2r(&sendbuf, &sendbuf_tmp);
  datatype_a2r(sendtype, &sendtype_tmp);
  datatype_a2r(recvtype, &recvtype_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Neighbor_allgather(sendbuf_tmp, sendcount, &sendtype_tmp,
                                recvbuf_tmp, recvcount, &recvtype_tmp,
                                &comm_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&recvbuf, &recvbuf_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Neighbor_allgather\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_neighbor_alltoall_(void *, int *, int *, void *, int *, int *, int *,
                            int *);

void mpi_neighbor_alltoall__(void *, int *, int *, void *, int *, int *, int *,
                             int *);

void pmpi_neighbor_alltoall_(void *, int *, int *, void *, int *, int *, int *,
                             int *);

void pmpi_neighbor_alltoall__(void *, int *, int *, void *, int *, int *, int *,
                              int *);

void pmpi_neighbor_alltoall_(void *, int *, int *, void *, int *, int *, int *,
                             int *);

#define A_f_MPI_Neighbor_alltoall _PMPI_Neighbor_alltoall
#pragma weak mpi_neighbor_alltoall_ = _PMPI_Neighbor_alltoall
#pragma weak mpi_neighbor_alltoall__ = _PMPI_Neighbor_alltoall
#pragma weak pmpi_neighbor_alltoall__ = _PMPI_Neighbor_alltoall
extern long long WI4MPI_Neighbor_alltoall_timeout;
void (*_LOCAL_MPI_Neighbor_alltoall)(void *, int *, int *, void *, int *, int *,
                                     int *, int *);

void A_f_MPI_Neighbor_alltoall(void *sendbuf, int *sendcount, int *sendtype,
                               void *recvbuf, int *recvcount, int *recvtype,
                               int *comm, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Neighbor_alltoall\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Neighbor_alltoall_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *sendbuf_tmp = sendbuf;
  int sendtype_tmp;
  void *recvbuf_tmp = recvbuf;
  int recvtype_tmp;
  int comm_tmp;
  buffer_a2r(&sendbuf, &sendbuf_tmp);
  datatype_a2r(sendtype, &sendtype_tmp);
  datatype_a2r(recvtype, &recvtype_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Neighbor_alltoall(sendbuf_tmp, sendcount, &sendtype_tmp,
                               recvbuf_tmp, recvcount, &recvtype_tmp, &comm_tmp,
                               &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&recvbuf, &recvbuf_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Neighbor_alltoall\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_comm_split_type_(int *, int *, int *, int *, int *, int *);

void mpi_comm_split_type__(int *, int *, int *, int *, int *, int *);

void pmpi_comm_split_type_(int *, int *, int *, int *, int *, int *);

void pmpi_comm_split_type__(int *, int *, int *, int *, int *, int *);

void pmpi_comm_split_type_(int *, int *, int *, int *, int *, int *);

#define A_f_MPI_Comm_split_type _PMPI_Comm_split_type
#pragma weak mpi_comm_split_type_ = _PMPI_Comm_split_type
#pragma weak mpi_comm_split_type__ = _PMPI_Comm_split_type
#pragma weak pmpi_comm_split_type__ = _PMPI_Comm_split_type
extern long long WI4MPI_Comm_split_type_timeout;
void (*_LOCAL_MPI_Comm_split_type)(int *, int *, int *, int *, int *, int *);

void A_f_MPI_Comm_split_type(int *comm, int *split_type, int *key, int *info,
                             int *newcomm, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Comm_split_type\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Comm_split_type_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  int info_tmp;
  int newcomm_tmp;
  comm_a2r(comm, &comm_tmp);
  info_a2r(info, &info_tmp);
  _LOCAL_MPI_Comm_split_type(&comm_tmp, split_type, key, &info_tmp,
                             &newcomm_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    comm_r2a(newcomm, &newcomm_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Comm_split_type\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_get_elements_x_(int *, int *, int *, int *);

void mpi_get_elements_x__(int *, int *, int *, int *);

void pmpi_get_elements_x_(int *, int *, int *, int *);

void pmpi_get_elements_x__(int *, int *, int *, int *);

void pmpi_get_elements_x_(int *, int *, int *, int *);

#define A_f_MPI_Get_elements_x _PMPI_Get_elements_x
#pragma weak mpi_get_elements_x_ = _PMPI_Get_elements_x
#pragma weak mpi_get_elements_x__ = _PMPI_Get_elements_x
#pragma weak pmpi_get_elements_x__ = _PMPI_Get_elements_x
extern long long WI4MPI_Get_elements_x_timeout;
void (*_LOCAL_MPI_Get_elements_x)(int *, int *, int *, int *);

void A_f_MPI_Get_elements_x(int *status, int *datatype, int *count, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Get_elements_x\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Get_elements_x_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int status_tmp1[R_f_MPI_STATUS_SIZE + 1];
  int *status_tmp =
      (status == A_f_MPI_STATUS_IGNORE ? R_f_MPI_STATUS_IGNORE : status_tmp1);
  int datatype_tmp;
  status_a2r(status, status_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_Get_elements_x(status_tmp, &datatype_tmp, count, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Get_elements_x\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_status_set_elements_x_(int *, int *, int *, int *);

void mpi_status_set_elements_x__(int *, int *, int *, int *);

void pmpi_status_set_elements_x_(int *, int *, int *, int *);

void pmpi_status_set_elements_x__(int *, int *, int *, int *);

void pmpi_status_set_elements_x_(int *, int *, int *, int *);

#define A_f_MPI_Status_set_elements_x _PMPI_Status_set_elements_x
#pragma weak mpi_status_set_elements_x_ = _PMPI_Status_set_elements_x
#pragma weak mpi_status_set_elements_x__ = _PMPI_Status_set_elements_x
#pragma weak pmpi_status_set_elements_x__ = _PMPI_Status_set_elements_x
extern long long WI4MPI_Status_set_elements_x_timeout;
void (*_LOCAL_MPI_Status_set_elements_x)(int *, int *, int *, int *);

void A_f_MPI_Status_set_elements_x(int *status, int *datatype, int *count,
                                   int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Status_set_elements_x\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Status_set_elements_x_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int status_tmp1[R_f_MPI_STATUS_SIZE + 1];
  int *status_tmp =
      (status == A_f_MPI_STATUS_IGNORE ? R_f_MPI_STATUS_IGNORE : status_tmp1);
  int datatype_tmp;
  status_a2r(status, status_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_Status_set_elements_x(status_tmp, &datatype_tmp, count, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    if (status != A_f_MPI_STATUS_IGNORE)
      status_r2a(status, status_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Status_set_elements_x\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_type_get_extent_x_(int *, int *, int *, int *);

void mpi_type_get_extent_x__(int *, int *, int *, int *);

void pmpi_type_get_extent_x_(int *, int *, int *, int *);

void pmpi_type_get_extent_x__(int *, int *, int *, int *);

void pmpi_type_get_extent_x_(int *, int *, int *, int *);

#define A_f_MPI_Type_get_extent_x _PMPI_Type_get_extent_x
#pragma weak mpi_type_get_extent_x_ = _PMPI_Type_get_extent_x
#pragma weak mpi_type_get_extent_x__ = _PMPI_Type_get_extent_x
#pragma weak pmpi_type_get_extent_x__ = _PMPI_Type_get_extent_x
extern long long WI4MPI_Type_get_extent_x_timeout;
void (*_LOCAL_MPI_Type_get_extent_x)(int *, int *, int *, int *);

void A_f_MPI_Type_get_extent_x(int *datatype, int *lb, int *extent, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Type_get_extent_x\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Type_get_extent_x_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int datatype_tmp;
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_Type_get_extent_x(&datatype_tmp, lb, extent, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Type_get_extent_x\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_type_get_true_extent_x_(int *, int *, int *, int *);

void mpi_type_get_true_extent_x__(int *, int *, int *, int *);

void pmpi_type_get_true_extent_x_(int *, int *, int *, int *);

void pmpi_type_get_true_extent_x__(int *, int *, int *, int *);

void pmpi_type_get_true_extent_x_(int *, int *, int *, int *);

#define A_f_MPI_Type_get_true_extent_x _PMPI_Type_get_true_extent_x
#pragma weak mpi_type_get_true_extent_x_ = _PMPI_Type_get_true_extent_x
#pragma weak mpi_type_get_true_extent_x__ = _PMPI_Type_get_true_extent_x
#pragma weak pmpi_type_get_true_extent_x__ = _PMPI_Type_get_true_extent_x
extern long long WI4MPI_Type_get_true_extent_x_timeout;
void (*_LOCAL_MPI_Type_get_true_extent_x)(int *, int *, int *, int *);

void A_f_MPI_Type_get_true_extent_x(int *datatype, int *lb, int *extent,
                                    int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Type_get_true_extent_x\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Type_get_true_extent_x_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int datatype_tmp;
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_Type_get_true_extent_x(&datatype_tmp, lb, extent, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Type_get_true_extent_x\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_type_size_x_(int *, int *, int *);

void mpi_type_size_x__(int *, int *, int *);

void pmpi_type_size_x_(int *, int *, int *);

void pmpi_type_size_x__(int *, int *, int *);

void pmpi_type_size_x_(int *, int *, int *);

#define A_f_MPI_Type_size_x _PMPI_Type_size_x
#pragma weak mpi_type_size_x_ = _PMPI_Type_size_x
#pragma weak mpi_type_size_x__ = _PMPI_Type_size_x
#pragma weak pmpi_type_size_x__ = _PMPI_Type_size_x
extern long long WI4MPI_Type_size_x_timeout;
void (*_LOCAL_MPI_Type_size_x)(int *, int *, int *);

void A_f_MPI_Type_size_x(int *datatype, int *size, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Type_size_x\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Type_size_x_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int datatype_tmp;
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_Type_size_x(&datatype_tmp, size, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Type_size_x\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_comm_create_group_(int *, int *, int *, int *, int *);

void mpi_comm_create_group__(int *, int *, int *, int *, int *);

void pmpi_comm_create_group_(int *, int *, int *, int *, int *);

void pmpi_comm_create_group__(int *, int *, int *, int *, int *);

void pmpi_comm_create_group_(int *, int *, int *, int *, int *);

#define A_f_MPI_Comm_create_group _PMPI_Comm_create_group
#pragma weak mpi_comm_create_group_ = _PMPI_Comm_create_group
#pragma weak mpi_comm_create_group__ = _PMPI_Comm_create_group
#pragma weak pmpi_comm_create_group__ = _PMPI_Comm_create_group
extern long long WI4MPI_Comm_create_group_timeout;
void (*_LOCAL_MPI_Comm_create_group)(int *, int *, int *, int *, int *);

void A_f_MPI_Comm_create_group(int *comm, int *group, int *tag, int *newcomm,
                               int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Comm_create_group\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Comm_create_group_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  int group_tmp;
  int tag_tmp;
  int newcomm_tmp;
  comm_a2r(comm, &comm_tmp);
  group_a2r(group, &group_tmp);
  tag_a2r(tag, &tag_tmp);
  _LOCAL_MPI_Comm_create_group(&comm_tmp, &group_tmp, &tag_tmp, &newcomm_tmp,
                               &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    comm_r2a(newcomm, &newcomm_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Comm_create_group\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_close_(int *, int *);

void mpi_file_close__(int *, int *);

void pmpi_file_close_(int *, int *);

void pmpi_file_close__(int *, int *);

void pmpi_file_close_(int *, int *);

#define A_f_MPI_File_close _PMPI_File_close
#pragma weak mpi_file_close_ = _PMPI_File_close
#pragma weak mpi_file_close__ = _PMPI_File_close
#pragma weak pmpi_file_close__ = _PMPI_File_close
extern long long WI4MPI_File_close_timeout;
void (*_LOCAL_MPI_File_close)(int *, int *);

void A_f_MPI_File_close(int *fh, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_close\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_close_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_File_close(fh, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_close\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_set_size_(int *, int *, int *);

void mpi_file_set_size__(int *, int *, int *);

void pmpi_file_set_size_(int *, int *, int *);

void pmpi_file_set_size__(int *, int *, int *);

void pmpi_file_set_size_(int *, int *, int *);

#define A_f_MPI_File_set_size _PMPI_File_set_size
#pragma weak mpi_file_set_size_ = _PMPI_File_set_size
#pragma weak mpi_file_set_size__ = _PMPI_File_set_size
#pragma weak pmpi_file_set_size__ = _PMPI_File_set_size
extern long long WI4MPI_File_set_size_timeout;
void (*_LOCAL_MPI_File_set_size)(int *, int *, int *);

void A_f_MPI_File_set_size(int *fh, int *size, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_set_size\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_set_size_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_File_set_size(fh, size, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_set_size\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_preallocate_(int *, int *, int *);

void mpi_file_preallocate__(int *, int *, int *);

void pmpi_file_preallocate_(int *, int *, int *);

void pmpi_file_preallocate__(int *, int *, int *);

void pmpi_file_preallocate_(int *, int *, int *);

#define A_f_MPI_File_preallocate _PMPI_File_preallocate
#pragma weak mpi_file_preallocate_ = _PMPI_File_preallocate
#pragma weak mpi_file_preallocate__ = _PMPI_File_preallocate
#pragma weak pmpi_file_preallocate__ = _PMPI_File_preallocate
extern long long WI4MPI_File_preallocate_timeout;
void (*_LOCAL_MPI_File_preallocate)(int *, int *, int *);

void A_f_MPI_File_preallocate(int *fh, int *size, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_preallocate\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_preallocate_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_File_preallocate(fh, size, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_preallocate\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_get_size_(int *, int *, int *);

void mpi_file_get_size__(int *, int *, int *);

void pmpi_file_get_size_(int *, int *, int *);

void pmpi_file_get_size__(int *, int *, int *);

void pmpi_file_get_size_(int *, int *, int *);

#define A_f_MPI_File_get_size _PMPI_File_get_size
#pragma weak mpi_file_get_size_ = _PMPI_File_get_size
#pragma weak mpi_file_get_size__ = _PMPI_File_get_size
#pragma weak pmpi_file_get_size__ = _PMPI_File_get_size
extern long long WI4MPI_File_get_size_timeout;
void (*_LOCAL_MPI_File_get_size)(int *, int *, int *);

void A_f_MPI_File_get_size(int *fh, int *size, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_get_size\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_get_size_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_File_get_size(fh, size, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_get_size\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_get_group_(int *, int *, int *);

void mpi_file_get_group__(int *, int *, int *);

void pmpi_file_get_group_(int *, int *, int *);

void pmpi_file_get_group__(int *, int *, int *);

void pmpi_file_get_group_(int *, int *, int *);

#define A_f_MPI_File_get_group _PMPI_File_get_group
#pragma weak mpi_file_get_group_ = _PMPI_File_get_group
#pragma weak mpi_file_get_group__ = _PMPI_File_get_group
#pragma weak pmpi_file_get_group__ = _PMPI_File_get_group
extern long long WI4MPI_File_get_group_timeout;
void (*_LOCAL_MPI_File_get_group)(int *, int *, int *);

void A_f_MPI_File_get_group(int *fh, int *group, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_get_group\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_get_group_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int group_tmp;
  _LOCAL_MPI_File_get_group(fh, &group_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    group_r2a(group, &group_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_get_group\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_get_amode_(int *, int *, int *);

void mpi_file_get_amode__(int *, int *, int *);

void pmpi_file_get_amode_(int *, int *, int *);

void pmpi_file_get_amode__(int *, int *, int *);

void pmpi_file_get_amode_(int *, int *, int *);

#define A_f_MPI_File_get_amode _PMPI_File_get_amode
#pragma weak mpi_file_get_amode_ = _PMPI_File_get_amode
#pragma weak mpi_file_get_amode__ = _PMPI_File_get_amode
#pragma weak pmpi_file_get_amode__ = _PMPI_File_get_amode
extern long long WI4MPI_File_get_amode_timeout;
void (*_LOCAL_MPI_File_get_amode)(int *, int *, int *);

void A_f_MPI_File_get_amode(int *fh, int *amode, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_get_amode\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_get_amode_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_File_get_amode(fh, amode, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_get_amode\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_set_info_(int *, int *, int *);

void mpi_file_set_info__(int *, int *, int *);

void pmpi_file_set_info_(int *, int *, int *);

void pmpi_file_set_info__(int *, int *, int *);

void pmpi_file_set_info_(int *, int *, int *);

#define A_f_MPI_File_set_info _PMPI_File_set_info
#pragma weak mpi_file_set_info_ = _PMPI_File_set_info
#pragma weak mpi_file_set_info__ = _PMPI_File_set_info
#pragma weak pmpi_file_set_info__ = _PMPI_File_set_info
extern long long WI4MPI_File_set_info_timeout;
void (*_LOCAL_MPI_File_set_info)(int *, int *, int *);

void A_f_MPI_File_set_info(int *fh, int *info, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_set_info\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_set_info_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int info_tmp;
  info_a2r(info, &info_tmp);
  _LOCAL_MPI_File_set_info(fh, &info_tmp, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_set_info\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_get_info_(int *, int *, int *);

void mpi_file_get_info__(int *, int *, int *);

void pmpi_file_get_info_(int *, int *, int *);

void pmpi_file_get_info__(int *, int *, int *);

void pmpi_file_get_info_(int *, int *, int *);

#define A_f_MPI_File_get_info _PMPI_File_get_info
#pragma weak mpi_file_get_info_ = _PMPI_File_get_info
#pragma weak mpi_file_get_info__ = _PMPI_File_get_info
#pragma weak pmpi_file_get_info__ = _PMPI_File_get_info
extern long long WI4MPI_File_get_info_timeout;
void (*_LOCAL_MPI_File_get_info)(int *, int *, int *);

void A_f_MPI_File_get_info(int *fh, int *info_used, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_get_info\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_get_info_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int info_used_tmp;
  _LOCAL_MPI_File_get_info(fh, &info_used_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    info_r2a(info_used, &info_used_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_get_info\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_read_at_(int *, int *, void *, int *, int *, int *, int *);

void mpi_file_read_at__(int *, int *, void *, int *, int *, int *, int *);

void pmpi_file_read_at_(int *, int *, void *, int *, int *, int *, int *);

void pmpi_file_read_at__(int *, int *, void *, int *, int *, int *, int *);

void pmpi_file_read_at_(int *, int *, void *, int *, int *, int *, int *);

#define A_f_MPI_File_read_at _PMPI_File_read_at
#pragma weak mpi_file_read_at_ = _PMPI_File_read_at
#pragma weak mpi_file_read_at__ = _PMPI_File_read_at
#pragma weak pmpi_file_read_at__ = _PMPI_File_read_at
extern long long WI4MPI_File_read_at_timeout;
void (*_LOCAL_MPI_File_read_at)(int *, int *, void *, int *, int *, int *,
                                int *);

void A_f_MPI_File_read_at(int *fh, int *offset, void *buf, int *count,
                          int *datatype, int *status, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_read_at\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_read_at_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  int status_tmp1[R_f_MPI_STATUS_SIZE + 1];
  int *status_tmp =
      (status == A_f_MPI_STATUS_IGNORE ? R_f_MPI_STATUS_IGNORE : status_tmp1);
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_File_read_at(fh, offset, buf_tmp, count, &datatype_tmp, status_tmp,
                          &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&buf, &buf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    if (status != A_f_MPI_STATUS_IGNORE)
      status_r2a(status, status_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_read_at\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_read_at_all_(int *, int *, void *, int *, int *, int *, int *);

void mpi_file_read_at_all__(int *, int *, void *, int *, int *, int *, int *);

void pmpi_file_read_at_all_(int *, int *, void *, int *, int *, int *, int *);

void pmpi_file_read_at_all__(int *, int *, void *, int *, int *, int *, int *);

void pmpi_file_read_at_all_(int *, int *, void *, int *, int *, int *, int *);

#define A_f_MPI_File_read_at_all _PMPI_File_read_at_all
#pragma weak mpi_file_read_at_all_ = _PMPI_File_read_at_all
#pragma weak mpi_file_read_at_all__ = _PMPI_File_read_at_all
#pragma weak pmpi_file_read_at_all__ = _PMPI_File_read_at_all
extern long long WI4MPI_File_read_at_all_timeout;
void (*_LOCAL_MPI_File_read_at_all)(int *, int *, void *, int *, int *, int *,
                                    int *);

void A_f_MPI_File_read_at_all(int *fh, int *offset, void *buf, int *count,
                              int *datatype, int *status, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_read_at_all\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_read_at_all_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  int status_tmp1[R_f_MPI_STATUS_SIZE + 1];
  int *status_tmp =
      (status == A_f_MPI_STATUS_IGNORE ? R_f_MPI_STATUS_IGNORE : status_tmp1);
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_File_read_at_all(fh, offset, buf_tmp, count, &datatype_tmp,
                              status_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&buf, &buf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    if (status != A_f_MPI_STATUS_IGNORE)
      status_r2a(status, status_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_read_at_all\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_write_at_(int *, int *, void *, int *, int *, int *, int *);

void mpi_file_write_at__(int *, int *, void *, int *, int *, int *, int *);

void pmpi_file_write_at_(int *, int *, void *, int *, int *, int *, int *);

void pmpi_file_write_at__(int *, int *, void *, int *, int *, int *, int *);

void pmpi_file_write_at_(int *, int *, void *, int *, int *, int *, int *);

#define A_f_MPI_File_write_at _PMPI_File_write_at
#pragma weak mpi_file_write_at_ = _PMPI_File_write_at
#pragma weak mpi_file_write_at__ = _PMPI_File_write_at
#pragma weak pmpi_file_write_at__ = _PMPI_File_write_at
extern long long WI4MPI_File_write_at_timeout;
void (*_LOCAL_MPI_File_write_at)(int *, int *, void *, int *, int *, int *,
                                 int *);

void A_f_MPI_File_write_at(int *fh, int *offset, void *buf, int *count,
                           int *datatype, int *status, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_write_at\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_write_at_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  int status_tmp1[R_f_MPI_STATUS_SIZE + 1];
  int *status_tmp =
      (status == A_f_MPI_STATUS_IGNORE ? R_f_MPI_STATUS_IGNORE : status_tmp1);
  buffer_a2r(&buf, &buf_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_File_write_at(fh, offset, buf_tmp, count, &datatype_tmp,
                           status_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    if (status != A_f_MPI_STATUS_IGNORE)
      status_r2a(status, status_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_write_at\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_write_at_all_(int *, int *, void *, int *, int *, int *, int *);

void mpi_file_write_at_all__(int *, int *, void *, int *, int *, int *, int *);

void pmpi_file_write_at_all_(int *, int *, void *, int *, int *, int *, int *);

void pmpi_file_write_at_all__(int *, int *, void *, int *, int *, int *, int *);

void pmpi_file_write_at_all_(int *, int *, void *, int *, int *, int *, int *);

#define A_f_MPI_File_write_at_all _PMPI_File_write_at_all
#pragma weak mpi_file_write_at_all_ = _PMPI_File_write_at_all
#pragma weak mpi_file_write_at_all__ = _PMPI_File_write_at_all
#pragma weak pmpi_file_write_at_all__ = _PMPI_File_write_at_all
extern long long WI4MPI_File_write_at_all_timeout;
void (*_LOCAL_MPI_File_write_at_all)(int *, int *, void *, int *, int *, int *,
                                     int *);

void A_f_MPI_File_write_at_all(int *fh, int *offset, void *buf, int *count,
                               int *datatype, int *status, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_write_at_all\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_write_at_all_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  int status_tmp1[R_f_MPI_STATUS_SIZE + 1];
  int *status_tmp =
      (status == A_f_MPI_STATUS_IGNORE ? R_f_MPI_STATUS_IGNORE : status_tmp1);
  buffer_a2r(&buf, &buf_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_File_write_at_all(fh, offset, buf_tmp, count, &datatype_tmp,
                               status_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    if (status != A_f_MPI_STATUS_IGNORE)
      status_r2a(status, status_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_write_at_all\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_iread_at_(int *, int *, void *, int *, int *, int *, int *);

void mpi_file_iread_at__(int *, int *, void *, int *, int *, int *, int *);

void pmpi_file_iread_at_(int *, int *, void *, int *, int *, int *, int *);

void pmpi_file_iread_at__(int *, int *, void *, int *, int *, int *, int *);

void pmpi_file_iread_at_(int *, int *, void *, int *, int *, int *, int *);

#define A_f_MPI_File_iread_at _PMPI_File_iread_at
#pragma weak mpi_file_iread_at_ = _PMPI_File_iread_at
#pragma weak mpi_file_iread_at__ = _PMPI_File_iread_at
#pragma weak pmpi_file_iread_at__ = _PMPI_File_iread_at
extern long long WI4MPI_File_iread_at_timeout;
void (*_LOCAL_MPI_File_iread_at)(int *, int *, void *, int *, int *, int *,
                                 int *);

void A_f_MPI_File_iread_at(int *fh, int *offset, void *buf, int *count,
                           int *datatype, int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_iread_at\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_iread_at_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  int request_tmp;
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_File_iread_at(fh, offset, buf_tmp, count, &datatype_tmp,
                           &request_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&buf, &buf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_iread_at\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_iwrite_at_(int *, int *, void *, int *, int *, int *, int *);

void mpi_file_iwrite_at__(int *, int *, void *, int *, int *, int *, int *);

void pmpi_file_iwrite_at_(int *, int *, void *, int *, int *, int *, int *);

void pmpi_file_iwrite_at__(int *, int *, void *, int *, int *, int *, int *);

void pmpi_file_iwrite_at_(int *, int *, void *, int *, int *, int *, int *);

#define A_f_MPI_File_iwrite_at _PMPI_File_iwrite_at
#pragma weak mpi_file_iwrite_at_ = _PMPI_File_iwrite_at
#pragma weak mpi_file_iwrite_at__ = _PMPI_File_iwrite_at
#pragma weak pmpi_file_iwrite_at__ = _PMPI_File_iwrite_at
extern long long WI4MPI_File_iwrite_at_timeout;
void (*_LOCAL_MPI_File_iwrite_at)(int *, int *, void *, int *, int *, int *,
                                  int *);

void A_f_MPI_File_iwrite_at(int *fh, int *offset, void *buf, int *count,
                            int *datatype, int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_iwrite_at\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_iwrite_at_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  int request_tmp;
  buffer_a2r(&buf, &buf_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_File_iwrite_at(fh, offset, buf_tmp, count, &datatype_tmp,
                            &request_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_iwrite_at\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_read_(int *, void *, int *, int *, int *, int *);

void mpi_file_read__(int *, void *, int *, int *, int *, int *);

void pmpi_file_read_(int *, void *, int *, int *, int *, int *);

void pmpi_file_read__(int *, void *, int *, int *, int *, int *);

void pmpi_file_read_(int *, void *, int *, int *, int *, int *);

#define A_f_MPI_File_read _PMPI_File_read
#pragma weak mpi_file_read_ = _PMPI_File_read
#pragma weak mpi_file_read__ = _PMPI_File_read
#pragma weak pmpi_file_read__ = _PMPI_File_read
extern long long WI4MPI_File_read_timeout;
void (*_LOCAL_MPI_File_read)(int *, void *, int *, int *, int *, int *);

void A_f_MPI_File_read(int *fh, void *buf, int *count, int *datatype,
                       int *status, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_read\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_read_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  int status_tmp1[R_f_MPI_STATUS_SIZE + 1];
  int *status_tmp =
      (status == A_f_MPI_STATUS_IGNORE ? R_f_MPI_STATUS_IGNORE : status_tmp1);
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_File_read(fh, buf_tmp, count, &datatype_tmp, status_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&buf, &buf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    if (status != A_f_MPI_STATUS_IGNORE)
      status_r2a(status, status_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_read\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_read_all_(int *, void *, int *, int *, int *, int *);

void mpi_file_read_all__(int *, void *, int *, int *, int *, int *);

void pmpi_file_read_all_(int *, void *, int *, int *, int *, int *);

void pmpi_file_read_all__(int *, void *, int *, int *, int *, int *);

void pmpi_file_read_all_(int *, void *, int *, int *, int *, int *);

#define A_f_MPI_File_read_all _PMPI_File_read_all
#pragma weak mpi_file_read_all_ = _PMPI_File_read_all
#pragma weak mpi_file_read_all__ = _PMPI_File_read_all
#pragma weak pmpi_file_read_all__ = _PMPI_File_read_all
extern long long WI4MPI_File_read_all_timeout;
void (*_LOCAL_MPI_File_read_all)(int *, void *, int *, int *, int *, int *);

void A_f_MPI_File_read_all(int *fh, void *buf, int *count, int *datatype,
                           int *status, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_read_all\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_read_all_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  int status_tmp1[R_f_MPI_STATUS_SIZE + 1];
  int *status_tmp =
      (status == A_f_MPI_STATUS_IGNORE ? R_f_MPI_STATUS_IGNORE : status_tmp1);
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_File_read_all(fh, buf_tmp, count, &datatype_tmp, status_tmp,
                           &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&buf, &buf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    if (status != A_f_MPI_STATUS_IGNORE)
      status_r2a(status, status_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_read_all\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_write_(int *, void *, int *, int *, int *, int *);

void mpi_file_write__(int *, void *, int *, int *, int *, int *);

void pmpi_file_write_(int *, void *, int *, int *, int *, int *);

void pmpi_file_write__(int *, void *, int *, int *, int *, int *);

void pmpi_file_write_(int *, void *, int *, int *, int *, int *);

#define A_f_MPI_File_write _PMPI_File_write
#pragma weak mpi_file_write_ = _PMPI_File_write
#pragma weak mpi_file_write__ = _PMPI_File_write
#pragma weak pmpi_file_write__ = _PMPI_File_write
extern long long WI4MPI_File_write_timeout;
void (*_LOCAL_MPI_File_write)(int *, void *, int *, int *, int *, int *);

void A_f_MPI_File_write(int *fh, void *buf, int *count, int *datatype,
                        int *status, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_write\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_write_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  int status_tmp1[R_f_MPI_STATUS_SIZE + 1];
  int *status_tmp =
      (status == A_f_MPI_STATUS_IGNORE ? R_f_MPI_STATUS_IGNORE : status_tmp1);
  buffer_a2r(&buf, &buf_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_File_write(fh, buf_tmp, count, &datatype_tmp, status_tmp,
                        &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    if (status != A_f_MPI_STATUS_IGNORE)
      status_r2a(status, status_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_write\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_write_all_(int *, void *, int *, int *, int *, int *);

void mpi_file_write_all__(int *, void *, int *, int *, int *, int *);

void pmpi_file_write_all_(int *, void *, int *, int *, int *, int *);

void pmpi_file_write_all__(int *, void *, int *, int *, int *, int *);

void pmpi_file_write_all_(int *, void *, int *, int *, int *, int *);

#define A_f_MPI_File_write_all _PMPI_File_write_all
#pragma weak mpi_file_write_all_ = _PMPI_File_write_all
#pragma weak mpi_file_write_all__ = _PMPI_File_write_all
#pragma weak pmpi_file_write_all__ = _PMPI_File_write_all
extern long long WI4MPI_File_write_all_timeout;
void (*_LOCAL_MPI_File_write_all)(int *, void *, int *, int *, int *, int *);

void A_f_MPI_File_write_all(int *fh, void *buf, int *count, int *datatype,
                            int *status, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_write_all\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_write_all_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  int status_tmp1[R_f_MPI_STATUS_SIZE + 1];
  int *status_tmp =
      (status == A_f_MPI_STATUS_IGNORE ? R_f_MPI_STATUS_IGNORE : status_tmp1);
  buffer_a2r(&buf, &buf_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_File_write_all(fh, buf_tmp, count, &datatype_tmp, status_tmp,
                            &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    if (status != A_f_MPI_STATUS_IGNORE)
      status_r2a(status, status_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_write_all\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_iread_(int *, void *, int *, int *, int *, int *);

void mpi_file_iread__(int *, void *, int *, int *, int *, int *);

void pmpi_file_iread_(int *, void *, int *, int *, int *, int *);

void pmpi_file_iread__(int *, void *, int *, int *, int *, int *);

void pmpi_file_iread_(int *, void *, int *, int *, int *, int *);

#define A_f_MPI_File_iread _PMPI_File_iread
#pragma weak mpi_file_iread_ = _PMPI_File_iread
#pragma weak mpi_file_iread__ = _PMPI_File_iread
#pragma weak pmpi_file_iread__ = _PMPI_File_iread
extern long long WI4MPI_File_iread_timeout;
void (*_LOCAL_MPI_File_iread)(int *, void *, int *, int *, int *, int *);

void A_f_MPI_File_iread(int *fh, void *buf, int *count, int *datatype,
                        int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_iread\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_iread_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  int request_tmp;
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_File_iread(fh, buf_tmp, count, &datatype_tmp, &request_tmp,
                        &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&buf, &buf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_iread\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_iwrite_(int *, void *, int *, int *, int *, int *);

void mpi_file_iwrite__(int *, void *, int *, int *, int *, int *);

void pmpi_file_iwrite_(int *, void *, int *, int *, int *, int *);

void pmpi_file_iwrite__(int *, void *, int *, int *, int *, int *);

void pmpi_file_iwrite_(int *, void *, int *, int *, int *, int *);

#define A_f_MPI_File_iwrite _PMPI_File_iwrite
#pragma weak mpi_file_iwrite_ = _PMPI_File_iwrite
#pragma weak mpi_file_iwrite__ = _PMPI_File_iwrite
#pragma weak pmpi_file_iwrite__ = _PMPI_File_iwrite
extern long long WI4MPI_File_iwrite_timeout;
void (*_LOCAL_MPI_File_iwrite)(int *, void *, int *, int *, int *, int *);

void A_f_MPI_File_iwrite(int *fh, void *buf, int *count, int *datatype,
                         int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_iwrite\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_iwrite_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int count_tmp;
  int datatype_tmp;
  int request_tmp;
  buffer_a2r(&buf, &buf_tmp);
  tag_a2r(count, &count_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_File_iwrite(fh, buf_tmp, &count_tmp, &datatype_tmp, &request_tmp,
                         &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_iwrite\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_seek_(int *, int *, int *, int *);

void mpi_file_seek__(int *, int *, int *, int *);

void pmpi_file_seek_(int *, int *, int *, int *);

void pmpi_file_seek__(int *, int *, int *, int *);

void pmpi_file_seek_(int *, int *, int *, int *);

#define A_f_MPI_File_seek _PMPI_File_seek
#pragma weak mpi_file_seek_ = _PMPI_File_seek
#pragma weak mpi_file_seek__ = _PMPI_File_seek
#pragma weak pmpi_file_seek__ = _PMPI_File_seek
extern long long WI4MPI_File_seek_timeout;
void (*_LOCAL_MPI_File_seek)(int *, int *, int *, int *);

void A_f_MPI_File_seek(int *fh, int *offset, int *whence, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_seek\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_seek_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_File_seek(fh, offset, whence, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_seek\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_get_position_(int *, int *, int *);

void mpi_file_get_position__(int *, int *, int *);

void pmpi_file_get_position_(int *, int *, int *);

void pmpi_file_get_position__(int *, int *, int *);

void pmpi_file_get_position_(int *, int *, int *);

#define A_f_MPI_File_get_position _PMPI_File_get_position
#pragma weak mpi_file_get_position_ = _PMPI_File_get_position
#pragma weak mpi_file_get_position__ = _PMPI_File_get_position
#pragma weak pmpi_file_get_position__ = _PMPI_File_get_position
extern long long WI4MPI_File_get_position_timeout;
void (*_LOCAL_MPI_File_get_position)(int *, int *, int *);

void A_f_MPI_File_get_position(int *fh, int *offset, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_get_position\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_get_position_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_File_get_position(fh, offset, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_get_position\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_get_byte_offset_(int *, int *, int *, int *);

void mpi_file_get_byte_offset__(int *, int *, int *, int *);

void pmpi_file_get_byte_offset_(int *, int *, int *, int *);

void pmpi_file_get_byte_offset__(int *, int *, int *, int *);

void pmpi_file_get_byte_offset_(int *, int *, int *, int *);

#define A_f_MPI_File_get_byte_offset _PMPI_File_get_byte_offset
#pragma weak mpi_file_get_byte_offset_ = _PMPI_File_get_byte_offset
#pragma weak mpi_file_get_byte_offset__ = _PMPI_File_get_byte_offset
#pragma weak pmpi_file_get_byte_offset__ = _PMPI_File_get_byte_offset
extern long long WI4MPI_File_get_byte_offset_timeout;
void (*_LOCAL_MPI_File_get_byte_offset)(int *, int *, int *, int *);

void A_f_MPI_File_get_byte_offset(int *fh, int *offset, int *disp, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_get_byte_offset\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_get_byte_offset_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_File_get_byte_offset(fh, offset, disp, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_get_byte_offset\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_read_shared_(int *, void *, int *, int *, int *, int *);

void mpi_file_read_shared__(int *, void *, int *, int *, int *, int *);

void pmpi_file_read_shared_(int *, void *, int *, int *, int *, int *);

void pmpi_file_read_shared__(int *, void *, int *, int *, int *, int *);

void pmpi_file_read_shared_(int *, void *, int *, int *, int *, int *);

#define A_f_MPI_File_read_shared _PMPI_File_read_shared
#pragma weak mpi_file_read_shared_ = _PMPI_File_read_shared
#pragma weak mpi_file_read_shared__ = _PMPI_File_read_shared
#pragma weak pmpi_file_read_shared__ = _PMPI_File_read_shared
extern long long WI4MPI_File_read_shared_timeout;
void (*_LOCAL_MPI_File_read_shared)(int *, void *, int *, int *, int *, int *);

void A_f_MPI_File_read_shared(int *fh, void *buf, int *count, int *datatype,
                              int *status, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_read_shared\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_read_shared_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  int status_tmp1[R_f_MPI_STATUS_SIZE + 1];
  int *status_tmp =
      (status == A_f_MPI_STATUS_IGNORE ? R_f_MPI_STATUS_IGNORE : status_tmp1);
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_File_read_shared(fh, buf_tmp, count, &datatype_tmp, status_tmp,
                              &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&buf, &buf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    if (status != A_f_MPI_STATUS_IGNORE)
      status_r2a(status, status_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_read_shared\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_write_shared_(int *, void *, int *, int *, int *, int *);

void mpi_file_write_shared__(int *, void *, int *, int *, int *, int *);

void pmpi_file_write_shared_(int *, void *, int *, int *, int *, int *);

void pmpi_file_write_shared__(int *, void *, int *, int *, int *, int *);

void pmpi_file_write_shared_(int *, void *, int *, int *, int *, int *);

#define A_f_MPI_File_write_shared _PMPI_File_write_shared
#pragma weak mpi_file_write_shared_ = _PMPI_File_write_shared
#pragma weak mpi_file_write_shared__ = _PMPI_File_write_shared
#pragma weak pmpi_file_write_shared__ = _PMPI_File_write_shared
extern long long WI4MPI_File_write_shared_timeout;
void (*_LOCAL_MPI_File_write_shared)(int *, void *, int *, int *, int *, int *);

void A_f_MPI_File_write_shared(int *fh, void *buf, int *count, int *datatype,
                               int *status, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_write_shared\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_write_shared_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  int status_tmp1[R_f_MPI_STATUS_SIZE + 1];
  int *status_tmp =
      (status == A_f_MPI_STATUS_IGNORE ? R_f_MPI_STATUS_IGNORE : status_tmp1);
  buffer_a2r(&buf, &buf_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_File_write_shared(fh, buf_tmp, count, &datatype_tmp, status_tmp,
                               &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    if (status != A_f_MPI_STATUS_IGNORE)
      status_r2a(status, status_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_write_shared\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_iread_shared_(int *, void *, int *, int *, int *, int *);

void mpi_file_iread_shared__(int *, void *, int *, int *, int *, int *);

void pmpi_file_iread_shared_(int *, void *, int *, int *, int *, int *);

void pmpi_file_iread_shared__(int *, void *, int *, int *, int *, int *);

void pmpi_file_iread_shared_(int *, void *, int *, int *, int *, int *);

#define A_f_MPI_File_iread_shared _PMPI_File_iread_shared
#pragma weak mpi_file_iread_shared_ = _PMPI_File_iread_shared
#pragma weak mpi_file_iread_shared__ = _PMPI_File_iread_shared
#pragma weak pmpi_file_iread_shared__ = _PMPI_File_iread_shared
extern long long WI4MPI_File_iread_shared_timeout;
void (*_LOCAL_MPI_File_iread_shared)(int *, void *, int *, int *, int *, int *);

void A_f_MPI_File_iread_shared(int *fh, void *buf, int *count, int *datatype,
                               int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_iread_shared\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_iread_shared_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  int request_tmp;
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_File_iread_shared(fh, buf_tmp, count, &datatype_tmp, &request_tmp,
                               &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&buf, &buf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_iread_shared\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_iwrite_shared_(int *, void *, int *, int *, int *, int *);

void mpi_file_iwrite_shared__(int *, void *, int *, int *, int *, int *);

void pmpi_file_iwrite_shared_(int *, void *, int *, int *, int *, int *);

void pmpi_file_iwrite_shared__(int *, void *, int *, int *, int *, int *);

void pmpi_file_iwrite_shared_(int *, void *, int *, int *, int *, int *);

#define A_f_MPI_File_iwrite_shared _PMPI_File_iwrite_shared
#pragma weak mpi_file_iwrite_shared_ = _PMPI_File_iwrite_shared
#pragma weak mpi_file_iwrite_shared__ = _PMPI_File_iwrite_shared
#pragma weak pmpi_file_iwrite_shared__ = _PMPI_File_iwrite_shared
extern long long WI4MPI_File_iwrite_shared_timeout;
void (*_LOCAL_MPI_File_iwrite_shared)(int *, void *, int *, int *, int *,
                                      int *);

void A_f_MPI_File_iwrite_shared(int *fh, void *buf, int *count, int *datatype,
                                int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_iwrite_shared\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_iwrite_shared_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  int request_tmp;
  buffer_a2r(&buf, &buf_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_File_iwrite_shared(fh, buf_tmp, count, &datatype_tmp, &request_tmp,
                                &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_iwrite_shared\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_read_ordered_(int *, void *, int *, int *, int *, int *);

void mpi_file_read_ordered__(int *, void *, int *, int *, int *, int *);

void pmpi_file_read_ordered_(int *, void *, int *, int *, int *, int *);

void pmpi_file_read_ordered__(int *, void *, int *, int *, int *, int *);

void pmpi_file_read_ordered_(int *, void *, int *, int *, int *, int *);

#define A_f_MPI_File_read_ordered _PMPI_File_read_ordered
#pragma weak mpi_file_read_ordered_ = _PMPI_File_read_ordered
#pragma weak mpi_file_read_ordered__ = _PMPI_File_read_ordered
#pragma weak pmpi_file_read_ordered__ = _PMPI_File_read_ordered
extern long long WI4MPI_File_read_ordered_timeout;
void (*_LOCAL_MPI_File_read_ordered)(int *, void *, int *, int *, int *, int *);

void A_f_MPI_File_read_ordered(int *fh, void *buf, int *count, int *datatype,
                               int *status, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_read_ordered\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_read_ordered_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  int status_tmp1[R_f_MPI_STATUS_SIZE + 1];
  int *status_tmp =
      (status == A_f_MPI_STATUS_IGNORE ? R_f_MPI_STATUS_IGNORE : status_tmp1);
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_File_read_ordered(fh, buf_tmp, count, &datatype_tmp, status_tmp,
                               &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&buf, &buf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    if (status != A_f_MPI_STATUS_IGNORE)
      status_r2a(status, status_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_read_ordered\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_write_ordered_(int *, void *, int *, int *, int *, int *);

void mpi_file_write_ordered__(int *, void *, int *, int *, int *, int *);

void pmpi_file_write_ordered_(int *, void *, int *, int *, int *, int *);

void pmpi_file_write_ordered__(int *, void *, int *, int *, int *, int *);

void pmpi_file_write_ordered_(int *, void *, int *, int *, int *, int *);

#define A_f_MPI_File_write_ordered _PMPI_File_write_ordered
#pragma weak mpi_file_write_ordered_ = _PMPI_File_write_ordered
#pragma weak mpi_file_write_ordered__ = _PMPI_File_write_ordered
#pragma weak pmpi_file_write_ordered__ = _PMPI_File_write_ordered
extern long long WI4MPI_File_write_ordered_timeout;
void (*_LOCAL_MPI_File_write_ordered)(int *, void *, int *, int *, int *,
                                      int *);

void A_f_MPI_File_write_ordered(int *fh, void *buf, int *count, int *datatype,
                                int *status, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_write_ordered\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_write_ordered_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  int status_tmp1[R_f_MPI_STATUS_SIZE + 1];
  int *status_tmp =
      (status == A_f_MPI_STATUS_IGNORE ? R_f_MPI_STATUS_IGNORE : status_tmp1);
  buffer_a2r(&buf, &buf_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_File_write_ordered(fh, buf_tmp, count, &datatype_tmp, status_tmp,
                                &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    if (status != A_f_MPI_STATUS_IGNORE)
      status_r2a(status, status_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_write_ordered\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_seek_shared_(int *, int *, int *, int *);

void mpi_file_seek_shared__(int *, int *, int *, int *);

void pmpi_file_seek_shared_(int *, int *, int *, int *);

void pmpi_file_seek_shared__(int *, int *, int *, int *);

void pmpi_file_seek_shared_(int *, int *, int *, int *);

#define A_f_MPI_File_seek_shared _PMPI_File_seek_shared
#pragma weak mpi_file_seek_shared_ = _PMPI_File_seek_shared
#pragma weak mpi_file_seek_shared__ = _PMPI_File_seek_shared
#pragma weak pmpi_file_seek_shared__ = _PMPI_File_seek_shared
extern long long WI4MPI_File_seek_shared_timeout;
void (*_LOCAL_MPI_File_seek_shared)(int *, int *, int *, int *);

void A_f_MPI_File_seek_shared(int *fh, int *offset, int *whence, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_seek_shared\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_seek_shared_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_File_seek_shared(fh, offset, whence, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_seek_shared\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_get_position_shared_(int *, int *, int *);

void mpi_file_get_position_shared__(int *, int *, int *);

void pmpi_file_get_position_shared_(int *, int *, int *);

void pmpi_file_get_position_shared__(int *, int *, int *);

void pmpi_file_get_position_shared_(int *, int *, int *);

#define A_f_MPI_File_get_position_shared _PMPI_File_get_position_shared
#pragma weak mpi_file_get_position_shared_ = _PMPI_File_get_position_shared
#pragma weak mpi_file_get_position_shared__ = _PMPI_File_get_position_shared
#pragma weak pmpi_file_get_position_shared__ = _PMPI_File_get_position_shared
extern long long WI4MPI_File_get_position_shared_timeout;
void (*_LOCAL_MPI_File_get_position_shared)(int *, int *, int *);

void A_f_MPI_File_get_position_shared(int *fh, int *offset, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_get_position_shared\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_get_position_shared_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_File_get_position_shared(fh, offset, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_get_position_shared\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_read_at_all_begin_(int *, int *, void *, int *, int *, int *);

void mpi_file_read_at_all_begin__(int *, int *, void *, int *, int *, int *);

void pmpi_file_read_at_all_begin_(int *, int *, void *, int *, int *, int *);

void pmpi_file_read_at_all_begin__(int *, int *, void *, int *, int *, int *);

void pmpi_file_read_at_all_begin_(int *, int *, void *, int *, int *, int *);

#define A_f_MPI_File_read_at_all_begin _PMPI_File_read_at_all_begin
#pragma weak mpi_file_read_at_all_begin_ = _PMPI_File_read_at_all_begin
#pragma weak mpi_file_read_at_all_begin__ = _PMPI_File_read_at_all_begin
#pragma weak pmpi_file_read_at_all_begin__ = _PMPI_File_read_at_all_begin
extern long long WI4MPI_File_read_at_all_begin_timeout;
void (*_LOCAL_MPI_File_read_at_all_begin)(int *, int *, void *, int *, int *,
                                          int *);

void A_f_MPI_File_read_at_all_begin(int *fh, int *offset, void *buf, int *count,
                                    int *datatype, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_read_at_all_begin\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_read_at_all_begin_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_File_read_at_all_begin(fh, offset, buf_tmp, count, &datatype_tmp,
                                    &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&buf, &buf_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_read_at_all_begin\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_read_at_all_end_(int *, void *, int *, int *);

void mpi_file_read_at_all_end__(int *, void *, int *, int *);

void pmpi_file_read_at_all_end_(int *, void *, int *, int *);

void pmpi_file_read_at_all_end__(int *, void *, int *, int *);

void pmpi_file_read_at_all_end_(int *, void *, int *, int *);

#define A_f_MPI_File_read_at_all_end _PMPI_File_read_at_all_end
#pragma weak mpi_file_read_at_all_end_ = _PMPI_File_read_at_all_end
#pragma weak mpi_file_read_at_all_end__ = _PMPI_File_read_at_all_end
#pragma weak pmpi_file_read_at_all_end__ = _PMPI_File_read_at_all_end
extern long long WI4MPI_File_read_at_all_end_timeout;
void (*_LOCAL_MPI_File_read_at_all_end)(int *, void *, int *, int *);

void A_f_MPI_File_read_at_all_end(int *fh, void *buf, int *status, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_read_at_all_end\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_read_at_all_end_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int status_tmp1[R_f_MPI_STATUS_SIZE + 1];
  int *status_tmp =
      (status == A_f_MPI_STATUS_IGNORE ? R_f_MPI_STATUS_IGNORE : status_tmp1);
  _LOCAL_MPI_File_read_at_all_end(fh, buf_tmp, status_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&buf, &buf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    if (status != A_f_MPI_STATUS_IGNORE)
      status_r2a(status, status_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_read_at_all_end\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_write_at_all_begin_(int *, int *, void *, int *, int *, int *);

void mpi_file_write_at_all_begin__(int *, int *, void *, int *, int *, int *);

void pmpi_file_write_at_all_begin_(int *, int *, void *, int *, int *, int *);

void pmpi_file_write_at_all_begin__(int *, int *, void *, int *, int *, int *);

void pmpi_file_write_at_all_begin_(int *, int *, void *, int *, int *, int *);

#define A_f_MPI_File_write_at_all_begin _PMPI_File_write_at_all_begin
#pragma weak mpi_file_write_at_all_begin_ = _PMPI_File_write_at_all_begin
#pragma weak mpi_file_write_at_all_begin__ = _PMPI_File_write_at_all_begin
#pragma weak pmpi_file_write_at_all_begin__ = _PMPI_File_write_at_all_begin
extern long long WI4MPI_File_write_at_all_begin_timeout;
void (*_LOCAL_MPI_File_write_at_all_begin)(int *, int *, void *, int *, int *,
                                           int *);

void A_f_MPI_File_write_at_all_begin(int *fh, int *offset, void *buf,
                                     int *count, int *datatype, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_write_at_all_begin\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_write_at_all_begin_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  buffer_a2r(&buf, &buf_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_File_write_at_all_begin(fh, offset, buf_tmp, count, &datatype_tmp,
                                     &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_write_at_all_begin\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_write_at_all_end_(int *, void *, int *, int *);

void mpi_file_write_at_all_end__(int *, void *, int *, int *);

void pmpi_file_write_at_all_end_(int *, void *, int *, int *);

void pmpi_file_write_at_all_end__(int *, void *, int *, int *);

void pmpi_file_write_at_all_end_(int *, void *, int *, int *);

#define A_f_MPI_File_write_at_all_end _PMPI_File_write_at_all_end
#pragma weak mpi_file_write_at_all_end_ = _PMPI_File_write_at_all_end
#pragma weak mpi_file_write_at_all_end__ = _PMPI_File_write_at_all_end
#pragma weak pmpi_file_write_at_all_end__ = _PMPI_File_write_at_all_end
extern long long WI4MPI_File_write_at_all_end_timeout;
void (*_LOCAL_MPI_File_write_at_all_end)(int *, void *, int *, int *);

void A_f_MPI_File_write_at_all_end(int *fh, void *buf, int *status, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_write_at_all_end\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_write_at_all_end_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int status_tmp1[R_f_MPI_STATUS_SIZE + 1];
  int *status_tmp =
      (status == A_f_MPI_STATUS_IGNORE ? R_f_MPI_STATUS_IGNORE : status_tmp1);
  buffer_a2r(&buf, &buf_tmp);
  _LOCAL_MPI_File_write_at_all_end(fh, buf_tmp, status_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    if (status != A_f_MPI_STATUS_IGNORE)
      status_r2a(status, status_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_write_at_all_end\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_read_all_begin_(int *, void *, int *, int *, int *);

void mpi_file_read_all_begin__(int *, void *, int *, int *, int *);

void pmpi_file_read_all_begin_(int *, void *, int *, int *, int *);

void pmpi_file_read_all_begin__(int *, void *, int *, int *, int *);

void pmpi_file_read_all_begin_(int *, void *, int *, int *, int *);

#define A_f_MPI_File_read_all_begin _PMPI_File_read_all_begin
#pragma weak mpi_file_read_all_begin_ = _PMPI_File_read_all_begin
#pragma weak mpi_file_read_all_begin__ = _PMPI_File_read_all_begin
#pragma weak pmpi_file_read_all_begin__ = _PMPI_File_read_all_begin
extern long long WI4MPI_File_read_all_begin_timeout;
void (*_LOCAL_MPI_File_read_all_begin)(int *, void *, int *, int *, int *);

void A_f_MPI_File_read_all_begin(int *fh, void *buf, int *count, int *datatype,
                                 int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_read_all_begin\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_read_all_begin_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_File_read_all_begin(fh, buf_tmp, count, &datatype_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&buf, &buf_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_read_all_begin\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_read_all_end_(int *, void *, int *, int *);

void mpi_file_read_all_end__(int *, void *, int *, int *);

void pmpi_file_read_all_end_(int *, void *, int *, int *);

void pmpi_file_read_all_end__(int *, void *, int *, int *);

void pmpi_file_read_all_end_(int *, void *, int *, int *);

#define A_f_MPI_File_read_all_end _PMPI_File_read_all_end
#pragma weak mpi_file_read_all_end_ = _PMPI_File_read_all_end
#pragma weak mpi_file_read_all_end__ = _PMPI_File_read_all_end
#pragma weak pmpi_file_read_all_end__ = _PMPI_File_read_all_end
extern long long WI4MPI_File_read_all_end_timeout;
void (*_LOCAL_MPI_File_read_all_end)(int *, void *, int *, int *);

void A_f_MPI_File_read_all_end(int *fh, void *buf, int *status, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_read_all_end\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_read_all_end_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int status_tmp1[R_f_MPI_STATUS_SIZE + 1];
  int *status_tmp =
      (status == A_f_MPI_STATUS_IGNORE ? R_f_MPI_STATUS_IGNORE : status_tmp1);
  _LOCAL_MPI_File_read_all_end(fh, buf_tmp, status_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&buf, &buf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    if (status != A_f_MPI_STATUS_IGNORE)
      status_r2a(status, status_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_read_all_end\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_write_all_begin_(int *, void *, int *, int *, int *);

void mpi_file_write_all_begin__(int *, void *, int *, int *, int *);

void pmpi_file_write_all_begin_(int *, void *, int *, int *, int *);

void pmpi_file_write_all_begin__(int *, void *, int *, int *, int *);

void pmpi_file_write_all_begin_(int *, void *, int *, int *, int *);

#define A_f_MPI_File_write_all_begin _PMPI_File_write_all_begin
#pragma weak mpi_file_write_all_begin_ = _PMPI_File_write_all_begin
#pragma weak mpi_file_write_all_begin__ = _PMPI_File_write_all_begin
#pragma weak pmpi_file_write_all_begin__ = _PMPI_File_write_all_begin
extern long long WI4MPI_File_write_all_begin_timeout;
void (*_LOCAL_MPI_File_write_all_begin)(int *, void *, int *, int *, int *);

void A_f_MPI_File_write_all_begin(int *fh, void *buf, int *count, int *datatype,
                                  int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_write_all_begin\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_write_all_begin_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int count_tmp;
  int datatype_tmp;
  buffer_a2r(&buf, &buf_tmp);
  tag_a2r(count, &count_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_File_write_all_begin(fh, buf_tmp, &count_tmp, &datatype_tmp,
                                  &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_write_all_begin\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_write_all_end_(int *, void *, int *, int *);

void mpi_file_write_all_end__(int *, void *, int *, int *);

void pmpi_file_write_all_end_(int *, void *, int *, int *);

void pmpi_file_write_all_end__(int *, void *, int *, int *);

void pmpi_file_write_all_end_(int *, void *, int *, int *);

#define A_f_MPI_File_write_all_end _PMPI_File_write_all_end
#pragma weak mpi_file_write_all_end_ = _PMPI_File_write_all_end
#pragma weak mpi_file_write_all_end__ = _PMPI_File_write_all_end
#pragma weak pmpi_file_write_all_end__ = _PMPI_File_write_all_end
extern long long WI4MPI_File_write_all_end_timeout;
void (*_LOCAL_MPI_File_write_all_end)(int *, void *, int *, int *);

void A_f_MPI_File_write_all_end(int *fh, void *buf, int *status, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_write_all_end\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_write_all_end_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int status_tmp1[R_f_MPI_STATUS_SIZE + 1];
  int *status_tmp =
      (status == A_f_MPI_STATUS_IGNORE ? R_f_MPI_STATUS_IGNORE : status_tmp1);
  buffer_a2r(&buf, &buf_tmp);
  _LOCAL_MPI_File_write_all_end(fh, buf_tmp, status_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    if (status != A_f_MPI_STATUS_IGNORE)
      status_r2a(status, status_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_write_all_end\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_read_ordered_begin_(int *, void *, int *, int *, int *);

void mpi_file_read_ordered_begin__(int *, void *, int *, int *, int *);

void pmpi_file_read_ordered_begin_(int *, void *, int *, int *, int *);

void pmpi_file_read_ordered_begin__(int *, void *, int *, int *, int *);

void pmpi_file_read_ordered_begin_(int *, void *, int *, int *, int *);

#define A_f_MPI_File_read_ordered_begin _PMPI_File_read_ordered_begin
#pragma weak mpi_file_read_ordered_begin_ = _PMPI_File_read_ordered_begin
#pragma weak mpi_file_read_ordered_begin__ = _PMPI_File_read_ordered_begin
#pragma weak pmpi_file_read_ordered_begin__ = _PMPI_File_read_ordered_begin
extern long long WI4MPI_File_read_ordered_begin_timeout;
void (*_LOCAL_MPI_File_read_ordered_begin)(int *, void *, int *, int *, int *);

void A_f_MPI_File_read_ordered_begin(int *fh, void *buf, int *count,
                                     int *datatype, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_read_ordered_begin\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_read_ordered_begin_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_File_read_ordered_begin(fh, buf_tmp, count, &datatype_tmp,
                                     &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&buf, &buf_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_read_ordered_begin\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_read_ordered_end_(int *, void *, int *, int *);

void mpi_file_read_ordered_end__(int *, void *, int *, int *);

void pmpi_file_read_ordered_end_(int *, void *, int *, int *);

void pmpi_file_read_ordered_end__(int *, void *, int *, int *);

void pmpi_file_read_ordered_end_(int *, void *, int *, int *);

#define A_f_MPI_File_read_ordered_end _PMPI_File_read_ordered_end
#pragma weak mpi_file_read_ordered_end_ = _PMPI_File_read_ordered_end
#pragma weak mpi_file_read_ordered_end__ = _PMPI_File_read_ordered_end
#pragma weak pmpi_file_read_ordered_end__ = _PMPI_File_read_ordered_end
extern long long WI4MPI_File_read_ordered_end_timeout;
void (*_LOCAL_MPI_File_read_ordered_end)(int *, void *, int *, int *);

void A_f_MPI_File_read_ordered_end(int *fh, void *buf, int *status, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_read_ordered_end\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_read_ordered_end_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int status_tmp1[R_f_MPI_STATUS_SIZE + 1];
  int *status_tmp =
      (status == A_f_MPI_STATUS_IGNORE ? R_f_MPI_STATUS_IGNORE : status_tmp1);
  _LOCAL_MPI_File_read_ordered_end(fh, buf_tmp, status_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&buf, &buf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    if (status != A_f_MPI_STATUS_IGNORE)
      status_r2a(status, status_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_read_ordered_end\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_write_ordered_begin_(int *, void *, int *, int *, int *);

void mpi_file_write_ordered_begin__(int *, void *, int *, int *, int *);

void pmpi_file_write_ordered_begin_(int *, void *, int *, int *, int *);

void pmpi_file_write_ordered_begin__(int *, void *, int *, int *, int *);

void pmpi_file_write_ordered_begin_(int *, void *, int *, int *, int *);

#define A_f_MPI_File_write_ordered_begin _PMPI_File_write_ordered_begin
#pragma weak mpi_file_write_ordered_begin_ = _PMPI_File_write_ordered_begin
#pragma weak mpi_file_write_ordered_begin__ = _PMPI_File_write_ordered_begin
#pragma weak pmpi_file_write_ordered_begin__ = _PMPI_File_write_ordered_begin
extern long long WI4MPI_File_write_ordered_begin_timeout;
void (*_LOCAL_MPI_File_write_ordered_begin)(int *, void *, int *, int *, int *);

void A_f_MPI_File_write_ordered_begin(int *fh, void *buf, int *count,
                                      int *datatype, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_write_ordered_begin\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_write_ordered_begin_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  buffer_a2r(&buf, &buf_tmp);
  _LOCAL_MPI_File_write_ordered_begin(fh, buf_tmp, count, &datatype_tmp,
                                      &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    datatype_r2a(datatype, &datatype_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_write_ordered_begin\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_write_ordered_end_(int *, void *, int *, int *);

void mpi_file_write_ordered_end__(int *, void *, int *, int *);

void pmpi_file_write_ordered_end_(int *, void *, int *, int *);

void pmpi_file_write_ordered_end__(int *, void *, int *, int *);

void pmpi_file_write_ordered_end_(int *, void *, int *, int *);

#define A_f_MPI_File_write_ordered_end _PMPI_File_write_ordered_end
#pragma weak mpi_file_write_ordered_end_ = _PMPI_File_write_ordered_end
#pragma weak mpi_file_write_ordered_end__ = _PMPI_File_write_ordered_end
#pragma weak pmpi_file_write_ordered_end__ = _PMPI_File_write_ordered_end
extern long long WI4MPI_File_write_ordered_end_timeout;
void (*_LOCAL_MPI_File_write_ordered_end)(int *, void *, int *, int *);

void A_f_MPI_File_write_ordered_end(int *fh, void *buf, int *status, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_write_ordered_end\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_write_ordered_end_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int status_tmp1[R_f_MPI_STATUS_SIZE + 1];
  int *status_tmp =
      (status == A_f_MPI_STATUS_IGNORE ? R_f_MPI_STATUS_IGNORE : status_tmp1);
  buffer_a2r(&buf, &buf_tmp);
  _LOCAL_MPI_File_write_ordered_end(fh, buf_tmp, status_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    if (status != A_f_MPI_STATUS_IGNORE)
      status_r2a(status, status_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_write_ordered_end\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_get_type_extent_(int *, int *, size_t *, int *);

void mpi_file_get_type_extent__(int *, int *, size_t *, int *);

void pmpi_file_get_type_extent_(int *, int *, size_t *, int *);

void pmpi_file_get_type_extent__(int *, int *, size_t *, int *);

void pmpi_file_get_type_extent_(int *, int *, size_t *, int *);

#define A_f_MPI_File_get_type_extent _PMPI_File_get_type_extent
#pragma weak mpi_file_get_type_extent_ = _PMPI_File_get_type_extent
#pragma weak mpi_file_get_type_extent__ = _PMPI_File_get_type_extent
#pragma weak pmpi_file_get_type_extent__ = _PMPI_File_get_type_extent
extern long long WI4MPI_File_get_type_extent_timeout;
void (*_LOCAL_MPI_File_get_type_extent)(int *, int *, size_t *, int *);

void A_f_MPI_File_get_type_extent(int *fh, int *datatype, size_t *extent,
                                  int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_get_type_extent\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_get_type_extent_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int datatype_tmp;
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_File_get_type_extent(fh, &datatype_tmp, extent, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_get_type_extent\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_set_atomicity_(int *, int *, int *);

void mpi_file_set_atomicity__(int *, int *, int *);

void pmpi_file_set_atomicity_(int *, int *, int *);

void pmpi_file_set_atomicity__(int *, int *, int *);

void pmpi_file_set_atomicity_(int *, int *, int *);

#define A_f_MPI_File_set_atomicity _PMPI_File_set_atomicity
#pragma weak mpi_file_set_atomicity_ = _PMPI_File_set_atomicity
#pragma weak mpi_file_set_atomicity__ = _PMPI_File_set_atomicity
#pragma weak pmpi_file_set_atomicity__ = _PMPI_File_set_atomicity
extern long long WI4MPI_File_set_atomicity_timeout;
void (*_LOCAL_MPI_File_set_atomicity)(int *, int *, int *);

void A_f_MPI_File_set_atomicity(int *fh, int *flag, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_set_atomicity\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_set_atomicity_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_File_set_atomicity(fh, flag, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_set_atomicity\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_get_atomicity_(int *, int *, int *);

void mpi_file_get_atomicity__(int *, int *, int *);

void pmpi_file_get_atomicity_(int *, int *, int *);

void pmpi_file_get_atomicity__(int *, int *, int *);

void pmpi_file_get_atomicity_(int *, int *, int *);

#define A_f_MPI_File_get_atomicity _PMPI_File_get_atomicity
#pragma weak mpi_file_get_atomicity_ = _PMPI_File_get_atomicity
#pragma weak mpi_file_get_atomicity__ = _PMPI_File_get_atomicity
#pragma weak pmpi_file_get_atomicity__ = _PMPI_File_get_atomicity
extern long long WI4MPI_File_get_atomicity_timeout;
void (*_LOCAL_MPI_File_get_atomicity)(int *, int *, int *);

void A_f_MPI_File_get_atomicity(int *fh, int *flag, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_get_atomicity\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_get_atomicity_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_File_get_atomicity(fh, flag, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_get_atomicity\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_sync_(int *, int *);

void mpi_file_sync__(int *, int *);

void pmpi_file_sync_(int *, int *);

void pmpi_file_sync__(int *, int *);

void pmpi_file_sync_(int *, int *);

#define A_f_MPI_File_sync _PMPI_File_sync
#pragma weak mpi_file_sync_ = _PMPI_File_sync
#pragma weak mpi_file_sync__ = _PMPI_File_sync
#pragma weak pmpi_file_sync__ = _PMPI_File_sync
extern long long WI4MPI_File_sync_timeout;
void (*_LOCAL_MPI_File_sync)(int *, int *);

void A_f_MPI_File_sync(int *fh, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_sync\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_sync_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_File_sync(fh, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_sync\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_wtime_(double *);

void mpi_wtime__(double *);

void pmpi_wtime_(double *);

void pmpi_wtime__(double *);

void pmpi_wtime_(double *);

#define A_f_MPI_Wtime _PMPI_Wtime
#pragma weak mpi_wtime_ = _PMPI_Wtime
#pragma weak mpi_wtime__ = _PMPI_Wtime
#pragma weak pmpi_wtime__ = _PMPI_Wtime
extern long long WI4MPI_Wtime_timeout;
void (*_LOCAL_MPI_Wtime)(double *);

void A_f_MPI_Wtime(double *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Wtime\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Wtime_timeout);
#endif
  in_w = 1;
  double ret_tmp = 0;

  _LOCAL_MPI_Wtime(&ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Wtime\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_wtick_(double *);

void mpi_wtick__(double *);

void pmpi_wtick_(double *);

void pmpi_wtick__(double *);

void pmpi_wtick_(double *);

#define A_f_MPI_Wtick _PMPI_Wtick
#pragma weak mpi_wtick_ = _PMPI_Wtick
#pragma weak mpi_wtick__ = _PMPI_Wtick
#pragma weak pmpi_wtick__ = _PMPI_Wtick
extern long long WI4MPI_Wtick_timeout;
void (*_LOCAL_MPI_Wtick)(double *);

void A_f_MPI_Wtick(double *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Wtick\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Wtick_timeout);
#endif
  in_w = 1;
  double ret_tmp = 0;

  _LOCAL_MPI_Wtick(&ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Wtick\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_finalize_(int *);

void mpi_finalize__(int *);

void pmpi_finalize_(int *);

void pmpi_finalize__(int *);

void pmpi_finalize_(int *);

#define A_f_MPI_Finalize _PMPI_Finalize
#pragma weak mpi_finalize_ = _PMPI_Finalize
#pragma weak mpi_finalize__ = _PMPI_Finalize
#pragma weak pmpi_finalize__ = _PMPI_Finalize
extern long long WI4MPI_Finalize_timeout;
void (*_LOCAL_MPI_Finalize)(int *);

void A_f_MPI_Finalize(int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Finalize\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Finalize_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_Finalize(&ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Finalize\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_waitany_(int *, int *, int *, int *, int *);

void mpi_waitany__(int *, int *, int *, int *, int *);

void pmpi_waitany_(int *, int *, int *, int *, int *);

void pmpi_waitany__(int *, int *, int *, int *, int *);

void pmpi_waitany_(int *, int *, int *, int *, int *);

#define A_f_MPI_Waitany _PMPI_Waitany
#pragma weak mpi_waitany_ = _PMPI_Waitany
#pragma weak mpi_waitany__ = _PMPI_Waitany
#pragma weak pmpi_waitany__ = _PMPI_Waitany
extern long long WI4MPI_Waitany_timeout;
void (*_LOCAL_MPI_Waitany)(int *, int *, int *, int *, int *);

void A_f_MPI_Waitany(int *count, int *array_of_requests, int *indx, int *status,
                     int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Waitany\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Waitany_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int *array_of_requests_tmp = (int *)wi4mpi_alloc((*count) * 1 * sizeof(int));
  int status_tmp1[R_f_MPI_STATUS_SIZE + 1];
  int *status_tmp =
      (status == A_f_MPI_STATUS_IGNORE ? R_f_MPI_STATUS_IGNORE : status_tmp1);
  for (int i = 0; i < *count; i++)
    request_a2r(&array_of_requests[i * 1], &array_of_requests_tmp[i * 1]);
  _LOCAL_MPI_Waitany(count, array_of_requests_tmp, indx, status_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    for (int i = 0; i < *count; i++)
      request_r2a(&array_of_requests[i * 1], &array_of_requests_tmp[i * 1]);
  wi4mpi_free(array_of_requests_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    if (status != A_f_MPI_STATUS_IGNORE)
      status_r2a(status, status_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Waitany\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_testany_(int *, int *, int *, int *, int *, int *);

void mpi_testany__(int *, int *, int *, int *, int *, int *);

void pmpi_testany_(int *, int *, int *, int *, int *, int *);

void pmpi_testany__(int *, int *, int *, int *, int *, int *);

void pmpi_testany_(int *, int *, int *, int *, int *, int *);

#define A_f_MPI_Testany _PMPI_Testany
#pragma weak mpi_testany_ = _PMPI_Testany
#pragma weak mpi_testany__ = _PMPI_Testany
#pragma weak pmpi_testany__ = _PMPI_Testany
extern long long WI4MPI_Testany_timeout;
void (*_LOCAL_MPI_Testany)(int *, int *, int *, int *, int *, int *);

void A_f_MPI_Testany(int *count, int *array_of_requests, int *indx, int *flag,
                     int *status, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Testany\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Testany_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int *array_of_requests_tmp = (int *)wi4mpi_alloc((*count) * 1 * sizeof(int));
  int status_tmp1[R_f_MPI_STATUS_SIZE + 1];
  int *status_tmp =
      (status == A_f_MPI_STATUS_IGNORE ? R_f_MPI_STATUS_IGNORE : status_tmp1);
  for (int i = 0; i < *count; i++)
    request_a2r(&array_of_requests[i * 1], &array_of_requests_tmp[i * 1]);
  _LOCAL_MPI_Testany(count, array_of_requests_tmp, indx, flag, status_tmp,
                     &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    for (int i = 0; i < *count; i++)
      request_r2a(&array_of_requests[i * 1], &array_of_requests_tmp[i * 1]);
  wi4mpi_free(array_of_requests_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    if (status != A_f_MPI_STATUS_IGNORE)
      status_r2a(status, status_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Testany\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_waitall_(int *, int *, int *, int *);

void mpi_waitall__(int *, int *, int *, int *);

void pmpi_waitall_(int *, int *, int *, int *);

void pmpi_waitall__(int *, int *, int *, int *);

void pmpi_waitall_(int *, int *, int *, int *);

#define A_f_MPI_Waitall _PMPI_Waitall
#pragma weak mpi_waitall_ = _PMPI_Waitall
#pragma weak mpi_waitall__ = _PMPI_Waitall
#pragma weak pmpi_waitall__ = _PMPI_Waitall
extern long long WI4MPI_Waitall_timeout;
void (*_LOCAL_MPI_Waitall)(int *, int *, int *, int *);

void A_f_MPI_Waitall(int *count, int *array_of_requests, int *array_of_statuses,
                     int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Waitall\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Waitall_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int *array_of_requests_tmp = (int *)wi4mpi_alloc((*count) * 1 * sizeof(int));
  int *array_of_statuses_tmp =
      (array_of_statuses == A_f_MPI_STATUSES_IGNORE
           ? R_f_MPI_STATUSES_IGNORE
           : (int *)wi4mpi_alloc((*count) * (R_f_MPI_STATUS_SIZE + 1) *
                                 sizeof(int)));
  for (int i = 0; i < *count; i++)
    request_a2r(&array_of_requests[i * 1], &array_of_requests_tmp[i * 1]);
  _LOCAL_MPI_Waitall(count, array_of_requests_tmp, array_of_statuses_tmp,
                     &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    for (int i = 0; i < *count; i++)
      request_r2a(&array_of_requests[i * 1], &array_of_requests_tmp[i * 1]);
  wi4mpi_free(array_of_requests_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    if (array_of_statuses != A_f_MPI_STATUSES_IGNORE)
      for (int i = 0; i < *count; i++)
        status_r2a(&array_of_statuses[i * A_f_MPI_STATUS_SIZE],
                   &array_of_statuses_tmp[i * R_f_MPI_STATUS_SIZE]);
  if (array_of_statuses != A_f_MPI_STATUSES_IGNORE)
    wi4mpi_free(array_of_statuses_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Waitall\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_testall_(int *, int *, int *, int *, int *);

void mpi_testall__(int *, int *, int *, int *, int *);

void pmpi_testall_(int *, int *, int *, int *, int *);

void pmpi_testall__(int *, int *, int *, int *, int *);

void pmpi_testall_(int *, int *, int *, int *, int *);

#define A_f_MPI_Testall _PMPI_Testall
#pragma weak mpi_testall_ = _PMPI_Testall
#pragma weak mpi_testall__ = _PMPI_Testall
#pragma weak pmpi_testall__ = _PMPI_Testall
extern long long WI4MPI_Testall_timeout;
void (*_LOCAL_MPI_Testall)(int *, int *, int *, int *, int *);

void A_f_MPI_Testall(int *count, int *array_of_requests, int *flag,
                     int *array_of_statuses, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Testall\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Testall_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int *array_of_requests_tmp = (int *)wi4mpi_alloc((*count) * 1 * sizeof(int));
  int *array_of_statuses_tmp =
      (array_of_statuses == A_f_MPI_STATUSES_IGNORE
           ? R_f_MPI_STATUSES_IGNORE
           : (int *)wi4mpi_alloc((*count) * (R_f_MPI_STATUS_SIZE + 1) *
                                 sizeof(int)));
  for (int i = 0; i < *count; i++)
    request_a2r(&array_of_requests[i * 1], &array_of_requests_tmp[i * 1]);
  _LOCAL_MPI_Testall(count, array_of_requests_tmp, flag, array_of_statuses_tmp,
                     &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    for (int i = 0; i < *count; i++)
      request_r2a(&array_of_requests[i * 1], &array_of_requests_tmp[i * 1]);
  wi4mpi_free(array_of_requests_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    if (array_of_statuses != A_f_MPI_STATUSES_IGNORE)
      for (int i = 0; i < *count; i++)
        status_r2a(&array_of_statuses[i * A_f_MPI_STATUS_SIZE],
                   &array_of_statuses_tmp[i * R_f_MPI_STATUS_SIZE]);
  if (array_of_statuses != A_f_MPI_STATUSES_IGNORE)
    wi4mpi_free(array_of_statuses_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Testall\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_waitsome_(int *, int *, int *, int *, int *, int *);

void mpi_waitsome__(int *, int *, int *, int *, int *, int *);

void pmpi_waitsome_(int *, int *, int *, int *, int *, int *);

void pmpi_waitsome__(int *, int *, int *, int *, int *, int *);

void pmpi_waitsome_(int *, int *, int *, int *, int *, int *);

#define A_f_MPI_Waitsome _PMPI_Waitsome
#pragma weak mpi_waitsome_ = _PMPI_Waitsome
#pragma weak mpi_waitsome__ = _PMPI_Waitsome
#pragma weak pmpi_waitsome__ = _PMPI_Waitsome
extern long long WI4MPI_Waitsome_timeout;
void (*_LOCAL_MPI_Waitsome)(int *, int *, int *, int *, int *, int *);

void A_f_MPI_Waitsome(int *incount, int *array_of_requests, int *outcount,
                      int *array_of_indices, int *array_of_statuses, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Waitsome\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Waitsome_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int *array_of_requests_tmp =
      (int *)wi4mpi_alloc((*incount) * 1 * sizeof(int));
  int *array_of_statuses_tmp =
      (array_of_statuses == A_f_MPI_STATUSES_IGNORE
           ? R_f_MPI_STATUSES_IGNORE
           : (int *)wi4mpi_alloc((*incount) * (R_f_MPI_STATUS_SIZE + 1) *
                                 sizeof(int)));
  for (int i = 0; i < *incount; i++)
    request_a2r(&array_of_requests[i * 1], &array_of_requests_tmp[i * 1]);
  _LOCAL_MPI_Waitsome(incount, array_of_requests_tmp, outcount,
                      array_of_indices, array_of_statuses_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    for (int i = 0; i < *incount; i++)
      request_r2a(&array_of_requests[i * 1], &array_of_requests_tmp[i * 1]);
  wi4mpi_free(array_of_requests_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    if (array_of_statuses != A_f_MPI_STATUSES_IGNORE)
      for (int i = 0; i < *incount; i++)
        status_r2a(&array_of_statuses[i * A_f_MPI_STATUS_SIZE],
                   &array_of_statuses_tmp[i * R_f_MPI_STATUS_SIZE]);
  if (array_of_statuses != A_f_MPI_STATUSES_IGNORE)
    wi4mpi_free(array_of_statuses_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Waitsome\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_testsome_(int *, int *, int *, int *, int *, int *);

void mpi_testsome__(int *, int *, int *, int *, int *, int *);

void pmpi_testsome_(int *, int *, int *, int *, int *, int *);

void pmpi_testsome__(int *, int *, int *, int *, int *, int *);

void pmpi_testsome_(int *, int *, int *, int *, int *, int *);

#define A_f_MPI_Testsome _PMPI_Testsome
#pragma weak mpi_testsome_ = _PMPI_Testsome
#pragma weak mpi_testsome__ = _PMPI_Testsome
#pragma weak pmpi_testsome__ = _PMPI_Testsome
extern long long WI4MPI_Testsome_timeout;
void (*_LOCAL_MPI_Testsome)(int *, int *, int *, int *, int *, int *);

void A_f_MPI_Testsome(int *incount, int *array_of_requests, int *outcount,
                      int *array_of_indices, int *array_of_statuses, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Testsome\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Testsome_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int *array_of_requests_tmp =
      (int *)wi4mpi_alloc((*incount) * 1 * sizeof(int));
  int *array_of_statuses_tmp =
      (array_of_statuses == A_f_MPI_STATUSES_IGNORE
           ? R_f_MPI_STATUSES_IGNORE
           : (int *)wi4mpi_alloc((*incount) * (R_f_MPI_STATUS_SIZE + 1) *
                                 sizeof(int)));
  for (int i = 0; i < *incount; i++)
    request_a2r(&array_of_requests[i * 1], &array_of_requests_tmp[i * 1]);
  _LOCAL_MPI_Testsome(incount, array_of_requests_tmp, outcount,
                      array_of_indices, array_of_statuses_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    for (int i = 0; i < *incount; i++)
      request_r2a(&array_of_requests[i * 1], &array_of_requests_tmp[i * 1]);
  wi4mpi_free(array_of_requests_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    if (array_of_statuses != A_f_MPI_STATUSES_IGNORE)
      for (int i = 0; i < *incount; i++)
        status_r2a(&array_of_statuses[i * A_f_MPI_STATUS_SIZE],
                   &array_of_statuses_tmp[i * R_f_MPI_STATUS_SIZE]);
  if (array_of_statuses != A_f_MPI_STATUSES_IGNORE)
    wi4mpi_free(array_of_statuses_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Testsome\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_startall_(int *, int *, int *);

void mpi_startall__(int *, int *, int *);

void pmpi_startall_(int *, int *, int *);

void pmpi_startall__(int *, int *, int *);

void pmpi_startall_(int *, int *, int *);

#define A_f_MPI_Startall _PMPI_Startall
#pragma weak mpi_startall_ = _PMPI_Startall
#pragma weak mpi_startall__ = _PMPI_Startall
#pragma weak pmpi_startall__ = _PMPI_Startall
extern long long WI4MPI_Startall_timeout;
void (*_LOCAL_MPI_Startall)(int *, int *, int *);

void A_f_MPI_Startall(int *count, int *array_of_requests, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Startall\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Startall_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int *array_of_requests_tmp = (int *)wi4mpi_alloc((*count) * 1 * sizeof(int));
  for (int i = 0; i < *count; i++)
    request_a2r(&array_of_requests[i * 1], &array_of_requests_tmp[i * 1]);
  _LOCAL_MPI_Startall(count, array_of_requests_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    for (int i = 0; i < *count; i++)
      request_r2a(&array_of_requests[i * 1], &array_of_requests_tmp[i * 1]);
  wi4mpi_free(array_of_requests_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Startall\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_alltoallw_(void *, int *, int *, int *, void *, int *, int *, int *,
                    int *, int *);

void mpi_alltoallw__(void *, int *, int *, int *, void *, int *, int *, int *,
                     int *, int *);

void pmpi_alltoallw_(void *, int *, int *, int *, void *, int *, int *, int *,
                     int *, int *);

void pmpi_alltoallw__(void *, int *, int *, int *, void *, int *, int *, int *,
                      int *, int *);

void pmpi_alltoallw_(void *, int *, int *, int *, void *, int *, int *, int *,
                     int *, int *);

#define A_f_MPI_Alltoallw _PMPI_Alltoallw
#pragma weak mpi_alltoallw_ = _PMPI_Alltoallw
#pragma weak mpi_alltoallw__ = _PMPI_Alltoallw
#pragma weak pmpi_alltoallw__ = _PMPI_Alltoallw
extern long long WI4MPI_Alltoallw_timeout;
void (*_LOCAL_MPI_Alltoallw)(void *, int *, int *, int *, void *, int *, int *,
                             int *, int *, int *);

void A_f_MPI_Alltoallw(void *sendbuf, int *sendcounts, int *sdispls,
                       int *sendtypes, void *recvbuf, int *recvcounts,
                       int *rdispls, int *recvtypes, int *comm, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Alltoallw\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Alltoallw_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;
  int comm_tmp1, ierr;
  comm_a2r(comm, &comm_tmp1);
  int *Comm_size;
  _LOCAL_MPI_Comm_size(&comm_tmp1, Comm_size, &ierr);
  void *sendbuf_tmp = sendbuf;
  int sendtypes_tmp;
  void *recvbuf_tmp = recvbuf;
  int recvtypes_tmp;
  int comm_tmp;
  buffer_a2r(&sendbuf, &sendbuf_tmp);
  datatype_a2r(sendtypes, &sendtypes_tmp);
  buffer_a2r(&recvbuf, &recvbuf_tmp);
  datatype_a2r(recvtypes, &recvtypes_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Alltoallw(sendbuf_tmp, sendcounts, sdispls, &sendtypes_tmp,
                       recvbuf_tmp, recvcounts, rdispls, &recvtypes_tmp,
                       &comm_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&recvbuf, &recvbuf_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Alltoallw\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_reduce_scatter_(void *, void *, int *, int *, int *, int *, int *);

void mpi_reduce_scatter__(void *, void *, int *, int *, int *, int *, int *);

void pmpi_reduce_scatter_(void *, void *, int *, int *, int *, int *, int *);

void pmpi_reduce_scatter__(void *, void *, int *, int *, int *, int *, int *);

void pmpi_reduce_scatter_(void *, void *, int *, int *, int *, int *, int *);

#define A_f_MPI_Reduce_scatter _PMPI_Reduce_scatter
#pragma weak mpi_reduce_scatter_ = _PMPI_Reduce_scatter
#pragma weak mpi_reduce_scatter__ = _PMPI_Reduce_scatter
#pragma weak pmpi_reduce_scatter__ = _PMPI_Reduce_scatter
extern long long WI4MPI_Reduce_scatter_timeout;
void (*_LOCAL_MPI_Reduce_scatter)(void *, void *, int *, int *, int *, int *,
                                  int *);

void A_f_MPI_Reduce_scatter(void *sendbuf, void *recvbuf, int *recvcounts,
                            int *datatype, int *op, int *comm, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Reduce_scatter\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Reduce_scatter_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *sendbuf_tmp = sendbuf;
  void *recvbuf_tmp = recvbuf;
  int datatype_tmp;
  int op_tmp;
  int comm_tmp;
  buffer_a2r(&sendbuf, &sendbuf_tmp);
  buffer_a2r(&recvbuf, &recvbuf_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  operator_a2r(op, &op_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Reduce_scatter(sendbuf_tmp, recvbuf_tmp, recvcounts, &datatype_tmp,
                            &op_tmp, &comm_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&recvbuf, &recvbuf_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Reduce_scatter\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_group_translate_ranks_(int *, int *, int *, int *, int *, int *);

void mpi_group_translate_ranks__(int *, int *, int *, int *, int *, int *);

void pmpi_group_translate_ranks_(int *, int *, int *, int *, int *, int *);

void pmpi_group_translate_ranks__(int *, int *, int *, int *, int *, int *);

void pmpi_group_translate_ranks_(int *, int *, int *, int *, int *, int *);

#define A_f_MPI_Group_translate_ranks _PMPI_Group_translate_ranks
#pragma weak mpi_group_translate_ranks_ = _PMPI_Group_translate_ranks
#pragma weak mpi_group_translate_ranks__ = _PMPI_Group_translate_ranks
#pragma weak pmpi_group_translate_ranks__ = _PMPI_Group_translate_ranks
extern long long WI4MPI_Group_translate_ranks_timeout;
void (*_LOCAL_MPI_Group_translate_ranks)(int *, int *, int *, int *, int *,
                                         int *);

void A_f_MPI_Group_translate_ranks(int *group1, int *n, int *ranks1,
                                   int *group2, int *ranks2, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Group_translate_ranks\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Group_translate_ranks_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int group1_tmp;
  int group2_tmp;
  group_a2r(group1, &group1_tmp);
  group_a2r(group2, &group2_tmp);
  _LOCAL_MPI_Group_translate_ranks(&group1_tmp, n, ranks1, &group2_tmp, ranks2,
                                   &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Group_translate_ranks\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_group_incl_(int *, int *, int *, int *, int *);

void mpi_group_incl__(int *, int *, int *, int *, int *);

void pmpi_group_incl_(int *, int *, int *, int *, int *);

void pmpi_group_incl__(int *, int *, int *, int *, int *);

void pmpi_group_incl_(int *, int *, int *, int *, int *);

#define A_f_MPI_Group_incl _PMPI_Group_incl
#pragma weak mpi_group_incl_ = _PMPI_Group_incl
#pragma weak mpi_group_incl__ = _PMPI_Group_incl
#pragma weak pmpi_group_incl__ = _PMPI_Group_incl
extern long long WI4MPI_Group_incl_timeout;
void (*_LOCAL_MPI_Group_incl)(int *, int *, int *, int *, int *);

void A_f_MPI_Group_incl(int *group, int *n, int *ranks, int *newgroup,
                        int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Group_incl\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Group_incl_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int group_tmp;
  int newgroup_tmp;
  group_a2r(group, &group_tmp);
  _LOCAL_MPI_Group_incl(&group_tmp, n, ranks, &newgroup_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    group_r2a(newgroup, &newgroup_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Group_incl\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_group_excl_(int *, int *, int *, int *, int *);

void mpi_group_excl__(int *, int *, int *, int *, int *);

void pmpi_group_excl_(int *, int *, int *, int *, int *);

void pmpi_group_excl__(int *, int *, int *, int *, int *);

void pmpi_group_excl_(int *, int *, int *, int *, int *);

#define A_f_MPI_Group_excl _PMPI_Group_excl
#pragma weak mpi_group_excl_ = _PMPI_Group_excl
#pragma weak mpi_group_excl__ = _PMPI_Group_excl
#pragma weak pmpi_group_excl__ = _PMPI_Group_excl
extern long long WI4MPI_Group_excl_timeout;
void (*_LOCAL_MPI_Group_excl)(int *, int *, int *, int *, int *);

void A_f_MPI_Group_excl(int *group, int *n, int *ranks, int *newgroup,
                        int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Group_excl\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Group_excl_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int group_tmp;
  int newgroup_tmp;
  group_a2r(group, &group_tmp);
  _LOCAL_MPI_Group_excl(&group_tmp, n, ranks, &newgroup_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    group_r2a(newgroup, &newgroup_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Group_excl\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_group_range_incl_(int *, int *, int *, int *, int *);

void mpi_group_range_incl__(int *, int *, int *, int *, int *);

void pmpi_group_range_incl_(int *, int *, int *, int *, int *);

void pmpi_group_range_incl__(int *, int *, int *, int *, int *);

void pmpi_group_range_incl_(int *, int *, int *, int *, int *);

#define A_f_MPI_Group_range_incl _PMPI_Group_range_incl
#pragma weak mpi_group_range_incl_ = _PMPI_Group_range_incl
#pragma weak mpi_group_range_incl__ = _PMPI_Group_range_incl
#pragma weak pmpi_group_range_incl__ = _PMPI_Group_range_incl
extern long long WI4MPI_Group_range_incl_timeout;
void (*_LOCAL_MPI_Group_range_incl)(int *, int *, int *, int *, int *);

void A_f_MPI_Group_range_incl(int *group, int *n, int *ranges, int *newgroup,
                              int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Group_range_incl\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Group_range_incl_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int group_tmp;
  int newgroup_tmp;
  group_a2r(group, &group_tmp);
  _LOCAL_MPI_Group_range_incl(&group_tmp, n, ranges, &newgroup_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    group_r2a(newgroup, &newgroup_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Group_range_incl\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_group_range_excl_(int *, int *, int *, int *, int *);

void mpi_group_range_excl__(int *, int *, int *, int *, int *);

void pmpi_group_range_excl_(int *, int *, int *, int *, int *);

void pmpi_group_range_excl__(int *, int *, int *, int *, int *);

void pmpi_group_range_excl_(int *, int *, int *, int *, int *);

#define A_f_MPI_Group_range_excl _PMPI_Group_range_excl
#pragma weak mpi_group_range_excl_ = _PMPI_Group_range_excl
#pragma weak mpi_group_range_excl__ = _PMPI_Group_range_excl
#pragma weak pmpi_group_range_excl__ = _PMPI_Group_range_excl
extern long long WI4MPI_Group_range_excl_timeout;
void (*_LOCAL_MPI_Group_range_excl)(int *, int *, int *, int *, int *);

void A_f_MPI_Group_range_excl(int *group, int *n, int *ranges, int *newgroup,
                              int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Group_range_excl\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Group_range_excl_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int group_tmp;
  int newgroup_tmp;
  group_a2r(group, &group_tmp);
  _LOCAL_MPI_Group_range_excl(&group_tmp, n, ranges, &newgroup_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    group_r2a(newgroup, &newgroup_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Group_range_excl\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_cart_create_(int *, int *, int *, int *, int *, int *, int *);

void mpi_cart_create__(int *, int *, int *, int *, int *, int *, int *);

void pmpi_cart_create_(int *, int *, int *, int *, int *, int *, int *);

void pmpi_cart_create__(int *, int *, int *, int *, int *, int *, int *);

void pmpi_cart_create_(int *, int *, int *, int *, int *, int *, int *);

#define A_f_MPI_Cart_create _PMPI_Cart_create
#pragma weak mpi_cart_create_ = _PMPI_Cart_create
#pragma weak mpi_cart_create__ = _PMPI_Cart_create
#pragma weak pmpi_cart_create__ = _PMPI_Cart_create
extern long long WI4MPI_Cart_create_timeout;
void (*_LOCAL_MPI_Cart_create)(int *, int *, int *, int *, int *, int *, int *);

void A_f_MPI_Cart_create(int *comm_old, int *ndims, int *dims, int *periods,
                         int *reorder, int *comm_cart, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Cart_create\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Cart_create_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_old_tmp;
  int comm_cart_tmp;
  comm_a2r(comm_old, &comm_old_tmp);
  _LOCAL_MPI_Cart_create(&comm_old_tmp, ndims, dims, periods, reorder,
                         &comm_cart_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    comm_r2a(comm_cart, &comm_cart_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Cart_create\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_dims_create_(int *, int *, int *, int *);

void mpi_dims_create__(int *, int *, int *, int *);

void pmpi_dims_create_(int *, int *, int *, int *);

void pmpi_dims_create__(int *, int *, int *, int *);

void pmpi_dims_create_(int *, int *, int *, int *);

#define A_f_MPI_Dims_create _PMPI_Dims_create
#pragma weak mpi_dims_create_ = _PMPI_Dims_create
#pragma weak mpi_dims_create__ = _PMPI_Dims_create
#pragma weak pmpi_dims_create__ = _PMPI_Dims_create
extern long long WI4MPI_Dims_create_timeout;
void (*_LOCAL_MPI_Dims_create)(int *, int *, int *, int *);

void A_f_MPI_Dims_create(int *nnodes, int *ndims, int *dims, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Dims_create\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Dims_create_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_Dims_create(nnodes, ndims, dims, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Dims_create\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_graph_create_(int *, int *, int *, int *, int *, int *, int *);

void mpi_graph_create__(int *, int *, int *, int *, int *, int *, int *);

void pmpi_graph_create_(int *, int *, int *, int *, int *, int *, int *);

void pmpi_graph_create__(int *, int *, int *, int *, int *, int *, int *);

void pmpi_graph_create_(int *, int *, int *, int *, int *, int *, int *);

#define A_f_MPI_Graph_create _PMPI_Graph_create
#pragma weak mpi_graph_create_ = _PMPI_Graph_create
#pragma weak mpi_graph_create__ = _PMPI_Graph_create
#pragma weak pmpi_graph_create__ = _PMPI_Graph_create
extern long long WI4MPI_Graph_create_timeout;
void (*_LOCAL_MPI_Graph_create)(int *, int *, int *, int *, int *, int *,
                                int *);

void A_f_MPI_Graph_create(int *comm_old, int *nnodes, int *indx, int *edges,
                          int *reorder, int *comm_graph, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Graph_create\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Graph_create_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_old_tmp;
  int comm_graph_tmp;
  comm_a2r(comm_old, &comm_old_tmp);
  _LOCAL_MPI_Graph_create(&comm_old_tmp, nnodes, indx, edges, reorder,
                          &comm_graph_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    comm_r2a(comm_graph, &comm_graph_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Graph_create\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_graph_get_(int *, int *, int *, int *, int *, int *);

void mpi_graph_get__(int *, int *, int *, int *, int *, int *);

void pmpi_graph_get_(int *, int *, int *, int *, int *, int *);

void pmpi_graph_get__(int *, int *, int *, int *, int *, int *);

void pmpi_graph_get_(int *, int *, int *, int *, int *, int *);

#define A_f_MPI_Graph_get _PMPI_Graph_get
#pragma weak mpi_graph_get_ = _PMPI_Graph_get
#pragma weak mpi_graph_get__ = _PMPI_Graph_get
#pragma weak pmpi_graph_get__ = _PMPI_Graph_get
extern long long WI4MPI_Graph_get_timeout;
void (*_LOCAL_MPI_Graph_get)(int *, int *, int *, int *, int *, int *);

void A_f_MPI_Graph_get(int *comm, int *maxindex, int *maxedges, int *indx,
                       int *edges, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Graph_get\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Graph_get_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Graph_get(&comm_tmp, maxindex, maxedges, indx, edges, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Graph_get\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_cart_get_(int *, int *, int *, int *, int *, int *);

void mpi_cart_get__(int *, int *, int *, int *, int *, int *);

void pmpi_cart_get_(int *, int *, int *, int *, int *, int *);

void pmpi_cart_get__(int *, int *, int *, int *, int *, int *);

void pmpi_cart_get_(int *, int *, int *, int *, int *, int *);

#define A_f_MPI_Cart_get _PMPI_Cart_get
#pragma weak mpi_cart_get_ = _PMPI_Cart_get
#pragma weak mpi_cart_get__ = _PMPI_Cart_get
#pragma weak pmpi_cart_get__ = _PMPI_Cart_get
extern long long WI4MPI_Cart_get_timeout;
void (*_LOCAL_MPI_Cart_get)(int *, int *, int *, int *, int *, int *);

void A_f_MPI_Cart_get(int *comm, int *maxdims, int *dims, int *periods,
                      int *coords, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Cart_get\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Cart_get_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Cart_get(&comm_tmp, maxdims, dims, periods, coords, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Cart_get\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_cart_rank_(int *, int *, int *, int *);

void mpi_cart_rank__(int *, int *, int *, int *);

void pmpi_cart_rank_(int *, int *, int *, int *);

void pmpi_cart_rank__(int *, int *, int *, int *);

void pmpi_cart_rank_(int *, int *, int *, int *);

#define A_f_MPI_Cart_rank _PMPI_Cart_rank
#pragma weak mpi_cart_rank_ = _PMPI_Cart_rank
#pragma weak mpi_cart_rank__ = _PMPI_Cart_rank
#pragma weak pmpi_cart_rank__ = _PMPI_Cart_rank
extern long long WI4MPI_Cart_rank_timeout;
void (*_LOCAL_MPI_Cart_rank)(int *, int *, int *, int *);

void A_f_MPI_Cart_rank(int *comm, int *coords, int *rank, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Cart_rank\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Cart_rank_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Cart_rank(&comm_tmp, coords, rank, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Cart_rank\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_cart_coords_(int *, int *, int *, int *, int *);

void mpi_cart_coords__(int *, int *, int *, int *, int *);

void pmpi_cart_coords_(int *, int *, int *, int *, int *);

void pmpi_cart_coords__(int *, int *, int *, int *, int *);

void pmpi_cart_coords_(int *, int *, int *, int *, int *);

#define A_f_MPI_Cart_coords _PMPI_Cart_coords
#pragma weak mpi_cart_coords_ = _PMPI_Cart_coords
#pragma weak mpi_cart_coords__ = _PMPI_Cart_coords
#pragma weak pmpi_cart_coords__ = _PMPI_Cart_coords
extern long long WI4MPI_Cart_coords_timeout;
void (*_LOCAL_MPI_Cart_coords)(int *, int *, int *, int *, int *);

void A_f_MPI_Cart_coords(int *comm, int *rank, int *maxdims, int *coords,
                         int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Cart_coords\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Cart_coords_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Cart_coords(&comm_tmp, rank, maxdims, coords, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Cart_coords\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_graph_neighbors_(int *, int *, int *, int *, int *);

void mpi_graph_neighbors__(int *, int *, int *, int *, int *);

void pmpi_graph_neighbors_(int *, int *, int *, int *, int *);

void pmpi_graph_neighbors__(int *, int *, int *, int *, int *);

void pmpi_graph_neighbors_(int *, int *, int *, int *, int *);

#define A_f_MPI_Graph_neighbors _PMPI_Graph_neighbors
#pragma weak mpi_graph_neighbors_ = _PMPI_Graph_neighbors
#pragma weak mpi_graph_neighbors__ = _PMPI_Graph_neighbors
#pragma weak pmpi_graph_neighbors__ = _PMPI_Graph_neighbors
extern long long WI4MPI_Graph_neighbors_timeout;
void (*_LOCAL_MPI_Graph_neighbors)(int *, int *, int *, int *, int *);

void A_f_MPI_Graph_neighbors(int *comm, int *rank, int *maxneighbors,
                             int *neighbors, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Graph_neighbors\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Graph_neighbors_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Graph_neighbors(&comm_tmp, rank, maxneighbors, neighbors,
                             &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Graph_neighbors\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_cart_sub_(int *, int *, int *, int *);

void mpi_cart_sub__(int *, int *, int *, int *);

void pmpi_cart_sub_(int *, int *, int *, int *);

void pmpi_cart_sub__(int *, int *, int *, int *);

void pmpi_cart_sub_(int *, int *, int *, int *);

#define A_f_MPI_Cart_sub _PMPI_Cart_sub
#pragma weak mpi_cart_sub_ = _PMPI_Cart_sub
#pragma weak mpi_cart_sub__ = _PMPI_Cart_sub
#pragma weak pmpi_cart_sub__ = _PMPI_Cart_sub
extern long long WI4MPI_Cart_sub_timeout;
void (*_LOCAL_MPI_Cart_sub)(int *, int *, int *, int *);

void A_f_MPI_Cart_sub(int *comm, int *remain_dims, int *newcomm, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Cart_sub\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Cart_sub_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  int newcomm_tmp;
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Cart_sub(&comm_tmp, remain_dims, &newcomm_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    comm_r2a(newcomm, &newcomm_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Cart_sub\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_cart_map_(int *, int *, int *, int *, int *, int *);

void mpi_cart_map__(int *, int *, int *, int *, int *, int *);

void pmpi_cart_map_(int *, int *, int *, int *, int *, int *);

void pmpi_cart_map__(int *, int *, int *, int *, int *, int *);

void pmpi_cart_map_(int *, int *, int *, int *, int *, int *);

#define A_f_MPI_Cart_map _PMPI_Cart_map
#pragma weak mpi_cart_map_ = _PMPI_Cart_map
#pragma weak mpi_cart_map__ = _PMPI_Cart_map
#pragma weak pmpi_cart_map__ = _PMPI_Cart_map
extern long long WI4MPI_Cart_map_timeout;
void (*_LOCAL_MPI_Cart_map)(int *, int *, int *, int *, int *, int *);

void A_f_MPI_Cart_map(int *comm, int *ndims, int *dims, int *periods,
                      int *newrank, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Cart_map\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Cart_map_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Cart_map(&comm_tmp, ndims, dims, periods, newrank, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Cart_map\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_graph_map_(int *, int *, int *, int *, int *, int *);

void mpi_graph_map__(int *, int *, int *, int *, int *, int *);

void pmpi_graph_map_(int *, int *, int *, int *, int *, int *);

void pmpi_graph_map__(int *, int *, int *, int *, int *, int *);

void pmpi_graph_map_(int *, int *, int *, int *, int *, int *);

#define A_f_MPI_Graph_map _PMPI_Graph_map
#pragma weak mpi_graph_map_ = _PMPI_Graph_map
#pragma weak mpi_graph_map__ = _PMPI_Graph_map
#pragma weak pmpi_graph_map__ = _PMPI_Graph_map
extern long long WI4MPI_Graph_map_timeout;
void (*_LOCAL_MPI_Graph_map)(int *, int *, int *, int *, int *, int *);

void A_f_MPI_Graph_map(int *comm, int *nnodes, int *indx, int *edges,
                       int *newrank, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Graph_map\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Graph_map_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Graph_map(&comm_tmp, nnodes, indx, edges, newrank, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Graph_map\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_type_get_contents_(int *, int *, int *, int *, int *, size_t *, int *,
                            int *);

void mpi_type_get_contents__(int *, int *, int *, int *, int *, size_t *, int *,
                             int *);

void pmpi_type_get_contents_(int *, int *, int *, int *, int *, size_t *, int *,
                             int *);

void pmpi_type_get_contents__(int *, int *, int *, int *, int *, size_t *,
                              int *, int *);

void pmpi_type_get_contents_(int *, int *, int *, int *, int *, size_t *, int *,
                             int *);

#define A_f_MPI_Type_get_contents _PMPI_Type_get_contents
#pragma weak mpi_type_get_contents_ = _PMPI_Type_get_contents
#pragma weak mpi_type_get_contents__ = _PMPI_Type_get_contents
#pragma weak pmpi_type_get_contents__ = _PMPI_Type_get_contents
extern long long WI4MPI_Type_get_contents_timeout;
void (*_LOCAL_MPI_Type_get_contents)(int *, int *, int *, int *, int *,
                                     size_t *, int *, int *);

void A_f_MPI_Type_get_contents(int *datatype, int *max_integers,
                               int *max_addresses, int *max_datatypes,
                               int *array_of_integers,
                               size_t *array_of_addresses,
                               int *array_of_datatypes, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Type_get_contents\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Type_get_contents_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int datatype_tmp;
  int *array_of_datatypes_tmp =
      (int *)wi4mpi_alloc((*max_datatypes) * 1 * sizeof(int));
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_Type_get_contents(
      &datatype_tmp, max_integers, max_addresses, max_datatypes,
      array_of_integers, array_of_addresses, array_of_datatypes_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    for (int i = 0; i < *max_datatypes; i++)
      datatype_r2a(&array_of_datatypes[i * 1], &array_of_datatypes_tmp[i * 1]);
  wi4mpi_free(array_of_datatypes_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Type_get_contents\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_type_create_darray_(int *, int *, int *, int *, int *, int *, int *,
                             int *, int *, int *, int *);

void mpi_type_create_darray__(int *, int *, int *, int *, int *, int *, int *,
                              int *, int *, int *, int *);

void pmpi_type_create_darray_(int *, int *, int *, int *, int *, int *, int *,
                              int *, int *, int *, int *);

void pmpi_type_create_darray__(int *, int *, int *, int *, int *, int *, int *,
                               int *, int *, int *, int *);

void pmpi_type_create_darray_(int *, int *, int *, int *, int *, int *, int *,
                              int *, int *, int *, int *);

#define A_f_MPI_Type_create_darray _PMPI_Type_create_darray
#pragma weak mpi_type_create_darray_ = _PMPI_Type_create_darray
#pragma weak mpi_type_create_darray__ = _PMPI_Type_create_darray
#pragma weak pmpi_type_create_darray__ = _PMPI_Type_create_darray
extern long long WI4MPI_Type_create_darray_timeout;
void (*_LOCAL_MPI_Type_create_darray)(int *, int *, int *, int *, int *, int *,
                                      int *, int *, int *, int *, int *);

void A_f_MPI_Type_create_darray(int *size, int *rank, int *ndims,
                                int *array_of_gsizes, int *array_of_distribs,
                                int *array_of_dargs, int *array_of_psizes,
                                int *order, int *oldtype, int *newtype,
                                int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Type_create_darray\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Type_create_darray_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int order_tmp;
  int oldtype_tmp;
  int newtype_tmp;
  order2_a2r(order, &order_tmp);
  datatype_a2r(oldtype, &oldtype_tmp);
  _LOCAL_MPI_Type_create_darray(
      size, rank, ndims, array_of_gsizes, array_of_distribs, array_of_dargs,
      array_of_psizes, &order_tmp, &oldtype_tmp, &newtype_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    datatype_r2a(newtype, &newtype_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Type_create_darray\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_type_create_hindexed_(int *, int *, size_t *, int *, int *, int *);

void mpi_type_create_hindexed__(int *, int *, size_t *, int *, int *, int *);

void pmpi_type_create_hindexed_(int *, int *, size_t *, int *, int *, int *);

void pmpi_type_create_hindexed__(int *, int *, size_t *, int *, int *, int *);

void pmpi_type_create_hindexed_(int *, int *, size_t *, int *, int *, int *);

#define A_f_MPI_Type_create_hindexed _PMPI_Type_create_hindexed
#pragma weak mpi_type_create_hindexed_ = _PMPI_Type_create_hindexed
#pragma weak mpi_type_create_hindexed__ = _PMPI_Type_create_hindexed
#pragma weak pmpi_type_create_hindexed__ = _PMPI_Type_create_hindexed
extern long long WI4MPI_Type_create_hindexed_timeout;
void (*_LOCAL_MPI_Type_create_hindexed)(int *, int *, size_t *, int *, int *,
                                        int *);

void A_f_MPI_Type_create_hindexed(int *count, int *array_of_blocklengths,
                                  size_t *array_of_displacements, int *oldtype,
                                  int *newtype, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Type_create_hindexed\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Type_create_hindexed_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int oldtype_tmp;
  int newtype_tmp;
  datatype_a2r(oldtype, &oldtype_tmp);
  _LOCAL_MPI_Type_create_hindexed(count, array_of_blocklengths,
                                  array_of_displacements, &oldtype_tmp,
                                  &newtype_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    datatype_r2a(newtype, &newtype_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Type_create_hindexed\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_type_create_indexed_block_(int *, int *, int *, int *, int *, int *);

void mpi_type_create_indexed_block__(int *, int *, int *, int *, int *, int *);

void pmpi_type_create_indexed_block_(int *, int *, int *, int *, int *, int *);

void pmpi_type_create_indexed_block__(int *, int *, int *, int *, int *, int *);

void pmpi_type_create_indexed_block_(int *, int *, int *, int *, int *, int *);

#define A_f_MPI_Type_create_indexed_block _PMPI_Type_create_indexed_block
#pragma weak mpi_type_create_indexed_block_ = _PMPI_Type_create_indexed_block
#pragma weak mpi_type_create_indexed_block__ = _PMPI_Type_create_indexed_block
#pragma weak pmpi_type_create_indexed_block__ = _PMPI_Type_create_indexed_block
extern long long WI4MPI_Type_create_indexed_block_timeout;
void (*_LOCAL_MPI_Type_create_indexed_block)(int *, int *, int *, int *, int *,
                                             int *);

void A_f_MPI_Type_create_indexed_block(int *count, int *blocklength,
                                       int *array_of_displacements,
                                       int *oldtype, int *newtype, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Type_create_indexed_block\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Type_create_indexed_block_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int oldtype_tmp;
  int newtype_tmp;
  datatype_a2r(oldtype, &oldtype_tmp);
  _LOCAL_MPI_Type_create_indexed_block(count, blocklength,
                                       array_of_displacements, &oldtype_tmp,
                                       &newtype_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    datatype_r2a(newtype, &newtype_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Type_create_indexed_block\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_type_create_hindexed_block_(int *, int *, size_t *, int *, int *,
                                     int *);

void mpi_type_create_hindexed_block__(int *, int *, size_t *, int *, int *,
                                      int *);

void pmpi_type_create_hindexed_block_(int *, int *, size_t *, int *, int *,
                                      int *);

void pmpi_type_create_hindexed_block__(int *, int *, size_t *, int *, int *,
                                       int *);

void pmpi_type_create_hindexed_block_(int *, int *, size_t *, int *, int *,
                                      int *);

#define A_f_MPI_Type_create_hindexed_block _PMPI_Type_create_hindexed_block
#pragma weak mpi_type_create_hindexed_block_ = _PMPI_Type_create_hindexed_block
#pragma weak mpi_type_create_hindexed_block__ = _PMPI_Type_create_hindexed_block
#pragma weak pmpi_type_create_hindexed_block__ =                               \
    _PMPI_Type_create_hindexed_block
extern long long WI4MPI_Type_create_hindexed_block_timeout;
void (*_LOCAL_MPI_Type_create_hindexed_block)(int *, int *, size_t *, int *,
                                              int *, int *);

void A_f_MPI_Type_create_hindexed_block(int *count, int *blocklength,
                                        size_t *array_of_displacements,
                                        int *oldtype, int *newtype, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Type_create_hindexed_block\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Type_create_hindexed_block_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int oldtype_tmp;
  int newtype_tmp;
  datatype_a2r(oldtype, &oldtype_tmp);
  _LOCAL_MPI_Type_create_hindexed_block(count, blocklength,
                                        array_of_displacements, &oldtype_tmp,
                                        &newtype_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    datatype_r2a(newtype, &newtype_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Type_create_hindexed_block\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_type_create_struct_(int *, int *, size_t *, int *, int *, int *);

void mpi_type_create_struct__(int *, int *, size_t *, int *, int *, int *);

void pmpi_type_create_struct_(int *, int *, size_t *, int *, int *, int *);

void pmpi_type_create_struct__(int *, int *, size_t *, int *, int *, int *);

void pmpi_type_create_struct_(int *, int *, size_t *, int *, int *, int *);

#define A_f_MPI_Type_create_struct _PMPI_Type_create_struct
#pragma weak mpi_type_create_struct_ = _PMPI_Type_create_struct
#pragma weak mpi_type_create_struct__ = _PMPI_Type_create_struct
#pragma weak pmpi_type_create_struct__ = _PMPI_Type_create_struct
extern long long WI4MPI_Type_create_struct_timeout;
void (*_LOCAL_MPI_Type_create_struct)(int *, int *, size_t *, int *, int *,
                                      int *);

void A_f_MPI_Type_create_struct(int *count, int *array_of_blocklengths,
                                size_t *array_of_displacements,
                                int *array_of_types, int *newtype, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Type_create_struct\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Type_create_struct_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int *array_of_types_tmp = (int *)wi4mpi_alloc((*count) * 1 * sizeof(int));
  int newtype_tmp;
  for (int i = 0; i < *count; i++)
    datatype_a2r(&array_of_types[i * 1], &array_of_types_tmp[i * 1]);
  _LOCAL_MPI_Type_create_struct(count, array_of_blocklengths,
                                array_of_displacements, array_of_types_tmp,
                                &newtype_tmp, &ret_tmp);
  wi4mpi_free(array_of_types_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    datatype_r2a(newtype, &newtype_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Type_create_struct\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_type_create_subarray_(int *, int *, int *, int *, int *, int *, int *,
                               int *);

void mpi_type_create_subarray__(int *, int *, int *, int *, int *, int *, int *,
                                int *);

void pmpi_type_create_subarray_(int *, int *, int *, int *, int *, int *, int *,
                                int *);

void pmpi_type_create_subarray__(int *, int *, int *, int *, int *, int *,
                                 int *, int *);

void pmpi_type_create_subarray_(int *, int *, int *, int *, int *, int *, int *,
                                int *);

#define A_f_MPI_Type_create_subarray _PMPI_Type_create_subarray
#pragma weak mpi_type_create_subarray_ = _PMPI_Type_create_subarray
#pragma weak mpi_type_create_subarray__ = _PMPI_Type_create_subarray
#pragma weak pmpi_type_create_subarray__ = _PMPI_Type_create_subarray
extern long long WI4MPI_Type_create_subarray_timeout;
void (*_LOCAL_MPI_Type_create_subarray)(int *, int *, int *, int *, int *,
                                        int *, int *, int *);

void A_f_MPI_Type_create_subarray(int *ndims, int *array_of_sizes,
                                  int *array_of_subsizes, int *array_of_starts,
                                  int *order, int *oldtype, int *newtype,
                                  int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Type_create_subarray\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Type_create_subarray_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int order_tmp;
  int oldtype_tmp;
  int newtype_tmp;
  order_a2r(order, &order_tmp);
  datatype_a2r(oldtype, &oldtype_tmp);
  _LOCAL_MPI_Type_create_subarray(ndims, array_of_sizes, array_of_subsizes,
                                  array_of_starts, &order_tmp, &oldtype_tmp,
                                  &newtype_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    datatype_r2a(newtype, &newtype_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Type_create_subarray\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_dist_graph_create_adjacent_(int *, int *, int *, int *, int *, int *,
                                     int *, int *, int *, int *, int *);

void mpi_dist_graph_create_adjacent__(int *, int *, int *, int *, int *, int *,
                                      int *, int *, int *, int *, int *);

void pmpi_dist_graph_create_adjacent_(int *, int *, int *, int *, int *, int *,
                                      int *, int *, int *, int *, int *);

void pmpi_dist_graph_create_adjacent__(int *, int *, int *, int *, int *, int *,
                                       int *, int *, int *, int *, int *);

void pmpi_dist_graph_create_adjacent_(int *, int *, int *, int *, int *, int *,
                                      int *, int *, int *, int *, int *);

#define A_f_MPI_Dist_graph_create_adjacent _PMPI_Dist_graph_create_adjacent
#pragma weak mpi_dist_graph_create_adjacent_ = _PMPI_Dist_graph_create_adjacent
#pragma weak mpi_dist_graph_create_adjacent__ = _PMPI_Dist_graph_create_adjacent
#pragma weak pmpi_dist_graph_create_adjacent__ =                               \
    _PMPI_Dist_graph_create_adjacent
extern long long WI4MPI_Dist_graph_create_adjacent_timeout;
void (*_LOCAL_MPI_Dist_graph_create_adjacent)(int *, int *, int *, int *, int *,
                                              int *, int *, int *, int *, int *,
                                              int *);

void A_f_MPI_Dist_graph_create_adjacent(int *comm_old, int *indegree,
                                        int *sources, int *sourceweights,
                                        int *outdegree, int *destinations,
                                        int *destweights, int *info,
                                        int *reorder, int *comm_dist_graph,
                                        int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Dist_graph_create_adjacent\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Dist_graph_create_adjacent_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_old_tmp;
  int *sourceweights_tmp = sourceweights;
  int *destweights_tmp = destweights;
  int info_tmp;
  int comm_dist_graph_tmp;
  comm_a2r(comm_old, &comm_old_tmp);
  weight_a2r(&sourceweights, &sourceweights_tmp);
  weight_a2r(&destweights, &destweights_tmp);
  info_a2r(info, &info_tmp);
  _LOCAL_MPI_Dist_graph_create_adjacent(
      &comm_old_tmp, indegree, sources, sourceweights_tmp, outdegree,
      destinations, destweights_tmp, &info_tmp, reorder, &comm_dist_graph_tmp,
      &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    comm_r2a(comm_dist_graph, &comm_dist_graph_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Dist_graph_create_adjacent\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_dist_graph_create_(int *, int *, int *, int *, int *, int *, int *,
                            int *, int *, int *);

void mpi_dist_graph_create__(int *, int *, int *, int *, int *, int *, int *,
                             int *, int *, int *);

void pmpi_dist_graph_create_(int *, int *, int *, int *, int *, int *, int *,
                             int *, int *, int *);

void pmpi_dist_graph_create__(int *, int *, int *, int *, int *, int *, int *,
                              int *, int *, int *);

void pmpi_dist_graph_create_(int *, int *, int *, int *, int *, int *, int *,
                             int *, int *, int *);

#define A_f_MPI_Dist_graph_create _PMPI_Dist_graph_create
#pragma weak mpi_dist_graph_create_ = _PMPI_Dist_graph_create
#pragma weak mpi_dist_graph_create__ = _PMPI_Dist_graph_create
#pragma weak pmpi_dist_graph_create__ = _PMPI_Dist_graph_create
extern long long WI4MPI_Dist_graph_create_timeout;
void (*_LOCAL_MPI_Dist_graph_create)(int *, int *, int *, int *, int *, int *,
                                     int *, int *, int *, int *);

void A_f_MPI_Dist_graph_create(int *comm_old, int *n, int *sources,
                               int *degrees, int *destinations, int *weights,
                               int *info, int *reorder, int *comm_dist_graph,
                               int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Dist_graph_create\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Dist_graph_create_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_old_tmp;
  int *weights_tmp = weights;
  int info_tmp;
  int comm_dist_graph_tmp;
  comm_a2r(comm_old, &comm_old_tmp);
  weight_a2r(&weights, &weights_tmp);
  info_a2r(info, &info_tmp);
  _LOCAL_MPI_Dist_graph_create(&comm_old_tmp, n, sources, degrees, destinations,
                               weights_tmp, &info_tmp, reorder,
                               &comm_dist_graph_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    comm_r2a(comm_dist_graph, &comm_dist_graph_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Dist_graph_create\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_dist_graph_neighbors_(int *, int *, int *, int *, int *, int *, int *,
                               int *);

void mpi_dist_graph_neighbors__(int *, int *, int *, int *, int *, int *, int *,
                                int *);

void pmpi_dist_graph_neighbors_(int *, int *, int *, int *, int *, int *, int *,
                                int *);

void pmpi_dist_graph_neighbors__(int *, int *, int *, int *, int *, int *,
                                 int *, int *);

void pmpi_dist_graph_neighbors_(int *, int *, int *, int *, int *, int *, int *,
                                int *);

#define A_f_MPI_Dist_graph_neighbors _PMPI_Dist_graph_neighbors
#pragma weak mpi_dist_graph_neighbors_ = _PMPI_Dist_graph_neighbors
#pragma weak mpi_dist_graph_neighbors__ = _PMPI_Dist_graph_neighbors
#pragma weak pmpi_dist_graph_neighbors__ = _PMPI_Dist_graph_neighbors
extern long long WI4MPI_Dist_graph_neighbors_timeout;
void (*_LOCAL_MPI_Dist_graph_neighbors)(int *, int *, int *, int *, int *,
                                        int *, int *, int *);

void A_f_MPI_Dist_graph_neighbors(int *comm, int *maxindegree, int *sources,
                                  int *sourceweights, int *maxoutdegree,
                                  int *destinations, int *destweights,
                                  int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Dist_graph_neighbors\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Dist_graph_neighbors_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  int *sourceweights_tmp = sourceweights;
  int *destweights_tmp = destweights;
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Dist_graph_neighbors(&comm_tmp, maxindegree, sources,
                                  sourceweights_tmp, maxoutdegree, destinations,
                                  destweights_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    weight_a2r(&sourceweights, &sourceweights_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    weight_a2r(&destweights, &destweights_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Dist_graph_neighbors\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_igatherv_(void *, int *, int *, void *, int *, int *, int *, int *,
                   int *, int *, int *);

void mpi_igatherv__(void *, int *, int *, void *, int *, int *, int *, int *,
                    int *, int *, int *);

void pmpi_igatherv_(void *, int *, int *, void *, int *, int *, int *, int *,
                    int *, int *, int *);

void pmpi_igatherv__(void *, int *, int *, void *, int *, int *, int *, int *,
                     int *, int *, int *);

void pmpi_igatherv_(void *, int *, int *, void *, int *, int *, int *, int *,
                    int *, int *, int *);

#define A_f_MPI_Igatherv _PMPI_Igatherv
#pragma weak mpi_igatherv_ = _PMPI_Igatherv
#pragma weak mpi_igatherv__ = _PMPI_Igatherv
#pragma weak pmpi_igatherv__ = _PMPI_Igatherv
extern long long WI4MPI_Igatherv_timeout;
void (*_LOCAL_MPI_Igatherv)(void *, int *, int *, void *, int *, int *, int *,
                            int *, int *, int *, int *);

void A_f_MPI_Igatherv(void *sendbuf, int *sendcount, int *sendtype,
                      void *recvbuf, int *recvcounts, int *displs,
                      int *recvtype, int *root, int *comm, int *request,
                      int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Igatherv\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Igatherv_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *sendbuf_tmp = sendbuf;
  int sendtype_tmp;
  void *recvbuf_tmp = recvbuf;
  int recvtype_tmp;
  int comm_tmp;
  int request_tmp;
  buffer_a2r(&sendbuf, &sendbuf_tmp);
  datatype_a2r(sendtype, &sendtype_tmp);
  buffer_a2r(&recvbuf, &recvbuf_tmp);
  datatype_a2r(recvtype, &recvtype_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Igatherv(sendbuf_tmp, sendcount, &sendtype_tmp, recvbuf_tmp,
                      recvcounts, displs, &recvtype_tmp, root, &comm_tmp,
                      &request_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&recvbuf, &recvbuf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Igatherv\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_iscatterv_(void *, int *, int *, int *, void *, int *, int *, int *,
                    int *, int *, int *);

void mpi_iscatterv__(void *, int *, int *, int *, void *, int *, int *, int *,
                     int *, int *, int *);

void pmpi_iscatterv_(void *, int *, int *, int *, void *, int *, int *, int *,
                     int *, int *, int *);

void pmpi_iscatterv__(void *, int *, int *, int *, void *, int *, int *, int *,
                      int *, int *, int *);

void pmpi_iscatterv_(void *, int *, int *, int *, void *, int *, int *, int *,
                     int *, int *, int *);

#define A_f_MPI_Iscatterv _PMPI_Iscatterv
#pragma weak mpi_iscatterv_ = _PMPI_Iscatterv
#pragma weak mpi_iscatterv__ = _PMPI_Iscatterv
#pragma weak pmpi_iscatterv__ = _PMPI_Iscatterv
extern long long WI4MPI_Iscatterv_timeout;
void (*_LOCAL_MPI_Iscatterv)(void *, int *, int *, int *, void *, int *, int *,
                             int *, int *, int *, int *);

void A_f_MPI_Iscatterv(void *sendbuf, int *sendcounts, int *displs,
                       int *sendtype, void *recvbuf, int *recvcount,
                       int *recvtype, int *root, int *comm, int *request,
                       int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Iscatterv\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Iscatterv_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *sendbuf_tmp = sendbuf;
  int sendtype_tmp;
  void *recvbuf_tmp = recvbuf;
  int recvtype_tmp;
  int comm_tmp;
  int request_tmp;
  buffer_a2r(&sendbuf, &sendbuf_tmp);
  datatype_a2r(sendtype, &sendtype_tmp);
  buffer_a2r(&recvbuf, &recvbuf_tmp);
  datatype_a2r(recvtype, &recvtype_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Iscatterv(sendbuf_tmp, sendcounts, displs, &sendtype_tmp,
                       recvbuf_tmp, recvcount, &recvtype_tmp, root, &comm_tmp,
                       &request_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&recvbuf, &recvbuf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Iscatterv\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_iallgatherv_(void *, int *, int *, void *, int *, int *, int *, int *,
                      int *, int *);

void mpi_iallgatherv__(void *, int *, int *, void *, int *, int *, int *, int *,
                       int *, int *);

void pmpi_iallgatherv_(void *, int *, int *, void *, int *, int *, int *, int *,
                       int *, int *);

void pmpi_iallgatherv__(void *, int *, int *, void *, int *, int *, int *,
                        int *, int *, int *);

void pmpi_iallgatherv_(void *, int *, int *, void *, int *, int *, int *, int *,
                       int *, int *);

#define A_f_MPI_Iallgatherv _PMPI_Iallgatherv
#pragma weak mpi_iallgatherv_ = _PMPI_Iallgatherv
#pragma weak mpi_iallgatherv__ = _PMPI_Iallgatherv
#pragma weak pmpi_iallgatherv__ = _PMPI_Iallgatherv
extern long long WI4MPI_Iallgatherv_timeout;
void (*_LOCAL_MPI_Iallgatherv)(void *, int *, int *, void *, int *, int *,
                               int *, int *, int *, int *);

void A_f_MPI_Iallgatherv(void *sendbuf, int *sendcount, int *sendtype,
                         void *recvbuf, int *recvcounts, int *displs,
                         int *recvtype, int *comm, int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Iallgatherv\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Iallgatherv_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *sendbuf_tmp = sendbuf;
  int sendtype_tmp;
  void *recvbuf_tmp = recvbuf;
  int recvtype_tmp;
  int comm_tmp;
  int request_tmp;
  buffer_a2r(&sendbuf, &sendbuf_tmp);
  datatype_a2r(sendtype, &sendtype_tmp);
  buffer_a2r(&recvbuf, &recvbuf_tmp);
  datatype_a2r(recvtype, &recvtype_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Iallgatherv(sendbuf_tmp, sendcount, &sendtype_tmp, recvbuf_tmp,
                         recvcounts, displs, &recvtype_tmp, &comm_tmp,
                         &request_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&recvbuf, &recvbuf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Iallgatherv\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_ialltoallv_(void *, int *, int *, int *, void *, int *, int *, int *,
                     int *, int *, int *);

void mpi_ialltoallv__(void *, int *, int *, int *, void *, int *, int *, int *,
                      int *, int *, int *);

void pmpi_ialltoallv_(void *, int *, int *, int *, void *, int *, int *, int *,
                      int *, int *, int *);

void pmpi_ialltoallv__(void *, int *, int *, int *, void *, int *, int *, int *,
                       int *, int *, int *);

void pmpi_ialltoallv_(void *, int *, int *, int *, void *, int *, int *, int *,
                      int *, int *, int *);

#define A_f_MPI_Ialltoallv _PMPI_Ialltoallv
#pragma weak mpi_ialltoallv_ = _PMPI_Ialltoallv
#pragma weak mpi_ialltoallv__ = _PMPI_Ialltoallv
#pragma weak pmpi_ialltoallv__ = _PMPI_Ialltoallv
extern long long WI4MPI_Ialltoallv_timeout;
void (*_LOCAL_MPI_Ialltoallv)(void *, int *, int *, int *, void *, int *, int *,
                              int *, int *, int *, int *);

void A_f_MPI_Ialltoallv(void *sendbuf, int *sendcounts, int *sdispls,
                        int *sendtype, void *recvbuf, int *recvcounts,
                        int *rdispls, int *recvtype, int *comm, int *request,
                        int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Ialltoallv\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Ialltoallv_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *sendbuf_tmp = sendbuf;
  int sendtype_tmp;
  void *recvbuf_tmp = recvbuf;
  int recvtype_tmp;
  int comm_tmp;
  int request_tmp;
  buffer_a2r(&sendbuf, &sendbuf_tmp);
  datatype_a2r(sendtype, &sendtype_tmp);
  buffer_a2r(&recvbuf, &recvbuf_tmp);
  datatype_a2r(recvtype, &recvtype_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Ialltoallv(sendbuf_tmp, sendcounts, sdispls, &sendtype_tmp,
                        recvbuf_tmp, recvcounts, rdispls, &recvtype_tmp,
                        &comm_tmp, &request_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&sendbuf, &sendbuf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&recvbuf, &recvbuf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Ialltoallv\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_ialltoallw_(void *, int *, int *, int *, void *, int *, int *, int *,
                     int *, int *, int *);

void mpi_ialltoallw__(void *, int *, int *, int *, void *, int *, int *, int *,
                      int *, int *, int *);

void pmpi_ialltoallw_(void *, int *, int *, int *, void *, int *, int *, int *,
                      int *, int *, int *);

void pmpi_ialltoallw__(void *, int *, int *, int *, void *, int *, int *, int *,
                       int *, int *, int *);

void pmpi_ialltoallw_(void *, int *, int *, int *, void *, int *, int *, int *,
                      int *, int *, int *);

#define A_f_MPI_Ialltoallw _PMPI_Ialltoallw
#pragma weak mpi_ialltoallw_ = _PMPI_Ialltoallw
#pragma weak mpi_ialltoallw__ = _PMPI_Ialltoallw
#pragma weak pmpi_ialltoallw__ = _PMPI_Ialltoallw
extern long long WI4MPI_Ialltoallw_timeout;
void (*_LOCAL_MPI_Ialltoallw)(void *, int *, int *, int *, void *, int *, int *,
                              int *, int *, int *, int *);

void A_f_MPI_Ialltoallw(void *sendbuf, int *sendcounts, int *sdispls,
                        int *sendtypes, void *recvbuf, int *recvcounts,
                        int *rdispls, int *recvtypes, int *comm, int *request,
                        int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Ialltoallw\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Ialltoallw_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;
  int comm_tmp1, ierr;
  comm_a2r(comm, &comm_tmp1);
  int *Comm_size;
  _LOCAL_MPI_Comm_size(&comm_tmp1, Comm_size, &ierr);
  void *sendbuf_tmp = sendbuf;
  int *sendtypes_tmp = (int *)wi4mpi_alloc((*Comm_size) * 1 * sizeof(int));
  void *recvbuf_tmp = recvbuf;
  int *recvtypes_tmp = (int *)wi4mpi_alloc((*Comm_size) * 1 * sizeof(int));
  int comm_tmp;
  int request_tmp;
  buffer_a2r(&sendbuf, &sendbuf_tmp);
  for (int i = 0; i < *Comm_size; i++)
    datatype_a2r(&sendtypes[i * 1], &sendtypes_tmp[i * 1]);
  buffer_a2r(&recvbuf, &recvbuf_tmp);
  for (int i = 0; i < *Comm_size; i++)
    datatype_a2r(&recvtypes[i * 1], &recvtypes_tmp[i * 1]);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Ialltoallw(sendbuf_tmp, sendcounts, sdispls, sendtypes_tmp,
                        recvbuf_tmp, recvcounts, rdispls, recvtypes_tmp,
                        &comm_tmp, &request_tmp, &ret_tmp);
  wi4mpi_free(sendtypes_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&recvbuf, &recvbuf_tmp);
  wi4mpi_free(recvtypes_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Ialltoallw\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_ireduce_scatter_(void *, void *, int *, int *, int *, int *, int *,
                          int *);

void mpi_ireduce_scatter__(void *, void *, int *, int *, int *, int *, int *,
                           int *);

void pmpi_ireduce_scatter_(void *, void *, int *, int *, int *, int *, int *,
                           int *);

void pmpi_ireduce_scatter__(void *, void *, int *, int *, int *, int *, int *,
                            int *);

void pmpi_ireduce_scatter_(void *, void *, int *, int *, int *, int *, int *,
                           int *);

#define A_f_MPI_Ireduce_scatter _PMPI_Ireduce_scatter
#pragma weak mpi_ireduce_scatter_ = _PMPI_Ireduce_scatter
#pragma weak mpi_ireduce_scatter__ = _PMPI_Ireduce_scatter
#pragma weak pmpi_ireduce_scatter__ = _PMPI_Ireduce_scatter
extern long long WI4MPI_Ireduce_scatter_timeout;
void (*_LOCAL_MPI_Ireduce_scatter)(void *, void *, int *, int *, int *, int *,
                                   int *, int *);

void A_f_MPI_Ireduce_scatter(void *sendbuf, void *recvbuf, int *recvcounts,
                             int *datatype, int *op, int *comm, int *request,
                             int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Ireduce_scatter\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Ireduce_scatter_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *sendbuf_tmp = sendbuf;
  void *recvbuf_tmp = recvbuf;
  int datatype_tmp;
  int op_tmp;
  int comm_tmp;
  int request_tmp;
  buffer_a2r(&sendbuf, &sendbuf_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  operator_a2r(op, &op_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Ireduce_scatter(sendbuf_tmp, recvbuf_tmp, recvcounts,
                             &datatype_tmp, &op_tmp, &comm_tmp, &request_tmp,
                             &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&recvbuf, &recvbuf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Ireduce_scatter\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_ineighbor_allgatherv_(void *, int *, int *, void *, int *, int *,
                               int *, int *, int *, int *);

void mpi_ineighbor_allgatherv__(void *, int *, int *, void *, int *, int *,
                                int *, int *, int *, int *);

void pmpi_ineighbor_allgatherv_(void *, int *, int *, void *, int *, int *,
                                int *, int *, int *, int *);

void pmpi_ineighbor_allgatherv__(void *, int *, int *, void *, int *, int *,
                                 int *, int *, int *, int *);

void pmpi_ineighbor_allgatherv_(void *, int *, int *, void *, int *, int *,
                                int *, int *, int *, int *);

#define A_f_MPI_Ineighbor_allgatherv _PMPI_Ineighbor_allgatherv
#pragma weak mpi_ineighbor_allgatherv_ = _PMPI_Ineighbor_allgatherv
#pragma weak mpi_ineighbor_allgatherv__ = _PMPI_Ineighbor_allgatherv
#pragma weak pmpi_ineighbor_allgatherv__ = _PMPI_Ineighbor_allgatherv
extern long long WI4MPI_Ineighbor_allgatherv_timeout;
void (*_LOCAL_MPI_Ineighbor_allgatherv)(void *, int *, int *, void *, int *,
                                        int *, int *, int *, int *, int *);

void A_f_MPI_Ineighbor_allgatherv(void *sendbuf, int *sendcount, int *sendtype,
                                  void *recvbuf, int *recvcounts, int *displs,
                                  int *recvtype, int *comm, int *request,
                                  int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Ineighbor_allgatherv\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Ineighbor_allgatherv_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *sendbuf_tmp = sendbuf;
  int sendtype_tmp;
  void *recvbuf_tmp = recvbuf;
  int recvtype_tmp;
  int comm_tmp;
  int request_tmp;
  buffer_a2r(&sendbuf, &sendbuf_tmp);
  datatype_a2r(sendtype, &sendtype_tmp);
  datatype_a2r(recvtype, &recvtype_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Ineighbor_allgatherv(
      sendbuf_tmp, sendcount, &sendtype_tmp, recvbuf_tmp, recvcounts, displs,
      &recvtype_tmp, &comm_tmp, &request_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&recvbuf, &recvbuf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Ineighbor_allgatherv\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_ineighbor_alltoallv_(void *, int *, int *, int *, void *, int *, int *,
                              int *, int *, int *, int *);

void mpi_ineighbor_alltoallv__(void *, int *, int *, int *, void *, int *,
                               int *, int *, int *, int *, int *);

void pmpi_ineighbor_alltoallv_(void *, int *, int *, int *, void *, int *,
                               int *, int *, int *, int *, int *);

void pmpi_ineighbor_alltoallv__(void *, int *, int *, int *, void *, int *,
                                int *, int *, int *, int *, int *);

void pmpi_ineighbor_alltoallv_(void *, int *, int *, int *, void *, int *,
                               int *, int *, int *, int *, int *);

#define A_f_MPI_Ineighbor_alltoallv _PMPI_Ineighbor_alltoallv
#pragma weak mpi_ineighbor_alltoallv_ = _PMPI_Ineighbor_alltoallv
#pragma weak mpi_ineighbor_alltoallv__ = _PMPI_Ineighbor_alltoallv
#pragma weak pmpi_ineighbor_alltoallv__ = _PMPI_Ineighbor_alltoallv
extern long long WI4MPI_Ineighbor_alltoallv_timeout;
void (*_LOCAL_MPI_Ineighbor_alltoallv)(void *, int *, int *, int *, void *,
                                       int *, int *, int *, int *, int *,
                                       int *);

void A_f_MPI_Ineighbor_alltoallv(void *sendbuf, int *sendcounts, int *sdispls,
                                 int *sendtype, void *recvbuf, int *recvcounts,
                                 int *rdispls, int *recvtype, int *comm,
                                 int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Ineighbor_alltoallv\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Ineighbor_alltoallv_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *sendbuf_tmp = sendbuf;
  int sendtype_tmp;
  void *recvbuf_tmp = recvbuf;
  int recvtype_tmp;
  int comm_tmp;
  int request_tmp;
  buffer_a2r(&sendbuf, &sendbuf_tmp);
  datatype_a2r(sendtype, &sendtype_tmp);
  datatype_a2r(recvtype, &recvtype_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Ineighbor_alltoallv(
      sendbuf_tmp, sendcounts, sdispls, &sendtype_tmp, recvbuf_tmp, recvcounts,
      rdispls, &recvtype_tmp, &comm_tmp, &request_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&recvbuf, &recvbuf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Ineighbor_alltoallv\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_ineighbor_alltoallw_(void *, int *, size_t *, int *, void *, int *,
                              size_t *, int *, int *, int *, int *);

void mpi_ineighbor_alltoallw__(void *, int *, size_t *, int *, void *, int *,
                               size_t *, int *, int *, int *, int *);

void pmpi_ineighbor_alltoallw_(void *, int *, size_t *, int *, void *, int *,
                               size_t *, int *, int *, int *, int *);

void pmpi_ineighbor_alltoallw__(void *, int *, size_t *, int *, void *, int *,
                                size_t *, int *, int *, int *, int *);

void pmpi_ineighbor_alltoallw_(void *, int *, size_t *, int *, void *, int *,
                               size_t *, int *, int *, int *, int *);

#define A_f_MPI_Ineighbor_alltoallw _PMPI_Ineighbor_alltoallw
#pragma weak mpi_ineighbor_alltoallw_ = _PMPI_Ineighbor_alltoallw
#pragma weak mpi_ineighbor_alltoallw__ = _PMPI_Ineighbor_alltoallw
#pragma weak pmpi_ineighbor_alltoallw__ = _PMPI_Ineighbor_alltoallw
extern long long WI4MPI_Ineighbor_alltoallw_timeout;
void (*_LOCAL_MPI_Ineighbor_alltoallw)(void *, int *, size_t *, int *, void *,
                                       int *, size_t *, int *, int *, int *,
                                       int *);

void A_f_MPI_Ineighbor_alltoallw(void *sendbuf, int *sendcounts,
                                 size_t *sdispls, int *sendtypes, void *recvbuf,
                                 int *recvcounts, size_t *rdispls,
                                 int *recvtypes, int *comm, int *request,
                                 int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Ineighbor_alltoallw\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Ineighbor_alltoallw_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;
  int comm_tmp1;
  comm_a2r(comm, &comm_tmp1);
  int *indegree, *outdegree, *weighted, ierr;
  _LOCAL_MPI_Dist_graph_neighbors_count(&comm_tmp1, indegree, outdegree,
                                        weighted, &ierr);
  void *sendbuf_tmp = sendbuf;
  int sendtypes_tmp;
  void *recvbuf_tmp = recvbuf;
  int recvtypes_tmp;
  int comm_tmp;
  int request_tmp;
  buffer_a2r(&sendbuf, &sendbuf_tmp);
  datatype_a2r(sendtypes, &sendtypes_tmp);
  datatype_a2r(recvtypes, &recvtypes_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Ineighbor_alltoallw(
      sendbuf_tmp, sendcounts, sdispls, &sendtypes_tmp, recvbuf_tmp, recvcounts,
      rdispls, &recvtypes_tmp, &comm_tmp, &request_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&recvbuf, &recvbuf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Ineighbor_alltoallw\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_neighbor_allgatherv_(void *, int *, int *, void *, int *, int *, int *,
                              int *, int *);

void mpi_neighbor_allgatherv__(void *, int *, int *, void *, int *, int *,
                               int *, int *, int *);

void pmpi_neighbor_allgatherv_(void *, int *, int *, void *, int *, int *,
                               int *, int *, int *);

void pmpi_neighbor_allgatherv__(void *, int *, int *, void *, int *, int *,
                                int *, int *, int *);

void pmpi_neighbor_allgatherv_(void *, int *, int *, void *, int *, int *,
                               int *, int *, int *);

#define A_f_MPI_Neighbor_allgatherv _PMPI_Neighbor_allgatherv
#pragma weak mpi_neighbor_allgatherv_ = _PMPI_Neighbor_allgatherv
#pragma weak mpi_neighbor_allgatherv__ = _PMPI_Neighbor_allgatherv
#pragma weak pmpi_neighbor_allgatherv__ = _PMPI_Neighbor_allgatherv
extern long long WI4MPI_Neighbor_allgatherv_timeout;
void (*_LOCAL_MPI_Neighbor_allgatherv)(void *, int *, int *, void *, int *,
                                       int *, int *, int *, int *);

void A_f_MPI_Neighbor_allgatherv(void *sendbuf, int *sendcount, int *sendtype,
                                 void *recvbuf, int *recvcounts, int *displs,
                                 int *recvtype, int *comm, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Neighbor_allgatherv\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Neighbor_allgatherv_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *sendbuf_tmp = sendbuf;
  int sendtype_tmp;
  void *recvbuf_tmp = recvbuf;
  int recvtype_tmp;
  int comm_tmp;
  buffer_a2r(&sendbuf, &sendbuf_tmp);
  datatype_a2r(sendtype, &sendtype_tmp);
  datatype_a2r(recvtype, &recvtype_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Neighbor_allgatherv(sendbuf_tmp, sendcount, &sendtype_tmp,
                                 recvbuf_tmp, recvcounts, displs, &recvtype_tmp,
                                 &comm_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&recvbuf, &recvbuf_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Neighbor_allgatherv\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_neighbor_alltoallv_(void *, int *, int *, int *, void *, int *, int *,
                             int *, int *, int *);

void mpi_neighbor_alltoallv__(void *, int *, int *, int *, void *, int *, int *,
                              int *, int *, int *);

void pmpi_neighbor_alltoallv_(void *, int *, int *, int *, void *, int *, int *,
                              int *, int *, int *);

void pmpi_neighbor_alltoallv__(void *, int *, int *, int *, void *, int *,
                               int *, int *, int *, int *);

void pmpi_neighbor_alltoallv_(void *, int *, int *, int *, void *, int *, int *,
                              int *, int *, int *);

#define A_f_MPI_Neighbor_alltoallv _PMPI_Neighbor_alltoallv
#pragma weak mpi_neighbor_alltoallv_ = _PMPI_Neighbor_alltoallv
#pragma weak mpi_neighbor_alltoallv__ = _PMPI_Neighbor_alltoallv
#pragma weak pmpi_neighbor_alltoallv__ = _PMPI_Neighbor_alltoallv
extern long long WI4MPI_Neighbor_alltoallv_timeout;
void (*_LOCAL_MPI_Neighbor_alltoallv)(void *, int *, int *, int *, void *,
                                      int *, int *, int *, int *, int *);

void A_f_MPI_Neighbor_alltoallv(void *sendbuf, int *sendcounts, int *sdispls,
                                int *sendtype, void *recvbuf, int *recvcounts,
                                int *rdispls, int *recvtype, int *comm,
                                int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Neighbor_alltoallv\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Neighbor_alltoallv_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *sendbuf_tmp = sendbuf;
  int sendtype_tmp;
  void *recvbuf_tmp = recvbuf;
  int recvtype_tmp;
  int comm_tmp;
  buffer_a2r(&sendbuf, &sendbuf_tmp);
  datatype_a2r(sendtype, &sendtype_tmp);
  datatype_a2r(recvtype, &recvtype_tmp);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Neighbor_alltoallv(sendbuf_tmp, sendcounts, sdispls, &sendtype_tmp,
                                recvbuf_tmp, recvcounts, rdispls, &recvtype_tmp,
                                &comm_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&recvbuf, &recvbuf_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Neighbor_alltoallv\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_neighbor_alltoallw_(void *, int *, size_t *, int *, void *, int *,
                             size_t *, int *, int *, int *);

void mpi_neighbor_alltoallw__(void *, int *, size_t *, int *, void *, int *,
                              size_t *, int *, int *, int *);

void pmpi_neighbor_alltoallw_(void *, int *, size_t *, int *, void *, int *,
                              size_t *, int *, int *, int *);

void pmpi_neighbor_alltoallw__(void *, int *, size_t *, int *, void *, int *,
                               size_t *, int *, int *, int *);

void pmpi_neighbor_alltoallw_(void *, int *, size_t *, int *, void *, int *,
                              size_t *, int *, int *, int *);

#define A_f_MPI_Neighbor_alltoallw _PMPI_Neighbor_alltoallw
#pragma weak mpi_neighbor_alltoallw_ = _PMPI_Neighbor_alltoallw
#pragma weak mpi_neighbor_alltoallw__ = _PMPI_Neighbor_alltoallw
#pragma weak pmpi_neighbor_alltoallw__ = _PMPI_Neighbor_alltoallw
extern long long WI4MPI_Neighbor_alltoallw_timeout;
void (*_LOCAL_MPI_Neighbor_alltoallw)(void *, int *, size_t *, int *, void *,
                                      int *, size_t *, int *, int *, int *);

void A_f_MPI_Neighbor_alltoallw(void *sendbuf, int *sendcounts, size_t *sdispls,
                                int *sendtypes, void *recvbuf, int *recvcounts,
                                size_t *rdispls, int *recvtypes, int *comm,
                                int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Neighbor_alltoallw\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Neighbor_alltoallw_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;
  int comm_tmp1;
  comm_a2r(comm, &comm_tmp1);
  int *indegree, *outdegree, *weighted, ierr;
  _LOCAL_MPI_Dist_graph_neighbors_count(&comm_tmp1, indegree, outdegree,
                                        weighted, &ierr);
  void *sendbuf_tmp = sendbuf;
  int *sendtypes_tmp = (int *)wi4mpi_alloc((*outdegree) * 1 * sizeof(int));
  void *recvbuf_tmp = recvbuf;
  int *recvtypes_tmp = (int *)wi4mpi_alloc((*indegree) * 1 * sizeof(int));
  int comm_tmp;
  buffer_a2r(&sendbuf, &sendbuf_tmp);
  for (int i = 0; i < *outdegree; i++)
    datatype_a2r(&sendtypes[i * 1], &sendtypes_tmp[i * 1]);
  for (int i = 0; i < *indegree; i++)
    datatype_a2r(&recvtypes[i * 1], &recvtypes_tmp[i * 1]);
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Neighbor_alltoallw(sendbuf_tmp, sendcounts, sdispls, sendtypes_tmp,
                                recvbuf_tmp, recvcounts, rdispls, recvtypes_tmp,
                                &comm_tmp, &ret_tmp);
  wi4mpi_free(sendtypes_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&recvbuf, &recvbuf_tmp);
  wi4mpi_free(recvtypes_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Neighbor_alltoallw\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_iwrite_all_(int *, void *, int *, int *, int *, int *);

void mpi_file_iwrite_all__(int *, void *, int *, int *, int *, int *);

void pmpi_file_iwrite_all_(int *, void *, int *, int *, int *, int *);

void pmpi_file_iwrite_all__(int *, void *, int *, int *, int *, int *);

void pmpi_file_iwrite_all_(int *, void *, int *, int *, int *, int *);

#define A_f_MPI_File_iwrite_all _PMPI_File_iwrite_all
#pragma weak mpi_file_iwrite_all_ = _PMPI_File_iwrite_all
#pragma weak mpi_file_iwrite_all__ = _PMPI_File_iwrite_all
#pragma weak pmpi_file_iwrite_all__ = _PMPI_File_iwrite_all
extern long long WI4MPI_File_iwrite_all_timeout;
void (*_LOCAL_MPI_File_iwrite_all)(int *, void *, int *, int *, int *, int *);

void A_f_MPI_File_iwrite_all(int *fh, void *buf, int *count, int *datatype,
                             int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_iwrite_all\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_iwrite_all_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  int request_tmp;
  buffer_a2r(&buf, &buf_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_File_iwrite_all(fh, buf_tmp, count, &datatype_tmp, &request_tmp,
                             &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&buf, &buf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_iwrite_all\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_iwrite_at_all_(int *, int *, void *, int *, int *, int *, int *);

void mpi_file_iwrite_at_all__(int *, int *, void *, int *, int *, int *, int *);

void pmpi_file_iwrite_at_all_(int *, int *, void *, int *, int *, int *, int *);

void pmpi_file_iwrite_at_all__(int *, int *, void *, int *, int *, int *,
                               int *);

void pmpi_file_iwrite_at_all_(int *, int *, void *, int *, int *, int *, int *);

#define A_f_MPI_File_iwrite_at_all _PMPI_File_iwrite_at_all
#pragma weak mpi_file_iwrite_at_all_ = _PMPI_File_iwrite_at_all
#pragma weak mpi_file_iwrite_at_all__ = _PMPI_File_iwrite_at_all
#pragma weak pmpi_file_iwrite_at_all__ = _PMPI_File_iwrite_at_all
extern long long WI4MPI_File_iwrite_at_all_timeout;
void (*_LOCAL_MPI_File_iwrite_at_all)(int *, int *, void *, int *, int *, int *,
                                      int *);

void A_f_MPI_File_iwrite_at_all(int *fh, int *offset, void *buf, int *count,
                                int *datatype, int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_iwrite_at_all\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_iwrite_at_all_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  int request_tmp;
  buffer_a2r(&buf, &buf_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_File_iwrite_at_all(fh, offset, buf_tmp, count, &datatype_tmp,
                                &request_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&buf, &buf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_iwrite_at_all\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_aint_add_(size_t *, size_t *, size_t *);

void mpi_aint_add__(size_t *, size_t *, size_t *);

void pmpi_aint_add_(size_t *, size_t *, size_t *);

void pmpi_aint_add__(size_t *, size_t *, size_t *);

void pmpi_aint_add_(size_t *, size_t *, size_t *);

#define A_f_MPI_Aint_add _PMPI_Aint_add
#pragma weak mpi_aint_add_ = _PMPI_Aint_add
#pragma weak mpi_aint_add__ = _PMPI_Aint_add
#pragma weak pmpi_aint_add__ = _PMPI_Aint_add
extern long long WI4MPI_Aint_add_timeout;
void (*_LOCAL_MPI_Aint_add)(size_t *, size_t *, size_t *);

void A_f_MPI_Aint_add(size_t *base, size_t *disp, size_t *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Aint_add\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Aint_add_timeout);
#endif
  in_w = 1;
  size_t ret_tmp = 0;

  _LOCAL_MPI_Aint_add(base, disp, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Aint_add\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_aint_diff_(size_t *, size_t *, size_t *);

void mpi_aint_diff__(size_t *, size_t *, size_t *);

void pmpi_aint_diff_(size_t *, size_t *, size_t *);

void pmpi_aint_diff__(size_t *, size_t *, size_t *);

void pmpi_aint_diff_(size_t *, size_t *, size_t *);

#define A_f_MPI_Aint_diff _PMPI_Aint_diff
#pragma weak mpi_aint_diff_ = _PMPI_Aint_diff
#pragma weak mpi_aint_diff__ = _PMPI_Aint_diff
#pragma weak pmpi_aint_diff__ = _PMPI_Aint_diff
extern long long WI4MPI_Aint_diff_timeout;
void (*_LOCAL_MPI_Aint_diff)(size_t *, size_t *, size_t *);

void A_f_MPI_Aint_diff(size_t *addr1, size_t *addr2, size_t *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Aint_diff\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Aint_diff_timeout);
#endif
  in_w = 1;
  size_t ret_tmp = 0;

  _LOCAL_MPI_Aint_diff(addr1, addr2, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Aint_diff\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_iread_all_(int *, void *, int *, int *, int *, int *);

void mpi_file_iread_all__(int *, void *, int *, int *, int *, int *);

void pmpi_file_iread_all_(int *, void *, int *, int *, int *, int *);

void pmpi_file_iread_all__(int *, void *, int *, int *, int *, int *);

void pmpi_file_iread_all_(int *, void *, int *, int *, int *, int *);

#define A_f_MPI_File_iread_all _PMPI_File_iread_all
#pragma weak mpi_file_iread_all_ = _PMPI_File_iread_all
#pragma weak mpi_file_iread_all__ = _PMPI_File_iread_all
#pragma weak pmpi_file_iread_all__ = _PMPI_File_iread_all
extern long long WI4MPI_File_iread_all_timeout;
void (*_LOCAL_MPI_File_iread_all)(int *, void *, int *, int *, int *, int *);

void A_f_MPI_File_iread_all(int *fh, void *buf, int *count, int *datatype,
                            int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_iread_all\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_iread_all_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  int request_tmp;
  buffer_a2r(&buf, &buf_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_File_iread_all(fh, buf_tmp, count, &datatype_tmp, &request_tmp,
                            &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&buf, &buf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_iread_all\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_file_iread_at_all_(int *, int *, void *, int *, int *, int *, int *);

void mpi_file_iread_at_all__(int *, int *, void *, int *, int *, int *, int *);

void pmpi_file_iread_at_all_(int *, int *, void *, int *, int *, int *, int *);

void pmpi_file_iread_at_all__(int *, int *, void *, int *, int *, int *, int *);

void pmpi_file_iread_at_all_(int *, int *, void *, int *, int *, int *, int *);

#define A_f_MPI_File_iread_at_all _PMPI_File_iread_at_all
#pragma weak mpi_file_iread_at_all_ = _PMPI_File_iread_at_all
#pragma weak mpi_file_iread_at_all__ = _PMPI_File_iread_at_all
#pragma weak pmpi_file_iread_at_all__ = _PMPI_File_iread_at_all
extern long long WI4MPI_File_iread_at_all_timeout;
void (*_LOCAL_MPI_File_iread_at_all)(int *, int *, void *, int *, int *, int *,
                                     int *);

void A_f_MPI_File_iread_at_all(int *fh, int *offset, void *buf, int *count,
                               int *datatype, int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_iread_at_all\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_iread_at_all_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *buf_tmp = buf;
  int datatype_tmp;
  int request_tmp;
  buffer_a2r(&buf, &buf_tmp);
  datatype_a2r(datatype, &datatype_tmp);
  _LOCAL_MPI_File_iread_at_all(fh, offset, buf_tmp, count, &datatype_tmp,
                               &request_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    buffer_r2a(&buf, &buf_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    request_r2a(request, &request_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_iread_at_all\n");
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}
void mpi_win_free_keyval_(int *, int *);

void mpi_win_free_keyval__(int *, int *);

void pmpi_win_free_keyval_(int *, int *);

void pmpi_win_free_keyval__(int *, int *);

void pmpi_win_free_keyval_(int *, int *);

#define A_f_MPI_Win_free_keyval _PMPI_Win_free_keyval
#pragma weak mpi_win_free_keyval_ = _PMPI_Win_free_keyval
#pragma weak mpi_win_free_keyval__ = _PMPI_Win_free_keyval
#pragma weak pmpi_win_free_keyval__ = _PMPI_Win_free_keyval
void (*_LOCAL_MPI_Win_free_keyval)(int *, int *);

void A_f_MPI_Win_free_keyval(int *win_keyval, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Win_free_keyval\n");
#endif
  in_w = 1;
  int ret_tmp = 0;
  int comm = R_f_MPI_COMM_WORLD;
  int errorcode = 7;
  fprintf(stderr, "A_f_MPI_Win_free_keyval Not implemented yet\n");
  _LOCAL_MPI_Abort(&comm, &errorcode, &ret_tmp);
  error_r2a(ret, &ret_tmp);
  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Win_free_keyval\n");
#endif
}
void mpi_win_delete_attr_(int *, int *, int *);

void mpi_win_delete_attr__(int *, int *, int *);

void pmpi_win_delete_attr_(int *, int *, int *);

void pmpi_win_delete_attr__(int *, int *, int *);

void pmpi_win_delete_attr_(int *, int *, int *);

#define A_f_MPI_Win_delete_attr _PMPI_Win_delete_attr
#pragma weak mpi_win_delete_attr_ = _PMPI_Win_delete_attr
#pragma weak mpi_win_delete_attr__ = _PMPI_Win_delete_attr
#pragma weak pmpi_win_delete_attr__ = _PMPI_Win_delete_attr
void (*_LOCAL_MPI_Win_delete_attr)(int *, int *, int *);

void A_f_MPI_Win_delete_attr(int *win, int *win_keyval, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Win_delete_attr\n");
#endif
  in_w = 1;
  int ret_tmp = 0;
  int comm = R_f_MPI_COMM_WORLD;
  int errorcode = 7;
  fprintf(stderr, "A_f_MPI_Win_delete_attr Not implemented yet\n");
  _LOCAL_MPI_Abort(&comm, &errorcode, &ret_tmp);
  error_r2a(ret, &ret_tmp);
  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Win_delete_attr\n");
#endif
}
void mpi_win_get_attr_(int *, int *, void *, int *, int *);

void mpi_win_get_attr__(int *, int *, void *, int *, int *);

void pmpi_win_get_attr_(int *, int *, void *, int *, int *);

void pmpi_win_get_attr__(int *, int *, void *, int *, int *);

void pmpi_win_get_attr_(int *, int *, void *, int *, int *);

#define A_f_MPI_Win_get_attr _PMPI_Win_get_attr
#pragma weak mpi_win_get_attr_ = _PMPI_Win_get_attr
#pragma weak mpi_win_get_attr__ = _PMPI_Win_get_attr
#pragma weak pmpi_win_get_attr__ = _PMPI_Win_get_attr
void (*_LOCAL_MPI_Win_get_attr)(int *, int *, void *, int *, int *);

void A_f_MPI_Win_get_attr(int *win, int *win_keyval, void *attribute_val,
                          int *flag, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Win_get_attr\n");
#endif
  in_w = 1;
  int ret_tmp = 0;
  int comm = R_f_MPI_COMM_WORLD;
  int errorcode = 7;
  fprintf(stderr, "A_f_MPI_Win_get_attr Not implemented yet\n");
  _LOCAL_MPI_Abort(&comm, &errorcode, &ret_tmp);
  error_r2a(ret, &ret_tmp);
  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Win_get_attr\n");
#endif
}
void mpi_win_set_attr_(int *, int *, void *, int *);

void mpi_win_set_attr__(int *, int *, void *, int *);

void pmpi_win_set_attr_(int *, int *, void *, int *);

void pmpi_win_set_attr__(int *, int *, void *, int *);

void pmpi_win_set_attr_(int *, int *, void *, int *);

#define A_f_MPI_Win_set_attr _PMPI_Win_set_attr
#pragma weak mpi_win_set_attr_ = _PMPI_Win_set_attr
#pragma weak mpi_win_set_attr__ = _PMPI_Win_set_attr
#pragma weak pmpi_win_set_attr__ = _PMPI_Win_set_attr
void (*_LOCAL_MPI_Win_set_attr)(int *, int *, void *, int *);

void A_f_MPI_Win_set_attr(int *win, int *win_keyval, void *attribute_val,
                          int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Win_set_attr\n");
#endif
  in_w = 1;
  int ret_tmp = 0;
  int comm = R_f_MPI_COMM_WORLD;
  int errorcode = 7;
  fprintf(stderr, "A_f_MPI_Win_set_attr Not implemented yet\n");
  _LOCAL_MPI_Abort(&comm, &errorcode, &ret_tmp);
  error_r2a(ret, &ret_tmp);
  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Win_set_attr\n");
#endif
}
void mpi_win_create_keyval_(void *, void *, int *, void *, int *);

void mpi_win_create_keyval__(void *, void *, int *, void *, int *);

void pmpi_win_create_keyval_(void *, void *, int *, void *, int *);

void pmpi_win_create_keyval__(void *, void *, int *, void *, int *);

void pmpi_win_create_keyval_(void *, void *, int *, void *, int *);

#define A_f_MPI_Win_create_keyval _PMPI_Win_create_keyval
#pragma weak mpi_win_create_keyval_ = _PMPI_Win_create_keyval
#pragma weak mpi_win_create_keyval__ = _PMPI_Win_create_keyval
#pragma weak pmpi_win_create_keyval__ = _PMPI_Win_create_keyval
void (*_LOCAL_MPI_Win_create_keyval)(void *, void *, int *, void *, int *);

void A_f_MPI_Win_create_keyval(void *win_copy_attr_fn, void *win_delete_attr_fn,
                               int *win_keyval, void *extra_state, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Win_create_keyval\n");
#endif
  in_w = 1;
  int ret_tmp = 0;
  int comm = R_f_MPI_COMM_WORLD;
  int errorcode = 7;
  fprintf(stderr, "A_f_MPI_Win_create_keyval Not implemented yet\n");
  _LOCAL_MPI_Abort(&comm, &errorcode, &ret_tmp);
  error_r2a(ret, &ret_tmp);
  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Win_create_keyval\n");
#endif
}
void mpi_win_create_errhandler_(void *, int *, int *);

void mpi_win_create_errhandler__(void *, int *, int *);

void pmpi_win_create_errhandler_(void *, int *, int *);

void pmpi_win_create_errhandler__(void *, int *, int *);

void pmpi_win_create_errhandler_(void *, int *, int *);

#define A_f_MPI_Win_create_errhandler _PMPI_Win_create_errhandler
#pragma weak mpi_win_create_errhandler_ = _PMPI_Win_create_errhandler
#pragma weak mpi_win_create_errhandler__ = _PMPI_Win_create_errhandler
#pragma weak pmpi_win_create_errhandler__ = _PMPI_Win_create_errhandler
void (*_LOCAL_MPI_Win_create_errhandler)(void *, int *, int *);

void A_f_MPI_Win_create_errhandler(void *win_errhandler_fn, int *errhandler,
                                   int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Win_create_errhandler\n");
#endif
  in_w = 1;
  int ret_tmp = 0;
  int comm = R_f_MPI_COMM_WORLD;
  int errorcode = 7;
  fprintf(stderr, "A_f_MPI_Win_create_errhandler Not implemented yet\n");
  _LOCAL_MPI_Abort(&comm, &errorcode, &ret_tmp);
  error_r2a(ret, &ret_tmp);
  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Win_create_errhandler\n");
#endif
}
void mpi_win_call_errhandler_(int *, int *, int *);

void mpi_win_call_errhandler__(int *, int *, int *);

void pmpi_win_call_errhandler_(int *, int *, int *);

void pmpi_win_call_errhandler__(int *, int *, int *);

void pmpi_win_call_errhandler_(int *, int *, int *);

#define A_f_MPI_Win_call_errhandler _PMPI_Win_call_errhandler
#pragma weak mpi_win_call_errhandler_ = _PMPI_Win_call_errhandler
#pragma weak mpi_win_call_errhandler__ = _PMPI_Win_call_errhandler
#pragma weak pmpi_win_call_errhandler__ = _PMPI_Win_call_errhandler
void (*_LOCAL_MPI_Win_call_errhandler)(int *, int *, int *);

void A_f_MPI_Win_call_errhandler(int *win, int *errorcode, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Win_call_errhandler\n");
#endif
  in_w = 1;
  int ret_tmp = 0;
  int comm = R_f_MPI_COMM_WORLD;
  int errorcode_tmp = 7;
  fprintf(stderr, "A_f_MPI_Win_call_errhandler Not implemented yet\n");
  _LOCAL_MPI_Abort(&comm, &errorcode_tmp, &ret_tmp);
  error_r2a(ret, &ret_tmp);
  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Win_call_errhandler\n");
#endif
}
void mpi_win_set_errhandler_(int *, int *, int *);

void mpi_win_set_errhandler__(int *, int *, int *);

void pmpi_win_set_errhandler_(int *, int *, int *);

void pmpi_win_set_errhandler__(int *, int *, int *);

void pmpi_win_set_errhandler_(int *, int *, int *);

#define A_f_MPI_Win_set_errhandler _PMPI_Win_set_errhandler
#pragma weak mpi_win_set_errhandler_ = _PMPI_Win_set_errhandler
#pragma weak mpi_win_set_errhandler__ = _PMPI_Win_set_errhandler
#pragma weak pmpi_win_set_errhandler__ = _PMPI_Win_set_errhandler
void (*_LOCAL_MPI_Win_set_errhandler)(int *, int *, int *);

void A_f_MPI_Win_set_errhandler(int *win, int *errhandler, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Win_set_errhandler\n");
#endif
  in_w = 1;
  int ret_tmp = 0;
  int comm_tmp = R_f_MPI_COMM_WORLD;
  int errorcode_tmp = 7;
  fprintf(stderr, "A_f_MPI_Win_set_errhandler Not implemented yet\n");
  _LOCAL_MPI_Abort(&comm_tmp, &errorcode_tmp, &ret_tmp);
  error_r2a(ret, &ret_tmp);
  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Win_set_errhandler\n");
#endif
}
void mpi_win_get_errhandler_(int *, int *, int *);

void mpi_win_get_errhandler__(int *, int *, int *);

void pmpi_win_get_errhandler_(int *, int *, int *);

void pmpi_win_get_errhandler__(int *, int *, int *);

void pmpi_win_get_errhandler_(int *, int *, int *);

#define A_f_MPI_Win_get_errhandler _PMPI_Win_get_errhandler
#pragma weak mpi_win_get_errhandler_ = _PMPI_Win_get_errhandler
#pragma weak mpi_win_get_errhandler__ = _PMPI_Win_get_errhandler
#pragma weak pmpi_win_get_errhandler__ = _PMPI_Win_get_errhandler
void (*_LOCAL_MPI_Win_get_errhandler)(int *, int *, int *);

void A_f_MPI_Win_get_errhandler(int *win, int *errhandler, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Win_get_errhandler\n");
#endif
  in_w = 1;
  int ret_tmp = 0;
  int comm = R_f_MPI_COMM_WORLD;
  int errorcode = 7;
  fprintf(stderr, "A_f_MPI_Win_get_errhandler Not implemented yet\n");
  _LOCAL_MPI_Abort(&comm, &errorcode, &ret_tmp);
  error_r2a(ret, &ret_tmp);
  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Win_get_errhandler\n");
#endif
}

void mpi_file_call_errhandler_(int *, int *, int *);

void mpi_file_call_errhandler__(int *, int *, int *);

void pmpi_file_call_errhandler_(int *, int *, int *);

void pmpi_file_call_errhandler__(int *, int *, int *);

void pmpi_file_call_errhandler_(int *, int *, int *);

#define A_f_MPI_File_call_errhandler _PMPI_File_call_errhandler
#pragma weak mpi_file_call_errhandler_ = _PMPI_File_call_errhandler
#pragma weak mpi_file_call_errhandler__ = _PMPI_File_call_errhandler
#pragma weak pmpi_file_call_errhandler__ = _PMPI_File_call_errhandler
void (*_LOCAL_MPI_File_call_errhandler)(int *, int *, int *);

void A_f_MPI_File_call_errhandler(int *fh, int *errorcode, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_call_errhandler\n");
#endif
  in_w = 1;
  int ret_tmp = 0;
  int comm = R_f_MPI_COMM_WORLD;
  int errorcode_tmp = 7;
  fprintf(stderr, "A_f_MPI_File_call_errhandler Not implemented yet\n");
  _LOCAL_MPI_Abort(&comm, &errorcode_tmp, &ret_tmp);
  error_r2a(ret, &ret_tmp);
  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_call_errhandler\n");
#endif
}
void mpi_file_create_errhandler_(void *, int *, int *);

void mpi_file_create_errhandler__(void *, int *, int *);

void pmpi_file_create_errhandler_(void *, int *, int *);

void pmpi_file_create_errhandler__(void *, int *, int *);

void pmpi_file_create_errhandler_(void *, int *, int *);

#define A_f_MPI_File_create_errhandler _PMPI_File_create_errhandler
#pragma weak mpi_file_create_errhandler_ = _PMPI_File_create_errhandler
#pragma weak mpi_file_create_errhandler__ = _PMPI_File_create_errhandler
#pragma weak pmpi_file_create_errhandler__ = _PMPI_File_create_errhandler
void (*_LOCAL_MPI_File_create_errhandler)(void *, int *, int *);

void A_f_MPI_File_create_errhandler(void *file_errhandler_fn, int *errhandler,
                                    int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_File_create_errhandler\n");
#endif
  in_w = 1;
  int ret_tmp = 0;
  int comm = R_f_MPI_COMM_WORLD;
  int errorcode = 7;
  fprintf(stderr, "A_f_MPI_File_create_errhandler Not implemented yet\n");
  _LOCAL_MPI_Abort(&comm, &errorcode, &ret_tmp);
  error_r2a(ret, &ret_tmp);
  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_File_create_errhandler\n");
#endif
}
void mpi_type_create_keyval_(void **, void *, int *, void *, int *);

void mpi_type_create_keyval__(void **, void *, int *, void *, int *);

void pmpi_type_create_keyval_(void **, void *, int *, void *, int *);

void pmpi_type_create_keyval__(void **, void *, int *, void *, int *);

void pmpi_type_create_keyval_(void **, void *, int *, void *, int *);

#define A_f_MPI_Type_create_keyval _PMPI_Type_create_keyval
#pragma weak mpi_type_create_keyval_ = _PMPI_Type_create_keyval
#pragma weak mpi_type_create_keyval__ = _PMPI_Type_create_keyval
#pragma weak pmpi_type_create_keyval__ = _PMPI_Type_create_keyval
void (*_LOCAL_MPI_Type_create_keyval)(void **, void *, int *, void *, int *);

void A_f_MPI_Type_create_keyval(void **type_copy_attr_fn,
                                void *type_delete_attr_fn, int *type_keyval,
                                void *extra_state, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Type_create_keyval\n");
#endif
  in_w = 1;
  int ret_tmp = 0;
  int comm = R_f_MPI_COMM_WORLD;
  int errorcode = 7;
  fprintf(stderr, "A_f_MPI_Type_create_keyval Not implemented yet\n");
  _LOCAL_MPI_Abort(&comm, &errorcode, &ret_tmp);
  error_r2a(ret, &ret_tmp);
  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Type_create_keyval\n");
#endif
}
void mpi_grequest_complete_(int *, int *);

void mpi_grequest_complete__(int *, int *);

void pmpi_grequest_complete_(int *, int *);

void pmpi_grequest_complete__(int *, int *);

void pmpi_grequest_complete_(int *, int *);

#define A_f_MPI_Grequest_complete _PMPI_Grequest_complete
#pragma weak mpi_grequest_complete_ = _PMPI_Grequest_complete
#pragma weak mpi_grequest_complete__ = _PMPI_Grequest_complete
#pragma weak pmpi_grequest_complete__ = _PMPI_Grequest_complete
void (*_LOCAL_MPI_Grequest_complete)(int *, int *);

void A_f_MPI_Grequest_complete(int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Grequest_complete\n");
#endif
  in_w = 1;
  int ret_tmp = 0;
  int comm = R_f_MPI_COMM_WORLD;
  int errorcode = 7;
  fprintf(stderr, "A_f_MPI_Grequest_complete Not implemented yet\n");
  _LOCAL_MPI_Abort(&comm, &errorcode, &ret_tmp);
  error_r2a(ret, &ret_tmp);
  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Grequest_complete\n");
#endif
}
void mpi_grequest_start_(void *, void *, void *, void *, int *, int *);

void mpi_grequest_start__(void *, void *, void *, void *, int *, int *);

void pmpi_grequest_start_(void *, void *, void *, void *, int *, int *);

void pmpi_grequest_start__(void *, void *, void *, void *, int *, int *);

void pmpi_grequest_start_(void *, void *, void *, void *, int *, int *);

#define A_f_MPI_Grequest_start _PMPI_Grequest_start
#pragma weak mpi_grequest_start_ = _PMPI_Grequest_start
#pragma weak mpi_grequest_start__ = _PMPI_Grequest_start
#pragma weak pmpi_grequest_start__ = _PMPI_Grequest_start
void (*_LOCAL_MPI_Grequest_start)(void *, void *, void *, void *, int *, int *);

void A_f_MPI_Grequest_start(void *query_fn, void *free_fn, void *cancel_fn,
                            void *extra_state, int *request, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Grequest_start\n");
#endif
  in_w = 1;
  int ret_tmp = 0;
  int comm = R_f_MPI_COMM_WORLD;
  int errorcode = 7;
  fprintf(stderr, "A_f_MPI_Grequest_start Not implemented yet\n");
  _LOCAL_MPI_Abort(&comm, &errorcode, &ret_tmp);
  error_r2a(ret, &ret_tmp);
  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Grequest_start\n");
#endif
}
void mpi_comm_create_keyval_(void *, void *, int *, void *, int *);

void mpi_comm_create_keyval__(void *, void *, int *, void *, int *);

void pmpi_comm_create_keyval_(void *, void *, int *, void *, int *);

void pmpi_comm_create_keyval__(void *, void *, int *, void *, int *);

void pmpi_comm_create_keyval_(void *, void *, int *, void *, int *);

#define A_f_MPI_Comm_create_keyval _PMPI_Comm_create_keyval
#pragma weak mpi_comm_create_keyval_ = _PMPI_Comm_create_keyval
#pragma weak mpi_comm_create_keyval__ = _PMPI_Comm_create_keyval
#pragma weak pmpi_comm_create_keyval__ = _PMPI_Comm_create_keyval
void (*_LOCAL_MPI_Comm_create_keyval)(void *, void *, int *, void *, int *);

void A_f_MPI_Comm_create_keyval(void *comm_copy_attr_fn,
                                void *comm_delete_attr_fn, int *comm_keyval,
                                void *extra_state, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Comm_create_keyval\n");
#endif
  in_w = 1;
  int ret_tmp = 0;
  int comm = R_f_MPI_COMM_WORLD;
  int errorcode = 7;
  fprintf(stderr, "A_f_MPI_Comm_create_keyval Not implemented yet\n");
  _LOCAL_MPI_Abort(&comm, &errorcode, &ret_tmp);
  error_r2a(ret, &ret_tmp);
  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Comm_create_keyval\n");
#endif
}
void mpi_comm_free_keyval_(int *, int *);

void mpi_comm_free_keyval__(int *, int *);

void pmpi_comm_free_keyval_(int *, int *);

void pmpi_comm_free_keyval__(int *, int *);

void pmpi_comm_free_keyval_(int *, int *);

#define A_f_MPI_Comm_free_keyval _PMPI_Comm_free_keyval
#pragma weak mpi_comm_free_keyval_ = _PMPI_Comm_free_keyval
#pragma weak mpi_comm_free_keyval__ = _PMPI_Comm_free_keyval
#pragma weak pmpi_comm_free_keyval__ = _PMPI_Comm_free_keyval
void (*_LOCAL_MPI_Comm_free_keyval)(int *, int *);

void A_f_MPI_Comm_free_keyval(int *comm_keyval, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Comm_free_keyval\n");
#endif
  in_w = 1;
  // int ret_tmp=0;
  // int comm=R_f_MPI_COMM_WORLD;
  // int errorcode=7;
  // fprintf(stderr, "A_f_MPI_Comm_free_keyval Not implemented yet\n");
  //_LOCAL_MPI_Abort( &comm, &errorcode, &ret_tmp);
  // error_r2a(ret,&ret_tmp);
  int ret_tmp = 0;

  //_LOCAL_MPI_Keyval_free( keyval, &ret_tmp);
  _LOCAL_MPI_Comm_free_keyval(comm_keyval, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS) {
    *comm_keyval = A_MPI_KEYVAL_INVALID;
  }

  error_r2a(ret, &ret_tmp);
  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Comm_free_keyval\n");
#endif
}
void mpi_pcontrol_(int *, int *);

void mpi_pcontrol__(int *, int *);

void pmpi_pcontrol_(int *, int *);

void pmpi_pcontrol__(int *, int *);

void pmpi_pcontrol_(int *, int *);

#define A_f_MPI_Pcontrol _PMPI_Pcontrol
#pragma weak mpi_pcontrol_ = _PMPI_Pcontrol
#pragma weak mpi_pcontrol__ = _PMPI_Pcontrol
#pragma weak pmpi_pcontrol__ = _PMPI_Pcontrol
void (*_LOCAL_MPI_Pcontrol)(int *, int *);

void A_f_MPI_Pcontrol(int *level, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Pcontrol\n");
#endif
  in_w = 1;
  // int ret_tmp=0;
  // int comm_tmp=R_f_MPI_COMM_WORLD;
  // int errorcode_tmp=7;
  // fprintf(stderr, "Not implemented yet\n");
  //_LOCAL_MPI_Abort( &comm_tmp, &errorcode_tmp, &ret_tmp);
  // error_r2a(ret,&ret_tmp);
  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Pcontrol\n");
#endif
  *ret = A_MPI_SUCCESS;
  return;
}

void mpi_register_datarep_(char **, void *, void *, void *, void *, int *, int);

void mpi_register_datarep__(char **, void *, void *, void *, void *, int *,
                            int);

void pmpi_register_datarep_(char **, void *, void *, void *, void *, int *,
                            int);

void pmpi_register_datarep__(char **, void *, void *, void *, void *, int *,
                             int);

void pmpi_register_datarep_(char **, void *, void *, void *, void *, int *,
                            int);

#define A_f_MPI_Register_datarep _PMPI_Register_datarep
#pragma weak mpi_register_datarep_ = _PMPI_Register_datarep
#pragma weak mpi_register_datarep__ = _PMPI_Register_datarep
#pragma weak pmpi_register_datarep__ = _PMPI_Register_datarep
void (*_LOCAL_MPI_Register_datarep)(char **, void *, void *, void *, void *,
                                    int *, int);

void A_f_MPI_Register_datarep(char **datarep, void *read_conversion_fn,
                              void *write_conversion_fn,
                              void *dtype_file_extent_fn, void *extra_state,
                              int *ret, int datarep_len) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Register_datarep\n");
#endif
  in_w = 1;
  int ret_tmp = 0;
  int comm = R_f_MPI_COMM_WORLD;
  int errorcode = 7;
  fprintf(stderr, "A_f_MPI_Register_datarep Not implemented yet\n");
  _LOCAL_MPI_Abort(&comm, &errorcode, &ret_tmp);
  error_r2a(ret, &ret_tmp);
  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Register_datarep\n");
#endif
}

void mpi_comm_spawn_multiple_(int, char **, char ***, int *, int *, int, int,
                              int *, int *, int *, int, int);

void mpi_comm_spawn_multiple__(int, char **, char ***, int *, int *, int, int,
                               int *, int *, int *, int, int);

void pmpi_comm_spawn_multiple_(int, char **, char ***, int *, int *, int, int,
                               int *, int *, int *, int, int);

void pmpi_comm_spawn_multiple__(int, char **, char ***, int *, int *, int, int,
                                int *, int *, int *, int, int);

void pmpi_comm_spawn_multiple_(int, char **, char ***, int *, int *, int, int,
                               int *, int *, int *, int, int);

#define A_f_MPI_Comm_spawn_multiple _PMPI_Comm_spawn_multiple
#pragma weak mpi_comm_spawn_multiple_ = _PMPI_Comm_spawn_multiple
#pragma weak mpi_comm_spawn_multiple__ = _PMPI_Comm_spawn_multiple
#pragma weak pmpi_comm_spawn_multiple__ = _PMPI_Comm_spawn_multiple
void (*_LOCAL_MPI_Comm_spawn_multiple)(int, char **, char ***, int *, int *,
                                       int, int, int *, int *, int *, int, int);

void A_f_MPI_Comm_spawn_multiple(int count, char **command, char ***argv,
                                 int *maxprocs, int *info, int *root, int *comm,
                                 int *intercomm, int *array_of_errcodes,
                                 int *ret, int command_len, int argv_len) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Comm_spawn_multiple\n");
#endif
  in_w = 1;
  int ret_tmp = 0;
  int comm_tmp = R_f_MPI_COMM_WORLD;
  int errorcode = 7;
  fprintf(stderr, "A_f_MPI_Comm_spawn_multiple Not implemented yet\n");
  _LOCAL_MPI_Abort(&comm_tmp, &errorcode, &ret_tmp);
  error_r2a(ret, &ret_tmp);
  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Comm_spawn_multiple\n");
#endif
}

__attribute__((constructor)) void wrapper_init_f(void) {
  /* ABI FIGE */
  _LOCAL_MPI_Win_free_keyval = dlsym(RTLD_NEXT, "pmpi_win_free_keyval_");
  _LOCAL_MPI_Win_delete_attr = dlsym(RTLD_NEXT, "pmpi_win_delete_attr_");
  _LOCAL_MPI_Win_get_attr = dlsym(RTLD_NEXT, "pmpi_win_get_attr_");
  _LOCAL_MPI_Win_set_attr = dlsym(RTLD_NEXT, "pmpi_win_set_attr_");
  _LOCAL_MPI_Win_create_keyval = dlsym(RTLD_NEXT, "pmpi_win_create_keyval_");
  _LOCAL_MPI_Win_create_errhandler =
      dlsym(RTLD_NEXT, "pmpi_win_create_errhandler_");
  _LOCAL_MPI_Win_call_errhandler =
      dlsym(RTLD_NEXT, "pmpi_win_call_errhandler_");
  _LOCAL_MPI_Win_set_errhandler = dlsym(RTLD_NEXT, "pmpi_win_set_errhandler_");
  _LOCAL_MPI_Win_get_errhandler = dlsym(RTLD_NEXT, "pmpi_win_get_errhandler_");
  _LOCAL_MPI_File_call_errhandler =
      dlsym(RTLD_NEXT, "pmpi_file_call_errhandler_");
  _LOCAL_MPI_File_create_errhandler =
      dlsym(RTLD_NEXT, "pmpi_file_create_errhandler_");
  _LOCAL_MPI_Type_create_keyval = dlsym(RTLD_NEXT, "pmpi_type_create_keyval_");
  _LOCAL_MPI_Grequest_complete = dlsym(RTLD_NEXT, "pmpi_grequest_complete_");
  _LOCAL_MPI_Grequest_start = dlsym(RTLD_NEXT, "pmpi_grequest_start_");
  _LOCAL_MPI_Comm_create_keyval = dlsym(RTLD_NEXT, "pmpi_comm_create_keyval_");
  _LOCAL_MPI_Comm_free_keyval = dlsym(RTLD_NEXT, "pmpi_comm_free_keyval_");
  _LOCAL_MPI_Register_datarep = dlsym(RTLD_NEXT, "pmpi_register_datarep_");
  _LOCAL_MPI_Comm_spawn_multiple =
      dlsym(RTLD_NEXT, "pmpi_comm_spawn_multiple_");
  _LOCAL_MPI_Pcontrol = dlsym(RTLD_NEXT, "pmpi_pcontrol_");
  /* --- */
  _LOCAL_MPI_Send = dlsym(RTLD_NEXT, "pmpi_send_");
  _LOCAL_MPI_Recv = dlsym(RTLD_NEXT, "pmpi_recv_");
  _LOCAL_MPI_Get_count = dlsym(RTLD_NEXT, "pmpi_get_count_");
  _LOCAL_MPI_Bsend = dlsym(RTLD_NEXT, "pmpi_bsend_");
  _LOCAL_MPI_Ssend = dlsym(RTLD_NEXT, "pmpi_ssend_");
  _LOCAL_MPI_Rsend = dlsym(RTLD_NEXT, "pmpi_rsend_");
  _LOCAL_MPI_Buffer_attach = dlsym(RTLD_NEXT, "pmpi_buffer_attach_");
  _LOCAL_MPI_Buffer_detach = dlsym(RTLD_NEXT, "pmpi_buffer_detach_");
  _LOCAL_MPI_Isend = dlsym(RTLD_NEXT, "pmpi_isend_");
  _LOCAL_MPI_Ibsend = dlsym(RTLD_NEXT, "pmpi_ibsend_");
  _LOCAL_MPI_Issend = dlsym(RTLD_NEXT, "pmpi_issend_");
  _LOCAL_MPI_Irsend = dlsym(RTLD_NEXT, "pmpi_irsend_");
  _LOCAL_MPI_Irecv = dlsym(RTLD_NEXT, "pmpi_irecv_");
  _LOCAL_MPI_Wait = dlsym(RTLD_NEXT, "pmpi_wait_");
  _LOCAL_MPI_Test = dlsym(RTLD_NEXT, "pmpi_test_");
  _LOCAL_MPI_Request_free = dlsym(RTLD_NEXT, "pmpi_request_free_");
  _LOCAL_MPI_Iprobe = dlsym(RTLD_NEXT, "pmpi_iprobe_");
  _LOCAL_MPI_Probe = dlsym(RTLD_NEXT, "pmpi_probe_");
  _LOCAL_MPI_Cancel = dlsym(RTLD_NEXT, "pmpi_cancel_");
  _LOCAL_MPI_Test_cancelled = dlsym(RTLD_NEXT, "pmpi_test_cancelled_");
  _LOCAL_MPI_Send_init = dlsym(RTLD_NEXT, "pmpi_send_init_");
  _LOCAL_MPI_Bsend_init = dlsym(RTLD_NEXT, "pmpi_bsend_init_");
  _LOCAL_MPI_Ssend_init = dlsym(RTLD_NEXT, "pmpi_ssend_init_");
  _LOCAL_MPI_Rsend_init = dlsym(RTLD_NEXT, "pmpi_rsend_init_");
  _LOCAL_MPI_Recv_init = dlsym(RTLD_NEXT, "pmpi_recv_init_");
  _LOCAL_MPI_Start = dlsym(RTLD_NEXT, "pmpi_start_");
  _LOCAL_MPI_Sendrecv = dlsym(RTLD_NEXT, "pmpi_sendrecv_");
  _LOCAL_MPI_Sendrecv_replace = dlsym(RTLD_NEXT, "pmpi_sendrecv_replace_");
  _LOCAL_MPI_Type_contiguous = dlsym(RTLD_NEXT, "pmpi_type_contiguous_");
  _LOCAL_MPI_Type_vector = dlsym(RTLD_NEXT, "pmpi_type_vector_");
  _LOCAL_MPI_Type_hvector = dlsym(RTLD_NEXT, "pmpi_type_hvector_");
  _LOCAL_MPI_Type_indexed = dlsym(RTLD_NEXT, "pmpi_type_indexed_");
  _LOCAL_MPI_Type_hindexed = dlsym(RTLD_NEXT, "pmpi_type_hindexed_");
  _LOCAL_MPI_Type_struct = dlsym(RTLD_NEXT, "pmpi_type_struct_");
  _LOCAL_MPI_Address = dlsym(RTLD_NEXT, "pmpi_address_");
  _LOCAL_MPI_Type_extent = dlsym(RTLD_NEXT, "pmpi_type_extent_");
  _LOCAL_MPI_Type_size = dlsym(RTLD_NEXT, "pmpi_type_size_");
  _LOCAL_MPI_Type_lb = dlsym(RTLD_NEXT, "pmpi_type_lb_");
  _LOCAL_MPI_Type_ub = dlsym(RTLD_NEXT, "pmpi_type_ub_");
  _LOCAL_MPI_Type_commit = dlsym(RTLD_NEXT, "pmpi_type_commit_");
  _LOCAL_MPI_Type_free = dlsym(RTLD_NEXT, "pmpi_type_free_");
  _LOCAL_MPI_Get_elements = dlsym(RTLD_NEXT, "pmpi_get_elements_");
  _LOCAL_MPI_Pack = dlsym(RTLD_NEXT, "pmpi_pack_");
  _LOCAL_MPI_Unpack = dlsym(RTLD_NEXT, "pmpi_unpack_");
  _LOCAL_MPI_Pack_size = dlsym(RTLD_NEXT, "pmpi_pack_size_");
  _LOCAL_MPI_Barrier = dlsym(RTLD_NEXT, "pmpi_barrier_");
  _LOCAL_MPI_Bcast = dlsym(RTLD_NEXT, "pmpi_bcast_");
  _LOCAL_MPI_Gather = dlsym(RTLD_NEXT, "pmpi_gather_");
  _LOCAL_MPI_Gatherv = dlsym(RTLD_NEXT, "pmpi_gatherv_");
  _LOCAL_MPI_Scatter = dlsym(RTLD_NEXT, "pmpi_scatter_");
  _LOCAL_MPI_Scatterv = dlsym(RTLD_NEXT, "pmpi_scatterv_");
  _LOCAL_MPI_Allgather = dlsym(RTLD_NEXT, "pmpi_allgather_");
  _LOCAL_MPI_Allgatherv = dlsym(RTLD_NEXT, "pmpi_allgatherv_");
  _LOCAL_MPI_Alltoall = dlsym(RTLD_NEXT, "pmpi_alltoall_");
  _LOCAL_MPI_Alltoallv = dlsym(RTLD_NEXT, "pmpi_alltoallv_");
  _LOCAL_MPI_Exscan = dlsym(RTLD_NEXT, "pmpi_exscan_");
  _LOCAL_MPI_Reduce = dlsym(RTLD_NEXT, "pmpi_reduce_");
  _LOCAL_MPI_Op_create = dlsym(RTLD_NEXT, "pmpi_op_create_");
  _LOCAL_MPI_Op_free = dlsym(RTLD_NEXT, "pmpi_op_free_");
  _LOCAL_MPI_Allreduce = dlsym(RTLD_NEXT, "pmpi_allreduce_");
  _LOCAL_MPI_Scan = dlsym(RTLD_NEXT, "pmpi_scan_");
  _LOCAL_MPI_Group_size = dlsym(RTLD_NEXT, "pmpi_group_size_");
  _LOCAL_MPI_Group_rank = dlsym(RTLD_NEXT, "pmpi_group_rank_");
  _LOCAL_MPI_Group_compare = dlsym(RTLD_NEXT, "pmpi_group_compare_");
  _LOCAL_MPI_Comm_group = dlsym(RTLD_NEXT, "pmpi_comm_group_");
  _LOCAL_MPI_Group_union = dlsym(RTLD_NEXT, "pmpi_group_union_");
  _LOCAL_MPI_Group_intersection = dlsym(RTLD_NEXT, "pmpi_group_intersection_");
  _LOCAL_MPI_Group_difference = dlsym(RTLD_NEXT, "pmpi_group_difference_");
  _LOCAL_MPI_Group_free = dlsym(RTLD_NEXT, "pmpi_group_free_");
  _LOCAL_MPI_Comm_size = dlsym(RTLD_NEXT, "pmpi_comm_size_");
  _LOCAL_MPI_Comm_rank = dlsym(RTLD_NEXT, "pmpi_comm_rank_");
  _LOCAL_MPI_Comm_compare = dlsym(RTLD_NEXT, "pmpi_comm_compare_");
  _LOCAL_MPI_Comm_dup = dlsym(RTLD_NEXT, "pmpi_comm_dup_");
  _LOCAL_MPI_Comm_dup_with_info = dlsym(RTLD_NEXT, "pmpi_comm_dup_with_info_");
  _LOCAL_MPI_Comm_create = dlsym(RTLD_NEXT, "pmpi_comm_create_");
  _LOCAL_MPI_Comm_split = dlsym(RTLD_NEXT, "pmpi_comm_split_");
  _LOCAL_MPI_Comm_free = dlsym(RTLD_NEXT, "pmpi_comm_free_");
  _LOCAL_MPI_Comm_test_inter = dlsym(RTLD_NEXT, "pmpi_comm_test_inter_");
  _LOCAL_MPI_Comm_remote_size = dlsym(RTLD_NEXT, "pmpi_comm_remote_size_");
  _LOCAL_MPI_Comm_remote_group = dlsym(RTLD_NEXT, "pmpi_comm_remote_group_");
  _LOCAL_MPI_Intercomm_create = dlsym(RTLD_NEXT, "pmpi_intercomm_create_");
  _LOCAL_MPI_Intercomm_merge = dlsym(RTLD_NEXT, "pmpi_intercomm_merge_");
  _LOCAL_MPI_Keyval_create = dlsym(RTLD_NEXT, "pmpi_keyval_create_");
  _LOCAL_MPI_Keyval_free = dlsym(RTLD_NEXT, "pmpi_keyval_free_");
  _LOCAL_MPI_Attr_put = dlsym(RTLD_NEXT, "pmpi_attr_put_");
  _LOCAL_MPI_Attr_get = dlsym(RTLD_NEXT, "pmpi_attr_get_");
  _LOCAL_MPI_Attr_delete = dlsym(RTLD_NEXT, "pmpi_attr_delete_");
  _LOCAL_MPI_Topo_test = dlsym(RTLD_NEXT, "pmpi_topo_test_");
  _LOCAL_MPI_Graphdims_get = dlsym(RTLD_NEXT, "pmpi_graphdims_get_");
  _LOCAL_MPI_Cartdim_get = dlsym(RTLD_NEXT, "pmpi_cartdim_get_");
  _LOCAL_MPI_Graph_neighbors_count =
      dlsym(RTLD_NEXT, "pmpi_graph_neighbors_count_");
  _LOCAL_MPI_Cart_shift = dlsym(RTLD_NEXT, "pmpi_cart_shift_");
  _LOCAL_MPI_Get_version = dlsym(RTLD_NEXT, "pmpi_get_version_");
  _LOCAL_MPI_Errhandler_create = dlsym(RTLD_NEXT, "pmpi_errhandler_create_");
  _LOCAL_MPI_Errhandler_set = dlsym(RTLD_NEXT, "pmpi_errhandler_set_");
  _LOCAL_MPI_Errhandler_get = dlsym(RTLD_NEXT, "pmpi_errhandler_get_");
  _LOCAL_MPI_Errhandler_free = dlsym(RTLD_NEXT, "pmpi_errhandler_free_");
  _LOCAL_MPI_Error_class = dlsym(RTLD_NEXT, "pmpi_error_class_");
  _LOCAL_MPI_Initialized = dlsym(RTLD_NEXT, "pmpi_initialized_");
  _LOCAL_MPI_Abort = dlsym(RTLD_NEXT, "pmpi_abort_");
  _LOCAL_MPI_Init = dlsym(RTLD_NEXT, "pmpi_init_");
  _LOCAL_MPI_Comm_accept = dlsym(RTLD_NEXT, "pmpi_comm_accept_");
  _LOCAL_MPI_Comm_connect = dlsym(RTLD_NEXT, "pmpi_comm_connect_");
  _LOCAL_MPI_Comm_disconnect = dlsym(RTLD_NEXT, "pmpi_comm_disconnect_");
  _LOCAL_MPI_Comm_get_parent = dlsym(RTLD_NEXT, "pmpi_comm_get_parent_");
  _LOCAL_MPI_Comm_join = dlsym(RTLD_NEXT, "pmpi_comm_join_");
  _LOCAL_MPI_Comm_set_info = dlsym(RTLD_NEXT, "pmpi_comm_set_info_");
  _LOCAL_MPI_Comm_get_info = dlsym(RTLD_NEXT, "pmpi_comm_get_info_");
  _LOCAL_MPI_Accumulate = dlsym(RTLD_NEXT, "pmpi_accumulate_");
  _LOCAL_MPI_Get = dlsym(RTLD_NEXT, "pmpi_get_");
  _LOCAL_MPI_Put = dlsym(RTLD_NEXT, "pmpi_put_");
  _LOCAL_MPI_Win_complete = dlsym(RTLD_NEXT, "pmpi_win_complete_");
  _LOCAL_MPI_Win_create = dlsym(RTLD_NEXT, "pmpi_win_create_");
  _LOCAL_MPI_Win_fence = dlsym(RTLD_NEXT, "pmpi_win_fence_");
  _LOCAL_MPI_Win_free = dlsym(RTLD_NEXT, "pmpi_win_free_");
  _LOCAL_MPI_Win_get_group = dlsym(RTLD_NEXT, "pmpi_win_get_group_");
  _LOCAL_MPI_Win_lock = dlsym(RTLD_NEXT, "pmpi_win_lock_");
  _LOCAL_MPI_Win_post = dlsym(RTLD_NEXT, "pmpi_win_post_");
  _LOCAL_MPI_Win_start = dlsym(RTLD_NEXT, "pmpi_win_start_");
  _LOCAL_MPI_Win_test = dlsym(RTLD_NEXT, "pmpi_win_test_");
  _LOCAL_MPI_Win_unlock = dlsym(RTLD_NEXT, "pmpi_win_unlock_");
  _LOCAL_MPI_Win_wait = dlsym(RTLD_NEXT, "pmpi_win_wait_");
  _LOCAL_MPI_Win_allocate = dlsym(RTLD_NEXT, "pmpi_win_allocate_");
  _LOCAL_MPI_Win_allocate_shared =
      dlsym(RTLD_NEXT, "pmpi_win_allocate_shared_");
  _LOCAL_MPI_Win_shared_query = dlsym(RTLD_NEXT, "pmpi_win_shared_query_");
  _LOCAL_MPI_Win_create_dynamic = dlsym(RTLD_NEXT, "pmpi_win_create_dynamic_");
  _LOCAL_MPI_Win_attach = dlsym(RTLD_NEXT, "pmpi_win_attach_");
  _LOCAL_MPI_Win_detach = dlsym(RTLD_NEXT, "pmpi_win_detach_");
  _LOCAL_MPI_Win_get_info = dlsym(RTLD_NEXT, "pmpi_win_get_info_");
  _LOCAL_MPI_Win_set_info = dlsym(RTLD_NEXT, "pmpi_win_set_info_");
  _LOCAL_MPI_Get_accumulate = dlsym(RTLD_NEXT, "pmpi_get_accumulate_");
  _LOCAL_MPI_Fetch_and_op = dlsym(RTLD_NEXT, "pmpi_fetch_and_op_");
  _LOCAL_MPI_Compare_and_swap = dlsym(RTLD_NEXT, "pmpi_compare_and_swap_");
  _LOCAL_MPI_Rput = dlsym(RTLD_NEXT, "pmpi_rput_");
  _LOCAL_MPI_Rget = dlsym(RTLD_NEXT, "pmpi_rget_");
  _LOCAL_MPI_Raccumulate = dlsym(RTLD_NEXT, "pmpi_raccumulate_");
  _LOCAL_MPI_Rget_accumulate = dlsym(RTLD_NEXT, "pmpi_rget_accumulate_");
  _LOCAL_MPI_Win_lock_all = dlsym(RTLD_NEXT, "pmpi_win_lock_all_");
  _LOCAL_MPI_Win_unlock_all = dlsym(RTLD_NEXT, "pmpi_win_unlock_all_");
  _LOCAL_MPI_Win_flush = dlsym(RTLD_NEXT, "pmpi_win_flush_");
  _LOCAL_MPI_Win_flush_all = dlsym(RTLD_NEXT, "pmpi_win_flush_all_");
  _LOCAL_MPI_Win_flush_local = dlsym(RTLD_NEXT, "pmpi_win_flush_local_");
  _LOCAL_MPI_Win_flush_local_all =
      dlsym(RTLD_NEXT, "pmpi_win_flush_local_all_");
  _LOCAL_MPI_Win_sync = dlsym(RTLD_NEXT, "pmpi_win_sync_");
  _LOCAL_MPI_Add_error_class = dlsym(RTLD_NEXT, "pmpi_add_error_class_");
  _LOCAL_MPI_Add_error_code = dlsym(RTLD_NEXT, "pmpi_add_error_code_");
  _LOCAL_MPI_Comm_call_errhandler =
      dlsym(RTLD_NEXT, "pmpi_comm_call_errhandler_");
  _LOCAL_MPI_Comm_delete_attr = dlsym(RTLD_NEXT, "pmpi_comm_delete_attr_");
  _LOCAL_MPI_Comm_get_attr = dlsym(RTLD_NEXT, "pmpi_comm_get_attr_");
  _LOCAL_MPI_Comm_set_attr = dlsym(RTLD_NEXT, "pmpi_comm_set_attr_");
  _LOCAL_MPI_Init_thread = dlsym(RTLD_NEXT, "pmpi_init_thread_");
  _LOCAL_MPI_Is_thread_main = dlsym(RTLD_NEXT, "pmpi_is_thread_main_");
  _LOCAL_MPI_Query_thread = dlsym(RTLD_NEXT, "pmpi_query_thread_");
  _LOCAL_MPI_Status_set_cancelled =
      dlsym(RTLD_NEXT, "pmpi_status_set_cancelled_");
  _LOCAL_MPI_Status_set_elements =
      dlsym(RTLD_NEXT, "pmpi_status_set_elements_");
  _LOCAL_MPI_Type_delete_attr = dlsym(RTLD_NEXT, "pmpi_type_delete_attr_");
  _LOCAL_MPI_Type_dup = dlsym(RTLD_NEXT, "pmpi_type_dup_");
  _LOCAL_MPI_Type_free_keyval = dlsym(RTLD_NEXT, "pmpi_type_free_keyval_");
  _LOCAL_MPI_Type_get_attr = dlsym(RTLD_NEXT, "pmpi_type_get_attr_");
  _LOCAL_MPI_Type_get_envelope = dlsym(RTLD_NEXT, "pmpi_type_get_envelope_");
  _LOCAL_MPI_Type_set_attr = dlsym(RTLD_NEXT, "pmpi_type_set_attr_");
  _LOCAL_MPI_Type_match_size = dlsym(RTLD_NEXT, "pmpi_type_match_size_");
  _LOCAL_MPI_Alloc_mem = dlsym(RTLD_NEXT, "pmpi_alloc_mem_");
  _LOCAL_MPI_Comm_create_errhandler =
      dlsym(RTLD_NEXT, "pmpi_comm_create_errhandler_");
  _LOCAL_MPI_Comm_get_errhandler =
      dlsym(RTLD_NEXT, "pmpi_comm_get_errhandler_");
  _LOCAL_MPI_Comm_set_errhandler =
      dlsym(RTLD_NEXT, "pmpi_comm_set_errhandler_");
  _LOCAL_MPI_File_get_errhandler =
      dlsym(RTLD_NEXT, "pmpi_file_get_errhandler_");
  _LOCAL_MPI_File_set_errhandler =
      dlsym(RTLD_NEXT, "pmpi_file_set_errhandler_");
  _LOCAL_MPI_Finalized = dlsym(RTLD_NEXT, "pmpi_finalized_");
  _LOCAL_MPI_Free_mem = dlsym(RTLD_NEXT, "pmpi_free_mem_");
  _LOCAL_MPI_Get_address = dlsym(RTLD_NEXT, "pmpi_get_address_");
  _LOCAL_MPI_Info_create = dlsym(RTLD_NEXT, "pmpi_info_create_");
  _LOCAL_MPI_Info_dup = dlsym(RTLD_NEXT, "pmpi_info_dup_");
  _LOCAL_MPI_Info_free = dlsym(RTLD_NEXT, "pmpi_info_free_");
  _LOCAL_MPI_Info_get_nkeys = dlsym(RTLD_NEXT, "pmpi_info_get_nkeys_");
  _LOCAL_MPI_Request_get_status = dlsym(RTLD_NEXT, "pmpi_request_get_status_");
  _LOCAL_MPI_Type_create_hvector =
      dlsym(RTLD_NEXT, "pmpi_type_create_hvector_");
  _LOCAL_MPI_Type_create_resized =
      dlsym(RTLD_NEXT, "pmpi_type_create_resized_");
  _LOCAL_MPI_Type_get_extent = dlsym(RTLD_NEXT, "pmpi_type_get_extent_");
  _LOCAL_MPI_Type_get_true_extent =
      dlsym(RTLD_NEXT, "pmpi_type_get_true_extent_");
  _LOCAL_MPI_Type_create_f90_integer =
      dlsym(RTLD_NEXT, "pmpi_type_create_f90_integer_");
  _LOCAL_MPI_Type_create_f90_real =
      dlsym(RTLD_NEXT, "pmpi_type_create_f90_real_");
  _LOCAL_MPI_Type_create_f90_complex =
      dlsym(RTLD_NEXT, "pmpi_type_create_f90_complex_");
  _LOCAL_MPI_Reduce_local = dlsym(RTLD_NEXT, "pmpi_reduce_local_");
  _LOCAL_MPI_Op_commutative = dlsym(RTLD_NEXT, "pmpi_op_commutative_");
  _LOCAL_MPI_Reduce_scatter_block =
      dlsym(RTLD_NEXT, "pmpi_reduce_scatter_block_");
  _LOCAL_MPI_Dist_graph_neighbors_count =
      dlsym(RTLD_NEXT, "pmpi_dist_graph_neighbors_count_");
  _LOCAL_MPI_Improbe = dlsym(RTLD_NEXT, "pmpi_improbe_");
  _LOCAL_MPI_Imrecv = dlsym(RTLD_NEXT, "pmpi_imrecv_");
  _LOCAL_MPI_Mprobe = dlsym(RTLD_NEXT, "pmpi_mprobe_");
  _LOCAL_MPI_Mrecv = dlsym(RTLD_NEXT, "pmpi_mrecv_");
  _LOCAL_MPI_Comm_idup = dlsym(RTLD_NEXT, "pmpi_comm_idup_");
  _LOCAL_MPI_Ibarrier = dlsym(RTLD_NEXT, "pmpi_ibarrier_");
  _LOCAL_MPI_Ibcast = dlsym(RTLD_NEXT, "pmpi_ibcast_");
  _LOCAL_MPI_Igather = dlsym(RTLD_NEXT, "pmpi_igather_");
  _LOCAL_MPI_Iscatter = dlsym(RTLD_NEXT, "pmpi_iscatter_");
  _LOCAL_MPI_Iallgather = dlsym(RTLD_NEXT, "pmpi_iallgather_");
  _LOCAL_MPI_Ialltoall = dlsym(RTLD_NEXT, "pmpi_ialltoall_");
  _LOCAL_MPI_Ireduce = dlsym(RTLD_NEXT, "pmpi_ireduce_");
  _LOCAL_MPI_Iallreduce = dlsym(RTLD_NEXT, "pmpi_iallreduce_");
  _LOCAL_MPI_Ireduce_scatter_block =
      dlsym(RTLD_NEXT, "pmpi_ireduce_scatter_block_");
  _LOCAL_MPI_Iscan = dlsym(RTLD_NEXT, "pmpi_iscan_");
  _LOCAL_MPI_Iexscan = dlsym(RTLD_NEXT, "pmpi_iexscan_");
  _LOCAL_MPI_Ineighbor_allgather =
      dlsym(RTLD_NEXT, "pmpi_ineighbor_allgather_");
  _LOCAL_MPI_Ineighbor_alltoall = dlsym(RTLD_NEXT, "pmpi_ineighbor_alltoall_");
  _LOCAL_MPI_Neighbor_allgather = dlsym(RTLD_NEXT, "pmpi_neighbor_allgather_");
  _LOCAL_MPI_Neighbor_alltoall = dlsym(RTLD_NEXT, "pmpi_neighbor_alltoall_");
  _LOCAL_MPI_Comm_split_type = dlsym(RTLD_NEXT, "pmpi_comm_split_type_");
  _LOCAL_MPI_Get_elements_x = dlsym(RTLD_NEXT, "pmpi_get_elements_x_");
  _LOCAL_MPI_Status_set_elements_x =
      dlsym(RTLD_NEXT, "pmpi_status_set_elements_x_");
  _LOCAL_MPI_Type_get_extent_x = dlsym(RTLD_NEXT, "pmpi_type_get_extent_x_");
  _LOCAL_MPI_Type_get_true_extent_x =
      dlsym(RTLD_NEXT, "pmpi_type_get_true_extent_x_");
  _LOCAL_MPI_Type_size_x = dlsym(RTLD_NEXT, "pmpi_type_size_x_");
  _LOCAL_MPI_Comm_create_group = dlsym(RTLD_NEXT, "pmpi_comm_create_group_");
  _LOCAL_MPI_File_close = dlsym(RTLD_NEXT, "pmpi_file_close_");
  _LOCAL_MPI_File_set_size = dlsym(RTLD_NEXT, "pmpi_file_set_size_");
  _LOCAL_MPI_File_preallocate = dlsym(RTLD_NEXT, "pmpi_file_preallocate_");
  _LOCAL_MPI_File_get_size = dlsym(RTLD_NEXT, "pmpi_file_get_size_");
  _LOCAL_MPI_File_get_group = dlsym(RTLD_NEXT, "pmpi_file_get_group_");
  _LOCAL_MPI_File_get_amode = dlsym(RTLD_NEXT, "pmpi_file_get_amode_");
  _LOCAL_MPI_File_set_info = dlsym(RTLD_NEXT, "pmpi_file_set_info_");
  _LOCAL_MPI_File_get_info = dlsym(RTLD_NEXT, "pmpi_file_get_info_");
  _LOCAL_MPI_File_read_at = dlsym(RTLD_NEXT, "pmpi_file_read_at_");
  _LOCAL_MPI_File_read_at_all = dlsym(RTLD_NEXT, "pmpi_file_read_at_all_");
  _LOCAL_MPI_File_write_at = dlsym(RTLD_NEXT, "pmpi_file_write_at_");
  _LOCAL_MPI_File_write_at_all = dlsym(RTLD_NEXT, "pmpi_file_write_at_all_");
  _LOCAL_MPI_File_iread_at = dlsym(RTLD_NEXT, "pmpi_file_iread_at_");
  _LOCAL_MPI_File_iwrite_at = dlsym(RTLD_NEXT, "pmpi_file_iwrite_at_");
  _LOCAL_MPI_File_read = dlsym(RTLD_NEXT, "pmpi_file_read_");
  _LOCAL_MPI_File_read_all = dlsym(RTLD_NEXT, "pmpi_file_read_all_");
  _LOCAL_MPI_File_write = dlsym(RTLD_NEXT, "pmpi_file_write_");
  _LOCAL_MPI_File_write_all = dlsym(RTLD_NEXT, "pmpi_file_write_all_");
  _LOCAL_MPI_File_iread = dlsym(RTLD_NEXT, "pmpi_file_iread_");
  _LOCAL_MPI_File_iwrite = dlsym(RTLD_NEXT, "pmpi_file_iwrite_");
  _LOCAL_MPI_File_seek = dlsym(RTLD_NEXT, "pmpi_file_seek_");
  _LOCAL_MPI_File_get_position = dlsym(RTLD_NEXT, "pmpi_file_get_position_");
  _LOCAL_MPI_File_get_byte_offset =
      dlsym(RTLD_NEXT, "pmpi_file_get_byte_offset_");
  _LOCAL_MPI_File_read_shared = dlsym(RTLD_NEXT, "pmpi_file_read_shared_");
  _LOCAL_MPI_File_write_shared = dlsym(RTLD_NEXT, "pmpi_file_write_shared_");
  _LOCAL_MPI_File_iread_shared = dlsym(RTLD_NEXT, "pmpi_file_iread_shared_");
  _LOCAL_MPI_File_iwrite_shared = dlsym(RTLD_NEXT, "pmpi_file_iwrite_shared_");
  _LOCAL_MPI_File_read_ordered = dlsym(RTLD_NEXT, "pmpi_file_read_ordered_");
  _LOCAL_MPI_File_write_ordered = dlsym(RTLD_NEXT, "pmpi_file_write_ordered_");
  _LOCAL_MPI_File_seek_shared = dlsym(RTLD_NEXT, "pmpi_file_seek_shared_");
  _LOCAL_MPI_File_get_position_shared =
      dlsym(RTLD_NEXT, "pmpi_file_get_position_shared_");
  _LOCAL_MPI_File_read_at_all_begin =
      dlsym(RTLD_NEXT, "pmpi_file_read_at_all_begin_");
  _LOCAL_MPI_File_read_at_all_end =
      dlsym(RTLD_NEXT, "pmpi_file_read_at_all_end_");
  _LOCAL_MPI_File_write_at_all_begin =
      dlsym(RTLD_NEXT, "pmpi_file_write_at_all_begin_");
  _LOCAL_MPI_File_write_at_all_end =
      dlsym(RTLD_NEXT, "pmpi_file_write_at_all_end_");
  _LOCAL_MPI_File_read_all_begin =
      dlsym(RTLD_NEXT, "pmpi_file_read_all_begin_");
  _LOCAL_MPI_File_read_all_end = dlsym(RTLD_NEXT, "pmpi_file_read_all_end_");
  _LOCAL_MPI_File_write_all_begin =
      dlsym(RTLD_NEXT, "pmpi_file_write_all_begin_");
  _LOCAL_MPI_File_write_all_end = dlsym(RTLD_NEXT, "pmpi_file_write_all_end_");
  _LOCAL_MPI_File_read_ordered_begin =
      dlsym(RTLD_NEXT, "pmpi_file_read_ordered_begin_");
  _LOCAL_MPI_File_read_ordered_end =
      dlsym(RTLD_NEXT, "pmpi_file_read_ordered_end_");
  _LOCAL_MPI_File_write_ordered_begin =
      dlsym(RTLD_NEXT, "pmpi_file_write_ordered_begin_");
  _LOCAL_MPI_File_write_ordered_end =
      dlsym(RTLD_NEXT, "pmpi_file_write_ordered_end_");
  _LOCAL_MPI_File_get_type_extent =
      dlsym(RTLD_NEXT, "pmpi_file_get_type_extent_");
  _LOCAL_MPI_File_set_atomicity = dlsym(RTLD_NEXT, "pmpi_file_set_atomicity_");
  _LOCAL_MPI_File_get_atomicity = dlsym(RTLD_NEXT, "pmpi_file_get_atomicity_");
  _LOCAL_MPI_File_sync = dlsym(RTLD_NEXT, "pmpi_file_sync_");
  _LOCAL_MPI_Wtime = dlsym(RTLD_NEXT, "pmpi_wtime_");
  _LOCAL_MPI_Wtick = dlsym(RTLD_NEXT, "pmpi_wtick_");
  _LOCAL_MPI_Finalize = dlsym(RTLD_NEXT, "pmpi_finalize_");
  _LOCAL_MPI_Waitany = dlsym(RTLD_NEXT, "pmpi_waitany_");
  _LOCAL_MPI_Testany = dlsym(RTLD_NEXT, "pmpi_testany_");
  _LOCAL_MPI_Waitall = dlsym(RTLD_NEXT, "pmpi_waitall_");
  _LOCAL_MPI_Testall = dlsym(RTLD_NEXT, "pmpi_testall_");
  _LOCAL_MPI_Waitsome = dlsym(RTLD_NEXT, "pmpi_waitsome_");
  _LOCAL_MPI_Testsome = dlsym(RTLD_NEXT, "pmpi_testsome_");
  _LOCAL_MPI_Startall = dlsym(RTLD_NEXT, "pmpi_startall_");
  _LOCAL_MPI_Alltoallw = dlsym(RTLD_NEXT, "pmpi_alltoallw_");
  _LOCAL_MPI_Reduce_scatter = dlsym(RTLD_NEXT, "pmpi_reduce_scatter_");
  _LOCAL_MPI_Group_translate_ranks =
      dlsym(RTLD_NEXT, "pmpi_group_translate_ranks_");
  _LOCAL_MPI_Group_incl = dlsym(RTLD_NEXT, "pmpi_group_incl_");
  _LOCAL_MPI_Group_excl = dlsym(RTLD_NEXT, "pmpi_group_excl_");
  _LOCAL_MPI_Group_range_incl = dlsym(RTLD_NEXT, "pmpi_group_range_incl_");
  _LOCAL_MPI_Group_range_excl = dlsym(RTLD_NEXT, "pmpi_group_range_excl_");
  _LOCAL_MPI_Cart_create = dlsym(RTLD_NEXT, "pmpi_cart_create_");
  _LOCAL_MPI_Dims_create = dlsym(RTLD_NEXT, "pmpi_dims_create_");
  _LOCAL_MPI_Graph_create = dlsym(RTLD_NEXT, "pmpi_graph_create_");
  _LOCAL_MPI_Graph_get = dlsym(RTLD_NEXT, "pmpi_graph_get_");
  _LOCAL_MPI_Cart_get = dlsym(RTLD_NEXT, "pmpi_cart_get_");
  _LOCAL_MPI_Cart_rank = dlsym(RTLD_NEXT, "pmpi_cart_rank_");
  _LOCAL_MPI_Cart_coords = dlsym(RTLD_NEXT, "pmpi_cart_coords_");
  _LOCAL_MPI_Graph_neighbors = dlsym(RTLD_NEXT, "pmpi_graph_neighbors_");
  _LOCAL_MPI_Cart_sub = dlsym(RTLD_NEXT, "pmpi_cart_sub_");
  _LOCAL_MPI_Cart_map = dlsym(RTLD_NEXT, "pmpi_cart_map_");
  _LOCAL_MPI_Graph_map = dlsym(RTLD_NEXT, "pmpi_graph_map_");
  _LOCAL_MPI_Type_get_contents = dlsym(RTLD_NEXT, "pmpi_type_get_contents_");
  _LOCAL_MPI_Type_create_darray = dlsym(RTLD_NEXT, "pmpi_type_create_darray_");
  _LOCAL_MPI_Type_create_hindexed =
      dlsym(RTLD_NEXT, "pmpi_type_create_hindexed_");
  _LOCAL_MPI_Type_create_indexed_block =
      dlsym(RTLD_NEXT, "pmpi_type_create_indexed_block_");
  _LOCAL_MPI_Type_create_hindexed_block =
      dlsym(RTLD_NEXT, "pmpi_type_create_hindexed_block_");
  _LOCAL_MPI_Type_create_struct = dlsym(RTLD_NEXT, "pmpi_type_create_struct_");
  _LOCAL_MPI_Type_create_subarray =
      dlsym(RTLD_NEXT, "pmpi_type_create_subarray_");
  _LOCAL_MPI_Dist_graph_create_adjacent =
      dlsym(RTLD_NEXT, "pmpi_dist_graph_create_adjacent_");
  _LOCAL_MPI_Dist_graph_create = dlsym(RTLD_NEXT, "pmpi_dist_graph_create_");
  _LOCAL_MPI_Dist_graph_neighbors =
      dlsym(RTLD_NEXT, "pmpi_dist_graph_neighbors_");
  _LOCAL_MPI_Igatherv = dlsym(RTLD_NEXT, "pmpi_igatherv_");
  _LOCAL_MPI_Iscatterv = dlsym(RTLD_NEXT, "pmpi_iscatterv_");
  _LOCAL_MPI_Iallgatherv = dlsym(RTLD_NEXT, "pmpi_iallgatherv_");
  _LOCAL_MPI_Ialltoallv = dlsym(RTLD_NEXT, "pmpi_ialltoallv_");
  _LOCAL_MPI_Ialltoallw = dlsym(RTLD_NEXT, "pmpi_ialltoallw_");
  _LOCAL_MPI_Ireduce_scatter = dlsym(RTLD_NEXT, "pmpi_ireduce_scatter_");
  _LOCAL_MPI_Ineighbor_allgatherv =
      dlsym(RTLD_NEXT, "pmpi_ineighbor_allgatherv_");
  _LOCAL_MPI_Ineighbor_alltoallv =
      dlsym(RTLD_NEXT, "pmpi_ineighbor_alltoallv_");
  _LOCAL_MPI_Ineighbor_alltoallw =
      dlsym(RTLD_NEXT, "pmpi_ineighbor_alltoallw_");
  _LOCAL_MPI_Neighbor_allgatherv =
      dlsym(RTLD_NEXT, "pmpi_neighbor_allgatherv_");
  _LOCAL_MPI_Neighbor_alltoallv = dlsym(RTLD_NEXT, "pmpi_neighbor_alltoallv_");
  _LOCAL_MPI_Neighbor_alltoallw = dlsym(RTLD_NEXT, "pmpi_neighbor_alltoallw_");
  _LOCAL_MPI_File_iwrite_all = dlsym(RTLD_NEXT, "pmpi_file_iwrite_all_");
  _LOCAL_MPI_File_iwrite_at_all = dlsym(RTLD_NEXT, "pmpi_file_iwrite_at_all_");
  _LOCAL_MPI_Aint_add = dlsym(RTLD_NEXT, "pmpi_aint_add_");
  _LOCAL_MPI_Aint_diff = dlsym(RTLD_NEXT, "pmpi_aint_diff_");
  _LOCAL_MPI_File_iread_all = dlsym(RTLD_NEXT, "pmpi_file_iread_all_");
  _LOCAL_MPI_File_iread_at_all = dlsym(RTLD_NEXT, "pmpi_file_iread_at_all_");
  _LOCAL_MPI_Error_string = dlsym(RTLD_NEXT, "pmpi_error_string_");
  _LOCAL_MPI_Get_processor_name = dlsym(RTLD_NEXT, "pmpi_get_processor_name_");
  _LOCAL_MPI_File_open = dlsym(RTLD_NEXT, "pmpi_file_open_");
  _LOCAL_MPI_File_set_view = dlsym(RTLD_NEXT, "pmpi_file_set_view_");
  _LOCAL_MPI_File_get_view = dlsym(RTLD_NEXT, "pmpi_file_get_view_");
  _LOCAL_MPI_File_delete = dlsym(RTLD_NEXT, "pmpi_file_delete_");
  _LOCAL_MPI_Info_delete = dlsym(RTLD_NEXT, "pmpi_info_delete_");
  _LOCAL_MPI_Info_get = dlsym(RTLD_NEXT, "pmpi_info_get_");
  _LOCAL_MPI_Info_get_nthkey = dlsym(RTLD_NEXT, "pmpi_info_get_nthkey_");
  _LOCAL_MPI_Info_get_valuelen = dlsym(RTLD_NEXT, "pmpi_info_get_valuelen_");
  _LOCAL_MPI_Info_set = dlsym(RTLD_NEXT, "pmpi_info_set_");
  _LOCAL_MPI_Win_get_name = dlsym(RTLD_NEXT, "pmpi_win_get_name_");
  _LOCAL_MPI_Win_set_name = dlsym(RTLD_NEXT, "pmpi_win_set_name_");
  _LOCAL_MPI_Comm_get_name = dlsym(RTLD_NEXT, "pmpi_comm_get_name_");
  _LOCAL_MPI_Comm_set_name = dlsym(RTLD_NEXT, "pmpi_comm_set_name_");
  _LOCAL_MPI_Comm_spawn = dlsym(RTLD_NEXT, "pmpi_comm_spawn_");
  _LOCAL_MPI_Type_get_name = dlsym(RTLD_NEXT, "pmpi_type_get_name_");
  _LOCAL_MPI_Type_set_name = dlsym(RTLD_NEXT, "pmpi_type_set_name_");
  _LOCAL_MPI_Add_error_string = dlsym(RTLD_NEXT, "pmpi_add_error_string_");
  _LOCAL_MPI_Close_port = dlsym(RTLD_NEXT, "pmpi_close_port_");
  _LOCAL_MPI_Get_library_version =
      dlsym(RTLD_NEXT, "pmpi_get_library_version_");
  _LOCAL_MPI_Open_port = dlsym(RTLD_NEXT, "pmpi_open_port_");
  _LOCAL_MPI_Publish_name = dlsym(RTLD_NEXT, "pmpi_publish_name_");
  _LOCAL_MPI_Unpublish_name = dlsym(RTLD_NEXT, "pmpi_unpublish_name_");
  _LOCAL_MPI_Lookup_name = dlsym(RTLD_NEXT, "pmpi_lookup_name_");
  _LOCAL_MPI_Pack_external = dlsym(RTLD_NEXT, "pmpi_pack_external_");
  _LOCAL_MPI_Pack_external_size = dlsym(RTLD_NEXT, "pmpi_pack_external_size_");
  _LOCAL_MPI_Unpack_external = dlsym(RTLD_NEXT, "pmpi_unpack_external_");
}

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
#include "helper.h"
#include "mappers.h"
#include "run_mpi.h"
#define debug_printer debug_printer_f
void debug_printer(const char *, ...);
#include "wrapper_f.h"
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
typedef void(A_F_MPI_Copy_function)(int *, int *, void *, void *, void *, int *,
                                    int *);
typedef void(A_F_MPI_Delete_function)(int *, int *, void *, void *, int *);
typedef struct {
  A_F_MPI_Copy_function *cp_function;
  A_F_MPI_Delete_function *del_function;
  int ref;
} myKeyval_functions_t;
extern myKeyval_functions_t *myKeyval_translation_get(int);
extern void myKeyval_translation_del(int);
extern void myKeyval_translation_add(int, myKeyval_functions_t *);
#if defined(OMPI_INTEL) || defined(_INTEL) || defined(_MPC)
int *MPI_UNWEIGHTED = NULL;
#endif
extern __thread int in_w;
void mpi_send_(void *, int *, int *, int *, int *, int *, int *);

void mpi_send__(void *, int *, int *, int *, int *, int *, int *);

void pmpi_send_(void *, int *, int *, int *, int *, int *, int *);

void pmpi_send__(void *, int *, int *, int *, int *, int *, int *);

void pmpi_send_(void *, int *, int *, int *, int *, int *, int *);

extern unsigned long long WI4MPI_Send_timeout;
extern unsigned int WI4MPI_Send_print;
void (*_LOCAL_MPI_Send)(void *, int *, int *, int *, int *, int *, int *);

void A_f_MPI_Send(void *buf, int *count, int *datatype, int *dest, int *tag,
                  int *comm, int *ret) {
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
  if (WI4MPI_Send_print)
    debug_printer("MPI_Send : \n{\nbuf : %*d,\ncount : %*d,\ndatatype : "
                  "%*d,\ndest : %*d,\ntag : %*d,\ncomm : %*d,\nerror/return : "
                  "%*d\n}\n",
                  buf, count, datatype, dest, tag, comm, ret_tmp);
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

extern unsigned long long WI4MPI_Recv_timeout;
extern unsigned int WI4MPI_Recv_print;
void (*_LOCAL_MPI_Recv)(void *, int *, int *, int *, int *, int *, int *,
                        int *);

void A_f_MPI_Recv(void *buf, int *count, int *datatype, int *source, int *tag,
                  int *comm, int *status, int *ret) {
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
  if (WI4MPI_Recv_print)
    debug_printer("MPI_Recv : \n{\nbuf : %*d,\ncount : %*d,\ndatatype : "
                  "%*d,\nsource : %*d,\ntag : %*d,\ncomm : %*d,\nstatus : "
                  "%S,\nerror/return : %*d\n}\n",
                  buf, count, datatype, source, tag, comm, status, ret_tmp);
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

extern unsigned long long WI4MPI_Get_count_timeout;
extern unsigned int WI4MPI_Get_count_print;
void (*_LOCAL_MPI_Get_count)(int *, int *, int *, int *);

void A_f_MPI_Get_count(int *status, int *datatype, int *count, int *ret) {
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
  if (WI4MPI_Get_count_print)
    debug_printer("MPI_Get_count : \n{\nstatus : %S,\ndatatype : %*d,\ncount : "
                  "%*d,\nerror/return : %*d\n}\n",
                  status, datatype, count, ret_tmp);
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

extern unsigned long long WI4MPI_Bsend_timeout;
extern unsigned int WI4MPI_Bsend_print;
void (*_LOCAL_MPI_Bsend)(void *, int *, int *, int *, int *, int *, int *);

void A_f_MPI_Bsend(void *buf, int *count, int *datatype, int *dest, int *tag,
                   int *comm, int *ret) {
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
  if (WI4MPI_Bsend_print)
    debug_printer("MPI_Bsend : \n{\nbuf : %*d,\ncount : %*d,\ndatatype : "
                  "%*d,\ndest : %*d,\ntag : %*d,\ncomm : %*d,\nerror/return : "
                  "%*d\n}\n",
                  buf, count, datatype, dest, tag, comm, ret_tmp);
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

extern unsigned long long WI4MPI_Ssend_timeout;
extern unsigned int WI4MPI_Ssend_print;
void (*_LOCAL_MPI_Ssend)(void *, int *, int *, int *, int *, int *, int *);

void A_f_MPI_Ssend(void *buf, int *count, int *datatype, int *dest, int *tag,
                   int *comm, int *ret) {
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
  if (WI4MPI_Ssend_print)
    debug_printer("MPI_Ssend : \n{\nbuf : %*d,\ncount : %*d,\ndatatype : "
                  "%*d,\ndest : %*d,\ntag : %*d,\ncomm : %*d,\nerror/return : "
                  "%*d\n}\n",
                  buf, count, datatype, dest, tag, comm, ret_tmp);
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

extern unsigned long long WI4MPI_Rsend_timeout;
extern unsigned int WI4MPI_Rsend_print;
void (*_LOCAL_MPI_Rsend)(void *, int *, int *, int *, int *, int *, int *);

void A_f_MPI_Rsend(void *buf, int *count, int *datatype, int *dest, int *tag,
                   int *comm, int *ret) {
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
  if (WI4MPI_Rsend_print)
    debug_printer("MPI_Rsend : \n{\nbuf : %*d,\ncount : %*d,\ndatatype : "
                  "%*d,\ndest : %*d,\ntag : %*d,\ncomm : %*d,\nerror/return : "
                  "%*d\n}\n",
                  buf, count, datatype, dest, tag, comm, ret_tmp);
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

extern unsigned long long WI4MPI_Buffer_attach_timeout;
extern unsigned int WI4MPI_Buffer_attach_print;
void (*_LOCAL_MPI_Buffer_attach)(void *, int *, int *);

void A_f_MPI_Buffer_attach(void *buffer, int *size, int *ret) {
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
  if (WI4MPI_Buffer_attach_print)
    debug_printer("MPI_Buffer_attach : \n{\nbuffer : %*d,\nsize : "
                  "%*d,\nerror/return : %*d\n}\n",
                  buffer, size, ret_tmp);
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

extern unsigned long long WI4MPI_Buffer_detach_timeout;
extern unsigned int WI4MPI_Buffer_detach_print;
void (*_LOCAL_MPI_Buffer_detach)(void *, int *, int *);

void A_f_MPI_Buffer_detach(void *buffer_addr, int *size, int *ret) {
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
  if (WI4MPI_Buffer_detach_print)
    debug_printer("MPI_Buffer_detach : \n{\nbuffer_addr : %*d,\nsize : "
                  "%*d,\nerror/return : %*d\n}\n",
                  buffer_addr, size, ret_tmp);
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

extern unsigned long long WI4MPI_Isend_timeout;
extern unsigned int WI4MPI_Isend_print;
void (*_LOCAL_MPI_Isend)(void *, int *, int *, int *, int *, int *, int *,
                         int *);

void A_f_MPI_Isend(void *buf, int *count, int *datatype, int *dest, int *tag,
                   int *comm, int *request, int *ret) {
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
  if (WI4MPI_Isend_print)
    debug_printer("MPI_Isend : \n{\nbuf : %*d,\ncount : %*d,\ndatatype : "
                  "%*d,\ndest : %*d,\ntag : %*d,\ncomm : %*d,\nrequest : "
                  "%*d,\nerror/return : %*d\n}\n",
                  buf, count, datatype, dest, tag, comm, request, ret_tmp);
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

extern unsigned long long WI4MPI_Ibsend_timeout;
extern unsigned int WI4MPI_Ibsend_print;
void (*_LOCAL_MPI_Ibsend)(void *, int *, int *, int *, int *, int *, int *,
                          int *);

void A_f_MPI_Ibsend(void *buf, int *count, int *datatype, int *dest, int *tag,
                    int *comm, int *request, int *ret) {
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
  if (WI4MPI_Ibsend_print)
    debug_printer("MPI_Ibsend : \n{\nbuf : %*d,\ncount : %*d,\ndatatype : "
                  "%*d,\ndest : %*d,\ntag : %*d,\ncomm : %*d,\nrequest : "
                  "%*d,\nerror/return : %*d\n}\n",
                  buf, count, datatype, dest, tag, comm, request, ret_tmp);
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

extern unsigned long long WI4MPI_Issend_timeout;
extern unsigned int WI4MPI_Issend_print;
void (*_LOCAL_MPI_Issend)(void *, int *, int *, int *, int *, int *, int *,
                          int *);

void A_f_MPI_Issend(void *buf, int *count, int *datatype, int *dest, int *tag,
                    int *comm, int *request, int *ret) {
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
  if (WI4MPI_Issend_print)
    debug_printer("MPI_Issend : \n{\nbuf : %*d,\ncount : %*d,\ndatatype : "
                  "%*d,\ndest : %*d,\ntag : %*d,\ncomm : %*d,\nrequest : "
                  "%*d,\nerror/return : %*d\n}\n",
                  buf, count, datatype, dest, tag, comm, request, ret_tmp);
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

extern unsigned long long WI4MPI_Irsend_timeout;
extern unsigned int WI4MPI_Irsend_print;
void (*_LOCAL_MPI_Irsend)(void *, int *, int *, int *, int *, int *, int *,
                          int *);

void A_f_MPI_Irsend(void *buf, int *count, int *datatype, int *dest, int *tag,
                    int *comm, int *request, int *ret) {
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
  if (WI4MPI_Irsend_print)
    debug_printer("MPI_Irsend : \n{\nbuf : %*d,\ncount : %*d,\ndatatype : "
                  "%*d,\ndest : %*d,\ntag : %*d,\ncomm : %*d,\nrequest : "
                  "%*d,\nerror/return : %*d\n}\n",
                  buf, count, datatype, dest, tag, comm, request, ret_tmp);
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

extern unsigned long long WI4MPI_Irecv_timeout;
extern unsigned int WI4MPI_Irecv_print;
void (*_LOCAL_MPI_Irecv)(void *, int *, int *, int *, int *, int *, int *,
                         int *);

void A_f_MPI_Irecv(void *buf, int *count, int *datatype, int *source, int *tag,
                   int *comm, int *request, int *ret) {
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
  if (WI4MPI_Irecv_print)
    debug_printer("MPI_Irecv : \n{\nbuf : %*d,\ncount : %*d,\ndatatype : "
                  "%*d,\nsource : %*d,\ntag : %*d,\ncomm : %*d,\nrequest : "
                  "%*d,\nerror/return : %*d\n}\n",
                  buf, count, datatype, source, tag, comm, request, ret_tmp);
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

extern unsigned long long WI4MPI_Wait_timeout;
extern unsigned int WI4MPI_Wait_print;
void (*_LOCAL_MPI_Wait)(int *, int *, int *);

void A_f_MPI_Wait(int *request, int *status, int *ret) {
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
  if (WI4MPI_Wait_print)
    debug_printer(
        "MPI_Wait : \n{\nrequest : %*d,\nstatus : %S,\nerror/return : %*d\n}\n",
        request, status, ret_tmp);
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

extern unsigned long long WI4MPI_Test_timeout;
extern unsigned int WI4MPI_Test_print;
void (*_LOCAL_MPI_Test)(int *, int *, int *, int *);

void A_f_MPI_Test(int *request, int *flag, int *status, int *ret) {
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
  if (WI4MPI_Test_print)
    debug_printer("MPI_Test : \n{\nrequest : %*d,\nflag : %*d,\nstatus : "
                  "%S,\nerror/return : %*d\n}\n",
                  request, flag, status, ret_tmp);
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

extern unsigned long long WI4MPI_Request_free_timeout;
extern unsigned int WI4MPI_Request_free_print;
void (*_LOCAL_MPI_Request_free)(int *, int *);

void A_f_MPI_Request_free(int *request, int *ret) {
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
  if (WI4MPI_Request_free_print)
    debug_printer(
        "MPI_Request_free : \n{\nrequest : %*d,\nerror/return : %*d\n}\n",
        request, ret_tmp);
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

extern unsigned long long WI4MPI_Iprobe_timeout;
extern unsigned int WI4MPI_Iprobe_print;
void (*_LOCAL_MPI_Iprobe)(int *, int *, int *, int *, int *, int *);

void A_f_MPI_Iprobe(int *source, int *tag, int *comm, int *flag, int *status,
                    int *ret) {
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
  if (WI4MPI_Iprobe_print)
    debug_printer("MPI_Iprobe : \n{\nsource : %*d,\ntag : %*d,\ncomm : "
                  "%*d,\nflag : %*d,\nstatus : %S,\nerror/return : %*d\n}\n",
                  source, tag, comm, flag, status, ret_tmp);
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

extern unsigned long long WI4MPI_Probe_timeout;
extern unsigned int WI4MPI_Probe_print;
void (*_LOCAL_MPI_Probe)(int *, int *, int *, int *, int *);

void A_f_MPI_Probe(int *source, int *tag, int *comm, int *status, int *ret) {
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
  if (WI4MPI_Probe_print)
    debug_printer("MPI_Probe : \n{\nsource : %*d,\ntag : %*d,\ncomm : "
                  "%*d,\nstatus : %S,\nerror/return : %*d\n}\n",
                  source, tag, comm, status, ret_tmp);
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

extern unsigned long long WI4MPI_Cancel_timeout;
extern unsigned int WI4MPI_Cancel_print;
void (*_LOCAL_MPI_Cancel)(int *, int *);

void A_f_MPI_Cancel(int *request, int *ret) {
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
  if (WI4MPI_Cancel_print)
    debug_printer("MPI_Cancel : \n{\nrequest : %*d,\nerror/return : %*d\n}\n",
                  request, ret_tmp);
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

extern unsigned long long WI4MPI_Test_cancelled_timeout;
extern unsigned int WI4MPI_Test_cancelled_print;
void (*_LOCAL_MPI_Test_cancelled)(int *, int *, int *);

void A_f_MPI_Test_cancelled(int *status, int *flag, int *ret) {
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
  if (WI4MPI_Test_cancelled_print)
    debug_printer("MPI_Test_cancelled : \n{\nstatus : %S,\nflag : "
                  "%*d,\nerror/return : %*d\n}\n",
                  status, flag, ret_tmp);
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

extern unsigned long long WI4MPI_Send_init_timeout;
extern unsigned int WI4MPI_Send_init_print;
void (*_LOCAL_MPI_Send_init)(void *, int *, int *, int *, int *, int *, int *,
                             int *);

void A_f_MPI_Send_init(void *buf, int *count, int *datatype, int *dest,
                       int *tag, int *comm, int *request, int *ret) {
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
  if (WI4MPI_Send_init_print)
    debug_printer("MPI_Send_init : \n{\nbuf : %*d,\ncount : %*d,\ndatatype : "
                  "%*d,\ndest : %*d,\ntag : %*d,\ncomm : %*d,\nrequest : "
                  "%*d,\nerror/return : %*d\n}\n",
                  buf, count, datatype, dest, tag, comm, request, ret_tmp);
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

extern unsigned long long WI4MPI_Bsend_init_timeout;
extern unsigned int WI4MPI_Bsend_init_print;
void (*_LOCAL_MPI_Bsend_init)(void *, int *, int *, int *, int *, int *, int *,
                              int *);

void A_f_MPI_Bsend_init(void *buf, int *count, int *datatype, int *dest,
                        int *tag, int *comm, int *request, int *ret) {
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
  if (WI4MPI_Bsend_init_print)
    debug_printer("MPI_Bsend_init : \n{\nbuf : %*d,\ncount : %*d,\ndatatype : "
                  "%*d,\ndest : %*d,\ntag : %*d,\ncomm : %*d,\nrequest : "
                  "%*d,\nerror/return : %*d\n}\n",
                  buf, count, datatype, dest, tag, comm, request, ret_tmp);
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

extern unsigned long long WI4MPI_Ssend_init_timeout;
extern unsigned int WI4MPI_Ssend_init_print;
void (*_LOCAL_MPI_Ssend_init)(void *, int *, int *, int *, int *, int *, int *,
                              int *);

void A_f_MPI_Ssend_init(void *buf, int *count, int *datatype, int *dest,
                        int *tag, int *comm, int *request, int *ret) {
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
  if (WI4MPI_Ssend_init_print)
    debug_printer("MPI_Ssend_init : \n{\nbuf : %*d,\ncount : %*d,\ndatatype : "
                  "%*d,\ndest : %*d,\ntag : %*d,\ncomm : %*d,\nrequest : "
                  "%*d,\nerror/return : %*d\n}\n",
                  buf, count, datatype, dest, tag, comm, request, ret_tmp);
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

extern unsigned long long WI4MPI_Rsend_init_timeout;
extern unsigned int WI4MPI_Rsend_init_print;
void (*_LOCAL_MPI_Rsend_init)(void *, int *, int *, int *, int *, int *, int *,
                              int *);

void A_f_MPI_Rsend_init(void *buf, int *count, int *datatype, int *dest,
                        int *tag, int *comm, int *request, int *ret) {
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
  if (WI4MPI_Rsend_init_print)
    debug_printer("MPI_Rsend_init : \n{\nbuf : %*d,\ncount : %*d,\ndatatype : "
                  "%*d,\ndest : %*d,\ntag : %*d,\ncomm : %*d,\nrequest : "
                  "%*d,\nerror/return : %*d\n}\n",
                  buf, count, datatype, dest, tag, comm, request, ret_tmp);
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

extern unsigned long long WI4MPI_Recv_init_timeout;
extern unsigned int WI4MPI_Recv_init_print;
void (*_LOCAL_MPI_Recv_init)(void *, int *, int *, int *, int *, int *, int *,
                             int *);

void A_f_MPI_Recv_init(void *buf, int *count, int *datatype, int *source,
                       int *tag, int *comm, int *request, int *ret) {
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
  if (WI4MPI_Recv_init_print)
    debug_printer("MPI_Recv_init : \n{\nbuf : %*d,\ncount : %*d,\ndatatype : "
                  "%*d,\nsource : %*d,\ntag : %*d,\ncomm : %*d,\nrequest : "
                  "%*d,\nerror/return : %*d\n}\n",
                  buf, count, datatype, source, tag, comm, request, ret_tmp);
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

extern unsigned long long WI4MPI_Start_timeout;
extern unsigned int WI4MPI_Start_print;
void (*_LOCAL_MPI_Start)(int *, int *);

void A_f_MPI_Start(int *request, int *ret) {
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
  if (WI4MPI_Start_print)
    debug_printer("MPI_Start : \n{\nrequest : %*d,\nerror/return : %*d\n}\n",
                  request, ret_tmp);
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

extern unsigned long long WI4MPI_Sendrecv_timeout;
extern unsigned int WI4MPI_Sendrecv_print;
void (*_LOCAL_MPI_Sendrecv)(void *, int *, int *, int *, int *, void *, int *,
                            int *, int *, int *, int *, int *, int *);

void A_f_MPI_Sendrecv(void *sendbuf, int *sendcount, int *sendtype, int *dest,
                      int *sendtag, void *recvbuf, int *recvcount,
                      int *recvtype, int *source, int *recvtag, int *comm,
                      int *status, int *ret) {
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
  if (WI4MPI_Sendrecv_print)
    debug_printer("MPI_Sendrecv : \n{\nsendbuf : %*d,\nsendcount : "
                  "%*d,\nsendtype : %*d,\ndest : %*d,\nsendtag : %*d,\nrecvbuf "
                  ": %*d,\nrecvcount : %*d,\nrecvtype : %*d,\nsource : "
                  "%*d,\nrecvtag : %*d,\ncomm : %*d,\nstatus : "
                  "%S,\nerror/return : %*d\n}\n",
                  sendbuf, sendcount, sendtype, dest, sendtag, recvbuf,
                  recvcount, recvtype, source, recvtag, comm, status, ret_tmp);
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

extern unsigned long long WI4MPI_Sendrecv_replace_timeout;
extern unsigned int WI4MPI_Sendrecv_replace_print;
void (*_LOCAL_MPI_Sendrecv_replace)(void *, int *, int *, int *, int *, int *,
                                    int *, int *, int *, int *);

void A_f_MPI_Sendrecv_replace(void *buf, int *count, int *datatype, int *dest,
                              int *sendtag, int *source, int *recvtag,
                              int *comm, int *status, int *ret) {
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
  if (WI4MPI_Sendrecv_replace_print)
    debug_printer("MPI_Sendrecv_replace : \n{\nbuf : %*d,\ncount : "
                  "%*d,\ndatatype : %*d,\ndest : %*d,\nsendtag : %*d,\nsource "
                  ": %*d,\nrecvtag : %*d,\ncomm : %*d,\nstatus : "
                  "%S,\nerror/return : %*d\n}\n",
                  buf, count, datatype, dest, sendtag, source, recvtag, comm,
                  status, ret_tmp);
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

extern unsigned long long WI4MPI_Type_contiguous_timeout;
extern unsigned int WI4MPI_Type_contiguous_print;
void (*_LOCAL_MPI_Type_contiguous)(int *, int *, int *, int *);

void A_f_MPI_Type_contiguous(int *count, int *oldtype, int *newtype, int *ret) {
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
  if (WI4MPI_Type_contiguous_print)
    debug_printer("MPI_Type_contiguous : \n{\ncount : %*d,\noldtype : "
                  "%*d,\nnewtype : %*d,\nerror/return : %*d\n}\n",
                  count, oldtype, newtype, ret_tmp);
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

extern unsigned long long WI4MPI_Type_vector_timeout;
extern unsigned int WI4MPI_Type_vector_print;
void (*_LOCAL_MPI_Type_vector)(int *, int *, int *, int *, int *, int *);

void A_f_MPI_Type_vector(int *count, int *blocklength, int *stride,
                         int *oldtype, int *newtype, int *ret) {
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
  if (WI4MPI_Type_vector_print)
    debug_printer("MPI_Type_vector : \n{\ncount : %*d,\nblocklength : "
                  "%*d,\nstride : %*d,\noldtype : %*d,\nnewtype : "
                  "%*d,\nerror/return : %*d\n}\n",
                  count, blocklength, stride, oldtype, newtype, ret_tmp);
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

extern unsigned long long WI4MPI_Type_hvector_timeout;
extern unsigned int WI4MPI_Type_hvector_print;
void (*_LOCAL_MPI_Type_hvector)(int *, int *, size_t *, int *, int *, int *);

void A_f_MPI_Type_hvector(int *count, int *blocklength, size_t *stride,
                          int *oldtype, int *newtype, int *ret) {
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
  if (WI4MPI_Type_hvector_print)
    debug_printer("MPI_Type_hvector : \n{\ncount : %*d,\nblocklength : "
                  "%*d,\nstride : %*d,\noldtype : %*d,\nnewtype : "
                  "%*d,\nerror/return : %*d\n}\n",
                  count, blocklength, stride, oldtype, newtype, ret_tmp);
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

extern unsigned long long WI4MPI_Type_indexed_timeout;
extern unsigned int WI4MPI_Type_indexed_print;
void (*_LOCAL_MPI_Type_indexed)(int *, int *, int *, int *, int *, int *);

void A_f_MPI_Type_indexed(int *count, int *array_of_blocklengths,
                          int *array_of_displacements, int *oldtype,
                          int *newtype, int *ret) {
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
  if (WI4MPI_Type_indexed_print)
    debug_printer("MPI_Type_indexed : \n{\ncount : %*d,\narray_of_blocklengths "
                  ": %*d,\narray_of_displacements : %*d,\noldtype : "
                  "%*d,\nnewtype : %*d,\nerror/return : %*d\n}\n",
                  count, array_of_blocklengths, array_of_displacements, oldtype,
                  newtype, ret_tmp);
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

extern unsigned long long WI4MPI_Type_hindexed_timeout;
extern unsigned int WI4MPI_Type_hindexed_print;
void (*_LOCAL_MPI_Type_hindexed)(int *, int *, size_t *, int *, int *, int *);

void A_f_MPI_Type_hindexed(int *count, int *array_of_blocklengths,
                           size_t *array_of_displacements, int *oldtype,
                           int *newtype, int *ret) {
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
  if (WI4MPI_Type_hindexed_print)
    debug_printer("MPI_Type_hindexed : \n{\ncount : "
                  "%*d,\narray_of_blocklengths : %*d,\narray_of_displacements "
                  ": %*d,\noldtype : %*d,\nnewtype : %*d,\nerror/return : "
                  "%*d\n}\n",
                  count, array_of_blocklengths, array_of_displacements, oldtype,
                  newtype, ret_tmp);
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

extern unsigned long long WI4MPI_Type_struct_timeout;
extern unsigned int WI4MPI_Type_struct_print;
void (*_LOCAL_MPI_Type_struct)(int *, int *, size_t *, int *, int *, int *);

void A_f_MPI_Type_struct(int *count, int *array_of_blocklengths,
                         size_t *array_of_displacements, int *array_of_types,
                         int *newtype, int *ret) {
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
  if (WI4MPI_Type_struct_print)
    debug_printer("MPI_Type_struct : \n{\ncount : %*d,\narray_of_blocklengths "
                  ": %*d,\narray_of_displacements : %*d,\narray_of_types : "
                  "%*d,\nnewtype : %*d,\nerror/return : %*d\n}\n",
                  count, count, array_of_blocklengths, count,
                  array_of_displacements, count, array_of_types, newtype,
                  ret_tmp);
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

extern unsigned long long WI4MPI_Address_timeout;
extern unsigned int WI4MPI_Address_print;
void (*_LOCAL_MPI_Address)(void *, size_t *, int *);

void A_f_MPI_Address(void *location, size_t *address, int *ret) {
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
  if (WI4MPI_Address_print)
    debug_printer("MPI_Address : \n{\nlocation : %*d,\naddress : "
                  "%*d,\nerror/return : %*d\n}\n",
                  location, address, ret_tmp);
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

extern unsigned long long WI4MPI_Type_extent_timeout;
extern unsigned int WI4MPI_Type_extent_print;
void (*_LOCAL_MPI_Type_extent)(int *, size_t *, int *);

void A_f_MPI_Type_extent(int *datatype, size_t *extent, int *ret) {
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
  if (WI4MPI_Type_extent_print)
    debug_printer("MPI_Type_extent : \n{\ndatatype : %*d,\nextent : "
                  "%*d,\nerror/return : %*d\n}\n",
                  datatype, extent, ret_tmp);
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

extern unsigned long long WI4MPI_Type_size_timeout;
extern unsigned int WI4MPI_Type_size_print;
void (*_LOCAL_MPI_Type_size)(int *, int *, int *);

void A_f_MPI_Type_size(int *datatype, int *size, int *ret) {
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
  if (WI4MPI_Type_size_print)
    debug_printer("MPI_Type_size : \n{\ndatatype : %*d,\nsize : "
                  "%*d,\nerror/return : %*d\n}\n",
                  datatype, size, ret_tmp);
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

extern unsigned long long WI4MPI_Type_lb_timeout;
extern unsigned int WI4MPI_Type_lb_print;
void (*_LOCAL_MPI_Type_lb)(int *, size_t *, int *);

void A_f_MPI_Type_lb(int *datatype, size_t *displacement, int *ret) {
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
  if (WI4MPI_Type_lb_print)
    debug_printer("MPI_Type_lb : \n{\ndatatype : %*d,\ndisplacement : "
                  "%*d,\nerror/return : %*d\n}\n",
                  datatype, displacement, ret_tmp);
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

extern unsigned long long WI4MPI_Type_ub_timeout;
extern unsigned int WI4MPI_Type_ub_print;
void (*_LOCAL_MPI_Type_ub)(int *, size_t *, int *);

void A_f_MPI_Type_ub(int *datatype, size_t *displacement, int *ret) {
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
  if (WI4MPI_Type_ub_print)
    debug_printer("MPI_Type_ub : \n{\ndatatype : %*d,\ndisplacement : "
                  "%*d,\nerror/return : %*d\n}\n",
                  datatype, displacement, ret_tmp);
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

extern unsigned long long WI4MPI_Type_commit_timeout;
extern unsigned int WI4MPI_Type_commit_print;
void (*_LOCAL_MPI_Type_commit)(int *, int *);

void A_f_MPI_Type_commit(int *datatype, int *ret) {
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
  if (WI4MPI_Type_commit_print)
    debug_printer(
        "MPI_Type_commit : \n{\ndatatype : %*d,\nerror/return : %*d\n}\n",
        datatype, ret_tmp);
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

extern unsigned long long WI4MPI_Type_free_timeout;
extern unsigned int WI4MPI_Type_free_print;
void (*_LOCAL_MPI_Type_free)(int *, int *);

void A_f_MPI_Type_free(int *datatype, int *ret) {
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
  if (WI4MPI_Type_free_print)
    debug_printer(
        "MPI_Type_free : \n{\ndatatype : %*d,\nerror/return : %*d\n}\n",
        datatype, ret_tmp);
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

extern unsigned long long WI4MPI_Get_elements_timeout;
extern unsigned int WI4MPI_Get_elements_print;
void (*_LOCAL_MPI_Get_elements)(int *, int *, int *, int *);

void A_f_MPI_Get_elements(int *status, int *datatype, int *count, int *ret) {
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
  if (WI4MPI_Get_elements_print)
    debug_printer("MPI_Get_elements : \n{\nstatus : %S,\ndatatype : "
                  "%*d,\ncount : %*d,\nerror/return : %*d\n}\n",
                  status, datatype, count, ret_tmp);
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

extern unsigned long long WI4MPI_Pack_timeout;
extern unsigned int WI4MPI_Pack_print;
void (*_LOCAL_MPI_Pack)(void *, int *, int *, void *, int *, int *, int *,
                        int *);

void A_f_MPI_Pack(void *inbuf, int *incount, int *datatype, void *outbuf,
                  int *outsize, int *position, int *comm, int *ret) {
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
  if (WI4MPI_Pack_print)
    debug_printer("MPI_Pack : \n{\ninbuf : %*d,\nincount : %*d,\ndatatype : "
                  "%*d,\noutbuf : %*d,\noutsize : %*d,\nposition : %*d,\ncomm "
                  ": %*d,\nerror/return : %*d\n}\n",
                  inbuf, incount, datatype, outbuf, outsize, position, comm,
                  ret_tmp);
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

extern unsigned long long WI4MPI_Unpack_timeout;
extern unsigned int WI4MPI_Unpack_print;
void (*_LOCAL_MPI_Unpack)(void *, int *, int *, void *, int *, int *, int *,
                          int *);

void A_f_MPI_Unpack(void *inbuf, int *insize, int *position, void *outbuf,
                    int *outcount, int *datatype, int *comm, int *ret) {
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
  if (WI4MPI_Unpack_print)
    debug_printer("MPI_Unpack : \n{\ninbuf : %*d,\ninsize : %*d,\nposition : "
                  "%*d,\noutbuf : %*d,\noutcount : %*d,\ndatatype : %*d,\ncomm "
                  ": %*d,\nerror/return : %*d\n}\n",
                  inbuf, insize, position, outbuf, outcount, datatype, comm,
                  ret_tmp);
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

extern unsigned long long WI4MPI_Pack_size_timeout;
extern unsigned int WI4MPI_Pack_size_print;
void (*_LOCAL_MPI_Pack_size)(int *, int *, int *, int *, int *);

void A_f_MPI_Pack_size(int *incount, int *datatype, int *comm, int *size,
                       int *ret) {
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
  if (WI4MPI_Pack_size_print)
    debug_printer("MPI_Pack_size : \n{\nincount : %*d,\ndatatype : %*d,\ncomm "
                  ": %*d,\nsize : %*d,\nerror/return : %*d\n}\n",
                  incount, datatype, comm, size, ret_tmp);
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

extern unsigned long long WI4MPI_Barrier_timeout;
extern unsigned int WI4MPI_Barrier_print;
void (*_LOCAL_MPI_Barrier)(int *, int *);

void A_f_MPI_Barrier(int *comm, int *ret) {
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
  if (WI4MPI_Barrier_print)
    debug_printer("MPI_Barrier : \n{\ncomm : %*d,\nerror/return : %*d\n}\n",
                  comm, ret_tmp);
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

extern unsigned long long WI4MPI_Bcast_timeout;
extern unsigned int WI4MPI_Bcast_print;
void (*_LOCAL_MPI_Bcast)(void *, int *, int *, int *, int *, int *);

void A_f_MPI_Bcast(void *buffer, int *count, int *datatype, int *root,
                   int *comm, int *ret) {
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
  if (WI4MPI_Bcast_print)
    debug_printer("MPI_Bcast : \n{\nbuffer : %*d,\ncount : %*d,\ndatatype : "
                  "%*d,\nroot : %*d,\ncomm : %*d,\nerror/return : %*d\n}\n",
                  buffer, count, datatype, root, comm, ret_tmp);
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

extern unsigned long long WI4MPI_Gather_timeout;
extern unsigned int WI4MPI_Gather_print;
void (*_LOCAL_MPI_Gather)(void *, int *, int *, void *, int *, int *, int *,
                          int *, int *);

void A_f_MPI_Gather(void *sendbuf, int *sendcount, int *sendtype, void *recvbuf,
                    int *recvcount, int *recvtype, int *root, int *comm,
                    int *ret) {
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
  if (WI4MPI_Gather_print)
    debug_printer("MPI_Gather : \n{\nsendbuf : %*d,\nsendcount : "
                  "%*d,\nsendtype : %*d,\nrecvbuf : %*d,\nrecvcount : "
                  "%*d,\nrecvtype : %*d,\nroot : %*d,\ncomm : "
                  "%*d,\nerror/return : %*d\n}\n",
                  sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype,
                  root, comm, ret_tmp);
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

extern unsigned long long WI4MPI_Gatherv_timeout;
extern unsigned int WI4MPI_Gatherv_print;
void (*_LOCAL_MPI_Gatherv)(void *, int *, int *, void *, int *, int *, int *,
                           int *, int *, int *);

void A_f_MPI_Gatherv(void *sendbuf, int *sendcount, int *sendtype,
                     void *recvbuf, int *recvcounts, int *displs, int *recvtype,
                     int *root, int *comm, int *ret) {
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
  if (WI4MPI_Gatherv_print)
    debug_printer("MPI_Gatherv : \n{\nsendbuf : %*d,\nsendcount : "
                  "%*d,\nsendtype : %*d,\nrecvbuf : %*d,\nrecvcounts : "
                  "%*d,\ndispls : %*d,\nrecvtype : %*d,\nroot : %*d,\ncomm : "
                  "%*d,\nerror/return : %*d\n}\n",
                  sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs,
                  recvtype, root, comm, ret_tmp);
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

extern unsigned long long WI4MPI_Scatter_timeout;
extern unsigned int WI4MPI_Scatter_print;
void (*_LOCAL_MPI_Scatter)(void *, int *, int *, void *, int *, int *, int *,
                           int *, int *);

void A_f_MPI_Scatter(void *sendbuf, int *sendcount, int *sendtype,
                     void *recvbuf, int *recvcount, int *recvtype, int *root,
                     int *comm, int *ret) {
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
  if (WI4MPI_Scatter_print)
    debug_printer("MPI_Scatter : \n{\nsendbuf : %*d,\nsendcount : "
                  "%*d,\nsendtype : %*d,\nrecvbuf : %*d,\nrecvcount : "
                  "%*d,\nrecvtype : %*d,\nroot : %*d,\ncomm : "
                  "%*d,\nerror/return : %*d\n}\n",
                  sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype,
                  root, comm, ret_tmp);
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

extern unsigned long long WI4MPI_Scatterv_timeout;
extern unsigned int WI4MPI_Scatterv_print;
void (*_LOCAL_MPI_Scatterv)(void *, int *, int *, int *, void *, int *, int *,
                            int *, int *, int *);

void A_f_MPI_Scatterv(void *sendbuf, int *sendcounts, int *displs,
                      int *sendtype, void *recvbuf, int *recvcount,
                      int *recvtype, int *root, int *comm, int *ret) {
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
  if (WI4MPI_Scatterv_print)
    debug_printer("MPI_Scatterv : \n{\nsendbuf : %*d,\nsendcounts : "
                  "%*d,\ndispls : %*d,\nsendtype : %*d,\nrecvbuf : "
                  "%*d,\nrecvcount : %*d,\nrecvtype : %*d,\nroot : %*d,\ncomm "
                  ": %*d,\nerror/return : %*d\n}\n",
                  sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount,
                  recvtype, root, comm, ret_tmp);
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

extern unsigned long long WI4MPI_Allgather_timeout;
extern unsigned int WI4MPI_Allgather_print;
void (*_LOCAL_MPI_Allgather)(void *, int *, int *, void *, int *, int *, int *,
                             int *);

void A_f_MPI_Allgather(void *sendbuf, int *sendcount, int *sendtype,
                       void *recvbuf, int *recvcount, int *recvtype, int *comm,
                       int *ret) {
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
  if (WI4MPI_Allgather_print)
    debug_printer("MPI_Allgather : \n{\nsendbuf : %*d,\nsendcount : "
                  "%*d,\nsendtype : %*d,\nrecvbuf : %*d,\nrecvcount : "
                  "%*d,\nrecvtype : %*d,\ncomm : %*d,\nerror/return : %*d\n}\n",
                  sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype,
                  comm, ret_tmp);
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

extern unsigned long long WI4MPI_Allgatherv_timeout;
extern unsigned int WI4MPI_Allgatherv_print;
void (*_LOCAL_MPI_Allgatherv)(void *, int *, int *, void *, int *, int *, int *,
                              int *, int *);

void A_f_MPI_Allgatherv(void *sendbuf, int *sendcount, int *sendtype,
                        void *recvbuf, int *recvcounts, int *displs,
                        int *recvtype, int *comm, int *ret) {
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
  if (WI4MPI_Allgatherv_print)
    debug_printer("MPI_Allgatherv : \n{\nsendbuf : %*d,\nsendcount : "
                  "%*d,\nsendtype : %*d,\nrecvbuf : %*d,\nrecvcounts : "
                  "%*d,\ndispls : %*d,\nrecvtype : %*d,\ncomm : "
                  "%*d,\nerror/return : %*d\n}\n",
                  sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs,
                  recvtype, comm, ret_tmp);
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

extern unsigned long long WI4MPI_Alltoall_timeout;
extern unsigned int WI4MPI_Alltoall_print;
void (*_LOCAL_MPI_Alltoall)(void *, int *, int *, void *, int *, int *, int *,
                            int *);

void A_f_MPI_Alltoall(void *sendbuf, int *sendcount, int *sendtype,
                      void *recvbuf, int *recvcount, int *recvtype, int *comm,
                      int *ret) {
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
  if (WI4MPI_Alltoall_print)
    debug_printer("MPI_Alltoall : \n{\nsendbuf : %*d,\nsendcount : "
                  "%*d,\nsendtype : %*d,\nrecvbuf : %*d,\nrecvcount : "
                  "%*d,\nrecvtype : %*d,\ncomm : %*d,\nerror/return : %*d\n}\n",
                  sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype,
                  comm, ret_tmp);
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

extern unsigned long long WI4MPI_Alltoallv_timeout;
extern unsigned int WI4MPI_Alltoallv_print;
void (*_LOCAL_MPI_Alltoallv)(void *, int *, int *, int *, void *, int *, int *,
                             int *, int *, int *);

void A_f_MPI_Alltoallv(void *sendbuf, int *sendcounts, int *sdispls,
                       int *sendtype, void *recvbuf, int *recvcounts,
                       int *rdispls, int *recvtype, int *comm, int *ret) {
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
  if (WI4MPI_Alltoallv_print)
    debug_printer("MPI_Alltoallv : \n{\nsendbuf : %*d,\nsendcounts : "
                  "%*d,\nsdispls : %*d,\nsendtype : %*d,\nrecvbuf : "
                  "%*d,\nrecvcounts : %*d,\nrdispls : %*d,\nrecvtype : "
                  "%*d,\ncomm : %*d,\nerror/return : %*d\n}\n",
                  sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts,
                  rdispls, recvtype, comm, ret_tmp);
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

extern unsigned long long WI4MPI_Exscan_timeout;
extern unsigned int WI4MPI_Exscan_print;
void (*_LOCAL_MPI_Exscan)(void *, void *, int *, int *, int *, int *, int *);

void A_f_MPI_Exscan(void *sendbuf, void *recvbuf, int *count, int *datatype,
                    int *op, int *comm, int *ret) {
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
  if (WI4MPI_Exscan_print)
    debug_printer("MPI_Exscan : \n{\nsendbuf : %*d,\nrecvbuf : %*d,\ncount : "
                  "%*d,\ndatatype : %*d,\nop : %*d,\ncomm : %*d,\nerror/return "
                  ": %*d\n}\n",
                  sendbuf, recvbuf, count, datatype, op, comm, ret_tmp);
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

extern unsigned long long WI4MPI_Reduce_timeout;
extern unsigned int WI4MPI_Reduce_print;
void (*_LOCAL_MPI_Reduce)(void *, void *, int *, int *, int *, int *, int *,
                          int *);

void A_f_MPI_Reduce(void *sendbuf, void *recvbuf, int *count, int *datatype,
                    int *op, int *root, int *comm, int *ret) {
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
  if (WI4MPI_Reduce_print)
    debug_printer("MPI_Reduce : \n{\nsendbuf : %*d,\nrecvbuf : %*d,\ncount : "
                  "%*d,\ndatatype : %*d,\nop : %*d,\nroot : %*d,\ncomm : "
                  "%*d,\nerror/return : %*d\n}\n",
                  sendbuf, recvbuf, count, datatype, op, root, comm, ret_tmp);
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

extern unsigned long long WI4MPI_Op_create_timeout;
extern unsigned int WI4MPI_Op_create_print;
void (*_LOCAL_MPI_Op_create)(void *, int *, int *, int *);

void A_f_MPI_Op_create(void *user_fn, int *commute, int *op, int *ret) {
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
  if (WI4MPI_Op_create_print)
    debug_printer("MPI_Op_create : \n{\nuser_fn : %*d,\ncommute : %*d,\nop : "
                  "%*d,\nerror/return : %*d\n}\n",
                  user_fn, commute, op, ret_tmp);
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

extern unsigned long long WI4MPI_Op_free_timeout;
extern unsigned int WI4MPI_Op_free_print;
void (*_LOCAL_MPI_Op_free)(int *, int *);

void A_f_MPI_Op_free(int *op, int *ret) {
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
  if (WI4MPI_Op_free_print)
    debug_printer("MPI_Op_free : \n{\nop : %*d,\nerror/return : %*d\n}\n", op,
                  ret_tmp);
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

extern unsigned long long WI4MPI_Allreduce_timeout;
extern unsigned int WI4MPI_Allreduce_print;
void (*_LOCAL_MPI_Allreduce)(void *, void *, int *, int *, int *, int *, int *);

void A_f_MPI_Allreduce(void *sendbuf, void *recvbuf, int *count, int *datatype,
                       int *op, int *comm, int *ret) {
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
  if (WI4MPI_Allreduce_print)
    debug_printer("MPI_Allreduce : \n{\nsendbuf : %*d,\nrecvbuf : %*d,\ncount "
                  ": %*d,\ndatatype : %*d,\nop : %*d,\ncomm : "
                  "%*d,\nerror/return : %*d\n}\n",
                  sendbuf, recvbuf, count, datatype, op, comm, ret_tmp);
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

extern unsigned long long WI4MPI_Scan_timeout;
extern unsigned int WI4MPI_Scan_print;
void (*_LOCAL_MPI_Scan)(void *, void *, int *, int *, int *, int *, int *);

void A_f_MPI_Scan(void *sendbuf, void *recvbuf, int *count, int *datatype,
                  int *op, int *comm, int *ret) {
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
  if (WI4MPI_Scan_print)
    debug_printer("MPI_Scan : \n{\nsendbuf : %*d,\nrecvbuf : %*d,\ncount : "
                  "%*d,\ndatatype : %*d,\nop : %*d,\ncomm : %*d,\nerror/return "
                  ": %*d\n}\n",
                  sendbuf, recvbuf, count, datatype, op, comm, ret_tmp);
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

extern unsigned long long WI4MPI_Group_size_timeout;
extern unsigned int WI4MPI_Group_size_print;
void (*_LOCAL_MPI_Group_size)(int *, int *, int *);

void A_f_MPI_Group_size(int *group, int *size, int *ret) {
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
  if (WI4MPI_Group_size_print)
    debug_printer("MPI_Group_size : \n{\ngroup : %*d,\nsize : "
                  "%*d,\nerror/return : %*d\n}\n",
                  group, size, ret_tmp);
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

extern unsigned long long WI4MPI_Group_rank_timeout;
extern unsigned int WI4MPI_Group_rank_print;
void (*_LOCAL_MPI_Group_rank)(int *, int *, int *);

void A_f_MPI_Group_rank(int *group, int *rank, int *ret) {
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
  if (WI4MPI_Group_rank_print)
    debug_printer("MPI_Group_rank : \n{\ngroup : %*d,\nrank : "
                  "%*d,\nerror/return : %*d\n}\n",
                  group, rank, ret_tmp);
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

extern unsigned long long WI4MPI_Group_compare_timeout;
extern unsigned int WI4MPI_Group_compare_print;
void (*_LOCAL_MPI_Group_compare)(int *, int *, int *, int *);

void A_f_MPI_Group_compare(int *group1, int *group2, int *result, int *ret) {
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
  if (WI4MPI_Group_compare_print)
    debug_printer("MPI_Group_compare : \n{\ngroup1 : %*d,\ngroup2 : "
                  "%*d,\nresult : %*d,\nerror/return : %*d\n}\n",
                  group1, group2, result, ret_tmp);
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

extern unsigned long long WI4MPI_Comm_group_timeout;
extern unsigned int WI4MPI_Comm_group_print;
void (*_LOCAL_MPI_Comm_group)(int *, int *, int *);

void A_f_MPI_Comm_group(int *comm, int *group, int *ret) {
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
  if (WI4MPI_Comm_group_print)
    debug_printer("MPI_Comm_group : \n{\ncomm : %*d,\ngroup : "
                  "%*d,\nerror/return : %*d\n}\n",
                  comm, group, ret_tmp);
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

extern unsigned long long WI4MPI_Group_union_timeout;
extern unsigned int WI4MPI_Group_union_print;
void (*_LOCAL_MPI_Group_union)(int *, int *, int *, int *);

void A_f_MPI_Group_union(int *group1, int *group2, int *newgroup, int *ret) {
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
  if (WI4MPI_Group_union_print)
    debug_printer("MPI_Group_union : \n{\ngroup1 : %*d,\ngroup2 : "
                  "%*d,\nnewgroup : %*d,\nerror/return : %*d\n}\n",
                  group1, group2, newgroup, ret_tmp);
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

extern unsigned long long WI4MPI_Group_intersection_timeout;
extern unsigned int WI4MPI_Group_intersection_print;
void (*_LOCAL_MPI_Group_intersection)(int *, int *, int *, int *);

void A_f_MPI_Group_intersection(int *group1, int *group2, int *newgroup,
                                int *ret) {
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
  if (WI4MPI_Group_intersection_print)
    debug_printer("MPI_Group_intersection : \n{\ngroup1 : %*d,\ngroup2 : "
                  "%*d,\nnewgroup : %*d,\nerror/return : %*d\n}\n",
                  group1, group2, newgroup, ret_tmp);
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

extern unsigned long long WI4MPI_Group_difference_timeout;
extern unsigned int WI4MPI_Group_difference_print;
void (*_LOCAL_MPI_Group_difference)(int *, int *, int *, int *);

void A_f_MPI_Group_difference(int *group1, int *group2, int *newgroup,
                              int *ret) {
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
  if (WI4MPI_Group_difference_print)
    debug_printer("MPI_Group_difference : \n{\ngroup1 : %*d,\ngroup2 : "
                  "%*d,\nnewgroup : %*d,\nerror/return : %*d\n}\n",
                  group1, group2, newgroup, ret_tmp);
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

extern unsigned long long WI4MPI_Group_free_timeout;
extern unsigned int WI4MPI_Group_free_print;
void (*_LOCAL_MPI_Group_free)(int *, int *);

void A_f_MPI_Group_free(int *group, int *ret) {
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
  if (WI4MPI_Group_free_print)
    debug_printer("MPI_Group_free : \n{\ngroup : %*d,\nerror/return : %*d\n}\n",
                  group, ret_tmp);
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

extern unsigned long long WI4MPI_Comm_size_timeout;
extern unsigned int WI4MPI_Comm_size_print;
void (*_LOCAL_MPI_Comm_size)(int *, int *, int *);

void A_f_MPI_Comm_size(int *comm, int *size, int *ret) {
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
  if (WI4MPI_Comm_size_print)
    debug_printer("MPI_Comm_size : \n{\ncomm : %*d,\nsize : %*d,\nerror/return "
                  ": %*d\n}\n",
                  comm, size, ret_tmp);
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

extern unsigned long long WI4MPI_Comm_rank_timeout;
extern unsigned int WI4MPI_Comm_rank_print;
void (*_LOCAL_MPI_Comm_rank)(int *, int *, int *);

void A_f_MPI_Comm_rank(int *comm, int *rank, int *ret) {
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
  if (WI4MPI_Comm_rank_print)
    debug_printer("MPI_Comm_rank : \n{\ncomm : %*d,\nrank : %*d,\nerror/return "
                  ": %*d\n}\n",
                  comm, rank, ret_tmp);
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

extern unsigned long long WI4MPI_Comm_compare_timeout;
extern unsigned int WI4MPI_Comm_compare_print;
void (*_LOCAL_MPI_Comm_compare)(int *, int *, int *, int *);

void A_f_MPI_Comm_compare(int *comm1, int *comm2, int *result, int *ret) {
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
  if (WI4MPI_Comm_compare_print)
    debug_printer("MPI_Comm_compare : \n{\ncomm1 : %*d,\ncomm2 : %*d,\nresult "
                  ": %*d,\nerror/return : %*d\n}\n",
                  comm1, comm2, result, ret_tmp);
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

extern unsigned long long WI4MPI_Comm_dup_timeout;
extern unsigned int WI4MPI_Comm_dup_print;
void (*_LOCAL_MPI_Comm_dup)(int *, int *, int *);

void A_f_MPI_Comm_dup(int *comm, int *newcomm, int *ret) {
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
  if (WI4MPI_Comm_dup_print)
    debug_printer("MPI_Comm_dup : \n{\ncomm : %*d,\nnewcomm : "
                  "%*d,\nerror/return : %*d\n}\n",
                  comm, newcomm, ret_tmp);
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

extern unsigned long long WI4MPI_Comm_dup_with_info_timeout;
extern unsigned int WI4MPI_Comm_dup_with_info_print;
void (*_LOCAL_MPI_Comm_dup_with_info)(int *, int *, int *, int *);

void A_f_MPI_Comm_dup_with_info(int *comm, int *info, int *newcomm, int *ret) {
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
  if (WI4MPI_Comm_dup_with_info_print)
    debug_printer("MPI_Comm_dup_with_info : \n{\ncomm : %*d,\ninfo : "
                  "%*d,\nnewcomm : %*d,\nerror/return : %*d\n}\n",
                  comm, info, newcomm, ret_tmp);
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

extern unsigned long long WI4MPI_Comm_create_timeout;
extern unsigned int WI4MPI_Comm_create_print;
void (*_LOCAL_MPI_Comm_create)(int *, int *, int *, int *);

void A_f_MPI_Comm_create(int *comm, int *group, int *newcomm, int *ret) {
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
  if (WI4MPI_Comm_create_print)
    debug_printer("MPI_Comm_create : \n{\ncomm : %*d,\ngroup : %*d,\nnewcomm : "
                  "%*d,\nerror/return : %*d\n}\n",
                  comm, group, newcomm, ret_tmp);
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

extern unsigned long long WI4MPI_Comm_split_timeout;
extern unsigned int WI4MPI_Comm_split_print;
void (*_LOCAL_MPI_Comm_split)(int *, int *, int *, int *, int *);

void A_f_MPI_Comm_split(int *comm, int *color, int *key, int *newcomm,
                        int *ret) {
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
  if (WI4MPI_Comm_split_print)
    debug_printer("MPI_Comm_split : \n{\ncomm : %*d,\ncolor : %*d,\nkey : "
                  "%*d,\nnewcomm : %*d,\nerror/return : %*d\n}\n",
                  comm, color, key, newcomm, ret_tmp);
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

extern unsigned long long WI4MPI_Comm_free_timeout;
extern unsigned int WI4MPI_Comm_free_print;
void (*_LOCAL_MPI_Comm_free)(int *, int *);

void A_f_MPI_Comm_free(int *comm, int *ret) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Comm_free_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Comm_free(&comm_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    comm_r2au(comm, &comm_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_Comm_free_print)
    debug_printer("MPI_Comm_free : \n{\ncomm : %*d,\nerror/return : %*d\n}\n",
                  comm, ret_tmp);
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

extern unsigned long long WI4MPI_Comm_test_inter_timeout;
extern unsigned int WI4MPI_Comm_test_inter_print;
void (*_LOCAL_MPI_Comm_test_inter)(int *, int *, int *);

void A_f_MPI_Comm_test_inter(int *comm, int *flag, int *ret) {
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
  if (WI4MPI_Comm_test_inter_print)
    debug_printer("MPI_Comm_test_inter : \n{\ncomm : %*d,\nflag : "
                  "%*d,\nerror/return : %*d\n}\n",
                  comm, flag, ret_tmp);
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

extern unsigned long long WI4MPI_Comm_remote_size_timeout;
extern unsigned int WI4MPI_Comm_remote_size_print;
void (*_LOCAL_MPI_Comm_remote_size)(int *, int *, int *);

void A_f_MPI_Comm_remote_size(int *comm, int *size, int *ret) {
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
  if (WI4MPI_Comm_remote_size_print)
    debug_printer("MPI_Comm_remote_size : \n{\ncomm : %*d,\nsize : "
                  "%*d,\nerror/return : %*d\n}\n",
                  comm, size, ret_tmp);
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

extern unsigned long long WI4MPI_Comm_remote_group_timeout;
extern unsigned int WI4MPI_Comm_remote_group_print;
void (*_LOCAL_MPI_Comm_remote_group)(int *, int *, int *);

void A_f_MPI_Comm_remote_group(int *comm, int *group, int *ret) {
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
  if (WI4MPI_Comm_remote_group_print)
    debug_printer("MPI_Comm_remote_group : \n{\ncomm : %*d,\ngroup : "
                  "%*d,\nerror/return : %*d\n}\n",
                  comm, group, ret_tmp);
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

extern unsigned long long WI4MPI_Intercomm_create_timeout;
extern unsigned int WI4MPI_Intercomm_create_print;
void (*_LOCAL_MPI_Intercomm_create)(int *, int *, int *, int *, int *, int *,
                                    int *);

void A_f_MPI_Intercomm_create(int *local_comm, int *local_leader,
                              int *peer_comm, int *remote_leader, int *tag,
                              int *newintercomm, int *ret) {
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
  if (WI4MPI_Intercomm_create_print)
    debug_printer("MPI_Intercomm_create : \n{\nlocal_comm : %*d,\nlocal_leader "
                  ": %*d,\npeer_comm : %*d,\nremote_leader : %*d,\ntag : "
                  "%*d,\nnewintercomm : %*d,\nerror/return : %*d\n}\n",
                  local_comm, local_leader, peer_comm, remote_leader, tag,
                  newintercomm, ret_tmp);
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

extern unsigned long long WI4MPI_Intercomm_merge_timeout;
extern unsigned int WI4MPI_Intercomm_merge_print;
void (*_LOCAL_MPI_Intercomm_merge)(int *, int *, int *, int *);

void A_f_MPI_Intercomm_merge(int *intercomm, int *high, int *newintracomm,
                             int *ret) {
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
  if (WI4MPI_Intercomm_merge_print)
    debug_printer("MPI_Intercomm_merge : \n{\nintercomm : %*d,\nhigh : "
                  "%*d,\nnewintracomm : %*d,\nerror/return : %*d\n}\n",
                  intercomm, high, newintracomm, ret_tmp);
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

void (*_LOCAL_MPI_Keyval_create)(void *, void *, int *, void *, int *);
int (*LOCAL_MPI_Keyval_create)(void *, void *, int *, void *);
int (*LOCAL_MPI_Comm_create_keyval)(void *, void *, int *, void *);
extern void *mpi_null_copy_fn_;
extern void *mpi_dup_fn_;
extern void *mpi_null_delete_fn_;
int wrapper_copy_function_f(R_MPI_Comm comm, int keyval, void *extra_state,
                            void *attribute_val_in, void *attribute_val_out,
                            int *flag) {
  A_MPI_Comm comm_tmp;
  comm_conv_r2a_static(&comm_tmp, &comm);
  A_F_MPI_Copy_function *ptr_copy_func =
      myKeyval_translation_get(keyval)->cp_function;
  myKeyval_translation_get(keyval)->ref++;
  // printf("duped %d %p %d %p\n",
  // keyval,comm,myKeyval_translation_get(keyval)->ref,ptr_copy_func);
  if (ptr_copy_func == (A_F_MPI_Copy_function *)A_MPI_NULL_COPY_FN ||
      ptr_copy_func == (A_F_MPI_Copy_function *)A_MPI_COMM_NULL_DELETE_FN ||
      ptr_copy_func == (A_F_MPI_Copy_function *)&mpi_null_copy_fn_) {
    *flag = 0;
    return R_MPI_SUCCESS;
  } else if (ptr_copy_func == (A_F_MPI_Copy_function *)A_MPI_COMM_DUP_FN ||
             ptr_copy_func == (A_F_MPI_Copy_function *)&mpi_dup_fn_) {
    *((int **)attribute_val_out) = (int *)attribute_val_in;
    *flag = 1;
    return R_MPI_SUCCESS;
  }
  int comm_tmpf = A_MPI_Comm_c2f(comm_tmp);
  int res;
  (ptr_copy_func)(&comm_tmpf, &keyval, extra_state, &attribute_val_in,
                  attribute_val_out, flag, &res);
  //    ptr_copy_func = NULL;
  return error_code_conv_r2a(res);
}

int wrapper_delete_function_f(R_MPI_Comm comm, int keyval, void *attribute_val,
                              void *extra_state) {
  A_MPI_Comm comm_tmp;
  int res;
  comm_conv_r2a_static(&comm_tmp, &comm);
  int ct = A_MPI_Comm_c2f(comm_tmp);
  A_F_MPI_Delete_function *ptr_delete_func =
      myKeyval_translation_get(keyval)->del_function;
  if (ptr_delete_func != (A_F_MPI_Delete_function *)A_MPI_NULL_DELETE_FN &&
      ptr_delete_func != (A_F_MPI_Delete_function *)&mpi_null_delete_fn_)
    (ptr_delete_func)(&ct, &keyval, attribute_val, extra_state, &res);
  else
    res = R_MPI_SUCCESS;
  myKeyval_translation_get(keyval)->ref--;
  // printf("deleted %d %p %d\n",
  // keyval,comm,myKeyval_translation_get(keyval)->ref);
  if (myKeyval_translation_get(keyval)->ref == 0)
    myKeyval_translation_del(keyval);
  // ptr_delete_func = NULL;
  return error_code_conv_r2a(res);
}
void A_f_MPI_Keyval_create(void *copy_fn, void *delete_fn, int *keyval,
                           void *extra_state, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Keyval_create\n");
#endif
  in_w = 1;

  /*void *copy_fn_tmp=copy_fn;
  void *delete_fn_tmp=delete_fn;
  void *extra_state_tmp=extra_state;
  copy_ptr_converter_a2r(&copy_fn,&copy_fn_tmp);
  delete_ptr_converter_a2r(&delete_fn,&delete_fn_tmp);
  buffer_a2r(&extra_state,&extra_state_tmp);
   LOCAL_MPI_Keyval_create(copy_fn_tmp,delete_fn_tmp, keyval,extra_state_tmp,
  &ret_tmp);
  ns_t* functions = NULL;
  */
  myKeyval_functions_t *functions = NULL;

  R_MPI_Copy_function *copy_fn_tmp;
  R_MPI_Delete_function *delete_fn_tmp;
  copy_fn_tmp = wrapper_copy_function_f;
  delete_fn_tmp = wrapper_delete_function_f;

  int ret_tmp = LOCAL_MPI_Comm_create_keyval(copy_fn_tmp, delete_fn_tmp, keyval,
                                             extra_state);

  functions = (myKeyval_functions_t *)malloc(sizeof(myKeyval_functions_t));
  functions->cp_function = copy_fn;
  functions->del_function = delete_fn;
  functions->ref = 1;
  myKeyval_translation_add(*keyval, functions);

  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Keyval_create\n");
#endif
}
void mpi_keyval_free_(int *, int *);

void mpi_keyval_free__(int *, int *);

void pmpi_keyval_free_(int *, int *);

void pmpi_keyval_free__(int *, int *);

void pmpi_keyval_free_(int *, int *);

void (*_LOCAL_MPI_Keyval_free)(int *, int *);

void A_f_MPI_Keyval_free(int *keyval, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Keyval_free\n");
#endif
  in_w = 1;
  int ret_tmp = 0;
  /*
   _LOCAL_MPI_Keyval_free( keyval, &ret_tmp);
  if(ret_tmp==R_f_MPI_SUCCESS)
  {
          *keyval=A_MPI_KEYVAL_INVALID;
  }
  */
  ret_tmp = A_MPI_Keyval_free(keyval);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Keyval_free\n");
#endif
}
void mpi_attr_put_(int *, int *, int *, int *);

void mpi_attr_put__(int *, int *, int *, int *);

void pmpi_attr_put_(int *, int *, int *, int *);

void pmpi_attr_put__(int *, int *, int *, int *);

void pmpi_attr_put_(int *, int *, int *, int *);

void (*_LOCAL_MPI_Attr_put)(int *, int *, int *, int *);

void A_f_MPI_Attr_put(int *comm, int *keyval, int *attribute_val, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Attr_put\n");
#endif
  // in_w=1;
  int ret_tmp = 0;

  int comm_tmp;
  /*comm_a2r(comm,&comm_tmp);
   _LOCAL_MPI_Attr_put( &comm_tmp, keyval, attribute_val, &ret_tmp);
  //if(*keyval==R_F_MPI_INVALID) *keyval=A_F_MPI_INVALID;
  */
  A_MPI_Comm ct = A_MPI_Comm_f2c(*comm);
  long tv = *(attribute_val);
  ret_tmp = A_MPI_Attr_put(ct, *keyval, &tv);
  error_r2a(ret, &ret_tmp);

// in_w=0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Attr_put\n");
#endif
}
void mpi_attr_get_(int *, int *, int *, int *, int *);

void mpi_attr_get__(int *, int *, int *, int *, int *);

void pmpi_attr_get_(int *, int *, int *, int *, int *);

void pmpi_attr_get__(int *, int *, int *, int *, int *);

void pmpi_attr_get_(int *, int *, int *, int *, int *);

void (*_LOCAL_MPI_Attr_get)(int *, int *, int *, int *, int *);

void A_f_MPI_Attr_get(int *comm, int *keyval, int *attribute_val, int *flag,
                      int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Attr_get\n");
#endif
  // in_w=1;
  int ret_tmp = 0;

  int comm_tmp;
  int keyval_tmp =
      *keyval; //=(*keyval==R_F_MPI_INVALID?A_F_MPI_INVALID:*keyval);
  /*comm_a2r(comm,&comm_tmp);
   _LOCAL_MPI_Attr_get( &comm_tmp, &keyval_tmp, attribute_val, flag, &ret_tmp);
  */
  A_MPI_Comm ct = A_MPI_Comm_f2c(*comm);
  long kt = 0;
  *attribute_val = 0;
  // printf("val %d %p %d %d\n",*attribute_val,ct,*keyval,*flag);
  ret_tmp = A_MPI_Attr_get(ct, *keyval, &kt, flag);
  if (kt >> 32)
    kt = (int)(((long)(1 << 31)) - 1);
  *attribute_val = (int)kt;
  // printf("val %d %p %d %d\n",*attribute_val,ct,*keyval,*flag);
  error_r2a(ret, &ret_tmp);
// in_w=0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Attr_get\n");
#endif
}
void mpi_attr_delete_(int *, int *, int *);

void mpi_attr_delete__(int *, int *, int *);

void pmpi_attr_delete_(int *, int *, int *);

void pmpi_attr_delete__(int *, int *, int *);

void pmpi_attr_delete_(int *, int *, int *);

void (*_LOCAL_MPI_Attr_delete)(int *, int *, int *);
int A_MPI_Attr_delete(A_MPI_Comm, int);

void A_f_MPI_Attr_delete(int *comm, int *keyval, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Attr_delete\n");
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  int keyval_tmp;
  // comm_a2r(comm,&comm_tmp);
  A_MPI_Comm ct = A_MPI_Comm_f2c(*comm);
  ret_tmp = A_MPI_Attr_delete(ct, *keyval);
  // _LOCAL_MPI_Attr_delete( &comm_tmp, keyval, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Attr_delete\n");
#endif
}
void mpi_topo_test_(int *, int *, int *);

void mpi_topo_test__(int *, int *, int *);

void pmpi_topo_test_(int *, int *, int *);

void pmpi_topo_test__(int *, int *, int *);

void pmpi_topo_test_(int *, int *, int *);

extern unsigned long long WI4MPI_Topo_test_timeout;
extern unsigned int WI4MPI_Topo_test_print;
void (*_LOCAL_MPI_Topo_test)(int *, int *, int *);

void A_f_MPI_Topo_test(int *comm, int *status, int *ret) {
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
  if (WI4MPI_Topo_test_print)
    debug_printer("MPI_Topo_test : \n{\ncomm : %*d,\nstatus : "
                  "%*d,\nerror/return : %*d\n}\n",
                  comm, status, ret_tmp);
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

extern unsigned long long WI4MPI_Graphdims_get_timeout;
extern unsigned int WI4MPI_Graphdims_get_print;
void (*_LOCAL_MPI_Graphdims_get)(int *, int *, int *, int *);

void A_f_MPI_Graphdims_get(int *comm, int *nnodes, int *nedges, int *ret) {
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
  if (WI4MPI_Graphdims_get_print)
    debug_printer("MPI_Graphdims_get : \n{\ncomm : %*d,\nnnodes : %*d,\nnedges "
                  ": %*d,\nerror/return : %*d\n}\n",
                  comm, nnodes, nedges, ret_tmp);
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

extern unsigned long long WI4MPI_Cartdim_get_timeout;
extern unsigned int WI4MPI_Cartdim_get_print;
void (*_LOCAL_MPI_Cartdim_get)(int *, int *, int *);

void A_f_MPI_Cartdim_get(int *comm, int *ndims, int *ret) {
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
  if (WI4MPI_Cartdim_get_print)
    debug_printer("MPI_Cartdim_get : \n{\ncomm : %*d,\nndims : "
                  "%*d,\nerror/return : %*d\n}\n",
                  comm, ndims, ret_tmp);
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

extern unsigned long long WI4MPI_Graph_neighbors_count_timeout;
extern unsigned int WI4MPI_Graph_neighbors_count_print;
void (*_LOCAL_MPI_Graph_neighbors_count)(int *, int *, int *, int *);

void A_f_MPI_Graph_neighbors_count(int *comm, int *rank, int *nneighbors,
                                   int *ret) {
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
  if (WI4MPI_Graph_neighbors_count_print)
    debug_printer("MPI_Graph_neighbors_count : \n{\ncomm : %*d,\nrank : "
                  "%*d,\nnneighbors : %*d,\nerror/return : %*d\n}\n",
                  comm, rank, nneighbors, ret_tmp);
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

extern unsigned long long WI4MPI_Cart_shift_timeout;
extern unsigned int WI4MPI_Cart_shift_print;
void (*_LOCAL_MPI_Cart_shift)(int *, int *, int *, int *, int *, int *);

void A_f_MPI_Cart_shift(int *comm, int *direction, int *disp, int *rank_source,
                        int *rank_dest, int *ret) {
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
  if (WI4MPI_Cart_shift_print)
    debug_printer("MPI_Cart_shift : \n{\ncomm : %*d,\ndirection : %*d,\ndisp : "
                  "%*d,\nrank_source : %*d,\nrank_dest : %*d,\nerror/return : "
                  "%*d\n}\n",
                  comm, direction, disp, rank_source, rank_dest, ret_tmp);
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

extern unsigned long long WI4MPI_Get_version_timeout;
extern unsigned int WI4MPI_Get_version_print;
void (*_LOCAL_MPI_Get_version)(int *, int *, int *);

void A_f_MPI_Get_version(int *version, int *subversion, int *ret) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Get_version_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_Get_version(version, subversion, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_Get_version_print)
    debug_printer("MPI_Get_version : \n{\nversion : %*d,\nsubversion : "
                  "%*d,\nerror/return : %*d\n}\n",
                  version, subversion, ret_tmp);
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

void (*_LOCAL_MPI_Errhandler_create)(void *, int *, int *);
extern int WI4MPI_errhandler_key;
#include "mappers.h"
static void wrapper_handler_function_f(R_MPI_Comm *comm, int *err, ...) {
  void (*hf)(int *, int *, ...);
  A_MPI_Comm comm_tmp;
  int ct;
  int flags;

  comm_conv_r2a_static(&comm_tmp, comm);
  // communicator_fn_translation_get(comm_tmp, &hf);
  R_MPI_Comm_get_attr(*comm, WI4MPI_errhandler_key, &hf, &flags);
  printf("coucou errhandler %d %p\n", comm_tmp, comm);
  ct = A_MPI_Comm_c2f(comm_tmp);
  if (hf)
    (*hf)(&ct, err, "", NULL);
}
extern int (*LOCAL_MPI_Errhandler_create)(R_MPI_Handler_function *,
                                          R_MPI_Errhandler *);
void A_f_MPI_Errhandler_create(void *function, int *errhandler, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Errhandler_create\n");
#endif
  // in_w=1;

  void *function_tmp = function;
  // handler_fct_ptr_conv_a2r(&function,&function_tmp);
  in_w = 1;

  A_MPI_Errhandler aerrhandler;
  A_MPI_Errhandler *paerrhandler = &aerrhandler;
  ptr_handler_fn = (A_MPI_Handler_function *)function;
  R_MPI_Errhandler errhandler_ltmp;
  R_MPI_Errhandler *errhandler_tmp = &errhandler_ltmp;
  int ret_tmp = LOCAL_MPI_Errhandler_create(
      (R_MPI_Handler_function *)&wrapper_handler_function_f, errhandler_tmp);
  errhandler_ptr_conv_r2a(&(paerrhandler), &errhandler_tmp);
  //*errhandler=(int)aerrhandler;
  *errhandler = A_MPI_Errhandler_c2f(aerrhandler);
  in_w = 0;

/*A_MPI_Errhandler errhandler_tmp;
*ret=A_MPI_Errhandler_create(function,&errhandler_tmp);
*errhandler=(int)errhandler_tmp;
*/ // in_w=0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Errhandler_create %d\n", *errhandler);
#endif
}
void mpi_errhandler_set_(int *, int *, int *);

void mpi_errhandler_set__(int *, int *, int *);

void pmpi_errhandler_set_(int *, int *, int *);

void pmpi_errhandler_set__(int *, int *, int *);

void pmpi_errhandler_set_(int *, int *, int *);

void (*_LOCAL_MPI_Errhandler_set)(int *, int *, int *);
void A_f_MPI_Errhandler_set(int *comm, int *errhandler, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Errhandler_set\n");
#endif
  /*in_w=1;
  int  ret_tmp=0;

  int comm_tmp;
  int errhandler_tmp;
  comm_a2r(comm,&comm_tmp);
  errhandler_converter_a2r(errhandler,&errhandler_tmp);
   _LOCAL_MPI_Errhandler_set( &comm_tmp, &errhandler_tmp, &ret_tmp);
  errhandler_set_func(comm_tmp,errhandler_tmp);
  error_r2a(ret,&ret_tmp);

  in_w=0;
  */
  A_MPI_Comm ct = A_MPI_Comm_f2c(*comm);
  // printf("%d\n",ct);
  A_MPI_Errhandler ht = A_MPI_Errhandler_f2c(*errhandler);
  *ret = A_MPI_Errhandler_set(ct, ht);
#ifdef DEBUG
  printf("sort : A_f_MPI_Errhandler_set\n %d", *errhandler);
#endif
}
void mpi_errhandler_get_(int *, int *, int *);

void mpi_errhandler_get__(int *, int *, int *);

void pmpi_errhandler_get_(int *, int *, int *);

void pmpi_errhandler_get__(int *, int *, int *);

void pmpi_errhandler_get_(int *, int *, int *);

void (*_LOCAL_MPI_Errhandler_get)(int *, int *, int *);

void A_f_MPI_Errhandler_get(int *comm, int *errhandler, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Errhandler_get\n");
#endif
  /*in_w=1;
  int  ret_tmp=0;

  int comm_tmp;
  int errhandler_tmp;
  comm_a2r(comm,&comm_tmp);
   _LOCAL_MPI_Errhandler_get( &comm_tmp, &errhandler_tmp, &ret_tmp);
  if(ret_tmp==R_f_MPI_SUCCESS)errhandler_converter_r2a(errhandler,&errhandler_tmp);
  error_r2a(ret,&ret_tmp);

  in_w=0;
  */

  A_MPI_Comm ct = A_MPI_Comm_f2c(*comm);
  A_MPI_Errhandler ht = (A_MPI_Errhandler)*errhandler;
  *ret = A_MPI_Errhandler_get(ct, &ht);
  if (*ret == A_f_MPI_SUCCESS)
    *errhandler = A_MPI_Errhandler_c2f(ht);
  else
    *errhandler = A_f_MPI_ERRORS_ARE_FATAL;
#ifdef DEBUG
  printf("sort : A_f_MPI_Errhandler_get\n");
#endif
}
void mpi_errhandler_free_(int *, int *);

void mpi_errhandler_free__(int *, int *);

void pmpi_errhandler_free_(int *, int *);

void pmpi_errhandler_free__(int *, int *);

void pmpi_errhandler_free_(int *, int *);

void (*_LOCAL_MPI_Errhandler_free)(int *, int *);

void A_f_MPI_Errhandler_free(int *errhandler, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Errhandler_free\n");
#endif
  /*in_w=1;
  int  ret_tmp=0;

  errhandler_converter_a2r(errhandler,&errhandler_tmp);
  errhandler_f_fn_translation_del(errhandler_tmp);
   _LOCAL_MPI_Errhandler_free( &errhandler_tmp, &ret_tmp);
  if(ret_tmp==R_f_MPI_SUCCESS){
  errhandler_f_fn_translation_del(errhandler_tmp);
  errhandler_converter_r2a(errhandler,&errhandler_tmp);


  }
  error_r2a(ret,&ret_tmp);

  in_w=0;*/
  A_MPI_Errhandler errhandler_tmp;
  if (*errhandler != 0)
    errhandler_tmp = (A_MPI_Errhandler)*errhandler;
  else
    errhandler_tmp = A_MPI_ERRHANDLER_NULL;
  *ret = A_MPI_Errhandler_free(&errhandler_tmp);
  if (*errhandler != 0)
    *errhandler = (int)errhandler_tmp;
#ifdef DEBUG
  printf("sort : A_f_MPI_Errhandler_free\n");
#endif
}
void mpi_error_class_(int *, int *, int *);

void mpi_error_class__(int *, int *, int *);

void pmpi_error_class_(int *, int *, int *);

void pmpi_error_class__(int *, int *, int *);

void pmpi_error_class_(int *, int *, int *);

extern unsigned long long WI4MPI_Error_class_timeout;
extern unsigned int WI4MPI_Error_class_print;
void (*_LOCAL_MPI_Error_class)(int *, int *, int *);

void A_f_MPI_Error_class(int *errorcode, int *errorclass, int *ret) {
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
  if (WI4MPI_Error_class_print)
    debug_printer("MPI_Error_class : \n{\nerrorcode : %*d,\nerrorclass : "
                  "%*d,\nerror/return : %*d\n}\n",
                  errorcode, errorclass, ret_tmp);
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

extern unsigned long long WI4MPI_Initialized_timeout;
extern unsigned int WI4MPI_Initialized_print;
void (*_LOCAL_MPI_Initialized)(int *, int *);

void A_f_MPI_Initialized(int *flag, int *ret) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Initialized_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_Initialized(flag, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_Initialized_print)
    debug_printer("MPI_Initialized : \n{\nflag : %*d,\nerror/return : %*d\n}\n",
                  flag, ret_tmp);
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

extern unsigned long long WI4MPI_Abort_timeout;
extern unsigned int WI4MPI_Abort_print;
void (*_LOCAL_MPI_Abort)(int *, int *, int *);

void A_f_MPI_Abort(int *comm, int *errorcode, int *ret) {
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
  if (WI4MPI_Abort_print)
    debug_printer("MPI_Abort : \n{\ncomm : %*d,\nerrorcode : "
                  "%*d,\nerror/return : %*d\n}\n",
                  comm, errorcode, ret_tmp);
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

extern unsigned long long WI4MPI_Init_timeout;
extern unsigned int WI4MPI_Init_print;
void (*_LOCAL_MPI_Init)(int *);

void A_f_MPI_Init(int *ret) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Init_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_Init(&ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_Init_print)
    debug_printer("MPI_Init : \n{\nerror/return : %*d\n}\n", ret_tmp);
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

extern unsigned long long WI4MPI_Comm_accept_timeout;
extern unsigned int WI4MPI_Comm_accept_print;
void (*_LOCAL_MPI_Comm_accept)(char *, int *, int *, int *, int *, int *);

void A_f_MPI_Comm_accept(char *port_name, int *info, int *root, int *comm,
                         int *newcomm, int *ret) {
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
  if (WI4MPI_Comm_accept_print)
    debug_printer("MPI_Comm_accept : \n{\nport_name : %*d,\ninfo : %*d,\nroot "
                  ": %*d,\ncomm : %*d,\nnewcomm : %*d,\nerror/return : "
                  "%*d\n}\n",
                  port_name, info, root, comm, newcomm, ret_tmp);
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

extern unsigned long long WI4MPI_Comm_connect_timeout;
extern unsigned int WI4MPI_Comm_connect_print;
void (*_LOCAL_MPI_Comm_connect)(char *, int *, int *, int *, int *, int *);

void A_f_MPI_Comm_connect(char *port_name, int *info, int *root, int *comm,
                          int *newcomm, int *ret) {
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
  if (WI4MPI_Comm_connect_print)
    debug_printer("MPI_Comm_connect : \n{\nport_name : %*d,\ninfo : %*d,\nroot "
                  ": %*d,\ncomm : %*d,\nnewcomm : %*d,\nerror/return : "
                  "%*d\n}\n",
                  port_name, info, root, comm, newcomm, ret_tmp);
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

extern unsigned long long WI4MPI_Comm_disconnect_timeout;
extern unsigned int WI4MPI_Comm_disconnect_print;
void (*_LOCAL_MPI_Comm_disconnect)(int *, int *);

void A_f_MPI_Comm_disconnect(int *comm, int *ret) {
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
  if (WI4MPI_Comm_disconnect_print)
    debug_printer(
        "MPI_Comm_disconnect : \n{\ncomm : %*d,\nerror/return : %*d\n}\n", comm,
        ret_tmp);
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

extern unsigned long long WI4MPI_Comm_get_parent_timeout;
extern unsigned int WI4MPI_Comm_get_parent_print;
void (*_LOCAL_MPI_Comm_get_parent)(int *, int *);

void A_f_MPI_Comm_get_parent(int *parent, int *ret) {
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
  if (WI4MPI_Comm_get_parent_print)
    debug_printer(
        "MPI_Comm_get_parent : \n{\nparent : %*d,\nerror/return : %*d\n}\n",
        parent, ret_tmp);
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

extern unsigned long long WI4MPI_Comm_join_timeout;
extern unsigned int WI4MPI_Comm_join_print;
void (*_LOCAL_MPI_Comm_join)(int *, int *, int *);

void A_f_MPI_Comm_join(int *fd, int *intercomm, int *ret) {
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
  if (WI4MPI_Comm_join_print)
    debug_printer("MPI_Comm_join : \n{\nfd : %*d,\nintercomm : "
                  "%*d,\nerror/return : %*d\n}\n",
                  fd, intercomm, ret_tmp);
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

extern unsigned long long WI4MPI_Comm_set_info_timeout;
extern unsigned int WI4MPI_Comm_set_info_print;
void (*_LOCAL_MPI_Comm_set_info)(int *, int *, int *);

void A_f_MPI_Comm_set_info(int *comm, int *info, int *ret) {
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
  if (WI4MPI_Comm_set_info_print)
    debug_printer("MPI_Comm_set_info : \n{\ncomm : %*d,\ninfo : "
                  "%*d,\nerror/return : %*d\n}\n",
                  comm, info, ret_tmp);
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

extern unsigned long long WI4MPI_Comm_get_info_timeout;
extern unsigned int WI4MPI_Comm_get_info_print;
void (*_LOCAL_MPI_Comm_get_info)(int *, int *, int *);

void A_f_MPI_Comm_get_info(int *comm, int *info, int *ret) {
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
  if (WI4MPI_Comm_get_info_print)
    debug_printer("MPI_Comm_get_info : \n{\ncomm : %*d,\ninfo : "
                  "%*d,\nerror/return : %*d\n}\n",
                  comm, info, ret_tmp);
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

extern unsigned long long WI4MPI_Accumulate_timeout;
extern unsigned int WI4MPI_Accumulate_print;
void (*_LOCAL_MPI_Accumulate)(void *, int *, int *, int *, size_t *, int *,
                              int *, int *, int *, int *);

void A_f_MPI_Accumulate(void *origin_addr, int *origin_count,
                        int *origin_datatype, int *target_rank,
                        size_t *target_disp, int *target_count,
                        int *target_datatype, int *op, int *win, int *ret) {
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
  if (WI4MPI_Accumulate_print)
    debug_printer("MPI_Accumulate : \n{\norigin_addr : %*d,\norigin_count : "
                  "%*d,\norigin_datatype : %*d,\ntarget_rank : "
                  "%*d,\ntarget_disp : %*d,\ntarget_count : "
                  "%*d,\ntarget_datatype : %*d,\nop : %*d,\nwin : "
                  "%*d,\nerror/return : %*d\n}\n",
                  origin_addr, origin_count, origin_datatype, target_rank,
                  target_disp, target_count, target_datatype, op, win, ret_tmp);
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

extern unsigned long long WI4MPI_Get_timeout;
extern unsigned int WI4MPI_Get_print;
void (*_LOCAL_MPI_Get)(void *, int *, int *, int *, size_t *, int *, int *,
                       int *, int *);

void A_f_MPI_Get(void *origin_addr, int *origin_count, int *origin_datatype,
                 int *target_rank, size_t *target_disp, int *target_count,
                 int *target_datatype, int *win, int *ret) {
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
  if (WI4MPI_Get_print)
    debug_printer("MPI_Get : \n{\norigin_addr : %*d,\norigin_count : "
                  "%*d,\norigin_datatype : %*d,\ntarget_rank : "
                  "%*d,\ntarget_disp : %*d,\ntarget_count : "
                  "%*d,\ntarget_datatype : %*d,\nwin : %*d,\nerror/return : "
                  "%*d\n}\n",
                  origin_addr, origin_count, origin_datatype, target_rank,
                  target_disp, target_count, target_datatype, win, ret_tmp);
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

extern unsigned long long WI4MPI_Put_timeout;
extern unsigned int WI4MPI_Put_print;
void (*_LOCAL_MPI_Put)(void *, int *, int *, int *, size_t *, int *, int *,
                       int *, int *);

void A_f_MPI_Put(void *origin_addr, int *origin_count, int *origin_datatype,
                 int *target_rank, size_t *target_disp, int *target_count,
                 int *target_datatype, int *win, int *ret) {
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
  if (WI4MPI_Put_print)
    debug_printer("MPI_Put : \n{\norigin_addr : %*d,\norigin_count : "
                  "%*d,\norigin_datatype : %*d,\ntarget_rank : "
                  "%*d,\ntarget_disp : %*d,\ntarget_count : "
                  "%*d,\ntarget_datatype : %*d,\nwin : %*d,\nerror/return : "
                  "%*d\n}\n",
                  origin_addr, origin_count, origin_datatype, target_rank,
                  target_disp, target_count, target_datatype, win, ret_tmp);
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

extern unsigned long long WI4MPI_Win_complete_timeout;
extern unsigned int WI4MPI_Win_complete_print;
void (*_LOCAL_MPI_Win_complete)(int *, int *);

void A_f_MPI_Win_complete(int *win, int *ret) {
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
  if (WI4MPI_Win_complete_print)
    debug_printer("MPI_Win_complete : \n{\nwin : %*d,\nerror/return : %*d\n}\n",
                  win, ret_tmp);
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

extern unsigned long long WI4MPI_Win_create_timeout;
extern unsigned int WI4MPI_Win_create_print;
void (*_LOCAL_MPI_Win_create)(void *, size_t *, int *, int *, int *, int *,
                              int *);

void A_f_MPI_Win_create(void *base, size_t *size, int *disp_unit, int *info,
                        int *comm, int *win, int *ret) {
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
  if (WI4MPI_Win_create_print)
    debug_printer("MPI_Win_create : \n{\nbase : %*d,\nsize : %*d,\ndisp_unit : "
                  "%*d,\ninfo : %*d,\ncomm : %*d,\nwin : %*d,\nerror/return : "
                  "%*d\n}\n",
                  base, size, disp_unit, info, comm, win, ret_tmp);
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

extern unsigned long long WI4MPI_Win_fence_timeout;
extern unsigned int WI4MPI_Win_fence_print;
void (*_LOCAL_MPI_Win_fence)(int *, int *, int *);

void A_f_MPI_Win_fence(int *assert, int *win, int *ret) {
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
  if (WI4MPI_Win_fence_print)
    debug_printer("MPI_Win_fence : \n{\nassert : %*d,\nwin : "
                  "%*d,\nerror/return : %*d\n}\n",
                  assert, win, ret_tmp);
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

extern unsigned long long WI4MPI_Win_free_timeout;
extern unsigned int WI4MPI_Win_free_print;
void (*_LOCAL_MPI_Win_free)(int *, int *);

void A_f_MPI_Win_free(int *win, int *ret) {
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
  if (WI4MPI_Win_free_print)
    debug_printer("MPI_Win_free : \n{\nwin : %*d,\nerror/return : %*d\n}\n",
                  win, ret_tmp);
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

extern unsigned long long WI4MPI_Win_get_group_timeout;
extern unsigned int WI4MPI_Win_get_group_print;
void (*_LOCAL_MPI_Win_get_group)(int *, int *, int *);

void A_f_MPI_Win_get_group(int *win, int *group, int *ret) {
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
  if (WI4MPI_Win_get_group_print)
    debug_printer("MPI_Win_get_group : \n{\nwin : %*d,\ngroup : "
                  "%*d,\nerror/return : %*d\n}\n",
                  win, group, ret_tmp);
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

extern unsigned long long WI4MPI_Win_lock_timeout;
extern unsigned int WI4MPI_Win_lock_print;
void (*_LOCAL_MPI_Win_lock)(int *, int *, int *, int *, int *);

void A_f_MPI_Win_lock(int *lock_type, int *rank, int *assert, int *win,
                      int *ret) {
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
  if (WI4MPI_Win_lock_print)
    debug_printer("MPI_Win_lock : \n{\nlock_type : %*d,\nrank : %*d,\nassert : "
                  "%*d,\nwin : %*d,\nerror/return : %*d\n}\n",
                  lock_type, rank, assert, win, ret_tmp);
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

extern unsigned long long WI4MPI_Win_post_timeout;
extern unsigned int WI4MPI_Win_post_print;
void (*_LOCAL_MPI_Win_post)(int *, int *, int *, int *);

void A_f_MPI_Win_post(int *group, int *assert, int *win, int *ret) {
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
  if (WI4MPI_Win_post_print)
    debug_printer("MPI_Win_post : \n{\ngroup : %*d,\nassert : %*d,\nwin : "
                  "%*d,\nerror/return : %*d\n}\n",
                  group, assert, win, ret_tmp);
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

extern unsigned long long WI4MPI_Win_start_timeout;
extern unsigned int WI4MPI_Win_start_print;
void (*_LOCAL_MPI_Win_start)(int *, int *, int *, int *);

void A_f_MPI_Win_start(int *group, int *assert, int *win, int *ret) {
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
  if (WI4MPI_Win_start_print)
    debug_printer("MPI_Win_start : \n{\ngroup : %*d,\nassert : %*d,\nwin : "
                  "%*d,\nerror/return : %*d\n}\n",
                  group, assert, win, ret_tmp);
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

extern unsigned long long WI4MPI_Win_test_timeout;
extern unsigned int WI4MPI_Win_test_print;
void (*_LOCAL_MPI_Win_test)(int *, int *, int *);

void A_f_MPI_Win_test(int *win, int *flag, int *ret) {
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
  if (WI4MPI_Win_test_print)
    debug_printer(
        "MPI_Win_test : \n{\nwin : %*d,\nflag : %*d,\nerror/return : %*d\n}\n",
        win, flag, ret_tmp);
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

extern unsigned long long WI4MPI_Win_unlock_timeout;
extern unsigned int WI4MPI_Win_unlock_print;
void (*_LOCAL_MPI_Win_unlock)(int *, int *, int *);

void A_f_MPI_Win_unlock(int *rank, int *win, int *ret) {
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
  if (WI4MPI_Win_unlock_print)
    debug_printer("MPI_Win_unlock : \n{\nrank : %*d,\nwin : %*d,\nerror/return "
                  ": %*d\n}\n",
                  rank, win, ret_tmp);
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

extern unsigned long long WI4MPI_Win_wait_timeout;
extern unsigned int WI4MPI_Win_wait_print;
void (*_LOCAL_MPI_Win_wait)(int *, int *);

void A_f_MPI_Win_wait(int *win, int *ret) {
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
  if (WI4MPI_Win_wait_print)
    debug_printer("MPI_Win_wait : \n{\nwin : %*d,\nerror/return : %*d\n}\n",
                  win, ret_tmp);
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

extern unsigned long long WI4MPI_Win_allocate_timeout;
extern unsigned int WI4MPI_Win_allocate_print;
void (*_LOCAL_MPI_Win_allocate)(size_t *, int *, int *, int *, void *, int *,
                                int *);

void A_f_MPI_Win_allocate(size_t *size, int *disp_unit, int *info, int *comm,
                          void *baseptr, int *win, int *ret) {
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
  if (WI4MPI_Win_allocate_print)
    debug_printer("MPI_Win_allocate : \n{\nsize : %*d,\ndisp_unit : %*d,\ninfo "
                  ": %*d,\ncomm : %*d,\nbaseptr : %*d,\nwin : "
                  "%*d,\nerror/return : %*d\n}\n",
                  size, disp_unit, info, comm, baseptr, win, ret_tmp);
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

extern unsigned long long WI4MPI_Win_allocate_shared_timeout;
extern unsigned int WI4MPI_Win_allocate_shared_print;
void (*_LOCAL_MPI_Win_allocate_shared)(size_t *, int *, int *, int *, void *,
                                       int *, int *);

void A_f_MPI_Win_allocate_shared(size_t *size, int *disp_unit, int *info,
                                 int *comm, void *baseptr, int *win, int *ret) {
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
  if (WI4MPI_Win_allocate_shared_print)
    debug_printer("MPI_Win_allocate_shared : \n{\nsize : %*d,\ndisp_unit : "
                  "%*d,\ninfo : %*d,\ncomm : %*d,\nbaseptr : %*d,\nwin : "
                  "%*d,\nerror/return : %*d\n}\n",
                  size, disp_unit, info, comm, baseptr, win, ret_tmp);
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

extern unsigned long long WI4MPI_Win_shared_query_timeout;
extern unsigned int WI4MPI_Win_shared_query_print;
void (*_LOCAL_MPI_Win_shared_query)(int *, int *, size_t *, int *, void *,
                                    int *);

void A_f_MPI_Win_shared_query(int *win, int *rank, size_t *size, int *disp_unit,
                              void *baseptr, int *ret) {
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
  if (WI4MPI_Win_shared_query_print)
    debug_printer("MPI_Win_shared_query : \n{\nwin : %*d,\nrank : %*d,\nsize : "
                  "%*d,\ndisp_unit : %*d,\nbaseptr : %*d,\nerror/return : "
                  "%*d\n}\n",
                  win, rank, size, disp_unit, baseptr, ret_tmp);
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

extern unsigned long long WI4MPI_Win_create_dynamic_timeout;
extern unsigned int WI4MPI_Win_create_dynamic_print;
void (*_LOCAL_MPI_Win_create_dynamic)(int *, int *, int *, int *);

void A_f_MPI_Win_create_dynamic(int *info, int *comm, int *win, int *ret) {
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
  if (WI4MPI_Win_create_dynamic_print)
    debug_printer("MPI_Win_create_dynamic : \n{\ninfo : %*d,\ncomm : %*d,\nwin "
                  ": %*d,\nerror/return : %*d\n}\n",
                  info, comm, win, ret_tmp);
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

extern unsigned long long WI4MPI_Win_attach_timeout;
extern unsigned int WI4MPI_Win_attach_print;
void (*_LOCAL_MPI_Win_attach)(int *, void *, size_t *, int *);

void A_f_MPI_Win_attach(int *win, void *base, size_t *size, int *ret) {
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
  if (WI4MPI_Win_attach_print)
    debug_printer("MPI_Win_attach : \n{\nwin : %*d,\nbase : %*d,\nsize : "
                  "%*d,\nerror/return : %*d\n}\n",
                  win, base, size, ret_tmp);
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

extern unsigned long long WI4MPI_Win_detach_timeout;
extern unsigned int WI4MPI_Win_detach_print;
void (*_LOCAL_MPI_Win_detach)(int *, void *, int *);

void A_f_MPI_Win_detach(int *win, void *base, int *ret) {
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
  if (WI4MPI_Win_detach_print)
    debug_printer("MPI_Win_detach : \n{\nwin : %*d,\nbase : %*d,\nerror/return "
                  ": %*d\n}\n",
                  win, base, ret_tmp);
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

extern unsigned long long WI4MPI_Win_get_info_timeout;
extern unsigned int WI4MPI_Win_get_info_print;
void (*_LOCAL_MPI_Win_get_info)(int *, int *, int *);

void A_f_MPI_Win_get_info(int *win, int *info_used, int *ret) {
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
  if (WI4MPI_Win_get_info_print)
    debug_printer("MPI_Win_get_info : \n{\nwin : %*d,\ninfo_used : "
                  "%*d,\nerror/return : %*d\n}\n",
                  win, info_used, ret_tmp);
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

extern unsigned long long WI4MPI_Win_set_info_timeout;
extern unsigned int WI4MPI_Win_set_info_print;
void (*_LOCAL_MPI_Win_set_info)(int *, int *, int *);

void A_f_MPI_Win_set_info(int *win, int *info, int *ret) {
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
  if (WI4MPI_Win_set_info_print)
    debug_printer("MPI_Win_set_info : \n{\nwin : %*d,\ninfo : "
                  "%*d,\nerror/return : %*d\n}\n",
                  win, info, ret_tmp);
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

extern unsigned long long WI4MPI_Get_accumulate_timeout;
extern unsigned int WI4MPI_Get_accumulate_print;
void (*_LOCAL_MPI_Get_accumulate)(void *, int *, int *, void *, int *, int *,
                                  int *, size_t *, int *, int *, int *, int *,
                                  int *);

void A_f_MPI_Get_accumulate(void *origin_addr, int *origin_count,
                            int *origin_datatype, void *result_addr,
                            int *result_count, int *result_datatype,
                            int *target_rank, size_t *target_disp,
                            int *target_count, int *target_datatype, int *op,
                            int *win, int *ret) {
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
  if (WI4MPI_Get_accumulate_print)
    debug_printer("MPI_Get_accumulate : \n{\norigin_addr : %*d,\norigin_count "
                  ": %*d,\norigin_datatype : %*d,\nresult_addr : "
                  "%*d,\nresult_count : %*d,\nresult_datatype : "
                  "%*d,\ntarget_rank : %*d,\ntarget_disp : %*d,\ntarget_count "
                  ": %*d,\ntarget_datatype : %*d,\nop : %*d,\nwin : "
                  "%*d,\nerror/return : %*d\n}\n",
                  origin_addr, origin_count, origin_datatype, result_addr,
                  result_count, result_datatype, target_rank, target_disp,
                  target_count, target_datatype, op, win, ret_tmp);
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

extern unsigned long long WI4MPI_Fetch_and_op_timeout;
extern unsigned int WI4MPI_Fetch_and_op_print;
void (*_LOCAL_MPI_Fetch_and_op)(void *, void *, int *, int *, size_t *, int *,
                                int *, int *);

void A_f_MPI_Fetch_and_op(void *origin_addr, void *result_addr, int *datatype,
                          int *target_rank, size_t *target_disp, int *op,
                          int *win, int *ret) {
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
  if (WI4MPI_Fetch_and_op_print)
    debug_printer("MPI_Fetch_and_op : \n{\norigin_addr : %*d,\nresult_addr : "
                  "%*d,\ndatatype : %*d,\ntarget_rank : %*d,\ntarget_disp : "
                  "%*d,\nop : %*d,\nwin : %*d,\nerror/return : %*d\n}\n",
                  origin_addr, result_addr, datatype, target_rank, target_disp,
                  op, win, ret_tmp);
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

extern unsigned long long WI4MPI_Compare_and_swap_timeout;
extern unsigned int WI4MPI_Compare_and_swap_print;
void (*_LOCAL_MPI_Compare_and_swap)(void *, void *, void *, int *, int *,
                                    size_t *, int *, int *);

void A_f_MPI_Compare_and_swap(void *origin_addr, void *compare_addr,
                              void *result_addr, int *datatype,
                              int *target_rank, size_t *target_disp, int *win,
                              int *ret) {
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
  if (WI4MPI_Compare_and_swap_print)
    debug_printer("MPI_Compare_and_swap : \n{\norigin_addr : "
                  "%*d,\ncompare_addr : %*d,\nresult_addr : %*d,\ndatatype : "
                  "%*d,\ntarget_rank : %*d,\ntarget_disp : %*d,\nwin : "
                  "%*d,\nerror/return : %*d\n}\n",
                  origin_addr, compare_addr, result_addr, datatype, target_rank,
                  target_disp, win, ret_tmp);
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

extern unsigned long long WI4MPI_Rput_timeout;
extern unsigned int WI4MPI_Rput_print;
void (*_LOCAL_MPI_Rput)(void *, int *, int *, int *, size_t *, int *, int *,
                        int *, int *, int *);

void A_f_MPI_Rput(void *origin_addr, int *origin_count, int *origin_datatype,
                  int *target_rank, size_t *target_disp, int *target_count,
                  int *target_datatype, int *win, int *request, int *ret) {
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
  if (WI4MPI_Rput_print)
    debug_printer(
        "MPI_Rput : \n{\norigin_addr : %*d,\norigin_count : "
        "%*d,\norigin_datatype : %*d,\ntarget_rank : %*d,\ntarget_disp : "
        "%*d,\ntarget_count : %*d,\ntarget_datatype : %*d,\nwin : "
        "%*d,\nrequest : %*d,\nerror/return : %*d\n}\n",
        origin_addr, origin_count, origin_datatype, target_rank, target_disp,
        target_count, target_datatype, win, request, ret_tmp);
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

extern unsigned long long WI4MPI_Rget_timeout;
extern unsigned int WI4MPI_Rget_print;
void (*_LOCAL_MPI_Rget)(void *, int *, int *, int *, size_t *, int *, int *,
                        int *, int *, int *);

void A_f_MPI_Rget(void *origin_addr, int *origin_count, int *origin_datatype,
                  int *target_rank, size_t *target_disp, int *target_count,
                  int *target_datatype, int *win, int *request, int *ret) {
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
  if (WI4MPI_Rget_print)
    debug_printer(
        "MPI_Rget : \n{\norigin_addr : %*d,\norigin_count : "
        "%*d,\norigin_datatype : %*d,\ntarget_rank : %*d,\ntarget_disp : "
        "%*d,\ntarget_count : %*d,\ntarget_datatype : %*d,\nwin : "
        "%*d,\nrequest : %*d,\nerror/return : %*d\n}\n",
        origin_addr, origin_count, origin_datatype, target_rank, target_disp,
        target_count, target_datatype, win, request, ret_tmp);
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

extern unsigned long long WI4MPI_Raccumulate_timeout;
extern unsigned int WI4MPI_Raccumulate_print;
void (*_LOCAL_MPI_Raccumulate)(void *, int *, int *, int *, size_t *, int *,
                               int *, int *, int *, int *, int *);

void A_f_MPI_Raccumulate(void *origin_addr, int *origin_count,
                         int *origin_datatype, int *target_rank,
                         size_t *target_disp, int *target_count,
                         int *target_datatype, int *op, int *win, int *request,
                         int *ret) {
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
  if (WI4MPI_Raccumulate_print)
    debug_printer(
        "MPI_Raccumulate : \n{\norigin_addr : %*d,\norigin_count : "
        "%*d,\norigin_datatype : %*d,\ntarget_rank : %*d,\ntarget_disp : "
        "%*d,\ntarget_count : %*d,\ntarget_datatype : %*d,\nop : %*d,\nwin : "
        "%*d,\nrequest : %*d,\nerror/return : %*d\n}\n",
        origin_addr, origin_count, origin_datatype, target_rank, target_disp,
        target_count, target_datatype, op, win, request, ret_tmp);
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

extern unsigned long long WI4MPI_Rget_accumulate_timeout;
extern unsigned int WI4MPI_Rget_accumulate_print;
void (*_LOCAL_MPI_Rget_accumulate)(void *, int *, int *, void *, int *, int *,
                                   int *, size_t *, int *, int *, int *, int *,
                                   int *, int *);

void A_f_MPI_Rget_accumulate(void *origin_addr, int *origin_count,
                             int *origin_datatype, void *result_addr,
                             int *result_count, int *result_datatype,
                             int *target_rank, size_t *target_disp,
                             int *target_count, int *target_datatype, int *op,
                             int *win, int *request, int *ret) {
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
  if (WI4MPI_Rget_accumulate_print)
    debug_printer("MPI_Rget_accumulate : \n{\norigin_addr : %*d,\norigin_count "
                  ": %*d,\norigin_datatype : %*d,\nresult_addr : "
                  "%*d,\nresult_count : %*d,\nresult_datatype : "
                  "%*d,\ntarget_rank : %*d,\ntarget_disp : %*d,\ntarget_count "
                  ": %*d,\ntarget_datatype : %*d,\nop : %*d,\nwin : "
                  "%*d,\nrequest : %*d,\nerror/return : %*d\n}\n",
                  origin_addr, origin_count, origin_datatype, result_addr,
                  result_count, result_datatype, target_rank, target_disp,
                  target_count, target_datatype, op, win, request, ret_tmp);
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

extern unsigned long long WI4MPI_Win_lock_all_timeout;
extern unsigned int WI4MPI_Win_lock_all_print;
void (*_LOCAL_MPI_Win_lock_all)(int *, int *, int *);

void A_f_MPI_Win_lock_all(int *assert, int *win, int *ret) {
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
  if (WI4MPI_Win_lock_all_print)
    debug_printer("MPI_Win_lock_all : \n{\nassert : %*d,\nwin : "
                  "%*d,\nerror/return : %*d\n}\n",
                  assert, win, ret_tmp);
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

extern unsigned long long WI4MPI_Win_unlock_all_timeout;
extern unsigned int WI4MPI_Win_unlock_all_print;
void (*_LOCAL_MPI_Win_unlock_all)(int *, int *);

void A_f_MPI_Win_unlock_all(int *win, int *ret) {
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
  if (WI4MPI_Win_unlock_all_print)
    debug_printer(
        "MPI_Win_unlock_all : \n{\nwin : %*d,\nerror/return : %*d\n}\n", win,
        ret_tmp);
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

extern unsigned long long WI4MPI_Win_flush_timeout;
extern unsigned int WI4MPI_Win_flush_print;
void (*_LOCAL_MPI_Win_flush)(int *, int *, int *);

void A_f_MPI_Win_flush(int *rank, int *win, int *ret) {
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
  if (WI4MPI_Win_flush_print)
    debug_printer(
        "MPI_Win_flush : \n{\nrank : %*d,\nwin : %*d,\nerror/return : %*d\n}\n",
        rank, win, ret_tmp);
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

extern unsigned long long WI4MPI_Win_flush_all_timeout;
extern unsigned int WI4MPI_Win_flush_all_print;
void (*_LOCAL_MPI_Win_flush_all)(int *, int *);

void A_f_MPI_Win_flush_all(int *win, int *ret) {
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
  if (WI4MPI_Win_flush_all_print)
    debug_printer(
        "MPI_Win_flush_all : \n{\nwin : %*d,\nerror/return : %*d\n}\n", win,
        ret_tmp);
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

extern unsigned long long WI4MPI_Win_flush_local_timeout;
extern unsigned int WI4MPI_Win_flush_local_print;
void (*_LOCAL_MPI_Win_flush_local)(int *, int *, int *);

void A_f_MPI_Win_flush_local(int *rank, int *win, int *ret) {
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
  if (WI4MPI_Win_flush_local_print)
    debug_printer("MPI_Win_flush_local : \n{\nrank : %*d,\nwin : "
                  "%*d,\nerror/return : %*d\n}\n",
                  rank, win, ret_tmp);
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

extern unsigned long long WI4MPI_Win_flush_local_all_timeout;
extern unsigned int WI4MPI_Win_flush_local_all_print;
void (*_LOCAL_MPI_Win_flush_local_all)(int *, int *);

void A_f_MPI_Win_flush_local_all(int *win, int *ret) {
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
  if (WI4MPI_Win_flush_local_all_print)
    debug_printer(
        "MPI_Win_flush_local_all : \n{\nwin : %*d,\nerror/return : %*d\n}\n",
        win, ret_tmp);
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

extern unsigned long long WI4MPI_Win_sync_timeout;
extern unsigned int WI4MPI_Win_sync_print;
void (*_LOCAL_MPI_Win_sync)(int *, int *);

void A_f_MPI_Win_sync(int *win, int *ret) {
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
  if (WI4MPI_Win_sync_print)
    debug_printer("MPI_Win_sync : \n{\nwin : %*d,\nerror/return : %*d\n}\n",
                  win, ret_tmp);
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

extern unsigned long long WI4MPI_Add_error_class_timeout;
extern unsigned int WI4MPI_Add_error_class_print;
void (*_LOCAL_MPI_Add_error_class)(int *, int *);

void A_f_MPI_Add_error_class(int *errorclass, int *ret) {
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
  if (WI4MPI_Add_error_class_print)
    debug_printer(
        "MPI_Add_error_class : \n{\nerrorclass : %*d,\nerror/return : %*d\n}\n",
        errorclass, ret_tmp);
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

extern unsigned long long WI4MPI_Add_error_code_timeout;
extern unsigned int WI4MPI_Add_error_code_print;
void (*_LOCAL_MPI_Add_error_code)(int *, int *, int *);

void A_f_MPI_Add_error_code(int *errorclass, int *errorcode, int *ret) {
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
  if (WI4MPI_Add_error_code_print)
    debug_printer("MPI_Add_error_code : \n{\nerrorclass : %*d,\nerrorcode : "
                  "%*d,\nerror/return : %*d\n}\n",
                  errorclass, errorcode, ret_tmp);
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

extern unsigned long long WI4MPI_Comm_call_errhandler_timeout;
extern unsigned int WI4MPI_Comm_call_errhandler_print;
void (*_LOCAL_MPI_Comm_call_errhandler)(int *, int *, int *);

void A_f_MPI_Comm_call_errhandler(int *comm, int *errorcode, int *ret) {
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
  if (WI4MPI_Comm_call_errhandler_print)
    debug_printer("MPI_Comm_call_errhandler : \n{\ncomm : %*d,\nerrorcode : "
                  "%*d,\nerror/return : %*d\n}\n",
                  comm, errorcode, ret_tmp);
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

extern unsigned long long WI4MPI_Comm_delete_attr_timeout;
extern unsigned int WI4MPI_Comm_delete_attr_print;
void (*_LOCAL_MPI_Comm_delete_attr)(int *, int *, int *);

void A_f_MPI_Comm_delete_attr(int *comm, int *comm_keyval, int *ret) {
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
  if (WI4MPI_Comm_delete_attr_print)
    debug_printer("MPI_Comm_delete_attr : \n{\ncomm : %*d,\ncomm_keyval : "
                  "%*d,\nerror/return : %*d\n}\n",
                  comm, comm_keyval, ret_tmp);
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

extern unsigned long long WI4MPI_Comm_get_attr_timeout;
extern unsigned int WI4MPI_Comm_get_attr_print;
void (*_LOCAL_MPI_Comm_get_attr)(int *, int *, void *, int *, int *);

void A_f_MPI_Comm_get_attr(int *comm, int *comm_keyval, void *attribute_val,
                           int *flag, int *ret) {
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
  if (WI4MPI_Comm_get_attr_print)
    debug_printer("MPI_Comm_get_attr : \n{\ncomm : %*d,\ncomm_keyval : "
                  "%*d,\nattribute_val : %*d,\nflag : %*d,\nerror/return : "
                  "%*d\n}\n",
                  comm, comm_keyval, attribute_val, flag, ret_tmp);
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

extern unsigned long long WI4MPI_Comm_set_attr_timeout;
extern unsigned int WI4MPI_Comm_set_attr_print;
void (*_LOCAL_MPI_Comm_set_attr)(int *, int *, void *, int *);

void A_f_MPI_Comm_set_attr(int *comm, int *comm_keyval, void *attribute_val,
                           int *ret) {
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
  if (WI4MPI_Comm_set_attr_print)
    debug_printer("MPI_Comm_set_attr : \n{\ncomm : %*d,\ncomm_keyval : "
                  "%*d,\nattribute_val : %*d,\nerror/return : %*d\n}\n",
                  comm, comm_keyval, attribute_val, ret_tmp);
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

extern unsigned long long WI4MPI_Init_thread_timeout;
extern unsigned int WI4MPI_Init_thread_print;
void (*_LOCAL_MPI_Init_thread)(int *, int *, int *);

void A_f_MPI_Init_thread(int *required, int *provided, int *ret) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Init_thread_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_Init_thread(required, provided, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_Init_thread_print)
    debug_printer("MPI_Init_thread : \n{\nrequired : %*d,\nprovided : "
                  "%*d,\nerror/return : %*d\n}\n",
                  required, provided, ret_tmp);
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

extern unsigned long long WI4MPI_Is_thread_main_timeout;
extern unsigned int WI4MPI_Is_thread_main_print;
void (*_LOCAL_MPI_Is_thread_main)(int *, int *);

void A_f_MPI_Is_thread_main(int *flag, int *ret) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Is_thread_main_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_Is_thread_main(flag, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_Is_thread_main_print)
    debug_printer(
        "MPI_Is_thread_main : \n{\nflag : %*d,\nerror/return : %*d\n}\n", flag,
        ret_tmp);
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

extern unsigned long long WI4MPI_Query_thread_timeout;
extern unsigned int WI4MPI_Query_thread_print;
void (*_LOCAL_MPI_Query_thread)(int *, int *);

void A_f_MPI_Query_thread(int *provided, int *ret) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Query_thread_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_Query_thread(provided, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_Query_thread_print)
    debug_printer(
        "MPI_Query_thread : \n{\nprovided : %*d,\nerror/return : %*d\n}\n",
        provided, ret_tmp);
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

extern unsigned long long WI4MPI_Status_set_cancelled_timeout;
extern unsigned int WI4MPI_Status_set_cancelled_print;
void (*_LOCAL_MPI_Status_set_cancelled)(int *, int *, int *);

void A_f_MPI_Status_set_cancelled(int *status, int *flag, int *ret) {
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
  if (WI4MPI_Status_set_cancelled_print)
    debug_printer("MPI_Status_set_cancelled : \n{\nstatus : %S,\nflag : "
                  "%*d,\nerror/return : %*d\n}\n",
                  status, flag, ret_tmp);
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

extern unsigned long long WI4MPI_Status_set_elements_timeout;
extern unsigned int WI4MPI_Status_set_elements_print;
void (*_LOCAL_MPI_Status_set_elements)(int *, int *, int *, int *);

void A_f_MPI_Status_set_elements(int *status, int *datatype, int *count,
                                 int *ret) {
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
  if (WI4MPI_Status_set_elements_print)
    debug_printer("MPI_Status_set_elements : \n{\nstatus : %S,\ndatatype : "
                  "%*d,\ncount : %*d,\nerror/return : %*d\n}\n",
                  status, datatype, count, ret_tmp);
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

extern unsigned long long WI4MPI_Type_delete_attr_timeout;
extern unsigned int WI4MPI_Type_delete_attr_print;
void (*_LOCAL_MPI_Type_delete_attr)(int *, int *, int *);

void A_f_MPI_Type_delete_attr(int *datatype, int *type_keyval, int *ret) {
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
  if (WI4MPI_Type_delete_attr_print)
    debug_printer("MPI_Type_delete_attr : \n{\ndatatype : %*d,\ntype_keyval : "
                  "%*d,\nerror/return : %*d\n}\n",
                  datatype, type_keyval, ret_tmp);
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

extern unsigned long long WI4MPI_Type_dup_timeout;
extern unsigned int WI4MPI_Type_dup_print;
void (*_LOCAL_MPI_Type_dup)(int *, int *, int *);

void A_f_MPI_Type_dup(int *oldtype, int *newtype, int *ret) {
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
  if (WI4MPI_Type_dup_print)
    debug_printer("MPI_Type_dup : \n{\noldtype : %*d,\nnewtype : "
                  "%*d,\nerror/return : %*d\n}\n",
                  oldtype, newtype, ret_tmp);
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

extern unsigned long long WI4MPI_Type_free_keyval_timeout;
extern unsigned int WI4MPI_Type_free_keyval_print;
void (*_LOCAL_MPI_Type_free_keyval)(int *, int *);

void A_f_MPI_Type_free_keyval(int *type_keyval, int *ret) {
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
  if (WI4MPI_Type_free_keyval_print)
    debug_printer("MPI_Type_free_keyval : \n{\ntype_keyval : "
                  "%*d,\nerror/return : %*d\n}\n",
                  type_keyval, ret_tmp);
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

extern unsigned long long WI4MPI_Type_get_attr_timeout;
extern unsigned int WI4MPI_Type_get_attr_print;
void (*_LOCAL_MPI_Type_get_attr)(int *, int *, void *, int *, int *);

void A_f_MPI_Type_get_attr(int *datatype, int *type_keyval, void *attribute_val,
                           int *flag, int *ret) {
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
  if (WI4MPI_Type_get_attr_print)
    debug_printer("MPI_Type_get_attr : \n{\ndatatype : %*d,\ntype_keyval : "
                  "%*d,\nattribute_val : %*d,\nflag : %*d,\nerror/return : "
                  "%*d\n}\n",
                  datatype, type_keyval, attribute_val, flag, ret_tmp);
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

extern unsigned long long WI4MPI_Type_get_envelope_timeout;
extern unsigned int WI4MPI_Type_get_envelope_print;
void (*_LOCAL_MPI_Type_get_envelope)(int *, int *, int *, int *, int *, int *);

void A_f_MPI_Type_get_envelope(int *datatype, int *num_integers,
                               int *num_addresses, int *num_datatypes,
                               int *combiner, int *ret) {
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
  if (WI4MPI_Type_get_envelope_print)
    debug_printer("MPI_Type_get_envelope : \n{\ndatatype : %*d,\nnum_integers "
                  ": %*d,\nnum_addresses : %*d,\nnum_datatypes : "
                  "%*d,\ncombiner : %*d,\nerror/return : %*d\n}\n",
                  datatype, num_integers, num_addresses, num_datatypes,
                  combiner, ret_tmp);
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

extern unsigned long long WI4MPI_Type_set_attr_timeout;
extern unsigned int WI4MPI_Type_set_attr_print;
void (*_LOCAL_MPI_Type_set_attr)(int *, int *, void *, int *);

void A_f_MPI_Type_set_attr(int *datatype, int *type_keyval, void *attribute_val,
                           int *ret) {
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
  if (WI4MPI_Type_set_attr_print)
    debug_printer("MPI_Type_set_attr : \n{\ndatatype : %*d,\ntype_keyval : "
                  "%*d,\nattribute_val : %*d,\nerror/return : %*d\n}\n",
                  datatype, type_keyval, attribute_val, ret_tmp);
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

extern unsigned long long WI4MPI_Type_match_size_timeout;
extern unsigned int WI4MPI_Type_match_size_print;
void (*_LOCAL_MPI_Type_match_size)(int *, int *, int *, int *);

void A_f_MPI_Type_match_size(int *typeclass, int *size, int *datatype,
                             int *ret) {
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
  if (WI4MPI_Type_match_size_print)
    debug_printer("MPI_Type_match_size : \n{\ntypeclass : %*d,\nsize : "
                  "%*d,\ndatatype : %*d,\nerror/return : %*d\n}\n",
                  typeclass, size, datatype, ret_tmp);
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

extern unsigned long long WI4MPI_Alloc_mem_timeout;
extern unsigned int WI4MPI_Alloc_mem_print;
void (*_LOCAL_MPI_Alloc_mem)(size_t *, int *, void *, int *);

void A_f_MPI_Alloc_mem(size_t *size, int *info, void *baseptr, int *ret) {
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
  if (WI4MPI_Alloc_mem_print)
    debug_printer("MPI_Alloc_mem : \n{\nsize : %*d,\ninfo : %*d,\nbaseptr : "
                  "%*d,\nerror/return : %*d\n}\n",
                  size, info, baseptr, ret_tmp);
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

void (*_LOCAL_MPI_Comm_create_errhandler)(void *, int *, int *);

void A_f_MPI_Comm_create_errhandler(void *comm_errhandler_fn, int *errhandler,
                                    int *ret) {
  /*#ifdef DEBUG
  printf("entre : A_f_MPI_Comm_create_errhandler\n");
  #endif
  in_w=1;
  int  ret_tmp=0;

  void *comm_errhandler_fn_tmp=comm_errhandler_fn;
  int errhandler_tmp;
  handler_fct_ptr_conv_a2r(&comm_errhandler_fn,&comm_errhandler_fn_tmp);
   _LOCAL_MPI_Comm_create_errhandler(comm_errhandler_fn_tmp, &errhandler_tmp,
  &ret_tmp);
  if(ret_tmp==R_f_MPI_SUCCESS)errhandler_converter_r2a(errhandler,&errhandler_tmp);
  errhandler_f_fn_translation_update(errhandler_tmp,comm_errhandler_fn);
  error_r2a(ret,&ret_tmp);

  in_w=0;
  #ifdef DEBUG
  printf("sort : A_f_MPI_Comm_create_errhandler\n");
  #endif
  */
  return A_f_MPI_Errhandler_create(comm_errhandler_fn, errhandler, ret);
}
void mpi_comm_get_errhandler_(int *, int *, int *);

void mpi_comm_get_errhandler__(int *, int *, int *);

void pmpi_comm_get_errhandler_(int *, int *, int *);

void pmpi_comm_get_errhandler__(int *, int *, int *);

void pmpi_comm_get_errhandler_(int *, int *, int *);

void (*_LOCAL_MPI_Comm_get_errhandler)(int *, int *, int *);

void A_f_MPI_Comm_get_errhandler(int *comm, int *errhandler, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Comm_get_errhandler\n");
#endif
  /*in_w=1;
  int  ret_tmp=0;

  int comm_tmp;
  int errhandler_tmp;
  comm_a2r(comm,&comm_tmp);
   _LOCAL_MPI_Comm_get_errhandler( &comm_tmp, &errhandler_tmp, &ret_tmp);
  if(ret_tmp==R_f_MPI_SUCCESS)errhandler_converter_r2a(errhandler,&errhandler_tmp);
  error_r2a(ret,&ret_tmp);

  in_w=0;
  #ifdef DEBUG
  printf("sort : A_f_MPI_Comm_get_errhandler\n");
  #endif
  */
  return A_f_MPI_Errhandler_get(comm, errhandler, ret);
}
void mpi_comm_set_errhandler_(int *, int *, int *);

void mpi_comm_set_errhandler__(int *, int *, int *);

void pmpi_comm_set_errhandler_(int *, int *, int *);

void pmpi_comm_set_errhandler__(int *, int *, int *);

void pmpi_comm_set_errhandler_(int *, int *, int *);

void (*_LOCAL_MPI_Comm_set_errhandler)(int *, int *, int *);

void A_f_MPI_Comm_set_errhandler(int *comm, int *errhandler, int *ret) {
  /*#ifdef DEBUG
  printf("entre : A_f_MPI_Comm_set_errhandler\n");
  #endif
  in_w=1;
  int  ret_tmp=0;

  int comm_tmp;
  int errhandler_tmp;
  comm_a2r(comm,&comm_tmp);
  errhandler_converter_a2r(errhandler,&errhandler_tmp);
   _LOCAL_MPI_Comm_set_errhandler( &comm_tmp, &errhandler_tmp, &ret_tmp);
  errhandler_set_func(comm_tmp,errhandler_tmp);
  error_r2a(ret,&ret_tmp);

  in_w=0;
  #ifdef DEBUG
  printf("sort : A_f_MPI_Comm_set_errhandler\n");
  #endif
  */
  return A_f_MPI_Errhandler_set(comm, errhandler, ret);
}
void mpi_file_get_errhandler_(int *, int *, int *);

void mpi_file_get_errhandler__(int *, int *, int *);

void pmpi_file_get_errhandler_(int *, int *, int *);

void pmpi_file_get_errhandler__(int *, int *, int *);

void pmpi_file_get_errhandler_(int *, int *, int *);

extern unsigned long long WI4MPI_File_get_errhandler_timeout;
extern unsigned int WI4MPI_File_get_errhandler_print;
void (*_LOCAL_MPI_File_get_errhandler)(int *, int *, int *);

void A_f_MPI_File_get_errhandler(int *file, int *errhandler, int *ret) {
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
  if (WI4MPI_File_get_errhandler_print)
    debug_printer("MPI_File_get_errhandler : \n{\nfile : %*d,\nerrhandler : "
                  "%*d,\nerror/return : %*d\n}\n",
                  file, errhandler, ret_tmp);
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

extern unsigned long long WI4MPI_File_set_errhandler_timeout;
extern unsigned int WI4MPI_File_set_errhandler_print;
void (*_LOCAL_MPI_File_set_errhandler)(int *, int *, int *);

void A_f_MPI_File_set_errhandler(int *file, int *errhandler, int *ret) {
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
  if (WI4MPI_File_set_errhandler_print)
    debug_printer("MPI_File_set_errhandler : \n{\nfile : %*d,\nerrhandler : "
                  "%*d,\nerror/return : %*d\n}\n",
                  file, errhandler, ret_tmp);
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

extern unsigned long long WI4MPI_Finalized_timeout;
extern unsigned int WI4MPI_Finalized_print;
void (*_LOCAL_MPI_Finalized)(int *, int *);

void A_f_MPI_Finalized(int *flag, int *ret) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Finalized_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_Finalized(flag, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_Finalized_print)
    debug_printer("MPI_Finalized : \n{\nflag : %*d,\nerror/return : %*d\n}\n",
                  flag, ret_tmp);
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

extern unsigned long long WI4MPI_Free_mem_timeout;
extern unsigned int WI4MPI_Free_mem_print;
void (*_LOCAL_MPI_Free_mem)(void *, int *);

void A_f_MPI_Free_mem(void *base, int *ret) {
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
  if (WI4MPI_Free_mem_print)
    debug_printer("MPI_Free_mem : \n{\nbase : %*d,\nerror/return : %*d\n}\n",
                  base, ret_tmp);
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

extern unsigned long long WI4MPI_Get_address_timeout;
extern unsigned int WI4MPI_Get_address_print;
void (*_LOCAL_MPI_Get_address)(void *, size_t *, int *);

void A_f_MPI_Get_address(void *location, size_t *address, int *ret) {
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
  if (WI4MPI_Get_address_print)
    debug_printer("MPI_Get_address : \n{\nlocation : %*d,\naddress : "
                  "%*d,\nerror/return : %*d\n}\n",
                  location, address, ret_tmp);
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

extern unsigned long long WI4MPI_Info_create_timeout;
extern unsigned int WI4MPI_Info_create_print;
void (*_LOCAL_MPI_Info_create)(int *, int *);

void A_f_MPI_Info_create(int *info, int *ret) {
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
  if (WI4MPI_Info_create_print)
    debug_printer("MPI_Info_create : \n{\ninfo : %*d,\nerror/return : %*d\n}\n",
                  info, ret_tmp);
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

extern unsigned long long WI4MPI_Info_dup_timeout;
extern unsigned int WI4MPI_Info_dup_print;
void (*_LOCAL_MPI_Info_dup)(int *, int *, int *);

void A_f_MPI_Info_dup(int *info, int *newinfo, int *ret) {
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
  if (WI4MPI_Info_dup_print)
    debug_printer("MPI_Info_dup : \n{\ninfo : %*d,\nnewinfo : "
                  "%*d,\nerror/return : %*d\n}\n",
                  info, newinfo, ret_tmp);
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

void (*_LOCAL_MPI_Info_free)(int *, int *);

void A_f_MPI_Info_free(int *info, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Info_free\n");
#endif
  in_w = 1;
  int ret_tmp = 0;

  int info_tmp;
  info_a2r(info, &info_tmp);
  _LOCAL_MPI_Info_free(&info_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    info_r2au(info, &info_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Info_free\n");
#endif
}
void mpi_info_get_nkeys_(int *, int *, int *);

void mpi_info_get_nkeys__(int *, int *, int *);

void pmpi_info_get_nkeys_(int *, int *, int *);

void pmpi_info_get_nkeys__(int *, int *, int *);

void pmpi_info_get_nkeys_(int *, int *, int *);

extern unsigned long long WI4MPI_Info_get_nkeys_timeout;
extern unsigned int WI4MPI_Info_get_nkeys_print;
void (*_LOCAL_MPI_Info_get_nkeys)(int *, int *, int *);

void A_f_MPI_Info_get_nkeys(int *info, int *nkeys, int *ret) {
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
  if (WI4MPI_Info_get_nkeys_print)
    debug_printer("MPI_Info_get_nkeys : \n{\ninfo : %*d,\nnkeys : "
                  "%*d,\nerror/return : %*d\n}\n",
                  info, nkeys, ret_tmp);
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

extern unsigned long long WI4MPI_Request_get_status_timeout;
extern unsigned int WI4MPI_Request_get_status_print;
void (*_LOCAL_MPI_Request_get_status)(int *, int *, int *, int *);

void A_f_MPI_Request_get_status(int *request, int *flag, int *status,
                                int *ret) {
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
  if (WI4MPI_Request_get_status_print)
    debug_printer("MPI_Request_get_status : \n{\nrequest : %*d,\nflag : "
                  "%*d,\nstatus : %S,\nerror/return : %*d\n}\n",
                  request, flag, status, ret_tmp);
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

extern unsigned long long WI4MPI_Type_create_hvector_timeout;
extern unsigned int WI4MPI_Type_create_hvector_print;
void (*_LOCAL_MPI_Type_create_hvector)(int *, int *, size_t *, int *, int *,
                                       int *);

void A_f_MPI_Type_create_hvector(int *count, int *blocklength, size_t *stride,
                                 int *oldtype, int *newtype, int *ret) {
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
  if (WI4MPI_Type_create_hvector_print)
    debug_printer("MPI_Type_create_hvector : \n{\ncount : %*d,\nblocklength : "
                  "%*d,\nstride : %*d,\noldtype : %*d,\nnewtype : "
                  "%*d,\nerror/return : %*d\n}\n",
                  count, blocklength, stride, oldtype, newtype, ret_tmp);
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

extern unsigned long long WI4MPI_Type_create_resized_timeout;
extern unsigned int WI4MPI_Type_create_resized_print;
void (*_LOCAL_MPI_Type_create_resized)(int *, size_t *, size_t *, int *, int *);

void A_f_MPI_Type_create_resized(int *oldtype, size_t *lb, size_t *extent,
                                 int *newtype, int *ret) {
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
  if (WI4MPI_Type_create_resized_print)
    debug_printer("MPI_Type_create_resized : \n{\noldtype : %*d,\nlb : "
                  "%*d,\nextent : %*d,\nnewtype : %*d,\nerror/return : "
                  "%*d\n}\n",
                  oldtype, lb, extent, newtype, ret_tmp);
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

extern unsigned long long WI4MPI_Type_get_extent_timeout;
extern unsigned int WI4MPI_Type_get_extent_print;
void (*_LOCAL_MPI_Type_get_extent)(int *, size_t *, size_t *, int *);

void A_f_MPI_Type_get_extent(int *datatype, size_t *lb, size_t *extent,
                             int *ret) {
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
  if (WI4MPI_Type_get_extent_print)
    debug_printer("MPI_Type_get_extent : \n{\ndatatype : %*d,\nlb : "
                  "%*d,\nextent : %*d,\nerror/return : %*d\n}\n",
                  datatype, lb, extent, ret_tmp);
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

extern unsigned long long WI4MPI_Type_get_true_extent_timeout;
extern unsigned int WI4MPI_Type_get_true_extent_print;
void (*_LOCAL_MPI_Type_get_true_extent)(int *, size_t *, size_t *, int *);

void A_f_MPI_Type_get_true_extent(int *datatype, size_t *true_lb,
                                  size_t *true_extent, int *ret) {
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
  if (WI4MPI_Type_get_true_extent_print)
    debug_printer("MPI_Type_get_true_extent : \n{\ndatatype : %*d,\ntrue_lb : "
                  "%*d,\ntrue_extent : %*d,\nerror/return : %*d\n}\n",
                  datatype, true_lb, true_extent, ret_tmp);
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

extern unsigned long long WI4MPI_Type_create_f90_integer_timeout;
extern unsigned int WI4MPI_Type_create_f90_integer_print;
void (*_LOCAL_MPI_Type_create_f90_integer)(int *, int *, int *);

void A_f_MPI_Type_create_f90_integer(int *range, int *newtype, int *ret) {
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
  if (WI4MPI_Type_create_f90_integer_print)
    debug_printer("MPI_Type_create_f90_integer : \n{\nrange : %*d,\nnewtype : "
                  "%*d,\nerror/return : %*d\n}\n",
                  range, newtype, ret_tmp);
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

extern unsigned long long WI4MPI_Type_create_f90_real_timeout;
extern unsigned int WI4MPI_Type_create_f90_real_print;
void (*_LOCAL_MPI_Type_create_f90_real)(int *, int *, int *, int *);

void A_f_MPI_Type_create_f90_real(int *precision, int *range, int *newtype,
                                  int *ret) {
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
  if (WI4MPI_Type_create_f90_real_print)
    debug_printer("MPI_Type_create_f90_real : \n{\nprecision : %*d,\nrange : "
                  "%*d,\nnewtype : %*d,\nerror/return : %*d\n}\n",
                  precision, range, newtype, ret_tmp);
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

extern unsigned long long WI4MPI_Type_create_f90_complex_timeout;
extern unsigned int WI4MPI_Type_create_f90_complex_print;
void (*_LOCAL_MPI_Type_create_f90_complex)(int *, int *, int *, int *);

void A_f_MPI_Type_create_f90_complex(int *precision, int *range, int *newtype,
                                     int *ret) {
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
  if (WI4MPI_Type_create_f90_complex_print)
    debug_printer("MPI_Type_create_f90_complex : \n{\nprecision : %*d,\nrange "
                  ": %*d,\nnewtype : %*d,\nerror/return : %*d\n}\n",
                  precision, range, newtype, ret_tmp);
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

extern unsigned long long WI4MPI_Reduce_local_timeout;
extern unsigned int WI4MPI_Reduce_local_print;
void (*_LOCAL_MPI_Reduce_local)(void *, void *, int *, int *, int *, int *);

void A_f_MPI_Reduce_local(void *inbuf, void *inoutbuf, int *count,
                          int *datatype, int *op, int *ret) {
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
  if (WI4MPI_Reduce_local_print)
    debug_printer("MPI_Reduce_local : \n{\ninbuf : %*d,\ninoutbuf : "
                  "%*d,\ncount : %*d,\ndatatype : %*d,\nop : "
                  "%*d,\nerror/return : %*d\n}\n",
                  inbuf, inoutbuf, count, datatype, op, ret_tmp);
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

extern unsigned long long WI4MPI_Op_commutative_timeout;
extern unsigned int WI4MPI_Op_commutative_print;
void (*_LOCAL_MPI_Op_commutative)(int *, int *, int *);

void A_f_MPI_Op_commutative(int *op, int *commute, int *ret) {
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
  if (WI4MPI_Op_commutative_print)
    debug_printer("MPI_Op_commutative : \n{\nop : %*d,\ncommute : "
                  "%*d,\nerror/return : %*d\n}\n",
                  op, commute, ret_tmp);
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

extern unsigned long long WI4MPI_Reduce_scatter_block_timeout;
extern unsigned int WI4MPI_Reduce_scatter_block_print;
void (*_LOCAL_MPI_Reduce_scatter_block)(void *, void *, int *, int *, int *,
                                        int *, int *);

void A_f_MPI_Reduce_scatter_block(void *sendbuf, void *recvbuf, int *recvcount,
                                  int *datatype, int *op, int *comm, int *ret) {
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
  if (WI4MPI_Reduce_scatter_block_print)
    debug_printer("MPI_Reduce_scatter_block : \n{\nsendbuf : %*d,\nrecvbuf : "
                  "%*d,\nrecvcount : %*d,\ndatatype : %*d,\nop : %*d,\ncomm : "
                  "%*d,\nerror/return : %*d\n}\n",
                  sendbuf, recvbuf, recvcount, datatype, op, comm, ret_tmp);
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

extern unsigned long long WI4MPI_Dist_graph_neighbors_count_timeout;
extern unsigned int WI4MPI_Dist_graph_neighbors_count_print;
void (*_LOCAL_MPI_Dist_graph_neighbors_count)(int *, int *, int *, int *,
                                              int *);

void A_f_MPI_Dist_graph_neighbors_count(int *comm, int *indegree,
                                        int *outdegree, int *weighted,
                                        int *ret) {
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
  if (WI4MPI_Dist_graph_neighbors_count_print)
    debug_printer("MPI_Dist_graph_neighbors_count : \n{\ncomm : %*d,\nindegree "
                  ": %*d,\noutdegree : %*d,\nweighted : %*d,\nerror/return : "
                  "%*d\n}\n",
                  comm, indegree, outdegree, weighted, ret_tmp);
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

extern unsigned long long WI4MPI_Improbe_timeout;
extern unsigned int WI4MPI_Improbe_print;
void (*_LOCAL_MPI_Improbe)(int *, int *, int *, int *, int *, int *, int *);

void A_f_MPI_Improbe(int *source, int *tag, int *comm, int *flag, int *message,
                     int *status, int *ret) {
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
  if (WI4MPI_Improbe_print)
    debug_printer("MPI_Improbe : \n{\nsource : %*d,\ntag : %*d,\ncomm : "
                  "%*d,\nflag : %*d,\nmessage : %*d,\nstatus : "
                  "%S,\nerror/return : %*d\n}\n",
                  source, tag, comm, flag, message, status, ret_tmp);
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

extern unsigned long long WI4MPI_Imrecv_timeout;
extern unsigned int WI4MPI_Imrecv_print;
void (*_LOCAL_MPI_Imrecv)(void *, int *, int *, int *, int *, int *);

void A_f_MPI_Imrecv(void *buf, int *count, int *datatype, int *message,
                    int *request, int *ret) {
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
  if (WI4MPI_Imrecv_print)
    debug_printer("MPI_Imrecv : \n{\nbuf : %*d,\ncount : %*d,\ndatatype : "
                  "%*d,\nmessage : %*d,\nrequest : %*d,\nerror/return : "
                  "%*d\n}\n",
                  buf, count, datatype, message, request, ret_tmp);
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

extern unsigned long long WI4MPI_Mprobe_timeout;
extern unsigned int WI4MPI_Mprobe_print;
void (*_LOCAL_MPI_Mprobe)(int *, int *, int *, int *, int *, int *);

void A_f_MPI_Mprobe(int *source, int *tag, int *comm, int *message, int *status,
                    int *ret) {
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
  if (WI4MPI_Mprobe_print)
    debug_printer("MPI_Mprobe : \n{\nsource : %*d,\ntag : %*d,\ncomm : "
                  "%*d,\nmessage : %*d,\nstatus : %S,\nerror/return : %*d\n}\n",
                  source, tag, comm, message, status, ret_tmp);
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

extern unsigned long long WI4MPI_Mrecv_timeout;
extern unsigned int WI4MPI_Mrecv_print;
void (*_LOCAL_MPI_Mrecv)(void *, int *, int *, int *, int *, int *);

void A_f_MPI_Mrecv(void *buf, int *count, int *datatype, int *message,
                   int *status, int *ret) {
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
  if (WI4MPI_Mrecv_print)
    debug_printer("MPI_Mrecv : \n{\nbuf : %*d,\ncount : %*d,\ndatatype : "
                  "%*d,\nmessage : %*d,\nstatus : %S,\nerror/return : %*d\n}\n",
                  buf, count, datatype, message, status, ret_tmp);
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

extern unsigned long long WI4MPI_Comm_idup_timeout;
extern unsigned int WI4MPI_Comm_idup_print;
void (*_LOCAL_MPI_Comm_idup)(int *, int *, int *, int *);

void A_f_MPI_Comm_idup(int *comm, int *newcomm, int *request, int *ret) {
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
  if (WI4MPI_Comm_idup_print)
    debug_printer("MPI_Comm_idup : \n{\ncomm : %*d,\nnewcomm : %*d,\nrequest : "
                  "%*d,\nerror/return : %*d\n}\n",
                  comm, newcomm, request, ret_tmp);
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

extern unsigned long long WI4MPI_Ibarrier_timeout;
extern unsigned int WI4MPI_Ibarrier_print;
void (*_LOCAL_MPI_Ibarrier)(int *, int *, int *);

void A_f_MPI_Ibarrier(int *comm, int *request, int *ret) {
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
  if (WI4MPI_Ibarrier_print)
    debug_printer("MPI_Ibarrier : \n{\ncomm : %*d,\nrequest : "
                  "%*d,\nerror/return : %*d\n}\n",
                  comm, request, ret_tmp);
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

extern unsigned long long WI4MPI_Ibcast_timeout;
extern unsigned int WI4MPI_Ibcast_print;
void (*_LOCAL_MPI_Ibcast)(void *, int *, int *, int *, int *, int *, int *);

void A_f_MPI_Ibcast(void *buffer, int *count, int *datatype, int *root,
                    int *comm, int *request, int *ret) {
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
  if (WI4MPI_Ibcast_print)
    debug_printer("MPI_Ibcast : \n{\nbuffer : %*d,\ncount : %*d,\ndatatype : "
                  "%*d,\nroot : %*d,\ncomm : %*d,\nrequest : "
                  "%*d,\nerror/return : %*d\n}\n",
                  buffer, count, datatype, root, comm, request, ret_tmp);
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

extern unsigned long long WI4MPI_Igather_timeout;
extern unsigned int WI4MPI_Igather_print;
void (*_LOCAL_MPI_Igather)(void *, int *, int *, void *, int *, int *, int *,
                           int *, int *, int *);

void A_f_MPI_Igather(void *sendbuf, int *sendcount, int *sendtype,
                     void *recvbuf, int *recvcount, int *recvtype, int *root,
                     int *comm, int *request, int *ret) {
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
  if (WI4MPI_Igather_print)
    debug_printer("MPI_Igather : \n{\nsendbuf : %*d,\nsendcount : "
                  "%*d,\nsendtype : %*d,\nrecvbuf : %*d,\nrecvcount : "
                  "%*d,\nrecvtype : %*d,\nroot : %*d,\ncomm : %*d,\nrequest : "
                  "%*d,\nerror/return : %*d\n}\n",
                  sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype,
                  root, comm, request, ret_tmp);
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

extern unsigned long long WI4MPI_Iscatter_timeout;
extern unsigned int WI4MPI_Iscatter_print;
void (*_LOCAL_MPI_Iscatter)(void *, int *, int *, void *, int *, int *, int *,
                            int *, int *, int *);

void A_f_MPI_Iscatter(void *sendbuf, int *sendcount, int *sendtype,
                      void *recvbuf, int *recvcount, int *recvtype, int *root,
                      int *comm, int *request, int *ret) {
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
  if (WI4MPI_Iscatter_print)
    debug_printer("MPI_Iscatter : \n{\nsendbuf : %*d,\nsendcount : "
                  "%*d,\nsendtype : %*d,\nrecvbuf : %*d,\nrecvcount : "
                  "%*d,\nrecvtype : %*d,\nroot : %*d,\ncomm : %*d,\nrequest : "
                  "%*d,\nerror/return : %*d\n}\n",
                  sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype,
                  root, comm, request, ret_tmp);
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

extern unsigned long long WI4MPI_Iallgather_timeout;
extern unsigned int WI4MPI_Iallgather_print;
void (*_LOCAL_MPI_Iallgather)(void *, int *, int *, void *, int *, int *, int *,
                              int *, int *);

void A_f_MPI_Iallgather(void *sendbuf, int *sendcount, int *sendtype,
                        void *recvbuf, int *recvcount, int *recvtype, int *comm,
                        int *request, int *ret) {
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
  if (WI4MPI_Iallgather_print)
    debug_printer("MPI_Iallgather : \n{\nsendbuf : %*d,\nsendcount : "
                  "%*d,\nsendtype : %*d,\nrecvbuf : %*d,\nrecvcount : "
                  "%*d,\nrecvtype : %*d,\ncomm : %*d,\nrequest : "
                  "%*d,\nerror/return : %*d\n}\n",
                  sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype,
                  comm, request, ret_tmp);
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

extern unsigned long long WI4MPI_Ialltoall_timeout;
extern unsigned int WI4MPI_Ialltoall_print;
void (*_LOCAL_MPI_Ialltoall)(void *, int *, int *, void *, int *, int *, int *,
                             int *, int *);

void A_f_MPI_Ialltoall(void *sendbuf, int *sendcount, int *sendtype,
                       void *recvbuf, int *recvcount, int *recvtype, int *comm,
                       int *request, int *ret) {
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
  if (WI4MPI_Ialltoall_print)
    debug_printer("MPI_Ialltoall : \n{\nsendbuf : %*d,\nsendcount : "
                  "%*d,\nsendtype : %*d,\nrecvbuf : %*d,\nrecvcount : "
                  "%*d,\nrecvtype : %*d,\ncomm : %*d,\nrequest : "
                  "%*d,\nerror/return : %*d\n}\n",
                  sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype,
                  comm, request, ret_tmp);
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

extern unsigned long long WI4MPI_Ireduce_timeout;
extern unsigned int WI4MPI_Ireduce_print;
void (*_LOCAL_MPI_Ireduce)(void *, void *, int *, int *, int *, int *, int *,
                           int *, int *);

void A_f_MPI_Ireduce(void *sendbuf, void *recvbuf, int *count, int *datatype,
                     int *op, int *root, int *comm, int *request, int *ret) {
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
  if (WI4MPI_Ireduce_print)
    debug_printer("MPI_Ireduce : \n{\nsendbuf : %*d,\nrecvbuf : %*d,\ncount : "
                  "%*d,\ndatatype : %*d,\nop : %*d,\nroot : %*d,\ncomm : "
                  "%*d,\nrequest : %*d,\nerror/return : %*d\n}\n",
                  sendbuf, recvbuf, count, datatype, op, root, comm, request,
                  ret_tmp);
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

extern unsigned long long WI4MPI_Iallreduce_timeout;
extern unsigned int WI4MPI_Iallreduce_print;
void (*_LOCAL_MPI_Iallreduce)(void *, void *, int *, int *, int *, int *, int *,
                              int *);

void A_f_MPI_Iallreduce(void *sendbuf, void *recvbuf, int *count, int *datatype,
                        int *op, int *comm, int *request, int *ret) {
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
  if (WI4MPI_Iallreduce_print)
    debug_printer("MPI_Iallreduce : \n{\nsendbuf : %*d,\nrecvbuf : %*d,\ncount "
                  ": %*d,\ndatatype : %*d,\nop : %*d,\ncomm : %*d,\nrequest : "
                  "%*d,\nerror/return : %*d\n}\n",
                  sendbuf, recvbuf, count, datatype, op, comm, request,
                  ret_tmp);
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

extern unsigned long long WI4MPI_Ireduce_scatter_block_timeout;
extern unsigned int WI4MPI_Ireduce_scatter_block_print;
void (*_LOCAL_MPI_Ireduce_scatter_block)(void *, void *, int *, int *, int *,
                                         int *, int *, int *);

void A_f_MPI_Ireduce_scatter_block(void *sendbuf, void *recvbuf, int *recvcount,
                                   int *datatype, int *op, int *comm,
                                   int *request, int *ret) {
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
  if (WI4MPI_Ireduce_scatter_block_print)
    debug_printer("MPI_Ireduce_scatter_block : \n{\nsendbuf : %*d,\nrecvbuf : "
                  "%*d,\nrecvcount : %*d,\ndatatype : %*d,\nop : %*d,\ncomm : "
                  "%*d,\nrequest : %*d,\nerror/return : %*d\n}\n",
                  sendbuf, recvbuf, recvcount, datatype, op, comm, request,
                  ret_tmp);
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

extern unsigned long long WI4MPI_Iscan_timeout;
extern unsigned int WI4MPI_Iscan_print;
void (*_LOCAL_MPI_Iscan)(void *, void *, int *, int *, int *, int *, int *,
                         int *);

void A_f_MPI_Iscan(void *sendbuf, void *recvbuf, int *count, int *datatype,
                   int *op, int *comm, int *request, int *ret) {
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
  if (WI4MPI_Iscan_print)
    debug_printer("MPI_Iscan : \n{\nsendbuf : %*d,\nrecvbuf : %*d,\ncount : "
                  "%*d,\ndatatype : %*d,\nop : %*d,\ncomm : %*d,\nrequest : "
                  "%*d,\nerror/return : %*d\n}\n",
                  sendbuf, recvbuf, count, datatype, op, comm, request,
                  ret_tmp);
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

extern unsigned long long WI4MPI_Iexscan_timeout;
extern unsigned int WI4MPI_Iexscan_print;
void (*_LOCAL_MPI_Iexscan)(void *, void *, int *, int *, int *, int *, int *,
                           int *);

void A_f_MPI_Iexscan(void *sendbuf, void *recvbuf, int *count, int *datatype,
                     int *op, int *comm, int *request, int *ret) {
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
  if (WI4MPI_Iexscan_print)
    debug_printer("MPI_Iexscan : \n{\nsendbuf : %*d,\nrecvbuf : %*d,\ncount : "
                  "%*d,\ndatatype : %*d,\nop : %*d,\ncomm : %*d,\nrequest : "
                  "%*d,\nerror/return : %*d\n}\n",
                  sendbuf, recvbuf, count, datatype, op, comm, request,
                  ret_tmp);
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

extern unsigned long long WI4MPI_Ineighbor_allgather_timeout;
extern unsigned int WI4MPI_Ineighbor_allgather_print;
void (*_LOCAL_MPI_Ineighbor_allgather)(void *, int *, int *, void *, int *,
                                       int *, int *, int *, int *);

void A_f_MPI_Ineighbor_allgather(void *sendbuf, int *sendcount, int *sendtype,
                                 void *recvbuf, int *recvcount, int *recvtype,
                                 int *comm, int *request, int *ret) {
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
  if (WI4MPI_Ineighbor_allgather_print)
    debug_printer("MPI_Ineighbor_allgather : \n{\nsendbuf : %*d,\nsendcount : "
                  "%*d,\nsendtype : %*d,\nrecvbuf : %*d,\nrecvcount : "
                  "%*d,\nrecvtype : %*d,\ncomm : %*d,\nrequest : "
                  "%*d,\nerror/return : %*d\n}\n",
                  sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype,
                  comm, request, ret_tmp);
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

extern unsigned long long WI4MPI_Ineighbor_alltoall_timeout;
extern unsigned int WI4MPI_Ineighbor_alltoall_print;
void (*_LOCAL_MPI_Ineighbor_alltoall)(void *, int *, int *, void *, int *,
                                      int *, int *, int *, int *);

void A_f_MPI_Ineighbor_alltoall(void *sendbuf, int *sendcount, int *sendtype,
                                void *recvbuf, int *recvcount, int *recvtype,
                                int *comm, int *request, int *ret) {
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
  if (WI4MPI_Ineighbor_alltoall_print)
    debug_printer("MPI_Ineighbor_alltoall : \n{\nsendbuf : %*d,\nsendcount : "
                  "%*d,\nsendtype : %*d,\nrecvbuf : %*d,\nrecvcount : "
                  "%*d,\nrecvtype : %*d,\ncomm : %*d,\nrequest : "
                  "%*d,\nerror/return : %*d\n}\n",
                  sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype,
                  comm, request, ret_tmp);
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

extern unsigned long long WI4MPI_Neighbor_allgather_timeout;
extern unsigned int WI4MPI_Neighbor_allgather_print;
void (*_LOCAL_MPI_Neighbor_allgather)(void *, int *, int *, void *, int *,
                                      int *, int *, int *);

void A_f_MPI_Neighbor_allgather(void *sendbuf, int *sendcount, int *sendtype,
                                void *recvbuf, int *recvcount, int *recvtype,
                                int *comm, int *ret) {
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
  if (WI4MPI_Neighbor_allgather_print)
    debug_printer("MPI_Neighbor_allgather : \n{\nsendbuf : %*d,\nsendcount : "
                  "%*d,\nsendtype : %*d,\nrecvbuf : %*d,\nrecvcount : "
                  "%*d,\nrecvtype : %*d,\ncomm : %*d,\nerror/return : %*d\n}\n",
                  sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype,
                  comm, ret_tmp);
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

extern unsigned long long WI4MPI_Neighbor_alltoall_timeout;
extern unsigned int WI4MPI_Neighbor_alltoall_print;
void (*_LOCAL_MPI_Neighbor_alltoall)(void *, int *, int *, void *, int *, int *,
                                     int *, int *);

void A_f_MPI_Neighbor_alltoall(void *sendbuf, int *sendcount, int *sendtype,
                               void *recvbuf, int *recvcount, int *recvtype,
                               int *comm, int *ret) {
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
  if (WI4MPI_Neighbor_alltoall_print)
    debug_printer("MPI_Neighbor_alltoall : \n{\nsendbuf : %*d,\nsendcount : "
                  "%*d,\nsendtype : %*d,\nrecvbuf : %*d,\nrecvcount : "
                  "%*d,\nrecvtype : %*d,\ncomm : %*d,\nerror/return : %*d\n}\n",
                  sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype,
                  comm, ret_tmp);
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

extern unsigned long long WI4MPI_Comm_split_type_timeout;
extern unsigned int WI4MPI_Comm_split_type_print;
void (*_LOCAL_MPI_Comm_split_type)(int *, int *, int *, int *, int *, int *);

void A_f_MPI_Comm_split_type(int *comm, int *split_type, int *key, int *info,
                             int *newcomm, int *ret) {
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
  if (WI4MPI_Comm_split_type_print)
    debug_printer("MPI_Comm_split_type : \n{\ncomm : %*d,\nsplit_type : "
                  "%*d,\nkey : %*d,\ninfo : %*d,\nnewcomm : %*d,\nerror/return "
                  ": %*d\n}\n",
                  comm, split_type, key, info, newcomm, ret_tmp);
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

extern unsigned long long WI4MPI_Get_elements_x_timeout;
extern unsigned int WI4MPI_Get_elements_x_print;
void (*_LOCAL_MPI_Get_elements_x)(int *, int *, int *, int *);

void A_f_MPI_Get_elements_x(int *status, int *datatype, int *count, int *ret) {
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
  if (WI4MPI_Get_elements_x_print)
    debug_printer("MPI_Get_elements_x : \n{\nstatus : %S,\ndatatype : "
                  "%*d,\ncount : %*d,\nerror/return : %*d\n}\n",
                  status, datatype, count, ret_tmp);
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

extern unsigned long long WI4MPI_Status_set_elements_x_timeout;
extern unsigned int WI4MPI_Status_set_elements_x_print;
void (*_LOCAL_MPI_Status_set_elements_x)(int *, int *, int *, int *);

void A_f_MPI_Status_set_elements_x(int *status, int *datatype, int *count,
                                   int *ret) {
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
  if (WI4MPI_Status_set_elements_x_print)
    debug_printer("MPI_Status_set_elements_x : \n{\nstatus : %S,\ndatatype : "
                  "%*d,\ncount : %*d,\nerror/return : %*d\n}\n",
                  status, datatype, count, ret_tmp);
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

extern unsigned long long WI4MPI_Type_get_extent_x_timeout;
extern unsigned int WI4MPI_Type_get_extent_x_print;
void (*_LOCAL_MPI_Type_get_extent_x)(int *, int *, int *, int *);

void A_f_MPI_Type_get_extent_x(int *datatype, int *lb, int *extent, int *ret) {
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
  if (WI4MPI_Type_get_extent_x_print)
    debug_printer("MPI_Type_get_extent_x : \n{\ndatatype : %*d,\nlb : "
                  "%*d,\nextent : %*d,\nerror/return : %*d\n}\n",
                  datatype, lb, extent, ret_tmp);
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

extern unsigned long long WI4MPI_Type_get_true_extent_x_timeout;
extern unsigned int WI4MPI_Type_get_true_extent_x_print;
void (*_LOCAL_MPI_Type_get_true_extent_x)(int *, int *, int *, int *);

void A_f_MPI_Type_get_true_extent_x(int *datatype, int *lb, int *extent,
                                    int *ret) {
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
  if (WI4MPI_Type_get_true_extent_x_print)
    debug_printer("MPI_Type_get_true_extent_x : \n{\ndatatype : %*d,\nlb : "
                  "%*d,\nextent : %*d,\nerror/return : %*d\n}\n",
                  datatype, lb, extent, ret_tmp);
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

extern unsigned long long WI4MPI_Type_size_x_timeout;
extern unsigned int WI4MPI_Type_size_x_print;
void (*_LOCAL_MPI_Type_size_x)(int *, int *, int *);

void A_f_MPI_Type_size_x(int *datatype, int *size, int *ret) {
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
  if (WI4MPI_Type_size_x_print)
    debug_printer("MPI_Type_size_x : \n{\ndatatype : %*d,\nsize : "
                  "%*d,\nerror/return : %*d\n}\n",
                  datatype, size, ret_tmp);
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

extern unsigned long long WI4MPI_Comm_create_group_timeout;
extern unsigned int WI4MPI_Comm_create_group_print;
void (*_LOCAL_MPI_Comm_create_group)(int *, int *, int *, int *, int *);

void A_f_MPI_Comm_create_group(int *comm, int *group, int *tag, int *newcomm,
                               int *ret) {
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
  if (WI4MPI_Comm_create_group_print)
    debug_printer("MPI_Comm_create_group : \n{\ncomm : %*d,\ngroup : %*d,\ntag "
                  ": %*d,\nnewcomm : %*d,\nerror/return : %*d\n}\n",
                  comm, group, tag, newcomm, ret_tmp);
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

extern unsigned long long WI4MPI_File_close_timeout;
extern unsigned int WI4MPI_File_close_print;
void (*_LOCAL_MPI_File_close)(int *, int *);

void A_f_MPI_File_close(int *fh, int *ret) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_close_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_File_close(fh, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_File_close_print)
    debug_printer("MPI_File_close : \n{\nfh : %*d,\nerror/return : %*d\n}\n",
                  fh, ret_tmp);
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

extern unsigned long long WI4MPI_File_set_size_timeout;
extern unsigned int WI4MPI_File_set_size_print;
void (*_LOCAL_MPI_File_set_size)(int *, int *, int *);

void A_f_MPI_File_set_size(int *fh, int *size, int *ret) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_set_size_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_File_set_size(fh, size, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_File_set_size_print)
    debug_printer("MPI_File_set_size : \n{\nfh : %*d,\nsize : "
                  "%*d,\nerror/return : %*d\n}\n",
                  fh, size, ret_tmp);
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

extern unsigned long long WI4MPI_File_preallocate_timeout;
extern unsigned int WI4MPI_File_preallocate_print;
void (*_LOCAL_MPI_File_preallocate)(int *, int *, int *);

void A_f_MPI_File_preallocate(int *fh, int *size, int *ret) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_preallocate_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_File_preallocate(fh, size, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_File_preallocate_print)
    debug_printer("MPI_File_preallocate : \n{\nfh : %*d,\nsize : "
                  "%*d,\nerror/return : %*d\n}\n",
                  fh, size, ret_tmp);
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

extern unsigned long long WI4MPI_File_get_size_timeout;
extern unsigned int WI4MPI_File_get_size_print;
void (*_LOCAL_MPI_File_get_size)(int *, int *, int *);

void A_f_MPI_File_get_size(int *fh, int *size, int *ret) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_get_size_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_File_get_size(fh, size, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_File_get_size_print)
    debug_printer("MPI_File_get_size : \n{\nfh : %*d,\nsize : "
                  "%*d,\nerror/return : %*d\n}\n",
                  fh, size, ret_tmp);
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

extern unsigned long long WI4MPI_File_get_group_timeout;
extern unsigned int WI4MPI_File_get_group_print;
void (*_LOCAL_MPI_File_get_group)(int *, int *, int *);

void A_f_MPI_File_get_group(int *fh, int *group, int *ret) {
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
  if (WI4MPI_File_get_group_print)
    debug_printer("MPI_File_get_group : \n{\nfh : %*d,\ngroup : "
                  "%*d,\nerror/return : %*d\n}\n",
                  fh, group, ret_tmp);
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

extern unsigned long long WI4MPI_File_get_amode_timeout;
extern unsigned int WI4MPI_File_get_amode_print;
void (*_LOCAL_MPI_File_get_amode)(int *, int *, int *);

void A_f_MPI_File_get_amode(int *fh, int *amode, int *ret) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_get_amode_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_File_get_amode(fh, amode, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_File_get_amode_print)
    debug_printer("MPI_File_get_amode : \n{\nfh : %*d,\namode : "
                  "%*d,\nerror/return : %*d\n}\n",
                  fh, amode, ret_tmp);
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

extern unsigned long long WI4MPI_File_set_info_timeout;
extern unsigned int WI4MPI_File_set_info_print;
void (*_LOCAL_MPI_File_set_info)(int *, int *, int *);

void A_f_MPI_File_set_info(int *fh, int *info, int *ret) {
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
  if (WI4MPI_File_set_info_print)
    debug_printer("MPI_File_set_info : \n{\nfh : %*d,\ninfo : "
                  "%*d,\nerror/return : %*d\n}\n",
                  fh, info, ret_tmp);
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

extern unsigned long long WI4MPI_File_get_info_timeout;
extern unsigned int WI4MPI_File_get_info_print;
void (*_LOCAL_MPI_File_get_info)(int *, int *, int *);

void A_f_MPI_File_get_info(int *fh, int *info_used, int *ret) {
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
  if (WI4MPI_File_get_info_print)
    debug_printer("MPI_File_get_info : \n{\nfh : %*d,\ninfo_used : "
                  "%*d,\nerror/return : %*d\n}\n",
                  fh, info_used, ret_tmp);
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

extern unsigned long long WI4MPI_File_read_at_timeout;
extern unsigned int WI4MPI_File_read_at_print;
void (*_LOCAL_MPI_File_read_at)(int *, int *, void *, int *, int *, int *,
                                int *);

void A_f_MPI_File_read_at(int *fh, int *offset, void *buf, int *count,
                          int *datatype, int *status, int *ret) {
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
  if (WI4MPI_File_read_at_print)
    debug_printer("MPI_File_read_at : \n{\nfh : %*d,\noffset : %*d,\nbuf : "
                  "%*d,\ncount : %*d,\ndatatype : %*d,\nstatus : "
                  "%S,\nerror/return : %*d\n}\n",
                  fh, offset, buf, count, datatype, status, ret_tmp);
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

extern unsigned long long WI4MPI_File_read_at_all_timeout;
extern unsigned int WI4MPI_File_read_at_all_print;
void (*_LOCAL_MPI_File_read_at_all)(int *, int *, void *, int *, int *, int *,
                                    int *);

void A_f_MPI_File_read_at_all(int *fh, int *offset, void *buf, int *count,
                              int *datatype, int *status, int *ret) {
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
  if (WI4MPI_File_read_at_all_print)
    debug_printer("MPI_File_read_at_all : \n{\nfh : %*d,\noffset : %*d,\n buf "
                  ": %*d,\ncount : %*d,\ndatatype : %*d,\nstatus : "
                  "%S,\nerror/return : %*d\n}\n",
                  fh, offset, buf, count, datatype, status, ret_tmp);
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

extern unsigned long long WI4MPI_File_write_at_timeout;
extern unsigned int WI4MPI_File_write_at_print;
void (*_LOCAL_MPI_File_write_at)(int *, int *, void *, int *, int *, int *,
                                 int *);

void A_f_MPI_File_write_at(int *fh, int *offset, void *buf, int *count,
                           int *datatype, int *status, int *ret) {
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
  if (WI4MPI_File_write_at_print)
    debug_printer("MPI_File_write_at : \n{\nfh : %*d,\noffset : %*d,\n buf : "
                  "%*d,\ncount : %*d,\ndatatype : %*d,\nstatus : "
                  "%S,\nerror/return : %*d\n}\n",
                  fh, offset, buf, count, datatype, status, ret_tmp);
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

extern unsigned long long WI4MPI_File_write_at_all_timeout;
extern unsigned int WI4MPI_File_write_at_all_print;
void (*_LOCAL_MPI_File_write_at_all)(int *, int *, void *, int *, int *, int *,
                                     int *);

void A_f_MPI_File_write_at_all(int *fh, int *offset, void *buf, int *count,
                               int *datatype, int *status, int *ret) {
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
  if (WI4MPI_File_write_at_all_print)
    debug_printer("MPI_File_write_at_all : \n{\nfh : %*d,\noffset : %*d,\nbuf "
                  ": %*d,\ncount : %*d,\ndatatype : %*d,\nstatus : "
                  "%S,\nerror/return : %*d\n}\n",
                  fh, offset, buf, count, datatype, status, ret_tmp);
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

extern unsigned long long WI4MPI_File_iread_at_timeout;
extern unsigned int WI4MPI_File_iread_at_print;
void (*_LOCAL_MPI_File_iread_at)(int *, int *, void *, int *, int *, int *,
                                 int *);

void A_f_MPI_File_iread_at(int *fh, int *offset, void *buf, int *count,
                           int *datatype, int *request, int *ret) {
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
  if (WI4MPI_File_iread_at_print)
    debug_printer("MPI_File_iread_at : \n{\nfh : %*d,\noffset : %*d,\nbuf : "
                  "%*d,\ncount : %*d,\ndatatype : %*d,\nrequest : "
                  "%*d,\nerror/return : %*d\n}\n",
                  fh, offset, buf, count, datatype, request, ret_tmp);
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

extern unsigned long long WI4MPI_File_iwrite_at_timeout;
extern unsigned int WI4MPI_File_iwrite_at_print;
void (*_LOCAL_MPI_File_iwrite_at)(int *, int *, void *, int *, int *, int *,
                                  int *);

void A_f_MPI_File_iwrite_at(int *fh, int *offset, void *buf, int *count,
                            int *datatype, int *request, int *ret) {
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
  if (WI4MPI_File_iwrite_at_print)
    debug_printer("MPI_File_iwrite_at : \n{\nfh : %*d,\noffset : %*d,\nbuf : "
                  "%*d,\ncount : %*d,\ndatatype : %*d,\nrequest : "
                  "%*d,\nerror/return : %*d\n}\n",
                  fh, offset, buf, count, datatype, request, ret_tmp);
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

extern unsigned long long WI4MPI_File_read_timeout;
extern unsigned int WI4MPI_File_read_print;
void (*_LOCAL_MPI_File_read)(int *, void *, int *, int *, int *, int *);

void A_f_MPI_File_read(int *fh, void *buf, int *count, int *datatype,
                       int *status, int *ret) {
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
  if (WI4MPI_File_read_print)
    debug_printer("MPI_File_read : \n{\nfh : %*d,\nbuf : %*d,\ncount : "
                  "%*d,\ndatatype : %*d,\nstatus : %S,\nerror/return : "
                  "%*d\n}\n",
                  fh, buf, count, datatype, status, ret_tmp);
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

extern unsigned long long WI4MPI_File_read_all_timeout;
extern unsigned int WI4MPI_File_read_all_print;
void (*_LOCAL_MPI_File_read_all)(int *, void *, int *, int *, int *, int *);

void A_f_MPI_File_read_all(int *fh, void *buf, int *count, int *datatype,
                           int *status, int *ret) {
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
  if (WI4MPI_File_read_all_print)
    debug_printer("MPI_File_read_all : \n{\nfh : %*d,\nbuf : %*d,\ncount : "
                  "%*d,\ndatatype : %*d,\nstatus : %S,\nerror/return : "
                  "%*d\n}\n",
                  fh, buf, count, datatype, status, ret_tmp);
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

extern unsigned long long WI4MPI_File_write_timeout;
extern unsigned int WI4MPI_File_write_print;
void (*_LOCAL_MPI_File_write)(int *, void *, int *, int *, int *, int *);

void A_f_MPI_File_write(int *fh, void *buf, int *count, int *datatype,
                        int *status, int *ret) {
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
  if (WI4MPI_File_write_print)
    debug_printer("MPI_File_write : \n{\nfh : %*d,\nbuf : %*d,\ncount : "
                  "%*d,\ndatatype : %*d,\nstatus : %S,\nerror/return : "
                  "%*d\n}\n",
                  fh, buf, count, datatype, status, ret_tmp);
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

extern unsigned long long WI4MPI_File_write_all_timeout;
extern unsigned int WI4MPI_File_write_all_print;
void (*_LOCAL_MPI_File_write_all)(int *, void *, int *, int *, int *, int *);

void A_f_MPI_File_write_all(int *fh, void *buf, int *count, int *datatype,
                            int *status, int *ret) {
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
  if (WI4MPI_File_write_all_print)
    debug_printer("MPI_File_write_all : \n{\nfh : %*d,\nbuf : %*d,\ncount : "
                  "%*d,\ndatatype : %*d,\nstatus : %S,\nerror/return : "
                  "%*d\n}\n",
                  fh, buf, count, datatype, status, ret_tmp);
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

extern unsigned long long WI4MPI_File_iread_timeout;
extern unsigned int WI4MPI_File_iread_print;
void (*_LOCAL_MPI_File_iread)(int *, void *, int *, int *, int *, int *);

void A_f_MPI_File_iread(int *fh, void *buf, int *count, int *datatype,
                        int *request, int *ret) {
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
  if (WI4MPI_File_iread_print)
    debug_printer("MPI_File_iread : \n{\nfh : %*d,\nbuf : %*d,\ncount : "
                  "%*d,\ndatatype : %*d,\nrequest : %*d,\nerror/return : "
                  "%*d\n}\n",
                  fh, buf, count, datatype, request, ret_tmp);
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

extern unsigned long long WI4MPI_File_iwrite_timeout;
extern unsigned int WI4MPI_File_iwrite_print;
void (*_LOCAL_MPI_File_iwrite)(int *, void *, int *, int *, int *, int *);

void A_f_MPI_File_iwrite(int *fh, void *buf, int *count, int *datatype,
                         int *request, int *ret) {
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
  if (WI4MPI_File_iwrite_print)
    debug_printer("MPI_File_iwrite : \n{\nfh : %*d,\nbuf : %*d,\ncount : "
                  "%*d,\ndatatype : %*d,\nrequest : %*d,\nerror/return : "
                  "%*d\n}\n",
                  fh, buf, count, datatype, request, ret_tmp);
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

extern unsigned long long WI4MPI_File_seek_timeout;
extern unsigned int WI4MPI_File_seek_print;
void (*_LOCAL_MPI_File_seek)(int *, int *, int *, int *);

void A_f_MPI_File_seek(int *fh, int *offset, int *whence, int *ret) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_seek_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_File_seek(fh, offset, whence, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_File_seek_print)
    debug_printer("MPI_File_seek : \n{\nfh : %*d,\noffset : %*d,\nwhence : "
                  "%*d,\nerror/return : %*d\n}\n",
                  fh, offset, whence, ret_tmp);
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

extern unsigned long long WI4MPI_File_get_position_timeout;
extern unsigned int WI4MPI_File_get_position_print;
void (*_LOCAL_MPI_File_get_position)(int *, int *, int *);

void A_f_MPI_File_get_position(int *fh, int *offset, int *ret) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_get_position_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_File_get_position(fh, offset, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_File_get_position_print)
    debug_printer("MPI_File_get_position : \n{\nfh : %*d,\noffset : "
                  "%*d,\nerror/return : %*d\n}\n",
                  fh, offset, ret_tmp);
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

extern unsigned long long WI4MPI_File_get_byte_offset_timeout;
extern unsigned int WI4MPI_File_get_byte_offset_print;
void (*_LOCAL_MPI_File_get_byte_offset)(int *, int *, int *, int *);

void A_f_MPI_File_get_byte_offset(int *fh, int *offset, int *disp, int *ret) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_get_byte_offset_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_File_get_byte_offset(fh, offset, disp, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_File_get_byte_offset_print)
    debug_printer("MPI_File_get_byte_offset : \n{\nfh : %*d,\noffset : "
                  "%*d,\ndisp : %*d,\nerror/return : %*d\n}\n",
                  fh, offset, disp, ret_tmp);
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

extern unsigned long long WI4MPI_File_read_shared_timeout;
extern unsigned int WI4MPI_File_read_shared_print;
void (*_LOCAL_MPI_File_read_shared)(int *, void *, int *, int *, int *, int *);

void A_f_MPI_File_read_shared(int *fh, void *buf, int *count, int *datatype,
                              int *status, int *ret) {
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
  if (WI4MPI_File_read_shared_print)
    debug_printer("MPI_File_read_shared : \n{\nfh : %*d,\nbuf : %*d,\ncount : "
                  "%*d,\ndatatype : %*d,\nstatus : %S,\nerror/return : "
                  "%*d\n}\n",
                  fh, buf, count, datatype, status, ret_tmp);
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

extern unsigned long long WI4MPI_File_write_shared_timeout;
extern unsigned int WI4MPI_File_write_shared_print;
void (*_LOCAL_MPI_File_write_shared)(int *, void *, int *, int *, int *, int *);

void A_f_MPI_File_write_shared(int *fh, void *buf, int *count, int *datatype,
                               int *status, int *ret) {
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
  if (WI4MPI_File_write_shared_print)
    debug_printer("MPI_File_write_shared : \n{\nfh : %*d,\nbuf : %*d,\ncount : "
                  "%*d,\ndatatype : %*d,\nstatus : %S,\nerror/return : "
                  "%*d\n}\n",
                  fh, buf, count, datatype, status, ret_tmp);
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

extern unsigned long long WI4MPI_File_iread_shared_timeout;
extern unsigned int WI4MPI_File_iread_shared_print;
void (*_LOCAL_MPI_File_iread_shared)(int *, void *, int *, int *, int *, int *);

void A_f_MPI_File_iread_shared(int *fh, void *buf, int *count, int *datatype,
                               int *request, int *ret) {
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
  if (WI4MPI_File_iread_shared_print)
    debug_printer("MPI_File_iread_shared : \n{\nfh : %*d,\nbuf : %*d,\ncount : "
                  "%*d,\ndatatype : %*d,\nrequest : %*d,\nerror/return : "
                  "%*d\n}\n",
                  fh, buf, count, datatype, request, ret_tmp);
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

extern unsigned long long WI4MPI_File_iwrite_shared_timeout;
extern unsigned int WI4MPI_File_iwrite_shared_print;
void (*_LOCAL_MPI_File_iwrite_shared)(int *, void *, int *, int *, int *,
                                      int *);

void A_f_MPI_File_iwrite_shared(int *fh, void *buf, int *count, int *datatype,
                                int *request, int *ret) {
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
  if (WI4MPI_File_iwrite_shared_print)
    debug_printer("MPI_File_iwrite_shared : \n{\nfh : %*d,\nbuf : %*d,\ncount "
                  ": %*d,\ndatatype : %*d,\nrequest : %*d,\nerror/return : "
                  "%*d\n}\n",
                  fh, buf, count, datatype, request, ret_tmp);
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

extern unsigned long long WI4MPI_File_read_ordered_timeout;
extern unsigned int WI4MPI_File_read_ordered_print;
void (*_LOCAL_MPI_File_read_ordered)(int *, void *, int *, int *, int *, int *);

void A_f_MPI_File_read_ordered(int *fh, void *buf, int *count, int *datatype,
                               int *status, int *ret) {
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
  if (WI4MPI_File_read_ordered_print)
    debug_printer("MPI_File_read_ordered : \n{\nfh : %*d,\nbuf : %*d,\ncount : "
                  "%*d,\ndatatype : %*d,\nstatus : %S,\nerror/return : "
                  "%*d\n}\n",
                  fh, buf, count, datatype, status, ret_tmp);
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

extern unsigned long long WI4MPI_File_write_ordered_timeout;
extern unsigned int WI4MPI_File_write_ordered_print;
void (*_LOCAL_MPI_File_write_ordered)(int *, void *, int *, int *, int *,
                                      int *);

void A_f_MPI_File_write_ordered(int *fh, void *buf, int *count, int *datatype,
                                int *status, int *ret) {
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
  if (WI4MPI_File_write_ordered_print)
    debug_printer("MPI_File_write_ordered : \n{\nfh : %*d,\nbuf : %*d,\ncount "
                  ": %*d,\ndatatype : %*d,\nstatus : %S,\nerror/return : "
                  "%*d\n}\n",
                  fh, buf, count, datatype, status, ret_tmp);
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

extern unsigned long long WI4MPI_File_seek_shared_timeout;
extern unsigned int WI4MPI_File_seek_shared_print;
void (*_LOCAL_MPI_File_seek_shared)(int *, int *, int *, int *);

void A_f_MPI_File_seek_shared(int *fh, int *offset, int *whence, int *ret) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_seek_shared_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_File_seek_shared(fh, offset, whence, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_File_seek_shared_print)
    debug_printer("MPI_File_seek_shared : \n{\nfh : %*d,\noffset : "
                  "%*d,\nwhence : %*d,\nerror/return : %*d\n}\n",
                  fh, offset, whence, ret_tmp);
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

extern unsigned long long WI4MPI_File_get_position_shared_timeout;
extern unsigned int WI4MPI_File_get_position_shared_print;
void (*_LOCAL_MPI_File_get_position_shared)(int *, int *, int *);

void A_f_MPI_File_get_position_shared(int *fh, int *offset, int *ret) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_get_position_shared_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_File_get_position_shared(fh, offset, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_File_get_position_shared_print)
    debug_printer("MPI_File_get_position_shared : \n{\nfh : %*d,\noffset : "
                  "%*d,\nerror/return : %*d\n}\n",
                  fh, offset, ret_tmp);
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

extern unsigned long long WI4MPI_File_read_at_all_begin_timeout;
extern unsigned int WI4MPI_File_read_at_all_begin_print;
void (*_LOCAL_MPI_File_read_at_all_begin)(int *, int *, void *, int *, int *,
                                          int *);

void A_f_MPI_File_read_at_all_begin(int *fh, int *offset, void *buf, int *count,
                                    int *datatype, int *ret) {
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
  if (WI4MPI_File_read_at_all_begin_print)
    debug_printer("MPI_File_read_at_all_begin : \n{\nfh : %*d,\noffset : "
                  "%*d,\nbuf : %*d,\ncount : %*d,\ndatatype : "
                  "%*d,\nerror/return : %*d\n}\n",
                  fh, offset, buf, count, datatype, ret_tmp);
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

extern unsigned long long WI4MPI_File_read_at_all_end_timeout;
extern unsigned int WI4MPI_File_read_at_all_end_print;
void (*_LOCAL_MPI_File_read_at_all_end)(int *, void *, int *, int *);

void A_f_MPI_File_read_at_all_end(int *fh, void *buf, int *status, int *ret) {
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
  if (WI4MPI_File_read_at_all_end_print)
    debug_printer("MPI_File_read_at_all_end : \n{\nfh : %*d,\nbuf : "
                  "%*d,\nstatus : %S,\nerror/return : %*d\n}\n",
                  fh, buf, status, ret_tmp);
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

extern unsigned long long WI4MPI_File_write_at_all_begin_timeout;
extern unsigned int WI4MPI_File_write_at_all_begin_print;
void (*_LOCAL_MPI_File_write_at_all_begin)(int *, int *, void *, int *, int *,
                                           int *);

void A_f_MPI_File_write_at_all_begin(int *fh, int *offset, void *buf,
                                     int *count, int *datatype, int *ret) {
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
  if (WI4MPI_File_write_at_all_begin_print)
    debug_printer("MPI_File_write_at_all_begin : \n{\nfh : %*d,\noffset : "
                  "%*d,\nbuf : %*d,\ncount : %*d,\ndatatype : "
                  "%*d,\nerror/return : %*d\n}\n",
                  fh, offset, buf, count, datatype, ret_tmp);
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

extern unsigned long long WI4MPI_File_write_at_all_end_timeout;
extern unsigned int WI4MPI_File_write_at_all_end_print;
void (*_LOCAL_MPI_File_write_at_all_end)(int *, void *, int *, int *);

void A_f_MPI_File_write_at_all_end(int *fh, void *buf, int *status, int *ret) {
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
  if (WI4MPI_File_write_at_all_end_print)
    debug_printer("MPI_File_write_at_all_end : \n{\nfh : %*d,\nbuf : "
                  "%*d,\nstatus : %S,\nerror/return : %*d\n}\n",
                  fh, buf, status, ret_tmp);
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

extern unsigned long long WI4MPI_File_read_all_begin_timeout;
extern unsigned int WI4MPI_File_read_all_begin_print;
void (*_LOCAL_MPI_File_read_all_begin)(int *, void *, int *, int *, int *);

void A_f_MPI_File_read_all_begin(int *fh, void *buf, int *count, int *datatype,
                                 int *ret) {
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
  if (WI4MPI_File_read_all_begin_print)
    debug_printer("MPI_File_read_all_begin : \n{\nfh : %*d,\nbuf : %*d,\ncount "
                  ": %*d,\ndatatype : %*d,\nerror/return : %*d\n}\n",
                  fh, buf, count, datatype, ret_tmp);
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

extern unsigned long long WI4MPI_File_read_all_end_timeout;
extern unsigned int WI4MPI_File_read_all_end_print;
void (*_LOCAL_MPI_File_read_all_end)(int *, void *, int *, int *);

void A_f_MPI_File_read_all_end(int *fh, void *buf, int *status, int *ret) {
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
  if (WI4MPI_File_read_all_end_print)
    debug_printer("MPI_File_read_all_end : \n{\nfh : %*d,\nbuf : %*d,\nstatus "
                  ": %S,\nerror/return : %*d\n}\n",
                  fh, buf, status, ret_tmp);
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

extern unsigned long long WI4MPI_File_write_all_begin_timeout;
extern unsigned int WI4MPI_File_write_all_begin_print;
void (*_LOCAL_MPI_File_write_all_begin)(int *, void *, int *, int *, int *);

void A_f_MPI_File_write_all_begin(int *fh, void *buf, int *count, int *datatype,
                                  int *ret) {
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
  if (WI4MPI_File_write_all_begin_print)
    debug_printer("MPI_File_write_all_begin : \n{\nfh : %*d,\nbuf : "
                  "%*d,\ncount : %*d,\ndatatype : %*d,\nerror/return : "
                  "%*d\n}\n",
                  fh, buf, count, datatype, ret_tmp);
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

extern unsigned long long WI4MPI_File_write_all_end_timeout;
extern unsigned int WI4MPI_File_write_all_end_print;
void (*_LOCAL_MPI_File_write_all_end)(int *, void *, int *, int *);

void A_f_MPI_File_write_all_end(int *fh, void *buf, int *status, int *ret) {
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
  if (WI4MPI_File_write_all_end_print)
    debug_printer("MPI_File_write_all_end : \n{\nfh : %*d,\nbuf : %*d,\nstatus "
                  ": %S,\nerror/return : %*d\n}\n",
                  fh, buf, status, ret_tmp);
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

extern unsigned long long WI4MPI_File_read_ordered_begin_timeout;
extern unsigned int WI4MPI_File_read_ordered_begin_print;
void (*_LOCAL_MPI_File_read_ordered_begin)(int *, void *, int *, int *, int *);

void A_f_MPI_File_read_ordered_begin(int *fh, void *buf, int *count,
                                     int *datatype, int *ret) {
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
  if (WI4MPI_File_read_ordered_begin_print)
    debug_printer("MPI_File_read_ordered_begin : \n{\nfh : %*d,\nbuf : "
                  "%*d,\ncount : %*d,\ndatatype : %*d,\nerror/return : "
                  "%*d\n}\n",
                  fh, buf, count, datatype, ret_tmp);
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

extern unsigned long long WI4MPI_File_read_ordered_end_timeout;
extern unsigned int WI4MPI_File_read_ordered_end_print;
void (*_LOCAL_MPI_File_read_ordered_end)(int *, void *, int *, int *);

void A_f_MPI_File_read_ordered_end(int *fh, void *buf, int *status, int *ret) {
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
  if (WI4MPI_File_read_ordered_end_print)
    debug_printer("MPI_File_read_ordered_end : \n{\nfh : %*d,\nbuf : "
                  "%*d,\nstatus : %S,\nerror/return : %*d\n}\n",
                  fh, buf, status, ret_tmp);
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

extern unsigned long long WI4MPI_File_write_ordered_begin_timeout;
extern unsigned int WI4MPI_File_write_ordered_begin_print;
void (*_LOCAL_MPI_File_write_ordered_begin)(int *, void *, int *, int *, int *);

void A_f_MPI_File_write_ordered_begin(int *fh, void *buf, int *count,
                                      int *datatype, int *ret) {
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
  if (WI4MPI_File_write_ordered_begin_print)
    debug_printer("MPI_File_write_ordered_begin : \n{\nfh : %*d,\nbuf : "
                  "%*d,\ncount : %*d,\ndatatype : %*d,\nerror/return : "
                  "%*d\n}\n",
                  fh, buf, count, datatype, ret_tmp);
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

extern unsigned long long WI4MPI_File_write_ordered_end_timeout;
extern unsigned int WI4MPI_File_write_ordered_end_print;
void (*_LOCAL_MPI_File_write_ordered_end)(int *, void *, int *, int *);

void A_f_MPI_File_write_ordered_end(int *fh, void *buf, int *status, int *ret) {
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
  if (WI4MPI_File_write_ordered_end_print)
    debug_printer("MPI_File_write_ordered_end : \n{\nfh : %*d,\nbuf : "
                  "%*d,\nstatus : %S,\nerror/return : %*d\n}\n",
                  fh, buf, status, ret_tmp);
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

extern unsigned long long WI4MPI_File_get_type_extent_timeout;
extern unsigned int WI4MPI_File_get_type_extent_print;
void (*_LOCAL_MPI_File_get_type_extent)(int *, int *, size_t *, int *);

void A_f_MPI_File_get_type_extent(int *fh, int *datatype, size_t *extent,
                                  int *ret) {
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
  if (WI4MPI_File_get_type_extent_print)
    debug_printer("MPI_File_get_type_extent : \n{\nfh : %*d,\ndatatype : "
                  "%*d,\nextent : %*d,\nerror/return : %*d\n}\n",
                  fh, datatype, extent, ret_tmp);
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

extern unsigned long long WI4MPI_File_set_atomicity_timeout;
extern unsigned int WI4MPI_File_set_atomicity_print;
void (*_LOCAL_MPI_File_set_atomicity)(int *, int *, int *);

void A_f_MPI_File_set_atomicity(int *fh, int *flag, int *ret) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_set_atomicity_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_File_set_atomicity(fh, flag, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_File_set_atomicity_print)
    debug_printer("MPI_File_set_atomicity : \n{\nfh : %*d,\nflag : "
                  "%*d,\nerror/return : %*d\n}\n",
                  fh, flag, ret_tmp);
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

extern unsigned long long WI4MPI_File_get_atomicity_timeout;
extern unsigned int WI4MPI_File_get_atomicity_print;
void (*_LOCAL_MPI_File_get_atomicity)(int *, int *, int *);

void A_f_MPI_File_get_atomicity(int *fh, int *flag, int *ret) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_get_atomicity_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_File_get_atomicity(fh, flag, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_File_get_atomicity_print)
    debug_printer("MPI_File_get_atomicity : \n{\nfh : %*d,\nflag : "
                  "%*d,\nerror/return : %*d\n}\n",
                  fh, flag, ret_tmp);
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

extern unsigned long long WI4MPI_File_sync_timeout;
extern unsigned int WI4MPI_File_sync_print;
void (*_LOCAL_MPI_File_sync)(int *, int *);

void A_f_MPI_File_sync(int *fh, int *ret) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_File_sync_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_File_sync(fh, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_File_sync_print)
    debug_printer("MPI_File_sync : \n{\nfh : %*d,\nerror/return : %*d\n}\n", fh,
                  ret_tmp);
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

extern unsigned long long WI4MPI_Wtime_timeout;
extern unsigned int WI4MPI_Wtime_print;
void (*_LOCAL_MPI_Wtime)(double *);

void A_f_MPI_Wtime(double *ret) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Wtime_timeout);
#endif
  in_w = 1;
  double ret_tmp = 0;

  _LOCAL_MPI_Wtime(&ret_tmp);

  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_Wtime_print)
    debug_printer("MPI_Wtime : \n{\nerror/return : %*d\n}\n", ret_tmp);
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

extern unsigned long long WI4MPI_Wtick_timeout;
extern unsigned int WI4MPI_Wtick_print;
void (*_LOCAL_MPI_Wtick)(double *);

void A_f_MPI_Wtick(double *ret) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Wtick_timeout);
#endif
  in_w = 1;
  double ret_tmp = 0;

  _LOCAL_MPI_Wtick(&ret_tmp);

  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_Wtick_print)
    debug_printer("MPI_Wtick : \n{\nerror/return : %*d\n}\n", ret_tmp);
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

extern unsigned long long WI4MPI_Finalize_timeout;
extern unsigned int WI4MPI_Finalize_print;
void (*_LOCAL_MPI_Finalize)(int *);

void A_f_MPI_Finalize(int *ret) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Finalize_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_Finalize(&ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_Finalize_print)
    debug_printer("MPI_Finalize : \n{\nerror/return : %*d\n}\n", ret_tmp);
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

extern unsigned long long WI4MPI_Waitany_timeout;
extern unsigned int WI4MPI_Waitany_print;
void (*_LOCAL_MPI_Waitany)(int *, int *, int *, int *, int *);

void A_f_MPI_Waitany(int *count, int *array_of_requests, int *indx, int *status,
                     int *ret) {
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
  if (WI4MPI_Waitany_print)
    debug_printer("MPI_Waitany : \n{\ncount : %*d,\narray_of_requests : "
                  "%*d,\nindx : %*d,\nstatus : %S,\nerror/return : %*d\n}\n",
                  count, count, array_of_requests, indx, status, ret_tmp);
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

extern unsigned long long WI4MPI_Testany_timeout;
extern unsigned int WI4MPI_Testany_print;
void (*_LOCAL_MPI_Testany)(int *, int *, int *, int *, int *, int *);

void A_f_MPI_Testany(int *count, int *array_of_requests, int *indx, int *flag,
                     int *status, int *ret) {
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
  if (WI4MPI_Testany_print)
    debug_printer("MPI_Testany : \n{\ncount : %*d,\narray_of_requests : "
                  "%*d,\nindx : %*d,\nflag : %*d,\nstatus : %S,\nerror/return "
                  ": %*d\n}\n",
                  count, count, array_of_requests, indx, flag, status, ret_tmp);
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

extern unsigned long long WI4MPI_Waitall_timeout;
extern unsigned int WI4MPI_Waitall_print;
void (*_LOCAL_MPI_Waitall)(int *, int *, int *, int *);

void A_f_MPI_Waitall(int *count, int *array_of_requests, int *array_of_statuses,
                     int *ret) {
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
  if (WI4MPI_Waitall_print)
    debug_printer("MPI_Waitall : \n{\ncount : %*d,\narray_of_requests : "
                  "%*d,\narray_of_statuses : %S,\nerror/return : %*d\n}\n",
                  count, count, array_of_requests, count, array_of_statuses,
                  ret_tmp);
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

extern unsigned long long WI4MPI_Testall_timeout;
extern unsigned int WI4MPI_Testall_print;
void (*_LOCAL_MPI_Testall)(int *, int *, int *, int *, int *);

void A_f_MPI_Testall(int *count, int *array_of_requests, int *flag,
                     int *array_of_statuses, int *ret) {
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
  if (WI4MPI_Testall_print)
    debug_printer("MPI_Testall : \n{\ncount : %*d,\narray_of_requests : "
                  "%*d,\nflag : %*d,\narray_of_statuses : %S,\nerror/return : "
                  "%*d\n}\n",
                  count, count, array_of_requests, flag, count,
                  array_of_statuses, ret_tmp);
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

extern unsigned long long WI4MPI_Waitsome_timeout;
extern unsigned int WI4MPI_Waitsome_print;
void (*_LOCAL_MPI_Waitsome)(int *, int *, int *, int *, int *, int *);

void A_f_MPI_Waitsome(int *incount, int *array_of_requests, int *outcount,
                      int *array_of_indices, int *array_of_statuses, int *ret) {
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
  if (WI4MPI_Waitsome_print)
    debug_printer("MPI_Waitsome : \n{\nincount : %*d,\narray_of_requests : "
                  "%*d,\noutcount : %*d,\narray_of_indices : "
                  "%*d,\narray_of_statuses : %S,\nerror/return : %*d\n}\n",
                  incount, incount, array_of_requests, outcount, outcount,
                  array_of_indices, incount, array_of_statuses, ret_tmp);
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

extern unsigned long long WI4MPI_Testsome_timeout;
extern unsigned int WI4MPI_Testsome_print;
void (*_LOCAL_MPI_Testsome)(int *, int *, int *, int *, int *, int *);

void A_f_MPI_Testsome(int *incount, int *array_of_requests, int *outcount,
                      int *array_of_indices, int *array_of_statuses, int *ret) {
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
  if (WI4MPI_Testsome_print)
    debug_printer("MPI_Testsome : \n{\nincount : %*d,\narray_of_requests : "
                  "%*d,\noutcount : %*d,\narray_of_indices : "
                  "%*d,\narray_of_statuses : %S,\nerror/return : %*d\n}\n",
                  incount, incount, array_of_requests, outcount, outcount,
                  array_of_indices, incount, array_of_statuses, ret_tmp);
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

extern unsigned long long WI4MPI_Startall_timeout;
extern unsigned int WI4MPI_Startall_print;
void (*_LOCAL_MPI_Startall)(int *, int *, int *);

void A_f_MPI_Startall(int *count, int *array_of_requests, int *ret) {
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
  if (WI4MPI_Startall_print)
    debug_printer("MPI_Startall : \n{\ncount : %*d,\narray_of_requests : "
                  "%*d,\nerror/return : %*d\n}\n",
                  count, count, array_of_requests, ret_tmp);
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

extern unsigned long long WI4MPI_Alltoallw_timeout;
extern unsigned int WI4MPI_Alltoallw_print;
void (*_LOCAL_MPI_Alltoallw)(void *, int *, int *, int *, void *, int *, int *,
                             int *, int *, int *);

void A_f_MPI_Alltoallw(void *sendbuf, int *sendcounts, int *sdispls,
                       int *sendtypes, void *recvbuf, int *recvcounts,
                       int *rdispls, int *recvtypes, int *comm, int *ret) {
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
  if (WI4MPI_Alltoallw_print)
    debug_printer("MPI_Alltoallw : \n{\nsendbuf : %*d,\nsendcounts : "
                  "%*d,\nsdispls : %*d,\nsendtypes : %*d,\nrecvbuf : "
                  "%*d,\nrecvcounts : %*d,\nrdispls : %*d,\nrecvtypes : "
                  "%*d,\ncomm : %*d,\nerror/return : %*d\n}\n",
                  sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts,
                  rdispls, recvtypes, comm, ret_tmp);
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

extern unsigned long long WI4MPI_Reduce_scatter_timeout;
extern unsigned int WI4MPI_Reduce_scatter_print;
void (*_LOCAL_MPI_Reduce_scatter)(void *, void *, int *, int *, int *, int *,
                                  int *);

void A_f_MPI_Reduce_scatter(void *sendbuf, void *recvbuf, int *recvcounts,
                            int *datatype, int *op, int *comm, int *ret) {
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
  if (WI4MPI_Reduce_scatter_print)
    debug_printer("MPI_Reduce_scatter : \n{\nsendbuf : %*d,\nrecvbuf : "
                  "%*d,\nrecvcounts : %*d,\ndatatype : %*d,\nop : %*d,\ncomm : "
                  "%*d,\nerror/return : %*d\n}\n",
                  sendbuf, recvbuf, recvcounts, datatype, op, comm, ret_tmp);
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

extern unsigned long long WI4MPI_Group_translate_ranks_timeout;
extern unsigned int WI4MPI_Group_translate_ranks_print;
void (*_LOCAL_MPI_Group_translate_ranks)(int *, int *, int *, int *, int *,
                                         int *);

void A_f_MPI_Group_translate_ranks(int *group1, int *n, int *ranks1,
                                   int *group2, int *ranks2, int *ret) {
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
  if (WI4MPI_Group_translate_ranks_print)
    debug_printer("MPI_Group_translate_ranks : \n{\ngroup1 : %*d,\nn : "
                  "%*d,\nranks1 : %*d,\ngroup2 : %*d,\nranks2 : "
                  "%*d,\nerror/return : %*d\n}\n",
                  group1, n, n, ranks1, group2, n, ranks2, ret_tmp);
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

extern unsigned long long WI4MPI_Group_incl_timeout;
extern unsigned int WI4MPI_Group_incl_print;
void (*_LOCAL_MPI_Group_incl)(int *, int *, int *, int *, int *);

void A_f_MPI_Group_incl(int *group, int *n, int *ranks, int *newgroup,
                        int *ret) {
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
  if (WI4MPI_Group_incl_print)
    debug_printer("MPI_Group_incl : \n{\ngroup : %*d,\nn : %*d,\nranks : "
                  "%*d,\nnewgroup : %*d,\nerror/return : %*d\n}\n",
                  group, n, n, ranks, newgroup, ret_tmp);
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

extern unsigned long long WI4MPI_Group_excl_timeout;
extern unsigned int WI4MPI_Group_excl_print;
void (*_LOCAL_MPI_Group_excl)(int *, int *, int *, int *, int *);

void A_f_MPI_Group_excl(int *group, int *n, int *ranks, int *newgroup,
                        int *ret) {
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
  if (WI4MPI_Group_excl_print)
    debug_printer("MPI_Group_excl : \n{\ngroup : %*d,\nn : %*d,\nranks : "
                  "%*d,\nnewgroup : %*d,\nerror/return : %*d\n}\n",
                  group, n, n, ranks, newgroup, ret_tmp);
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

extern unsigned long long WI4MPI_Group_range_incl_timeout;
extern unsigned int WI4MPI_Group_range_incl_print;
void (*_LOCAL_MPI_Group_range_incl)(int *, int *, int *, int *, int *);

void A_f_MPI_Group_range_incl(int *group, int *n, int *ranges, int *newgroup,
                              int *ret) {
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
  if (WI4MPI_Group_range_incl_print)
    debug_printer("MPI_Group_range_incl : \n{\ngroup : %*d,\nn : %*d,\nranges "
                  ": %*d,\nnewgroup : %*d,\nerror/return : %*d\n}\n",
                  group, n, n, ranges, newgroup, ret_tmp);
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

extern unsigned long long WI4MPI_Group_range_excl_timeout;
extern unsigned int WI4MPI_Group_range_excl_print;
void (*_LOCAL_MPI_Group_range_excl)(int *, int *, int *, int *, int *);

void A_f_MPI_Group_range_excl(int *group, int *n, int *ranges, int *newgroup,
                              int *ret) {
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
  if (WI4MPI_Group_range_excl_print)
    debug_printer("MPI_Group_range_excl : \n{\ngroup : %*d,\nn : %*d,\nranges "
                  ": %*d,\nnewgroup : %*d,\nerror/return : %*d\n}\n",
                  group, n, n, ranges, newgroup, ret_tmp);
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

extern unsigned long long WI4MPI_Cart_create_timeout;
extern unsigned int WI4MPI_Cart_create_print;
void (*_LOCAL_MPI_Cart_create)(int *, int *, int *, int *, int *, int *, int *);

void A_f_MPI_Cart_create(int *comm_old, int *ndims, int *dims, int *periods,
                         int *reorder, int *comm_cart, int *ret) {
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
  if (WI4MPI_Cart_create_print)
    debug_printer("MPI_Cart_create : \n{\ncomm_old : %*d,\nndims : %*d,\ndims "
                  ": %*d,\nperiods : %*d,\nreorder : %*d,\ncomm_cart : "
                  "%*d,\nerror/return : %*d\n}\n",
                  comm_old, ndims, ndims, dims, ndims, periods, reorder,
                  comm_cart, ret_tmp);
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

extern unsigned long long WI4MPI_Dims_create_timeout;
extern unsigned int WI4MPI_Dims_create_print;
void (*_LOCAL_MPI_Dims_create)(int *, int *, int *, int *);

void A_f_MPI_Dims_create(int *nnodes, int *ndims, int *dims, int *ret) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Dims_create_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  _LOCAL_MPI_Dims_create(nnodes, ndims, dims, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_Dims_create_print)
    debug_printer("MPI_Dims_create : \n{\nnnodes : %*d,\nndims : %*d,\ndims : "
                  "%*d,\nerror/return : %*d\n}\n",
                  nnodes, ndims, ndims, dims, ret_tmp);
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

extern unsigned long long WI4MPI_Graph_create_timeout;
extern unsigned int WI4MPI_Graph_create_print;
void (*_LOCAL_MPI_Graph_create)(int *, int *, int *, int *, int *, int *,
                                int *);

void A_f_MPI_Graph_create(int *comm_old, int *nnodes, int *indx, int *edges,
                          int *reorder, int *comm_graph, int *ret) {
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
  if (WI4MPI_Graph_create_print)
    debug_printer("MPI_Graph_create : \n{\ncomm_old : %*d,\nnnodes : "
                  "%*d,\nindx : %*d,\nedges : %*d,\nreorder : %*d,\ncomm_graph "
                  ": %*d,\nerror/return : %*d\n}\n",
                  comm_old, nnodes, nnodes, indx, nnodes, edges, reorder,
                  comm_graph, ret_tmp);
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

extern unsigned long long WI4MPI_Graph_get_timeout;
extern unsigned int WI4MPI_Graph_get_print;
void (*_LOCAL_MPI_Graph_get)(int *, int *, int *, int *, int *, int *);

void A_f_MPI_Graph_get(int *comm, int *maxindex, int *maxedges, int *indx,
                       int *edges, int *ret) {
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
  if (WI4MPI_Graph_get_print)
    debug_printer("MPI_Graph_get : \n{\ncomm : %*d,\nmaxindex : %*d,\nmaxedges "
                  ": %*d,\nindx : %*d,\nedges : %*d,\nerror/return : %*d\n}\n",
                  comm, maxindex, maxedges, maxindex, indx, maxedges, edges,
                  ret_tmp);
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

extern unsigned long long WI4MPI_Cart_get_timeout;
extern unsigned int WI4MPI_Cart_get_print;
void (*_LOCAL_MPI_Cart_get)(int *, int *, int *, int *, int *, int *);

void A_f_MPI_Cart_get(int *comm, int *maxdims, int *dims, int *periods,
                      int *coords, int *ret) {
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
  if (WI4MPI_Cart_get_print)
    debug_printer("MPI_Cart_get : \n{\ncomm : %*d,\nmaxdims : %*d,\ndims : "
                  "%*d,\nperiods : %*d,\ncoords : %*d,\nerror/return : "
                  "%*d\n}\n",
                  comm, maxdims, maxdims, dims, maxdims, periods, maxdims,
                  coords, ret_tmp);
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

extern unsigned long long WI4MPI_Cart_rank_timeout;
extern unsigned int WI4MPI_Cart_rank_print;
void (*_LOCAL_MPI_Cart_rank)(int *, int *, int *, int *);

void A_f_MPI_Cart_rank(int *comm, int *coords, int *rank, int *ret) {
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
  if (WI4MPI_Cart_rank_print)
    debug_printer("MPI_Cart_rank : \n{\ncomm : %*d,\ncoords : %*d,\nrank : "
                  "%*d,\nerror/return : %*d\n}\n",
                  comm, coords, rank, ret_tmp);
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

extern unsigned long long WI4MPI_Cart_coords_timeout;
extern unsigned int WI4MPI_Cart_coords_print;
void (*_LOCAL_MPI_Cart_coords)(int *, int *, int *, int *, int *);

void A_f_MPI_Cart_coords(int *comm, int *rank, int *maxdims, int *coords,
                         int *ret) {
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
  if (WI4MPI_Cart_coords_print)
    debug_printer("MPI_Cart_coords : \n{\ncomm : %*d,\nrank : %*d,\nmaxdims : "
                  "%*d,\ncoords : %*d,\nerror/return : %*d\n}\n",
                  comm, rank, maxdims, maxdims, coords, ret_tmp);
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

extern unsigned long long WI4MPI_Graph_neighbors_timeout;
extern unsigned int WI4MPI_Graph_neighbors_print;
void (*_LOCAL_MPI_Graph_neighbors)(int *, int *, int *, int *, int *);

void A_f_MPI_Graph_neighbors(int *comm, int *rank, int *maxneighbors,
                             int *neighbors, int *ret) {
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
  if (WI4MPI_Graph_neighbors_print)
    debug_printer("MPI_Graph_neighbors : \n{\ncomm : %*d,\nrank : "
                  "%*d,\nmaxneighbors : %*d,\nneighbors : %*d,\nerror/return : "
                  "%*d\n}\n",
                  comm, rank, maxneighbors, maxneighbors, neighbors, ret_tmp);
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

extern unsigned long long WI4MPI_Cart_sub_timeout;
extern unsigned int WI4MPI_Cart_sub_print;
void (*_LOCAL_MPI_Cart_sub)(int *, int *, int *, int *);

void A_f_MPI_Cart_sub(int *comm, int *remain_dims, int *newcomm, int *ret) {
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
  if (WI4MPI_Cart_sub_print)
    debug_printer("MPI_Cart_sub : \n{\ncomm : %*d,\nremain_dims : "
                  "%*d,\nnewcomm : %*d,\nerror/return : %*d\n}\n",
                  comm, remain_dims, newcomm, ret_tmp);
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

extern unsigned long long WI4MPI_Cart_map_timeout;
extern unsigned int WI4MPI_Cart_map_print;
void (*_LOCAL_MPI_Cart_map)(int *, int *, int *, int *, int *, int *);

void A_f_MPI_Cart_map(int *comm, int *ndims, int *dims, int *periods,
                      int *newrank, int *ret) {
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
  if (WI4MPI_Cart_map_print)
    debug_printer("MPI_Cart_map : \n{\ncomm : %*d,\nndims : %*d,\ndims : "
                  "%*d,\nperiods : %*d,\nnewrank : %*d,\nerror/return : "
                  "%*d\n}\n",
                  comm, ndims, ndims, dims, ndims, periods, newrank, ret_tmp);
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

extern unsigned long long WI4MPI_Graph_map_timeout;
extern unsigned int WI4MPI_Graph_map_print;
void (*_LOCAL_MPI_Graph_map)(int *, int *, int *, int *, int *, int *);

void A_f_MPI_Graph_map(int *comm, int *nnodes, int *indx, int *edges,
                       int *newrank, int *ret) {
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
  if (WI4MPI_Graph_map_print)
    debug_printer("MPI_Graph_map : \n{\ncomm : %*d,\nnnodes : %*d,\nindx : "
                  "%*d,\nedges : %*d,\nnewrank : %*d,\nerror/return : %*d\n}\n",
                  comm, nnodes, nnodes, indx, nnodes, edges, newrank, ret_tmp);
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

extern unsigned long long WI4MPI_Type_get_contents_timeout;
extern unsigned int WI4MPI_Type_get_contents_print;
void (*_LOCAL_MPI_Type_get_contents)(int *, int *, int *, int *, int *,
                                     size_t *, int *, int *);

void A_f_MPI_Type_get_contents(int *datatype, int *max_integers,
                               int *max_addresses, int *max_datatypes,
                               int *array_of_integers,
                               size_t *array_of_addresses,
                               int *array_of_datatypes, int *ret) {
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
  if (WI4MPI_Type_get_contents_print)
    debug_printer("MPI_Type_get_contents : \n{\ndatatype : %*d,\nmax_integers "
                  ": %*d,\nmax_addresses : %*d,\nmax_datatypes : "
                  "%*d,\narray_of_integers : %*d,\narray_of_addresses : "
                  "%*d,\narray_of_datatypes : %*d,\nerror/return : %*d\n}\n",
                  datatype, max_integers, max_addresses, max_datatypes,
                  max_integers, array_of_integers, max_addresses,
                  array_of_addresses, max_datatypes, array_of_datatypes,
                  ret_tmp);
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

extern unsigned long long WI4MPI_Type_create_darray_timeout;
extern unsigned int WI4MPI_Type_create_darray_print;
void (*_LOCAL_MPI_Type_create_darray)(int *, int *, int *, int *, int *, int *,
                                      int *, int *, int *, int *, int *);

void A_f_MPI_Type_create_darray(int *size, int *rank, int *ndims,
                                int *array_of_gsizes, int *array_of_distribs,
                                int *array_of_dargs, int *array_of_psizes,
                                int *order, int *oldtype, int *newtype,
                                int *ret) {
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
  if (WI4MPI_Type_create_darray_print)
    debug_printer(
        "MPI_Type_create_darray : \n{\nsize : %*d,\nrank : %*d,\nndims : "
        "%*d,\narray_of_gsizes : %*d,\narray_of_distribs : "
        "%*d,\narray_of_dargs : %*d,\narray_of_psizes : %*d,\norder : "
        "%*d,\noldtype : %*d,\nnewtype : %*d,\nerror/return : %*d\n}\n",
        size, rank, ndims, array_of_gsizes, array_of_distribs, array_of_dargs,
        array_of_psizes, order, oldtype, newtype, ret_tmp);
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

extern unsigned long long WI4MPI_Type_create_hindexed_timeout;
extern unsigned int WI4MPI_Type_create_hindexed_print;
void (*_LOCAL_MPI_Type_create_hindexed)(int *, int *, size_t *, int *, int *,
                                        int *);

void A_f_MPI_Type_create_hindexed(int *count, int *array_of_blocklengths,
                                  size_t *array_of_displacements, int *oldtype,
                                  int *newtype, int *ret) {
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
  if (WI4MPI_Type_create_hindexed_print)
    debug_printer("MPI_Type_create_hindexed : \n{\ncount : "
                  "%*d,\narray_of_blocklengths : %*d,\narray_of_displacements "
                  ": %*d,\noldtype : %*d,\nnewtype : %*d,\nerror/return : "
                  "%*d\n}\n",
                  count, count, array_of_blocklengths, count,
                  array_of_displacements, oldtype, newtype, ret_tmp);
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

extern unsigned long long WI4MPI_Type_create_indexed_block_timeout;
extern unsigned int WI4MPI_Type_create_indexed_block_print;
void (*_LOCAL_MPI_Type_create_indexed_block)(int *, int *, int *, int *, int *,
                                             int *);

void A_f_MPI_Type_create_indexed_block(int *count, int *blocklength,
                                       int *array_of_displacements,
                                       int *oldtype, int *newtype, int *ret) {
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
  if (WI4MPI_Type_create_indexed_block_print)
    debug_printer("MPI_Type_create_indexed_block : \n{\ncount : "
                  "%*d,\nblocklength : %*d,\narray_of_displacements : "
                  "%*d,\noldtype : %*d,\nnewtype : %*d,\nerror/return : "
                  "%*d\n}\n",
                  count, blocklength, count, array_of_displacements, oldtype,
                  newtype, ret_tmp);
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

extern unsigned long long WI4MPI_Type_create_hindexed_block_timeout;
extern unsigned int WI4MPI_Type_create_hindexed_block_print;
void (*_LOCAL_MPI_Type_create_hindexed_block)(int *, int *, size_t *, int *,
                                              int *, int *);

void A_f_MPI_Type_create_hindexed_block(int *count, int *blocklength,
                                        size_t *array_of_displacements,
                                        int *oldtype, int *newtype, int *ret) {
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
  if (WI4MPI_Type_create_hindexed_block_print)
    debug_printer("MPI_Type_create_hindexed_block : \n{\ncount : "
                  "%*d,\nblocklength : %*d,\narray_of_displacements : "
                  "%*d,\noldtype : %*d,\nnewtype : %*d,\nerror/return : "
                  "%*d\n}\n",
                  count, blocklength, count, array_of_displacements, oldtype,
                  newtype, ret_tmp);
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

extern unsigned long long WI4MPI_Type_create_struct_timeout;
extern unsigned int WI4MPI_Type_create_struct_print;
void (*_LOCAL_MPI_Type_create_struct)(int *, int *, size_t *, int *, int *,
                                      int *);

void A_f_MPI_Type_create_struct(int *count, int *array_of_blocklengths,
                                size_t *array_of_displacements,
                                int *array_of_types, int *newtype, int *ret) {
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
  if (WI4MPI_Type_create_struct_print)
    debug_printer(
        "MPI_Type_create_struct : \n{\ncount : %*d,\narray_of_blocklengths : "
        "%*d,\narray_of_displacements : %*d,\narray_of_types : %*d,\nnewtype : "
        "%*d,\nerror/return : %*d\n}\n",
        count, count, array_of_blocklengths, count, array_of_displacements,
        count, array_of_types, newtype, ret_tmp);
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

extern unsigned long long WI4MPI_Type_create_subarray_timeout;
extern unsigned int WI4MPI_Type_create_subarray_print;
void (*_LOCAL_MPI_Type_create_subarray)(int *, int *, int *, int *, int *,
                                        int *, int *, int *);

void A_f_MPI_Type_create_subarray(int *ndims, int *array_of_sizes,
                                  int *array_of_subsizes, int *array_of_starts,
                                  int *order, int *oldtype, int *newtype,
                                  int *ret) {
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
  if (WI4MPI_Type_create_subarray_print)
    debug_printer("MPI_Type_create_subarray : \n{\nndims : "
                  "%*d,\narray_of_sizes : %*d,\narray_of_subsizes : "
                  "%*d,\narray_of_starts : %*d,\norder : %*d,\noldtype : "
                  "%*d,\nnewtype : %*d,\nerror/return : %*d\n}\n",
                  ndims, ndims, array_of_sizes, ndims, array_of_subsizes,
                  array_of_starts, order, oldtype, newtype, ret_tmp);
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

extern unsigned long long WI4MPI_Dist_graph_create_adjacent_timeout;
extern unsigned int WI4MPI_Dist_graph_create_adjacent_print;
void (*_LOCAL_MPI_Dist_graph_create_adjacent)(int *, int *, int *, int *, int *,
                                              int *, int *, int *, int *, int *,
                                              int *);

void A_f_MPI_Dist_graph_create_adjacent(int *comm_old, int *indegree,
                                        int *sources, int *sourceweights,
                                        int *outdegree, int *destinations,
                                        int *destweights, int *info,
                                        int *reorder, int *comm_dist_graph,
                                        int *ret) {
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
  if (WI4MPI_Dist_graph_create_adjacent_print)
    debug_printer("MPI_Dist_graph_create_adjacent : \n{\ncomm_old : "
                  "%*d,\nindegree : %*d,\nsources : %*d,\nsourceweights : "
                  "%*d,\noutdegree : %*d,\ndestinations : %*d,\ndestweights : "
                  "%*d,\ninfo : %*d,\nreorder : %*d,\ncomm_dist_graph : "
                  "%*d,\nerror/return : %*d\n}\n",
                  comm_old, indegree, indegree, sources, sourceweights,
                  outdegree, outdegree, destinations, destweights, info,
                  reorder, comm_dist_graph, ret_tmp);
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

extern unsigned long long WI4MPI_Dist_graph_create_timeout;
extern unsigned int WI4MPI_Dist_graph_create_print;
void (*_LOCAL_MPI_Dist_graph_create)(int *, int *, int *, int *, int *, int *,
                                     int *, int *, int *, int *);

void A_f_MPI_Dist_graph_create(int *comm_old, int *n, int *sources,
                               int *degrees, int *destinations, int *weights,
                               int *info, int *reorder, int *comm_dist_graph,
                               int *ret) {
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
  if (WI4MPI_Dist_graph_create_print)
    debug_printer("MPI_Dist_graph_create : \n{\ncomm_old : %*d,\nn : "
                  "%*d,\nsources : %*d,\ndegrees : %*d,\ndestinations : "
                  "%*d,\nweights : %*d,\ninfo : %*d,\nreorder : "
                  "%*d,\ncomm_dist_graph : %*d,\nerror/return : %*d\n}\n",
                  comm_old, n, n, sources, n, degrees, n, destinations, weights,
                  info, reorder, comm_dist_graph, ret_tmp);
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

extern unsigned long long WI4MPI_Dist_graph_neighbors_timeout;
extern unsigned int WI4MPI_Dist_graph_neighbors_print;
void (*_LOCAL_MPI_Dist_graph_neighbors)(int *, int *, int *, int *, int *,
                                        int *, int *, int *);

void A_f_MPI_Dist_graph_neighbors(int *comm, int *maxindegree, int *sources,
                                  int *sourceweights, int *maxoutdegree,
                                  int *destinations, int *destweights,
                                  int *ret) {
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
  if (WI4MPI_Dist_graph_neighbors_print)
    debug_printer("MPI_Dist_graph_neighbors : \n{\ncomm : %*d,\nmaxindegree : "
                  "%*d,\nsources : %*d,\nsourceweights : %*d,\nmaxoutdegree : "
                  "%*d,\ndestinations : %*d,\ndestweights : %*d,\nerror/return "
                  ": %*d\n}\n",
                  comm, maxindegree, maxindegree, sources, sourceweights,
                  maxoutdegree, maxoutdegree, destinations, destweights,
                  ret_tmp);
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

extern unsigned long long WI4MPI_Igatherv_timeout;
extern unsigned int WI4MPI_Igatherv_print;
void (*_LOCAL_MPI_Igatherv)(void *, int *, int *, void *, int *, int *, int *,
                            int *, int *, int *, int *);

void A_f_MPI_Igatherv(void *sendbuf, int *sendcount, int *sendtype,
                      void *recvbuf, int *recvcounts, int *displs,
                      int *recvtype, int *root, int *comm, int *request,
                      int *ret) {
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
  if (WI4MPI_Igatherv_print)
    debug_printer("MPI_Igatherv : \n{\nsendbuf : %*d,\nsendcount : "
                  "%*d,\nsendtype : %*d,\nrecvbuf : %*d,\nrecvcounts : "
                  "%*d,\ndispls : %*d,\nrecvtype : %*d,\nroot : %*d,\ncomm : "
                  "%*d,\nrequest : %*d,\nerror/return : %*d\n}\n",
                  sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs,
                  recvtype, root, comm, request, ret_tmp);
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

extern unsigned long long WI4MPI_Iscatterv_timeout;
extern unsigned int WI4MPI_Iscatterv_print;
void (*_LOCAL_MPI_Iscatterv)(void *, int *, int *, int *, void *, int *, int *,
                             int *, int *, int *, int *);

void A_f_MPI_Iscatterv(void *sendbuf, int *sendcounts, int *displs,
                       int *sendtype, void *recvbuf, int *recvcount,
                       int *recvtype, int *root, int *comm, int *request,
                       int *ret) {
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
  if (WI4MPI_Iscatterv_print)
    debug_printer("MPI_Iscatterv : \n{\nsendbuf : %*d,\nsendcounts : "
                  "%*d,\ndispls : %*d,\nsendtype : %*d,\nrecvbuf : "
                  "%*d,\nrecvcount : %*d,\nrecvtype : %*d,\nroot : %*d,\ncomm "
                  ": %*d,\nrequest : %*d,\nerror/return : %*d\n}\n",
                  sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount,
                  recvtype, root, comm, request, ret_tmp);
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

extern unsigned long long WI4MPI_Iallgatherv_timeout;
extern unsigned int WI4MPI_Iallgatherv_print;
void (*_LOCAL_MPI_Iallgatherv)(void *, int *, int *, void *, int *, int *,
                               int *, int *, int *, int *);

void A_f_MPI_Iallgatherv(void *sendbuf, int *sendcount, int *sendtype,
                         void *recvbuf, int *recvcounts, int *displs,
                         int *recvtype, int *comm, int *request, int *ret) {
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
  if (WI4MPI_Iallgatherv_print)
    debug_printer("MPI_Iallgatherv : \n{\nsendbuf : %*d,\nsendcount : "
                  "%*d,\nsendtype : %*d,\nrecvbuf : %*d,\nrecvcounts : "
                  "%*d,\ndispls : %*d,\nrecvtype : %*d,\ncomm : %*d,\nrequest "
                  ": %*d,\nerror/return : %*d\n}\n",
                  sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs,
                  recvtype, comm, request, ret_tmp);
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

extern unsigned long long WI4MPI_Ialltoallv_timeout;
extern unsigned int WI4MPI_Ialltoallv_print;
void (*_LOCAL_MPI_Ialltoallv)(void *, int *, int *, int *, void *, int *, int *,
                              int *, int *, int *, int *);

void A_f_MPI_Ialltoallv(void *sendbuf, int *sendcounts, int *sdispls,
                        int *sendtype, void *recvbuf, int *recvcounts,
                        int *rdispls, int *recvtype, int *comm, int *request,
                        int *ret) {
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
  if (WI4MPI_Ialltoallv_print)
    debug_printer("MPI_Ialltoallv : \n{\nsendbuf : %*d,\nsendcounts : "
                  "%*d,\nsdispls : %*d,\nsendtype : %*d,\nrecvbuf : "
                  "%*d,\nrecvcounts : %*d,\nrdispls : %*d,\nrecvtype : "
                  "%*d,\ncomm : %*d,\nrequest : %*d,\nerror/return : %*d\n}\n",
                  sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts,
                  rdispls, recvtype, comm, request, ret_tmp);
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

extern unsigned long long WI4MPI_Ialltoallw_timeout;
extern unsigned int WI4MPI_Ialltoallw_print;
void (*_LOCAL_MPI_Ialltoallw)(void *, int *, int *, int *, void *, int *, int *,
                              int *, int *, int *, int *);

void A_f_MPI_Ialltoallw(void *sendbuf, int *sendcounts, int *sdispls,
                        int *sendtypes, void *recvbuf, int *recvcounts,
                        int *rdispls, int *recvtypes, int *comm, int *request,
                        int *ret) {
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
  if (WI4MPI_Ialltoallw_print)
    debug_printer("MPI_Ialltoallw : \n{\nsendbuf : %*d,\nsendcounts : "
                  "%*d,\nsdispls : %*d,\nsendtypes : %*d,\nrecvbuf : "
                  "%*d,\nrecvcounts : %*d,\nrdispls : %*d,\nrecvtypes : "
                  "%*d,\ncomm : %*d,\nrequest : %*d,\nerror/return : %*d\n}\n",
                  sendbuf, sendcounts, sdispls, Comm_size, sendtypes, recvbuf,
                  recvcounts, rdispls, Comm_size, recvtypes, comm, request,
                  ret_tmp);
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

extern unsigned long long WI4MPI_Ireduce_scatter_timeout;
extern unsigned int WI4MPI_Ireduce_scatter_print;
void (*_LOCAL_MPI_Ireduce_scatter)(void *, void *, int *, int *, int *, int *,
                                   int *, int *);

void A_f_MPI_Ireduce_scatter(void *sendbuf, void *recvbuf, int *recvcounts,
                             int *datatype, int *op, int *comm, int *request,
                             int *ret) {
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
  if (WI4MPI_Ireduce_scatter_print)
    debug_printer("MPI_Ireduce_scatter : \n{\nsendbuf : %*d,\nrecvbuf : "
                  "%*d,\nrecvcounts : %*d,\ndatatype : %*d,\nop : %*d,\ncomm : "
                  "%*d,\nrequest : %*d,\nerror/return : %*d\n}\n",
                  sendbuf, recvbuf, recvcounts, datatype, op, comm, request,
                  ret_tmp);
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

extern unsigned long long WI4MPI_Ineighbor_allgatherv_timeout;
extern unsigned int WI4MPI_Ineighbor_allgatherv_print;
void (*_LOCAL_MPI_Ineighbor_allgatherv)(void *, int *, int *, void *, int *,
                                        int *, int *, int *, int *, int *);

void A_f_MPI_Ineighbor_allgatherv(void *sendbuf, int *sendcount, int *sendtype,
                                  void *recvbuf, int *recvcounts, int *displs,
                                  int *recvtype, int *comm, int *request,
                                  int *ret) {
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
  if (WI4MPI_Ineighbor_allgatherv_print)
    debug_printer("MPI_Ineighbor_allgatherv : \n{\nsendbuf : %*d,\nsendcount : "
                  "%*d,\nsendtype : %*d,\nrecvbuf : %*d,\nrecvcounts : "
                  "%*d,\ndispls : %*d,\nrecvtype : %*d,\ncomm : %*d,\nrequest "
                  ": %*d,\nerror/return : %*d\n}\n",
                  sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs,
                  recvtype, comm, request, ret_tmp);
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

extern unsigned long long WI4MPI_Ineighbor_alltoallv_timeout;
extern unsigned int WI4MPI_Ineighbor_alltoallv_print;
void (*_LOCAL_MPI_Ineighbor_alltoallv)(void *, int *, int *, int *, void *,
                                       int *, int *, int *, int *, int *,
                                       int *);

void A_f_MPI_Ineighbor_alltoallv(void *sendbuf, int *sendcounts, int *sdispls,
                                 int *sendtype, void *recvbuf, int *recvcounts,
                                 int *rdispls, int *recvtype, int *comm,
                                 int *request, int *ret) {
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
  if (WI4MPI_Ineighbor_alltoallv_print)
    debug_printer("MPI_Ineighbor_alltoallv : \n{\nsendbuf : %*d,\nsendcounts : "
                  "%*d,\nsdispls : %*d,\nsendtype : %*d,\nrecvbuf : "
                  "%*d,\nrecvcounts : %*d,\nrdispls : %*d,\nrecvtype : "
                  "%*d,\ncomm : %*d,\nrequest : %*d,\nerror/return : %*d\n}\n",
                  sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts,
                  rdispls, recvtype, comm, request, ret_tmp);
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

extern unsigned long long WI4MPI_Ineighbor_alltoallw_timeout;
extern unsigned int WI4MPI_Ineighbor_alltoallw_print;
void (*_LOCAL_MPI_Ineighbor_alltoallw)(void *, int *, size_t *, int *, void *,
                                       int *, size_t *, int *, int *, int *,
                                       int *);

void A_f_MPI_Ineighbor_alltoallw(void *sendbuf, int *sendcounts,
                                 size_t *sdispls, int *sendtypes, void *recvbuf,
                                 int *recvcounts, size_t *rdispls,
                                 int *recvtypes, int *comm, int *request,
                                 int *ret) {
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
  if (WI4MPI_Ineighbor_alltoallw_print)
    debug_printer("MPI_Ineighbor_alltoallw : \n{\nsendbuf : %*d,\nsendcounts : "
                  "%*d,\nsdispls : %*d,\nsendtypes : %*d,\nrecvbuf : "
                  "%*d,\nrecvcounts : %*d,\nrdispls : %*d,\nrecvtypes : "
                  "%*d,\ncomm : %*d,\nrequest : %*d,\nerror/return : %*d\n}\n",
                  sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts,
                  rdispls, recvtypes, comm, request, ret_tmp);
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

extern unsigned long long WI4MPI_Neighbor_allgatherv_timeout;
extern unsigned int WI4MPI_Neighbor_allgatherv_print;
void (*_LOCAL_MPI_Neighbor_allgatherv)(void *, int *, int *, void *, int *,
                                       int *, int *, int *, int *);

void A_f_MPI_Neighbor_allgatherv(void *sendbuf, int *sendcount, int *sendtype,
                                 void *recvbuf, int *recvcounts, int *displs,
                                 int *recvtype, int *comm, int *ret) {
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
  if (WI4MPI_Neighbor_allgatherv_print)
    debug_printer("MPI_Neighbor_allgatherv : \n{\nsendbuf : %*d,\nsendcount : "
                  "%*d,\nsendtype : %*d,\nrecvbuf : %*d,\nrecvcounts : "
                  "%*d,\ndispls : %*d,\nrecvtype : %*d,\ncomm : "
                  "%*d,\nerror/return : %*d\n}\n",
                  sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs,
                  recvtype, comm, ret_tmp);
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

extern unsigned long long WI4MPI_Neighbor_alltoallv_timeout;
extern unsigned int WI4MPI_Neighbor_alltoallv_print;
void (*_LOCAL_MPI_Neighbor_alltoallv)(void *, int *, int *, int *, void *,
                                      int *, int *, int *, int *, int *);

void A_f_MPI_Neighbor_alltoallv(void *sendbuf, int *sendcounts, int *sdispls,
                                int *sendtype, void *recvbuf, int *recvcounts,
                                int *rdispls, int *recvtype, int *comm,
                                int *ret) {
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
  if (WI4MPI_Neighbor_alltoallv_print)
    debug_printer("MPI_Neighbor_alltoallv : \n{\nsendbuf : %*d,\nsendcounts : "
                  "%*d,\nsdispls : %*d,\nsendtype : %*d,\nrecvbuf : "
                  "%*d,\nrecvcounts : %*d,\nrdispls : %*d,\nrecvtype : "
                  "%*d,\ncomm : %*d,\nerror/return : %*d\n}\n",
                  sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts,
                  rdispls, recvtype, comm, ret_tmp);
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

extern unsigned long long WI4MPI_Neighbor_alltoallw_timeout;
extern unsigned int WI4MPI_Neighbor_alltoallw_print;
void (*_LOCAL_MPI_Neighbor_alltoallw)(void *, int *, size_t *, int *, void *,
                                      int *, size_t *, int *, int *, int *);

void A_f_MPI_Neighbor_alltoallw(void *sendbuf, int *sendcounts, size_t *sdispls,
                                int *sendtypes, void *recvbuf, int *recvcounts,
                                size_t *rdispls, int *recvtypes, int *comm,
                                int *ret) {
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
  if (WI4MPI_Neighbor_alltoallw_print)
    debug_printer("MPI_Neighbor_alltoallw : \n{\nsendbuf : %*d,\nsendcounts : "
                  "%*d,\nsdispls : %*d,\nsendtypes : %*d,\nrecvbuf : "
                  "%*d,\nrecvcounts : %*d,\nrdispls : %*d,\nrecvtypes : "
                  "%*d,\ncomm : %*d,\nerror/return : %*d\n}\n",
                  sendbuf, sendcounts, sdispls, outdegree, sendtypes, recvbuf,
                  recvcounts, rdispls, indegree, recvtypes, comm, ret_tmp);
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

extern unsigned long long WI4MPI_File_iwrite_all_timeout;
extern unsigned int WI4MPI_File_iwrite_all_print;
void (*_LOCAL_MPI_File_iwrite_all)(int *, void *, int *, int *, int *, int *);

void A_f_MPI_File_iwrite_all(int *fh, void *buf, int *count, int *datatype,
                             int *request, int *ret) {
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
  if (WI4MPI_File_iwrite_all_print)
    debug_printer("MPI_File_iwrite_all : \n{\nfh : %*d,\nbuf : %*d,\ncount : "
                  "%*d,\ndatatype : %*d,\nrequest : %*d,\nerror/return : "
                  "%*d\n}\n",
                  fh, buf, count, datatype, request, ret_tmp);
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

extern unsigned long long WI4MPI_File_iwrite_at_all_timeout;
extern unsigned int WI4MPI_File_iwrite_at_all_print;
void (*_LOCAL_MPI_File_iwrite_at_all)(int *, int *, void *, int *, int *, int *,
                                      int *);

void A_f_MPI_File_iwrite_at_all(int *fh, int *offset, void *buf, int *count,
                                int *datatype, int *request, int *ret) {
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
  if (WI4MPI_File_iwrite_at_all_print)
    debug_printer("MPI_File_iwrite_at_all : \n{\nfh : %*d,\noffset : %*d,\nbuf "
                  ": %*d,\ncount : %*d,\ndatatype : %*d,\nrequest : "
                  "%*d,\nerror/return : %*d\n}\n",
                  fh, offset, buf, count, datatype, request, ret_tmp);
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

extern unsigned long long WI4MPI_Aint_add_timeout;
extern unsigned int WI4MPI_Aint_add_print;
void (*_LOCAL_MPI_Aint_add)(size_t *, size_t *, size_t *);

void A_f_MPI_Aint_add(size_t *base, size_t *disp, size_t *ret) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Aint_add_timeout);
#endif
  in_w = 1;
  size_t ret_tmp = 0;

  _LOCAL_MPI_Aint_add(base, disp, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_Aint_add_print)
    debug_printer(
        "MPI_Aint_add : \n{\nbase : %*d,\ndisp : %*d,\nerror/return : %*d\n}\n",
        base, disp, ret_tmp);
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

extern unsigned long long WI4MPI_Aint_diff_timeout;
extern unsigned int WI4MPI_Aint_diff_print;
void (*_LOCAL_MPI_Aint_diff)(size_t *, size_t *, size_t *);

void A_f_MPI_Aint_diff(size_t *addr1, size_t *addr2, size_t *ret) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Aint_diff_timeout);
#endif
  in_w = 1;
  size_t ret_tmp = 0;

  _LOCAL_MPI_Aint_diff(addr1, addr2, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_Aint_diff_print)
    debug_printer("MPI_Aint_diff : \n{\naddr1 : %*d,\naddr2 : "
                  "%*d,\nerror/return : %*d\n}\n",
                  addr1, addr2, ret_tmp);
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

extern unsigned long long WI4MPI_File_iread_all_timeout;
extern unsigned int WI4MPI_File_iread_all_print;
void (*_LOCAL_MPI_File_iread_all)(int *, void *, int *, int *, int *, int *);

void A_f_MPI_File_iread_all(int *fh, void *buf, int *count, int *datatype,
                            int *request, int *ret) {
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
  if (WI4MPI_File_iread_all_print)
    debug_printer("MPI_File_iread_all : \n{\nfh : %*d,\nbuf : %*d,\ncount : "
                  "%*d,\ndatatype : %*d,\nrequest : %*d,\nerror/return : "
                  "%*d\n}\n",
                  fh, buf, count, datatype, request, ret_tmp);
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

extern unsigned long long WI4MPI_File_iread_at_all_timeout;
extern unsigned int WI4MPI_File_iread_at_all_print;
void (*_LOCAL_MPI_File_iread_at_all)(int *, int *, void *, int *, int *, int *,
                                     int *);

void A_f_MPI_File_iread_at_all(int *fh, int *offset, void *buf, int *count,
                               int *datatype, int *request, int *ret) {
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
  if (WI4MPI_File_iread_at_all_print)
    debug_printer("MPI_File_iread_at_all : \n{\nfh : %*d,\noffset : %*d,\nbuf "
                  ": %*d,\ncount : %*d,\ndatatype : %*d,\nrequest : "
                  "%*d,\nerror/return : %*d\n}\n",
                  fh, offset, buf, count, datatype, request, ret_tmp);
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

//#define A_f_MPI_Win_free_keyval _PMPI_Win_free_keyval
//#pragma weak mpi_win_free_keyval_=_PMPI_Win_free_keyval
//#pragma weak mpi_win_free_keyval__=_PMPI_Win_free_keyval
//#pragma weak pmpi_win_free_keyval__=_PMPI_Win_free_keyval
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

//#define A_f_MPI_Win_delete_attr _PMPI_Win_delete_attr
//#pragma weak mpi_win_delete_attr_=_PMPI_Win_delete_attr
//#pragma weak mpi_win_delete_attr__=_PMPI_Win_delete_attr
//#pragma weak pmpi_win_delete_attr__=_PMPI_Win_delete_attr
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

//#define A_f_MPI_Win_get_attr _PMPI_Win_get_attr
//#pragma weak mpi_win_get_attr_=_PMPI_Win_get_attr
//#pragma weak mpi_win_get_attr__=_PMPI_Win_get_attr
//#pragma weak pmpi_win_get_attr__=_PMPI_Win_get_attr
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

//#define A_f_MPI_Win_set_attr _PMPI_Win_set_attr
//#pragma weak mpi_win_set_attr_=_PMPI_Win_set_attr
//#pragma weak mpi_win_set_attr__=_PMPI_Win_set_attr
//#pragma weak pmpi_win_set_attr__=_PMPI_Win_set_attr
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

//#define A_f_MPI_Win_create_keyval _PMPI_Win_create_keyval
//#pragma weak mpi_win_create_keyval_=_PMPI_Win_create_keyval
//#pragma weak mpi_win_create_keyval__=_PMPI_Win_create_keyval
//#pragma weak pmpi_win_create_keyval__=_PMPI_Win_create_keyval
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

//#define A_f_MPI_Win_create_errhandler _PMPI_Win_create_errhandler
//#pragma weak mpi_win_create_errhandler_=_PMPI_Win_create_errhandler
//#pragma weak mpi_win_create_errhandler__=_PMPI_Win_create_errhandler
//#pragma weak pmpi_win_create_errhandler__=_PMPI_Win_create_errhandler
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

//#define A_f_MPI_Win_call_errhandler _PMPI_Win_call_errhandler
//#pragma weak mpi_win_call_errhandler_=_PMPI_Win_call_errhandler
//#pragma weak mpi_win_call_errhandler__=_PMPI_Win_call_errhandler
//#pragma weak pmpi_win_call_errhandler__=_PMPI_Win_call_errhandler
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

//#define A_f_MPI_Win_set_errhandler _PMPI_Win_set_errhandler
//#pragma weak mpi_win_set_errhandler_=_PMPI_Win_set_errhandler
//#pragma weak mpi_win_set_errhandler__=_PMPI_Win_set_errhandler
//#pragma weak pmpi_win_set_errhandler__=_PMPI_Win_set_errhandler
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

//#define A_f_MPI_Win_get_errhandler _PMPI_Win_get_errhandler
//#pragma weak mpi_win_get_errhandler_=_PMPI_Win_get_errhandler
//#pragma weak mpi_win_get_errhandler__=_PMPI_Win_get_errhandler
//#pragma weak pmpi_win_get_errhandler__=_PMPI_Win_get_errhandler
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

//#define A_f_MPI_File_call_errhandler _PMPI_File_call_errhandler
//#pragma weak mpi_file_call_errhandler_=_PMPI_File_call_errhandler
//#pragma weak mpi_file_call_errhandler__=_PMPI_File_call_errhandler
//#pragma weak pmpi_file_call_errhandler__=_PMPI_File_call_errhandler
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

//#define A_f_MPI_File_create_errhandler _PMPI_File_create_errhandler
//#pragma weak mpi_file_create_errhandler_=_PMPI_File_create_errhandler
//#pragma weak mpi_file_create_errhandler__=_PMPI_File_create_errhandler
//#pragma weak pmpi_file_create_errhandler__=_PMPI_File_create_errhandler
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

//#define A_f_MPI_Type_create_keyval _PMPI_Type_create_keyval
//#pragma weak mpi_type_create_keyval_=_PMPI_Type_create_keyval
//#pragma weak mpi_type_create_keyval__=_PMPI_Type_create_keyval
//#pragma weak pmpi_type_create_keyval__=_PMPI_Type_create_keyval
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

//#define A_f_MPI_Grequest_complete _PMPI_Grequest_complete
//#pragma weak mpi_grequest_complete_=_PMPI_Grequest_complete
//#pragma weak mpi_grequest_complete__=_PMPI_Grequest_complete
//#pragma weak pmpi_grequest_complete__=_PMPI_Grequest_complete
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

//#define A_f_MPI_Grequest_start _PMPI_Grequest_start
//#pragma weak mpi_grequest_start_=_PMPI_Grequest_start
//#pragma weak mpi_grequest_start__=_PMPI_Grequest_start
//#pragma weak pmpi_grequest_start__=_PMPI_Grequest_start
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

//#define A_f_MPI_Comm_create_keyval _PMPI_Comm_create_keyval
//#pragma weak mpi_comm_create_keyval_=_PMPI_Comm_create_keyval
//#pragma weak mpi_comm_create_keyval__=_PMPI_Comm_create_keyval
//#pragma weak pmpi_comm_create_keyval__=_PMPI_Comm_create_keyval
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

//#define A_f_MPI_Comm_free_keyval _PMPI_Comm_free_keyval
//#pragma weak mpi_comm_free_keyval_=_PMPI_Comm_free_keyval
//#pragma weak mpi_comm_free_keyval__=_PMPI_Comm_free_keyval
//#pragma weak pmpi_comm_free_keyval__=_PMPI_Comm_free_keyval
void (*_LOCAL_MPI_Comm_free_keyval)(int *, int *);

void A_f_MPI_Comm_free_keyval(int *comm_keyval, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Comm_free_keyval\n");
#endif
  in_w = 1;
  // int ret_tmp=0;
  // int comm=R_f_MPI_COMM_WORLD;
  // int errorcode=7;
  // fprintf(stderr, "Not implemented yet\n");
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

//#define A_f_MPI_Pcontrol _PMPI_Pcontrol
//#pragma weak mpi_pcontrol_=_PMPI_Pcontrol
//#pragma weak mpi_pcontrol__=_PMPI_Pcontrol
//#pragma weak pmpi_pcontrol__=_PMPI_Pcontrol
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

//#define A_f_MPI_Register_datarep _PMPI_Register_datarep
//#pragma weak mpi_register_datarep_=_PMPI_Register_datarep
//#pragma weak mpi_register_datarep__=_PMPI_Register_datarep
//#pragma weak pmpi_register_datarep__=_PMPI_Register_datarep
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

//#define A_f_MPI_Comm_spawn_multiple _PMPI_Comm_spawn_multiple
//#pragma weak mpi_comm_spawn_multiple_=_PMPI_Comm_spawn_multiple
//#pragma weak mpi_comm_spawn_multiple__=_PMPI_Comm_spawn_multiple
//#pragma weak pmpi_comm_spawn_multiple__=_PMPI_Comm_spawn_multiple
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

#ifdef WI4MPI_STATIC
#define WATTR
#else
#define WATTR __attribute__((constructor))
#endif
WATTR void wrapper_init_f(void) {
  dlopen(getenv("WI4MPI_RUN_MPI_LIB"), RTLD_NOW | RTLD_GLOBAL);
  void *lib_handle_f =
      dlopen(getenv("WI4MPI_RUN_MPI_F_LIB"), RTLD_NOW | RTLD_GLOBAL);
  void *lib_handle_io_f =
      dlopen(getenv("WI4MPI_MPIIO_LIB"), RTLD_NOW | RTLD_GLOBAL);

#if !defined(_MPC)
  if (!lib_handle_f) {
    printf("%s not loaded \nerror : %s\n", getenv("WI4MPI_RUN_MPI_F_LIB"),
           dlerror());
    exit(1);
  }
#endif
  /* ABI FIGE */
  _LOCAL_MPI_Win_free_keyval = dlsym(lib_handle_f, "pmpi_win_free_keyval_");
  _LOCAL_MPI_Win_delete_attr = dlsym(lib_handle_f, "pmpi_win_delete_attr_");
  _LOCAL_MPI_Win_get_attr = dlsym(lib_handle_f, "pmpi_win_get_attr_");
  _LOCAL_MPI_Win_set_attr = dlsym(lib_handle_f, "pmpi_win_set_attr_");
  _LOCAL_MPI_Win_create_keyval = dlsym(lib_handle_f, "pmpi_win_create_keyval_");
  _LOCAL_MPI_Win_create_errhandler =
      dlsym(lib_handle_f, "pmpi_win_create_errhandler_");
  _LOCAL_MPI_Win_call_errhandler =
      dlsym(lib_handle_f, "pmpi_win_call_errhandler_");
  _LOCAL_MPI_Win_set_errhandler =
      dlsym(lib_handle_f, "pmpi_win_set_errhandler_");
  _LOCAL_MPI_Win_get_errhandler =
      dlsym(lib_handle_f, "pmpi_win_get_errhandler_");
  _LOCAL_MPI_File_call_errhandler =
      dlsym(lib_handle_io_f, "pmpi_file_call_errhandler_");
  _LOCAL_MPI_File_create_errhandler =
      dlsym(lib_handle_io_f, "pmpi_file_create_errhandler_");
  _LOCAL_MPI_Type_create_keyval =
      dlsym(lib_handle_f, "pmpi_type_create_keyval_");
  _LOCAL_MPI_Grequest_complete = dlsym(lib_handle_f, "pmpi_grequest_complete_");
  _LOCAL_MPI_Grequest_start = dlsym(lib_handle_f, "pmpi_grequest_start_");
  _LOCAL_MPI_Comm_create_keyval =
      dlsym(lib_handle_f, "pmpi_comm_create_keyval_");
  _LOCAL_MPI_Comm_free_keyval = dlsym(lib_handle_f, "pmpi_comm_free_keyval_");
  _LOCAL_MPI_Register_datarep = dlsym(lib_handle_f, "pmpi_register_datarep_");
  _LOCAL_MPI_Comm_spawn_multiple =
      dlsym(lib_handle_f, "pmpi_comm_spawn_multiple_");
  _LOCAL_MPI_Pcontrol = dlsym(lib_handle_f, "pmpi_pcontrol_");
  /* --- */
  _LOCAL_MPI_Send = dlsym(lib_handle_f, "pmpi_send_");
  _LOCAL_MPI_Recv = dlsym(lib_handle_f, "pmpi_recv_");
  _LOCAL_MPI_Get_count = dlsym(lib_handle_f, "pmpi_get_count_");
  _LOCAL_MPI_Bsend = dlsym(lib_handle_f, "pmpi_bsend_");
  _LOCAL_MPI_Ssend = dlsym(lib_handle_f, "pmpi_ssend_");
  _LOCAL_MPI_Rsend = dlsym(lib_handle_f, "pmpi_rsend_");
  _LOCAL_MPI_Buffer_attach = dlsym(lib_handle_f, "pmpi_buffer_attach_");
  _LOCAL_MPI_Buffer_detach = dlsym(lib_handle_f, "pmpi_buffer_detach_");
  _LOCAL_MPI_Isend = dlsym(lib_handle_f, "pmpi_isend_");
  _LOCAL_MPI_Ibsend = dlsym(lib_handle_f, "pmpi_ibsend_");
  _LOCAL_MPI_Issend = dlsym(lib_handle_f, "pmpi_issend_");
  _LOCAL_MPI_Irsend = dlsym(lib_handle_f, "pmpi_irsend_");
  _LOCAL_MPI_Irecv = dlsym(lib_handle_f, "pmpi_irecv_");
  _LOCAL_MPI_Wait = dlsym(lib_handle_f, "pmpi_wait_");
  _LOCAL_MPI_Test = dlsym(lib_handle_f, "pmpi_test_");
  _LOCAL_MPI_Request_free = dlsym(lib_handle_f, "pmpi_request_free_");
  _LOCAL_MPI_Iprobe = dlsym(lib_handle_f, "pmpi_iprobe_");
  _LOCAL_MPI_Probe = dlsym(lib_handle_f, "pmpi_probe_");
  _LOCAL_MPI_Cancel = dlsym(lib_handle_f, "pmpi_cancel_");
  _LOCAL_MPI_Test_cancelled = dlsym(lib_handle_f, "pmpi_test_cancelled_");
  _LOCAL_MPI_Send_init = dlsym(lib_handle_f, "pmpi_send_init_");
  _LOCAL_MPI_Bsend_init = dlsym(lib_handle_f, "pmpi_bsend_init_");
  _LOCAL_MPI_Ssend_init = dlsym(lib_handle_f, "pmpi_ssend_init_");
  _LOCAL_MPI_Rsend_init = dlsym(lib_handle_f, "pmpi_rsend_init_");
  _LOCAL_MPI_Recv_init = dlsym(lib_handle_f, "pmpi_recv_init_");
  _LOCAL_MPI_Start = dlsym(lib_handle_f, "pmpi_start_");
  _LOCAL_MPI_Sendrecv = dlsym(lib_handle_f, "pmpi_sendrecv_");
  _LOCAL_MPI_Sendrecv_replace = dlsym(lib_handle_f, "pmpi_sendrecv_replace_");
  _LOCAL_MPI_Type_contiguous = dlsym(lib_handle_f, "pmpi_type_contiguous_");
  _LOCAL_MPI_Type_vector = dlsym(lib_handle_f, "pmpi_type_vector_");
  _LOCAL_MPI_Type_hvector = dlsym(lib_handle_f, "pmpi_type_hvector_");
  _LOCAL_MPI_Type_indexed = dlsym(lib_handle_f, "pmpi_type_indexed_");
  _LOCAL_MPI_Type_hindexed = dlsym(lib_handle_f, "pmpi_type_hindexed_");
  _LOCAL_MPI_Type_struct = dlsym(lib_handle_f, "pmpi_type_struct_");
  _LOCAL_MPI_Address = dlsym(lib_handle_f, "pmpi_address_");
  _LOCAL_MPI_Type_extent = dlsym(lib_handle_f, "pmpi_type_extent_");
  _LOCAL_MPI_Type_size = dlsym(lib_handle_f, "pmpi_type_size_");
  _LOCAL_MPI_Type_lb = dlsym(lib_handle_f, "pmpi_type_lb_");
  _LOCAL_MPI_Type_ub = dlsym(lib_handle_f, "pmpi_type_ub_");
  _LOCAL_MPI_Type_commit = dlsym(lib_handle_f, "pmpi_type_commit_");
  _LOCAL_MPI_Type_free = dlsym(lib_handle_f, "pmpi_type_free_");
  _LOCAL_MPI_Get_elements = dlsym(lib_handle_f, "pmpi_get_elements_");
  _LOCAL_MPI_Pack = dlsym(lib_handle_f, "pmpi_pack_");
  _LOCAL_MPI_Unpack = dlsym(lib_handle_f, "pmpi_unpack_");
  _LOCAL_MPI_Pack_size = dlsym(lib_handle_f, "pmpi_pack_size_");
  _LOCAL_MPI_Barrier = dlsym(lib_handle_f, "pmpi_barrier_");
  _LOCAL_MPI_Bcast = dlsym(lib_handle_f, "pmpi_bcast_");
  _LOCAL_MPI_Gather = dlsym(lib_handle_f, "pmpi_gather_");
  _LOCAL_MPI_Gatherv = dlsym(lib_handle_f, "pmpi_gatherv_");
  _LOCAL_MPI_Scatter = dlsym(lib_handle_f, "pmpi_scatter_");
  _LOCAL_MPI_Scatterv = dlsym(lib_handle_f, "pmpi_scatterv_");
  _LOCAL_MPI_Allgather = dlsym(lib_handle_f, "pmpi_allgather_");
  _LOCAL_MPI_Allgatherv = dlsym(lib_handle_f, "pmpi_allgatherv_");
  _LOCAL_MPI_Alltoall = dlsym(lib_handle_f, "pmpi_alltoall_");
  _LOCAL_MPI_Alltoallv = dlsym(lib_handle_f, "pmpi_alltoallv_");
  _LOCAL_MPI_Exscan = dlsym(lib_handle_f, "pmpi_exscan_");
  _LOCAL_MPI_Reduce = dlsym(lib_handle_f, "pmpi_reduce_");
  _LOCAL_MPI_Op_create = dlsym(lib_handle_f, "pmpi_op_create_");
  _LOCAL_MPI_Op_free = dlsym(lib_handle_f, "pmpi_op_free_");
  _LOCAL_MPI_Allreduce = dlsym(lib_handle_f, "pmpi_allreduce_");
  _LOCAL_MPI_Scan = dlsym(lib_handle_f, "pmpi_scan_");
  _LOCAL_MPI_Group_size = dlsym(lib_handle_f, "pmpi_group_size_");
  _LOCAL_MPI_Group_rank = dlsym(lib_handle_f, "pmpi_group_rank_");
  _LOCAL_MPI_Group_compare = dlsym(lib_handle_f, "pmpi_group_compare_");
  _LOCAL_MPI_Comm_group = dlsym(lib_handle_f, "pmpi_comm_group_");
  _LOCAL_MPI_Group_union = dlsym(lib_handle_f, "pmpi_group_union_");
  _LOCAL_MPI_Group_intersection =
      dlsym(lib_handle_f, "pmpi_group_intersection_");
  _LOCAL_MPI_Group_difference = dlsym(lib_handle_f, "pmpi_group_difference_");
  _LOCAL_MPI_Group_free = dlsym(lib_handle_f, "pmpi_group_free_");
  _LOCAL_MPI_Comm_size = dlsym(lib_handle_f, "pmpi_comm_size_");
  _LOCAL_MPI_Comm_rank = dlsym(lib_handle_f, "pmpi_comm_rank_");
  _LOCAL_MPI_Comm_compare = dlsym(lib_handle_f, "pmpi_comm_compare_");
  _LOCAL_MPI_Comm_dup = dlsym(lib_handle_f, "pmpi_comm_dup_");
  _LOCAL_MPI_Comm_dup_with_info =
      dlsym(lib_handle_f, "pmpi_comm_dup_with_info_");
  _LOCAL_MPI_Comm_create = dlsym(lib_handle_f, "pmpi_comm_create_");
  _LOCAL_MPI_Comm_split = dlsym(lib_handle_f, "pmpi_comm_split_");
  _LOCAL_MPI_Comm_free = dlsym(lib_handle_f, "pmpi_comm_free_");
  _LOCAL_MPI_Comm_test_inter = dlsym(lib_handle_f, "pmpi_comm_test_inter_");
  _LOCAL_MPI_Comm_remote_size = dlsym(lib_handle_f, "pmpi_comm_remote_size_");
  _LOCAL_MPI_Comm_remote_group = dlsym(lib_handle_f, "pmpi_comm_remote_group_");
  _LOCAL_MPI_Intercomm_create = dlsym(lib_handle_f, "pmpi_intercomm_create_");
  _LOCAL_MPI_Intercomm_merge = dlsym(lib_handle_f, "pmpi_intercomm_merge_");
  _LOCAL_MPI_Keyval_create = dlsym(lib_handle_f, "pmpi_keyval_create_");
  _LOCAL_MPI_Keyval_free = dlsym(lib_handle_f, "pmpi_keyval_free_");
  _LOCAL_MPI_Attr_put = dlsym(lib_handle_f, "pmpi_attr_put_");
  _LOCAL_MPI_Attr_get = dlsym(lib_handle_f, "pmpi_attr_get_");
  _LOCAL_MPI_Attr_delete = dlsym(lib_handle_f, "pmpi_attr_delete_");
  _LOCAL_MPI_Topo_test = dlsym(lib_handle_f, "pmpi_topo_test_");
  _LOCAL_MPI_Graphdims_get = dlsym(lib_handle_f, "pmpi_graphdims_get_");
  _LOCAL_MPI_Cartdim_get = dlsym(lib_handle_f, "pmpi_cartdim_get_");
  _LOCAL_MPI_Graph_neighbors_count =
      dlsym(lib_handle_f, "pmpi_graph_neighbors_count_");
  _LOCAL_MPI_Cart_shift = dlsym(lib_handle_f, "pmpi_cart_shift_");
  _LOCAL_MPI_Get_version = dlsym(lib_handle_f, "pmpi_get_version_");
  _LOCAL_MPI_Errhandler_create = dlsym(lib_handle_f, "pmpi_errhandler_create_");
  _LOCAL_MPI_Errhandler_set = dlsym(lib_handle_f, "pmpi_errhandler_set_");
  _LOCAL_MPI_Errhandler_get = dlsym(lib_handle_f, "pmpi_errhandler_get_");
  _LOCAL_MPI_Errhandler_free = dlsym(lib_handle_f, "pmpi_errhandler_free_");
  _LOCAL_MPI_Error_class = dlsym(lib_handle_f, "pmpi_error_class_");
  _LOCAL_MPI_Initialized = dlsym(lib_handle_f, "pmpi_initialized_");
  _LOCAL_MPI_Abort = dlsym(lib_handle_f, "pmpi_abort_");
  _LOCAL_MPI_Init = dlsym(lib_handle_f, "pmpi_init_");
  _LOCAL_MPI_Comm_accept = dlsym(lib_handle_f, "pmpi_comm_accept_");
  _LOCAL_MPI_Comm_connect = dlsym(lib_handle_f, "pmpi_comm_connect_");
  _LOCAL_MPI_Comm_disconnect = dlsym(lib_handle_f, "pmpi_comm_disconnect_");
  _LOCAL_MPI_Comm_get_parent = dlsym(lib_handle_f, "pmpi_comm_get_parent_");
  _LOCAL_MPI_Comm_join = dlsym(lib_handle_f, "pmpi_comm_join_");
  _LOCAL_MPI_Comm_set_info = dlsym(lib_handle_f, "pmpi_comm_set_info_");
  _LOCAL_MPI_Comm_get_info = dlsym(lib_handle_f, "pmpi_comm_get_info_");
  _LOCAL_MPI_Accumulate = dlsym(lib_handle_f, "pmpi_accumulate_");
  _LOCAL_MPI_Get = dlsym(lib_handle_f, "pmpi_get_");
  _LOCAL_MPI_Put = dlsym(lib_handle_f, "pmpi_put_");
  _LOCAL_MPI_Win_complete = dlsym(lib_handle_f, "pmpi_win_complete_");
  _LOCAL_MPI_Win_create = dlsym(lib_handle_f, "pmpi_win_create_");
  _LOCAL_MPI_Win_fence = dlsym(lib_handle_f, "pmpi_win_fence_");
  _LOCAL_MPI_Win_free = dlsym(lib_handle_f, "pmpi_win_free_");
  _LOCAL_MPI_Win_get_group = dlsym(lib_handle_f, "pmpi_win_get_group_");
  _LOCAL_MPI_Win_lock = dlsym(lib_handle_f, "pmpi_win_lock_");
  _LOCAL_MPI_Win_post = dlsym(lib_handle_f, "pmpi_win_post_");
  _LOCAL_MPI_Win_start = dlsym(lib_handle_f, "pmpi_win_start_");
  _LOCAL_MPI_Win_test = dlsym(lib_handle_f, "pmpi_win_test_");
  _LOCAL_MPI_Win_unlock = dlsym(lib_handle_f, "pmpi_win_unlock_");
  _LOCAL_MPI_Win_wait = dlsym(lib_handle_f, "pmpi_win_wait_");
  _LOCAL_MPI_Win_allocate = dlsym(lib_handle_f, "pmpi_win_allocate_");
  _LOCAL_MPI_Win_allocate_shared =
      dlsym(lib_handle_f, "pmpi_win_allocate_shared_");
  _LOCAL_MPI_Win_shared_query = dlsym(lib_handle_f, "pmpi_win_shared_query_");
  _LOCAL_MPI_Win_create_dynamic =
      dlsym(lib_handle_f, "pmpi_win_create_dynamic_");
  _LOCAL_MPI_Win_attach = dlsym(lib_handle_f, "pmpi_win_attach_");
  _LOCAL_MPI_Win_detach = dlsym(lib_handle_f, "pmpi_win_detach_");
  _LOCAL_MPI_Win_get_info = dlsym(lib_handle_f, "pmpi_win_get_info_");
  _LOCAL_MPI_Win_set_info = dlsym(lib_handle_f, "pmpi_win_set_info_");
  _LOCAL_MPI_Get_accumulate = dlsym(lib_handle_f, "pmpi_get_accumulate_");
  _LOCAL_MPI_Fetch_and_op = dlsym(lib_handle_f, "pmpi_fetch_and_op_");
  _LOCAL_MPI_Compare_and_swap = dlsym(lib_handle_f, "pmpi_compare_and_swap_");
  _LOCAL_MPI_Rput = dlsym(lib_handle_f, "pmpi_rput_");
  _LOCAL_MPI_Rget = dlsym(lib_handle_f, "pmpi_rget_");
  _LOCAL_MPI_Raccumulate = dlsym(lib_handle_f, "pmpi_raccumulate_");
  _LOCAL_MPI_Rget_accumulate = dlsym(lib_handle_f, "pmpi_rget_accumulate_");
  _LOCAL_MPI_Win_lock_all = dlsym(lib_handle_f, "pmpi_win_lock_all_");
  _LOCAL_MPI_Win_unlock_all = dlsym(lib_handle_f, "pmpi_win_unlock_all_");
  _LOCAL_MPI_Win_flush = dlsym(lib_handle_f, "pmpi_win_flush_");
  _LOCAL_MPI_Win_flush_all = dlsym(lib_handle_f, "pmpi_win_flush_all_");
  _LOCAL_MPI_Win_flush_local = dlsym(lib_handle_f, "pmpi_win_flush_local_");
  _LOCAL_MPI_Win_flush_local_all =
      dlsym(lib_handle_f, "pmpi_win_flush_local_all_");
  _LOCAL_MPI_Win_sync = dlsym(lib_handle_f, "pmpi_win_sync_");
  _LOCAL_MPI_Add_error_class = dlsym(lib_handle_f, "pmpi_add_error_class_");
  _LOCAL_MPI_Add_error_code = dlsym(lib_handle_f, "pmpi_add_error_code_");
  _LOCAL_MPI_Comm_call_errhandler =
      dlsym(lib_handle_f, "pmpi_comm_call_errhandler_");
  _LOCAL_MPI_Comm_delete_attr = dlsym(lib_handle_f, "pmpi_comm_delete_attr_");
  _LOCAL_MPI_Comm_get_attr = dlsym(lib_handle_f, "pmpi_comm_get_attr_");
  _LOCAL_MPI_Comm_set_attr = dlsym(lib_handle_f, "pmpi_comm_set_attr_");
  _LOCAL_MPI_Init_thread = dlsym(lib_handle_f, "pmpi_init_thread_");
  _LOCAL_MPI_Is_thread_main = dlsym(lib_handle_f, "pmpi_is_thread_main_");
  _LOCAL_MPI_Query_thread = dlsym(lib_handle_f, "pmpi_query_thread_");
  _LOCAL_MPI_Status_set_cancelled =
      dlsym(lib_handle_f, "pmpi_status_set_cancelled_");
  _LOCAL_MPI_Status_set_elements =
      dlsym(lib_handle_f, "pmpi_status_set_elements_");
  _LOCAL_MPI_Type_delete_attr = dlsym(lib_handle_f, "pmpi_type_delete_attr_");
  _LOCAL_MPI_Type_dup = dlsym(lib_handle_f, "pmpi_type_dup_");
  _LOCAL_MPI_Type_free_keyval = dlsym(lib_handle_f, "pmpi_type_free_keyval_");
  _LOCAL_MPI_Type_get_attr = dlsym(lib_handle_f, "pmpi_type_get_attr_");
  _LOCAL_MPI_Type_get_envelope = dlsym(lib_handle_f, "pmpi_type_get_envelope_");
  _LOCAL_MPI_Type_set_attr = dlsym(lib_handle_f, "pmpi_type_set_attr_");
  _LOCAL_MPI_Type_match_size = dlsym(lib_handle_f, "pmpi_type_match_size_");
  _LOCAL_MPI_Alloc_mem = dlsym(lib_handle_f, "pmpi_alloc_mem_");
  _LOCAL_MPI_Comm_create_errhandler =
      dlsym(lib_handle_f, "pmpi_comm_create_errhandler_");
  _LOCAL_MPI_Comm_get_errhandler =
      dlsym(lib_handle_f, "pmpi_comm_get_errhandler_");
  _LOCAL_MPI_Comm_set_errhandler =
      dlsym(lib_handle_f, "pmpi_comm_set_errhandler_");
  _LOCAL_MPI_File_get_errhandler =
      dlsym(lib_handle_io_f, "pmpi_file_get_errhandler_");
  _LOCAL_MPI_File_set_errhandler =
      dlsym(lib_handle_io_f, "pmpi_file_set_errhandler_");
  _LOCAL_MPI_Finalized = dlsym(lib_handle_f, "pmpi_finalized_");
  _LOCAL_MPI_Free_mem = dlsym(lib_handle_f, "pmpi_free_mem_");
  _LOCAL_MPI_Get_address = dlsym(lib_handle_f, "pmpi_get_address_");
  _LOCAL_MPI_Info_create = dlsym(lib_handle_f, "pmpi_info_create_");
  _LOCAL_MPI_Info_dup = dlsym(lib_handle_f, "pmpi_info_dup_");
  _LOCAL_MPI_Info_free = dlsym(lib_handle_f, "pmpi_info_free_");
  _LOCAL_MPI_Info_get_nkeys = dlsym(lib_handle_f, "pmpi_info_get_nkeys_");
  _LOCAL_MPI_Request_get_status =
      dlsym(lib_handle_f, "pmpi_request_get_status_");
  _LOCAL_MPI_Type_create_hvector =
      dlsym(lib_handle_f, "pmpi_type_create_hvector_");
  _LOCAL_MPI_Type_create_resized =
      dlsym(lib_handle_f, "pmpi_type_create_resized_");
  _LOCAL_MPI_Type_get_extent = dlsym(lib_handle_f, "pmpi_type_get_extent_");
  _LOCAL_MPI_Type_get_true_extent =
      dlsym(lib_handle_f, "pmpi_type_get_true_extent_");
  _LOCAL_MPI_Type_create_f90_integer =
      dlsym(lib_handle_f, "pmpi_type_create_f90_integer_");
  _LOCAL_MPI_Type_create_f90_real =
      dlsym(lib_handle_f, "pmpi_type_create_f90_real_");
  _LOCAL_MPI_Type_create_f90_complex =
      dlsym(lib_handle_f, "pmpi_type_create_f90_complex_");
  _LOCAL_MPI_Reduce_local = dlsym(lib_handle_f, "pmpi_reduce_local_");
  _LOCAL_MPI_Op_commutative = dlsym(lib_handle_f, "pmpi_op_commutative_");
  _LOCAL_MPI_Reduce_scatter_block =
      dlsym(lib_handle_f, "pmpi_reduce_scatter_block_");
  _LOCAL_MPI_Dist_graph_neighbors_count =
      dlsym(lib_handle_f, "pmpi_dist_graph_neighbors_count_");
  _LOCAL_MPI_Improbe = dlsym(lib_handle_f, "pmpi_improbe_");
  _LOCAL_MPI_Imrecv = dlsym(lib_handle_f, "pmpi_imrecv_");
  _LOCAL_MPI_Mprobe = dlsym(lib_handle_f, "pmpi_mprobe_");
  _LOCAL_MPI_Mrecv = dlsym(lib_handle_f, "pmpi_mrecv_");
  _LOCAL_MPI_Comm_idup = dlsym(lib_handle_f, "pmpi_comm_idup_");
  _LOCAL_MPI_Ibarrier = dlsym(lib_handle_f, "pmpi_ibarrier_");
  _LOCAL_MPI_Ibcast = dlsym(lib_handle_f, "pmpi_ibcast_");
  _LOCAL_MPI_Igather = dlsym(lib_handle_f, "pmpi_igather_");
  _LOCAL_MPI_Iscatter = dlsym(lib_handle_f, "pmpi_iscatter_");
  _LOCAL_MPI_Iallgather = dlsym(lib_handle_f, "pmpi_iallgather_");
  _LOCAL_MPI_Ialltoall = dlsym(lib_handle_f, "pmpi_ialltoall_");
  _LOCAL_MPI_Ireduce = dlsym(lib_handle_f, "pmpi_ireduce_");
  _LOCAL_MPI_Iallreduce = dlsym(lib_handle_f, "pmpi_iallreduce_");
  _LOCAL_MPI_Ireduce_scatter_block =
      dlsym(lib_handle_f, "pmpi_ireduce_scatter_block_");
  _LOCAL_MPI_Iscan = dlsym(lib_handle_f, "pmpi_iscan_");
  _LOCAL_MPI_Iexscan = dlsym(lib_handle_f, "pmpi_iexscan_");
  _LOCAL_MPI_Ineighbor_allgather =
      dlsym(lib_handle_f, "pmpi_ineighbor_allgather_");
  _LOCAL_MPI_Ineighbor_alltoall =
      dlsym(lib_handle_f, "pmpi_ineighbor_alltoall_");
  _LOCAL_MPI_Neighbor_allgather =
      dlsym(lib_handle_f, "pmpi_neighbor_allgather_");
  _LOCAL_MPI_Neighbor_alltoall = dlsym(lib_handle_f, "pmpi_neighbor_alltoall_");
  _LOCAL_MPI_Comm_split_type = dlsym(lib_handle_f, "pmpi_comm_split_type_");
  _LOCAL_MPI_Get_elements_x = dlsym(lib_handle_f, "pmpi_get_elements_x_");
  _LOCAL_MPI_Status_set_elements_x =
      dlsym(lib_handle_f, "pmpi_status_set_elements_x_");
  _LOCAL_MPI_Type_get_extent_x = dlsym(lib_handle_f, "pmpi_type_get_extent_x_");
  _LOCAL_MPI_Type_get_true_extent_x =
      dlsym(lib_handle_f, "pmpi_type_get_true_extent_x_");
  _LOCAL_MPI_Type_size_x = dlsym(lib_handle_f, "pmpi_type_size_x_");
  _LOCAL_MPI_Comm_create_group = dlsym(lib_handle_f, "pmpi_comm_create_group_");
  _LOCAL_MPI_File_close = dlsym(lib_handle_io_f, "pmpi_file_close_");
  _LOCAL_MPI_File_set_size = dlsym(lib_handle_io_f, "pmpi_file_set_size_");
  _LOCAL_MPI_File_preallocate =
      dlsym(lib_handle_io_f, "pmpi_file_preallocate_");
  _LOCAL_MPI_File_get_size = dlsym(lib_handle_io_f, "pmpi_file_get_size_");
  _LOCAL_MPI_File_get_group = dlsym(lib_handle_io_f, "pmpi_file_get_group_");
  _LOCAL_MPI_File_get_amode = dlsym(lib_handle_io_f, "pmpi_file_get_amode_");
  _LOCAL_MPI_File_set_info = dlsym(lib_handle_io_f, "pmpi_file_set_info_");
  _LOCAL_MPI_File_get_info = dlsym(lib_handle_io_f, "pmpi_file_get_info_");
  _LOCAL_MPI_File_read_at = dlsym(lib_handle_io_f, "pmpi_file_read_at_");
  _LOCAL_MPI_File_read_at_all =
      dlsym(lib_handle_io_f, "pmpi_file_read_at_all_");
  _LOCAL_MPI_File_write_at = dlsym(lib_handle_io_f, "pmpi_file_write_at_");
  _LOCAL_MPI_File_write_at_all =
      dlsym(lib_handle_io_f, "pmpi_file_write_at_all_");
  _LOCAL_MPI_File_iread_at = dlsym(lib_handle_io_f, "pmpi_file_iread_at_");
  _LOCAL_MPI_File_iwrite_at = dlsym(lib_handle_io_f, "pmpi_file_iwrite_at_");
  _LOCAL_MPI_File_read = dlsym(lib_handle_io_f, "pmpi_file_read_");
  _LOCAL_MPI_File_read_all = dlsym(lib_handle_io_f, "pmpi_file_read_all_");
  _LOCAL_MPI_File_write = dlsym(lib_handle_io_f, "pmpi_file_write_");
  _LOCAL_MPI_File_write_all = dlsym(lib_handle_io_f, "pmpi_file_write_all_");
  _LOCAL_MPI_File_iread = dlsym(lib_handle_io_f, "pmpi_file_iread_");
  _LOCAL_MPI_File_iwrite = dlsym(lib_handle_io_f, "pmpi_file_iwrite_");
  _LOCAL_MPI_File_seek = dlsym(lib_handle_io_f, "pmpi_file_seek_");
  _LOCAL_MPI_File_get_position =
      dlsym(lib_handle_io_f, "pmpi_file_get_position_");
  _LOCAL_MPI_File_get_byte_offset =
      dlsym(lib_handle_io_f, "pmpi_file_get_byte_offset_");
  _LOCAL_MPI_File_read_shared =
      dlsym(lib_handle_io_f, "pmpi_file_read_shared_");
  _LOCAL_MPI_File_write_shared =
      dlsym(lib_handle_io_f, "pmpi_file_write_shared_");
  _LOCAL_MPI_File_iread_shared =
      dlsym(lib_handle_io_f, "pmpi_file_iread_shared_");
  _LOCAL_MPI_File_iwrite_shared =
      dlsym(lib_handle_io_f, "pmpi_file_iwrite_shared_");
  _LOCAL_MPI_File_read_ordered =
      dlsym(lib_handle_io_f, "pmpi_file_read_ordered_");
  _LOCAL_MPI_File_write_ordered =
      dlsym(lib_handle_io_f, "pmpi_file_write_ordered_");
  _LOCAL_MPI_File_seek_shared =
      dlsym(lib_handle_io_f, "pmpi_file_seek_shared_");
  _LOCAL_MPI_File_get_position_shared =
      dlsym(lib_handle_io_f, "pmpi_file_get_position_shared_");
  _LOCAL_MPI_File_read_at_all_begin =
      dlsym(lib_handle_io_f, "pmpi_file_read_at_all_begin_");
  _LOCAL_MPI_File_read_at_all_end =
      dlsym(lib_handle_io_f, "pmpi_file_read_at_all_end_");
  _LOCAL_MPI_File_write_at_all_begin =
      dlsym(lib_handle_io_f, "pmpi_file_write_at_all_begin_");
  _LOCAL_MPI_File_write_at_all_end =
      dlsym(lib_handle_io_f, "pmpi_file_write_at_all_end_");
  _LOCAL_MPI_File_read_all_begin =
      dlsym(lib_handle_io_f, "pmpi_file_read_all_begin_");
  _LOCAL_MPI_File_read_all_end =
      dlsym(lib_handle_io_f, "pmpi_file_read_all_end_");
  _LOCAL_MPI_File_write_all_begin =
      dlsym(lib_handle_io_f, "pmpi_file_write_all_begin_");
  _LOCAL_MPI_File_write_all_end =
      dlsym(lib_handle_io_f, "pmpi_file_write_all_end_");
  _LOCAL_MPI_File_read_ordered_begin =
      dlsym(lib_handle_io_f, "pmpi_file_read_ordered_begin_");
  _LOCAL_MPI_File_read_ordered_end =
      dlsym(lib_handle_io_f, "pmpi_file_read_ordered_end_");
  _LOCAL_MPI_File_write_ordered_begin =
      dlsym(lib_handle_io_f, "pmpi_file_write_ordered_begin_");
  _LOCAL_MPI_File_write_ordered_end =
      dlsym(lib_handle_io_f, "pmpi_file_write_ordered_end_");
  _LOCAL_MPI_File_get_type_extent =
      dlsym(lib_handle_io_f, "pmpi_file_get_type_extent_");
  _LOCAL_MPI_File_set_atomicity =
      dlsym(lib_handle_io_f, "pmpi_file_set_atomicity_");
  _LOCAL_MPI_File_get_atomicity =
      dlsym(lib_handle_io_f, "pmpi_file_get_atomicity_");
  _LOCAL_MPI_File_sync = dlsym(lib_handle_io_f, "pmpi_file_sync_");
  _LOCAL_MPI_Wtime = dlsym(lib_handle_f, "pmpi_wtime_");
  _LOCAL_MPI_Wtick = dlsym(lib_handle_f, "pmpi_wtick_");
  _LOCAL_MPI_Finalize = dlsym(lib_handle_f, "pmpi_finalize_");
  _LOCAL_MPI_Waitany = dlsym(lib_handle_f, "pmpi_waitany_");
  _LOCAL_MPI_Testany = dlsym(lib_handle_f, "pmpi_testany_");
  _LOCAL_MPI_Waitall = dlsym(lib_handle_f, "pmpi_waitall_");
  _LOCAL_MPI_Testall = dlsym(lib_handle_f, "pmpi_testall_");
  _LOCAL_MPI_Waitsome = dlsym(lib_handle_f, "pmpi_waitsome_");
  _LOCAL_MPI_Testsome = dlsym(lib_handle_f, "pmpi_testsome_");
  _LOCAL_MPI_Startall = dlsym(lib_handle_f, "pmpi_startall_");
  _LOCAL_MPI_Alltoallw = dlsym(lib_handle_f, "pmpi_alltoallw_");
  _LOCAL_MPI_Reduce_scatter = dlsym(lib_handle_f, "pmpi_reduce_scatter_");
  _LOCAL_MPI_Group_translate_ranks =
      dlsym(lib_handle_f, "pmpi_group_translate_ranks_");
  _LOCAL_MPI_Group_incl = dlsym(lib_handle_f, "pmpi_group_incl_");
  _LOCAL_MPI_Group_excl = dlsym(lib_handle_f, "pmpi_group_excl_");
  _LOCAL_MPI_Group_range_incl = dlsym(lib_handle_f, "pmpi_group_range_incl_");
  _LOCAL_MPI_Group_range_excl = dlsym(lib_handle_f, "pmpi_group_range_excl_");
  _LOCAL_MPI_Cart_create = dlsym(lib_handle_f, "pmpi_cart_create_");
  _LOCAL_MPI_Dims_create = dlsym(lib_handle_f, "pmpi_dims_create_");
  _LOCAL_MPI_Graph_create = dlsym(lib_handle_f, "pmpi_graph_create_");
  _LOCAL_MPI_Graph_get = dlsym(lib_handle_f, "pmpi_graph_get_");
  _LOCAL_MPI_Cart_get = dlsym(lib_handle_f, "pmpi_cart_get_");
  _LOCAL_MPI_Cart_rank = dlsym(lib_handle_f, "pmpi_cart_rank_");
  _LOCAL_MPI_Cart_coords = dlsym(lib_handle_f, "pmpi_cart_coords_");
  _LOCAL_MPI_Graph_neighbors = dlsym(lib_handle_f, "pmpi_graph_neighbors_");
  _LOCAL_MPI_Cart_sub = dlsym(lib_handle_f, "pmpi_cart_sub_");
  _LOCAL_MPI_Cart_map = dlsym(lib_handle_f, "pmpi_cart_map_");
  _LOCAL_MPI_Graph_map = dlsym(lib_handle_f, "pmpi_graph_map_");
  _LOCAL_MPI_Type_get_contents = dlsym(lib_handle_f, "pmpi_type_get_contents_");
  _LOCAL_MPI_Type_create_darray =
      dlsym(lib_handle_f, "pmpi_type_create_darray_");
  _LOCAL_MPI_Type_create_hindexed =
      dlsym(lib_handle_f, "pmpi_type_create_hindexed_");
  _LOCAL_MPI_Type_create_indexed_block =
      dlsym(lib_handle_f, "pmpi_type_create_indexed_block_");
  _LOCAL_MPI_Type_create_hindexed_block =
      dlsym(lib_handle_f, "pmpi_type_create_hindexed_block_");
  _LOCAL_MPI_Type_create_struct =
      dlsym(lib_handle_f, "pmpi_type_create_struct_");
  _LOCAL_MPI_Type_create_subarray =
      dlsym(lib_handle_f, "pmpi_type_create_subarray_");
  _LOCAL_MPI_Dist_graph_create_adjacent =
      dlsym(lib_handle_f, "pmpi_dist_graph_create_adjacent_");
  _LOCAL_MPI_Dist_graph_create = dlsym(lib_handle_f, "pmpi_dist_graph_create_");
  _LOCAL_MPI_Dist_graph_neighbors =
      dlsym(lib_handle_f, "pmpi_dist_graph_neighbors_");
  _LOCAL_MPI_Igatherv = dlsym(lib_handle_f, "pmpi_igatherv_");
  _LOCAL_MPI_Iscatterv = dlsym(lib_handle_f, "pmpi_iscatterv_");
  _LOCAL_MPI_Iallgatherv = dlsym(lib_handle_f, "pmpi_iallgatherv_");
  _LOCAL_MPI_Ialltoallv = dlsym(lib_handle_f, "pmpi_ialltoallv_");
  _LOCAL_MPI_Ialltoallw = dlsym(lib_handle_f, "pmpi_ialltoallw_");
  _LOCAL_MPI_Ireduce_scatter = dlsym(lib_handle_f, "pmpi_ireduce_scatter_");
  _LOCAL_MPI_Ineighbor_allgatherv =
      dlsym(lib_handle_f, "pmpi_ineighbor_allgatherv_");
  _LOCAL_MPI_Ineighbor_alltoallv =
      dlsym(lib_handle_f, "pmpi_ineighbor_alltoallv_");
  _LOCAL_MPI_Ineighbor_alltoallw =
      dlsym(lib_handle_f, "pmpi_ineighbor_alltoallw_");
  _LOCAL_MPI_Neighbor_allgatherv =
      dlsym(lib_handle_f, "pmpi_neighbor_allgatherv_");
  _LOCAL_MPI_Neighbor_alltoallv =
      dlsym(lib_handle_f, "pmpi_neighbor_alltoallv_");
  _LOCAL_MPI_Neighbor_alltoallw =
      dlsym(lib_handle_f, "pmpi_neighbor_alltoallw_");
  _LOCAL_MPI_File_iwrite_all = dlsym(lib_handle_io_f, "pmpi_file_iwrite_all_");
  _LOCAL_MPI_File_iwrite_at_all =
      dlsym(lib_handle_io_f, "pmpi_file_iwrite_at_all_");
  _LOCAL_MPI_Aint_add = dlsym(lib_handle_f, "pmpi_aint_add_");
  _LOCAL_MPI_Aint_diff = dlsym(lib_handle_f, "pmpi_aint_diff_");
  _LOCAL_MPI_File_iread_all = dlsym(lib_handle_io_f, "pmpi_file_iread_all_");
  _LOCAL_MPI_File_iread_at_all =
      dlsym(lib_handle_io_f, "pmpi_file_iread_at_all_");
  _LOCAL_MPI_Error_string = dlsym(lib_handle_f, "pmpi_error_string_");
  _LOCAL_MPI_Get_processor_name =
      dlsym(lib_handle_f, "pmpi_get_processor_name_");
  _LOCAL_MPI_File_open = dlsym(lib_handle_io_f, "pmpi_file_open_");
  _LOCAL_MPI_File_set_view = dlsym(lib_handle_io_f, "pmpi_file_set_view_");
  _LOCAL_MPI_File_get_view = dlsym(lib_handle_io_f, "pmpi_file_get_view_");
  _LOCAL_MPI_File_delete = dlsym(lib_handle_io_f, "pmpi_file_delete_");
  _LOCAL_MPI_Info_delete = dlsym(lib_handle_f, "pmpi_info_delete_");
  _LOCAL_MPI_Info_get = dlsym(lib_handle_f, "pmpi_info_get_");
  _LOCAL_MPI_Info_get_nthkey = dlsym(lib_handle_f, "pmpi_info_get_nthkey_");
  _LOCAL_MPI_Info_get_valuelen = dlsym(lib_handle_f, "pmpi_info_get_valuelen_");
  _LOCAL_MPI_Info_set = dlsym(lib_handle_f, "pmpi_info_set_");
  _LOCAL_MPI_Win_get_name = dlsym(lib_handle_f, "pmpi_win_get_name_");
  _LOCAL_MPI_Win_set_name = dlsym(lib_handle_f, "pmpi_win_set_name_");
  _LOCAL_MPI_Comm_get_name = dlsym(lib_handle_f, "pmpi_comm_get_name_");
  _LOCAL_MPI_Comm_set_name = dlsym(lib_handle_f, "pmpi_comm_set_name_");
  _LOCAL_MPI_Comm_spawn = dlsym(lib_handle_f, "pmpi_comm_spawn_");
  _LOCAL_MPI_Type_get_name = dlsym(lib_handle_f, "pmpi_type_get_name_");
  _LOCAL_MPI_Type_set_name = dlsym(lib_handle_f, "pmpi_type_set_name_");
  _LOCAL_MPI_Add_error_string = dlsym(lib_handle_f, "pmpi_add_error_string_");
  _LOCAL_MPI_Close_port = dlsym(lib_handle_f, "pmpi_close_port_");
  _LOCAL_MPI_Get_library_version =
      dlsym(lib_handle_f, "pmpi_get_library_version_");
  _LOCAL_MPI_Open_port = dlsym(lib_handle_f, "pmpi_open_port_");
  _LOCAL_MPI_Publish_name = dlsym(lib_handle_f, "pmpi_publish_name_");
  _LOCAL_MPI_Unpublish_name = dlsym(lib_handle_f, "pmpi_unpublish_name_");
  _LOCAL_MPI_Lookup_name = dlsym(lib_handle_f, "pmpi_lookup_name_");
  _LOCAL_MPI_Pack_external = dlsym(lib_handle_f, "pmpi_pack_external_");
  _LOCAL_MPI_Pack_external_size =
      dlsym(lib_handle_f, "pmpi_pack_external_size_");
  _LOCAL_MPI_Unpack_external = dlsym(lib_handle_f, "pmpi_unpack_external_");
#if defined(OMPI_OMPI) || defined(_OMPI)
  ccc_mpi_fortran_bottom_ = dlsym(lib_handle_f, "mpi_fortran_bottom_");
  ccc_mpi_fortran_in_place_ = dlsym(lib_handle_f, "mpi_fortran_in_place_");
  ccc_mpi_fortran_argv_null_ = dlsym(lib_handle_f, "mpi_fortran_argv_null_");
  ccc_mpi_fortran_argvs_null_ = dlsym(lib_handle_f, "mpi_fortran_argvs_null_");
  ccc_mpi_fortran_errcodes_ignore_ =
      dlsym(lib_handle_f, "mpi_fortran_errcodes_ignore_");
  ccc_mpi_fortran_status_ignore_ =
      dlsym(lib_handle_f, "mpi_fortran_status_ignore_");
  ccc_mpi_fortran_statuses_ignore_ =
      dlsym(lib_handle_f, "mpi_fortran_statuses_ignore_");
  ccc_mpi_fortran_unweighted_ = dlsym(lib_handle_f, "mpi_fortran_unweighted_");
  ccc_mpi_fortran_weights_empty_ =
      dlsym(lib_handle_f, "mpi_fortran_weights_empty_");
#endif
#if defined(OMPI_INTEL) || defined(_INTEL) || defined(_MPC)
  ccc_mpi_fortran_bottom_ = dlsym(lib_handle_f, "mpipriv1_");
  ccc_mpi_fortran_in_place_ = ((int *)dlsym(lib_handle_f, "mpipriv1_") + 1);
  ccc_mpi_fortran_argv_null_ = ((int *)dlsym(lib_handle_f, "mpiprivc_") + 1);
  ccc_mpi_fortran_argvs_null_ = dlsym(lib_handle_f, "mpiprivc_");
  ccc_mpi_fortran_errcodes_ignore_ =
      ((int *)dlsym(lib_handle_f, "mpipriv2_") + 1);
  ccc_mpi_fortran_status_ignore_ =
      ((int *)dlsym(lib_handle_f, "mpipriv1_") + 2);
  ccc_mpi_fortran_statuses_ignore_ = dlsym(lib_handle_f, "mpipriv2_");
  ccc_mpi_fortran_unweighted_ = dlsym(lib_handle_f, "mpifcmb5_");
  ccc_mpi_fortran_weights_empty_ = dlsym(lib_handle_f, "mpifcmb9_");
#endif
}

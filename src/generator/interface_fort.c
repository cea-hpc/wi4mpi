#include <stdlib.h>
#define _GNU_SOURCE
#include "manual_interface.h"
#include <dlfcn.h>
#include <stdio.h>

void *mpi_comm_null_copy_fn_ = NULL;
void *mpi_comm_null_copy_fn_ = NULL;
void *mpi_win_dup_fn_ = NULL;
void *mpi_null_copy_fn_ = NULL;
void *mpi_comm_null_delete_fn_ = NULL;
void *mpi_comm_dup_fn_ = NULL;
void *mpi_type_null_copy_fn_ = NULL;
void *mpi_null_delete_fn_ = NULL;
void *mpi_dup_fn_ = NULL;
void *mpi_conversion_fn_null_ = NULL;
void *mpi_win_null_delete_fn_ = NULL;
void *mpi_type_null_delete_fn_ = NULL;
void *mpi_type_dup_fn_ = NULL;
void *mpi_win_null_copy_fn_ = NULL;
/*ompi constante*/
int mpi_fortran_bottom_;
int mpi_fortran_in_place_;
int mpi_fortran_argv_null_;
int mpi_fortran_argvs_null_;
int mpi_fortran_errcodes_ignore_;
int mpi_fortran_status_ignore_;
int mpi_fortran_statuses_ignore_;
int mpi_fortran_unweighted_;
int mpi_fortran_weights_empty_;

char wi4mpi_mode_f[] = "";

void mpi_send_(void *buf, int *count, int *datatype, int *dest, int *tag,
               int *comm, int *ret);
#pragma weak mpi_send_ = pmpi_send_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Send(void *buf, int *count, int *datatype, int *dest,
                            int *tag, int *comm, int *ret);

void INTERF_2_INTEL_MPI_Send(void *buf, int *count, int *datatype, int *dest,
                             int *tag, int *comm, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Send)(                 \
    void *buf, int *count, int *datatype, int *dest, int *tag, int *comm,      \
    int *ret);                                                                 \
    void pmpi_send_(void *buf, int *count, int *datatype, int *dest, int *tag, \
                    int *comm, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Send(buf, count, datatype, dest, tag, comm); }

void mpi_recv_(void *buf, int *count, int *datatype, int *source, int *tag,
               int *comm, int *status, int *ret);
#pragma weak mpi_recv_ = pmpi_recv_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Recv(void *buf, int *count, int *datatype, int *source,
                            int *tag, int *comm, int *status, int *ret);

void INTERF_2_INTEL_MPI_Recv(void *buf, int *count, int *datatype, int *source,
                             int *tag, int *comm, int *status, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Recv)(                 \
    void *buf, int *count, int *datatype, int *source, int *tag, int *comm,    \
    int *status, int *ret);                                                    \
    void pmpi_recv_(void *buf, int *count, int *datatype, int *source,         \
                    int *tag, int *comm, int *status, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Recv(buf, count, datatype, source, tag, comm,
                                    status);
}

void mpi_get_count_(int *status, int *datatype, int *count, int *ret);
#pragma weak mpi_get_count_ = pmpi_get_count_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Get_count(int *status, int *datatype, int *count,
                                 int *ret);

void INTERF_2_INTEL_MPI_Get_count(int *status, int *datatype, int *count,
                                  int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Get_count)(            \
    int *status, int *datatype, int *count, int *ret);                         \
    void pmpi_get_count_(int *status, int *datatype, int *count, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Get_count(status, datatype, count); }

void mpi_bsend_(void *buf, int *count, int *datatype, int *dest, int *tag,
                int *comm, int *ret);
#pragma weak mpi_bsend_ = pmpi_bsend_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Bsend(void *buf, int *count, int *datatype, int *dest,
                             int *tag, int *comm, int *ret);

void INTERF_2_INTEL_MPI_Bsend(void *buf, int *count, int *datatype, int *dest,
                              int *tag, int *comm, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Bsend)(                \
    void *buf, int *count, int *datatype, int *dest, int *tag, int *comm,      \
    int *ret);                                                                 \
    void pmpi_bsend_(void *buf, int *count, int *datatype, int *dest,          \
                     int *tag, int *comm, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Bsend(buf, count, datatype, dest, tag, comm); }

void mpi_ssend_(void *buf, int *count, int *datatype, int *dest, int *tag,
                int *comm, int *ret);
#pragma weak mpi_ssend_ = pmpi_ssend_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Ssend(void *buf, int *count, int *datatype, int *dest,
                             int *tag, int *comm, int *ret);

void INTERF_2_INTEL_MPI_Ssend(void *buf, int *count, int *datatype, int *dest,
                              int *tag, int *comm, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Ssend)(                \
    void *buf, int *count, int *datatype, int *dest, int *tag, int *comm,      \
    int *ret);                                                                 \
    void pmpi_ssend_(void *buf, int *count, int *datatype, int *dest,          \
                     int *tag, int *comm, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Ssend(buf, count, datatype, dest, tag, comm); }

void mpi_rsend_(void *buf, int *count, int *datatype, int *dest, int *tag,
                int *comm, int *ret);
#pragma weak mpi_rsend_ = pmpi_rsend_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Rsend(void *buf, int *count, int *datatype, int *dest,
                             int *tag, int *comm, int *ret);

void INTERF_2_INTEL_MPI_Rsend(void *buf, int *count, int *datatype, int *dest,
                              int *tag, int *comm, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Rsend)(                \
    void *buf, int *count, int *datatype, int *dest, int *tag, int *comm,      \
    int *ret);                                                                 \
    void pmpi_rsend_(void *buf, int *count, int *datatype, int *dest,          \
                     int *tag, int *comm, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Rsend(buf, count, datatype, dest, tag, comm); }

void mpi_buffer_attach_(void *buffer, int *size, int *ret);
#pragma weak mpi_buffer_attach_ = pmpi_buffer_attach_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Buffer_attach(void *buffer, int *size, int *ret);

void INTERF_2_INTEL_MPI_Buffer_attach(void *buffer, int *size, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Buffer_attach)(        \
    void *buffer, int *size, int *ret);                                        \
    void pmpi_buffer_attach_(void *buffer, int *size, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Buffer_attach(buffer, size); }

void mpi_buffer_detach_(void *buffer_addr, int *size, int *ret);
#pragma weak mpi_buffer_detach_ = pmpi_buffer_detach_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Buffer_detach(void *buffer_addr, int *size, int *ret);

void INTERF_2_INTEL_MPI_Buffer_detach(void *buffer_addr, int *size, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Buffer_detach)(        \
    void *buffer_addr, int *size, int *ret);                                   \
    void pmpi_buffer_detach_(void *buffer_addr, int *size, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Buffer_detach(buffer_addr, size); }

void mpi_isend_(void *buf, int *count, int *datatype, int *dest, int *tag,
                int *comm, int *request, int *ret);
#pragma weak mpi_isend_ = pmpi_isend_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Isend(void *buf, int *count, int *datatype, int *dest,
                             int *tag, int *comm, int *request, int *ret);

void INTERF_2_INTEL_MPI_Isend(void *buf, int *count, int *datatype, int *dest,
                              int *tag, int *comm, int *request, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Isend)(                \
    void *buf, int *count, int *datatype, int *dest, int *tag, int *comm,      \
    int *request, int *ret);                                                   \
    void pmpi_isend_(void *buf, int *count, int *datatype, int *dest,          \
                     int *tag, int *comm, int *request, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Isend(buf, count, datatype, dest, tag, comm,
                                     request);
}

void mpi_ibsend_(void *buf, int *count, int *datatype, int *dest, int *tag,
                 int *comm, int *request, int *ret);
#pragma weak mpi_ibsend_ = pmpi_ibsend_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Ibsend(void *buf, int *count, int *datatype, int *dest,
                              int *tag, int *comm, int *request, int *ret);

void INTERF_2_INTEL_MPI_Ibsend(void *buf, int *count, int *datatype, int *dest,
                               int *tag, int *comm, int *request, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Ibsend)(               \
    void *buf, int *count, int *datatype, int *dest, int *tag, int *comm,      \
    int *request, int *ret);                                                   \
    void pmpi_ibsend_(void *buf, int *count, int *datatype, int *dest,         \
                      int *tag, int *comm, int *request, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Ibsend(buf, count, datatype, dest, tag, comm,
                                      request);
}

void mpi_issend_(void *buf, int *count, int *datatype, int *dest, int *tag,
                 int *comm, int *request, int *ret);
#pragma weak mpi_issend_ = pmpi_issend_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Issend(void *buf, int *count, int *datatype, int *dest,
                              int *tag, int *comm, int *request, int *ret);

void INTERF_2_INTEL_MPI_Issend(void *buf, int *count, int *datatype, int *dest,
                               int *tag, int *comm, int *request, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Issend)(               \
    void *buf, int *count, int *datatype, int *dest, int *tag, int *comm,      \
    int *request, int *ret);                                                   \
    void pmpi_issend_(void *buf, int *count, int *datatype, int *dest,         \
                      int *tag, int *comm, int *request, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Issend(buf, count, datatype, dest, tag, comm,
                                      request);
}

void mpi_irsend_(void *buf, int *count, int *datatype, int *dest, int *tag,
                 int *comm, int *request, int *ret);
#pragma weak mpi_irsend_ = pmpi_irsend_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Irsend(void *buf, int *count, int *datatype, int *dest,
                              int *tag, int *comm, int *request, int *ret);

void INTERF_2_INTEL_MPI_Irsend(void *buf, int *count, int *datatype, int *dest,
                               int *tag, int *comm, int *request, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Irsend)(               \
    void *buf, int *count, int *datatype, int *dest, int *tag, int *comm,      \
    int *request, int *ret);                                                   \
    void pmpi_irsend_(void *buf, int *count, int *datatype, int *dest,         \
                      int *tag, int *comm, int *request, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Irsend(buf, count, datatype, dest, tag, comm,
                                      request);
}

void mpi_irecv_(void *buf, int *count, int *datatype, int *source, int *tag,
                int *comm, int *request, int *ret);
#pragma weak mpi_irecv_ = pmpi_irecv_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Irecv(void *buf, int *count, int *datatype, int *source,
                             int *tag, int *comm, int *request, int *ret);

void INTERF_2_INTEL_MPI_Irecv(void *buf, int *count, int *datatype, int *source,
                              int *tag, int *comm, int *request, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Irecv)(                \
    void *buf, int *count, int *datatype, int *source, int *tag, int *comm,    \
    int *request, int *ret);                                                   \
    void pmpi_irecv_(void *buf, int *count, int *datatype, int *source,        \
                     int *tag, int *comm, int *request, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Irecv(buf, count, datatype, source, tag, comm,
                                     request);
}

void mpi_wait_(int *request, int *status, int *ret);
#pragma weak mpi_wait_ = pmpi_wait_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Wait(int *request, int *status, int *ret);

void INTERF_2_INTEL_MPI_Wait(int *request, int *status, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Wait)(                 \
    int *request, int *status, int *ret);                                      \
    void pmpi_wait_(int *request, int *status, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Wait(request, status); }

void mpi_test_(int *request, int *flag, int *status, int *ret);
#pragma weak mpi_test_ = pmpi_test_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Test(int *request, int *flag, int *status, int *ret);

void INTERF_2_INTEL_MPI_Test(int *request, int *flag, int *status, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Test)(                 \
    int *request, int *flag, int *status, int *ret);                           \
    void pmpi_test_(int *request, int *flag, int *status, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Test(request, flag, status); }

void mpi_request_free_(int *request, int *ret);
#pragma weak mpi_request_free_ = pmpi_request_free_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Request_free(int *request, int *ret);

void INTERF_2_INTEL_MPI_Request_free(int *request, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Request_free)(         \
    int *request, int *ret);                                                   \
    void pmpi_request_free_(int *request, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Request_free(request); }

void mpi_iprobe_(int *source, int *tag, int *comm, int *flag, int *status,
                 int *ret);
#pragma weak mpi_iprobe_ = pmpi_iprobe_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Iprobe(int *source, int *tag, int *comm, int *flag,
                              int *status, int *ret);

void INTERF_2_INTEL_MPI_Iprobe(int *source, int *tag, int *comm, int *flag,
                               int *status, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Iprobe)(               \
    int *source, int *tag, int *comm, int *flag, int *status, int *ret);       \
    void pmpi_iprobe_(int *source, int *tag, int *comm, int *flag,             \
                      int *status, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Iprobe(source, tag, comm, flag, status); }

void mpi_probe_(int *source, int *tag, int *comm, int *status, int *ret);
#pragma weak mpi_probe_ = pmpi_probe_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Probe(int *source, int *tag, int *comm, int *status,
                             int *ret);

void INTERF_2_INTEL_MPI_Probe(int *source, int *tag, int *comm, int *status,
                              int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Probe)(                \
    int *source, int *tag, int *comm, int *status, int *ret);                  \
    void pmpi_probe_(int *source, int *tag, int *comm, int *status, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Probe(source, tag, comm, status); }

void mpi_cancel_(int *request, int *ret);
#pragma weak mpi_cancel_ = pmpi_cancel_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Cancel(int *request, int *ret);

void INTERF_2_INTEL_MPI_Cancel(int *request, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Cancel)(int *request,  \
                                                                int *ret);     \
    void pmpi_cancel_(int *request, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Cancel(request); }

void mpi_test_cancelled_(int *status, int *flag, int *ret);
#pragma weak mpi_test_cancelled_ = pmpi_test_cancelled_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Test_cancelled(int *status, int *flag, int *ret);

void INTERF_2_INTEL_MPI_Test_cancelled(int *status, int *flag, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Test_cancelled)(       \
    int *status, int *flag, int *ret);                                         \
    void pmpi_test_cancelled_(int *status, int *flag, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Test_cancelled(status, flag); }

void mpi_send_init_(void *buf, int *count, int *datatype, int *dest, int *tag,
                    int *comm, int *request, int *ret);
#pragma weak mpi_send_init_ = pmpi_send_init_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Send_init(void *buf, int *count, int *datatype,
                                 int *dest, int *tag, int *comm, int *request,
                                 int *ret);

void INTERF_2_INTEL_MPI_Send_init(void *buf, int *count, int *datatype,
                                  int *dest, int *tag, int *comm, int *request,
                                  int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Send_init)(            \
    void *buf, int *count, int *datatype, int *dest, int *tag, int *comm,      \
    int *request, int *ret);                                                   \
    void pmpi_send_init_(void *buf, int *count, int *datatype, int *dest,      \
                         int *tag, int *comm, int *request, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Send_init(buf, count, datatype, dest, tag, comm,
                                         request);
}

void mpi_bsend_init_(void *buf, int *count, int *datatype, int *dest, int *tag,
                     int *comm, int *request, int *ret);
#pragma weak mpi_bsend_init_ = pmpi_bsend_init_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Bsend_init(void *buf, int *count, int *datatype,
                                  int *dest, int *tag, int *comm, int *request,
                                  int *ret);

void INTERF_2_INTEL_MPI_Bsend_init(void *buf, int *count, int *datatype,
                                   int *dest, int *tag, int *comm, int *request,
                                   int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Bsend_init)(           \
    void *buf, int *count, int *datatype, int *dest, int *tag, int *comm,      \
    int *request, int *ret);                                                   \
    void pmpi_bsend_init_(void *buf, int *count, int *datatype, int *dest,     \
                          int *tag, int *comm, int *request, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Bsend_init(buf, count, datatype, dest, tag, comm,
                                          request);
}

void mpi_ssend_init_(void *buf, int *count, int *datatype, int *dest, int *tag,
                     int *comm, int *request, int *ret);
#pragma weak mpi_ssend_init_ = pmpi_ssend_init_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Ssend_init(void *buf, int *count, int *datatype,
                                  int *dest, int *tag, int *comm, int *request,
                                  int *ret);

void INTERF_2_INTEL_MPI_Ssend_init(void *buf, int *count, int *datatype,
                                   int *dest, int *tag, int *comm, int *request,
                                   int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Ssend_init)(           \
    void *buf, int *count, int *datatype, int *dest, int *tag, int *comm,      \
    int *request, int *ret);                                                   \
    void pmpi_ssend_init_(void *buf, int *count, int *datatype, int *dest,     \
                          int *tag, int *comm, int *request, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Ssend_init(buf, count, datatype, dest, tag, comm,
                                          request);
}

void mpi_rsend_init_(void *buf, int *count, int *datatype, int *dest, int *tag,
                     int *comm, int *request, int *ret);
#pragma weak mpi_rsend_init_ = pmpi_rsend_init_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Rsend_init(void *buf, int *count, int *datatype,
                                  int *dest, int *tag, int *comm, int *request,
                                  int *ret);

void INTERF_2_INTEL_MPI_Rsend_init(void *buf, int *count, int *datatype,
                                   int *dest, int *tag, int *comm, int *request,
                                   int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Rsend_init)(           \
    void *buf, int *count, int *datatype, int *dest, int *tag, int *comm,      \
    int *request, int *ret);                                                   \
    void pmpi_rsend_init_(void *buf, int *count, int *datatype, int *dest,     \
                          int *tag, int *comm, int *request, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Rsend_init(buf, count, datatype, dest, tag, comm,
                                          request);
}

void mpi_recv_init_(void *buf, int *count, int *datatype, int *source, int *tag,
                    int *comm, int *request, int *ret);
#pragma weak mpi_recv_init_ = pmpi_recv_init_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Recv_init(void *buf, int *count, int *datatype,
                                 int *source, int *tag, int *comm, int *request,
                                 int *ret);

void INTERF_2_INTEL_MPI_Recv_init(void *buf, int *count, int *datatype,
                                  int *source, int *tag, int *comm,
                                  int *request, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Recv_init)(            \
    void *buf, int *count, int *datatype, int *source, int *tag, int *comm,    \
    int *request, int *ret);                                                   \
    void pmpi_recv_init_(void *buf, int *count, int *datatype, int *source,    \
                         int *tag, int *comm, int *request, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Recv_init(buf, count, datatype, source, tag,
                                         comm, request);
}

void mpi_start_(int *request, int *ret);
#pragma weak mpi_start_ = pmpi_start_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Start(int *request, int *ret);

void INTERF_2_INTEL_MPI_Start(int *request, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Start)(int *request,   \
                                                               int *ret);      \
    void pmpi_start_(int *request, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Start(request); }

void mpi_sendrecv_(void *sendbuf, int *sendcount, int *sendtype, int *dest,
                   int *sendtag, void *recvbuf, int *recvcount, int *recvtype,
                   int *source, int *recvtag, int *comm, int *status, int *ret);
#pragma weak mpi_sendrecv_ = pmpi_sendrecv_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Sendrecv(void *sendbuf, int *sendcount, int *sendtype,
                                int *dest, int *sendtag, void *recvbuf,
                                int *recvcount, int *recvtype, int *source,
                                int *recvtag, int *comm, int *status, int *ret);

void INTERF_2_INTEL_MPI_Sendrecv(void *sendbuf, int *sendcount, int *sendtype,
                                 int *dest, int *sendtag, void *recvbuf,
                                 int *recvcount, int *recvtype, int *source,
                                 int *recvtag, int *comm, int *status,
                                 int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Sendrecv)(             \
    void *sendbuf, int *sendcount, int *sendtype, int *dest, int *sendtag,     \
    void *recvbuf, int *recvcount, int *recvtype, int *source, int *recvtag,   \
    int *comm, int *status, int *ret);                                         \
    void pmpi_sendrecv_(void *sendbuf, int *sendcount, int *sendtype,          \
                        int *dest, int *sendtag, void *recvbuf,                \
                        int *recvcount, int *recvtype, int *source,            \
                        int *recvtag, int *comm, int *status, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Sendrecv(sendbuf, sendcount, sendtype, dest,
                                        sendtag, recvbuf, recvcount, recvtype,
                                        source, recvtag, comm, status);
}

void mpi_sendrecv_replace_(void *buf, int *count, int *datatype, int *dest,
                           int *sendtag, int *source, int *recvtag, int *comm,
                           int *status, int *ret);
#pragma weak mpi_sendrecv_replace_ = pmpi_sendrecv_replace_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Sendrecv_replace(void *buf, int *count, int *datatype,
                                        int *dest, int *sendtag, int *source,
                                        int *recvtag, int *comm, int *status,
                                        int *ret);

void INTERF_2_INTEL_MPI_Sendrecv_replace(void *buf, int *count, int *datatype,
                                         int *dest, int *sendtag, int *source,
                                         int *recvtag, int *comm, int *status,
                                         int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Sendrecv_replace)(     \
    void *buf, int *count, int *datatype, int *dest, int *sendtag,             \
    int *source, int *recvtag, int *comm, int *status, int *ret);              \
    void pmpi_sendrecv_replace_(                                               \
        void *buf, int *count, int *datatype, int *dest, int *sendtag,         \
        int *source, int *recvtag, int *comm, int *status, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Sendrecv_replace(
      buf, count, datatype, dest, sendtag, source, recvtag, comm, status);
}

void mpi_type_contiguous_(int *count, int *oldtype, int *newtype, int *ret);
#pragma weak mpi_type_contiguous_ = pmpi_type_contiguous_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Type_contiguous(int *count, int *oldtype, int *newtype,
                                       int *ret);

void INTERF_2_INTEL_MPI_Type_contiguous(int *count, int *oldtype, int *newtype,
                                        int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Type_contiguous)(      \
    int *count, int *oldtype, int *newtype, int *ret);                         \
    void pmpi_type_contiguous_(int *count, int *oldtype, int *newtype,         \
                               int *ret);
{ return INTERFACE_F_LOCAL_MPI_Type_contiguous(count, oldtype, newtype); }

void mpi_type_vector_(int *count, int *blocklength, int *stride, int *oldtype,
                      int *newtype, int *ret);
#pragma weak mpi_type_vector_ = pmpi_type_vector_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Type_vector(int *count, int *blocklength, int *stride,
                                   int *oldtype, int *newtype, int *ret);

void INTERF_2_INTEL_MPI_Type_vector(int *count, int *blocklength, int *stride,
                                    int *oldtype, int *newtype, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Type_vector)(          \
    int *count, int *blocklength, int *stride, int *oldtype, int *newtype,     \
    int *ret);                                                                 \
    void pmpi_type_vector_(int *count, int *blocklength, int *stride,          \
                           int *oldtype, int *newtype, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Type_vector(count, blocklength, stride, oldtype,
                                           newtype);
}

void mpi_type_hvector_(int *count, int *blocklength, size_t stride,
                       int *oldtype, int *newtype, int *ret);
#pragma weak mpi_type_hvector_ = pmpi_type_hvector_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Type_hvector(int *count, int *blocklength, size_t stride,
                                    int *oldtype, int *newtype, int *ret);

void INTERF_2_INTEL_MPI_Type_hvector(int *count, int *blocklength,
                                     size_t stride, int *oldtype, int *newtype,
                                     int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Type_hvector)(         \
    int *count, int *blocklength, size_t stride, int *oldtype, int *newtype,   \
    int *ret);                                                                 \
    void pmpi_type_hvector_(int *count, int *blocklength, size_t stride,       \
                            int *oldtype, int *newtype, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Type_hvector(count, blocklength, stride, oldtype,
                                            newtype);
}

void mpi_type_indexed_(int *count, int *array_of_blocklengths,
                       int *array_of_displacements, int *oldtype, int *newtype,
                       int *ret);
#pragma weak mpi_type_indexed_ = pmpi_type_indexed_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Type_indexed(int *count, int *array_of_blocklengths,
                                    int *array_of_displacements, int *oldtype,
                                    int *newtype, int *ret);

void INTERF_2_INTEL_MPI_Type_indexed(int *count, int *array_of_blocklengths,
                                     int *array_of_displacements, int *oldtype,
                                     int *newtype, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Type_indexed)(         \
    int *count, int *array_of_blocklengths, int *array_of_displacements,       \
    int *oldtype, int *newtype, int *ret);                                     \
    void pmpi_type_indexed_(int *count, int *array_of_blocklengths,            \
                            int *array_of_displacements, int *oldtype,         \
                            int *newtype, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Type_indexed(
      count, array_of_blocklengths, array_of_displacements, oldtype, newtype);
}

void mpi_type_hindexed_(int *count, int *array_of_blocklengths,
                        size_t array_of_displacements, int *oldtype,
                        int *newtype, int *ret);
#pragma weak mpi_type_hindexed_ = pmpi_type_hindexed_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Type_hindexed(int *count, int *array_of_blocklengths,
                                     size_t array_of_displacements,
                                     int *oldtype, int *newtype, int *ret);

void INTERF_2_INTEL_MPI_Type_hindexed(int *count, int *array_of_blocklengths,
                                      size_t array_of_displacements,
                                      int *oldtype, int *newtype, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Type_hindexed)(        \
    int *count, int *array_of_blocklengths, size_t array_of_displacements,     \
    int *oldtype, int *newtype, int *ret);                                     \
    void pmpi_type_hindexed_(int *count, int *array_of_blocklengths,           \
                             size_t array_of_displacements, int *oldtype,      \
                             int *newtype, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Type_hindexed(
      count, array_of_blocklengths, array_of_displacements, oldtype, newtype);
}

void mpi_type_struct_(int *count, int *array_of_blocklengths,
                      size_t array_of_displacements, int *array_of_types,
                      int *newtype, int *ret);
#pragma weak mpi_type_struct_ = pmpi_type_struct_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Type_struct(int *count, int *array_of_blocklengths,
                                   size_t array_of_displacements,
                                   int *array_of_types, int *newtype, int *ret);

void INTERF_2_INTEL_MPI_Type_struct(int *count, int *array_of_blocklengths,
                                    size_t array_of_displacements,
                                    int *array_of_types, int *newtype,
                                    int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Type_struct)(          \
    int *count, int *array_of_blocklengths, size_t array_of_displacements,     \
    int *array_of_types, int *newtype, int *ret);                              \
    void pmpi_type_struct_(int *count, int *array_of_blocklengths,             \
                           size_t array_of_displacements, int *array_of_types, \
                           int *newtype, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Type_struct(count, array_of_blocklengths,
                                           array_of_displacements,
                                           array_of_types, newtype);
}

void mpi_address_(void *location, size_t address, int *ret);
#pragma weak mpi_address_ = pmpi_address_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Address(void *location, size_t address, int *ret);

void INTERF_2_INTEL_MPI_Address(void *location, size_t address, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Address)(              \
    void *location, size_t address, int *ret);                                 \
    void pmpi_address_(void *location, size_t address, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Address(location, address); }

void mpi_type_extent_(int *datatype, size_t extent, int *ret);
#pragma weak mpi_type_extent_ = pmpi_type_extent_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Type_extent(int *datatype, size_t extent, int *ret);

void INTERF_2_INTEL_MPI_Type_extent(int *datatype, size_t extent, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Type_extent)(          \
    int *datatype, size_t extent, int *ret);                                   \
    void pmpi_type_extent_(int *datatype, size_t extent, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Type_extent(datatype, extent); }

void mpi_type_size_(int *datatype, int *size, int *ret);
#pragma weak mpi_type_size_ = pmpi_type_size_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Type_size(int *datatype, int *size, int *ret);

void INTERF_2_INTEL_MPI_Type_size(int *datatype, int *size, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Type_size)(            \
    int *datatype, int *size, int *ret);                                       \
    void pmpi_type_size_(int *datatype, int *size, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Type_size(datatype, size); }

void mpi_type_lb_(int *datatype, size_t displacement, int *ret);
#pragma weak mpi_type_lb_ = pmpi_type_lb_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Type_lb(int *datatype, size_t displacement, int *ret);

void INTERF_2_INTEL_MPI_Type_lb(int *datatype, size_t displacement, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Type_lb)(              \
    int *datatype, size_t displacement, int *ret);                             \
    void pmpi_type_lb_(int *datatype, size_t displacement, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Type_lb(datatype, displacement); }

void mpi_type_ub_(int *datatype, size_t displacement, int *ret);
#pragma weak mpi_type_ub_ = pmpi_type_ub_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Type_ub(int *datatype, size_t displacement, int *ret);

void INTERF_2_INTEL_MPI_Type_ub(int *datatype, size_t displacement, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Type_ub)(              \
    int *datatype, size_t displacement, int *ret);                             \
    void pmpi_type_ub_(int *datatype, size_t displacement, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Type_ub(datatype, displacement); }

void mpi_type_commit_(int *datatype, int *ret);
#pragma weak mpi_type_commit_ = pmpi_type_commit_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Type_commit(int *datatype, int *ret);

void INTERF_2_INTEL_MPI_Type_commit(int *datatype, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Type_commit)(          \
    int *datatype, int *ret);                                                  \
    void pmpi_type_commit_(int *datatype, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Type_commit(datatype); }

void mpi_type_free_(int *datatype, int *ret);
#pragma weak mpi_type_free_ = pmpi_type_free_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Type_free(int *datatype, int *ret);

void INTERF_2_INTEL_MPI_Type_free(int *datatype, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Type_free)(            \
    int *datatype, int *ret);                                                  \
    void pmpi_type_free_(int *datatype, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Type_free(datatype); }

void mpi_get_elements_(int *status, int *datatype, int *count, int *ret);
#pragma weak mpi_get_elements_ = pmpi_get_elements_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Get_elements(int *status, int *datatype, int *count,
                                    int *ret);

void INTERF_2_INTEL_MPI_Get_elements(int *status, int *datatype, int *count,
                                     int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Get_elements)(         \
    int *status, int *datatype, int *count, int *ret);                         \
    void pmpi_get_elements_(int *status, int *datatype, int *count, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Get_elements(status, datatype, count); }

void mpi_pack_(void *inbuf, int *incount, int *datatype, void *outbuf,
               int *outsize, int *position, int *comm, int *ret);
#pragma weak mpi_pack_ = pmpi_pack_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Pack(void *inbuf, int *incount, int *datatype,
                            void *outbuf, int *outsize, int *position,
                            int *comm, int *ret);

void INTERF_2_INTEL_MPI_Pack(void *inbuf, int *incount, int *datatype,
                             void *outbuf, int *outsize, int *position,
                             int *comm, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Pack)(                 \
    void *inbuf, int *incount, int *datatype, void *outbuf, int *outsize,      \
    int *position, int *comm, int *ret);                                       \
    void pmpi_pack_(void *inbuf, int *incount, int *datatype, void *outbuf,    \
                    int *outsize, int *position, int *comm, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Pack(inbuf, incount, datatype, outbuf, outsize,
                                    position, comm);
}

void mpi_unpack_(void *inbuf, int *insize, int *position, void *outbuf,
                 int *outcount, int *datatype, int *comm, int *ret);
#pragma weak mpi_unpack_ = pmpi_unpack_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Unpack(void *inbuf, int *insize, int *position,
                              void *outbuf, int *outcount, int *datatype,
                              int *comm, int *ret);

void INTERF_2_INTEL_MPI_Unpack(void *inbuf, int *insize, int *position,
                               void *outbuf, int *outcount, int *datatype,
                               int *comm, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Unpack)(               \
    void *inbuf, int *insize, int *position, void *outbuf, int *outcount,      \
    int *datatype, int *comm, int *ret);                                       \
    void pmpi_unpack_(void *inbuf, int *insize, int *position, void *outbuf,   \
                      int *outcount, int *datatype, int *comm, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Unpack(inbuf, insize, position, outbuf, outcount,
                                      datatype, comm);
}

void mpi_pack_size_(int *incount, int *datatype, int *comm, int *size,
                    int *ret);
#pragma weak mpi_pack_size_ = pmpi_pack_size_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Pack_size(int *incount, int *datatype, int *comm,
                                 int *size, int *ret);

void INTERF_2_INTEL_MPI_Pack_size(int *incount, int *datatype, int *comm,
                                  int *size, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Pack_size)(            \
    int *incount, int *datatype, int *comm, int *size, int *ret);              \
    void pmpi_pack_size_(int *incount, int *datatype, int *comm, int *size,    \
                         int *ret);
{ return INTERFACE_F_LOCAL_MPI_Pack_size(incount, datatype, comm, size); }

void mpi_barrier_(int *comm, int *ret);
#pragma weak mpi_barrier_ = pmpi_barrier_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Barrier(int *comm, int *ret);

void INTERF_2_INTEL_MPI_Barrier(int *comm, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Barrier)(int *comm,    \
                                                                 int *ret);    \
    void pmpi_barrier_(int *comm, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Barrier(comm); }

void mpi_bcast_(void *buffer, int *count, int *datatype, int *root, int *comm,
                int *ret);
#pragma weak mpi_bcast_ = pmpi_bcast_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Bcast(void *buffer, int *count, int *datatype, int *root,
                             int *comm, int *ret);

void INTERF_2_INTEL_MPI_Bcast(void *buffer, int *count, int *datatype,
                              int *root, int *comm, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Bcast)(                \
    void *buffer, int *count, int *datatype, int *root, int *comm, int *ret);  \
    void pmpi_bcast_(void *buffer, int *count, int *datatype, int *root,       \
                     int *comm, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Bcast(buffer, count, datatype, root, comm); }

void mpi_gather_(void *sendbuf, int *sendcount, int *sendtype, void *recvbuf,
                 int *recvcount, int *recvtype, int *root, int *comm, int *ret);
#pragma weak mpi_gather_ = pmpi_gather_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Gather(void *sendbuf, int *sendcount, int *sendtype,
                              void *recvbuf, int *recvcount, int *recvtype,
                              int *root, int *comm, int *ret);

void INTERF_2_INTEL_MPI_Gather(void *sendbuf, int *sendcount, int *sendtype,
                               void *recvbuf, int *recvcount, int *recvtype,
                               int *root, int *comm, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Gather)(               \
    void *sendbuf, int *sendcount, int *sendtype, void *recvbuf,               \
    int *recvcount, int *recvtype, int *root, int *comm, int *ret);            \
    void pmpi_gather_(void *sendbuf, int *sendcount, int *sendtype,            \
                      void *recvbuf, int *recvcount, int *recvtype, int *root, \
                      int *comm, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Gather(sendbuf, sendcount, sendtype, recvbuf,
                                      recvcount, recvtype, root, comm);
}

void mpi_gatherv_(void *sendbuf, int *sendcount, int *sendtype, void *recvbuf,
                  int *recvcounts, int *displs, int *recvtype, int *root,
                  int *comm, int *ret);
#pragma weak mpi_gatherv_ = pmpi_gatherv_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Gatherv(void *sendbuf, int *sendcount, int *sendtype,
                               void *recvbuf, int *recvcounts, int *displs,
                               int *recvtype, int *root, int *comm, int *ret);

void INTERF_2_INTEL_MPI_Gatherv(void *sendbuf, int *sendcount, int *sendtype,
                                void *recvbuf, int *recvcounts, int *displs,
                                int *recvtype, int *root, int *comm, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Gatherv)(              \
    void *sendbuf, int *sendcount, int *sendtype, void *recvbuf,               \
    int *recvcounts, int *displs, int *recvtype, int *root, int *comm,         \
    int *ret);                                                                 \
    void pmpi_gatherv_(void *sendbuf, int *sendcount, int *sendtype,           \
                       void *recvbuf, int *recvcounts, int *displs,            \
                       int *recvtype, int *root, int *comm, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Gatherv(sendbuf, sendcount, sendtype, recvbuf,
                                       recvcounts, displs, recvtype, root,
                                       comm);
}

void mpi_scatter_(void *sendbuf, int *sendcount, int *sendtype, void *recvbuf,
                  int *recvcount, int *recvtype, int *root, int *comm,
                  int *ret);
#pragma weak mpi_scatter_ = pmpi_scatter_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Scatter(void *sendbuf, int *sendcount, int *sendtype,
                               void *recvbuf, int *recvcount, int *recvtype,
                               int *root, int *comm, int *ret);

void INTERF_2_INTEL_MPI_Scatter(void *sendbuf, int *sendcount, int *sendtype,
                                void *recvbuf, int *recvcount, int *recvtype,
                                int *root, int *comm, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Scatter)(              \
    void *sendbuf, int *sendcount, int *sendtype, void *recvbuf,               \
    int *recvcount, int *recvtype, int *root, int *comm, int *ret);            \
    void pmpi_scatter_(void *sendbuf, int *sendcount, int *sendtype,           \
                       void *recvbuf, int *recvcount, int *recvtype,           \
                       int *root, int *comm, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Scatter(sendbuf, sendcount, sendtype, recvbuf,
                                       recvcount, recvtype, root, comm);
}

void mpi_scatterv_(void *sendbuf, int *sendcounts, int *displs, int *sendtype,
                   void *recvbuf, int *recvcount, int *recvtype, int *root,
                   int *comm, int *ret);
#pragma weak mpi_scatterv_ = pmpi_scatterv_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Scatterv(void *sendbuf, int *sendcounts, int *displs,
                                int *sendtype, void *recvbuf, int *recvcount,
                                int *recvtype, int *root, int *comm, int *ret);

void INTERF_2_INTEL_MPI_Scatterv(void *sendbuf, int *sendcounts, int *displs,
                                 int *sendtype, void *recvbuf, int *recvcount,
                                 int *recvtype, int *root, int *comm, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Scatterv)(             \
    void *sendbuf, int *sendcounts, int *displs, int *sendtype, void *recvbuf, \
    int *recvcount, int *recvtype, int *root, int *comm, int *ret);            \
    void pmpi_scatterv_(void *sendbuf, int *sendcounts, int *displs,           \
                        int *sendtype, void *recvbuf, int *recvcount,          \
                        int *recvtype, int *root, int *comm, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Scatterv(sendbuf, sendcounts, displs, sendtype,
                                        recvbuf, recvcount, recvtype, root,
                                        comm);
}

void mpi_allgather_(void *sendbuf, int *sendcount, int *sendtype, void *recvbuf,
                    int *recvcount, int *recvtype, int *comm, int *ret);
#pragma weak mpi_allgather_ = pmpi_allgather_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Allgather(void *sendbuf, int *sendcount, int *sendtype,
                                 void *recvbuf, int *recvcount, int *recvtype,
                                 int *comm, int *ret);

void INTERF_2_INTEL_MPI_Allgather(void *sendbuf, int *sendcount, int *sendtype,
                                  void *recvbuf, int *recvcount, int *recvtype,
                                  int *comm, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Allgather)(            \
    void *sendbuf, int *sendcount, int *sendtype, void *recvbuf,               \
    int *recvcount, int *recvtype, int *comm, int *ret);                       \
    void pmpi_allgather_(void *sendbuf, int *sendcount, int *sendtype,         \
                         void *recvbuf, int *recvcount, int *recvtype,         \
                         int *comm, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Allgather(sendbuf, sendcount, sendtype, recvbuf,
                                         recvcount, recvtype, comm);
}

void mpi_allgatherv_(void *sendbuf, int *sendcount, int *sendtype,
                     void *recvbuf, int *recvcounts, int *displs, int *recvtype,
                     int *comm, int *ret);
#pragma weak mpi_allgatherv_ = pmpi_allgatherv_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Allgatherv(void *sendbuf, int *sendcount, int *sendtype,
                                  void *recvbuf, int *recvcounts, int *displs,
                                  int *recvtype, int *comm, int *ret);

void INTERF_2_INTEL_MPI_Allgatherv(void *sendbuf, int *sendcount, int *sendtype,
                                   void *recvbuf, int *recvcounts, int *displs,
                                   int *recvtype, int *comm, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Allgatherv)(           \
    void *sendbuf, int *sendcount, int *sendtype, void *recvbuf,               \
    int *recvcounts, int *displs, int *recvtype, int *comm, int *ret);         \
    void pmpi_allgatherv_(void *sendbuf, int *sendcount, int *sendtype,        \
                          void *recvbuf, int *recvcounts, int *displs,         \
                          int *recvtype, int *comm, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Allgatherv(sendbuf, sendcount, sendtype, recvbuf,
                                          recvcounts, displs, recvtype, comm);
}

void mpi_alltoall_(void *sendbuf, int *sendcount, int *sendtype, void *recvbuf,
                   int *recvcount, int *recvtype, int *comm, int *ret);
#pragma weak mpi_alltoall_ = pmpi_alltoall_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Alltoall(void *sendbuf, int *sendcount, int *sendtype,
                                void *recvbuf, int *recvcount, int *recvtype,
                                int *comm, int *ret);

void INTERF_2_INTEL_MPI_Alltoall(void *sendbuf, int *sendcount, int *sendtype,
                                 void *recvbuf, int *recvcount, int *recvtype,
                                 int *comm, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Alltoall)(             \
    void *sendbuf, int *sendcount, int *sendtype, void *recvbuf,               \
    int *recvcount, int *recvtype, int *comm, int *ret);                       \
    void pmpi_alltoall_(void *sendbuf, int *sendcount, int *sendtype,          \
                        void *recvbuf, int *recvcount, int *recvtype,          \
                        int *comm, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Alltoall(sendbuf, sendcount, sendtype, recvbuf,
                                        recvcount, recvtype, comm);
}

void mpi_alltoallv_(void *sendbuf, int *sendcounts, int *sdispls, int *sendtype,
                    void *recvbuf, int *recvcounts, int *rdispls, int *recvtype,
                    int *comm, int *ret);
#pragma weak mpi_alltoallv_ = pmpi_alltoallv_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Alltoallv(void *sendbuf, int *sendcounts, int *sdispls,
                                 int *sendtype, void *recvbuf, int *recvcounts,
                                 int *rdispls, int *recvtype, int *comm,
                                 int *ret);

void INTERF_2_INTEL_MPI_Alltoallv(void *sendbuf, int *sendcounts, int *sdispls,
                                  int *sendtype, void *recvbuf, int *recvcounts,
                                  int *rdispls, int *recvtype, int *comm,
                                  int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Alltoallv)(            \
    void *sendbuf, int *sendcounts, int *sdispls, int *sendtype,               \
    void *recvbuf, int *recvcounts, int *rdispls, int *recvtype, int *comm,    \
    int *ret);                                                                 \
    void pmpi_alltoallv_(void *sendbuf, int *sendcounts, int *sdispls,         \
                         int *sendtype, void *recvbuf, int *recvcounts,        \
                         int *rdispls, int *recvtype, int *comm, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Alltoallv(sendbuf, sendcounts, sdispls, sendtype,
                                         recvbuf, recvcounts, rdispls, recvtype,
                                         comm);
}

void mpi_exscan_(void *sendbuf, void *recvbuf, int *count, int *datatype,
                 int *op, int *comm, int *ret);
#pragma weak mpi_exscan_ = pmpi_exscan_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Exscan(void *sendbuf, void *recvbuf, int *count,
                              int *datatype, int *op, int *comm, int *ret);

void INTERF_2_INTEL_MPI_Exscan(void *sendbuf, void *recvbuf, int *count,
                               int *datatype, int *op, int *comm, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Exscan)(               \
    void *sendbuf, void *recvbuf, int *count, int *datatype, int *op,          \
    int *comm, int *ret);                                                      \
    void pmpi_exscan_(void *sendbuf, void *recvbuf, int *count, int *datatype, \
                      int *op, int *comm, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Exscan(sendbuf, recvbuf, count, datatype, op,
                                      comm);
}

void mpi_reduce_(void *sendbuf, void *recvbuf, int *count, int *datatype,
                 int *op, int *root, int *comm, int *ret);
#pragma weak mpi_reduce_ = pmpi_reduce_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Reduce(void *sendbuf, void *recvbuf, int *count,
                              int *datatype, int *op, int *root, int *comm,
                              int *ret);

void INTERF_2_INTEL_MPI_Reduce(void *sendbuf, void *recvbuf, int *count,
                               int *datatype, int *op, int *root, int *comm,
                               int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Reduce)(               \
    void *sendbuf, void *recvbuf, int *count, int *datatype, int *op,          \
    int *root, int *comm, int *ret);                                           \
    void pmpi_reduce_(void *sendbuf, void *recvbuf, int *count, int *datatype, \
                      int *op, int *root, int *comm, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Reduce(sendbuf, recvbuf, count, datatype, op,
                                      root, comm);
}

void mpi_op_create_(void *user_fn, int *commute, int *op, int *ret);
#pragma weak mpi_op_create_ = pmpi_op_create_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Op_create(void *user_fn, int *commute, int *op,
                                 int *ret);

void INTERF_2_INTEL_MPI_Op_create(void *user_fn, int *commute, int *op,
                                  int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Op_create)(            \
    void *user_fn, int *commute, int *op, int *ret);                           \
    void pmpi_op_create_(void *user_fn, int *commute, int *op, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Op_create(user_fn, commute, op); }

void mpi_op_free_(int *op, int *ret);
#pragma weak mpi_op_free_ = pmpi_op_free_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Op_free(int *op, int *ret);

void INTERF_2_INTEL_MPI_Op_free(int *op, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Op_free)(int *op,      \
                                                                 int *ret);    \
    void pmpi_op_free_(int *op, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Op_free(op); }

void mpi_allreduce_(void *sendbuf, void *recvbuf, int *count, int *datatype,
                    int *op, int *comm, int *ret);
#pragma weak mpi_allreduce_ = pmpi_allreduce_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Allreduce(void *sendbuf, void *recvbuf, int *count,
                                 int *datatype, int *op, int *comm, int *ret);

void INTERF_2_INTEL_MPI_Allreduce(void *sendbuf, void *recvbuf, int *count,
                                  int *datatype, int *op, int *comm, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Allreduce)(            \
    void *sendbuf, void *recvbuf, int *count, int *datatype, int *op,          \
    int *comm, int *ret);                                                      \
    void pmpi_allreduce_(void *sendbuf, void *recvbuf, int *count,             \
                         int *datatype, int *op, int *comm, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Allreduce(sendbuf, recvbuf, count, datatype, op,
                                         comm);
}

void mpi_scan_(void *sendbuf, void *recvbuf, int *count, int *datatype, int *op,
               int *comm, int *ret);
#pragma weak mpi_scan_ = pmpi_scan_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Scan(void *sendbuf, void *recvbuf, int *count,
                            int *datatype, int *op, int *comm, int *ret);

void INTERF_2_INTEL_MPI_Scan(void *sendbuf, void *recvbuf, int *count,
                             int *datatype, int *op, int *comm, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Scan)(                 \
    void *sendbuf, void *recvbuf, int *count, int *datatype, int *op,          \
    int *comm, int *ret);                                                      \
    void pmpi_scan_(void *sendbuf, void *recvbuf, int *count, int *datatype,   \
                    int *op, int *comm, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Scan(sendbuf, recvbuf, count, datatype, op,
                                    comm);
}

void mpi_group_size_(int *group, int *size, int *ret);
#pragma weak mpi_group_size_ = pmpi_group_size_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Group_size(int *group, int *size, int *ret);

void INTERF_2_INTEL_MPI_Group_size(int *group, int *size, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Group_size)(           \
    int *group, int *size, int *ret);                                          \
    void pmpi_group_size_(int *group, int *size, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Group_size(group, size); }

void mpi_group_rank_(int *group, int *rank, int *ret);
#pragma weak mpi_group_rank_ = pmpi_group_rank_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Group_rank(int *group, int *rank, int *ret);

void INTERF_2_INTEL_MPI_Group_rank(int *group, int *rank, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Group_rank)(           \
    int *group, int *rank, int *ret);                                          \
    void pmpi_group_rank_(int *group, int *rank, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Group_rank(group, rank); }

void mpi_group_compare_(int *group1, int *group2, int *result, int *ret);
#pragma weak mpi_group_compare_ = pmpi_group_compare_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Group_compare(int *group1, int *group2, int *result,
                                     int *ret);

void INTERF_2_INTEL_MPI_Group_compare(int *group1, int *group2, int *result,
                                      int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Group_compare)(        \
    int *group1, int *group2, int *result, int *ret);                          \
    void pmpi_group_compare_(int *group1, int *group2, int *result, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Group_compare(group1, group2, result); }

void mpi_comm_group_(int *comm, int *group, int *ret);
#pragma weak mpi_comm_group_ = pmpi_comm_group_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Comm_group(int *comm, int *group, int *ret);

void INTERF_2_INTEL_MPI_Comm_group(int *comm, int *group, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Comm_group)(           \
    int *comm, int *group, int *ret);                                          \
    void pmpi_comm_group_(int *comm, int *group, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Comm_group(comm, group); }

void mpi_group_union_(int *group1, int *group2, int *newgroup, int *ret);
#pragma weak mpi_group_union_ = pmpi_group_union_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Group_union(int *group1, int *group2, int *newgroup,
                                   int *ret);

void INTERF_2_INTEL_MPI_Group_union(int *group1, int *group2, int *newgroup,
                                    int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Group_union)(          \
    int *group1, int *group2, int *newgroup, int *ret);                        \
    void pmpi_group_union_(int *group1, int *group2, int *newgroup, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Group_union(group1, group2, newgroup); }

void mpi_group_intersection_(int *group1, int *group2, int *newgroup, int *ret);
#pragma weak mpi_group_intersection_ = pmpi_group_intersection_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Group_intersection(int *group1, int *group2,
                                          int *newgroup, int *ret);

void INTERF_2_INTEL_MPI_Group_intersection(int *group1, int *group2,
                                           int *newgroup, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Group_intersection)(   \
    int *group1, int *group2, int *newgroup, int *ret);                        \
    void pmpi_group_intersection_(int *group1, int *group2, int *newgroup,     \
                                  int *ret);
{ return INTERFACE_F_LOCAL_MPI_Group_intersection(group1, group2, newgroup); }

void mpi_group_difference_(int *group1, int *group2, int *newgroup, int *ret);
#pragma weak mpi_group_difference_ = pmpi_group_difference_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Group_difference(int *group1, int *group2, int *newgroup,
                                        int *ret);

void INTERF_2_INTEL_MPI_Group_difference(int *group1, int *group2,
                                         int *newgroup, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Group_difference)(     \
    int *group1, int *group2, int *newgroup, int *ret);                        \
    void pmpi_group_difference_(int *group1, int *group2, int *newgroup,       \
                                int *ret);
{ return INTERFACE_F_LOCAL_MPI_Group_difference(group1, group2, newgroup); }

void mpi_group_free_(int *group, int *ret);
#pragma weak mpi_group_free_ = pmpi_group_free_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Group_free(int *group, int *ret);

void INTERF_2_INTEL_MPI_Group_free(int *group, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Group_free)(           \
    int *group, int *ret);                                                     \
    void pmpi_group_free_(int *group, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Group_free(group); }

void mpi_comm_size_(int *comm, int *size, int *ret);
#pragma weak mpi_comm_size_ = pmpi_comm_size_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Comm_size(int *comm, int *size, int *ret);

void INTERF_2_INTEL_MPI_Comm_size(int *comm, int *size, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Comm_size)(            \
    int *comm, int *size, int *ret);                                           \
    void pmpi_comm_size_(int *comm, int *size, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Comm_size(comm, size); }

void mpi_comm_rank_(int *comm, int *rank, int *ret);
#pragma weak mpi_comm_rank_ = pmpi_comm_rank_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Comm_rank(int *comm, int *rank, int *ret);

void INTERF_2_INTEL_MPI_Comm_rank(int *comm, int *rank, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Comm_rank)(            \
    int *comm, int *rank, int *ret);                                           \
    void pmpi_comm_rank_(int *comm, int *rank, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Comm_rank(comm, rank); }

void mpi_comm_compare_(int *comm1, int *comm2, int *result, int *ret);
#pragma weak mpi_comm_compare_ = pmpi_comm_compare_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Comm_compare(int *comm1, int *comm2, int *result,
                                    int *ret);

void INTERF_2_INTEL_MPI_Comm_compare(int *comm1, int *comm2, int *result,
                                     int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Comm_compare)(         \
    int *comm1, int *comm2, int *result, int *ret);                            \
    void pmpi_comm_compare_(int *comm1, int *comm2, int *result, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Comm_compare(comm1, comm2, result); }

void mpi_comm_dup_(int *comm, int *newcomm, int *ret);
#pragma weak mpi_comm_dup_ = pmpi_comm_dup_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Comm_dup(int *comm, int *newcomm, int *ret);

void INTERF_2_INTEL_MPI_Comm_dup(int *comm, int *newcomm, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Comm_dup)(             \
    int *comm, int *newcomm, int *ret);                                        \
    void pmpi_comm_dup_(int *comm, int *newcomm, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Comm_dup(comm, newcomm); }

void mpi_comm_dup_with_info_(int *comm, int *info, int *newcomm, int *ret);
#pragma weak mpi_comm_dup_with_info_ = pmpi_comm_dup_with_info_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Comm_dup_with_info(int *comm, int *info, int *newcomm,
                                          int *ret);

void INTERF_2_INTEL_MPI_Comm_dup_with_info(int *comm, int *info, int *newcomm,
                                           int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Comm_dup_with_info)(   \
    int *comm, int *info, int *newcomm, int *ret);                             \
    void pmpi_comm_dup_with_info_(int *comm, int *info, int *newcomm,          \
                                  int *ret);
{ return INTERFACE_F_LOCAL_MPI_Comm_dup_with_info(comm, info, newcomm); }

void mpi_comm_create_(int *comm, int *group, int *newcomm, int *ret);
#pragma weak mpi_comm_create_ = pmpi_comm_create_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Comm_create(int *comm, int *group, int *newcomm,
                                   int *ret);

void INTERF_2_INTEL_MPI_Comm_create(int *comm, int *group, int *newcomm,
                                    int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Comm_create)(          \
    int *comm, int *group, int *newcomm, int *ret);                            \
    void pmpi_comm_create_(int *comm, int *group, int *newcomm, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Comm_create(comm, group, newcomm); }

void mpi_comm_split_(int *comm, int *color, int *key, int *newcomm, int *ret);
#pragma weak mpi_comm_split_ = pmpi_comm_split_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Comm_split(int *comm, int *color, int *key, int *newcomm,
                                  int *ret);

void INTERF_2_INTEL_MPI_Comm_split(int *comm, int *color, int *key,
                                   int *newcomm, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Comm_split)(           \
    int *comm, int *color, int *key, int *newcomm, int *ret);                  \
    void pmpi_comm_split_(int *comm, int *color, int *key, int *newcomm,       \
                          int *ret);
{ return INTERFACE_F_LOCAL_MPI_Comm_split(comm, color, key, newcomm); }

void mpi_comm_free_(int *comm, int *ret);
#pragma weak mpi_comm_free_ = pmpi_comm_free_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Comm_free(int *comm, int *ret);

void INTERF_2_INTEL_MPI_Comm_free(int *comm, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Comm_free)(int *comm,  \
                                                                   int *ret);  \
    void pmpi_comm_free_(int *comm, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Comm_free(comm); }

void mpi_comm_test_inter_(int *comm, int *flag, int *ret);
#pragma weak mpi_comm_test_inter_ = pmpi_comm_test_inter_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Comm_test_inter(int *comm, int *flag, int *ret);

void INTERF_2_INTEL_MPI_Comm_test_inter(int *comm, int *flag, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Comm_test_inter)(      \
    int *comm, int *flag, int *ret);                                           \
    void pmpi_comm_test_inter_(int *comm, int *flag, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Comm_test_inter(comm, flag); }

void mpi_comm_remote_size_(int *comm, int *size, int *ret);
#pragma weak mpi_comm_remote_size_ = pmpi_comm_remote_size_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Comm_remote_size(int *comm, int *size, int *ret);

void INTERF_2_INTEL_MPI_Comm_remote_size(int *comm, int *size, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Comm_remote_size)(     \
    int *comm, int *size, int *ret);                                           \
    void pmpi_comm_remote_size_(int *comm, int *size, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Comm_remote_size(comm, size); }

void mpi_comm_remote_group_(int *comm, int *group, int *ret);
#pragma weak mpi_comm_remote_group_ = pmpi_comm_remote_group_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Comm_remote_group(int *comm, int *group, int *ret);

void INTERF_2_INTEL_MPI_Comm_remote_group(int *comm, int *group, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Comm_remote_group)(    \
    int *comm, int *group, int *ret);                                          \
    void pmpi_comm_remote_group_(int *comm, int *group, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Comm_remote_group(comm, group); }

void mpi_intercomm_create_(int *local_comm, int *local_leader, int *peer_comm,
                           int *remote_leader, int *tag, int *newintercomm,
                           int *ret);
#pragma weak mpi_intercomm_create_ = pmpi_intercomm_create_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Intercomm_create(int *local_comm, int *local_leader,
                                        int *peer_comm, int *remote_leader,
                                        int *tag, int *newintercomm, int *ret);

void INTERF_2_INTEL_MPI_Intercomm_create(int *local_comm, int *local_leader,
                                         int *peer_comm, int *remote_leader,
                                         int *tag, int *newintercomm, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Intercomm_create)(     \
    int *local_comm, int *local_leader, int *peer_comm, int *remote_leader,    \
    int *tag, int *newintercomm, int *ret);                                    \
    void pmpi_intercomm_create_(int *local_comm, int *local_leader,            \
                                int *peer_comm, int *remote_leader, int *tag,  \
                                int *newintercomm, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Intercomm_create(
      local_comm, local_leader, peer_comm, remote_leader, tag, newintercomm);
}

void mpi_intercomm_merge_(int *intercomm, int *high, int *newintracomm,
                          int *ret);
#pragma weak mpi_intercomm_merge_ = pmpi_intercomm_merge_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Intercomm_merge(int *intercomm, int *high,
                                       int *newintracomm, int *ret);

void INTERF_2_INTEL_MPI_Intercomm_merge(int *intercomm, int *high,
                                        int *newintracomm, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Intercomm_merge)(      \
    int *intercomm, int *high, int *newintracomm, int *ret);                   \
    void pmpi_intercomm_merge_(int *intercomm, int *high, int *newintracomm,   \
                               int *ret);
{ return INTERFACE_F_LOCAL_MPI_Intercomm_merge(intercomm, high, newintracomm); }

void mpi_keyval_create_(void *copy_fn, void *delete_fn, int *keyval,
                        void *extra_state, int *ret);
#pragma weak mpi_keyval_create_ = pmpi_keyval_create_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Keyval_create(void *copy_fn, void *delete_fn,
                                     int *keyval, void *extra_state, int *ret);

void INTERF_2_INTEL_MPI_Keyval_create(void *copy_fn, void *delete_fn,
                                      int *keyval, void *extra_state, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Keyval_create)(        \
    void *copy_fn, void *delete_fn, int *keyval, void *extra_state, int *ret); \
    void pmpi_keyval_create_(void *copy_fn, void *delete_fn, int *keyval,      \
                             void *extra_state, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Keyval_create(copy_fn, delete_fn, keyval,
                                             extra_state);
}

void mpi_keyval_free_(int *keyval, int *ret);
#pragma weak mpi_keyval_free_ = pmpi_keyval_free_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Keyval_free(int *keyval, int *ret);

void INTERF_2_INTEL_MPI_Keyval_free(int *keyval, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Keyval_free)(          \
    int *keyval, int *ret);                                                    \
    void pmpi_keyval_free_(int *keyval, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Keyval_free(keyval); }

void mpi_attr_put_(int *comm, int *keyval, void *attribute_val, int *ret);
#pragma weak mpi_attr_put_ = pmpi_attr_put_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Attr_put(int *comm, int *keyval, void *attribute_val,
                                int *ret);

void INTERF_2_INTEL_MPI_Attr_put(int *comm, int *keyval, void *attribute_val,
                                 int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Attr_put)(             \
    int *comm, int *keyval, void *attribute_val, int *ret);                    \
    void pmpi_attr_put_(int *comm, int *keyval, void *attribute_val,           \
                        int *ret);
{ return INTERFACE_F_LOCAL_MPI_Attr_put(comm, keyval, attribute_val); }

void mpi_attr_get_(int *comm, int *keyval, void *attribute_val, int *flag,
                   int *ret);
#pragma weak mpi_attr_get_ = pmpi_attr_get_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Attr_get(int *comm, int *keyval, void *attribute_val,
                                int *flag, int *ret);

void INTERF_2_INTEL_MPI_Attr_get(int *comm, int *keyval, void *attribute_val,
                                 int *flag, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Attr_get)(             \
    int *comm, int *keyval, void *attribute_val, int *flag, int *ret);         \
    void pmpi_attr_get_(int *comm, int *keyval, void *attribute_val,           \
                        int *flag, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Attr_get(comm, keyval, attribute_val, flag); }

void mpi_attr_delete_(int *comm, int *keyval, int *ret);
#pragma weak mpi_attr_delete_ = pmpi_attr_delete_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Attr_delete(int *comm, int *keyval, int *ret);

void INTERF_2_INTEL_MPI_Attr_delete(int *comm, int *keyval, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Attr_delete)(          \
    int *comm, int *keyval, int *ret);                                         \
    void pmpi_attr_delete_(int *comm, int *keyval, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Attr_delete(comm, keyval); }

void mpi_topo_test_(int *comm, int *status, int *ret);
#pragma weak mpi_topo_test_ = pmpi_topo_test_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Topo_test(int *comm, int *status, int *ret);

void INTERF_2_INTEL_MPI_Topo_test(int *comm, int *status, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Topo_test)(            \
    int *comm, int *status, int *ret);                                         \
    void pmpi_topo_test_(int *comm, int *status, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Topo_test(comm, status); }

void mpi_graphdims_get_(int *comm, int *nnodes, int *nedges, int *ret);
#pragma weak mpi_graphdims_get_ = pmpi_graphdims_get_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Graphdims_get(int *comm, int *nnodes, int *nedges,
                                     int *ret);

void INTERF_2_INTEL_MPI_Graphdims_get(int *comm, int *nnodes, int *nedges,
                                      int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Graphdims_get)(        \
    int *comm, int *nnodes, int *nedges, int *ret);                            \
    void pmpi_graphdims_get_(int *comm, int *nnodes, int *nedges, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Graphdims_get(comm, nnodes, nedges); }

void mpi_cartdim_get_(int *comm, int *ndims, int *ret);
#pragma weak mpi_cartdim_get_ = pmpi_cartdim_get_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Cartdim_get(int *comm, int *ndims, int *ret);

void INTERF_2_INTEL_MPI_Cartdim_get(int *comm, int *ndims, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Cartdim_get)(          \
    int *comm, int *ndims, int *ret);                                          \
    void pmpi_cartdim_get_(int *comm, int *ndims, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Cartdim_get(comm, ndims); }

void mpi_graph_neighbors_count_(int *comm, int *rank, int *nneighbors,
                                int *ret);
#pragma weak mpi_graph_neighbors_count_ = pmpi_graph_neighbors_count_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Graph_neighbors_count(int *comm, int *rank,
                                             int *nneighbors, int *ret);

void INTERF_2_INTEL_MPI_Graph_neighbors_count(int *comm, int *rank,
                                              int *nneighbors, int *ret);

#endif /* WI4MPI_STATIC */ void (                                              \
    *INTERFACE_F_LOCAL_MPI_Graph_neighbors_count)(int *comm, int *rank,        \
                                                  int *nneighbors, int *ret);  \
    void pmpi_graph_neighbors_count_(int *comm, int *rank, int *nneighbors,    \
                                     int *ret);
{ return INTERFACE_F_LOCAL_MPI_Graph_neighbors_count(comm, rank, nneighbors); }

void mpi_cart_shift_(int *comm, int *direction, int *disp, int *rank_source,
                     int *rank_dest, int *ret);
#pragma weak mpi_cart_shift_ = pmpi_cart_shift_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Cart_shift(int *comm, int *direction, int *disp,
                                  int *rank_source, int *rank_dest, int *ret);

void INTERF_2_INTEL_MPI_Cart_shift(int *comm, int *direction, int *disp,
                                   int *rank_source, int *rank_dest, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Cart_shift)(           \
    int *comm, int *direction, int *disp, int *rank_source, int *rank_dest,    \
    int *ret);                                                                 \
    void pmpi_cart_shift_(int *comm, int *direction, int *disp,                \
                          int *rank_source, int *rank_dest, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Cart_shift(comm, direction, disp, rank_source,
                                          rank_dest);
}

void mpi_get_processor_name_(char name, int *resultlen, int *ret);
#pragma weak mpi_get_processor_name_ = pmpi_get_processor_name_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Get_processor_name(char name, int *resultlen, int *ret);

void INTERF_2_INTEL_MPI_Get_processor_name(char name, int *resultlen, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Get_processor_name)(   \
    char name, int *resultlen, int *ret);                                      \
    void pmpi_get_processor_name_(char name, int *resultlen, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Get_processor_name(name, resultlen); }

void mpi_get_version_(int *version, int *subversion, int *ret);
#pragma weak mpi_get_version_ = pmpi_get_version_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Get_version(int *version, int *subversion, int *ret);

void INTERF_2_INTEL_MPI_Get_version(int *version, int *subversion, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Get_version)(          \
    int *version, int *subversion, int *ret);                                  \
    void pmpi_get_version_(int *version, int *subversion, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Get_version(version, subversion); }

void mpi_get_library_version_(char version, int *resultlen, int *ret);
#pragma weak mpi_get_library_version_ = pmpi_get_library_version_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Get_library_version(char version, int *resultlen,
                                           int *ret);

void INTERF_2_INTEL_MPI_Get_library_version(char version, int *resultlen,
                                            int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Get_library_version)(  \
    char version, int *resultlen, int *ret);                                   \
    void pmpi_get_library_version_(char version, int *resultlen, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Get_library_version(version, resultlen); }

void mpi_errhandler_create_(void *function, int *errhandler, int *ret);
#pragma weak mpi_errhandler_create_ = pmpi_errhandler_create_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Errhandler_create(void *function, int *errhandler,
                                         int *ret);

void INTERF_2_INTEL_MPI_Errhandler_create(void *function, int *errhandler,
                                          int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Errhandler_create)(    \
    void *function, int *errhandler, int *ret);                                \
    void pmpi_errhandler_create_(void *function, int *errhandler, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Errhandler_create(function, errhandler); }

void mpi_errhandler_set_(int *comm, int *errhandler, int *ret);
#pragma weak mpi_errhandler_set_ = pmpi_errhandler_set_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Errhandler_set(int *comm, int *errhandler, int *ret);

void INTERF_2_INTEL_MPI_Errhandler_set(int *comm, int *errhandler, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Errhandler_set)(       \
    int *comm, int *errhandler, int *ret);                                     \
    void pmpi_errhandler_set_(int *comm, int *errhandler, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Errhandler_set(comm, errhandler); }

void mpi_errhandler_get_(int *comm, int *errhandler, int *ret);
#pragma weak mpi_errhandler_get_ = pmpi_errhandler_get_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Errhandler_get(int *comm, int *errhandler, int *ret);

void INTERF_2_INTEL_MPI_Errhandler_get(int *comm, int *errhandler, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Errhandler_get)(       \
    int *comm, int *errhandler, int *ret);                                     \
    void pmpi_errhandler_get_(int *comm, int *errhandler, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Errhandler_get(comm, errhandler); }

void mpi_errhandler_free_(int *errhandler, int *ret);
#pragma weak mpi_errhandler_free_ = pmpi_errhandler_free_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Errhandler_free(int *errhandler, int *ret);

void INTERF_2_INTEL_MPI_Errhandler_free(int *errhandler, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Errhandler_free)(      \
    int *errhandler, int *ret);                                                \
    void pmpi_errhandler_free_(int *errhandler, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Errhandler_free(errhandler); }

void mpi_error_string_(int *errorcode, char string, int *resultlen, int *ret);
#pragma weak mpi_error_string_ = pmpi_error_string_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Error_string(int *errorcode, char string, int *resultlen,
                                    int *ret);

void INTERF_2_INTEL_MPI_Error_string(int *errorcode, char string,
                                     int *resultlen, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Error_string)(         \
    int *errorcode, char string, int *resultlen, int *ret);                    \
    void pmpi_error_string_(int *errorcode, char string, int *resultlen,       \
                            int *ret);
{ return INTERFACE_F_LOCAL_MPI_Error_string(errorcode, string, resultlen); }

void mpi_error_class_(int *errorcode, int *errorclass, int *ret);
#pragma weak mpi_error_class_ = pmpi_error_class_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Error_class(int *errorcode, int *errorclass, int *ret);

void INTERF_2_INTEL_MPI_Error_class(int *errorcode, int *errorclass, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Error_class)(          \
    int *errorcode, int *errorclass, int *ret);                                \
    void pmpi_error_class_(int *errorcode, int *errorclass, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Error_class(errorcode, errorclass); }

void mpi_initialized_(int *flag, int *ret);
#pragma weak mpi_initialized_ = pmpi_initialized_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Initialized(int *flag, int *ret);

void INTERF_2_INTEL_MPI_Initialized(int *flag, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Initialized)(          \
    int *flag, int *ret);                                                      \
    void pmpi_initialized_(int *flag, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Initialized(flag); }

void mpi_abort_(int *comm, int *errorcode, int *ret);
#pragma weak mpi_abort_ = pmpi_abort_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Abort(int *comm, int *errorcode, int *ret);

void INTERF_2_INTEL_MPI_Abort(int *comm, int *errorcode, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Abort)(                \
    int *comm, int *errorcode, int *ret);                                      \
    void pmpi_abort_(int *comm, int *errorcode, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Abort(comm, errorcode); }

void mpi_close_port_(char port_name, int *ret);
#pragma weak mpi_close_port_ = pmpi_close_port_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Close_port(char port_name, int *ret);

void INTERF_2_INTEL_MPI_Close_port(char port_name, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Close_port)(           \
    char port_name, int *ret);                                                 \
    void pmpi_close_port_(char port_name, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Close_port(port_name); }

void mpi_comm_accept_(char port_name, int *info, int *root, int *comm,
                      int *newcomm, int *ret);
#pragma weak mpi_comm_accept_ = pmpi_comm_accept_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Comm_accept(char port_name, int *info, int *root,
                                   int *comm, int *newcomm, int *ret);

void INTERF_2_INTEL_MPI_Comm_accept(char port_name, int *info, int *root,
                                    int *comm, int *newcomm, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Comm_accept)(          \
    char port_name, int *info, int *root, int *comm, int *newcomm, int *ret);  \
    void pmpi_comm_accept_(char port_name, int *info, int *root, int *comm,    \
                           int *newcomm, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Comm_accept(port_name, info, root, comm,
                                           newcomm);
}

void mpi_comm_connect_(char port_name, int *info, int *root, int *comm,
                       int *newcomm, int *ret);
#pragma weak mpi_comm_connect_ = pmpi_comm_connect_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Comm_connect(char port_name, int *info, int *root,
                                    int *comm, int *newcomm, int *ret);

void INTERF_2_INTEL_MPI_Comm_connect(char port_name, int *info, int *root,
                                     int *comm, int *newcomm, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Comm_connect)(         \
    char port_name, int *info, int *root, int *comm, int *newcomm, int *ret);  \
    void pmpi_comm_connect_(char port_name, int *info, int *root, int *comm,   \
                            int *newcomm, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Comm_connect(port_name, info, root, comm,
                                            newcomm);
}

void mpi_comm_disconnect_(int *comm, int *ret);
#pragma weak mpi_comm_disconnect_ = pmpi_comm_disconnect_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Comm_disconnect(int *comm, int *ret);

void INTERF_2_INTEL_MPI_Comm_disconnect(int *comm, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Comm_disconnect)(      \
    int *comm, int *ret);                                                      \
    void pmpi_comm_disconnect_(int *comm, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Comm_disconnect(comm); }

void mpi_comm_get_parent_(int *parent, int *ret);
#pragma weak mpi_comm_get_parent_ = pmpi_comm_get_parent_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Comm_get_parent(int *parent, int *ret);

void INTERF_2_INTEL_MPI_Comm_get_parent(int *parent, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Comm_get_parent)(      \
    int *parent, int *ret);                                                    \
    void pmpi_comm_get_parent_(int *parent, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Comm_get_parent(parent); }

void mpi_comm_join_(int *fd, int *intercomm, int *ret);
#pragma weak mpi_comm_join_ = pmpi_comm_join_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Comm_join(int *fd, int *intercomm, int *ret);

void INTERF_2_INTEL_MPI_Comm_join(int *fd, int *intercomm, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Comm_join)(            \
    int *fd, int *intercomm, int *ret);                                        \
    void pmpi_comm_join_(int *fd, int *intercomm, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Comm_join(fd, intercomm); }

void mpi_open_port_(int *info, char port_name, int *ret);
#pragma weak mpi_open_port_ = pmpi_open_port_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Open_port(int *info, char port_name, int *ret);

void INTERF_2_INTEL_MPI_Open_port(int *info, char port_name, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Open_port)(            \
    int *info, char port_name, int *ret);                                      \
    void pmpi_open_port_(int *info, char port_name, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Open_port(info, port_name); }

void mpi_comm_set_info_(int *comm, int *info, int *ret);
#pragma weak mpi_comm_set_info_ = pmpi_comm_set_info_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Comm_set_info(int *comm, int *info, int *ret);

void INTERF_2_INTEL_MPI_Comm_set_info(int *comm, int *info, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Comm_set_info)(        \
    int *comm, int *info, int *ret);                                           \
    void pmpi_comm_set_info_(int *comm, int *info, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Comm_set_info(comm, info); }

void mpi_comm_get_info_(int *comm, int *info, int *ret);
#pragma weak mpi_comm_get_info_ = pmpi_comm_get_info_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Comm_get_info(int *comm, int *info, int *ret);

void INTERF_2_INTEL_MPI_Comm_get_info(int *comm, int *info, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Comm_get_info)(        \
    int *comm, int *info, int *ret);                                           \
    void pmpi_comm_get_info_(int *comm, int *info, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Comm_get_info(comm, info); }

void mpi_accumulate_(void *origin_addr, int *origin_count, int *origin_datatype,
                     int *target_rank, size_t target_disp, int *target_count,
                     int *target_datatype, int *op, int *win, int *ret);
#pragma weak mpi_accumulate_ = pmpi_accumulate_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Accumulate(void *origin_addr, int *origin_count,
                                  int *origin_datatype, int *target_rank,
                                  size_t target_disp, int *target_count,
                                  int *target_datatype, int *op, int *win,
                                  int *ret);

void INTERF_2_INTEL_MPI_Accumulate(void *origin_addr, int *origin_count,
                                   int *origin_datatype, int *target_rank,
                                   size_t target_disp, int *target_count,
                                   int *target_datatype, int *op, int *win,
                                   int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Accumulate)(           \
    void *origin_addr, int *origin_count, int *origin_datatype,                \
    int *target_rank, size_t target_disp, int *target_count,                   \
    int *target_datatype, int *op, int *win, int *ret);                        \
    void pmpi_accumulate_(void *origin_addr, int *origin_count,                \
                          int *origin_datatype, int *target_rank,              \
                          size_t target_disp, int *target_count,               \
                          int *target_datatype, int *op, int *win, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Accumulate(
      origin_addr, origin_count, origin_datatype, target_rank, target_disp,
      target_count, target_datatype, op, win);
}

void mpi_get_(void *origin_addr, int *origin_count, int *origin_datatype,
              int *target_rank, size_t target_disp, int *target_count,
              int *target_datatype, int *win, int *ret);
#pragma weak mpi_get_ = pmpi_get_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Get(void *origin_addr, int *origin_count,
                           int *origin_datatype, int *target_rank,
                           size_t target_disp, int *target_count,
                           int *target_datatype, int *win, int *ret);

void INTERF_2_INTEL_MPI_Get(void *origin_addr, int *origin_count,
                            int *origin_datatype, int *target_rank,
                            size_t target_disp, int *target_count,
                            int *target_datatype, int *win, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Get)(                  \
    void *origin_addr, int *origin_count, int *origin_datatype,                \
    int *target_rank, size_t target_disp, int *target_count,                   \
    int *target_datatype, int *win, int *ret);                                 \
    void pmpi_get_(void *origin_addr, int *origin_count, int *origin_datatype, \
                   int *target_rank, size_t target_disp, int *target_count,    \
                   int *target_datatype, int *win, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Get(origin_addr, origin_count, origin_datatype,
                                   target_rank, target_disp, target_count,
                                   target_datatype, win);
}

void mpi_put_(void *origin_addr, int *origin_count, int *origin_datatype,
              int *target_rank, size_t target_disp, int *target_count,
              int *target_datatype, int *win, int *ret);
#pragma weak mpi_put_ = pmpi_put_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Put(void *origin_addr, int *origin_count,
                           int *origin_datatype, int *target_rank,
                           size_t target_disp, int *target_count,
                           int *target_datatype, int *win, int *ret);

void INTERF_2_INTEL_MPI_Put(void *origin_addr, int *origin_count,
                            int *origin_datatype, int *target_rank,
                            size_t target_disp, int *target_count,
                            int *target_datatype, int *win, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Put)(                  \
    void *origin_addr, int *origin_count, int *origin_datatype,                \
    int *target_rank, size_t target_disp, int *target_count,                   \
    int *target_datatype, int *win, int *ret);                                 \
    void pmpi_put_(void *origin_addr, int *origin_count, int *origin_datatype, \
                   int *target_rank, size_t target_disp, int *target_count,    \
                   int *target_datatype, int *win, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Put(origin_addr, origin_count, origin_datatype,
                                   target_rank, target_disp, target_count,
                                   target_datatype, win);
}

void mpi_win_complete_(int *win, int *ret);
#pragma weak mpi_win_complete_ = pmpi_win_complete_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Win_complete(int *win, int *ret);

void INTERF_2_INTEL_MPI_Win_complete(int *win, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Win_complete)(         \
    int *win, int *ret);                                                       \
    void pmpi_win_complete_(int *win, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Win_complete(win); }

void mpi_win_create_(void *base, size_t size, int *disp_unit, int *info,
                     int *comm, int *win, int *ret);
#pragma weak mpi_win_create_ = pmpi_win_create_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Win_create(void *base, size_t size, int *disp_unit,
                                  int *info, int *comm, int *win, int *ret);

void INTERF_2_INTEL_MPI_Win_create(void *base, size_t size, int *disp_unit,
                                   int *info, int *comm, int *win, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Win_create)(           \
    void *base, size_t size, int *disp_unit, int *info, int *comm, int *win,   \
    int *ret);                                                                 \
    void pmpi_win_create_(void *base, size_t size, int *disp_unit, int *info,  \
                          int *comm, int *win, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Win_create(base, size, disp_unit, info, comm,
                                          win);
}

void mpi_win_fence_(int *assert, int *win, int *ret);
#pragma weak mpi_win_fence_ = pmpi_win_fence_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Win_fence(int *assert, int *win, int *ret);

void INTERF_2_INTEL_MPI_Win_fence(int *assert, int *win, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Win_fence)(            \
    int *assert, int *win, int *ret);                                          \
    void pmpi_win_fence_(int *assert, int *win, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Win_fence(assert, win); }

void mpi_win_free_(int *win, int *ret);
#pragma weak mpi_win_free_ = pmpi_win_free_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Win_free(int *win, int *ret);

void INTERF_2_INTEL_MPI_Win_free(int *win, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Win_free)(int *win,    \
                                                                  int *ret);   \
    void pmpi_win_free_(int *win, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Win_free(win); }

void mpi_win_get_group_(int *win, int *group, int *ret);
#pragma weak mpi_win_get_group_ = pmpi_win_get_group_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Win_get_group(int *win, int *group, int *ret);

void INTERF_2_INTEL_MPI_Win_get_group(int *win, int *group, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Win_get_group)(        \
    int *win, int *group, int *ret);                                           \
    void pmpi_win_get_group_(int *win, int *group, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Win_get_group(win, group); }

void mpi_win_lock_(int *lock_type, int *rank, int *assert, int *win, int *ret);
#pragma weak mpi_win_lock_ = pmpi_win_lock_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Win_lock(int *lock_type, int *rank, int *assert,
                                int *win, int *ret);

void INTERF_2_INTEL_MPI_Win_lock(int *lock_type, int *rank, int *assert,
                                 int *win, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Win_lock)(             \
    int *lock_type, int *rank, int *assert, int *win, int *ret);               \
    void pmpi_win_lock_(int *lock_type, int *rank, int *assert, int *win,      \
                        int *ret);
{ return INTERFACE_F_LOCAL_MPI_Win_lock(lock_type, rank, assert, win); }

void mpi_win_post_(int *group, int *assert, int *win, int *ret);
#pragma weak mpi_win_post_ = pmpi_win_post_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Win_post(int *group, int *assert, int *win, int *ret);

void INTERF_2_INTEL_MPI_Win_post(int *group, int *assert, int *win, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Win_post)(             \
    int *group, int *assert, int *win, int *ret);                              \
    void pmpi_win_post_(int *group, int *assert, int *win, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Win_post(group, assert, win); }

void mpi_win_start_(int *group, int *assert, int *win, int *ret);
#pragma weak mpi_win_start_ = pmpi_win_start_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Win_start(int *group, int *assert, int *win, int *ret);

void INTERF_2_INTEL_MPI_Win_start(int *group, int *assert, int *win, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Win_start)(            \
    int *group, int *assert, int *win, int *ret);                              \
    void pmpi_win_start_(int *group, int *assert, int *win, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Win_start(group, assert, win); }

void mpi_win_test_(int *win, int *flag, int *ret);
#pragma weak mpi_win_test_ = pmpi_win_test_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Win_test(int *win, int *flag, int *ret);

void INTERF_2_INTEL_MPI_Win_test(int *win, int *flag, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Win_test)(             \
    int *win, int *flag, int *ret);                                            \
    void pmpi_win_test_(int *win, int *flag, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Win_test(win, flag); }

void mpi_win_unlock_(int *rank, int *win, int *ret);
#pragma weak mpi_win_unlock_ = pmpi_win_unlock_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Win_unlock(int *rank, int *win, int *ret);

void INTERF_2_INTEL_MPI_Win_unlock(int *rank, int *win, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Win_unlock)(           \
    int *rank, int *win, int *ret);                                            \
    void pmpi_win_unlock_(int *rank, int *win, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Win_unlock(rank, win); }

void mpi_win_wait_(int *win, int *ret);
#pragma weak mpi_win_wait_ = pmpi_win_wait_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Win_wait(int *win, int *ret);

void INTERF_2_INTEL_MPI_Win_wait(int *win, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Win_wait)(int *win,    \
                                                                  int *ret);   \
    void pmpi_win_wait_(int *win, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Win_wait(win); }

void mpi_win_allocate_(size_t size, int *disp_unit, int *info, int *comm,
                       void *baseptr, int *win, int *ret);
#pragma weak mpi_win_allocate_ = pmpi_win_allocate_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Win_allocate(size_t size, int *disp_unit, int *info,
                                    int *comm, void *baseptr, int *win,
                                    int *ret);

void INTERF_2_INTEL_MPI_Win_allocate(size_t size, int *disp_unit, int *info,
                                     int *comm, void *baseptr, int *win,
                                     int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Win_allocate)(         \
    size_t size, int *disp_unit, int *info, int *comm, void *baseptr,          \
    int *win, int *ret);                                                       \
    void pmpi_win_allocate_(size_t size, int *disp_unit, int *info, int *comm, \
                            void *baseptr, int *win, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Win_allocate(size, disp_unit, info, comm,
                                            baseptr, win);
}

void mpi_win_allocate_shared_(size_t size, int *disp_unit, int *info, int *comm,
                              void *baseptr, int *win, int *ret);
#pragma weak mpi_win_allocate_shared_ = pmpi_win_allocate_shared_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Win_allocate_shared(size_t size, int *disp_unit,
                                           int *info, int *comm, void *baseptr,
                                           int *win, int *ret);

void INTERF_2_INTEL_MPI_Win_allocate_shared(size_t size, int *disp_unit,
                                            int *info, int *comm, void *baseptr,
                                            int *win, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Win_allocate_shared)(  \
    size_t size, int *disp_unit, int *info, int *comm, void *baseptr,          \
    int *win, int *ret);                                                       \
    void pmpi_win_allocate_shared_(size_t size, int *disp_unit, int *info,     \
                                   int *comm, void *baseptr, int *win,         \
                                   int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Win_allocate_shared(size, disp_unit, info, comm,
                                                   baseptr, win);
}

void mpi_win_shared_query_(int *win, int *rank, size_t size, int *disp_unit,
                           void *baseptr, int *ret);
#pragma weak mpi_win_shared_query_ = pmpi_win_shared_query_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Win_shared_query(int *win, int *rank, size_t size,
                                        int *disp_unit, void *baseptr,
                                        int *ret);

void INTERF_2_INTEL_MPI_Win_shared_query(int *win, int *rank, size_t size,
                                         int *disp_unit, void *baseptr,
                                         int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Win_shared_query)(     \
    int *win, int *rank, size_t size, int *disp_unit, void *baseptr,           \
    int *ret);                                                                 \
    void pmpi_win_shared_query_(int *win, int *rank, size_t size,              \
                                int *disp_unit, void *baseptr, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Win_shared_query(win, rank, size, disp_unit,
                                                baseptr);
}

void mpi_win_create_dynamic_(int *info, int *comm, int *win, int *ret);
#pragma weak mpi_win_create_dynamic_ = pmpi_win_create_dynamic_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Win_create_dynamic(int *info, int *comm, int *win,
                                          int *ret);

void INTERF_2_INTEL_MPI_Win_create_dynamic(int *info, int *comm, int *win,
                                           int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Win_create_dynamic)(   \
    int *info, int *comm, int *win, int *ret);                                 \
    void pmpi_win_create_dynamic_(int *info, int *comm, int *win, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Win_create_dynamic(info, comm, win); }

void mpi_win_attach_(int *win, void *base, size_t size, int *ret);
#pragma weak mpi_win_attach_ = pmpi_win_attach_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Win_attach(int *win, void *base, size_t size, int *ret);

void INTERF_2_INTEL_MPI_Win_attach(int *win, void *base, size_t size, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Win_attach)(           \
    int *win, void *base, size_t size, int *ret);                              \
    void pmpi_win_attach_(int *win, void *base, size_t size, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Win_attach(win, base, size); }

void mpi_win_detach_(int *win, void *base, int *ret);
#pragma weak mpi_win_detach_ = pmpi_win_detach_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Win_detach(int *win, void *base, int *ret);

void INTERF_2_INTEL_MPI_Win_detach(int *win, void *base, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Win_detach)(           \
    int *win, void *base, int *ret);                                           \
    void pmpi_win_detach_(int *win, void *base, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Win_detach(win, base); }

void mpi_win_get_info_(int *win, int *info_used, int *ret);
#pragma weak mpi_win_get_info_ = pmpi_win_get_info_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Win_get_info(int *win, int *info_used, int *ret);

void INTERF_2_INTEL_MPI_Win_get_info(int *win, int *info_used, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Win_get_info)(         \
    int *win, int *info_used, int *ret);                                       \
    void pmpi_win_get_info_(int *win, int *info_used, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Win_get_info(win, info_used); }

void mpi_win_set_info_(int *win, int *info, int *ret);
#pragma weak mpi_win_set_info_ = pmpi_win_set_info_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Win_set_info(int *win, int *info, int *ret);

void INTERF_2_INTEL_MPI_Win_set_info(int *win, int *info, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Win_set_info)(         \
    int *win, int *info, int *ret);                                            \
    void pmpi_win_set_info_(int *win, int *info, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Win_set_info(win, info); }

void mpi_get_accumulate_(void *origin_addr, int *origin_count,
                         int *origin_datatype, void *result_addr,
                         int *result_count, int *result_datatype,
                         int *target_rank, size_t target_disp,
                         int *target_count, int *target_datatype, int *op,
                         int *win, int *ret);
#pragma weak mpi_get_accumulate_ = pmpi_get_accumulate_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Get_accumulate(void *origin_addr, int *origin_count,
                                      int *origin_datatype, void *result_addr,
                                      int *result_count, int *result_datatype,
                                      int *target_rank, size_t target_disp,
                                      int *target_count, int *target_datatype,
                                      int *op, int *win, int *ret);

void INTERF_2_INTEL_MPI_Get_accumulate(void *origin_addr, int *origin_count,
                                       int *origin_datatype, void *result_addr,
                                       int *result_count, int *result_datatype,
                                       int *target_rank, size_t target_disp,
                                       int *target_count, int *target_datatype,
                                       int *op, int *win, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Get_accumulate)(       \
    void *origin_addr, int *origin_count, int *origin_datatype,                \
    void *result_addr, int *result_count, int *result_datatype,                \
    int *target_rank, size_t target_disp, int *target_count,                   \
    int *target_datatype, int *op, int *win, int *ret);                        \
    void pmpi_get_accumulate_(                                                 \
        void *origin_addr, int *origin_count, int *origin_datatype,            \
        void *result_addr, int *result_count, int *result_datatype,            \
        int *target_rank, size_t target_disp, int *target_count,               \
        int *target_datatype, int *op, int *win, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Get_accumulate(
      origin_addr, origin_count, origin_datatype, result_addr, result_count,
      result_datatype, target_rank, target_disp, target_count, target_datatype,
      op, win);
}

void mpi_fetch_and_op_(void *origin_addr, void *result_addr, int *datatype,
                       int *target_rank, size_t target_disp, int *op, int *win,
                       int *ret);
#pragma weak mpi_fetch_and_op_ = pmpi_fetch_and_op_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Fetch_and_op(void *origin_addr, void *result_addr,
                                    int *datatype, int *target_rank,
                                    size_t target_disp, int *op, int *win,
                                    int *ret);

void INTERF_2_INTEL_MPI_Fetch_and_op(void *origin_addr, void *result_addr,
                                     int *datatype, int *target_rank,
                                     size_t target_disp, int *op, int *win,
                                     int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Fetch_and_op)(         \
    void *origin_addr, void *result_addr, int *datatype, int *target_rank,     \
    size_t target_disp, int *op, int *win, int *ret);                          \
    void pmpi_fetch_and_op_(void *origin_addr, void *result_addr,              \
                            int *datatype, int *target_rank,                   \
                            size_t target_disp, int *op, int *win, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Fetch_and_op(origin_addr, result_addr, datatype,
                                            target_rank, target_disp, op, win);
}

void mpi_compare_and_swap_(void *origin_addr, void *compare_addr,
                           void *result_addr, int *datatype, int *target_rank,
                           size_t target_disp, int *win, int *ret);
#pragma weak mpi_compare_and_swap_ = pmpi_compare_and_swap_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Compare_and_swap(void *origin_addr, void *compare_addr,
                                        void *result_addr, int *datatype,
                                        int *target_rank, size_t target_disp,
                                        int *win, int *ret);

void INTERF_2_INTEL_MPI_Compare_and_swap(void *origin_addr, void *compare_addr,
                                         void *result_addr, int *datatype,
                                         int *target_rank, size_t target_disp,
                                         int *win, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Compare_and_swap)(     \
    void *origin_addr, void *compare_addr, void *result_addr, int *datatype,   \
    int *target_rank, size_t target_disp, int *win, int *ret);                 \
    void pmpi_compare_and_swap_(void *origin_addr, void *compare_addr,         \
                                void *result_addr, int *datatype,              \
                                int *target_rank, size_t target_disp,          \
                                int *win, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Compare_and_swap(origin_addr, compare_addr,
                                                result_addr, datatype,
                                                target_rank, target_disp, win);
}

void mpi_rput_(void *origin_addr, int *origin_count, int *origin_datatype,
               int *target_rank, size_t target_disp, int *target_count,
               int *target_datatype, int *win, int *request, int *ret);
#pragma weak mpi_rput_ = pmpi_rput_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Rput(void *origin_addr, int *origin_count,
                            int *origin_datatype, int *target_rank,
                            size_t target_disp, int *target_count,
                            int *target_datatype, int *win, int *request,
                            int *ret);

void INTERF_2_INTEL_MPI_Rput(void *origin_addr, int *origin_count,
                             int *origin_datatype, int *target_rank,
                             size_t target_disp, int *target_count,
                             int *target_datatype, int *win, int *request,
                             int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Rput)(                 \
    void *origin_addr, int *origin_count, int *origin_datatype,                \
    int *target_rank, size_t target_disp, int *target_count,                   \
    int *target_datatype, int *win, int *request, int *ret);                   \
    void pmpi_rput_(void *origin_addr, int *origin_count,                      \
                    int *origin_datatype, int *target_rank,                    \
                    size_t target_disp, int *target_count,                     \
                    int *target_datatype, int *win, int *request, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Rput(origin_addr, origin_count, origin_datatype,
                                    target_rank, target_disp, target_count,
                                    target_datatype, win, request);
}

void mpi_rget_(void *origin_addr, int *origin_count, int *origin_datatype,
               int *target_rank, size_t target_disp, int *target_count,
               int *target_datatype, int *win, int *request, int *ret);
#pragma weak mpi_rget_ = pmpi_rget_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Rget(void *origin_addr, int *origin_count,
                            int *origin_datatype, int *target_rank,
                            size_t target_disp, int *target_count,
                            int *target_datatype, int *win, int *request,
                            int *ret);

void INTERF_2_INTEL_MPI_Rget(void *origin_addr, int *origin_count,
                             int *origin_datatype, int *target_rank,
                             size_t target_disp, int *target_count,
                             int *target_datatype, int *win, int *request,
                             int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Rget)(                 \
    void *origin_addr, int *origin_count, int *origin_datatype,                \
    int *target_rank, size_t target_disp, int *target_count,                   \
    int *target_datatype, int *win, int *request, int *ret);                   \
    void pmpi_rget_(void *origin_addr, int *origin_count,                      \
                    int *origin_datatype, int *target_rank,                    \
                    size_t target_disp, int *target_count,                     \
                    int *target_datatype, int *win, int *request, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Rget(origin_addr, origin_count, origin_datatype,
                                    target_rank, target_disp, target_count,
                                    target_datatype, win, request);
}

void mpi_raccumulate_(void *origin_addr, int *origin_count,
                      int *origin_datatype, int *target_rank,
                      size_t target_disp, int *target_count,
                      int *target_datatype, int *op, int *win, int *request,
                      int *ret);
#pragma weak mpi_raccumulate_ = pmpi_raccumulate_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Raccumulate(void *origin_addr, int *origin_count,
                                   int *origin_datatype, int *target_rank,
                                   size_t target_disp, int *target_count,
                                   int *target_datatype, int *op, int *win,
                                   int *request, int *ret);

void INTERF_2_INTEL_MPI_Raccumulate(void *origin_addr, int *origin_count,
                                    int *origin_datatype, int *target_rank,
                                    size_t target_disp, int *target_count,
                                    int *target_datatype, int *op, int *win,
                                    int *request, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Raccumulate)(          \
    void *origin_addr, int *origin_count, int *origin_datatype,                \
    int *target_rank, size_t target_disp, int *target_count,                   \
    int *target_datatype, int *op, int *win, int *request, int *ret);          \
    void pmpi_raccumulate_(                                                    \
        void *origin_addr, int *origin_count, int *origin_datatype,            \
        int *target_rank, size_t target_disp, int *target_count,               \
        int *target_datatype, int *op, int *win, int *request, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Raccumulate(
      origin_addr, origin_count, origin_datatype, target_rank, target_disp,
      target_count, target_datatype, op, win, request);
}

void mpi_rget_accumulate_(void *origin_addr, int *origin_count,
                          int *origin_datatype, void *result_addr,
                          int *result_count, int *result_datatype,
                          int *target_rank, size_t target_disp,
                          int *target_count, int *target_datatype, int *op,
                          int *win, int *request, int *ret);
#pragma weak mpi_rget_accumulate_ = pmpi_rget_accumulate_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Rget_accumulate(void *origin_addr, int *origin_count,
                                       int *origin_datatype, void *result_addr,
                                       int *result_count, int *result_datatype,
                                       int *target_rank, size_t target_disp,
                                       int *target_count, int *target_datatype,
                                       int *op, int *win, int *request,
                                       int *ret);

void INTERF_2_INTEL_MPI_Rget_accumulate(void *origin_addr, int *origin_count,
                                        int *origin_datatype, void *result_addr,
                                        int *result_count, int *result_datatype,
                                        int *target_rank, size_t target_disp,
                                        int *target_count, int *target_datatype,
                                        int *op, int *win, int *request,
                                        int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Rget_accumulate)(      \
    void *origin_addr, int *origin_count, int *origin_datatype,                \
    void *result_addr, int *result_count, int *result_datatype,                \
    int *target_rank, size_t target_disp, int *target_count,                   \
    int *target_datatype, int *op, int *win, int *request, int *ret);          \
    void pmpi_rget_accumulate_(                                                \
        void *origin_addr, int *origin_count, int *origin_datatype,            \
        void *result_addr, int *result_count, int *result_datatype,            \
        int *target_rank, size_t target_disp, int *target_count,               \
        int *target_datatype, int *op, int *win, int *request, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Rget_accumulate(
      origin_addr, origin_count, origin_datatype, result_addr, result_count,
      result_datatype, target_rank, target_disp, target_count, target_datatype,
      op, win, request);
}

void mpi_win_lock_all_(int *assert, int *win, int *ret);
#pragma weak mpi_win_lock_all_ = pmpi_win_lock_all_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Win_lock_all(int *assert, int *win, int *ret);

void INTERF_2_INTEL_MPI_Win_lock_all(int *assert, int *win, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Win_lock_all)(         \
    int *assert, int *win, int *ret);                                          \
    void pmpi_win_lock_all_(int *assert, int *win, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Win_lock_all(assert, win); }

void mpi_win_unlock_all_(int *win, int *ret);
#pragma weak mpi_win_unlock_all_ = pmpi_win_unlock_all_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Win_unlock_all(int *win, int *ret);

void INTERF_2_INTEL_MPI_Win_unlock_all(int *win, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Win_unlock_all)(       \
    int *win, int *ret);                                                       \
    void pmpi_win_unlock_all_(int *win, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Win_unlock_all(win); }

void mpi_win_flush_(int *rank, int *win, int *ret);
#pragma weak mpi_win_flush_ = pmpi_win_flush_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Win_flush(int *rank, int *win, int *ret);

void INTERF_2_INTEL_MPI_Win_flush(int *rank, int *win, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Win_flush)(            \
    int *rank, int *win, int *ret);                                            \
    void pmpi_win_flush_(int *rank, int *win, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Win_flush(rank, win); }

void mpi_win_flush_all_(int *win, int *ret);
#pragma weak mpi_win_flush_all_ = pmpi_win_flush_all_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Win_flush_all(int *win, int *ret);

void INTERF_2_INTEL_MPI_Win_flush_all(int *win, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Win_flush_all)(        \
    int *win, int *ret);                                                       \
    void pmpi_win_flush_all_(int *win, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Win_flush_all(win); }

void mpi_win_flush_local_(int *rank, int *win, int *ret);
#pragma weak mpi_win_flush_local_ = pmpi_win_flush_local_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Win_flush_local(int *rank, int *win, int *ret);

void INTERF_2_INTEL_MPI_Win_flush_local(int *rank, int *win, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Win_flush_local)(      \
    int *rank, int *win, int *ret);                                            \
    void pmpi_win_flush_local_(int *rank, int *win, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Win_flush_local(rank, win); }

void mpi_win_flush_local_all_(int *win, int *ret);
#pragma weak mpi_win_flush_local_all_ = pmpi_win_flush_local_all_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Win_flush_local_all(int *win, int *ret);

void INTERF_2_INTEL_MPI_Win_flush_local_all(int *win, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Win_flush_local_all)(  \
    int *win, int *ret);                                                       \
    void pmpi_win_flush_local_all_(int *win, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Win_flush_local_all(win); }

void mpi_win_sync_(int *win, int *ret);
#pragma weak mpi_win_sync_ = pmpi_win_sync_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Win_sync(int *win, int *ret);

void INTERF_2_INTEL_MPI_Win_sync(int *win, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Win_sync)(int *win,    \
                                                                  int *ret);   \
    void pmpi_win_sync_(int *win, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Win_sync(win); }

void mpi_add_error_class_(int *errorclass, int *ret);
#pragma weak mpi_add_error_class_ = pmpi_add_error_class_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Add_error_class(int *errorclass, int *ret);

void INTERF_2_INTEL_MPI_Add_error_class(int *errorclass, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Add_error_class)(      \
    int *errorclass, int *ret);                                                \
    void pmpi_add_error_class_(int *errorclass, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Add_error_class(errorclass); }

void mpi_add_error_code_(int *errorclass, int *errorcode, int *ret);
#pragma weak mpi_add_error_code_ = pmpi_add_error_code_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Add_error_code(int *errorclass, int *errorcode,
                                      int *ret);

void INTERF_2_INTEL_MPI_Add_error_code(int *errorclass, int *errorcode,
                                       int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Add_error_code)(       \
    int *errorclass, int *errorcode, int *ret);                                \
    void pmpi_add_error_code_(int *errorclass, int *errorcode, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Add_error_code(errorclass, errorcode); }

void mpi_add_error_string_(int *errorcode, char string, int *ret);
#pragma weak mpi_add_error_string_ = pmpi_add_error_string_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Add_error_string(int *errorcode, char string, int *ret);

void INTERF_2_INTEL_MPI_Add_error_string(int *errorcode, char string, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Add_error_string)(     \
    int *errorcode, char string, int *ret);                                    \
    void pmpi_add_error_string_(int *errorcode, char string, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Add_error_string(errorcode, string); }

void mpi_comm_call_errhandler_(int *comm, int *errorcode, int *ret);
#pragma weak mpi_comm_call_errhandler_ = pmpi_comm_call_errhandler_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Comm_call_errhandler(int *comm, int *errorcode,
                                            int *ret);

void INTERF_2_INTEL_MPI_Comm_call_errhandler(int *comm, int *errorcode,
                                             int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Comm_call_errhandler)( \
    int *comm, int *errorcode, int *ret);                                      \
    void pmpi_comm_call_errhandler_(int *comm, int *errorcode, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Comm_call_errhandler(comm, errorcode); }

void mpi_comm_create_keyval_(void *comm_copy_attr_fn, void *comm_delete_attr_fn,
                             int *comm_keyval, void *extra_state, int *ret);
#pragma weak mpi_comm_create_keyval_ = pmpi_comm_create_keyval_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Comm_create_keyval(void *comm_copy_attr_fn,
                                          void *comm_delete_attr_fn,
                                          int *comm_keyval, void *extra_state,
                                          int *ret);

void INTERF_2_INTEL_MPI_Comm_create_keyval(void *comm_copy_attr_fn,
                                           void *comm_delete_attr_fn,
                                           int *comm_keyval, void *extra_state,
                                           int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Comm_create_keyval)(   \
    void *comm_copy_attr_fn, void *comm_delete_attr_fn, int *comm_keyval,      \
    void *extra_state, int *ret);                                              \
    void pmpi_comm_create_keyval_(void *comm_copy_attr_fn,                     \
                                  void *comm_delete_attr_fn, int *comm_keyval, \
                                  void *extra_state, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Comm_create_keyval(
      comm_copy_attr_fn, comm_delete_attr_fn, comm_keyval, extra_state);
}

void mpi_comm_delete_attr_(int *comm, int *comm_keyval, int *ret);
#pragma weak mpi_comm_delete_attr_ = pmpi_comm_delete_attr_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Comm_delete_attr(int *comm, int *comm_keyval, int *ret);

void INTERF_2_INTEL_MPI_Comm_delete_attr(int *comm, int *comm_keyval, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Comm_delete_attr)(     \
    int *comm, int *comm_keyval, int *ret);                                    \
    void pmpi_comm_delete_attr_(int *comm, int *comm_keyval, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Comm_delete_attr(comm, comm_keyval); }

void mpi_comm_free_keyval_(int *comm_keyval, int *ret);
#pragma weak mpi_comm_free_keyval_ = pmpi_comm_free_keyval_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Comm_free_keyval(int *comm_keyval, int *ret);

void INTERF_2_INTEL_MPI_Comm_free_keyval(int *comm_keyval, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Comm_free_keyval)(     \
    int *comm_keyval, int *ret);                                               \
    void pmpi_comm_free_keyval_(int *comm_keyval, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Comm_free_keyval(comm_keyval); }

void mpi_comm_get_attr_(int *comm, int *comm_keyval, void *attribute_val,
                        int *flag, int *ret);
#pragma weak mpi_comm_get_attr_ = pmpi_comm_get_attr_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Comm_get_attr(int *comm, int *comm_keyval,
                                     void *attribute_val, int *flag, int *ret);

void INTERF_2_INTEL_MPI_Comm_get_attr(int *comm, int *comm_keyval,
                                      void *attribute_val, int *flag, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Comm_get_attr)(        \
    int *comm, int *comm_keyval, void *attribute_val, int *flag, int *ret);    \
    void pmpi_comm_get_attr_(int *comm, int *comm_keyval, void *attribute_val, \
                             int *flag, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Comm_get_attr(comm, comm_keyval, attribute_val,
                                             flag);
}

void mpi_comm_get_name_(int *comm, char comm_name, int *resultlen, int *ret);
#pragma weak mpi_comm_get_name_ = pmpi_comm_get_name_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Comm_get_name(int *comm, char comm_name, int *resultlen,
                                     int *ret);

void INTERF_2_INTEL_MPI_Comm_get_name(int *comm, char comm_name, int *resultlen,
                                      int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Comm_get_name)(        \
    int *comm, char comm_name, int *resultlen, int *ret);                      \
    void pmpi_comm_get_name_(int *comm, char comm_name, int *resultlen,        \
                             int *ret);
{ return INTERFACE_F_LOCAL_MPI_Comm_get_name(comm, comm_name, resultlen); }

void mpi_comm_set_attr_(int *comm, int *comm_keyval, void *attribute_val,
                        int *ret);
#pragma weak mpi_comm_set_attr_ = pmpi_comm_set_attr_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Comm_set_attr(int *comm, int *comm_keyval,
                                     void *attribute_val, int *ret);

void INTERF_2_INTEL_MPI_Comm_set_attr(int *comm, int *comm_keyval,
                                      void *attribute_val, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Comm_set_attr)(        \
    int *comm, int *comm_keyval, void *attribute_val, int *ret);               \
    void pmpi_comm_set_attr_(int *comm, int *comm_keyval, void *attribute_val, \
                             int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Comm_set_attr(comm, comm_keyval, attribute_val);
}

void mpi_comm_set_name_(int *comm, char comm_name, int *ret);
#pragma weak mpi_comm_set_name_ = pmpi_comm_set_name_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Comm_set_name(int *comm, char comm_name, int *ret);

void INTERF_2_INTEL_MPI_Comm_set_name(int *comm, char comm_name, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Comm_set_name)(        \
    int *comm, char comm_name, int *ret);                                      \
    void pmpi_comm_set_name_(int *comm, char comm_name, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Comm_set_name(comm, comm_name); }

void mpi_file_call_errhandler_(int *fh, int *errorcode, int *ret);
#pragma weak mpi_file_call_errhandler_ = pmpi_file_call_errhandler_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_call_errhandler(int *fh, int *errorcode, int *ret);

void INTERF_2_INTEL_MPI_File_call_errhandler(int *fh, int *errorcode, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_call_errhandler)( \
    int *fh, int *errorcode, int *ret);                                        \
    void pmpi_file_call_errhandler_(int *fh, int *errorcode, int *ret);
{ return INTERFACE_F_LOCAL_MPI_File_call_errhandler(fh, errorcode); }

void mpi_grequest_complete_(int *request, int *ret);
#pragma weak mpi_grequest_complete_ = pmpi_grequest_complete_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Grequest_complete(int *request, int *ret);

void INTERF_2_INTEL_MPI_Grequest_complete(int *request, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Grequest_complete)(    \
    int *request, int *ret);                                                   \
    void pmpi_grequest_complete_(int *request, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Grequest_complete(request); }

void mpi_grequest_start_(void *query_fn, void *free_fn, void *cancel_fn,
                         void *extra_state, int *request, int *ret);
#pragma weak mpi_grequest_start_ = pmpi_grequest_start_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Grequest_start(void *query_fn, void *free_fn,
                                      void *cancel_fn, void *extra_state,
                                      int *request, int *ret);

void INTERF_2_INTEL_MPI_Grequest_start(void *query_fn, void *free_fn,
                                       void *cancel_fn, void *extra_state,
                                       int *request, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Grequest_start)(       \
    void *query_fn, void *free_fn, void *cancel_fn, void *extra_state,         \
    int *request, int *ret);                                                   \
    void pmpi_grequest_start_(void *query_fn, void *free_fn, void *cancel_fn,  \
                              void *extra_state, int *request, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Grequest_start(query_fn, free_fn, cancel_fn,
                                              extra_state, request);
}

void mpi_is_thread_main_(int *flag, int *ret);
#pragma weak mpi_is_thread_main_ = pmpi_is_thread_main_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Is_thread_main(int *flag, int *ret);

void INTERF_2_INTEL_MPI_Is_thread_main(int *flag, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Is_thread_main)(       \
    int *flag, int *ret);                                                      \
    void pmpi_is_thread_main_(int *flag, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Is_thread_main(flag); }

void mpi_query_thread_(int *provided, int *ret);
#pragma weak mpi_query_thread_ = pmpi_query_thread_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Query_thread(int *provided, int *ret);

void INTERF_2_INTEL_MPI_Query_thread(int *provided, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Query_thread)(         \
    int *provided, int *ret);                                                  \
    void pmpi_query_thread_(int *provided, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Query_thread(provided); }

void mpi_status_set_cancelled_(int *status, int *flag, int *ret);
#pragma weak mpi_status_set_cancelled_ = pmpi_status_set_cancelled_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Status_set_cancelled(int *status, int *flag, int *ret);

void INTERF_2_INTEL_MPI_Status_set_cancelled(int *status, int *flag, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Status_set_cancelled)( \
    int *status, int *flag, int *ret);                                         \
    void pmpi_status_set_cancelled_(int *status, int *flag, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Status_set_cancelled(status, flag); }

void mpi_status_set_elements_(int *status, int *datatype, int *count, int *ret);
#pragma weak mpi_status_set_elements_ = pmpi_status_set_elements_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Status_set_elements(int *status, int *datatype,
                                           int *count, int *ret);

void INTERF_2_INTEL_MPI_Status_set_elements(int *status, int *datatype,
                                            int *count, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Status_set_elements)(  \
    int *status, int *datatype, int *count, int *ret);                         \
    void pmpi_status_set_elements_(int *status, int *datatype, int *count,     \
                                   int *ret);
{ return INTERFACE_F_LOCAL_MPI_Status_set_elements(status, datatype, count); }

void mpi_type_create_keyval_(void *type_copy_attr_fn, void *type_delete_attr_fn,
                             int *type_keyval, void *extra_state, int *ret);
#pragma weak mpi_type_create_keyval_ = pmpi_type_create_keyval_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Type_create_keyval(void *type_copy_attr_fn,
                                          void *type_delete_attr_fn,
                                          int *type_keyval, void *extra_state,
                                          int *ret);

void INTERF_2_INTEL_MPI_Type_create_keyval(void *type_copy_attr_fn,
                                           void *type_delete_attr_fn,
                                           int *type_keyval, void *extra_state,
                                           int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Type_create_keyval)(   \
    void *type_copy_attr_fn, void *type_delete_attr_fn, int *type_keyval,      \
    void *extra_state, int *ret);                                              \
    void pmpi_type_create_keyval_(void *type_copy_attr_fn,                     \
                                  void *type_delete_attr_fn, int *type_keyval, \
                                  void *extra_state, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Type_create_keyval(
      type_copy_attr_fn, type_delete_attr_fn, type_keyval, extra_state);
}

void mpi_type_delete_attr_(int *datatype, int *type_keyval, int *ret);
#pragma weak mpi_type_delete_attr_ = pmpi_type_delete_attr_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Type_delete_attr(int *datatype, int *type_keyval,
                                        int *ret);

void INTERF_2_INTEL_MPI_Type_delete_attr(int *datatype, int *type_keyval,
                                         int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Type_delete_attr)(     \
    int *datatype, int *type_keyval, int *ret);                                \
    void pmpi_type_delete_attr_(int *datatype, int *type_keyval, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Type_delete_attr(datatype, type_keyval); }

void mpi_type_dup_(int *oldtype, int *newtype, int *ret);
#pragma weak mpi_type_dup_ = pmpi_type_dup_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Type_dup(int *oldtype, int *newtype, int *ret);

void INTERF_2_INTEL_MPI_Type_dup(int *oldtype, int *newtype, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Type_dup)(             \
    int *oldtype, int *newtype, int *ret);                                     \
    void pmpi_type_dup_(int *oldtype, int *newtype, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Type_dup(oldtype, newtype); }

void mpi_type_free_keyval_(int *type_keyval, int *ret);
#pragma weak mpi_type_free_keyval_ = pmpi_type_free_keyval_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Type_free_keyval(int *type_keyval, int *ret);

void INTERF_2_INTEL_MPI_Type_free_keyval(int *type_keyval, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Type_free_keyval)(     \
    int *type_keyval, int *ret);                                               \
    void pmpi_type_free_keyval_(int *type_keyval, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Type_free_keyval(type_keyval); }

void mpi_type_get_attr_(int *datatype, int *type_keyval, void *attribute_val,
                        int *flag, int *ret);
#pragma weak mpi_type_get_attr_ = pmpi_type_get_attr_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Type_get_attr(int *datatype, int *type_keyval,
                                     void *attribute_val, int *flag, int *ret);

void INTERF_2_INTEL_MPI_Type_get_attr(int *datatype, int *type_keyval,
                                      void *attribute_val, int *flag, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Type_get_attr)(        \
    int *datatype, int *type_keyval, void *attribute_val, int *flag,           \
    int *ret);                                                                 \
    void pmpi_type_get_attr_(int *datatype, int *type_keyval,                  \
                             void *attribute_val, int *flag, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Type_get_attr(datatype, type_keyval,
                                             attribute_val, flag);
}

void mpi_type_get_envelope_(int *datatype, int *num_integers,
                            int *num_addresses, int *num_datatypes,
                            int *combiner, int *ret);
#pragma weak mpi_type_get_envelope_ = pmpi_type_get_envelope_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Type_get_envelope(int *datatype, int *num_integers,
                                         int *num_addresses, int *num_datatypes,
                                         int *combiner, int *ret);

void INTERF_2_INTEL_MPI_Type_get_envelope(int *datatype, int *num_integers,
                                          int *num_addresses,
                                          int *num_datatypes, int *combiner,
                                          int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Type_get_envelope)(    \
    int *datatype, int *num_integers, int *num_addresses, int *num_datatypes,  \
    int *combiner, int *ret);                                                  \
    void pmpi_type_get_envelope_(int *datatype, int *num_integers,             \
                                 int *num_addresses, int *num_datatypes,       \
                                 int *combiner, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Type_get_envelope(
      datatype, num_integers, num_addresses, num_datatypes, combiner);
}

void mpi_type_get_name_(int *datatype, char type_name, int *resultlen,
                        int *ret);
#pragma weak mpi_type_get_name_ = pmpi_type_get_name_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Type_get_name(int *datatype, char type_name,
                                     int *resultlen, int *ret);

void INTERF_2_INTEL_MPI_Type_get_name(int *datatype, char type_name,
                                      int *resultlen, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Type_get_name)(        \
    int *datatype, char type_name, int *resultlen, int *ret);                  \
    void pmpi_type_get_name_(int *datatype, char type_name, int *resultlen,    \
                             int *ret);
{ return INTERFACE_F_LOCAL_MPI_Type_get_name(datatype, type_name, resultlen); }

void mpi_type_set_attr_(int *datatype, int *type_keyval, void *attribute_val,
                        int *ret);
#pragma weak mpi_type_set_attr_ = pmpi_type_set_attr_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Type_set_attr(int *datatype, int *type_keyval,
                                     void *attribute_val, int *ret);

void INTERF_2_INTEL_MPI_Type_set_attr(int *datatype, int *type_keyval,
                                      void *attribute_val, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Type_set_attr)(        \
    int *datatype, int *type_keyval, void *attribute_val, int *ret);           \
    void pmpi_type_set_attr_(int *datatype, int *type_keyval,                  \
                             void *attribute_val, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Type_set_attr(datatype, type_keyval,
                                             attribute_val);
}

void mpi_type_set_name_(int *datatype, char type_name, int *ret);
#pragma weak mpi_type_set_name_ = pmpi_type_set_name_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Type_set_name(int *datatype, char type_name, int *ret);

void INTERF_2_INTEL_MPI_Type_set_name(int *datatype, char type_name, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Type_set_name)(        \
    int *datatype, char type_name, int *ret);                                  \
    void pmpi_type_set_name_(int *datatype, char type_name, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Type_set_name(datatype, type_name); }

void mpi_type_match_size_(int *typeclass, int *size, int *datatype, int *ret);
#pragma weak mpi_type_match_size_ = pmpi_type_match_size_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Type_match_size(int *typeclass, int *size, int *datatype,
                                       int *ret);

void INTERF_2_INTEL_MPI_Type_match_size(int *typeclass, int *size,
                                        int *datatype, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Type_match_size)(      \
    int *typeclass, int *size, int *datatype, int *ret);                       \
    void pmpi_type_match_size_(int *typeclass, int *size, int *datatype,       \
                               int *ret);
{ return INTERFACE_F_LOCAL_MPI_Type_match_size(typeclass, size, datatype); }

void mpi_win_call_errhandler_(int *win, int *errorcode, int *ret);
#pragma weak mpi_win_call_errhandler_ = pmpi_win_call_errhandler_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Win_call_errhandler(int *win, int *errorcode, int *ret);

void INTERF_2_INTEL_MPI_Win_call_errhandler(int *win, int *errorcode, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Win_call_errhandler)(  \
    int *win, int *errorcode, int *ret);                                       \
    void pmpi_win_call_errhandler_(int *win, int *errorcode, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Win_call_errhandler(win, errorcode); }

void mpi_win_create_keyval_(void *win_copy_attr_fn, void *win_delete_attr_fn,
                            int *win_keyval, void *extra_state, int *ret);
#pragma weak mpi_win_create_keyval_ = pmpi_win_create_keyval_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Win_create_keyval(void *win_copy_attr_fn,
                                         void *win_delete_attr_fn,
                                         int *win_keyval, void *extra_state,
                                         int *ret);

void INTERF_2_INTEL_MPI_Win_create_keyval(void *win_copy_attr_fn,
                                          void *win_delete_attr_fn,
                                          int *win_keyval, void *extra_state,
                                          int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Win_create_keyval)(    \
    void *win_copy_attr_fn, void *win_delete_attr_fn, int *win_keyval,         \
    void *extra_state, int *ret);                                              \
    void pmpi_win_create_keyval_(void *win_copy_attr_fn,                       \
                                 void *win_delete_attr_fn, int *win_keyval,    \
                                 void *extra_state, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Win_create_keyval(
      win_copy_attr_fn, win_delete_attr_fn, win_keyval, extra_state);
}

void mpi_win_delete_attr_(int *win, int *win_keyval, int *ret);
#pragma weak mpi_win_delete_attr_ = pmpi_win_delete_attr_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Win_delete_attr(int *win, int *win_keyval, int *ret);

void INTERF_2_INTEL_MPI_Win_delete_attr(int *win, int *win_keyval, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Win_delete_attr)(      \
    int *win, int *win_keyval, int *ret);                                      \
    void pmpi_win_delete_attr_(int *win, int *win_keyval, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Win_delete_attr(win, win_keyval); }

void mpi_win_free_keyval_(int *win_keyval, int *ret);
#pragma weak mpi_win_free_keyval_ = pmpi_win_free_keyval_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Win_free_keyval(int *win_keyval, int *ret);

void INTERF_2_INTEL_MPI_Win_free_keyval(int *win_keyval, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Win_free_keyval)(      \
    int *win_keyval, int *ret);                                                \
    void pmpi_win_free_keyval_(int *win_keyval, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Win_free_keyval(win_keyval); }

void mpi_win_get_attr_(int *win, int *win_keyval, void *attribute_val,
                       int *flag, int *ret);
#pragma weak mpi_win_get_attr_ = pmpi_win_get_attr_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Win_get_attr(int *win, int *win_keyval,
                                    void *attribute_val, int *flag, int *ret);

void INTERF_2_INTEL_MPI_Win_get_attr(int *win, int *win_keyval,
                                     void *attribute_val, int *flag, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Win_get_attr)(         \
    int *win, int *win_keyval, void *attribute_val, int *flag, int *ret);      \
    void pmpi_win_get_attr_(int *win, int *win_keyval, void *attribute_val,    \
                            int *flag, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Win_get_attr(win, win_keyval, attribute_val,
                                            flag);
}

void mpi_win_get_name_(int *win, char win_name, int *resultlen, int *ret);
#pragma weak mpi_win_get_name_ = pmpi_win_get_name_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Win_get_name(int *win, char win_name, int *resultlen,
                                    int *ret);

void INTERF_2_INTEL_MPI_Win_get_name(int *win, char win_name, int *resultlen,
                                     int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Win_get_name)(         \
    int *win, char win_name, int *resultlen, int *ret);                        \
    void pmpi_win_get_name_(int *win, char win_name, int *resultlen,           \
                            int *ret);
{ return INTERFACE_F_LOCAL_MPI_Win_get_name(win, win_name, resultlen); }

void mpi_win_set_attr_(int *win, int *win_keyval, void *attribute_val,
                       int *ret);
#pragma weak mpi_win_set_attr_ = pmpi_win_set_attr_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Win_set_attr(int *win, int *win_keyval,
                                    void *attribute_val, int *ret);

void INTERF_2_INTEL_MPI_Win_set_attr(int *win, int *win_keyval,
                                     void *attribute_val, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Win_set_attr)(         \
    int *win, int *win_keyval, void *attribute_val, int *ret);                 \
    void pmpi_win_set_attr_(int *win, int *win_keyval, void *attribute_val,    \
                            int *ret);
{ return INTERFACE_F_LOCAL_MPI_Win_set_attr(win, win_keyval, attribute_val); }

void mpi_win_set_name_(int *win, char win_name, int *ret);
#pragma weak mpi_win_set_name_ = pmpi_win_set_name_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Win_set_name(int *win, char win_name, int *ret);

void INTERF_2_INTEL_MPI_Win_set_name(int *win, char win_name, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Win_set_name)(         \
    int *win, char win_name, int *ret);                                        \
    void pmpi_win_set_name_(int *win, char win_name, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Win_set_name(win, win_name); }

void mpi_alloc_mem_(size_t size, int *info, void *baseptr, int *ret);
#pragma weak mpi_alloc_mem_ = pmpi_alloc_mem_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Alloc_mem(size_t size, int *info, void *baseptr,
                                 int *ret);

void INTERF_2_INTEL_MPI_Alloc_mem(size_t size, int *info, void *baseptr,
                                  int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Alloc_mem)(            \
    size_t size, int *info, void *baseptr, int *ret);                          \
    void pmpi_alloc_mem_(size_t size, int *info, void *baseptr, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Alloc_mem(size, info, baseptr); }

void mpi_comm_create_errhandler_(void *comm_errhandler_fn, int *errhandler,
                                 int *ret);
#pragma weak mpi_comm_create_errhandler_ = pmpi_comm_create_errhandler_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Comm_create_errhandler(void *comm_errhandler_fn,
                                              int *errhandler, int *ret);

void INTERF_2_INTEL_MPI_Comm_create_errhandler(void *comm_errhandler_fn,
                                               int *errhandler, int *ret);

#endif /* WI4MPI_STATIC */ void (                                              \
    *INTERFACE_F_LOCAL_MPI_Comm_create_errhandler)(void *comm_errhandler_fn,   \
                                                   int *errhandler, int *ret); \
    void pmpi_comm_create_errhandler_(void *comm_errhandler_fn,                \
                                      int *errhandler, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Comm_create_errhandler(comm_errhandler_fn,
                                                      errhandler);
}

void mpi_comm_get_errhandler_(int *comm, int *errhandler, int *ret);
#pragma weak mpi_comm_get_errhandler_ = pmpi_comm_get_errhandler_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Comm_get_errhandler(int *comm, int *errhandler,
                                           int *ret);

void INTERF_2_INTEL_MPI_Comm_get_errhandler(int *comm, int *errhandler,
                                            int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Comm_get_errhandler)(  \
    int *comm, int *errhandler, int *ret);                                     \
    void pmpi_comm_get_errhandler_(int *comm, int *errhandler, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Comm_get_errhandler(comm, errhandler); }

void mpi_comm_set_errhandler_(int *comm, int *errhandler, int *ret);
#pragma weak mpi_comm_set_errhandler_ = pmpi_comm_set_errhandler_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Comm_set_errhandler(int *comm, int *errhandler,
                                           int *ret);

void INTERF_2_INTEL_MPI_Comm_set_errhandler(int *comm, int *errhandler,
                                            int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Comm_set_errhandler)(  \
    int *comm, int *errhandler, int *ret);                                     \
    void pmpi_comm_set_errhandler_(int *comm, int *errhandler, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Comm_set_errhandler(comm, errhandler); }

void mpi_file_get_errhandler_(int *file, int *errhandler, int *ret);
#pragma weak mpi_file_get_errhandler_ = pmpi_file_get_errhandler_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_get_errhandler(int *file, int *errhandler,
                                           int *ret);

void INTERF_2_INTEL_MPI_File_get_errhandler(int *file, int *errhandler,
                                            int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_get_errhandler)(  \
    int *file, int *errhandler, int *ret);                                     \
    void pmpi_file_get_errhandler_(int *file, int *errhandler, int *ret);
{ return INTERFACE_F_LOCAL_MPI_File_get_errhandler(file, errhandler); }

void mpi_file_set_errhandler_(int *file, int *errhandler, int *ret);
#pragma weak mpi_file_set_errhandler_ = pmpi_file_set_errhandler_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_set_errhandler(int *file, int *errhandler,
                                           int *ret);

void INTERF_2_INTEL_MPI_File_set_errhandler(int *file, int *errhandler,
                                            int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_set_errhandler)(  \
    int *file, int *errhandler, int *ret);                                     \
    void pmpi_file_set_errhandler_(int *file, int *errhandler, int *ret);
{ return INTERFACE_F_LOCAL_MPI_File_set_errhandler(file, errhandler); }

void mpi_finalized_(int *flag, int *ret);
#pragma weak mpi_finalized_ = pmpi_finalized_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Finalized(int *flag, int *ret);

void INTERF_2_INTEL_MPI_Finalized(int *flag, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Finalized)(int *flag,  \
                                                                   int *ret);  \
    void pmpi_finalized_(int *flag, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Finalized(flag); }

void mpi_free_mem_(void *base, int *ret);
#pragma weak mpi_free_mem_ = pmpi_free_mem_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Free_mem(void *base, int *ret);

void INTERF_2_INTEL_MPI_Free_mem(void *base, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Free_mem)(void *base,  \
                                                                  int *ret);   \
    void pmpi_free_mem_(void *base, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Free_mem(base); }

void mpi_get_address_(void *location, size_t address, int *ret);
#pragma weak mpi_get_address_ = pmpi_get_address_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Get_address(void *location, size_t address, int *ret);

void INTERF_2_INTEL_MPI_Get_address(void *location, size_t address, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Get_address)(          \
    void *location, size_t address, int *ret);                                 \
    void pmpi_get_address_(void *location, size_t address, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Get_address(location, address); }

void mpi_info_create_(int *info, int *ret);
#pragma weak mpi_info_create_ = pmpi_info_create_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Info_create(int *info, int *ret);

void INTERF_2_INTEL_MPI_Info_create(int *info, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Info_create)(          \
    int *info, int *ret);                                                      \
    void pmpi_info_create_(int *info, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Info_create(info); }

void mpi_info_delete_(int *info, char key, int *ret);
#pragma weak mpi_info_delete_ = pmpi_info_delete_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Info_delete(int *info, char key, int *ret);

void INTERF_2_INTEL_MPI_Info_delete(int *info, char key, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Info_delete)(          \
    int *info, char key, int *ret);                                            \
    void pmpi_info_delete_(int *info, char key, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Info_delete(info, key); }

void mpi_info_dup_(int *info, int *newinfo, int *ret);
#pragma weak mpi_info_dup_ = pmpi_info_dup_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Info_dup(int *info, int *newinfo, int *ret);

void INTERF_2_INTEL_MPI_Info_dup(int *info, int *newinfo, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Info_dup)(             \
    int *info, int *newinfo, int *ret);                                        \
    void pmpi_info_dup_(int *info, int *newinfo, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Info_dup(info, newinfo); }

void mpi_info_free_(int *info, int *ret);
#pragma weak mpi_info_free_ = pmpi_info_free_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Info_free(int *info, int *ret);

void INTERF_2_INTEL_MPI_Info_free(int *info, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Info_free)(int *info,  \
                                                                   int *ret);  \
    void pmpi_info_free_(int *info, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Info_free(info); }

void mpi_info_get_(int *info, char key, int *valuelen, char value, int *flag,
                   int *ret);
#pragma weak mpi_info_get_ = pmpi_info_get_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Info_get(int *info, char key, int *valuelen, char value,
                                int *flag, int *ret);

void INTERF_2_INTEL_MPI_Info_get(int *info, char key, int *valuelen, char value,
                                 int *flag, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Info_get)(             \
    int *info, char key, int *valuelen, char value, int *flag, int *ret);      \
    void pmpi_info_get_(int *info, char key, int *valuelen, char value,        \
                        int *flag, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Info_get(info, key, valuelen, value, flag); }

void mpi_info_get_nkeys_(int *info, int *nkeys, int *ret);
#pragma weak mpi_info_get_nkeys_ = pmpi_info_get_nkeys_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Info_get_nkeys(int *info, int *nkeys, int *ret);

void INTERF_2_INTEL_MPI_Info_get_nkeys(int *info, int *nkeys, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Info_get_nkeys)(       \
    int *info, int *nkeys, int *ret);                                          \
    void pmpi_info_get_nkeys_(int *info, int *nkeys, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Info_get_nkeys(info, nkeys); }

void mpi_info_get_nthkey_(int *info, int *n, char key, int *ret);
#pragma weak mpi_info_get_nthkey_ = pmpi_info_get_nthkey_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Info_get_nthkey(int *info, int *n, char key, int *ret);

void INTERF_2_INTEL_MPI_Info_get_nthkey(int *info, int *n, char key, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Info_get_nthkey)(      \
    int *info, int *n, char key, int *ret);                                    \
    void pmpi_info_get_nthkey_(int *info, int *n, char key, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Info_get_nthkey(info, n, key); }

void mpi_info_get_valuelen_(int *info, char key, int *valuelen, int *flag,
                            int *ret);
#pragma weak mpi_info_get_valuelen_ = pmpi_info_get_valuelen_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Info_get_valuelen(int *info, char key, int *valuelen,
                                         int *flag, int *ret);

void INTERF_2_INTEL_MPI_Info_get_valuelen(int *info, char key, int *valuelen,
                                          int *flag, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Info_get_valuelen)(    \
    int *info, char key, int *valuelen, int *flag, int *ret);                  \
    void pmpi_info_get_valuelen_(int *info, char key, int *valuelen,           \
                                 int *flag, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Info_get_valuelen(info, key, valuelen, flag); }

void mpi_info_set_(int *info, char key, char value, int *ret);
#pragma weak mpi_info_set_ = pmpi_info_set_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Info_set(int *info, char key, char value, int *ret);

void INTERF_2_INTEL_MPI_Info_set(int *info, char key, char value, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Info_set)(             \
    int *info, char key, char value, int *ret);                                \
    void pmpi_info_set_(int *info, char key, char value, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Info_set(info, key, value); }

void mpi_request_get_status_(int *request, int *flag, int *status, int *ret);
#pragma weak mpi_request_get_status_ = pmpi_request_get_status_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Request_get_status(int *request, int *flag, int *status,
                                          int *ret);

void INTERF_2_INTEL_MPI_Request_get_status(int *request, int *flag, int *status,
                                           int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Request_get_status)(   \
    int *request, int *flag, int *status, int *ret);                           \
    void pmpi_request_get_status_(int *request, int *flag, int *status,        \
                                  int *ret);
{ return INTERFACE_F_LOCAL_MPI_Request_get_status(request, flag, status); }

void mpi_type_create_hvector_(int *count, int *blocklength, size_t stride,
                              int *oldtype, int *newtype, int *ret);
#pragma weak mpi_type_create_hvector_ = pmpi_type_create_hvector_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Type_create_hvector(int *count, int *blocklength,
                                           size_t stride, int *oldtype,
                                           int *newtype, int *ret);

void INTERF_2_INTEL_MPI_Type_create_hvector(int *count, int *blocklength,
                                            size_t stride, int *oldtype,
                                            int *newtype, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Type_create_hvector)(  \
    int *count, int *blocklength, size_t stride, int *oldtype, int *newtype,   \
    int *ret);                                                                 \
    void pmpi_type_create_hvector_(int *count, int *blocklength,               \
                                   size_t stride, int *oldtype, int *newtype,  \
                                   int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Type_create_hvector(count, blocklength, stride,
                                                   oldtype, newtype);
}

void mpi_type_create_resized_(int *oldtype, size_t lb, size_t extent,
                              int *newtype, int *ret);
#pragma weak mpi_type_create_resized_ = pmpi_type_create_resized_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Type_create_resized(int *oldtype, size_t lb,
                                           size_t extent, int *newtype,
                                           int *ret);

void INTERF_2_INTEL_MPI_Type_create_resized(int *oldtype, size_t lb,
                                            size_t extent, int *newtype,
                                            int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Type_create_resized)(  \
    int *oldtype, size_t lb, size_t extent, int *newtype, int *ret);           \
    void pmpi_type_create_resized_(int *oldtype, size_t lb, size_t extent,     \
                                   int *newtype, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Type_create_resized(oldtype, lb, extent,
                                                   newtype);
}

void mpi_type_get_extent_(int *datatype, size_t lb, size_t extent, int *ret);
#pragma weak mpi_type_get_extent_ = pmpi_type_get_extent_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Type_get_extent(int *datatype, size_t lb, size_t extent,
                                       int *ret);

void INTERF_2_INTEL_MPI_Type_get_extent(int *datatype, size_t lb, size_t extent,
                                        int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Type_get_extent)(      \
    int *datatype, size_t lb, size_t extent, int *ret);                        \
    void pmpi_type_get_extent_(int *datatype, size_t lb, size_t extent,        \
                               int *ret);
{ return INTERFACE_F_LOCAL_MPI_Type_get_extent(datatype, lb, extent); }

void mpi_type_get_true_extent_(int *datatype, size_t true_lb,
                               size_t true_extent, int *ret);
#pragma weak mpi_type_get_true_extent_ = pmpi_type_get_true_extent_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Type_get_true_extent(int *datatype, size_t true_lb,
                                            size_t true_extent, int *ret);

void INTERF_2_INTEL_MPI_Type_get_true_extent(int *datatype, size_t true_lb,
                                             size_t true_extent, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Type_get_true_extent)( \
    int *datatype, size_t true_lb, size_t true_extent, int *ret);              \
    void pmpi_type_get_true_extent_(int *datatype, size_t true_lb,             \
                                    size_t true_extent, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Type_get_true_extent(datatype, true_lb,
                                                    true_extent);
}

void mpi_win_create_errhandler_(void *win_errhandler_fn, int *errhandler,
                                int *ret);
#pragma weak mpi_win_create_errhandler_ = pmpi_win_create_errhandler_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Win_create_errhandler(void *win_errhandler_fn,
                                             int *errhandler, int *ret);

void INTERF_2_INTEL_MPI_Win_create_errhandler(void *win_errhandler_fn,
                                              int *errhandler, int *ret);

#endif /* WI4MPI_STATIC */ void (                                              \
    *INTERFACE_F_LOCAL_MPI_Win_create_errhandler)(void *win_errhandler_fn,     \
                                                  int *errhandler, int *ret);  \
    void pmpi_win_create_errhandler_(void *win_errhandler_fn, int *errhandler, \
                                     int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Win_create_errhandler(win_errhandler_fn,
                                                     errhandler);
}

void mpi_win_get_errhandler_(int *win, int *errhandler, int *ret);
#pragma weak mpi_win_get_errhandler_ = pmpi_win_get_errhandler_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Win_get_errhandler(int *win, int *errhandler, int *ret);

void INTERF_2_INTEL_MPI_Win_get_errhandler(int *win, int *errhandler, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Win_get_errhandler)(   \
    int *win, int *errhandler, int *ret);                                      \
    void pmpi_win_get_errhandler_(int *win, int *errhandler, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Win_get_errhandler(win, errhandler); }

void mpi_win_set_errhandler_(int *win, int *errhandler, int *ret);
#pragma weak mpi_win_set_errhandler_ = pmpi_win_set_errhandler_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Win_set_errhandler(int *win, int *errhandler, int *ret);

void INTERF_2_INTEL_MPI_Win_set_errhandler(int *win, int *errhandler, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Win_set_errhandler)(   \
    int *win, int *errhandler, int *ret);                                      \
    void pmpi_win_set_errhandler_(int *win, int *errhandler, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Win_set_errhandler(win, errhandler); }

void mpi_type_create_f90_integer_(int *range, int *newtype, int *ret);
#pragma weak mpi_type_create_f90_integer_ = pmpi_type_create_f90_integer_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Type_create_f90_integer(int *range, int *newtype,
                                               int *ret);

void INTERF_2_INTEL_MPI_Type_create_f90_integer(int *range, int *newtype,
                                                int *ret);

#endif /* WI4MPI_STATIC */ void (                                              \
    *INTERFACE_F_LOCAL_MPI_Type_create_f90_integer)(int *range, int *newtype,  \
                                                    int *ret);                 \
    void pmpi_type_create_f90_integer_(int *range, int *newtype, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Type_create_f90_integer(range, newtype); }

void mpi_type_create_f90_real_(int *precision, int *range, int *newtype,
                               int *ret);
#pragma weak mpi_type_create_f90_real_ = pmpi_type_create_f90_real_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Type_create_f90_real(int *precision, int *range,
                                            int *newtype, int *ret);

void INTERF_2_INTEL_MPI_Type_create_f90_real(int *precision, int *range,
                                             int *newtype, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Type_create_f90_real)( \
    int *precision, int *range, int *newtype, int *ret);                       \
    void pmpi_type_create_f90_real_(int *precision, int *range, int *newtype,  \
                                    int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Type_create_f90_real(precision, range, newtype);
}

void mpi_type_create_f90_complex_(int *precision, int *range, int *newtype,
                                  int *ret);
#pragma weak mpi_type_create_f90_complex_ = pmpi_type_create_f90_complex_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Type_create_f90_complex(int *precision, int *range,
                                               int *newtype, int *ret);

void INTERF_2_INTEL_MPI_Type_create_f90_complex(int *precision, int *range,
                                                int *newtype, int *ret);

#endif /* WI4MPI_STATIC */ void (                                              \
    *INTERFACE_F_LOCAL_MPI_Type_create_f90_complex)(                           \
    int *precision, int *range, int *newtype, int *ret);                       \
    void pmpi_type_create_f90_complex_(int *precision, int *range,             \
                                       int *newtype, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Type_create_f90_complex(precision, range,
                                                       newtype);
}

void mpi_reduce_local_(void *inbuf, void *inoutbuf, int *count, int *datatype,
                       int *op, int *ret);
#pragma weak mpi_reduce_local_ = pmpi_reduce_local_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Reduce_local(void *inbuf, void *inoutbuf, int *count,
                                    int *datatype, int *op, int *ret);

void INTERF_2_INTEL_MPI_Reduce_local(void *inbuf, void *inoutbuf, int *count,
                                     int *datatype, int *op, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Reduce_local)(         \
    void *inbuf, void *inoutbuf, int *count, int *datatype, int *op,           \
    int *ret);                                                                 \
    void pmpi_reduce_local_(void *inbuf, void *inoutbuf, int *count,           \
                            int *datatype, int *op, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Reduce_local(inbuf, inoutbuf, count, datatype,
                                            op);
}

void mpi_op_commutative_(int *op, int *commute, int *ret);
#pragma weak mpi_op_commutative_ = pmpi_op_commutative_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Op_commutative(int *op, int *commute, int *ret);

void INTERF_2_INTEL_MPI_Op_commutative(int *op, int *commute, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Op_commutative)(       \
    int *op, int *commute, int *ret);                                          \
    void pmpi_op_commutative_(int *op, int *commute, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Op_commutative(op, commute); }

void mpi_reduce_scatter_block_(void *sendbuf, void *recvbuf, int *recvcount,
                               int *datatype, int *op, int *comm, int *ret);
#pragma weak mpi_reduce_scatter_block_ = pmpi_reduce_scatter_block_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Reduce_scatter_block(void *sendbuf, void *recvbuf,
                                            int *recvcount, int *datatype,
                                            int *op, int *comm, int *ret);

void INTERF_2_INTEL_MPI_Reduce_scatter_block(void *sendbuf, void *recvbuf,
                                             int *recvcount, int *datatype,
                                             int *op, int *comm, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Reduce_scatter_block)( \
    void *sendbuf, void *recvbuf, int *recvcount, int *datatype, int *op,      \
    int *comm, int *ret);                                                      \
    void pmpi_reduce_scatter_block_(void *sendbuf, void *recvbuf,              \
                                    int *recvcount, int *datatype, int *op,    \
                                    int *comm, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Reduce_scatter_block(sendbuf, recvbuf, recvcount,
                                                    datatype, op, comm);
}

void mpi_dist_graph_neighbors_count_(int *comm, int *indegree, int *outdegree,
                                     int *weighted, int *ret);
#pragma weak mpi_dist_graph_neighbors_count_ = pmpi_dist_graph_neighbors_count_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Dist_graph_neighbors_count(int *comm, int *indegree,
                                                  int *outdegree, int *weighted,
                                                  int *ret);

void INTERF_2_INTEL_MPI_Dist_graph_neighbors_count(int *comm, int *indegree,
                                                   int *outdegree,
                                                   int *weighted, int *ret);

#endif /* WI4MPI_STATIC */ void (                                              \
    *INTERFACE_F_LOCAL_MPI_Dist_graph_neighbors_count)(                        \
    int *comm, int *indegree, int *outdegree, int *weighted, int *ret);        \
    void pmpi_dist_graph_neighbors_count_(                                     \
        int *comm, int *indegree, int *outdegree, int *weighted, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Dist_graph_neighbors_count(comm, indegree,
                                                          outdegree, weighted);
}

void mpi_improbe_(int *source, int *tag, int *comm, int *flag, int *message,
                  int *status, int *ret);
#pragma weak mpi_improbe_ = pmpi_improbe_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Improbe(int *source, int *tag, int *comm, int *flag,
                               int *message, int *status, int *ret);

void INTERF_2_INTEL_MPI_Improbe(int *source, int *tag, int *comm, int *flag,
                                int *message, int *status, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Improbe)(              \
    int *source, int *tag, int *comm, int *flag, int *message, int *status,    \
    int *ret);                                                                 \
    void pmpi_improbe_(int *source, int *tag, int *comm, int *flag,            \
                       int *message, int *status, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Improbe(source, tag, comm, flag, message,
                                       status);
}

void mpi_imrecv_(void *buf, int *count, int *datatype, int *message,
                 int *request, int *ret);
#pragma weak mpi_imrecv_ = pmpi_imrecv_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Imrecv(void *buf, int *count, int *datatype,
                              int *message, int *request, int *ret);

void INTERF_2_INTEL_MPI_Imrecv(void *buf, int *count, int *datatype,
                               int *message, int *request, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Imrecv)(               \
    void *buf, int *count, int *datatype, int *message, int *request,          \
    int *ret);                                                                 \
    void pmpi_imrecv_(void *buf, int *count, int *datatype, int *message,      \
                      int *request, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Imrecv(buf, count, datatype, message, request); }

void mpi_mprobe_(int *source, int *tag, int *comm, int *message, int *status,
                 int *ret);
#pragma weak mpi_mprobe_ = pmpi_mprobe_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Mprobe(int *source, int *tag, int *comm, int *message,
                              int *status, int *ret);

void INTERF_2_INTEL_MPI_Mprobe(int *source, int *tag, int *comm, int *message,
                               int *status, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Mprobe)(               \
    int *source, int *tag, int *comm, int *message, int *status, int *ret);    \
    void pmpi_mprobe_(int *source, int *tag, int *comm, int *message,          \
                      int *status, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Mprobe(source, tag, comm, message, status); }

void mpi_mrecv_(void *buf, int *count, int *datatype, int *message, int *status,
                int *ret);
#pragma weak mpi_mrecv_ = pmpi_mrecv_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Mrecv(void *buf, int *count, int *datatype, int *message,
                             int *status, int *ret);

void INTERF_2_INTEL_MPI_Mrecv(void *buf, int *count, int *datatype,
                              int *message, int *status, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Mrecv)(                \
    void *buf, int *count, int *datatype, int *message, int *status,           \
    int *ret);                                                                 \
    void pmpi_mrecv_(void *buf, int *count, int *datatype, int *message,       \
                     int *status, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Mrecv(buf, count, datatype, message, status); }

void mpi_comm_idup_(int *comm, int *newcomm, int *request, int *ret);
#pragma weak mpi_comm_idup_ = pmpi_comm_idup_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Comm_idup(int *comm, int *newcomm, int *request,
                                 int *ret);

void INTERF_2_INTEL_MPI_Comm_idup(int *comm, int *newcomm, int *request,
                                  int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Comm_idup)(            \
    int *comm, int *newcomm, int *request, int *ret);                          \
    void pmpi_comm_idup_(int *comm, int *newcomm, int *request, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Comm_idup(comm, newcomm, request); }

void mpi_ibarrier_(int *comm, int *request, int *ret);
#pragma weak mpi_ibarrier_ = pmpi_ibarrier_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Ibarrier(int *comm, int *request, int *ret);

void INTERF_2_INTEL_MPI_Ibarrier(int *comm, int *request, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Ibarrier)(             \
    int *comm, int *request, int *ret);                                        \
    void pmpi_ibarrier_(int *comm, int *request, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Ibarrier(comm, request); }

void mpi_ibcast_(void *buffer, int *count, int *datatype, int *root, int *comm,
                 int *request, int *ret);
#pragma weak mpi_ibcast_ = pmpi_ibcast_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Ibcast(void *buffer, int *count, int *datatype,
                              int *root, int *comm, int *request, int *ret);

void INTERF_2_INTEL_MPI_Ibcast(void *buffer, int *count, int *datatype,
                               int *root, int *comm, int *request, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Ibcast)(               \
    void *buffer, int *count, int *datatype, int *root, int *comm,             \
    int *request, int *ret);                                                   \
    void pmpi_ibcast_(void *buffer, int *count, int *datatype, int *root,      \
                      int *comm, int *request, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Ibcast(buffer, count, datatype, root, comm,
                                      request);
}

void mpi_igather_(void *sendbuf, int *sendcount, int *sendtype, void *recvbuf,
                  int *recvcount, int *recvtype, int *root, int *comm,
                  int *request, int *ret);
#pragma weak mpi_igather_ = pmpi_igather_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Igather(void *sendbuf, int *sendcount, int *sendtype,
                               void *recvbuf, int *recvcount, int *recvtype,
                               int *root, int *comm, int *request, int *ret);

void INTERF_2_INTEL_MPI_Igather(void *sendbuf, int *sendcount, int *sendtype,
                                void *recvbuf, int *recvcount, int *recvtype,
                                int *root, int *comm, int *request, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Igather)(              \
    void *sendbuf, int *sendcount, int *sendtype, void *recvbuf,               \
    int *recvcount, int *recvtype, int *root, int *comm, int *request,         \
    int *ret);                                                                 \
    void pmpi_igather_(void *sendbuf, int *sendcount, int *sendtype,           \
                       void *recvbuf, int *recvcount, int *recvtype,           \
                       int *root, int *comm, int *request, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Igather(sendbuf, sendcount, sendtype, recvbuf,
                                       recvcount, recvtype, root, comm,
                                       request);
}

void mpi_iscatter_(void *sendbuf, int *sendcount, int *sendtype, void *recvbuf,
                   int *recvcount, int *recvtype, int *root, int *comm,
                   int *request, int *ret);
#pragma weak mpi_iscatter_ = pmpi_iscatter_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Iscatter(void *sendbuf, int *sendcount, int *sendtype,
                                void *recvbuf, int *recvcount, int *recvtype,
                                int *root, int *comm, int *request, int *ret);

void INTERF_2_INTEL_MPI_Iscatter(void *sendbuf, int *sendcount, int *sendtype,
                                 void *recvbuf, int *recvcount, int *recvtype,
                                 int *root, int *comm, int *request, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Iscatter)(             \
    void *sendbuf, int *sendcount, int *sendtype, void *recvbuf,               \
    int *recvcount, int *recvtype, int *root, int *comm, int *request,         \
    int *ret);                                                                 \
    void pmpi_iscatter_(void *sendbuf, int *sendcount, int *sendtype,          \
                        void *recvbuf, int *recvcount, int *recvtype,          \
                        int *root, int *comm, int *request, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Iscatter(sendbuf, sendcount, sendtype, recvbuf,
                                        recvcount, recvtype, root, comm,
                                        request);
}

void mpi_iallgather_(void *sendbuf, int *sendcount, int *sendtype,
                     void *recvbuf, int *recvcount, int *recvtype, int *comm,
                     int *request, int *ret);
#pragma weak mpi_iallgather_ = pmpi_iallgather_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Iallgather(void *sendbuf, int *sendcount, int *sendtype,
                                  void *recvbuf, int *recvcount, int *recvtype,
                                  int *comm, int *request, int *ret);

void INTERF_2_INTEL_MPI_Iallgather(void *sendbuf, int *sendcount, int *sendtype,
                                   void *recvbuf, int *recvcount, int *recvtype,
                                   int *comm, int *request, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Iallgather)(           \
    void *sendbuf, int *sendcount, int *sendtype, void *recvbuf,               \
    int *recvcount, int *recvtype, int *comm, int *request, int *ret);         \
    void pmpi_iallgather_(void *sendbuf, int *sendcount, int *sendtype,        \
                          void *recvbuf, int *recvcount, int *recvtype,        \
                          int *comm, int *request, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Iallgather(sendbuf, sendcount, sendtype, recvbuf,
                                          recvcount, recvtype, comm, request);
}

void mpi_ialltoall_(void *sendbuf, int *sendcount, int *sendtype, void *recvbuf,
                    int *recvcount, int *recvtype, int *comm, int *request,
                    int *ret);
#pragma weak mpi_ialltoall_ = pmpi_ialltoall_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Ialltoall(void *sendbuf, int *sendcount, int *sendtype,
                                 void *recvbuf, int *recvcount, int *recvtype,
                                 int *comm, int *request, int *ret);

void INTERF_2_INTEL_MPI_Ialltoall(void *sendbuf, int *sendcount, int *sendtype,
                                  void *recvbuf, int *recvcount, int *recvtype,
                                  int *comm, int *request, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Ialltoall)(            \
    void *sendbuf, int *sendcount, int *sendtype, void *recvbuf,               \
    int *recvcount, int *recvtype, int *comm, int *request, int *ret);         \
    void pmpi_ialltoall_(void *sendbuf, int *sendcount, int *sendtype,         \
                         void *recvbuf, int *recvcount, int *recvtype,         \
                         int *comm, int *request, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Ialltoall(sendbuf, sendcount, sendtype, recvbuf,
                                         recvcount, recvtype, comm, request);
}

void mpi_ireduce_(void *sendbuf, void *recvbuf, int *count, int *datatype,
                  int *op, int *root, int *comm, int *request, int *ret);
#pragma weak mpi_ireduce_ = pmpi_ireduce_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Ireduce(void *sendbuf, void *recvbuf, int *count,
                               int *datatype, int *op, int *root, int *comm,
                               int *request, int *ret);

void INTERF_2_INTEL_MPI_Ireduce(void *sendbuf, void *recvbuf, int *count,
                                int *datatype, int *op, int *root, int *comm,
                                int *request, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Ireduce)(              \
    void *sendbuf, void *recvbuf, int *count, int *datatype, int *op,          \
    int *root, int *comm, int *request, int *ret);                             \
    void pmpi_ireduce_(void *sendbuf, void *recvbuf, int *count,               \
                       int *datatype, int *op, int *root, int *comm,           \
                       int *request, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Ireduce(sendbuf, recvbuf, count, datatype, op,
                                       root, comm, request);
}

void mpi_iallreduce_(void *sendbuf, void *recvbuf, int *count, int *datatype,
                     int *op, int *comm, int *request, int *ret);
#pragma weak mpi_iallreduce_ = pmpi_iallreduce_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Iallreduce(void *sendbuf, void *recvbuf, int *count,
                                  int *datatype, int *op, int *comm,
                                  int *request, int *ret);

void INTERF_2_INTEL_MPI_Iallreduce(void *sendbuf, void *recvbuf, int *count,
                                   int *datatype, int *op, int *comm,
                                   int *request, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Iallreduce)(           \
    void *sendbuf, void *recvbuf, int *count, int *datatype, int *op,          \
    int *comm, int *request, int *ret);                                        \
    void pmpi_iallreduce_(void *sendbuf, void *recvbuf, int *count,            \
                          int *datatype, int *op, int *comm, int *request,     \
                          int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Iallreduce(sendbuf, recvbuf, count, datatype, op,
                                          comm, request);
}

void mpi_ireduce_scatter_block_(void *sendbuf, void *recvbuf, int *recvcount,
                                int *datatype, int *op, int *comm, int *request,
                                int *ret);
#pragma weak mpi_ireduce_scatter_block_ = pmpi_ireduce_scatter_block_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Ireduce_scatter_block(void *sendbuf, void *recvbuf,
                                             int *recvcount, int *datatype,
                                             int *op, int *comm, int *request,
                                             int *ret);

void INTERF_2_INTEL_MPI_Ireduce_scatter_block(void *sendbuf, void *recvbuf,
                                              int *recvcount, int *datatype,
                                              int *op, int *comm, int *request,
                                              int *ret);

#endif /* WI4MPI_STATIC */ void (                                              \
    *INTERFACE_F_LOCAL_MPI_Ireduce_scatter_block)(                             \
    void *sendbuf, void *recvbuf, int *recvcount, int *datatype, int *op,      \
    int *comm, int *request, int *ret);                                        \
    void pmpi_ireduce_scatter_block_(void *sendbuf, void *recvbuf,             \
                                     int *recvcount, int *datatype, int *op,   \
                                     int *comm, int *request, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Ireduce_scatter_block(
      sendbuf, recvbuf, recvcount, datatype, op, comm, request);
}

void mpi_iscan_(void *sendbuf, void *recvbuf, int *count, int *datatype,
                int *op, int *comm, int *request, int *ret);
#pragma weak mpi_iscan_ = pmpi_iscan_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Iscan(void *sendbuf, void *recvbuf, int *count,
                             int *datatype, int *op, int *comm, int *request,
                             int *ret);

void INTERF_2_INTEL_MPI_Iscan(void *sendbuf, void *recvbuf, int *count,
                              int *datatype, int *op, int *comm, int *request,
                              int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Iscan)(                \
    void *sendbuf, void *recvbuf, int *count, int *datatype, int *op,          \
    int *comm, int *request, int *ret);                                        \
    void pmpi_iscan_(void *sendbuf, void *recvbuf, int *count, int *datatype,  \
                     int *op, int *comm, int *request, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Iscan(sendbuf, recvbuf, count, datatype, op,
                                     comm, request);
}

void mpi_iexscan_(void *sendbuf, void *recvbuf, int *count, int *datatype,
                  int *op, int *comm, int *request, int *ret);
#pragma weak mpi_iexscan_ = pmpi_iexscan_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Iexscan(void *sendbuf, void *recvbuf, int *count,
                               int *datatype, int *op, int *comm, int *request,
                               int *ret);

void INTERF_2_INTEL_MPI_Iexscan(void *sendbuf, void *recvbuf, int *count,
                                int *datatype, int *op, int *comm, int *request,
                                int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Iexscan)(              \
    void *sendbuf, void *recvbuf, int *count, int *datatype, int *op,          \
    int *comm, int *request, int *ret);                                        \
    void pmpi_iexscan_(void *sendbuf, void *recvbuf, int *count,               \
                       int *datatype, int *op, int *comm, int *request,        \
                       int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Iexscan(sendbuf, recvbuf, count, datatype, op,
                                       comm, request);
}

void mpi_ineighbor_allgather_(void *sendbuf, int *sendcount, int *sendtype,
                              void *recvbuf, int *recvcount, int *recvtype,
                              int *comm, int *request, int *ret);
#pragma weak mpi_ineighbor_allgather_ = pmpi_ineighbor_allgather_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Ineighbor_allgather(void *sendbuf, int *sendcount,
                                           int *sendtype, void *recvbuf,
                                           int *recvcount, int *recvtype,
                                           int *comm, int *request, int *ret);

void INTERF_2_INTEL_MPI_Ineighbor_allgather(void *sendbuf, int *sendcount,
                                            int *sendtype, void *recvbuf,
                                            int *recvcount, int *recvtype,
                                            int *comm, int *request, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Ineighbor_allgather)(  \
    void *sendbuf, int *sendcount, int *sendtype, void *recvbuf,               \
    int *recvcount, int *recvtype, int *comm, int *request, int *ret);         \
    void pmpi_ineighbor_allgather_(                                            \
        void *sendbuf, int *sendcount, int *sendtype, void *recvbuf,           \
        int *recvcount, int *recvtype, int *comm, int *request, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Ineighbor_allgather(sendbuf, sendcount, sendtype,
                                                   recvbuf, recvcount, recvtype,
                                                   comm, request);
}

void mpi_ineighbor_alltoall_(void *sendbuf, int *sendcount, int *sendtype,
                             void *recvbuf, int *recvcount, int *recvtype,
                             int *comm, int *request, int *ret);
#pragma weak mpi_ineighbor_alltoall_ = pmpi_ineighbor_alltoall_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Ineighbor_alltoall(void *sendbuf, int *sendcount,
                                          int *sendtype, void *recvbuf,
                                          int *recvcount, int *recvtype,
                                          int *comm, int *request, int *ret);

void INTERF_2_INTEL_MPI_Ineighbor_alltoall(void *sendbuf, int *sendcount,
                                           int *sendtype, void *recvbuf,
                                           int *recvcount, int *recvtype,
                                           int *comm, int *request, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Ineighbor_alltoall)(   \
    void *sendbuf, int *sendcount, int *sendtype, void *recvbuf,               \
    int *recvcount, int *recvtype, int *comm, int *request, int *ret);         \
    void pmpi_ineighbor_alltoall_(                                             \
        void *sendbuf, int *sendcount, int *sendtype, void *recvbuf,           \
        int *recvcount, int *recvtype, int *comm, int *request, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Ineighbor_alltoall(sendbuf, sendcount, sendtype,
                                                  recvbuf, recvcount, recvtype,
                                                  comm, request);
}

void mpi_neighbor_allgather_(void *sendbuf, int *sendcount, int *sendtype,
                             void *recvbuf, int *recvcount, int *recvtype,
                             int *comm, int *ret);
#pragma weak mpi_neighbor_allgather_ = pmpi_neighbor_allgather_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Neighbor_allgather(void *sendbuf, int *sendcount,
                                          int *sendtype, void *recvbuf,
                                          int *recvcount, int *recvtype,
                                          int *comm, int *ret);

void INTERF_2_INTEL_MPI_Neighbor_allgather(void *sendbuf, int *sendcount,
                                           int *sendtype, void *recvbuf,
                                           int *recvcount, int *recvtype,
                                           int *comm, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Neighbor_allgather)(   \
    void *sendbuf, int *sendcount, int *sendtype, void *recvbuf,               \
    int *recvcount, int *recvtype, int *comm, int *ret);                       \
    void pmpi_neighbor_allgather_(                                             \
        void *sendbuf, int *sendcount, int *sendtype, void *recvbuf,           \
        int *recvcount, int *recvtype, int *comm, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Neighbor_allgather(
      sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm);
}

void mpi_neighbor_alltoall_(void *sendbuf, int *sendcount, int *sendtype,
                            void *recvbuf, int *recvcount, int *recvtype,
                            int *comm, int *ret);
#pragma weak mpi_neighbor_alltoall_ = pmpi_neighbor_alltoall_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Neighbor_alltoall(void *sendbuf, int *sendcount,
                                         int *sendtype, void *recvbuf,
                                         int *recvcount, int *recvtype,
                                         int *comm, int *ret);

void INTERF_2_INTEL_MPI_Neighbor_alltoall(void *sendbuf, int *sendcount,
                                          int *sendtype, void *recvbuf,
                                          int *recvcount, int *recvtype,
                                          int *comm, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Neighbor_alltoall)(    \
    void *sendbuf, int *sendcount, int *sendtype, void *recvbuf,               \
    int *recvcount, int *recvtype, int *comm, int *ret);                       \
    void pmpi_neighbor_alltoall_(void *sendbuf, int *sendcount, int *sendtype, \
                                 void *recvbuf, int *recvcount, int *recvtype, \
                                 int *comm, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Neighbor_alltoall(
      sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm);
}

void mpi_comm_split_type_(int *comm, int *split_type, int *key, int *info,
                          int *newcomm, int *ret);
#pragma weak mpi_comm_split_type_ = pmpi_comm_split_type_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Comm_split_type(int *comm, int *split_type, int *key,
                                       int *info, int *newcomm, int *ret);

void INTERF_2_INTEL_MPI_Comm_split_type(int *comm, int *split_type, int *key,
                                        int *info, int *newcomm, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Comm_split_type)(      \
    int *comm, int *split_type, int *key, int *info, int *newcomm, int *ret);  \
    void pmpi_comm_split_type_(int *comm, int *split_type, int *key,           \
                               int *info, int *newcomm, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Comm_split_type(comm, split_type, key, info,
                                               newcomm);
}

void mpi_get_elements_x_(int *status, int *datatype, int *count, int *ret);
#pragma weak mpi_get_elements_x_ = pmpi_get_elements_x_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Get_elements_x(int *status, int *datatype, int *count,
                                      int *ret);

void INTERF_2_INTEL_MPI_Get_elements_x(int *status, int *datatype, int *count,
                                       int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Get_elements_x)(       \
    int *status, int *datatype, int *count, int *ret);                         \
    void pmpi_get_elements_x_(int *status, int *datatype, int *count,          \
                              int *ret);
{ return INTERFACE_F_LOCAL_MPI_Get_elements_x(status, datatype, count); }

void mpi_status_set_elements_x_(int *status, int *datatype, int *count,
                                int *ret);
#pragma weak mpi_status_set_elements_x_ = pmpi_status_set_elements_x_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Status_set_elements_x(int *status, int *datatype,
                                             int *count, int *ret);

void INTERF_2_INTEL_MPI_Status_set_elements_x(int *status, int *datatype,
                                              int *count, int *ret);

#endif /* WI4MPI_STATIC */ void (                                              \
    *INTERFACE_F_LOCAL_MPI_Status_set_elements_x)(int *status, int *datatype,  \
                                                  int *count, int *ret);       \
    void pmpi_status_set_elements_x_(int *status, int *datatype, int *count,   \
                                     int *ret);
{ return INTERFACE_F_LOCAL_MPI_Status_set_elements_x(status, datatype, count); }

void mpi_type_get_extent_x_(int *datatype, int *lb, int *extent, int *ret);
#pragma weak mpi_type_get_extent_x_ = pmpi_type_get_extent_x_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Type_get_extent_x(int *datatype, int *lb, int *extent,
                                         int *ret);

void INTERF_2_INTEL_MPI_Type_get_extent_x(int *datatype, int *lb, int *extent,
                                          int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Type_get_extent_x)(    \
    int *datatype, int *lb, int *extent, int *ret);                            \
    void pmpi_type_get_extent_x_(int *datatype, int *lb, int *extent,          \
                                 int *ret);
{ return INTERFACE_F_LOCAL_MPI_Type_get_extent_x(datatype, lb, extent); }

void mpi_type_get_true_extent_x_(int *datatype, int *lb, int *extent, int *ret);
#pragma weak mpi_type_get_true_extent_x_ = pmpi_type_get_true_extent_x_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Type_get_true_extent_x(int *datatype, int *lb,
                                              int *extent, int *ret);

void INTERF_2_INTEL_MPI_Type_get_true_extent_x(int *datatype, int *lb,
                                               int *extent, int *ret);

#endif /* WI4MPI_STATIC */ void (                                              \
    *INTERFACE_F_LOCAL_MPI_Type_get_true_extent_x)(int *datatype, int *lb,     \
                                                   int *extent, int *ret);     \
    void pmpi_type_get_true_extent_x_(int *datatype, int *lb, int *extent,     \
                                      int *ret);
{ return INTERFACE_F_LOCAL_MPI_Type_get_true_extent_x(datatype, lb, extent); }

void mpi_type_size_x_(int *datatype, int *size, int *ret);
#pragma weak mpi_type_size_x_ = pmpi_type_size_x_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Type_size_x(int *datatype, int *size, int *ret);

void INTERF_2_INTEL_MPI_Type_size_x(int *datatype, int *size, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Type_size_x)(          \
    int *datatype, int *size, int *ret);                                       \
    void pmpi_type_size_x_(int *datatype, int *size, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Type_size_x(datatype, size); }

void mpi_comm_create_group_(int *comm, int *group, int *tag, int *newcomm,
                            int *ret);
#pragma weak mpi_comm_create_group_ = pmpi_comm_create_group_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Comm_create_group(int *comm, int *group, int *tag,
                                         int *newcomm, int *ret);

void INTERF_2_INTEL_MPI_Comm_create_group(int *comm, int *group, int *tag,
                                          int *newcomm, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Comm_create_group)(    \
    int *comm, int *group, int *tag, int *newcomm, int *ret);                  \
    void pmpi_comm_create_group_(int *comm, int *group, int *tag,              \
                                 int *newcomm, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Comm_create_group(comm, group, tag, newcomm); }

void pi_t_category_changed_(int *stamp, int *ret);
#pragma weak pi_t_category_changed_ = ppi_t_category_changed_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_PI_T_category_changed(int *stamp, int *ret);

void INTERF_2_INTEL_PI_T_category_changed(int *stamp, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_PI_T_category_changed)(    \
    int *stamp, int *ret);                                                     \
    void ppi_t_category_changed_(int *stamp, int *ret);
{ return INTERFACE_F_LOCAL_PI_T_category_changed(stamp); }

void mpi_file_open_(int *comm, char *filename, int *amode, int *info, int *fh,
                    int *ret);
#pragma weak mpi_file_open_ = pmpi_file_open_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_open(int *comm, char *filename, int *amode,
                                 int *info, int *fh, int *ret);

void INTERF_2_INTEL_MPI_File_open(int *comm, char *filename, int *amode,
                                  int *info, int *fh, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_open)(            \
    int *comm, char *filename, int *amode, int *info, int *fh, int *ret);      \
    void pmpi_file_open_(int *comm, char *filename, int *amode, int *info,     \
                         int *fh, int *ret);
{ return INTERFACE_F_LOCAL_MPI_File_open(comm, filename, amode, info, fh); }

void mpi_file_close_(int *fh, int *ret);
#pragma weak mpi_file_close_ = pmpi_file_close_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_close(int *fh, int *ret);

void INTERF_2_INTEL_MPI_File_close(int *fh, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_close)(int *fh,   \
                                                                    int *ret); \
    void pmpi_file_close_(int *fh, int *ret);
{ return INTERFACE_F_LOCAL_MPI_File_close(fh); }

void mpi_file_delete_(char *filename, int *info, int *ret);
#pragma weak mpi_file_delete_ = pmpi_file_delete_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_delete(char *filename, int *info, int *ret);

void INTERF_2_INTEL_MPI_File_delete(char *filename, int *info, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_delete)(          \
    char *filename, int *info, int *ret);                                      \
    void pmpi_file_delete_(char *filename, int *info, int *ret);
{ return INTERFACE_F_LOCAL_MPI_File_delete(filename, info); }

void mpi_file_set_size_(int *fh, int size, int *ret);
#pragma weak mpi_file_set_size_ = pmpi_file_set_size_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_set_size(int *fh, int size, int *ret);

void INTERF_2_INTEL_MPI_File_set_size(int *fh, int size, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_set_size)(        \
    int *fh, int size, int *ret);                                              \
    void pmpi_file_set_size_(int *fh, int size, int *ret);
{ return INTERFACE_F_LOCAL_MPI_File_set_size(fh, size); }

void mpi_file_preallocate_(int *fh, int size, int *ret);
#pragma weak mpi_file_preallocate_ = pmpi_file_preallocate_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_preallocate(int *fh, int size, int *ret);

void INTERF_2_INTEL_MPI_File_preallocate(int *fh, int size, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_preallocate)(     \
    int *fh, int size, int *ret);                                              \
    void pmpi_file_preallocate_(int *fh, int size, int *ret);
{ return INTERFACE_F_LOCAL_MPI_File_preallocate(fh, size); }

void mpi_file_get_size_(int *fh, int size, int *ret);
#pragma weak mpi_file_get_size_ = pmpi_file_get_size_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_get_size(int *fh, int size, int *ret);

void INTERF_2_INTEL_MPI_File_get_size(int *fh, int size, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_get_size)(        \
    int *fh, int size, int *ret);                                              \
    void pmpi_file_get_size_(int *fh, int size, int *ret);
{ return INTERFACE_F_LOCAL_MPI_File_get_size(fh, size); }

void mpi_file_get_group_(int *fh, int *group, int *ret);
#pragma weak mpi_file_get_group_ = pmpi_file_get_group_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_get_group(int *fh, int *group, int *ret);

void INTERF_2_INTEL_MPI_File_get_group(int *fh, int *group, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_get_group)(       \
    int *fh, int *group, int *ret);                                            \
    void pmpi_file_get_group_(int *fh, int *group, int *ret);
{ return INTERFACE_F_LOCAL_MPI_File_get_group(fh, group); }

void mpi_file_get_amode_(int *fh, int *amode, int *ret);
#pragma weak mpi_file_get_amode_ = pmpi_file_get_amode_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_get_amode(int *fh, int *amode, int *ret);

void INTERF_2_INTEL_MPI_File_get_amode(int *fh, int *amode, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_get_amode)(       \
    int *fh, int *amode, int *ret);                                            \
    void pmpi_file_get_amode_(int *fh, int *amode, int *ret);
{ return INTERFACE_F_LOCAL_MPI_File_get_amode(fh, amode); }

void mpi_file_set_info_(int *fh, int *info, int *ret);
#pragma weak mpi_file_set_info_ = pmpi_file_set_info_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_set_info(int *fh, int *info, int *ret);

void INTERF_2_INTEL_MPI_File_set_info(int *fh, int *info, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_set_info)(        \
    int *fh, int *info, int *ret);                                             \
    void pmpi_file_set_info_(int *fh, int *info, int *ret);
{ return INTERFACE_F_LOCAL_MPI_File_set_info(fh, info); }

void mpi_file_get_info_(int *fh, int *info_used, int *ret);
#pragma weak mpi_file_get_info_ = pmpi_file_get_info_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_get_info(int *fh, int *info_used, int *ret);

void INTERF_2_INTEL_MPI_File_get_info(int *fh, int *info_used, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_get_info)(        \
    int *fh, int *info_used, int *ret);                                        \
    void pmpi_file_get_info_(int *fh, int *info_used, int *ret);
{ return INTERFACE_F_LOCAL_MPI_File_get_info(fh, info_used); }

void mpi_file_set_view_(int *fh, int disp, int *etype, int *filetype,
                        char datarep, int *info, int *ret);
#pragma weak mpi_file_set_view_ = pmpi_file_set_view_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_set_view(int *fh, int disp, int *etype,
                                     int *filetype, char datarep, int *info,
                                     int *ret);

void INTERF_2_INTEL_MPI_File_set_view(int *fh, int disp, int *etype,
                                      int *filetype, char datarep, int *info,
                                      int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_set_view)(        \
    int *fh, int disp, int *etype, int *filetype, char datarep, int *info,     \
    int *ret);                                                                 \
    void pmpi_file_set_view_(int *fh, int disp, int *etype, int *filetype,     \
                             char datarep, int *info, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_File_set_view(fh, disp, etype, filetype, datarep,
                                             info);
}

void mpi_file_get_view_(int *fh, int disp, int *etype, int *filetype,
                        char datarep, int *ret);
#pragma weak mpi_file_get_view_ = pmpi_file_get_view_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_get_view(int *fh, int disp, int *etype,
                                     int *filetype, char datarep, int *ret);

void INTERF_2_INTEL_MPI_File_get_view(int *fh, int disp, int *etype,
                                      int *filetype, char datarep, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_get_view)(        \
    int *fh, int disp, int *etype, int *filetype, char datarep, int *ret);     \
    void pmpi_file_get_view_(int *fh, int disp, int *etype, int *filetype,     \
                             char datarep, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_File_get_view(fh, disp, etype, filetype,
                                             datarep);
}

void mpi_file_read_at_(int *fh, int offset, void *buf, int *count,
                       int *datatype, int *status, int *ret);
#pragma weak mpi_file_read_at_ = pmpi_file_read_at_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_read_at(int *fh, int offset, void *buf, int *count,
                                    int *datatype, int *status, int *ret);

void INTERF_2_INTEL_MPI_File_read_at(int *fh, int offset, void *buf, int *count,
                                     int *datatype, int *status, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_read_at)(         \
    int *fh, int offset, void *buf, int *count, int *datatype, int *status,    \
    int *ret);                                                                 \
    void pmpi_file_read_at_(int *fh, int offset, void *buf, int *count,        \
                            int *datatype, int *status, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_File_read_at(fh, offset, buf, count, datatype,
                                            status);
}

void mpi_file_read_at_all_(int *fh, int offset, void *buf, int *count,
                           int *datatype, int *status, int *ret);
#pragma weak mpi_file_read_at_all_ = pmpi_file_read_at_all_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_read_at_all(int *fh, int offset, void *buf,
                                        int *count, int *datatype, int *status,
                                        int *ret);

void INTERF_2_INTEL_MPI_File_read_at_all(int *fh, int offset, void *buf,
                                         int *count, int *datatype, int *status,
                                         int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_read_at_all)(     \
    int *fh, int offset, void *buf, int *count, int *datatype, int *status,    \
    int *ret);                                                                 \
    void pmpi_file_read_at_all_(int *fh, int offset, void *buf, int *count,    \
                                int *datatype, int *status, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_File_read_at_all(fh, offset, buf, count,
                                                datatype, status);
}

void mpi_file_write_at_(int *fh, int offset, void *buf, int *count,
                        int *datatype, int *status, int *ret);
#pragma weak mpi_file_write_at_ = pmpi_file_write_at_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_write_at(int *fh, int offset, void *buf, int *count,
                                     int *datatype, int *status, int *ret);

void INTERF_2_INTEL_MPI_File_write_at(int *fh, int offset, void *buf,
                                      int *count, int *datatype, int *status,
                                      int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_write_at)(        \
    int *fh, int offset, void *buf, int *count, int *datatype, int *status,    \
    int *ret);                                                                 \
    void pmpi_file_write_at_(int *fh, int offset, void *buf, int *count,       \
                             int *datatype, int *status, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_File_write_at(fh, offset, buf, count, datatype,
                                             status);
}

void mpi_file_write_at_all_(int *fh, int offset, void *buf, int *count,
                            int *datatype, int *status, int *ret);
#pragma weak mpi_file_write_at_all_ = pmpi_file_write_at_all_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_write_at_all(int *fh, int offset, void *buf,
                                         int *count, int *datatype, int *status,
                                         int *ret);

void INTERF_2_INTEL_MPI_File_write_at_all(int *fh, int offset, void *buf,
                                          int *count, int *datatype,
                                          int *status, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_write_at_all)(    \
    int *fh, int offset, void *buf, int *count, int *datatype, int *status,    \
    int *ret);                                                                 \
    void pmpi_file_write_at_all_(int *fh, int offset, void *buf, int *count,   \
                                 int *datatype, int *status, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_File_write_at_all(fh, offset, buf, count,
                                                 datatype, status);
}

void mpi_file_iread_at_(int *fh, int offset, void *buf, int *count,
                        int *datatype, int *request, int *ret);
#pragma weak mpi_file_iread_at_ = pmpi_file_iread_at_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_iread_at(int *fh, int offset, void *buf, int *count,
                                     int *datatype, int *request, int *ret);

void INTERF_2_INTEL_MPI_File_iread_at(int *fh, int offset, void *buf,
                                      int *count, int *datatype, int *request,
                                      int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_iread_at)(        \
    int *fh, int offset, void *buf, int *count, int *datatype, int *request,   \
    int *ret);                                                                 \
    void pmpi_file_iread_at_(int *fh, int offset, void *buf, int *count,       \
                             int *datatype, int *request, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_File_iread_at(fh, offset, buf, count, datatype,
                                             request);
}

void mpi_file_iwrite_at_(int *fh, int offset, void *buf, int *count,
                         int *datatype, int *request, int *ret);
#pragma weak mpi_file_iwrite_at_ = pmpi_file_iwrite_at_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_iwrite_at(int *fh, int offset, void *buf,
                                      int *count, int *datatype, int *request,
                                      int *ret);

void INTERF_2_INTEL_MPI_File_iwrite_at(int *fh, int offset, void *buf,
                                       int *count, int *datatype, int *request,
                                       int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_iwrite_at)(       \
    int *fh, int offset, void *buf, int *count, int *datatype, int *request,   \
    int *ret);                                                                 \
    void pmpi_file_iwrite_at_(int *fh, int offset, void *buf, int *count,      \
                              int *datatype, int *request, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_File_iwrite_at(fh, offset, buf, count, datatype,
                                              request);
}

void mpi_file_read_(int *fh, void *buf, int *count, int *datatype, int *status,
                    int *ret);
#pragma weak mpi_file_read_ = pmpi_file_read_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_read(int *fh, void *buf, int *count, int *datatype,
                                 int *status, int *ret);

void INTERF_2_INTEL_MPI_File_read(int *fh, void *buf, int *count, int *datatype,
                                  int *status, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_read)(            \
    int *fh, void *buf, int *count, int *datatype, int *status, int *ret);     \
    void pmpi_file_read_(int *fh, void *buf, int *count, int *datatype,        \
                         int *status, int *ret);
{ return INTERFACE_F_LOCAL_MPI_File_read(fh, buf, count, datatype, status); }

void mpi_file_read_all_(int *fh, void *buf, int *count, int *datatype,
                        int *status, int *ret);
#pragma weak mpi_file_read_all_ = pmpi_file_read_all_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_read_all(int *fh, void *buf, int *count,
                                     int *datatype, int *status, int *ret);

void INTERF_2_INTEL_MPI_File_read_all(int *fh, void *buf, int *count,
                                      int *datatype, int *status, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_read_all)(        \
    int *fh, void *buf, int *count, int *datatype, int *status, int *ret);     \
    void pmpi_file_read_all_(int *fh, void *buf, int *count, int *datatype,    \
                             int *status, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_File_read_all(fh, buf, count, datatype, status);
}

void mpi_file_write_(int *fh, void *buf, int *count, int *datatype, int *status,
                     int *ret);
#pragma weak mpi_file_write_ = pmpi_file_write_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_write(int *fh, void *buf, int *count, int *datatype,
                                  int *status, int *ret);

void INTERF_2_INTEL_MPI_File_write(int *fh, void *buf, int *count,
                                   int *datatype, int *status, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_write)(           \
    int *fh, void *buf, int *count, int *datatype, int *status, int *ret);     \
    void pmpi_file_write_(int *fh, void *buf, int *count, int *datatype,       \
                          int *status, int *ret);
{ return INTERFACE_F_LOCAL_MPI_File_write(fh, buf, count, datatype, status); }

void mpi_file_write_all_(int *fh, void *buf, int *count, int *datatype,
                         int *status, int *ret);
#pragma weak mpi_file_write_all_ = pmpi_file_write_all_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_write_all(int *fh, void *buf, int *count,
                                      int *datatype, int *status, int *ret);

void INTERF_2_INTEL_MPI_File_write_all(int *fh, void *buf, int *count,
                                       int *datatype, int *status, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_write_all)(       \
    int *fh, void *buf, int *count, int *datatype, int *status, int *ret);     \
    void pmpi_file_write_all_(int *fh, void *buf, int *count, int *datatype,   \
                              int *status, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_File_write_all(fh, buf, count, datatype, status);
}

void mpi_file_iread_(int *fh, void *buf, int *count, int *datatype,
                     int *request, int *ret);
#pragma weak mpi_file_iread_ = pmpi_file_iread_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_iread(int *fh, void *buf, int *count, int *datatype,
                                  int *request, int *ret);

void INTERF_2_INTEL_MPI_File_iread(int *fh, void *buf, int *count,
                                   int *datatype, int *request, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_iread)(           \
    int *fh, void *buf, int *count, int *datatype, int *request, int *ret);    \
    void pmpi_file_iread_(int *fh, void *buf, int *count, int *datatype,       \
                          int *request, int *ret);
{ return INTERFACE_F_LOCAL_MPI_File_iread(fh, buf, count, datatype, request); }

void mpi_file_iwrite_(int *fh, void *buf, int *count, int *datatype,
                      int *request, int *ret);
#pragma weak mpi_file_iwrite_ = pmpi_file_iwrite_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_iwrite(int *fh, void *buf, int *count,
                                   int *datatype, int *request, int *ret);

void INTERF_2_INTEL_MPI_File_iwrite(int *fh, void *buf, int *count,
                                    int *datatype, int *request, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_iwrite)(          \
    int *fh, void *buf, int *count, int *datatype, int *request, int *ret);    \
    void pmpi_file_iwrite_(int *fh, void *buf, int *count, int *datatype,      \
                           int *request, int *ret);
{ return INTERFACE_F_LOCAL_MPI_File_iwrite(fh, buf, count, datatype, request); }

void mpi_file_seek_(int *fh, int offset, int *whence, int *ret);
#pragma weak mpi_file_seek_ = pmpi_file_seek_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_seek(int *fh, int offset, int *whence, int *ret);

void INTERF_2_INTEL_MPI_File_seek(int *fh, int offset, int *whence, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_seek)(            \
    int *fh, int offset, int *whence, int *ret);                               \
    void pmpi_file_seek_(int *fh, int offset, int *whence, int *ret);
{ return INTERFACE_F_LOCAL_MPI_File_seek(fh, offset, whence); }

void mpi_file_get_position_(int *fh, int offset, int *ret);
#pragma weak mpi_file_get_position_ = pmpi_file_get_position_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_get_position(int *fh, int offset, int *ret);

void INTERF_2_INTEL_MPI_File_get_position(int *fh, int offset, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_get_position)(    \
    int *fh, int offset, int *ret);                                            \
    void pmpi_file_get_position_(int *fh, int offset, int *ret);
{ return INTERFACE_F_LOCAL_MPI_File_get_position(fh, offset); }

void mpi_file_get_byte_offset_(int *fh, int offset, int disp, int *ret);
#pragma weak mpi_file_get_byte_offset_ = pmpi_file_get_byte_offset_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_get_byte_offset(int *fh, int offset, int disp,
                                            int *ret);

void INTERF_2_INTEL_MPI_File_get_byte_offset(int *fh, int offset, int disp,
                                             int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_get_byte_offset)( \
    int *fh, int offset, int disp, int *ret);                                  \
    void pmpi_file_get_byte_offset_(int *fh, int offset, int disp, int *ret);
{ return INTERFACE_F_LOCAL_MPI_File_get_byte_offset(fh, offset, disp); }

void mpi_file_read_shared_(int *fh, void *buf, int *count, int *datatype,
                           int *status, int *ret);
#pragma weak mpi_file_read_shared_ = pmpi_file_read_shared_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_read_shared(int *fh, void *buf, int *count,
                                        int *datatype, int *status, int *ret);

void INTERF_2_INTEL_MPI_File_read_shared(int *fh, void *buf, int *count,
                                         int *datatype, int *status, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_read_shared)(     \
    int *fh, void *buf, int *count, int *datatype, int *status, int *ret);     \
    void pmpi_file_read_shared_(int *fh, void *buf, int *count, int *datatype, \
                                int *status, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_File_read_shared(fh, buf, count, datatype,
                                                status);
}

void mpi_file_write_shared_(int *fh, void *buf, int *count, int *datatype,
                            int *status, int *ret);
#pragma weak mpi_file_write_shared_ = pmpi_file_write_shared_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_write_shared(int *fh, void *buf, int *count,
                                         int *datatype, int *status, int *ret);

void INTERF_2_INTEL_MPI_File_write_shared(int *fh, void *buf, int *count,
                                          int *datatype, int *status, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_write_shared)(    \
    int *fh, void *buf, int *count, int *datatype, int *status, int *ret);     \
    void pmpi_file_write_shared_(int *fh, void *buf, int *count,               \
                                 int *datatype, int *status, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_File_write_shared(fh, buf, count, datatype,
                                                 status);
}

void mpi_file_iread_shared_(int *fh, void *buf, int *count, int *datatype,
                            int *request, int *ret);
#pragma weak mpi_file_iread_shared_ = pmpi_file_iread_shared_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_iread_shared(int *fh, void *buf, int *count,
                                         int *datatype, int *request, int *ret);

void INTERF_2_INTEL_MPI_File_iread_shared(int *fh, void *buf, int *count,
                                          int *datatype, int *request,
                                          int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_iread_shared)(    \
    int *fh, void *buf, int *count, int *datatype, int *request, int *ret);    \
    void pmpi_file_iread_shared_(int *fh, void *buf, int *count,               \
                                 int *datatype, int *request, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_File_iread_shared(fh, buf, count, datatype,
                                                 request);
}

void mpi_file_iwrite_shared_(int *fh, void *buf, int *count, int *datatype,
                             int *request, int *ret);
#pragma weak mpi_file_iwrite_shared_ = pmpi_file_iwrite_shared_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_iwrite_shared(int *fh, void *buf, int *count,
                                          int *datatype, int *request,
                                          int *ret);

void INTERF_2_INTEL_MPI_File_iwrite_shared(int *fh, void *buf, int *count,
                                           int *datatype, int *request,
                                           int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_iwrite_shared)(   \
    int *fh, void *buf, int *count, int *datatype, int *request, int *ret);    \
    void pmpi_file_iwrite_shared_(int *fh, void *buf, int *count,              \
                                  int *datatype, int *request, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_File_iwrite_shared(fh, buf, count, datatype,
                                                  request);
}

void mpi_file_read_ordered_(int *fh, void *buf, int *count, int *datatype,
                            int *status, int *ret);
#pragma weak mpi_file_read_ordered_ = pmpi_file_read_ordered_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_read_ordered(int *fh, void *buf, int *count,
                                         int *datatype, int *status, int *ret);

void INTERF_2_INTEL_MPI_File_read_ordered(int *fh, void *buf, int *count,
                                          int *datatype, int *status, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_read_ordered)(    \
    int *fh, void *buf, int *count, int *datatype, int *status, int *ret);     \
    void pmpi_file_read_ordered_(int *fh, void *buf, int *count,               \
                                 int *datatype, int *status, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_File_read_ordered(fh, buf, count, datatype,
                                                 status);
}

void mpi_file_write_ordered_(int *fh, void *buf, int *count, int *datatype,
                             int *status, int *ret);
#pragma weak mpi_file_write_ordered_ = pmpi_file_write_ordered_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_write_ordered(int *fh, void *buf, int *count,
                                          int *datatype, int *status, int *ret);

void INTERF_2_INTEL_MPI_File_write_ordered(int *fh, void *buf, int *count,
                                           int *datatype, int *status,
                                           int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_write_ordered)(   \
    int *fh, void *buf, int *count, int *datatype, int *status, int *ret);     \
    void pmpi_file_write_ordered_(int *fh, void *buf, int *count,              \
                                  int *datatype, int *status, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_File_write_ordered(fh, buf, count, datatype,
                                                  status);
}

void mpi_file_seek_shared_(int *fh, int offset, int *whence, int *ret);
#pragma weak mpi_file_seek_shared_ = pmpi_file_seek_shared_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_seek_shared(int *fh, int offset, int *whence,
                                        int *ret);

void INTERF_2_INTEL_MPI_File_seek_shared(int *fh, int offset, int *whence,
                                         int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_seek_shared)(     \
    int *fh, int offset, int *whence, int *ret);                               \
    void pmpi_file_seek_shared_(int *fh, int offset, int *whence, int *ret);
{ return INTERFACE_F_LOCAL_MPI_File_seek_shared(fh, offset, whence); }

void mpi_file_get_position_shared_(int *fh, int offset, int *ret);
#pragma weak mpi_file_get_position_shared_ = pmpi_file_get_position_shared_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_get_position_shared(int *fh, int offset, int *ret);

void INTERF_2_INTEL_MPI_File_get_position_shared(int *fh, int offset, int *ret);

#endif /* WI4MPI_STATIC */ void (                                              \
    *INTERFACE_F_LOCAL_MPI_File_get_position_shared)(int *fh, int offset,      \
                                                     int *ret);                \
    void pmpi_file_get_position_shared_(int *fh, int offset, int *ret);
{ return INTERFACE_F_LOCAL_MPI_File_get_position_shared(fh, offset); }

void mpi_file_read_at_all_begin_(int *fh, int offset, void *buf, int *count,
                                 int *datatype, int *ret);
#pragma weak mpi_file_read_at_all_begin_ = pmpi_file_read_at_all_begin_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_read_at_all_begin(int *fh, int offset, void *buf,
                                              int *count, int *datatype,
                                              int *ret);

void INTERF_2_INTEL_MPI_File_read_at_all_begin(int *fh, int offset, void *buf,
                                               int *count, int *datatype,
                                               int *ret);

#endif /* WI4MPI_STATIC */ void (                                              \
    *INTERFACE_F_LOCAL_MPI_File_read_at_all_begin)(                            \
    int *fh, int offset, void *buf, int *count, int *datatype, int *ret);      \
    void pmpi_file_read_at_all_begin_(int *fh, int offset, void *buf,          \
                                      int *count, int *datatype, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_File_read_at_all_begin(fh, offset, buf, count,
                                                      datatype);
}

void mpi_file_read_at_all_end_(int *fh, void *buf, int *status, int *ret);
#pragma weak mpi_file_read_at_all_end_ = pmpi_file_read_at_all_end_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_read_at_all_end(int *fh, void *buf, int *status,
                                            int *ret);

void INTERF_2_INTEL_MPI_File_read_at_all_end(int *fh, void *buf, int *status,
                                             int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_read_at_all_end)( \
    int *fh, void *buf, int *status, int *ret);                                \
    void pmpi_file_read_at_all_end_(int *fh, void *buf, int *status,           \
                                    int *ret);
{ return INTERFACE_F_LOCAL_MPI_File_read_at_all_end(fh, buf, status); }

void mpi_file_write_at_all_begin_(int *fh, int offset, void *buf, int *count,
                                  int *datatype, int *ret);
#pragma weak mpi_file_write_at_all_begin_ = pmpi_file_write_at_all_begin_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_write_at_all_begin(int *fh, int offset, void *buf,
                                               int *count, int *datatype,
                                               int *ret);

void INTERF_2_INTEL_MPI_File_write_at_all_begin(int *fh, int offset, void *buf,
                                                int *count, int *datatype,
                                                int *ret);

#endif /* WI4MPI_STATIC */ void (                                              \
    *INTERFACE_F_LOCAL_MPI_File_write_at_all_begin)(                           \
    int *fh, int offset, void *buf, int *count, int *datatype, int *ret);      \
    void pmpi_file_write_at_all_begin_(int *fh, int offset, void *buf,         \
                                       int *count, int *datatype, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_File_write_at_all_begin(fh, offset, buf, count,
                                                       datatype);
}

void mpi_file_write_at_all_end_(int *fh, void *buf, int *status, int *ret);
#pragma weak mpi_file_write_at_all_end_ = pmpi_file_write_at_all_end_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_write_at_all_end(int *fh, void *buf, int *status,
                                             int *ret);

void INTERF_2_INTEL_MPI_File_write_at_all_end(int *fh, void *buf, int *status,
                                              int *ret);

#endif /* WI4MPI_STATIC */ void (                                              \
    *INTERFACE_F_LOCAL_MPI_File_write_at_all_end)(int *fh, void *buf,          \
                                                  int *status, int *ret);      \
    void pmpi_file_write_at_all_end_(int *fh, void *buf, int *status,          \
                                     int *ret);
{ return INTERFACE_F_LOCAL_MPI_File_write_at_all_end(fh, buf, status); }

void mpi_file_read_all_begin_(int *fh, void *buf, int *count, int *datatype,
                              int *ret);
#pragma weak mpi_file_read_all_begin_ = pmpi_file_read_all_begin_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_read_all_begin(int *fh, void *buf, int *count,
                                           int *datatype, int *ret);

void INTERF_2_INTEL_MPI_File_read_all_begin(int *fh, void *buf, int *count,
                                            int *datatype, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_read_all_begin)(  \
    int *fh, void *buf, int *count, int *datatype, int *ret);                  \
    void pmpi_file_read_all_begin_(int *fh, void *buf, int *count,             \
                                   int *datatype, int *ret);
{ return INTERFACE_F_LOCAL_MPI_File_read_all_begin(fh, buf, count, datatype); }

void mpi_file_read_all_end_(int *fh, void *buf, int *status, int *ret);
#pragma weak mpi_file_read_all_end_ = pmpi_file_read_all_end_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_read_all_end(int *fh, void *buf, int *status,
                                         int *ret);

void INTERF_2_INTEL_MPI_File_read_all_end(int *fh, void *buf, int *status,
                                          int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_read_all_end)(    \
    int *fh, void *buf, int *status, int *ret);                                \
    void pmpi_file_read_all_end_(int *fh, void *buf, int *status, int *ret);
{ return INTERFACE_F_LOCAL_MPI_File_read_all_end(fh, buf, status); }

void mpi_file_write_all_begin_(int *fh, void *buf, int *count, int *datatype,
                               int *ret);
#pragma weak mpi_file_write_all_begin_ = pmpi_file_write_all_begin_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_write_all_begin(int *fh, void *buf, int *count,
                                            int *datatype, int *ret);

void INTERF_2_INTEL_MPI_File_write_all_begin(int *fh, void *buf, int *count,
                                             int *datatype, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_write_all_begin)( \
    int *fh, void *buf, int *count, int *datatype, int *ret);                  \
    void pmpi_file_write_all_begin_(int *fh, void *buf, int *count,            \
                                    int *datatype, int *ret);
{ return INTERFACE_F_LOCAL_MPI_File_write_all_begin(fh, buf, count, datatype); }

void mpi_file_write_all_end_(int *fh, void *buf, int *status, int *ret);
#pragma weak mpi_file_write_all_end_ = pmpi_file_write_all_end_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_write_all_end(int *fh, void *buf, int *status,
                                          int *ret);

void INTERF_2_INTEL_MPI_File_write_all_end(int *fh, void *buf, int *status,
                                           int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_write_all_end)(   \
    int *fh, void *buf, int *status, int *ret);                                \
    void pmpi_file_write_all_end_(int *fh, void *buf, int *status, int *ret);
{ return INTERFACE_F_LOCAL_MPI_File_write_all_end(fh, buf, status); }

void mpi_file_read_ordered_begin_(int *fh, void *buf, int *count, int *datatype,
                                  int *ret);
#pragma weak mpi_file_read_ordered_begin_ = pmpi_file_read_ordered_begin_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_read_ordered_begin(int *fh, void *buf, int *count,
                                               int *datatype, int *ret);

void INTERF_2_INTEL_MPI_File_read_ordered_begin(int *fh, void *buf, int *count,
                                                int *datatype, int *ret);

#endif /* WI4MPI_STATIC */ void (                                              \
    *INTERFACE_F_LOCAL_MPI_File_read_ordered_begin)(                           \
    int *fh, void *buf, int *count, int *datatype, int *ret);                  \
    void pmpi_file_read_ordered_begin_(int *fh, void *buf, int *count,         \
                                       int *datatype, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_File_read_ordered_begin(fh, buf, count,
                                                       datatype);
}

void mpi_file_read_ordered_end_(int *fh, void *buf, int *status, int *ret);
#pragma weak mpi_file_read_ordered_end_ = pmpi_file_read_ordered_end_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_read_ordered_end(int *fh, void *buf, int *status,
                                             int *ret);

void INTERF_2_INTEL_MPI_File_read_ordered_end(int *fh, void *buf, int *status,
                                              int *ret);

#endif /* WI4MPI_STATIC */ void (                                              \
    *INTERFACE_F_LOCAL_MPI_File_read_ordered_end)(int *fh, void *buf,          \
                                                  int *status, int *ret);      \
    void pmpi_file_read_ordered_end_(int *fh, void *buf, int *status,          \
                                     int *ret);
{ return INTERFACE_F_LOCAL_MPI_File_read_ordered_end(fh, buf, status); }

void mpi_file_write_ordered_begin_(int *fh, void *buf, int *count,
                                   int *datatype, int *ret);
#pragma weak mpi_file_write_ordered_begin_ = pmpi_file_write_ordered_begin_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_write_ordered_begin(int *fh, void *buf, int *count,
                                                int *datatype, int *ret);

void INTERF_2_INTEL_MPI_File_write_ordered_begin(int *fh, void *buf, int *count,
                                                 int *datatype, int *ret);

#endif /* WI4MPI_STATIC */ void (                                              \
    *INTERFACE_F_LOCAL_MPI_File_write_ordered_begin)(                          \
    int *fh, void *buf, int *count, int *datatype, int *ret);                  \
    void pmpi_file_write_ordered_begin_(int *fh, void *buf, int *count,        \
                                        int *datatype, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_File_write_ordered_begin(fh, buf, count,
                                                        datatype);
}

void mpi_file_write_ordered_end_(int *fh, void *buf, int *status, int *ret);
#pragma weak mpi_file_write_ordered_end_ = pmpi_file_write_ordered_end_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_write_ordered_end(int *fh, void *buf, int *status,
                                              int *ret);

void INTERF_2_INTEL_MPI_File_write_ordered_end(int *fh, void *buf, int *status,
                                               int *ret);

#endif /* WI4MPI_STATIC */ void (                                              \
    *INTERFACE_F_LOCAL_MPI_File_write_ordered_end)(int *fh, void *buf,         \
                                                   int *status, int *ret);     \
    void pmpi_file_write_ordered_end_(int *fh, void *buf, int *status,         \
                                      int *ret);
{ return INTERFACE_F_LOCAL_MPI_File_write_ordered_end(fh, buf, status); }

void mpi_file_get_type_extent_(int *fh, int *datatype, size_t extent, int *ret);
#pragma weak mpi_file_get_type_extent_ = pmpi_file_get_type_extent_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_get_type_extent(int *fh, int *datatype,
                                            size_t extent, int *ret);

void INTERF_2_INTEL_MPI_File_get_type_extent(int *fh, int *datatype,
                                             size_t extent, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_get_type_extent)( \
    int *fh, int *datatype, size_t extent, int *ret);                          \
    void pmpi_file_get_type_extent_(int *fh, int *datatype, size_t extent,     \
                                    int *ret);
{ return INTERFACE_F_LOCAL_MPI_File_get_type_extent(fh, datatype, extent); }

void mpi_file_set_atomicity_(int *fh, int *flag, int *ret);
#pragma weak mpi_file_set_atomicity_ = pmpi_file_set_atomicity_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_set_atomicity(int *fh, int *flag, int *ret);

void INTERF_2_INTEL_MPI_File_set_atomicity(int *fh, int *flag, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_set_atomicity)(   \
    int *fh, int *flag, int *ret);                                             \
    void pmpi_file_set_atomicity_(int *fh, int *flag, int *ret);
{ return INTERFACE_F_LOCAL_MPI_File_set_atomicity(fh, flag); }

void mpi_file_get_atomicity_(int *fh, int *flag, int *ret);
#pragma weak mpi_file_get_atomicity_ = pmpi_file_get_atomicity_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_get_atomicity(int *fh, int *flag, int *ret);

void INTERF_2_INTEL_MPI_File_get_atomicity(int *fh, int *flag, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_get_atomicity)(   \
    int *fh, int *flag, int *ret);                                             \
    void pmpi_file_get_atomicity_(int *fh, int *flag, int *ret);
{ return INTERFACE_F_LOCAL_MPI_File_get_atomicity(fh, flag); }

void mpi_file_sync_(int *fh, int *ret);
#pragma weak mpi_file_sync_ = pmpi_file_sync_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_sync(int *fh, int *ret);

void INTERF_2_INTEL_MPI_File_sync(int *fh, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_sync)(int *fh,    \
                                                                   int *ret);  \
    void pmpi_file_sync_(int *fh, int *ret);
{ return INTERFACE_F_LOCAL_MPI_File_sync(fh); }

double mpi_wtime_();
#pragma weak mpi_wtime_ = pmpi_wtime_

#ifdef WI4MPI_STATIC

double INTERF_2_OMPI_MPI_Wtime();

double INTERF_2_INTEL_MPI_Wtime();

#endif /* WI4MPI_STATIC */ double (*INTERFACE_F_LOCAL_MPI_Wtime)();            \
    double pmpi_wtime_();
{ return INTERFACE_F_LOCAL_MPI_Wtime(); }

double mpi_wtick_();
#pragma weak mpi_wtick_ = pmpi_wtick_

#ifdef WI4MPI_STATIC

double INTERF_2_OMPI_MPI_Wtick();

double INTERF_2_INTEL_MPI_Wtick();

#endif /* WI4MPI_STATIC */ double (*INTERFACE_F_LOCAL_MPI_Wtick)();            \
    double pmpi_wtick_();
{ return INTERFACE_F_LOCAL_MPI_Wtick(); }

void mpi_finalize_(int *ret);
#pragma weak mpi_finalize_ = pmpi_finalize_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Finalize(int *ret);

void INTERF_2_INTEL_MPI_Finalize(int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Finalize)(int *ret);   \
    void pmpi_finalize_(int *ret);
{ return INTERFACE_F_LOCAL_MPI_Finalize(); }

void mpi_waitany_(int *count, int *array_of_requests, int *indx, int *status,
                  int *ret);
#pragma weak mpi_waitany_ = pmpi_waitany_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Waitany(int *count, int *array_of_requests, int *indx,
                               int *status, int *ret);

void INTERF_2_INTEL_MPI_Waitany(int *count, int *array_of_requests, int *indx,
                                int *status, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Waitany)(              \
    int *count, int *array_of_requests, int *indx, int *status, int *ret);     \
    void pmpi_waitany_(int *count, int *array_of_requests, int *indx,          \
                       int *status, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Waitany(count, array_of_requests, indx, status);
}

void mpi_testany_(int *count, int *array_of_requests, int *indx, int *flag,
                  int *status, int *ret);
#pragma weak mpi_testany_ = pmpi_testany_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Testany(int *count, int *array_of_requests, int *indx,
                               int *flag, int *status, int *ret);

void INTERF_2_INTEL_MPI_Testany(int *count, int *array_of_requests, int *indx,
                                int *flag, int *status, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Testany)(              \
    int *count, int *array_of_requests, int *indx, int *flag, int *status,     \
    int *ret);                                                                 \
    void pmpi_testany_(int *count, int *array_of_requests, int *indx,          \
                       int *flag, int *status, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Testany(count, array_of_requests, indx, flag,
                                       status);
}

void mpi_waitall_(int *count, int *array_of_requests, int *array_of_statuses,
                  int *ret);
#pragma weak mpi_waitall_ = pmpi_waitall_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Waitall(int *count, int *array_of_requests,
                               int *array_of_statuses, int *ret);

void INTERF_2_INTEL_MPI_Waitall(int *count, int *array_of_requests,
                                int *array_of_statuses, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Waitall)(              \
    int *count, int *array_of_requests, int *array_of_statuses, int *ret);     \
    void pmpi_waitall_(int *count, int *array_of_requests,                     \
                       int *array_of_statuses, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Waitall(count, array_of_requests,
                                       array_of_statuses);
}

void mpi_testall_(int *count, int *array_of_requests, int *flag,
                  int *array_of_statuses, int *ret);
#pragma weak mpi_testall_ = pmpi_testall_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Testall(int *count, int *array_of_requests, int *flag,
                               int *array_of_statuses, int *ret);

void INTERF_2_INTEL_MPI_Testall(int *count, int *array_of_requests, int *flag,
                                int *array_of_statuses, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Testall)(              \
    int *count, int *array_of_requests, int *flag, int *array_of_statuses,     \
    int *ret);                                                                 \
    void pmpi_testall_(int *count, int *array_of_requests, int *flag,          \
                       int *array_of_statuses, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Testall(count, array_of_requests, flag,
                                       array_of_statuses);
}

void mpi_waitsome_(int *incount, int *array_of_requests, int *outcount,
                   int *array_of_indices, int *array_of_statuses, int *ret);
#pragma weak mpi_waitsome_ = pmpi_waitsome_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Waitsome(int *incount, int *array_of_requests,
                                int *outcount, int *array_of_indices,
                                int *array_of_statuses, int *ret);

void INTERF_2_INTEL_MPI_Waitsome(int *incount, int *array_of_requests,
                                 int *outcount, int *array_of_indices,
                                 int *array_of_statuses, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Waitsome)(             \
    int *incount, int *array_of_requests, int *outcount,                       \
    int *array_of_indices, int *array_of_statuses, int *ret);                  \
    void pmpi_waitsome_(int *incount, int *array_of_requests, int *outcount,   \
                        int *array_of_indices, int *array_of_statuses,         \
                        int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Waitsome(incount, array_of_requests, outcount,
                                        array_of_indices, array_of_statuses);
}

void mpi_testsome_(int *incount, int *array_of_requests, int *outcount,
                   int *array_of_indices, int *array_of_statuses, int *ret);
#pragma weak mpi_testsome_ = pmpi_testsome_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Testsome(int *incount, int *array_of_requests,
                                int *outcount, int *array_of_indices,
                                int *array_of_statuses, int *ret);

void INTERF_2_INTEL_MPI_Testsome(int *incount, int *array_of_requests,
                                 int *outcount, int *array_of_indices,
                                 int *array_of_statuses, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Testsome)(             \
    int *incount, int *array_of_requests, int *outcount,                       \
    int *array_of_indices, int *array_of_statuses, int *ret);                  \
    void pmpi_testsome_(int *incount, int *array_of_requests, int *outcount,   \
                        int *array_of_indices, int *array_of_statuses,         \
                        int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Testsome(incount, array_of_requests, outcount,
                                        array_of_indices, array_of_statuses);
}

void mpi_startall_(int *count, int *array_of_requests, int *ret);
#pragma weak mpi_startall_ = pmpi_startall_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Startall(int *count, int *array_of_requests, int *ret);

void INTERF_2_INTEL_MPI_Startall(int *count, int *array_of_requests, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Startall)(             \
    int *count, int *array_of_requests, int *ret);                             \
    void pmpi_startall_(int *count, int *array_of_requests, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Startall(count, array_of_requests); }

void mpi_alltoallw_(void *sendbuf, int *sendcounts, int *sdispls,
                    int *sendtypes, void *recvbuf, int *recvcounts,
                    int *rdispls, int *recvtypes, int *comm, int *ret);
#pragma weak mpi_alltoallw_ = pmpi_alltoallw_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Alltoallw(void *sendbuf, int *sendcounts, int *sdispls,
                                 int *sendtypes, void *recvbuf, int *recvcounts,
                                 int *rdispls, int *recvtypes, int *comm,
                                 int *ret);

void INTERF_2_INTEL_MPI_Alltoallw(void *sendbuf, int *sendcounts, int *sdispls,
                                  int *sendtypes, void *recvbuf,
                                  int *recvcounts, int *rdispls, int *recvtypes,
                                  int *comm, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Alltoallw)(            \
    void *sendbuf, int *sendcounts, int *sdispls, int *sendtypes,              \
    void *recvbuf, int *recvcounts, int *rdispls, int *recvtypes, int *comm,   \
    int *ret);                                                                 \
    void pmpi_alltoallw_(void *sendbuf, int *sendcounts, int *sdispls,         \
                         int *sendtypes, void *recvbuf, int *recvcounts,       \
                         int *rdispls, int *recvtypes, int *comm, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Alltoallw(sendbuf, sendcounts, sdispls,
                                         sendtypes, recvbuf, recvcounts,
                                         rdispls, recvtypes, comm);
}

void mpi_reduce_scatter_(void *sendbuf, void *recvbuf, int *recvcounts,
                         int *datatype, int *op, int *comm, int *ret);
#pragma weak mpi_reduce_scatter_ = pmpi_reduce_scatter_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Reduce_scatter(void *sendbuf, void *recvbuf,
                                      int *recvcounts, int *datatype, int *op,
                                      int *comm, int *ret);

void INTERF_2_INTEL_MPI_Reduce_scatter(void *sendbuf, void *recvbuf,
                                       int *recvcounts, int *datatype, int *op,
                                       int *comm, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Reduce_scatter)(       \
    void *sendbuf, void *recvbuf, int *recvcounts, int *datatype, int *op,     \
    int *comm, int *ret);                                                      \
    void pmpi_reduce_scatter_(void *sendbuf, void *recvbuf, int *recvcounts,   \
                              int *datatype, int *op, int *comm, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Reduce_scatter(sendbuf, recvbuf, recvcounts,
                                              datatype, op, comm);
}

void mpi_group_translate_ranks_(int *group1, int *n, int *ranks1, int *group2,
                                int *ranks2, int *ret);
#pragma weak mpi_group_translate_ranks_ = pmpi_group_translate_ranks_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Group_translate_ranks(int *group1, int *n, int *ranks1,
                                             int *group2, int *ranks2,
                                             int *ret);

void INTERF_2_INTEL_MPI_Group_translate_ranks(int *group1, int *n, int *ranks1,
                                              int *group2, int *ranks2,
                                              int *ret);

#endif /* WI4MPI_STATIC */ void (                                              \
    *INTERFACE_F_LOCAL_MPI_Group_translate_ranks)(                             \
    int *group1, int *n, int *ranks1, int *group2, int *ranks2, int *ret);     \
    void pmpi_group_translate_ranks_(int *group1, int *n, int *ranks1,         \
                                     int *group2, int *ranks2, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Group_translate_ranks(group1, n, ranks1, group2,
                                                     ranks2);
}

void mpi_group_incl_(int *group, int *n, int *ranks, int *newgroup, int *ret);
#pragma weak mpi_group_incl_ = pmpi_group_incl_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Group_incl(int *group, int *n, int *ranks, int *newgroup,
                                  int *ret);

void INTERF_2_INTEL_MPI_Group_incl(int *group, int *n, int *ranks,
                                   int *newgroup, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Group_incl)(           \
    int *group, int *n, int *ranks, int *newgroup, int *ret);                  \
    void pmpi_group_incl_(int *group, int *n, int *ranks, int *newgroup,       \
                          int *ret);
{ return INTERFACE_F_LOCAL_MPI_Group_incl(group, n, ranks, newgroup); }

void mpi_group_excl_(int *group, int *n, int *ranks, int *newgroup, int *ret);
#pragma weak mpi_group_excl_ = pmpi_group_excl_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Group_excl(int *group, int *n, int *ranks, int *newgroup,
                                  int *ret);

void INTERF_2_INTEL_MPI_Group_excl(int *group, int *n, int *ranks,
                                   int *newgroup, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Group_excl)(           \
    int *group, int *n, int *ranks, int *newgroup, int *ret);                  \
    void pmpi_group_excl_(int *group, int *n, int *ranks, int *newgroup,       \
                          int *ret);
{ return INTERFACE_F_LOCAL_MPI_Group_excl(group, n, ranks, newgroup); }

void mpi_group_range_incl_(int *group, int *n, int *ranges, int *newgroup,
                           int *ret);
#pragma weak mpi_group_range_incl_ = pmpi_group_range_incl_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Group_range_incl(int *group, int *n, int *ranges,
                                        int *newgroup, int *ret);

void INTERF_2_INTEL_MPI_Group_range_incl(int *group, int *n, int *ranges,
                                         int *newgroup, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Group_range_incl)(     \
    int *group, int *n, int *ranges, int *newgroup, int *ret);                 \
    void pmpi_group_range_incl_(int *group, int *n, int *ranges,               \
                                int *newgroup, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Group_range_incl(group, n, ranges, newgroup); }

void mpi_group_range_excl_(int *group, int *n, int *ranges, int *newgroup,
                           int *ret);
#pragma weak mpi_group_range_excl_ = pmpi_group_range_excl_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Group_range_excl(int *group, int *n, int *ranges,
                                        int *newgroup, int *ret);

void INTERF_2_INTEL_MPI_Group_range_excl(int *group, int *n, int *ranges,
                                         int *newgroup, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Group_range_excl)(     \
    int *group, int *n, int *ranges, int *newgroup, int *ret);                 \
    void pmpi_group_range_excl_(int *group, int *n, int *ranges,               \
                                int *newgroup, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Group_range_excl(group, n, ranges, newgroup); }

void mpi_cart_create_(int *comm_old, int *ndims, int *dims, int *periods,
                      int *reorder, int *comm_cart, int *ret);
#pragma weak mpi_cart_create_ = pmpi_cart_create_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Cart_create(int *comm_old, int *ndims, int *dims,
                                   int *periods, int *reorder, int *comm_cart,
                                   int *ret);

void INTERF_2_INTEL_MPI_Cart_create(int *comm_old, int *ndims, int *dims,
                                    int *periods, int *reorder, int *comm_cart,
                                    int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Cart_create)(          \
    int *comm_old, int *ndims, int *dims, int *periods, int *reorder,          \
    int *comm_cart, int *ret);                                                 \
    void pmpi_cart_create_(int *comm_old, int *ndims, int *dims, int *periods, \
                           int *reorder, int *comm_cart, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Cart_create(comm_old, ndims, dims, periods,
                                           reorder, comm_cart);
}

void mpi_dims_create_(int *nnodes, int *ndims, int *dims, int *ret);
#pragma weak mpi_dims_create_ = pmpi_dims_create_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Dims_create(int *nnodes, int *ndims, int *dims,
                                   int *ret);

void INTERF_2_INTEL_MPI_Dims_create(int *nnodes, int *ndims, int *dims,
                                    int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Dims_create)(          \
    int *nnodes, int *ndims, int *dims, int *ret);                             \
    void pmpi_dims_create_(int *nnodes, int *ndims, int *dims, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Dims_create(nnodes, ndims, dims); }

void mpi_graph_create_(int *comm_old, int *nnodes, int *indx, int *edges,
                       int *reorder, int *comm_graph, int *ret);
#pragma weak mpi_graph_create_ = pmpi_graph_create_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Graph_create(int *comm_old, int *nnodes, int *indx,
                                    int *edges, int *reorder, int *comm_graph,
                                    int *ret);

void INTERF_2_INTEL_MPI_Graph_create(int *comm_old, int *nnodes, int *indx,
                                     int *edges, int *reorder, int *comm_graph,
                                     int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Graph_create)(         \
    int *comm_old, int *nnodes, int *indx, int *edges, int *reorder,           \
    int *comm_graph, int *ret);                                                \
    void pmpi_graph_create_(int *comm_old, int *nnodes, int *indx, int *edges, \
                            int *reorder, int *comm_graph, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Graph_create(comm_old, nnodes, indx, edges,
                                            reorder, comm_graph);
}

void mpi_graph_get_(int *comm, int *maxindex, int *maxedges, int *indx,
                    int *edges, int *ret);
#pragma weak mpi_graph_get_ = pmpi_graph_get_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Graph_get(int *comm, int *maxindex, int *maxedges,
                                 int *indx, int *edges, int *ret);

void INTERF_2_INTEL_MPI_Graph_get(int *comm, int *maxindex, int *maxedges,
                                  int *indx, int *edges, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Graph_get)(            \
    int *comm, int *maxindex, int *maxedges, int *indx, int *edges, int *ret); \
    void pmpi_graph_get_(int *comm, int *maxindex, int *maxedges, int *indx,   \
                         int *edges, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Graph_get(comm, maxindex, maxedges, indx, edges);
}

void mpi_cart_get_(int *comm, int *maxdims, int *dims, int *periods,
                   int *coords, int *ret);
#pragma weak mpi_cart_get_ = pmpi_cart_get_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Cart_get(int *comm, int *maxdims, int *dims,
                                int *periods, int *coords, int *ret);

void INTERF_2_INTEL_MPI_Cart_get(int *comm, int *maxdims, int *dims,
                                 int *periods, int *coords, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Cart_get)(             \
    int *comm, int *maxdims, int *dims, int *periods, int *coords, int *ret);  \
    void pmpi_cart_get_(int *comm, int *maxdims, int *dims, int *periods,      \
                        int *coords, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Cart_get(comm, maxdims, dims, periods, coords); }

void mpi_cart_rank_(int *comm, int *coords, int *rank, int *ret);
#pragma weak mpi_cart_rank_ = pmpi_cart_rank_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Cart_rank(int *comm, int *coords, int *rank, int *ret);

void INTERF_2_INTEL_MPI_Cart_rank(int *comm, int *coords, int *rank, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Cart_rank)(            \
    int *comm, int *coords, int *rank, int *ret);                              \
    void pmpi_cart_rank_(int *comm, int *coords, int *rank, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Cart_rank(comm, coords, rank); }

void mpi_cart_coords_(int *comm, int *rank, int *maxdims, int *coords,
                      int *ret);
#pragma weak mpi_cart_coords_ = pmpi_cart_coords_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Cart_coords(int *comm, int *rank, int *maxdims,
                                   int *coords, int *ret);

void INTERF_2_INTEL_MPI_Cart_coords(int *comm, int *rank, int *maxdims,
                                    int *coords, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Cart_coords)(          \
    int *comm, int *rank, int *maxdims, int *coords, int *ret);                \
    void pmpi_cart_coords_(int *comm, int *rank, int *maxdims, int *coords,    \
                           int *ret);
{ return INTERFACE_F_LOCAL_MPI_Cart_coords(comm, rank, maxdims, coords); }

void mpi_graph_neighbors_(int *comm, int *rank, int *maxneighbors,
                          int *neighbors, int *ret);
#pragma weak mpi_graph_neighbors_ = pmpi_graph_neighbors_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Graph_neighbors(int *comm, int *rank, int *maxneighbors,
                                       int *neighbors, int *ret);

void INTERF_2_INTEL_MPI_Graph_neighbors(int *comm, int *rank, int *maxneighbors,
                                        int *neighbors, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Graph_neighbors)(      \
    int *comm, int *rank, int *maxneighbors, int *neighbors, int *ret);        \
    void pmpi_graph_neighbors_(int *comm, int *rank, int *maxneighbors,        \
                               int *neighbors, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Graph_neighbors(comm, rank, maxneighbors,
                                               neighbors);
}

void mpi_cart_sub_(int *comm, int *remain_dims, int *newcomm, int *ret);
#pragma weak mpi_cart_sub_ = pmpi_cart_sub_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Cart_sub(int *comm, int *remain_dims, int *newcomm,
                                int *ret);

void INTERF_2_INTEL_MPI_Cart_sub(int *comm, int *remain_dims, int *newcomm,
                                 int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Cart_sub)(             \
    int *comm, int *remain_dims, int *newcomm, int *ret);                      \
    void pmpi_cart_sub_(int *comm, int *remain_dims, int *newcomm, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Cart_sub(comm, remain_dims, newcomm); }

void mpi_cart_map_(int *comm, int *ndims, int *dims, int *periods, int *newrank,
                   int *ret);
#pragma weak mpi_cart_map_ = pmpi_cart_map_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Cart_map(int *comm, int *ndims, int *dims, int *periods,
                                int *newrank, int *ret);

void INTERF_2_INTEL_MPI_Cart_map(int *comm, int *ndims, int *dims, int *periods,
                                 int *newrank, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Cart_map)(             \
    int *comm, int *ndims, int *dims, int *periods, int *newrank, int *ret);   \
    void pmpi_cart_map_(int *comm, int *ndims, int *dims, int *periods,        \
                        int *newrank, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Cart_map(comm, ndims, dims, periods, newrank); }

void mpi_graph_map_(int *comm, int *nnodes, int *indx, int *edges, int *newrank,
                    int *ret);
#pragma weak mpi_graph_map_ = pmpi_graph_map_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Graph_map(int *comm, int *nnodes, int *indx, int *edges,
                                 int *newrank, int *ret);

void INTERF_2_INTEL_MPI_Graph_map(int *comm, int *nnodes, int *indx, int *edges,
                                  int *newrank, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Graph_map)(            \
    int *comm, int *nnodes, int *indx, int *edges, int *newrank, int *ret);    \
    void pmpi_graph_map_(int *comm, int *nnodes, int *indx, int *edges,        \
                         int *newrank, int *ret);
{ return INTERFACE_F_LOCAL_MPI_Graph_map(comm, nnodes, indx, edges, newrank); }

void mpi_comm_spawn_(char *command, char argv, int *maxprocs, int *info,
                     int *root, int *comm, int *intercomm,
                     int *array_of_errcodes, int *ret);
#pragma weak mpi_comm_spawn_ = pmpi_comm_spawn_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Comm_spawn(char *command, char argv, int *maxprocs,
                                  int *info, int *root, int *comm,
                                  int *intercomm, int *array_of_errcodes,
                                  int *ret);

void INTERF_2_INTEL_MPI_Comm_spawn(char *command, char argv, int *maxprocs,
                                   int *info, int *root, int *comm,
                                   int *intercomm, int *array_of_errcodes,
                                   int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Comm_spawn)(           \
    char *command, char argv, int *maxprocs, int *info, int *root, int *comm,  \
    int *intercomm, int *array_of_errcodes, int *ret);                         \
    void pmpi_comm_spawn_(char *command, char argv, int *maxprocs, int *info,  \
                          int *root, int *comm, int *intercomm,                \
                          int *array_of_errcodes, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Comm_spawn(command, argv, maxprocs, info, root,
                                          comm, intercomm, array_of_errcodes);
}

void mpi_type_get_contents_(int *datatype, int *max_integers,
                            int *max_addresses, int *max_datatypes,
                            int *array_of_integers, size_t array_of_addresses,
                            int *array_of_datatypes, int *ret);
#pragma weak mpi_type_get_contents_ = pmpi_type_get_contents_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Type_get_contents(int *datatype, int *max_integers,
                                         int *max_addresses, int *max_datatypes,
                                         int *array_of_integers,
                                         size_t array_of_addresses,
                                         int *array_of_datatypes, int *ret);

void INTERF_2_INTEL_MPI_Type_get_contents(int *datatype, int *max_integers,
                                          int *max_addresses,
                                          int *max_datatypes,
                                          int *array_of_integers,
                                          size_t array_of_addresses,
                                          int *array_of_datatypes, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Type_get_contents)(    \
    int *datatype, int *max_integers, int *max_addresses, int *max_datatypes,  \
    int *array_of_integers, size_t array_of_addresses,                         \
    int *array_of_datatypes, int *ret);                                        \
    void pmpi_type_get_contents_(                                              \
        int *datatype, int *max_integers, int *max_addresses,                  \
        int *max_datatypes, int *array_of_integers, size_t array_of_addresses, \
        int *array_of_datatypes, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Type_get_contents(
      datatype, max_integers, max_addresses, max_datatypes, array_of_integers,
      array_of_addresses, array_of_datatypes);
}

void mpi_type_create_darray_(int *size, int *rank, int *ndims,
                             int *array_of_gsizes, int *array_of_distribs,
                             int *array_of_dargs, int *array_of_psizes,
                             int *order, int *oldtype, int *newtype, int *ret);
#pragma weak mpi_type_create_darray_ = pmpi_type_create_darray_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Type_create_darray(int *size, int *rank, int *ndims,
                                          int *array_of_gsizes,
                                          int *array_of_distribs,
                                          int *array_of_dargs,
                                          int *array_of_psizes, int *order,
                                          int *oldtype, int *newtype, int *ret);

void INTERF_2_INTEL_MPI_Type_create_darray(
    int *size, int *rank, int *ndims, int *array_of_gsizes,
    int *array_of_distribs, int *array_of_dargs, int *array_of_psizes,
    int *order, int *oldtype, int *newtype, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Type_create_darray)(   \
    int *size, int *rank, int *ndims, int *array_of_gsizes,                    \
    int *array_of_distribs, int *array_of_dargs, int *array_of_psizes,         \
    int *order, int *oldtype, int *newtype, int *ret);                         \
    void pmpi_type_create_darray_(                                             \
        int *size, int *rank, int *ndims, int *array_of_gsizes,                \
        int *array_of_distribs, int *array_of_dargs, int *array_of_psizes,     \
        int *order, int *oldtype, int *newtype, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Type_create_darray(
      size, rank, ndims, array_of_gsizes, array_of_distribs, array_of_dargs,
      array_of_psizes, order, oldtype, newtype);
}

void mpi_type_create_hindexed_(int *count, int *array_of_blocklengths,
                               size_t array_of_displacements, int *oldtype,
                               int *newtype, int *ret);
#pragma weak mpi_type_create_hindexed_ = pmpi_type_create_hindexed_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Type_create_hindexed(int *count,
                                            int *array_of_blocklengths,
                                            size_t array_of_displacements,
                                            int *oldtype, int *newtype,
                                            int *ret);

void INTERF_2_INTEL_MPI_Type_create_hindexed(int *count,
                                             int *array_of_blocklengths,
                                             size_t array_of_displacements,
                                             int *oldtype, int *newtype,
                                             int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Type_create_hindexed)( \
    int *count, int *array_of_blocklengths, size_t array_of_displacements,     \
    int *oldtype, int *newtype, int *ret);                                     \
    void pmpi_type_create_hindexed_(int *count, int *array_of_blocklengths,    \
                                    size_t array_of_displacements,             \
                                    int *oldtype, int *newtype, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Type_create_hindexed(
      count, array_of_blocklengths, array_of_displacements, oldtype, newtype);
}

void mpi_type_create_indexed_block_(int *count, int *blocklength,
                                    int *array_of_displacements, int *oldtype,
                                    int *newtype, int *ret);
#pragma weak mpi_type_create_indexed_block_ = pmpi_type_create_indexed_block_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Type_create_indexed_block(int *count, int *blocklength,
                                                 int *array_of_displacements,
                                                 int *oldtype, int *newtype,
                                                 int *ret);

void INTERF_2_INTEL_MPI_Type_create_indexed_block(int *count, int *blocklength,
                                                  int *array_of_displacements,
                                                  int *oldtype, int *newtype,
                                                  int *ret);

#endif /* WI4MPI_STATIC */ void (                                              \
    *INTERFACE_F_LOCAL_MPI_Type_create_indexed_block)(                         \
    int *count, int *blocklength, int *array_of_displacements, int *oldtype,   \
    int *newtype, int *ret);                                                   \
    void pmpi_type_create_indexed_block_(                                      \
        int *count, int *blocklength, int *array_of_displacements,             \
        int *oldtype, int *newtype, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Type_create_indexed_block(
      count, blocklength, array_of_displacements, oldtype, newtype);
}

void mpi_type_create_hindexed_block_(int *count, int *blocklength,
                                     size_t array_of_displacements,
                                     int *oldtype, int *newtype, int *ret);
#pragma weak mpi_type_create_hindexed_block_ = pmpi_type_create_hindexed_block_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Type_create_hindexed_block(int *count, int *blocklength,
                                                  size_t array_of_displacements,
                                                  int *oldtype, int *newtype,
                                                  int *ret);

void INTERF_2_INTEL_MPI_Type_create_hindexed_block(
    int *count, int *blocklength, size_t array_of_displacements, int *oldtype,
    int *newtype, int *ret);

#endif /* WI4MPI_STATIC */ void (                                              \
    *INTERFACE_F_LOCAL_MPI_Type_create_hindexed_block)(                        \
    int *count, int *blocklength, size_t array_of_displacements, int *oldtype, \
    int *newtype, int *ret);                                                   \
    void pmpi_type_create_hindexed_block_(                                     \
        int *count, int *blocklength, size_t array_of_displacements,           \
        int *oldtype, int *newtype, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Type_create_hindexed_block(
      count, blocklength, array_of_displacements, oldtype, newtype);
}

void mpi_type_create_struct_(int *count, int *array_of_blocklengths,
                             size_t array_of_displacements, int *array_of_types,
                             int *newtype, int *ret);
#pragma weak mpi_type_create_struct_ = pmpi_type_create_struct_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Type_create_struct(int *count,
                                          int *array_of_blocklengths,
                                          size_t array_of_displacements,
                                          int *array_of_types, int *newtype,
                                          int *ret);

void INTERF_2_INTEL_MPI_Type_create_struct(int *count,
                                           int *array_of_blocklengths,
                                           size_t array_of_displacements,
                                           int *array_of_types, int *newtype,
                                           int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Type_create_struct)(   \
    int *count, int *array_of_blocklengths, size_t array_of_displacements,     \
    int *array_of_types, int *newtype, int *ret);                              \
    void pmpi_type_create_struct_(                                             \
        int *count, int *array_of_blocklengths, size_t array_of_displacements, \
        int *array_of_types, int *newtype, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Type_create_struct(count, array_of_blocklengths,
                                                  array_of_displacements,
                                                  array_of_types, newtype);
}

void mpi_type_create_subarray_(int *ndims, int *array_of_sizes,
                               int *array_of_subsizes, int *array_of_starts,
                               int *order, int *oldtype, int *newtype,
                               int *ret);
#pragma weak mpi_type_create_subarray_ = pmpi_type_create_subarray_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Type_create_subarray(int *ndims, int *array_of_sizes,
                                            int *array_of_subsizes,
                                            int *array_of_starts, int *order,
                                            int *oldtype, int *newtype,
                                            int *ret);

void INTERF_2_INTEL_MPI_Type_create_subarray(int *ndims, int *array_of_sizes,
                                             int *array_of_subsizes,
                                             int *array_of_starts, int *order,
                                             int *oldtype, int *newtype,
                                             int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Type_create_subarray)( \
    int *ndims, int *array_of_sizes, int *array_of_subsizes,                   \
    int *array_of_starts, int *order, int *oldtype, int *newtype, int *ret);   \
    void pmpi_type_create_subarray_(int *ndims, int *array_of_sizes,           \
                                    int *array_of_subsizes,                    \
                                    int *array_of_starts, int *order,          \
                                    int *oldtype, int *newtype, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Type_create_subarray(
      ndims, array_of_sizes, array_of_subsizes, array_of_starts, order, oldtype,
      newtype);
}

void mpi_dist_graph_create_adjacent_(int *comm_old, int *indegree, int *sources,
                                     int *sourceweights, int *outdegree,
                                     int *destinations, int *destweights,
                                     int *info, int *reorder,
                                     int *comm_dist_graph, int *ret);
#pragma weak mpi_dist_graph_create_adjacent_ = pmpi_dist_graph_create_adjacent_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Dist_graph_create_adjacent(
    int *comm_old, int *indegree, int *sources, int *sourceweights,
    int *outdegree, int *destinations, int *destweights, int *info,
    int *reorder, int *comm_dist_graph, int *ret);

void INTERF_2_INTEL_MPI_Dist_graph_create_adjacent(
    int *comm_old, int *indegree, int *sources, int *sourceweights,
    int *outdegree, int *destinations, int *destweights, int *info,
    int *reorder, int *comm_dist_graph, int *ret);

#endif /* WI4MPI_STATIC */ void (                                              \
    *INTERFACE_F_LOCAL_MPI_Dist_graph_create_adjacent)(                        \
    int *comm_old, int *indegree, int *sources, int *sourceweights,            \
    int *outdegree, int *destinations, int *destweights, int *info,            \
    int *reorder, int *comm_dist_graph, int *ret);                             \
    void pmpi_dist_graph_create_adjacent_(                                     \
        int *comm_old, int *indegree, int *sources, int *sourceweights,        \
        int *outdegree, int *destinations, int *destweights, int *info,        \
        int *reorder, int *comm_dist_graph, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Dist_graph_create_adjacent(
      comm_old, indegree, sources, sourceweights, outdegree, destinations,
      destweights, info, reorder, comm_dist_graph);
}

void mpi_dist_graph_create_(int *comm_old, int *n, int *sources, int *degrees,
                            int *destinations, int *weights, int *info,
                            int *reorder, int *comm_dist_graph, int *ret);
#pragma weak mpi_dist_graph_create_ = pmpi_dist_graph_create_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Dist_graph_create(int *comm_old, int *n, int *sources,
                                         int *degrees, int *destinations,
                                         int *weights, int *info, int *reorder,
                                         int *comm_dist_graph, int *ret);

void INTERF_2_INTEL_MPI_Dist_graph_create(int *comm_old, int *n, int *sources,
                                          int *degrees, int *destinations,
                                          int *weights, int *info, int *reorder,
                                          int *comm_dist_graph, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Dist_graph_create)(    \
    int *comm_old, int *n, int *sources, int *degrees, int *destinations,      \
    int *weights, int *info, int *reorder, int *comm_dist_graph, int *ret);    \
    void pmpi_dist_graph_create_(int *comm_old, int *n, int *sources,          \
                                 int *degrees, int *destinations,              \
                                 int *weights, int *info, int *reorder,        \
                                 int *comm_dist_graph, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Dist_graph_create(comm_old, n, sources, degrees,
                                                 destinations, weights, info,
                                                 reorder, comm_dist_graph);
}

void mpi_dist_graph_neighbors_(int *comm, int *maxindegree, int *sources,
                               int *sourceweights, int *maxoutdegree,
                               int *destinations, int *destweights, int *ret);
#pragma weak mpi_dist_graph_neighbors_ = pmpi_dist_graph_neighbors_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Dist_graph_neighbors(int *comm, int *maxindegree,
                                            int *sources, int *sourceweights,
                                            int *maxoutdegree,
                                            int *destinations, int *destweights,
                                            int *ret);

void INTERF_2_INTEL_MPI_Dist_graph_neighbors(int *comm, int *maxindegree,
                                             int *sources, int *sourceweights,
                                             int *maxoutdegree,
                                             int *destinations,
                                             int *destweights, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Dist_graph_neighbors)( \
    int *comm, int *maxindegree, int *sources, int *sourceweights,             \
    int *maxoutdegree, int *destinations, int *destweights, int *ret);         \
    void pmpi_dist_graph_neighbors_(                                           \
        int *comm, int *maxindegree, int *sources, int *sourceweights,         \
        int *maxoutdegree, int *destinations, int *destweights, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Dist_graph_neighbors(comm, maxindegree, sources,
                                                    sourceweights, maxoutdegree,
                                                    destinations, destweights);
}

void mpi_igatherv_(void *sendbuf, int *sendcount, int *sendtype, void *recvbuf,
                   int *recvcounts, int *displs, int *recvtype, int *root,
                   int *comm, int *request, int *ret);
#pragma weak mpi_igatherv_ = pmpi_igatherv_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Igatherv(void *sendbuf, int *sendcount, int *sendtype,
                                void *recvbuf, int *recvcounts, int *displs,
                                int *recvtype, int *root, int *comm,
                                int *request, int *ret);

void INTERF_2_INTEL_MPI_Igatherv(void *sendbuf, int *sendcount, int *sendtype,
                                 void *recvbuf, int *recvcounts, int *displs,
                                 int *recvtype, int *root, int *comm,
                                 int *request, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Igatherv)(             \
    void *sendbuf, int *sendcount, int *sendtype, void *recvbuf,               \
    int *recvcounts, int *displs, int *recvtype, int *root, int *comm,         \
    int *request, int *ret);                                                   \
    void pmpi_igatherv_(void *sendbuf, int *sendcount, int *sendtype,          \
                        void *recvbuf, int *recvcounts, int *displs,           \
                        int *recvtype, int *root, int *comm, int *request,     \
                        int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Igatherv(sendbuf, sendcount, sendtype, recvbuf,
                                        recvcounts, displs, recvtype, root,
                                        comm, request);
}

void mpi_iscatterv_(void *sendbuf, int *sendcounts, int *displs, int *sendtype,
                    void *recvbuf, int *recvcount, int *recvtype, int *root,
                    int *comm, int *request, int *ret);
#pragma weak mpi_iscatterv_ = pmpi_iscatterv_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Iscatterv(void *sendbuf, int *sendcounts, int *displs,
                                 int *sendtype, void *recvbuf, int *recvcount,
                                 int *recvtype, int *root, int *comm,
                                 int *request, int *ret);

void INTERF_2_INTEL_MPI_Iscatterv(void *sendbuf, int *sendcounts, int *displs,
                                  int *sendtype, void *recvbuf, int *recvcount,
                                  int *recvtype, int *root, int *comm,
                                  int *request, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Iscatterv)(            \
    void *sendbuf, int *sendcounts, int *displs, int *sendtype, void *recvbuf, \
    int *recvcount, int *recvtype, int *root, int *comm, int *request,         \
    int *ret);                                                                 \
    void pmpi_iscatterv_(void *sendbuf, int *sendcounts, int *displs,          \
                         int *sendtype, void *recvbuf, int *recvcount,         \
                         int *recvtype, int *root, int *comm, int *request,    \
                         int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Iscatterv(sendbuf, sendcounts, displs, sendtype,
                                         recvbuf, recvcount, recvtype, root,
                                         comm, request);
}

void mpi_iallgatherv_(void *sendbuf, int *sendcount, int *sendtype,
                      void *recvbuf, int *recvcounts, int *displs,
                      int *recvtype, int *comm, int *request, int *ret);
#pragma weak mpi_iallgatherv_ = pmpi_iallgatherv_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Iallgatherv(void *sendbuf, int *sendcount, int *sendtype,
                                   void *recvbuf, int *recvcounts, int *displs,
                                   int *recvtype, int *comm, int *request,
                                   int *ret);

void INTERF_2_INTEL_MPI_Iallgatherv(void *sendbuf, int *sendcount,
                                    int *sendtype, void *recvbuf,
                                    int *recvcounts, int *displs, int *recvtype,
                                    int *comm, int *request, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Iallgatherv)(          \
    void *sendbuf, int *sendcount, int *sendtype, void *recvbuf,               \
    int *recvcounts, int *displs, int *recvtype, int *comm, int *request,      \
    int *ret);                                                                 \
    void pmpi_iallgatherv_(void *sendbuf, int *sendcount, int *sendtype,       \
                           void *recvbuf, int *recvcounts, int *displs,        \
                           int *recvtype, int *comm, int *request, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Iallgatherv(sendbuf, sendcount, sendtype,
                                           recvbuf, recvcounts, displs,
                                           recvtype, comm, request);
}

void mpi_ialltoallv_(void *sendbuf, int *sendcounts, int *sdispls,
                     int *sendtype, void *recvbuf, int *recvcounts,
                     int *rdispls, int *recvtype, int *comm, int *request,
                     int *ret);
#pragma weak mpi_ialltoallv_ = pmpi_ialltoallv_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Ialltoallv(void *sendbuf, int *sendcounts, int *sdispls,
                                  int *sendtype, void *recvbuf, int *recvcounts,
                                  int *rdispls, int *recvtype, int *comm,
                                  int *request, int *ret);

void INTERF_2_INTEL_MPI_Ialltoallv(void *sendbuf, int *sendcounts, int *sdispls,
                                   int *sendtype, void *recvbuf,
                                   int *recvcounts, int *rdispls, int *recvtype,
                                   int *comm, int *request, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Ialltoallv)(           \
    void *sendbuf, int *sendcounts, int *sdispls, int *sendtype,               \
    void *recvbuf, int *recvcounts, int *rdispls, int *recvtype, int *comm,    \
    int *request, int *ret);                                                   \
    void pmpi_ialltoallv_(void *sendbuf, int *sendcounts, int *sdispls,        \
                          int *sendtype, void *recvbuf, int *recvcounts,       \
                          int *rdispls, int *recvtype, int *comm,              \
                          int *request, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Ialltoallv(sendbuf, sendcounts, sdispls,
                                          sendtype, recvbuf, recvcounts,
                                          rdispls, recvtype, comm, request);
}

void mpi_ialltoallw_(void *sendbuf, int *sendcounts, int *sdispls,
                     int *sendtypes, void *recvbuf, int *recvcounts,
                     int *rdispls, int *recvtypes, int *comm, int *request,
                     int *ret);
#pragma weak mpi_ialltoallw_ = pmpi_ialltoallw_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Ialltoallw(void *sendbuf, int *sendcounts, int *sdispls,
                                  int *sendtypes, void *recvbuf,
                                  int *recvcounts, int *rdispls, int *recvtypes,
                                  int *comm, int *request, int *ret);

void INTERF_2_INTEL_MPI_Ialltoallw(void *sendbuf, int *sendcounts, int *sdispls,
                                   int *sendtypes, void *recvbuf,
                                   int *recvcounts, int *rdispls,
                                   int *recvtypes, int *comm, int *request,
                                   int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Ialltoallw)(           \
    void *sendbuf, int *sendcounts, int *sdispls, int *sendtypes,              \
    void *recvbuf, int *recvcounts, int *rdispls, int *recvtypes, int *comm,   \
    int *request, int *ret);                                                   \
    void pmpi_ialltoallw_(void *sendbuf, int *sendcounts, int *sdispls,        \
                          int *sendtypes, void *recvbuf, int *recvcounts,      \
                          int *rdispls, int *recvtypes, int *comm,             \
                          int *request, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Ialltoallw(sendbuf, sendcounts, sdispls,
                                          sendtypes, recvbuf, recvcounts,
                                          rdispls, recvtypes, comm, request);
}

void mpi_ireduce_scatter_(void *sendbuf, void *recvbuf, int *recvcounts,
                          int *datatype, int *op, int *comm, int *request,
                          int *ret);
#pragma weak mpi_ireduce_scatter_ = pmpi_ireduce_scatter_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Ireduce_scatter(void *sendbuf, void *recvbuf,
                                       int *recvcounts, int *datatype, int *op,
                                       int *comm, int *request, int *ret);

void INTERF_2_INTEL_MPI_Ireduce_scatter(void *sendbuf, void *recvbuf,
                                        int *recvcounts, int *datatype, int *op,
                                        int *comm, int *request, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Ireduce_scatter)(      \
    void *sendbuf, void *recvbuf, int *recvcounts, int *datatype, int *op,     \
    int *comm, int *request, int *ret);                                        \
    void pmpi_ireduce_scatter_(void *sendbuf, void *recvbuf, int *recvcounts,  \
                               int *datatype, int *op, int *comm,              \
                               int *request, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Ireduce_scatter(sendbuf, recvbuf, recvcounts,
                                               datatype, op, comm, request);
}

void mpi_ineighbor_allgatherv_(void *sendbuf, int *sendcount, int *sendtype,
                               void *recvbuf, int *recvcounts, int *displs,
                               int *recvtype, int *comm, int *request,
                               int *ret);
#pragma weak mpi_ineighbor_allgatherv_ = pmpi_ineighbor_allgatherv_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Ineighbor_allgatherv(void *sendbuf, int *sendcount,
                                            int *sendtype, void *recvbuf,
                                            int *recvcounts, int *displs,
                                            int *recvtype, int *comm,
                                            int *request, int *ret);

void INTERF_2_INTEL_MPI_Ineighbor_allgatherv(void *sendbuf, int *sendcount,
                                             int *sendtype, void *recvbuf,
                                             int *recvcounts, int *displs,
                                             int *recvtype, int *comm,
                                             int *request, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Ineighbor_allgatherv)( \
    void *sendbuf, int *sendcount, int *sendtype, void *recvbuf,               \
    int *recvcounts, int *displs, int *recvtype, int *comm, int *request,      \
    int *ret);                                                                 \
    void pmpi_ineighbor_allgatherv_(                                           \
        void *sendbuf, int *sendcount, int *sendtype, void *recvbuf,           \
        int *recvcounts, int *displs, int *recvtype, int *comm, int *request,  \
        int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Ineighbor_allgatherv(
      sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm,
      request);
}

void mpi_ineighbor_alltoallv_(void *sendbuf, int *sendcounts, int *sdispls,
                              int *sendtype, void *recvbuf, int *recvcounts,
                              int *rdispls, int *recvtype, int *comm,
                              int *request, int *ret);
#pragma weak mpi_ineighbor_alltoallv_ = pmpi_ineighbor_alltoallv_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Ineighbor_alltoallv(void *sendbuf, int *sendcounts,
                                           int *sdispls, int *sendtype,
                                           void *recvbuf, int *recvcounts,
                                           int *rdispls, int *recvtype,
                                           int *comm, int *request, int *ret);

void INTERF_2_INTEL_MPI_Ineighbor_alltoallv(void *sendbuf, int *sendcounts,
                                            int *sdispls, int *sendtype,
                                            void *recvbuf, int *recvcounts,
                                            int *rdispls, int *recvtype,
                                            int *comm, int *request, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Ineighbor_alltoallv)(  \
    void *sendbuf, int *sendcounts, int *sdispls, int *sendtype,               \
    void *recvbuf, int *recvcounts, int *rdispls, int *recvtype, int *comm,    \
    int *request, int *ret);                                                   \
    void pmpi_ineighbor_alltoallv_(                                            \
        void *sendbuf, int *sendcounts, int *sdispls, int *sendtype,           \
        void *recvbuf, int *recvcounts, int *rdispls, int *recvtype,           \
        int *comm, int *request, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Ineighbor_alltoallv(
      sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls,
      recvtype, comm, request);
}

void mpi_ineighbor_alltoallw_(void *sendbuf, int *sendcounts, size_t sdispls,
                              int *sendtypes, void *recvbuf, int *recvcounts,
                              size_t rdispls, int *recvtypes, int *comm,
                              int *request, int *ret);
#pragma weak mpi_ineighbor_alltoallw_ = pmpi_ineighbor_alltoallw_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Ineighbor_alltoallw(void *sendbuf, int *sendcounts,
                                           size_t sdispls, int *sendtypes,
                                           void *recvbuf, int *recvcounts,
                                           size_t rdispls, int *recvtypes,
                                           int *comm, int *request, int *ret);

void INTERF_2_INTEL_MPI_Ineighbor_alltoallw(void *sendbuf, int *sendcounts,
                                            size_t sdispls, int *sendtypes,
                                            void *recvbuf, int *recvcounts,
                                            size_t rdispls, int *recvtypes,
                                            int *comm, int *request, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Ineighbor_alltoallw)(  \
    void *sendbuf, int *sendcounts, size_t sdispls, int *sendtypes,            \
    void *recvbuf, int *recvcounts, size_t rdispls, int *recvtypes, int *comm, \
    int *request, int *ret);                                                   \
    void pmpi_ineighbor_alltoallw_(                                            \
        void *sendbuf, int *sendcounts, size_t sdispls, int *sendtypes,        \
        void *recvbuf, int *recvcounts, size_t rdispls, int *recvtypes,        \
        int *comm, int *request, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Ineighbor_alltoallw(
      sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls,
      recvtypes, comm, request);
}

void mpi_neighbor_allgatherv_(void *sendbuf, int *sendcount, int *sendtype,
                              void *recvbuf, int *recvcounts, int *displs,
                              int *recvtype, int *comm, int *ret);
#pragma weak mpi_neighbor_allgatherv_ = pmpi_neighbor_allgatherv_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Neighbor_allgatherv(void *sendbuf, int *sendcount,
                                           int *sendtype, void *recvbuf,
                                           int *recvcounts, int *displs,
                                           int *recvtype, int *comm, int *ret);

void INTERF_2_INTEL_MPI_Neighbor_allgatherv(void *sendbuf, int *sendcount,
                                            int *sendtype, void *recvbuf,
                                            int *recvcounts, int *displs,
                                            int *recvtype, int *comm, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Neighbor_allgatherv)(  \
    void *sendbuf, int *sendcount, int *sendtype, void *recvbuf,               \
    int *recvcounts, int *displs, int *recvtype, int *comm, int *ret);         \
    void pmpi_neighbor_allgatherv_(                                            \
        void *sendbuf, int *sendcount, int *sendtype, void *recvbuf,           \
        int *recvcounts, int *displs, int *recvtype, int *comm, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Neighbor_allgatherv(sendbuf, sendcount, sendtype,
                                                   recvbuf, recvcounts, displs,
                                                   recvtype, comm);
}

void mpi_neighbor_alltoallv_(void *sendbuf, int *sendcounts, int *sdispls,
                             int *sendtype, void *recvbuf, int *recvcounts,
                             int *rdispls, int *recvtype, int *comm, int *ret);
#pragma weak mpi_neighbor_alltoallv_ = pmpi_neighbor_alltoallv_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Neighbor_alltoallv(void *sendbuf, int *sendcounts,
                                          int *sdispls, int *sendtype,
                                          void *recvbuf, int *recvcounts,
                                          int *rdispls, int *recvtype,
                                          int *comm, int *ret);

void INTERF_2_INTEL_MPI_Neighbor_alltoallv(void *sendbuf, int *sendcounts,
                                           int *sdispls, int *sendtype,
                                           void *recvbuf, int *recvcounts,
                                           int *rdispls, int *recvtype,
                                           int *comm, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Neighbor_alltoallv)(   \
    void *sendbuf, int *sendcounts, int *sdispls, int *sendtype,               \
    void *recvbuf, int *recvcounts, int *rdispls, int *recvtype, int *comm,    \
    int *ret);                                                                 \
    void pmpi_neighbor_alltoallv_(void *sendbuf, int *sendcounts,              \
                                  int *sdispls, int *sendtype, void *recvbuf,  \
                                  int *recvcounts, int *rdispls,               \
                                  int *recvtype, int *comm, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Neighbor_alltoallv(sendbuf, sendcounts, sdispls,
                                                  sendtype, recvbuf, recvcounts,
                                                  rdispls, recvtype, comm);
}

void mpi_neighbor_alltoallw_(void *sendbuf, int *sendcounts, size_t sdispls,
                             int *sendtypes, void *recvbuf, int *recvcounts,
                             size_t rdispls, int *recvtypes, int *comm,
                             int *ret);
#pragma weak mpi_neighbor_alltoallw_ = pmpi_neighbor_alltoallw_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Neighbor_alltoallw(void *sendbuf, int *sendcounts,
                                          size_t sdispls, int *sendtypes,
                                          void *recvbuf, int *recvcounts,
                                          size_t rdispls, int *recvtypes,
                                          int *comm, int *ret);

void INTERF_2_INTEL_MPI_Neighbor_alltoallw(void *sendbuf, int *sendcounts,
                                           size_t sdispls, int *sendtypes,
                                           void *recvbuf, int *recvcounts,
                                           size_t rdispls, int *recvtypes,
                                           int *comm, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Neighbor_alltoallw)(   \
    void *sendbuf, int *sendcounts, size_t sdispls, int *sendtypes,            \
    void *recvbuf, int *recvcounts, size_t rdispls, int *recvtypes, int *comm, \
    int *ret);                                                                 \
    void pmpi_neighbor_alltoallw_(                                             \
        void *sendbuf, int *sendcounts, size_t sdispls, int *sendtypes,        \
        void *recvbuf, int *recvcounts, size_t rdispls, int *recvtypes,        \
        int *comm, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Neighbor_alltoallw(
      sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls,
      recvtypes, comm);
}

void mpi_file_iwrite_all_(int *fh, void *buf, int *count, int *datatype,
                          int *request, int *ret);
#pragma weak mpi_file_iwrite_all_ = pmpi_file_iwrite_all_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_iwrite_all(int *fh, void *buf, int *count,
                                       int *datatype, int *request, int *ret);

void INTERF_2_INTEL_MPI_File_iwrite_all(int *fh, void *buf, int *count,
                                        int *datatype, int *request, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_iwrite_all)(      \
    int *fh, void *buf, int *count, int *datatype, int *request, int *ret);    \
    void pmpi_file_iwrite_all_(int *fh, void *buf, int *count, int *datatype,  \
                               int *request, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_File_iwrite_all(fh, buf, count, datatype,
                                               request);
}

void mpi_file_iwrite_at_all_(int *fh, int offset, void *buf, int *count,
                             int *datatype, int *request, int *ret);
#pragma weak mpi_file_iwrite_at_all_ = pmpi_file_iwrite_at_all_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_iwrite_at_all(int *fh, int offset, void *buf,
                                          int *count, int *datatype,
                                          int *request, int *ret);

void INTERF_2_INTEL_MPI_File_iwrite_at_all(int *fh, int offset, void *buf,
                                           int *count, int *datatype,
                                           int *request, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_iwrite_at_all)(   \
    int *fh, int offset, void *buf, int *count, int *datatype, int *request,   \
    int *ret);                                                                 \
    void pmpi_file_iwrite_at_all_(int *fh, int offset, void *buf, int *count,  \
                                  int *datatype, int *request, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_File_iwrite_at_all(fh, offset, buf, count,
                                                  datatype, request);
}

void mpi_type_null_copy_fn_(int *oldtype, int *type_keyval, void *extra_state,
                            void *attribute_val_in, void *attribute_val_out,
                            int *flag, int *ret);
#pragma weak mpi_type_null_copy_fn_ = pmpi_type_null_copy_fn_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Type_null_copy_fn(int *oldtype, int *type_keyval,
                                         void *extra_state,
                                         void *attribute_val_in,
                                         void *attribute_val_out, int *flag,
                                         int *ret);

void INTERF_2_INTEL_MPI_Type_null_copy_fn(int *oldtype, int *type_keyval,
                                          void *extra_state,
                                          void *attribute_val_in,
                                          void *attribute_val_out, int *flag,
                                          int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Type_null_copy_fn)(    \
    int *oldtype, int *type_keyval, void *extra_state, void *attribute_val_in, \
    void *attribute_val_out, int *flag, int *ret);                             \
    void pmpi_type_null_copy_fn_(                                              \
        int *oldtype, int *type_keyval, void *extra_state,                     \
        void *attribute_val_in, void *attribute_val_out, int *flag, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Type_null_copy_fn(oldtype, type_keyval,
                                                 extra_state, attribute_val_in,
                                                 attribute_val_out, flag);
}

void mpi_type_null_delete_fn_(int *datatype, int *type_keyval,
                              void *attribute_val, void *extra_state, int *ret);
#pragma weak mpi_type_null_delete_fn_ = pmpi_type_null_delete_fn_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Type_null_delete_fn(int *datatype, int *type_keyval,
                                           void *attribute_val,
                                           void *extra_state, int *ret);

void INTERF_2_INTEL_MPI_Type_null_delete_fn(int *datatype, int *type_keyval,
                                            void *attribute_val,
                                            void *extra_state, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Type_null_delete_fn)(  \
    int *datatype, int *type_keyval, void *attribute_val, void *extra_state,   \
    int *ret);                                                                 \
    void pmpi_type_null_delete_fn_(int *datatype, int *type_keyval,            \
                                   void *attribute_val, void *extra_state,     \
                                   int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Type_null_delete_fn(datatype, type_keyval,
                                                   attribute_val, extra_state);
}

size_t mpi_aint_add_(size_t base, size_t disp);
#pragma weak mpi_aint_add_ = pmpi_aint_add_

#ifdef WI4MPI_STATIC

size_t INTERF_2_OMPI_MPI_Aint_add(size_t base, size_t disp);

size_t INTERF_2_INTEL_MPI_Aint_add(size_t base, size_t disp);

#endif /* WI4MPI_STATIC */ size_t (*INTERFACE_F_LOCAL_MPI_Aint_add)(           \
    size_t base, size_t disp);                                                 \
    size_t pmpi_aint_add_(size_t base, size_t disp);
{ return INTERFACE_F_LOCAL_MPI_Aint_add(base, disp); }

size_t mpi_aint_diff_(size_t addr1, size_t addr2);
#pragma weak mpi_aint_diff_ = pmpi_aint_diff_

#ifdef WI4MPI_STATIC

size_t INTERF_2_OMPI_MPI_Aint_diff(size_t addr1, size_t addr2);

size_t INTERF_2_INTEL_MPI_Aint_diff(size_t addr1, size_t addr2);

#endif /* WI4MPI_STATIC */ size_t (*INTERFACE_F_LOCAL_MPI_Aint_diff)(          \
    size_t addr1, size_t addr2);                                               \
    size_t pmpi_aint_diff_(size_t addr1, size_t addr2);
{ return INTERFACE_F_LOCAL_MPI_Aint_diff(addr1, addr2); }

void mpi_conversion_fn_null_(void *userbuf, int *datatype, int *count,
                             void *filebuf, int position, void *extra_state,
                             int *ret);
#pragma weak mpi_conversion_fn_null_ = pmpi_conversion_fn_null_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Conversion_fn_null(void *userbuf, int *datatype,
                                          int *count, void *filebuf,
                                          int position, void *extra_state,
                                          int *ret);

void INTERF_2_INTEL_MPI_Conversion_fn_null(void *userbuf, int *datatype,
                                           int *count, void *filebuf,
                                           int position, void *extra_state,
                                           int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Conversion_fn_null)(   \
    void *userbuf, int *datatype, int *count, void *filebuf, int position,     \
    void *extra_state, int *ret);                                              \
    void pmpi_conversion_fn_null_(void *userbuf, int *datatype, int *count,    \
                                  void *filebuf, int position,                 \
                                  void *extra_state, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Conversion_fn_null(
      userbuf, datatype, count, filebuf, position, extra_state);
}

void mpi_dup_fn_(int *oldcomm, int *keyval, void *extra_state,
                 void *attribute_val_in, void *attribute_val_out, int *flag,
                 int *ret);
#pragma weak mpi_dup_fn_ = pmpi_dup_fn_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_Dup_fn(int *oldcomm, int *keyval, void *extra_state,
                              void *attribute_val_in, void *attribute_val_out,
                              int *flag, int *ret);

void INTERF_2_INTEL_MPI_Dup_fn(int *oldcomm, int *keyval, void *extra_state,
                               void *attribute_val_in, void *attribute_val_out,
                               int *flag, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_Dup_fn)(               \
    int *oldcomm, int *keyval, void *extra_state, void *attribute_val_in,      \
    void *attribute_val_out, int *flag, int *ret);                             \
    void pmpi_dup_fn_(int *oldcomm, int *keyval, void *extra_state,            \
                      void *attribute_val_in, void *attribute_val_out,         \
                      int *flag, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_Dup_fn(
      oldcomm, keyval, extra_state, attribute_val_in, attribute_val_out, flag);
}

void mpi_file_iread_all_(int *fh, void *buf, int *count, int *datatype,
                         int *request, int *ret);
#pragma weak mpi_file_iread_all_ = pmpi_file_iread_all_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_iread_all(int *fh, void *buf, int *count,
                                      int *datatype, int *request, int *ret);

void INTERF_2_INTEL_MPI_File_iread_all(int *fh, void *buf, int *count,
                                       int *datatype, int *request, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_iread_all)(       \
    int *fh, void *buf, int *count, int *datatype, int *request, int *ret);    \
    void pmpi_file_iread_all_(int *fh, void *buf, int *count, int *datatype,   \
                              int *request, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_File_iread_all(fh, buf, count, datatype,
                                              request);
}

void mpi_file_iread_at_all_(int *fh, int offset, void *buf, int *count,
                            int *datatype, int *request, int *ret);
#pragma weak mpi_file_iread_at_all_ = pmpi_file_iread_at_all_

#ifdef WI4MPI_STATIC

void INTERF_2_OMPI_MPI_File_iread_at_all(int *fh, int offset, void *buf,
                                         int *count, int *datatype,
                                         int *request, int *ret);

void INTERF_2_INTEL_MPI_File_iread_at_all(int *fh, int offset, void *buf,
                                          int *count, int *datatype,
                                          int *request, int *ret);

#endif /* WI4MPI_STATIC */ void (*INTERFACE_F_LOCAL_MPI_File_iread_at_all)(    \
    int *fh, int offset, void *buf, int *count, int *datatype, int *request,   \
    int *ret);                                                                 \
    void pmpi_file_iread_at_all_(int *fh, int offset, void *buf, int *count,   \
                                 int *datatype, int *request, int *ret);
{
  return INTERFACE_F_LOCAL_MPI_File_iread_at_all(fh, offset, buf, count,
                                                 datatype, request);
}

extern int wi4mpi__init__C;
int wi4mpi__init__F = 0;
__attribute__((constructor)) void wrapper_interface_f(void) {
  if (wi4mpi__init__F != 0)
    return;
  wi4mpi__init__F = 1;
  if (wi4mpi__init__C == 0)
    wrapper_interface();
#ifndef WI4MPI_STATIC
#define to_string(name) #name
#define handle_loader(name)                                                    \
  INTERFACE_F_LOCAL_##name = dlsym(interface_handle, to_string(CC##name))

#else
#define handle_loader(name, MPI_TARGET)                                        \
  INTERFACE_F_LOCAL_##name = MPI_TARGET##name

#endif /*WI4MPI_STATIC*/
#ifndef WI4MPI_STATIC
  void *interface_handle_f;
  if (getenv("WI4MPI_WRAPPER_LIB") != NULL) {
    interface_handle_f =
        dlopen(getenv("WI4MPI_WRAPPER_LIB"), RTLD_NOW | RTLD_GLOBAL);
  } else {
    if (strcmp(wi4mpi_mode_f, "") != 0) {
      interface_handle_f = dlopen(wi4mpi_mode_f, RTLD_NOW | RTLD_GLOBAL);
    } else {
      fprintf(stderr, "Please provide either WI4MPI_WRAPPER_LIB environment or "
                      "compile with -wi4mpi_default_run_paths\n");
      exit(1);
    }
  }
  if (!interface_handle_f) {
    printf("Dlopen failed to open WI4MPI librarie.\nerror :%s\n", dlerror());
    exit(1);
  }

  INTERF_F_LOCAL_MPI_Pcontrol = dlsym(interface_handle_f, "A_f_MPI_Pcontrol");

  INTERF_F_LOCAL_MPI_Send = dlsym(interface_handle_f, "A_f_MPI_Send");

  INTERF_F_LOCAL_MPI_Recv = dlsym(interface_handle_f, "A_f_MPI_Recv");

  INTERF_F_LOCAL_MPI_Get_count = dlsym(interface_handle_f, "A_f_MPI_Get_count");

  INTERF_F_LOCAL_MPI_Bsend = dlsym(interface_handle_f, "A_f_MPI_Bsend");

  INTERF_F_LOCAL_MPI_Ssend = dlsym(interface_handle_f, "A_f_MPI_Ssend");

  INTERF_F_LOCAL_MPI_Rsend = dlsym(interface_handle_f, "A_f_MPI_Rsend");

  INTERF_F_LOCAL_MPI_Buffer_attach =
      dlsym(interface_handle_f, "A_f_MPI_Buffer_attach");

  INTERF_F_LOCAL_MPI_Buffer_detach =
      dlsym(interface_handle_f, "A_f_MPI_Buffer_detach");

  INTERF_F_LOCAL_MPI_Isend = dlsym(interface_handle_f, "A_f_MPI_Isend");

  INTERF_F_LOCAL_MPI_Ibsend = dlsym(interface_handle_f, "A_f_MPI_Ibsend");

  INTERF_F_LOCAL_MPI_Issend = dlsym(interface_handle_f, "A_f_MPI_Issend");

  INTERF_F_LOCAL_MPI_Irsend = dlsym(interface_handle_f, "A_f_MPI_Irsend");

  INTERF_F_LOCAL_MPI_Irecv = dlsym(interface_handle_f, "A_f_MPI_Irecv");

  INTERF_F_LOCAL_MPI_Wait = dlsym(interface_handle_f, "A_f_MPI_Wait");

  INTERF_F_LOCAL_MPI_Test = dlsym(interface_handle_f, "A_f_MPI_Test");

  INTERF_F_LOCAL_MPI_Request_free =
      dlsym(interface_handle_f, "A_f_MPI_Request_free");

  INTERF_F_LOCAL_MPI_Iprobe = dlsym(interface_handle_f, "A_f_MPI_Iprobe");

  INTERF_F_LOCAL_MPI_Probe = dlsym(interface_handle_f, "A_f_MPI_Probe");

  INTERF_F_LOCAL_MPI_Cancel = dlsym(interface_handle_f, "A_f_MPI_Cancel");

  INTERF_F_LOCAL_MPI_Test_cancelled =
      dlsym(interface_handle_f, "A_f_MPI_Test_cancelled");

  INTERF_F_LOCAL_MPI_Send_init = dlsym(interface_handle_f, "A_f_MPI_Send_init");

  INTERF_F_LOCAL_MPI_Bsend_init =
      dlsym(interface_handle_f, "A_f_MPI_Bsend_init");

  INTERF_F_LOCAL_MPI_Ssend_init =
      dlsym(interface_handle_f, "A_f_MPI_Ssend_init");

  INTERF_F_LOCAL_MPI_Rsend_init =
      dlsym(interface_handle_f, "A_f_MPI_Rsend_init");

  INTERF_F_LOCAL_MPI_Recv_init = dlsym(interface_handle_f, "A_f_MPI_Recv_init");

  INTERF_F_LOCAL_MPI_Start = dlsym(interface_handle_f, "A_f_MPI_Start");

  INTERF_F_LOCAL_MPI_Sendrecv = dlsym(interface_handle_f, "A_f_MPI_Sendrecv");

  INTERF_F_LOCAL_MPI_Sendrecv_replace =
      dlsym(interface_handle_f, "A_f_MPI_Sendrecv_replace");

  INTERF_F_LOCAL_MPI_Type_contiguous =
      dlsym(interface_handle_f, "A_f_MPI_Type_contiguous");

  INTERF_F_LOCAL_MPI_Type_vector =
      dlsym(interface_handle_f, "A_f_MPI_Type_vector");

  INTERF_F_LOCAL_MPI_Type_hvector =
      dlsym(interface_handle_f, "A_f_MPI_Type_hvector");

  INTERF_F_LOCAL_MPI_Type_indexed =
      dlsym(interface_handle_f, "A_f_MPI_Type_indexed");

  INTERF_F_LOCAL_MPI_Type_hindexed =
      dlsym(interface_handle_f, "A_f_MPI_Type_hindexed");

  INTERF_F_LOCAL_MPI_Type_struct =
      dlsym(interface_handle_f, "A_f_MPI_Type_struct");

  INTERF_F_LOCAL_MPI_Address = dlsym(interface_handle_f, "A_f_MPI_Address");

  INTERF_F_LOCAL_MPI_Type_extent =
      dlsym(interface_handle_f, "A_f_MPI_Type_extent");

  INTERF_F_LOCAL_MPI_Type_size = dlsym(interface_handle_f, "A_f_MPI_Type_size");

  INTERF_F_LOCAL_MPI_Type_lb = dlsym(interface_handle_f, "A_f_MPI_Type_lb");

  INTERF_F_LOCAL_MPI_Type_ub = dlsym(interface_handle_f, "A_f_MPI_Type_ub");

  INTERF_F_LOCAL_MPI_Type_commit =
      dlsym(interface_handle_f, "A_f_MPI_Type_commit");

  INTERF_F_LOCAL_MPI_Type_free = dlsym(interface_handle_f, "A_f_MPI_Type_free");

  INTERF_F_LOCAL_MPI_Get_elements =
      dlsym(interface_handle_f, "A_f_MPI_Get_elements");

  INTERF_F_LOCAL_MPI_Pack = dlsym(interface_handle_f, "A_f_MPI_Pack");

  INTERF_F_LOCAL_MPI_Unpack = dlsym(interface_handle_f, "A_f_MPI_Unpack");

  INTERF_F_LOCAL_MPI_Pack_size = dlsym(interface_handle_f, "A_f_MPI_Pack_size");

  INTERF_F_LOCAL_MPI_Barrier = dlsym(interface_handle_f, "A_f_MPI_Barrier");

  INTERF_F_LOCAL_MPI_Bcast = dlsym(interface_handle_f, "A_f_MPI_Bcast");

  INTERF_F_LOCAL_MPI_Gather = dlsym(interface_handle_f, "A_f_MPI_Gather");

  INTERF_F_LOCAL_MPI_Gatherv = dlsym(interface_handle_f, "A_f_MPI_Gatherv");

  INTERF_F_LOCAL_MPI_Scatter = dlsym(interface_handle_f, "A_f_MPI_Scatter");

  INTERF_F_LOCAL_MPI_Scatterv = dlsym(interface_handle_f, "A_f_MPI_Scatterv");

  INTERF_F_LOCAL_MPI_Allgather = dlsym(interface_handle_f, "A_f_MPI_Allgather");

  INTERF_F_LOCAL_MPI_Allgatherv =
      dlsym(interface_handle_f, "A_f_MPI_Allgatherv");

  INTERF_F_LOCAL_MPI_Alltoall = dlsym(interface_handle_f, "A_f_MPI_Alltoall");

  INTERF_F_LOCAL_MPI_Alltoallv = dlsym(interface_handle_f, "A_f_MPI_Alltoallv");

  INTERF_F_LOCAL_MPI_Exscan = dlsym(interface_handle_f, "A_f_MPI_Exscan");

  INTERF_F_LOCAL_MPI_Reduce = dlsym(interface_handle_f, "A_f_MPI_Reduce");

  INTERF_F_LOCAL_MPI_Op_create = dlsym(interface_handle_f, "A_f_MPI_Op_create");

  INTERF_F_LOCAL_MPI_Op_free = dlsym(interface_handle_f, "A_f_MPI_Op_free");

  INTERF_F_LOCAL_MPI_Allreduce = dlsym(interface_handle_f, "A_f_MPI_Allreduce");

  INTERF_F_LOCAL_MPI_Scan = dlsym(interface_handle_f, "A_f_MPI_Scan");

  INTERF_F_LOCAL_MPI_Group_size =
      dlsym(interface_handle_f, "A_f_MPI_Group_size");

  INTERF_F_LOCAL_MPI_Group_rank =
      dlsym(interface_handle_f, "A_f_MPI_Group_rank");

  INTERF_F_LOCAL_MPI_Group_compare =
      dlsym(interface_handle_f, "A_f_MPI_Group_compare");

  INTERF_F_LOCAL_MPI_Comm_group =
      dlsym(interface_handle_f, "A_f_MPI_Comm_group");

  INTERF_F_LOCAL_MPI_Group_union =
      dlsym(interface_handle_f, "A_f_MPI_Group_union");

  INTERF_F_LOCAL_MPI_Group_intersection =
      dlsym(interface_handle_f, "A_f_MPI_Group_intersection");

  INTERF_F_LOCAL_MPI_Group_difference =
      dlsym(interface_handle_f, "A_f_MPI_Group_difference");

  INTERF_F_LOCAL_MPI_Group_free =
      dlsym(interface_handle_f, "A_f_MPI_Group_free");

  INTERF_F_LOCAL_MPI_Comm_size = dlsym(interface_handle_f, "A_f_MPI_Comm_size");

  INTERF_F_LOCAL_MPI_Comm_rank = dlsym(interface_handle_f, "A_f_MPI_Comm_rank");

  INTERF_F_LOCAL_MPI_Comm_compare =
      dlsym(interface_handle_f, "A_f_MPI_Comm_compare");

  INTERF_F_LOCAL_MPI_Comm_dup = dlsym(interface_handle_f, "A_f_MPI_Comm_dup");

  INTERF_F_LOCAL_MPI_Comm_dup_with_info =
      dlsym(interface_handle_f, "A_f_MPI_Comm_dup_with_info");

  INTERF_F_LOCAL_MPI_Comm_create =
      dlsym(interface_handle_f, "A_f_MPI_Comm_create");

  INTERF_F_LOCAL_MPI_Comm_split =
      dlsym(interface_handle_f, "A_f_MPI_Comm_split");

  INTERF_F_LOCAL_MPI_Comm_free = dlsym(interface_handle_f, "A_f_MPI_Comm_free");

  INTERF_F_LOCAL_MPI_Comm_test_inter =
      dlsym(interface_handle_f, "A_f_MPI_Comm_test_inter");

  INTERF_F_LOCAL_MPI_Comm_remote_size =
      dlsym(interface_handle_f, "A_f_MPI_Comm_remote_size");

  INTERF_F_LOCAL_MPI_Comm_remote_group =
      dlsym(interface_handle_f, "A_f_MPI_Comm_remote_group");

  INTERF_F_LOCAL_MPI_Intercomm_create =
      dlsym(interface_handle_f, "A_f_MPI_Intercomm_create");

  INTERF_F_LOCAL_MPI_Intercomm_merge =
      dlsym(interface_handle_f, "A_f_MPI_Intercomm_merge");

  INTERF_F_LOCAL_MPI_Keyval_create =
      dlsym(interface_handle_f, "A_f_MPI_Keyval_create");

  INTERF_F_LOCAL_MPI_Keyval_free =
      dlsym(interface_handle_f, "A_f_MPI_Keyval_free");

  INTERF_F_LOCAL_MPI_Attr_put = dlsym(interface_handle_f, "A_f_MPI_Attr_put");

  INTERF_F_LOCAL_MPI_Attr_get = dlsym(interface_handle_f, "A_f_MPI_Attr_get");

  INTERF_F_LOCAL_MPI_Attr_delete =
      dlsym(interface_handle_f, "A_f_MPI_Attr_delete");

  INTERF_F_LOCAL_MPI_Topo_test = dlsym(interface_handle_f, "A_f_MPI_Topo_test");

  INTERF_F_LOCAL_MPI_Graphdims_get =
      dlsym(interface_handle_f, "A_f_MPI_Graphdims_get");

  INTERF_F_LOCAL_MPI_Cartdim_get =
      dlsym(interface_handle_f, "A_f_MPI_Cartdim_get");

  INTERF_F_LOCAL_MPI_Graph_neighbors_count =
      dlsym(interface_handle_f, "A_f_MPI_Graph_neighbors_count");

  INTERF_F_LOCAL_MPI_Cart_shift =
      dlsym(interface_handle_f, "A_f_MPI_Cart_shift");

  INTERF_F_LOCAL_MPI_Get_processor_name =
      dlsym(interface_handle_f, "A_f_MPI_Get_processor_name");

  INTERF_F_LOCAL_MPI_Get_version =
      dlsym(interface_handle_f, "A_f_MPI_Get_version");

  INTERF_F_LOCAL_MPI_Get_library_version =
      dlsym(interface_handle_f, "A_f_MPI_Get_library_version");

  INTERF_F_LOCAL_MPI_Errhandler_create =
      dlsym(interface_handle_f, "A_f_MPI_Errhandler_create");

  INTERF_F_LOCAL_MPI_Errhandler_set =
      dlsym(interface_handle_f, "A_f_MPI_Errhandler_set");

  INTERF_F_LOCAL_MPI_Errhandler_get =
      dlsym(interface_handle_f, "A_f_MPI_Errhandler_get");

  INTERF_F_LOCAL_MPI_Errhandler_free =
      dlsym(interface_handle_f, "A_f_MPI_Errhandler_free");

  INTERF_F_LOCAL_MPI_Error_string =
      dlsym(interface_handle_f, "A_f_MPI_Error_string");

  INTERF_F_LOCAL_MPI_Error_class =
      dlsym(interface_handle_f, "A_f_MPI_Error_class");

  INTERF_F_LOCAL_MPI_Initialized =
      dlsym(interface_handle_f, "A_f_MPI_Initialized");

  INTERF_F_LOCAL_MPI_Abort = dlsym(interface_handle_f, "A_f_MPI_Abort");

  INTERF_F_LOCAL_MPI_Init = dlsym(interface_handle_f, "A_f_MPI_Init");

  INTERF_F_LOCAL_MPI_Close_port =
      dlsym(interface_handle_f, "A_f_MPI_Close_port");

  INTERF_F_LOCAL_MPI_Comm_accept =
      dlsym(interface_handle_f, "A_f_MPI_Comm_accept");

  INTERF_F_LOCAL_MPI_Comm_connect =
      dlsym(interface_handle_f, "A_f_MPI_Comm_connect");

  INTERF_F_LOCAL_MPI_Comm_disconnect =
      dlsym(interface_handle_f, "A_f_MPI_Comm_disconnect");

  INTERF_F_LOCAL_MPI_Comm_get_parent =
      dlsym(interface_handle_f, "A_f_MPI_Comm_get_parent");

  INTERF_F_LOCAL_MPI_Comm_join = dlsym(interface_handle_f, "A_f_MPI_Comm_join");

  INTERF_F_LOCAL_MPI_Lookup_name =
      dlsym(interface_handle_f, "A_f_MPI_Lookup_name");

  INTERF_F_LOCAL_MPI_Open_port = dlsym(interface_handle_f, "A_f_MPI_Open_port");

  INTERF_F_LOCAL_MPI_Publish_name =
      dlsym(interface_handle_f, "A_f_MPI_Publish_name");

  INTERF_F_LOCAL_MPI_Unpublish_name =
      dlsym(interface_handle_f, "A_f_MPI_Unpublish_name");

  INTERF_F_LOCAL_MPI_Comm_set_info =
      dlsym(interface_handle_f, "A_f_MPI_Comm_set_info");

  INTERF_F_LOCAL_MPI_Comm_get_info =
      dlsym(interface_handle_f, "A_f_MPI_Comm_get_info");

  INTERF_F_LOCAL_MPI_Accumulate =
      dlsym(interface_handle_f, "A_f_MPI_Accumulate");

  INTERF_F_LOCAL_MPI_Get = dlsym(interface_handle_f, "A_f_MPI_Get");

  INTERF_F_LOCAL_MPI_Put = dlsym(interface_handle_f, "A_f_MPI_Put");

  INTERF_F_LOCAL_MPI_Win_complete =
      dlsym(interface_handle_f, "A_f_MPI_Win_complete");

  INTERF_F_LOCAL_MPI_Win_create =
      dlsym(interface_handle_f, "A_f_MPI_Win_create");

  INTERF_F_LOCAL_MPI_Win_fence = dlsym(interface_handle_f, "A_f_MPI_Win_fence");

  INTERF_F_LOCAL_MPI_Win_free = dlsym(interface_handle_f, "A_f_MPI_Win_free");

  INTERF_F_LOCAL_MPI_Win_get_group =
      dlsym(interface_handle_f, "A_f_MPI_Win_get_group");

  INTERF_F_LOCAL_MPI_Win_lock = dlsym(interface_handle_f, "A_f_MPI_Win_lock");

  INTERF_F_LOCAL_MPI_Win_post = dlsym(interface_handle_f, "A_f_MPI_Win_post");

  INTERF_F_LOCAL_MPI_Win_start = dlsym(interface_handle_f, "A_f_MPI_Win_start");

  INTERF_F_LOCAL_MPI_Win_test = dlsym(interface_handle_f, "A_f_MPI_Win_test");

  INTERF_F_LOCAL_MPI_Win_unlock =
      dlsym(interface_handle_f, "A_f_MPI_Win_unlock");

  INTERF_F_LOCAL_MPI_Win_wait = dlsym(interface_handle_f, "A_f_MPI_Win_wait");

  INTERF_F_LOCAL_MPI_Win_allocate =
      dlsym(interface_handle_f, "A_f_MPI_Win_allocate");

  INTERF_F_LOCAL_MPI_Win_allocate_shared =
      dlsym(interface_handle_f, "A_f_MPI_Win_allocate_shared");

  INTERF_F_LOCAL_MPI_Win_shared_query =
      dlsym(interface_handle_f, "A_f_MPI_Win_shared_query");

  INTERF_F_LOCAL_MPI_Win_create_dynamic =
      dlsym(interface_handle_f, "A_f_MPI_Win_create_dynamic");

  INTERF_F_LOCAL_MPI_Win_attach =
      dlsym(interface_handle_f, "A_f_MPI_Win_attach");

  INTERF_F_LOCAL_MPI_Win_detach =
      dlsym(interface_handle_f, "A_f_MPI_Win_detach");

  INTERF_F_LOCAL_MPI_Win_get_info =
      dlsym(interface_handle_f, "A_f_MPI_Win_get_info");

  INTERF_F_LOCAL_MPI_Win_set_info =
      dlsym(interface_handle_f, "A_f_MPI_Win_set_info");

  INTERF_F_LOCAL_MPI_Get_accumulate =
      dlsym(interface_handle_f, "A_f_MPI_Get_accumulate");

  INTERF_F_LOCAL_MPI_Fetch_and_op =
      dlsym(interface_handle_f, "A_f_MPI_Fetch_and_op");

  INTERF_F_LOCAL_MPI_Compare_and_swap =
      dlsym(interface_handle_f, "A_f_MPI_Compare_and_swap");

  INTERF_F_LOCAL_MPI_Rput = dlsym(interface_handle_f, "A_f_MPI_Rput");

  INTERF_F_LOCAL_MPI_Rget = dlsym(interface_handle_f, "A_f_MPI_Rget");

  INTERF_F_LOCAL_MPI_Raccumulate =
      dlsym(interface_handle_f, "A_f_MPI_Raccumulate");

  INTERF_F_LOCAL_MPI_Rget_accumulate =
      dlsym(interface_handle_f, "A_f_MPI_Rget_accumulate");

  INTERF_F_LOCAL_MPI_Win_lock_all =
      dlsym(interface_handle_f, "A_f_MPI_Win_lock_all");

  INTERF_F_LOCAL_MPI_Win_unlock_all =
      dlsym(interface_handle_f, "A_f_MPI_Win_unlock_all");

  INTERF_F_LOCAL_MPI_Win_flush = dlsym(interface_handle_f, "A_f_MPI_Win_flush");

  INTERF_F_LOCAL_MPI_Win_flush_all =
      dlsym(interface_handle_f, "A_f_MPI_Win_flush_all");

  INTERF_F_LOCAL_MPI_Win_flush_local =
      dlsym(interface_handle_f, "A_f_MPI_Win_flush_local");

  INTERF_F_LOCAL_MPI_Win_flush_local_all =
      dlsym(interface_handle_f, "A_f_MPI_Win_flush_local_all");

  INTERF_F_LOCAL_MPI_Win_sync = dlsym(interface_handle_f, "A_f_MPI_Win_sync");

  INTERF_F_LOCAL_MPI_Add_error_class =
      dlsym(interface_handle_f, "A_f_MPI_Add_error_class");

  INTERF_F_LOCAL_MPI_Add_error_code =
      dlsym(interface_handle_f, "A_f_MPI_Add_error_code");

  INTERF_F_LOCAL_MPI_Add_error_string =
      dlsym(interface_handle_f, "A_f_MPI_Add_error_string");

  INTERF_F_LOCAL_MPI_Comm_call_errhandler =
      dlsym(interface_handle_f, "A_f_MPI_Comm_call_errhandler");

  INTERF_F_LOCAL_MPI_Comm_create_keyval =
      dlsym(interface_handle_f, "A_f_MPI_Comm_create_keyval");

  INTERF_F_LOCAL_MPI_Comm_delete_attr =
      dlsym(interface_handle_f, "A_f_MPI_Comm_delete_attr");

  INTERF_F_LOCAL_MPI_Comm_free_keyval =
      dlsym(interface_handle_f, "A_f_MPI_Comm_free_keyval");

  INTERF_F_LOCAL_MPI_Comm_get_attr =
      dlsym(interface_handle_f, "A_f_MPI_Comm_get_attr");

  INTERF_F_LOCAL_MPI_Comm_get_name =
      dlsym(interface_handle_f, "A_f_MPI_Comm_get_name");

  INTERF_F_LOCAL_MPI_Comm_set_attr =
      dlsym(interface_handle_f, "A_f_MPI_Comm_set_attr");

  INTERF_F_LOCAL_MPI_Comm_set_name =
      dlsym(interface_handle_f, "A_f_MPI_Comm_set_name");

  INTERF_F_LOCAL_MPI_Grequest_complete =
      dlsym(interface_handle_f, "A_f_MPI_Grequest_complete");

  INTERF_F_LOCAL_MPI_Grequest_start =
      dlsym(interface_handle_f, "A_f_MPI_Grequest_start");

  INTERF_F_LOCAL_MPI_Init_thread =
      dlsym(interface_handle_f, "A_f_MPI_Init_thread");

  INTERF_F_LOCAL_MPI_Is_thread_main =
      dlsym(interface_handle_f, "A_f_MPI_Is_thread_main");

  INTERF_F_LOCAL_MPI_Query_thread =
      dlsym(interface_handle_f, "A_f_MPI_Query_thread");

  INTERF_F_LOCAL_MPI_Status_set_cancelled =
      dlsym(interface_handle_f, "A_f_MPI_Status_set_cancelled");

  INTERF_F_LOCAL_MPI_Status_set_elements =
      dlsym(interface_handle_f, "A_f_MPI_Status_set_elements");

  INTERF_F_LOCAL_MPI_Type_create_keyval =
      dlsym(interface_handle_f, "A_f_MPI_Type_create_keyval");

  INTERF_F_LOCAL_MPI_Type_delete_attr =
      dlsym(interface_handle_f, "A_f_MPI_Type_delete_attr");

  INTERF_F_LOCAL_MPI_Type_dup = dlsym(interface_handle_f, "A_f_MPI_Type_dup");

  INTERF_F_LOCAL_MPI_Type_free_keyval =
      dlsym(interface_handle_f, "A_f_MPI_Type_free_keyval");

  INTERF_F_LOCAL_MPI_Type_get_attr =
      dlsym(interface_handle_f, "A_f_MPI_Type_get_attr");

  INTERF_F_LOCAL_MPI_Type_get_envelope =
      dlsym(interface_handle_f, "A_f_MPI_Type_get_envelope");

  INTERF_F_LOCAL_MPI_Type_get_name =
      dlsym(interface_handle_f, "A_f_MPI_Type_get_name");

  INTERF_F_LOCAL_MPI_Type_set_attr =
      dlsym(interface_handle_f, "A_f_MPI_Type_set_attr");

  INTERF_F_LOCAL_MPI_Type_set_name =
      dlsym(interface_handle_f, "A_f_MPI_Type_set_name");

  INTERF_F_LOCAL_MPI_Type_match_size =
      dlsym(interface_handle_f, "A_f_MPI_Type_match_size");

  INTERF_F_LOCAL_MPI_Win_create_keyval =
      dlsym(interface_handle_f, "A_f_MPI_Win_create_keyval");

  INTERF_F_LOCAL_MPI_Win_delete_attr =
      dlsym(interface_handle_f, "A_f_MPI_Win_delete_attr");

  INTERF_F_LOCAL_MPI_Win_free_keyval =
      dlsym(interface_handle_f, "A_f_MPI_Win_free_keyval");

  INTERF_F_LOCAL_MPI_Win_get_attr =
      dlsym(interface_handle_f, "A_f_MPI_Win_get_attr");

  INTERF_F_LOCAL_MPI_Win_get_name =
      dlsym(interface_handle_f, "A_f_MPI_Win_get_name");

  INTERF_F_LOCAL_MPI_Win_set_name =
      dlsym(interface_handle_f, "A_f_MPI_Win_set_name");

  INTERF_F_LOCAL_MPI_Alloc_mem = dlsym(interface_handle_f, "A_f_MPI_Alloc_mem");

  INTERF_F_LOCAL_MPI_Comm_create_errhandler =
      dlsym(interface_handle_f, "A_f_MPI_Comm_create_errhandler");

  INTERF_F_LOCAL_MPI_Comm_get_errhandler =
      dlsym(interface_handle_f, "A_f_MPI_Comm_get_errhandler");

  INTERF_F_LOCAL_MPI_Comm_set_errhandler =
      dlsym(interface_handle_f, "A_f_MPI_Comm_set_errhandler");

  INTERF_F_LOCAL_MPI_File_create_errhandler =
      dlsym(interface_handle_f, "A_f_MPI_File_create_errhandler");

  INTERF_F_LOCAL_MPI_File_get_errhandler =
      dlsym(interface_handle_f, "A_f_MPI_File_get_errhandler");

  INTERF_F_LOCAL_MPI_File_set_errhandler =
      dlsym(interface_handle_f, "A_f_MPI_File_set_errhandler");

  INTERF_F_LOCAL_MPI_Finalized = dlsym(interface_handle_f, "A_f_MPI_Finalized");

  INTERF_F_LOCAL_MPI_Free_mem = dlsym(interface_handle_f, "A_f_MPI_Free_mem");

  INTERF_F_LOCAL_MPI_Get_address =
      dlsym(interface_handle_f, "A_f_MPI_Get_address");

  INTERF_F_LOCAL_MPI_Info_create =
      dlsym(interface_handle_f, "A_f_MPI_Info_create");

  INTERF_F_LOCAL_MPI_Info_delete =
      dlsym(interface_handle_f, "A_f_MPI_Info_delete");

  INTERF_F_LOCAL_MPI_Info_dup = dlsym(interface_handle_f, "A_f_MPI_Info_dup");

  INTERF_F_LOCAL_MPI_Info_free = dlsym(interface_handle_f, "A_f_MPI_Info_free");

  INTERF_F_LOCAL_MPI_Info_get = dlsym(interface_handle_f, "A_f_MPI_Info_get");

  INTERF_F_LOCAL_MPI_Info_get_nkeys =
      dlsym(interface_handle_f, "A_f_MPI_Info_get_nkeys");

  INTERF_F_LOCAL_MPI_Info_get_nthkey =
      dlsym(interface_handle_f, "A_f_MPI_Info_get_nthkey");

  INTERF_F_LOCAL_MPI_Info_get_valuelen =
      dlsym(interface_handle_f, "A_f_MPI_Info_get_valuelen");

  INTERF_F_LOCAL_MPI_Info_set = dlsym(interface_handle_f, "A_f_MPI_Info_set");

  INTERF_F_LOCAL_MPI_Request_get_status =
      dlsym(interface_handle_f, "A_f_MPI_Request_get_status");

  INTERF_F_LOCAL_MPI_Type_create_hvector =
      dlsym(interface_handle_f, "A_f_MPI_Type_create_hvector");

  INTERF_F_LOCAL_MPI_Type_create_resized =
      dlsym(interface_handle_f, "A_f_MPI_Type_create_resized");

  INTERF_F_LOCAL_MPI_Type_get_extent =
      dlsym(interface_handle_f, "A_f_MPI_Type_get_extent");

  INTERF_F_LOCAL_MPI_Type_get_true_extent =
      dlsym(interface_handle_f, "A_f_MPI_Type_get_true_extent");

  INTERF_F_LOCAL_MPI_Win_get_errhandler =
      dlsym(interface_handle_f, "A_f_MPI_Win_get_errhandler");

  INTERF_F_LOCAL_MPI_Type_create_f90_integer =
      dlsym(interface_handle_f, "A_f_MPI_Type_create_f90_integer");

  INTERF_F_LOCAL_MPI_Type_create_f90_real =
      dlsym(interface_handle_f, "A_f_MPI_Type_create_f90_real");

  INTERF_F_LOCAL_MPI_Type_create_f90_complex =
      dlsym(interface_handle_f, "A_f_MPI_Type_create_f90_complex");

  INTERF_F_LOCAL_MPI_Reduce_local =
      dlsym(interface_handle_f, "A_f_MPI_Reduce_local");

  INTERF_F_LOCAL_MPI_Op_commutative =
      dlsym(interface_handle_f, "A_f_MPI_Op_commutative");

  INTERF_F_LOCAL_MPI_Reduce_scatter_block =
      dlsym(interface_handle_f, "A_f_MPI_Reduce_scatter_block");

  INTERF_F_LOCAL_MPI_Dist_graph_neighbors_count =
      dlsym(interface_handle_f, "A_f_MPI_Dist_graph_neighbors_count");

  INTERF_F_LOCAL_MPI_Improbe = dlsym(interface_handle_f, "A_f_MPI_Improbe");

  INTERF_F_LOCAL_MPI_Imrecv = dlsym(interface_handle_f, "A_f_MPI_Imrecv");

  INTERF_F_LOCAL_MPI_Mprobe = dlsym(interface_handle_f, "A_f_MPI_Mprobe");

  INTERF_F_LOCAL_MPI_Mrecv = dlsym(interface_handle_f, "A_f_MPI_Mrecv");

  INTERF_F_LOCAL_MPI_Comm_idup = dlsym(interface_handle_f, "A_f_MPI_Comm_idup");

  INTERF_F_LOCAL_MPI_Ibarrier = dlsym(interface_handle_f, "A_f_MPI_Ibarrier");

  INTERF_F_LOCAL_MPI_Ibcast = dlsym(interface_handle_f, "A_f_MPI_Ibcast");

  INTERF_F_LOCAL_MPI_Igather = dlsym(interface_handle_f, "A_f_MPI_Igather");

  INTERF_F_LOCAL_MPI_Iscatter = dlsym(interface_handle_f, "A_f_MPI_Iscatter");

  INTERF_F_LOCAL_MPI_Iallgather =
      dlsym(interface_handle_f, "A_f_MPI_Iallgather");

  INTERF_F_LOCAL_MPI_Ialltoall = dlsym(interface_handle_f, "A_f_MPI_Ialltoall");

  INTERF_F_LOCAL_MPI_Ireduce = dlsym(interface_handle_f, "A_f_MPI_Ireduce");

  INTERF_F_LOCAL_MPI_Iallreduce =
      dlsym(interface_handle_f, "A_f_MPI_Iallreduce");

  INTERF_F_LOCAL_MPI_Ireduce_scatter_block =
      dlsym(interface_handle_f, "A_f_MPI_Ireduce_scatter_block");

  INTERF_F_LOCAL_MPI_Iscan = dlsym(interface_handle_f, "A_f_MPI_Iscan");

  INTERF_F_LOCAL_MPI_Iexscan = dlsym(interface_handle_f, "A_f_MPI_Iexscan");

  INTERF_F_LOCAL_MPI_Ineighbor_allgather =
      dlsym(interface_handle_f, "A_f_MPI_Ineighbor_allgather");

  INTERF_F_LOCAL_MPI_Ineighbor_alltoall =
      dlsym(interface_handle_f, "A_f_MPI_Ineighbor_alltoall");

  INTERF_F_LOCAL_MPI_Neighbor_allgather =
      dlsym(interface_handle_f, "A_f_MPI_Neighbor_allgather");

  INTERF_F_LOCAL_MPI_Neighbor_alltoall =
      dlsym(interface_handle_f, "A_f_MPI_Neighbor_alltoall");

  INTERF_F_LOCAL_MPI_Comm_split_type =
      dlsym(interface_handle_f, "A_f_MPI_Comm_split_type");

  INTERF_F_LOCAL_MPI_Get_elements_x =
      dlsym(interface_handle_f, "A_f_MPI_Get_elements_x");

  INTERF_F_LOCAL_MPI_Status_set_elements_x =
      dlsym(interface_handle_f, "A_f_MPI_Status_set_elements_x");

  INTERF_F_LOCAL_MPI_Type_get_extent_x =
      dlsym(interface_handle_f, "A_f_MPI_Type_get_extent_x");

  INTERF_F_LOCAL_MPI_Type_get_true_extent_x =
      dlsym(interface_handle_f, "A_f_MPI_Type_get_true_extent_x");

  INTERF_F_LOCAL_MPI_Type_size_x =
      dlsym(interface_handle_f, "A_f_MPI_Type_size_x");

  INTERF_F_LOCAL_MPI_Comm_create_group =
      dlsym(interface_handle_f, "A_f_MPI_Comm_create_group");

  INTERF_F_LOCAL_MPI_T_init_thread =
      dlsym(interface_handle_f, "A_f_MPI_T_init_thread");

  INTERF_F_LOCAL_MPI_T_enum_get_info =
      dlsym(interface_handle_f, "A_f_MPI_T_enum_get_info");

  INTERF_F_LOCAL_MPI_T_enum_get_item =
      dlsym(interface_handle_f, "A_f_MPI_T_enum_get_item");

  INTERF_F_LOCAL_MPI_T_cvar_get_num =
      dlsym(interface_handle_f, "A_f_MPI_T_cvar_get_num");

  INTERF_F_LOCAL_MPI_T_cvar_get_info =
      dlsym(interface_handle_f, "A_f_MPI_T_cvar_get_info");

  INTERF_F_LOCAL_MPI_T_cvar_handle_alloc =
      dlsym(interface_handle_f, "A_f_MPI_T_cvar_handle_alloc");

  INTERF_F_LOCAL_MPI_T_cvar_handle_free =
      dlsym(interface_handle_f, "A_f_MPI_T_cvar_handle_free");

  INTERF_F_LOCAL_MPI_T_cvar_read =
      dlsym(interface_handle_f, "A_f_MPI_T_cvar_read");

  INTERF_F_LOCAL_MPI_T_cvar_write =
      dlsym(interface_handle_f, "A_f_MPI_T_cvar_write");

  INTERF_F_LOCAL_MPI_T_pvar_get_num =
      dlsym(interface_handle_f, "A_f_MPI_T_pvar_get_num");

  INTERF_F_LOCAL_MPI_T_pvar_get_info =
      dlsym(interface_handle_f, "A_f_MPI_T_pvar_get_info");

  INTERF_F_LOCAL_MPI_T_pvar_session_create =
      dlsym(interface_handle_f, "A_f_MPI_T_pvar_session_create");

  INTERF_F_LOCAL_MPI_T_pvar_session_free =
      dlsym(interface_handle_f, "A_f_MPI_T_pvar_session_free");

  INTERF_F_LOCAL_MPI_T_pvar_handle_alloc =
      dlsym(interface_handle_f, "A_f_MPI_T_pvar_handle_alloc");

  INTERF_F_LOCAL_MPI_T_pvar_handle_free =
      dlsym(interface_handle_f, "A_f_MPI_T_pvar_handle_free");

  INTERF_F_LOCAL_MPI_T_pvar_start =
      dlsym(interface_handle_f, "A_f_MPI_T_pvar_start");

  INTERF_F_LOCAL_MPI_T_pvar_stop =
      dlsym(interface_handle_f, "A_f_MPI_T_pvar_stop");

  INTERF_F_LOCAL_MPI_T_pvar_read =
      dlsym(interface_handle_f, "A_f_MPI_T_pvar_read");

  INTERF_F_LOCAL_MPI_T_pvar_write =
      dlsym(interface_handle_f, "A_f_MPI_T_pvar_write");

  INTERF_F_LOCAL_MPI_T_pvar_reset =
      dlsym(interface_handle_f, "A_f_MPI_T_pvar_reset");

  INTERF_F_LOCAL_MPI_T_pvar_readreset =
      dlsym(interface_handle_f, "A_f_MPI_T_pvar_readreset");

  INTERF_F_LOCAL_MPI_T_category_get_num =
      dlsym(interface_handle_f, "A_f_MPI_T_category_get_num");

  INTERF_F_LOCAL_MPI_T_category_get_info =
      dlsym(interface_handle_f, "A_f_MPI_T_category_get_info");

  INTERF_F_LOCAL_PI_T_category_changed =
      dlsym(interface_handle_f, "A_f_PI_T_category_changed");

  INTERF_F_LOCAL_MPI_File_open = dlsym(interface_handle_f, "A_f_MPI_File_open");

  INTERF_F_LOCAL_MPI_File_close =
      dlsym(interface_handle_f, "A_f_MPI_File_close");

  INTERF_F_LOCAL_MPI_File_delete =
      dlsym(interface_handle_f, "A_f_MPI_File_delete");

  INTERF_F_LOCAL_MPI_File_set_size =
      dlsym(interface_handle_f, "A_f_MPI_File_set_size");

  INTERF_F_LOCAL_MPI_File_preallocate =
      dlsym(interface_handle_f, "A_f_MPI_File_preallocate");

  INTERF_F_LOCAL_MPI_File_get_size =
      dlsym(interface_handle_f, "A_f_MPI_File_get_size");

  INTERF_F_LOCAL_MPI_File_get_group =
      dlsym(interface_handle_f, "A_f_MPI_File_get_group");

  INTERF_F_LOCAL_MPI_File_get_amode =
      dlsym(interface_handle_f, "A_f_MPI_File_get_amode");

  INTERF_F_LOCAL_MPI_File_set_info =
      dlsym(interface_handle_f, "A_f_MPI_File_set_info");

  INTERF_F_LOCAL_MPI_File_get_info =
      dlsym(interface_handle_f, "A_f_MPI_File_get_info");

  INTERF_F_LOCAL_MPI_File_set_view =
      dlsym(interface_handle_f, "A_f_MPI_File_set_view");

  INTERF_F_LOCAL_MPI_File_get_view =
      dlsym(interface_handle_f, "A_f_MPI_File_get_view");

  INTERF_F_LOCAL_MPI_File_read_at =
      dlsym(interface_handle_f, "A_f_MPI_File_read_at");

  INTERF_F_LOCAL_MPI_File_read_at_all =
      dlsym(interface_handle_f, "A_f_MPI_File_read_at_all");

  INTERF_F_LOCAL_MPI_File_write_at =
      dlsym(interface_handle_f, "A_f_MPI_File_write_at");

  INTERF_F_LOCAL_MPI_File_write_at_all =
      dlsym(interface_handle_f, "A_f_MPI_File_write_at_all");

  INTERF_F_LOCAL_MPI_File_iread_at =
      dlsym(interface_handle_f, "A_f_MPI_File_iread_at");

  INTERF_F_LOCAL_MPI_File_iwrite_at =
      dlsym(interface_handle_f, "A_f_MPI_File_iwrite_at");

  INTERF_F_LOCAL_MPI_File_read = dlsym(interface_handle_f, "A_f_MPI_File_read");

  INTERF_F_LOCAL_MPI_File_read_all =
      dlsym(interface_handle_f, "A_f_MPI_File_read_all");

  INTERF_F_LOCAL_MPI_File_write =
      dlsym(interface_handle_f, "A_f_MPI_File_write");

  INTERF_F_LOCAL_MPI_File_write_all =
      dlsym(interface_handle_f, "A_f_MPI_File_write_all");

  INTERF_F_LOCAL_MPI_File_iread =
      dlsym(interface_handle_f, "A_f_MPI_File_iread");

  INTERF_F_LOCAL_MPI_File_iwrite =
      dlsym(interface_handle_f, "A_f_MPI_File_iwrite");

  INTERF_F_LOCAL_MPI_File_seek = dlsym(interface_handle_f, "A_f_MPI_File_seek");

  INTERF_F_LOCAL_MPI_File_get_position =
      dlsym(interface_handle_f, "A_f_MPI_File_get_position");

  INTERF_F_LOCAL_MPI_File_get_byte_offset =
      dlsym(interface_handle_f, "A_f_MPI_File_get_byte_offset");

  INTERF_F_LOCAL_MPI_File_read_shared =
      dlsym(interface_handle_f, "A_f_MPI_File_read_shared");

  INTERF_F_LOCAL_MPI_File_write_shared =
      dlsym(interface_handle_f, "A_f_MPI_File_write_shared");

  INTERF_F_LOCAL_MPI_File_iread_shared =
      dlsym(interface_handle_f, "A_f_MPI_File_iread_shared");

  INTERF_F_LOCAL_MPI_File_iwrite_shared =
      dlsym(interface_handle_f, "A_f_MPI_File_iwrite_shared");

  INTERF_F_LOCAL_MPI_File_read_ordered =
      dlsym(interface_handle_f, "A_f_MPI_File_read_ordered");

  INTERF_F_LOCAL_MPI_File_write_ordered =
      dlsym(interface_handle_f, "A_f_MPI_File_write_ordered");

  INTERF_F_LOCAL_MPI_File_seek_shared =
      dlsym(interface_handle_f, "A_f_MPI_File_seek_shared");

  INTERF_F_LOCAL_MPI_File_get_position_shared =
      dlsym(interface_handle_f, "A_f_MPI_File_get_position_shared");

  INTERF_F_LOCAL_MPI_File_read_at_all_begin =
      dlsym(interface_handle_f, "A_f_MPI_File_read_at_all_begin");

  INTERF_F_LOCAL_MPI_File_read_at_all_end =
      dlsym(interface_handle_f, "A_f_MPI_File_read_at_all_end");

  INTERF_F_LOCAL_MPI_File_write_at_all_begin =
      dlsym(interface_handle_f, "A_f_MPI_File_write_at_all_begin");

  INTERF_F_LOCAL_MPI_File_write_at_all_end =
      dlsym(interface_handle_f, "A_f_MPI_File_write_at_all_end");

  INTERF_F_LOCAL_MPI_File_read_all_begin =
      dlsym(interface_handle_f, "A_f_MPI_File_read_all_begin");

  INTERF_F_LOCAL_MPI_File_read_all_end =
      dlsym(interface_handle_f, "A_f_MPI_File_read_all_end");

  INTERF_F_LOCAL_MPI_File_write_all_begin =
      dlsym(interface_handle_f, "A_f_MPI_File_write_all_begin");

  INTERF_F_LOCAL_MPI_File_write_all_end =
      dlsym(interface_handle_f, "A_f_MPI_File_write_all_end");

  INTERF_F_LOCAL_MPI_File_read_ordered_begin =
      dlsym(interface_handle_f, "A_f_MPI_File_read_ordered_begin");

  INTERF_F_LOCAL_MPI_File_read_ordered_end =
      dlsym(interface_handle_f, "A_f_MPI_File_read_ordered_end");

  INTERF_F_LOCAL_MPI_File_write_ordered_begin =
      dlsym(interface_handle_f, "A_f_MPI_File_write_ordered_begin");

  INTERF_F_LOCAL_MPI_File_write_ordered_end =
      dlsym(interface_handle_f, "A_f_MPI_File_write_ordered_end");

  INTERF_F_LOCAL_MPI_File_get_type_extent =
      dlsym(interface_handle_f, "A_f_MPI_File_get_type_extent");

  INTERF_F_LOCAL_MPI_Register_datarep =
      dlsym(interface_handle_f, "A_f_MPI_Register_datarep");

  INTERF_F_LOCAL_MPI_File_set_atomicity =
      dlsym(interface_handle_f, "A_f_MPI_File_set_atomicity");

  INTERF_F_LOCAL_MPI_File_get_atomicity =
      dlsym(interface_handle_f, "A_f_MPI_File_get_atomicity");

  INTERF_F_LOCAL_MPI_File_sync = dlsym(interface_handle_f, "A_f_MPI_File_sync");

  INTERF_F_LOCAL_MPI_T_finalize =
      dlsym(interface_handle_f, "A_f_MPI_T_finalize");

  INTERF_F_LOCAL_MPI_Wtime = dlsym(interface_handle_f, "A_f_MPI_Wtime");

  INTERF_F_LOCAL_MPI_Wtick = dlsym(interface_handle_f, "A_f_MPI_Wtick");

  INTERF_F_LOCAL_MPI_Finalize = dlsym(interface_handle_f, "A_f_MPI_Finalize");

  INTERF_F_LOCAL_MPI_Waitany = dlsym(interface_handle_f, "A_f_MPI_Waitany");

  INTERF_F_LOCAL_MPI_Testany = dlsym(interface_handle_f, "A_f_MPI_Testany");

  INTERF_F_LOCAL_MPI_Waitall = dlsym(interface_handle_f, "A_f_MPI_Waitall");

  INTERF_F_LOCAL_MPI_Testall = dlsym(interface_handle_f, "A_f_MPI_Testall");

  INTERF_F_LOCAL_MPI_Waitsome = dlsym(interface_handle_f, "A_f_MPI_Waitsome");

  INTERF_F_LOCAL_MPI_Testsome = dlsym(interface_handle_f, "A_f_MPI_Testsome");

  INTERF_F_LOCAL_MPI_Startall = dlsym(interface_handle_f, "A_f_MPI_Startall");

  INTERF_F_LOCAL_MPI_Alltoallw = dlsym(interface_handle_f, "A_f_MPI_Alltoallw");

  INTERF_F_LOCAL_MPI_Reduce_scatter =
      dlsym(interface_handle_f, "A_f_MPI_Reduce_scatter");

  INTERF_F_LOCAL_MPI_Group_translate_ranks =
      dlsym(interface_handle_f, "A_f_MPI_Group_translate_ranks");

  INTERF_F_LOCAL_MPI_Group_incl =
      dlsym(interface_handle_f, "A_f_MPI_Group_incl");

  INTERF_F_LOCAL_MPI_Group_excl =
      dlsym(interface_handle_f, "A_f_MPI_Group_excl");

  INTERF_F_LOCAL_MPI_Group_range_incl =
      dlsym(interface_handle_f, "A_f_MPI_Group_range_incl");

  INTERF_F_LOCAL_MPI_Group_range_excl =
      dlsym(interface_handle_f, "A_f_MPI_Group_range_excl");

  INTERF_F_LOCAL_MPI_Cart_create =
      dlsym(interface_handle_f, "A_f_MPI_Cart_create");

  INTERF_F_LOCAL_MPI_Dims_create =
      dlsym(interface_handle_f, "A_f_MPI_Dims_create");

  INTERF_F_LOCAL_MPI_Graph_create =
      dlsym(interface_handle_f, "A_f_MPI_Graph_create");

  INTERF_F_LOCAL_MPI_Graph_get = dlsym(interface_handle_f, "A_f_MPI_Graph_get");

  INTERF_F_LOCAL_MPI_Cart_get = dlsym(interface_handle_f, "A_f_MPI_Cart_get");

  INTERF_F_LOCAL_MPI_Cart_rank = dlsym(interface_handle_f, "A_f_MPI_Cart_rank");

  INTERF_F_LOCAL_MPI_Cart_coords =
      dlsym(interface_handle_f, "A_f_MPI_Cart_coords");

  INTERF_F_LOCAL_MPI_Graph_neighbors =
      dlsym(interface_handle_f, "A_f_MPI_Graph_neighbors");

  INTERF_F_LOCAL_MPI_Cart_sub = dlsym(interface_handle_f, "A_f_MPI_Cart_sub");

  INTERF_F_LOCAL_MPI_Cart_map = dlsym(interface_handle_f, "A_f_MPI_Cart_map");

  INTERF_F_LOCAL_MPI_Graph_map = dlsym(interface_handle_f, "A_f_MPI_Graph_map");

  INTERF_F_LOCAL_MPI_Comm_spawn =
      dlsym(interface_handle_f, "A_f_MPI_Comm_spawn");

  INTERF_F_LOCAL_MPI_Comm_spawn_multiple =
      dlsym(interface_handle_f, "A_f_MPI_Comm_spawn_multiple");

  INTERF_F_LOCAL_MPI_Type_get_contents =
      dlsym(interface_handle_f, "A_f_MPI_Type_get_contents");

  INTERF_F_LOCAL_MPI_Pack_external =
      dlsym(interface_handle_f, "A_f_MPI_Pack_external");

  INTERF_F_LOCAL_MPI_Pack_external_size =
      dlsym(interface_handle_f, "A_f_MPI_Pack_external_size");

  INTERF_F_LOCAL_MPI_Type_create_darray =
      dlsym(interface_handle_f, "A_f_MPI_Type_create_darray");

  INTERF_F_LOCAL_MPI_Type_create_hindexed =
      dlsym(interface_handle_f, "A_f_MPI_Type_create_hindexed");

  INTERF_F_LOCAL_MPI_Type_create_indexed_block =
      dlsym(interface_handle_f, "A_f_MPI_Type_create_indexed_block");

  INTERF_F_LOCAL_MPI_Type_create_hindexed_block =
      dlsym(interface_handle_f, "A_f_MPI_Type_create_hindexed_block");

  INTERF_F_LOCAL_MPI_Type_create_struct =
      dlsym(interface_handle_f, "A_f_MPI_Type_create_struct");

  INTERF_F_LOCAL_MPI_Type_create_subarray =
      dlsym(interface_handle_f, "A_f_MPI_Type_create_subarray");

  INTERF_F_LOCAL_MPI_Unpack_external =
      dlsym(interface_handle_f, "A_f_MPI_Unpack_external");

  INTERF_F_LOCAL_MPI_Dist_graph_create_adjacent =
      dlsym(interface_handle_f, "A_f_MPI_Dist_graph_create_adjacent");

  INTERF_F_LOCAL_MPI_Dist_graph_create =
      dlsym(interface_handle_f, "A_f_MPI_Dist_graph_create");

  INTERF_F_LOCAL_MPI_Dist_graph_neighbors =
      dlsym(interface_handle_f, "A_f_MPI_Dist_graph_neighbors");

  INTERF_F_LOCAL_MPI_Igatherv = dlsym(interface_handle_f, "A_f_MPI_Igatherv");

  INTERF_F_LOCAL_MPI_Iscatterv = dlsym(interface_handle_f, "A_f_MPI_Iscatterv");

  INTERF_F_LOCAL_MPI_Iallgatherv =
      dlsym(interface_handle_f, "A_f_MPI_Iallgatherv");

  INTERF_F_LOCAL_MPI_Ialltoallv =
      dlsym(interface_handle_f, "A_f_MPI_Ialltoallv");

  INTERF_F_LOCAL_MPI_Ialltoallw =
      dlsym(interface_handle_f, "A_f_MPI_Ialltoallw");

  INTERF_F_LOCAL_MPI_Ireduce_scatter =
      dlsym(interface_handle_f, "A_f_MPI_Ireduce_scatter");

  INTERF_F_LOCAL_MPI_Ineighbor_allgatherv =
      dlsym(interface_handle_f, "A_f_MPI_Ineighbor_allgatherv");

  INTERF_F_LOCAL_MPI_Ineighbor_alltoallv =
      dlsym(interface_handle_f, "A_f_MPI_Ineighbor_alltoallv");

  INTERF_F_LOCAL_MPI_Ineighbor_alltoallw =
      dlsym(interface_handle_f, "A_f_MPI_Ineighbor_alltoallw");

  INTERF_F_LOCAL_MPI_Neighbor_allgatherv =
      dlsym(interface_handle_f, "A_f_MPI_Neighbor_allgatherv");

  INTERF_F_LOCAL_MPI_Neighbor_alltoallv =
      dlsym(interface_handle_f, "A_f_MPI_Neighbor_alltoallv");

  INTERF_F_LOCAL_MPI_Neighbor_alltoallw =
      dlsym(interface_handle_f, "A_f_MPI_Neighbor_alltoallw");

  INTERF_F_LOCAL_MPI_T_category_get_cvars =
      dlsym(interface_handle_f, "A_f_MPI_T_category_get_cvars");

  INTERF_F_LOCAL_MPI_T_category_get_pvars =
      dlsym(interface_handle_f, "A_f_MPI_T_category_get_pvars");

  INTERF_F_LOCAL_MPI_T_category_get_categories =
      dlsym(interface_handle_f, "A_f_MPI_T_category_get_categories");

  INTERF_F_LOCAL_MPI_File_iwrite_all =
      dlsym(interface_handle_f, "A_f_MPI_File_iwrite_all");

  INTERF_F_LOCAL_MPI_File_iwrite_at_all =
      dlsym(interface_handle_f, "A_f_MPI_File_iwrite_at_all");

  INTERF_F_LOCAL_MPI_T_category_get_index =
      dlsym(interface_handle_f, "A_f_MPI_T_category_get_index");

  INTERF_F_LOCAL_MPI_T_cvar_get_index =
      dlsym(interface_handle_f, "A_f_MPI_T_cvar_get_index");

  INTERF_F_LOCAL_MPI_T_pvar_get_index =
      dlsym(interface_handle_f, "A_f_MPI_T_pvar_get_index");

  INTERF_F_LOCAL_MPI_Aint_add = dlsym(interface_handle_f, "A_f_MPI_Aint_add");

  INTERF_F_LOCAL_MPI_Aint_diff = dlsym(interface_handle_f, "A_f_MPI_Aint_diff");

  INTERF_F_LOCAL_MPI_Comm_dup_fn =
      dlsym(interface_handle_f, "A_f_MPI_Comm_dup_fn");

  INTERF_F_LOCAL_MPI_Comm_null_copy_fn =
      dlsym(interface_handle_f, "A_f_MPI_Comm_null_copy_fn");

  INTERF_F_LOCAL_MPI_Comm_null_delete_fn =
      dlsym(interface_handle_f, "A_f_MPI_Comm_null_delete_fn");

  INTERF_F_LOCAL_MPI_File_iread_all =
      dlsym(interface_handle_f, "A_f_MPI_File_iread_all");

  INTERF_F_LOCAL_MPI_File_iread_at_all =
      dlsym(interface_handle_f, "A_f_MPI_File_iread_at_all");

  INTERF_F_LOCAL_MPI_T_category_changed =
      dlsym(interface_handle_f, "A_f_MPI_T_category_changed");

  INTERF_F_LOCAL_MPIX_query_cuda_support =
      dlsym(interface_handle_f, "A_f_MPIX_query_cuda_support");
#else
  char *target = getenv("WI4MPI_STATIC_TARGET_TYPE");
  if (!target)
    printf("no valid WI4MPI_STATIC_TARGET_TYPE defined\n");
  exit(1);
}

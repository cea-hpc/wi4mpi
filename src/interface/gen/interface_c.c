#include <stdlib.h>
#define _GNU_SOURCE
#include "mpi.h"
#include <dlfcn.h>
#include <stdio.h>

char wi4mpi_mode[] = "";

__thread int in_w;

int MPI_Pcontrol(int level, ...);
#pragma weak MPI_Pcontrol = PMPI_Pcontrol

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Pcontrol(int level, ...);

int INTERF_2_INTEL_MPI_Pcontrol(int level, ...);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Pcontrol)(int level, ...);
int PMPI_Pcontrol(int level, ...) {
  return INTERFACE_LOCAL_MPI_Pcontrol(level);
}

int MPI_Send(void *buf, int count, MPI_Datatype datatype, int dest, int tag,
             MPI_Comm comm);
#pragma weak MPI_Send = PMPI_Send

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Send(void *buf, int count, MPI_Datatype datatype,
                           int dest, int tag, MPI_Comm comm);

int INTERF_2_INTEL_MPI_Send(void *buf, int count, MPI_Datatype datatype,
                            int dest, int tag, MPI_Comm comm);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Send)(void *buf, int count, MPI_Datatype datatype,
                                int dest, int tag, MPI_Comm comm);
int PMPI_Send(void *buf, int count, MPI_Datatype datatype, int dest, int tag,
              MPI_Comm comm) {
  return INTERFACE_LOCAL_MPI_Send(buf, count, datatype, dest, tag, comm);
}

int MPI_Recv(void *buf, int count, MPI_Datatype datatype, int source, int tag,
             MPI_Comm comm, MPI_Status *status);
#pragma weak MPI_Recv = PMPI_Recv

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Recv(void *buf, int count, MPI_Datatype datatype,
                           int source, int tag, MPI_Comm comm,
                           MPI_Status *status);

int INTERF_2_INTEL_MPI_Recv(void *buf, int count, MPI_Datatype datatype,
                            int source, int tag, MPI_Comm comm,
                            MPI_Status *status);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Recv)(void *buf, int count, MPI_Datatype datatype,
                                int source, int tag, MPI_Comm comm,
                                MPI_Status *status);
int PMPI_Recv(void *buf, int count, MPI_Datatype datatype, int source, int tag,
              MPI_Comm comm, MPI_Status *status) {
  return INTERFACE_LOCAL_MPI_Recv(buf, count, datatype, source, tag, comm,
                                  status);
}

int MPI_Get_count(MPI_Status *status, MPI_Datatype datatype, int *count);
#pragma weak MPI_Get_count = PMPI_Get_count

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Get_count(MPI_Status *status, MPI_Datatype datatype,
                                int *count);

int INTERF_2_INTEL_MPI_Get_count(MPI_Status *status, MPI_Datatype datatype,
                                 int *count);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Get_count)(MPI_Status *status, MPI_Datatype datatype,
                                     int *count);
int PMPI_Get_count(MPI_Status *status, MPI_Datatype datatype, int *count) {
  return INTERFACE_LOCAL_MPI_Get_count(status, datatype, count);
}

int MPI_Bsend(void *buf, int count, MPI_Datatype datatype, int dest, int tag,
              MPI_Comm comm);
#pragma weak MPI_Bsend = PMPI_Bsend

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Bsend(void *buf, int count, MPI_Datatype datatype,
                            int dest, int tag, MPI_Comm comm);

int INTERF_2_INTEL_MPI_Bsend(void *buf, int count, MPI_Datatype datatype,
                             int dest, int tag, MPI_Comm comm);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Bsend)(void *buf, int count, MPI_Datatype datatype,
                                 int dest, int tag, MPI_Comm comm);
int PMPI_Bsend(void *buf, int count, MPI_Datatype datatype, int dest, int tag,
               MPI_Comm comm) {
  return INTERFACE_LOCAL_MPI_Bsend(buf, count, datatype, dest, tag, comm);
}

int MPI_Ssend(void *buf, int count, MPI_Datatype datatype, int dest, int tag,
              MPI_Comm comm);
#pragma weak MPI_Ssend = PMPI_Ssend

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Ssend(void *buf, int count, MPI_Datatype datatype,
                            int dest, int tag, MPI_Comm comm);

int INTERF_2_INTEL_MPI_Ssend(void *buf, int count, MPI_Datatype datatype,
                             int dest, int tag, MPI_Comm comm);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Ssend)(void *buf, int count, MPI_Datatype datatype,
                                 int dest, int tag, MPI_Comm comm);
int PMPI_Ssend(void *buf, int count, MPI_Datatype datatype, int dest, int tag,
               MPI_Comm comm) {
  return INTERFACE_LOCAL_MPI_Ssend(buf, count, datatype, dest, tag, comm);
}

int MPI_Rsend(void *buf, int count, MPI_Datatype datatype, int dest, int tag,
              MPI_Comm comm);
#pragma weak MPI_Rsend = PMPI_Rsend

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Rsend(void *buf, int count, MPI_Datatype datatype,
                            int dest, int tag, MPI_Comm comm);

int INTERF_2_INTEL_MPI_Rsend(void *buf, int count, MPI_Datatype datatype,
                             int dest, int tag, MPI_Comm comm);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Rsend)(void *buf, int count, MPI_Datatype datatype,
                                 int dest, int tag, MPI_Comm comm);
int PMPI_Rsend(void *buf, int count, MPI_Datatype datatype, int dest, int tag,
               MPI_Comm comm) {
  return INTERFACE_LOCAL_MPI_Rsend(buf, count, datatype, dest, tag, comm);
}

int MPI_Buffer_attach(void *buffer, int size);
#pragma weak MPI_Buffer_attach = PMPI_Buffer_attach

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Buffer_attach(void *buffer, int size);

int INTERF_2_INTEL_MPI_Buffer_attach(void *buffer, int size);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Buffer_attach)(void *buffer, int size);
int PMPI_Buffer_attach(void *buffer, int size) {
  return INTERFACE_LOCAL_MPI_Buffer_attach(buffer, size);
}

int MPI_Buffer_detach(void *buffer_addr, int *size);
#pragma weak MPI_Buffer_detach = PMPI_Buffer_detach

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Buffer_detach(void *buffer_addr, int *size);

int INTERF_2_INTEL_MPI_Buffer_detach(void *buffer_addr, int *size);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Buffer_detach)(void *buffer_addr, int *size);
int PMPI_Buffer_detach(void *buffer_addr, int *size) {
  return INTERFACE_LOCAL_MPI_Buffer_detach(buffer_addr, size);
}

int MPI_Isend(void *buf, int count, MPI_Datatype datatype, int dest, int tag,
              MPI_Comm comm, MPI_Request *request);
#pragma weak MPI_Isend = PMPI_Isend

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Isend(void *buf, int count, MPI_Datatype datatype,
                            int dest, int tag, MPI_Comm comm,
                            MPI_Request *request);

int INTERF_2_INTEL_MPI_Isend(void *buf, int count, MPI_Datatype datatype,
                             int dest, int tag, MPI_Comm comm,
                             MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Isend)(void *buf, int count, MPI_Datatype datatype,
                                 int dest, int tag, MPI_Comm comm,
                                 MPI_Request *request);
int PMPI_Isend(void *buf, int count, MPI_Datatype datatype, int dest, int tag,
               MPI_Comm comm, MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_Isend(buf, count, datatype, dest, tag, comm,
                                   request);
}

int MPI_Ibsend(void *buf, int count, MPI_Datatype datatype, int dest, int tag,
               MPI_Comm comm, MPI_Request *request);
#pragma weak MPI_Ibsend = PMPI_Ibsend

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Ibsend(void *buf, int count, MPI_Datatype datatype,
                             int dest, int tag, MPI_Comm comm,
                             MPI_Request *request);

int INTERF_2_INTEL_MPI_Ibsend(void *buf, int count, MPI_Datatype datatype,
                              int dest, int tag, MPI_Comm comm,
                              MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Ibsend)(void *buf, int count, MPI_Datatype datatype,
                                  int dest, int tag, MPI_Comm comm,
                                  MPI_Request *request);
int PMPI_Ibsend(void *buf, int count, MPI_Datatype datatype, int dest, int tag,
                MPI_Comm comm, MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_Ibsend(buf, count, datatype, dest, tag, comm,
                                    request);
}

int MPI_Issend(void *buf, int count, MPI_Datatype datatype, int dest, int tag,
               MPI_Comm comm, MPI_Request *request);
#pragma weak MPI_Issend = PMPI_Issend

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Issend(void *buf, int count, MPI_Datatype datatype,
                             int dest, int tag, MPI_Comm comm,
                             MPI_Request *request);

int INTERF_2_INTEL_MPI_Issend(void *buf, int count, MPI_Datatype datatype,
                              int dest, int tag, MPI_Comm comm,
                              MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Issend)(void *buf, int count, MPI_Datatype datatype,
                                  int dest, int tag, MPI_Comm comm,
                                  MPI_Request *request);
int PMPI_Issend(void *buf, int count, MPI_Datatype datatype, int dest, int tag,
                MPI_Comm comm, MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_Issend(buf, count, datatype, dest, tag, comm,
                                    request);
}

int MPI_Irsend(void *buf, int count, MPI_Datatype datatype, int dest, int tag,
               MPI_Comm comm, MPI_Request *request);
#pragma weak MPI_Irsend = PMPI_Irsend

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Irsend(void *buf, int count, MPI_Datatype datatype,
                             int dest, int tag, MPI_Comm comm,
                             MPI_Request *request);

int INTERF_2_INTEL_MPI_Irsend(void *buf, int count, MPI_Datatype datatype,
                              int dest, int tag, MPI_Comm comm,
                              MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Irsend)(void *buf, int count, MPI_Datatype datatype,
                                  int dest, int tag, MPI_Comm comm,
                                  MPI_Request *request);
int PMPI_Irsend(void *buf, int count, MPI_Datatype datatype, int dest, int tag,
                MPI_Comm comm, MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_Irsend(buf, count, datatype, dest, tag, comm,
                                    request);
}

int MPI_Irecv(void *buf, int count, MPI_Datatype datatype, int source, int tag,
              MPI_Comm comm, MPI_Request *request);
#pragma weak MPI_Irecv = PMPI_Irecv

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Irecv(void *buf, int count, MPI_Datatype datatype,
                            int source, int tag, MPI_Comm comm,
                            MPI_Request *request);

int INTERF_2_INTEL_MPI_Irecv(void *buf, int count, MPI_Datatype datatype,
                             int source, int tag, MPI_Comm comm,
                             MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Irecv)(void *buf, int count, MPI_Datatype datatype,
                                 int source, int tag, MPI_Comm comm,
                                 MPI_Request *request);
int PMPI_Irecv(void *buf, int count, MPI_Datatype datatype, int source, int tag,
               MPI_Comm comm, MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_Irecv(buf, count, datatype, source, tag, comm,
                                   request);
}

int MPI_Wait(MPI_Request *request, MPI_Status *status);
#pragma weak MPI_Wait = PMPI_Wait

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Wait(MPI_Request *request, MPI_Status *status);

int INTERF_2_INTEL_MPI_Wait(MPI_Request *request, MPI_Status *status);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Wait)(MPI_Request *request, MPI_Status *status);
int PMPI_Wait(MPI_Request *request, MPI_Status *status) {
  return INTERFACE_LOCAL_MPI_Wait(request, status);
}

int MPI_Test(MPI_Request *request, int *flag, MPI_Status *status);
#pragma weak MPI_Test = PMPI_Test

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Test(MPI_Request *request, int *flag, MPI_Status *status);

int INTERF_2_INTEL_MPI_Test(MPI_Request *request, int *flag,
                            MPI_Status *status);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Test)(MPI_Request *request, int *flag,
                                MPI_Status *status);
int PMPI_Test(MPI_Request *request, int *flag, MPI_Status *status) {
  return INTERFACE_LOCAL_MPI_Test(request, flag, status);
}

int MPI_Request_free(MPI_Request *request);
#pragma weak MPI_Request_free = PMPI_Request_free

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Request_free(MPI_Request *request);

int INTERF_2_INTEL_MPI_Request_free(MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Request_free)(MPI_Request *request);
int PMPI_Request_free(MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_Request_free(request);
}

int MPI_Iprobe(int source, int tag, MPI_Comm comm, int *flag,
               MPI_Status *status);
#pragma weak MPI_Iprobe = PMPI_Iprobe

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Iprobe(int source, int tag, MPI_Comm comm, int *flag,
                             MPI_Status *status);

int INTERF_2_INTEL_MPI_Iprobe(int source, int tag, MPI_Comm comm, int *flag,
                              MPI_Status *status);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Iprobe)(int source, int tag, MPI_Comm comm, int *flag,
                                  MPI_Status *status);
int PMPI_Iprobe(int source, int tag, MPI_Comm comm, int *flag,
                MPI_Status *status) {
  return INTERFACE_LOCAL_MPI_Iprobe(source, tag, comm, flag, status);
}

int MPI_Probe(int source, int tag, MPI_Comm comm, MPI_Status *status);
#pragma weak MPI_Probe = PMPI_Probe

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Probe(int source, int tag, MPI_Comm comm,
                            MPI_Status *status);

int INTERF_2_INTEL_MPI_Probe(int source, int tag, MPI_Comm comm,
                             MPI_Status *status);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Probe)(int source, int tag, MPI_Comm comm,
                                 MPI_Status *status);
int PMPI_Probe(int source, int tag, MPI_Comm comm, MPI_Status *status) {
  return INTERFACE_LOCAL_MPI_Probe(source, tag, comm, status);
}

int MPI_Cancel(MPI_Request *request);
#pragma weak MPI_Cancel = PMPI_Cancel

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Cancel(MPI_Request *request);

int INTERF_2_INTEL_MPI_Cancel(MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Cancel)(MPI_Request *request);
int PMPI_Cancel(MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_Cancel(request);
}

int MPI_Test_cancelled(MPI_Status *status, int *flag);
#pragma weak MPI_Test_cancelled = PMPI_Test_cancelled

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Test_cancelled(MPI_Status *status, int *flag);

int INTERF_2_INTEL_MPI_Test_cancelled(MPI_Status *status, int *flag);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Test_cancelled)(MPI_Status *status, int *flag);
int PMPI_Test_cancelled(MPI_Status *status, int *flag) {
  return INTERFACE_LOCAL_MPI_Test_cancelled(status, flag);
}

int MPI_Send_init(void *buf, int count, MPI_Datatype datatype, int dest,
                  int tag, MPI_Comm comm, MPI_Request *request);
#pragma weak MPI_Send_init = PMPI_Send_init

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Send_init(void *buf, int count, MPI_Datatype datatype,
                                int dest, int tag, MPI_Comm comm,
                                MPI_Request *request);

int INTERF_2_INTEL_MPI_Send_init(void *buf, int count, MPI_Datatype datatype,
                                 int dest, int tag, MPI_Comm comm,
                                 MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Send_init)(void *buf, int count,
                                     MPI_Datatype datatype, int dest, int tag,
                                     MPI_Comm comm, MPI_Request *request);
int PMPI_Send_init(void *buf, int count, MPI_Datatype datatype, int dest,
                   int tag, MPI_Comm comm, MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_Send_init(buf, count, datatype, dest, tag, comm,
                                       request);
}

int MPI_Bsend_init(void *buf, int count, MPI_Datatype datatype, int dest,
                   int tag, MPI_Comm comm, MPI_Request *request);
#pragma weak MPI_Bsend_init = PMPI_Bsend_init

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Bsend_init(void *buf, int count, MPI_Datatype datatype,
                                 int dest, int tag, MPI_Comm comm,
                                 MPI_Request *request);

int INTERF_2_INTEL_MPI_Bsend_init(void *buf, int count, MPI_Datatype datatype,
                                  int dest, int tag, MPI_Comm comm,
                                  MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Bsend_init)(void *buf, int count,
                                      MPI_Datatype datatype, int dest, int tag,
                                      MPI_Comm comm, MPI_Request *request);
int PMPI_Bsend_init(void *buf, int count, MPI_Datatype datatype, int dest,
                    int tag, MPI_Comm comm, MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_Bsend_init(buf, count, datatype, dest, tag, comm,
                                        request);
}

int MPI_Ssend_init(void *buf, int count, MPI_Datatype datatype, int dest,
                   int tag, MPI_Comm comm, MPI_Request *request);
#pragma weak MPI_Ssend_init = PMPI_Ssend_init

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Ssend_init(void *buf, int count, MPI_Datatype datatype,
                                 int dest, int tag, MPI_Comm comm,
                                 MPI_Request *request);

int INTERF_2_INTEL_MPI_Ssend_init(void *buf, int count, MPI_Datatype datatype,
                                  int dest, int tag, MPI_Comm comm,
                                  MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Ssend_init)(void *buf, int count,
                                      MPI_Datatype datatype, int dest, int tag,
                                      MPI_Comm comm, MPI_Request *request);
int PMPI_Ssend_init(void *buf, int count, MPI_Datatype datatype, int dest,
                    int tag, MPI_Comm comm, MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_Ssend_init(buf, count, datatype, dest, tag, comm,
                                        request);
}

int MPI_Rsend_init(void *buf, int count, MPI_Datatype datatype, int dest,
                   int tag, MPI_Comm comm, MPI_Request *request);
#pragma weak MPI_Rsend_init = PMPI_Rsend_init

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Rsend_init(void *buf, int count, MPI_Datatype datatype,
                                 int dest, int tag, MPI_Comm comm,
                                 MPI_Request *request);

int INTERF_2_INTEL_MPI_Rsend_init(void *buf, int count, MPI_Datatype datatype,
                                  int dest, int tag, MPI_Comm comm,
                                  MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Rsend_init)(void *buf, int count,
                                      MPI_Datatype datatype, int dest, int tag,
                                      MPI_Comm comm, MPI_Request *request);
int PMPI_Rsend_init(void *buf, int count, MPI_Datatype datatype, int dest,
                    int tag, MPI_Comm comm, MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_Rsend_init(buf, count, datatype, dest, tag, comm,
                                        request);
}

int MPI_Recv_init(void *buf, int count, MPI_Datatype datatype, int source,
                  int tag, MPI_Comm comm, MPI_Request *request);
#pragma weak MPI_Recv_init = PMPI_Recv_init

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Recv_init(void *buf, int count, MPI_Datatype datatype,
                                int source, int tag, MPI_Comm comm,
                                MPI_Request *request);

int INTERF_2_INTEL_MPI_Recv_init(void *buf, int count, MPI_Datatype datatype,
                                 int source, int tag, MPI_Comm comm,
                                 MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Recv_init)(void *buf, int count,
                                     MPI_Datatype datatype, int source, int tag,
                                     MPI_Comm comm, MPI_Request *request);
int PMPI_Recv_init(void *buf, int count, MPI_Datatype datatype, int source,
                   int tag, MPI_Comm comm, MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_Recv_init(buf, count, datatype, source, tag, comm,
                                       request);
}

int MPI_Start(MPI_Request *request);
#pragma weak MPI_Start = PMPI_Start

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Start(MPI_Request *request);

int INTERF_2_INTEL_MPI_Start(MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Start)(MPI_Request *request);
int PMPI_Start(MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_Start(request);
}

int MPI_Sendrecv(void *sendbuf, int sendcount, MPI_Datatype sendtype, int dest,
                 int sendtag, void *recvbuf, int recvcount,
                 MPI_Datatype recvtype, int source, int recvtag, MPI_Comm comm,
                 MPI_Status *status);
#pragma weak MPI_Sendrecv = PMPI_Sendrecv

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Sendrecv(void *sendbuf, int sendcount,
                               MPI_Datatype sendtype, int dest, int sendtag,
                               void *recvbuf, int recvcount,
                               MPI_Datatype recvtype, int source, int recvtag,
                               MPI_Comm comm, MPI_Status *status);

int INTERF_2_INTEL_MPI_Sendrecv(void *sendbuf, int sendcount,
                                MPI_Datatype sendtype, int dest, int sendtag,
                                void *recvbuf, int recvcount,
                                MPI_Datatype recvtype, int source, int recvtag,
                                MPI_Comm comm, MPI_Status *status);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Sendrecv)(void *sendbuf, int sendcount,
                                    MPI_Datatype sendtype, int dest,
                                    int sendtag, void *recvbuf, int recvcount,
                                    MPI_Datatype recvtype, int source,
                                    int recvtag, MPI_Comm comm,
                                    MPI_Status *status);
int PMPI_Sendrecv(void *sendbuf, int sendcount, MPI_Datatype sendtype, int dest,
                  int sendtag, void *recvbuf, int recvcount,
                  MPI_Datatype recvtype, int source, int recvtag, MPI_Comm comm,
                  MPI_Status *status) {
  return INTERFACE_LOCAL_MPI_Sendrecv(sendbuf, sendcount, sendtype, dest,
                                      sendtag, recvbuf, recvcount, recvtype,
                                      source, recvtag, comm, status);
}

int MPI_Sendrecv_replace(void *buf, int count, MPI_Datatype datatype, int dest,
                         int sendtag, int source, int recvtag, MPI_Comm comm,
                         MPI_Status *status);
#pragma weak MPI_Sendrecv_replace = PMPI_Sendrecv_replace

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Sendrecv_replace(void *buf, int count,
                                       MPI_Datatype datatype, int dest,
                                       int sendtag, int source, int recvtag,
                                       MPI_Comm comm, MPI_Status *status);

int INTERF_2_INTEL_MPI_Sendrecv_replace(void *buf, int count,
                                        MPI_Datatype datatype, int dest,
                                        int sendtag, int source, int recvtag,
                                        MPI_Comm comm, MPI_Status *status);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Sendrecv_replace)(void *buf, int count,
                                            MPI_Datatype datatype, int dest,
                                            int sendtag, int source,
                                            int recvtag, MPI_Comm comm,
                                            MPI_Status *status);
int PMPI_Sendrecv_replace(void *buf, int count, MPI_Datatype datatype, int dest,
                          int sendtag, int source, int recvtag, MPI_Comm comm,
                          MPI_Status *status) {
  return INTERFACE_LOCAL_MPI_Sendrecv_replace(
      buf, count, datatype, dest, sendtag, source, recvtag, comm, status);
}

int MPI_Type_contiguous(int count, MPI_Datatype oldtype, MPI_Datatype *newtype);
#pragma weak MPI_Type_contiguous = PMPI_Type_contiguous

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Type_contiguous(int count, MPI_Datatype oldtype,
                                      MPI_Datatype *newtype);

int INTERF_2_INTEL_MPI_Type_contiguous(int count, MPI_Datatype oldtype,
                                       MPI_Datatype *newtype);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Type_contiguous)(int count, MPI_Datatype oldtype,
                                           MPI_Datatype *newtype);
int PMPI_Type_contiguous(int count, MPI_Datatype oldtype,
                         MPI_Datatype *newtype) {
  return INTERFACE_LOCAL_MPI_Type_contiguous(count, oldtype, newtype);
}

int MPI_Type_vector(int count, int blocklength, int stride,
                    MPI_Datatype oldtype, MPI_Datatype *newtype);
#pragma weak MPI_Type_vector = PMPI_Type_vector

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Type_vector(int count, int blocklength, int stride,
                                  MPI_Datatype oldtype, MPI_Datatype *newtype);

int INTERF_2_INTEL_MPI_Type_vector(int count, int blocklength, int stride,
                                   MPI_Datatype oldtype, MPI_Datatype *newtype);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Type_vector)(int count, int blocklength, int stride,
                                       MPI_Datatype oldtype,
                                       MPI_Datatype *newtype);
int PMPI_Type_vector(int count, int blocklength, int stride,
                     MPI_Datatype oldtype, MPI_Datatype *newtype) {
  return INTERFACE_LOCAL_MPI_Type_vector(count, blocklength, stride, oldtype,
                                         newtype);
}

int MPI_Type_hvector(int count, int blocklength, MPI_Aint stride,
                     MPI_Datatype oldtype, MPI_Datatype *newtype);
#pragma weak MPI_Type_hvector = PMPI_Type_hvector

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Type_hvector(int count, int blocklength, MPI_Aint stride,
                                   MPI_Datatype oldtype, MPI_Datatype *newtype);

int INTERF_2_INTEL_MPI_Type_hvector(int count, int blocklength, MPI_Aint stride,
                                    MPI_Datatype oldtype,
                                    MPI_Datatype *newtype);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Type_hvector)(int count, int blocklength,
                                        MPI_Aint stride, MPI_Datatype oldtype,
                                        MPI_Datatype *newtype);
int PMPI_Type_hvector(int count, int blocklength, MPI_Aint stride,
                      MPI_Datatype oldtype, MPI_Datatype *newtype) {
  return INTERFACE_LOCAL_MPI_Type_hvector(count, blocklength, stride, oldtype,
                                          newtype);
}

int MPI_Type_indexed(int count, int *array_of_blocklengths,
                     int *array_of_displacements, MPI_Datatype oldtype,
                     MPI_Datatype *newtype);
#pragma weak MPI_Type_indexed = PMPI_Type_indexed

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Type_indexed(int count, int *array_of_blocklengths,
                                   int *array_of_displacements,
                                   MPI_Datatype oldtype, MPI_Datatype *newtype);

int INTERF_2_INTEL_MPI_Type_indexed(int count, int *array_of_blocklengths,
                                    int *array_of_displacements,
                                    MPI_Datatype oldtype,
                                    MPI_Datatype *newtype);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Type_indexed)(int count, int *array_of_blocklengths,
                                        int *array_of_displacements,
                                        MPI_Datatype oldtype,
                                        MPI_Datatype *newtype);
int PMPI_Type_indexed(int count, int *array_of_blocklengths,
                      int *array_of_displacements, MPI_Datatype oldtype,
                      MPI_Datatype *newtype) {
  return INTERFACE_LOCAL_MPI_Type_indexed(
      count, array_of_blocklengths, array_of_displacements, oldtype, newtype);
}

int MPI_Type_hindexed(int count, int *array_of_blocklengths,
                      MPI_Aint *array_of_displacements, MPI_Datatype oldtype,
                      MPI_Datatype *newtype);
#pragma weak MPI_Type_hindexed = PMPI_Type_hindexed

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Type_hindexed(int count, int *array_of_blocklengths,
                                    MPI_Aint *array_of_displacements,
                                    MPI_Datatype oldtype,
                                    MPI_Datatype *newtype);

int INTERF_2_INTEL_MPI_Type_hindexed(int count, int *array_of_blocklengths,
                                     MPI_Aint *array_of_displacements,
                                     MPI_Datatype oldtype,
                                     MPI_Datatype *newtype);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Type_hindexed)(int count, int *array_of_blocklengths,
                                         MPI_Aint *array_of_displacements,
                                         MPI_Datatype oldtype,
                                         MPI_Datatype *newtype);
int PMPI_Type_hindexed(int count, int *array_of_blocklengths,
                       MPI_Aint *array_of_displacements, MPI_Datatype oldtype,
                       MPI_Datatype *newtype) {
  return INTERFACE_LOCAL_MPI_Type_hindexed(
      count, array_of_blocklengths, array_of_displacements, oldtype, newtype);
}

int MPI_Type_struct(int count, int *array_of_blocklengths,
                    MPI_Aint *array_of_displacements,
                    MPI_Datatype array_of_types[], MPI_Datatype *newtype);
#pragma weak MPI_Type_struct = PMPI_Type_struct

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Type_struct(int count, int *array_of_blocklengths,
                                  MPI_Aint *array_of_displacements,
                                  MPI_Datatype array_of_types[],
                                  MPI_Datatype *newtype);

int INTERF_2_INTEL_MPI_Type_struct(int count, int *array_of_blocklengths,
                                   MPI_Aint *array_of_displacements,
                                   MPI_Datatype array_of_types[],
                                   MPI_Datatype *newtype);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Type_struct)(int count, int *array_of_blocklengths,
                                       MPI_Aint *array_of_displacements,
                                       MPI_Datatype array_of_types[],
                                       MPI_Datatype *newtype);
int PMPI_Type_struct(int count, int *array_of_blocklengths,
                     MPI_Aint *array_of_displacements,
                     MPI_Datatype array_of_types[], MPI_Datatype *newtype) {
  return INTERFACE_LOCAL_MPI_Type_struct(count, array_of_blocklengths,
                                         array_of_displacements, array_of_types,
                                         newtype);
}

int MPI_Address(void *location, MPI_Aint *address);
#pragma weak MPI_Address = PMPI_Address

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Address(void *location, MPI_Aint *address);

int INTERF_2_INTEL_MPI_Address(void *location, MPI_Aint *address);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Address)(void *location, MPI_Aint *address);
int PMPI_Address(void *location, MPI_Aint *address) {
  return INTERFACE_LOCAL_MPI_Address(location, address);
}

int MPI_Type_extent(MPI_Datatype datatype, MPI_Aint *extent);
#pragma weak MPI_Type_extent = PMPI_Type_extent

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Type_extent(MPI_Datatype datatype, MPI_Aint *extent);

int INTERF_2_INTEL_MPI_Type_extent(MPI_Datatype datatype, MPI_Aint *extent);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Type_extent)(MPI_Datatype datatype, MPI_Aint *extent);
int PMPI_Type_extent(MPI_Datatype datatype, MPI_Aint *extent) {
  return INTERFACE_LOCAL_MPI_Type_extent(datatype, extent);
}

int MPI_Type_size(MPI_Datatype datatype, int *size);
#pragma weak MPI_Type_size = PMPI_Type_size

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Type_size(MPI_Datatype datatype, int *size);

int INTERF_2_INTEL_MPI_Type_size(MPI_Datatype datatype, int *size);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Type_size)(MPI_Datatype datatype, int *size);
int PMPI_Type_size(MPI_Datatype datatype, int *size) {
  return INTERFACE_LOCAL_MPI_Type_size(datatype, size);
}

int MPI_Type_lb(MPI_Datatype datatype, MPI_Aint *displacement);
#pragma weak MPI_Type_lb = PMPI_Type_lb

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Type_lb(MPI_Datatype datatype, MPI_Aint *displacement);

int INTERF_2_INTEL_MPI_Type_lb(MPI_Datatype datatype, MPI_Aint *displacement);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Type_lb)(MPI_Datatype datatype,
                                   MPI_Aint *displacement);
int PMPI_Type_lb(MPI_Datatype datatype, MPI_Aint *displacement) {
  return INTERFACE_LOCAL_MPI_Type_lb(datatype, displacement);
}

int MPI_Type_ub(MPI_Datatype datatype, MPI_Aint *displacement);
#pragma weak MPI_Type_ub = PMPI_Type_ub

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Type_ub(MPI_Datatype datatype, MPI_Aint *displacement);

int INTERF_2_INTEL_MPI_Type_ub(MPI_Datatype datatype, MPI_Aint *displacement);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Type_ub)(MPI_Datatype datatype,
                                   MPI_Aint *displacement);
int PMPI_Type_ub(MPI_Datatype datatype, MPI_Aint *displacement) {
  return INTERFACE_LOCAL_MPI_Type_ub(datatype, displacement);
}

int MPI_Type_commit(MPI_Datatype *datatype);
#pragma weak MPI_Type_commit = PMPI_Type_commit

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Type_commit(MPI_Datatype *datatype);

int INTERF_2_INTEL_MPI_Type_commit(MPI_Datatype *datatype);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Type_commit)(MPI_Datatype *datatype);
int PMPI_Type_commit(MPI_Datatype *datatype) {
  return INTERFACE_LOCAL_MPI_Type_commit(datatype);
}

int MPI_Type_free(MPI_Datatype *datatype);
#pragma weak MPI_Type_free = PMPI_Type_free

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Type_free(MPI_Datatype *datatype);

int INTERF_2_INTEL_MPI_Type_free(MPI_Datatype *datatype);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Type_free)(MPI_Datatype *datatype);
int PMPI_Type_free(MPI_Datatype *datatype) {
  return INTERFACE_LOCAL_MPI_Type_free(datatype);
}

int MPI_Get_elements(MPI_Status *status, MPI_Datatype datatype, int *count);
#pragma weak MPI_Get_elements = PMPI_Get_elements

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Get_elements(MPI_Status *status, MPI_Datatype datatype,
                                   int *count);

int INTERF_2_INTEL_MPI_Get_elements(MPI_Status *status, MPI_Datatype datatype,
                                    int *count);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Get_elements)(MPI_Status *status,
                                        MPI_Datatype datatype, int *count);
int PMPI_Get_elements(MPI_Status *status, MPI_Datatype datatype, int *count) {
  return INTERFACE_LOCAL_MPI_Get_elements(status, datatype, count);
}

int MPI_Pack(void *inbuf, int incount, MPI_Datatype datatype, void *outbuf,
             int outsize, int *position, MPI_Comm comm);
#pragma weak MPI_Pack = PMPI_Pack

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Pack(void *inbuf, int incount, MPI_Datatype datatype,
                           void *outbuf, int outsize, int *position,
                           MPI_Comm comm);

int INTERF_2_INTEL_MPI_Pack(void *inbuf, int incount, MPI_Datatype datatype,
                            void *outbuf, int outsize, int *position,
                            MPI_Comm comm);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Pack)(void *inbuf, int incount, MPI_Datatype datatype,
                                void *outbuf, int outsize, int *position,
                                MPI_Comm comm);
int PMPI_Pack(void *inbuf, int incount, MPI_Datatype datatype, void *outbuf,
              int outsize, int *position, MPI_Comm comm) {
  return INTERFACE_LOCAL_MPI_Pack(inbuf, incount, datatype, outbuf, outsize,
                                  position, comm);
}

int MPI_Unpack(void *inbuf, int insize, int *position, void *outbuf,
               int outcount, MPI_Datatype datatype, MPI_Comm comm);
#pragma weak MPI_Unpack = PMPI_Unpack

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Unpack(void *inbuf, int insize, int *position,
                             void *outbuf, int outcount, MPI_Datatype datatype,
                             MPI_Comm comm);

int INTERF_2_INTEL_MPI_Unpack(void *inbuf, int insize, int *position,
                              void *outbuf, int outcount, MPI_Datatype datatype,
                              MPI_Comm comm);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Unpack)(void *inbuf, int insize, int *position,
                                  void *outbuf, int outcount,
                                  MPI_Datatype datatype, MPI_Comm comm);
int PMPI_Unpack(void *inbuf, int insize, int *position, void *outbuf,
                int outcount, MPI_Datatype datatype, MPI_Comm comm) {
  return INTERFACE_LOCAL_MPI_Unpack(inbuf, insize, position, outbuf, outcount,
                                    datatype, comm);
}

int MPI_Pack_size(int incount, MPI_Datatype datatype, MPI_Comm comm, int *size);
#pragma weak MPI_Pack_size = PMPI_Pack_size

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Pack_size(int incount, MPI_Datatype datatype,
                                MPI_Comm comm, int *size);

int INTERF_2_INTEL_MPI_Pack_size(int incount, MPI_Datatype datatype,
                                 MPI_Comm comm, int *size);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Pack_size)(int incount, MPI_Datatype datatype,
                                     MPI_Comm comm, int *size);
int PMPI_Pack_size(int incount, MPI_Datatype datatype, MPI_Comm comm,
                   int *size) {
  return INTERFACE_LOCAL_MPI_Pack_size(incount, datatype, comm, size);
}

int MPI_Barrier(MPI_Comm comm);
#pragma weak MPI_Barrier = PMPI_Barrier

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Barrier(MPI_Comm comm);

int INTERF_2_INTEL_MPI_Barrier(MPI_Comm comm);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Barrier)(MPI_Comm comm);
int PMPI_Barrier(MPI_Comm comm) { return INTERFACE_LOCAL_MPI_Barrier(comm); }

int MPI_Bcast(void *buffer, int count, MPI_Datatype datatype, int root,
              MPI_Comm comm);
#pragma weak MPI_Bcast = PMPI_Bcast

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Bcast(void *buffer, int count, MPI_Datatype datatype,
                            int root, MPI_Comm comm);

int INTERF_2_INTEL_MPI_Bcast(void *buffer, int count, MPI_Datatype datatype,
                             int root, MPI_Comm comm);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Bcast)(void *buffer, int count, MPI_Datatype datatype,
                                 int root, MPI_Comm comm);
int PMPI_Bcast(void *buffer, int count, MPI_Datatype datatype, int root,
               MPI_Comm comm) {
  return INTERFACE_LOCAL_MPI_Bcast(buffer, count, datatype, root, comm);
}

int MPI_Gather(void *sendbuf, int sendcount, MPI_Datatype sendtype,
               void *recvbuf, int recvcount, MPI_Datatype recvtype, int root,
               MPI_Comm comm);
#pragma weak MPI_Gather = PMPI_Gather

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Gather(void *sendbuf, int sendcount,
                             MPI_Datatype sendtype, void *recvbuf,
                             int recvcount, MPI_Datatype recvtype, int root,
                             MPI_Comm comm);

int INTERF_2_INTEL_MPI_Gather(void *sendbuf, int sendcount,
                              MPI_Datatype sendtype, void *recvbuf,
                              int recvcount, MPI_Datatype recvtype, int root,
                              MPI_Comm comm);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Gather)(void *sendbuf, int sendcount,
                                  MPI_Datatype sendtype, void *recvbuf,
                                  int recvcount, MPI_Datatype recvtype,
                                  int root, MPI_Comm comm);
int PMPI_Gather(void *sendbuf, int sendcount, MPI_Datatype sendtype,
                void *recvbuf, int recvcount, MPI_Datatype recvtype, int root,
                MPI_Comm comm) {
  return INTERFACE_LOCAL_MPI_Gather(sendbuf, sendcount, sendtype, recvbuf,
                                    recvcount, recvtype, root, comm);
}

int MPI_Gatherv(void *sendbuf, int sendcount, MPI_Datatype sendtype,
                void *recvbuf, int *recvcounts, int *displs,
                MPI_Datatype recvtype, int root, MPI_Comm comm);
#pragma weak MPI_Gatherv = PMPI_Gatherv

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Gatherv(void *sendbuf, int sendcount,
                              MPI_Datatype sendtype, void *recvbuf,
                              int *recvcounts, int *displs,
                              MPI_Datatype recvtype, int root, MPI_Comm comm);

int INTERF_2_INTEL_MPI_Gatherv(void *sendbuf, int sendcount,
                               MPI_Datatype sendtype, void *recvbuf,
                               int *recvcounts, int *displs,
                               MPI_Datatype recvtype, int root, MPI_Comm comm);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Gatherv)(void *sendbuf, int sendcount,
                                   MPI_Datatype sendtype, void *recvbuf,
                                   int *recvcounts, int *displs,
                                   MPI_Datatype recvtype, int root,
                                   MPI_Comm comm);
int PMPI_Gatherv(void *sendbuf, int sendcount, MPI_Datatype sendtype,
                 void *recvbuf, int *recvcounts, int *displs,
                 MPI_Datatype recvtype, int root, MPI_Comm comm) {
  return INTERFACE_LOCAL_MPI_Gatherv(sendbuf, sendcount, sendtype, recvbuf,
                                     recvcounts, displs, recvtype, root, comm);
}

int MPI_Scatter(void *sendbuf, int sendcount, MPI_Datatype sendtype,
                void *recvbuf, int recvcount, MPI_Datatype recvtype, int root,
                MPI_Comm comm);
#pragma weak MPI_Scatter = PMPI_Scatter

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Scatter(void *sendbuf, int sendcount,
                              MPI_Datatype sendtype, void *recvbuf,
                              int recvcount, MPI_Datatype recvtype, int root,
                              MPI_Comm comm);

int INTERF_2_INTEL_MPI_Scatter(void *sendbuf, int sendcount,
                               MPI_Datatype sendtype, void *recvbuf,
                               int recvcount, MPI_Datatype recvtype, int root,
                               MPI_Comm comm);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Scatter)(void *sendbuf, int sendcount,
                                   MPI_Datatype sendtype, void *recvbuf,
                                   int recvcount, MPI_Datatype recvtype,
                                   int root, MPI_Comm comm);
int PMPI_Scatter(void *sendbuf, int sendcount, MPI_Datatype sendtype,
                 void *recvbuf, int recvcount, MPI_Datatype recvtype, int root,
                 MPI_Comm comm) {
  return INTERFACE_LOCAL_MPI_Scatter(sendbuf, sendcount, sendtype, recvbuf,
                                     recvcount, recvtype, root, comm);
}

int MPI_Scatterv(void *sendbuf, int *sendcounts, int *displs,
                 MPI_Datatype sendtype, void *recvbuf, int recvcount,
                 MPI_Datatype recvtype, int root, MPI_Comm comm);
#pragma weak MPI_Scatterv = PMPI_Scatterv

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Scatterv(void *sendbuf, int *sendcounts, int *displs,
                               MPI_Datatype sendtype, void *recvbuf,
                               int recvcount, MPI_Datatype recvtype, int root,
                               MPI_Comm comm);

int INTERF_2_INTEL_MPI_Scatterv(void *sendbuf, int *sendcounts, int *displs,
                                MPI_Datatype sendtype, void *recvbuf,
                                int recvcount, MPI_Datatype recvtype, int root,
                                MPI_Comm comm);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Scatterv)(void *sendbuf, int *sendcounts, int *displs,
                                    MPI_Datatype sendtype, void *recvbuf,
                                    int recvcount, MPI_Datatype recvtype,
                                    int root, MPI_Comm comm);
int PMPI_Scatterv(void *sendbuf, int *sendcounts, int *displs,
                  MPI_Datatype sendtype, void *recvbuf, int recvcount,
                  MPI_Datatype recvtype, int root, MPI_Comm comm) {
  return INTERFACE_LOCAL_MPI_Scatterv(sendbuf, sendcounts, displs, sendtype,
                                      recvbuf, recvcount, recvtype, root, comm);
}

int MPI_Allgather(void *sendbuf, int sendcount, MPI_Datatype sendtype,
                  void *recvbuf, int recvcount, MPI_Datatype recvtype,
                  MPI_Comm comm);
#pragma weak MPI_Allgather = PMPI_Allgather

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Allgather(void *sendbuf, int sendcount,
                                MPI_Datatype sendtype, void *recvbuf,
                                int recvcount, MPI_Datatype recvtype,
                                MPI_Comm comm);

int INTERF_2_INTEL_MPI_Allgather(void *sendbuf, int sendcount,
                                 MPI_Datatype sendtype, void *recvbuf,
                                 int recvcount, MPI_Datatype recvtype,
                                 MPI_Comm comm);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Allgather)(void *sendbuf, int sendcount,
                                     MPI_Datatype sendtype, void *recvbuf,
                                     int recvcount, MPI_Datatype recvtype,
                                     MPI_Comm comm);
int PMPI_Allgather(void *sendbuf, int sendcount, MPI_Datatype sendtype,
                   void *recvbuf, int recvcount, MPI_Datatype recvtype,
                   MPI_Comm comm) {
  return INTERFACE_LOCAL_MPI_Allgather(sendbuf, sendcount, sendtype, recvbuf,
                                       recvcount, recvtype, comm);
}

int MPI_Allgatherv(void *sendbuf, int sendcount, MPI_Datatype sendtype,
                   void *recvbuf, int *recvcounts, int *displs,
                   MPI_Datatype recvtype, MPI_Comm comm);
#pragma weak MPI_Allgatherv = PMPI_Allgatherv

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Allgatherv(void *sendbuf, int sendcount,
                                 MPI_Datatype sendtype, void *recvbuf,
                                 int *recvcounts, int *displs,
                                 MPI_Datatype recvtype, MPI_Comm comm);

int INTERF_2_INTEL_MPI_Allgatherv(void *sendbuf, int sendcount,
                                  MPI_Datatype sendtype, void *recvbuf,
                                  int *recvcounts, int *displs,
                                  MPI_Datatype recvtype, MPI_Comm comm);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Allgatherv)(void *sendbuf, int sendcount,
                                      MPI_Datatype sendtype, void *recvbuf,
                                      int *recvcounts, int *displs,
                                      MPI_Datatype recvtype, MPI_Comm comm);
int PMPI_Allgatherv(void *sendbuf, int sendcount, MPI_Datatype sendtype,
                    void *recvbuf, int *recvcounts, int *displs,
                    MPI_Datatype recvtype, MPI_Comm comm) {
  return INTERFACE_LOCAL_MPI_Allgatherv(sendbuf, sendcount, sendtype, recvbuf,
                                        recvcounts, displs, recvtype, comm);
}

int MPI_Alltoall(void *sendbuf, int sendcount, MPI_Datatype sendtype,
                 void *recvbuf, int recvcount, MPI_Datatype recvtype,
                 MPI_Comm comm);
#pragma weak MPI_Alltoall = PMPI_Alltoall

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Alltoall(void *sendbuf, int sendcount,
                               MPI_Datatype sendtype, void *recvbuf,
                               int recvcount, MPI_Datatype recvtype,
                               MPI_Comm comm);

int INTERF_2_INTEL_MPI_Alltoall(void *sendbuf, int sendcount,
                                MPI_Datatype sendtype, void *recvbuf,
                                int recvcount, MPI_Datatype recvtype,
                                MPI_Comm comm);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Alltoall)(void *sendbuf, int sendcount,
                                    MPI_Datatype sendtype, void *recvbuf,
                                    int recvcount, MPI_Datatype recvtype,
                                    MPI_Comm comm);
int PMPI_Alltoall(void *sendbuf, int sendcount, MPI_Datatype sendtype,
                  void *recvbuf, int recvcount, MPI_Datatype recvtype,
                  MPI_Comm comm) {
  return INTERFACE_LOCAL_MPI_Alltoall(sendbuf, sendcount, sendtype, recvbuf,
                                      recvcount, recvtype, comm);
}

int MPI_Alltoallv(void *sendbuf, int *sendcounts, int *sdispls,
                  MPI_Datatype sendtype, void *recvbuf, int *recvcounts,
                  int *rdispls, MPI_Datatype recvtype, MPI_Comm comm);
#pragma weak MPI_Alltoallv = PMPI_Alltoallv

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Alltoallv(void *sendbuf, int *sendcounts, int *sdispls,
                                MPI_Datatype sendtype, void *recvbuf,
                                int *recvcounts, int *rdispls,
                                MPI_Datatype recvtype, MPI_Comm comm);

int INTERF_2_INTEL_MPI_Alltoallv(void *sendbuf, int *sendcounts, int *sdispls,
                                 MPI_Datatype sendtype, void *recvbuf,
                                 int *recvcounts, int *rdispls,
                                 MPI_Datatype recvtype, MPI_Comm comm);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Alltoallv)(void *sendbuf, int *sendcounts,
                                     int *sdispls, MPI_Datatype sendtype,
                                     void *recvbuf, int *recvcounts,
                                     int *rdispls, MPI_Datatype recvtype,
                                     MPI_Comm comm);
int PMPI_Alltoallv(void *sendbuf, int *sendcounts, int *sdispls,
                   MPI_Datatype sendtype, void *recvbuf, int *recvcounts,
                   int *rdispls, MPI_Datatype recvtype, MPI_Comm comm) {
  return INTERFACE_LOCAL_MPI_Alltoallv(sendbuf, sendcounts, sdispls, sendtype,
                                       recvbuf, recvcounts, rdispls, recvtype,
                                       comm);
}

int MPI_Exscan(void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype,
               MPI_Op op, MPI_Comm comm);
#pragma weak MPI_Exscan = PMPI_Exscan

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Exscan(void *sendbuf, void *recvbuf, int count,
                             MPI_Datatype datatype, MPI_Op op, MPI_Comm comm);

int INTERF_2_INTEL_MPI_Exscan(void *sendbuf, void *recvbuf, int count,
                              MPI_Datatype datatype, MPI_Op op, MPI_Comm comm);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Exscan)(void *sendbuf, void *recvbuf, int count,
                                  MPI_Datatype datatype, MPI_Op op,
                                  MPI_Comm comm);
int PMPI_Exscan(void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype,
                MPI_Op op, MPI_Comm comm) {
  return INTERFACE_LOCAL_MPI_Exscan(sendbuf, recvbuf, count, datatype, op,
                                    comm);
}

int MPI_Reduce(void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype,
               MPI_Op op, int root, MPI_Comm comm);
#pragma weak MPI_Reduce = PMPI_Reduce

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Reduce(void *sendbuf, void *recvbuf, int count,
                             MPI_Datatype datatype, MPI_Op op, int root,
                             MPI_Comm comm);

int INTERF_2_INTEL_MPI_Reduce(void *sendbuf, void *recvbuf, int count,
                              MPI_Datatype datatype, MPI_Op op, int root,
                              MPI_Comm comm);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Reduce)(void *sendbuf, void *recvbuf, int count,
                                  MPI_Datatype datatype, MPI_Op op, int root,
                                  MPI_Comm comm);
int PMPI_Reduce(void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype,
                MPI_Op op, int root, MPI_Comm comm) {
  return INTERFACE_LOCAL_MPI_Reduce(sendbuf, recvbuf, count, datatype, op, root,
                                    comm);
}

int MPI_Op_create(MPI_User_function *user_fn, int commute, MPI_Op *op);
#pragma weak MPI_Op_create = PMPI_Op_create

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Op_create(MPI_User_function *user_fn, int commute,
                                MPI_Op *op);

int INTERF_2_INTEL_MPI_Op_create(MPI_User_function *user_fn, int commute,
                                 MPI_Op *op);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Op_create)(MPI_User_function *user_fn, int commute,
                                     MPI_Op *op);
int PMPI_Op_create(MPI_User_function *user_fn, int commute, MPI_Op *op) {
  return INTERFACE_LOCAL_MPI_Op_create(user_fn, commute, op);
}

int MPI_Op_free(MPI_Op *op);
#pragma weak MPI_Op_free = PMPI_Op_free

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Op_free(MPI_Op *op);

int INTERF_2_INTEL_MPI_Op_free(MPI_Op *op);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Op_free)(MPI_Op *op);
int PMPI_Op_free(MPI_Op *op) { return INTERFACE_LOCAL_MPI_Op_free(op); }

int MPI_Allreduce(void *sendbuf, void *recvbuf, int count,
                  MPI_Datatype datatype, MPI_Op op, MPI_Comm comm);
#pragma weak MPI_Allreduce = PMPI_Allreduce

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Allreduce(void *sendbuf, void *recvbuf, int count,
                                MPI_Datatype datatype, MPI_Op op,
                                MPI_Comm comm);

int INTERF_2_INTEL_MPI_Allreduce(void *sendbuf, void *recvbuf, int count,
                                 MPI_Datatype datatype, MPI_Op op,
                                 MPI_Comm comm);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Allreduce)(void *sendbuf, void *recvbuf, int count,
                                     MPI_Datatype datatype, MPI_Op op,
                                     MPI_Comm comm);
int PMPI_Allreduce(void *sendbuf, void *recvbuf, int count,
                   MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) {
  return INTERFACE_LOCAL_MPI_Allreduce(sendbuf, recvbuf, count, datatype, op,
                                       comm);
}

int MPI_Scan(void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype,
             MPI_Op op, MPI_Comm comm);
#pragma weak MPI_Scan = PMPI_Scan

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Scan(void *sendbuf, void *recvbuf, int count,
                           MPI_Datatype datatype, MPI_Op op, MPI_Comm comm);

int INTERF_2_INTEL_MPI_Scan(void *sendbuf, void *recvbuf, int count,
                            MPI_Datatype datatype, MPI_Op op, MPI_Comm comm);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Scan)(void *sendbuf, void *recvbuf, int count,
                                MPI_Datatype datatype, MPI_Op op,
                                MPI_Comm comm);
int PMPI_Scan(void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype,
              MPI_Op op, MPI_Comm comm) {
  return INTERFACE_LOCAL_MPI_Scan(sendbuf, recvbuf, count, datatype, op, comm);
}

int MPI_Group_size(MPI_Group group, int *size);
#pragma weak MPI_Group_size = PMPI_Group_size

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Group_size(MPI_Group group, int *size);

int INTERF_2_INTEL_MPI_Group_size(MPI_Group group, int *size);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Group_size)(MPI_Group group, int *size);
int PMPI_Group_size(MPI_Group group, int *size) {
  return INTERFACE_LOCAL_MPI_Group_size(group, size);
}

int MPI_Group_rank(MPI_Group group, int *rank);
#pragma weak MPI_Group_rank = PMPI_Group_rank

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Group_rank(MPI_Group group, int *rank);

int INTERF_2_INTEL_MPI_Group_rank(MPI_Group group, int *rank);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Group_rank)(MPI_Group group, int *rank);
int PMPI_Group_rank(MPI_Group group, int *rank) {
  return INTERFACE_LOCAL_MPI_Group_rank(group, rank);
}

int MPI_Group_compare(MPI_Group group1, MPI_Group group2, int *result);
#pragma weak MPI_Group_compare = PMPI_Group_compare

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Group_compare(MPI_Group group1, MPI_Group group2,
                                    int *result);

int INTERF_2_INTEL_MPI_Group_compare(MPI_Group group1, MPI_Group group2,
                                     int *result);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Group_compare)(MPI_Group group1, MPI_Group group2,
                                         int *result);
int PMPI_Group_compare(MPI_Group group1, MPI_Group group2, int *result) {
  return INTERFACE_LOCAL_MPI_Group_compare(group1, group2, result);
}

int MPI_Comm_group(MPI_Comm comm, MPI_Group *group);
#pragma weak MPI_Comm_group = PMPI_Comm_group

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Comm_group(MPI_Comm comm, MPI_Group *group);

int INTERF_2_INTEL_MPI_Comm_group(MPI_Comm comm, MPI_Group *group);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Comm_group)(MPI_Comm comm, MPI_Group *group);
int PMPI_Comm_group(MPI_Comm comm, MPI_Group *group) {
  return INTERFACE_LOCAL_MPI_Comm_group(comm, group);
}

int MPI_Group_union(MPI_Group group1, MPI_Group group2, MPI_Group *newgroup);
#pragma weak MPI_Group_union = PMPI_Group_union

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Group_union(MPI_Group group1, MPI_Group group2,
                                  MPI_Group *newgroup);

int INTERF_2_INTEL_MPI_Group_union(MPI_Group group1, MPI_Group group2,
                                   MPI_Group *newgroup);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Group_union)(MPI_Group group1, MPI_Group group2,
                                       MPI_Group *newgroup);
int PMPI_Group_union(MPI_Group group1, MPI_Group group2, MPI_Group *newgroup) {
  return INTERFACE_LOCAL_MPI_Group_union(group1, group2, newgroup);
}

int MPI_Group_intersection(MPI_Group group1, MPI_Group group2,
                           MPI_Group *newgroup);
#pragma weak MPI_Group_intersection = PMPI_Group_intersection

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Group_intersection(MPI_Group group1, MPI_Group group2,
                                         MPI_Group *newgroup);

int INTERF_2_INTEL_MPI_Group_intersection(MPI_Group group1, MPI_Group group2,
                                          MPI_Group *newgroup);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Group_intersection)(MPI_Group group1,
                                              MPI_Group group2,
                                              MPI_Group *newgroup);
int PMPI_Group_intersection(MPI_Group group1, MPI_Group group2,
                            MPI_Group *newgroup) {
  return INTERFACE_LOCAL_MPI_Group_intersection(group1, group2, newgroup);
}

int MPI_Group_difference(MPI_Group group1, MPI_Group group2,
                         MPI_Group *newgroup);
#pragma weak MPI_Group_difference = PMPI_Group_difference

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Group_difference(MPI_Group group1, MPI_Group group2,
                                       MPI_Group *newgroup);

int INTERF_2_INTEL_MPI_Group_difference(MPI_Group group1, MPI_Group group2,
                                        MPI_Group *newgroup);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Group_difference)(MPI_Group group1, MPI_Group group2,
                                            MPI_Group *newgroup);
int PMPI_Group_difference(MPI_Group group1, MPI_Group group2,
                          MPI_Group *newgroup) {
  return INTERFACE_LOCAL_MPI_Group_difference(group1, group2, newgroup);
}

int MPI_Group_free(MPI_Group *group);
#pragma weak MPI_Group_free = PMPI_Group_free

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Group_free(MPI_Group *group);

int INTERF_2_INTEL_MPI_Group_free(MPI_Group *group);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Group_free)(MPI_Group *group);
int PMPI_Group_free(MPI_Group *group) {
  return INTERFACE_LOCAL_MPI_Group_free(group);
}

int MPI_Comm_size(MPI_Comm comm, int *size);
#pragma weak MPI_Comm_size = PMPI_Comm_size

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Comm_size(MPI_Comm comm, int *size);

int INTERF_2_INTEL_MPI_Comm_size(MPI_Comm comm, int *size);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Comm_size)(MPI_Comm comm, int *size);
int PMPI_Comm_size(MPI_Comm comm, int *size) {
  return INTERFACE_LOCAL_MPI_Comm_size(comm, size);
}

int MPI_Comm_rank(MPI_Comm comm, int *rank);
#pragma weak MPI_Comm_rank = PMPI_Comm_rank

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Comm_rank(MPI_Comm comm, int *rank);

int INTERF_2_INTEL_MPI_Comm_rank(MPI_Comm comm, int *rank);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Comm_rank)(MPI_Comm comm, int *rank);
int PMPI_Comm_rank(MPI_Comm comm, int *rank) {
  return INTERFACE_LOCAL_MPI_Comm_rank(comm, rank);
}

int MPI_Comm_compare(MPI_Comm comm1, MPI_Comm comm2, int *result);
#pragma weak MPI_Comm_compare = PMPI_Comm_compare

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Comm_compare(MPI_Comm comm1, MPI_Comm comm2, int *result);

int INTERF_2_INTEL_MPI_Comm_compare(MPI_Comm comm1, MPI_Comm comm2,
                                    int *result);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Comm_compare)(MPI_Comm comm1, MPI_Comm comm2,
                                        int *result);
int PMPI_Comm_compare(MPI_Comm comm1, MPI_Comm comm2, int *result) {
  return INTERFACE_LOCAL_MPI_Comm_compare(comm1, comm2, result);
}

int MPI_Comm_dup(MPI_Comm comm, MPI_Comm *newcomm);
#pragma weak MPI_Comm_dup = PMPI_Comm_dup

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Comm_dup(MPI_Comm comm, MPI_Comm *newcomm);

int INTERF_2_INTEL_MPI_Comm_dup(MPI_Comm comm, MPI_Comm *newcomm);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Comm_dup)(MPI_Comm comm, MPI_Comm *newcomm);
int PMPI_Comm_dup(MPI_Comm comm, MPI_Comm *newcomm) {
  return INTERFACE_LOCAL_MPI_Comm_dup(comm, newcomm);
}

int MPI_Comm_dup_with_info(MPI_Comm comm, MPI_Info info, MPI_Comm *newcomm);
#pragma weak MPI_Comm_dup_with_info = PMPI_Comm_dup_with_info

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Comm_dup_with_info(MPI_Comm comm, MPI_Info info,
                                         MPI_Comm *newcomm);

int INTERF_2_INTEL_MPI_Comm_dup_with_info(MPI_Comm comm, MPI_Info info,
                                          MPI_Comm *newcomm);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Comm_dup_with_info)(MPI_Comm comm, MPI_Info info,
                                              MPI_Comm *newcomm);
int PMPI_Comm_dup_with_info(MPI_Comm comm, MPI_Info info, MPI_Comm *newcomm) {
  return INTERFACE_LOCAL_MPI_Comm_dup_with_info(comm, info, newcomm);
}

int MPI_Comm_create(MPI_Comm comm, MPI_Group group, MPI_Comm *newcomm);
#pragma weak MPI_Comm_create = PMPI_Comm_create

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Comm_create(MPI_Comm comm, MPI_Group group,
                                  MPI_Comm *newcomm);

int INTERF_2_INTEL_MPI_Comm_create(MPI_Comm comm, MPI_Group group,
                                   MPI_Comm *newcomm);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Comm_create)(MPI_Comm comm, MPI_Group group,
                                       MPI_Comm *newcomm);
int PMPI_Comm_create(MPI_Comm comm, MPI_Group group, MPI_Comm *newcomm) {
  return INTERFACE_LOCAL_MPI_Comm_create(comm, group, newcomm);
}

int MPI_Comm_split(MPI_Comm comm, int color, int key, MPI_Comm *newcomm);
#pragma weak MPI_Comm_split = PMPI_Comm_split

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Comm_split(MPI_Comm comm, int color, int key,
                                 MPI_Comm *newcomm);

int INTERF_2_INTEL_MPI_Comm_split(MPI_Comm comm, int color, int key,
                                  MPI_Comm *newcomm);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Comm_split)(MPI_Comm comm, int color, int key,
                                      MPI_Comm *newcomm);
int PMPI_Comm_split(MPI_Comm comm, int color, int key, MPI_Comm *newcomm) {
  return INTERFACE_LOCAL_MPI_Comm_split(comm, color, key, newcomm);
}

int MPI_Comm_free(MPI_Comm *comm);
#pragma weak MPI_Comm_free = PMPI_Comm_free

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Comm_free(MPI_Comm *comm);

int INTERF_2_INTEL_MPI_Comm_free(MPI_Comm *comm);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Comm_free)(MPI_Comm *comm);
int PMPI_Comm_free(MPI_Comm *comm) {
  return INTERFACE_LOCAL_MPI_Comm_free(comm);
}

int MPI_Comm_test_inter(MPI_Comm comm, int *flag);
#pragma weak MPI_Comm_test_inter = PMPI_Comm_test_inter

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Comm_test_inter(MPI_Comm comm, int *flag);

int INTERF_2_INTEL_MPI_Comm_test_inter(MPI_Comm comm, int *flag);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Comm_test_inter)(MPI_Comm comm, int *flag);
int PMPI_Comm_test_inter(MPI_Comm comm, int *flag) {
  return INTERFACE_LOCAL_MPI_Comm_test_inter(comm, flag);
}

int MPI_Comm_remote_size(MPI_Comm comm, int *size);
#pragma weak MPI_Comm_remote_size = PMPI_Comm_remote_size

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Comm_remote_size(MPI_Comm comm, int *size);

int INTERF_2_INTEL_MPI_Comm_remote_size(MPI_Comm comm, int *size);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Comm_remote_size)(MPI_Comm comm, int *size);
int PMPI_Comm_remote_size(MPI_Comm comm, int *size) {
  return INTERFACE_LOCAL_MPI_Comm_remote_size(comm, size);
}

int MPI_Comm_remote_group(MPI_Comm comm, MPI_Group *group);
#pragma weak MPI_Comm_remote_group = PMPI_Comm_remote_group

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Comm_remote_group(MPI_Comm comm, MPI_Group *group);

int INTERF_2_INTEL_MPI_Comm_remote_group(MPI_Comm comm, MPI_Group *group);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Comm_remote_group)(MPI_Comm comm, MPI_Group *group);
int PMPI_Comm_remote_group(MPI_Comm comm, MPI_Group *group) {
  return INTERFACE_LOCAL_MPI_Comm_remote_group(comm, group);
}

int MPI_Intercomm_create(MPI_Comm local_comm, int local_leader,
                         MPI_Comm peer_comm, int remote_leader, int tag,
                         MPI_Comm *newintercomm);
#pragma weak MPI_Intercomm_create = PMPI_Intercomm_create

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Intercomm_create(MPI_Comm local_comm, int local_leader,
                                       MPI_Comm peer_comm, int remote_leader,
                                       int tag, MPI_Comm *newintercomm);

int INTERF_2_INTEL_MPI_Intercomm_create(MPI_Comm local_comm, int local_leader,
                                        MPI_Comm peer_comm, int remote_leader,
                                        int tag, MPI_Comm *newintercomm);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Intercomm_create)(MPI_Comm local_comm,
                                            int local_leader,
                                            MPI_Comm peer_comm,
                                            int remote_leader, int tag,
                                            MPI_Comm *newintercomm);
int PMPI_Intercomm_create(MPI_Comm local_comm, int local_leader,
                          MPI_Comm peer_comm, int remote_leader, int tag,
                          MPI_Comm *newintercomm) {
  return INTERFACE_LOCAL_MPI_Intercomm_create(
      local_comm, local_leader, peer_comm, remote_leader, tag, newintercomm);
}

int MPI_Intercomm_merge(MPI_Comm intercomm, int high, MPI_Comm *newintracomm);
#pragma weak MPI_Intercomm_merge = PMPI_Intercomm_merge

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Intercomm_merge(MPI_Comm intercomm, int high,
                                      MPI_Comm *newintracomm);

int INTERF_2_INTEL_MPI_Intercomm_merge(MPI_Comm intercomm, int high,
                                       MPI_Comm *newintracomm);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Intercomm_merge)(MPI_Comm intercomm, int high,
                                           MPI_Comm *newintracomm);
int PMPI_Intercomm_merge(MPI_Comm intercomm, int high, MPI_Comm *newintracomm) {
  return INTERFACE_LOCAL_MPI_Intercomm_merge(intercomm, high, newintracomm);
}

int MPI_Keyval_create(MPI_Copy_function *copy_fn,
                      MPI_Delete_function *delete_fn, int *keyval,
                      void *extra_state);
#pragma weak MPI_Keyval_create = PMPI_Keyval_create

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Keyval_create(MPI_Copy_function *copy_fn,
                                    MPI_Delete_function *delete_fn, int *keyval,
                                    void *extra_state);

int INTERF_2_INTEL_MPI_Keyval_create(MPI_Copy_function *copy_fn,
                                     MPI_Delete_function *delete_fn,
                                     int *keyval, void *extra_state);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Keyval_create)(MPI_Copy_function *copy_fn,
                                         MPI_Delete_function *delete_fn,
                                         int *keyval, void *extra_state);
int PMPI_Keyval_create(MPI_Copy_function *copy_fn,
                       MPI_Delete_function *delete_fn, int *keyval,
                       void *extra_state) {
  return INTERFACE_LOCAL_MPI_Keyval_create(copy_fn, delete_fn, keyval,
                                           extra_state);
}

int MPI_Keyval_free(int *keyval);
#pragma weak MPI_Keyval_free = PMPI_Keyval_free

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Keyval_free(int *keyval);

int INTERF_2_INTEL_MPI_Keyval_free(int *keyval);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Keyval_free)(int *keyval);
int PMPI_Keyval_free(int *keyval) {
  return INTERFACE_LOCAL_MPI_Keyval_free(keyval);
}

int MPI_Attr_put(MPI_Comm comm, int keyval, void *attribute_val);
#pragma weak MPI_Attr_put = PMPI_Attr_put

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Attr_put(MPI_Comm comm, int keyval, void *attribute_val);

int INTERF_2_INTEL_MPI_Attr_put(MPI_Comm comm, int keyval, void *attribute_val);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Attr_put)(MPI_Comm comm, int keyval,
                                    void *attribute_val);
int PMPI_Attr_put(MPI_Comm comm, int keyval, void *attribute_val) {
  return INTERFACE_LOCAL_MPI_Attr_put(comm, keyval, attribute_val);
}

int MPI_Attr_get(MPI_Comm comm, int keyval, void *attribute_val, int *flag);
#pragma weak MPI_Attr_get = PMPI_Attr_get

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Attr_get(MPI_Comm comm, int keyval, void *attribute_val,
                               int *flag);

int INTERF_2_INTEL_MPI_Attr_get(MPI_Comm comm, int keyval, void *attribute_val,
                                int *flag);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Attr_get)(MPI_Comm comm, int keyval,
                                    void *attribute_val, int *flag);
int PMPI_Attr_get(MPI_Comm comm, int keyval, void *attribute_val, int *flag) {
  return INTERFACE_LOCAL_MPI_Attr_get(comm, keyval, attribute_val, flag);
}

int MPI_Attr_delete(MPI_Comm comm, int keyval);
#pragma weak MPI_Attr_delete = PMPI_Attr_delete

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Attr_delete(MPI_Comm comm, int keyval);

int INTERF_2_INTEL_MPI_Attr_delete(MPI_Comm comm, int keyval);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Attr_delete)(MPI_Comm comm, int keyval);
int PMPI_Attr_delete(MPI_Comm comm, int keyval) {
  return INTERFACE_LOCAL_MPI_Attr_delete(comm, keyval);
}

int MPI_Topo_test(MPI_Comm comm, int *status);
#pragma weak MPI_Topo_test = PMPI_Topo_test

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Topo_test(MPI_Comm comm, int *status);

int INTERF_2_INTEL_MPI_Topo_test(MPI_Comm comm, int *status);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Topo_test)(MPI_Comm comm, int *status);
int PMPI_Topo_test(MPI_Comm comm, int *status) {
  return INTERFACE_LOCAL_MPI_Topo_test(comm, status);
}

int MPI_Graphdims_get(MPI_Comm comm, int *nnodes, int *nedges);
#pragma weak MPI_Graphdims_get = PMPI_Graphdims_get

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Graphdims_get(MPI_Comm comm, int *nnodes, int *nedges);

int INTERF_2_INTEL_MPI_Graphdims_get(MPI_Comm comm, int *nnodes, int *nedges);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Graphdims_get)(MPI_Comm comm, int *nnodes,
                                         int *nedges);
int PMPI_Graphdims_get(MPI_Comm comm, int *nnodes, int *nedges) {
  return INTERFACE_LOCAL_MPI_Graphdims_get(comm, nnodes, nedges);
}

int MPI_Cartdim_get(MPI_Comm comm, int *ndims);
#pragma weak MPI_Cartdim_get = PMPI_Cartdim_get

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Cartdim_get(MPI_Comm comm, int *ndims);

int INTERF_2_INTEL_MPI_Cartdim_get(MPI_Comm comm, int *ndims);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Cartdim_get)(MPI_Comm comm, int *ndims);
int PMPI_Cartdim_get(MPI_Comm comm, int *ndims) {
  return INTERFACE_LOCAL_MPI_Cartdim_get(comm, ndims);
}

int MPI_Graph_neighbors_count(MPI_Comm comm, int rank, int *nneighbors);
#pragma weak MPI_Graph_neighbors_count = PMPI_Graph_neighbors_count

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Graph_neighbors_count(MPI_Comm comm, int rank,
                                            int *nneighbors);

int INTERF_2_INTEL_MPI_Graph_neighbors_count(MPI_Comm comm, int rank,
                                             int *nneighbors);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Graph_neighbors_count)(MPI_Comm comm, int rank,
                                                 int *nneighbors);
int PMPI_Graph_neighbors_count(MPI_Comm comm, int rank, int *nneighbors) {
  return INTERFACE_LOCAL_MPI_Graph_neighbors_count(comm, rank, nneighbors);
}

int MPI_Cart_shift(MPI_Comm comm, int direction, int disp, int *rank_source,
                   int *rank_dest);
#pragma weak MPI_Cart_shift = PMPI_Cart_shift

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Cart_shift(MPI_Comm comm, int direction, int disp,
                                 int *rank_source, int *rank_dest);

int INTERF_2_INTEL_MPI_Cart_shift(MPI_Comm comm, int direction, int disp,
                                  int *rank_source, int *rank_dest);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Cart_shift)(MPI_Comm comm, int direction, int disp,
                                      int *rank_source, int *rank_dest);
int PMPI_Cart_shift(MPI_Comm comm, int direction, int disp, int *rank_source,
                    int *rank_dest) {
  return INTERFACE_LOCAL_MPI_Cart_shift(comm, direction, disp, rank_source,
                                        rank_dest);
}

int MPI_Get_processor_name(char *name, int *resultlen);
#pragma weak MPI_Get_processor_name = PMPI_Get_processor_name

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Get_processor_name(char *name, int *resultlen);

int INTERF_2_INTEL_MPI_Get_processor_name(char *name, int *resultlen);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Get_processor_name)(char *name, int *resultlen);
int PMPI_Get_processor_name(char *name, int *resultlen) {
  return INTERFACE_LOCAL_MPI_Get_processor_name(name, resultlen);
}

int MPI_Get_version(int *version, int *subversion);
#pragma weak MPI_Get_version = PMPI_Get_version

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Get_version(int *version, int *subversion);

int INTERF_2_INTEL_MPI_Get_version(int *version, int *subversion);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Get_version)(int *version, int *subversion);
int PMPI_Get_version(int *version, int *subversion) {
  return INTERFACE_LOCAL_MPI_Get_version(version, subversion);
}

int MPI_Get_library_version(char *version, int *resultlen);
#pragma weak MPI_Get_library_version = PMPI_Get_library_version

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Get_library_version(char *version, int *resultlen);

int INTERF_2_INTEL_MPI_Get_library_version(char *version, int *resultlen);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Get_library_version)(char *version, int *resultlen);
int PMPI_Get_library_version(char *version, int *resultlen) {
  return INTERFACE_LOCAL_MPI_Get_library_version(version, resultlen);
}

int MPI_Errhandler_create(MPI_Handler_function *function,
                          MPI_Errhandler *errhandler);
#pragma weak MPI_Errhandler_create = PMPI_Errhandler_create

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Errhandler_create(MPI_Handler_function *function,
                                        MPI_Errhandler *errhandler);

int INTERF_2_INTEL_MPI_Errhandler_create(MPI_Handler_function *function,
                                         MPI_Errhandler *errhandler);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Errhandler_create)(MPI_Handler_function *function,
                                             MPI_Errhandler *errhandler);
int PMPI_Errhandler_create(MPI_Handler_function *function,
                           MPI_Errhandler *errhandler) {
  return INTERFACE_LOCAL_MPI_Errhandler_create(function, errhandler);
}

int MPI_Errhandler_set(MPI_Comm comm, MPI_Errhandler errhandler);
#pragma weak MPI_Errhandler_set = PMPI_Errhandler_set

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Errhandler_set(MPI_Comm comm, MPI_Errhandler errhandler);

int INTERF_2_INTEL_MPI_Errhandler_set(MPI_Comm comm, MPI_Errhandler errhandler);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Errhandler_set)(MPI_Comm comm,
                                          MPI_Errhandler errhandler);
int PMPI_Errhandler_set(MPI_Comm comm, MPI_Errhandler errhandler) {
  return INTERFACE_LOCAL_MPI_Errhandler_set(comm, errhandler);
}

int MPI_Errhandler_get(MPI_Comm comm, MPI_Errhandler *errhandler);
#pragma weak MPI_Errhandler_get = PMPI_Errhandler_get

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Errhandler_get(MPI_Comm comm, MPI_Errhandler *errhandler);

int INTERF_2_INTEL_MPI_Errhandler_get(MPI_Comm comm,
                                      MPI_Errhandler *errhandler);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Errhandler_get)(MPI_Comm comm,
                                          MPI_Errhandler *errhandler);
int PMPI_Errhandler_get(MPI_Comm comm, MPI_Errhandler *errhandler) {
  return INTERFACE_LOCAL_MPI_Errhandler_get(comm, errhandler);
}

int MPI_Errhandler_free(MPI_Errhandler *errhandler);
#pragma weak MPI_Errhandler_free = PMPI_Errhandler_free

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Errhandler_free(MPI_Errhandler *errhandler);

int INTERF_2_INTEL_MPI_Errhandler_free(MPI_Errhandler *errhandler);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Errhandler_free)(MPI_Errhandler *errhandler);
int PMPI_Errhandler_free(MPI_Errhandler *errhandler) {
  return INTERFACE_LOCAL_MPI_Errhandler_free(errhandler);
}

int MPI_Error_string(int errorcode, char *string, int *resultlen);
#pragma weak MPI_Error_string = PMPI_Error_string

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Error_string(int errorcode, char *string, int *resultlen);

int INTERF_2_INTEL_MPI_Error_string(int errorcode, char *string,
                                    int *resultlen);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Error_string)(int errorcode, char *string,
                                        int *resultlen);
int PMPI_Error_string(int errorcode, char *string, int *resultlen) {
  return INTERFACE_LOCAL_MPI_Error_string(errorcode, string, resultlen);
}

int MPI_Error_class(int errorcode, int *errorclass);
#pragma weak MPI_Error_class = PMPI_Error_class

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Error_class(int errorcode, int *errorclass);

int INTERF_2_INTEL_MPI_Error_class(int errorcode, int *errorclass);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Error_class)(int errorcode, int *errorclass);
int PMPI_Error_class(int errorcode, int *errorclass) {
  return INTERFACE_LOCAL_MPI_Error_class(errorcode, errorclass);
}

int MPI_Initialized(int *flag);
#pragma weak MPI_Initialized = PMPI_Initialized

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Initialized(int *flag);

int INTERF_2_INTEL_MPI_Initialized(int *flag);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Initialized)(int *flag);
int PMPI_Initialized(int *flag) {
  return INTERFACE_LOCAL_MPI_Initialized(flag);
}

int MPI_Abort(MPI_Comm comm, int errorcode);
#pragma weak MPI_Abort = PMPI_Abort

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Abort(MPI_Comm comm, int errorcode);

int INTERF_2_INTEL_MPI_Abort(MPI_Comm comm, int errorcode);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Abort)(MPI_Comm comm, int errorcode);
int PMPI_Abort(MPI_Comm comm, int errorcode) {
  return INTERFACE_LOCAL_MPI_Abort(comm, errorcode);
}

int MPI_Init(int *argc, char ***argv);
#pragma weak MPI_Init = PMPI_Init

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Init(int *argc, char ***argv);

int INTERF_2_INTEL_MPI_Init(int *argc, char ***argv);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Init)(int *argc, char ***argv);
int PMPI_Init(int *argc, char ***argv) {
  return INTERFACE_LOCAL_MPI_Init(argc, argv);
}

int MPI_Close_port(char *port_name);
#pragma weak MPI_Close_port = PMPI_Close_port

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Close_port(char *port_name);

int INTERF_2_INTEL_MPI_Close_port(char *port_name);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Close_port)(char *port_name);
int PMPI_Close_port(char *port_name) {
  return INTERFACE_LOCAL_MPI_Close_port(port_name);
}

int MPI_Comm_accept(char *port_name, MPI_Info info, int root, MPI_Comm comm,
                    MPI_Comm *newcomm);
#pragma weak MPI_Comm_accept = PMPI_Comm_accept

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Comm_accept(char *port_name, MPI_Info info, int root,
                                  MPI_Comm comm, MPI_Comm *newcomm);

int INTERF_2_INTEL_MPI_Comm_accept(char *port_name, MPI_Info info, int root,
                                   MPI_Comm comm, MPI_Comm *newcomm);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Comm_accept)(char *port_name, MPI_Info info, int root,
                                       MPI_Comm comm, MPI_Comm *newcomm);
int PMPI_Comm_accept(char *port_name, MPI_Info info, int root, MPI_Comm comm,
                     MPI_Comm *newcomm) {
  return INTERFACE_LOCAL_MPI_Comm_accept(port_name, info, root, comm, newcomm);
}

int MPI_Comm_connect(char *port_name, MPI_Info info, int root, MPI_Comm comm,
                     MPI_Comm *newcomm);
#pragma weak MPI_Comm_connect = PMPI_Comm_connect

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Comm_connect(char *port_name, MPI_Info info, int root,
                                   MPI_Comm comm, MPI_Comm *newcomm);

int INTERF_2_INTEL_MPI_Comm_connect(char *port_name, MPI_Info info, int root,
                                    MPI_Comm comm, MPI_Comm *newcomm);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Comm_connect)(char *port_name, MPI_Info info,
                                        int root, MPI_Comm comm,
                                        MPI_Comm *newcomm);
int PMPI_Comm_connect(char *port_name, MPI_Info info, int root, MPI_Comm comm,
                      MPI_Comm *newcomm) {
  return INTERFACE_LOCAL_MPI_Comm_connect(port_name, info, root, comm, newcomm);
}

int MPI_Comm_disconnect(MPI_Comm *comm);
#pragma weak MPI_Comm_disconnect = PMPI_Comm_disconnect

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Comm_disconnect(MPI_Comm *comm);

int INTERF_2_INTEL_MPI_Comm_disconnect(MPI_Comm *comm);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Comm_disconnect)(MPI_Comm *comm);
int PMPI_Comm_disconnect(MPI_Comm *comm) {
  return INTERFACE_LOCAL_MPI_Comm_disconnect(comm);
}

int MPI_Comm_get_parent(MPI_Comm *parent);
#pragma weak MPI_Comm_get_parent = PMPI_Comm_get_parent

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Comm_get_parent(MPI_Comm *parent);

int INTERF_2_INTEL_MPI_Comm_get_parent(MPI_Comm *parent);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Comm_get_parent)(MPI_Comm *parent);
int PMPI_Comm_get_parent(MPI_Comm *parent) {
  return INTERFACE_LOCAL_MPI_Comm_get_parent(parent);
}

int MPI_Comm_join(int fd, MPI_Comm *intercomm);
#pragma weak MPI_Comm_join = PMPI_Comm_join

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Comm_join(int fd, MPI_Comm *intercomm);

int INTERF_2_INTEL_MPI_Comm_join(int fd, MPI_Comm *intercomm);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Comm_join)(int fd, MPI_Comm *intercomm);
int PMPI_Comm_join(int fd, MPI_Comm *intercomm) {
  return INTERFACE_LOCAL_MPI_Comm_join(fd, intercomm);
}

int MPI_Lookup_name(char *service_name, MPI_Info info, char *port_name);
#pragma weak MPI_Lookup_name = PMPI_Lookup_name

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Lookup_name(char *service_name, MPI_Info info,
                                  char *port_name);

int INTERF_2_INTEL_MPI_Lookup_name(char *service_name, MPI_Info info,
                                   char *port_name);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Lookup_name)(char *service_name, MPI_Info info,
                                       char *port_name);
int PMPI_Lookup_name(char *service_name, MPI_Info info, char *port_name) {
  return INTERFACE_LOCAL_MPI_Lookup_name(service_name, info, port_name);
}

int MPI_Open_port(MPI_Info info, char *port_name);
#pragma weak MPI_Open_port = PMPI_Open_port

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Open_port(MPI_Info info, char *port_name);

int INTERF_2_INTEL_MPI_Open_port(MPI_Info info, char *port_name);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Open_port)(MPI_Info info, char *port_name);
int PMPI_Open_port(MPI_Info info, char *port_name) {
  return INTERFACE_LOCAL_MPI_Open_port(info, port_name);
}

int MPI_Publish_name(char *service_name, MPI_Info info, char *port_name);
#pragma weak MPI_Publish_name = PMPI_Publish_name

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Publish_name(char *service_name, MPI_Info info,
                                   char *port_name);

int INTERF_2_INTEL_MPI_Publish_name(char *service_name, MPI_Info info,
                                    char *port_name);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Publish_name)(char *service_name, MPI_Info info,
                                        char *port_name);
int PMPI_Publish_name(char *service_name, MPI_Info info, char *port_name) {
  return INTERFACE_LOCAL_MPI_Publish_name(service_name, info, port_name);
}

int MPI_Unpublish_name(char *service_name, MPI_Info info, char *port_name);
#pragma weak MPI_Unpublish_name = PMPI_Unpublish_name

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Unpublish_name(char *service_name, MPI_Info info,
                                     char *port_name);

int INTERF_2_INTEL_MPI_Unpublish_name(char *service_name, MPI_Info info,
                                      char *port_name);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Unpublish_name)(char *service_name, MPI_Info info,
                                          char *port_name);
int PMPI_Unpublish_name(char *service_name, MPI_Info info, char *port_name) {
  return INTERFACE_LOCAL_MPI_Unpublish_name(service_name, info, port_name);
}

int MPI_Comm_set_info(MPI_Comm comm, MPI_Info info);
#pragma weak MPI_Comm_set_info = PMPI_Comm_set_info

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Comm_set_info(MPI_Comm comm, MPI_Info info);

int INTERF_2_INTEL_MPI_Comm_set_info(MPI_Comm comm, MPI_Info info);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Comm_set_info)(MPI_Comm comm, MPI_Info info);
int PMPI_Comm_set_info(MPI_Comm comm, MPI_Info info) {
  return INTERFACE_LOCAL_MPI_Comm_set_info(comm, info);
}

int MPI_Comm_get_info(MPI_Comm comm, MPI_Info *info);
#pragma weak MPI_Comm_get_info = PMPI_Comm_get_info

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Comm_get_info(MPI_Comm comm, MPI_Info *info);

int INTERF_2_INTEL_MPI_Comm_get_info(MPI_Comm comm, MPI_Info *info);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Comm_get_info)(MPI_Comm comm, MPI_Info *info);
int PMPI_Comm_get_info(MPI_Comm comm, MPI_Info *info) {
  return INTERFACE_LOCAL_MPI_Comm_get_info(comm, info);
}

int MPI_Accumulate(void *origin_addr, int origin_count,
                   MPI_Datatype origin_datatype, int target_rank,
                   MPI_Aint target_disp, int target_count,
                   MPI_Datatype target_datatype, MPI_Op op, MPI_Win win);
#pragma weak MPI_Accumulate = PMPI_Accumulate

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Accumulate(void *origin_addr, int origin_count,
                                 MPI_Datatype origin_datatype, int target_rank,
                                 MPI_Aint target_disp, int target_count,
                                 MPI_Datatype target_datatype, MPI_Op op,
                                 MPI_Win win);

int INTERF_2_INTEL_MPI_Accumulate(void *origin_addr, int origin_count,
                                  MPI_Datatype origin_datatype, int target_rank,
                                  MPI_Aint target_disp, int target_count,
                                  MPI_Datatype target_datatype, MPI_Op op,
                                  MPI_Win win);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Accumulate)(void *origin_addr, int origin_count,
                                      MPI_Datatype origin_datatype,
                                      int target_rank, MPI_Aint target_disp,
                                      int target_count,
                                      MPI_Datatype target_datatype, MPI_Op op,
                                      MPI_Win win);
int PMPI_Accumulate(void *origin_addr, int origin_count,
                    MPI_Datatype origin_datatype, int target_rank,
                    MPI_Aint target_disp, int target_count,
                    MPI_Datatype target_datatype, MPI_Op op, MPI_Win win) {
  return INTERFACE_LOCAL_MPI_Accumulate(
      origin_addr, origin_count, origin_datatype, target_rank, target_disp,
      target_count, target_datatype, op, win);
}

int MPI_Get(void *origin_addr, int origin_count, MPI_Datatype origin_datatype,
            int target_rank, MPI_Aint target_disp, int target_count,
            MPI_Datatype target_datatype, MPI_Win win);
#pragma weak MPI_Get = PMPI_Get

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Get(void *origin_addr, int origin_count,
                          MPI_Datatype origin_datatype, int target_rank,
                          MPI_Aint target_disp, int target_count,
                          MPI_Datatype target_datatype, MPI_Win win);

int INTERF_2_INTEL_MPI_Get(void *origin_addr, int origin_count,
                           MPI_Datatype origin_datatype, int target_rank,
                           MPI_Aint target_disp, int target_count,
                           MPI_Datatype target_datatype, MPI_Win win);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Get)(void *origin_addr, int origin_count,
                               MPI_Datatype origin_datatype, int target_rank,
                               MPI_Aint target_disp, int target_count,
                               MPI_Datatype target_datatype, MPI_Win win);
int PMPI_Get(void *origin_addr, int origin_count, MPI_Datatype origin_datatype,
             int target_rank, MPI_Aint target_disp, int target_count,
             MPI_Datatype target_datatype, MPI_Win win) {
  return INTERFACE_LOCAL_MPI_Get(origin_addr, origin_count, origin_datatype,
                                 target_rank, target_disp, target_count,
                                 target_datatype, win);
}

int MPI_Put(void *origin_addr, int origin_count, MPI_Datatype origin_datatype,
            int target_rank, MPI_Aint target_disp, int target_count,
            MPI_Datatype target_datatype, MPI_Win win);
#pragma weak MPI_Put = PMPI_Put

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Put(void *origin_addr, int origin_count,
                          MPI_Datatype origin_datatype, int target_rank,
                          MPI_Aint target_disp, int target_count,
                          MPI_Datatype target_datatype, MPI_Win win);

int INTERF_2_INTEL_MPI_Put(void *origin_addr, int origin_count,
                           MPI_Datatype origin_datatype, int target_rank,
                           MPI_Aint target_disp, int target_count,
                           MPI_Datatype target_datatype, MPI_Win win);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Put)(void *origin_addr, int origin_count,
                               MPI_Datatype origin_datatype, int target_rank,
                               MPI_Aint target_disp, int target_count,
                               MPI_Datatype target_datatype, MPI_Win win);
int PMPI_Put(void *origin_addr, int origin_count, MPI_Datatype origin_datatype,
             int target_rank, MPI_Aint target_disp, int target_count,
             MPI_Datatype target_datatype, MPI_Win win) {
  return INTERFACE_LOCAL_MPI_Put(origin_addr, origin_count, origin_datatype,
                                 target_rank, target_disp, target_count,
                                 target_datatype, win);
}

int MPI_Win_complete(MPI_Win win);
#pragma weak MPI_Win_complete = PMPI_Win_complete

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Win_complete(MPI_Win win);

int INTERF_2_INTEL_MPI_Win_complete(MPI_Win win);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Win_complete)(MPI_Win win);
int PMPI_Win_complete(MPI_Win win) {
  return INTERFACE_LOCAL_MPI_Win_complete(win);
}

int MPI_Win_create(void *base, MPI_Aint size, int disp_unit, MPI_Info info,
                   MPI_Comm comm, MPI_Win *win);
#pragma weak MPI_Win_create = PMPI_Win_create

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Win_create(void *base, MPI_Aint size, int disp_unit,
                                 MPI_Info info, MPI_Comm comm, MPI_Win *win);

int INTERF_2_INTEL_MPI_Win_create(void *base, MPI_Aint size, int disp_unit,
                                  MPI_Info info, MPI_Comm comm, MPI_Win *win);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Win_create)(void *base, MPI_Aint size, int disp_unit,
                                      MPI_Info info, MPI_Comm comm,
                                      MPI_Win *win);
int PMPI_Win_create(void *base, MPI_Aint size, int disp_unit, MPI_Info info,
                    MPI_Comm comm, MPI_Win *win) {
  return INTERFACE_LOCAL_MPI_Win_create(base, size, disp_unit, info, comm, win);
}

int MPI_Win_fence(int assert, MPI_Win win);
#pragma weak MPI_Win_fence = PMPI_Win_fence

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Win_fence(int assert, MPI_Win win);

int INTERF_2_INTEL_MPI_Win_fence(int assert, MPI_Win win);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Win_fence)(int assert, MPI_Win win);
int PMPI_Win_fence(int assert, MPI_Win win) {
  return INTERFACE_LOCAL_MPI_Win_fence(assert, win);
}

int MPI_Win_free(MPI_Win *win);
#pragma weak MPI_Win_free = PMPI_Win_free

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Win_free(MPI_Win *win);

int INTERF_2_INTEL_MPI_Win_free(MPI_Win *win);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Win_free)(MPI_Win *win);
int PMPI_Win_free(MPI_Win *win) { return INTERFACE_LOCAL_MPI_Win_free(win); }

int MPI_Win_get_group(MPI_Win win, MPI_Group *group);
#pragma weak MPI_Win_get_group = PMPI_Win_get_group

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Win_get_group(MPI_Win win, MPI_Group *group);

int INTERF_2_INTEL_MPI_Win_get_group(MPI_Win win, MPI_Group *group);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Win_get_group)(MPI_Win win, MPI_Group *group);
int PMPI_Win_get_group(MPI_Win win, MPI_Group *group) {
  return INTERFACE_LOCAL_MPI_Win_get_group(win, group);
}

int MPI_Win_lock(int lock_type, int rank, int assert, MPI_Win win);
#pragma weak MPI_Win_lock = PMPI_Win_lock

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Win_lock(int lock_type, int rank, int assert,
                               MPI_Win win);

int INTERF_2_INTEL_MPI_Win_lock(int lock_type, int rank, int assert,
                                MPI_Win win);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Win_lock)(int lock_type, int rank, int assert,
                                    MPI_Win win);
int PMPI_Win_lock(int lock_type, int rank, int assert, MPI_Win win) {
  return INTERFACE_LOCAL_MPI_Win_lock(lock_type, rank, assert, win);
}

int MPI_Win_post(MPI_Group group, int assert, MPI_Win win);
#pragma weak MPI_Win_post = PMPI_Win_post

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Win_post(MPI_Group group, int assert, MPI_Win win);

int INTERF_2_INTEL_MPI_Win_post(MPI_Group group, int assert, MPI_Win win);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Win_post)(MPI_Group group, int assert, MPI_Win win);
int PMPI_Win_post(MPI_Group group, int assert, MPI_Win win) {
  return INTERFACE_LOCAL_MPI_Win_post(group, assert, win);
}

int MPI_Win_start(MPI_Group group, int assert, MPI_Win win);
#pragma weak MPI_Win_start = PMPI_Win_start

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Win_start(MPI_Group group, int assert, MPI_Win win);

int INTERF_2_INTEL_MPI_Win_start(MPI_Group group, int assert, MPI_Win win);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Win_start)(MPI_Group group, int assert, MPI_Win win);
int PMPI_Win_start(MPI_Group group, int assert, MPI_Win win) {
  return INTERFACE_LOCAL_MPI_Win_start(group, assert, win);
}

int MPI_Win_test(MPI_Win win, int *flag);
#pragma weak MPI_Win_test = PMPI_Win_test

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Win_test(MPI_Win win, int *flag);

int INTERF_2_INTEL_MPI_Win_test(MPI_Win win, int *flag);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Win_test)(MPI_Win win, int *flag);
int PMPI_Win_test(MPI_Win win, int *flag) {
  return INTERFACE_LOCAL_MPI_Win_test(win, flag);
}

int MPI_Win_unlock(int rank, MPI_Win win);
#pragma weak MPI_Win_unlock = PMPI_Win_unlock

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Win_unlock(int rank, MPI_Win win);

int INTERF_2_INTEL_MPI_Win_unlock(int rank, MPI_Win win);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Win_unlock)(int rank, MPI_Win win);
int PMPI_Win_unlock(int rank, MPI_Win win) {
  return INTERFACE_LOCAL_MPI_Win_unlock(rank, win);
}

int MPI_Win_wait(MPI_Win win);
#pragma weak MPI_Win_wait = PMPI_Win_wait

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Win_wait(MPI_Win win);

int INTERF_2_INTEL_MPI_Win_wait(MPI_Win win);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Win_wait)(MPI_Win win);
int PMPI_Win_wait(MPI_Win win) { return INTERFACE_LOCAL_MPI_Win_wait(win); }

int MPI_Win_allocate(MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm,
                     void *baseptr, MPI_Win *win);
#pragma weak MPI_Win_allocate = PMPI_Win_allocate

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Win_allocate(MPI_Aint size, int disp_unit, MPI_Info info,
                                   MPI_Comm comm, void *baseptr, MPI_Win *win);

int INTERF_2_INTEL_MPI_Win_allocate(MPI_Aint size, int disp_unit, MPI_Info info,
                                    MPI_Comm comm, void *baseptr, MPI_Win *win);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Win_allocate)(MPI_Aint size, int disp_unit,
                                        MPI_Info info, MPI_Comm comm,
                                        void *baseptr, MPI_Win *win);
int PMPI_Win_allocate(MPI_Aint size, int disp_unit, MPI_Info info,
                      MPI_Comm comm, void *baseptr, MPI_Win *win) {
  return INTERFACE_LOCAL_MPI_Win_allocate(size, disp_unit, info, comm, baseptr,
                                          win);
}

int MPI_Win_allocate_shared(MPI_Aint size, int disp_unit, MPI_Info info,
                            MPI_Comm comm, void *baseptr, MPI_Win *win);
#pragma weak MPI_Win_allocate_shared = PMPI_Win_allocate_shared

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Win_allocate_shared(MPI_Aint size, int disp_unit,
                                          MPI_Info info, MPI_Comm comm,
                                          void *baseptr, MPI_Win *win);

int INTERF_2_INTEL_MPI_Win_allocate_shared(MPI_Aint size, int disp_unit,
                                           MPI_Info info, MPI_Comm comm,
                                           void *baseptr, MPI_Win *win);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Win_allocate_shared)(MPI_Aint size, int disp_unit,
                                               MPI_Info info, MPI_Comm comm,
                                               void *baseptr, MPI_Win *win);
int PMPI_Win_allocate_shared(MPI_Aint size, int disp_unit, MPI_Info info,
                             MPI_Comm comm, void *baseptr, MPI_Win *win) {
  return INTERFACE_LOCAL_MPI_Win_allocate_shared(size, disp_unit, info, comm,
                                                 baseptr, win);
}

int MPI_Win_shared_query(MPI_Win win, int rank, MPI_Aint *size, int *disp_unit,
                         void *baseptr);
#pragma weak MPI_Win_shared_query = PMPI_Win_shared_query

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Win_shared_query(MPI_Win win, int rank, MPI_Aint *size,
                                       int *disp_unit, void *baseptr);

int INTERF_2_INTEL_MPI_Win_shared_query(MPI_Win win, int rank, MPI_Aint *size,
                                        int *disp_unit, void *baseptr);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Win_shared_query)(MPI_Win win, int rank,
                                            MPI_Aint *size, int *disp_unit,
                                            void *baseptr);
int PMPI_Win_shared_query(MPI_Win win, int rank, MPI_Aint *size, int *disp_unit,
                          void *baseptr) {
  return INTERFACE_LOCAL_MPI_Win_shared_query(win, rank, size, disp_unit,
                                              baseptr);
}

int MPI_Win_create_dynamic(MPI_Info info, MPI_Comm comm, MPI_Win *win);
#pragma weak MPI_Win_create_dynamic = PMPI_Win_create_dynamic

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Win_create_dynamic(MPI_Info info, MPI_Comm comm,
                                         MPI_Win *win);

int INTERF_2_INTEL_MPI_Win_create_dynamic(MPI_Info info, MPI_Comm comm,
                                          MPI_Win *win);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Win_create_dynamic)(MPI_Info info, MPI_Comm comm,
                                              MPI_Win *win);
int PMPI_Win_create_dynamic(MPI_Info info, MPI_Comm comm, MPI_Win *win) {
  return INTERFACE_LOCAL_MPI_Win_create_dynamic(info, comm, win);
}

int MPI_Win_attach(MPI_Win win, void *base, MPI_Aint size);
#pragma weak MPI_Win_attach = PMPI_Win_attach

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Win_attach(MPI_Win win, void *base, MPI_Aint size);

int INTERF_2_INTEL_MPI_Win_attach(MPI_Win win, void *base, MPI_Aint size);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Win_attach)(MPI_Win win, void *base, MPI_Aint size);
int PMPI_Win_attach(MPI_Win win, void *base, MPI_Aint size) {
  return INTERFACE_LOCAL_MPI_Win_attach(win, base, size);
}

int MPI_Win_detach(MPI_Win win, void *base);
#pragma weak MPI_Win_detach = PMPI_Win_detach

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Win_detach(MPI_Win win, void *base);

int INTERF_2_INTEL_MPI_Win_detach(MPI_Win win, void *base);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Win_detach)(MPI_Win win, void *base);
int PMPI_Win_detach(MPI_Win win, void *base) {
  return INTERFACE_LOCAL_MPI_Win_detach(win, base);
}

int MPI_Win_get_info(MPI_Win win, MPI_Info *info_used);
#pragma weak MPI_Win_get_info = PMPI_Win_get_info

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Win_get_info(MPI_Win win, MPI_Info *info_used);

int INTERF_2_INTEL_MPI_Win_get_info(MPI_Win win, MPI_Info *info_used);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Win_get_info)(MPI_Win win, MPI_Info *info_used);
int PMPI_Win_get_info(MPI_Win win, MPI_Info *info_used) {
  return INTERFACE_LOCAL_MPI_Win_get_info(win, info_used);
}

int MPI_Win_set_info(MPI_Win win, MPI_Info info);
#pragma weak MPI_Win_set_info = PMPI_Win_set_info

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Win_set_info(MPI_Win win, MPI_Info info);

int INTERF_2_INTEL_MPI_Win_set_info(MPI_Win win, MPI_Info info);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Win_set_info)(MPI_Win win, MPI_Info info);
int PMPI_Win_set_info(MPI_Win win, MPI_Info info) {
  return INTERFACE_LOCAL_MPI_Win_set_info(win, info);
}

int MPI_Get_accumulate(void *origin_addr, int origin_count,
                       MPI_Datatype origin_datatype, void *result_addr,
                       int result_count, MPI_Datatype result_datatype,
                       int target_rank, MPI_Aint target_disp, int target_count,
                       MPI_Datatype target_datatype, MPI_Op op, MPI_Win win);
#pragma weak MPI_Get_accumulate = PMPI_Get_accumulate

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Get_accumulate(
    void *origin_addr, int origin_count, MPI_Datatype origin_datatype,
    void *result_addr, int result_count, MPI_Datatype result_datatype,
    int target_rank, MPI_Aint target_disp, int target_count,
    MPI_Datatype target_datatype, MPI_Op op, MPI_Win win);

int INTERF_2_INTEL_MPI_Get_accumulate(
    void *origin_addr, int origin_count, MPI_Datatype origin_datatype,
    void *result_addr, int result_count, MPI_Datatype result_datatype,
    int target_rank, MPI_Aint target_disp, int target_count,
    MPI_Datatype target_datatype, MPI_Op op, MPI_Win win);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Get_accumulate)(
    void *origin_addr, int origin_count, MPI_Datatype origin_datatype,
    void *result_addr, int result_count, MPI_Datatype result_datatype,
    int target_rank, MPI_Aint target_disp, int target_count,
    MPI_Datatype target_datatype, MPI_Op op, MPI_Win win);
int PMPI_Get_accumulate(void *origin_addr, int origin_count,
                        MPI_Datatype origin_datatype, void *result_addr,
                        int result_count, MPI_Datatype result_datatype,
                        int target_rank, MPI_Aint target_disp, int target_count,
                        MPI_Datatype target_datatype, MPI_Op op, MPI_Win win) {
  return INTERFACE_LOCAL_MPI_Get_accumulate(
      origin_addr, origin_count, origin_datatype, result_addr, result_count,
      result_datatype, target_rank, target_disp, target_count, target_datatype,
      op, win);
}

int MPI_Fetch_and_op(void *origin_addr, void *result_addr,
                     MPI_Datatype datatype, int target_rank,
                     MPI_Aint target_disp, MPI_Op op, MPI_Win win);
#pragma weak MPI_Fetch_and_op = PMPI_Fetch_and_op

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Fetch_and_op(void *origin_addr, void *result_addr,
                                   MPI_Datatype datatype, int target_rank,
                                   MPI_Aint target_disp, MPI_Op op,
                                   MPI_Win win);

int INTERF_2_INTEL_MPI_Fetch_and_op(void *origin_addr, void *result_addr,
                                    MPI_Datatype datatype, int target_rank,
                                    MPI_Aint target_disp, MPI_Op op,
                                    MPI_Win win);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Fetch_and_op)(void *origin_addr, void *result_addr,
                                        MPI_Datatype datatype, int target_rank,
                                        MPI_Aint target_disp, MPI_Op op,
                                        MPI_Win win);
int PMPI_Fetch_and_op(void *origin_addr, void *result_addr,
                      MPI_Datatype datatype, int target_rank,
                      MPI_Aint target_disp, MPI_Op op, MPI_Win win) {
  return INTERFACE_LOCAL_MPI_Fetch_and_op(origin_addr, result_addr, datatype,
                                          target_rank, target_disp, op, win);
}

int MPI_Compare_and_swap(void *origin_addr, void *compare_addr,
                         void *result_addr, MPI_Datatype datatype,
                         int target_rank, MPI_Aint target_disp, MPI_Win win);
#pragma weak MPI_Compare_and_swap = PMPI_Compare_and_swap

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Compare_and_swap(void *origin_addr, void *compare_addr,
                                       void *result_addr, MPI_Datatype datatype,
                                       int target_rank, MPI_Aint target_disp,
                                       MPI_Win win);

int INTERF_2_INTEL_MPI_Compare_and_swap(void *origin_addr, void *compare_addr,
                                        void *result_addr,
                                        MPI_Datatype datatype, int target_rank,
                                        MPI_Aint target_disp, MPI_Win win);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Compare_and_swap)(
    void *origin_addr, void *compare_addr, void *result_addr,
    MPI_Datatype datatype, int target_rank, MPI_Aint target_disp, MPI_Win win);
int PMPI_Compare_and_swap(void *origin_addr, void *compare_addr,
                          void *result_addr, MPI_Datatype datatype,
                          int target_rank, MPI_Aint target_disp, MPI_Win win) {
  return INTERFACE_LOCAL_MPI_Compare_and_swap(origin_addr, compare_addr,
                                              result_addr, datatype,
                                              target_rank, target_disp, win);
}

int MPI_Rput(void *origin_addr, int origin_count, MPI_Datatype origin_datatype,
             int target_rank, MPI_Aint target_disp, int target_count,
             MPI_Datatype target_datatype, MPI_Win win, MPI_Request *request);
#pragma weak MPI_Rput = PMPI_Rput

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Rput(void *origin_addr, int origin_count,
                           MPI_Datatype origin_datatype, int target_rank,
                           MPI_Aint target_disp, int target_count,
                           MPI_Datatype target_datatype, MPI_Win win,
                           MPI_Request *request);

int INTERF_2_INTEL_MPI_Rput(void *origin_addr, int origin_count,
                            MPI_Datatype origin_datatype, int target_rank,
                            MPI_Aint target_disp, int target_count,
                            MPI_Datatype target_datatype, MPI_Win win,
                            MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Rput)(void *origin_addr, int origin_count,
                                MPI_Datatype origin_datatype, int target_rank,
                                MPI_Aint target_disp, int target_count,
                                MPI_Datatype target_datatype, MPI_Win win,
                                MPI_Request *request);
int PMPI_Rput(void *origin_addr, int origin_count, MPI_Datatype origin_datatype,
              int target_rank, MPI_Aint target_disp, int target_count,
              MPI_Datatype target_datatype, MPI_Win win, MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_Rput(origin_addr, origin_count, origin_datatype,
                                  target_rank, target_disp, target_count,
                                  target_datatype, win, request);
}

int MPI_Rget(void *origin_addr, int origin_count, MPI_Datatype origin_datatype,
             int target_rank, MPI_Aint target_disp, int target_count,
             MPI_Datatype target_datatype, MPI_Win win, MPI_Request *request);
#pragma weak MPI_Rget = PMPI_Rget

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Rget(void *origin_addr, int origin_count,
                           MPI_Datatype origin_datatype, int target_rank,
                           MPI_Aint target_disp, int target_count,
                           MPI_Datatype target_datatype, MPI_Win win,
                           MPI_Request *request);

int INTERF_2_INTEL_MPI_Rget(void *origin_addr, int origin_count,
                            MPI_Datatype origin_datatype, int target_rank,
                            MPI_Aint target_disp, int target_count,
                            MPI_Datatype target_datatype, MPI_Win win,
                            MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Rget)(void *origin_addr, int origin_count,
                                MPI_Datatype origin_datatype, int target_rank,
                                MPI_Aint target_disp, int target_count,
                                MPI_Datatype target_datatype, MPI_Win win,
                                MPI_Request *request);
int PMPI_Rget(void *origin_addr, int origin_count, MPI_Datatype origin_datatype,
              int target_rank, MPI_Aint target_disp, int target_count,
              MPI_Datatype target_datatype, MPI_Win win, MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_Rget(origin_addr, origin_count, origin_datatype,
                                  target_rank, target_disp, target_count,
                                  target_datatype, win, request);
}

int MPI_Raccumulate(void *origin_addr, int origin_count,
                    MPI_Datatype origin_datatype, int target_rank,
                    MPI_Aint target_disp, int target_count,
                    MPI_Datatype target_datatype, MPI_Op op, MPI_Win win,
                    MPI_Request *request);
#pragma weak MPI_Raccumulate = PMPI_Raccumulate

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Raccumulate(void *origin_addr, int origin_count,
                                  MPI_Datatype origin_datatype, int target_rank,
                                  MPI_Aint target_disp, int target_count,
                                  MPI_Datatype target_datatype, MPI_Op op,
                                  MPI_Win win, MPI_Request *request);

int INTERF_2_INTEL_MPI_Raccumulate(void *origin_addr, int origin_count,
                                   MPI_Datatype origin_datatype,
                                   int target_rank, MPI_Aint target_disp,
                                   int target_count,
                                   MPI_Datatype target_datatype, MPI_Op op,
                                   MPI_Win win, MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Raccumulate)(void *origin_addr, int origin_count,
                                       MPI_Datatype origin_datatype,
                                       int target_rank, MPI_Aint target_disp,
                                       int target_count,
                                       MPI_Datatype target_datatype, MPI_Op op,
                                       MPI_Win win, MPI_Request *request);
int PMPI_Raccumulate(void *origin_addr, int origin_count,
                     MPI_Datatype origin_datatype, int target_rank,
                     MPI_Aint target_disp, int target_count,
                     MPI_Datatype target_datatype, MPI_Op op, MPI_Win win,
                     MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_Raccumulate(
      origin_addr, origin_count, origin_datatype, target_rank, target_disp,
      target_count, target_datatype, op, win, request);
}

int MPI_Rget_accumulate(void *origin_addr, int origin_count,
                        MPI_Datatype origin_datatype, void *result_addr,
                        int result_count, MPI_Datatype result_datatype,
                        int target_rank, MPI_Aint target_disp, int target_count,
                        MPI_Datatype target_datatype, MPI_Op op, MPI_Win win,
                        MPI_Request *request);
#pragma weak MPI_Rget_accumulate = PMPI_Rget_accumulate

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Rget_accumulate(
    void *origin_addr, int origin_count, MPI_Datatype origin_datatype,
    void *result_addr, int result_count, MPI_Datatype result_datatype,
    int target_rank, MPI_Aint target_disp, int target_count,
    MPI_Datatype target_datatype, MPI_Op op, MPI_Win win, MPI_Request *request);

int INTERF_2_INTEL_MPI_Rget_accumulate(
    void *origin_addr, int origin_count, MPI_Datatype origin_datatype,
    void *result_addr, int result_count, MPI_Datatype result_datatype,
    int target_rank, MPI_Aint target_disp, int target_count,
    MPI_Datatype target_datatype, MPI_Op op, MPI_Win win, MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Rget_accumulate)(
    void *origin_addr, int origin_count, MPI_Datatype origin_datatype,
    void *result_addr, int result_count, MPI_Datatype result_datatype,
    int target_rank, MPI_Aint target_disp, int target_count,
    MPI_Datatype target_datatype, MPI_Op op, MPI_Win win, MPI_Request *request);
int PMPI_Rget_accumulate(void *origin_addr, int origin_count,
                         MPI_Datatype origin_datatype, void *result_addr,
                         int result_count, MPI_Datatype result_datatype,
                         int target_rank, MPI_Aint target_disp,
                         int target_count, MPI_Datatype target_datatype,
                         MPI_Op op, MPI_Win win, MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_Rget_accumulate(
      origin_addr, origin_count, origin_datatype, result_addr, result_count,
      result_datatype, target_rank, target_disp, target_count, target_datatype,
      op, win, request);
}

int MPI_Win_lock_all(int assert, MPI_Win win);
#pragma weak MPI_Win_lock_all = PMPI_Win_lock_all

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Win_lock_all(int assert, MPI_Win win);

int INTERF_2_INTEL_MPI_Win_lock_all(int assert, MPI_Win win);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Win_lock_all)(int assert, MPI_Win win);
int PMPI_Win_lock_all(int assert, MPI_Win win) {
  return INTERFACE_LOCAL_MPI_Win_lock_all(assert, win);
}

int MPI_Win_unlock_all(MPI_Win win);
#pragma weak MPI_Win_unlock_all = PMPI_Win_unlock_all

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Win_unlock_all(MPI_Win win);

int INTERF_2_INTEL_MPI_Win_unlock_all(MPI_Win win);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Win_unlock_all)(MPI_Win win);
int PMPI_Win_unlock_all(MPI_Win win) {
  return INTERFACE_LOCAL_MPI_Win_unlock_all(win);
}

int MPI_Win_flush(int rank, MPI_Win win);
#pragma weak MPI_Win_flush = PMPI_Win_flush

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Win_flush(int rank, MPI_Win win);

int INTERF_2_INTEL_MPI_Win_flush(int rank, MPI_Win win);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Win_flush)(int rank, MPI_Win win);
int PMPI_Win_flush(int rank, MPI_Win win) {
  return INTERFACE_LOCAL_MPI_Win_flush(rank, win);
}

int MPI_Win_flush_all(MPI_Win win);
#pragma weak MPI_Win_flush_all = PMPI_Win_flush_all

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Win_flush_all(MPI_Win win);

int INTERF_2_INTEL_MPI_Win_flush_all(MPI_Win win);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Win_flush_all)(MPI_Win win);
int PMPI_Win_flush_all(MPI_Win win) {
  return INTERFACE_LOCAL_MPI_Win_flush_all(win);
}

int MPI_Win_flush_local(int rank, MPI_Win win);
#pragma weak MPI_Win_flush_local = PMPI_Win_flush_local

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Win_flush_local(int rank, MPI_Win win);

int INTERF_2_INTEL_MPI_Win_flush_local(int rank, MPI_Win win);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Win_flush_local)(int rank, MPI_Win win);
int PMPI_Win_flush_local(int rank, MPI_Win win) {
  return INTERFACE_LOCAL_MPI_Win_flush_local(rank, win);
}

int MPI_Win_flush_local_all(MPI_Win win);
#pragma weak MPI_Win_flush_local_all = PMPI_Win_flush_local_all

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Win_flush_local_all(MPI_Win win);

int INTERF_2_INTEL_MPI_Win_flush_local_all(MPI_Win win);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Win_flush_local_all)(MPI_Win win);
int PMPI_Win_flush_local_all(MPI_Win win) {
  return INTERFACE_LOCAL_MPI_Win_flush_local_all(win);
}

int MPI_Win_sync(MPI_Win win);
#pragma weak MPI_Win_sync = PMPI_Win_sync

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Win_sync(MPI_Win win);

int INTERF_2_INTEL_MPI_Win_sync(MPI_Win win);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Win_sync)(MPI_Win win);
int PMPI_Win_sync(MPI_Win win) { return INTERFACE_LOCAL_MPI_Win_sync(win); }

int MPI_Add_error_class(int *errorclass);
#pragma weak MPI_Add_error_class = PMPI_Add_error_class

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Add_error_class(int *errorclass);

int INTERF_2_INTEL_MPI_Add_error_class(int *errorclass);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Add_error_class)(int *errorclass);
int PMPI_Add_error_class(int *errorclass) {
  return INTERFACE_LOCAL_MPI_Add_error_class(errorclass);
}

int MPI_Add_error_code(int errorclass, int *errorcode);
#pragma weak MPI_Add_error_code = PMPI_Add_error_code

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Add_error_code(int errorclass, int *errorcode);

int INTERF_2_INTEL_MPI_Add_error_code(int errorclass, int *errorcode);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Add_error_code)(int errorclass, int *errorcode);
int PMPI_Add_error_code(int errorclass, int *errorcode) {
  return INTERFACE_LOCAL_MPI_Add_error_code(errorclass, errorcode);
}

int MPI_Add_error_string(int errorcode, char *string);
#pragma weak MPI_Add_error_string = PMPI_Add_error_string

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Add_error_string(int errorcode, char *string);

int INTERF_2_INTEL_MPI_Add_error_string(int errorcode, char *string);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Add_error_string)(int errorcode, char *string);
int PMPI_Add_error_string(int errorcode, char *string) {
  return INTERFACE_LOCAL_MPI_Add_error_string(errorcode, string);
}

int MPI_Comm_call_errhandler(MPI_Comm comm, int errorcode);
#pragma weak MPI_Comm_call_errhandler = PMPI_Comm_call_errhandler

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Comm_call_errhandler(MPI_Comm comm, int errorcode);

int INTERF_2_INTEL_MPI_Comm_call_errhandler(MPI_Comm comm, int errorcode);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Comm_call_errhandler)(MPI_Comm comm, int errorcode);
int PMPI_Comm_call_errhandler(MPI_Comm comm, int errorcode) {
  return INTERFACE_LOCAL_MPI_Comm_call_errhandler(comm, errorcode);
}

int MPI_Comm_create_keyval(MPI_Comm_copy_attr_function *comm_copy_attr_fn,
                           MPI_Comm_delete_attr_function *comm_delete_attr_fn,
                           int *comm_keyval, void *extra_state);
#pragma weak MPI_Comm_create_keyval = PMPI_Comm_create_keyval

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Comm_create_keyval(
    MPI_Comm_copy_attr_function *comm_copy_attr_fn,
    MPI_Comm_delete_attr_function *comm_delete_attr_fn, int *comm_keyval,
    void *extra_state);

int INTERF_2_INTEL_MPI_Comm_create_keyval(
    MPI_Comm_copy_attr_function *comm_copy_attr_fn,
    MPI_Comm_delete_attr_function *comm_delete_attr_fn, int *comm_keyval,
    void *extra_state);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Comm_create_keyval)(
    MPI_Comm_copy_attr_function *comm_copy_attr_fn,
    MPI_Comm_delete_attr_function *comm_delete_attr_fn, int *comm_keyval,
    void *extra_state);
int PMPI_Comm_create_keyval(MPI_Comm_copy_attr_function *comm_copy_attr_fn,
                            MPI_Comm_delete_attr_function *comm_delete_attr_fn,
                            int *comm_keyval, void *extra_state) {
  return INTERFACE_LOCAL_MPI_Comm_create_keyval(
      comm_copy_attr_fn, comm_delete_attr_fn, comm_keyval, extra_state);
}

int MPI_Comm_delete_attr(MPI_Comm comm, int comm_keyval);
#pragma weak MPI_Comm_delete_attr = PMPI_Comm_delete_attr

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Comm_delete_attr(MPI_Comm comm, int comm_keyval);

int INTERF_2_INTEL_MPI_Comm_delete_attr(MPI_Comm comm, int comm_keyval);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Comm_delete_attr)(MPI_Comm comm, int comm_keyval);
int PMPI_Comm_delete_attr(MPI_Comm comm, int comm_keyval) {
  return INTERFACE_LOCAL_MPI_Comm_delete_attr(comm, comm_keyval);
}

int MPI_Comm_free_keyval(int *comm_keyval);
#pragma weak MPI_Comm_free_keyval = PMPI_Comm_free_keyval

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Comm_free_keyval(int *comm_keyval);

int INTERF_2_INTEL_MPI_Comm_free_keyval(int *comm_keyval);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Comm_free_keyval)(int *comm_keyval);
int PMPI_Comm_free_keyval(int *comm_keyval) {
  return INTERFACE_LOCAL_MPI_Comm_free_keyval(comm_keyval);
}

int MPI_Comm_get_attr(MPI_Comm comm, int comm_keyval, void *attribute_val,
                      int *flag);
#pragma weak MPI_Comm_get_attr = PMPI_Comm_get_attr

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Comm_get_attr(MPI_Comm comm, int comm_keyval,
                                    void *attribute_val, int *flag);

int INTERF_2_INTEL_MPI_Comm_get_attr(MPI_Comm comm, int comm_keyval,
                                     void *attribute_val, int *flag);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Comm_get_attr)(MPI_Comm comm, int comm_keyval,
                                         void *attribute_val, int *flag);
int PMPI_Comm_get_attr(MPI_Comm comm, int comm_keyval, void *attribute_val,
                       int *flag) {
  return INTERFACE_LOCAL_MPI_Comm_get_attr(comm, comm_keyval, attribute_val,
                                           flag);
}

int MPI_Comm_get_name(MPI_Comm comm, char *comm_name, int *resultlen);
#pragma weak MPI_Comm_get_name = PMPI_Comm_get_name

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Comm_get_name(MPI_Comm comm, char *comm_name,
                                    int *resultlen);

int INTERF_2_INTEL_MPI_Comm_get_name(MPI_Comm comm, char *comm_name,
                                     int *resultlen);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Comm_get_name)(MPI_Comm comm, char *comm_name,
                                         int *resultlen);
int PMPI_Comm_get_name(MPI_Comm comm, char *comm_name, int *resultlen) {
  return INTERFACE_LOCAL_MPI_Comm_get_name(comm, comm_name, resultlen);
}

int MPI_Comm_set_attr(MPI_Comm comm, int comm_keyval, void *attribute_val);
#pragma weak MPI_Comm_set_attr = PMPI_Comm_set_attr

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Comm_set_attr(MPI_Comm comm, int comm_keyval,
                                    void *attribute_val);

int INTERF_2_INTEL_MPI_Comm_set_attr(MPI_Comm comm, int comm_keyval,
                                     void *attribute_val);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Comm_set_attr)(MPI_Comm comm, int comm_keyval,
                                         void *attribute_val);
int PMPI_Comm_set_attr(MPI_Comm comm, int comm_keyval, void *attribute_val) {
  return INTERFACE_LOCAL_MPI_Comm_set_attr(comm, comm_keyval, attribute_val);
}

int MPI_Comm_set_name(MPI_Comm comm, char *comm_name);
#pragma weak MPI_Comm_set_name = PMPI_Comm_set_name

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Comm_set_name(MPI_Comm comm, char *comm_name);

int INTERF_2_INTEL_MPI_Comm_set_name(MPI_Comm comm, char *comm_name);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Comm_set_name)(MPI_Comm comm, char *comm_name);
int PMPI_Comm_set_name(MPI_Comm comm, char *comm_name) {
  return INTERFACE_LOCAL_MPI_Comm_set_name(comm, comm_name);
}

int MPI_Grequest_complete(MPI_Request request);
#pragma weak MPI_Grequest_complete = PMPI_Grequest_complete

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Grequest_complete(MPI_Request request);

int INTERF_2_INTEL_MPI_Grequest_complete(MPI_Request request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Grequest_complete)(MPI_Request request);
int PMPI_Grequest_complete(MPI_Request request) {
  return INTERFACE_LOCAL_MPI_Grequest_complete(request);
}

int MPI_Grequest_start(MPI_Grequest_query_function *query_fn,
                       MPI_Grequest_free_function *free_fn,
                       MPI_Grequest_cancel_function *cancel_fn,
                       void *extra_state, MPI_Request *request);
#pragma weak MPI_Grequest_start = PMPI_Grequest_start

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Grequest_start(MPI_Grequest_query_function *query_fn,
                                     MPI_Grequest_free_function *free_fn,
                                     MPI_Grequest_cancel_function *cancel_fn,
                                     void *extra_state, MPI_Request *request);

int INTERF_2_INTEL_MPI_Grequest_start(MPI_Grequest_query_function *query_fn,
                                      MPI_Grequest_free_function *free_fn,
                                      MPI_Grequest_cancel_function *cancel_fn,
                                      void *extra_state, MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Grequest_start)(
    MPI_Grequest_query_function *query_fn, MPI_Grequest_free_function *free_fn,
    MPI_Grequest_cancel_function *cancel_fn, void *extra_state,
    MPI_Request *request);
int PMPI_Grequest_start(MPI_Grequest_query_function *query_fn,
                        MPI_Grequest_free_function *free_fn,
                        MPI_Grequest_cancel_function *cancel_fn,
                        void *extra_state, MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_Grequest_start(query_fn, free_fn, cancel_fn,
                                            extra_state, request);
}

int MPI_Init_thread(int *argc, char ***argv, int required, int *provided);
#pragma weak MPI_Init_thread = PMPI_Init_thread

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Init_thread(int *argc, char ***argv, int required,
                                  int *provided);

int INTERF_2_INTEL_MPI_Init_thread(int *argc, char ***argv, int required,
                                   int *provided);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Init_thread)(int *argc, char ***argv, int required,
                                       int *provided);
int PMPI_Init_thread(int *argc, char ***argv, int required, int *provided) {
  return INTERFACE_LOCAL_MPI_Init_thread(argc, argv, required, provided);
}

int MPI_Is_thread_main(int *flag);
#pragma weak MPI_Is_thread_main = PMPI_Is_thread_main

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Is_thread_main(int *flag);

int INTERF_2_INTEL_MPI_Is_thread_main(int *flag);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Is_thread_main)(int *flag);
int PMPI_Is_thread_main(int *flag) {
  return INTERFACE_LOCAL_MPI_Is_thread_main(flag);
}

int MPI_Query_thread(int *provided);
#pragma weak MPI_Query_thread = PMPI_Query_thread

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Query_thread(int *provided);

int INTERF_2_INTEL_MPI_Query_thread(int *provided);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Query_thread)(int *provided);
int PMPI_Query_thread(int *provided) {
  return INTERFACE_LOCAL_MPI_Query_thread(provided);
}

int MPI_Status_set_cancelled(MPI_Status *status, int flag);
#pragma weak MPI_Status_set_cancelled = PMPI_Status_set_cancelled

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Status_set_cancelled(MPI_Status *status, int flag);

int INTERF_2_INTEL_MPI_Status_set_cancelled(MPI_Status *status, int flag);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Status_set_cancelled)(MPI_Status *status, int flag);
int PMPI_Status_set_cancelled(MPI_Status *status, int flag) {
  return INTERFACE_LOCAL_MPI_Status_set_cancelled(status, flag);
}

int MPI_Status_set_elements(MPI_Status *status, MPI_Datatype datatype,
                            int count);
#pragma weak MPI_Status_set_elements = PMPI_Status_set_elements

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Status_set_elements(MPI_Status *status,
                                          MPI_Datatype datatype, int count);

int INTERF_2_INTEL_MPI_Status_set_elements(MPI_Status *status,
                                           MPI_Datatype datatype, int count);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Status_set_elements)(MPI_Status *status,
                                               MPI_Datatype datatype,
                                               int count);
int PMPI_Status_set_elements(MPI_Status *status, MPI_Datatype datatype,
                             int count) {
  return INTERFACE_LOCAL_MPI_Status_set_elements(status, datatype, count);
}

int MPI_Type_create_keyval(MPI_Type_copy_attr_function *type_copy_attr_fn,
                           MPI_Type_delete_attr_function *type_delete_attr_fn,
                           int *type_keyval, void *extra_state);
#pragma weak MPI_Type_create_keyval = PMPI_Type_create_keyval

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Type_create_keyval(
    MPI_Type_copy_attr_function *type_copy_attr_fn,
    MPI_Type_delete_attr_function *type_delete_attr_fn, int *type_keyval,
    void *extra_state);

int INTERF_2_INTEL_MPI_Type_create_keyval(
    MPI_Type_copy_attr_function *type_copy_attr_fn,
    MPI_Type_delete_attr_function *type_delete_attr_fn, int *type_keyval,
    void *extra_state);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Type_create_keyval)(
    MPI_Type_copy_attr_function *type_copy_attr_fn,
    MPI_Type_delete_attr_function *type_delete_attr_fn, int *type_keyval,
    void *extra_state);
int PMPI_Type_create_keyval(MPI_Type_copy_attr_function *type_copy_attr_fn,
                            MPI_Type_delete_attr_function *type_delete_attr_fn,
                            int *type_keyval, void *extra_state) {
  return INTERFACE_LOCAL_MPI_Type_create_keyval(
      type_copy_attr_fn, type_delete_attr_fn, type_keyval, extra_state);
}

int MPI_Type_delete_attr(MPI_Datatype datatype, int type_keyval);
#pragma weak MPI_Type_delete_attr = PMPI_Type_delete_attr

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Type_delete_attr(MPI_Datatype datatype, int type_keyval);

int INTERF_2_INTEL_MPI_Type_delete_attr(MPI_Datatype datatype, int type_keyval);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Type_delete_attr)(MPI_Datatype datatype,
                                            int type_keyval);
int PMPI_Type_delete_attr(MPI_Datatype datatype, int type_keyval) {
  return INTERFACE_LOCAL_MPI_Type_delete_attr(datatype, type_keyval);
}

int MPI_Type_dup(MPI_Datatype oldtype, MPI_Datatype *newtype);
#pragma weak MPI_Type_dup = PMPI_Type_dup

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Type_dup(MPI_Datatype oldtype, MPI_Datatype *newtype);

int INTERF_2_INTEL_MPI_Type_dup(MPI_Datatype oldtype, MPI_Datatype *newtype);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Type_dup)(MPI_Datatype oldtype,
                                    MPI_Datatype *newtype);
int PMPI_Type_dup(MPI_Datatype oldtype, MPI_Datatype *newtype) {
  return INTERFACE_LOCAL_MPI_Type_dup(oldtype, newtype);
}

int MPI_Type_free_keyval(int *type_keyval);
#pragma weak MPI_Type_free_keyval = PMPI_Type_free_keyval

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Type_free_keyval(int *type_keyval);

int INTERF_2_INTEL_MPI_Type_free_keyval(int *type_keyval);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Type_free_keyval)(int *type_keyval);
int PMPI_Type_free_keyval(int *type_keyval) {
  return INTERFACE_LOCAL_MPI_Type_free_keyval(type_keyval);
}

int MPI_Type_get_attr(MPI_Datatype datatype, int type_keyval,
                      void *attribute_val, int *flag);
#pragma weak MPI_Type_get_attr = PMPI_Type_get_attr

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Type_get_attr(MPI_Datatype datatype, int type_keyval,
                                    void *attribute_val, int *flag);

int INTERF_2_INTEL_MPI_Type_get_attr(MPI_Datatype datatype, int type_keyval,
                                     void *attribute_val, int *flag);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Type_get_attr)(MPI_Datatype datatype, int type_keyval,
                                         void *attribute_val, int *flag);
int PMPI_Type_get_attr(MPI_Datatype datatype, int type_keyval,
                       void *attribute_val, int *flag) {
  return INTERFACE_LOCAL_MPI_Type_get_attr(datatype, type_keyval, attribute_val,
                                           flag);
}

int MPI_Type_get_envelope(MPI_Datatype datatype, int *num_integers,
                          int *num_addresses, int *num_datatypes,
                          int *combiner);
#pragma weak MPI_Type_get_envelope = PMPI_Type_get_envelope

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Type_get_envelope(MPI_Datatype datatype,
                                        int *num_integers, int *num_addresses,
                                        int *num_datatypes, int *combiner);

int INTERF_2_INTEL_MPI_Type_get_envelope(MPI_Datatype datatype,
                                         int *num_integers, int *num_addresses,
                                         int *num_datatypes, int *combiner);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Type_get_envelope)(MPI_Datatype datatype,
                                             int *num_integers,
                                             int *num_addresses,
                                             int *num_datatypes, int *combiner);
int PMPI_Type_get_envelope(MPI_Datatype datatype, int *num_integers,
                           int *num_addresses, int *num_datatypes,
                           int *combiner) {
  return INTERFACE_LOCAL_MPI_Type_get_envelope(
      datatype, num_integers, num_addresses, num_datatypes, combiner);
}

int MPI_Type_get_name(MPI_Datatype datatype, char *type_name, int *resultlen);
#pragma weak MPI_Type_get_name = PMPI_Type_get_name

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Type_get_name(MPI_Datatype datatype, char *type_name,
                                    int *resultlen);

int INTERF_2_INTEL_MPI_Type_get_name(MPI_Datatype datatype, char *type_name,
                                     int *resultlen);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Type_get_name)(MPI_Datatype datatype, char *type_name,
                                         int *resultlen);
int PMPI_Type_get_name(MPI_Datatype datatype, char *type_name, int *resultlen) {
  return INTERFACE_LOCAL_MPI_Type_get_name(datatype, type_name, resultlen);
}

int MPI_Type_set_attr(MPI_Datatype datatype, int type_keyval,
                      void *attribute_val);
#pragma weak MPI_Type_set_attr = PMPI_Type_set_attr

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Type_set_attr(MPI_Datatype datatype, int type_keyval,
                                    void *attribute_val);

int INTERF_2_INTEL_MPI_Type_set_attr(MPI_Datatype datatype, int type_keyval,
                                     void *attribute_val);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Type_set_attr)(MPI_Datatype datatype, int type_keyval,
                                         void *attribute_val);
int PMPI_Type_set_attr(MPI_Datatype datatype, int type_keyval,
                       void *attribute_val) {
  return INTERFACE_LOCAL_MPI_Type_set_attr(datatype, type_keyval,
                                           attribute_val);
}

int MPI_Type_set_name(MPI_Datatype datatype, char *type_name);
#pragma weak MPI_Type_set_name = PMPI_Type_set_name

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Type_set_name(MPI_Datatype datatype, char *type_name);

int INTERF_2_INTEL_MPI_Type_set_name(MPI_Datatype datatype, char *type_name);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Type_set_name)(MPI_Datatype datatype,
                                         char *type_name);
int PMPI_Type_set_name(MPI_Datatype datatype, char *type_name) {
  return INTERFACE_LOCAL_MPI_Type_set_name(datatype, type_name);
}

int MPI_Type_match_size(int typeclass, int size, MPI_Datatype *datatype);
#pragma weak MPI_Type_match_size = PMPI_Type_match_size

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Type_match_size(int typeclass, int size,
                                      MPI_Datatype *datatype);

int INTERF_2_INTEL_MPI_Type_match_size(int typeclass, int size,
                                       MPI_Datatype *datatype);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Type_match_size)(int typeclass, int size,
                                           MPI_Datatype *datatype);
int PMPI_Type_match_size(int typeclass, int size, MPI_Datatype *datatype) {
  return INTERFACE_LOCAL_MPI_Type_match_size(typeclass, size, datatype);
}

int MPI_Win_create_keyval(MPI_Win_copy_attr_function *win_copy_attr_fn,
                          MPI_Win_delete_attr_function *win_delete_attr_fn,
                          int *win_keyval, void *extra_state);
#pragma weak MPI_Win_create_keyval = PMPI_Win_create_keyval

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Win_create_keyval(
    MPI_Win_copy_attr_function *win_copy_attr_fn,
    MPI_Win_delete_attr_function *win_delete_attr_fn, int *win_keyval,
    void *extra_state);

int INTERF_2_INTEL_MPI_Win_create_keyval(
    MPI_Win_copy_attr_function *win_copy_attr_fn,
    MPI_Win_delete_attr_function *win_delete_attr_fn, int *win_keyval,
    void *extra_state);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Win_create_keyval)(
    MPI_Win_copy_attr_function *win_copy_attr_fn,
    MPI_Win_delete_attr_function *win_delete_attr_fn, int *win_keyval,
    void *extra_state);
int PMPI_Win_create_keyval(MPI_Win_copy_attr_function *win_copy_attr_fn,
                           MPI_Win_delete_attr_function *win_delete_attr_fn,
                           int *win_keyval, void *extra_state) {
  return INTERFACE_LOCAL_MPI_Win_create_keyval(
      win_copy_attr_fn, win_delete_attr_fn, win_keyval, extra_state);
}

int MPI_Win_delete_attr(MPI_Win win, int win_keyval);
#pragma weak MPI_Win_delete_attr = PMPI_Win_delete_attr

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Win_delete_attr(MPI_Win win, int win_keyval);

int INTERF_2_INTEL_MPI_Win_delete_attr(MPI_Win win, int win_keyval);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Win_delete_attr)(MPI_Win win, int win_keyval);
int PMPI_Win_delete_attr(MPI_Win win, int win_keyval) {
  return INTERFACE_LOCAL_MPI_Win_delete_attr(win, win_keyval);
}

int MPI_Win_free_keyval(int *win_keyval);
#pragma weak MPI_Win_free_keyval = PMPI_Win_free_keyval

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Win_free_keyval(int *win_keyval);

int INTERF_2_INTEL_MPI_Win_free_keyval(int *win_keyval);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Win_free_keyval)(int *win_keyval);
int PMPI_Win_free_keyval(int *win_keyval) {
  return INTERFACE_LOCAL_MPI_Win_free_keyval(win_keyval);
}

int MPI_Win_get_attr(MPI_Win win, int win_keyval, void *attribute_val,
                     int *flag);
#pragma weak MPI_Win_get_attr = PMPI_Win_get_attr

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Win_get_attr(MPI_Win win, int win_keyval,
                                   void *attribute_val, int *flag);

int INTERF_2_INTEL_MPI_Win_get_attr(MPI_Win win, int win_keyval,
                                    void *attribute_val, int *flag);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Win_get_attr)(MPI_Win win, int win_keyval,
                                        void *attribute_val, int *flag);
int PMPI_Win_get_attr(MPI_Win win, int win_keyval, void *attribute_val,
                      int *flag) {
  return INTERFACE_LOCAL_MPI_Win_get_attr(win, win_keyval, attribute_val, flag);
}

int MPI_Win_get_name(MPI_Win win, char *win_name, int *resultlen);
#pragma weak MPI_Win_get_name = PMPI_Win_get_name

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Win_get_name(MPI_Win win, char *win_name, int *resultlen);

int INTERF_2_INTEL_MPI_Win_get_name(MPI_Win win, char *win_name,
                                    int *resultlen);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Win_get_name)(MPI_Win win, char *win_name,
                                        int *resultlen);
int PMPI_Win_get_name(MPI_Win win, char *win_name, int *resultlen) {
  return INTERFACE_LOCAL_MPI_Win_get_name(win, win_name, resultlen);
}

int MPI_Win_set_name(MPI_Win win, char *win_name);
#pragma weak MPI_Win_set_name = PMPI_Win_set_name

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Win_set_name(MPI_Win win, char *win_name);

int INTERF_2_INTEL_MPI_Win_set_name(MPI_Win win, char *win_name);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Win_set_name)(MPI_Win win, char *win_name);
int PMPI_Win_set_name(MPI_Win win, char *win_name) {
  return INTERFACE_LOCAL_MPI_Win_set_name(win, win_name);
}

int MPI_Alloc_mem(MPI_Aint size, MPI_Info info, void *baseptr);
#pragma weak MPI_Alloc_mem = PMPI_Alloc_mem

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Alloc_mem(MPI_Aint size, MPI_Info info, void *baseptr);

int INTERF_2_INTEL_MPI_Alloc_mem(MPI_Aint size, MPI_Info info, void *baseptr);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Alloc_mem)(MPI_Aint size, MPI_Info info,
                                     void *baseptr);
int PMPI_Alloc_mem(MPI_Aint size, MPI_Info info, void *baseptr) {
  return INTERFACE_LOCAL_MPI_Alloc_mem(size, info, baseptr);
}

int MPI_Comm_create_errhandler(MPI_Comm_errhandler_function *comm_errhandler_fn,
                               MPI_Errhandler *errhandler);
#pragma weak MPI_Comm_create_errhandler = PMPI_Comm_create_errhandler

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Comm_create_errhandler(
    MPI_Comm_errhandler_function *comm_errhandler_fn,
    MPI_Errhandler *errhandler);

int INTERF_2_INTEL_MPI_Comm_create_errhandler(
    MPI_Comm_errhandler_function *comm_errhandler_fn,
    MPI_Errhandler *errhandler);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Comm_create_errhandler)(
    MPI_Comm_errhandler_function *comm_errhandler_fn,
    MPI_Errhandler *errhandler);
int PMPI_Comm_create_errhandler(
    MPI_Comm_errhandler_function *comm_errhandler_fn,
    MPI_Errhandler *errhandler) {
  return INTERFACE_LOCAL_MPI_Comm_create_errhandler(comm_errhandler_fn,
                                                    errhandler);
}

int MPI_Comm_get_errhandler(MPI_Comm comm, MPI_Errhandler *errhandler);
#pragma weak MPI_Comm_get_errhandler = PMPI_Comm_get_errhandler

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Comm_get_errhandler(MPI_Comm comm,
                                          MPI_Errhandler *errhandler);

int INTERF_2_INTEL_MPI_Comm_get_errhandler(MPI_Comm comm,
                                           MPI_Errhandler *errhandler);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Comm_get_errhandler)(MPI_Comm comm,
                                               MPI_Errhandler *errhandler);
int PMPI_Comm_get_errhandler(MPI_Comm comm, MPI_Errhandler *errhandler) {
  return INTERFACE_LOCAL_MPI_Comm_get_errhandler(comm, errhandler);
}

int MPI_Comm_set_errhandler(MPI_Comm comm, MPI_Errhandler errhandler);
#pragma weak MPI_Comm_set_errhandler = PMPI_Comm_set_errhandler

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Comm_set_errhandler(MPI_Comm comm,
                                          MPI_Errhandler errhandler);

int INTERF_2_INTEL_MPI_Comm_set_errhandler(MPI_Comm comm,
                                           MPI_Errhandler errhandler);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Comm_set_errhandler)(MPI_Comm comm,
                                               MPI_Errhandler errhandler);
int PMPI_Comm_set_errhandler(MPI_Comm comm, MPI_Errhandler errhandler) {
  return INTERFACE_LOCAL_MPI_Comm_set_errhandler(comm, errhandler);
}

int MPI_File_get_errhandler(MPI_File file, MPI_Errhandler *errhandler);
#pragma weak MPI_File_get_errhandler = PMPI_File_get_errhandler

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_get_errhandler(MPI_File file,
                                          MPI_Errhandler *errhandler);

int INTERF_2_INTEL_MPI_File_get_errhandler(MPI_File file,
                                           MPI_Errhandler *errhandler);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_get_errhandler)(MPI_File file,
                                               MPI_Errhandler *errhandler);
int PMPI_File_get_errhandler(MPI_File file, MPI_Errhandler *errhandler) {
  return INTERFACE_LOCAL_MPI_File_get_errhandler(file, errhandler);
}

int MPI_File_set_errhandler(MPI_File file, MPI_Errhandler errhandler);
#pragma weak MPI_File_set_errhandler = PMPI_File_set_errhandler

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_set_errhandler(MPI_File file,
                                          MPI_Errhandler errhandler);

int INTERF_2_INTEL_MPI_File_set_errhandler(MPI_File file,
                                           MPI_Errhandler errhandler);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_set_errhandler)(MPI_File file,
                                               MPI_Errhandler errhandler);
int PMPI_File_set_errhandler(MPI_File file, MPI_Errhandler errhandler) {
  return INTERFACE_LOCAL_MPI_File_set_errhandler(file, errhandler);
}

int MPI_Finalized(int *flag);
#pragma weak MPI_Finalized = PMPI_Finalized

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Finalized(int *flag);

int INTERF_2_INTEL_MPI_Finalized(int *flag);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Finalized)(int *flag);
int PMPI_Finalized(int *flag) { return INTERFACE_LOCAL_MPI_Finalized(flag); }

int MPI_Free_mem(void *base);
#pragma weak MPI_Free_mem = PMPI_Free_mem

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Free_mem(void *base);

int INTERF_2_INTEL_MPI_Free_mem(void *base);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Free_mem)(void *base);
int PMPI_Free_mem(void *base) { return INTERFACE_LOCAL_MPI_Free_mem(base); }

int MPI_Get_address(void *location, MPI_Aint *address);
#pragma weak MPI_Get_address = PMPI_Get_address

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Get_address(void *location, MPI_Aint *address);

int INTERF_2_INTEL_MPI_Get_address(void *location, MPI_Aint *address);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Get_address)(void *location, MPI_Aint *address);
int PMPI_Get_address(void *location, MPI_Aint *address) {
  return INTERFACE_LOCAL_MPI_Get_address(location, address);
}

int MPI_Info_create(MPI_Info *info);
#pragma weak MPI_Info_create = PMPI_Info_create

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Info_create(MPI_Info *info);

int INTERF_2_INTEL_MPI_Info_create(MPI_Info *info);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Info_create)(MPI_Info *info);
int PMPI_Info_create(MPI_Info *info) {
  return INTERFACE_LOCAL_MPI_Info_create(info);
}

int MPI_Info_delete(MPI_Info info, char *key);
#pragma weak MPI_Info_delete = PMPI_Info_delete

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Info_delete(MPI_Info info, char *key);

int INTERF_2_INTEL_MPI_Info_delete(MPI_Info info, char *key);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Info_delete)(MPI_Info info, char *key);
int PMPI_Info_delete(MPI_Info info, char *key) {
  return INTERFACE_LOCAL_MPI_Info_delete(info, key);
}

int MPI_Info_dup(MPI_Info info, MPI_Info *newinfo);
#pragma weak MPI_Info_dup = PMPI_Info_dup

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Info_dup(MPI_Info info, MPI_Info *newinfo);

int INTERF_2_INTEL_MPI_Info_dup(MPI_Info info, MPI_Info *newinfo);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Info_dup)(MPI_Info info, MPI_Info *newinfo);
int PMPI_Info_dup(MPI_Info info, MPI_Info *newinfo) {
  return INTERFACE_LOCAL_MPI_Info_dup(info, newinfo);
}

int MPI_Info_free(MPI_Info *info);
#pragma weak MPI_Info_free = PMPI_Info_free

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Info_free(MPI_Info *info);

int INTERF_2_INTEL_MPI_Info_free(MPI_Info *info);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Info_free)(MPI_Info *info);
int PMPI_Info_free(MPI_Info *info) {
  return INTERFACE_LOCAL_MPI_Info_free(info);
}

int MPI_Info_get(MPI_Info info, char *key, int valuelen, char *value,
                 int *flag);
#pragma weak MPI_Info_get = PMPI_Info_get

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Info_get(MPI_Info info, char *key, int valuelen,
                               char *value, int *flag);

int INTERF_2_INTEL_MPI_Info_get(MPI_Info info, char *key, int valuelen,
                                char *value, int *flag);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Info_get)(MPI_Info info, char *key, int valuelen,
                                    char *value, int *flag);
int PMPI_Info_get(MPI_Info info, char *key, int valuelen, char *value,
                  int *flag) {
  return INTERFACE_LOCAL_MPI_Info_get(info, key, valuelen, value, flag);
}

int MPI_Info_get_nkeys(MPI_Info info, int *nkeys);
#pragma weak MPI_Info_get_nkeys = PMPI_Info_get_nkeys

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Info_get_nkeys(MPI_Info info, int *nkeys);

int INTERF_2_INTEL_MPI_Info_get_nkeys(MPI_Info info, int *nkeys);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Info_get_nkeys)(MPI_Info info, int *nkeys);
int PMPI_Info_get_nkeys(MPI_Info info, int *nkeys) {
  return INTERFACE_LOCAL_MPI_Info_get_nkeys(info, nkeys);
}

int MPI_Info_get_nthkey(MPI_Info info, int n, char *key);
#pragma weak MPI_Info_get_nthkey = PMPI_Info_get_nthkey

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Info_get_nthkey(MPI_Info info, int n, char *key);

int INTERF_2_INTEL_MPI_Info_get_nthkey(MPI_Info info, int n, char *key);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Info_get_nthkey)(MPI_Info info, int n, char *key);
int PMPI_Info_get_nthkey(MPI_Info info, int n, char *key) {
  return INTERFACE_LOCAL_MPI_Info_get_nthkey(info, n, key);
}

int MPI_Info_get_valuelen(MPI_Info info, char *key, int *valuelen, int *flag);
#pragma weak MPI_Info_get_valuelen = PMPI_Info_get_valuelen

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Info_get_valuelen(MPI_Info info, char *key, int *valuelen,
                                        int *flag);

int INTERF_2_INTEL_MPI_Info_get_valuelen(MPI_Info info, char *key,
                                         int *valuelen, int *flag);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Info_get_valuelen)(MPI_Info info, char *key,
                                             int *valuelen, int *flag);
int PMPI_Info_get_valuelen(MPI_Info info, char *key, int *valuelen, int *flag) {
  return INTERFACE_LOCAL_MPI_Info_get_valuelen(info, key, valuelen, flag);
}

int MPI_Info_set(MPI_Info info, char *key, char *value);
#pragma weak MPI_Info_set = PMPI_Info_set

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Info_set(MPI_Info info, char *key, char *value);

int INTERF_2_INTEL_MPI_Info_set(MPI_Info info, char *key, char *value);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Info_set)(MPI_Info info, char *key, char *value);
int PMPI_Info_set(MPI_Info info, char *key, char *value) {
  return INTERFACE_LOCAL_MPI_Info_set(info, key, value);
}

int MPI_Request_get_status(MPI_Request request, int *flag, MPI_Status *status);
#pragma weak MPI_Request_get_status = PMPI_Request_get_status

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Request_get_status(MPI_Request request, int *flag,
                                         MPI_Status *status);

int INTERF_2_INTEL_MPI_Request_get_status(MPI_Request request, int *flag,
                                          MPI_Status *status);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Request_get_status)(MPI_Request request, int *flag,
                                              MPI_Status *status);
int PMPI_Request_get_status(MPI_Request request, int *flag,
                            MPI_Status *status) {
  return INTERFACE_LOCAL_MPI_Request_get_status(request, flag, status);
}

int MPI_Type_create_hvector(int count, int blocklength, MPI_Aint stride,
                            MPI_Datatype oldtype, MPI_Datatype *newtype);
#pragma weak MPI_Type_create_hvector = PMPI_Type_create_hvector

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Type_create_hvector(int count, int blocklength,
                                          MPI_Aint stride, MPI_Datatype oldtype,
                                          MPI_Datatype *newtype);

int INTERF_2_INTEL_MPI_Type_create_hvector(int count, int blocklength,
                                           MPI_Aint stride,
                                           MPI_Datatype oldtype,
                                           MPI_Datatype *newtype);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Type_create_hvector)(int count, int blocklength,
                                               MPI_Aint stride,
                                               MPI_Datatype oldtype,
                                               MPI_Datatype *newtype);
int PMPI_Type_create_hvector(int count, int blocklength, MPI_Aint stride,
                             MPI_Datatype oldtype, MPI_Datatype *newtype) {
  return INTERFACE_LOCAL_MPI_Type_create_hvector(count, blocklength, stride,
                                                 oldtype, newtype);
}

int MPI_Type_create_resized(MPI_Datatype oldtype, MPI_Aint lb, MPI_Aint extent,
                            MPI_Datatype *newtype);
#pragma weak MPI_Type_create_resized = PMPI_Type_create_resized

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Type_create_resized(MPI_Datatype oldtype, MPI_Aint lb,
                                          MPI_Aint extent,
                                          MPI_Datatype *newtype);

int INTERF_2_INTEL_MPI_Type_create_resized(MPI_Datatype oldtype, MPI_Aint lb,
                                           MPI_Aint extent,
                                           MPI_Datatype *newtype);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Type_create_resized)(MPI_Datatype oldtype,
                                               MPI_Aint lb, MPI_Aint extent,
                                               MPI_Datatype *newtype);
int PMPI_Type_create_resized(MPI_Datatype oldtype, MPI_Aint lb, MPI_Aint extent,
                             MPI_Datatype *newtype) {
  return INTERFACE_LOCAL_MPI_Type_create_resized(oldtype, lb, extent, newtype);
}

int MPI_Type_get_extent(MPI_Datatype datatype, MPI_Aint *lb, MPI_Aint *extent);
#pragma weak MPI_Type_get_extent = PMPI_Type_get_extent

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Type_get_extent(MPI_Datatype datatype, MPI_Aint *lb,
                                      MPI_Aint *extent);

int INTERF_2_INTEL_MPI_Type_get_extent(MPI_Datatype datatype, MPI_Aint *lb,
                                       MPI_Aint *extent);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Type_get_extent)(MPI_Datatype datatype, MPI_Aint *lb,
                                           MPI_Aint *extent);
int PMPI_Type_get_extent(MPI_Datatype datatype, MPI_Aint *lb,
                         MPI_Aint *extent) {
  return INTERFACE_LOCAL_MPI_Type_get_extent(datatype, lb, extent);
}

int MPI_Type_get_true_extent(MPI_Datatype datatype, MPI_Aint *true_lb,
                             MPI_Aint *true_extent);
#pragma weak MPI_Type_get_true_extent = PMPI_Type_get_true_extent

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Type_get_true_extent(MPI_Datatype datatype,
                                           MPI_Aint *true_lb,
                                           MPI_Aint *true_extent);

int INTERF_2_INTEL_MPI_Type_get_true_extent(MPI_Datatype datatype,
                                            MPI_Aint *true_lb,
                                            MPI_Aint *true_extent);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Type_get_true_extent)(MPI_Datatype datatype,
                                                MPI_Aint *true_lb,
                                                MPI_Aint *true_extent);
int PMPI_Type_get_true_extent(MPI_Datatype datatype, MPI_Aint *true_lb,
                              MPI_Aint *true_extent) {
  return INTERFACE_LOCAL_MPI_Type_get_true_extent(datatype, true_lb,
                                                  true_extent);
}

int MPI_Win_get_errhandler(MPI_Win win, MPI_Errhandler *errhandler);
#pragma weak MPI_Win_get_errhandler = PMPI_Win_get_errhandler

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Win_get_errhandler(MPI_Win win,
                                         MPI_Errhandler *errhandler);

int INTERF_2_INTEL_MPI_Win_get_errhandler(MPI_Win win,
                                          MPI_Errhandler *errhandler);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Win_get_errhandler)(MPI_Win win,
                                              MPI_Errhandler *errhandler);
int PMPI_Win_get_errhandler(MPI_Win win, MPI_Errhandler *errhandler) {
  return INTERFACE_LOCAL_MPI_Win_get_errhandler(win, errhandler);
}

int MPI_Type_create_f90_integer(int range, MPI_Datatype *newtype);
#pragma weak MPI_Type_create_f90_integer = PMPI_Type_create_f90_integer

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Type_create_f90_integer(int range, MPI_Datatype *newtype);

int INTERF_2_INTEL_MPI_Type_create_f90_integer(int range,
                                               MPI_Datatype *newtype);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Type_create_f90_integer)(int range,
                                                   MPI_Datatype *newtype);
int PMPI_Type_create_f90_integer(int range, MPI_Datatype *newtype) {
  return INTERFACE_LOCAL_MPI_Type_create_f90_integer(range, newtype);
}

int MPI_Type_create_f90_real(int precision, int range, MPI_Datatype *newtype);
#pragma weak MPI_Type_create_f90_real = PMPI_Type_create_f90_real

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Type_create_f90_real(int precision, int range,
                                           MPI_Datatype *newtype);

int INTERF_2_INTEL_MPI_Type_create_f90_real(int precision, int range,
                                            MPI_Datatype *newtype);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Type_create_f90_real)(int precision, int range,
                                                MPI_Datatype *newtype);
int PMPI_Type_create_f90_real(int precision, int range, MPI_Datatype *newtype) {
  return INTERFACE_LOCAL_MPI_Type_create_f90_real(precision, range, newtype);
}

int MPI_Type_create_f90_complex(int precision, int range,
                                MPI_Datatype *newtype);
#pragma weak MPI_Type_create_f90_complex = PMPI_Type_create_f90_complex

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Type_create_f90_complex(int precision, int range,
                                              MPI_Datatype *newtype);

int INTERF_2_INTEL_MPI_Type_create_f90_complex(int precision, int range,
                                               MPI_Datatype *newtype);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Type_create_f90_complex)(int precision, int range,
                                                   MPI_Datatype *newtype);
int PMPI_Type_create_f90_complex(int precision, int range,
                                 MPI_Datatype *newtype) {
  return INTERFACE_LOCAL_MPI_Type_create_f90_complex(precision, range, newtype);
}

int MPI_Reduce_local(void *inbuf, void *inoutbuf, int count,
                     MPI_Datatype datatype, MPI_Op op);
#pragma weak MPI_Reduce_local = PMPI_Reduce_local

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Reduce_local(void *inbuf, void *inoutbuf, int count,
                                   MPI_Datatype datatype, MPI_Op op);

int INTERF_2_INTEL_MPI_Reduce_local(void *inbuf, void *inoutbuf, int count,
                                    MPI_Datatype datatype, MPI_Op op);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Reduce_local)(void *inbuf, void *inoutbuf, int count,
                                        MPI_Datatype datatype, MPI_Op op);
int PMPI_Reduce_local(void *inbuf, void *inoutbuf, int count,
                      MPI_Datatype datatype, MPI_Op op) {
  return INTERFACE_LOCAL_MPI_Reduce_local(inbuf, inoutbuf, count, datatype, op);
}

int MPI_Op_commutative(MPI_Op op, int *commute);
#pragma weak MPI_Op_commutative = PMPI_Op_commutative

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Op_commutative(MPI_Op op, int *commute);

int INTERF_2_INTEL_MPI_Op_commutative(MPI_Op op, int *commute);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Op_commutative)(MPI_Op op, int *commute);
int PMPI_Op_commutative(MPI_Op op, int *commute) {
  return INTERFACE_LOCAL_MPI_Op_commutative(op, commute);
}

int MPI_Reduce_scatter_block(void *sendbuf, void *recvbuf, int recvcount,
                             MPI_Datatype datatype, MPI_Op op, MPI_Comm comm);
#pragma weak MPI_Reduce_scatter_block = PMPI_Reduce_scatter_block

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Reduce_scatter_block(void *sendbuf, void *recvbuf,
                                           int recvcount, MPI_Datatype datatype,
                                           MPI_Op op, MPI_Comm comm);

int INTERF_2_INTEL_MPI_Reduce_scatter_block(void *sendbuf, void *recvbuf,
                                            int recvcount,
                                            MPI_Datatype datatype, MPI_Op op,
                                            MPI_Comm comm);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Reduce_scatter_block)(void *sendbuf, void *recvbuf,
                                                int recvcount,
                                                MPI_Datatype datatype,
                                                MPI_Op op, MPI_Comm comm);
int PMPI_Reduce_scatter_block(void *sendbuf, void *recvbuf, int recvcount,
                              MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) {
  return INTERFACE_LOCAL_MPI_Reduce_scatter_block(sendbuf, recvbuf, recvcount,
                                                  datatype, op, comm);
}

int MPI_Dist_graph_neighbors_count(MPI_Comm comm, int *indegree, int *outdegree,
                                   int *weighted);
#pragma weak MPI_Dist_graph_neighbors_count = PMPI_Dist_graph_neighbors_count

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Dist_graph_neighbors_count(MPI_Comm comm, int *indegree,
                                                 int *outdegree, int *weighted);

int INTERF_2_INTEL_MPI_Dist_graph_neighbors_count(MPI_Comm comm, int *indegree,
                                                  int *outdegree,
                                                  int *weighted);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Dist_graph_neighbors_count)(MPI_Comm comm,
                                                      int *indegree,
                                                      int *outdegree,
                                                      int *weighted);
int PMPI_Dist_graph_neighbors_count(MPI_Comm comm, int *indegree,
                                    int *outdegree, int *weighted) {
  return INTERFACE_LOCAL_MPI_Dist_graph_neighbors_count(comm, indegree,
                                                        outdegree, weighted);
}

int MPI_Improbe(int source, int tag, MPI_Comm comm, int *flag,
                MPI_Message *message, MPI_Status *status);
#pragma weak MPI_Improbe = PMPI_Improbe

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Improbe(int source, int tag, MPI_Comm comm, int *flag,
                              MPI_Message *message, MPI_Status *status);

int INTERF_2_INTEL_MPI_Improbe(int source, int tag, MPI_Comm comm, int *flag,
                               MPI_Message *message, MPI_Status *status);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Improbe)(int source, int tag, MPI_Comm comm,
                                   int *flag, MPI_Message *message,
                                   MPI_Status *status);
int PMPI_Improbe(int source, int tag, MPI_Comm comm, int *flag,
                 MPI_Message *message, MPI_Status *status) {
  return INTERFACE_LOCAL_MPI_Improbe(source, tag, comm, flag, message, status);
}

int MPI_Imrecv(void *buf, int count, MPI_Datatype datatype,
               MPI_Message *message, MPI_Request *request);
#pragma weak MPI_Imrecv = PMPI_Imrecv

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Imrecv(void *buf, int count, MPI_Datatype datatype,
                             MPI_Message *message, MPI_Request *request);

int INTERF_2_INTEL_MPI_Imrecv(void *buf, int count, MPI_Datatype datatype,
                              MPI_Message *message, MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Imrecv)(void *buf, int count, MPI_Datatype datatype,
                                  MPI_Message *message, MPI_Request *request);
int PMPI_Imrecv(void *buf, int count, MPI_Datatype datatype,
                MPI_Message *message, MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_Imrecv(buf, count, datatype, message, request);
}

int MPI_Mprobe(int source, int tag, MPI_Comm comm, MPI_Message *message,
               MPI_Status *status);
#pragma weak MPI_Mprobe = PMPI_Mprobe

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Mprobe(int source, int tag, MPI_Comm comm,
                             MPI_Message *message, MPI_Status *status);

int INTERF_2_INTEL_MPI_Mprobe(int source, int tag, MPI_Comm comm,
                              MPI_Message *message, MPI_Status *status);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Mprobe)(int source, int tag, MPI_Comm comm,
                                  MPI_Message *message, MPI_Status *status);
int PMPI_Mprobe(int source, int tag, MPI_Comm comm, MPI_Message *message,
                MPI_Status *status) {
  return INTERFACE_LOCAL_MPI_Mprobe(source, tag, comm, message, status);
}

int MPI_Mrecv(void *buf, int count, MPI_Datatype datatype, MPI_Message *message,
              MPI_Status *status);
#pragma weak MPI_Mrecv = PMPI_Mrecv

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Mrecv(void *buf, int count, MPI_Datatype datatype,
                            MPI_Message *message, MPI_Status *status);

int INTERF_2_INTEL_MPI_Mrecv(void *buf, int count, MPI_Datatype datatype,
                             MPI_Message *message, MPI_Status *status);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Mrecv)(void *buf, int count, MPI_Datatype datatype,
                                 MPI_Message *message, MPI_Status *status);
int PMPI_Mrecv(void *buf, int count, MPI_Datatype datatype,
               MPI_Message *message, MPI_Status *status) {
  return INTERFACE_LOCAL_MPI_Mrecv(buf, count, datatype, message, status);
}

int MPI_Comm_idup(MPI_Comm comm, MPI_Comm *newcomm, MPI_Request *request);
#pragma weak MPI_Comm_idup = PMPI_Comm_idup

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Comm_idup(MPI_Comm comm, MPI_Comm *newcomm,
                                MPI_Request *request);

int INTERF_2_INTEL_MPI_Comm_idup(MPI_Comm comm, MPI_Comm *newcomm,
                                 MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Comm_idup)(MPI_Comm comm, MPI_Comm *newcomm,
                                     MPI_Request *request);
int PMPI_Comm_idup(MPI_Comm comm, MPI_Comm *newcomm, MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_Comm_idup(comm, newcomm, request);
}

int MPI_Ibarrier(MPI_Comm comm, MPI_Request *request);
#pragma weak MPI_Ibarrier = PMPI_Ibarrier

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Ibarrier(MPI_Comm comm, MPI_Request *request);

int INTERF_2_INTEL_MPI_Ibarrier(MPI_Comm comm, MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Ibarrier)(MPI_Comm comm, MPI_Request *request);
int PMPI_Ibarrier(MPI_Comm comm, MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_Ibarrier(comm, request);
}

int MPI_Ibcast(void *buffer, int count, MPI_Datatype datatype, int root,
               MPI_Comm comm, MPI_Request *request);
#pragma weak MPI_Ibcast = PMPI_Ibcast

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Ibcast(void *buffer, int count, MPI_Datatype datatype,
                             int root, MPI_Comm comm, MPI_Request *request);

int INTERF_2_INTEL_MPI_Ibcast(void *buffer, int count, MPI_Datatype datatype,
                              int root, MPI_Comm comm, MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Ibcast)(void *buffer, int count,
                                  MPI_Datatype datatype, int root,
                                  MPI_Comm comm, MPI_Request *request);
int PMPI_Ibcast(void *buffer, int count, MPI_Datatype datatype, int root,
                MPI_Comm comm, MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_Ibcast(buffer, count, datatype, root, comm,
                                    request);
}

int MPI_Igather(void *sendbuf, int sendcount, MPI_Datatype sendtype,
                void *recvbuf, int recvcount, MPI_Datatype recvtype, int root,
                MPI_Comm comm, MPI_Request *request);
#pragma weak MPI_Igather = PMPI_Igather

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Igather(void *sendbuf, int sendcount,
                              MPI_Datatype sendtype, void *recvbuf,
                              int recvcount, MPI_Datatype recvtype, int root,
                              MPI_Comm comm, MPI_Request *request);

int INTERF_2_INTEL_MPI_Igather(void *sendbuf, int sendcount,
                               MPI_Datatype sendtype, void *recvbuf,
                               int recvcount, MPI_Datatype recvtype, int root,
                               MPI_Comm comm, MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Igather)(void *sendbuf, int sendcount,
                                   MPI_Datatype sendtype, void *recvbuf,
                                   int recvcount, MPI_Datatype recvtype,
                                   int root, MPI_Comm comm,
                                   MPI_Request *request);
int PMPI_Igather(void *sendbuf, int sendcount, MPI_Datatype sendtype,
                 void *recvbuf, int recvcount, MPI_Datatype recvtype, int root,
                 MPI_Comm comm, MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_Igather(sendbuf, sendcount, sendtype, recvbuf,
                                     recvcount, recvtype, root, comm, request);
}

int MPI_Iscatter(void *sendbuf, int sendcount, MPI_Datatype sendtype,
                 void *recvbuf, int recvcount, MPI_Datatype recvtype, int root,
                 MPI_Comm comm, MPI_Request *request);
#pragma weak MPI_Iscatter = PMPI_Iscatter

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Iscatter(void *sendbuf, int sendcount,
                               MPI_Datatype sendtype, void *recvbuf,
                               int recvcount, MPI_Datatype recvtype, int root,
                               MPI_Comm comm, MPI_Request *request);

int INTERF_2_INTEL_MPI_Iscatter(void *sendbuf, int sendcount,
                                MPI_Datatype sendtype, void *recvbuf,
                                int recvcount, MPI_Datatype recvtype, int root,
                                MPI_Comm comm, MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Iscatter)(void *sendbuf, int sendcount,
                                    MPI_Datatype sendtype, void *recvbuf,
                                    int recvcount, MPI_Datatype recvtype,
                                    int root, MPI_Comm comm,
                                    MPI_Request *request);
int PMPI_Iscatter(void *sendbuf, int sendcount, MPI_Datatype sendtype,
                  void *recvbuf, int recvcount, MPI_Datatype recvtype, int root,
                  MPI_Comm comm, MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_Iscatter(sendbuf, sendcount, sendtype, recvbuf,
                                      recvcount, recvtype, root, comm, request);
}

int MPI_Iallgather(void *sendbuf, int sendcount, MPI_Datatype sendtype,
                   void *recvbuf, int recvcount, MPI_Datatype recvtype,
                   MPI_Comm comm, MPI_Request *request);
#pragma weak MPI_Iallgather = PMPI_Iallgather

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Iallgather(void *sendbuf, int sendcount,
                                 MPI_Datatype sendtype, void *recvbuf,
                                 int recvcount, MPI_Datatype recvtype,
                                 MPI_Comm comm, MPI_Request *request);

int INTERF_2_INTEL_MPI_Iallgather(void *sendbuf, int sendcount,
                                  MPI_Datatype sendtype, void *recvbuf,
                                  int recvcount, MPI_Datatype recvtype,
                                  MPI_Comm comm, MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Iallgather)(void *sendbuf, int sendcount,
                                      MPI_Datatype sendtype, void *recvbuf,
                                      int recvcount, MPI_Datatype recvtype,
                                      MPI_Comm comm, MPI_Request *request);
int PMPI_Iallgather(void *sendbuf, int sendcount, MPI_Datatype sendtype,
                    void *recvbuf, int recvcount, MPI_Datatype recvtype,
                    MPI_Comm comm, MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_Iallgather(sendbuf, sendcount, sendtype, recvbuf,
                                        recvcount, recvtype, comm, request);
}

int MPI_Ialltoall(void *sendbuf, int sendcount, MPI_Datatype sendtype,
                  void *recvbuf, int recvcount, MPI_Datatype recvtype,
                  MPI_Comm comm, MPI_Request *request);
#pragma weak MPI_Ialltoall = PMPI_Ialltoall

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Ialltoall(void *sendbuf, int sendcount,
                                MPI_Datatype sendtype, void *recvbuf,
                                int recvcount, MPI_Datatype recvtype,
                                MPI_Comm comm, MPI_Request *request);

int INTERF_2_INTEL_MPI_Ialltoall(void *sendbuf, int sendcount,
                                 MPI_Datatype sendtype, void *recvbuf,
                                 int recvcount, MPI_Datatype recvtype,
                                 MPI_Comm comm, MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Ialltoall)(void *sendbuf, int sendcount,
                                     MPI_Datatype sendtype, void *recvbuf,
                                     int recvcount, MPI_Datatype recvtype,
                                     MPI_Comm comm, MPI_Request *request);
int PMPI_Ialltoall(void *sendbuf, int sendcount, MPI_Datatype sendtype,
                   void *recvbuf, int recvcount, MPI_Datatype recvtype,
                   MPI_Comm comm, MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_Ialltoall(sendbuf, sendcount, sendtype, recvbuf,
                                       recvcount, recvtype, comm, request);
}

int MPI_Ireduce(void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype,
                MPI_Op op, int root, MPI_Comm comm, MPI_Request *request);
#pragma weak MPI_Ireduce = PMPI_Ireduce

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Ireduce(void *sendbuf, void *recvbuf, int count,
                              MPI_Datatype datatype, MPI_Op op, int root,
                              MPI_Comm comm, MPI_Request *request);

int INTERF_2_INTEL_MPI_Ireduce(void *sendbuf, void *recvbuf, int count,
                               MPI_Datatype datatype, MPI_Op op, int root,
                               MPI_Comm comm, MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Ireduce)(void *sendbuf, void *recvbuf, int count,
                                   MPI_Datatype datatype, MPI_Op op, int root,
                                   MPI_Comm comm, MPI_Request *request);
int PMPI_Ireduce(void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype,
                 MPI_Op op, int root, MPI_Comm comm, MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_Ireduce(sendbuf, recvbuf, count, datatype, op,
                                     root, comm, request);
}

int MPI_Iallreduce(void *sendbuf, void *recvbuf, int count,
                   MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                   MPI_Request *request);
#pragma weak MPI_Iallreduce = PMPI_Iallreduce

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Iallreduce(void *sendbuf, void *recvbuf, int count,
                                 MPI_Datatype datatype, MPI_Op op,
                                 MPI_Comm comm, MPI_Request *request);

int INTERF_2_INTEL_MPI_Iallreduce(void *sendbuf, void *recvbuf, int count,
                                  MPI_Datatype datatype, MPI_Op op,
                                  MPI_Comm comm, MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Iallreduce)(void *sendbuf, void *recvbuf, int count,
                                      MPI_Datatype datatype, MPI_Op op,
                                      MPI_Comm comm, MPI_Request *request);
int PMPI_Iallreduce(void *sendbuf, void *recvbuf, int count,
                    MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                    MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_Iallreduce(sendbuf, recvbuf, count, datatype, op,
                                        comm, request);
}

int MPI_Ireduce_scatter_block(void *sendbuf, void *recvbuf, int recvcount,
                              MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                              MPI_Request *request);
#pragma weak MPI_Ireduce_scatter_block = PMPI_Ireduce_scatter_block

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Ireduce_scatter_block(void *sendbuf, void *recvbuf,
                                            int recvcount,
                                            MPI_Datatype datatype, MPI_Op op,
                                            MPI_Comm comm,
                                            MPI_Request *request);

int INTERF_2_INTEL_MPI_Ireduce_scatter_block(void *sendbuf, void *recvbuf,
                                             int recvcount,
                                             MPI_Datatype datatype, MPI_Op op,
                                             MPI_Comm comm,
                                             MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Ireduce_scatter_block)(void *sendbuf, void *recvbuf,
                                                 int recvcount,
                                                 MPI_Datatype datatype,
                                                 MPI_Op op, MPI_Comm comm,
                                                 MPI_Request *request);
int PMPI_Ireduce_scatter_block(void *sendbuf, void *recvbuf, int recvcount,
                               MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                               MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_Ireduce_scatter_block(sendbuf, recvbuf, recvcount,
                                                   datatype, op, comm, request);
}

int MPI_Iscan(void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype,
              MPI_Op op, MPI_Comm comm, MPI_Request *request);
#pragma weak MPI_Iscan = PMPI_Iscan

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Iscan(void *sendbuf, void *recvbuf, int count,
                            MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                            MPI_Request *request);

int INTERF_2_INTEL_MPI_Iscan(void *sendbuf, void *recvbuf, int count,
                             MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                             MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Iscan)(void *sendbuf, void *recvbuf, int count,
                                 MPI_Datatype datatype, MPI_Op op,
                                 MPI_Comm comm, MPI_Request *request);
int PMPI_Iscan(void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype,
               MPI_Op op, MPI_Comm comm, MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_Iscan(sendbuf, recvbuf, count, datatype, op, comm,
                                   request);
}

int MPI_Iexscan(void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype,
                MPI_Op op, MPI_Comm comm, MPI_Request *request);
#pragma weak MPI_Iexscan = PMPI_Iexscan

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Iexscan(void *sendbuf, void *recvbuf, int count,
                              MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                              MPI_Request *request);

int INTERF_2_INTEL_MPI_Iexscan(void *sendbuf, void *recvbuf, int count,
                               MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                               MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Iexscan)(void *sendbuf, void *recvbuf, int count,
                                   MPI_Datatype datatype, MPI_Op op,
                                   MPI_Comm comm, MPI_Request *request);
int PMPI_Iexscan(void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype,
                 MPI_Op op, MPI_Comm comm, MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_Iexscan(sendbuf, recvbuf, count, datatype, op,
                                     comm, request);
}

int MPI_Ineighbor_allgather(void *sendbuf, int sendcount, MPI_Datatype sendtype,
                            void *recvbuf, int recvcount, MPI_Datatype recvtype,
                            MPI_Comm comm, MPI_Request *request);
#pragma weak MPI_Ineighbor_allgather = PMPI_Ineighbor_allgather

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Ineighbor_allgather(void *sendbuf, int sendcount,
                                          MPI_Datatype sendtype, void *recvbuf,
                                          int recvcount, MPI_Datatype recvtype,
                                          MPI_Comm comm, MPI_Request *request);

int INTERF_2_INTEL_MPI_Ineighbor_allgather(void *sendbuf, int sendcount,
                                           MPI_Datatype sendtype, void *recvbuf,
                                           int recvcount, MPI_Datatype recvtype,
                                           MPI_Comm comm, MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Ineighbor_allgather)(
    void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf,
    int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request);
int PMPI_Ineighbor_allgather(void *sendbuf, int sendcount,
                             MPI_Datatype sendtype, void *recvbuf,
                             int recvcount, MPI_Datatype recvtype,
                             MPI_Comm comm, MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_Ineighbor_allgather(sendbuf, sendcount, sendtype,
                                                 recvbuf, recvcount, recvtype,
                                                 comm, request);
}

int MPI_Ineighbor_alltoall(void *sendbuf, int sendcount, MPI_Datatype sendtype,
                           void *recvbuf, int recvcount, MPI_Datatype recvtype,
                           MPI_Comm comm, MPI_Request *request);
#pragma weak MPI_Ineighbor_alltoall = PMPI_Ineighbor_alltoall

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Ineighbor_alltoall(void *sendbuf, int sendcount,
                                         MPI_Datatype sendtype, void *recvbuf,
                                         int recvcount, MPI_Datatype recvtype,
                                         MPI_Comm comm, MPI_Request *request);

int INTERF_2_INTEL_MPI_Ineighbor_alltoall(void *sendbuf, int sendcount,
                                          MPI_Datatype sendtype, void *recvbuf,
                                          int recvcount, MPI_Datatype recvtype,
                                          MPI_Comm comm, MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Ineighbor_alltoall)(
    void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf,
    int recvcount, MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request);
int PMPI_Ineighbor_alltoall(void *sendbuf, int sendcount, MPI_Datatype sendtype,
                            void *recvbuf, int recvcount, MPI_Datatype recvtype,
                            MPI_Comm comm, MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_Ineighbor_alltoall(sendbuf, sendcount, sendtype,
                                                recvbuf, recvcount, recvtype,
                                                comm, request);
}

int MPI_Neighbor_allgather(void *sendbuf, int sendcount, MPI_Datatype sendtype,
                           void *recvbuf, int recvcount, MPI_Datatype recvtype,
                           MPI_Comm comm);
#pragma weak MPI_Neighbor_allgather = PMPI_Neighbor_allgather

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Neighbor_allgather(void *sendbuf, int sendcount,
                                         MPI_Datatype sendtype, void *recvbuf,
                                         int recvcount, MPI_Datatype recvtype,
                                         MPI_Comm comm);

int INTERF_2_INTEL_MPI_Neighbor_allgather(void *sendbuf, int sendcount,
                                          MPI_Datatype sendtype, void *recvbuf,
                                          int recvcount, MPI_Datatype recvtype,
                                          MPI_Comm comm);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Neighbor_allgather)(void *sendbuf, int sendcount,
                                              MPI_Datatype sendtype,
                                              void *recvbuf, int recvcount,
                                              MPI_Datatype recvtype,
                                              MPI_Comm comm);
int PMPI_Neighbor_allgather(void *sendbuf, int sendcount, MPI_Datatype sendtype,
                            void *recvbuf, int recvcount, MPI_Datatype recvtype,
                            MPI_Comm comm) {
  return INTERFACE_LOCAL_MPI_Neighbor_allgather(
      sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm);
}

int MPI_Neighbor_alltoall(void *sendbuf, int sendcount, MPI_Datatype sendtype,
                          void *recvbuf, int recvcount, MPI_Datatype recvtype,
                          MPI_Comm comm);
#pragma weak MPI_Neighbor_alltoall = PMPI_Neighbor_alltoall

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Neighbor_alltoall(void *sendbuf, int sendcount,
                                        MPI_Datatype sendtype, void *recvbuf,
                                        int recvcount, MPI_Datatype recvtype,
                                        MPI_Comm comm);

int INTERF_2_INTEL_MPI_Neighbor_alltoall(void *sendbuf, int sendcount,
                                         MPI_Datatype sendtype, void *recvbuf,
                                         int recvcount, MPI_Datatype recvtype,
                                         MPI_Comm comm);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Neighbor_alltoall)(void *sendbuf, int sendcount,
                                             MPI_Datatype sendtype,
                                             void *recvbuf, int recvcount,
                                             MPI_Datatype recvtype,
                                             MPI_Comm comm);
int PMPI_Neighbor_alltoall(void *sendbuf, int sendcount, MPI_Datatype sendtype,
                           void *recvbuf, int recvcount, MPI_Datatype recvtype,
                           MPI_Comm comm) {
  return INTERFACE_LOCAL_MPI_Neighbor_alltoall(
      sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm);
}

int MPI_Comm_split_type(MPI_Comm comm, int split_type, int key, MPI_Info info,
                        MPI_Comm *newcomm);
#pragma weak MPI_Comm_split_type = PMPI_Comm_split_type

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Comm_split_type(MPI_Comm comm, int split_type, int key,
                                      MPI_Info info, MPI_Comm *newcomm);

int INTERF_2_INTEL_MPI_Comm_split_type(MPI_Comm comm, int split_type, int key,
                                       MPI_Info info, MPI_Comm *newcomm);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Comm_split_type)(MPI_Comm comm, int split_type,
                                           int key, MPI_Info info,
                                           MPI_Comm *newcomm);
int PMPI_Comm_split_type(MPI_Comm comm, int split_type, int key, MPI_Info info,
                         MPI_Comm *newcomm) {
  return INTERFACE_LOCAL_MPI_Comm_split_type(comm, split_type, key, info,
                                             newcomm);
}

int MPI_Get_elements_x(MPI_Status *status, MPI_Datatype datatype,
                       MPI_Count *count);
#pragma weak MPI_Get_elements_x = PMPI_Get_elements_x

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Get_elements_x(MPI_Status *status, MPI_Datatype datatype,
                                     MPI_Count *count);

int INTERF_2_INTEL_MPI_Get_elements_x(MPI_Status *status, MPI_Datatype datatype,
                                      MPI_Count *count);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Get_elements_x)(MPI_Status *status,
                                          MPI_Datatype datatype,
                                          MPI_Count *count);
int PMPI_Get_elements_x(MPI_Status *status, MPI_Datatype datatype,
                        MPI_Count *count) {
  return INTERFACE_LOCAL_MPI_Get_elements_x(status, datatype, count);
}

int MPI_Status_set_elements_x(MPI_Status *status, MPI_Datatype datatype,
                              MPI_Count count);
#pragma weak MPI_Status_set_elements_x = PMPI_Status_set_elements_x

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Status_set_elements_x(MPI_Status *status,
                                            MPI_Datatype datatype,
                                            MPI_Count count);

int INTERF_2_INTEL_MPI_Status_set_elements_x(MPI_Status *status,
                                             MPI_Datatype datatype,
                                             MPI_Count count);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Status_set_elements_x)(MPI_Status *status,
                                                 MPI_Datatype datatype,
                                                 MPI_Count count);
int PMPI_Status_set_elements_x(MPI_Status *status, MPI_Datatype datatype,
                               MPI_Count count) {
  return INTERFACE_LOCAL_MPI_Status_set_elements_x(status, datatype, count);
}

int MPI_Type_get_extent_x(MPI_Datatype datatype, MPI_Count *lb,
                          MPI_Count *extent);
#pragma weak MPI_Type_get_extent_x = PMPI_Type_get_extent_x

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Type_get_extent_x(MPI_Datatype datatype, MPI_Count *lb,
                                        MPI_Count *extent);

int INTERF_2_INTEL_MPI_Type_get_extent_x(MPI_Datatype datatype, MPI_Count *lb,
                                         MPI_Count *extent);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Type_get_extent_x)(MPI_Datatype datatype,
                                             MPI_Count *lb, MPI_Count *extent);
int PMPI_Type_get_extent_x(MPI_Datatype datatype, MPI_Count *lb,
                           MPI_Count *extent) {
  return INTERFACE_LOCAL_MPI_Type_get_extent_x(datatype, lb, extent);
}

int MPI_Type_get_true_extent_x(MPI_Datatype datatype, MPI_Count *lb,
                               MPI_Count *extent);
#pragma weak MPI_Type_get_true_extent_x = PMPI_Type_get_true_extent_x

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Type_get_true_extent_x(MPI_Datatype datatype,
                                             MPI_Count *lb, MPI_Count *extent);

int INTERF_2_INTEL_MPI_Type_get_true_extent_x(MPI_Datatype datatype,
                                              MPI_Count *lb, MPI_Count *extent);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Type_get_true_extent_x)(MPI_Datatype datatype,
                                                  MPI_Count *lb,
                                                  MPI_Count *extent);
int PMPI_Type_get_true_extent_x(MPI_Datatype datatype, MPI_Count *lb,
                                MPI_Count *extent) {
  return INTERFACE_LOCAL_MPI_Type_get_true_extent_x(datatype, lb, extent);
}

int MPI_Type_size_x(MPI_Datatype datatype, MPI_Count *size);
#pragma weak MPI_Type_size_x = PMPI_Type_size_x

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Type_size_x(MPI_Datatype datatype, MPI_Count *size);

int INTERF_2_INTEL_MPI_Type_size_x(MPI_Datatype datatype, MPI_Count *size);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Type_size_x)(MPI_Datatype datatype, MPI_Count *size);
int PMPI_Type_size_x(MPI_Datatype datatype, MPI_Count *size) {
  return INTERFACE_LOCAL_MPI_Type_size_x(datatype, size);
}

int MPI_Comm_create_group(MPI_Comm comm, MPI_Group group, int tag,
                          MPI_Comm *newcomm);
#pragma weak MPI_Comm_create_group = PMPI_Comm_create_group

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Comm_create_group(MPI_Comm comm, MPI_Group group, int tag,
                                        MPI_Comm *newcomm);

int INTERF_2_INTEL_MPI_Comm_create_group(MPI_Comm comm, MPI_Group group,
                                         int tag, MPI_Comm *newcomm);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Comm_create_group)(MPI_Comm comm, MPI_Group group,
                                             int tag, MPI_Comm *newcomm);
int PMPI_Comm_create_group(MPI_Comm comm, MPI_Group group, int tag,
                           MPI_Comm *newcomm) {
  return INTERFACE_LOCAL_MPI_Comm_create_group(comm, group, tag, newcomm);
}

int MPI_T_init_thread(int required, int *provided);
#pragma weak MPI_T_init_thread = PMPI_T_init_thread

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_T_init_thread(int required, int *provided);

int INTERF_2_INTEL_MPI_T_init_thread(int required, int *provided);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_T_init_thread)(int required, int *provided);
int PMPI_T_init_thread(int required, int *provided) {
  return INTERFACE_LOCAL_MPI_T_init_thread(required, provided);
}

int MPI_T_enum_get_info(MPI_T_enum enumtype, int *num, char *name,
                        int *name_len);
#pragma weak MPI_T_enum_get_info = PMPI_T_enum_get_info

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_T_enum_get_info(MPI_T_enum enumtype, int *num, char *name,
                                      int *name_len);

int INTERF_2_INTEL_MPI_T_enum_get_info(MPI_T_enum enumtype, int *num,
                                       char *name, int *name_len);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_T_enum_get_info)(MPI_T_enum enumtype, int *num,
                                           char *name, int *name_len);
int PMPI_T_enum_get_info(MPI_T_enum enumtype, int *num, char *name,
                         int *name_len) {
  return INTERFACE_LOCAL_MPI_T_enum_get_info(enumtype, num, name, name_len);
}

int MPI_T_enum_get_item(MPI_T_enum enumtype, int indx, int *value, char *name,
                        int *name_len);
#pragma weak MPI_T_enum_get_item = PMPI_T_enum_get_item

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_T_enum_get_item(MPI_T_enum enumtype, int indx, int *value,
                                      char *name, int *name_len);

int INTERF_2_INTEL_MPI_T_enum_get_item(MPI_T_enum enumtype, int indx,
                                       int *value, char *name, int *name_len);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_T_enum_get_item)(MPI_T_enum enumtype, int indx,
                                           int *value, char *name,
                                           int *name_len);
int PMPI_T_enum_get_item(MPI_T_enum enumtype, int indx, int *value, char *name,
                         int *name_len) {
  return INTERFACE_LOCAL_MPI_T_enum_get_item(enumtype, indx, value, name,
                                             name_len);
}

int MPI_T_cvar_get_num(int *num_cvar);
#pragma weak MPI_T_cvar_get_num = PMPI_T_cvar_get_num

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_T_cvar_get_num(int *num_cvar);

int INTERF_2_INTEL_MPI_T_cvar_get_num(int *num_cvar);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_T_cvar_get_num)(int *num_cvar);
int PMPI_T_cvar_get_num(int *num_cvar) {
  return INTERFACE_LOCAL_MPI_T_cvar_get_num(num_cvar);
}

int MPI_T_cvar_get_info(int cvar_index, char *name, int *name_len,
                        int *verbosity, MPI_Datatype *datatype,
                        MPI_T_enum *enumtype, char *desc, int *desc_len,
                        int *binding, int *scope);
#pragma weak MPI_T_cvar_get_info = PMPI_T_cvar_get_info

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_T_cvar_get_info(int cvar_index, char *name, int *name_len,
                                      int *verbosity, MPI_Datatype *datatype,
                                      MPI_T_enum *enumtype, char *desc,
                                      int *desc_len, int *binding, int *scope);

int INTERF_2_INTEL_MPI_T_cvar_get_info(int cvar_index, char *name,
                                       int *name_len, int *verbosity,
                                       MPI_Datatype *datatype,
                                       MPI_T_enum *enumtype, char *desc,
                                       int *desc_len, int *binding, int *scope);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_T_cvar_get_info)(int cvar_index, char *name,
                                           int *name_len, int *verbosity,
                                           MPI_Datatype *datatype,
                                           MPI_T_enum *enumtype, char *desc,
                                           int *desc_len, int *binding,
                                           int *scope);
int PMPI_T_cvar_get_info(int cvar_index, char *name, int *name_len,
                         int *verbosity, MPI_Datatype *datatype,
                         MPI_T_enum *enumtype, char *desc, int *desc_len,
                         int *binding, int *scope) {
  return INTERFACE_LOCAL_MPI_T_cvar_get_info(cvar_index, name, name_len,
                                             verbosity, datatype, enumtype,
                                             desc, desc_len, binding, scope);
}

int MPI_T_cvar_handle_alloc(int cvar_index, void *obj_handle,
                            MPI_T_cvar_handle *handle, int *count);
#pragma weak MPI_T_cvar_handle_alloc = PMPI_T_cvar_handle_alloc

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_T_cvar_handle_alloc(int cvar_index, void *obj_handle,
                                          MPI_T_cvar_handle *handle,
                                          int *count);

int INTERF_2_INTEL_MPI_T_cvar_handle_alloc(int cvar_index, void *obj_handle,
                                           MPI_T_cvar_handle *handle,
                                           int *count);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_T_cvar_handle_alloc)(int cvar_index, void *obj_handle,
                                               MPI_T_cvar_handle *handle,
                                               int *count);
int PMPI_T_cvar_handle_alloc(int cvar_index, void *obj_handle,
                             MPI_T_cvar_handle *handle, int *count) {
  return INTERFACE_LOCAL_MPI_T_cvar_handle_alloc(cvar_index, obj_handle, handle,
                                                 count);
}

int MPI_T_cvar_handle_free(MPI_T_cvar_handle *handle);
#pragma weak MPI_T_cvar_handle_free = PMPI_T_cvar_handle_free

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_T_cvar_handle_free(MPI_T_cvar_handle *handle);

int INTERF_2_INTEL_MPI_T_cvar_handle_free(MPI_T_cvar_handle *handle);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_T_cvar_handle_free)(MPI_T_cvar_handle *handle);
int PMPI_T_cvar_handle_free(MPI_T_cvar_handle *handle) {
  return INTERFACE_LOCAL_MPI_T_cvar_handle_free(handle);
}

int MPI_T_cvar_read(MPI_T_cvar_handle handle, void *buf);
#pragma weak MPI_T_cvar_read = PMPI_T_cvar_read

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_T_cvar_read(MPI_T_cvar_handle handle, void *buf);

int INTERF_2_INTEL_MPI_T_cvar_read(MPI_T_cvar_handle handle, void *buf);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_T_cvar_read)(MPI_T_cvar_handle handle, void *buf);
int PMPI_T_cvar_read(MPI_T_cvar_handle handle, void *buf) {
  return INTERFACE_LOCAL_MPI_T_cvar_read(handle, buf);
}

int MPI_T_cvar_write(MPI_T_cvar_handle handle, void *buf);
#pragma weak MPI_T_cvar_write = PMPI_T_cvar_write

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_T_cvar_write(MPI_T_cvar_handle handle, void *buf);

int INTERF_2_INTEL_MPI_T_cvar_write(MPI_T_cvar_handle handle, void *buf);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_T_cvar_write)(MPI_T_cvar_handle handle, void *buf);
int PMPI_T_cvar_write(MPI_T_cvar_handle handle, void *buf) {
  return INTERFACE_LOCAL_MPI_T_cvar_write(handle, buf);
}

int MPI_T_pvar_get_num(int *num_pvar);
#pragma weak MPI_T_pvar_get_num = PMPI_T_pvar_get_num

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_T_pvar_get_num(int *num_pvar);

int INTERF_2_INTEL_MPI_T_pvar_get_num(int *num_pvar);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_T_pvar_get_num)(int *num_pvar);
int PMPI_T_pvar_get_num(int *num_pvar) {
  return INTERFACE_LOCAL_MPI_T_pvar_get_num(num_pvar);
}

int MPI_T_pvar_get_info(int pvar_index, char *name, int *name_len,
                        int *verbosity, int *var_class, MPI_Datatype *datatype,
                        MPI_T_enum *enumtype, char *desc, int *desc_len,
                        int *binding, int *readonly, int *continuous,
                        int *atomic);
#pragma weak MPI_T_pvar_get_info = PMPI_T_pvar_get_info

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_T_pvar_get_info(
    int pvar_index, char *name, int *name_len, int *verbosity, int *var_class,
    MPI_Datatype *datatype, MPI_T_enum *enumtype, char *desc, int *desc_len,
    int *binding, int *readonly, int *continuous, int *atomic);

int INTERF_2_INTEL_MPI_T_pvar_get_info(
    int pvar_index, char *name, int *name_len, int *verbosity, int *var_class,
    MPI_Datatype *datatype, MPI_T_enum *enumtype, char *desc, int *desc_len,
    int *binding, int *readonly, int *continuous, int *atomic);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_T_pvar_get_info)(
    int pvar_index, char *name, int *name_len, int *verbosity, int *var_class,
    MPI_Datatype *datatype, MPI_T_enum *enumtype, char *desc, int *desc_len,
    int *binding, int *readonly, int *continuous, int *atomic);
int PMPI_T_pvar_get_info(int pvar_index, char *name, int *name_len,
                         int *verbosity, int *var_class, MPI_Datatype *datatype,
                         MPI_T_enum *enumtype, char *desc, int *desc_len,
                         int *binding, int *readonly, int *continuous,
                         int *atomic) {
  return INTERFACE_LOCAL_MPI_T_pvar_get_info(
      pvar_index, name, name_len, verbosity, var_class, datatype, enumtype,
      desc, desc_len, binding, readonly, continuous, atomic);
}

int MPI_T_category_get_num(int *num_cat);
#pragma weak MPI_T_category_get_num = PMPI_T_category_get_num

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_T_category_get_num(int *num_cat);

int INTERF_2_INTEL_MPI_T_category_get_num(int *num_cat);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_T_category_get_num)(int *num_cat);
int PMPI_T_category_get_num(int *num_cat) {
  return INTERFACE_LOCAL_MPI_T_category_get_num(num_cat);
}

int MPI_T_category_get_info(int cat_index, char *name, int *name_len,
                            char *desc, int *desc_len, int *num_cvars,
                            int *num_pvars, int *num_categories);
#pragma weak MPI_T_category_get_info = PMPI_T_category_get_info

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_T_category_get_info(int cat_index, char *name,
                                          int *name_len, char *desc,
                                          int *desc_len, int *num_cvars,
                                          int *num_pvars, int *num_categories);

int INTERF_2_INTEL_MPI_T_category_get_info(int cat_index, char *name,
                                           int *name_len, char *desc,
                                           int *desc_len, int *num_cvars,
                                           int *num_pvars, int *num_categories);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_T_category_get_info)(int cat_index, char *name,
                                               int *name_len, char *desc,
                                               int *desc_len, int *num_cvars,
                                               int *num_pvars,
                                               int *num_categories);
int PMPI_T_category_get_info(int cat_index, char *name, int *name_len,
                             char *desc, int *desc_len, int *num_cvars,
                             int *num_pvars, int *num_categories) {
  return INTERFACE_LOCAL_MPI_T_category_get_info(cat_index, name, name_len,
                                                 desc, desc_len, num_cvars,
                                                 num_pvars, num_categories);
}

int MPI_File_open(MPI_Comm comm, char *filename, int amode, MPI_Info info,
                  MPI_File *fh);
#pragma weak MPI_File_open = PMPI_File_open

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_open(MPI_Comm comm, char *filename, int amode,
                                MPI_Info info, MPI_File *fh);

int INTERF_2_INTEL_MPI_File_open(MPI_Comm comm, char *filename, int amode,
                                 MPI_Info info, MPI_File *fh);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_open)(MPI_Comm comm, char *filename, int amode,
                                     MPI_Info info, MPI_File *fh);
int PMPI_File_open(MPI_Comm comm, char *filename, int amode, MPI_Info info,
                   MPI_File *fh) {
  return INTERFACE_LOCAL_MPI_File_open(comm, filename, amode, info, fh);
}

int MPI_File_close(MPI_File *fh);
#pragma weak MPI_File_close = PMPI_File_close

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_close(MPI_File *fh);

int INTERF_2_INTEL_MPI_File_close(MPI_File *fh);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_close)(MPI_File *fh);
int PMPI_File_close(MPI_File *fh) { return INTERFACE_LOCAL_MPI_File_close(fh); }

int MPI_File_delete(char *filename, MPI_Info info);
#pragma weak MPI_File_delete = PMPI_File_delete

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_delete(char *filename, MPI_Info info);

int INTERF_2_INTEL_MPI_File_delete(char *filename, MPI_Info info);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_delete)(char *filename, MPI_Info info);
int PMPI_File_delete(char *filename, MPI_Info info) {
  return INTERFACE_LOCAL_MPI_File_delete(filename, info);
}

int MPI_File_set_size(MPI_File fh, MPI_Offset size);
#pragma weak MPI_File_set_size = PMPI_File_set_size

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_set_size(MPI_File fh, MPI_Offset size);

int INTERF_2_INTEL_MPI_File_set_size(MPI_File fh, MPI_Offset size);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_set_size)(MPI_File fh, MPI_Offset size);
int PMPI_File_set_size(MPI_File fh, MPI_Offset size) {
  return INTERFACE_LOCAL_MPI_File_set_size(fh, size);
}

int MPI_File_preallocate(MPI_File fh, MPI_Offset size);
#pragma weak MPI_File_preallocate = PMPI_File_preallocate

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_preallocate(MPI_File fh, MPI_Offset size);

int INTERF_2_INTEL_MPI_File_preallocate(MPI_File fh, MPI_Offset size);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_preallocate)(MPI_File fh, MPI_Offset size);
int PMPI_File_preallocate(MPI_File fh, MPI_Offset size) {
  return INTERFACE_LOCAL_MPI_File_preallocate(fh, size);
}

int MPI_File_get_size(MPI_File fh, MPI_Offset *size);
#pragma weak MPI_File_get_size = PMPI_File_get_size

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_get_size(MPI_File fh, MPI_Offset *size);

int INTERF_2_INTEL_MPI_File_get_size(MPI_File fh, MPI_Offset *size);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_get_size)(MPI_File fh, MPI_Offset *size);
int PMPI_File_get_size(MPI_File fh, MPI_Offset *size) {
  return INTERFACE_LOCAL_MPI_File_get_size(fh, size);
}

int MPI_File_get_group(MPI_File fh, MPI_Group *group);
#pragma weak MPI_File_get_group = PMPI_File_get_group

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_get_group(MPI_File fh, MPI_Group *group);

int INTERF_2_INTEL_MPI_File_get_group(MPI_File fh, MPI_Group *group);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_get_group)(MPI_File fh, MPI_Group *group);
int PMPI_File_get_group(MPI_File fh, MPI_Group *group) {
  return INTERFACE_LOCAL_MPI_File_get_group(fh, group);
}

int MPI_File_get_amode(MPI_File fh, int *amode);
#pragma weak MPI_File_get_amode = PMPI_File_get_amode

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_get_amode(MPI_File fh, int *amode);

int INTERF_2_INTEL_MPI_File_get_amode(MPI_File fh, int *amode);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_get_amode)(MPI_File fh, int *amode);
int PMPI_File_get_amode(MPI_File fh, int *amode) {
  return INTERFACE_LOCAL_MPI_File_get_amode(fh, amode);
}

int MPI_File_set_info(MPI_File fh, MPI_Info info);
#pragma weak MPI_File_set_info = PMPI_File_set_info

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_set_info(MPI_File fh, MPI_Info info);

int INTERF_2_INTEL_MPI_File_set_info(MPI_File fh, MPI_Info info);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_set_info)(MPI_File fh, MPI_Info info);
int PMPI_File_set_info(MPI_File fh, MPI_Info info) {
  return INTERFACE_LOCAL_MPI_File_set_info(fh, info);
}

int MPI_File_get_info(MPI_File fh, MPI_Info *info_used);
#pragma weak MPI_File_get_info = PMPI_File_get_info

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_get_info(MPI_File fh, MPI_Info *info_used);

int INTERF_2_INTEL_MPI_File_get_info(MPI_File fh, MPI_Info *info_used);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_get_info)(MPI_File fh, MPI_Info *info_used);
int PMPI_File_get_info(MPI_File fh, MPI_Info *info_used) {
  return INTERFACE_LOCAL_MPI_File_get_info(fh, info_used);
}

int MPI_File_set_view(MPI_File fh, MPI_Offset disp, MPI_Datatype etype,
                      MPI_Datatype filetype, char *datarep, MPI_Info info);
#pragma weak MPI_File_set_view = PMPI_File_set_view

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_set_view(MPI_File fh, MPI_Offset disp,
                                    MPI_Datatype etype, MPI_Datatype filetype,
                                    char *datarep, MPI_Info info);

int INTERF_2_INTEL_MPI_File_set_view(MPI_File fh, MPI_Offset disp,
                                     MPI_Datatype etype, MPI_Datatype filetype,
                                     char *datarep, MPI_Info info);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_set_view)(MPI_File fh, MPI_Offset disp,
                                         MPI_Datatype etype,
                                         MPI_Datatype filetype, char *datarep,
                                         MPI_Info info);
int PMPI_File_set_view(MPI_File fh, MPI_Offset disp, MPI_Datatype etype,
                       MPI_Datatype filetype, char *datarep, MPI_Info info) {
  return INTERFACE_LOCAL_MPI_File_set_view(fh, disp, etype, filetype, datarep,
                                           info);
}

int MPI_File_get_view(MPI_File fh, MPI_Offset *disp, MPI_Datatype *etype,
                      MPI_Datatype *filetype, char *datarep);
#pragma weak MPI_File_get_view = PMPI_File_get_view

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_get_view(MPI_File fh, MPI_Offset *disp,
                                    MPI_Datatype *etype, MPI_Datatype *filetype,
                                    char *datarep);

int INTERF_2_INTEL_MPI_File_get_view(MPI_File fh, MPI_Offset *disp,
                                     MPI_Datatype *etype,
                                     MPI_Datatype *filetype, char *datarep);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_get_view)(MPI_File fh, MPI_Offset *disp,
                                         MPI_Datatype *etype,
                                         MPI_Datatype *filetype, char *datarep);
int PMPI_File_get_view(MPI_File fh, MPI_Offset *disp, MPI_Datatype *etype,
                       MPI_Datatype *filetype, char *datarep) {
  return INTERFACE_LOCAL_MPI_File_get_view(fh, disp, etype, filetype, datarep);
}

int MPI_File_read_at(MPI_File fh, MPI_Offset offset, void *buf, int count,
                     MPI_Datatype datatype, MPI_Status *status);
#pragma weak MPI_File_read_at = PMPI_File_read_at

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_read_at(MPI_File fh, MPI_Offset offset, void *buf,
                                   int count, MPI_Datatype datatype,
                                   MPI_Status *status);

int INTERF_2_INTEL_MPI_File_read_at(MPI_File fh, MPI_Offset offset, void *buf,
                                    int count, MPI_Datatype datatype,
                                    MPI_Status *status);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_read_at)(MPI_File fh, MPI_Offset offset,
                                        void *buf, int count,
                                        MPI_Datatype datatype,
                                        MPI_Status *status);
int PMPI_File_read_at(MPI_File fh, MPI_Offset offset, void *buf, int count,
                      MPI_Datatype datatype, MPI_Status *status) {
  return INTERFACE_LOCAL_MPI_File_read_at(fh, offset, buf, count, datatype,
                                          status);
}

int MPI_File_read_at_all(MPI_File fh, MPI_Offset offset, void *buf, int count,
                         MPI_Datatype datatype, MPI_Status *status);
#pragma weak MPI_File_read_at_all = PMPI_File_read_at_all

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_read_at_all(MPI_File fh, MPI_Offset offset,
                                       void *buf, int count,
                                       MPI_Datatype datatype,
                                       MPI_Status *status);

int INTERF_2_INTEL_MPI_File_read_at_all(MPI_File fh, MPI_Offset offset,
                                        void *buf, int count,
                                        MPI_Datatype datatype,
                                        MPI_Status *status);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_read_at_all)(MPI_File fh, MPI_Offset offset,
                                            void *buf, int count,
                                            MPI_Datatype datatype,
                                            MPI_Status *status);
int PMPI_File_read_at_all(MPI_File fh, MPI_Offset offset, void *buf, int count,
                          MPI_Datatype datatype, MPI_Status *status) {
  return INTERFACE_LOCAL_MPI_File_read_at_all(fh, offset, buf, count, datatype,
                                              status);
}

int MPI_File_write_at(MPI_File fh, MPI_Offset offset, void *buf, int count,
                      MPI_Datatype datatype, MPI_Status *status);
#pragma weak MPI_File_write_at = PMPI_File_write_at

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_write_at(MPI_File fh, MPI_Offset offset, void *buf,
                                    int count, MPI_Datatype datatype,
                                    MPI_Status *status);

int INTERF_2_INTEL_MPI_File_write_at(MPI_File fh, MPI_Offset offset, void *buf,
                                     int count, MPI_Datatype datatype,
                                     MPI_Status *status);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_write_at)(MPI_File fh, MPI_Offset offset,
                                         void *buf, int count,
                                         MPI_Datatype datatype,
                                         MPI_Status *status);
int PMPI_File_write_at(MPI_File fh, MPI_Offset offset, void *buf, int count,
                       MPI_Datatype datatype, MPI_Status *status) {
  return INTERFACE_LOCAL_MPI_File_write_at(fh, offset, buf, count, datatype,
                                           status);
}

int MPI_File_write_at_all(MPI_File fh, MPI_Offset offset, void *buf, int count,
                          MPI_Datatype datatype, MPI_Status *status);
#pragma weak MPI_File_write_at_all = PMPI_File_write_at_all

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_write_at_all(MPI_File fh, MPI_Offset offset,
                                        void *buf, int count,
                                        MPI_Datatype datatype,
                                        MPI_Status *status);

int INTERF_2_INTEL_MPI_File_write_at_all(MPI_File fh, MPI_Offset offset,
                                         void *buf, int count,
                                         MPI_Datatype datatype,
                                         MPI_Status *status);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_write_at_all)(MPI_File fh, MPI_Offset offset,
                                             void *buf, int count,
                                             MPI_Datatype datatype,
                                             MPI_Status *status);
int PMPI_File_write_at_all(MPI_File fh, MPI_Offset offset, void *buf, int count,
                           MPI_Datatype datatype, MPI_Status *status) {
  return INTERFACE_LOCAL_MPI_File_write_at_all(fh, offset, buf, count, datatype,
                                               status);
}

int MPI_File_iread_at(MPI_File fh, MPI_Offset offset, void *buf, int count,
                      MPI_Datatype datatype, MPI_Request *request);
#pragma weak MPI_File_iread_at = PMPI_File_iread_at

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_iread_at(MPI_File fh, MPI_Offset offset, void *buf,
                                    int count, MPI_Datatype datatype,
                                    MPI_Request *request);

int INTERF_2_INTEL_MPI_File_iread_at(MPI_File fh, MPI_Offset offset, void *buf,
                                     int count, MPI_Datatype datatype,
                                     MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_iread_at)(MPI_File fh, MPI_Offset offset,
                                         void *buf, int count,
                                         MPI_Datatype datatype,
                                         MPI_Request *request);
int PMPI_File_iread_at(MPI_File fh, MPI_Offset offset, void *buf, int count,
                       MPI_Datatype datatype, MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_File_iread_at(fh, offset, buf, count, datatype,
                                           request);
}

int MPI_File_iwrite_at(MPI_File fh, MPI_Offset offset, void *buf, int count,
                       MPI_Datatype datatype, MPI_Request *request);
#pragma weak MPI_File_iwrite_at = PMPI_File_iwrite_at

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_iwrite_at(MPI_File fh, MPI_Offset offset, void *buf,
                                     int count, MPI_Datatype datatype,
                                     MPI_Request *request);

int INTERF_2_INTEL_MPI_File_iwrite_at(MPI_File fh, MPI_Offset offset, void *buf,
                                      int count, MPI_Datatype datatype,
                                      MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_iwrite_at)(MPI_File fh, MPI_Offset offset,
                                          void *buf, int count,
                                          MPI_Datatype datatype,
                                          MPI_Request *request);
int PMPI_File_iwrite_at(MPI_File fh, MPI_Offset offset, void *buf, int count,
                        MPI_Datatype datatype, MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_File_iwrite_at(fh, offset, buf, count, datatype,
                                            request);
}

int MPI_File_read(MPI_File fh, void *buf, int count, MPI_Datatype datatype,
                  MPI_Status *status);
#pragma weak MPI_File_read = PMPI_File_read

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_read(MPI_File fh, void *buf, int count,
                                MPI_Datatype datatype, MPI_Status *status);

int INTERF_2_INTEL_MPI_File_read(MPI_File fh, void *buf, int count,
                                 MPI_Datatype datatype, MPI_Status *status);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_read)(MPI_File fh, void *buf, int count,
                                     MPI_Datatype datatype, MPI_Status *status);
int PMPI_File_read(MPI_File fh, void *buf, int count, MPI_Datatype datatype,
                   MPI_Status *status) {
  return INTERFACE_LOCAL_MPI_File_read(fh, buf, count, datatype, status);
}

int MPI_File_read_all(MPI_File fh, void *buf, int count, MPI_Datatype datatype,
                      MPI_Status *status);
#pragma weak MPI_File_read_all = PMPI_File_read_all

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_read_all(MPI_File fh, void *buf, int count,
                                    MPI_Datatype datatype, MPI_Status *status);

int INTERF_2_INTEL_MPI_File_read_all(MPI_File fh, void *buf, int count,
                                     MPI_Datatype datatype, MPI_Status *status);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_read_all)(MPI_File fh, void *buf, int count,
                                         MPI_Datatype datatype,
                                         MPI_Status *status);
int PMPI_File_read_all(MPI_File fh, void *buf, int count, MPI_Datatype datatype,
                       MPI_Status *status) {
  return INTERFACE_LOCAL_MPI_File_read_all(fh, buf, count, datatype, status);
}

int MPI_File_write(MPI_File fh, void *buf, int count, MPI_Datatype datatype,
                   MPI_Status *status);
#pragma weak MPI_File_write = PMPI_File_write

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_write(MPI_File fh, void *buf, int count,
                                 MPI_Datatype datatype, MPI_Status *status);

int INTERF_2_INTEL_MPI_File_write(MPI_File fh, void *buf, int count,
                                  MPI_Datatype datatype, MPI_Status *status);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_write)(MPI_File fh, void *buf, int count,
                                      MPI_Datatype datatype,
                                      MPI_Status *status);
int PMPI_File_write(MPI_File fh, void *buf, int count, MPI_Datatype datatype,
                    MPI_Status *status) {
  return INTERFACE_LOCAL_MPI_File_write(fh, buf, count, datatype, status);
}

int MPI_File_write_all(MPI_File fh, void *buf, int count, MPI_Datatype datatype,
                       MPI_Status *status);
#pragma weak MPI_File_write_all = PMPI_File_write_all

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_write_all(MPI_File fh, void *buf, int count,
                                     MPI_Datatype datatype, MPI_Status *status);

int INTERF_2_INTEL_MPI_File_write_all(MPI_File fh, void *buf, int count,
                                      MPI_Datatype datatype,
                                      MPI_Status *status);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_write_all)(MPI_File fh, void *buf, int count,
                                          MPI_Datatype datatype,
                                          MPI_Status *status);
int PMPI_File_write_all(MPI_File fh, void *buf, int count,
                        MPI_Datatype datatype, MPI_Status *status) {
  return INTERFACE_LOCAL_MPI_File_write_all(fh, buf, count, datatype, status);
}

int MPI_File_iread(MPI_File fh, void *buf, int count, MPI_Datatype datatype,
                   MPI_Request *request);
#pragma weak MPI_File_iread = PMPI_File_iread

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_iread(MPI_File fh, void *buf, int count,
                                 MPI_Datatype datatype, MPI_Request *request);

int INTERF_2_INTEL_MPI_File_iread(MPI_File fh, void *buf, int count,
                                  MPI_Datatype datatype, MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_iread)(MPI_File fh, void *buf, int count,
                                      MPI_Datatype datatype,
                                      MPI_Request *request);
int PMPI_File_iread(MPI_File fh, void *buf, int count, MPI_Datatype datatype,
                    MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_File_iread(fh, buf, count, datatype, request);
}

int MPI_File_iwrite(MPI_File fh, void *buf, int count, MPI_Datatype datatype,
                    MPI_Request *request);
#pragma weak MPI_File_iwrite = PMPI_File_iwrite

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_iwrite(MPI_File fh, void *buf, int count,
                                  MPI_Datatype datatype, MPI_Request *request);

int INTERF_2_INTEL_MPI_File_iwrite(MPI_File fh, void *buf, int count,
                                   MPI_Datatype datatype, MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_iwrite)(MPI_File fh, void *buf, int count,
                                       MPI_Datatype datatype,
                                       MPI_Request *request);
int PMPI_File_iwrite(MPI_File fh, void *buf, int count, MPI_Datatype datatype,
                     MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_File_iwrite(fh, buf, count, datatype, request);
}

int MPI_File_seek(MPI_File fh, MPI_Offset offset, int whence);
#pragma weak MPI_File_seek = PMPI_File_seek

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_seek(MPI_File fh, MPI_Offset offset, int whence);

int INTERF_2_INTEL_MPI_File_seek(MPI_File fh, MPI_Offset offset, int whence);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_seek)(MPI_File fh, MPI_Offset offset,
                                     int whence);
int PMPI_File_seek(MPI_File fh, MPI_Offset offset, int whence) {
  return INTERFACE_LOCAL_MPI_File_seek(fh, offset, whence);
}

int MPI_File_get_position(MPI_File fh, MPI_Offset *offset);
#pragma weak MPI_File_get_position = PMPI_File_get_position

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_get_position(MPI_File fh, MPI_Offset *offset);

int INTERF_2_INTEL_MPI_File_get_position(MPI_File fh, MPI_Offset *offset);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_get_position)(MPI_File fh, MPI_Offset *offset);
int PMPI_File_get_position(MPI_File fh, MPI_Offset *offset) {
  return INTERFACE_LOCAL_MPI_File_get_position(fh, offset);
}

int MPI_File_get_byte_offset(MPI_File fh, MPI_Offset offset, MPI_Offset *disp);
#pragma weak MPI_File_get_byte_offset = PMPI_File_get_byte_offset

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_get_byte_offset(MPI_File fh, MPI_Offset offset,
                                           MPI_Offset *disp);

int INTERF_2_INTEL_MPI_File_get_byte_offset(MPI_File fh, MPI_Offset offset,
                                            MPI_Offset *disp);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_get_byte_offset)(MPI_File fh, MPI_Offset offset,
                                                MPI_Offset *disp);
int PMPI_File_get_byte_offset(MPI_File fh, MPI_Offset offset,
                              MPI_Offset *disp) {
  return INTERFACE_LOCAL_MPI_File_get_byte_offset(fh, offset, disp);
}

int MPI_File_read_shared(MPI_File fh, void *buf, int count,
                         MPI_Datatype datatype, MPI_Status *status);
#pragma weak MPI_File_read_shared = PMPI_File_read_shared

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_read_shared(MPI_File fh, void *buf, int count,
                                       MPI_Datatype datatype,
                                       MPI_Status *status);

int INTERF_2_INTEL_MPI_File_read_shared(MPI_File fh, void *buf, int count,
                                        MPI_Datatype datatype,
                                        MPI_Status *status);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_read_shared)(MPI_File fh, void *buf, int count,
                                            MPI_Datatype datatype,
                                            MPI_Status *status);
int PMPI_File_read_shared(MPI_File fh, void *buf, int count,
                          MPI_Datatype datatype, MPI_Status *status) {
  return INTERFACE_LOCAL_MPI_File_read_shared(fh, buf, count, datatype, status);
}

int MPI_File_write_shared(MPI_File fh, void *buf, int count,
                          MPI_Datatype datatype, MPI_Status *status);
#pragma weak MPI_File_write_shared = PMPI_File_write_shared

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_write_shared(MPI_File fh, void *buf, int count,
                                        MPI_Datatype datatype,
                                        MPI_Status *status);

int INTERF_2_INTEL_MPI_File_write_shared(MPI_File fh, void *buf, int count,
                                         MPI_Datatype datatype,
                                         MPI_Status *status);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_write_shared)(MPI_File fh, void *buf, int count,
                                             MPI_Datatype datatype,
                                             MPI_Status *status);
int PMPI_File_write_shared(MPI_File fh, void *buf, int count,
                           MPI_Datatype datatype, MPI_Status *status) {
  return INTERFACE_LOCAL_MPI_File_write_shared(fh, buf, count, datatype,
                                               status);
}

int MPI_File_iread_shared(MPI_File fh, void *buf, int count,
                          MPI_Datatype datatype, MPI_Request *request);
#pragma weak MPI_File_iread_shared = PMPI_File_iread_shared

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_iread_shared(MPI_File fh, void *buf, int count,
                                        MPI_Datatype datatype,
                                        MPI_Request *request);

int INTERF_2_INTEL_MPI_File_iread_shared(MPI_File fh, void *buf, int count,
                                         MPI_Datatype datatype,
                                         MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_iread_shared)(MPI_File fh, void *buf, int count,
                                             MPI_Datatype datatype,
                                             MPI_Request *request);
int PMPI_File_iread_shared(MPI_File fh, void *buf, int count,
                           MPI_Datatype datatype, MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_File_iread_shared(fh, buf, count, datatype,
                                               request);
}

int MPI_File_iwrite_shared(MPI_File fh, void *buf, int count,
                           MPI_Datatype datatype, MPI_Request *request);
#pragma weak MPI_File_iwrite_shared = PMPI_File_iwrite_shared

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_iwrite_shared(MPI_File fh, void *buf, int count,
                                         MPI_Datatype datatype,
                                         MPI_Request *request);

int INTERF_2_INTEL_MPI_File_iwrite_shared(MPI_File fh, void *buf, int count,
                                          MPI_Datatype datatype,
                                          MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_iwrite_shared)(MPI_File fh, void *buf, int count,
                                              MPI_Datatype datatype,
                                              MPI_Request *request);
int PMPI_File_iwrite_shared(MPI_File fh, void *buf, int count,
                            MPI_Datatype datatype, MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_File_iwrite_shared(fh, buf, count, datatype,
                                                request);
}

int MPI_File_read_ordered(MPI_File fh, void *buf, int count,
                          MPI_Datatype datatype, MPI_Status *status);
#pragma weak MPI_File_read_ordered = PMPI_File_read_ordered

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_read_ordered(MPI_File fh, void *buf, int count,
                                        MPI_Datatype datatype,
                                        MPI_Status *status);

int INTERF_2_INTEL_MPI_File_read_ordered(MPI_File fh, void *buf, int count,
                                         MPI_Datatype datatype,
                                         MPI_Status *status);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_read_ordered)(MPI_File fh, void *buf, int count,
                                             MPI_Datatype datatype,
                                             MPI_Status *status);
int PMPI_File_read_ordered(MPI_File fh, void *buf, int count,
                           MPI_Datatype datatype, MPI_Status *status) {
  return INTERFACE_LOCAL_MPI_File_read_ordered(fh, buf, count, datatype,
                                               status);
}

int MPI_File_write_ordered(MPI_File fh, void *buf, int count,
                           MPI_Datatype datatype, MPI_Status *status);
#pragma weak MPI_File_write_ordered = PMPI_File_write_ordered

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_write_ordered(MPI_File fh, void *buf, int count,
                                         MPI_Datatype datatype,
                                         MPI_Status *status);

int INTERF_2_INTEL_MPI_File_write_ordered(MPI_File fh, void *buf, int count,
                                          MPI_Datatype datatype,
                                          MPI_Status *status);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_write_ordered)(MPI_File fh, void *buf, int count,
                                              MPI_Datatype datatype,
                                              MPI_Status *status);
int PMPI_File_write_ordered(MPI_File fh, void *buf, int count,
                            MPI_Datatype datatype, MPI_Status *status) {
  return INTERFACE_LOCAL_MPI_File_write_ordered(fh, buf, count, datatype,
                                                status);
}

int MPI_File_seek_shared(MPI_File fh, MPI_Offset offset, int whence);
#pragma weak MPI_File_seek_shared = PMPI_File_seek_shared

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_seek_shared(MPI_File fh, MPI_Offset offset,
                                       int whence);

int INTERF_2_INTEL_MPI_File_seek_shared(MPI_File fh, MPI_Offset offset,
                                        int whence);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_seek_shared)(MPI_File fh, MPI_Offset offset,
                                            int whence);
int PMPI_File_seek_shared(MPI_File fh, MPI_Offset offset, int whence) {
  return INTERFACE_LOCAL_MPI_File_seek_shared(fh, offset, whence);
}

int MPI_File_get_position_shared(MPI_File fh, MPI_Offset *offset);
#pragma weak MPI_File_get_position_shared = PMPI_File_get_position_shared

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_get_position_shared(MPI_File fh, MPI_Offset *offset);

int INTERF_2_INTEL_MPI_File_get_position_shared(MPI_File fh,
                                                MPI_Offset *offset);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_get_position_shared)(MPI_File fh,
                                                    MPI_Offset *offset);
int PMPI_File_get_position_shared(MPI_File fh, MPI_Offset *offset) {
  return INTERFACE_LOCAL_MPI_File_get_position_shared(fh, offset);
}

int MPI_File_read_at_all_begin(MPI_File fh, MPI_Offset offset, void *buf,
                               int count, MPI_Datatype datatype);
#pragma weak MPI_File_read_at_all_begin = PMPI_File_read_at_all_begin

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_read_at_all_begin(MPI_File fh, MPI_Offset offset,
                                             void *buf, int count,
                                             MPI_Datatype datatype);

int INTERF_2_INTEL_MPI_File_read_at_all_begin(MPI_File fh, MPI_Offset offset,
                                              void *buf, int count,
                                              MPI_Datatype datatype);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_read_at_all_begin)(MPI_File fh,
                                                  MPI_Offset offset, void *buf,
                                                  int count,
                                                  MPI_Datatype datatype);
int PMPI_File_read_at_all_begin(MPI_File fh, MPI_Offset offset, void *buf,
                                int count, MPI_Datatype datatype) {
  return INTERFACE_LOCAL_MPI_File_read_at_all_begin(fh, offset, buf, count,
                                                    datatype);
}

int MPI_File_read_at_all_end(MPI_File fh, void *buf, MPI_Status *status);
#pragma weak MPI_File_read_at_all_end = PMPI_File_read_at_all_end

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_read_at_all_end(MPI_File fh, void *buf,
                                           MPI_Status *status);

int INTERF_2_INTEL_MPI_File_read_at_all_end(MPI_File fh, void *buf,
                                            MPI_Status *status);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_read_at_all_end)(MPI_File fh, void *buf,
                                                MPI_Status *status);
int PMPI_File_read_at_all_end(MPI_File fh, void *buf, MPI_Status *status) {
  return INTERFACE_LOCAL_MPI_File_read_at_all_end(fh, buf, status);
}

int MPI_File_write_at_all_begin(MPI_File fh, MPI_Offset offset, void *buf,
                                int count, MPI_Datatype datatype);
#pragma weak MPI_File_write_at_all_begin = PMPI_File_write_at_all_begin

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_write_at_all_begin(MPI_File fh, MPI_Offset offset,
                                              void *buf, int count,
                                              MPI_Datatype datatype);

int INTERF_2_INTEL_MPI_File_write_at_all_begin(MPI_File fh, MPI_Offset offset,
                                               void *buf, int count,
                                               MPI_Datatype datatype);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_write_at_all_begin)(MPI_File fh,
                                                   MPI_Offset offset, void *buf,
                                                   int count,
                                                   MPI_Datatype datatype);
int PMPI_File_write_at_all_begin(MPI_File fh, MPI_Offset offset, void *buf,
                                 int count, MPI_Datatype datatype) {
  return INTERFACE_LOCAL_MPI_File_write_at_all_begin(fh, offset, buf, count,
                                                     datatype);
}

int MPI_File_write_at_all_end(MPI_File fh, void *buf, MPI_Status *status);
#pragma weak MPI_File_write_at_all_end = PMPI_File_write_at_all_end

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_write_at_all_end(MPI_File fh, void *buf,
                                            MPI_Status *status);

int INTERF_2_INTEL_MPI_File_write_at_all_end(MPI_File fh, void *buf,
                                             MPI_Status *status);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_write_at_all_end)(MPI_File fh, void *buf,
                                                 MPI_Status *status);
int PMPI_File_write_at_all_end(MPI_File fh, void *buf, MPI_Status *status) {
  return INTERFACE_LOCAL_MPI_File_write_at_all_end(fh, buf, status);
}

int MPI_File_read_all_begin(MPI_File fh, void *buf, int count,
                            MPI_Datatype datatype);
#pragma weak MPI_File_read_all_begin = PMPI_File_read_all_begin

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_read_all_begin(MPI_File fh, void *buf, int count,
                                          MPI_Datatype datatype);

int INTERF_2_INTEL_MPI_File_read_all_begin(MPI_File fh, void *buf, int count,
                                           MPI_Datatype datatype);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_read_all_begin)(MPI_File fh, void *buf,
                                               int count,
                                               MPI_Datatype datatype);
int PMPI_File_read_all_begin(MPI_File fh, void *buf, int count,
                             MPI_Datatype datatype) {
  return INTERFACE_LOCAL_MPI_File_read_all_begin(fh, buf, count, datatype);
}

int MPI_File_read_all_end(MPI_File fh, void *buf, MPI_Status *status);
#pragma weak MPI_File_read_all_end = PMPI_File_read_all_end

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_read_all_end(MPI_File fh, void *buf,
                                        MPI_Status *status);

int INTERF_2_INTEL_MPI_File_read_all_end(MPI_File fh, void *buf,
                                         MPI_Status *status);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_read_all_end)(MPI_File fh, void *buf,
                                             MPI_Status *status);
int PMPI_File_read_all_end(MPI_File fh, void *buf, MPI_Status *status) {
  return INTERFACE_LOCAL_MPI_File_read_all_end(fh, buf, status);
}

int MPI_File_write_all_begin(MPI_File fh, void *buf, int count,
                             MPI_Datatype datatype);
#pragma weak MPI_File_write_all_begin = PMPI_File_write_all_begin

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_write_all_begin(MPI_File fh, void *buf, int count,
                                           MPI_Datatype datatype);

int INTERF_2_INTEL_MPI_File_write_all_begin(MPI_File fh, void *buf, int count,
                                            MPI_Datatype datatype);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_write_all_begin)(MPI_File fh, void *buf,
                                                int count,
                                                MPI_Datatype datatype);
int PMPI_File_write_all_begin(MPI_File fh, void *buf, int count,
                              MPI_Datatype datatype) {
  return INTERFACE_LOCAL_MPI_File_write_all_begin(fh, buf, count, datatype);
}

int MPI_File_write_all_end(MPI_File fh, void *buf, MPI_Status *status);
#pragma weak MPI_File_write_all_end = PMPI_File_write_all_end

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_write_all_end(MPI_File fh, void *buf,
                                         MPI_Status *status);

int INTERF_2_INTEL_MPI_File_write_all_end(MPI_File fh, void *buf,
                                          MPI_Status *status);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_write_all_end)(MPI_File fh, void *buf,
                                              MPI_Status *status);
int PMPI_File_write_all_end(MPI_File fh, void *buf, MPI_Status *status) {
  return INTERFACE_LOCAL_MPI_File_write_all_end(fh, buf, status);
}

int MPI_File_read_ordered_begin(MPI_File fh, void *buf, int count,
                                MPI_Datatype datatype);
#pragma weak MPI_File_read_ordered_begin = PMPI_File_read_ordered_begin

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_read_ordered_begin(MPI_File fh, void *buf, int count,
                                              MPI_Datatype datatype);

int INTERF_2_INTEL_MPI_File_read_ordered_begin(MPI_File fh, void *buf,
                                               int count,
                                               MPI_Datatype datatype);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_read_ordered_begin)(MPI_File fh, void *buf,
                                                   int count,
                                                   MPI_Datatype datatype);
int PMPI_File_read_ordered_begin(MPI_File fh, void *buf, int count,
                                 MPI_Datatype datatype) {
  return INTERFACE_LOCAL_MPI_File_read_ordered_begin(fh, buf, count, datatype);
}

int MPI_File_read_ordered_end(MPI_File fh, void *buf, MPI_Status *status);
#pragma weak MPI_File_read_ordered_end = PMPI_File_read_ordered_end

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_read_ordered_end(MPI_File fh, void *buf,
                                            MPI_Status *status);

int INTERF_2_INTEL_MPI_File_read_ordered_end(MPI_File fh, void *buf,
                                             MPI_Status *status);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_read_ordered_end)(MPI_File fh, void *buf,
                                                 MPI_Status *status);
int PMPI_File_read_ordered_end(MPI_File fh, void *buf, MPI_Status *status) {
  return INTERFACE_LOCAL_MPI_File_read_ordered_end(fh, buf, status);
}

int MPI_File_write_ordered_begin(MPI_File fh, void *buf, int count,
                                 MPI_Datatype datatype);
#pragma weak MPI_File_write_ordered_begin = PMPI_File_write_ordered_begin

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_write_ordered_begin(MPI_File fh, void *buf,
                                               int count,
                                               MPI_Datatype datatype);

int INTERF_2_INTEL_MPI_File_write_ordered_begin(MPI_File fh, void *buf,
                                                int count,
                                                MPI_Datatype datatype);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_write_ordered_begin)(MPI_File fh, void *buf,
                                                    int count,
                                                    MPI_Datatype datatype);
int PMPI_File_write_ordered_begin(MPI_File fh, void *buf, int count,
                                  MPI_Datatype datatype) {
  return INTERFACE_LOCAL_MPI_File_write_ordered_begin(fh, buf, count, datatype);
}

int MPI_File_write_ordered_end(MPI_File fh, void *buf, MPI_Status *status);
#pragma weak MPI_File_write_ordered_end = PMPI_File_write_ordered_end

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_write_ordered_end(MPI_File fh, void *buf,
                                             MPI_Status *status);

int INTERF_2_INTEL_MPI_File_write_ordered_end(MPI_File fh, void *buf,
                                              MPI_Status *status);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_write_ordered_end)(MPI_File fh, void *buf,
                                                  MPI_Status *status);
int PMPI_File_write_ordered_end(MPI_File fh, void *buf, MPI_Status *status) {
  return INTERFACE_LOCAL_MPI_File_write_ordered_end(fh, buf, status);
}

int MPI_File_get_type_extent(MPI_File fh, MPI_Datatype datatype,
                             MPI_Aint *extent);
#pragma weak MPI_File_get_type_extent = PMPI_File_get_type_extent

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_get_type_extent(MPI_File fh, MPI_Datatype datatype,
                                           MPI_Aint *extent);

int INTERF_2_INTEL_MPI_File_get_type_extent(MPI_File fh, MPI_Datatype datatype,
                                            MPI_Aint *extent);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_get_type_extent)(MPI_File fh,
                                                MPI_Datatype datatype,
                                                MPI_Aint *extent);
int PMPI_File_get_type_extent(MPI_File fh, MPI_Datatype datatype,
                              MPI_Aint *extent) {
  return INTERFACE_LOCAL_MPI_File_get_type_extent(fh, datatype, extent);
}

int MPI_Register_datarep(char *datarep,
                         MPI_Datarep_conversion_function *read_conversion_fn,
                         MPI_Datarep_conversion_function *write_conversion_fn,
                         MPI_Datarep_extent_function *dtype_file_extent_fn,
                         void *extra_state);
#pragma weak MPI_Register_datarep = PMPI_Register_datarep

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Register_datarep(
    char *datarep, MPI_Datarep_conversion_function *read_conversion_fn,
    MPI_Datarep_conversion_function *write_conversion_fn,
    MPI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state);

int INTERF_2_INTEL_MPI_Register_datarep(
    char *datarep, MPI_Datarep_conversion_function *read_conversion_fn,
    MPI_Datarep_conversion_function *write_conversion_fn,
    MPI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Register_datarep)(
    char *datarep, MPI_Datarep_conversion_function *read_conversion_fn,
    MPI_Datarep_conversion_function *write_conversion_fn,
    MPI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state);
int PMPI_Register_datarep(char *datarep,
                          MPI_Datarep_conversion_function *read_conversion_fn,
                          MPI_Datarep_conversion_function *write_conversion_fn,
                          MPI_Datarep_extent_function *dtype_file_extent_fn,
                          void *extra_state) {
  return INTERFACE_LOCAL_MPI_Register_datarep(
      datarep, read_conversion_fn, write_conversion_fn, dtype_file_extent_fn,
      extra_state);
}

int MPI_File_set_atomicity(MPI_File fh, int flag);
#pragma weak MPI_File_set_atomicity = PMPI_File_set_atomicity

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_set_atomicity(MPI_File fh, int flag);

int INTERF_2_INTEL_MPI_File_set_atomicity(MPI_File fh, int flag);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_set_atomicity)(MPI_File fh, int flag);
int PMPI_File_set_atomicity(MPI_File fh, int flag) {
  return INTERFACE_LOCAL_MPI_File_set_atomicity(fh, flag);
}

int MPI_File_get_atomicity(MPI_File fh, int *flag);
#pragma weak MPI_File_get_atomicity = PMPI_File_get_atomicity

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_get_atomicity(MPI_File fh, int *flag);

int INTERF_2_INTEL_MPI_File_get_atomicity(MPI_File fh, int *flag);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_get_atomicity)(MPI_File fh, int *flag);
int PMPI_File_get_atomicity(MPI_File fh, int *flag) {
  return INTERFACE_LOCAL_MPI_File_get_atomicity(fh, flag);
}

int MPI_File_sync(MPI_File fh);
#pragma weak MPI_File_sync = PMPI_File_sync

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_sync(MPI_File fh);

int INTERF_2_INTEL_MPI_File_sync(MPI_File fh);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_sync)(MPI_File fh);
int PMPI_File_sync(MPI_File fh) { return INTERFACE_LOCAL_MPI_File_sync(fh); }

int MPI_T_finalize();
#pragma weak MPI_T_finalize = PMPI_T_finalize

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_T_finalize();

int INTERF_2_INTEL_MPI_T_finalize();

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_T_finalize)();
int PMPI_T_finalize() { return INTERFACE_LOCAL_MPI_T_finalize(); }

double MPI_Wtime();
#pragma weak MPI_Wtime = PMPI_Wtime

#ifdef WI4MPI_STATIC

double INTERF_2_OMPI_MPI_Wtime();

double INTERF_2_INTEL_MPI_Wtime();

#endif /* WI4MPI_STATIC */

double (*INTERFACE_LOCAL_MPI_Wtime)();
double PMPI_Wtime() { return INTERFACE_LOCAL_MPI_Wtime(); }

double MPI_Wtick();
#pragma weak MPI_Wtick = PMPI_Wtick

#ifdef WI4MPI_STATIC

double INTERF_2_OMPI_MPI_Wtick();

double INTERF_2_INTEL_MPI_Wtick();

#endif /* WI4MPI_STATIC */

double (*INTERFACE_LOCAL_MPI_Wtick)();
double PMPI_Wtick() { return INTERFACE_LOCAL_MPI_Wtick(); }

int MPI_Finalize();
#pragma weak MPI_Finalize = PMPI_Finalize

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Finalize();

int INTERF_2_INTEL_MPI_Finalize();

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Finalize)();
int PMPI_Finalize() { return INTERFACE_LOCAL_MPI_Finalize(); }

int MPI_Waitany(int count, MPI_Request array_of_requests[], int *indx,
                MPI_Status *status);
#pragma weak MPI_Waitany = PMPI_Waitany

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Waitany(int count, MPI_Request array_of_requests[],
                              int *indx, MPI_Status *status);

int INTERF_2_INTEL_MPI_Waitany(int count, MPI_Request array_of_requests[],
                               int *indx, MPI_Status *status);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Waitany)(int count, MPI_Request array_of_requests[],
                                   int *indx, MPI_Status *status);
int PMPI_Waitany(int count, MPI_Request array_of_requests[], int *indx,
                 MPI_Status *status) {
  return INTERFACE_LOCAL_MPI_Waitany(count, array_of_requests, indx, status);
}

int MPI_Testany(int count, MPI_Request array_of_requests[], int *indx,
                int *flag, MPI_Status *status);
#pragma weak MPI_Testany = PMPI_Testany

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Testany(int count, MPI_Request array_of_requests[],
                              int *indx, int *flag, MPI_Status *status);

int INTERF_2_INTEL_MPI_Testany(int count, MPI_Request array_of_requests[],
                               int *indx, int *flag, MPI_Status *status);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Testany)(int count, MPI_Request array_of_requests[],
                                   int *indx, int *flag, MPI_Status *status);
int PMPI_Testany(int count, MPI_Request array_of_requests[], int *indx,
                 int *flag, MPI_Status *status) {
  return INTERFACE_LOCAL_MPI_Testany(count, array_of_requests, indx, flag,
                                     status);
}

int MPI_Waitall(int count, MPI_Request array_of_requests[],
                MPI_Status array_of_statuses[]);
#pragma weak MPI_Waitall = PMPI_Waitall

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Waitall(int count, MPI_Request array_of_requests[],
                              MPI_Status array_of_statuses[]);

int INTERF_2_INTEL_MPI_Waitall(int count, MPI_Request array_of_requests[],
                               MPI_Status array_of_statuses[]);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Waitall)(int count, MPI_Request array_of_requests[],
                                   MPI_Status array_of_statuses[]);
int PMPI_Waitall(int count, MPI_Request array_of_requests[],
                 MPI_Status array_of_statuses[]) {
  return INTERFACE_LOCAL_MPI_Waitall(count, array_of_requests,
                                     array_of_statuses);
}

int MPI_Testall(int count, MPI_Request array_of_requests[], int *flag,
                MPI_Status array_of_statuses[]);
#pragma weak MPI_Testall = PMPI_Testall

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Testall(int count, MPI_Request array_of_requests[],
                              int *flag, MPI_Status array_of_statuses[]);

int INTERF_2_INTEL_MPI_Testall(int count, MPI_Request array_of_requests[],
                               int *flag, MPI_Status array_of_statuses[]);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Testall)(int count, MPI_Request array_of_requests[],
                                   int *flag, MPI_Status array_of_statuses[]);
int PMPI_Testall(int count, MPI_Request array_of_requests[], int *flag,
                 MPI_Status array_of_statuses[]) {
  return INTERFACE_LOCAL_MPI_Testall(count, array_of_requests, flag,
                                     array_of_statuses);
}

int MPI_Waitsome(int incount, MPI_Request array_of_requests[], int *outcount,
                 int array_of_indices[], MPI_Status array_of_statuses[]);
#pragma weak MPI_Waitsome = PMPI_Waitsome

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Waitsome(int incount, MPI_Request array_of_requests[],
                               int *outcount, int array_of_indices[],
                               MPI_Status array_of_statuses[]);

int INTERF_2_INTEL_MPI_Waitsome(int incount, MPI_Request array_of_requests[],
                                int *outcount, int array_of_indices[],
                                MPI_Status array_of_statuses[]);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Waitsome)(int incount,
                                    MPI_Request array_of_requests[],
                                    int *outcount, int array_of_indices[],
                                    MPI_Status array_of_statuses[]);
int PMPI_Waitsome(int incount, MPI_Request array_of_requests[], int *outcount,
                  int array_of_indices[], MPI_Status array_of_statuses[]) {
  return INTERFACE_LOCAL_MPI_Waitsome(incount, array_of_requests, outcount,
                                      array_of_indices, array_of_statuses);
}

int MPI_Testsome(int incount, MPI_Request array_of_requests[], int *outcount,
                 int array_of_indices[], MPI_Status array_of_statuses[]);
#pragma weak MPI_Testsome = PMPI_Testsome

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Testsome(int incount, MPI_Request array_of_requests[],
                               int *outcount, int array_of_indices[],
                               MPI_Status array_of_statuses[]);

int INTERF_2_INTEL_MPI_Testsome(int incount, MPI_Request array_of_requests[],
                                int *outcount, int array_of_indices[],
                                MPI_Status array_of_statuses[]);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Testsome)(int incount,
                                    MPI_Request array_of_requests[],
                                    int *outcount, int array_of_indices[],
                                    MPI_Status array_of_statuses[]);
int PMPI_Testsome(int incount, MPI_Request array_of_requests[], int *outcount,
                  int array_of_indices[], MPI_Status array_of_statuses[]) {
  return INTERFACE_LOCAL_MPI_Testsome(incount, array_of_requests, outcount,
                                      array_of_indices, array_of_statuses);
}

int MPI_Startall(int count, MPI_Request array_of_requests[]);
#pragma weak MPI_Startall = PMPI_Startall

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Startall(int count, MPI_Request array_of_requests[]);

int INTERF_2_INTEL_MPI_Startall(int count, MPI_Request array_of_requests[]);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Startall)(int count, MPI_Request array_of_requests[]);
int PMPI_Startall(int count, MPI_Request array_of_requests[]) {
  return INTERFACE_LOCAL_MPI_Startall(count, array_of_requests);
}

int MPI_Alltoallw(void *sendbuf, int sendcounts[], int sdispls[],
                  MPI_Datatype sendtypes[], void *recvbuf, int recvcounts[],
                  int rdispls[], MPI_Datatype recvtypes[], MPI_Comm comm);
#pragma weak MPI_Alltoallw = PMPI_Alltoallw

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Alltoallw(void *sendbuf, int sendcounts[], int sdispls[],
                                MPI_Datatype sendtypes[], void *recvbuf,
                                int recvcounts[], int rdispls[],
                                MPI_Datatype recvtypes[], MPI_Comm comm);

int INTERF_2_INTEL_MPI_Alltoallw(void *sendbuf, int sendcounts[], int sdispls[],
                                 MPI_Datatype sendtypes[], void *recvbuf,
                                 int recvcounts[], int rdispls[],
                                 MPI_Datatype recvtypes[], MPI_Comm comm);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Alltoallw)(void *sendbuf, int sendcounts[],
                                     int sdispls[], MPI_Datatype sendtypes[],
                                     void *recvbuf, int recvcounts[],
                                     int rdispls[], MPI_Datatype recvtypes[],
                                     MPI_Comm comm);
int PMPI_Alltoallw(void *sendbuf, int sendcounts[], int sdispls[],
                   MPI_Datatype sendtypes[], void *recvbuf, int recvcounts[],
                   int rdispls[], MPI_Datatype recvtypes[], MPI_Comm comm) {
  return INTERFACE_LOCAL_MPI_Alltoallw(sendbuf, sendcounts, sdispls, sendtypes,
                                       recvbuf, recvcounts, rdispls, recvtypes,
                                       comm);
}

int MPI_Reduce_scatter(void *sendbuf, void *recvbuf, int recvcounts[],
                       MPI_Datatype datatype, MPI_Op op, MPI_Comm comm);
#pragma weak MPI_Reduce_scatter = PMPI_Reduce_scatter

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Reduce_scatter(void *sendbuf, void *recvbuf,
                                     int recvcounts[], MPI_Datatype datatype,
                                     MPI_Op op, MPI_Comm comm);

int INTERF_2_INTEL_MPI_Reduce_scatter(void *sendbuf, void *recvbuf,
                                      int recvcounts[], MPI_Datatype datatype,
                                      MPI_Op op, MPI_Comm comm);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Reduce_scatter)(void *sendbuf, void *recvbuf,
                                          int recvcounts[],
                                          MPI_Datatype datatype, MPI_Op op,
                                          MPI_Comm comm);
int PMPI_Reduce_scatter(void *sendbuf, void *recvbuf, int recvcounts[],
                        MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) {
  return INTERFACE_LOCAL_MPI_Reduce_scatter(sendbuf, recvbuf, recvcounts,
                                            datatype, op, comm);
}

int MPI_Group_translate_ranks(MPI_Group group1, int n, int ranks1[],
                              MPI_Group group2, int ranks2[]);
#pragma weak MPI_Group_translate_ranks = PMPI_Group_translate_ranks

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Group_translate_ranks(MPI_Group group1, int n,
                                            int ranks1[], MPI_Group group2,
                                            int ranks2[]);

int INTERF_2_INTEL_MPI_Group_translate_ranks(MPI_Group group1, int n,
                                             int ranks1[], MPI_Group group2,
                                             int ranks2[]);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Group_translate_ranks)(MPI_Group group1, int n,
                                                 int ranks1[], MPI_Group group2,
                                                 int ranks2[]);
int PMPI_Group_translate_ranks(MPI_Group group1, int n, int ranks1[],
                               MPI_Group group2, int ranks2[]) {
  return INTERFACE_LOCAL_MPI_Group_translate_ranks(group1, n, ranks1, group2,
                                                   ranks2);
}

int MPI_Group_incl(MPI_Group group, int n, int ranks[], MPI_Group *newgroup);
#pragma weak MPI_Group_incl = PMPI_Group_incl

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Group_incl(MPI_Group group, int n, int ranks[],
                                 MPI_Group *newgroup);

int INTERF_2_INTEL_MPI_Group_incl(MPI_Group group, int n, int ranks[],
                                  MPI_Group *newgroup);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Group_incl)(MPI_Group group, int n, int ranks[],
                                      MPI_Group *newgroup);
int PMPI_Group_incl(MPI_Group group, int n, int ranks[], MPI_Group *newgroup) {
  return INTERFACE_LOCAL_MPI_Group_incl(group, n, ranks, newgroup);
}

int MPI_Group_excl(MPI_Group group, int n, int ranks[], MPI_Group *newgroup);
#pragma weak MPI_Group_excl = PMPI_Group_excl

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Group_excl(MPI_Group group, int n, int ranks[],
                                 MPI_Group *newgroup);

int INTERF_2_INTEL_MPI_Group_excl(MPI_Group group, int n, int ranks[],
                                  MPI_Group *newgroup);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Group_excl)(MPI_Group group, int n, int ranks[],
                                      MPI_Group *newgroup);
int PMPI_Group_excl(MPI_Group group, int n, int ranks[], MPI_Group *newgroup) {
  return INTERFACE_LOCAL_MPI_Group_excl(group, n, ranks, newgroup);
}

int MPI_Group_range_incl(MPI_Group group, int n, int ranges[][3],
                         MPI_Group *newgroup);
#pragma weak MPI_Group_range_incl = PMPI_Group_range_incl

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Group_range_incl(MPI_Group group, int n, int ranges[][3],
                                       MPI_Group *newgroup);

int INTERF_2_INTEL_MPI_Group_range_incl(MPI_Group group, int n, int ranges[][3],
                                        MPI_Group *newgroup);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Group_range_incl)(MPI_Group group, int n,
                                            int ranges[][3],
                                            MPI_Group *newgroup);
int PMPI_Group_range_incl(MPI_Group group, int n, int ranges[][3],
                          MPI_Group *newgroup) {
  return INTERFACE_LOCAL_MPI_Group_range_incl(group, n, ranges, newgroup);
}

int MPI_Group_range_excl(MPI_Group group, int n, int ranges[][3],
                         MPI_Group *newgroup);
#pragma weak MPI_Group_range_excl = PMPI_Group_range_excl

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Group_range_excl(MPI_Group group, int n, int ranges[][3],
                                       MPI_Group *newgroup);

int INTERF_2_INTEL_MPI_Group_range_excl(MPI_Group group, int n, int ranges[][3],
                                        MPI_Group *newgroup);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Group_range_excl)(MPI_Group group, int n,
                                            int ranges[][3],
                                            MPI_Group *newgroup);
int PMPI_Group_range_excl(MPI_Group group, int n, int ranges[][3],
                          MPI_Group *newgroup) {
  return INTERFACE_LOCAL_MPI_Group_range_excl(group, n, ranges, newgroup);
}

int MPI_Cart_create(MPI_Comm comm_old, int ndims, int dims[], int periods[],
                    int reorder, MPI_Comm *comm_cart);
#pragma weak MPI_Cart_create = PMPI_Cart_create

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Cart_create(MPI_Comm comm_old, int ndims, int dims[],
                                  int periods[], int reorder,
                                  MPI_Comm *comm_cart);

int INTERF_2_INTEL_MPI_Cart_create(MPI_Comm comm_old, int ndims, int dims[],
                                   int periods[], int reorder,
                                   MPI_Comm *comm_cart);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Cart_create)(MPI_Comm comm_old, int ndims, int dims[],
                                       int periods[], int reorder,
                                       MPI_Comm *comm_cart);
int PMPI_Cart_create(MPI_Comm comm_old, int ndims, int dims[], int periods[],
                     int reorder, MPI_Comm *comm_cart) {
  return INTERFACE_LOCAL_MPI_Cart_create(comm_old, ndims, dims, periods,
                                         reorder, comm_cart);
}

int MPI_Dims_create(int nnodes, int ndims, int dims[]);
#pragma weak MPI_Dims_create = PMPI_Dims_create

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Dims_create(int nnodes, int ndims, int dims[]);

int INTERF_2_INTEL_MPI_Dims_create(int nnodes, int ndims, int dims[]);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Dims_create)(int nnodes, int ndims, int dims[]);
int PMPI_Dims_create(int nnodes, int ndims, int dims[]) {
  return INTERFACE_LOCAL_MPI_Dims_create(nnodes, ndims, dims);
}

int MPI_Graph_create(MPI_Comm comm_old, int nnodes, int indx[], int edges[],
                     int reorder, MPI_Comm *comm_graph);
#pragma weak MPI_Graph_create = PMPI_Graph_create

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Graph_create(MPI_Comm comm_old, int nnodes, int indx[],
                                   int edges[], int reorder,
                                   MPI_Comm *comm_graph);

int INTERF_2_INTEL_MPI_Graph_create(MPI_Comm comm_old, int nnodes, int indx[],
                                    int edges[], int reorder,
                                    MPI_Comm *comm_graph);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Graph_create)(MPI_Comm comm_old, int nnodes,
                                        int indx[], int edges[], int reorder,
                                        MPI_Comm *comm_graph);
int PMPI_Graph_create(MPI_Comm comm_old, int nnodes, int indx[], int edges[],
                      int reorder, MPI_Comm *comm_graph) {
  return INTERFACE_LOCAL_MPI_Graph_create(comm_old, nnodes, indx, edges,
                                          reorder, comm_graph);
}

int MPI_Graph_get(MPI_Comm comm, int maxindex, int maxedges, int indx[],
                  int edges[]);
#pragma weak MPI_Graph_get = PMPI_Graph_get

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Graph_get(MPI_Comm comm, int maxindex, int maxedges,
                                int indx[], int edges[]);

int INTERF_2_INTEL_MPI_Graph_get(MPI_Comm comm, int maxindex, int maxedges,
                                 int indx[], int edges[]);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Graph_get)(MPI_Comm comm, int maxindex, int maxedges,
                                     int indx[], int edges[]);
int PMPI_Graph_get(MPI_Comm comm, int maxindex, int maxedges, int indx[],
                   int edges[]) {
  return INTERFACE_LOCAL_MPI_Graph_get(comm, maxindex, maxedges, indx, edges);
}

int MPI_Cart_get(MPI_Comm comm, int maxdims, int dims[], int periods[],
                 int coords[]);
#pragma weak MPI_Cart_get = PMPI_Cart_get

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Cart_get(MPI_Comm comm, int maxdims, int dims[],
                               int periods[], int coords[]);

int INTERF_2_INTEL_MPI_Cart_get(MPI_Comm comm, int maxdims, int dims[],
                                int periods[], int coords[]);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Cart_get)(MPI_Comm comm, int maxdims, int dims[],
                                    int periods[], int coords[]);
int PMPI_Cart_get(MPI_Comm comm, int maxdims, int dims[], int periods[],
                  int coords[]) {
  return INTERFACE_LOCAL_MPI_Cart_get(comm, maxdims, dims, periods, coords);
}

int MPI_Cart_rank(MPI_Comm comm, int coords[], int *rank);
#pragma weak MPI_Cart_rank = PMPI_Cart_rank

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Cart_rank(MPI_Comm comm, int coords[], int *rank);

int INTERF_2_INTEL_MPI_Cart_rank(MPI_Comm comm, int coords[], int *rank);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Cart_rank)(MPI_Comm comm, int coords[], int *rank);
int PMPI_Cart_rank(MPI_Comm comm, int coords[], int *rank) {
  return INTERFACE_LOCAL_MPI_Cart_rank(comm, coords, rank);
}

int MPI_Cart_coords(MPI_Comm comm, int rank, int maxdims, int coords[]);
#pragma weak MPI_Cart_coords = PMPI_Cart_coords

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Cart_coords(MPI_Comm comm, int rank, int maxdims,
                                  int coords[]);

int INTERF_2_INTEL_MPI_Cart_coords(MPI_Comm comm, int rank, int maxdims,
                                   int coords[]);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Cart_coords)(MPI_Comm comm, int rank, int maxdims,
                                       int coords[]);
int PMPI_Cart_coords(MPI_Comm comm, int rank, int maxdims, int coords[]) {
  return INTERFACE_LOCAL_MPI_Cart_coords(comm, rank, maxdims, coords);
}

int MPI_Graph_neighbors(MPI_Comm comm, int rank, int maxneighbors,
                        int neighbors[]);
#pragma weak MPI_Graph_neighbors = PMPI_Graph_neighbors

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Graph_neighbors(MPI_Comm comm, int rank, int maxneighbors,
                                      int neighbors[]);

int INTERF_2_INTEL_MPI_Graph_neighbors(MPI_Comm comm, int rank,
                                       int maxneighbors, int neighbors[]);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Graph_neighbors)(MPI_Comm comm, int rank,
                                           int maxneighbors, int neighbors[]);
int PMPI_Graph_neighbors(MPI_Comm comm, int rank, int maxneighbors,
                         int neighbors[]) {
  return INTERFACE_LOCAL_MPI_Graph_neighbors(comm, rank, maxneighbors,
                                             neighbors);
}

int MPI_Cart_sub(MPI_Comm comm, int remain_dims[], MPI_Comm *newcomm);
#pragma weak MPI_Cart_sub = PMPI_Cart_sub

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Cart_sub(MPI_Comm comm, int remain_dims[],
                               MPI_Comm *newcomm);

int INTERF_2_INTEL_MPI_Cart_sub(MPI_Comm comm, int remain_dims[],
                                MPI_Comm *newcomm);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Cart_sub)(MPI_Comm comm, int remain_dims[],
                                    MPI_Comm *newcomm);
int PMPI_Cart_sub(MPI_Comm comm, int remain_dims[], MPI_Comm *newcomm) {
  return INTERFACE_LOCAL_MPI_Cart_sub(comm, remain_dims, newcomm);
}

int MPI_Cart_map(MPI_Comm comm, int ndims, int dims[], int periods[],
                 int *newrank);
#pragma weak MPI_Cart_map = PMPI_Cart_map

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Cart_map(MPI_Comm comm, int ndims, int dims[],
                               int periods[], int *newrank);

int INTERF_2_INTEL_MPI_Cart_map(MPI_Comm comm, int ndims, int dims[],
                                int periods[], int *newrank);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Cart_map)(MPI_Comm comm, int ndims, int dims[],
                                    int periods[], int *newrank);
int PMPI_Cart_map(MPI_Comm comm, int ndims, int dims[], int periods[],
                  int *newrank) {
  return INTERFACE_LOCAL_MPI_Cart_map(comm, ndims, dims, periods, newrank);
}

int MPI_Graph_map(MPI_Comm comm, int nnodes, int indx[], int edges[],
                  int *newrank);
#pragma weak MPI_Graph_map = PMPI_Graph_map

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Graph_map(MPI_Comm comm, int nnodes, int indx[],
                                int edges[], int *newrank);

int INTERF_2_INTEL_MPI_Graph_map(MPI_Comm comm, int nnodes, int indx[],
                                 int edges[], int *newrank);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Graph_map)(MPI_Comm comm, int nnodes, int indx[],
                                     int edges[], int *newrank);
int PMPI_Graph_map(MPI_Comm comm, int nnodes, int indx[], int edges[],
                   int *newrank) {
  return INTERFACE_LOCAL_MPI_Graph_map(comm, nnodes, indx, edges, newrank);
}

int MPI_Comm_spawn(char *command, char *argv[], int maxprocs, MPI_Info info,
                   int root, MPI_Comm comm, MPI_Comm *intercomm,
                   int array_of_errcodes[]);
#pragma weak MPI_Comm_spawn = PMPI_Comm_spawn

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Comm_spawn(char *command, char *argv[], int maxprocs,
                                 MPI_Info info, int root, MPI_Comm comm,
                                 MPI_Comm *intercomm, int array_of_errcodes[]);

int INTERF_2_INTEL_MPI_Comm_spawn(char *command, char *argv[], int maxprocs,
                                  MPI_Info info, int root, MPI_Comm comm,
                                  MPI_Comm *intercomm, int array_of_errcodes[]);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Comm_spawn)(char *command, char *argv[], int maxprocs,
                                      MPI_Info info, int root, MPI_Comm comm,
                                      MPI_Comm *intercomm,
                                      int array_of_errcodes[]);
int PMPI_Comm_spawn(char *command, char *argv[], int maxprocs, MPI_Info info,
                    int root, MPI_Comm comm, MPI_Comm *intercomm,
                    int array_of_errcodes[]) {
  return INTERFACE_LOCAL_MPI_Comm_spawn(command, argv, maxprocs, info, root,
                                        comm, intercomm, array_of_errcodes);
}

int MPI_Comm_spawn_multiple(int count, char *array_of_commands[],
                            char **array_of_argv[], int array_of_maxprocs[],
                            MPI_Info array_of_info[], int root, MPI_Comm comm,
                            MPI_Comm *intercomm, int array_of_errcodes[]);
#pragma weak MPI_Comm_spawn_multiple = PMPI_Comm_spawn_multiple

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Comm_spawn_multiple(int count, char *array_of_commands[],
                                          char **array_of_argv[],
                                          int array_of_maxprocs[],
                                          MPI_Info array_of_info[], int root,
                                          MPI_Comm comm, MPI_Comm *intercomm,
                                          int array_of_errcodes[]);

int INTERF_2_INTEL_MPI_Comm_spawn_multiple(int count, char *array_of_commands[],
                                           char **array_of_argv[],
                                           int array_of_maxprocs[],
                                           MPI_Info array_of_info[], int root,
                                           MPI_Comm comm, MPI_Comm *intercomm,
                                           int array_of_errcodes[]);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Comm_spawn_multiple)(
    int count, char *array_of_commands[], char **array_of_argv[],
    int array_of_maxprocs[], MPI_Info array_of_info[], int root, MPI_Comm comm,
    MPI_Comm *intercomm, int array_of_errcodes[]);
int PMPI_Comm_spawn_multiple(int count, char *array_of_commands[],
                             char **array_of_argv[], int array_of_maxprocs[],
                             MPI_Info array_of_info[], int root, MPI_Comm comm,
                             MPI_Comm *intercomm, int array_of_errcodes[]) {
  return INTERFACE_LOCAL_MPI_Comm_spawn_multiple(
      count, array_of_commands, array_of_argv, array_of_maxprocs, array_of_info,
      root, comm, intercomm, array_of_errcodes);
}

int MPI_Type_get_contents(MPI_Datatype datatype, int max_integers,
                          int max_addresses, int max_datatypes,
                          int array_of_integers[],
                          MPI_Aint array_of_addresses[],
                          MPI_Datatype array_of_datatypes[]);
#pragma weak MPI_Type_get_contents = PMPI_Type_get_contents

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Type_get_contents(MPI_Datatype datatype, int max_integers,
                                        int max_addresses, int max_datatypes,
                                        int array_of_integers[],
                                        MPI_Aint array_of_addresses[],
                                        MPI_Datatype array_of_datatypes[]);

int INTERF_2_INTEL_MPI_Type_get_contents(MPI_Datatype datatype,
                                         int max_integers, int max_addresses,
                                         int max_datatypes,
                                         int array_of_integers[],
                                         MPI_Aint array_of_addresses[],
                                         MPI_Datatype array_of_datatypes[]);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Type_get_contents)(
    MPI_Datatype datatype, int max_integers, int max_addresses,
    int max_datatypes, int array_of_integers[], MPI_Aint array_of_addresses[],
    MPI_Datatype array_of_datatypes[]);
int PMPI_Type_get_contents(MPI_Datatype datatype, int max_integers,
                           int max_addresses, int max_datatypes,
                           int array_of_integers[],
                           MPI_Aint array_of_addresses[],
                           MPI_Datatype array_of_datatypes[]) {
  return INTERFACE_LOCAL_MPI_Type_get_contents(
      datatype, max_integers, max_addresses, max_datatypes, array_of_integers,
      array_of_addresses, array_of_datatypes);
}

int MPI_Pack_external(char datarep[], void *inbuf, int incount,
                      MPI_Datatype datatype, void *outbuf, MPI_Aint outsize,
                      MPI_Aint *position);
#pragma weak MPI_Pack_external = PMPI_Pack_external

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Pack_external(char datarep[], void *inbuf, int incount,
                                    MPI_Datatype datatype, void *outbuf,
                                    MPI_Aint outsize, MPI_Aint *position);

int INTERF_2_INTEL_MPI_Pack_external(char datarep[], void *inbuf, int incount,
                                     MPI_Datatype datatype, void *outbuf,
                                     MPI_Aint outsize, MPI_Aint *position);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Pack_external)(char datarep[], void *inbuf,
                                         int incount, MPI_Datatype datatype,
                                         void *outbuf, MPI_Aint outsize,
                                         MPI_Aint *position);
int PMPI_Pack_external(char datarep[], void *inbuf, int incount,
                       MPI_Datatype datatype, void *outbuf, MPI_Aint outsize,
                       MPI_Aint *position) {
  return INTERFACE_LOCAL_MPI_Pack_external(datarep, inbuf, incount, datatype,
                                           outbuf, outsize, position);
}

int MPI_Pack_external_size(char datarep[], int incount, MPI_Datatype datatype,
                           MPI_Aint *size);
#pragma weak MPI_Pack_external_size = PMPI_Pack_external_size

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Pack_external_size(char datarep[], int incount,
                                         MPI_Datatype datatype, MPI_Aint *size);

int INTERF_2_INTEL_MPI_Pack_external_size(char datarep[], int incount,
                                          MPI_Datatype datatype,
                                          MPI_Aint *size);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Pack_external_size)(char datarep[], int incount,
                                              MPI_Datatype datatype,
                                              MPI_Aint *size);
int PMPI_Pack_external_size(char datarep[], int incount, MPI_Datatype datatype,
                            MPI_Aint *size) {
  return INTERFACE_LOCAL_MPI_Pack_external_size(datarep, incount, datatype,
                                                size);
}

int MPI_Type_create_darray(int size, int rank, int ndims, int array_of_gsizes[],
                           int array_of_distribs[], int array_of_dargs[],
                           int array_of_psizes[], int order,
                           MPI_Datatype oldtype, MPI_Datatype *newtype);
#pragma weak MPI_Type_create_darray = PMPI_Type_create_darray

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Type_create_darray(
    int size, int rank, int ndims, int array_of_gsizes[],
    int array_of_distribs[], int array_of_dargs[], int array_of_psizes[],
    int order, MPI_Datatype oldtype, MPI_Datatype *newtype);

int INTERF_2_INTEL_MPI_Type_create_darray(
    int size, int rank, int ndims, int array_of_gsizes[],
    int array_of_distribs[], int array_of_dargs[], int array_of_psizes[],
    int order, MPI_Datatype oldtype, MPI_Datatype *newtype);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Type_create_darray)(
    int size, int rank, int ndims, int array_of_gsizes[],
    int array_of_distribs[], int array_of_dargs[], int array_of_psizes[],
    int order, MPI_Datatype oldtype, MPI_Datatype *newtype);
int PMPI_Type_create_darray(int size, int rank, int ndims,
                            int array_of_gsizes[], int array_of_distribs[],
                            int array_of_dargs[], int array_of_psizes[],
                            int order, MPI_Datatype oldtype,
                            MPI_Datatype *newtype) {
  return INTERFACE_LOCAL_MPI_Type_create_darray(
      size, rank, ndims, array_of_gsizes, array_of_distribs, array_of_dargs,
      array_of_psizes, order, oldtype, newtype);
}

int MPI_Type_create_hindexed(int count, int array_of_blocklengths[],
                             MPI_Aint array_of_displacements[],
                             MPI_Datatype oldtype, MPI_Datatype *newtype);
#pragma weak MPI_Type_create_hindexed = PMPI_Type_create_hindexed

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Type_create_hindexed(int count,
                                           int array_of_blocklengths[],
                                           MPI_Aint array_of_displacements[],
                                           MPI_Datatype oldtype,
                                           MPI_Datatype *newtype);

int INTERF_2_INTEL_MPI_Type_create_hindexed(int count,
                                            int array_of_blocklengths[],
                                            MPI_Aint array_of_displacements[],
                                            MPI_Datatype oldtype,
                                            MPI_Datatype *newtype);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Type_create_hindexed)(
    int count, int array_of_blocklengths[], MPI_Aint array_of_displacements[],
    MPI_Datatype oldtype, MPI_Datatype *newtype);
int PMPI_Type_create_hindexed(int count, int array_of_blocklengths[],
                              MPI_Aint array_of_displacements[],
                              MPI_Datatype oldtype, MPI_Datatype *newtype) {
  return INTERFACE_LOCAL_MPI_Type_create_hindexed(
      count, array_of_blocklengths, array_of_displacements, oldtype, newtype);
}

int MPI_Type_create_indexed_block(int count, int blocklength,
                                  int array_of_displacements[],
                                  MPI_Datatype oldtype, MPI_Datatype *newtype);
#pragma weak MPI_Type_create_indexed_block = PMPI_Type_create_indexed_block

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Type_create_indexed_block(int count, int blocklength,
                                                int array_of_displacements[],
                                                MPI_Datatype oldtype,
                                                MPI_Datatype *newtype);

int INTERF_2_INTEL_MPI_Type_create_indexed_block(int count, int blocklength,
                                                 int array_of_displacements[],
                                                 MPI_Datatype oldtype,
                                                 MPI_Datatype *newtype);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Type_create_indexed_block)(
    int count, int blocklength, int array_of_displacements[],
    MPI_Datatype oldtype, MPI_Datatype *newtype);
int PMPI_Type_create_indexed_block(int count, int blocklength,
                                   int array_of_displacements[],
                                   MPI_Datatype oldtype,
                                   MPI_Datatype *newtype) {
  return INTERFACE_LOCAL_MPI_Type_create_indexed_block(
      count, blocklength, array_of_displacements, oldtype, newtype);
}

int MPI_Type_create_hindexed_block(int count, int blocklength,
                                   MPI_Aint array_of_displacements[],
                                   MPI_Datatype oldtype, MPI_Datatype *newtype);
#pragma weak MPI_Type_create_hindexed_block = PMPI_Type_create_hindexed_block

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Type_create_hindexed_block(
    int count, int blocklength, MPI_Aint array_of_displacements[],
    MPI_Datatype oldtype, MPI_Datatype *newtype);

int INTERF_2_INTEL_MPI_Type_create_hindexed_block(
    int count, int blocklength, MPI_Aint array_of_displacements[],
    MPI_Datatype oldtype, MPI_Datatype *newtype);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Type_create_hindexed_block)(
    int count, int blocklength, MPI_Aint array_of_displacements[],
    MPI_Datatype oldtype, MPI_Datatype *newtype);
int PMPI_Type_create_hindexed_block(int count, int blocklength,
                                    MPI_Aint array_of_displacements[],
                                    MPI_Datatype oldtype,
                                    MPI_Datatype *newtype) {
  return INTERFACE_LOCAL_MPI_Type_create_hindexed_block(
      count, blocklength, array_of_displacements, oldtype, newtype);
}

int MPI_Type_create_struct(int count, int array_of_blocklengths[],
                           MPI_Aint array_of_displacements[],
                           MPI_Datatype array_of_types[],
                           MPI_Datatype *newtype);
#pragma weak MPI_Type_create_struct = PMPI_Type_create_struct

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Type_create_struct(int count, int array_of_blocklengths[],
                                         MPI_Aint array_of_displacements[],
                                         MPI_Datatype array_of_types[],
                                         MPI_Datatype *newtype);

int INTERF_2_INTEL_MPI_Type_create_struct(int count,
                                          int array_of_blocklengths[],
                                          MPI_Aint array_of_displacements[],
                                          MPI_Datatype array_of_types[],
                                          MPI_Datatype *newtype);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Type_create_struct)(int count,
                                              int array_of_blocklengths[],
                                              MPI_Aint array_of_displacements[],
                                              MPI_Datatype array_of_types[],
                                              MPI_Datatype *newtype);
int PMPI_Type_create_struct(int count, int array_of_blocklengths[],
                            MPI_Aint array_of_displacements[],
                            MPI_Datatype array_of_types[],
                            MPI_Datatype *newtype) {
  return INTERFACE_LOCAL_MPI_Type_create_struct(count, array_of_blocklengths,
                                                array_of_displacements,
                                                array_of_types, newtype);
}

int MPI_Type_create_subarray(int ndims, int array_of_sizes[],
                             int array_of_subsizes[], int array_of_starts[],
                             int order, MPI_Datatype oldtype,
                             MPI_Datatype *newtype);
#pragma weak MPI_Type_create_subarray = PMPI_Type_create_subarray

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Type_create_subarray(int ndims, int array_of_sizes[],
                                           int array_of_subsizes[],
                                           int array_of_starts[], int order,
                                           MPI_Datatype oldtype,
                                           MPI_Datatype *newtype);

int INTERF_2_INTEL_MPI_Type_create_subarray(int ndims, int array_of_sizes[],
                                            int array_of_subsizes[],
                                            int array_of_starts[], int order,
                                            MPI_Datatype oldtype,
                                            MPI_Datatype *newtype);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Type_create_subarray)(int ndims, int array_of_sizes[],
                                                int array_of_subsizes[],
                                                int array_of_starts[],
                                                int order, MPI_Datatype oldtype,
                                                MPI_Datatype *newtype);
int PMPI_Type_create_subarray(int ndims, int array_of_sizes[],
                              int array_of_subsizes[], int array_of_starts[],
                              int order, MPI_Datatype oldtype,
                              MPI_Datatype *newtype) {
  return INTERFACE_LOCAL_MPI_Type_create_subarray(
      ndims, array_of_sizes, array_of_subsizes, array_of_starts, order, oldtype,
      newtype);
}

int MPI_Unpack_external(char datarep[], void *inbuf, MPI_Aint insize,
                        MPI_Aint *position, void *outbuf, int outcount,
                        MPI_Datatype datatype);
#pragma weak MPI_Unpack_external = PMPI_Unpack_external

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Unpack_external(char datarep[], void *inbuf,
                                      MPI_Aint insize, MPI_Aint *position,
                                      void *outbuf, int outcount,
                                      MPI_Datatype datatype);

int INTERF_2_INTEL_MPI_Unpack_external(char datarep[], void *inbuf,
                                       MPI_Aint insize, MPI_Aint *position,
                                       void *outbuf, int outcount,
                                       MPI_Datatype datatype);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Unpack_external)(char datarep[], void *inbuf,
                                           MPI_Aint insize, MPI_Aint *position,
                                           void *outbuf, int outcount,
                                           MPI_Datatype datatype);
int PMPI_Unpack_external(char datarep[], void *inbuf, MPI_Aint insize,
                         MPI_Aint *position, void *outbuf, int outcount,
                         MPI_Datatype datatype) {
  return INTERFACE_LOCAL_MPI_Unpack_external(datarep, inbuf, insize, position,
                                             outbuf, outcount, datatype);
}

int MPI_Dist_graph_create_adjacent(MPI_Comm comm_old, int indegree,
                                   int sources[], int *sourceweights,
                                   int outdegree, int destinations[],
                                   int *destweights, MPI_Info info, int reorder,
                                   MPI_Comm *comm_dist_graph);
#pragma weak MPI_Dist_graph_create_adjacent = PMPI_Dist_graph_create_adjacent

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Dist_graph_create_adjacent(
    MPI_Comm comm_old, int indegree, int sources[], int *sourceweights,
    int outdegree, int destinations[], int *destweights, MPI_Info info,
    int reorder, MPI_Comm *comm_dist_graph);

int INTERF_2_INTEL_MPI_Dist_graph_create_adjacent(
    MPI_Comm comm_old, int indegree, int sources[], int *sourceweights,
    int outdegree, int destinations[], int *destweights, MPI_Info info,
    int reorder, MPI_Comm *comm_dist_graph);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Dist_graph_create_adjacent)(
    MPI_Comm comm_old, int indegree, int sources[], int *sourceweights,
    int outdegree, int destinations[], int *destweights, MPI_Info info,
    int reorder, MPI_Comm *comm_dist_graph);
int PMPI_Dist_graph_create_adjacent(MPI_Comm comm_old, int indegree,
                                    int sources[], int *sourceweights,
                                    int outdegree, int destinations[],
                                    int *destweights, MPI_Info info,
                                    int reorder, MPI_Comm *comm_dist_graph) {
  return INTERFACE_LOCAL_MPI_Dist_graph_create_adjacent(
      comm_old, indegree, sources, sourceweights, outdegree, destinations,
      destweights, info, reorder, comm_dist_graph);
}

int MPI_Dist_graph_create(MPI_Comm comm_old, int n, int sources[],
                          int degrees[], int destinations[], int *weights,
                          MPI_Info info, int reorder,
                          MPI_Comm *comm_dist_graph);
#pragma weak MPI_Dist_graph_create = PMPI_Dist_graph_create

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Dist_graph_create(MPI_Comm comm_old, int n, int sources[],
                                        int degrees[], int destinations[],
                                        int *weights, MPI_Info info,
                                        int reorder, MPI_Comm *comm_dist_graph);

int INTERF_2_INTEL_MPI_Dist_graph_create(MPI_Comm comm_old, int n,
                                         int sources[], int degrees[],
                                         int destinations[], int *weights,
                                         MPI_Info info, int reorder,
                                         MPI_Comm *comm_dist_graph);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Dist_graph_create)(MPI_Comm comm_old, int n,
                                             int sources[], int degrees[],
                                             int destinations[], int *weights,
                                             MPI_Info info, int reorder,
                                             MPI_Comm *comm_dist_graph);
int PMPI_Dist_graph_create(MPI_Comm comm_old, int n, int sources[],
                           int degrees[], int destinations[], int *weights,
                           MPI_Info info, int reorder,
                           MPI_Comm *comm_dist_graph) {
  return INTERFACE_LOCAL_MPI_Dist_graph_create(comm_old, n, sources, degrees,
                                               destinations, weights, info,
                                               reorder, comm_dist_graph);
}

int MPI_Dist_graph_neighbors(MPI_Comm comm, int maxindegree, int sources[],
                             int *sourceweights, int maxoutdegree,
                             int destinations[], int *destweights);
#pragma weak MPI_Dist_graph_neighbors = PMPI_Dist_graph_neighbors

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Dist_graph_neighbors(MPI_Comm comm, int maxindegree,
                                           int sources[], int *sourceweights,
                                           int maxoutdegree, int destinations[],
                                           int *destweights);

int INTERF_2_INTEL_MPI_Dist_graph_neighbors(MPI_Comm comm, int maxindegree,
                                            int sources[], int *sourceweights,
                                            int maxoutdegree,
                                            int destinations[],
                                            int *destweights);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Dist_graph_neighbors)(
    MPI_Comm comm, int maxindegree, int sources[], int *sourceweights,
    int maxoutdegree, int destinations[], int *destweights);
int PMPI_Dist_graph_neighbors(MPI_Comm comm, int maxindegree, int sources[],
                              int *sourceweights, int maxoutdegree,
                              int destinations[], int *destweights) {
  return INTERFACE_LOCAL_MPI_Dist_graph_neighbors(comm, maxindegree, sources,
                                                  sourceweights, maxoutdegree,
                                                  destinations, destweights);
}

int MPI_Igatherv(void *sendbuf, int sendcount, MPI_Datatype sendtype,
                 void *recvbuf, int recvcounts[], int displs[],
                 MPI_Datatype recvtype, int root, MPI_Comm comm,
                 MPI_Request *request);
#pragma weak MPI_Igatherv = PMPI_Igatherv

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Igatherv(void *sendbuf, int sendcount,
                               MPI_Datatype sendtype, void *recvbuf,
                               int recvcounts[], int displs[],
                               MPI_Datatype recvtype, int root, MPI_Comm comm,
                               MPI_Request *request);

int INTERF_2_INTEL_MPI_Igatherv(void *sendbuf, int sendcount,
                                MPI_Datatype sendtype, void *recvbuf,
                                int recvcounts[], int displs[],
                                MPI_Datatype recvtype, int root, MPI_Comm comm,
                                MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Igatherv)(void *sendbuf, int sendcount,
                                    MPI_Datatype sendtype, void *recvbuf,
                                    int recvcounts[], int displs[],
                                    MPI_Datatype recvtype, int root,
                                    MPI_Comm comm, MPI_Request *request);
int PMPI_Igatherv(void *sendbuf, int sendcount, MPI_Datatype sendtype,
                  void *recvbuf, int recvcounts[], int displs[],
                  MPI_Datatype recvtype, int root, MPI_Comm comm,
                  MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_Igatherv(sendbuf, sendcount, sendtype, recvbuf,
                                      recvcounts, displs, recvtype, root, comm,
                                      request);
}

int MPI_Iscatterv(void *sendbuf, int sendcounts[], int *displs,
                  MPI_Datatype sendtype, void *recvbuf, int recvcount,
                  MPI_Datatype recvtype, int root, MPI_Comm comm,
                  MPI_Request *request);
#pragma weak MPI_Iscatterv = PMPI_Iscatterv

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Iscatterv(void *sendbuf, int sendcounts[], int *displs,
                                MPI_Datatype sendtype, void *recvbuf,
                                int recvcount, MPI_Datatype recvtype, int root,
                                MPI_Comm comm, MPI_Request *request);

int INTERF_2_INTEL_MPI_Iscatterv(void *sendbuf, int sendcounts[], int *displs,
                                 MPI_Datatype sendtype, void *recvbuf,
                                 int recvcount, MPI_Datatype recvtype, int root,
                                 MPI_Comm comm, MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Iscatterv)(void *sendbuf, int sendcounts[],
                                     int *displs, MPI_Datatype sendtype,
                                     void *recvbuf, int recvcount,
                                     MPI_Datatype recvtype, int root,
                                     MPI_Comm comm, MPI_Request *request);
int PMPI_Iscatterv(void *sendbuf, int sendcounts[], int *displs,
                   MPI_Datatype sendtype, void *recvbuf, int recvcount,
                   MPI_Datatype recvtype, int root, MPI_Comm comm,
                   MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_Iscatterv(sendbuf, sendcounts, displs, sendtype,
                                       recvbuf, recvcount, recvtype, root, comm,
                                       request);
}

int MPI_Iallgatherv(void *sendbuf, int sendcount, MPI_Datatype sendtype,
                    void *recvbuf, int recvcounts[], int displs[],
                    MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request);
#pragma weak MPI_Iallgatherv = PMPI_Iallgatherv

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Iallgatherv(void *sendbuf, int sendcount,
                                  MPI_Datatype sendtype, void *recvbuf,
                                  int recvcounts[], int displs[],
                                  MPI_Datatype recvtype, MPI_Comm comm,
                                  MPI_Request *request);

int INTERF_2_INTEL_MPI_Iallgatherv(void *sendbuf, int sendcount,
                                   MPI_Datatype sendtype, void *recvbuf,
                                   int recvcounts[], int displs[],
                                   MPI_Datatype recvtype, MPI_Comm comm,
                                   MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Iallgatherv)(void *sendbuf, int sendcount,
                                       MPI_Datatype sendtype, void *recvbuf,
                                       int recvcounts[], int displs[],
                                       MPI_Datatype recvtype, MPI_Comm comm,
                                       MPI_Request *request);
int PMPI_Iallgatherv(void *sendbuf, int sendcount, MPI_Datatype sendtype,
                     void *recvbuf, int recvcounts[], int displs[],
                     MPI_Datatype recvtype, MPI_Comm comm,
                     MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_Iallgatherv(sendbuf, sendcount, sendtype, recvbuf,
                                         recvcounts, displs, recvtype, comm,
                                         request);
}

int MPI_Ialltoallv(void *sendbuf, int *sendcounts, int *sdispls,
                   MPI_Datatype sendtype, void *recvbuf, int *recvcounts,
                   int *rdispls, MPI_Datatype recvtype, MPI_Comm comm,
                   MPI_Request *request);
#pragma weak MPI_Ialltoallv = PMPI_Ialltoallv

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Ialltoallv(void *sendbuf, int *sendcounts, int *sdispls,
                                 MPI_Datatype sendtype, void *recvbuf,
                                 int *recvcounts, int *rdispls,
                                 MPI_Datatype recvtype, MPI_Comm comm,
                                 MPI_Request *request);

int INTERF_2_INTEL_MPI_Ialltoallv(void *sendbuf, int *sendcounts, int *sdispls,
                                  MPI_Datatype sendtype, void *recvbuf,
                                  int *recvcounts, int *rdispls,
                                  MPI_Datatype recvtype, MPI_Comm comm,
                                  MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Ialltoallv)(void *sendbuf, int *sendcounts,
                                      int *sdispls, MPI_Datatype sendtype,
                                      void *recvbuf, int *recvcounts,
                                      int *rdispls, MPI_Datatype recvtype,
                                      MPI_Comm comm, MPI_Request *request);
int PMPI_Ialltoallv(void *sendbuf, int *sendcounts, int *sdispls,
                    MPI_Datatype sendtype, void *recvbuf, int *recvcounts,
                    int *rdispls, MPI_Datatype recvtype, MPI_Comm comm,
                    MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_Ialltoallv(sendbuf, sendcounts, sdispls, sendtype,
                                        recvbuf, recvcounts, rdispls, recvtype,
                                        comm, request);
}

int MPI_Ialltoallw(void *sendbuf, int sendcounts[], int sdispls[],
                   MPI_Datatype sendtypes[], void *recvbuf, int recvcounts[],
                   int rdispls[], MPI_Datatype recvtypes[], MPI_Comm comm,
                   MPI_Request *request);
#pragma weak MPI_Ialltoallw = PMPI_Ialltoallw

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Ialltoallw(void *sendbuf, int sendcounts[], int sdispls[],
                                 MPI_Datatype sendtypes[], void *recvbuf,
                                 int recvcounts[], int rdispls[],
                                 MPI_Datatype recvtypes[], MPI_Comm comm,
                                 MPI_Request *request);

int INTERF_2_INTEL_MPI_Ialltoallw(void *sendbuf, int sendcounts[],
                                  int sdispls[], MPI_Datatype sendtypes[],
                                  void *recvbuf, int recvcounts[],
                                  int rdispls[], MPI_Datatype recvtypes[],
                                  MPI_Comm comm, MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Ialltoallw)(void *sendbuf, int sendcounts[],
                                      int sdispls[], MPI_Datatype sendtypes[],
                                      void *recvbuf, int recvcounts[],
                                      int rdispls[], MPI_Datatype recvtypes[],
                                      MPI_Comm comm, MPI_Request *request);
int PMPI_Ialltoallw(void *sendbuf, int sendcounts[], int sdispls[],
                    MPI_Datatype sendtypes[], void *recvbuf, int recvcounts[],
                    int rdispls[], MPI_Datatype recvtypes[], MPI_Comm comm,
                    MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_Ialltoallw(sendbuf, sendcounts, sdispls, sendtypes,
                                        recvbuf, recvcounts, rdispls, recvtypes,
                                        comm, request);
}

int MPI_Ireduce_scatter(void *sendbuf, void *recvbuf, int recvcounts[],
                        MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                        MPI_Request *request);
#pragma weak MPI_Ireduce_scatter = PMPI_Ireduce_scatter

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Ireduce_scatter(void *sendbuf, void *recvbuf,
                                      int recvcounts[], MPI_Datatype datatype,
                                      MPI_Op op, MPI_Comm comm,
                                      MPI_Request *request);

int INTERF_2_INTEL_MPI_Ireduce_scatter(void *sendbuf, void *recvbuf,
                                       int recvcounts[], MPI_Datatype datatype,
                                       MPI_Op op, MPI_Comm comm,
                                       MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Ireduce_scatter)(void *sendbuf, void *recvbuf,
                                           int recvcounts[],
                                           MPI_Datatype datatype, MPI_Op op,
                                           MPI_Comm comm, MPI_Request *request);
int PMPI_Ireduce_scatter(void *sendbuf, void *recvbuf, int recvcounts[],
                         MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                         MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_Ireduce_scatter(sendbuf, recvbuf, recvcounts,
                                             datatype, op, comm, request);
}

int MPI_Ineighbor_allgatherv(void *sendbuf, int sendcount,
                             MPI_Datatype sendtype, void *recvbuf,
                             int recvcounts[], int displs[],
                             MPI_Datatype recvtype, MPI_Comm comm,
                             MPI_Request *request);
#pragma weak MPI_Ineighbor_allgatherv = PMPI_Ineighbor_allgatherv

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Ineighbor_allgatherv(void *sendbuf, int sendcount,
                                           MPI_Datatype sendtype, void *recvbuf,
                                           int recvcounts[], int displs[],
                                           MPI_Datatype recvtype, MPI_Comm comm,
                                           MPI_Request *request);

int INTERF_2_INTEL_MPI_Ineighbor_allgatherv(void *sendbuf, int sendcount,
                                            MPI_Datatype sendtype,
                                            void *recvbuf, int recvcounts[],
                                            int displs[], MPI_Datatype recvtype,
                                            MPI_Comm comm,
                                            MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Ineighbor_allgatherv)(
    void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf,
    int recvcounts[], int displs[], MPI_Datatype recvtype, MPI_Comm comm,
    MPI_Request *request);
int PMPI_Ineighbor_allgatherv(void *sendbuf, int sendcount,
                              MPI_Datatype sendtype, void *recvbuf,
                              int recvcounts[], int displs[],
                              MPI_Datatype recvtype, MPI_Comm comm,
                              MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_Ineighbor_allgatherv(sendbuf, sendcount, sendtype,
                                                  recvbuf, recvcounts, displs,
                                                  recvtype, comm, request);
}

int MPI_Ineighbor_alltoallv(void *sendbuf, int sendcounts[], int sdispls[],
                            MPI_Datatype sendtype, void *recvbuf,
                            int recvcounts[], int rdispls[],
                            MPI_Datatype recvtype, MPI_Comm comm,
                            MPI_Request *request);
#pragma weak MPI_Ineighbor_alltoallv = PMPI_Ineighbor_alltoallv

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Ineighbor_alltoallv(void *sendbuf, int sendcounts[],
                                          int sdispls[], MPI_Datatype sendtype,
                                          void *recvbuf, int recvcounts[],
                                          int rdispls[], MPI_Datatype recvtype,
                                          MPI_Comm comm, MPI_Request *request);

int INTERF_2_INTEL_MPI_Ineighbor_alltoallv(void *sendbuf, int sendcounts[],
                                           int sdispls[], MPI_Datatype sendtype,
                                           void *recvbuf, int recvcounts[],
                                           int rdispls[], MPI_Datatype recvtype,
                                           MPI_Comm comm, MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Ineighbor_alltoallv)(
    void *sendbuf, int sendcounts[], int sdispls[], MPI_Datatype sendtype,
    void *recvbuf, int recvcounts[], int rdispls[], MPI_Datatype recvtype,
    MPI_Comm comm, MPI_Request *request);
int PMPI_Ineighbor_alltoallv(void *sendbuf, int sendcounts[], int sdispls[],
                             MPI_Datatype sendtype, void *recvbuf,
                             int recvcounts[], int rdispls[],
                             MPI_Datatype recvtype, MPI_Comm comm,
                             MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_Ineighbor_alltoallv(
      sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls,
      recvtype, comm, request);
}

int MPI_Ineighbor_alltoallw(void *sendbuf, int sendcounts[], MPI_Aint sdispls[],
                            MPI_Datatype sendtypes[], void *recvbuf,
                            int recvcounts[], MPI_Aint rdispls[],
                            MPI_Datatype recvtypes[], MPI_Comm comm,
                            MPI_Request *request);
#pragma weak MPI_Ineighbor_alltoallw = PMPI_Ineighbor_alltoallw

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Ineighbor_alltoallw(void *sendbuf, int sendcounts[],
                                          MPI_Aint sdispls[],
                                          MPI_Datatype sendtypes[],
                                          void *recvbuf, int recvcounts[],
                                          MPI_Aint rdispls[],
                                          MPI_Datatype recvtypes[],
                                          MPI_Comm comm, MPI_Request *request);

int INTERF_2_INTEL_MPI_Ineighbor_alltoallw(void *sendbuf, int sendcounts[],
                                           MPI_Aint sdispls[],
                                           MPI_Datatype sendtypes[],
                                           void *recvbuf, int recvcounts[],
                                           MPI_Aint rdispls[],
                                           MPI_Datatype recvtypes[],
                                           MPI_Comm comm, MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Ineighbor_alltoallw)(
    void *sendbuf, int sendcounts[], MPI_Aint sdispls[],
    MPI_Datatype sendtypes[], void *recvbuf, int recvcounts[],
    MPI_Aint rdispls[], MPI_Datatype recvtypes[], MPI_Comm comm,
    MPI_Request *request);
int PMPI_Ineighbor_alltoallw(void *sendbuf, int sendcounts[],
                             MPI_Aint sdispls[], MPI_Datatype sendtypes[],
                             void *recvbuf, int recvcounts[],
                             MPI_Aint rdispls[], MPI_Datatype recvtypes[],
                             MPI_Comm comm, MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_Ineighbor_alltoallw(
      sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls,
      recvtypes, comm, request);
}

int MPI_Neighbor_allgatherv(void *sendbuf, int sendcount, MPI_Datatype sendtype,
                            void *recvbuf, int recvcounts[], int displs[],
                            MPI_Datatype recvtype, MPI_Comm comm);
#pragma weak MPI_Neighbor_allgatherv = PMPI_Neighbor_allgatherv

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Neighbor_allgatherv(void *sendbuf, int sendcount,
                                          MPI_Datatype sendtype, void *recvbuf,
                                          int recvcounts[], int displs[],
                                          MPI_Datatype recvtype, MPI_Comm comm);

int INTERF_2_INTEL_MPI_Neighbor_allgatherv(void *sendbuf, int sendcount,
                                           MPI_Datatype sendtype, void *recvbuf,
                                           int recvcounts[], int displs[],
                                           MPI_Datatype recvtype,
                                           MPI_Comm comm);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Neighbor_allgatherv)(
    void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf,
    int recvcounts[], int displs[], MPI_Datatype recvtype, MPI_Comm comm);
int PMPI_Neighbor_allgatherv(void *sendbuf, int sendcount,
                             MPI_Datatype sendtype, void *recvbuf,
                             int recvcounts[], int displs[],
                             MPI_Datatype recvtype, MPI_Comm comm) {
  return INTERFACE_LOCAL_MPI_Neighbor_allgatherv(sendbuf, sendcount, sendtype,
                                                 recvbuf, recvcounts, displs,
                                                 recvtype, comm);
}

int MPI_Neighbor_alltoallv(void *sendbuf, int sendcounts[], int sdispls[],
                           MPI_Datatype sendtype, void *recvbuf,
                           int recvcounts[], int rdispls[],
                           MPI_Datatype recvtype, MPI_Comm comm);
#pragma weak MPI_Neighbor_alltoallv = PMPI_Neighbor_alltoallv

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Neighbor_alltoallv(void *sendbuf, int sendcounts[],
                                         int sdispls[], MPI_Datatype sendtype,
                                         void *recvbuf, int recvcounts[],
                                         int rdispls[], MPI_Datatype recvtype,
                                         MPI_Comm comm);

int INTERF_2_INTEL_MPI_Neighbor_alltoallv(void *sendbuf, int sendcounts[],
                                          int sdispls[], MPI_Datatype sendtype,
                                          void *recvbuf, int recvcounts[],
                                          int rdispls[], MPI_Datatype recvtype,
                                          MPI_Comm comm);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Neighbor_alltoallv)(
    void *sendbuf, int sendcounts[], int sdispls[], MPI_Datatype sendtype,
    void *recvbuf, int recvcounts[], int rdispls[], MPI_Datatype recvtype,
    MPI_Comm comm);
int PMPI_Neighbor_alltoallv(void *sendbuf, int sendcounts[], int sdispls[],
                            MPI_Datatype sendtype, void *recvbuf,
                            int recvcounts[], int rdispls[],
                            MPI_Datatype recvtype, MPI_Comm comm) {
  return INTERFACE_LOCAL_MPI_Neighbor_alltoallv(sendbuf, sendcounts, sdispls,
                                                sendtype, recvbuf, recvcounts,
                                                rdispls, recvtype, comm);
}

int MPI_Neighbor_alltoallw(void *sendbuf, int sendcounts[], MPI_Aint sdispls[],
                           MPI_Datatype sendtypes[], void *recvbuf,
                           int recvcounts[], MPI_Aint rdispls[],
                           MPI_Datatype recvtypes[], MPI_Comm comm);
#pragma weak MPI_Neighbor_alltoallw = PMPI_Neighbor_alltoallw

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_Neighbor_alltoallw(
    void *sendbuf, int sendcounts[], MPI_Aint sdispls[],
    MPI_Datatype sendtypes[], void *recvbuf, int recvcounts[],
    MPI_Aint rdispls[], MPI_Datatype recvtypes[], MPI_Comm comm);

int INTERF_2_INTEL_MPI_Neighbor_alltoallw(
    void *sendbuf, int sendcounts[], MPI_Aint sdispls[],
    MPI_Datatype sendtypes[], void *recvbuf, int recvcounts[],
    MPI_Aint rdispls[], MPI_Datatype recvtypes[], MPI_Comm comm);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_Neighbor_alltoallw)(
    void *sendbuf, int sendcounts[], MPI_Aint sdispls[],
    MPI_Datatype sendtypes[], void *recvbuf, int recvcounts[],
    MPI_Aint rdispls[], MPI_Datatype recvtypes[], MPI_Comm comm);
int PMPI_Neighbor_alltoallw(void *sendbuf, int sendcounts[], MPI_Aint sdispls[],
                            MPI_Datatype sendtypes[], void *recvbuf,
                            int recvcounts[], MPI_Aint rdispls[],
                            MPI_Datatype recvtypes[], MPI_Comm comm) {
  return INTERFACE_LOCAL_MPI_Neighbor_alltoallw(sendbuf, sendcounts, sdispls,
                                                sendtypes, recvbuf, recvcounts,
                                                rdispls, recvtypes, comm);
}

int MPI_T_category_get_cvars(int cat_index, int len, int indices[]);
#pragma weak MPI_T_category_get_cvars = PMPI_T_category_get_cvars

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_T_category_get_cvars(int cat_index, int len,
                                           int indices[]);

int INTERF_2_INTEL_MPI_T_category_get_cvars(int cat_index, int len,
                                            int indices[]);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_T_category_get_cvars)(int cat_index, int len,
                                                int indices[]);
int PMPI_T_category_get_cvars(int cat_index, int len, int indices[]) {
  return INTERFACE_LOCAL_MPI_T_category_get_cvars(cat_index, len, indices);
}

int MPI_T_category_get_pvars(int cat_index, int len, int indices[]);
#pragma weak MPI_T_category_get_pvars = PMPI_T_category_get_pvars

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_T_category_get_pvars(int cat_index, int len,
                                           int indices[]);

int INTERF_2_INTEL_MPI_T_category_get_pvars(int cat_index, int len,
                                            int indices[]);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_T_category_get_pvars)(int cat_index, int len,
                                                int indices[]);
int PMPI_T_category_get_pvars(int cat_index, int len, int indices[]) {
  return INTERFACE_LOCAL_MPI_T_category_get_pvars(cat_index, len, indices);
}

int MPI_T_category_get_categories(int cat_index, int len, int indices[]);
#pragma weak MPI_T_category_get_categories = PMPI_T_category_get_categories

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_T_category_get_categories(int cat_index, int len,
                                                int indices[]);

int INTERF_2_INTEL_MPI_T_category_get_categories(int cat_index, int len,
                                                 int indices[]);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_T_category_get_categories)(int cat_index, int len,
                                                     int indices[]);
int PMPI_T_category_get_categories(int cat_index, int len, int indices[]) {
  return INTERFACE_LOCAL_MPI_T_category_get_categories(cat_index, len, indices);
}

int MPI_File_iwrite_all(MPI_File fh, void *buf, int count,
                        MPI_Datatype datatype, MPI_Request *request);
#pragma weak MPI_File_iwrite_all = PMPI_File_iwrite_all

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_iwrite_all(MPI_File fh, void *buf, int count,
                                      MPI_Datatype datatype,
                                      MPI_Request *request);

int INTERF_2_INTEL_MPI_File_iwrite_all(MPI_File fh, void *buf, int count,
                                       MPI_Datatype datatype,
                                       MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_iwrite_all)(MPI_File fh, void *buf, int count,
                                           MPI_Datatype datatype,
                                           MPI_Request *request);
int PMPI_File_iwrite_all(MPI_File fh, void *buf, int count,
                         MPI_Datatype datatype, MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_File_iwrite_all(fh, buf, count, datatype, request);
}

int MPI_File_iwrite_at_all(MPI_File fh, MPI_Offset offset, void *buf, int count,
                           MPI_Datatype datatype, MPI_Request *request);
#pragma weak MPI_File_iwrite_at_all = PMPI_File_iwrite_at_all

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_iwrite_at_all(MPI_File fh, MPI_Offset offset,
                                         void *buf, int count,
                                         MPI_Datatype datatype,
                                         MPI_Request *request);

int INTERF_2_INTEL_MPI_File_iwrite_at_all(MPI_File fh, MPI_Offset offset,
                                          void *buf, int count,
                                          MPI_Datatype datatype,
                                          MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_iwrite_at_all)(MPI_File fh, MPI_Offset offset,
                                              void *buf, int count,
                                              MPI_Datatype datatype,
                                              MPI_Request *request);
int PMPI_File_iwrite_at_all(MPI_File fh, MPI_Offset offset, void *buf,
                            int count, MPI_Datatype datatype,
                            MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_File_iwrite_at_all(fh, offset, buf, count,
                                                datatype, request);
}

int MPI_T_category_get_index(char *name, int *cat_index);
#pragma weak MPI_T_category_get_index = PMPI_T_category_get_index

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_T_category_get_index(char *name, int *cat_index);

int INTERF_2_INTEL_MPI_T_category_get_index(char *name, int *cat_index);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_T_category_get_index)(char *name, int *cat_index);
int PMPI_T_category_get_index(char *name, int *cat_index) {
  return INTERFACE_LOCAL_MPI_T_category_get_index(name, cat_index);
}

int MPI_T_cvar_get_index(char *name, int *cvar_index);
#pragma weak MPI_T_cvar_get_index = PMPI_T_cvar_get_index

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_T_cvar_get_index(char *name, int *cvar_index);

int INTERF_2_INTEL_MPI_T_cvar_get_index(char *name, int *cvar_index);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_T_cvar_get_index)(char *name, int *cvar_index);
int PMPI_T_cvar_get_index(char *name, int *cvar_index) {
  return INTERFACE_LOCAL_MPI_T_cvar_get_index(name, cvar_index);
}

int MPI_T_pvar_get_index(char *name, int var_class, int *pvar_index);
#pragma weak MPI_T_pvar_get_index = PMPI_T_pvar_get_index

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_T_pvar_get_index(char *name, int var_class,
                                       int *pvar_index);

int INTERF_2_INTEL_MPI_T_pvar_get_index(char *name, int var_class,
                                        int *pvar_index);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_T_pvar_get_index)(char *name, int var_class,
                                            int *pvar_index);
int PMPI_T_pvar_get_index(char *name, int var_class, int *pvar_index) {
  return INTERFACE_LOCAL_MPI_T_pvar_get_index(name, var_class, pvar_index);
}

MPI_Aint MPI_Aint_add(MPI_Aint base, MPI_Aint disp);
#pragma weak MPI_Aint_add = PMPI_Aint_add

#ifdef WI4MPI_STATIC

MPI_Aint INTERF_2_OMPI_MPI_Aint_add(MPI_Aint base, MPI_Aint disp);

MPI_Aint INTERF_2_INTEL_MPI_Aint_add(MPI_Aint base, MPI_Aint disp);

#endif /* WI4MPI_STATIC */

MPI_Aint (*INTERFACE_LOCAL_MPI_Aint_add)(MPI_Aint base, MPI_Aint disp);
MPI_Aint PMPI_Aint_add(MPI_Aint base, MPI_Aint disp) {
  return INTERFACE_LOCAL_MPI_Aint_add(base, disp);
}

MPI_Aint MPI_Aint_diff(MPI_Aint addr1, MPI_Aint addr2);
#pragma weak MPI_Aint_diff = PMPI_Aint_diff

#ifdef WI4MPI_STATIC

MPI_Aint INTERF_2_OMPI_MPI_Aint_diff(MPI_Aint addr1, MPI_Aint addr2);

MPI_Aint INTERF_2_INTEL_MPI_Aint_diff(MPI_Aint addr1, MPI_Aint addr2);

#endif /* WI4MPI_STATIC */

MPI_Aint (*INTERFACE_LOCAL_MPI_Aint_diff)(MPI_Aint addr1, MPI_Aint addr2);
MPI_Aint PMPI_Aint_diff(MPI_Aint addr1, MPI_Aint addr2) {
  return INTERFACE_LOCAL_MPI_Aint_diff(addr1, addr2);
}

int MPI_File_iread_all(MPI_File fh, void *buf, int count, MPI_Datatype datatype,
                       MPI_Request *request);
#pragma weak MPI_File_iread_all = PMPI_File_iread_all

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_iread_all(MPI_File fh, void *buf, int count,
                                     MPI_Datatype datatype,
                                     MPI_Request *request);

int INTERF_2_INTEL_MPI_File_iread_all(MPI_File fh, void *buf, int count,
                                      MPI_Datatype datatype,
                                      MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_iread_all)(MPI_File fh, void *buf, int count,
                                          MPI_Datatype datatype,
                                          MPI_Request *request);
int PMPI_File_iread_all(MPI_File fh, void *buf, int count,
                        MPI_Datatype datatype, MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_File_iread_all(fh, buf, count, datatype, request);
}

int MPI_File_iread_at_all(MPI_File fh, MPI_Offset offset, void *buf, int count,
                          MPI_Datatype datatype, MPI_Request *request);
#pragma weak MPI_File_iread_at_all = PMPI_File_iread_at_all

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_File_iread_at_all(MPI_File fh, MPI_Offset offset,
                                        void *buf, int count,
                                        MPI_Datatype datatype,
                                        MPI_Request *request);

int INTERF_2_INTEL_MPI_File_iread_at_all(MPI_File fh, MPI_Offset offset,
                                         void *buf, int count,
                                         MPI_Datatype datatype,
                                         MPI_Request *request);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_File_iread_at_all)(MPI_File fh, MPI_Offset offset,
                                             void *buf, int count,
                                             MPI_Datatype datatype,
                                             MPI_Request *request);
int PMPI_File_iread_at_all(MPI_File fh, MPI_Offset offset, void *buf, int count,
                           MPI_Datatype datatype, MPI_Request *request) {
  return INTERFACE_LOCAL_MPI_File_iread_at_all(fh, offset, buf, count, datatype,
                                               request);
}

int MPI_T_category_changed(int *stamp);
#pragma weak MPI_T_category_changed = PMPI_T_category_changed

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPI_T_category_changed(int *stamp);

int INTERF_2_INTEL_MPI_T_category_changed(int *stamp);

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPI_T_category_changed)(int *stamp);
int PMPI_T_category_changed(int *stamp) {
  return INTERFACE_LOCAL_MPI_T_category_changed(stamp);
}

int MPIX_query_cuda_support();
#pragma weak MPIX_query_cuda_support = PMPIX_query_cuda_support

#ifdef WI4MPI_STATIC

int INTERF_2_OMPI_MPIX_query_cuda_support();

int INTERF_2_INTEL_MPIX_query_cuda_support();

#endif /* WI4MPI_STATIC */

int (*INTERFACE_LOCAL_MPIX_query_cuda_support)();
int PMPIX_query_cuda_support() {
  return INTERFACE_LOCAL_MPIX_query_cuda_support();
}

int wi4mpi__init__C = 0;
extern int wi4mpi__init__F;
__attribute__((constructor)) void wrapper_interface(void) {
  void *interface_handle;
  if (wi4mpi__init__C != 0)
    return;
  wi4mpi__init__C = 1;
#ifdef WI4MPI_STATIC
  char *target_inter = getenv("WI4MPI_STATIC_TARGET_TYPE");
  int libfound = 0;
  if (!libfound) {
    printf("no target library defined conversion cannot be chosen\n");
    exit(1);
  }

#else /* WI4MPI_STATIC */
  if (getenv("WI4MPI_WRAPPER_LIB") != NULL)
    interface_handle =
        dlopen(getenv("WI4MPI_WRAPPER_LIB"), RTLD_NOW | RTLD_GLOBAL);
  else {
    if (strcmp(wi4mpi_mode, "") != 0) {
      interface_handle = dlopen(wi4mpi_mode, RTLD_NOW | RTLD_GLOBAL);
    } else {
      fprintf(stderr, "Please provide either WI4MPI_WRAPPER_LIB environment or "
                      "compile with -wi4mpi_default_run_paths\n");
      exit(1);
    }
  }
  if (!interface_handle) {
    printf("Dlopen failed to open WI4MPI librarie.\nerror :%s\n", dlerror());
    exit(1);
  }

  INTERFACE_LOCAL_MPI_Pcontrol = dlsym(interface_handle, "INTERF_MPI_Pcontrol");

  INTERFACE_LOCAL_MPI_Send = dlsym(interface_handle, "INTERF_MPI_Send");

  INTERFACE_LOCAL_MPI_Recv = dlsym(interface_handle, "INTERF_MPI_Recv");

  INTERFACE_LOCAL_MPI_Get_count =
      dlsym(interface_handle, "INTERF_MPI_Get_count");

  INTERFACE_LOCAL_MPI_Bsend = dlsym(interface_handle, "INTERF_MPI_Bsend");

  INTERFACE_LOCAL_MPI_Ssend = dlsym(interface_handle, "INTERF_MPI_Ssend");

  INTERFACE_LOCAL_MPI_Rsend = dlsym(interface_handle, "INTERF_MPI_Rsend");

  INTERFACE_LOCAL_MPI_Buffer_attach =
      dlsym(interface_handle, "INTERF_MPI_Buffer_attach");

  INTERFACE_LOCAL_MPI_Buffer_detach =
      dlsym(interface_handle, "INTERF_MPI_Buffer_detach");

  INTERFACE_LOCAL_MPI_Isend = dlsym(interface_handle, "INTERF_MPI_Isend");

  INTERFACE_LOCAL_MPI_Ibsend = dlsym(interface_handle, "INTERF_MPI_Ibsend");

  INTERFACE_LOCAL_MPI_Issend = dlsym(interface_handle, "INTERF_MPI_Issend");

  INTERFACE_LOCAL_MPI_Irsend = dlsym(interface_handle, "INTERF_MPI_Irsend");

  INTERFACE_LOCAL_MPI_Irecv = dlsym(interface_handle, "INTERF_MPI_Irecv");

  INTERFACE_LOCAL_MPI_Wait = dlsym(interface_handle, "INTERF_MPI_Wait");

  INTERFACE_LOCAL_MPI_Test = dlsym(interface_handle, "INTERF_MPI_Test");

  INTERFACE_LOCAL_MPI_Request_free =
      dlsym(interface_handle, "INTERF_MPI_Request_free");

  INTERFACE_LOCAL_MPI_Iprobe = dlsym(interface_handle, "INTERF_MPI_Iprobe");

  INTERFACE_LOCAL_MPI_Probe = dlsym(interface_handle, "INTERF_MPI_Probe");

  INTERFACE_LOCAL_MPI_Cancel = dlsym(interface_handle, "INTERF_MPI_Cancel");

  INTERFACE_LOCAL_MPI_Test_cancelled =
      dlsym(interface_handle, "INTERF_MPI_Test_cancelled");

  INTERFACE_LOCAL_MPI_Send_init =
      dlsym(interface_handle, "INTERF_MPI_Send_init");

  INTERFACE_LOCAL_MPI_Bsend_init =
      dlsym(interface_handle, "INTERF_MPI_Bsend_init");

  INTERFACE_LOCAL_MPI_Ssend_init =
      dlsym(interface_handle, "INTERF_MPI_Ssend_init");

  INTERFACE_LOCAL_MPI_Rsend_init =
      dlsym(interface_handle, "INTERF_MPI_Rsend_init");

  INTERFACE_LOCAL_MPI_Recv_init =
      dlsym(interface_handle, "INTERF_MPI_Recv_init");

  INTERFACE_LOCAL_MPI_Start = dlsym(interface_handle, "INTERF_MPI_Start");

  INTERFACE_LOCAL_MPI_Sendrecv = dlsym(interface_handle, "INTERF_MPI_Sendrecv");

  INTERFACE_LOCAL_MPI_Sendrecv_replace =
      dlsym(interface_handle, "INTERF_MPI_Sendrecv_replace");

  INTERFACE_LOCAL_MPI_Type_contiguous =
      dlsym(interface_handle, "INTERF_MPI_Type_contiguous");

  INTERFACE_LOCAL_MPI_Type_vector =
      dlsym(interface_handle, "INTERF_MPI_Type_vector");

  INTERFACE_LOCAL_MPI_Type_hvector =
      dlsym(interface_handle, "INTERF_MPI_Type_hvector");

  INTERFACE_LOCAL_MPI_Type_indexed =
      dlsym(interface_handle, "INTERF_MPI_Type_indexed");

  INTERFACE_LOCAL_MPI_Type_hindexed =
      dlsym(interface_handle, "INTERF_MPI_Type_hindexed");

  INTERFACE_LOCAL_MPI_Type_struct =
      dlsym(interface_handle, "INTERF_MPI_Type_struct");

  INTERFACE_LOCAL_MPI_Address = dlsym(interface_handle, "INTERF_MPI_Address");

  INTERFACE_LOCAL_MPI_Type_extent =
      dlsym(interface_handle, "INTERF_MPI_Type_extent");

  INTERFACE_LOCAL_MPI_Type_size =
      dlsym(interface_handle, "INTERF_MPI_Type_size");

  INTERFACE_LOCAL_MPI_Type_lb = dlsym(interface_handle, "INTERF_MPI_Type_lb");

  INTERFACE_LOCAL_MPI_Type_ub = dlsym(interface_handle, "INTERF_MPI_Type_ub");

  INTERFACE_LOCAL_MPI_Type_commit =
      dlsym(interface_handle, "INTERF_MPI_Type_commit");

  INTERFACE_LOCAL_MPI_Type_free =
      dlsym(interface_handle, "INTERF_MPI_Type_free");

  INTERFACE_LOCAL_MPI_Get_elements =
      dlsym(interface_handle, "INTERF_MPI_Get_elements");

  INTERFACE_LOCAL_MPI_Pack = dlsym(interface_handle, "INTERF_MPI_Pack");

  INTERFACE_LOCAL_MPI_Unpack = dlsym(interface_handle, "INTERF_MPI_Unpack");

  INTERFACE_LOCAL_MPI_Pack_size =
      dlsym(interface_handle, "INTERF_MPI_Pack_size");

  INTERFACE_LOCAL_MPI_Barrier = dlsym(interface_handle, "INTERF_MPI_Barrier");

  INTERFACE_LOCAL_MPI_Bcast = dlsym(interface_handle, "INTERF_MPI_Bcast");

  INTERFACE_LOCAL_MPI_Gather = dlsym(interface_handle, "INTERF_MPI_Gather");

  INTERFACE_LOCAL_MPI_Gatherv = dlsym(interface_handle, "INTERF_MPI_Gatherv");

  INTERFACE_LOCAL_MPI_Scatter = dlsym(interface_handle, "INTERF_MPI_Scatter");

  INTERFACE_LOCAL_MPI_Scatterv = dlsym(interface_handle, "INTERF_MPI_Scatterv");

  INTERFACE_LOCAL_MPI_Allgather =
      dlsym(interface_handle, "INTERF_MPI_Allgather");

  INTERFACE_LOCAL_MPI_Allgatherv =
      dlsym(interface_handle, "INTERF_MPI_Allgatherv");

  INTERFACE_LOCAL_MPI_Alltoall = dlsym(interface_handle, "INTERF_MPI_Alltoall");

  INTERFACE_LOCAL_MPI_Alltoallv =
      dlsym(interface_handle, "INTERF_MPI_Alltoallv");

  INTERFACE_LOCAL_MPI_Exscan = dlsym(interface_handle, "INTERF_MPI_Exscan");

  INTERFACE_LOCAL_MPI_Reduce = dlsym(interface_handle, "INTERF_MPI_Reduce");

  INTERFACE_LOCAL_MPI_Op_create =
      dlsym(interface_handle, "INTERF_MPI_Op_create");

  INTERFACE_LOCAL_MPI_Op_free = dlsym(interface_handle, "INTERF_MPI_Op_free");

  INTERFACE_LOCAL_MPI_Allreduce =
      dlsym(interface_handle, "INTERF_MPI_Allreduce");

  INTERFACE_LOCAL_MPI_Scan = dlsym(interface_handle, "INTERF_MPI_Scan");

  INTERFACE_LOCAL_MPI_Group_size =
      dlsym(interface_handle, "INTERF_MPI_Group_size");

  INTERFACE_LOCAL_MPI_Group_rank =
      dlsym(interface_handle, "INTERF_MPI_Group_rank");

  INTERFACE_LOCAL_MPI_Group_compare =
      dlsym(interface_handle, "INTERF_MPI_Group_compare");

  INTERFACE_LOCAL_MPI_Comm_group =
      dlsym(interface_handle, "INTERF_MPI_Comm_group");

  INTERFACE_LOCAL_MPI_Group_union =
      dlsym(interface_handle, "INTERF_MPI_Group_union");

  INTERFACE_LOCAL_MPI_Group_intersection =
      dlsym(interface_handle, "INTERF_MPI_Group_intersection");

  INTERFACE_LOCAL_MPI_Group_difference =
      dlsym(interface_handle, "INTERF_MPI_Group_difference");

  INTERFACE_LOCAL_MPI_Group_free =
      dlsym(interface_handle, "INTERF_MPI_Group_free");

  INTERFACE_LOCAL_MPI_Comm_size =
      dlsym(interface_handle, "INTERF_MPI_Comm_size");

  INTERFACE_LOCAL_MPI_Comm_rank =
      dlsym(interface_handle, "INTERF_MPI_Comm_rank");

  INTERFACE_LOCAL_MPI_Comm_compare =
      dlsym(interface_handle, "INTERF_MPI_Comm_compare");

  INTERFACE_LOCAL_MPI_Comm_dup = dlsym(interface_handle, "INTERF_MPI_Comm_dup");

  INTERFACE_LOCAL_MPI_Comm_dup_with_info =
      dlsym(interface_handle, "INTERF_MPI_Comm_dup_with_info");

  INTERFACE_LOCAL_MPI_Comm_create =
      dlsym(interface_handle, "INTERF_MPI_Comm_create");

  INTERFACE_LOCAL_MPI_Comm_split =
      dlsym(interface_handle, "INTERF_MPI_Comm_split");

  INTERFACE_LOCAL_MPI_Comm_free =
      dlsym(interface_handle, "INTERF_MPI_Comm_free");

  INTERFACE_LOCAL_MPI_Comm_test_inter =
      dlsym(interface_handle, "INTERF_MPI_Comm_test_inter");

  INTERFACE_LOCAL_MPI_Comm_remote_size =
      dlsym(interface_handle, "INTERF_MPI_Comm_remote_size");

  INTERFACE_LOCAL_MPI_Comm_remote_group =
      dlsym(interface_handle, "INTERF_MPI_Comm_remote_group");

  INTERFACE_LOCAL_MPI_Intercomm_create =
      dlsym(interface_handle, "INTERF_MPI_Intercomm_create");

  INTERFACE_LOCAL_MPI_Intercomm_merge =
      dlsym(interface_handle, "INTERF_MPI_Intercomm_merge");

  INTERFACE_LOCAL_MPI_Keyval_create =
      dlsym(interface_handle, "INTERF_MPI_Keyval_create");

  INTERFACE_LOCAL_MPI_Keyval_free =
      dlsym(interface_handle, "INTERF_MPI_Keyval_free");

  INTERFACE_LOCAL_MPI_Attr_put = dlsym(interface_handle, "INTERF_MPI_Attr_put");

  INTERFACE_LOCAL_MPI_Attr_get = dlsym(interface_handle, "INTERF_MPI_Attr_get");

  INTERFACE_LOCAL_MPI_Attr_delete =
      dlsym(interface_handle, "INTERF_MPI_Attr_delete");

  INTERFACE_LOCAL_MPI_Topo_test =
      dlsym(interface_handle, "INTERF_MPI_Topo_test");

  INTERFACE_LOCAL_MPI_Graphdims_get =
      dlsym(interface_handle, "INTERF_MPI_Graphdims_get");

  INTERFACE_LOCAL_MPI_Cartdim_get =
      dlsym(interface_handle, "INTERF_MPI_Cartdim_get");

  INTERFACE_LOCAL_MPI_Graph_neighbors_count =
      dlsym(interface_handle, "INTERF_MPI_Graph_neighbors_count");

  INTERFACE_LOCAL_MPI_Cart_shift =
      dlsym(interface_handle, "INTERF_MPI_Cart_shift");

  INTERFACE_LOCAL_MPI_Get_processor_name =
      dlsym(interface_handle, "INTERF_MPI_Get_processor_name");

  INTERFACE_LOCAL_MPI_Get_version =
      dlsym(interface_handle, "INTERF_MPI_Get_version");

  INTERFACE_LOCAL_MPI_Get_library_version =
      dlsym(interface_handle, "INTERF_MPI_Get_library_version");

  INTERFACE_LOCAL_MPI_Errhandler_create =
      dlsym(interface_handle, "INTERF_MPI_Errhandler_create");

  INTERFACE_LOCAL_MPI_Errhandler_set =
      dlsym(interface_handle, "INTERF_MPI_Errhandler_set");

  INTERFACE_LOCAL_MPI_Errhandler_get =
      dlsym(interface_handle, "INTERF_MPI_Errhandler_get");

  INTERFACE_LOCAL_MPI_Errhandler_free =
      dlsym(interface_handle, "INTERF_MPI_Errhandler_free");

  INTERFACE_LOCAL_MPI_Error_string =
      dlsym(interface_handle, "INTERF_MPI_Error_string");

  INTERFACE_LOCAL_MPI_Error_class =
      dlsym(interface_handle, "INTERF_MPI_Error_class");

  INTERFACE_LOCAL_MPI_Initialized =
      dlsym(interface_handle, "INTERF_MPI_Initialized");

  INTERFACE_LOCAL_MPI_Abort = dlsym(interface_handle, "INTERF_MPI_Abort");

  INTERFACE_LOCAL_MPI_Init = dlsym(interface_handle, "INTERF_MPI_Init");

  INTERFACE_LOCAL_MPI_Close_port =
      dlsym(interface_handle, "INTERF_MPI_Close_port");

  INTERFACE_LOCAL_MPI_Comm_accept =
      dlsym(interface_handle, "INTERF_MPI_Comm_accept");

  INTERFACE_LOCAL_MPI_Comm_connect =
      dlsym(interface_handle, "INTERF_MPI_Comm_connect");

  INTERFACE_LOCAL_MPI_Comm_disconnect =
      dlsym(interface_handle, "INTERF_MPI_Comm_disconnect");

  INTERFACE_LOCAL_MPI_Comm_get_parent =
      dlsym(interface_handle, "INTERF_MPI_Comm_get_parent");

  INTERFACE_LOCAL_MPI_Comm_join =
      dlsym(interface_handle, "INTERF_MPI_Comm_join");

  INTERFACE_LOCAL_MPI_Lookup_name =
      dlsym(interface_handle, "INTERF_MPI_Lookup_name");

  INTERFACE_LOCAL_MPI_Open_port =
      dlsym(interface_handle, "INTERF_MPI_Open_port");

  INTERFACE_LOCAL_MPI_Publish_name =
      dlsym(interface_handle, "INTERF_MPI_Publish_name");

  INTERFACE_LOCAL_MPI_Unpublish_name =
      dlsym(interface_handle, "INTERF_MPI_Unpublish_name");

  INTERFACE_LOCAL_MPI_Comm_set_info =
      dlsym(interface_handle, "INTERF_MPI_Comm_set_info");

  INTERFACE_LOCAL_MPI_Comm_get_info =
      dlsym(interface_handle, "INTERF_MPI_Comm_get_info");

  INTERFACE_LOCAL_MPI_Accumulate =
      dlsym(interface_handle, "INTERF_MPI_Accumulate");

  INTERFACE_LOCAL_MPI_Get = dlsym(interface_handle, "INTERF_MPI_Get");

  INTERFACE_LOCAL_MPI_Put = dlsym(interface_handle, "INTERF_MPI_Put");

  INTERFACE_LOCAL_MPI_Win_complete =
      dlsym(interface_handle, "INTERF_MPI_Win_complete");

  INTERFACE_LOCAL_MPI_Win_create =
      dlsym(interface_handle, "INTERF_MPI_Win_create");

  INTERFACE_LOCAL_MPI_Win_fence =
      dlsym(interface_handle, "INTERF_MPI_Win_fence");

  INTERFACE_LOCAL_MPI_Win_free = dlsym(interface_handle, "INTERF_MPI_Win_free");

  INTERFACE_LOCAL_MPI_Win_get_group =
      dlsym(interface_handle, "INTERF_MPI_Win_get_group");

  INTERFACE_LOCAL_MPI_Win_lock = dlsym(interface_handle, "INTERF_MPI_Win_lock");

  INTERFACE_LOCAL_MPI_Win_post = dlsym(interface_handle, "INTERF_MPI_Win_post");

  INTERFACE_LOCAL_MPI_Win_start =
      dlsym(interface_handle, "INTERF_MPI_Win_start");

  INTERFACE_LOCAL_MPI_Win_test = dlsym(interface_handle, "INTERF_MPI_Win_test");

  INTERFACE_LOCAL_MPI_Win_unlock =
      dlsym(interface_handle, "INTERF_MPI_Win_unlock");

  INTERFACE_LOCAL_MPI_Win_wait = dlsym(interface_handle, "INTERF_MPI_Win_wait");

  INTERFACE_LOCAL_MPI_Win_allocate =
      dlsym(interface_handle, "INTERF_MPI_Win_allocate");

  INTERFACE_LOCAL_MPI_Win_allocate_shared =
      dlsym(interface_handle, "INTERF_MPI_Win_allocate_shared");

  INTERFACE_LOCAL_MPI_Win_shared_query =
      dlsym(interface_handle, "INTERF_MPI_Win_shared_query");

  INTERFACE_LOCAL_MPI_Win_create_dynamic =
      dlsym(interface_handle, "INTERF_MPI_Win_create_dynamic");

  INTERFACE_LOCAL_MPI_Win_attach =
      dlsym(interface_handle, "INTERF_MPI_Win_attach");

  INTERFACE_LOCAL_MPI_Win_detach =
      dlsym(interface_handle, "INTERF_MPI_Win_detach");

  INTERFACE_LOCAL_MPI_Win_get_info =
      dlsym(interface_handle, "INTERF_MPI_Win_get_info");

  INTERFACE_LOCAL_MPI_Win_set_info =
      dlsym(interface_handle, "INTERF_MPI_Win_set_info");

  INTERFACE_LOCAL_MPI_Get_accumulate =
      dlsym(interface_handle, "INTERF_MPI_Get_accumulate");

  INTERFACE_LOCAL_MPI_Fetch_and_op =
      dlsym(interface_handle, "INTERF_MPI_Fetch_and_op");

  INTERFACE_LOCAL_MPI_Compare_and_swap =
      dlsym(interface_handle, "INTERF_MPI_Compare_and_swap");

  INTERFACE_LOCAL_MPI_Rput = dlsym(interface_handle, "INTERF_MPI_Rput");

  INTERFACE_LOCAL_MPI_Rget = dlsym(interface_handle, "INTERF_MPI_Rget");

  INTERFACE_LOCAL_MPI_Raccumulate =
      dlsym(interface_handle, "INTERF_MPI_Raccumulate");

  INTERFACE_LOCAL_MPI_Rget_accumulate =
      dlsym(interface_handle, "INTERF_MPI_Rget_accumulate");

  INTERFACE_LOCAL_MPI_Win_lock_all =
      dlsym(interface_handle, "INTERF_MPI_Win_lock_all");

  INTERFACE_LOCAL_MPI_Win_unlock_all =
      dlsym(interface_handle, "INTERF_MPI_Win_unlock_all");

  INTERFACE_LOCAL_MPI_Win_flush =
      dlsym(interface_handle, "INTERF_MPI_Win_flush");

  INTERFACE_LOCAL_MPI_Win_flush_all =
      dlsym(interface_handle, "INTERF_MPI_Win_flush_all");

  INTERFACE_LOCAL_MPI_Win_flush_local =
      dlsym(interface_handle, "INTERF_MPI_Win_flush_local");

  INTERFACE_LOCAL_MPI_Win_flush_local_all =
      dlsym(interface_handle, "INTERF_MPI_Win_flush_local_all");

  INTERFACE_LOCAL_MPI_Win_sync = dlsym(interface_handle, "INTERF_MPI_Win_sync");

  INTERFACE_LOCAL_MPI_Add_error_class =
      dlsym(interface_handle, "INTERF_MPI_Add_error_class");

  INTERFACE_LOCAL_MPI_Add_error_code =
      dlsym(interface_handle, "INTERF_MPI_Add_error_code");

  INTERFACE_LOCAL_MPI_Add_error_string =
      dlsym(interface_handle, "INTERF_MPI_Add_error_string");

  INTERFACE_LOCAL_MPI_Comm_call_errhandler =
      dlsym(interface_handle, "INTERF_MPI_Comm_call_errhandler");

  INTERFACE_LOCAL_MPI_Comm_create_keyval =
      dlsym(interface_handle, "INTERF_MPI_Comm_create_keyval");

  INTERFACE_LOCAL_MPI_Comm_delete_attr =
      dlsym(interface_handle, "INTERF_MPI_Comm_delete_attr");

  INTERFACE_LOCAL_MPI_Comm_free_keyval =
      dlsym(interface_handle, "INTERF_MPI_Comm_free_keyval");

  INTERFACE_LOCAL_MPI_Comm_get_attr =
      dlsym(interface_handle, "INTERF_MPI_Comm_get_attr");

  INTERFACE_LOCAL_MPI_Comm_get_name =
      dlsym(interface_handle, "INTERF_MPI_Comm_get_name");

  INTERFACE_LOCAL_MPI_Comm_set_attr =
      dlsym(interface_handle, "INTERF_MPI_Comm_set_attr");

  INTERFACE_LOCAL_MPI_Comm_set_name =
      dlsym(interface_handle, "INTERF_MPI_Comm_set_name");

  INTERFACE_LOCAL_MPI_Grequest_complete =
      dlsym(interface_handle, "INTERF_MPI_Grequest_complete");

  INTERFACE_LOCAL_MPI_Grequest_start =
      dlsym(interface_handle, "INTERF_MPI_Grequest_start");

  INTERFACE_LOCAL_MPI_Init_thread =
      dlsym(interface_handle, "INTERF_MPI_Init_thread");

  INTERFACE_LOCAL_MPI_Is_thread_main =
      dlsym(interface_handle, "INTERF_MPI_Is_thread_main");

  INTERFACE_LOCAL_MPI_Query_thread =
      dlsym(interface_handle, "INTERF_MPI_Query_thread");

  INTERFACE_LOCAL_MPI_Status_set_cancelled =
      dlsym(interface_handle, "INTERF_MPI_Status_set_cancelled");

  INTERFACE_LOCAL_MPI_Status_set_elements =
      dlsym(interface_handle, "INTERF_MPI_Status_set_elements");

  INTERFACE_LOCAL_MPI_Type_create_keyval =
      dlsym(interface_handle, "INTERF_MPI_Type_create_keyval");

  INTERFACE_LOCAL_MPI_Type_delete_attr =
      dlsym(interface_handle, "INTERF_MPI_Type_delete_attr");

  INTERFACE_LOCAL_MPI_Type_dup = dlsym(interface_handle, "INTERF_MPI_Type_dup");

  INTERFACE_LOCAL_MPI_Type_free_keyval =
      dlsym(interface_handle, "INTERF_MPI_Type_free_keyval");

  INTERFACE_LOCAL_MPI_Type_get_attr =
      dlsym(interface_handle, "INTERF_MPI_Type_get_attr");

  INTERFACE_LOCAL_MPI_Type_get_envelope =
      dlsym(interface_handle, "INTERF_MPI_Type_get_envelope");

  INTERFACE_LOCAL_MPI_Type_get_name =
      dlsym(interface_handle, "INTERF_MPI_Type_get_name");

  INTERFACE_LOCAL_MPI_Type_set_attr =
      dlsym(interface_handle, "INTERF_MPI_Type_set_attr");

  INTERFACE_LOCAL_MPI_Type_set_name =
      dlsym(interface_handle, "INTERF_MPI_Type_set_name");

  INTERFACE_LOCAL_MPI_Type_match_size =
      dlsym(interface_handle, "INTERF_MPI_Type_match_size");

  INTERFACE_LOCAL_MPI_Win_create_keyval =
      dlsym(interface_handle, "INTERF_MPI_Win_create_keyval");

  INTERFACE_LOCAL_MPI_Win_delete_attr =
      dlsym(interface_handle, "INTERF_MPI_Win_delete_attr");

  INTERFACE_LOCAL_MPI_Win_free_keyval =
      dlsym(interface_handle, "INTERF_MPI_Win_free_keyval");

  INTERFACE_LOCAL_MPI_Win_get_attr =
      dlsym(interface_handle, "INTERF_MPI_Win_get_attr");

  INTERFACE_LOCAL_MPI_Win_get_name =
      dlsym(interface_handle, "INTERF_MPI_Win_get_name");

  INTERFACE_LOCAL_MPI_Win_set_name =
      dlsym(interface_handle, "INTERF_MPI_Win_set_name");

  INTERFACE_LOCAL_MPI_Alloc_mem =
      dlsym(interface_handle, "INTERF_MPI_Alloc_mem");

  INTERFACE_LOCAL_MPI_Comm_create_errhandler =
      dlsym(interface_handle, "INTERF_MPI_Comm_create_errhandler");

  INTERFACE_LOCAL_MPI_Comm_get_errhandler =
      dlsym(interface_handle, "INTERF_MPI_Comm_get_errhandler");

  INTERFACE_LOCAL_MPI_Comm_set_errhandler =
      dlsym(interface_handle, "INTERF_MPI_Comm_set_errhandler");

  INTERFACE_LOCAL_MPI_File_get_errhandler =
      dlsym(interface_handle, "INTERF_MPI_File_get_errhandler");

  INTERFACE_LOCAL_MPI_File_set_errhandler =
      dlsym(interface_handle, "INTERF_MPI_File_set_errhandler");

  INTERFACE_LOCAL_MPI_Finalized =
      dlsym(interface_handle, "INTERF_MPI_Finalized");

  INTERFACE_LOCAL_MPI_Free_mem = dlsym(interface_handle, "INTERF_MPI_Free_mem");

  INTERFACE_LOCAL_MPI_Get_address =
      dlsym(interface_handle, "INTERF_MPI_Get_address");

  INTERFACE_LOCAL_MPI_Info_create =
      dlsym(interface_handle, "INTERF_MPI_Info_create");

  INTERFACE_LOCAL_MPI_Info_delete =
      dlsym(interface_handle, "INTERF_MPI_Info_delete");

  INTERFACE_LOCAL_MPI_Info_dup = dlsym(interface_handle, "INTERF_MPI_Info_dup");

  INTERFACE_LOCAL_MPI_Info_free =
      dlsym(interface_handle, "INTERF_MPI_Info_free");

  INTERFACE_LOCAL_MPI_Info_get = dlsym(interface_handle, "INTERF_MPI_Info_get");

  INTERFACE_LOCAL_MPI_Info_get_nkeys =
      dlsym(interface_handle, "INTERF_MPI_Info_get_nkeys");

  INTERFACE_LOCAL_MPI_Info_get_nthkey =
      dlsym(interface_handle, "INTERF_MPI_Info_get_nthkey");

  INTERFACE_LOCAL_MPI_Info_get_valuelen =
      dlsym(interface_handle, "INTERF_MPI_Info_get_valuelen");

  INTERFACE_LOCAL_MPI_Info_set = dlsym(interface_handle, "INTERF_MPI_Info_set");

  INTERFACE_LOCAL_MPI_Request_get_status =
      dlsym(interface_handle, "INTERF_MPI_Request_get_status");

  INTERFACE_LOCAL_MPI_Type_create_hvector =
      dlsym(interface_handle, "INTERF_MPI_Type_create_hvector");

  INTERFACE_LOCAL_MPI_Type_create_resized =
      dlsym(interface_handle, "INTERF_MPI_Type_create_resized");

  INTERFACE_LOCAL_MPI_Type_get_extent =
      dlsym(interface_handle, "INTERF_MPI_Type_get_extent");

  INTERFACE_LOCAL_MPI_Type_get_true_extent =
      dlsym(interface_handle, "INTERF_MPI_Type_get_true_extent");

  INTERFACE_LOCAL_MPI_Win_get_errhandler =
      dlsym(interface_handle, "INTERF_MPI_Win_get_errhandler");

  INTERFACE_LOCAL_MPI_Type_create_f90_integer =
      dlsym(interface_handle, "INTERF_MPI_Type_create_f90_integer");

  INTERFACE_LOCAL_MPI_Type_create_f90_real =
      dlsym(interface_handle, "INTERF_MPI_Type_create_f90_real");

  INTERFACE_LOCAL_MPI_Type_create_f90_complex =
      dlsym(interface_handle, "INTERF_MPI_Type_create_f90_complex");

  INTERFACE_LOCAL_MPI_Reduce_local =
      dlsym(interface_handle, "INTERF_MPI_Reduce_local");

  INTERFACE_LOCAL_MPI_Op_commutative =
      dlsym(interface_handle, "INTERF_MPI_Op_commutative");

  INTERFACE_LOCAL_MPI_Reduce_scatter_block =
      dlsym(interface_handle, "INTERF_MPI_Reduce_scatter_block");

  INTERFACE_LOCAL_MPI_Dist_graph_neighbors_count =
      dlsym(interface_handle, "INTERF_MPI_Dist_graph_neighbors_count");

  INTERFACE_LOCAL_MPI_Improbe = dlsym(interface_handle, "INTERF_MPI_Improbe");

  INTERFACE_LOCAL_MPI_Imrecv = dlsym(interface_handle, "INTERF_MPI_Imrecv");

  INTERFACE_LOCAL_MPI_Mprobe = dlsym(interface_handle, "INTERF_MPI_Mprobe");

  INTERFACE_LOCAL_MPI_Mrecv = dlsym(interface_handle, "INTERF_MPI_Mrecv");

  INTERFACE_LOCAL_MPI_Comm_idup =
      dlsym(interface_handle, "INTERF_MPI_Comm_idup");

  INTERFACE_LOCAL_MPI_Ibarrier = dlsym(interface_handle, "INTERF_MPI_Ibarrier");

  INTERFACE_LOCAL_MPI_Ibcast = dlsym(interface_handle, "INTERF_MPI_Ibcast");

  INTERFACE_LOCAL_MPI_Igather = dlsym(interface_handle, "INTERF_MPI_Igather");

  INTERFACE_LOCAL_MPI_Iscatter = dlsym(interface_handle, "INTERF_MPI_Iscatter");

  INTERFACE_LOCAL_MPI_Iallgather =
      dlsym(interface_handle, "INTERF_MPI_Iallgather");

  INTERFACE_LOCAL_MPI_Ialltoall =
      dlsym(interface_handle, "INTERF_MPI_Ialltoall");

  INTERFACE_LOCAL_MPI_Ireduce = dlsym(interface_handle, "INTERF_MPI_Ireduce");

  INTERFACE_LOCAL_MPI_Iallreduce =
      dlsym(interface_handle, "INTERF_MPI_Iallreduce");

  INTERFACE_LOCAL_MPI_Ireduce_scatter_block =
      dlsym(interface_handle, "INTERF_MPI_Ireduce_scatter_block");

  INTERFACE_LOCAL_MPI_Iscan = dlsym(interface_handle, "INTERF_MPI_Iscan");

  INTERFACE_LOCAL_MPI_Iexscan = dlsym(interface_handle, "INTERF_MPI_Iexscan");

  INTERFACE_LOCAL_MPI_Ineighbor_allgather =
      dlsym(interface_handle, "INTERF_MPI_Ineighbor_allgather");

  INTERFACE_LOCAL_MPI_Ineighbor_alltoall =
      dlsym(interface_handle, "INTERF_MPI_Ineighbor_alltoall");

  INTERFACE_LOCAL_MPI_Neighbor_allgather =
      dlsym(interface_handle, "INTERF_MPI_Neighbor_allgather");

  INTERFACE_LOCAL_MPI_Neighbor_alltoall =
      dlsym(interface_handle, "INTERF_MPI_Neighbor_alltoall");

  INTERFACE_LOCAL_MPI_Comm_split_type =
      dlsym(interface_handle, "INTERF_MPI_Comm_split_type");

  INTERFACE_LOCAL_MPI_Get_elements_x =
      dlsym(interface_handle, "INTERF_MPI_Get_elements_x");

  INTERFACE_LOCAL_MPI_Status_set_elements_x =
      dlsym(interface_handle, "INTERF_MPI_Status_set_elements_x");

  INTERFACE_LOCAL_MPI_Type_get_extent_x =
      dlsym(interface_handle, "INTERF_MPI_Type_get_extent_x");

  INTERFACE_LOCAL_MPI_Type_get_true_extent_x =
      dlsym(interface_handle, "INTERF_MPI_Type_get_true_extent_x");

  INTERFACE_LOCAL_MPI_Type_size_x =
      dlsym(interface_handle, "INTERF_MPI_Type_size_x");

  INTERFACE_LOCAL_MPI_Comm_create_group =
      dlsym(interface_handle, "INTERF_MPI_Comm_create_group");

  INTERFACE_LOCAL_MPI_T_init_thread =
      dlsym(interface_handle, "INTERF_MPI_T_init_thread");

  INTERFACE_LOCAL_MPI_T_enum_get_info =
      dlsym(interface_handle, "INTERF_MPI_T_enum_get_info");

  INTERFACE_LOCAL_MPI_T_enum_get_item =
      dlsym(interface_handle, "INTERF_MPI_T_enum_get_item");

  INTERFACE_LOCAL_MPI_T_cvar_get_num =
      dlsym(interface_handle, "INTERF_MPI_T_cvar_get_num");

  INTERFACE_LOCAL_MPI_T_cvar_get_info =
      dlsym(interface_handle, "INTERF_MPI_T_cvar_get_info");

  INTERFACE_LOCAL_MPI_T_cvar_handle_alloc =
      dlsym(interface_handle, "INTERF_MPI_T_cvar_handle_alloc");

  INTERFACE_LOCAL_MPI_T_cvar_handle_free =
      dlsym(interface_handle, "INTERF_MPI_T_cvar_handle_free");

  INTERFACE_LOCAL_MPI_T_cvar_read =
      dlsym(interface_handle, "INTERF_MPI_T_cvar_read");

  INTERFACE_LOCAL_MPI_T_cvar_write =
      dlsym(interface_handle, "INTERF_MPI_T_cvar_write");

  INTERFACE_LOCAL_MPI_T_pvar_get_num =
      dlsym(interface_handle, "INTERF_MPI_T_pvar_get_num");

  INTERFACE_LOCAL_MPI_T_pvar_get_info =
      dlsym(interface_handle, "INTERF_MPI_T_pvar_get_info");

  INTERFACE_LOCAL_MPI_T_category_get_num =
      dlsym(interface_handle, "INTERF_MPI_T_category_get_num");

  INTERFACE_LOCAL_MPI_T_category_get_info =
      dlsym(interface_handle, "INTERF_MPI_T_category_get_info");

  INTERFACE_LOCAL_MPI_File_open =
      dlsym(interface_handle, "INTERF_MPI_File_open");

  INTERFACE_LOCAL_MPI_File_close =
      dlsym(interface_handle, "INTERF_MPI_File_close");

  INTERFACE_LOCAL_MPI_File_delete =
      dlsym(interface_handle, "INTERF_MPI_File_delete");

  INTERFACE_LOCAL_MPI_File_set_size =
      dlsym(interface_handle, "INTERF_MPI_File_set_size");

  INTERFACE_LOCAL_MPI_File_preallocate =
      dlsym(interface_handle, "INTERF_MPI_File_preallocate");

  INTERFACE_LOCAL_MPI_File_get_size =
      dlsym(interface_handle, "INTERF_MPI_File_get_size");

  INTERFACE_LOCAL_MPI_File_get_group =
      dlsym(interface_handle, "INTERF_MPI_File_get_group");

  INTERFACE_LOCAL_MPI_File_get_amode =
      dlsym(interface_handle, "INTERF_MPI_File_get_amode");

  INTERFACE_LOCAL_MPI_File_set_info =
      dlsym(interface_handle, "INTERF_MPI_File_set_info");

  INTERFACE_LOCAL_MPI_File_get_info =
      dlsym(interface_handle, "INTERF_MPI_File_get_info");

  INTERFACE_LOCAL_MPI_File_set_view =
      dlsym(interface_handle, "INTERF_MPI_File_set_view");

  INTERFACE_LOCAL_MPI_File_get_view =
      dlsym(interface_handle, "INTERF_MPI_File_get_view");

  INTERFACE_LOCAL_MPI_File_read_at =
      dlsym(interface_handle, "INTERF_MPI_File_read_at");

  INTERFACE_LOCAL_MPI_File_read_at_all =
      dlsym(interface_handle, "INTERF_MPI_File_read_at_all");

  INTERFACE_LOCAL_MPI_File_write_at =
      dlsym(interface_handle, "INTERF_MPI_File_write_at");

  INTERFACE_LOCAL_MPI_File_write_at_all =
      dlsym(interface_handle, "INTERF_MPI_File_write_at_all");

  INTERFACE_LOCAL_MPI_File_iread_at =
      dlsym(interface_handle, "INTERF_MPI_File_iread_at");

  INTERFACE_LOCAL_MPI_File_iwrite_at =
      dlsym(interface_handle, "INTERF_MPI_File_iwrite_at");

  INTERFACE_LOCAL_MPI_File_read =
      dlsym(interface_handle, "INTERF_MPI_File_read");

  INTERFACE_LOCAL_MPI_File_read_all =
      dlsym(interface_handle, "INTERF_MPI_File_read_all");

  INTERFACE_LOCAL_MPI_File_write =
      dlsym(interface_handle, "INTERF_MPI_File_write");

  INTERFACE_LOCAL_MPI_File_write_all =
      dlsym(interface_handle, "INTERF_MPI_File_write_all");

  INTERFACE_LOCAL_MPI_File_iread =
      dlsym(interface_handle, "INTERF_MPI_File_iread");

  INTERFACE_LOCAL_MPI_File_iwrite =
      dlsym(interface_handle, "INTERF_MPI_File_iwrite");

  INTERFACE_LOCAL_MPI_File_seek =
      dlsym(interface_handle, "INTERF_MPI_File_seek");

  INTERFACE_LOCAL_MPI_File_get_position =
      dlsym(interface_handle, "INTERF_MPI_File_get_position");

  INTERFACE_LOCAL_MPI_File_get_byte_offset =
      dlsym(interface_handle, "INTERF_MPI_File_get_byte_offset");

  INTERFACE_LOCAL_MPI_File_read_shared =
      dlsym(interface_handle, "INTERF_MPI_File_read_shared");

  INTERFACE_LOCAL_MPI_File_write_shared =
      dlsym(interface_handle, "INTERF_MPI_File_write_shared");

  INTERFACE_LOCAL_MPI_File_iread_shared =
      dlsym(interface_handle, "INTERF_MPI_File_iread_shared");

  INTERFACE_LOCAL_MPI_File_iwrite_shared =
      dlsym(interface_handle, "INTERF_MPI_File_iwrite_shared");

  INTERFACE_LOCAL_MPI_File_read_ordered =
      dlsym(interface_handle, "INTERF_MPI_File_read_ordered");

  INTERFACE_LOCAL_MPI_File_write_ordered =
      dlsym(interface_handle, "INTERF_MPI_File_write_ordered");

  INTERFACE_LOCAL_MPI_File_seek_shared =
      dlsym(interface_handle, "INTERF_MPI_File_seek_shared");

  INTERFACE_LOCAL_MPI_File_get_position_shared =
      dlsym(interface_handle, "INTERF_MPI_File_get_position_shared");

  INTERFACE_LOCAL_MPI_File_read_at_all_begin =
      dlsym(interface_handle, "INTERF_MPI_File_read_at_all_begin");

  INTERFACE_LOCAL_MPI_File_read_at_all_end =
      dlsym(interface_handle, "INTERF_MPI_File_read_at_all_end");

  INTERFACE_LOCAL_MPI_File_write_at_all_begin =
      dlsym(interface_handle, "INTERF_MPI_File_write_at_all_begin");

  INTERFACE_LOCAL_MPI_File_write_at_all_end =
      dlsym(interface_handle, "INTERF_MPI_File_write_at_all_end");

  INTERFACE_LOCAL_MPI_File_read_all_begin =
      dlsym(interface_handle, "INTERF_MPI_File_read_all_begin");

  INTERFACE_LOCAL_MPI_File_read_all_end =
      dlsym(interface_handle, "INTERF_MPI_File_read_all_end");

  INTERFACE_LOCAL_MPI_File_write_all_begin =
      dlsym(interface_handle, "INTERF_MPI_File_write_all_begin");

  INTERFACE_LOCAL_MPI_File_write_all_end =
      dlsym(interface_handle, "INTERF_MPI_File_write_all_end");

  INTERFACE_LOCAL_MPI_File_read_ordered_begin =
      dlsym(interface_handle, "INTERF_MPI_File_read_ordered_begin");

  INTERFACE_LOCAL_MPI_File_read_ordered_end =
      dlsym(interface_handle, "INTERF_MPI_File_read_ordered_end");

  INTERFACE_LOCAL_MPI_File_write_ordered_begin =
      dlsym(interface_handle, "INTERF_MPI_File_write_ordered_begin");

  INTERFACE_LOCAL_MPI_File_write_ordered_end =
      dlsym(interface_handle, "INTERF_MPI_File_write_ordered_end");

  INTERFACE_LOCAL_MPI_File_get_type_extent =
      dlsym(interface_handle, "INTERF_MPI_File_get_type_extent");

  INTERFACE_LOCAL_MPI_Register_datarep =
      dlsym(interface_handle, "INTERF_MPI_Register_datarep");

  INTERFACE_LOCAL_MPI_File_set_atomicity =
      dlsym(interface_handle, "INTERF_MPI_File_set_atomicity");

  INTERFACE_LOCAL_MPI_File_get_atomicity =
      dlsym(interface_handle, "INTERF_MPI_File_get_atomicity");

  INTERFACE_LOCAL_MPI_File_sync =
      dlsym(interface_handle, "INTERF_MPI_File_sync");

  INTERFACE_LOCAL_MPI_T_finalize =
      dlsym(interface_handle, "INTERF_MPI_T_finalize");

  INTERFACE_LOCAL_MPI_Wtime = dlsym(interface_handle, "INTERF_MPI_Wtime");

  INTERFACE_LOCAL_MPI_Wtick = dlsym(interface_handle, "INTERF_MPI_Wtick");

  INTERFACE_LOCAL_MPI_Finalize = dlsym(interface_handle, "INTERF_MPI_Finalize");

  INTERFACE_LOCAL_MPI_Waitany = dlsym(interface_handle, "INTERF_MPI_Waitany");

  INTERFACE_LOCAL_MPI_Testany = dlsym(interface_handle, "INTERF_MPI_Testany");

  INTERFACE_LOCAL_MPI_Waitall = dlsym(interface_handle, "INTERF_MPI_Waitall");

  INTERFACE_LOCAL_MPI_Testall = dlsym(interface_handle, "INTERF_MPI_Testall");

  INTERFACE_LOCAL_MPI_Waitsome = dlsym(interface_handle, "INTERF_MPI_Waitsome");

  INTERFACE_LOCAL_MPI_Testsome = dlsym(interface_handle, "INTERF_MPI_Testsome");

  INTERFACE_LOCAL_MPI_Startall = dlsym(interface_handle, "INTERF_MPI_Startall");

  INTERFACE_LOCAL_MPI_Alltoallw =
      dlsym(interface_handle, "INTERF_MPI_Alltoallw");

  INTERFACE_LOCAL_MPI_Reduce_scatter =
      dlsym(interface_handle, "INTERF_MPI_Reduce_scatter");

  INTERFACE_LOCAL_MPI_Group_translate_ranks =
      dlsym(interface_handle, "INTERF_MPI_Group_translate_ranks");

  INTERFACE_LOCAL_MPI_Group_incl =
      dlsym(interface_handle, "INTERF_MPI_Group_incl");

  INTERFACE_LOCAL_MPI_Group_excl =
      dlsym(interface_handle, "INTERF_MPI_Group_excl");

  INTERFACE_LOCAL_MPI_Group_range_incl =
      dlsym(interface_handle, "INTERF_MPI_Group_range_incl");

  INTERFACE_LOCAL_MPI_Group_range_excl =
      dlsym(interface_handle, "INTERF_MPI_Group_range_excl");

  INTERFACE_LOCAL_MPI_Cart_create =
      dlsym(interface_handle, "INTERF_MPI_Cart_create");

  INTERFACE_LOCAL_MPI_Dims_create =
      dlsym(interface_handle, "INTERF_MPI_Dims_create");

  INTERFACE_LOCAL_MPI_Graph_create =
      dlsym(interface_handle, "INTERF_MPI_Graph_create");

  INTERFACE_LOCAL_MPI_Graph_get =
      dlsym(interface_handle, "INTERF_MPI_Graph_get");

  INTERFACE_LOCAL_MPI_Cart_get = dlsym(interface_handle, "INTERF_MPI_Cart_get");

  INTERFACE_LOCAL_MPI_Cart_rank =
      dlsym(interface_handle, "INTERF_MPI_Cart_rank");

  INTERFACE_LOCAL_MPI_Cart_coords =
      dlsym(interface_handle, "INTERF_MPI_Cart_coords");

  INTERFACE_LOCAL_MPI_Graph_neighbors =
      dlsym(interface_handle, "INTERF_MPI_Graph_neighbors");

  INTERFACE_LOCAL_MPI_Cart_sub = dlsym(interface_handle, "INTERF_MPI_Cart_sub");

  INTERFACE_LOCAL_MPI_Cart_map = dlsym(interface_handle, "INTERF_MPI_Cart_map");

  INTERFACE_LOCAL_MPI_Graph_map =
      dlsym(interface_handle, "INTERF_MPI_Graph_map");

  INTERFACE_LOCAL_MPI_Comm_spawn =
      dlsym(interface_handle, "INTERF_MPI_Comm_spawn");

  INTERFACE_LOCAL_MPI_Comm_spawn_multiple =
      dlsym(interface_handle, "INTERF_MPI_Comm_spawn_multiple");

  INTERFACE_LOCAL_MPI_Type_get_contents =
      dlsym(interface_handle, "INTERF_MPI_Type_get_contents");

  INTERFACE_LOCAL_MPI_Pack_external =
      dlsym(interface_handle, "INTERF_MPI_Pack_external");

  INTERFACE_LOCAL_MPI_Pack_external_size =
      dlsym(interface_handle, "INTERF_MPI_Pack_external_size");

  INTERFACE_LOCAL_MPI_Type_create_darray =
      dlsym(interface_handle, "INTERF_MPI_Type_create_darray");

  INTERFACE_LOCAL_MPI_Type_create_hindexed =
      dlsym(interface_handle, "INTERF_MPI_Type_create_hindexed");

  INTERFACE_LOCAL_MPI_Type_create_indexed_block =
      dlsym(interface_handle, "INTERF_MPI_Type_create_indexed_block");

  INTERFACE_LOCAL_MPI_Type_create_hindexed_block =
      dlsym(interface_handle, "INTERF_MPI_Type_create_hindexed_block");

  INTERFACE_LOCAL_MPI_Type_create_struct =
      dlsym(interface_handle, "INTERF_MPI_Type_create_struct");

  INTERFACE_LOCAL_MPI_Type_create_subarray =
      dlsym(interface_handle, "INTERF_MPI_Type_create_subarray");

  INTERFACE_LOCAL_MPI_Unpack_external =
      dlsym(interface_handle, "INTERF_MPI_Unpack_external");

  INTERFACE_LOCAL_MPI_Dist_graph_create_adjacent =
      dlsym(interface_handle, "INTERF_MPI_Dist_graph_create_adjacent");

  INTERFACE_LOCAL_MPI_Dist_graph_create =
      dlsym(interface_handle, "INTERF_MPI_Dist_graph_create");

  INTERFACE_LOCAL_MPI_Dist_graph_neighbors =
      dlsym(interface_handle, "INTERF_MPI_Dist_graph_neighbors");

  INTERFACE_LOCAL_MPI_Igatherv = dlsym(interface_handle, "INTERF_MPI_Igatherv");

  INTERFACE_LOCAL_MPI_Iscatterv =
      dlsym(interface_handle, "INTERF_MPI_Iscatterv");

  INTERFACE_LOCAL_MPI_Iallgatherv =
      dlsym(interface_handle, "INTERF_MPI_Iallgatherv");

  INTERFACE_LOCAL_MPI_Ialltoallv =
      dlsym(interface_handle, "INTERF_MPI_Ialltoallv");

  INTERFACE_LOCAL_MPI_Ialltoallw =
      dlsym(interface_handle, "INTERF_MPI_Ialltoallw");

  INTERFACE_LOCAL_MPI_Ireduce_scatter =
      dlsym(interface_handle, "INTERF_MPI_Ireduce_scatter");

  INTERFACE_LOCAL_MPI_Ineighbor_allgatherv =
      dlsym(interface_handle, "INTERF_MPI_Ineighbor_allgatherv");

  INTERFACE_LOCAL_MPI_Ineighbor_alltoallv =
      dlsym(interface_handle, "INTERF_MPI_Ineighbor_alltoallv");

  INTERFACE_LOCAL_MPI_Ineighbor_alltoallw =
      dlsym(interface_handle, "INTERF_MPI_Ineighbor_alltoallw");

  INTERFACE_LOCAL_MPI_Neighbor_allgatherv =
      dlsym(interface_handle, "INTERF_MPI_Neighbor_allgatherv");

  INTERFACE_LOCAL_MPI_Neighbor_alltoallv =
      dlsym(interface_handle, "INTERF_MPI_Neighbor_alltoallv");

  INTERFACE_LOCAL_MPI_Neighbor_alltoallw =
      dlsym(interface_handle, "INTERF_MPI_Neighbor_alltoallw");

  INTERFACE_LOCAL_MPI_T_category_get_cvars =
      dlsym(interface_handle, "INTERF_MPI_T_category_get_cvars");

  INTERFACE_LOCAL_MPI_T_category_get_pvars =
      dlsym(interface_handle, "INTERF_MPI_T_category_get_pvars");

  INTERFACE_LOCAL_MPI_T_category_get_categories =
      dlsym(interface_handle, "INTERF_MPI_T_category_get_categories");

  INTERFACE_LOCAL_MPI_File_iwrite_all =
      dlsym(interface_handle, "INTERF_MPI_File_iwrite_all");

  INTERFACE_LOCAL_MPI_File_iwrite_at_all =
      dlsym(interface_handle, "INTERF_MPI_File_iwrite_at_all");

  INTERFACE_LOCAL_MPI_T_category_get_index =
      dlsym(interface_handle, "INTERF_MPI_T_category_get_index");

  INTERFACE_LOCAL_MPI_T_cvar_get_index =
      dlsym(interface_handle, "INTERF_MPI_T_cvar_get_index");

  INTERFACE_LOCAL_MPI_T_pvar_get_index =
      dlsym(interface_handle, "INTERF_MPI_T_pvar_get_index");

  INTERFACE_LOCAL_MPI_Aint_add = dlsym(interface_handle, "INTERF_MPI_Aint_add");

  INTERFACE_LOCAL_MPI_Aint_diff =
      dlsym(interface_handle, "INTERF_MPI_Aint_diff");

  INTERFACE_LOCAL_MPI_File_iread_all =
      dlsym(interface_handle, "INTERF_MPI_File_iread_all");

  INTERFACE_LOCAL_MPI_File_iread_at_all =
      dlsym(interface_handle, "INTERF_MPI_File_iread_at_all");

  INTERFACE_LOCAL_MPI_T_category_changed =
      dlsym(interface_handle, "INTERF_MPI_T_category_changed");

  INTERFACE_LOCAL_MPIX_query_cuda_support =
      dlsym(interface_handle, "INTERF_MPIX_query_cuda_support");

#endif /* WI4MPI_STATIC */
  if (wi4mpi__init__F == 0)
    wrapper_interface_f();
}

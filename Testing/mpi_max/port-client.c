#include <stdio.h>
#include "mpi.h"
#define MAX_DATA 1
int main(int argc, char **argv) {
  MPI_Comm server;
  double buf[MAX_DATA] = { 3.14};
  char port_name[MPI_MAX_PORT_NAME];
  MPI_Init(&argc, &argv);
  printf("starting client\n");
    MPI_Barrier(MPI_COMM_WORLD);
  MPI_Lookup_name("wii", MPI_INFO_NULL, port_name);
  MPI_Comm_connect(port_name, MPI_INFO_NULL, 0, MPI_COMM_SELF, &server);
  MPI_Send(buf, 1, MPI_DOUBLE, 0, 1, server);
  MPI_Comm_disconnect(&server);
  MPI_Finalize();
  return 0;
}

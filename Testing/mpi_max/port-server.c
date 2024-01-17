#include <stdio.h>
#include "mpi.h"
#define MAX_DATA 1
int main(int argc, char *argv[]) {
    MPI_Comm client;
    MPI_Status status;
    char port_name[MPI_MAX_PORT_NAME];
    double buf[MAX_DATA];
    int size, again;
    MPI_Init(&argc, &argv);
    MPI_Open_port(MPI_INFO_NULL, port_name);
    printf("server available at %s\n", port_name);
    MPI_Publish_name("wii", MPI_INFO_NULL, port_name);
    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Comm_accept(port_name, MPI_INFO_NULL, 0, MPI_COMM_SELF, &client);
    MPI_Recv(buf, MAX_DATA, MPI_DOUBLE, MPI_ANY_SOURCE, MPI_ANY_TAG, client,
            &status);
    printf("server received %f\n", *buf);
    MPI_Comm_disconnect(&client);
    MPI_Unpublish_name("wii", MPI_INFO_NULL, port_name);
    MPI_Close_port(port_name);
    MPI_Finalize();
    return 0;
}

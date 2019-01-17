#include <mpi.h>

int main (int argc, char **argv) {

    MPI_Init(&argc, &argv);

    const char *filename = "test.bin";
    MPI_File fh;

    MPI_File_open(MPI_COMM_SELF, filename, MPI_MODE_RDWR, MPI_INFO_NULL, &fh);
    MPI_File_close(&fh);

    MPI_Finalize();
}

#include <stdio.h>
#include "mpi.h"
int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);

    MPI_File testfile;
    MPI_File_open(MPI_COMM_WORLD, "test", MPI_MODE_RDWR|MPI_MODE_CREATE, MPI_INFO_NULL, &testfile);
    MPI_Offset disp;
    MPI_Datatype etype;
    MPI_Datatype ftype;
    char datarep[MPI_MAX_DATAREP_STRING];
    MPI_File_get_view(testfile, &disp, &etype, &ftype, datarep);
    printf("get view %s\n", datarep);
    MPI_File_set_view(testfile, disp, etype, ftype, "external32", MPI_INFO_NULL);
    MPI_File_get_view(testfile, &disp, &etype, &ftype, datarep);
    printf("get view %s\n", datarep);
    MPI_File_close(&testfile);

    MPI_Finalize();
    return 0;
}

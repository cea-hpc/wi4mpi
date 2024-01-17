#include <stdio.h>
#include "mpi.h"
int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);

    char proc_name[MPI_MAX_PROCESSOR_NAME];
    char lib_ver[MPI_MAX_LIBRARY_VERSION_STRING];
    char error_string[MPI_MAX_ERROR_STRING];
    char comm_string[MPI_MAX_OBJECT_NAME];
    char type_string[MPI_MAX_OBJECT_NAME];
    char win_string[MPI_MAX_OBJECT_NAME];
    int errcode = MPI_ERR_NAME;
    int len;


    MPI_Get_processor_name(proc_name, &len);
    printf("procname: %d %s\n", len, proc_name);
    MPI_Get_library_version(lib_ver, &len);
    printf("libver: %d %s\n", len, lib_ver);

    MPI_Error_string(errcode, error_string, &len);
    printf("error: %d %s\n", len, error_string);
    int testerrclass;
    MPI_Add_error_class(&testerrclass);
    int testerrcode;
    MPI_Add_error_code(testerrclass, &testerrcode);
    MPI_Add_error_string(testerrcode, "mouhaha");
    MPI_Error_string(testerrcode, error_string, &len);
    printf("custom error: %d %s\n", len, error_string);

    MPI_Comm testcomm;
    MPI_Comm_dup(MPI_COMM_WORLD, &testcomm);
    MPI_Comm_set_name(testcomm, "my comm");
    MPI_Comm_get_name(testcomm, comm_string, &len);
    printf("comm name: %d %s\n", len, comm_string);
    MPI_Comm_free(&testcomm);

    MPI_Datatype testtype;
    MPI_Type_contiguous(3, MPI_INTEGER, &testtype);
    MPI_Type_commit(&testtype);
    MPI_Type_set_name(testtype, "3 integer");
    MPI_Type_get_name(testtype, type_string, &len);
    printf("type name: %d %s\n", len, type_string);
    MPI_Type_free(&testtype);

    MPI_Win mywin;
    MPI_Win_create(lib_ver, 3, 1, MPI_INFO_NULL, MPI_COMM_WORLD, &mywin);
    MPI_Win_set_name(mywin, "test window");
    MPI_Win_get_name(mywin, win_string, &len);
    printf("win name: %d %s\n", len, win_string);
    MPI_Win_free(&mywin);

    MPI_Finalize();
    return 0;
}

#include <stdio.h>
#include "mpi.h"
int main(int argc, char *argv[])
{
    MPI_Init(&argc, &argv);
    MPI_Info info;
    MPI_Info_create(&info);
    MPI_Info_set(info, "mama", "mia");
    int vallen, flag;
    char val[250];
    char key[MPI_MAX_INFO_KEY];
    MPI_Info_get_nthkey(info, 0, key);
    printf("get nth: %s\n", key);
    MPI_Info_get_valuelen(info, "mama", &vallen, &flag);
    printf("get valuelen: %d\n", vallen);
    MPI_Info_get(info, "mama", 249, val, &flag);
    printf("get: %s\n", val);
    MPI_Info_delete(info, "mama");
    MPI_Finalize();
    return 0;
}

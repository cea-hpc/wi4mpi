 #include <dlfcn.h>
#define __GNU_SOURCE
#include "run_mpi.h"
#include <stdlib.h>
int (*LOCAL_MPI_Comm_c2f)   (R_MPI_Comm);
int (*LOCAL_MPI_File_c2f)   (R_MPI_File);
int (*LOCAL_MPI_Group_c2f)  (R_MPI_Group);
int (*LOCAL_MPI_Info_c2f)   (R_MPI_Info);
int (*LOCAL_MPI_Message_c2f)(R_MPI_Message);
int (*LOCAL_MPI_Op_c2f)     (R_MPI_Op);
int (*LOCAL_MPI_Type_c2f)   (R_MPI_Datatype);
int (*LOCAL_MPI_Win_c2f)    (R_MPI_Win);
R_MPI_Comm     (*LOCAL_MPI_Comm_f2c)   (int);
R_MPI_File     (*LOCAL_MPI_File_f2c)   (int);
R_MPI_Group    (*LOCAL_MPI_Group_f2c)  (int);
R_MPI_Info     (*LOCAL_MPI_Info_f2c)   (int);
R_MPI_Message  (*LOCAL_MPI_Message_f2c)(int);
R_MPI_Op       (*LOCAL_MPI_Op_f2c)     (int);
R_MPI_Datatype     (*LOCAL_MPI_Type_f2c)   (int);
R_MPI_Win      (*LOCAL_MPI_Win_f2c)    (int);
int wi4mpi_default_c2f(void*a)
{
    return (int)(a);
}
void *wi4mpi_default_f2c(int a)
{
    return (void *)(a);
}
void init_f2c(void *lib_handle)
{
#ifndef R_MPI_Comm_c2f
LOCAL_MPI_Comm_c2f=dlsym(lib_handle,"PMPI_Comm_c2f");
if(!LOCAL_MPI_Comm_c2f) exit(1);
#endif
#ifndef R_MPI_Comm_f2c
LOCAL_MPI_Comm_f2c=dlsym(lib_handle,"PMPI_Comm_f2c");
if(!LOCAL_MPI_Comm_f2c) exit(1);
#endif
#ifndef R_MPI_File_c2f
LOCAL_MPI_File_c2f=dlsym(lib_handle,"PMPI_File_c2f");
if(!LOCAL_MPI_File_c2f) exit(1);
#endif
#ifndef R_MPI_File_f2c
LOCAL_MPI_File_f2c=dlsym(lib_handle,"PMPI_File_f2c");
if(!LOCAL_MPI_File_f2c) exit(1);
#endif
}


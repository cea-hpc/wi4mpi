int A_MPI_Comm_set_errhandler(A_MPI_Comm comm,A_MPI_Errhandler errhandler)
{
#ifdef DEBUG
printf("entre : A_MPI_Comm_set_errhandler\n");
#endif
return  A_MPI_Errhandler_set(comm,errhandler);
}
int R_MPI_Comm_set_errhandler(R_MPI_Comm comm,R_MPI_Errhandler errhandler)
{
#ifdef DEBUG
printf("entre : R_MPI_Comm_set_errhandler\n");
#endif
int ret_tmp= LOCAL_MPI_Comm_set_errhandler( comm, errhandler);
#ifdef DEBUG
printf("sort : R_MPI_Comm_set_errhandler\n");
#endif
return ret_tmp;
}

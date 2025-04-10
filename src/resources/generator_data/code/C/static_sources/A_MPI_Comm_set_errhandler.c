int A_MPI_Comm_set_errhandler(A_MPI_Comm comm,A_MPI_Errhandler errhandler)
{
#ifdef DEBUG
printf("input: A_MPI_Comm_set_errhandler\n");
#endif
return  A_MPI_Errhandler_set(comm,errhandler);
}

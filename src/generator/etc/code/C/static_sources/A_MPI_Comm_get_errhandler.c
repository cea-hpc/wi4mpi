int A_MPI_Comm_get_errhandler(A_MPI_Comm comm,A_MPI_Errhandler * errhandler)
{
#ifdef DEBUG
printf("entre : A_MPI_Comm_get_errhandler\n");
#endif
return A_MPI_Errhandler_get(comm,errhandler);
}

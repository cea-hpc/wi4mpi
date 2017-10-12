int A_MPI_Comm_create_errhandler(A_MPI_Comm_errhandler_function * comm_errhandler_fn,A_MPI_Errhandler * errhandler)
{
#ifdef DEBUG
printf("entre : A_MPI_Comm_create_errhandler\n");
#endif
return A_MPI_Errhandler_create(comm_errhandler_fn,errhandler);
#ifdef DEBUG
printf("sort : A_MPI_Comm_create_errhandler\n");
#endif
//return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Comm_create_errhandler(R_MPI_Comm_errhandler_function * comm_errhandler_fn,R_MPI_Errhandler * errhandler)
{
#ifdef DEBUG
printf("entre : R_MPI_Comm_create_errhandler\n");
#endif
int ret_tmp= LOCAL_MPI_Comm_create_errhandler( comm_errhandler_fn, errhandler);
#ifdef DEBUG
printf("sort : R_MPI_Comm_create_errhandler\n");
#endif
return ret_tmp;
}

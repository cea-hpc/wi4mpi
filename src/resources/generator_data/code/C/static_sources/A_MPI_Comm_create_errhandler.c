int A_MPI_Comm_create_errhandler(A_MPI_Comm_errhandler_function * comm_errhandler_fn,A_MPI_Errhandler * errhandler)
{
#ifdef DEBUG
printf("input: A_MPI_Comm_create_errhandler\n");
#endif
return A_MPI_Errhandler_create(comm_errhandler_fn,errhandler);
#ifdef DEBUG
printf("output: A_MPI_Comm_create_errhandler\n");
#endif
//return error_code_conv_r2a(ret_tmp);
}

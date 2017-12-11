int A_MPI_Errhandler_free(A_MPI_Errhandler * errhandler)
{
#ifdef DEBUG
printf("entre : A_MPI_Errhandler_free\n");
#endif
in_w=1;

R_MPI_Errhandler  errhandler_ltmp;
R_MPI_Errhandler * errhandler_tmp=&errhandler_ltmp;
errhandler_conv_a2r(errhandler,errhandler_tmp);
int ret_tmp= LOCAL_MPI_Errhandler_free( errhandler_tmp);
/*if(ret_tmp == R_MPI_SUCCESS){
errhandler_del(errhandler,errhandler_tmp);
}*/
*errhandler=A_MPI_ERRHANDLER_NULL;
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Errhandler_free\n");
#endif
return error_code_conv_r2a(ret_tmp);
}

int R_MPI_Errhandler_free(R_MPI_Errhandler * errhandler)
{
#ifdef DEBUG
printf("entre : R_MPI_Errhandler_free\n");
#endif
int ret_tmp= LOCAL_MPI_Errhandler_free( errhandler);
#ifdef DEBUG
printf("sort : R_MPI_Errhandler_free\n");
#endif
return ret_tmp;
}

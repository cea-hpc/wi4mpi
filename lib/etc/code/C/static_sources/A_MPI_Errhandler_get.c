int A_MPI_Errhandler_get(A_MPI_Comm comm,A_MPI_Errhandler * errhandler)
{
#ifdef DEBUG
printf("entre : A_MPI_Errhandler_get\n");
#endif
in_w=1;

    errhandler_locks_ac();
R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
R_MPI_Errhandler  errhandler_ltmp;
R_MPI_Errhandler * errhandler_tmp=&errhandler_ltmp;
int ret_tmp= LOCAL_MPI_Errhandler_get( comm_tmp, errhandler_tmp);
if(ret_tmp == R_MPI_SUCCESS){
//errhandler_translation_get_key_from_value(*errhandler_tmp,errhandler);
if(errhandler_ltmp!=R_MPI_ERRORS_ARE_FATAL&&errhandler_ltmp!=R_MPI_ERRORS_RETURN){
int flg;
R_MPI_Comm_get_attr(comm_tmp,WI4MPI_errhandler_key,&ptr_handler_fn,&flg);
errhandler_ptr_conv_r2a(&errhandler,&errhandler_tmp);
}else
    *errhandler=(errhandler_ltmp!=R_MPI_ERRORS_ARE_FATAL?A_MPI_ERRORS_RETURN:A_MPI_ERRORS_ARE_FATAL);
}else
*errhandler=A_MPI_ERRHANDLER_NULL;
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Errhandler_get\n");
#endif
    errhandler_locks_re();
return error_code_conv_r2a(ret_tmp);
}

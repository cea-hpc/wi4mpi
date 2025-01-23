int interndel_fn(R_MPI_Comm c, int k, void *v, void *e) {                      
  return R_MPI_SUCCESS;                                                        
}                                                                              
int interndup_fn(R_MPI_Comm c, int k, void *e, void *vi, void *vo, int *flag) {
  *flag = 1;                                                                   
  *((void **)vo) = vi;                                                         
  return R_MPI_SUCCESS;                                                        
}                                                                              
int A_MPI_Errhandler_set(A_MPI_Comm comm,A_MPI_Errhandler errhandler)
{
#ifdef DEBUG
printf("entre : A_MPI_Errhandler_set\n");
#endif
in_w=1;

errhandler_locks_ac();
R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
A_MPI_Handler_function *ptr_errhandler_func;
R_MPI_Errhandler errhandler_tmp;

if(errhandler==A_MPI_ERRORS_ARE_FATAL)
    errhandler_tmp=R_MPI_ERRORS_ARE_FATAL;
else if(errhandler==A_MPI_ERRORS_RETURN)
    errhandler_tmp=R_MPI_ERRORS_RETURN;
else
    errhandler_conv_a2r(&errhandler,&errhandler_tmp);

int ret_tmp= LOCAL_MPI_Errhandler_set( comm_tmp, errhandler_tmp);
if(!errhandler_translation_is_const(errhandler)){
//A_MPI_Handler_function* ptr_errhandler_func;
if(WI4MPI_errhandler_key==R_MPI_KEYVAL_INVALID)
{
    R_MPI_Comm_create_keyval(&interndup_fn,&interndel_fn,&WI4MPI_errhandler_key,NULL);
}
errhandler_fn_translation_get(errhandler, &ptr_errhandler_func);
//printf("coucou %p %p\n",errhandler,ptr_errhandler_func);
//communicator_fn_translation_update(comm, ptr_errhandler_func);
R_MPI_Comm_set_attr(comm_tmp,WI4MPI_errhandler_key,ptr_errhandler_func);
}
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Errhandler_set\n");
#endif
    errhandler_locks_re();
return error_code_conv_r2a(ret_tmp);
}


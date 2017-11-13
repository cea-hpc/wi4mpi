void  (*_LOCAL_MPI_Comm_create_errhandler)(void *,int *,int *);

void  A_f_MPI_Comm_create_errhandler(void * comm_errhandler_fn,int * errhandler,int * ret)
{
/*#ifdef DEBUG
printf("entre : A_f_MPI_Comm_create_errhandler\n");
#endif
in_w=1;
int  ret_tmp=0;

void *comm_errhandler_fn_tmp=comm_errhandler_fn;
int errhandler_tmp;
handler_fct_ptr_conv_a2r(&comm_errhandler_fn,&comm_errhandler_fn_tmp);
 _LOCAL_MPI_Comm_create_errhandler(comm_errhandler_fn_tmp, &errhandler_tmp, &ret_tmp);
if(ret_tmp==R_f_MPI_SUCCESS)errhandler_converter_r2a(errhandler,&errhandler_tmp);
errhandler_f_fn_translation_update(errhandler_tmp,comm_errhandler_fn);
error_r2a(ret,&ret_tmp);

in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Comm_create_errhandler\n");
#endif
*/
    return A_f_MPI_Errhandler_create( comm_errhandler_fn,errhandler,ret);
}

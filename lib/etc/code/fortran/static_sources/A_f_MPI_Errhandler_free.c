void  (*_LOCAL_MPI_Errhandler_free)(int *,int *);

void  A_f_MPI_Errhandler_free(int * errhandler,int * ret)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Errhandler_free\n");
#endif
/*in_w=1;
int  ret_tmp=0;

errhandler_converter_a2r(errhandler,&errhandler_tmp);
errhandler_f_fn_translation_del(errhandler_tmp);
 _LOCAL_MPI_Errhandler_free( &errhandler_tmp, &ret_tmp);
if(ret_tmp==R_f_MPI_SUCCESS){
errhandler_f_fn_translation_del(errhandler_tmp);
errhandler_converter_r2a(errhandler,&errhandler_tmp);


}
error_r2a(ret,&ret_tmp);

in_w=0;*/
A_MPI_Errhandler errhandler_tmp;
if(*errhandler!=0)
    errhandler_tmp=(A_MPI_Errhandler)*errhandler;
else
    errhandler_tmp=A_MPI_ERRHANDLER_NULL;
*ret=A_MPI_Errhandler_free( &errhandler_tmp);
if(*errhandler!=0)
    *errhandler=(int)errhandler_tmp;
#ifdef DEBUG
printf("sort : A_f_MPI_Errhandler_free\n");
#endif
}

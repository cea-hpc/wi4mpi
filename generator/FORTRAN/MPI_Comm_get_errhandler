void  (*_LOCAL_MPI_Comm_get_errhandler)(int *,int *,int *);

void  A_f_MPI_Comm_get_errhandler(int * comm,int * errhandler,int * ret)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Comm_get_errhandler\n");
#endif
/*in_w=1;
int  ret_tmp=0;

int comm_tmp;
int errhandler_tmp;
comm_a2r(comm,&comm_tmp);
 _LOCAL_MPI_Comm_get_errhandler( &comm_tmp, &errhandler_tmp, &ret_tmp);
if(ret_tmp==R_f_MPI_SUCCESS)errhandler_converter_r2a(errhandler,&errhandler_tmp);
error_r2a(ret,&ret_tmp);

in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Comm_get_errhandler\n");
#endif
*/
    return A_f_MPI_Errhandler_get(comm,errhandler,ret); 
}

void  (*_LOCAL_MPI_Errhandler_get)(int *,int *,int *);

void  A_f_MPI_Errhandler_get(int * comm,int * errhandler,int * ret)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Errhandler_get\n");
#endif
/*in_w=1;
int  ret_tmp=0;

int comm_tmp;
int errhandler_tmp;
comm_a2r(comm,&comm_tmp);
 _LOCAL_MPI_Errhandler_get( &comm_tmp, &errhandler_tmp, &ret_tmp);
if(ret_tmp==R_f_MPI_SUCCESS)errhandler_converter_r2a(errhandler,&errhandler_tmp);
error_r2a(ret,&ret_tmp);

in_w=0;
*/

A_MPI_Comm ct=A_MPI_Comm_f2c(*comm);
A_MPI_Errhandler ht=(A_MPI_Errhandler)*errhandler;
*ret=A_MPI_Errhandler_get(ct,&ht);
if(*ret==A_f_MPI_SUCCESS)
    *errhandler=A_MPI_Errhandler_c2f(ht);
    else
    *errhandler=A_f_MPI_ERRORS_ARE_FATAL;
#ifdef DEBUG
printf("sort : A_f_MPI_Errhandler_get\n");
#endif
}

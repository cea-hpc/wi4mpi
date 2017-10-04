void  (*_LOCAL_MPI_Errhandler_set)(int *,int *,int *);
void  A_f_MPI_Errhandler_set(int * comm,int * errhandler,int * ret)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Errhandler_set\n");
#endif
/*in_w=1;
int  ret_tmp=0;

int comm_tmp;
int errhandler_tmp;
comm_a2r(comm,&comm_tmp);
errhandler_converter_a2r(errhandler,&errhandler_tmp);
 _LOCAL_MPI_Errhandler_set( &comm_tmp, &errhandler_tmp, &ret_tmp);
errhandler_set_func(comm_tmp,errhandler_tmp);
error_r2a(ret,&ret_tmp);

in_w=0;
*/
A_MPI_Comm ct=A_MPI_Comm_f2c(*comm);
//printf("%d\n",ct);
A_MPI_Errhandler ht=A_MPI_Errhandler_f2c(*errhandler);
*ret=A_MPI_Errhandler_set(ct,ht);
#ifdef DEBUG
printf("sort : A_f_MPI_Errhandler_set\n %d",*errhandler);
#endif
}

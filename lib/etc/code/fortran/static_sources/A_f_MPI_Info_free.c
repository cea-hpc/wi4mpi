void  (*_LOCAL_MPI_Info_free)(int *,int *);

void  A_f_MPI_Info_free(int * info,int * ret)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Info_free\n");
#endif
in_w=1;
int  ret_tmp=0;

int info_tmp;
info_a2r(info,&info_tmp);
 _LOCAL_MPI_Info_free( &info_tmp, &ret_tmp);
if(ret_tmp==R_f_MPI_SUCCESS)info_r2au(info,&info_tmp);
error_r2a(ret,&ret_tmp);

in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Info_free\n");
#endif
}

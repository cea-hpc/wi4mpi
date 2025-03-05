void  A_f_MPI_Info_delete(int * info,char * key,int * ret,fort_string_length keylen)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Info_delete\n");
#endif
in_w=1;

int  ret_tmp=0;
char key_tmp[R_MPI_MAX_INFO_KEY-1];
fstring_max_conv_a2r(key, key_tmp, keylen, R_MPI_MAX_INFO_KEY-1, true);

int info_tmp;
info_a2r(info,&info_tmp);
 LOCAL_f_MPI_Info_delete( &info_tmp, key_tmp, &ret_tmp,R_MPI_MAX_INFO_KEY-1);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Info_delete\n");
#endif

}


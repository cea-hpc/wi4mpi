void  A_f_MPI_Info_get_nthkey(int * info,int * n,char * key,int * ret,fort_string_length keylen)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Info_get_nthkey\n");
#endif
in_w=1;


int  ret_tmp=0;

int info_tmp;
char key_tmp[R_MPI_MAX_INFO_KEY-1];
info_a2r(info,&info_tmp);
 LOCAL_f_MPI_Info_get_nthkey( &info_tmp, n, key_tmp, &ret_tmp,R_MPI_MAX_INFO_KEY-1);
 fstring_max_conv_r2a(key, key_tmp, keylen, R_MPI_MAX_INFO_KEY-1);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Info_get_nthkey\n");
#endif

}


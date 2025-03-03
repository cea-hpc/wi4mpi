void  A_f_MPI_Info_get_valuelen(int * info,char * key,int * valuelen,int * flag,int * ret,fort_string_length keylen)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Info_get_valuelen\n");
#endif
in_w=1;

int  ret_tmp=0;

int info_tmp;
info_a2r(info,&info_tmp);
char key_tmp[R_MPI_MAX_INFO_KEY-1];
fstring_max_conv_a2r(key, key_tmp, keylen, R_MPI_MAX_INFO_KEY-1, true);
 LOCAL_f_MPI_Info_get_valuelen( &info_tmp, key_tmp, valuelen, flag, &ret_tmp, R_MPI_MAX_INFO_KEY-1);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Info_get_valuelen\n");
#endif

}


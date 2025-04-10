void  A_f_MPI_Info_get(int * info,char * key,int * valuelen,char * value,int * flag,int * ret, fort_string_length keylen, fort_string_length valuelen_)
{
#ifdef DEBUG
printf("input: A_f_MPI_Info_get\n");
#endif
in_w=1;

int  ret_tmp=0;

int info_tmp;
info_a2r(info,&info_tmp);
char key_tmp[R_MPI_MAX_INFO_KEY-1];
fstring_max_conv_a2r(key, key_tmp, keylen, R_MPI_MAX_INFO_KEY-1, true);

 LOCAL_f_MPI_Info_get( &info_tmp, key_tmp, valuelen, value, flag, &ret_tmp, R_MPI_MAX_INFO_KEY-1, valuelen_);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("output: A_f_MPI_Info_get\n");
#endif

}


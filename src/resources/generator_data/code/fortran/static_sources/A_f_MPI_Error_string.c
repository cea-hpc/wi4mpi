void  A_f_MPI_Error_string(int * errorcode,char * string,int * resultlen,int * ret,fort_string_length string_len)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Error_string\n");
#endif
in_w=1;

int errorcode_tmp=*errorcode;
int  ret_tmp=0;
char string_tmp[R_MPI_MAX_ERROR_STRING-1];
int resultlen_tmp;
error_a2r(errorcode,&errorcode_tmp);
    LOCAL_f_MPI_Error_string(&errorcode_tmp,string_tmp,&resultlen_tmp,&ret_tmp,R_MPI_MAX_ERROR_STRING-1);

fstring_max_conv_r2a(string, string_tmp, string_len, resultlen_tmp);
length_max_conv_r2a(resultlen, &resultlen_tmp, A_MPI_MAX_ERROR_STRING, R_MPI_MAX_ERROR_STRING);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Error_string\n");
#endif
}


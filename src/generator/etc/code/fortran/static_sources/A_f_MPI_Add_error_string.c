void  A_f_MPI_Add_error_string(int * errorcode,char * string, int *ret, fort_string_length string_len)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Add_error_string\n");
#endif
in_w=1;

int  ret_tmp=0;

int errorcode_tmp;
error_a2r(errorcode,&errorcode_tmp);
char tmp_name[R_MPI_MAX_ERROR_STRING-1];
fstring_max_conv_a2r(string, tmp_name, string_len, R_MPI_MAX_ERROR_STRING-1, false);
 LOCAL_f_MPI_Add_error_string( &errorcode_tmp, tmp_name, &ret_tmp, R_MPI_MAX_ERROR_STRING-1);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Add_error_string\n");
#endif

}


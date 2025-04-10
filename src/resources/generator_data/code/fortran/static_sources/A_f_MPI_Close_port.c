void  A_f_MPI_Close_port(char * string, int *ret, fort_string_length string_len)
{
#ifdef DEBUG
printf("input: A_f_MPI_Close_port\n");
#endif
in_w=1;

int  ret_tmp=0;
char tmp_name[R_MPI_MAX_PORT_NAME-1];
fstring_max_conv_a2r(string, tmp_name, string_len, R_MPI_MAX_PORT_NAME-1, false);

 LOCAL_f_MPI_Close_port(tmp_name, &ret_tmp, R_MPI_MAX_PORT_NAME-1);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("output: A_f_MPI_Close_port\n");
#endif

}


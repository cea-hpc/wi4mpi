void  A_f_MPI_Publish_name(char *service_name, int *info, char *port_name, int *ret, fort_string_length service_name_len, fort_string_length port_name_len)
{
#ifdef DEBUG
printf("input: A_f_MPI_Publish_name\n");
#endif
in_w=1;

int  ret_tmp=0;
int info_tmp;
info_a2r(info, &info_tmp);
char tmp_name[R_MPI_MAX_PORT_NAME-1];
fstring_max_conv_a2r(port_name, tmp_name, port_name_len, R_MPI_MAX_PORT_NAME-1, false);

 LOCAL_f_MPI_Publish_name(service_name, &info_tmp, tmp_name, &ret_tmp,service_name_len, R_MPI_MAX_PORT_NAME-1);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("output: A_f_MPI_Publish_name\n");
#endif

}


void  A_f_MPI_Comm_set_name(int * comm,char * comm_name, int *ret, fort_string_length comm_name_len)
{
#ifdef DEBUG
printf("input: A_f_MPI_Comm_set_name\n");
#endif
in_w=1;

int  ret_tmp=0;

int comm_tmp;
comm_a2r(comm,&comm_tmp);
char tmp_name[R_MPI_MAX_OBJECT_NAME-1];
fstring_max_conv_a2r(comm_name, tmp_name, comm_name_len, R_MPI_MAX_OBJECT_NAME-1, false);
 LOCAL_f_MPI_Comm_set_name( &comm_tmp, tmp_name, &ret_tmp, R_MPI_MAX_OBJECT_NAME-1);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("output: A_f_MPI_Comm_set_name\n");
#endif

}


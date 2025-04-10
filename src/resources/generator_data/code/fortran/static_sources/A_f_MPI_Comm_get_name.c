void  A_f_MPI_Comm_get_name(int * comm,char * comm_name, int *resultlen, int *ret, fort_string_length comm_name_len)
{
#ifdef DEBUG
printf("input: A_f_MPI_Comm_get_name\n");
#endif
in_w=1;

int  ret_tmp=0;

int comm_tmp;
comm_a2r(comm,&comm_tmp);
char tmp_name[R_MPI_MAX_OBJECT_NAME-1];
int resultlen_tmp;

 LOCAL_f_MPI_Comm_get_name( &comm_tmp, tmp_name, &resultlen_tmp, &ret_tmp, R_MPI_MAX_OBJECT_NAME-1);

fstring_max_conv_r2a(comm_name, tmp_name, comm_name_len, resultlen_tmp);
length_max_conv_r2a(resultlen, &resultlen_tmp, A_MPI_MAX_OBJECT_NAME, R_MPI_MAX_OBJECT_NAME);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("output: A_f_MPI_Comm_get_name\n");
#endif

}


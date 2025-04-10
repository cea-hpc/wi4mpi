void  A_f_MPI_Type_set_name(int * datatype,char * type_name, int *ret, fort_string_length type_name_len)
{
#ifdef DEBUG
printf("input: A_f_MPI_Type_set_name\n");
#endif
in_w=1;

int  ret_tmp=0;

int datatype_tmp;
datatype_a2r(datatype,&datatype_tmp);
char tmp_name[R_MPI_MAX_OBJECT_NAME-1];
fstring_max_conv_a2r(type_name, tmp_name, type_name_len, R_MPI_MAX_OBJECT_NAME-1, false);
 LOCAL_f_MPI_Type_set_name( &datatype_tmp, tmp_name, &ret_tmp, R_MPI_MAX_OBJECT_NAME-1);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("output: A_f_MPI_Type_set_name\n");
#endif

}


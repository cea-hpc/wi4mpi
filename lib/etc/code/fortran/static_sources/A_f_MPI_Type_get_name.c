void  A_f_MPI_Type_get_name(int * datatype,char * type_name, int *resultlen, int *ret, fort_string_length type_name_len)
{
#ifdef DEBUG
#endif
in_w=1;

int  ret_tmp=0;

int datatype_tmp;
datatype_a2r(datatype,&datatype_tmp);
char tmp_name[R_MPI_MAX_OBJECT_NAME-1];
int resultlen_tmp;

 LOCAL_f_MPI_Type_get_name( &datatype_tmp, tmp_name, &resultlen_tmp, &ret_tmp, R_MPI_MAX_OBJECT_NAME-1);

fstring_max_conv_r2a(type_name, tmp_name, type_name_len, resultlen_tmp);
length_max_conv_r2a(resultlen, &resultlen_tmp, A_MPI_MAX_OBJECT_NAME, R_MPI_MAX_OBJECT_NAME);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
#endif

}


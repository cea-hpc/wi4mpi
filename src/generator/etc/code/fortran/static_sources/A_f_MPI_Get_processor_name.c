void  A_f_MPI_Get_processor_name(char * name,int * resultlen,int * ret,fort_string_length namelen)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Get_processor_name\n");
#endif
in_w=1;

int  ret_tmp=0;
char tmp_name[R_MPI_MAX_PROCESSOR_NAME-1];
int resultlen_tmp;

LOCAL_f_MPI_Get_processor_name(tmp_name,&resultlen_tmp, &ret_tmp, R_MPI_MAX_PROCESSOR_NAME - 1);

fstring_max_conv_r2a(name, tmp_name, namelen, resultlen_tmp);
length_max_conv_r2a(resultlen, &resultlen_tmp, A_MPI_MAX_PROCESSOR_NAME, R_MPI_MAX_PROCESSOR_NAME);
error_r2a(ret,&ret_tmp);

in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Get_processor_name\n");
#endif

}

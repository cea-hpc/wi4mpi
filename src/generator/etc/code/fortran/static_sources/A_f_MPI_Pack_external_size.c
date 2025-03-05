void  A_f_MPI_Pack_external_size(char *datarep, int *count, int *datatype, size_t *size, int *ret, fort_string_length datarep_len)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Pack_external_size\n");
#endif
in_w=1;

int  ret_tmp=0;
int datatype_tmp;
datatype_a2r(datatype, &datatype_tmp);

 LOCAL_f_MPI_Pack_external_size(datarep, count, &datatype_tmp, size, &ret_tmp, datarep_len);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Pack_external_size\n");
#endif

}


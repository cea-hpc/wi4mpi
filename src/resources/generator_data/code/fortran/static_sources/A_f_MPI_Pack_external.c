void  A_f_MPI_Pack_external(char *datarep, void *inbuf, int *count, int *datatype, void *outbuf, size_t *outsize, size_t *position, int *ret, fort_string_length datarep_len)
{
#ifdef DEBUG
printf("input: A_f_MPI_Pack_external\n");
#endif
in_w=1;

int  ret_tmp=0;
int datatype_tmp;
datatype_a2r(datatype, &datatype_tmp);

 LOCAL_f_MPI_Pack_external(datarep, inbuf, count, &datatype_tmp, outbuf, outsize, position, &ret_tmp, datarep_len);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("output: A_f_MPI_Pack_external\n");
#endif

}


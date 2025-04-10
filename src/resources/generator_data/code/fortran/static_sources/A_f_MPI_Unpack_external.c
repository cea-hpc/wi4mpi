void  A_f_MPI_Unpack_external(char *datarep, void *inbuf, size_t *insize, size_t *position, void *outbuf, int *outcount, int *datatype, int *ret, fort_string_length datarep_len)
{
#ifdef DEBUG
printf("input: A_f_MPI_Unpack_external\n");
#endif
in_w=1;

int  ret_tmp=0;
int datatype_tmp;
datatype_a2r(datatype, &datatype_tmp);

 LOCAL_f_MPI_Unpack_external(datarep, inbuf, insize, position, outbuf, outcount, &datatype_tmp, &ret_tmp, datarep_len);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("output: A_f_MPI_Unpack_external\n");
#endif

}


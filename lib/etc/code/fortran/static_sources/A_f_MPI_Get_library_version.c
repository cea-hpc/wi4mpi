void  A_f_MPI_Get_library_version(char * version, int *resultlen, int *ret, fort_string_length version_len)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Get_library_version\n");
#endif
in_w=1;

int  ret_tmp=0;
char tmp_version[R_MPI_MAX_LIBRARY_VERSION_STRING-1];
int tmp_resultlen;

LOCAL_f_MPI_Get_library_version(tmp_version, &tmp_resultlen, &ret_tmp, sizeof(tmp_version));

fstring_max_conv_r2a(version, tmp_version, version_len, tmp_resultlen);
length_max_conv_r2a(resultlen, &tmp_resultlen, A_MPI_MAX_LIBRARY_VERSION_STRING, R_MPI_MAX_LIBRARY_VERSION_STRING);
error_r2a(ret,&ret_tmp);

in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Get_library_version\n");
#endif

}


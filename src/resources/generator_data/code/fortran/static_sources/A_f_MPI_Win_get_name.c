void  A_f_MPI_Win_get_name(int * win,char * win_name, int *resultlen, int *ret, fort_string_length win_name_len)
{
#ifdef DEBUG
printf("input: A_f_MPI_Win_get_name\n");
#endif
in_w=1;

int  ret_tmp=0;

int win_tmp;
fwin_a2r(win,&win_tmp);
char tmp_name[R_MPI_MAX_OBJECT_NAME-1];
int resultlen_tmp;

 LOCAL_f_MPI_Win_get_name( &win_tmp, tmp_name, &resultlen_tmp, &ret_tmp, R_MPI_MAX_OBJECT_NAME-1);

fstring_max_conv_r2a(win_name, tmp_name, win_name_len, resultlen_tmp);
length_max_conv_r2a(resultlen, &resultlen_tmp, A_MPI_MAX_OBJECT_NAME, R_MPI_MAX_OBJECT_NAME);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("output: A_f_MPI_Win_get_name\n");
#endif

}


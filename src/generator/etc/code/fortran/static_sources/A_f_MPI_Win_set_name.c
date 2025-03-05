void  A_f_MPI_Win_set_name(int *win, char *win_name, int *ret, fort_string_length win_name_len)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Win_set_name\n");
#endif
in_w=1;

int  ret_tmp=0;
int win_tmp;
fwin_a2r(win, &win_tmp);
char tmp_name[R_MPI_MAX_OBJECT_NAME-1];
fstring_max_conv_a2r(win_name, tmp_name, win_name_len, R_MPI_MAX_OBJECT_NAME-1, false);

 LOCAL_f_MPI_Win_set_name(&win_tmp, tmp_name, &ret_tmp, R_MPI_MAX_OBJECT_NAME-1);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Win_set_name\n");
#endif

}


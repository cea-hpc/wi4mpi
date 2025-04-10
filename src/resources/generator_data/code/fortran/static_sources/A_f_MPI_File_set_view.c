void  A_f_MPI_File_set_view(int * fh,int* disp,int * etype,int * filetype,char *datarep,int * info,int * ret,fort_string_length datareplen)
{
#ifdef DEBUG
printf("input: A_f_MPI_File_set_view\n");
#endif
in_w=1;

int  ret_tmp=0;

int etype_tmp;
int filetype_tmp;
int info_tmp;
datatype_a2r(etype,&etype_tmp);
datatype_a2r(filetype,&filetype_tmp);
info_a2r(info,&info_tmp);
char tmp_name[R_MPI_MAX_DATAREP_STRING-1];
fstring_max_conv_a2r(datarep, tmp_name, datareplen, R_MPI_MAX_DATAREP_STRING-1, false);
 LOCAL_f_MPI_File_set_view( fh, disp, &etype_tmp, &filetype_tmp, tmp_name, &info_tmp, &ret_tmp, R_MPI_MAX_DATAREP_STRING-1);
 error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("output: A_f_MPI_File_set_view\n");
#endif

}


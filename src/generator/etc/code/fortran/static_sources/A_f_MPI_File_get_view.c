void  A_f_MPI_File_get_view(int * fh,int* disp,int * etype,int * filetype,char *datarep,int * ret,fort_string_length datareplen)
{
#ifdef DEBUG
printf("entre : A_f_MPI_File_get_view\n");
#endif
in_w=1;

int  ret_tmp=0;

int etype_tmp;
int filetype_tmp;
char tmp_name[R_MPI_MAX_DATAREP_STRING-1];
 LOCAL_f_MPI_File_get_view( fh, disp, &etype_tmp, &filetype_tmp, tmp_name, &ret_tmp, R_MPI_MAX_DATAREP_STRING-1);
datatype_r2a(etype,&etype_tmp);
datatype_r2a(filetype,&filetype_tmp);
 fstring_max_conv_r2a(datarep, tmp_name, datareplen, R_MPI_MAX_DATAREP_STRING-1);
 error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_File_get_view\n");
#endif

}


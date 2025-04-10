void  A_f_MPI_File_delete(char * filename,int * info,int * ret,fort_string_length filenamelen)
{
#ifdef DEBUG
printf("input: A_f_MPI_File_delete\n");
#endif
in_w=1;

int  ret_tmp=0;

int info_tmp;
info_a2r(info,&info_tmp);
 LOCAL_f_MPI_File_delete( filename, &info_tmp, &ret_tmp, filenamelen);
 error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("output: A_f_MPI_File_delete\n");
#endif

}


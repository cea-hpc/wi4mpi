void A_f_MPI_File_open(int* comm, char *filename, int* amode,int* info, int *fh,int *ret, fort_string_length filenamelen)
{
#ifdef DEBUG
printf("input: A_f_MPI_File_open\n");
#endif
in_w=1;

//printf("entre: MPI_File_open\n");
int comm_tmp;
int info_tmp=0;
int ret_tmp=0;
comm_a2r(comm,&comm_tmp);
//printf("apres comm_a2r\n");
info_a2r(info,&info_tmp);
//printf("Avant appel comm %d_%d | info %d_%d | filename %s\n",*comm,comm_tmp,*info,info_tmp,filename);
LOCAL_f_MPI_File_open(&comm_tmp, filename, amode, &info_tmp, fh, &ret_tmp, filenamelen);
error_r2a(ret,&ret_tmp);
//printf("sort: MPI_File_open\n");
in_w=0;
#ifdef DEBUG
printf("output: A_f_MPI_File_open\n");
#endif

}


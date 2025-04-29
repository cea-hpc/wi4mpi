void  A_f_MPI_Comm_spawn(char *command, char *argv, int *maxprocs, int *info, int *root, int *comm, int *intercomm, int *array_of_errcodes, int *ret, fort_string_length command_len, fort_string_length argv_len)
{
#ifdef DEBUG
printf("input: A_f_MPI_Comm_spawn\n");
#endif
in_w=1;

int  ret_tmp=0;

int info_tmp;
info_a2r(info,&info_tmp);
int root_tmp;
rank_mapper_a2r(root, &root_tmp);
int comm_tmp;
comm_a2r(comm,&comm_tmp);
int intercomm_tmp;

 LOCAL_f_MPI_Comm_spawn(command, argv, maxprocs, &info_tmp, &root_tmp,&comm_tmp, &intercomm_tmp, array_of_errcodes, &ret_tmp,command_len,argv_len);
comm_r2a(intercomm,&intercomm_tmp);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("output: A_f_MPI_Comm_spawn\n");
#endif

}


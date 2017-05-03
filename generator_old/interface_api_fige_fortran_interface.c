void  mpi_register_datarep_(char *datarep, void *read_conversion_fn, void *write_conversion_fn,
                            void *dtype_file_extent_fn, void *extra_state, int * ret);
#pragma weak mpi_register_datarep_=pmpi_register_datarep_
void  (*INTERFACE_F_LOCAL_MPI_Register_datarep)(char *datarep, void *read_conversion_fn, void *write_conversion_fn,
                            void *dtype_file_extent_fn, void *extra_state, int * ret);

void pmpi_register_datarep_(char *datarep, void *read_conversion_fn, void *write_conversion_fn,
                            void *dtype_file_extent_fn, void *extra_state, int * ret){

return  INTERFACE_F_LOCAL_MPI_Register_datarep(datarep, read_conversion_fn, write_conversion_fn,
                            dtype_file_extent_fn, extra_state, ret);
}

void  mpi_comm_spawn_multiple_(int count,char **command, char ***argv, int *maxprocs, int *info, int *root, int *comm, int *intercomm, int *array_of_errcodes, int *ret,int command_len, int argv_len);
#pragma weak mpi_comm_spawn_multiple_=pmpi_comm_spawn_multiple_
void  (*INTERFACE_F_LOCAL_MPI_Comm_spawn_multiple)(int count,char **command, char ***argv, int *maxprocs, int *info, int *root, int *comm, int *intercomm, int *array_of_errcodes, int *ret,int command_len, int argv_len);

void pmpi_comm_spawn_multiple_(int count,char **command, char ***argv, int *maxprocs, int *info, int *root, int *comm, int *intercomm, int *array_of_errcodes, int *ret,int command_len, int argv_len){

return  INTERFACE_F_LOCAL_MPI_Comm_spawn_multiple( count,command, argv, maxprocs, info, root, comm, intercomm, array_of_errcodes, ret,command_len, argv_len);
}


__attribute__((constructor)) void wrapper_interface_f(void) {
INTERFACE_F_LOCAL_MPI_Register_datarep=dlsym(interface_handle_f,"A_f_MPI_Register_datarep");
INTERFACE_F_LOCAL_MPI_Comm_spawn_multiple=dlsym(interface_handle_f,"A_f_MPI_Comm_spawn_multiple");
}

void A_f_MPI_Comm_connect(char *port_name, int *info, int *root, int *comm,
                          int *newcomm, int *ret, fort_string_length port_name_len) {
#ifdef DEBUG
printf("entre : A_f_MPI_Comm_connect\n");
#endif
  in_w = 1;
  int ret_tmp = 0;

  int info_tmp;
  int root_tmp;
  int comm_tmp;
  int newcomm_tmp;
  info_a2r(info, &info_tmp);
  rank_mapper_a2r(root, &root_tmp);
  comm_a2r(comm, &comm_tmp);
  char tmp_name[R_MPI_MAX_PORT_NAME-1];
  fstring_max_conv_a2r(port_name, tmp_name, port_name_len, R_MPI_MAX_PORT_NAME-1, false);
  LOCAL_f_MPI_Comm_connect(tmp_name, &info_tmp, &root_tmp, &comm_tmp,
                          &newcomm_tmp, &ret_tmp, R_MPI_MAX_PORT_NAME-1);
  if (ret_tmp == R_f_MPI_SUCCESS)
    comm_r2a(newcomm, &newcomm_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
printf("sort : A_f_MPI_Comm_connect\n");
#endif
}


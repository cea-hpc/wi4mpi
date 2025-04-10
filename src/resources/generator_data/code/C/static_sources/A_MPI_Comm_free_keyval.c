
int A_MPI_Comm_free_keyval(int *comm_keyval) {
  in_w = 1;
#ifdef DEBUG
  printf("input: A_MPI_Comm_free_keyval\n");
#endif

  int ret_tmp = LOCAL_MPI_Comm_free_keyval(comm_keyval);

  *comm_keyval = A_MPI_KEYVAL_INVALID;
#ifdef DEBUG
  printf("output: A_MPI_Comm_free_keyval\n");
#endif
  in_w = 0;
  return error_code_conv_r2a(ret_tmp);
}

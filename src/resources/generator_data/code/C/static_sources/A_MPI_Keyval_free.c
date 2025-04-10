
int A_MPI_Keyval_free(int *keyval) {
  in_w = 1;
#ifdef DEBUG
  printf("input: A_MPI_Keyval_free\n");
#endif
  int ret_tmp = LOCAL_MPI_Keyval_free(keyval);
  *keyval = A_MPI_KEYVAL_INVALID;
#ifdef DEBUG
  printf("input: A_MPI_Keyval_free\n");
#endif
  in_w = 0;
  return error_code_conv_r2a(ret_tmp);
}

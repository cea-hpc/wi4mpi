
void A_f_MPI_Keyval_free(int *keyval, int *ret) {
#ifdef DEBUG
  printf("input: A_f_MPI_Keyval_free\n");
#endif
  in_w = 1;
  int ret_tmp = 0;
  ret_tmp = A_MPI_Keyval_free(keyval);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("output: A_f_MPI_Keyval_free\n");
#endif
}

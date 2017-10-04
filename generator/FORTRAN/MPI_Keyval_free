void (*_LOCAL_MPI_Keyval_free)(int *, int *);

void A_f_MPI_Keyval_free(int *keyval, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Keyval_free\n");
#endif
  in_w = 1;
  int ret_tmp = 0;
  /*
   _LOCAL_MPI_Keyval_free( keyval, &ret_tmp);
  if(ret_tmp==R_f_MPI_SUCCESS)
  {
          *keyval=A_MPI_KEYVAL_INVALID;
  }
  */
  ret_tmp = A_MPI_Keyval_free(keyval);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Keyval_free\n");
#endif
}

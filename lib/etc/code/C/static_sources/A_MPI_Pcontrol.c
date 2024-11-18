int A_MPI_Pcontrol(int level, ...) {
#ifdef DEBUG
  printf("entre : A_MPI_Pcontrol\n");
#endif
  in_w = 1;
  fprintf(stderr, "A_MPI_Pcontrol Not implemented yet\n");
  // int ret_tmp= LOCAL_MPI_Abort(R_MPI_COMM_WORLD,7);
  in_w = 0;
#ifdef DEBUG
  printf("sort : A_MPI_Pcontrol\n");
#endif
  // return error_code_conv_r2a(ret_tmp);
  return A_MPI_SUCCESS;
}

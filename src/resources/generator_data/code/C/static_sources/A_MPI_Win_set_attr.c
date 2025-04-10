);
int A_MPI_Win_set_attr(A_MPI_Win win, int win_keyval, void *attribute_val) {
#ifdef DEBUG
  printf("input: A_MPI_Win_set_attr\n");
#endif
  in_w = 1;

  R_MPI_Win win_tmp;
  win_conv_a2r(&win, &win_tmp);
  int win_keyval_tmp;
  my_keyval_a2r(&win_keyval, &win_keyval_tmp);
  void *attribute_val_tmp;
  switch (win_keyval_tmp) {
  case R_MPI_WIN_BASE: // void*
    buffer_conv_a2r(&attribute_val, &attribute_val_tmp);
  case R_MPI_WIN_SIZE: // MPI_Aint
    attribute_val = (R_MPI_Aint *)attribute_val_tmp;
  case R_MPI_WIN_DISP_UNIT:
    win_attr_flavor_conv_a2r(attribute_val, attribute_val_tmp);
  case R_MPI_WIN_CREATE_FLAVOR:
    win_attr_flavor_conv_a2r(attribute_val, attribute_val_tmp);
  case R_MPI_WIN_MODEL: // int*
    win_attr_model_conv_a2r(attribute_val, attribute_val_tmp);
  }
  int ret_tmp =
      LOCAL_MPI_Win_set_attr(win_tmp, win_keyval_tmp, attribute_val_tmp);
  win_conv_r2a(&win, &win_tmp);
  in_w = 0;
#ifdef DEBUG
  printf("output: A_MPI_Win_set_attr\n");
#endif
  return error_code_conv_r2a(ret_tmp);
}

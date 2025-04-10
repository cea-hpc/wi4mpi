#ifndef MPI_WIN_CREATE_KEYVAL_OVERRIDE
int A_MPI_Win_create_keyval(A_MPI_Win_copy_attr_function *win_copy_attr_fn,
                            A_MPI_Win_delete_attr_function *win_delete_attr_fn,
                            int *win_keyval, void *extra_state) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Win_create_keyval_timeout);
#endif
  in_w = 1;

  ptr_win_copy_fn = (A_MPI_Win_copy_attr_function *)win_copy_attr_fn;

  ptr_win_dlt_fn = (A_MPI_Win_delete_attr_function *)win_delete_attr_fn;

  void *extra_state_tmp;
  buffer_conv_a2r(&extra_state, &extra_state_tmp);
  int ret_tmp = LOCAL_MPI_Win_create_keyval(
      (R_MPI_Win_copy_attr_function *)wrapper_win_copy_function,
      (R_MPI_Win_delete_attr_function *)wrapper_win_delete_function, win_keyval,
      extra_state_tmp);

  int ret = error_code_conv_r2a(ret_tmp);
  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_Win_create_keyval_print)
    debug_printer(
        "MPI_Win_create_keyval: \n{\nwin_copy_attr_fn: %p,\nwin_keyval: "
        "%*d,\nextra_state: %p,\nerror/return: %d\n}\n",
        win_copy_attr_fn, win_keyval, extra_state, ret);
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
  return ret;
}
#endif

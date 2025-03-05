void (*LOCAL_f_MPI_Keyval_create)(void *, void *, int *, void *, int *);

void A_f_MPI_Keyval_create(void *copy_fn, void *delete_fn, int *keyval,
                           void *extra_state, int *ret) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Keyval_create_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *copy_fn_tmp = copy_fn;
  void *delete_fn_tmp = delete_fn;
  void *extra_state_tmp = extra_state;
  copy_ptr_converter_a2r(&copy_fn, &copy_fn_tmp);
  delete_ptr_converter_a2r(&delete_fn, &delete_fn_tmp);
  buffer_a2r(&extra_state, &extra_state_tmp);
  LOCAL_f_MPI_Keyval_create(copy_fn_tmp, delete_fn_tmp, keyval, extra_state_tmp,
                           &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_Keyval_create_print)
    debug_printer(
        "MPI_Keyval_create : \n{\ncopy_fn : %p,\ndelete_fn : %p,\nkeyval : "
        "%*d,\nextra_state : %p,\nerror/return : %*d\n}\n",
        copy_fn, delete_fn, keyval, extra_state, ret);
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}

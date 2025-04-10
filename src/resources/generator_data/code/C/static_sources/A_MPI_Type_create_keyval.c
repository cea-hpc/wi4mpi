#ifndef MPI_TYPE_CREATE_KEYVAL_OVERRIDE
int A_MPI_Type_create_keyval(
    A_MPI_Type_copy_attr_function *type_copy_attr_fn,
    A_MPI_Type_delete_attr_function *type_delete_attr_fn, int *type_keyval,
    void *extra_state) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Type_create_keyval_timeout);
#endif
  in_w = 1;

  ptr_type_cpy_attr_fn = (A_MPI_Type_copy_attr_function *)type_copy_attr_fn;

  ptr_type_dlt_attr_fn = (A_MPI_Type_delete_attr_function *)type_delete_attr_fn;

  void *extra_state_tmp;
  buffer_conv_a2r(&extra_state, &extra_state_tmp);
  int ret_tmp = LOCAL_MPI_Type_create_keyval(
      (R_MPI_Type_copy_attr_function *)wrapper_type_copy_attr_fn,
      (R_MPI_Type_delete_attr_function *)wrapper_type_delete_attr_fn,
      type_keyval, extra_state_tmp);

  int ret = error_code_conv_r2a(ret_tmp);
  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_Type_create_keyval_print)
    debug_printer("MPI_Type_create_keyval: \n{\ntype_copy_attr_fn: "
                  "%p,\ntype_delete_attr_fn: %p,\ntype_keyval: "
                  "%*d,\nextra_state: %p,\nerror/return: %d\n}\n",
                  type_copy_attr_fn, type_delete_attr_fn, type_keyval,
                  extra_state, ret);
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
  return ret;
}
#endif

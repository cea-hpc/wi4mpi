void A_f_MPI_Errhandler_create(void *function, int *errhandler, int *ret) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Errhandler_create_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  void *function_tmp = function;
  int errhandler_tmp;
  handler_fct_ptr_conv_a2r(&function, &function_tmp);
  LOCAL_f_MPI_Errhandler_create(function_tmp, &errhandler_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    errhandler_converter_r2a(errhandler, &errhandler_tmp);
  errhandler_f_fn_translation_update(errhandler_tmp, function);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_Errhandler_create_print)
    debug_printer("MPI_Errhandler_create: \n{\nfunction: %p,\nerrhandler: "
                  "%*d,\nerror/return: %*d\n}\n",
                  function, errhandler, ret);
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}

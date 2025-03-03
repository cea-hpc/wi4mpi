void A_f_MPI_Errhandler_free(int *errhandler, int *ret) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Errhandler_free_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int errhandler_tmp;
  errhandler_converter_a2r(errhandler, &errhandler_tmp);
  errhandler_f_fn_translation_del(errhandler_tmp);
  LOCAL_f_MPI_Errhandler_free(&errhandler_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS) {
    errhandler_f_fn_translation_del(errhandler_tmp);
    errhandler_converter_r2a(errhandler, &errhandler_tmp);
  }
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_Errhandler_free_print)
    debug_printer(
        "MPI_Errhandler_free : \n{\nerrhandler : %*d,\nerror/return : %*d\n}\n",
        errhandler, ret);
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}

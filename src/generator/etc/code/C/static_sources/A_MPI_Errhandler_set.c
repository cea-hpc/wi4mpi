#ifndef MPI_ERRHANDLER_SET_OVERRIDE
int A_MPI_Errhandler_set(A_MPI_Comm comm, A_MPI_Errhandler errhandler) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Errhandler_set_timeout);
#endif
  in_w = 1;

  R_MPI_Comm comm_tmp;
  comm_conv_a2r(&comm, &comm_tmp);
  R_MPI_Errhandler errhandler_tmp;
  errhandler_conv_a2r(&errhandler, &errhandler_tmp);
  int ret_tmp = LOCAL_MPI_Errhandler_set(comm_tmp, errhandler_tmp);
  if (!errhandler_translation_is_const(errhandler)) {
    A_MPI_Handler_function *ptr_errhandler_func;
    errhandler_fn_translation_get(errhandler, &ptr_errhandler_func);
    communicator_fn_translation_update(comm, ptr_errhandler_func);
  }
  int ret = error_code_conv_r2a(ret_tmp);
  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_Errhandler_set_print)
    debug_printer("MPI_Errhandler_set : \n{\ncomm : %C,\nerrhandler : "
                  "%e,\nerror/return : %d\n}\n",
                  comm, errhandler, ret);
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
  return ret;
}
#endif

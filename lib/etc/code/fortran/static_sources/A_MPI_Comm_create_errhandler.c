#ifndef MPI_COMM_CREATE_ERRHANDLER_OVERRIDE
int A_MPI_Comm_create_errhandler(
    A_MPI_Comm_errhandler_function *comm_errhandler_fn,
    A_MPI_Errhandler *errhandler) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Comm_create_errhandler_timeout);
#endif
  in_w = 1;

  ptr_comm_fn_handler = (A_MPI_Comm_errhandler_function *)comm_errhandler_fn;
  R_MPI_Errhandler errhandler_ltmp = R_MPI_ERRHANDLER_NULL;
  R_MPI_Errhandler *errhandler_tmp = &errhandler_ltmp;
  int ret_tmp = LOCAL_MPI_Comm_create_errhandler(
      (R_MPI_Comm_errhandler_function *)wrapper_comm_handler_function,
      errhandler_tmp);
  errhandler_ptr_conv_r2a(&errhandler, &errhandler_tmp);
  int ret = error_code_conv_r2a(ret_tmp);
  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_Comm_create_errhandler_print)
    debug_printer("MPI_Comm_create_errhandler : \n{\ncomm_errhandler_fn : "
                  "%p,\nerrhandler : %p,\nerror/return : %d\n}\n",
                  comm_errhandler_fn, errhandler, ret);
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
  return ret;
}
#endif

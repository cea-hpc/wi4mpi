#ifndef MPI_ERRHANDLER_CREATE_OVERRIDE
int A_MPI_Errhandler_create(A_MPI_Handler_function *function,
                            A_MPI_Errhandler *errhandler) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Errhandler_create_timeout);
#endif
  in_w = 1;

  ptr_handler_fn = (A_MPI_Handler_function *)function;
  R_MPI_Errhandler errhandler_ltmp = R_MPI_ERRHANDLER_NULL;
  R_MPI_Errhandler *errhandler_tmp = &errhandler_ltmp;
  int ret_tmp = LOCAL_MPI_Errhandler_create(
      (R_MPI_Handler_function *)wrapper_handler_function, errhandler_tmp);
  errhandler_ptr_conv_r2a(&errhandler, &errhandler_tmp);
  int ret = error_code_conv_r2a(ret_tmp);
  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_Errhandler_create_print)
    debug_printer("MPI_Errhandler_create: \n{\nfunction: %p,\nerrhandler: "
                  "%p,\nerror/return: %d\n}\n",
                  function, errhandler, ret);
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
  return ret;
}
#endif


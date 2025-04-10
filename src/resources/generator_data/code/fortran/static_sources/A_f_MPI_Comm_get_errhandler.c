void A_f_MPI_Comm_get_errhandler(int *comm, int *errhandler, int *ret) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Comm_get_errhandler_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  int errhandler_tmp;
  comm_a2r(comm, &comm_tmp);
  LOCAL_f_MPI_Comm_get_errhandler(&comm_tmp, &errhandler_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    errhandler_converter_r2a(errhandler, &errhandler_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_Comm_get_errhandler_print)
    debug_printer("MPI_Comm_get_errhandler: \n{\ncomm: %*C,\nerrhandler: "
                  "%*d,\nerror/return: %*d\n}\n",
                  comm, errhandler, ret);
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}

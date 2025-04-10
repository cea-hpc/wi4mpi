void A_f_MPI_Errhandler_set(int *comm, int *errhandler, int *ret) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Errhandler_set_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  int errhandler_tmp;
  comm_a2r(comm, &comm_tmp);
  errhandler_converter_a2r(errhandler, &errhandler_tmp);
  LOCAL_f_MPI_Errhandler_set(&comm_tmp, &errhandler_tmp, &ret_tmp);
  errhandler_set_func(comm_tmp, errhandler_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_Errhandler_set_print)
    debug_printer("MPI_Errhandler_set: \n{\ncomm: %*C,\nerrhandler: "
                  "%*d,\nerror/return: %*d\n}\n",
                  comm, errhandler, ret);
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}

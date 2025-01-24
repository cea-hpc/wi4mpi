
void A_f_MPI_Errhandler_get(int *comm, int *errhandler, int *ret) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Errhandler_get_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  int errhandler_tmp;
  comm_a2r(comm, &comm_tmp);
  _LOCAL_MPI_Errhandler_get(&comm_tmp, &errhandler_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    errhandler_converter_r2a(errhandler, &errhandler_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_Errhandler_get_print)
    debug_printer("MPI_Errhandler_get : \n{\ncomm : %*C,\nerrhandler : "
                  "%*d,\nerror/return : %*d\n}\n",
                  comm, errhandler, ret);
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}

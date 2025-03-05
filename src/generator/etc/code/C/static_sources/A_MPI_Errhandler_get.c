#ifndef MPI_ERRHANDLER_GET_OVERRIDE
int A_MPI_Errhandler_get(A_MPI_Comm comm, A_MPI_Errhandler *errhandler) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Errhandler_get_timeout);
#endif
  in_w = 1;

  R_MPI_Comm comm_tmp;
  comm_conv_a2r(&comm, &comm_tmp);
  R_MPI_Errhandler errhandler_ltmp = R_MPI_ERRHANDLER_NULL;
  R_MPI_Errhandler *errhandler_tmp = &errhandler_ltmp;
  int ret_tmp = LOCAL_MPI_Errhandler_get(comm_tmp, errhandler_tmp);
  if (ret_tmp == R_MPI_SUCCESS) {
    errhandler_translation_get_key_from_value(*errhandler_tmp, errhandler);
  }
  int ret = error_code_conv_r2a(ret_tmp);
  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_Errhandler_get_print)
    debug_printer("MPI_Errhandler_get : \n{\ncomm : %C,\nerrhandler : "
                  "%p,\nerror/return : %d\n}\n",
                  comm, errhandler, ret);
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
  return ret;
}
#endif

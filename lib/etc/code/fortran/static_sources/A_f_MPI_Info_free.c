void A_f_MPI_Info_free(int *info, int *ret) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Info_free_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int info_tmp;
  info_a2r(info, &info_tmp);
  LOCAL_f_MPI_Info_free(&info_tmp, &ret_tmp);
  if (ret_tmp == R_f_MPI_SUCCESS)
    info_r2a(info, &info_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_Info_free_print)
    debug_printer("MPI_Info_free : \n{\ninfo : %*d,\nerror/return : %*d\n}\n",
                  info, ret);
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}

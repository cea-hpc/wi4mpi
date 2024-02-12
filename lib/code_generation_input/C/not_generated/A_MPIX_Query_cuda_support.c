#ifndef MPIX_QUERY_CUDA_SUPPORT_OVERRIDE
int A_MPIX_Query_cuda_support() {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPIX_Query_cuda_support_timeout);
#endif
  in_w = 1;

  int ret_tmp =
      (LOCAL_MPIX_Query_cuda_support ? LOCAL_MPIX_Query_cuda_support() : 0);
  int ret = ret_tmp;
  in_w = 0;
#ifdef DEBUG
  if (WI4MPIX_Query_cuda_support_print)
    debug_printer("MPIX_Query_cuda_support : \n{\nerror/return : %lf\n}\n",
                  ret);
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
  return ret;
}
#endif

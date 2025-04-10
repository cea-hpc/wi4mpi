A_MPI_Aint A__MPI_Aint_diff(A_MPI_Aint addr1, A_MPI_Aint addr2) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Aint_diff_timeout);
#endif
  in_w = 1;
  R_MPI_Aint addr1_tmp;
  addr1_tmp = (R_MPI_Aint)addr1;
  R_MPI_Aint addr2_tmp;
  addr2_tmp = (R_MPI_Aint)addr2;

#ifdef R_MPI_Aint_diff
  R_MPI_Aint ret_tmp = R_MPI_Aint_diff(addr1_tmp, addr2_tmp);
#else
  R_MPI_Aint ret_tmp = LOCAL_MPI_Aint_diff(addr1_tmp, addr2_tmp);
#endif

  A_MPI_Aint ret = (A_MPI_Aint)ret_tmp;
  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_Aint_diff_print)
    debug_printer("MPI_Aint_diff:\n{\naddr1: %ld,\naddr2: "
                  "%ld,\nerror/return: %ld\n}\n",
                  addr1, addr2, ret);
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
  return ret;
}

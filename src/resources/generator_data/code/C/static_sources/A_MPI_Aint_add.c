A_MPI_Aint A__MPI_Aint_add(A_MPI_Aint base, A_MPI_Aint disp) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Aint_add_timeout);
#endif
  in_w = 1;
  R_MPI_Aint base_tmp;
  base_tmp = (R_MPI_Aint)base;
  R_MPI_Aint disp_tmp;
  disp_tmp = (R_MPI_Aint)disp;

#ifdef R_MPI_Aint_add
  R_MPI_Aint ret_tmp = R_MPI_Aint_add(base_tmp, disp_tmp);
#else
  R_MPI_Aint ret_tmp = LOCAL_MPI_Aint_add(base_tmp, disp_tmp);
#endif

  A_MPI_Aint ret = (A_MPI_Aint)ret_tmp;
  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_Aint_add_print)
    debug_printer(
        "MPI_Aint_add:\n{\nbase: %ld,\ndisp: %ld,\nerror/return: %ld\n}\n",
        base, disp, ret);
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
  return ret;
}


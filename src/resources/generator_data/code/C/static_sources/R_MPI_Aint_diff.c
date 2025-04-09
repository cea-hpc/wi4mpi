// use two underscores to workaround openmpi implementation being macro
R_MPI_Aint R__MPI_Aint_diff(R_MPI_Aint addr1, R_MPI_Aint addr2) {
#ifdef TIMEOUT_SUPPORT
#endif
#ifdef R_MPI_Aint_diff
  R_MPI_Aint ret_tmp = LOCAL_MPI_Aint_diff(addr1, addr2);
#else
  R_MPI_Aint ret_tmp = LOCAL_MPI_Aint_diff(addr1, addr2);
#endif
  R_MPI_Aint ret = ret_tmp;
#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
  return ret;
}

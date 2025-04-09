// use two underscores to workaround openmpi implementation being macro
R_MPI_Aint R__MPI_Aint_add(R_MPI_Aint base, R_MPI_Aint disp) {
#ifdef TIMEOUT_SUPPORT
#endif
#ifdef R_MPI_Aint_add
  R_MPI_Aint ret_tmp = R_MPI_Aint_add(base, disp);
#else
  R_MPI_Aint ret_tmp = LOCAL_MPI_Aint_add(base, disp);
#endif
  R_MPI_Aint ret = ret_tmp;
#ifdef DEBUG
#endif
#ifdef TIMEOUT_SUPPORT
#endif
  return ret;
}

int R_MPI_Pcontrol(int level, ...) {
#ifdef DEBUG
  printf("entre : R_MPI_Pcontrol\n");
#endif
  int ret_tmp = LOCAL_MPI_Pcontrol(level, "", NULL);
#ifdef DEBUG
  printf("sort : R_MPI_Pcontrol\n");
#endif
  return ret_tmp;
}

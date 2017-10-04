void (*_LOCAL_MPI_Attr_delete)(int *, int *, int *);
int A_MPI_Attr_delete(A_MPI_Comm, int);

void A_f_MPI_Attr_delete(int *comm, int *keyval, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Attr_delete\n");
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  int keyval_tmp;
  // comm_a2r(comm,&comm_tmp);
  A_MPI_Comm ct = A_MPI_Comm_f2c(*comm);
  ret_tmp = A_MPI_Attr_delete(ct, *keyval);
  // _LOCAL_MPI_Attr_delete( &comm_tmp, keyval, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Attr_delete\n");
#endif
}

void (*_LOCAL_MPI_Attr_put)(int *, int *, int *, int *);

void A_f_MPI_Attr_put(int *comm, int *keyval, int *attribute_val, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Attr_put\n");
#endif
  // in_w=1;
  int ret_tmp = 0;

  int comm_tmp;
  /*comm_a2r(comm,&comm_tmp);
   _LOCAL_MPI_Attr_put( &comm_tmp, keyval, attribute_val, &ret_tmp);
  //if(*keyval==R_F_MPI_INVALID) *keyval=A_F_MPI_INVALID;
  */
  A_MPI_Comm ct = A_MPI_Comm_f2c(*comm);
  intptr_t tv = *(attribute_val);
  ret_tmp = A_MPI_Attr_put(ct, *keyval, (void*)tv);
  error_r2a(ret, &ret_tmp);

// in_w=0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Attr_put\n");
#endif
}

void (*_LOCAL_MPI_Attr_get)(int *, int *, int *, int *, int *);

void A_f_MPI_Attr_get(int *comm, int *keyval, int *attribute_val, int *flag,
                      int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Attr_get\n");
#endif
  // in_w=1;
  int ret_tmp = 0;

  int comm_tmp;
  int keyval_tmp =
      *keyval; //=(*keyval==R_F_MPI_INVALID?A_F_MPI_INVALID:*keyval);
  /*comm_a2r(comm,&comm_tmp);
   _LOCAL_MPI_Attr_get( &comm_tmp, &keyval_tmp, attribute_val, flag, &ret_tmp);
  */
  A_MPI_Comm ct = A_MPI_Comm_f2c(*comm);
  intptr_t kt = 0;
  *attribute_val = 0;
  // printf("val %d %p %d %d\n",*attribute_val,ct,*keyval,*flag);
  ret_tmp = A_MPI_Attr_get(ct, *keyval, &kt, flag);
  // if (kt >> 32)
  //   kt = (int)(((long)(1 << 31)) - 1);
  *attribute_val = (int)kt;
  // printf("val %d %p %d %d\n",*attribute_val,ct,*keyval,*flag);
  error_r2a(ret, &ret_tmp);
// in_w=0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Attr_get\n");
#endif
}

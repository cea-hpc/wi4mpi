void A_f_MPI_Attr_get(int *comm, int *keyval, int *attribute_val, int *flag,
                      int *ret) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Attr_get_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  int comm_tmp;
  int keyval_tmp;
  comm_a2r(comm, &comm_tmp);
  keyval_a2r(keyval, &keyval_tmp);
  LOCAL_f_MPI_Attr_get(&comm_tmp, &keyval_tmp, attribute_val, flag, &ret_tmp);
  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_Attr_get_print)
    debug_printer(
        "MPI_Attr_get : \n{\ncomm : %*C,\nkeyval : %*d,\nattribute_val : "
        "%*d,\nflag : %*d,\nerror/return : %*d\n}\n",
        comm, keyval, attribute_val, flag, ret);
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}

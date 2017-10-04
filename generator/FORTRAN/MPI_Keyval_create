void (*_LOCAL_MPI_Keyval_create)(void *, void *, int *, void *, int *);
int (*LOCAL_MPI_Keyval_create)(void *, void *, int *, void *);
int (*LOCAL_MPI_Comm_create_keyval)(void *, void *, int *, void *);
extern void *mpi_null_copy_fn_;
extern void *mpi_dup_fn_;
extern void *mpi_null_delete_fn_;
int wrapper_copy_function_f(R_MPI_Comm comm, int keyval, void *extra_state,
                            void *attribute_val_in, void *attribute_val_out,
                            int *flag) {
  A_MPI_Comm comm_tmp;
  comm_conv_r2a_static(&comm_tmp, &comm);
  A_F_MPI_Copy_function *ptr_copy_func =
      myKeyval_translation_get(keyval)->cp_function;
  myKeyval_translation_get(keyval)->ref++;
  // printf("duped %d %p %d %p\n",
  // keyval,comm,myKeyval_translation_get(keyval)->ref,ptr_copy_func);
  if (ptr_copy_func == (A_F_MPI_Copy_function *)A_MPI_NULL_COPY_FN ||
      ptr_copy_func == (A_F_MPI_Copy_function *)A_MPI_COMM_NULL_DELETE_FN ||
      ptr_copy_func == (A_F_MPI_Copy_function *)&mpi_null_copy_fn_) {
    *flag = 0;
    return R_MPI_SUCCESS;
  } else if (ptr_copy_func == (A_F_MPI_Copy_function *)A_MPI_COMM_DUP_FN ||
             ptr_copy_func == (A_F_MPI_Copy_function *)&mpi_dup_fn_) {
    *((int **)attribute_val_out) = (int *)attribute_val_in;
    *flag = 1;
    return R_MPI_SUCCESS;
  }
  int comm_tmpf = A_MPI_Comm_c2f(comm_tmp);
  int res;
  (ptr_copy_func)(&comm_tmpf, &keyval, extra_state, &attribute_val_in,
                  attribute_val_out, flag, &res);
  //    ptr_copy_func = NULL;
  return error_code_conv_r2a(res);
}

int wrapper_delete_function_f(R_MPI_Comm comm, int keyval, void *attribute_val,
                              void *extra_state) {
  A_MPI_Comm comm_tmp;
  int res;
  comm_conv_r2a_static(&comm_tmp, &comm);
  int ct = A_MPI_Comm_c2f(comm_tmp);
  A_F_MPI_Delete_function *ptr_delete_func =
      myKeyval_translation_get(keyval)->del_function;
  if (ptr_delete_func != (A_F_MPI_Delete_function *)A_MPI_NULL_DELETE_FN &&
      ptr_delete_func != (A_F_MPI_Delete_function *)&mpi_null_delete_fn_)
    (ptr_delete_func)(&ct, &keyval, attribute_val, extra_state, &res);
  else
    res = R_MPI_SUCCESS;
  myKeyval_translation_get(keyval)->ref--;
  // printf("deleted %d %p %d\n",
  // keyval,comm,myKeyval_translation_get(keyval)->ref);
  if (myKeyval_translation_get(keyval)->ref == 0)
    myKeyval_translation_del(keyval);
  // ptr_delete_func = NULL;
  return error_code_conv_r2a(res);
}
void A_f_MPI_Keyval_create(void *copy_fn, void *delete_fn, int *keyval,
                           void *extra_state, int *ret) {
#ifdef DEBUG
  printf("entre : A_f_MPI_Keyval_create\n");
#endif
  in_w = 1;

  /*void *copy_fn_tmp=copy_fn;
  void *delete_fn_tmp=delete_fn;
  void *extra_state_tmp=extra_state;
  copy_ptr_converter_a2r(&copy_fn,&copy_fn_tmp);
  delete_ptr_converter_a2r(&delete_fn,&delete_fn_tmp);
  buffer_a2r(&extra_state,&extra_state_tmp);
   LOCAL_MPI_Keyval_create(copy_fn_tmp,delete_fn_tmp, keyval,extra_state_tmp,
  &ret_tmp);
  ns_t* functions = NULL;
  */
  myKeyval_functions_t *functions = NULL;

  R_MPI_Copy_function *copy_fn_tmp;
  R_MPI_Delete_function *delete_fn_tmp;
  copy_fn_tmp = wrapper_copy_function_f;
  delete_fn_tmp = wrapper_delete_function_f;

  int ret_tmp = LOCAL_MPI_Comm_create_keyval(copy_fn_tmp, delete_fn_tmp, keyval,
                                             extra_state);

  functions = (myKeyval_functions_t *)malloc(sizeof(myKeyval_functions_t));
  functions->cp_function = copy_fn;
  functions->del_function = delete_fn;
  functions->ref = 1;
  myKeyval_translation_add(*keyval, functions);

  error_r2a(ret, &ret_tmp);

  in_w = 0;
#ifdef DEBUG
  printf("sort : A_f_MPI_Keyval_create\n");
#endif
}


int A_MPI_Comm_create_keyval(A_MPI_Comm_copy_attr_function *copy_fn,
                             A_MPI_Comm_delete_attr_function *delete_fn,
                             int *keyval, void *extra_state) {
  in_w = 1;
#ifdef DEBUG
  printf("entre : A_MPI_Comm_create_keyval\n");
#endif
  myKeyval_functions_t *functions = NULL;
  R_MPI_Copy_function *copy_fn_tmp;
  R_MPI_Delete_function *delete_fn_tmp;
  if ((void *)copy_fn == (void *)A_MPI_NULL_COPY_FN) {
    copy_fn_tmp = R_MPI_NULL_COPY_FN;
  } else if ((void *)copy_fn == A_MPI_COMM_DUP_FN) {
    copy_fn_tmp = R_MPI_COMM_DUP_FN;
  } else {
    copy_fn_tmp = wrapper_copy_function;
  }
  if (delete_fn == ((A_MPI_Delete_function *)A_MPI_NULL_DELETE_FN)) {
    delete_fn_tmp = R_MPI_NULL_DELETE_FN;
  } else {
    delete_fn_tmp = wrapper_delete_function;
  }

  int ret_tmp = LOCAL_MPI_Comm_create_keyval(copy_fn_tmp, delete_fn_tmp, keyval,
                                             extra_state);

  functions = (myKeyval_functions_t *)malloc(sizeof(myKeyval_functions_t));
  functions->cp_function = copy_fn;
  functions->del_function = delete_fn;
  myKeyval_translation_add(*keyval, functions);
#ifdef DEBUG
  printf("sort : A_MPI_Comm_create_keyval\n");
#endif
  in_w = 0;
  return error_code_conv_r2a(ret_tmp);
}

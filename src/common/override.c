//############################# Wi4MPI License ###########################
//# `04/04/2016`                                                         #
//# Copyright or (C) or Copr. Commissariat a l'Energie Atomique          #
//#                                                                      #
//# IDDN.FR.001.210022.000.S.P.2014.000.10800                            #
//# This file is part of the Wi4MPI library.                             #
//#                                                                      #
//# This software is governed by the CeCILL-C license under French law   #
//# and abiding by the rules of distribution of free software. You can   #
//# use, modify and/ or redistribute the software under the terms of     #
//# the CeCILL-C license as circulated by CEA, CNRS and INRIA at the     #
//# following URL http://www.cecill.info.                                #
//#                                                                      #
//# The fact that you are presently reading this means that you have     #
//# had knowledge of the CeCILL-C license and that you accept its        #
//# terms.                                                               #
//#                                                                      #
//# Authors:                                                             #
//#   - Delforge Tony <tony.delforge.tgcc@cea.fr>                        #
//#   - Ducrot Vincent <vincent.ducrot.tgcc@cea.fr>                      #
//#                                                                      #
//########################################################################

#ifdef MPI_WAITANY_OVERRRIDE
int A_MPI_Waitany(int count, A_MPI_Request array_of_requests[], int *indx,
                  A_MPI_Status *status) {
#ifdef DEBUG
  printf("entre : A_MPI_Waitany\n");
#endif
  in_w = 1;

  *indx = 0;
  R_MPI_Request *array_of_requests_tmp =
      wi4mpi_alloc(sizeof(R_MPI_Request) * count);
  int i1, test;
  R_MPI_Status status_ltmp;
  R_MPI_Status *status_tmp = &status_ltmp;
  bzero(status_tmp, sizeof(R_MPI_Status));
  for (i1 = 0; i1 < count; i1++) {
    test = 0;
    array_of_requests_tmp[i1] = R_MPI_REQUEST_NULL;
    request_tab_conv_a2r(&array_of_requests[i1], &array_of_requests_tmp[i1]);
    if (array_of_requests[i1] != A_MPI_REQUEST_NULL) {
      int ret = R_MPI_Test(&array_of_requests_tmp[i1], &test, status_tmp);
      if (ret == R_MPI_SUCCESS && test) {
        *indx = i1;
        if (status != A_MPI_STATUS_IGNORE)
          status_prt_conv_r2a(&status, &status_tmp);
        if (array_of_requests_tmp[*indx] == R_MPI_REQUEST_NULL) {
          request_array_delete(&array_of_requests[*indx],
                               &array_of_requests_tmp[*indx]);
          array_of_requests[i1] = A_MPI_REQUEST_NULL;
        }
        wi4mpi_free(array_of_requests_tmp);
        in_w = 0;
        return A_MPI_SUCCESS;
      }
    }
  }
  int idx_tmp = 0;
  int ret_tmp = 0;
  ret_tmp =
      LOCAL_MPI_Waitany(count, array_of_requests_tmp, &idx_tmp, status_tmp);
  *indx = idx_tmp;
  if (ret_tmp == R_MPI_SUCCESS) {
    printf("%d\n", *indx);
    if (*indx != R_MPI_UNDEFINED &&
        array_of_requests_tmp[*indx] == R_MPI_REQUEST_NULL) {

      request_array_delete(&array_of_requests[*indx],
                           &array_of_requests_tmp[*indx]);
    }
  }
  if (status != A_MPI_STATUS_IGNORE)
    status_prt_conv_r2a(&status, &status_tmp);
  wi4mpi_free(array_of_requests_tmp);
  in_w = 0;
#ifdef DEBUG
  printf("sort : A_MPI_Waitany\n");
#endif
  return error_code_conv_r2a(ret_tmp);
}
#endif

#ifdef MPI_WAITALL_OVERRRIDE
int A_MPI_Waitall(int count, A_MPI_Request array_of_requests[],
                  A_MPI_Status array_of_statuses[]) {
#ifdef DEBUG
  printf("entre : A_MPI_Waitall\n");
#endif
  in_w = 1;

  R_MPI_Request *array_of_requests_tmp =
      wi4mpi_alloc(sizeof(R_MPI_Request) * count);
  R_MPI_Status *array_of_statuses_tmp =
      (array_of_statuses == A_MPI_STATUSES_IGNORE
           ? R_MPI_STATUSES_IGNORE
           : (R_MPI_Status *)wi4mpi_alloc(sizeof(R_MPI_Status) * count));
  int *offset_tmp = wi4mpi_alloc(sizeof(int) * count);
  int i1, i33;
  i33 = 0;
  for (i1 = 0; i1 < count; i1++) {
    R_MPI_Request req_tmp;
    int test, ret;
    request_tab_conv_a2r(&array_of_requests[i1], &array_of_requests_tmp[i33]);
    if (array_of_statuses == A_MPI_STATUSES_IGNORE)
      ret = LOCAL_MPI_Test(&array_of_requests_tmp[i33], &test,
                           R_MPI_STATUS_IGNORE);
    else
      ret = LOCAL_MPI_Test(&array_of_requests_tmp[i33], &test,
                           &array_of_statuses_tmp[i33]);
    if (ret != R_MPI_SUCCESS || !test) {
      offset_tmp[i33] = i1;
      i33++;
    } else {
      if (array_of_requests_tmp[i33] == R_MPI_REQUEST_NULL)
        request_array_delete(&array_of_requests[i1],
                             &array_of_requests_tmp[i33]);
      if (array_of_statuses != A_MPI_STATUSES_IGNORE)
        status_tab_conv_r2a(&array_of_statuses[i1],
                            &array_of_statuses_tmp[i33]);
    }
  }

  int ret_tmp = (i33 ? LOCAL_MPI_Waitall(i33, array_of_requests_tmp,
                                         array_of_statuses_tmp)
                     : R_MPI_SUCCESS);
  int i2;
  if (ret_tmp == R_MPI_SUCCESS) {
    for (i2 = 0; i2 < i33; i2++) {
      if (array_of_requests_tmp[i2] == R_MPI_REQUEST_NULL) {
        request_array_delete(&array_of_requests[offset_tmp[i2]],
                             &array_of_requests_tmp[i2]);
      }
    }
  }
  int i3;
  if (array_of_statuses != A_MPI_STATUSES_IGNORE && array_of_statuses) {
    for (i3 = 0; i3 < i33; i3++) {
      status_tab_conv_r2a(&array_of_statuses[offset_tmp[i3]],
                          &array_of_statuses_tmp[i3]);
    }
  }
  wi4mpi_free(array_of_requests_tmp);
  if (array_of_statuses != A_MPI_STATUSES_IGNORE)
    wi4mpi_free(array_of_statuses_tmp);
  wi4mpi_free(offset_tmp);
  in_w = 0;
#ifdef DEBUG
  printf("sort : A_MPI_Waitall\n");
#endif
  return error_code_conv_r2a(ret_tmp);
}
#endif

#ifdef MPI_WAITSOME_OVERRRIDE
int A_MPI_Waitsome(int incount, A_MPI_Request array_of_requests[],
                   int *outcount, int array_of_indices[],
                   A_MPI_Status array_of_statuses[]) {
#ifdef DEBUG
  printf("entre : A_MPI_Waitsome\n");
#endif
  in_w = 1;

  R_MPI_Request *array_of_requests_tmp =
      wi4mpi_alloc(sizeof(R_MPI_Request) * incount);
  int i1;
  for (i1 = 0; i1 < incount; i1++) {
    request_tab_conv_a2r(&array_of_requests[i1], &array_of_requests_tmp[i1]);
  }

  R_MPI_Status *array_of_statuses_tmp =
      (array_of_statuses == A_MPI_STATUSES_IGNORE
           ? R_MPI_STATUSES_IGNORE
           : (R_MPI_Status *)wi4mpi_alloc(sizeof(R_MPI_Status) * incount));
  int ret_tmp = LOCAL_MPI_Waitsome(incount, array_of_requests_tmp, outcount,
                                   array_of_indices, array_of_statuses_tmp);
  int i2;
  if (ret_tmp == R_MPI_SUCCESS) {
    for (i2 = 0; i2 < *outcount; i2++) {
      if (array_of_requests_tmp[array_of_indices[i2]] == R_MPI_REQUEST_NULL) {
        request_array_delete(&array_of_requests[array_of_indices[i2]],
                             &array_of_requests_tmp[array_of_indices[i2]]);
      }
    }
  }

  int i4;
  if (array_of_statuses != A_MPI_STATUSES_IGNORE) {
    for (i4 = 0; i4 < *outcount; i4++) {
      status_tab_conv_r2a(&array_of_statuses[i4], &array_of_statuses_tmp[i4]);
    }
  }
  wi4mpi_free(array_of_requests_tmp);
  if (array_of_statuses != A_MPI_STATUSES_IGNORE)
    wi4mpi_free(array_of_statuses_tmp);
  in_w = 0;
#ifdef DEBUG
  printf("sort : A_MPI_Waitsome\n");
#endif
  return error_code_conv_r2a(ret_tmp);
}
#endif

#ifdef MPI_TESTANY_OVERRRIDE
int A_MPI_Testany(int count, A_MPI_Request array_of_requests[], int *indx,
                  int *flag, A_MPI_Status *status) {
#ifdef DEBUG
  printf("entre : A_MPI_Testany\n");
#endif
  in_w = 1;
  int i1, test;
  for (i1 = 0; i1 < count; i1++) {
    R_MPI_Request rt;
    R_MPI_Status st;
    R_MPI_Status *pst = &st;
    request_tab_conv_a2r(&array_of_requests[i1], &rt);
    if (array_of_requests[i1] != A_MPI_REQUEST_NULL) {
      int ret = R_MPI_Test(&rt, &test, &st);
      if (ret == R_MPI_SUCCESS) {
        if (test) {
          *indx = i1;
          *flag = 1;
          status_prt_conv_r2a(&status, &pst);
          request_array_delete(&array_of_requests[*indx], &rt);

          in_w = 0;
          return A_MPI_SUCCESS;
        }
      } else {
        in_w = 0;
        return error_code_conv_r2a(ret);
      }
    }
  }
  in_w = 0;
  return A_MPI_SUCCESS;
}
#endif

#ifdef MPI_TESTALL_OVERRRIDE
int A_MPI_Testall(int count, A_MPI_Request array_of_requests[], int *flag,
                  A_MPI_Status array_of_statuses[]) {
#ifdef DEBUG
  printf("entre : A_MPI_Testall\n");
#endif
  in_w = 1;

  R_MPI_Request *array_of_requests_tmp =
      wi4mpi_alloc(sizeof(R_MPI_Request) * count);
  int i1;
  for (i1 = 0; i1 < count; i1++) {
    request_tab_conv_a2r(&array_of_requests[i1], &array_of_requests_tmp[i1]);
  }

  R_MPI_Status *array_of_statuses_tmp =
      (array_of_statuses == A_MPI_STATUSES_IGNORE
           ? R_MPI_STATUSES_IGNORE
           : (R_MPI_Status *)wi4mpi_alloc(sizeof(R_MPI_Status) * count));
  int ret_tmp = LOCAL_MPI_Testall(count, array_of_requests_tmp, flag,
                                  array_of_statuses_tmp);
  int i2;
  if (ret_tmp == R_MPI_SUCCESS) {
    if (*flag)
      for (i2 = 0; i2 < count; i2++) {
        if (array_of_requests_tmp[i2] == R_MPI_REQUEST_NULL) {
          request_array_delete(&array_of_requests[i2],
                               &array_of_requests_tmp[i2]);
        }
      }
  }

  int i3;
  if (array_of_statuses != A_MPI_STATUSES_IGNORE) {
    for (i3 = 0; i3 < count; i3++) {
      status_tab_conv_r2a(&array_of_statuses[i3], &array_of_statuses_tmp[i3]);
    }
  }
  wi4mpi_free(array_of_requests_tmp);
  if (array_of_statuses != A_MPI_STATUSES_IGNORE)
    wi4mpi_free(array_of_statuses_tmp);
  in_w = 0;
#ifdef DEBUG
  printf("sort : A_MPI_Testall\n");
#endif
  return error_code_conv_r2a(ret_tmp);
}
#endif

#ifdef MPI_TESTSOME_OVERRRIDE
int A_MPI_Testsome(int incount, A_MPI_Request array_of_requests[],
                   int *outcount, int array_of_indices[],
                   A_MPI_Status array_of_statuses[]) {
#ifdef DEBUG
  printf("entre : A_MPI_Testsome\n");
#endif
  in_w = 1;

  R_MPI_Request *array_of_requests_tmp =
      wi4mpi_alloc(sizeof(R_MPI_Request) * incount);
  int i1;
  for (i1 = 0; i1 < incount; i1++) {
    request_tab_conv_a2r(&array_of_requests[i1], &array_of_requests_tmp[i1]);
  }

  R_MPI_Status *array_of_statuses_tmp =
      (array_of_statuses == A_MPI_STATUSES_IGNORE
           ? R_MPI_STATUSES_IGNORE
           : (R_MPI_Status *)wi4mpi_alloc(sizeof(R_MPI_Status) * incount));
  int ret_tmp = LOCAL_MPI_Testsome(incount, array_of_requests_tmp, outcount,
                                   array_of_indices, array_of_statuses_tmp);
  int i2;
  if (ret_tmp == R_MPI_SUCCESS) {
    for (i2 = 0; i2 < *outcount; i2++) {
      if (array_of_requests_tmp[array_of_indices[i2]] == R_MPI_REQUEST_NULL) {
        request_array_delete(&array_of_requests[array_of_indices[i2]],
                             &array_of_requests_tmp[array_of_indices[i2]]);
      }
    }
  }

  int i4;
  if (array_of_statuses != A_MPI_STATUSES_IGNORE) {
    for (i4 = 0; i4 < *outcount; i4++) {
      status_tab_conv_r2a(&array_of_statuses[i4], &array_of_statuses_tmp[i4]);
    }
  }
  wi4mpi_free(array_of_requests_tmp);
  if (array_of_statuses != A_MPI_STATUSES_IGNORE)
    wi4mpi_free(array_of_statuses_tmp);
  in_w = 0;
#ifdef DEBUG
  printf("sort : A_MPI_Testsome\n");
#endif
  return error_code_conv_r2a(ret_tmp);
}
#endif

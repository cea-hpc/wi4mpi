#ifdef OMPI_OMPI
#define allocate_global 1
#define OMPI_LOAD_SYM 1
#include "run_mpi.h"
#define string(a) #a
#define ccc_symbol(a) ccc_##a
#define load_symbol(cte_symbol) ccc_symbol(cte_symbol)=dlsym(lib_handle,string(cte_symbol))
#include <dlfcn.h>

void init_global(void *lib_handle)
{
load_symbol(R_MPI_GROUP_NULL);
load_symbol(R_MPI_COMM_NULL);
load_symbol(R_MPI_REQUEST_NULL);
load_symbol(R_MPI_OP_NULL);
load_symbol(R_MPI_ERRHANDLER_NULL);
load_symbol(R_MPI_INFO_NULL);
load_symbol(R_MPI_WIN_NULL);
load_symbol(R_MPI_FILE_NULL);
load_symbol(R_MPI_COMM_WORLD);
load_symbol(R_MPI_COMM_SELF);
load_symbol(R_MPI_GROUP_EMPTY);
load_symbol(R_MPI_MAX);
load_symbol(R_MPI_MIN);
load_symbol(R_MPI_SUM);
load_symbol(R_MPI_PROD);
load_symbol(R_MPI_LAND);
load_symbol(R_MPI_BAND);
load_symbol(R_MPI_LOR);
load_symbol(R_MPI_BOR);
load_symbol(R_MPI_LXOR);
load_symbol(R_MPI_BXOR);
load_symbol(R_MPI_MAXLOC);
load_symbol(R_MPI_MINLOC);
load_symbol(R_MPI_REPLACE);
load_symbol(R_MPI_DATATYPE_NULL);
load_symbol(R_MPI_BYTE);
load_symbol(R_MPI_PACKED);
load_symbol(R_MPI_CHAR);
load_symbol(R_MPI_SHORT);
load_symbol(R_MPI_INT);
load_symbol(R_MPI_LONG);
load_symbol(R_MPI_FLOAT);
load_symbol(R_MPI_DOUBLE);
load_symbol(R_MPI_LONG_DOUBLE);
load_symbol(R_MPI_UNSIGNED_CHAR);
load_symbol(R_MPI_SIGNED_CHAR);
load_symbol(R_MPI_UNSIGNED_SHORT);
load_symbol(R_MPI_UNSIGNED_LONG);
load_symbol(R_MPI_UNSIGNED);
load_symbol(R_MPI_FLOAT_INT);
load_symbol(R_MPI_DOUBLE_INT);
load_symbol(R_MPI_LONG_DOUBLE_INT);
load_symbol(R_MPI_LONG_INT);
load_symbol(R_MPI_SHORT_INT);
load_symbol(R_MPI_2INT);
load_symbol(R_MPI_UB);
load_symbol(R_MPI_LB);
load_symbol(R_MPI_WCHAR);
load_symbol(R_MPI_LONG_LONG_INT);
load_symbol(R_MPI_LONG_LONG);
load_symbol(R_MPI_UNSIGNED_LONG_LONG);
load_symbol(R_MPI_2COMPLEX);
load_symbol(R_MPI_2DOUBLE_COMPLEX);
load_symbol(R_MPI_CHARACTER);
load_symbol(R_MPI_LOGICAL);
load_symbol(R_MPI_LOGICAL1);
load_symbol(R_MPI_LOGICAL2);
load_symbol(R_MPI_LOGICAL4);
load_symbol(R_MPI_LOGICAL8);
load_symbol(R_MPI_INTEGER);
load_symbol(R_MPI_INTEGER1);
load_symbol(R_MPI_INTEGER2);
load_symbol(R_MPI_INTEGER4);
load_symbol(R_MPI_INTEGER8);
load_symbol(R_MPI_REAL);
load_symbol(R_MPI_REAL4);
load_symbol(R_MPI_REAL8);
load_symbol(R_MPI_REAL16);
load_symbol(R_MPI_DOUBLE_PRECISION);
load_symbol(R_MPI_COMPLEX);
load_symbol(R_MPI_COMPLEX8);
load_symbol(R_MPI_COMPLEX32);
load_symbol(R_MPI_DOUBLE_COMPLEX);
load_symbol(R_MPI_2REAL);
load_symbol(R_MPI_2DOUBLE_PRECISION);
load_symbol(R_MPI_2INTEGER);
load_symbol(R_MPI_INT8_T);
load_symbol(R_MPI_UINT8_T);
load_symbol(R_MPI_INT16_T);
load_symbol(R_MPI_UINT16_T);
load_symbol(R_MPI_INT32_T);
load_symbol(R_MPI_UINT32_T);
load_symbol(R_MPI_INT64_T);
load_symbol(R_MPI_UINT64_T);
load_symbol(R_MPI_AINT);
load_symbol(R_MPI_OFFSET);
load_symbol(R_MPI_C_BOOL);
load_symbol(R_MPI_C_COMPLEX);
load_symbol(R_MPI_C_FLOAT_COMPLEX);
load_symbol(R_MPI_C_DOUBLE_COMPLEX);
load_symbol(R_MPI_C_LONG_DOUBLE_COMPLEX);
load_symbol(R_MPI_ERRORS_ARE_FATAL);
load_symbol(R_MPI_ERRORS_RETURN);
ccc_OMPI_C_MPI_DUP_FN=dlsym(lib_handle,"OMPI_C_MPI_DUP_FN");
ccc_OMPI_C_MPI_NULL_COPY_FN=dlsym(lib_handle,"OMPI_C_MPI_NULL_COPY_FN");
ccc_OMPI_C_MPI_NULL_DELETE_FN=dlsym(lib_handle,"OMPI_C_MPI_NULL_DELETE_FN");


}
#endif

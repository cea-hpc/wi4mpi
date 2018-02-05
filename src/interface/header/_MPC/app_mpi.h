#ifndef CCC_MPI
#define CCC_MPI

#ifndef __MPI__COMPILE__
#define A_MPI_ MPI_
#define A_PMPI_ PMPI_
#endif
typedef unsigned long size_t;
typedef size_t A_MPI_Aint;
typedef size_t A_MPI_Offset;
//typedef size_t A_MPI_Count;
typedef long long A_MPI_Count;
typedef size_t A_MPI_Comm;
typedef size_t A_MPI_Datatype;
typedef size_t A_MPI_Errhandler;
typedef size_t A_MPI_File;
typedef size_t A_MPI_Group;
typedef size_t A_MPI_Info;
typedef size_t A_MPI_Op;
typedef size_t A_MPI_Request;
typedef size_t A_MPI_Message;
//typedef size_t A_MPI_Status;
typedef size_t A_MPI_Win;
typedef size_t A_MPI_T_enum;
typedef size_t A_MPI_T_cvar_handle;
typedef size_t A_MPI_T_pvar_handle;
typedef size_t A_MPI_T_pvar_session;

typedef int A_MPI_Fint;
/*
 * A_MPI_Status
 */
struct CCC_mpi_status_struct {
    /* These fields are publicly defined in the MPI specification.
       User applications may freely read from these fields. */
    int A_MPI_SOURCE;
    int A_MPI_TAG;
    int A_MPI_ERROR;
    /* The following two fields are internal to the Open MPI
       implementation and should not be accessed by MPI applications.
       They are subject to change at any time.  These are not the
       droids you're looking for. */
    int _cancelled;
    size_t _ucount;
};
typedef struct CCC_mpi_status_struct A_MPI_Status;

/*
 * User typedefs
 *
 * Even though A_MPI_Copy_function and A_MPI_Delete_function are
 * deprecated, we do not use the attributes marking them as such,
 * because otherwise the compiler will warn for all the functions that
 * are declared using them (e.g., A_MPI_Keyval_create).
 */
typedef int (A_MPI_Copy_function)(A_MPI_Comm, int, void *,
                                void *, void *, int *);
typedef int (A_MPI_Delete_function)(A_MPI_Comm, int, void *, void *);
typedef int (A_MPI_Datarep_extent_function)(A_MPI_Datatype, A_MPI_Aint *, void *);
typedef int (A_MPI_Datarep_conversion_function)(void *, A_MPI_Datatype,
                                              int, void *, A_MPI_Offset, void *);
typedef void (A_MPI_Comm_errhandler_function)(A_MPI_Comm *, int *, ...);
typedef A_MPI_Comm_errhandler_function A_MPI_Comm_errhandler_fn;
typedef void (A_MPI_File_errhandler_fn)(A_MPI_File *, int *, ...);
typedef A_MPI_File_errhandler_fn A_MPI_File_errhandler_function;
typedef void (A_MPI_Win_errhandler_function)(A_MPI_Win *, int *, ...);
typedef A_MPI_Win_errhandler_function A_MPI_Win_errhandler_fn;
typedef void (A_MPI_Handler_function)(A_MPI_Comm *, int *, ...);
typedef void (A_MPI_User_function)(void *, void *, int *, A_MPI_Datatype *);
typedef int (A_MPI_Comm_copy_attr_function)(A_MPI_Comm, int, void *,
                                            void *, void *, int *);
typedef int (A_MPI_Comm_delete_attr_function)(A_MPI_Comm, int, void *, void *);
typedef int (A_MPI_Type_copy_attr_function)(A_MPI_Datatype, int, void *,
                                            void *, void *, int *);
typedef int (A_MPI_Type_delete_attr_function)(A_MPI_Datatype, int,
                                              void *, void *);
typedef int (A_MPI_Win_copy_attr_function)(A_MPI_Win, int, void *,
                                           void *, void *, int *);
typedef int (A_MPI_Win_delete_attr_function)(A_MPI_Win, int, void *, void *);
typedef int (A_MPI_Grequest_query_function)(void *, A_MPI_Status *);
typedef int (A_MPI_Grequest_free_function)(void *);
typedef int (A_MPI_Grequest_cancel_function)(void *, int);

/*
 * Miscellaneous constants
 */
#define A_MPI_ANY_SOURCE         -1                      /* match any source rank */
#define A_MPI_PROC_NULL          -2                      /* rank of null process */
#define A_MPI_ROOT               -4                      /* special value for intercomms */
#define A_MPI_ANY_TAG            -1                      /* match any message tag */
#define OPAL_MAX_PROCESSOR_NAME 512 /* max proc. name length */
#define OPAL_MAX_ERROR_STRING  2048   /* max error message length */
#define OPAL_MAX_OBJECT_NAME   1024    /* max object name length */
#define A_MPI_MAX_LIBRARY_VERSION_STRING 256             /* max length of library version string */
#define A_MPI_UNDEFINED          -32766                  /* undefined stuff */
#define A_MPI_DIST_GRAPH         3                       /* dist graph topology */
#define A_MPI_CART               1                       /* cartesian topology */
#define A_MPI_GRAPH              2                       /* graph topology */
#define A_MPI_KEYVAL_INVALID     -1                      /* invalid key value */

/*
 * More constants
 */
#define A_MPI_UNWEIGHTED           ((void *) 2)          /* unweighted graph */
#define A_MPI_WEIGHTS_EMPTY        ((void *) 3)          /* empty weights */
#define A_MPI_BOTTOM               ((void *) 0)          /* base reference address */
#define A_MPI_IN_PLACE             ((void *) 1)          /* in place buffer */
#define A_MPI_BSEND_OVERHEAD       128                   /* size of bsend header + ptr */
#define A_MPI_MAX_INFO_KEY 256     /* max info key length */
#define A_MPI_MAX_INFO_VAL 512     /* max info value length */
#define A_MPI_ARGV_NULL            ((char **) 0)         /* NULL argument vector */
#define A_MPI_ARGVS_NULL           ((char ***) 0)        /* NULL argument vectors */
#define A_MPI_ERRCODES_IGNORE      ((int *) 0)           /* don't return error codes */
#define A_MPI_MAX_PORT_NAME 512    /* max port name length */
#define A_MPI_ORDER_C              0                     /* C row major order */
#define A_MPI_ORDER_FORTRAN        1                     /* Fortran column major order */
#define A_MPI_DISTRIBUTE_BLOCK     0                     /* block distribution */
#define A_MPI_DISTRIBUTE_CYCLIC    1                     /* cyclic distribution */
#define A_MPI_DISTRIBUTE_NONE      2                     /* not distributed */
#define A_MPI_DISTRIBUTE_DFLT_DARG (-1)                  /* default distribution arg */

/*
 * Since these values are arbitrary to Open MPI, we might as well make
 * them the same as ROMIO for ease of mapping.  These values taken
 * from ROMIO's mpio.h file.
 */
#define A_MPI_MODE_CREATE              1  /* ADIO_CREATE */
#define A_MPI_MODE_RDONLY              2  /* ADIO_RDONLY */
#define A_MPI_MODE_WRONLY              4  /* ADIO_WRONLY  */
#define A_MPI_MODE_RDWR                8  /* ADIO_RDWR  */
#define A_MPI_MODE_DELETE_ON_CLOSE    16  /* ADIO_DELETE_ON_CLOSE */
#define A_MPI_MODE_UNIQUE_OPEN        32  /* ADIO_UNIQUE_OPEN */
#define A_MPI_MODE_EXCL               64  /* ADIO_EXCL */
#define A_MPI_MODE_APPEND            128  /* ADIO_APPEND */
#define A_MPI_MODE_SEQUENTIAL        256  /* ADIO_SEQUENTIAL */

#define A_MPI_DISPLACEMENT_CURRENT   -54278278

#define A_MPI_SEEK_SET               600
#define A_MPI_SEEK_CUR               602
#define A_MPI_SEEK_END               604

/* Max data representation length */
#define A_MPI_MAX_DATAREP_STRING 512

/*
 * MPI-2 One-Sided Communications asserts
 */
#define A_MPI_MODE_NOCHECK             1
#define A_MPI_MODE_NOPRECEDE           2
#define A_MPI_MODE_NOPUT               4
#define A_MPI_MODE_NOSTORE             8
#define A_MPI_MODE_NOSUCCEED          16

#define A_MPI_LOCK_EXCLUSIVE           1
#define A_MPI_LOCK_SHARED              2

#define A_MPI_WIN_FLAVOR_CREATE        1
#define A_MPI_WIN_FLAVOR_ALLOCATE      2
#define A_MPI_WIN_FLAVOR_DYNAMIC       3
#define A_MPI_WIN_FLAVOR_SHARED        4

#define A_MPI_WIN_UNIFIED              0
#define A_MPI_WIN_SEPARATE             1

/*
 * Predefined attribute keyvals
 *
 * DO NOT CHANGE THE ORDER WITHOUT ALSO CHANGING THE ORDER IN
 * src/attribute/attribute_predefined.c and mpif.h.in.
 */
enum {
    /* MPI-1 */
    A_MPI_TAG_UB,
    A_MPI_HOST,
    A_MPI_IO,
    A_MPI_WTIME_IS_GLOBAL,

    /* MPI-2 */
    A_MPI_APPNUM,
    A_MPI_LASTUSEDCODE,
    A_MPI_UNIVERSE_SIZE,
    A_MPI_WIN_BASE,
    A_MPI_WIN_SIZE,
    A_MPI_WIN_DISP_UNIT,
    A_MPI_WIN_CREATE_FLAVOR,
    A_MPI_WIN_MODEL,

    /* Even though these four are IMPI attributes, they need to be there
       for all MPI jobs */
    IA_MPI_CLIENT_SIZE,
    IA_MPI_CLIENT_COLOR,
    IA_MPI_HOST_SIZE,
    IA_MPI_HOST_COLOR
};

/*
 * Error classes and codes
 * Do not change the values of these without also modifying mpif.h.in.
 */
#define A_MPI_SUCCESS                   0
#define A_MPI_ERR_BUFFER                1
#define A_MPI_ERR_COUNT                 2
#define A_MPI_ERR_TYPE                  3
#define A_MPI_ERR_TAG                   4
#define A_MPI_ERR_COMM                  5
#define A_MPI_ERR_RANK                  6
#define A_MPI_ERR_REQUEST               7
#define A_MPI_ERR_ROOT                  8
#define A_MPI_ERR_GROUP                 9
#define A_MPI_ERR_OP                    10
#define A_MPI_ERR_TOPOLOGY              11
#define A_MPI_ERR_DIMS                  12
#define A_MPI_ERR_ARG                   13
#define A_MPI_ERR_UNKNOWN               14
#define A_MPI_ERR_TRUNCATE              15
#define A_MPI_ERR_OTHER                 16
#define A_MPI_ERR_INTERN                17
#define A_MPI_ERR_IN_STATUS             18
#define A_MPI_ERR_PENDING               19
#define A_MPI_ERR_ACCESS                20
#define A_MPI_ERR_AMODE                 21
#define A_MPI_ERR_ASSERT                22
#define A_MPI_ERR_BAD_FILE              23
#define A_MPI_ERR_BASE                  24
#define A_MPI_ERR_CONVERSION            25
#define A_MPI_ERR_DISP                  26
#define A_MPI_ERR_DUP_DATAREP           27
#define A_MPI_ERR_FILE_EXISTS           28
#define A_MPI_ERR_FILE_IN_USE           29
#define A_MPI_ERR_FILE                  30
#define A_MPI_ERR_INFO_KEY              31
#define A_MPI_ERR_INFO_NOKEY            32
#define A_MPI_ERR_INFO_VALUE            33
#define A_MPI_ERR_INFO                  34
#define A_MPI_ERR_IO                    35
#define A_MPI_ERR_KEYVAL                36
#define A_MPI_ERR_LOCKTYPE              37
#define A_MPI_ERR_NAME                  38
#define A_MPI_ERR_NO_MEM                39
#define A_MPI_ERR_NOT_SAME              40
#define A_MPI_ERR_NO_SPACE              41
#define A_MPI_ERR_NO_SUCH_FILE          42
#define A_MPI_ERR_PORT                  43
#define A_MPI_ERR_QUOTA                 44
#define A_MPI_ERR_READ_ONLY             45
#define A_MPI_ERR_RMA_CONFLICT          46
#define A_MPI_ERR_RMA_SYNC              47
#define A_MPI_ERR_SERVICE               48
#define A_MPI_ERR_SIZE                  49
#define A_MPI_ERR_SPAWN                 50
#define A_MPI_ERR_UNSUPPORTED_DATAREP   51
#define A_MPI_ERR_UNSUPPORTED_OPERATION 52
#define A_MPI_ERR_WIN                   53
#define A_MPI_T_ERR_MEMORY              54
#define A_MPI_T_ERR_NOT_INITIALIZED     55
#define A_MPI_T_ERR_CANNOT_INIT         56
#define A_MPI_T_ERR_INVALID_INDEX       57
#define A_MPI_T_ERR_INVALID_ITEM        58
#define A_MPI_T_ERR_INVALID_HANDLE      59
#define A_MPI_T_ERR_OUT_OF_HANDLES      60
#define A_MPI_T_ERR_OUT_OF_SESSIONS     61
#define A_MPI_T_ERR_INVALID_SESSION     62
#define A_MPI_T_ERR_CVAR_SET_NOT_NOW    63
#define A_MPI_T_ERR_CVAR_SET_NEVER      64
#define A_MPI_T_ERR_PVAR_NO_STARTSTOP   65
#define A_MPI_T_ERR_PVAR_NO_WRITE       66
#define A_MPI_T_ERR_PVAR_NO_ATOMIC      67
#define A_MPI_ERR_RMA_RANGE             74
#define A_MPI_ERR_RMA_ATTACH            75
#define A_MPI_ERR_RMA_FLAVOR            70
#define A_MPI_ERR_RMA_SHARED            76

/* for 1.8 these intentially overlap other error codes because A_MPI_ERR_LASTCODE
   can not be changed in a release series*/
#define A_MPI_T_ERR_INVALID             70
#define A_MPI_T_ERR_INVALID_NAME        71

/* Per MPI-3 p349 47, A_MPI_ERR_LASTCODE must be >= the last predefined
   A_MPI_ERR_<foo> code.  So just set it equal to the last code --
   A_MPI_ERR_RMA_SHARED, in this case. */
#define A_MPI_ERR_LASTCODE              A_MPI_ERR_RMA_SHARED            76

#define A_MPI_ERR_SYSRESOURCE          -2


/*
 * Comparison results.  Don't change the order of these, the group
 * comparison functions rely on it.
 * Do not change the order of these without also modifying mpif.h.in.
 */
enum {
  A_MPI_IDENT,
  A_MPI_CONGRUENT,
  A_MPI_SIMILAR,
  A_MPI_UNEQUAL
};

/*
 * A_MPI_Init_thread constants
 * Do not change the order of these without also modifying mpif.h.in.
 */
enum {
  A_MPI_THREAD_SINGLE,
  A_MPI_THREAD_FUNNELED,
  A_MPI_THREAD_SERIALIZED,
  A_MPI_THREAD_MULTIPLE
};

/*
 * Datatype combiners.
 * Do not change the order of these without also modifying mpif.h.in.
 * (see also mpif-common.h.fin).
 */
enum {
  A_MPI_COMBINER_NAMED,
  A_MPI_COMBINER_DUP,
  A_MPI_COMBINER_CONTIGUOUS,
  A_MPI_COMBINER_VECTOR,
  A_MPI_COMBINER_HVECTOR_INTEGER,
  A_MPI_COMBINER_HVECTOR,
  A_MPI_COMBINER_INDEXED,
  A_MPI_COMBINER_HINDEXED_INTEGER,
  A_MPI_COMBINER_HINDEXED,
  A_MPI_COMBINER_INDEXED_BLOCK,
  A_MPI_COMBINER_STRUCT_INTEGER,
  A_MPI_COMBINER_STRUCT,
  A_MPI_COMBINER_SUBARRAY,
  A_MPI_COMBINER_DARRAY,
  A_MPI_COMBINER_F90_REAL,
  A_MPI_COMBINER_F90_COMPLEX,
  A_MPI_COMBINER_F90_INTEGER,
  A_MPI_COMBINER_RESIZED,
  A_MPI_COMBINER_HINDEXED_BLOCK
};

/*
 * Communicator split type constants.
 * Do not change the order of these without also modifying mpif.h.in
 * (see also mpif-common.h.fin).
 */
enum {
  A_MPI_COMM_TYPE_SHARED
};

/*
 * MPIT Verbosity Levels
 */
enum {
  A_MPI_T_VERBOSITY_USER_BASIC,
  A_MPI_T_VERBOSITY_USER_DETAIL,
  A_MPI_T_VERBOSITY_USER_ALL,
  A_MPI_T_VERBOSITY_TUNER_BASIC,
  A_MPI_T_VERBOSITY_TUNER_DETAIL,
  A_MPI_T_VERBOSITY_TUNER_ALL,
  A_MPI_T_VERBOSITY_MPIDEV_BASIC,
  A_MPI_T_VERBOSITY_MPIDEV_DETAIL,
  A_MPI_T_VERBOSITY_MPIDEV_ALL
};

/*
 * MPIT Scopes
 */
enum {
  A_MPI_T_SCOPE_CONSTANT,
  A_MPI_T_SCOPE_READONLY,
  A_MPI_T_SCOPE_LOCAL,
  A_MPI_T_SCOPE_GROUP,
  A_MPI_T_SCOPE_GROUP_EQ,
  A_MPI_T_SCOPE_ALL,
  A_MPI_T_SCOPE_ALL_EQ
};

/*
 * MPIT Object Binding
 */
enum {
  A_MPI_T_BIND_NO_OBJECT,
  A_MPI_T_BIND_A_MPI_COMM,
  A_MPI_T_BIND_A_MPI_DATATYPE,
  A_MPI_T_BIND_A_MPI_ERRHANDLER,
  A_MPI_T_BIND_A_MPI_FILE,
  A_MPI_T_BIND_A_MPI_GROUP,
  A_MPI_T_BIND_A_MPI_OP,
  A_MPI_T_BIND_A_MPI_REQUEST,
  A_MPI_T_BIND_A_MPI_WIN,
  A_MPI_T_BIND_A_MPI_MESSAGE,
  A_MPI_T_BIND_A_MPI_INFO
};

/*
 * MPIT pvar classes
 */
enum {
  A_MPI_T_PVAR_CLASS_STATE,
  A_MPI_T_PVAR_CLASS_LEVEL,
  A_MPI_T_PVAR_CLASS_SIZE,
  A_MPI_T_PVAR_CLASS_PERCENTAGE,
  A_MPI_T_PVAR_CLASS_HIGHWATERMARK,
  A_MPI_T_PVAR_CLASS_LOWWATERMARK,
  A_MPI_T_PVAR_CLASS_COUNTER,
  A_MPI_T_PVAR_CLASS_AGGREGATE,
  A_MPI_T_PVAR_CLASS_TIMER,
  A_MPI_T_PVAR_CLASS_GENERIC
};

/*
 * NULL handles
 */
#define A_MPI_GROUP_NULL 0x0
#define A_MPI_COMM_NULL 0x0
#define A_MPI_REQUEST_NULL 0x0
#define A_MPI_MESSAGE_NULL 0x0
#define A_MPI_OP_NULL 0x0
#define A_MPI_ERRHANDLER_NULL 0x0
#define A_MPI_INFO_NULL 0x0
#define A_MPI_WIN_NULL 0x0
#define A_MPI_FILE_NULL 0x0
#define A_MPI_T_ENUM_NULL 0x0

/*
 * A_MPI_INFO_ENV handle
 */
#define A_MPI_INFO_ENV 0x0 

#define A_MPI_STATUS_IGNORE 0x0
#define A_MPI_STATUSES_IGNORE 0x0

/*
 * Special A_MPI_T handles
 */
#define A_MPI_T_PVAR_ALL_HANDLES ((A_MPI_T_pvar_handle) -1)
#define A_MPI_T_PVAR_HANDLE_NULL ((A_MPI_T_pvar_handle) 0)
#define A_MPI_T_CVAR_HANDLE_NULL ((A_MPI_T_cvar_handle) 0)


#define A_MPI_NULL_DELETE_FN  0x0
#define A_MPI_NULL_COPY_FN  0x0
#define A_MPI_DUP_FN  0x1

#define A_MPI_TYPE_NULL_DELETE_FN  0x0
#define A_MPI_TYPE_NULL_COPY_FN  0x0
#define A_MPI_TYPE_DUP_FN  0x1

#define A_MPI_COMM_NULL_DELETE_FN  0x0
#define A_MPI_COMM_NULL_COPY_FN  0x0
#define A_MPI_COMM_DUP_FN  0x1

#define A_MPI_WIN_NULL_DELETE_FN  0x0
#define A_MPI_WIN_NULL_COPY_FN  0x0
#define A_MPI_WIN_DUP_FN  0x1

/* A_MPI_CONVERSION_FN_NULL is a sentinel value, but it has to be large
   enough to be the same size as a valid function pointer.  It
   therefore shares many characteristics between Fortran constants and
   Fortran sentinel functions.  For example, it shares the problem of
   having Fortran compilers have all-caps versions of the symbols that
   must be able to be present, and therefore has to be in this
   conditional block in mpi.h. */
#define A_MPI_CONVERSION_FN_NULL ((A_MPI_Datarep_conversion_function*) 0)
 //extern struct ompi_predefined_datatype_t ompi_mpi_cxx_cplex;


/*
 * MPI predefined handles
 */
#define A_MPI_COMM_WORLD 0x1
#define A_MPI_COMM_SELF 0x2

#define A_MPI_GROUP_EMPTY 0x1

#define A_MPI_MESSAGE_NO_PROC 0x1

#define A_MPI_MAX 1
#define A_MPI_MIN 2
#define A_MPI_SUM 3
#define A_MPI_PROD 4
#define A_MPI_LAND 5
#define A_MPI_BAND 6
#define A_MPI_LOR 7
#define A_MPI_BOR 8
#define A_MPI_LXOR 9
#define A_MPI_BXOR 10
#define A_MPI_MAXLOC 11
#define A_MPI_MINLOC 12
#define A_MPI_REPLACE 13
#define A_MPI_NO_OP 14

/* C datatypes */
#define A_MPI_DATATYPE_NULL 0
#define A_MPI_BYTE 1
#define A_MPI_PACKED 2
#define A_MPI_CHAR 3
#define A_MPI_SHORT 4
#define A_MPI_INT 5
#define A_MPI_LONG 6
#define A_MPI_FLOAT 7
#define A_MPI_DOUBLE 8
#define A_MPI_LONG_DOUBLE 9
#define A_MPI_UNSIGNED_CHAR 10
#define A_MPI_SIGNED_CHAR 11
#define A_MPI_UNSIGNED_SHORT 12
#define A_MPI_UNSIGNED_LONG 13
#define A_MPI_UNSIGNED 14
#define A_MPI_FLOAT_INT 15
#define A_MPI_DOUBLE_INT 16
#define A_MPI_LONG_DOUBLE_INT 17
#define A_MPI_LONG_INT 18
#define A_MPI_SHORT_INT 19
#define A_MPI_2INT 20
#define A_MPI_UB 21
#define A_MPI_LB 22
#define A_MPI_WCHAR 23
#define A_MPI_LONG_LONG_INT 24
#define A_MPI_LONG_LONG 25
#define A_MPI_UNSIGNED_LONG_LONG 26
#define A_MPI_2COMPLEX 27
#define A_MPI_2DOUBLE_COMPLEX 28

/* Fortran datatype bindings */
#define A_MPI_CHARACTER 29
#define A_MPI_LOGICAL 30
#define A_MPI_LOGICAL1 31
#define A_MPI_LOGICAL2 32
#define A_MPI_LOGICAL4 33
#define A_MPI_LOGICAL8 34
#define A_MPI_INTEGER 35
#define A_MPI_INTEGER1 36
#define A_MPI_INTEGER2 37
#define A_MPI_INTEGER4 38
#define A_MPI_INTEGER8 39
#define A_MPI_INTEGER16 40
#define A_MPI_REAL 41
#define A_MPI_REAL4 42
#define A_MPI_REAL8 43
#define A_MPI_REAL16 44
#define A_MPI_DOUBLE_PRECISION 45
#define A_MPI_COMPLEX 46
#define A_MPI_COMPLEX8 47
#define A_MPI_COMPLEX16 48
#define A_MPI_COMPLEX32 49
#define A_MPI_DOUBLE_COMPLEX 50
#define A_MPI_2REAL 51
#define A_MPI_2DOUBLE_PRECISION 52
#define A_MPI_2INTEGER 53

/* New datatypes from the MPI 2.2 standard */
#define A_MPI_INT8_T                54
#define A_MPI_UINT8_T               55
#define A_MPI_INT16_T               56
#define A_MPI_UINT16_T              57
#define A_MPI_INT32_T               58
#define A_MPI_UINT32_T              59
#define A_MPI_INT64_T               60
#define A_MPI_UINT64_T              61
#define A_MPI_AINT                  62
#define A_MPI_OFFSET                63
#define A_MPI_C_BOOL                64
#define A_MPI_C_COMPLEX             65
#define A_MPI_C_FLOAT_COMPLEX       66
#define A_MPI_C_DOUBLE_COMPLEX      67
#define A_MPI_C_LONG_DOUBLE_COMPLEX 68
#define A_MPI_CXX_BOOL              69
#define A_MPI_CXX_FLOAT_COMPLEX     70
#define A_MPI_CXX_DOUBLE_COMPLEX    71
#define A_MPI_CXX_LONG_DOUBLE_COMPLEX 72

/* New datatypes from the 3.0 standard */
#define A_MPI_COUNT 73 

#define A_MPI_ERRORS_ARE_FATAL 1
#define A_MPI_ERRORS_RETURN 2 

/* Typeclass definition for A_MPI_Type_match_size */
#define A_MPI_TYPECLASS_INTEGER    1
#define A_MPI_TYPECLASS_REAL       2
#define A_MPI_TYPECLASS_COMPLEX    3


/*
 * MPI API
 */

  int A_MPI_Abort(A_MPI_Comm comm, int errorcode);
  int A_MPI_Accumulate(void *origin_addr, int origin_count, A_MPI_Datatype origin_datatype,
                                  int target_rank, A_MPI_Aint target_disp, int target_count,
                                  A_MPI_Datatype target_datatype, A_MPI_Op op, A_MPI_Win win);
  int A_MPI_Add_error_class(int *errorclass);
  int A_MPI_Add_error_code(int errorclass, int *errorcode);
  int A_MPI_Add_error_string(int errorcode, char *string);
  int A_MPI_Address(void *location, A_MPI_Aint *address);
  int A_MPI_Allgather(void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                                 void *recvbuf, int recvcount,
                                 A_MPI_Datatype recvtype, A_MPI_Comm comm);
  int A_MPI_Iallgather(void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                                 void *recvbuf, int recvcount,
                                 A_MPI_Datatype recvtype, A_MPI_Comm comm, A_MPI_Request *request);
  int A_MPI_Allgatherv(void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                                  void *recvbuf, int recvcounts[],
                                  int displs[], A_MPI_Datatype recvtype, A_MPI_Comm comm);
  int A_MPI_Iallgatherv(void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                                  void *recvbuf, int recvcounts[],
                                  int displs[], A_MPI_Datatype recvtype, A_MPI_Comm comm, A_MPI_Request *request);
  int A_MPI_Alloc_mem(A_MPI_Aint size, A_MPI_Info info,
                                 void *baseptr);
  int A_MPI_Allreduce(void *sendbuf, void *recvbuf, int count,
                                 A_MPI_Datatype datatype, A_MPI_Op op, A_MPI_Comm comm);
  int A_MPI_Iallreduce(void *sendbuf, void *recvbuf, int count,
                                 A_MPI_Datatype datatype, A_MPI_Op op, A_MPI_Comm comm, A_MPI_Request *request);
  int A_MPI_Alltoall(void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                                void *recvbuf, int recvcount,
                                A_MPI_Datatype recvtype, A_MPI_Comm comm);
  int A_MPI_Ialltoall(void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                                void *recvbuf, int recvcount,
                                A_MPI_Datatype recvtype, A_MPI_Comm comm, A_MPI_Request *request);
  int A_MPI_Alltoallv(void *sendbuf, int sendcounts[], int sdispls[],
                                 A_MPI_Datatype sendtype, void *recvbuf, int recvcounts[],
                                 int rdispls[], A_MPI_Datatype recvtype, A_MPI_Comm comm);
  int A_MPI_Ialltoallv(void *sendbuf, int sendcounts[], int sdispls[],
                                 A_MPI_Datatype sendtype, void *recvbuf, int recvcounts[],
                                 int rdispls[], A_MPI_Datatype recvtype, A_MPI_Comm comm, A_MPI_Request *request);
  int A_MPI_Alltoallw(void *sendbuf, int sendcounts[], int sdispls[], A_MPI_Datatype sendtypes[],
                                 void *recvbuf, int recvcounts[], int rdispls[], A_MPI_Datatype recvtypes[],
                                 A_MPI_Comm comm);
  int A_MPI_Ialltoallw(void *sendbuf, int sendcounts[], int sdispls[], A_MPI_Datatype sendtypes[],
                                 void *recvbuf, int recvcounts[], int rdispls[], A_MPI_Datatype recvtypes[],
                                 A_MPI_Comm comm, A_MPI_Request *request);
  int A_MPI_Attr_delete(A_MPI_Comm comm, int keyval);
  int A_MPI_Attr_get(A_MPI_Comm comm, int keyval, void *attribute_val, int *flag);
  int A_MPI_Attr_put(A_MPI_Comm comm, int keyval, void *attribute_val);
  int A_MPI_Barrier(A_MPI_Comm comm);
  int A_MPI_Ibarrier(A_MPI_Comm comm, A_MPI_Request *request);
  int A_MPI_Bcast(void *buffer, int count, A_MPI_Datatype datatype,
                             int root, A_MPI_Comm comm);
  int A_MPI_Bsend(void *buf, int count, A_MPI_Datatype datatype,
                             int dest, int tag, A_MPI_Comm comm);
  int A_MPI_Ibcast(void *buffer, int count, A_MPI_Datatype datatype,
				                              int root, A_MPI_Comm comm,
											  A_MPI_Request *request);
  int A_MPI_Bsend_init(void *buf, int count, A_MPI_Datatype datatype,
                                  int dest, int tag, A_MPI_Comm comm, A_MPI_Request *request);
  int A_MPI_Buffer_attach(void *buffer, int size);
  int A_MPI_Buffer_detach(void *buffer, int *size);
  int A_MPI_Cancel(A_MPI_Request *request);
  int A_MPI_Cart_coords(A_MPI_Comm comm, int rank, int maxdims, int coords[]);
  int A_MPI_Cart_create(A_MPI_Comm old_comm, int ndims, int dims[],
                                   int periods[], int reorder, A_MPI_Comm *comm_cart);
  int A_MPI_Cart_get(A_MPI_Comm comm, int maxdims, int dims[],
                                int periods[], int coords[]);
  int A_MPI_Cart_map(A_MPI_Comm comm, int ndims, int dims[],
                                int periods[], int *newrank);
  int A_MPI_Cart_rank(A_MPI_Comm comm, int coords[], int *rank);
  int A_MPI_Cart_shift(A_MPI_Comm comm, int direction, int disp,
                                  int *rank_source, int *rank_dest);
  int A_MPI_Cart_sub(A_MPI_Comm comm, int remain_dims[], A_MPI_Comm *new_comm);
  int A_MPI_Cartdim_get(A_MPI_Comm comm, int *ndims);
  int A_MPI_Close_port(char *port_name);
  int A_MPI_Comm_accept(char *port_name, A_MPI_Info info, int root,
                                   A_MPI_Comm comm, A_MPI_Comm *newcomm);
  A_MPI_Fint A_MPI_Comm_c2f(A_MPI_Comm comm);
  int A_MPI_Comm_call_errhandler(A_MPI_Comm comm, int errorcode);
  int A_MPI_Comm_compare(A_MPI_Comm comm1, A_MPI_Comm comm2, int *result);
  int A_MPI_Comm_connect(char *port_name, A_MPI_Info info, int root,
                                    A_MPI_Comm comm, A_MPI_Comm *newcomm);
  int A_MPI_Comm_create_errhandler(A_MPI_Comm_errhandler_function *function,
                                              A_MPI_Errhandler *errhandler);
  int A_MPI_Comm_create_keyval(A_MPI_Comm_copy_attr_function *comm_copy_attr_fn,
                                          A_MPI_Comm_delete_attr_function *comm_delete_attr_fn,
                                          int *comm_keyval, void *extra_state);
  int A_MPI_Comm_create_group(A_MPI_Comm comm, A_MPI_Group group, int tag, A_MPI_Comm *newcomm);
  int A_MPI_Comm_create(A_MPI_Comm comm, A_MPI_Group group, A_MPI_Comm *newcomm);
  int A_MPI_Comm_delete_attr(A_MPI_Comm comm, int comm_keyval);
  int A_MPI_Comm_disconnect(A_MPI_Comm *comm);
  int A_MPI_Comm_dup(A_MPI_Comm comm, A_MPI_Comm *newcomm);
  int A_MPI_Comm_idup(A_MPI_Comm comm, A_MPI_Comm *newcomm, A_MPI_Request *request);
  int A_MPI_Comm_dup_with_info(A_MPI_Comm comm, A_MPI_Info info, A_MPI_Comm *newcomm);
  A_MPI_Comm A_MPI_Comm_f2c(A_MPI_Fint comm);
  int A_MPI_Comm_free_keyval(int *comm_keyval);
  int A_MPI_Comm_free(A_MPI_Comm *comm);
  int A_MPI_Comm_get_attr(A_MPI_Comm comm, int comm_keyval,
                                     void *attribute_val, int *flag);
  int A_MPI_Dist_graph_create(A_MPI_Comm comm_old, int n, int nodes[],
                                         int degrees[], int targets[],
                                         int weights[], A_MPI_Info info,
                                         int reorder, A_MPI_Comm * newcomm);
  int A_MPI_Dist_graph_create_adjacent(A_MPI_Comm comm_old,
                                                  int indegree, int sources[],
                                                  int sourceweights[],
                                                  int outdegree,
                                                  int destinations[],
                                                  int destweights[],
                                                  A_MPI_Info info, int reorder,
                                                  A_MPI_Comm *comm_dist_graph);
 int A_MPI_Dist_graph_neighbors(A_MPI_Comm comm, int maxindegree,
                                           int sources[], int sourceweights[],
                                           int maxoutdegree,
                                           int destinations[],
                                           int destweights[]);
  int A_MPI_Dist_graph_neighbors_count(A_MPI_Comm comm,
                                                  int *inneighbors,
                                                  int *outneighbors,
                                                  int *weighted);
  int A_MPI_Comm_get_errhandler(A_MPI_Comm comm, A_MPI_Errhandler *erhandler);
  int A_MPI_Comm_get_info(A_MPI_Comm comm, A_MPI_Info *info_used);
  int A_MPI_Comm_get_name(A_MPI_Comm comm, char *comm_name, int *resultlen);
  int A_MPI_Comm_get_parent(A_MPI_Comm *parent);
  int A_MPI_Comm_group(A_MPI_Comm comm, A_MPI_Group *group);
  int A_MPI_Comm_join(int fd, A_MPI_Comm *intercomm);
  int A_MPI_Comm_rank(A_MPI_Comm comm, int *rank);
  int A_MPI_Comm_remote_group(A_MPI_Comm comm, A_MPI_Group *group);
  int A_MPI_Comm_remote_size(A_MPI_Comm comm, int *size);
  int A_MPI_Comm_set_attr(A_MPI_Comm comm, int comm_keyval, void *attribute_val);
  int A_MPI_Comm_set_errhandler(A_MPI_Comm comm, A_MPI_Errhandler errhandler);
  int A_MPI_Comm_set_info(A_MPI_Comm comm, A_MPI_Info info);
  int A_MPI_Comm_set_name(A_MPI_Comm comm, char *comm_name);
  int A_MPI_Comm_size(A_MPI_Comm comm, int *size);
  int A_MPI_Comm_spawn(char *command, char *argv[], int maxprocs, A_MPI_Info info,
                                  int root, A_MPI_Comm comm, A_MPI_Comm *intercomm,
                                  int array_of_errcodes[]);
  int A_MPI_Comm_spawn_multiple(int count, char *array_of_commands[], char **array_of_argv[],
                                           int array_of_maxprocs[], A_MPI_Info array_of_info[],
                                           int root, A_MPI_Comm comm, A_MPI_Comm *intercomm,
                                           int array_of_errcodes[]);
  int A_MPI_Comm_split(A_MPI_Comm comm, int color, int key, A_MPI_Comm *newcomm);
  int A_MPI_Comm_split_type(A_MPI_Comm comm, int split_type, int key, A_MPI_Info info, A_MPI_Comm *newcomm);
  int A_MPI_Comm_test_inter(A_MPI_Comm comm, int *flag);
  int A_MPI_Compare_and_swap(void *origin_addr, void *compare_addr,
                                        void *result_addr, A_MPI_Datatype datatype, int target_rank,
                                        A_MPI_Aint target_disp, A_MPI_Win win);
  int A_MPI_Dims_create(int nnodes, int ndims, int dims[]);
  A_MPI_Fint A_MPI_Errhandler_c2f(A_MPI_Errhandler errhandler);
  int A_MPI_Errhandler_create(A_MPI_Handler_function *function,
                                         A_MPI_Errhandler *errhandler);
  A_MPI_Errhandler A_MPI_Errhandler_f2c(A_MPI_Fint errhandler);
  int A_MPI_Errhandler_free(A_MPI_Errhandler *errhandler);
  int A_MPI_Errhandler_get(A_MPI_Comm comm, A_MPI_Errhandler *errhandler);
  int A_MPI_Errhandler_set(A_MPI_Comm comm, A_MPI_Errhandler errhandler);
  int A_MPI_Error_class(int errorcode, int *errorclass);
  int A_MPI_Error_string(int errorcode, char *string, int *resultlen);
  int A_MPI_Exscan(void *sendbuf, void *recvbuf, int count,
                              A_MPI_Datatype datatype, A_MPI_Op op, A_MPI_Comm comm);
  int A_MPI_Fetch_and_op(void *origin_addr, void *result_addr, A_MPI_Datatype datatype,
                                    int target_rank, A_MPI_Aint target_disp, A_MPI_Op op, A_MPI_Win win);
  int A_MPI_Iexscan(void *sendbuf, void *recvbuf, int count,
                              A_MPI_Datatype datatype, A_MPI_Op op, A_MPI_Comm comm, A_MPI_Request *request);
  A_MPI_Fint A_MPI_File_c2f(A_MPI_File file);
  A_MPI_File A_MPI_File_f2c(A_MPI_Fint file);
  int A_MPI_File_call_errhandler(A_MPI_File fh, int errorcode);
  int A_MPI_File_create_errhandler(A_MPI_File_errhandler_function *function,
                                              A_MPI_Errhandler *errhandler);
  int A_MPI_File_set_errhandler( A_MPI_File file, A_MPI_Errhandler errhandler);
  int A_MPI_File_get_errhandler( A_MPI_File file, A_MPI_Errhandler *errhandler);
  int A_MPI_File_open(A_MPI_Comm comm, char *filename, int amode,
                                 A_MPI_Info info, A_MPI_File *fh);
  int A_MPI_File_close(A_MPI_File *fh);
  int A_MPI_File_delete(char *filename, A_MPI_Info info);
  int A_MPI_File_set_size(A_MPI_File fh, A_MPI_Offset size);
  int A_MPI_File_preallocate(A_MPI_File fh, A_MPI_Offset size);
  int A_MPI_File_get_size(A_MPI_File fh, A_MPI_Offset *size);
  int A_MPI_File_get_group(A_MPI_File fh, A_MPI_Group *group);
  int A_MPI_File_get_amode(A_MPI_File fh, int *amode);
  int A_MPI_File_set_info(A_MPI_File fh, A_MPI_Info info);
  int A_MPI_File_get_info(A_MPI_File fh, A_MPI_Info *info_used);
  int A_MPI_File_set_view(A_MPI_File fh, A_MPI_Offset disp, A_MPI_Datatype etype,
                                     A_MPI_Datatype filetype, char *datarep, A_MPI_Info info);
  int A_MPI_File_get_view(A_MPI_File fh, A_MPI_Offset *disp,
                                     A_MPI_Datatype *etype,
                                     A_MPI_Datatype *filetype, char *datarep);
  int A_MPI_File_read_at(A_MPI_File fh, A_MPI_Offset offset, void *buf,
                                    int count, A_MPI_Datatype datatype, A_MPI_Status *status);
  int A_MPI_File_read_at_all(A_MPI_File fh, A_MPI_Offset offset, void *buf,
                                        int count, A_MPI_Datatype datatype, A_MPI_Status *status);
  int A_MPI_File_write_at(A_MPI_File fh, A_MPI_Offset offset, void *buf,
                                     int count, A_MPI_Datatype datatype, A_MPI_Status *status);
  int A_MPI_File_write_at_all(A_MPI_File fh, A_MPI_Offset offset, void *buf,
                                         int count, A_MPI_Datatype datatype, A_MPI_Status *status);
  int A_MPI_File_iread_at(A_MPI_File fh, A_MPI_Offset offset, void *buf,
                                     int count, A_MPI_Datatype datatype, A_MPI_Request *request);
  int A_MPI_File_iwrite_at(A_MPI_File fh, A_MPI_Offset offset, void *buf,
                                      int count, A_MPI_Datatype datatype, A_MPI_Request *request);
  int A_MPI_File_read(A_MPI_File fh, void *buf, int count,
                                 A_MPI_Datatype datatype, A_MPI_Status *status);
  int A_MPI_File_read_all(A_MPI_File fh, void *buf, int count,
                                     A_MPI_Datatype datatype, A_MPI_Status *status);
  int A_MPI_File_write(A_MPI_File fh, void *buf, int count,
                                  A_MPI_Datatype datatype, A_MPI_Status *status);
  int A_MPI_File_write_all(A_MPI_File fh, void *buf, int count,
                                      A_MPI_Datatype datatype, A_MPI_Status *status);
  int A_MPI_File_iread(A_MPI_File fh, void *buf, int count,
                                  A_MPI_Datatype datatype, A_MPI_Request *request);
  int A_MPI_File_iwrite(A_MPI_File fh, void *buf, int count,
                                   A_MPI_Datatype datatype, A_MPI_Request *request);
  int A_MPI_File_seek(A_MPI_File fh, A_MPI_Offset offset, int whence);
  int A_MPI_File_get_position(A_MPI_File fh, A_MPI_Offset *offset);
  int A_MPI_File_get_byte_offset(A_MPI_File fh, A_MPI_Offset offset,
                                            A_MPI_Offset *disp);
  int A_MPI_File_read_shared(A_MPI_File fh, void *buf, int count,
                                        A_MPI_Datatype datatype, A_MPI_Status *status);
  int A_MPI_File_write_shared(A_MPI_File fh, void *buf, int count,
					 A_MPI_Datatype datatype, A_MPI_Status *status);
  int A_MPI_File_iread_shared(A_MPI_File fh, void *buf, int count,
                                         A_MPI_Datatype datatype, A_MPI_Request *request);
  int A_MPI_File_iwrite_shared(A_MPI_File fh, void *buf, int count,
                                          A_MPI_Datatype datatype, A_MPI_Request *request);
  int A_MPI_File_read_ordered(A_MPI_File fh, void *buf, int count,
                                         A_MPI_Datatype datatype, A_MPI_Status *status);
  int A_MPI_File_write_ordered(A_MPI_File fh, void *buf, int count,
                                          A_MPI_Datatype datatype, A_MPI_Status *status);
  int A_MPI_File_seek_shared(A_MPI_File fh, A_MPI_Offset offset, int whence);
  int A_MPI_File_get_position_shared(A_MPI_File fh, A_MPI_Offset *offset);
  int A_MPI_File_read_at_all_begin(A_MPI_File fh, A_MPI_Offset offset, void *buf,
                                              int count, A_MPI_Datatype datatype);
  int A_MPI_File_read_at_all_end(A_MPI_File fh, void *buf, A_MPI_Status *status);
  int A_MPI_File_write_at_all_begin(A_MPI_File fh, A_MPI_Offset offset, void *buf,
                                               int count, A_MPI_Datatype datatype);
  int A_MPI_File_write_at_all_end(A_MPI_File fh, void *buf, A_MPI_Status *status);
  int A_MPI_File_read_all_begin(A_MPI_File fh, void *buf, int count,
                                           A_MPI_Datatype datatype);
  int A_MPI_File_read_all_end(A_MPI_File fh, void *buf, A_MPI_Status *status);
  int A_MPI_File_write_all_begin(A_MPI_File fh, void *buf, int count,
                                            A_MPI_Datatype datatype);
  int A_MPI_File_write_all_end(A_MPI_File fh, void *buf, A_MPI_Status *status);
  int A_MPI_File_read_ordered_begin(A_MPI_File fh, void *buf, int count,
                                               A_MPI_Datatype datatype);
  int A_MPI_File_read_ordered_end(A_MPI_File fh, void *buf, A_MPI_Status *status);
  int A_MPI_File_write_ordered_begin(A_MPI_File fh, void *buf, int count,
                                                A_MPI_Datatype datatype);
  int A_MPI_File_write_ordered_end(A_MPI_File fh, void *buf, A_MPI_Status *status);
  int A_MPI_File_get_type_extent(A_MPI_File fh, A_MPI_Datatype datatype,
                                            A_MPI_Aint *extent);
  int A_MPI_File_set_atomicity(A_MPI_File fh, int flag);
  int A_MPI_File_get_atomicity(A_MPI_File fh, int *flag);
  int A_MPI_File_sync(A_MPI_File fh);
  int A_MPI_Finalize(void);
  int A_MPI_Finalized(int *flag);
  int A_MPI_Free_mem(void *base);
  int A_MPI_Gather(void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                              void *recvbuf, int recvcount, A_MPI_Datatype recvtype,
                              int root, A_MPI_Comm comm);
  int A_MPI_Igather(void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                              void *recvbuf, int recvcount, A_MPI_Datatype recvtype,
                              int root, A_MPI_Comm comm, A_MPI_Request *request);
  int A_MPI_Gatherv(void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                               void *recvbuf, int recvcounts[], int displs[],
                               A_MPI_Datatype recvtype, int root, A_MPI_Comm comm);
  int A_MPI_Igatherv(void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                               void *recvbuf, int recvcounts[], int displs[],
                               A_MPI_Datatype recvtype, int root, A_MPI_Comm comm, A_MPI_Request *request);
  int A_MPI_Get_address(void *location, A_MPI_Aint *address);
  int A_MPI_Get_count(A_MPI_Status *status, A_MPI_Datatype datatype, int *count);
  int A_MPI_Get_elements(A_MPI_Status *status, A_MPI_Datatype datatype, int *count);
  int A_MPI_Get_elements_x(A_MPI_Status *status, A_MPI_Datatype datatype, A_MPI_Count *count);
  int A_MPI_Get(void *origin_addr, int origin_count,
                           A_MPI_Datatype origin_datatype, int target_rank,
                           A_MPI_Aint target_disp, int target_count,
                           A_MPI_Datatype target_datatype, A_MPI_Win win);
  int A_MPI_Get_accumulate(void *origin_addr, int origin_count, A_MPI_Datatype origin_datatype,
                                      void *result_addr, int result_count, A_MPI_Datatype result_datatype,
                                      int target_rank, A_MPI_Aint target_disp, int target_count,
                                      A_MPI_Datatype target_datatype, A_MPI_Op op, A_MPI_Win win);
  int A_MPI_Get_library_version(char *version, int *resultlen);
  int A_MPI_Get_processor_name(char *name, int *resultlen);
  int A_MPI_Get_version(int *version, int *subversion);
  int A_MPI_Graph_create(A_MPI_Comm comm_old, int nnodes, int index[],
                                    int edges[], int reorder, A_MPI_Comm *comm_graph);
  int A_MPI_Graph_get(A_MPI_Comm comm, int maxindex, int maxedges,
                                 int index[], int edges[]);
  int A_MPI_Graph_map(A_MPI_Comm comm, int nnodes, int index[], int edges[],
                                 int *newrank);
  int A_MPI_Graph_neighbors_count(A_MPI_Comm comm, int rank, int *nneighbors);
  int A_MPI_Graph_neighbors(A_MPI_Comm comm, int rank, int maxneighbors,
                                       int neighbors[]);
  int A_MPI_Graphdims_get(A_MPI_Comm comm, int *nnodes, int *nedges);
  int A_MPI_Grequest_complete(A_MPI_Request request);
  int A_MPI_Grequest_start(A_MPI_Grequest_query_function *query_fn,
                                      A_MPI_Grequest_free_function *free_fn,
                                      A_MPI_Grequest_cancel_function *cancel_fn,
                                      void *extra_state, A_MPI_Request *request);
  A_MPI_Fint A_MPI_Group_c2f(A_MPI_Group group);
  int A_MPI_Group_compare(A_MPI_Group group1, A_MPI_Group group2, int *result);
  int A_MPI_Group_difference(A_MPI_Group group1, A_MPI_Group group2,
                                        A_MPI_Group *newgroup);
  int A_MPI_Group_excl(A_MPI_Group group, int n, int ranks[],
                                  A_MPI_Group *newgroup);
  A_MPI_Group A_MPI_Group_f2c(A_MPI_Fint group);
  int A_MPI_Group_free(A_MPI_Group *group);
  int A_MPI_Group_incl(A_MPI_Group group, int n, int ranks[],
                                  A_MPI_Group *newgroup);
  int A_MPI_Group_intersection(A_MPI_Group group1, A_MPI_Group group2,
                                          A_MPI_Group *newgroup);
  int A_MPI_Group_range_excl(A_MPI_Group group, int n, int ranges[][3],
                                        A_MPI_Group *newgroup);
  int A_MPI_Group_range_incl(A_MPI_Group group, int n, int ranges[][3],
                                        A_MPI_Group *newgroup);
  int A_MPI_Group_rank(A_MPI_Group group, int *rank);
  int A_MPI_Group_size(A_MPI_Group group, int *size);
  int A_MPI_Group_translate_ranks(A_MPI_Group group1, int n, int ranks1[],
                                             A_MPI_Group group2, int ranks2[]);
  int A_MPI_Group_union(A_MPI_Group group1, A_MPI_Group group2,
                                   A_MPI_Group *newgroup);
  int A_MPI_Ibsend(void *buf, int count, A_MPI_Datatype datatype, int dest,
                              int tag, A_MPI_Comm comm, A_MPI_Request *request);
  int A_MPI_Improbe(int source, int tag, A_MPI_Comm comm,
                               int *flag, A_MPI_Message *message,
                               A_MPI_Status *status);
  int A_MPI_Imrecv(void *buf, int count, A_MPI_Datatype type,
                              A_MPI_Message *message, A_MPI_Request *request);
  A_MPI_Fint A_MPI_Info_c2f(A_MPI_Info info);
  int A_MPI_Info_create(A_MPI_Info *info);
  int A_MPI_Info_delete(A_MPI_Info info, char *key);
  int A_MPI_Info_dup(A_MPI_Info info, A_MPI_Info *newinfo);
  A_MPI_Info A_MPI_Info_f2c(A_MPI_Fint info);
  int A_MPI_Info_free(A_MPI_Info *info);
  int A_MPI_Info_get(A_MPI_Info info, char *key, int valuelen,
                                char *value, int *flag);
  int A_MPI_Info_get_nkeys(A_MPI_Info info, int *nkeys);
  int A_MPI_Info_get_nthkey(A_MPI_Info info, int n, char *key);
  int A_MPI_Info_get_valuelen(A_MPI_Info info, char *key, int *valuelen,
                                         int *flag);
  int A_MPI_Info_set(A_MPI_Info info, char *key, char *value);
  int A_MPI_Init(int *argc, char ***argv);
  int A_MPI_Initialized(int *flag);
  int A_MPI_Init_thread(int *argc, char ***argv, int required,
                                   int *provided);
  int A_MPI_Intercomm_create(A_MPI_Comm local_comm, int local_leader,
                                        A_MPI_Comm bridge_comm, int remote_leader,
                                        int tag, A_MPI_Comm *newintercomm);
  int A_MPI_Intercomm_merge(A_MPI_Comm intercomm, int high,
                                       A_MPI_Comm *newintercomm);
  int A_MPI_Iprobe(int source, int tag, A_MPI_Comm comm, int *flag,
                              A_MPI_Status *status);
  int A_MPI_Irecv(void *buf, int count, A_MPI_Datatype datatype, int source,
                             int tag, A_MPI_Comm comm, A_MPI_Request *request);
  int A_MPI_Irsend(void *buf, int count, A_MPI_Datatype datatype, int dest,
                              int tag, A_MPI_Comm comm, A_MPI_Request *request);
  int A_MPI_Isend(void *buf, int count, A_MPI_Datatype datatype, int dest,
                             int tag, A_MPI_Comm comm, A_MPI_Request *request);
  int A_MPI_Issend(void *buf, int count, A_MPI_Datatype datatype, int dest,
                              int tag, A_MPI_Comm comm, A_MPI_Request *request);
  int A_MPI_Is_thread_main(int *flag);
  int A_MPI_Keyval_create(A_MPI_Copy_function *copy_fn,
                                     A_MPI_Delete_function *delete_fn,
                                     int *keyval, void *extra_state);
  int A_MPI_Keyval_free(int *keyval);
  int A_MPI_Lookup_name(char *service_name, A_MPI_Info info, char *port_name);
  A_MPI_Fint A_MPI_Message_c2f(A_MPI_Message message);
  A_MPI_Message A_MPI_Message_f2c(A_MPI_Fint message);
  int A_MPI_Mprobe(int source, int tag, A_MPI_Comm comm,
                               A_MPI_Message *message,
                               A_MPI_Status *status);
  int A_MPI_Mrecv(void *buf, int count, A_MPI_Datatype type,
                             A_MPI_Message *message, A_MPI_Status *status);
  int A_MPI_Neighbor_allgather(void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                                          void *recvbuf, int recvcount, A_MPI_Datatype recvtype,
                                          A_MPI_Comm comm);
  int A_MPI_Ineighbor_allgather(void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                                           void *recvbuf, int recvcount, A_MPI_Datatype recvtype,
                                           A_MPI_Comm comm, A_MPI_Request *request);
  int A_MPI_Neighbor_allgatherv(void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                                           void *recvbuf, int recvcounts[], int displs[],
                                           A_MPI_Datatype recvtype, A_MPI_Comm comm);
  int A_MPI_Ineighbor_allgatherv(void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                                            void *recvbuf, int recvcounts[], int displs[],
                                            A_MPI_Datatype recvtype, A_MPI_Comm comm, A_MPI_Request *request);
  int A_MPI_Neighbor_alltoall(void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                                         void *recvbuf, int recvcount, A_MPI_Datatype recvtype,
                                         A_MPI_Comm comm);
  int A_MPI_Ineighbor_alltoall(void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                                          void *recvbuf, int recvcount, A_MPI_Datatype recvtype,
                                          A_MPI_Comm comm, A_MPI_Request *request);
  int A_MPI_Neighbor_alltoallv(void *sendbuf, int sendcounts[], int sdispls[],  A_MPI_Datatype sendtype,
                                          void *recvbuf, int recvcounts[], int rdispls[], A_MPI_Datatype recvtype,
                                          A_MPI_Comm comm);
  int A_MPI_Ineighbor_alltoallv(void *sendbuf, int sendcounts[], int sdispls[], A_MPI_Datatype sendtype,
                                           void *recvbuf, int recvcounts[], int rdispls[], A_MPI_Datatype recvtype,
                                           A_MPI_Comm comm, A_MPI_Request *request);
  int A_MPI_Neighbor_alltoallw(void *sendbuf, int sendcounts[], A_MPI_Aint sdispls[], A_MPI_Datatype sendtypes[],
                                          void *recvbuf, int recvcounts[], A_MPI_Aint rdispls[], A_MPI_Datatype recvtypes[],
                                          A_MPI_Comm comm);
  int A_MPI_Ineighbor_alltoallw(void *sendbuf, int sendcounts[], A_MPI_Aint sdispls[], A_MPI_Datatype sendtypes[],
                                           void *recvbuf, int recvcounts[], A_MPI_Aint rdispls[], A_MPI_Datatype recvtypes[],
                                           A_MPI_Comm comm, A_MPI_Request *request);
  A_MPI_Fint A_MPI_Op_c2f(A_MPI_Op op);
  int A_MPI_Op_commutative(A_MPI_Op op, int *commute);
  int A_MPI_Op_create(A_MPI_User_function *function, int commute, A_MPI_Op *op);
  int A_MPI_Open_port(A_MPI_Info info, char *port_name);
  A_MPI_Op A_MPI_Op_f2c(A_MPI_Fint op);
  int A_MPI_Op_free(A_MPI_Op *op);
  int A_MPI_Pack_external(char datarep[], void *inbuf, int incount,
                                     A_MPI_Datatype datatype, void *outbuf,
                                     A_MPI_Aint outsize, A_MPI_Aint *position);
  int A_MPI_Pack_external_size(char datarep[], int incount,
                                          A_MPI_Datatype datatype, A_MPI_Aint *size);
  int A_MPI_Pack(void *inbuf, int incount, A_MPI_Datatype datatype,
                            void *outbuf, int outsize, int *position, A_MPI_Comm comm);
  int A_MPI_Pack_size(int incount, A_MPI_Datatype datatype, A_MPI_Comm comm,
                                 int *size);
  int A_MPI_Pcontrol(int level, ...);
  int A_MPI_Probe(int source, int tag, A_MPI_Comm comm, A_MPI_Status *status);
  int A_MPI_Publish_name(char *service_name, A_MPI_Info info,
                                    char *port_name);
  int A_MPI_Put(void *origin_addr, int origin_count, A_MPI_Datatype origin_datatype,
                           int target_rank, A_MPI_Aint target_disp, int target_count,
                           A_MPI_Datatype target_datatype, A_MPI_Win win);
  int A_MPI_Query_thread(int *provided);
  int A_MPI_Raccumulate(void *origin_addr, int origin_count, A_MPI_Datatype origin_datatype, 
                                   int target_rank, A_MPI_Aint target_disp, int target_count, 
                                   A_MPI_Datatype target_datatype, A_MPI_Op op, A_MPI_Win win, A_MPI_Request *request);
  int A_MPI_Recv_init(void *buf, int count, A_MPI_Datatype datatype, int source,
                                 int tag, A_MPI_Comm comm, A_MPI_Request *request);
  int A_MPI_Recv(void *buf, int count, A_MPI_Datatype datatype, int source,
                            int tag, A_MPI_Comm comm, A_MPI_Status *status);
  int A_MPI_Reduce(void *sendbuf, void *recvbuf, int count,
                              A_MPI_Datatype datatype, A_MPI_Op op, int root, A_MPI_Comm comm);
  int A_MPI_Ireduce(void *sendbuf, void *recvbuf, int count,
                              A_MPI_Datatype datatype, A_MPI_Op op, int root, A_MPI_Comm comm, A_MPI_Request *request);
  int A_MPI_Reduce_local(void *inbuf, void *inoutbuf, int count,
                                    A_MPI_Datatype datatype, A_MPI_Op op);
  int A_MPI_Reduce_scatter(void *sendbuf, void *recvbuf, int recvcounts[],
                                      A_MPI_Datatype datatype, A_MPI_Op op, A_MPI_Comm comm);
  int A_MPI_Ireduce_scatter(void *sendbuf, void *recvbuf, int recvcounts[],
                                      A_MPI_Datatype datatype, A_MPI_Op op, A_MPI_Comm comm, A_MPI_Request *request);
  int A_MPI_Reduce_scatter_block(void *sendbuf, void *recvbuf, int recvcount,
                                      A_MPI_Datatype datatype, A_MPI_Op op, A_MPI_Comm comm);
  int A_MPI_Ireduce_scatter_block(void *sendbuf, void *recvbuf, int recvcount,
                                      A_MPI_Datatype datatype, A_MPI_Op op, A_MPI_Comm comm, A_MPI_Request *request);
  int A_MPI_Register_datarep(char *datarep,
                                        A_MPI_Datarep_conversion_function *read_conversion_fn,
                                        A_MPI_Datarep_conversion_function *write_conversion_fn,
                                        A_MPI_Datarep_extent_function *dtype_file_extent_fn,
                                        void *extra_state);
  A_MPI_Fint A_MPI_Request_c2f(A_MPI_Request request);
  A_MPI_Request A_MPI_Request_f2c(A_MPI_Fint request);
  int A_MPI_Request_free(A_MPI_Request *request);
  int A_MPI_Request_get_status(A_MPI_Request request, int *flag,
                                          A_MPI_Status *status);
  int A_MPI_Rget(void *origin_addr, int origin_count, A_MPI_Datatype origin_datatype, 
                            int target_rank, A_MPI_Aint target_disp, int target_count, A_MPI_Datatype target_datatype,
                            A_MPI_Win win, A_MPI_Request *request);
  int A_MPI_Rget_accumulate(void *origin_addr, int origin_count, A_MPI_Datatype origin_datatype,
                                       void *result_addr, int result_count, A_MPI_Datatype result_datatype,
                                       int target_rank, A_MPI_Aint target_disp, int target_count, 
                                       A_MPI_Datatype target_datatype, A_MPI_Op op,
                                       A_MPI_Win win, A_MPI_Request *request);
  int A_MPI_Rput(void *origin_addr, int origin_count, A_MPI_Datatype origin_datatype,
                            int target_rank, A_MPI_Aint target_disp, int target_cout, 
                            A_MPI_Datatype target_datatype, A_MPI_Win win, A_MPI_Request *request);
  int A_MPI_Rsend(void *ibuf, int count, A_MPI_Datatype datatype, int dest,
                             int tag, A_MPI_Comm comm);
  int A_MPI_Rsend_init(void *buf, int count, A_MPI_Datatype datatype,
                                  int dest, int tag, A_MPI_Comm comm,
                                  A_MPI_Request *request);
  int A_MPI_Scan(void *sendbuf, void *recvbuf, int count,
                            A_MPI_Datatype datatype, A_MPI_Op op, A_MPI_Comm comm);
  int A_MPI_Iscan(void *sendbuf, void *recvbuf, int count,
                            A_MPI_Datatype datatype, A_MPI_Op op, A_MPI_Comm comm, A_MPI_Request *request);
  int A_MPI_Scatter(void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                               void *recvbuf, int recvcount, A_MPI_Datatype recvtype,
                               int root, A_MPI_Comm comm);
  int A_MPI_Iscatter(void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                               void *recvbuf, int recvcount, A_MPI_Datatype recvtype,
                               int root, A_MPI_Comm comm, A_MPI_Request *request);
  int A_MPI_Scatterv(void *sendbuf, int sendcounts[], int displs[],
                                A_MPI_Datatype sendtype, void *recvbuf, int recvcount,
                                A_MPI_Datatype recvtype, int root, A_MPI_Comm comm);
  int A_MPI_Iscatterv(void *sendbuf, int sendcounts[], int displs[],
                                A_MPI_Datatype sendtype, void *recvbuf, int recvcount,
                                A_MPI_Datatype recvtype, int root, A_MPI_Comm comm, A_MPI_Request *request);
  int A_MPI_Send_init(void *buf, int count, A_MPI_Datatype datatype,
                                 int dest, int tag, A_MPI_Comm comm,
                                 A_MPI_Request *request);
  int A_MPI_Send(void *buf, int count, A_MPI_Datatype datatype, int dest,
                            int tag, A_MPI_Comm comm);
  int A_MPI_Sendrecv(void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                                int dest, int sendtag, void *recvbuf, int recvcount,
                                A_MPI_Datatype recvtype, int source, int recvtag,
                                A_MPI_Comm comm,  A_MPI_Status *status);
  int A_MPI_Sendrecv_replace(void * buf, int count, A_MPI_Datatype datatype,
                                        int dest, int sendtag, int source, int recvtag,
                                        A_MPI_Comm comm, A_MPI_Status *status);
  int A_MPI_Ssend_init(void *buf, int count, A_MPI_Datatype datatype,
                                  int dest, int tag, A_MPI_Comm comm,
                                  A_MPI_Request *request);
  int A_MPI_Ssend(void *buf, int count, A_MPI_Datatype datatype, int dest,
                             int tag, A_MPI_Comm comm);
  int A_MPI_Start(A_MPI_Request *request);
  int A_MPI_Startall(int count, A_MPI_Request array_of_requests[]);
  int A_MPI_Status_c2f(A_MPI_Status *c_status, A_MPI_Fint *f_status);
  int A_MPI_Status_f2c(A_MPI_Fint *f_status, A_MPI_Status *c_status);
  int A_MPI_Status_set_cancelled(A_MPI_Status *status, int flag);
  int A_MPI_Status_set_elements(A_MPI_Status *status, A_MPI_Datatype datatype,
                                           int count);
  int A_MPI_Status_set_elements_x(A_MPI_Status *status, A_MPI_Datatype datatype,
                                             A_MPI_Count count);
  int A_MPI_Testall(int count, A_MPI_Request array_of_requests[], int *flag,
                               A_MPI_Status array_of_statuses[]);
  int A_MPI_Testany(int count, A_MPI_Request array_of_requests[], int *index,
                               int *flag, A_MPI_Status *status);
  int A_MPI_Test(A_MPI_Request *request, int *flag, A_MPI_Status *status);
  int A_MPI_Test_cancelled(A_MPI_Status *status, int *flag);
  int A_MPI_Testsome(int incount, A_MPI_Request array_of_requests[],
                                int *outcount, int array_of_indices[],
                                A_MPI_Status array_of_statuses[]);
  int A_MPI_Topo_test(A_MPI_Comm comm, int *status);
  A_MPI_Fint A_MPI_Type_c2f(A_MPI_Datatype datatype);
  int A_MPI_Type_commit(A_MPI_Datatype *type);
  int A_MPI_Type_contiguous(int count, A_MPI_Datatype oldtype,
                                       A_MPI_Datatype *newtype);
  int A_MPI_Type_create_darray(int size, int rank, int ndims,
                                          int gsize_array[], int distrib_array[],
                                          int darg_array[], int psize_array[],
                                          int order, A_MPI_Datatype oldtype,
                                          A_MPI_Datatype *newtype);
  int A_MPI_Type_create_f90_complex(int p, int r, A_MPI_Datatype *newtype);
  int A_MPI_Type_create_f90_integer(int r, A_MPI_Datatype *newtype);
  int A_MPI_Type_create_f90_real(int p, int r, A_MPI_Datatype *newtype);
  int A_MPI_Type_create_hindexed_block(int count, int blocklength,
                                                  A_MPI_Aint array_of_displacements[],
                                                  A_MPI_Datatype oldtype,
                                                  A_MPI_Datatype *newtype);
  int A_MPI_Type_create_hindexed(int count, int array_of_blocklengths[],
                                            A_MPI_Aint array_of_displacements[],
                                            A_MPI_Datatype oldtype,
                                            A_MPI_Datatype *newtype);
  int A_MPI_Type_create_hvector(int count, int blocklength, A_MPI_Aint stride,
                                           A_MPI_Datatype oldtype,
                                           A_MPI_Datatype *newtype);
  int A_MPI_Type_create_keyval(A_MPI_Type_copy_attr_function *type_copy_attr_fn,
                                          A_MPI_Type_delete_attr_function *type_delete_attr_fn,
                                          int *type_keyval, void *extra_state);
  int A_MPI_Type_create_indexed_block(int count, int blocklength,
                                                 int array_of_displacements[],
                                                 A_MPI_Datatype oldtype,
                                                 A_MPI_Datatype *newtype);
  int A_MPI_Type_create_struct(int count, int array_of_block_lengths[],
                                          A_MPI_Aint array_of_displacements[],
                                          A_MPI_Datatype array_of_types[],
                                          A_MPI_Datatype *newtype);
  int A_MPI_Type_create_subarray(int ndims, int size_array[], int subsize_array[],
                                            int start_array[], int order,
                                            A_MPI_Datatype oldtype, A_MPI_Datatype *newtype);
  int A_MPI_Type_create_resized(A_MPI_Datatype oldtype, A_MPI_Aint lb,
                                           A_MPI_Aint extent, A_MPI_Datatype *newtype);
  int A_MPI_Type_delete_attr(A_MPI_Datatype type, int type_keyval);
  int A_MPI_Type_dup(A_MPI_Datatype type, A_MPI_Datatype *newtype);
  int A_MPI_Type_extent(A_MPI_Datatype type, A_MPI_Aint *extent);
  int A_MPI_Type_free(A_MPI_Datatype *type);
  int A_MPI_Type_free_keyval(int *type_keyval);
  A_MPI_Datatype A_MPI_Type_f2c(A_MPI_Fint datatype);
  int A_MPI_Type_get_attr(A_MPI_Datatype type, int type_keyval,
                                     void *attribute_val, int *flag);
  int A_MPI_Type_get_contents(A_MPI_Datatype mtype, int max_integers,
                                         int max_addresses, int max_datatypes,
                                         int array_of_integers[],
                                         A_MPI_Aint array_of_addresses[],
                                         A_MPI_Datatype array_of_datatypes[]);
  int A_MPI_Type_get_envelope(A_MPI_Datatype type, int *num_integers,
                                         int *num_addresses, int *num_datatypes,
                                         int *combiner);
  int A_MPI_Type_get_extent(A_MPI_Datatype type, A_MPI_Aint *lb,
                                       A_MPI_Aint *extent);
  int A_MPI_Type_get_extent_x(A_MPI_Datatype type, A_MPI_Count *lb,
                                         A_MPI_Count *extent);
  int A_MPI_Type_get_name(A_MPI_Datatype type, char *type_name,
                                     int *resultlen);
  int A_MPI_Type_get_true_extent(A_MPI_Datatype datatype, A_MPI_Aint *true_lb,
                                            A_MPI_Aint *true_extent);
  int A_MPI_Type_get_true_extent_x(A_MPI_Datatype datatype, A_MPI_Count *true_lb,
                                              A_MPI_Count *true_extent);
  int A_MPI_Type_hindexed(int count, int array_of_blocklengths[],
                                     A_MPI_Aint array_of_displacements[],
                                     A_MPI_Datatype oldtype, A_MPI_Datatype *newtype);
  int A_MPI_Type_hvector(int count, int blocklength, A_MPI_Aint stride,
                                    A_MPI_Datatype oldtype, A_MPI_Datatype *newtype);
  int A_MPI_Type_indexed(int count, int array_of_blocklengths[],
                                    int array_of_displacements[],
                                    A_MPI_Datatype oldtype, A_MPI_Datatype *newtype);
  int A_MPI_Type_lb(A_MPI_Datatype type, A_MPI_Aint *lb);
  int A_MPI_Type_match_size(int typeclass, int size, A_MPI_Datatype *type);
  int A_MPI_Type_set_attr(A_MPI_Datatype type, int type_keyval,
                                     void *attr_val);
  int A_MPI_Type_set_name(A_MPI_Datatype type, char *type_name);
  int A_MPI_Type_size(A_MPI_Datatype type, int *size);
  int A_MPI_Type_size_x(A_MPI_Datatype type, A_MPI_Count *size);
  int A_MPI_Type_struct(int count, int array_of_blocklengths[],
                                   A_MPI_Aint array_of_displacements[],
                                   A_MPI_Datatype array_of_types[],
                                   A_MPI_Datatype *newtype);
  int A_MPI_Type_ub(A_MPI_Datatype mtype, A_MPI_Aint *ub);
  int A_MPI_Type_vector(int count, int blocklength, int stride,
                                   A_MPI_Datatype oldtype, A_MPI_Datatype *newtype);
  int A_MPI_Unpack(void *inbuf, int insize, int *position,
                              void *outbuf, int outcount, A_MPI_Datatype datatype,
                              A_MPI_Comm comm);
  int A_MPI_Unpublish_name(char *service_name, A_MPI_Info info, char *port_name);
  int A_MPI_Unpack_external (char datarep[], void *inbuf, A_MPI_Aint insize,
                                        A_MPI_Aint *position, void *outbuf, int outcount,
                                        A_MPI_Datatype datatype);
  int A_MPI_Waitall(int count, A_MPI_Request array_of_requests[],
                               A_MPI_Status *array_of_statuses);
  int A_MPI_Waitany(int count, A_MPI_Request array_of_requests[],
                               int *index, A_MPI_Status *status);
  int A_MPI_Wait(A_MPI_Request *request, A_MPI_Status *status);
  int A_MPI_Waitsome(int incount, A_MPI_Request array_of_requests[],
                                int *outcount, int array_of_indices[],
                                A_MPI_Status array_of_statuses[]);
  int A_MPI_Win_allocate(A_MPI_Aint size, int disp_unit, A_MPI_Info info,
                                    A_MPI_Comm comm, void *baseptr, A_MPI_Win *win);
  int A_MPI_Win_allocate_shared(A_MPI_Aint size, int disp_unit, A_MPI_Info info,
                                           A_MPI_Comm comm, void *baseptr, A_MPI_Win *win);
  int A_MPI_Win_attach(A_MPI_Win win, void *base, A_MPI_Aint size);
  A_MPI_Fint A_MPI_Win_c2f(A_MPI_Win win);
  int A_MPI_Win_call_errhandler(A_MPI_Win win, int errorcode);
  int A_MPI_Win_complete(A_MPI_Win win);
  int A_MPI_Win_create(void *base, A_MPI_Aint size, int disp_unit,
                                  A_MPI_Info info, A_MPI_Comm comm, A_MPI_Win *win);
  int A_MPI_Win_create_dynamic(A_MPI_Info info, A_MPI_Comm comm, A_MPI_Win *win);
  int A_MPI_Win_create_errhandler(A_MPI_Win_errhandler_function *function,
                                             A_MPI_Errhandler *errhandler);
  int A_MPI_Win_create_keyval(A_MPI_Win_copy_attr_function *win_copy_attr_fn,
                                         A_MPI_Win_delete_attr_function *win_delete_attr_fn,
                                         int *win_keyval, void *extra_state);
  int A_MPI_Win_delete_attr(A_MPI_Win win, int win_keyval);
  int A_MPI_Win_detach(A_MPI_Win win, void *base);
  A_MPI_Win A_MPI_Win_f2c(A_MPI_Fint win);
  int A_MPI_Win_fence(int assert, A_MPI_Win win);
  int A_MPI_Win_flush(int rank, A_MPI_Win win);
  int A_MPI_Win_flush_all(A_MPI_Win win);
  int A_MPI_Win_flush_local(int rank, A_MPI_Win win);
  int A_MPI_Win_flush_local_all(A_MPI_Win win);
  int A_MPI_Win_free(A_MPI_Win *win);
  int A_MPI_Win_free_keyval(int *win_keyval);
  int A_MPI_Win_get_attr(A_MPI_Win win, int win_keyval,
                                    void *attribute_val, int *flag);
  int A_MPI_Win_get_errhandler(A_MPI_Win win, A_MPI_Errhandler *errhandler);
  int A_MPI_Win_get_group(A_MPI_Win win, A_MPI_Group *group);
  int A_MPI_Win_get_info(A_MPI_Win win, A_MPI_Info *info_used);
  int A_MPI_Win_get_name(A_MPI_Win win, char *win_name, int *resultlen);
  int A_MPI_Win_lock(int lock_type, int rank, int assert, A_MPI_Win win);
  int A_MPI_Win_lock_all(int assert, A_MPI_Win win);
  int A_MPI_Win_post(A_MPI_Group group, int assert, A_MPI_Win win);
  int A_MPI_Win_set_attr(A_MPI_Win win, int win_keyval, void *attribute_val);
  int A_MPI_Win_set_errhandler(A_MPI_Win win, A_MPI_Errhandler errhandler);
  int A_MPI_Win_set_info(A_MPI_Win win, A_MPI_Info info);
  int A_MPI_Win_set_name(A_MPI_Win win, char *win_name);
  int A_MPI_Win_shared_query(A_MPI_Win win, int rank, A_MPI_Aint *size, int *disp_unit, void *baseptr);
  int A_MPI_Win_start(A_MPI_Group group, int assert, A_MPI_Win win);
  int A_MPI_Win_sync(A_MPI_Win win);
  int A_MPI_Win_test(A_MPI_Win win, int *flag);
  int A_MPI_Win_unlock(int rank, A_MPI_Win win);
  int A_MPI_Win_unlock_all(A_MPI_Win win);
  int A_MPI_Win_wait(A_MPI_Win win);
  double A_MPI_Wtick(void);
  double A_MPI_Wtime(void);

  /*
   * Profiling MPI API
   */
  int A_PMPI_Abort(A_MPI_Comm comm, int errorcode);
  int A_PMPI_Accumulate(void *origin_addr, int origin_count, A_MPI_Datatype origin_datatype,
                                   int target_rank, A_MPI_Aint target_disp, int target_count,
                                   A_MPI_Datatype target_datatype, A_MPI_Op op, A_MPI_Win win);
  int A_PMPI_Add_error_class(int *errorclass);
  int A_PMPI_Add_error_code(int errorclass, int *errorcode);
  int A_PMPI_Add_error_string(int errorcode, char *string);
  int A_PMPI_Address(void *location, A_MPI_Aint *address);
  int A_PMPI_Allgather(void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                                  void *recvbuf, int recvcount,
                                  A_MPI_Datatype recvtype, A_MPI_Comm comm);
  int A_PMPI_Iallgather(void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                                  void *recvbuf, int recvcount,
                                  A_MPI_Datatype recvtype, A_MPI_Comm comm, A_MPI_Request *request);
  int A_PMPI_Allgatherv(void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                                   void *recvbuf, int recvcounts[],
                                   int displs[], A_MPI_Datatype recvtype, A_MPI_Comm comm);
  int A_PMPI_Iallgatherv(void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                                   void *recvbuf, int recvcounts[],
                                   int displs[], A_MPI_Datatype recvtype, A_MPI_Comm comm, A_MPI_Request *request);
  int A_PMPI_Alloc_mem(A_MPI_Aint size, A_MPI_Info info,
                                  void *baseptr);
  int A_PMPI_Allreduce(void *sendbuf, void *recvbuf, int count,
                                  A_MPI_Datatype datatype, A_MPI_Op op, A_MPI_Comm comm);
  int A_PMPI_Iallreduce(void *sendbuf, void *recvbuf, int count,
                                  A_MPI_Datatype datatype, A_MPI_Op op, A_MPI_Comm comm, A_MPI_Request *request);
  int A_PMPI_Alltoall(void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                                 void *recvbuf, int recvcount,
                                 A_MPI_Datatype recvtype, A_MPI_Comm comm);
  int A_PMPI_Ialltoall(void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                                 void *recvbuf, int recvcount,
                                 A_MPI_Datatype recvtype, A_MPI_Comm comm, A_MPI_Request *request);
  int A_PMPI_Alltoallv(void *sendbuf, int sendcounts[], int sdispls[],
                                  A_MPI_Datatype sendtype, void *recvbuf, int recvcounts[],
                                  int rdispls[], A_MPI_Datatype recvtype, A_MPI_Comm comm);
  int A_PMPI_Ialltoallv(void *sendbuf, int sendcounts[], int sdispls[],
                                  A_MPI_Datatype sendtype, void *recvbuf, int recvcounts[],
                                  int rdispls[], A_MPI_Datatype recvtype, A_MPI_Comm comm, A_MPI_Request *request);
  int A_PMPI_Alltoallw(void *sendbuf, int sendcounts[], int sdispls[], A_MPI_Datatype sendtypes[],
                                  void *recvbuf, int recvcounts[], int rdispls[], A_MPI_Datatype recvtypes[],
                                  A_MPI_Comm comm);
  int A_PMPI_Ialltoallw(void *sendbuf, int sendcounts[], int sdispls[], A_MPI_Datatype sendtypes[],
                                  void *recvbuf, int recvcounts[], int rdispls[], A_MPI_Datatype recvtypes[],
                                  A_MPI_Comm comm, A_MPI_Request *request);
  int A_PMPI_Attr_delete(A_MPI_Comm comm, int keyval);
  int A_PMPI_Attr_get(A_MPI_Comm comm, int keyval, void *attribute_val, int *flag);
  int A_PMPI_Dist_graph_create(A_MPI_Comm comm_old, int n, int nodes[],
                                          int degrees[], int targets[],
                                          int weights[], A_MPI_Info info,
                                          int reorder, A_MPI_Comm * newcomm);
  int A_PMPI_Dist_graph_create_adjacent(A_MPI_Comm comm_old,
                                                   int indegree, int sources[],
                                                   int sourceweights[],
                                                   int outdegree,
                                                   int destinations[],
                                                   int destweights[],
                                                   A_MPI_Info info, int reorder,
                                                   A_MPI_Comm *comm_dist_graph);
 int A_PMPI_Dist_graph_neighbors(A_MPI_Comm comm, int maxindegree,
                                            int sources[], int sourceweights[],
                                            int maxoutdegree,
                                             int destinations[],
                                            int destweights[]);
  int A_PMPI_Dist_graph_neighbors_count(A_MPI_Comm comm,
                                                   int *inneighbors,
                                                   int *outneighbors,
                                                   int *weighted);
  int A_PMPI_Attr_put(A_MPI_Comm comm, int keyval, void *attribute_val);
  int A_PMPI_Barrier(A_MPI_Comm comm);
  int A_PMPI_Ibarrier(A_MPI_Comm comm, A_MPI_Request *request);
  int A_PMPI_Bcast(void *buffer, int count, A_MPI_Datatype datatype,
                              int root, A_MPI_Comm comm);
  int A_PMPI_Ibcast(void *buffer, int count, A_MPI_Datatype datatype,
				                              int root, A_MPI_Comm comm,
											  A_MPI_Request *request);
  int A_PMPI_Bsend(void *buf, int count, A_MPI_Datatype datatype,
                              int dest, int tag, A_MPI_Comm comm);
  int A_PMPI_Bsend_init(void *buf, int count, A_MPI_Datatype datatype,
                                   int dest, int tag, A_MPI_Comm comm, A_MPI_Request *request);
  int A_PMPI_Buffer_attach(void *buffer, int size);
  int A_PMPI_Buffer_detach(void *buffer, int *size);
  int A_PMPI_Cancel(A_MPI_Request *request);
  int A_PMPI_Cart_coords(A_MPI_Comm comm, int rank, int maxdims, int coords[]);
  int A_PMPI_Cart_create(A_MPI_Comm old_comm, int ndims, int dims[],
                                    int periods[], int reorder, A_MPI_Comm *comm_cart);
  int A_PMPI_Cart_get(A_MPI_Comm comm, int maxdims, int dims[],
                                 int periods[], int coords[]);
  int A_PMPI_Cart_map(A_MPI_Comm comm, int ndims, int dims[],
                                 int periods[], int *newrank);
  int A_PMPI_Cart_rank(A_MPI_Comm comm, int coords[], int *rank);
  int A_PMPI_Cart_shift(A_MPI_Comm comm, int direction, int disp,
                                   int *rank_source, int *rank_dest);
  int A_PMPI_Cart_sub(A_MPI_Comm comm, int remain_dims[], A_MPI_Comm *new_comm);
  int A_PMPI_Cartdim_get(A_MPI_Comm comm, int *ndims);
  int A_PMPI_Close_port(char *port_name);
  int A_PMPI_Comm_accept(char *port_name, A_MPI_Info info, int root,
                                    A_MPI_Comm comm, A_MPI_Comm *newcomm);
  A_MPI_Fint A_PMPI_Comm_c2f(A_MPI_Comm comm);
  int A_PMPI_Comm_call_errhandler(A_MPI_Comm comm, int errorcode);
  int A_PMPI_Comm_compare(A_MPI_Comm comm1, A_MPI_Comm comm2, int *result);
  int A_PMPI_Comm_connect(char *port_name, A_MPI_Info info, int root,
                                     A_MPI_Comm comm, A_MPI_Comm *newcomm);
  int A_PMPI_Comm_create_errhandler(A_MPI_Comm_errhandler_function *function,
                                               A_MPI_Errhandler *errhandler);
  int A_PMPI_Comm_create_keyval(A_MPI_Comm_copy_attr_function *comm_copy_attr_fn,
                                           A_MPI_Comm_delete_attr_function *comm_delete_attr_fn,
                                           int *comm_keyval, void *extra_state);
  int A_PMPI_Comm_create_group(A_MPI_Comm comm, A_MPI_Group group, int tag, A_MPI_Comm *newcomm);
  int A_PMPI_Comm_create(A_MPI_Comm comm, A_MPI_Group group, A_MPI_Comm *newcomm);
  int A_PMPI_Comm_delete_attr(A_MPI_Comm comm, int comm_keyval);
  int A_PMPI_Comm_disconnect(A_MPI_Comm *comm);
  int A_PMPI_Comm_dup(A_MPI_Comm comm, A_MPI_Comm *newcomm);
  int A_PMPI_Comm_idup(A_MPI_Comm comm, A_MPI_Comm *newcomm, A_MPI_Request *request);
  int A_PMPI_Comm_dup_with_info(A_MPI_Comm comm, A_MPI_Info info, A_MPI_Comm *newcomm);
  A_MPI_Comm A_PMPI_Comm_f2c(A_MPI_Fint comm);
  int A_PMPI_Comm_free_keyval(int *comm_keyval);
  int A_PMPI_Comm_free(A_MPI_Comm *comm);
  int A_PMPI_Comm_get_attr(A_MPI_Comm comm, int comm_keyval,
                                      void *attribute_val, int *flag);
  int A_PMPI_Comm_get_errhandler(A_MPI_Comm comm, A_MPI_Errhandler *erhandler);
  int A_PMPI_Comm_get_info(A_MPI_Comm comm, A_MPI_Info *info_used);
  int A_PMPI_Comm_get_name(A_MPI_Comm comm, char *comm_name, int *resultlen);
  int A_PMPI_Comm_get_parent(A_MPI_Comm *parent);
  int A_PMPI_Comm_group(A_MPI_Comm comm, A_MPI_Group *group);
  int A_PMPI_Comm_join(int fd, A_MPI_Comm *intercomm);
  int A_PMPI_Comm_rank(A_MPI_Comm comm, int *rank);
  int A_PMPI_Comm_remote_group(A_MPI_Comm comm, A_MPI_Group *group);
  int A_PMPI_Comm_remote_size(A_MPI_Comm comm, int *size);
  int A_PMPI_Comm_set_attr(A_MPI_Comm comm, int comm_keyval, void *attribute_val);
  int A_PMPI_Comm_set_errhandler(A_MPI_Comm comm, A_MPI_Errhandler errhandler);
  int A_PMPI_Comm_set_info(A_MPI_Comm comm, A_MPI_Info info);
  int A_PMPI_Comm_set_name(A_MPI_Comm comm, char *comm_name);
  int A_PMPI_Comm_size(A_MPI_Comm comm, int *size);
  int A_PMPI_Comm_spawn(char *command, char *argv[], int maxprocs, A_MPI_Info info,
                                   int root, A_MPI_Comm comm, A_MPI_Comm *intercomm,
                                   int array_of_errcodes[]);
  int A_PMPI_Comm_spawn_multiple(int count, char *array_of_commands[], char **array_of_argv[],
                                            int array_of_maxprocs[], A_MPI_Info array_of_info[],
                                            int root, A_MPI_Comm comm, A_MPI_Comm *intercomm,
                                            int array_of_errcodes[]);
  int A_PMPI_Comm_split(A_MPI_Comm comm, int color, int key, A_MPI_Comm *newcomm);
  int A_PMPI_Comm_split_type(A_MPI_Comm comm, int split_type, int key, A_MPI_Info info, A_MPI_Comm *newcomm);
  int A_PMPI_Comm_test_inter(A_MPI_Comm comm, int *flag);
  int A_PMPI_Compare_and_swap(void *origin_addr, void *compare_addr,
                                         void *result_addr, A_MPI_Datatype datatype, int target_rank,
                                         A_MPI_Aint target_disp, A_MPI_Win win);
  int A_PMPI_Dims_create(int nnodes, int ndims, int dims[]);
  A_MPI_Fint A_PMPI_Errhandler_c2f(A_MPI_Errhandler errhandler);
  int A_PMPI_Errhandler_create(A_MPI_Handler_function *function,
                                          A_MPI_Errhandler *errhandler);
  A_MPI_Errhandler A_PMPI_Errhandler_f2c(A_MPI_Fint errhandler);
  int A_PMPI_Errhandler_free(A_MPI_Errhandler *errhandler);
  int A_PMPI_Errhandler_get(A_MPI_Comm comm, A_MPI_Errhandler *errhandler);
  int A_PMPI_Errhandler_set(A_MPI_Comm comm, A_MPI_Errhandler errhandler);
  int A_PMPI_Error_class(int errorcode, int *errorclass);
  int A_PMPI_Error_string(int errorcode, char *string, int *resultlen);
  int A_PMPI_Exscan(void *sendbuf, void *recvbuf, int count,
                               A_MPI_Datatype datatype, A_MPI_Op op, A_MPI_Comm comm);
  int A_PMPI_Fetch_and_op(void *origin_addr, void *result_addr, A_MPI_Datatype datatype,
                                     int target_rank, A_MPI_Aint target_disp, A_MPI_Op op, A_MPI_Win win);
  int A_PMPI_Iexscan(void *sendbuf, void *recvbuf, int count,
                               A_MPI_Datatype datatype, A_MPI_Op op, A_MPI_Comm comm, A_MPI_Request *request);
  A_MPI_Fint A_PMPI_File_c2f(A_MPI_File file);
  A_MPI_File A_PMPI_File_f2c(A_MPI_Fint file);
  int A_PMPI_File_call_errhandler(A_MPI_File fh, int errorcode);
  int A_PMPI_File_create_errhandler(A_MPI_File_errhandler_function *function,
                                               A_MPI_Errhandler *errhandler);
  int A_PMPI_File_set_errhandler( A_MPI_File file, A_MPI_Errhandler errhandler);
  int A_PMPI_File_get_errhandler( A_MPI_File file, A_MPI_Errhandler *errhandler);
  int A_PMPI_File_open(A_MPI_Comm comm, char *filename, int amode,
                                  A_MPI_Info info, A_MPI_File *fh);
  int A_PMPI_File_close(A_MPI_File *fh);
  int A_PMPI_File_delete(char *filename, A_MPI_Info info);
  int A_PMPI_File_set_size(A_MPI_File fh, A_MPI_Offset size);
  int A_PMPI_File_preallocate(A_MPI_File fh, A_MPI_Offset size);
  int A_PMPI_File_get_size(A_MPI_File fh, A_MPI_Offset *size);
  int A_PMPI_File_get_group(A_MPI_File fh, A_MPI_Group *group);
  int A_PMPI_File_get_amode(A_MPI_File fh, int *amode);
  int A_PMPI_File_set_info(A_MPI_File fh, A_MPI_Info info);
  int A_PMPI_File_get_info(A_MPI_File fh, A_MPI_Info *info_used);
  int A_PMPI_File_set_view(A_MPI_File fh, A_MPI_Offset disp, A_MPI_Datatype etype,
                                      A_MPI_Datatype filetype, char *datarep, A_MPI_Info info);
  int A_PMPI_File_get_view(A_MPI_File fh, A_MPI_Offset *disp,
                                      A_MPI_Datatype *etype,
                                      A_MPI_Datatype *filetype, char *datarep);
  int A_PMPI_File_read_at(A_MPI_File fh, A_MPI_Offset offset, void *buf,
                                     int count, A_MPI_Datatype datatype, A_MPI_Status *status);
  int A_PMPI_File_read_at_all(A_MPI_File fh, A_MPI_Offset offset, void *buf,
                                         int count, A_MPI_Datatype datatype, A_MPI_Status *status);
  int A_PMPI_File_write_at(A_MPI_File fh, A_MPI_Offset offset, void *buf,
                                      int count, A_MPI_Datatype datatype, A_MPI_Status *status);
  int A_PMPI_File_write_at_all(A_MPI_File fh, A_MPI_Offset offset, void *buf,
                                          int count, A_MPI_Datatype datatype, A_MPI_Status *status);
  int A_PMPI_File_iread_at(A_MPI_File fh, A_MPI_Offset offset, void *buf,
                                      int count, A_MPI_Datatype datatype, A_MPI_Request *request);
  int A_PMPI_File_iwrite_at(A_MPI_File fh, A_MPI_Offset offset, void *buf,
                                       int count, A_MPI_Datatype datatype, A_MPI_Request *request);
  int A_PMPI_File_read(A_MPI_File fh, void *buf, int count,
                                  A_MPI_Datatype datatype, A_MPI_Status *status);
  int A_PMPI_File_read_all(A_MPI_File fh, void *buf, int count,
                                      A_MPI_Datatype datatype, A_MPI_Status *status);
  int A_PMPI_File_write(A_MPI_File fh, void *buf, int count,
                                   A_MPI_Datatype datatype, A_MPI_Status *status);
  int A_PMPI_File_write_all(A_MPI_File fh, void *buf, int count,
                                       A_MPI_Datatype datatype, A_MPI_Status *status);
  int A_PMPI_File_iread(A_MPI_File fh, void *buf, int count,
                                   A_MPI_Datatype datatype, A_MPI_Request *request);
  int A_PMPI_File_iwrite(A_MPI_File fh, void *buf, int count,
                                    A_MPI_Datatype datatype, A_MPI_Request *request);
  int A_PMPI_File_seek(A_MPI_File fh, A_MPI_Offset offset, int whence);
  int A_PMPI_File_get_position(A_MPI_File fh, A_MPI_Offset *offset);
  int A_PMPI_File_get_byte_offset(A_MPI_File fh, A_MPI_Offset offset,
                                             A_MPI_Offset *disp);
  int A_PMPI_File_read_shared(A_MPI_File fh, void *buf, int count,
                                         A_MPI_Datatype datatype, A_MPI_Status *status);
  int A_PMPI_File_write_shared(A_MPI_File fh, void *buf, int count,
                                          A_MPI_Datatype datatype, A_MPI_Status *status);
  int A_PMPI_File_iread_shared(A_MPI_File fh, void *buf, int count,
                                          A_MPI_Datatype datatype, A_MPI_Request *request);
  int A_PMPI_File_iwrite_shared(A_MPI_File fh, void *buf, int count,
                                           A_MPI_Datatype datatype, A_MPI_Request *request);
  int A_PMPI_File_read_ordered(A_MPI_File fh, void *buf, int count,
                                          A_MPI_Datatype datatype, A_MPI_Status *status);
  int A_PMPI_File_write_ordered(A_MPI_File fh, void *buf, int count,
                                           A_MPI_Datatype datatype, A_MPI_Status *status);
  int A_PMPI_File_seek_shared(A_MPI_File fh, A_MPI_Offset offset, int whence);
  int A_PMPI_File_get_position_shared(A_MPI_File fh, A_MPI_Offset *offset);
  int A_PMPI_File_read_at_all_begin(A_MPI_File fh, A_MPI_Offset offset, void *buf,
                                               int count, A_MPI_Datatype datatype);
  int A_PMPI_File_read_at_all_end(A_MPI_File fh, void *buf, A_MPI_Status *status);
  int A_PMPI_File_write_at_all_begin(A_MPI_File fh, A_MPI_Offset offset, void *buf,
                                                int count, A_MPI_Datatype datatype);
  int A_PMPI_File_write_at_all_end(A_MPI_File fh, void *buf, A_MPI_Status *status);
  int A_PMPI_File_read_all_begin(A_MPI_File fh, void *buf, int count,
                                            A_MPI_Datatype datatype);
  int A_PMPI_File_read_all_end(A_MPI_File fh, void *buf, A_MPI_Status *status);
  int A_PMPI_File_write_all_begin(A_MPI_File fh, void *buf, int count,
                                             A_MPI_Datatype datatype);
  int A_PMPI_File_write_all_end(A_MPI_File fh, void *buf, A_MPI_Status *status);
  int A_PMPI_File_read_ordered_begin(A_MPI_File fh, void *buf, int count,
                                                A_MPI_Datatype datatype);
  int A_PMPI_File_read_ordered_end(A_MPI_File fh, void *buf, A_MPI_Status *status);
  int A_PMPI_File_write_ordered_begin(A_MPI_File fh, void *buf, int count,
                                                 A_MPI_Datatype datatype);
  int A_PMPI_File_write_ordered_end(A_MPI_File fh, void *buf, A_MPI_Status *status);
  int A_PMPI_File_get_type_extent(A_MPI_File fh, A_MPI_Datatype datatype,
                                             A_MPI_Aint *extent);
  int A_PMPI_File_set_atomicity(A_MPI_File fh, int flag);
  int A_PMPI_File_get_atomicity(A_MPI_File fh, int *flag);
  int A_PMPI_File_sync(A_MPI_File fh);
  int A_PMPI_Finalize(void);
  int A_PMPI_Finalized(int *flag);
  int A_PMPI_Free_mem(void *base);
  int A_PMPI_Gather(void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                               void *recvbuf, int recvcount, A_MPI_Datatype recvtype,
                               int root, A_MPI_Comm comm);
  int A_PMPI_Igather(void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                               void *recvbuf, int recvcount, A_MPI_Datatype recvtype,
                               int root, A_MPI_Comm comm, A_MPI_Request *request);
  int A_PMPI_Gatherv(void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                                void *recvbuf, int recvcounts[], int displs[],
                                A_MPI_Datatype recvtype, int root, A_MPI_Comm comm);
  int A_PMPI_Igatherv(void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                                void *recvbuf, int recvcounts[], int displs[],
                                A_MPI_Datatype recvtype, int root, A_MPI_Comm comm, A_MPI_Request *request);
  int A_PMPI_Get_address(void *location, A_MPI_Aint *address);
  int A_PMPI_Get_count(A_MPI_Status *status, A_MPI_Datatype datatype, int *count);
  int A_PMPI_Get_elements(A_MPI_Status *status, A_MPI_Datatype datatype,
                                     int *count);
  int A_PMPI_Get_elements_x(A_MPI_Status *status, A_MPI_Datatype datatype,
                                       A_MPI_Count *count);
  int A_PMPI_Get(void *origin_addr, int origin_count,
                            A_MPI_Datatype origin_datatype, int target_rank,
                            A_MPI_Aint target_disp, int target_count,
                            A_MPI_Datatype target_datatype, A_MPI_Win win);
  int A_PMPI_Get_accumulate(void *origin_addr, int origin_count, A_MPI_Datatype origin_datatype,
                                       void *result_addr, int result_count, A_MPI_Datatype result_datatype,
                                       int target_rank, A_MPI_Aint target_disp, int target_count,
                                       A_MPI_Datatype target_datatype, A_MPI_Op op, A_MPI_Win win);
  int A_PMPI_Get_library_version(char *version, int *resultlen);
  int A_PMPI_Get_processor_name(char *name, int *resultlen);
  int A_PMPI_Get_version(int *version, int *subversion);
  int A_PMPI_Graph_create(A_MPI_Comm comm_old, int nnodes, int index[],
                                     int edges[], int reorder, A_MPI_Comm *comm_graph);
  int A_PMPI_Graph_get(A_MPI_Comm comm, int maxindex, int maxedges,
                                  int index[], int edges[]);
  int A_PMPI_Graph_map(A_MPI_Comm comm, int nnodes, int index[], int edges[],
                                  int *newrank);
  int A_PMPI_Graph_neighbors_count(A_MPI_Comm comm, int rank, int *nneighbors);
  int A_PMPI_Graph_neighbors(A_MPI_Comm comm, int rank, int maxneighbors,
                                        int neighbors[]);
  int A_PMPI_Graphdims_get(A_MPI_Comm comm, int *nnodes, int *nedges);
  int A_PMPI_Grequest_complete(A_MPI_Request request);
  int A_PMPI_Grequest_start(A_MPI_Grequest_query_function *query_fn,
                                       A_MPI_Grequest_free_function *free_fn,
                                       A_MPI_Grequest_cancel_function *cancel_fn,
                                       void *extra_state, A_MPI_Request *request);
  A_MPI_Fint A_PMPI_Group_c2f(A_MPI_Group group);
  int A_PMPI_Group_compare(A_MPI_Group group1, A_MPI_Group group2, int *result);
  int A_PMPI_Group_difference(A_MPI_Group group1, A_MPI_Group group2,
                                         A_MPI_Group *newgroup);
  int A_PMPI_Group_excl(A_MPI_Group group, int n, int ranks[],
                                   A_MPI_Group *newgroup);
  A_MPI_Group A_PMPI_Group_f2c(A_MPI_Fint group);
  int A_PMPI_Group_free(A_MPI_Group *group);
  int A_PMPI_Group_incl(A_MPI_Group group, int n, int ranks[],
                                   A_MPI_Group *newgroup);
  int A_PMPI_Group_intersection(A_MPI_Group group1, A_MPI_Group group2,
                                           A_MPI_Group *newgroup);
  int A_PMPI_Group_range_excl(A_MPI_Group group, int n, int ranges[][3],
                                         A_MPI_Group *newgroup);
  int A_PMPI_Group_range_incl(A_MPI_Group group, int n, int ranges[][3],
                                         A_MPI_Group *newgroup);
  int A_PMPI_Group_rank(A_MPI_Group group, int *rank);
  int A_PMPI_Group_size(A_MPI_Group group, int *size);
  int A_PMPI_Group_translate_ranks(A_MPI_Group group1, int n, int ranks1[],
                                              A_MPI_Group group2, int ranks2[]);
  int A_PMPI_Group_union(A_MPI_Group group1, A_MPI_Group group2,
                                    A_MPI_Group *newgroup);
  int A_PMPI_Ibsend(void *buf, int count, A_MPI_Datatype datatype, int dest,
                               int tag, A_MPI_Comm comm, A_MPI_Request *request);
  int A_PMPI_Improbe(int source, int tag, A_MPI_Comm comm,
                                int *flag, A_MPI_Message *message,
                                A_MPI_Status *status);
  int A_PMPI_Imrecv(void *buf, int count, A_MPI_Datatype type,
                               A_MPI_Message *message, A_MPI_Request *request);
  A_MPI_Fint A_PMPI_Info_c2f(A_MPI_Info info);
  int A_PMPI_Info_create(A_MPI_Info *info);
  int A_PMPI_Info_delete(A_MPI_Info info, char *key);
  int A_PMPI_Info_dup(A_MPI_Info info, A_MPI_Info *newinfo);
  A_MPI_Info A_PMPI_Info_f2c(A_MPI_Fint info);
  int A_PMPI_Info_free(A_MPI_Info *info);
  int A_PMPI_Info_get(A_MPI_Info info, char *key, int valuelen,
                                 char *value, int *flag);
  int A_PMPI_Info_get_nkeys(A_MPI_Info info, int *nkeys);
  int A_PMPI_Info_get_nthkey(A_MPI_Info info, int n, char *key);
  int A_PMPI_Info_get_valuelen(A_MPI_Info info, char *key, int *valuelen,
                                          int *flag);
  int A_PMPI_Info_set(A_MPI_Info info, char *key, char *value);
  int A_PMPI_Init(int *argc, char ***argv);
  int A_PMPI_Initialized(int *flag);
  int A_PMPI_Init_thread(int *argc, char ***argv, int required,
                                    int *provided);
  int A_PMPI_Intercomm_create(A_MPI_Comm local_comm, int local_leader,
                                         A_MPI_Comm bridge_comm, int remote_leader,
                                         int tag, A_MPI_Comm *newintercomm);
  int A_PMPI_Intercomm_merge(A_MPI_Comm intercomm, int high,
                                        A_MPI_Comm *newintercomm);
  int A_PMPI_Iprobe(int source, int tag, A_MPI_Comm comm, int *flag,
                               A_MPI_Status *status);
  int A_PMPI_Irecv(void *buf, int count, A_MPI_Datatype datatype, int source,
                              int tag, A_MPI_Comm comm, A_MPI_Request *request);
  int A_PMPI_Irsend(void *buf, int count, A_MPI_Datatype datatype, int dest,
                               int tag, A_MPI_Comm comm, A_MPI_Request *request);
  int A_PMPI_Isend(void *buf, int count, A_MPI_Datatype datatype, int dest,
                              int tag, A_MPI_Comm comm, A_MPI_Request *request);
  int A_PMPI_Issend(void *buf, int count, A_MPI_Datatype datatype, int dest,
                               int tag, A_MPI_Comm comm, A_MPI_Request *request);
  int A_PMPI_Is_thread_main(int *flag);
  int A_PMPI_Keyval_create(A_MPI_Copy_function *copy_fn,
                                      A_MPI_Delete_function *delete_fn,
                                      int *keyval, void *extra_state);
  int A_PMPI_Keyval_free(int *keyval);
  int A_PMPI_Lookup_name(char *service_name, A_MPI_Info info, char *port_name);
  A_MPI_Fint A_PMPI_Message_c2f(A_MPI_Message message);
  A_MPI_Message A_PMPI_Message_f2c(A_MPI_Fint message);
  int A_PMPI_Mprobe(int source, int tag, A_MPI_Comm comm,
                               A_MPI_Message *message,
                               A_MPI_Status *status);
  int A_PMPI_Mrecv(void *buf, int count, A_MPI_Datatype type,
                              A_MPI_Message *message, A_MPI_Status *status);
  int A_PMPI_Neighbor_allgather(void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                                           void *recvbuf, int recvcount, A_MPI_Datatype recvtype,
                                           A_MPI_Comm comm);
  int A_PMPI_Ineighbor_allgather(void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                                            void *recvbuf, int recvcount, A_MPI_Datatype recvtype,
                                            A_MPI_Comm comm, A_MPI_Request *request);
  int A_PMPI_Neighbor_allgatherv(void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                                            void *recvbuf, int recvcounts[], int displs[],
                                            A_MPI_Datatype recvtype, A_MPI_Comm comm);
  int A_PMPI_Ineighbor_allgatherv(void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                                             void *recvbuf, int recvcounts[], int displs[],
                                             A_MPI_Datatype recvtype, A_MPI_Comm comm, A_MPI_Request *request);
  int A_PMPI_Neighbor_alltoall(void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                                          void *recvbuf, int recvcount, A_MPI_Datatype recvtype,
                                          A_MPI_Comm comm);
  int A_PMPI_Ineighbor_alltoall(void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                                           void *recvbuf, int recvcount, A_MPI_Datatype recvtype,
                                           A_MPI_Comm comm, A_MPI_Request *request);
  int A_PMPI_Neighbor_alltoallv(void *sendbuf, int sendcounts[], int sdispls[],  A_MPI_Datatype sendtype,
                                           void *recvbuf, int recvcounts[], int rdispls[], A_MPI_Datatype recvtype,
                                           A_MPI_Comm comm);
  int A_PMPI_Ineighbor_alltoallv(void *sendbuf, int sendcounts[], int sdispls[], A_MPI_Datatype sendtype,
                                            void *recvbuf, int recvcounts[], int rdispls[], A_MPI_Datatype recvtype,
                                            A_MPI_Comm comm, A_MPI_Request *request);
  int A_PMPI_Neighbor_alltoallw(void *sendbuf, int sendcounts[], A_MPI_Aint sdispls[], A_MPI_Datatype sendtypes[],
                                           void *recvbuf, int recvcounts[], A_MPI_Aint rdispls[], A_MPI_Datatype recvtypes[],
                                           A_MPI_Comm comm);
  int A_PMPI_Ineighbor_alltoallw(void *sendbuf, int sendcounts[], A_MPI_Aint sdispls[], A_MPI_Datatype sendtypes[],
                                            void *recvbuf, int recvcounts[], A_MPI_Aint rdispls[], A_MPI_Datatype recvtypes[],
                                            A_MPI_Comm comm, A_MPI_Request *request);
  A_MPI_Fint A_PMPI_Op_c2f(A_MPI_Op op);
  int A_PMPI_Op_commutative(A_MPI_Op op, int *commute);
  int A_PMPI_Op_create(A_MPI_User_function *function, int commute, A_MPI_Op *op);
  int A_PMPI_Open_port(A_MPI_Info info, char *port_name);
  A_MPI_Op A_PMPI_Op_f2c(A_MPI_Fint op);
  int A_PMPI_Op_free(A_MPI_Op *op);
  int A_PMPI_Pack_external(char datarep[], void *inbuf, int incount,
                                      A_MPI_Datatype datatype, void *outbuf,
                                      A_MPI_Aint outsize, A_MPI_Aint *position);
  int A_PMPI_Pack_external_size(char datarep[], int incount,
                                           A_MPI_Datatype datatype, A_MPI_Aint *size);
  int A_PMPI_Pack(void *inbuf, int incount, A_MPI_Datatype datatype,
                             void *outbuf, int outsize, int *position, A_MPI_Comm comm);
  int A_PMPI_Pack_size(int incount, A_MPI_Datatype datatype, A_MPI_Comm comm,
                                  int *size);
  int A_PMPI_Pcontrol(int level, ...);
  int A_PMPI_Probe(int source, int tag, A_MPI_Comm comm, A_MPI_Status *status);
  int A_PMPI_Publish_name(char *service_name, A_MPI_Info info,
                                     char *port_name);
  int A_PMPI_Put(void *origin_addr, int origin_count, A_MPI_Datatype origin_datatype,
                            int target_rank, A_MPI_Aint target_disp, int target_count,
                            A_MPI_Datatype target_datatype, A_MPI_Win win);
  int A_PMPI_Query_thread(int *provided);
  int A_PMPI_Raccumulate(void *origin_addr, int origin_count, A_MPI_Datatype origin_datatype, 
                                    int target_rank, A_MPI_Aint target_disp, int target_count, 
                                    A_MPI_Datatype target_datatype, A_MPI_Op op, A_MPI_Win win, A_MPI_Request *request);
  int A_PMPI_Recv_init(void *buf, int count, A_MPI_Datatype datatype, int source,
                                  int tag, A_MPI_Comm comm, A_MPI_Request *request);
  int A_PMPI_Recv(void *buf, int count, A_MPI_Datatype datatype, int source,
                             int tag, A_MPI_Comm comm, A_MPI_Status *status);
  int A_PMPI_Reduce(void *sendbuf, void *recvbuf, int count,
                               A_MPI_Datatype datatype, A_MPI_Op op, int root, A_MPI_Comm comm);
  int A_PMPI_Ireduce(void *sendbuf, void *recvbuf, int count,
                               A_MPI_Datatype datatype, A_MPI_Op op, int root, A_MPI_Comm comm, A_MPI_Request *request);
  int A_PMPI_Reduce_local(void *inbuf, void *inoutbuf, int count,
                                     A_MPI_Datatype datatype, A_MPI_Op);
  int A_PMPI_Reduce_scatter(void *sendbuf, void *recvbuf, int recvcounts[],
                                       A_MPI_Datatype datatype, A_MPI_Op op, A_MPI_Comm comm);
  int A_PMPI_Ireduce_scatter(void *sendbuf, void *recvbuf, int recvcounts[],
                                        A_MPI_Datatype datatype, A_MPI_Op op, A_MPI_Comm comm, A_MPI_Request *request);
  int A_PMPI_Reduce_scatter_block(void *sendbuf, void *recvbuf, int recvcount,
                                             A_MPI_Datatype datatype, A_MPI_Op op, A_MPI_Comm comm);
  int A_PMPI_Ireduce_scatter_block(void *sendbuf, void *recvbuf, int recvcount,
                                              A_MPI_Datatype datatype, A_MPI_Op op, A_MPI_Comm comm, A_MPI_Request *request);
  int A_PMPI_Register_datarep(char *datarep,
                                         A_MPI_Datarep_conversion_function *read_conversion_fn,
                                         A_MPI_Datarep_conversion_function *write_conversion_fn,
                                         A_MPI_Datarep_extent_function *dtype_file_extent_fn,
                                         void *extra_state);
  A_MPI_Fint A_PMPI_Request_c2f(A_MPI_Request request);
  A_MPI_Request A_PMPI_Request_f2c(A_MPI_Fint request);
  int A_PMPI_Request_free(A_MPI_Request *request);
  int A_PMPI_Request_get_status(A_MPI_Request request, int *flag,
                                           A_MPI_Status *status);
  int A_PMPI_Rget(void *origin_addr, int origin_count, A_MPI_Datatype origin_datatype, 
                             int target_rank, A_MPI_Aint target_disp, int target_count, A_MPI_Datatype target_datatype,
                             A_MPI_Win win, A_MPI_Request *request);
  int A_PMPI_Rget_accumulate(void *origin_addr, int origin_count, A_MPI_Datatype origin_datatype,
                                        void *result_addr, int result_count, A_MPI_Datatype result_datatype,
                                        int target_rank, A_MPI_Aint target_disp, int target_count, 
                                        A_MPI_Datatype target_datatype, A_MPI_Op op,
                                        A_MPI_Win win, A_MPI_Request *request);
  int A_PMPI_Rput(void *origin_addr, int origin_count, A_MPI_Datatype origin_datatype,
                             int target_rank, A_MPI_Aint target_disp, int target_cout, 
                             A_MPI_Datatype target_datatype, A_MPI_Win win, A_MPI_Request *request);
  int A_PMPI_Rsend(void *ibuf, int count, A_MPI_Datatype datatype, int dest,
                              int tag, A_MPI_Comm comm);
  int A_PMPI_Rsend_init(void *buf, int count, A_MPI_Datatype datatype,
                                   int dest, int tag, A_MPI_Comm comm,
                                   A_MPI_Request *request);
  int A_PMPI_Scan(void *sendbuf, void *recvbuf, int count,
                             A_MPI_Datatype datatype, A_MPI_Op op, A_MPI_Comm comm);
  int A_PMPI_Iscan(void *sendbuf, void *recvbuf, int count,
                             A_MPI_Datatype datatype, A_MPI_Op op, A_MPI_Comm comm, A_MPI_Request *request);
  int A_PMPI_Scatter(void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                                void *recvbuf, int recvcount, A_MPI_Datatype recvtype,
                                int root, A_MPI_Comm comm);
  int A_PMPI_Iscatter(void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                                void *recvbuf, int recvcount, A_MPI_Datatype recvtype,
                                int root, A_MPI_Comm comm, A_MPI_Request *request);
  int A_PMPI_Scatterv(void *sendbuf, int sendcounts[], int displs[],
                                 A_MPI_Datatype sendtype, void *recvbuf, int recvcount,
                                 A_MPI_Datatype recvtype, int root, A_MPI_Comm comm);
  int A_PMPI_Iscatterv(void *sendbuf, int sendcounts[], int displs[],
                                 A_MPI_Datatype sendtype, void *recvbuf, int recvcount,
                                 A_MPI_Datatype recvtype, int root, A_MPI_Comm comm, A_MPI_Request *request);
  int A_PMPI_Send_init(void *buf, int count, A_MPI_Datatype datatype,
                                  int dest, int tag, A_MPI_Comm comm,
                                  A_MPI_Request *request);
  int A_PMPI_Send(void *buf, int count, A_MPI_Datatype datatype, int dest,
                             int tag, A_MPI_Comm comm);
  int A_PMPI_Sendrecv(void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                                 int dest, int sendtag, void *recvbuf, int recvcount,
                                 A_MPI_Datatype recvtype, int source, int recvtag,
                                 A_MPI_Comm comm,  A_MPI_Status *status);
  int A_PMPI_Sendrecv_replace(void * buf, int count, A_MPI_Datatype datatype,
                                         int dest, int sendtag, int source, int recvtag,
                                         A_MPI_Comm comm, A_MPI_Status *status);
  int A_PMPI_Ssend_init(void *buf, int count, A_MPI_Datatype datatype,
                                   int dest, int tag, A_MPI_Comm comm,
                                   A_MPI_Request *request);
  int A_PMPI_Ssend(void *buf, int count, A_MPI_Datatype datatype, int dest,
                              int tag, A_MPI_Comm comm);
  int A_PMPI_Start(A_MPI_Request *request);
  int A_PMPI_Startall(int count, A_MPI_Request array_of_requests[]);
  int A_PMPI_Status_c2f(A_MPI_Status *c_status, A_MPI_Fint *f_status);
  int A_PMPI_Status_f2c(A_MPI_Fint *f_status, A_MPI_Status *c_status);
  int A_PMPI_Status_set_cancelled(A_MPI_Status *status, int flag);
  int A_PMPI_Status_set_elements(A_MPI_Status *status, A_MPI_Datatype datatype,
                                            int count);
  int A_PMPI_Status_set_elements_x(A_MPI_Status *status, A_MPI_Datatype datatype,
                                              A_MPI_Count count);
  int A_PMPI_Testall(int count, A_MPI_Request array_of_requests[], int *flag,
                                A_MPI_Status array_of_statuses[]);
  int A_PMPI_Testany(int count, A_MPI_Request array_of_requests[], int *index, int *flag, A_MPI_Status *status);
  int A_PMPI_Test(A_MPI_Request *request, int *flag, A_MPI_Status *status);
  int A_PMPI_Test_cancelled(A_MPI_Status *status, int *flag);
  int A_PMPI_Testsome(int incount, A_MPI_Request array_of_requests[],
                                 int *outcount, int array_of_indices[],
                                 A_MPI_Status array_of_statuses[]);
  int A_PMPI_Topo_test(A_MPI_Comm comm, int *status);
  A_MPI_Fint A_PMPI_Type_c2f(A_MPI_Datatype datatype);
  int A_PMPI_Type_commit(A_MPI_Datatype *type);
  int A_PMPI_Type_contiguous(int count, A_MPI_Datatype oldtype,
                                        A_MPI_Datatype *newtype);
  int A_PMPI_Type_create_darray(int size, int rank, int ndims,
                                           int gsize_array[], int distrib_array[],
                                           int darg_array[], int psize_array[],
                                           int order, A_MPI_Datatype oldtype,
                                           A_MPI_Datatype *newtype);
  int A_PMPI_Type_create_f90_complex(int p, int r, A_MPI_Datatype *newtype);
  int A_PMPI_Type_create_f90_integer(int r, A_MPI_Datatype *newtype);
  int A_PMPI_Type_create_f90_real(int p, int r, A_MPI_Datatype *newtype);
  int A_PMPI_Type_create_hindexed(int count, int array_of_blocklengths[],
                                             A_MPI_Aint array_of_displacements[],
                                             A_MPI_Datatype oldtype,
                                             A_MPI_Datatype *newtype);
  int A_PMPI_Type_create_hvector(int count, int blocklength, A_MPI_Aint stride,
                                            A_MPI_Datatype oldtype,
                                            A_MPI_Datatype *newtype);
  int A_PMPI_Type_create_keyval(A_MPI_Type_copy_attr_function *type_copy_attr_fn,
                                           A_MPI_Type_delete_attr_function *type_delete_attr_fn,
                                           int *type_keyval, void *extra_state);
  int A_PMPI_Type_create_hindexed_block(int count, int blocklength,
                                                   A_MPI_Aint array_of_displacements[],
                                                   A_MPI_Datatype oldtype,
                                                   A_MPI_Datatype *newtype);
  int A_PMPI_Type_create_indexed_block(int count, int blocklength,
                                                  int array_of_displacements[],
                                                  A_MPI_Datatype oldtype,
                                                  A_MPI_Datatype *newtype);
  int A_PMPI_Type_create_struct(int count, int array_of_block_lengths[],
                                           A_MPI_Aint array_of_displacements[],
                                           A_MPI_Datatype array_of_types[],
                                           A_MPI_Datatype *newtype);
  int A_PMPI_Type_create_subarray(int ndims, int size_array[], int subsize_array[],
                                             int start_array[], int order,
                                             A_MPI_Datatype oldtype, A_MPI_Datatype *newtype);
  int A_PMPI_Type_create_resized(A_MPI_Datatype oldtype, A_MPI_Aint lb,
                                            A_MPI_Aint extent, A_MPI_Datatype *newtype);
  int A_PMPI_Type_delete_attr(A_MPI_Datatype type, int type_keyval);
  int A_PMPI_Type_dup(A_MPI_Datatype type, A_MPI_Datatype *newtype);
  int A_PMPI_Type_extent(A_MPI_Datatype type, A_MPI_Aint *extent);
  int A_PMPI_Type_free(A_MPI_Datatype *type);
  int A_PMPI_Type_free_keyval(int *type_keyval);
  A_MPI_Datatype A_PMPI_Type_f2c(A_MPI_Fint datatype);
  int A_PMPI_Type_get_attr(A_MPI_Datatype type, int type_keyval,
                                      void *attribute_val, int *flag);
  int A_PMPI_Type_get_contents(A_MPI_Datatype mtype, int max_integers,
                                          int max_addresses, int max_datatypes,
                                          int array_of_integers[],
                                          A_MPI_Aint array_of_addresses[],
                                          A_MPI_Datatype array_of_datatypes[]);
  int A_PMPI_Type_get_envelope(A_MPI_Datatype type, int *num_integers,
                                          int *num_addresses, int *num_datatypes,
                                          int *combiner);
  int A_PMPI_Type_get_extent(A_MPI_Datatype type, A_MPI_Aint *lb,
                                        A_MPI_Aint *extent);
  int A_PMPI_Type_get_extent_x(A_MPI_Datatype type, A_MPI_Count *lb,
                                          A_MPI_Count *extent);
  int A_PMPI_Type_get_name(A_MPI_Datatype type, char *type_name,
                                      int *resultlen);
  int A_PMPI_Type_get_true_extent(A_MPI_Datatype datatype, A_MPI_Aint *true_lb,
                                             A_MPI_Aint *true_extent);
  int A_PMPI_Type_get_true_extent_x(A_MPI_Datatype datatype, A_MPI_Count *true_lb,
                                               A_MPI_Count *true_extent);
  int A_PMPI_Type_hindexed(int count, int array_of_blocklengths[],
                                      A_MPI_Aint array_of_displacements[],
                                      A_MPI_Datatype oldtype, A_MPI_Datatype *newtype);
  int A_PMPI_Type_hvector(int count, int blocklength, A_MPI_Aint stride,
                                     A_MPI_Datatype oldtype, A_MPI_Datatype *newtype);
  int A_PMPI_Type_indexed(int count, int array_of_blocklengths[],
                                     int array_of_displacements[],
                                     A_MPI_Datatype oldtype, A_MPI_Datatype *newtype);
  int A_PMPI_Type_lb(A_MPI_Datatype type, A_MPI_Aint *lb);
  int A_PMPI_Type_match_size(int typeclass, int size, A_MPI_Datatype *type);
  int A_PMPI_Type_set_attr(A_MPI_Datatype type, int type_keyval,
                                      void *attr_val);
  int A_PMPI_Type_set_name(A_MPI_Datatype type, char *type_name);
  int A_PMPI_Type_size(A_MPI_Datatype type, int *size);
  int A_PMPI_Type_size_x(A_MPI_Datatype type, A_MPI_Count *size);
  int A_PMPI_Type_struct(int count, int array_of_blocklengths[],
                                    A_MPI_Aint array_of_displacements[],
                                    A_MPI_Datatype array_of_types[],
                                    A_MPI_Datatype *newtype);
  int A_PMPI_Type_ub(A_MPI_Datatype mtype, A_MPI_Aint *ub);
  int A_PMPI_Type_vector(int count, int blocklength, int stride,
                                    A_MPI_Datatype oldtype, A_MPI_Datatype *newtype);
  int A_PMPI_Unpack(void *inbuf, int insize, int *position,
                               void *outbuf, int outcount, A_MPI_Datatype datatype,
                               A_MPI_Comm comm);
  int A_PMPI_Unpublish_name(char *service_name, A_MPI_Info info,
                                       char *port_name);
  int A_PMPI_Unpack_external (char datarep[], void *inbuf, A_MPI_Aint insize,
                                         A_MPI_Aint *position, void *outbuf, int outcount,
                                         A_MPI_Datatype datatype);
  int A_PMPI_Waitall(int count, A_MPI_Request array_of_requests[],
                                A_MPI_Status array_of_statuses[]);
  int A_PMPI_Waitany(int count, A_MPI_Request array_of_requests[],
                                int *index, A_MPI_Status *status);
  int A_PMPI_Wait(A_MPI_Request *request, A_MPI_Status *status);
  int A_PMPI_Waitsome(int incount, A_MPI_Request array_of_requests[],
                                 int *outcount, int array_of_indices[],
                                 A_MPI_Status array_of_statuses[]);
  int A_PMPI_Win_allocate(A_MPI_Aint size, int disp_unit, A_MPI_Info info,
                                     A_MPI_Comm comm, void *baseptr, A_MPI_Win *win);
  int A_PMPI_Win_allocate_shared(A_MPI_Aint size, int disp_unit, A_MPI_Info info,
                                            A_MPI_Comm comm, void *baseptr, A_MPI_Win *win);
  int A_PMPI_Win_attach(A_MPI_Win win, void *base, A_MPI_Aint size);
  A_MPI_Fint A_PMPI_Win_c2f(A_MPI_Win win);
  int A_PMPI_Win_call_errhandler(A_MPI_Win win, int errorcode);
  int A_PMPI_Win_complete(A_MPI_Win win);
  int A_PMPI_Win_create(void *base, A_MPI_Aint size, int disp_unit,
                                   A_MPI_Info info, A_MPI_Comm comm, A_MPI_Win *win);
  int A_PMPI_Win_create_dynamic(A_MPI_Info info, A_MPI_Comm comm, A_MPI_Win *win);
  int A_PMPI_Win_create_errhandler(A_MPI_Win_errhandler_function *function,
                                              A_MPI_Errhandler *errhandler);
  int A_PMPI_Win_create_keyval(A_MPI_Win_copy_attr_function *win_copy_attr_fn,
                                          A_MPI_Win_delete_attr_function *win_delete_attr_fn,
                                          int *win_keyval, void *extra_state);
  int A_PMPI_Win_delete_attr(A_MPI_Win win, int win_keyval);
  int A_PMPI_Win_detach(A_MPI_Win win, void *base);
  A_MPI_Win A_PMPI_Win_f2c(A_MPI_Fint win);
  int A_PMPI_Win_fence(int assert, A_MPI_Win win);
  int A_PMPI_Win_flush(int rank, A_MPI_Win win);
  int A_PMPI_Win_flush_all(A_MPI_Win win);
  int A_PMPI_Win_flush_local(int rank, A_MPI_Win win);
  int A_PMPI_Win_flush_local_all(A_MPI_Win win);
  int A_PMPI_Win_free(A_MPI_Win *win);
  int A_PMPI_Win_free_keyval(int *win_keyval);
  int A_PMPI_Win_get_attr(A_MPI_Win win, int win_keyval,
                                     void *attribute_val, int *flag);
  int A_PMPI_Win_get_errhandler(A_MPI_Win win, A_MPI_Errhandler *errhandler);
  int A_PMPI_Win_get_group(A_MPI_Win win, A_MPI_Group *group);
  int A_PMPI_Win_get_info(A_MPI_Win win, A_MPI_Info *info_used);
  int A_PMPI_Win_get_name(A_MPI_Win win, char *win_name, int *resultlen);
  int A_PMPI_Win_lock(int lock_type, int rank, int assert, A_MPI_Win win);
  int A_PMPI_Win_lock_all(int assert, A_MPI_Win win);
  int A_PMPI_Win_post(A_MPI_Group group, int assert, A_MPI_Win win);
  int A_PMPI_Win_set_attr(A_MPI_Win win, int win_keyval, void *attribute_val);
  int A_PMPI_Win_set_errhandler(A_MPI_Win win, A_MPI_Errhandler errhandler);
  int A_PMPI_Win_set_info(A_MPI_Win win, A_MPI_Info info);
  int A_PMPI_Win_set_name(A_MPI_Win win, char *win_name);
  int A_PMPI_Win_shared_query(A_MPI_Win win, int rank, A_MPI_Aint *size, int *disp_unit, void *baseptr);
  int A_PMPI_Win_start(A_MPI_Group group, int assert, A_MPI_Win win);
  int A_PMPI_Win_sync(A_MPI_Win win);
  int A_PMPI_Win_test(A_MPI_Win win, int *flag);
  int A_PMPI_Win_unlock(int rank, A_MPI_Win win);
  int A_PMPI_Win_unlock_all(A_MPI_Win win);
  int A_PMPI_Win_wait(A_MPI_Win win);
  double A_PMPI_Wtick(void);
  double A_PMPI_Wtime(void);
  int A_PMPI_T_init_thread (int required, int *provided);
  int A_PMPI_T_finalize (void);
  int A_PMPI_T_cvar_get_num (int *num_cvar);
  int A_PMPI_T_cvar_get_info (int cvar_index, char *name, int *name_len,
                                         int *verbosity, A_MPI_Datatype *datatype,
                                         A_MPI_T_enum *enumtype, char *desc,
                                         int *desc_len, int *bind, int *scope);
  int A_PMPI_T_cvar_get_index (char *name, int *cvar_index);
  int A_PMPI_T_cvar_handle_alloc (int cvar_index, void *obj_handle,
                                            A_MPI_T_cvar_handle *handle, int *count);
  int A_PMPI_T_cvar_handle_free (A_MPI_T_cvar_handle *handle);
  int A_PMPI_T_cvar_read (A_MPI_T_cvar_handle handle, void *buf);
  int A_PMPI_T_cvar_write (A_MPI_T_cvar_handle handle, void *buf);
  int A_PMPI_T_category_get_num(int *num_cat);
  int A_PMPI_T_category_get_info(int cat_index, char *name, int *name_len,
                                            char *desc, int *desc_len, int *num_cvars,
                                            int *num_pvars, int *num_categories);
  int A_PMPI_T_category_get_index (char *name, int *category_index);
  int A_PMPI_T_category_get_cvars(int cat_index, int len, int indices[]);
  int A_PMPI_T_category_get_pvars(int cat_index, int len, int indices[]);
  int A_PMPI_T_category_get_categories(int cat_index, int len, int indices[]);
  int A_PMPI_T_category_changed(int *stamp);

  int A_PMPI_T_pvar_get_num(int *num_pvar);
  int A_PMPI_T_pvar_get_info(int pvar_index, char *name, int *name_len,
                                        int *verbosity, int *var_class, A_MPI_Datatype *datatype,
                                        A_MPI_T_enum *enumtype, char *desc, int *desc_len, int *bind,
                                        int *readonly, int *continuous, int *atomic);
  int A_PMPI_T_pvar_get_index (char *name, int var_class, int *pvar_index);
  int A_PMPI_T_pvar_session_create(A_MPI_T_pvar_session *session);
  int A_PMPI_T_pvar_session_free(A_MPI_T_pvar_session *session);
  int A_PMPI_T_pvar_handle_alloc(A_MPI_T_pvar_session session, int pvar_index,
                                            void *obj_handle, A_MPI_T_pvar_handle *handle, int *count);
  int A_PMPI_T_pvar_handle_free(A_MPI_T_pvar_session session, A_MPI_T_pvar_handle *handle);
  int A_PMPI_T_pvar_start(A_MPI_T_pvar_session session, A_MPI_T_pvar_handle handle);
  int A_PMPI_T_pvar_stop(A_MPI_T_pvar_session session, A_MPI_T_pvar_handle handle);
  int A_PMPI_T_pvar_read(A_MPI_T_pvar_session session, A_MPI_T_pvar_handle handle,
                                    void *buf);
  int A_PMPI_T_pvar_write(A_MPI_T_pvar_session session, A_MPI_T_pvar_handle handle,
                                     void *buf);
  int A_PMPI_T_pvar_reset(A_MPI_T_pvar_session session, A_MPI_T_pvar_handle handle);
  int A_PMPI_T_pvar_readreset(A_MPI_T_pvar_session session, A_MPI_T_pvar_handle handle,
                                         void *buf);
  int A_PMPI_T_enum_get_info(A_MPI_T_enum enumtype, int *num, char *name, int *name_len);
  int A_PMPI_T_enum_get_item(A_MPI_T_enum enumtype, int index, int *value, char *name,
                                        int *name_len);

  /*
   * Tool MPI API
   */
  int A_MPI_T_init_thread (int required, int *provided);
  int A_MPI_T_finalize (void);
  int A_MPI_T_cvar_get_num (int *num_cvar);
  int A_MPI_T_cvar_get_info (int cvar_index, char *name, int *name_len,
                                        int *verbosity, A_MPI_Datatype *datatype,
                                        A_MPI_T_enum *enumtype, char *desc,
                                        int *desc_len, int *bind, int *scope);
  int A_MPI_T_cvar_get_index (char *name, int *cvar_index);
  int A_MPI_T_cvar_handle_alloc (int cvar_index, void *obj_handle,
                                            A_MPI_T_cvar_handle *handle, int *count);
  int A_MPI_T_cvar_handle_free (A_MPI_T_cvar_handle *handle);
  int A_MPI_T_cvar_read (A_MPI_T_cvar_handle handle, void *buf);
  int A_MPI_T_cvar_write (A_MPI_T_cvar_handle handle, void *buf);
  int A_MPI_T_category_get_num(int *num_cat);
  int A_MPI_T_category_get_info(int cat_index, char *name, int *name_len,
                                           char *desc, int *desc_len, int *num_cvars,
                                           int *num_pvars, int *num_categories);
  int A_MPI_T_category_get_index (char *name, int *category_index);
  int A_MPI_T_category_get_cvars(int cat_index, int len, int indices[]);
  int A_MPI_T_category_get_pvars(int cat_index, int len, int indices[]);
  int A_MPI_T_category_get_categories(int cat_index, int len, int indices[]);
  int A_MPI_T_category_changed(int *stamp);

  int A_MPI_T_pvar_get_num(int *num_pvar);
  int A_MPI_T_pvar_get_info(int pvar_index, char *name, int *name_len,
                                       int *verbosity, int *var_class, A_MPI_Datatype *datatype,
                                       A_MPI_T_enum *enumtype, char *desc, int *desc_len, int *bind,
                                       int *readonly, int *continuous, int *atomic);
  int A_MPI_T_pvar_get_index (char *name, int var_class, int *pvar_index);
  int A_MPI_T_pvar_session_create(A_MPI_T_pvar_session *session);
  int A_MPI_T_pvar_session_free(A_MPI_T_pvar_session *session);
  int A_MPI_T_pvar_handle_alloc(A_MPI_T_pvar_session session, int pvar_index,
                                           void *obj_handle, A_MPI_T_pvar_handle *handle, int *count);
  int A_MPI_T_pvar_handle_free(A_MPI_T_pvar_session session, A_MPI_T_pvar_handle *handle);
  int A_MPI_T_pvar_start(A_MPI_T_pvar_session session, A_MPI_T_pvar_handle handle);
  int A_MPI_T_pvar_stop(A_MPI_T_pvar_session session, A_MPI_T_pvar_handle handle);
  int A_MPI_T_pvar_read(A_MPI_T_pvar_session session, A_MPI_T_pvar_handle handle,
                                   void *buf);
  int A_MPI_T_pvar_write(A_MPI_T_pvar_session session, A_MPI_T_pvar_handle handle,
                                    void *buf);
  int A_MPI_T_pvar_reset(A_MPI_T_pvar_session session, A_MPI_T_pvar_handle handle);
  int A_MPI_T_pvar_readreset(A_MPI_T_pvar_session session, A_MPI_T_pvar_handle handle,
                                        void *buf);
  int A_MPI_T_enum_get_info(A_MPI_T_enum enumtype, int *num, char *name, int *name_len);
  int A_MPI_T_enum_get_item(A_MPI_T_enum enumtype, int index, int *value, char *name,
                                       int *name_len);

#endif /*CCC_MPI*/

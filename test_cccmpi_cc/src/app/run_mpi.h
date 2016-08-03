/* ompi/include/mpi.h.  Generated from mpi.h.in by configure.  */
/*
 * Copyright (c) 2004-2005 The Trustees of Indiana University and Indiana
 *                         University Research and Technology
 *                         Corporation.  All rights reserved.
 * Copyright (c) 2004-2010 The University of Tennessee and The University
 *                         of Tennessee Research Foundation.  All rights
 *                         reserved.
 * Copyright (c) 2004-2007 High Performance Computing Center Stuttgart,
 *                         University of Stuttgart.  All rights reserved.
 * Copyright (c) 2004-2005 The Regents of the University of California.
 *                         All rights reserved.
 * Copyright (c) 2007-2011 Cisco Systems, Inc.  All rights reserved.
 * Copyright (c) 2008-2009 Sun Microsystems, Inc.  All rights reserved.
 * Copyright (c) 2009      Oak Ridge National Labs.  All rights reserved.
 * $COPYRIGHT$
 *
 * Additional copyrights may follow
 *
 * $HEADER$
 */

#ifndef OMPI_R_MPI_H
#define OMPI_R_MPI_H

/* The comment below (and the ending partner) are for building fat
   distributions on platforms that support it.  Please do not remove */

/* @OMPI_BEGIN_CONFIGURE_SECTION@ */

#ifndef OMPI_CONFIG_H

/* Only include these if OMPI_CONFIG_H isn't defined (meaning if
   ompi_config.h hasn't already been included).  Otherwise, we'll
   duplicate all those symbols.  OMPI coding standards say that
   ompi_config.h must be included before all other files, so this
   should be good enough */

/* The compiler id which OMPI was built with */
#define OPAL_BUILD_PLATFORM_COMPILER_FAMILYID 1

/* The compiler version which OMPI was built with */
#define OPAL_BUILD_PLATFORM_COMPILER_VERSION 263175

/* Define to 1 if you have the ANSI C header files. */
#define OPAL_STDC_HEADERS 1

/* Whether your compiler has __attribute__ deprecated or not */
#define OPAL_HAVE_ATTRIBUTE_DEPRECATED 1

/* Whether your compiler has __attribute__ deprecated with the optional argument */
#define OPAL_HAVE_ATTRIBUTE_DEPRECATED_ARGUMENT 0

/* Define to 1 if you have the <sys/time.h> header file. */
#define OPAL_HAVE_SYS_TIME_H 1

/* Define to 1 if you have the <sys/synch.h> header file. */
/* #undef OPAL_HAVE_SYS_SYNCH_H */

/* Define to 1 if the system has the type `long long'. */
#define OPAL_HAVE_LONG_LONG 1

/* The size of a `bool', as computed by sizeof. */
/* #undef OPAL_SIZEOF_BOOL */

/* The size of a `int', as computed by sizeof. */
/* #undef OPAL_SIZEOF_INT */

/* Maximum length of datarep string (default is 128) */
#define OPAL_MAX_DATAREP_STRING 128

/* Maximum length of error strings (default is 256) */
#define OPAL_MAX_ERROR_STRING 256

/* Maximum length of info keys (default is 36) */
#define OPAL_MAX_INFO_KEY 36

/* Maximum length of info vals (default is 256) */
#define OPAL_MAX_INFO_VAL 256

/* Maximum length of object names (default is 64) */
#define OPAL_MAX_OBJECT_NAME 64

/* Maximum length of port names (default is 1024) */
#define OPAL_MAX_PORT_NAME 1024

/* Maximum length of processor names (default is 256) */
#define OPAL_MAX_PROCESSOR_NAME 256

/* Whether we have FORTRAN LOGICAL*1 or not */
#define OMPI_HAVE_FORTRAN_LOGICAL1 1

/* Whether we have FORTRAN LOGICAL*2 or not */
#define OMPI_HAVE_FORTRAN_LOGICAL2 1

/* Whether we have FORTRAN LOGICAL*4 or not */
#define OMPI_HAVE_FORTRAN_LOGICAL4 1

/* Whether we have FORTRAN LOGICAL*8 or not */
#define OMPI_HAVE_FORTRAN_LOGICAL8 1

/* Whether we have FORTRAN INTEGER*1 or not */
#define OMPI_HAVE_FORTRAN_INTEGER1 1

/* Whether we have FORTRAN INTEGER*16 or not */
#define OMPI_HAVE_FORTRAN_INTEGER16 0

/* Whether we have FORTRAN INTEGER*2 or not */
#define OMPI_HAVE_FORTRAN_INTEGER2 1

/* Whether we have FORTRAN INTEGER*4 or not */
#define OMPI_HAVE_FORTRAN_INTEGER4 1

/* Whether we have FORTRAN INTEGER*8 or not */
#define OMPI_HAVE_FORTRAN_INTEGER8 1

/* Whether we have FORTRAN REAL*16 or not */
#define OMPI_HAVE_FORTRAN_REAL16 1

/* Whether we have FORTRAN REAL*2 or not */
#define OMPI_HAVE_FORTRAN_REAL2 0

/* Whether we have FORTRAN REAL*4 or not */
#define OMPI_HAVE_FORTRAN_REAL4 1

/* Whether we have FORTRAN REAL*8 or not */
#define OMPI_HAVE_FORTRAN_REAL8 1

/* Whether we have float _Complex  or not */
#define HAVE_FLOAT__COMPLEX 1

/* Whether we have double _Complex  or not */
#define HAVE_DOUBLE__COMPLEX 1

/* Whether we have long double _Complex  or not */
#define HAVE_LONG_DOUBLE__COMPLEX 1

/* Type of R_MPI_Offset -- has to be defined here and typedef'ed later because mpi.h does not get AC SUBST's */
#define OMPI_R_MPI_OFFSET_TYPE long long

/* MPI datatype corresponding to R_MPI_Offset */
#define R_OMPI_OFFSET_DATATYPE R_MPI_LONG_LONG

/* Size of the R_MPI_Offset corresponding type */
#define OMPI_R_MPI_OFFSET_SIZE 8

/* type to use for ptrdiff_t, if it does not exist, set to ptrdiff_t if it does exist */
#define OPAL_PTRDIFF_TYPE ptrdiff_t

/* Whether we want MPI cxx support or not */
#define OMPI_WANT_CXX_BINDINGS 1

/* do we want to try to work around C++ bindings SEEK_* issue? */
#define OMPI_WANT_R_MPI_CXX_SEEK 1

/* Whether a const_cast on a 2-d array will work with the C++ compiler */
#define OMPI_CXX_SUPPORTS_2D_CONST_CAST 1

/* Whether we want the MPI f77 bindings or not */
#define OMPI_WANT_F77_BINDINGS 1

/* Whether we want the MPI f90 bindings or not */
#define OMPI_WANT_F90_BINDINGS 1

/* Enable warnings in wrong usage (e.g. deprecated) in user-level code */
/* XXX This __disabled__ by default for Open MPI-1.5, but will be __enabled__ for Open MPI-1.7 by default */
/* Users should be notified about this proposed change. */
#ifndef OMPI_WANT_R_MPI_INTERFACE_WARNING
#define OMPI_WANT_R_MPI_INTERFACE_WARNING 0
#endif

/* Whether or not we have compiled with C++ exceptions support */
#define OMPI_HAVE_CXX_EXCEPTION_SUPPORT 0

/* Major, minor, and release version of Open MPI */
#define OMPI_MAJOR_VERSION 1
#define OMPI_MINOR_VERSION 2
#define OMPI_RELEASE_VERSION 8

/* A  type that allows us to have sentinel type values that are still
   valid */
#define ompi_fortran_bogus_type_t int

/* C type corresponding to FORTRAN INTEGER */
#define ompi_fortran_integer_t int

/* Whether C compiler supports -fvisibility */
#define OPAL_C_HAVE_VISIBILITY 1

/* Whether OMPI should provide MPI File interface */
#define OMPI_PROVIDE_R_MPI_FILE_INTERFACE 1

#ifndef OMPI_DECLSPEC
#  if defined(WIN32) || defined(_WIN32)
#    if defined(OMPI_IMPORTS)
#      define OMPI_DECLSPEC        __declspec(dllimport)
#    else
#      define OMPI_DECLSPEC
#    endif  /* defined(OMPI_IMPORTS) */
#  else
#    if OPAL_C_HAVE_VISIBILITY == 1
#       define OMPI_DECLSPEC __attribute__((visibility("default")))
#    else
#       define OMPI_DECLSPEC
#    endif
#  endif
#endif

#ifndef R_MPI_Fint
/* R_MPI_Fint is the same as ompi_fortran_INTEGER_t */
#define R_MPI_Fint ompi_fortran_integer_t
#endif

#endif /* #ifndef OMPI_CONFIG_H */

/* @OMPI_END_CONFIGURE_SECTION@ */

/* include for ptrdiff_t */
#ifdef OPAL_STDC_HEADERS
#include <stddef.h>
#endif

#ifndef OMPI_BUILDING
#define OMPI_BUILDING 0
#endif


/*
 * Just in case you need it.  :-)
 */
#define OPEN_MPI 1

/*
 * MPI version
 */
#define R_MPI_VERSION 2
#define R_MPI_SUBVERSION 1


/*
 * Do we want MPI interface deprecated function warnings?  This is
 * only relevant if we're not building Open MPI (i.e., we're compiling an
 * MPI application).
 */
#if !(OMPI_BUILDING || \
      (defined(OMPI_BUILDING_CXX_BINDINGS_LIBRARY) && \
       OMPI_BUILDING_CXX_BINDINGS_LIBRARY))

     /*
      * Figure out which compiler is being invoked (in order to compare if
      * it was different than what OMPI was built with).
      */
//#    include "mpi_portable_platform.h"

     /*
      * If we're currently using the same compiler that was used to
      * build Open MPI, enable compile-time warning of user-level code
      * (e.g. usage of deprecated functions).
      */
#    if (OPAL_BUILD_PLATFORM_COMPILER_FAMILYID == PLATFORM_COMPILER_FAMILYID) && \
        (OPAL_BUILD_PLATFORM_COMPILER_VERSION == PLATFORM_COMPILER_VERSION)

#        if OMPI_WANT_R_MPI_INTERFACE_WARNING
#            if OPAL_HAVE_ATTRIBUTE_DEPRECATED
#                if OPAL_HAVE_ATTRIBUTE_DEPRECATED_ARGUMENT
#                    define __mpi_interface_deprecated__(msg) __attribute__((__deprecated__(msg)))
#                else
#                    define __mpi_interface_deprecated__(msg) __attribute__((__deprecated__))
#                endif
#            endif
#        endif
#    endif
#endif

/*
 * If we didn't define __mpi_interface_deprecated__ above, then we
 * don't want it, so define it to empty (can't use #undef in the logic
 * above because autoconf will comment it out).
 */
#if !defined(__mpi_interface_deprecated__)
#    define __mpi_interface_deprecated__(msg)
#endif

/*
 * To accomodate programs written for MPI implementations that use a
 * straight ROMIO import
 */
#if !OMPI_BUILDING && OMPI_PROVIDE_R_MPI_FILE_INTERFACE
#define R_MPIO_Request R_MPI_Request
#define R_MPIO_Test R_MPI_Test
#define R_MPIO_Wait R_MPI_Wait
#endif

/*
 * When initializing global pointers to Open MPI internally-defined
 * structs, some compilers warn about type-punning to incomplete
 * types.  Therefore, when full struct definitions are unavailable
 * (when not building Open MPI), cast to an opaque (void *) pointer to
 * disable any strict-aliasing optimizations.  Don't cast to (void *)
 * when building Open MPI so that we actually get the benefit of type
 * checking (because we *do* have the full type definitions available
 * when building OMPI).
 */
#if !OMPI_BUILDING
#define OMPI_PREDEFINED_GLOBAL(type, global) ((type) ((void *) &(global)))
#else
#define OMPI_PREDEFINED_GLOBAL(type, global) ((type) &(global))
#endif

#if defined(c_plusplus) || defined(__cplusplus)
extern "C" {
#endif
/*
 * Typedefs
 */

typedef OPAL_PTRDIFF_TYPE R_MPI_Aint;
typedef OMPI_R_MPI_OFFSET_TYPE R_MPI_Offset;
typedef struct ompi_communicator_t *R_MPI_Comm;
typedef struct ompi_datatype_t *R_MPI_Datatype;
typedef struct ompi_errhandler_t *R_MPI_Errhandler;
#if OMPI_PROVIDE_R_MPI_FILE_INTERFACE
typedef struct ompi_file_t *R_MPI_File;
#endif
typedef struct ompi_group_t *R_MPI_Group;
typedef struct ompi_info_t *R_MPI_Info;
typedef struct ompi_op_t *R_MPI_Op;
typedef struct ompi_request_t *R_MPI_Request;
typedef struct r_ompi_status_public_t R_MPI_Status;
typedef struct ompi_win_t *R_MPI_Win;

/*
 * R_MPI_Status
 */
struct r_ompi_status_public_t {
    /* These fields are publicly defined in the MPI specification.
       User applications may freely read from these fields. */
    int R_MPI_SOURCE;
    int R_MPI_TAG;
    int R_MPI_ERROR;
    /* The following two fields are internal to the Open MPI
       implementation and should not be accessed by MPI applications.
       They are subject to change at any time.  These are not the
       droids you're looking for. */
    int _cancelled;
    size_t _ucount;
};
typedef struct r_ompi_status_public_t r_ompi_status_public_t;

/*
 * User typedefs
 *
 * Even though R_MPI_Copy_function and R_MPI_Delete_function are
 * deprecated, we do not use the attributes marking them as such,
 * because otherwise the compiler will warn for all the functions that
 * are declared using them (e.g., R_MPI_Keyval_create).
 */
typedef int (R_MPI_Copy_function)(R_MPI_Comm, int, void *,
                                void *, void *, int *);
typedef int (R_MPI_Delete_function)(R_MPI_Comm, int, void *, void *);
typedef int (R_MPI_Datarep_extent_function)(R_MPI_Datatype, R_MPI_Aint *, void *);
typedef int (R_MPI_Datarep_conversion_function)(void *, R_MPI_Datatype,
                                              int, void *, R_MPI_Offset, void *);
typedef void (R_MPI_Comm_errhandler_function)(R_MPI_Comm *, int *, ...);
typedef R_MPI_Comm_errhandler_function R_MPI_Comm_errhandler_fn
        __mpi_interface_deprecated__("R_MPI_Comm_errhandler_fn was deprecated in MPI-2.2; use R_MPI_Comm_errhandler_function instead");

#if OMPI_PROVIDE_R_MPI_FILE_INTERFACE
    /* This is a little hackish, but errhandler.h needs space for a
       R_MPI_File_errhandler_fn.  While it could just be removed, this
       allows us to maintain a stable ABI within OMPI, at least for
       apps that don't use MPI I/O. */
typedef void (ompi_file_errhandler_fn)(R_MPI_File *, int *, ...);
typedef ompi_file_errhandler_fn R_MPI_File_errhandler_fn
        __mpi_interface_deprecated__("R_MPI_File_errhandler_fn was deprecated in MPI-2.2; use R_MPI_File_errhandler_function instead");
typedef ompi_file_errhandler_fn R_MPI_File_errhandler_function;
#else
struct ompi_file_t;
typedef void (ompi_file_errhandler_fn)(struct ompi_file_t**, int *, ...);
#endif
typedef void (R_MPI_Win_errhandler_function)(R_MPI_Win *, int *, ...);
typedef R_MPI_Win_errhandler_function R_MPI_Win_errhandler_fn
        __mpi_interface_deprecated__("R_MPI_Win_errhandler_fn was deprecated in MPI-2.2; use R_MPI_Win_errhandler_function instead");
    /* R_MPI_Handler_function is deprecated, but we don't mark it as
       such because otherwise the R_MPI_Errhandler_create() declaration
       would cause a warning to be issued */
typedef void (R_MPI_Handler_function)(R_MPI_Comm *, int *, ...);
typedef void (R_MPI_User_function)(void *, void *, int *, R_MPI_Datatype *);
typedef int (R_MPI_Comm_copy_attr_function)(R_MPI_Comm, int, void *,
                                            void *, void *, int *);
typedef int (R_MPI_Comm_delete_attr_function)(R_MPI_Comm, int, void *, void *);
typedef int (R_MPI_Type_copy_attr_function)(R_MPI_Datatype, int, void *,
                                            void *, void *, int *);
typedef int (R_MPI_Type_delete_attr_function)(R_MPI_Datatype, int,
                                              void *, void *);
typedef int (R_MPI_Win_copy_attr_function)(R_MPI_Win, int, void *,
                                           void *, void *, int *);
typedef int (R_MPI_Win_delete_attr_function)(R_MPI_Win, int, void *, void *);
typedef int (R_MPI_Grequest_query_function)(void *, R_MPI_Status *);
typedef int (R_MPI_Grequest_free_function)(void *);
typedef int (R_MPI_Grequest_cancel_function)(void *, int);

/*
 * Miscellaneous constants
 */
#define R_MPI_ANY_SOURCE         -1                      /* match any source rank */
#define R_MPI_PROC_NULL          -2                      /* rank of null process */
#define R_MPI_ROOT               -4                      /* special value for intercomms */
#define R_MPI_ANY_TAG            -1                      /* match any message tag */
#define R_MPI_MAX_PROCESSOR_NAME OPAL_MAX_PROCESSOR_NAME /* max proc. name length */
#define R_MPI_MAX_ERROR_STRING   OPAL_MAX_ERROR_STRING   /* max error message length */
#define R_MPI_MAX_OBJECT_NAME    OPAL_MAX_OBJECT_NAME    /* max object name length */
#define R_MPI_UNDEFINED          -32766                  /* undefined stuff */
#define R_MPI_CART               1                       /* cartesian topology */
#define R_MPI_GRAPH              2                       /* graph topology */
#define R_MPI_KEYVAL_INVALID     -1                      /* invalid key value */

/*
 * More constants
 */
#define R_MPI_BOTTOM               ((void *) 0)          /* base reference address */
#define R_MPI_IN_PLACE             ((void *) 1)          /* in place buffer */
#define R_MPI_BSEND_OVERHEAD       128                   /* size of bsend header + ptr */
#define R_MPI_MAX_INFO_KEY         OPAL_MAX_INFO_KEY     /* max info key length */
#define R_MPI_MAX_INFO_VAL         OPAL_MAX_INFO_VAL     /* max info value length */
#define R_MPI_ARGV_NULL            ((char **) 0)         /* NULL argument vector */
#define R_MPI_ARGVS_NULL           ((char ***) 0)        /* NULL argument vectors */
#define R_MPI_ERRCODES_IGNORE      ((int *) 0)           /* don't return error codes */
#define R_MPI_MAX_PORT_NAME        OPAL_MAX_PORT_NAME    /* max port name length */
#define R_MPI_MAX_NAME_LEN         R_MPI_MAX_PORT_NAME     /* max port name length, non-std. (LAM < 6.3b1) */
#define R_MPI_ORDER_C              0                     /* C row major order */
#define R_MPI_ORDER_FORTRAN        1                     /* Fortran column major order */
#define R_MPI_DISTRIBUTE_BLOCK     0                     /* block distribution */
#define R_MPI_DISTRIBUTE_CYCLIC    1                     /* cyclic distribution */
#define R_MPI_DISTRIBUTE_NONE      2                     /* not distributed */
#define R_MPI_DISTRIBUTE_DFLT_DARG (-1)                  /* default distribution arg */

#if OMPI_PROVIDE_R_MPI_FILE_INTERFACE
/*
 * Since these values are arbitrary to Open MPI, we might as well make
 * them the same as ROMIO for ease of mapping.  These values taken
 * from ROMIO's mpio.h file.
 */
#define R_MPI_MODE_CREATE              1  /* ADIO_CREATE */
#define R_MPI_MODE_RDONLY              2  /* ADIO_RDONLY */
#define R_MPI_MODE_WRONLY              4  /* ADIO_WRONLY  */
#define R_MPI_MODE_RDWR                8  /* ADIO_RDWR  */
#define R_MPI_MODE_DELETE_ON_CLOSE    16  /* ADIO_DELETE_ON_CLOSE */
#define R_MPI_MODE_UNIQUE_OPEN        32  /* ADIO_UNIQUE_OPEN */
#define R_MPI_MODE_EXCL               64  /* ADIO_EXCL */
#define R_MPI_MODE_APPEND            128  /* ADIO_APPEND */
#define R_MPI_MODE_SEQUENTIAL        256  /* ADIO_SEQUENTIAL */

#define R_MPI_DISPLACEMENT_CURRENT   -54278278

#define R_MPI_SEEK_SET               600
#define R_MPI_SEEK_CUR               602
#define R_MPI_SEEK_END               604

/* Max data representation length */
#define R_MPI_MAX_DATAREP_STRING OPAL_MAX_DATAREP_STRING 

#endif /* #if OMPI_PROVIDE_R_MPI_FILE_INTERFACE */

/*
 * MPI-2 One-Sided Communications asserts
 */
#define R_MPI_MODE_NOCHECK             1
#define R_MPI_MODE_NOPRECEDE           2
#define R_MPI_MODE_NOPUT               4
#define R_MPI_MODE_NOSTORE             8
#define R_MPI_MODE_NOSUCCEED          16

#define R_MPI_LOCK_EXCLUSIVE           1
#define R_MPI_LOCK_SHARED              2


/*
 * Predefined attribute keyvals
 *
 * DO NOT CHANGE THE ORDER WITHOUT ALSO CHANGING THE ORDER IN
 * src/attribute/attribute_predefined.c and mpif.h.in.
 */
enum {
    /* MPI-1 */
    R_MPI_TAG_UB,
    R_MPI_HOST,
    R_MPI_IO,
    R_MPI_WTIME_IS_GLOBAL,

    /* MPI-2 */
    R_MPI_APPNUM,
    R_MPI_LASTUSEDCODE,
    R_MPI_UNIVERSE_SIZE,
    R_MPI_WIN_BASE,
    R_MPI_WIN_SIZE,
    R_MPI_WIN_DISP_UNIT,

    /* Even though these four are IMPI attributes, they need to be there
       for all MPI jobs */
    IR_MPI_CLIENT_SIZE,
    IR_MPI_CLIENT_COLOR,
    IR_MPI_HOST_SIZE,
    IR_MPI_HOST_COLOR
};

/*
 * Error classes and codes
 * Do not change the values of these without also modifying mpif.h.in.
 */
#define R_MPI_SUCCESS                   0
#define R_MPI_ERR_BUFFER                1
#define R_MPI_ERR_COUNT                 2
#define R_MPI_ERR_TYPE                  3
#define R_MPI_ERR_TAG                   4
#define R_MPI_ERR_COMM                  5
#define R_MPI_ERR_RANK                  6
#define R_MPI_ERR_REQUEST               7
#define R_MPI_ERR_ROOT                  8
#define R_MPI_ERR_GROUP                 9
#define R_MPI_ERR_OP                    10
#define R_MPI_ERR_TOPOLOGY              11
#define R_MPI_ERR_DIMS                  12
#define R_MPI_ERR_ARG                   13
#define R_MPI_ERR_UNKNOWN               14
#define R_MPI_ERR_TRUNCATE              15
#define R_MPI_ERR_OTHER                 16
#define R_MPI_ERR_INTERN                17
#define R_MPI_ERR_IN_STATUS             18
#define R_MPI_ERR_PENDING               19
#define R_MPI_ERR_ACCESS                20
#define R_MPI_ERR_AMODE                 21
#define R_MPI_ERR_ASSERT                22
#define R_MPI_ERR_BAD_FILE              23
#define R_MPI_ERR_BASE                  24
#define R_MPI_ERR_CONVERSION            25
#define R_MPI_ERR_DISP                  26
#define R_MPI_ERR_DUP_DATAREP           27
#define R_MPI_ERR_FILE_EXISTS           28
#define R_MPI_ERR_FILE_IN_USE           29
#define R_MPI_ERR_FILE                  30
#define R_MPI_ERR_INFO_KEY              31
#define R_MPI_ERR_INFO_NOKEY            32
#define R_MPI_ERR_INFO_VALUE            33
#define R_MPI_ERR_INFO                  34
#define R_MPI_ERR_IO                    35
#define R_MPI_ERR_KEYVAL                36
#define R_MPI_ERR_LOCKTYPE              37
#define R_MPI_ERR_NAME                  38
#define R_MPI_ERR_NO_MEM                39
#define R_MPI_ERR_NOT_SAME              40
#define R_MPI_ERR_NO_SPACE              41
#define R_MPI_ERR_NO_SUCH_FILE          42
#define R_MPI_ERR_PORT                  43
#define R_MPI_ERR_QUOTA                 44
#define R_MPI_ERR_READ_ONLY             45
#define R_MPI_ERR_RMA_CONFLICT          46
#define R_MPI_ERR_RMA_SYNC              47
#define R_MPI_ERR_SERVICE               48
#define R_MPI_ERR_SIZE                  49
#define R_MPI_ERR_SPAWN                 50
#define R_MPI_ERR_UNSUPPORTED_DATAREP   51
#define R_MPI_ERR_UNSUPPORTED_OPERATION 52
#define R_MPI_ERR_WIN                   53
#define R_MPI_ERR_LASTCODE              54

#define R_MPI_ERR_SYSRESOURCE          -2


/*
 * Comparison results.  Don't change the order of these, the group
 * comparison functions rely on it.
 * Do not change the order of these without also modifying mpif.h.in.
 */
enum {
  R_MPI_IDENT,
  R_MPI_CONGRUENT,
  R_MPI_SIMILAR,
  R_MPI_UNEQUAL
};

/*
 * R_MPI_Init_thread constants
 * Do not change the order of these without also modifying mpif.h.in.
 */
enum {
  R_MPI_THREAD_SINGLE,
  R_MPI_THREAD_FUNNELED,
  R_MPI_THREAD_SERIALIZED,
  R_MPI_THREAD_MULTIPLE
};

/*
 * Datatype combiners.
 * Do not change the order of these without also modifying mpif.h.in.
 */
enum {
  R_MPI_COMBINER_NAMED,
  R_MPI_COMBINER_DUP,
  R_MPI_COMBINER_CONTIGUOUS,
  R_MPI_COMBINER_VECTOR,
  R_MPI_COMBINER_HVECTOR_INTEGER,
  R_MPI_COMBINER_HVECTOR,
  R_MPI_COMBINER_INDEXED,
  R_MPI_COMBINER_HINDEXED_INTEGER,
  R_MPI_COMBINER_HINDEXED,
  R_MPI_COMBINER_INDEXED_BLOCK,
  R_MPI_COMBINER_STRUCT_INTEGER,
  R_MPI_COMBINER_STRUCT,
  R_MPI_COMBINER_SUBARRAY,
  R_MPI_COMBINER_DARRAY,
  R_MPI_COMBINER_F90_REAL,
  R_MPI_COMBINER_F90_COMPLEX,
  R_MPI_COMBINER_F90_INTEGER,
  R_MPI_COMBINER_RESIZED
};

/*
 * NULL handles
 */
#define R_MPI_GROUP_NULL OMPI_PREDEFINED_GLOBAL(R_MPI_Group, ompi_mpi_group_null)
#define R_MPI_COMM_NULL OMPI_PREDEFINED_GLOBAL(R_MPI_Comm, ompi_mpi_comm_null)
#define R_MPI_REQUEST_NULL OMPI_PREDEFINED_GLOBAL(R_MPI_Request, ompi_request_null)
#define R_MPI_OP_NULL OMPI_PREDEFINED_GLOBAL(R_MPI_Op, ompi_mpi_op_null)
#define R_MPI_ERRHANDLER_NULL OMPI_PREDEFINED_GLOBAL(R_MPI_Errhandler, ompi_mpi_errhandler_null)
#define R_MPI_INFO_NULL OMPI_PREDEFINED_GLOBAL(R_MPI_Info, ompi_mpi_info_null)
#define R_MPI_WIN_NULL OMPI_PREDEFINED_GLOBAL(R_MPI_Win, ompi_mpi_win_null)
#if OMPI_PROVIDE_R_MPI_FILE_INTERFACE
#define R_MPI_FILE_NULL OMPI_PREDEFINED_GLOBAL(R_MPI_File, ompi_mpi_file_null)
#endif

#define R_MPI_STATUS_IGNORE ((R_MPI_Status *) 0)
#define R_MPI_STATUSES_IGNORE ((R_MPI_Status *) 0)

/* MPI-2 specifies that the name "R_MPI_TYPE_NULL_DELETE_FN" (and all
   related friends) must be accessible in C, C++, and Fortran. This is
   unworkable if the back-end Fortran compiler uses all caps for its
   linker symbol convention -- it results in two functions with
   different signatures that have the same name (i.e., both C and
   Fortran use the symbol R_MPI_TYPE_NULL_DELETE_FN).  So we have to
   #define the C names to be something else, so that they names are
   *accessed* through R_MPI_TYPE_NULL_DELETE_FN, but their actual symbol
   name is different.

   However, this file is included when the fortran wrapper functions
   are compiled in Open MPI, so we do *not* want these #defines in
   this case (i.e., we need the Fortran wrapper function to be
   compiled as R_MPI_TYPE_NULL_DELETE_FN).  So add some #if kinds of
   protection for this case. */

#if !defined(OMPI_COMPILING_F77_WRAPPERS)
#define R_MPI_NULL_DELETE_FN OMPI_C_MPI_NULL_DELETE_FN
#define R_MPI_NULL_COPY_FN OMPI_C_MPI_NULL_COPY_FN
#define R_MPI_DUP_FN OMPI_C_MPI_DUP_FN

#define R_MPI_TYPE_NULL_DELETE_FN OMPI_C_MPI_TYPE_NULL_DELETE_FN
#define R_MPI_TYPE_NULL_COPY_FN OMPI_C_MPI_TYPE_NULL_COPY_FN
#define R_MPI_TYPE_DUP_FN OMPI_C_MPI_TYPE_DUP_FN

#define R_MPI_COMM_NULL_DELETE_FN OMPI_C_MPI_COMM_NULL_DELETE_FN
#define R_MPI_COMM_NULL_COPY_FN OMPI_C_MPI_COMM_NULL_COPY_FN
#define R_MPI_COMM_DUP_FN OMPI_C_MPI_COMM_DUP_FN

#define R_MPI_WIN_NULL_DELETE_FN OMPI_C_MPI_WIN_NULL_DELETE_FN
#define R_MPI_WIN_NULL_COPY_FN OMPI_C_MPI_WIN_NULL_COPY_FN
#define R_MPI_WIN_DUP_FN OMPI_C_MPI_WIN_DUP_FN

/* R_MPI_CONVERSION_FN_NULL is a sentinel value, but it has to be large
   enough to be the same size as a valid function pointer.  It
   therefore shares many characteristics between Fortran constants and
   Fortran sentinel functions.  For example, it shares the problem of
   having Fortran compilers have all-caps versions of the symbols that
   must be able to be present, and therefore has to be in this
   conditional block in mpi.h. */
#define R_MPI_CONVERSION_FN_NULL ((R_MPI_Datarep_conversion_function*) 0)
#endif

OMPI_DECLSPEC int OMPI_C_MPI_TYPE_NULL_DELETE_FN( R_MPI_Datatype datatype,
                                                int type_keyval,
                                                void* attribute_val_out,
                                                void* extra_state );
OMPI_DECLSPEC int OMPI_C_MPI_TYPE_NULL_COPY_FN( R_MPI_Datatype datatype,
                                              int type_keyval,
                                              void* extra_state,
                                              void* attribute_val_in,
                                              void* attribute_val_out,
                                              int* flag );
OMPI_DECLSPEC int OMPI_C_MPI_TYPE_DUP_FN( R_MPI_Datatype datatype,
                                        int type_keyval,
                                        void* extra_state,
                                        void* attribute_val_in,
                                        void* attribute_val_out,
                                        int* flag );
OMPI_DECLSPEC int OMPI_C_MPI_COMM_NULL_DELETE_FN( R_MPI_Comm comm,
                                                int comm_keyval,
                                                void* attribute_val_out,
                                                void* extra_state );
OMPI_DECLSPEC int OMPI_C_MPI_COMM_NULL_COPY_FN( R_MPI_Comm comm,
                                              int comm_keyval,
                                              void* extra_state,
                                              void* attribute_val_in,
                                              void* attribute_val_out,
                                              int* flag );
OMPI_DECLSPEC int OMPI_C_MPI_COMM_DUP_FN( R_MPI_Comm comm, int comm_keyval,
                                        void* extra_state,
                                        void* attribute_val_in,
                                        void* attribute_val_out,
                                        int* flag );
OMPI_DECLSPEC int OMPI_C_MPI_NULL_DELETE_FN( R_MPI_Comm comm, int comm_keyval,
                                           void* attribute_val_out,
                                           void* extra_state )
                                           __mpi_interface_deprecated__("R_MPI_NULL_DELETE_FN is deprecated in MPI-2.0");
OMPI_DECLSPEC int OMPI_C_MPI_NULL_COPY_FN( R_MPI_Comm comm, int comm_keyval,
                                         void* extra_state,
                                         void* attribute_val_in,
                                         void* attribute_val_out,
                                         int* flag )
                                         __mpi_interface_deprecated__("R_MPI_NULL_COPY_FN is deprecated in MPI-2.0");
OMPI_DECLSPEC int OMPI_C_MPI_DUP_FN( R_MPI_Comm comm, int comm_keyval,
                                   void* extra_state,
                                   void* attribute_val_in,
                                   void* attribute_val_out,
                                   int* flag )
                                   __mpi_interface_deprecated__("R_MPI_DUP_FN is deprecated in MPI-2.0");
OMPI_DECLSPEC int OMPI_C_MPI_WIN_NULL_DELETE_FN( R_MPI_Win window,
                                               int win_keyval,
                                               void* attribute_val_out,
                                               void* extra_state );
OMPI_DECLSPEC int OMPI_C_MPI_WIN_NULL_COPY_FN( R_MPI_Win window, int win_keyval,
                                             void* extra_state,
                                             void* attribute_val_in,
                                             void* attribute_val_out,
                                             int* flag );
OMPI_DECLSPEC int OMPI_C_MPI_WIN_DUP_FN( R_MPI_Win window, int win_keyval,
                                         void* extra_state,
                                         void* attribute_val_in,
                                         void* attribute_val_out,
                                         int* flag );

/*
 * External variables
 *
 * The below externs use the ompi_predefined_xxx_t structures to maintain
 * back compatibility between MPI library versions.
 * See ompi/communicator/communicator.h comments with struct ompi_communicator_t
 * for full explanation why we chose to use the ompi_predefined_xxx_t structure.
 */
OMPI_DECLSPEC extern struct ompi_predefined_communicator_t ompi_mpi_comm_world;
OMPI_DECLSPEC extern struct ompi_predefined_communicator_t ompi_mpi_comm_self;
OMPI_DECLSPEC extern struct ompi_predefined_communicator_t ompi_mpi_comm_null;

OMPI_DECLSPEC extern struct ompi_predefined_group_t ompi_mpi_group_empty;
OMPI_DECLSPEC extern struct ompi_predefined_group_t ompi_mpi_group_null;

OMPI_DECLSPEC extern struct ompi_predefined_request_t ompi_request_null;

OMPI_DECLSPEC extern struct ompi_predefined_op_t ompi_mpi_op_null;
OMPI_DECLSPEC extern struct ompi_predefined_op_t ompi_mpi_op_min;
OMPI_DECLSPEC extern struct ompi_predefined_op_t ompi_mpi_op_max;
OMPI_DECLSPEC extern struct ompi_predefined_op_t ompi_mpi_op_sum;
OMPI_DECLSPEC extern struct ompi_predefined_op_t ompi_mpi_op_prod;
OMPI_DECLSPEC extern struct ompi_predefined_op_t ompi_mpi_op_land;
OMPI_DECLSPEC extern struct ompi_predefined_op_t ompi_mpi_op_band;
OMPI_DECLSPEC extern struct ompi_predefined_op_t ompi_mpi_op_lor;
OMPI_DECLSPEC extern struct ompi_predefined_op_t ompi_mpi_op_bor;
OMPI_DECLSPEC extern struct ompi_predefined_op_t ompi_mpi_op_lxor;
OMPI_DECLSPEC extern struct ompi_predefined_op_t ompi_mpi_op_bxor;
OMPI_DECLSPEC extern struct ompi_predefined_op_t ompi_mpi_op_maxloc;
OMPI_DECLSPEC extern struct ompi_predefined_op_t ompi_mpi_op_minloc;
OMPI_DECLSPEC extern struct ompi_predefined_op_t ompi_mpi_op_replace;


OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_datatype_null;

OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_lb __mpi_interface_deprecated__("R_MPI_LB is deprecated in MPI-2.0");
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_ub __mpi_interface_deprecated__("R_MPI_UB is deprecated in MPI-2.0");
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_char;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_signed_char;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_unsigned_char;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_byte;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_short;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_unsigned_short;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_int;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_unsigned;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_long;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_unsigned_long;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_long_long_int;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_unsigned_long_long;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_float;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_double;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_long_double;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_wchar;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_packed;

/*
 * Following are the C++/C99 datatypes
 */
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_cxx_bool;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_cxx_cplex;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_cxx_dblcplex;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_cxx_ldblcplex;

/*
 * Following are the Fortran datatypes
 */
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_logical;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_character;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_integer;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_real;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_dblprec;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_cplex;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_dblcplex;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_ldblcplex;

/* Aggregate struct datatypes are not const */
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_2int;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_2integer;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_2real;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_2dblprec;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_2cplex;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_2dblcplex;

OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_float_int;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_double_int;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_longdbl_int;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_short_int;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_long_int;

/* Optional MPI2 datatypes, always declared and defined, but not "exported" as R_MPI_LOGICAL1 */
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_logical1;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_logical2;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_logical4;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_logical8;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_integer1;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_integer2;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_integer4;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_integer8;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_integer16;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_real2;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_real4;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_real8;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_real16;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_complex8;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_complex16;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_complex32;

/* New datatypes from the MPI 2.2 standard */
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_int8_t;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_uint8_t;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_int16_t;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_uint16_t;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_int32_t;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_uint32_t;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_int64_t;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_uint64_t;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_aint;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_offset;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_c_bool;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_c_complex;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_c_float_complex;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_c_double_complex;
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_c_long_double_complex;

OMPI_DECLSPEC extern struct ompi_predefined_errhandler_t ompi_mpi_errhandler_null;
OMPI_DECLSPEC extern struct ompi_predefined_errhandler_t ompi_mpi_errors_are_fatal;
OMPI_DECLSPEC extern struct ompi_predefined_errhandler_t ompi_mpi_errors_return;

OMPI_DECLSPEC extern struct ompi_predefined_win_t ompi_mpi_win_null;
OMPI_DECLSPEC extern struct ompi_predefined_file_t ompi_mpi_file_null;

OMPI_DECLSPEC extern struct ompi_predefined_info_t ompi_mpi_info_null;

OMPI_DECLSPEC extern R_MPI_Fint *R_MPI_F_STATUS_IGNORE;
OMPI_DECLSPEC extern R_MPI_Fint *R_MPI_F_STATUSES_IGNORE;

/*
 * MPI predefined handles
 */
#define R_MPI_COMM_WORLD OMPI_PREDEFINED_GLOBAL( R_MPI_Comm, ompi_mpi_comm_world)
#define R_MPI_COMM_SELF OMPI_PREDEFINED_GLOBAL(R_MPI_Comm, ompi_mpi_comm_self)

#define R_MPI_GROUP_EMPTY OMPI_PREDEFINED_GLOBAL(R_MPI_Group, ompi_mpi_group_empty)

#define R_MPI_MAX OMPI_PREDEFINED_GLOBAL(R_MPI_Op, ompi_mpi_op_max)
#define R_MPI_MIN OMPI_PREDEFINED_GLOBAL(R_MPI_Op, ompi_mpi_op_min)
#define R_MPI_SUM OMPI_PREDEFINED_GLOBAL(R_MPI_Op, ompi_mpi_op_sum)
#define R_MPI_PROD OMPI_PREDEFINED_GLOBAL(R_MPI_Op, ompi_mpi_op_prod)
#define R_MPI_LAND OMPI_PREDEFINED_GLOBAL(R_MPI_Op, ompi_mpi_op_land)
#define R_MPI_BAND OMPI_PREDEFINED_GLOBAL(R_MPI_Op, ompi_mpi_op_band)
#define R_MPI_LOR OMPI_PREDEFINED_GLOBAL(R_MPI_Op, ompi_mpi_op_lor)
#define R_MPI_BOR OMPI_PREDEFINED_GLOBAL(R_MPI_Op, ompi_mpi_op_bor)
#define R_MPI_LXOR OMPI_PREDEFINED_GLOBAL(R_MPI_Op, ompi_mpi_op_lxor)
#define R_MPI_BXOR OMPI_PREDEFINED_GLOBAL(R_MPI_Op, ompi_mpi_op_bxor)
#define R_MPI_MAXLOC OMPI_PREDEFINED_GLOBAL(R_MPI_Op, ompi_mpi_op_maxloc)
#define R_MPI_MINLOC OMPI_PREDEFINED_GLOBAL(R_MPI_Op, ompi_mpi_op_minloc)
#define R_MPI_REPLACE OMPI_PREDEFINED_GLOBAL(R_MPI_Op, ompi_mpi_op_replace)

/* C datatypes */
#define R_MPI_DATATYPE_NULL OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_datatype_null)
#define R_MPI_BYTE OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_byte)
#define R_MPI_PACKED OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_packed)
#define R_MPI_CHAR OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_char)
#define R_MPI_SHORT OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_short)
#define R_MPI_INT OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_int)
#define R_MPI_LONG OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_long)
#define R_MPI_FLOAT OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_float)
#define R_MPI_DOUBLE OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_double)
#define R_MPI_LONG_DOUBLE OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_long_double)
#define R_MPI_UNSIGNED_CHAR OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_unsigned_char)
#define R_MPI_SIGNED_CHAR OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_signed_char)
#define R_MPI_UNSIGNED_SHORT OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_unsigned_short)
#define R_MPI_UNSIGNED_LONG OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_unsigned_long)
#define R_MPI_UNSIGNED OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_unsigned)
#define R_MPI_FLOAT_INT OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_float_int)
#define R_MPI_DOUBLE_INT OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_double_int)
#define R_MPI_LONG_DOUBLE_INT OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_longdbl_int)
#define R_MPI_LONG_INT OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_long_int)
#define R_MPI_SHORT_INT OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_short_int)
#define R_MPI_2INT OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_2int)
#define R_MPI_UB OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_ub)
#define R_MPI_LB OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_lb)
#define R_MPI_WCHAR OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_wchar)
#if OPAL_HAVE_LONG_LONG
#define R_MPI_LONG_LONG_INT OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_long_long_int)
#define R_MPI_LONG_LONG OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_long_long_int)
#define R_MPI_UNSIGNED_LONG_LONG OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_unsigned_long_long)
#endif  /* OPAL_HAVE_LONG_LONG */
#define R_MPI_2COMPLEX OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_2cplex)
#define R_MPI_2DOUBLE_COMPLEX OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_2dblcplex)

/* Fortran datatype bindings */
#define R_MPI_CHARACTER OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_character)
#define R_MPI_LOGICAL OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_logical)
#if OMPI_HAVE_FORTRAN_LOGICAL1
#define R_MPI_LOGICAL1 OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_logical1)
#endif
#if OMPI_HAVE_FORTRAN_LOGICAL2
#define R_MPI_LOGICAL2 OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_logical2)
#endif
#if OMPI_HAVE_FORTRAN_LOGICAL4
#define R_MPI_LOGICAL4 OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_logical4)
#endif
#if OMPI_HAVE_FORTRAN_LOGICAL8
#define R_MPI_LOGICAL8 OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_logical8)
#endif
#define R_MPI_INTEGER OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_integer)
#if OMPI_HAVE_FORTRAN_INTEGER1
#define R_MPI_INTEGER1 OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_integer1)
#endif
#if OMPI_HAVE_FORTRAN_INTEGER2
#define R_MPI_INTEGER2 OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_integer2)
#endif
#if OMPI_HAVE_FORTRAN_INTEGER4
#define R_MPI_INTEGER4 OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_integer4)
#endif
#if OMPI_HAVE_FORTRAN_INTEGER8
#define R_MPI_INTEGER8 OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_integer8)
#endif
#if OMPI_HAVE_FORTRAN_INTEGER16
#define R_MPI_INTEGER16 OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_integer16)
#endif
#define R_MPI_REAL OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_real)
#if OMPI_HAVE_FORTRAN_REAL4
#define R_MPI_REAL4 OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_real4)
#endif
#if OMPI_HAVE_FORTRAN_REAL8
#define R_MPI_REAL8 OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_real8)
#endif
#if OMPI_HAVE_FORTRAN_REAL16
#define R_MPI_REAL16 OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_real16)
#endif
#define R_MPI_DOUBLE_PRECISION OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_dblprec)
#define R_MPI_COMPLEX OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_cplex)
#if OMPI_HAVE_FORTRAN_REAL4
#define R_MPI_COMPLEX8 OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_complex8)
#endif
#if OMPI_HAVE_FORTRAN_REAL8
#define R_MPI_COMPLEX16 OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_complex16)
#endif
#if OMPI_HAVE_FORTRAN_REAL16
#define R_MPI_COMPLEX32 OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_complex32)
#endif
#define R_MPI_DOUBLE_COMPLEX OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_dblcplex)
#define R_MPI_2REAL OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_2real)
#define R_MPI_2DOUBLE_PRECISION OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_2dblprec)
#define R_MPI_2INTEGER OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_2integer)

/* New datatypes from the MPI 2.2 standard */
#define R_MPI_INT8_T                OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_int8_t)
#define R_MPI_UINT8_T               OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_uint8_t)
#define R_MPI_INT16_T               OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_int16_t)
#define R_MPI_UINT16_T              OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_uint16_t)
#define R_MPI_INT32_T               OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_int32_t)
#define R_MPI_UINT32_T              OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_uint32_t)
#define R_MPI_INT64_T               OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_int64_t)
#define R_MPI_UINT64_T              OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_uint64_t)
#define R_MPI_AINT                  OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_aint)
#define R_MPI_OFFSET                OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_offset)
#define R_MPI_C_BOOL                OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_c_bool)
#if HAVE_FLOAT__COMPLEX
#define R_MPI_C_COMPLEX             OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_c_complex)
#define R_MPI_C_FLOAT_COMPLEX       OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_c_float_complex)
#endif
#if HAVE_DOUBLE__COMPLEX
#define R_MPI_C_DOUBLE_COMPLEX      OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_c_double_complex)
#endif
#if HAVE_LONG_DOUBLE__COMPLEX
#define R_MPI_C_LONG_DOUBLE_COMPLEX OMPI_PREDEFINED_GLOBAL(R_MPI_Datatype, ompi_mpi_c_long_double_complex)
#endif

#define R_MPI_ERRORS_ARE_FATAL OMPI_PREDEFINED_GLOBAL(R_MPI_Errhandler, ompi_mpi_errors_are_fatal)
#define R_MPI_ERRORS_RETURN OMPI_PREDEFINED_GLOBAL(R_MPI_Errhandler, ompi_mpi_errors_return)

/* Typeclass definition for R_MPI_Type_match_size */
#define R_MPI_TYPECLASS_INTEGER    1
#define R_MPI_TYPECLASS_REAL       2
#define R_MPI_TYPECLASS_COMPLEX    3


/*
 * MPI API
 */

OMPI_DECLSPEC  int R_MPI_Abort(R_MPI_Comm comm, int errorcode);
OMPI_DECLSPEC  int R_MPI_Accumulate(void *origin_addr, int origin_count, R_MPI_Datatype origin_datatype,
                                  int target_rank, R_MPI_Aint target_disp, int target_count,
                                  R_MPI_Datatype target_datatype, R_MPI_Op op, R_MPI_Win win);
OMPI_DECLSPEC  int R_MPI_Add_error_class(int *errorclass);
OMPI_DECLSPEC  int R_MPI_Add_error_code(int errorclass, int *errorcode);
OMPI_DECLSPEC  int R_MPI_Add_error_string(int errorcode, char *string);
OMPI_DECLSPEC  int R_MPI_Address(void *location, R_MPI_Aint *address)
                               __mpi_interface_deprecated__("R_MPI_Address is superseded by R_MPI_Get_address in MPI-2.0");
OMPI_DECLSPEC  int R_MPI_Allgather(void *sendbuf, int sendcount, R_MPI_Datatype sendtype,
                                 void *recvbuf, int recvcount,
                                 R_MPI_Datatype recvtype, R_MPI_Comm comm);
OMPI_DECLSPEC  int R_MPI_Allgatherv(void *sendbuf, int sendcount, R_MPI_Datatype sendtype,
                                  void *recvbuf, int *recvcounts,
                                  int *displs, R_MPI_Datatype recvtype, R_MPI_Comm comm);
OMPI_DECLSPEC  int R_MPI_Alloc_mem(R_MPI_Aint size, R_MPI_Info info,
                                 void *baseptr);
OMPI_DECLSPEC  int R_MPI_Allreduce(void *sendbuf, void *recvbuf, int count,
                                 R_MPI_Datatype datatype, R_MPI_Op op, R_MPI_Comm comm);
OMPI_DECLSPEC  int R_MPI_Alltoall(void *sendbuf, int sendcount, R_MPI_Datatype sendtype,
                                void *recvbuf, int recvcount,
                                R_MPI_Datatype recvtype, R_MPI_Comm comm);
OMPI_DECLSPEC  int R_MPI_Alltoallv(void *sendbuf, int *sendcounts, int *sdispls,
                                 R_MPI_Datatype sendtype, void *recvbuf, int *recvcounts,
                                 int *rdispls, R_MPI_Datatype recvtype, R_MPI_Comm comm);
OMPI_DECLSPEC  int R_MPI_Alltoallw(void *sendbuf, int *sendcounts, int *sdispls, R_MPI_Datatype *sendtypes,
                                 void *recvbuf, int *recvcounts, int *rdispls, R_MPI_Datatype *recvtypes,
                                 R_MPI_Comm comm);
OMPI_DECLSPEC  int R_MPI_Attr_delete(R_MPI_Comm comm, int keyval)
                                   __mpi_interface_deprecated__("R_MPI_Attr_delete is superseded by R_MPI_Comm_delete_attr in MPI-2.0");
OMPI_DECLSPEC  int R_MPI_Attr_get(R_MPI_Comm comm, int keyval, void *attribute_val, int *flag)
                                __mpi_interface_deprecated__("R_MPI_Attr_get is superseded by R_MPI_Comm_get_attr in MPI-2.0");
OMPI_DECLSPEC  int R_MPI_Attr_put(R_MPI_Comm comm, int keyval, void *attribute_val)
                                __mpi_interface_deprecated__("R_MPI_Attr_put is superseded by R_MPI_Comm_set_attr in MPI-2.0");
OMPI_DECLSPEC  int R_MPI_Barrier(R_MPI_Comm comm);
OMPI_DECLSPEC  int R_MPI_Bcast(void *buffer, int count, R_MPI_Datatype datatype,
                             int root, R_MPI_Comm comm);
OMPI_DECLSPEC  int R_MPI_Bsend(void *buf, int count, R_MPI_Datatype datatype,
                             int dest, int tag, R_MPI_Comm comm);
OMPI_DECLSPEC  int R_MPI_Bsend_init(void *buf, int count, R_MPI_Datatype datatype,
                                  int dest, int tag, R_MPI_Comm comm, R_MPI_Request *request);
OMPI_DECLSPEC  int R_MPI_Buffer_attach(void *buffer, int size);
OMPI_DECLSPEC  int R_MPI_Buffer_detach(void *buffer, int *size);
OMPI_DECLSPEC  int R_MPI_Cancel(R_MPI_Request *request);
OMPI_DECLSPEC  int R_MPI_Cart_coords(R_MPI_Comm comm, int rank, int maxdims, int *coords);
OMPI_DECLSPEC  int R_MPI_Cart_create(R_MPI_Comm old_comm, int ndims, int *dims,
                                   int *periods, int reorder, R_MPI_Comm *comm_cart);
OMPI_DECLSPEC  int R_MPI_Cart_get(R_MPI_Comm comm, int maxdims, int *dims,
                                int *periods, int *coords);
OMPI_DECLSPEC  int R_MPI_Cart_map(R_MPI_Comm comm, int ndims, int *dims,
                                int *periods, int *newrank);
OMPI_DECLSPEC  int R_MPI_Cart_rank(R_MPI_Comm comm, int *coords, int *rank);
OMPI_DECLSPEC  int R_MPI_Cart_shift(R_MPI_Comm comm, int direction, int disp,
                                  int *rank_source, int *rank_dest);
OMPI_DECLSPEC  int R_MPI_Cart_sub(R_MPI_Comm comm, int *remain_dims, R_MPI_Comm *new_comm);
OMPI_DECLSPEC  int R_MPI_Cartdim_get(R_MPI_Comm comm, int *ndims);
OMPI_DECLSPEC  int R_MPI_Close_port(char *port_name);
OMPI_DECLSPEC  int R_MPI_Comm_accept(char *port_name, R_MPI_Info info, int root,
                                   R_MPI_Comm comm, R_MPI_Comm *newcomm);
OMPI_DECLSPEC  R_MPI_Fint R_MPI_Comm_c2f(R_MPI_Comm comm);
OMPI_DECLSPEC  int R_MPI_Comm_call_errhandler(R_MPI_Comm comm, int errorcode);
OMPI_DECLSPEC  int R_MPI_Comm_compare(R_MPI_Comm comm1, R_MPI_Comm comm2, int *result);
OMPI_DECLSPEC  int R_MPI_Comm_connect(char *port_name, R_MPI_Info info, int root,
                                    R_MPI_Comm comm, R_MPI_Comm *newcomm);
OMPI_DECLSPEC  int R_MPI_Comm_create_errhandler(R_MPI_Comm_errhandler_function *function,
                                              R_MPI_Errhandler *errhandler);
OMPI_DECLSPEC  int R_MPI_Comm_create_keyval(R_MPI_Comm_copy_attr_function *comm_copy_attr_fn,
                                          R_MPI_Comm_delete_attr_function *comm_delete_attr_fn,
                                          int *comm_keyval, void *extra_state);
OMPI_DECLSPEC  int R_MPI_Comm_create(R_MPI_Comm comm, R_MPI_Group group, R_MPI_Comm *newcomm);
OMPI_DECLSPEC  int R_MPI_Comm_delete_attr(R_MPI_Comm comm, int comm_keyval);
OMPI_DECLSPEC  int R_MPI_Comm_disconnect(R_MPI_Comm *comm);
OMPI_DECLSPEC  int R_MPI_Comm_dup(R_MPI_Comm comm, R_MPI_Comm *newcomm);
OMPI_DECLSPEC  R_MPI_Comm R_MPI_Comm_f2c(R_MPI_Fint comm);
OMPI_DECLSPEC  int R_MPI_Comm_free_keyval(int *comm_keyval);
OMPI_DECLSPEC  int R_MPI_Comm_free(R_MPI_Comm *comm);
OMPI_DECLSPEC  int R_MPI_Comm_get_attr(R_MPI_Comm comm, int comm_keyval,
                                     void *attribute_val, int *flag);
OMPI_DECLSPEC  int R_MPI_Comm_get_errhandler(R_MPI_Comm comm, R_MPI_Errhandler *erhandler);
OMPI_DECLSPEC  int R_MPI_Comm_get_name(R_MPI_Comm comm, char *comm_name, int *resultlen);
OMPI_DECLSPEC  int R_MPI_Comm_get_parent(R_MPI_Comm *parent);
OMPI_DECLSPEC  int R_MPI_Comm_group(R_MPI_Comm comm, R_MPI_Group *group);
OMPI_DECLSPEC  int R_MPI_Comm_join(int fd, R_MPI_Comm *intercomm);
OMPI_DECLSPEC  int R_MPI_Comm_rank(R_MPI_Comm comm, int *rank);
OMPI_DECLSPEC  int R_MPI_Comm_remote_group(R_MPI_Comm comm, R_MPI_Group *group);
OMPI_DECLSPEC  int R_MPI_Comm_remote_size(R_MPI_Comm comm, int *size);
OMPI_DECLSPEC  int R_MPI_Comm_set_attr(R_MPI_Comm comm, int comm_keyval, void *attribute_val);
OMPI_DECLSPEC  int R_MPI_Comm_set_errhandler(R_MPI_Comm comm, R_MPI_Errhandler errhandler);
OMPI_DECLSPEC  int R_MPI_Comm_set_name(R_MPI_Comm comm, char *comm_name);
OMPI_DECLSPEC  int R_MPI_Comm_size(R_MPI_Comm comm, int *size);
OMPI_DECLSPEC  int R_MPI_Comm_spawn(char *command, char **argv, int maxprocs, R_MPI_Info info,
                                  int root, R_MPI_Comm comm, R_MPI_Comm *intercomm,
                                  int *array_of_errcodes);
OMPI_DECLSPEC  int R_MPI_Comm_spawn_multiple(int count, char **array_of_commands, char ***array_of_argv,
                                           int *array_of_maxprocs, R_MPI_Info *array_of_info,
                                           int root, R_MPI_Comm comm, R_MPI_Comm *intercomm,
                                           int *array_of_errcodes);
OMPI_DECLSPEC  int R_MPI_Comm_split(R_MPI_Comm comm, int color, int key, R_MPI_Comm *newcomm);
OMPI_DECLSPEC  int R_MPI_Comm_test_inter(R_MPI_Comm comm, int *flag);
OMPI_DECLSPEC  int R_MPI_Dims_create(int nnodes, int ndims, int *dims);
OMPI_DECLSPEC  R_MPI_Fint R_MPI_Errhandler_c2f(R_MPI_Errhandler errhandler);
OMPI_DECLSPEC  int R_MPI_Errhandler_create(R_MPI_Handler_function *function,
                                         R_MPI_Errhandler *errhandler)
                                         __mpi_interface_deprecated__("R_MPI_Errhandler_create is superseded by R_MPI_Comm_create_errhandler in MPI-2.0");
OMPI_DECLSPEC  R_MPI_Errhandler R_MPI_Errhandler_f2c(R_MPI_Fint errhandler);
OMPI_DECLSPEC  int R_MPI_Errhandler_free(R_MPI_Errhandler *errhandler);
OMPI_DECLSPEC  int R_MPI_Errhandler_get(R_MPI_Comm comm, R_MPI_Errhandler *errhandler)
                                      __mpi_interface_deprecated__("R_MPI_Errhandler_get is superseded by R_MPI_Comm_get_errhandler in MPI-2.0");
OMPI_DECLSPEC  int R_MPI_Errhandler_set(R_MPI_Comm comm, R_MPI_Errhandler errhandler)
                                      __mpi_interface_deprecated__("R_MPI_Errhandler_set is superseded by R_MPI_Comm_set_errhandler in MPI-2.0");
OMPI_DECLSPEC  int R_MPI_Error_class(int errorcode, int *errorclass);
OMPI_DECLSPEC  int R_MPI_Error_string(int errorcode, char *string, int *resultlen);
OMPI_DECLSPEC  int R_MPI_Exscan(void *sendbuf, void *recvbuf, int count,
                              R_MPI_Datatype datatype, R_MPI_Op op, R_MPI_Comm comm);
#if OMPI_PROVIDE_R_MPI_FILE_INTERFACE
OMPI_DECLSPEC  R_MPI_Fint R_MPI_File_c2f(R_MPI_File file);
OMPI_DECLSPEC  R_MPI_File R_MPI_File_f2c(R_MPI_Fint file);
OMPI_DECLSPEC  int R_MPI_File_call_errhandler(R_MPI_File fh, int errorcode);
OMPI_DECLSPEC  int R_MPI_File_create_errhandler(R_MPI_File_errhandler_function *function,
                                              R_MPI_Errhandler *errhandler);
OMPI_DECLSPEC  int R_MPI_File_set_errhandler( R_MPI_File file, R_MPI_Errhandler errhandler);
OMPI_DECLSPEC  int R_MPI_File_get_errhandler( R_MPI_File file, R_MPI_Errhandler *errhandler);
OMPI_DECLSPEC  int R_MPI_File_open(R_MPI_Comm comm, char *filename, int amode,
                                 R_MPI_Info info, R_MPI_File *fh);
OMPI_DECLSPEC  int R_MPI_File_close(R_MPI_File *fh);
OMPI_DECLSPEC  int R_MPI_File_delete(char *filename, R_MPI_Info info);
OMPI_DECLSPEC  int R_MPI_File_set_size(R_MPI_File fh, R_MPI_Offset size);
OMPI_DECLSPEC  int R_MPI_File_preallocate(R_MPI_File fh, R_MPI_Offset size);
OMPI_DECLSPEC  int R_MPI_File_get_size(R_MPI_File fh, R_MPI_Offset *size);
OMPI_DECLSPEC  int R_MPI_File_get_group(R_MPI_File fh, R_MPI_Group *group);
OMPI_DECLSPEC  int R_MPI_File_get_amode(R_MPI_File fh, int *amode);
OMPI_DECLSPEC  int R_MPI_File_set_info(R_MPI_File fh, R_MPI_Info info);
OMPI_DECLSPEC  int R_MPI_File_get_info(R_MPI_File fh, R_MPI_Info *info_used);
OMPI_DECLSPEC  int R_MPI_File_set_view(R_MPI_File fh, R_MPI_Offset disp, R_MPI_Datatype etype,
                                     R_MPI_Datatype filetype, char *datarep, R_MPI_Info info);
OMPI_DECLSPEC  int R_MPI_File_get_view(R_MPI_File fh, R_MPI_Offset *disp,
                                     R_MPI_Datatype *etype,
                                     R_MPI_Datatype *filetype, char *datarep);
OMPI_DECLSPEC  int R_MPI_File_read_at(R_MPI_File fh, R_MPI_Offset offset, void *buf,
                                    int count, R_MPI_Datatype datatype, R_MPI_Status *status);
OMPI_DECLSPEC  int R_MPI_File_read_at_all(R_MPI_File fh, R_MPI_Offset offset, void *buf,
                                        int count, R_MPI_Datatype datatype, R_MPI_Status *status);
OMPI_DECLSPEC  int R_MPI_File_write_at(R_MPI_File fh, R_MPI_Offset offset, void *buf,
                                     int count, R_MPI_Datatype datatype, R_MPI_Status *status);
OMPI_DECLSPEC  int R_MPI_File_write_at_all(R_MPI_File fh, R_MPI_Offset offset, void *buf,
                                         int count, R_MPI_Datatype datatype, R_MPI_Status *status);
OMPI_DECLSPEC  int R_MPI_File_iread_at(R_MPI_File fh, R_MPI_Offset offset, void *buf,
                                     int count, R_MPI_Datatype datatype, R_MPI_Request *request);
OMPI_DECLSPEC  int R_MPI_File_iwrite_at(R_MPI_File fh, R_MPI_Offset offset, void *buf,
                                      int count, R_MPI_Datatype datatype, R_MPI_Request *request);
OMPI_DECLSPEC  int R_MPI_File_read(R_MPI_File fh, void *buf, int count,
                                 R_MPI_Datatype datatype, R_MPI_Status *status);
OMPI_DECLSPEC  int R_MPI_File_read_all(R_MPI_File fh, void *buf, int count,
                                     R_MPI_Datatype datatype, R_MPI_Status *status);
OMPI_DECLSPEC  int R_MPI_File_write(R_MPI_File fh, void *buf, int count,
                                  R_MPI_Datatype datatype, R_MPI_Status *status);
OMPI_DECLSPEC  int R_MPI_File_write_all(R_MPI_File fh, void *buf, int count,
                                      R_MPI_Datatype datatype, R_MPI_Status *status);
OMPI_DECLSPEC  int R_MPI_File_iread(R_MPI_File fh, void *buf, int count,
                                  R_MPI_Datatype datatype, R_MPI_Request *request);
OMPI_DECLSPEC  int R_MPI_File_iwrite(R_MPI_File fh, void *buf, int count,
                                   R_MPI_Datatype datatype, R_MPI_Request *request);
OMPI_DECLSPEC  int R_MPI_File_seek(R_MPI_File fh, R_MPI_Offset offset, int whence);
OMPI_DECLSPEC  int R_MPI_File_get_position(R_MPI_File fh, R_MPI_Offset *offset);
OMPI_DECLSPEC  int R_MPI_File_get_byte_offset(R_MPI_File fh, R_MPI_Offset offset,
                                            R_MPI_Offset *disp);
OMPI_DECLSPEC  int R_MPI_File_read_shared(R_MPI_File fh, void *buf, int count,
                                        R_MPI_Datatype datatype, R_MPI_Status *status);
OMPI_DECLSPEC  int R_MPI_File_write_shared(R_MPI_File fh, void *buf, int count,
					 R_MPI_Datatype datatype, R_MPI_Status *status);
OMPI_DECLSPEC  int R_MPI_File_iread_shared(R_MPI_File fh, void *buf, int count,
                                         R_MPI_Datatype datatype, R_MPI_Request *request);
OMPI_DECLSPEC  int R_MPI_File_iwrite_shared(R_MPI_File fh, void *buf, int count,
                                          R_MPI_Datatype datatype, R_MPI_Request *request);
OMPI_DECLSPEC  int R_MPI_File_read_ordered(R_MPI_File fh, void *buf, int count,
                                         R_MPI_Datatype datatype, R_MPI_Status *status);
OMPI_DECLSPEC  int R_MPI_File_write_ordered(R_MPI_File fh, void *buf, int count,
                                          R_MPI_Datatype datatype, R_MPI_Status *status);
OMPI_DECLSPEC  int R_MPI_File_seek_shared(R_MPI_File fh, R_MPI_Offset offset, int whence);
OMPI_DECLSPEC  int R_MPI_File_get_position_shared(R_MPI_File fh, R_MPI_Offset *offset);
OMPI_DECLSPEC  int R_MPI_File_read_at_all_begin(R_MPI_File fh, R_MPI_Offset offset, void *buf,
                                              int count, R_MPI_Datatype datatype);
OMPI_DECLSPEC  int R_MPI_File_read_at_all_end(R_MPI_File fh, void *buf, R_MPI_Status *status);
OMPI_DECLSPEC  int R_MPI_File_write_at_all_begin(R_MPI_File fh, R_MPI_Offset offset, void *buf,
                                               int count, R_MPI_Datatype datatype);
OMPI_DECLSPEC  int R_MPI_File_write_at_all_end(R_MPI_File fh, void *buf, R_MPI_Status *status);
OMPI_DECLSPEC  int R_MPI_File_read_all_begin(R_MPI_File fh, void *buf, int count,
                                           R_MPI_Datatype datatype);
OMPI_DECLSPEC  int R_MPI_File_read_all_end(R_MPI_File fh, void *buf, R_MPI_Status *status);
OMPI_DECLSPEC  int R_MPI_File_write_all_begin(R_MPI_File fh, void *buf, int count,
                                            R_MPI_Datatype datatype);
OMPI_DECLSPEC  int R_MPI_File_write_all_end(R_MPI_File fh, void *buf, R_MPI_Status *status);
OMPI_DECLSPEC  int R_MPI_File_read_ordered_begin(R_MPI_File fh, void *buf, int count,
                                               R_MPI_Datatype datatype);
OMPI_DECLSPEC  int R_MPI_File_read_ordered_end(R_MPI_File fh, void *buf, R_MPI_Status *status);
OMPI_DECLSPEC  int R_MPI_File_write_ordered_begin(R_MPI_File fh, void *buf, int count,
                                                R_MPI_Datatype datatype);
OMPI_DECLSPEC  int R_MPI_File_write_ordered_end(R_MPI_File fh, void *buf, R_MPI_Status *status);
OMPI_DECLSPEC  int R_MPI_File_get_type_extent(R_MPI_File fh, R_MPI_Datatype datatype,
                                            R_MPI_Aint *extent);
OMPI_DECLSPEC  int R_MPI_File_set_atomicity(R_MPI_File fh, int flag);
OMPI_DECLSPEC  int R_MPI_File_get_atomicity(R_MPI_File fh, int *flag);
OMPI_DECLSPEC  int R_MPI_File_sync(R_MPI_File fh);
#endif /* #if OMPI_PROVIDE_R_MPI_FILE_INTERFACE */
OMPI_DECLSPEC  int R_MPI_Finalize(void);
OMPI_DECLSPEC  int R_MPI_Finalized(int *flag);
OMPI_DECLSPEC  int R_MPI_Free_mem(void *base);
OMPI_DECLSPEC  int R_MPI_Gather(void *sendbuf, int sendcount, R_MPI_Datatype sendtype,
                              void *recvbuf, int recvcount, R_MPI_Datatype recvtype,
                              int root, R_MPI_Comm comm);
OMPI_DECLSPEC  int R_MPI_Gatherv(void *sendbuf, int sendcount, R_MPI_Datatype sendtype,
                               void *recvbuf, int *recvcounts, int *displs,
                               R_MPI_Datatype recvtype, int root, R_MPI_Comm comm);
OMPI_DECLSPEC  int R_MPI_Get_address(void *location, R_MPI_Aint *address);
OMPI_DECLSPEC  int R_MPI_Get_count(R_MPI_Status *status, R_MPI_Datatype datatype, int *count);
OMPI_DECLSPEC  int R_MPI_Get_elements(R_MPI_Status *status, R_MPI_Datatype datatype, int *count);
OMPI_DECLSPEC  int R_MPI_Get(void *origin_addr, int origin_count,
                           R_MPI_Datatype origin_datatype, int target_rank,
                           R_MPI_Aint target_disp, int target_count,
                           R_MPI_Datatype target_datatype, R_MPI_Win win);
OMPI_DECLSPEC  int R_MPI_Get_processor_name(char *name, int *resultlen);
OMPI_DECLSPEC  int R_MPI_Get_version(int *version, int *subversion);
OMPI_DECLSPEC  int R_MPI_Graph_create(R_MPI_Comm comm_old, int nnodes, int *index,
                                    int *edges, int reorder, R_MPI_Comm *comm_graph);
OMPI_DECLSPEC  int R_MPI_Graph_get(R_MPI_Comm comm, int maxindex, int maxedges,
                                 int *index, int *edges);
OMPI_DECLSPEC  int R_MPI_Graph_map(R_MPI_Comm comm, int nnodes, int *index, int *edges,
                                 int *newrank);
OMPI_DECLSPEC  int R_MPI_Graph_neighbors_count(R_MPI_Comm comm, int rank, int *nneighbors);
OMPI_DECLSPEC  int R_MPI_Graph_neighbors(R_MPI_Comm comm, int rank, int maxneighbors,
                                       int *neighbors);
OMPI_DECLSPEC  int R_MPI_Graphdims_get(R_MPI_Comm comm, int *nnodes, int *nedges);
OMPI_DECLSPEC  int R_MPI_Grequest_complete(R_MPI_Request request);
OMPI_DECLSPEC  int R_MPI_Grequest_start(R_MPI_Grequest_query_function *query_fn,
                                      R_MPI_Grequest_free_function *free_fn,
                                      R_MPI_Grequest_cancel_function *cancel_fn,
                                      void *extra_state, R_MPI_Request *request);
OMPI_DECLSPEC  R_MPI_Fint R_MPI_Group_c2f(R_MPI_Group group);
OMPI_DECLSPEC  int R_MPI_Group_compare(R_MPI_Group group1, R_MPI_Group group2, int *result);
OMPI_DECLSPEC  int R_MPI_Group_difference(R_MPI_Group group1, R_MPI_Group group2,
                                        R_MPI_Group *newgroup);
OMPI_DECLSPEC  int R_MPI_Group_excl(R_MPI_Group group, int n, int *ranks,
                                  R_MPI_Group *newgroup);
OMPI_DECLSPEC  R_MPI_Group R_MPI_Group_f2c(R_MPI_Fint group);
OMPI_DECLSPEC  int R_MPI_Group_free(R_MPI_Group *group);
OMPI_DECLSPEC  int R_MPI_Group_incl(R_MPI_Group group, int n, int *ranks,
                                  R_MPI_Group *newgroup);
OMPI_DECLSPEC  int R_MPI_Group_intersection(R_MPI_Group group1, R_MPI_Group group2,
                                          R_MPI_Group *newgroup);
OMPI_DECLSPEC  int R_MPI_Group_range_excl(R_MPI_Group group, int n, int ranges[][3],
                                        R_MPI_Group *newgroup);
OMPI_DECLSPEC  int R_MPI_Group_range_incl(R_MPI_Group group, int n, int ranges[][3],
                                        R_MPI_Group *newgroup);
OMPI_DECLSPEC  int R_MPI_Group_rank(R_MPI_Group group, int *rank);
OMPI_DECLSPEC  int R_MPI_Group_size(R_MPI_Group group, int *size);
OMPI_DECLSPEC  int R_MPI_Group_translate_ranks(R_MPI_Group group1, int n, int *ranks1,
                                             R_MPI_Group group2, int *ranks2);
OMPI_DECLSPEC  int R_MPI_Group_union(R_MPI_Group group1, R_MPI_Group group2,
                                   R_MPI_Group *newgroup);
OMPI_DECLSPEC  int R_MPI_Ibsend(void *buf, int count, R_MPI_Datatype datatype, int dest,
                              int tag, R_MPI_Comm comm, R_MPI_Request *request);
OMPI_DECLSPEC  R_MPI_Fint R_MPI_Info_c2f(R_MPI_Info info);
OMPI_DECLSPEC  int R_MPI_Info_create(R_MPI_Info *info);
OMPI_DECLSPEC  int R_MPI_Info_delete(R_MPI_Info info, char *key);
OMPI_DECLSPEC  int R_MPI_Info_dup(R_MPI_Info info, R_MPI_Info *newinfo);
OMPI_DECLSPEC  R_MPI_Info R_MPI_Info_f2c(R_MPI_Fint info);
OMPI_DECLSPEC  int R_MPI_Info_free(R_MPI_Info *info);
OMPI_DECLSPEC  int R_MPI_Info_get(R_MPI_Info info, char *key, int valuelen,
                                char *value, int *flag);
OMPI_DECLSPEC  int R_MPI_Info_get_nkeys(R_MPI_Info info, int *nkeys);
OMPI_DECLSPEC  int R_MPI_Info_get_nthkey(R_MPI_Info info, int n, char *key);
OMPI_DECLSPEC  int R_MPI_Info_get_valuelen(R_MPI_Info info, char *key, int *valuelen,
                                         int *flag);
OMPI_DECLSPEC  int R_MPI_Info_set(R_MPI_Info info, char *key, char *value);
OMPI_DECLSPEC  int R_MPI_Init(int *argc, char ***argv);
OMPI_DECLSPEC  int R_MPI_Initialized(int *flag);
OMPI_DECLSPEC  int R_MPI_Init_thread(int *argc, char ***argv, int required,
                                   int *provided);
OMPI_DECLSPEC  int R_MPI_Intercomm_create(R_MPI_Comm local_comm, int local_leader,
                                        R_MPI_Comm bridge_comm, int remote_leader,
                                        int tag, R_MPI_Comm *newintercomm);
OMPI_DECLSPEC  int R_MPI_Intercomm_merge(R_MPI_Comm intercomm, int high,
                                       R_MPI_Comm *newintercomm);
OMPI_DECLSPEC  int R_MPI_Iprobe(int source, int tag, R_MPI_Comm comm, int *flag,
                              R_MPI_Status *status);
OMPI_DECLSPEC  int R_MPI_Irecv(void *buf, int count, R_MPI_Datatype datatype, int source,
                             int tag, R_MPI_Comm comm, R_MPI_Request *request);
OMPI_DECLSPEC  int R_MPI_Irsend(void *buf, int count, R_MPI_Datatype datatype, int dest,
                              int tag, R_MPI_Comm comm, R_MPI_Request *request);
OMPI_DECLSPEC  int R_MPI_Isend(void *buf, int count, R_MPI_Datatype datatype, int dest,
                             int tag, R_MPI_Comm comm, R_MPI_Request *request);
OMPI_DECLSPEC  int R_MPI_Issend(void *buf, int count, R_MPI_Datatype datatype, int dest,
                              int tag, R_MPI_Comm comm, R_MPI_Request *request);
OMPI_DECLSPEC  int R_MPI_Is_thread_main(int *flag);
OMPI_DECLSPEC  int R_MPI_Keyval_create(R_MPI_Copy_function *copy_fn,
                                     R_MPI_Delete_function *delete_fn,
                                     int *keyval, void *extra_state)
                                     __mpi_interface_deprecated__("R_MPI_Keyval_create is superseded by R_MPI_Comm_create_keyval in MPI-2.0");
OMPI_DECLSPEC  int R_MPI_Keyval_free(int *keyval)
                                   __mpi_interface_deprecated__("R_MPI_Keyval_free is superseded by R_MPI_Comm_free_keyval in MPI-2.0");
OMPI_DECLSPEC  int R_MPI_Lookup_name(char *service_name, R_MPI_Info info, char *port_name);
OMPI_DECLSPEC  R_MPI_Fint R_MPI_Op_c2f(R_MPI_Op op);
OMPI_DECLSPEC  int R_MPI_Op_commutative(R_MPI_Op op, int *commute);
OMPI_DECLSPEC  int R_MPI_Op_create(R_MPI_User_function *function, int commute, R_MPI_Op *op);
OMPI_DECLSPEC  int R_MPI_Open_port(R_MPI_Info info, char *port_name);
OMPI_DECLSPEC  R_MPI_Op R_MPI_Op_f2c(R_MPI_Fint op);
OMPI_DECLSPEC  int R_MPI_Op_free(R_MPI_Op *op);
OMPI_DECLSPEC  int R_MPI_Pack_external(char *datarep, void *inbuf, int incount,
                                     R_MPI_Datatype datatype, void *outbuf,
                                     R_MPI_Aint outsize, R_MPI_Aint *position);
OMPI_DECLSPEC  int R_MPI_Pack_external_size(char *datarep, int incount,
                                          R_MPI_Datatype datatype, R_MPI_Aint *size);
OMPI_DECLSPEC  int R_MPI_Pack(void *inbuf, int incount, R_MPI_Datatype datatype,
                            void *outbuf, int outsize, int *position, R_MPI_Comm comm);
OMPI_DECLSPEC  int R_MPI_Pack_size(int incount, R_MPI_Datatype datatype, R_MPI_Comm comm,
                                 int *size);
OMPI_DECLSPEC  int R_MPI_Pcontrol(const int level, ...);
OMPI_DECLSPEC  int R_MPI_Probe(int source, int tag, R_MPI_Comm comm, R_MPI_Status *status);
OMPI_DECLSPEC  int R_MPI_Publish_name(char *service_name, R_MPI_Info info,
                                    char *port_name);
OMPI_DECLSPEC  int R_MPI_Put(void *origin_addr, int origin_count, R_MPI_Datatype origin_datatype,
                           int target_rank, R_MPI_Aint target_disp, int target_count,
                           R_MPI_Datatype target_datatype, R_MPI_Win win);
OMPI_DECLSPEC  int R_MPI_Query_thread(int *provided);
OMPI_DECLSPEC  int R_MPI_Recv_init(void *buf, int count, R_MPI_Datatype datatype, int source,
                                 int tag, R_MPI_Comm comm, R_MPI_Request *request);
OMPI_DECLSPEC  int R_MPI_Recv(void *buf, int count, R_MPI_Datatype datatype, int source,
                            int tag, R_MPI_Comm comm, R_MPI_Status *status);
OMPI_DECLSPEC  int R_MPI_Reduce(void *sendbuf, void *recvbuf, int count,
                              R_MPI_Datatype datatype, R_MPI_Op op, int root, R_MPI_Comm comm);
OMPI_DECLSPEC  int R_MPI_Reduce_local(void *inbuf, void *inoutbuf, int count,
                                    R_MPI_Datatype datatype, R_MPI_Op op);
OMPI_DECLSPEC  int R_MPI_Reduce_scatter(void *sendbuf, void *recvbuf, int *recvcounts,
                                      R_MPI_Datatype datatype, R_MPI_Op op, R_MPI_Comm comm);
OMPI_DECLSPEC  int R_MPI_Register_datarep(char *datarep,
                                        R_MPI_Datarep_conversion_function *read_conversion_fn,
                                        R_MPI_Datarep_conversion_function *write_conversion_fn,
                                        R_MPI_Datarep_extent_function *dtype_file_extent_fn,
                                        void *extra_state);
OMPI_DECLSPEC  R_MPI_Fint R_MPI_Request_c2f(R_MPI_Request request);
OMPI_DECLSPEC  R_MPI_Request R_MPI_Request_f2c(R_MPI_Fint request);
OMPI_DECLSPEC  int R_MPI_Request_free(R_MPI_Request *request);
OMPI_DECLSPEC  int R_MPI_Request_get_status(R_MPI_Request request, int *flag,
                                          R_MPI_Status *status);
OMPI_DECLSPEC  int R_MPI_Rsend(void *ibuf, int count, R_MPI_Datatype datatype, int dest,
                             int tag, R_MPI_Comm comm);
OMPI_DECLSPEC  int R_MPI_Rsend_init(void *buf, int count, R_MPI_Datatype datatype,
                                  int dest, int tag, R_MPI_Comm comm,
                                  R_MPI_Request *request);
OMPI_DECLSPEC  int R_MPI_Scan(void *sendbuf, void *recvbuf, int count,
                            R_MPI_Datatype datatype, R_MPI_Op op, R_MPI_Comm comm);
OMPI_DECLSPEC  int R_MPI_Scatter(void *sendbuf, int sendcount, R_MPI_Datatype sendtype,
                               void *recvbuf, int recvcount, R_MPI_Datatype recvtype,
                               int root, R_MPI_Comm comm);
OMPI_DECLSPEC  int R_MPI_Scatterv(void *sendbuf, int *sendcounts, int *displs,
                                R_MPI_Datatype sendtype, void *recvbuf, int recvcount,
                                R_MPI_Datatype recvtype, int root, R_MPI_Comm comm);
OMPI_DECLSPEC  int R_MPI_Send_init(void *buf, int count, R_MPI_Datatype datatype,
                                 int dest, int tag, R_MPI_Comm comm,
                                 R_MPI_Request *request);
OMPI_DECLSPEC  int R_MPI_Send(void *buf, int count, R_MPI_Datatype datatype, int dest,
                            int tag, R_MPI_Comm comm);
OMPI_DECLSPEC  int R_MPI_Sendrecv(void *sendbuf, int sendcount, R_MPI_Datatype sendtype,
                                int dest, int sendtag, void *recvbuf, int recvcount,
                                R_MPI_Datatype recvtype, int source, int recvtag,
                                R_MPI_Comm comm,  R_MPI_Status *status);
OMPI_DECLSPEC  int R_MPI_Sendrecv_replace(void * buf, int count, R_MPI_Datatype datatype,
                                        int dest, int sendtag, int source, int recvtag,
                                        R_MPI_Comm comm, R_MPI_Status *status);
OMPI_DECLSPEC  int R_MPI_Ssend_init(void *buf, int count, R_MPI_Datatype datatype,
                                  int dest, int tag, R_MPI_Comm comm,
                                  R_MPI_Request *request);
OMPI_DECLSPEC  int R_MPI_Ssend(void *buf, int count, R_MPI_Datatype datatype, int dest,
                             int tag, R_MPI_Comm comm);
OMPI_DECLSPEC  int R_MPI_Start(R_MPI_Request *request);
OMPI_DECLSPEC  int R_MPI_Startall(int count, R_MPI_Request *array_of_requests);
OMPI_DECLSPEC  int R_MPI_Status_c2f(R_MPI_Status *c_status, R_MPI_Fint *f_status);
OMPI_DECLSPEC  int R_MPI_Status_f2c(R_MPI_Fint *f_status, R_MPI_Status *c_status);
OMPI_DECLSPEC  int R_MPI_Status_set_cancelled(R_MPI_Status *status, int flag);
OMPI_DECLSPEC  int R_MPI_Status_set_elements(R_MPI_Status *status, R_MPI_Datatype datatype,
                                           int count);
OMPI_DECLSPEC  int R_MPI_Testall(int count, R_MPI_Request array_of_requests[], int *flag,
                               R_MPI_Status array_of_statuses[]);
OMPI_DECLSPEC  int R_MPI_Testany(int count, R_MPI_Request array_of_requests[], int *index,
                               int *flag, R_MPI_Status *status);
OMPI_DECLSPEC  int R_MPI_Test(R_MPI_Request *request, int *flag, R_MPI_Status *status);
OMPI_DECLSPEC  int R_MPI_Test_cancelled(R_MPI_Status *status, int *flag);
OMPI_DECLSPEC  int R_MPI_Testsome(int incount, R_MPI_Request array_of_requests[],
                                int *outcount, int array_of_indices[],
                                R_MPI_Status array_of_statuses[]);
OMPI_DECLSPEC  int R_MPI_Topo_test(R_MPI_Comm comm, int *status);
OMPI_DECLSPEC  R_MPI_Fint R_MPI_Type_c2f(R_MPI_Datatype datatype);
OMPI_DECLSPEC  int R_MPI_Type_commit(R_MPI_Datatype *type);
OMPI_DECLSPEC  int R_MPI_Type_contiguous(int count, R_MPI_Datatype oldtype,
                                       R_MPI_Datatype *newtype);
OMPI_DECLSPEC  int R_MPI_Type_create_darray(int size, int rank, int ndims,
                                          int gsize_array[], int distrib_array[],
                                          int darg_array[], int psize_array[],
                                          int order, R_MPI_Datatype oldtype,
                                          R_MPI_Datatype *newtype);
OMPI_DECLSPEC  int R_MPI_Type_create_f90_complex(int p, int r, R_MPI_Datatype *newtype);
OMPI_DECLSPEC  int R_MPI_Type_create_f90_integer(int r, R_MPI_Datatype *newtype);
OMPI_DECLSPEC  int R_MPI_Type_create_f90_real(int p, int r, R_MPI_Datatype *newtype);
OMPI_DECLSPEC  int R_MPI_Type_create_hindexed(int count, int array_of_blocklengths[],
                                            R_MPI_Aint array_of_displacements[],
                                            R_MPI_Datatype oldtype,
                                            R_MPI_Datatype *newtype);
OMPI_DECLSPEC  int R_MPI_Type_create_hvector(int count, int blocklength, R_MPI_Aint stride,
                                           R_MPI_Datatype oldtype,
                                           R_MPI_Datatype *newtype);
OMPI_DECLSPEC  int R_MPI_Type_create_keyval(R_MPI_Type_copy_attr_function *type_copy_attr_fn,
                                          R_MPI_Type_delete_attr_function *type_delete_attr_fn,
                                          int *type_keyval, void *extra_state);
OMPI_DECLSPEC  int R_MPI_Type_create_indexed_block(int count, int blocklength,
                                                 int array_of_displacements[],
                                                 R_MPI_Datatype oldtype,
                                                 R_MPI_Datatype *newtype);
OMPI_DECLSPEC  int R_MPI_Type_create_struct(int count, int array_of_block_lengths[],
                                          R_MPI_Aint array_of_displacements[],
                                          R_MPI_Datatype array_of_types[],
                                          R_MPI_Datatype *newtype);
OMPI_DECLSPEC  int R_MPI_Type_create_subarray(int ndims, int size_array[], int subsize_array[],
                                            int start_array[], int order,
                                            R_MPI_Datatype oldtype, R_MPI_Datatype *newtype);
OMPI_DECLSPEC  int R_MPI_Type_create_resized(R_MPI_Datatype oldtype, R_MPI_Aint lb,
                                           R_MPI_Aint extent, R_MPI_Datatype *newtype);
OMPI_DECLSPEC  int R_MPI_Type_delete_attr(R_MPI_Datatype type, int type_keyval);
OMPI_DECLSPEC  int R_MPI_Type_dup(R_MPI_Datatype type, R_MPI_Datatype *newtype);
OMPI_DECLSPEC  int R_MPI_Type_extent(R_MPI_Datatype type, R_MPI_Aint *extent)
                                   __mpi_interface_deprecated__("R_MPI_Type_extent is superseded by R_MPI_Type_get_extent in MPI-2.0");
OMPI_DECLSPEC  int R_MPI_Type_free(R_MPI_Datatype *type);
OMPI_DECLSPEC  int R_MPI_Type_free_keyval(int *type_keyval);
OMPI_DECLSPEC  R_MPI_Datatype R_MPI_Type_f2c(R_MPI_Fint datatype);
OMPI_DECLSPEC  int R_MPI_Type_get_attr(R_MPI_Datatype type, int type_keyval,
                                     void *attribute_val, int *flag);
OMPI_DECLSPEC  int R_MPI_Type_get_contents(R_MPI_Datatype mtype, int max_integers,
                                         int max_addresses, int max_datatypes,
                                         int array_of_integers[],
                                         R_MPI_Aint array_of_addresses[],
                                         R_MPI_Datatype array_of_datatypes[]);
OMPI_DECLSPEC  int R_MPI_Type_get_envelope(R_MPI_Datatype type, int *num_integers,
                                         int *num_addresses, int *num_datatypes,
                                         int *combiner);
OMPI_DECLSPEC  int R_MPI_Type_get_extent(R_MPI_Datatype type, R_MPI_Aint *lb,
                                       R_MPI_Aint *extent);
OMPI_DECLSPEC  int R_MPI_Type_get_name(R_MPI_Datatype type, char *type_name,
                                     int *resultlen);
OMPI_DECLSPEC  int R_MPI_Type_get_true_extent(R_MPI_Datatype datatype, R_MPI_Aint *true_lb,
                                            R_MPI_Aint *true_extent);
OMPI_DECLSPEC  int R_MPI_Type_hindexed(int count, int array_of_blocklengths[],
                                     R_MPI_Aint array_of_displacements[],
                                     R_MPI_Datatype oldtype, R_MPI_Datatype *newtype)
                                     __mpi_interface_deprecated__("R_MPI_Type_hindexed is superseded by R_MPI_Type_create_hindexed in MPI-2.0");
OMPI_DECLSPEC  int R_MPI_Type_hvector(int count, int blocklength, R_MPI_Aint stride,
                                    R_MPI_Datatype oldtype, R_MPI_Datatype *newtype)
                                    __mpi_interface_deprecated__("R_MPI_Type_hvector is superseded by R_MPI_Type_create_hvector in MPI-2.0");
OMPI_DECLSPEC  int R_MPI_Type_indexed(int count, int array_of_blocklengths[],
                                    int array_of_displacements[],
                                    R_MPI_Datatype oldtype, R_MPI_Datatype *newtype);
OMPI_DECLSPEC  int R_MPI_Type_lb(R_MPI_Datatype type, R_MPI_Aint *lb)
                               __mpi_interface_deprecated__("R_MPI_Type_lb is deprecated, use R_MPI_Type_get_extent in MPI-2.0");
OMPI_DECLSPEC  int R_MPI_Type_match_size(int typeclass, int size, R_MPI_Datatype *type);
OMPI_DECLSPEC  int R_MPI_Type_set_attr(R_MPI_Datatype type, int type_keyval,
                                     void *attr_val);
OMPI_DECLSPEC  int R_MPI_Type_set_name(R_MPI_Datatype type, char *type_name);
OMPI_DECLSPEC  int R_MPI_Type_size(R_MPI_Datatype type, int *size);
OMPI_DECLSPEC  int R_MPI_Type_struct(int count, int array_of_blocklengths[],
                                   R_MPI_Aint array_of_displacements[],
                                   R_MPI_Datatype array_of_types[],
                                   R_MPI_Datatype *newtype)
                                   __mpi_interface_deprecated__("R_MPI_Type_struct is superseded by R_MPI_Type_create_struct in MPI-2.0");
OMPI_DECLSPEC  int R_MPI_Type_ub(R_MPI_Datatype mtype, R_MPI_Aint *ub)
                               __mpi_interface_deprecated__("R_MPI_Type_ub is deprecated, use R_MPI_Type_get_extent in MPI-2.0");
OMPI_DECLSPEC  int R_MPI_Type_vector(int count, int blocklength, int stride,
                                   R_MPI_Datatype oldtype, R_MPI_Datatype *newtype);
OMPI_DECLSPEC  int R_MPI_Unpack(void *inbuf, int insize, int *position,
                              void *outbuf, int outcount, R_MPI_Datatype datatype,
                              R_MPI_Comm comm);
OMPI_DECLSPEC  int R_MPI_Unpublish_name(char *service_name, R_MPI_Info info, char *port_name);
OMPI_DECLSPEC  int R_MPI_Unpack_external (char *datarep, void *inbuf, R_MPI_Aint insize,
                                        R_MPI_Aint *position, void *outbuf, int outcount,
                                        R_MPI_Datatype datatype);
OMPI_DECLSPEC  int R_MPI_Waitall(int count, R_MPI_Request *array_of_requests,
                               R_MPI_Status *array_of_statuses);
OMPI_DECLSPEC  int R_MPI_Waitany(int count, R_MPI_Request *array_of_requests,
                               int *index, R_MPI_Status *status);
OMPI_DECLSPEC  int R_MPI_Wait(R_MPI_Request *request, R_MPI_Status *status);
OMPI_DECLSPEC  int R_MPI_Waitsome(int incount, R_MPI_Request *array_of_requests,
                                int *outcount, int *array_of_indices,
                                R_MPI_Status *array_of_statuses);
OMPI_DECLSPEC  R_MPI_Fint R_MPI_Win_c2f(R_MPI_Win win);
OMPI_DECLSPEC  int R_MPI_Win_call_errhandler(R_MPI_Win win, int errorcode);
OMPI_DECLSPEC  int R_MPI_Win_complete(R_MPI_Win win);
OMPI_DECLSPEC  int R_MPI_Win_create(void *base, R_MPI_Aint size, int disp_unit,
                                  R_MPI_Info info, R_MPI_Comm comm, R_MPI_Win *win);
OMPI_DECLSPEC  int R_MPI_Win_create_errhandler(R_MPI_Win_errhandler_function *function,
                                             R_MPI_Errhandler *errhandler);
OMPI_DECLSPEC  int R_MPI_Win_create_keyval(R_MPI_Win_copy_attr_function *win_copy_attr_fn,
                                         R_MPI_Win_delete_attr_function *win_delete_attr_fn,
                                         int *win_keyval, void *extra_state);
OMPI_DECLSPEC  int R_MPI_Win_delete_attr(R_MPI_Win win, int win_keyval);
OMPI_DECLSPEC  R_MPI_Win R_MPI_Win_f2c(R_MPI_Fint win);
OMPI_DECLSPEC  int R_MPI_Win_fence(int assert, R_MPI_Win win);
OMPI_DECLSPEC  int R_MPI_Win_free(R_MPI_Win *win);
OMPI_DECLSPEC  int R_MPI_Win_free_keyval(int *win_keyval);
OMPI_DECLSPEC  int R_MPI_Win_get_attr(R_MPI_Win win, int win_keyval,
                                    void *attribute_val, int *flag);
OMPI_DECLSPEC  int R_MPI_Win_get_errhandler(R_MPI_Win win, R_MPI_Errhandler *errhandler);
OMPI_DECLSPEC  int R_MPI_Win_get_group(R_MPI_Win win, R_MPI_Group *group);
OMPI_DECLSPEC  int R_MPI_Win_get_name(R_MPI_Win win, char *win_name, int *resultlen);
OMPI_DECLSPEC  int R_MPI_Win_lock(int lock_type, int rank, int assert, R_MPI_Win win);
OMPI_DECLSPEC  int R_MPI_Win_post(R_MPI_Group group, int assert, R_MPI_Win win);
OMPI_DECLSPEC  int R_MPI_Win_set_attr(R_MPI_Win win, int win_keyval, void *attribute_val);
OMPI_DECLSPEC  int R_MPI_Win_set_errhandler(R_MPI_Win win, R_MPI_Errhandler errhandler);
OMPI_DECLSPEC  int R_MPI_Win_set_name(R_MPI_Win win, char *win_name);
OMPI_DECLSPEC  int R_MPI_Win_start(R_MPI_Group group, int assert, R_MPI_Win win);
OMPI_DECLSPEC  int R_MPI_Win_test(R_MPI_Win win, int *flag);
OMPI_DECLSPEC  int R_MPI_Win_unlock(int rank, R_MPI_Win win);
OMPI_DECLSPEC  int R_MPI_Win_wait(R_MPI_Win win);
OMPI_DECLSPEC  double R_MPI_Wtick(void);
OMPI_DECLSPEC  double R_MPI_Wtime(void);


  /*
   * Profiling MPI API
   */
OMPI_DECLSPEC  int R_PMPI_Abort(R_MPI_Comm comm, int errorcode);
OMPI_DECLSPEC  int R_PMPI_Accumulate(void *origin_addr, int origin_count, R_MPI_Datatype origin_datatype,
                                   int target_rank, R_MPI_Aint target_disp, int target_count,
                                   R_MPI_Datatype target_datatype, R_MPI_Op op, R_MPI_Win win);
OMPI_DECLSPEC  int R_PMPI_Add_error_class(int *errorclass);
OMPI_DECLSPEC  int R_PMPI_Add_error_code(int errorclass, int *errorcode);
OMPI_DECLSPEC  int R_PMPI_Add_error_string(int errorcode, char *string);
OMPI_DECLSPEC  int R_PMPI_Address(void *location, R_MPI_Aint *address)
                                __mpi_interface_deprecated__("R_MPI_Address is superseded by R_MPI_Get_address in MPI-2.0");
OMPI_DECLSPEC  int R_PMPI_Allgather(void *sendbuf, int sendcount, R_MPI_Datatype sendtype,
                                  void *recvbuf, int recvcount,
                                  R_MPI_Datatype recvtype, R_MPI_Comm comm);
OMPI_DECLSPEC  int R_PMPI_Allgatherv(void *sendbuf, int sendcount, R_MPI_Datatype sendtype,
                                   void *recvbuf, int *recvcounts,
                                   int *displs, R_MPI_Datatype recvtype, R_MPI_Comm comm);
OMPI_DECLSPEC  int R_PMPI_Alloc_mem(R_MPI_Aint size, R_MPI_Info info,
                                  void *baseptr);
OMPI_DECLSPEC  int R_PMPI_Allreduce(void *sendbuf, void *recvbuf, int count,
                                  R_MPI_Datatype datatype, R_MPI_Op op, R_MPI_Comm comm);
OMPI_DECLSPEC  int R_PMPI_Alltoall(void *sendbuf, int sendcount, R_MPI_Datatype sendtype,
                                 void *recvbuf, int recvcount,
                                 R_MPI_Datatype recvtype, R_MPI_Comm comm);
OMPI_DECLSPEC  int R_PMPI_Alltoallv(void *sendbuf, int *sendcounts, int *sdispls,
                                  R_MPI_Datatype sendtype, void *recvbuf, int *recvcounts,
                                  int *rdispls, R_MPI_Datatype recvtype, R_MPI_Comm comm);
OMPI_DECLSPEC  int R_PMPI_Alltoallw(void *sendbuf, int *sendcounts, int *sdispls, R_MPI_Datatype *sendtypes,
                                  void *recvbuf, int *recvcounts, int *rdispls, R_MPI_Datatype *recvtypes,
                                  R_MPI_Comm comm);
OMPI_DECLSPEC  int R_PMPI_Attr_delete(R_MPI_Comm comm, int keyval)
                                    __mpi_interface_deprecated__("R_MPI_Attr_delete is superseded by R_MPI_Comm_delete_attr in MPI-2.0");
OMPI_DECLSPEC  int R_PMPI_Attr_get(R_MPI_Comm comm, int keyval, void *attribute_val, int *flag)
                                 __mpi_interface_deprecated__("R_MPI_Attr_get is superseded by R_MPI_Comm_get_attr in MPI-2.0");
OMPI_DECLSPEC  int R_PMPI_Attr_put(R_MPI_Comm comm, int keyval, void *attribute_val)
                                 __mpi_interface_deprecated__("R_MPI_Attr_put is superseded by R_MPI_Comm_set_attr in MPI-2.0");
OMPI_DECLSPEC  int R_PMPI_Barrier(R_MPI_Comm comm);
OMPI_DECLSPEC  int R_PMPI_Bcast(void *buffer, int count, R_MPI_Datatype datatype,
                              int root, R_MPI_Comm comm);
OMPI_DECLSPEC  int R_PMPI_Bsend(void *buf, int count, R_MPI_Datatype datatype,
                              int dest, int tag, R_MPI_Comm comm);
OMPI_DECLSPEC  int R_PMPI_Bsend_init(void *buf, int count, R_MPI_Datatype datatype,
                                   int dest, int tag, R_MPI_Comm comm, R_MPI_Request *request);
OMPI_DECLSPEC  int R_PMPI_Buffer_attach(void *buffer, int size);
OMPI_DECLSPEC  int R_PMPI_Buffer_detach(void *buffer, int *size);
OMPI_DECLSPEC  int R_PMPI_Cancel(R_MPI_Request *request);
OMPI_DECLSPEC  int R_PMPI_Cart_coords(R_MPI_Comm comm, int rank, int maxdims, int *coords);
OMPI_DECLSPEC  int R_PMPI_Cart_create(R_MPI_Comm old_comm, int ndims, int *dims,
                                    int *periods, int reorder, R_MPI_Comm *comm_cart);
OMPI_DECLSPEC  int R_PMPI_Cart_get(R_MPI_Comm comm, int maxdims, int *dims,
                                 int *periods, int *coords);
OMPI_DECLSPEC  int R_PMPI_Cart_map(R_MPI_Comm comm, int ndims, int *dims,
                                 int *periods, int *newrank);
OMPI_DECLSPEC  int R_PMPI_Cart_rank(R_MPI_Comm comm, int *coords, int *rank);
OMPI_DECLSPEC  int R_PMPI_Cart_shift(R_MPI_Comm comm, int direction, int disp,
                                   int *rank_source, int *rank_dest);
OMPI_DECLSPEC  int R_PMPI_Cart_sub(R_MPI_Comm comm, int *remain_dims, R_MPI_Comm *new_comm);
OMPI_DECLSPEC  int R_PMPI_Cartdim_get(R_MPI_Comm comm, int *ndims);
OMPI_DECLSPEC  int R_PMPI_Close_port(char *port_name);
OMPI_DECLSPEC  int R_PMPI_Comm_accept(char *port_name, R_MPI_Info info, int root,
                                    R_MPI_Comm comm, R_MPI_Comm *newcomm);
OMPI_DECLSPEC  R_MPI_Fint R_PMPI_Comm_c2f(R_MPI_Comm comm);
OMPI_DECLSPEC  int R_PMPI_Comm_call_errhandler(R_MPI_Comm comm, int errorcode);
OMPI_DECLSPEC  int R_PMPI_Comm_compare(R_MPI_Comm comm1, R_MPI_Comm comm2, int *result);
OMPI_DECLSPEC  int R_PMPI_Comm_connect(char *port_name, R_MPI_Info info, int root,
                                     R_MPI_Comm comm, R_MPI_Comm *newcomm);
OMPI_DECLSPEC  int R_PMPI_Comm_create_errhandler(R_MPI_Comm_errhandler_function *function,
                                               R_MPI_Errhandler *errhandler);
OMPI_DECLSPEC  int R_PMPI_Comm_create_keyval(R_MPI_Comm_copy_attr_function *comm_copy_attr_fn,
                                           R_MPI_Comm_delete_attr_function *comm_delete_attr_fn,
                                           int *comm_keyval, void *extra_state);
OMPI_DECLSPEC  int R_PMPI_Comm_create(R_MPI_Comm comm, R_MPI_Group group, R_MPI_Comm *newcomm);
OMPI_DECLSPEC  int R_PMPI_Comm_delete_attr(R_MPI_Comm comm, int comm_keyval);
OMPI_DECLSPEC  int R_PMPI_Comm_disconnect(R_MPI_Comm *comm);
OMPI_DECLSPEC  int R_PMPI_Comm_dup(R_MPI_Comm comm, R_MPI_Comm *newcomm);
OMPI_DECLSPEC  R_MPI_Comm R_PMPI_Comm_f2c(R_MPI_Fint comm);
OMPI_DECLSPEC  int R_PMPI_Comm_free_keyval(int *comm_keyval);
OMPI_DECLSPEC  int R_PMPI_Comm_free(R_MPI_Comm *comm);
OMPI_DECLSPEC  int R_PMPI_Comm_get_attr(R_MPI_Comm comm, int comm_keyval,
                                      void *attribute_val, int *flag);
OMPI_DECLSPEC  int R_PMPI_Comm_get_errhandler(R_MPI_Comm comm, R_MPI_Errhandler *erhandler);
OMPI_DECLSPEC  int R_PMPI_Comm_get_name(R_MPI_Comm comm, char *comm_name, int *resultlen);
OMPI_DECLSPEC  int R_PMPI_Comm_get_parent(R_MPI_Comm *parent);
OMPI_DECLSPEC  int R_PMPI_Comm_group(R_MPI_Comm comm, R_MPI_Group *group);
OMPI_DECLSPEC  int R_PMPI_Comm_join(int fd, R_MPI_Comm *intercomm);
OMPI_DECLSPEC  int R_PMPI_Comm_rank(R_MPI_Comm comm, int *rank);
OMPI_DECLSPEC  int R_PMPI_Comm_remote_group(R_MPI_Comm comm, R_MPI_Group *group);
OMPI_DECLSPEC  int R_PMPI_Comm_remote_size(R_MPI_Comm comm, int *size);
OMPI_DECLSPEC  int R_PMPI_Comm_set_attr(R_MPI_Comm comm, int comm_keyval, void *attribute_val);
OMPI_DECLSPEC  int R_PMPI_Comm_set_errhandler(R_MPI_Comm comm, R_MPI_Errhandler errhandler);
OMPI_DECLSPEC  int R_PMPI_Comm_set_name(R_MPI_Comm comm, char *comm_name);
OMPI_DECLSPEC  int R_PMPI_Comm_size(R_MPI_Comm comm, int *size);
OMPI_DECLSPEC  int R_PMPI_Comm_spawn(char *command, char **argv, int maxprocs, R_MPI_Info info,
                                   int root, R_MPI_Comm comm, R_MPI_Comm *intercomm,
                                   int *array_of_errcodes);
OMPI_DECLSPEC  int R_PMPI_Comm_spawn_multiple(int count, char **array_of_commands, char ***array_of_argv,
                                            int *array_of_maxprocs, R_MPI_Info *array_of_info,
                                            int root, R_MPI_Comm comm, R_MPI_Comm *intercomm,
                                            int *array_of_errcodes);
OMPI_DECLSPEC  int R_PMPI_Comm_split(R_MPI_Comm comm, int color, int key, R_MPI_Comm *newcomm);
OMPI_DECLSPEC  int R_PMPI_Comm_test_inter(R_MPI_Comm comm, int *flag);
OMPI_DECLSPEC  int R_PMPI_Dims_create(int nnodes, int ndims, int *dims);
OMPI_DECLSPEC  R_MPI_Fint R_PMPI_Errhandler_c2f(R_MPI_Errhandler errhandler);
OMPI_DECLSPEC  int R_PMPI_Errhandler_create(R_MPI_Handler_function *function,
                                          R_MPI_Errhandler *errhandler)
                                          __mpi_interface_deprecated__("R_MPI_Errhandler_create is superseded by R_MPI_Comm_create_errhandler in MPI-2.0");
OMPI_DECLSPEC  R_MPI_Errhandler R_PMPI_Errhandler_f2c(R_MPI_Fint errhandler);
OMPI_DECLSPEC  int R_PMPI_Errhandler_free(R_MPI_Errhandler *errhandler);
OMPI_DECLSPEC  int R_PMPI_Errhandler_get(R_MPI_Comm comm, R_MPI_Errhandler *errhandler)
                                       __mpi_interface_deprecated__("R_MPI_Errhandler_get is superseded by R_MPI_Comm_get_errhandler in MPI-2.0");
OMPI_DECLSPEC  int R_PMPI_Errhandler_set(R_MPI_Comm comm, R_MPI_Errhandler errhandler)
                                       __mpi_interface_deprecated__("R_MPI_Errhandler_set is superseded by R_MPI_Comm_set_errhandler in MPI-2.0");
OMPI_DECLSPEC  int R_PMPI_Error_class(int errorcode, int *errorclass);
OMPI_DECLSPEC  int R_PMPI_Error_string(int errorcode, char *string, int *resultlen);
OMPI_DECLSPEC  int R_PMPI_Exscan(void *sendbuf, void *recvbuf, int count,
                               R_MPI_Datatype datatype, R_MPI_Op op, R_MPI_Comm comm);
#if OMPI_PROVIDE_R_MPI_FILE_INTERFACE
OMPI_DECLSPEC  R_MPI_Fint R_PMPI_File_c2f(R_MPI_File file);
OMPI_DECLSPEC  R_MPI_File R_PMPI_File_f2c(R_MPI_Fint file);
OMPI_DECLSPEC  int R_PMPI_File_call_errhandler(R_MPI_File fh, int errorcode);
OMPI_DECLSPEC  int R_PMPI_File_create_errhandler(R_MPI_File_errhandler_function *function,
                                               R_MPI_Errhandler *errhandler);
OMPI_DECLSPEC  int R_PMPI_File_set_errhandler( R_MPI_File file, R_MPI_Errhandler errhandler);
OMPI_DECLSPEC  int R_PMPI_File_get_errhandler( R_MPI_File file, R_MPI_Errhandler *errhandler);
OMPI_DECLSPEC  int R_PMPI_File_open(R_MPI_Comm comm, char *filename, int amode,
                                  R_MPI_Info info, R_MPI_File *fh);
OMPI_DECLSPEC  int R_PMPI_File_close(R_MPI_File *fh);
OMPI_DECLSPEC  int R_PMPI_File_delete(char *filename, R_MPI_Info info);
OMPI_DECLSPEC  int R_PMPI_File_set_size(R_MPI_File fh, R_MPI_Offset size);
OMPI_DECLSPEC  int R_PMPI_File_preallocate(R_MPI_File fh, R_MPI_Offset size);
OMPI_DECLSPEC  int R_PMPI_File_get_size(R_MPI_File fh, R_MPI_Offset *size);
OMPI_DECLSPEC  int R_PMPI_File_get_group(R_MPI_File fh, R_MPI_Group *group);
OMPI_DECLSPEC  int R_PMPI_File_get_amode(R_MPI_File fh, int *amode);
OMPI_DECLSPEC  int R_PMPI_File_set_info(R_MPI_File fh, R_MPI_Info info);
OMPI_DECLSPEC  int R_PMPI_File_get_info(R_MPI_File fh, R_MPI_Info *info_used);
OMPI_DECLSPEC  int R_PMPI_File_set_view(R_MPI_File fh, R_MPI_Offset disp, R_MPI_Datatype etype,
                                      R_MPI_Datatype filetype, char *datarep, R_MPI_Info info);
OMPI_DECLSPEC  int R_PMPI_File_get_view(R_MPI_File fh, R_MPI_Offset *disp,
                                      R_MPI_Datatype *etype,
                                      R_MPI_Datatype *filetype, char *datarep);
OMPI_DECLSPEC  int R_PMPI_File_read_at(R_MPI_File fh, R_MPI_Offset offset, void *buf,
                                     int count, R_MPI_Datatype datatype, R_MPI_Status *status);
OMPI_DECLSPEC  int R_PMPI_File_read_at_all(R_MPI_File fh, R_MPI_Offset offset, void *buf,
                                         int count, R_MPI_Datatype datatype, R_MPI_Status *status);
OMPI_DECLSPEC  int R_PMPI_File_write_at(R_MPI_File fh, R_MPI_Offset offset, void *buf,
                                      int count, R_MPI_Datatype datatype, R_MPI_Status *status);
OMPI_DECLSPEC  int R_PMPI_File_write_at_all(R_MPI_File fh, R_MPI_Offset offset, void *buf,
                                          int count, R_MPI_Datatype datatype, R_MPI_Status *status);
OMPI_DECLSPEC  int R_PMPI_File_iread_at(R_MPI_File fh, R_MPI_Offset offset, void *buf,
                                      int count, R_MPI_Datatype datatype, R_MPI_Request *request);
OMPI_DECLSPEC  int R_PMPI_File_iwrite_at(R_MPI_File fh, R_MPI_Offset offset, void *buf,
                                       int count, R_MPI_Datatype datatype, R_MPI_Request *request);
OMPI_DECLSPEC  int R_PMPI_File_read(R_MPI_File fh, void *buf, int count,
                                  R_MPI_Datatype datatype, R_MPI_Status *status);
OMPI_DECLSPEC  int R_PMPI_File_read_all(R_MPI_File fh, void *buf, int count,
                                      R_MPI_Datatype datatype, R_MPI_Status *status);
OMPI_DECLSPEC  int R_PMPI_File_write(R_MPI_File fh, void *buf, int count,
                                   R_MPI_Datatype datatype, R_MPI_Status *status);
OMPI_DECLSPEC  int R_PMPI_File_write_all(R_MPI_File fh, void *buf, int count,
                                       R_MPI_Datatype datatype, R_MPI_Status *status);
OMPI_DECLSPEC  int R_PMPI_File_iread(R_MPI_File fh, void *buf, int count,
                                   R_MPI_Datatype datatype, R_MPI_Request *request);
OMPI_DECLSPEC  int R_PMPI_File_iwrite(R_MPI_File fh, void *buf, int count,
                                    R_MPI_Datatype datatype, R_MPI_Request *request);
OMPI_DECLSPEC  int R_PMPI_File_seek(R_MPI_File fh, R_MPI_Offset offset, int whence);
OMPI_DECLSPEC  int R_PMPI_File_get_position(R_MPI_File fh, R_MPI_Offset *offset);
OMPI_DECLSPEC  int R_PMPI_File_get_byte_offset(R_MPI_File fh, R_MPI_Offset offset,
                                             R_MPI_Offset *disp);
OMPI_DECLSPEC  int R_PMPI_File_read_shared(R_MPI_File fh, void *buf, int count,
                                         R_MPI_Datatype datatype, R_MPI_Status *status);
OMPI_DECLSPEC  int R_PMPI_File_write_shared(R_MPI_File fh, void *buf, int count,
                                          R_MPI_Datatype datatype, R_MPI_Status *status);
OMPI_DECLSPEC  int R_PMPI_File_iread_shared(R_MPI_File fh, void *buf, int count,
                                          R_MPI_Datatype datatype, R_MPI_Request *request);
OMPI_DECLSPEC  int R_PMPI_File_iwrite_shared(R_MPI_File fh, void *buf, int count,
                                           R_MPI_Datatype datatype, R_MPI_Request *request);
OMPI_DECLSPEC  int R_PMPI_File_read_ordered(R_MPI_File fh, void *buf, int count,
                                          R_MPI_Datatype datatype, R_MPI_Status *status);
OMPI_DECLSPEC  int R_PMPI_File_write_ordered(R_MPI_File fh, void *buf, int count,
                                           R_MPI_Datatype datatype, R_MPI_Status *status);
OMPI_DECLSPEC  int R_PMPI_File_seek_shared(R_MPI_File fh, R_MPI_Offset offset, int whence);
OMPI_DECLSPEC  int R_PMPI_File_get_position_shared(R_MPI_File fh, R_MPI_Offset *offset);
OMPI_DECLSPEC  int R_PMPI_File_read_at_all_begin(R_MPI_File fh, R_MPI_Offset offset, void *buf,
                                               int count, R_MPI_Datatype datatype);
OMPI_DECLSPEC  int R_PMPI_File_read_at_all_end(R_MPI_File fh, void *buf, R_MPI_Status *status);
OMPI_DECLSPEC  int R_PMPI_File_write_at_all_begin(R_MPI_File fh, R_MPI_Offset offset, void *buf,
                                                int count, R_MPI_Datatype datatype);
OMPI_DECLSPEC  int R_PMPI_File_write_at_all_end(R_MPI_File fh, void *buf, R_MPI_Status *status);
OMPI_DECLSPEC  int R_PMPI_File_read_all_begin(R_MPI_File fh, void *buf, int count,
                                            R_MPI_Datatype datatype);
OMPI_DECLSPEC  int R_PMPI_File_read_all_end(R_MPI_File fh, void *buf, R_MPI_Status *status);
OMPI_DECLSPEC  int R_PMPI_File_write_all_begin(R_MPI_File fh, void *buf, int count,
                                             R_MPI_Datatype datatype);
OMPI_DECLSPEC  int R_PMPI_File_write_all_end(R_MPI_File fh, void *buf, R_MPI_Status *status);
OMPI_DECLSPEC  int R_PMPI_File_read_ordered_begin(R_MPI_File fh, void *buf, int count,
                                                R_MPI_Datatype datatype);
OMPI_DECLSPEC  int R_PMPI_File_read_ordered_end(R_MPI_File fh, void *buf, R_MPI_Status *status);
OMPI_DECLSPEC  int R_PMPI_File_write_ordered_begin(R_MPI_File fh, void *buf, int count,
                                                 R_MPI_Datatype datatype);
OMPI_DECLSPEC  int R_PMPI_File_write_ordered_end(R_MPI_File fh, void *buf, R_MPI_Status *status);
OMPI_DECLSPEC  int R_PMPI_File_get_type_extent(R_MPI_File fh, R_MPI_Datatype datatype,
                                             R_MPI_Aint *extent);
OMPI_DECLSPEC  int R_PMPI_File_set_atomicity(R_MPI_File fh, int flag);
OMPI_DECLSPEC  int R_PMPI_File_get_atomicity(R_MPI_File fh, int *flag);
OMPI_DECLSPEC  int R_PMPI_File_sync(R_MPI_File fh);
#endif /* #if OMPI_PROVIDE_R_MPI_FILE_INTERFACE */
OMPI_DECLSPEC  int R_PMPI_Finalize(void);
OMPI_DECLSPEC  int R_PMPI_Finalized(int *flag);
OMPI_DECLSPEC  int R_PMPI_Free_mem(void *base);
OMPI_DECLSPEC  int R_PMPI_Gather(void *sendbuf, int sendcount, R_MPI_Datatype sendtype,
                               void *recvbuf, int recvcount, R_MPI_Datatype recvtype,
                               int root, R_MPI_Comm comm);
OMPI_DECLSPEC  int R_PMPI_Gatherv(void *sendbuf, int sendcount, R_MPI_Datatype sendtype,
                                void *recvbuf, int *recvcounts, int *displs,
                                R_MPI_Datatype recvtype, int root, R_MPI_Comm comm);
OMPI_DECLSPEC  int R_PMPI_Get_address(void *location, R_MPI_Aint *address);
OMPI_DECLSPEC  int R_PMPI_Get_count(R_MPI_Status *status, R_MPI_Datatype datatype, int *count);
OMPI_DECLSPEC  int R_PMPI_Get_elements(R_MPI_Status *status, R_MPI_Datatype datatype,
                                     int *count);
OMPI_DECLSPEC  int R_PMPI_Get(void *origin_addr, int origin_count,
                            R_MPI_Datatype origin_datatype, int target_rank,
                            R_MPI_Aint target_disp, int target_count,
                            R_MPI_Datatype target_datatype, R_MPI_Win win);
OMPI_DECLSPEC  int R_PMPI_Get_processor_name(char *name, int *resultlen);
OMPI_DECLSPEC  int R_PMPI_Get_version(int *version, int *subversion);
OMPI_DECLSPEC  int R_PMPI_Graph_create(R_MPI_Comm comm_old, int nnodes, int *index,
                                     int *edges, int reorder, R_MPI_Comm *comm_graph);
OMPI_DECLSPEC  int R_PMPI_Graph_get(R_MPI_Comm comm, int maxindex, int maxedges,
                                  int *index, int *edges);
OMPI_DECLSPEC  int R_PMPI_Graph_map(R_MPI_Comm comm, int nnodes, int *index, int *edges,
                                  int *newrank);
OMPI_DECLSPEC  int R_PMPI_Graph_neighbors_count(R_MPI_Comm comm, int rank, int *nneighbors);
OMPI_DECLSPEC  int R_PMPI_Graph_neighbors(R_MPI_Comm comm, int rank, int maxneighbors,
                                        int *neighbors);
OMPI_DECLSPEC  int R_PMPI_Graphdims_get(R_MPI_Comm comm, int *nnodes, int *nedges);
OMPI_DECLSPEC  int R_PMPI_Grequest_complete(R_MPI_Request request);
OMPI_DECLSPEC  int R_PMPI_Grequest_start(R_MPI_Grequest_query_function *query_fn,
                                       R_MPI_Grequest_free_function *free_fn,
                                       R_MPI_Grequest_cancel_function *cancel_fn,
                                       void *extra_state, R_MPI_Request *request);
OMPI_DECLSPEC  R_MPI_Fint R_PMPI_Group_c2f(R_MPI_Group group);
OMPI_DECLSPEC  int R_PMPI_Group_compare(R_MPI_Group group1, R_MPI_Group group2, int *result);
OMPI_DECLSPEC  int R_PMPI_Group_difference(R_MPI_Group group1, R_MPI_Group group2,
                                         R_MPI_Group *newgroup);
OMPI_DECLSPEC  int R_PMPI_Group_excl(R_MPI_Group group, int n, int *ranks,
                                   R_MPI_Group *newgroup);
OMPI_DECLSPEC  R_MPI_Group R_PMPI_Group_f2c(R_MPI_Fint group);
OMPI_DECLSPEC  int R_PMPI_Group_free(R_MPI_Group *group);
OMPI_DECLSPEC  int R_PMPI_Group_incl(R_MPI_Group group, int n, int *ranks,
                                   R_MPI_Group *newgroup);
OMPI_DECLSPEC  int R_PMPI_Group_intersection(R_MPI_Group group1, R_MPI_Group group2,
                                           R_MPI_Group *newgroup);
OMPI_DECLSPEC  int R_PMPI_Group_range_excl(R_MPI_Group group, int n, int ranges[][3],
                                         R_MPI_Group *newgroup);
OMPI_DECLSPEC  int R_PMPI_Group_range_incl(R_MPI_Group group, int n, int ranges[][3],
                                         R_MPI_Group *newgroup);
OMPI_DECLSPEC  int R_PMPI_Group_rank(R_MPI_Group group, int *rank);
OMPI_DECLSPEC  int R_PMPI_Group_size(R_MPI_Group group, int *size);
OMPI_DECLSPEC  int R_PMPI_Group_translate_ranks(R_MPI_Group group1, int n, int *ranks1,
                                              R_MPI_Group group2, int *ranks2);
OMPI_DECLSPEC  int R_PMPI_Group_union(R_MPI_Group group1, R_MPI_Group group2,
                                    R_MPI_Group *newgroup);
OMPI_DECLSPEC  int R_PMPI_Ibsend(void *buf, int count, R_MPI_Datatype datatype, int dest,
                               int tag, R_MPI_Comm comm, R_MPI_Request *request);
OMPI_DECLSPEC  R_MPI_Fint R_PMPI_Info_c2f(R_MPI_Info info);
OMPI_DECLSPEC  int R_PMPI_Info_create(R_MPI_Info *info);
OMPI_DECLSPEC  int R_PMPI_Info_delete(R_MPI_Info info, char *key);
OMPI_DECLSPEC  int R_PMPI_Info_dup(R_MPI_Info info, R_MPI_Info *newinfo);
OMPI_DECLSPEC  R_MPI_Info R_PMPI_Info_f2c(R_MPI_Fint info);
OMPI_DECLSPEC  int R_PMPI_Info_free(R_MPI_Info *info);
OMPI_DECLSPEC  int R_PMPI_Info_get(R_MPI_Info info, char *key, int valuelen,
                                 char *value, int *flag);
OMPI_DECLSPEC  int R_PMPI_Info_get_nkeys(R_MPI_Info info, int *nkeys);
OMPI_DECLSPEC  int R_PMPI_Info_get_nthkey(R_MPI_Info info, int n, char *key);
OMPI_DECLSPEC  int R_PMPI_Info_get_valuelen(R_MPI_Info info, char *key, int *valuelen,
                                          int *flag);
OMPI_DECLSPEC  int R_PMPI_Info_set(R_MPI_Info info, char *key, char *value);
OMPI_DECLSPEC  int R_PMPI_Init(int *argc, char ***argv);
OMPI_DECLSPEC  int R_PMPI_Initialized(int *flag);
OMPI_DECLSPEC  int R_PMPI_Init_thread(int *argc, char ***argv, int required,
                                    int *provided);
OMPI_DECLSPEC  int R_PMPI_Intercomm_create(R_MPI_Comm local_comm, int local_leader,
                                         R_MPI_Comm bridge_comm, int remote_leader,
                                         int tag, R_MPI_Comm *newintercomm);
OMPI_DECLSPEC  int R_PMPI_Intercomm_merge(R_MPI_Comm intercomm, int high,
                                        R_MPI_Comm *newintercomm);
OMPI_DECLSPEC  int R_PMPI_Iprobe(int source, int tag, R_MPI_Comm comm, int *flag,
                               R_MPI_Status *status);
OMPI_DECLSPEC  int R_PMPI_Irecv(void *buf, int count, R_MPI_Datatype datatype, int source,
                              int tag, R_MPI_Comm comm, R_MPI_Request *request);
OMPI_DECLSPEC  int R_PMPI_Irsend(void *buf, int count, R_MPI_Datatype datatype, int dest,
                               int tag, R_MPI_Comm comm, R_MPI_Request *request);
OMPI_DECLSPEC  int R_PMPI_Isend(void *buf, int count, R_MPI_Datatype datatype, int dest,
                              int tag, R_MPI_Comm comm, R_MPI_Request *request);
OMPI_DECLSPEC  int R_PMPI_Issend(void *buf, int count, R_MPI_Datatype datatype, int dest,
                               int tag, R_MPI_Comm comm, R_MPI_Request *request);
OMPI_DECLSPEC  int R_PMPI_Is_thread_main(int *flag);
OMPI_DECLSPEC  int R_PMPI_Keyval_create(R_MPI_Copy_function *copy_fn,
                                      R_MPI_Delete_function *delete_fn,
                                      int *keyval, void *extra_state)
                                      __mpi_interface_deprecated__("R_MPI_Keyval_create is superseded by R_MPI_Comm_create_keyval in MPI-2.0");
OMPI_DECLSPEC  int R_PMPI_Keyval_free(int *keyval)
                                    __mpi_interface_deprecated__("R_MPI_Keyval_free is superseded by R_MPI_Comm_free_keyval in MPI-2.0");
OMPI_DECLSPEC  int R_PMPI_Lookup_name(char *service_name, R_MPI_Info info, char *port_name);
OMPI_DECLSPEC  R_MPI_Fint R_PMPI_Op_c2f(R_MPI_Op op);
OMPI_DECLSPEC  int R_PMPI_Op_commutative(R_MPI_Op op, int *commute);
OMPI_DECLSPEC  int R_PMPI_Op_create(R_MPI_User_function *function, int commute, R_MPI_Op *op);
OMPI_DECLSPEC  int R_PMPI_Open_port(R_MPI_Info info, char *port_name);
OMPI_DECLSPEC  R_MPI_Op R_PMPI_Op_f2c(R_MPI_Fint op);
OMPI_DECLSPEC  int R_PMPI_Op_free(R_MPI_Op *op);
OMPI_DECLSPEC  int R_PMPI_Pack_external(char *datarep, void *inbuf, int incount,
                                      R_MPI_Datatype datatype, void *outbuf,
                                      R_MPI_Aint outsize, R_MPI_Aint *position);
OMPI_DECLSPEC  int R_PMPI_Pack_external_size(char *datarep, int incount,
                                           R_MPI_Datatype datatype, R_MPI_Aint *size);
OMPI_DECLSPEC  int R_PMPI_Pack(void *inbuf, int incount, R_MPI_Datatype datatype,
                             void *outbuf, int outsize, int *position, R_MPI_Comm comm);
OMPI_DECLSPEC  int R_PMPI_Pack_size(int incount, R_MPI_Datatype datatype, R_MPI_Comm comm,
                                  int *size);
OMPI_DECLSPEC  int R_PMPI_Pcontrol(const int level, ...);
OMPI_DECLSPEC  int R_PMPI_Probe(int source, int tag, R_MPI_Comm comm, R_MPI_Status *status);
OMPI_DECLSPEC  int R_PMPI_Publish_name(char *service_name, R_MPI_Info info,
                                     char *port_name);
OMPI_DECLSPEC  int R_PMPI_Put(void *origin_addr, int origin_count, R_MPI_Datatype origin_datatype,
                            int target_rank, R_MPI_Aint target_disp, int target_count,
                            R_MPI_Datatype target_datatype, R_MPI_Win win);
OMPI_DECLSPEC  int R_PMPI_Query_thread(int *provided);
OMPI_DECLSPEC  int R_PMPI_Recv_init(void *buf, int count, R_MPI_Datatype datatype, int source,
                                  int tag, R_MPI_Comm comm, R_MPI_Request *request);
OMPI_DECLSPEC  int R_PMPI_Recv(void *buf, int count, R_MPI_Datatype datatype, int source,
                             int tag, R_MPI_Comm comm, R_MPI_Status *status);
OMPI_DECLSPEC  int R_PMPI_Reduce(void *sendbuf, void *recvbuf, int count,
                               R_MPI_Datatype datatype, R_MPI_Op op, int root, R_MPI_Comm comm);
OMPI_DECLSPEC  int R_PMPI_Reduce_local(void *inbuf, void *inoutbuf, int count,
                                     R_MPI_Datatype datatype, R_MPI_Op);
OMPI_DECLSPEC  int R_PMPI_Reduce_scatter(void *sendbuf, void *recvbuf, int *recvcounts,
                                       R_MPI_Datatype datatype, R_MPI_Op op, R_MPI_Comm comm);
OMPI_DECLSPEC  int R_PMPI_Register_datarep(char *datarep,
                                         R_MPI_Datarep_conversion_function *read_conversion_fn,
                                         R_MPI_Datarep_conversion_function *write_conversion_fn,
                                         R_MPI_Datarep_extent_function *dtype_file_extent_fn,
                                         void *extra_state);
OMPI_DECLSPEC  R_MPI_Fint R_PMPI_Request_c2f(R_MPI_Request request);
OMPI_DECLSPEC  R_MPI_Request R_PMPI_Request_f2c(R_MPI_Fint request);
OMPI_DECLSPEC  int R_PMPI_Request_free(R_MPI_Request *request);
OMPI_DECLSPEC  int R_PMPI_Request_get_status(R_MPI_Request request, int *flag,
                                           R_MPI_Status *status);
OMPI_DECLSPEC  int R_PMPI_Rsend(void *ibuf, int count, R_MPI_Datatype datatype, int dest,
                              int tag, R_MPI_Comm comm);
OMPI_DECLSPEC  int R_PMPI_Rsend_init(void *buf, int count, R_MPI_Datatype datatype,
                                   int dest, int tag, R_MPI_Comm comm,
                                   R_MPI_Request *request);
OMPI_DECLSPEC  int R_PMPI_Scan(void *sendbuf, void *recvbuf, int count,
                             R_MPI_Datatype datatype, R_MPI_Op op, R_MPI_Comm comm);
OMPI_DECLSPEC  int R_PMPI_Scatter(void *sendbuf, int sendcount, R_MPI_Datatype sendtype,
                                void *recvbuf, int recvcount, R_MPI_Datatype recvtype,
                                int root, R_MPI_Comm comm);
OMPI_DECLSPEC  int R_PMPI_Scatterv(void *sendbuf, int *sendcounts, int *displs,
                                 R_MPI_Datatype sendtype, void *recvbuf, int recvcount,
                                 R_MPI_Datatype recvtype, int root, R_MPI_Comm comm);
OMPI_DECLSPEC  int R_PMPI_Send_init(void *buf, int count, R_MPI_Datatype datatype,
                                  int dest, int tag, R_MPI_Comm comm,
                                  R_MPI_Request *request);
OMPI_DECLSPEC  int R_PMPI_Send(void *buf, int count, R_MPI_Datatype datatype, int dest,
                             int tag, R_MPI_Comm comm);
OMPI_DECLSPEC  int R_PMPI_Sendrecv(void *sendbuf, int sendcount, R_MPI_Datatype sendtype,
                                 int dest, int sendtag, void *recvbuf, int recvcount,
                                 R_MPI_Datatype recvtype, int source, int recvtag,
                                 R_MPI_Comm comm,  R_MPI_Status *status);
OMPI_DECLSPEC  int R_PMPI_Sendrecv_replace(void * buf, int count, R_MPI_Datatype datatype,
                                         int dest, int sendtag, int source, int recvtag,
                                         R_MPI_Comm comm, R_MPI_Status *status);
OMPI_DECLSPEC  int R_PMPI_Ssend_init(void *buf, int count, R_MPI_Datatype datatype,
                                   int dest, int tag, R_MPI_Comm comm,
                                   R_MPI_Request *request);
OMPI_DECLSPEC  int R_PMPI_Ssend(void *buf, int count, R_MPI_Datatype datatype, int dest,
                              int tag, R_MPI_Comm comm);
OMPI_DECLSPEC  int R_PMPI_Start(R_MPI_Request *request);
OMPI_DECLSPEC  int R_PMPI_Startall(int count, R_MPI_Request *array_of_requests);
OMPI_DECLSPEC  int R_PMPI_Status_c2f(R_MPI_Status *c_status, R_MPI_Fint *f_status);
OMPI_DECLSPEC  int R_PMPI_Status_f2c(R_MPI_Fint *f_status, R_MPI_Status *c_status);
OMPI_DECLSPEC  int R_PMPI_Status_set_cancelled(R_MPI_Status *status, int flag);
OMPI_DECLSPEC  int R_PMPI_Status_set_elements(R_MPI_Status *status, R_MPI_Datatype datatype,
                                            int count);
OMPI_DECLSPEC  int R_PMPI_Testall(int count, R_MPI_Request array_of_requests[], int *flag,
                                R_MPI_Status array_of_statuses[]);
OMPI_DECLSPEC  int R_PMPI_Testany(int count, R_MPI_Request array_of_requests[], int *index, int *flag, R_MPI_Status *status);
OMPI_DECLSPEC  int R_PMPI_Test(R_MPI_Request *request, int *flag, R_MPI_Status *status);
OMPI_DECLSPEC  int R_PMPI_Test_cancelled(R_MPI_Status *status, int *flag);
OMPI_DECLSPEC  int R_PMPI_Testsome(int incount, R_MPI_Request array_of_requests[],
                                 int *outcount, int array_of_indices[],
                                 R_MPI_Status array_of_statuses[]);
OMPI_DECLSPEC  int R_PMPI_Topo_test(R_MPI_Comm comm, int *status);
OMPI_DECLSPEC  R_MPI_Fint R_PMPI_Type_c2f(R_MPI_Datatype datatype);
OMPI_DECLSPEC  int R_PMPI_Type_commit(R_MPI_Datatype *type);
OMPI_DECLSPEC  int R_PMPI_Type_contiguous(int count, R_MPI_Datatype oldtype,
                                        R_MPI_Datatype *newtype);
OMPI_DECLSPEC  int R_PMPI_Type_create_darray(int size, int rank, int ndims,
                                           int gsize_array[], int distrib_array[],
                                           int darg_array[], int psize_array[],
                                           int order, R_MPI_Datatype oldtype,
                                           R_MPI_Datatype *newtype);
OMPI_DECLSPEC  int R_PMPI_Type_create_f90_complex(int p, int r, R_MPI_Datatype *newtype);
OMPI_DECLSPEC  int R_PMPI_Type_create_f90_integer(int r, R_MPI_Datatype *newtype);
OMPI_DECLSPEC  int R_PMPI_Type_create_f90_real(int p, int r, R_MPI_Datatype *newtype);
OMPI_DECLSPEC  int R_PMPI_Type_create_hindexed(int count, int array_of_blocklengths[],
                                             R_MPI_Aint array_of_displacements[],
                                             R_MPI_Datatype oldtype,
                                             R_MPI_Datatype *newtype);
OMPI_DECLSPEC  int R_PMPI_Type_create_hvector(int count, int blocklength, R_MPI_Aint stride,
                                            R_MPI_Datatype oldtype,
                                            R_MPI_Datatype *newtype);
OMPI_DECLSPEC  int R_PMPI_Type_create_keyval(R_MPI_Type_copy_attr_function *type_copy_attr_fn,
                                           R_MPI_Type_delete_attr_function *type_delete_attr_fn,
                                           int *type_keyval, void *extra_state);
OMPI_DECLSPEC  int R_PMPI_Type_create_indexed_block(int count, int blocklength,
                                                  int array_of_displacements[],
                                                  R_MPI_Datatype oldtype,
                                                  R_MPI_Datatype *newtype);
OMPI_DECLSPEC  int R_PMPI_Type_create_struct(int count, int array_of_block_lengths[],
                                           R_MPI_Aint array_of_displacements[],
                                           R_MPI_Datatype array_of_types[],
                                           R_MPI_Datatype *newtype);
OMPI_DECLSPEC  int R_PMPI_Type_create_subarray(int ndims, int size_array[], int subsize_array[],
                                             int start_array[], int order,
                                             R_MPI_Datatype oldtype, R_MPI_Datatype *newtype);
OMPI_DECLSPEC  int R_PMPI_Type_create_resized(R_MPI_Datatype oldtype, R_MPI_Aint lb,
                                            R_MPI_Aint extent, R_MPI_Datatype *newtype);
OMPI_DECLSPEC  int R_PMPI_Type_delete_attr(R_MPI_Datatype type, int type_keyval);
OMPI_DECLSPEC  int R_PMPI_Type_dup(R_MPI_Datatype type, R_MPI_Datatype *newtype);
OMPI_DECLSPEC  int R_PMPI_Type_extent(R_MPI_Datatype type, R_MPI_Aint *extent)
                                    __mpi_interface_deprecated__("R_MPI_Type_extent is superseded by R_MPI_Type_get_extent in MPI-2.0");
OMPI_DECLSPEC  int R_PMPI_Type_free(R_MPI_Datatype *type);
OMPI_DECLSPEC  int R_PMPI_Type_free_keyval(int *type_keyval);
OMPI_DECLSPEC  R_MPI_Datatype R_PMPI_Type_f2c(R_MPI_Fint datatype);
OMPI_DECLSPEC  int R_PMPI_Type_get_attr(R_MPI_Datatype type, int type_keyval,
                                      void *attribute_val, int *flag);
OMPI_DECLSPEC  int R_PMPI_Type_get_contents(R_MPI_Datatype mtype, int max_integers,
                                          int max_addresses, int max_datatypes,
                                          int array_of_integers[],
                                          R_MPI_Aint array_of_addresses[],
                                          R_MPI_Datatype array_of_datatypes[]);
OMPI_DECLSPEC  int R_PMPI_Type_get_envelope(R_MPI_Datatype type, int *num_integers,
                                          int *num_addresses, int *num_datatypes,
                                          int *combiner);
OMPI_DECLSPEC  int R_PMPI_Type_get_extent(R_MPI_Datatype type, R_MPI_Aint *lb,
                                        R_MPI_Aint *extent);
OMPI_DECLSPEC  int R_PMPI_Type_get_name(R_MPI_Datatype type, char *type_name,
                                      int *resultlen);
OMPI_DECLSPEC  int R_PMPI_Type_get_true_extent(R_MPI_Datatype datatype, R_MPI_Aint *true_lb,
                                             R_MPI_Aint *true_extent);
OMPI_DECLSPEC  int R_PMPI_Type_hindexed(int count, int array_of_blocklengths[],
                                      R_MPI_Aint array_of_displacements[],
                                      R_MPI_Datatype oldtype, R_MPI_Datatype *newtype)
                                      __mpi_interface_deprecated__("R_MPI_Type_hindexed is superseded by R_MPI_Type_create_hindexed in MPI-2.0");
OMPI_DECLSPEC  int R_PMPI_Type_hvector(int count, int blocklength, R_MPI_Aint stride,
                                     R_MPI_Datatype oldtype, R_MPI_Datatype *newtype)
                                     __mpi_interface_deprecated__("R_MPI_Type_hvector is superseded by R_MPI_Type_create_hvector in MPI-2.0");
OMPI_DECLSPEC  int R_PMPI_Type_indexed(int count, int array_of_blocklengths[],
                                     int array_of_displacements[],
                                     R_MPI_Datatype oldtype, R_MPI_Datatype *newtype);
OMPI_DECLSPEC  int R_PMPI_Type_lb(R_MPI_Datatype type, R_MPI_Aint *lb)
                                __mpi_interface_deprecated__("R_MPI_Type_lb is deprecated, use R_MPI_Type_get_extent in MPI-2.0");
OMPI_DECLSPEC  int R_PMPI_Type_match_size(int typeclass, int size, R_MPI_Datatype *type);
OMPI_DECLSPEC  int R_PMPI_Type_set_attr(R_MPI_Datatype type, int type_keyval,
                                      void *attr_val);
OMPI_DECLSPEC  int R_PMPI_Type_set_name(R_MPI_Datatype type, char *type_name);
OMPI_DECLSPEC  int R_PMPI_Type_size(R_MPI_Datatype type, int *size);
OMPI_DECLSPEC  int R_PMPI_Type_struct(int count, int array_of_blocklengths[],
                                    R_MPI_Aint array_of_displacements[],
                                    R_MPI_Datatype array_of_types[],
                                    R_MPI_Datatype *newtype)
                                    __mpi_interface_deprecated__("R_MPI_Type_struct is superseded by R_MPI_Type_create_struct in MPI-2.0");
OMPI_DECLSPEC  int R_PMPI_Type_ub(R_MPI_Datatype mtype, R_MPI_Aint *ub)
                                __mpi_interface_deprecated__("R_MPI_Type_ub is deprecated, use R_MPI_Type_get_extent in MPI-2.0");
OMPI_DECLSPEC  int R_PMPI_Type_vector(int count, int blocklength, int stride,
                                    R_MPI_Datatype oldtype, R_MPI_Datatype *newtype);
OMPI_DECLSPEC  int R_PMPI_Unpack(void *inbuf, int insize, int *position,
                               void *outbuf, int outcount, R_MPI_Datatype datatype,
                               R_MPI_Comm comm);
OMPI_DECLSPEC  int R_PMPI_Unpublish_name(char *service_name, R_MPI_Info info,
                                       char *port_name);
OMPI_DECLSPEC  int R_PMPI_Unpack_external (char *datarep, void *inbuf, R_MPI_Aint insize,
                                         R_MPI_Aint *position, void *outbuf, int outcount,
                                         R_MPI_Datatype datatype);
OMPI_DECLSPEC  int R_PMPI_Waitall(int count, R_MPI_Request *array_of_requests,
                                R_MPI_Status *array_of_statuses);
OMPI_DECLSPEC  int R_PMPI_Waitany(int count, R_MPI_Request *array_of_requests,
                                int *index, R_MPI_Status *status);
OMPI_DECLSPEC  int R_PMPI_Wait(R_MPI_Request *request, R_MPI_Status *status);
OMPI_DECLSPEC  int R_PMPI_Waitsome(int incount, R_MPI_Request *array_of_requests,
                                 int *outcount, int *array_of_indices,
                                 R_MPI_Status *array_of_statuses);
OMPI_DECLSPEC  R_MPI_Fint R_PMPI_Win_c2f(R_MPI_Win win);
OMPI_DECLSPEC  int R_PMPI_Win_call_errhandler(R_MPI_Win win, int errorcode);
OMPI_DECLSPEC  int R_PMPI_Win_complete(R_MPI_Win win);
OMPI_DECLSPEC  int R_PMPI_Win_create(void *base, R_MPI_Aint size, int disp_unit,
                                   R_MPI_Info info, R_MPI_Comm comm, R_MPI_Win *win);
OMPI_DECLSPEC  int R_PMPI_Win_create_errhandler(R_MPI_Win_errhandler_function *function,
                                              R_MPI_Errhandler *errhandler);
OMPI_DECLSPEC  int R_PMPI_Win_create_keyval(R_MPI_Win_copy_attr_function *win_copy_attr_fn,
                                          R_MPI_Win_delete_attr_function *win_delete_attr_fn,
                                          int *win_keyval, void *extra_state);
OMPI_DECLSPEC  int R_PMPI_Win_delete_attr(R_MPI_Win win, int win_keyval);
OMPI_DECLSPEC  R_MPI_Win R_PMPI_Win_f2c(R_MPI_Fint win);
OMPI_DECLSPEC  int R_PMPI_Win_fence(int assert, R_MPI_Win win);
OMPI_DECLSPEC  int R_PMPI_Win_free(R_MPI_Win *win);
OMPI_DECLSPEC  int R_PMPI_Win_free_keyval(int *win_keyval);
OMPI_DECLSPEC  int R_PMPI_Win_get_attr(R_MPI_Win win, int win_keyval,
                                     void *attribute_val, int *flag);
OMPI_DECLSPEC  int R_PMPI_Win_get_errhandler(R_MPI_Win win, R_MPI_Errhandler *errhandler);
OMPI_DECLSPEC  int R_PMPI_Win_get_group(R_MPI_Win win, R_MPI_Group *group);
OMPI_DECLSPEC  int R_PMPI_Win_get_name(R_MPI_Win win, char *win_name, int *resultlen);
OMPI_DECLSPEC  int R_PMPI_Win_lock(int lock_type, int rank, int assert, R_MPI_Win win);
OMPI_DECLSPEC  int R_PMPI_Win_post(R_MPI_Group group, int assert, R_MPI_Win win);
OMPI_DECLSPEC  int R_PMPI_Win_set_attr(R_MPI_Win win, int win_keyval, void *attribute_val);
OMPI_DECLSPEC  int R_PMPI_Win_set_errhandler(R_MPI_Win win, R_MPI_Errhandler errhandler);
OMPI_DECLSPEC  int R_PMPI_Win_set_name(R_MPI_Win win, char *win_name);
OMPI_DECLSPEC  int R_PMPI_Win_start(R_MPI_Group group, int assert, R_MPI_Win win);
OMPI_DECLSPEC  int R_PMPI_Win_test(R_MPI_Win win, int *flag);
OMPI_DECLSPEC  int R_PMPI_Win_unlock(int rank, R_MPI_Win win);
OMPI_DECLSPEC  int R_PMPI_Win_wait(R_MPI_Win win);
OMPI_DECLSPEC  double R_PMPI_Wtick(void);
OMPI_DECLSPEC  double R_PMPI_Wtime(void);

#if defined(c_plusplus) || defined(__cplusplus)
}
#endif

/*
 * Conditional MPI 2 C++ bindings support.  Include if:
 *   - The user does not explicitly request us to skip it (when a C++ compiler
 *       is used to compile C code).
 *   - We want C++ bindings support
 *   - We are not building OMPI itself
 *   - We are using a C++ compiler
 */
#if !defined(OMPI_SKIP_MPICXX) && OMPI_WANT_CXX_BINDINGS && !OMPI_BUILDING
#if defined(c_plusplus) || defined(__cplusplus)
#include "openmpi/ompi/mpi/cxx/mpicxx.h"
#endif
#endif

#if !OMPI_PROVIDE_R_MPI_FILE_INTERFACE && !OMPI_BUILDING
/* ROMIO requires MPI implementations to set this to 1 if they provide
   R_MPI_OFFSET.  We need to provide it because its used throughout the
   DDT engine */
#define HAVE_R_MPI_OFFSET 1
#endif

#endif /* OMPI_R_MPI_H */

/* -*- Mode: C; c-basic-offset:4 ; -*- */
//############################# Wi4MPI License ###########################
//# Copyright or (C) or Copr. Commissariat a l'Energie Atomique          #
//#                                                                      #
//# IDDN.FR.001.210022.000.S.P.2014.000.10800                            #
//# This file is part of the Wi4MPI library.                             #
//#                                                                      #
//# SPDX-License-Identifier: BSD-3-Clause OR CeCILL-B                    #
//#                                                                      #
//########################################################################
/*  
 *  (C) 2001 by Argonne National Laboratory.
    
    				  MPICH2 COPYRIGHT
    
    The following is a notice of limited availability of the code, and disclaimer
    which must be included in the prologue of the code and in all source listings
    of the code.
    
    Copyright Notice
     + 2002 University of Chicago
    
    Permission is hereby granted to use, reproduce, prepare derivative works, and
    to redistribute to others.  This software was authored by:
    
    Mathematics and Computer Science Division
    Argonne National Laboratory, Argonne IL 60439
    
    (and)
    
    Department of Computer Science
    University of Illinois at Urbana-Champaign
    
    
    			      GOVERNMENT LICENSE
    
    Portions of this material resulted from work developed under a U.S.
    Government Contract and are subject to the following license: the Government
    is granted for itself and others acting on its behalf a paid-up, nonexclusive,
    irrevocable worldwide license in this computer software to reproduce, prepare
    derivative works, and perform publicly and display publicly.
    
    				  DISCLAIMER
    
    This computer code material was prepared, in part, as an account of work
    sponsored by an agency of the United States Government.  Neither the United
    States, nor the University of Chicago, nor any of their employees, makes any
    warranty express or implied, or assumes any legal liability or responsibility
    for the accuracy, completeness, or usefulness of any information, apparatus,
    product, or process disclosed, or represents that its use would not infringe
    privately owned rights.
    
 *      
 */
/* src/include/mpi.h.  Generated from mpi.h.in by configure. */
#ifndef A_MPI_INCLUDED
#define A_MPI_INCLUDED

/* user include file for MPI programs */
#if !defined(_WIN32) && !defined(_WIN64)  /* Linux only */
#	include <stdint.h> /* for __WORDSIZE definition */
#   ifdef __WORDSIZE
#	    if __WORDSIZE != 8*8 /* 32 or 64 */
#		    error A wrong version of mpi.h file was included. Check include path.
#	    endif
#    endif
#endif

/* Keep C++ compilers from getting confused */
#if defined(__cplusplus)
extern "C" {
#endif

#undef MPICH_DEFINE_ATTR_TYPE_TYPES
#if defined(__has_attribute)
#  if __has_attribute(pointer_with_type_tag) && \
      __has_attribute(type_tag_for_datatype) && \
      !defined(MPICH_NO_ATTR_TYPE_TAGS)
#    define MPICH_DEFINE_ATTR_TYPE_TYPES 1
#    define MPICH_ATTR_POINTER_WITH_TYPE_TAG(buffer_idx, type_idx)  __attribute__((pointer_with_type_tag(MPI,buffer_idx,type_idx)))
#    define MPICH_ATTR_TYPE_TAG(type)                               __attribute__((type_tag_for_datatype(MPI,type)))
#    define MPICH_ATTR_TYPE_TAG_LAYOUT_COMPATIBLE(type)             __attribute__((type_tag_for_datatype(MPI,type,layout_compatible)))
#    define MPICH_ATTR_TYPE_TAG_MUST_BE_NULL()                      __attribute__((type_tag_for_datatype(MPI,void,must_be_null)))
#    include <stddef.h>
#  endif
#endif

#if !defined(MPICH_ATTR_POINTER_WITH_TYPE_TAG)
#  define MPICH_ATTR_POINTER_WITH_TYPE_TAG(buffer_idx, type_idx)
#  define MPICH_ATTR_TYPE_TAG(type)
#  define MPICH_ATTR_TYPE_TAG_LAYOUT_COMPATIBLE(type)
#  define MPICH_ATTR_TYPE_TAG_MUST_BE_NULL()
#endif

#if !defined(INT8_C)
/* stdint.h was not included, see if we can get it */
#  if defined(__cplusplus)
#    if __cplusplus >= 201103
#      include <cstdint>
#    endif
#  endif
#endif

#if !defined(INT8_C)
/* stdint.h was not included, see if we can get it */
#  if defined(__STDC_VERSION__)
#    if __STDC_VERSION__ >= 199901
#      include <stdint.h>
#    endif
#  endif
#endif

#if defined(INT8_C)
/* stdint.h was included, so we can annotate these types */
#  define MPICH_ATTR_TYPE_TAG_STDINT(type) MPICH_ATTR_TYPE_TAG(type)
#else
#  define MPICH_ATTR_TYPE_TAG_STDINT(type)
#endif

#ifdef __STDC_VERSION__ 
#if __STDC_VERSION__ >= 199901
#  define MPICH_ATTR_TYPE_TAG_C99(type) MPICH_ATTR_TYPE_TAG(type)
#else
#  define MPICH_ATTR_TYPE_TAG_C99(type)
#endif
#else 
#  define MPICH_ATTR_TYPE_TAG_C99(type)
#endif

#if defined(__cplusplus)
#  define MPICH_ATTR_TYPE_TAG_CXX(type) MPICH_ATTR_TYPE_TAG(type)
#else
#  define MPICH_ATTR_TYPE_TAG_CXX(type)
#endif


/* Define some null objects */
#define A_MPI_COMM_NULL      ((A_MPI_Comm)0x04000000)
#define A_MPI_OP_NULL        ((A_MPI_Op)0x18000000)
#define A_MPI_GROUP_NULL     ((A_MPI_Group)0x08000000)
#define A_MPI_DATATYPE_NULL  ((A_MPI_Datatype)0x0c000000)
#define A_MPI_REQUEST_NULL   ((A_MPI_Request)0x2c000000)
#define A_MPI_ERRHANDLER_NULL ((A_MPI_Errhandler)0x14000000)
#define A_MPI_MESSAGE_NULL   ((A_MPI_Message)A_MPI_REQUEST_NULL)
#define A_MPI_MESSAGE_NO_PROC ((A_MPI_Message)0x6c000000)

/* Results of the compare operations. */
#define A_MPI_IDENT     0
#define A_MPI_CONGRUENT 1
#define A_MPI_SIMILAR   2
#define A_MPI_UNEQUAL   3

typedef int A_MPI_Datatype;
#define A_MPI_CHAR           ((A_MPI_Datatype)0x4c000101)
#define A_MPI_SIGNED_CHAR    ((A_MPI_Datatype)0x4c000118)
#define A_MPI_UNSIGNED_CHAR  ((A_MPI_Datatype)0x4c000102)
#define A_MPI_BYTE           ((A_MPI_Datatype)0x4c00010d)
#define A_MPI_WCHAR          ((A_MPI_Datatype)0x4c00040e)
#define A_MPI_SHORT          ((A_MPI_Datatype)0x4c000203)
#define A_MPI_UNSIGNED_SHORT ((A_MPI_Datatype)0x4c000204)
#define A_MPI_INT            ((A_MPI_Datatype)0x4c000405)
#define A_MPI_UNSIGNED       ((A_MPI_Datatype)0x4c000406)
#define A_MPI_LONG           ((A_MPI_Datatype)0x4c000807)
#define A_MPI_UNSIGNED_LONG  ((A_MPI_Datatype)0x4c000808)
#define A_MPI_FLOAT          ((A_MPI_Datatype)0x4c00040a)
#define A_MPI_DOUBLE         ((A_MPI_Datatype)0x4c00080b)
#define A_MPI_LONG_DOUBLE    ((A_MPI_Datatype)0x4c00100c)
#define A_MPI_LONG_LONG_INT  ((A_MPI_Datatype)0x4c000809)
#define A_MPI_UNSIGNED_LONG_LONG ((A_MPI_Datatype)0x4c000819)
#define A_MPI_LONG_LONG      A_MPI_LONG_LONG_INT

#ifdef MPICH_DEFINE_ATTR_TYPE_TYPES
static  A_MPI_Datatype mpich_mpi_char               MPICH_ATTR_TYPE_TAG(char)               = A_MPI_CHAR;
static  A_MPI_Datatype mpich_mpi_signed_char        MPICH_ATTR_TYPE_TAG(signed char)        = A_MPI_SIGNED_CHAR;
static  A_MPI_Datatype mpich_mpi_unsigned_char      MPICH_ATTR_TYPE_TAG(unsigned char)      = A_MPI_UNSIGNED_CHAR;
/*static  A_MPI_Datatype mpich_mpi_byte               MPICH_ATTR_TYPE_TAG(char)               = A_MPI_BYTE;*/
static  A_MPI_Datatype mpich_mpi_wchar              MPICH_ATTR_TYPE_TAG(wchar_t)            = A_MPI_WCHAR;
static  A_MPI_Datatype mpich_mpi_short              MPICH_ATTR_TYPE_TAG(short)              = A_MPI_SHORT;
static  A_MPI_Datatype mpich_mpi_unsigned_short     MPICH_ATTR_TYPE_TAG(unsigned short)     = A_MPI_UNSIGNED_SHORT;
static  A_MPI_Datatype mpich_mpi_int                MPICH_ATTR_TYPE_TAG(int)                = A_MPI_INT;
static  A_MPI_Datatype mpich_mpi_unsigned           MPICH_ATTR_TYPE_TAG(unsigned)           = A_MPI_UNSIGNED;
static  A_MPI_Datatype mpich_mpi_long               MPICH_ATTR_TYPE_TAG(long)               = A_MPI_LONG;
static  A_MPI_Datatype mpich_mpi_unsigned_long      MPICH_ATTR_TYPE_TAG(unsigned long)      = A_MPI_UNSIGNED_LONG;
static  A_MPI_Datatype mpich_mpi_float              MPICH_ATTR_TYPE_TAG(float)              = A_MPI_FLOAT;
static  A_MPI_Datatype mpich_mpi_double             MPICH_ATTR_TYPE_TAG(double)             = A_MPI_DOUBLE;
#if 0x4c00100c != 0x0c000000
static  A_MPI_Datatype mpich_mpi_long_double        MPICH_ATTR_TYPE_TAG(long double)        = A_MPI_LONG_DOUBLE;
#endif
static  A_MPI_Datatype mpich_mpi_long_long_int      MPICH_ATTR_TYPE_TAG(long long int)      = A_MPI_LONG_LONG_INT;
static  A_MPI_Datatype mpich_mpi_unsigned_long_long MPICH_ATTR_TYPE_TAG(unsigned long long) = A_MPI_UNSIGNED_LONG_LONG;
#endif

#define A_MPI_PACKED         ((A_MPI_Datatype)0x4c00010f)
#define A_MPI_LB             ((A_MPI_Datatype)0x4c000010)
#define A_MPI_UB             ((A_MPI_Datatype)0x4c000011)

/* 
   The layouts for the types A_MPI_DOUBLE_INT etc are simply
   struct { 
       double var;
       int    loc;
   }
   This is documented in the man pages on the various datatypes.   
 */
#define A_MPI_FLOAT_INT         ((A_MPI_Datatype)0x8c000000)
#define A_MPI_DOUBLE_INT        ((A_MPI_Datatype)0x8c000001)
#define A_MPI_LONG_INT          ((A_MPI_Datatype)0x8c000002)
#define A_MPI_SHORT_INT         ((A_MPI_Datatype)0x8c000003)
#define A_MPI_2INT              ((A_MPI_Datatype)0x4c000816)
#define A_MPI_LONG_DOUBLE_INT   ((A_MPI_Datatype)0x8c000004)

#ifdef MPICH_DEFINE_ATTR_TYPE_TYPES
struct mpich_struct_mpi_float_int       { float f; int i; };
struct mpich_struct_mpi_double_int      { double d; int i; };
struct mpich_struct_mpi_long_int        { long l; int i; };
struct mpich_struct_mpi_short_int       { short s; int i; };
struct mpich_struct_mpi_2int            { int i1; int i2; };
#if 0x8c000004 != 0x0c000000
struct mpich_struct_mpi_long_double_int { long double ld; int i; };
#endif

static  A_MPI_Datatype mpich_mpi_float_int       MPICH_ATTR_TYPE_TAG_LAYOUT_COMPATIBLE(struct mpich_struct_mpi_float_int)       = A_MPI_FLOAT_INT;
static  A_MPI_Datatype mpich_mpi_double_int      MPICH_ATTR_TYPE_TAG_LAYOUT_COMPATIBLE(struct mpich_struct_mpi_double_int)      = A_MPI_DOUBLE_INT;
static  A_MPI_Datatype mpich_mpi_long_int        MPICH_ATTR_TYPE_TAG_LAYOUT_COMPATIBLE(struct mpich_struct_mpi_long_int)        = A_MPI_LONG_INT;
static  A_MPI_Datatype mpich_mpi_short_int       MPICH_ATTR_TYPE_TAG_LAYOUT_COMPATIBLE(struct mpich_struct_mpi_short_int)       = A_MPI_SHORT_INT;

/*
 * The A_MPI_2INT line is commented out because currently Clang 3.3 flags
 * struct {int i1; int i2;} as different from int[2]. But actually these
 * two types are of the same layout. Clang gives a type mismatch warning
 * for a definitely correct code like the following:
 *  int in[2], out[2];
 *  A_MPI_Reduce(in, out, 1, A_MPI_2INT, A_MPI_MAXLOC, 0, A_MPI_COMM_WORLD);
 *
 * So, we disable type checking for A_MPI_2INT until Clang fixes this bug.
 */

/* static  A_MPI_Datatype mpich_mpi_2int            MPICH_ATTR_TYPE_TAG_LAYOUT_COMPATIBLE(struct mpich_struct_mpi_2int)            = A_MPI_2INT
 */

#if 0x8c000004 != 0x0c000000
static  A_MPI_Datatype mpich_mpi_long_double_int MPICH_ATTR_TYPE_TAG_LAYOUT_COMPATIBLE(struct mpich_struct_mpi_long_double_int) = A_MPI_LONG_DOUBLE_INT;
#endif
#endif

/* Fortran types */
#define A_MPI_COMPLEX           ((A_MPI_Datatype)1275070494)
#define A_MPI_DOUBLE_COMPLEX    ((A_MPI_Datatype)1275072546)
#define A_MPI_LOGICAL           ((A_MPI_Datatype)1275069469)
#define A_MPI_REAL              ((A_MPI_Datatype)1275069468)
#define A_MPI_DOUBLE_PRECISION  ((A_MPI_Datatype)1275070495)
#define A_MPI_INTEGER           ((A_MPI_Datatype)1275069467)
#define A_MPI_2INTEGER          ((A_MPI_Datatype)1275070496)
/* 
 * A_MPI_2COMPLEX and A_MPI_2DOUBLE_COMPLEX were defined by accident in 
 * MPI 1.0 and removed in MPI 1.1.  
 *
 * This definition provides backward compatibility.  These definitions
 * will be removed in a subsequent MPICH release
 */
#define MPICH_DEFINE_2COMPLEX
#ifdef MPICH_DEFINE_2COMPLEX
#define A_MPI_2COMPLEX          ((A_MPI_Datatype)1275072548)
#define A_MPI_2DOUBLE_COMPLEX   ((A_MPI_Datatype)1275076645)
#endif 
#define A_MPI_2REAL             ((A_MPI_Datatype)1275070497)
#define A_MPI_2DOUBLE_PRECISION ((A_MPI_Datatype)1275072547)
#define A_MPI_CHARACTER         ((A_MPI_Datatype)1275068698)

/* Size-specific types (see MPI-2, 10.2.5) */
#define A_MPI_REAL4             ((A_MPI_Datatype)0x4c000427)
#define A_MPI_REAL8             ((A_MPI_Datatype)0x4c000829)
#define A_MPI_REAL16            ((A_MPI_Datatype)0x4c00102b)
#define A_MPI_COMPLEX8          ((A_MPI_Datatype)0x4c000828)
#define A_MPI_COMPLEX16         ((A_MPI_Datatype)0x4c00102a)
#define A_MPI_COMPLEX32         ((A_MPI_Datatype)0x4c00202c)
#define A_MPI_INTEGER1          ((A_MPI_Datatype)0x4c00012d)
#define A_MPI_INTEGER2          ((A_MPI_Datatype)0x4c00022f)
#define A_MPI_INTEGER4          ((A_MPI_Datatype)0x4c000430)
#define A_MPI_INTEGER8          ((A_MPI_Datatype)0x4c000831)
#define A_MPI_INTEGER16         ((A_MPI_Datatype)A_MPI_DATATYPE_NULL)

/* C99 fixed-width datatypes */
#define A_MPI_INT8_T            ((A_MPI_Datatype)0x4c000137)
#define A_MPI_INT16_T           ((A_MPI_Datatype)0x4c000238)
#define A_MPI_INT32_T           ((A_MPI_Datatype)0x4c000439)
#define A_MPI_INT64_T           ((A_MPI_Datatype)0x4c00083a)
#define A_MPI_UINT8_T           ((A_MPI_Datatype)0x4c00013b)
#define A_MPI_UINT16_T          ((A_MPI_Datatype)0x4c00023c)
#define A_MPI_UINT32_T          ((A_MPI_Datatype)0x4c00043d)
#define A_MPI_UINT64_T          ((A_MPI_Datatype)0x4c00083e)

#ifdef MPICH_DEFINE_ATTR_TYPE_TYPES
static  A_MPI_Datatype mpich_mpi_int8_t   MPICH_ATTR_TYPE_TAG_STDINT(int8_t)   = A_MPI_INT8_T;
static  A_MPI_Datatype mpich_mpi_int16_t  MPICH_ATTR_TYPE_TAG_STDINT(int16_t)  = A_MPI_INT16_T;
static  A_MPI_Datatype mpich_mpi_int32_t  MPICH_ATTR_TYPE_TAG_STDINT(int32_t)  = A_MPI_INT32_T;
static  A_MPI_Datatype mpich_mpi_int64_t  MPICH_ATTR_TYPE_TAG_STDINT(int64_t)  = A_MPI_INT64_T;
static  A_MPI_Datatype mpich_mpi_uint8_t  MPICH_ATTR_TYPE_TAG_STDINT(uint8_t)  = A_MPI_UINT8_T;
static  A_MPI_Datatype mpich_mpi_uint16_t MPICH_ATTR_TYPE_TAG_STDINT(uint16_t) = A_MPI_UINT16_T;
static  A_MPI_Datatype mpich_mpi_uint32_t MPICH_ATTR_TYPE_TAG_STDINT(uint32_t) = A_MPI_UINT32_T;
static  A_MPI_Datatype mpich_mpi_uint64_t MPICH_ATTR_TYPE_TAG_STDINT(uint64_t) = A_MPI_UINT64_T;
#endif

/* other C99 types */
#define A_MPI_C_BOOL                 ((A_MPI_Datatype)0x4c00013f)
#define A_MPI_C_FLOAT_COMPLEX        ((A_MPI_Datatype)0x4c000840)
#define A_MPI_C_COMPLEX              A_MPI_C_FLOAT_COMPLEX
#define A_MPI_C_DOUBLE_COMPLEX       ((A_MPI_Datatype)0x4c001041)
#define A_MPI_C_LONG_DOUBLE_COMPLEX  ((A_MPI_Datatype)0x4c002042)

#ifdef MPICH_DEFINE_ATTR_TYPE_TYPES
static  A_MPI_Datatype mpich_mpi_c_bool                MPICH_ATTR_TYPE_TAG_C99(_Bool)           = A_MPI_C_BOOL;
static  A_MPI_Datatype mpich_mpi_c_float_complex       MPICH_ATTR_TYPE_TAG_C99(float _Complex)  = A_MPI_C_FLOAT_COMPLEX;
static  A_MPI_Datatype mpich_mpi_c_double_complex      MPICH_ATTR_TYPE_TAG_C99(double _Complex) = A_MPI_C_DOUBLE_COMPLEX;
#if 0x4c002042 != 0x0c000000
static  A_MPI_Datatype mpich_mpi_c_long_double_complex MPICH_ATTR_TYPE_TAG_C99(long double _Complex) = A_MPI_C_LONG_DOUBLE_COMPLEX;
#endif
#endif

/* address/offset types */
#define A_MPI_AINT          ((A_MPI_Datatype)0x4c000843)
#define A_MPI_OFFSET        ((A_MPI_Datatype)0x4c000844)
#define A_MPI_COUNT         ((A_MPI_Datatype)0x4c000845)

/* MPI-3 C++ types */
#define A_MPI_CXX_BOOL                ((A_MPI_Datatype)0x4c000133)
#define A_MPI_CXX_FLOAT_COMPLEX       ((A_MPI_Datatype)0x4c000834)
#define A_MPI_CXX_DOUBLE_COMPLEX      ((A_MPI_Datatype)0x4c001035)
#define A_MPI_CXX_LONG_DOUBLE_COMPLEX ((A_MPI_Datatype)0x4c002036)

/* typeclasses */
#define A_MPI_TYPECLASS_REAL 1
#define A_MPI_TYPECLASS_INTEGER 2
#define A_MPI_TYPECLASS_COMPLEX 3

/* Communicators */
typedef int A_MPI_Comm;
#define A_MPI_COMM_WORLD ((A_MPI_Comm)0x44000000)
#define A_MPI_COMM_SELF  ((A_MPI_Comm)0x44000001)

/* Groups */
typedef int A_MPI_Group;
#define A_MPI_GROUP_EMPTY ((A_MPI_Group)0x48000000)

/* RMA and Windows */
typedef int A_MPI_Win;
#define A_MPI_WIN_NULL ((A_MPI_Win)0x20000000)

/* File and IO */
/* This define lets ROMIO know that A_MPI_File has been defined */
#define A_MPI_FILE_DEFINED
/* ROMIO uses a pointer for A_MPI_File objects.  This must be the same definition
   as in src/mpi/romio/include/mpio.h.in  */
typedef struct ADIOI_FileD *A_MPI_File;
#define A_MPI_FILE_NULL ((A_MPI_File)0)

/* Collective operations */
typedef int A_MPI_Op;

#define A_MPI_MAX     (A_MPI_Op)(0x58000001)
#define A_MPI_MIN     (A_MPI_Op)(0x58000002)
#define A_MPI_SUM     (A_MPI_Op)(0x58000003)
#define A_MPI_PROD    (A_MPI_Op)(0x58000004)
#define A_MPI_LAND    (A_MPI_Op)(0x58000005)
#define A_MPI_BAND    (A_MPI_Op)(0x58000006)
#define A_MPI_LOR     (A_MPI_Op)(0x58000007)
#define A_MPI_BOR     (A_MPI_Op)(0x58000008)
#define A_MPI_LXOR    (A_MPI_Op)(0x58000009)
#define A_MPI_BXOR    (A_MPI_Op)(0x5800000a)
#define A_MPI_MINLOC  (A_MPI_Op)(0x5800000b)
#define A_MPI_MAXLOC  (A_MPI_Op)(0x5800000c)
#define A_MPI_REPLACE (A_MPI_Op)(0x5800000d)
#define A_MPI_NO_OP   (A_MPI_Op)(0x5800000e)

/* Permanent key values */
/* C Versions (return pointer to value),
   Fortran Versions (return integer value).
   Handled directly by the attribute value routine
   
   DO NOT CHANGE THESE.  The values encode:
   builtin kind (0x1 in bit 30-31)
   Keyval object (0x9 in bits 26-29)
   for communicator (0x1 in bits 22-25)
   
   Fortran versions of the attributes are formed by adding one to
   the C version.
 */
#define A_MPI_TAG_UB           0x64400001
#define A_MPI_HOST             0x64400003
#define A_MPI_IO               0x64400005
#define A_MPI_WTIME_IS_GLOBAL  0x64400007
#define A_MPI_UNIVERSE_SIZE    0x64400009
#define A_MPI_LASTUSEDCODE     0x6440000b
#define A_MPI_APPNUM           0x6440000d

/* In addition, there are 5 predefined window attributes that are
   defined for every window */
#define A_MPI_WIN_BASE          0x66000001
#define A_MPI_WIN_SIZE          0x66000003
#define A_MPI_WIN_DISP_UNIT     0x66000005
#define A_MPI_WIN_CREATE_FLAVOR 0x66000007
#define A_MPI_WIN_MODEL         0x66000009

#ifdef MPICH_DEFINE_ATTR_TYPE_TYPES
static  A_MPI_Datatype mpich_mpi_datatype_null MPICH_ATTR_TYPE_TAG_MUST_BE_NULL() = A_MPI_DATATYPE_NULL;
#endif

/* These are only guesses; make sure you change them in mpif.h as well */
#define A_MPI_MAX_PROCESSOR_NAME 128
#define A_MPI_MAX_LIBRARY_VERSION_STRING 8192
#define A_MPI_MAX_ERROR_STRING   512
#define A_MPI_MAX_PORT_NAME      256
#define A_MPI_MAX_OBJECT_NAME    128
#define A_MPI_MAX_DATAREP_STRING 128

/* Pre-defined ants */
#define A_MPI_UNDEFINED      (-32766)
#define A_MPI_UNDEFINED_RANK A_MPI_UNDEFINED
#define A_MPI_KEYVAL_INVALID 0x24000000

/* MPI-3 window flavors */
typedef enum MPIR_Win_flavor {
    A_MPI_WIN_FLAVOR_CREATE      = 1,
    A_MPI_WIN_FLAVOR_ALLOCATE    = 2,
    A_MPI_WIN_FLAVOR_DYNAMIC     = 3,
    A_MPI_WIN_FLAVOR_SHARED      = 4
} MPIR_Win_flavor_t;

/* MPI-3 window consistency models */
typedef enum MPIR_Win_model {
    A_MPI_WIN_SEPARATE   = 1,
    A_MPI_WIN_UNIFIED    = 2
} MPIR_Win_model_t;

/* Upper bound on the overhead in bsend for each message buffer */
#define A_MPI_BSEND_OVERHEAD 95

/* Topology types */
typedef enum MPIR_Topo_type { A_MPI_GRAPH=1, A_MPI_CART=2, A_MPI_DIST_GRAPH=3 } MPIR_Topo_type;

#define A_MPI_BOTTOM      (void *)0

#define A_MPI_PROC_NULL   (-1)
#define A_MPI_ANY_SOURCE 	(-2)
#define A_MPI_ROOT        (-3)
#define A_MPI_ANY_TAG     (-1)

#define A_MPI_LOCK_EXCLUSIVE  234
#define A_MPI_LOCK_SHARED     235

/* C functions */
typedef void (A_MPI_Handler_function) ( A_MPI_Comm *, int *, ... );
typedef int (A_MPI_Comm_copy_attr_function)(A_MPI_Comm, int, void *, void *, 
					  void *, int *);
typedef int (A_MPI_Comm_delete_attr_function)(A_MPI_Comm, int, void *, void *);
typedef int (A_MPI_Type_copy_attr_function)(A_MPI_Datatype, int, void *, void *, 
					  void *, int *);
typedef int (A_MPI_Type_delete_attr_function)(A_MPI_Datatype, int, void *, void *);
typedef int (A_MPI_Win_copy_attr_function)(A_MPI_Win, int, void *, void *, void *,
					 int *);
typedef int (A_MPI_Win_delete_attr_function)(A_MPI_Win, int, void *, void *);
/* added in MPI-2.2 */
typedef void (A_MPI_Comm_errhandler_function)(A_MPI_Comm *, int *, ...);
typedef void (A_MPI_File_errhandler_function)(A_MPI_File *, int *, ...);
typedef void (A_MPI_Win_errhandler_function)(A_MPI_Win *, int *, ...);
/* names that were added in MPI-2.0 and deprecated in MPI-2.2 */
typedef A_MPI_Comm_errhandler_function A_MPI_Comm_errhandler_fn;
typedef A_MPI_File_errhandler_function A_MPI_File_errhandler_fn;
typedef A_MPI_Win_errhandler_function A_MPI_Win_errhandler_fn;

/* Built in (0x1 in 30-31), errhandler (0x5 in bits 26-29, allkind (0
   in 22-25), index in the low bits */
#define A_MPI_ERRORS_ARE_FATAL ((A_MPI_Errhandler)0x54000000)
#define A_MPI_ERRORS_RETURN    ((A_MPI_Errhandler)0x54000001)
/* MPIR_ERRORS_THROW_EXCEPTIONS is not part of the MPI standard, it is here to
   facilitate the c++ binding which has MPI::ERRORS_THROW_EXCEPTIONS. 
   Using the MPIR prefix preserved the A_MPI_ names for objects defined by
   the standard. */
#define MPIR_ERRORS_THROW_EXCEPTIONS ((A_MPI_Errhandler)0x54000002)
typedef int A_MPI_Errhandler;

/* Make the C names for the dup function mixed case.
   This is required for systems that use all uppercase names for Fortran 
   externals.  */
/* MPI 1 names */
#define A_MPI_NULL_COPY_FN   ((A_MPI_Copy_function *)0)
#define A_MPI_NULL_DELETE_FN ((A_MPI_Delete_function *)0)
#define A_MPI_DUP_FN         MPIR_Dup_fn
/* MPI 2 names */
#define A_MPI_COMM_NULL_COPY_FN ((A_MPI_Comm_copy_attr_function*)0)
#define A_MPI_COMM_NULL_DELETE_FN ((A_MPI_Comm_delete_attr_function*)0)
#define A_MPI_COMM_DUP_FN  ((A_MPI_Comm_copy_attr_function *)A_MPI_DUP_FN)
#define A_MPI_WIN_NULL_COPY_FN ((A_MPI_Win_copy_attr_function*)0)
#define A_MPI_WIN_NULL_DELETE_FN ((A_MPI_Win_delete_attr_function*)0)
#define A_MPI_WIN_DUP_FN   ((A_MPI_Win_copy_attr_function*)A_MPI_DUP_FN)
#define A_MPI_TYPE_NULL_COPY_FN ((A_MPI_Type_copy_attr_function*)0)
#define A_MPI_TYPE_NULL_DELETE_FN ((A_MPI_Type_delete_attr_function*)0)
#define A_MPI_TYPE_DUP_FN ((A_MPI_Type_copy_attr_function*)A_MPI_DUP_FN)

/* MPI request opjects */
typedef int A_MPI_Request;

/* MPI message objects for Mprobe and related functions */
typedef int A_MPI_Message;

/* User combination function */
typedef void (A_MPI_User_function) ( void *, void *, int *, A_MPI_Datatype * ); 

/* MPI Attribute copy and delete functions */
typedef int (A_MPI_Copy_function) ( A_MPI_Comm, int, void *, void *, void *, int * );
typedef int (A_MPI_Delete_function) ( A_MPI_Comm, int, void *, void * );

#define A_MPI_VERSION    3
#define A_MPI_SUBVERSION 0
#define MPICH_NAME     3
#define MPICH         1
#define MPICH_HAS_C2F  1


/* MPICH_VERSION is the version string. MPICH_NUMVERSION is the
 * numeric version that can be used in numeric comparisons.
 *
 * MPICH_VERSION uses the following format:
 * Version: [MAJ].[MIN].[REV][EXT][EXT_NUMBER]
 * Example: 1.0.7rc1 has
 *          MAJ = 1
 *          MIN = 0
 *          REV = 7
 *          EXT = rc
 *          EXT_NUMBER = 1
 *
 * MPICH_NUMVERSION will convert EXT to a format number:
 *          ALPHA (a) = 0
 *          BETA (b)  = 1
 *          RC (rc)   = 2
 *          PATCH (p) = 3
 * Regular releases are treated as patch 0
 *
 * Numeric version will have 1 digit for MAJ, 2 digits for MIN, 2
 * digits for REV, 1 digit for EXT and 2 digits for EXT_NUMBER. So,
 * 1.0.7rc1 will have the numeric version 10007201.
 */
#define MPICH_VERSION "3.1.2"
#define MPICH_NUMVERSION 30102300

#define MPICH_RELEASE_TYPE_ALPHA  0
#define MPICH_RELEASE_TYPE_BETA   1
#define MPICH_RELEASE_TYPE_RC     2
#define MPICH_RELEASE_TYPE_PATCH  3

#define MPICH_CALC_VERSION(MAJOR, MINOR, REVISION, TYPE, PATCH) \
    (((MAJOR) * 10000000) + ((MINOR) * 100000) + ((REVISION) * 1000) + ((TYPE) * 100) + (PATCH))

/* for the datatype decoders */
enum MPIR_Combiner_enum {
    A_MPI_COMBINER_NAMED            = 1,
    A_MPI_COMBINER_DUP              = 2,
    A_MPI_COMBINER_CONTIGUOUS       = 3, 
    A_MPI_COMBINER_VECTOR           = 4,
    A_MPI_COMBINER_HVECTOR_INTEGER  = 5,
    A_MPI_COMBINER_HVECTOR          = 6,
    A_MPI_COMBINER_INDEXED          = 7,
    A_MPI_COMBINER_HINDEXED_INTEGER = 8, 
    A_MPI_COMBINER_HINDEXED         = 9, 
    A_MPI_COMBINER_INDEXED_BLOCK    = 10, 
    A_MPI_COMBINER_STRUCT_INTEGER   = 11,
    A_MPI_COMBINER_STRUCT           = 12,
    A_MPI_COMBINER_SUBARRAY         = 13,
    A_MPI_COMBINER_DARRAY           = 14,
    A_MPI_COMBINER_F90_REAL         = 15,
    A_MPI_COMBINER_F90_COMPLEX      = 16,
    A_MPI_COMBINER_F90_INTEGER      = 17,
    A_MPI_COMBINER_RESIZED          = 18,
    A_MPI_COMBINER_HINDEXED_BLOCK   = 19
};

/* for info */
typedef int A_MPI_Info;
#define A_MPI_INFO_NULL         ((A_MPI_Info)0x1c000000)
#define A_MPI_INFO_ENV          ((A_MPI_Info)0x5c000001)
#define A_MPI_MAX_INFO_KEY       255
#define A_MPI_MAX_INFO_VAL      1024

/* for subarray and darray ructors */
#define A_MPI_ORDER_C              56
#define A_MPI_ORDER_FORTRAN        57
#define A_MPI_DISTRIBUTE_BLOCK    121
#define A_MPI_DISTRIBUTE_CYCLIC   122
#define A_MPI_DISTRIBUTE_NONE     123
#define A_MPI_DISTRIBUTE_DFLT_DARG -49767

#define A_MPI_IN_PLACE  (void *) -1

/* asserts for one-sided communication */
#define A_MPI_MODE_NOCHECK      1024
#define A_MPI_MODE_NOSTORE      2048
#define A_MPI_MODE_NOPUT        4096
#define A_MPI_MODE_NOPRECEDE    8192
#define A_MPI_MODE_NOSUCCEED   16384 

/* predefined types for A_MPI_Comm_split_type */
#define A_MPI_COMM_TYPE_SHARED    1

/* Definitions that are determined by configure. */
typedef long A_MPI_Aint;
typedef int A_MPI_Fint;
typedef long long A_MPI_Count;

#ifdef MPICH_DEFINE_ATTR_TYPE_TYPES
static  A_MPI_Datatype mpich_mpi_aint   MPICH_ATTR_TYPE_TAG(A_MPI_Aint)   = A_MPI_AINT;
#endif

/* FIXME: The following two definition are not defined by MPI and must not be
   included in the mpi.h file, as the MPI namespace is reserved to the MPI 
   standard */
#define A_MPI_AINT_FMT_DEC_SPEC "%ld"
#define A_MPI_AINT_FMT_HEX_SPEC "%lx"

/* Let ROMIO know that A_MPI_Offset is already defined */
#define HAVE_A_MPI_OFFSET
/* A_MPI_OFFSET_TYPEDEF is set in configure and is 
      typedef $A_MPI_OFFSET A_MPI_Offset;
   where $A_MPI_OFFSET is the correct C type */
typedef long long A_MPI_Offset;

#ifdef MPICH_DEFINE_ATTR_TYPE_TYPES
static  A_MPI_Datatype mpich_mpi_offset MPICH_ATTR_TYPE_TAG(A_MPI_Offset) = A_MPI_OFFSET;
#endif

/* The order of these elements must match that in mpif.h, mpi_f08_types.f90,
   and mpi_c_interface_types.f90 */
typedef struct A_MPI_Status {
    int count_lo;
    int count_hi_and_cancelled;
    int A_MPI_SOURCE;
    int A_MPI_TAG;
    int A_MPI_ERROR;
} A_MPI_Status;

/* types for the A_MPI_T_ interface */
struct MPIR_T_enum_s;
struct MPIR_T_cvar_handle_s;
struct MPIR_T_pvar_handle_s;
struct MPIR_T_pvar_session_s;

typedef struct MPIR_T_enum_s * A_MPI_T_enum;
typedef struct MPIR_T_cvar_handle_s * A_MPI_T_cvar_handle;
typedef struct MPIR_T_pvar_handle_s * A_MPI_T_pvar_handle;
typedef struct MPIR_T_pvar_session_s * A_MPI_T_pvar_session;

/* extra  at front would be safer, but is incompatible with A_MPI_T_ prototypes */
extern struct MPIR_T_pvar_handle_s *  A_MPI_T_PVAR_ALL_HANDLES;

#define A_MPI_T_ENUM_NULL         ((A_MPI_T_enum)NULL)
#define A_MPI_T_CVAR_HANDLE_NULL  ((A_MPI_T_cvar_handle)NULL)
#define A_MPI_T_PVAR_HANDLE_NULL  ((A_MPI_T_pvar_handle)NULL)
#define A_MPI_T_PVAR_SESSION_NULL ((A_MPI_T_pvar_session)NULL)

/* the A_MPI_T_ interface requires that these VERBOSITY ants occur in this
 * relative order with increasing values */
typedef enum MPIR_T_verbosity_t {
    /* don't name-shift this if/when A_MPI_T_ is accepted, this is an MPICH-only
     * extension */
    MPIX_T_VERBOSITY_INVALID = 0,

    /* arbitrarily shift values to aid debugging and reduce accidental errors */
    A_MPI_T_VERBOSITY_USER_BASIC = 221,
    A_MPI_T_VERBOSITY_USER_DETAIL,
    A_MPI_T_VERBOSITY_USER_ALL,

    A_MPI_T_VERBOSITY_TUNER_BASIC,
    A_MPI_T_VERBOSITY_TUNER_DETAIL,
    A_MPI_T_VERBOSITY_TUNER_ALL,

    A_MPI_T_VERBOSITY_MPIDEV_BASIC,
    A_MPI_T_VERBOSITY_MPIDEV_DETAIL,
    A_MPI_T_VERBOSITY_MPIDEV_ALL
} MPIR_T_verbosity_t;

typedef enum MPIR_T_bind_t {
    /* don't name-shift this if/when A_MPI_T_ is accepted, this is an MPICH-only
     * extension */
    MPIX_T_BIND_INVALID = 0,

    /* arbitrarily shift values to aid debugging and reduce accidental errors */
    A_MPI_T_BIND_NO_OBJECT = 9700,
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
} MPIR_T_bind_t;

typedef enum MPIR_T_scope_t {
    /* don't name-shift this if/when A_MPI_T_ is accepted, this is an MPICH-only
     * extension */
    MPIX_T_SCOPE_INVALID = 0,

    /* arbitrarily shift values to aid debugging and reduce accidental errors */
    A_MPI_T_SCOPE_CONSTANT = 60438,
    A_MPI_T_SCOPE_READONLY,
    A_MPI_T_SCOPE_LOCAL,
    A_MPI_T_SCOPE_GROUP,
    A_MPI_T_SCOPE_GROUP_EQ,
    A_MPI_T_SCOPE_ALL,
    A_MPI_T_SCOPE_ALL_EQ
} MPIR_T_scope_t;

typedef enum MPIR_T_pvar_class_t {
    /* don't name-shift this if/when A_MPI_T_ is accepted, this is an MPICH-only
     * extension */
    MPIX_T_PVAR_CLASS_INVALID = 0,

    /* arbitrarily shift values to aid debugging and reduce accidental errors */
    MPIR_T_PVAR_CLASS_FIRST = 240,
    A_MPI_T_PVAR_CLASS_STATE = MPIR_T_PVAR_CLASS_FIRST,
    A_MPI_T_PVAR_CLASS_LEVEL,
    A_MPI_T_PVAR_CLASS_SIZE,
    A_MPI_T_PVAR_CLASS_PERCENTAGE,
    A_MPI_T_PVAR_CLASS_HIGHWATERMARK,
    A_MPI_T_PVAR_CLASS_LOWWATERMARK,
    A_MPI_T_PVAR_CLASS_COUNTER,
    A_MPI_T_PVAR_CLASS_AGGREGATE,
    A_MPI_T_PVAR_CLASS_TIMER,
    A_MPI_T_PVAR_CLASS_GENERIC,
    MPIR_T_PVAR_CLASS_LAST,
    MPIR_T_PVAR_CLASS_NUMBER = MPIR_T_PVAR_CLASS_LAST - MPIR_T_PVAR_CLASS_FIRST
} MPIR_T_pvar_class_t;

/* Handle conversion types/functions */

/* Programs that need to convert types used in MPICH should use these */
//#define A_MPI_Comm_c2f(comm) (A_MPI_Fint)(comm)
//#define A_MPI_Comm_f2c(comm) (A_MPI_Comm)(comm)
//#define A_MPI_Type_c2f(datatype) (A_MPI_Fint)(datatype)
//#define A_MPI_Type_f2c(datatype) (A_MPI_Datatype)(datatype)
//#define A_MPI_Group_c2f(group) (A_MPI_Fint)(group)
//#define A_MPI_Group_f2c(group) (A_MPI_Group)(group)
//#define A_MPI_Info_c2f(info) (A_MPI_Fint)(info)
//#define A_MPI_Info_f2c(info) (A_MPI_Info)(info)
//#define A_MPI_Request_f2c(request) (A_MPI_Request)(request)
//#define A_MPI_Request_c2f(request) (A_MPI_Fint)(request)
//#define A_MPI_Op_c2f(op) (A_MPI_Fint)(op)
//#define A_MPI_Op_f2c(op) (A_MPI_Op)(op)
//#define A_MPI_Errhandler_c2f(errhandler) (A_MPI_Fint)(errhandler)
//#define A_MPI_Errhandler_f2c(errhandler) (A_MPI_Errhandler)(errhandler)
//#define A_MPI_Win_c2f(win)   (A_MPI_Fint)(win)
//#define A_MPI_Win_f2c(win)   (A_MPI_Win)(win)
//#define A_MPI_Message_c2f(msg) ((A_MPI_Fint)(msg))
//#define A_MPI_Message_f2c(msg) ((A_MPI_Message)(msg))

/* PMPI versions of the handle transfer functions.  See section 4.17 */
#define A_PMPI_Comm_c2f(comm) (A_MPI_Fint)(comm)
#define A_PMPI_Comm_f2c(comm) (A_MPI_Comm)(comm)
#define A_PMPI_Type_c2f(datatype) (A_MPI_Fint)(datatype)
#define A_PMPI_Type_f2c(datatype) (A_MPI_Datatype)(datatype)
#define A_PMPI_Group_c2f(group) (A_MPI_Fint)(group)
#define A_PMPI_Group_f2c(group) (A_MPI_Group)(group)
#define A_PMPI_Info_c2f(info) (A_MPI_Fint)(info)
#define A_PMPI_Info_f2c(info) (A_MPI_Info)(info)
#define A_PMPI_Request_f2c(request) (A_MPI_Request)(request)
#define A_PMPI_Request_c2f(request) (A_MPI_Fint)(request)
#define A_PMPI_Op_c2f(op) (A_MPI_Fint)(op)
#define A_PMPI_Op_f2c(op) (A_MPI_Op)(op)
#define A_PMPI_Errhandler_c2f(errhandler) (A_MPI_Fint)(errhandler)
#define A_PMPI_Errhandler_f2c(errhandler) (A_MPI_Errhandler)(errhandler)
#define A_PMPI_Win_c2f(win)   (A_MPI_Fint)(win)
#define A_PMPI_Win_f2c(win)   (A_MPI_Win)(win)
#define A_PMPI_Message_c2f(msg) ((A_MPI_Fint)(msg))
#define A_PMPI_Message_f2c(msg) ((A_MPI_Message)(msg))

#define A_MPI_STATUS_IGNORE (A_MPI_Status *)1
#define A_MPI_STATUSES_IGNORE (A_MPI_Status *)1
#define A_MPI_ERRCODES_IGNORE (int *)0

/* See 4.12.5 for A_MPI_F_STATUS(ES)_IGNORE */
#define MPIU_DLL_SPEC
extern MPIU_DLL_SPEC A_MPI_Fint * A_MPI_F_STATUS_IGNORE;
extern MPIU_DLL_SPEC A_MPI_Fint * A_MPI_F_STATUSES_IGNORE;
//extern MPIU_DLL_SPEC int *  A_MPI_UNWEIGHTED;
//extern MPIU_DLL_SPEC int *  A_MPI_WEIGHTS_EMPTY;
int *  A_MPI_UNWEIGHTED;
int *  A_MPI_WEIGHTS_EMPTY;

/* The annotation MPIU_DLL_SPEC to the extern statements is used 
   as a hook for systems that require C extensions to correctly ruct
   DLLs, and is defined as an empty string otherwise
 */

/* The MPI standard requires that the ARGV_NULL values be the same as
   NULL (see 5.3.2) */
#define A_MPI_ARGV_NULL (char **)0
#define A_MPI_ARGVS_NULL (char ***)0

/* C type for A_MPI_STATUS in F08.
   The field order should match that in mpi_f08_types.f90, and mpi_c_interface_types.f90.
 */
typedef struct {
    A_MPI_Fint count_lo;
    A_MPI_Fint count_hi_and_cancelled;
    A_MPI_Fint A_MPI_SOURCE;
    A_MPI_Fint A_MPI_TAG;
    A_MPI_Fint A_MPI_ERROR;
} A_MPI_F08_Status;

extern A_MPI_F08_Status MPIR_F08_A_MPI_STATUS_IGNORE_OBJ;
extern A_MPI_F08_Status MPIR_F08_A_MPI_STATUSES_IGNORE_OBJ[1];
extern int MPIR_F08_A_MPI_IN_PLACE;
extern int MPIR_F08_A_MPI_BOTTOM;

/* Pointers to above objects */
extern A_MPI_F08_Status *A_MPI_F08_STATUS_IGNORE;
extern A_MPI_F08_Status *A_MPI_F08_STATUSES_IGNORE;

/* For supported thread levels */
#define A_MPI_THREAD_SINGLE 0
#define A_MPI_THREAD_FUNNELED 1
#define A_MPI_THREAD_SERIALIZED 2
#define A_MPI_THREAD_MULTIPLE 3

/* Typedefs for generalized requests */
typedef int (A_MPI_Grequest_cancel_function)(void *, int); 
typedef int (A_MPI_Grequest_free_function)(void *); 
typedef int (A_MPI_Grequest_query_function)(void *, A_MPI_Status *); 
typedef int (MPIX_Grequest_poll_function)(void *, A_MPI_Status *);
typedef int (MPIX_Grequest_wait_function)(int, void **, double, A_MPI_Status *);

/* MPI's error classes */
#define A_MPI_SUCCESS          0      /* Successful return code */
/* Communication argument parameters */
#define A_MPI_ERR_BUFFER       1      /* Invalid buffer pointer */
#define A_MPI_ERR_COUNT        2      /* Invalid count argument */
#define A_MPI_ERR_TYPE         3      /* Invalid datatype argument */
#define A_MPI_ERR_TAG          4      /* Invalid tag argument */
#define A_MPI_ERR_COMM         5      /* Invalid communicator */
#define A_MPI_ERR_RANK         6      /* Invalid rank */
#define A_MPI_ERR_ROOT         7      /* Invalid root */
#define A_MPI_ERR_TRUNCATE    14      /* Message truncated on receive */

/* MPI Objects (other than COMM) */
#define A_MPI_ERR_GROUP        8      /* Invalid group */
#define A_MPI_ERR_OP           9      /* Invalid operation */
#define A_MPI_ERR_REQUEST     19      /* Invalid mpi_request handle */

/* Special topology argument parameters */
#define A_MPI_ERR_TOPOLOGY    10      /* Invalid topology */
#define A_MPI_ERR_DIMS        11      /* Invalid dimension argument */

/* All other arguments.  This is a class with many kinds */
#define A_MPI_ERR_ARG         12      /* Invalid argument */

/* Other errors that are not simply an invalid argument */
#define A_MPI_ERR_OTHER       15      /* Other error; use Error_string */

#define A_MPI_ERR_UNKNOWN     13      /* Unknown error */
#define A_MPI_ERR_INTERN      16      /* Internal error code    */

/* Multiple completion has two special error classes */
#define A_MPI_ERR_IN_STATUS   17      /* Look in status for error value */
#define A_MPI_ERR_PENDING     18      /* Pending request */

/* New MPI-2 Error classes */
#define A_MPI_ERR_FILE        27      /* */
#define A_MPI_ERR_ACCESS      20      /* */
#define A_MPI_ERR_AMODE       21      /* */
#define A_MPI_ERR_BAD_FILE    22      /* */
#define A_MPI_ERR_FILE_EXISTS 25      /* */
#define A_MPI_ERR_FILE_IN_USE 26      /* */
#define A_MPI_ERR_NO_SPACE    36      /* */
#define A_MPI_ERR_NO_SUCH_FILE 37     /* */
#define A_MPI_ERR_IO          32      /* */
#define A_MPI_ERR_READ_ONLY   40      /* */
#define A_MPI_ERR_CONVERSION  23      /* */
#define A_MPI_ERR_DUP_DATAREP 24      /* */
#define A_MPI_ERR_UNSUPPORTED_DATAREP   43  /* */

/* A_MPI_ERR_INFO is NOT defined in the MPI-2 standard.  I believe that
   this is an oversight */
#define A_MPI_ERR_INFO        28      /* */
#define A_MPI_ERR_INFO_KEY    29      /* */
#define A_MPI_ERR_INFO_VALUE  30      /* */
#define A_MPI_ERR_INFO_NOKEY  31      /* */

#define A_MPI_ERR_NAME        33      /* */
#define A_MPI_ERR_NO_MEM      34      /* Alloc_mem could not allocate memory */
#define A_MPI_ERR_NOT_SAME    35      /* */
#define A_MPI_ERR_PORT        38      /* */
#define A_MPI_ERR_QUOTA       39      /* */
#define A_MPI_ERR_SERVICE     41      /* */
#define A_MPI_ERR_SPAWN       42      /* */
#define A_MPI_ERR_UNSUPPORTED_OPERATION 44 /* */
#define A_MPI_ERR_WIN         45      /* */

#define A_MPI_ERR_BASE        46      /* */
#define A_MPI_ERR_LOCKTYPE    47      /* */
#define A_MPI_ERR_KEYVAL      48      /* Erroneous attribute key */
#define A_MPI_ERR_RMA_CONFLICT 49     /* */
#define A_MPI_ERR_RMA_SYNC    50      /* */ 
#define A_MPI_ERR_SIZE        51      /* */
#define A_MPI_ERR_DISP        52      /* */
#define A_MPI_ERR_ASSERT      53      /* */

#define MPIX_ERR_PROC_FAIL_STOP 54   /* Process failure */

#define A_MPI_ERR_RMA_RANGE  55       /* */
#define A_MPI_ERR_RMA_ATTACH 56       /* */
#define A_MPI_ERR_RMA_SHARED 57       /* */
#define A_MPI_ERR_RMA_FLAVOR 58       /* */

/* Return codes for functions in the MPI Tool Information Interface */
#define A_MPI_T_ERR_MEMORY            59  /* Out of memory */
#define A_MPI_T_ERR_NOT_INITIALIZED   60  /* Interface not initialized */
#define A_MPI_T_ERR_CANNOT_INIT       61  /* Interface not in the state to
                                           be initialized */
#define A_MPI_T_ERR_INVALID_INDEX     62  /* The index is invalid or
                                           has been deleted  */
#define A_MPI_T_ERR_INVALID_ITEM      63  /* Item index queried is out of range */
#define A_MPI_T_ERR_INVALID_HANDLE    64  /* The handle is invalid */
#define A_MPI_T_ERR_OUT_OF_HANDLES    65  /* No more handles available */
#define A_MPI_T_ERR_OUT_OF_SESSIONS   66  /* No more sessions available */
#define A_MPI_T_ERR_INVALID_SESSION   67  /* Session argument is not valid */
#define A_MPI_T_ERR_CVAR_SET_NOT_NOW  68  /* Cvar can't be set at this moment */
#define A_MPI_T_ERR_CVAR_SET_NEVER    69  /* Cvar can't be set until
                                           end of execution */
#define A_MPI_T_ERR_PVAR_NO_STARTSTOP 70  /* Pvar can't be started or stopped */
#define A_MPI_T_ERR_PVAR_NO_WRITE     71  /* Pvar can't be written or reset */
#define A_MPI_T_ERR_PVAR_NO_ATOMIC    72  /* Pvar can't be R/W atomically */

#define A_MPI_ERR_LASTCODE    0x3fffffff  /* Last valid error code for a 
					   predefined error class */
#define A_MPI_T_ERR_INVALID_NAME      73  /* Name doesn't match */
#define A_MPI_T_ERR_INVALID           74  /* Generic error code for MPI_T added in MPI-3.1 */
/* WARNING: this is also defined in mpishared.h.  Update both locations */
#define MPICH_ERR_LAST_CLASS 74     /* It is also helpful to know the
				       last valid class */
/* End of MPI's error classes */

/* Function type defs */
typedef int (A_MPI_Datarep_conversion_function)(void *, A_MPI_Datatype, int, 
             void *, A_MPI_Offset, void *);
typedef int (A_MPI_Datarep_extent_function)(A_MPI_Datatype datatype, A_MPI_Aint *,
					  void *);
#define A_MPI_CONVERSION_FN_NULL ((A_MPI_Datarep_conversion_function *)0)

/* 
   For systems that may need to add additional definitions to support
   different declaration styles and options (e.g., different calling 
   conventions or DLL import/export controls).  
*/
/* --Insert Additional Definitions Here-- */

/*
 * Normally, we provide prototypes for all MPI routines.  In a few weird
 * cases, we need to suppress the prototypes.
 */
#ifndef MPICH_SUPPRESS_PROTOTYPES
/* We require that the C compiler support prototypes */
/* Begin Prototypes */
int A_MPI_Send( void *buf, int count, A_MPI_Datatype datatype, int dest, int tag,
             A_MPI_Comm comm) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_MPI_Recv(void *buf, int count, A_MPI_Datatype datatype, int source, int tag,
             A_MPI_Comm comm, A_MPI_Status *status) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_MPI_Get_count( A_MPI_Status *status, A_MPI_Datatype datatype, int *count);
int A_MPI_Bsend( void *buf, int count, A_MPI_Datatype datatype, int dest, int tag,
              A_MPI_Comm comm) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_MPI_Ssend( void *buf, int count, A_MPI_Datatype datatype, int dest, int tag,
              A_MPI_Comm comm) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_MPI_Rsend( void *buf, int count, A_MPI_Datatype datatype, int dest, int tag,
              A_MPI_Comm comm) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_MPI_Buffer_attach(void *buffer, int size);
int A_MPI_Buffer_detach(void *buffer_addr, int *size);
int A_MPI_Isend( void *buf, int count, A_MPI_Datatype datatype, int dest, int tag,
              A_MPI_Comm comm, A_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_MPI_Ibsend( void *buf, int count, A_MPI_Datatype datatype, int dest, int tag,
               A_MPI_Comm comm, A_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_MPI_Issend( void *buf, int count, A_MPI_Datatype datatype, int dest, int tag,
               A_MPI_Comm comm, A_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_MPI_Irsend( void *buf, int count, A_MPI_Datatype datatype, int dest, int tag,
               A_MPI_Comm comm, A_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_MPI_Irecv(void *buf, int count, A_MPI_Datatype datatype, int source, int tag,
              A_MPI_Comm comm, A_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_MPI_Wait(A_MPI_Request *request, A_MPI_Status *status);
int A_MPI_Test(A_MPI_Request *request, int *flag, A_MPI_Status *status);
int A_MPI_Request_free(A_MPI_Request *request);
int A_MPI_Waitany(int count, A_MPI_Request array_of_requests[], int *indx, A_MPI_Status *status);
int A_MPI_Testany(int count, A_MPI_Request array_of_requests[], int *indx, int *flag,
                A_MPI_Status *status);
int A_MPI_Waitall(int count, A_MPI_Request array_of_requests[], A_MPI_Status array_of_statuses[]);
int A_MPI_Testall(int count, A_MPI_Request array_of_requests[], int *flag,
                A_MPI_Status array_of_statuses[]);
int A_MPI_Waitsome(int incount, A_MPI_Request array_of_requests[], int *outcount,
                 int array_of_indices[], A_MPI_Status array_of_statuses[]);
int A_MPI_Testsome(int incount, A_MPI_Request array_of_requests[], int *outcount,
                 int array_of_indices[], A_MPI_Status array_of_statuses[]);
int A_MPI_Iprobe(int source, int tag, A_MPI_Comm comm, int *flag, A_MPI_Status *status);
int A_MPI_Probe(int source, int tag, A_MPI_Comm comm, A_MPI_Status *status);
int A_MPI_Cancel(A_MPI_Request *request);
int A_MPI_Test_cancelled( A_MPI_Status *status, int *flag);
int A_MPI_Send_init( void *buf, int count, A_MPI_Datatype datatype, int dest, int tag,
                  A_MPI_Comm comm, A_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_MPI_Bsend_init( void *buf, int count, A_MPI_Datatype datatype, int dest, int tag,
                   A_MPI_Comm comm, A_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_MPI_Ssend_init( void *buf, int count, A_MPI_Datatype datatype, int dest, int tag,
                   A_MPI_Comm comm, A_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_MPI_Rsend_init( void *buf, int count, A_MPI_Datatype datatype, int dest, int tag,
                   A_MPI_Comm comm, A_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_MPI_Recv_init(void *buf, int count, A_MPI_Datatype datatype, int source, int tag,
                  A_MPI_Comm comm, A_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_MPI_Start(A_MPI_Request *request);
int A_MPI_Startall(int count, A_MPI_Request array_of_requests[]);
int A_MPI_Sendrecv( void *sendbuf, int sendcount, A_MPI_Datatype sendtype, int dest,
                 int sendtag, void *recvbuf, int recvcount, A_MPI_Datatype recvtype,
                 int source, int recvtag, A_MPI_Comm comm, A_MPI_Status *status)
                 MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(6,8);
int A_MPI_Sendrecv_replace(void *buf, int count, A_MPI_Datatype datatype, int dest,
                         int sendtag, int source, int recvtag, A_MPI_Comm comm,
                         A_MPI_Status *status) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_MPI_Type_contiguous(int count, A_MPI_Datatype oldtype, A_MPI_Datatype *newtype);
int A_MPI_Type_vector(int count, int blocklength, int stride, A_MPI_Datatype oldtype,
                    A_MPI_Datatype *newtype);
int A_MPI_Type_hvector(int count, int blocklength, A_MPI_Aint stride, A_MPI_Datatype oldtype,
                     A_MPI_Datatype *newtype);
int A_MPI_Type_indexed(int count,  int *array_of_blocklengths,
                      int *array_of_displacements, A_MPI_Datatype oldtype,
                     A_MPI_Datatype *newtype);
int A_MPI_Type_hindexed(int count,  int *array_of_blocklengths,
                       A_MPI_Aint *array_of_displacements, A_MPI_Datatype oldtype,
                      A_MPI_Datatype *newtype);
int A_MPI_Type_struct(int count,  int *array_of_blocklengths,
                     A_MPI_Aint *array_of_displacements,
                     A_MPI_Datatype *array_of_types, A_MPI_Datatype *newtype);
int A_MPI_Address( void *location, A_MPI_Aint *address);
int A_MPI_Type_extent(A_MPI_Datatype datatype, A_MPI_Aint *extent);
int A_MPI_Type_size(A_MPI_Datatype datatype, int *size);
int A_MPI_Type_lb(A_MPI_Datatype datatype, A_MPI_Aint *displacement);
int A_MPI_Type_ub(A_MPI_Datatype datatype, A_MPI_Aint *displacement);
int A_MPI_Type_commit(A_MPI_Datatype *datatype);
int A_MPI_Type_free(A_MPI_Datatype *datatype);
int A_MPI_Get_elements( A_MPI_Status *status, A_MPI_Datatype datatype, int *count);
int A_MPI_Pack( void *inbuf, int incount, A_MPI_Datatype datatype, void *outbuf,
             int outsize, int *position, A_MPI_Comm comm) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_MPI_Unpack( void *inbuf, int insize, int *position, void *outbuf, int outcount,
               A_MPI_Datatype datatype, A_MPI_Comm comm) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int A_MPI_Pack_size(int incount, A_MPI_Datatype datatype, A_MPI_Comm comm, int *size);
int A_MPI_Barrier(A_MPI_Comm comm);
int A_MPI_Bcast(void *buffer, int count, A_MPI_Datatype datatype, int root, A_MPI_Comm comm)
              MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_MPI_Gather( void *sendbuf, int sendcount, A_MPI_Datatype sendtype, void *recvbuf,
               int recvcount, A_MPI_Datatype recvtype, int root, A_MPI_Comm comm)
               MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int A_MPI_Gatherv( void *sendbuf, int sendcount, A_MPI_Datatype sendtype, void *recvbuf,
                 int *recvcounts,  int *displs, A_MPI_Datatype recvtype, int root,
                A_MPI_Comm comm)
                MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,7);
int A_MPI_Scatter( void *sendbuf, int sendcount, A_MPI_Datatype sendtype, void *recvbuf,
                int recvcount, A_MPI_Datatype recvtype, int root, A_MPI_Comm comm)
                MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int A_MPI_Scatterv( void *sendbuf,  int *sendcounts,  int *displs,
                 A_MPI_Datatype sendtype, void *recvbuf, int recvcount, A_MPI_Datatype recvtype,
                 int root, A_MPI_Comm comm)
                 MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(5,7);
int A_MPI_Allgather( void *sendbuf, int sendcount, A_MPI_Datatype sendtype, void *recvbuf,
                  int recvcount, A_MPI_Datatype recvtype, A_MPI_Comm comm)
                  MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int A_MPI_Allgatherv( void *sendbuf, int sendcount, A_MPI_Datatype sendtype, void *recvbuf,
                    int *recvcounts,  int *displs, A_MPI_Datatype recvtype, A_MPI_Comm comm)
                   MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,7);
int A_MPI_Alltoall( void *sendbuf, int sendcount, A_MPI_Datatype sendtype, void *recvbuf,
                 int recvcount, A_MPI_Datatype recvtype, A_MPI_Comm comm)
                 MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int A_MPI_Alltoallv( void *sendbuf,  int *sendcounts,  int *sdispls,
                  A_MPI_Datatype sendtype, void *recvbuf,  int *recvcounts,
                   int *rdispls, A_MPI_Datatype recvtype, A_MPI_Comm comm)
                  MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(5,8);
int A_MPI_Alltoallw( void *sendbuf,  int sendcounts[],  int sdispls[],
                   A_MPI_Datatype sendtypes[], void *recvbuf,  int recvcounts[],
                   int rdispls[],  A_MPI_Datatype recvtypes[], A_MPI_Comm comm);
int A_MPI_Exscan( void *sendbuf, void *recvbuf, int count, A_MPI_Datatype datatype,
               A_MPI_Op op, A_MPI_Comm comm)
               MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_MPI_Reduce( void *sendbuf, void *recvbuf, int count, A_MPI_Datatype datatype,
               A_MPI_Op op, int root, A_MPI_Comm comm)
               MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_MPI_Op_create(A_MPI_User_function *user_fn, int commute, A_MPI_Op *op);
int A_MPI_Op_free(A_MPI_Op *op);
int A_MPI_Allreduce(void *sendbuf, void *recvbuf, int count, A_MPI_Datatype datatype,
                  A_MPI_Op op, A_MPI_Comm comm)
                  MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_MPI_Reduce_scatter( void *sendbuf, void *recvbuf,  int recvcounts[],
                       A_MPI_Datatype datatype, A_MPI_Op op, A_MPI_Comm comm)
                       MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_MPI_Scan( void *sendbuf, void *recvbuf, int count, A_MPI_Datatype datatype, A_MPI_Op op,
             A_MPI_Comm comm)
             MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_MPI_Group_size(A_MPI_Group group, int *size);
int A_MPI_Group_rank(A_MPI_Group group, int *rank);
int A_MPI_Group_translate_ranks(A_MPI_Group group1, int n,  int ranks1[], A_MPI_Group group2,
                              int ranks2[]);
int A_MPI_Group_compare(A_MPI_Group group1, A_MPI_Group group2, int *result);
int A_MPI_Comm_group(A_MPI_Comm comm, A_MPI_Group *group);
int A_MPI_Group_union(A_MPI_Group group1, A_MPI_Group group2, A_MPI_Group *newgroup);
int A_MPI_Group_intersection(A_MPI_Group group1, A_MPI_Group group2, A_MPI_Group *newgroup);
int A_MPI_Group_difference(A_MPI_Group group1, A_MPI_Group group2, A_MPI_Group *newgroup);
int A_MPI_Group_incl(A_MPI_Group group, int n,  int ranks[], A_MPI_Group *newgroup);
int A_MPI_Group_excl(A_MPI_Group group, int n,  int ranks[], A_MPI_Group *newgroup);
int A_MPI_Group_range_incl(A_MPI_Group group, int n, int ranges[][3], A_MPI_Group *newgroup);
int A_MPI_Group_range_excl(A_MPI_Group group, int n, int ranges[][3], A_MPI_Group *newgroup);
int A_MPI_Group_free(A_MPI_Group *group);
int A_MPI_Comm_size(A_MPI_Comm comm, int *size);
int A_MPI_Comm_rank(A_MPI_Comm comm, int *rank);
int A_MPI_Comm_compare(A_MPI_Comm comm1, A_MPI_Comm comm2, int *result);
int A_MPI_Comm_dup(A_MPI_Comm comm, A_MPI_Comm *newcomm);
int A_MPI_Comm_dup_with_info(A_MPI_Comm comm, A_MPI_Info info, A_MPI_Comm *newcomm);
int A_MPI_Comm_create(A_MPI_Comm comm, A_MPI_Group group, A_MPI_Comm *newcomm);
int A_MPI_Comm_split(A_MPI_Comm comm, int color, int key, A_MPI_Comm *newcomm);
int A_MPI_Comm_free(A_MPI_Comm *comm);
int A_MPI_Comm_test_inter(A_MPI_Comm comm, int *flag);
int A_MPI_Comm_remote_size(A_MPI_Comm comm, int *size);
int A_MPI_Comm_remote_group(A_MPI_Comm comm, A_MPI_Group *group);
int A_MPI_Intercomm_create(A_MPI_Comm local_comm, int local_leader, A_MPI_Comm peer_comm,
                         int remote_leader, int tag, A_MPI_Comm *newintercomm);
int A_MPI_Intercomm_merge(A_MPI_Comm intercomm, int high, A_MPI_Comm *newintracomm);
int A_MPI_Keyval_create(A_MPI_Copy_function *copy_fn, A_MPI_Delete_function *delete_fn,
                      int *keyval, void *extra_state);
int A_MPI_Keyval_free(int *keyval);
int A_MPI_Attr_put(A_MPI_Comm comm, int keyval, void *attribute_val);
int A_MPI_Attr_get(A_MPI_Comm comm, int keyval, void *attribute_val, int *flag);
int A_MPI_Attr_delete(A_MPI_Comm comm, int keyval);
int A_MPI_Topo_test(A_MPI_Comm comm, int *status);
int A_MPI_Cart_create(A_MPI_Comm comm_old, int ndims,  int dims[],  int periods[],
                    int reorder, A_MPI_Comm *comm_cart);
int A_MPI_Dims_create(int nnodes, int ndims, int dims[]);
int A_MPI_Graph_create(A_MPI_Comm comm_old, int nnodes,  int indx[],  int edges[],
                     int reorder, A_MPI_Comm *comm_graph);
int A_MPI_Graphdims_get(A_MPI_Comm comm, int *nnodes, int *nedges);
int A_MPI_Graph_get(A_MPI_Comm comm, int maxindex, int maxedges, int indx[], int edges[]);
int A_MPI_Cartdim_get(A_MPI_Comm comm, int *ndims);
int A_MPI_Cart_get(A_MPI_Comm comm, int maxdims, int dims[], int periods[], int coords[]);
int A_MPI_Cart_rank(A_MPI_Comm comm,  int coords[], int *rank);
int A_MPI_Cart_coords(A_MPI_Comm comm, int rank, int maxdims, int coords[]);
int A_MPI_Graph_neighbors_count(A_MPI_Comm comm, int rank, int *nneighbors);
int A_MPI_Graph_neighbors(A_MPI_Comm comm, int rank, int maxneighbors, int neighbors[]);
int A_MPI_Cart_shift(A_MPI_Comm comm, int direction, int disp, int *rank_source, int *rank_dest);
int A_MPI_Cart_sub(A_MPI_Comm comm,  int remain_dims[], A_MPI_Comm *newcomm);
int A_MPI_Cart_map(A_MPI_Comm comm, int ndims,  int dims[],  int periods[], int *newrank);
int A_MPI_Graph_map(A_MPI_Comm comm, int nnodes,  int indx[],  int edges[], int *newrank);
int A_MPI_Get_processor_name(char *name, int *resultlen);
int A_MPI_Get_version(int *version, int *subversion);
int A_MPI_Get_library_version(char *version, int *resultlen);
int A_MPI_Errhandler_create(A_MPI_Handler_function *function, A_MPI_Errhandler *errhandler);
int A_MPI_Errhandler_set(A_MPI_Comm comm, A_MPI_Errhandler errhandler);
int A_MPI_Errhandler_get(A_MPI_Comm comm, A_MPI_Errhandler *errhandler);
int A_MPI_Errhandler_free(A_MPI_Errhandler *errhandler);
int A_MPI_Error_string(int errorcode, char *string, int *resultlen);
int A_MPI_Error_class(int errorcode, int *errorclass);
double A_MPI_Wtime(void);
double A_MPI_Wtick(void);
int A_MPI_Init(int *argc, char ***argv);
int A_MPI_Finalize(void);
int A_MPI_Initialized(int *flag);
int A_MPI_Abort(A_MPI_Comm comm, int errorcode);

/* Note that we may need to define a @PCONTROL_LIST@ depending on whether
   stdargs are supported */
int A_MPI_Pcontrol( int level, ...);
int A_MPI_DUP_FN(A_MPI_Comm oldcomm, int keyval, void *extra_state, void *attribute_val_in,
               void *attribute_val_out, int *flag);

/* Process Creation and Management */
int A_MPI_Close_port( char *port_name);
int A_MPI_Comm_accept( char *port_name, A_MPI_Info info, int root, A_MPI_Comm comm,
                    A_MPI_Comm *newcomm);
int A_MPI_Comm_connect( char *port_name, A_MPI_Info info, int root, A_MPI_Comm comm,
                     A_MPI_Comm *newcomm);
int A_MPI_Comm_disconnect(A_MPI_Comm *comm);
int A_MPI_Comm_get_parent(A_MPI_Comm *parent);
int A_MPI_Comm_join(int fd, A_MPI_Comm *intercomm);
int A_MPI_Comm_spawn( char *command, char *argv[], int maxprocs, A_MPI_Info info, int root,
                   A_MPI_Comm comm, A_MPI_Comm *intercomm, int array_of_errcodes[]);
int A_MPI_Comm_spawn_multiple(int count, char *array_of_commands[], char **array_of_argv[],
                             int array_of_maxprocs[],  A_MPI_Info array_of_info[],
                            int root, A_MPI_Comm comm, A_MPI_Comm *intercomm, int array_of_errcodes[]);
int A_MPI_Lookup_name( char *service_name, A_MPI_Info info, char *port_name);
int A_MPI_Open_port(A_MPI_Info info, char *port_name);
int A_MPI_Publish_name( char *service_name, A_MPI_Info info,  char *port_name);
int A_MPI_Unpublish_name( char *service_name, A_MPI_Info info,  char *port_name);
int A_MPI_Comm_set_info(A_MPI_Comm comm, A_MPI_Info info);
int A_MPI_Comm_get_info(A_MPI_Comm comm, A_MPI_Info *info);

/* One-Sided Communications */
int A_MPI_Accumulate( void *origin_addr, int origin_count, A_MPI_Datatype origin_datatype,
                   int target_rank, A_MPI_Aint target_disp, int target_count,
                   A_MPI_Datatype target_datatype, A_MPI_Op op, A_MPI_Win win)
                   MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_MPI_Get(void *origin_addr, int origin_count, A_MPI_Datatype origin_datatype,
            int target_rank, A_MPI_Aint target_disp, int target_count,
            A_MPI_Datatype target_datatype, A_MPI_Win win) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_MPI_Put( void *origin_addr, int origin_count, A_MPI_Datatype origin_datatype,
            int target_rank, A_MPI_Aint target_disp, int target_count,
            A_MPI_Datatype target_datatype, A_MPI_Win win) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_MPI_Win_complete(A_MPI_Win win);
int A_MPI_Win_create(void *base, A_MPI_Aint size, int disp_unit, A_MPI_Info info, A_MPI_Comm comm,
                   A_MPI_Win *win);
int A_MPI_Win_fence(int assert, A_MPI_Win win);
int A_MPI_Win_free(A_MPI_Win *win);
int A_MPI_Win_get_group(A_MPI_Win win, A_MPI_Group *group);
int A_MPI_Win_lock(int lock_type, int rank, int assert, A_MPI_Win win);
int A_MPI_Win_post(A_MPI_Group group, int assert, A_MPI_Win win);
int A_MPI_Win_start(A_MPI_Group group, int assert, A_MPI_Win win);
int A_MPI_Win_test(A_MPI_Win win, int *flag);
int A_MPI_Win_unlock(int rank, A_MPI_Win win);
int A_MPI_Win_wait(A_MPI_Win win);

/* MPI-3 One-Sided Communication Routines */
int A_MPI_Win_allocate(A_MPI_Aint size, int disp_unit, A_MPI_Info info, A_MPI_Comm comm, void *baseptr,
                     A_MPI_Win *win);
int A_MPI_Win_allocate_shared(A_MPI_Aint size, int disp_unit, A_MPI_Info info, A_MPI_Comm comm,
                            void *baseptr, A_MPI_Win *win);
int A_MPI_Win_shared_query(A_MPI_Win win, int rank, A_MPI_Aint *size, int *disp_unit, void *baseptr);
int A_MPI_Win_create_dynamic(A_MPI_Info info, A_MPI_Comm comm, A_MPI_Win *win);
int A_MPI_Win_attach(A_MPI_Win win, void *base, A_MPI_Aint size);
int A_MPI_Win_detach(A_MPI_Win win,  void *base);
int A_MPI_Win_get_info(A_MPI_Win win, A_MPI_Info *info_used);
int A_MPI_Win_set_info(A_MPI_Win win, A_MPI_Info info);
int A_MPI_Get_accumulate( void *origin_addr, int origin_count,
                        A_MPI_Datatype origin_datatype, void *result_addr, int result_count,
                        A_MPI_Datatype result_datatype, int target_rank, A_MPI_Aint target_disp,
                        int target_count, A_MPI_Datatype target_datatype, A_MPI_Op op, A_MPI_Win win)
                        MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3)
                        MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int A_MPI_Fetch_and_op( void *origin_addr, void *result_addr,
                      A_MPI_Datatype datatype, int target_rank, A_MPI_Aint target_disp,
                      A_MPI_Op op, A_MPI_Win win)
                      MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_MPI_Compare_and_swap( void *origin_addr,  void *compare_addr,
                          void *result_addr, A_MPI_Datatype datatype, int target_rank,
                          A_MPI_Aint target_disp, A_MPI_Win win)
                          MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4)
                          MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4)
                          MPICH_ATTR_POINTER_WITH_TYPE_TAG(3,4);
int A_MPI_Rput( void *origin_addr, int origin_count,
              A_MPI_Datatype origin_datatype, int target_rank, A_MPI_Aint target_disp,
              int target_count, A_MPI_Datatype target_datatype, A_MPI_Win win,
              A_MPI_Request *request)
              MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_MPI_Rget(void *origin_addr, int origin_count,
              A_MPI_Datatype origin_datatype, int target_rank, A_MPI_Aint target_disp,
              int target_count, A_MPI_Datatype target_datatype, A_MPI_Win win,
              A_MPI_Request *request)
              MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_MPI_Raccumulate( void *origin_addr, int origin_count,
                     A_MPI_Datatype origin_datatype, int target_rank, A_MPI_Aint target_disp,
                     int target_count, A_MPI_Datatype target_datatype, A_MPI_Op op, A_MPI_Win win,
                     A_MPI_Request *request)
                     MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_MPI_Rget_accumulate( void *origin_addr, int origin_count,
                         A_MPI_Datatype origin_datatype, void *result_addr, int result_count,
                         A_MPI_Datatype result_datatype, int target_rank, A_MPI_Aint target_disp,
                         int target_count, A_MPI_Datatype target_datatype, A_MPI_Op op, A_MPI_Win win,
                         A_MPI_Request *request)
                         MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3)
                         MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int A_MPI_Win_lock_all(int assert, A_MPI_Win win);
int A_MPI_Win_unlock_all(A_MPI_Win win);
int A_MPI_Win_flush(int rank, A_MPI_Win win);
int A_MPI_Win_flush_all(A_MPI_Win win);
int A_MPI_Win_flush_local(int rank, A_MPI_Win win);
int A_MPI_Win_flush_local_all(A_MPI_Win win);
int A_MPI_Win_sync(A_MPI_Win win);
 
/* External Interfaces */
int A_MPI_Add_error_class(int *errorclass);
int A_MPI_Add_error_code(int errorclass, int *errorcode);
int A_MPI_Add_error_string(int errorcode,  char *string);
int A_MPI_Comm_call_errhandler(A_MPI_Comm comm, int errorcode);
int A_MPI_Comm_create_keyval(A_MPI_Comm_copy_attr_function *comm_copy_attr_fn,
                           A_MPI_Comm_delete_attr_function *comm_delete_attr_fn, int *comm_keyval,
                           void *extra_state);
int A_MPI_Comm_delete_attr(A_MPI_Comm comm, int comm_keyval);
int A_MPI_Comm_free_keyval(int *comm_keyval);
int A_MPI_Comm_get_attr(A_MPI_Comm comm, int comm_keyval, void *attribute_val, int *flag);
int A_MPI_Comm_get_name(A_MPI_Comm comm, char *comm_name, int *resultlen);
int A_MPI_Comm_set_attr(A_MPI_Comm comm, int comm_keyval, void *attribute_val);
int A_MPI_Comm_set_name(A_MPI_Comm comm,  char *comm_name);
int A_MPI_File_call_errhandler(A_MPI_File fh, int errorcode);
int A_MPI_Grequest_complete(A_MPI_Request request);
int A_MPI_Grequest_start(A_MPI_Grequest_query_function *query_fn, A_MPI_Grequest_free_function *free_fn,
                       A_MPI_Grequest_cancel_function *cancel_fn, void *extra_state,
                       A_MPI_Request *request);
int A_MPI_Init_thread(int *argc, char ***argv, int required, int *provided);
int A_MPI_Is_thread_main(int *flag);
int A_MPI_Query_thread(int *provided);
int A_MPI_Status_set_cancelled(A_MPI_Status *status, int flag);
int A_MPI_Status_set_elements(A_MPI_Status *status, A_MPI_Datatype datatype, int count);
int A_MPI_Type_create_keyval(A_MPI_Type_copy_attr_function *type_copy_attr_fn,
                           A_MPI_Type_delete_attr_function *type_delete_attr_fn,
                           int *type_keyval, void *extra_state);
int A_MPI_Type_delete_attr(A_MPI_Datatype datatype, int type_keyval);
int A_MPI_Type_dup(A_MPI_Datatype oldtype, A_MPI_Datatype *newtype);
int A_MPI_Type_free_keyval(int *type_keyval);
int A_MPI_Type_get_attr(A_MPI_Datatype datatype, int type_keyval, void *attribute_val, int *flag);
int A_MPI_Type_get_contents(A_MPI_Datatype datatype, int max_integers, int max_addresses,
                          int max_datatypes, int array_of_integers[],
                          A_MPI_Aint array_of_addresses[], A_MPI_Datatype array_of_datatypes[]);
int A_MPI_Type_get_envelope(A_MPI_Datatype datatype, int *num_integers, int *num_addresses,
                          int *num_datatypes, int *combiner);
int A_MPI_Type_get_name(A_MPI_Datatype datatype, char *type_name, int *resultlen);
int A_MPI_Type_set_attr(A_MPI_Datatype datatype, int type_keyval, void *attribute_val);
int A_MPI_Type_set_name(A_MPI_Datatype datatype,  char *type_name);
int A_MPI_Type_match_size(int typeclass, int size, A_MPI_Datatype *datatype);
int A_MPI_Win_call_errhandler(A_MPI_Win win, int errorcode);
int A_MPI_Win_create_keyval(A_MPI_Win_copy_attr_function *win_copy_attr_fn,
                          A_MPI_Win_delete_attr_function *win_delete_attr_fn, int *win_keyval,
                          void *extra_state);
int A_MPI_Win_delete_attr(A_MPI_Win win, int win_keyval);
int A_MPI_Win_free_keyval(int *win_keyval);
int A_MPI_Win_get_attr(A_MPI_Win win, int win_keyval, void *attribute_val, int *flag);
int A_MPI_Win_get_name(A_MPI_Win win, char *win_name, int *resultlen);
int A_MPI_Win_set_attr(A_MPI_Win win, int win_keyval, void *attribute_val);
int A_MPI_Win_set_name(A_MPI_Win win,  char *win_name);

int A_MPI_Alloc_mem(A_MPI_Aint size, A_MPI_Info info, void *baseptr);
int A_MPI_Comm_create_errhandler(A_MPI_Comm_errhandler_function *comm_errhandler_fn,
                               A_MPI_Errhandler *errhandler);
int A_MPI_Comm_get_errhandler(A_MPI_Comm comm, A_MPI_Errhandler *errhandler);
int A_MPI_Comm_set_errhandler(A_MPI_Comm comm, A_MPI_Errhandler errhandler);
int A_MPI_File_create_errhandler(A_MPI_File_errhandler_function *file_errhandler_fn,
                               A_MPI_Errhandler *errhandler);
int A_MPI_File_get_errhandler(A_MPI_File file, A_MPI_Errhandler *errhandler);
int A_MPI_File_set_errhandler(A_MPI_File file, A_MPI_Errhandler errhandler);
int A_MPI_Finalized(int *flag);
int A_MPI_Free_mem(void *base);
int A_MPI_Get_address( void *location, A_MPI_Aint *address);
int A_MPI_Info_create(A_MPI_Info *info);
int A_MPI_Info_delete(A_MPI_Info info,  char *key);
int A_MPI_Info_dup(A_MPI_Info info, A_MPI_Info *newinfo);
int A_MPI_Info_free(A_MPI_Info *info);
int A_MPI_Info_get(A_MPI_Info info,  char *key, int valuelen, char *value, int *flag);
int A_MPI_Info_get_nkeys(A_MPI_Info info, int *nkeys);
int A_MPI_Info_get_nthkey(A_MPI_Info info, int n, char *key);
int A_MPI_Info_get_valuelen(A_MPI_Info info,  char *key, int *valuelen, int *flag);
int A_MPI_Info_set(A_MPI_Info info,  char *key,  char *value);
int A_MPI_Pack_external( char datarep[],  void *inbuf, int incount,
                      A_MPI_Datatype datatype, void *outbuf, A_MPI_Aint outsize, A_MPI_Aint *position)
                      MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_MPI_Pack_external_size( char datarep[], int incount, A_MPI_Datatype datatype,
                           A_MPI_Aint *size);
int A_MPI_Request_get_status(A_MPI_Request request, int *flag, A_MPI_Status *status);
int A_MPI_Status_c2f( A_MPI_Status *c_status, A_MPI_Fint *f_status);
int A_MPI_Status_f2c( A_MPI_Fint *f_status, A_MPI_Status *c_status);
int A_MPI_Type_create_darray(int size, int rank, int ndims,  int array_of_gsizes[],
                            int array_of_distribs[],  int array_of_dargs[],
                            int array_of_psizes[], int order, A_MPI_Datatype oldtype,
                           A_MPI_Datatype *newtype);
int A_MPI_Type_create_hindexed(int count,  int array_of_blocklengths[],
                              A_MPI_Aint array_of_displacements[], A_MPI_Datatype oldtype,
                             A_MPI_Datatype *newtype);
int A_MPI_Type_create_hvector(int count, int blocklength, A_MPI_Aint stride, A_MPI_Datatype oldtype,
                            A_MPI_Datatype *newtype);
int A_MPI_Type_create_indexed_block(int count, int blocklength,  int array_of_displacements[],
                                  A_MPI_Datatype oldtype, A_MPI_Datatype *newtype);
int A_MPI_Type_create_hindexed_block(int count, int blocklength,
                                    A_MPI_Aint array_of_displacements[],
                                   A_MPI_Datatype oldtype, A_MPI_Datatype *newtype);
int A_MPI_Type_create_resized(A_MPI_Datatype oldtype, A_MPI_Aint lb, A_MPI_Aint extent,
                            A_MPI_Datatype *newtype);
int A_MPI_Type_create_struct(int count,  int array_of_blocklengths[],
                            A_MPI_Aint array_of_displacements[],
                            A_MPI_Datatype array_of_types[], A_MPI_Datatype *newtype);
int A_MPI_Type_create_subarray(int ndims,  int array_of_sizes[],
                              int array_of_subsizes[],  int array_of_starts[],
                             int order, A_MPI_Datatype oldtype, A_MPI_Datatype *newtype);
int A_MPI_Type_get_extent(A_MPI_Datatype datatype, A_MPI_Aint *lb, A_MPI_Aint *extent);
int A_MPI_Type_get_true_extent(A_MPI_Datatype datatype, A_MPI_Aint *true_lb, A_MPI_Aint *true_extent);
int A_MPI_Unpack_external( char datarep[],  void *inbuf, A_MPI_Aint insize,
                        A_MPI_Aint *position, void *outbuf, int outcount, A_MPI_Datatype datatype)
                        MPICH_ATTR_POINTER_WITH_TYPE_TAG(5,7);
int A_MPI_Win_create_errhandler(A_MPI_Win_errhandler_function *win_errhandler_fn,
                              A_MPI_Errhandler *errhandler);
int A_MPI_Win_get_errhandler(A_MPI_Win win, A_MPI_Errhandler *errhandler);
int A_MPI_Win_set_errhandler(A_MPI_Win win, A_MPI_Errhandler errhandler);

/* Fortran 90-related functions.  These routines are available only if
   Fortran 90 support is enabled 
*/
int A_MPI_Type_create_f90_integer(int range, A_MPI_Datatype *newtype);
int A_MPI_Type_create_f90_real(int precision, int range, A_MPI_Datatype *newtype);
int A_MPI_Type_create_f90_complex(int precision, int range, A_MPI_Datatype *newtype);

int A_MPI_Reduce_local( void *inbuf, void *inoutbuf, int count, A_MPI_Datatype datatype,
                     A_MPI_Op op)
                     MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_MPI_Op_commutative(A_MPI_Op op, int *commute);
int A_MPI_Reduce_scatter_block( void *sendbuf, void *recvbuf, int recvcount,
                             A_MPI_Datatype datatype, A_MPI_Op op, A_MPI_Comm comm)
                             MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4)
                             MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_MPI_Dist_graph_create_adjacent(A_MPI_Comm comm_old, int indegree,  int sources[],
                                    int sourceweights[], int outdegree,
                                    int destinations[],  int destweights[],
                                   A_MPI_Info info, int reorder, A_MPI_Comm *comm_dist_graph);
int A_MPI_Dist_graph_create(A_MPI_Comm comm_old, int n,  int sources[],  int degrees[],
                           int destinations[],  int weights[], A_MPI_Info info,
                          int reorder, A_MPI_Comm *comm_dist_graph);
int A_MPI_Dist_graph_neighbors_count(A_MPI_Comm comm, int *indegree, int *outdegree, int *weighted);
int A_MPI_Dist_graph_neighbors(A_MPI_Comm comm, int maxindegree, int sources[], int sourceweights[],
                             int maxoutdegree, int destinations[], int destweights[]);

/* Matched probe functionality */
int A_MPI_Improbe(int source, int tag, A_MPI_Comm comm, int *flag, A_MPI_Message *message,
                A_MPI_Status *status);
int A_MPI_Imrecv(void *buf, int count, A_MPI_Datatype datatype, A_MPI_Message *message,
               A_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_MPI_Mprobe(int source, int tag, A_MPI_Comm comm, A_MPI_Message *message, A_MPI_Status *status);
int A_MPI_Mrecv(void *buf, int count, A_MPI_Datatype datatype, A_MPI_Message *message,
              A_MPI_Status *status) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);

/* Nonblocking collectives */
int A_MPI_Comm_idup(A_MPI_Comm comm, A_MPI_Comm *newcomm, A_MPI_Request *request);
int A_MPI_Ibarrier(A_MPI_Comm comm, A_MPI_Request *request);
int A_MPI_Ibcast(void *buffer, int count, A_MPI_Datatype datatype, int root, A_MPI_Comm comm,
               A_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_MPI_Igather( void *sendbuf, int sendcount, A_MPI_Datatype sendtype, void *recvbuf,
                int recvcount, A_MPI_Datatype recvtype, int root, A_MPI_Comm comm,
                A_MPI_Request *request)
                MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int A_MPI_Igatherv( void *sendbuf, int sendcount, A_MPI_Datatype sendtype, void *recvbuf,
                  int recvcounts[],  int displs[], A_MPI_Datatype recvtype, int root,
                 A_MPI_Comm comm, A_MPI_Request *request)
                 MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,7);
int A_MPI_Iscatter( void *sendbuf, int sendcount, A_MPI_Datatype sendtype, void *recvbuf,
                 int recvcount, A_MPI_Datatype recvtype, int root, A_MPI_Comm comm,
                 A_MPI_Request *request)
                 MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int A_MPI_Iscatterv( void *sendbuf,  int sendcounts[],  int displs[],
                  A_MPI_Datatype sendtype, void *recvbuf, int recvcount, A_MPI_Datatype recvtype,
                  int root, A_MPI_Comm comm, A_MPI_Request *request)
                  MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(5,7);
int A_MPI_Iallgather( void *sendbuf, int sendcount, A_MPI_Datatype sendtype, void *recvbuf,
                   int recvcount, A_MPI_Datatype recvtype, A_MPI_Comm comm, A_MPI_Request *request)
                   MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int A_MPI_Iallgatherv( void *sendbuf, int sendcount, A_MPI_Datatype sendtype, void *recvbuf,
                     int recvcounts[],  int displs[], A_MPI_Datatype recvtype,
                    A_MPI_Comm comm, A_MPI_Request *request)
                    MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,7);
int A_MPI_Ialltoall( void *sendbuf, int sendcount, A_MPI_Datatype sendtype, void *recvbuf,
                  int recvcount, A_MPI_Datatype recvtype, A_MPI_Comm comm, A_MPI_Request *request)
                  MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int A_MPI_Ialltoallv( void *sendbuf,  int sendcounts[],  int sdispls[],
                   A_MPI_Datatype sendtype, void *recvbuf,  int recvcounts[],
                    int rdispls[], A_MPI_Datatype recvtype, A_MPI_Comm comm,
                   A_MPI_Request *request)
                   MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(5,8);
int A_MPI_Ialltoallw( void *sendbuf,  int sendcounts[],  int sdispls[],
                    A_MPI_Datatype sendtypes[], void *recvbuf,  int recvcounts[],
                    int rdispls[],  A_MPI_Datatype recvtypes[], A_MPI_Comm comm,
                   A_MPI_Request *request);
int A_MPI_Ireduce( void *sendbuf, void *recvbuf, int count, A_MPI_Datatype datatype,
                A_MPI_Op op, int root, A_MPI_Comm comm, A_MPI_Request *request)
                MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_MPI_Iallreduce( void *sendbuf, void *recvbuf, int count, A_MPI_Datatype datatype,
                   A_MPI_Op op, A_MPI_Comm comm, A_MPI_Request *request)
                   MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_MPI_Ireduce_scatter( void *sendbuf, void *recvbuf,  int recvcounts[],
                        A_MPI_Datatype datatype, A_MPI_Op op, A_MPI_Comm comm, A_MPI_Request *request)
                        MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_MPI_Ireduce_scatter_block( void *sendbuf, void *recvbuf, int recvcount,
                              A_MPI_Datatype datatype, A_MPI_Op op, A_MPI_Comm comm,
                              A_MPI_Request *request)
                              MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4)
                              MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_MPI_Iscan( void *sendbuf, void *recvbuf, int count, A_MPI_Datatype datatype, A_MPI_Op op,
              A_MPI_Comm comm, A_MPI_Request *request)
              MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_MPI_Iexscan( void *sendbuf, void *recvbuf, int count, A_MPI_Datatype datatype,
                A_MPI_Op op, A_MPI_Comm comm, A_MPI_Request *request)
                MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);

/* Neighborhood collectives */
int A_MPI_Ineighbor_allgather( void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                            void *recvbuf, int recvcount, A_MPI_Datatype recvtype,
                            A_MPI_Comm comm, A_MPI_Request *request)
                            MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3)
                            MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int A_MPI_Ineighbor_allgatherv( void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                             void *recvbuf,  int recvcounts[],  int displs[],
                             A_MPI_Datatype recvtype, A_MPI_Comm comm, A_MPI_Request *request)
                             MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3)
                             MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,7);
int A_MPI_Ineighbor_alltoall( void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                           void *recvbuf, int recvcount, A_MPI_Datatype recvtype, A_MPI_Comm comm,
                           A_MPI_Request *request)
                           MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3)
                           MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int A_MPI_Ineighbor_alltoallv( void *sendbuf,  int sendcounts[],  int sdispls[],
                            A_MPI_Datatype sendtype, void *recvbuf,  int recvcounts[],
                             int rdispls[], A_MPI_Datatype recvtype, A_MPI_Comm comm,
                            A_MPI_Request *request)
                            MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4)
                            MPICH_ATTR_POINTER_WITH_TYPE_TAG(5,8);
int A_MPI_Ineighbor_alltoallw( void *sendbuf,  int sendcounts[],
                             A_MPI_Aint sdispls[],  A_MPI_Datatype sendtypes[],
                            void *recvbuf,  int recvcounts[],  A_MPI_Aint rdispls[],
                             A_MPI_Datatype recvtypes[], A_MPI_Comm comm, A_MPI_Request *request);
int A_MPI_Neighbor_allgather( void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                           void *recvbuf, int recvcount, A_MPI_Datatype recvtype, A_MPI_Comm comm)
                           MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3)
                           MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int A_MPI_Neighbor_allgatherv( void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                            void *recvbuf,  int recvcounts[],  int displs[],
                            A_MPI_Datatype recvtype, A_MPI_Comm comm)
                            MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3)
                            MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,7);
int A_MPI_Neighbor_alltoall( void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                          void *recvbuf, int recvcount, A_MPI_Datatype recvtype, A_MPI_Comm comm)
                          MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3)
                          MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int A_MPI_Neighbor_alltoallv( void *sendbuf,  int sendcounts[],  int sdispls[],
                           A_MPI_Datatype sendtype, void *recvbuf,  int recvcounts[],
                            int rdispls[], A_MPI_Datatype recvtype, A_MPI_Comm comm)
                           MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4)
                           MPICH_ATTR_POINTER_WITH_TYPE_TAG(5,8);
int A_MPI_Neighbor_alltoallw( void *sendbuf,  int sendcounts[],  A_MPI_Aint sdispls[],
                            A_MPI_Datatype sendtypes[], void *recvbuf,  int recvcounts[],
                            A_MPI_Aint rdispls[],  A_MPI_Datatype recvtypes[], A_MPI_Comm comm);

/* Shared memory */
int A_MPI_Comm_split_type(A_MPI_Comm comm, int split_type, int key, A_MPI_Info info, A_MPI_Comm *newcomm);

/* MPI-3 "large count" routines */
int A_MPI_Get_elements_x( A_MPI_Status *status, A_MPI_Datatype datatype, A_MPI_Count *count);
int A_MPI_Status_set_elements_x(A_MPI_Status *status, A_MPI_Datatype datatype, A_MPI_Count count);
int A_MPI_Type_get_extent_x(A_MPI_Datatype datatype, A_MPI_Count *lb, A_MPI_Count *extent);
int A_MPI_Type_get_true_extent_x(A_MPI_Datatype datatype, A_MPI_Count *lb, A_MPI_Count *extent);
int A_MPI_Type_size_x(A_MPI_Datatype datatype, A_MPI_Count *size);

/* Noncollective communicator creation */
int A_MPI_Comm_create_group(A_MPI_Comm comm, A_MPI_Group group, int tag, A_MPI_Comm *newcomm);


/* Non-standard but public extensions to MPI */
/* Fault Tolerance Extensions */
int MPIX_Comm_group_failed(A_MPI_Comm comm, A_MPI_Group *failed_group);
int MPIX_Comm_remote_group_failed(A_MPI_Comm comm, A_MPI_Group *failed_group);
int MPIX_Comm_reenable_anysource(A_MPI_Comm comm, A_MPI_Group *failed_group);


/* A_MPI_T interface */
/* The A_MPI_T routines are available only in C bindings - tell tools that they
   can skip these prototypes */
/* Begin Skip Prototypes */
int A_MPI_T_init_thread(int required, int *provided);
int A_MPI_T_finalize(void);
int A_MPI_T_enum_get_info(A_MPI_T_enum enumtype, int *num, char *name, int *name_len);
int A_MPI_T_enum_get_item(A_MPI_T_enum enumtype, int indx, int *value, char *name, int *name_len);
int A_MPI_T_cvar_get_num(int *num_cvar);
int A_MPI_T_cvar_get_info(int cvar_index, char *name, int *name_len, int *verbosity,
                        A_MPI_Datatype *datatype, A_MPI_T_enum *enumtype, char *desc, int *desc_len,
                        int *binding, int *scope);
int A_MPI_T_cvar_handle_alloc(int cvar_index, void *obj_handle, A_MPI_T_cvar_handle *handle,
                            int *count);
int A_MPI_T_cvar_handle_free(A_MPI_T_cvar_handle *handle);
int A_MPI_T_cvar_read(A_MPI_T_cvar_handle handle, void *buf);
int A_MPI_T_cvar_write(A_MPI_T_cvar_handle handle,  void *buf);
int A_MPI_T_pvar_get_num(int *num_pvar);
int A_MPI_T_pvar_get_info(int pvar_index, char *name, int *name_len, int *verbosity, int *var_class,
                        A_MPI_Datatype *datatype, A_MPI_T_enum *enumtype, char *desc, int *desc_len,
                        int *binding, int *readonly, int *continuous, int *atomic);
int A_MPI_T_pvar_session_create(A_MPI_T_pvar_session *session);
int A_MPI_T_pvar_session_free(A_MPI_T_pvar_session *session);
int A_MPI_T_pvar_handle_alloc(A_MPI_T_pvar_session session, int pvar_index, void *obj_handle,
                            A_MPI_T_pvar_handle *handle, int *count);
int A_MPI_T_pvar_handle_free(A_MPI_T_pvar_session session, A_MPI_T_pvar_handle *handle);
int A_MPI_T_pvar_start(A_MPI_T_pvar_session session, A_MPI_T_pvar_handle handle);
int A_MPI_T_pvar_stop(A_MPI_T_pvar_session session, A_MPI_T_pvar_handle handle);
int A_MPI_T_pvar_read(A_MPI_T_pvar_session session, A_MPI_T_pvar_handle handle, void *buf);
int A_MPI_T_pvar_write(A_MPI_T_pvar_session session, A_MPI_T_pvar_handle handle,  void *buf);
int A_MPI_T_pvar_reset(A_MPI_T_pvar_session session, A_MPI_T_pvar_handle handle);
int A_MPI_T_pvar_readreset(A_MPI_T_pvar_session session, A_MPI_T_pvar_handle handle, void *buf);
int A_MPI_T_category_get_num(int *num_cat);
int A_MPI_T_category_get_info(int cat_index, char *name, int *name_len, char *desc, int *desc_len,
                            int *num_cvars, int *num_pvars, int *num_categories);
int A_MPI_T_category_get_cvars(int cat_index, int len, int indices[]);
int A_MPI_T_category_get_pvars(int cat_index, int len, int indices[]);
int A_MPI_T_category_get_categories(int cat_index, int len, int indices[]);
int A_MPI_T_category_changed(int *stamp);
/* End Skip Prototypes */
/* End Prototypes */
#endif /* MPICH_SUPPRESS_PROTOTYPES */


/* Here are the bindings of the profiling routines */
#if !defined(A_MPI_BUILD_PROFILING)
int A_PMPI_Send( void *buf, int count, A_MPI_Datatype datatype, int dest, int tag,
              A_MPI_Comm comm) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_PMPI_Recv(void *buf, int count, A_MPI_Datatype datatype, int source, int tag,
              A_MPI_Comm comm, A_MPI_Status *status) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_PMPI_Get_count( A_MPI_Status *status, A_MPI_Datatype datatype, int *count);
int A_PMPI_Bsend( void *buf, int count, A_MPI_Datatype datatype, int dest, int tag,
               A_MPI_Comm comm) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_PMPI_Ssend( void *buf, int count, A_MPI_Datatype datatype, int dest, int tag,
               A_MPI_Comm comm) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_PMPI_Rsend( void *buf, int count, A_MPI_Datatype datatype, int dest, int tag,
               A_MPI_Comm comm) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_PMPI_Buffer_attach(void *buffer, int size);
int A_PMPI_Buffer_detach(void *buffer_addr, int *size);
int A_PMPI_Isend( void *buf, int count, A_MPI_Datatype datatype, int dest, int tag,
               A_MPI_Comm comm, A_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_PMPI_Ibsend( void *buf, int count, A_MPI_Datatype datatype, int dest, int tag,
                A_MPI_Comm comm, A_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_PMPI_Issend( void *buf, int count, A_MPI_Datatype datatype, int dest, int tag,
                A_MPI_Comm comm, A_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_PMPI_Irsend( void *buf, int count, A_MPI_Datatype datatype, int dest, int tag,
                A_MPI_Comm comm, A_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_PMPI_Irecv(void *buf, int count, A_MPI_Datatype datatype, int source, int tag,
               A_MPI_Comm comm, A_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_PMPI_Wait(A_MPI_Request *request, A_MPI_Status *status);
int A_PMPI_Test(A_MPI_Request *request, int *flag, A_MPI_Status *status);
int A_PMPI_Request_free(A_MPI_Request *request);
int A_PMPI_Waitany(int count, A_MPI_Request array_of_requests[], int *indx, A_MPI_Status *status);
int A_PMPI_Testany(int count, A_MPI_Request array_of_requests[], int *indx, int *flag,
                 A_MPI_Status *status);
int A_PMPI_Waitall(int count, A_MPI_Request array_of_requests[], A_MPI_Status array_of_statuses[]);
int A_PMPI_Testall(int count, A_MPI_Request array_of_requests[], int *flag,
                 A_MPI_Status array_of_statuses[]);
int A_PMPI_Waitsome(int incount, A_MPI_Request array_of_requests[], int *outcount,
                  int array_of_indices[], A_MPI_Status array_of_statuses[]);
int A_PMPI_Testsome(int incount, A_MPI_Request array_of_requests[], int *outcount,
                  int array_of_indices[], A_MPI_Status array_of_statuses[]);
int A_PMPI_Iprobe(int source, int tag, A_MPI_Comm comm, int *flag, A_MPI_Status *status);
int A_PMPI_Probe(int source, int tag, A_MPI_Comm comm, A_MPI_Status *status);
int A_PMPI_Cancel(A_MPI_Request *request);
int A_PMPI_Test_cancelled( A_MPI_Status *status, int *flag);
int A_PMPI_Send_init( void *buf, int count, A_MPI_Datatype datatype, int dest, int tag,
                   A_MPI_Comm comm, A_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_PMPI_Bsend_init( void *buf, int count, A_MPI_Datatype datatype, int dest, int tag,
                    A_MPI_Comm comm, A_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_PMPI_Ssend_init( void *buf, int count, A_MPI_Datatype datatype, int dest, int tag,
                    A_MPI_Comm comm, A_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_PMPI_Rsend_init( void *buf, int count, A_MPI_Datatype datatype, int dest, int tag,
                    A_MPI_Comm comm, A_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_PMPI_Recv_init(void *buf, int count, A_MPI_Datatype datatype, int source, int tag,
                   A_MPI_Comm comm, A_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_PMPI_Start(A_MPI_Request *request);
int A_PMPI_Startall(int count, A_MPI_Request array_of_requests[]);
int A_PMPI_Sendrecv( void *sendbuf, int sendcount, A_MPI_Datatype sendtype, int dest,
                  int sendtag, void *recvbuf, int recvcount, A_MPI_Datatype recvtype,
                  int source, int recvtag, A_MPI_Comm comm, A_MPI_Status *status)
                  MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3)
                  MPICH_ATTR_POINTER_WITH_TYPE_TAG(6,8);
int A_PMPI_Sendrecv_replace(void *buf, int count, A_MPI_Datatype datatype, int dest,
                          int sendtag, int source, int recvtag, A_MPI_Comm comm,
                          A_MPI_Status *status) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_PMPI_Type_contiguous(int count, A_MPI_Datatype oldtype, A_MPI_Datatype *newtype);
int A_PMPI_Type_vector(int count, int blocklength, int stride, A_MPI_Datatype oldtype,
                     A_MPI_Datatype *newtype);
int A_PMPI_Type_hvector(int count, int blocklength, A_MPI_Aint stride, A_MPI_Datatype oldtype,
                      A_MPI_Datatype *newtype);
int A_PMPI_Type_indexed(int count,  int *array_of_blocklengths,
                       int *array_of_displacements, A_MPI_Datatype oldtype,
                      A_MPI_Datatype *newtype);
int A_PMPI_Type_hindexed(int count,  int *array_of_blocklengths,
                        A_MPI_Aint *array_of_displacements, A_MPI_Datatype oldtype,
                       A_MPI_Datatype *newtype);
int A_PMPI_Type_struct(int count,  int *array_of_blocklengths,
                      A_MPI_Aint *array_of_displacements,
                      A_MPI_Datatype *array_of_types, A_MPI_Datatype *newtype);
int A_PMPI_Address( void *location, A_MPI_Aint *address);
int A_PMPI_Type_extent(A_MPI_Datatype datatype, A_MPI_Aint *extent);
int A_PMPI_Type_size(A_MPI_Datatype datatype, int *size);
int A_PMPI_Type_lb(A_MPI_Datatype datatype, A_MPI_Aint *displacement);
int A_PMPI_Type_ub(A_MPI_Datatype datatype, A_MPI_Aint *displacement);
int A_PMPI_Type_commit(A_MPI_Datatype *datatype);
int A_PMPI_Type_free(A_MPI_Datatype *datatype);
int A_PMPI_Get_elements( A_MPI_Status *status, A_MPI_Datatype datatype, int *count);
int A_PMPI_Pack( void *inbuf, int incount, A_MPI_Datatype datatype, void *outbuf,
              int outsize, int *position, A_MPI_Comm comm) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_PMPI_Unpack( void *inbuf, int insize, int *position, void *outbuf, int outcount,
                A_MPI_Datatype datatype, A_MPI_Comm comm) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int A_PMPI_Pack_size(int incount, A_MPI_Datatype datatype, A_MPI_Comm comm, int *size);
int A_PMPI_Barrier(A_MPI_Comm comm);
int A_PMPI_Bcast(void *buffer, int count, A_MPI_Datatype datatype, int root, A_MPI_Comm comm)
               MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_PMPI_Gather( void *sendbuf, int sendcount, A_MPI_Datatype sendtype, void *recvbuf,
                int recvcount, A_MPI_Datatype recvtype, int root, A_MPI_Comm comm)
                MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int A_PMPI_Gatherv( void *sendbuf, int sendcount, A_MPI_Datatype sendtype, void *recvbuf,
                  int *recvcounts,  int *displs, A_MPI_Datatype recvtype, int root,
                 A_MPI_Comm comm)
                 MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,7);
int A_PMPI_Scatter( void *sendbuf, int sendcount, A_MPI_Datatype sendtype, void *recvbuf,
                 int recvcount, A_MPI_Datatype recvtype, int root, A_MPI_Comm comm)
                 MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int A_PMPI_Scatterv( void *sendbuf,  int *sendcounts,  int *displs,
                  A_MPI_Datatype sendtype, void *recvbuf, int recvcount, A_MPI_Datatype recvtype,
                  int root, A_MPI_Comm comm)
                  MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(5,7);
int A_PMPI_Allgather( void *sendbuf, int sendcount, A_MPI_Datatype sendtype, void *recvbuf,
                   int recvcount, A_MPI_Datatype recvtype, A_MPI_Comm comm)
                   MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int A_PMPI_Allgatherv( void *sendbuf, int sendcount, A_MPI_Datatype sendtype, void *recvbuf,
                     int *recvcounts,  int *displs, A_MPI_Datatype recvtype, A_MPI_Comm comm)
                    MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,7);
int A_PMPI_Alltoall( void *sendbuf, int sendcount, A_MPI_Datatype sendtype, void *recvbuf,
                  int recvcount, A_MPI_Datatype recvtype, A_MPI_Comm comm)
                  MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int A_PMPI_Alltoallv( void *sendbuf,  int *sendcounts,  int *sdispls,
                   A_MPI_Datatype sendtype, void *recvbuf,  int *recvcounts,
                    int *rdispls, A_MPI_Datatype recvtype, A_MPI_Comm comm)
                   MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(5,8);
int A_PMPI_Alltoallw( void *sendbuf,  int sendcounts[],  int sdispls[],
                    A_MPI_Datatype sendtypes[], void *recvbuf,  int recvcounts[],
                    int rdispls[],  A_MPI_Datatype recvtypes[], A_MPI_Comm comm);
int A_PMPI_Exscan( void *sendbuf, void *recvbuf, int count, A_MPI_Datatype datatype,
                A_MPI_Op op, A_MPI_Comm comm)
                MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_PMPI_Reduce( void *sendbuf, void *recvbuf, int count, A_MPI_Datatype datatype,
                A_MPI_Op op, int root, A_MPI_Comm comm)
                MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_PMPI_Op_create(A_MPI_User_function *user_fn, int commute, A_MPI_Op *op);
int A_PMPI_Op_free(A_MPI_Op *op);
int A_PMPI_Allreduce( void *sendbuf, void *recvbuf, int count, A_MPI_Datatype datatype,
                   A_MPI_Op op, A_MPI_Comm comm)
                   MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_PMPI_Reduce_scatter( void *sendbuf, void *recvbuf,  int recvcounts[],
                        A_MPI_Datatype datatype, A_MPI_Op op, A_MPI_Comm comm)
                        MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_PMPI_Scan( void *sendbuf, void *recvbuf, int count, A_MPI_Datatype datatype, A_MPI_Op op,
              A_MPI_Comm comm)
              MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_PMPI_Group_size(A_MPI_Group group, int *size);
int A_PMPI_Group_rank(A_MPI_Group group, int *rank);
int A_PMPI_Group_translate_ranks(A_MPI_Group group1, int n,  int ranks1[], A_MPI_Group group2,
                               int ranks2[]);
int A_PMPI_Group_compare(A_MPI_Group group1, A_MPI_Group group2, int *result);
int A_PMPI_Comm_group(A_MPI_Comm comm, A_MPI_Group *group);
int A_PMPI_Group_union(A_MPI_Group group1, A_MPI_Group group2, A_MPI_Group *newgroup);
int A_PMPI_Group_intersection(A_MPI_Group group1, A_MPI_Group group2, A_MPI_Group *newgroup);
int A_PMPI_Group_difference(A_MPI_Group group1, A_MPI_Group group2, A_MPI_Group *newgroup);
int A_PMPI_Group_incl(A_MPI_Group group, int n,  int ranks[], A_MPI_Group *newgroup);
int A_PMPI_Group_excl(A_MPI_Group group, int n,  int ranks[], A_MPI_Group *newgroup);
int A_PMPI_Group_range_incl(A_MPI_Group group, int n, int ranges[][3], A_MPI_Group *newgroup);
int A_PMPI_Group_range_excl(A_MPI_Group group, int n, int ranges[][3], A_MPI_Group *newgroup);
int A_PMPI_Group_free(A_MPI_Group *group);
int A_PMPI_Comm_size(A_MPI_Comm comm, int *size);
int A_PMPI_Comm_rank(A_MPI_Comm comm, int *rank);
int A_PMPI_Comm_compare(A_MPI_Comm comm1, A_MPI_Comm comm2, int *result);
int A_PMPI_Comm_dup(A_MPI_Comm comm, A_MPI_Comm *newcomm);
int A_PMPI_Comm_dup_with_info(A_MPI_Comm comm, A_MPI_Info info, A_MPI_Comm *newcomm);
int A_PMPI_Comm_create(A_MPI_Comm comm, A_MPI_Group group, A_MPI_Comm *newcomm);
int A_PMPI_Comm_split(A_MPI_Comm comm, int color, int key, A_MPI_Comm *newcomm);
int A_PMPI_Comm_free(A_MPI_Comm *comm);
int A_PMPI_Comm_test_inter(A_MPI_Comm comm, int *flag);
int A_PMPI_Comm_remote_size(A_MPI_Comm comm, int *size);
int A_PMPI_Comm_remote_group(A_MPI_Comm comm, A_MPI_Group *group);
int A_PMPI_Intercomm_create(A_MPI_Comm local_comm, int local_leader, A_MPI_Comm peer_comm,
                          int remote_leader, int tag, A_MPI_Comm *newintercomm);
int A_PMPI_Intercomm_merge(A_MPI_Comm intercomm, int high, A_MPI_Comm *newintracomm);
int A_PMPI_Keyval_create(A_MPI_Copy_function *copy_fn, A_MPI_Delete_function *delete_fn,
                       int *keyval, void *extra_state);
int A_PMPI_Keyval_free(int *keyval);
int A_PMPI_Attr_put(A_MPI_Comm comm, int keyval, void *attribute_val);
int A_PMPI_Attr_get(A_MPI_Comm comm, int keyval, void *attribute_val, int *flag);
int A_PMPI_Attr_delete(A_MPI_Comm comm, int keyval);
int A_PMPI_Topo_test(A_MPI_Comm comm, int *status);
int A_PMPI_Cart_create(A_MPI_Comm comm_old, int ndims,  int dims[],  int periods[],
                     int reorder, A_MPI_Comm *comm_cart);
int A_PMPI_Dims_create(int nnodes, int ndims, int dims[]);
int A_PMPI_Graph_create(A_MPI_Comm comm_old, int nnodes,  int indx[],  int edges[],
                      int reorder, A_MPI_Comm *comm_graph);
int A_PMPI_Graphdims_get(A_MPI_Comm comm, int *nnodes, int *nedges);
int A_PMPI_Graph_get(A_MPI_Comm comm, int maxindex, int maxedges, int indx[], int edges[]);
int A_PMPI_Cartdim_get(A_MPI_Comm comm, int *ndims);
int A_PMPI_Cart_get(A_MPI_Comm comm, int maxdims, int dims[], int periods[], int coords[]);
int A_PMPI_Cart_rank(A_MPI_Comm comm,  int coords[], int *rank);
int A_PMPI_Cart_coords(A_MPI_Comm comm, int rank, int maxdims, int coords[]);
int A_PMPI_Graph_neighbors_count(A_MPI_Comm comm, int rank, int *nneighbors);
int A_PMPI_Graph_neighbors(A_MPI_Comm comm, int rank, int maxneighbors, int neighbors[]);
int A_PMPI_Cart_shift(A_MPI_Comm comm, int direction, int disp, int *rank_source, int *rank_dest);
int A_PMPI_Cart_sub(A_MPI_Comm comm,  int remain_dims[], A_MPI_Comm *newcomm);
int A_PMPI_Cart_map(A_MPI_Comm comm, int ndims,  int dims[],  int periods[], int *newrank);
int A_PMPI_Graph_map(A_MPI_Comm comm, int nnodes,  int indx[],  int edges[], int *newrank);
int A_PMPI_Get_processor_name(char *name, int *resultlen);
int A_PMPI_Get_version(int *version, int *subversion);
int A_PMPI_Get_library_version(char *version, int *resultlen);
int A_PMPI_Errhandler_create(A_MPI_Handler_function *function, A_MPI_Errhandler *errhandler);
int A_PMPI_Errhandler_set(A_MPI_Comm comm, A_MPI_Errhandler errhandler);
int A_PMPI_Errhandler_get(A_MPI_Comm comm, A_MPI_Errhandler *errhandler);
int A_PMPI_Errhandler_free(A_MPI_Errhandler *errhandler);
int A_PMPI_Error_string(int errorcode, char *string, int *resultlen);
int A_PMPI_Error_class(int errorcode, int *errorclass);
double A_PMPI_Wtime(void);
double A_PMPI_Wtick(void);
int A_PMPI_Init(int *argc, char ***argv);
int A_PMPI_Finalize(void);
int A_PMPI_Initialized(int *flag);
int A_PMPI_Abort(A_MPI_Comm comm, int errorcode);

/* Note that we may need to define a @PCONTROL_LIST@ depending on whether
   stdargs are supported */
int A_PMPI_Pcontrol( int level, ...);

/* Process Creation and Management */
int A_PMPI_Close_port( char *port_name);
int A_PMPI_Comm_accept( char *port_name, A_MPI_Info info, int root, A_MPI_Comm comm,
                     A_MPI_Comm *newcomm);
int A_PMPI_Comm_connect( char *port_name, A_MPI_Info info, int root, A_MPI_Comm comm,
                      A_MPI_Comm *newcomm);
int A_PMPI_Comm_disconnect(A_MPI_Comm *comm);
int A_PMPI_Comm_get_parent(A_MPI_Comm *parent);
int A_PMPI_Comm_join(int fd, A_MPI_Comm *intercomm);
int A_PMPI_Comm_spawn( char *command, char *argv[], int maxprocs, A_MPI_Info info, int root,
                    A_MPI_Comm comm, A_MPI_Comm *intercomm, int array_of_errcodes[]);
int A_PMPI_Comm_spawn_multiple(int count, char *array_of_commands[], char **array_of_argv[],
                              int array_of_maxprocs[],  A_MPI_Info array_of_info[],
                             int root, A_MPI_Comm comm, A_MPI_Comm *intercomm, int array_of_errcodes[]);
int A_PMPI_Lookup_name( char *service_name, A_MPI_Info info, char *port_name);
int A_PMPI_Open_port(A_MPI_Info info, char *port_name);
int A_PMPI_Publish_name( char *service_name, A_MPI_Info info,  char *port_name);
int A_PMPI_Unpublish_name( char *service_name, A_MPI_Info info,  char *port_name);
int A_PMPI_Comm_set_info(A_MPI_Comm comm, A_MPI_Info info);
int A_PMPI_Comm_get_info(A_MPI_Comm comm, A_MPI_Info *info);

/* One-Sided Communications */
int A_PMPI_Accumulate( void *origin_addr, int origin_count, A_MPI_Datatype origin_datatype,
                    int target_rank, A_MPI_Aint target_disp, int target_count,
                    A_MPI_Datatype target_datatype, A_MPI_Op op, A_MPI_Win win)
                    MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_PMPI_Get(void *origin_addr, int origin_count, A_MPI_Datatype origin_datatype,
             int target_rank, A_MPI_Aint target_disp, int target_count,
             A_MPI_Datatype target_datatype, A_MPI_Win win) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_PMPI_Put( void *origin_addr, int origin_count, A_MPI_Datatype origin_datatype,
             int target_rank, A_MPI_Aint target_disp, int target_count,
             A_MPI_Datatype target_datatype, A_MPI_Win win) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_PMPI_Win_complete(A_MPI_Win win);
int A_PMPI_Win_create(void *base, A_MPI_Aint size, int disp_unit, A_MPI_Info info, A_MPI_Comm comm,
                    A_MPI_Win *win);
int A_PMPI_Win_fence(int assert, A_MPI_Win win);
int A_PMPI_Win_free(A_MPI_Win *win);
int A_PMPI_Win_get_group(A_MPI_Win win, A_MPI_Group *group);
int A_PMPI_Win_lock(int lock_type, int rank, int assert, A_MPI_Win win);
int A_PMPI_Win_post(A_MPI_Group group, int assert, A_MPI_Win win);
int A_PMPI_Win_start(A_MPI_Group group, int assert, A_MPI_Win win);
int A_PMPI_Win_test(A_MPI_Win win, int *flag);
int A_PMPI_Win_unlock(int rank, A_MPI_Win win);
int A_PMPI_Win_wait(A_MPI_Win win);

/* MPI-3 One-Sided Communication Routines */
int A_PMPI_Win_allocate(A_MPI_Aint size, int disp_unit, A_MPI_Info info, A_MPI_Comm comm, void *baseptr,
                      A_MPI_Win *win);
int A_PMPI_Win_allocate_shared(A_MPI_Aint size, int disp_unit, A_MPI_Info info, A_MPI_Comm comm,
                             void *baseptr, A_MPI_Win *win);
int A_PMPI_Win_shared_query(A_MPI_Win win, int rank, A_MPI_Aint *size, int *disp_unit, void *baseptr);
int A_PMPI_Win_create_dynamic(A_MPI_Info info, A_MPI_Comm comm, A_MPI_Win *win);
int A_PMPI_Win_attach(A_MPI_Win win, void *base, A_MPI_Aint size);
int A_PMPI_Win_detach(A_MPI_Win win,  void *base);
int A_PMPI_Win_get_info(A_MPI_Win win, A_MPI_Info *info_used);
int A_PMPI_Win_set_info(A_MPI_Win win, A_MPI_Info info);
int A_PMPI_Get_accumulate( void *origin_addr, int origin_count,
                         A_MPI_Datatype origin_datatype, void *result_addr, int result_count,
                         A_MPI_Datatype result_datatype, int target_rank, A_MPI_Aint target_disp,
                         int target_count, A_MPI_Datatype target_datatype, A_MPI_Op op, A_MPI_Win win)
                         MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3)
                         MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int A_PMPI_Fetch_and_op( void *origin_addr, void *result_addr,
                       A_MPI_Datatype datatype, int target_rank, A_MPI_Aint target_disp,
                       A_MPI_Op op, A_MPI_Win win)
                       MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_PMPI_Compare_and_swap( void *origin_addr,  void *compare_addr,
                           void *result_addr, A_MPI_Datatype datatype, int target_rank,
                           A_MPI_Aint target_disp, A_MPI_Win win)
                           MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4)
                           MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4)
                           MPICH_ATTR_POINTER_WITH_TYPE_TAG(3,4);
int A_PMPI_Rput( void *origin_addr, int origin_count,
               A_MPI_Datatype origin_datatype, int target_rank, A_MPI_Aint target_disp,
               int target_count, A_MPI_Datatype target_datatype, A_MPI_Win win,
               A_MPI_Request *request)
               MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_PMPI_Rget(void *origin_addr, int origin_count,
               A_MPI_Datatype origin_datatype, int target_rank, A_MPI_Aint target_disp,
               int target_count, A_MPI_Datatype target_datatype, A_MPI_Win win,
               A_MPI_Request *request)
               MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_PMPI_Raccumulate( void *origin_addr, int origin_count,
                      A_MPI_Datatype origin_datatype, int target_rank, A_MPI_Aint target_disp,
                      int target_count, A_MPI_Datatype target_datatype, A_MPI_Op op, A_MPI_Win win,
                      A_MPI_Request *request)
                      MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_PMPI_Rget_accumulate( void *origin_addr, int origin_count,
                          A_MPI_Datatype origin_datatype, void *result_addr, int result_count,
                          A_MPI_Datatype result_datatype, int target_rank, A_MPI_Aint target_disp,
                          int target_count, A_MPI_Datatype target_datatype, A_MPI_Op op, A_MPI_Win win,
                          A_MPI_Request *request)
                          MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3)
                          MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int A_PMPI_Win_lock_all(int assert, A_MPI_Win win);
int A_PMPI_Win_unlock_all(A_MPI_Win win);
int A_PMPI_Win_flush(int rank, A_MPI_Win win);
int A_PMPI_Win_flush_all(A_MPI_Win win);
int A_PMPI_Win_flush_local(int rank, A_MPI_Win win);
int A_PMPI_Win_flush_local_all(A_MPI_Win win);
int A_PMPI_Win_sync(A_MPI_Win win);
 
/* External Interfaces */
int A_PMPI_Add_error_class(int *errorclass);
int A_PMPI_Add_error_code(int errorclass, int *errorcode);
int A_PMPI_Add_error_string(int errorcode,  char *string);
int A_PMPI_Comm_call_errhandler(A_MPI_Comm comm, int errorcode);
int A_PMPI_Comm_create_keyval(A_MPI_Comm_copy_attr_function *comm_copy_attr_fn,
                            A_MPI_Comm_delete_attr_function *comm_delete_attr_fn, int *comm_keyval,
                            void *extra_state);
int A_PMPI_Comm_delete_attr(A_MPI_Comm comm, int comm_keyval);
int A_PMPI_Comm_free_keyval(int *comm_keyval);
int A_PMPI_Comm_get_attr(A_MPI_Comm comm, int comm_keyval, void *attribute_val, int *flag);
int A_PMPI_Comm_get_name(A_MPI_Comm comm, char *comm_name, int *resultlen);
int A_PMPI_Comm_set_attr(A_MPI_Comm comm, int comm_keyval, void *attribute_val);
int A_PMPI_Comm_set_name(A_MPI_Comm comm,  char *comm_name);
int A_PMPI_File_call_errhandler(A_MPI_File fh, int errorcode);
int A_PMPI_Grequest_complete(A_MPI_Request request);
int A_PMPI_Grequest_start(A_MPI_Grequest_query_function *query_fn, A_MPI_Grequest_free_function *free_fn,
                        A_MPI_Grequest_cancel_function *cancel_fn, void *extra_state,
                        A_MPI_Request *request);
int A_PMPI_Init_thread(int *argc, char ***argv, int required, int *provided);
int A_PMPI_Is_thread_main(int *flag);
int A_PMPI_Query_thread(int *provided);
int A_PMPI_Status_set_cancelled(A_MPI_Status *status, int flag);
int A_PMPI_Status_set_elements(A_MPI_Status *status, A_MPI_Datatype datatype, int count);
int A_PMPI_Type_create_keyval(A_MPI_Type_copy_attr_function *type_copy_attr_fn,
                            A_MPI_Type_delete_attr_function *type_delete_attr_fn,
                            int *type_keyval, void *extra_state);
int A_PMPI_Type_delete_attr(A_MPI_Datatype datatype, int type_keyval);
int A_PMPI_Type_dup(A_MPI_Datatype oldtype, A_MPI_Datatype *newtype);
int A_PMPI_Type_free_keyval(int *type_keyval);
int A_PMPI_Type_get_attr(A_MPI_Datatype datatype, int type_keyval, void *attribute_val, int *flag);
int A_PMPI_Type_get_contents(A_MPI_Datatype datatype, int max_integers, int max_addresses,
                           int max_datatypes, int array_of_integers[],
                           A_MPI_Aint array_of_addresses[], A_MPI_Datatype array_of_datatypes[]);
int A_PMPI_Type_get_envelope(A_MPI_Datatype datatype, int *num_integers, int *num_addresses,
                           int *num_datatypes, int *combiner);
int A_PMPI_Type_get_name(A_MPI_Datatype datatype, char *type_name, int *resultlen);
int A_PMPI_Type_set_attr(A_MPI_Datatype datatype, int type_keyval, void *attribute_val);
int A_PMPI_Type_set_name(A_MPI_Datatype datatype,  char *type_name);
int A_PMPI_Type_match_size(int typeclass, int size, A_MPI_Datatype *datatype);
int A_PMPI_Win_call_errhandler(A_MPI_Win win, int errorcode);
int A_PMPI_Win_create_keyval(A_MPI_Win_copy_attr_function *win_copy_attr_fn,
                           A_MPI_Win_delete_attr_function *win_delete_attr_fn, int *win_keyval,
                           void *extra_state);
int A_PMPI_Win_delete_attr(A_MPI_Win win, int win_keyval);
int A_PMPI_Win_free_keyval(int *win_keyval);
int A_PMPI_Win_get_attr(A_MPI_Win win, int win_keyval, void *attribute_val, int *flag);
int A_PMPI_Win_get_name(A_MPI_Win win, char *win_name, int *resultlen);
int A_PMPI_Win_set_attr(A_MPI_Win win, int win_keyval, void *attribute_val);
int A_PMPI_Win_set_name(A_MPI_Win win,  char *win_name);

int A_PMPI_Alloc_mem(A_MPI_Aint size, A_MPI_Info info, void *baseptr);
int A_PMPI_Comm_create_errhandler(A_MPI_Comm_errhandler_function *comm_errhandler_fn,
                                A_MPI_Errhandler *errhandler);
int A_PMPI_Comm_get_errhandler(A_MPI_Comm comm, A_MPI_Errhandler *errhandler);
int A_PMPI_Comm_set_errhandler(A_MPI_Comm comm, A_MPI_Errhandler errhandler);
int A_PMPI_File_create_errhandler(A_MPI_File_errhandler_function *file_errhandler_fn,
                                A_MPI_Errhandler *errhandler);
int A_PMPI_File_get_errhandler(A_MPI_File file, A_MPI_Errhandler *errhandler);
int A_PMPI_File_set_errhandler(A_MPI_File file, A_MPI_Errhandler errhandler);
int A_PMPI_Finalized(int *flag);
int A_PMPI_Free_mem(void *base);
int A_PMPI_Get_address( void *location, A_MPI_Aint *address);
int A_PMPI_Info_create(A_MPI_Info *info);
int A_PMPI_Info_delete(A_MPI_Info info,  char *key);
int A_PMPI_Info_dup(A_MPI_Info info, A_MPI_Info *newinfo);
int A_PMPI_Info_free(A_MPI_Info *info);
int A_PMPI_Info_get(A_MPI_Info info,  char *key, int valuelen, char *value, int *flag);
int A_PMPI_Info_get_nkeys(A_MPI_Info info, int *nkeys);
int A_PMPI_Info_get_nthkey(A_MPI_Info info, int n, char *key);
int A_PMPI_Info_get_valuelen(A_MPI_Info info,  char *key, int *valuelen, int *flag);
int A_PMPI_Info_set(A_MPI_Info info,  char *key,  char *value);
int A_PMPI_Pack_external( char datarep[],  void *inbuf, int incount,
                       A_MPI_Datatype datatype, void *outbuf, A_MPI_Aint outsize, A_MPI_Aint *position)
                       MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_PMPI_Pack_external_size( char datarep[], int incount, A_MPI_Datatype datatype,
                            A_MPI_Aint *size);
int A_PMPI_Request_get_status(A_MPI_Request request, int *flag, A_MPI_Status *status);
int A_PMPI_Status_c2f( A_MPI_Status *c_status, A_MPI_Fint *f_status);
int A_PMPI_Status_f2c( A_MPI_Fint *f_status, A_MPI_Status *c_status);
int A_PMPI_Type_create_darray(int size, int rank, int ndims,  int array_of_gsizes[],
                             int array_of_distribs[],  int array_of_dargs[],
                             int array_of_psizes[], int order, A_MPI_Datatype oldtype,
                            A_MPI_Datatype *newtype);
int A_PMPI_Type_create_hindexed(int count,  int array_of_blocklengths[],
                               A_MPI_Aint array_of_displacements[], A_MPI_Datatype oldtype,
                              A_MPI_Datatype *newtype);
int A_PMPI_Type_create_hvector(int count, int blocklength, A_MPI_Aint stride, A_MPI_Datatype oldtype,
                             A_MPI_Datatype *newtype);
int A_PMPI_Type_create_indexed_block(int count, int blocklength,  int array_of_displacements[],
                                   A_MPI_Datatype oldtype, A_MPI_Datatype *newtype);
int A_PMPI_Type_create_hindexed_block(int count, int blocklength,
                                     A_MPI_Aint array_of_displacements[],
                                    A_MPI_Datatype oldtype, A_MPI_Datatype *newtype);
int A_PMPI_Type_create_resized(A_MPI_Datatype oldtype, A_MPI_Aint lb, A_MPI_Aint extent,
                             A_MPI_Datatype *newtype);
int A_PMPI_Type_create_struct(int count,  int array_of_blocklengths[],
                             A_MPI_Aint array_of_displacements[],
                             A_MPI_Datatype array_of_types[], A_MPI_Datatype *newtype);
int A_PMPI_Type_create_subarray(int ndims,  int array_of_sizes[],
                               int array_of_subsizes[],  int array_of_starts[],
                              int order, A_MPI_Datatype oldtype, A_MPI_Datatype *newtype);
int A_PMPI_Type_get_extent(A_MPI_Datatype datatype, A_MPI_Aint *lb, A_MPI_Aint *extent);
int A_PMPI_Type_get_true_extent(A_MPI_Datatype datatype, A_MPI_Aint *true_lb, A_MPI_Aint *true_extent);
int A_PMPI_Unpack_external( char datarep[],  void *inbuf, A_MPI_Aint insize,
                         A_MPI_Aint *position, void *outbuf, int outcount, A_MPI_Datatype datatype)
                         MPICH_ATTR_POINTER_WITH_TYPE_TAG(5,7);
int A_PMPI_Win_create_errhandler(A_MPI_Win_errhandler_function *win_errhandler_fn,
                               A_MPI_Errhandler *errhandler);
int A_PMPI_Win_get_errhandler(A_MPI_Win win, A_MPI_Errhandler *errhandler);
int A_PMPI_Win_set_errhandler(A_MPI_Win win, A_MPI_Errhandler errhandler);

/* Fortran 90-related functions.  These routines are available only if
   Fortran 90 support is enabled 
*/
int A_PMPI_Type_create_f90_integer(int r, A_MPI_Datatype *newtype);
int A_PMPI_Type_create_f90_real(int p, int r, A_MPI_Datatype *newtype);
int A_PMPI_Type_create_f90_complex(int p, int r, A_MPI_Datatype *newtype);

int A_PMPI_Reduce_local( void *inbuf, void *inoutbuf, int count, A_MPI_Datatype datatype,
                      A_MPI_Op op)
                      MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_PMPI_Op_commutative(A_MPI_Op op, int *commute);
int A_PMPI_Reduce_scatter_block( void *sendbuf, void *recvbuf, int recvcount,
                              A_MPI_Datatype datatype, A_MPI_Op op, A_MPI_Comm comm)
                              MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4)
                              MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_PMPI_Dist_graph_create_adjacent(A_MPI_Comm comm_old, int indegree,  int sources[],
                                     int sourceweights[], int outdegree,
                                     int destinations[],  int destweights[],
                                    A_MPI_Info info, int reorder, A_MPI_Comm *comm_dist_graph);
int A_PMPI_Dist_graph_create(A_MPI_Comm comm_old, int n,  int sources[],  int degrees[],
                            int destinations[],  int weights[], A_MPI_Info info,
                           int reorder, A_MPI_Comm *comm_dist_graph);
int A_PMPI_Dist_graph_neighbors_count(A_MPI_Comm comm, int *indegree, int *outdegree, int *weighted);
int A_PMPI_Dist_graph_neighbors(A_MPI_Comm comm, int maxindegree, int sources[], int sourceweights[],
                              int maxoutdegree, int destinations[], int destweights[]);

/* Matched probe functionality */
int A_PMPI_Improbe(int source, int tag, A_MPI_Comm comm, int *flag, A_MPI_Message *message,
                 A_MPI_Status *status);
int A_PMPI_Imrecv(void *buf, int count, A_MPI_Datatype datatype, A_MPI_Message *message,
                A_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_PMPI_Mprobe(int source, int tag, A_MPI_Comm comm, A_MPI_Message *message, A_MPI_Status *status);
int A_PMPI_Mrecv(void *buf, int count, A_MPI_Datatype datatype, A_MPI_Message *message,
               A_MPI_Status *status) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);

/* Nonblocking collectives */
int A_PMPI_Comm_idup(A_MPI_Comm comm, A_MPI_Comm *newcomm, A_MPI_Request *request);
int A_PMPI_Ibarrier(A_MPI_Comm comm, A_MPI_Request *request);
int A_PMPI_Ibcast(void *buffer, int count, A_MPI_Datatype datatype, int root, A_MPI_Comm comm,
                A_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int A_PMPI_Igather( void *sendbuf, int sendcount, A_MPI_Datatype sendtype, void *recvbuf,
                 int recvcount, A_MPI_Datatype recvtype, int root, A_MPI_Comm comm,
                 A_MPI_Request *request)
                 MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int A_PMPI_Igatherv( void *sendbuf, int sendcount, A_MPI_Datatype sendtype, void *recvbuf,
                   int recvcounts[],  int displs[], A_MPI_Datatype recvtype, int root,
                  A_MPI_Comm comm, A_MPI_Request *request)
                  MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,7);
int A_PMPI_Iscatter( void *sendbuf, int sendcount, A_MPI_Datatype sendtype, void *recvbuf,
                  int recvcount, A_MPI_Datatype recvtype, int root, A_MPI_Comm comm,
                  A_MPI_Request *request)
                  MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int A_PMPI_Iscatterv( void *sendbuf,  int sendcounts[],  int displs[],
                   A_MPI_Datatype sendtype, void *recvbuf, int recvcount, A_MPI_Datatype recvtype,
                   int root, A_MPI_Comm comm, A_MPI_Request *request)
                   MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(5,7);
int A_PMPI_Iallgather( void *sendbuf, int sendcount, A_MPI_Datatype sendtype, void *recvbuf,
                    int recvcount, A_MPI_Datatype recvtype, A_MPI_Comm comm, A_MPI_Request *request)
                    MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int A_PMPI_Iallgatherv( void *sendbuf, int sendcount, A_MPI_Datatype sendtype, void *recvbuf,
                      int recvcounts[],  int displs[], A_MPI_Datatype recvtype,
                     A_MPI_Comm comm, A_MPI_Request *request)
                     MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,7);
int A_PMPI_Ialltoall( void *sendbuf, int sendcount, A_MPI_Datatype sendtype, void *recvbuf,
                   int recvcount, A_MPI_Datatype recvtype, A_MPI_Comm comm, A_MPI_Request *request)
                   MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int A_PMPI_Ialltoallv( void *sendbuf,  int sendcounts[],  int sdispls[],
                    A_MPI_Datatype sendtype, void *recvbuf,  int recvcounts[],
                     int rdispls[], A_MPI_Datatype recvtype, A_MPI_Comm comm,
                    A_MPI_Request *request)
                    MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(5,8);
int A_PMPI_Ialltoallw( void *sendbuf,  int sendcounts[],  int sdispls[],
                     A_MPI_Datatype sendtypes[], void *recvbuf,  int recvcounts[],
                     int rdispls[],  A_MPI_Datatype recvtypes[], A_MPI_Comm comm,
                    A_MPI_Request *request);
int A_PMPI_Ireduce( void *sendbuf, void *recvbuf, int count, A_MPI_Datatype datatype,
                 A_MPI_Op op, int root, A_MPI_Comm comm, A_MPI_Request *request)
                 MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_PMPI_Iallreduce( void *sendbuf, void *recvbuf, int count, A_MPI_Datatype datatype,
                    A_MPI_Op op, A_MPI_Comm comm, A_MPI_Request *request)
                    MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_PMPI_Ireduce_scatter( void *sendbuf, void *recvbuf,  int recvcounts[],
                         A_MPI_Datatype datatype, A_MPI_Op op, A_MPI_Comm comm, A_MPI_Request *request)
                         MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4)
                         MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_PMPI_Ireduce_scatter_block( void *sendbuf, void *recvbuf, int recvcount,
                               A_MPI_Datatype datatype, A_MPI_Op op, A_MPI_Comm comm,
                               A_MPI_Request *request)
                               MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4)
                               MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_PMPI_Iscan( void *sendbuf, void *recvbuf, int count, A_MPI_Datatype datatype, A_MPI_Op op,
               A_MPI_Comm comm, A_MPI_Request *request)
               MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_PMPI_Iexscan( void *sendbuf, void *recvbuf, int count, A_MPI_Datatype datatype,
                 A_MPI_Op op, A_MPI_Comm comm, A_MPI_Request *request)
                 MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);

/* Neighborhood collectives */
int A_PMPI_Ineighbor_allgather( void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                             void *recvbuf, int recvcount, A_MPI_Datatype recvtype,
                             A_MPI_Comm comm, A_MPI_Request *request)
                             MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3)
                             MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int A_PMPI_Ineighbor_allgatherv( void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                              void *recvbuf,  int recvcounts[],  int displs[],
                              A_MPI_Datatype recvtype, A_MPI_Comm comm, A_MPI_Request *request)
                              MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3)
                              MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,7);
int A_PMPI_Ineighbor_alltoall( void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                            void *recvbuf, int recvcount, A_MPI_Datatype recvtype, A_MPI_Comm comm,
                            A_MPI_Request *request)
                            MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3)
                            MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int A_PMPI_Ineighbor_alltoallv( void *sendbuf,  int sendcounts[],  int sdispls[],
                             A_MPI_Datatype sendtype, void *recvbuf,  int recvcounts[],
                              int rdispls[], A_MPI_Datatype recvtype, A_MPI_Comm comm,
                             A_MPI_Request *request)
                             MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4)
                             MPICH_ATTR_POINTER_WITH_TYPE_TAG(5,8);
int A_PMPI_Ineighbor_alltoallw( void *sendbuf,  int sendcounts[],
                              A_MPI_Aint sdispls[],  A_MPI_Datatype sendtypes[],
                             void *recvbuf,  int recvcounts[],  A_MPI_Aint rdispls[],
                              A_MPI_Datatype recvtypes[], A_MPI_Comm comm, A_MPI_Request *request);
int A_PMPI_Neighbor_allgather( void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                            void *recvbuf, int recvcount, A_MPI_Datatype recvtype, A_MPI_Comm comm)
                            MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3)
                            MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int A_PMPI_Neighbor_allgatherv( void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                             void *recvbuf,  int recvcounts[],  int displs[],
                             A_MPI_Datatype recvtype, A_MPI_Comm comm)
                             MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3)
                             MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,7);
int A_PMPI_Neighbor_alltoall( void *sendbuf, int sendcount, A_MPI_Datatype sendtype,
                           void *recvbuf, int recvcount, A_MPI_Datatype recvtype, A_MPI_Comm comm)
                           MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3)
                           MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int A_PMPI_Neighbor_alltoallv( void *sendbuf,  int sendcounts[],  int sdispls[],
                            A_MPI_Datatype sendtype, void *recvbuf,  int recvcounts[],
                             int rdispls[], A_MPI_Datatype recvtype, A_MPI_Comm comm)
                            MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4)
                            MPICH_ATTR_POINTER_WITH_TYPE_TAG(5,8);
int A_PMPI_Neighbor_alltoallw( void *sendbuf,  int sendcounts[],  A_MPI_Aint sdispls[],
                             A_MPI_Datatype sendtypes[], void *recvbuf,  int recvcounts[],
                             A_MPI_Aint rdispls[],  A_MPI_Datatype recvtypes[],
                            A_MPI_Comm comm);

/* Shared memory */
int A_PMPI_Comm_split_type(A_MPI_Comm comm, int split_type, int key, A_MPI_Info info, A_MPI_Comm *newcomm);

/* Noncollective communicator creation */
int A_PMPI_Comm_create_group(A_MPI_Comm comm, A_MPI_Group group, int tag, A_MPI_Comm *newcomm);

/* MPI-3 "large count" routines */
int A_PMPI_Get_elements_x( A_MPI_Status *status, A_MPI_Datatype datatype, A_MPI_Count *count);
int A_PMPI_Status_set_elements_x(A_MPI_Status *status, A_MPI_Datatype datatype, A_MPI_Count count);
int A_PMPI_Type_get_extent_x(A_MPI_Datatype datatype, A_MPI_Count *lb, A_MPI_Count *extent);
int A_PMPI_Type_get_true_extent_x(A_MPI_Datatype datatype, A_MPI_Count *lb, A_MPI_Count *extent);
int A_PMPI_Type_size_x(A_MPI_Datatype datatype, A_MPI_Count *size);

/* Non-standard but public extensions to MPI */
/* Fault Tolerance Extensions */
int PMPIX_Comm_group_failed(A_MPI_Comm comm, A_MPI_Group *failed_group);
int PMPIX_Comm_remote_group_failed(A_MPI_Comm comm, A_MPI_Group *failed_group);
int PMPIX_Comm_reenable_anysource(A_MPI_Comm comm, A_MPI_Group *failed_group);


/* A_MPI_T interface */
/* The A_MPI_T routines are available only in C bindings - tell tools that they
   can skip these prototypes */
/* Begin Skip Prototypes */
int A_PMPI_T_init_thread(int required, int *provided);
int A_PMPI_T_finalize(void);
int A_PMPI_T_enum_get_info(A_MPI_T_enum enumtype, int *num, char *name, int *name_len);
int A_PMPI_T_enum_get_item(A_MPI_T_enum enumtype, int indx, int *value, char *name, int *name_len);
int A_PMPI_T_cvar_get_num(int *num_cvar);
int A_PMPI_T_cvar_get_info(int cvar_index, char *name, int *name_len, int *verbosity,
                         A_MPI_Datatype *datatype, A_MPI_T_enum *enumtype, char *desc, int *desc_len,
                         int *binding, int *scope);
int A_PMPI_T_cvar_handle_alloc(int cvar_index, void *obj_handle, A_MPI_T_cvar_handle *handle,
                             int *count);
int A_PMPI_T_cvar_handle_free(A_MPI_T_cvar_handle *handle);
int A_PMPI_T_cvar_read(A_MPI_T_cvar_handle handle, void *buf);
int A_PMPI_T_cvar_write(A_MPI_T_cvar_handle handle,  void *buf);
int A_PMPI_T_pvar_get_num(int *num_pvar);
int A_PMPI_T_pvar_get_info(int pvar_index, char *name, int *name_len, int *verbosity, int *var_class,
                         A_MPI_Datatype *datatype, A_MPI_T_enum *enumtype, char *desc, int *desc_len,
                         int *binding, int *readonly, int *continuous, int *atomic);
int A_PMPI_T_pvar_session_create(A_MPI_T_pvar_session *session);
int A_PMPI_T_pvar_session_free(A_MPI_T_pvar_session *session);
int A_PMPI_T_pvar_handle_alloc(A_MPI_T_pvar_session session, int pvar_index, void *obj_handle,
                             A_MPI_T_pvar_handle *handle, int *count);
int A_PMPI_T_pvar_handle_free(A_MPI_T_pvar_session session, A_MPI_T_pvar_handle *handle);
int A_PMPI_T_pvar_start(A_MPI_T_pvar_session session, A_MPI_T_pvar_handle handle);
int A_PMPI_T_pvar_stop(A_MPI_T_pvar_session session, A_MPI_T_pvar_handle handle);
int A_PMPI_T_pvar_read(A_MPI_T_pvar_session session, A_MPI_T_pvar_handle handle, void *buf);
int A_PMPI_T_pvar_write(A_MPI_T_pvar_session session, A_MPI_T_pvar_handle handle,  void *buf);
int A_PMPI_T_pvar_reset(A_MPI_T_pvar_session session, A_MPI_T_pvar_handle handle);
int A_PMPI_T_pvar_readreset(A_MPI_T_pvar_session session, A_MPI_T_pvar_handle handle, void *buf);
int A_PMPI_T_category_get_num(int *num_cat);
int A_PMPI_T_category_get_info(int cat_index, char *name, int *name_len, char *desc, int *desc_len,
                             int *num_cvars, int *num_pvars, int *num_categories);
int A_PMPI_T_category_get_cvars(int cat_index, int len, int indices[]);
int A_PMPI_T_category_get_pvars(int cat_index, int len, int indices[]);
int A_PMPI_T_category_get_categories(int cat_index, int len, int indices[]);
int A_PMPI_T_category_changed(int *stamp);
/* End Skip Prototypes */
#endif  /* A_MPI_BUILD_PROFILING */
/* End of MPI bindings */

/* feature advertisement */
#define MPIIMPL_ADVERTISES_FEATURES 1
#define MPIIMPL_HAVE_A_MPI_INFO 1                                                 
#define MPIIMPL_HAVE_A_MPI_COMBINER_DARRAY 1                                      
#define MPIIMPL_HAVE_A_MPI_TYPE_CREATE_DARRAY 1
#define MPIIMPL_HAVE_A_MPI_COMBINER_SUBARRAY 1                                    
#define MPIIMPL_HAVE_A_MPI_TYPE_CREATE_DARRAY 1
#define MPIIMPL_HAVE_A_MPI_COMBINER_DUP 1                                         
#define MPIIMPL_HAVE_A_MPI_GREQUEST 1      
#define MPIIMPL_HAVE_STATUS_SET_BYTES 1
#define MPIIMPL_HAVE_STATUS_SET_INFO 1

#include "app_mpio.h"

#if defined(__cplusplus)
}
/* Add the C++ bindings */
/* 
   If MPICH_SKIP_MPICXX is defined, the mpicxx.h file will *not* be included.
   This is necessary, for example, when building the C++ interfaces.  It
   can also be used when you want to use a C++ compiler to compile C code,
   and do not want to load the C++ bindings.  These definitions can
   be made by the C++ compilation script
 */
#if !defined(MPICH_SKIP_MPICXX)
/* mpicxx.h contains the MPI C++ binding.  In the mpi.h.in file, this 
   include is in an autoconf variable in case the compiler is a C++ 
   compiler but MPI was built without the C++ bindings */
#include "mpicxx.h"
#endif 
#endif


/* Generalized requests extensions */
typedef int MPIX_Grequest_class;
int MPIX_Grequest_class_create(A_MPI_Grequest_query_function *query_fn,
                               A_MPI_Grequest_free_function *free_fn,
                               A_MPI_Grequest_cancel_function *cancel_fn,
                               MPIX_Grequest_poll_function *poll_fn,
                               MPIX_Grequest_wait_function *wait_fn,
                               MPIX_Grequest_class *greq_class);
int MPIX_Grequest_class_allocate(MPIX_Grequest_class greq_class, void *extra_state,
                                 A_MPI_Request *request);
int MPIX_Grequest_start(A_MPI_Grequest_query_function *query_fn,
                        A_MPI_Grequest_free_function *free_fn,
                        A_MPI_Grequest_cancel_function *cancel_fn,
                        MPIX_Grequest_poll_function *poll_fn,
                        MPIX_Grequest_wait_function *wait_fn, void *extra_state,
                        A_MPI_Request *request);

/* RMA Mutexes Extensions */
struct mpixi_mutex_s;
typedef struct mpixi_mutex_s * MPIX_Mutex;
int MPIX_Mutex_create(int count, A_MPI_Comm comm, MPIX_Mutex *hdl);
int MPIX_Mutex_free(MPIX_Mutex *hdl);
int MPIX_Mutex_lock(MPIX_Mutex hdl, int mutex, int proc);
int MPIX_Mutex_unlock(MPIX_Mutex hdl, int mutex, int proc);


#if !defined(A_MPI_BUILD_PROFILING)
/* Generalized requests extensions */
int PMPIX_Grequest_class_create(A_MPI_Grequest_query_function *query_fn,
                                A_MPI_Grequest_free_function *free_fn,
                                A_MPI_Grequest_cancel_function *cancel_fn,
                                MPIX_Grequest_poll_function *poll_fn,
                                MPIX_Grequest_wait_function *wait_fn,
                                MPIX_Grequest_class *greq_class);
int PMPIX_Grequest_class_allocate(MPIX_Grequest_class greq_class, void *extra_state,
                                  A_MPI_Request *request);
int PMPIX_Grequest_start(A_MPI_Grequest_query_function *query_fn,
                         A_MPI_Grequest_free_function *free_fn,
                         A_MPI_Grequest_cancel_function *cancel_fn,
                         MPIX_Grequest_poll_function *poll_fn,
                         MPIX_Grequest_wait_function *wait_fn, void *extra_state,
                         A_MPI_Request *request);

/* RMA Mutexes Extensions */
int PMPIX_Mutex_create(int count, A_MPI_Comm comm, MPIX_Mutex *hdl);
int PMPIX_Mutex_free(MPIX_Mutex *hdl);
int PMPIX_Mutex_lock(MPIX_Mutex hdl, int mutex, int proc);
int PMPIX_Mutex_unlock(MPIX_Mutex hdl, int mutex, int proc);
#endif /* A_MPI_BUILD_PROFILING */

#endif

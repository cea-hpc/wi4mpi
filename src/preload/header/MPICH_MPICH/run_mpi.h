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
#ifndef R_MPI_INCLUDED
#define R_MPI_INCLUDED

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
#define R_MPI_COMM_NULL      ((R_MPI_Comm)0x04000000)
#define R_MPI_OP_NULL        ((R_MPI_Op)0x18000000)
#define R_MPI_GROUP_NULL     ((R_MPI_Group)0x08000000)
#define R_MPI_DATATYPE_NULL  ((R_MPI_Datatype)0x0c000000)
#define R_MPI_REQUEST_NULL   ((R_MPI_Request)0x2c000000)
#define R_MPI_ERRHANDLER_NULL ((R_MPI_Errhandler)0x14000000)
#define R_MPI_MESSAGE_NULL   ((R_MPI_Message)R_MPI_REQUEST_NULL)
#define R_MPI_MESSAGE_NO_PROC ((R_MPI_Message)0x6c000000)

/* Results of the compare operations. */
#define R_MPI_IDENT     0
#define R_MPI_CONGRUENT 1
#define R_MPI_SIMILAR   2
#define R_MPI_UNEQUAL   3

typedef int R_MPI_Datatype;
#define R_MPI_CHAR           ((R_MPI_Datatype)0x4c000101)
#define R_MPI_SIGNED_CHAR    ((R_MPI_Datatype)0x4c000118)
#define R_MPI_UNSIGNED_CHAR  ((R_MPI_Datatype)0x4c000102)
#define R_MPI_BYTE           ((R_MPI_Datatype)0x4c00010d)
#define R_MPI_WCHAR          ((R_MPI_Datatype)0x4c00040e)
#define R_MPI_SHORT          ((R_MPI_Datatype)0x4c000203)
#define R_MPI_UNSIGNED_SHORT ((R_MPI_Datatype)0x4c000204)
#define R_MPI_INT            ((R_MPI_Datatype)0x4c000405)
#define R_MPI_UNSIGNED       ((R_MPI_Datatype)0x4c000406)
#define R_MPI_LONG           ((R_MPI_Datatype)0x4c000807)
#define R_MPI_UNSIGNED_LONG  ((R_MPI_Datatype)0x4c000808)
#define R_MPI_FLOAT          ((R_MPI_Datatype)0x4c00040a)
#define R_MPI_DOUBLE         ((R_MPI_Datatype)0x4c00080b)
#define R_MPI_LONG_DOUBLE    ((R_MPI_Datatype)0x4c00100c)
#define R_MPI_LONG_LONG_INT  ((R_MPI_Datatype)0x4c000809)
#define R_MPI_UNSIGNED_LONG_LONG ((R_MPI_Datatype)0x4c000819)
#define R_MPI_LONG_LONG      R_MPI_LONG_LONG_INT

#ifdef MPICH_DEFINE_ATTR_TYPE_TYPES
static  R_MPI_Datatype mpich_mpi_char               MPICH_ATTR_TYPE_TAG(char)               = R_MPI_CHAR;
static  R_MPI_Datatype mpich_mpi_signed_char        MPICH_ATTR_TYPE_TAG(signed char)        = R_MPI_SIGNED_CHAR;
static  R_MPI_Datatype mpich_mpi_unsigned_char      MPICH_ATTR_TYPE_TAG(unsigned char)      = R_MPI_UNSIGNED_CHAR;
/*static  R_MPI_Datatype mpich_mpi_byte               MPICH_ATTR_TYPE_TAG(char)               = R_MPI_BYTE;*/
static  R_MPI_Datatype mpich_mpi_wchar              MPICH_ATTR_TYPE_TAG(wchar_t)            = R_MPI_WCHAR;
static  R_MPI_Datatype mpich_mpi_short              MPICH_ATTR_TYPE_TAG(short)              = R_MPI_SHORT;
static  R_MPI_Datatype mpich_mpi_unsigned_short     MPICH_ATTR_TYPE_TAG(unsigned short)     = R_MPI_UNSIGNED_SHORT;
static  R_MPI_Datatype mpich_mpi_int                MPICH_ATTR_TYPE_TAG(int)                = R_MPI_INT;
static  R_MPI_Datatype mpich_mpi_unsigned           MPICH_ATTR_TYPE_TAG(unsigned)           = R_MPI_UNSIGNED;
static  R_MPI_Datatype mpich_mpi_long               MPICH_ATTR_TYPE_TAG(long)               = R_MPI_LONG;
static  R_MPI_Datatype mpich_mpi_unsigned_long      MPICH_ATTR_TYPE_TAG(unsigned long)      = R_MPI_UNSIGNED_LONG;
static  R_MPI_Datatype mpich_mpi_float              MPICH_ATTR_TYPE_TAG(float)              = R_MPI_FLOAT;
static  R_MPI_Datatype mpich_mpi_double             MPICH_ATTR_TYPE_TAG(double)             = R_MPI_DOUBLE;
#if 0x4c00100c != 0x0c000000
static  R_MPI_Datatype mpich_mpi_long_double        MPICH_ATTR_TYPE_TAG(long double)        = R_MPI_LONG_DOUBLE;
#endif
static  R_MPI_Datatype mpich_mpi_long_long_int      MPICH_ATTR_TYPE_TAG(long long int)      = R_MPI_LONG_LONG_INT;
static  R_MPI_Datatype mpich_mpi_unsigned_long_long MPICH_ATTR_TYPE_TAG(unsigned long long) = R_MPI_UNSIGNED_LONG_LONG;
#endif

#define R_MPI_PACKED         ((R_MPI_Datatype)0x4c00010f)
#define R_MPI_LB             ((R_MPI_Datatype)0x4c000010)
#define R_MPI_UB             ((R_MPI_Datatype)0x4c000011)

/* 
   The layouts for the types R_MPI_DOUBLE_INT etc are simply
   struct { 
       double var;
       int    loc;
   }
   This is documented in the man pages on the various datatypes.   
 */
#define R_MPI_FLOAT_INT         ((R_MPI_Datatype)0x8c000000)
#define R_MPI_DOUBLE_INT        ((R_MPI_Datatype)0x8c000001)
#define R_MPI_LONG_INT          ((R_MPI_Datatype)0x8c000002)
#define R_MPI_SHORT_INT         ((R_MPI_Datatype)0x8c000003)
#define R_MPI_2INT              ((R_MPI_Datatype)0x4c000816)
#define R_MPI_LONG_DOUBLE_INT   ((R_MPI_Datatype)0x8c000004)

#ifdef MPICH_DEFINE_ATTR_TYPE_TYPES
struct mpich_struct_mpi_float_int       { float f; int i; };
struct mpich_struct_mpi_double_int      { double d; int i; };
struct mpich_struct_mpi_long_int        { long l; int i; };
struct mpich_struct_mpi_short_int       { short s; int i; };
struct mpich_struct_mpi_2int            { int i1; int i2; };
#if 0x8c000004 != 0x0c000000
struct mpich_struct_mpi_long_double_int { long double ld; int i; };
#endif

static  R_MPI_Datatype mpich_mpi_float_int       MPICH_ATTR_TYPE_TAG_LAYOUT_COMPATIBLE(struct mpich_struct_mpi_float_int)       = R_MPI_FLOAT_INT;
static  R_MPI_Datatype mpich_mpi_double_int      MPICH_ATTR_TYPE_TAG_LAYOUT_COMPATIBLE(struct mpich_struct_mpi_double_int)      = R_MPI_DOUBLE_INT;
static  R_MPI_Datatype mpich_mpi_long_int        MPICH_ATTR_TYPE_TAG_LAYOUT_COMPATIBLE(struct mpich_struct_mpi_long_int)        = R_MPI_LONG_INT;
static  R_MPI_Datatype mpich_mpi_short_int       MPICH_ATTR_TYPE_TAG_LAYOUT_COMPATIBLE(struct mpich_struct_mpi_short_int)       = R_MPI_SHORT_INT;

/*
 * The R_MPI_2INT line is commented out because currently Clang 3.3 flags
 * struct {int i1; int i2;} as different from int[2]. But actually these
 * two types are of the same layout. Clang gives a type mismatch warning
 * for a definitely correct code like the following:
 *  int in[2], out[2];
 *  R_MPI_Reduce(in, out, 1, R_MPI_2INT, R_MPI_MAXLOC, 0, R_MPI_COMM_WORLD);
 *
 * So, we disable type checking for R_MPI_2INT until Clang fixes this bug.
 */

/* static  R_MPI_Datatype mpich_mpi_2int            MPICH_ATTR_TYPE_TAG_LAYOUT_COMPATIBLE(struct mpich_struct_mpi_2int)            = R_MPI_2INT
 */

#if 0x8c000004 != 0x0c000000
static  R_MPI_Datatype mpich_mpi_long_double_int MPICH_ATTR_TYPE_TAG_LAYOUT_COMPATIBLE(struct mpich_struct_mpi_long_double_int) = R_MPI_LONG_DOUBLE_INT;
#endif
#endif

/* Fortran types */
#define R_MPI_COMPLEX           ((R_MPI_Datatype)1275070494)
#define R_MPI_DOUBLE_COMPLEX    ((R_MPI_Datatype)1275072546)
#define R_MPI_LOGICAL           ((R_MPI_Datatype)1275069469)
#define R_MPI_REAL              ((R_MPI_Datatype)1275069468)
#define R_MPI_DOUBLE_PRECISION  ((R_MPI_Datatype)1275070495)
#define R_MPI_INTEGER           ((R_MPI_Datatype)1275069467)
#define R_MPI_2INTEGER          ((R_MPI_Datatype)1275070496)
/* 
 * R_MPI_2COMPLEX and R_MPI_2DOUBLE_COMPLEX were defined by accident in 
 * MPI 1.0 and removed in MPI 1.1.  
 *
 * This definition provides backward compatibility.  These definitions
 * will be removed in a subsequent MPICH release
 */
#define MPICH_DEFINE_2COMPLEX
#ifdef MPICH_DEFINE_2COMPLEX
#define R_MPI_2COMPLEX          ((R_MPI_Datatype)1275072548)
#define R_MPI_2DOUBLE_COMPLEX   ((R_MPI_Datatype)1275076645)
#endif 
#define R_MPI_2REAL             ((R_MPI_Datatype)1275070497)
#define R_MPI_2DOUBLE_PRECISION ((R_MPI_Datatype)1275072547)
#define R_MPI_CHARACTER         ((R_MPI_Datatype)1275068698)

/* Size-specific types (see MPI-2, 10.2.5) */
#define R_MPI_REAL4             ((R_MPI_Datatype)0x4c000427)
#define R_MPI_REAL8             ((R_MPI_Datatype)0x4c000829)
#define R_MPI_REAL16            ((R_MPI_Datatype)0x4c00102b)
#define R_MPI_COMPLEX8          ((R_MPI_Datatype)0x4c000828)
#define R_MPI_COMPLEX16         ((R_MPI_Datatype)0x4c00102a)
#define R_MPI_COMPLEX32         ((R_MPI_Datatype)0x4c00202c)
#define R_MPI_INTEGER1          ((R_MPI_Datatype)0x4c00012d)
#define R_MPI_INTEGER2          ((R_MPI_Datatype)0x4c00022f)
#define R_MPI_INTEGER4          ((R_MPI_Datatype)0x4c000430)
#define R_MPI_INTEGER8          ((R_MPI_Datatype)0x4c000831)
#define R_MPI_INTEGER16         ((R_MPI_Datatype)R_MPI_DATATYPE_NULL)

/* C99 fixed-width datatypes */
#define R_MPI_INT8_T            ((R_MPI_Datatype)0x4c000137)
#define R_MPI_INT16_T           ((R_MPI_Datatype)0x4c000238)
#define R_MPI_INT32_T           ((R_MPI_Datatype)0x4c000439)
#define R_MPI_INT64_T           ((R_MPI_Datatype)0x4c00083a)
#define R_MPI_UINT8_T           ((R_MPI_Datatype)0x4c00013b)
#define R_MPI_UINT16_T          ((R_MPI_Datatype)0x4c00023c)
#define R_MPI_UINT32_T          ((R_MPI_Datatype)0x4c00043d)
#define R_MPI_UINT64_T          ((R_MPI_Datatype)0x4c00083e)

#ifdef MPICH_DEFINE_ATTR_TYPE_TYPES
static  R_MPI_Datatype mpich_mpi_int8_t   MPICH_ATTR_TYPE_TAG_STDINT(int8_t)   = R_MPI_INT8_T;
static  R_MPI_Datatype mpich_mpi_int16_t  MPICH_ATTR_TYPE_TAG_STDINT(int16_t)  = R_MPI_INT16_T;
static  R_MPI_Datatype mpich_mpi_int32_t  MPICH_ATTR_TYPE_TAG_STDINT(int32_t)  = R_MPI_INT32_T;
static  R_MPI_Datatype mpich_mpi_int64_t  MPICH_ATTR_TYPE_TAG_STDINT(int64_t)  = R_MPI_INT64_T;
static  R_MPI_Datatype mpich_mpi_uint8_t  MPICH_ATTR_TYPE_TAG_STDINT(uint8_t)  = R_MPI_UINT8_T;
static  R_MPI_Datatype mpich_mpi_uint16_t MPICH_ATTR_TYPE_TAG_STDINT(uint16_t) = R_MPI_UINT16_T;
static  R_MPI_Datatype mpich_mpi_uint32_t MPICH_ATTR_TYPE_TAG_STDINT(uint32_t) = R_MPI_UINT32_T;
static  R_MPI_Datatype mpich_mpi_uint64_t MPICH_ATTR_TYPE_TAG_STDINT(uint64_t) = R_MPI_UINT64_T;
#endif

/* other C99 types */
#define R_MPI_C_BOOL                 ((R_MPI_Datatype)0x4c00013f)
#define R_MPI_C_FLOAT_COMPLEX        ((R_MPI_Datatype)0x4c000840)
#define R_MPI_C_COMPLEX              R_MPI_C_FLOAT_COMPLEX
#define R_MPI_C_DOUBLE_COMPLEX       ((R_MPI_Datatype)0x4c001041)
#define R_MPI_C_LONG_DOUBLE_COMPLEX  ((R_MPI_Datatype)0x4c002042)

#ifdef MPICH_DEFINE_ATTR_TYPE_TYPES
static  R_MPI_Datatype mpich_mpi_c_bool                MPICH_ATTR_TYPE_TAG_C99(_Bool)           = R_MPI_C_BOOL;
static  R_MPI_Datatype mpich_mpi_c_float_complex       MPICH_ATTR_TYPE_TAG_C99(float _Complex)  = R_MPI_C_FLOAT_COMPLEX;
static  R_MPI_Datatype mpich_mpi_c_double_complex      MPICH_ATTR_TYPE_TAG_C99(double _Complex) = R_MPI_C_DOUBLE_COMPLEX;
#if 0x4c002042 != 0x0c000000
static  R_MPI_Datatype mpich_mpi_c_long_double_complex MPICH_ATTR_TYPE_TAG_C99(long double _Complex) = R_MPI_C_LONG_DOUBLE_COMPLEX;
#endif
#endif

/* address/offset types */
#define R_MPI_AINT          ((R_MPI_Datatype)0x4c000843)
#define R_MPI_OFFSET        ((R_MPI_Datatype)0x4c000844)
#define R_MPI_COUNT         ((R_MPI_Datatype)0x4c000845)

/* MPI-3 C++ types */
#define R_MPI_CXX_BOOL                ((R_MPI_Datatype)0x4c000133)
#define R_MPI_CXX_FLOAT_COMPLEX       ((R_MPI_Datatype)0x4c000834)
#define R_MPI_CXX_DOUBLE_COMPLEX      ((R_MPI_Datatype)0x4c001035)
#define R_MPI_CXX_LONG_DOUBLE_COMPLEX ((R_MPI_Datatype)0x4c002036)

/* typeclasses */
#define R_MPI_TYPECLASS_REAL 1
#define R_MPI_TYPECLASS_INTEGER 2
#define R_MPI_TYPECLASS_COMPLEX 3

/* Communicators */
typedef int R_MPI_Comm;
#define R_MPI_COMM_WORLD ((R_MPI_Comm)0x44000000)
#define R_MPI_COMM_SELF  ((R_MPI_Comm)0x44000001)

/* Groups */
typedef int R_MPI_Group;
#define R_MPI_GROUP_EMPTY ((R_MPI_Group)0x48000000)

/* RMA and Windows */
typedef int R_MPI_Win;
#define R_MPI_WIN_NULL ((R_MPI_Win)0x20000000)

/* File and IO */
/* This define lets ROMIO know that R_MPI_File has been defined */
#define R_MPI_FILE_DEFINED
/* ROMIO uses a pointer for R_MPI_File objects.  This must be the same definition
   as in src/mpi/romio/include/mpio.h.in  */
typedef struct ADIOI_FileD *R_MPI_File;
#define R_MPI_FILE_NULL ((R_MPI_File)0)

/* Collective operations */
typedef int R_MPI_Op;

#define R_MPI_MAX     (R_MPI_Op)(0x58000001)
#define R_MPI_MIN     (R_MPI_Op)(0x58000002)
#define R_MPI_SUM     (R_MPI_Op)(0x58000003)
#define R_MPI_PROD    (R_MPI_Op)(0x58000004)
#define R_MPI_LAND    (R_MPI_Op)(0x58000005)
#define R_MPI_BAND    (R_MPI_Op)(0x58000006)
#define R_MPI_LOR     (R_MPI_Op)(0x58000007)
#define R_MPI_BOR     (R_MPI_Op)(0x58000008)
#define R_MPI_LXOR    (R_MPI_Op)(0x58000009)
#define R_MPI_BXOR    (R_MPI_Op)(0x5800000a)
#define R_MPI_MINLOC  (R_MPI_Op)(0x5800000b)
#define R_MPI_MAXLOC  (R_MPI_Op)(0x5800000c)
#define R_MPI_REPLACE (R_MPI_Op)(0x5800000d)
#define R_MPI_NO_OP   (R_MPI_Op)(0x5800000e)

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
#define R_MPI_TAG_UB           0x64400001
#define R_MPI_HOST             0x64400003
#define R_MPI_IO               0x64400005
#define R_MPI_WTIME_IS_GLOBAL  0x64400007
#define R_MPI_UNIVERSE_SIZE    0x64400009
#define R_MPI_LASTUSEDCODE     0x6440000b
#define R_MPI_APPNUM           0x6440000d

/* In addition, there are 5 predefined window attributes that are
   defined for every window */
#define R_MPI_WIN_BASE          0x66000001
#define R_MPI_WIN_SIZE          0x66000003
#define R_MPI_WIN_DISP_UNIT     0x66000005
#define R_MPI_WIN_CREATE_FLAVOR 0x66000007
#define R_MPI_WIN_MODEL         0x66000009

#ifdef MPICH_DEFINE_ATTR_TYPE_TYPES
static  R_MPI_Datatype mpich_mpi_datatype_null MPICH_ATTR_TYPE_TAG_MUST_BE_NULL() = R_MPI_DATATYPE_NULL;
#endif

/* These are only guesses; make sure you change them in mpif.h as well */
#define R_MPI_MAX_PROCESSOR_NAME 128
#define R_MPI_MAX_LIBRARY_VERSION_STRING 8192
#define R_MPI_MAX_ERROR_STRING   512
#define R_MPI_MAX_PORT_NAME      256
#define R_MPI_MAX_OBJECT_NAME    128
#define R_MPI_MAX_DATAREP_STRING 128

/* Pre-defined ants */
#define R_MPI_UNDEFINED      (-32766)
#define R_MPI_UNDEFINED_RANK R_MPI_UNDEFINED
#define R_MPI_KEYVAL_INVALID 0x24000000

/* MPI-3 window flavors */
typedef enum R_MPIR_Win_flavor {
    R_MPI_WIN_FLAVOR_CREATE      = 1,
    R_MPI_WIN_FLAVOR_ALLOCATE    = 2,
    R_MPI_WIN_FLAVOR_DYNAMIC     = 3,
    R_MPI_WIN_FLAVOR_SHARED      = 4
} R_MPIR_Win_flavor_t;

/* MPI-3 window consistency models */
typedef enum A_MPIR_Win_model {
    R_MPI_WIN_SEPARATE   = 1,
    R_MPI_WIN_UNIFIED    = 2
} A_MPIR_Win_model_t;

/* Upper bound on the overhead in bsend for each message buffer */
#define R_MPI_BSEND_OVERHEAD 95

/* Topology types */
typedef enum R_MPIR_Topo_type { R_MPI_GRAPH=1, R_MPI_CART=2, R_MPI_DIST_GRAPH=3 } R_MPIR_Topo_type;

#define R_MPI_BOTTOM      (void *)0

#define R_MPI_PROC_NULL   (-1)
#define R_MPI_ANY_SOURCE 	(-2)
#define R_MPI_ROOT        (-3)
#define R_MPI_ANY_TAG     (-1)

#define R_MPI_LOCK_EXCLUSIVE  234
#define R_MPI_LOCK_SHARED     235

/* C functions */
typedef void (R_MPI_Handler_function) ( R_MPI_Comm *, int *, ... );
typedef int (R_MPI_Comm_copy_attr_function)(R_MPI_Comm, int, void *, void *, 
					  void *, int *);
typedef int (R_MPI_Comm_delete_attr_function)(R_MPI_Comm, int, void *, void *);
typedef int (R_MPI_Type_copy_attr_function)(R_MPI_Datatype, int, void *, void *, 
					  void *, int *);
typedef int (R_MPI_Type_delete_attr_function)(R_MPI_Datatype, int, void *, void *);
typedef int (R_MPI_Win_copy_attr_function)(R_MPI_Win, int, void *, void *, void *,
					 int *);
typedef int (R_MPI_Win_delete_attr_function)(R_MPI_Win, int, void *, void *);
/* added in MPI-2.2 */
typedef void (R_MPI_Comm_errhandler_function)(R_MPI_Comm *, int *, ...);
typedef void (R_MPI_File_errhandler_function)(R_MPI_File *, int *, ...);
typedef void (R_MPI_Win_errhandler_function)(R_MPI_Win *, int *, ...);
/* names that were added in MPI-2.0 and deprecated in MPI-2.2 */
typedef R_MPI_Comm_errhandler_function R_MPI_Comm_errhandler_fn;
typedef R_MPI_File_errhandler_function R_MPI_File_errhandler_fn;
typedef R_MPI_Win_errhandler_function R_MPI_Win_errhandler_fn;

/* Built in (0x1 in 30-31), errhandler (0x5 in bits 26-29, allkind (0
   in 22-25), index in the low bits */
#define R_MPI_ERRORS_ARE_FATAL ((R_MPI_Errhandler)0x54000000)
#define R_MPI_ERRORS_RETURN    ((R_MPI_Errhandler)0x54000001)
/* MPIR_ERRORS_THROW_EXCEPTIONS is not part of the MPI standard, it is here to
   facilitate the c++ binding which has MPI::ERRORS_THROW_EXCEPTIONS. 
   Using the MPIR prefix preserved the R_MPI_ names for objects defined by
   the standard. */
#define R_MPIR_ERRORS_THROW_EXCEPTIONS ((R_MPI_Errhandler)0x54000002)
typedef int R_MPI_Errhandler;

/* Make the C names for the dup function mixed case.
   This is required for systems that use all uppercase names for Fortran 
   externals.  */
/* MPI 1 names */
#define R_MPI_NULL_COPY_FN   ((R_MPI_Copy_function *)0)
#define R_MPI_NULL_DELETE_FN ((R_MPI_Delete_function *)0)
#define R_MPI_DUP_FN         MPIR_Dup_fn
/* MPI 2 names */
#define R_MPI_COMM_NULL_COPY_FN ((R_MPI_Comm_copy_attr_function*)0)
#define R_MPI_COMM_NULL_DELETE_FN ((R_MPI_Comm_delete_attr_function*)0)
#define R_MPI_COMM_DUP_FN  ((R_MPI_Comm_copy_attr_function *)R_MPI_DUP_FN)
#define R_MPI_WIN_NULL_COPY_FN ((R_MPI_Win_copy_attr_function*)0)
#define R_MPI_WIN_NULL_DELETE_FN ((R_MPI_Win_delete_attr_function*)0)
#define R_MPI_WIN_DUP_FN   ((R_MPI_Win_copy_attr_function*)R_MPI_DUP_FN)
#define R_MPI_TYPE_NULL_COPY_FN ((R_MPI_Type_copy_attr_function*)0)
#define R_MPI_TYPE_NULL_DELETE_FN ((R_MPI_Type_delete_attr_function*)0)
#define R_MPI_TYPE_DUP_FN ((R_MPI_Type_copy_attr_function*)R_MPI_DUP_FN)

/* MPI request opjects */
typedef int R_MPI_Request;

/* MPI message objects for Mprobe and related functions */
typedef int R_MPI_Message;

/* User combination function */
typedef void (R_MPI_User_function) ( void *, void *, int *, R_MPI_Datatype * ); 

/* MPI Attribute copy and delete functions */
typedef int (R_MPI_Copy_function) ( R_MPI_Comm, int, void *, void *, void *, int * );
typedef int (R_MPI_Delete_function) ( R_MPI_Comm, int, void *, void * );

#define R_MPI_VERSION    3
#define R_MPI_SUBVERSION 0
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
enum R_MPIR_Combiner_enum {
    R_MPI_COMBINER_NAMED            = 1,
    R_MPI_COMBINER_DUP              = 2,
    R_MPI_COMBINER_CONTIGUOUS       = 3, 
    R_MPI_COMBINER_VECTOR           = 4,
    R_MPI_COMBINER_HVECTOR_INTEGER  = 5,
    R_MPI_COMBINER_HVECTOR          = 6,
    R_MPI_COMBINER_INDEXED          = 7,
    R_MPI_COMBINER_HINDEXED_INTEGER = 8, 
    R_MPI_COMBINER_HINDEXED         = 9, 
    R_MPI_COMBINER_INDEXED_BLOCK    = 10, 
    R_MPI_COMBINER_STRUCT_INTEGER   = 11,
    R_MPI_COMBINER_STRUCT           = 12,
    R_MPI_COMBINER_SUBARRAY         = 13,
    R_MPI_COMBINER_DARRAY           = 14,
    R_MPI_COMBINER_F90_REAL         = 15,
    R_MPI_COMBINER_F90_COMPLEX      = 16,
    R_MPI_COMBINER_F90_INTEGER      = 17,
    R_MPI_COMBINER_RESIZED          = 18,
    R_MPI_COMBINER_HINDEXED_BLOCK   = 19
};

/* for info */
typedef int R_MPI_Info;
#define R_MPI_INFO_NULL         ((R_MPI_Info)0x1c000000)
#define R_MPI_INFO_ENV          ((R_MPI_Info)0x5c000001)
#define R_MPI_MAX_INFO_KEY       255
#define R_MPI_MAX_INFO_VAL      1024

/* for subarray and darray ructors */
#define R_MPI_ORDER_C              56
#define R_MPI_ORDER_FORTRAN        57
#define R_MPI_DISTRIBUTE_BLOCK    121
#define R_MPI_DISTRIBUTE_CYCLIC   122
#define R_MPI_DISTRIBUTE_NONE     123
#define R_MPI_DISTRIBUTE_DFLT_DARG -49767

#define R_MPI_IN_PLACE  (void *) -1

/* asserts for one-sided communication */
#define R_MPI_MODE_NOCHECK      1024
#define R_MPI_MODE_NOSTORE      2048
#define R_MPI_MODE_NOPUT        4096
#define R_MPI_MODE_NOPRECEDE    8192
#define R_MPI_MODE_NOSUCCEED   16384 

/* predefined types for R_MPI_Comm_split_type */
#define R_MPI_COMM_TYPE_SHARED    1

/* Definitions that are determined by configure. */
typedef long R_MPI_Aint;
typedef int R_MPI_Fint;
typedef long long R_MPI_Count;

#ifdef MPICH_DEFINE_ATTR_TYPE_TYPES
static  R_MPI_Datatype mpich_mpi_aint   MPICH_ATTR_TYPE_TAG(R_MPI_Aint)   = R_MPI_AINT;
#endif

/* FIXME: The following two definition are not defined by MPI and must not be
   included in the mpi.h file, as the MPI namespace is reserved to the MPI 
   standard */
#define R_MPI_AINT_FMT_DEC_SPEC "%ld"
#define R_MPI_AINT_FMT_HEX_SPEC "%lx"

/* Let ROMIO know that R_MPI_Offset is already defined */
#define HAVE_R_MPI_OFFSET
/* R_MPI_OFFSET_TYPEDEF is set in configure and is 
      typedef $R_MPI_OFFSET R_MPI_Offset;
   where $R_MPI_OFFSET is the correct C type */
typedef long long R_MPI_Offset;

#ifdef MPICH_DEFINE_ATTR_TYPE_TYPES
static  R_MPI_Datatype mpich_mpi_offset MPICH_ATTR_TYPE_TAG(R_MPI_Offset) = R_MPI_OFFSET;
#endif

/* The order of these elements must match that in mpif.h, mpi_f08_types.f90,
   and mpi_c_interface_types.f90 */
typedef struct R_MPI_Status {
    int count_lo;
    int count_hi_and_cancelled;
    int R_MPI_SOURCE;
    int R_MPI_TAG;
    int R_MPI_ERROR;
} R_MPI_Status;

/* types for the R_MPI_T_ interface */
struct MPIR_T_enum_s;
struct MPIR_T_cvar_handle_s;
struct MPIR_T_pvar_handle_s;
struct MPIR_T_pvar_session_s;

typedef struct MPIR_T_enum_s * R_MPI_T_enum;
typedef struct MPIR_T_cvar_handle_s * R_MPI_T_cvar_handle;
typedef struct MPIR_T_pvar_handle_s * R_MPI_T_pvar_handle;
typedef struct MPIR_T_pvar_session_s * R_MPI_T_pvar_session;

/* extra  at front would be safer, but is incompatible with R_MPI_T_ prototypes */
extern struct MPIR_T_pvar_handle_s *  R_MPI_T_PVAR_ALL_HANDLES;

#define R_MPI_T_ENUM_NULL         ((R_MPI_T_enum)NULL)
#define R_MPI_T_CVAR_HANDLE_NULL  ((R_MPI_T_cvar_handle)NULL)
#define R_MPI_T_PVAR_HANDLE_NULL  ((R_MPI_T_pvar_handle)NULL)
#define R_MPI_T_PVAR_SESSION_NULL ((R_MPI_T_pvar_session)NULL)

/* the R_MPI_T_ interface requires that these VERBOSITY ants occur in this
 * relative order with increasing values */
typedef enum R_MPIR_T_verbosity_t {
    /* don't name-shift this if/when R_MPI_T_ is accepted, this is an MPICH-only
     * extension */
    R_MPIX_T_VERBOSITY_INVALID = 0,

    /* arbitrarily shift values to aid debugging and reduce accidental errors */
    R_MPI_T_VERBOSITY_USER_BASIC = 221,
    R_MPI_T_VERBOSITY_USER_DETAIL,
    R_MPI_T_VERBOSITY_USER_ALL,

    R_MPI_T_VERBOSITY_TUNER_BASIC,
    R_MPI_T_VERBOSITY_TUNER_DETAIL,
    R_MPI_T_VERBOSITY_TUNER_ALL,

    R_MPI_T_VERBOSITY_MPIDEV_BASIC,
    R_MPI_T_VERBOSITY_MPIDEV_DETAIL,
    R_MPI_T_VERBOSITY_MPIDEV_ALL
} R_MPIR_T_verbosity_t;

typedef enum R_MPIR_T_bind_t {
    /* don't name-shift this if/when R_MPI_T_ is accepted, this is an MPICH-only
     * extension */
    MPIX_T_BIND_INVALID = 0,

    /* arbitrarily shift values to aid debugging and reduce accidental errors */
    R_MPI_T_BIND_NO_OBJECT = 9700,
    R_MPI_T_BIND_R_MPI_COMM,
    R_MPI_T_BIND_R_MPI_DATATYPE,
    R_MPI_T_BIND_R_MPI_ERRHANDLER,
    R_MPI_T_BIND_R_MPI_FILE,
    R_MPI_T_BIND_R_MPI_GROUP,
    R_MPI_T_BIND_R_MPI_OP,
    R_MPI_T_BIND_R_MPI_REQUEST,
    R_MPI_T_BIND_R_MPI_WIN,
    R_MPI_T_BIND_R_MPI_MESSAGE,
    R_MPI_T_BIND_R_MPI_INFO
} R_MPIR_T_bind_t;

typedef enum R_MPIR_T_scope_t {
    /* don't name-shift this if/when R_MPI_T_ is accepted, this is an MPICH-only
     * extension */
    R_MPIX_T_SCOPE_INVALID = 0,

    /* arbitrarily shift values to aid debugging and reduce accidental errors */
    R_MPI_T_SCOPE_CONSTANT = 60438,
    R_MPI_T_SCOPE_READONLY,
    R_MPI_T_SCOPE_LOCAL,
    R_MPI_T_SCOPE_GROUP,
    R_MPI_T_SCOPE_GROUP_EQ,
    R_MPI_T_SCOPE_ALL,
    R_MPI_T_SCOPE_ALL_EQ
} R_MPIR_T_scope_t;

typedef enum R_MPIR_T_pvar_class_t {
    /* don't name-shift this if/when R_MPI_T_ is accepted, this is an MPICH-only
     * extension */
    R_MPIX_T_PVAR_CLASS_INVALID = 0,

    /* arbitrarily shift values to aid debugging and reduce accidental errors */
    R_MPIR_T_PVAR_CLASS_FIRST = 240,
    R_MPI_T_PVAR_CLASS_STATE = R_MPIR_T_PVAR_CLASS_FIRST,
    R_MPI_T_PVAR_CLASS_LEVEL,
    R_MPI_T_PVAR_CLASS_SIZE,
    R_MPI_T_PVAR_CLASS_PERCENTAGE,
    R_MPI_T_PVAR_CLASS_HIGHWATERMARK,
    R_MPI_T_PVAR_CLASS_LOWWATERMARK,
    R_MPI_T_PVAR_CLASS_COUNTER,
    R_MPI_T_PVAR_CLASS_AGGREGATE,
    R_MPI_T_PVAR_CLASS_TIMER,
    R_MPI_T_PVAR_CLASS_GENERIC,
    R_MPIR_T_PVAR_CLASS_LAST,
    R_MPIR_T_PVAR_CLASS_NUMBER = R_MPIR_T_PVAR_CLASS_LAST - R_MPIR_T_PVAR_CLASS_FIRST
} R_MPIR_T_pvar_class_t;

/* Handle conversion types/functions */

/* Programs that need to convert types used in MPICH should use these */
#define R_MPI_Comm_c2f(comm) (R_MPI_Fint)(comm)
#define R_MPI_Comm_f2c(comm) (R_MPI_Comm)(comm)
#define R_MPI_Type_c2f(datatype) (R_MPI_Fint)(datatype)
#define R_MPI_Type_f2c(datatype) (R_MPI_Datatype)(datatype)
#define R_MPI_Group_c2f(group) (R_MPI_Fint)(group)
#define R_MPI_Group_f2c(group) (R_MPI_Group)(group)
#define R_MPI_Info_c2f(info) (R_MPI_Fint)(info)
#define R_MPI_Info_f2c(info) (R_MPI_Info)(info)
#define R_MPI_Request_f2c(request) (R_MPI_Request)(request)
#define R_MPI_Request_c2f(request) (R_MPI_Fint)(request)
#define R_MPI_Op_c2f(op) (R_MPI_Fint)(op)
#define R_MPI_Op_f2c(op) (R_MPI_Op)(op)
#define R_MPI_Errhandler_c2f(errhandler) (R_MPI_Fint)(errhandler)
#define R_MPI_Errhandler_f2c(errhandler) (R_MPI_Errhandler)(errhandler)
#define R_MPI_Win_c2f(win)   (R_MPI_Fint)(win)
#define R_MPI_Win_f2c(win)   (R_MPI_Win)(win)
#define R_MPI_Message_c2f(msg) ((R_MPI_Fint)(msg))
#define R_MPI_Message_f2c(msg) ((R_MPI_Message)(msg))

/* PMPI versions of the handle transfer functions.  See section 4.17 */
#define R_PMPIComm_c2f(comm) (R_MPI_Fint)(comm)
#define R_PMPIComm_f2c(comm) (R_MPI_Comm)(comm)
#define R_PMPIType_c2f(datatype) (R_MPI_Fint)(datatype)
#define R_PMPIType_f2c(datatype) (R_MPI_Datatype)(datatype)
#define R_PMPIGroup_c2f(group) (R_MPI_Fint)(group)
#define R_PMPIGroup_f2c(group) (R_MPI_Group)(group)
#define R_PMPIInfo_c2f(info) (R_MPI_Fint)(info)
#define R_PMPIInfo_f2c(info) (R_MPI_Info)(info)
#define R_PMPIRequest_f2c(request) (R_MPI_Request)(request)
#define R_PMPIRequest_c2f(request) (R_MPI_Fint)(request)
#define R_PMPIOp_c2f(op) (R_MPI_Fint)(op)
#define R_PMPIOp_f2c(op) (R_MPI_Op)(op)
#define R_PMPIErrhandler_c2f(errhandler) (R_MPI_Fint)(errhandler)
#define R_PMPIErrhandler_f2c(errhandler) (R_MPI_Errhandler)(errhandler)
#define R_PMPIWin_c2f(win)   (R_MPI_Fint)(win)
#define R_PMPIWin_f2c(win)   (R_MPI_Win)(win)
#define R_PMPIMessage_c2f(msg) ((R_MPI_Fint)(msg))
#define R_PMPIMessage_f2c(msg) ((R_MPI_Message)(msg))

#define R_MPI_STATUS_IGNORE (R_MPI_Status *)1
#define R_MPI_STATUSES_IGNORE (R_MPI_Status *)1
#define R_MPI_ERRCODES_IGNORE (int *)0

/* See 4.12.5 for R_MPI_F_STATUS(ES)_IGNORE */
#define MPIU_DLL_SPEC
extern MPIU_DLL_SPEC R_MPI_Fint * R_MPI_F_STATUS_IGNORE;
extern MPIU_DLL_SPEC R_MPI_Fint * R_MPI_F_STATUSES_IGNORE;
//extern MPIU_DLL_SPEC int *  R_MPI_UNWEIGHTED;
//extern MPIU_DLL_SPEC int *  R_MPI_WEIGHTS_EMPTY;
int *  R_MPI_UNWEIGHTED;
int *  R_MPI_WEIGHTS_EMPTY;

/* The annotation MPIU_DLL_SPEC to the extern statements is used 
   as a hook for systems that require C extensions to correctly ruct
   DLLs, and is defined as an empty string otherwise
 */

/* The MPI standard requires that the ARGV_NULL values be the same as
   NULL (see 5.3.2) */
#define R_MPI_ARGV_NULL (char **)0
#define R_MPI_ARGVS_NULL (char ***)0

/* C type for R_MPI_STATUS in F08.
   The field order should match that in mpi_f08_types.f90, and mpi_c_interface_types.f90.
 */
typedef struct {
    R_MPI_Fint count_lo;
    R_MPI_Fint count_hi_and_cancelled;
    R_MPI_Fint R_MPI_SOURCE;
    R_MPI_Fint R_MPI_TAG;
    R_MPI_Fint R_MPI_ERROR;
} R_MPI_F08_Status;

extern R_MPI_F08_Status MPIR_F08_R_MPI_STATUS_IGNORE_OBJ;
extern R_MPI_F08_Status MPIR_F08_R_MPI_STATUSES_IGNORE_OBJ[1];
extern int MPIR_F08_R_MPI_IN_PLACE;
extern int MPIR_F08_R_MPI_BOTTOM;

/* Pointers to above objects */
extern R_MPI_F08_Status *R_MPI_F08_STATUS_IGNORE;
extern R_MPI_F08_Status *R_MPI_F08_STATUSES_IGNORE;

/* For supported thread levels */
#define R_MPI_THREAD_SINGLE 0
#define R_MPI_THREAD_FUNNELED 1
#define R_MPI_THREAD_SERIALIZED 2
#define R_MPI_THREAD_MULTIPLE 3

/* Typedefs for generalized requests */
typedef int (R_MPI_Grequest_cancel_function)(void *, int); 
typedef int (R_MPI_Grequest_free_function)(void *); 
typedef int (R_MPI_Grequest_query_function)(void *, R_MPI_Status *); 
typedef int (R_MPIX_Grequest_poll_function)(void *, R_MPI_Status *);
typedef int (R_MPIX_Grequest_wait_function)(int, void **, double, R_MPI_Status *);

/* MPI's error classes */
#define R_MPI_SUCCESS          0      /* Successful return code */
/* Communication argument parameters */
#define R_MPI_ERR_BUFFER       1      /* Invalid buffer pointer */
#define R_MPI_ERR_COUNT        2      /* Invalid count argument */
#define R_MPI_ERR_TYPE         3      /* Invalid datatype argument */
#define R_MPI_ERR_TAG          4      /* Invalid tag argument */
#define R_MPI_ERR_COMM         5      /* Invalid communicator */
#define R_MPI_ERR_RANK         6      /* Invalid rank */
#define R_MPI_ERR_ROOT         7      /* Invalid root */
#define R_MPI_ERR_TRUNCATE    14      /* Message truncated on receive */

/* MPI Objects (other than COMM) */
#define R_MPI_ERR_GROUP        8      /* Invalid group */
#define R_MPI_ERR_OP           9      /* Invalid operation */
#define R_MPI_ERR_REQUEST     19      /* Invalid mpi_request handle */

/* Special topology argument parameters */
#define R_MPI_ERR_TOPOLOGY    10      /* Invalid topology */
#define R_MPI_ERR_DIMS        11      /* Invalid dimension argument */

/* All other arguments.  This is a class with many kinds */
#define R_MPI_ERR_ARG         12      /* Invalid argument */

/* Other errors that are not simply an invalid argument */
#define R_MPI_ERR_OTHER       15      /* Other error; use Error_string */

#define R_MPI_ERR_UNKNOWN     13      /* Unknown error */
#define R_MPI_ERR_INTERN      16      /* Internal error code    */

/* Multiple completion has two special error classes */
#define R_MPI_ERR_IN_STATUS   17      /* Look in status for error value */
#define R_MPI_ERR_PENDING     18      /* Pending request */

/* New MPI-2 Error classes */
#define R_MPI_ERR_FILE        27      /* */
#define R_MPI_ERR_ACCESS      20      /* */
#define R_MPI_ERR_AMODE       21      /* */
#define R_MPI_ERR_BAD_FILE    22      /* */
#define R_MPI_ERR_FILE_EXISTS 25      /* */
#define R_MPI_ERR_FILE_IN_USE 26      /* */
#define R_MPI_ERR_NO_SPACE    36      /* */
#define R_MPI_ERR_NO_SUCH_FILE 37     /* */
#define R_MPI_ERR_IO          32      /* */
#define R_MPI_ERR_READ_ONLY   40      /* */
#define R_MPI_ERR_CONVERSION  23      /* */
#define R_MPI_ERR_DUP_DATAREP 24      /* */
#define R_MPI_ERR_UNSUPPORTED_DATAREP   43  /* */

/* R_MPI_ERR_INFO is NOT defined in the MPI-2 standard.  I believe that
   this is an oversight */
#define R_MPI_ERR_INFO        28      /* */
#define R_MPI_ERR_INFO_KEY    29      /* */
#define R_MPI_ERR_INFO_VALUE  30      /* */
#define R_MPI_ERR_INFO_NOKEY  31      /* */

#define R_MPI_ERR_NAME        33      /* */
#define R_MPI_ERR_NO_MEM      34      /* Alloc_mem could not allocate memory */
#define R_MPI_ERR_NOT_SAME    35      /* */
#define R_MPI_ERR_PORT        38      /* */
#define R_MPI_ERR_QUOTA       39      /* */
#define R_MPI_ERR_SERVICE     41      /* */
#define R_MPI_ERR_SPAWN       42      /* */
#define R_MPI_ERR_UNSUPPORTED_OPERATION 44 /* */
#define R_MPI_ERR_WIN         45      /* */

#define R_MPI_ERR_BASE        46      /* */
#define R_MPI_ERR_LOCKTYPE    47      /* */
#define R_MPI_ERR_KEYVAL      48      /* Erroneous attribute key */
#define R_MPI_ERR_RMA_CONFLICT 49     /* */
#define R_MPI_ERR_RMA_SYNC    50      /* */ 
#define R_MPI_ERR_SIZE        51      /* */
#define R_MPI_ERR_DISP        52      /* */
#define R_MPI_ERR_ASSERT      53      /* */

#define MPIX_ERR_PROC_FAIL_STOP 54   /* Process failure */

#define R_MPI_ERR_RMA_RANGE  55       /* */
#define R_MPI_ERR_RMA_ATTACH 56       /* */
#define R_MPI_ERR_RMA_SHARED 57       /* */
#define R_MPI_ERR_RMA_FLAVOR 58       /* */

/* Return codes for functions in the MPI Tool Information Interface */
#define R_MPI_T_ERR_MEMORY            59  /* Out of memory */
#define R_MPI_T_ERR_NOT_INITIALIZED   60  /* Interface not initialized */
#define R_MPI_T_ERR_CANNOT_INIT       61  /* Interface not in the state to
                                           be initialized */
#define R_MPI_T_ERR_INVALID_INDEX     62  /* The index is invalid or
                                           has been deleted  */
#define R_MPI_T_ERR_INVALID_ITEM      63  /* Item index queried is out of range */
#define R_MPI_T_ERR_INVALID_HANDLE    64  /* The handle is invalid */
#define R_MPI_T_ERR_OUT_OF_HANDLES    65  /* No more handles available */
#define R_MPI_T_ERR_OUT_OF_SESSIONS   66  /* No more sessions available */
#define R_MPI_T_ERR_INVALID_SESSION   67  /* Session argument is not valid */
#define R_MPI_T_ERR_CVAR_SET_NOT_NOW  68  /* Cvar can't be set at this moment */
#define R_MPI_T_ERR_CVAR_SET_NEVER    69  /* Cvar can't be set until
                                           end of execution */
#define R_MPI_T_ERR_PVAR_NO_STARTSTOP 70  /* Pvar can't be started or stopped */
#define R_MPI_T_ERR_PVAR_NO_WRITE     71  /* Pvar can't be written or reset */
#define R_MPI_T_ERR_PVAR_NO_ATOMIC    72  /* Pvar can't be R/W atomically */

#define R_MPI_ERR_LASTCODE    0x3fffffff  /* Last valid error code for a 
					   predefined error class */
#define R_MPI_T_ERR_INVALID_NAME      73  /* Name doesn't match */
#define R_MPI_T_ERR_INVALID           74  /* Generic error code for MPI_T added in MPI-3.1 */
/* WARNING: this is also defined in mpishared.h.  Update both locations */
#define MPICH_ERR_LAST_CLASS 74     /* It is also helpful to know the
				       last valid class */
/* End of MPI's error classes */

/* Function type defs */
typedef int (R_MPI_Datarep_conversion_function)(void *, R_MPI_Datatype, int, 
             void *, R_MPI_Offset, void *);
typedef int (R_MPI_Datarep_extent_function)(R_MPI_Datatype datatype, R_MPI_Aint *,
					  void *);
#define R_MPI_CONVERSION_FN_NULL ((R_MPI_Datarep_conversion_function *)0)

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
int R_MPI_Send( void *buf, int count, R_MPI_Datatype datatype, int dest, int tag,
             R_MPI_Comm comm) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_MPI_Recv(void *buf, int count, R_MPI_Datatype datatype, int source, int tag,
             R_MPI_Comm comm, R_MPI_Status *status) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_MPI_Get_count( R_MPI_Status *status, R_MPI_Datatype datatype, int *count);
int R_MPI_Bsend( void *buf, int count, R_MPI_Datatype datatype, int dest, int tag,
              R_MPI_Comm comm) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_MPI_Ssend( void *buf, int count, R_MPI_Datatype datatype, int dest, int tag,
              R_MPI_Comm comm) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_MPI_Rsend( void *buf, int count, R_MPI_Datatype datatype, int dest, int tag,
              R_MPI_Comm comm) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_MPI_Buffer_attach(void *buffer, int size);
int R_MPI_Buffer_detach(void *buffer_addr, int *size);
int R_MPI_Isend( void *buf, int count, R_MPI_Datatype datatype, int dest, int tag,
              R_MPI_Comm comm, R_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_MPI_Ibsend( void *buf, int count, R_MPI_Datatype datatype, int dest, int tag,
               R_MPI_Comm comm, R_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_MPI_Issend( void *buf, int count, R_MPI_Datatype datatype, int dest, int tag,
               R_MPI_Comm comm, R_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_MPI_Irsend( void *buf, int count, R_MPI_Datatype datatype, int dest, int tag,
               R_MPI_Comm comm, R_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_MPI_Irecv(void *buf, int count, R_MPI_Datatype datatype, int source, int tag,
              R_MPI_Comm comm, R_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_MPI_Wait(R_MPI_Request *request, R_MPI_Status *status);
int R_MPI_Test(R_MPI_Request *request, int *flag, R_MPI_Status *status);
int R_MPI_Request_free(R_MPI_Request *request);
int R_MPI_Waitany(int count, R_MPI_Request array_of_requests[], int *indx, R_MPI_Status *status);
int R_MPI_Testany(int count, R_MPI_Request array_of_requests[], int *indx, int *flag,
                R_MPI_Status *status);
int R_MPI_Waitall(int count, R_MPI_Request array_of_requests[], R_MPI_Status array_of_statuses[]);
int R_MPI_Testall(int count, R_MPI_Request array_of_requests[], int *flag,
                R_MPI_Status array_of_statuses[]);
int R_MPI_Waitsome(int incount, R_MPI_Request array_of_requests[], int *outcount,
                 int array_of_indices[], R_MPI_Status array_of_statuses[]);
int R_MPI_Testsome(int incount, R_MPI_Request array_of_requests[], int *outcount,
                 int array_of_indices[], R_MPI_Status array_of_statuses[]);
int R_MPI_Iprobe(int source, int tag, R_MPI_Comm comm, int *flag, R_MPI_Status *status);
int R_MPI_Probe(int source, int tag, R_MPI_Comm comm, R_MPI_Status *status);
int R_MPI_Cancel(R_MPI_Request *request);
int R_MPI_Test_cancelled( R_MPI_Status *status, int *flag);
int R_MPI_Send_init( void *buf, int count, R_MPI_Datatype datatype, int dest, int tag,
                  R_MPI_Comm comm, R_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_MPI_Bsend_init( void *buf, int count, R_MPI_Datatype datatype, int dest, int tag,
                   R_MPI_Comm comm, R_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_MPI_Ssend_init( void *buf, int count, R_MPI_Datatype datatype, int dest, int tag,
                   R_MPI_Comm comm, R_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_MPI_Rsend_init( void *buf, int count, R_MPI_Datatype datatype, int dest, int tag,
                   R_MPI_Comm comm, R_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_MPI_Recv_init(void *buf, int count, R_MPI_Datatype datatype, int source, int tag,
                  R_MPI_Comm comm, R_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_MPI_Start(R_MPI_Request *request);
int R_MPI_Startall(int count, R_MPI_Request array_of_requests[]);
int R_MPI_Sendrecv( void *sendbuf, int sendcount, R_MPI_Datatype sendtype, int dest,
                 int sendtag, void *recvbuf, int recvcount, R_MPI_Datatype recvtype,
                 int source, int recvtag, R_MPI_Comm comm, R_MPI_Status *status)
                 MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(6,8);
int R_MPI_Sendrecv_replace(void *buf, int count, R_MPI_Datatype datatype, int dest,
                         int sendtag, int source, int recvtag, R_MPI_Comm comm,
                         R_MPI_Status *status) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_MPI_Type_contiguous(int count, R_MPI_Datatype oldtype, R_MPI_Datatype *newtype);
int R_MPI_Type_vector(int count, int blocklength, int stride, R_MPI_Datatype oldtype,
                    R_MPI_Datatype *newtype);
int R_MPI_Type_hvector(int count, int blocklength, R_MPI_Aint stride, R_MPI_Datatype oldtype,
                     R_MPI_Datatype *newtype);
int R_MPI_Type_indexed(int count,  int *array_of_blocklengths,
                      int *array_of_displacements, R_MPI_Datatype oldtype,
                     R_MPI_Datatype *newtype);
int R_MPI_Type_hindexed(int count,  int *array_of_blocklengths,
                       R_MPI_Aint *array_of_displacements, R_MPI_Datatype oldtype,
                      R_MPI_Datatype *newtype);
int R_MPI_Type_struct(int count,  int *array_of_blocklengths,
                     R_MPI_Aint *array_of_displacements,
                     R_MPI_Datatype *array_of_types, R_MPI_Datatype *newtype);
int R_MPI_Address( void *location, R_MPI_Aint *address);
int R_MPI_Type_extent(R_MPI_Datatype datatype, R_MPI_Aint *extent);
int R_MPI_Type_size(R_MPI_Datatype datatype, int *size);
int R_MPI_Type_lb(R_MPI_Datatype datatype, R_MPI_Aint *displacement);
int R_MPI_Type_ub(R_MPI_Datatype datatype, R_MPI_Aint *displacement);
int R_MPI_Type_commit(R_MPI_Datatype *datatype);
int R_MPI_Type_free(R_MPI_Datatype *datatype);
int R_MPI_Get_elements( R_MPI_Status *status, R_MPI_Datatype datatype, int *count);
int R_MPI_Pack( void *inbuf, int incount, R_MPI_Datatype datatype, void *outbuf,
             int outsize, int *position, R_MPI_Comm comm) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_MPI_Unpack( void *inbuf, int insize, int *position, void *outbuf, int outcount,
               R_MPI_Datatype datatype, R_MPI_Comm comm) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int R_MPI_Pack_size(int incount, R_MPI_Datatype datatype, R_MPI_Comm comm, int *size);
int R_MPI_Barrier(R_MPI_Comm comm);
int R_MPI_Bcast(void *buffer, int count, R_MPI_Datatype datatype, int root, R_MPI_Comm comm)
              MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_MPI_Gather( void *sendbuf, int sendcount, R_MPI_Datatype sendtype, void *recvbuf,
               int recvcount, R_MPI_Datatype recvtype, int root, R_MPI_Comm comm)
               MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int R_MPI_Gatherv( void *sendbuf, int sendcount, R_MPI_Datatype sendtype, void *recvbuf,
                 int *recvcounts,  int *displs, R_MPI_Datatype recvtype, int root,
                R_MPI_Comm comm)
                MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,7);
int R_MPI_Scatter( void *sendbuf, int sendcount, R_MPI_Datatype sendtype, void *recvbuf,
                int recvcount, R_MPI_Datatype recvtype, int root, R_MPI_Comm comm)
                MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int R_MPI_Scatterv( void *sendbuf,  int *sendcounts,  int *displs,
                 R_MPI_Datatype sendtype, void *recvbuf, int recvcount, R_MPI_Datatype recvtype,
                 int root, R_MPI_Comm comm)
                 MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(5,7);
int R_MPI_Allgather( void *sendbuf, int sendcount, R_MPI_Datatype sendtype, void *recvbuf,
                  int recvcount, R_MPI_Datatype recvtype, R_MPI_Comm comm)
                  MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int R_MPI_Allgatherv( void *sendbuf, int sendcount, R_MPI_Datatype sendtype, void *recvbuf,
                    int *recvcounts,  int *displs, R_MPI_Datatype recvtype, R_MPI_Comm comm)
                   MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,7);
int R_MPI_Alltoall( void *sendbuf, int sendcount, R_MPI_Datatype sendtype, void *recvbuf,
                 int recvcount, R_MPI_Datatype recvtype, R_MPI_Comm comm)
                 MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int R_MPI_Alltoallv( void *sendbuf,  int *sendcounts,  int *sdispls,
                  R_MPI_Datatype sendtype, void *recvbuf,  int *recvcounts,
                   int *rdispls, R_MPI_Datatype recvtype, R_MPI_Comm comm)
                  MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(5,8);
int R_MPI_Alltoallw( void *sendbuf,  int sendcounts[],  int sdispls[],
                   R_MPI_Datatype sendtypes[], void *recvbuf,  int recvcounts[],
                   int rdispls[],  R_MPI_Datatype recvtypes[], R_MPI_Comm comm);
int R_MPI_Exscan( void *sendbuf, void *recvbuf, int count, R_MPI_Datatype datatype,
               R_MPI_Op op, R_MPI_Comm comm)
               MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_MPI_Reduce( void *sendbuf, void *recvbuf, int count, R_MPI_Datatype datatype,
               R_MPI_Op op, int root, R_MPI_Comm comm)
               MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_MPI_Op_create(R_MPI_User_function *user_fn, int commute, R_MPI_Op *op);
int R_MPI_Op_free(R_MPI_Op *op);
int R_MPI_Allreduce(void *sendbuf, void *recvbuf, int count, R_MPI_Datatype datatype,
                  R_MPI_Op op, R_MPI_Comm comm)
                  MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_MPI_Reduce_scatter( void *sendbuf, void *recvbuf,  int recvcounts[],
                       R_MPI_Datatype datatype, R_MPI_Op op, R_MPI_Comm comm)
                       MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_MPI_Scan( void *sendbuf, void *recvbuf, int count, R_MPI_Datatype datatype, R_MPI_Op op,
             R_MPI_Comm comm)
             MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_MPI_Group_size(R_MPI_Group group, int *size);
int R_MPI_Group_rank(R_MPI_Group group, int *rank);
int R_MPI_Group_translate_ranks(R_MPI_Group group1, int n,  int ranks1[], R_MPI_Group group2,
                              int ranks2[]);
int R_MPI_Group_compare(R_MPI_Group group1, R_MPI_Group group2, int *result);
int R_MPI_Comm_group(R_MPI_Comm comm, R_MPI_Group *group);
int R_MPI_Group_union(R_MPI_Group group1, R_MPI_Group group2, R_MPI_Group *newgroup);
int R_MPI_Group_intersection(R_MPI_Group group1, R_MPI_Group group2, R_MPI_Group *newgroup);
int R_MPI_Group_difference(R_MPI_Group group1, R_MPI_Group group2, R_MPI_Group *newgroup);
int R_MPI_Group_incl(R_MPI_Group group, int n,  int ranks[], R_MPI_Group *newgroup);
int R_MPI_Group_excl(R_MPI_Group group, int n,  int ranks[], R_MPI_Group *newgroup);
int R_MPI_Group_range_incl(R_MPI_Group group, int n, int ranges[][3], R_MPI_Group *newgroup);
int R_MPI_Group_range_excl(R_MPI_Group group, int n, int ranges[][3], R_MPI_Group *newgroup);
int R_MPI_Group_free(R_MPI_Group *group);
int R_MPI_Comm_size(R_MPI_Comm comm, int *size);
int R_MPI_Comm_rank(R_MPI_Comm comm, int *rank);
int R_MPI_Comm_compare(R_MPI_Comm comm1, R_MPI_Comm comm2, int *result);
int R_MPI_Comm_dup(R_MPI_Comm comm, R_MPI_Comm *newcomm);
int R_MPI_Comm_dup_with_info(R_MPI_Comm comm, R_MPI_Info info, R_MPI_Comm *newcomm);
int R_MPI_Comm_create(R_MPI_Comm comm, R_MPI_Group group, R_MPI_Comm *newcomm);
int R_MPI_Comm_split(R_MPI_Comm comm, int color, int key, R_MPI_Comm *newcomm);
int R_MPI_Comm_free(R_MPI_Comm *comm);
int R_MPI_Comm_test_inter(R_MPI_Comm comm, int *flag);
int R_MPI_Comm_remote_size(R_MPI_Comm comm, int *size);
int R_MPI_Comm_remote_group(R_MPI_Comm comm, R_MPI_Group *group);
int R_MPI_Intercomm_create(R_MPI_Comm local_comm, int local_leader, R_MPI_Comm peer_comm,
                         int remote_leader, int tag, R_MPI_Comm *newintercomm);
int R_MPI_Intercomm_merge(R_MPI_Comm intercomm, int high, R_MPI_Comm *newintracomm);
int R_MPI_Keyval_create(R_MPI_Copy_function *copy_fn, R_MPI_Delete_function *delete_fn,
                      int *keyval, void *extra_state);
int R_MPI_Keyval_free(int *keyval);
int R_MPI_Attr_put(R_MPI_Comm comm, int keyval, void *attribute_val);
int R_MPI_Attr_get(R_MPI_Comm comm, int keyval, void *attribute_val, int *flag);
int R_MPI_Attr_delete(R_MPI_Comm comm, int keyval);
int R_MPI_Topo_test(R_MPI_Comm comm, int *status);
int R_MPI_Cart_create(R_MPI_Comm comm_old, int ndims,  int dims[],  int periods[],
                    int reorder, R_MPI_Comm *comm_cart);
int R_MPI_Dims_create(int nnodes, int ndims, int dims[]);
int R_MPI_Graph_create(R_MPI_Comm comm_old, int nnodes,  int indx[],  int edges[],
                     int reorder, R_MPI_Comm *comm_graph);
int R_MPI_Graphdims_get(R_MPI_Comm comm, int *nnodes, int *nedges);
int R_MPI_Graph_get(R_MPI_Comm comm, int maxindex, int maxedges, int indx[], int edges[]);
int R_MPI_Cartdim_get(R_MPI_Comm comm, int *ndims);
int R_MPI_Cart_get(R_MPI_Comm comm, int maxdims, int dims[], int periods[], int coords[]);
int R_MPI_Cart_rank(R_MPI_Comm comm,  int coords[], int *rank);
int R_MPI_Cart_coords(R_MPI_Comm comm, int rank, int maxdims, int coords[]);
int R_MPI_Graph_neighbors_count(R_MPI_Comm comm, int rank, int *nneighbors);
int R_MPI_Graph_neighbors(R_MPI_Comm comm, int rank, int maxneighbors, int neighbors[]);
int R_MPI_Cart_shift(R_MPI_Comm comm, int direction, int disp, int *rank_source, int *rank_dest);
int R_MPI_Cart_sub(R_MPI_Comm comm,  int remain_dims[], R_MPI_Comm *newcomm);
int R_MPI_Cart_map(R_MPI_Comm comm, int ndims,  int dims[],  int periods[], int *newrank);
int R_MPI_Graph_map(R_MPI_Comm comm, int nnodes,  int indx[],  int edges[], int *newrank);
int R_MPI_Get_processor_name(char *name, int *resultlen);
int R_MPI_Get_version(int *version, int *subversion);
int R_MPI_Get_library_version(char *version, int *resultlen);
int R_MPI_Errhandler_create(R_MPI_Handler_function *function, R_MPI_Errhandler *errhandler);
int R_MPI_Errhandler_set(R_MPI_Comm comm, R_MPI_Errhandler errhandler);
int R_MPI_Errhandler_get(R_MPI_Comm comm, R_MPI_Errhandler *errhandler);
int R_MPI_Errhandler_free(R_MPI_Errhandler *errhandler);
int R_MPI_Error_string(int errorcode, char *string, int *resultlen);
int R_MPI_Error_class(int errorcode, int *errorclass);
double R_MPI_Wtime(void);
double R_MPI_Wtick(void);
int R_MPI_Init(int *argc, char ***argv);
int R_MPI_Finalize(void);
int R_MPI_Initialized(int *flag);
int R_MPI_Abort(R_MPI_Comm comm, int errorcode);

/* Note that we may need to define a @PCONTROL_LIST@ depending on whether
   stdargs are supported */
int R_MPI_Pcontrol( int level, ...);

/* Process Creation and Management */
int R_MPI_Close_port( char *port_name);
int R_MPI_Comm_accept( char *port_name, R_MPI_Info info, int root, R_MPI_Comm comm,
                    R_MPI_Comm *newcomm);
int R_MPI_Comm_connect( char *port_name, R_MPI_Info info, int root, R_MPI_Comm comm,
                     R_MPI_Comm *newcomm);
int R_MPI_Comm_disconnect(R_MPI_Comm *comm);
int R_MPI_Comm_get_parent(R_MPI_Comm *parent);
int R_MPI_Comm_join(int fd, R_MPI_Comm *intercomm);
int R_MPI_Comm_spawn( char *command, char *argv[], int maxprocs, R_MPI_Info info, int root,
                   R_MPI_Comm comm, R_MPI_Comm *intercomm, int array_of_errcodes[]);
int R_MPI_Comm_spawn_multiple(int count, char *array_of_commands[], char **array_of_argv[],
                             int array_of_maxprocs[],  R_MPI_Info array_of_info[],
                            int root, R_MPI_Comm comm, R_MPI_Comm *intercomm, int array_of_errcodes[]);
int R_MPI_Lookup_name( char *service_name, R_MPI_Info info, char *port_name);
int R_MPI_Open_port(R_MPI_Info info, char *port_name);
int R_MPI_Publish_name( char *service_name, R_MPI_Info info,  char *port_name);
int R_MPI_Unpublish_name( char *service_name, R_MPI_Info info,  char *port_name);
int R_MPI_Comm_set_info(R_MPI_Comm comm, R_MPI_Info info);
int R_MPI_Comm_get_info(R_MPI_Comm comm, R_MPI_Info *info);

/* One-Sided Communications */
int R_MPI_Accumulate( void *origin_addr, int origin_count, R_MPI_Datatype origin_datatype,
                   int target_rank, R_MPI_Aint target_disp, int target_count,
                   R_MPI_Datatype target_datatype, R_MPI_Op op, R_MPI_Win win)
                   MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_MPI_Get(void *origin_addr, int origin_count, R_MPI_Datatype origin_datatype,
            int target_rank, R_MPI_Aint target_disp, int target_count,
            R_MPI_Datatype target_datatype, R_MPI_Win win) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_MPI_Put( void *origin_addr, int origin_count, R_MPI_Datatype origin_datatype,
            int target_rank, R_MPI_Aint target_disp, int target_count,
            R_MPI_Datatype target_datatype, R_MPI_Win win) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_MPI_Win_complete(R_MPI_Win win);
int R_MPI_Win_create(void *base, R_MPI_Aint size, int disp_unit, R_MPI_Info info, R_MPI_Comm comm,
                   R_MPI_Win *win);
int R_MPI_Win_fence(int assert, R_MPI_Win win);
int R_MPI_Win_free(R_MPI_Win *win);
int R_MPI_Win_get_group(R_MPI_Win win, R_MPI_Group *group);
int R_MPI_Win_lock(int lock_type, int rank, int assert, R_MPI_Win win);
int R_MPI_Win_post(R_MPI_Group group, int assert, R_MPI_Win win);
int R_MPI_Win_start(R_MPI_Group group, int assert, R_MPI_Win win);
int R_MPI_Win_test(R_MPI_Win win, int *flag);
int R_MPI_Win_unlock(int rank, R_MPI_Win win);
int R_MPI_Win_wait(R_MPI_Win win);

/* MPI-3 One-Sided Communication Routines */
int R_MPI_Win_allocate(R_MPI_Aint size, int disp_unit, R_MPI_Info info, R_MPI_Comm comm, void *baseptr,
                     R_MPI_Win *win);
int R_MPI_Win_allocate_shared(R_MPI_Aint size, int disp_unit, R_MPI_Info info, R_MPI_Comm comm,
                            void *baseptr, R_MPI_Win *win);
int R_MPI_Win_shared_query(R_MPI_Win win, int rank, R_MPI_Aint *size, int *disp_unit, void *baseptr);
int R_MPI_Win_create_dynamic(R_MPI_Info info, R_MPI_Comm comm, R_MPI_Win *win);
int R_MPI_Win_attach(R_MPI_Win win, void *base, R_MPI_Aint size);
int R_MPI_Win_detach(R_MPI_Win win,  void *base);
int R_MPI_Win_get_info(R_MPI_Win win, R_MPI_Info *info_used);
int R_MPI_Win_set_info(R_MPI_Win win, R_MPI_Info info);
int R_MPI_Get_accumulate( void *origin_addr, int origin_count,
                        R_MPI_Datatype origin_datatype, void *result_addr, int result_count,
                        R_MPI_Datatype result_datatype, int target_rank, R_MPI_Aint target_disp,
                        int target_count, R_MPI_Datatype target_datatype, R_MPI_Op op, R_MPI_Win win)
                        MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3)
                        MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int R_MPI_Fetch_and_op( void *origin_addr, void *result_addr,
                      R_MPI_Datatype datatype, int target_rank, R_MPI_Aint target_disp,
                      R_MPI_Op op, R_MPI_Win win)
                      MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_MPI_Compare_and_swap( void *origin_addr,  void *compare_addr,
                          void *result_addr, R_MPI_Datatype datatype, int target_rank,
                          R_MPI_Aint target_disp, R_MPI_Win win)
                          MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4)
                          MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4)
                          MPICH_ATTR_POINTER_WITH_TYPE_TAG(3,4);
int R_MPI_Rput( void *origin_addr, int origin_count,
              R_MPI_Datatype origin_datatype, int target_rank, R_MPI_Aint target_disp,
              int target_count, R_MPI_Datatype target_datatype, R_MPI_Win win,
              R_MPI_Request *request)
              MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_MPI_Rget(void *origin_addr, int origin_count,
              R_MPI_Datatype origin_datatype, int target_rank, R_MPI_Aint target_disp,
              int target_count, R_MPI_Datatype target_datatype, R_MPI_Win win,
              R_MPI_Request *request)
              MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_MPI_Raccumulate( void *origin_addr, int origin_count,
                     R_MPI_Datatype origin_datatype, int target_rank, R_MPI_Aint target_disp,
                     int target_count, R_MPI_Datatype target_datatype, R_MPI_Op op, R_MPI_Win win,
                     R_MPI_Request *request)
                     MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_MPI_Rget_accumulate( void *origin_addr, int origin_count,
                         R_MPI_Datatype origin_datatype, void *result_addr, int result_count,
                         R_MPI_Datatype result_datatype, int target_rank, R_MPI_Aint target_disp,
                         int target_count, R_MPI_Datatype target_datatype, R_MPI_Op op, R_MPI_Win win,
                         R_MPI_Request *request)
                         MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3)
                         MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int R_MPI_Win_lock_all(int assert, R_MPI_Win win);
int R_MPI_Win_unlock_all(R_MPI_Win win);
int R_MPI_Win_flush(int rank, R_MPI_Win win);
int R_MPI_Win_flush_all(R_MPI_Win win);
int R_MPI_Win_flush_local(int rank, R_MPI_Win win);
int R_MPI_Win_flush_local_all(R_MPI_Win win);
int R_MPI_Win_sync(R_MPI_Win win);
 
/* External Interfaces */
int R_MPI_Add_error_class(int *errorclass);
int R_MPI_Add_error_code(int errorclass, int *errorcode);
int R_MPI_Add_error_string(int errorcode,  char *string);
int R_MPI_Comm_call_errhandler(R_MPI_Comm comm, int errorcode);
int R_MPI_Comm_create_keyval(R_MPI_Comm_copy_attr_function *comm_copy_attr_fn,
                           R_MPI_Comm_delete_attr_function *comm_delete_attr_fn, int *comm_keyval,
                           void *extra_state);
int R_MPI_Comm_delete_attr(R_MPI_Comm comm, int comm_keyval);
int R_MPI_Comm_free_keyval(int *comm_keyval);
int R_MPI_Comm_get_attr(R_MPI_Comm comm, int comm_keyval, void *attribute_val, int *flag);
int R_MPI_Comm_get_name(R_MPI_Comm comm, char *comm_name, int *resultlen);
int R_MPI_Comm_set_attr(R_MPI_Comm comm, int comm_keyval, void *attribute_val);
int R_MPI_Comm_set_name(R_MPI_Comm comm,  char *comm_name);
int R_MPI_File_call_errhandler(R_MPI_File fh, int errorcode);
int R_MPI_Grequest_complete(R_MPI_Request request);
int R_MPI_Grequest_start(R_MPI_Grequest_query_function *query_fn, R_MPI_Grequest_free_function *free_fn,
                       R_MPI_Grequest_cancel_function *cancel_fn, void *extra_state,
                       R_MPI_Request *request);
int R_MPI_Init_thread(int *argc, char ***argv, int required, int *provided);
int R_MPI_Is_thread_main(int *flag);
int R_MPI_Query_thread(int *provided);
int R_MPI_Status_set_cancelled(R_MPI_Status *status, int flag);
int R_MPI_Status_set_elements(R_MPI_Status *status, R_MPI_Datatype datatype, int count);
int R_MPI_Type_create_keyval(R_MPI_Type_copy_attr_function *type_copy_attr_fn,
                           R_MPI_Type_delete_attr_function *type_delete_attr_fn,
                           int *type_keyval, void *extra_state);
int R_MPI_Type_delete_attr(R_MPI_Datatype datatype, int type_keyval);
int R_MPI_Type_dup(R_MPI_Datatype oldtype, R_MPI_Datatype *newtype);
int R_MPI_Type_free_keyval(int *type_keyval);
int R_MPI_Type_get_attr(R_MPI_Datatype datatype, int type_keyval, void *attribute_val, int *flag);
int R_MPI_Type_get_contents(R_MPI_Datatype datatype, int max_integers, int max_addresses,
                          int max_datatypes, int array_of_integers[],
                          R_MPI_Aint array_of_addresses[], R_MPI_Datatype array_of_datatypes[]);
int R_MPI_Type_get_envelope(R_MPI_Datatype datatype, int *num_integers, int *num_addresses,
                          int *num_datatypes, int *combiner);
int R_MPI_Type_get_name(R_MPI_Datatype datatype, char *type_name, int *resultlen);
int R_MPI_Type_set_attr(R_MPI_Datatype datatype, int type_keyval, void *attribute_val);
int R_MPI_Type_set_name(R_MPI_Datatype datatype,  char *type_name);
int R_MPI_Type_match_size(int typeclass, int size, R_MPI_Datatype *datatype);
int R_MPI_Win_call_errhandler(R_MPI_Win win, int errorcode);
int R_MPI_Win_create_keyval(R_MPI_Win_copy_attr_function *win_copy_attr_fn,
                          R_MPI_Win_delete_attr_function *win_delete_attr_fn, int *win_keyval,
                          void *extra_state);
int R_MPI_Win_delete_attr(R_MPI_Win win, int win_keyval);
int R_MPI_Win_free_keyval(int *win_keyval);
int R_MPI_Win_get_attr(R_MPI_Win win, int win_keyval, void *attribute_val, int *flag);
int R_MPI_Win_get_name(R_MPI_Win win, char *win_name, int *resultlen);
int R_MPI_Win_set_attr(R_MPI_Win win, int win_keyval, void *attribute_val);
int R_MPI_Win_set_name(R_MPI_Win win,  char *win_name);

int R_MPI_Alloc_mem(R_MPI_Aint size, R_MPI_Info info, void *baseptr);
int R_MPI_Comm_create_errhandler(R_MPI_Comm_errhandler_function *comm_errhandler_fn,
                               R_MPI_Errhandler *errhandler);
int R_MPI_Comm_get_errhandler(R_MPI_Comm comm, R_MPI_Errhandler *errhandler);
int R_MPI_Comm_set_errhandler(R_MPI_Comm comm, R_MPI_Errhandler errhandler);
int R_MPI_File_create_errhandler(R_MPI_File_errhandler_function *file_errhandler_fn,
                               R_MPI_Errhandler *errhandler);
int R_MPI_File_get_errhandler(R_MPI_File file, R_MPI_Errhandler *errhandler);
int R_MPI_File_set_errhandler(R_MPI_File file, R_MPI_Errhandler errhandler);
int R_MPI_Finalized(int *flag);
int R_MPI_Free_mem(void *base);
int R_MPI_Get_address( void *location, R_MPI_Aint *address);
int R_MPI_Info_create(R_MPI_Info *info);
int R_MPI_Info_delete(R_MPI_Info info,  char *key);
int R_MPI_Info_dup(R_MPI_Info info, R_MPI_Info *newinfo);
int R_MPI_Info_free(R_MPI_Info *info);
int R_MPI_Info_get(R_MPI_Info info,  char *key, int valuelen, char *value, int *flag);
int R_MPI_Info_get_nkeys(R_MPI_Info info, int *nkeys);
int R_MPI_Info_get_nthkey(R_MPI_Info info, int n, char *key);
int R_MPI_Info_get_valuelen(R_MPI_Info info,  char *key, int *valuelen, int *flag);
int R_MPI_Info_set(R_MPI_Info info,  char *key,  char *value);
int R_MPI_Pack_external( char datarep[],  void *inbuf, int incount,
                      R_MPI_Datatype datatype, void *outbuf, R_MPI_Aint outsize, R_MPI_Aint *position)
                      MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_MPI_Pack_external_size( char datarep[], int incount, R_MPI_Datatype datatype,
                           R_MPI_Aint *size);
int R_MPI_Request_get_status(R_MPI_Request request, int *flag, R_MPI_Status *status);
int R_MPI_Status_c2f( R_MPI_Status *c_status, R_MPI_Fint *f_status);
int R_MPI_Status_f2c( R_MPI_Fint *f_status, R_MPI_Status *c_status);
int R_MPI_Type_create_darray(int size, int rank, int ndims,  int array_of_gsizes[],
                            int array_of_distribs[],  int array_of_dargs[],
                            int array_of_psizes[], int order, R_MPI_Datatype oldtype,
                           R_MPI_Datatype *newtype);
int R_MPI_Type_create_hindexed(int count,  int array_of_blocklengths[],
                              R_MPI_Aint array_of_displacements[], R_MPI_Datatype oldtype,
                             R_MPI_Datatype *newtype);
int R_MPI_Type_create_hvector(int count, int blocklength, R_MPI_Aint stride, R_MPI_Datatype oldtype,
                            R_MPI_Datatype *newtype);
int R_MPI_Type_create_indexed_block(int count, int blocklength,  int array_of_displacements[],
                                  R_MPI_Datatype oldtype, R_MPI_Datatype *newtype);
int R_MPI_Type_create_hindexed_block(int count, int blocklength,
                                    R_MPI_Aint array_of_displacements[],
                                   R_MPI_Datatype oldtype, R_MPI_Datatype *newtype);
int R_MPI_Type_create_resized(R_MPI_Datatype oldtype, R_MPI_Aint lb, R_MPI_Aint extent,
                            R_MPI_Datatype *newtype);
int R_MPI_Type_create_struct(int count,  int array_of_blocklengths[],
                            R_MPI_Aint array_of_displacements[],
                            R_MPI_Datatype array_of_types[], R_MPI_Datatype *newtype);
int R_MPI_Type_create_subarray(int ndims,  int array_of_sizes[],
                              int array_of_subsizes[],  int array_of_starts[],
                             int order, R_MPI_Datatype oldtype, R_MPI_Datatype *newtype);
int R_MPI_Type_get_extent(R_MPI_Datatype datatype, R_MPI_Aint *lb, R_MPI_Aint *extent);
int R_MPI_Type_get_true_extent(R_MPI_Datatype datatype, R_MPI_Aint *true_lb, R_MPI_Aint *true_extent);
int R_MPI_Unpack_external( char datarep[],  void *inbuf, R_MPI_Aint insize,
                        R_MPI_Aint *position, void *outbuf, int outcount, R_MPI_Datatype datatype)
                        MPICH_ATTR_POINTER_WITH_TYPE_TAG(5,7);
int R_MPI_Win_create_errhandler(R_MPI_Win_errhandler_function *win_errhandler_fn,
                              R_MPI_Errhandler *errhandler);
int R_MPI_Win_get_errhandler(R_MPI_Win win, R_MPI_Errhandler *errhandler);
int R_MPI_Win_set_errhandler(R_MPI_Win win, R_MPI_Errhandler errhandler);

/* Fortran 90-related functions.  These routines are available only if
   Fortran 90 support is enabled 
*/
int R_MPI_Type_create_f90_integer(int range, R_MPI_Datatype *newtype);
int R_MPI_Type_create_f90_real(int precision, int range, R_MPI_Datatype *newtype);
int R_MPI_Type_create_f90_complex(int precision, int range, R_MPI_Datatype *newtype);

int R_MPI_Reduce_local( void *inbuf, void *inoutbuf, int count, R_MPI_Datatype datatype,
                     R_MPI_Op op)
                     MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_MPI_Op_commutative(R_MPI_Op op, int *commute);
int R_MPI_Reduce_scatter_block( void *sendbuf, void *recvbuf, int recvcount,
                             R_MPI_Datatype datatype, R_MPI_Op op, R_MPI_Comm comm)
                             MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4)
                             MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_MPI_Dist_graph_create_adjacent(R_MPI_Comm comm_old, int indegree,  int sources[],
                                    int sourceweights[], int outdegree,
                                    int destinations[],  int destweights[],
                                   R_MPI_Info info, int reorder, R_MPI_Comm *comm_dist_graph);
int R_MPI_Dist_graph_create(R_MPI_Comm comm_old, int n,  int sources[],  int degrees[],
                           int destinations[],  int weights[], R_MPI_Info info,
                          int reorder, R_MPI_Comm *comm_dist_graph);
int R_MPI_Dist_graph_neighbors_count(R_MPI_Comm comm, int *indegree, int *outdegree, int *weighted);
int R_MPI_Dist_graph_neighbors(R_MPI_Comm comm, int maxindegree, int sources[], int sourceweights[],
                             int maxoutdegree, int destinations[], int destweights[]);

/* Matched probe functionality */
int R_MPI_Improbe(int source, int tag, R_MPI_Comm comm, int *flag, R_MPI_Message *message,
                R_MPI_Status *status);
int R_MPI_Imrecv(void *buf, int count, R_MPI_Datatype datatype, R_MPI_Message *message,
               R_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_MPI_Mprobe(int source, int tag, R_MPI_Comm comm, R_MPI_Message *message, R_MPI_Status *status);
int R_MPI_Mrecv(void *buf, int count, R_MPI_Datatype datatype, R_MPI_Message *message,
              R_MPI_Status *status) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);

/* Nonblocking collectives */
int R_MPI_Comm_idup(R_MPI_Comm comm, R_MPI_Comm *newcomm, R_MPI_Request *request);
int R_MPI_Ibarrier(R_MPI_Comm comm, R_MPI_Request *request);
int R_MPI_Ibcast(void *buffer, int count, R_MPI_Datatype datatype, int root, R_MPI_Comm comm,
               R_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_MPI_Igather( void *sendbuf, int sendcount, R_MPI_Datatype sendtype, void *recvbuf,
                int recvcount, R_MPI_Datatype recvtype, int root, R_MPI_Comm comm,
                R_MPI_Request *request)
                MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int R_MPI_Igatherv( void *sendbuf, int sendcount, R_MPI_Datatype sendtype, void *recvbuf,
                  int recvcounts[],  int displs[], R_MPI_Datatype recvtype, int root,
                 R_MPI_Comm comm, R_MPI_Request *request)
                 MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,7);
int R_MPI_Iscatter( void *sendbuf, int sendcount, R_MPI_Datatype sendtype, void *recvbuf,
                 int recvcount, R_MPI_Datatype recvtype, int root, R_MPI_Comm comm,
                 R_MPI_Request *request)
                 MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int R_MPI_Iscatterv( void *sendbuf,  int sendcounts[],  int displs[],
                  R_MPI_Datatype sendtype, void *recvbuf, int recvcount, R_MPI_Datatype recvtype,
                  int root, R_MPI_Comm comm, R_MPI_Request *request)
                  MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(5,7);
int R_MPI_Iallgather( void *sendbuf, int sendcount, R_MPI_Datatype sendtype, void *recvbuf,
                   int recvcount, R_MPI_Datatype recvtype, R_MPI_Comm comm, R_MPI_Request *request)
                   MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int R_MPI_Iallgatherv( void *sendbuf, int sendcount, R_MPI_Datatype sendtype, void *recvbuf,
                     int recvcounts[],  int displs[], R_MPI_Datatype recvtype,
                    R_MPI_Comm comm, R_MPI_Request *request)
                    MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,7);
int R_MPI_Ialltoall( void *sendbuf, int sendcount, R_MPI_Datatype sendtype, void *recvbuf,
                  int recvcount, R_MPI_Datatype recvtype, R_MPI_Comm comm, R_MPI_Request *request)
                  MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int R_MPI_Ialltoallv( void *sendbuf,  int sendcounts[],  int sdispls[],
                   R_MPI_Datatype sendtype, void *recvbuf,  int recvcounts[],
                    int rdispls[], R_MPI_Datatype recvtype, R_MPI_Comm comm,
                   R_MPI_Request *request)
                   MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(5,8);
int R_MPI_Ialltoallw( void *sendbuf,  int sendcounts[],  int sdispls[],
                    R_MPI_Datatype sendtypes[], void *recvbuf,  int recvcounts[],
                    int rdispls[],  R_MPI_Datatype recvtypes[], R_MPI_Comm comm,
                   R_MPI_Request *request);
int R_MPI_Ireduce( void *sendbuf, void *recvbuf, int count, R_MPI_Datatype datatype,
                R_MPI_Op op, int root, R_MPI_Comm comm, R_MPI_Request *request)
                MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_MPI_Iallreduce( void *sendbuf, void *recvbuf, int count, R_MPI_Datatype datatype,
                   R_MPI_Op op, R_MPI_Comm comm, R_MPI_Request *request)
                   MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_MPI_Ireduce_scatter( void *sendbuf, void *recvbuf,  int recvcounts[],
                        R_MPI_Datatype datatype, R_MPI_Op op, R_MPI_Comm comm, R_MPI_Request *request)
                        MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_MPI_Ireduce_scatter_block( void *sendbuf, void *recvbuf, int recvcount,
                              R_MPI_Datatype datatype, R_MPI_Op op, R_MPI_Comm comm,
                              R_MPI_Request *request)
                              MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4)
                              MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_MPI_Iscan( void *sendbuf, void *recvbuf, int count, R_MPI_Datatype datatype, R_MPI_Op op,
              R_MPI_Comm comm, R_MPI_Request *request)
              MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_MPI_Iexscan( void *sendbuf, void *recvbuf, int count, R_MPI_Datatype datatype,
                R_MPI_Op op, R_MPI_Comm comm, R_MPI_Request *request)
                MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);

/* Neighborhood collectives */
int R_MPI_Ineighbor_allgather( void *sendbuf, int sendcount, R_MPI_Datatype sendtype,
                            void *recvbuf, int recvcount, R_MPI_Datatype recvtype,
                            R_MPI_Comm comm, R_MPI_Request *request)
                            MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3)
                            MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int R_MPI_Ineighbor_allgatherv( void *sendbuf, int sendcount, R_MPI_Datatype sendtype,
                             void *recvbuf,  int recvcounts[],  int displs[],
                             R_MPI_Datatype recvtype, R_MPI_Comm comm, R_MPI_Request *request)
                             MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3)
                             MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,7);
int R_MPI_Ineighbor_alltoall( void *sendbuf, int sendcount, R_MPI_Datatype sendtype,
                           void *recvbuf, int recvcount, R_MPI_Datatype recvtype, R_MPI_Comm comm,
                           R_MPI_Request *request)
                           MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3)
                           MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int R_MPI_Ineighbor_alltoallv( void *sendbuf,  int sendcounts[],  int sdispls[],
                            R_MPI_Datatype sendtype, void *recvbuf,  int recvcounts[],
                             int rdispls[], R_MPI_Datatype recvtype, R_MPI_Comm comm,
                            R_MPI_Request *request)
                            MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4)
                            MPICH_ATTR_POINTER_WITH_TYPE_TAG(5,8);
int R_MPI_Ineighbor_alltoallw( void *sendbuf,  int sendcounts[],
                             R_MPI_Aint sdispls[],  R_MPI_Datatype sendtypes[],
                            void *recvbuf,  int recvcounts[],  R_MPI_Aint rdispls[],
                             R_MPI_Datatype recvtypes[], R_MPI_Comm comm, R_MPI_Request *request);
int R_MPI_Neighbor_allgather( void *sendbuf, int sendcount, R_MPI_Datatype sendtype,
                           void *recvbuf, int recvcount, R_MPI_Datatype recvtype, R_MPI_Comm comm)
                           MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3)
                           MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int R_MPI_Neighbor_allgatherv( void *sendbuf, int sendcount, R_MPI_Datatype sendtype,
                            void *recvbuf,  int recvcounts[],  int displs[],
                            R_MPI_Datatype recvtype, R_MPI_Comm comm)
                            MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3)
                            MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,7);
int R_MPI_Neighbor_alltoall( void *sendbuf, int sendcount, R_MPI_Datatype sendtype,
                          void *recvbuf, int recvcount, R_MPI_Datatype recvtype, R_MPI_Comm comm)
                          MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3)
                          MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int R_MPI_Neighbor_alltoallv( void *sendbuf,  int sendcounts[],  int sdispls[],
                           R_MPI_Datatype sendtype, void *recvbuf,  int recvcounts[],
                            int rdispls[], R_MPI_Datatype recvtype, R_MPI_Comm comm)
                           MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4)
                           MPICH_ATTR_POINTER_WITH_TYPE_TAG(5,8);
int R_MPI_Neighbor_alltoallw( void *sendbuf,  int sendcounts[],  R_MPI_Aint sdispls[],
                            R_MPI_Datatype sendtypes[], void *recvbuf,  int recvcounts[],
                            R_MPI_Aint rdispls[],  R_MPI_Datatype recvtypes[], R_MPI_Comm comm);

/* Shared memory */
int R_MPI_Comm_split_type(R_MPI_Comm comm, int split_type, int key, R_MPI_Info info, R_MPI_Comm *newcomm);

/* MPI-3 "large count" routines */
int R_MPI_Get_elements_x( R_MPI_Status *status, R_MPI_Datatype datatype, R_MPI_Count *count);
int R_MPI_Status_set_elements_x(R_MPI_Status *status, R_MPI_Datatype datatype, R_MPI_Count count);
int R_MPI_Type_get_extent_x(R_MPI_Datatype datatype, R_MPI_Count *lb, R_MPI_Count *extent);
int R_MPI_Type_get_true_extent_x(R_MPI_Datatype datatype, R_MPI_Count *lb, R_MPI_Count *extent);
int R_MPI_Type_size_x(R_MPI_Datatype datatype, R_MPI_Count *size);

/* Noncollective communicator creation */
int R_MPI_Comm_create_group(R_MPI_Comm comm, R_MPI_Group group, int tag, R_MPI_Comm *newcomm);


/* Non-standard but public extensions to MPI */
/* Fault Tolerance Extensions */
int MPIX_Comm_group_failed(R_MPI_Comm comm, R_MPI_Group *failed_group);
int MPIX_Comm_remote_group_failed(R_MPI_Comm comm, R_MPI_Group *failed_group);
int MPIX_Comm_reenable_anysource(R_MPI_Comm comm, R_MPI_Group *failed_group);


/* R_MPI_T interface */
/* The R_MPI_T routines are available only in C bindings - tell tools that they
   can skip these prototypes */
/* Begin Skip Prototypes */
int R_MPI_T_init_thread(int required, int *provided);
int R_MPI_T_finalize(void);
int R_MPI_T_enum_get_info(R_MPI_T_enum enumtype, int *num, char *name, int *name_len);
int R_MPI_T_enum_get_item(R_MPI_T_enum enumtype, int indx, int *value, char *name, int *name_len);
int R_MPI_T_cvar_get_num(int *num_cvar);
int R_MPI_T_cvar_get_info(int cvar_index, char *name, int *name_len, int *verbosity,
                        R_MPI_Datatype *datatype, R_MPI_T_enum *enumtype, char *desc, int *desc_len,
                        int *binding, int *scope);
int R_MPI_T_cvar_handle_alloc(int cvar_index, void *obj_handle, R_MPI_T_cvar_handle *handle,
                            int *count);
int R_MPI_T_cvar_handle_free(R_MPI_T_cvar_handle *handle);
int R_MPI_T_cvar_read(R_MPI_T_cvar_handle handle, void *buf);
int R_MPI_T_cvar_write(R_MPI_T_cvar_handle handle,  void *buf);
int R_MPI_T_pvar_get_num(int *num_pvar);
int R_MPI_T_pvar_get_info(int pvar_index, char *name, int *name_len, int *verbosity, int *var_class,
                        R_MPI_Datatype *datatype, R_MPI_T_enum *enumtype, char *desc, int *desc_len,
                        int *binding, int *readonly, int *continuous, int *atomic);
int R_MPI_T_pvar_session_create(R_MPI_T_pvar_session *session);
int R_MPI_T_pvar_session_free(R_MPI_T_pvar_session *session);
int R_MPI_T_pvar_handle_alloc(R_MPI_T_pvar_session session, int pvar_index, void *obj_handle,
                            R_MPI_T_pvar_handle *handle, int *count);
int R_MPI_T_pvar_handle_free(R_MPI_T_pvar_session session, R_MPI_T_pvar_handle *handle);
int R_MPI_T_pvar_start(R_MPI_T_pvar_session session, R_MPI_T_pvar_handle handle);
int R_MPI_T_pvar_stop(R_MPI_T_pvar_session session, R_MPI_T_pvar_handle handle);
int R_MPI_T_pvar_read(R_MPI_T_pvar_session session, R_MPI_T_pvar_handle handle, void *buf);
int R_MPI_T_pvar_write(R_MPI_T_pvar_session session, R_MPI_T_pvar_handle handle,  void *buf);
int R_MPI_T_pvar_reset(R_MPI_T_pvar_session session, R_MPI_T_pvar_handle handle);
int R_MPI_T_pvar_readreset(R_MPI_T_pvar_session session, R_MPI_T_pvar_handle handle, void *buf);
int R_MPI_T_category_get_num(int *num_cat);
int R_MPI_T_category_get_info(int cat_index, char *name, int *name_len, char *desc, int *desc_len,
                            int *num_cvars, int *num_pvars, int *num_categories);
int R_MPI_T_category_get_cvars(int cat_index, int len, int indices[]);
int R_MPI_T_category_get_pvars(int cat_index, int len, int indices[]);
int R_MPI_T_category_get_categories(int cat_index, int len, int indices[]);
int R_MPI_T_category_changed(int *stamp);
/* End Skip Prototypes */
/* End Prototypes */
#endif /* MPICH_SUPPRESS_PROTOTYPES */


/* Here are the bindings of the profiling routines */
#if !defined(R_MPI_BUILD_PROFILING)
int R_PMPISend( void *buf, int count, R_MPI_Datatype datatype, int dest, int tag,
              R_MPI_Comm comm) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_PMPIRecv(void *buf, int count, R_MPI_Datatype datatype, int source, int tag,
              R_MPI_Comm comm, R_MPI_Status *status) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_PMPIGet_count( R_MPI_Status *status, R_MPI_Datatype datatype, int *count);
int R_PMPIBsend( void *buf, int count, R_MPI_Datatype datatype, int dest, int tag,
               R_MPI_Comm comm) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_PMPISsend( void *buf, int count, R_MPI_Datatype datatype, int dest, int tag,
               R_MPI_Comm comm) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_PMPIRsend( void *buf, int count, R_MPI_Datatype datatype, int dest, int tag,
               R_MPI_Comm comm) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_PMPIBuffer_attach(void *buffer, int size);
int R_PMPIBuffer_detach(void *buffer_addr, int *size);
int R_PMPIIsend( void *buf, int count, R_MPI_Datatype datatype, int dest, int tag,
               R_MPI_Comm comm, R_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_PMPIIbsend( void *buf, int count, R_MPI_Datatype datatype, int dest, int tag,
                R_MPI_Comm comm, R_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_PMPIIssend( void *buf, int count, R_MPI_Datatype datatype, int dest, int tag,
                R_MPI_Comm comm, R_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_PMPIIrsend( void *buf, int count, R_MPI_Datatype datatype, int dest, int tag,
                R_MPI_Comm comm, R_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_PMPIIrecv(void *buf, int count, R_MPI_Datatype datatype, int source, int tag,
               R_MPI_Comm comm, R_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_PMPIWait(R_MPI_Request *request, R_MPI_Status *status);
int R_PMPITest(R_MPI_Request *request, int *flag, R_MPI_Status *status);
int R_PMPIRequest_free(R_MPI_Request *request);
int R_PMPIWaitany(int count, R_MPI_Request array_of_requests[], int *indx, R_MPI_Status *status);
int R_PMPITestany(int count, R_MPI_Request array_of_requests[], int *indx, int *flag,
                 R_MPI_Status *status);
int R_PMPIWaitall(int count, R_MPI_Request array_of_requests[], R_MPI_Status array_of_statuses[]);
int R_PMPITestall(int count, R_MPI_Request array_of_requests[], int *flag,
                 R_MPI_Status array_of_statuses[]);
int R_PMPIWaitsome(int incount, R_MPI_Request array_of_requests[], int *outcount,
                  int array_of_indices[], R_MPI_Status array_of_statuses[]);
int R_PMPITestsome(int incount, R_MPI_Request array_of_requests[], int *outcount,
                  int array_of_indices[], R_MPI_Status array_of_statuses[]);
int R_PMPIIprobe(int source, int tag, R_MPI_Comm comm, int *flag, R_MPI_Status *status);
int R_PMPIProbe(int source, int tag, R_MPI_Comm comm, R_MPI_Status *status);
int R_PMPICancel(R_MPI_Request *request);
int R_PMPITest_cancelled( R_MPI_Status *status, int *flag);
int R_PMPISend_init( void *buf, int count, R_MPI_Datatype datatype, int dest, int tag,
                   R_MPI_Comm comm, R_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_PMPIBsend_init( void *buf, int count, R_MPI_Datatype datatype, int dest, int tag,
                    R_MPI_Comm comm, R_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_PMPISsend_init( void *buf, int count, R_MPI_Datatype datatype, int dest, int tag,
                    R_MPI_Comm comm, R_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_PMPIRsend_init( void *buf, int count, R_MPI_Datatype datatype, int dest, int tag,
                    R_MPI_Comm comm, R_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_PMPIRecv_init(void *buf, int count, R_MPI_Datatype datatype, int source, int tag,
                   R_MPI_Comm comm, R_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_PMPIStart(R_MPI_Request *request);
int R_PMPIStartall(int count, R_MPI_Request array_of_requests[]);
int R_PMPISendrecv( void *sendbuf, int sendcount, R_MPI_Datatype sendtype, int dest,
                  int sendtag, void *recvbuf, int recvcount, R_MPI_Datatype recvtype,
                  int source, int recvtag, R_MPI_Comm comm, R_MPI_Status *status)
                  MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3)
                  MPICH_ATTR_POINTER_WITH_TYPE_TAG(6,8);
int R_PMPISendrecv_replace(void *buf, int count, R_MPI_Datatype datatype, int dest,
                          int sendtag, int source, int recvtag, R_MPI_Comm comm,
                          R_MPI_Status *status) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_PMPIType_contiguous(int count, R_MPI_Datatype oldtype, R_MPI_Datatype *newtype);
int R_PMPIType_vector(int count, int blocklength, int stride, R_MPI_Datatype oldtype,
                     R_MPI_Datatype *newtype);
int R_PMPIType_hvector(int count, int blocklength, R_MPI_Aint stride, R_MPI_Datatype oldtype,
                      R_MPI_Datatype *newtype);
int R_PMPIType_indexed(int count,  int *array_of_blocklengths,
                       int *array_of_displacements, R_MPI_Datatype oldtype,
                      R_MPI_Datatype *newtype);
int R_PMPIType_hindexed(int count,  int *array_of_blocklengths,
                        R_MPI_Aint *array_of_displacements, R_MPI_Datatype oldtype,
                       R_MPI_Datatype *newtype);
int R_PMPIType_struct(int count,  int *array_of_blocklengths,
                      R_MPI_Aint *array_of_displacements,
                      R_MPI_Datatype *array_of_types, R_MPI_Datatype *newtype);
int R_PMPIAddress( void *location, R_MPI_Aint *address);
int R_PMPIType_extent(R_MPI_Datatype datatype, R_MPI_Aint *extent);
int R_PMPIType_size(R_MPI_Datatype datatype, int *size);
int R_PMPIType_lb(R_MPI_Datatype datatype, R_MPI_Aint *displacement);
int R_PMPIType_ub(R_MPI_Datatype datatype, R_MPI_Aint *displacement);
int R_PMPIType_commit(R_MPI_Datatype *datatype);
int R_PMPIType_free(R_MPI_Datatype *datatype);
int R_PMPIGet_elements( R_MPI_Status *status, R_MPI_Datatype datatype, int *count);
int R_PMPIPack( void *inbuf, int incount, R_MPI_Datatype datatype, void *outbuf,
              int outsize, int *position, R_MPI_Comm comm) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_PMPIUnpack( void *inbuf, int insize, int *position, void *outbuf, int outcount,
                R_MPI_Datatype datatype, R_MPI_Comm comm) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int R_PMPIPack_size(int incount, R_MPI_Datatype datatype, R_MPI_Comm comm, int *size);
int R_PMPIBarrier(R_MPI_Comm comm);
int R_PMPIBcast(void *buffer, int count, R_MPI_Datatype datatype, int root, R_MPI_Comm comm)
               MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_PMPIGather( void *sendbuf, int sendcount, R_MPI_Datatype sendtype, void *recvbuf,
                int recvcount, R_MPI_Datatype recvtype, int root, R_MPI_Comm comm)
                MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int R_PMPIGatherv( void *sendbuf, int sendcount, R_MPI_Datatype sendtype, void *recvbuf,
                  int *recvcounts,  int *displs, R_MPI_Datatype recvtype, int root,
                 R_MPI_Comm comm)
                 MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,7);
int R_PMPIScatter( void *sendbuf, int sendcount, R_MPI_Datatype sendtype, void *recvbuf,
                 int recvcount, R_MPI_Datatype recvtype, int root, R_MPI_Comm comm)
                 MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int R_PMPIScatterv( void *sendbuf,  int *sendcounts,  int *displs,
                  R_MPI_Datatype sendtype, void *recvbuf, int recvcount, R_MPI_Datatype recvtype,
                  int root, R_MPI_Comm comm)
                  MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(5,7);
int R_PMPIAllgather( void *sendbuf, int sendcount, R_MPI_Datatype sendtype, void *recvbuf,
                   int recvcount, R_MPI_Datatype recvtype, R_MPI_Comm comm)
                   MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int R_PMPIAllgatherv( void *sendbuf, int sendcount, R_MPI_Datatype sendtype, void *recvbuf,
                     int *recvcounts,  int *displs, R_MPI_Datatype recvtype, R_MPI_Comm comm)
                    MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,7);
int R_PMPIAlltoall( void *sendbuf, int sendcount, R_MPI_Datatype sendtype, void *recvbuf,
                  int recvcount, R_MPI_Datatype recvtype, R_MPI_Comm comm)
                  MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int R_PMPIAlltoallv( void *sendbuf,  int *sendcounts,  int *sdispls,
                   R_MPI_Datatype sendtype, void *recvbuf,  int *recvcounts,
                    int *rdispls, R_MPI_Datatype recvtype, R_MPI_Comm comm)
                   MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(5,8);
int R_PMPIAlltoallw( void *sendbuf,  int sendcounts[],  int sdispls[],
                    R_MPI_Datatype sendtypes[], void *recvbuf,  int recvcounts[],
                    int rdispls[],  R_MPI_Datatype recvtypes[], R_MPI_Comm comm);
int R_PMPIExscan( void *sendbuf, void *recvbuf, int count, R_MPI_Datatype datatype,
                R_MPI_Op op, R_MPI_Comm comm)
                MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_PMPIReduce( void *sendbuf, void *recvbuf, int count, R_MPI_Datatype datatype,
                R_MPI_Op op, int root, R_MPI_Comm comm)
                MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_PMPIOp_create(R_MPI_User_function *user_fn, int commute, R_MPI_Op *op);
int R_PMPIOp_free(R_MPI_Op *op);
int R_PMPIAllreduce( void *sendbuf, void *recvbuf, int count, R_MPI_Datatype datatype,
                   R_MPI_Op op, R_MPI_Comm comm)
                   MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_PMPIReduce_scatter( void *sendbuf, void *recvbuf,  int recvcounts[],
                        R_MPI_Datatype datatype, R_MPI_Op op, R_MPI_Comm comm)
                        MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_PMPIScan( void *sendbuf, void *recvbuf, int count, R_MPI_Datatype datatype, R_MPI_Op op,
              R_MPI_Comm comm)
              MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_PMPIGroup_size(R_MPI_Group group, int *size);
int R_PMPIGroup_rank(R_MPI_Group group, int *rank);
int R_PMPIGroup_translate_ranks(R_MPI_Group group1, int n,  int ranks1[], R_MPI_Group group2,
                               int ranks2[]);
int R_PMPIGroup_compare(R_MPI_Group group1, R_MPI_Group group2, int *result);
int R_PMPIComm_group(R_MPI_Comm comm, R_MPI_Group *group);
int R_PMPIGroup_union(R_MPI_Group group1, R_MPI_Group group2, R_MPI_Group *newgroup);
int R_PMPIGroup_intersection(R_MPI_Group group1, R_MPI_Group group2, R_MPI_Group *newgroup);
int R_PMPIGroup_difference(R_MPI_Group group1, R_MPI_Group group2, R_MPI_Group *newgroup);
int R_PMPIGroup_incl(R_MPI_Group group, int n,  int ranks[], R_MPI_Group *newgroup);
int R_PMPIGroup_excl(R_MPI_Group group, int n,  int ranks[], R_MPI_Group *newgroup);
int R_PMPIGroup_range_incl(R_MPI_Group group, int n, int ranges[][3], R_MPI_Group *newgroup);
int R_PMPIGroup_range_excl(R_MPI_Group group, int n, int ranges[][3], R_MPI_Group *newgroup);
int R_PMPIGroup_free(R_MPI_Group *group);
int R_PMPIComm_size(R_MPI_Comm comm, int *size);
int R_PMPIComm_rank(R_MPI_Comm comm, int *rank);
int R_PMPIComm_compare(R_MPI_Comm comm1, R_MPI_Comm comm2, int *result);
int R_PMPIComm_dup(R_MPI_Comm comm, R_MPI_Comm *newcomm);
int R_PMPIComm_dup_with_info(R_MPI_Comm comm, R_MPI_Info info, R_MPI_Comm *newcomm);
int R_PMPIComm_create(R_MPI_Comm comm, R_MPI_Group group, R_MPI_Comm *newcomm);
int R_PMPIComm_split(R_MPI_Comm comm, int color, int key, R_MPI_Comm *newcomm);
int R_PMPIComm_free(R_MPI_Comm *comm);
int R_PMPIComm_test_inter(R_MPI_Comm comm, int *flag);
int R_PMPIComm_remote_size(R_MPI_Comm comm, int *size);
int R_PMPIComm_remote_group(R_MPI_Comm comm, R_MPI_Group *group);
int R_PMPIIntercomm_create(R_MPI_Comm local_comm, int local_leader, R_MPI_Comm peer_comm,
                          int remote_leader, int tag, R_MPI_Comm *newintercomm);
int R_PMPIIntercomm_merge(R_MPI_Comm intercomm, int high, R_MPI_Comm *newintracomm);
int R_PMPIKeyval_create(R_MPI_Copy_function *copy_fn, R_MPI_Delete_function *delete_fn,
                       int *keyval, void *extra_state);
int R_PMPIKeyval_free(int *keyval);
int R_PMPIAttr_put(R_MPI_Comm comm, int keyval, void *attribute_val);
int R_PMPIAttr_get(R_MPI_Comm comm, int keyval, void *attribute_val, int *flag);
int R_PMPIAttr_delete(R_MPI_Comm comm, int keyval);
int R_PMPITopo_test(R_MPI_Comm comm, int *status);
int R_PMPICart_create(R_MPI_Comm comm_old, int ndims,  int dims[],  int periods[],
                     int reorder, R_MPI_Comm *comm_cart);
int R_PMPIDims_create(int nnodes, int ndims, int dims[]);
int R_PMPIGraph_create(R_MPI_Comm comm_old, int nnodes,  int indx[],  int edges[],
                      int reorder, R_MPI_Comm *comm_graph);
int R_PMPIGraphdims_get(R_MPI_Comm comm, int *nnodes, int *nedges);
int R_PMPIGraph_get(R_MPI_Comm comm, int maxindex, int maxedges, int indx[], int edges[]);
int R_PMPICartdim_get(R_MPI_Comm comm, int *ndims);
int R_PMPICart_get(R_MPI_Comm comm, int maxdims, int dims[], int periods[], int coords[]);
int R_PMPICart_rank(R_MPI_Comm comm,  int coords[], int *rank);
int R_PMPICart_coords(R_MPI_Comm comm, int rank, int maxdims, int coords[]);
int R_PMPIGraph_neighbors_count(R_MPI_Comm comm, int rank, int *nneighbors);
int R_PMPIGraph_neighbors(R_MPI_Comm comm, int rank, int maxneighbors, int neighbors[]);
int R_PMPICart_shift(R_MPI_Comm comm, int direction, int disp, int *rank_source, int *rank_dest);
int R_PMPICart_sub(R_MPI_Comm comm,  int remain_dims[], R_MPI_Comm *newcomm);
int R_PMPICart_map(R_MPI_Comm comm, int ndims,  int dims[],  int periods[], int *newrank);
int R_PMPIGraph_map(R_MPI_Comm comm, int nnodes,  int indx[],  int edges[], int *newrank);
int R_PMPIGet_processor_name(char *name, int *resultlen);
int R_PMPIGet_version(int *version, int *subversion);
int R_PMPIGet_library_version(char *version, int *resultlen);
int R_PMPIErrhandler_create(R_MPI_Handler_function *function, R_MPI_Errhandler *errhandler);
int R_PMPIErrhandler_set(R_MPI_Comm comm, R_MPI_Errhandler errhandler);
int R_PMPIErrhandler_get(R_MPI_Comm comm, R_MPI_Errhandler *errhandler);
int R_PMPIErrhandler_free(R_MPI_Errhandler *errhandler);
int R_PMPIError_string(int errorcode, char *string, int *resultlen);
int R_PMPIError_class(int errorcode, int *errorclass);
double R_PMPIWtime(void);
double R_PMPIWtick(void);
int R_PMPIInit(int *argc, char ***argv);
int R_PMPIFinalize(void);
int R_PMPIInitialized(int *flag);
int R_PMPIAbort(R_MPI_Comm comm, int errorcode);

/* Note that we may need to define a @PCONTROL_LIST@ depending on whether
   stdargs are supported */
int R_PMPIPcontrol( int level, ...);

/* Process Creation and Management */
int R_PMPIClose_port( char *port_name);
int R_PMPIComm_accept( char *port_name, R_MPI_Info info, int root, R_MPI_Comm comm,
                     R_MPI_Comm *newcomm);
int R_PMPIComm_connect( char *port_name, R_MPI_Info info, int root, R_MPI_Comm comm,
                      R_MPI_Comm *newcomm);
int R_PMPIComm_disconnect(R_MPI_Comm *comm);
int R_PMPIComm_get_parent(R_MPI_Comm *parent);
int R_PMPIComm_join(int fd, R_MPI_Comm *intercomm);
int R_PMPIComm_spawn( char *command, char *argv[], int maxprocs, R_MPI_Info info, int root,
                    R_MPI_Comm comm, R_MPI_Comm *intercomm, int array_of_errcodes[]);
int R_PMPIComm_spawn_multiple(int count, char *array_of_commands[], char **array_of_argv[],
                              int array_of_maxprocs[],  R_MPI_Info array_of_info[],
                             int root, R_MPI_Comm comm, R_MPI_Comm *intercomm, int array_of_errcodes[]);
int R_PMPILookup_name( char *service_name, R_MPI_Info info, char *port_name);
int R_PMPIOpen_port(R_MPI_Info info, char *port_name);
int R_PMPIPublish_name( char *service_name, R_MPI_Info info,  char *port_name);
int R_PMPIUnpublish_name( char *service_name, R_MPI_Info info,  char *port_name);
int R_PMPIComm_set_info(R_MPI_Comm comm, R_MPI_Info info);
int R_PMPIComm_get_info(R_MPI_Comm comm, R_MPI_Info *info);

/* One-Sided Communications */
int R_PMPIAccumulate( void *origin_addr, int origin_count, R_MPI_Datatype origin_datatype,
                    int target_rank, R_MPI_Aint target_disp, int target_count,
                    R_MPI_Datatype target_datatype, R_MPI_Op op, R_MPI_Win win)
                    MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_PMPIGet(void *origin_addr, int origin_count, R_MPI_Datatype origin_datatype,
             int target_rank, R_MPI_Aint target_disp, int target_count,
             R_MPI_Datatype target_datatype, R_MPI_Win win) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_PMPIPut( void *origin_addr, int origin_count, R_MPI_Datatype origin_datatype,
             int target_rank, R_MPI_Aint target_disp, int target_count,
             R_MPI_Datatype target_datatype, R_MPI_Win win) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_PMPIWin_complete(R_MPI_Win win);
int R_PMPIWin_create(void *base, R_MPI_Aint size, int disp_unit, R_MPI_Info info, R_MPI_Comm comm,
                    R_MPI_Win *win);
int R_PMPIWin_fence(int assert, R_MPI_Win win);
int R_PMPIWin_free(R_MPI_Win *win);
int R_PMPIWin_get_group(R_MPI_Win win, R_MPI_Group *group);
int R_PMPIWin_lock(int lock_type, int rank, int assert, R_MPI_Win win);
int R_PMPIWin_post(R_MPI_Group group, int assert, R_MPI_Win win);
int R_PMPIWin_start(R_MPI_Group group, int assert, R_MPI_Win win);
int R_PMPIWin_test(R_MPI_Win win, int *flag);
int R_PMPIWin_unlock(int rank, R_MPI_Win win);
int R_PMPIWin_wait(R_MPI_Win win);

/* MPI-3 One-Sided Communication Routines */
int R_PMPIWin_allocate(R_MPI_Aint size, int disp_unit, R_MPI_Info info, R_MPI_Comm comm, void *baseptr,
                      R_MPI_Win *win);
int R_PMPIWin_allocate_shared(R_MPI_Aint size, int disp_unit, R_MPI_Info info, R_MPI_Comm comm,
                             void *baseptr, R_MPI_Win *win);
int R_PMPIWin_shared_query(R_MPI_Win win, int rank, R_MPI_Aint *size, int *disp_unit, void *baseptr);
int R_PMPIWin_create_dynamic(R_MPI_Info info, R_MPI_Comm comm, R_MPI_Win *win);
int R_PMPIWin_attach(R_MPI_Win win, void *base, R_MPI_Aint size);
int R_PMPIWin_detach(R_MPI_Win win,  void *base);
int R_PMPIWin_get_info(R_MPI_Win win, R_MPI_Info *info_used);
int R_PMPIWin_set_info(R_MPI_Win win, R_MPI_Info info);
int R_PMPIGet_accumulate( void *origin_addr, int origin_count,
                         R_MPI_Datatype origin_datatype, void *result_addr, int result_count,
                         R_MPI_Datatype result_datatype, int target_rank, R_MPI_Aint target_disp,
                         int target_count, R_MPI_Datatype target_datatype, R_MPI_Op op, R_MPI_Win win)
                         MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3)
                         MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int R_PMPIFetch_and_op( void *origin_addr, void *result_addr,
                       R_MPI_Datatype datatype, int target_rank, R_MPI_Aint target_disp,
                       R_MPI_Op op, R_MPI_Win win)
                       MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_PMPICompare_and_swap( void *origin_addr,  void *compare_addr,
                           void *result_addr, R_MPI_Datatype datatype, int target_rank,
                           R_MPI_Aint target_disp, R_MPI_Win win)
                           MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4)
                           MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4)
                           MPICH_ATTR_POINTER_WITH_TYPE_TAG(3,4);
int R_PMPIRput( void *origin_addr, int origin_count,
               R_MPI_Datatype origin_datatype, int target_rank, R_MPI_Aint target_disp,
               int target_count, R_MPI_Datatype target_datatype, R_MPI_Win win,
               R_MPI_Request *request)
               MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_PMPIRget(void *origin_addr, int origin_count,
               R_MPI_Datatype origin_datatype, int target_rank, R_MPI_Aint target_disp,
               int target_count, R_MPI_Datatype target_datatype, R_MPI_Win win,
               R_MPI_Request *request)
               MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_PMPIRaccumulate( void *origin_addr, int origin_count,
                      R_MPI_Datatype origin_datatype, int target_rank, R_MPI_Aint target_disp,
                      int target_count, R_MPI_Datatype target_datatype, R_MPI_Op op, R_MPI_Win win,
                      R_MPI_Request *request)
                      MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_PMPIRget_accumulate( void *origin_addr, int origin_count,
                          R_MPI_Datatype origin_datatype, void *result_addr, int result_count,
                          R_MPI_Datatype result_datatype, int target_rank, R_MPI_Aint target_disp,
                          int target_count, R_MPI_Datatype target_datatype, R_MPI_Op op, R_MPI_Win win,
                          R_MPI_Request *request)
                          MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3)
                          MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int R_PMPIWin_lock_all(int assert, R_MPI_Win win);
int R_PMPIWin_unlock_all(R_MPI_Win win);
int R_PMPIWin_flush(int rank, R_MPI_Win win);
int R_PMPIWin_flush_all(R_MPI_Win win);
int R_PMPIWin_flush_local(int rank, R_MPI_Win win);
int R_PMPIWin_flush_local_all(R_MPI_Win win);
int R_PMPIWin_sync(R_MPI_Win win);
 
/* External Interfaces */
int R_PMPIAdd_error_class(int *errorclass);
int R_PMPIAdd_error_code(int errorclass, int *errorcode);
int R_PMPIAdd_error_string(int errorcode,  char *string);
int R_PMPIComm_call_errhandler(R_MPI_Comm comm, int errorcode);
int R_PMPIComm_create_keyval(R_MPI_Comm_copy_attr_function *comm_copy_attr_fn,
                            R_MPI_Comm_delete_attr_function *comm_delete_attr_fn, int *comm_keyval,
                            void *extra_state);
int R_PMPIComm_delete_attr(R_MPI_Comm comm, int comm_keyval);
int R_PMPIComm_free_keyval(int *comm_keyval);
int R_PMPIComm_get_attr(R_MPI_Comm comm, int comm_keyval, void *attribute_val, int *flag);
int R_PMPIComm_get_name(R_MPI_Comm comm, char *comm_name, int *resultlen);
int R_PMPIComm_set_attr(R_MPI_Comm comm, int comm_keyval, void *attribute_val);
int R_PMPIComm_set_name(R_MPI_Comm comm,  char *comm_name);
int R_PMPIFile_call_errhandler(R_MPI_File fh, int errorcode);
int R_PMPIGrequest_complete(R_MPI_Request request);
int R_PMPIGrequest_start(R_MPI_Grequest_query_function *query_fn, R_MPI_Grequest_free_function *free_fn,
                        R_MPI_Grequest_cancel_function *cancel_fn, void *extra_state,
                        R_MPI_Request *request);
int R_PMPIInit_thread(int *argc, char ***argv, int required, int *provided);
int R_PMPIIs_thread_main(int *flag);
int R_PMPIQuery_thread(int *provided);
int R_PMPIStatus_set_cancelled(R_MPI_Status *status, int flag);
int R_PMPIStatus_set_elements(R_MPI_Status *status, R_MPI_Datatype datatype, int count);
int R_PMPIType_create_keyval(R_MPI_Type_copy_attr_function *type_copy_attr_fn,
                            R_MPI_Type_delete_attr_function *type_delete_attr_fn,
                            int *type_keyval, void *extra_state);
int R_PMPIType_delete_attr(R_MPI_Datatype datatype, int type_keyval);
int R_PMPIType_dup(R_MPI_Datatype oldtype, R_MPI_Datatype *newtype);
int R_PMPIType_free_keyval(int *type_keyval);
int R_PMPIType_get_attr(R_MPI_Datatype datatype, int type_keyval, void *attribute_val, int *flag);
int R_PMPIType_get_contents(R_MPI_Datatype datatype, int max_integers, int max_addresses,
                           int max_datatypes, int array_of_integers[],
                           R_MPI_Aint array_of_addresses[], R_MPI_Datatype array_of_datatypes[]);
int R_PMPIType_get_envelope(R_MPI_Datatype datatype, int *num_integers, int *num_addresses,
                           int *num_datatypes, int *combiner);
int R_PMPIType_get_name(R_MPI_Datatype datatype, char *type_name, int *resultlen);
int R_PMPIType_set_attr(R_MPI_Datatype datatype, int type_keyval, void *attribute_val);
int R_PMPIType_set_name(R_MPI_Datatype datatype,  char *type_name);
int R_PMPIType_match_size(int typeclass, int size, R_MPI_Datatype *datatype);
int R_PMPIWin_call_errhandler(R_MPI_Win win, int errorcode);
int R_PMPIWin_create_keyval(R_MPI_Win_copy_attr_function *win_copy_attr_fn,
                           R_MPI_Win_delete_attr_function *win_delete_attr_fn, int *win_keyval,
                           void *extra_state);
int R_PMPIWin_delete_attr(R_MPI_Win win, int win_keyval);
int R_PMPIWin_free_keyval(int *win_keyval);
int R_PMPIWin_get_attr(R_MPI_Win win, int win_keyval, void *attribute_val, int *flag);
int R_PMPIWin_get_name(R_MPI_Win win, char *win_name, int *resultlen);
int R_PMPIWin_set_attr(R_MPI_Win win, int win_keyval, void *attribute_val);
int R_PMPIWin_set_name(R_MPI_Win win,  char *win_name);

int R_PMPIAlloc_mem(R_MPI_Aint size, R_MPI_Info info, void *baseptr);
int R_PMPIComm_create_errhandler(R_MPI_Comm_errhandler_function *comm_errhandler_fn,
                                R_MPI_Errhandler *errhandler);
int R_PMPIComm_get_errhandler(R_MPI_Comm comm, R_MPI_Errhandler *errhandler);
int R_PMPIComm_set_errhandler(R_MPI_Comm comm, R_MPI_Errhandler errhandler);
int R_PMPIFile_create_errhandler(R_MPI_File_errhandler_function *file_errhandler_fn,
                                R_MPI_Errhandler *errhandler);
int R_PMPIFile_get_errhandler(R_MPI_File file, R_MPI_Errhandler *errhandler);
int R_PMPIFile_set_errhandler(R_MPI_File file, R_MPI_Errhandler errhandler);
int R_PMPIFinalized(int *flag);
int R_PMPIFree_mem(void *base);
int R_PMPIGet_address( void *location, R_MPI_Aint *address);
int R_PMPIInfo_create(R_MPI_Info *info);
int R_PMPIInfo_delete(R_MPI_Info info,  char *key);
int R_PMPIInfo_dup(R_MPI_Info info, R_MPI_Info *newinfo);
int R_PMPIInfo_free(R_MPI_Info *info);
int R_PMPIInfo_get(R_MPI_Info info,  char *key, int valuelen, char *value, int *flag);
int R_PMPIInfo_get_nkeys(R_MPI_Info info, int *nkeys);
int R_PMPIInfo_get_nthkey(R_MPI_Info info, int n, char *key);
int R_PMPIInfo_get_valuelen(R_MPI_Info info,  char *key, int *valuelen, int *flag);
int R_PMPIInfo_set(R_MPI_Info info,  char *key,  char *value);
int R_PMPIPack_external( char datarep[],  void *inbuf, int incount,
                       R_MPI_Datatype datatype, void *outbuf, R_MPI_Aint outsize, R_MPI_Aint *position)
                       MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_PMPIPack_external_size( char datarep[], int incount, R_MPI_Datatype datatype,
                            R_MPI_Aint *size);
int R_PMPIRequest_get_status(R_MPI_Request request, int *flag, R_MPI_Status *status);
int R_PMPIStatus_c2f( R_MPI_Status *c_status, R_MPI_Fint *f_status);
int R_PMPIStatus_f2c( R_MPI_Fint *f_status, R_MPI_Status *c_status);
int R_PMPIType_create_darray(int size, int rank, int ndims,  int array_of_gsizes[],
                             int array_of_distribs[],  int array_of_dargs[],
                             int array_of_psizes[], int order, R_MPI_Datatype oldtype,
                            R_MPI_Datatype *newtype);
int R_PMPIType_create_hindexed(int count,  int array_of_blocklengths[],
                               R_MPI_Aint array_of_displacements[], R_MPI_Datatype oldtype,
                              R_MPI_Datatype *newtype);
int R_PMPIType_create_hvector(int count, int blocklength, R_MPI_Aint stride, R_MPI_Datatype oldtype,
                             R_MPI_Datatype *newtype);
int R_PMPIType_create_indexed_block(int count, int blocklength,  int array_of_displacements[],
                                   R_MPI_Datatype oldtype, R_MPI_Datatype *newtype);
int R_PMPIType_create_hindexed_block(int count, int blocklength,
                                     R_MPI_Aint array_of_displacements[],
                                    R_MPI_Datatype oldtype, R_MPI_Datatype *newtype);
int R_PMPIType_create_resized(R_MPI_Datatype oldtype, R_MPI_Aint lb, R_MPI_Aint extent,
                             R_MPI_Datatype *newtype);
int R_PMPIType_create_struct(int count,  int array_of_blocklengths[],
                             R_MPI_Aint array_of_displacements[],
                             R_MPI_Datatype array_of_types[], R_MPI_Datatype *newtype);
int R_PMPIType_create_subarray(int ndims,  int array_of_sizes[],
                               int array_of_subsizes[],  int array_of_starts[],
                              int order, R_MPI_Datatype oldtype, R_MPI_Datatype *newtype);
int R_PMPIType_get_extent(R_MPI_Datatype datatype, R_MPI_Aint *lb, R_MPI_Aint *extent);
int R_PMPIType_get_true_extent(R_MPI_Datatype datatype, R_MPI_Aint *true_lb, R_MPI_Aint *true_extent);
int R_PMPIUnpack_external( char datarep[],  void *inbuf, R_MPI_Aint insize,
                         R_MPI_Aint *position, void *outbuf, int outcount, R_MPI_Datatype datatype)
                         MPICH_ATTR_POINTER_WITH_TYPE_TAG(5,7);
int R_PMPIWin_create_errhandler(R_MPI_Win_errhandler_function *win_errhandler_fn,
                               R_MPI_Errhandler *errhandler);
int R_PMPIWin_get_errhandler(R_MPI_Win win, R_MPI_Errhandler *errhandler);
int R_PMPIWin_set_errhandler(R_MPI_Win win, R_MPI_Errhandler errhandler);

/* Fortran 90-related functions.  These routines are available only if
   Fortran 90 support is enabled 
*/
int R_PMPIType_create_f90_integer(int r, R_MPI_Datatype *newtype);
int R_PMPIType_create_f90_real(int p, int r, R_MPI_Datatype *newtype);
int R_PMPIType_create_f90_complex(int p, int r, R_MPI_Datatype *newtype);

int R_PMPIReduce_local( void *inbuf, void *inoutbuf, int count, R_MPI_Datatype datatype,
                      R_MPI_Op op)
                      MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_PMPIOp_commutative(R_MPI_Op op, int *commute);
int R_PMPIReduce_scatter_block( void *sendbuf, void *recvbuf, int recvcount,
                              R_MPI_Datatype datatype, R_MPI_Op op, R_MPI_Comm comm)
                              MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4)
                              MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_PMPIDist_graph_create_adjacent(R_MPI_Comm comm_old, int indegree,  int sources[],
                                     int sourceweights[], int outdegree,
                                     int destinations[],  int destweights[],
                                    R_MPI_Info info, int reorder, R_MPI_Comm *comm_dist_graph);
int R_PMPIDist_graph_create(R_MPI_Comm comm_old, int n,  int sources[],  int degrees[],
                            int destinations[],  int weights[], R_MPI_Info info,
                           int reorder, R_MPI_Comm *comm_dist_graph);
int R_PMPIDist_graph_neighbors_count(R_MPI_Comm comm, int *indegree, int *outdegree, int *weighted);
int R_PMPIDist_graph_neighbors(R_MPI_Comm comm, int maxindegree, int sources[], int sourceweights[],
                              int maxoutdegree, int destinations[], int destweights[]);

/* Matched probe functionality */
int R_PMPIImprobe(int source, int tag, R_MPI_Comm comm, int *flag, R_MPI_Message *message,
                 R_MPI_Status *status);
int R_PMPIImrecv(void *buf, int count, R_MPI_Datatype datatype, R_MPI_Message *message,
                R_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_PMPIMprobe(int source, int tag, R_MPI_Comm comm, R_MPI_Message *message, R_MPI_Status *status);
int R_PMPIMrecv(void *buf, int count, R_MPI_Datatype datatype, R_MPI_Message *message,
               R_MPI_Status *status) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);

/* Nonblocking collectives */
int R_PMPIComm_idup(R_MPI_Comm comm, R_MPI_Comm *newcomm, R_MPI_Request *request);
int R_PMPIIbarrier(R_MPI_Comm comm, R_MPI_Request *request);
int R_PMPIIbcast(void *buffer, int count, R_MPI_Datatype datatype, int root, R_MPI_Comm comm,
                R_MPI_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3);
int R_PMPIIgather( void *sendbuf, int sendcount, R_MPI_Datatype sendtype, void *recvbuf,
                 int recvcount, R_MPI_Datatype recvtype, int root, R_MPI_Comm comm,
                 R_MPI_Request *request)
                 MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int R_PMPIIgatherv( void *sendbuf, int sendcount, R_MPI_Datatype sendtype, void *recvbuf,
                   int recvcounts[],  int displs[], R_MPI_Datatype recvtype, int root,
                  R_MPI_Comm comm, R_MPI_Request *request)
                  MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,7);
int R_PMPIIscatter( void *sendbuf, int sendcount, R_MPI_Datatype sendtype, void *recvbuf,
                  int recvcount, R_MPI_Datatype recvtype, int root, R_MPI_Comm comm,
                  R_MPI_Request *request)
                  MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int R_PMPIIscatterv( void *sendbuf,  int sendcounts[],  int displs[],
                   R_MPI_Datatype sendtype, void *recvbuf, int recvcount, R_MPI_Datatype recvtype,
                   int root, R_MPI_Comm comm, R_MPI_Request *request)
                   MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(5,7);
int R_PMPIIallgather( void *sendbuf, int sendcount, R_MPI_Datatype sendtype, void *recvbuf,
                    int recvcount, R_MPI_Datatype recvtype, R_MPI_Comm comm, R_MPI_Request *request)
                    MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int R_PMPIIallgatherv( void *sendbuf, int sendcount, R_MPI_Datatype sendtype, void *recvbuf,
                      int recvcounts[],  int displs[], R_MPI_Datatype recvtype,
                     R_MPI_Comm comm, R_MPI_Request *request)
                     MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,7);
int R_PMPIIalltoall( void *sendbuf, int sendcount, R_MPI_Datatype sendtype, void *recvbuf,
                   int recvcount, R_MPI_Datatype recvtype, R_MPI_Comm comm, R_MPI_Request *request)
                   MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3) MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int R_PMPIIalltoallv( void *sendbuf,  int sendcounts[],  int sdispls[],
                    R_MPI_Datatype sendtype, void *recvbuf,  int recvcounts[],
                     int rdispls[], R_MPI_Datatype recvtype, R_MPI_Comm comm,
                    R_MPI_Request *request)
                    MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(5,8);
int R_PMPIIalltoallw( void *sendbuf,  int sendcounts[],  int sdispls[],
                     R_MPI_Datatype sendtypes[], void *recvbuf,  int recvcounts[],
                     int rdispls[],  R_MPI_Datatype recvtypes[], R_MPI_Comm comm,
                    R_MPI_Request *request);
int R_PMPIIreduce( void *sendbuf, void *recvbuf, int count, R_MPI_Datatype datatype,
                 R_MPI_Op op, int root, R_MPI_Comm comm, R_MPI_Request *request)
                 MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_PMPIIallreduce( void *sendbuf, void *recvbuf, int count, R_MPI_Datatype datatype,
                    R_MPI_Op op, R_MPI_Comm comm, R_MPI_Request *request)
                    MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_PMPIIreduce_scatter( void *sendbuf, void *recvbuf,  int recvcounts[],
                         R_MPI_Datatype datatype, R_MPI_Op op, R_MPI_Comm comm, R_MPI_Request *request)
                         MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4)
                         MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_PMPIIreduce_scatter_block( void *sendbuf, void *recvbuf, int recvcount,
                               R_MPI_Datatype datatype, R_MPI_Op op, R_MPI_Comm comm,
                               R_MPI_Request *request)
                               MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4)
                               MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_PMPIIscan( void *sendbuf, void *recvbuf, int count, R_MPI_Datatype datatype, R_MPI_Op op,
               R_MPI_Comm comm, R_MPI_Request *request)
               MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_PMPIIexscan( void *sendbuf, void *recvbuf, int count, R_MPI_Datatype datatype,
                 R_MPI_Op op, R_MPI_Comm comm, R_MPI_Request *request)
                 MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);

/* Neighborhood collectives */
int R_PMPIIneighbor_allgather( void *sendbuf, int sendcount, R_MPI_Datatype sendtype,
                             void *recvbuf, int recvcount, R_MPI_Datatype recvtype,
                             R_MPI_Comm comm, R_MPI_Request *request)
                             MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3)
                             MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int R_PMPIIneighbor_allgatherv( void *sendbuf, int sendcount, R_MPI_Datatype sendtype,
                              void *recvbuf,  int recvcounts[],  int displs[],
                              R_MPI_Datatype recvtype, R_MPI_Comm comm, R_MPI_Request *request)
                              MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3)
                              MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,7);
int R_PMPIIneighbor_alltoall( void *sendbuf, int sendcount, R_MPI_Datatype sendtype,
                            void *recvbuf, int recvcount, R_MPI_Datatype recvtype, R_MPI_Comm comm,
                            R_MPI_Request *request)
                            MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3)
                            MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int R_PMPIIneighbor_alltoallv( void *sendbuf,  int sendcounts[],  int sdispls[],
                             R_MPI_Datatype sendtype, void *recvbuf,  int recvcounts[],
                              int rdispls[], R_MPI_Datatype recvtype, R_MPI_Comm comm,
                             R_MPI_Request *request)
                             MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4)
                             MPICH_ATTR_POINTER_WITH_TYPE_TAG(5,8);
int R_PMPIIneighbor_alltoallw( void *sendbuf,  int sendcounts[],
                              R_MPI_Aint sdispls[],  R_MPI_Datatype sendtypes[],
                             void *recvbuf,  int recvcounts[],  R_MPI_Aint rdispls[],
                              R_MPI_Datatype recvtypes[], R_MPI_Comm comm, R_MPI_Request *request);
int R_PMPINeighbor_allgather( void *sendbuf, int sendcount, R_MPI_Datatype sendtype,
                            void *recvbuf, int recvcount, R_MPI_Datatype recvtype, R_MPI_Comm comm)
                            MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3)
                            MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int R_PMPINeighbor_allgatherv( void *sendbuf, int sendcount, R_MPI_Datatype sendtype,
                             void *recvbuf,  int recvcounts[],  int displs[],
                             R_MPI_Datatype recvtype, R_MPI_Comm comm)
                             MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3)
                             MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,7);
int R_PMPINeighbor_alltoall( void *sendbuf, int sendcount, R_MPI_Datatype sendtype,
                           void *recvbuf, int recvcount, R_MPI_Datatype recvtype, R_MPI_Comm comm)
                           MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,3)
                           MPICH_ATTR_POINTER_WITH_TYPE_TAG(4,6);
int R_PMPINeighbor_alltoallv( void *sendbuf,  int sendcounts[],  int sdispls[],
                            R_MPI_Datatype sendtype, void *recvbuf,  int recvcounts[],
                             int rdispls[], R_MPI_Datatype recvtype, R_MPI_Comm comm)
                            MPICH_ATTR_POINTER_WITH_TYPE_TAG(1,4)
                            MPICH_ATTR_POINTER_WITH_TYPE_TAG(5,8);
int R_PMPINeighbor_alltoallw( void *sendbuf,  int sendcounts[],  R_MPI_Aint sdispls[],
                             R_MPI_Datatype sendtypes[], void *recvbuf,  int recvcounts[],
                             R_MPI_Aint rdispls[],  R_MPI_Datatype recvtypes[],
                            R_MPI_Comm comm);

/* Shared memory */
int R_PMPIComm_split_type(R_MPI_Comm comm, int split_type, int key, R_MPI_Info info, R_MPI_Comm *newcomm);

/* Noncollective communicator creation */
int R_PMPIComm_create_group(R_MPI_Comm comm, R_MPI_Group group, int tag, R_MPI_Comm *newcomm);

/* MPI-3 "large count" routines */
int R_PMPIGet_elements_x( R_MPI_Status *status, R_MPI_Datatype datatype, R_MPI_Count *count);
int R_PMPIStatus_set_elements_x(R_MPI_Status *status, R_MPI_Datatype datatype, R_MPI_Count count);
int R_PMPIType_get_extent_x(R_MPI_Datatype datatype, R_MPI_Count *lb, R_MPI_Count *extent);
int R_PMPIType_get_true_extent_x(R_MPI_Datatype datatype, R_MPI_Count *lb, R_MPI_Count *extent);
int R_PMPIType_size_x(R_MPI_Datatype datatype, R_MPI_Count *size);

/* Non-standard but public extensions to MPI */
/* Fault Tolerance Extensions */
int PMPIX_Comm_group_failed(R_MPI_Comm comm, R_MPI_Group *failed_group);
int PMPIX_Comm_remote_group_failed(R_MPI_Comm comm, R_MPI_Group *failed_group);
int PMPIX_Comm_reenable_anysource(R_MPI_Comm comm, R_MPI_Group *failed_group);


/* R_MPI_T interface */
/* The R_MPI_T routines are available only in C bindings - tell tools that they
   can skip these prototypes */
/* Begin Skip Prototypes */
int R_PMPIT_init_thread(int required, int *provided);
int R_PMPIT_finalize(void);
int R_PMPIT_enum_get_info(R_MPI_T_enum enumtype, int *num, char *name, int *name_len);
int R_PMPIT_enum_get_item(R_MPI_T_enum enumtype, int indx, int *value, char *name, int *name_len);
int R_PMPIT_cvar_get_num(int *num_cvar);
int R_PMPIT_cvar_get_info(int cvar_index, char *name, int *name_len, int *verbosity,
                         R_MPI_Datatype *datatype, R_MPI_T_enum *enumtype, char *desc, int *desc_len,
                         int *binding, int *scope);
int R_PMPIT_cvar_handle_alloc(int cvar_index, void *obj_handle, R_MPI_T_cvar_handle *handle,
                             int *count);
int R_PMPIT_cvar_handle_free(R_MPI_T_cvar_handle *handle);
int R_PMPIT_cvar_read(R_MPI_T_cvar_handle handle, void *buf);
int R_PMPIT_cvar_write(R_MPI_T_cvar_handle handle,  void *buf);
int R_PMPIT_pvar_get_num(int *num_pvar);
int R_PMPIT_pvar_get_info(int pvar_index, char *name, int *name_len, int *verbosity, int *var_class,
                         R_MPI_Datatype *datatype, R_MPI_T_enum *enumtype, char *desc, int *desc_len,
                         int *binding, int *readonly, int *continuous, int *atomic);
int R_PMPIT_pvar_session_create(R_MPI_T_pvar_session *session);
int R_PMPIT_pvar_session_free(R_MPI_T_pvar_session *session);
int R_PMPIT_pvar_handle_alloc(R_MPI_T_pvar_session session, int pvar_index, void *obj_handle,
                             R_MPI_T_pvar_handle *handle, int *count);
int R_PMPIT_pvar_handle_free(R_MPI_T_pvar_session session, R_MPI_T_pvar_handle *handle);
int R_PMPIT_pvar_start(R_MPI_T_pvar_session session, R_MPI_T_pvar_handle handle);
int R_PMPIT_pvar_stop(R_MPI_T_pvar_session session, R_MPI_T_pvar_handle handle);
int R_PMPIT_pvar_read(R_MPI_T_pvar_session session, R_MPI_T_pvar_handle handle, void *buf);
int R_PMPIT_pvar_write(R_MPI_T_pvar_session session, R_MPI_T_pvar_handle handle,  void *buf);
int R_PMPIT_pvar_reset(R_MPI_T_pvar_session session, R_MPI_T_pvar_handle handle);
int R_PMPIT_pvar_readreset(R_MPI_T_pvar_session session, R_MPI_T_pvar_handle handle, void *buf);
int R_PMPIT_category_get_num(int *num_cat);
int R_PMPIT_category_get_info(int cat_index, char *name, int *name_len, char *desc, int *desc_len,
                             int *num_cvars, int *num_pvars, int *num_categories);
int R_PMPIT_category_get_cvars(int cat_index, int len, int indices[]);
int R_PMPIT_category_get_pvars(int cat_index, int len, int indices[]);
int R_PMPIT_category_get_categories(int cat_index, int len, int indices[]);
int R_PMPIT_category_changed(int *stamp);
/* End Skip Prototypes */
#endif  /* R_MPI_BUILD_PROFILING */
/* End of MPI bindings */

/* feature advertisement */
#define MPIIMPL_ADVERTISES_FEATURES 1
#define MPIIMPL_HAVE_R_MPI_INFO 1                                                 
#define MPIIMPL_HAVE_R_MPI_COMBINER_DARRAY 1                                      
#define MPIIMPL_HAVE_R_MPI_TYPE_CREATE_DARRAY 1
#define MPIIMPL_HAVE_R_MPI_COMBINER_SUBARRAY 1                                    
#define MPIIMPL_HAVE_R_MPI_TYPE_CREATE_DARRAY 1
#define MPIIMPL_HAVE_R_MPI_COMBINER_DUP 1                                         
#define MPIIMPL_HAVE_R_MPI_GREQUEST 1      
#define MPIIMPL_HAVE_STATUS_SET_BYTES 1
#define MPIIMPL_HAVE_STATUS_SET_INFO 1

#include "run_mpio.h"

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
int R_MPIX_Grequest_class_create(R_MPI_Grequest_query_function *query_fn,
                               R_MPI_Grequest_free_function *free_fn,
                               R_MPI_Grequest_cancel_function *cancel_fn,
                               R_MPIX_Grequest_poll_function *poll_fn,
                               R_MPIX_Grequest_wait_function *wait_fn,
                               MPIX_Grequest_class *greq_class);
int R_MPIX_Grequest_class_allocate(MPIX_Grequest_class greq_class, void *extra_state,
                                 R_MPI_Request *request);
int R_MPIX_Grequest_start(R_MPI_Grequest_query_function *query_fn,
                        R_MPI_Grequest_free_function *free_fn,
                        R_MPI_Grequest_cancel_function *cancel_fn,
                        R_MPIX_Grequest_poll_function *poll_fn,
                        R_MPIX_Grequest_wait_function *wait_fn, void *extra_state,
                        R_MPI_Request *request);

/* RMA Mutexes Extensions */
struct mpixi_mutex_s;
typedef struct mpixi_mutex_s * MPIX_Mutex;
int MPIX_Mutex_create(int count, R_MPI_Comm comm, MPIX_Mutex *hdl);
int MPIX_Mutex_free(MPIX_Mutex *hdl);
int MPIX_Mutex_lock(MPIX_Mutex hdl, int mutex, int proc);
int MPIX_Mutex_unlock(MPIX_Mutex hdl, int mutex, int proc);


#if !defined(R_MPI_BUILD_PROFILING)
/* Generalized requests extensions */
int R_PMPIX_Grequest_class_create(R_MPI_Grequest_query_function *query_fn,
                                R_MPI_Grequest_free_function *free_fn,
                                R_MPI_Grequest_cancel_function *cancel_fn,
                                R_MPIX_Grequest_poll_function *poll_fn,
                                R_MPIX_Grequest_wait_function *wait_fn,
                                MPIX_Grequest_class *greq_class);
int R_PMPIX_Grequest_class_allocate(MPIX_Grequest_class greq_class, void *extra_state,
                                  R_MPI_Request *request);
int R_PMPIX_Grequest_start(R_MPI_Grequest_query_function *query_fn,
                         R_MPI_Grequest_free_function *free_fn,
                         R_MPI_Grequest_cancel_function *cancel_fn,
                         R_MPIX_Grequest_poll_function *poll_fn,
                         R_MPIX_Grequest_wait_function *wait_fn, void *extra_state,
                         R_MPI_Request *request);

/* RMA Mutexes Extensions */
int R_PMPIX_Mutex_create(int count, R_MPI_Comm comm, MPIX_Mutex *hdl);
int R_PMPIX_Mutex_free(MPIX_Mutex *hdl);
int R_PMPIX_Mutex_lock(MPIX_Mutex hdl, int mutex, int proc);
int R_PMPIX_Mutex_unlock(MPIX_Mutex hdl, int mutex, int proc);
#endif /* R_MPI_BUILD_PROFILING */

#endif

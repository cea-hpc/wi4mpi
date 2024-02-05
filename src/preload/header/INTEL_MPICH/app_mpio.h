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
 *
 *   Copyright (C) 1997 University of Chicago.

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

/* user include file for MPI-IO programs */

#ifndef A_MPIO_INCLUDE
#define A_MPIO_INCLUDE

#include "app_mpi.h"

#if defined(__cplusplus)
extern "C" {
#endif

#define ROMIO_VERSION 126 /* version 1.2.6 */

/* define MPI-IO datatypes and ants */

#ifndef A_MPI_FILE_DEFINED
typedef struct ADIOI_FileD *A_MPI_File;
#endif

#define HAVE_A_MPI_GREQUEST 1
#ifndef HAVE_A_MPI_GREQUEST
typedef struct ADIOI_RequestD *MPIO_Request;  
#else
#define MPIO_Request A_MPI_Request
#define MPIO_USES_A_MPI_REQUEST
#endif
#define MPIO_REQUEST_DEFINED

#ifndef HAVE_A_MPI_OFFSET
typedef long long A_MPI_Offset;
/* If we needed to define A_MPI_Offset, then we also need to make
   this definition. */
#ifndef HAVE_A_MPI_DATAREP_FUNCTIONS
#define HAVE_A_MPI_DATAREP_FUNCTIONS
typedef int (A_MPI_Datarep_conversion_function)(void *, A_MPI_Datatype, int, 
             void *, A_MPI_Offset, void *);
typedef int (A_MPI_Datarep_extent_function)(A_MPI_Datatype datatype, A_MPI_Aint *,
					  void *);
#endif
#endif

#ifndef NEEDS_A_MPI_FINT

#endif
#ifdef NEEDS_A_MPI_FINT
typedef int A_MPI_Fint; 
#endif

#ifndef HAVE_A_MPI_INFO
#define HAVE_A_MPI_INFO
#endif
#ifndef HAVE_A_MPI_INFO
  typedef struct MPIR_Info *A_MPI_Info;
# define A_MPI_INFO_NULL         ((A_MPI_Info) 0)
# define A_MPI_MAX_INFO_KEY       255
# define A_MPI_MAX_INFO_VAL      1024
#endif

#define A_MPI_MODE_RDONLY              2  /* ADIO_RDONLY */
#define A_MPI_MODE_RDWR                8  /* ADIO_RDWR  */
#define A_MPI_MODE_WRONLY              4  /* ADIO_WRONLY  */
#define A_MPI_MODE_CREATE              1  /* ADIO_CREATE */ 
#define A_MPI_MODE_EXCL               64  /* ADIO_EXCL */
#define A_MPI_MODE_DELETE_ON_CLOSE    16  /* ADIO_DELETE_ON_CLOSE */
#define A_MPI_MODE_UNIQUE_OPEN        32  /* ADIO_UNIQUE_OPEN */
#define A_MPI_MODE_APPEND            128  /* ADIO_APPEND */
#define A_MPI_MODE_SEQUENTIAL        256  /* ADIO_SEQUENTIAL */

#define A_MPI_DISPLACEMENT_CURRENT   -54278278

#ifndef MPICH
/* FIXME: Make sure that we get a consistent definition of A_MPI_FILE_NULL
	in MPICH */
/* MPICH defines null object handles differently */
#define A_MPI_FILE_NULL           ((A_MPI_File) 0)
#endif
#define MPIO_REQUEST_NULL       ((MPIO_Request) 0)

#define A_MPI_SEEK_SET            600
#define A_MPI_SEEK_CUR            602
#define A_MPI_SEEK_END            604

/* Open MPI: don't define A_MPI_MAX_DATAREP_STRING here; it's defined in
   OMPI's mpi.h. */
#ifndef OPEN_MPI
#define A_MPI_MAX_DATAREP_STRING  128
#endif

#ifndef HAVE_A_MPI_DARRAY_SUBARRAY
#define HAVE_A_MPI_DARRAY_SUBARRAY
#endif
#ifndef HAVE_A_MPI_DARRAY_SUBARRAY
#  define A_MPI_ORDER_C             56
#  define A_MPI_ORDER_FORTRAN       57
#  define A_MPI_DISTRIBUTE_BLOCK    121
#  define A_MPI_DISTRIBUTE_CYCLIC   122
#  define A_MPI_DISTRIBUTE_NONE     123
#  define A_MPI_DISTRIBUTE_DFLT_DARG -49767
#endif


/* MPI-IO function prototypes */

/* The compiler must support ANSI C style prototypes, otherwise 
   long long ants (e.g. 0) may get passed as ints. */

#ifndef HAVE_PRAGMA_HP_SEC_DEF

/* Section 9.2 */
/* Begin Prototypes */
int A_MPI_File_open(A_MPI_Comm comm,  char *filename, int amode, A_MPI_Info info, A_MPI_File *fh);
int A_MPI_File_close(A_MPI_File *fh);
int A_MPI_File_delete( char *filename, A_MPI_Info info);
int A_MPI_File_set_size(A_MPI_File fh, A_MPI_Offset size);
int A_MPI_File_preallocate(A_MPI_File fh, A_MPI_Offset size);
int A_MPI_File_get_size(A_MPI_File fh, A_MPI_Offset *size);
int A_MPI_File_get_group(A_MPI_File fh, A_MPI_Group *group);
int A_MPI_File_get_amode(A_MPI_File fh, int *amode);
int A_MPI_File_set_info(A_MPI_File fh, A_MPI_Info info);
int A_MPI_File_get_info(A_MPI_File fh, A_MPI_Info *info_used);

/* Section 9.3 */
int A_MPI_File_set_view(A_MPI_File fh, A_MPI_Offset disp, A_MPI_Datatype etype, A_MPI_Datatype filetype,
                       char *datarep, A_MPI_Info info);
int A_MPI_File_get_view(A_MPI_File fh, A_MPI_Offset *disp, A_MPI_Datatype *etype, A_MPI_Datatype *filetype,
                      char *datarep);

/* Section 9.4.2 */
int A_MPI_File_read_at(A_MPI_File fh, A_MPI_Offset offset, void *buf, int count, A_MPI_Datatype datatype,
                     A_MPI_Status *status) MPICH_ATTR_POINTER_WITH_TYPE_TAG(3,5);
int A_MPI_File_read_at_all(A_MPI_File fh, A_MPI_Offset offset, void * buf, int count,
                         A_MPI_Datatype datatype, A_MPI_Status *status)
    MPICH_ATTR_POINTER_WITH_TYPE_TAG(3,5);
int A_MPI_File_write_at(A_MPI_File fh, A_MPI_Offset offset,  void * buf, int count,
                      A_MPI_Datatype datatype, A_MPI_Status *status)
    MPICH_ATTR_POINTER_WITH_TYPE_TAG(3,5);
int A_MPI_File_write_at_all(A_MPI_File fh, A_MPI_Offset offset,  void *buf, int count,
                          A_MPI_Datatype datatype, A_MPI_Status *status)
    MPICH_ATTR_POINTER_WITH_TYPE_TAG(3,5);

/* nonblocking calls currently use MPIO_Request, because generalized
   requests not yet implemented. For the same reason, MPIO_Test and 
   MPIO_Wait are used to test and wait on nonblocking I/O requests */ 
int A_MPI_File_iread_at(A_MPI_File fh, A_MPI_Offset offset, void *buf, int count, A_MPI_Datatype datatype,
                      MPIO_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(3,5);
int A_MPI_File_iwrite_at(A_MPI_File fh, A_MPI_Offset offset,  void *buf, int count,
                       A_MPI_Datatype datatype, MPIO_Request *request)
    MPICH_ATTR_POINTER_WITH_TYPE_TAG(3,5);

/* Section 9.4.3 */
int A_MPI_File_read(A_MPI_File fh, void *buf, int count, A_MPI_Datatype datatype, A_MPI_Status *status)
    MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_MPI_File_read_all(A_MPI_File fh, void *buf, int count, A_MPI_Datatype datatype, A_MPI_Status *status)
    MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_MPI_File_write(A_MPI_File fh,  void *buf, int count, A_MPI_Datatype datatype,
                   A_MPI_Status *status) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_MPI_File_write_all(A_MPI_File fh,  void *buf, int count, A_MPI_Datatype datatype,
                       A_MPI_Status *status) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);

/* nonblocking calls currently use MPIO_Request, because generalized
   requests not yet implemented. For the same reason, MPIO_Test and 
   MPIO_Wait are used to test and wait on nonblocking I/O requests */ 

int A_MPI_File_iread(A_MPI_File fh, void *buf, int count, A_MPI_Datatype datatype, MPIO_Request *request)
    MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_MPI_File_iwrite(A_MPI_File fh,  void *buf, int count, A_MPI_Datatype datatype,
                    MPIO_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);

int A_MPI_File_seek(A_MPI_File fh, A_MPI_Offset offset, int whence);
int A_MPI_File_get_position(A_MPI_File fh, A_MPI_Offset *offset);
int A_MPI_File_get_byte_offset(A_MPI_File fh, A_MPI_Offset offset, A_MPI_Offset *disp);

/* Section 9.4.4 */
int A_MPI_File_read_shared(A_MPI_File fh, void *buf, int count, A_MPI_Datatype datatype,
                         A_MPI_Status *status) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_MPI_File_write_shared(A_MPI_File fh,  void *buf, int count, A_MPI_Datatype datatype,
                          A_MPI_Status *status) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_MPI_File_iread_shared(A_MPI_File fh, void *buf, int count, A_MPI_Datatype datatype,
                          MPIO_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_MPI_File_iwrite_shared(A_MPI_File fh,  void *buf, int count, A_MPI_Datatype datatype,
                           MPIO_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_MPI_File_read_ordered(A_MPI_File fh, void *buf, int count, A_MPI_Datatype datatype,
                          A_MPI_Status *status) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_MPI_File_write_ordered(A_MPI_File fh,  void *buf, int count, A_MPI_Datatype datatype,
                           A_MPI_Status *status) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_MPI_File_seek_shared(A_MPI_File fh, A_MPI_Offset offset, int whence);
int A_MPI_File_get_position_shared(A_MPI_File fh, A_MPI_Offset *offset);

/* Section 9.4.5 */
int A_MPI_File_read_at_all_begin(A_MPI_File fh, A_MPI_Offset offset, void *buf, int count,
                               A_MPI_Datatype datatype) MPICH_ATTR_POINTER_WITH_TYPE_TAG(3,5);
int A_MPI_File_read_at_all_end(A_MPI_File fh, void *buf, A_MPI_Status *status);
int A_MPI_File_write_at_all_begin(A_MPI_File fh, A_MPI_Offset offset,  void *buf, int count,
                                A_MPI_Datatype datatype) MPICH_ATTR_POINTER_WITH_TYPE_TAG(3,5);
int A_MPI_File_write_at_all_end(A_MPI_File fh,  void *buf, A_MPI_Status *status);
int A_MPI_File_read_all_begin(A_MPI_File fh, void *buf, int count, A_MPI_Datatype datatype)
    MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_MPI_File_read_all_end(A_MPI_File fh, void *buf, A_MPI_Status *status);
int A_MPI_File_write_all_begin(A_MPI_File fh,  void *buf, int count, A_MPI_Datatype datatype)
    MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_MPI_File_write_all_end(A_MPI_File fh,  void *buf, A_MPI_Status *status);
int A_MPI_File_read_ordered_begin(A_MPI_File fh, void *buf, int count, A_MPI_Datatype datatype)
    MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_MPI_File_read_ordered_end(A_MPI_File fh, void *buf, A_MPI_Status *status);
int A_MPI_File_write_ordered_begin(A_MPI_File fh,  void *buf, int count, A_MPI_Datatype datatype)
    MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_MPI_File_write_ordered_end(A_MPI_File fh,  void *buf, A_MPI_Status *status);

/* Section 9.5.1 */
int A_MPI_File_get_type_extent(A_MPI_File fh, A_MPI_Datatype datatype, A_MPI_Aint *extent);

/* Section 9.5.3 */
int A_MPI_Register_datarep( char *datarep, A_MPI_Datarep_conversion_function *read_conversion_fn,
			 A_MPI_Datarep_conversion_function *write_conversion_fn,
			 A_MPI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state);

/* Section 9.6.1 */
int A_MPI_File_set_atomicity(A_MPI_File fh, int flag);
int A_MPI_File_get_atomicity(A_MPI_File fh, int *flag);
int A_MPI_File_sync(A_MPI_File fh);

/* Section 4.13.3 */
#ifndef MPICH
/* MPICH provides these definitions */
int A_MPI_File_set_errhandler(A_MPI_File file, A_MPI_Errhandler errhandler);
int A_MPI_File_get_errhandler(A_MPI_File file, A_MPI_Errhandler *errhandler);
#endif
/* End Prototypes */

#ifndef HAVE_A_MPI_DARRAY_SUBARRAY
/* Section 4.14.4 */
int A_MPI_Type_create_subarray(int ndims,  int array_of_sizes[],  int array_of_subsizes[],
                              int array_of_starts[], int order, A_MPI_Datatype oldtype,
                             A_MPI_Datatype *newtype);

/* Section 4.14.5 */
int A_MPI_Type_create_darray(int size, int rank, int ndims,  int array_of_gsizes[],
                            int array_of_distribs[],  int array_of_dargs[],
                            int array_of_psizes, int order, A_MPI_Datatype oldtype,
                           A_MPI_Datatype *newtype);
#endif

/* The globus2 device has to rename A_MPI_ symbols in order to use the vendor
   MPI as one of its transport mechanisms.  Therefore, the following undefines
   should only happen if MPICH_RENAMING_A_MPI_FUNCS is not defined. */
/* Section 4.12.4 */
#if !defined(MPICH_RENAMING_A_MPI_FUNCS)
#ifdef A_MPI_File_f2c
#undef A_MPI_File_f2c
#endif
#ifdef A_MPI_File_c2f
#undef A_MPI_File_c2f
#endif
#endif
/* above needed for some versions of mpi.h in MPICH!! */
A_MPI_File A_MPI_File_f2c(A_MPI_Fint file);
A_MPI_Fint A_MPI_File_c2f(A_MPI_File file);


#ifndef HAVE_A_MPI_GREQUEST
/* The following functions are required if generalized requests are not
   available, because in that case, an MPIO_Request object
   is currently used for nonblocking I/O. */
int MPIO_Test(MPIO_Request *request, int *flag, A_MPI_Status *status);
int MPIO_Wait(MPIO_Request *request, A_MPI_Status *status);
int MPIO_Testall(int count, MPIO_Request array_of_requests[], int *flag,
                 A_MPI_Status array_of_statuses[]);
int MPIO_Waitall(int count, MPIO_Request array_of_requests[], A_MPI_Status array_of_statuses[]);
int MPIO_Testany(int count, MPIO_Request array_of_requests[], int *indx, int *flag,
                 A_MPI_Status *status);
int MPIO_Waitany(int count, MPIO_Request array_of_requests[], int *indx, A_MPI_Status *status);
int MPIO_Waitsome(int incount, MPIO_Request array_of_requests[], int *outcount,
                  int array_of_indices[], A_MPI_Status array_of_statuses[]);
int MPIO_Testsome(int incount, MPIO_Request array_of_requests[], int *outcount,
                  int array_of_indices[], A_MPI_Status array_of_statuses[]);

A_MPI_Fint MPIO_Request_c2f(MPIO_Request request);
MPIO_Request MPIO_Request_f2c(A_MPI_Fint request);
#endif /* HAVE_A_MPI_GREQUEST */

/* info functions if not defined in the MPI implementation */
#ifndef HAVE_A_MPI_INFO

int A_MPI_Info_create(A_MPI_Info *info);
int A_MPI_Info_set(A_MPI_Info info,  char *key,  char *value);
int A_MPI_Info_delete(A_MPI_Info info,  char *key);
int A_MPI_Info_get(A_MPI_Info info,  char *key, int valuelen, char *value, int *flag);
int A_MPI_Info_get_valuelen(A_MPI_Info info,  char *key, int *valuelen, int *flag);
int A_MPI_Info_get_nkeys(A_MPI_Info info, int *nkeys);
int A_MPI_Info_get_nthkey(A_MPI_Info info, int n, char *key);
int A_MPI_Info_dup(A_MPI_Info info, A_MPI_Info *newinfo);
int A_MPI_Info_free(A_MPI_Info *info);

/* The globus2 device has to rename A_MPI_ symbols in order to use the vendor
   MPI as one of its transport mechanisms.  Therefore, the following undefines
   should only happen if MPICH_RENAMING_A_MPI_FUNCS is not defined. */
#if !defined(MPICH_RENAMING_A_MPI_FUNCS)
#ifdef A_MPI_Info_f2c
#undef A_MPI_Info_f2c
#endif
#ifdef A_MPI_Info_c2f
#undef A_MPI_Info_c2f
#endif
#endif
/* above needed for some versions of mpi.h in MPICH!! */
A_MPI_Fint A_MPI_Info_c2f(A_MPI_Info info);
A_MPI_Info A_MPI_Info_f2c(A_MPI_Fint info);
#endif

#endif   /* HAVE_PRAGMA_HP_SEC_DEF */


/**************** BINDINGS FOR THE PROFILING INTERFACE ***************/


/* Section 9.2 */
int A_PMPI_File_open(A_MPI_Comm,  char *, int, A_MPI_Info, A_MPI_File *);
int A_PMPI_File_close(A_MPI_File *);
int A_PMPI_File_delete( char *, A_MPI_Info);
int A_PMPI_File_set_size(A_MPI_File, A_MPI_Offset);
int A_PMPI_File_preallocate(A_MPI_File, A_MPI_Offset);
int A_PMPI_File_get_size(A_MPI_File, A_MPI_Offset *);
int A_PMPI_File_get_group(A_MPI_File, A_MPI_Group *);
int A_PMPI_File_get_amode(A_MPI_File, int *);
int A_PMPI_File_set_info(A_MPI_File, A_MPI_Info);
int A_PMPI_File_get_info(A_MPI_File, A_MPI_Info *);

/* Section 9.3 */
int A_PMPI_File_set_view(A_MPI_File, A_MPI_Offset, 
    A_MPI_Datatype, A_MPI_Datatype,  char *, A_MPI_Info);
int A_PMPI_File_get_view(A_MPI_File, A_MPI_Offset *, 
      A_MPI_Datatype *, A_MPI_Datatype *, char *);

/* Section 9.4.2 */
int A_PMPI_File_read_at(A_MPI_File, A_MPI_Offset, void *,
	      int, A_MPI_Datatype, A_MPI_Status *)
              MPICH_ATTR_POINTER_WITH_TYPE_TAG(3,5);
int A_PMPI_File_read_at_all(A_MPI_File, A_MPI_Offset, void *,
	      int, A_MPI_Datatype, A_MPI_Status *)
              MPICH_ATTR_POINTER_WITH_TYPE_TAG(3,5);
int A_PMPI_File_write_at(A_MPI_File, A_MPI_Offset,  void *,
	      int, A_MPI_Datatype, A_MPI_Status *)
              MPICH_ATTR_POINTER_WITH_TYPE_TAG(3,5);
int A_PMPI_File_write_at_all(A_MPI_File, A_MPI_Offset,  void *,
	      int, A_MPI_Datatype, A_MPI_Status *)
              MPICH_ATTR_POINTER_WITH_TYPE_TAG(3,5);

/* nonblocking calls currently use MPIO_Request, because generalized
   requests not yet implemented. For the same reason, MPIO_Test and 
   MPIO_Wait are used to test and wait on nonblocking I/O requests */ 

int A_PMPI_File_iread_at(A_MPI_File, A_MPI_Offset, void *,
	      int, A_MPI_Datatype, MPIO_Request *)
              MPICH_ATTR_POINTER_WITH_TYPE_TAG(3,5);
int A_PMPI_File_iwrite_at(A_MPI_File, A_MPI_Offset,  void *,
	      int, A_MPI_Datatype, MPIO_Request *)
              MPICH_ATTR_POINTER_WITH_TYPE_TAG(3,5);

/* Section 9.4.3 */
int A_PMPI_File_read(A_MPI_File, void *, int, A_MPI_Datatype, A_MPI_Status *)
                   MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_PMPI_File_read_all(A_MPI_File, void *, int, A_MPI_Datatype, A_MPI_Status *)
                       MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_PMPI_File_write(A_MPI_File,  void *, int, A_MPI_Datatype, A_MPI_Status *)
                    MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_PMPI_File_write_all(A_MPI_File,  void *, int, A_MPI_Datatype, A_MPI_Status *)
                        MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);

/* nonblocking calls currently use MPIO_Request, because generalized
   requests not yet implemented. For the same reason, MPIO_Test and 
   MPIO_Wait are used to test and wait on nonblocking I/O requests */ 

int A_PMPI_File_iread(A_MPI_File, void *, int, A_MPI_Datatype, MPIO_Request *)
                    MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_PMPI_File_iwrite(A_MPI_File,  void *, int, A_MPI_Datatype, MPIO_Request *)
                     MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);

int A_PMPI_File_seek(A_MPI_File, A_MPI_Offset, int);
int A_PMPI_File_get_position(A_MPI_File, A_MPI_Offset *);
int A_PMPI_File_get_byte_offset(A_MPI_File, A_MPI_Offset, A_MPI_Offset *);

/* Section 9.4.4 */
int A_PMPI_File_read_shared(A_MPI_File, void *, int, A_MPI_Datatype, A_MPI_Status *)
                          MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_PMPI_File_write_shared(A_MPI_File,  void *, int, A_MPI_Datatype, A_MPI_Status *)
                           MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_PMPI_File_iread_shared(A_MPI_File, void *, int, 
			   A_MPI_Datatype, MPIO_Request *)
                           MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_PMPI_File_iwrite_shared(A_MPI_File,  void *, int,
			    A_MPI_Datatype, MPIO_Request *)
                            MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_PMPI_File_read_ordered(A_MPI_File, void *, int, A_MPI_Datatype, A_MPI_Status *)
                           MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_PMPI_File_write_ordered(A_MPI_File,  void *, int, A_MPI_Datatype, A_MPI_Status *)
                            MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_PMPI_File_seek_shared(A_MPI_File, A_MPI_Offset, int);
int A_PMPI_File_get_position_shared(A_MPI_File, A_MPI_Offset *);

/* Section 9.4.5 */
int A_PMPI_File_read_at_all_begin(A_MPI_File, A_MPI_Offset, void *,
                               int, A_MPI_Datatype)
                               MPICH_ATTR_POINTER_WITH_TYPE_TAG(3,5);
int A_PMPI_File_read_at_all_end(A_MPI_File, void *, A_MPI_Status *);
int A_PMPI_File_write_at_all_begin(A_MPI_File, A_MPI_Offset,  void *,
                                 int, A_MPI_Datatype)
                                 MPICH_ATTR_POINTER_WITH_TYPE_TAG(3,5);
int A_PMPI_File_write_at_all_end(A_MPI_File,  void *, A_MPI_Status *);
int A_PMPI_File_read_all_begin(A_MPI_File, void *, int, A_MPI_Datatype)
                             MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_PMPI_File_read_all_end(A_MPI_File, void *, A_MPI_Status *);
int A_PMPI_File_write_all_begin(A_MPI_File,  void *, int, A_MPI_Datatype)
                              MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_PMPI_File_write_all_end(A_MPI_File,  void *, A_MPI_Status *);
int A_PMPI_File_read_ordered_begin(A_MPI_File, void *, int, A_MPI_Datatype)
                                 MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_PMPI_File_read_ordered_end(A_MPI_File, void *, A_MPI_Status *);
int A_PMPI_File_write_ordered_begin(A_MPI_File,  void *, int, A_MPI_Datatype)
                                  MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int A_PMPI_File_write_ordered_end(A_MPI_File,  void *, A_MPI_Status *);

/* Section 9.5.1 */
int A_PMPI_File_get_type_extent(A_MPI_File, A_MPI_Datatype, A_MPI_Aint *);

/* Section 9.5.3 */
int A_PMPI_Register_datarep( char *,
			 A_MPI_Datarep_conversion_function *,
			 A_MPI_Datarep_conversion_function *,
			 A_MPI_Datarep_extent_function *,
			 void *);

/* Section 9.6.1 */
int A_PMPI_File_set_atomicity(A_MPI_File, int);
int A_PMPI_File_get_atomicity(A_MPI_File, int *);
int A_PMPI_File_sync(A_MPI_File);

/* Section 4.13.3 */
#ifndef MPICH
/* MPICH provides these definitions */
int A_PMPI_File_set_errhandler( A_MPI_File, A_MPI_Errhandler );
int A_PMPI_File_get_errhandler( A_MPI_File, A_MPI_Errhandler * );
#endif

#ifndef HAVE_A_MPI_DARRAY_SUBARRAY
/* Section 4.14.4 */
int A_PMPI_Type_create_subarray(int, int *, int *, int *, int, 
                      A_MPI_Datatype, A_MPI_Datatype *);

/* Section 4.14.5 */
int A_PMPI_Type_create_darray(int, int, int, int *, int *, 
                    int *, int *, int, A_MPI_Datatype, A_MPI_Datatype *);
#endif

/* Section 4.12.4 */
A_MPI_File A_PMPI_File_f2c(A_MPI_Fint);
A_MPI_Fint A_PMPI_File_c2f(A_MPI_File);

#ifndef HAVE_A_MPI_GREQUEST
/* The following functions are required if generalized requests are not
   available, because in that case, an MPIO_Request object
   is currently used for nonblocking I/O. */
int PMPIO_Test(MPIO_Request *, int *, A_MPI_Status *);
int PMPIO_Wait(MPIO_Request *, A_MPI_Status *);
int PMPIO_Testall(int, MPIO_Request *, int *, A_MPI_Status *);
int PMPIO_Waitall(int, MPIO_Request *, A_MPI_Status *);
int PMPIO_Testany(int, MPIO_Request *, int *, int *, A_MPI_Status *);
int PMPIO_Waitany(int, MPIO_Request *, int *, A_MPI_Status *);
int PMPIO_Waitsome(int, MPIO_Request *, int *, int *, A_MPI_Status *);
int PMPIO_Testsome(int, MPIO_Request *, int *, int *, A_MPI_Status *);
A_MPI_Fint PMPIO_Request_c2f(MPIO_Request);
MPIO_Request PMPIO_Request_f2c(A_MPI_Fint);
#endif /* HAVE_A_MPI_GREQUEST */

/* info functions if not defined in the MPI implementation */
#ifndef HAVE_A_MPI_INFO

int A_PMPI_Info_create(A_MPI_Info *);
int A_PMPI_Info_set(A_MPI_Info, char *, char *);
int A_PMPI_Info_delete(A_MPI_Info, char *);
int A_PMPI_Info_get(A_MPI_Info, char *, int, char *, int *);
int A_PMPI_Info_get_valuelen(A_MPI_Info, char *, int *, int *);
int A_PMPI_Info_get_nkeys(A_MPI_Info, int *);
int A_PMPI_Info_get_nthkey(A_MPI_Info, int, char *);
int A_PMPI_Info_dup(A_MPI_Info, A_MPI_Info *);
int A_PMPI_Info_free(A_MPI_Info *);

A_MPI_Fint A_PMPI_Info_c2f(A_MPI_Info);
A_MPI_Info A_PMPI_Info_f2c(A_MPI_Fint);
#endif

#if defined(__cplusplus)
}
#endif

#endif

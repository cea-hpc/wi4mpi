/* -*- Mode: C; c-basic-offset:4 ; -*- */
/* 
 *
 *   Copyright (C) 1997 University of Chicago. 
 *   See COPYRIGHT notice in top-level directory.
 */

/* user include file for MPI-IO programs */

#ifndef R_MPIO_INCLUDE
#define R_MPIO_INCLUDE

#include "run_mpi.h"

#if defined(__cplusplus)
extern "C" {
#endif

#define ROMIO_VERSION 126 /* version 1.2.6 */

/* define MPI-IO datatypes and constants */

#ifndef R_MPI_FILE_DEFINED
typedef struct ADIOI_FileD *R_MPI_File;
#endif

#define HAVE_MPI_GREQUEST
#ifndef HAVE_MPI_GREQUEST
typedef struct ADIOI_RequestD *R_MPIO_Request;  
#else
#define R_MPIO_Request R_MPI_Request
#define R_MPIO_USES_MPI_REQUEST
/* Also rename the MPIO routines to get the MPI versions */
#define R_MPIO_Wait R_MPI_Wait
#define R_MPIO_Test R_MPI_Test
#define PMPIO_Wait R_PMPI_Wait
#define PMPIO_Test R_PMPI_Test
#endif
#define R_MPIO_REQUEST_DEFINED

#ifndef HAVE_MPI_OFFSET
typedef long long R_MPI_Offset;
/* If we needed to define R_MPI_Offset, then we also need to make
   this definition. */
#ifndef HAVE_MPI_DATAREP_FUNCTIONS
#define HAVE_MPI_DATAREP_FUNCTIONS
typedef int (R_MPI_Datarep_conversion_function)(void *, R_MPI_Datatype, int, 
             void *, R_MPI_Offset, void *);
typedef int (R_MPI_Datarep_extent_function)(R_MPI_Datatype datatype, R_MPI_Aint *,
					  void *);
#endif
#endif

#ifndef NEEDS_MPI_FINT

#endif
#ifdef NEEDS_MPI_FINT
typedef int R_MPI_Fint; 
#endif

#ifndef HAVE_MPI_INFO
#define HAVE_MPI_INFO
#endif
#ifndef HAVE_MPI_INFO
  typedef struct MPIR_Info *R_MPI_Info;
# define R_MPI_INFO_NULL         ((R_MPI_Info) 0)
# define R_MPI_MAX_INFO_KEY       255
# define R_MPI_MAX_INFO_VAL      1024
#endif

#define R_MPI_MODE_RDONLY              2  /* ADIO_RDONLY */
#define R_MPI_MODE_RDWR                8  /* ADIO_RDWR  */
#define R_MPI_MODE_WRONLY              4  /* ADIO_WRONLY  */
#define R_MPI_MODE_CREATE              1  /* ADIO_CREATE */ 
#define R_MPI_MODE_EXCL               64  /* ADIO_EXCL */
#define R_MPI_MODE_DELETE_ON_CLOSE    16  /* ADIO_DELETE_ON_CLOSE */
#define R_MPI_MODE_UNIQUE_OPEN        32  /* ADIO_UNIQUE_OPEN */
#define R_MPI_MODE_APPEND            128  /* ADIO_APPEND */
#define R_MPI_MODE_SEQUENTIAL        256  /* ADIO_SEQUENTIAL */

#define R_MPI_DISPLACEMENT_CURRENT   -54278278

#ifndef MPICH
/* FIXME: Make sure that we get a consistent definition of R_MPI_FILE_NULL
	in MPICH */
/* MPICH defines null object handles differently */
#define R_MPI_FILE_NULL           ((R_MPI_File) 0)
#endif
#define R_MPIO_REQUEST_NULL       ((R_MPIO_Request) 0)

#define R_MPI_SEEK_SET            600
#define R_MPI_SEEK_CUR            602
#define R_MPI_SEEK_END            604

/* Open MPI: don't define R_MPI_MAX_DATAREP_STRING here; it's defined in
   OMPI's mpi.h. */
#ifndef OPEN_MPI
#define R_MPI_MAX_DATAREP_STRING  128
#endif

#ifndef HAVE_MPI_DARRAY_SUBARRAY
#define HAVE_MPI_DARRAY_SUBARRAY
#endif
#ifndef HAVE_MPI_DARRAY_SUBARRAY
#  define R_MPI_ORDER_C             56
#  define R_MPI_ORDER_FORTRAN       57
#  define R_MPI_DISTRIBUTE_BLOCK    121
#  define R_MPI_DISTRIBUTE_CYCLIC   122
#  define R_MPI_DISTRIBUTE_NONE     123
#  define R_MPI_DISTRIBUTE_DFLT_DARG -49767
#endif


/* MPI-IO function prototypes */

/* The compiler must support ANSI C style prototypes, otherwise 
   long long constants (e.g. 0) may get passed as ints. */

#ifndef HAVE_PRAGMA_HP_SEC_DEF

/* Section 9.2 */
/* Begin Prototypes */
int R_MPI_File_open(R_MPI_Comm comm, char *filename, int amode, R_MPI_Info info, R_MPI_File *fh);
int R_MPI_File_close(R_MPI_File *fh);
int R_MPI_File_delete(char *filename, R_MPI_Info info);
int R_MPI_File_set_size(R_MPI_File fh, R_MPI_Offset size);
int R_MPI_File_preallocate(R_MPI_File fh, R_MPI_Offset size);
int R_MPI_File_get_size(R_MPI_File fh, R_MPI_Offset *size);
int R_MPI_File_get_group(R_MPI_File fh, R_MPI_Group *group);
int R_MPI_File_get_amode(R_MPI_File fh, int *amode);
int R_MPI_File_set_info(R_MPI_File fh, R_MPI_Info info);
int R_MPI_File_get_info(R_MPI_File fh, R_MPI_Info *info_used);

/* Section 9.3 */
int R_MPI_File_set_view(R_MPI_File fh, R_MPI_Offset disp, R_MPI_Datatype etype, R_MPI_Datatype filetype,
                      char *datarep, R_MPI_Info info);
int R_MPI_File_get_view(R_MPI_File fh, R_MPI_Offset *disp, R_MPI_Datatype *etype, R_MPI_Datatype *filetype,
                      char *datarep);

/* Section 9.4.2 */
int R_MPI_File_read_at(R_MPI_File fh, R_MPI_Offset offset, void *buf, int count, R_MPI_Datatype datatype,
                     R_MPI_Status *status) MPICH_ATTR_POINTER_WITH_TYPE_TAG(3,5);
int R_MPI_File_read_at_all(R_MPI_File fh, R_MPI_Offset offset, void * buf, int count,
                         R_MPI_Datatype datatype, R_MPI_Status *status)
    MPICH_ATTR_POINTER_WITH_TYPE_TAG(3,5);
int R_MPI_File_write_at(R_MPI_File fh, R_MPI_Offset offset, void * buf, int count,
                      R_MPI_Datatype datatype, R_MPI_Status *status)
    MPICH_ATTR_POINTER_WITH_TYPE_TAG(3,5);
int R_MPI_File_write_at_all(R_MPI_File fh, R_MPI_Offset offset, void *buf, int count,
                          R_MPI_Datatype datatype, R_MPI_Status *status)
    MPICH_ATTR_POINTER_WITH_TYPE_TAG(3,5);

/* nonblocking calls currently use R_MPIO_Request, because generalized
   requests not yet implemented. For the same reason, R_MPIO_Test and 
   R_MPIO_Wait are used to test and wait on nonblocking I/O requests */ 
int R_MPI_File_iread_at(R_MPI_File fh, R_MPI_Offset offset, void *buf, int count, R_MPI_Datatype datatype,
                      R_MPIO_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(3,5);
int R_MPI_File_iwrite_at(R_MPI_File fh, R_MPI_Offset offset, void *buf, int count,
                       R_MPI_Datatype datatype, R_MPIO_Request *request)
    MPICH_ATTR_POINTER_WITH_TYPE_TAG(3,5);

/* Section 9.4.3 */
int R_MPI_File_read(R_MPI_File fh, void *buf, int count, R_MPI_Datatype datatype, R_MPI_Status *status)
    MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_MPI_File_read_all(R_MPI_File fh, void *buf, int count, R_MPI_Datatype datatype, R_MPI_Status *status)
    MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_MPI_File_write(R_MPI_File fh, void *buf, int count, R_MPI_Datatype datatype,
                   R_MPI_Status *status) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_MPI_File_write_all(R_MPI_File fh, void *buf, int count, R_MPI_Datatype datatype,
                       R_MPI_Status *status) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);

/* nonblocking calls currently use R_MPIO_Request, because generalized
   requests not yet implemented. For the same reason, R_MPIO_Test and 
   R_MPIO_Wait are used to test and wait on nonblocking I/O requests */ 

int R_MPI_File_iread(R_MPI_File fh, void *buf, int count, R_MPI_Datatype datatype, R_MPIO_Request *request)
    MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_MPI_File_iwrite(R_MPI_File fh, void *buf, int count, R_MPI_Datatype datatype,
                    R_MPIO_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);

int R_MPI_File_seek(R_MPI_File fh, R_MPI_Offset offset, int whence);
int R_MPI_File_get_position(R_MPI_File fh, R_MPI_Offset *offset);
int R_MPI_File_get_byte_offset(R_MPI_File fh, R_MPI_Offset offset, R_MPI_Offset *disp);

/* Section 9.4.4 */
int R_MPI_File_read_shared(R_MPI_File fh, void *buf, int count, R_MPI_Datatype datatype,
                         R_MPI_Status *status) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_MPI_File_write_shared(R_MPI_File fh, void *buf, int count, R_MPI_Datatype datatype,
                          R_MPI_Status *status) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_MPI_File_iread_shared(R_MPI_File fh, void *buf, int count, R_MPI_Datatype datatype,
                          R_MPIO_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_MPI_File_iwrite_shared(R_MPI_File fh, void *buf, int count, R_MPI_Datatype datatype,
                           R_MPIO_Request *request) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_MPI_File_read_ordered(R_MPI_File fh, void *buf, int count, R_MPI_Datatype datatype,
                          R_MPI_Status *status) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_MPI_File_write_ordered(R_MPI_File fh, void *buf, int count, R_MPI_Datatype datatype,
                           R_MPI_Status *status) MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_MPI_File_seek_shared(R_MPI_File fh, R_MPI_Offset offset, int whence);
int R_MPI_File_get_position_shared(R_MPI_File fh, R_MPI_Offset *offset);

/* Section 9.4.5 */
int R_MPI_File_read_at_all_begin(R_MPI_File fh, R_MPI_Offset offset, void *buf, int count,
                               R_MPI_Datatype datatype) MPICH_ATTR_POINTER_WITH_TYPE_TAG(3,5);
int R_MPI_File_read_at_all_end(R_MPI_File fh, void *buf, R_MPI_Status *status);
int R_MPI_File_write_at_all_begin(R_MPI_File fh, R_MPI_Offset offset, void *buf, int count,
                                R_MPI_Datatype datatype) MPICH_ATTR_POINTER_WITH_TYPE_TAG(3,5);
int R_MPI_File_write_at_all_end(R_MPI_File fh, void *buf, R_MPI_Status *status);
int R_MPI_File_read_all_begin(R_MPI_File fh, void *buf, int count, R_MPI_Datatype datatype)
    MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_MPI_File_read_all_end(R_MPI_File fh, void *buf, R_MPI_Status *status);
int R_MPI_File_write_all_begin(R_MPI_File fh, void *buf, int count, R_MPI_Datatype datatype)
    MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_MPI_File_write_all_end(R_MPI_File fh, void *buf, R_MPI_Status *status);
int R_MPI_File_read_ordered_begin(R_MPI_File fh, void *buf, int count, R_MPI_Datatype datatype)
    MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_MPI_File_read_ordered_end(R_MPI_File fh, void *buf, R_MPI_Status *status);
int R_MPI_File_write_ordered_begin(R_MPI_File fh, void *buf, int count, R_MPI_Datatype datatype)
    MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_MPI_File_write_ordered_end(R_MPI_File fh, void *buf, R_MPI_Status *status);

/* Section 9.5.1 */
int R_MPI_File_get_type_extent(R_MPI_File fh, R_MPI_Datatype datatype, R_MPI_Aint *extent);

/* Section 9.5.3 */
int R_MPI_Register_datarep(char *datarep, R_MPI_Datarep_conversion_function *read_conversion_fn,
			 R_MPI_Datarep_conversion_function *write_conversion_fn,
			 R_MPI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state);

/* Section 9.6.1 */
int R_MPI_File_set_atomicity(R_MPI_File fh, int flag);
int R_MPI_File_get_atomicity(R_MPI_File fh, int *flag);
int R_MPI_File_sync(R_MPI_File fh);

/* Section 4.13.3 */
#ifndef MPICH
/* MPICH provides these definitions */
int R_MPI_File_set_errhandler(R_MPI_File file, R_MPI_Errhandler errhandler);
int R_MPI_File_get_errhandler(R_MPI_File file, R_MPI_Errhandler *errhandler);
#endif

/* For MPI 3.1 */
int R_MPI_File_iread_at_all(R_MPI_File fh, R_MPI_Offset offset, void *buf, int count,
                           R_MPI_Datatype datatype, R_MPI_Request *request)
    MPICH_ATTR_POINTER_WITH_TYPE_TAG(3,5);
int R_MPI_File_iwrite_at_all(R_MPI_File fh, R_MPI_Offset offset, void *buf, int count,
                            R_MPI_Datatype datatype, R_MPI_Request *request)
    MPICH_ATTR_POINTER_WITH_TYPE_TAG(3,5);
int R_MPI_File_iread_all(R_MPI_File fh, void *buf, int count, R_MPI_Datatype datatype,
                        R_MPI_Request *request)
    MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_MPI_File_iwrite_all(R_MPI_File fh, void *buf, int count, R_MPI_Datatype datatype,
                         R_MPI_Request *request)
    MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
/* End Prototypes */

#ifndef HAVE_MPI_DARRAY_SUBARRAY
/* Section 4.14.4 */
int R_MPI_Type_create_subarray(int ndims, const int array_of_sizes[], const int array_of_subsizes[],
                             const int array_of_starts[], int order, R_MPI_Datatype oldtype,
                             R_MPI_Datatype *newtype);

/* Section 4.14.5 */
int R_MPI_Type_create_darray(int size, int rank, int ndims, const int array_of_gsizes[],
                           const int array_of_distribs[], const int array_of_dargs[],
                           const int array_of_psizes, int order, R_MPI_Datatype oldtype,
                           R_MPI_Datatype *newtype);
#endif

/* The globus2 device has to rename R_MPI_ symbols in order to use the vendor
   MPI as one of its transport mechanisms.  Therefore, the following undefines
   should only happen if MPICH_RENAMING_MPI_FUNCS is not defined. */
/* Section 4.12.4 */
#if !defined(MPICH_RENAMING_MPI_FUNCS)
#ifdef R_MPI_File_f2c
#undef R_MPI_File_f2c
#endif
#ifdef R_MPI_File_c2f
#undef R_MPI_File_c2f
#endif
#endif
/* above needed for some versions of mpi.h in MPICH!! */
R_MPI_File R_MPI_File_f2c(R_MPI_Fint file);
R_MPI_Fint R_MPI_File_c2f(R_MPI_File file);


#ifndef HAVE_MPI_GREQUEST
/* The following functions are required if generalized requests are not
   available, because in that case, an R_MPIO_Request object
   is currently used for nonblocking I/O. */
int R_MPIO_Test(R_MPIO_Request *request, int *flag, R_MPI_Status *status);
int R_MPIO_Wait(R_MPIO_Request *request, R_MPI_Status *status);
int R_MPIO_Testall(int count, R_MPIO_Request array_of_requests[], int *flag,
                 R_MPI_Status array_of_statuses[]);
int R_MPIO_Waitall(int count, R_MPIO_Request array_of_requests[], R_MPI_Status array_of_statuses[]);
int R_MPIO_Testany(int count, R_MPIO_Request array_of_requests[], int *indx, int *flag,
                 R_MPI_Status *status);
int R_MPIO_Waitany(int count, R_MPIO_Request array_of_requests[], int *indx, R_MPI_Status *status);
int R_MPIO_Waitsome(int incount, R_MPIO_Request array_of_requests[], int *outcount,
                  int array_of_indices[], R_MPI_Status array_of_statuses[]);
int R_MPIO_Testsome(int incount, R_MPIO_Request array_of_requests[], int *outcount,
                  int array_of_indices[], R_MPI_Status array_of_statuses[]);

R_MPI_Fint R_MPIO_Request_c2f(R_MPIO_Request request);
R_MPIO_Request R_MPIO_Request_f2c(R_MPI_Fint request);
#endif /* HAVE_MPI_GREQUEST */

/* info functions if not defined in the MPI implementation */
#ifndef HAVE_MPI_INFO

int R_MPI_Info_create(R_MPI_Info *info);
int R_MPI_Info_set(R_MPI_Info info, const char *key, const char *value);
int R_MPI_Info_delete(R_MPI_Info info, const char *key);
int R_MPI_Info_get(R_MPI_Info info, const char *key, int valuelen, char *value, int *flag);
int R_MPI_Info_get_valuelen(R_MPI_Info info, const char *key, int *valuelen, int *flag);
int R_MPI_Info_get_nkeys(R_MPI_Info info, int *nkeys);
int R_MPI_Info_get_nthkey(R_MPI_Info info, int n, char *key);
int R_MPI_Info_dup(R_MPI_Info info, R_MPI_Info *newinfo);
int R_MPI_Info_free(R_MPI_Info *info);

/* The globus2 device has to rename R_MPI_ symbols in order to use the vendor
   MPI as one of its transport mechanisms.  Therefore, the following undefines
   should only happen if MPICH_RENAMING_MPI_FUNCS is not defined. */
#if !defined(MPICH_RENAMING_MPI_FUNCS)
#ifdef R_MPI_Info_f2c
#undef R_MPI_Info_f2c
#endif
#ifdef R_MPI_Info_c2f
#undef R_MPI_Info_c2f
#endif
#endif
/* above needed for some versions of mpi.h in MPICH!! */
R_MPI_Fint R_MPI_Info_c2f(R_MPI_Info info);
R_MPI_Info R_MPI_Info_f2c(R_MPI_Fint info);
#endif

#endif   /* HAVE_PRAGMA_HP_SEC_DEF */


/**************** BINDINGS FOR THE PROFILING INTERFACE ***************/


/* Section 9.2 */
int R_PMPI_File_open(R_MPI_Comm, const char *, int, R_MPI_Info, R_MPI_File *);
int R_PMPI_File_close(R_MPI_File *);
int R_PMPI_File_delete(const char *, R_MPI_Info);
int R_PMPI_File_set_size(R_MPI_File, R_MPI_Offset);
int R_PMPI_File_preallocate(R_MPI_File, R_MPI_Offset);
int R_PMPI_File_get_size(R_MPI_File, R_MPI_Offset *);
int R_PMPI_File_get_group(R_MPI_File, R_MPI_Group *);
int R_PMPI_File_get_amode(R_MPI_File, int *);
int R_PMPI_File_set_info(R_MPI_File, R_MPI_Info);
int R_PMPI_File_get_info(R_MPI_File, R_MPI_Info *);

/* Section 9.3 */
int R_PMPI_File_set_view(R_MPI_File, R_MPI_Offset, 
    R_MPI_Datatype, R_MPI_Datatype, const char *, R_MPI_Info);
int R_PMPI_File_get_view(R_MPI_File, R_MPI_Offset *, 
      R_MPI_Datatype *, R_MPI_Datatype *, char *);

/* Section 9.4.2 */
int R_PMPI_File_read_at(R_MPI_File, R_MPI_Offset, void *,
	      int, R_MPI_Datatype, R_MPI_Status *)
              MPICH_ATTR_POINTER_WITH_TYPE_TAG(3,5);
int R_PMPI_File_read_at_all(R_MPI_File, R_MPI_Offset, void *,
	      int, R_MPI_Datatype, R_MPI_Status *)
              MPICH_ATTR_POINTER_WITH_TYPE_TAG(3,5);
int R_PMPI_File_write_at(R_MPI_File, R_MPI_Offset, const void *,
	      int, R_MPI_Datatype, R_MPI_Status *)
              MPICH_ATTR_POINTER_WITH_TYPE_TAG(3,5);
int R_PMPI_File_write_at_all(R_MPI_File, R_MPI_Offset, const void *,
	      int, R_MPI_Datatype, R_MPI_Status *)
              MPICH_ATTR_POINTER_WITH_TYPE_TAG(3,5);

/* nonblocking calls currently use R_MPIO_Request, because generalized
   requests not yet implemented. For the same reason, R_MPIO_Test and 
   R_MPIO_Wait are used to test and wait on nonblocking I/O requests */ 

int R_PMPI_File_iread_at(R_MPI_File, R_MPI_Offset, void *,
	      int, R_MPI_Datatype, R_MPIO_Request *)
              MPICH_ATTR_POINTER_WITH_TYPE_TAG(3,5);
int R_PMPI_File_iwrite_at(R_MPI_File, R_MPI_Offset, const void *,
	      int, R_MPI_Datatype, R_MPIO_Request *)
              MPICH_ATTR_POINTER_WITH_TYPE_TAG(3,5);

/* Section 9.4.3 */
int R_PMPI_File_read(R_MPI_File, void *, int, R_MPI_Datatype, R_MPI_Status *)
                   MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_PMPI_File_read_all(R_MPI_File, void *, int, R_MPI_Datatype, R_MPI_Status *)
                       MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_PMPI_File_write(R_MPI_File, const void *, int, R_MPI_Datatype, R_MPI_Status *)
                    MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_PMPI_File_write_all(R_MPI_File, const void *, int, R_MPI_Datatype, R_MPI_Status *)
                        MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);

/* nonblocking calls currently use R_MPIO_Request, because generalized
   requests not yet implemented. For the same reason, R_MPIO_Test and 
   R_MPIO_Wait are used to test and wait on nonblocking I/O requests */ 

int R_PMPI_File_iread(R_MPI_File, void *, int, R_MPI_Datatype, R_MPIO_Request *)
                    MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_PMPI_File_iwrite(R_MPI_File, const void *, int, R_MPI_Datatype, R_MPIO_Request *)
                     MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);

int R_PMPI_File_seek(R_MPI_File, R_MPI_Offset, int);
int R_PMPI_File_get_position(R_MPI_File, R_MPI_Offset *);
int R_PMPI_File_get_byte_offset(R_MPI_File, R_MPI_Offset, R_MPI_Offset *);

/* Section 9.4.4 */
int R_PMPI_File_read_shared(R_MPI_File, void *, int, R_MPI_Datatype, R_MPI_Status *)
                          MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_PMPI_File_write_shared(R_MPI_File, const void *, int, R_MPI_Datatype, R_MPI_Status *)
                           MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_PMPI_File_iread_shared(R_MPI_File, void *, int, 
			   R_MPI_Datatype, R_MPIO_Request *)
                           MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_PMPI_File_iwrite_shared(R_MPI_File, const void *, int,
			    R_MPI_Datatype, R_MPIO_Request *)
                            MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_PMPI_File_read_ordered(R_MPI_File, void *, int, R_MPI_Datatype, R_MPI_Status *)
                           MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_PMPI_File_write_ordered(R_MPI_File, const void *, int, R_MPI_Datatype, R_MPI_Status *)
                            MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_PMPI_File_seek_shared(R_MPI_File, R_MPI_Offset, int);
int R_PMPI_File_get_position_shared(R_MPI_File, R_MPI_Offset *);

/* Section 9.4.5 */
int R_PMPI_File_read_at_all_begin(R_MPI_File, R_MPI_Offset, void *,
                               int, R_MPI_Datatype)
                               MPICH_ATTR_POINTER_WITH_TYPE_TAG(3,5);
int R_PMPI_File_read_at_all_end(R_MPI_File, void *, R_MPI_Status *);
int R_PMPI_File_write_at_all_begin(R_MPI_File, R_MPI_Offset, const void *,
                                 int, R_MPI_Datatype)
                                 MPICH_ATTR_POINTER_WITH_TYPE_TAG(3,5);
int R_PMPI_File_write_at_all_end(R_MPI_File, const void *, R_MPI_Status *);
int R_PMPI_File_read_all_begin(R_MPI_File, void *, int, R_MPI_Datatype)
                             MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_PMPI_File_read_all_end(R_MPI_File, void *, R_MPI_Status *);
int R_PMPI_File_write_all_begin(R_MPI_File, const void *, int, R_MPI_Datatype)
                              MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_PMPI_File_write_all_end(R_MPI_File, const void *, R_MPI_Status *);
int R_PMPI_File_read_ordered_begin(R_MPI_File, void *, int, R_MPI_Datatype)
                                 MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_PMPI_File_read_ordered_end(R_MPI_File, void *, R_MPI_Status *);
int R_PMPI_File_write_ordered_begin(R_MPI_File, const void *, int, R_MPI_Datatype)
                                  MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_PMPI_File_write_ordered_end(R_MPI_File, const void *, R_MPI_Status *);

/* Section 9.5.1 */
int R_PMPI_File_get_type_extent(R_MPI_File, R_MPI_Datatype, R_MPI_Aint *);

/* Section 9.5.3 */
int R_PMPI_Register_datarep(const char *,
			 R_MPI_Datarep_conversion_function *,
			 R_MPI_Datarep_conversion_function *,
			 R_MPI_Datarep_extent_function *,
			 void *);

/* Section 9.6.1 */
int R_PMPI_File_set_atomicity(R_MPI_File, int);
int R_PMPI_File_get_atomicity(R_MPI_File, int *);
int R_PMPI_File_sync(R_MPI_File);

/* Section 4.13.3 */
#ifndef MPICH
/* MPICH provides these definitions */
int R_PMPI_File_set_errhandler( R_MPI_File, R_MPI_Errhandler );
int R_PMPI_File_get_errhandler( R_MPI_File, R_MPI_Errhandler * );
#endif

/* For MPI 3.1 */
int R_PMPI_File_iread_at_all(R_MPI_File fh, R_MPI_Offset offset, void *buf, int count,
                            R_MPI_Datatype datatype, R_MPI_Request *request)
    MPICH_ATTR_POINTER_WITH_TYPE_TAG(3,5);
int R_PMPI_File_iwrite_at_all(R_MPI_File fh, R_MPI_Offset offset, const void *buf, int count,
                             R_MPI_Datatype datatype, R_MPI_Request *request)
    MPICH_ATTR_POINTER_WITH_TYPE_TAG(3,5);
int R_PMPI_File_iread_all(R_MPI_File fh, void *buf, int count, R_MPI_Datatype datatype,
                         R_MPI_Request *request)
    MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);
int R_PMPI_File_iwrite_all(R_MPI_File fh, const void *buf, int count, R_MPI_Datatype datatype,
                          R_MPI_Request *request)
    MPICH_ATTR_POINTER_WITH_TYPE_TAG(2,4);

#ifndef HAVE_MPI_DARRAY_SUBARRAY
/* Section 4.14.4 */
int R_PMPI_Type_create_subarray(int, int *, int *, int *, int, 
                      R_MPI_Datatype, R_MPI_Datatype *);

/* Section 4.14.5 */
int R_PMPI_Type_create_darray(int, int, int, int *, int *, 
                    int *, int *, int, R_MPI_Datatype, R_MPI_Datatype *);
#endif

/* Section 4.12.4 */
R_MPI_File R_PMPI_File_f2c(R_MPI_Fint);
R_MPI_Fint R_PMPI_File_c2f(R_MPI_File);

#ifndef HAVE_MPI_GREQUEST
/* The following functions are required if generalized requests are not
   available, because in that case, an R_MPIO_Request object
   is currently used for nonblocking I/O. */
int PMPIO_Test(R_MPIO_Request *, int *, R_MPI_Status *);
int PMPIO_Wait(R_MPIO_Request *, R_MPI_Status *);
int PMPIO_Testall(int, R_MPIO_Request *, int *, R_MPI_Status *);
int PMPIO_Waitall(int, R_MPIO_Request *, R_MPI_Status *);
int PMPIO_Testany(int, R_MPIO_Request *, int *, int *, R_MPI_Status *);
int PMPIO_Waitany(int, R_MPIO_Request *, int *, R_MPI_Status *);
int PMPIO_Waitsome(int, R_MPIO_Request *, int *, int *, R_MPI_Status *);
int PMPIO_Testsome(int, R_MPIO_Request *, int *, int *, R_MPI_Status *);
R_MPI_Fint PMPIO_Request_c2f(R_MPIO_Request);
R_MPIO_Request PMPIO_Request_f2c(R_MPI_Fint);
#endif /* HAVE_MPI_GREQUEST */

/* info functions if not defined in the MPI implementation */
#ifndef HAVE_MPI_INFO

int R_PMPI_Info_create(R_MPI_Info *);
int R_PMPI_Info_set(R_MPI_Info, char *, char *);
int R_PMPI_Info_delete(R_MPI_Info, char *);
int R_PMPI_Info_get(R_MPI_Info, char *, int, char *, int *);
int R_PMPI_Info_get_valuelen(R_MPI_Info, char *, int *, int *);
int R_PMPI_Info_get_nkeys(R_MPI_Info, int *);
int R_PMPI_Info_get_nthkey(R_MPI_Info, int, char *);
int R_PMPI_Info_dup(R_MPI_Info, R_MPI_Info *);
int R_PMPI_Info_free(R_MPI_Info *);

R_MPI_Fint R_PMPI_Info_c2f(R_MPI_Info);
R_MPI_Info R_PMPI_Info_f2c(R_MPI_Fint);
#endif

#if defined(__cplusplus)
}
#endif

#endif

#define A_f_MPI_BOTTOM (((int*)&mpi_fortran_bottom_))
int mpi_fortran_bottom_;
#define A_f_MPI_IN_PLACE (((int*)&mpi_fortran_in_place_))
int mpi_fortran_in_place_;
#define A_f_MPI_ARGV_NULL (((int*)&mpi_fortran_argv_null_))
int mpi_fortran_argv_null_;
#define A_f_MPI_ARGVS_NULL (((int*)&mpi_fortran_argvs_null_))
int mpi_fortran_argvs_null_;
#define A_f_MPI_ERRCODES_IGNORE (((int*)&mpi_fortran_errcodes_ignore_))
int mpi_fortran_errcodes_ignore_;
#define A_f_MPI_STATUS_IGNORE (((int*)&mpi_fortran_status_ignore_))
int mpi_fortran_status_ignore_;
#define A_f_MPI_STATUSES_IGNORE (((int*)&mpi_fortran_statuses_ignore_))
int mpi_fortran_statuses_ignore_;
#define A_f_MPI_UNWEIGHTED (((int*)&mpi_fortran_unweighted_))
int mpi_fortran_unweighted_;
#define A_f_MPI_WEIGHTS_EMPTY (((int*)&mpi_fortran_weights_empty_))
int mpi_fortran_weights_empty_;
#define R_f_MPI_BOTTOM (((int*)&mpi_fortran_bottom_))
int *ccc_mpi_fortran_bottom_;
#define R_f_MPI_IN_PLACE (((int*)&mpi_fortran_in_place_))
int *ccc_mpi_fortran_in_place_;
#define R_f_MPI_ARGV_NULL (((int*)&mpi_fortran_argv_null_))
int *ccc_mpi_fortran_argv_null_;
#define R_f_MPI_ARGVS_NULL (((int*)&mpi_fortran_argvs_null_))
int *ccc_mpi_fortran_argvs_null_;
#define R_f_MPI_ERRCODES_IGNORE (((int*)&mpi_fortran_errcodes_ignore_))
int *ccc_mpi_fortran_errcodes_ignore_;
#define R_f_MPI_STATUS_IGNORE (((int*)&mpi_fortran_status_ignore_))
int *ccc_mpi_fortran_status_ignore_;
#define R_f_MPI_STATUSES_IGNORE (((int*)&mpi_fortran_statuses_ignore_))
int *ccc_mpi_fortran_statuses_ignore_;
#define R_f_MPI_UNWEIGHTED (((int*)&mpi_fortran_unweighted_))
int *ccc_mpi_fortran_unweighted_;
#define R_f_MPI_WEIGHTS_EMPTY (((int*)&mpi_fortran_weights_empty_))
int *ccc_mpi_fortran_weights_empty_;
//############################# Wi4MPI License ###########################
//# `04/04/2016`                                                         #
//# Copyright or (C) or Copr. Commissariat a l'Energie Atomique         #
//#                                                                      #
//# IDDN.FR.001.210022.000.S.P.2014.000.10800                            #
//# This file is part of the Wi4MPI library.                             #
//#                                                                      #
//# SPDX-License-Identifier: BSD-3-Clause OR CeCILL-B                    #
//#                                                                      #
//#                                                                      #
//# Authors:                                                             #
//#   - Delforge Tony <tony.delforge.tgcc@cea.fr>                        #
//#   - Ducrot Vincent <vincent.ducrot.tgcc@cea.fr>                      #
//#                                                                      #
//########################################################################
#ifndef __wrapper__h__
#define __wrapper__h__

#include "utils.h"

#include "engine.h"

#define A_f_MPI_COMM_SELF 1

#define R_f_MPI_COMM_SELF 1

#define A_f_MPI_COMM_WORLD 0

#define R_f_MPI_COMM_WORLD 0

#define A_f_MPI_COMM_NULL 2

#define R_f_MPI_COMM_NULL 2

static inline void comm_a2r(int *ca,int *cr){
if(A_f_MPI_COMM_SELF==*ca){
*cr=(int )R_f_MPI_COMM_SELF;return;}
else
if(A_f_MPI_COMM_WORLD==*ca){
*cr=(int )R_f_MPI_COMM_WORLD;return;}
else
if(A_f_MPI_COMM_NULL==*ca){
*cr=(int )R_f_MPI_COMM_NULL;return;}
else
communicator_translation_get_f(*ca,cr);
}

static inline void comm_r2a(int *ca,int *cr){
if(R_f_MPI_COMM_SELF==*cr){
*ca=(int )A_f_MPI_COMM_SELF;return;}
else
if(R_f_MPI_COMM_WORLD==*cr){
*ca=(int )A_f_MPI_COMM_WORLD;return;}
else
if(R_f_MPI_COMM_NULL==*cr){
*ca=(int )A_f_MPI_COMM_NULL;return;}
else
communicator_translation_update_alloc_f(*cr,ca);

}
static inline void comm_r2au(int *ca,int *cr){
if(R_f_MPI_COMM_SELF==*cr){
communicator_translation_del_f(*ca);*ca=(int )A_f_MPI_COMM_SELF;return;}
else
if(R_f_MPI_COMM_WORLD==*cr){
communicator_translation_del_f(*ca);*ca=(int )A_f_MPI_COMM_WORLD;return;}
else
if(R_f_MPI_COMM_NULL==*cr){
communicator_translation_del_f(*ca);*ca=(int )A_f_MPI_COMM_NULL;return;}
else
communicator_translation_update_f(*cr,ca);

}
#define A_f_MPI_ERR_NO_SUCH_FILE 42

#define R_f_MPI_ERR_NO_SUCH_FILE 42

#define A_f_MPI_ERR_PORT 43

#define R_f_MPI_ERR_PORT 43

#define A_f_MPI_ERR_SIZE 49

#define R_f_MPI_ERR_SIZE 49

#define A_f_MPI_ERR_UNSUPPORTED_OPERATION 52

#define R_f_MPI_ERR_UNSUPPORTED_OPERATION 52

#define A_f_MPI_ERR_WIN 53

#define R_f_MPI_ERR_WIN 53

#define A_f_MPI_ERR_BASE 24

#define R_f_MPI_ERR_BASE 24

#define A_f_MPI_ERR_CONVERSION 25

#define R_f_MPI_ERR_CONVERSION 25

#define A_f_MPI_ERR_DISP 26

#define R_f_MPI_ERR_DISP 26

#define A_f_MPI_ERR_DUP_DATAREP 27

#define R_f_MPI_ERR_DUP_DATAREP 27

#define A_f_MPI_ERR_ACCESS 20

#define R_f_MPI_ERR_ACCESS 20

#define A_f_MPI_ERR_AMODE 21

#define R_f_MPI_ERR_AMODE 21

#define A_f_MPI_ERR_ASSERT 22

#define R_f_MPI_ERR_ASSERT 22

#define A_f_MPI_ERR_BAD_FILE 23

#define R_f_MPI_ERR_BAD_FILE 23

#define A_f_MPI_ERR_RMA_CONFLICT 46

#define R_f_MPI_ERR_RMA_CONFLICT 46

#define A_f_MPI_ERR_RMA_SYNC 47

#define R_f_MPI_ERR_RMA_SYNC 47

#define A_f_MPI_ERR_QUOTA 44

#define R_f_MPI_ERR_QUOTA 44

#define A_f_MPI_ERR_READ_ONLY 45

#define R_f_MPI_ERR_READ_ONLY 45

#define A_f_MPI_ERR_FILE_EXISTS 28

#define R_f_MPI_ERR_FILE_EXISTS 28

#define A_f_MPI_ERR_FILE_IN_USE 29

#define R_f_MPI_ERR_FILE_IN_USE 29

#define A_f_MPI_ERR_NOT_SAME 40

#define R_f_MPI_ERR_NOT_SAME 40

#define A_f_MPI_ERR_NO_SPACE 41

#define R_f_MPI_ERR_NO_SPACE 41

#define A_f_MPI_ERR_BUFFER 1

#define R_f_MPI_ERR_BUFFER 1

#define A_f_MPI_SUCCESS 0

#define R_f_MPI_SUCCESS 0

#define A_f_MPI_ERR_TYPE 3

#define R_f_MPI_ERR_TYPE 3

#define A_f_MPI_ERR_COUNT 2

#define R_f_MPI_ERR_COUNT 2

#define A_f_MPI_ERR_COMM 5

#define R_f_MPI_ERR_COMM 5

#define A_f_MPI_ERR_TAG 4

#define R_f_MPI_ERR_TAG 4

#define A_f_MPI_ERR_REQUEST 7

#define R_f_MPI_ERR_REQUEST 7

#define A_f_MPI_ERR_RANK 6

#define R_f_MPI_ERR_RANK 6

#define A_f_MPI_ERR_GROUP 9

#define R_f_MPI_ERR_GROUP 9

#define A_f_MPI_ERR_ROOT 8

#define R_f_MPI_ERR_ROOT 8

#define A_f_MPI_ERR_UNSUPPORTED_DATAREP 51

#define R_f_MPI_ERR_UNSUPPORTED_DATAREP 51

#define A_f_MPI_ERR_NO_MEM 39

#define R_f_MPI_ERR_NO_MEM 39

#define A_f_MPI_ERR_NAME 38

#define R_f_MPI_ERR_NAME 38

#define A_f_MPI_ERR_LASTCODE 71

#define R_f_MPI_ERR_LASTCODE 71

#define A_f_MPI_ERR_TOPOLOGY 11

#define R_f_MPI_ERR_TOPOLOGY 11

#define A_f_MPI_ERR_OP 10

#define R_f_MPI_ERR_OP 10

#define A_f_MPI_ERR_ARG 13

#define R_f_MPI_ERR_ARG 13

#define A_f_MPI_ERR_DIMS 12

#define R_f_MPI_ERR_DIMS 12

#define A_f_MPI_ERR_TRUNCATE 15

#define R_f_MPI_ERR_TRUNCATE 15

#define A_f_MPI_ERR_UNKNOWN 14

#define R_f_MPI_ERR_UNKNOWN 14

#define A_f_MPI_ERR_INTERN 17

#define R_f_MPI_ERR_INTERN 17

#define A_f_MPI_ERR_OTHER 16

#define R_f_MPI_ERR_OTHER 16

#define A_f_MPI_ERR_PENDING 19

#define R_f_MPI_ERR_PENDING 19

#define A_f_MPI_ERR_IN_STATUS 18

#define R_f_MPI_ERR_IN_STATUS 18

#define A_f_MPI_ERR_INFO_KEY 31

#define R_f_MPI_ERR_INFO_KEY 31

#define A_f_MPI_ERR_FILE 30

#define R_f_MPI_ERR_FILE 30

#define A_f_MPI_ERR_LOCKTYPE 37

#define R_f_MPI_ERR_LOCKTYPE 37

#define A_f_MPI_ERR_KEYVAL 36

#define R_f_MPI_ERR_KEYVAL 36

#define A_f_MPI_ERR_IO 35

#define R_f_MPI_ERR_IO 35

#define A_f_MPI_ERR_INFO 34

#define R_f_MPI_ERR_INFO 34

#define A_f_MPI_ERR_INFO_VALUE 33

#define R_f_MPI_ERR_INFO_VALUE 33

#define A_f_MPI_ERR_INFO_NOKEY 32

#define R_f_MPI_ERR_INFO_NOKEY 32

#define A_f_MPI_ERR_SPAWN 50

#define R_f_MPI_ERR_SPAWN 50

static inline void error_a2r(int *ca,int *cr){
if(A_f_MPI_ERR_NO_SUCH_FILE==*ca){
*cr=(int )R_f_MPI_ERR_NO_SUCH_FILE;return;}
else
if(A_f_MPI_ERR_PORT==*ca){
*cr=(int )R_f_MPI_ERR_PORT;return;}
else
if(A_f_MPI_ERR_SIZE==*ca){
*cr=(int )R_f_MPI_ERR_SIZE;return;}
else
if(A_f_MPI_ERR_UNSUPPORTED_OPERATION==*ca){
*cr=(int )R_f_MPI_ERR_UNSUPPORTED_OPERATION;return;}
else
if(A_f_MPI_ERR_WIN==*ca){
*cr=(int )R_f_MPI_ERR_WIN;return;}
else
if(A_f_MPI_ERR_BASE==*ca){
*cr=(int )R_f_MPI_ERR_BASE;return;}
else
if(A_f_MPI_ERR_CONVERSION==*ca){
*cr=(int )R_f_MPI_ERR_CONVERSION;return;}
else
if(A_f_MPI_ERR_DISP==*ca){
*cr=(int )R_f_MPI_ERR_DISP;return;}
else
if(A_f_MPI_ERR_DUP_DATAREP==*ca){
*cr=(int )R_f_MPI_ERR_DUP_DATAREP;return;}
else
if(A_f_MPI_ERR_ACCESS==*ca){
*cr=(int )R_f_MPI_ERR_ACCESS;return;}
else
if(A_f_MPI_ERR_AMODE==*ca){
*cr=(int )R_f_MPI_ERR_AMODE;return;}
else
if(A_f_MPI_ERR_ASSERT==*ca){
*cr=(int )R_f_MPI_ERR_ASSERT;return;}
else
if(A_f_MPI_ERR_BAD_FILE==*ca){
*cr=(int )R_f_MPI_ERR_BAD_FILE;return;}
else
if(A_f_MPI_ERR_RMA_CONFLICT==*ca){
*cr=(int )R_f_MPI_ERR_RMA_CONFLICT;return;}
else
if(A_f_MPI_ERR_RMA_SYNC==*ca){
*cr=(int )R_f_MPI_ERR_RMA_SYNC;return;}
else
if(A_f_MPI_ERR_QUOTA==*ca){
*cr=(int )R_f_MPI_ERR_QUOTA;return;}
else
if(A_f_MPI_ERR_READ_ONLY==*ca){
*cr=(int )R_f_MPI_ERR_READ_ONLY;return;}
else
if(A_f_MPI_ERR_FILE_EXISTS==*ca){
*cr=(int )R_f_MPI_ERR_FILE_EXISTS;return;}
else
if(A_f_MPI_ERR_FILE_IN_USE==*ca){
*cr=(int )R_f_MPI_ERR_FILE_IN_USE;return;}
else
if(A_f_MPI_ERR_NOT_SAME==*ca){
*cr=(int )R_f_MPI_ERR_NOT_SAME;return;}
else
if(A_f_MPI_ERR_NO_SPACE==*ca){
*cr=(int )R_f_MPI_ERR_NO_SPACE;return;}
else
if(A_f_MPI_ERR_BUFFER==*ca){
*cr=(int )R_f_MPI_ERR_BUFFER;return;}
else
if(A_f_MPI_SUCCESS==*ca){
*cr=(int )R_f_MPI_SUCCESS;return;}
else
if(A_f_MPI_ERR_TYPE==*ca){
*cr=(int )R_f_MPI_ERR_TYPE;return;}
else
if(A_f_MPI_ERR_COUNT==*ca){
*cr=(int )R_f_MPI_ERR_COUNT;return;}
else
if(A_f_MPI_ERR_COMM==*ca){
*cr=(int )R_f_MPI_ERR_COMM;return;}
else
if(A_f_MPI_ERR_TAG==*ca){
*cr=(int )R_f_MPI_ERR_TAG;return;}
else
if(A_f_MPI_ERR_REQUEST==*ca){
*cr=(int )R_f_MPI_ERR_REQUEST;return;}
else
if(A_f_MPI_ERR_RANK==*ca){
*cr=(int )R_f_MPI_ERR_RANK;return;}
else
if(A_f_MPI_ERR_GROUP==*ca){
*cr=(int )R_f_MPI_ERR_GROUP;return;}
else
if(A_f_MPI_ERR_ROOT==*ca){
*cr=(int )R_f_MPI_ERR_ROOT;return;}
else
if(A_f_MPI_ERR_UNSUPPORTED_DATAREP==*ca){
*cr=(int )R_f_MPI_ERR_UNSUPPORTED_DATAREP;return;}
else
if(A_f_MPI_ERR_NO_MEM==*ca){
*cr=(int )R_f_MPI_ERR_NO_MEM;return;}
else
if(A_f_MPI_ERR_NAME==*ca){
*cr=(int )R_f_MPI_ERR_NAME;return;}
else
if(A_f_MPI_ERR_LASTCODE==*ca){
*cr=(int )R_f_MPI_ERR_LASTCODE;return;}
else
if(A_f_MPI_ERR_TOPOLOGY==*ca){
*cr=(int )R_f_MPI_ERR_TOPOLOGY;return;}
else
if(A_f_MPI_ERR_OP==*ca){
*cr=(int )R_f_MPI_ERR_OP;return;}
else
if(A_f_MPI_ERR_ARG==*ca){
*cr=(int )R_f_MPI_ERR_ARG;return;}
else
if(A_f_MPI_ERR_DIMS==*ca){
*cr=(int )R_f_MPI_ERR_DIMS;return;}
else
if(A_f_MPI_ERR_TRUNCATE==*ca){
*cr=(int )R_f_MPI_ERR_TRUNCATE;return;}
else
if(A_f_MPI_ERR_UNKNOWN==*ca){
*cr=(int )R_f_MPI_ERR_UNKNOWN;return;}
else
if(A_f_MPI_ERR_INTERN==*ca){
*cr=(int )R_f_MPI_ERR_INTERN;return;}
else
if(A_f_MPI_ERR_OTHER==*ca){
*cr=(int )R_f_MPI_ERR_OTHER;return;}
else
if(A_f_MPI_ERR_PENDING==*ca){
*cr=(int )R_f_MPI_ERR_PENDING;return;}
else
if(A_f_MPI_ERR_IN_STATUS==*ca){
*cr=(int )R_f_MPI_ERR_IN_STATUS;return;}
else
if(A_f_MPI_ERR_INFO_KEY==*ca){
*cr=(int )R_f_MPI_ERR_INFO_KEY;return;}
else
if(A_f_MPI_ERR_FILE==*ca){
*cr=(int )R_f_MPI_ERR_FILE;return;}
else
if(A_f_MPI_ERR_LOCKTYPE==*ca){
*cr=(int )R_f_MPI_ERR_LOCKTYPE;return;}
else
if(A_f_MPI_ERR_KEYVAL==*ca){
*cr=(int )R_f_MPI_ERR_KEYVAL;return;}
else
if(A_f_MPI_ERR_IO==*ca){
*cr=(int )R_f_MPI_ERR_IO;return;}
else
if(A_f_MPI_ERR_INFO==*ca){
*cr=(int )R_f_MPI_ERR_INFO;return;}
else
if(A_f_MPI_ERR_INFO_VALUE==*ca){
*cr=(int )R_f_MPI_ERR_INFO_VALUE;return;}
else
if(A_f_MPI_ERR_INFO_NOKEY==*ca){
*cr=(int )R_f_MPI_ERR_INFO_NOKEY;return;}
else
if(A_f_MPI_ERR_SPAWN==*ca){
*cr=(int )R_f_MPI_ERR_SPAWN;return;}
else
error_translation_get_f(*ca,cr);
}

static inline void error_r2a(int *ca,int *cr){
if(R_f_MPI_ERR_NO_SUCH_FILE==*cr){
*ca=(int )A_f_MPI_ERR_NO_SUCH_FILE;return;}
else
if(R_f_MPI_ERR_PORT==*cr){
*ca=(int )A_f_MPI_ERR_PORT;return;}
else
if(R_f_MPI_ERR_SIZE==*cr){
*ca=(int )A_f_MPI_ERR_SIZE;return;}
else
if(R_f_MPI_ERR_UNSUPPORTED_OPERATION==*cr){
*ca=(int )A_f_MPI_ERR_UNSUPPORTED_OPERATION;return;}
else
if(R_f_MPI_ERR_WIN==*cr){
*ca=(int )A_f_MPI_ERR_WIN;return;}
else
if(R_f_MPI_ERR_BASE==*cr){
*ca=(int )A_f_MPI_ERR_BASE;return;}
else
if(R_f_MPI_ERR_CONVERSION==*cr){
*ca=(int )A_f_MPI_ERR_CONVERSION;return;}
else
if(R_f_MPI_ERR_DISP==*cr){
*ca=(int )A_f_MPI_ERR_DISP;return;}
else
if(R_f_MPI_ERR_DUP_DATAREP==*cr){
*ca=(int )A_f_MPI_ERR_DUP_DATAREP;return;}
else
if(R_f_MPI_ERR_ACCESS==*cr){
*ca=(int )A_f_MPI_ERR_ACCESS;return;}
else
if(R_f_MPI_ERR_AMODE==*cr){
*ca=(int )A_f_MPI_ERR_AMODE;return;}
else
if(R_f_MPI_ERR_ASSERT==*cr){
*ca=(int )A_f_MPI_ERR_ASSERT;return;}
else
if(R_f_MPI_ERR_BAD_FILE==*cr){
*ca=(int )A_f_MPI_ERR_BAD_FILE;return;}
else
if(R_f_MPI_ERR_RMA_CONFLICT==*cr){
*ca=(int )A_f_MPI_ERR_RMA_CONFLICT;return;}
else
if(R_f_MPI_ERR_RMA_SYNC==*cr){
*ca=(int )A_f_MPI_ERR_RMA_SYNC;return;}
else
if(R_f_MPI_ERR_QUOTA==*cr){
*ca=(int )A_f_MPI_ERR_QUOTA;return;}
else
if(R_f_MPI_ERR_READ_ONLY==*cr){
*ca=(int )A_f_MPI_ERR_READ_ONLY;return;}
else
if(R_f_MPI_ERR_FILE_EXISTS==*cr){
*ca=(int )A_f_MPI_ERR_FILE_EXISTS;return;}
else
if(R_f_MPI_ERR_FILE_IN_USE==*cr){
*ca=(int )A_f_MPI_ERR_FILE_IN_USE;return;}
else
if(R_f_MPI_ERR_NOT_SAME==*cr){
*ca=(int )A_f_MPI_ERR_NOT_SAME;return;}
else
if(R_f_MPI_ERR_NO_SPACE==*cr){
*ca=(int )A_f_MPI_ERR_NO_SPACE;return;}
else
if(R_f_MPI_ERR_BUFFER==*cr){
*ca=(int )A_f_MPI_ERR_BUFFER;return;}
else
if(R_f_MPI_SUCCESS==*cr){
*ca=(int )A_f_MPI_SUCCESS;return;}
else
if(R_f_MPI_ERR_TYPE==*cr){
*ca=(int )A_f_MPI_ERR_TYPE;return;}
else
if(R_f_MPI_ERR_COUNT==*cr){
*ca=(int )A_f_MPI_ERR_COUNT;return;}
else
if(R_f_MPI_ERR_COMM==*cr){
*ca=(int )A_f_MPI_ERR_COMM;return;}
else
if(R_f_MPI_ERR_TAG==*cr){
*ca=(int )A_f_MPI_ERR_TAG;return;}
else
if(R_f_MPI_ERR_REQUEST==*cr){
*ca=(int )A_f_MPI_ERR_REQUEST;return;}
else
if(R_f_MPI_ERR_RANK==*cr){
*ca=(int )A_f_MPI_ERR_RANK;return;}
else
if(R_f_MPI_ERR_GROUP==*cr){
*ca=(int )A_f_MPI_ERR_GROUP;return;}
else
if(R_f_MPI_ERR_ROOT==*cr){
*ca=(int )A_f_MPI_ERR_ROOT;return;}
else
if(R_f_MPI_ERR_UNSUPPORTED_DATAREP==*cr){
*ca=(int )A_f_MPI_ERR_UNSUPPORTED_DATAREP;return;}
else
if(R_f_MPI_ERR_NO_MEM==*cr){
*ca=(int )A_f_MPI_ERR_NO_MEM;return;}
else
if(R_f_MPI_ERR_NAME==*cr){
*ca=(int )A_f_MPI_ERR_NAME;return;}
else
if(R_f_MPI_ERR_LASTCODE==*cr){
*ca=(int )A_f_MPI_ERR_LASTCODE;return;}
else
if(R_f_MPI_ERR_TOPOLOGY==*cr){
*ca=(int )A_f_MPI_ERR_TOPOLOGY;return;}
else
if(R_f_MPI_ERR_OP==*cr){
*ca=(int )A_f_MPI_ERR_OP;return;}
else
if(R_f_MPI_ERR_ARG==*cr){
*ca=(int )A_f_MPI_ERR_ARG;return;}
else
if(R_f_MPI_ERR_DIMS==*cr){
*ca=(int )A_f_MPI_ERR_DIMS;return;}
else
if(R_f_MPI_ERR_TRUNCATE==*cr){
*ca=(int )A_f_MPI_ERR_TRUNCATE;return;}
else
if(R_f_MPI_ERR_UNKNOWN==*cr){
*ca=(int )A_f_MPI_ERR_UNKNOWN;return;}
else
if(R_f_MPI_ERR_INTERN==*cr){
*ca=(int )A_f_MPI_ERR_INTERN;return;}
else
if(R_f_MPI_ERR_OTHER==*cr){
*ca=(int )A_f_MPI_ERR_OTHER;return;}
else
if(R_f_MPI_ERR_PENDING==*cr){
*ca=(int )A_f_MPI_ERR_PENDING;return;}
else
if(R_f_MPI_ERR_IN_STATUS==*cr){
*ca=(int )A_f_MPI_ERR_IN_STATUS;return;}
else
if(R_f_MPI_ERR_INFO_KEY==*cr){
*ca=(int )A_f_MPI_ERR_INFO_KEY;return;}
else
if(R_f_MPI_ERR_FILE==*cr){
*ca=(int )A_f_MPI_ERR_FILE;return;}
else
if(R_f_MPI_ERR_LOCKTYPE==*cr){
*ca=(int )A_f_MPI_ERR_LOCKTYPE;return;}
else
if(R_f_MPI_ERR_KEYVAL==*cr){
*ca=(int )A_f_MPI_ERR_KEYVAL;return;}
else
if(R_f_MPI_ERR_IO==*cr){
*ca=(int )A_f_MPI_ERR_IO;return;}
else
if(R_f_MPI_ERR_INFO==*cr){
*ca=(int )A_f_MPI_ERR_INFO;return;}
else
if(R_f_MPI_ERR_INFO_VALUE==*cr){
*ca=(int )A_f_MPI_ERR_INFO_VALUE;return;}
else
if(R_f_MPI_ERR_INFO_NOKEY==*cr){
*ca=(int )A_f_MPI_ERR_INFO_NOKEY;return;}
else
if(R_f_MPI_ERR_SPAWN==*cr){
*ca=(int )A_f_MPI_ERR_SPAWN;return;}
else
error_translation_update_alloc_f(*cr,ca);

}
static inline void error_r2au(int *ca,int *cr){
if(R_f_MPI_ERR_NO_SUCH_FILE==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_NO_SUCH_FILE;return;}
else
if(R_f_MPI_ERR_PORT==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_PORT;return;}
else
if(R_f_MPI_ERR_SIZE==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_SIZE;return;}
else
if(R_f_MPI_ERR_UNSUPPORTED_OPERATION==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_UNSUPPORTED_OPERATION;return;}
else
if(R_f_MPI_ERR_WIN==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_WIN;return;}
else
if(R_f_MPI_ERR_BASE==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_BASE;return;}
else
if(R_f_MPI_ERR_CONVERSION==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_CONVERSION;return;}
else
if(R_f_MPI_ERR_DISP==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_DISP;return;}
else
if(R_f_MPI_ERR_DUP_DATAREP==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_DUP_DATAREP;return;}
else
if(R_f_MPI_ERR_ACCESS==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_ACCESS;return;}
else
if(R_f_MPI_ERR_AMODE==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_AMODE;return;}
else
if(R_f_MPI_ERR_ASSERT==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_ASSERT;return;}
else
if(R_f_MPI_ERR_BAD_FILE==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_BAD_FILE;return;}
else
if(R_f_MPI_ERR_RMA_CONFLICT==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_RMA_CONFLICT;return;}
else
if(R_f_MPI_ERR_RMA_SYNC==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_RMA_SYNC;return;}
else
if(R_f_MPI_ERR_QUOTA==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_QUOTA;return;}
else
if(R_f_MPI_ERR_READ_ONLY==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_READ_ONLY;return;}
else
if(R_f_MPI_ERR_FILE_EXISTS==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_FILE_EXISTS;return;}
else
if(R_f_MPI_ERR_FILE_IN_USE==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_FILE_IN_USE;return;}
else
if(R_f_MPI_ERR_NOT_SAME==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_NOT_SAME;return;}
else
if(R_f_MPI_ERR_NO_SPACE==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_NO_SPACE;return;}
else
if(R_f_MPI_ERR_BUFFER==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_BUFFER;return;}
else
if(R_f_MPI_SUCCESS==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_SUCCESS;return;}
else
if(R_f_MPI_ERR_TYPE==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_TYPE;return;}
else
if(R_f_MPI_ERR_COUNT==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_COUNT;return;}
else
if(R_f_MPI_ERR_COMM==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_COMM;return;}
else
if(R_f_MPI_ERR_TAG==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_TAG;return;}
else
if(R_f_MPI_ERR_REQUEST==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_REQUEST;return;}
else
if(R_f_MPI_ERR_RANK==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_RANK;return;}
else
if(R_f_MPI_ERR_GROUP==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_GROUP;return;}
else
if(R_f_MPI_ERR_ROOT==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_ROOT;return;}
else
if(R_f_MPI_ERR_UNSUPPORTED_DATAREP==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_UNSUPPORTED_DATAREP;return;}
else
if(R_f_MPI_ERR_NO_MEM==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_NO_MEM;return;}
else
if(R_f_MPI_ERR_NAME==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_NAME;return;}
else
if(R_f_MPI_ERR_LASTCODE==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_LASTCODE;return;}
else
if(R_f_MPI_ERR_TOPOLOGY==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_TOPOLOGY;return;}
else
if(R_f_MPI_ERR_OP==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_OP;return;}
else
if(R_f_MPI_ERR_ARG==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_ARG;return;}
else
if(R_f_MPI_ERR_DIMS==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_DIMS;return;}
else
if(R_f_MPI_ERR_TRUNCATE==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_TRUNCATE;return;}
else
if(R_f_MPI_ERR_UNKNOWN==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_UNKNOWN;return;}
else
if(R_f_MPI_ERR_INTERN==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_INTERN;return;}
else
if(R_f_MPI_ERR_OTHER==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_OTHER;return;}
else
if(R_f_MPI_ERR_PENDING==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_PENDING;return;}
else
if(R_f_MPI_ERR_IN_STATUS==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_IN_STATUS;return;}
else
if(R_f_MPI_ERR_INFO_KEY==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_INFO_KEY;return;}
else
if(R_f_MPI_ERR_FILE==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_FILE;return;}
else
if(R_f_MPI_ERR_LOCKTYPE==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_LOCKTYPE;return;}
else
if(R_f_MPI_ERR_KEYVAL==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_KEYVAL;return;}
else
if(R_f_MPI_ERR_IO==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_IO;return;}
else
if(R_f_MPI_ERR_INFO==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_INFO;return;}
else
if(R_f_MPI_ERR_INFO_VALUE==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_INFO_VALUE;return;}
else
if(R_f_MPI_ERR_INFO_NOKEY==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_INFO_NOKEY;return;}
else
if(R_f_MPI_ERR_SPAWN==*cr){
error_translation_del_f(*ca);*ca=(int )A_f_MPI_ERR_SPAWN;return;}
else
error_translation_update_f(*cr,ca);

}
#define A_f_MPI_2DOUBLE_PRECISION 24

#define R_f_MPI_2DOUBLE_PRECISION 24

#define A_f_MPI_2INTEGER 25

#define R_f_MPI_2INTEGER 25

#define A_f_MPI_REAL 13

#define R_f_MPI_REAL 13

#define A_f_MPI_REAL8 15

#define R_f_MPI_REAL8 15

#define A_f_MPI_DOUBLE_COMPLEX 22

#define R_f_MPI_DOUBLE_COMPLEX 22

#define A_f_MPI_DOUBLE_PRECISION 17

#define R_f_MPI_DOUBLE_PRECISION 17

#define A_f_MPI_2REAL 23

#define R_f_MPI_2REAL 23

#define A_f_MPI_COMPLEX 18

#define R_f_MPI_COMPLEX 18

#define A_f_MPI_BYTE 1

#define R_f_MPI_BYTE 1

#define A_f_MPI_DATATYPE_NULL 0

#define R_f_MPI_DATATYPE_NULL 0

#define A_f_MPI_UB 3

#define R_f_MPI_UB 3

#define A_f_MPI_PACKED 2

#define R_f_MPI_PACKED 2

#define A_f_MPI_CHARACTER 5

#define R_f_MPI_CHARACTER 5

#define A_f_MPI_LB 4

#define R_f_MPI_LB 4

#define A_f_MPI_INTEGER 7

#define R_f_MPI_INTEGER 7

#define A_f_MPI_LOGICAL 6

#define R_f_MPI_LOGICAL 6

#define A_f_MPI_INTEGER2 9

#define R_f_MPI_INTEGER2 9

#define A_f_MPI_INTEGER1 8

#define R_f_MPI_INTEGER1 8

#define A_f_MPI_REAL4 14

#define R_f_MPI_REAL4 14

#define A_f_MPI_INTEGER4 10

#define R_f_MPI_INTEGER4 10

static inline void datatype_a2r(int *ca,int *cr){
if(A_f_MPI_2DOUBLE_PRECISION==*ca){
*cr=(int )R_f_MPI_2DOUBLE_PRECISION;return;}
else
if(A_f_MPI_2INTEGER==*ca){
*cr=(int )R_f_MPI_2INTEGER;return;}
else
if(A_f_MPI_REAL==*ca){
*cr=(int )R_f_MPI_REAL;return;}
else
if(A_f_MPI_REAL8==*ca){
*cr=(int )R_f_MPI_REAL8;return;}
else
if(A_f_MPI_DOUBLE_COMPLEX==*ca){
*cr=(int )R_f_MPI_DOUBLE_COMPLEX;return;}
else
if(A_f_MPI_DOUBLE_PRECISION==*ca){
*cr=(int )R_f_MPI_DOUBLE_PRECISION;return;}
else
if(A_f_MPI_2REAL==*ca){
*cr=(int )R_f_MPI_2REAL;return;}
else
if(A_f_MPI_COMPLEX==*ca){
*cr=(int )R_f_MPI_COMPLEX;return;}
else
if(A_f_MPI_BYTE==*ca){
*cr=(int )R_f_MPI_BYTE;return;}
else
if(A_f_MPI_DATATYPE_NULL==*ca){
*cr=(int )R_f_MPI_DATATYPE_NULL;return;}
else
if(A_f_MPI_UB==*ca){
*cr=(int )R_f_MPI_UB;return;}
else
if(A_f_MPI_PACKED==*ca){
*cr=(int )R_f_MPI_PACKED;return;}
else
if(A_f_MPI_CHARACTER==*ca){
*cr=(int )R_f_MPI_CHARACTER;return;}
else
if(A_f_MPI_LB==*ca){
*cr=(int )R_f_MPI_LB;return;}
else
if(A_f_MPI_INTEGER==*ca){
*cr=(int )R_f_MPI_INTEGER;return;}
else
if(A_f_MPI_LOGICAL==*ca){
*cr=(int )R_f_MPI_LOGICAL;return;}
else
if(A_f_MPI_INTEGER2==*ca){
*cr=(int )R_f_MPI_INTEGER2;return;}
else
if(A_f_MPI_INTEGER1==*ca){
*cr=(int )R_f_MPI_INTEGER1;return;}
else
if(A_f_MPI_REAL4==*ca){
*cr=(int )R_f_MPI_REAL4;return;}
else
if(A_f_MPI_INTEGER4==*ca){
*cr=(int )R_f_MPI_INTEGER4;return;}
else
datatype_translation_get_f(*ca,cr);
}

static inline void datatype_r2a(int *ca,int *cr){
if(R_f_MPI_2DOUBLE_PRECISION==*cr){
*ca=(int )A_f_MPI_2DOUBLE_PRECISION;return;}
else
if(R_f_MPI_2INTEGER==*cr){
*ca=(int )A_f_MPI_2INTEGER;return;}
else
if(R_f_MPI_REAL==*cr){
*ca=(int )A_f_MPI_REAL;return;}
else
if(R_f_MPI_REAL8==*cr){
*ca=(int )A_f_MPI_REAL8;return;}
else
if(R_f_MPI_DOUBLE_COMPLEX==*cr){
*ca=(int )A_f_MPI_DOUBLE_COMPLEX;return;}
else
if(R_f_MPI_DOUBLE_PRECISION==*cr){
*ca=(int )A_f_MPI_DOUBLE_PRECISION;return;}
else
if(R_f_MPI_2REAL==*cr){
*ca=(int )A_f_MPI_2REAL;return;}
else
if(R_f_MPI_COMPLEX==*cr){
*ca=(int )A_f_MPI_COMPLEX;return;}
else
if(R_f_MPI_BYTE==*cr){
*ca=(int )A_f_MPI_BYTE;return;}
else
if(R_f_MPI_DATATYPE_NULL==*cr){
*ca=(int )A_f_MPI_DATATYPE_NULL;return;}
else
if(R_f_MPI_UB==*cr){
*ca=(int )A_f_MPI_UB;return;}
else
if(R_f_MPI_PACKED==*cr){
*ca=(int )A_f_MPI_PACKED;return;}
else
if(R_f_MPI_CHARACTER==*cr){
*ca=(int )A_f_MPI_CHARACTER;return;}
else
if(R_f_MPI_LB==*cr){
*ca=(int )A_f_MPI_LB;return;}
else
if(R_f_MPI_INTEGER==*cr){
*ca=(int )A_f_MPI_INTEGER;return;}
else
if(R_f_MPI_LOGICAL==*cr){
*ca=(int )A_f_MPI_LOGICAL;return;}
else
if(R_f_MPI_INTEGER2==*cr){
*ca=(int )A_f_MPI_INTEGER2;return;}
else
if(R_f_MPI_INTEGER1==*cr){
*ca=(int )A_f_MPI_INTEGER1;return;}
else
if(R_f_MPI_REAL4==*cr){
*ca=(int )A_f_MPI_REAL4;return;}
else
if(R_f_MPI_INTEGER4==*cr){
*ca=(int )A_f_MPI_INTEGER4;return;}
else
datatype_translation_update_alloc_f(*cr,ca);

}
static inline void datatype_r2au(int *ca,int *cr){
if(R_f_MPI_2DOUBLE_PRECISION==*cr){
datatype_translation_del_f(*ca);*ca=(int )A_f_MPI_2DOUBLE_PRECISION;return;}
else
if(R_f_MPI_2INTEGER==*cr){
datatype_translation_del_f(*ca);*ca=(int )A_f_MPI_2INTEGER;return;}
else
if(R_f_MPI_REAL==*cr){
datatype_translation_del_f(*ca);*ca=(int )A_f_MPI_REAL;return;}
else
if(R_f_MPI_REAL8==*cr){
datatype_translation_del_f(*ca);*ca=(int )A_f_MPI_REAL8;return;}
else
if(R_f_MPI_DOUBLE_COMPLEX==*cr){
datatype_translation_del_f(*ca);*ca=(int )A_f_MPI_DOUBLE_COMPLEX;return;}
else
if(R_f_MPI_DOUBLE_PRECISION==*cr){
datatype_translation_del_f(*ca);*ca=(int )A_f_MPI_DOUBLE_PRECISION;return;}
else
if(R_f_MPI_2REAL==*cr){
datatype_translation_del_f(*ca);*ca=(int )A_f_MPI_2REAL;return;}
else
if(R_f_MPI_COMPLEX==*cr){
datatype_translation_del_f(*ca);*ca=(int )A_f_MPI_COMPLEX;return;}
else
if(R_f_MPI_BYTE==*cr){
datatype_translation_del_f(*ca);*ca=(int )A_f_MPI_BYTE;return;}
else
if(R_f_MPI_DATATYPE_NULL==*cr){
datatype_translation_del_f(*ca);*ca=(int )A_f_MPI_DATATYPE_NULL;return;}
else
if(R_f_MPI_UB==*cr){
datatype_translation_del_f(*ca);*ca=(int )A_f_MPI_UB;return;}
else
if(R_f_MPI_PACKED==*cr){
datatype_translation_del_f(*ca);*ca=(int )A_f_MPI_PACKED;return;}
else
if(R_f_MPI_CHARACTER==*cr){
datatype_translation_del_f(*ca);*ca=(int )A_f_MPI_CHARACTER;return;}
else
if(R_f_MPI_LB==*cr){
datatype_translation_del_f(*ca);*ca=(int )A_f_MPI_LB;return;}
else
if(R_f_MPI_INTEGER==*cr){
datatype_translation_del_f(*ca);*ca=(int )A_f_MPI_INTEGER;return;}
else
if(R_f_MPI_LOGICAL==*cr){
datatype_translation_del_f(*ca);*ca=(int )A_f_MPI_LOGICAL;return;}
else
if(R_f_MPI_INTEGER2==*cr){
datatype_translation_del_f(*ca);*ca=(int )A_f_MPI_INTEGER2;return;}
else
if(R_f_MPI_INTEGER1==*cr){
datatype_translation_del_f(*ca);*ca=(int )A_f_MPI_INTEGER1;return;}
else
if(R_f_MPI_REAL4==*cr){
datatype_translation_del_f(*ca);*ca=(int )A_f_MPI_REAL4;return;}
else
if(R_f_MPI_INTEGER4==*cr){
datatype_translation_del_f(*ca);*ca=(int )A_f_MPI_INTEGER4;return;}
else
datatype_translation_update_f(*cr,ca);

}
#define A_f_MPI_MAXLOC 11

#define R_f_MPI_MAXLOC 11

#define A_f_MPI_BXOR 10

#define R_f_MPI_BXOR 10

#define A_f_MPI_MINLOC 12

#define R_f_MPI_MINLOC 12

#define A_f_MPI_MAX 1

#define R_f_MPI_MAX 1

#define A_f_MPI_OP_NULL 0

#define R_f_MPI_OP_NULL 0

#define A_f_MPI_SUM 3

#define R_f_MPI_SUM 3

#define A_f_MPI_MIN 2

#define R_f_MPI_MIN 2

#define A_f_MPI_LAND 5

#define R_f_MPI_LAND 5

#define A_f_MPI_PROD 4

#define R_f_MPI_PROD 4

#define A_f_MPI_LOR 7

#define R_f_MPI_LOR 7

#define A_f_MPI_BAND 6

#define R_f_MPI_BAND 6

#define A_f_MPI_LXOR 9

#define R_f_MPI_LXOR 9

#define A_f_MPI_BOR 8

#define R_f_MPI_BOR 8

static inline void operator_a2r(int *ca,int *cr){
if(A_f_MPI_MAXLOC==*ca){
*cr=(int )R_f_MPI_MAXLOC;return;}
else
if(A_f_MPI_BXOR==*ca){
*cr=(int )R_f_MPI_BXOR;return;}
else
if(A_f_MPI_MINLOC==*ca){
*cr=(int )R_f_MPI_MINLOC;return;}
else
if(A_f_MPI_MAX==*ca){
*cr=(int )R_f_MPI_MAX;return;}
else
if(A_f_MPI_OP_NULL==*ca){
*cr=(int )R_f_MPI_OP_NULL;return;}
else
if(A_f_MPI_SUM==*ca){
*cr=(int )R_f_MPI_SUM;return;}
else
if(A_f_MPI_MIN==*ca){
*cr=(int )R_f_MPI_MIN;return;}
else
if(A_f_MPI_LAND==*ca){
*cr=(int )R_f_MPI_LAND;return;}
else
if(A_f_MPI_PROD==*ca){
*cr=(int )R_f_MPI_PROD;return;}
else
if(A_f_MPI_LOR==*ca){
*cr=(int )R_f_MPI_LOR;return;}
else
if(A_f_MPI_BAND==*ca){
*cr=(int )R_f_MPI_BAND;return;}
else
if(A_f_MPI_LXOR==*ca){
*cr=(int )R_f_MPI_LXOR;return;}
else
if(A_f_MPI_BOR==*ca){
*cr=(int )R_f_MPI_BOR;return;}
else
operation_translation_get_f(*ca,cr);
User_fct_g_ptr=get_user_fct(*cr);
}

static inline void operator_r2a(int *ca,int *cr){
if(R_f_MPI_MAXLOC==*cr){
*ca=(int )A_f_MPI_MAXLOC;return;}
else
if(R_f_MPI_BXOR==*cr){
*ca=(int )A_f_MPI_BXOR;return;}
else
if(R_f_MPI_MINLOC==*cr){
*ca=(int )A_f_MPI_MINLOC;return;}
else
if(R_f_MPI_MAX==*cr){
*ca=(int )A_f_MPI_MAX;return;}
else
if(R_f_MPI_OP_NULL==*cr){
*ca=(int )A_f_MPI_OP_NULL;return;}
else
if(R_f_MPI_SUM==*cr){
*ca=(int )A_f_MPI_SUM;return;}
else
if(R_f_MPI_MIN==*cr){
*ca=(int )A_f_MPI_MIN;return;}
else
if(R_f_MPI_LAND==*cr){
*ca=(int )A_f_MPI_LAND;return;}
else
if(R_f_MPI_PROD==*cr){
*ca=(int )A_f_MPI_PROD;return;}
else
if(R_f_MPI_LOR==*cr){
*ca=(int )A_f_MPI_LOR;return;}
else
if(R_f_MPI_BAND==*cr){
*ca=(int )A_f_MPI_BAND;return;}
else
if(R_f_MPI_LXOR==*cr){
*ca=(int )A_f_MPI_LXOR;return;}
else
if(R_f_MPI_BOR==*cr){
*ca=(int )A_f_MPI_BOR;return;}
else
operation_translation_update_alloc_f(*cr,ca);
add_user_fct(*cr);

}
static inline void operator_r2au(int *ca,int *cr){
if(R_f_MPI_MAXLOC==*cr){
operation_translation_del_f(*ca);*ca=(int )A_f_MPI_MAXLOC;return;}
else
if(R_f_MPI_BXOR==*cr){
operation_translation_del_f(*ca);*ca=(int )A_f_MPI_BXOR;return;}
else
if(R_f_MPI_MINLOC==*cr){
operation_translation_del_f(*ca);*ca=(int )A_f_MPI_MINLOC;return;}
else
if(R_f_MPI_MAX==*cr){
operation_translation_del_f(*ca);*ca=(int )A_f_MPI_MAX;return;}
else
if(R_f_MPI_OP_NULL==*cr){
operation_translation_del_f(*ca);*ca=(int )A_f_MPI_OP_NULL;return;}
else
if(R_f_MPI_SUM==*cr){
operation_translation_del_f(*ca);*ca=(int )A_f_MPI_SUM;return;}
else
if(R_f_MPI_MIN==*cr){
operation_translation_del_f(*ca);*ca=(int )A_f_MPI_MIN;return;}
else
if(R_f_MPI_LAND==*cr){
operation_translation_del_f(*ca);*ca=(int )A_f_MPI_LAND;return;}
else
if(R_f_MPI_PROD==*cr){
operation_translation_del_f(*ca);*ca=(int )A_f_MPI_PROD;return;}
else
if(R_f_MPI_LOR==*cr){
operation_translation_del_f(*ca);*ca=(int )A_f_MPI_LOR;return;}
else
if(R_f_MPI_BAND==*cr){
operation_translation_del_f(*ca);*ca=(int )A_f_MPI_BAND;return;}
else
if(R_f_MPI_LXOR==*cr){
operation_translation_del_f(*ca);*ca=(int )A_f_MPI_LXOR;return;}
else
if(R_f_MPI_BOR==*cr){
operation_translation_del_f(*ca);*ca=(int )A_f_MPI_BOR;return;}
else
operation_translation_update_f(*cr,ca);

}
#define A_f_MPI_ANY_SOURCE -1

#define R_f_MPI_ANY_SOURCE -1

#define A_f_MPI_PROC_NULL -2

#define R_f_MPI_PROC_NULL -2

static inline void source_a2r(int *ca,int *cr){
if(A_f_MPI_ANY_SOURCE==*ca){
*cr=(int )R_f_MPI_ANY_SOURCE;return;}
else
if(A_f_MPI_PROC_NULL==*ca){
*cr=(int )R_f_MPI_PROC_NULL;return;}
else
*cr=*ca;
}

static inline void source_r2a(int *ca,int *cr){
if(R_f_MPI_ANY_SOURCE==*cr){
*ca=(int )A_f_MPI_ANY_SOURCE;return;}
else
if(R_f_MPI_PROC_NULL==*cr){
*ca=(int )A_f_MPI_PROC_NULL;return;}
else
*ca=*cr;

}
#define A_f_MPI_ANY_TAG -1

#define R_f_MPI_ANY_TAG -1

static inline void tag_a2r(int *ca,int *cr){
if(A_f_MPI_ANY_TAG==*ca){
*cr=(int )R_f_MPI_ANY_TAG;return;}
else
*cr=*ca;
}

static inline void tag_r2a(int *ca,int *cr){
if(R_f_MPI_ANY_TAG==*cr){
*ca=(int )A_f_MPI_ANY_TAG;return;}
else
*ca=*cr;

}
#define A_f_MPI_REQUEST_NULL 0

#define R_f_MPI_REQUEST_NULL 0

static inline void request_a2r(int *ca,int *cr){
if(A_f_MPI_REQUEST_NULL==*ca){
*cr=(int )R_f_MPI_REQUEST_NULL;return;}
else
request_translation_get_f(*ca,cr);
}

static inline void request_r2a(int *ca,int *cr){
if(R_f_MPI_REQUEST_NULL==*cr){
*ca=(int )A_f_MPI_REQUEST_NULL;return;}
else
request_translation_update_alloc_f(*cr,ca);

}
static inline void request_r2au(int *ca,int *cr){
if(R_f_MPI_REQUEST_NULL==*cr){
request_translation_del_f(*ca);*ca=(int )A_f_MPI_REQUEST_NULL;return;}
else
request_translation_update_f(*cr,ca);

}
#define A_f_MPI_GROUP_EMPTY 1

#define R_f_MPI_GROUP_EMPTY 1

#define A_f_MPI_GROUP_NULL 0

#define R_f_MPI_GROUP_NULL 0

static inline void group_a2r(int *ca,int *cr){
if(A_f_MPI_GROUP_EMPTY==*ca){
*cr=(int )R_f_MPI_GROUP_EMPTY;return;}
else
if(A_f_MPI_GROUP_NULL==*ca){
*cr=(int )R_f_MPI_GROUP_NULL;return;}
else
group_translation_get_f(*ca,cr);
}

static inline void group_r2a(int *ca,int *cr){
if(R_f_MPI_GROUP_EMPTY==*cr){
*ca=(int )A_f_MPI_GROUP_EMPTY;return;}
else
if(R_f_MPI_GROUP_NULL==*cr){
*ca=(int )A_f_MPI_GROUP_NULL;return;}
else
group_translation_update_alloc_f(*cr,ca);

}
static inline void group_r2au(int *ca,int *cr){
if(R_f_MPI_GROUP_EMPTY==*cr){
group_translation_del_f(*ca);*ca=(int )A_f_MPI_GROUP_EMPTY;return;}
else
if(R_f_MPI_GROUP_NULL==*cr){
group_translation_del_f(*ca);*ca=(int )A_f_MPI_GROUP_NULL;return;}
else
group_translation_update_f(*cr,ca);

}
#define A_f_MPI_ERRORS_ARE_FATAL 1

#define R_f_MPI_ERRORS_ARE_FATAL 1

#define A_f_MPI_ERRHANDLER_NULL 0

#define R_f_MPI_ERRHANDLER_NULL 0

#define A_f_MPI_ERRORS_RETURN 2

#define R_f_MPI_ERRORS_RETURN 2

static inline void err_handler_a2r(int *ca,int *cr){
if(A_f_MPI_ERRORS_ARE_FATAL==*ca){
*cr=(int )R_f_MPI_ERRORS_ARE_FATAL;return;}
else
if(A_f_MPI_ERRHANDLER_NULL==*ca){
*cr=(int )R_f_MPI_ERRHANDLER_NULL;return;}
else
if(A_f_MPI_ERRORS_RETURN==*ca){
*cr=(int )R_f_MPI_ERRORS_RETURN;return;}
else
errhandler_translation_get_f(*ca,cr);
}

static inline void err_handler_r2a(int *ca,int *cr){
if(R_f_MPI_ERRORS_ARE_FATAL==*cr){
*ca=(int )A_f_MPI_ERRORS_ARE_FATAL;return;}
else
if(R_f_MPI_ERRHANDLER_NULL==*cr){
*ca=(int )A_f_MPI_ERRHANDLER_NULL;return;}
else
if(R_f_MPI_ERRORS_RETURN==*cr){
*ca=(int )A_f_MPI_ERRORS_RETURN;return;}
else
errhandler_translation_update_alloc_f(*cr,ca);

}
static inline void err_handler_r2au(int *ca,int *cr){
if(R_f_MPI_ERRORS_ARE_FATAL==*cr){
errhandler_translation_del_f(*ca);*ca=(int )A_f_MPI_ERRORS_ARE_FATAL;return;}
else
if(R_f_MPI_ERRHANDLER_NULL==*cr){
errhandler_translation_del_f(*ca);*ca=(int )A_f_MPI_ERRHANDLER_NULL;return;}
else
if(R_f_MPI_ERRORS_RETURN==*cr){
errhandler_translation_del_f(*ca);*ca=(int )A_f_MPI_ERRORS_RETURN;return;}
else
errhandler_translation_update_f(*cr,ca);

}
#define A_f_MPI_CART 1

#define R_f_MPI_CART 1

#define A_f_MPI_GRAPH 2

#define R_f_MPI_GRAPH 2

#define A_f_MPI_UNDEFINED -32766

#define R_f_MPI_UNDEFINED -32766

static inline void topo_status_a2r(int *ca,int *cr){
if(A_f_MPI_CART==*ca){
*cr=(int )R_f_MPI_CART;return;}
else
if(A_f_MPI_GRAPH==*ca){
*cr=(int )R_f_MPI_GRAPH;return;}
else
if(A_f_MPI_UNDEFINED==*ca){
*cr=(int )R_f_MPI_UNDEFINED;return;}
else
*cr=*ca;
}

static inline void topo_status_r2a(int *ca,int *cr){
if(R_f_MPI_CART==*cr){
*ca=(int )A_f_MPI_CART;return;}
else
if(R_f_MPI_GRAPH==*cr){
*ca=(int )A_f_MPI_GRAPH;return;}
else
if(R_f_MPI_UNDEFINED==*cr){
*ca=(int )A_f_MPI_UNDEFINED;return;}
else
*ca=*cr;

}
#define A_f_MPI_MAXLOC 11

#define R_f_MPI_MAXLOC 11

#define A_f_MPI_BXOR 10

#define R_f_MPI_BXOR 10

#define A_f_MPI_MINLOC 12

#define R_f_MPI_MINLOC 12

#define A_f_MPI_MAX 1

#define R_f_MPI_MAX 1

#define A_f_MPI_OP_NULL 0

#define R_f_MPI_OP_NULL 0

#define A_f_MPI_SUM 3

#define R_f_MPI_SUM 3

#define A_f_MPI_MIN 2

#define R_f_MPI_MIN 2

#define A_f_MPI_LAND 5

#define R_f_MPI_LAND 5

#define A_f_MPI_PROD 4

#define R_f_MPI_PROD 4

#define A_f_MPI_LOR 7

#define R_f_MPI_LOR 7

#define A_f_MPI_BAND 6

#define R_f_MPI_BAND 6

#define A_f_MPI_LXOR 9

#define R_f_MPI_LXOR 9

#define A_f_MPI_BOR 8

#define R_f_MPI_BOR 8

static inline void operator_del_a2r(int *ca,int *cr){
if(A_f_MPI_MAXLOC==*ca){
*cr=(int )R_f_MPI_MAXLOC;return;}
else
if(A_f_MPI_BXOR==*ca){
*cr=(int )R_f_MPI_BXOR;return;}
else
if(A_f_MPI_MINLOC==*ca){
*cr=(int )R_f_MPI_MINLOC;return;}
else
if(A_f_MPI_MAX==*ca){
*cr=(int )R_f_MPI_MAX;return;}
else
if(A_f_MPI_OP_NULL==*ca){
*cr=(int )R_f_MPI_OP_NULL;return;}
else
if(A_f_MPI_SUM==*ca){
*cr=(int )R_f_MPI_SUM;return;}
else
if(A_f_MPI_MIN==*ca){
*cr=(int )R_f_MPI_MIN;return;}
else
if(A_f_MPI_LAND==*ca){
*cr=(int )R_f_MPI_LAND;return;}
else
if(A_f_MPI_PROD==*ca){
*cr=(int )R_f_MPI_PROD;return;}
else
if(A_f_MPI_LOR==*ca){
*cr=(int )R_f_MPI_LOR;return;}
else
if(A_f_MPI_BAND==*ca){
*cr=(int )R_f_MPI_BAND;return;}
else
if(A_f_MPI_LXOR==*ca){
*cr=(int )R_f_MPI_LXOR;return;}
else
if(A_f_MPI_BOR==*ca){
*cr=(int )R_f_MPI_BOR;return;}
else
operation_translation_get_f(*ca,cr);
del_usr_fct(*cr);
}

static inline void operator_del_r2a(int *ca,int *cr){
if(R_f_MPI_MAXLOC==*cr){
*ca=(int )A_f_MPI_MAXLOC;return;}
else
if(R_f_MPI_BXOR==*cr){
*ca=(int )A_f_MPI_BXOR;return;}
else
if(R_f_MPI_MINLOC==*cr){
*ca=(int )A_f_MPI_MINLOC;return;}
else
if(R_f_MPI_MAX==*cr){
*ca=(int )A_f_MPI_MAX;return;}
else
if(R_f_MPI_OP_NULL==*cr){
*ca=(int )A_f_MPI_OP_NULL;return;}
else
if(R_f_MPI_SUM==*cr){
*ca=(int )A_f_MPI_SUM;return;}
else
if(R_f_MPI_MIN==*cr){
*ca=(int )A_f_MPI_MIN;return;}
else
if(R_f_MPI_LAND==*cr){
*ca=(int )A_f_MPI_LAND;return;}
else
if(R_f_MPI_PROD==*cr){
*ca=(int )A_f_MPI_PROD;return;}
else
if(R_f_MPI_LOR==*cr){
*ca=(int )A_f_MPI_LOR;return;}
else
if(R_f_MPI_BAND==*cr){
*ca=(int )A_f_MPI_BAND;return;}
else
if(R_f_MPI_LXOR==*cr){
*ca=(int )A_f_MPI_LXOR;return;}
else
if(R_f_MPI_BOR==*cr){
*ca=(int )A_f_MPI_BOR;return;}
else
operation_translation_update_alloc_f(*cr,ca);

}
static inline void operator_del_r2au(int *ca,int *cr){
if(R_f_MPI_MAXLOC==*cr){
operation_translation_del_f(*ca);*ca=(int )A_f_MPI_MAXLOC;return;}
else
if(R_f_MPI_BXOR==*cr){
operation_translation_del_f(*ca);*ca=(int )A_f_MPI_BXOR;return;}
else
if(R_f_MPI_MINLOC==*cr){
operation_translation_del_f(*ca);*ca=(int )A_f_MPI_MINLOC;return;}
else
if(R_f_MPI_MAX==*cr){
operation_translation_del_f(*ca);*ca=(int )A_f_MPI_MAX;return;}
else
if(R_f_MPI_OP_NULL==*cr){
operation_translation_del_f(*ca);*ca=(int )A_f_MPI_OP_NULL;return;}
else
if(R_f_MPI_SUM==*cr){
operation_translation_del_f(*ca);*ca=(int )A_f_MPI_SUM;return;}
else
if(R_f_MPI_MIN==*cr){
operation_translation_del_f(*ca);*ca=(int )A_f_MPI_MIN;return;}
else
if(R_f_MPI_LAND==*cr){
operation_translation_del_f(*ca);*ca=(int )A_f_MPI_LAND;return;}
else
if(R_f_MPI_PROD==*cr){
operation_translation_del_f(*ca);*ca=(int )A_f_MPI_PROD;return;}
else
if(R_f_MPI_LOR==*cr){
operation_translation_del_f(*ca);*ca=(int )A_f_MPI_LOR;return;}
else
if(R_f_MPI_BAND==*cr){
operation_translation_del_f(*ca);*ca=(int )A_f_MPI_BAND;return;}
else
if(R_f_MPI_LXOR==*cr){
operation_translation_del_f(*ca);*ca=(int )A_f_MPI_LXOR;return;}
else
if(R_f_MPI_BOR==*cr){
operation_translation_del_f(*ca);*ca=(int )A_f_MPI_BOR;return;}
else
operation_translation_update_f(*cr,ca);

}
static inline void delete_ptr_converter_a2r(void **ca,void **cr){
*cr=*ca;
}

static inline void delete_ptr_converter_r2a(void **ca,void **cr){
*ca=*cr;

}
#define A_f_MPI_ERRORS_ARE_FATAL 1

#define R_f_MPI_ERRORS_ARE_FATAL 1

#define A_f_MPI_ERRHANDLER_NULL 0

#define R_f_MPI_ERRHANDLER_NULL 0

#define A_f_MPI_ERRORS_RETURN 2

#define R_f_MPI_ERRORS_RETURN 2

static inline void errhandler_converter_a2r(int *ca,int *cr){
if(A_f_MPI_ERRORS_ARE_FATAL==*ca){
*cr=(int )R_f_MPI_ERRORS_ARE_FATAL;return;}
else
if(A_f_MPI_ERRHANDLER_NULL==*ca){
*cr=(int )R_f_MPI_ERRHANDLER_NULL;return;}
else
if(A_f_MPI_ERRORS_RETURN==*ca){
*cr=(int )R_f_MPI_ERRORS_RETURN;return;}
else
errhandler_translation_get_f(*ca,cr);
}

static inline void errhandler_converter_r2a(int *ca,int *cr){
if(R_f_MPI_ERRORS_ARE_FATAL==*cr){
*ca=(int )A_f_MPI_ERRORS_ARE_FATAL;return;}
else
if(R_f_MPI_ERRHANDLER_NULL==*cr){
*ca=(int )A_f_MPI_ERRHANDLER_NULL;return;}
else
if(R_f_MPI_ERRORS_RETURN==*cr){
*ca=(int )A_f_MPI_ERRORS_RETURN;return;}
else
errhandler_translation_update_alloc_f(*cr,ca);

}
static inline void errhandler_converter_r2au(int *ca,int *cr){
if(R_f_MPI_ERRORS_ARE_FATAL==*cr){
errhandler_translation_del_f(*ca);*ca=(int )A_f_MPI_ERRORS_ARE_FATAL;return;}
else
if(R_f_MPI_ERRHANDLER_NULL==*cr){
errhandler_translation_del_f(*ca);*ca=(int )A_f_MPI_ERRHANDLER_NULL;return;}
else
if(R_f_MPI_ERRORS_RETURN==*cr){
errhandler_translation_del_f(*ca);*ca=(int )A_f_MPI_ERRORS_RETURN;return;}
else
errhandler_translation_update_f(*cr,ca);

}
#define A_f_MPI_HOST 1

#define R_f_MPI_HOST 1

#define A_f_MPI_TAG_UB 0

#define R_f_MPI_TAG_UB 0

#define A_f_MPI_WTIME_IS_GLOBAL 3

#define R_f_MPI_WTIME_IS_GLOBAL 3

#define A_f_MPI_IO 2

#define R_f_MPI_IO 2

#define A_f_MPI_KEYVAL_INVALID -1

#define R_f_MPI_KEYVAL_INVALID -1

#define A_f_MPI_APPNUM 4

#define R_f_MPI_APPNUM 4

#define A_f_MPI_WIN_BASE 7

#define R_f_MPI_WIN_BASE 7

#define A_f_MPI_UNIVERSE_SIZE 6

#define R_f_MPI_UNIVERSE_SIZE 6

#define A_f_MPI_WIN_DISP_UNIT 9

#define R_f_MPI_WIN_DISP_UNIT 9

#define A_f_MPI_LASTUSEDCODE 5

#define R_f_MPI_LASTUSEDCODE 5

#define A_f_MPI_WIN_SIZE 8

#define R_f_MPI_WIN_SIZE 8

static inline void keyval_a2r(int *ca,int *cr){
if(A_f_MPI_HOST==*ca){
*cr=(int )R_f_MPI_HOST;return;}
else
if(A_f_MPI_TAG_UB==*ca){
*cr=(int )R_f_MPI_TAG_UB;return;}
else
if(A_f_MPI_WTIME_IS_GLOBAL==*ca){
*cr=(int )R_f_MPI_WTIME_IS_GLOBAL;return;}
else
if(A_f_MPI_IO==*ca){
*cr=(int )R_f_MPI_IO;return;}
else
if(A_f_MPI_KEYVAL_INVALID==*ca){
*cr=(int )R_f_MPI_KEYVAL_INVALID;return;}
else
if(A_f_MPI_APPNUM==*ca){
*cr=(int )R_f_MPI_APPNUM;return;}
else
if(A_f_MPI_WIN_BASE==*ca){
*cr=(int )R_f_MPI_WIN_BASE;return;}
else
if(A_f_MPI_UNIVERSE_SIZE==*ca){
*cr=(int )R_f_MPI_UNIVERSE_SIZE;return;}
else
if(A_f_MPI_WIN_DISP_UNIT==*ca){
*cr=(int )R_f_MPI_WIN_DISP_UNIT;return;}
else
if(A_f_MPI_LASTUSEDCODE==*ca){
*cr=(int )R_f_MPI_LASTUSEDCODE;return;}
else
if(A_f_MPI_WIN_SIZE==*ca){
*cr=(int )R_f_MPI_WIN_SIZE;return;}
else
keyval_translation_get_f(*ca,cr);
}

static inline void keyval_r2a(int *ca,int *cr){
if(R_f_MPI_HOST==*cr){
*ca=(int )A_f_MPI_HOST;return;}
else
if(R_f_MPI_TAG_UB==*cr){
*ca=(int )A_f_MPI_TAG_UB;return;}
else
if(R_f_MPI_WTIME_IS_GLOBAL==*cr){
*ca=(int )A_f_MPI_WTIME_IS_GLOBAL;return;}
else
if(R_f_MPI_IO==*cr){
*ca=(int )A_f_MPI_IO;return;}
else
if(R_f_MPI_KEYVAL_INVALID==*cr){
*ca=(int )A_f_MPI_KEYVAL_INVALID;return;}
else
if(R_f_MPI_APPNUM==*cr){
*ca=(int )A_f_MPI_APPNUM;return;}
else
if(R_f_MPI_WIN_BASE==*cr){
*ca=(int )A_f_MPI_WIN_BASE;return;}
else
if(R_f_MPI_UNIVERSE_SIZE==*cr){
*ca=(int )A_f_MPI_UNIVERSE_SIZE;return;}
else
if(R_f_MPI_WIN_DISP_UNIT==*cr){
*ca=(int )A_f_MPI_WIN_DISP_UNIT;return;}
else
if(R_f_MPI_LASTUSEDCODE==*cr){
*ca=(int )A_f_MPI_LASTUSEDCODE;return;}
else
if(R_f_MPI_WIN_SIZE==*cr){
*ca=(int )A_f_MPI_WIN_SIZE;return;}
else
keyval_translation_update_alloc_f(*cr,ca);

}
static inline void keyval_r2au(int *ca,int *cr){
if(R_f_MPI_HOST==*cr){
keyval_translation_del_f(*ca);*ca=(int )A_f_MPI_HOST;return;}
else
if(R_f_MPI_TAG_UB==*cr){
keyval_translation_del_f(*ca);*ca=(int )A_f_MPI_TAG_UB;return;}
else
if(R_f_MPI_WTIME_IS_GLOBAL==*cr){
keyval_translation_del_f(*ca);*ca=(int )A_f_MPI_WTIME_IS_GLOBAL;return;}
else
if(R_f_MPI_IO==*cr){
keyval_translation_del_f(*ca);*ca=(int )A_f_MPI_IO;return;}
else
if(R_f_MPI_KEYVAL_INVALID==*cr){
keyval_translation_del_f(*ca);*ca=(int )A_f_MPI_KEYVAL_INVALID;return;}
else
if(R_f_MPI_APPNUM==*cr){
keyval_translation_del_f(*ca);*ca=(int )A_f_MPI_APPNUM;return;}
else
if(R_f_MPI_WIN_BASE==*cr){
keyval_translation_del_f(*ca);*ca=(int )A_f_MPI_WIN_BASE;return;}
else
if(R_f_MPI_UNIVERSE_SIZE==*cr){
keyval_translation_del_f(*ca);*ca=(int )A_f_MPI_UNIVERSE_SIZE;return;}
else
if(R_f_MPI_WIN_DISP_UNIT==*cr){
keyval_translation_del_f(*ca);*ca=(int )A_f_MPI_WIN_DISP_UNIT;return;}
else
if(R_f_MPI_LASTUSEDCODE==*cr){
keyval_translation_del_f(*ca);*ca=(int )A_f_MPI_LASTUSEDCODE;return;}
else
if(R_f_MPI_WIN_SIZE==*cr){
keyval_translation_del_f(*ca);*ca=(int )A_f_MPI_WIN_SIZE;return;}
else
keyval_translation_update_f(*cr,ca);

}
#define A_f_MPI_ANY_SOURCE -1

#define R_f_MPI_ANY_SOURCE -1

#define A_f_MPI_PROC_NULL -2

#define R_f_MPI_PROC_NULL -2

static inline void rank_mapper_a2r(int *ca,int *cr){
if(A_f_MPI_ANY_SOURCE==*ca){
*cr=(int )R_f_MPI_ANY_SOURCE;return;}
else
if(A_f_MPI_PROC_NULL==*ca){
*cr=(int )R_f_MPI_PROC_NULL;return;}
else
*cr=*ca;
}

static inline void rank_mapper_r2a(int *ca,int *cr){
if(R_f_MPI_ANY_SOURCE==*cr){
*ca=(int )A_f_MPI_ANY_SOURCE;return;}
else
if(R_f_MPI_PROC_NULL==*cr){
*ca=(int )A_f_MPI_PROC_NULL;return;}
else
*ca=*cr;

}
#define A_f_MPI_INFO_NULL 0

#define R_f_MPI_INFO_NULL 0

static inline void info_a2r(int *ca,int *cr){
if(A_f_MPI_INFO_NULL==*ca){
*cr=(int )R_f_MPI_INFO_NULL;return;}
else
info_translation_get_f(*ca,cr);
}

static inline void info_r2a(int *ca,int *cr){
if(R_f_MPI_INFO_NULL==*cr){
*ca=(int )A_f_MPI_INFO_NULL;return;}
else
info_translation_update_alloc_f(*cr,ca);

}
static inline void info_r2au(int *ca,int *cr){
if(R_f_MPI_INFO_NULL==*cr){
info_translation_del_f(*ca);*ca=(int )A_f_MPI_INFO_NULL;return;}
else
info_translation_update_f(*cr,ca);

}
#define A_f_MPI_ORDER_FORTRAN 1

#define R_f_MPI_ORDER_FORTRAN 1

#define A_f_MPI_ORDER_C 0

#define R_f_MPI_ORDER_C 0

static inline void order_a2r(int *ca,int *cr){
if(A_f_MPI_ORDER_FORTRAN==*ca){
*cr=(int )R_f_MPI_ORDER_FORTRAN;return;}
else
if(A_f_MPI_ORDER_C==*ca){
*cr=(int )R_f_MPI_ORDER_C;return;}
else
*cr=*ca;
}

static inline void order_r2a(int *ca,int *cr){
if(R_f_MPI_ORDER_FORTRAN==*cr){
*ca=(int )A_f_MPI_ORDER_FORTRAN;return;}
else
if(R_f_MPI_ORDER_C==*cr){
*ca=(int )A_f_MPI_ORDER_C;return;}
else
*ca=*cr;

}
#define A_f_MPI_DISTRIBUTE_CYCLIC 1

#define R_f_MPI_DISTRIBUTE_CYCLIC 1

#define A_f_MPI_DISTRIBUTE_BLOCK 0

#define R_f_MPI_DISTRIBUTE_BLOCK 0

#define A_f_MPI_DISTRIBUTE_NONE 2

#define R_f_MPI_DISTRIBUTE_NONE 2

#define A_f_MPI_DISTRIBUTE_DFLT_DARG -1

#define R_f_MPI_DISTRIBUTE_DFLT_DARG -1

static inline void order2_a2r(int *ca,int *cr){
if(A_f_MPI_DISTRIBUTE_CYCLIC==*ca){
*cr=(int )R_f_MPI_DISTRIBUTE_CYCLIC;return;}
else
if(A_f_MPI_DISTRIBUTE_BLOCK==*ca){
*cr=(int )R_f_MPI_DISTRIBUTE_BLOCK;return;}
else
if(A_f_MPI_DISTRIBUTE_NONE==*ca){
*cr=(int )R_f_MPI_DISTRIBUTE_NONE;return;}
else
if(A_f_MPI_DISTRIBUTE_DFLT_DARG==*ca){
*cr=(int )R_f_MPI_DISTRIBUTE_DFLT_DARG;return;}
else
*cr=*ca;
}

static inline void order2_r2a(int *ca,int *cr){
if(R_f_MPI_DISTRIBUTE_CYCLIC==*cr){
*ca=(int )A_f_MPI_DISTRIBUTE_CYCLIC;return;}
else
if(R_f_MPI_DISTRIBUTE_BLOCK==*cr){
*ca=(int )A_f_MPI_DISTRIBUTE_BLOCK;return;}
else
if(R_f_MPI_DISTRIBUTE_NONE==*cr){
*ca=(int )A_f_MPI_DISTRIBUTE_NONE;return;}
else
if(R_f_MPI_DISTRIBUTE_DFLT_DARG==*cr){
*ca=(int )A_f_MPI_DISTRIBUTE_DFLT_DARG;return;}
else
*ca=*cr;

}
#define A_f_MPI_LOCK_EXCLUSIVE 1

#define R_f_MPI_LOCK_EXCLUSIVE 1

#define A_f_MPI_LOCK_SHARED 2

#define R_f_MPI_LOCK_SHARED 2

static inline void win_lock_a2r(int *ca,int *cr){
if(A_f_MPI_LOCK_EXCLUSIVE==*ca){
*cr=(int )R_f_MPI_LOCK_EXCLUSIVE;return;}
else
if(A_f_MPI_LOCK_SHARED==*ca){
*cr=(int )R_f_MPI_LOCK_SHARED;return;}
else
*cr=*ca;
}

static inline void win_lock_r2a(int *ca,int *cr){
if(R_f_MPI_LOCK_EXCLUSIVE==*cr){
*ca=(int )A_f_MPI_LOCK_EXCLUSIVE;return;}
else
if(R_f_MPI_LOCK_SHARED==*cr){
*ca=(int )A_f_MPI_LOCK_SHARED;return;}
else
*ca=*cr;

}
#define A_f_MPI_WIN_NULL 0

#define R_f_MPI_WIN_NULL 0

static inline void fwin_a2r(int *ca,int *cr){
if(A_f_MPI_WIN_NULL==*ca){
*cr=(int )R_f_MPI_WIN_NULL;return;}
else
win_translation_get_f(*ca,cr);
}

static inline void fwin_r2a(int *ca,int *cr){
if(R_f_MPI_WIN_NULL==*cr){
*ca=(int )A_f_MPI_WIN_NULL;return;}
else
win_translation_update_alloc_f(*cr,ca);

}
static inline void fwin_r2au(int *ca,int *cr){
if(R_f_MPI_WIN_NULL==*cr){
win_translation_del_f(*ca);*ca=(int )A_f_MPI_WIN_NULL;return;}
else
win_translation_update_f(*cr,ca);

}
#define A_f_MPI_MESSAGE_NO_PROC 1

#define R_f_MPI_MESSAGE_NO_PROC 1

#define A_f_MPI_MESSAGE_NULL 0

#define R_f_MPI_MESSAGE_NULL 0

static inline void message_a2r(int *ca,int *cr){
if(A_f_MPI_MESSAGE_NO_PROC==*ca){
*cr=(int )R_f_MPI_MESSAGE_NO_PROC;return;}
else
if(A_f_MPI_MESSAGE_NULL==*ca){
*cr=(int )R_f_MPI_MESSAGE_NULL;return;}
else
message_translation_get_f(*ca,cr);
}

static inline void message_r2a(int *ca,int *cr){
if(R_f_MPI_MESSAGE_NO_PROC==*cr){
*ca=(int )A_f_MPI_MESSAGE_NO_PROC;return;}
else
if(R_f_MPI_MESSAGE_NULL==*cr){
*ca=(int )A_f_MPI_MESSAGE_NULL;return;}
else
message_translation_update_alloc_f(*cr,ca);

}
static inline void message_r2au(int *ca,int *cr){
if(R_f_MPI_MESSAGE_NO_PROC==*cr){
message_translation_del_f(*ca);*ca=(int )A_f_MPI_MESSAGE_NO_PROC;return;}
else
if(R_f_MPI_MESSAGE_NULL==*cr){
message_translation_del_f(*ca);*ca=(int )A_f_MPI_MESSAGE_NULL;return;}
else
message_translation_update_f(*cr,ca);

}
#define A_f_MPI_FILE_NULL 0

#define R_f_MPI_FILE_NULL 0

static inline void file_a2r(int *ca,int *cr){
if(A_f_MPI_FILE_NULL==*ca){
*cr=(int )R_f_MPI_FILE_NULL;return;}
else
file_translation_get_f(*ca,cr);
}

static inline void file_r2a(int *ca,int *cr){
if(R_f_MPI_FILE_NULL==*cr){
*ca=(int )A_f_MPI_FILE_NULL;return;}
else
file_translation_update_alloc_f(*cr,ca);

}
static inline void file_r2au(int *ca,int *cr){
if(R_f_MPI_FILE_NULL==*cr){
file_translation_del_f(*ca);*ca=(int )A_f_MPI_FILE_NULL;return;}
else
file_translation_update_f(*cr,ca);

}
 #define A_f_MPI_STATUS_SIZE           6
 #define A_f_MPI_SOURCE           1
 #define A_f_MPI_TAG           2
 #define A_f_MPI_ERROR           3

 #define R_f_MPI_STATUS_SIZE           6
 #define R_f_MPI_SOURCE           1
 #define R_f_MPI_TAG           2
 #define R_f_MPI_ERROR           3

#include "manual_wrapper.h"
#endif

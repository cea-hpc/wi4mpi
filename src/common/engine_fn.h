//############################# Wi4MPI License ###########################
//# `04/04/2016`                                                         #
//# Copyright or (C) or Copr. Commissariat a l'Energie Atomique          #
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


/*
 * This file contains hashtables for user functions.
 * These functions are used for errhandler functions
 * and user functions for MPI_Op.
 * For each entry in these hashtables, key is
 * application side MPI structure corresponding
 * to the function (e.g.: A_MPI_Op for user operation
 * function) and value is the corresponding function
 * pointer.
 *
 * name##_fn_translation_get
 * Args:
 *   keytype key: Application corresponding structure
 *   (input)
 *   valuetype* value: Corresponding user function
 *   (output)
 * Return: void
 * This function will search key in the hashtable and
 * set value to the corresponding value. An assert is
 * made if key is not found.
 * This function should be called when a call to the
 * wrapper function is made.
 *
 * name##_fn_translation_update
 * Args:
 *   keytype key: Application corresponding structure
 *   (input)
 *   valuetype value: Corresponding user function
 *   (input)
 * Return: void
 * This function will update the entry specified by
 * key argument. If no entry exists for this argument,
 * a new entry is created.
 * This function should be called when user specifies
 * a user function (e.g.: MPI_Op_create)
 *
 * name##_fn_translation_del
 * Args:
 *   keytype key: Application corresponding structure
 *   (input)
 * Return: void
 * This function will delete entry specified by key.
 *
 * name##_fn_free_all
 * No argument, returns void
 * This function will delete all entries of the
 * hashtable.
 * This function should be called at MPI_Finalize.
 *
 */


#ifndef NEW_UTILS_FN_H
#define NEW_UTILS_FN_H

/*#include <mpi.h>
#include <mpi_app.h>
#ifdef FORTRAN
#include <mpif_app.h>
#endif*/

#include "run_mpi.h"
#include "app_mpi.h"

#include <assert.h>
#include <limits.h>
#include <string.h>
#include "uthash.h"
//#include "thread_safety.h"
//#include <config.h>

#define HASHTABLE_OPTI_FN_HEADER(keytype, valuetype, name) \
typedef struct { \
  keytype key; \
  valuetype value; \
  int ref;  \
  UT_hash_handle hh; \
} name##_fn_translation_t; \
  \
void name##_fn_translation_get(keytype key, valuetype* value); \
void name##_fn_translation_update(keytype key, valuetype value); \
void name##_fn_translation_del(keytype key); \
void name##_translation_fn_init(); \
void name##_fn_translation_free_all();

HASHTABLE_OPTI_FN_HEADER(int, void *, errhandler_f)
HASHTABLE_OPTI_FN_HEADER(int , void *, operator)
HASHTABLE_OPTI_FN_HEADER(int , void *, communicator_f)

HASHTABLE_OPTI_FN_HEADER(A_MPI_Errhandler, A_MPI_Handler_function*, errhandler)
HASHTABLE_OPTI_FN_HEADER(A_MPI_Op, A_MPI_User_function*, operation)
#if WRAPPER_MPI_VERSION > 21
HASHTABLE_OPTI_FN_HEADER(A_MPI_Comm, A_MPI_Comm_errhandler_fn*, communicator)
#else
HASHTABLE_OPTI_FN_HEADER(A_MPI_Comm, A_MPI_Handler_function*, communicator)
#endif

//#if WRAPPER_MPI_VERSION > 21
HASHTABLE_OPTI_FN_HEADER(A_MPI_File, A_MPI_File_errhandler_fn*, file)
//#endif

#endif

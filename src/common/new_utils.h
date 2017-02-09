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



/*
 *  This file contains all functions used for hastables.
 *  2 versions are possible :
 *     * Application side structures are large enough to
 *       directly contain corresponding OpenMPI data
 *     * Application side structures are not enough large
 *       A hashtable is created where keys are truncated
 *       structure adresses : OPTI
 *       (e.g. : key = (A_MPI_Comm) a_comm, where a_comm
 *       is a pointer to MPI_Comm in the application)
 *       and values are OpenMPI corresponding data :
 *       NO_OPTI
 *  This method works because MPI structure internal
 *  behavior is masked to MPI user.
 */

#ifndef NEW_UTILS_H
#define NEW_UTILS_H
//#include <mpi.h>
//#include <mpi_app.h>
#include "run_mpi.h"
#include "app_mpi.h"
#include "optimisation.h"
/*#ifdef FORTRAN
#include <mpif_app.h>
#endif*/
#include <assert.h>
#include <limits.h>
#include <string.h>
#include "uthash.h"
#include "thread_safety.h"

//#include <config.h>

/*
 *  Function prototypes are the same between the 2
 *  versions, so that functions calls are the same.
 *
 *  These functions are :
 *      varname##_translation_add_const :
 *      Args :
 *        A_##type a_mpi_##varname : Application side
 *        corresponding constant (input)
 *        type mpi_##varname : OpenMPI corresponding
 *        constant (input)
 *      Returns : void
 *      Add a MPI constant in a hashtable. This hashtable
 *      exists in the two versions and will allow to detect
 *      if the structure is a MPI constant such as
 *      MPI_COMM_WORLD.
 *      This function should be called at MPI_Init
 *
 *      varname##_translation_is_const :
 *      Args :
 *        A_##type a_mpi##varname : Application side
 *        variable (input)
 *      Returns : boolean : 1 if variable is a
 *      constant, 0 if not.
 *      This function will search in the MPI constant
 *      hashtable if the variable is present.
 *
 *      varname##_translation_get :
 *      Args :
 *        A_##type a_mpi_##varname : Application side
 *        variable (input)
 *        type *mpi_##varname : Pointer to OpenMPI side
 *        corresponding value (output)
 *      Returns : void, will assert if not found.
 *      In the OPTI case, this function will simply perform
 *      a memcpy from application side to OpenMPI side
 *      In the NO_OPTI case, this function will search the
 *      corresponding entry in the hashtables. If it is not
 *      found, function will assert. Value will be set in
 *      the mpi_##varname via memcpy.
 *      This function should be used when a MPI structure is
 *      set as an input of the function (e.g. : MPI_Comm in
 *      function MPI_Comm_size)
 *
 *      varname##_translation_get_key_from_value :
 *      Args :
 *        type mpi_##varname : OpenMPI side variable (input)
 *        A_##type *a_mpi_##varname : Pointer to application
 *        side corresponding key (output)
 *      Returns : void, assert if not found
 *      This function will give the corresponding key for
 *      a OpenMPI value. This function may give strange
 *      results when used with another value than a constant
 *      (as we don't know internal behavior of a structure in
 *      the application side)
 *      In the NO_OPTI case, function will assert if the value
 *      is not found in the hashtables.
 *      This function should be used when using a user function
 *      (e.g. : when MPI user creates a
 *      MPI_Comm_copy_attr_function, wrapper will instead give
 *      an internal function to OpenMPI, and when this function
 *      is called, application side MPI variable are retieved
 *      via this function, and the actual call to the user
 *      function can be performed).
 *
 *      varname##_translation_update :
 *      Args :
 *        A_##type *a_mpi_varname : Pointer to application side
 *        variable to update (input/output)
 *        type mpi_##varname : OpenMPI corresponding value (input)
 *      Returns : void
 *      Depending if OPTI or NO_OPTI, this function has different
 *      behaviors :
 *          OPTI :
 *          Function will check if OpenMPI variable is a constant.
 *          If it is the case, a memcpy is done to set application
 *          variable to application corresponding constant.
 *          Else, a memcpy is done to store OpenMPI data in this
 *          application structure.
 *          NO_OPTI :
 *          Function will check if OpenMPI variable is a constant.
 *          If it is the case, a memcpy is done to set application
 *          variable to application corresponding constant.
 *          Else, if an entry corresponding to this variable
 *          already exists in the hashtable, value is changed in
 *          the hashtable into the OpenMPI given argument.
 *          If no entry exists for this application variable, a
 *          new entry is created. Key is a truncated value of the
 *          application structure adress, value is the given
 *          OpenMPI corresponding value argument.
 *      This function should be called when the MPI variable is an
 *      output (e.g. : Argument MPI_Datatype *newtype of
 *      MPI_Type_create_struct function)
 *
 *
 *      varname##_translation_del :
 *      Args:
 *         A_##type *a_mpi_##varname : Pointer to application side
 *         variable to delete
 *      Returns : void
 *      In the OPTI case, this function will do nothing as only
 *      one hashtable exists, for constants, and we don't want to
 *      delete entries in this hashtable until application
 *      completion.
 *      In the NO_OPTI case, this function will search an entry
 *      corresponding to that value :
 *        First in constant hashtable : if entry is found, function
 *        does nothing as we don't want to delete entries in this
 *        hashtable until application completion, and function
 *        returns.
 *        Second in other hashtable : if entry is found, function
 *        simply deletes it.
 *      This function should be called when a MPI variable is
 *      deleted (e.g. : Argument MPI_Comm *comm of MPI_Comm_free)
 *
 *      varname##_translation_free_all:
 *      No arg, returns void
 *      Simply free constant hashtable and other hashtable in the
 *      NO_OPTI case.
 *      This function should be called at MPI_Finalize
 *
 *      varname##_get_size:
 *      No arg
 *      Returns : int, size of the hashtable
 *      This function returns number of entries of other hashtable
 *      In the OPTI case, always returns 0 because there is only
 *      one hashtable for constant variables and this hashtable is
 *      not count in this function.
 *      This function may be called at MPI_Finalize to check
 *      memory leaks in the hashtable.
 *
 */


#define HASHTABLE_OPTI_HEADER(type, varname)   \
 \
typedef struct { \
  A_##type a_##varname##_key; \
  R_##type r_##varname##_value; \
  UT_hash_handle hh; \
} varname##_translation_t; \
 \
void varname##_translation_add_const(A_##type a_mpi_##varname, R_##type mpi_##varname); \
int varname##_translation_is_const(A_##type a_mpi_##varname); \
void varname##_translation_get(A_##type a_mpi_##varname, R_##type* mpi_##varname); \
void varname##_translation_get_key_from_value(R_##type mpi_##varname, A_##type *a_mpi_##varname); \
void varname##_translation_update(A_##type * a_mpi_##varname, R_##type mpi_##varname); \
void varname##_translation_free_all(); \
int varname##_translation_get_size();

#define HASHTABLE_NO_OPTI_HEADER(type, varname)   \
typedef struct { \
  A_##type a_##varname##_key; \
  R_##type r_##varname##_value; \
  UT_hash_handle hh; \
} varname##_translation_t; \
 \
void varname##_translation_add_const(A_##type a_mpi_##varname, R_##type mpi_##varname); \
int varname##_translation_is_const(A_##type a_mpi_##varname); \
void varname##_translation_get(A_##type a_mpi_##varname, R_##type* mpi_##varname); \
void varname##_translation_get_key_from_value(R_##type mpi_##varname, A_##type *a_mpi_##varname); \
void varname##_translation_update(A_##type * a_mpi_##varname, R_##type mpi_##varname); \
void varname##_translation_del(A_##type * a_mpi_##varname); \
void varname##_translation_free_all(); \
void varname##_translation_init();\
int varname##_translation_get_size();


/* Communicator */
#if HASHTABLE_OPTI_COMMUNICATOR
HASHTABLE_OPTI_HEADER(MPI_Comm,communicator)
#define communicator_translation_del(a_mpi_type)
#define communicator_translation_get_size() 0
#else
HASHTABLE_NO_OPTI_HEADER(MPI_Comm,communicator)
#endif

/* Datatype */
#if HASHTABLE_OPTI_DATATYPE
HASHTABLE_OPTI_HEADER(MPI_Datatype,datatype)
#define datatype_translation_del(a_mpi_type)
#define datatype_translation_get_size() 0
#else
HASHTABLE_NO_OPTI_HEADER(MPI_Datatype,datatype)
#endif

/* Datatype */
#if HASHTABLE_OPTI_ERRHANDLER
HASHTABLE_OPTI_HEADER(MPI_Errhandler,errhandler)
#define errhandler_translation_del(a_mpi_type)
#define errhandler_translation_get_size() 0
#else
HASHTABLE_NO_OPTI_HEADER(MPI_Errhandler,errhandler)
#endif

/* Op */
#if HASHTABLE_OPTI_OP
HASHTABLE_OPTI_HEADER(MPI_Op,operation)
#define operation_translation_del(a_mpi_type)
#define operation_translation_get_size() 0
#else
HASHTABLE_NO_OPTI_HEADER(MPI_Op,operation)
#endif

/* Group */
#if HASHTABLE_OPTI_GROUP
HASHTABLE_OPTI_HEADER(MPI_Group,group)
#define group_translation_del(a_mpi_type)
#define group_translation_get_size() 0
#else
HASHTABLE_NO_OPTI_HEADER(MPI_Group,group)
#endif

/* Info */
#if HASHTABLE_OPTI_INFO
HASHTABLE_OPTI_HEADER(MPI_Info,info)
#define info_translation_del(a_mpi_type)
#define info_translation_get_size() 0
#else
HASHTABLE_NO_OPTI_HEADER(MPI_Info,info)
#endif

/* File */
#if HASHTABLE_OPTI_FILE
HASHTABLE_OPTI_HEADER(MPI_File,file)
#define file_translation_del(a_mpi_type)
#define file_translation_get_size() 0
#else
HASHTABLE_NO_OPTI_HEADER(MPI_File,file)
#endif

/* Win */
#if HASHTABLE_OPTI_WIN
HASHTABLE_OPTI_HEADER(MPI_Win,win)
#define win_translation_del(a_mpi_type)
#define win_translation_get_size() 0
#else
HASHTABLE_NO_OPTI_HEADER(MPI_Win,win)
#endif

/* Message  */
#if HASHTABLE_OPTI_MESSAGE
HASHTABLE_OPTI_HEADER(MPI_Message,message)
#define message_translation_del(a_mpi_type)
#define message_translation_get_size() 0
#else
HASHTABLE_NO_OPTI_HEADER(MPI_Message,message)
#endif

/* MPI_T_enum */
#if HASHTABLE_OPTI_ENUM
HASHTABLE_OPTI_HEADER(MPI_T_enum, t_enum)
#define t_enum_translation_del(a_mpi_type)
#define t_enum_translation_get_size() 0
#else
HASHTABLE_NO_OPTI_HEADER(MPI_T_enum, t_enum)
#endif

/* MPI_T_cvar_handle */
#if HASHTABLE_OPTI_CVAR
HASHTABLE_OPTI_HEADER(MPI_T_cvar_handle, cvar_handle)
#define cvar_handle_translation_del(a_mpi_type)
#define cvar_handle_translation_get_size() 0
#else
HASHTABLE_NO_OPTI_HEADER(MPI_T_cvar_handle, cvar_handle)
#endif

/* MPI_T_pvar_handle */
#if HASHTABLE_OPTI_PVAR
HASHTABLE_OPTI_HEADER(MPI_T_pvar_handle, pvar_handle)
#define pvar_handle_translation_del(a_mpi_type)
#define pvar_handle_translation_get_size() 0
#else
HASHTABLE_NO_OPTI_HEADER(MPI_T_pvar_handle, pvar_handle)
#endif

/* MPI_T_pvar_session */
//#if HASHTABLE_OPTI_SESSION
//HASHTABLE_OPTI_HEADER(MPI_T_pvar_session, pvar_session)
//#define pvar_session_translation_del(a_mpi_type)
//#define pvar_session_translation_get_size() 0
//#else
//HASHTABLE_NO_OPTI_HEADER(MPI_T_pvar_session, pvar_session)
//#endif

//A_MPI_T_enum;
//A_MPI_T_cvar_handle;
//A_MPI_T_pvar_handle;
//A_MPI_T_pvar_session;


/*
 * Following functions for MPI_Request structures are
 * a bit different from other hashtables.
 * In MPI specification, MPI_Request is used for
 * non-blocking communications (e.g. : MPI_IRecv) and
 * persitent requests. Depending on which case user
 * uses this MPI_Request, variable should or not be
 * freed at end of some functions.
 * Instead, for NO_OPTI case three hashtables are
 * created : One for constant variables, a second for
 * MPI_Request used in non-blocking case, a third for
 * MPI_Request used in a persistent request.
 * Function behaviors are nearly the same, but a third
 * argument is used for get function and update function.
 *
 * In get function and NO_OPTI case, third argument
 * int *non_blocking will be set to 1 if variable
 * corresponds to a non-blocking communication, 0 if
 * variable corresponds to a persistent request, and a
 * negative value if variable is a constant.
 * In get function and OPTI case, this variable will
 * always be set to a negative value.
 *
 * In update function and NO_OPTI case, if third argument
 * int non_blocking is set to 1, variable will be set in
 * non-blocking MPI_Request hashtable if it should. If
 * third argument int non_blocking is set to 0, variable
 * will be set in persistent request MPI_Request hashtable
 * if it should.
 * If OPTI case, this argument will not be read.
 *
 */


/* Request */

typedef struct {
    A_MPI_Request a_request_key;
    R_MPI_Request r_request_value;
    UT_hash_handle hh;
} request_translation_t;

void request_translation_add_const(A_MPI_Request a_mpi_request, R_MPI_Request mpi_request);
int request_translation_is_const(A_MPI_Request a_mpi_request);
void request_translation_get(A_MPI_Request a_mpi_request, R_MPI_Request* mpi_request, int* non_blocking);
void request_translation_get_key_from_value(R_MPI_Request mpi_request, A_MPI_Request *a_mpi_request);
void request_translation_update(A_MPI_Request * a_mpi_request, R_MPI_Request mpi_request, int non_blocking);
void request_translation_free_all();

#if HASHTABLE_OPTI_REQUEST
#define request_translation_del(a_mpi_type)
#define request_translation_get_size() 0
#else
void request_translation_del(A_MPI_Request * a_mpi_request);
int request_translation_get_size();
#endif

/* MPI IO */
//#if WRAPPER_MPI_VERSION > 21

/* File */
/*#if HASHTABLE_OPTI_FILE
HASHTABLE_OPTI_HEADER(MPI_File,file)
#define file_translation_del(a_mpi_type)
#define file_translation_get_size() 0
#else
HASHTABLE_NO_OPTI_HEADER(MPI_File,file)
#endif*/

/* Info */
/*#if HASHTABLE_OPTI_INFO
HASHTABLE_OPTI_HEADER(MPI_Info,info)
#define info_translation_del(a_mpi_type)
#define info_translation_get_size() 0
#else
HASHTABLE_NO_OPTI_HEADER(MPI_Info,info)
#endif*/


//#endif

#endif

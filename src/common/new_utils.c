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


//#ifdef OMPI_OMPI
//#include "ompi_ext_decl.h"
//#endif


#include "new_utils.h"
#include <stdio.h>
/*
static void dump(void * src, size_t size) {
    unsigned char * tab = (unsigned char*) malloc(size);
    memcpy(tab, src, size);
    size_t i=0;
    for(;i<size;i++)
      fprintf(stderr, "%02X ", tab[i]);
    fprintf(stderr, "\n");
    free(tab);
}
*/

/*  Memcpy if application structure is large enough */

#define HASHTABLE_OPTI(type, varname)   \
static varname##_translation_t* varname##_const_table = NULL;  \
  \
/*  ADD  */  \
void varname##_translation_add_const(A_##type a_mpi_##varname, R_##type mpi_##varname) {  \
   /* Hashtable */  \
    varname##_translation_t* conv = (varname##_translation_t*) malloc(sizeof(varname##_translation_t));  \
    memcpy(&(conv->a_##varname##_key), &a_mpi_##varname, sizeof(A_##type));  \
    memcpy(&(conv->r_##varname##_value), &mpi_##varname, sizeof(R_##type));  \
    HASH_ADD(hh, varname##_const_table, a_##varname##_key, sizeof(A_##type), conv);  \
}  \
  \
int varname##_translation_is_const(A_##type a_mpi_##varname) { \
    varname##_translation_t* conv;  \
    HASH_FIND(hh,varname##_const_table, &a_mpi_##varname, sizeof(A_##type), conv);  \
    return (conv != NULL); \
} \
 \
/*  GET  */  \
void varname##_translation_get(A_##type a_mpi_##varname, R_##type *mpi_##varname) {  \
    varname##_translation_t* conv;  \
    HASH_FIND(hh,varname##_const_table, &a_mpi_##varname, sizeof(A_##type), conv);  \
    if(conv != NULL) { /* constant */  \
        memcpy(mpi_##varname,&(conv->r_##varname##_value), sizeof(R_##type));  \
    } else { /* Not a constant */ \
        /* Memcpy */  \
        memcpy(mpi_##varname, &a_mpi_##varname, sizeof(R_##type));  \
    }  \
}  \
  \
/*  GET_KEY */  \
void varname##_translation_get_key_from_value(R_##type mpi_##varname, A_##type *a_mpi_##varname) {  \
    varname##_translation_t* conv;  \
    /* Search in const */  \
    for (conv = varname##_const_table; conv != NULL; conv = conv->hh.next) {  \
        if (conv->r_##varname##_value == mpi_##varname) {  \
            memcpy(a_mpi_##varname, &(conv->a_##varname##_key), sizeof(A_##type));  \
            return;  \
        }  \
    }  \
    memcpy(a_mpi_##varname, &mpi_##varname, sizeof(R_##type));  \
    return;  \
}  \
  \
static varname##_translation_t* varname##_translation_get_key_from_const(R_##type mpi_##varname, A_##type *a_mpi_##varname) {  \
    varname##_translation_t* conv;  \
    /* Search in const */  \
    for (conv = varname##_const_table; conv != NULL; conv = conv->hh.next) {  \
        if (conv->r_##varname##_value == mpi_##varname) {  \
            return conv;  \
        }  \
    }  \
    return NULL;  \
}  \
  \
/* UPDATE */  \
  \
void varname##_translation_update(A_##type * a_mpi_##varname, R_##type mpi_##varname) {  \
    varname##_translation_t* conv = varname##_translation_get_key_from_const(mpi_##varname, a_mpi_##varname);  \
    if(conv != NULL) { /* constant */  \
        /* varname##_translation_del(a_mpi_##varname); We delete last entry */  \
        memcpy(a_mpi_##varname,&(conv->a_##varname##_key), sizeof(A_##type));  \
        return;  \
    }  \
    /* Memcpy */  \
    memcpy(a_mpi_##varname, &mpi_##varname, sizeof(R_##type));  \
}  \
  \
void varname##_translation_free_all() {  \
    HASH_CLEAR(hh, varname##_const_table);   \
}

/*   True hashtables  */

#define HASHTABLE_NO_OPTI(type, varname, mpi_null)   \
static varname##_translation_t* varname##_table = NULL;  \
static varname##_translation_t* varname##_const_table = NULL;  \
int counter_##varname=0;\
pthread_spinlock_t varname##_vLock=1;\
table_lock_t varname##_Lock=&varname##_vLock;\
  \
/*  lock_init  */  \
void varname##_translation_init(void) {\
      lock_init(varname##_Lock);\
}  \
/*  ADD  */  \
void varname##_translation_add_const(A_##type a_mpi_##varname, R_##type mpi_##varname) {  \
   /* Hashtable */  \
    varname##_translation_t* conv = (varname##_translation_t*) malloc(sizeof(varname##_translation_t));  \
    memcpy(&(conv->a_##varname##_key), &a_mpi_##varname, sizeof(A_##type));  \
    memcpy(&(conv->r_##varname##_value), &mpi_##varname, sizeof(R_##type));/* conv->r_##varname##_value=mpi_##varname;*/  \
    HASH_ADD(hh, varname##_const_table, a_##varname##_key, sizeof(A_##type), conv);  \
}  \
  \
int varname##_translation_is_const(A_##type a_mpi_##varname) { \
    varname##_translation_t* conv;  \
    HASH_FIND(hh,varname##_const_table, &a_mpi_##varname, sizeof(A_##type), conv);  \
    return (conv != NULL); \
} \
 \
A_##type create_key_##varname(void){\
int key=999;\
    varname##_translation_t* conv_cte;  \
    varname##_translation_t* conv;  \
do {\
key++;\
HASH_FIND(hh,varname##_const_table, &key, sizeof(int), conv_cte);\
HASH_FIND(hh,varname##_table, &key, sizeof(int), conv);\
}while(conv&&conv_cte);\
return key;\
}\
\
/*  GET  */  \
void varname##_translation_get(A_##type a_mpi_##varname, R_##type *mpi_##varname) {  \
    varname##_translation_t* conv;  \
    HASH_FIND(hh,varname##_const_table, &a_mpi_##varname, sizeof(A_##type), conv);  \
    if(conv != NULL) { \
        /*memcpy(mpi_##varname,&(conv->r_##varname##_value), sizeof(R_##type));*/*mpi_##varname=conv->r_##varname##_value;  \
    } else { /* Not a constant */  \
        /* In an hashtable */   \
        lock(varname##_Lock);\
        HASH_FIND(hh,varname##_table, &a_mpi_##varname, sizeof(A_##type), conv); \
        unlock(varname##_Lock);\
        if(conv == NULL) { \
            /*memcpy(mpi_##varname, mpi_null, sizeof(R_##type));*/ /*attention*/ *mpi_##varname=mpi_null;  \
        } else { \
            memcpy(mpi_##varname,&(conv->r_##varname##_value), sizeof(R_##type));/*mpi_##varname=conv->r_##varname##_value;*/  \
        }  \
    }  \
}  \
  \
/*  GET_KEY */  \
void varname##_translation_get_key_from_value(R_##type mpi_##varname, A_##type *a_mpi_##varname) {  \
    varname##_translation_t* conv;  \
    /* Search in const */  \
    for (conv = varname##_const_table; conv != NULL; conv = conv->hh.next) {  \
        if (conv->r_##varname##_value == mpi_##varname) {  \
            memcpy(a_mpi_##varname, &(conv->a_##varname##_key), sizeof(A_##type));  \
            return;  \
        }  \
    }  \
    /* Search in not const */  \
    for (conv = varname##_table; conv != NULL; conv = conv->hh.next) {  \
        if (conv->r_##varname##_value == mpi_##varname) {  \
            memcpy(a_mpi_##varname, &(conv->a_##varname##_key), sizeof(A_##type));  \
            return;  \
        }  \
    }  \
    /* Not found */  \
    assert(0);  \
}  \
  \
static varname##_translation_t* varname##_translation_get_key_from_const(R_##type mpi_##varname, A_##type *a_mpi_##varname) {  \
    varname##_translation_t* conv;  \
    /* Search in const */  \
    for (conv = varname##_const_table; conv != NULL; conv = conv->hh.next) {  \
        if (conv->r_##varname##_value == mpi_##varname) {  \
            return conv;  \
        }  \
    }  \
    return NULL;  \
}  \
  \
/* DEL */  \
void varname##_translation_del(A_##type * a_mpi_##varname) {  \
    varname##_translation_t* conv;  \
    HASH_FIND(hh, varname##_const_table, a_mpi_##varname, sizeof(A_##type), conv);  \
    if(conv != NULL) { /* constant */  \
        /* Nothing to delete */  \
        return;  \
    }  \
    /* Hashtable */  \
    lock(varname##_Lock);\
    HASH_FIND(hh, varname##_table, a_mpi_##varname, sizeof(A_##type), conv);  \
    if(conv != NULL) {  \
        HASH_DELETE(hh, varname##_table, conv);  \
    }  \
    unlock(varname##_Lock);\
}  \
  \
void varname##_translation_update(A_##type * a_mpi_##varname, R_##type mpi_##varname) {  \
    varname##_translation_t* conv =NULL;\
    varname##_translation_t* conv_cte =NULL;\
    if(conv_cte=varname##_translation_get_key_from_const(mpi_##varname, a_mpi_##varname)){\
    memcpy(a_mpi_##varname,&(conv_cte->a_##varname##_key),  sizeof(A_##type)); \
    return;\
    }\
    lock(varname##_Lock);\
    memset(a_mpi_##varname,0,sizeof(A_##type));\
    do\
    {\
    (*(int*)a_mpi_##varname)=++counter_##varname;if(counter_##varname&(1>>31)) counter_##varname=0;\
    HASH_FIND(hh, varname##_table, a_mpi_##varname, sizeof(A_##type), conv);  \
    HASH_FIND(hh, varname##_const_table, a_mpi_##varname, sizeof(A_##type), conv_cte);  \
    }\
    while(conv||conv_cte);\
    if (conv == NULL) { /* New value in hashtable */  \
        conv = (varname##_translation_t*) malloc(sizeof(varname##_translation_t));  \
    /*    memcpy(a_mpi_##varname, &a_mpi_##varname, sizeof(A_##type)); */ \
        memcpy(&(conv->a_##varname##_key), a_mpi_##varname, sizeof(A_##type));  \
        memcpy(&(conv->r_##varname##_value), &mpi_##varname, sizeof(R_##type));  \
        HASH_ADD(hh, varname##_table, a_##varname##_key, sizeof(A_##type), conv);  \
    } else {  \
    exit(11);\
        memcpy(&(conv->r_##varname##_value), &mpi_##varname, sizeof(R_##type));  \
    }  \
    unlock(varname##_Lock);\
}  \
void varname##_translation_update_alloc(A_##type * a_mpi_##varname, R_##type mpi_##varname) {  \
    /* Hashtable */  \
    varname##_translation_t* conv =NULL;\
    varname##_translation_t* conv_cte =NULL;\
    lock(varname##_Lock);\
    memset(a_mpi_##varname,0,sizeof(A_##type));\
    do\
    {\
    (*(int*)a_mpi_##varname)=++counter_##varname;if(counter_##varname&(1>>31)) counter_##varname=0;\
    HASH_FIND(hh, varname##_table, a_mpi_##varname, sizeof(A_##type), conv);  \
    HASH_FIND(hh, varname##_const_table, a_mpi_##varname, sizeof(A_##type), conv_cte);  \
    }\
    while(conv||conv_cte);\
    if (conv == NULL) { /* New value in hashtable */  \
        conv = (varname##_translation_t*) malloc(sizeof(varname##_translation_t));  \
    /*    memcpy(a_mpi_##varname, &a_mpi_##varname, sizeof(A_##type)); */ \
        memcpy(&(conv->a_##varname##_key), a_mpi_##varname, sizeof(A_##type));  \
        memcpy(&(conv->r_##varname##_value), &mpi_##varname, sizeof(R_##type));  \
        HASH_ADD(hh, varname##_table, a_##varname##_key, sizeof(A_##type), conv);  \
    } else {  \
        memcpy(&(conv->r_##varname##_value), &mpi_##varname, sizeof(R_##type));  \
    }  \
    unlock(varname##_Lock);\
}  \
  \
int varname##_translation_get_size() {  \
    int size = 0;  \
    varname##_translation_t* conv;  \
    for (conv = varname##_table; conv != NULL; conv = conv->hh.next)  \
        size++;  \
    return size;  \
}  \
  \
void varname##_translation_free_all() {  \
    HASH_CLEAR(hh, varname##_const_table);   \
    lock(varname##_Lock);\
    HASH_CLEAR(hh, varname##_table);   \
    unlock(varname##_Lock);\
}\

/* Communicator */
#if HASHTABLE_OPTI_COMMUNICATOR
HASHTABLE_OPTI(MPI_Comm,communicator);
#else
HASHTABLE_NO_OPTI(MPI_Comm,communicator, R_MPI_COMM_NULL);
#endif

/* Datatype */
#if HASHTABLE_OPTI_DATATYPE
HASHTABLE_OPTI(MPI_Datatype,datatype);
#else
HASHTABLE_NO_OPTI(MPI_Datatype,datatype, R_MPI_DATATYPE_NULL);
#endif

/* Errhandler */
#if HASHTABLE_OPTI_ERRHANDLER
HASHTABLE_OPTI(MPI_Errhandler,errhandler);
#else
HASHTABLE_NO_OPTI(MPI_Errhandler,errhandler, R_MPI_ERRHANDLER_NULL);
#endif

/* Op */
#if HASHTABLE_OPTI_OP
HASHTABLE_OPTI(MPI_Op,operation);
#else
HASHTABLE_NO_OPTI(MPI_Op,operation, R_MPI_OP_NULL);
#endif

/* Group */
#if HASHTABLE_OPTI_GROUP
HASHTABLE_OPTI(MPI_Group,group);
#else
HASHTABLE_NO_OPTI(MPI_Group,group, R_MPI_GROUP_NULL);
#endif

/* Win */
#if HASHTABLE_OPTI_WIN
HASHTABLE_OPTI(MPI_Win,win);
#else
HASHTABLE_NO_OPTI(MPI_Win,win, R_MPI_WIN_NULL);
#endif

/* Message */
#if HASHTABLE_OPTI_MESSAGE
HASHTABLE_OPTI(MPI_Message,message);
#else
HASHTABLE_NO_OPTI(MPI_Message,message, R_MPI_MESSAGE_NULL);
#endif

/* MPI_T_enum */
#if HASHTABLE_OPTI_ENUM
HASHTABLE_OPTI(MPI_T_enum, t_enum);
#else
HASHTABLE_NO_OPTI(MPI_T_enum, t_enum, R_MPI_T_ENUM_NULL);
#endif

/* MPI_T_cvar_handle */
#if HASHTABLE_OPTI_CVAR
HASHTABLE_OPTI(MPI_T_cvar_handle, cvar_handle);
#else
HASHTABLE_NO_OPTI(MPI_T_cvar_handle, cvar_handle, R_MPI_T_CVAR_HANDLE_NULL);
#endif

/* MPI_T_pvar_handle */
#if HASHTABLE_OPTI_PVAR
HASHTABLE_OPTI(MPI_T_pvar_handle, pvar_handle);
#else
HASHTABLE_NO_OPTI(MPI_T_pvar_handle, pvar_handle, R_MPI_T_PVAR_HANDLE_NULL);
#endif

/*  MPI_T_pvar_session*/
//#if HASHTABLE_OPTI_SESSION
//HASHTABLE_OPTI(MPI_T_pvar_session, pvar_session);
//#else
//HASHTABLE_NO_OPTI(MPI_T_pvar_session, pvar_session, R_MPI_T_PVAR_SESSION_NULL);
//#endif

/* Request */
static request_translation_t* request_const_table = NULL;
/*table_lock_t*/ volatile int * request_Lock;

/*  ADD  */
void request_translation_add_const(A_MPI_Request a_mpi_request, R_MPI_Request mpi_request) {
    /* Hashtable */
    request_translation_t* conv = (request_translation_t*) malloc(sizeof(request_translation_t));
    memcpy(&(conv->a_request_key), &a_mpi_request, sizeof(A_MPI_Request));
    memcpy(&(conv->r_request_value), &mpi_request, sizeof(R_MPI_Request));
    HASH_ADD(hh, request_const_table, a_request_key, sizeof(A_MPI_Request), conv);
}

int request_translation_is_const(A_MPI_Request a_mpi_request) {
    request_translation_t* conv;
    HASH_FIND(hh,request_const_table, &a_mpi_request, sizeof(A_MPI_Request), conv);
    return (conv != NULL);
}
#if HASHTABLE_OPTI_REQUEST
int request_translation_is_non_blocking(A_MPI_Request a_mpi_request) { /* We don't bother it in OPTI */
    return -1;
}

/*  GET  */
void request_translation_get(A_MPI_Request a_mpi_request, R_MPI_Request *mpi_request, int * non_blocking) {
    *non_blocking = -1;   /* We don't bother it in OPTI*/
    request_translation_t* conv;
    HASH_FIND(hh,request_const_table, &a_mpi_request, sizeof(A_MPI_Request), conv);
    if(conv != NULL) { /* constant */
        memcpy(mpi_request,&(conv->r_request_value), sizeof(R_MPI_Request));
    } else { /* Not a constant */
        /* Memcpy */
        memcpy(mpi_request, &a_mpi_request, sizeof(R_MPI_Request));
    }
}

static request_translation_t* request_translation_get_key_from_const(R_MPI_Request mpi_request, A_MPI_Request *a_mpi_request) {
    request_translation_t* conv;
    /* Search in const */
    for (conv = request_const_table; conv != NULL; conv = conv->hh.next) {
        if (conv->r_request_value == mpi_request) {
            return conv;
        }
    }
    return NULL;
}

/* UPDATE */
void request_translation_update(A_MPI_Request * a_mpi_request, R_MPI_Request mpi_request, int non_blocking) {
    request_translation_t* conv = request_translation_get_key_from_const(mpi_request, a_mpi_request);
    lock(request_Lock);
    if(conv != NULL) { /* constant */
        /*request_translation_del(a_mpi_request);  We delete last entry */
        memcpy(a_mpi_request,&(conv->a_request_key), sizeof(A_MPI_Request));
        return;
    }
    /* Memcpy */
    memcpy(a_mpi_request, &mpi_request, sizeof(R_MPI_Request));
    unlock(request_Lock);
}

void request_translation_free_all() {
    lock(request_Lock);
    HASH_CLEAR(hh, request_const_table);
    unlock(request_Lock);
}

#else
/*   True hashtables  */
static request_translation_t* request_table_non_blocking = NULL;
static request_translation_t* request_table_persist_request = NULL;
pthread_spinlock_t tt;
int counter_request=0;
table_lock_t request_Lock=&tt;

/*
static void dump_hashtable(request_translation_t* conv) {
    for (; conv != NULL; conv = conv->hh.next) {
        dump(&(conv->a_request_key), sizeof(A_MPI_Request));
        fprintf(stderr, "|->");
        dump(&(conv->r_request_value), sizeof(MPI_Request));
    }
}
*/
void request_translation_init()
{
      lock_init(request_Lock);
}
/*  GET  */
void request_translation_get(A_MPI_Request a_mpi_request, R_MPI_Request *mpi_request, int* non_blocking) {
    request_translation_t* conv;
    HASH_FIND(hh,request_const_table, &a_mpi_request, sizeof(A_MPI_Request), conv);
    if(conv != NULL) { /* constant */
        memcpy(mpi_request,&(conv->r_request_value), sizeof(R_MPI_Request));
        *non_blocking = -1; /* We don't bother it*/
    } else { /* Not a constant */
        /* In an hashtable */
        lock(request_Lock);
        HASH_FIND(hh,request_table_non_blocking, &a_mpi_request, sizeof(A_MPI_Request), conv);
        unlock(request_Lock);
        if(conv != NULL) {
            *non_blocking = 1;
            memcpy(mpi_request,&(conv->r_request_value), sizeof(R_MPI_Request));
        } else {
            lock(request_Lock);
            HASH_FIND(hh,request_table_persist_request, &a_mpi_request, sizeof(A_MPI_Request), conv);
            unlock(request_Lock);
            *non_blocking = 0;
            if(conv == NULL) {
                *mpi_request=R_MPI_REQUEST_NULL;//memcpy(mpi_request, R_MPI_REQUEST_NULL, sizeof(R_MPI_Request));   
            } else {
                memcpy(mpi_request,&(conv->r_request_value), sizeof(R_MPI_Request));
            }
        }
    }
}

static request_translation_t* request_translation_get_key_from_const(R_MPI_Request mpi_request, A_MPI_Request *a_mpi_request) {
    request_translation_t* conv;
    /* Search in const */
    for (conv = request_const_table; conv != NULL; conv = conv->hh.next) {
        if (conv->r_request_value == mpi_request) {
            return conv;
        }
    }
    return NULL;
}

/* DEL */
void request_translation_del(A_MPI_Request * a_mpi_request) {
    request_translation_t* conv;
    HASH_FIND(hh, request_const_table, a_mpi_request, sizeof(A_MPI_Request), conv);
    if(conv != NULL) { /* constant */
        /* Nothing to delete */
        return;
    }
    /* Hashtable */
    lock(request_Lock);
    HASH_FIND(hh, request_table_non_blocking, a_mpi_request, sizeof(A_MPI_Request), conv);
    if(conv != NULL) {
        HASH_DELETE(hh, request_table_non_blocking, conv);
    } else {
        HASH_FIND(hh, request_table_persist_request, a_mpi_request, sizeof(A_MPI_Request), conv);

        if(conv != NULL) {
            HASH_DELETE(hh, request_table_persist_request, conv);
        }
    }
    unlock(request_Lock);
}

/* UPDATE */
void request_translation_update(A_MPI_Request * a_mpi_request, R_MPI_Request mpi_request, int non_blocking) {
    
    request_translation_t* conv_non_blocking = NULL;
    request_translation_t* conv_persist_request = NULL;
    request_translation_t* conv_cte =  request_translation_get_key_from_const( mpi_request, a_mpi_request);
    if(conv_cte!=NULL)
    {
        memcpy(a_mpi_request,&(conv_cte->a_request_key),sizeof(A_MPI_Request));
        return;
    }
    /* Hashtable */
    lock(request_Lock);
    memset(a_mpi_request,0,sizeof(A_MPI_Request));
    do {
   *((int*)a_mpi_request)=++counter_request;if(counter_request&(1>>31)) counter_request=0;
    HASH_FIND(hh, request_table_non_blocking, a_mpi_request, sizeof(A_MPI_Request), conv_non_blocking);
    HASH_FIND(hh, request_const_table, a_mpi_request, sizeof(A_MPI_Request), conv_cte);
    HASH_FIND(hh, request_table_persist_request, a_mpi_request, sizeof(A_MPI_Request), conv_persist_request);
}while(conv_non_blocking||conv_persist_request||conv_cte);
        conv_non_blocking = (request_translation_t*) malloc(sizeof(request_translation_t));
        memcpy(&(conv_non_blocking->a_request_key), a_mpi_request, sizeof(A_MPI_Request));
        memcpy(&(conv_non_blocking->r_request_value), &mpi_request, sizeof(R_MPI_Request));
        if(non_blocking) {
            HASH_ADD(hh, request_table_non_blocking, a_request_key, sizeof(A_MPI_Request), conv_non_blocking);
        } else {
            HASH_ADD(hh, request_table_persist_request, a_request_key, sizeof(A_MPI_Request), conv_non_blocking);
        }

    unlock(request_Lock);
}

int request_translation_get_size() {
    int size = 0;
    request_translation_t* conv;
    for (conv = request_table_non_blocking; conv != NULL; conv = conv->hh.next)
        size++;
    for (conv = request_table_persist_request; conv != NULL; conv = conv->hh.next)
        size++;
    return size;
}

void request_translation_free_all() {
    lock(request_Lock);
    HASH_CLEAR(hh, request_const_table);
    HASH_CLEAR(hh, request_table_non_blocking);
    HASH_CLEAR(hh, request_table_persist_request);
    unlock(request_Lock);
}
#endif

//#if WRAPPER_MPI_VERSION > 21
/* File */
#if HASHTABLE_OPTI_FILE
HASHTABLE_OPTI(MPI_File,file);
#else
HASHTABLE_NO_OPTI(MPI_File,file, R_MPI_FILE_NULL);
#endif

/* Info */
#if HASHTABLE_OPTI_INFO
HASHTABLE_OPTI(MPI_Info,info);
#else
HASHTABLE_NO_OPTI(MPI_Info,info, R_MPI_INFO_NULL);
#endif

//#endif

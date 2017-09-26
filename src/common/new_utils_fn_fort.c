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


#include "new_utils_fn.h"
#include "new_utils.h"
#include <stdio.h>

static void dump(void * src, size_t size) {
    unsigned char * tab = (unsigned char*) malloc(size);
    memcpy(tab, src, size);
    size_t i=0;
    for(; i<size; i++)
        fprintf(stderr, "%02X ", tab[i]);
    fprintf(stderr, "\n");
    free(tab);
}


#define HASHTABLE_OPTI_FN(keytype, valuetype, name) \
 \
static name##_fn_translation_t* name##_fn_table = NULL; \
 \
void name##_fn_translation_get(keytype key, valuetype* value) { \
    name##_fn_translation_t* conv;  \
    /*printf("name##fn get\n");*/\
    HASH_FIND(hh,name##_fn_table, &key, sizeof(keytype), conv);  \
    assert(conv != NULL); \
    memcpy(value,&(conv->value), sizeof(valuetype)); \
} \
 \
 \
void name##_fn_translation_update(keytype key, valuetype value) { \
    name##_fn_translation_t* conv;  \
    /*printf("name##fn update\n");*/\
    HASH_FIND(hh,name##_fn_table, &key, sizeof(keytype), conv);  \
    if (conv == NULL) { /* New value in hashtable */ \
        conv = (name##_fn_translation_t*) malloc(sizeof(name##_fn_translation_t)); \
        memcpy(&(conv->key), &key, sizeof(keytype)); \
        memcpy(&(conv->value), &value, sizeof(valuetype)); \
        HASH_ADD(hh, name##_fn_table, key, sizeof(keytype), conv); \
    } else { \
        memcpy(&(conv->value), &value, sizeof(valuetype)); \
    } \
} \
 \
void name##_fn_translation_del(keytype key) { \
    name##_fn_translation_t* conv;  \
    HASH_FIND(hh,name##_fn_table, &key, sizeof(keytype), conv);  \
    /*printf("name##fn del\n%d\n%d\n",key,conv);*/\
    if(conv != NULL) \
    HASH_DELETE(hh, name##_fn_table, conv); \
		free(conv); \
} \
 \
void name##_fn_translation_free_all() { \
    HASH_CLEAR(hh, name##_fn_table); \
}
//HASHTABLE_OPTI_FN_HEADER(int, void*, operator)
HASHTABLE_OPTI_FN(int, void*, errhandler_f)
HASHTABLE_OPTI_FN(int, void*, operator)
HASHTABLE_OPTI_FN(int, void*, communicator_f)
/*#if WRAPPER_MPI_VERSION > 21
HASHTABLE_OPTI_FN(A_MPI_Comm, A_MPI_Comm_errhandler_fn*, communicator)
#else
HASHTABLE_OPTI_FN(A_MPI_Comm, A_MPI_Handler_function*, communicator)
#endif

#if WRAPPER_MPI_VERSION > 21
HASHTABLE_OPTI_FN(A_MPI_File, A_MPI_File_errhandler_fn*, file)
#endif*/

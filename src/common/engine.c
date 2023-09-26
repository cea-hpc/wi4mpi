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


#include <pthread.h>

#include <stdio.h>
#include "wrapper_f.h"
#include "engine.h"
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
void *wi4mpi_alloc(size_t size)
{
    return malloc(size);
}
void wi4mpi_free(void *ptr)
{
    return free(ptr);
}

/*   True hashtables  */
#if defined(OMPI_INTEL) || defined(_INTEL)
extern char ompi_mpi_comm_null[];
extern char ompi_mpi_comm_self[];
extern char ompi_mpi_comm_world[];
extern char ompi_mpi_2cplex[];
extern char ompi_mpi_2dblcplex[];
extern char ompi_mpi_2dblprec[];
extern char ompi_mpi_2int[];
extern char ompi_mpi_2integer[];
extern char ompi_mpi_2real[];
extern char ompi_mpi_aint[];
extern char ompi_mpi_byte[];
extern char ompi_mpi_c_bool[];
extern char ompi_mpi_c_complex[];
extern char ompi_mpi_c_double_complex[];
extern char ompi_mpi_c_float_complex[];
extern char ompi_mpi_c_long_double_complex[];
extern char ompi_mpi_char[];
extern char ompi_mpi_character[];
extern char ompi_mpi_complex16[];
extern char ompi_mpi_complex32[];
extern char ompi_mpi_complex8[];
extern char ompi_mpi_cplex[];
extern char ompi_mpi_cxx_bool[];
extern char ompi_mpi_cxx_cplex[];
extern char ompi_mpi_cxx_dblcplex[];
extern char ompi_mpi_cxx_ldblcplex[];
extern char ompi_mpi_datatype_null[];
extern char ompi_mpi_dblcplex[];
extern char ompi_mpi_dblprec[];
extern char ompi_mpi_double[];
extern char ompi_mpi_double_int[];
extern char ompi_mpi_float[];
extern char ompi_mpi_float_int[];
extern char ompi_mpi_int16_t[];
extern char ompi_mpi_int32_t[];
extern char ompi_mpi_int64_t[];
extern char ompi_mpi_int8_t[];
extern char ompi_mpi_int[];
extern char ompi_mpi_integer16[];
extern char ompi_mpi_integer1[];
extern char ompi_mpi_integer2[];
extern char ompi_mpi_integer4[];
extern char ompi_mpi_integer8[];
extern char ompi_mpi_integer[];
extern char ompi_mpi_lb[];
extern char ompi_mpi_ldblcplex[];
extern char ompi_mpi_logical1[];
extern char ompi_mpi_logical2[];
extern char ompi_mpi_logical4[];
extern char ompi_mpi_logical8[];
extern char ompi_mpi_logical[];
extern char ompi_mpi_long[];
extern char ompi_mpi_long_double[];
extern char ompi_mpi_long_int[];
extern char ompi_mpi_long_long_int[];
extern char ompi_mpi_longdbl_int[];
extern char ompi_mpi_offset[];
extern char ompi_mpi_count[];
extern char ompi_message_null[];
extern char ompi_mpi_packed[];
extern char ompi_mpi_real16[];
extern char ompi_mpi_real2[];
extern char ompi_mpi_real4[];
extern char ompi_mpi_real8[];
extern char ompi_mpi_real[];
extern char ompi_mpi_short[];
extern char ompi_mpi_short_int[];
extern char ompi_mpi_signed_char[];
extern char ompi_mpi_ub[];
extern char ompi_mpi_uint16_t[];
extern char ompi_mpi_uint32_t[];
extern char ompi_mpi_uint64_t[];
extern char ompi_mpi_uint8_t[];
extern char ompi_mpi_unsigned[];
extern char ompi_mpi_unsigned_char[];
extern char ompi_mpi_unsigned_long[];
extern char ompi_mpi_unsigned_long_long[];
extern char ompi_mpi_unsigned_short[];
extern char ompi_mpi_wchar[];
extern char ompi_mpi_errhandler_null[];
extern char ompi_mpi_errors_are_fatal[];
extern char ompi_mpi_errors_return[];
extern char ompi_mpi_file_null[];
extern char ompi_mpi_group_empty[];
extern char ompi_mpi_group_null[];
extern char ompi_mpi_info_null[];
extern char ompi_mpi_op_band[];
extern char ompi_mpi_op_bor[];
extern char ompi_mpi_op_bxor[];
extern char ompi_mpi_op_land[];
extern char ompi_mpi_op_lor[];
extern char ompi_mpi_op_lxor[];
extern char ompi_mpi_op_max[];
extern char ompi_mpi_op_maxloc[];
extern char ompi_mpi_op_min[];
extern char ompi_mpi_op_minloc[];
extern char ompi_mpi_op_null[];
extern char ompi_mpi_op_prod[];
extern char ompi_mpi_op_replace[];
extern char ompi_mpi_op_sum[];
extern char ompi_request_null[];
extern char ompi_mpi_win_null[];
extern char ompi_message_no_proc[];
#include "run_mpio.h"
#endif

int cmp(const void *a,const void *b)
{
    return ((long long)a)<((long long )b);
}
#define HASHTABLE_NO_OPT_NO_FORTRAN(type,varname,mpi_null)  \
/*typedef struct {R_##type C;int idx;} type##_container;*/\
static type##_container * varname##_table = NULL;  \
static type##_container * const_##varname##_table = NULL;  \
static varname##_translation_t* varname##_const_table = NULL;  \
int *counter_##varname=NULL;\
int f##varname=100000;\
int *p_##varname;\
int l##varname;\
int max##varname;\
int varname##_size;\
pthread_spinlock_t varname##_vLock;\
table_lock_t varname##_Lock=&varname##_vLock;\
size_t *varname##cte_list;\
int  varname##cte_list_size;\
/*  lock_init  */  \
void varname##_translation_init(void) {\
      int i;\
        char *envvar;\
        char varname1[256],varname2[256];\
        strcat(varname1,"WI4");\
        strcat(varname1,#type);\
        strcpy(varname2,varname1);\
        strcat(varname1,"_OFFSET");\
        strcat(varname2,"_TABLE_SIZE");\
if((envvar=getenv(varname1)))\
    f##varname=strtol(envvar,NULL,10);\
if((envvar=getenv(varname2)))\
     varname##_size=strtol(envvar,NULL,10);\
    else\
        varname##_size=1024*1024;\
        lock_init(varname##_Lock);\
    varname##_table=(type##_container *)malloc(varname##_size*sizeof(type##_container));\
    counter_##varname=(int*)malloc(varname##_size*sizeof(int));\
    p_##varname=counter_##varname+varname##_size-1;\
/*printf("alloc %p %p\n",counter_##varname,p_##varname);*/\
    for(i=0;i<varname##_size;i++) {\
        counter_##varname[i]=varname##_size-i-1;\
    }\
}  \
/*  ADD  */  \
void varname##_translation_add_const(A_##type a_mpi_##varname, R_##type mpi_##varname) {  \
    varname##_translation_t* conv = (varname##_translation_t*) malloc(sizeof(varname##_translation_t));  \
    memcpy(&(conv->a_##varname##_key), &a_mpi_##varname, sizeof(A_##type));  \
    memcpy(&(conv->r_##varname##_value), &mpi_##varname, sizeof(R_##type)); \
    HASH_ADD(hh, varname##_const_table, a_##varname##_key, sizeof(A_##type), conv);  \
}  \
  \
int varname##_translation_is_const(A_##type a_mpi_##varname) { \
    varname##_translation_t* conv;  \
    HASH_FIND(hh,varname##_const_table, &a_mpi_##varname, sizeof(A_##type), conv);  \
    return (int)(conv != NULL); \
} \
 \
/*  GET  */  \
void varname##_translation_get(A_##type a_mpi_##varname, R_##type *mpi_##varname) {  \
      int i,id;\
    varname##_translation_t* conv;  \
    HASH_FIND(hh,varname##_const_table, &a_mpi_##varname, sizeof(A_##type), conv);  \
   if(conv != NULL) { \
        *mpi_##varname=(conv->r_##varname##_value);  \
    } else { \
        id=((int)a_mpi_##varname)-f##varname;\
        memcpy(mpi_##varname,&(varname##_table[id].C), sizeof(R_##type));\
    }  \
}  \
/*  GET_KEY */  \
varname##_translation_t* varname##_translation_get_key_from_const(R_##type mpi_##varname, A_##type *a_mpi_##varname) {  \
    varname##_translation_t* conv;  \
    for (conv = varname##_const_table; conv != NULL; conv = conv->hh.next) {  \
        if (conv->r_##varname##_value == mpi_##varname) {  \
            return conv;  \
        }  \
    }  \
    type##_container *tmp=varname##_table;\
    /*while(tmp!=(varname##_table+varname##_size)) if(!memcmp(&mpi_##varname,&(tmp->C),sizeof(R_##type))) return (tmp-varname##_table)+f##varname;*/\
    return (varname##_translation_t* )NULL;  \
}  \
  \
varname##_translation_t*  varname##_translation_get_key_from_value(R_##type mpi_##varname, A_##type *a_mpi_##varname) {  \
    varname##_translation_t* conv;  \
 for (conv = varname##_const_table; conv != NULL; conv = conv->hh.next) {  \
        if (conv->r_##varname##_value == mpi_##varname) {  \
            return conv;  \
        }  \
    }  \
    return (varname##_translation_t* )NULL;  \
}\
\
/* DEL */  \
void varname##_translation_del_f(int a_mpi_##varname) {  \
    int id;\
   lock(varname##_Lock);\
    id=a_mpi_##varname-f##varname;\
    if(id>=f##varname&&id<f##varname+varname##_size-1)\
    {p_##varname++;(*p_##varname)=id;\
    }\
    unlock(varname##_Lock);\
}  \
void varname##_translation_del(A_##type * a_mpi_##varname) {  \
    int id;varname##_translation_t* conv;R_##type mpi_##varname;  \
    HASH_FIND(hh, varname##_const_table, a_mpi_##varname, sizeof(A_##type), conv);  \
   if(conv != NULL) {    \
          \
        return;  \
    }  \
    lock(varname##_Lock);\
    id=(*((int*)a_mpi_##varname))-f##varname;\
    p_##varname++;\
    (*p_##varname)=id;\
    unlock(varname##_Lock);\
}  \
  \
void varname##_translation_update(A_##type * a_mpi_##varname, R_##type mpi_##varname) {  \
    varname##_translation_t* conv =NULL;\
    varname##_translation_t* conv_cte =NULL;\
    if((conv_cte=varname##_translation_get_key_from_const(mpi_##varname, a_mpi_##varname))){\
    memcpy(a_mpi_##varname,&(conv_cte->a_##varname##_key),  sizeof(A_##type)); \
    return;\
    }\
    lock(varname##_Lock);\
    int id=*p_##varname;\
    p_##varname--;\
    memset(a_mpi_##varname,0,sizeof(A_##type));\
    (*((int *)a_mpi_##varname))=id+f##varname;\
    memcpy(&(varname##_table[id].C),& mpi_##varname,sizeof( R_##type));\
    unlock(varname##_Lock);\
}  \
void varname##_translation_update_alloc(A_##type * a_mpi_##varname, R_##type mpi_##varname) {  \
    lock(varname##_Lock);\
    int id=*p_##varname;\
    p_##varname--;\
    memset(a_mpi_##varname,0,sizeof(A_##type));\
    (*((int *)a_mpi_##varname))=id+f##varname;\
    memcpy(&(varname##_table[id].C),& mpi_##varname,sizeof( R_##type));\
    unlock(varname##_Lock);\
}  \
  \
int varname##_translation_get_size() {  \
    return varname##_size;  \
}  \
  \
void varname##_translation_free_all() {  \
    HASH_CLEAR(hh, varname##_const_table);   \
    lock(varname##_Lock);\
    free( varname##_table);   \
    free( counter_##varname);   \
    unlock(varname##_Lock);\
} \




#define HASHTABLE_NO_OPTI(type, varname, mpi_null)   \
/*typedef struct {int fort;R_##type C;int idx;} type##_container;*/\
static type##_container * varname##_table = NULL;  \
static type##_container * const_##varname##_table = NULL;  \
static varname##_translation_t* varname##_const_table = NULL;  \
int *counter_##varname=NULL;\
int f##varname=100000;\
int *p_##varname;\
int l##varname;\
int max##varname;\
int varname##_size;\
pthread_spinlock_t varname##_vLock;\
table_lock_t varname##_Lock=&varname##_vLock;\
size_t *varname##cte_list;\
int  varname##cte_list_size;\
/*R_##type R_##type##_f2c(int);\
int R_##type##_c2f(R_##type);\
*/\
/*  lock_init  */  \
void varname##_translation_init(void) {\
      int i;\
        char *envvar;\
        char varname1[256],varname2[256];\
        strcpy(varname1,"WI4");\
        strcat(varname1,#type);\
        strcpy(varname2,varname1);\
        strcat(varname1,"_OFFSET");\
        strcat(varname2,"_TABLE_SIZE");\
if((envvar=getenv(varname1)))\
    f##varname=strtol(envvar,NULL,10);\
if((envvar=getenv(varname2)))\
     varname##_size=strtol(envvar,NULL,10);\
    else\
        varname##_size=1024*1024;\
        lock_init(varname##_Lock);\
    varname##_table=(type##_container *)malloc(varname##_size*sizeof(type##_container));\
    counter_##varname=(int*)malloc(varname##_size*sizeof(int));\
    p_##varname=counter_##varname+varname##_size-1;\
    for(i=0;i<varname##_size;i++) {\
        counter_##varname[i]=varname##_size-i-1;\
    }\
/*varname##cte_list=malloc(1024*1024*sizeof(void*));\
varname##cte_list_size=0;\
*/}  \
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
/*  GET  */  \
void varname##_translation_get(A_##type a_mpi_##varname, R_##type *mpi_##varname) {  \
      int i,id;\
    varname##_translation_t* conv;  \
    HASH_FIND(hh,varname##_const_table, &a_mpi_##varname, sizeof(A_##type), conv);  \
/* if(get_##type##_cte_a2r(&a_mpi_##varname,mpi_##varname)) return;*/\
   if(conv != NULL) { /*printf("ababa\n");*/\
        /*memcpy(mpi_##varname,&(conv->r_##varname##_value), sizeof(R_##type));*/*mpi_##varname=(conv->r_##varname##_value);  \
    } else { /* Not a constant */  \
        /* In an hashtable */   \
        id=((int)a_mpi_##varname)-f##varname;\
    /*    if(id<0||id>=varname##_size) *mpi_##varname=R_##mpi_null;\
        else*/ memcpy(mpi_##varname,&(varname##_table[id].C), sizeof(R_##type));\
    }  \
}  \
void varname##_translation_get_f(int a_mpi_##varname, int *mpi_##varname) {  \
      int i,id;\
 /*   varname##_translation_t* conv;  \
    HASH_FIND(hh,varname##_const_table, &a_mpi_##varname, sizeof(A_##type), conv);  \
/* if(get_##type##_cte_a2r(&a_mpi_##varname,mpi_##varname)) return;*/\
  /* if(conv != NULL) { printf("ababa\n");*/\
        /*memcpy(mpi_##varname,&(conv->r_##varname##_value), sizeof(R_##type));*mpi_##varname=(conv->r_##varname##_value);  \
 */ /*  } else */{ /* Not a constant */  \
        /* In an hashtable */   \
        id=((int)a_mpi_##varname)-f##varname;\
     /*   if(id<0||id>= varname##_size) *mpi_##varname=R_##type##_c2f(R_##mpi_null);\
        else*/ memcpy(mpi_##varname,&(varname##_table[id].fort), sizeof(int));\
        /*printf ("%s gf %d %d\n",#varname,a_mpi_##varname,*mpi_##varname);\
    */}  \
}  \
/*  GET_KEY */  \
varname##_translation_t* varname##_translation_get_key_from_const(R_##type mpi_##varname, A_##type *a_mpi_##varname) {  \
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
varname##_translation_t*  varname##_translation_get_key_from_value(R_##type mpi_##varname, A_##type *a_mpi_##varname) {  \
    varname##_translation_t* conv;  \
 for (conv = varname##_const_table; conv != NULL; conv = conv->hh.next) {  \
        if (conv->r_##varname##_value == mpi_##varname) {  memcpy(a_mpi_##varname,&(conv->a_##varname##_key),sizeof(A_##type));\
            return conv;  \
        }  \
    }  \
    type##_container *tmp=varname##_table;\
    while(tmp!=(varname##_table+varname##_size)) {if(!memcmp(&mpi_##varname,&(tmp->C),sizeof(R_##type))) {*a_mpi_##varname=(A_##type) ((tmp-varname##_table)+f##varname); return NULL; }tmp++;}\
    return NULL;  \
}\
/* DEL */  \
void varname##_translation_del_f(int a_mpi_##varname) {  \
    int id;\
    lock(varname##_Lock);\
    id=a_mpi_##varname-f##varname;\
    if(id>=0&&id<=varname##_size-1)\
    {p_##varname++;(*p_##varname)=id;\
    }\
    unlock(varname##_Lock);\
}  \
void varname##_translation_del(A_##type * a_mpi_##varname) {  \
    int id;varname##_translation_t* conv;R_##type mpi_##varname;  \
    HASH_FIND(hh, varname##_const_table, a_mpi_##varname, sizeof(A_##type), conv);  \
/* if(get_##type##_cte_a2r(&a_mpi_##varname,mpi_##varname)) return;*/\
   if(conv != NULL) {    \
          \
        return;  \
    }  /*printf("%s %d delete\n",#varname,*a_mpi_##varname);*/\
    /* Hashtable */  \
    id=(*((int*)a_mpi_##varname))-f##varname;\
    /*printf("%d\n",id);*/if(id<0||id>=varname##_size)\
        return;\
    lock(varname##_Lock);\
    varname##_table[id].C=R_##mpi_null;\
    varname##_table[id].fort=R_f_##mpi_null;\
    p_##varname++;\
    (*p_##varname)=id;\
    *(a_mpi_##varname)=A_##mpi_null;\
    unlock(varname##_Lock);\
}  \
  \
void varname##_translation_update(A_##type * a_mpi_##varname, R_##type mpi_##varname) {  \
    varname##_translation_t* conv =NULL;\
    varname##_translation_t* conv_cte =NULL;\
/*if(get_##type##_cte_r2a(a_mpi_##varname,&mpi_##varname)) return;*/\
    if((conv_cte=varname##_translation_get_key_from_const(mpi_##varname, a_mpi_##varname))){\
    memcpy(a_mpi_##varname,&(conv_cte->a_##varname##_key),  sizeof(A_##type)); \
    return;\
    }\
    lock(varname##_Lock);\
    int id=*p_##varname;\
    p_##varname--;\
    memset(a_mpi_##varname,0,sizeof(A_##type));\
    (*((int *)a_mpi_##varname))=id+f##varname;\
    memcpy(&(varname##_table[id].C),& mpi_##varname,sizeof( R_##type));\
    varname##_table[id].fort=R_##type##_c2f(mpi_##varname);\
    unlock(varname##_Lock);\
}  \
void varname##_translation_update_f(int mpi_##varname, int *a_mpi_##varname) {  \
    varname##_translation_t* conv =NULL;\
    varname##_translation_t* conv_cte =NULL;\
    R_##type tmp;\
/*if(get_##type##_cte_r2a(a_mpi_##varname,&mpi_##varname)) return;*/\
    /*if(conv_cte=varname##_translation_get_key_from_const(mpi_##varname, a_mpi_##varname)){\
    memcpy(a_mpi_##varname,&(conv_cte->a_##varname##_key),  sizeof(A_##type)); \
    return;\
    }*//*if((*a_mpi_##varname)<(varname##_size+f##varname) && (*a_mpi_##varname)>=f##varname) if  (varname##_table[*a_mpi_##varname].fort==mpi_##varname) return; \
*/\
    lock(varname##_Lock);\
    int id=*p_##varname;\
    p_##varname--;\
    memset(a_mpi_##varname,0,sizeof(int));\
    (*((int *)a_mpi_##varname))=id+f##varname;\
    tmp=R_##type##_f2c(mpi_##varname);\
    memcpy(&(varname##_table[id].C),&tmp,sizeof( R_##type));\
    varname##_table[id].fort=mpi_##varname;\
    /*printf ("%s uf %d %d\n",#varname,*a_mpi_##varname,mpi_##varname);*/\
    unlock(varname##_Lock);\
}  \
void varname##_translation_update_alloc_f(int mpi_##varname,int * a_mpi_##varname) {  \
    varname##_translation_t* conv =NULL;\
    varname##_translation_t* conv_cte =NULL;\
    R_##type tmp;\
/*if(get_##type_cte_r2a(a_mpi_##varname,&mpi_##varname)) return;*/\
    /*if(conv_cte=varname##_translation_get_key_from_const(mpi_##varname, a_mpi_##varname)){\
    memcpy(a_mpi_##varname,&(conv_cte->a_##varname##_key),  sizeof(A_##type)); \
    return;\
    }*/\
    /*printf ("%s uaf avant %d %d\n",#varname,*a_mpi_##varname,mpi_##varname);*/\
/*if((*a_mpi_##varname)<(varname##_size+f##varname) && (*a_mpi_##varname)>=f##varname) if  (varname##_table[*a_mpi_##varname].fort==mpi_##varname) return; */\
    lock(varname##_Lock);\
    int id=*p_##varname;\
    p_##varname--;\
    memset(a_mpi_##varname,0,sizeof(int));\
    (*((int *)a_mpi_##varname))=id+f##varname;\
    tmp=R_##type##_f2c(mpi_##varname);\
    memcpy(&(varname##_table[id].C),& tmp,sizeof( R_##type));\
    varname##_table[id].fort=mpi_##varname;\
    /*printf ("%s uaf %d %d\n",#varname,*a_mpi_##varname,mpi_##varname);*/\
    unlock(varname##_Lock);\
}  \
void varname##_translation_update_alloc(A_##type * a_mpi_##varname, R_##type mpi_##varname) {  \
    /* Hashtable */  \
    varname##_translation_t* conv_cte =NULL;\
    if((conv_cte=varname##_translation_get_key_from_const(mpi_##varname, a_mpi_##varname))){\
    memcpy(a_mpi_##varname,&(conv_cte->a_##varname##_key),  sizeof(A_##type)); \
    return;\
    }\
    lock(varname##_Lock);\
    int id=*p_##varname;\
    if((conv_cte=varname##_translation_get_key_from_const(mpi_##varname, a_mpi_##varname))){\
    memcpy(a_mpi_##varname,&(conv_cte->a_##varname##_key),  sizeof(A_##type)); \
    return; \
		} \
    p_##varname--;\
    memset(a_mpi_##varname,0,sizeof(A_##type));\
    (*((int *)a_mpi_##varname))=id+f##varname;\
    memcpy(&(varname##_table[id].C),& mpi_##varname,sizeof( R_##type));\
    varname##_table[id].fort=R_##type##_c2f(mpi_##varname);\
    unlock(varname##_Lock);\
}  \
  \
int varname##_translation_get_size() {  \
    return varname##_size;  \
}  \
  \
void varname##_translation_free_all() {  \
    HASH_CLEAR(hh, varname##_const_table);   \
    lock(varname##_Lock);\
    free( varname##_table);   \
    free( counter_##varname);   \
    unlock(varname##_Lock);\
}\

#define HASHTABLE_NO_OPT_NO_FORTRAN_FUNC(type,varname,mpi_null)  \
/*typedef struct {R_##type C;int idx;void *func_ptr} type##_container;*/\
static type##_container * varname##_table = NULL;  \
static type##_container * const_##varname##_table = NULL;  \
static varname##_translation_t* varname##_const_table = NULL;  \
int *counter_##varname=NULL;\
int f##varname=100000;\
int *p_##varname;\
int l##varname;\
int max##varname;\
int varname##_size;\
pthread_spinlock_t varname##_vLock;\
table_lock_t varname##_Lock=&varname##_vLock;\
size_t *varname##cte_list;\
int  varname##cte_list_size;\
/*  lock_init  */  \
void varname##_translation_init(void) {\
      int i;\
        char *envvar;\
        char varname1[256],varname2[256];\
        strcat(varname1,"WI4");\
        strcat(varname1,#type);\
        strcpy(varname2,varname1);\
        strcat(varname1,"_OFFSET");\
        strcat(varname2,"_TABLE_SIZE");\
if((envvar=getenv(varname1)))\
    f##varname=strtol(envvar,NULL,10);\
if((envvar=getenv(varname2)))\
     varname##_size=strtol(envvar,NULL,10);\
    else\
        varname##_size=1024*1024;\
        lock_init(varname##_Lock);\
    varname##_table=(type##_container *)malloc(varname##_size*sizeof(type##_container));\
    counter_##varname=(int*)malloc(varname##_size*sizeof(int));\
    p_##varname=counter_##varname+varname##_size-1;\
/*printf("alloc %p %p\n",counter_##varname,p_##varname);*/\
    for(i=0;i<varname##_size;i++) {\
        counter_##varname[i]=varname##_size-i-1;\
    }\
}  \
/*  ADD  */  \
void varname##_translation_add_const(A_##type a_mpi_##varname, R_##type mpi_##varname) {  \
    varname##_translation_t* conv = (varname##_translation_t*) malloc(sizeof(varname##_translation_t));  \
    memcpy(&(conv->a_##varname##_key), &a_mpi_##varname, sizeof(A_##type));  \
    memcpy(&(conv->r_##varname##_value), &mpi_##varname, sizeof(R_##type)); \
    HASH_ADD(hh, varname##_const_table, a_##varname##_key, sizeof(A_##type), conv);  \
}  \
  \
int varname##_translation_is_const(A_##type a_mpi_##varname) { \
    varname##_translation_t* conv;  \
    HASH_FIND(hh,varname##_const_table, &a_mpi_##varname, sizeof(A_##type), conv);  \
    return (int)(conv != NULL); \
} \
 \
/*  GET  */  \
void varname##_translation_get(A_##type a_mpi_##varname, R_##type *mpi_##varname) {  \
      int i,id;\
    varname##_translation_t* conv;  \
    HASH_FIND(hh,varname##_const_table, &a_mpi_##varname, sizeof(A_##type), conv);  \
   if(conv != NULL) { \
        *mpi_##varname=(conv->r_##varname##_value);  \
    } else { \
        id=((int)a_mpi_##varname)-f##varname;\
        memcpy(mpi_##varname,&(varname##_table[id].C), sizeof(R_##type));\
    }  \
}  \
/*  GET_KEY */  \
varname##_translation_t* varname##_translation_get_key_from_const(R_##type mpi_##varname, A_##type *a_mpi_##varname) {  \
    varname##_translation_t* conv;  \
    for (conv = varname##_const_table; conv != NULL; conv = conv->hh.next) {  \
        if (conv->r_##varname##_value == mpi_##varname) {  \
            return conv;  \
        }  \
    }  \
    type##_container *tmp=varname##_table;\
    while(tmp!=(varname##_table+varname##_size)) if(!memcmp(&mpi_##varname,&(tmp->C),sizeof(R_##type))) return (tmp-varname##_table)+f##varname;\
    return NULL;  \
}  \
  \
varname##_translation_t*  varname##_translation_get_key_from_value(R_##type mpi_##varname, A_##type *a_mpi_##varname) {  \
    varname##_translation_t* conv;  \
 for (conv = varname##_const_table; conv != NULL; conv = conv->hh.next) {  \
        if (conv->r_##varname##_value == mpi_##varname) {  \
            return conv;  \
        }  \
    }  \
    return NULL;  \
}\
void varname##_translation_add_funtion_ref(A_##type a_mpi_##varname,void *fn){\
 id=(*((int*)a_mpi_##varname))-f##varname;\
varname##_table[id].func_ptr=fn;\
}\
\
/* DEL */  \
void varname##_translation_del_f(int a_mpi_##varname) {  \
    int id;\
    lock(varname##_Lock);\
    id=a_mpi_##varname-f##varname;\
    if(id>=0&&id<=varname##_size-1)\
    {p_##varname++;(*p_##varname)=id;\
    }\
    unlock(varname##_Lock);\
}  \
void varname##_translation_del(A_##type * a_mpi_##varname) {  \
    int id;varname##_translation_t* conv;R_##type mpi_##varname;  \
    HASH_FIND(hh, varname##_const_table, a_mpi_##varname, sizeof(A_##type), conv);  \
   if(conv != NULL) {    \
          \
        return;  \
    }  \
    lock(varname##_Lock);\
    id=(*((int*)a_mpi_##varname))-f##varname;\
    p_##varname++;\
    (*p_##varname)=id;\
    munmap(varname##_table[id].fn,func_page_size);\
    unlock(varname##_Lock);\
}  \
  \
void varname##_translation_update(A_##type * a_mpi_##varname, R_##type mpi_##varname) {  \
    varname##_translation_t* conv =NULL;\
    varname##_translation_t* conv_cte =NULL;\
    if((conv_cte=varname##_translation_get_key_from_const(mpi_##varname, a_mpi_##varname))){\
    memcpy(a_mpi_##varname,&(conv_cte->a_##varname##_key),  sizeof(A_##type)); \
    return;\
    }\
    lock(varname##_Lock);\
    int id=*p_##varname;\
    p_##varname--;\
    memset(a_mpi_##varname,0,sizeof(A_##type));\
    (*((int *)a_mpi_##varname))=id+f##varname;\
    memcpy(&(varname##_table[id].C),& mpi_##varname,sizeof( R_##type));\
    unlock(varname##_Lock);\
}  \
void varname##_translation_update_alloc(A_##type * a_mpi_##varname, R_##type mpi_##varname) {  \
    lock(varname##_Lock);\
    int id=*p_##varname;\
    p_##varname--;\
    memset(a_mpi_##varname,0,sizeof(A_##type));\
    (*((int *)a_mpi_##varname))=id+f##varname;\
    memcpy(&(varname##_table[id].C),& mpi_##varname,sizeof( R_##type));\
    unlock(varname##_Lock);\
}  \
  \
int varname##_translation_get_size() {  \
    return varname##_size;  \
}  \
  \
void varname##_translation_free_all() {  \
    HASH_CLEAR(hh, varname##_const_table);   \
    lock(varname##_Lock);\
    free( varname##_table);   \
    free( counter_##varname);   \
    unlock(varname##_Lock);\
} \




#define HASHTABLE_NO_OPTI_FUNC(type, varname, mpi_null)   \
/*typedef struct {int fort;R_##type C;int idx;void *func_ptr} type##_container;*/\
static type##_container * varname##_table = NULL;  \
static type##_container * const_##varname##_table = NULL;  \
static varname##_translation_t* varname##_const_table = NULL;  \
int *counter_##varname=NULL;\
int f##varname=100000;\
int *p_##varname;\
int l##varname;\
int max##varname;\
int varname##_size;\
pthread_spinlock_t varname##_vLock;\
table_lock_t varname##_Lock=&varname##_vLock;\
size_t *varname##cte_list;\
int  varname##cte_list_size;\
/*R_##type R_##type##_f2c(int);\
int R_##type##_c2f(R_##type);\
*/\
/*  lock_init  */  \
void varname##_translation_init(void) {\
      int i;\
        char *envvar;\
        char varname1[256],varname2[256];\
        strcat(varname1,"WI4");\
        strcat(varname1,#type);\
        strcpy(varname2,varname1);\
        strcat(varname1,"_OFFSET");\
        strcat(varname2,"_TABLE_SIZE");\
if((envvar=getenv(varname1)))\
    f##varname=strtol(envvar,NULL,10);\
if((envvar=getenv(varname2)))\
     varname##_size=strtol(envvar,NULL,10);\
    else\
        varname##_size=1024*1024;\
        lock_init(varname##_Lock);\
    varname##_table=(type##_container *)malloc(varname##_size*sizeof(type##_container));\
    counter_##varname=(int*)malloc(varname##_size*sizeof(int));\
    p_##varname=counter_##varname+varname##_size-1;\
    for(i=0;i<varname##_size;i++) {\
        counter_##varname[i]=varname##_size-i-1;\
    }\
/*varname##cte_list=malloc(1024*1024*sizeof(void*));\
varname##cte_list_size=0;\
*/}  \
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
/*  GET  */  \
void varname##_translation_get(A_##type a_mpi_##varname, R_##type *mpi_##varname) {  \
      int i,id;\
    varname##_translation_t* conv;  \
    HASH_FIND(hh,varname##_const_table, &a_mpi_##varname, sizeof(A_##type), conv);  \
/* if(get_##type##_cte_a2r(&a_mpi_##varname,mpi_##varname)) return;*/\
   if(conv != NULL) { /*printf("ababa\n");*/\
        /*memcpy(mpi_##varname,&(conv->r_##varname##_value), sizeof(R_##type));*/*mpi_##varname=(conv->r_##varname##_value);  \
    } else { /* Not a constant */  \
        /* In an hashtable */   \
        id=((int)a_mpi_##varname)-f##varname;\
      /* if(id<0||id>= varname##_size) *mpi_##varname=R_##mpi_null;*/ \
       /* else*/ memcpy(mpi_##varname,&(varname##_table[id].C), sizeof(R_##type));\
    }  \
}  \
void varname##_translation_add_funtion_ref(A_##type a_mpi_##varname,void *fn){\
 id=(((int)a_mpi_##varname))-f##varname;\
varname##_table[id].func_ptr=fn;\
void varname##_translation_add_funtion_ref_f(int a_mpi_##varname,void *fn){\
 id=a_mpi_##varname-f##varname;\
varname##_table[id].func_ptr=fn;\
}\
void varname##_translation_get_f(int a_mpi_##varname, int *mpi_##varname) {  \
      int i,id;\
 /*   varname##_translation_t* conv;  \
    HASH_FIND(hh,varname##_const_table, &a_mpi_##varname, sizeof(A_##type), conv);  \
/* if(get_##type##_cte_a2r(&a_mpi_##varname,mpi_##varname)) return;*/\
  /* if(conv != NULL) { printf("ababa\n");*/\
        /*memcpy(mpi_##varname,&(conv->r_##varname##_value), sizeof(R_##type));*mpi_##varname=(conv->r_##varname##_value);  \
 */ /*  } else */{ /* Not a constant */  \
        /* In an hashtable */   \
        id=((int)a_mpi_##varname)-f##varname;\
      /*  if(id<0||id>=varname##_size) *mpi_##varname=R_##type##_c2f(R_##mpi_null);\
        else*/ memcpy(mpi_##varname,&(varname##_table[id].fort), sizeof(int));\
        /*printf ("%s gf %d %d\n",#varname,a_mpi_##varname,*mpi_##varname);\
    */}  \
}  \
/*  GET_KEY */  \
varname##_translation_t* varname##_translation_get_key_from_const(R_##type mpi_##varname, A_##type *a_mpi_##varname) {  \
    varname##_translation_t* conv;  \
    /* Search in const */  \
    for (conv = varname##_const_table; conv != NULL; conv = conv->hh.next) {  \
        if (conv->r_##varname##_value == mpi_##varname) {  \
            return conv;  \
        }  \
    }  \
    type##_container *tmp=varname##_table;\
    while(tmp!=(varname##_table+varname##_size)) if(!memcmp(&mpi_##varname,&(tmp->C),sizeof(R_##type))) return (tmp-varname##_table)+f##varname;\
    return NULL;  \
}  \
  \
varname##_translation_t*  varname##_translation_get_key_from_value(R_##type mpi_##varname, A_##type *a_mpi_##varname) {  \
    varname##_translation_t* conv;  \
 for (conv = varname##_const_table; conv != NULL; conv = conv->hh.next) {  \
        if (conv->r_##varname##_value == mpi_##varname) {  \
            return conv;  \
        }  \
    }  \
    return NULL;  \
}\
/* DEL */  \
void varname##_translation_del_f(int a_mpi_##varname) {  \
    int id;\
    lock(varname##_Lock);\
    id=a_mpi_##varname-f##varname;\
    if(id>=0&&id<=varname##_size-1)\
    {p_##varname++;(*p_##varname)=id;\
    }\
    unlock(varname##_Lock);\
}  \
void varname##_translation_del(A_##type * a_mpi_##varname) {  \
    int id;varname##_translation_t* conv;R_##type mpi_##varname;  \
    HASH_FIND(hh, varname##_const_table, a_mpi_##varname, sizeof(A_##type), conv);  \
/* if(get_##type##_cte_a2r(&a_mpi_##varname,mpi_##varname)) return;*/\
   if(conv != NULL) {    \
          \
        return;  \
    }  /*printf("%s %d delete\n",#varname,*a_mpi_##varname);*/\
    /* Hashtable */  \
    id=(*((int*)a_mpi_##varname))-f##varname;\
    /*printf("%d\n",id);*/if(id<0||id>=varname##_size)\
        return;\
    lock(varname##_Lock);\
    varname##_table[id].C=R_##mpi_null;\
    /*varname##_table[id].fort=R_##type##_c2f(mpi_null);*/\
    p_##varname++;\
    (*p_##varname)=id;\
    *(a_mpi_##varname)=(A_##mpi_null);\
    munmap(varname##_table[id].fn,func_page_size);\
    unlock(varname##_Lock);\
}  \
  \
void varname##_translation_update(A_##type * a_mpi_##varname, R_##type mpi_##varname) {  \
    varname##_translation_t* conv =NULL;\
    varname##_translation_t* conv_cte =NULL;\
/*if(get_##type##_cte_r2a(a_mpi_##varname,&mpi_##varname)) return;*/\
    if((conv_cte=varname##_translation_get_key_from_const(mpi_##varname, a_mpi_##varname))){\
    memcpy(a_mpi_##varname,&(conv_cte->a_##varname##_key),  sizeof(A_##type)); \
    return;\
    }\
    lock(varname##_Lock);\
    int id=*p_##varname;\
    p_##varname--;\
    memset(a_mpi_##varname,0,sizeof(A_##type));\
    (*((int *)a_mpi_##varname))=id+f##varname;\
    memcpy(&(varname##_table[id].C),& mpi_##varname,sizeof( R_##type));\
    /*varname##_table[id].fort=R_##type##_c2f(mpi_##varname);*/\
    unlock(varname##_Lock);\
}  \
void varname##_translation_update_f(int mpi_##varname, int *a_mpi_##varname) {  \
    varname##_translation_t* conv =NULL;\
    varname##_translation_t* conv_cte =NULL;\
    R_##type tmp;\
/*if(get_##type##_cte_r2a(a_mpi_##varname,&mpi_##varname)) return;*/\
    /*if(conv_cte=varname##_translation_get_key_from_const(mpi_##varname, a_mpi_##varname)){\
    memcpy(a_mpi_##varname,&(conv_cte->a_##varname##_key),  sizeof(A_##type)); \
    return;\
    }*//*if((*a_mpi_##varname)<(varname##_size+f##varname) && (*a_mpi_##varname)>=f##varname) if  (varname##_table[*a_mpi_##varname].fort==mpi_##varname) return; \
*/\
    lock(varname##_Lock);\
    int id=*p_##varname;\
    p_##varname--;\
    memset(a_mpi_##varname,0,sizeof(int));\
    (*((int *)a_mpi_##varname))=id+f##varname;\
    tmp=R_##type##_f2c(mpi_##varname);\
    memcpy(&(varname##_table[id].C),& tmp,sizeof( R_##type));\
    varname##_table[id].fort=mpi_##varname;\
    /*printf ("%s uf %d %d\n",#varname,*a_mpi_##varname,mpi_##varname);*/\
    unlock(varname##_Lock);\
}  \
void varname##_translation_update_alloc_f(int mpi_##varname,int * a_mpi_##varname) {  \
    varname##_translation_t* conv =NULL;\
    varname##_translation_t* conv_cte =NULL;\
    R_##type tmp;\
/*if(get_##type_cte_r2a(a_mpi_##varname,&mpi_##varname)) return;*/\
    /*if(conv_cte=varname##_translation_get_key_from_const(mpi_##varname, a_mpi_##varname)){\
    memcpy(a_mpi_##varname,&(conv_cte->a_##varname##_key),  sizeof(A_##type)); \
    return;\
    }*/\
    /*printf ("%s uaf avant %d %d\n",#varname,*a_mpi_##varname,mpi_##varname);*/\
/*if((*a_mpi_##varname)<(varname##_size+f##varname) && (*a_mpi_##varname)>=f##varname) if  (varname##_table[*a_mpi_##varname].fort==mpi_##varname) return; */\
    lock(varname##_Lock);\
    int id=*p_##varname;\
    p_##varname--;\
    memset(a_mpi_##varname,0,sizeof(int));\
    (*((int *)a_mpi_##varname))=id+f##varname;\
    tmp=R_##type##_f2c(mpi_##varname);\
    memcpy(&(varname##_table[id].C),& tmp,sizeof( R_##type));\
    varname##_table[id].fort=mpi_##varname;\
    /*printf ("%s uaf %d %d\n",#varname,*a_mpi_##varname,mpi_##varname);*/\
    unlock(varname##_Lock);\
}  \
void varname##_translation_update_alloc(A_##type * a_mpi_##varname, R_##type mpi_##varname) {  \
    /* Hashtable */  \
    varname##_translation_t* conv_cte =NULL;\
    if((conv_cte=varname##_translation_get_key_from_const(mpi_##varname, a_mpi_##varname))){\
    memcpy(a_mpi_##varname,&(conv_cte->a_##varname##_key),  sizeof(A_##type)); \
    return;\
    }\
    lock(varname##_Lock);\
    int id=*p_##varname;\
    if((conv_cte=varname##_translation_get_key_from_const(mpi_##varname, a_mpi_##varname))){\
    memcpy(a_mpi_##varname,&(conv_cte->a_##varname##_key),  sizeof(A_##type)); \
    return; \
		} \
    p_##varname--;\
    memset(a_mpi_##varname,0,sizeof(A_##type));\
    (*((int *)a_mpi_##varname))=id+f##varname;\
    memcpy(&(varname##_table[id].C),& mpi_##varname,sizeof( R_##type));\
    /*varname##_table[id].fort=R_##type##_c2f(mpi_##varname);*/\
    unlock(varname##_Lock);\
}  \
  \
int varname##_translation_get_size() {  \
    return varname##_size;  \
}  \
  \
void varname##_translation_free_all() {  \
    HASH_CLEAR(hh, varname##_const_table);   \
    lock(varname##_Lock);\
    free( varname##_table);   \
    free( counter_##varname);   \
    unlock(varname##_Lock);\
}\

#define NO_TABLE_NO_OPTI(type, varname, mpi_null)   \
void varname##_translation_add_const(A_##type a_mpi_##varname, R_##type mpi_##varname) {  \
} \
void varname##_translation_get(A_##type a_mpi_##varname, R_##type *mpi_##varname) {  \
*mpi_##varname=a_mpi_##varname;\
}  \
void varname##_translation_get_f(int a_mpi_##varname, int *mpi_##varname) {  \
*mpi_##varname=a_mpi_##varname;\
}  \
void varname##_translation_del(A_##type * a_mpi_##varname) {  \
}  \
  \
void varname##_translation_update(A_##type * a_mpi_##varname, R_##type mpi_##varname) {  \
*a_mpi_##varname=mpi_##varname;\
}  \
void varname##_translation_update_f(int mpi_##varname,int * a_mpi_##varname ) {  \
*a_mpi_##varname=mpi_##varname;\
}  \
void varname##_translation_update_alloc_f(int mpi_##varname,int * a_mpi_##varname)  {  \
*a_mpi_##varname=mpi_##varname;\
}  \
void varname##_translation_update_alloc(A_##type * a_mpi_##varname, R_##type mpi_##varname) {  \
*a_mpi_##varname=mpi_##varname;\
}  \
  \
int varname##_translation_get_size() {  \
    return 0; \
}  \
  \
void varname##_translation_free_all() {  \
}
typedef int A_MPI_Keyval;
typedef int R_MPI_Keyval;
typedef int A_MPI_Error;
typedef int R_MPI_Error;
NO_TABLE_NO_OPTI(MPI_Error,error,MPI_SUCCESS);
NO_TABLE_NO_OPTI(MPI_Keyval,keyval,0);
/* Communicator */
/* Communicator */
HASHTABLE_NO_OPTI(MPI_Comm,communicator, MPI_COMM_NULL);

/* Datatype */
typedef R_MPI_Datatype R_MPI_Type;
typedef A_MPI_Datatype A_MPI_Type;
HASHTABLE_NO_OPTI(MPI_Type,datatype, MPI_DATATYPE_NULL);

/* Errhandler */
HASHTABLE_NO_OPTI(MPI_Errhandler,errhandler, MPI_ERRHANDLER_NULL);

/* Op */
HASHTABLE_NO_OPTI(MPI_Op,operation, MPI_OP_NULL);

/* Group */
HASHTABLE_NO_OPTI(MPI_Group,group, MPI_GROUP_NULL);

/* Win */
HASHTABLE_NO_OPTI(MPI_Win,win, MPI_WIN_NULL);

/* Message */
HASHTABLE_NO_OPTI(MPI_Message,message, MPI_MESSAGE_NULL);

/* MPI_T_enum */
HASHTABLE_NO_OPT_NO_FORTRAN(MPI_T_enum, t_enum, MPI_T_ENUM_NULL);

/* MPI_T_cvar_handle */
HASHTABLE_NO_OPT_NO_FORTRAN(MPI_T_cvar_handle, cvar_handle, MPI_T_CVAR_HANDLE_NULL);

/* MPI_T_pvar_handle */
HASHTABLE_NO_OPT_NO_FORTRAN(MPI_T_pvar_handle, pvar_handle, MPI_T_PVAR_HANDLE_NULL);

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
/*   True hashtables  */
/*typedef struct {
    R_MPI_Request Creq;
    int           Freq;
    int           nb;
}__WI4MPI_req_container;*/
__WI4MPI_req_container* request_table = NULL;
R_MPI_Request* request_table_persist_request = NULL;
pthread_spinlock_t tt;
int fnb=10000;
int *counter_request=NULL;
int *p_req;
int req_size;
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
    int i;
    char *envvar;
    if((envvar=getenv("WI4MPI_REQUEST_OFFSET")))
            fnb=strtol(envvar,NULL,10);
    if((envvar=getenv("WI4MPI_REQUEST_TABLE_SIZE")))
            req_size=strtol(envvar,NULL,10);
    else
    req_size=1024*1024;
      lock_init(request_Lock);
      request_table = ( __WI4MPI_req_container*) calloc(req_size,sizeof(__WI4MPI_req_container));
      counter_request=(int *)malloc((req_size)*sizeof(int));
      p_req=counter_request+req_size-1;
      for( i =0;i<req_size;i++)
       {
            counter_request[i]=req_size-i-1;
       }
}
/*  GET  */
void request_translation_get_f(int a_mpi_request, int *mpi_request) {
    int id=(int)a_mpi_request;
   if(id<fnb)
    return;
    if(a_mpi_request==0)
     {   *mpi_request=0;
        return;
    } else { /* Not a constant */
        /* In a table */
                {
                   memcpy(mpi_request,&request_table[id-fnb].Freq,sizeof(int));
                 //  *non_blocking=request_table[id-fnb].nb;
               // printf("persist %d %p %p\n",id,*mpi_request,a_mpi_request);
                }
        }
    
}
void request_translation_get(A_MPI_Request a_mpi_request, R_MPI_Request *mpi_request, int* non_blocking) {
    int id=(int)a_mpi_request;
   if((id<fnb)||(id>(fnb+req_size)))
    {// const request        
         request_translation_t* conv;
     /*HASH_FIND(hh,request_const_table, &a_mpi_request, sizeof(A_MPI_Request), conv);
    
    if  (conv != NULL)
         memcpy( mpi_request,&(conv->r_request_value), sizeof(R_MPI_Request));

        return;*/
    if(a_mpi_request==A_MPI_REQUEST_NULL)
    {
        *mpi_request=R_MPI_REQUEST_NULL;
        return;
    }
    } else { /* Not a constant */
        /* In a table */
                {
                   memcpy(mpi_request,&request_table[id-fnb].Creq,sizeof(R_MPI_Request));
                   *non_blocking=request_table[id-fnb].nb;
               // printf("persist %d %p %p\n",id,*mpi_request,a_mpi_request);
                }
        }
    
}

int request_translation_get_key_from_const(R_MPI_Request mpi_request, A_MPI_Request *a_mpi_request) {
    request_translation_t* conv;
    /* Search in const */
    for (conv = request_const_table; conv != NULL; conv = conv->hh.next) {
        if (conv->r_request_value == mpi_request) {
            memcpy(a_mpi_request,&(conv->a_request_key),sizeof(A_MPI_Request));
            return 1;
        }
    }
    return 0;
}

/* DEL */
void request_translation_del_f(int a_mpi_request) {
    int id=((int)(a_mpi_request));
   if(id<fnb||id>fnb+req_size)
    {// const request        

        return;
    } 
    /* table */
    lock(request_Lock);
                     p_req++;
                    (*p_req)=id-fnb;


    unlock(request_Lock);
}
void request_translation_del(A_MPI_Request * a_mpi_request) {
    int id=((int)(*a_mpi_request));
   if(id<fnb||id>fnb+req_size)
    {// const request        

        return;
    } 
    /* table */
    lock(request_Lock);
                     p_req++;
                    (*p_req)=id-fnb;


    unlock(request_Lock);
}

void request_translation_update_f(int mpi_request,int * a_mpi_request) {
    if(mpi_request==R_f_MPI_REQUEST_NULL)
    {   
    A_MPI_Request tmp=(A_MPI_Request)(*a_mpi_request); 
request_translation_del(&tmp);
*a_mpi_request=0;
        return;
    }
    lock(request_Lock);
            int id=*p_req;
            p_req--;
             (*((int *)a_mpi_request))=id+fnb;
            
            memcpy(&(request_table[id].Freq),&mpi_request,sizeof(int));
            request_table[id].nb=1;
            //    printf("non block %d %p %p %p %p\n",id,mpi_request,*a_mpi_request,request_table_non_blocking[id-fnb],request_table_non_blocking);

              //  printf("persist %d %p %p\n",id,mpi_request,*a_mpi_request);
        
    
    unlock(request_Lock);
}
void request_translation_update_alloc_f(int mpi_request,int * a_mpi_request ) {
//    if(mpi_request==R_MPI_REQUEST_NULL)
//    {    *a_mpi_request=A_MPI_REQUEST_NULL;
//        return;
//    }
    lock(request_Lock);
            int id=*p_req;
            p_req--;
             (*((int *)a_mpi_request))=id+fnb;
            
            memcpy(&(request_table[id].Freq),&mpi_request,sizeof(int));
            request_table[id].nb=1;
            //    printf("non block %d %p %p %p %p\n",id,mpi_request,*a_mpi_request,request_table_non_blocking[id-fnb],request_table_non_blocking);

              //  printf("persist %d %p %p\n",id,mpi_request,*a_mpi_request);
        
    
    unlock(request_Lock);
}
/* UPDATE */
void request_translation_update(A_MPI_Request * a_mpi_request, R_MPI_Request mpi_request, int non_blocking) {
    if(mpi_request==R_MPI_REQUEST_NULL)
    {    *a_mpi_request=A_MPI_REQUEST_NULL;
        return;
    }
/*    if(request_translation_get_key_from_const( mpi_request, a_mpi_request))
        return;
*/    memset(a_mpi_request,0,sizeof(A_MPI_Request));
    lock(request_Lock);
            int id=*p_req;
            p_req--;
             (*((int *)a_mpi_request))=id+fnb;
            
            memcpy(&(request_table[id].Creq),&mpi_request,sizeof(R_MPI_Request));
            request_table[id].nb=1;
            //    printf("non block %d %p %p %p %p\n",id,mpi_request,*a_mpi_request,request_table_non_blocking[id-fnb],request_table_non_blocking);

              //  printf("persist %d %p %p\n",id,mpi_request,*a_mpi_request);
        
    
    unlock(request_Lock);
}

int request_translation_get_size() {
    int size = req_size;
    return size;
}

void request_translation_free_all() {
    lock(request_Lock);
    HASH_CLEAR(hh, request_const_table);
    free(request_table);
    free(counter_request);
    unlock(request_Lock);
}

//#if WRAPPER_MPI_VERSION > 21
/* File */
#if HASHTABLE_OPTI_FILE
HASHTABLE_OPTI(MPI_File,file);
#else
HASHTABLE_NO_OPTI(MPI_File,file, MPI_FILE_NULL);
#endif

/* Info */
#if HASHTABLE_OPTI_INFO
HASHTABLE_OPTI(MPI_Info,info);
#else
HASHTABLE_NO_OPTI(MPI_Info,info, MPI_INFO_NULL);
#endif

//#endif

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

/*#ifdef FORTRAN
#include <mpif_app.h>
#endif*/
#include "new_utils.h"
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


/*   True hashtables  */
int cmp(const void *a,const void *b)
{
    return ((long long)a)<((long long )b);
}
#define HASHTABLE_NO_OPTI(type, varname, mpi_null)   \
typedef struct {int fort;R_##type C;int idx;} type##_container;\
static type##_container * varname##_table = NULL;  \
static type##_container * const_##varname##_table = NULL;  \
static varname##_translation_t* varname##_const_table = NULL;  \
int *counter_##varname=NULL;\
int f##varname=100000;\
int *p_##varname;\
int l##varname;\
int max##varname;\
int varname##_size;\
pthread_spinlock_t varname##_vLock=1;\
table_lock_t varname##_Lock=&varname##_vLock;\
size_t *varname##cte_list;\
int  varname##cte_list_size;\
/*  lock_init  */  \
void varname##_translation_init(void) {\
      int i;\
        lock_init(varname##_Lock);\
    varname##_table=(type##_container *)malloc(1024*1024*sizeof(type##_container));\
    counter_##varname=(int*)malloc(1024*1024*sizeof(int));\
    p_##varname=counter_##varname+1024*1024-1;\
    for(i=0;i<1024*1024;i++) {\
        counter_##varname[i]=1024*1024-i-1;\
    }\
    varname##_size=1024*1024;\
varname##cte_list=malloc(1024*1024*sizeof(void*));\
varname##cte_list_size=0;\
}  \
/*void varname##_commit_const()\
{int i; \
int inter_inf=0,inter_sup=0,inter_size=0,tmp=0;\
qsort(varname##cte_list,varname##cte_list_size,sizeof(void*),cmp);\
for(i=0;i<varname##cte_list_size;i++){\
    if((varname##cte_list[i]-tmp-2)>inter_size){\
        inter_size=varname##cte_list[i]-tmp-2;\
        inter_inf=tmp+1;inter_sup=varname##cte_list[i]-1;\
}\
tmp=varname##cte_list[i];\
}\
if((2^31-tmp-2)>inter_size){\
        inter_size=2^31-tmp-2;\
        inter_inf=tmp+1;inter_sup=2^31-1;\
}\
f##varname=inter_inf;\
l##varname=inter_sup;\
max##varname=inter_size;\
if((-varname##cte_list[0]+varname##cte_list[varname##cte_list_size-1])<2*cte_list_size)\
{\
const_##varname##_table=malloc(2*(-varname##cte_list[0]+varname##cte_list[cte_list_size-1]+1)*sizeof(type##_container));\
const_##varname##_offset=varname##cte_list[0];\
varname##cte_list_size*=-1;\
}\
else\
if(varname##cte_list_size<8)\
{\
    const_##varname##_table=malloc(varname##cte_list_size*sizeof(type##_container));\
}else \
varname##cte_list_size=0;\
free(varname##cte_list);varname##cte_list=NULL;\
}\
R_##type C_get_cte_a2r(A_##type a_mpi_##varname) {\
if(varname##cte_list_size>0){\
int i;\
for(i=0;i<varname##cte_list_size;i++)\
if(const_##varname##_table[i].idx==(int)(a_mpi_##varname)){\
    return const_##varname##_table[i].C;\
}\
}else if(varname##cte_list_size<0){\
return const_##varname##_table[(int)(a_mpi_##varname)-const_##varname##_offset].C;\
}else {\
 varname##_translation_t *conv;\
 HASH_FIND(hh,varname##_const_table, &a_mpi_##varname, sizeof(A_##type), conv);  \
return conv->r_##varname##_value;\
}\
}\
int Fort_get_cte_a2r(int a_mpi_##varname) {\
if(varname##cte_list_size>0){\
int i;\
for(i=0;i<varname##cte_list_size;i++)\
if(const_##varname##_table[i].idx==(int)(a_mpi_##varname)){\
    return const_##varname##_table[i].C;\
}\
}else if(varname##cte_list_size<0){\
return const_##varname##_table[(int)(a_mpi_##varname)-const_##varname##_offset].C;\
}else {\
 varname##_translation_t *conv;\
 HASH_FIND(hh,varname##_const_table, &a_mpi_##varname, sizeof(A_##type), conv);  \
return local_MPI_##type_##c2f(conv->r_##varname##_value);\
}\
}\
int Fort_get_cte_r2a(int mpi_##varname) {\
if(varname##cte_list_size>0){\
int i;\
for(i=0;i<abs(varname##cte_list_size);i++)\
if(const_##varname##_table[i].Fort==(int)(mpi_##varname)){\
    return const_##varname##_table[i].idx;\
}\
else {\
    varname##_translation_t* conv;  \
        \
    for (conv = varname##_const_table; conv != NULL; conv = conv->hh.next) {  \
        if (conv->r_##varname##_value == mpi_##varname) {  \
            return conv->value;  \
        }  \
return (conv->r_##varname##_value);\
}\
}\
*/\
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
    if(conv != NULL) { /*printf("ababa\n");*/\
        /*memcpy(mpi_##varname,&(conv->r_##varname##_value), sizeof(R_##type));*/*mpi_##varname=(conv->r_##varname##_value);  \
    } else { /* Not a constant */  \
        /* In an hashtable */   \
        id=((int)a_mpi_##varname)-f##varname;\
        memcpy(mpi_##varname,&(varname##_table[id].C), sizeof(R_##type));\
    }  \
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
        if (conv->r_##varname##_value == mpi_##varname) {  \
            return conv;  \
        }  \
    }  \
    return NULL;  \
}\
/* DEL */  \
void varname##_translation_del(A_##type * a_mpi_##varname) {  \
    int id;varname##_translation_t* conv;  \
    HASH_FIND(hh, varname##_const_table, a_mpi_##varname, sizeof(A_##type), conv);  \
    if(conv != NULL) { /* constant */  \
        /* Nothing to delete */  \
        return;  \
    }  \
    /* Hashtable */  \
    lock(varname##_Lock);\
    id=(*((int*)a_mpi_##varname))-f##varname;\
    (*p_##varname)=id;\
    p_##varname++;\
    \
    unlock(varname##_Lock);\
}  \
  \
/*int varname##_fort_set(R_##type * r_mpi_##varname) {  \
    int ret;\
    lock(varname##_Lock);\
    int id=*p_##varname;\
    p_##varname--;\
    ret=id+f##varname;\
    memcpy(&(varname##_table[id].C),& mpi_##varname,sizeof( R_##type));\
    unlock(varname##_Lock);\
return ret;\
} */ \
void varname##_translation_update(A_##type * a_mpi_##varname, R_##type mpi_##varname) {  \
    varname##_translation_t* conv =NULL;\
    varname##_translation_t* conv_cte =NULL;\
    if(conv_cte=varname##_translation_get_key_from_const(mpi_##varname, a_mpi_##varname)){\
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
    /* Hashtable */  \
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
}\

/* Communicator */
HASHTABLE_NO_OPTI(MPI_Comm,communicator, R_MPI_COMM_NULL);

/* Datatype */
HASHTABLE_NO_OPTI(MPI_Datatype,datatype, R_MPI_DATATYPE_NULL);

/* Errhandler */
HASHTABLE_NO_OPTI(MPI_Errhandler,errhandler, R_MPI_ERRHANDLER_NULL);

/* Op */
HASHTABLE_NO_OPTI(MPI_Op,operation, R_MPI_OP_NULL);

/* Group */
HASHTABLE_NO_OPTI(MPI_Group,group, R_MPI_GROUP_NULL);

/* Win */
HASHTABLE_NO_OPTI(MPI_Win,win, R_MPI_WIN_NULL);

/* Message */
HASHTABLE_NO_OPTI(MPI_Message,message, R_MPI_MESSAGE_NULL);

/* MPI_T_enum */
HASHTABLE_NO_OPTI(MPI_T_enum, t_enum, R_MPI_T_ENUM_NULL);

/* MPI_T_cvar_handle */
HASHTABLE_NO_OPTI(MPI_T_cvar_handle, cvar_handle, R_MPI_T_CVAR_HANDLE_NULL);

/* MPI_T_pvar_handle */
HASHTABLE_NO_OPTI(MPI_T_pvar_handle, pvar_handle, R_MPI_T_PVAR_HANDLE_NULL);

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
typedef struct {
    R_MPI_Request Creq;
    int           Freq;
    int           nb;
}__WI4MPI_req_container;
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
      lock_init(request_Lock);
      request_table = ( __WI4MPI_req_container*) calloc(1024*1024,sizeof(__WI4MPI_req_container));
      counter_request=(int *)malloc((1024*1024)*sizeof(int));
      p_req=counter_request+1024*1024-1;
      for( i =0;i<1024*1024;i++)
       {
            counter_request[i]=1024*1024-i-1;
       }
    req_size=1024*1024;
}
/*  GET  */
void request_translation_get(A_MPI_Request a_mpi_request, R_MPI_Request *mpi_request, int* non_blocking) {
    int id=(int)a_mpi_request;
   if(id<fnb)
    {// const request        
         request_translation_t* conv;
     HASH_FIND(hh,request_const_table, &a_mpi_request, sizeof(A_MPI_Request), conv);
    
    if  (conv != NULL)
         memcpy( mpi_request,&(conv->r_request_value), sizeof(R_MPI_Request));

        return;
    if(a_mpi_request==0)
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
void request_translation_del(A_MPI_Request * a_mpi_request) {
    int id=*((int*)(a_mpi_request));
   if(id<fnb)
    {// const request        

        return;
    } 
    /* table */
    lock(request_Lock);
                     p_req++;
                    (*p_req)=id-fnb;


    unlock(request_Lock);
}

/* UPDATE */
void request_translation_update(A_MPI_Request * a_mpi_request, R_MPI_Request mpi_request, int non_blocking) {
//    if(mpi_request==R_MPI_REQUEST_NULL)
//    {    *a_mpi_request=A_MPI_REQUEST_NULL;
//        return;
//    }
    if(request_translation_get_key_from_const( mpi_request, a_mpi_request))
        return;
    memset(a_mpi_request,0,sizeof(A_MPI_Request));
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
HASHTABLE_NO_OPTI(MPI_File,file, R_MPI_FILE_NULL);
#endif

/* Info */
#if HASHTABLE_OPTI_INFO
HASHTABLE_OPTI(MPI_Info,info);
#else
HASHTABLE_NO_OPTI(MPI_Info,info, R_MPI_INFO_NULL);
#endif

//#endif

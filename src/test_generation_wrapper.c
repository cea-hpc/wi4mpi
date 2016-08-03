//############################# Wi4MPI License ###########################
//# `04/04/2016`                                                         #
//# Copyright or (C) or Copr. Commissariat a l'Energie Atomique         #
//#                                                                      #
//# IDDN.FR.001.210022.001.S.P.2014.000.10800                            #
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
 * This code is full generated
 */
#define _GNU_SOURCE
#include <stdio.h>
#include <dlfcn.h>
/*ompi constante*/
#if defined(OMPI_INTEL)
char ompi_mpi_comm_null[1024];
char ompi_mpi_comm_self[1024];
char ompi_mpi_comm_world[1024];
char ompi_mpi_2cplex[512];
char ompi_mpi_2dblcplex[512];
char ompi_mpi_2dblprec[512];
char ompi_mpi_2int[512];
char ompi_mpi_2integer[512];
char ompi_mpi_2real[512];
char ompi_mpi_aint[512];
char ompi_mpi_byte[512];
char ompi_mpi_c_bool[512];
char ompi_mpi_c_complex[512];
char ompi_mpi_c_double_complex[512];
char ompi_mpi_c_float_complex[512];
char ompi_mpi_c_long_double_complex[512];
char ompi_mpi_char[512];
char ompi_mpi_character[512];
char ompi_mpi_complex16[512];
char ompi_mpi_complex32[512];
char ompi_mpi_complex8[512];
char ompi_mpi_cplex[512];
char ompi_mpi_cxx_bool[512];
char ompi_mpi_cxx_cplex[512];
char ompi_mpi_cxx_dblcplex[512];
char ompi_mpi_cxx_ldblcplex[512];
char ompi_mpi_datatype_null[512];
char ompi_mpi_dblcplex[512];
char ompi_mpi_dblprec[512];
char ompi_mpi_double[512];
char ompi_mpi_double_int[512];
char ompi_mpi_float[512];
char ompi_mpi_float_int[512];
char ompi_mpi_int16_t[512];
char ompi_mpi_int32_t[512];
char ompi_mpi_int64_t[512];
char ompi_mpi_int8_t[512];
char ompi_mpi_int[512];
char ompi_mpi_integer16[512];
char ompi_mpi_integer1[512];
char ompi_mpi_integer2[512];
char ompi_mpi_integer4[512];
char ompi_mpi_integer8[512];
char ompi_mpi_integer[512];
char ompi_mpi_lb[512];
char ompi_mpi_ldblcplex[512];
char ompi_mpi_logical1[512];
char ompi_mpi_logical2[512];
char ompi_mpi_logical4[512];
char ompi_mpi_logical8[512];
char ompi_mpi_logical[512];
char ompi_mpi_long[512];
char ompi_mpi_long_double[512];
char ompi_mpi_long_int[512];
char ompi_mpi_long_long_int[512];
char ompi_mpi_longdbl_int[512];
char ompi_mpi_offset[512];
char ompi_mpi_packed[512];
char ompi_mpi_real16[512];
char ompi_mpi_real2[512];
char ompi_mpi_real4[512];
char ompi_mpi_real8[512];
char ompi_mpi_real[512];
char ompi_mpi_short[512];
char ompi_mpi_short_int[512];
char ompi_mpi_signed_char[512];
char ompi_mpi_ub[512];
char ompi_mpi_uint16_t[512];
char ompi_mpi_uint32_t[512];
char ompi_mpi_uint64_t[512];
char ompi_mpi_uint8_t[512];
char ompi_mpi_unsigned[512];
char ompi_mpi_unsigned_char[512];
char ompi_mpi_unsigned_long[512];
char ompi_mpi_unsigned_long_long[512];
char ompi_mpi_unsigned_short[512];
char ompi_mpi_wchar[512];
char ompi_mpi_errhandler_null[1024];
char ompi_mpi_errors_are_fatal[1024];
char ompi_mpi_errors_return[1024];
char ompi_mpi_file_null[1536];
char ompi_mpi_group_empty[256];
char ompi_mpi_group_null[256];
char ompi_mpi_info_null[256];
char ompi_mpi_op_band[2048];
char ompi_mpi_op_bor[2048];
char ompi_mpi_op_bxor[2048];
char ompi_mpi_op_land[2048];
char ompi_mpi_op_lor[2048];
char ompi_mpi_op_lxor[2048];
char ompi_mpi_op_max[2048];
char ompi_mpi_op_maxloc[2048];
char ompi_mpi_op_min[2048];
char ompi_mpi_op_minloc[2048];
char ompi_mpi_op_null[2048];
char ompi_mpi_op_prod[2048];
char ompi_mpi_op_replace[2048];
char ompi_mpi_op_sum[2048];
char ompi_request_null[256];
char ompi_mpi_win_null[512];
#endif
#include "mappers.h"

__thread int in_w=0;
#if defined(INTEL_OMPI) || defined(OMPI_INTEL)
int MPIR_Dup_fn(A_MPI_Comm oldcomm, int keyval, void *extra_state, void *attribute_val_in,
               void *attribute_val_out, int *flag)
{return 0;}
#endif

void wrapper_user_function(void* invec, void* inoutvec, int* len,R_MPI_Datatype* type)
{
    A_MPI_Datatype datatype_tmp;
    datatype_conv_r2a( &datatype_tmp,type);

    (ptr_user_func)(invec, inoutvec, len, &datatype_tmp);
}

static void wrapper_comm_handler_function(R_MPI_Comm* comm, int* err, ...)
{
    A_MPI_Comm comm_tmp;
    comm_conv_r2a(&comm_tmp,comm);

    (ptr_comm_fn_handler)(&comm_tmp, err, "", NULL);
}

static void wrapper_handler_function(R_MPI_Comm* comm, int* err, ...)
{
    A_MPI_Comm comm_tmp;
    comm_conv_a2r(&comm_tmp,comm);

    (ptr_handler_fn)(&comm_tmp, err, "", NULL);
}
int print(FILE* stream, const char* format, ...)
{
    int ret_status = 0;
#ifdef DEBUG
    va_list args;
    va_start(args,format);
    ret_status = fprintf(stream, format, args);
    va_end(args);
#endif 
    return ret_status;
}

typedef struct {
    A_MPI_Copy_function* cp_function;
    A_MPI_Delete_function* del_function;
} myKeyval_functions_t;

typedef struct {
    int keyval;
    myKeyval_functions_t* functions;
    UT_hash_handle hh;
} myKeyval_translation_t;

typedef struct {
    myKeyval_translation_t* table;
    pthread_mutex_t lock;
} myKeyval_translation_table_t;

static myKeyval_translation_table_t myKeyval_table = { NULL,
    PTHREAD_MUTEX_INITIALIZER
};

static myKeyval_translation_table_t* get_myKeyval_table() {
    return &myKeyval_table;
}

static inline void myKeyval_read_lock() {
    pthread_mutex_lock(&get_myKeyval_table()->lock);
}

static inline void myKeyval_read_unlock() {
    pthread_mutex_unlock(&get_myKeyval_table()->lock);
}

static inline void myKeyval_write_lock() {
    pthread_mutex_lock(&get_myKeyval_table()->lock);
}

static inline void myKeyval_write_unlock() {
    pthread_mutex_unlock(&get_myKeyval_table()->lock);
}
static void myKeyval_translation_add(int keyval,
        myKeyval_functions_t* functions)
{
    myKeyval_translation_t* conv;
    conv = malloc(sizeof(myKeyval_translation_t));
    conv->keyval = keyval;
    conv->functions = functions;
    myKeyval_write_lock();
    HASH_ADD_INT(get_myKeyval_table()->table, keyval, conv);
    HASH_FIND_INT(get_myKeyval_table()->table, &keyval, conv);
    assert(conv != NULL);
    print(stderr, "\t\tREGISTER keyval %d -> (%p, %p)\n", keyval,
            functions->cp_function, functions->del_function);
    myKeyval_write_unlock();
}

static myKeyval_functions_t* myKeyval_translation_get(int keyval)
{
    myKeyval_functions_t* functions;
    myKeyval_translation_t* conv;
    myKeyval_read_lock();
    HASH_FIND_INT(get_myKeyval_table()->table, &keyval, conv);
    if (conv != NULL)
    {
        functions = conv->functions;
        print(stderr, "\t\tkeyval %d -> (%p, %p)\n", keyval, functions->cp_function,
                functions->del_function);
    }
    else
    {
        return NULL;
    }
    myKeyval_read_unlock();
    return functions;
}

static void myKeyval_translation_del(int keyval)
{
    myKeyval_translation_t* conv;
    myKeyval_write_lock();
    HASH_FIND_INT(get_myKeyval_table()->table, &keyval, conv);
    assert(conv != NULL);
    HASH_DEL(get_myKeyval_table()->table, conv);
    print(stderr, "\t\tDELETE keyval %d\n", keyval);
    myKeyval_write_unlock();
    free(conv);
}
static int wrapper_copy_function(R_MPI_Comm comm, int keyval, void* extra_state,
        void* attribute_val_in, void* attribute_val_out, int* flag)
{
    A_MPI_Comm comm_tmp;
    comm_conv_r2a(&comm_tmp, &comm);
    A_MPI_Copy_function* ptr_copy_func = myKeyval_translation_get(keyval)->cp_function;
    int res = (ptr_copy_func)(comm_tmp, keyval, extra_state, attribute_val_in,attribute_val_out, flag);
    ptr_copy_func = NULL;
    return  error_code_conv_r2a(res);
}


static int wrapper_delete_function(R_MPI_Comm comm, int keyval,
        void* attribute_val, void* extra_state)
{
    A_MPI_Comm comm_tmp;
    comm_conv_r2a(&comm_tmp, &comm);
    A_MPI_Delete_function* ptr_delete_func=myKeyval_translation_get(keyval)->del_function;
    int res = (ptr_delete_func)(comm_tmp, keyval, attribute_val, extra_state);
    ptr_delete_func = NULL;
    return error_code_conv_r2a(res);
}

__asm__(
".global PMPI_Comm_create_keyval\n"
".weak MPI_Comm_create_keyval\n"
".set MPI_Comm_create_keyval,PMPI_Comm_create_keyval\n"
".extern in_w\n"
".extern A_MPI_Comm_create_keyval\n"
".extern R_MPI_Comm_create_keyval\n"
".type PMPI_Comm_create_keyval,@function\n"
".text\n"
"PMPI_Comm_create_keyval:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Comm_create_keyval\n"
"jmp *A_MPI_Comm_create_keyval@GOTPCREL(%rip)\n"
"inwrap_MPI_Comm_create_keyval:\n"
"jmp *R_MPI_Comm_create_keyval@GOTPCREL(%rip)\n"
".size PMPI_Comm_create_keyval,.-PMPI_Comm_create_keyval\n"
);



int (*LOCAL_MPI_Comm_create_keyval)(R_MPI_Comm_copy_attr_function *,R_MPI_Delete_function *,int *,void * );

int A_MPI_Comm_create_keyval(A_MPI_Comm_copy_attr_function * copy_fn,A_MPI_Comm_delete_attr_function * delete_fn,int * keyval,void * extra_state)
{     
#ifdef DEBUG
    printf("entre : A_MPI_Comm_create_keyval\n");
#endif
    myKeyval_functions_t* functions = NULL;
    R_MPI_Copy_function * copy_fn_tmp;
    R_MPI_Delete_function* delete_fn_tmp;
    if ((void*)copy_fn == (void*)A_MPI_NULL_COPY_FN)
    { 
        copy_fn_tmp = R_MPI_NULL_COPY_FN;
    }
    else if((void*) copy_fn == A_MPI_COMM_DUP_FN)
    { 
        copy_fn_tmp = R_MPI_COMM_DUP_FN;
    }
    else
    { 
        copy_fn_tmp = wrapper_copy_function;
    }
    if(delete_fn == ((A_MPI_Delete_function*) A_MPI_NULL_DELETE_FN)) {
        delete_fn_tmp = R_MPI_NULL_DELETE_FN;
    }
    else
    { 
        delete_fn_tmp = wrapper_delete_function;
    }

    int ret_tmp= LOCAL_MPI_Comm_create_keyval( copy_fn_tmp, delete_fn_tmp, keyval, extra_state);

    functions = (myKeyval_functions_t*) malloc(sizeof(myKeyval_functions_t));
    functions->cp_function = copy_fn;
    functions->del_function = delete_fn;
    myKeyval_translation_add(*keyval, functions);
#ifdef DEBUG
    printf("sort : A_MPI_Comm_create_keyval\n");
#endif

    return error_code_conv_r2a(ret_tmp);
}

int R_MPI_Comm_create_keyval(R_MPI_Copy_function * copy_fn,R_MPI_Delete_function * delete_fn,int * keyval,void * extra_state)
{
#ifdef DEBUF
 printf("entre : R_MPI_Comm_create_keyval\n");
#endif
 int ret_tmp = LOCAL_MPI_Comm_create_keyval( copy_fn, delete_fn, keyval, extra_state);
#ifdef DEBUG
 printf("sort : R_MPI_Comm_create_keyval\n");
#endif
 return ret_tmp;
}

__asm__(
".global PMPI_Keyval_create\n"
".weak MPI_Keyval_create\n"
".set MPI_Keyval_create,PMPI_Keyval_create\n"
".extern in_w\n"
".extern A_MPI_Keyval_create\n"
".extern R_MPI_Keyval_create\n"
".type PMPI_Keyval_create,@function\n"
".text\n"
"PMPI_Keyval_create:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Keyval_create\n"
"jmp *A_MPI_Keyval_create@GOTPCREL(%rip)\n"
"inwrap_MPI_Keyval_create:\n"
"jmp *R_MPI_Keyval_create@GOTPCREL(%rip)\n"
".size PMPI_Keyval_create,.-PMPI_Keyval_create\n"
);


int (*LOCAL_MPI_Keyval_create)(R_MPI_Copy_function *,R_MPI_Delete_function *,int *,void *);

int A_MPI_Keyval_create(A_MPI_Copy_function * copy_fn,A_MPI_Delete_function * delete_fn,int * keyval,void * extra_state)
{   
#ifdef DEBUG
    printf("entre : A_MPI_Keyva_create\n");
#endif
    myKeyval_functions_t* functions = NULL;
    R_MPI_Copy_function * copy_fn_tmp;
    R_MPI_Delete_function* delete_fn_tmp;
    if ((void*)copy_fn == (void*)A_MPI_NULL_COPY_FN)
    { 
        copy_fn_tmp = R_MPI_NULL_COPY_FN;
    }
    else if((void*) copy_fn == A_MPI_COMM_DUP_FN)
    { 
        copy_fn_tmp = R_MPI_COMM_DUP_FN;
    }
    else
    { 
        copy_fn_tmp = wrapper_copy_function;
    }
    if(delete_fn == ((A_MPI_Delete_function*) A_MPI_NULL_DELETE_FN)) {
        delete_fn_tmp = R_MPI_NULL_DELETE_FN;
    }
    else
    { 
        delete_fn_tmp = wrapper_delete_function;
    }

    int ret_tmp= LOCAL_MPI_Keyval_create( copy_fn_tmp, delete_fn_tmp, keyval, extra_state);

    functions = (myKeyval_functions_t*) malloc(sizeof(myKeyval_functions_t));
    functions->cp_function = copy_fn;
    functions->del_function = delete_fn;
    myKeyval_translation_add(*keyval, functions);
#ifdef DEBUG
    printf("sort : A_MPI_Keyval_create\n");
#endif

    return error_code_conv_r2a(ret_tmp);
}

int R_MPI_Keyval_create(R_MPI_Copy_function * copy_fn,R_MPI_Delete_function * delete_fn,int * keyval,void * extra_state)
{
#ifdef DEBUG
    printf("entre : R_MPI_create_keyval\n");
#endif
    int ret_tmp = LOCAL_MPI_Keyval_create(copy_fn, delete_fn, keyval, extra_state);
#ifdef DEBUG    
    printf("sort: R_MPI_create_keyval\n");
#endif
    return ret_tmp;
}


__asm__(
".global PMPI_Comm_free_keyval\n"
".weak MPI_Comm_free_keyval\n"
".set MPI_Comm_free_keyval,PMPI_Comm_free_keyval\n"
".extern in_w\n"
".extern A_MPI_Comm_free_keyval\n"
".extern R_MPI_Comm_free_keyval\n"
".type PMPI_Comm_free_keyval,@function\n"
".text\n"
"PMPI_Comm_free_keyval:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x08, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Comm_free_keyval\n"
"jmp *A_MPI_Comm_free_keyval@GOTPCREL(%rip)\n"
"inwrap_MPI_Comm_free_keyval:\n"
"jmp *R_MPI_Comm_free_keyval@GOTPCREL(%rip)\n"
".size PMPI_Comm_free_keyval,.-PMPI_Comm_free_keyval\n"
);


int (*LOCAL_MPI_Comm_free_keyval)(int *);

int A_MPI_Comm_free_keyval(int * comm_keyval)
{
#ifdef DEBUG
    printf("entre : A_MPI_Comm_free_keyval\n");
#endif

    int ret_tmp = LOCAL_MPI_Comm_free_keyval(comm_keyval);

    *comm_keyval=A_MPI_KEYVAL_INVALID;
#ifdef DEBUG
    printf("sort : A_MPI_Comm_free_keyval\n");
#endif      
    return error_code_conv_r2a(ret_tmp);
}

int R_MPI_Comm_free_keyval(int * comm_keyval)
{
#ifdef DEBUG
     printf("entre : R_MPI_Comm_free_keyval\n");
#endif
     int ret_tmp = LOCAL_MPI_Comm_free_keyval(comm_keyval);
#ifdef DEBUG
     printf("sort : R_MPI_Comm_free_keyval\n");
#endif
     return ret_tmp;
}

__asm__(
".global PMPI_Keyval_free\n"
".weak MPI_Keyval_free\n"
".set MPI_Keyval_free,PMPI_Keyval_free\n"
".extern in_w\n"
".extern A_MPI_Keyval_free\n"
".extern R_MPI_Keyval_free\n"
".type PMPI_Keyval_free,@function\n"
".text\n"
"PMPI_Keyval_free:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x08, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Keyval_free\n"
"jmp *A_MPI_Keyval_free@GOTPCREL(%rip)\n"
"inwrap_MPI_Keyval_free:\n"
"jmp *R_MPI_Keyval_free@GOTPCREL(%rip)\n"
".size PMPI_Keyval_free,.-PMPI_Keyval_free\n"
);

int (*LOCAL_MPI_Keyval_free)(int *);

int A_MPI_Keyval_free(int * keyval)
{
#ifdef DEBUG
    printf("entre : A_MPI_Keyval_free\n");
#endif
    int ret_tmp =  LOCAL_MPI_Keyval_free(keyval);
    *keyval=A_MPI_KEYVAL_INVALID;
#ifdef DEBUG
    printf("entre : A_MPI_Keyval_free\n");
#endif
    return error_code_conv_r2a(ret_tmp);
}

int R_MPI_Keyval_free(int * keyval)
{
#ifdef DEBUG
      printf("entre : R_MPI_Keyval_free\n");
#endif      
      int ret_tmp = LOCAL_MPI_Keyval_free(keyval);
#ifdef DEBUG      
      printf("sort : R_MPI_Keyval_free\n");
#endif      
      return ret_tmp;
}
int wrapper_datarep_read_conversion_fn(void * userbuf, R_MPI_Datatype datatype, int count, void *filebuf,
        R_MPI_Offset position, void *extra_state)
{
    A_MPI_Datatype datatype_tmp;
    datatype_conv_r2a(&datatype_tmp,&datatype);

    A_MPI_Offset offset_tmp = (A_MPI_Offset) position;
    int ret_tmp = (ptr_read_conversion_fn)(userbuf, datatype_tmp, count, filebuf, offset_tmp, extra_state);
    return ret_tmp;
}

int wrapper_datarep_write_conversion_fn(void * userbuf, R_MPI_Datatype datatype, int count, void *filebuf,
        R_MPI_Offset position, void *extra_state)
{
    A_MPI_Datatype datatype_tmp;
    datatype_conv_r2a(&datatype_tmp,&datatype);
    A_MPI_Offset offset_tmp = (A_MPI_Offset) position;
    int ret_tmp = (ptr_write_conversion_fn)(userbuf, datatype_tmp, count, filebuf, offset_tmp, extra_state);
    return ret_tmp;
}

int wrapper_datarep_extent_fn(R_MPI_Datatype datatype, R_MPI_Aint *file_extent, void* extra_state)
{
    A_MPI_Datatype datatype_tmp;
    datatype_conv_r2a(&datatype_tmp,&datatype);
    A_MPI_Aint *file_extent_tmp = (A_MPI_Aint*) file_extent;
    int ret_tmp = (ptr_extent_fn)(datatype_tmp, file_extent_tmp, extra_state);
    return ret_tmp;
}
int MPI_Send(void * buf,int count,A_MPI_Datatype datatype,int dest,int tag,A_MPI_Comm comm);
int (*LOCAL_MPI_Send)(void *,int,R_MPI_Datatype,int,int,R_MPI_Comm);

__asm__(
".global PMPI_Send\n"
".weak MPI_Send\n"
".set MPI_Send,PMPI_Send\n"
".extern in_w\n"
".extern A_MPI_Send\n"
".extern R_MPI_Send\n"
".type PMPI_Send,@function\n"
".text\n"
"PMPI_Send:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Send\n"
"jmp *A_MPI_Send@GOTPCREL(%rip)\n"
"inwrap_MPI_Send:\n"
"jmp *R_MPI_Send@GOTPCREL(%rip)\n"
".size PMPI_Send,.-PMPI_Send\n"

);

int A_MPI_Send(void * buf,int count,A_MPI_Datatype datatype,int dest,int tag,A_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : A_MPI_Send\n");
#endif
in_w=1;

void * buf_tmp;
const_buffer_conv_a2r(&buf,&buf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
int dest_tmp;
dest_conv_a2r(&dest,&dest_tmp);
int tag_tmp;
tag_conv_a2r(&tag,&tag_tmp);
R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
int ret_tmp= LOCAL_MPI_Send( buf_tmp, count, datatype_tmp, dest_tmp, tag_tmp, comm_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Send\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Send(void * buf,int count,R_MPI_Datatype datatype,int dest,int tag,R_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : R_MPI_Send\n");
#endif
int ret_tmp= LOCAL_MPI_Send( buf, count, datatype, dest, tag, comm);
#ifdef DEBUG
printf("sort : R_MPI_Send\n");
#endif
return ret_tmp;
}
int MPI_Recv(void * buf,int count,A_MPI_Datatype datatype,int source,int tag,A_MPI_Comm comm,A_MPI_Status * status);
int (*LOCAL_MPI_Recv)(void *,int,R_MPI_Datatype,int,int,R_MPI_Comm,R_MPI_Status *);

__asm__(
".global PMPI_Recv\n"
".weak MPI_Recv\n"
".set MPI_Recv,PMPI_Recv\n"
".extern in_w\n"
".extern A_MPI_Recv\n"
".extern R_MPI_Recv\n"
".type PMPI_Recv,@function\n"
".text\n"
"PMPI_Recv:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Recv\n"
"jmp *A_MPI_Recv@GOTPCREL(%rip)\n"
"inwrap_MPI_Recv:\n"
"jmp *R_MPI_Recv@GOTPCREL(%rip)\n"
".size PMPI_Recv,.-PMPI_Recv\n"

);

int A_MPI_Recv(void * buf,int count,A_MPI_Datatype datatype,int source,int tag,A_MPI_Comm comm,A_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : A_MPI_Recv\n");
#endif
in_w=1;

void * buf_tmp;
buffer_conv_a2r(&buf,&buf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
int source_tmp;
source_conv_a2r(&source,&source_tmp);
int tag_tmp;
tag_conv_a2r(&tag,&tag_tmp);
R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
R_MPI_Status  status_ltmp;
R_MPI_Status * status_tmp=&status_ltmp;
int ret_tmp= LOCAL_MPI_Recv( buf_tmp, count, datatype_tmp, source_tmp, tag_tmp, comm_tmp, status_tmp);
buffer_conv_r2a(&buf,&buf_tmp);
status_prt_conv_r2a(&status,&status_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Recv\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Recv(void * buf,int count,R_MPI_Datatype datatype,int source,int tag,R_MPI_Comm comm,R_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : R_MPI_Recv\n");
#endif
int ret_tmp= LOCAL_MPI_Recv( buf, count, datatype, source, tag, comm, status);
#ifdef DEBUG
printf("sort : R_MPI_Recv\n");
#endif
return ret_tmp;
}
int MPI_Get_count(A_MPI_Status * status,A_MPI_Datatype datatype,int * count);
int (*LOCAL_MPI_Get_count)(R_MPI_Status *,R_MPI_Datatype,int *);

__asm__(
".global PMPI_Get_count\n"
".weak MPI_Get_count\n"
".set MPI_Get_count,PMPI_Get_count\n"
".extern in_w\n"
".extern A_MPI_Get_count\n"
".extern R_MPI_Get_count\n"
".type PMPI_Get_count,@function\n"
".text\n"
"PMPI_Get_count:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Get_count\n"
"jmp *A_MPI_Get_count@GOTPCREL(%rip)\n"
"inwrap_MPI_Get_count:\n"
"jmp *R_MPI_Get_count@GOTPCREL(%rip)\n"
".size PMPI_Get_count,.-PMPI_Get_count\n"

);

int A_MPI_Get_count(A_MPI_Status * status,A_MPI_Datatype datatype,int * count)
{
#ifdef DEBUG
printf("entre : A_MPI_Get_count\n");
#endif
in_w=1;

R_MPI_Status  status_ltmp;
R_MPI_Status * status_tmp=&status_ltmp;
status_prt_conv_a2r(&status,&status_tmp);
R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);

int ret_tmp= LOCAL_MPI_Get_count( status_tmp, datatype_tmp, count);

in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Get_count\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Get_count(R_MPI_Status * status,R_MPI_Datatype datatype,int * count)
{
#ifdef DEBUG
printf("entre : R_MPI_Get_count\n");
#endif
int ret_tmp= LOCAL_MPI_Get_count( status, datatype, count);
#ifdef DEBUG
printf("sort : R_MPI_Get_count\n");
#endif
return ret_tmp;
}
int MPI_Bsend(void * buf,int count,A_MPI_Datatype datatype,int dest,int tag,A_MPI_Comm comm);
int (*LOCAL_MPI_Bsend)(void *,int,R_MPI_Datatype,int,int,R_MPI_Comm);

__asm__(
".global PMPI_Bsend\n"
".weak MPI_Bsend\n"
".set MPI_Bsend,PMPI_Bsend\n"
".extern in_w\n"
".extern A_MPI_Bsend\n"
".extern R_MPI_Bsend\n"
".type PMPI_Bsend,@function\n"
".text\n"
"PMPI_Bsend:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Bsend\n"
"jmp *A_MPI_Bsend@GOTPCREL(%rip)\n"
"inwrap_MPI_Bsend:\n"
"jmp *R_MPI_Bsend@GOTPCREL(%rip)\n"
".size PMPI_Bsend,.-PMPI_Bsend\n"

);

int A_MPI_Bsend(void * buf,int count,A_MPI_Datatype datatype,int dest,int tag,A_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : A_MPI_Bsend\n");
#endif
in_w=1;

void * buf_tmp;
const_buffer_conv_a2r(&buf,&buf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
int dest_tmp;
dest_conv_a2r(&dest,&dest_tmp);
int tag_tmp;
tag_conv_a2r(&tag,&tag_tmp);
R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
int ret_tmp= LOCAL_MPI_Bsend( buf_tmp, count, datatype_tmp, dest_tmp, tag_tmp, comm_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Bsend\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Bsend(void * buf,int count,R_MPI_Datatype datatype,int dest,int tag,R_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : R_MPI_Bsend\n");
#endif
int ret_tmp= LOCAL_MPI_Bsend( buf, count, datatype, dest, tag, comm);
#ifdef DEBUG
printf("sort : R_MPI_Bsend\n");
#endif
return ret_tmp;
}
int MPI_Ssend(void * buf,int count,A_MPI_Datatype datatype,int dest,int tag,A_MPI_Comm comm);
int (*LOCAL_MPI_Ssend)(void *,int,R_MPI_Datatype,int,int,R_MPI_Comm);

__asm__(
".global PMPI_Ssend\n"
".weak MPI_Ssend\n"
".set MPI_Ssend,PMPI_Ssend\n"
".extern in_w\n"
".extern A_MPI_Ssend\n"
".extern R_MPI_Ssend\n"
".type PMPI_Ssend,@function\n"
".text\n"
"PMPI_Ssend:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Ssend\n"
"jmp *A_MPI_Ssend@GOTPCREL(%rip)\n"
"inwrap_MPI_Ssend:\n"
"jmp *R_MPI_Ssend@GOTPCREL(%rip)\n"
".size PMPI_Ssend,.-PMPI_Ssend\n"

);

int A_MPI_Ssend(void * buf,int count,A_MPI_Datatype datatype,int dest,int tag,A_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : A_MPI_Ssend\n");
#endif
in_w=1;

void * buf_tmp;
const_buffer_conv_a2r(&buf,&buf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
int dest_tmp;
dest_conv_a2r(&dest,&dest_tmp);
int tag_tmp;
tag_conv_a2r(&tag,&tag_tmp);
R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
int ret_tmp= LOCAL_MPI_Ssend( buf_tmp, count, datatype_tmp, dest_tmp, tag_tmp, comm_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Ssend\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Ssend(void * buf,int count,R_MPI_Datatype datatype,int dest,int tag,R_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : R_MPI_Ssend\n");
#endif
int ret_tmp= LOCAL_MPI_Ssend( buf, count, datatype, dest, tag, comm);
#ifdef DEBUG
printf("sort : R_MPI_Ssend\n");
#endif
return ret_tmp;
}
int MPI_Rsend(void * buf,int count,A_MPI_Datatype datatype,int dest,int tag,A_MPI_Comm comm);
int (*LOCAL_MPI_Rsend)(void *,int,R_MPI_Datatype,int,int,R_MPI_Comm);

__asm__(
".global PMPI_Rsend\n"
".weak MPI_Rsend\n"
".set MPI_Rsend,PMPI_Rsend\n"
".extern in_w\n"
".extern A_MPI_Rsend\n"
".extern R_MPI_Rsend\n"
".type PMPI_Rsend,@function\n"
".text\n"
"PMPI_Rsend:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Rsend\n"
"jmp *A_MPI_Rsend@GOTPCREL(%rip)\n"
"inwrap_MPI_Rsend:\n"
"jmp *R_MPI_Rsend@GOTPCREL(%rip)\n"
".size PMPI_Rsend,.-PMPI_Rsend\n"

);

int A_MPI_Rsend(void * buf,int count,A_MPI_Datatype datatype,int dest,int tag,A_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : A_MPI_Rsend\n");
#endif
in_w=1;

void * buf_tmp;
const_buffer_conv_a2r(&buf,&buf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
int dest_tmp;
dest_conv_a2r(&dest,&dest_tmp);
int tag_tmp;
tag_conv_a2r(&tag,&tag_tmp);
R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
int ret_tmp= LOCAL_MPI_Rsend( buf_tmp, count, datatype_tmp, dest_tmp, tag_tmp, comm_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Rsend\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Rsend(void * buf,int count,R_MPI_Datatype datatype,int dest,int tag,R_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : R_MPI_Rsend\n");
#endif
int ret_tmp= LOCAL_MPI_Rsend( buf, count, datatype, dest, tag, comm);
#ifdef DEBUG
printf("sort : R_MPI_Rsend\n");
#endif
return ret_tmp;
}
int MPI_Buffer_attach(void * buffer,int size);
int (*LOCAL_MPI_Buffer_attach)(void *,int);

__asm__(
".global PMPI_Buffer_attach\n"
".weak MPI_Buffer_attach\n"
".set MPI_Buffer_attach,PMPI_Buffer_attach\n"
".extern in_w\n"
".extern A_MPI_Buffer_attach\n"
".extern R_MPI_Buffer_attach\n"
".type PMPI_Buffer_attach,@function\n"
".text\n"
"PMPI_Buffer_attach:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Buffer_attach\n"
"jmp *A_MPI_Buffer_attach@GOTPCREL(%rip)\n"
"inwrap_MPI_Buffer_attach:\n"
"jmp *R_MPI_Buffer_attach@GOTPCREL(%rip)\n"
".size PMPI_Buffer_attach,.-PMPI_Buffer_attach\n"

);

int A_MPI_Buffer_attach(void * buffer,int size)
{
#ifdef DEBUG
printf("entre : A_MPI_Buffer_attach\n");
#endif
in_w=1;

void * buffer_tmp;
buffer_conv_a2r(&buffer,&buffer_tmp);


int ret_tmp= LOCAL_MPI_Buffer_attach( buffer_tmp, size);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Buffer_attach\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Buffer_attach(void * buffer,int size)
{
#ifdef DEBUG
printf("entre : R_MPI_Buffer_attach\n");
#endif
int ret_tmp= LOCAL_MPI_Buffer_attach( buffer, size);
#ifdef DEBUG
printf("sort : R_MPI_Buffer_attach\n");
#endif
return ret_tmp;
}
int MPI_Buffer_detach(void * buffer_addr,int * size);
int (*LOCAL_MPI_Buffer_detach)(void *,int *);

__asm__(
".global PMPI_Buffer_detach\n"
".weak MPI_Buffer_detach\n"
".set MPI_Buffer_detach,PMPI_Buffer_detach\n"
".extern in_w\n"
".extern A_MPI_Buffer_detach\n"
".extern R_MPI_Buffer_detach\n"
".type PMPI_Buffer_detach,@function\n"
".text\n"
"PMPI_Buffer_detach:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Buffer_detach\n"
"jmp *A_MPI_Buffer_detach@GOTPCREL(%rip)\n"
"inwrap_MPI_Buffer_detach:\n"
"jmp *R_MPI_Buffer_detach@GOTPCREL(%rip)\n"
".size PMPI_Buffer_detach,.-PMPI_Buffer_detach\n"

);

int A_MPI_Buffer_detach(void * buffer_addr,int * size)
{
#ifdef DEBUG
printf("entre : A_MPI_Buffer_detach\n");
#endif
in_w=1;

void * buffer_addr_tmp;
buffer_conv_a2r(&buffer_addr,&buffer_addr_tmp);

int ret_tmp= LOCAL_MPI_Buffer_detach( buffer_addr_tmp, size);
buffer_conv_r2a(&buffer_addr,&buffer_addr_tmp);

in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Buffer_detach\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Buffer_detach(void * buffer_addr,int * size)
{
#ifdef DEBUG
printf("entre : R_MPI_Buffer_detach\n");
#endif
int ret_tmp= LOCAL_MPI_Buffer_detach( buffer_addr, size);
#ifdef DEBUG
printf("sort : R_MPI_Buffer_detach\n");
#endif
return ret_tmp;
}
int MPI_Isend(void * buf,int count,A_MPI_Datatype datatype,int dest,int tag,A_MPI_Comm comm,A_MPI_Request * request);
int (*LOCAL_MPI_Isend)(void *,int,R_MPI_Datatype,int,int,R_MPI_Comm,R_MPI_Request *);

__asm__(
".global PMPI_Isend\n"
".weak MPI_Isend\n"
".set MPI_Isend,PMPI_Isend\n"
".extern in_w\n"
".extern A_MPI_Isend\n"
".extern R_MPI_Isend\n"
".type PMPI_Isend,@function\n"
".text\n"
"PMPI_Isend:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Isend\n"
"jmp *A_MPI_Isend@GOTPCREL(%rip)\n"
"inwrap_MPI_Isend:\n"
"jmp *R_MPI_Isend@GOTPCREL(%rip)\n"
".size PMPI_Isend,.-PMPI_Isend\n"

);

int A_MPI_Isend(void * buf,int count,A_MPI_Datatype datatype,int dest,int tag,A_MPI_Comm comm,A_MPI_Request * request)
{
#ifdef DEBUG
printf("entre : A_MPI_Isend\n");
#endif
in_w=1;

void * buf_tmp;
const_buffer_conv_a2r(&buf,&buf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
int dest_tmp;
dest_conv_a2r(&dest,&dest_tmp);
int tag_tmp;
tag_conv_a2r(&tag,&tag_tmp);
R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
R_MPI_Request  request_ltmp;
R_MPI_Request * request_tmp=&request_ltmp;
int ret_tmp= LOCAL_MPI_Isend( buf_tmp, count, datatype_tmp, dest_tmp, tag_tmp, comm_tmp, request_tmp);
if(ret_tmp == R_MPI_SUCCESS){
request_ptr_conv_r2a(&request,&request_tmp);
}
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Isend\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Isend(void * buf,int count,R_MPI_Datatype datatype,int dest,int tag,R_MPI_Comm comm,R_MPI_Request * request)
{
#ifdef DEBUG
printf("entre : R_MPI_Isend\n");
#endif
int ret_tmp= LOCAL_MPI_Isend( buf, count, datatype, dest, tag, comm, request);
#ifdef DEBUG
printf("sort : R_MPI_Isend\n");
#endif
return ret_tmp;
}
int MPI_Ibsend(void * buf,int count,A_MPI_Datatype datatype,int dest,int tag,A_MPI_Comm comm,A_MPI_Request * request);
int (*LOCAL_MPI_Ibsend)(void *,int,R_MPI_Datatype,int,int,R_MPI_Comm,R_MPI_Request *);

__asm__(
".global PMPI_Ibsend\n"
".weak MPI_Ibsend\n"
".set MPI_Ibsend,PMPI_Ibsend\n"
".extern in_w\n"
".extern A_MPI_Ibsend\n"
".extern R_MPI_Ibsend\n"
".type PMPI_Ibsend,@function\n"
".text\n"
"PMPI_Ibsend:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Ibsend\n"
"jmp *A_MPI_Ibsend@GOTPCREL(%rip)\n"
"inwrap_MPI_Ibsend:\n"
"jmp *R_MPI_Ibsend@GOTPCREL(%rip)\n"
".size PMPI_Ibsend,.-PMPI_Ibsend\n"

);

int A_MPI_Ibsend(void * buf,int count,A_MPI_Datatype datatype,int dest,int tag,A_MPI_Comm comm,A_MPI_Request * request)
{
#ifdef DEBUG
printf("entre : A_MPI_Ibsend\n");
#endif
in_w=1;

void * buf_tmp;
const_buffer_conv_a2r(&buf,&buf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
int dest_tmp;
dest_conv_a2r(&dest,&dest_tmp);
int tag_tmp;
tag_conv_a2r(&tag,&tag_tmp);
R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
R_MPI_Request  request_ltmp;
R_MPI_Request * request_tmp=&request_ltmp;
int ret_tmp= LOCAL_MPI_Ibsend( buf_tmp, count, datatype_tmp, dest_tmp, tag_tmp, comm_tmp, request_tmp);
if(ret_tmp == R_MPI_SUCCESS){
request_ptr_conv_r2a(&request,&request_tmp);
}
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Ibsend\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Ibsend(void * buf,int count,R_MPI_Datatype datatype,int dest,int tag,R_MPI_Comm comm,R_MPI_Request * request)
{
#ifdef DEBUG
printf("entre : R_MPI_Ibsend\n");
#endif
int ret_tmp= LOCAL_MPI_Ibsend( buf, count, datatype, dest, tag, comm, request);
#ifdef DEBUG
printf("sort : R_MPI_Ibsend\n");
#endif
return ret_tmp;
}
int MPI_Issend(void * buf,int count,A_MPI_Datatype datatype,int dest,int tag,A_MPI_Comm comm,A_MPI_Request * request);
int (*LOCAL_MPI_Issend)(void *,int,R_MPI_Datatype,int,int,R_MPI_Comm,R_MPI_Request *);

__asm__(
".global PMPI_Issend\n"
".weak MPI_Issend\n"
".set MPI_Issend,PMPI_Issend\n"
".extern in_w\n"
".extern A_MPI_Issend\n"
".extern R_MPI_Issend\n"
".type PMPI_Issend,@function\n"
".text\n"
"PMPI_Issend:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Issend\n"
"jmp *A_MPI_Issend@GOTPCREL(%rip)\n"
"inwrap_MPI_Issend:\n"
"jmp *R_MPI_Issend@GOTPCREL(%rip)\n"
".size PMPI_Issend,.-PMPI_Issend\n"

);

int A_MPI_Issend(void * buf,int count,A_MPI_Datatype datatype,int dest,int tag,A_MPI_Comm comm,A_MPI_Request * request)
{
#ifdef DEBUG
printf("entre : A_MPI_Issend\n");
#endif
in_w=1;

void * buf_tmp;
const_buffer_conv_a2r(&buf,&buf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
int dest_tmp;
dest_conv_a2r(&dest,&dest_tmp);
int tag_tmp;
tag_conv_a2r(&tag,&tag_tmp);
R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
R_MPI_Request  request_ltmp;
R_MPI_Request * request_tmp=&request_ltmp;
int ret_tmp= LOCAL_MPI_Issend( buf_tmp, count, datatype_tmp, dest_tmp, tag_tmp, comm_tmp, request_tmp);
if(ret_tmp == R_MPI_SUCCESS){
request_ptr_conv_r2a(&request,&request_tmp);
}
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Issend\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Issend(void * buf,int count,R_MPI_Datatype datatype,int dest,int tag,R_MPI_Comm comm,R_MPI_Request * request)
{
#ifdef DEBUG
printf("entre : R_MPI_Issend\n");
#endif
int ret_tmp= LOCAL_MPI_Issend( buf, count, datatype, dest, tag, comm, request);
#ifdef DEBUG
printf("sort : R_MPI_Issend\n");
#endif
return ret_tmp;
}
int MPI_Irsend(void * buf,int count,A_MPI_Datatype datatype,int dest,int tag,A_MPI_Comm comm,A_MPI_Request * request);
int (*LOCAL_MPI_Irsend)(void *,int,R_MPI_Datatype,int,int,R_MPI_Comm,R_MPI_Request *);

__asm__(
".global PMPI_Irsend\n"
".weak MPI_Irsend\n"
".set MPI_Irsend,PMPI_Irsend\n"
".extern in_w\n"
".extern A_MPI_Irsend\n"
".extern R_MPI_Irsend\n"
".type PMPI_Irsend,@function\n"
".text\n"
"PMPI_Irsend:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Irsend\n"
"jmp *A_MPI_Irsend@GOTPCREL(%rip)\n"
"inwrap_MPI_Irsend:\n"
"jmp *R_MPI_Irsend@GOTPCREL(%rip)\n"
".size PMPI_Irsend,.-PMPI_Irsend\n"

);

int A_MPI_Irsend(void * buf,int count,A_MPI_Datatype datatype,int dest,int tag,A_MPI_Comm comm,A_MPI_Request * request)
{
#ifdef DEBUG
printf("entre : A_MPI_Irsend\n");
#endif
in_w=1;

void * buf_tmp;
const_buffer_conv_a2r(&buf,&buf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
int dest_tmp;
dest_conv_a2r(&dest,&dest_tmp);
int tag_tmp;
tag_conv_a2r(&tag,&tag_tmp);
R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
R_MPI_Request  request_ltmp;
R_MPI_Request * request_tmp=&request_ltmp;
int ret_tmp= LOCAL_MPI_Irsend( buf_tmp, count, datatype_tmp, dest_tmp, tag_tmp, comm_tmp, request_tmp);
if(ret_tmp == R_MPI_SUCCESS){
request_ptr_conv_r2a(&request,&request_tmp);
}
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Irsend\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Irsend(void * buf,int count,R_MPI_Datatype datatype,int dest,int tag,R_MPI_Comm comm,R_MPI_Request * request)
{
#ifdef DEBUG
printf("entre : R_MPI_Irsend\n");
#endif
int ret_tmp= LOCAL_MPI_Irsend( buf, count, datatype, dest, tag, comm, request);
#ifdef DEBUG
printf("sort : R_MPI_Irsend\n");
#endif
return ret_tmp;
}
int MPI_Irecv(void * buf,int count,A_MPI_Datatype datatype,int source,int tag,A_MPI_Comm comm,A_MPI_Request * request);
int (*LOCAL_MPI_Irecv)(void *,int,R_MPI_Datatype,int,int,R_MPI_Comm,R_MPI_Request *);

__asm__(
".global PMPI_Irecv\n"
".weak MPI_Irecv\n"
".set MPI_Irecv,PMPI_Irecv\n"
".extern in_w\n"
".extern A_MPI_Irecv\n"
".extern R_MPI_Irecv\n"
".type PMPI_Irecv,@function\n"
".text\n"
"PMPI_Irecv:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Irecv\n"
"jmp *A_MPI_Irecv@GOTPCREL(%rip)\n"
"inwrap_MPI_Irecv:\n"
"jmp *R_MPI_Irecv@GOTPCREL(%rip)\n"
".size PMPI_Irecv,.-PMPI_Irecv\n"

);

int A_MPI_Irecv(void * buf,int count,A_MPI_Datatype datatype,int source,int tag,A_MPI_Comm comm,A_MPI_Request * request)
{
#ifdef DEBUG
printf("entre : A_MPI_Irecv\n");
#endif
in_w=1;

void * buf_tmp;
buffer_conv_a2r(&buf,&buf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
int source_tmp;
source_conv_a2r(&source,&source_tmp);
int tag_tmp;
tag_conv_a2r(&tag,&tag_tmp);
R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
R_MPI_Request  request_ltmp;
R_MPI_Request * request_tmp=&request_ltmp;
int ret_tmp= LOCAL_MPI_Irecv( buf_tmp, count, datatype_tmp, source_tmp, tag_tmp, comm_tmp, request_tmp);
buffer_conv_r2a(&buf,&buf_tmp);
if(ret_tmp == R_MPI_SUCCESS){
request_ptr_conv_r2a(&request,&request_tmp);
}
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Irecv\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Irecv(void * buf,int count,R_MPI_Datatype datatype,int source,int tag,R_MPI_Comm comm,R_MPI_Request * request)
{
#ifdef DEBUG
printf("entre : R_MPI_Irecv\n");
#endif
int ret_tmp= LOCAL_MPI_Irecv( buf, count, datatype, source, tag, comm, request);
#ifdef DEBUG
printf("sort : R_MPI_Irecv\n");
#endif
return ret_tmp;
}
int MPI_Wait(A_MPI_Request * request,A_MPI_Status * status);
int (*LOCAL_MPI_Wait)(R_MPI_Request *,R_MPI_Status *);

__asm__(
".global PMPI_Wait\n"
".weak MPI_Wait\n"
".set MPI_Wait,PMPI_Wait\n"
".extern in_w\n"
".extern A_MPI_Wait\n"
".extern R_MPI_Wait\n"
".type PMPI_Wait,@function\n"
".text\n"
"PMPI_Wait:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Wait\n"
"jmp *A_MPI_Wait@GOTPCREL(%rip)\n"
"inwrap_MPI_Wait:\n"
"jmp *R_MPI_Wait@GOTPCREL(%rip)\n"
".size PMPI_Wait,.-PMPI_Wait\n"

);

int A_MPI_Wait(A_MPI_Request * request,A_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : A_MPI_Wait\n");
#endif
in_w=1;

R_MPI_Request  request_ltmp;
R_MPI_Request * request_tmp=&request_ltmp;
request_ptr_conv_a2r(&request,&request_tmp);
R_MPI_Status  status_ltmp;
R_MPI_Status * status_tmp=&status_ltmp;
int ret_tmp= LOCAL_MPI_Wait( request_tmp, status_tmp);
if(ret_tmp == R_MPI_SUCCESS){
 if(*request_tmp == R_MPI_REQUEST_NULL){
request_ptr_delete(&request,&request_tmp);
}
}
status_prt_conv_r2a(&status,&status_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Wait\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Wait(R_MPI_Request * request,R_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : R_MPI_Wait\n");
#endif
int ret_tmp= LOCAL_MPI_Wait( request, status);
#ifdef DEBUG
printf("sort : R_MPI_Wait\n");
#endif
return ret_tmp;
}
int MPI_Test(A_MPI_Request * request,int * flag,A_MPI_Status * status);
int (*LOCAL_MPI_Test)(R_MPI_Request *,int *,R_MPI_Status *);

__asm__(
".global PMPI_Test\n"
".weak MPI_Test\n"
".set MPI_Test,PMPI_Test\n"
".extern in_w\n"
".extern A_MPI_Test\n"
".extern R_MPI_Test\n"
".type PMPI_Test,@function\n"
".text\n"
"PMPI_Test:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Test\n"
"jmp *A_MPI_Test@GOTPCREL(%rip)\n"
"inwrap_MPI_Test:\n"
"jmp *R_MPI_Test@GOTPCREL(%rip)\n"
".size PMPI_Test,.-PMPI_Test\n"

);

int A_MPI_Test(A_MPI_Request * request,int * flag,A_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : A_MPI_Test\n");
#endif
in_w=1;

R_MPI_Request  request_ltmp;
R_MPI_Request * request_tmp=&request_ltmp;
request_ptr_conv_a2r(&request,&request_tmp);

R_MPI_Status  status_ltmp;
R_MPI_Status * status_tmp=&status_ltmp;
int ret_tmp= LOCAL_MPI_Test( request_tmp, flag, status_tmp);
if(ret_tmp == R_MPI_SUCCESS){
if(*flag)
 if(*request_tmp == R_MPI_REQUEST_NULL){
request_ptr_delete(&request,&request_tmp);
}
}

status_prt_conv_r2a(&status,&status_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Test\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Test(R_MPI_Request * request,int * flag,R_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : R_MPI_Test\n");
#endif
int ret_tmp= LOCAL_MPI_Test( request, flag, status);
#ifdef DEBUG
printf("sort : R_MPI_Test\n");
#endif
return ret_tmp;
}
int MPI_Request_free(A_MPI_Request * request);
int (*LOCAL_MPI_Request_free)(R_MPI_Request *);

__asm__(
".global PMPI_Request_free\n"
".weak MPI_Request_free\n"
".set MPI_Request_free,PMPI_Request_free\n"
".extern in_w\n"
".extern A_MPI_Request_free\n"
".extern R_MPI_Request_free\n"
".type PMPI_Request_free,@function\n"
".text\n"
"PMPI_Request_free:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Request_free\n"
"jmp *A_MPI_Request_free@GOTPCREL(%rip)\n"
"inwrap_MPI_Request_free:\n"
"jmp *R_MPI_Request_free@GOTPCREL(%rip)\n"
".size PMPI_Request_free,.-PMPI_Request_free\n"

);

int A_MPI_Request_free(A_MPI_Request * request)
{
#ifdef DEBUG
printf("entre : A_MPI_Request_free\n");
#endif
in_w=1;

R_MPI_Request  request_ltmp;
R_MPI_Request * request_tmp=&request_ltmp;
request_ptr_conv_a2r(&request,&request_tmp);
int ret_tmp= LOCAL_MPI_Request_free( request_tmp);
if(ret_tmp == R_MPI_SUCCESS){
request_pers_ptr_delete(&request,&request_tmp);
request_ptr_delete(&request,&request_tmp);
}
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Request_free\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Request_free(R_MPI_Request * request)
{
#ifdef DEBUG
printf("entre : R_MPI_Request_free\n");
#endif
int ret_tmp= LOCAL_MPI_Request_free( request);
#ifdef DEBUG
printf("sort : R_MPI_Request_free\n");
#endif
return ret_tmp;
}
int MPI_Iprobe(int source,int tag,A_MPI_Comm comm,int * flag,A_MPI_Status * status);
int (*LOCAL_MPI_Iprobe)(int,int,R_MPI_Comm,int *,R_MPI_Status *);

__asm__(
".global PMPI_Iprobe\n"
".weak MPI_Iprobe\n"
".set MPI_Iprobe,PMPI_Iprobe\n"
".extern in_w\n"
".extern A_MPI_Iprobe\n"
".extern R_MPI_Iprobe\n"
".type PMPI_Iprobe,@function\n"
".text\n"
"PMPI_Iprobe:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Iprobe\n"
"jmp *A_MPI_Iprobe@GOTPCREL(%rip)\n"
"inwrap_MPI_Iprobe:\n"
"jmp *R_MPI_Iprobe@GOTPCREL(%rip)\n"
".size PMPI_Iprobe,.-PMPI_Iprobe\n"

);

int A_MPI_Iprobe(int source,int tag,A_MPI_Comm comm,int * flag,A_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : A_MPI_Iprobe\n");
#endif
in_w=1;

int source_tmp;
source_conv_a2r(&source,&source_tmp);
int tag_tmp;
tag_conv_a2r(&tag,&tag_tmp);
R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);

R_MPI_Status  status_ltmp;
R_MPI_Status * status_tmp=&status_ltmp;
int ret_tmp= LOCAL_MPI_Iprobe( source_tmp, tag_tmp, comm_tmp, flag, status_tmp);

status_prt_conv_r2a(&status,&status_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Iprobe\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Iprobe(int source,int tag,R_MPI_Comm comm,int * flag,R_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : R_MPI_Iprobe\n");
#endif
int ret_tmp= LOCAL_MPI_Iprobe( source, tag, comm, flag, status);
#ifdef DEBUG
printf("sort : R_MPI_Iprobe\n");
#endif
return ret_tmp;
}
int MPI_Probe(int source,int tag,A_MPI_Comm comm,A_MPI_Status * status);
int (*LOCAL_MPI_Probe)(int,int,R_MPI_Comm,R_MPI_Status *);

__asm__(
".global PMPI_Probe\n"
".weak MPI_Probe\n"
".set MPI_Probe,PMPI_Probe\n"
".extern in_w\n"
".extern A_MPI_Probe\n"
".extern R_MPI_Probe\n"
".type PMPI_Probe,@function\n"
".text\n"
"PMPI_Probe:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Probe\n"
"jmp *A_MPI_Probe@GOTPCREL(%rip)\n"
"inwrap_MPI_Probe:\n"
"jmp *R_MPI_Probe@GOTPCREL(%rip)\n"
".size PMPI_Probe,.-PMPI_Probe\n"

);

int A_MPI_Probe(int source,int tag,A_MPI_Comm comm,A_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : A_MPI_Probe\n");
#endif
in_w=1;

int source_tmp;
source_conv_a2r(&source,&source_tmp);
int tag_tmp;
tag_conv_a2r(&tag,&tag_tmp);
R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
R_MPI_Status  status_ltmp;
R_MPI_Status * status_tmp=&status_ltmp;
int ret_tmp= LOCAL_MPI_Probe( source_tmp, tag_tmp, comm_tmp, status_tmp);
status_prt_conv_r2a(&status,&status_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Probe\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Probe(int source,int tag,R_MPI_Comm comm,R_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : R_MPI_Probe\n");
#endif
int ret_tmp= LOCAL_MPI_Probe( source, tag, comm, status);
#ifdef DEBUG
printf("sort : R_MPI_Probe\n");
#endif
return ret_tmp;
}
int MPI_Cancel(A_MPI_Request * request);
int (*LOCAL_MPI_Cancel)(R_MPI_Request *);

__asm__(
".global PMPI_Cancel\n"
".weak MPI_Cancel\n"
".set MPI_Cancel,PMPI_Cancel\n"
".extern in_w\n"
".extern A_MPI_Cancel\n"
".extern R_MPI_Cancel\n"
".type PMPI_Cancel,@function\n"
".text\n"
"PMPI_Cancel:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Cancel\n"
"jmp *A_MPI_Cancel@GOTPCREL(%rip)\n"
"inwrap_MPI_Cancel:\n"
"jmp *R_MPI_Cancel@GOTPCREL(%rip)\n"
".size PMPI_Cancel,.-PMPI_Cancel\n"

);

int A_MPI_Cancel(A_MPI_Request * request)
{
#ifdef DEBUG
printf("entre : A_MPI_Cancel\n");
#endif
in_w=1;

R_MPI_Request  request_ltmp;
R_MPI_Request * request_tmp=&request_ltmp;
request_ptr_conv_a2r(&request,&request_tmp);
int ret_tmp= LOCAL_MPI_Cancel( request_tmp);
if(ret_tmp == R_MPI_SUCCESS){
request_cancel_r2a(&request,&request_tmp);
}
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Cancel\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Cancel(R_MPI_Request * request)
{
#ifdef DEBUG
printf("entre : R_MPI_Cancel\n");
#endif
int ret_tmp= LOCAL_MPI_Cancel( request);
#ifdef DEBUG
printf("sort : R_MPI_Cancel\n");
#endif
return ret_tmp;
}
int MPI_Test_cancelled(A_MPI_Status * status,int * flag);
int (*LOCAL_MPI_Test_cancelled)(R_MPI_Status *,int *);

__asm__(
".global PMPI_Test_cancelled\n"
".weak MPI_Test_cancelled\n"
".set MPI_Test_cancelled,PMPI_Test_cancelled\n"
".extern in_w\n"
".extern A_MPI_Test_cancelled\n"
".extern R_MPI_Test_cancelled\n"
".type PMPI_Test_cancelled,@function\n"
".text\n"
"PMPI_Test_cancelled:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Test_cancelled\n"
"jmp *A_MPI_Test_cancelled@GOTPCREL(%rip)\n"
"inwrap_MPI_Test_cancelled:\n"
"jmp *R_MPI_Test_cancelled@GOTPCREL(%rip)\n"
".size PMPI_Test_cancelled,.-PMPI_Test_cancelled\n"

);

int A_MPI_Test_cancelled(A_MPI_Status * status,int * flag)
{
#ifdef DEBUG
printf("entre : A_MPI_Test_cancelled\n");
#endif
in_w=1;

R_MPI_Status  status_ltmp;
R_MPI_Status * status_tmp=&status_ltmp;
status_prt_conv_a2r(&status,&status_tmp);

int ret_tmp= LOCAL_MPI_Test_cancelled( status_tmp, flag);

in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Test_cancelled\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Test_cancelled(R_MPI_Status * status,int * flag)
{
#ifdef DEBUG
printf("entre : R_MPI_Test_cancelled\n");
#endif
int ret_tmp= LOCAL_MPI_Test_cancelled( status, flag);
#ifdef DEBUG
printf("sort : R_MPI_Test_cancelled\n");
#endif
return ret_tmp;
}
int MPI_Send_init(void * buf,int count,A_MPI_Datatype datatype,int dest,int tag,A_MPI_Comm comm,A_MPI_Request * request);
int (*LOCAL_MPI_Send_init)(void *,int,R_MPI_Datatype,int,int,R_MPI_Comm,R_MPI_Request *);

__asm__(
".global PMPI_Send_init\n"
".weak MPI_Send_init\n"
".set MPI_Send_init,PMPI_Send_init\n"
".extern in_w\n"
".extern A_MPI_Send_init\n"
".extern R_MPI_Send_init\n"
".type PMPI_Send_init,@function\n"
".text\n"
"PMPI_Send_init:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Send_init\n"
"jmp *A_MPI_Send_init@GOTPCREL(%rip)\n"
"inwrap_MPI_Send_init:\n"
"jmp *R_MPI_Send_init@GOTPCREL(%rip)\n"
".size PMPI_Send_init,.-PMPI_Send_init\n"

);

int A_MPI_Send_init(void * buf,int count,A_MPI_Datatype datatype,int dest,int tag,A_MPI_Comm comm,A_MPI_Request * request)
{
#ifdef DEBUG
printf("entre : A_MPI_Send_init\n");
#endif
in_w=1;

void * buf_tmp;
const_buffer_conv_a2r(&buf,&buf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
int dest_tmp;
dest_conv_a2r(&dest,&dest_tmp);
int tag_tmp;
tag_conv_a2r(&tag,&tag_tmp);
R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
R_MPI_Request  request_ltmp;
R_MPI_Request * request_tmp=&request_ltmp;
int ret_tmp= LOCAL_MPI_Send_init( buf_tmp, count, datatype_tmp, dest_tmp, tag_tmp, comm_tmp, request_tmp);
if(ret_tmp == R_MPI_SUCCESS){
request_pers_ptr_conv_r2a(&request,&request_tmp);
}
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Send_init\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Send_init(void * buf,int count,R_MPI_Datatype datatype,int dest,int tag,R_MPI_Comm comm,R_MPI_Request * request)
{
#ifdef DEBUG
printf("entre : R_MPI_Send_init\n");
#endif
int ret_tmp= LOCAL_MPI_Send_init( buf, count, datatype, dest, tag, comm, request);
#ifdef DEBUG
printf("sort : R_MPI_Send_init\n");
#endif
return ret_tmp;
}
int MPI_Bsend_init(void * buf,int count,A_MPI_Datatype datatype,int dest,int tag,A_MPI_Comm comm,A_MPI_Request * request);
int (*LOCAL_MPI_Bsend_init)(void *,int,R_MPI_Datatype,int,int,R_MPI_Comm,R_MPI_Request *);

__asm__(
".global PMPI_Bsend_init\n"
".weak MPI_Bsend_init\n"
".set MPI_Bsend_init,PMPI_Bsend_init\n"
".extern in_w\n"
".extern A_MPI_Bsend_init\n"
".extern R_MPI_Bsend_init\n"
".type PMPI_Bsend_init,@function\n"
".text\n"
"PMPI_Bsend_init:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Bsend_init\n"
"jmp *A_MPI_Bsend_init@GOTPCREL(%rip)\n"
"inwrap_MPI_Bsend_init:\n"
"jmp *R_MPI_Bsend_init@GOTPCREL(%rip)\n"
".size PMPI_Bsend_init,.-PMPI_Bsend_init\n"

);

int A_MPI_Bsend_init(void * buf,int count,A_MPI_Datatype datatype,int dest,int tag,A_MPI_Comm comm,A_MPI_Request * request)
{
#ifdef DEBUG
printf("entre : A_MPI_Bsend_init\n");
#endif
in_w=1;

void * buf_tmp;
const_buffer_conv_a2r(&buf,&buf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
int dest_tmp;
dest_conv_a2r(&dest,&dest_tmp);
int tag_tmp;
tag_conv_a2r(&tag,&tag_tmp);
R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
R_MPI_Request  request_ltmp;
R_MPI_Request * request_tmp=&request_ltmp;
int ret_tmp= LOCAL_MPI_Bsend_init( buf_tmp, count, datatype_tmp, dest_tmp, tag_tmp, comm_tmp, request_tmp);
if(ret_tmp == R_MPI_SUCCESS){
request_pers_ptr_conv_r2a(&request,&request_tmp);
}
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Bsend_init\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Bsend_init(void * buf,int count,R_MPI_Datatype datatype,int dest,int tag,R_MPI_Comm comm,R_MPI_Request * request)
{
#ifdef DEBUG
printf("entre : R_MPI_Bsend_init\n");
#endif
int ret_tmp= LOCAL_MPI_Bsend_init( buf, count, datatype, dest, tag, comm, request);
#ifdef DEBUG
printf("sort : R_MPI_Bsend_init\n");
#endif
return ret_tmp;
}
int MPI_Ssend_init(void * buf,int count,A_MPI_Datatype datatype,int dest,int tag,A_MPI_Comm comm,A_MPI_Request * request);
int (*LOCAL_MPI_Ssend_init)(void *,int,R_MPI_Datatype,int,int,R_MPI_Comm,R_MPI_Request *);

__asm__(
".global PMPI_Ssend_init\n"
".weak MPI_Ssend_init\n"
".set MPI_Ssend_init,PMPI_Ssend_init\n"
".extern in_w\n"
".extern A_MPI_Ssend_init\n"
".extern R_MPI_Ssend_init\n"
".type PMPI_Ssend_init,@function\n"
".text\n"
"PMPI_Ssend_init:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Ssend_init\n"
"jmp *A_MPI_Ssend_init@GOTPCREL(%rip)\n"
"inwrap_MPI_Ssend_init:\n"
"jmp *R_MPI_Ssend_init@GOTPCREL(%rip)\n"
".size PMPI_Ssend_init,.-PMPI_Ssend_init\n"

);

int A_MPI_Ssend_init(void * buf,int count,A_MPI_Datatype datatype,int dest,int tag,A_MPI_Comm comm,A_MPI_Request * request)
{
#ifdef DEBUG
printf("entre : A_MPI_Ssend_init\n");
#endif
in_w=1;

void * buf_tmp;
const_buffer_conv_a2r(&buf,&buf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
int dest_tmp;
dest_conv_a2r(&dest,&dest_tmp);
int tag_tmp;
tag_conv_a2r(&tag,&tag_tmp);
R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
R_MPI_Request  request_ltmp;
R_MPI_Request * request_tmp=&request_ltmp;
int ret_tmp= LOCAL_MPI_Ssend_init( buf_tmp, count, datatype_tmp, dest_tmp, tag_tmp, comm_tmp, request_tmp);
if(ret_tmp == R_MPI_SUCCESS){
request_pers_ptr_conv_r2a(&request,&request_tmp);
}
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Ssend_init\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Ssend_init(void * buf,int count,R_MPI_Datatype datatype,int dest,int tag,R_MPI_Comm comm,R_MPI_Request * request)
{
#ifdef DEBUG
printf("entre : R_MPI_Ssend_init\n");
#endif
int ret_tmp= LOCAL_MPI_Ssend_init( buf, count, datatype, dest, tag, comm, request);
#ifdef DEBUG
printf("sort : R_MPI_Ssend_init\n");
#endif
return ret_tmp;
}
int MPI_Rsend_init(void * buf,int count,A_MPI_Datatype datatype,int dest,int tag,A_MPI_Comm comm,A_MPI_Request * request);
int (*LOCAL_MPI_Rsend_init)(void *,int,R_MPI_Datatype,int,int,R_MPI_Comm,R_MPI_Request *);

__asm__(
".global PMPI_Rsend_init\n"
".weak MPI_Rsend_init\n"
".set MPI_Rsend_init,PMPI_Rsend_init\n"
".extern in_w\n"
".extern A_MPI_Rsend_init\n"
".extern R_MPI_Rsend_init\n"
".type PMPI_Rsend_init,@function\n"
".text\n"
"PMPI_Rsend_init:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Rsend_init\n"
"jmp *A_MPI_Rsend_init@GOTPCREL(%rip)\n"
"inwrap_MPI_Rsend_init:\n"
"jmp *R_MPI_Rsend_init@GOTPCREL(%rip)\n"
".size PMPI_Rsend_init,.-PMPI_Rsend_init\n"

);

int A_MPI_Rsend_init(void * buf,int count,A_MPI_Datatype datatype,int dest,int tag,A_MPI_Comm comm,A_MPI_Request * request)
{
#ifdef DEBUG
printf("entre : A_MPI_Rsend_init\n");
#endif
in_w=1;

void * buf_tmp;
const_buffer_conv_a2r(&buf,&buf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
int dest_tmp;
dest_conv_a2r(&dest,&dest_tmp);
int tag_tmp;
tag_conv_a2r(&tag,&tag_tmp);
R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
R_MPI_Request  request_ltmp;
R_MPI_Request * request_tmp=&request_ltmp;
int ret_tmp= LOCAL_MPI_Rsend_init( buf_tmp, count, datatype_tmp, dest_tmp, tag_tmp, comm_tmp, request_tmp);
if(ret_tmp == R_MPI_SUCCESS){
request_pers_ptr_conv_r2a(&request,&request_tmp);
}
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Rsend_init\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Rsend_init(void * buf,int count,R_MPI_Datatype datatype,int dest,int tag,R_MPI_Comm comm,R_MPI_Request * request)
{
#ifdef DEBUG
printf("entre : R_MPI_Rsend_init\n");
#endif
int ret_tmp= LOCAL_MPI_Rsend_init( buf, count, datatype, dest, tag, comm, request);
#ifdef DEBUG
printf("sort : R_MPI_Rsend_init\n");
#endif
return ret_tmp;
}
int MPI_Recv_init(void * buf,int count,A_MPI_Datatype datatype,int source,int tag,A_MPI_Comm comm,A_MPI_Request * request);
int (*LOCAL_MPI_Recv_init)(void *,int,R_MPI_Datatype,int,int,R_MPI_Comm,R_MPI_Request *);

__asm__(
".global PMPI_Recv_init\n"
".weak MPI_Recv_init\n"
".set MPI_Recv_init,PMPI_Recv_init\n"
".extern in_w\n"
".extern A_MPI_Recv_init\n"
".extern R_MPI_Recv_init\n"
".type PMPI_Recv_init,@function\n"
".text\n"
"PMPI_Recv_init:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Recv_init\n"
"jmp *A_MPI_Recv_init@GOTPCREL(%rip)\n"
"inwrap_MPI_Recv_init:\n"
"jmp *R_MPI_Recv_init@GOTPCREL(%rip)\n"
".size PMPI_Recv_init,.-PMPI_Recv_init\n"

);

int A_MPI_Recv_init(void * buf,int count,A_MPI_Datatype datatype,int source,int tag,A_MPI_Comm comm,A_MPI_Request * request)
{
#ifdef DEBUG
printf("entre : A_MPI_Recv_init\n");
#endif
in_w=1;

void * buf_tmp;
buffer_conv_a2r(&buf,&buf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
int source_tmp;
source_conv_a2r(&source,&source_tmp);
int tag_tmp;
tag_conv_a2r(&tag,&tag_tmp);
R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
R_MPI_Request  request_ltmp;
R_MPI_Request * request_tmp=&request_ltmp;
int ret_tmp= LOCAL_MPI_Recv_init( buf_tmp, count, datatype_tmp, source_tmp, tag_tmp, comm_tmp, request_tmp);
buffer_conv_r2a(&buf,&buf_tmp);
if(ret_tmp == R_MPI_SUCCESS){
request_pers_ptr_conv_r2a(&request,&request_tmp);
}
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Recv_init\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Recv_init(void * buf,int count,R_MPI_Datatype datatype,int source,int tag,R_MPI_Comm comm,R_MPI_Request * request)
{
#ifdef DEBUG
printf("entre : R_MPI_Recv_init\n");
#endif
int ret_tmp= LOCAL_MPI_Recv_init( buf, count, datatype, source, tag, comm, request);
#ifdef DEBUG
printf("sort : R_MPI_Recv_init\n");
#endif
return ret_tmp;
}
int MPI_Start(A_MPI_Request * request);
int (*LOCAL_MPI_Start)(R_MPI_Request *);

__asm__(
".global PMPI_Start\n"
".weak MPI_Start\n"
".set MPI_Start,PMPI_Start\n"
".extern in_w\n"
".extern A_MPI_Start\n"
".extern R_MPI_Start\n"
".type PMPI_Start,@function\n"
".text\n"
"PMPI_Start:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Start\n"
"jmp *A_MPI_Start@GOTPCREL(%rip)\n"
"inwrap_MPI_Start:\n"
"jmp *R_MPI_Start@GOTPCREL(%rip)\n"
".size PMPI_Start,.-PMPI_Start\n"

);

int A_MPI_Start(A_MPI_Request * request)
{
#ifdef DEBUG
printf("entre : A_MPI_Start\n");
#endif
in_w=1;

R_MPI_Request  request_ltmp;
R_MPI_Request * request_tmp=&request_ltmp;
request_pers_ptr_conv_a2r(&request,&request_tmp);
int ret_tmp= LOCAL_MPI_Start( request_tmp);
request_pers_ptr_conv_r2a(&request,&request_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Start\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Start(R_MPI_Request * request)
{
#ifdef DEBUG
printf("entre : R_MPI_Start\n");
#endif
int ret_tmp= LOCAL_MPI_Start( request);
#ifdef DEBUG
printf("sort : R_MPI_Start\n");
#endif
return ret_tmp;
}
int MPI_Sendrecv(void * sendbuf,int sendcount,A_MPI_Datatype sendtype,int dest,int sendtag,void * recvbuf,int recvcount,A_MPI_Datatype recvtype,int source,int recvtag,A_MPI_Comm comm,A_MPI_Status * status);
int (*LOCAL_MPI_Sendrecv)(void *,int,R_MPI_Datatype,int,int,void *,int,R_MPI_Datatype,int,int,R_MPI_Comm,R_MPI_Status *);

__asm__(
".global PMPI_Sendrecv\n"
".weak MPI_Sendrecv\n"
".set MPI_Sendrecv,PMPI_Sendrecv\n"
".extern in_w\n"
".extern A_MPI_Sendrecv\n"
".extern R_MPI_Sendrecv\n"
".type PMPI_Sendrecv,@function\n"
".text\n"
"PMPI_Sendrecv:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Sendrecv\n"
"jmp *A_MPI_Sendrecv@GOTPCREL(%rip)\n"
"inwrap_MPI_Sendrecv:\n"
"jmp *R_MPI_Sendrecv@GOTPCREL(%rip)\n"
".size PMPI_Sendrecv,.-PMPI_Sendrecv\n"

);

int A_MPI_Sendrecv(void * sendbuf,int sendcount,A_MPI_Datatype sendtype,int dest,int sendtag,void * recvbuf,int recvcount,A_MPI_Datatype recvtype,int source,int recvtag,A_MPI_Comm comm,A_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : A_MPI_Sendrecv\n");
#endif
in_w=1;

void * sendbuf_tmp;
const_buffer_conv_a2r(&sendbuf,&sendbuf_tmp);


R_MPI_Datatype sendtype_tmp;
datatype_conv_a2r(&sendtype,&sendtype_tmp);
int dest_tmp;
dest_conv_a2r(&dest,&dest_tmp);
int sendtag_tmp;
tag_conv_a2r(&sendtag,&sendtag_tmp);
void * recvbuf_tmp;
buffer_conv_a2r(&recvbuf,&recvbuf_tmp);


R_MPI_Datatype recvtype_tmp;
datatype_conv_a2r(&recvtype,&recvtype_tmp);
int source_tmp;
source_conv_a2r(&source,&source_tmp);
int recvtag_tmp;
tag_conv_a2r(&recvtag,&recvtag_tmp);
R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
R_MPI_Status  status_ltmp;
R_MPI_Status * status_tmp=&status_ltmp;
int ret_tmp= LOCAL_MPI_Sendrecv( sendbuf_tmp, sendcount, sendtype_tmp, dest_tmp, sendtag_tmp, recvbuf_tmp, recvcount, recvtype_tmp, source_tmp, recvtag_tmp, comm_tmp, status_tmp);
buffer_conv_r2a(&recvbuf,&recvbuf_tmp);
status_prt_conv_r2a(&status,&status_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Sendrecv\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Sendrecv(void * sendbuf,int sendcount,R_MPI_Datatype sendtype,int dest,int sendtag,void * recvbuf,int recvcount,R_MPI_Datatype recvtype,int source,int recvtag,R_MPI_Comm comm,R_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : R_MPI_Sendrecv\n");
#endif
int ret_tmp= LOCAL_MPI_Sendrecv( sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, recvtype, source, recvtag, comm, status);
#ifdef DEBUG
printf("sort : R_MPI_Sendrecv\n");
#endif
return ret_tmp;
}
int MPI_Sendrecv_replace(void * buf,int count,A_MPI_Datatype datatype,int dest,int sendtag,int source,int recvtag,A_MPI_Comm comm,A_MPI_Status * status);
int (*LOCAL_MPI_Sendrecv_replace)(void *,int,R_MPI_Datatype,int,int,int,int,R_MPI_Comm,R_MPI_Status *);

__asm__(
".global PMPI_Sendrecv_replace\n"
".weak MPI_Sendrecv_replace\n"
".set MPI_Sendrecv_replace,PMPI_Sendrecv_replace\n"
".extern in_w\n"
".extern A_MPI_Sendrecv_replace\n"
".extern R_MPI_Sendrecv_replace\n"
".type PMPI_Sendrecv_replace,@function\n"
".text\n"
"PMPI_Sendrecv_replace:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Sendrecv_replace\n"
"jmp *A_MPI_Sendrecv_replace@GOTPCREL(%rip)\n"
"inwrap_MPI_Sendrecv_replace:\n"
"jmp *R_MPI_Sendrecv_replace@GOTPCREL(%rip)\n"
".size PMPI_Sendrecv_replace,.-PMPI_Sendrecv_replace\n"

);

int A_MPI_Sendrecv_replace(void * buf,int count,A_MPI_Datatype datatype,int dest,int sendtag,int source,int recvtag,A_MPI_Comm comm,A_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : A_MPI_Sendrecv_replace\n");
#endif
in_w=1;

void * buf_tmp;
buffer_conv_a2r(&buf,&buf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
int dest_tmp;
dest_conv_a2r(&dest,&dest_tmp);
int sendtag_tmp;
tag_conv_a2r(&sendtag,&sendtag_tmp);
int source_tmp;
source_conv_a2r(&source,&source_tmp);
int recvtag_tmp;
tag_conv_a2r(&recvtag,&recvtag_tmp);
R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
R_MPI_Status  status_ltmp;
R_MPI_Status * status_tmp=&status_ltmp;
int ret_tmp= LOCAL_MPI_Sendrecv_replace( buf_tmp, count, datatype_tmp, dest_tmp, sendtag_tmp, source_tmp, recvtag_tmp, comm_tmp, status_tmp);
buffer_conv_r2a(&buf,&buf_tmp);
status_prt_conv_r2a(&status,&status_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Sendrecv_replace\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Sendrecv_replace(void * buf,int count,R_MPI_Datatype datatype,int dest,int sendtag,int source,int recvtag,R_MPI_Comm comm,R_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : R_MPI_Sendrecv_replace\n");
#endif
int ret_tmp= LOCAL_MPI_Sendrecv_replace( buf, count, datatype, dest, sendtag, source, recvtag, comm, status);
#ifdef DEBUG
printf("sort : R_MPI_Sendrecv_replace\n");
#endif
return ret_tmp;
}
int MPI_Type_contiguous(int count,A_MPI_Datatype oldtype,A_MPI_Datatype * newtype);
int (*LOCAL_MPI_Type_contiguous)(int,R_MPI_Datatype,R_MPI_Datatype *);

__asm__(
".global PMPI_Type_contiguous\n"
".weak MPI_Type_contiguous\n"
".set MPI_Type_contiguous,PMPI_Type_contiguous\n"
".extern in_w\n"
".extern A_MPI_Type_contiguous\n"
".extern R_MPI_Type_contiguous\n"
".type PMPI_Type_contiguous,@function\n"
".text\n"
"PMPI_Type_contiguous:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Type_contiguous\n"
"jmp *A_MPI_Type_contiguous@GOTPCREL(%rip)\n"
"inwrap_MPI_Type_contiguous:\n"
"jmp *R_MPI_Type_contiguous@GOTPCREL(%rip)\n"
".size PMPI_Type_contiguous,.-PMPI_Type_contiguous\n"

);

int A_MPI_Type_contiguous(int count,A_MPI_Datatype oldtype,A_MPI_Datatype * newtype)
{
#ifdef DEBUG
printf("entre : A_MPI_Type_contiguous\n");
#endif
in_w=1;



R_MPI_Datatype oldtype_tmp;
datatype_conv_a2r(&oldtype,&oldtype_tmp);
R_MPI_Datatype  newtype_ltmp;
R_MPI_Datatype * newtype_tmp=&newtype_ltmp;
int ret_tmp= LOCAL_MPI_Type_contiguous( count, oldtype_tmp, newtype_tmp);
datatype_conv_r2a(newtype,newtype_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Type_contiguous\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Type_contiguous(int count,R_MPI_Datatype oldtype,R_MPI_Datatype * newtype)
{
#ifdef DEBUG
printf("entre : R_MPI_Type_contiguous\n");
#endif
int ret_tmp= LOCAL_MPI_Type_contiguous( count, oldtype, newtype);
#ifdef DEBUG
printf("sort : R_MPI_Type_contiguous\n");
#endif
return ret_tmp;
}
int MPI_Type_vector(int count,int blocklength,int stride,A_MPI_Datatype oldtype,A_MPI_Datatype * newtype);
int (*LOCAL_MPI_Type_vector)(int,int,int,R_MPI_Datatype,R_MPI_Datatype *);

__asm__(
".global PMPI_Type_vector\n"
".weak MPI_Type_vector\n"
".set MPI_Type_vector,PMPI_Type_vector\n"
".extern in_w\n"
".extern A_MPI_Type_vector\n"
".extern R_MPI_Type_vector\n"
".type PMPI_Type_vector,@function\n"
".text\n"
"PMPI_Type_vector:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Type_vector\n"
"jmp *A_MPI_Type_vector@GOTPCREL(%rip)\n"
"inwrap_MPI_Type_vector:\n"
"jmp *R_MPI_Type_vector@GOTPCREL(%rip)\n"
".size PMPI_Type_vector,.-PMPI_Type_vector\n"

);

int A_MPI_Type_vector(int count,int blocklength,int stride,A_MPI_Datatype oldtype,A_MPI_Datatype * newtype)
{
#ifdef DEBUG
printf("entre : A_MPI_Type_vector\n");
#endif
in_w=1;







R_MPI_Datatype oldtype_tmp;
datatype_conv_a2r(&oldtype,&oldtype_tmp);
R_MPI_Datatype  newtype_ltmp;
R_MPI_Datatype * newtype_tmp=&newtype_ltmp;
int ret_tmp= LOCAL_MPI_Type_vector( count, blocklength, stride, oldtype_tmp, newtype_tmp);
datatype_conv_r2a(newtype,newtype_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Type_vector\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Type_vector(int count,int blocklength,int stride,R_MPI_Datatype oldtype,R_MPI_Datatype * newtype)
{
#ifdef DEBUG
printf("entre : R_MPI_Type_vector\n");
#endif
int ret_tmp= LOCAL_MPI_Type_vector( count, blocklength, stride, oldtype, newtype);
#ifdef DEBUG
printf("sort : R_MPI_Type_vector\n");
#endif
return ret_tmp;
}
int MPI_Type_hvector(int count,int blocklength,A_MPI_Aint stride,A_MPI_Datatype oldtype,A_MPI_Datatype * newtype);
int (*LOCAL_MPI_Type_hvector)(int,int,R_MPI_Aint,R_MPI_Datatype,R_MPI_Datatype *);

__asm__(
".global PMPI_Type_hvector\n"
".weak MPI_Type_hvector\n"
".set MPI_Type_hvector,PMPI_Type_hvector\n"
".extern in_w\n"
".extern A_MPI_Type_hvector\n"
".extern R_MPI_Type_hvector\n"
".type PMPI_Type_hvector,@function\n"
".text\n"
"PMPI_Type_hvector:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Type_hvector\n"
"jmp *A_MPI_Type_hvector@GOTPCREL(%rip)\n"
"inwrap_MPI_Type_hvector:\n"
"jmp *R_MPI_Type_hvector@GOTPCREL(%rip)\n"
".size PMPI_Type_hvector,.-PMPI_Type_hvector\n"

);

int A_MPI_Type_hvector(int count,int blocklength,A_MPI_Aint stride,A_MPI_Datatype oldtype,A_MPI_Datatype * newtype)
{
#ifdef DEBUG
printf("entre : A_MPI_Type_hvector\n");
#endif
in_w=1;





R_MPI_Aint stride_tmp;
stride_tmp = (R_MPI_Aint)stride;
R_MPI_Datatype oldtype_tmp;
datatype_conv_a2r(&oldtype,&oldtype_tmp);
R_MPI_Datatype  newtype_ltmp;
R_MPI_Datatype * newtype_tmp=&newtype_ltmp;
int ret_tmp= LOCAL_MPI_Type_hvector( count, blocklength, stride_tmp, oldtype_tmp, newtype_tmp);
datatype_conv_r2a(newtype,newtype_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Type_hvector\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Type_hvector(int count,int blocklength,R_MPI_Aint stride,R_MPI_Datatype oldtype,R_MPI_Datatype * newtype)
{
#ifdef DEBUG
printf("entre : R_MPI_Type_hvector\n");
#endif
int ret_tmp= LOCAL_MPI_Type_hvector( count, blocklength, stride, oldtype, newtype);
#ifdef DEBUG
printf("sort : R_MPI_Type_hvector\n");
#endif
return ret_tmp;
}
int MPI_Type_indexed(int count,int * array_of_blocklengths,int * array_of_displacements,A_MPI_Datatype oldtype,A_MPI_Datatype * newtype);
int (*LOCAL_MPI_Type_indexed)(int,int *,int *,R_MPI_Datatype,R_MPI_Datatype *);

__asm__(
".global PMPI_Type_indexed\n"
".weak MPI_Type_indexed\n"
".set MPI_Type_indexed,PMPI_Type_indexed\n"
".extern in_w\n"
".extern A_MPI_Type_indexed\n"
".extern R_MPI_Type_indexed\n"
".type PMPI_Type_indexed,@function\n"
".text\n"
"PMPI_Type_indexed:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Type_indexed\n"
"jmp *A_MPI_Type_indexed@GOTPCREL(%rip)\n"
"inwrap_MPI_Type_indexed:\n"
"jmp *R_MPI_Type_indexed@GOTPCREL(%rip)\n"
".size PMPI_Type_indexed,.-PMPI_Type_indexed\n"

);

int A_MPI_Type_indexed(int count,int * array_of_blocklengths,int * array_of_displacements,A_MPI_Datatype oldtype,A_MPI_Datatype * newtype)
{
#ifdef DEBUG
printf("entre : A_MPI_Type_indexed\n");
#endif
in_w=1;







R_MPI_Datatype oldtype_tmp;
datatype_conv_a2r(&oldtype,&oldtype_tmp);
R_MPI_Datatype  newtype_ltmp;
R_MPI_Datatype * newtype_tmp=&newtype_ltmp;
int ret_tmp= LOCAL_MPI_Type_indexed( count, array_of_blocklengths, array_of_displacements, oldtype_tmp, newtype_tmp);
datatype_conv_r2a(newtype,newtype_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Type_indexed\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Type_indexed(int count,int * array_of_blocklengths,int * array_of_displacements,R_MPI_Datatype oldtype,R_MPI_Datatype * newtype)
{
#ifdef DEBUG
printf("entre : R_MPI_Type_indexed\n");
#endif
int ret_tmp= LOCAL_MPI_Type_indexed( count, array_of_blocklengths, array_of_displacements, oldtype, newtype);
#ifdef DEBUG
printf("sort : R_MPI_Type_indexed\n");
#endif
return ret_tmp;
}
int MPI_Type_hindexed(int count,int * array_of_blocklengths,A_MPI_Aint * array_of_displacements,A_MPI_Datatype oldtype,A_MPI_Datatype * newtype);
int (*LOCAL_MPI_Type_hindexed)(int,int *,R_MPI_Aint *,R_MPI_Datatype,R_MPI_Datatype *);

__asm__(
".global PMPI_Type_hindexed\n"
".weak MPI_Type_hindexed\n"
".set MPI_Type_hindexed,PMPI_Type_hindexed\n"
".extern in_w\n"
".extern A_MPI_Type_hindexed\n"
".extern R_MPI_Type_hindexed\n"
".type PMPI_Type_hindexed,@function\n"
".text\n"
"PMPI_Type_hindexed:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Type_hindexed\n"
"jmp *A_MPI_Type_hindexed@GOTPCREL(%rip)\n"
"inwrap_MPI_Type_hindexed:\n"
"jmp *R_MPI_Type_hindexed@GOTPCREL(%rip)\n"
".size PMPI_Type_hindexed,.-PMPI_Type_hindexed\n"

);

int A_MPI_Type_hindexed(int count,int * array_of_blocklengths,A_MPI_Aint * array_of_displacements,A_MPI_Datatype oldtype,A_MPI_Datatype * newtype)
{
#ifdef DEBUG
printf("entre : A_MPI_Type_hindexed\n");
#endif
in_w=1;





R_MPI_Aint  *array_of_displacements_tmp = malloc(sizeof(R_MPI_Aint )*count);
int i1;
for(i1=0; i1 < count;i1++){
array_of_displacements_tmp[i1]= (R_MPI_Aint )array_of_displacements[i1];
}
R_MPI_Datatype oldtype_tmp;
datatype_conv_a2r(&oldtype,&oldtype_tmp);
R_MPI_Datatype  newtype_ltmp;
R_MPI_Datatype * newtype_tmp=&newtype_ltmp;
int ret_tmp= LOCAL_MPI_Type_hindexed( count, array_of_blocklengths, array_of_displacements_tmp, oldtype_tmp, newtype_tmp);
datatype_conv_r2a(newtype,newtype_tmp);
free(array_of_displacements_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Type_hindexed\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Type_hindexed(int count,int * array_of_blocklengths,R_MPI_Aint * array_of_displacements,R_MPI_Datatype oldtype,R_MPI_Datatype * newtype)
{
#ifdef DEBUG
printf("entre : R_MPI_Type_hindexed\n");
#endif
int ret_tmp= LOCAL_MPI_Type_hindexed( count, array_of_blocklengths, array_of_displacements, oldtype, newtype);
#ifdef DEBUG
printf("sort : R_MPI_Type_hindexed\n");
#endif
return ret_tmp;
}
int MPI_Type_struct(int count,int * array_of_blocklengths,A_MPI_Aint * array_of_displacements,R_MPI_Datatype * array_of_types[],A_MPI_Datatype * newtype);
int (*LOCAL_MPI_Type_struct)(int,int *,R_MPI_Aint *,R_MPI_Datatype *,R_MPI_Datatype *);

__asm__(
".global PMPI_Type_struct\n"
".weak MPI_Type_struct\n"
".set MPI_Type_struct,PMPI_Type_struct\n"
".extern in_w\n"
".extern A_MPI_Type_struct\n"
".extern R_MPI_Type_struct\n"
".type PMPI_Type_struct,@function\n"
".text\n"
"PMPI_Type_struct:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Type_struct\n"
"jmp *A_MPI_Type_struct@GOTPCREL(%rip)\n"
"inwrap_MPI_Type_struct:\n"
"jmp *R_MPI_Type_struct@GOTPCREL(%rip)\n"
".size PMPI_Type_struct,.-PMPI_Type_struct\n"

);

int A_MPI_Type_struct(int count,int * array_of_blocklengths,A_MPI_Aint * array_of_displacements,A_MPI_Datatype array_of_types[],A_MPI_Datatype * newtype)
{
#ifdef DEBUG
printf("entre : A_MPI_Type_struct\n");
#endif
in_w=1;





R_MPI_Aint  *array_of_displacements_tmp = malloc(sizeof(R_MPI_Aint )*count);
int i1;
for(i1=0; i1 < count;i1++){
array_of_displacements_tmp[i1]= (R_MPI_Aint )array_of_displacements[i1];
}
R_MPI_Datatype *array_of_types_tmp = malloc(sizeof(R_MPI_Datatype)*count);
int i2;
for(i2=0; i2 < count;i2++){
datatype_conv_a2r(&array_of_types[i2],&array_of_types_tmp[i2]);
}
R_MPI_Datatype  newtype_ltmp;
R_MPI_Datatype * newtype_tmp=&newtype_ltmp;
int ret_tmp= LOCAL_MPI_Type_struct( count, array_of_blocklengths, array_of_displacements_tmp, array_of_types_tmp, newtype_tmp);
datatype_conv_r2a(newtype,newtype_tmp);
free(array_of_displacements_tmp);
free(array_of_types_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Type_struct\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Type_struct(int count,int * array_of_blocklengths,R_MPI_Aint * array_of_displacements,R_MPI_Datatype array_of_types[],R_MPI_Datatype * newtype)
{
#ifdef DEBUG
printf("entre : R_MPI_Type_struct\n");
#endif
int ret_tmp= LOCAL_MPI_Type_struct( count, array_of_blocklengths, array_of_displacements, array_of_types, newtype);
#ifdef DEBUG
printf("sort : R_MPI_Type_struct\n");
#endif
return ret_tmp;
}
int MPI_Address(void * location,A_MPI_Aint * address);
int (*LOCAL_MPI_Address)(void *,R_MPI_Aint *);

__asm__(
".global PMPI_Address\n"
".weak MPI_Address\n"
".set MPI_Address,PMPI_Address\n"
".extern in_w\n"
".extern A_MPI_Address\n"
".extern R_MPI_Address\n"
".type PMPI_Address,@function\n"
".text\n"
"PMPI_Address:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Address\n"
"jmp *A_MPI_Address@GOTPCREL(%rip)\n"
"inwrap_MPI_Address:\n"
"jmp *R_MPI_Address@GOTPCREL(%rip)\n"
".size PMPI_Address,.-PMPI_Address\n"

);

int A_MPI_Address(void * location,A_MPI_Aint * address)
{
#ifdef DEBUG
printf("entre : A_MPI_Address\n");
#endif
in_w=1;

void * location_tmp;
const_buffer_conv_a2r(&location,&location_tmp);
R_MPI_Aint  address_ltmp;
R_MPI_Aint * address_tmp=&address_ltmp;
int ret_tmp= LOCAL_MPI_Address( location_tmp, address_tmp);
*address= (A_MPI_Aint ) *address_tmp;
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Address\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Address(void * location,R_MPI_Aint * address)
{
#ifdef DEBUG
printf("entre : R_MPI_Address\n");
#endif
int ret_tmp= LOCAL_MPI_Address( location, address);
#ifdef DEBUG
printf("sort : R_MPI_Address\n");
#endif
return ret_tmp;
}
int MPI_Type_extent(A_MPI_Datatype datatype,A_MPI_Aint * extent);
int (*LOCAL_MPI_Type_extent)(R_MPI_Datatype,R_MPI_Aint *);

__asm__(
".global PMPI_Type_extent\n"
".weak MPI_Type_extent\n"
".set MPI_Type_extent,PMPI_Type_extent\n"
".extern in_w\n"
".extern A_MPI_Type_extent\n"
".extern R_MPI_Type_extent\n"
".type PMPI_Type_extent,@function\n"
".text\n"
"PMPI_Type_extent:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Type_extent\n"
"jmp *A_MPI_Type_extent@GOTPCREL(%rip)\n"
"inwrap_MPI_Type_extent:\n"
"jmp *R_MPI_Type_extent@GOTPCREL(%rip)\n"
".size PMPI_Type_extent,.-PMPI_Type_extent\n"

);

int A_MPI_Type_extent(A_MPI_Datatype datatype,A_MPI_Aint * extent)
{
#ifdef DEBUG
printf("entre : A_MPI_Type_extent\n");
#endif
in_w=1;

R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
R_MPI_Aint  extent_ltmp;
R_MPI_Aint * extent_tmp=&extent_ltmp;
int ret_tmp= LOCAL_MPI_Type_extent( datatype_tmp, extent_tmp);
*extent= (A_MPI_Aint ) *extent_tmp;
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Type_extent\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Type_extent(R_MPI_Datatype datatype,R_MPI_Aint * extent)
{
#ifdef DEBUG
printf("entre : R_MPI_Type_extent\n");
#endif
int ret_tmp= LOCAL_MPI_Type_extent( datatype, extent);
#ifdef DEBUG
printf("sort : R_MPI_Type_extent\n");
#endif
return ret_tmp;
}
int MPI_Type_size(A_MPI_Datatype datatype,int * size);
int (*LOCAL_MPI_Type_size)(R_MPI_Datatype,int *);

__asm__(
".global PMPI_Type_size\n"
".weak MPI_Type_size\n"
".set MPI_Type_size,PMPI_Type_size\n"
".extern in_w\n"
".extern A_MPI_Type_size\n"
".extern R_MPI_Type_size\n"
".type PMPI_Type_size,@function\n"
".text\n"
"PMPI_Type_size:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Type_size\n"
"jmp *A_MPI_Type_size@GOTPCREL(%rip)\n"
"inwrap_MPI_Type_size:\n"
"jmp *R_MPI_Type_size@GOTPCREL(%rip)\n"
".size PMPI_Type_size,.-PMPI_Type_size\n"

);

int A_MPI_Type_size(A_MPI_Datatype datatype,int * size)
{
#ifdef DEBUG
printf("entre : A_MPI_Type_size\n");
#endif
in_w=1;

R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);

int ret_tmp= LOCAL_MPI_Type_size( datatype_tmp, size);

in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Type_size\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Type_size(R_MPI_Datatype datatype,int * size)
{
#ifdef DEBUG
printf("entre : R_MPI_Type_size\n");
#endif
int ret_tmp= LOCAL_MPI_Type_size( datatype, size);
#ifdef DEBUG
printf("sort : R_MPI_Type_size\n");
#endif
return ret_tmp;
}
int MPI_Type_lb(A_MPI_Datatype datatype,A_MPI_Aint * displacement);
int (*LOCAL_MPI_Type_lb)(R_MPI_Datatype,R_MPI_Aint *);

__asm__(
".global PMPI_Type_lb\n"
".weak MPI_Type_lb\n"
".set MPI_Type_lb,PMPI_Type_lb\n"
".extern in_w\n"
".extern A_MPI_Type_lb\n"
".extern R_MPI_Type_lb\n"
".type PMPI_Type_lb,@function\n"
".text\n"
"PMPI_Type_lb:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Type_lb\n"
"jmp *A_MPI_Type_lb@GOTPCREL(%rip)\n"
"inwrap_MPI_Type_lb:\n"
"jmp *R_MPI_Type_lb@GOTPCREL(%rip)\n"
".size PMPI_Type_lb,.-PMPI_Type_lb\n"

);

int A_MPI_Type_lb(A_MPI_Datatype datatype,A_MPI_Aint * displacement)
{
#ifdef DEBUG
printf("entre : A_MPI_Type_lb\n");
#endif
in_w=1;

R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
R_MPI_Aint  displacement_ltmp;
R_MPI_Aint * displacement_tmp=&displacement_ltmp;
int ret_tmp= LOCAL_MPI_Type_lb( datatype_tmp, displacement_tmp);
*displacement= (A_MPI_Aint ) *displacement_tmp;
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Type_lb\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Type_lb(R_MPI_Datatype datatype,R_MPI_Aint * displacement)
{
#ifdef DEBUG
printf("entre : R_MPI_Type_lb\n");
#endif
int ret_tmp= LOCAL_MPI_Type_lb( datatype, displacement);
#ifdef DEBUG
printf("sort : R_MPI_Type_lb\n");
#endif
return ret_tmp;
}
int MPI_Type_ub(A_MPI_Datatype datatype,A_MPI_Aint * displacement);
int (*LOCAL_MPI_Type_ub)(R_MPI_Datatype,R_MPI_Aint *);

__asm__(
".global PMPI_Type_ub\n"
".weak MPI_Type_ub\n"
".set MPI_Type_ub,PMPI_Type_ub\n"
".extern in_w\n"
".extern A_MPI_Type_ub\n"
".extern R_MPI_Type_ub\n"
".type PMPI_Type_ub,@function\n"
".text\n"
"PMPI_Type_ub:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Type_ub\n"
"jmp *A_MPI_Type_ub@GOTPCREL(%rip)\n"
"inwrap_MPI_Type_ub:\n"
"jmp *R_MPI_Type_ub@GOTPCREL(%rip)\n"
".size PMPI_Type_ub,.-PMPI_Type_ub\n"

);

int A_MPI_Type_ub(A_MPI_Datatype datatype,A_MPI_Aint * displacement)
{
#ifdef DEBUG
printf("entre : A_MPI_Type_ub\n");
#endif
in_w=1;

R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
R_MPI_Aint  displacement_ltmp;
R_MPI_Aint * displacement_tmp=&displacement_ltmp;
int ret_tmp= LOCAL_MPI_Type_ub( datatype_tmp, displacement_tmp);
*displacement= (A_MPI_Aint ) *displacement_tmp;
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Type_ub\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Type_ub(R_MPI_Datatype datatype,R_MPI_Aint * displacement)
{
#ifdef DEBUG
printf("entre : R_MPI_Type_ub\n");
#endif
int ret_tmp= LOCAL_MPI_Type_ub( datatype, displacement);
#ifdef DEBUG
printf("sort : R_MPI_Type_ub\n");
#endif
return ret_tmp;
}
int MPI_Type_commit(A_MPI_Datatype * datatype);
int (*LOCAL_MPI_Type_commit)(R_MPI_Datatype *);

__asm__(
".global PMPI_Type_commit\n"
".weak MPI_Type_commit\n"
".set MPI_Type_commit,PMPI_Type_commit\n"
".extern in_w\n"
".extern A_MPI_Type_commit\n"
".extern R_MPI_Type_commit\n"
".type PMPI_Type_commit,@function\n"
".text\n"
"PMPI_Type_commit:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Type_commit\n"
"jmp *A_MPI_Type_commit@GOTPCREL(%rip)\n"
"inwrap_MPI_Type_commit:\n"
"jmp *R_MPI_Type_commit@GOTPCREL(%rip)\n"
".size PMPI_Type_commit,.-PMPI_Type_commit\n"

);

int A_MPI_Type_commit(A_MPI_Datatype * datatype)
{
#ifdef DEBUG
printf("entre : A_MPI_Type_commit\n");
#endif
in_w=1;

R_MPI_Datatype  datatype_ltmp;
R_MPI_Datatype * datatype_tmp=&datatype_ltmp;
datatype_conv_a2r(datatype,datatype_tmp);
int ret_tmp= LOCAL_MPI_Type_commit( datatype_tmp);
datatype_conv_r2a(datatype,datatype_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Type_commit\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Type_commit(R_MPI_Datatype * datatype)
{
#ifdef DEBUG
printf("entre : R_MPI_Type_commit\n");
#endif
int ret_tmp= LOCAL_MPI_Type_commit( datatype);
#ifdef DEBUG
printf("sort : R_MPI_Type_commit\n");
#endif
return ret_tmp;
}
int MPI_Type_free(A_MPI_Datatype * datatype);
int (*LOCAL_MPI_Type_free)(R_MPI_Datatype *);

__asm__(
".global PMPI_Type_free\n"
".weak MPI_Type_free\n"
".set MPI_Type_free,PMPI_Type_free\n"
".extern in_w\n"
".extern A_MPI_Type_free\n"
".extern R_MPI_Type_free\n"
".type PMPI_Type_free,@function\n"
".text\n"
"PMPI_Type_free:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Type_free\n"
"jmp *A_MPI_Type_free@GOTPCREL(%rip)\n"
"inwrap_MPI_Type_free:\n"
"jmp *R_MPI_Type_free@GOTPCREL(%rip)\n"
".size PMPI_Type_free,.-PMPI_Type_free\n"

);

int A_MPI_Type_free(A_MPI_Datatype * datatype)
{
#ifdef DEBUG
printf("entre : A_MPI_Type_free\n");
#endif
in_w=1;

R_MPI_Datatype  datatype_ltmp;
R_MPI_Datatype * datatype_tmp=&datatype_ltmp;
datatype_conv_a2r(datatype,datatype_tmp);
int ret_tmp= LOCAL_MPI_Type_free( datatype_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Type_free\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Type_free(R_MPI_Datatype * datatype)
{
#ifdef DEBUG
printf("entre : R_MPI_Type_free\n");
#endif
int ret_tmp= LOCAL_MPI_Type_free( datatype);
#ifdef DEBUG
printf("sort : R_MPI_Type_free\n");
#endif
return ret_tmp;
}
int MPI_Get_elements(A_MPI_Status * status,A_MPI_Datatype datatype,int * count);
int (*LOCAL_MPI_Get_elements)(R_MPI_Status *,R_MPI_Datatype,int *);

__asm__(
".global PMPI_Get_elements\n"
".weak MPI_Get_elements\n"
".set MPI_Get_elements,PMPI_Get_elements\n"
".extern in_w\n"
".extern A_MPI_Get_elements\n"
".extern R_MPI_Get_elements\n"
".type PMPI_Get_elements,@function\n"
".text\n"
"PMPI_Get_elements:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Get_elements\n"
"jmp *A_MPI_Get_elements@GOTPCREL(%rip)\n"
"inwrap_MPI_Get_elements:\n"
"jmp *R_MPI_Get_elements@GOTPCREL(%rip)\n"
".size PMPI_Get_elements,.-PMPI_Get_elements\n"

);

int A_MPI_Get_elements(A_MPI_Status * status,A_MPI_Datatype datatype,int * count)
{
#ifdef DEBUG
printf("entre : A_MPI_Get_elements\n");
#endif
in_w=1;

R_MPI_Status  status_ltmp;
R_MPI_Status * status_tmp=&status_ltmp;
status_prt_conv_a2r(&status,&status_tmp);
R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);

int ret_tmp= LOCAL_MPI_Get_elements( status_tmp, datatype_tmp, count);

in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Get_elements\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Get_elements(R_MPI_Status * status,R_MPI_Datatype datatype,int * count)
{
#ifdef DEBUG
printf("entre : R_MPI_Get_elements\n");
#endif
int ret_tmp= LOCAL_MPI_Get_elements( status, datatype, count);
#ifdef DEBUG
printf("sort : R_MPI_Get_elements\n");
#endif
return ret_tmp;
}
int MPI_Pack(void * inbuf,int incount,A_MPI_Datatype datatype,void * outbuf,int outsize,int * position,A_MPI_Comm comm);
int (*LOCAL_MPI_Pack)(void *,int,R_MPI_Datatype,void *,int,int *,R_MPI_Comm);

__asm__(
".global PMPI_Pack\n"
".weak MPI_Pack\n"
".set MPI_Pack,PMPI_Pack\n"
".extern in_w\n"
".extern A_MPI_Pack\n"
".extern R_MPI_Pack\n"
".type PMPI_Pack,@function\n"
".text\n"
"PMPI_Pack:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Pack\n"
"jmp *A_MPI_Pack@GOTPCREL(%rip)\n"
"inwrap_MPI_Pack:\n"
"jmp *R_MPI_Pack@GOTPCREL(%rip)\n"
".size PMPI_Pack,.-PMPI_Pack\n"

);

int A_MPI_Pack(void * inbuf,int incount,A_MPI_Datatype datatype,void * outbuf,int outsize,int * position,A_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : A_MPI_Pack\n");
#endif
in_w=1;

void * inbuf_tmp;
const_buffer_conv_a2r(&inbuf,&inbuf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
void * outbuf_tmp;
buffer_conv_a2r(&outbuf,&outbuf_tmp);




R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
int ret_tmp= LOCAL_MPI_Pack( inbuf_tmp, incount, datatype_tmp, outbuf_tmp, outsize, position, comm_tmp);
buffer_conv_r2a(&outbuf,&outbuf_tmp);

in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Pack\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Pack(void * inbuf,int incount,R_MPI_Datatype datatype,void * outbuf,int outsize,int * position,R_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : R_MPI_Pack\n");
#endif
int ret_tmp= LOCAL_MPI_Pack( inbuf, incount, datatype, outbuf, outsize, position, comm);
#ifdef DEBUG
printf("sort : R_MPI_Pack\n");
#endif
return ret_tmp;
}
int MPI_Unpack(void * inbuf,int insize,int * position,void * outbuf,int outcount,A_MPI_Datatype datatype,A_MPI_Comm comm);
int (*LOCAL_MPI_Unpack)(void *,int,int *,void *,int,R_MPI_Datatype,R_MPI_Comm);

__asm__(
".global PMPI_Unpack\n"
".weak MPI_Unpack\n"
".set MPI_Unpack,PMPI_Unpack\n"
".extern in_w\n"
".extern A_MPI_Unpack\n"
".extern R_MPI_Unpack\n"
".type PMPI_Unpack,@function\n"
".text\n"
"PMPI_Unpack:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Unpack\n"
"jmp *A_MPI_Unpack@GOTPCREL(%rip)\n"
"inwrap_MPI_Unpack:\n"
"jmp *R_MPI_Unpack@GOTPCREL(%rip)\n"
".size PMPI_Unpack,.-PMPI_Unpack\n"

);

int A_MPI_Unpack(void * inbuf,int insize,int * position,void * outbuf,int outcount,A_MPI_Datatype datatype,A_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : A_MPI_Unpack\n");
#endif
in_w=1;

void * inbuf_tmp;
const_buffer_conv_a2r(&inbuf,&inbuf_tmp);




void * outbuf_tmp;
buffer_conv_a2r(&outbuf,&outbuf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
int ret_tmp= LOCAL_MPI_Unpack( inbuf_tmp, insize, position, outbuf_tmp, outcount, datatype_tmp, comm_tmp);

buffer_conv_r2a(&outbuf,&outbuf_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Unpack\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Unpack(void * inbuf,int insize,int * position,void * outbuf,int outcount,R_MPI_Datatype datatype,R_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : R_MPI_Unpack\n");
#endif
int ret_tmp= LOCAL_MPI_Unpack( inbuf, insize, position, outbuf, outcount, datatype, comm);
#ifdef DEBUG
printf("sort : R_MPI_Unpack\n");
#endif
return ret_tmp;
}
int MPI_Pack_size(int incount,A_MPI_Datatype datatype,A_MPI_Comm comm,int * size);
int (*LOCAL_MPI_Pack_size)(int,R_MPI_Datatype,R_MPI_Comm,int *);

__asm__(
".global PMPI_Pack_size\n"
".weak MPI_Pack_size\n"
".set MPI_Pack_size,PMPI_Pack_size\n"
".extern in_w\n"
".extern A_MPI_Pack_size\n"
".extern R_MPI_Pack_size\n"
".type PMPI_Pack_size,@function\n"
".text\n"
"PMPI_Pack_size:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Pack_size\n"
"jmp *A_MPI_Pack_size@GOTPCREL(%rip)\n"
"inwrap_MPI_Pack_size:\n"
"jmp *R_MPI_Pack_size@GOTPCREL(%rip)\n"
".size PMPI_Pack_size,.-PMPI_Pack_size\n"

);

int A_MPI_Pack_size(int incount,A_MPI_Datatype datatype,A_MPI_Comm comm,int * size)
{
#ifdef DEBUG
printf("entre : A_MPI_Pack_size\n");
#endif
in_w=1;



R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);

int ret_tmp= LOCAL_MPI_Pack_size( incount, datatype_tmp, comm_tmp, size);

in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Pack_size\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Pack_size(int incount,R_MPI_Datatype datatype,R_MPI_Comm comm,int * size)
{
#ifdef DEBUG
printf("entre : R_MPI_Pack_size\n");
#endif
int ret_tmp= LOCAL_MPI_Pack_size( incount, datatype, comm, size);
#ifdef DEBUG
printf("sort : R_MPI_Pack_size\n");
#endif
return ret_tmp;
}
int MPI_Barrier(A_MPI_Comm comm);
int (*LOCAL_MPI_Barrier)(R_MPI_Comm);

__asm__(
".global PMPI_Barrier\n"
".weak MPI_Barrier\n"
".set MPI_Barrier,PMPI_Barrier\n"
".extern in_w\n"
".extern A_MPI_Barrier\n"
".extern R_MPI_Barrier\n"
".type PMPI_Barrier,@function\n"
".text\n"
"PMPI_Barrier:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Barrier\n"
"jmp *A_MPI_Barrier@GOTPCREL(%rip)\n"
"inwrap_MPI_Barrier:\n"
"jmp *R_MPI_Barrier@GOTPCREL(%rip)\n"
".size PMPI_Barrier,.-PMPI_Barrier\n"

);

int A_MPI_Barrier(A_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : A_MPI_Barrier\n");
#endif
in_w=1;

R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
int ret_tmp= LOCAL_MPI_Barrier( comm_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Barrier\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Barrier(R_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : R_MPI_Barrier\n");
#endif
int ret_tmp= LOCAL_MPI_Barrier( comm);
#ifdef DEBUG
printf("sort : R_MPI_Barrier\n");
#endif
return ret_tmp;
}
int MPI_Bcast(void * buffer,int count,A_MPI_Datatype datatype,int root,A_MPI_Comm comm);
int (*LOCAL_MPI_Bcast)(void *,int,R_MPI_Datatype,int,R_MPI_Comm);

__asm__(
".global PMPI_Bcast\n"
".weak MPI_Bcast\n"
".set MPI_Bcast,PMPI_Bcast\n"
".extern in_w\n"
".extern A_MPI_Bcast\n"
".extern R_MPI_Bcast\n"
".type PMPI_Bcast,@function\n"
".text\n"
"PMPI_Bcast:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Bcast\n"
"jmp *A_MPI_Bcast@GOTPCREL(%rip)\n"
"inwrap_MPI_Bcast:\n"
"jmp *R_MPI_Bcast@GOTPCREL(%rip)\n"
".size PMPI_Bcast,.-PMPI_Bcast\n"

);

int A_MPI_Bcast(void * buffer,int count,A_MPI_Datatype datatype,int root,A_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : A_MPI_Bcast\n");
#endif
in_w=1;

void * buffer_tmp;
buffer_conv_a2r(&buffer,&buffer_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);


R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
int ret_tmp= LOCAL_MPI_Bcast( buffer_tmp, count, datatype_tmp, root, comm_tmp);
buffer_conv_r2a(&buffer,&buffer_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Bcast\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Bcast(void * buffer,int count,R_MPI_Datatype datatype,int root,R_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : R_MPI_Bcast\n");
#endif
int ret_tmp= LOCAL_MPI_Bcast( buffer, count, datatype, root, comm);
#ifdef DEBUG
printf("sort : R_MPI_Bcast\n");
#endif
return ret_tmp;
}
int MPI_Gather(void * sendbuf,int sendcount,A_MPI_Datatype sendtype,void * recvbuf,int recvcount,A_MPI_Datatype recvtype,int root,A_MPI_Comm comm);
int (*LOCAL_MPI_Gather)(void *,int,R_MPI_Datatype,void *,int,R_MPI_Datatype,int,R_MPI_Comm);

__asm__(
".global PMPI_Gather\n"
".weak MPI_Gather\n"
".set MPI_Gather,PMPI_Gather\n"
".extern in_w\n"
".extern A_MPI_Gather\n"
".extern R_MPI_Gather\n"
".type PMPI_Gather,@function\n"
".text\n"
"PMPI_Gather:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Gather\n"
"jmp *A_MPI_Gather@GOTPCREL(%rip)\n"
"inwrap_MPI_Gather:\n"
"jmp *R_MPI_Gather@GOTPCREL(%rip)\n"
".size PMPI_Gather,.-PMPI_Gather\n"

);

int A_MPI_Gather(void * sendbuf,int sendcount,A_MPI_Datatype sendtype,void * recvbuf,int recvcount,A_MPI_Datatype recvtype,int root,A_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : A_MPI_Gather\n");
#endif
in_w=1;

void * sendbuf_tmp;
const_buffer_conv_a2r(&sendbuf,&sendbuf_tmp);


R_MPI_Datatype sendtype_tmp;
datatype_conv_a2r(&sendtype,&sendtype_tmp);
void * recvbuf_tmp;
buffer_conv_a2r(&recvbuf,&recvbuf_tmp);


R_MPI_Datatype recvtype_tmp;
datatype_conv_a2r(&recvtype,&recvtype_tmp);


R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
int ret_tmp= LOCAL_MPI_Gather( sendbuf_tmp, sendcount, sendtype_tmp, recvbuf_tmp, recvcount, recvtype_tmp, root, comm_tmp);
buffer_conv_r2a(&recvbuf,&recvbuf_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Gather\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Gather(void * sendbuf,int sendcount,R_MPI_Datatype sendtype,void * recvbuf,int recvcount,R_MPI_Datatype recvtype,int root,R_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : R_MPI_Gather\n");
#endif
int ret_tmp= LOCAL_MPI_Gather( sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm);
#ifdef DEBUG
printf("sort : R_MPI_Gather\n");
#endif
return ret_tmp;
}
int MPI_Gatherv(void * sendbuf,int sendcount,A_MPI_Datatype sendtype,void * recvbuf,int * recvcounts,int * displs,A_MPI_Datatype recvtype,int root,A_MPI_Comm comm);
int (*LOCAL_MPI_Gatherv)(void *,int,R_MPI_Datatype,void *,int *,int *,R_MPI_Datatype,int,R_MPI_Comm);

__asm__(
".global PMPI_Gatherv\n"
".weak MPI_Gatherv\n"
".set MPI_Gatherv,PMPI_Gatherv\n"
".extern in_w\n"
".extern A_MPI_Gatherv\n"
".extern R_MPI_Gatherv\n"
".type PMPI_Gatherv,@function\n"
".text\n"
"PMPI_Gatherv:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Gatherv\n"
"jmp *A_MPI_Gatherv@GOTPCREL(%rip)\n"
"inwrap_MPI_Gatherv:\n"
"jmp *R_MPI_Gatherv@GOTPCREL(%rip)\n"
".size PMPI_Gatherv,.-PMPI_Gatherv\n"

);

int A_MPI_Gatherv(void * sendbuf,int sendcount,A_MPI_Datatype sendtype,void * recvbuf,int * recvcounts,int * displs,A_MPI_Datatype recvtype,int root,A_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : A_MPI_Gatherv\n");
#endif
in_w=1;

void * sendbuf_tmp;
const_buffer_conv_a2r(&sendbuf,&sendbuf_tmp);


R_MPI_Datatype sendtype_tmp;
datatype_conv_a2r(&sendtype,&sendtype_tmp);
void * recvbuf_tmp;
buffer_conv_a2r(&recvbuf,&recvbuf_tmp);




R_MPI_Datatype recvtype_tmp;
datatype_conv_a2r(&recvtype,&recvtype_tmp);


R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
int ret_tmp= LOCAL_MPI_Gatherv( sendbuf_tmp, sendcount, sendtype_tmp, recvbuf_tmp, recvcounts, displs, recvtype_tmp, root, comm_tmp);
buffer_conv_r2a(&recvbuf,&recvbuf_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Gatherv\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Gatherv(void * sendbuf,int sendcount,R_MPI_Datatype sendtype,void * recvbuf,int * recvcounts,int * displs,R_MPI_Datatype recvtype,int root,R_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : R_MPI_Gatherv\n");
#endif
int ret_tmp= LOCAL_MPI_Gatherv( sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm);
#ifdef DEBUG
printf("sort : R_MPI_Gatherv\n");
#endif
return ret_tmp;
}
int MPI_Scatter(void * sendbuf,int sendcount,A_MPI_Datatype sendtype,void * recvbuf,int recvcount,A_MPI_Datatype recvtype,int root,A_MPI_Comm comm);
int (*LOCAL_MPI_Scatter)(void *,int,R_MPI_Datatype,void *,int,R_MPI_Datatype,int,R_MPI_Comm);

__asm__(
".global PMPI_Scatter\n"
".weak MPI_Scatter\n"
".set MPI_Scatter,PMPI_Scatter\n"
".extern in_w\n"
".extern A_MPI_Scatter\n"
".extern R_MPI_Scatter\n"
".type PMPI_Scatter,@function\n"
".text\n"
"PMPI_Scatter:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Scatter\n"
"jmp *A_MPI_Scatter@GOTPCREL(%rip)\n"
"inwrap_MPI_Scatter:\n"
"jmp *R_MPI_Scatter@GOTPCREL(%rip)\n"
".size PMPI_Scatter,.-PMPI_Scatter\n"

);

int A_MPI_Scatter(void * sendbuf,int sendcount,A_MPI_Datatype sendtype,void * recvbuf,int recvcount,A_MPI_Datatype recvtype,int root,A_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : A_MPI_Scatter\n");
#endif
in_w=1;

void * sendbuf_tmp;
const_buffer_conv_a2r(&sendbuf,&sendbuf_tmp);


R_MPI_Datatype sendtype_tmp;
datatype_conv_a2r(&sendtype,&sendtype_tmp);
void * recvbuf_tmp;
buffer_conv_a2r(&recvbuf,&recvbuf_tmp);


R_MPI_Datatype recvtype_tmp;
datatype_conv_a2r(&recvtype,&recvtype_tmp);


R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
int ret_tmp= LOCAL_MPI_Scatter( sendbuf_tmp, sendcount, sendtype_tmp, recvbuf_tmp, recvcount, recvtype_tmp, root, comm_tmp);
buffer_conv_r2a(&recvbuf,&recvbuf_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Scatter\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Scatter(void * sendbuf,int sendcount,R_MPI_Datatype sendtype,void * recvbuf,int recvcount,R_MPI_Datatype recvtype,int root,R_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : R_MPI_Scatter\n");
#endif
int ret_tmp= LOCAL_MPI_Scatter( sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm);
#ifdef DEBUG
printf("sort : R_MPI_Scatter\n");
#endif
return ret_tmp;
}
int MPI_Scatterv(void * sendbuf,int * sendcounts,int * displs,A_MPI_Datatype sendtype,void * recvbuf,int recvcount,A_MPI_Datatype recvtype,int root,A_MPI_Comm comm);
int (*LOCAL_MPI_Scatterv)(void *,int *,int *,R_MPI_Datatype,void *,int,R_MPI_Datatype,int,R_MPI_Comm);

__asm__(
".global PMPI_Scatterv\n"
".weak MPI_Scatterv\n"
".set MPI_Scatterv,PMPI_Scatterv\n"
".extern in_w\n"
".extern A_MPI_Scatterv\n"
".extern R_MPI_Scatterv\n"
".type PMPI_Scatterv,@function\n"
".text\n"
"PMPI_Scatterv:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Scatterv\n"
"jmp *A_MPI_Scatterv@GOTPCREL(%rip)\n"
"inwrap_MPI_Scatterv:\n"
"jmp *R_MPI_Scatterv@GOTPCREL(%rip)\n"
".size PMPI_Scatterv,.-PMPI_Scatterv\n"

);

int A_MPI_Scatterv(void * sendbuf,int * sendcounts,int * displs,A_MPI_Datatype sendtype,void * recvbuf,int recvcount,A_MPI_Datatype recvtype,int root,A_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : A_MPI_Scatterv\n");
#endif
in_w=1;

void * sendbuf_tmp;
const_buffer_conv_a2r(&sendbuf,&sendbuf_tmp);




R_MPI_Datatype sendtype_tmp;
datatype_conv_a2r(&sendtype,&sendtype_tmp);
void * recvbuf_tmp;
buffer_conv_a2r(&recvbuf,&recvbuf_tmp);


R_MPI_Datatype recvtype_tmp;
datatype_conv_a2r(&recvtype,&recvtype_tmp);


R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
int ret_tmp= LOCAL_MPI_Scatterv( sendbuf_tmp, sendcounts, displs, sendtype_tmp, recvbuf_tmp, recvcount, recvtype_tmp, root, comm_tmp);
buffer_conv_r2a(&recvbuf,&recvbuf_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Scatterv\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Scatterv(void * sendbuf,int * sendcounts,int * displs,R_MPI_Datatype sendtype,void * recvbuf,int recvcount,R_MPI_Datatype recvtype,int root,R_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : R_MPI_Scatterv\n");
#endif
int ret_tmp= LOCAL_MPI_Scatterv( sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm);
#ifdef DEBUG
printf("sort : R_MPI_Scatterv\n");
#endif
return ret_tmp;
}
int MPI_Allgather(void * sendbuf,int sendcount,A_MPI_Datatype sendtype,void * recvbuf,int recvcount,A_MPI_Datatype recvtype,A_MPI_Comm comm);
int (*LOCAL_MPI_Allgather)(void *,int,R_MPI_Datatype,void *,int,R_MPI_Datatype,R_MPI_Comm);

__asm__(
".global PMPI_Allgather\n"
".weak MPI_Allgather\n"
".set MPI_Allgather,PMPI_Allgather\n"
".extern in_w\n"
".extern A_MPI_Allgather\n"
".extern R_MPI_Allgather\n"
".type PMPI_Allgather,@function\n"
".text\n"
"PMPI_Allgather:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Allgather\n"
"jmp *A_MPI_Allgather@GOTPCREL(%rip)\n"
"inwrap_MPI_Allgather:\n"
"jmp *R_MPI_Allgather@GOTPCREL(%rip)\n"
".size PMPI_Allgather,.-PMPI_Allgather\n"

);

int A_MPI_Allgather(void * sendbuf,int sendcount,A_MPI_Datatype sendtype,void * recvbuf,int recvcount,A_MPI_Datatype recvtype,A_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : A_MPI_Allgather\n");
#endif
in_w=1;

void * sendbuf_tmp;
const_buffer_conv_a2r(&sendbuf,&sendbuf_tmp);


R_MPI_Datatype sendtype_tmp;
datatype_conv_a2r(&sendtype,&sendtype_tmp);
void * recvbuf_tmp;
buffer_conv_a2r(&recvbuf,&recvbuf_tmp);


R_MPI_Datatype recvtype_tmp;
datatype_conv_a2r(&recvtype,&recvtype_tmp);
R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
int ret_tmp= LOCAL_MPI_Allgather( sendbuf_tmp, sendcount, sendtype_tmp, recvbuf_tmp, recvcount, recvtype_tmp, comm_tmp);
buffer_conv_r2a(&recvbuf,&recvbuf_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Allgather\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Allgather(void * sendbuf,int sendcount,R_MPI_Datatype sendtype,void * recvbuf,int recvcount,R_MPI_Datatype recvtype,R_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : R_MPI_Allgather\n");
#endif
int ret_tmp= LOCAL_MPI_Allgather( sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm);
#ifdef DEBUG
printf("sort : R_MPI_Allgather\n");
#endif
return ret_tmp;
}
int MPI_Allgatherv(void * sendbuf,int sendcount,A_MPI_Datatype sendtype,void * recvbuf,int * recvcounts,int * displs,A_MPI_Datatype recvtype,A_MPI_Comm comm);
int (*LOCAL_MPI_Allgatherv)(void *,int,R_MPI_Datatype,void *,int *,int *,R_MPI_Datatype,R_MPI_Comm);

__asm__(
".global PMPI_Allgatherv\n"
".weak MPI_Allgatherv\n"
".set MPI_Allgatherv,PMPI_Allgatherv\n"
".extern in_w\n"
".extern A_MPI_Allgatherv\n"
".extern R_MPI_Allgatherv\n"
".type PMPI_Allgatherv,@function\n"
".text\n"
"PMPI_Allgatherv:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Allgatherv\n"
"jmp *A_MPI_Allgatherv@GOTPCREL(%rip)\n"
"inwrap_MPI_Allgatherv:\n"
"jmp *R_MPI_Allgatherv@GOTPCREL(%rip)\n"
".size PMPI_Allgatherv,.-PMPI_Allgatherv\n"

);

int A_MPI_Allgatherv(void * sendbuf,int sendcount,A_MPI_Datatype sendtype,void * recvbuf,int * recvcounts,int * displs,A_MPI_Datatype recvtype,A_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : A_MPI_Allgatherv\n");
#endif
in_w=1;

void * sendbuf_tmp;
const_buffer_conv_a2r(&sendbuf,&sendbuf_tmp);


R_MPI_Datatype sendtype_tmp;
datatype_conv_a2r(&sendtype,&sendtype_tmp);
void * recvbuf_tmp;
buffer_conv_a2r(&recvbuf,&recvbuf_tmp);




R_MPI_Datatype recvtype_tmp;
datatype_conv_a2r(&recvtype,&recvtype_tmp);
R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
int ret_tmp= LOCAL_MPI_Allgatherv( sendbuf_tmp, sendcount, sendtype_tmp, recvbuf_tmp, recvcounts, displs, recvtype_tmp, comm_tmp);
buffer_conv_r2a(&recvbuf,&recvbuf_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Allgatherv\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Allgatherv(void * sendbuf,int sendcount,R_MPI_Datatype sendtype,void * recvbuf,int * recvcounts,int * displs,R_MPI_Datatype recvtype,R_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : R_MPI_Allgatherv\n");
#endif
int ret_tmp= LOCAL_MPI_Allgatherv( sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm);
#ifdef DEBUG
printf("sort : R_MPI_Allgatherv\n");
#endif
return ret_tmp;
}
int MPI_Alltoall(void * sendbuf,int sendcount,A_MPI_Datatype sendtype,void * recvbuf,int recvcount,A_MPI_Datatype recvtype,A_MPI_Comm comm);
int (*LOCAL_MPI_Alltoall)(void *,int,R_MPI_Datatype,void *,int,R_MPI_Datatype,R_MPI_Comm);

__asm__(
".global PMPI_Alltoall\n"
".weak MPI_Alltoall\n"
".set MPI_Alltoall,PMPI_Alltoall\n"
".extern in_w\n"
".extern A_MPI_Alltoall\n"
".extern R_MPI_Alltoall\n"
".type PMPI_Alltoall,@function\n"
".text\n"
"PMPI_Alltoall:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Alltoall\n"
"jmp *A_MPI_Alltoall@GOTPCREL(%rip)\n"
"inwrap_MPI_Alltoall:\n"
"jmp *R_MPI_Alltoall@GOTPCREL(%rip)\n"
".size PMPI_Alltoall,.-PMPI_Alltoall\n"

);

int A_MPI_Alltoall(void * sendbuf,int sendcount,A_MPI_Datatype sendtype,void * recvbuf,int recvcount,A_MPI_Datatype recvtype,A_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : A_MPI_Alltoall\n");
#endif
in_w=1;

void * sendbuf_tmp;
const_buffer_conv_a2r(&sendbuf,&sendbuf_tmp);


R_MPI_Datatype sendtype_tmp;
datatype_conv_a2r(&sendtype,&sendtype_tmp);
void * recvbuf_tmp;
buffer_conv_a2r(&recvbuf,&recvbuf_tmp);


R_MPI_Datatype recvtype_tmp;
datatype_conv_a2r(&recvtype,&recvtype_tmp);
R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
int ret_tmp= LOCAL_MPI_Alltoall( sendbuf_tmp, sendcount, sendtype_tmp, recvbuf_tmp, recvcount, recvtype_tmp, comm_tmp);
buffer_conv_r2a(&recvbuf,&recvbuf_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Alltoall\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Alltoall(void * sendbuf,int sendcount,R_MPI_Datatype sendtype,void * recvbuf,int recvcount,R_MPI_Datatype recvtype,R_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : R_MPI_Alltoall\n");
#endif
int ret_tmp= LOCAL_MPI_Alltoall( sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm);
#ifdef DEBUG
printf("sort : R_MPI_Alltoall\n");
#endif
return ret_tmp;
}
int MPI_Alltoallv(void * sendbuf,int * sendcounts,int * sdispls,A_MPI_Datatype sendtype,void * recvbuf,int * recvcounts,int * rdispls,A_MPI_Datatype recvtype,A_MPI_Comm comm);
int (*LOCAL_MPI_Alltoallv)(void *,int *,int *,R_MPI_Datatype,void *,int *,int *,R_MPI_Datatype,R_MPI_Comm);

__asm__(
".global PMPI_Alltoallv\n"
".weak MPI_Alltoallv\n"
".set MPI_Alltoallv,PMPI_Alltoallv\n"
".extern in_w\n"
".extern A_MPI_Alltoallv\n"
".extern R_MPI_Alltoallv\n"
".type PMPI_Alltoallv,@function\n"
".text\n"
"PMPI_Alltoallv:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Alltoallv\n"
"jmp *A_MPI_Alltoallv@GOTPCREL(%rip)\n"
"inwrap_MPI_Alltoallv:\n"
"jmp *R_MPI_Alltoallv@GOTPCREL(%rip)\n"
".size PMPI_Alltoallv,.-PMPI_Alltoallv\n"

);

int A_MPI_Alltoallv(void * sendbuf,int * sendcounts,int * sdispls,A_MPI_Datatype sendtype,void * recvbuf,int * recvcounts,int * rdispls,A_MPI_Datatype recvtype,A_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : A_MPI_Alltoallv\n");
#endif
in_w=1;

void * sendbuf_tmp;
const_buffer_conv_a2r(&sendbuf,&sendbuf_tmp);




R_MPI_Datatype sendtype_tmp;
datatype_conv_a2r(&sendtype,&sendtype_tmp);
void * recvbuf_tmp;
buffer_conv_a2r(&recvbuf,&recvbuf_tmp);




R_MPI_Datatype recvtype_tmp;
datatype_conv_a2r(&recvtype,&recvtype_tmp);
R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
int ret_tmp= LOCAL_MPI_Alltoallv( sendbuf_tmp, sendcounts, sdispls, sendtype_tmp, recvbuf_tmp, recvcounts, rdispls, recvtype_tmp, comm_tmp);
buffer_conv_r2a(&recvbuf,&recvbuf_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Alltoallv\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Alltoallv(void * sendbuf,int * sendcounts,int * sdispls,R_MPI_Datatype sendtype,void * recvbuf,int * recvcounts,int * rdispls,R_MPI_Datatype recvtype,R_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : R_MPI_Alltoallv\n");
#endif
int ret_tmp= LOCAL_MPI_Alltoallv( sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm);
#ifdef DEBUG
printf("sort : R_MPI_Alltoallv\n");
#endif
return ret_tmp;
}
int MPI_Reduce(void * sendbuf,void * recvbuf,int count,A_MPI_Datatype datatype,A_MPI_Op op,int root,A_MPI_Comm comm);
int (*LOCAL_MPI_Reduce)(void *,void *,int,R_MPI_Datatype,R_MPI_Op,int,R_MPI_Comm);

__asm__(
".global PMPI_Reduce\n"
".weak MPI_Reduce\n"
".set MPI_Reduce,PMPI_Reduce\n"
".extern in_w\n"
".extern A_MPI_Reduce\n"
".extern R_MPI_Reduce\n"
".type PMPI_Reduce,@function\n"
".text\n"
"PMPI_Reduce:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Reduce\n"
"jmp *A_MPI_Reduce@GOTPCREL(%rip)\n"
"inwrap_MPI_Reduce:\n"
"jmp *R_MPI_Reduce@GOTPCREL(%rip)\n"
".size PMPI_Reduce,.-PMPI_Reduce\n"

);

int A_MPI_Reduce(void * sendbuf,void * recvbuf,int count,A_MPI_Datatype datatype,A_MPI_Op op,int root,A_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : A_MPI_Reduce\n");
#endif
in_w=1;

void * sendbuf_tmp;
const_buffer_conv_a2r(&sendbuf,&sendbuf_tmp);
void * recvbuf_tmp;
buffer_conv_a2r(&recvbuf,&recvbuf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
R_MPI_Op op_tmp;
op_conv_a2r(&op,&op_tmp);


R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
int ret_tmp= LOCAL_MPI_Reduce( sendbuf_tmp, recvbuf_tmp, count, datatype_tmp, op_tmp, root, comm_tmp);
buffer_conv_r2a(&recvbuf,&recvbuf_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Reduce\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Reduce(void * sendbuf,void * recvbuf,int count,R_MPI_Datatype datatype,R_MPI_Op op,int root,R_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : R_MPI_Reduce\n");
#endif
int ret_tmp= LOCAL_MPI_Reduce( sendbuf, recvbuf, count, datatype, op, root, comm);
#ifdef DEBUG
printf("sort : R_MPI_Reduce\n");
#endif
return ret_tmp;
}
int MPI_Op_create(A_MPI_User_function * user_fn,int commute,A_MPI_Op * op);
int (*LOCAL_MPI_Op_create)(R_MPI_User_function *,int,R_MPI_Op *);

__asm__(
".global PMPI_Op_create\n"
".weak MPI_Op_create\n"
".set MPI_Op_create,PMPI_Op_create\n"
".extern in_w\n"
".extern A_MPI_Op_create\n"
".extern R_MPI_Op_create\n"
".type PMPI_Op_create,@function\n"
".text\n"
"PMPI_Op_create:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Op_create\n"
"jmp *A_MPI_Op_create@GOTPCREL(%rip)\n"
"inwrap_MPI_Op_create:\n"
"jmp *R_MPI_Op_create@GOTPCREL(%rip)\n"
".size PMPI_Op_create,.-PMPI_Op_create\n"

);

int A_MPI_Op_create(A_MPI_User_function * user_fn,int commute,A_MPI_Op * op)
{
#ifdef DEBUG
printf("entre : A_MPI_Op_create\n");
#endif
in_w=1;


ptr_user_func=(A_MPI_User_function *)user_fn;


R_MPI_Op  op_ltmp;
R_MPI_Op * op_tmp=&op_ltmp;
int ret_tmp= LOCAL_MPI_Op_create( (R_MPI_User_function *)wrapper_user_function, commute, op_tmp);
op_conv_r2a(op,op_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Op_create\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Op_create(R_MPI_User_function * user_fn,int commute,R_MPI_Op * op)
{
#ifdef DEBUG
printf("entre : R_MPI_Op_create\n");
#endif
int ret_tmp= LOCAL_MPI_Op_create( user_fn, commute, op);
#ifdef DEBUG
printf("sort : R_MPI_Op_create\n");
#endif
return ret_tmp;
}
int MPI_Op_free(A_MPI_Op * op);
int (*LOCAL_MPI_Op_free)(R_MPI_Op *);

__asm__(
".global PMPI_Op_free\n"
".weak MPI_Op_free\n"
".set MPI_Op_free,PMPI_Op_free\n"
".extern in_w\n"
".extern A_MPI_Op_free\n"
".extern R_MPI_Op_free\n"
".type PMPI_Op_free,@function\n"
".text\n"
"PMPI_Op_free:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Op_free\n"
"jmp *A_MPI_Op_free@GOTPCREL(%rip)\n"
"inwrap_MPI_Op_free:\n"
"jmp *R_MPI_Op_free@GOTPCREL(%rip)\n"
".size PMPI_Op_free,.-PMPI_Op_free\n"

);

int A_MPI_Op_free(A_MPI_Op * op)
{
#ifdef DEBUG
printf("entre : A_MPI_Op_free\n");
#endif
in_w=1;

R_MPI_Op  op_ltmp;
R_MPI_Op * op_tmp=&op_ltmp;
op_conv_a2r(op,op_tmp);
int ret_tmp= LOCAL_MPI_Op_free( op_tmp);
op_conv_r2a(op,op_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Op_free\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Op_free(R_MPI_Op * op)
{
#ifdef DEBUG
printf("entre : R_MPI_Op_free\n");
#endif
int ret_tmp= LOCAL_MPI_Op_free( op);
#ifdef DEBUG
printf("sort : R_MPI_Op_free\n");
#endif
return ret_tmp;
}
int MPI_Allreduce(void * sendbuf,void * recvbuf,int count,A_MPI_Datatype datatype,A_MPI_Op op,A_MPI_Comm comm);
int (*LOCAL_MPI_Allreduce)(void *,void *,int,R_MPI_Datatype,R_MPI_Op,R_MPI_Comm);

__asm__(
".global PMPI_Allreduce\n"
".weak MPI_Allreduce\n"
".set MPI_Allreduce,PMPI_Allreduce\n"
".extern in_w\n"
".extern A_MPI_Allreduce\n"
".extern R_MPI_Allreduce\n"
".type PMPI_Allreduce,@function\n"
".text\n"
"PMPI_Allreduce:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Allreduce\n"
"jmp *A_MPI_Allreduce@GOTPCREL(%rip)\n"
"inwrap_MPI_Allreduce:\n"
"jmp *R_MPI_Allreduce@GOTPCREL(%rip)\n"
".size PMPI_Allreduce,.-PMPI_Allreduce\n"

);

int A_MPI_Allreduce(void * sendbuf,void * recvbuf,int count,A_MPI_Datatype datatype,A_MPI_Op op,A_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : A_MPI_Allreduce\n");
#endif
in_w=1;

void * sendbuf_tmp;
const_buffer_conv_a2r(&sendbuf,&sendbuf_tmp);
void * recvbuf_tmp;
buffer_conv_a2r(&recvbuf,&recvbuf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
R_MPI_Op op_tmp;
op_conv_a2r(&op,&op_tmp);
R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
int ret_tmp= LOCAL_MPI_Allreduce( sendbuf_tmp, recvbuf_tmp, count, datatype_tmp, op_tmp, comm_tmp);
buffer_conv_r2a(&recvbuf,&recvbuf_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Allreduce\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Allreduce(void * sendbuf,void * recvbuf,int count,R_MPI_Datatype datatype,R_MPI_Op op,R_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : R_MPI_Allreduce\n");
#endif
int ret_tmp= LOCAL_MPI_Allreduce( sendbuf, recvbuf, count, datatype, op, comm);
#ifdef DEBUG
printf("sort : R_MPI_Allreduce\n");
#endif
return ret_tmp;
}
int MPI_Scan(void * sendbuf,void * recvbuf,int count,A_MPI_Datatype datatype,A_MPI_Op op,A_MPI_Comm comm);
int (*LOCAL_MPI_Scan)(void *,void *,int,R_MPI_Datatype,R_MPI_Op,R_MPI_Comm);

__asm__(
".global PMPI_Scan\n"
".weak MPI_Scan\n"
".set MPI_Scan,PMPI_Scan\n"
".extern in_w\n"
".extern A_MPI_Scan\n"
".extern R_MPI_Scan\n"
".type PMPI_Scan,@function\n"
".text\n"
"PMPI_Scan:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Scan\n"
"jmp *A_MPI_Scan@GOTPCREL(%rip)\n"
"inwrap_MPI_Scan:\n"
"jmp *R_MPI_Scan@GOTPCREL(%rip)\n"
".size PMPI_Scan,.-PMPI_Scan\n"

);

int A_MPI_Scan(void * sendbuf,void * recvbuf,int count,A_MPI_Datatype datatype,A_MPI_Op op,A_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : A_MPI_Scan\n");
#endif
in_w=1;

void * sendbuf_tmp;
const_buffer_conv_a2r(&sendbuf,&sendbuf_tmp);
void * recvbuf_tmp;
buffer_conv_a2r(&recvbuf,&recvbuf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
R_MPI_Op op_tmp;
op_conv_a2r(&op,&op_tmp);
R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
int ret_tmp= LOCAL_MPI_Scan( sendbuf_tmp, recvbuf_tmp, count, datatype_tmp, op_tmp, comm_tmp);
buffer_conv_r2a(&recvbuf,&recvbuf_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Scan\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Scan(void * sendbuf,void * recvbuf,int count,R_MPI_Datatype datatype,R_MPI_Op op,R_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : R_MPI_Scan\n");
#endif
int ret_tmp= LOCAL_MPI_Scan( sendbuf, recvbuf, count, datatype, op, comm);
#ifdef DEBUG
printf("sort : R_MPI_Scan\n");
#endif
return ret_tmp;
}
int MPI_Group_size(A_MPI_Group group,int * size);
int (*LOCAL_MPI_Group_size)(R_MPI_Group,int *);

__asm__(
".global PMPI_Group_size\n"
".weak MPI_Group_size\n"
".set MPI_Group_size,PMPI_Group_size\n"
".extern in_w\n"
".extern A_MPI_Group_size\n"
".extern R_MPI_Group_size\n"
".type PMPI_Group_size,@function\n"
".text\n"
"PMPI_Group_size:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Group_size\n"
"jmp *A_MPI_Group_size@GOTPCREL(%rip)\n"
"inwrap_MPI_Group_size:\n"
"jmp *R_MPI_Group_size@GOTPCREL(%rip)\n"
".size PMPI_Group_size,.-PMPI_Group_size\n"

);

int A_MPI_Group_size(A_MPI_Group group,int * size)
{
#ifdef DEBUG
printf("entre : A_MPI_Group_size\n");
#endif
in_w=1;

R_MPI_Group group_tmp;
group_conv_a2r(&group,&group_tmp);

int ret_tmp= LOCAL_MPI_Group_size( group_tmp, size);

in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Group_size\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Group_size(R_MPI_Group group,int * size)
{
#ifdef DEBUG
printf("entre : R_MPI_Group_size\n");
#endif
int ret_tmp= LOCAL_MPI_Group_size( group, size);
#ifdef DEBUG
printf("sort : R_MPI_Group_size\n");
#endif
return ret_tmp;
}
int MPI_Group_rank(A_MPI_Group group,int * rank);
int (*LOCAL_MPI_Group_rank)(R_MPI_Group,int *);

__asm__(
".global PMPI_Group_rank\n"
".weak MPI_Group_rank\n"
".set MPI_Group_rank,PMPI_Group_rank\n"
".extern in_w\n"
".extern A_MPI_Group_rank\n"
".extern R_MPI_Group_rank\n"
".type PMPI_Group_rank,@function\n"
".text\n"
"PMPI_Group_rank:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Group_rank\n"
"jmp *A_MPI_Group_rank@GOTPCREL(%rip)\n"
"inwrap_MPI_Group_rank:\n"
"jmp *R_MPI_Group_rank@GOTPCREL(%rip)\n"
".size PMPI_Group_rank,.-PMPI_Group_rank\n"

);

int A_MPI_Group_rank(A_MPI_Group group,int * rank)
{
#ifdef DEBUG
printf("entre : A_MPI_Group_rank\n");
#endif
in_w=1;

R_MPI_Group group_tmp;
group_conv_a2r(&group,&group_tmp);

int ret_tmp= LOCAL_MPI_Group_rank( group_tmp, rank);

in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Group_rank\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Group_rank(R_MPI_Group group,int * rank)
{
#ifdef DEBUG
printf("entre : R_MPI_Group_rank\n");
#endif
int ret_tmp= LOCAL_MPI_Group_rank( group, rank);
#ifdef DEBUG
printf("sort : R_MPI_Group_rank\n");
#endif
return ret_tmp;
}
int MPI_Group_compare(A_MPI_Group group1,A_MPI_Group group2,int * result);
int (*LOCAL_MPI_Group_compare)(R_MPI_Group,R_MPI_Group,int *);

__asm__(
".global PMPI_Group_compare\n"
".weak MPI_Group_compare\n"
".set MPI_Group_compare,PMPI_Group_compare\n"
".extern in_w\n"
".extern A_MPI_Group_compare\n"
".extern R_MPI_Group_compare\n"
".type PMPI_Group_compare,@function\n"
".text\n"
"PMPI_Group_compare:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Group_compare\n"
"jmp *A_MPI_Group_compare@GOTPCREL(%rip)\n"
"inwrap_MPI_Group_compare:\n"
"jmp *R_MPI_Group_compare@GOTPCREL(%rip)\n"
".size PMPI_Group_compare,.-PMPI_Group_compare\n"

);

int A_MPI_Group_compare(A_MPI_Group group1,A_MPI_Group group2,int * result)
{
#ifdef DEBUG
printf("entre : A_MPI_Group_compare\n");
#endif
in_w=1;

R_MPI_Group group1_tmp;
group_conv_a2r(&group1,&group1_tmp);
R_MPI_Group group2_tmp;
group_conv_a2r(&group2,&group2_tmp);

int ret_tmp= LOCAL_MPI_Group_compare( group1_tmp, group2_tmp, result);

in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Group_compare\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Group_compare(R_MPI_Group group1,R_MPI_Group group2,int * result)
{
#ifdef DEBUG
printf("entre : R_MPI_Group_compare\n");
#endif
int ret_tmp= LOCAL_MPI_Group_compare( group1, group2, result);
#ifdef DEBUG
printf("sort : R_MPI_Group_compare\n");
#endif
return ret_tmp;
}
int MPI_Comm_group(A_MPI_Comm comm,A_MPI_Group * group);
int (*LOCAL_MPI_Comm_group)(R_MPI_Comm,R_MPI_Group *);

__asm__(
".global PMPI_Comm_group\n"
".weak MPI_Comm_group\n"
".set MPI_Comm_group,PMPI_Comm_group\n"
".extern in_w\n"
".extern A_MPI_Comm_group\n"
".extern R_MPI_Comm_group\n"
".type PMPI_Comm_group,@function\n"
".text\n"
"PMPI_Comm_group:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Comm_group\n"
"jmp *A_MPI_Comm_group@GOTPCREL(%rip)\n"
"inwrap_MPI_Comm_group:\n"
"jmp *R_MPI_Comm_group@GOTPCREL(%rip)\n"
".size PMPI_Comm_group,.-PMPI_Comm_group\n"

);

int A_MPI_Comm_group(A_MPI_Comm comm,A_MPI_Group * group)
{
#ifdef DEBUG
printf("entre : A_MPI_Comm_group\n");
#endif
in_w=1;

R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
R_MPI_Group  group_ltmp;
R_MPI_Group * group_tmp=&group_ltmp;
int ret_tmp= LOCAL_MPI_Comm_group( comm_tmp, group_tmp);
group_conv_r2a(group,group_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Comm_group\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Comm_group(R_MPI_Comm comm,R_MPI_Group * group)
{
#ifdef DEBUG
printf("entre : R_MPI_Comm_group\n");
#endif
int ret_tmp= LOCAL_MPI_Comm_group( comm, group);
#ifdef DEBUG
printf("sort : R_MPI_Comm_group\n");
#endif
return ret_tmp;
}
int MPI_Group_union(A_MPI_Group group1,A_MPI_Group group2,A_MPI_Group * newgroup);
int (*LOCAL_MPI_Group_union)(R_MPI_Group,R_MPI_Group,R_MPI_Group *);

__asm__(
".global PMPI_Group_union\n"
".weak MPI_Group_union\n"
".set MPI_Group_union,PMPI_Group_union\n"
".extern in_w\n"
".extern A_MPI_Group_union\n"
".extern R_MPI_Group_union\n"
".type PMPI_Group_union,@function\n"
".text\n"
"PMPI_Group_union:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Group_union\n"
"jmp *A_MPI_Group_union@GOTPCREL(%rip)\n"
"inwrap_MPI_Group_union:\n"
"jmp *R_MPI_Group_union@GOTPCREL(%rip)\n"
".size PMPI_Group_union,.-PMPI_Group_union\n"

);

int A_MPI_Group_union(A_MPI_Group group1,A_MPI_Group group2,A_MPI_Group * newgroup)
{
#ifdef DEBUG
printf("entre : A_MPI_Group_union\n");
#endif
in_w=1;

R_MPI_Group group1_tmp;
group_conv_a2r(&group1,&group1_tmp);
R_MPI_Group group2_tmp;
group_conv_a2r(&group2,&group2_tmp);
R_MPI_Group  newgroup_ltmp;
R_MPI_Group * newgroup_tmp=&newgroup_ltmp;
int ret_tmp= LOCAL_MPI_Group_union( group1_tmp, group2_tmp, newgroup_tmp);
group_conv_r2a(newgroup,newgroup_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Group_union\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Group_union(R_MPI_Group group1,R_MPI_Group group2,R_MPI_Group * newgroup)
{
#ifdef DEBUG
printf("entre : R_MPI_Group_union\n");
#endif
int ret_tmp= LOCAL_MPI_Group_union( group1, group2, newgroup);
#ifdef DEBUG
printf("sort : R_MPI_Group_union\n");
#endif
return ret_tmp;
}
int MPI_Group_intersection(A_MPI_Group group1,A_MPI_Group group2,A_MPI_Group * newgroup);
int (*LOCAL_MPI_Group_intersection)(R_MPI_Group,R_MPI_Group,R_MPI_Group *);

__asm__(
".global PMPI_Group_intersection\n"
".weak MPI_Group_intersection\n"
".set MPI_Group_intersection,PMPI_Group_intersection\n"
".extern in_w\n"
".extern A_MPI_Group_intersection\n"
".extern R_MPI_Group_intersection\n"
".type PMPI_Group_intersection,@function\n"
".text\n"
"PMPI_Group_intersection:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Group_intersection\n"
"jmp *A_MPI_Group_intersection@GOTPCREL(%rip)\n"
"inwrap_MPI_Group_intersection:\n"
"jmp *R_MPI_Group_intersection@GOTPCREL(%rip)\n"
".size PMPI_Group_intersection,.-PMPI_Group_intersection\n"

);

int A_MPI_Group_intersection(A_MPI_Group group1,A_MPI_Group group2,A_MPI_Group * newgroup)
{
#ifdef DEBUG
printf("entre : A_MPI_Group_intersection\n");
#endif
in_w=1;

R_MPI_Group group1_tmp;
group_conv_a2r(&group1,&group1_tmp);
R_MPI_Group group2_tmp;
group_conv_a2r(&group2,&group2_tmp);
R_MPI_Group  newgroup_ltmp;
R_MPI_Group * newgroup_tmp=&newgroup_ltmp;
int ret_tmp= LOCAL_MPI_Group_intersection( group1_tmp, group2_tmp, newgroup_tmp);
group_conv_r2a(newgroup,newgroup_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Group_intersection\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Group_intersection(R_MPI_Group group1,R_MPI_Group group2,R_MPI_Group * newgroup)
{
#ifdef DEBUG
printf("entre : R_MPI_Group_intersection\n");
#endif
int ret_tmp= LOCAL_MPI_Group_intersection( group1, group2, newgroup);
#ifdef DEBUG
printf("sort : R_MPI_Group_intersection\n");
#endif
return ret_tmp;
}
int MPI_Group_difference(A_MPI_Group group1,A_MPI_Group group2,A_MPI_Group * newgroup);
int (*LOCAL_MPI_Group_difference)(R_MPI_Group,R_MPI_Group,R_MPI_Group *);

__asm__(
".global PMPI_Group_difference\n"
".weak MPI_Group_difference\n"
".set MPI_Group_difference,PMPI_Group_difference\n"
".extern in_w\n"
".extern A_MPI_Group_difference\n"
".extern R_MPI_Group_difference\n"
".type PMPI_Group_difference,@function\n"
".text\n"
"PMPI_Group_difference:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Group_difference\n"
"jmp *A_MPI_Group_difference@GOTPCREL(%rip)\n"
"inwrap_MPI_Group_difference:\n"
"jmp *R_MPI_Group_difference@GOTPCREL(%rip)\n"
".size PMPI_Group_difference,.-PMPI_Group_difference\n"

);

int A_MPI_Group_difference(A_MPI_Group group1,A_MPI_Group group2,A_MPI_Group * newgroup)
{
#ifdef DEBUG
printf("entre : A_MPI_Group_difference\n");
#endif
in_w=1;

R_MPI_Group group1_tmp;
group_conv_a2r(&group1,&group1_tmp);
R_MPI_Group group2_tmp;
group_conv_a2r(&group2,&group2_tmp);
R_MPI_Group  newgroup_ltmp;
R_MPI_Group * newgroup_tmp=&newgroup_ltmp;
int ret_tmp= LOCAL_MPI_Group_difference( group1_tmp, group2_tmp, newgroup_tmp);
group_conv_r2a(newgroup,newgroup_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Group_difference\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Group_difference(R_MPI_Group group1,R_MPI_Group group2,R_MPI_Group * newgroup)
{
#ifdef DEBUG
printf("entre : R_MPI_Group_difference\n");
#endif
int ret_tmp= LOCAL_MPI_Group_difference( group1, group2, newgroup);
#ifdef DEBUG
printf("sort : R_MPI_Group_difference\n");
#endif
return ret_tmp;
}
int MPI_Group_free(A_MPI_Group * group);
int (*LOCAL_MPI_Group_free)(R_MPI_Group *);

__asm__(
".global PMPI_Group_free\n"
".weak MPI_Group_free\n"
".set MPI_Group_free,PMPI_Group_free\n"
".extern in_w\n"
".extern A_MPI_Group_free\n"
".extern R_MPI_Group_free\n"
".type PMPI_Group_free,@function\n"
".text\n"
"PMPI_Group_free:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Group_free\n"
"jmp *A_MPI_Group_free@GOTPCREL(%rip)\n"
"inwrap_MPI_Group_free:\n"
"jmp *R_MPI_Group_free@GOTPCREL(%rip)\n"
".size PMPI_Group_free,.-PMPI_Group_free\n"

);

int A_MPI_Group_free(A_MPI_Group * group)
{
#ifdef DEBUG
printf("entre : A_MPI_Group_free\n");
#endif
in_w=1;

R_MPI_Group  group_ltmp;
R_MPI_Group * group_tmp=&group_ltmp;
group_conv_a2r(group,group_tmp);
int ret_tmp= LOCAL_MPI_Group_free( group_tmp);
group_conv_r2a(group,group_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Group_free\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Group_free(R_MPI_Group * group)
{
#ifdef DEBUG
printf("entre : R_MPI_Group_free\n");
#endif
int ret_tmp= LOCAL_MPI_Group_free( group);
#ifdef DEBUG
printf("sort : R_MPI_Group_free\n");
#endif
return ret_tmp;
}
int MPI_Comm_size(A_MPI_Comm comm,int * size);
int (*LOCAL_MPI_Comm_size)(R_MPI_Comm,int *);

__asm__(
".global PMPI_Comm_size\n"
".weak MPI_Comm_size\n"
".set MPI_Comm_size,PMPI_Comm_size\n"
".extern in_w\n"
".extern A_MPI_Comm_size\n"
".extern R_MPI_Comm_size\n"
".type PMPI_Comm_size,@function\n"
".text\n"
"PMPI_Comm_size:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Comm_size\n"
"jmp *A_MPI_Comm_size@GOTPCREL(%rip)\n"
"inwrap_MPI_Comm_size:\n"
"jmp *R_MPI_Comm_size@GOTPCREL(%rip)\n"
".size PMPI_Comm_size,.-PMPI_Comm_size\n"

);

int A_MPI_Comm_size(A_MPI_Comm comm,int * size)
{
#ifdef DEBUG
printf("entre : A_MPI_Comm_size\n");
#endif
in_w=1;

R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);

int ret_tmp= LOCAL_MPI_Comm_size( comm_tmp, size);

in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Comm_size\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Comm_size(R_MPI_Comm comm,int * size)
{
#ifdef DEBUG
printf("entre : R_MPI_Comm_size\n");
#endif
int ret_tmp= LOCAL_MPI_Comm_size( comm, size);
#ifdef DEBUG
printf("sort : R_MPI_Comm_size\n");
#endif
return ret_tmp;
}
int MPI_Comm_rank(A_MPI_Comm comm,int * rank);
int (*LOCAL_MPI_Comm_rank)(R_MPI_Comm,int *);

__asm__(
".global PMPI_Comm_rank\n"
".weak MPI_Comm_rank\n"
".set MPI_Comm_rank,PMPI_Comm_rank\n"
".extern in_w\n"
".extern A_MPI_Comm_rank\n"
".extern R_MPI_Comm_rank\n"
".type PMPI_Comm_rank,@function\n"
".text\n"
"PMPI_Comm_rank:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Comm_rank\n"
"jmp *A_MPI_Comm_rank@GOTPCREL(%rip)\n"
"inwrap_MPI_Comm_rank:\n"
"jmp *R_MPI_Comm_rank@GOTPCREL(%rip)\n"
".size PMPI_Comm_rank,.-PMPI_Comm_rank\n"

);

int A_MPI_Comm_rank(A_MPI_Comm comm,int * rank)
{
#ifdef DEBUG
printf("entre : A_MPI_Comm_rank\n");
#endif
in_w=1;

R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);

int ret_tmp= LOCAL_MPI_Comm_rank( comm_tmp, rank);

in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Comm_rank\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Comm_rank(R_MPI_Comm comm,int * rank)
{
#ifdef DEBUG
printf("entre : R_MPI_Comm_rank\n");
#endif
int ret_tmp= LOCAL_MPI_Comm_rank( comm, rank);
#ifdef DEBUG
printf("sort : R_MPI_Comm_rank\n");
#endif
return ret_tmp;
}
int MPI_Comm_compare(A_MPI_Comm comm1,A_MPI_Comm comm2,int * result);
int (*LOCAL_MPI_Comm_compare)(R_MPI_Comm,R_MPI_Comm,int *);

__asm__(
".global PMPI_Comm_compare\n"
".weak MPI_Comm_compare\n"
".set MPI_Comm_compare,PMPI_Comm_compare\n"
".extern in_w\n"
".extern A_MPI_Comm_compare\n"
".extern R_MPI_Comm_compare\n"
".type PMPI_Comm_compare,@function\n"
".text\n"
"PMPI_Comm_compare:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Comm_compare\n"
"jmp *A_MPI_Comm_compare@GOTPCREL(%rip)\n"
"inwrap_MPI_Comm_compare:\n"
"jmp *R_MPI_Comm_compare@GOTPCREL(%rip)\n"
".size PMPI_Comm_compare,.-PMPI_Comm_compare\n"

);

int A_MPI_Comm_compare(A_MPI_Comm comm1,A_MPI_Comm comm2,int * result)
{
#ifdef DEBUG
printf("entre : A_MPI_Comm_compare\n");
#endif
in_w=1;

R_MPI_Comm comm1_tmp;
comm_conv_a2r(&comm1,&comm1_tmp);
R_MPI_Comm comm2_tmp;
comm_conv_a2r(&comm2,&comm2_tmp);

int ret_tmp= LOCAL_MPI_Comm_compare( comm1_tmp, comm2_tmp, result);

in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Comm_compare\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Comm_compare(R_MPI_Comm comm1,R_MPI_Comm comm2,int * result)
{
#ifdef DEBUG
printf("entre : R_MPI_Comm_compare\n");
#endif
int ret_tmp= LOCAL_MPI_Comm_compare( comm1, comm2, result);
#ifdef DEBUG
printf("sort : R_MPI_Comm_compare\n");
#endif
return ret_tmp;
}
int MPI_Comm_dup(A_MPI_Comm comm,A_MPI_Comm * newcomm);
int (*LOCAL_MPI_Comm_dup)(R_MPI_Comm,R_MPI_Comm *);

__asm__(
".global PMPI_Comm_dup\n"
".weak MPI_Comm_dup\n"
".set MPI_Comm_dup,PMPI_Comm_dup\n"
".extern in_w\n"
".extern A_MPI_Comm_dup\n"
".extern R_MPI_Comm_dup\n"
".type PMPI_Comm_dup,@function\n"
".text\n"
"PMPI_Comm_dup:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Comm_dup\n"
"jmp *A_MPI_Comm_dup@GOTPCREL(%rip)\n"
"inwrap_MPI_Comm_dup:\n"
"jmp *R_MPI_Comm_dup@GOTPCREL(%rip)\n"
".size PMPI_Comm_dup,.-PMPI_Comm_dup\n"

);

int A_MPI_Comm_dup(A_MPI_Comm comm,A_MPI_Comm * newcomm)
{
#ifdef DEBUG
printf("entre : A_MPI_Comm_dup\n");
#endif
in_w=1;

R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
R_MPI_Comm  newcomm_ltmp;
R_MPI_Comm * newcomm_tmp=&newcomm_ltmp;
int ret_tmp= LOCAL_MPI_Comm_dup( comm_tmp, newcomm_tmp);
comm_conv_r2a(newcomm,newcomm_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Comm_dup\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Comm_dup(R_MPI_Comm comm,R_MPI_Comm * newcomm)
{
#ifdef DEBUG
printf("entre : R_MPI_Comm_dup\n");
#endif
int ret_tmp= LOCAL_MPI_Comm_dup( comm, newcomm);
#ifdef DEBUG
printf("sort : R_MPI_Comm_dup\n");
#endif
return ret_tmp;
}
int MPI_Comm_create(A_MPI_Comm comm,A_MPI_Group group,A_MPI_Comm * newcomm);
int (*LOCAL_MPI_Comm_create)(R_MPI_Comm,R_MPI_Group,R_MPI_Comm *);

__asm__(
".global PMPI_Comm_create\n"
".weak MPI_Comm_create\n"
".set MPI_Comm_create,PMPI_Comm_create\n"
".extern in_w\n"
".extern A_MPI_Comm_create\n"
".extern R_MPI_Comm_create\n"
".type PMPI_Comm_create,@function\n"
".text\n"
"PMPI_Comm_create:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Comm_create\n"
"jmp *A_MPI_Comm_create@GOTPCREL(%rip)\n"
"inwrap_MPI_Comm_create:\n"
"jmp *R_MPI_Comm_create@GOTPCREL(%rip)\n"
".size PMPI_Comm_create,.-PMPI_Comm_create\n"

);

int A_MPI_Comm_create(A_MPI_Comm comm,A_MPI_Group group,A_MPI_Comm * newcomm)
{
#ifdef DEBUG
printf("entre : A_MPI_Comm_create\n");
#endif
in_w=1;

R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
R_MPI_Group group_tmp;
group_conv_a2r(&group,&group_tmp);
R_MPI_Comm  newcomm_ltmp;
R_MPI_Comm * newcomm_tmp=&newcomm_ltmp;
int ret_tmp= LOCAL_MPI_Comm_create( comm_tmp, group_tmp, newcomm_tmp);
comm_conv_r2a(newcomm,newcomm_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Comm_create\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Comm_create(R_MPI_Comm comm,R_MPI_Group group,R_MPI_Comm * newcomm)
{
#ifdef DEBUG
printf("entre : R_MPI_Comm_create\n");
#endif
int ret_tmp= LOCAL_MPI_Comm_create( comm, group, newcomm);
#ifdef DEBUG
printf("sort : R_MPI_Comm_create\n");
#endif
return ret_tmp;
}
int MPI_Comm_split(A_MPI_Comm comm,int color,int key,A_MPI_Comm * newcomm);
int (*LOCAL_MPI_Comm_split)(R_MPI_Comm,int,int,R_MPI_Comm *);

__asm__(
".global PMPI_Comm_split\n"
".weak MPI_Comm_split\n"
".set MPI_Comm_split,PMPI_Comm_split\n"
".extern in_w\n"
".extern A_MPI_Comm_split\n"
".extern R_MPI_Comm_split\n"
".type PMPI_Comm_split,@function\n"
".text\n"
"PMPI_Comm_split:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Comm_split\n"
"jmp *A_MPI_Comm_split@GOTPCREL(%rip)\n"
"inwrap_MPI_Comm_split:\n"
"jmp *R_MPI_Comm_split@GOTPCREL(%rip)\n"
".size PMPI_Comm_split,.-PMPI_Comm_split\n"

);

int A_MPI_Comm_split(A_MPI_Comm comm,int color,int key,A_MPI_Comm * newcomm)
{
#ifdef DEBUG
printf("entre : A_MPI_Comm_split\n");
#endif
in_w=1;

R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);




R_MPI_Comm  newcomm_ltmp;
R_MPI_Comm * newcomm_tmp=&newcomm_ltmp;
int ret_tmp= LOCAL_MPI_Comm_split( comm_tmp, color, key, newcomm_tmp);
comm_conv_r2a(newcomm,newcomm_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Comm_split\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Comm_split(R_MPI_Comm comm,int color,int key,R_MPI_Comm * newcomm)
{
#ifdef DEBUG
printf("entre : R_MPI_Comm_split\n");
#endif
int ret_tmp= LOCAL_MPI_Comm_split( comm, color, key, newcomm);
#ifdef DEBUG
printf("sort : R_MPI_Comm_split\n");
#endif
return ret_tmp;
}
int MPI_Comm_free(A_MPI_Comm * comm);
int (*LOCAL_MPI_Comm_free)(R_MPI_Comm *);

__asm__(
".global PMPI_Comm_free\n"
".weak MPI_Comm_free\n"
".set MPI_Comm_free,PMPI_Comm_free\n"
".extern in_w\n"
".extern A_MPI_Comm_free\n"
".extern R_MPI_Comm_free\n"
".type PMPI_Comm_free,@function\n"
".text\n"
"PMPI_Comm_free:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Comm_free\n"
"jmp *A_MPI_Comm_free@GOTPCREL(%rip)\n"
"inwrap_MPI_Comm_free:\n"
"jmp *R_MPI_Comm_free@GOTPCREL(%rip)\n"
".size PMPI_Comm_free,.-PMPI_Comm_free\n"

);

int A_MPI_Comm_free(A_MPI_Comm * comm)
{
#ifdef DEBUG
printf("entre : A_MPI_Comm_free\n");
#endif
in_w=1;

R_MPI_Comm  comm_ltmp;
R_MPI_Comm * comm_tmp=&comm_ltmp;
comm_conv_a2r(comm,comm_tmp);
int ret_tmp= LOCAL_MPI_Comm_free( comm_tmp);
if(ret_tmp == R_MPI_SUCCESS){
communicator_translation_del(comm);
comm_conv_r2a(comm,comm_tmp);
}
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Comm_free\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Comm_free(R_MPI_Comm * comm)
{
#ifdef DEBUG
printf("entre : R_MPI_Comm_free\n");
#endif
int ret_tmp= LOCAL_MPI_Comm_free( comm);
#ifdef DEBUG
printf("sort : R_MPI_Comm_free\n");
#endif
return ret_tmp;
}
int MPI_Comm_test_inter(A_MPI_Comm comm,int * flag);
int (*LOCAL_MPI_Comm_test_inter)(R_MPI_Comm,int *);

__asm__(
".global PMPI_Comm_test_inter\n"
".weak MPI_Comm_test_inter\n"
".set MPI_Comm_test_inter,PMPI_Comm_test_inter\n"
".extern in_w\n"
".extern A_MPI_Comm_test_inter\n"
".extern R_MPI_Comm_test_inter\n"
".type PMPI_Comm_test_inter,@function\n"
".text\n"
"PMPI_Comm_test_inter:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Comm_test_inter\n"
"jmp *A_MPI_Comm_test_inter@GOTPCREL(%rip)\n"
"inwrap_MPI_Comm_test_inter:\n"
"jmp *R_MPI_Comm_test_inter@GOTPCREL(%rip)\n"
".size PMPI_Comm_test_inter,.-PMPI_Comm_test_inter\n"

);

int A_MPI_Comm_test_inter(A_MPI_Comm comm,int * flag)
{
#ifdef DEBUG
printf("entre : A_MPI_Comm_test_inter\n");
#endif
in_w=1;

R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);

int ret_tmp= LOCAL_MPI_Comm_test_inter( comm_tmp, flag);

in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Comm_test_inter\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Comm_test_inter(R_MPI_Comm comm,int * flag)
{
#ifdef DEBUG
printf("entre : R_MPI_Comm_test_inter\n");
#endif
int ret_tmp= LOCAL_MPI_Comm_test_inter( comm, flag);
#ifdef DEBUG
printf("sort : R_MPI_Comm_test_inter\n");
#endif
return ret_tmp;
}
int MPI_Comm_remote_size(A_MPI_Comm comm,int * size);
int (*LOCAL_MPI_Comm_remote_size)(R_MPI_Comm,int *);

__asm__(
".global PMPI_Comm_remote_size\n"
".weak MPI_Comm_remote_size\n"
".set MPI_Comm_remote_size,PMPI_Comm_remote_size\n"
".extern in_w\n"
".extern A_MPI_Comm_remote_size\n"
".extern R_MPI_Comm_remote_size\n"
".type PMPI_Comm_remote_size,@function\n"
".text\n"
"PMPI_Comm_remote_size:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Comm_remote_size\n"
"jmp *A_MPI_Comm_remote_size@GOTPCREL(%rip)\n"
"inwrap_MPI_Comm_remote_size:\n"
"jmp *R_MPI_Comm_remote_size@GOTPCREL(%rip)\n"
".size PMPI_Comm_remote_size,.-PMPI_Comm_remote_size\n"

);

int A_MPI_Comm_remote_size(A_MPI_Comm comm,int * size)
{
#ifdef DEBUG
printf("entre : A_MPI_Comm_remote_size\n");
#endif
in_w=1;

R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);

int ret_tmp= LOCAL_MPI_Comm_remote_size( comm_tmp, size);

in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Comm_remote_size\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Comm_remote_size(R_MPI_Comm comm,int * size)
{
#ifdef DEBUG
printf("entre : R_MPI_Comm_remote_size\n");
#endif
int ret_tmp= LOCAL_MPI_Comm_remote_size( comm, size);
#ifdef DEBUG
printf("sort : R_MPI_Comm_remote_size\n");
#endif
return ret_tmp;
}
int MPI_Comm_remote_group(A_MPI_Comm comm,A_MPI_Group * group);
int (*LOCAL_MPI_Comm_remote_group)(R_MPI_Comm,R_MPI_Group *);

__asm__(
".global PMPI_Comm_remote_group\n"
".weak MPI_Comm_remote_group\n"
".set MPI_Comm_remote_group,PMPI_Comm_remote_group\n"
".extern in_w\n"
".extern A_MPI_Comm_remote_group\n"
".extern R_MPI_Comm_remote_group\n"
".type PMPI_Comm_remote_group,@function\n"
".text\n"
"PMPI_Comm_remote_group:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Comm_remote_group\n"
"jmp *A_MPI_Comm_remote_group@GOTPCREL(%rip)\n"
"inwrap_MPI_Comm_remote_group:\n"
"jmp *R_MPI_Comm_remote_group@GOTPCREL(%rip)\n"
".size PMPI_Comm_remote_group,.-PMPI_Comm_remote_group\n"

);

int A_MPI_Comm_remote_group(A_MPI_Comm comm,A_MPI_Group * group)
{
#ifdef DEBUG
printf("entre : A_MPI_Comm_remote_group\n");
#endif
in_w=1;

R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
R_MPI_Group  group_ltmp;
R_MPI_Group * group_tmp=&group_ltmp;
int ret_tmp= LOCAL_MPI_Comm_remote_group( comm_tmp, group_tmp);
group_conv_r2a(group,group_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Comm_remote_group\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Comm_remote_group(R_MPI_Comm comm,R_MPI_Group * group)
{
#ifdef DEBUG
printf("entre : R_MPI_Comm_remote_group\n");
#endif
int ret_tmp= LOCAL_MPI_Comm_remote_group( comm, group);
#ifdef DEBUG
printf("sort : R_MPI_Comm_remote_group\n");
#endif
return ret_tmp;
}
int MPI_Intercomm_create(A_MPI_Comm local_comm,int local_leader,A_MPI_Comm peer_comm,int remote_leader,int tag,A_MPI_Comm * newintercomm);
int (*LOCAL_MPI_Intercomm_create)(R_MPI_Comm,int,R_MPI_Comm,int,int,R_MPI_Comm *);

__asm__(
".global PMPI_Intercomm_create\n"
".weak MPI_Intercomm_create\n"
".set MPI_Intercomm_create,PMPI_Intercomm_create\n"
".extern in_w\n"
".extern A_MPI_Intercomm_create\n"
".extern R_MPI_Intercomm_create\n"
".type PMPI_Intercomm_create,@function\n"
".text\n"
"PMPI_Intercomm_create:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Intercomm_create\n"
"jmp *A_MPI_Intercomm_create@GOTPCREL(%rip)\n"
"inwrap_MPI_Intercomm_create:\n"
"jmp *R_MPI_Intercomm_create@GOTPCREL(%rip)\n"
".size PMPI_Intercomm_create,.-PMPI_Intercomm_create\n"

);

int A_MPI_Intercomm_create(A_MPI_Comm local_comm,int local_leader,A_MPI_Comm peer_comm,int remote_leader,int tag,A_MPI_Comm * newintercomm)
{
#ifdef DEBUG
printf("entre : A_MPI_Intercomm_create\n");
#endif
in_w=1;

R_MPI_Comm local_comm_tmp;
comm_conv_a2r(&local_comm,&local_comm_tmp);


R_MPI_Comm peer_comm_tmp;
comm_conv_a2r(&peer_comm,&peer_comm_tmp);


int tag_tmp;
tag_conv_a2r(&tag,&tag_tmp);
R_MPI_Comm  newintercomm_ltmp;
R_MPI_Comm * newintercomm_tmp=&newintercomm_ltmp;
int ret_tmp= LOCAL_MPI_Intercomm_create( local_comm_tmp, local_leader, peer_comm_tmp, remote_leader, tag_tmp, newintercomm_tmp);
comm_conv_r2a(newintercomm,newintercomm_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Intercomm_create\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Intercomm_create(R_MPI_Comm local_comm,int local_leader,R_MPI_Comm peer_comm,int remote_leader,int tag,R_MPI_Comm * newintercomm)
{
#ifdef DEBUG
printf("entre : R_MPI_Intercomm_create\n");
#endif
int ret_tmp= LOCAL_MPI_Intercomm_create( local_comm, local_leader, peer_comm, remote_leader, tag, newintercomm);
#ifdef DEBUG
printf("sort : R_MPI_Intercomm_create\n");
#endif
return ret_tmp;
}
int MPI_Intercomm_merge(A_MPI_Comm intercomm,int high,A_MPI_Comm * newintracomm);
int (*LOCAL_MPI_Intercomm_merge)(R_MPI_Comm,int,R_MPI_Comm *);

__asm__(
".global PMPI_Intercomm_merge\n"
".weak MPI_Intercomm_merge\n"
".set MPI_Intercomm_merge,PMPI_Intercomm_merge\n"
".extern in_w\n"
".extern A_MPI_Intercomm_merge\n"
".extern R_MPI_Intercomm_merge\n"
".type PMPI_Intercomm_merge,@function\n"
".text\n"
"PMPI_Intercomm_merge:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Intercomm_merge\n"
"jmp *A_MPI_Intercomm_merge@GOTPCREL(%rip)\n"
"inwrap_MPI_Intercomm_merge:\n"
"jmp *R_MPI_Intercomm_merge@GOTPCREL(%rip)\n"
".size PMPI_Intercomm_merge,.-PMPI_Intercomm_merge\n"

);

int A_MPI_Intercomm_merge(A_MPI_Comm intercomm,int high,A_MPI_Comm * newintracomm)
{
#ifdef DEBUG
printf("entre : A_MPI_Intercomm_merge\n");
#endif
in_w=1;

R_MPI_Comm intercomm_tmp;
comm_conv_a2r(&intercomm,&intercomm_tmp);


R_MPI_Comm  newintracomm_ltmp;
R_MPI_Comm * newintracomm_tmp=&newintracomm_ltmp;
int ret_tmp= LOCAL_MPI_Intercomm_merge( intercomm_tmp, high, newintracomm_tmp);
comm_conv_r2a(newintracomm,newintracomm_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Intercomm_merge\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Intercomm_merge(R_MPI_Comm intercomm,int high,R_MPI_Comm * newintracomm)
{
#ifdef DEBUG
printf("entre : R_MPI_Intercomm_merge\n");
#endif
int ret_tmp= LOCAL_MPI_Intercomm_merge( intercomm, high, newintracomm);
#ifdef DEBUG
printf("sort : R_MPI_Intercomm_merge\n");
#endif
return ret_tmp;
}
int MPI_Attr_put(A_MPI_Comm comm,int keyval,void * attribute_val);
int (*LOCAL_MPI_Attr_put)(R_MPI_Comm,int,void *);

__asm__(
".global PMPI_Attr_put\n"
".weak MPI_Attr_put\n"
".set MPI_Attr_put,PMPI_Attr_put\n"
".extern in_w\n"
".extern A_MPI_Attr_put\n"
".extern R_MPI_Attr_put\n"
".type PMPI_Attr_put,@function\n"
".text\n"
"PMPI_Attr_put:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Attr_put\n"
"jmp *A_MPI_Attr_put@GOTPCREL(%rip)\n"
"inwrap_MPI_Attr_put:\n"
"jmp *R_MPI_Attr_put@GOTPCREL(%rip)\n"
".size PMPI_Attr_put,.-PMPI_Attr_put\n"

);

int A_MPI_Attr_put(A_MPI_Comm comm,int keyval,void * attribute_val)
{
#ifdef DEBUG
printf("entre : A_MPI_Attr_put\n");
#endif
in_w=1;

R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);




int ret_tmp= LOCAL_MPI_Attr_put( comm_tmp, keyval, attribute_val);
comm_conv_r2a(&comm,&comm_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Attr_put\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Attr_put(R_MPI_Comm comm,int keyval,void * attribute_val)
{
#ifdef DEBUG
printf("entre : R_MPI_Attr_put\n");
#endif
int ret_tmp= LOCAL_MPI_Attr_put( comm, keyval, attribute_val);
#ifdef DEBUG
printf("sort : R_MPI_Attr_put\n");
#endif
return ret_tmp;
}
int MPI_Attr_get(A_MPI_Comm comm,int keyval,void * attribute_val,int * flag);
int (*LOCAL_MPI_Attr_get)(R_MPI_Comm,int,void *,int *);

__asm__(
".global PMPI_Attr_get\n"
".weak MPI_Attr_get\n"
".set MPI_Attr_get,PMPI_Attr_get\n"
".extern in_w\n"
".extern A_MPI_Attr_get\n"
".extern R_MPI_Attr_get\n"
".type PMPI_Attr_get,@function\n"
".text\n"
"PMPI_Attr_get:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Attr_get\n"
"jmp *A_MPI_Attr_get@GOTPCREL(%rip)\n"
"inwrap_MPI_Attr_get:\n"
"jmp *R_MPI_Attr_get@GOTPCREL(%rip)\n"
".size PMPI_Attr_get,.-PMPI_Attr_get\n"

);

int A_MPI_Attr_get(A_MPI_Comm comm,int keyval,void * attribute_val,int * flag)
{
#ifdef DEBUG
printf("entre : A_MPI_Attr_get\n");
#endif
in_w=1;

R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);




int ret_tmp= LOCAL_MPI_Attr_get( comm_tmp, keyval, attribute_val, flag);


in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Attr_get\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Attr_get(R_MPI_Comm comm,int keyval,void * attribute_val,int * flag)
{
#ifdef DEBUG
printf("entre : R_MPI_Attr_get\n");
#endif
int ret_tmp= LOCAL_MPI_Attr_get( comm, keyval, attribute_val, flag);
#ifdef DEBUG
printf("sort : R_MPI_Attr_get\n");
#endif
return ret_tmp;
}
int MPI_Attr_delete(A_MPI_Comm comm,int keyval);
int (*LOCAL_MPI_Attr_delete)(R_MPI_Comm,int);

__asm__(
".global PMPI_Attr_delete\n"
".weak MPI_Attr_delete\n"
".set MPI_Attr_delete,PMPI_Attr_delete\n"
".extern in_w\n"
".extern A_MPI_Attr_delete\n"
".extern R_MPI_Attr_delete\n"
".type PMPI_Attr_delete,@function\n"
".text\n"
"PMPI_Attr_delete:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Attr_delete\n"
"jmp *A_MPI_Attr_delete@GOTPCREL(%rip)\n"
"inwrap_MPI_Attr_delete:\n"
"jmp *R_MPI_Attr_delete@GOTPCREL(%rip)\n"
".size PMPI_Attr_delete,.-PMPI_Attr_delete\n"

);

int A_MPI_Attr_delete(A_MPI_Comm comm,int keyval)
{
#ifdef DEBUG
printf("entre : A_MPI_Attr_delete\n");
#endif
in_w=1;

R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);


int ret_tmp= LOCAL_MPI_Attr_delete( comm_tmp, keyval);
comm_conv_r2a(&comm,&comm_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Attr_delete\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Attr_delete(R_MPI_Comm comm,int keyval)
{
#ifdef DEBUG
printf("entre : R_MPI_Attr_delete\n");
#endif
int ret_tmp= LOCAL_MPI_Attr_delete( comm, keyval);
#ifdef DEBUG
printf("sort : R_MPI_Attr_delete\n");
#endif
return ret_tmp;
}
int MPI_Topo_test(A_MPI_Comm comm,int * status);
int (*LOCAL_MPI_Topo_test)(R_MPI_Comm,int *);

__asm__(
".global PMPI_Topo_test\n"
".weak MPI_Topo_test\n"
".set MPI_Topo_test,PMPI_Topo_test\n"
".extern in_w\n"
".extern A_MPI_Topo_test\n"
".extern R_MPI_Topo_test\n"
".type PMPI_Topo_test,@function\n"
".text\n"
"PMPI_Topo_test:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Topo_test\n"
"jmp *A_MPI_Topo_test@GOTPCREL(%rip)\n"
"inwrap_MPI_Topo_test:\n"
"jmp *R_MPI_Topo_test@GOTPCREL(%rip)\n"
".size PMPI_Topo_test,.-PMPI_Topo_test\n"

);

int A_MPI_Topo_test(A_MPI_Comm comm,int * status)
{
#ifdef DEBUG
printf("entre : A_MPI_Topo_test\n");
#endif
in_w=1;

R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
int  status_ltmp;
int * status_tmp=&status_ltmp;
int ret_tmp= LOCAL_MPI_Topo_test( comm_tmp, status_tmp);
topo_status_mapper(status,status_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Topo_test\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Topo_test(R_MPI_Comm comm,int * status)
{
#ifdef DEBUG
printf("entre : R_MPI_Topo_test\n");
#endif
int ret_tmp= LOCAL_MPI_Topo_test( comm, status);
#ifdef DEBUG
printf("sort : R_MPI_Topo_test\n");
#endif
return ret_tmp;
}
int MPI_Graphdims_get(A_MPI_Comm comm,int * nnodes,int * nedges);
int (*LOCAL_MPI_Graphdims_get)(R_MPI_Comm,int *,int *);

__asm__(
".global PMPI_Graphdims_get\n"
".weak MPI_Graphdims_get\n"
".set MPI_Graphdims_get,PMPI_Graphdims_get\n"
".extern in_w\n"
".extern A_MPI_Graphdims_get\n"
".extern R_MPI_Graphdims_get\n"
".type PMPI_Graphdims_get,@function\n"
".text\n"
"PMPI_Graphdims_get:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Graphdims_get\n"
"jmp *A_MPI_Graphdims_get@GOTPCREL(%rip)\n"
"inwrap_MPI_Graphdims_get:\n"
"jmp *R_MPI_Graphdims_get@GOTPCREL(%rip)\n"
".size PMPI_Graphdims_get,.-PMPI_Graphdims_get\n"

);

int A_MPI_Graphdims_get(A_MPI_Comm comm,int * nnodes,int * nedges)
{
#ifdef DEBUG
printf("entre : A_MPI_Graphdims_get\n");
#endif
in_w=1;

R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);


int ret_tmp= LOCAL_MPI_Graphdims_get( comm_tmp, nnodes, nedges);


in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Graphdims_get\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Graphdims_get(R_MPI_Comm comm,int * nnodes,int * nedges)
{
#ifdef DEBUG
printf("entre : R_MPI_Graphdims_get\n");
#endif
int ret_tmp= LOCAL_MPI_Graphdims_get( comm, nnodes, nedges);
#ifdef DEBUG
printf("sort : R_MPI_Graphdims_get\n");
#endif
return ret_tmp;
}
int MPI_Cartdim_get(A_MPI_Comm comm,int * ndims);
int (*LOCAL_MPI_Cartdim_get)(R_MPI_Comm,int *);

__asm__(
".global PMPI_Cartdim_get\n"
".weak MPI_Cartdim_get\n"
".set MPI_Cartdim_get,PMPI_Cartdim_get\n"
".extern in_w\n"
".extern A_MPI_Cartdim_get\n"
".extern R_MPI_Cartdim_get\n"
".type PMPI_Cartdim_get,@function\n"
".text\n"
"PMPI_Cartdim_get:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Cartdim_get\n"
"jmp *A_MPI_Cartdim_get@GOTPCREL(%rip)\n"
"inwrap_MPI_Cartdim_get:\n"
"jmp *R_MPI_Cartdim_get@GOTPCREL(%rip)\n"
".size PMPI_Cartdim_get,.-PMPI_Cartdim_get\n"

);

int A_MPI_Cartdim_get(A_MPI_Comm comm,int * ndims)
{
#ifdef DEBUG
printf("entre : A_MPI_Cartdim_get\n");
#endif
in_w=1;

R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);

int ret_tmp= LOCAL_MPI_Cartdim_get( comm_tmp, ndims);

in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Cartdim_get\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Cartdim_get(R_MPI_Comm comm,int * ndims)
{
#ifdef DEBUG
printf("entre : R_MPI_Cartdim_get\n");
#endif
int ret_tmp= LOCAL_MPI_Cartdim_get( comm, ndims);
#ifdef DEBUG
printf("sort : R_MPI_Cartdim_get\n");
#endif
return ret_tmp;
}
int MPI_Graph_neighbors_count(A_MPI_Comm comm,int rank,int * nneighbors);
int (*LOCAL_MPI_Graph_neighbors_count)(R_MPI_Comm,int,int *);

__asm__(
".global PMPI_Graph_neighbors_count\n"
".weak MPI_Graph_neighbors_count\n"
".set MPI_Graph_neighbors_count,PMPI_Graph_neighbors_count\n"
".extern in_w\n"
".extern A_MPI_Graph_neighbors_count\n"
".extern R_MPI_Graph_neighbors_count\n"
".type PMPI_Graph_neighbors_count,@function\n"
".text\n"
"PMPI_Graph_neighbors_count:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Graph_neighbors_count\n"
"jmp *A_MPI_Graph_neighbors_count@GOTPCREL(%rip)\n"
"inwrap_MPI_Graph_neighbors_count:\n"
"jmp *R_MPI_Graph_neighbors_count@GOTPCREL(%rip)\n"
".size PMPI_Graph_neighbors_count,.-PMPI_Graph_neighbors_count\n"

);

int A_MPI_Graph_neighbors_count(A_MPI_Comm comm,int rank,int * nneighbors)
{
#ifdef DEBUG
printf("entre : A_MPI_Graph_neighbors_count\n");
#endif
in_w=1;

R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);



int ret_tmp= LOCAL_MPI_Graph_neighbors_count( comm_tmp, rank, nneighbors);

in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Graph_neighbors_count\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Graph_neighbors_count(R_MPI_Comm comm,int rank,int * nneighbors)
{
#ifdef DEBUG
printf("entre : R_MPI_Graph_neighbors_count\n");
#endif
int ret_tmp= LOCAL_MPI_Graph_neighbors_count( comm, rank, nneighbors);
#ifdef DEBUG
printf("sort : R_MPI_Graph_neighbors_count\n");
#endif
return ret_tmp;
}
int MPI_Cart_shift(A_MPI_Comm comm,int direction,int disp,int * rank_source,int * rank_dest);
int (*LOCAL_MPI_Cart_shift)(R_MPI_Comm,int,int,int *,int *);

__asm__(
".global PMPI_Cart_shift\n"
".weak MPI_Cart_shift\n"
".set MPI_Cart_shift,PMPI_Cart_shift\n"
".extern in_w\n"
".extern A_MPI_Cart_shift\n"
".extern R_MPI_Cart_shift\n"
".type PMPI_Cart_shift,@function\n"
".text\n"
"PMPI_Cart_shift:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Cart_shift\n"
"jmp *A_MPI_Cart_shift@GOTPCREL(%rip)\n"
"inwrap_MPI_Cart_shift:\n"
"jmp *R_MPI_Cart_shift@GOTPCREL(%rip)\n"
".size PMPI_Cart_shift,.-PMPI_Cart_shift\n"

);

int A_MPI_Cart_shift(A_MPI_Comm comm,int direction,int disp,int * rank_source,int * rank_dest)
{
#ifdef DEBUG
printf("entre : A_MPI_Cart_shift\n");
#endif
in_w=1;

R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);




int  rank_source_ltmp;
int * rank_source_tmp=&rank_source_ltmp;

int ret_tmp= LOCAL_MPI_Cart_shift( comm_tmp, direction, disp, rank_source_tmp, rank_dest);
source_conv_r2a(rank_source,rank_source_tmp);

in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Cart_shift\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Cart_shift(R_MPI_Comm comm,int direction,int disp,int * rank_source,int * rank_dest)
{
#ifdef DEBUG
printf("entre : R_MPI_Cart_shift\n");
#endif
int ret_tmp= LOCAL_MPI_Cart_shift( comm, direction, disp, rank_source, rank_dest);
#ifdef DEBUG
printf("sort : R_MPI_Cart_shift\n");
#endif
return ret_tmp;
}
int MPI_Get_processor_name(char * name,int * resultlen);
int (*LOCAL_MPI_Get_processor_name)(char *,int *);

__asm__(
".global PMPI_Get_processor_name\n"
".weak MPI_Get_processor_name\n"
".set MPI_Get_processor_name,PMPI_Get_processor_name\n"
".extern in_w\n"
".extern A_MPI_Get_processor_name\n"
".extern R_MPI_Get_processor_name\n"
".type PMPI_Get_processor_name,@function\n"
".text\n"
"PMPI_Get_processor_name:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Get_processor_name\n"
"jmp *A_MPI_Get_processor_name@GOTPCREL(%rip)\n"
"inwrap_MPI_Get_processor_name:\n"
"jmp *R_MPI_Get_processor_name@GOTPCREL(%rip)\n"
".size PMPI_Get_processor_name,.-PMPI_Get_processor_name\n"

);

int A_MPI_Get_processor_name(char * name,int * resultlen)
{
#ifdef DEBUG
printf("entre : A_MPI_Get_processor_name\n");
#endif
in_w=1;



int ret_tmp= LOCAL_MPI_Get_processor_name( name, resultlen);


in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Get_processor_name\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Get_processor_name(char * name,int * resultlen)
{
#ifdef DEBUG
printf("entre : R_MPI_Get_processor_name\n");
#endif
int ret_tmp= LOCAL_MPI_Get_processor_name( name, resultlen);
#ifdef DEBUG
printf("sort : R_MPI_Get_processor_name\n");
#endif
return ret_tmp;
}
int MPI_Get_version(int * version,int * subversion);
int (*LOCAL_MPI_Get_version)(int *,int *);

__asm__(
".global PMPI_Get_version\n"
".weak MPI_Get_version\n"
".set MPI_Get_version,PMPI_Get_version\n"
".extern in_w\n"
".extern A_MPI_Get_version\n"
".extern R_MPI_Get_version\n"
".type PMPI_Get_version,@function\n"
".text\n"
"PMPI_Get_version:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Get_version\n"
"jmp *A_MPI_Get_version@GOTPCREL(%rip)\n"
"inwrap_MPI_Get_version:\n"
"jmp *R_MPI_Get_version@GOTPCREL(%rip)\n"
".size PMPI_Get_version,.-PMPI_Get_version\n"

);

int A_MPI_Get_version(int * version,int * subversion)
{
#ifdef DEBUG
printf("entre : A_MPI_Get_version\n");
#endif
in_w=1;



int ret_tmp= LOCAL_MPI_Get_version( version, subversion);


in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Get_version\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Get_version(int * version,int * subversion)
{
#ifdef DEBUG
printf("entre : R_MPI_Get_version\n");
#endif
int ret_tmp= LOCAL_MPI_Get_version( version, subversion);
#ifdef DEBUG
printf("sort : R_MPI_Get_version\n");
#endif
return ret_tmp;
}
int MPI_Errhandler_create(A_MPI_Handler_function * function,A_MPI_Errhandler * errhandler);
int (*LOCAL_MPI_Errhandler_create)(R_MPI_Handler_function *,R_MPI_Errhandler *);

__asm__(
".global PMPI_Errhandler_create\n"
".weak MPI_Errhandler_create\n"
".set MPI_Errhandler_create,PMPI_Errhandler_create\n"
".extern in_w\n"
".extern A_MPI_Errhandler_create\n"
".extern R_MPI_Errhandler_create\n"
".type PMPI_Errhandler_create,@function\n"
".text\n"
"PMPI_Errhandler_create:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Errhandler_create\n"
"jmp *A_MPI_Errhandler_create@GOTPCREL(%rip)\n"
"inwrap_MPI_Errhandler_create:\n"
"jmp *R_MPI_Errhandler_create@GOTPCREL(%rip)\n"
".size PMPI_Errhandler_create,.-PMPI_Errhandler_create\n"

);

int A_MPI_Errhandler_create(A_MPI_Handler_function * function,A_MPI_Errhandler * errhandler)
{
#ifdef DEBUG
printf("entre : A_MPI_Errhandler_create\n");
#endif
in_w=1;


ptr_handler_fn=(A_MPI_Handler_function *)function;
R_MPI_Errhandler  errhandler_ltmp;
R_MPI_Errhandler * errhandler_tmp=&errhandler_ltmp;
int ret_tmp= LOCAL_MPI_Errhandler_create( (R_MPI_Handler_function *)wrapper_handler_function, errhandler_tmp);
errhandler_ptr_conv_r2a(&errhandler,&errhandler_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Errhandler_create\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Errhandler_create(R_MPI_Handler_function * function,R_MPI_Errhandler * errhandler)
{
#ifdef DEBUG
printf("entre : R_MPI_Errhandler_create\n");
#endif
int ret_tmp= LOCAL_MPI_Errhandler_create( function, errhandler);
#ifdef DEBUG
printf("sort : R_MPI_Errhandler_create\n");
#endif
return ret_tmp;
}
int MPI_Errhandler_set(A_MPI_Comm comm,A_MPI_Errhandler errhandler);
int (*LOCAL_MPI_Errhandler_set)(R_MPI_Comm,R_MPI_Errhandler);

__asm__(
".global PMPI_Errhandler_set\n"
".weak MPI_Errhandler_set\n"
".set MPI_Errhandler_set,PMPI_Errhandler_set\n"
".extern in_w\n"
".extern A_MPI_Errhandler_set\n"
".extern R_MPI_Errhandler_set\n"
".type PMPI_Errhandler_set,@function\n"
".text\n"
"PMPI_Errhandler_set:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Errhandler_set\n"
"jmp *A_MPI_Errhandler_set@GOTPCREL(%rip)\n"
"inwrap_MPI_Errhandler_set:\n"
"jmp *R_MPI_Errhandler_set@GOTPCREL(%rip)\n"
".size PMPI_Errhandler_set,.-PMPI_Errhandler_set\n"

);

int A_MPI_Errhandler_set(A_MPI_Comm comm,A_MPI_Errhandler errhandler)
{
#ifdef DEBUG
printf("entre : A_MPI_Errhandler_set\n");
#endif
in_w=1;

R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
R_MPI_Errhandler errhandler_tmp;
errhandler_conv_a2r(&errhandler,&errhandler_tmp);
int ret_tmp= LOCAL_MPI_Errhandler_set( comm_tmp, errhandler_tmp);
if(!errhandler_translation_is_const(errhandler)){
A_MPI_Handler_function* ptr_errhandler_func;
errhandler_fn_translation_get(errhandler, &ptr_errhandler_func);
communicator_fn_translation_update(comm, ptr_errhandler_func);
}
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Errhandler_set\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Errhandler_set(R_MPI_Comm comm,R_MPI_Errhandler errhandler)
{
#ifdef DEBUG
printf("entre : R_MPI_Errhandler_set\n");
#endif
int ret_tmp= LOCAL_MPI_Errhandler_set( comm, errhandler);
#ifdef DEBUG
printf("sort : R_MPI_Errhandler_set\n");
#endif
return ret_tmp;
}
int MPI_Errhandler_get(A_MPI_Comm comm,A_MPI_Errhandler * errhandler);
int (*LOCAL_MPI_Errhandler_get)(R_MPI_Comm,R_MPI_Errhandler *);

__asm__(
".global PMPI_Errhandler_get\n"
".weak MPI_Errhandler_get\n"
".set MPI_Errhandler_get,PMPI_Errhandler_get\n"
".extern in_w\n"
".extern A_MPI_Errhandler_get\n"
".extern R_MPI_Errhandler_get\n"
".type PMPI_Errhandler_get,@function\n"
".text\n"
"PMPI_Errhandler_get:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Errhandler_get\n"
"jmp *A_MPI_Errhandler_get@GOTPCREL(%rip)\n"
"inwrap_MPI_Errhandler_get:\n"
"jmp *R_MPI_Errhandler_get@GOTPCREL(%rip)\n"
".size PMPI_Errhandler_get,.-PMPI_Errhandler_get\n"

);

int A_MPI_Errhandler_get(A_MPI_Comm comm,A_MPI_Errhandler * errhandler)
{
#ifdef DEBUG
printf("entre : A_MPI_Errhandler_get\n");
#endif
in_w=1;

R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
R_MPI_Errhandler  errhandler_ltmp;
R_MPI_Errhandler * errhandler_tmp=&errhandler_ltmp;
int ret_tmp= LOCAL_MPI_Errhandler_get( comm_tmp, errhandler_tmp);
if(ret_tmp == R_MPI_SUCCESS){
A_MPI_Handler_function* ptr_err_handler_func;
communicator_fn_translation_get(comm, &ptr_err_handler_func);
errhandler_fn_translation_update(*errhandler, ptr_err_handler_func);
}
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Errhandler_get\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Errhandler_get(R_MPI_Comm comm,R_MPI_Errhandler * errhandler)
{
#ifdef DEBUG
printf("entre : R_MPI_Errhandler_get\n");
#endif
int ret_tmp= LOCAL_MPI_Errhandler_get( comm, errhandler);
#ifdef DEBUG
printf("sort : R_MPI_Errhandler_get\n");
#endif
return ret_tmp;
}
int MPI_Errhandler_free(A_MPI_Errhandler * errhandler);
int (*LOCAL_MPI_Errhandler_free)(R_MPI_Errhandler *);

__asm__(
".global PMPI_Errhandler_free\n"
".weak MPI_Errhandler_free\n"
".set MPI_Errhandler_free,PMPI_Errhandler_free\n"
".extern in_w\n"
".extern A_MPI_Errhandler_free\n"
".extern R_MPI_Errhandler_free\n"
".type PMPI_Errhandler_free,@function\n"
".text\n"
"PMPI_Errhandler_free:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Errhandler_free\n"
"jmp *A_MPI_Errhandler_free@GOTPCREL(%rip)\n"
"inwrap_MPI_Errhandler_free:\n"
"jmp *R_MPI_Errhandler_free@GOTPCREL(%rip)\n"
".size PMPI_Errhandler_free,.-PMPI_Errhandler_free\n"

);

int A_MPI_Errhandler_free(A_MPI_Errhandler * errhandler)
{
#ifdef DEBUG
printf("entre : A_MPI_Errhandler_free\n");
#endif
in_w=1;

R_MPI_Errhandler  errhandler_ltmp;
R_MPI_Errhandler * errhandler_tmp=&errhandler_ltmp;
errhandler_conv_a2r(errhandler,errhandler_tmp);
int ret_tmp= LOCAL_MPI_Errhandler_free( errhandler_tmp);
if(ret_tmp == R_MPI_SUCCESS){
errhandler_del(errhandler,errhandler_tmp);
}
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Errhandler_free\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Errhandler_free(R_MPI_Errhandler * errhandler)
{
#ifdef DEBUG
printf("entre : R_MPI_Errhandler_free\n");
#endif
int ret_tmp= LOCAL_MPI_Errhandler_free( errhandler);
#ifdef DEBUG
printf("sort : R_MPI_Errhandler_free\n");
#endif
return ret_tmp;
}
int MPI_Error_string(int errorcode,char * string,int * resultlen);
int (*LOCAL_MPI_Error_string)(int,char *,int *);

__asm__(
".global PMPI_Error_string\n"
".weak MPI_Error_string\n"
".set MPI_Error_string,PMPI_Error_string\n"
".extern in_w\n"
".extern A_MPI_Error_string\n"
".extern R_MPI_Error_string\n"
".type PMPI_Error_string,@function\n"
".text\n"
"PMPI_Error_string:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Error_string\n"
"jmp *A_MPI_Error_string@GOTPCREL(%rip)\n"
"inwrap_MPI_Error_string:\n"
"jmp *R_MPI_Error_string@GOTPCREL(%rip)\n"
".size PMPI_Error_string,.-PMPI_Error_string\n"

);

int A_MPI_Error_string(int errorcode,char * string,int * resultlen)
{
#ifdef DEBUG
printf("entre : A_MPI_Error_string\n");
#endif
in_w=1;





int ret_tmp= LOCAL_MPI_Error_string( errorcode, string, resultlen);


in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Error_string\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Error_string(int errorcode,char * string,int * resultlen)
{
#ifdef DEBUG
printf("entre : R_MPI_Error_string\n");
#endif
int ret_tmp= LOCAL_MPI_Error_string( errorcode, string, resultlen);
#ifdef DEBUG
printf("sort : R_MPI_Error_string\n");
#endif
return ret_tmp;
}
int MPI_Error_class(int errorcode,int * errorclass);
int (*LOCAL_MPI_Error_class)(int,int *);

__asm__(
".global PMPI_Error_class\n"
".weak MPI_Error_class\n"
".set MPI_Error_class,PMPI_Error_class\n"
".extern in_w\n"
".extern A_MPI_Error_class\n"
".extern R_MPI_Error_class\n"
".type PMPI_Error_class,@function\n"
".text\n"
"PMPI_Error_class:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Error_class\n"
"jmp *A_MPI_Error_class@GOTPCREL(%rip)\n"
"inwrap_MPI_Error_class:\n"
"jmp *R_MPI_Error_class@GOTPCREL(%rip)\n"
".size PMPI_Error_class,.-PMPI_Error_class\n"

);

int A_MPI_Error_class(int errorcode,int * errorclass)
{
#ifdef DEBUG
printf("entre : A_MPI_Error_class\n");
#endif
in_w=1;




int ret_tmp= LOCAL_MPI_Error_class( errorcode, errorclass);
*errorclass = error_code_conv_r2a(*errorclass);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Error_class\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Error_class(int errorcode,int * errorclass)
{
#ifdef DEBUG
printf("entre : R_MPI_Error_class\n");
#endif
int ret_tmp= LOCAL_MPI_Error_class( errorcode, errorclass);
#ifdef DEBUG
printf("sort : R_MPI_Error_class\n");
#endif
return ret_tmp;
}
int MPI_Initialized(int * flag);
int (*LOCAL_MPI_Initialized)(int *);

__asm__(
".global PMPI_Initialized\n"
".weak MPI_Initialized\n"
".set MPI_Initialized,PMPI_Initialized\n"
".extern in_w\n"
".extern A_MPI_Initialized\n"
".extern R_MPI_Initialized\n"
".type PMPI_Initialized,@function\n"
".text\n"
"PMPI_Initialized:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Initialized\n"
"jmp *A_MPI_Initialized@GOTPCREL(%rip)\n"
"inwrap_MPI_Initialized:\n"
"jmp *R_MPI_Initialized@GOTPCREL(%rip)\n"
".size PMPI_Initialized,.-PMPI_Initialized\n"

);

int A_MPI_Initialized(int * flag)
{
#ifdef DEBUG
printf("entre : A_MPI_Initialized\n");
#endif
in_w=1;


int ret_tmp= LOCAL_MPI_Initialized( flag);

in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Initialized\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Initialized(int * flag)
{
#ifdef DEBUG
printf("entre : R_MPI_Initialized\n");
#endif
int ret_tmp= LOCAL_MPI_Initialized( flag);
#ifdef DEBUG
printf("sort : R_MPI_Initialized\n");
#endif
return ret_tmp;
}
int MPI_Abort(A_MPI_Comm comm,int errorcode);
int (*LOCAL_MPI_Abort)(R_MPI_Comm,int);

__asm__(
".global PMPI_Abort\n"
".weak MPI_Abort\n"
".set MPI_Abort,PMPI_Abort\n"
".extern in_w\n"
".extern A_MPI_Abort\n"
".extern R_MPI_Abort\n"
".type PMPI_Abort,@function\n"
".text\n"
"PMPI_Abort:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Abort\n"
"jmp *A_MPI_Abort@GOTPCREL(%rip)\n"
"inwrap_MPI_Abort:\n"
"jmp *R_MPI_Abort@GOTPCREL(%rip)\n"
".size PMPI_Abort,.-PMPI_Abort\n"

);

int A_MPI_Abort(A_MPI_Comm comm,int errorcode)
{
#ifdef DEBUG
printf("entre : A_MPI_Abort\n");
#endif
in_w=1;

R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);


int ret_tmp= LOCAL_MPI_Abort( comm_tmp, errorcode);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Abort\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Abort(R_MPI_Comm comm,int errorcode)
{
#ifdef DEBUG
printf("entre : R_MPI_Abort\n");
#endif
int ret_tmp= LOCAL_MPI_Abort( comm, errorcode);
#ifdef DEBUG
printf("sort : R_MPI_Abort\n");
#endif
return ret_tmp;
}
int MPI_Init(int * argc,char *** argv);
int (*LOCAL_MPI_Init)(int *,char ***);

__asm__(
".global PMPI_Init\n"
".weak MPI_Init\n"
".set MPI_Init,PMPI_Init\n"
".extern in_w\n"
".extern A_MPI_Init\n"
".extern R_MPI_Init\n"
".type PMPI_Init,@function\n"
".text\n"
"PMPI_Init:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Init\n"
"jmp *A_MPI_Init@GOTPCREL(%rip)\n"
"inwrap_MPI_Init:\n"
"jmp *R_MPI_Init@GOTPCREL(%rip)\n"
".size PMPI_Init,.-PMPI_Init\n"

);

int A_MPI_Init(int * argc,char *** argv)
{
#ifdef DEBUG
printf("entre : A_MPI_Init\n");
#endif
in_w=1;





int ret_tmp= LOCAL_MPI_Init( argc, argv);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Init\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Init(int * argc,char *** argv)
{
#ifdef DEBUG
printf("entre : R_MPI_Init\n");
#endif
int ret_tmp= LOCAL_MPI_Init( argc, argv);
#ifdef DEBUG
printf("sort : R_MPI_Init\n");
#endif
return ret_tmp;
}
int MPI_Comm_delete_attr(A_MPI_Comm comm,int comm_keyval);
int (*LOCAL_MPI_Comm_delete_attr)(R_MPI_Comm,int);

__asm__(
".global PMPI_Comm_delete_attr\n"
".weak MPI_Comm_delete_attr\n"
".set MPI_Comm_delete_attr,PMPI_Comm_delete_attr\n"
".extern in_w\n"
".extern A_MPI_Comm_delete_attr\n"
".extern R_MPI_Comm_delete_attr\n"
".type PMPI_Comm_delete_attr,@function\n"
".text\n"
"PMPI_Comm_delete_attr:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Comm_delete_attr\n"
"jmp *A_MPI_Comm_delete_attr@GOTPCREL(%rip)\n"
"inwrap_MPI_Comm_delete_attr:\n"
"jmp *R_MPI_Comm_delete_attr@GOTPCREL(%rip)\n"
".size PMPI_Comm_delete_attr,.-PMPI_Comm_delete_attr\n"

);

int A_MPI_Comm_delete_attr(A_MPI_Comm comm,int comm_keyval)
{
#ifdef DEBUG
printf("entre : A_MPI_Comm_delete_attr\n");
#endif
in_w=1;

R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);


int ret_tmp= LOCAL_MPI_Comm_delete_attr( comm_tmp, comm_keyval);
comm_conv_r2a(&comm,&comm_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Comm_delete_attr\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Comm_delete_attr(R_MPI_Comm comm,int comm_keyval)
{
#ifdef DEBUG
printf("entre : R_MPI_Comm_delete_attr\n");
#endif
int ret_tmp= LOCAL_MPI_Comm_delete_attr( comm, comm_keyval);
#ifdef DEBUG
printf("sort : R_MPI_Comm_delete_attr\n");
#endif
return ret_tmp;
}
int MPI_Comm_get_attr(A_MPI_Comm comm,int comm_keyval,void * attribute_val,int * flag);
int (*LOCAL_MPI_Comm_get_attr)(R_MPI_Comm,int,void *,int *);

__asm__(
".global PMPI_Comm_get_attr\n"
".weak MPI_Comm_get_attr\n"
".set MPI_Comm_get_attr,PMPI_Comm_get_attr\n"
".extern in_w\n"
".extern A_MPI_Comm_get_attr\n"
".extern R_MPI_Comm_get_attr\n"
".type PMPI_Comm_get_attr,@function\n"
".text\n"
"PMPI_Comm_get_attr:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Comm_get_attr\n"
"jmp *A_MPI_Comm_get_attr@GOTPCREL(%rip)\n"
"inwrap_MPI_Comm_get_attr:\n"
"jmp *R_MPI_Comm_get_attr@GOTPCREL(%rip)\n"
".size PMPI_Comm_get_attr,.-PMPI_Comm_get_attr\n"

);

int A_MPI_Comm_get_attr(A_MPI_Comm comm,int comm_keyval,void * attribute_val,int * flag)
{
#ifdef DEBUG
printf("entre : A_MPI_Comm_get_attr\n");
#endif
in_w=1;

R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);




int ret_tmp= LOCAL_MPI_Comm_get_attr( comm_tmp, comm_keyval, attribute_val, flag);


in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Comm_get_attr\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Comm_get_attr(R_MPI_Comm comm,int comm_keyval,void * attribute_val,int * flag)
{
#ifdef DEBUG
printf("entre : R_MPI_Comm_get_attr\n");
#endif
int ret_tmp= LOCAL_MPI_Comm_get_attr( comm, comm_keyval, attribute_val, flag);
#ifdef DEBUG
printf("sort : R_MPI_Comm_get_attr\n");
#endif
return ret_tmp;
}
int MPI_Comm_set_attr(A_MPI_Comm comm,int comm_keyval,void * attribute_val);
int (*LOCAL_MPI_Comm_set_attr)(R_MPI_Comm,int,void *);

__asm__(
".global PMPI_Comm_set_attr\n"
".weak MPI_Comm_set_attr\n"
".set MPI_Comm_set_attr,PMPI_Comm_set_attr\n"
".extern in_w\n"
".extern A_MPI_Comm_set_attr\n"
".extern R_MPI_Comm_set_attr\n"
".type PMPI_Comm_set_attr,@function\n"
".text\n"
"PMPI_Comm_set_attr:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Comm_set_attr\n"
"jmp *A_MPI_Comm_set_attr@GOTPCREL(%rip)\n"
"inwrap_MPI_Comm_set_attr:\n"
"jmp *R_MPI_Comm_set_attr@GOTPCREL(%rip)\n"
".size PMPI_Comm_set_attr,.-PMPI_Comm_set_attr\n"

);

int A_MPI_Comm_set_attr(A_MPI_Comm comm,int comm_keyval,void * attribute_val)
{
#ifdef DEBUG
printf("entre : A_MPI_Comm_set_attr\n");
#endif
in_w=1;

R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);




int ret_tmp= LOCAL_MPI_Comm_set_attr( comm_tmp, comm_keyval, attribute_val);
comm_conv_r2a(&comm,&comm_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Comm_set_attr\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Comm_set_attr(R_MPI_Comm comm,int comm_keyval,void * attribute_val)
{
#ifdef DEBUG
printf("entre : R_MPI_Comm_set_attr\n");
#endif
int ret_tmp= LOCAL_MPI_Comm_set_attr( comm, comm_keyval, attribute_val);
#ifdef DEBUG
printf("sort : R_MPI_Comm_set_attr\n");
#endif
return ret_tmp;
}
int MPI_Init_thread(int * argc,char *** argv,int required,int * provided);
int (*LOCAL_MPI_Init_thread)(int *,char ***,int,int *);

__asm__(
".global PMPI_Init_thread\n"
".weak MPI_Init_thread\n"
".set MPI_Init_thread,PMPI_Init_thread\n"
".extern in_w\n"
".extern A_MPI_Init_thread\n"
".extern R_MPI_Init_thread\n"
".type PMPI_Init_thread,@function\n"
".text\n"
"PMPI_Init_thread:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Init_thread\n"
"jmp *A_MPI_Init_thread@GOTPCREL(%rip)\n"
"inwrap_MPI_Init_thread:\n"
"jmp *R_MPI_Init_thread@GOTPCREL(%rip)\n"
".size PMPI_Init_thread,.-PMPI_Init_thread\n"

);

int A_MPI_Init_thread(int * argc,char *** argv,int required,int * provided)
{
#ifdef DEBUG
printf("entre : A_MPI_Init_thread\n");
#endif
in_w=1;








int ret_tmp= LOCAL_MPI_Init_thread( argc, argv, required, provided);

in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Init_thread\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Init_thread(int * argc,char *** argv,int required,int * provided)
{
#ifdef DEBUG
printf("entre : R_MPI_Init_thread\n");
#endif
int ret_tmp= LOCAL_MPI_Init_thread( argc, argv, required, provided);
#ifdef DEBUG
printf("sort : R_MPI_Init_thread\n");
#endif
return ret_tmp;
}
int MPI_Comm_create_errhandler(A_MPI_Comm_errhandler_function * comm_errhandler_fn,A_MPI_Errhandler * errhandler);
int (*LOCAL_MPI_Comm_create_errhandler)(R_MPI_Comm_errhandler_function *,R_MPI_Errhandler *);

__asm__(
".global PMPI_Comm_create_errhandler\n"
".weak MPI_Comm_create_errhandler\n"
".set MPI_Comm_create_errhandler,PMPI_Comm_create_errhandler\n"
".extern in_w\n"
".extern A_MPI_Comm_create_errhandler\n"
".extern R_MPI_Comm_create_errhandler\n"
".type PMPI_Comm_create_errhandler,@function\n"
".text\n"
"PMPI_Comm_create_errhandler:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Comm_create_errhandler\n"
"jmp *A_MPI_Comm_create_errhandler@GOTPCREL(%rip)\n"
"inwrap_MPI_Comm_create_errhandler:\n"
"jmp *R_MPI_Comm_create_errhandler@GOTPCREL(%rip)\n"
".size PMPI_Comm_create_errhandler,.-PMPI_Comm_create_errhandler\n"

);

int A_MPI_Comm_create_errhandler(A_MPI_Comm_errhandler_function * comm_errhandler_fn,A_MPI_Errhandler * errhandler)
{
#ifdef DEBUG
printf("entre : A_MPI_Comm_create_errhandler\n");
#endif
in_w=1;


ptr_comm_fn_handler=(A_MPI_Comm_errhandler_function *)comm_errhandler_fn;
R_MPI_Errhandler  errhandler_ltmp;
R_MPI_Errhandler * errhandler_tmp=&errhandler_ltmp;
int ret_tmp= LOCAL_MPI_Comm_create_errhandler( (R_MPI_Comm_errhandler_function *)wrapper_comm_handler_function, errhandler_tmp);
errhandler_ptr_conv_r2a(&errhandler,&errhandler_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Comm_create_errhandler\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Comm_create_errhandler(R_MPI_Comm_errhandler_function * comm_errhandler_fn,R_MPI_Errhandler * errhandler)
{
#ifdef DEBUG
printf("entre : R_MPI_Comm_create_errhandler\n");
#endif
int ret_tmp= LOCAL_MPI_Comm_create_errhandler( comm_errhandler_fn, errhandler);
#ifdef DEBUG
printf("sort : R_MPI_Comm_create_errhandler\n");
#endif
return ret_tmp;
}
int MPI_Comm_get_errhandler(A_MPI_Comm comm,A_MPI_Errhandler * errhandler);
int (*LOCAL_MPI_Comm_get_errhandler)(R_MPI_Comm,R_MPI_Errhandler *);

__asm__(
".global PMPI_Comm_get_errhandler\n"
".weak MPI_Comm_get_errhandler\n"
".set MPI_Comm_get_errhandler,PMPI_Comm_get_errhandler\n"
".extern in_w\n"
".extern A_MPI_Comm_get_errhandler\n"
".extern R_MPI_Comm_get_errhandler\n"
".type PMPI_Comm_get_errhandler,@function\n"
".text\n"
"PMPI_Comm_get_errhandler:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Comm_get_errhandler\n"
"jmp *A_MPI_Comm_get_errhandler@GOTPCREL(%rip)\n"
"inwrap_MPI_Comm_get_errhandler:\n"
"jmp *R_MPI_Comm_get_errhandler@GOTPCREL(%rip)\n"
".size PMPI_Comm_get_errhandler,.-PMPI_Comm_get_errhandler\n"

);

int A_MPI_Comm_get_errhandler(A_MPI_Comm comm,A_MPI_Errhandler * errhandler)
{
#ifdef DEBUG
printf("entre : A_MPI_Comm_get_errhandler\n");
#endif
in_w=1;

R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
R_MPI_Errhandler  errhandler_ltmp;
R_MPI_Errhandler * errhandler_tmp=&errhandler_ltmp;
int ret_tmp= LOCAL_MPI_Comm_get_errhandler( comm_tmp, errhandler_tmp);
if(ret_tmp == R_MPI_SUCCESS){
A_MPI_Comm_errhandler_fn* ptr_err_handler_func;
communicator_fn_translation_get(comm, &ptr_err_handler_func);
errhandler_fn_translation_update(*errhandler, ptr_err_handler_func);
}
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Comm_get_errhandler\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Comm_get_errhandler(R_MPI_Comm comm,R_MPI_Errhandler * errhandler)
{
#ifdef DEBUG
printf("entre : R_MPI_Comm_get_errhandler\n");
#endif
int ret_tmp= LOCAL_MPI_Comm_get_errhandler( comm, errhandler);
#ifdef DEBUG
printf("sort : R_MPI_Comm_get_errhandler\n");
#endif
return ret_tmp;
}
int MPI_Comm_set_errhandler(A_MPI_Comm comm,A_MPI_Errhandler errhandler);
int (*LOCAL_MPI_Comm_set_errhandler)(R_MPI_Comm,R_MPI_Errhandler);

__asm__(
".global PMPI_Comm_set_errhandler\n"
".weak MPI_Comm_set_errhandler\n"
".set MPI_Comm_set_errhandler,PMPI_Comm_set_errhandler\n"
".extern in_w\n"
".extern A_MPI_Comm_set_errhandler\n"
".extern R_MPI_Comm_set_errhandler\n"
".type PMPI_Comm_set_errhandler,@function\n"
".text\n"
"PMPI_Comm_set_errhandler:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Comm_set_errhandler\n"
"jmp *A_MPI_Comm_set_errhandler@GOTPCREL(%rip)\n"
"inwrap_MPI_Comm_set_errhandler:\n"
"jmp *R_MPI_Comm_set_errhandler@GOTPCREL(%rip)\n"
".size PMPI_Comm_set_errhandler,.-PMPI_Comm_set_errhandler\n"

);

int A_MPI_Comm_set_errhandler(A_MPI_Comm comm,A_MPI_Errhandler errhandler)
{
#ifdef DEBUG
printf("entre : A_MPI_Comm_set_errhandler\n");
#endif
in_w=1;

R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
R_MPI_Errhandler errhandler_tmp;
errhandler_conv_a2r(&errhandler,&errhandler_tmp);
int ret_tmp= LOCAL_MPI_Comm_set_errhandler( comm_tmp, errhandler_tmp);
if(!errhandler_translation_is_const(errhandler)){
A_MPI_Comm_errhandler_fn* ptr_errhandler_func;
errhandler_fn_translation_get(errhandler, &ptr_errhandler_func);
communicator_fn_translation_update(comm, ptr_errhandler_func);
}
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Comm_set_errhandler\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Comm_set_errhandler(R_MPI_Comm comm,R_MPI_Errhandler errhandler)
{
#ifdef DEBUG
printf("entre : R_MPI_Comm_set_errhandler\n");
#endif
int ret_tmp= LOCAL_MPI_Comm_set_errhandler( comm, errhandler);
#ifdef DEBUG
printf("sort : R_MPI_Comm_set_errhandler\n");
#endif
return ret_tmp;
}
int MPI_File_get_errhandler(A_MPI_File file,A_MPI_Errhandler * errhandler);
int (*LOCAL_MPI_File_get_errhandler)(R_MPI_File,R_MPI_Errhandler *);

__asm__(
".global PMPI_File_get_errhandler\n"
".weak MPI_File_get_errhandler\n"
".set MPI_File_get_errhandler,PMPI_File_get_errhandler\n"
".extern in_w\n"
".extern A_MPI_File_get_errhandler\n"
".extern R_MPI_File_get_errhandler\n"
".type PMPI_File_get_errhandler,@function\n"
".text\n"
"PMPI_File_get_errhandler:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_get_errhandler\n"
"jmp *A_MPI_File_get_errhandler@GOTPCREL(%rip)\n"
"inwrap_MPI_File_get_errhandler:\n"
"jmp *R_MPI_File_get_errhandler@GOTPCREL(%rip)\n"
".size PMPI_File_get_errhandler,.-PMPI_File_get_errhandler\n"

);

int A_MPI_File_get_errhandler(A_MPI_File file,A_MPI_Errhandler * errhandler)
{
#ifdef DEBUG
printf("entre : A_MPI_File_get_errhandler\n");
#endif
in_w=1;

R_MPI_File file_tmp;
file_conv_a2r(&file,&file_tmp);
R_MPI_Errhandler  errhandler_ltmp;
R_MPI_Errhandler * errhandler_tmp=&errhandler_ltmp;
int ret_tmp= LOCAL_MPI_File_get_errhandler( file_tmp, errhandler_tmp);
if(ret_tmp == R_MPI_SUCCESS){
errhandler_ptr_conv_r2a(&errhandler,&errhandler_tmp);
}
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_get_errhandler\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_get_errhandler(R_MPI_File file,R_MPI_Errhandler * errhandler)
{
#ifdef DEBUG
printf("entre : R_MPI_File_get_errhandler\n");
#endif
int ret_tmp= LOCAL_MPI_File_get_errhandler( file, errhandler);
#ifdef DEBUG
printf("sort : R_MPI_File_get_errhandler\n");
#endif
return ret_tmp;
}
int MPI_File_set_errhandler(A_MPI_File file,A_MPI_Errhandler errhandler);
int (*LOCAL_MPI_File_set_errhandler)(R_MPI_File,R_MPI_Errhandler);

__asm__(
".global PMPI_File_set_errhandler\n"
".weak MPI_File_set_errhandler\n"
".set MPI_File_set_errhandler,PMPI_File_set_errhandler\n"
".extern in_w\n"
".extern A_MPI_File_set_errhandler\n"
".extern R_MPI_File_set_errhandler\n"
".type PMPI_File_set_errhandler,@function\n"
".text\n"
"PMPI_File_set_errhandler:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_set_errhandler\n"
"jmp *A_MPI_File_set_errhandler@GOTPCREL(%rip)\n"
"inwrap_MPI_File_set_errhandler:\n"
"jmp *R_MPI_File_set_errhandler@GOTPCREL(%rip)\n"
".size PMPI_File_set_errhandler,.-PMPI_File_set_errhandler\n"

);

int A_MPI_File_set_errhandler(A_MPI_File file,A_MPI_Errhandler errhandler)
{
#ifdef DEBUG
printf("entre : A_MPI_File_set_errhandler\n");
#endif
in_w=1;

R_MPI_File file_tmp;
file_conv_a2r(&file,&file_tmp);
R_MPI_Errhandler errhandler_tmp;
errhandler_conv_a2r(&errhandler,&errhandler_tmp);
int ret_tmp= LOCAL_MPI_File_set_errhandler( file_tmp, errhandler_tmp);
file_conv_r2a(&file,&file_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_set_errhandler\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_set_errhandler(R_MPI_File file,R_MPI_Errhandler errhandler)
{
#ifdef DEBUG
printf("entre : R_MPI_File_set_errhandler\n");
#endif
int ret_tmp= LOCAL_MPI_File_set_errhandler( file, errhandler);
#ifdef DEBUG
printf("sort : R_MPI_File_set_errhandler\n");
#endif
return ret_tmp;
}
int MPI_Info_create(A_MPI_Info * info);
int (*LOCAL_MPI_Info_create)(R_MPI_Info *);

__asm__(
".global PMPI_Info_create\n"
".weak MPI_Info_create\n"
".set MPI_Info_create,PMPI_Info_create\n"
".extern in_w\n"
".extern A_MPI_Info_create\n"
".extern R_MPI_Info_create\n"
".type PMPI_Info_create,@function\n"
".text\n"
"PMPI_Info_create:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Info_create\n"
"jmp *A_MPI_Info_create@GOTPCREL(%rip)\n"
"inwrap_MPI_Info_create:\n"
"jmp *R_MPI_Info_create@GOTPCREL(%rip)\n"
".size PMPI_Info_create,.-PMPI_Info_create\n"

);

int A_MPI_Info_create(A_MPI_Info * info)
{
#ifdef DEBUG
printf("entre : A_MPI_Info_create\n");
#endif
in_w=1;

R_MPI_Info  info_ltmp;
R_MPI_Info * info_tmp=&info_ltmp;
int ret_tmp= LOCAL_MPI_Info_create( info_tmp);
info_conv_r2a(info,info_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Info_create\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Info_create(R_MPI_Info * info)
{
#ifdef DEBUG
printf("entre : R_MPI_Info_create\n");
#endif
int ret_tmp= LOCAL_MPI_Info_create( info);
#ifdef DEBUG
printf("sort : R_MPI_Info_create\n");
#endif
return ret_tmp;
}
int MPI_Info_delete(A_MPI_Info info,char * key);
int (*LOCAL_MPI_Info_delete)(R_MPI_Info,char *);

__asm__(
".global PMPI_Info_delete\n"
".weak MPI_Info_delete\n"
".set MPI_Info_delete,PMPI_Info_delete\n"
".extern in_w\n"
".extern A_MPI_Info_delete\n"
".extern R_MPI_Info_delete\n"
".type PMPI_Info_delete,@function\n"
".text\n"
"PMPI_Info_delete:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Info_delete\n"
"jmp *A_MPI_Info_delete@GOTPCREL(%rip)\n"
"inwrap_MPI_Info_delete:\n"
"jmp *R_MPI_Info_delete@GOTPCREL(%rip)\n"
".size PMPI_Info_delete,.-PMPI_Info_delete\n"

);

int A_MPI_Info_delete(A_MPI_Info info,char * key)
{
#ifdef DEBUG
printf("entre : A_MPI_Info_delete\n");
#endif
in_w=1;

R_MPI_Info info_tmp;
info_conv_a2r(&info,&info_tmp);


int ret_tmp= LOCAL_MPI_Info_delete( info_tmp, key);
info_conv_r2a(&info,&info_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Info_delete\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Info_delete(R_MPI_Info info,char * key)
{
#ifdef DEBUG
printf("entre : R_MPI_Info_delete\n");
#endif
int ret_tmp= LOCAL_MPI_Info_delete( info, key);
#ifdef DEBUG
printf("sort : R_MPI_Info_delete\n");
#endif
return ret_tmp;
}
int MPI_Info_dup(A_MPI_Info info,A_MPI_Info * newinfo);
int (*LOCAL_MPI_Info_dup)(R_MPI_Info,R_MPI_Info *);

__asm__(
".global PMPI_Info_dup\n"
".weak MPI_Info_dup\n"
".set MPI_Info_dup,PMPI_Info_dup\n"
".extern in_w\n"
".extern A_MPI_Info_dup\n"
".extern R_MPI_Info_dup\n"
".type PMPI_Info_dup,@function\n"
".text\n"
"PMPI_Info_dup:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Info_dup\n"
"jmp *A_MPI_Info_dup@GOTPCREL(%rip)\n"
"inwrap_MPI_Info_dup:\n"
"jmp *R_MPI_Info_dup@GOTPCREL(%rip)\n"
".size PMPI_Info_dup,.-PMPI_Info_dup\n"

);

int A_MPI_Info_dup(A_MPI_Info info,A_MPI_Info * newinfo)
{
#ifdef DEBUG
printf("entre : A_MPI_Info_dup\n");
#endif
in_w=1;

R_MPI_Info info_tmp;
info_conv_a2r(&info,&info_tmp);
R_MPI_Info  newinfo_ltmp;
R_MPI_Info * newinfo_tmp=&newinfo_ltmp;
int ret_tmp= LOCAL_MPI_Info_dup( info_tmp, newinfo_tmp);
info_conv_r2a(newinfo,newinfo_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Info_dup\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Info_dup(R_MPI_Info info,R_MPI_Info * newinfo)
{
#ifdef DEBUG
printf("entre : R_MPI_Info_dup\n");
#endif
int ret_tmp= LOCAL_MPI_Info_dup( info, newinfo);
#ifdef DEBUG
printf("sort : R_MPI_Info_dup\n");
#endif
return ret_tmp;
}
int MPI_Info_free(A_MPI_Info * info);
int (*LOCAL_MPI_Info_free)(R_MPI_Info *);

__asm__(
".global PMPI_Info_free\n"
".weak MPI_Info_free\n"
".set MPI_Info_free,PMPI_Info_free\n"
".extern in_w\n"
".extern A_MPI_Info_free\n"
".extern R_MPI_Info_free\n"
".type PMPI_Info_free,@function\n"
".text\n"
"PMPI_Info_free:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Info_free\n"
"jmp *A_MPI_Info_free@GOTPCREL(%rip)\n"
"inwrap_MPI_Info_free:\n"
"jmp *R_MPI_Info_free@GOTPCREL(%rip)\n"
".size PMPI_Info_free,.-PMPI_Info_free\n"

);

int A_MPI_Info_free(A_MPI_Info * info)
{
#ifdef DEBUG
printf("entre : A_MPI_Info_free\n");
#endif
in_w=1;

R_MPI_Info  info_ltmp;
R_MPI_Info * info_tmp=&info_ltmp;
info_conv_a2r(info,info_tmp);
int ret_tmp= LOCAL_MPI_Info_free( info_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Info_free\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Info_free(R_MPI_Info * info)
{
#ifdef DEBUG
printf("entre : R_MPI_Info_free\n");
#endif
int ret_tmp= LOCAL_MPI_Info_free( info);
#ifdef DEBUG
printf("sort : R_MPI_Info_free\n");
#endif
return ret_tmp;
}
int MPI_Info_get(A_MPI_Info info,char * key,int valuelen,char * value,int * flag);
int (*LOCAL_MPI_Info_get)(R_MPI_Info,char *,int,char *,int *);

__asm__(
".global PMPI_Info_get\n"
".weak MPI_Info_get\n"
".set MPI_Info_get,PMPI_Info_get\n"
".extern in_w\n"
".extern A_MPI_Info_get\n"
".extern R_MPI_Info_get\n"
".type PMPI_Info_get,@function\n"
".text\n"
"PMPI_Info_get:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Info_get\n"
"jmp *A_MPI_Info_get@GOTPCREL(%rip)\n"
"inwrap_MPI_Info_get:\n"
"jmp *R_MPI_Info_get@GOTPCREL(%rip)\n"
".size PMPI_Info_get,.-PMPI_Info_get\n"

);

int A_MPI_Info_get(A_MPI_Info info,char * key,int valuelen,char * value,int * flag)
{
#ifdef DEBUG
printf("entre : A_MPI_Info_get\n");
#endif
in_w=1;

R_MPI_Info info_tmp;
info_conv_a2r(&info,&info_tmp);






int ret_tmp= LOCAL_MPI_Info_get( info_tmp, key, valuelen, value, flag);


in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Info_get\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Info_get(R_MPI_Info info,char * key,int valuelen,char * value,int * flag)
{
#ifdef DEBUG
printf("entre : R_MPI_Info_get\n");
#endif
int ret_tmp= LOCAL_MPI_Info_get( info, key, valuelen, value, flag);
#ifdef DEBUG
printf("sort : R_MPI_Info_get\n");
#endif
return ret_tmp;
}
int MPI_Info_get_nkeys(A_MPI_Info info,int * nkeys);
int (*LOCAL_MPI_Info_get_nkeys)(R_MPI_Info,int *);

__asm__(
".global PMPI_Info_get_nkeys\n"
".weak MPI_Info_get_nkeys\n"
".set MPI_Info_get_nkeys,PMPI_Info_get_nkeys\n"
".extern in_w\n"
".extern A_MPI_Info_get_nkeys\n"
".extern R_MPI_Info_get_nkeys\n"
".type PMPI_Info_get_nkeys,@function\n"
".text\n"
"PMPI_Info_get_nkeys:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Info_get_nkeys\n"
"jmp *A_MPI_Info_get_nkeys@GOTPCREL(%rip)\n"
"inwrap_MPI_Info_get_nkeys:\n"
"jmp *R_MPI_Info_get_nkeys@GOTPCREL(%rip)\n"
".size PMPI_Info_get_nkeys,.-PMPI_Info_get_nkeys\n"

);

int A_MPI_Info_get_nkeys(A_MPI_Info info,int * nkeys)
{
#ifdef DEBUG
printf("entre : A_MPI_Info_get_nkeys\n");
#endif
in_w=1;

R_MPI_Info info_tmp;
info_conv_a2r(&info,&info_tmp);

int ret_tmp= LOCAL_MPI_Info_get_nkeys( info_tmp, nkeys);

in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Info_get_nkeys\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Info_get_nkeys(R_MPI_Info info,int * nkeys)
{
#ifdef DEBUG
printf("entre : R_MPI_Info_get_nkeys\n");
#endif
int ret_tmp= LOCAL_MPI_Info_get_nkeys( info, nkeys);
#ifdef DEBUG
printf("sort : R_MPI_Info_get_nkeys\n");
#endif
return ret_tmp;
}
int MPI_Info_get_nthkey(A_MPI_Info info,int n,char * key);
int (*LOCAL_MPI_Info_get_nthkey)(R_MPI_Info,int,char *);

__asm__(
".global PMPI_Info_get_nthkey\n"
".weak MPI_Info_get_nthkey\n"
".set MPI_Info_get_nthkey,PMPI_Info_get_nthkey\n"
".extern in_w\n"
".extern A_MPI_Info_get_nthkey\n"
".extern R_MPI_Info_get_nthkey\n"
".type PMPI_Info_get_nthkey,@function\n"
".text\n"
"PMPI_Info_get_nthkey:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Info_get_nthkey\n"
"jmp *A_MPI_Info_get_nthkey@GOTPCREL(%rip)\n"
"inwrap_MPI_Info_get_nthkey:\n"
"jmp *R_MPI_Info_get_nthkey@GOTPCREL(%rip)\n"
".size PMPI_Info_get_nthkey,.-PMPI_Info_get_nthkey\n"

);

int A_MPI_Info_get_nthkey(A_MPI_Info info,int n,char * key)
{
#ifdef DEBUG
printf("entre : A_MPI_Info_get_nthkey\n");
#endif
in_w=1;

R_MPI_Info info_tmp;
info_conv_a2r(&info,&info_tmp);



int ret_tmp= LOCAL_MPI_Info_get_nthkey( info_tmp, n, key);

in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Info_get_nthkey\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Info_get_nthkey(R_MPI_Info info,int n,char * key)
{
#ifdef DEBUG
printf("entre : R_MPI_Info_get_nthkey\n");
#endif
int ret_tmp= LOCAL_MPI_Info_get_nthkey( info, n, key);
#ifdef DEBUG
printf("sort : R_MPI_Info_get_nthkey\n");
#endif
return ret_tmp;
}
int MPI_Info_get_valuelen(A_MPI_Info info,char * key,int * valuelen,int * flag);
int (*LOCAL_MPI_Info_get_valuelen)(R_MPI_Info,char *,int *,int *);

__asm__(
".global PMPI_Info_get_valuelen\n"
".weak MPI_Info_get_valuelen\n"
".set MPI_Info_get_valuelen,PMPI_Info_get_valuelen\n"
".extern in_w\n"
".extern A_MPI_Info_get_valuelen\n"
".extern R_MPI_Info_get_valuelen\n"
".type PMPI_Info_get_valuelen,@function\n"
".text\n"
"PMPI_Info_get_valuelen:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Info_get_valuelen\n"
"jmp *A_MPI_Info_get_valuelen@GOTPCREL(%rip)\n"
"inwrap_MPI_Info_get_valuelen:\n"
"jmp *R_MPI_Info_get_valuelen@GOTPCREL(%rip)\n"
".size PMPI_Info_get_valuelen,.-PMPI_Info_get_valuelen\n"

);

int A_MPI_Info_get_valuelen(A_MPI_Info info,char * key,int * valuelen,int * flag)
{
#ifdef DEBUG
printf("entre : A_MPI_Info_get_valuelen\n");
#endif
in_w=1;

R_MPI_Info info_tmp;
info_conv_a2r(&info,&info_tmp);




int ret_tmp= LOCAL_MPI_Info_get_valuelen( info_tmp, key, valuelen, flag);


in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Info_get_valuelen\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Info_get_valuelen(R_MPI_Info info,char * key,int * valuelen,int * flag)
{
#ifdef DEBUG
printf("entre : R_MPI_Info_get_valuelen\n");
#endif
int ret_tmp= LOCAL_MPI_Info_get_valuelen( info, key, valuelen, flag);
#ifdef DEBUG
printf("sort : R_MPI_Info_get_valuelen\n");
#endif
return ret_tmp;
}
int MPI_Info_set(A_MPI_Info info,char * key,char * value);
int (*LOCAL_MPI_Info_set)(R_MPI_Info,char *,char *);

__asm__(
".global PMPI_Info_set\n"
".weak MPI_Info_set\n"
".set MPI_Info_set,PMPI_Info_set\n"
".extern in_w\n"
".extern A_MPI_Info_set\n"
".extern R_MPI_Info_set\n"
".type PMPI_Info_set,@function\n"
".text\n"
"PMPI_Info_set:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Info_set\n"
"jmp *A_MPI_Info_set@GOTPCREL(%rip)\n"
"inwrap_MPI_Info_set:\n"
"jmp *R_MPI_Info_set@GOTPCREL(%rip)\n"
".size PMPI_Info_set,.-PMPI_Info_set\n"

);

int A_MPI_Info_set(A_MPI_Info info,char * key,char * value)
{
#ifdef DEBUG
printf("entre : A_MPI_Info_set\n");
#endif
in_w=1;

R_MPI_Info info_tmp;
info_conv_a2r(&info,&info_tmp);




int ret_tmp= LOCAL_MPI_Info_set( info_tmp, key, value);
info_conv_r2a(&info,&info_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Info_set\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Info_set(R_MPI_Info info,char * key,char * value)
{
#ifdef DEBUG
printf("entre : R_MPI_Info_set\n");
#endif
int ret_tmp= LOCAL_MPI_Info_set( info, key, value);
#ifdef DEBUG
printf("sort : R_MPI_Info_set\n");
#endif
return ret_tmp;
}
int MPI_Request_get_status(A_MPI_Request request,int * flag,A_MPI_Status * status);
int (*LOCAL_MPI_Request_get_status)(R_MPI_Request,int *,R_MPI_Status *);

__asm__(
".global PMPI_Request_get_status\n"
".weak MPI_Request_get_status\n"
".set MPI_Request_get_status,PMPI_Request_get_status\n"
".extern in_w\n"
".extern A_MPI_Request_get_status\n"
".extern R_MPI_Request_get_status\n"
".type PMPI_Request_get_status,@function\n"
".text\n"
"PMPI_Request_get_status:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Request_get_status\n"
"jmp *A_MPI_Request_get_status@GOTPCREL(%rip)\n"
"inwrap_MPI_Request_get_status:\n"
"jmp *R_MPI_Request_get_status@GOTPCREL(%rip)\n"
".size PMPI_Request_get_status,.-PMPI_Request_get_status\n"

);

int A_MPI_Request_get_status(A_MPI_Request request,int * flag,A_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : A_MPI_Request_get_status\n");
#endif
in_w=1;

R_MPI_Request request_tmp;
request_tab_conv_a2r(&request,&request_tmp);

R_MPI_Status  status_ltmp;
R_MPI_Status * status_tmp=&status_ltmp;
int ret_tmp= LOCAL_MPI_Request_get_status( request_tmp, flag, status_tmp);

status_prt_conv_r2a(&status,&status_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Request_get_status\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Request_get_status(R_MPI_Request request,int * flag,R_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : R_MPI_Request_get_status\n");
#endif
int ret_tmp= LOCAL_MPI_Request_get_status( request, flag, status);
#ifdef DEBUG
printf("sort : R_MPI_Request_get_status\n");
#endif
return ret_tmp;
}
int MPI_Type_create_hvector(int count,int blocklength,A_MPI_Aint stride,A_MPI_Datatype oldtype,A_MPI_Datatype * newtype);
int (*LOCAL_MPI_Type_create_hvector)(int,int,R_MPI_Aint,R_MPI_Datatype,R_MPI_Datatype *);

__asm__(
".global PMPI_Type_create_hvector\n"
".weak MPI_Type_create_hvector\n"
".set MPI_Type_create_hvector,PMPI_Type_create_hvector\n"
".extern in_w\n"
".extern A_MPI_Type_create_hvector\n"
".extern R_MPI_Type_create_hvector\n"
".type PMPI_Type_create_hvector,@function\n"
".text\n"
"PMPI_Type_create_hvector:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Type_create_hvector\n"
"jmp *A_MPI_Type_create_hvector@GOTPCREL(%rip)\n"
"inwrap_MPI_Type_create_hvector:\n"
"jmp *R_MPI_Type_create_hvector@GOTPCREL(%rip)\n"
".size PMPI_Type_create_hvector,.-PMPI_Type_create_hvector\n"

);

int A_MPI_Type_create_hvector(int count,int blocklength,A_MPI_Aint stride,A_MPI_Datatype oldtype,A_MPI_Datatype * newtype)
{
#ifdef DEBUG
printf("entre : A_MPI_Type_create_hvector\n");
#endif
in_w=1;





R_MPI_Aint stride_tmp;
stride_tmp = (R_MPI_Aint)stride;
R_MPI_Datatype oldtype_tmp;
datatype_conv_a2r(&oldtype,&oldtype_tmp);
R_MPI_Datatype  newtype_ltmp;
R_MPI_Datatype * newtype_tmp=&newtype_ltmp;
int ret_tmp= LOCAL_MPI_Type_create_hvector( count, blocklength, stride_tmp, oldtype_tmp, newtype_tmp);
datatype_conv_r2a(newtype,newtype_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Type_create_hvector\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Type_create_hvector(int count,int blocklength,R_MPI_Aint stride,R_MPI_Datatype oldtype,R_MPI_Datatype * newtype)
{
#ifdef DEBUG
printf("entre : R_MPI_Type_create_hvector\n");
#endif
int ret_tmp= LOCAL_MPI_Type_create_hvector( count, blocklength, stride, oldtype, newtype);
#ifdef DEBUG
printf("sort : R_MPI_Type_create_hvector\n");
#endif
return ret_tmp;
}
int MPI_Type_get_extent(A_MPI_Datatype datatype,A_MPI_Aint * lb,A_MPI_Aint * extent);
int (*LOCAL_MPI_Type_get_extent)(R_MPI_Datatype,R_MPI_Aint *,R_MPI_Aint *);

__asm__(
".global PMPI_Type_get_extent\n"
".weak MPI_Type_get_extent\n"
".set MPI_Type_get_extent,PMPI_Type_get_extent\n"
".extern in_w\n"
".extern A_MPI_Type_get_extent\n"
".extern R_MPI_Type_get_extent\n"
".type PMPI_Type_get_extent,@function\n"
".text\n"
"PMPI_Type_get_extent:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Type_get_extent\n"
"jmp *A_MPI_Type_get_extent@GOTPCREL(%rip)\n"
"inwrap_MPI_Type_get_extent:\n"
"jmp *R_MPI_Type_get_extent@GOTPCREL(%rip)\n"
".size PMPI_Type_get_extent,.-PMPI_Type_get_extent\n"

);

int A_MPI_Type_get_extent(A_MPI_Datatype datatype,A_MPI_Aint * lb,A_MPI_Aint * extent)
{
#ifdef DEBUG
printf("entre : A_MPI_Type_get_extent\n");
#endif
in_w=1;

R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
R_MPI_Aint  lb_ltmp;
R_MPI_Aint * lb_tmp=&lb_ltmp;
R_MPI_Aint  extent_ltmp;
R_MPI_Aint * extent_tmp=&extent_ltmp;
int ret_tmp= LOCAL_MPI_Type_get_extent( datatype_tmp, lb_tmp, extent_tmp);
*lb= (A_MPI_Aint ) *lb_tmp;
*extent= (A_MPI_Aint ) *extent_tmp;
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Type_get_extent\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Type_get_extent(R_MPI_Datatype datatype,R_MPI_Aint * lb,R_MPI_Aint * extent)
{
#ifdef DEBUG
printf("entre : R_MPI_Type_get_extent\n");
#endif
int ret_tmp= LOCAL_MPI_Type_get_extent( datatype, lb, extent);
#ifdef DEBUG
printf("sort : R_MPI_Type_get_extent\n");
#endif
return ret_tmp;
}
int MPI_File_open(A_MPI_Comm comm,char * filename,int amode,A_MPI_Info info,A_MPI_File * fh);
int (*LOCAL_MPI_File_open)(R_MPI_Comm,char *,int,R_MPI_Info,R_MPI_File *);

__asm__(
".global PMPI_File_open\n"
".weak MPI_File_open\n"
".set MPI_File_open,PMPI_File_open\n"
".extern in_w\n"
".extern A_MPI_File_open\n"
".extern R_MPI_File_open\n"
".type PMPI_File_open,@function\n"
".text\n"
"PMPI_File_open:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_open\n"
"jmp *A_MPI_File_open@GOTPCREL(%rip)\n"
"inwrap_MPI_File_open:\n"
"jmp *R_MPI_File_open@GOTPCREL(%rip)\n"
".size PMPI_File_open,.-PMPI_File_open\n"

);

int A_MPI_File_open(A_MPI_Comm comm,char * filename,int amode,A_MPI_Info info,A_MPI_File * fh)
{
#ifdef DEBUG
printf("entre : A_MPI_File_open\n");
#endif
in_w=1;

R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);


int amode_tmp =0;
amode_conv_a2r(&amode,&amode_tmp);
R_MPI_Info info_tmp;
info_conv_a2r(&info,&info_tmp);
R_MPI_File  fh_ltmp;
R_MPI_File * fh_tmp=&fh_ltmp;
int ret_tmp= LOCAL_MPI_File_open( comm_tmp, filename, amode_tmp, info_tmp, fh_tmp);
file_conv_r2a(fh,fh_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_open\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_open(R_MPI_Comm comm,char * filename,int amode,R_MPI_Info info,R_MPI_File * fh)
{
#ifdef DEBUG
printf("entre : R_MPI_File_open\n");
#endif
int ret_tmp= LOCAL_MPI_File_open( comm, filename, amode, info, fh);
#ifdef DEBUG
printf("sort : R_MPI_File_open\n");
#endif
return ret_tmp;
}
int MPI_File_close(A_MPI_File * fh);
int (*LOCAL_MPI_File_close)(R_MPI_File *);

__asm__(
".global PMPI_File_close\n"
".weak MPI_File_close\n"
".set MPI_File_close,PMPI_File_close\n"
".extern in_w\n"
".extern A_MPI_File_close\n"
".extern R_MPI_File_close\n"
".type PMPI_File_close,@function\n"
".text\n"
"PMPI_File_close:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_close\n"
"jmp *A_MPI_File_close@GOTPCREL(%rip)\n"
"inwrap_MPI_File_close:\n"
"jmp *R_MPI_File_close@GOTPCREL(%rip)\n"
".size PMPI_File_close,.-PMPI_File_close\n"

);

int A_MPI_File_close(A_MPI_File * fh)
{
#ifdef DEBUG
printf("entre : A_MPI_File_close\n");
#endif
in_w=1;

R_MPI_File  fh_ltmp;
R_MPI_File * fh_tmp=&fh_ltmp;
file_conv_a2r(fh,fh_tmp);
int ret_tmp= LOCAL_MPI_File_close( fh_tmp);
file_conv_r2a(fh,fh_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_close\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_close(R_MPI_File * fh)
{
#ifdef DEBUG
printf("entre : R_MPI_File_close\n");
#endif
int ret_tmp= LOCAL_MPI_File_close( fh);
#ifdef DEBUG
printf("sort : R_MPI_File_close\n");
#endif
return ret_tmp;
}
int MPI_File_delete(char * filename,A_MPI_Info info);
int (*LOCAL_MPI_File_delete)(char *,R_MPI_Info);

__asm__(
".global PMPI_File_delete\n"
".weak MPI_File_delete\n"
".set MPI_File_delete,PMPI_File_delete\n"
".extern in_w\n"
".extern A_MPI_File_delete\n"
".extern R_MPI_File_delete\n"
".type PMPI_File_delete,@function\n"
".text\n"
"PMPI_File_delete:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_delete\n"
"jmp *A_MPI_File_delete@GOTPCREL(%rip)\n"
"inwrap_MPI_File_delete:\n"
"jmp *R_MPI_File_delete@GOTPCREL(%rip)\n"
".size PMPI_File_delete,.-PMPI_File_delete\n"

);

int A_MPI_File_delete(char * filename,A_MPI_Info info)
{
#ifdef DEBUG
printf("entre : A_MPI_File_delete\n");
#endif
in_w=1;



R_MPI_Info info_tmp;
info_conv_a2r(&info,&info_tmp);
int ret_tmp= LOCAL_MPI_File_delete( filename, info_tmp);

in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_delete\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_delete(char * filename,R_MPI_Info info)
{
#ifdef DEBUG
printf("entre : R_MPI_File_delete\n");
#endif
int ret_tmp= LOCAL_MPI_File_delete( filename, info);
#ifdef DEBUG
printf("sort : R_MPI_File_delete\n");
#endif
return ret_tmp;
}
int MPI_File_set_size(A_MPI_File fh,A_MPI_Offset size);
int (*LOCAL_MPI_File_set_size)(R_MPI_File,R_MPI_Offset);

__asm__(
".global PMPI_File_set_size\n"
".weak MPI_File_set_size\n"
".set MPI_File_set_size,PMPI_File_set_size\n"
".extern in_w\n"
".extern A_MPI_File_set_size\n"
".extern R_MPI_File_set_size\n"
".type PMPI_File_set_size,@function\n"
".text\n"
"PMPI_File_set_size:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_set_size\n"
"jmp *A_MPI_File_set_size@GOTPCREL(%rip)\n"
"inwrap_MPI_File_set_size:\n"
"jmp *R_MPI_File_set_size@GOTPCREL(%rip)\n"
".size PMPI_File_set_size,.-PMPI_File_set_size\n"

);

int A_MPI_File_set_size(A_MPI_File fh,A_MPI_Offset size)
{
#ifdef DEBUG
printf("entre : A_MPI_File_set_size\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
R_MPI_Offset size_tmp;
size_tmp = (R_MPI_Offset)size;
int ret_tmp= LOCAL_MPI_File_set_size( fh_tmp, size_tmp);
file_conv_r2a(&fh,&fh_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_set_size\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_set_size(R_MPI_File fh,R_MPI_Offset size)
{
#ifdef DEBUG
printf("entre : R_MPI_File_set_size\n");
#endif
int ret_tmp= LOCAL_MPI_File_set_size( fh, size);
#ifdef DEBUG
printf("sort : R_MPI_File_set_size\n");
#endif
return ret_tmp;
}
int MPI_File_preallocate(A_MPI_File fh,A_MPI_Offset size);
int (*LOCAL_MPI_File_preallocate)(R_MPI_File,R_MPI_Offset);

__asm__(
".global PMPI_File_preallocate\n"
".weak MPI_File_preallocate\n"
".set MPI_File_preallocate,PMPI_File_preallocate\n"
".extern in_w\n"
".extern A_MPI_File_preallocate\n"
".extern R_MPI_File_preallocate\n"
".type PMPI_File_preallocate,@function\n"
".text\n"
"PMPI_File_preallocate:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_preallocate\n"
"jmp *A_MPI_File_preallocate@GOTPCREL(%rip)\n"
"inwrap_MPI_File_preallocate:\n"
"jmp *R_MPI_File_preallocate@GOTPCREL(%rip)\n"
".size PMPI_File_preallocate,.-PMPI_File_preallocate\n"

);

int A_MPI_File_preallocate(A_MPI_File fh,A_MPI_Offset size)
{
#ifdef DEBUG
printf("entre : A_MPI_File_preallocate\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
R_MPI_Offset size_tmp;
size_tmp = (R_MPI_Offset)size;
int ret_tmp= LOCAL_MPI_File_preallocate( fh_tmp, size_tmp);
file_conv_r2a(&fh,&fh_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_preallocate\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_preallocate(R_MPI_File fh,R_MPI_Offset size)
{
#ifdef DEBUG
printf("entre : R_MPI_File_preallocate\n");
#endif
int ret_tmp= LOCAL_MPI_File_preallocate( fh, size);
#ifdef DEBUG
printf("sort : R_MPI_File_preallocate\n");
#endif
return ret_tmp;
}
int MPI_File_get_size(A_MPI_File fh,A_MPI_Offset * size);
int (*LOCAL_MPI_File_get_size)(R_MPI_File,R_MPI_Offset *);

__asm__(
".global PMPI_File_get_size\n"
".weak MPI_File_get_size\n"
".set MPI_File_get_size,PMPI_File_get_size\n"
".extern in_w\n"
".extern A_MPI_File_get_size\n"
".extern R_MPI_File_get_size\n"
".type PMPI_File_get_size,@function\n"
".text\n"
"PMPI_File_get_size:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_get_size\n"
"jmp *A_MPI_File_get_size@GOTPCREL(%rip)\n"
"inwrap_MPI_File_get_size:\n"
"jmp *R_MPI_File_get_size@GOTPCREL(%rip)\n"
".size PMPI_File_get_size,.-PMPI_File_get_size\n"

);

int A_MPI_File_get_size(A_MPI_File fh,A_MPI_Offset * size)
{
#ifdef DEBUG
printf("entre : A_MPI_File_get_size\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
R_MPI_Offset  size_ltmp;
R_MPI_Offset * size_tmp=&size_ltmp;
int ret_tmp= LOCAL_MPI_File_get_size( fh_tmp, size_tmp);
*size= (A_MPI_Offset ) *size_tmp;
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_get_size\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_get_size(R_MPI_File fh,R_MPI_Offset * size)
{
#ifdef DEBUG
printf("entre : R_MPI_File_get_size\n");
#endif
int ret_tmp= LOCAL_MPI_File_get_size( fh, size);
#ifdef DEBUG
printf("sort : R_MPI_File_get_size\n");
#endif
return ret_tmp;
}
int MPI_File_get_group(A_MPI_File fh,A_MPI_Group * group);
int (*LOCAL_MPI_File_get_group)(R_MPI_File,R_MPI_Group *);

__asm__(
".global PMPI_File_get_group\n"
".weak MPI_File_get_group\n"
".set MPI_File_get_group,PMPI_File_get_group\n"
".extern in_w\n"
".extern A_MPI_File_get_group\n"
".extern R_MPI_File_get_group\n"
".type PMPI_File_get_group,@function\n"
".text\n"
"PMPI_File_get_group:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_get_group\n"
"jmp *A_MPI_File_get_group@GOTPCREL(%rip)\n"
"inwrap_MPI_File_get_group:\n"
"jmp *R_MPI_File_get_group@GOTPCREL(%rip)\n"
".size PMPI_File_get_group,.-PMPI_File_get_group\n"

);

int A_MPI_File_get_group(A_MPI_File fh,A_MPI_Group * group)
{
#ifdef DEBUG
printf("entre : A_MPI_File_get_group\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
R_MPI_Group  group_ltmp;
R_MPI_Group * group_tmp=&group_ltmp;
int ret_tmp= LOCAL_MPI_File_get_group( fh_tmp, group_tmp);
group_conv_r2a(group,group_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_get_group\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_get_group(R_MPI_File fh,R_MPI_Group * group)
{
#ifdef DEBUG
printf("entre : R_MPI_File_get_group\n");
#endif
int ret_tmp= LOCAL_MPI_File_get_group( fh, group);
#ifdef DEBUG
printf("sort : R_MPI_File_get_group\n");
#endif
return ret_tmp;
}
int MPI_File_get_amode(A_MPI_File fh,int * amode);
int (*LOCAL_MPI_File_get_amode)(R_MPI_File,int *);

__asm__(
".global PMPI_File_get_amode\n"
".weak MPI_File_get_amode\n"
".set MPI_File_get_amode,PMPI_File_get_amode\n"
".extern in_w\n"
".extern A_MPI_File_get_amode\n"
".extern R_MPI_File_get_amode\n"
".type PMPI_File_get_amode,@function\n"
".text\n"
"PMPI_File_get_amode:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_get_amode\n"
"jmp *A_MPI_File_get_amode@GOTPCREL(%rip)\n"
"inwrap_MPI_File_get_amode:\n"
"jmp *R_MPI_File_get_amode@GOTPCREL(%rip)\n"
".size PMPI_File_get_amode,.-PMPI_File_get_amode\n"

);

int A_MPI_File_get_amode(A_MPI_File fh,int * amode)
{
#ifdef DEBUG
printf("entre : A_MPI_File_get_amode\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
int  amode_ltmp;
int * amode_tmp=&amode_ltmp;
int ret_tmp= LOCAL_MPI_File_get_amode( fh_tmp, amode_tmp);
amode_conv_r2a(amode,amode_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_get_amode\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_get_amode(R_MPI_File fh,int * amode)
{
#ifdef DEBUG
printf("entre : R_MPI_File_get_amode\n");
#endif
int ret_tmp= LOCAL_MPI_File_get_amode( fh, amode);
#ifdef DEBUG
printf("sort : R_MPI_File_get_amode\n");
#endif
return ret_tmp;
}
int MPI_File_set_info(A_MPI_File fh,A_MPI_Info info);
int (*LOCAL_MPI_File_set_info)(R_MPI_File,R_MPI_Info);

__asm__(
".global PMPI_File_set_info\n"
".weak MPI_File_set_info\n"
".set MPI_File_set_info,PMPI_File_set_info\n"
".extern in_w\n"
".extern A_MPI_File_set_info\n"
".extern R_MPI_File_set_info\n"
".type PMPI_File_set_info,@function\n"
".text\n"
"PMPI_File_set_info:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_set_info\n"
"jmp *A_MPI_File_set_info@GOTPCREL(%rip)\n"
"inwrap_MPI_File_set_info:\n"
"jmp *R_MPI_File_set_info@GOTPCREL(%rip)\n"
".size PMPI_File_set_info,.-PMPI_File_set_info\n"

);

int A_MPI_File_set_info(A_MPI_File fh,A_MPI_Info info)
{
#ifdef DEBUG
printf("entre : A_MPI_File_set_info\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
R_MPI_Info info_tmp;
info_conv_a2r(&info,&info_tmp);
int ret_tmp= LOCAL_MPI_File_set_info( fh_tmp, info_tmp);
file_conv_r2a(&fh,&fh_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_set_info\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_set_info(R_MPI_File fh,R_MPI_Info info)
{
#ifdef DEBUG
printf("entre : R_MPI_File_set_info\n");
#endif
int ret_tmp= LOCAL_MPI_File_set_info( fh, info);
#ifdef DEBUG
printf("sort : R_MPI_File_set_info\n");
#endif
return ret_tmp;
}
int MPI_File_get_info(A_MPI_File fh,A_MPI_Info * info_used);
int (*LOCAL_MPI_File_get_info)(R_MPI_File,R_MPI_Info *);

__asm__(
".global PMPI_File_get_info\n"
".weak MPI_File_get_info\n"
".set MPI_File_get_info,PMPI_File_get_info\n"
".extern in_w\n"
".extern A_MPI_File_get_info\n"
".extern R_MPI_File_get_info\n"
".type PMPI_File_get_info,@function\n"
".text\n"
"PMPI_File_get_info:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_get_info\n"
"jmp *A_MPI_File_get_info@GOTPCREL(%rip)\n"
"inwrap_MPI_File_get_info:\n"
"jmp *R_MPI_File_get_info@GOTPCREL(%rip)\n"
".size PMPI_File_get_info,.-PMPI_File_get_info\n"

);

int A_MPI_File_get_info(A_MPI_File fh,A_MPI_Info * info_used)
{
#ifdef DEBUG
printf("entre : A_MPI_File_get_info\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
R_MPI_Info  info_used_ltmp;
R_MPI_Info * info_used_tmp=&info_used_ltmp;
int ret_tmp= LOCAL_MPI_File_get_info( fh_tmp, info_used_tmp);
file_conv_r2a(&fh,&fh_tmp);
info_conv_r2a(info_used,info_used_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_get_info\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_get_info(R_MPI_File fh,R_MPI_Info * info_used)
{
#ifdef DEBUG
printf("entre : R_MPI_File_get_info\n");
#endif
int ret_tmp= LOCAL_MPI_File_get_info( fh, info_used);
#ifdef DEBUG
printf("sort : R_MPI_File_get_info\n");
#endif
return ret_tmp;
}
int MPI_File_set_view(A_MPI_File fh,A_MPI_Offset disp,A_MPI_Datatype etype,A_MPI_Datatype filetype,char * datarep,A_MPI_Info info);
int (*LOCAL_MPI_File_set_view)(R_MPI_File,R_MPI_Offset,R_MPI_Datatype,R_MPI_Datatype,char *,R_MPI_Info);

__asm__(
".global PMPI_File_set_view\n"
".weak MPI_File_set_view\n"
".set MPI_File_set_view,PMPI_File_set_view\n"
".extern in_w\n"
".extern A_MPI_File_set_view\n"
".extern R_MPI_File_set_view\n"
".type PMPI_File_set_view,@function\n"
".text\n"
"PMPI_File_set_view:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_set_view\n"
"jmp *A_MPI_File_set_view@GOTPCREL(%rip)\n"
"inwrap_MPI_File_set_view:\n"
"jmp *R_MPI_File_set_view@GOTPCREL(%rip)\n"
".size PMPI_File_set_view,.-PMPI_File_set_view\n"

);

int A_MPI_File_set_view(A_MPI_File fh,A_MPI_Offset disp,A_MPI_Datatype etype,A_MPI_Datatype filetype,char * datarep,A_MPI_Info info)
{
#ifdef DEBUG
printf("entre : A_MPI_File_set_view\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
R_MPI_Offset disp_tmp;
disp_tmp = (R_MPI_Offset)disp;
R_MPI_Datatype etype_tmp;
datatype_conv_a2r(&etype,&etype_tmp);
R_MPI_Datatype filetype_tmp;
datatype_conv_a2r(&filetype,&filetype_tmp);


R_MPI_Info info_tmp;
info_conv_a2r(&info,&info_tmp);
int ret_tmp= LOCAL_MPI_File_set_view( fh_tmp, disp_tmp, etype_tmp, filetype_tmp, datarep, info_tmp);
file_conv_r2a(&fh,&fh_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_set_view\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_set_view(R_MPI_File fh,R_MPI_Offset disp,R_MPI_Datatype etype,R_MPI_Datatype filetype,char * datarep,R_MPI_Info info)
{
#ifdef DEBUG
printf("entre : R_MPI_File_set_view\n");
#endif
int ret_tmp= LOCAL_MPI_File_set_view( fh, disp, etype, filetype, datarep, info);
#ifdef DEBUG
printf("sort : R_MPI_File_set_view\n");
#endif
return ret_tmp;
}
int MPI_File_get_view(A_MPI_File fh,A_MPI_Offset * disp,A_MPI_Datatype * etype,A_MPI_Datatype * filetype,char * datarep);
int (*LOCAL_MPI_File_get_view)(R_MPI_File,R_MPI_Offset *,R_MPI_Datatype *,R_MPI_Datatype *,char *);

__asm__(
".global PMPI_File_get_view\n"
".weak MPI_File_get_view\n"
".set MPI_File_get_view,PMPI_File_get_view\n"
".extern in_w\n"
".extern A_MPI_File_get_view\n"
".extern R_MPI_File_get_view\n"
".type PMPI_File_get_view,@function\n"
".text\n"
"PMPI_File_get_view:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_get_view\n"
"jmp *A_MPI_File_get_view@GOTPCREL(%rip)\n"
"inwrap_MPI_File_get_view:\n"
"jmp *R_MPI_File_get_view@GOTPCREL(%rip)\n"
".size PMPI_File_get_view,.-PMPI_File_get_view\n"

);

int A_MPI_File_get_view(A_MPI_File fh,A_MPI_Offset * disp,A_MPI_Datatype * etype,A_MPI_Datatype * filetype,char * datarep)
{
#ifdef DEBUG
printf("entre : A_MPI_File_get_view\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
R_MPI_Offset  disp_ltmp;
R_MPI_Offset * disp_tmp=&disp_ltmp;
R_MPI_Datatype  etype_ltmp;
R_MPI_Datatype * etype_tmp=&etype_ltmp;
R_MPI_Datatype  filetype_ltmp;
R_MPI_Datatype * filetype_tmp=&filetype_ltmp;

int ret_tmp= LOCAL_MPI_File_get_view( fh_tmp, disp_tmp, etype_tmp, filetype_tmp, datarep);
*disp= (A_MPI_Offset ) *disp_tmp;
datatype_conv_r2a(etype,etype_tmp);
datatype_conv_r2a(filetype,filetype_tmp);

in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_get_view\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_get_view(R_MPI_File fh,R_MPI_Offset * disp,R_MPI_Datatype * etype,R_MPI_Datatype * filetype,char * datarep)
{
#ifdef DEBUG
printf("entre : R_MPI_File_get_view\n");
#endif
int ret_tmp= LOCAL_MPI_File_get_view( fh, disp, etype, filetype, datarep);
#ifdef DEBUG
printf("sort : R_MPI_File_get_view\n");
#endif
return ret_tmp;
}
int MPI_File_read_at(A_MPI_File fh,A_MPI_Offset offset,void * buf,int count,A_MPI_Datatype datatype,A_MPI_Status * status);
int (*LOCAL_MPI_File_read_at)(R_MPI_File,R_MPI_Offset,void *,int,R_MPI_Datatype,R_MPI_Status *);

__asm__(
".global PMPI_File_read_at\n"
".weak MPI_File_read_at\n"
".set MPI_File_read_at,PMPI_File_read_at\n"
".extern in_w\n"
".extern A_MPI_File_read_at\n"
".extern R_MPI_File_read_at\n"
".type PMPI_File_read_at,@function\n"
".text\n"
"PMPI_File_read_at:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_read_at\n"
"jmp *A_MPI_File_read_at@GOTPCREL(%rip)\n"
"inwrap_MPI_File_read_at:\n"
"jmp *R_MPI_File_read_at@GOTPCREL(%rip)\n"
".size PMPI_File_read_at,.-PMPI_File_read_at\n"

);

int A_MPI_File_read_at(A_MPI_File fh,A_MPI_Offset offset,void * buf,int count,A_MPI_Datatype datatype,A_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : A_MPI_File_read_at\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
R_MPI_Offset offset_tmp;
offset_tmp = (R_MPI_Offset)offset;
void * buf_tmp;
buffer_conv_a2r(&buf,&buf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
R_MPI_Status  status_ltmp;
R_MPI_Status * status_tmp=&status_ltmp;
int ret_tmp= LOCAL_MPI_File_read_at( fh_tmp, offset_tmp, buf_tmp, count, datatype_tmp, status_tmp);
buffer_conv_r2a(&buf,&buf_tmp);
status_prt_conv_r2a(&status,&status_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_read_at\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_read_at(R_MPI_File fh,R_MPI_Offset offset,void * buf,int count,R_MPI_Datatype datatype,R_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : R_MPI_File_read_at\n");
#endif
int ret_tmp= LOCAL_MPI_File_read_at( fh, offset, buf, count, datatype, status);
#ifdef DEBUG
printf("sort : R_MPI_File_read_at\n");
#endif
return ret_tmp;
}
int MPI_File_read_at_all(A_MPI_File fh,A_MPI_Offset offset,void * buf,int count,A_MPI_Datatype datatype,A_MPI_Status * status);
int (*LOCAL_MPI_File_read_at_all)(R_MPI_File,R_MPI_Offset,void *,int,R_MPI_Datatype,R_MPI_Status *);

__asm__(
".global PMPI_File_read_at_all\n"
".weak MPI_File_read_at_all\n"
".set MPI_File_read_at_all,PMPI_File_read_at_all\n"
".extern in_w\n"
".extern A_MPI_File_read_at_all\n"
".extern R_MPI_File_read_at_all\n"
".type PMPI_File_read_at_all,@function\n"
".text\n"
"PMPI_File_read_at_all:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_read_at_all\n"
"jmp *A_MPI_File_read_at_all@GOTPCREL(%rip)\n"
"inwrap_MPI_File_read_at_all:\n"
"jmp *R_MPI_File_read_at_all@GOTPCREL(%rip)\n"
".size PMPI_File_read_at_all,.-PMPI_File_read_at_all\n"

);

int A_MPI_File_read_at_all(A_MPI_File fh,A_MPI_Offset offset,void * buf,int count,A_MPI_Datatype datatype,A_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : A_MPI_File_read_at_all\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
R_MPI_Offset offset_tmp;
offset_tmp = (R_MPI_Offset)offset;
void * buf_tmp;
buffer_conv_a2r(&buf,&buf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
R_MPI_Status  status_ltmp;
R_MPI_Status * status_tmp=&status_ltmp;
int ret_tmp= LOCAL_MPI_File_read_at_all( fh_tmp, offset_tmp, buf_tmp, count, datatype_tmp, status_tmp);
buffer_conv_r2a(&buf,&buf_tmp);
status_prt_conv_r2a(&status,&status_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_read_at_all\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_read_at_all(R_MPI_File fh,R_MPI_Offset offset,void * buf,int count,R_MPI_Datatype datatype,R_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : R_MPI_File_read_at_all\n");
#endif
int ret_tmp= LOCAL_MPI_File_read_at_all( fh, offset, buf, count, datatype, status);
#ifdef DEBUG
printf("sort : R_MPI_File_read_at_all\n");
#endif
return ret_tmp;
}
int MPI_File_write_at(A_MPI_File fh,A_MPI_Offset offset,void * buf,int count,A_MPI_Datatype datatype,A_MPI_Status * status);
int (*LOCAL_MPI_File_write_at)(R_MPI_File,R_MPI_Offset,void *,int,R_MPI_Datatype,R_MPI_Status *);

__asm__(
".global PMPI_File_write_at\n"
".weak MPI_File_write_at\n"
".set MPI_File_write_at,PMPI_File_write_at\n"
".extern in_w\n"
".extern A_MPI_File_write_at\n"
".extern R_MPI_File_write_at\n"
".type PMPI_File_write_at,@function\n"
".text\n"
"PMPI_File_write_at:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_write_at\n"
"jmp *A_MPI_File_write_at@GOTPCREL(%rip)\n"
"inwrap_MPI_File_write_at:\n"
"jmp *R_MPI_File_write_at@GOTPCREL(%rip)\n"
".size PMPI_File_write_at,.-PMPI_File_write_at\n"

);

int A_MPI_File_write_at(A_MPI_File fh,A_MPI_Offset offset,void * buf,int count,A_MPI_Datatype datatype,A_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : A_MPI_File_write_at\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
R_MPI_Offset offset_tmp;
offset_tmp = (R_MPI_Offset)offset;
void * buf_tmp;
const_buffer_conv_a2r(&buf,&buf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
R_MPI_Status  status_ltmp;
R_MPI_Status * status_tmp=&status_ltmp;
int ret_tmp= LOCAL_MPI_File_write_at( fh_tmp, offset_tmp, buf_tmp, count, datatype_tmp, status_tmp);
file_conv_r2a(&fh,&fh_tmp);
status_prt_conv_r2a(&status,&status_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_write_at\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_write_at(R_MPI_File fh,R_MPI_Offset offset,void * buf,int count,R_MPI_Datatype datatype,R_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : R_MPI_File_write_at\n");
#endif
int ret_tmp= LOCAL_MPI_File_write_at( fh, offset, buf, count, datatype, status);
#ifdef DEBUG
printf("sort : R_MPI_File_write_at\n");
#endif
return ret_tmp;
}
int MPI_File_write_at_all(A_MPI_File fh,A_MPI_Offset offset,void * buf,int count,A_MPI_Datatype datatype,A_MPI_Status * status);
int (*LOCAL_MPI_File_write_at_all)(R_MPI_File,R_MPI_Offset,void *,int,R_MPI_Datatype,R_MPI_Status *);

__asm__(
".global PMPI_File_write_at_all\n"
".weak MPI_File_write_at_all\n"
".set MPI_File_write_at_all,PMPI_File_write_at_all\n"
".extern in_w\n"
".extern A_MPI_File_write_at_all\n"
".extern R_MPI_File_write_at_all\n"
".type PMPI_File_write_at_all,@function\n"
".text\n"
"PMPI_File_write_at_all:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_write_at_all\n"
"jmp *A_MPI_File_write_at_all@GOTPCREL(%rip)\n"
"inwrap_MPI_File_write_at_all:\n"
"jmp *R_MPI_File_write_at_all@GOTPCREL(%rip)\n"
".size PMPI_File_write_at_all,.-PMPI_File_write_at_all\n"

);

int A_MPI_File_write_at_all(A_MPI_File fh,A_MPI_Offset offset,void * buf,int count,A_MPI_Datatype datatype,A_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : A_MPI_File_write_at_all\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
R_MPI_Offset offset_tmp;
offset_tmp = (R_MPI_Offset)offset;
void * buf_tmp;
const_buffer_conv_a2r(&buf,&buf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
R_MPI_Status  status_ltmp;
R_MPI_Status * status_tmp=&status_ltmp;
int ret_tmp= LOCAL_MPI_File_write_at_all( fh_tmp, offset_tmp, buf_tmp, count, datatype_tmp, status_tmp);
file_conv_r2a(&fh,&fh_tmp);
status_prt_conv_r2a(&status,&status_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_write_at_all\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_write_at_all(R_MPI_File fh,R_MPI_Offset offset,void * buf,int count,R_MPI_Datatype datatype,R_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : R_MPI_File_write_at_all\n");
#endif
int ret_tmp= LOCAL_MPI_File_write_at_all( fh, offset, buf, count, datatype, status);
#ifdef DEBUG
printf("sort : R_MPI_File_write_at_all\n");
#endif
return ret_tmp;
}
int MPI_File_iread_at(A_MPI_File fh,A_MPI_Offset offset,void * buf,int count,A_MPI_Datatype datatype,A_MPI_Request * request);
int (*LOCAL_MPI_File_iread_at)(R_MPI_File,R_MPI_Offset,void *,int,R_MPI_Datatype,R_MPI_Request *);

__asm__(
".global PMPI_File_iread_at\n"
".weak MPI_File_iread_at\n"
".set MPI_File_iread_at,PMPI_File_iread_at\n"
".extern in_w\n"
".extern A_MPI_File_iread_at\n"
".extern R_MPI_File_iread_at\n"
".type PMPI_File_iread_at,@function\n"
".text\n"
"PMPI_File_iread_at:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_iread_at\n"
"jmp *A_MPI_File_iread_at@GOTPCREL(%rip)\n"
"inwrap_MPI_File_iread_at:\n"
"jmp *R_MPI_File_iread_at@GOTPCREL(%rip)\n"
".size PMPI_File_iread_at,.-PMPI_File_iread_at\n"

);

int A_MPI_File_iread_at(A_MPI_File fh,A_MPI_Offset offset,void * buf,int count,A_MPI_Datatype datatype,A_MPI_Request * request)
{
#ifdef DEBUG
printf("entre : A_MPI_File_iread_at\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
R_MPI_Offset offset_tmp;
offset_tmp = (R_MPI_Offset)offset;
void * buf_tmp;
buffer_conv_a2r(&buf,&buf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
R_MPI_Request  request_ltmp;
R_MPI_Request * request_tmp=&request_ltmp;
int ret_tmp= LOCAL_MPI_File_iread_at( fh_tmp, offset_tmp, buf_tmp, count, datatype_tmp, request_tmp);
buffer_conv_r2a(&buf,&buf_tmp);
if(ret_tmp == R_MPI_SUCCESS){
request_ptr_conv_r2a(&request,&request_tmp);
}
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_iread_at\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_iread_at(R_MPI_File fh,R_MPI_Offset offset,void * buf,int count,R_MPI_Datatype datatype,R_MPI_Request * request)
{
#ifdef DEBUG
printf("entre : R_MPI_File_iread_at\n");
#endif
int ret_tmp= LOCAL_MPI_File_iread_at( fh, offset, buf, count, datatype, request);
#ifdef DEBUG
printf("sort : R_MPI_File_iread_at\n");
#endif
return ret_tmp;
}
int MPI_File_iwrite_at(A_MPI_File fh,A_MPI_Offset offset,void * buf,int count,A_MPI_Datatype datatype,A_MPI_Request * request);
int (*LOCAL_MPI_File_iwrite_at)(R_MPI_File,R_MPI_Offset,void *,int,R_MPI_Datatype,R_MPI_Request *);

__asm__(
".global PMPI_File_iwrite_at\n"
".weak MPI_File_iwrite_at\n"
".set MPI_File_iwrite_at,PMPI_File_iwrite_at\n"
".extern in_w\n"
".extern A_MPI_File_iwrite_at\n"
".extern R_MPI_File_iwrite_at\n"
".type PMPI_File_iwrite_at,@function\n"
".text\n"
"PMPI_File_iwrite_at:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_iwrite_at\n"
"jmp *A_MPI_File_iwrite_at@GOTPCREL(%rip)\n"
"inwrap_MPI_File_iwrite_at:\n"
"jmp *R_MPI_File_iwrite_at@GOTPCREL(%rip)\n"
".size PMPI_File_iwrite_at,.-PMPI_File_iwrite_at\n"

);

int A_MPI_File_iwrite_at(A_MPI_File fh,A_MPI_Offset offset,void * buf,int count,A_MPI_Datatype datatype,A_MPI_Request * request)
{
#ifdef DEBUG
printf("entre : A_MPI_File_iwrite_at\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
R_MPI_Offset offset_tmp;
offset_tmp = (R_MPI_Offset)offset;
void * buf_tmp;
const_buffer_conv_a2r(&buf,&buf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
R_MPI_Request  request_ltmp;
R_MPI_Request * request_tmp=&request_ltmp;
int ret_tmp= LOCAL_MPI_File_iwrite_at( fh_tmp, offset_tmp, buf_tmp, count, datatype_tmp, request_tmp);
file_conv_r2a(&fh,&fh_tmp);
if(ret_tmp == R_MPI_SUCCESS){
request_ptr_conv_r2a(&request,&request_tmp);
}
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_iwrite_at\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_iwrite_at(R_MPI_File fh,R_MPI_Offset offset,void * buf,int count,R_MPI_Datatype datatype,R_MPI_Request * request)
{
#ifdef DEBUG
printf("entre : R_MPI_File_iwrite_at\n");
#endif
int ret_tmp= LOCAL_MPI_File_iwrite_at( fh, offset, buf, count, datatype, request);
#ifdef DEBUG
printf("sort : R_MPI_File_iwrite_at\n");
#endif
return ret_tmp;
}
int MPI_File_read(A_MPI_File fh,void * buf,int count,A_MPI_Datatype datatype,A_MPI_Status * status);
int (*LOCAL_MPI_File_read)(R_MPI_File,void *,int,R_MPI_Datatype,R_MPI_Status *);

__asm__(
".global PMPI_File_read\n"
".weak MPI_File_read\n"
".set MPI_File_read,PMPI_File_read\n"
".extern in_w\n"
".extern A_MPI_File_read\n"
".extern R_MPI_File_read\n"
".type PMPI_File_read,@function\n"
".text\n"
"PMPI_File_read:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_read\n"
"jmp *A_MPI_File_read@GOTPCREL(%rip)\n"
"inwrap_MPI_File_read:\n"
"jmp *R_MPI_File_read@GOTPCREL(%rip)\n"
".size PMPI_File_read,.-PMPI_File_read\n"

);

int A_MPI_File_read(A_MPI_File fh,void * buf,int count,A_MPI_Datatype datatype,A_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : A_MPI_File_read\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
void * buf_tmp;
buffer_conv_a2r(&buf,&buf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
R_MPI_Status  status_ltmp;
R_MPI_Status * status_tmp=&status_ltmp;
int ret_tmp= LOCAL_MPI_File_read( fh_tmp, buf_tmp, count, datatype_tmp, status_tmp);
file_conv_r2a(&fh,&fh_tmp);
buffer_conv_r2a(&buf,&buf_tmp);
status_prt_conv_r2a(&status,&status_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_read\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_read(R_MPI_File fh,void * buf,int count,R_MPI_Datatype datatype,R_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : R_MPI_File_read\n");
#endif
int ret_tmp= LOCAL_MPI_File_read( fh, buf, count, datatype, status);
#ifdef DEBUG
printf("sort : R_MPI_File_read\n");
#endif
return ret_tmp;
}
int MPI_File_read_all(A_MPI_File fh,void * buf,int count,A_MPI_Datatype datatype,A_MPI_Status * status);
int (*LOCAL_MPI_File_read_all)(R_MPI_File,void *,int,R_MPI_Datatype,R_MPI_Status *);

__asm__(
".global PMPI_File_read_all\n"
".weak MPI_File_read_all\n"
".set MPI_File_read_all,PMPI_File_read_all\n"
".extern in_w\n"
".extern A_MPI_File_read_all\n"
".extern R_MPI_File_read_all\n"
".type PMPI_File_read_all,@function\n"
".text\n"
"PMPI_File_read_all:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_read_all\n"
"jmp *A_MPI_File_read_all@GOTPCREL(%rip)\n"
"inwrap_MPI_File_read_all:\n"
"jmp *R_MPI_File_read_all@GOTPCREL(%rip)\n"
".size PMPI_File_read_all,.-PMPI_File_read_all\n"

);

int A_MPI_File_read_all(A_MPI_File fh,void * buf,int count,A_MPI_Datatype datatype,A_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : A_MPI_File_read_all\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
void * buf_tmp;
buffer_conv_a2r(&buf,&buf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
R_MPI_Status  status_ltmp;
R_MPI_Status * status_tmp=&status_ltmp;
int ret_tmp= LOCAL_MPI_File_read_all( fh_tmp, buf_tmp, count, datatype_tmp, status_tmp);
file_conv_r2a(&fh,&fh_tmp);
buffer_conv_r2a(&buf,&buf_tmp);
status_prt_conv_r2a(&status,&status_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_read_all\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_read_all(R_MPI_File fh,void * buf,int count,R_MPI_Datatype datatype,R_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : R_MPI_File_read_all\n");
#endif
int ret_tmp= LOCAL_MPI_File_read_all( fh, buf, count, datatype, status);
#ifdef DEBUG
printf("sort : R_MPI_File_read_all\n");
#endif
return ret_tmp;
}
int MPI_File_write(A_MPI_File fh,void * buf,int count,A_MPI_Datatype datatype,A_MPI_Status * status);
int (*LOCAL_MPI_File_write)(R_MPI_File,void *,int,R_MPI_Datatype,R_MPI_Status *);

__asm__(
".global PMPI_File_write\n"
".weak MPI_File_write\n"
".set MPI_File_write,PMPI_File_write\n"
".extern in_w\n"
".extern A_MPI_File_write\n"
".extern R_MPI_File_write\n"
".type PMPI_File_write,@function\n"
".text\n"
"PMPI_File_write:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_write\n"
"jmp *A_MPI_File_write@GOTPCREL(%rip)\n"
"inwrap_MPI_File_write:\n"
"jmp *R_MPI_File_write@GOTPCREL(%rip)\n"
".size PMPI_File_write,.-PMPI_File_write\n"

);

int A_MPI_File_write(A_MPI_File fh,void * buf,int count,A_MPI_Datatype datatype,A_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : A_MPI_File_write\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
void * buf_tmp;
const_buffer_conv_a2r(&buf,&buf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
R_MPI_Status  status_ltmp;
R_MPI_Status * status_tmp=&status_ltmp;
int ret_tmp= LOCAL_MPI_File_write( fh_tmp, buf_tmp, count, datatype_tmp, status_tmp);
file_conv_r2a(&fh,&fh_tmp);
status_prt_conv_r2a(&status,&status_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_write\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_write(R_MPI_File fh,void * buf,int count,R_MPI_Datatype datatype,R_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : R_MPI_File_write\n");
#endif
int ret_tmp= LOCAL_MPI_File_write( fh, buf, count, datatype, status);
#ifdef DEBUG
printf("sort : R_MPI_File_write\n");
#endif
return ret_tmp;
}
int MPI_File_write_all(A_MPI_File fh,void * buf,int count,A_MPI_Datatype datatype,A_MPI_Status * status);
int (*LOCAL_MPI_File_write_all)(R_MPI_File,void *,int,R_MPI_Datatype,R_MPI_Status *);

__asm__(
".global PMPI_File_write_all\n"
".weak MPI_File_write_all\n"
".set MPI_File_write_all,PMPI_File_write_all\n"
".extern in_w\n"
".extern A_MPI_File_write_all\n"
".extern R_MPI_File_write_all\n"
".type PMPI_File_write_all,@function\n"
".text\n"
"PMPI_File_write_all:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_write_all\n"
"jmp *A_MPI_File_write_all@GOTPCREL(%rip)\n"
"inwrap_MPI_File_write_all:\n"
"jmp *R_MPI_File_write_all@GOTPCREL(%rip)\n"
".size PMPI_File_write_all,.-PMPI_File_write_all\n"

);

int A_MPI_File_write_all(A_MPI_File fh,void * buf,int count,A_MPI_Datatype datatype,A_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : A_MPI_File_write_all\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
void * buf_tmp;
const_buffer_conv_a2r(&buf,&buf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
R_MPI_Status  status_ltmp;
R_MPI_Status * status_tmp=&status_ltmp;
int ret_tmp= LOCAL_MPI_File_write_all( fh_tmp, buf_tmp, count, datatype_tmp, status_tmp);
file_conv_r2a(&fh,&fh_tmp);
status_prt_conv_r2a(&status,&status_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_write_all\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_write_all(R_MPI_File fh,void * buf,int count,R_MPI_Datatype datatype,R_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : R_MPI_File_write_all\n");
#endif
int ret_tmp= LOCAL_MPI_File_write_all( fh, buf, count, datatype, status);
#ifdef DEBUG
printf("sort : R_MPI_File_write_all\n");
#endif
return ret_tmp;
}
int MPI_File_iread(A_MPI_File fh,void * buf,int count,A_MPI_Datatype datatype,A_MPI_Request * request);
int (*LOCAL_MPI_File_iread)(R_MPI_File,void *,int,R_MPI_Datatype,R_MPI_Request *);

__asm__(
".global PMPI_File_iread\n"
".weak MPI_File_iread\n"
".set MPI_File_iread,PMPI_File_iread\n"
".extern in_w\n"
".extern A_MPI_File_iread\n"
".extern R_MPI_File_iread\n"
".type PMPI_File_iread,@function\n"
".text\n"
"PMPI_File_iread:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_iread\n"
"jmp *A_MPI_File_iread@GOTPCREL(%rip)\n"
"inwrap_MPI_File_iread:\n"
"jmp *R_MPI_File_iread@GOTPCREL(%rip)\n"
".size PMPI_File_iread,.-PMPI_File_iread\n"

);

int A_MPI_File_iread(A_MPI_File fh,void * buf,int count,A_MPI_Datatype datatype,A_MPI_Request * request)
{
#ifdef DEBUG
printf("entre : A_MPI_File_iread\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
void * buf_tmp;
buffer_conv_a2r(&buf,&buf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
R_MPI_Request  request_ltmp;
R_MPI_Request * request_tmp=&request_ltmp;
int ret_tmp= LOCAL_MPI_File_iread( fh_tmp, buf_tmp, count, datatype_tmp, request_tmp);
file_conv_r2a(&fh,&fh_tmp);
buffer_conv_r2a(&buf,&buf_tmp);
if(ret_tmp == R_MPI_SUCCESS){
request_ptr_conv_r2a(&request,&request_tmp);
}
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_iread\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_iread(R_MPI_File fh,void * buf,int count,R_MPI_Datatype datatype,R_MPI_Request * request)
{
#ifdef DEBUG
printf("entre : R_MPI_File_iread\n");
#endif
int ret_tmp= LOCAL_MPI_File_iread( fh, buf, count, datatype, request);
#ifdef DEBUG
printf("sort : R_MPI_File_iread\n");
#endif
return ret_tmp;
}
int MPI_File_iwrite(A_MPI_File fh,void * buf,int count,A_MPI_Datatype datatype,A_MPI_Request * request);
int (*LOCAL_MPI_File_iwrite)(R_MPI_File,void *,int,R_MPI_Datatype,R_MPI_Request *);

__asm__(
".global PMPI_File_iwrite\n"
".weak MPI_File_iwrite\n"
".set MPI_File_iwrite,PMPI_File_iwrite\n"
".extern in_w\n"
".extern A_MPI_File_iwrite\n"
".extern R_MPI_File_iwrite\n"
".type PMPI_File_iwrite,@function\n"
".text\n"
"PMPI_File_iwrite:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_iwrite\n"
"jmp *A_MPI_File_iwrite@GOTPCREL(%rip)\n"
"inwrap_MPI_File_iwrite:\n"
"jmp *R_MPI_File_iwrite@GOTPCREL(%rip)\n"
".size PMPI_File_iwrite,.-PMPI_File_iwrite\n"

);

int A_MPI_File_iwrite(A_MPI_File fh,void * buf,int count,A_MPI_Datatype datatype,A_MPI_Request * request)
{
#ifdef DEBUG
printf("entre : A_MPI_File_iwrite\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
void * buf_tmp;
const_buffer_conv_a2r(&buf,&buf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
R_MPI_Request  request_ltmp;
R_MPI_Request * request_tmp=&request_ltmp;
int ret_tmp= LOCAL_MPI_File_iwrite( fh_tmp, buf_tmp, count, datatype_tmp, request_tmp);
file_conv_r2a(&fh,&fh_tmp);
if(ret_tmp == R_MPI_SUCCESS){
request_ptr_conv_r2a(&request,&request_tmp);
}
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_iwrite\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_iwrite(R_MPI_File fh,void * buf,int count,R_MPI_Datatype datatype,R_MPI_Request * request)
{
#ifdef DEBUG
printf("entre : R_MPI_File_iwrite\n");
#endif
int ret_tmp= LOCAL_MPI_File_iwrite( fh, buf, count, datatype, request);
#ifdef DEBUG
printf("sort : R_MPI_File_iwrite\n");
#endif
return ret_tmp;
}
int MPI_File_seek(A_MPI_File fh,A_MPI_Offset offset,int whence);
int (*LOCAL_MPI_File_seek)(R_MPI_File,R_MPI_Offset,int);

__asm__(
".global PMPI_File_seek\n"
".weak MPI_File_seek\n"
".set MPI_File_seek,PMPI_File_seek\n"
".extern in_w\n"
".extern A_MPI_File_seek\n"
".extern R_MPI_File_seek\n"
".type PMPI_File_seek,@function\n"
".text\n"
"PMPI_File_seek:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_seek\n"
"jmp *A_MPI_File_seek@GOTPCREL(%rip)\n"
"inwrap_MPI_File_seek:\n"
"jmp *R_MPI_File_seek@GOTPCREL(%rip)\n"
".size PMPI_File_seek,.-PMPI_File_seek\n"

);

int A_MPI_File_seek(A_MPI_File fh,A_MPI_Offset offset,int whence)
{
#ifdef DEBUG
printf("entre : A_MPI_File_seek\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
R_MPI_Offset offset_tmp;
offset_tmp = (R_MPI_Offset)offset;


int ret_tmp= LOCAL_MPI_File_seek( fh_tmp, offset_tmp, whence);
file_conv_r2a(&fh,&fh_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_seek\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_seek(R_MPI_File fh,R_MPI_Offset offset,int whence)
{
#ifdef DEBUG
printf("entre : R_MPI_File_seek\n");
#endif
int ret_tmp= LOCAL_MPI_File_seek( fh, offset, whence);
#ifdef DEBUG
printf("sort : R_MPI_File_seek\n");
#endif
return ret_tmp;
}
int MPI_File_get_position(A_MPI_File fh,A_MPI_Offset * offset);
int (*LOCAL_MPI_File_get_position)(R_MPI_File,R_MPI_Offset *);

__asm__(
".global PMPI_File_get_position\n"
".weak MPI_File_get_position\n"
".set MPI_File_get_position,PMPI_File_get_position\n"
".extern in_w\n"
".extern A_MPI_File_get_position\n"
".extern R_MPI_File_get_position\n"
".type PMPI_File_get_position,@function\n"
".text\n"
"PMPI_File_get_position:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_get_position\n"
"jmp *A_MPI_File_get_position@GOTPCREL(%rip)\n"
"inwrap_MPI_File_get_position:\n"
"jmp *R_MPI_File_get_position@GOTPCREL(%rip)\n"
".size PMPI_File_get_position,.-PMPI_File_get_position\n"

);

int A_MPI_File_get_position(A_MPI_File fh,A_MPI_Offset * offset)
{
#ifdef DEBUG
printf("entre : A_MPI_File_get_position\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
R_MPI_Offset  offset_ltmp;
R_MPI_Offset * offset_tmp=&offset_ltmp;
int ret_tmp= LOCAL_MPI_File_get_position( fh_tmp, offset_tmp);
*offset= (A_MPI_Offset ) *offset_tmp;
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_get_position\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_get_position(R_MPI_File fh,R_MPI_Offset * offset)
{
#ifdef DEBUG
printf("entre : R_MPI_File_get_position\n");
#endif
int ret_tmp= LOCAL_MPI_File_get_position( fh, offset);
#ifdef DEBUG
printf("sort : R_MPI_File_get_position\n");
#endif
return ret_tmp;
}
int MPI_File_get_byte_offset(A_MPI_File fh,A_MPI_Offset offset,A_MPI_Offset * disp);
int (*LOCAL_MPI_File_get_byte_offset)(R_MPI_File,R_MPI_Offset,R_MPI_Offset *);

__asm__(
".global PMPI_File_get_byte_offset\n"
".weak MPI_File_get_byte_offset\n"
".set MPI_File_get_byte_offset,PMPI_File_get_byte_offset\n"
".extern in_w\n"
".extern A_MPI_File_get_byte_offset\n"
".extern R_MPI_File_get_byte_offset\n"
".type PMPI_File_get_byte_offset,@function\n"
".text\n"
"PMPI_File_get_byte_offset:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_get_byte_offset\n"
"jmp *A_MPI_File_get_byte_offset@GOTPCREL(%rip)\n"
"inwrap_MPI_File_get_byte_offset:\n"
"jmp *R_MPI_File_get_byte_offset@GOTPCREL(%rip)\n"
".size PMPI_File_get_byte_offset,.-PMPI_File_get_byte_offset\n"

);

int A_MPI_File_get_byte_offset(A_MPI_File fh,A_MPI_Offset offset,A_MPI_Offset * disp)
{
#ifdef DEBUG
printf("entre : A_MPI_File_get_byte_offset\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
R_MPI_Offset offset_tmp;
offset_tmp = (R_MPI_Offset)offset;
R_MPI_Offset  disp_ltmp;
R_MPI_Offset * disp_tmp=&disp_ltmp;
int ret_tmp= LOCAL_MPI_File_get_byte_offset( fh_tmp, offset_tmp, disp_tmp);
*disp= (A_MPI_Offset ) *disp_tmp;
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_get_byte_offset\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_get_byte_offset(R_MPI_File fh,R_MPI_Offset offset,R_MPI_Offset * disp)
{
#ifdef DEBUG
printf("entre : R_MPI_File_get_byte_offset\n");
#endif
int ret_tmp= LOCAL_MPI_File_get_byte_offset( fh, offset, disp);
#ifdef DEBUG
printf("sort : R_MPI_File_get_byte_offset\n");
#endif
return ret_tmp;
}
int MPI_File_read_shared(A_MPI_File fh,void * buf,int count,A_MPI_Datatype datatype,A_MPI_Status * status);
int (*LOCAL_MPI_File_read_shared)(R_MPI_File,void *,int,R_MPI_Datatype,R_MPI_Status *);

__asm__(
".global PMPI_File_read_shared\n"
".weak MPI_File_read_shared\n"
".set MPI_File_read_shared,PMPI_File_read_shared\n"
".extern in_w\n"
".extern A_MPI_File_read_shared\n"
".extern R_MPI_File_read_shared\n"
".type PMPI_File_read_shared,@function\n"
".text\n"
"PMPI_File_read_shared:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_read_shared\n"
"jmp *A_MPI_File_read_shared@GOTPCREL(%rip)\n"
"inwrap_MPI_File_read_shared:\n"
"jmp *R_MPI_File_read_shared@GOTPCREL(%rip)\n"
".size PMPI_File_read_shared,.-PMPI_File_read_shared\n"

);

int A_MPI_File_read_shared(A_MPI_File fh,void * buf,int count,A_MPI_Datatype datatype,A_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : A_MPI_File_read_shared\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
void * buf_tmp;
buffer_conv_a2r(&buf,&buf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
R_MPI_Status  status_ltmp;
R_MPI_Status * status_tmp=&status_ltmp;
int ret_tmp= LOCAL_MPI_File_read_shared( fh_tmp, buf_tmp, count, datatype_tmp, status_tmp);
file_conv_r2a(&fh,&fh_tmp);
buffer_conv_r2a(&buf,&buf_tmp);
status_prt_conv_r2a(&status,&status_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_read_shared\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_read_shared(R_MPI_File fh,void * buf,int count,R_MPI_Datatype datatype,R_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : R_MPI_File_read_shared\n");
#endif
int ret_tmp= LOCAL_MPI_File_read_shared( fh, buf, count, datatype, status);
#ifdef DEBUG
printf("sort : R_MPI_File_read_shared\n");
#endif
return ret_tmp;
}
int MPI_File_write_shared(A_MPI_File fh,void * buf,int count,A_MPI_Datatype datatype,A_MPI_Status * status);
int (*LOCAL_MPI_File_write_shared)(R_MPI_File,void *,int,R_MPI_Datatype,R_MPI_Status *);

__asm__(
".global PMPI_File_write_shared\n"
".weak MPI_File_write_shared\n"
".set MPI_File_write_shared,PMPI_File_write_shared\n"
".extern in_w\n"
".extern A_MPI_File_write_shared\n"
".extern R_MPI_File_write_shared\n"
".type PMPI_File_write_shared,@function\n"
".text\n"
"PMPI_File_write_shared:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_write_shared\n"
"jmp *A_MPI_File_write_shared@GOTPCREL(%rip)\n"
"inwrap_MPI_File_write_shared:\n"
"jmp *R_MPI_File_write_shared@GOTPCREL(%rip)\n"
".size PMPI_File_write_shared,.-PMPI_File_write_shared\n"

);

int A_MPI_File_write_shared(A_MPI_File fh,void * buf,int count,A_MPI_Datatype datatype,A_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : A_MPI_File_write_shared\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
void * buf_tmp;
const_buffer_conv_a2r(&buf,&buf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
R_MPI_Status  status_ltmp;
R_MPI_Status * status_tmp=&status_ltmp;
int ret_tmp= LOCAL_MPI_File_write_shared( fh_tmp, buf_tmp, count, datatype_tmp, status_tmp);
file_conv_r2a(&fh,&fh_tmp);
status_prt_conv_r2a(&status,&status_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_write_shared\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_write_shared(R_MPI_File fh,void * buf,int count,R_MPI_Datatype datatype,R_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : R_MPI_File_write_shared\n");
#endif
int ret_tmp= LOCAL_MPI_File_write_shared( fh, buf, count, datatype, status);
#ifdef DEBUG
printf("sort : R_MPI_File_write_shared\n");
#endif
return ret_tmp;
}
int MPI_File_iread_shared(A_MPI_File fh,void * buf,int count,A_MPI_Datatype datatype,A_MPI_Request * request);
int (*LOCAL_MPI_File_iread_shared)(R_MPI_File,void *,int,R_MPI_Datatype,R_MPI_Request *);

__asm__(
".global PMPI_File_iread_shared\n"
".weak MPI_File_iread_shared\n"
".set MPI_File_iread_shared,PMPI_File_iread_shared\n"
".extern in_w\n"
".extern A_MPI_File_iread_shared\n"
".extern R_MPI_File_iread_shared\n"
".type PMPI_File_iread_shared,@function\n"
".text\n"
"PMPI_File_iread_shared:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_iread_shared\n"
"jmp *A_MPI_File_iread_shared@GOTPCREL(%rip)\n"
"inwrap_MPI_File_iread_shared:\n"
"jmp *R_MPI_File_iread_shared@GOTPCREL(%rip)\n"
".size PMPI_File_iread_shared,.-PMPI_File_iread_shared\n"

);

int A_MPI_File_iread_shared(A_MPI_File fh,void * buf,int count,A_MPI_Datatype datatype,A_MPI_Request * request)
{
#ifdef DEBUG
printf("entre : A_MPI_File_iread_shared\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
void * buf_tmp;
buffer_conv_a2r(&buf,&buf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
R_MPI_Request  request_ltmp;
R_MPI_Request * request_tmp=&request_ltmp;
int ret_tmp= LOCAL_MPI_File_iread_shared( fh_tmp, buf_tmp, count, datatype_tmp, request_tmp);
file_conv_r2a(&fh,&fh_tmp);
buffer_conv_r2a(&buf,&buf_tmp);
if(ret_tmp == R_MPI_SUCCESS){
request_ptr_conv_r2a(&request,&request_tmp);
}
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_iread_shared\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_iread_shared(R_MPI_File fh,void * buf,int count,R_MPI_Datatype datatype,R_MPI_Request * request)
{
#ifdef DEBUG
printf("entre : R_MPI_File_iread_shared\n");
#endif
int ret_tmp= LOCAL_MPI_File_iread_shared( fh, buf, count, datatype, request);
#ifdef DEBUG
printf("sort : R_MPI_File_iread_shared\n");
#endif
return ret_tmp;
}
int MPI_File_iwrite_shared(A_MPI_File fh,void * buf,int count,A_MPI_Datatype datatype,A_MPI_Request * request);
int (*LOCAL_MPI_File_iwrite_shared)(R_MPI_File,void *,int,R_MPI_Datatype,R_MPI_Request *);

__asm__(
".global PMPI_File_iwrite_shared\n"
".weak MPI_File_iwrite_shared\n"
".set MPI_File_iwrite_shared,PMPI_File_iwrite_shared\n"
".extern in_w\n"
".extern A_MPI_File_iwrite_shared\n"
".extern R_MPI_File_iwrite_shared\n"
".type PMPI_File_iwrite_shared,@function\n"
".text\n"
"PMPI_File_iwrite_shared:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_iwrite_shared\n"
"jmp *A_MPI_File_iwrite_shared@GOTPCREL(%rip)\n"
"inwrap_MPI_File_iwrite_shared:\n"
"jmp *R_MPI_File_iwrite_shared@GOTPCREL(%rip)\n"
".size PMPI_File_iwrite_shared,.-PMPI_File_iwrite_shared\n"

);

int A_MPI_File_iwrite_shared(A_MPI_File fh,void * buf,int count,A_MPI_Datatype datatype,A_MPI_Request * request)
{
#ifdef DEBUG
printf("entre : A_MPI_File_iwrite_shared\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
void * buf_tmp;
const_buffer_conv_a2r(&buf,&buf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
R_MPI_Request  request_ltmp;
R_MPI_Request * request_tmp=&request_ltmp;
int ret_tmp= LOCAL_MPI_File_iwrite_shared( fh_tmp, buf_tmp, count, datatype_tmp, request_tmp);
file_conv_r2a(&fh,&fh_tmp);
if(ret_tmp == R_MPI_SUCCESS){
request_ptr_conv_r2a(&request,&request_tmp);
}
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_iwrite_shared\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_iwrite_shared(R_MPI_File fh,void * buf,int count,R_MPI_Datatype datatype,R_MPI_Request * request)
{
#ifdef DEBUG
printf("entre : R_MPI_File_iwrite_shared\n");
#endif
int ret_tmp= LOCAL_MPI_File_iwrite_shared( fh, buf, count, datatype, request);
#ifdef DEBUG
printf("sort : R_MPI_File_iwrite_shared\n");
#endif
return ret_tmp;
}
int MPI_File_read_ordered(A_MPI_File fh,void * buf,int count,A_MPI_Datatype datatype,A_MPI_Status * status);
int (*LOCAL_MPI_File_read_ordered)(R_MPI_File,void *,int,R_MPI_Datatype,R_MPI_Status *);

__asm__(
".global PMPI_File_read_ordered\n"
".weak MPI_File_read_ordered\n"
".set MPI_File_read_ordered,PMPI_File_read_ordered\n"
".extern in_w\n"
".extern A_MPI_File_read_ordered\n"
".extern R_MPI_File_read_ordered\n"
".type PMPI_File_read_ordered,@function\n"
".text\n"
"PMPI_File_read_ordered:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_read_ordered\n"
"jmp *A_MPI_File_read_ordered@GOTPCREL(%rip)\n"
"inwrap_MPI_File_read_ordered:\n"
"jmp *R_MPI_File_read_ordered@GOTPCREL(%rip)\n"
".size PMPI_File_read_ordered,.-PMPI_File_read_ordered\n"

);

int A_MPI_File_read_ordered(A_MPI_File fh,void * buf,int count,A_MPI_Datatype datatype,A_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : A_MPI_File_read_ordered\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
void * buf_tmp;
buffer_conv_a2r(&buf,&buf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
R_MPI_Status  status_ltmp;
R_MPI_Status * status_tmp=&status_ltmp;
int ret_tmp= LOCAL_MPI_File_read_ordered( fh_tmp, buf_tmp, count, datatype_tmp, status_tmp);
file_conv_r2a(&fh,&fh_tmp);
buffer_conv_r2a(&buf,&buf_tmp);
status_prt_conv_r2a(&status,&status_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_read_ordered\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_read_ordered(R_MPI_File fh,void * buf,int count,R_MPI_Datatype datatype,R_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : R_MPI_File_read_ordered\n");
#endif
int ret_tmp= LOCAL_MPI_File_read_ordered( fh, buf, count, datatype, status);
#ifdef DEBUG
printf("sort : R_MPI_File_read_ordered\n");
#endif
return ret_tmp;
}
int MPI_File_write_ordered(A_MPI_File fh,void * buf,int count,A_MPI_Datatype datatype,A_MPI_Status * status);
int (*LOCAL_MPI_File_write_ordered)(R_MPI_File,void *,int,R_MPI_Datatype,R_MPI_Status *);

__asm__(
".global PMPI_File_write_ordered\n"
".weak MPI_File_write_ordered\n"
".set MPI_File_write_ordered,PMPI_File_write_ordered\n"
".extern in_w\n"
".extern A_MPI_File_write_ordered\n"
".extern R_MPI_File_write_ordered\n"
".type PMPI_File_write_ordered,@function\n"
".text\n"
"PMPI_File_write_ordered:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_write_ordered\n"
"jmp *A_MPI_File_write_ordered@GOTPCREL(%rip)\n"
"inwrap_MPI_File_write_ordered:\n"
"jmp *R_MPI_File_write_ordered@GOTPCREL(%rip)\n"
".size PMPI_File_write_ordered,.-PMPI_File_write_ordered\n"

);

int A_MPI_File_write_ordered(A_MPI_File fh,void * buf,int count,A_MPI_Datatype datatype,A_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : A_MPI_File_write_ordered\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
void * buf_tmp;
const_buffer_conv_a2r(&buf,&buf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
R_MPI_Status  status_ltmp;
R_MPI_Status * status_tmp=&status_ltmp;
int ret_tmp= LOCAL_MPI_File_write_ordered( fh_tmp, buf_tmp, count, datatype_tmp, status_tmp);
file_conv_r2a(&fh,&fh_tmp);
status_prt_conv_r2a(&status,&status_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_write_ordered\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_write_ordered(R_MPI_File fh,void * buf,int count,R_MPI_Datatype datatype,R_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : R_MPI_File_write_ordered\n");
#endif
int ret_tmp= LOCAL_MPI_File_write_ordered( fh, buf, count, datatype, status);
#ifdef DEBUG
printf("sort : R_MPI_File_write_ordered\n");
#endif
return ret_tmp;
}
int MPI_File_seek_shared(A_MPI_File fh,A_MPI_Offset offset,int whence);
int (*LOCAL_MPI_File_seek_shared)(R_MPI_File,R_MPI_Offset,int);

__asm__(
".global PMPI_File_seek_shared\n"
".weak MPI_File_seek_shared\n"
".set MPI_File_seek_shared,PMPI_File_seek_shared\n"
".extern in_w\n"
".extern A_MPI_File_seek_shared\n"
".extern R_MPI_File_seek_shared\n"
".type PMPI_File_seek_shared,@function\n"
".text\n"
"PMPI_File_seek_shared:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_seek_shared\n"
"jmp *A_MPI_File_seek_shared@GOTPCREL(%rip)\n"
"inwrap_MPI_File_seek_shared:\n"
"jmp *R_MPI_File_seek_shared@GOTPCREL(%rip)\n"
".size PMPI_File_seek_shared,.-PMPI_File_seek_shared\n"

);

int A_MPI_File_seek_shared(A_MPI_File fh,A_MPI_Offset offset,int whence)
{
#ifdef DEBUG
printf("entre : A_MPI_File_seek_shared\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
R_MPI_Offset offset_tmp;
offset_tmp = (R_MPI_Offset)offset;


int ret_tmp= LOCAL_MPI_File_seek_shared( fh_tmp, offset_tmp, whence);
file_conv_r2a(&fh,&fh_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_seek_shared\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_seek_shared(R_MPI_File fh,R_MPI_Offset offset,int whence)
{
#ifdef DEBUG
printf("entre : R_MPI_File_seek_shared\n");
#endif
int ret_tmp= LOCAL_MPI_File_seek_shared( fh, offset, whence);
#ifdef DEBUG
printf("sort : R_MPI_File_seek_shared\n");
#endif
return ret_tmp;
}
int MPI_File_get_position_shared(A_MPI_File fh,A_MPI_Offset * offset);
int (*LOCAL_MPI_File_get_position_shared)(R_MPI_File,R_MPI_Offset *);

__asm__(
".global PMPI_File_get_position_shared\n"
".weak MPI_File_get_position_shared\n"
".set MPI_File_get_position_shared,PMPI_File_get_position_shared\n"
".extern in_w\n"
".extern A_MPI_File_get_position_shared\n"
".extern R_MPI_File_get_position_shared\n"
".type PMPI_File_get_position_shared,@function\n"
".text\n"
"PMPI_File_get_position_shared:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_get_position_shared\n"
"jmp *A_MPI_File_get_position_shared@GOTPCREL(%rip)\n"
"inwrap_MPI_File_get_position_shared:\n"
"jmp *R_MPI_File_get_position_shared@GOTPCREL(%rip)\n"
".size PMPI_File_get_position_shared,.-PMPI_File_get_position_shared\n"

);

int A_MPI_File_get_position_shared(A_MPI_File fh,A_MPI_Offset * offset)
{
#ifdef DEBUG
printf("entre : A_MPI_File_get_position_shared\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
R_MPI_Offset  offset_ltmp;
R_MPI_Offset * offset_tmp=&offset_ltmp;
int ret_tmp= LOCAL_MPI_File_get_position_shared( fh_tmp, offset_tmp);
*offset= (A_MPI_Offset ) *offset_tmp;
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_get_position_shared\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_get_position_shared(R_MPI_File fh,R_MPI_Offset * offset)
{
#ifdef DEBUG
printf("entre : R_MPI_File_get_position_shared\n");
#endif
int ret_tmp= LOCAL_MPI_File_get_position_shared( fh, offset);
#ifdef DEBUG
printf("sort : R_MPI_File_get_position_shared\n");
#endif
return ret_tmp;
}
int MPI_File_read_at_all_begin(A_MPI_File fh,A_MPI_Offset offset,void * buf,int count,A_MPI_Datatype datatype);
int (*LOCAL_MPI_File_read_at_all_begin)(R_MPI_File,R_MPI_Offset,void *,int,R_MPI_Datatype);

__asm__(
".global PMPI_File_read_at_all_begin\n"
".weak MPI_File_read_at_all_begin\n"
".set MPI_File_read_at_all_begin,PMPI_File_read_at_all_begin\n"
".extern in_w\n"
".extern A_MPI_File_read_at_all_begin\n"
".extern R_MPI_File_read_at_all_begin\n"
".type PMPI_File_read_at_all_begin,@function\n"
".text\n"
"PMPI_File_read_at_all_begin:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_read_at_all_begin\n"
"jmp *A_MPI_File_read_at_all_begin@GOTPCREL(%rip)\n"
"inwrap_MPI_File_read_at_all_begin:\n"
"jmp *R_MPI_File_read_at_all_begin@GOTPCREL(%rip)\n"
".size PMPI_File_read_at_all_begin,.-PMPI_File_read_at_all_begin\n"

);

int A_MPI_File_read_at_all_begin(A_MPI_File fh,A_MPI_Offset offset,void * buf,int count,A_MPI_Datatype datatype)
{
#ifdef DEBUG
printf("entre : A_MPI_File_read_at_all_begin\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
R_MPI_Offset offset_tmp;
offset_tmp = (R_MPI_Offset)offset;
void * buf_tmp;
buffer_conv_a2r(&buf,&buf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
int ret_tmp= LOCAL_MPI_File_read_at_all_begin( fh_tmp, offset_tmp, buf_tmp, count, datatype_tmp);
buffer_conv_r2a(&buf,&buf_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_read_at_all_begin\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_read_at_all_begin(R_MPI_File fh,R_MPI_Offset offset,void * buf,int count,R_MPI_Datatype datatype)
{
#ifdef DEBUG
printf("entre : R_MPI_File_read_at_all_begin\n");
#endif
int ret_tmp= LOCAL_MPI_File_read_at_all_begin( fh, offset, buf, count, datatype);
#ifdef DEBUG
printf("sort : R_MPI_File_read_at_all_begin\n");
#endif
return ret_tmp;
}
int MPI_File_read_at_all_end(A_MPI_File fh,void * buf,A_MPI_Status * status);
int (*LOCAL_MPI_File_read_at_all_end)(R_MPI_File,void *,R_MPI_Status *);

__asm__(
".global PMPI_File_read_at_all_end\n"
".weak MPI_File_read_at_all_end\n"
".set MPI_File_read_at_all_end,PMPI_File_read_at_all_end\n"
".extern in_w\n"
".extern A_MPI_File_read_at_all_end\n"
".extern R_MPI_File_read_at_all_end\n"
".type PMPI_File_read_at_all_end,@function\n"
".text\n"
"PMPI_File_read_at_all_end:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_read_at_all_end\n"
"jmp *A_MPI_File_read_at_all_end@GOTPCREL(%rip)\n"
"inwrap_MPI_File_read_at_all_end:\n"
"jmp *R_MPI_File_read_at_all_end@GOTPCREL(%rip)\n"
".size PMPI_File_read_at_all_end,.-PMPI_File_read_at_all_end\n"

);

int A_MPI_File_read_at_all_end(A_MPI_File fh,void * buf,A_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : A_MPI_File_read_at_all_end\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
void * buf_tmp;
buffer_conv_a2r(&buf,&buf_tmp);
R_MPI_Status  status_ltmp;
R_MPI_Status * status_tmp=&status_ltmp;
int ret_tmp= LOCAL_MPI_File_read_at_all_end( fh_tmp, buf_tmp, status_tmp);
buffer_conv_r2a(&buf,&buf_tmp);
status_prt_conv_r2a(&status,&status_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_read_at_all_end\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_read_at_all_end(R_MPI_File fh,void * buf,R_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : R_MPI_File_read_at_all_end\n");
#endif
int ret_tmp= LOCAL_MPI_File_read_at_all_end( fh, buf, status);
#ifdef DEBUG
printf("sort : R_MPI_File_read_at_all_end\n");
#endif
return ret_tmp;
}
int MPI_File_write_at_all_begin(A_MPI_File fh,A_MPI_Offset offset,void * buf,int count,A_MPI_Datatype datatype);
int (*LOCAL_MPI_File_write_at_all_begin)(R_MPI_File,R_MPI_Offset,void *,int,R_MPI_Datatype);

__asm__(
".global PMPI_File_write_at_all_begin\n"
".weak MPI_File_write_at_all_begin\n"
".set MPI_File_write_at_all_begin,PMPI_File_write_at_all_begin\n"
".extern in_w\n"
".extern A_MPI_File_write_at_all_begin\n"
".extern R_MPI_File_write_at_all_begin\n"
".type PMPI_File_write_at_all_begin,@function\n"
".text\n"
"PMPI_File_write_at_all_begin:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_write_at_all_begin\n"
"jmp *A_MPI_File_write_at_all_begin@GOTPCREL(%rip)\n"
"inwrap_MPI_File_write_at_all_begin:\n"
"jmp *R_MPI_File_write_at_all_begin@GOTPCREL(%rip)\n"
".size PMPI_File_write_at_all_begin,.-PMPI_File_write_at_all_begin\n"

);

int A_MPI_File_write_at_all_begin(A_MPI_File fh,A_MPI_Offset offset,void * buf,int count,A_MPI_Datatype datatype)
{
#ifdef DEBUG
printf("entre : A_MPI_File_write_at_all_begin\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
R_MPI_Offset offset_tmp;
offset_tmp = (R_MPI_Offset)offset;
void * buf_tmp;
const_buffer_conv_a2r(&buf,&buf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
int ret_tmp= LOCAL_MPI_File_write_at_all_begin( fh_tmp, offset_tmp, buf_tmp, count, datatype_tmp);
file_conv_r2a(&fh,&fh_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_write_at_all_begin\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_write_at_all_begin(R_MPI_File fh,R_MPI_Offset offset,void * buf,int count,R_MPI_Datatype datatype)
{
#ifdef DEBUG
printf("entre : R_MPI_File_write_at_all_begin\n");
#endif
int ret_tmp= LOCAL_MPI_File_write_at_all_begin( fh, offset, buf, count, datatype);
#ifdef DEBUG
printf("sort : R_MPI_File_write_at_all_begin\n");
#endif
return ret_tmp;
}
int MPI_File_write_at_all_end(A_MPI_File fh,void * buf,A_MPI_Status * status);
int (*LOCAL_MPI_File_write_at_all_end)(R_MPI_File,void *,R_MPI_Status *);

__asm__(
".global PMPI_File_write_at_all_end\n"
".weak MPI_File_write_at_all_end\n"
".set MPI_File_write_at_all_end,PMPI_File_write_at_all_end\n"
".extern in_w\n"
".extern A_MPI_File_write_at_all_end\n"
".extern R_MPI_File_write_at_all_end\n"
".type PMPI_File_write_at_all_end,@function\n"
".text\n"
"PMPI_File_write_at_all_end:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_write_at_all_end\n"
"jmp *A_MPI_File_write_at_all_end@GOTPCREL(%rip)\n"
"inwrap_MPI_File_write_at_all_end:\n"
"jmp *R_MPI_File_write_at_all_end@GOTPCREL(%rip)\n"
".size PMPI_File_write_at_all_end,.-PMPI_File_write_at_all_end\n"

);

int A_MPI_File_write_at_all_end(A_MPI_File fh,void * buf,A_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : A_MPI_File_write_at_all_end\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
void * buf_tmp;
const_buffer_conv_a2r(&buf,&buf_tmp);
R_MPI_Status  status_ltmp;
R_MPI_Status * status_tmp=&status_ltmp;
int ret_tmp= LOCAL_MPI_File_write_at_all_end( fh_tmp, buf_tmp, status_tmp);
file_conv_r2a(&fh,&fh_tmp);
status_prt_conv_r2a(&status,&status_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_write_at_all_end\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_write_at_all_end(R_MPI_File fh,void * buf,R_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : R_MPI_File_write_at_all_end\n");
#endif
int ret_tmp= LOCAL_MPI_File_write_at_all_end( fh, buf, status);
#ifdef DEBUG
printf("sort : R_MPI_File_write_at_all_end\n");
#endif
return ret_tmp;
}
int MPI_File_read_all_begin(A_MPI_File fh,void * buf,int count,A_MPI_Datatype datatype);
int (*LOCAL_MPI_File_read_all_begin)(R_MPI_File,void *,int,R_MPI_Datatype);

__asm__(
".global PMPI_File_read_all_begin\n"
".weak MPI_File_read_all_begin\n"
".set MPI_File_read_all_begin,PMPI_File_read_all_begin\n"
".extern in_w\n"
".extern A_MPI_File_read_all_begin\n"
".extern R_MPI_File_read_all_begin\n"
".type PMPI_File_read_all_begin,@function\n"
".text\n"
"PMPI_File_read_all_begin:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_read_all_begin\n"
"jmp *A_MPI_File_read_all_begin@GOTPCREL(%rip)\n"
"inwrap_MPI_File_read_all_begin:\n"
"jmp *R_MPI_File_read_all_begin@GOTPCREL(%rip)\n"
".size PMPI_File_read_all_begin,.-PMPI_File_read_all_begin\n"

);

int A_MPI_File_read_all_begin(A_MPI_File fh,void * buf,int count,A_MPI_Datatype datatype)
{
#ifdef DEBUG
printf("entre : A_MPI_File_read_all_begin\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
void * buf_tmp;
buffer_conv_a2r(&buf,&buf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
int ret_tmp= LOCAL_MPI_File_read_all_begin( fh_tmp, buf_tmp, count, datatype_tmp);
file_conv_r2a(&fh,&fh_tmp);
buffer_conv_r2a(&buf,&buf_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_read_all_begin\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_read_all_begin(R_MPI_File fh,void * buf,int count,R_MPI_Datatype datatype)
{
#ifdef DEBUG
printf("entre : R_MPI_File_read_all_begin\n");
#endif
int ret_tmp= LOCAL_MPI_File_read_all_begin( fh, buf, count, datatype);
#ifdef DEBUG
printf("sort : R_MPI_File_read_all_begin\n");
#endif
return ret_tmp;
}
int MPI_File_read_all_end(A_MPI_File fh,void * buf,A_MPI_Status * status);
int (*LOCAL_MPI_File_read_all_end)(R_MPI_File,void *,R_MPI_Status *);

__asm__(
".global PMPI_File_read_all_end\n"
".weak MPI_File_read_all_end\n"
".set MPI_File_read_all_end,PMPI_File_read_all_end\n"
".extern in_w\n"
".extern A_MPI_File_read_all_end\n"
".extern R_MPI_File_read_all_end\n"
".type PMPI_File_read_all_end,@function\n"
".text\n"
"PMPI_File_read_all_end:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_read_all_end\n"
"jmp *A_MPI_File_read_all_end@GOTPCREL(%rip)\n"
"inwrap_MPI_File_read_all_end:\n"
"jmp *R_MPI_File_read_all_end@GOTPCREL(%rip)\n"
".size PMPI_File_read_all_end,.-PMPI_File_read_all_end\n"

);

int A_MPI_File_read_all_end(A_MPI_File fh,void * buf,A_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : A_MPI_File_read_all_end\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
void * buf_tmp;
buffer_conv_a2r(&buf,&buf_tmp);
R_MPI_Status  status_ltmp;
R_MPI_Status * status_tmp=&status_ltmp;
int ret_tmp= LOCAL_MPI_File_read_all_end( fh_tmp, buf_tmp, status_tmp);
file_conv_r2a(&fh,&fh_tmp);
buffer_conv_r2a(&buf,&buf_tmp);
status_prt_conv_r2a(&status,&status_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_read_all_end\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_read_all_end(R_MPI_File fh,void * buf,R_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : R_MPI_File_read_all_end\n");
#endif
int ret_tmp= LOCAL_MPI_File_read_all_end( fh, buf, status);
#ifdef DEBUG
printf("sort : R_MPI_File_read_all_end\n");
#endif
return ret_tmp;
}
int MPI_File_write_all_begin(A_MPI_File fh,void * buf,int count,A_MPI_Datatype datatype);
int (*LOCAL_MPI_File_write_all_begin)(R_MPI_File,void *,int,R_MPI_Datatype);

__asm__(
".global PMPI_File_write_all_begin\n"
".weak MPI_File_write_all_begin\n"
".set MPI_File_write_all_begin,PMPI_File_write_all_begin\n"
".extern in_w\n"
".extern A_MPI_File_write_all_begin\n"
".extern R_MPI_File_write_all_begin\n"
".type PMPI_File_write_all_begin,@function\n"
".text\n"
"PMPI_File_write_all_begin:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_write_all_begin\n"
"jmp *A_MPI_File_write_all_begin@GOTPCREL(%rip)\n"
"inwrap_MPI_File_write_all_begin:\n"
"jmp *R_MPI_File_write_all_begin@GOTPCREL(%rip)\n"
".size PMPI_File_write_all_begin,.-PMPI_File_write_all_begin\n"

);

int A_MPI_File_write_all_begin(A_MPI_File fh,void * buf,int count,A_MPI_Datatype datatype)
{
#ifdef DEBUG
printf("entre : A_MPI_File_write_all_begin\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
void * buf_tmp;
const_buffer_conv_a2r(&buf,&buf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
int ret_tmp= LOCAL_MPI_File_write_all_begin( fh_tmp, buf_tmp, count, datatype_tmp);
file_conv_r2a(&fh,&fh_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_write_all_begin\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_write_all_begin(R_MPI_File fh,void * buf,int count,R_MPI_Datatype datatype)
{
#ifdef DEBUG
printf("entre : R_MPI_File_write_all_begin\n");
#endif
int ret_tmp= LOCAL_MPI_File_write_all_begin( fh, buf, count, datatype);
#ifdef DEBUG
printf("sort : R_MPI_File_write_all_begin\n");
#endif
return ret_tmp;
}
int MPI_File_write_all_end(A_MPI_File fh,void * buf,A_MPI_Status * status);
int (*LOCAL_MPI_File_write_all_end)(R_MPI_File,void *,R_MPI_Status *);

__asm__(
".global PMPI_File_write_all_end\n"
".weak MPI_File_write_all_end\n"
".set MPI_File_write_all_end,PMPI_File_write_all_end\n"
".extern in_w\n"
".extern A_MPI_File_write_all_end\n"
".extern R_MPI_File_write_all_end\n"
".type PMPI_File_write_all_end,@function\n"
".text\n"
"PMPI_File_write_all_end:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_write_all_end\n"
"jmp *A_MPI_File_write_all_end@GOTPCREL(%rip)\n"
"inwrap_MPI_File_write_all_end:\n"
"jmp *R_MPI_File_write_all_end@GOTPCREL(%rip)\n"
".size PMPI_File_write_all_end,.-PMPI_File_write_all_end\n"

);

int A_MPI_File_write_all_end(A_MPI_File fh,void * buf,A_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : A_MPI_File_write_all_end\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
void * buf_tmp;
const_buffer_conv_a2r(&buf,&buf_tmp);
R_MPI_Status  status_ltmp;
R_MPI_Status * status_tmp=&status_ltmp;
int ret_tmp= LOCAL_MPI_File_write_all_end( fh_tmp, buf_tmp, status_tmp);
file_conv_r2a(&fh,&fh_tmp);
status_prt_conv_r2a(&status,&status_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_write_all_end\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_write_all_end(R_MPI_File fh,void * buf,R_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : R_MPI_File_write_all_end\n");
#endif
int ret_tmp= LOCAL_MPI_File_write_all_end( fh, buf, status);
#ifdef DEBUG
printf("sort : R_MPI_File_write_all_end\n");
#endif
return ret_tmp;
}
int MPI_File_read_ordered_begin(A_MPI_File fh,void * buf,int count,A_MPI_Datatype datatype);
int (*LOCAL_MPI_File_read_ordered_begin)(R_MPI_File,void *,int,R_MPI_Datatype);

__asm__(
".global PMPI_File_read_ordered_begin\n"
".weak MPI_File_read_ordered_begin\n"
".set MPI_File_read_ordered_begin,PMPI_File_read_ordered_begin\n"
".extern in_w\n"
".extern A_MPI_File_read_ordered_begin\n"
".extern R_MPI_File_read_ordered_begin\n"
".type PMPI_File_read_ordered_begin,@function\n"
".text\n"
"PMPI_File_read_ordered_begin:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_read_ordered_begin\n"
"jmp *A_MPI_File_read_ordered_begin@GOTPCREL(%rip)\n"
"inwrap_MPI_File_read_ordered_begin:\n"
"jmp *R_MPI_File_read_ordered_begin@GOTPCREL(%rip)\n"
".size PMPI_File_read_ordered_begin,.-PMPI_File_read_ordered_begin\n"

);

int A_MPI_File_read_ordered_begin(A_MPI_File fh,void * buf,int count,A_MPI_Datatype datatype)
{
#ifdef DEBUG
printf("entre : A_MPI_File_read_ordered_begin\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
void * buf_tmp;
buffer_conv_a2r(&buf,&buf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
int ret_tmp= LOCAL_MPI_File_read_ordered_begin( fh_tmp, buf_tmp, count, datatype_tmp);
file_conv_r2a(&fh,&fh_tmp);
buffer_conv_r2a(&buf,&buf_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_read_ordered_begin\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_read_ordered_begin(R_MPI_File fh,void * buf,int count,R_MPI_Datatype datatype)
{
#ifdef DEBUG
printf("entre : R_MPI_File_read_ordered_begin\n");
#endif
int ret_tmp= LOCAL_MPI_File_read_ordered_begin( fh, buf, count, datatype);
#ifdef DEBUG
printf("sort : R_MPI_File_read_ordered_begin\n");
#endif
return ret_tmp;
}
int MPI_File_read_ordered_end(A_MPI_File fh,void * buf,A_MPI_Status * status);
int (*LOCAL_MPI_File_read_ordered_end)(R_MPI_File,void *,R_MPI_Status *);

__asm__(
".global PMPI_File_read_ordered_end\n"
".weak MPI_File_read_ordered_end\n"
".set MPI_File_read_ordered_end,PMPI_File_read_ordered_end\n"
".extern in_w\n"
".extern A_MPI_File_read_ordered_end\n"
".extern R_MPI_File_read_ordered_end\n"
".type PMPI_File_read_ordered_end,@function\n"
".text\n"
"PMPI_File_read_ordered_end:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_read_ordered_end\n"
"jmp *A_MPI_File_read_ordered_end@GOTPCREL(%rip)\n"
"inwrap_MPI_File_read_ordered_end:\n"
"jmp *R_MPI_File_read_ordered_end@GOTPCREL(%rip)\n"
".size PMPI_File_read_ordered_end,.-PMPI_File_read_ordered_end\n"

);

int A_MPI_File_read_ordered_end(A_MPI_File fh,void * buf,A_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : A_MPI_File_read_ordered_end\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
void * buf_tmp;
buffer_conv_a2r(&buf,&buf_tmp);
R_MPI_Status  status_ltmp;
R_MPI_Status * status_tmp=&status_ltmp;
int ret_tmp= LOCAL_MPI_File_read_ordered_end( fh_tmp, buf_tmp, status_tmp);
file_conv_r2a(&fh,&fh_tmp);
buffer_conv_r2a(&buf,&buf_tmp);
status_prt_conv_r2a(&status,&status_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_read_ordered_end\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_read_ordered_end(R_MPI_File fh,void * buf,R_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : R_MPI_File_read_ordered_end\n");
#endif
int ret_tmp= LOCAL_MPI_File_read_ordered_end( fh, buf, status);
#ifdef DEBUG
printf("sort : R_MPI_File_read_ordered_end\n");
#endif
return ret_tmp;
}
int MPI_File_write_ordered_begin(A_MPI_File fh,void * buf,int count,A_MPI_Datatype datatype);
int (*LOCAL_MPI_File_write_ordered_begin)(R_MPI_File,void *,int,R_MPI_Datatype);

__asm__(
".global PMPI_File_write_ordered_begin\n"
".weak MPI_File_write_ordered_begin\n"
".set MPI_File_write_ordered_begin,PMPI_File_write_ordered_begin\n"
".extern in_w\n"
".extern A_MPI_File_write_ordered_begin\n"
".extern R_MPI_File_write_ordered_begin\n"
".type PMPI_File_write_ordered_begin,@function\n"
".text\n"
"PMPI_File_write_ordered_begin:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_write_ordered_begin\n"
"jmp *A_MPI_File_write_ordered_begin@GOTPCREL(%rip)\n"
"inwrap_MPI_File_write_ordered_begin:\n"
"jmp *R_MPI_File_write_ordered_begin@GOTPCREL(%rip)\n"
".size PMPI_File_write_ordered_begin,.-PMPI_File_write_ordered_begin\n"

);

int A_MPI_File_write_ordered_begin(A_MPI_File fh,void * buf,int count,A_MPI_Datatype datatype)
{
#ifdef DEBUG
printf("entre : A_MPI_File_write_ordered_begin\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
void * buf_tmp;
const_buffer_conv_a2r(&buf,&buf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
int ret_tmp= LOCAL_MPI_File_write_ordered_begin( fh_tmp, buf_tmp, count, datatype_tmp);
file_conv_r2a(&fh,&fh_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_write_ordered_begin\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_write_ordered_begin(R_MPI_File fh,void * buf,int count,R_MPI_Datatype datatype)
{
#ifdef DEBUG
printf("entre : R_MPI_File_write_ordered_begin\n");
#endif
int ret_tmp= LOCAL_MPI_File_write_ordered_begin( fh, buf, count, datatype);
#ifdef DEBUG
printf("sort : R_MPI_File_write_ordered_begin\n");
#endif
return ret_tmp;
}
int MPI_File_write_ordered_end(A_MPI_File fh,void * buf,A_MPI_Status * status);
int (*LOCAL_MPI_File_write_ordered_end)(R_MPI_File,void *,R_MPI_Status *);

__asm__(
".global PMPI_File_write_ordered_end\n"
".weak MPI_File_write_ordered_end\n"
".set MPI_File_write_ordered_end,PMPI_File_write_ordered_end\n"
".extern in_w\n"
".extern A_MPI_File_write_ordered_end\n"
".extern R_MPI_File_write_ordered_end\n"
".type PMPI_File_write_ordered_end,@function\n"
".text\n"
"PMPI_File_write_ordered_end:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_write_ordered_end\n"
"jmp *A_MPI_File_write_ordered_end@GOTPCREL(%rip)\n"
"inwrap_MPI_File_write_ordered_end:\n"
"jmp *R_MPI_File_write_ordered_end@GOTPCREL(%rip)\n"
".size PMPI_File_write_ordered_end,.-PMPI_File_write_ordered_end\n"

);

int A_MPI_File_write_ordered_end(A_MPI_File fh,void * buf,A_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : A_MPI_File_write_ordered_end\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
void * buf_tmp;
const_buffer_conv_a2r(&buf,&buf_tmp);
R_MPI_Status  status_ltmp;
R_MPI_Status * status_tmp=&status_ltmp;
int ret_tmp= LOCAL_MPI_File_write_ordered_end( fh_tmp, buf_tmp, status_tmp);
file_conv_r2a(&fh,&fh_tmp);
status_prt_conv_r2a(&status,&status_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_write_ordered_end\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_write_ordered_end(R_MPI_File fh,void * buf,R_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : R_MPI_File_write_ordered_end\n");
#endif
int ret_tmp= LOCAL_MPI_File_write_ordered_end( fh, buf, status);
#ifdef DEBUG
printf("sort : R_MPI_File_write_ordered_end\n");
#endif
return ret_tmp;
}
int MPI_File_get_type_extent(A_MPI_File fh,A_MPI_Datatype datatype,A_MPI_Aint * extent);
int (*LOCAL_MPI_File_get_type_extent)(R_MPI_File,R_MPI_Datatype,R_MPI_Aint *);

__asm__(
".global PMPI_File_get_type_extent\n"
".weak MPI_File_get_type_extent\n"
".set MPI_File_get_type_extent,PMPI_File_get_type_extent\n"
".extern in_w\n"
".extern A_MPI_File_get_type_extent\n"
".extern R_MPI_File_get_type_extent\n"
".type PMPI_File_get_type_extent,@function\n"
".text\n"
"PMPI_File_get_type_extent:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_get_type_extent\n"
"jmp *A_MPI_File_get_type_extent@GOTPCREL(%rip)\n"
"inwrap_MPI_File_get_type_extent:\n"
"jmp *R_MPI_File_get_type_extent@GOTPCREL(%rip)\n"
".size PMPI_File_get_type_extent,.-PMPI_File_get_type_extent\n"

);

int A_MPI_File_get_type_extent(A_MPI_File fh,A_MPI_Datatype datatype,A_MPI_Aint * extent)
{
#ifdef DEBUG
printf("entre : A_MPI_File_get_type_extent\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
R_MPI_Aint  extent_ltmp;
R_MPI_Aint * extent_tmp=&extent_ltmp;
int ret_tmp= LOCAL_MPI_File_get_type_extent( fh_tmp, datatype_tmp, extent_tmp);
*extent= (A_MPI_Aint ) *extent_tmp;
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_get_type_extent\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_get_type_extent(R_MPI_File fh,R_MPI_Datatype datatype,R_MPI_Aint * extent)
{
#ifdef DEBUG
printf("entre : R_MPI_File_get_type_extent\n");
#endif
int ret_tmp= LOCAL_MPI_File_get_type_extent( fh, datatype, extent);
#ifdef DEBUG
printf("sort : R_MPI_File_get_type_extent\n");
#endif
return ret_tmp;
}
int MPI_Register_datarep(char * datarep,A_MPI_Datarep_conversion_function * read_conversion_fn,A_MPI_Datarep_conversion_function * write_conversion_fn,A_MPI_Datarep_extent_function * dtype_file_extent_fn,void * extra_state);
int (*LOCAL_MPI_Register_datarep)(char *,R_MPI_Datarep_conversion_function *,R_MPI_Datarep_conversion_function *,R_MPI_Datarep_extent_function *,void *);

__asm__(
".global PMPI_Register_datarep\n"
".weak MPI_Register_datarep\n"
".set MPI_Register_datarep,PMPI_Register_datarep\n"
".extern in_w\n"
".extern A_MPI_Register_datarep\n"
".extern R_MPI_Register_datarep\n"
".type PMPI_Register_datarep,@function\n"
".text\n"
"PMPI_Register_datarep:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Register_datarep\n"
"jmp *A_MPI_Register_datarep@GOTPCREL(%rip)\n"
"inwrap_MPI_Register_datarep:\n"
"jmp *R_MPI_Register_datarep@GOTPCREL(%rip)\n"
".size PMPI_Register_datarep,.-PMPI_Register_datarep\n"

);

int A_MPI_Register_datarep(char * datarep,A_MPI_Datarep_conversion_function * read_conversion_fn,A_MPI_Datarep_conversion_function * write_conversion_fn,A_MPI_Datarep_extent_function * dtype_file_extent_fn,void * extra_state)
{
#ifdef DEBUG
printf("entre : A_MPI_Register_datarep\n");
#endif
in_w=1;




ptr_read_conversion_fn=(A_MPI_Datarep_conversion_function *)read_conversion_fn;

ptr_write_conversion_fn=(A_MPI_Datarep_conversion_function *)write_conversion_fn;

ptr_extent_fn=(A_MPI_Datarep_extent_function *)dtype_file_extent_fn;
void * extra_state_tmp;
buffer_conv_a2r(&extra_state,&extra_state_tmp);
int ret_tmp= LOCAL_MPI_Register_datarep( datarep, (R_MPI_Datarep_conversion_function *)wrapper_datarep_read_conversion_fn, (R_MPI_Datarep_conversion_function *)wrapper_datarep_write_conversion_fn, (R_MPI_Datarep_extent_function *)wrapper_datarep_extent_fn, extra_state_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Register_datarep\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Register_datarep(char * datarep,R_MPI_Datarep_conversion_function * read_conversion_fn,R_MPI_Datarep_conversion_function * write_conversion_fn,R_MPI_Datarep_extent_function * dtype_file_extent_fn,void * extra_state)
{
#ifdef DEBUG
printf("entre : R_MPI_Register_datarep\n");
#endif
int ret_tmp= LOCAL_MPI_Register_datarep( datarep, read_conversion_fn, write_conversion_fn, dtype_file_extent_fn, extra_state);
#ifdef DEBUG
printf("sort : R_MPI_Register_datarep\n");
#endif
return ret_tmp;
}
int MPI_File_set_atomicity(A_MPI_File fh,int flag);
int (*LOCAL_MPI_File_set_atomicity)(R_MPI_File,int);

__asm__(
".global PMPI_File_set_atomicity\n"
".weak MPI_File_set_atomicity\n"
".set MPI_File_set_atomicity,PMPI_File_set_atomicity\n"
".extern in_w\n"
".extern A_MPI_File_set_atomicity\n"
".extern R_MPI_File_set_atomicity\n"
".type PMPI_File_set_atomicity,@function\n"
".text\n"
"PMPI_File_set_atomicity:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_set_atomicity\n"
"jmp *A_MPI_File_set_atomicity@GOTPCREL(%rip)\n"
"inwrap_MPI_File_set_atomicity:\n"
"jmp *R_MPI_File_set_atomicity@GOTPCREL(%rip)\n"
".size PMPI_File_set_atomicity,.-PMPI_File_set_atomicity\n"

);

int A_MPI_File_set_atomicity(A_MPI_File fh,int flag)
{
#ifdef DEBUG
printf("entre : A_MPI_File_set_atomicity\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);


int ret_tmp= LOCAL_MPI_File_set_atomicity( fh_tmp, flag);
file_conv_r2a(&fh,&fh_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_set_atomicity\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_set_atomicity(R_MPI_File fh,int flag)
{
#ifdef DEBUG
printf("entre : R_MPI_File_set_atomicity\n");
#endif
int ret_tmp= LOCAL_MPI_File_set_atomicity( fh, flag);
#ifdef DEBUG
printf("sort : R_MPI_File_set_atomicity\n");
#endif
return ret_tmp;
}
int MPI_File_get_atomicity(A_MPI_File fh,int * flag);
int (*LOCAL_MPI_File_get_atomicity)(R_MPI_File,int *);

__asm__(
".global PMPI_File_get_atomicity\n"
".weak MPI_File_get_atomicity\n"
".set MPI_File_get_atomicity,PMPI_File_get_atomicity\n"
".extern in_w\n"
".extern A_MPI_File_get_atomicity\n"
".extern R_MPI_File_get_atomicity\n"
".type PMPI_File_get_atomicity,@function\n"
".text\n"
"PMPI_File_get_atomicity:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_get_atomicity\n"
"jmp *A_MPI_File_get_atomicity@GOTPCREL(%rip)\n"
"inwrap_MPI_File_get_atomicity:\n"
"jmp *R_MPI_File_get_atomicity@GOTPCREL(%rip)\n"
".size PMPI_File_get_atomicity,.-PMPI_File_get_atomicity\n"

);

int A_MPI_File_get_atomicity(A_MPI_File fh,int * flag)
{
#ifdef DEBUG
printf("entre : A_MPI_File_get_atomicity\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);

int ret_tmp= LOCAL_MPI_File_get_atomicity( fh_tmp, flag);

in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_get_atomicity\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_get_atomicity(R_MPI_File fh,int * flag)
{
#ifdef DEBUG
printf("entre : R_MPI_File_get_atomicity\n");
#endif
int ret_tmp= LOCAL_MPI_File_get_atomicity( fh, flag);
#ifdef DEBUG
printf("sort : R_MPI_File_get_atomicity\n");
#endif
return ret_tmp;
}
int MPI_File_sync(A_MPI_File fh);
int (*LOCAL_MPI_File_sync)(R_MPI_File);

__asm__(
".global PMPI_File_sync\n"
".weak MPI_File_sync\n"
".set MPI_File_sync,PMPI_File_sync\n"
".extern in_w\n"
".extern A_MPI_File_sync\n"
".extern R_MPI_File_sync\n"
".type PMPI_File_sync,@function\n"
".text\n"
"PMPI_File_sync:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_File_sync\n"
"jmp *A_MPI_File_sync@GOTPCREL(%rip)\n"
"inwrap_MPI_File_sync:\n"
"jmp *R_MPI_File_sync@GOTPCREL(%rip)\n"
".size PMPI_File_sync,.-PMPI_File_sync\n"

);

int A_MPI_File_sync(A_MPI_File fh)
{
#ifdef DEBUG
printf("entre : A_MPI_File_sync\n");
#endif
in_w=1;

R_MPI_File fh_tmp;
file_conv_a2r(&fh,&fh_tmp);
int ret_tmp= LOCAL_MPI_File_sync( fh_tmp);
file_conv_r2a(&fh,&fh_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_sync\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_sync(R_MPI_File fh)
{
#ifdef DEBUG
printf("entre : R_MPI_File_sync\n");
#endif
int ret_tmp= LOCAL_MPI_File_sync( fh);
#ifdef DEBUG
printf("sort : R_MPI_File_sync\n");
#endif
return ret_tmp;
}
double MPI_Wtime( );
double (*LOCAL_MPI_Wtime)();

__asm__(
".global PMPI_Wtime\n"
".weak MPI_Wtime\n"
".set MPI_Wtime,PMPI_Wtime\n"
".extern in_w\n"
".extern A_MPI_Wtime\n"
".extern R_MPI_Wtime\n"
".type PMPI_Wtime,@function\n"
".text\n"
"PMPI_Wtime:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Wtime\n"
"jmp *A_MPI_Wtime@GOTPCREL(%rip)\n"
"inwrap_MPI_Wtime:\n"
"jmp *R_MPI_Wtime@GOTPCREL(%rip)\n"
".size PMPI_Wtime,.-PMPI_Wtime\n"

);

double A_MPI_Wtime( )
{
#ifdef DEBUG
printf("entre : A_MPI_Wtime\n");
#endif
in_w=1;

double ret_tmp= LOCAL_MPI_Wtime( );
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Wtime\n");
#endif
return ret_tmp;
}
double R_MPI_Wtime( )
{
#ifdef DEBUG
printf("entre : R_MPI_Wtime\n");
#endif
double ret_tmp= LOCAL_MPI_Wtime( );
#ifdef DEBUG
printf("sort : R_MPI_Wtime\n");
#endif
return ret_tmp;
}
double MPI_Wtick( );
double (*LOCAL_MPI_Wtick)();

__asm__(
".global PMPI_Wtick\n"
".weak MPI_Wtick\n"
".set MPI_Wtick,PMPI_Wtick\n"
".extern in_w\n"
".extern A_MPI_Wtick\n"
".extern R_MPI_Wtick\n"
".type PMPI_Wtick,@function\n"
".text\n"
"PMPI_Wtick:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Wtick\n"
"jmp *A_MPI_Wtick@GOTPCREL(%rip)\n"
"inwrap_MPI_Wtick:\n"
"jmp *R_MPI_Wtick@GOTPCREL(%rip)\n"
".size PMPI_Wtick,.-PMPI_Wtick\n"

);

double A_MPI_Wtick( )
{
#ifdef DEBUG
printf("entre : A_MPI_Wtick\n");
#endif
in_w=1;

double ret_tmp= LOCAL_MPI_Wtick( );
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Wtick\n");
#endif
return ret_tmp;
}
double R_MPI_Wtick( )
{
#ifdef DEBUG
printf("entre : R_MPI_Wtick\n");
#endif
double ret_tmp= LOCAL_MPI_Wtick( );
#ifdef DEBUG
printf("sort : R_MPI_Wtick\n");
#endif
return ret_tmp;
}
int MPI_Finalize( );
int (*LOCAL_MPI_Finalize)();

__asm__(
".global PMPI_Finalize\n"
".weak MPI_Finalize\n"
".set MPI_Finalize,PMPI_Finalize\n"
".extern in_w\n"
".extern A_MPI_Finalize\n"
".extern R_MPI_Finalize\n"
".type PMPI_Finalize,@function\n"
".text\n"
"PMPI_Finalize:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Finalize\n"
"jmp *A_MPI_Finalize@GOTPCREL(%rip)\n"
"inwrap_MPI_Finalize:\n"
"jmp *R_MPI_Finalize@GOTPCREL(%rip)\n"
".size PMPI_Finalize,.-PMPI_Finalize\n"

);

int A_MPI_Finalize( )
{
#ifdef DEBUG
printf("entre : A_MPI_Finalize\n");
#endif
in_w=1;

int ret_tmp= LOCAL_MPI_Finalize( );
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Finalize\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Finalize( )
{
#ifdef DEBUG
printf("entre : R_MPI_Finalize\n");
#endif
int ret_tmp= LOCAL_MPI_Finalize( );
#ifdef DEBUG
printf("sort : R_MPI_Finalize\n");
#endif
return ret_tmp;
}
int MPI_Waitany(int count,R_MPI_Request * array_of_requests[],int * indx,A_MPI_Status * status);
int (*LOCAL_MPI_Waitany)(int,R_MPI_Request *,int *,R_MPI_Status *);

__asm__(
".global PMPI_Waitany\n"
".weak MPI_Waitany\n"
".set MPI_Waitany,PMPI_Waitany\n"
".extern in_w\n"
".extern A_MPI_Waitany\n"
".extern R_MPI_Waitany\n"
".type PMPI_Waitany,@function\n"
".text\n"
"PMPI_Waitany:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Waitany\n"
"jmp *A_MPI_Waitany@GOTPCREL(%rip)\n"
"inwrap_MPI_Waitany:\n"
"jmp *R_MPI_Waitany@GOTPCREL(%rip)\n"
".size PMPI_Waitany,.-PMPI_Waitany\n"

);

int A_MPI_Waitany(int count,A_MPI_Request array_of_requests[],int * indx,A_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : A_MPI_Waitany\n");
#endif
in_w=1;



R_MPI_Request *array_of_requests_tmp = malloc(sizeof(R_MPI_Request)*count);
int i1;
for(i1=0; i1 < count;i1++){
request_tab_conv_a2r(&array_of_requests[i1],&array_of_requests_tmp[i1]);
}

R_MPI_Status  status_ltmp;
R_MPI_Status * status_tmp=&status_ltmp;
int ret_tmp= LOCAL_MPI_Waitany( count, array_of_requests_tmp, indx, status_tmp);
if(ret_tmp == R_MPI_SUCCESS){
 if(array_of_requests_tmp[*indx] == R_MPI_REQUEST_NULL){
request_array_delete(&array_of_requests[*indx],&array_of_requests_tmp[*indx]);
}
}

status_prt_conv_r2a(&status,&status_tmp);
free(array_of_requests_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Waitany\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Waitany(int count,R_MPI_Request array_of_requests[],int * indx,R_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : R_MPI_Waitany\n");
#endif
int ret_tmp= LOCAL_MPI_Waitany( count, array_of_requests, indx, status);
#ifdef DEBUG
printf("sort : R_MPI_Waitany\n");
#endif
return ret_tmp;
}
int MPI_Testany(int count,R_MPI_Request * array_of_requests[],int * indx,int * flag,A_MPI_Status * status);
int (*LOCAL_MPI_Testany)(int,R_MPI_Request *,int *,int *,R_MPI_Status *);

__asm__(
".global PMPI_Testany\n"
".weak MPI_Testany\n"
".set MPI_Testany,PMPI_Testany\n"
".extern in_w\n"
".extern A_MPI_Testany\n"
".extern R_MPI_Testany\n"
".type PMPI_Testany,@function\n"
".text\n"
"PMPI_Testany:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Testany\n"
"jmp *A_MPI_Testany@GOTPCREL(%rip)\n"
"inwrap_MPI_Testany:\n"
"jmp *R_MPI_Testany@GOTPCREL(%rip)\n"
".size PMPI_Testany,.-PMPI_Testany\n"

);

int A_MPI_Testany(int count,A_MPI_Request array_of_requests[],int * indx,int * flag,A_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : A_MPI_Testany\n");
#endif
in_w=1;



R_MPI_Request *array_of_requests_tmp = malloc(sizeof(R_MPI_Request)*count);
int i1;
for(i1=0; i1 < count;i1++){
request_tab_conv_a2r(&array_of_requests[i1],&array_of_requests_tmp[i1]);
}


R_MPI_Status  status_ltmp;
R_MPI_Status * status_tmp=&status_ltmp;
int ret_tmp= LOCAL_MPI_Testany( count, array_of_requests_tmp, indx, flag, status_tmp);
if(ret_tmp == R_MPI_SUCCESS){
if(*flag)
 if(array_of_requests_tmp[*indx] == R_MPI_REQUEST_NULL){
request_array_delete(&array_of_requests[*indx],&array_of_requests_tmp[*indx]);
}
}


status_prt_conv_r2a(&status,&status_tmp);
free(array_of_requests_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Testany\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Testany(int count,R_MPI_Request array_of_requests[],int * indx,int * flag,R_MPI_Status * status)
{
#ifdef DEBUG
printf("entre : R_MPI_Testany\n");
#endif
int ret_tmp= LOCAL_MPI_Testany( count, array_of_requests, indx, flag, status);
#ifdef DEBUG
printf("sort : R_MPI_Testany\n");
#endif
return ret_tmp;
}
int MPI_Waitall(int count,R_MPI_Request * array_of_requests[],R_MPI_Status * array_of_statuses[]);
int (*LOCAL_MPI_Waitall)(int,R_MPI_Request *,R_MPI_Status *);

__asm__(
".global PMPI_Waitall\n"
".weak MPI_Waitall\n"
".set MPI_Waitall,PMPI_Waitall\n"
".extern in_w\n"
".extern A_MPI_Waitall\n"
".extern R_MPI_Waitall\n"
".type PMPI_Waitall,@function\n"
".text\n"
"PMPI_Waitall:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Waitall\n"
"jmp *A_MPI_Waitall@GOTPCREL(%rip)\n"
"inwrap_MPI_Waitall:\n"
"jmp *R_MPI_Waitall@GOTPCREL(%rip)\n"
".size PMPI_Waitall,.-PMPI_Waitall\n"

);

int A_MPI_Waitall(int count,A_MPI_Request array_of_requests[],A_MPI_Status array_of_statuses[])
{
#ifdef DEBUG
printf("entre : A_MPI_Waitall\n");
#endif
in_w=1;



R_MPI_Request *array_of_requests_tmp = malloc(sizeof(R_MPI_Request)*count);
int i1;
for(i1=0; i1 < count;i1++){
request_tab_conv_a2r(&array_of_requests[i1],&array_of_requests_tmp[i1]);
}
R_MPI_Status *array_of_statuses_tmp=(array_of_statuses==A_MPI_STATUSES_IGNORE?R_MPI_STATUSES_IGNORE:(R_MPI_Status *) malloc(sizeof(R_MPI_Status)*count));
int ret_tmp= LOCAL_MPI_Waitall( count, array_of_requests_tmp, array_of_statuses_tmp);
int i2;
if(ret_tmp == R_MPI_SUCCESS){
for(i2 = 0; i2 < count; i2++){
if(array_of_requests_tmp[i2]==R_MPI_REQUEST_NULL){
request_array_delete(&array_of_requests[i2],&array_of_requests_tmp[i2]);
}
}
}
int i3;
if (array_of_statuses!=A_MPI_STATUSES_IGNORE)
{
for(i3=0; i3 < count;i3++){
status_tab_conv_r2a(&array_of_statuses[i3],&array_of_statuses_tmp[i3]);
}
}
free(array_of_requests_tmp);
if (array_of_statuses!=A_MPI_STATUSES_IGNORE)
free(array_of_statuses_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Waitall\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Waitall(int count,R_MPI_Request array_of_requests[],R_MPI_Status array_of_statuses[])
{
#ifdef DEBUG
printf("entre : R_MPI_Waitall\n");
#endif
int ret_tmp= LOCAL_MPI_Waitall( count, array_of_requests, array_of_statuses);
#ifdef DEBUG
printf("sort : R_MPI_Waitall\n");
#endif
return ret_tmp;
}
int MPI_Testall(int count,R_MPI_Request * array_of_requests[],int * flag,R_MPI_Status * array_of_statuses[]);
int (*LOCAL_MPI_Testall)(int,R_MPI_Request *,int *,R_MPI_Status *);

__asm__(
".global PMPI_Testall\n"
".weak MPI_Testall\n"
".set MPI_Testall,PMPI_Testall\n"
".extern in_w\n"
".extern A_MPI_Testall\n"
".extern R_MPI_Testall\n"
".type PMPI_Testall,@function\n"
".text\n"
"PMPI_Testall:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Testall\n"
"jmp *A_MPI_Testall@GOTPCREL(%rip)\n"
"inwrap_MPI_Testall:\n"
"jmp *R_MPI_Testall@GOTPCREL(%rip)\n"
".size PMPI_Testall,.-PMPI_Testall\n"

);

int A_MPI_Testall(int count,A_MPI_Request array_of_requests[],int * flag,A_MPI_Status array_of_statuses[])
{
#ifdef DEBUG
printf("entre : A_MPI_Testall\n");
#endif
in_w=1;



R_MPI_Request *array_of_requests_tmp = malloc(sizeof(R_MPI_Request)*count);
int i1;
for(i1=0; i1 < count;i1++){
request_tab_conv_a2r(&array_of_requests[i1],&array_of_requests_tmp[i1]);
}

R_MPI_Status *array_of_statuses_tmp=(array_of_statuses==A_MPI_STATUSES_IGNORE?R_MPI_STATUSES_IGNORE:(R_MPI_Status *) malloc(sizeof(R_MPI_Status)*count));
int ret_tmp= LOCAL_MPI_Testall( count, array_of_requests_tmp, flag, array_of_statuses_tmp);
int i2;
if(ret_tmp == R_MPI_SUCCESS){
if(*flag)
for(i2 = 0; i2 < count; i2++){
if(array_of_requests_tmp[i2]==R_MPI_REQUEST_NULL){
request_array_delete(&array_of_requests[i2],&array_of_requests_tmp[i2]);
}
}
}

int i3;
if (array_of_statuses!=A_MPI_STATUSES_IGNORE)
{
for(i3=0; i3 < count;i3++){
status_tab_conv_r2a(&array_of_statuses[i3],&array_of_statuses_tmp[i3]);
}
}
free(array_of_requests_tmp);
if (array_of_statuses!=A_MPI_STATUSES_IGNORE)
free(array_of_statuses_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Testall\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Testall(int count,R_MPI_Request array_of_requests[],int * flag,R_MPI_Status array_of_statuses[])
{
#ifdef DEBUG
printf("entre : R_MPI_Testall\n");
#endif
int ret_tmp= LOCAL_MPI_Testall( count, array_of_requests, flag, array_of_statuses);
#ifdef DEBUG
printf("sort : R_MPI_Testall\n");
#endif
return ret_tmp;
}
int MPI_Waitsome(int incount,R_MPI_Request * array_of_requests[],int * outcount,int * array_of_indices[],R_MPI_Status * array_of_statuses[]);
int (*LOCAL_MPI_Waitsome)(int,R_MPI_Request *,int *,int *,R_MPI_Status *);

__asm__(
".global PMPI_Waitsome\n"
".weak MPI_Waitsome\n"
".set MPI_Waitsome,PMPI_Waitsome\n"
".extern in_w\n"
".extern A_MPI_Waitsome\n"
".extern R_MPI_Waitsome\n"
".type PMPI_Waitsome,@function\n"
".text\n"
"PMPI_Waitsome:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Waitsome\n"
"jmp *A_MPI_Waitsome@GOTPCREL(%rip)\n"
"inwrap_MPI_Waitsome:\n"
"jmp *R_MPI_Waitsome@GOTPCREL(%rip)\n"
".size PMPI_Waitsome,.-PMPI_Waitsome\n"

);

int A_MPI_Waitsome(int incount,A_MPI_Request array_of_requests[],int * outcount,int array_of_indices[],A_MPI_Status array_of_statuses[])
{
#ifdef DEBUG
printf("entre : A_MPI_Waitsome\n");
#endif
in_w=1;



R_MPI_Request *array_of_requests_tmp = malloc(sizeof(R_MPI_Request)*incount);
int i1;
for(i1=0; i1 < incount;i1++){
request_tab_conv_a2r(&array_of_requests[i1],&array_of_requests_tmp[i1]);
}


R_MPI_Status *array_of_statuses_tmp=(array_of_statuses==A_MPI_STATUSES_IGNORE?R_MPI_STATUSES_IGNORE:(R_MPI_Status *) malloc(sizeof(R_MPI_Status)*incount));
int ret_tmp= LOCAL_MPI_Waitsome( incount, array_of_requests_tmp, outcount, array_of_indices, array_of_statuses_tmp);
int i2;
if(ret_tmp == R_MPI_SUCCESS){
for(i2 = 0; i2 < *outcount; i2++){
if(array_of_requests_tmp[array_of_indices[i2]]==R_MPI_REQUEST_NULL){
request_array_delete(&array_of_requests[array_of_indices[i2]],&array_of_requests_tmp[array_of_indices[i2]]);
}
}
}


int i4;
if (array_of_statuses!=A_MPI_STATUSES_IGNORE)
{
for(i4=0; i4 < *outcount;i4++){
status_tab_conv_r2a(&array_of_statuses[i4],&array_of_statuses_tmp[i4]);
}
}
free(array_of_requests_tmp);
if (array_of_statuses!=A_MPI_STATUSES_IGNORE)
free(array_of_statuses_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Waitsome\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Waitsome(int incount,R_MPI_Request array_of_requests[],int * outcount,int array_of_indices[],R_MPI_Status array_of_statuses[])
{
#ifdef DEBUG
printf("entre : R_MPI_Waitsome\n");
#endif
int ret_tmp= LOCAL_MPI_Waitsome( incount, array_of_requests, outcount, array_of_indices, array_of_statuses);
#ifdef DEBUG
printf("sort : R_MPI_Waitsome\n");
#endif
return ret_tmp;
}
int MPI_Testsome(int incount,R_MPI_Request * array_of_requests[],int * outcount,int * array_of_indices[],R_MPI_Status * array_of_statuses[]);
int (*LOCAL_MPI_Testsome)(int,R_MPI_Request *,int *,int *,R_MPI_Status *);

__asm__(
".global PMPI_Testsome\n"
".weak MPI_Testsome\n"
".set MPI_Testsome,PMPI_Testsome\n"
".extern in_w\n"
".extern A_MPI_Testsome\n"
".extern R_MPI_Testsome\n"
".type PMPI_Testsome,@function\n"
".text\n"
"PMPI_Testsome:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Testsome\n"
"jmp *A_MPI_Testsome@GOTPCREL(%rip)\n"
"inwrap_MPI_Testsome:\n"
"jmp *R_MPI_Testsome@GOTPCREL(%rip)\n"
".size PMPI_Testsome,.-PMPI_Testsome\n"

);

int A_MPI_Testsome(int incount,A_MPI_Request array_of_requests[],int * outcount,int array_of_indices[],A_MPI_Status array_of_statuses[])
{
#ifdef DEBUG
printf("entre : A_MPI_Testsome\n");
#endif
in_w=1;



R_MPI_Request *array_of_requests_tmp = malloc(sizeof(R_MPI_Request)*incount);
int i1;
for(i1=0; i1 < incount;i1++){
request_tab_conv_a2r(&array_of_requests[i1],&array_of_requests_tmp[i1]);
}


R_MPI_Status *array_of_statuses_tmp=(array_of_statuses==A_MPI_STATUSES_IGNORE?R_MPI_STATUSES_IGNORE:(R_MPI_Status *) malloc(sizeof(R_MPI_Status)*incount));
int ret_tmp= LOCAL_MPI_Testsome( incount, array_of_requests_tmp, outcount, array_of_indices, array_of_statuses_tmp);
int i2;
if(ret_tmp == R_MPI_SUCCESS){
for(i2 = 0; i2 < *outcount; i2++){
if(array_of_requests_tmp[array_of_indices[i2]]==R_MPI_REQUEST_NULL){
request_array_delete(&array_of_requests[array_of_indices[i2]],&array_of_requests_tmp[array_of_indices[i2]]);
}
}
}


int i4;
if (array_of_statuses!=A_MPI_STATUSES_IGNORE)
{
for(i4=0; i4 < *outcount;i4++){
status_tab_conv_r2a(&array_of_statuses[i4],&array_of_statuses_tmp[i4]);
}
}
free(array_of_requests_tmp);
if (array_of_statuses!=A_MPI_STATUSES_IGNORE)
free(array_of_statuses_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Testsome\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Testsome(int incount,R_MPI_Request array_of_requests[],int * outcount,int array_of_indices[],R_MPI_Status array_of_statuses[])
{
#ifdef DEBUG
printf("entre : R_MPI_Testsome\n");
#endif
int ret_tmp= LOCAL_MPI_Testsome( incount, array_of_requests, outcount, array_of_indices, array_of_statuses);
#ifdef DEBUG
printf("sort : R_MPI_Testsome\n");
#endif
return ret_tmp;
}
int MPI_Startall(int count,R_MPI_Request * array_of_requests[]);
int (*LOCAL_MPI_Startall)(int,R_MPI_Request *);

__asm__(
".global PMPI_Startall\n"
".weak MPI_Startall\n"
".set MPI_Startall,PMPI_Startall\n"
".extern in_w\n"
".extern A_MPI_Startall\n"
".extern R_MPI_Startall\n"
".type PMPI_Startall,@function\n"
".text\n"
"PMPI_Startall:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x10, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Startall\n"
"jmp *A_MPI_Startall@GOTPCREL(%rip)\n"
"inwrap_MPI_Startall:\n"
"jmp *R_MPI_Startall@GOTPCREL(%rip)\n"
".size PMPI_Startall,.-PMPI_Startall\n"

);

int A_MPI_Startall(int count,A_MPI_Request array_of_requests[])
{
#ifdef DEBUG
printf("entre : A_MPI_Startall\n");
#endif
in_w=1;



R_MPI_Request *array_of_requests_tmp = malloc(sizeof(R_MPI_Request)*count);
int i1;
for(i1=0; i1 < count;i1++){
request_tab_conv_a2r(&array_of_requests[i1],&array_of_requests_tmp[i1]);
}
int ret_tmp= LOCAL_MPI_Startall( count, array_of_requests_tmp);
free(array_of_requests_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Startall\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Startall(int count,R_MPI_Request array_of_requests[])
{
#ifdef DEBUG
printf("entre : R_MPI_Startall\n");
#endif
int ret_tmp= LOCAL_MPI_Startall( count, array_of_requests);
#ifdef DEBUG
printf("sort : R_MPI_Startall\n");
#endif
return ret_tmp;
}
int MPI_Alltoallw(void * sendbuf,int * sendcounts[],int * sdispls[],R_MPI_Datatype * sendtypes[],void * recvbuf,int * recvcounts[],int * rdispls[],R_MPI_Datatype * recvtypes[],A_MPI_Comm comm);
int (*LOCAL_MPI_Alltoallw)(void *,int *,int *,R_MPI_Datatype *,void *,int *,int *,R_MPI_Datatype *,R_MPI_Comm);

__asm__(
".global PMPI_Alltoallw\n"
".weak MPI_Alltoallw\n"
".set MPI_Alltoallw,PMPI_Alltoallw\n"
".extern in_w\n"
".extern A_MPI_Alltoallw\n"
".extern R_MPI_Alltoallw\n"
".type PMPI_Alltoallw,@function\n"
".text\n"
"PMPI_Alltoallw:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Alltoallw\n"
"jmp *A_MPI_Alltoallw@GOTPCREL(%rip)\n"
"inwrap_MPI_Alltoallw:\n"
"jmp *R_MPI_Alltoallw@GOTPCREL(%rip)\n"
".size PMPI_Alltoallw,.-PMPI_Alltoallw\n"

);

int A_MPI_Alltoallw(void * sendbuf,int sendcounts[],int sdispls[],A_MPI_Datatype sendtypes[],void * recvbuf,int recvcounts[],int rdispls[],A_MPI_Datatype recvtypes[],A_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : A_MPI_Alltoallw\n");
#endif
in_w=1;
R_MPI_Comm comm_tmp1;
comm_conv_a2r(&comm,&comm_tmp1);
int Comm_size;
LOCAL_MPI_Comm_size(comm_tmp1, &Comm_size);
void * sendbuf_tmp;
const_buffer_conv_a2r(&sendbuf,&sendbuf_tmp);




R_MPI_Datatype *sendtypes_tmp = malloc(sizeof(R_MPI_Datatype)*Comm_size);
int i1;
for(i1=0; i1 < Comm_size;i1++){
datatype_conv_a2r(&sendtypes[i1],&sendtypes_tmp[i1]);
}
void * recvbuf_tmp;
buffer_conv_a2r(&recvbuf,&recvbuf_tmp);




R_MPI_Datatype *recvtypes_tmp = malloc(sizeof(R_MPI_Datatype)*Comm_size);
int i2;
for(i2=0; i2 < Comm_size;i2++){
datatype_conv_a2r(&recvtypes[i2],&recvtypes_tmp[i2]);
}
R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
int ret_tmp= LOCAL_MPI_Alltoallw( sendbuf_tmp, sendcounts, sdispls, sendtypes_tmp, recvbuf_tmp, recvcounts, rdispls, recvtypes_tmp, comm_tmp);
buffer_conv_r2a(&recvbuf,&recvbuf_tmp);
free(sendtypes_tmp);
free(recvtypes_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Alltoallw\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Alltoallw(void * sendbuf,int sendcounts[],int sdispls[],R_MPI_Datatype sendtypes[],void * recvbuf,int recvcounts[],int rdispls[],R_MPI_Datatype recvtypes[],R_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : R_MPI_Alltoallw\n");
#endif
int ret_tmp= LOCAL_MPI_Alltoallw( sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm);
#ifdef DEBUG
printf("sort : R_MPI_Alltoallw\n");
#endif
return ret_tmp;
}
int MPI_Reduce_scatter(void * sendbuf,void * recvbuf,int * recvcounts[],A_MPI_Datatype datatype,A_MPI_Op op,A_MPI_Comm comm);
int (*LOCAL_MPI_Reduce_scatter)(void *,void *,int *,R_MPI_Datatype,R_MPI_Op,R_MPI_Comm);

__asm__(
".global PMPI_Reduce_scatter\n"
".weak MPI_Reduce_scatter\n"
".set MPI_Reduce_scatter,PMPI_Reduce_scatter\n"
".extern in_w\n"
".extern A_MPI_Reduce_scatter\n"
".extern R_MPI_Reduce_scatter\n"
".type PMPI_Reduce_scatter,@function\n"
".text\n"
"PMPI_Reduce_scatter:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Reduce_scatter\n"
"jmp *A_MPI_Reduce_scatter@GOTPCREL(%rip)\n"
"inwrap_MPI_Reduce_scatter:\n"
"jmp *R_MPI_Reduce_scatter@GOTPCREL(%rip)\n"
".size PMPI_Reduce_scatter,.-PMPI_Reduce_scatter\n"

);

int A_MPI_Reduce_scatter(void * sendbuf,void * recvbuf,int recvcounts[],A_MPI_Datatype datatype,A_MPI_Op op,A_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : A_MPI_Reduce_scatter\n");
#endif
in_w=1;

void * sendbuf_tmp;
const_buffer_conv_a2r(&sendbuf,&sendbuf_tmp);
void * recvbuf_tmp;
buffer_conv_a2r(&recvbuf,&recvbuf_tmp);


R_MPI_Datatype datatype_tmp;
datatype_conv_a2r(&datatype,&datatype_tmp);
R_MPI_Op op_tmp;
op_conv_a2r(&op,&op_tmp);
R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);
int ret_tmp= LOCAL_MPI_Reduce_scatter( sendbuf_tmp, recvbuf_tmp, recvcounts, datatype_tmp, op_tmp, comm_tmp);
buffer_conv_r2a(&recvbuf,&recvbuf_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Reduce_scatter\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Reduce_scatter(void * sendbuf,void * recvbuf,int recvcounts[],R_MPI_Datatype datatype,R_MPI_Op op,R_MPI_Comm comm)
{
#ifdef DEBUG
printf("entre : R_MPI_Reduce_scatter\n");
#endif
int ret_tmp= LOCAL_MPI_Reduce_scatter( sendbuf, recvbuf, recvcounts, datatype, op, comm);
#ifdef DEBUG
printf("sort : R_MPI_Reduce_scatter\n");
#endif
return ret_tmp;
}
int MPI_Group_translate_ranks(A_MPI_Group group1,int n,int * ranks1[],A_MPI_Group group2,int * ranks2[]);
int (*LOCAL_MPI_Group_translate_ranks)(R_MPI_Group,int,int *,R_MPI_Group,int *);

__asm__(
".global PMPI_Group_translate_ranks\n"
".weak MPI_Group_translate_ranks\n"
".set MPI_Group_translate_ranks,PMPI_Group_translate_ranks\n"
".extern in_w\n"
".extern A_MPI_Group_translate_ranks\n"
".extern R_MPI_Group_translate_ranks\n"
".type PMPI_Group_translate_ranks,@function\n"
".text\n"
"PMPI_Group_translate_ranks:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Group_translate_ranks\n"
"jmp *A_MPI_Group_translate_ranks@GOTPCREL(%rip)\n"
"inwrap_MPI_Group_translate_ranks:\n"
"jmp *R_MPI_Group_translate_ranks@GOTPCREL(%rip)\n"
".size PMPI_Group_translate_ranks,.-PMPI_Group_translate_ranks\n"

);

int A_MPI_Group_translate_ranks(A_MPI_Group group1,int n,int ranks1[],A_MPI_Group group2,int ranks2[])
{
#ifdef DEBUG
printf("entre : A_MPI_Group_translate_ranks\n");
#endif
in_w=1;

R_MPI_Group group1_tmp;
group_conv_a2r(&group1,&group1_tmp);




R_MPI_Group group2_tmp;
group_conv_a2r(&group2,&group2_tmp);

int ret_tmp= LOCAL_MPI_Group_translate_ranks( group1_tmp, n, ranks1, group2_tmp, ranks2);

in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Group_translate_ranks\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Group_translate_ranks(R_MPI_Group group1,int n,int ranks1[],R_MPI_Group group2,int ranks2[])
{
#ifdef DEBUG
printf("entre : R_MPI_Group_translate_ranks\n");
#endif
int ret_tmp= LOCAL_MPI_Group_translate_ranks( group1, n, ranks1, group2, ranks2);
#ifdef DEBUG
printf("sort : R_MPI_Group_translate_ranks\n");
#endif
return ret_tmp;
}
int MPI_Group_incl(A_MPI_Group group,int n,int * ranks[],A_MPI_Group * newgroup);
int (*LOCAL_MPI_Group_incl)(R_MPI_Group,int,int *,R_MPI_Group *);

__asm__(
".global PMPI_Group_incl\n"
".weak MPI_Group_incl\n"
".set MPI_Group_incl,PMPI_Group_incl\n"
".extern in_w\n"
".extern A_MPI_Group_incl\n"
".extern R_MPI_Group_incl\n"
".type PMPI_Group_incl,@function\n"
".text\n"
"PMPI_Group_incl:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Group_incl\n"
"jmp *A_MPI_Group_incl@GOTPCREL(%rip)\n"
"inwrap_MPI_Group_incl:\n"
"jmp *R_MPI_Group_incl@GOTPCREL(%rip)\n"
".size PMPI_Group_incl,.-PMPI_Group_incl\n"

);

int A_MPI_Group_incl(A_MPI_Group group,int n,int ranks[],A_MPI_Group * newgroup)
{
#ifdef DEBUG
printf("entre : A_MPI_Group_incl\n");
#endif
in_w=1;

R_MPI_Group group_tmp;
group_conv_a2r(&group,&group_tmp);




R_MPI_Group  newgroup_ltmp;
R_MPI_Group * newgroup_tmp=&newgroup_ltmp;
int ret_tmp= LOCAL_MPI_Group_incl( group_tmp, n, ranks, newgroup_tmp);
group_conv_r2a(newgroup,newgroup_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Group_incl\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Group_incl(R_MPI_Group group,int n,int ranks[],R_MPI_Group * newgroup)
{
#ifdef DEBUG
printf("entre : R_MPI_Group_incl\n");
#endif
int ret_tmp= LOCAL_MPI_Group_incl( group, n, ranks, newgroup);
#ifdef DEBUG
printf("sort : R_MPI_Group_incl\n");
#endif
return ret_tmp;
}
int MPI_Group_excl(A_MPI_Group group,int n,int * ranks[],A_MPI_Group * newgroup);
int (*LOCAL_MPI_Group_excl)(R_MPI_Group,int,int *,R_MPI_Group *);

__asm__(
".global PMPI_Group_excl\n"
".weak MPI_Group_excl\n"
".set MPI_Group_excl,PMPI_Group_excl\n"
".extern in_w\n"
".extern A_MPI_Group_excl\n"
".extern R_MPI_Group_excl\n"
".type PMPI_Group_excl,@function\n"
".text\n"
"PMPI_Group_excl:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Group_excl\n"
"jmp *A_MPI_Group_excl@GOTPCREL(%rip)\n"
"inwrap_MPI_Group_excl:\n"
"jmp *R_MPI_Group_excl@GOTPCREL(%rip)\n"
".size PMPI_Group_excl,.-PMPI_Group_excl\n"

);

int A_MPI_Group_excl(A_MPI_Group group,int n,int ranks[],A_MPI_Group * newgroup)
{
#ifdef DEBUG
printf("entre : A_MPI_Group_excl\n");
#endif
in_w=1;

R_MPI_Group group_tmp;
group_conv_a2r(&group,&group_tmp);




R_MPI_Group  newgroup_ltmp;
R_MPI_Group * newgroup_tmp=&newgroup_ltmp;
int ret_tmp= LOCAL_MPI_Group_excl( group_tmp, n, ranks, newgroup_tmp);
group_conv_r2a(newgroup,newgroup_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Group_excl\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Group_excl(R_MPI_Group group,int n,int ranks[],R_MPI_Group * newgroup)
{
#ifdef DEBUG
printf("entre : R_MPI_Group_excl\n");
#endif
int ret_tmp= LOCAL_MPI_Group_excl( group, n, ranks, newgroup);
#ifdef DEBUG
printf("sort : R_MPI_Group_excl\n");
#endif
return ret_tmp;
}
int MPI_Group_range_incl(A_MPI_Group group,int n,int ranges[][3],A_MPI_Group * newgroup);
int (*LOCAL_MPI_Group_range_incl)(R_MPI_Group,int,int[][3],R_MPI_Group *);

__asm__(
".global PMPI_Group_range_incl\n"
".weak MPI_Group_range_incl\n"
".set MPI_Group_range_incl,PMPI_Group_range_incl\n"
".extern in_w\n"
".extern A_MPI_Group_range_incl\n"
".extern R_MPI_Group_range_incl\n"
".type PMPI_Group_range_incl,@function\n"
".text\n"
"PMPI_Group_range_incl:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Group_range_incl\n"
"jmp *A_MPI_Group_range_incl@GOTPCREL(%rip)\n"
"inwrap_MPI_Group_range_incl:\n"
"jmp *R_MPI_Group_range_incl@GOTPCREL(%rip)\n"
".size PMPI_Group_range_incl,.-PMPI_Group_range_incl\n"

);

int A_MPI_Group_range_incl(A_MPI_Group group,int n,int ranges[][3],A_MPI_Group * newgroup)
{
#ifdef DEBUG
printf("entre : A_MPI_Group_range_incl\n");
#endif
in_w=1;

R_MPI_Group group_tmp;
group_conv_a2r(&group,&group_tmp);




R_MPI_Group  newgroup_ltmp;
R_MPI_Group * newgroup_tmp=&newgroup_ltmp;
int ret_tmp= LOCAL_MPI_Group_range_incl( group_tmp, n, ranges, newgroup_tmp);
group_conv_r2a(newgroup,newgroup_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Group_range_incl\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Group_range_incl(R_MPI_Group group,int n,int ranges[][3],R_MPI_Group * newgroup)
{
#ifdef DEBUG
printf("entre : R_MPI_Group_range_incl\n");
#endif
int ret_tmp= LOCAL_MPI_Group_range_incl( group, n, ranges, newgroup);
#ifdef DEBUG
printf("sort : R_MPI_Group_range_incl\n");
#endif
return ret_tmp;
}
int MPI_Group_range_excl(A_MPI_Group group,int n,int ranges[][3],A_MPI_Group * newgroup);
int (*LOCAL_MPI_Group_range_excl)(R_MPI_Group,int,int[][3],R_MPI_Group *);

__asm__(
".global PMPI_Group_range_excl\n"
".weak MPI_Group_range_excl\n"
".set MPI_Group_range_excl,PMPI_Group_range_excl\n"
".extern in_w\n"
".extern A_MPI_Group_range_excl\n"
".extern R_MPI_Group_range_excl\n"
".type PMPI_Group_range_excl,@function\n"
".text\n"
"PMPI_Group_range_excl:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Group_range_excl\n"
"jmp *A_MPI_Group_range_excl@GOTPCREL(%rip)\n"
"inwrap_MPI_Group_range_excl:\n"
"jmp *R_MPI_Group_range_excl@GOTPCREL(%rip)\n"
".size PMPI_Group_range_excl,.-PMPI_Group_range_excl\n"

);

int A_MPI_Group_range_excl(A_MPI_Group group,int n,int ranges[][3],A_MPI_Group * newgroup)
{
#ifdef DEBUG
printf("entre : A_MPI_Group_range_excl\n");
#endif
in_w=1;

R_MPI_Group group_tmp;
group_conv_a2r(&group,&group_tmp);




R_MPI_Group  newgroup_ltmp;
R_MPI_Group * newgroup_tmp=&newgroup_ltmp;
int ret_tmp= LOCAL_MPI_Group_range_excl( group_tmp, n, ranges, newgroup_tmp);
group_conv_r2a(newgroup,newgroup_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Group_range_excl\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Group_range_excl(R_MPI_Group group,int n,int ranges[][3],R_MPI_Group * newgroup)
{
#ifdef DEBUG
printf("entre : R_MPI_Group_range_excl\n");
#endif
int ret_tmp= LOCAL_MPI_Group_range_excl( group, n, ranges, newgroup);
#ifdef DEBUG
printf("sort : R_MPI_Group_range_excl\n");
#endif
return ret_tmp;
}
int MPI_Cart_create(A_MPI_Comm comm_old,int ndims,int * dims[],int * periods[],int reorder,A_MPI_Comm * comm_cart);
int (*LOCAL_MPI_Cart_create)(R_MPI_Comm,int,int *,int *,int,R_MPI_Comm *);

__asm__(
".global PMPI_Cart_create\n"
".weak MPI_Cart_create\n"
".set MPI_Cart_create,PMPI_Cart_create\n"
".extern in_w\n"
".extern A_MPI_Cart_create\n"
".extern R_MPI_Cart_create\n"
".type PMPI_Cart_create,@function\n"
".text\n"
"PMPI_Cart_create:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Cart_create\n"
"jmp *A_MPI_Cart_create@GOTPCREL(%rip)\n"
"inwrap_MPI_Cart_create:\n"
"jmp *R_MPI_Cart_create@GOTPCREL(%rip)\n"
".size PMPI_Cart_create,.-PMPI_Cart_create\n"

);

int A_MPI_Cart_create(A_MPI_Comm comm_old,int ndims,int dims[],int periods[],int reorder,A_MPI_Comm * comm_cart)
{
#ifdef DEBUG
printf("entre : A_MPI_Cart_create\n");
#endif
in_w=1;

R_MPI_Comm comm_old_tmp;
comm_conv_a2r(&comm_old,&comm_old_tmp);








R_MPI_Comm  comm_cart_ltmp;
R_MPI_Comm * comm_cart_tmp=&comm_cart_ltmp;
int ret_tmp= LOCAL_MPI_Cart_create( comm_old_tmp, ndims, dims, periods, reorder, comm_cart_tmp);
comm_conv_r2a(comm_cart,comm_cart_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Cart_create\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Cart_create(R_MPI_Comm comm_old,int ndims,int dims[],int periods[],int reorder,R_MPI_Comm * comm_cart)
{
#ifdef DEBUG
printf("entre : R_MPI_Cart_create\n");
#endif
int ret_tmp= LOCAL_MPI_Cart_create( comm_old, ndims, dims, periods, reorder, comm_cart);
#ifdef DEBUG
printf("sort : R_MPI_Cart_create\n");
#endif
return ret_tmp;
}
int MPI_Dims_create(int nnodes,int ndims,int * dims[]);
int (*LOCAL_MPI_Dims_create)(int,int,int *);

__asm__(
".global PMPI_Dims_create\n"
".weak MPI_Dims_create\n"
".set MPI_Dims_create,PMPI_Dims_create\n"
".extern in_w\n"
".extern A_MPI_Dims_create\n"
".extern R_MPI_Dims_create\n"
".type PMPI_Dims_create,@function\n"
".text\n"
"PMPI_Dims_create:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Dims_create\n"
"jmp *A_MPI_Dims_create@GOTPCREL(%rip)\n"
"inwrap_MPI_Dims_create:\n"
"jmp *R_MPI_Dims_create@GOTPCREL(%rip)\n"
".size PMPI_Dims_create,.-PMPI_Dims_create\n"

);

int A_MPI_Dims_create(int nnodes,int ndims,int dims[])
{
#ifdef DEBUG
printf("entre : A_MPI_Dims_create\n");
#endif
in_w=1;







int ret_tmp= LOCAL_MPI_Dims_create( nnodes, ndims, dims);

in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Dims_create\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Dims_create(int nnodes,int ndims,int dims[])
{
#ifdef DEBUG
printf("entre : R_MPI_Dims_create\n");
#endif
int ret_tmp= LOCAL_MPI_Dims_create( nnodes, ndims, dims);
#ifdef DEBUG
printf("sort : R_MPI_Dims_create\n");
#endif
return ret_tmp;
}
int MPI_Graph_create(A_MPI_Comm comm_old,int nnodes,int * indx[],int * edges[],int reorder,A_MPI_Comm * comm_graph);
int (*LOCAL_MPI_Graph_create)(R_MPI_Comm,int,int *,int *,int,R_MPI_Comm *);

__asm__(
".global PMPI_Graph_create\n"
".weak MPI_Graph_create\n"
".set MPI_Graph_create,PMPI_Graph_create\n"
".extern in_w\n"
".extern A_MPI_Graph_create\n"
".extern R_MPI_Graph_create\n"
".type PMPI_Graph_create,@function\n"
".text\n"
"PMPI_Graph_create:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Graph_create\n"
"jmp *A_MPI_Graph_create@GOTPCREL(%rip)\n"
"inwrap_MPI_Graph_create:\n"
"jmp *R_MPI_Graph_create@GOTPCREL(%rip)\n"
".size PMPI_Graph_create,.-PMPI_Graph_create\n"

);

int A_MPI_Graph_create(A_MPI_Comm comm_old,int nnodes,int indx[],int edges[],int reorder,A_MPI_Comm * comm_graph)
{
#ifdef DEBUG
printf("entre : A_MPI_Graph_create\n");
#endif
in_w=1;

R_MPI_Comm comm_old_tmp;
comm_conv_a2r(&comm_old,&comm_old_tmp);








R_MPI_Comm  comm_graph_ltmp;
R_MPI_Comm * comm_graph_tmp=&comm_graph_ltmp;
int ret_tmp= LOCAL_MPI_Graph_create( comm_old_tmp, nnodes, indx, edges, reorder, comm_graph_tmp);
comm_conv_r2a(comm_graph,comm_graph_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Graph_create\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Graph_create(R_MPI_Comm comm_old,int nnodes,int indx[],int edges[],int reorder,R_MPI_Comm * comm_graph)
{
#ifdef DEBUG
printf("entre : R_MPI_Graph_create\n");
#endif
int ret_tmp= LOCAL_MPI_Graph_create( comm_old, nnodes, indx, edges, reorder, comm_graph);
#ifdef DEBUG
printf("sort : R_MPI_Graph_create\n");
#endif
return ret_tmp;
}
int MPI_Graph_get(A_MPI_Comm comm,int maxindex,int maxedges,int * indx[],int * edges[]);
int (*LOCAL_MPI_Graph_get)(R_MPI_Comm,int,int,int *,int *);

__asm__(
".global PMPI_Graph_get\n"
".weak MPI_Graph_get\n"
".set MPI_Graph_get,PMPI_Graph_get\n"
".extern in_w\n"
".extern A_MPI_Graph_get\n"
".extern R_MPI_Graph_get\n"
".type PMPI_Graph_get,@function\n"
".text\n"
"PMPI_Graph_get:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Graph_get\n"
"jmp *A_MPI_Graph_get@GOTPCREL(%rip)\n"
"inwrap_MPI_Graph_get:\n"
"jmp *R_MPI_Graph_get@GOTPCREL(%rip)\n"
".size PMPI_Graph_get,.-PMPI_Graph_get\n"

);

int A_MPI_Graph_get(A_MPI_Comm comm,int maxindex,int maxedges,int indx[],int edges[])
{
#ifdef DEBUG
printf("entre : A_MPI_Graph_get\n");
#endif
in_w=1;

R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);






int ret_tmp= LOCAL_MPI_Graph_get( comm_tmp, maxindex, maxedges, indx, edges);


in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Graph_get\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Graph_get(R_MPI_Comm comm,int maxindex,int maxedges,int indx[],int edges[])
{
#ifdef DEBUG
printf("entre : R_MPI_Graph_get\n");
#endif
int ret_tmp= LOCAL_MPI_Graph_get( comm, maxindex, maxedges, indx, edges);
#ifdef DEBUG
printf("sort : R_MPI_Graph_get\n");
#endif
return ret_tmp;
}
int MPI_Cart_get(A_MPI_Comm comm,int maxdims,int * dims[],int * periods[],int * coords[]);
int (*LOCAL_MPI_Cart_get)(R_MPI_Comm,int,int *,int *,int *);

__asm__(
".global PMPI_Cart_get\n"
".weak MPI_Cart_get\n"
".set MPI_Cart_get,PMPI_Cart_get\n"
".extern in_w\n"
".extern A_MPI_Cart_get\n"
".extern R_MPI_Cart_get\n"
".type PMPI_Cart_get,@function\n"
".text\n"
"PMPI_Cart_get:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Cart_get\n"
"jmp *A_MPI_Cart_get@GOTPCREL(%rip)\n"
"inwrap_MPI_Cart_get:\n"
"jmp *R_MPI_Cart_get@GOTPCREL(%rip)\n"
".size PMPI_Cart_get,.-PMPI_Cart_get\n"

);

int A_MPI_Cart_get(A_MPI_Comm comm,int maxdims,int dims[],int periods[],int coords[])
{
#ifdef DEBUG
printf("entre : A_MPI_Cart_get\n");
#endif
in_w=1;

R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);





int ret_tmp= LOCAL_MPI_Cart_get( comm_tmp, maxdims, dims, periods, coords);



in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Cart_get\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Cart_get(R_MPI_Comm comm,int maxdims,int dims[],int periods[],int coords[])
{
#ifdef DEBUG
printf("entre : R_MPI_Cart_get\n");
#endif
int ret_tmp= LOCAL_MPI_Cart_get( comm, maxdims, dims, periods, coords);
#ifdef DEBUG
printf("sort : R_MPI_Cart_get\n");
#endif
return ret_tmp;
}
int MPI_Cart_rank(A_MPI_Comm comm,int * coords[],int * rank);
int (*LOCAL_MPI_Cart_rank)(R_MPI_Comm,int *,int *);

__asm__(
".global PMPI_Cart_rank\n"
".weak MPI_Cart_rank\n"
".set MPI_Cart_rank,PMPI_Cart_rank\n"
".extern in_w\n"
".extern A_MPI_Cart_rank\n"
".extern R_MPI_Cart_rank\n"
".type PMPI_Cart_rank,@function\n"
".text\n"
"PMPI_Cart_rank:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Cart_rank\n"
"jmp *A_MPI_Cart_rank@GOTPCREL(%rip)\n"
"inwrap_MPI_Cart_rank:\n"
"jmp *R_MPI_Cart_rank@GOTPCREL(%rip)\n"
".size PMPI_Cart_rank,.-PMPI_Cart_rank\n"

);

int A_MPI_Cart_rank(A_MPI_Comm comm,int coords[],int * rank)
{
#ifdef DEBUG
printf("entre : A_MPI_Cart_rank\n");
#endif
in_w=1;

R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);



int ret_tmp= LOCAL_MPI_Cart_rank( comm_tmp, coords, rank);

in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Cart_rank\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Cart_rank(R_MPI_Comm comm,int coords[],int * rank)
{
#ifdef DEBUG
printf("entre : R_MPI_Cart_rank\n");
#endif
int ret_tmp= LOCAL_MPI_Cart_rank( comm, coords, rank);
#ifdef DEBUG
printf("sort : R_MPI_Cart_rank\n");
#endif
return ret_tmp;
}
int MPI_Cart_coords(A_MPI_Comm comm,int rank,int maxdims,int * coords[]);
int (*LOCAL_MPI_Cart_coords)(R_MPI_Comm,int,int,int *);

__asm__(
".global PMPI_Cart_coords\n"
".weak MPI_Cart_coords\n"
".set MPI_Cart_coords,PMPI_Cart_coords\n"
".extern in_w\n"
".extern A_MPI_Cart_coords\n"
".extern R_MPI_Cart_coords\n"
".type PMPI_Cart_coords,@function\n"
".text\n"
"PMPI_Cart_coords:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Cart_coords\n"
"jmp *A_MPI_Cart_coords@GOTPCREL(%rip)\n"
"inwrap_MPI_Cart_coords:\n"
"jmp *R_MPI_Cart_coords@GOTPCREL(%rip)\n"
".size PMPI_Cart_coords,.-PMPI_Cart_coords\n"

);

int A_MPI_Cart_coords(A_MPI_Comm comm,int rank,int maxdims,int coords[])
{
#ifdef DEBUG
printf("entre : A_MPI_Cart_coords\n");
#endif
in_w=1;

R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);





int ret_tmp= LOCAL_MPI_Cart_coords( comm_tmp, rank, maxdims, coords);

in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Cart_coords\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Cart_coords(R_MPI_Comm comm,int rank,int maxdims,int coords[])
{
#ifdef DEBUG
printf("entre : R_MPI_Cart_coords\n");
#endif
int ret_tmp= LOCAL_MPI_Cart_coords( comm, rank, maxdims, coords);
#ifdef DEBUG
printf("sort : R_MPI_Cart_coords\n");
#endif
return ret_tmp;
}
int MPI_Graph_neighbors(A_MPI_Comm comm,int rank,int maxneighbors,int * neighbors[]);
int (*LOCAL_MPI_Graph_neighbors)(R_MPI_Comm,int,int,int *);

__asm__(
".global PMPI_Graph_neighbors\n"
".weak MPI_Graph_neighbors\n"
".set MPI_Graph_neighbors,PMPI_Graph_neighbors\n"
".extern in_w\n"
".extern A_MPI_Graph_neighbors\n"
".extern R_MPI_Graph_neighbors\n"
".type PMPI_Graph_neighbors,@function\n"
".text\n"
"PMPI_Graph_neighbors:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Graph_neighbors\n"
"jmp *A_MPI_Graph_neighbors@GOTPCREL(%rip)\n"
"inwrap_MPI_Graph_neighbors:\n"
"jmp *R_MPI_Graph_neighbors@GOTPCREL(%rip)\n"
".size PMPI_Graph_neighbors,.-PMPI_Graph_neighbors\n"

);

int A_MPI_Graph_neighbors(A_MPI_Comm comm,int rank,int maxneighbors,int neighbors[])
{
#ifdef DEBUG
printf("entre : A_MPI_Graph_neighbors\n");
#endif
in_w=1;

R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);





int ret_tmp= LOCAL_MPI_Graph_neighbors( comm_tmp, rank, maxneighbors, neighbors);

in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Graph_neighbors\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Graph_neighbors(R_MPI_Comm comm,int rank,int maxneighbors,int neighbors[])
{
#ifdef DEBUG
printf("entre : R_MPI_Graph_neighbors\n");
#endif
int ret_tmp= LOCAL_MPI_Graph_neighbors( comm, rank, maxneighbors, neighbors);
#ifdef DEBUG
printf("sort : R_MPI_Graph_neighbors\n");
#endif
return ret_tmp;
}
int MPI_Cart_sub(A_MPI_Comm comm,int * remain_dims[],A_MPI_Comm * newcomm);
int (*LOCAL_MPI_Cart_sub)(R_MPI_Comm,int *,R_MPI_Comm *);

__asm__(
".global PMPI_Cart_sub\n"
".weak MPI_Cart_sub\n"
".set MPI_Cart_sub,PMPI_Cart_sub\n"
".extern in_w\n"
".extern A_MPI_Cart_sub\n"
".extern R_MPI_Cart_sub\n"
".type PMPI_Cart_sub,@function\n"
".text\n"
"PMPI_Cart_sub:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x20, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Cart_sub\n"
"jmp *A_MPI_Cart_sub@GOTPCREL(%rip)\n"
"inwrap_MPI_Cart_sub:\n"
"jmp *R_MPI_Cart_sub@GOTPCREL(%rip)\n"
".size PMPI_Cart_sub,.-PMPI_Cart_sub\n"

);

int A_MPI_Cart_sub(A_MPI_Comm comm,int remain_dims[],A_MPI_Comm * newcomm)
{
#ifdef DEBUG
printf("entre : A_MPI_Cart_sub\n");
#endif
in_w=1;

R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);


R_MPI_Comm  newcomm_ltmp;
R_MPI_Comm * newcomm_tmp=&newcomm_ltmp;
int ret_tmp= LOCAL_MPI_Cart_sub( comm_tmp, remain_dims, newcomm_tmp);
comm_conv_r2a(newcomm,newcomm_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Cart_sub\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Cart_sub(R_MPI_Comm comm,int remain_dims[],R_MPI_Comm * newcomm)
{
#ifdef DEBUG
printf("entre : R_MPI_Cart_sub\n");
#endif
int ret_tmp= LOCAL_MPI_Cart_sub( comm, remain_dims, newcomm);
#ifdef DEBUG
printf("sort : R_MPI_Cart_sub\n");
#endif
return ret_tmp;
}
int MPI_Cart_map(A_MPI_Comm comm,int ndims,int * dims[],int * periods[],int * newrank);
int (*LOCAL_MPI_Cart_map)(R_MPI_Comm,int,int *,int *,int *);

__asm__(
".global PMPI_Cart_map\n"
".weak MPI_Cart_map\n"
".set MPI_Cart_map,PMPI_Cart_map\n"
".extern in_w\n"
".extern A_MPI_Cart_map\n"
".extern R_MPI_Cart_map\n"
".type PMPI_Cart_map,@function\n"
".text\n"
"PMPI_Cart_map:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Cart_map\n"
"jmp *A_MPI_Cart_map@GOTPCREL(%rip)\n"
"inwrap_MPI_Cart_map:\n"
"jmp *R_MPI_Cart_map@GOTPCREL(%rip)\n"
".size PMPI_Cart_map,.-PMPI_Cart_map\n"

);

int A_MPI_Cart_map(A_MPI_Comm comm,int ndims,int dims[],int periods[],int * newrank)
{
#ifdef DEBUG
printf("entre : A_MPI_Cart_map\n");
#endif
in_w=1;

R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);







int ret_tmp= LOCAL_MPI_Cart_map( comm_tmp, ndims, dims, periods, newrank);

in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Cart_map\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Cart_map(R_MPI_Comm comm,int ndims,int dims[],int periods[],int * newrank)
{
#ifdef DEBUG
printf("entre : R_MPI_Cart_map\n");
#endif
int ret_tmp= LOCAL_MPI_Cart_map( comm, ndims, dims, periods, newrank);
#ifdef DEBUG
printf("sort : R_MPI_Cart_map\n");
#endif
return ret_tmp;
}
int MPI_Graph_map(A_MPI_Comm comm,int nnodes,int * indx[],int * edges[],int * newrank);
int (*LOCAL_MPI_Graph_map)(R_MPI_Comm,int,int *,int *,int *);

__asm__(
".global PMPI_Graph_map\n"
".weak MPI_Graph_map\n"
".set MPI_Graph_map,PMPI_Graph_map\n"
".extern in_w\n"
".extern A_MPI_Graph_map\n"
".extern R_MPI_Graph_map\n"
".type PMPI_Graph_map,@function\n"
".text\n"
"PMPI_Graph_map:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Graph_map\n"
"jmp *A_MPI_Graph_map@GOTPCREL(%rip)\n"
"inwrap_MPI_Graph_map:\n"
"jmp *R_MPI_Graph_map@GOTPCREL(%rip)\n"
".size PMPI_Graph_map,.-PMPI_Graph_map\n"

);

int A_MPI_Graph_map(A_MPI_Comm comm,int nnodes,int indx[],int edges[],int * newrank)
{
#ifdef DEBUG
printf("entre : A_MPI_Graph_map\n");
#endif
in_w=1;

R_MPI_Comm comm_tmp;
comm_conv_a2r(&comm,&comm_tmp);







int ret_tmp= LOCAL_MPI_Graph_map( comm_tmp, nnodes, indx, edges, newrank);

in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Graph_map\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Graph_map(R_MPI_Comm comm,int nnodes,int indx[],int edges[],int * newrank)
{
#ifdef DEBUG
printf("entre : R_MPI_Graph_map\n");
#endif
int ret_tmp= LOCAL_MPI_Graph_map( comm, nnodes, indx, edges, newrank);
#ifdef DEBUG
printf("sort : R_MPI_Graph_map\n");
#endif
return ret_tmp;
}
int MPI_Type_create_darray(int size,int rank,int ndims,int * array_of_gsizes[],int * array_of_distribs[],int * array_of_dargs[],int * array_of_psizes[],int order,A_MPI_Datatype oldtype,A_MPI_Datatype * newtype);
int (*LOCAL_MPI_Type_create_darray)(int,int,int,int *,int *,int *,int *,int,R_MPI_Datatype,R_MPI_Datatype *);

__asm__(
".global PMPI_Type_create_darray\n"
".weak MPI_Type_create_darray\n"
".set MPI_Type_create_darray,PMPI_Type_create_darray\n"
".extern in_w\n"
".extern A_MPI_Type_create_darray\n"
".extern R_MPI_Type_create_darray\n"
".type PMPI_Type_create_darray,@function\n"
".text\n"
"PMPI_Type_create_darray:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Type_create_darray\n"
"jmp *A_MPI_Type_create_darray@GOTPCREL(%rip)\n"
"inwrap_MPI_Type_create_darray:\n"
"jmp *R_MPI_Type_create_darray@GOTPCREL(%rip)\n"
".size PMPI_Type_create_darray,.-PMPI_Type_create_darray\n"

);

int A_MPI_Type_create_darray(int size,int rank,int ndims,int array_of_gsizes[],int array_of_distribs[],int array_of_dargs[],int array_of_psizes[],int order,A_MPI_Datatype oldtype,A_MPI_Datatype * newtype)
{
#ifdef DEBUG
printf("entre : A_MPI_Type_create_darray\n");
#endif
in_w=1;















int order_tmp =0;
order2_conv_a2r(&order,&order_tmp);
R_MPI_Datatype oldtype_tmp;
datatype_conv_a2r(&oldtype,&oldtype_tmp);
R_MPI_Datatype  newtype_ltmp;
R_MPI_Datatype * newtype_tmp=&newtype_ltmp;
int ret_tmp= LOCAL_MPI_Type_create_darray( size, rank, ndims, array_of_gsizes, array_of_distribs, array_of_dargs, array_of_psizes, order_tmp, oldtype_tmp, newtype_tmp);
datatype_conv_r2a(newtype,newtype_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Type_create_darray\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Type_create_darray(int size,int rank,int ndims,int array_of_gsizes[],int array_of_distribs[],int array_of_dargs[],int array_of_psizes[],int order,R_MPI_Datatype oldtype,R_MPI_Datatype * newtype)
{
#ifdef DEBUG
printf("entre : R_MPI_Type_create_darray\n");
#endif
int ret_tmp= LOCAL_MPI_Type_create_darray( size, rank, ndims, array_of_gsizes, array_of_distribs, array_of_dargs, array_of_psizes, order, oldtype, newtype);
#ifdef DEBUG
printf("sort : R_MPI_Type_create_darray\n");
#endif
return ret_tmp;
}
int MPI_Type_create_hindexed(int count,int * array_of_blocklengths[],R_MPI_Aint * array_of_displacements[],A_MPI_Datatype oldtype,A_MPI_Datatype * newtype);
int (*LOCAL_MPI_Type_create_hindexed)(int,int *,R_MPI_Aint *,R_MPI_Datatype,R_MPI_Datatype *);

__asm__(
".global PMPI_Type_create_hindexed\n"
".weak MPI_Type_create_hindexed\n"
".set MPI_Type_create_hindexed,PMPI_Type_create_hindexed\n"
".extern in_w\n"
".extern A_MPI_Type_create_hindexed\n"
".extern R_MPI_Type_create_hindexed\n"
".type PMPI_Type_create_hindexed,@function\n"
".text\n"
"PMPI_Type_create_hindexed:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Type_create_hindexed\n"
"jmp *A_MPI_Type_create_hindexed@GOTPCREL(%rip)\n"
"inwrap_MPI_Type_create_hindexed:\n"
"jmp *R_MPI_Type_create_hindexed@GOTPCREL(%rip)\n"
".size PMPI_Type_create_hindexed,.-PMPI_Type_create_hindexed\n"

);

int A_MPI_Type_create_hindexed(int count,int array_of_blocklengths[],A_MPI_Aint array_of_displacements[],A_MPI_Datatype oldtype,A_MPI_Datatype * newtype)
{
#ifdef DEBUG
printf("entre : A_MPI_Type_create_hindexed\n");
#endif
in_w=1;





R_MPI_Aint *array_of_displacements_tmp = malloc(sizeof(R_MPI_Aint)*count);
int i2;
for(i2=0; i2 < count;i2++){
array_of_displacements_tmp[i2]= (R_MPI_Aint)array_of_displacements[i2];
}
R_MPI_Datatype oldtype_tmp;
datatype_conv_a2r(&oldtype,&oldtype_tmp);
R_MPI_Datatype  newtype_ltmp;
R_MPI_Datatype * newtype_tmp=&newtype_ltmp;
int ret_tmp= LOCAL_MPI_Type_create_hindexed( count, array_of_blocklengths, array_of_displacements_tmp, oldtype_tmp, newtype_tmp);
datatype_conv_r2a(newtype,newtype_tmp);
free(array_of_displacements_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Type_create_hindexed\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Type_create_hindexed(int count,int array_of_blocklengths[],R_MPI_Aint array_of_displacements[],R_MPI_Datatype oldtype,R_MPI_Datatype * newtype)
{
#ifdef DEBUG
printf("entre : R_MPI_Type_create_hindexed\n");
#endif
int ret_tmp= LOCAL_MPI_Type_create_hindexed( count, array_of_blocklengths, array_of_displacements, oldtype, newtype);
#ifdef DEBUG
printf("sort : R_MPI_Type_create_hindexed\n");
#endif
return ret_tmp;
}
int MPI_Type_create_struct(int count,int * array_of_blocklengths[],R_MPI_Aint * array_of_displacements[],R_MPI_Datatype * array_of_types[],A_MPI_Datatype * newtype);
int (*LOCAL_MPI_Type_create_struct)(int,int *,R_MPI_Aint *,R_MPI_Datatype *,R_MPI_Datatype *);

__asm__(
".global PMPI_Type_create_struct\n"
".weak MPI_Type_create_struct\n"
".set MPI_Type_create_struct,PMPI_Type_create_struct\n"
".extern in_w\n"
".extern A_MPI_Type_create_struct\n"
".extern R_MPI_Type_create_struct\n"
".type PMPI_Type_create_struct,@function\n"
".text\n"
"PMPI_Type_create_struct:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Type_create_struct\n"
"jmp *A_MPI_Type_create_struct@GOTPCREL(%rip)\n"
"inwrap_MPI_Type_create_struct:\n"
"jmp *R_MPI_Type_create_struct@GOTPCREL(%rip)\n"
".size PMPI_Type_create_struct,.-PMPI_Type_create_struct\n"

);

int A_MPI_Type_create_struct(int count,int array_of_blocklengths[],A_MPI_Aint array_of_displacements[],A_MPI_Datatype array_of_types[],A_MPI_Datatype * newtype)
{
#ifdef DEBUG
printf("entre : A_MPI_Type_create_struct\n");
#endif
in_w=1;





R_MPI_Aint *array_of_displacements_tmp = malloc(sizeof(R_MPI_Aint)*count);
int i2;
for(i2=0; i2 < count;i2++){
array_of_displacements_tmp[i2]= (R_MPI_Aint)array_of_displacements[i2];
}
R_MPI_Datatype *array_of_types_tmp = malloc(sizeof(R_MPI_Datatype)*count);
int i3;
for(i3=0; i3 < count;i3++){
datatype_conv_a2r(&array_of_types[i3],&array_of_types_tmp[i3]);
}
R_MPI_Datatype  newtype_ltmp;
R_MPI_Datatype * newtype_tmp=&newtype_ltmp;
int ret_tmp= LOCAL_MPI_Type_create_struct( count, array_of_blocklengths, array_of_displacements_tmp, array_of_types_tmp, newtype_tmp);
datatype_conv_r2a(newtype,newtype_tmp);
free(array_of_displacements_tmp);
free(array_of_types_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Type_create_struct\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Type_create_struct(int count,int array_of_blocklengths[],R_MPI_Aint array_of_displacements[],R_MPI_Datatype array_of_types[],R_MPI_Datatype * newtype)
{
#ifdef DEBUG
printf("entre : R_MPI_Type_create_struct\n");
#endif
int ret_tmp= LOCAL_MPI_Type_create_struct( count, array_of_blocklengths, array_of_displacements, array_of_types, newtype);
#ifdef DEBUG
printf("sort : R_MPI_Type_create_struct\n");
#endif
return ret_tmp;
}
int MPI_Type_create_subarray(int ndims,int * array_of_sizes[],int * array_of_subsizes[],int * array_of_starts[],int order,A_MPI_Datatype oldtype,A_MPI_Datatype * newtype);
int (*LOCAL_MPI_Type_create_subarray)(int,int *,int *,int *,int,R_MPI_Datatype,R_MPI_Datatype *);

__asm__(
".global PMPI_Type_create_subarray\n"
".weak MPI_Type_create_subarray\n"
".set MPI_Type_create_subarray,PMPI_Type_create_subarray\n"
".extern in_w\n"
".extern A_MPI_Type_create_subarray\n"
".extern R_MPI_Type_create_subarray\n"
".type PMPI_Type_create_subarray,@function\n"
".text\n"
"PMPI_Type_create_subarray:\n"
"push %rbp\n"
"mov %rsp, %rbp\n"
"sub $0x30, %rsp\n"
"mov %rdi, -0x8(%rbp)\n"
"mov %rsi, -0x10(%rbp)\n"
"mov %rdx, -0x18(%rbp)\n"
"mov %rcx, -0x20(%rbp)\n"
"mov %r8, -0x28(%rbp)\n"
"mov %r9, -0x30(%rbp)\n"
".byte 0x66\n"
"leaq in_w@tlsgd(%rip), %rdi\n"
".value 0x6666\n"
"rex64\n"
"call __tls_get_addr@PLT\n"
"mov -0x8(%rbp), %rdi\n"
"mov -0x10(%rbp), %rsi\n"
"mov -0x18(%rbp), %rdx\n"
"mov -0x20(%rbp), %rcx\n"
"mov -0x28(%rbp), %r8\n"
"mov -0x30(%rbp), %r9\n"
"leave\n"
"cmpl $0x0, 0x0(%rax)\n"
"jne inwrap_MPI_Type_create_subarray\n"
"jmp *A_MPI_Type_create_subarray@GOTPCREL(%rip)\n"
"inwrap_MPI_Type_create_subarray:\n"
"jmp *R_MPI_Type_create_subarray@GOTPCREL(%rip)\n"
".size PMPI_Type_create_subarray,.-PMPI_Type_create_subarray\n"

);

int A_MPI_Type_create_subarray(int ndims,int array_of_sizes[],int array_of_subsizes[],int array_of_starts[],int order,A_MPI_Datatype oldtype,A_MPI_Datatype * newtype)
{
#ifdef DEBUG
printf("entre : A_MPI_Type_create_subarray\n");
#endif
in_w=1;









int order_tmp =0;
order_conv_a2r(&order,&order_tmp);
R_MPI_Datatype oldtype_tmp;
datatype_conv_a2r(&oldtype,&oldtype_tmp);
R_MPI_Datatype  newtype_ltmp;
R_MPI_Datatype * newtype_tmp=&newtype_ltmp;
int ret_tmp= LOCAL_MPI_Type_create_subarray( ndims, array_of_sizes, array_of_subsizes, array_of_starts, order_tmp, oldtype_tmp, newtype_tmp);
datatype_conv_r2a(newtype,newtype_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Type_create_subarray\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Type_create_subarray(int ndims,int array_of_sizes[],int array_of_subsizes[],int array_of_starts[],int order,R_MPI_Datatype oldtype,R_MPI_Datatype * newtype)
{
#ifdef DEBUG
printf("entre : R_MPI_Type_create_subarray\n");
#endif
int ret_tmp= LOCAL_MPI_Type_create_subarray( ndims, array_of_sizes, array_of_subsizes, array_of_starts, order, oldtype, newtype);
#ifdef DEBUG
printf("sort : R_MPI_Type_create_subarray\n");
#endif
return ret_tmp;
}
#ifdef OMPI_OMPI
#endif
__attribute__((constructor)) void wrapper_init(void) {
void *lib_handle=dlopen(getenv("TRUE_MPI_LIB"),RTLD_NOW|RTLD_GLOBAL);
LOCAL_MPI_Keyval_create=dlsym(lib_handle,"PMPI_Keyval_create"); /* replaced by MPI_Comm_create_keyval */
LOCAL_MPI_Keyval_free=dlsym(lib_handle,"PMPI_Keyval_free"); /* replaced by MPI_Comm_free_keyval */
LOCAL_MPI_Comm_create_keyval=dlsym(lib_handle,"PMPI_Comm_create_keyval");
LOCAL_MPI_Comm_free_keyval=dlsym(lib_handle,"PMPI_Comm_free_keyval");

LOCAL_MPI_Send=dlsym(lib_handle,"PMPI_Send");
LOCAL_MPI_Recv=dlsym(lib_handle,"PMPI_Recv");
LOCAL_MPI_Get_count=dlsym(lib_handle,"PMPI_Get_count");
LOCAL_MPI_Bsend=dlsym(lib_handle,"PMPI_Bsend");
LOCAL_MPI_Ssend=dlsym(lib_handle,"PMPI_Ssend");
LOCAL_MPI_Rsend=dlsym(lib_handle,"PMPI_Rsend");
LOCAL_MPI_Buffer_attach=dlsym(lib_handle,"PMPI_Buffer_attach");
LOCAL_MPI_Buffer_detach=dlsym(lib_handle,"PMPI_Buffer_detach");
LOCAL_MPI_Isend=dlsym(lib_handle,"PMPI_Isend");
LOCAL_MPI_Ibsend=dlsym(lib_handle,"PMPI_Ibsend");
LOCAL_MPI_Issend=dlsym(lib_handle,"PMPI_Issend");
LOCAL_MPI_Irsend=dlsym(lib_handle,"PMPI_Irsend");
LOCAL_MPI_Irecv=dlsym(lib_handle,"PMPI_Irecv");
LOCAL_MPI_Wait=dlsym(lib_handle,"PMPI_Wait");
LOCAL_MPI_Test=dlsym(lib_handle,"PMPI_Test");
LOCAL_MPI_Request_free=dlsym(lib_handle,"PMPI_Request_free");
LOCAL_MPI_Iprobe=dlsym(lib_handle,"PMPI_Iprobe");
LOCAL_MPI_Probe=dlsym(lib_handle,"PMPI_Probe");
LOCAL_MPI_Cancel=dlsym(lib_handle,"PMPI_Cancel");
LOCAL_MPI_Test_cancelled=dlsym(lib_handle,"PMPI_Test_cancelled");
LOCAL_MPI_Send_init=dlsym(lib_handle,"PMPI_Send_init");
LOCAL_MPI_Bsend_init=dlsym(lib_handle,"PMPI_Bsend_init");
LOCAL_MPI_Ssend_init=dlsym(lib_handle,"PMPI_Ssend_init");
LOCAL_MPI_Rsend_init=dlsym(lib_handle,"PMPI_Rsend_init");
LOCAL_MPI_Recv_init=dlsym(lib_handle,"PMPI_Recv_init");
LOCAL_MPI_Start=dlsym(lib_handle,"PMPI_Start");
LOCAL_MPI_Sendrecv=dlsym(lib_handle,"PMPI_Sendrecv");
LOCAL_MPI_Sendrecv_replace=dlsym(lib_handle,"PMPI_Sendrecv_replace");
LOCAL_MPI_Type_contiguous=dlsym(lib_handle,"PMPI_Type_contiguous");
LOCAL_MPI_Type_vector=dlsym(lib_handle,"PMPI_Type_vector");
LOCAL_MPI_Type_hvector=dlsym(lib_handle,"PMPI_Type_hvector");
LOCAL_MPI_Type_indexed=dlsym(lib_handle,"PMPI_Type_indexed");
LOCAL_MPI_Type_hindexed=dlsym(lib_handle,"PMPI_Type_hindexed");
LOCAL_MPI_Type_struct=dlsym(lib_handle,"PMPI_Type_struct");
LOCAL_MPI_Address=dlsym(lib_handle,"PMPI_Address");
LOCAL_MPI_Type_extent=dlsym(lib_handle,"PMPI_Type_extent");
LOCAL_MPI_Type_size=dlsym(lib_handle,"PMPI_Type_size");
LOCAL_MPI_Type_lb=dlsym(lib_handle,"PMPI_Type_lb");
LOCAL_MPI_Type_ub=dlsym(lib_handle,"PMPI_Type_ub");
LOCAL_MPI_Type_commit=dlsym(lib_handle,"PMPI_Type_commit");
LOCAL_MPI_Type_free=dlsym(lib_handle,"PMPI_Type_free");
LOCAL_MPI_Get_elements=dlsym(lib_handle,"PMPI_Get_elements");
LOCAL_MPI_Pack=dlsym(lib_handle,"PMPI_Pack");
LOCAL_MPI_Unpack=dlsym(lib_handle,"PMPI_Unpack");
LOCAL_MPI_Pack_size=dlsym(lib_handle,"PMPI_Pack_size");
LOCAL_MPI_Barrier=dlsym(lib_handle,"PMPI_Barrier");
LOCAL_MPI_Bcast=dlsym(lib_handle,"PMPI_Bcast");
LOCAL_MPI_Gather=dlsym(lib_handle,"PMPI_Gather");
LOCAL_MPI_Gatherv=dlsym(lib_handle,"PMPI_Gatherv");
LOCAL_MPI_Scatter=dlsym(lib_handle,"PMPI_Scatter");
LOCAL_MPI_Scatterv=dlsym(lib_handle,"PMPI_Scatterv");
LOCAL_MPI_Allgather=dlsym(lib_handle,"PMPI_Allgather");
LOCAL_MPI_Allgatherv=dlsym(lib_handle,"PMPI_Allgatherv");
LOCAL_MPI_Alltoall=dlsym(lib_handle,"PMPI_Alltoall");
LOCAL_MPI_Alltoallv=dlsym(lib_handle,"PMPI_Alltoallv");
LOCAL_MPI_Reduce=dlsym(lib_handle,"PMPI_Reduce");
LOCAL_MPI_Op_create=dlsym(lib_handle,"PMPI_Op_create");
LOCAL_MPI_Op_free=dlsym(lib_handle,"PMPI_Op_free");
LOCAL_MPI_Allreduce=dlsym(lib_handle,"PMPI_Allreduce");
LOCAL_MPI_Scan=dlsym(lib_handle,"PMPI_Scan");
LOCAL_MPI_Group_size=dlsym(lib_handle,"PMPI_Group_size");
LOCAL_MPI_Group_rank=dlsym(lib_handle,"PMPI_Group_rank");
LOCAL_MPI_Group_compare=dlsym(lib_handle,"PMPI_Group_compare");
LOCAL_MPI_Comm_group=dlsym(lib_handle,"PMPI_Comm_group");
LOCAL_MPI_Group_union=dlsym(lib_handle,"PMPI_Group_union");
LOCAL_MPI_Group_intersection=dlsym(lib_handle,"PMPI_Group_intersection");
LOCAL_MPI_Group_difference=dlsym(lib_handle,"PMPI_Group_difference");
LOCAL_MPI_Group_free=dlsym(lib_handle,"PMPI_Group_free");
LOCAL_MPI_Comm_size=dlsym(lib_handle,"PMPI_Comm_size");
LOCAL_MPI_Comm_rank=dlsym(lib_handle,"PMPI_Comm_rank");
LOCAL_MPI_Comm_compare=dlsym(lib_handle,"PMPI_Comm_compare");
LOCAL_MPI_Comm_dup=dlsym(lib_handle,"PMPI_Comm_dup");
LOCAL_MPI_Comm_create=dlsym(lib_handle,"PMPI_Comm_create");
LOCAL_MPI_Comm_split=dlsym(lib_handle,"PMPI_Comm_split");
LOCAL_MPI_Comm_free=dlsym(lib_handle,"PMPI_Comm_free");
LOCAL_MPI_Comm_test_inter=dlsym(lib_handle,"PMPI_Comm_test_inter");
LOCAL_MPI_Comm_remote_size=dlsym(lib_handle,"PMPI_Comm_remote_size");
LOCAL_MPI_Comm_remote_group=dlsym(lib_handle,"PMPI_Comm_remote_group");
LOCAL_MPI_Intercomm_create=dlsym(lib_handle,"PMPI_Intercomm_create");
LOCAL_MPI_Intercomm_merge=dlsym(lib_handle,"PMPI_Intercomm_merge");
LOCAL_MPI_Attr_put=dlsym(lib_handle,"PMPI_Attr_put");
LOCAL_MPI_Attr_get=dlsym(lib_handle,"PMPI_Attr_get");
LOCAL_MPI_Attr_delete=dlsym(lib_handle,"PMPI_Attr_delete");
LOCAL_MPI_Topo_test=dlsym(lib_handle,"PMPI_Topo_test");
LOCAL_MPI_Graphdims_get=dlsym(lib_handle,"PMPI_Graphdims_get");
LOCAL_MPI_Cartdim_get=dlsym(lib_handle,"PMPI_Cartdim_get");
LOCAL_MPI_Graph_neighbors_count=dlsym(lib_handle,"PMPI_Graph_neighbors_count");
LOCAL_MPI_Cart_shift=dlsym(lib_handle,"PMPI_Cart_shift");
LOCAL_MPI_Get_processor_name=dlsym(lib_handle,"PMPI_Get_processor_name");
LOCAL_MPI_Get_version=dlsym(lib_handle,"PMPI_Get_version");
LOCAL_MPI_Errhandler_create=dlsym(lib_handle,"PMPI_Errhandler_create");
LOCAL_MPI_Errhandler_set=dlsym(lib_handle,"PMPI_Errhandler_set");
LOCAL_MPI_Errhandler_get=dlsym(lib_handle,"PMPI_Errhandler_get");
LOCAL_MPI_Errhandler_free=dlsym(lib_handle,"PMPI_Errhandler_free");
LOCAL_MPI_Error_string=dlsym(lib_handle,"PMPI_Error_string");
LOCAL_MPI_Error_class=dlsym(lib_handle,"PMPI_Error_class");
LOCAL_MPI_Initialized=dlsym(lib_handle,"PMPI_Initialized");
LOCAL_MPI_Abort=dlsym(lib_handle,"PMPI_Abort");
LOCAL_MPI_Init=dlsym(lib_handle,"PMPI_Init");
LOCAL_MPI_Comm_delete_attr=dlsym(lib_handle,"PMPI_Comm_delete_attr");
LOCAL_MPI_Comm_get_attr=dlsym(lib_handle,"PMPI_Comm_get_attr");
LOCAL_MPI_Comm_set_attr=dlsym(lib_handle,"PMPI_Comm_set_attr");
LOCAL_MPI_Init_thread=dlsym(lib_handle,"PMPI_Init_thread");
LOCAL_MPI_Comm_create_errhandler=dlsym(lib_handle,"PMPI_Comm_create_errhandler");
LOCAL_MPI_Comm_get_errhandler=dlsym(lib_handle,"PMPI_Comm_get_errhandler");
LOCAL_MPI_Comm_set_errhandler=dlsym(lib_handle,"PMPI_Comm_set_errhandler");
LOCAL_MPI_File_get_errhandler=dlsym(lib_handle,"PMPI_File_get_errhandler");
LOCAL_MPI_File_set_errhandler=dlsym(lib_handle,"PMPI_File_set_errhandler");
LOCAL_MPI_Info_create=dlsym(lib_handle,"PMPI_Info_create");
LOCAL_MPI_Info_delete=dlsym(lib_handle,"PMPI_Info_delete");
LOCAL_MPI_Info_dup=dlsym(lib_handle,"PMPI_Info_dup");
LOCAL_MPI_Info_free=dlsym(lib_handle,"PMPI_Info_free");
LOCAL_MPI_Info_get=dlsym(lib_handle,"PMPI_Info_get");
LOCAL_MPI_Info_get_nkeys=dlsym(lib_handle,"PMPI_Info_get_nkeys");
LOCAL_MPI_Info_get_nthkey=dlsym(lib_handle,"PMPI_Info_get_nthkey");
LOCAL_MPI_Info_get_valuelen=dlsym(lib_handle,"PMPI_Info_get_valuelen");
LOCAL_MPI_Info_set=dlsym(lib_handle,"PMPI_Info_set");
LOCAL_MPI_Request_get_status=dlsym(lib_handle,"PMPI_Request_get_status");
LOCAL_MPI_Type_create_hvector=dlsym(lib_handle,"PMPI_Type_create_hvector");
LOCAL_MPI_Type_get_extent=dlsym(lib_handle,"PMPI_Type_get_extent");
LOCAL_MPI_File_open=dlsym(lib_handle,"PMPI_File_open");
LOCAL_MPI_File_close=dlsym(lib_handle,"PMPI_File_close");
LOCAL_MPI_File_delete=dlsym(lib_handle,"PMPI_File_delete");
LOCAL_MPI_File_set_size=dlsym(lib_handle,"PMPI_File_set_size");
LOCAL_MPI_File_preallocate=dlsym(lib_handle,"PMPI_File_preallocate");
LOCAL_MPI_File_get_size=dlsym(lib_handle,"PMPI_File_get_size");
LOCAL_MPI_File_get_group=dlsym(lib_handle,"PMPI_File_get_group");
LOCAL_MPI_File_get_amode=dlsym(lib_handle,"PMPI_File_get_amode");
LOCAL_MPI_File_set_info=dlsym(lib_handle,"PMPI_File_set_info");
LOCAL_MPI_File_get_info=dlsym(lib_handle,"PMPI_File_get_info");
LOCAL_MPI_File_set_view=dlsym(lib_handle,"PMPI_File_set_view");
LOCAL_MPI_File_get_view=dlsym(lib_handle,"PMPI_File_get_view");
LOCAL_MPI_File_read_at=dlsym(lib_handle,"PMPI_File_read_at");
LOCAL_MPI_File_read_at_all=dlsym(lib_handle,"PMPI_File_read_at_all");
LOCAL_MPI_File_write_at=dlsym(lib_handle,"PMPI_File_write_at");
LOCAL_MPI_File_write_at_all=dlsym(lib_handle,"PMPI_File_write_at_all");
LOCAL_MPI_File_iread_at=dlsym(lib_handle,"PMPI_File_iread_at");
LOCAL_MPI_File_iwrite_at=dlsym(lib_handle,"PMPI_File_iwrite_at");
LOCAL_MPI_File_read=dlsym(lib_handle,"PMPI_File_read");
LOCAL_MPI_File_read_all=dlsym(lib_handle,"PMPI_File_read_all");
LOCAL_MPI_File_write=dlsym(lib_handle,"PMPI_File_write");
LOCAL_MPI_File_write_all=dlsym(lib_handle,"PMPI_File_write_all");
LOCAL_MPI_File_iread=dlsym(lib_handle,"PMPI_File_iread");
LOCAL_MPI_File_iwrite=dlsym(lib_handle,"PMPI_File_iwrite");
LOCAL_MPI_File_seek=dlsym(lib_handle,"PMPI_File_seek");
LOCAL_MPI_File_get_position=dlsym(lib_handle,"PMPI_File_get_position");
LOCAL_MPI_File_get_byte_offset=dlsym(lib_handle,"PMPI_File_get_byte_offset");
LOCAL_MPI_File_read_shared=dlsym(lib_handle,"PMPI_File_read_shared");
LOCAL_MPI_File_write_shared=dlsym(lib_handle,"PMPI_File_write_shared");
LOCAL_MPI_File_iread_shared=dlsym(lib_handle,"PMPI_File_iread_shared");
LOCAL_MPI_File_iwrite_shared=dlsym(lib_handle,"PMPI_File_iwrite_shared");
LOCAL_MPI_File_read_ordered=dlsym(lib_handle,"PMPI_File_read_ordered");
LOCAL_MPI_File_write_ordered=dlsym(lib_handle,"PMPI_File_write_ordered");
LOCAL_MPI_File_seek_shared=dlsym(lib_handle,"PMPI_File_seek_shared");
LOCAL_MPI_File_get_position_shared=dlsym(lib_handle,"PMPI_File_get_position_shared");
LOCAL_MPI_File_read_at_all_begin=dlsym(lib_handle,"PMPI_File_read_at_all_begin");
LOCAL_MPI_File_read_at_all_end=dlsym(lib_handle,"PMPI_File_read_at_all_end");
LOCAL_MPI_File_write_at_all_begin=dlsym(lib_handle,"PMPI_File_write_at_all_begin");
LOCAL_MPI_File_write_at_all_end=dlsym(lib_handle,"PMPI_File_write_at_all_end");
LOCAL_MPI_File_read_all_begin=dlsym(lib_handle,"PMPI_File_read_all_begin");
LOCAL_MPI_File_read_all_end=dlsym(lib_handle,"PMPI_File_read_all_end");
LOCAL_MPI_File_write_all_begin=dlsym(lib_handle,"PMPI_File_write_all_begin");
LOCAL_MPI_File_write_all_end=dlsym(lib_handle,"PMPI_File_write_all_end");
LOCAL_MPI_File_read_ordered_begin=dlsym(lib_handle,"PMPI_File_read_ordered_begin");
LOCAL_MPI_File_read_ordered_end=dlsym(lib_handle,"PMPI_File_read_ordered_end");
LOCAL_MPI_File_write_ordered_begin=dlsym(lib_handle,"PMPI_File_write_ordered_begin");
LOCAL_MPI_File_write_ordered_end=dlsym(lib_handle,"PMPI_File_write_ordered_end");
LOCAL_MPI_File_get_type_extent=dlsym(lib_handle,"PMPI_File_get_type_extent");
LOCAL_MPI_Register_datarep=dlsym(lib_handle,"PMPI_Register_datarep");
LOCAL_MPI_File_set_atomicity=dlsym(lib_handle,"PMPI_File_set_atomicity");
LOCAL_MPI_File_get_atomicity=dlsym(lib_handle,"PMPI_File_get_atomicity");
LOCAL_MPI_File_sync=dlsym(lib_handle,"PMPI_File_sync");
LOCAL_MPI_Wtime=dlsym(lib_handle,"PMPI_Wtime");
LOCAL_MPI_Wtick=dlsym(lib_handle,"PMPI_Wtick");
LOCAL_MPI_Finalize=dlsym(lib_handle,"PMPI_Finalize");
LOCAL_MPI_Waitany=dlsym(lib_handle,"PMPI_Waitany");
LOCAL_MPI_Testany=dlsym(lib_handle,"PMPI_Testany");
LOCAL_MPI_Waitall=dlsym(lib_handle,"PMPI_Waitall");
LOCAL_MPI_Testall=dlsym(lib_handle,"PMPI_Testall");
LOCAL_MPI_Waitsome=dlsym(lib_handle,"PMPI_Waitsome");
LOCAL_MPI_Testsome=dlsym(lib_handle,"PMPI_Testsome");
LOCAL_MPI_Startall=dlsym(lib_handle,"PMPI_Startall");
LOCAL_MPI_Alltoallw=dlsym(lib_handle,"PMPI_Alltoallw");
LOCAL_MPI_Reduce_scatter=dlsym(lib_handle,"PMPI_Reduce_scatter");
LOCAL_MPI_Group_translate_ranks=dlsym(lib_handle,"PMPI_Group_translate_ranks");
LOCAL_MPI_Group_incl=dlsym(lib_handle,"PMPI_Group_incl");
LOCAL_MPI_Group_excl=dlsym(lib_handle,"PMPI_Group_excl");
LOCAL_MPI_Group_range_incl=dlsym(lib_handle,"PMPI_Group_range_incl");
LOCAL_MPI_Group_range_excl=dlsym(lib_handle,"PMPI_Group_range_excl");
LOCAL_MPI_Cart_create=dlsym(lib_handle,"PMPI_Cart_create");
LOCAL_MPI_Dims_create=dlsym(lib_handle,"PMPI_Dims_create");
LOCAL_MPI_Graph_create=dlsym(lib_handle,"PMPI_Graph_create");
LOCAL_MPI_Graph_get=dlsym(lib_handle,"PMPI_Graph_get");
LOCAL_MPI_Cart_get=dlsym(lib_handle,"PMPI_Cart_get");
LOCAL_MPI_Cart_rank=dlsym(lib_handle,"PMPI_Cart_rank");
LOCAL_MPI_Cart_coords=dlsym(lib_handle,"PMPI_Cart_coords");
LOCAL_MPI_Graph_neighbors=dlsym(lib_handle,"PMPI_Graph_neighbors");
LOCAL_MPI_Cart_sub=dlsym(lib_handle,"PMPI_Cart_sub");
LOCAL_MPI_Cart_map=dlsym(lib_handle,"PMPI_Cart_map");
LOCAL_MPI_Graph_map=dlsym(lib_handle,"PMPI_Graph_map");
LOCAL_MPI_Type_create_darray=dlsym(lib_handle,"PMPI_Type_create_darray");
LOCAL_MPI_Type_create_hindexed=dlsym(lib_handle,"PMPI_Type_create_hindexed");
LOCAL_MPI_Type_create_struct=dlsym(lib_handle,"PMPI_Type_create_struct");
LOCAL_MPI_Type_create_subarray=dlsym(lib_handle,"PMPI_Type_create_subarray");
datatype_translation_init();
communicator_translation_init();
request_translation_init();
operation_translation_init();
group_translation_init();
errhandler_translation_init();
file_translation_init();
info_translation_init();
//DATATYPE
datatype_translation_add_const(A_MPI_DATATYPE_NULL, R_MPI_DATATYPE_NULL);
datatype_translation_add_const(A_MPI_CHAR, R_MPI_CHAR);
datatype_translation_add_const(A_MPI_SIGNED_CHAR, R_MPI_SIGNED_CHAR);
datatype_translation_add_const(A_MPI_UNSIGNED_CHAR, R_MPI_UNSIGNED_CHAR);
datatype_translation_add_const(A_MPI_BYTE, R_MPI_BYTE);
datatype_translation_add_const(A_MPI_WCHAR, R_MPI_WCHAR);
datatype_translation_add_const(A_MPI_SHORT, R_MPI_SHORT);
datatype_translation_add_const(A_MPI_UNSIGNED_SHORT, R_MPI_UNSIGNED_SHORT);
datatype_translation_add_const(A_MPI_INT, R_MPI_INT);
datatype_translation_add_const(A_MPI_UNSIGNED, R_MPI_UNSIGNED);
datatype_translation_add_const(A_MPI_LONG, R_MPI_LONG);
datatype_translation_add_const(A_MPI_UNSIGNED_LONG, R_MPI_UNSIGNED_LONG);
datatype_translation_add_const(A_MPI_FLOAT, R_MPI_FLOAT);
datatype_translation_add_const(A_MPI_DOUBLE, R_MPI_DOUBLE);
datatype_translation_add_const(A_MPI_LONG_DOUBLE, R_MPI_LONG_DOUBLE);
datatype_translation_add_const(A_MPI_LONG_LONG_INT, R_MPI_LONG_LONG_INT);
datatype_translation_add_const(A_MPI_UNSIGNED_LONG_LONG, R_MPI_UNSIGNED_LONG_LONG);
datatype_translation_add_const(A_MPI_LONG_LONG, R_MPI_LONG_LONG);
datatype_translation_add_const(A_MPI_UB, R_MPI_UB);
datatype_translation_add_const(A_MPI_LB, R_MPI_LB);
datatype_translation_add_const(A_MPI_PACKED, R_MPI_PACKED);
datatype_translation_add_const(A_MPI_2INT, R_MPI_2INT);
datatype_translation_add_const(A_MPI_LONG_INT, R_MPI_LONG_INT);
datatype_translation_add_const(A_MPI_SHORT_INT, R_MPI_SHORT_INT);
datatype_translation_add_const(A_MPI_DOUBLE_INT, R_MPI_DOUBLE_INT);
datatype_translation_add_const(A_MPI_FLOAT_INT, R_MPI_FLOAT_INT);
datatype_translation_add_const(A_MPI_LONG_DOUBLE_INT, R_MPI_LONG_DOUBLE_INT);
datatype_translation_add_const(A_MPI_CHARACTER, R_MPI_CHARACTER);
datatype_translation_add_const(A_MPI_LOGICAL, R_MPI_LOGICAL);
datatype_translation_add_const(A_MPI_DOUBLE_COMPLEX, R_MPI_DOUBLE_COMPLEX);
datatype_translation_add_const(A_MPI_COMPLEX, R_MPI_COMPLEX);
datatype_translation_add_const(A_MPI_INTEGER, R_MPI_INTEGER);
datatype_translation_add_const(A_MPI_REAL, R_MPI_REAL);
datatype_translation_add_const(A_MPI_DOUBLE_PRECISION,R_MPI_DOUBLE_PRECISION);
//COMM
communicator_translation_add_const(A_MPI_COMM_WORLD, R_MPI_COMM_WORLD);
communicator_translation_add_const(A_MPI_COMM_SELF, R_MPI_COMM_SELF);
communicator_translation_add_const(A_MPI_COMM_NULL, R_MPI_COMM_NULL);
//REQUEST
request_translation_add_const(A_MPI_REQUEST_NULL, R_MPI_REQUEST_NULL);
//OP
operation_translation_add_const(A_MPI_OP_NULL, R_MPI_OP_NULL);
operation_translation_add_const(A_MPI_MAX, R_MPI_MAX);
operation_translation_add_const(A_MPI_MIN, R_MPI_MIN);
operation_translation_add_const(A_MPI_SUM, R_MPI_SUM);
operation_translation_add_const(A_MPI_PROD, R_MPI_PROD);
operation_translation_add_const(A_MPI_MAXLOC, R_MPI_MAXLOC);
operation_translation_add_const(A_MPI_MINLOC, R_MPI_MINLOC);
operation_translation_add_const(A_MPI_BAND, R_MPI_BAND);
operation_translation_add_const(A_MPI_BOR, R_MPI_BOR);
operation_translation_add_const(A_MPI_BXOR, R_MPI_BXOR);
operation_translation_add_const(A_MPI_LAND, R_MPI_LAND);
operation_translation_add_const(A_MPI_LOR, R_MPI_LOR);
operation_translation_add_const(A_MPI_LXOR, R_MPI_LXOR);
operation_translation_add_const(A_MPI_REPLACE, R_MPI_REPLACE);
//operation_translation_add_const(A_MPI_SAME_MODE, R_MPI_SAME_MODE);
//GROUP
group_translation_add_const(A_MPI_GROUP_NULL, R_MPI_GROUP_NULL);
group_translation_add_const(A_MPI_GROUP_EMPTY, R_MPI_GROUP_EMPTY);
//ERRHANDLER
errhandler_translation_add_const(A_MPI_ERRHANDLER_NULL,R_MPI_ERRHANDLER_NULL);
errhandler_translation_add_const(A_MPI_ERRORS_ARE_FATAL,R_MPI_ERRORS_ARE_FATAL);
errhandler_translation_add_const(A_MPI_ERRORS_RETURN, R_MPI_ERRORS_RETURN);
//FILE
file_translation_add_const(A_MPI_FILE_NULL, R_MPI_FILE_NULL);
//INFO
info_translation_add_const(A_MPI_INFO_NULL, R_MPI_INFO_NULL);


}

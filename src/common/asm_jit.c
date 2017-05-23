#include "mappers.h"
extern __thread int in_w;

/*** JIT Users typedefs***/
//MPI_Op_create: (DONE)
//- typedef void (MPI_User_function)(void *, void *, int *, MPI_Datatype *);
//MPI_Register_datarep:(DONE)
//-	typedef int (MPI_Datarep_extent_function)(MPI_Datatype, MPI_Aint *, void *);
//-	typedef int (MPI_Datarep_conversion_function)(void *, MPI_Datatype, int, void *, MPI_Offset, void *);
//MPI_Grequest_start:(DONE) 
//- typedef int (MPI_Grequest_query_function)(void *, MPI_Status *);
//- typedef int (MPI_Grequest_free_function)(void *);									No conversion is needed
//- typedef int (MPI_Grequest_cancel_function)(void *, int)						No conversion is needed

/*** The keyval user function are handled in a different way ***/
//MPI_Create_keyval:(DONE)
//-	typedef int (MPI_Copy_function)(MPI_Comm, int, void *,void *, void *, int *);
//-	typedef int (MPI_Delete_function)(MPI_Comm, int, void *, void *);
//MPI_Comm_create_keyval:(DONE)
//- typedef int (MPI_Comm_copy_attr_function)(MPI_Comm, int, void *,void *, void *, int *);
//- typedef int (MPI_Comm_delete_attr_function)(MPI_Comm, int, void *, void *);
//MPI_Type_create_keyval:(DONE)
//- typedef int (MPI_Type_copy_attr_function)(MPI_Datatype, int, void *,void *, void *, int *);
//- typedef int (MPI_Type_delete_attr_function)(MPI_Datatype, int,void *, void *);
//MPI_Win_create_keyval:(DONE)
//- typedef int (MPI_Win_copy_attr_function)(MPI_Win, int, void *, void *, void *, int *);
//- typedef int (MPI_Win_delete_attr_function)(MPI_Win, int, void *, void *);

/*** Handled by wrapper ***/
//MPI_Comm_create_errhandler:
//- typedef void (MPI_Comm_errhandler_function)(MPI_Comm *, int *, ...); typedef MPI_Comm_errhandler_function MPI_Comm_errhandler_fn; // MPI_COMM_Errhandler_fn deprecated
//MPI_Errhandler_create
//- typedef void (MPI_Handler_function)(MPI_Comm *, int *, ...);

/*** The following user typedef variadic funtion are not implemented yet ***/
//MPI_File_create_errhandler
//- typedef void (ompi_file_errhandler_fn)(MPI_File *, int *, ...); typedef ompi_file_errhandler_fn MPI_File_errhandler_fn; typedef ompi_file_errhandler_fn MPI_File_errhandler_function; //MPI_File_errhandler_fn deprecated
//MPI_Win_create_errhandler:
//- typedef void (MPI_Win_errhandler_function)(MPI_Win *, int *, ...); typedef MPI_Win_errhandler_function MPI_Win_errhandler_fn; //MPI_Win_errhandler_fn deprecated

//MPI_User_function(void *, void *, int *, MPI_Datatype *);
__asm__(
".global user_fn_wrapper_template\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"user_fn_wrapper_template:\n"
"  call peip_user_fn\n"
"peip_user_fn:\n"
"  pop %rax\n"
"  sub $0x15,%rax\n"
"  mov %rax,%r9\n"
"  mov %rdi,%rax\n"
"  push   %rbp\n"
"  mov    %rsp,%rbp\n"
"  sub    $0x30,%rsp\n"
"  mov    %rdi,-0x18(%rbp)\n"
"  mov    %rsi,-0x20(%rbp)\n"
"  mov    %edx,-0x24(%rbp)\n"
"  mov    %rcx,-0x30(%rbp)\n"
"  movq   $0x0,-0x8(%rbp)\n"
"  movq   0x0(%r9),%r8\n"
"  callq  *0x8(%r9)\n"
"  leaveq \n"
"  retq \n"
);     
int user_func_resolved(void *a,void *b,int *c,R_MPI_Datatype *d,void (*pf)(void *in,void *out,int *len,A_MPI_Datatype *data_type))
{
   A_MPI_Datatype tmp;
   datatype_conv_r2a(&tmp,d);
	 in_w=0;
   pf(a,b,c,&tmp);
	 in_w=1;
}
//MPI_Datarep_extent_function)(MPI_Datatype, MPI_Aint *, void *);
__asm__(
".global user_datarep_extent_function_template\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"user_datarep_extent_function_template:\n"
"  call peip_datarep_extent_func\n"
"peip_datarep_extent_func:\n"
"  pop %rax\n"
"  sub $0x15,%rax\n"
"  mov %rax,%r9\n"
"  mov %rdi,%rax\n"
"  push   %rbp\n"
"  mov    %rsp,%rbp\n"
"  sub    $0x20,%rsp\n"
"	 mov    %rdi,-0x8(%rbp)\n"
"	 mov    %rsi,-0x10(%rbp)\n"
"	 mov    %rdx,-0x18(%rbp)\n"
"	 mov    %rcx,-0x20(%rbp) \n"
"  movq   0x0(%r9),%r8\n"
"  callq  *0x8(%r9)\n"
"  leaveq \n"
"  retq \n"
);     
int datarep_extent_func_resolved(R_MPI_Datatype a, R_MPI_Aint *b, void *c, int (*pf)(A_MPI_Datatype data_type, A_MPI_Aint *file_extent, void *extra_state))
{
   A_MPI_Datatype tmp;
   datatype_conv_r2a(&tmp,&a);
	 in_w=0;
   pf(tmp,(A_MPI_Aint*)b,c);
	 in_w=1;
}
//int (MPI_Datarep_conversion_function)(void *, MPI_Datatype, int, void *, MPI_Offset, void *);
__asm__(
".global user_datarep_connversion_function_template\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"user_datarep_conversion_function_template:\n"
"  call peip_datarep_conversion_func\n"
"peip_datarep_conversion_func:\n"
"  pop %rax\n"
"  sub $0x15,%rax\n"
"  mov %rax,%r15\n"
"  mov %rdi,%rax\n"
"  push   %rbp\n"
"  mov    %rsp,%rbp\n"
"  sub    $0x40,%rsp\n"
"  mov    %rdi,-0x8(%rbp)\n"
"  mov    %rsi,-0x10(%rbp)\n"
"  mov    %edx,-0x14(%rbp)\n"
"  mov    %rcx,-0x20(%rbp)\n"
"  mov    %r8,-0x28(%rbp)\n"
"  mov    %r9,-0x30(%rbp)\n"
"  movq   0x0(%r15),%r14\n"
"  callq  *0x8(%r15)\n"
"  leaveq \n"
"  retq \n"
);     
int datarep_conversion_func_resolved(void *a, R_MPI_Datatype b, int c, void *d, R_MPI_Offset e, void *f, int (*pf)(void *userbuf, A_MPI_Datatype datatype, int count, void *filebuf, A_MPI_Offset posistion, void *extra_state))
{
   A_MPI_Datatype tmp;
   datatype_conv_r2a(&tmp,&b);
	 in_w=0;
   pf(a,tmp,c,d,(A_MPI_Offset)e,f);
	 in_w=1;
}

//int (MPI_Grequest_query_function)(void *, MPI_Status *);
__asm__(
".global user_qrequest_query_function_template\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"nop\n"
"user_qrequest_query_function_template:\n"
"  call peip_qrequest_query_func\n"
"peip_qrequest_query_func:\n"
"  pop %rax\n"
"  sub $0x15,%rax\n"
"  mov %rax,%r9\n"
"  mov %rdi,%rax\n"
"  push   %rbp\n"
"  mov    %rsp,%rbp\n"
"  sub    $0x18,%rsp\n"
"  mov    %rdi,-0x8(%rbp)\n"
"  mov    %rsi,-0x10(%rbp)\n"
"  movq   0x0(%r9),%r14\n"
"  callq  *0x8(%r9)\n"
"  leaveq \n"
"  retq \n"
);     
int qrequest_query_func_resolved(void *a, R_MPI_Status *b, int (*pf)(void *extra_state, A_MPI_Status *status))
{
	 A_MPI_Status ltmp;
   A_MPI_Status *tmp=&ltmp;
   status_prt_conv_r2a(&tmp,&b);
	 in_w=0;
   pf(a,tmp);
	 in_w=1;
}

/*** Trigger a bug within srun ***/
//__thread size_t internal_cur_size;
//__thread size_t max_internal_size;
//__thread char wi4mpi_tmp_buff[1024*1024];
//void *wi4mpi_internal_allocator(size_t size)
//{
//    if((internal_cur_size+size+sizeof(size_t))<max_internal_size)
//    {
//        void *ptr=wi4mpi_tmp_buff+internal_cur_size;
//        ((size_t*)ptr)[0]=size;
//        internal_cur_size+=size+sizeof(size_t);
//        
//        return ptr+sizeof(size_t);
//    }
//    else
//        return malloc(size);
//}
//
//void wi4mpi_internal_free(void *ptr)
//{
//    if((ptr-(void*)wi4mpi_tmp_buff)<max_internal_size)
//    {
//        internal_cur_size-=((size_t*)ptr)[-1];
//        ((size_t*)ptr)[-1]=0;
//    }
//    else
//        free(ptr);
//}
/*******************************/

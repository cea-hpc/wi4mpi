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
"  call peip\n"
"peip:\n"
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
#include "mappers.h"
int user_func_resolved(void *a,void *b,int *c,R_MPI_Datatype *d,void (*pf)(void *in,void *out,int *len,A_MPI_Datatype *data_type))
{
    A_MPI_Datatype tmp;
   datatype_conv_r2a(&tmp,d);
   pf(a,b,c,&tmp);
}
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

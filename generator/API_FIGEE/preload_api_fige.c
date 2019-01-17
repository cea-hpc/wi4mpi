int MPI_Pcontrol(int level,...);
int (*LOCAL_MPI_Pcontrol)(int,...);

__asm__(
".global PMPI_Pcontrol\n"
".weak MPI_Pcontrol\n"
".set MPI_Pcontrol,PMPI_Pcontrol\n"
".extern in_w\n"
".extern A_MPI_Pcontrol\n"
".extern R_MPI_Pcontrol\n"
".type PMPI_Pcontrol,@function\n"
".text\n"
"PMPI_Pcontrol:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Pcontrol\n"
"b A_MPI_Pcontrol\n"
"inwrap_MPI_Pcontrol:\n"
"b R_MPI_Pcontrol\n"
#else
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
"jne inwrap_MPI_Pcontrol\n"
"jmp *A_MPI_Pcontrol@GOTPCREL(%rip)\n"
"inwrap_MPI_Pcontrol:\n"
"jmp *R_MPI_Pcontrol@GOTPCREL(%rip)\n"
#endif
".size PMPI_Pcontrol,.-PMPI_Pcontrol\n"

);

int A_MPI_Pcontrol(int level,...)
{
#ifdef DEBUG
printf("entre : A_MPI_Pcontrol\n");
#endif
in_w=1;
//fprintf(stderr, "A_MPI_Pcontrol Not implemented yet\n");
//int ret_tmp= LOCAL_MPI_Abort(R_MPI_COMM_WORLD,7);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Pcontrol\n");
#endif
//return error_code_conv_r2a(ret_tmp);
return A_MPI_SUCCESS;
}
int R_MPI_Pcontrol(int level,...)
{
#ifdef DEBUG
printf("entre : R_MPI_Pcontrol\n");
#endif
int ret_tmp= LOCAL_MPI_Pcontrol( level,"",NULL);
#ifdef DEBUG
printf("sort : R_MPI_Pcontrol\n");
#endif
return ret_tmp;
}
int MPI_Win_create_errhandler(A_MPI_Win_errhandler_function * win_errhandler_fn,A_MPI_Errhandler * errhandler);
int (*LOCAL_MPI_Win_create_errhandler)(R_MPI_Win_errhandler_function *,R_MPI_Errhandler *);

__asm__(
".global PMPI_Win_create_errhandler\n"
".weak MPI_Win_create_errhandler\n"
".set MPI_Win_create_errhandler,PMPI_Win_create_errhandler\n"
".extern in_w\n"
".extern A_MPI_Win_create_errhandler\n"
".extern R_MPI_Win_create_errhandler\n"
".type PMPI_Win_create_errhandler,@function\n"
".text\n"
"PMPI_Win_create_errhandler:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Win_create_errhandler\n"
"b A_MPI_Win_create_errhandler\n"
"inwrap_MPI_Win_create_errhandler:\n"
"b R_MPI_Win_create_errhandler\n"
#else
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
"jne inwrap_MPI_Win_create_errhandler\n"
"jmp *A_MPI_Win_create_errhandler@GOTPCREL(%rip)\n"
"inwrap_MPI_Win_create_errhandler:\n"
"jmp *R_MPI_Win_create_errhandler@GOTPCREL(%rip)\n"
#endif
".size PMPI_Win_create_errhandler,.-PMPI_Win_create_errhandler\n"

);

int A_MPI_Win_create_errhandler(A_MPI_Win_errhandler_function * win_errhandler_fn,A_MPI_Errhandler * errhandler)
{
#ifdef DEBUG
printf("entre : A_MPI_Win_create_errhandler\n");
#endif
in_w=1;
fprintf(stderr, "A_MPI_Win_create_errhandler Not implemented yet\n");
int ret_tmp= LOCAL_MPI_Abort(R_MPI_COMM_WORLD,7);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Win_create_errhandler\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Win_create_errhandler(R_MPI_Win_errhandler_function * win_errhandler_fn,R_MPI_Errhandler * errhandler)
{
#ifdef DEBUG
printf("entre : R_MPI_Win_create_errhandler\n");
#endif
int ret_tmp= LOCAL_MPI_Win_create_errhandler( win_errhandler_fn, errhandler);
#ifdef DEBUG
printf("sort : R_MPI_Win_create_errhandler\n");
#endif
return ret_tmp;
}
int MPI_Win_call_errhandler(A_MPI_Win win,int errorcode);
int (*LOCAL_MPI_Win_call_errhandler)(R_MPI_Win,int);

__asm__(
".global PMPI_Win_call_errhandler\n"
".weak MPI_Win_call_errhandler\n"
".set MPI_Win_call_errhandler,PMPI_Win_call_errhandler\n"
".extern in_w\n"
".extern A_MPI_Win_call_errhandler\n"
".extern R_MPI_Win_call_errhandler\n"
".type PMPI_Win_call_errhandler,@function\n"
".text\n"
"PMPI_Win_call_errhandler:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Win_call_errhandler\n"
"b A_MPI_Win_call_errhandler\n"
"inwrap_MPI_Win_call_errhandler:\n"
"b R_MPI_Win_call_errhandler\n"
#else
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
"jne inwrap_MPI_Win_call_errhandler\n"
"jmp *A_MPI_Win_call_errhandler@GOTPCREL(%rip)\n"
"inwrap_MPI_Win_call_errhandler:\n"
"jmp *R_MPI_Win_call_errhandler@GOTPCREL(%rip)\n"
#endif
".size PMPI_Win_call_errhandler,.-PMPI_Win_call_errhandler\n"

);

int A_MPI_Win_call_errhandler(A_MPI_Win win,int errorcode)
{
#ifdef DEBUG
printf("entre : A_MPI_Win_call_errhandler\n");
#endif
in_w=1;
fprintf(stderr, "A_MPI_Win_call_errhandler Not implemented yet\n");
int ret_tmp= LOCAL_MPI_Abort(R_MPI_COMM_WORLD,7);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Win_call_errhandler\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Win_call_errhandler(R_MPI_Win win,int errorcode)
{
#ifdef DEBUG
printf("entre : R_MPI_Win_call_errhandler\n");
#endif
int ret_tmp= LOCAL_MPI_Win_call_errhandler( win, errorcode);
#ifdef DEBUG
printf("sort : R_MPI_Win_call_errhandler\n");
#endif
return ret_tmp;
}
int MPI_Win_set_errhandler(A_MPI_Win win,A_MPI_Errhandler errhandler);
int (*LOCAL_MPI_Win_set_errhandler)(R_MPI_Win,R_MPI_Errhandler);

__asm__(
".global PMPI_Win_set_errhandler\n"
".weak MPI_Win_set_errhandler\n"
".set MPI_Win_set_errhandler,PMPI_Win_set_errhandler\n"
".extern in_w\n"
".extern A_MPI_Win_set_errhandler\n"
".extern R_MPI_Win_set_errhandler\n"
".type PMPI_Win_set_errhandler,@function\n"
".text\n"
"PMPI_Win_set_errhandler:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Win_set_errhandler\n"
"b A_MPI_Win_set_errhandler\n"
"inwrap_MPI_Win_set_errhandler:\n"
"b R_MPI_Win_set_errhandler\n"
#else
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
"jne inwrap_MPI_Win_set_errhandler\n"
"jmp *A_MPI_Win_set_errhandler@GOTPCREL(%rip)\n"
"inwrap_MPI_Win_set_errhandler:\n"
"jmp *R_MPI_Win_set_errhandler@GOTPCREL(%rip)\n"
#endif
".size PMPI_Win_set_errhandler,.-PMPI_Win_set_errhandler\n"

);

int A_MPI_Win_set_errhandler(A_MPI_Win win,A_MPI_Errhandler errhandler)
{
#ifdef DEBUG
printf("entre : A_MPI_Win_set_errhandler\n");
#endif
in_w=1;
fprintf(stderr, "A_MPI_Win_set_errhandler Not implemented yet\n");
int ret_tmp= LOCAL_MPI_Abort(R_MPI_COMM_WORLD,7);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Win_set_errhandler\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_Win_set_errhandler(R_MPI_Win win,R_MPI_Errhandler errhandler)
{
#ifdef DEBUG
printf("entre : R_MPI_Win_set_errhandler\n");
#endif
int ret_tmp= LOCAL_MPI_Win_set_errhandler( win, errhandler);
#ifdef DEBUG
printf("sort : R_MPI_Win_set_errhandler\n");
#endif
return ret_tmp;
}
int MPI_File_call_errhandler(A_MPI_File fh,int errorcode);
int (*LOCAL_MPI_File_call_errhandler)(R_MPI_File,int);

__asm__(
".global PMPI_File_call_errhandler\n"
".weak MPI_File_call_errhandler\n"
".set MPI_File_call_errhandler,PMPI_File_call_errhandler\n"
".extern in_w\n"
".extern A_MPI_File_call_errhandler\n"
".extern R_MPI_File_call_errhandler\n"
".type PMPI_File_call_errhandler,@function\n"
".text\n"
"PMPI_File_call_errhandler:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_File_call_errhandler\n"
"b A_MPI_File_call_errhandler\n"
"inwrap_MPI_File_call_errhandler:\n"
"b R_MPI_File_call_errhandler\n"
#else
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
"jne inwrap_MPI_File_call_errhandler\n"
"jmp *A_MPI_File_call_errhandler@GOTPCREL(%rip)\n"
"inwrap_MPI_File_call_errhandler:\n"
"jmp *R_MPI_File_call_errhandler@GOTPCREL(%rip)\n"
#endif
".size PMPI_File_call_errhandler,.-PMPI_File_call_errhandler\n"

);

int A_MPI_File_call_errhandler(A_MPI_File fh,int errorcode)
{
#ifdef DEBUG
printf("entre : A_MPI_File_call_errhandler\n");
#endif
in_w=1;
fprintf(stderr, "A_MPI_File_call_errhandler Not implemented yet\n");
int ret_tmp= LOCAL_MPI_Abort(R_MPI_COMM_WORLD,7);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_call_errhandler\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_call_errhandler(R_MPI_File fh,int errorcode)
{
#ifdef DEBUG
printf("entre : R_MPI_File_call_errhandler\n");
#endif
int ret_tmp= LOCAL_MPI_File_call_errhandler( fh, errorcode);
#ifdef DEBUG
printf("sort : R_MPI_File_call_errhandler\n");
#endif
return ret_tmp;
}

int MPI_File_create_errhandler(A_MPI_File_errhandler_function * file_errhandler_fn,A_MPI_Errhandler * errhandler);
int (*LOCAL_MPI_File_create_errhandler)(R_MPI_File_errhandler_function *,R_MPI_Errhandler *);

__asm__(
".global PMPI_File_create_errhandler\n"
".weak MPI_File_create_errhandler\n"
".set MPI_File_create_errhandler,PMPI_File_create_errhandler\n"
".extern in_w\n"
".extern A_MPI_File_create_errhandler\n"
".extern R_MPI_File_create_errhandler\n"
".type PMPI_File_create_errhandler,@function\n"
".text\n"
"PMPI_File_create_errhandler:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_File_create_errhandler\n"
"b A_MPI_File_create_errhandler\n"
"inwrap_MPI_File_create_errhandler:\n"
"b R_MPI_File_create_errhandler\n"
#else
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
"jne inwrap_MPI_File_create_errhandler\n"
"jmp *A_MPI_File_create_errhandler@GOTPCREL(%rip)\n"
"inwrap_MPI_File_create_errhandler:\n"
"jmp *R_MPI_File_create_errhandler@GOTPCREL(%rip)\n"
#endif
".size PMPI_File_create_errhandler,.-PMPI_File_create_errhandler\n"

);

int A_MPI_File_create_errhandler(A_MPI_File_errhandler_function * file_errhandler_fn,A_MPI_Errhandler * errhandler)
{
#ifdef DEBUG
printf("entre : A_MPI_File_create_errhandler\n");
#endif
in_w=1;
fprintf(stderr, "A_MPI_File_create_errhandler Not implemented yet\n");
int ret_tmp= LOCAL_MPI_Abort(R_MPI_COMM_WORLD,7);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_create_errhandler\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_File_create_errhandler(R_MPI_File_errhandler_function * file_errhandler_fn,R_MPI_Errhandler * errhandler)
{
#ifdef DEBUG
printf("entre : R_MPI_File_create_errhandler\n");
#endif
int ret_tmp= LOCAL_MPI_File_create_errhandler( file_errhandler_fn, errhandler);
#ifdef DEBUG
printf("sort : R_MPI_File_create_errhandler\n");
#endif
return ret_tmp;
}
int MPI_T_pvar_read(A_MPI_T_pvar_session session,A_MPI_T_pvar_handle handle,void * buf);
int (*LOCAL_MPI_T_pvar_read)(R_MPI_T_pvar_session,R_MPI_T_pvar_handle,void *);

__asm__(
".global PMPI_T_pvar_read\n"
".weak MPI_T_pvar_read\n"
".set MPI_T_pvar_read,PMPI_T_pvar_read\n"
".extern in_w\n"
".extern A_MPI_T_pvar_read\n"
".extern R_MPI_T_pvar_read\n"
".type PMPI_T_pvar_read,@function\n"
".text\n"
"PMPI_T_pvar_read:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_T_pvar_read\n"
"b A_MPI_T_pvar_read\n"
"inwrap_MPI_T_pvar_read:\n"
"b R_MPI_T_pvar_read\n"
#else
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
"jne inwrap_MPI_T_pvar_read\n"
"jmp *A_MPI_T_pvar_read@GOTPCREL(%rip)\n"
"inwrap_MPI_T_pvar_read:\n"
"jmp *R_MPI_T_pvar_read@GOTPCREL(%rip)\n"
#endif
".size PMPI_T_pvar_read,.-PMPI_T_pvar_read\n"

);

int A_MPI_T_pvar_read(A_MPI_T_pvar_session session,A_MPI_T_pvar_handle handle,void * buf)
{
#ifdef DEBUG
printf("entre : A_MPI_T_pvar_read\n");
#endif
in_w=1;
fprintf(stderr, "A_MPI_T_pvar_read Not implemented yet\n");
int ret_tmp= LOCAL_MPI_Abort(R_MPI_COMM_WORLD,7);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_T_pvar_read\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_T_pvar_read(R_MPI_T_pvar_session session,R_MPI_T_pvar_handle handle,void * buf)
{
#ifdef DEBUG
printf("entre : R_MPI_T_pvar_read\n");
#endif
int ret_tmp= LOCAL_MPI_T_pvar_read( session, handle, buf);
#ifdef DEBUG
printf("sort : R_MPI_T_pvar_read\n");
#endif
return ret_tmp;
}
int MPI_T_pvar_readreset(A_MPI_T_pvar_session session,A_MPI_T_pvar_handle handle,void * buf);
int (*LOCAL_MPI_T_pvar_readreset)(R_MPI_T_pvar_session,R_MPI_T_pvar_handle,void *);

__asm__(
".global PMPI_T_pvar_readreset\n"
".weak MPI_T_pvar_readreset\n"
".set MPI_T_pvar_readreset,PMPI_T_pvar_readreset\n"
".extern in_w\n"
".extern A_MPI_T_pvar_readreset\n"
".extern R_MPI_T_pvar_readreset\n"
".type PMPI_T_pvar_readreset,@function\n"
".text\n"
"PMPI_T_pvar_readreset:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_T_pvar_readreset\n"
"b A_MPI_T_pvar_readreset\n"
"inwrap_MPI_T_pvar_readreset:\n"
"b R_MPI_T_pvar_readreset\n"
#else
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
"jne inwrap_MPI_T_pvar_readreset\n"
"jmp *A_MPI_T_pvar_readreset@GOTPCREL(%rip)\n"
"inwrap_MPI_T_pvar_readreset:\n"
"jmp *R_MPI_T_pvar_readreset@GOTPCREL(%rip)\n"
#endif
".size PMPI_T_pvar_readreset,.-PMPI_T_pvar_readreset\n"

);

int A_MPI_T_pvar_readreset(A_MPI_T_pvar_session session,A_MPI_T_pvar_handle handle,void * buf)
{
#ifdef DEBUG
printf("entre : A_MPI_T_pvar_readreset\n");
#endif
in_w=1;
fprintf(stderr, "A_MPI_T_pvar_readreset Not implemented yet\n");
int ret_tmp= LOCAL_MPI_Abort(R_MPI_COMM_WORLD,7);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_T_pvar_readreset\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_T_pvar_readreset(R_MPI_T_pvar_session session,R_MPI_T_pvar_handle handle,void * buf)
{
#ifdef DEBUG
printf("entre : R_MPI_T_pvar_readreset\n");
#endif
int ret_tmp= LOCAL_MPI_T_pvar_readreset( session, handle, buf);
#ifdef DEBUG
printf("sort : R_MPI_T_pvar_readreset\n");
#endif
return ret_tmp;
}
int MPI_T_pvar_reset(A_MPI_T_pvar_session session,A_MPI_T_pvar_handle handle);
int (*LOCAL_MPI_T_pvar_reset)(R_MPI_T_pvar_session,R_MPI_T_pvar_handle);

__asm__(
".global PMPI_T_pvar_reset\n"
".weak MPI_T_pvar_reset\n"
".set MPI_T_pvar_reset,PMPI_T_pvar_reset\n"
".extern in_w\n"
".extern A_MPI_T_pvar_reset\n"
".extern R_MPI_T_pvar_reset\n"
".type PMPI_T_pvar_reset,@function\n"
".text\n"
"PMPI_T_pvar_reset:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_T_pvar_reset\n"
"b A_MPI_T_pvar_reset\n"
"inwrap_MPI_T_pvar_reset:\n"
"b R_MPI_T_pvar_reset\n"
#else
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
"jne inwrap_MPI_T_pvar_reset\n"
"jmp *A_MPI_T_pvar_reset@GOTPCREL(%rip)\n"
"inwrap_MPI_T_pvar_reset:\n"
"jmp *R_MPI_T_pvar_reset@GOTPCREL(%rip)\n"
#endif
".size PMPI_T_pvar_reset,.-PMPI_T_pvar_reset\n"

);

int A_MPI_T_pvar_reset(A_MPI_T_pvar_session session,A_MPI_T_pvar_handle handle)
{
#ifdef DEBUG
printf("entre : A_MPI_T_pvar_reset\n");
#endif
in_w=1;
fprintf(stderr, "A_MPI_T_pvar_reset Not implemented yet\n");
int ret_tmp= LOCAL_MPI_Abort(R_MPI_COMM_WORLD,7);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_T_pvar_reset\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_T_pvar_reset(R_MPI_T_pvar_session session,R_MPI_T_pvar_handle handle)
{
#ifdef DEBUG
printf("entre : R_MPI_T_pvar_reset\n");
#endif
int ret_tmp= LOCAL_MPI_T_pvar_reset( session, handle);
#ifdef DEBUG
printf("sort : R_MPI_T_pvar_reset\n");
#endif
return ret_tmp;
}
int MPI_T_pvar_session_create(A_MPI_T_pvar_session * session);
int (*LOCAL_MPI_T_pvar_session_create)(R_MPI_T_pvar_session *);

__asm__(
".global PMPI_T_pvar_session_create\n"
".weak MPI_T_pvar_session_create\n"
".set MPI_T_pvar_session_create,PMPI_T_pvar_session_create\n"
".extern in_w\n"
".extern A_MPI_T_pvar_session_create\n"
".extern R_MPI_T_pvar_session_create\n"
".type PMPI_T_pvar_session_create,@function\n"
".text\n"
"PMPI_T_pvar_session_create:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_T_pvar_session_create\n"
"b A_MPI_T_pvar_session_create\n"
"inwrap_MPI_T_pvar_session_create:\n"
"b R_MPI_T_pvar_session_create\n"
#else
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
"jne inwrap_MPI_T_pvar_session_create\n"
"jmp *A_MPI_T_pvar_session_create@GOTPCREL(%rip)\n"
"inwrap_MPI_T_pvar_session_create:\n"
"jmp *R_MPI_T_pvar_session_create@GOTPCREL(%rip)\n"
#endif
".size PMPI_T_pvar_session_create,.-PMPI_T_pvar_session_create\n"

);

int A_MPI_T_pvar_session_create(A_MPI_T_pvar_session * session)
{
#ifdef DEBUG
printf("entre : A_MPI_T_pvar_session_create\n");
#endif
in_w=1;
fprintf(stderr, "A_MPI_T_pvar_session_create Not implemented yet\n");
int ret_tmp= LOCAL_MPI_Abort(R_MPI_COMM_WORLD,7);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_T_pvar_session_create\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_T_pvar_session_create(R_MPI_T_pvar_session * session)
{
#ifdef DEBUG
printf("entre : R_MPI_T_pvar_session_create\n");
#endif
int ret_tmp= LOCAL_MPI_T_pvar_session_create( session);
#ifdef DEBUG
printf("sort : R_MPI_T_pvar_session_create\n");
#endif
return ret_tmp;
}
int MPI_T_pvar_session_free(A_MPI_T_pvar_session * session);
int (*LOCAL_MPI_T_pvar_session_free)(R_MPI_T_pvar_session *);

__asm__(
".global PMPI_T_pvar_session_free\n"
".weak MPI_T_pvar_session_free\n"
".set MPI_T_pvar_session_free,PMPI_T_pvar_session_free\n"
".extern in_w\n"
".extern A_MPI_T_pvar_session_free\n"
".extern R_MPI_T_pvar_session_free\n"
".type PMPI_T_pvar_session_free,@function\n"
".text\n"
"PMPI_T_pvar_session_free:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_T_pvar_session_free\n"
"b A_MPI_T_pvar_session_free\n"
"inwrap_MPI_T_pvar_session_free:\n"
"b R_MPI_T_pvar_session_free\n"
#else
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
"jne inwrap_MPI_T_pvar_session_free\n"
"jmp *A_MPI_T_pvar_session_free@GOTPCREL(%rip)\n"
"inwrap_MPI_T_pvar_session_free:\n"
"jmp *R_MPI_T_pvar_session_free@GOTPCREL(%rip)\n"
#endif
".size PMPI_T_pvar_session_free,.-PMPI_T_pvar_session_free\n"

);

int A_MPI_T_pvar_session_free(A_MPI_T_pvar_session * session)
{
#ifdef DEBUG
printf("entre : A_MPI_T_pvar_session_free\n");
#endif
in_w=1;
fprintf(stderr, "A_MPI_T_pvar_session_free Not implemented yet\n");
int ret_tmp= LOCAL_MPI_Abort(R_MPI_COMM_WORLD,7);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_T_pvar_session_free\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_T_pvar_session_free(R_MPI_T_pvar_session * session)
{
#ifdef DEBUG
printf("entre : R_MPI_T_pvar_session_free\n");
#endif
int ret_tmp= LOCAL_MPI_T_pvar_session_free( session);
#ifdef DEBUG
printf("sort : R_MPI_T_pvar_session_free\n");
#endif
return ret_tmp;
}
int MPI_T_pvar_start(A_MPI_T_pvar_session session,A_MPI_T_pvar_handle handle);
int (*LOCAL_MPI_T_pvar_start)(R_MPI_T_pvar_session,R_MPI_T_pvar_handle);

__asm__(
".global PMPI_T_pvar_start\n"
".weak MPI_T_pvar_start\n"
".set MPI_T_pvar_start,PMPI_T_pvar_start\n"
".extern in_w\n"
".extern A_MPI_T_pvar_start\n"
".extern R_MPI_T_pvar_start\n"
".type PMPI_T_pvar_start,@function\n"
".text\n"
"PMPI_T_pvar_start:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_T_pvar_start\n"
"b A_MPI_T_pvar_start\n"
"inwrap_MPI_T_pvar_start:\n"
"b R_MPI_T_pvar_start\n"
#else
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
"jne inwrap_MPI_T_pvar_start\n"
"jmp *A_MPI_T_pvar_start@GOTPCREL(%rip)\n"
"inwrap_MPI_T_pvar_start:\n"
"jmp *R_MPI_T_pvar_start@GOTPCREL(%rip)\n"
#endif
".size PMPI_T_pvar_start,.-PMPI_T_pvar_start\n"

);

int A_MPI_T_pvar_start(A_MPI_T_pvar_session session,A_MPI_T_pvar_handle handle)
{
#ifdef DEBUG
printf("entre : A_MPI_T_pvar_start\n");
#endif
in_w=1;
fprintf(stderr, "A_MPI_T_pvar_start Not implemented yet\n");
int ret_tmp= LOCAL_MPI_Abort(R_MPI_COMM_WORLD,7);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_T_pvar_start\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_T_pvar_start(R_MPI_T_pvar_session session,R_MPI_T_pvar_handle handle)
{
#ifdef DEBUG
printf("entre : R_MPI_T_pvar_start\n");
#endif
int ret_tmp= LOCAL_MPI_T_pvar_start( session, handle);
#ifdef DEBUG
printf("sort : R_MPI_T_pvar_start\n");
#endif
return ret_tmp;
}
int MPI_T_pvar_stop(A_MPI_T_pvar_session session,A_MPI_T_pvar_handle handle);
int (*LOCAL_MPI_T_pvar_stop)(R_MPI_T_pvar_session,R_MPI_T_pvar_handle);

__asm__(
".global PMPI_T_pvar_stop\n"
".weak MPI_T_pvar_stop\n"
".set MPI_T_pvar_stop,PMPI_T_pvar_stop\n"
".extern in_w\n"
".extern A_MPI_T_pvar_stop\n"
".extern R_MPI_T_pvar_stop\n"
".type PMPI_T_pvar_stop,@function\n"
".text\n"
"PMPI_T_pvar_stop:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_T_pvar_stop\n"
"b A_MPI_T_pvar_stop\n"
"inwrap_MPI_T_pvar_stop:\n"
"b R_MPI_T_pvar_stop\n"
#else
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
"jne inwrap_MPI_T_pvar_stop\n"
"jmp *A_MPI_T_pvar_stop@GOTPCREL(%rip)\n"
"inwrap_MPI_T_pvar_stop:\n"
"jmp *R_MPI_T_pvar_stop@GOTPCREL(%rip)\n"
#endif
".size PMPI_T_pvar_stop,.-PMPI_T_pvar_stop\n"

);

int A_MPI_T_pvar_stop(A_MPI_T_pvar_session session,A_MPI_T_pvar_handle handle)
{
#ifdef DEBUG
printf("entre : A_MPI_T_pvar_stop\n");
#endif
in_w=1;
fprintf(stderr, "A_MPI_T_pvar_stop Not implemented yet\n");
int ret_tmp= LOCAL_MPI_Abort(R_MPI_COMM_WORLD,7);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_T_pvar_stop\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_T_pvar_stop(R_MPI_T_pvar_session session,R_MPI_T_pvar_handle handle)
{
#ifdef DEBUG
printf("entre : R_MPI_T_pvar_stop\n");
#endif
int ret_tmp= LOCAL_MPI_T_pvar_stop( session, handle);
#ifdef DEBUG
printf("sort : R_MPI_T_pvar_stop\n");
#endif
return ret_tmp;
}
int MPI_T_pvar_write(A_MPI_T_pvar_session session,A_MPI_T_pvar_handle handle,void * buf);
int (*LOCAL_MPI_T_pvar_write)(R_MPI_T_pvar_session,R_MPI_T_pvar_handle,void *);

__asm__(
".global PMPI_T_pvar_write\n"
".weak MPI_T_pvar_write\n"
".set MPI_T_pvar_write,PMPI_T_pvar_write\n"
".extern in_w\n"
".extern A_MPI_T_pvar_write\n"
".extern R_MPI_T_pvar_write\n"
".type PMPI_T_pvar_write,@function\n"
".text\n"
"PMPI_T_pvar_write:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_T_pvar_write\n"
"b A_MPI_T_pvar_write\n"
"inwrap_MPI_T_pvar_write:\n"
"b R_MPI_T_pvar_write\n"
#else
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
"jne inwrap_MPI_T_pvar_write\n"
"jmp *A_MPI_T_pvar_write@GOTPCREL(%rip)\n"
"inwrap_MPI_T_pvar_write:\n"
"jmp *R_MPI_T_pvar_write@GOTPCREL(%rip)\n"
#endif
".size PMPI_T_pvar_write,.-PMPI_T_pvar_write\n"

);

int A_MPI_T_pvar_write(A_MPI_T_pvar_session session,A_MPI_T_pvar_handle handle,void * buf)
{
#ifdef DEBUG
printf("entre : A_MPI_T_pvar_write\n");
#endif
in_w=1;
fprintf(stderr, "A_MPI_T_pvar_write Not implemented yet\n");
int ret_tmp= LOCAL_MPI_Abort(R_MPI_COMM_WORLD,7);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_T_pvar_write\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_T_pvar_write(R_MPI_T_pvar_session session,R_MPI_T_pvar_handle handle,void * buf)
{
#ifdef DEBUG
printf("entre : R_MPI_T_pvar_write\n");
#endif
int ret_tmp= LOCAL_MPI_T_pvar_write( session, handle, buf);
#ifdef DEBUG
printf("sort : R_MPI_T_pvar_write\n");
#endif
return ret_tmp;
}
int MPI_T_pvar_handle_alloc(A_MPI_T_pvar_session session,int pvar_index,void * obj_handle,A_MPI_T_pvar_handle * handle,int * count);
int (*LOCAL_MPI_T_pvar_handle_alloc)(R_MPI_T_pvar_session,int,void *,R_MPI_T_pvar_handle *,int *);

__asm__(
".global PMPI_T_pvar_handle_alloc\n"
".weak MPI_T_pvar_handle_alloc\n"
".set MPI_T_pvar_handle_alloc,PMPI_T_pvar_handle_alloc\n"
".extern in_w\n"
".extern A_MPI_T_pvar_handle_alloc\n"
".extern R_MPI_T_pvar_handle_alloc\n"
".type PMPI_T_pvar_handle_alloc,@function\n"
".text\n"
"PMPI_T_pvar_handle_alloc:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_T_pvar_handle_alloc\n"
"b A_MPI_T_pvar_handle_alloc\n"
"inwrap_MPI_T_pvar_handle_alloc:\n"
"b R_MPI_T_pvar_handle_alloc\n"
#else
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
"jne inwrap_MPI_T_pvar_handle_alloc\n"
"jmp *A_MPI_T_pvar_handle_alloc@GOTPCREL(%rip)\n"
"inwrap_MPI_T_pvar_handle_alloc:\n"
"jmp *R_MPI_T_pvar_handle_alloc@GOTPCREL(%rip)\n"
#endif
".size PMPI_T_pvar_handle_alloc,.-PMPI_T_pvar_handle_alloc\n"

);

int A_MPI_T_pvar_handle_alloc(A_MPI_T_pvar_session session,int pvar_index,void * obj_handle,A_MPI_T_pvar_handle * handle,int * count)
{
#ifdef DEBUG
printf("entre : A_MPI_T_pvar_handle_alloc\n");
#endif
in_w=1;
fprintf(stderr, "A_MPI_T_pvar_write Not implemented yet\n");
int ret_tmp= LOCAL_MPI_Abort(R_MPI_COMM_WORLD,7);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_T_pvar_handle_alloc\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_T_pvar_handle_alloc(R_MPI_T_pvar_session session,int pvar_index,void * obj_handle,R_MPI_T_pvar_handle * handle,int * count)
{
#ifdef DEBUG
printf("entre : R_MPI_T_pvar_handle_alloc\n");
#endif
int ret_tmp= LOCAL_MPI_T_pvar_handle_alloc( session, pvar_index, obj_handle, handle, count);
#ifdef DEBUG
printf("sort : R_MPI_T_pvar_handle_alloc\n");
#endif
return ret_tmp;
}
int MPI_T_pvar_handle_free(A_MPI_T_pvar_session session,A_MPI_T_pvar_handle * handle);
int (*LOCAL_MPI_T_pvar_handle_free)(R_MPI_T_pvar_session,R_MPI_T_pvar_handle *);

__asm__(
".global PMPI_T_pvar_handle_free\n"
".weak MPI_T_pvar_handle_free\n"
".set MPI_T_pvar_handle_free,PMPI_T_pvar_handle_free\n"
".extern in_w\n"
".extern A_MPI_T_pvar_handle_free\n"
".extern R_MPI_T_pvar_handle_free\n"
".type PMPI_T_pvar_handle_free,@function\n"
".text\n"
"PMPI_T_pvar_handle_free:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_T_pvar_handle_free\n"
"b A_MPI_T_pvar_handle_free\n"
"inwrap_MPI_T_pvar_handle_free:\n"
"b R_MPI_T_pvar_handle_free\n"
#else
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
"jne inwrap_MPI_T_pvar_handle_free\n"
"jmp *A_MPI_T_pvar_handle_free@GOTPCREL(%rip)\n"
"inwrap_MPI_T_pvar_handle_free:\n"
"jmp *R_MPI_T_pvar_handle_free@GOTPCREL(%rip)\n"
#endif
".size PMPI_T_pvar_handle_free,.-PMPI_T_pvar_handle_free\n"

);

int A_MPI_T_pvar_handle_free(A_MPI_T_pvar_session session,A_MPI_T_pvar_handle * handle)
{
#ifdef DEBUG
printf("entre : A_MPI_T_pvar_handle_free\n");
#endif
in_w=1;
fprintf(stderr, "A_MPI_T_pvar_handle_free Not implemented yet\n");
int ret_tmp= LOCAL_MPI_Abort(R_MPI_COMM_WORLD,7);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_T_pvar_handle_free\n");
#endif
return error_code_conv_r2a(ret_tmp);
}
int R_MPI_T_pvar_handle_free(R_MPI_T_pvar_session session,R_MPI_T_pvar_handle * handle)
{
#ifdef DEBUG
printf("entre : R_MPI_T_pvar_handle_free\n");
#endif
int ret_tmp= LOCAL_MPI_T_pvar_handle_free( session, handle);
#ifdef DEBUG
printf("sort : R_MPI_T_pvar_handle_free\n");
#endif
return ret_tmp;
}

#if defined(INTEL_OMPI) || defined(OMPI_OMPI) || defined(_OMPI)
__asm__(
".global PMPI_Errhandler_f2c\n"
".weak MPI_Errhandler_f2c\n"
".set MPI_Errhandler_f2c,PMPI_Errhandler_f2c\n"
".extern in_w\n"
".extern A_MPI_Errhandler_f2c\n"
".extern R_MPI_Errhandler_f2c\n"
".type PMPI_Errhandler_f2c,@function\n"
".text\n"
"PMPI_Errhandler_f2c:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Errhandler_f2c\n"
"b A_MPI_Errhandler_f2c\n"
"inwrap_MPI_Errhandler_f2c:\n"
"b R_MPI_Errhandler_f2c\n"
#else
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
"jne inwrap_MPI_Errhandler_f2c\n"
"jmp *A_MPI_Errhandler_f2c@GOTPCREL(%rip)\n"
"inwrap_MPI_Errhandler_f2c:\n"
"jmp *R_MPI_Errhandler_f2c@GOTPCREL(%rip)\n"
#endif
".size PMPI_Errhandler_f2c,.-PMPI_Errhandler_f2c\n"
);

R_MPI_Errhandler (*LOCAL_MPI_Errhandler_f2c)(R_MPI_Fint);
A_MPI_Errhandler A_MPI_Errhandler_f2c(A_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : A_MPI_Errhandler_f2c\n");
#endif
in_w=1;
fprintf(stderr, "A_MPI_Errhandler_f2c Not implemented yet\n");
int ret_tmp= LOCAL_MPI_Abort(R_MPI_COMM_WORLD,7);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Errhandler_f2c\n");
#endif
return A_MPI_ERRHANDLER_NULL;
}

R_MPI_Errhandler (*LOCAL_MPI_Errhandler_f2c)(int);
R_MPI_Errhandler R_MPI_Errhandler_f2c(R_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : R_MPI_Errhandler_f2c\n");
#endif
R_MPI_Errhandler ret=LOCAL_MPI_Errhandler_f2c(op);
#ifdef DEBUG
printf("sort : R_MPI_Errhandler_f2c\n");
#endif
return ret;
}

__asm__(
".global PMPI_Errhandler_c2f\n"
".weak MPI_Errhandler_c2f\n"
".set MPI_Errhandler_c2f,PMPI_Errhandler_c2f\n"
".extern in_w\n"
".extern A_MPI_Errhandler_c2f\n"
".extern R_MPI_Errhandler_c2f\n"
".type PMPI_Errhandler_c2f,@function\n"
".text\n"
"PMPI_Errhandler_c2f:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Errhandler_c2f\n"
"b A_MPI_Errhandler_c2f\n"
"inwrap_MPI_Errhandler_c2f:\n"
"b R_MPI_Errhandler_c2f\n"
#else
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
"jne inwrap_MPI_Errhandler_c2f\n"
"jmp *A_MPI_Errhandler_c2f@GOTPCREL(%rip)\n"
"inwrap_MPI_Errhandler_c2f:\n"
"jmp *R_MPI_Errhandler_c2f@GOTPCREL(%rip)\n"
#endif
".size PMPI_Errhandler_c2f,.-PMPI_Errhandler_c2f\n"
);

R_MPI_Fint (*LOCAL_MPI_Errhandler_c2f)(R_MPI_Errhandler);
A_MPI_Fint A_MPI_Errhandler_c2f(A_MPI_Errhandler op)
{
#ifdef DEBUG
printf("entre : A_MPI_Errhandler_c2f\n");
#endif
in_w=1;
fprintf(stderr, "A_MPI_Errhandler_c2f Not implemented yet\n");
int ret_tmp= LOCAL_MPI_Abort(R_MPI_COMM_WORLD,7);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Errhandler_c2f\n");
#endif
return ret_tmp;
}

R_MPI_Errhandler (*LOCAL_MPI_Errhandler_f2c)(int);
R_MPI_Fint R_MPI_Errhandler_c2f(R_MPI_Errhandler op)
{
#ifdef DEBUG
printf("entre : R_MPI_Errhandler_c2f\n");
#endif
in_w=1;
R_MPI_Fint ret=LOCAL_MPI_Errhandler_c2f(op);
in_w=0;
#ifdef DEBUG
printf("sort : R_MPI_Errhandler_c2f\n");
#endif
return ret;
}
#elif defined(OMPI_INTEL) || defined(_INTEL)
__asm__(
".global PMPI_Errhandler_f2c\n"
".weak MPI_Errhandler_f2c\n"
".set MPI_Errhandler_f2c,PMPI_Errhandler_f2c\n"
".extern in_w\n"
".extern A_MPI_Errhandler_f2c\n"
".extern R_MPI_Errhandler_f2c\n"
".type PMPI_Errhandler_f2c,@function\n"
".text\n"
"PMPI_Errhandler_f2c:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Errhandler_f2c\n"
"b A__MPI_Errhandler_f2c\n"
"inwrap_MPI_Errhandler_f2c:\n"
"b R__MPI_Errhandler_f2c\n"
#else
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
"jne inwrap_MPI_Errhandler_f2c\n"
"jmp *A__MPI_Errhandler_f2c@GOTPCREL(%rip)\n"
"inwrap_MPI_Errhandler_f2c:\n"
"jmp *R__MPI_Errhandler_f2c@GOTPCREL(%rip)\n"
#endif
".size PMPI_Errhandler_f2c,.-PMPI_Errhandler_f2c\n"
);

A_MPI_Errhandler A__MPI_Errhandler_f2c(A_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : A_MPI_Errhandler_f2c\n");
#endif
in_w=1;
fprintf(stderr, "A_MPI_Errhandler_f2c Not implemented yet\n");
int ret_tmp= LOCAL_MPI_Abort(R_MPI_COMM_WORLD,7);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Errhandler_f2c\n");
#endif
return ret_tmp;
}
R_MPI_Fint (*LOCAL_MPI_Errhandler_c2f)(R_MPI_Errhandler);
R_MPI_Errhandler (*LOCAL_MPI_Errhandler_f2c)(int);


R_MPI_Errhandler R__MPI_Errhandler_f2c(R_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : R_MPI_Errhandler_f2c\n");
#endif
R_MPI_Errhandler ret=LOCAL_MPI_Errhandler_f2c(op);
#ifdef DEBUG
printf("sort : R_MPI_Errhandler_f2c\n");
#endif
return ret;
}

__asm__(
".global PMPI_Errhandler_c2f\n"
".weak MPI_Errhandler_c2f\n"
".set MPI_Errhandler_c2f,PMPI_Errhandler_c2f\n"
".extern in_w\n"
".extern A_MPI_Errhandler_c2f\n"
".extern R_MPI_Errhandler_c2f\n"
".type PMPI_Errhandler_c2f,@function\n"
".text\n"
"PMPI_Errhandler_c2f:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Errhandler_c2f\n"
"b A__MPI_Errhandler_c2f\n"
"inwrap_MPI_Errhandler_c2f:\n"
"b R__MPI_Errhandler_c2f\n"
#else
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
"jne inwrap_MPI_Errhandler_c2f\n"
"jmp *A__MPI_Errhandler_c2f@GOTPCREL(%rip)\n"
"inwrap_MPI_Errhandler_c2f:\n"
"jmp *R__MPI_Errhandler_c2f@GOTPCREL(%rip)\n"
#endif
".size PMPI_Errhandler_c2f,.-PMPI_Errhandler_c2f\n"
);

int A__MPI_Errhandler_c2f(A_MPI_Errhandler op)
{
#ifdef DEBUG
printf("entre : A_MPI_Errhandler_c2f\n");
#endif
in_w=1;
fprintf(stderr, "A_MPI_Errhandler_c2f Not implemented yet\n");
int ret_tmp= LOCAL_MPI_Abort(R_MPI_COMM_WORLD,7);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Errhandler_c2f\n");
#endif
return ret_tmp;
}


int R__MPI_Errhandler_c2f(R_MPI_Errhandler op)
{
#ifdef DEBUG
printf("entre : R_MPI_Errhandler_c2f\n");
#endif
in_w=1;
R_MPI_Fint ret=LOCAL_MPI_Errhandler_c2f(op);
in_w=0;
#ifdef DEBUG
printf("sort : R_MPI_Errhandler_c2f\n");
#endif
return ret;
}
#endif
void wrapper_init_f(void);
#if defined(OMPI_OMPI) || defined(_OMPI)
#endif
__attribute__((constructor)) void wrapper_init(void) {
void *lib_handle=dlopen(getenv("WI4MPI_RUN_MPI_C_LIB"),RTLD_NOW|RTLD_GLOBAL);
void *lib_handle_io=lib_handle; // TODO: use WI4MPI_MPIIO_LIB
#if defined(INTEL_OMPI) || defined(OMPI_OMPI) || defined(_OMPI)
LOCAL_MPI_Errhandler_f2c=dlsym(lib_handle,"PMPI_Errhandler_f2c");
LOCAL_MPI_Errhandler_c2f=dlsym(lib_handle,"PMPI_Errhandler_c2f");
#endif
/* ABI FIGE */
LOCAL_MPI_Pcontrol=dlsym(lib_handle,"PMPI_Pcontrol");
LOCAL_MPI_Win_create_errhandler=dlsym(lib_handle,"PMPI_Win_create_errhandler");
LOCAL_MPI_Win_call_errhandler=dlsym(lib_handle,"PMPI_Win_call_errhandler");
LOCAL_MPI_Win_set_errhandler=dlsym(lib_handle,"PMPI_Win_set_errhandler");
LOCAL_MPI_File_call_errhandler=dlsym(lib_handle_io,"PMPI_File_call_errhandler");
LOCAL_MPI_File_create_errhandler=dlsym(lib_handle_io,"PMPI_File_create_errhandler");
LOCAL_MPI_T_pvar_read=dlsym(lib_handle,"PMPI_T_pvar_read");
LOCAL_MPI_T_pvar_readreset=dlsym(lib_handle,"PMPI_T_pvar_readreset");
LOCAL_MPI_T_pvar_reset=dlsym(lib_handle,"PMPI_T_pvar_reset");
LOCAL_MPI_T_pvar_session_create=dlsym(lib_handle,"PMPI_T_pvar_session_create");
LOCAL_MPI_T_pvar_session_free=dlsym(lib_handle,"PMPI_T_pvar_session_free");
LOCAL_MPI_T_pvar_start=dlsym(lib_handle,"PMPI_T_pvar_start");
LOCAL_MPI_T_pvar_stop=dlsym(lib_handle,"PMPI_T_pvar_stop");
LOCAL_MPI_T_pvar_write=dlsym(lib_handle,"PMPI_T_pvar_write");
LOCAL_MPI_T_pvar_handle_alloc=dlsym(lib_handle,"PMPI_T_pvar_handle_alloc");
LOCAL_MPI_T_pvar_handle_free=dlsym(lib_handle,"PMPI_T_pvar_handle_free");
/* --- */

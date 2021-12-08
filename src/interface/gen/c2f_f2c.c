//############################# Wi4MPI License ###########################
//# `04/04/2016`                                                         #
//# Copyright or (C) or Copr. Commissariat a l'Energie Atomique         #
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
#include "wrapper_f.h"
#if defined(INTEL_OMPI) || defined (OMPI_OMPI) || defined(_OMPI) || defined(_MPC)
#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <stdio.h>
#include <dlfcn.h>
#include "mappers.h"
extern __thread int in_w;

__asm__(
".global CCMPI_Win_f2c\n"
".weak MPI_Win_f2c\n"
".set MPI_Win_f2c,CCMPI_Win_f2c\n"
".extern in_w\n"
".extern A_MPI_Win_f2c\n"
".extern R_MPI_Win_f2c\n"
".type CCMPI_Win_f2c,@function\n"
".text\n"
"CCMPI_Win_f2c:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Win_f2c\n"
"b A_MPI_Win_f2c\n"
"inwrap_MPI_Win_f2c:\n"
"b R_MPI_Win_f2c\n"
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
"jne inwrap_MPI_Win_f2c\n"
"jmp *A_MPI_Win_f2c@GOTPCREL(%rip)\n"
"inwrap_MPI_Win_f2c:\n"
"jmp *R_MPI_Win_f2c@GOTPCREL(%rip)\n"
#endif

);


__asm__(
".global CCMPI_Win_c2f\n"
".weak MPI_Win_c2f\n"
".set MPI_Win_c2f,CCMPI_Win_c2f\n"
".extern in_w\n"
".extern A_MPI_Win_c2f\n"
".extern R_MPI_Win_c2f\n"
".type CCMPI_Win_c2f,@function\n"
".text\n"
"CCMPI_Win_c2f:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Win_c2f\n"
"b A_MPI_Win_c2f\n"
"inwrap_MPI_Win_c2f:\n"
"b R_MPI_Win_c2f\n"
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
"jne inwrap_MPI_Win_c2f\n"
"jmp *A_MPI_Win_c2f@GOTPCREL(%rip)\n"
"inwrap_MPI_Win_c2f:\n"
"jmp *R_MPI_Win_c2f@GOTPCREL(%rip)\n"
#endif

);


__asm__(
".global CCMPI_Message_f2c\n"
".weak MPI_Message_f2c\n"
".set MPI_Message_f2c,CCMPI_Message_f2c\n"
".extern in_w\n"
".extern A_MPI_Message_f2c\n"
".extern R_MPI_Message_f2c\n"
".type CCMPI_Message_f2c,@function\n"
".text\n"
"CCMPI_Message_f2c:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Message_f2c\n"
"b A_MPI_Message_f2c\n"
"inwrap_MPI_Message_f2c:\n"
"b R_MPI_Message_f2c\n"
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
"jne inwrap_MPI_Message_f2c\n"
"jmp *A_MPI_Message_f2c@GOTPCREL(%rip)\n"
"inwrap_MPI_Message_f2c:\n"
"jmp *R_MPI_Message_f2c@GOTPCREL(%rip)\n"
#endif

);


__asm__(
".global CCMPI_Message_c2f\n"
".weak MPI_Message_c2f\n"
".set MPI_Message_c2f,CCMPI_Message_c2f\n"
".extern in_w\n"
".extern A_MPI_Message_c2f\n"
".extern R_MPI_Message_c2f\n"
".type CCMPI_Message_c2f,@function\n"
".text\n"
"CCMPI_Message_c2f:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Message_c2f\n"
"b A_MPI_Message_c2f\n"
"inwrap_MPI_Message_c2f:\n"
"b R_MPI_Message_c2f\n"
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
"jne inwrap_MPI_Message_c2f\n"
"jmp *A_MPI_Message_c2f@GOTPCREL(%rip)\n"
"inwrap_MPI_Message_c2f:\n"
"jmp *R_MPI_Message_c2f@GOTPCREL(%rip)\n"
#endif

);
__asm__(
".global CCMPI_File_f2c\n"
".weak MPI_File_f2c\n"
".set MPI_File_f2c,CCMPI_File_f2c\n"
".extern in_w\n"
".extern A_MPI_File_f2c\n"
".extern R_MPI_File_f2c\n"
".type CCMPI_File_f2c,@function\n"
".text\n"
"CCMPI_File_f2c:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_File_f2c\n"
"b A_MPI_File_f2c\n"
"inwrap_MPI_File_f2c:\n"
"b R_MPI_File_f2c\n"
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
"jne inwrap_MPI_File_f2c\n"
"jmp *A_MPI_File_f2c@GOTPCREL(%rip)\n"
"inwrap_MPI_File_f2c:\n"
"jmp *R_MPI_File_f2c@GOTPCREL(%rip)\n"
#endif

);

__asm__(
".global CCMPI_File_c2f\n"
".weak MPI_File_c2f\n"
".set MPI_File_c2f,CCMPI_File_c2f\n"
".extern in_w\n"
".extern A_MPI_File_c2f\n"
".extern R_MPI_File_c2f\n"
".type CCMPI_File_c2f,@function\n"
".text\n"
"CCMPI_File_c2f:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_File_c2f\n"
"b A_MPI_File_c2f\n"
"inwrap_MPI_File_c2f:\n"
"b R_MPI_File_c2f\n"
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
"jne inwrap_MPI_File_c2f\n"
"jmp *A_MPI_File_c2f@GOTPCREL(%rip)\n"
"inwrap_MPI_File_c2f:\n"
"jmp *R_MPI_File_c2f@GOTPCREL(%rip)\n"
#endif

);
__asm__(
".global CCMPI_Op_f2c\n"
".weak MPI_Op_f2c\n"
".set MPI_Op_f2c,CCMPI_Op_f2c\n"
".extern in_w\n"
".extern A_MPI_Op_f2c\n"
".extern R_MPI_Op_f2c\n"
".type CCMPI_Op_f2c,@function\n"
".text\n"
"CCMPI_Op_f2c:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Op_f2c\n"
"b A_MPI_Op_f2c\n"
"inwrap_MPI_Op_f2c:\n"
"b R_MPI_Op_f2c\n"
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
"jne inwrap_MPI_Op_f2c\n"
"jmp *A_MPI_Op_f2c@GOTPCREL(%rip)\n"
"inwrap_MPI_Op_f2c:\n"
"jmp *R_MPI_Op_f2c@GOTPCREL(%rip)\n"
#endif

);
__asm__(
".global CCMPI_Op_c2f\n"
".weak MPI_Op_c2f\n"
".set MPI_Op_c2f,CCMPI_Op_c2f\n"
".extern in_w\n"
".extern A_MPI_Op_c2f\n"
".extern R_MPI_Op_c2f\n"
".type CCMPI_Op_c2f,@function\n"
".text\n"
"CCMPI_Op_c2f:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Op_c2f\n"
"b A_MPI_Op_c2f\n"
"inwrap_MPI_Op_c2f:\n"
"b R_MPI_Op_c2f\n"
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
"jne inwrap_MPI_Op_c2f\n"
"jmp *A_MPI_Op_c2f@GOTPCREL(%rip)\n"
"inwrap_MPI_Op_c2f:\n"
"jmp *R_MPI_Op_c2f@GOTPCREL(%rip)\n"
#endif

);



__asm__(
".global CCMPI_Info_f2c\n"
".weak MPI_Info_f2c\n"
".set MPI_Info_f2c,CCMPI_Info_f2c\n"
".extern in_w\n"
".extern A_MPI_Info_f2c\n"
".extern R_MPI_Info_f2c\n"
".type CCMPI_Info_f2c,@function\n"
".text\n"
"CCMPI_Info_f2c:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Info_f2c\n"
"b A_MPI_Info_f2c\n"
"inwrap_MPI_Info_f2c:\n"
"b R_MPI_Info_f2c\n"
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
"jne inwrap_MPI_Info_f2c\n"
"jmp *A_MPI_Info_f2c@GOTPCREL(%rip)\n"
"inwrap_MPI_Info_f2c:\n"
"jmp *R_MPI_Info_f2c@GOTPCREL(%rip)\n"
#endif

);

__asm__(
".global CCMPI_Info_c2f\n"
".weak MPI_Info_c2f\n"
".set MPI_Info_c2f,CCMPI_Info_c2f\n"
".extern in_w\n"
".extern A_MPI_Info_c2f\n"
".extern R_MPI_Info_c2f\n"
".type CCMPI_Info_c2f,@function\n"
".text\n"
"CCMPI_Info_c2f:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Info_c2f\n"
"b A_MPI_Info_c2f\n"
"inwrap_MPI_Info_c2f:\n"
"b R_MPI_Info_c2f\n"
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
"jne inwrap_MPI_Info_c2f\n"
"jmp *A_MPI_Info_c2f@GOTPCREL(%rip)\n"
"inwrap_MPI_Info_c2f:\n"
"jmp *R_MPI_Info_c2f@GOTPCREL(%rip)\n"
#endif

);


/*__asm__(
".global CCMPI_Errhandler_f2c\n"
".weak MPI_Errhandler_f2c\n"
".set MPI_Errhandler_f2c,CCMPI_Errhandler_f2c\n"
".extern in_w\n"
".extern A_MPI_Errhandler_f2c\n"
".extern R_MPI_Errhandler_f2c\n"
".type CCMPI_Errhandler_f2c,@function\n"
".text\n"
"CCMPI_Errhandler_f2c:\n"
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

);

R_MPI_Errhandler (*LOCAL_MPI_Errhandler_f2c)(R_MPI_Fint);
A_MPI_Errhandler A_MPI_Errhandler_f2c(A_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : A_MPI_Errhandler_f2c\n");
#endif
in_w=1;
A_MPI_Errhandler ret;
R_MPI_Fint op_tmp;
errhandler_converter_a2r(&op,&op_tmp);
R_MPI_Errhandler ret_tmp=LOCAL_MPI_Errhandler_f2c(op_tmp);
errhandler_comm_ptr_conv_r2a(&ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Errhandler_f2c\n");
#endif
return ret;
}


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
".global CCMPI_Errhandler_c2f\n"
".weak MPI_Errhandler_c2f\n"
".set MPI_Errhandler_c2f,CCMPI_Errhandler_c2f\n"
".extern in_w\n"
".extern A_MPI_Errhandler_c2f\n"
".extern R_MPI_Errhandler_c2f\n"
".type CCMPI_Errhandler_c2f,@function\n"
".text\n"
"CCMPI_Errhandler_c2f:\n"
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

);

R_MPI_Fint (*LOCAL_MPI_Errhandler_c2f)(R_MPI_Errhandler);
A_MPI_Fint A_MPI_Errhandler_c2f(A_MPI_Errhandler op)
{
#ifdef DEBUG
printf("entre : A_MPI_Errhandler_c2f\n");
#endif
in_w=1;
A_MPI_Fint ret;
R_MPI_Errhandler op_tmp;
errhandler_conv_a2r(&op,&op_tmp);
R_MPI_Fint ret_tmp=LOCAL_MPI_Errhandler_c2f(op_tmp);
errhandler_converter_r2a(&ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Errhandler_c2f\n");
#endif
return ret;
}


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
*/

__asm__(
".global CCMPI_Group_f2c\n"
".weak MPI_Group_f2c\n"
".set MPI_Group_f2c,CCMPI_Group_f2c\n"
".extern in_w\n"
".extern A_MPI_Group_f2c\n"
".extern R_MPI_Group_f2c\n"
".type CCMPI_Group_f2c,@function\n"
".text\n"
"CCMPI_Group_f2c:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Group_f2c\n"
"b A_MPI_Group_f2c\n"
"inwrap_MPI_Group_f2c:\n"
"b R_MPI_Group_f2c\n"
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
"jne inwrap_MPI_Group_f2c\n"
"jmp *A_MPI_Group_f2c@GOTPCREL(%rip)\n"
"inwrap_MPI_Group_f2c:\n"
"jmp *R_MPI_Group_f2c@GOTPCREL(%rip)\n"
#endif

);

__asm__(
".global CCMPI_Group_c2f\n"
".weak MPI_Group_c2f\n"
".set MPI_Group_c2f,CCMPI_Group_c2f\n"
".extern in_w\n"
".extern A_MPI_Group_c2f\n"
".extern R_MPI_Group_c2f\n"
".type CCMPI_Group_c2f,@function\n"
".text\n"
"CCMPI_Group_c2f:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Group_c2f\n"
"b A_MPI_Group_c2f\n"
"inwrap_MPI_Group_c2f:\n"
"b R_MPI_Group_c2f\n"
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
"jne inwrap_MPI_Group_c2f\n"
"jmp *A_MPI_Group_c2f@GOTPCREL(%rip)\n"
"inwrap_MPI_Group_c2f:\n"
"jmp *R_MPI_Group_c2f@GOTPCREL(%rip)\n"
#endif

);
/**/__asm__(
".global CCMPI_Request_f2c\n"
".weak MPI_Request_f2c\n"
".set MPI_Request_f2c,CCMPI_Request_f2c\n"
".extern in_w\n"
".extern A_MPI_Request_f2c\n"
".extern R_MPI_Request_f2c\n"
".type CCMPI_Request_f2c,@function\n"
".text\n"
"CCMPI_Request_f2c:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Request_f2c\n"
"b A_MPI_Request_f2c\n"
"inwrap_MPI_Request_f2c:\n"
"b R_MPI_Request_f2c\n"
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
"jne inwrap_MPI_Request_f2c\n"
"jmp *A_MPI_Request_f2c@GOTPCREL(%rip)\n"
"inwrap_MPI_Request_f2c:\n"
"jmp *R_MPI_Request_f2c@GOTPCREL(%rip)\n"
#endif

);
__asm__(
".global CCMPI_Request_c2f\n"
".weak MPI_Request_c2f\n"
".set MPI_Request_c2f,CCMPI_Request_c2f\n"
".extern in_w\n"
".extern A_MPI_Request_c2f\n"
".extern R_MPI_Request_c2f\n"
".type CCMPI_Request_c2f,@function\n"
".text\n"
"CCMPI_Request_c2f:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Request_c2f\n"
"b A_MPI_Request_c2f\n"
"inwrap_MPI_Request_c2f:\n"
"b R_MPI_Request_c2f\n"
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
"jne inwrap_MPI_Request_c2f\n"
"jmp *A_MPI_Request_c2f@GOTPCREL(%rip)\n"
"inwrap_MPI_Request_c2f:\n"
"jmp *R_MPI_Request_c2f@GOTPCREL(%rip)\n"
#endif

);

__asm__(
".global CCMPI_Type_f2c\n"
".weak MPI_Type_f2c\n"
".set MPI_Type_f2c,CCMPI_Type_f2c\n"
".extern in_w\n"
".extern A_MPI_Type_f2c\n"
".extern R_MPI_Type_f2c\n"
".type CCMPI_Type_f2c,@function\n"
".text\n"
"CCMPI_Type_f2c:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Type_f2c\n"
"b A_MPI_Type_f2c\n"
"inwrap_MPI_Type_f2c:\n"
"b R_MPI_Type_f2c\n"
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
"jne inwrap_MPI_Type_f2c\n"
"jmp *A_MPI_Type_f2c@GOTPCREL(%rip)\n"
"inwrap_MPI_Type_f2c:\n"
"jmp *R_MPI_Type_f2c@GOTPCREL(%rip)\n"
#endif

);
__asm__(
".global CCMPI_Type_c2f\n"
".weak MPI_Type_c2f\n"
".set MPI_Type_c2f,CCMPI_Type_c2f\n"
".extern in_w\n"
".extern A_MPI_Type_c2f\n"
".extern R_MPI_Type_c2f\n"
".type CCMPI_Type_c2f,@function\n"
".text\n"
"CCMPI_Type_c2f:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Type_c2f\n"
"b A_MPI_Type_c2f\n"
"inwrap_MPI_Type_c2f:\n"
"b R_MPI_Type_c2f\n"
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
"jne inwrap_MPI_Type_c2f\n"
"jmp *A_MPI_Type_c2f@GOTPCREL(%rip)\n"
"inwrap_MPI_Type_c2f:\n"
"jmp *R_MPI_Type_c2f@GOTPCREL(%rip)\n"
#endif

);
__asm__(
".global CCMPI_Comm_f2c\n"
".weak MPI_Comm_f2c\n"
".set MPI_Comm_f2c,CCMPI_Comm_f2c\n"
".extern in_w\n"
".extern A_MPI_Comm_f2c\n"
".extern R_MPI_Comm_f2c\n"
".type CCMPI_Comm_f2c,@function\n"
".text\n"
"CCMPI_Comm_f2c:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Comm_f2c\n"
"b A_MPI_Comm_f2c\n"
"inwrap_MPI_Comm_f2c:\n"
"b R_MPI_Comm_f2c\n"
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
"jne inwrap_MPI_Comm_f2c\n"
"jmp *A_MPI_Comm_f2c@GOTPCREL(%rip)\n"
"inwrap_MPI_Comm_f2c:\n"
"jmp *R_MPI_Comm_f2c@GOTPCREL(%rip)\n"
#endif

);
__asm__(
".global CCMPI_Comm_c2f\n"
".weak MPI_Comm_c2f\n"
".set MPI_Comm_c2f,CCMPI_Comm_c2f\n"
".extern in_w\n"
".extern A_MPI_Comm_c2f\n"
".extern R_MPI_Comm_c2f\n"
".type CCMPI_Comm_c2f,@function\n"
".text\n"
"CCMPI_Comm_c2f:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Comm_c2f\n"
"b A_MPI_Comm_c2f\n"
"inwrap_MPI_Comm_c2f:\n"
"b R_MPI_Comm_c2f\n"
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
"jne inwrap_MPI_Comm_c2f\n"
"jmp *A_MPI_Comm_c2f@GOTPCREL(%rip)\n"
"inwrap_MPI_Comm_c2f:\n"
"jmp *R_MPI_Comm_c2f@GOTPCREL(%rip)\n"
#endif

);

__asm__(
".global CCMPI_Status_c2f\n"
".weak MPI_Status_c2f\n"
".set MPI_Status_c2f,CCMPI_Status_c2f\n"
".extern in_w\n"
".extern A_MPI_Status_c2f\n"
".extern R_MPI_Status_c2f\n"
".type CCMPI_Status_c2f,@function\n"
".text\n"
"CCMPI_Status_c2f:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Status_c2f\n"
"b A_MPI_Status_c2f\n"
"inwrap_MPI_Status_c2f:\n"
"b R_MPI_Status_c2f\n"
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
"jne inwrap_MPI_Status_c2f\n"
"jmp *A_MPI_Status_c2f@GOTPCREL(%rip)\n"
"inwrap_MPI_Status_c2f:\n"
"jmp *R_MPI_Status_c2f@GOTPCREL(%rip)\n"
#endif

);
__asm__(
".global CCMPI_Status_f2c\n"
".weak MPI_Status_f2c\n"
".set MPI_Status_f2c,CCMPI_Status_f2c\n"
".extern in_w\n"
".extern A_MPI_Status_f2c\n"
".extern R_MPI_Status_f2c\n"
".type CCMPI_Status_f2c,@function\n"
".text\n"
"CCMPI_Status_f2c:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Status_f2c\n"
"b A_MPI_Status_f2c\n"
"inwrap_MPI_Status_f2c:\n"
"b R_MPI_Status_f2c\n"
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
"jne inwrap_MPI_Status_f2c\n"
"jmp *A_MPI_Status_f2c@GOTPCREL(%rip)\n"
"inwrap_MPI_Status_f2c:\n"
"jmp *R_MPI_Status_f2c@GOTPCREL(%rip)\n"
#endif

);
#elif defined(OMPI_INTEL) || defined(_INTEL)
#include "mappers.h"
extern __thread int in_w;

__asm__(
".global CCMPI_Win_f2c\n"
".weak MPI_Win_f2c\n"
".set MPI_Win_f2c,CCMPI_Win_f2c\n"
".extern in_w\n"
".extern A_MPI_Win_f2c\n"
".extern R_MPI_Win_f2c\n"
".type CCMPI_Win_f2c,@function\n"
".text\n"
"CCMPI_Win_f2c:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Win_f2c\n"
"b A_MPI_Win_f2c\n"
"inwrap_MPI_Win_f2c:\n"
"b R__MPI_Win_f2c\n"
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
"jne inwrap_MPI_Win_f2c\n"
"jmp *A_MPI_Win_f2c@GOTPCREL(%rip)\n"
"inwrap_MPI_Win_f2c:\n"
"jmp *R__MPI_Win_f2c@GOTPCREL(%rip)\n"
#endif

);

R_MPI_Win R__MPI_Win_f2c(R_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : R_MPI_Win_f2c\n");
#endif
#ifdef DEBUG
printf("sort : R_MPI_Win_f2c\n");
#endif
return R_MPI_Win_f2c(op);
}


__asm__(
".global CCMPI_Win_c2f\n"
".weak MPI_Win_c2f\n"
".set MPI_Win_c2f,CCMPI_Win_c2f\n"
".extern in_w\n"
".extern A_MPI_Win_c2f\n"
".extern R_MPI_Win_c2f\n"
".type CCMPI_Win_c2f,@function\n"
".text\n"
"CCMPI_Win_c2f:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Win_c2f\n"
"b A_MPI_Win_c2f\n"
"inwrap_MPI_Win_c2f:\n"
"b R__MPI_Win_c2f\n"
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
"jne inwrap_MPI_Win_c2f\n"
"jmp *A_MPI_Win_c2f@GOTPCREL(%rip)\n"
"inwrap_MPI_Win_c2f:\n"
"jmp *R__MPI_Win_c2f@GOTPCREL(%rip)\n"
#endif

);

int R__MPI_Win_c2f(R_MPI_Win op)
{
#ifdef DEBUG
printf("entre : R_MPI_Win_c2f\n");
#endif
in_w=1;
in_w=0;
#ifdef DEBUG
printf("sort : R_MPI_Win_c2f\n");
#endif
return R_MPI_Win_c2f(op);
}

__asm__(
".global CCMPI_Message_f2c\n"
".weak MPI_Message_f2c\n"
".set MPI_Message_f2c,CCMPI_Message_f2c\n"
".extern in_w\n"
".extern A_MPI_Message_f2c\n"
".extern R_MPI_Message_f2c\n"
".type CCMPI_Message_f2c,@function\n"
".text\n"
"CCMPI_Message_f2c:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Message_f2c\n"
"b A_MPI_Message_f2c\n"
"inwrap_MPI_Message_f2c:\n"
"b R__MPI_Message_f2c\n"
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
"jne inwrap_MPI_Message_f2c\n"
"jmp *A_MPI_Message_f2c@GOTPCREL(%rip)\n"
"inwrap_MPI_Message_f2c:\n"
"jmp *R__MPI_Message_f2c@GOTPCREL(%rip)\n"
#endif

);

R_MPI_Message R__MPI_Message_f2c(R_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : R_MPI_Message_f2c\n");
#endif
#ifdef DEBUG
printf("sort : R_MPI_Message_f2c\n");
#endif
return R_MPI_Message_f2c(op);
}


__asm__(
".global CCMPI_Message_c2f\n"
".weak MPI_Message_c2f\n"
".set MPI_Message_c2f,CCMPI_Message_c2f\n"
".extern in_w\n"
".extern A_MPI_Message_c2f\n"
".extern R_MPI_Message_c2f\n"
".type CCMPI_Message_c2f,@function\n"
".text\n"
"CCMPI_Message_c2f:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Message_c2f\n"
"b A_MPI_Message_c2f\n"
"inwrap_MPI_Message_c2f:\n"
"b R__MPI_Message_c2f\n"
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
"jne inwrap_MPI_Message_c2f\n"
"jmp *A_MPI_Message_c2f@GOTPCREL(%rip)\n"
"inwrap_MPI_Message_c2f:\n"
"jmp *R__MPI_Message_c2f@GOTPCREL(%rip)\n"
#endif

);

int R__MPI_Message_c2f(R_MPI_Message op)
{
#ifdef DEBUG
printf("entre : R_MPI_Message_c2f\n");
#endif
in_w=1;
in_w=0;
#ifdef DEBUG
printf("sort : R_MPI_Message_c2f\n");
#endif
return R_MPI_Message_c2f(op);
}
__asm__(
".global CCMPI_Op_f2c\n"
".weak MPI_Op_f2c\n"
".set MPI_Op_f2c,CCMPI_Op_f2c\n"
".extern in_w\n"
".extern A_MPI_Op_f2c\n"
".extern R_MPI_Op_f2c\n"
".type CCMPI_Op_f2c,@function\n"
".text\n"
"CCMPI_Op_f2c:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Op_f2c\n"
"b A_MPI_Op_f2c\n"
"inwrap_MPI_Op_f2c:\n"
"b R__MPI_Op_f2c\n"
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
"jne inwrap_MPI_Op_f2c\n"
"jmp *A_MPI_Op_f2c@GOTPCREL(%rip)\n"
"inwrap_MPI_Op_f2c:\n"
"jmp *R__MPI_Op_f2c@GOTPCREL(%rip)\n"
#endif

);

R_MPI_Op R__MPI_Op_f2c(R_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : R_MPI_Op_f2c\n");
#endif
#ifdef DEBUG
printf("sort : R_MPI_Op_f2c\n");
#endif
return R_MPI_Op_f2c(op);
}


__asm__(
".global CCMPI_Op_c2f\n"
".weak MPI_Op_c2f\n"
".set MPI_Op_c2f,CCMPI_Op_c2f\n"
".extern in_w\n"
".extern A_MPI_Op_c2f\n"
".extern R_MPI_Op_c2f\n"
".type CCMPI_Op_c2f,@function\n"
".text\n"
"CCMPI_Op_c2f:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Op_c2f\n"
"b A_MPI_Op_c2f\n"
"inwrap_MPI_Op_c2f:\n"
"b R__MPI_Op_c2f\n"
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
"jne inwrap_MPI_Op_c2f\n"
"jmp *A_MPI_Op_c2f@GOTPCREL(%rip)\n"
"inwrap_MPI_Op_c2f:\n"
"jmp *R__MPI_Op_c2f@GOTPCREL(%rip)\n"
#endif

);

int R__MPI_Op_c2f(R_MPI_Op op)
{
#ifdef DEBUG
printf("entre : R_MPI_Op_c2f\n");
#endif
in_w=1;
in_w=0;
#ifdef DEBUG
printf("sort : R_MPI_Op_c2f\n");
#endif
return R_MPI_Op_c2f(op);
}


__asm__(
".global CCMPI_Info_f2c\n"
".weak MPI_Info_f2c\n"
".set MPI_Info_f2c,CCMPI_Info_f2c\n"
".extern in_w\n"
".extern A_MPI_Info_f2c\n"
".extern R_MPI_Info_f2c\n"
".type CCMPI_Info_f2c,@function\n"
".text\n"
"CCMPI_Info_f2c:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Info_f2c\n"
"b A_MPI_Info_f2c\n"
"inwrap_MPI_Info_f2c:\n"
"b R__MPI_Info_f2c\n"
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
"jne inwrap_MPI_Info_f2c\n"
"jmp *A_MPI_Info_f2c@GOTPCREL(%rip)\n"
"inwrap_MPI_Info_f2c:\n"
"jmp *R__MPI_Info_f2c@GOTPCREL(%rip)\n"
#endif

);


R_MPI_Info R__MPI_Info_f2c(R_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : R_MPI_Info_f2c\n");
#endif
#ifdef DEBUG
printf("sort : R_MPI_Info_f2c\n");
#endif
return R_MPI_Info_f2c(op);
}


__asm__(
".global CCMPI_Info_c2f\n"
".weak MPI_Info_c2f\n"
".set MPI_Info_c2f,CCMPI_Info_c2f\n"
".extern in_w\n"
".extern A_MPI_Info_c2f\n"
".extern R_MPI_Info_c2f\n"
".type CCMPI_Info_c2f,@function\n"
".text\n"
"CCMPI_Info_c2f:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Info_c2f\n"
"b A_MPI_Info_c2f\n"
"inwrap_MPI_Info_c2f:\n"
"b R__MPI_Info_c2f\n"
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
"jne inwrap_MPI_Info_c2f\n"
"jmp *A_MPI_Info_c2f@GOTPCREL(%rip)\n"
"inwrap_MPI_Info_c2f:\n"
"jmp *R__MPI_Info_c2f@GOTPCREL(%rip)\n"
#endif

);

int R__MPI_Info_c2f(R_MPI_Info op)
{
#ifdef DEBUG
printf("entre : R_MPI_Info_c2f\n");
#endif
in_w=1;
in_w=0;
#ifdef DEBUG
printf("sort : R_MPI_Info_c2f\n");
#endif
return R_MPI_Info_c2f(op);
}


/*__asm__(
".global CCMPI_Errhandler_f2c\n"
".weak MPI_Errhandler_f2c\n"
".set MPI_Errhandler_f2c,CCMPI_Errhandler_f2c\n"
".extern in_w\n"
".extern A_MPI_Errhandler_f2c\n"
".extern R_MPI_Errhandler_f2c\n"
".type CCMPI_Errhandler_f2c,@function\n"
".text\n"
"CCMPI_Errhandler_f2c:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Errhandler_f2c\n"
"b A_MPI_Errhandler_f2c\n"
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
"jmp *A_MPI_Errhandler_f2c@GOTPCREL(%rip)\n"
"inwrap_MPI_Errhandler_f2c:\n"
"jmp *R__MPI_Errhandler_f2c@GOTPCREL(%rip)\n"
#endif

);

A_MPI_Errhandler A__MPI_Errhandler_f2c(A_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : A_MPI_Errhandler_f2c\n");
#endif
in_w=1;
A_MPI_Errhandler op_ret;
int op_tmp;
errhandler_converter_a2r(&op,&op_tmp);
errhandler_comm_ptr_conv_r2a(&op_ret,&op_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Errhandler_f2c\n");
#endif
return op_ret;
}


R_MPI_Errhandler R__MPI_Errhandler_f2c(R_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : R_MPI_Errhandler_f2c\n");
#endif
#ifdef DEBUG
printf("sort : R_MPI_Errhandler_f2c\n");
#endif
return op;
}


__asm__(
".global CCMPI_Errhandler_c2f\n"
".weak MPI_Errhandler_c2f\n"
".set MPI_Errhandler_c2f,CCMPI_Errhandler_c2f\n"
".extern in_w\n"
".extern A_MPI_Errhandler_c2f\n"
".extern R_MPI_Errhandler_c2f\n"
".type CCMPI_Errhandler_c2f,@function\n"
".text\n"
"CCMPI_Errhandler_c2f:\n"
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

);

int A__MPI_Errhandler_c2f(A_MPI_Errhandler op)
{
#ifdef DEBUG
printf("entre : A_MPI_Errhandler_c2f\n");
#endif
in_w=1;
int ret;
R_MPI_Errhandler op_tmp;
errhandler_conv_a2r(&op,&op_tmp);
errhandler_converter_r2a(&ret,&op_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Errhandler_c2f\n");
#endif
return ret;
}


int R__MPI_Errhandler_c2f(R_MPI_Errhandler op)
{
#ifdef DEBUG
printf("entre : R_MPI_Errhandler_c2f\n");
#endif
in_w=1;
in_w=0;
#ifdef DEBUG
printf("sort : R_MPI_Errhandler_c2f\n");
#endif
return op;
}
*/

__asm__(
".global CCMPI_Group_f2c\n"
".weak MPI_Group_f2c\n"
".set MPI_Group_f2c,CCMPI_Group_f2c\n"
".extern in_w\n"
".extern A_MPI_Group_f2c\n"
".extern R_MPI_Group_f2c\n"
".type CCMPI_Group_f2c,@function\n"
".text\n"
"CCMPI_Group_f2c:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Group_f2c\n"
"b A_MPI_Group_f2c\n"
"inwrap_MPI_Group_f2c:\n"
"b R__MPI_Group_f2c\n"
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
"jne inwrap_MPI_Group_f2c\n"
"jmp *A_MPI_Group_f2c@GOTPCREL(%rip)\n"
"inwrap_MPI_Group_f2c:\n"
"jmp *R__MPI_Group_f2c@GOTPCREL(%rip)\n"
#endif

);

/*A_MPI_Group A__MPI_Group_f2c(A_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : A_MPI_Group_f2c\n");
#endif
in_w=1;
A_MPI_Group op_ret;
int op_tmp;
group_a2r(&op,&op_tmp);
group_conv_r2a(&op_ret,&op_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Group_f2c\n");
#endif
return op_ret;
}
*/

R_MPI_Group R__MPI_Group_f2c(R_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : R_MPI_Group_f2c\n");
#endif
#ifdef DEBUG
printf("sort : R_MPI_Group_f2c\n");
#endif
return R_MPI_Group_f2c(op);
}


__asm__(
".global CCMPI_Group_c2f\n"
".weak MPI_Group_c2f\n"
".set MPI_Group_c2f,CCMPI_Group_c2f\n"
".extern in_w\n"
".extern A_MPI_Group_c2f\n"
".extern R_MPI_Group_c2f\n"
".type CCMPI_Group_c2f,@function\n"
".text\n"
"CCMPI_Group_c2f:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Group_c2f\n"
"b A_MPI_Group_c2f\n"
"inwrap_MPI_Group_c2f:\n"
"b R__MPI_Group_c2f\n"
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
"jne inwrap_MPI_Group_c2f\n"
"jmp *A_MPI_Group_c2f@GOTPCREL(%rip)\n"
"inwrap_MPI_Group_c2f:\n"
"jmp *R__MPI_Group_c2f@GOTPCREL(%rip)\n"
#endif

);

/*int A__MPI_Group_c2f(A_MPI_Group op)
{
#ifdef DEBUG
printf("entre : A_MPI_Group_c2f\n");
#endif
in_w=1;
int ret;
R_MPI_Group op_tmp;
group_conv_a2r(&op,&op_tmp);
group_r2a(&ret,&op_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Group_c2f\n");
#endif
return ret;
}*/


int R__MPI_Group_c2f(R_MPI_Group op)
{
#ifdef DEBUG
printf("entre : R_MPI_Group_c2f\n");
#endif
in_w=1;
in_w=0;
#ifdef DEBUG
printf("sort : R_MPI_Group_c2f\n");
#endif
return R_MPI_Group_c2f(op);
}


__asm__(
".global CCMPI_Request_f2c\n"
".weak MPI_Request_f2c\n"
".set MPI_Request_f2c,CCMPI_Request_f2c\n"
".extern in_w\n"
".extern A_MPI_Request_f2c\n"
".extern R_MPI_Request_f2c\n"
".type CCMPI_Request_f2c,@function\n"
".text\n"
"CCMPI_Request_f2c:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Request_f2c\n"
"b A_MPI_Request_f2c\n"
"inwrap_MPI_Request_f2c:\n"
"b R__MPI_Request_f2c\n"
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
"jne inwrap_MPI_Request_f2c\n"
"jmp *A_MPI_Request_f2c@GOTPCREL(%rip)\n"
"inwrap_MPI_Request_f2c:\n"
"jmp *R__MPI_Request_f2c@GOTPCREL(%rip)\n"
#endif

);

/*A_MPI_Request A__MPI_Request_f2c(A_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : A_MPI_Request_f2c\n");
#endif
in_w=1;
A_MPI_Request op_ret;
int op_tmp;
request_a2r(&op,&op_tmp);
request_ptr_conv_r2a(&op_ret,&op_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Request_f2c\n");
#endif
return op_ret;
}
*/

R_MPI_Request R__MPI_Request_f2c(R_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : R_MPI_Request_f2c\n");
#endif
#ifdef DEBUG
printf("sort : R_MPI_Request_f2c\n");
#endif
return R_MPI_Request_f2c(op);
}


__asm__(
".global CCMPI_Request_c2f\n"
".weak MPI_Request_c2f\n"
".set MPI_Request_c2f,CCMPI_Request_c2f\n"
".extern in_w\n"
".extern A_MPI_Request_c2f\n"
".extern R_MPI_Request_c2f\n"
".type CCMPI_Request_c2f,@function\n"
".text\n"
"CCMPI_Request_c2f:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Request_c2f\n"
"b A_MPI_Request_c2f\n"
"inwrap_MPI_Request_c2f:\n"
"b R__MPI_Request_c2f\n"
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
"jne inwrap_MPI_Request_c2f\n"
"jmp *A_MPI_Request_c2f@GOTPCREL(%rip)\n"
"inwrap_MPI_Request_c2f:\n"
"jmp *R__MPI_Request_c2f@GOTPCREL(%rip)\n"
#endif

);
/*
int A__MPI_Request_c2f(A_MPI_Request op)
{
#ifdef DEBUG
printf("entre : A_MPI_Request_c2f\n");
#endif
in_w=1;
int ret;
R_MPI_Request op_tmp;
request_ptr_conv_a2r(&op,&op_tmp);
request_r2a(&ret,&op_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Request_c2f\n");
#endif
return ret;
}
*/

int R__MPI_Request_c2f(R_MPI_Request op)
{
#ifdef DEBUG
printf("entre : R_MPI_Request_c2f\n");
#endif
in_w=1;
in_w=0;
#ifdef DEBUG
printf("sort : R_MPI_Request_c2f\n");
#endif
return R_MPI_Request_c2f(op);
}


__asm__(
".global CCMPI_Type_f2c\n"
".weak MPI_Type_f2c\n"
".set MPI_Type_f2c,CCMPI_Type_f2c\n"
".extern in_w\n"
".extern A_MPI_Type_f2c\n"
".extern R_MPI_Type_f2c\n"
".type CCMPI_Type_f2c,@function\n"
".text\n"
"CCMPI_Type_f2c:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Type_f2c\n"
"b A_MPI_Type_f2c\n"
"inwrap_MPI_Type_f2c:\n"
"b R__MPI_Type_f2c\n"
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
"jne inwrap_MPI_Type_f2c\n"
"jmp *A_MPI_Type_f2c@GOTPCREL(%rip)\n"
"inwrap_MPI_Type_f2c:\n"
"jmp *R__MPI_Type_f2c@GOTPCREL(%rip)\n"
#endif

);

/*A_MPI_Datatype A__MPI_Type_f2c(A_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : A_MPI_Type_f2c\n");
#endif
in_w=1;
A_MPI_Datatype op_ret;
int op_tmp;
datatype_a2r(&op,&op_tmp);
datatype_conv_r2a(&op_ret,&op_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Type_f2c\n");
#endif
return op_ret;
}
*/

R_MPI_Datatype R__MPI_Type_f2c(R_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : R_MPI_Type_f2c\n");
#endif
#ifdef DEBUG
printf("sort : R_MPI_Type_f2c\n");
#endif
return R_MPI_Type_f2c(op);
}


__asm__(
".global CCMPI_Type_c2f\n"
".weak MPI_Type_c2f\n"
".set MPI_Type_c2f,CCMPI_Type_c2f\n"
".extern in_w\n"
".extern A_MPI_Type_c2f\n"
".extern R_MPI_Type_c2f\n"
".type CCMPI_Type_c2f,@function\n"
".text\n"
"CCMPI_Type_c2f:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Type_c2f\n"
"b A_MPI_Type_c2f\n"
"inwrap_MPI_Type_c2f:\n"
"b R__MPI_Type_c2f\n"
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
"jne inwrap_MPI_Type_c2f\n"
"jmp *A_MPI_Type_c2f@GOTPCREL(%rip)\n"
"inwrap_MPI_Type_c2f:\n"
"jmp *R__MPI_Type_c2f@GOTPCREL(%rip)\n"
#endif

);
/*
int A__MPI_Type_c2f(A_MPI_Datatype op)
{
#ifdef DEBUG
printf("entre : A_MPI_Type_c2f\n");
#endif
in_w=1;
int ret;
R_MPI_Datatype op_tmp;
datatype_conv_a2r(&op,&op_tmp);
datatype_r2a(&ret,&op_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Type_c2f\n");
#endif
return ret;
}*/


int R__MPI_Type_c2f(R_MPI_Datatype op)
{
#ifdef DEBUG
printf("entre : R_MPI_Type_c2f\n");
#endif
in_w=1;
in_w=0;
#ifdef DEBUG
printf("sort : R_MPI_Type_c2f\n");
#endif
return R_MPI_Type_c2f(op);
}


__asm__(
".global CCMPI_Comm_f2c\n"
".weak MPI_Comm_f2c\n"
".set MPI_Comm_f2c,CCMPI_Comm_f2c\n"
".extern in_w\n"
".extern A_MPI_Comm_f2c\n"
".extern R_MPI_Comm_f2c\n"
".type CCMPI_Comm_f2c,@function\n"
".text\n"
"CCMPI_Comm_f2c:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Comm_f2c\n"
"b A_MPI_Comm_f2c\n"
"inwrap_MPI_Comm_f2c:\n"
"b R__MPI_Comm_f2c\n"
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
"jne inwrap_MPI_Comm_f2c\n"
"jmp *A_MPI_Comm_f2c@GOTPCREL(%rip)\n"
"inwrap_MPI_Comm_f2c:\n"
"jmp *R__MPI_Comm_f2c@GOTPCREL(%rip)\n"
#endif

);

/*A_MPI_Comm A__MPI_Comm_f2c(A_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : A_MPI_Comm_f2c\n");
#endif
in_w=1;
A_MPI_Comm op_ret;
int op_tmp;
comm_a2r(&op,&op_tmp);
comm_conv_r2a(&op_ret,&op_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Comm_f2c\n");
#endif
return op_ret;
}
*/

R_MPI_Comm R__MPI_Comm_f2c(R_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : R_MPI_Comm_f2c\n");
#endif
#ifdef DEBUG
printf("sort : R_MPI_Comm_f2c\n");
#endif
return R_MPI_Comm_f2c(op);
}


__asm__(
".global CCMPI_Comm_c2f\n"
".weak MPI_Comm_c2f\n"
".set MPI_Comm_c2f,CCMPI_Comm_c2f\n"
".extern in_w\n"
".extern A_MPI_Comm_c2f\n"
".extern R_MPI_Comm_c2f\n"
".type CCMPI_Comm_c2f,@function\n"
".text\n"
"CCMPI_Comm_c2f:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Comm_c2f\n"
"b A_MPI_Comm_c2f\n"
"inwrap_MPI_Comm_c2f:\n"
"b R__MPI_Comm_c2f\n"
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
"jne inwrap_MPI_Comm_c2f\n"
"jmp *A_MPI_Comm_c2f@GOTPCREL(%rip)\n"
"inwrap_MPI_Comm_c2f:\n"
"jmp *R__MPI_Comm_c2f@GOTPCREL(%rip)\n"
#endif

);
/*
int A__MPI_Comm_c2f(A_MPI_Comm op)
{
#ifdef DEBUG
printf("entre : A_MPI_Comm_c2f\n");
#endif
in_w=1;
int ret;
R_MPI_Comm op_tmp;
comm_conv_a2r(&op,&op_tmp);
comm_r2a(&ret,&op_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Comm_c2f\n");
#endif
return ret;
}*/


int R__MPI_Comm_c2f(R_MPI_Comm op)
{
#ifdef DEBUG
printf("entre : R_MPI_Comm_c2f\n");
#endif
in_w=1;
in_w=0;
#ifdef DEBUG
printf("sort : R_MPI_Comm_c2f\n");
#endif
return R_MPI_Comm_c2f(op);
}
__asm__(
".global CCMPI_File_f2c\n"
".weak MPI_File_f2c\n"
".set MPI_File_f2c,CCMPI_File_f2c\n"
".extern in_w\n"
".extern A_MPI_File_f2c\n"
".extern R_MPI_File_f2c\n"
".type CCMPI_File_f2c,@function\n"
".text\n"
"CCMPI_File_f2c:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_File_f2c\n"
"b A_MPI_File_f2c\n"
"inwrap_MPI_File_f2c:\n"
"b R__MPI_File_f2c\n"
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
"jne inwrap_MPI_File_f2c\n"
"jmp *A_MPI_File_f2c@GOTPCREL(%rip)\n"
"inwrap_MPI_File_f2c:\n"
"jmp *R__MPI_File_f2c@GOTPCREL(%rip)\n"
#endif

);

R_MPI_File (*LOCAL_MPI_File_f2c)(R_MPI_Fint);
/*A_MPI_File A_MPI_File_f2c(A_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : A_MPI_File_f2c\n");
#endif
in_w=1;
A_MPI_File ret;
R_MPI_File ret_tmp=LOCAL_MPI_File_f2c(op);
file_conv_r2a(&ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_f2c\n");
#endif
return ret;
}
*/

R_MPI_File R__MPI_File_f2c(R_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : R_MPI_File_f2c\n");
#endif
R_MPI_File ret=LOCAL_MPI_File_f2c(op);
#ifdef DEBUG
printf("sort : R_MPI_File_f2c\n");
#endif
return ret;
}


__asm__(
".global CCMPI_File_c2f\n"
".weak MPI_File_c2f\n"
".set MPI_File_c2f,CCMPI_File_c2f\n"
".extern in_w\n"
".extern A_MPI_File_c2f\n"
".extern R__MPI_File_c2f\n"
".type CCMPI_File_c2f,@function\n"
".text\n"
"CCMPI_File_c2f:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_File_c2f\n"
"b A_MPI_File_c2f\n"
"inwrap_MPI_File_c2f:\n"
"b R__MPI_File_c2f\n"
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
"jne inwrap_MPI_File_c2f\n"
"jmp *A_MPI_File_c2f@GOTPCREL(%rip)\n"
"inwrap_MPI_File_c2f:\n"
"jmp *R__MPI_File_c2f@GOTPCREL(%rip)\n"
#endif

);

R_MPI_Fint (*LOCAL_MPI_File_c2f)(R_MPI_File);
/*A_MPI_Fint A_MPI_File_c2f(A_MPI_File op)
{
#ifdef DEBUG
printf("entre : A_MPI_File_c2f\n");
#endif
in_w=1;
A_MPI_Fint ret;
R_MPI_File op_tmp;
file_conv_a2r(&op,&op_tmp);
ret=LOCAL_MPI_File_c2f(op_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_c2f\n");
#endif
return ret;
}*/


R_MPI_Fint R__MPI_File_c2f(R_MPI_File op)
{
#ifdef DEBUG
printf("entre : R_MPI_File_c2f\n");
#endif
in_w=1;
R_MPI_Fint ret=LOCAL_MPI_File_c2f(op);
in_w=0;
#ifdef DEBUG
printf("sort : R_MPI_File_c2f\n");
#endif
return ret;
}


int (*LOCAL_MPI_Status_f2c)(R_MPI_Fint*,R_MPI_Status*);
int (*LOCAL_MPI_Status_c2f)(R_MPI_Status* ,R_MPI_Fint*);

__attribute__((constructor)) void wrapper_init_c2ff2c(void) {
void *lib_handle_c2ff2c=dlopen(getenv("WI4MPI_RUN_MPI_C_LIB"),RTLD_NOW|RTLD_GLOBAL);
LOCAL_MPI_File_f2c=dlsym(lib_handle_c2ff2c,"PMPI_File_f2c");
LOCAL_MPI_File_c2f=dlsym(lib_handle_c2ff2c,"PMPI_File_c2f");

LOCAL_MPI_Status_f2c=dlsym(lib_handle_c2ff2c,"PMPI_Status_f2c");
LOCAL_MPI_Status_c2f=dlsym(lib_handle_c2ff2c,"PMPI_Status_c2f");
}

__asm__(
".global CCMPI_Status_c2f\n"
".weak MPI_Status_c2f\n"
".set MPI_Status_c2f,CCMPI_Status_c2f\n"
".extern in_w\n"
".extern A_MPI_Status_c2f\n"
".extern R_MPI_Status_c2f\n"
".type CCMPI_Status_c2f,@function\n"
".text\n"
"CCMPI_Status_c2f:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Status_c2f\n"
"b A_MPI_Status_c2f\n"
"inwrap_MPI_Status_c2f:\n"
"b R__MPI_Status_c2f\n"
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
"jne inwrap_MPI_Status_c2f\n"
"jmp *A_MPI_Status_c2f@GOTPCREL(%rip)\n"
"inwrap_MPI_Status_c2f:\n"
"jmp *R__MPI_Status_c2f@GOTPCREL(%rip)\n"
#endif

);
int R__MPI_Status_c2f(R_MPI_Status *in,R_MPI_Fint *op)
{
#ifdef DEBUG
printf("entre : R_MPI_Status_c2f\n");
#endif
in_w=1;
int ret=LOCAL_MPI_Status_c2f(in,op);
in_w=0;
#ifdef DEBUG
printf("sort : R_MPI_Status_c2f\n");
#endif
return ret;
}
__asm__(
".global CCMPI_Status_f2c\n"
".weak MPI_Status_f2c\n"
".set MPI_Status_f2c,CCMPI_Status_f2c\n"
".extern in_w\n"
".extern A_MPI_Status_f2c\n"
".extern R_MPI_Status_f2c\n"
".type CCMPI_Status_f2c,@function\n"
".text\n"
"CCMPI_Status_f2c:\n"
#ifdef __aarch64__
"adrp x8, :gottprel:in_w\n"
"ldr x8, [x8, :gottprel_lo12:in_w]\n"
"mrs x9, TPIDR_EL0\n"
"ldr w8, [x9, x8]\n"
"cbnz w8, inwrap_MPI_Status_f2c\n"
"b A_MPI_Status_f2c\n"
"inwrap_MPI_Status_f2c:\n"
"b R__MPI_Status_f2c\n"
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
"jne inwrap_MPI_Status_f2c\n"
"jmp *A_MPI_Status_f2c@GOTPCREL(%rip)\n"
"inwrap_MPI_Status_f2c:\n"
"jmp *R__MPI_Status_f2c@GOTPCREL(%rip)\n"
#endif

);
int R__MPI_Status_f2c(R_MPI_Fint *in,R_MPI_Status *op)
{
#ifdef DEBUG
printf("entre : R_MPI_Status_f2c\n");
#endif
in_w=1;
int ret=LOCAL_MPI_Status_f2c(in,op);
in_w=0;
#ifdef DEBUG
printf("sort : R_MPI_Status_f2c\n");
#endif
return ret;
}
#endif

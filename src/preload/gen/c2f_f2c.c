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
#if defined(INTEL_OMPI) || defined(OMPI_OMPI) || defined(_OMPI)
#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <stdio.h>
#include <dlfcn.h>
#include "wrapper_f.h"
#include "mappers.h"
extern __thread int in_w;
__asm__(
".global PMPI_File_f2c\n"
".weak MPI_File_f2c\n"
".set MPI_File_f2c,PMPI_File_f2c\n"
".extern in_w\n"
".extern A_MPI_File_f2c\n"
".extern R_MPI_File_f2c\n"
".type PMPI_File_f2c,@function\n"
".text\n"
"PMPI_File_f2c:\n"
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
".size PMPI_File_f2c,.-PMPI_File_f2c\n"

);

R_MPI_File (*LOCAL_MPI_File_f2c)(R_MPI_Fint);
A_MPI_File A_MPI_File_f2c(A_MPI_Fint op)
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


R_MPI_File R_MPI_File_f2c(R_MPI_Fint op)
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
".global PMPI_File_c2f\n"
".weak MPI_File_c2f\n"
".set MPI_File_c2f,PMPI_File_c2f\n"
".extern in_w\n"
".extern A_MPI_File_c2f\n"
".extern R_MPI_File_c2f\n"
".type PMPI_File_c2f,@function\n"
".text\n"
"PMPI_File_c2f:\n"
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
".size PMPI_File_c2f,.-PMPI_File_c2f\n"

);

R_MPI_Fint (*LOCAL_MPI_File_c2f)(R_MPI_File);
A_MPI_Fint A_MPI_File_c2f(A_MPI_File op)
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
}


R_MPI_Fint R_MPI_File_c2f(R_MPI_File op)
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


__asm__(
".global PMPI_Op_f2c\n"
".weak MPI_Op_f2c\n"
".set MPI_Op_f2c,PMPI_Op_f2c\n"
".extern in_w\n"
".extern A_MPI_Op_f2c\n"
".extern R_MPI_Op_f2c\n"
".type PMPI_Op_f2c,@function\n"
".text\n"
"PMPI_Op_f2c:\n"
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
".size PMPI_Op_f2c,.-PMPI_Op_f2c\n"

);

R_MPI_Op (*LOCAL_MPI_Op_f2c)(R_MPI_Fint);
A_MPI_Op A_MPI_Op_f2c(A_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : A_MPI_Op_f2c\n");
#endif
in_w=1;
A_MPI_Op ret;
R_MPI_Fint op_tmp;
operator_a2r(&op,&op_tmp);
R_MPI_Op ret_tmp=LOCAL_MPI_Op_f2c(op_tmp);
op_conv_r2a(&ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Op_f2c\n");
#endif
return ret;
}


R_MPI_Op R_MPI_Op_f2c(R_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : R_MPI_Op_f2c\n");
#endif
R_MPI_Op ret=LOCAL_MPI_Op_f2c(op);
#ifdef DEBUG
printf("sort : R_MPI_Op_f2c\n");
#endif
return ret;
}


__asm__(
".global PMPI_Op_c2f\n"
".weak MPI_Op_c2f\n"
".set MPI_Op_c2f,PMPI_Op_c2f\n"
".extern in_w\n"
".extern A_MPI_Op_c2f\n"
".extern R_MPI_Op_c2f\n"
".type PMPI_Op_c2f,@function\n"
".text\n"
"PMPI_Op_c2f:\n"
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
".size PMPI_Op_c2f,.-PMPI_Op_c2f\n"

);

R_MPI_Fint (*LOCAL_MPI_Op_c2f)(R_MPI_Op);
A_MPI_Fint A_MPI_Op_c2f(A_MPI_Op op)
{
#ifdef DEBUG
printf("entre : A_MPI_Op_c2f\n");
#endif
in_w=1;
A_MPI_Fint ret;
R_MPI_Op op_tmp;
op_conv_a2r(&op,&op_tmp);
R_MPI_Fint ret_tmp=LOCAL_MPI_Op_c2f(op_tmp);
operator_r2a(&ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Op_c2f\n");
#endif
return ret;
}


R_MPI_Fint R_MPI_Op_c2f(R_MPI_Op op)
{
#ifdef DEBUG
printf("entre : R_MPI_Op_c2f\n");
#endif
in_w=1;
R_MPI_Fint ret=LOCAL_MPI_Op_c2f(op);
in_w=0;
#ifdef DEBUG
printf("sort : R_MPI_Op_c2f\n");
#endif
return ret;
}


__asm__(
".global PMPI_Info_f2c\n"
".weak MPI_Info_f2c\n"
".set MPI_Info_f2c,PMPI_Info_f2c\n"
".extern in_w\n"
".extern A_MPI_Info_f2c\n"
".extern R_MPI_Info_f2c\n"
".type PMPI_Info_f2c,@function\n"
".text\n"
"PMPI_Info_f2c:\n"
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
".size PMPI_Info_f2c,.-PMPI_Info_f2c\n"

);

R_MPI_Info (*LOCAL_MPI_Info_f2c)(R_MPI_Fint);
A_MPI_Info A_MPI_Info_f2c(A_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : A_MPI_Info_f2c\n");
#endif
in_w=1;
A_MPI_Info ret;
R_MPI_Fint op_tmp;
info_a2r(&op,&op_tmp);
R_MPI_Info ret_tmp=LOCAL_MPI_Info_f2c(op_tmp);
info_conv_r2a(&ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Info_f2c\n");
#endif
return ret;
}


R_MPI_Info R_MPI_Info_f2c(R_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : R_MPI_Info_f2c\n");
#endif
R_MPI_Info ret=LOCAL_MPI_Info_f2c(op);
#ifdef DEBUG
printf("sort : R_MPI_Info_f2c\n");
#endif
return ret;
}


__asm__(
".global PMPI_Info_c2f\n"
".weak MPI_Info_c2f\n"
".set MPI_Info_c2f,PMPI_Info_c2f\n"
".extern in_w\n"
".extern A_MPI_Info_c2f\n"
".extern R_MPI_Info_c2f\n"
".type PMPI_Info_c2f,@function\n"
".text\n"
"PMPI_Info_c2f:\n"
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
".size PMPI_Info_c2f,.-PMPI_Info_c2f\n"

);

R_MPI_Fint (*LOCAL_MPI_Info_c2f)(R_MPI_Info);
A_MPI_Fint A_MPI_Info_c2f(A_MPI_Info op)
{
#ifdef DEBUG
printf("entre : A_MPI_Info_c2f\n");
#endif
in_w=1;
A_MPI_Fint ret;
R_MPI_Info op_tmp;
info_conv_a2r(&op,&op_tmp);
R_MPI_Fint ret_tmp=LOCAL_MPI_Info_c2f(op_tmp);
info_r2a(&ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Info_c2f\n");
#endif
return ret;
}


R_MPI_Fint R_MPI_Info_c2f(R_MPI_Info op)
{
#ifdef DEBUG
printf("entre : R_MPI_Info_c2f\n");
#endif
in_w=1;
R_MPI_Fint ret=LOCAL_MPI_Info_c2f(op);
in_w=0;
#ifdef DEBUG
printf("sort : R_MPI_Info_c2f\n");
#endif
return ret;
}


__asm__(
".global PMPI_Group_f2c\n"
".weak MPI_Group_f2c\n"
".set MPI_Group_f2c,PMPI_Group_f2c\n"
".extern in_w\n"
".extern A_MPI_Group_f2c\n"
".extern R_MPI_Group_f2c\n"
".type PMPI_Group_f2c,@function\n"
".text\n"
"PMPI_Group_f2c:\n"
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
".size PMPI_Group_f2c,.-PMPI_Group_f2c\n"

);

R_MPI_Group (*LOCAL_MPI_Group_f2c)(R_MPI_Fint);
A_MPI_Group A_MPI_Group_f2c(A_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : A_MPI_Group_f2c\n");
#endif
in_w=1;
A_MPI_Group ret;
R_MPI_Fint op_tmp;
group_a2r(&op,&op_tmp);
R_MPI_Group ret_tmp=LOCAL_MPI_Group_f2c(op_tmp);
group_conv_r2a(&ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Group_f2c\n");
#endif
return ret;
}


R_MPI_Group R_MPI_Group_f2c(R_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : R_MPI_Group_f2c\n");
#endif
R_MPI_Group ret=LOCAL_MPI_Group_f2c(op);
#ifdef DEBUG
printf("sort : R_MPI_Group_f2c\n");
#endif
return ret;
}


__asm__(
".global PMPI_Group_c2f\n"
".weak MPI_Group_c2f\n"
".set MPI_Group_c2f,PMPI_Group_c2f\n"
".extern in_w\n"
".extern A_MPI_Group_c2f\n"
".extern R_MPI_Group_c2f\n"
".type PMPI_Group_c2f,@function\n"
".text\n"
"PMPI_Group_c2f:\n"
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
".size PMPI_Group_c2f,.-PMPI_Group_c2f\n"

);

R_MPI_Fint (*LOCAL_MPI_Group_c2f)(R_MPI_Group);
A_MPI_Fint A_MPI_Group_c2f(A_MPI_Group op)
{
#ifdef DEBUG
printf("entre : A_MPI_Group_c2f\n");
#endif
in_w=1;
A_MPI_Fint ret;
R_MPI_Group op_tmp;
group_conv_a2r(&op,&op_tmp);
R_MPI_Fint ret_tmp=LOCAL_MPI_Group_c2f(op_tmp);
group_r2a(&ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Group_c2f\n");
#endif
return ret;
}


R_MPI_Fint R_MPI_Group_c2f(R_MPI_Group op)
{
#ifdef DEBUG
printf("entre : R_MPI_Group_c2f\n");
#endif
in_w=1;
R_MPI_Fint ret=LOCAL_MPI_Group_c2f(op);
in_w=0;
#ifdef DEBUG
printf("sort : R_MPI_Group_c2f\n");
#endif
return ret;
}


__asm__(
".global PMPI_Request_f2c\n"
".weak MPI_Request_f2c\n"
".set MPI_Request_f2c,PMPI_Request_f2c\n"
".extern in_w\n"
".extern A_MPI_Request_f2c\n"
".extern R_MPI_Request_f2c\n"
".type PMPI_Request_f2c,@function\n"
".text\n"
"PMPI_Request_f2c:\n"
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
".size PMPI_Request_f2c,.-PMPI_Request_f2c\n"

);

R_MPI_Request (*LOCAL_MPI_Request_f2c)(R_MPI_Fint);
A_MPI_Request A_MPI_Request_f2c(A_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : A_MPI_Request_f2c\n");
#endif
in_w=1;
A_MPI_Request ret;
R_MPI_Fint op_tmp;
request_a2r(&op,&op_tmp);
R_MPI_Request ret_tmp=LOCAL_MPI_Request_f2c(op_tmp);
request_tab_conv_r2a(&ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Request_f2c\n");
#endif
return ret;
}


R_MPI_Request R_MPI_Request_f2c(R_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : R_MPI_Request_f2c\n");
#endif
R_MPI_Request ret=LOCAL_MPI_Request_f2c(op);
#ifdef DEBUG
printf("sort : R_MPI_Request_f2c\n");
#endif
return ret;
}


__asm__(
".global PMPI_Request_c2f\n"
".weak MPI_Request_c2f\n"
".set MPI_Request_c2f,PMPI_Request_c2f\n"
".extern in_w\n"
".extern A_MPI_Request_c2f\n"
".extern R_MPI_Request_c2f\n"
".type PMPI_Request_c2f,@function\n"
".text\n"
"PMPI_Request_c2f:\n"
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
".size PMPI_Request_c2f,.-PMPI_Request_c2f\n"

);

R_MPI_Fint (*LOCAL_MPI_Request_c2f)(R_MPI_Request);
A_MPI_Fint A_MPI_Request_c2f(A_MPI_Request op)
{
#ifdef DEBUG
printf("entre : A_MPI_Request_c2f\n");
#endif
in_w=1;
A_MPI_Fint ret;
R_MPI_Request op_tmp;
request_tab_conv_a2r(&op,&op_tmp);
R_MPI_Fint ret_tmp=LOCAL_MPI_Request_c2f(op_tmp);
request_r2a(&ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Request_c2f\n");
#endif
return ret;
}


R_MPI_Fint R_MPI_Request_c2f(R_MPI_Request op)
{
#ifdef DEBUG
printf("entre : R_MPI_Request_c2f\n");
#endif
in_w=1;
R_MPI_Fint ret=LOCAL_MPI_Request_c2f(op);
in_w=0;
#ifdef DEBUG
printf("sort : R_MPI_Request_c2f\n");
#endif
return ret;
}


__asm__(
".global PMPI_Type_f2c\n"
".weak MPI_Type_f2c\n"
".set MPI_Type_f2c,PMPI_Type_f2c\n"
".extern in_w\n"
".extern A_MPI_Type_f2c\n"
".extern R_MPI_Type_f2c\n"
".type PMPI_Type_f2c,@function\n"
".text\n"
"PMPI_Type_f2c:\n"
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
".size PMPI_Type_f2c,.-PMPI_Type_f2c\n"

);

R_MPI_Datatype (*LOCAL_MPI_Type_f2c)(R_MPI_Fint);
A_MPI_Datatype A_MPI_Type_f2c(A_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : A_MPI_Type_f2c\n");
#endif
in_w=1;
A_MPI_Datatype ret;
R_MPI_Fint op_tmp;
datatype_a2r(&op,&op_tmp);
R_MPI_Datatype ret_tmp=LOCAL_MPI_Type_f2c(op_tmp);
datatype_conv_r2a(&ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Type_f2c\n");
#endif
return ret;
}


R_MPI_Datatype R_MPI_Type_f2c(R_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : R_MPI_Type_f2c\n");
#endif
R_MPI_Datatype ret=LOCAL_MPI_Type_f2c(op);
#ifdef DEBUG
printf("sort : R_MPI_Type_f2c\n");
#endif
return ret;
}


__asm__(
".global PMPI_Type_c2f\n"
".weak MPI_Type_c2f\n"
".set MPI_Type_c2f,PMPI_Type_c2f\n"
".extern in_w\n"
".extern A_MPI_Type_c2f\n"
".extern R_MPI_Type_c2f\n"
".type PMPI_Type_c2f,@function\n"
".text\n"
"PMPI_Type_c2f:\n"
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
".size PMPI_Type_c2f,.-PMPI_Type_c2f\n"

);

R_MPI_Fint (*LOCAL_MPI_Type_c2f)(R_MPI_Datatype);
A_MPI_Fint A_MPI_Type_c2f(A_MPI_Datatype op)
{
#ifdef DEBUG
printf("entre : A_MPI_Type_c2f\n");
#endif
in_w=1;
A_MPI_Fint ret;
R_MPI_Datatype op_tmp;
datatype_conv_a2r(&op,&op_tmp);
R_MPI_Fint ret_tmp=LOCAL_MPI_Type_c2f(op_tmp);
datatype_r2a(&ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Type_c2f\n");
#endif
return ret;
}


R_MPI_Fint R_MPI_Type_c2f(R_MPI_Datatype op)
{
#ifdef DEBUG
printf("entre : R_MPI_Type_c2f\n");
#endif
in_w=1;
R_MPI_Fint ret=LOCAL_MPI_Type_c2f(op);
in_w=0;
#ifdef DEBUG
printf("sort : R_MPI_Type_c2f\n");
#endif
return ret;
}


__asm__(
".global PMPI_Comm_f2c\n"
".weak MPI_Comm_f2c\n"
".set MPI_Comm_f2c,PMPI_Comm_f2c\n"
".extern in_w\n"
".extern A_MPI_Comm_f2c\n"
".extern R_MPI_Comm_f2c\n"
".type PMPI_Comm_f2c,@function\n"
".text\n"
"PMPI_Comm_f2c:\n"
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
".size PMPI_Comm_f2c,.-PMPI_Comm_f2c\n"

);

R_MPI_Comm (*LOCAL_MPI_Comm_f2c)(R_MPI_Fint);
A_MPI_Comm A_MPI_Comm_f2c(A_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : A_MPI_Comm_f2c\n");
#endif
in_w=1;
A_MPI_Comm ret;
R_MPI_Fint op_tmp;
comm_a2r(&op,&op_tmp);
R_MPI_Comm ret_tmp=LOCAL_MPI_Comm_f2c(op_tmp);
comm_conv_r2a(&ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Comm_f2c\n");
#endif
return ret;
}


R_MPI_Comm R_MPI_Comm_f2c(R_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : R_MPI_Comm_f2c\n");
#endif
R_MPI_Comm ret=LOCAL_MPI_Comm_f2c(op);
#ifdef DEBUG
printf("sort : R_MPI_Comm_f2c\n");
#endif
return ret;
}


__asm__(
".global PMPI_Comm_c2f\n"
".weak MPI_Comm_c2f\n"
".set MPI_Comm_c2f,PMPI_Comm_c2f\n"
".extern in_w\n"
".extern A_MPI_Comm_c2f\n"
".extern R_MPI_Comm_c2f\n"
".type PMPI_Comm_c2f,@function\n"
".text\n"
"PMPI_Comm_c2f:\n"
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
".size PMPI_Comm_c2f,.-PMPI_Comm_c2f\n"

);

R_MPI_Fint (*LOCAL_MPI_Comm_c2f)(R_MPI_Comm);
A_MPI_Fint A_MPI_Comm_c2f(A_MPI_Comm op)
{
#ifdef DEBUG
printf("entre : A_MPI_Comm_c2f\n");
#endif
in_w=1;
A_MPI_Fint ret;
R_MPI_Comm op_tmp;
comm_conv_a2r(&op,&op_tmp);
R_MPI_Fint ret_tmp=LOCAL_MPI_Comm_c2f(op_tmp);
comm_r2a(&ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Comm_c2f\n");
#endif
return ret;
}


R_MPI_Fint R_MPI_Comm_c2f(R_MPI_Comm op)
{
#ifdef DEBUG
printf("entre : R_MPI_Comm_c2f\n");
#endif
in_w=1;
R_MPI_Fint ret=LOCAL_MPI_Comm_c2f(op);
in_w=0;
#ifdef DEBUG
printf("sort : R_MPI_Comm_c2f\n");
#endif
return ret;
}


__asm__(
".global PMPI_Win_f2c\n"
".weak MPI_Win_f2c\n"
".set MPI_Win_f2c,PMPI_Win_f2c\n"
".extern in_w\n"
".extern A_MPI_Win_f2c\n"
".extern R_MPI_Win_f2c\n"
".type PMPI_Win_f2c,@function\n"
".text\n"
"PMPI_Win_f2c:\n"
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
".size PMPI_Win_f2c,.-PMPI_Win_f2c\n"

);

R_MPI_Win (*LOCAL_MPI_Win_f2c)(R_MPI_Fint);
A_MPI_Win A_MPI_Win_f2c(A_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : A_MPI_Win_f2c\n");
#endif
in_w=1;
A_MPI_Win ret;
R_MPI_Fint op_tmp;
fwin_a2r(&op,&op_tmp);
R_MPI_Win ret_tmp=LOCAL_MPI_Win_f2c(op_tmp);
win_conv_r2a(&ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Win_f2c\n");
#endif
return ret;
}


R_MPI_Win R_MPI_Win_f2c(R_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : R_MPI_Win_f2c\n");
#endif
R_MPI_Win ret=LOCAL_MPI_Win_f2c(op);
#ifdef DEBUG
printf("sort : R_MPI_Win_f2c\n");
#endif
return ret;
}


__asm__(
".global PMPI_Win_c2f\n"
".weak MPI_Win_c2f\n"
".set MPI_Win_c2f,PMPI_Win_c2f\n"
".extern in_w\n"
".extern A_MPI_Win_c2f\n"
".extern R_MPI_Win_c2f\n"
".type PMPI_Win_c2f,@function\n"
".text\n"
"PMPI_Win_c2f:\n"
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
".size PMPI_Win_c2f,.-PMPI_Win_c2f\n"

);

R_MPI_Fint (*LOCAL_MPI_Win_c2f)(R_MPI_Win);
A_MPI_Fint A_MPI_Win_c2f(A_MPI_Win op)
{
#ifdef DEBUG
printf("entre : A_MPI_Win_c2f\n");
#endif
in_w=1;
A_MPI_Fint ret;
R_MPI_Win op_tmp;
win_conv_a2r(&op,&op_tmp);
R_MPI_Fint ret_tmp=LOCAL_MPI_Win_c2f(op_tmp);
fwin_r2a(&ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Win_c2f\n");
#endif
return ret;
}


R_MPI_Fint R_MPI_Win_c2f(R_MPI_Win op)
{
#ifdef DEBUG
printf("entre : R_MPI_Win_c2f\n");
#endif
in_w=1;
R_MPI_Fint ret=LOCAL_MPI_Win_c2f(op);
in_w=0;
#ifdef DEBUG
printf("sort : R_MPI_Win_c2f\n");
#endif
return ret;
}


__asm__(
".global PMPI_Message_f2c\n"
".weak MPI_Message_f2c\n"
".set MPI_Message_f2c,PMPI_Message_f2c\n"
".extern in_w\n"
".extern A_MPI_Message_f2c\n"
".extern R_MPI_Message_f2c\n"
".type PMPI_Message_f2c,@function\n"
".text\n"
"PMPI_Message_f2c:\n"
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
".size PMPI_Message_f2c,.-PMPI_Message_f2c\n"

);

R_MPI_Message (*LOCAL_MPI_Message_f2c)(R_MPI_Fint);
A_MPI_Message A_MPI_Message_f2c(A_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : A_MPI_Message_f2c\n");
#endif
in_w=1;
A_MPI_Message ret;
R_MPI_Fint op_tmp;
message_a2r(&op,&op_tmp);
R_MPI_Message ret_tmp=LOCAL_MPI_Message_f2c(op_tmp);
message_conv_r2a(&ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Message_f2c\n");
#endif
return ret;
}


R_MPI_Message R_MPI_Message_f2c(R_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : R_MPI_Message_f2c\n");
#endif
R_MPI_Message ret=LOCAL_MPI_Message_f2c(op);
#ifdef DEBUG
printf("sort : R_MPI_Message_f2c\n");
#endif
return ret;
}


__asm__(
".global PMPI_Message_c2f\n"
".weak MPI_Message_c2f\n"
".set MPI_Message_c2f,PMPI_Message_c2f\n"
".extern in_w\n"
".extern A_MPI_Message_c2f\n"
".extern R_MPI_Message_c2f\n"
".type PMPI_Message_c2f,@function\n"
".text\n"
"PMPI_Message_c2f:\n"
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
".size PMPI_Message_c2f,.-PMPI_Message_c2f\n"

);

R_MPI_Fint (*LOCAL_MPI_Message_c2f)(R_MPI_Message);
A_MPI_Fint A_MPI_Message_c2f(A_MPI_Message op)
{
#ifdef DEBUG
printf("entre : A_MPI_Message_c2f\n");
#endif
in_w=1;
A_MPI_Fint ret;
R_MPI_Message op_tmp;
message_conv_a2r(&op,&op_tmp);
R_MPI_Fint ret_tmp=LOCAL_MPI_Message_c2f(op_tmp);
message_r2a(&ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Message_c2f\n");
#endif
return ret;
}


R_MPI_Fint R_MPI_Message_c2f(R_MPI_Message op)
{
#ifdef DEBUG
printf("entre : R_MPI_Message_c2f\n");
#endif
in_w=1;
R_MPI_Fint ret=LOCAL_MPI_Message_c2f(op);
in_w=0;
#ifdef DEBUG
printf("sort : R_MPI_Message_c2f\n");
#endif
return ret;
}

int (*LOCAL_MPI_Status_f2c)(R_MPI_Fint*,R_MPI_Status*);
int (*LOCAL_MPI_Status_c2f)(R_MPI_Status* ,R_MPI_Fint*);

__attribute__((constructor)) void wrapper_init_c2ff2c(void) {
void *lib_handle_c2ff2c=dlopen(getenv("WI4MPI_RUN_MPI_C_LIB"),RTLD_NOW|RTLD_GLOBAL);
LOCAL_MPI_File_f2c=dlsym(lib_handle_c2ff2c,"PMPI_File_f2c");
LOCAL_MPI_File_c2f=dlsym(lib_handle_c2ff2c,"PMPI_File_c2f");
LOCAL_MPI_Op_f2c=dlsym(lib_handle_c2ff2c,"PMPI_Op_f2c");
LOCAL_MPI_Op_c2f=dlsym(lib_handle_c2ff2c,"PMPI_Op_c2f");
LOCAL_MPI_Info_f2c=dlsym(lib_handle_c2ff2c,"PMPI_Info_f2c");
LOCAL_MPI_Info_c2f=dlsym(lib_handle_c2ff2c,"PMPI_Info_c2f");
LOCAL_MPI_Group_f2c=dlsym(lib_handle_c2ff2c,"PMPI_Group_f2c");
LOCAL_MPI_Group_c2f=dlsym(lib_handle_c2ff2c,"PMPI_Group_c2f");
LOCAL_MPI_Request_f2c=dlsym(lib_handle_c2ff2c,"PMPI_Request_f2c");
LOCAL_MPI_Request_c2f=dlsym(lib_handle_c2ff2c,"PMPI_Request_c2f");
LOCAL_MPI_Type_f2c=dlsym(lib_handle_c2ff2c,"PMPI_Type_f2c");
LOCAL_MPI_Type_c2f=dlsym(lib_handle_c2ff2c,"PMPI_Type_c2f");
LOCAL_MPI_Comm_f2c=dlsym(lib_handle_c2ff2c,"PMPI_Comm_f2c");
LOCAL_MPI_Comm_c2f=dlsym(lib_handle_c2ff2c,"PMPI_Comm_c2f");
LOCAL_MPI_Win_f2c=dlsym(lib_handle_c2ff2c,"PMPI_Win_f2c");
LOCAL_MPI_Win_c2f=dlsym(lib_handle_c2ff2c,"PMPI_Win_c2f");
LOCAL_MPI_Message_f2c=dlsym(lib_handle_c2ff2c,"PMPI_Message_f2c");
LOCAL_MPI_Message_c2f=dlsym(lib_handle_c2ff2c,"PMPI_Message_c2f");
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

);
int A_MPI_Status_c2f(A_MPI_Status *in, A_MPI_Fint *op)
{ 
#ifdef DEBUG
printf("entre : A_MPI_Status_c2f\n");
#endif
in_w=1;
int tmp[R_f_MPI_STATUS_SIZE];
R_MPI_Status ltmp;
R_MPI_Status *tmp2=&ltmp;
status_prt_conv_a2r(&in,&tmp2);
int ret=LOCAL_MPI_Status_c2f(tmp2,tmp);
status_r2a(tmp,op);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Status_c2f\n");
#endif
return ret;
}
int R_MPI_Status_c2f(R_MPI_Status *in,R_MPI_Fint *op)
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
".global MPI_Status_f2c\n"
".weak MPI_Status_f2c\n"
".set MPI_Status_f2c,CCMPI_Status_f2c\n"
".extern in_w\n"
".extern A_MPI_Status_f2c\n"
".extern R_MPI_Status_f2c\n"
".type MPI_Status_f2c,@function\n"
".text\n"
"MPI_Status_f2c:\n"
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

);
int A_MPI_Status_f2c(A_MPI_Fint *in,A_MPI_Status *op)
{
#ifdef DEBUG
printf("entre : A_MPI_Status_f2c\n");
#endif
in_w=1;
int tmp[R_f_MPI_STATUS_SIZE];
R_MPI_Status tmp2;
//status_prt_conv_r2a
status_a2r(in,tmp);
int ret=LOCAL_MPI_Status_f2c(tmp,&tmp2);
//status_prt_conv_r2a(&op,&(&tmp2));
status_tab_conv_r2a(op,&tmp2);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Status_f2c\n");
#endif
return ret;
}
int R_MPI_Status_f2c(R_MPI_Fint *in,R_MPI_Status *op)
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
#elif defined(OMPI_INTEL) || defined(_INTEL)
#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <stdio.h>
#include <dlfcn.h>
//char ompi_mpi_comm_null[1024];
//char ompi_mpi_comm_self[1024];
//char ompi_mpi_comm_world[1024];
//char ompi_mpi_2cplex[512];
//char ompi_mpi_2dblcplex[512];
//char ompi_mpi_2dblprec[512];
//char ompi_mpi_2int[512];
//char ompi_mpi_2integer[512];
//char ompi_mpi_2real[512];
//char ompi_mpi_aint[512];
//char ompi_mpi_byte[512];
//char ompi_mpi_c_bool[512];
//char ompi_mpi_c_complex[512];
//char ompi_mpi_c_double_complex[512];
//char ompi_mpi_c_float_complex[512];
//char ompi_mpi_c_long_double_complex[512];
//char ompi_mpi_char[512];
//char ompi_mpi_character[512];
//char ompi_mpi_complex16[512];
//char ompi_mpi_complex32[512];
//char ompi_mpi_complex8[512];
//char ompi_mpi_cplex[512];
//char ompi_mpi_cxx_bool[512];
//char ompi_mpi_cxx_cplex[512];
//char ompi_mpi_cxx_dblcplex[512];
//char ompi_mpi_cxx_ldblcplex[512];
//char ompi_mpi_datatype_null[512];
//char ompi_mpi_dblcplex[512];
//char ompi_mpi_dblprec[512];
//char ompi_mpi_double[512];
//char ompi_mpi_double_int[512];
//char ompi_mpi_float[512];
//char ompi_mpi_float_int[512];
//char ompi_mpi_int16_t[512];
//char ompi_mpi_int32_t[512];
//char ompi_mpi_int64_t[512];
//char ompi_mpi_int8_t[512];
//char ompi_mpi_int[512];
//char ompi_mpi_integer16[512];
//char ompi_mpi_integer1[512];
//char ompi_mpi_integer2[512];
//char ompi_mpi_integer4[512];
//char ompi_mpi_integer8[512];
//char ompi_mpi_integer[512];
//char ompi_mpi_lb[512];
//char ompi_mpi_ldblcplex[512];
//char ompi_mpi_logical1[512];
//char ompi_mpi_logical2[512];
//char ompi_mpi_logical4[512];
//char ompi_mpi_logical8[512];
//char ompi_mpi_logical[512];
//char ompi_mpi_long[512];
//char ompi_mpi_long_double[512];
//char ompi_mpi_long_int[512];
//char ompi_mpi_long_long_int[512];
//char ompi_mpi_longdbl_int[512];
//char ompi_mpi_offset[512];
//char ompi_mpi_count[512];
//char ompi_message_null[512];
//char ompi_mpi_packed[512];
//char ompi_mpi_real16[512];
//char ompi_mpi_real2[512];
//char ompi_mpi_real4[512];
//char ompi_mpi_real8[512];
//char ompi_mpi_real[512];
//char ompi_mpi_short[512];
//char ompi_mpi_short_int[512];
//char ompi_mpi_signed_char[512];
//char ompi_mpi_ub[512];
//char ompi_mpi_uint16_t[512];
//char ompi_mpi_uint32_t[512];
//char ompi_mpi_uint64_t[512];
//char ompi_mpi_uint8_t[512];
//char ompi_mpi_unsigned[512];
//char ompi_mpi_unsigned_char[512];
//char ompi_mpi_unsigned_long[512];
//char ompi_mpi_unsigned_long_long[512];
//char ompi_mpi_unsigned_short[512];
//char ompi_mpi_wchar[512];
//char ompi_mpi_errhandler_null[1024];
//char ompi_mpi_errors_are_fatal[1024];
//char ompi_mpi_errors_return[1024];
//char ompi_mpi_file_null[1536];
//char ompi_mpi_group_empty[256];
//char ompi_mpi_group_null[256];
//char ompi_mpi_info_null[256];
//char ompi_mpi_op_band[2048];
//char ompi_mpi_op_bor[2048];
//char ompi_mpi_op_bxor[2048];
//char ompi_mpi_op_land[2048];
//char ompi_mpi_op_lor[2048];
//char ompi_mpi_op_lxor[2048];
//char ompi_mpi_op_max[2048];
//char ompi_mpi_op_maxloc[2048];
//char ompi_mpi_op_min[2048];
//char ompi_mpi_op_minloc[2048];
//char ompi_mpi_op_null[2048];
//char ompi_mpi_op_prod[2048];
//char ompi_mpi_op_replace[2048];
//char ompi_mpi_op_sum[2048];
//char ompi_request_null[256];
//char ompi_mpi_win_null[512];
//char ompi_message_no_proc[512];
#include "wrapper_f.h"
#include "mappers.h"
extern __thread int in_w;
__asm__(
".global PMPI_File_f2c\n"
".weak MPI_File_f2c\n"
".set MPI_File_f2c,PMPI_File_f2c\n"
".extern in_w\n"
".extern A_MPI_File_f2c\n"
".extern R_MPI_File_f2c\n"
".type PMPI_File_f2c,@function\n"
".text\n"
"PMPI_File_f2c:\n"
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
"jmp *A__MPI_File_f2c@GOTPCREL(%rip)\n"
"inwrap_MPI_File_f2c:\n"
"jmp *R__MPI_File_f2c@GOTPCREL(%rip)\n"
".size PMPI_File_f2c,.-PMPI_File_f2c\n"

);

R_MPI_File (*LOCAL_MPI_File_f2c)(R_MPI_Fint);
A_MPI_File A__MPI_File_f2c(A_MPI_Fint op)
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
".global PMPI_File_c2f\n"
".weak MPI_File_c2f\n"
".set MPI_File_c2f,PMPI_File_c2f\n"
".extern in_w\n"
".extern A_MPI_File_c2f\n"
".extern R_MPI_File_c2f\n"
".type PMPI_File_c2f,@function\n"
".text\n"
"PMPI_File_c2f:\n"
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
"jmp *A__MPI_File_c2f@GOTPCREL(%rip)\n"
"inwrap_MPI_File_c2f:\n"
"jmp *R__MPI_File_c2f@GOTPCREL(%rip)\n"
".size PMPI_File_c2f,.-PMPI_File_c2f\n"

);

int (*LOCAL_MPI_File_c2f)(R_MPI_File);
int A__MPI_File_c2f(A_MPI_File op)
{
#ifdef DEBUG
printf("entre : A_MPI_File_c2f\n");
#endif
in_w=1;
int ret;
R_MPI_File op_tmp;
file_conv_a2r(&op,&op_tmp);
int ret_tmp=LOCAL_MPI_File_c2f(op_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_File_c2f\n");
#endif
return ret_tmp;
}


int R__MPI_File_c2f(R_MPI_File op)
{
#ifdef DEBUG
printf("entre : R_MPI_File_c2f\n");
#endif
in_w=1;
int ret=LOCAL_MPI_File_c2f(op);
in_w=0;
#ifdef DEBUG
printf("sort : R_MPI_File_c2f\n");
#endif
return ret;
}


__asm__(
".global PMPI_Op_f2c\n"
".weak MPI_Op_f2c\n"
".set MPI_Op_f2c,PMPI_Op_f2c\n"
".extern in_w\n"
".extern A_MPI_Op_f2c\n"
".extern R_MPI_Op_f2c\n"
".type PMPI_Op_f2c,@function\n"
".text\n"
"PMPI_Op_f2c:\n"
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
"jmp *A__MPI_Op_f2c@GOTPCREL(%rip)\n"
"inwrap_MPI_Op_f2c:\n"
"jmp *R__MPI_Op_f2c@GOTPCREL(%rip)\n"
".size PMPI_Op_f2c,.-PMPI_Op_f2c\n"

);

A_MPI_Op A__MPI_Op_f2c(A_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : A_MPI_Op_f2c\n");
#endif
in_w=1;
A_MPI_Op op_ret;
int op_tmp;
operator_a2r(&op,&op_tmp);
op_conv_r2a(&op_ret,&op_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Op_f2c\n");
#endif
return op_ret;
}


R_MPI_Op R__MPI_Op_f2c(R_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : R_MPI_Op_f2c\n");
#endif
#ifdef DEBUG
printf("sort : R_MPI_Op_f2c\n");
#endif
return op;
}


__asm__(
".global PMPI_Op_c2f\n"
".weak MPI_Op_c2f\n"
".set MPI_Op_c2f,PMPI_Op_c2f\n"
".extern in_w\n"
".extern A_MPI_Op_c2f\n"
".extern R_MPI_Op_c2f\n"
".type PMPI_Op_c2f,@function\n"
".text\n"
"PMPI_Op_c2f:\n"
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
"jmp *A__MPI_Op_c2f@GOTPCREL(%rip)\n"
"inwrap_MPI_Op_c2f:\n"
"jmp *R__MPI_Op_c2f@GOTPCREL(%rip)\n"
".size PMPI_Op_c2f,.-PMPI_Op_c2f\n"

);

int A__MPI_Op_c2f(A_MPI_Op op)
{
#ifdef DEBUG
printf("entre : A_MPI_Op_c2f\n");
#endif
in_w=1;
int ret;
R_MPI_Op op_tmp;
op_conv_a2r(&op,&op_tmp);
operator_r2a(&ret,&op_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Op_c2f\n");
#endif
return ret;
}


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
return op;
}


__asm__(
".global PMPI_Info_f2c\n"
".weak MPI_Info_f2c\n"
".set MPI_Info_f2c,PMPI_Info_f2c\n"
".extern in_w\n"
".extern A_MPI_Info_f2c\n"
".extern R_MPI_Info_f2c\n"
".type PMPI_Info_f2c,@function\n"
".text\n"
"PMPI_Info_f2c:\n"
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
"jmp *A__MPI_Info_f2c@GOTPCREL(%rip)\n"
"inwrap_MPI_Info_f2c:\n"
"jmp *R__MPI_Info_f2c@GOTPCREL(%rip)\n"
".size PMPI_Info_f2c,.-PMPI_Info_f2c\n"

);

R_MPI_Info (*LOCAL_MPI_Info_f2c)(R_MPI_Fint);
A_MPI_Info A__MPI_Info_f2c(A_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : A_MPI_Info_f2c\n");
#endif
in_w=1;
A_MPI_Info op_ret;
int op_tmp;
info_a2r(&op,&op_tmp);
R_MPI_Info ret_tmp=LOCAL_MPI_Info_f2c(op_tmp);
info_conv_r2a(&op_ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Info_f2c\n");
#endif
return op_ret;
}


R_MPI_Info R__MPI_Info_f2c(R_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : R_MPI_Info_f2c\n");
#endif
R_MPI_Info ret_tmp=LOCAL_MPI_Info_f2c(op);
#ifdef DEBUG
printf("sort : R_MPI_Info_f2c\n");
#endif
return op;
}


__asm__(
".global PMPI_Info_c2f\n"
".weak MPI_Info_c2f\n"
".set MPI_Info_c2f,PMPI_Info_c2f\n"
".extern in_w\n"
".extern A_MPI_Info_c2f\n"
".extern R_MPI_Info_c2f\n"
".type PMPI_Info_c2f,@function\n"
".text\n"
"PMPI_Info_c2f:\n"
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
"jmp *A__MPI_Info_c2f@GOTPCREL(%rip)\n"
"inwrap_MPI_Info_c2f:\n"
"jmp *R__MPI_Info_c2f@GOTPCREL(%rip)\n"
".size PMPI_Info_c2f,.-PMPI_Info_c2f\n"

);

R_MPI_Fint (*LOCAL_MPI_Info_c2f)(R_MPI_Info);
int A__MPI_Info_c2f(A_MPI_Info op)
{
#ifdef DEBUG
printf("entre : A_MPI_Info_c2f\n");
#endif
in_w=1;
int ret;
R_MPI_Info op_tmp;
info_conv_a2r(&op,&op_tmp);
int ret_tmp=LOCAL_MPI_Info_c2f(op_tmp);
info_r2a(&ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Info_c2f\n");
#endif
return ret;
}


int R__MPI_Info_c2f(R_MPI_Info op)
{
#ifdef DEBUG
printf("entre : R_MPI_Info_c2f\n");
#endif
in_w=1;
int ret=LOCAL_MPI_Info_c2f(op);
in_w=0;
#ifdef DEBUG
printf("sort : R_MPI_Info_c2f\n");
#endif
return ret;
}


__asm__(
".global PMPI_Group_f2c\n"
".weak MPI_Group_f2c\n"
".set MPI_Group_f2c,PMPI_Group_f2c\n"
".extern in_w\n"
".extern A_MPI_Group_f2c\n"
".extern R_MPI_Group_f2c\n"
".type PMPI_Group_f2c,@function\n"
".text\n"
"PMPI_Group_f2c:\n"
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
"jmp *A__MPI_Group_f2c@GOTPCREL(%rip)\n"
"inwrap_MPI_Group_f2c:\n"
"jmp *R__MPI_Group_f2c@GOTPCREL(%rip)\n"
".size PMPI_Group_f2c,.-PMPI_Group_f2c\n"

);

A_MPI_Group A__MPI_Group_f2c(A_MPI_Fint op)
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


R_MPI_Group R__MPI_Group_f2c(R_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : R_MPI_Group_f2c\n");
#endif
#ifdef DEBUG
printf("sort : R_MPI_Group_f2c\n");
#endif
return op;
}


__asm__(
".global PMPI_Group_c2f\n"
".weak MPI_Group_c2f\n"
".set MPI_Group_c2f,PMPI_Group_c2f\n"
".extern in_w\n"
".extern A_MPI_Group_c2f\n"
".extern R_MPI_Group_c2f\n"
".type PMPI_Group_c2f,@function\n"
".text\n"
"PMPI_Group_c2f:\n"
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
"jmp *A__MPI_Group_c2f@GOTPCREL(%rip)\n"
"inwrap_MPI_Group_c2f:\n"
"jmp *R__MPI_Group_c2f@GOTPCREL(%rip)\n"
".size PMPI_Group_c2f,.-PMPI_Group_c2f\n"

);

int A__MPI_Group_c2f(A_MPI_Group op)
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
}


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
return op;
}


__asm__(
".global PMPI_Request_f2c\n"
".weak MPI_Request_f2c\n"
".set MPI_Request_f2c,PMPI_Request_f2c\n"
".extern in_w\n"
".extern A_MPI_Request_f2c\n"
".extern R_MPI_Request_f2c\n"
".type PMPI_Request_f2c,@function\n"
".text\n"
"PMPI_Request_f2c:\n"
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
"jmp *A__MPI_Request_f2c@GOTPCREL(%rip)\n"
"inwrap_MPI_Request_f2c:\n"
"jmp *R__MPI_Request_f2c@GOTPCREL(%rip)\n"
".size PMPI_Request_f2c,.-PMPI_Request_f2c\n"

);

A_MPI_Request A__MPI_Request_f2c(A_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : A_MPI_Request_f2c\n");
#endif
in_w=1;
A_MPI_Request op_ret;
int op_tmp;
request_a2r(&op,&op_tmp);
request_tab_conv_r2a(&op_ret,&op_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Request_f2c\n");
#endif
return op_ret;
}


R_MPI_Request R__MPI_Request_f2c(R_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : R_MPI_Request_f2c\n");
#endif
#ifdef DEBUG
printf("sort : R_MPI_Request_f2c\n");
#endif
return op;
}


__asm__(
".global PMPI_Request_c2f\n"
".weak MPI_Request_c2f\n"
".set MPI_Request_c2f,PMPI_Request_c2f\n"
".extern in_w\n"
".extern A_MPI_Request_c2f\n"
".extern R_MPI_Request_c2f\n"
".type PMPI_Request_c2f,@function\n"
".text\n"
"PMPI_Request_c2f:\n"
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
"jmp *A__MPI_Request_c2f@GOTPCREL(%rip)\n"
"inwrap_MPI_Request_c2f:\n"
"jmp *R__MPI_Request_c2f@GOTPCREL(%rip)\n"
".size PMPI_Request_c2f,.-PMPI_Request_c2f\n"

);

int A__MPI_Request_c2f(A_MPI_Request op)
{
#ifdef DEBUG
printf("entre : A_MPI_Request_c2f\n");
#endif
in_w=1;
int ret;
R_MPI_Request op_tmp;
request_tab_conv_a2r(&op,&op_tmp);
request_r2a(&ret,&op_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Request_c2f\n");
#endif
return ret;
}


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
return op;
}


__asm__(
".global PMPI_Type_f2c\n"
".weak MPI_Type_f2c\n"
".set MPI_Type_f2c,PMPI_Type_f2c\n"
".extern in_w\n"
".extern A_MPI_Type_f2c\n"
".extern R_MPI_Type_f2c\n"
".type PMPI_Type_f2c,@function\n"
".text\n"
"PMPI_Type_f2c:\n"
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
"jmp *A__MPI_Type_f2c@GOTPCREL(%rip)\n"
"inwrap_MPI_Type_f2c:\n"
"jmp *R__MPI_Type_f2c@GOTPCREL(%rip)\n"
".size PMPI_Type_f2c,.-PMPI_Type_f2c\n"

);

A_MPI_Datatype A__MPI_Type_f2c(A_MPI_Fint op)
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


R_MPI_Datatype R__MPI_Type_f2c(R_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : R_MPI_Type_f2c\n");
#endif
#ifdef DEBUG
printf("sort : R_MPI_Type_f2c\n");
#endif
return op;
}


__asm__(
".global PMPI_Type_c2f\n"
".weak MPI_Type_c2f\n"
".set MPI_Type_c2f,PMPI_Type_c2f\n"
".extern in_w\n"
".extern A_MPI_Type_c2f\n"
".extern R_MPI_Type_c2f\n"
".type PMPI_Type_c2f,@function\n"
".text\n"
"PMPI_Type_c2f:\n"
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
"jmp *A__MPI_Type_c2f@GOTPCREL(%rip)\n"
"inwrap_MPI_Type_c2f:\n"
"jmp *R__MPI_Type_c2f@GOTPCREL(%rip)\n"
".size PMPI_Type_c2f,.-PMPI_Type_c2f\n"

);

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
}


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
return op;
}


__asm__(
".global PMPI_Comm_f2c\n"
".weak MPI_Comm_f2c\n"
".set MPI_Comm_f2c,PMPI_Comm_f2c\n"
".extern in_w\n"
".extern A_MPI_Comm_f2c\n"
".extern R_MPI_Comm_f2c\n"
".type PMPI_Comm_f2c,@function\n"
".text\n"
"PMPI_Comm_f2c:\n"
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
"jmp *A__MPI_Comm_f2c@GOTPCREL(%rip)\n"
"inwrap_MPI_Comm_f2c:\n"
"jmp *R__MPI_Comm_f2c@GOTPCREL(%rip)\n"
".size PMPI_Comm_f2c,.-PMPI_Comm_f2c\n"

);

A_MPI_Comm A__MPI_Comm_f2c(A_MPI_Fint op)
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


R_MPI_Comm R__MPI_Comm_f2c(R_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : R_MPI_Comm_f2c\n");
#endif
#ifdef DEBUG
printf("sort : R_MPI_Comm_f2c\n");
#endif
return op;
}


__asm__(
".global PMPI_Comm_c2f\n"
".weak MPI_Comm_c2f\n"
".set MPI_Comm_c2f,PMPI_Comm_c2f\n"
".extern in_w\n"
".extern A_MPI_Comm_c2f\n"
".extern R_MPI_Comm_c2f\n"
".type PMPI_Comm_c2f,@function\n"
".text\n"
"PMPI_Comm_c2f:\n"
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
"jmp *A__MPI_Comm_c2f@GOTPCREL(%rip)\n"
"inwrap_MPI_Comm_c2f:\n"
"jmp *R__MPI_Comm_c2f@GOTPCREL(%rip)\n"
".size PMPI_Comm_c2f,.-PMPI_Comm_c2f\n"

);

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
}


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
return op;
}


__asm__(
".global PMPI_Win_f2c\n"
".weak MPI_Win_f2c\n"
".set MPI_Win_f2c,PMPI_Win_f2c\n"
".extern in_w\n"
".extern A_MPI_Win_f2c\n"
".extern R_MPI_Win_f2c\n"
".type PMPI_Win_f2c,@function\n"
".text\n"
"PMPI_Win_f2c:\n"
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
"jmp *A__MPI_Win_f2c@GOTPCREL(%rip)\n"
"inwrap_MPI_Win_f2c:\n"
"jmp *R__MPI_Win_f2c@GOTPCREL(%rip)\n"
".size PMPI_Win_f2c,.-PMPI_Win_f2c\n"

);

A_MPI_Win A__MPI_Win_f2c(A_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : A_MPI_Win_f2c\n");
#endif
in_w=1;
A_MPI_Win op_ret;
int op_tmp;
fwin_a2r(&op,&op_tmp);
win_conv_r2a(&op_ret,&op_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Win_f2c\n");
#endif
return op_ret;
}


R_MPI_Win R__MPI_Win_f2c(R_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : R_MPI_Win_f2c\n");
#endif
#ifdef DEBUG
printf("sort : R_MPI_Win_f2c\n");
#endif
return op;
}


__asm__(
".global PMPI_Win_c2f\n"
".weak MPI_Win_c2f\n"
".set MPI_Win_c2f,PMPI_Win_c2f\n"
".extern in_w\n"
".extern A_MPI_Win_c2f\n"
".extern R_MPI_Win_c2f\n"
".type PMPI_Win_c2f,@function\n"
".text\n"
"PMPI_Win_c2f:\n"
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
"jmp *A__MPI_Win_c2f@GOTPCREL(%rip)\n"
"inwrap_MPI_Win_c2f:\n"
"jmp *R__MPI_Win_c2f@GOTPCREL(%rip)\n"
".size PMPI_Win_c2f,.-PMPI_Win_c2f\n"

);

int A__MPI_Win_c2f(A_MPI_Win op)
{
#ifdef DEBUG
printf("entre : A_MPI_Win_c2f\n");
#endif
in_w=1;
int ret;
R_MPI_Win op_tmp;
win_conv_a2r(&op,&op_tmp);
fwin_r2a(&ret,&op_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Win_c2f\n");
#endif
return ret;
}


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
return op;
}


__asm__(
".global PMPI_Message_f2c\n"
".weak MPI_Message_f2c\n"
".set MPI_Message_f2c,PMPI_Message_f2c\n"
".extern in_w\n"
".extern A_MPI_Message_f2c\n"
".extern R_MPI_Message_f2c\n"
".type PMPI_Message_f2c,@function\n"
".text\n"
"PMPI_Message_f2c:\n"
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
"jmp *A__MPI_Message_f2c@GOTPCREL(%rip)\n"
"inwrap_MPI_Message_f2c:\n"
"jmp *R__MPI_Message_f2c@GOTPCREL(%rip)\n"
".size PMPI_Message_f2c,.-PMPI_Message_f2c\n"

);

A_MPI_Message A__MPI_Message_f2c(A_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : A_MPI_Message_f2c\n");
#endif
in_w=1;
A_MPI_Message op_ret;
int op_tmp;
message_a2r(&op,&op_tmp);
message_conv_r2a(&op_ret,&op_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Message_f2c\n");
#endif
return op_ret;
}


R_MPI_Message R__MPI_Message_f2c(R_MPI_Fint op)
{
#ifdef DEBUG
printf("entre : R_MPI_Message_f2c\n");
#endif
#ifdef DEBUG
printf("sort : R_MPI_Message_f2c\n");
#endif
return op;
}


__asm__(
".global PMPI_Message_c2f\n"
".weak MPI_Message_c2f\n"
".set MPI_Message_c2f,PMPI_Message_c2f\n"
".extern in_w\n"
".extern A_MPI_Message_c2f\n"
".extern R_MPI_Message_c2f\n"
".type PMPI_Message_c2f,@function\n"
".text\n"
"PMPI_Message_c2f:\n"
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
"jmp *A__MPI_Message_c2f@GOTPCREL(%rip)\n"
"inwrap_MPI_Message_c2f:\n"
"jmp *R__MPI_Message_c2f@GOTPCREL(%rip)\n"
".size PMPI_Message_c2f,.-PMPI_Message_c2f\n"

);

int A__MPI_Message_c2f(A_MPI_Message op)
{
#ifdef DEBUG
printf("entre : A_MPI_Message_c2f\n");
#endif
in_w=1;
int ret;
R_MPI_Message op_tmp;
message_conv_a2r(&op,&op_tmp);
message_r2a(&ret,&op_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Message_c2f\n");
#endif
return ret;
}


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
return op;
}
int (*LOCAL_MPI_Status_f2c)(R_MPI_Fint*,R_MPI_Status*);
int (*LOCAL_MPI_Status_c2f)(R_MPI_Status* ,R_MPI_Fint*);

__attribute__((constructor)) void wrapper_init_c2ff2c(void) {
void *lib_handle_c2ff2c=dlopen(getenv("WI4MPI_RUN_MPI_C_LIB"),RTLD_NOW|RTLD_GLOBAL);
LOCAL_MPI_File_f2c=dlsym(lib_handle_c2ff2c,"PMPI_File_f2c");
LOCAL_MPI_File_c2f=dlsym(lib_handle_c2ff2c,"PMPI_File_c2f");
LOCAL_MPI_Info_f2c=dlsym(lib_handle_c2ff2c,"PMPI_Info_f2c");
LOCAL_MPI_Info_c2f=dlsym(lib_handle_c2ff2c,"PMPI_Info_c2f");

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
"jmp *A__MPI_Status_c2f@GOTPCREL(%rip)\n"
"inwrap_MPI_Status_c2f:\n"
"jmp *R__MPI_Status_c2f@GOTPCREL(%rip)\n"

);
int A__MPI_Status_c2f(A_MPI_Status *in, A_MPI_Fint *op)
{ 
#ifdef DEBUG
printf("entre : A_MPI_Status_c2f\n");
#endif
in_w=1;
int tmp[R_f_MPI_STATUS_SIZE];
R_MPI_Status ltmp;
R_MPI_Status* tmp2=&ltmp;
status_prt_conv_a2r(&in,&tmp2);
int ret=LOCAL_MPI_Status_c2f(tmp2,tmp);
status_r2a(tmp,op);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Status_c2f\n");
#endif
return ret;
}
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
".global MPI_Status_f2c\n"
".weak MPI_Status_f2c\n"
".set MPI_Status_f2c,CCMPI_Status_f2c\n"
".extern in_w\n"
".extern A_MPI_Status_f2c\n"
".extern R_MPI_Status_f2c\n"
".type MPI_Status_f2c,@function\n"
".text\n"
"MPI_Status_f2c:\n"
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
"jmp *A__MPI_Status_f2c@GOTPCREL(%rip)\n"
"inwrap_MPI_Status_f2c:\n"
"jmp *R__MPI_Status_f2c@GOTPCREL(%rip)\n"

);
int A__MPI_Status_f2c(A_MPI_Fint *in,A_MPI_Status *op)
{
#ifdef DEBUG
printf("entre : A_MPI_Status_f2c\n");
#endif
in_w=1;
int tmp[R_f_MPI_STATUS_SIZE];
R_MPI_Status tmp2;
//status_prt_conv_r2a
status_a2r(in,tmp);
int ret=LOCAL_MPI_Status_f2c(tmp,&tmp2);
status_tab_conv_r2a(op,&tmp2);
in_w=0;
#ifdef DEBUG
printf("sort : A_MPI_Status_f2c\n");
#endif
return ret;
}
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

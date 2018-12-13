#!/usr/bin/python

############################# Wi4MPI License ###########################
# `04/04/2016`                                                         #
# Copyright or (C) or Copr. Commissariat a l'Energie Atomique          #
#                                                                      #
# IDDN.FR.001.210022.000.S.P.2014.000.10800                            #
# This file is part of the Wi4MPI library.                             #
#                                                                      #
# This software is governed by the CeCILL-C license under French law   #
# and abiding by the rules of distribution of free software. You can   #
# use, modify and/ or redistribute the software under the terms of     #
# the CeCILL-C license as circulated by CEA, CNRS and INRIA at the     #
# following URL http://www.cecill.info.                                #
#                                                                      #
# The fact that you are presently reading this means that you have     #
# had knowledge of the CeCILL-C license and that you accept its        #
# terms.                                                               #
#                                                                      #
# Authors:                                                             #
#   - Delforge Tony <tony.delforge.tgcc@cea.fr>                        #
#   - Ducrot Vincent <vincent.ducrot.tgcc@cea.fr>                      #
#                                                                      #
######################################################################## 



import json
import os , sys


def generate_func_asmK_tls(func_name, nargs):
            count_hexa=0
            nb_args = nargs
            str_reg=''
            str=''
            str=str+'__asm__(\n'
            str=str+'\".global P'+func_name+'\\n\"\n'
            str=str+'\".weak '+func_name+'\\n\"\n'
            str=str+'\".set '+func_name+',P'+func_name+'\\n\"\n'
            str=str+'\".extern in_w\\n\"\n'
            str=str+'\".extern A_'+func_name+'\\n\"\n'
            str=str+'\".extern R_'+func_name+'\\n\"\n'
            str=str+'\".type P'+func_name+',@function\\n\"\n'
            str=str+'\".text\\n\"\n'
            str=str+'\"P'+func_name+':\\n\"\n'
            # generate AARCH64 code
            str=str+'#ifdef __aarch64__\n'
            str=str+'\"adrp x8, :gottprel:in_w\\n\"\n'
            str=str+'\"ldr x8, [x8, :gottprel_lo12:in_w]\\n\"\n'
            str=str+'\"mrs x9, TPIDR_EL0\\n\"\n'
            str=str+'\"ldr w8, [x9, x8]\\n\"\n'
            str=str+'\"cbnz w8, inwrap_'+func_name+'\\n\"\n'
            str=str+'\"b A_'+func_name+'\\n\"\n'
            str=str+'\"inwrap_'+func_name+':\\n\"\n'
            str=str+'\"b R_'+func_name+'\\n\"\n'
            str=str+'#else\n'
            # generate x86_64
            for i in range(nb_args):
                  if i < 6:
                        count_hexa=count_hexa+8
                        #print 'count_hexa '+count_hexa.__str__()
            #if count_hexa % 32 != <0: #16 without __m256 | 32 with __m256
            while count_hexa % 16 != 0: #16 without __m256 | 32 with __m256
                  count_hexa=count_hexa+8
            str=str+'\"push %rbp\\n\"\n'
            str=str+'\"mov %rsp, %rbp\\n\"\n'
            str=str+'\"sub $'+count_hexa.__hex__()+', %rsp\\n\"\n'
            count_hexa=0
            for i in range(nb_args):
                  if i < 6:
                        count_hexa=count_hexa+8
                        if i == 0:
                              str_reg='%rdi'
                        elif i == 1:
                              str_reg='%rsi'
                        elif i == 2:
                              str_reg='%rdx'
                        elif i == 3:
                              str_reg='%rcx'
                        elif i == 4:
                              str_reg='%r8'
                        elif i == 5:
                              str_reg='%r9'
                        str=str+'\"mov '+str_reg+', -'+count_hexa.__hex__()+'(%rbp)\\n\"\n'
            str=str+'\".byte 0x66\\n\"\n'
            str=str+'\"leaq in_w@tlsgd(%rip), %rdi\\n\"\n'
            str=str+'\".value 0x6666\\n\"\n'
            str=str+'\"rex64\\n\"\n'
            str=str+'\"call __tls_get_addr@PLT\\n\"\n'
            count_hexa=0
            for i in range(nb_args):
                  if i < 6:
                        count_hexa=count_hexa+8
                        if i == 0:
                              str_reg='%rdi'
                        elif i == 1:
                              str_reg='%rsi'
                        elif i == 2:
                              str_reg='%rdx'
                        elif i == 3:
                              str_reg='%rcx'
                        elif i == 4:
                              str_reg='%r8'
                        elif i == 5:
                              str_reg='%r9'
                        str=str+'\"mov -'+count_hexa.__hex__()+'(%rbp), '+str_reg+'\\n\"\n'
            str=str+'\"leave\\n\"\n'
            str=str+'\"cmpl $0x0, 0x0(%rax)\\n\"\n'
            str=str+'\"jne inwrap_'+func_name+'\\n\"\n'
            str=str+'\"jmp *A_'+func_name+'@GOTPCREL(%rip)\\n\"\n'
            str=str+'\"inwrap_'+func_name+':\\n\"\n'
            str=str+'\"jmp *R_'+func_name+'@GOTPCREL(%rip)\\n\"\n'
            str=str+'#endif\n'
            str=str+'\".size P'+func_name+',.-P'+func_name+'\\n\"\n'
            str=str+'\n);\n'
            return str


def generate_func_asmK_tls_updated_for_interface(func_name, nargs):
            count_hexa=0
            nb_args = nargs
            str_reg=''
            str=''
            str=str+'__asm__(\n'
            str=str+'\".global CC'+func_name+'\\n\"\n'
            str=str+'\".weak '+func_name+'\\n\"\n'
            str=str+'\".set '+func_name+',CC'+func_name+'\\n\"\n'
            str=str+'\".extern in_w\\n\"\n'
            str=str+'\".extern A_'+func_name+'\\n\"\n'
            str=str+'\".extern R_'+func_name+'\\n\"\n'
            str=str+'\".type CC'+func_name+',@function\\n\"\n'
            str=str+'\".text\\n\"\n'
            str=str+'\"CC'+func_name+':\\n\"\n'
            # generate AARCH64 code
            str=str+'#ifdef __aarch64__\n'
            str=str+'\"adrp x8, :gottprel:in_w\\n\"\n'
            str=str+'\"ldr x8, [x8, :gottprel_lo12:in_w]\\n\"\n'
            str=str+'\"mrs x9, TPIDR_EL0\\n\"\n'
            str=str+'\"ldr w8, [x9, x8]\\n\"\n'
            str=str+'\"cbnz w8, inwrap_'+func_name+'\\n\"\n'
            str=str+'\"b A_'+func_name+'\\n\"\n'
            str=str+'\"inwrap_'+func_name+':\\n\"\n'
            str=str+'\"b R_'+func_name+'\\n\"\n'
            str=str+'#else\n'
            # generate x86_64
            for i in range(nb_args):
                  if i < 6:
                        count_hexa=count_hexa+8
                        #print 'count_hexa '+count_hexa.__str__()
            #if count_hexa % 32 != <0: #16 without __m256 | 32 with __m256
            while count_hexa % 16 != 0: #16 without __m256 | 32 with __m256
                  count_hexa=count_hexa+8
            str=str+'\"push %rbp\\n\"\n'
            str=str+'\"mov %rsp, %rbp\\n\"\n'
            str=str+'\"sub $'+count_hexa.__hex__()+', %rsp\\n\"\n'
            count_hexa=0
            for i in range(nb_args):
                  if i < 6:
                        count_hexa=count_hexa+8
                        if i == 0:
                              str_reg='%rdi'
                        elif i == 1:
                              str_reg='%rsi'
                        elif i == 2:
                              str_reg='%rdx'
                        elif i == 3:
                              str_reg='%rcx'
                        elif i == 4:
                              str_reg='%r8'
                        elif i == 5:
                              str_reg='%r9'
                        str=str+'\"mov '+str_reg+', -'+count_hexa.__hex__()+'(%rbp)\\n\"\n'
            str=str+'\".byte 0x66\\n\"\n'
            str=str+'\"leaq in_w@tlsgd(%rip), %rdi\\n\"\n'
            str=str+'\".value 0x6666\\n\"\n'
            str=str+'\"rex64\\n\"\n'
            str=str+'\"call __tls_get_addr@PLT\\n\"\n'
            count_hexa=0
            for i in range(nb_args):
                  if i < 6:
                        count_hexa=count_hexa+8
                        if i == 0:
                              str_reg='%rdi'
                        elif i == 1:
                              str_reg='%rsi'
                        elif i == 2:
                              str_reg='%rdx'
                        elif i == 3:
                              str_reg='%rcx'
                        elif i == 4:
                              str_reg='%r8'
                        elif i == 5:
                              str_reg='%r9'
                        str=str+'\"mov -'+count_hexa.__hex__()+'(%rbp), '+str_reg+'\\n\"\n'
            str=str+'\"leave\\n\"\n'
            str=str+'\"cmpl $0x0, 0x0(%rax)\\n\"\n'
            str=str+'\"jne inwrap_'+func_name+'\\n\"\n'
            str=str+'\"jmp *A_'+func_name+'@GOTPCREL(%rip)\\n\"\n'
            str=str+'\"inwrap_'+func_name+':\\n\"\n'
            str=str+'\"jmp *R_'+func_name+'@GOTPCREL(%rip)\\n\"\n'
            str=str+'#endif\n'
            #str=str+'\".size P'+func_name+',.-P'+func_name+'\\n\"\n'
            str=str+'\n);\n'
            return str




def generate_func_asmK_tls_(func_name, nargs):
            count_hexa=0
            nb_args = nargs
            str_reg=''
            str=''
            str=str+'__asm__(\n'
            str=str+'\".global P'+func_name+'\\n\"\n'
            str=str+'\".weak '+func_name+'\\n\"\n'
            str=str+'\".set '+func_name+',P'+func_name+'\\n\"\n'
            str=str+'\".extern in_w\\n\"\n'
            str=str+'\".extern A_'+func_name+'\\n\"\n'
            str=str+'\".extern R_'+func_name+'\\n\"\n'
            str=str+'\".type P'+func_name+',@function\\n\"\n'
            str=str+'\".text\\n\"\n'
            str=str+'\"P'+func_name+':\\n\"\n'
            # generate AARCH64 code
            str=str+'#ifdef __aarch64__\n'
            str=str+'\"adrp x8, :gottprel:in_w\\n\"\n'
            str=str+'\"ldr x8, [x8, :gottprel_lo12:in_w]\\n\"\n'
            str=str+'\"mrs x9, TPIDR_EL0\\n\"\n'
            str=str+'\"ldr w8, [x9, x8]\\n\"\n'
            str=str+'\"cbnz w8, inwrap_'+func_name+'\\n\"\n'
            str=str+'\"b A_'+func_name+'\\n\"\n'
            str=str+'\"inwrap_'+func_name+':\\n\"\n'
            str=str+'\"b R_'+func_name+'\\n\"\n'
            str=str+'#else\n'
            # generate x86_64
            for i in range(nb_args):
                  if i < 6:
                        count_hexa=count_hexa+8
                        #print 'count_hexa '+count_hexa.__str__()
            #if count_hexa % 32 != <0: #16 without __m256 | 32 with __m256
            while count_hexa % 16 != 0: #16 without __m256 | 32 with __m256
                  count_hexa=count_hexa+8
            str=str+'\"push %rbp\\n\"\n'
            str=str+'\"mov %rsp, %rbp\\n\"\n'
            str=str+'\"sub $'+count_hexa.__hex__()+', %rsp\\n\"\n'
            count_hexa=0
            for i in range(nb_args):
                  if i < 6:
                        count_hexa=count_hexa+8
                        if i == 0:
                              str_reg='%rdi'
                        elif i == 1:
                              str_reg='%rsi'
                        elif i == 2:
                              str_reg='%rdx'
                        elif i == 3:
                              str_reg='%rcx'
                        elif i == 4:
                              str_reg='%r8'
                        elif i == 5:
                              str_reg='%r9'
                        str=str+'\"mov '+str_reg+', -'+count_hexa.__hex__()+'(%rbp)\\n\"\n'
            str=str+'\".byte 0x66\\n\"\n'
            str=str+'\"leaq in_w@tlsgd(%rip), %rdi\\n\"\n'
            str=str+'\".value 0x6666\\n\"\n'
            str=str+'\"rex64\\n\"\n'
            str=str+'\"call __tls_get_addr@PLT\\n\"\n'
            count_hexa=0
            for i in range(nb_args):
                  if i < 6:
                        count_hexa=count_hexa+8
                        if i == 0:
                              str_reg='%rdi'
                        elif i == 1:
                              str_reg='%rsi'
                        elif i == 2:
                              str_reg='%rdx'
                        elif i == 3:
                              str_reg='%rcx'
                        elif i == 4:
                              str_reg='%r8'
                        elif i == 5:
                              str_reg='%r9'
                        str=str+'\"mov -'+count_hexa.__hex__()+'(%rbp), '+str_reg+'\\n\"\n'
            str=str+'\"leave\\n\"\n'
            str=str+'\"cmpl $0x0, 0x0(%rax)\\n\"\n'
            str=str+'\"jne inwrap_'+func_name+'\\n\"\n'
            str=str+'\"jmp *A__'+func_name+'@GOTPCREL(%rip)\\n\"\n'
            str=str+'\"inwrap_'+func_name+':\\n\"\n'
            str=str+'\"jmp *R__'+func_name+'@GOTPCREL(%rip)\\n\"\n'
            str=str+'#endif\n'
            str=str+'\".size P'+func_name+',.-P'+func_name+'\\n\"\n'
            str=str+'\n);\n'
            return str

def generate_func_asmK_tls_updated_for_interface_(func_name, nargs):
            count_hexa=0
            nb_args = nargs
            str_reg=''
            str=''
            str=str+'__asm__(\n'
            str=str+'\".global CC'+func_name+'\\n\"\n'
            str=str+'\".weak '+func_name+'\\n\"\n'
            str=str+'\".set '+func_name+',CC'+func_name+'\\n\"\n'
            str=str+'\".extern in_w\\n\"\n'
            str=str+'\".extern A_'+func_name+'\\n\"\n'
            str=str+'\".extern R_'+func_name+'\\n\"\n'
            str=str+'\".type CC'+func_name+',@function\\n\"\n'
            str=str+'\".text\\n\"\n'
            str=str+'\"CC'+func_name+':\\n\"\n'
            # generate AARCH64 code
            str=str+'#ifdef __aarch64__\n'
            str=str+'\"adrp x8, :gottprel:in_w\\n\"\n'
            str=str+'\"ldr x8, [x8, :gottprel_lo12:in_w]\\n\"\n'
            str=str+'\"mrs x9, TPIDR_EL0\\n\"\n'
            str=str+'\"ldr w8, [x9, x8]\\n\"\n'
            str=str+'\"cbnz w8, inwrap_'+func_name+'\\n\"\n'
            str=str+'\"b A_'+func_name+'\\n\"\n'
            str=str+'\"inwrap_'+func_name+':\\n\"\n'
            str=str+'\"b R_'+func_name+'\\n\"\n'
            str=str+'#else\n'
            # generate x86_64
            for i in range(nb_args):
                  if i < 6:
                        count_hexa=count_hexa+8
                        #print 'count_hexa '+count_hexa.__str__()
            #if count_hexa % 32 != <0: #16 without __m256 | 32 with __m256
            while count_hexa % 16 != 0: #16 without __m256 | 32 with __m256
                  count_hexa=count_hexa+8
            str=str+'\"push %rbp\\n\"\n'
            str=str+'\"mov %rsp, %rbp\\n\"\n'
            str=str+'\"sub $'+count_hexa.__hex__()+', %rsp\\n\"\n'
            count_hexa=0
            for i in range(nb_args):
                  if i < 6:
                        count_hexa=count_hexa+8
                        if i == 0:
                              str_reg='%rdi'
                        elif i == 1:
                              str_reg='%rsi'
                        elif i == 2:
                              str_reg='%rdx'
                        elif i == 3:
                              str_reg='%rcx'
                        elif i == 4:
                              str_reg='%r8'
                        elif i == 5:
                              str_reg='%r9'
                        str=str+'\"mov '+str_reg+', -'+count_hexa.__hex__()+'(%rbp)\\n\"\n'
            str=str+'\".byte 0x66\\n\"\n'
            str=str+'\"leaq in_w@tlsgd(%rip), %rdi\\n\"\n'
            str=str+'\".value 0x6666\\n\"\n'
            str=str+'\"rex64\\n\"\n'
            str=str+'\"call __tls_get_addr@PLT\\n\"\n'
            count_hexa=0
            for i in range(nb_args):
                  if i < 6:
                        count_hexa=count_hexa+8
                        if i == 0:
                              str_reg='%rdi'
                        elif i == 1:
                              str_reg='%rsi'
                        elif i == 2:
                              str_reg='%rdx'
                        elif i == 3:
                              str_reg='%rcx'
                        elif i == 4:
                              str_reg='%r8'
                        elif i == 5:
                              str_reg='%r9'
                        str=str+'\"mov -'+count_hexa.__hex__()+'(%rbp), '+str_reg+'\\n\"\n'
            str=str+'\"leave\\n\"\n'
            str=str+'\"cmpl $0x0, 0x0(%rax)\\n\"\n'
            str=str+'\"jne inwrap_'+func_name+'\\n\"\n'
            str=str+'\"jmp *A__'+func_name+'@GOTPCREL(%rip)\\n\"\n'
            str=str+'\"inwrap_'+func_name+':\\n\"\n'
            str=str+'\"jmp *R__'+func_name+'@GOTPCREL(%rip)\\n\"\n'
            str=str+'#endif\n'
            #str=str+'\".size P'+func_name+',.-P'+func_name+'\\n\"\n'
            str=str+'\n);\n'
            return str

with open('./C/mappers.json') as mapper_file:
   mappers=json.load(mapper_file)
with open('./FORTRAN/mappers_f.json') as mapper_file_f:
   mappers_f=json.load(mapper_file_f)
ompi_const=open('./C/ompi_const_set.txt','r')


interface=''                                                 
preload=''                                                   
                                                             
if len(sys.argv) < 2:                                        
   print 'Version needeed: (PRELOAD | INTERFACE)'
else:                                                        
   if sys.argv[1] == 'INTERFACE':
      #print 'INTERFACE'                              
      interface='true'                                         
   elif sys.argv[1] == 'PRELOAD':
      #print 'PRELOAD'
      preload='true'                                               


   c2ff2c=["MPI_File","MPI_Op","MPI_Info","MPI_Group","MPI_Request","MPI_Type","MPI_Comm","MPI_Win","MPI_Message","MPI_Errhandler"] #"MPI_Errhandler", 
   list_F=["file_converter","op_converter","Info_converter","group_converter","Request_ptr_converter","Datatype_converter","Comm_str_converter","win_converter","message_ptr_converter","errhandler_mapper"] #"errhandler_mapper",
   count=0
   func_name=""
   
   print '//############################# Wi4MPI License ###########################' 
   print '//# `04/04/2016`                                                         #'
   print '//# Copyright or (C) or Copr. Commissariat a l\'Energie Atomique          #'
   print '//#                                                                      #'
   print '//# IDDN.FR.001.210022.000.S.P.2014.000.10800                            #'
   print '//# This file is part of the Wi4MPI library.                             #'
   print '//#                                                                      #'
   print '//# This software is governed by the CeCILL-C license under French law   #'
   print '//# and abiding by the rules of distribution of free software. You can   #'
   print '//# use, modify and/ or redistribute the software under the terms of     #'
   print '//# the CeCILL-C license as circulated by CEA, CNRS and INRIA at the     #'
   print '//# following URL http://www.cecill.info.                                #'
   print '//#                                                                      #'
   print '//# The fact that you are presently reading this means that you have     #'
   print '//# had knowledge of the CeCILL-C license and that you accept its        #'
   print '//# terms.                                                               #'
   print '//#                                                                      #'
   print '//# Authors:                                                             #'
   print '//#   - Delforge Tony <tony.delforge.tgcc@cea.fr>                        #'
   print '//#   - Ducrot Vincent <vincent.ducrot.tgcc@cea.fr>                      #'
   print '//#                                                                      #'
   print '//########################################################################'
   
   
   print '#if defined(INTEL_OMPI) || defined (OMPI_OMPI)'
   print '#define _GNU_SOURCE'
   print '#include <stdio.h>'
   print '#include <dlfcn.h>'
   
   
   print "#include \"mappers.h\"" 
   
   print "extern __thread int in_w;"
   
   for i in c2ff2c :
      for j in mappers:
         if len(j.split('const')) == 1:
            if mappers[j]['type'] == i:
              C_a2r=mappers[j]['a2r']
              C_r2a=mappers[j]['r2a']
            elif i == 'MPI_Type':
              C_a2r='datatype_conv_a2r'
              C_r2a='datatype_conv_r2a'
            elif i == 'MPI_Request':
              C_a2r='request_tab_conv_a2r'
              C_r2a='request_tab_conv_r2a'
            elif i == 'MPI_Errhandler':
              C_r2a='errhandler_comm_ptr_conv_r2a'
      
      for k in mappers_f:
         if len(k.split('const')) == 1:
            if k == list_F[count]:
              F_a2r=mappers_f[k]['a2r']
              F_r2a=mappers_f[k]['r2a']
              break
            else:
              F_a2r="undef"
              F_r2a="undef"
   
      func_name=i+'_f2c'
      #generate code chooser_______________________________________________________
      if preload == 'true':  
         print generate_func_asmK_tls(func_name, 1)
      elif interface == 'true':
         print generate_func_asmK_tls_updated_for_interface(func_name, 1)
      #generate pointeur LOCAL_____________________________________________________
      if i == 'MPI_Type':
         print 'R_MPI_Datatype (*LOCAL_'+i+'_f2c)(R_MPI_Fint);'
      else:
         print 'R_'+i+' (*LOCAL_'+i+'_f2c)(R_MPI_Fint);'
      #generate A_f2c______________________________________________________________
      if i == 'MPI_Type':
         print 'A_MPI_Datatype A_'+i+'_f2c(A_MPI_Fint op)'
      else:
         print 'A_'+i+' A_'+i+'_f2c(A_MPI_Fint op)'
      print '{'
      print '#ifdef DEBUG'
      print 'printf(\"entre : A_'+i+'_f2c\\n\");'
      print '#endif'
      print 'in_w=1;'
      if i == 'MPI_Type':
         print 'A_MPI_Datatype ret;'
      else:
         print 'A_'+i+' ret;'
      if i != 'MPI_File' and i != 'MPI_Type':
         print 'R_MPI_Fint op_tmp;'
         print F_a2r+'(&op,&op_tmp);'
         print 'R_'+i+' ret_tmp=LOCAL_'+i+'_f2c(op_tmp);'
      elif i == 'MPI_Type':
         print 'R_MPI_Fint op_tmp;'
         print F_a2r+'(&op,&op_tmp);'
         print 'R_MPI_Datatype ret_tmp=LOCAL_'+i+'_f2c(op_tmp);'
      else:
         print 'R_'+i+' ret_tmp=LOCAL_'+i+'_f2c(op);'
      print C_r2a+'(&ret,&ret_tmp);'
      print 'in_w=0;'
      print '#ifdef DEBUG'
      print 'printf(\"sort : A_'+i+'_f2c\\n\");'
      print '#endif'
      print 'return ret;'
      print '}'
      print '\n'
      #generate R_f2c______________________________________________________________
      if i == 'MPI_Type':
         print 'R_MPI_Datatype R_'+i+'_f2c(R_MPI_Fint op)'
      else:
         print 'R_'+i+' R_'+i+'_f2c(R_MPI_Fint op)'
      print '{'
      print '#ifdef DEBUG'
      print 'printf(\"entre : R_'+i+'_f2c\\n\");'
      print '#endif'
      if i == 'MPI_Type':
         print 'R_MPI_Datatype ret=LOCAL_'+i+'_f2c(op);'
      else:
         print 'R_'+i+' ret=LOCAL_'+i+'_f2c(op);'
      print '#ifdef DEBUG'
      print 'printf(\"sort : R_'+i+'_f2c\\n\");'
      print '#endif'
      print 'return ret;'
      print '}'
      print '\n'
   
      func_name=i+'_c2f'
      #generate code chooser_______________________________________________________
      if preload == 'true':
         print generate_func_asmK_tls(func_name, 1)
      elif interface == 'true':
         print generate_func_asmK_tls_updated_for_interface(func_name, 1)
      #generate pointeur LOCAL_____________________________________________________
      if i == 'MPI_Type':
         print 'R_MPI_Fint (*LOCAL_'+i+'_c2f)(R_MPI_Datatype);'
      else :
         print 'R_MPI_Fint (*LOCAL_'+i+'_c2f)(R_'+i+');'
      #generate A_c2f______________________________________________________________
      if i == 'MPI_Type':
         print 'A_MPI_Fint A_'+i+'_c2f(A_MPI_Datatype op)'
      else:
         print 'A_MPI_Fint A_'+i+'_c2f(A_'+i+' op)'
      print '{'
      print '#ifdef DEBUG'
      print 'printf(\"entre : A_'+i+'_c2f\\n\");'
      print '#endif'
      print 'in_w=1;'
      print 'A_MPI_Fint ret;'
      if i == 'MPI_Type':
         print 'R_MPI_Datatype op_tmp;'
      else:
         print 'R_'+i+' op_tmp;'
      print C_a2r+'(&op,&op_tmp);'
      if i != 'MPI_File':
         print 'R_MPI_Fint ret_tmp=LOCAL_'+i+'_c2f(op_tmp);'
         print F_r2a+'(&ret,&ret_tmp);'
      else :
         print 'ret=LOCAL_'+i+'_c2f(op_tmp);'
      print 'in_w=0;'
      print '#ifdef DEBUG'
      print 'printf(\"sort : A_'+i+'_c2f\\n\");'
      print '#endif'
      print 'return ret;'
      print '}'
      print '\n'
      #generate R_c2f______________________________________________________________
      if i == 'MPI_Type':
         print 'R_MPI_Fint R_'+i+'_c2f(R_MPI_Datatype op)'
      else:
         print 'R_MPI_Fint R_'+i+'_c2f(R_'+i+' op)'
      print '{'
      print '#ifdef DEBUG'
      print 'printf(\"entre : R_'+i+'_c2f\\n\");'
      print '#endif'
      print 'in_w=1;'
      print 'R_MPI_Fint ret=LOCAL_'+i+'_c2f(op);'
      print 'in_w=0;'
      print '#ifdef DEBUG'
      print 'printf(\"sort : R_'+i+'_c2f\\n\");'
      print '#endif'
      print 'return ret;'
      print '}'
      print '\n'
   
      count=count+1
   
   count = 0
   print '__attribute__((constructor)) void wrapper_init_c2ff2c(void) {'
   print 'void *lib_handle_c2ff2c=dlopen(getenv(\"WI4MPI_RUN_MPI_C_LIB\"),RTLD_NOW|RTLD_GLOBAL);'
   for i in c2ff2c:
      print 'LOCAL_'+i+'_f2c=dlsym(lib_handle_c2ff2c,\"P'+i+'_f2c\");' 
      print 'LOCAL_'+i+'_c2f=dlsym(lib_handle_c2ff2c,\"P'+i+'_c2f\");' 
   print '}'
   print '#elif defined(OMPI_INTEL)'
   print '#define _GNU_SOURCE' 
   print '#include <stdio.h>'
   print '#include <dlfcn.h>'

   for i in ompi_const:
      print i.split('\n')[0]
   print "#include \"mappers.h\"" 
   print "extern __thread int in_w;"
   for i in c2ff2c :
      for j in mappers:
         if len(j.split('const')) == 1:
            if mappers[j]['type'] == i:
              C_a2r=mappers[j]['a2r']
              C_r2a=mappers[j]['r2a']
            elif i == 'MPI_Type':
              C_a2r='datatype_conv_a2r'
              C_r2a='datatype_conv_r2a'
            elif i == 'MPI_Request':
              C_a2r='request_tab_conv_a2r'
              C_r2a='request_tab_conv_r2a'
            elif i == 'MPI_Errhandler':
              C_r2a='errhandler_comm_ptr_conv_r2a'
      
      for k in mappers_f:
         if len(k.split('const')) == 1:
            if k == list_F[count]:
              F_a2r=mappers_f[k]['a2r']
              F_r2a=mappers_f[k]['r2a']
              break
            else:
              F_a2r="undef"
              F_r2a="undef"
   
      func_name=i+'_f2c'
      #generate code chooser_______________________________________________________
      if preload == 'true':
         print generate_func_asmK_tls_(func_name, 1)
      elif interface == 'true':
         print generate_func_asmK_tls_updated_for_interface_(func_name, 1)
      #generate A_f2c______________________________________________________________
      if i == 'MPI_Type':
         print 'A_MPI_Datatype A__'+i+'_f2c(A_MPI_Fint op)'
      else:
         print 'A_'+i+' A__'+i+'_f2c(A_MPI_Fint op)'
      print '{'
      print '#ifdef DEBUG'
      print 'printf(\"entre : A_'+i+'_f2c\\n\");'
      print '#endif'
      print 'in_w=1;'
      if i == 'MPI_Type':
         print 'A_MPI_Datatype op_ret;'
      else:
         print 'A_'+i+' op_ret;'
      if i != 'MPI_File' and i != 'MPI_Type':
         print 'int op_tmp;'
         print F_a2r+'(&op,&op_tmp);'
         print C_r2a+'(&op_ret,&op_tmp);'
      elif i == 'MPI_Type':
         print 'int op_tmp;'
         print F_a2r+'(&op,&op_tmp);'
         print C_r2a+'(&op_ret,&op_tmp);'
      else:
         print C_r2a+'(&op_ret,&op);'
      print 'in_w=0;'
      print '#ifdef DEBUG'
      print 'printf(\"sort : A_'+i+'_f2c\\n\");'
      print '#endif'
      print 'return op_ret;'
      print '}'
      print '\n'
      #generate R_f2c______________________________________________________________
      if i == 'MPI_Type':
         print 'R_MPI_Datatype R__'+i+'_f2c(R_MPI_Fint op)'
      else:
         print 'R_'+i+' R__'+i+'_f2c(R_MPI_Fint op)'
      print '{'
      print '#ifdef DEBUG'
      print 'printf(\"entre : R_'+i+'_f2c\\n\");'
      print '#endif'
      print '#ifdef DEBUG'
      print 'printf(\"sort : R_'+i+'_f2c\\n\");'
      print '#endif'
      print 'return op;'
      print '}'
      print '\n'
      
      func_name=i+'_c2f'
      #generate code chooser_______________________________________________________
      if preload == 'true':
         print generate_func_asmK_tls_(func_name, 1)
      elif interface == 'true':
         print generate_func_asmK_tls_updated_for_interface_(func_name, 1)
      #generate A_c2f______________________________________________________________
      if i == 'MPI_Type':
         print 'int A__'+i+'_c2f(A_MPI_Datatype op)'
      else:
         print 'int A__'+i+'_c2f(A_'+i+' op)'
      print '{'
      print '#ifdef DEBUG'
      print 'printf(\"entre : A_'+i+'_c2f\\n\");'
      print '#endif'
      print 'in_w=1;'
      print 'int ret;'
      if i == 'MPI_Type':
         print 'R_MPI_Datatype op_tmp;'
      else:
         print 'R_'+i+' op_tmp;'
      print C_a2r+'(&op,&op_tmp);'
      if i != 'MPI_File':
         print F_r2a+'(&ret,&op_tmp);'
      print 'in_w=0;'
      print '#ifdef DEBUG'
      print 'printf(\"sort : A_'+i+'_c2f\\n\");'
      print '#endif'
      if i == 'MPI_File':
         print 'return op_tmp;'
      else:
         print 'return ret;'
      print '}'
      print '\n'
      #generate R_c2f______________________________________________________________
      if i == 'MPI_Type':
         print 'int R__'+i+'_c2f(R_MPI_Datatype op)'
      else:
         print 'int R__'+i+'_c2f(R_'+i+' op)'
      print '{'
      print '#ifdef DEBUG'
      print 'printf(\"entre : R_'+i+'_c2f\\n\");'
      print '#endif'
      print 'in_w=1;'
      print 'in_w=0;'
      print '#ifdef DEBUG'
      print 'printf(\"sort : R_'+i+'_c2f\\n\");'
      print '#endif'
      print 'return op;'
      print '}'
      print '\n'
   
      count=count+1
   
   print '#endif'

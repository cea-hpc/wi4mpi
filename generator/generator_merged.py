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
import string
import os, sys
from pprint import pprint

#-----------------------------------CLASS FORTRAN--------------------------------#
class generator_f:
    def __init__(self,mapper_list):
        self.mappers=mapper_list
    def generate_func(self,func_dict,debug=False):
        #pprint(func_dict)
        str=self.print_symbol(func_dict,prefix='A_f_',name_arg=True,retval_name=False,app_side=True)
        str=str+'\n{'
        str=str+'\n#ifdef DEBUG'
        str=str+'\nprintf(\"entre : A_f_'+func_dict['name']+'\\n\");'
        str=str+'\n#endif'
        str=str+'\nin_w=1;\n'             
        str=str+self.mappers[func_dict['ret']['name']]['type']+' ret_tmp=0;\n'
        if func_dict['name'] == "MPI_Alltoallw" or func_dict['name'] == "MPI_Ialltoallw":
            str=str+'int comm_tmp1, ierr;\ncomm_a2r(comm,&comm_tmp1);\nint *Comm_size;\n_LOCAL_MPI_Comm_size(&comm_tmp1, Comm_size, &ierr);'
        elif func_dict['name'] == "MPI_Ineighbor_alltoallw" or func_dict['name'] == "MPI_Neighbor_alltoallw":
            str=str+'int comm_tmp1;\ncomm_a2r(comm,&comm_tmp1);\nint *indegree, *outdegree, *weighted, ierr;\n_LOCAL_MPI_Dist_graph_neighbors_count(&comm_tmp1, indegree,outdegree, weighted, &ierr);'
        for arg in func_dict['args']:
            if (arg['In'] or arg['Out']) and not 'nomap' in self.mappers[arg['name']]:
                str=str+'\n'+self.print_temporary_decl(arg,'R_')
        for arg in func_dict['args']:
            if arg['In'] and not 'nomap' in self.mappers[arg['name']]:
                str=str+'\n'+self.affect_temp_conv(arg)
        if debug:
            str=str+'\nprintf("'+func_dict['name']+'\\n");'      
        if 'assoc' in func_dict:
            for assoc in func_dict['assoc']:
                if  assoc['func'].find('_del')!=-1:
                    str=str+'\n'+assoc['func']+'('
                    str=str+assoc['key']
                    if 'value' in assoc:
                         str=str+','+assoc['value']
                    str=str+');'
        str=str+'\n'+self.print_symbol(func_dict,prefix='_LOCAL_',name_arg_postfix='_tmp',name_arg=True,retval_name=True,app_side=False,call=True)+';'
        if debug:
            str=str+'\nprintf("before conv '+func_dict['name']+' %d %d\\n",*ret,ret_tmp);'      
        for arg in func_dict['args']:
            if arg['Out'] and not 'nomap' in self.mappers[arg['name']] or arg['Out'] and func_dict['name'] == 'MPI_Keyval_free':
                if not 'nomap' in self.mappers[arg['name']]:
                  if func_dict['name']=='MPI_Errhandler_free':
                     str=str+'\nif(ret_tmp==R_f_MPI_SUCCESS){\n' 
                     str=str+'errhandler_f_fn_translation_del(errhandler_tmp);\n'
                     str=str+'errhandler_converter_r2a(errhandler,&errhandler_tmp);\n'
                     str=str+'}'
                  elif func_dict['name']=='MPI_Error_class':
                     str=str+'\n'+self.affect_val_conv(arg)
                  else:
                     str=str+'\nif(ret_tmp==R_f_MPI_SUCCESS)'+self.affect_val_conv(arg)
                else:
                  str=str+'\nif(ret_tmp==R_f_MPI_SUCCESS)\n'
                  str=str+'{\n'
                  str=str+'\t*keyval=A_MPI_KEYVAL_INVALID;\n'
                  str=str+'}\n'
                  
            if 'arg_dep' in arg and arg['arg_dep']!='' and (arg['In'] or arg['Out'])  and not 'nomap' in self.mappers[arg['name']]:
                if arg['var'] == 'array_of_statuses': 
                  str=str+'\nif (array_of_statuses!=A_f_MPI_STATUSES_IGNORE)'
                  str=str+'\n'+' free('+arg['var']+'_tmp);'
                else:
                  str=str+'\n'+' free('+arg['var']+'_tmp);'
        if 'assoc' in func_dict:
            for assoc in func_dict['assoc']:
                if  assoc['func'].find('_del')==-1:
                    str=str+'\n'+assoc['func']+'('
                    str=str+assoc['key']
                    if 'value' in assoc:
                        str=str+','+assoc['value']
                    str=str+');'
        str=str+'\n'+self.print_return_conv(func_dict)
        if debug:
            str=str+'\nprintf("end '+func_dict['name']+' %d %d\\n",*ret,ret_tmp);' 
        str=str+'\nin_w=0;\n'             
        str=str+'#ifdef DEBUG'
        str=str+'\nprintf(\"sort : A_f_'+func_dict['name']+'\\n\");'
        str=str+'\n#endif'
        str=str+'\n'+'}'
        return str

    def add_prefix(self,type,prefix):
        return ''
        str=type.split('MPI_')
        if len(str) > 1:
            return str[0]+prefix+'MPI_'+str[1]
        else:
            return type
    def print_symbol(self,func_dict,type_prefix='',prefix='',postfix='',name_arg=False,retval_name=False,app_side=False,name_arg_postfix='',call=False,func_ptr=False,lower=False,direct =False):
        arg_len=0; 
        if ('as_ret' in func_dict['ret'] and not retval_name):
            if app_side : 
                str=self.add_prefix(self.mappers[func_dict['ret']['name']]['type'],prefix)
            else:
                str=self.add_prefix(self.mappers[func_dict['ret']['name']]['type'],type_prefix)
        else:
            if app_side:
                str='void '
            else:
                str=''
        if retval_name :
            if 'as_ret' in self.mappers[func_dict['ret']['name']]:
                str=str+' '+'ret_tmp='
        if func_ptr:
            str=str+' (*'+prefix+func_dict['name']+postfix+')('
        else:
            if not lower:
                str=str+' '+prefix+func_dict['name']+postfix+'('
            else:
                str=str+' '+prefix+func_dict['name'].lower()+postfix+'('
        if len(func_dict['args']) !=0 :
            for arg in func_dict['args']:
                if self.mappers[arg['name']]['type']!='':
                    if call != True:
                        if app_side:
                            str=str+self.mappers[arg['name']]['type']+'*'
                        else:
                            str=str+self.mappers[arg['name']]['type']+'*'
                    if name_arg:
                        if call:
                            if (arg['In'] or arg['Out']) and not 'nomap' in self.mappers[arg['name']] and not 'array' in self.mappers[arg['name']]: 
                                if arg['arg_dep'] =='' and not 'status_size' in self.mappers[arg['name']] and self.mappers[arg['name']]['type']!= 'void ' and not direct:
                                    if arg['name'] == 'weight_converter':
                                       str=str+' '
                                    else:
                                       str=str+' &'
                                str=str+arg['var']+name_arg_postfix
                            else:
                                str=str+' '+arg['var']
                        else:
                            str=str+' '+arg['var']+name_arg_postfix
                    str=str+','
                    arg_len=arg_len+1
        
        if not ('as_ret' in self.mappers[func_dict['ret']['name']]):
                if retval_name== False and not call:
                    if app_side:
                        str=str+self.mappers[func_dict['ret']['name']]['type']+'*'
                    else:
                        str=str+self.mappers[func_dict['ret']['name']]['type']+'*'
                if name_arg:
                    if call and not direct:
                            str=str+' '+'&ret'+name_arg_postfix
                    else:
                        str=str+' '+'ret'+name_arg_postfix
                arg_len=arg_len+1
        else: 
            str=str[:-1]
        if(arg_len==0):
             if retval_name== False:
                str=str+'void'
        str=str+')'
        return str

    def print_return_conv(self,func_dict):
        str=''
        if not 'nomap' in  self.mappers[func_dict['ret']['name']]:  
            if 'as_ret' in func_dict['ret'] :
                str=self.mappers[func_dict['ret']['name']]['type'] +' '+func_dict['ret']['var']+';\n'
            str=str+ self.mappers[func_dict['ret']['name']]['r2a']+'('+func_dict['ret']['var']+',&'+func_dict['ret']['var']+'_tmp);\n'
        if 'as_ret' in func_dict['ret']:
            str=str+'return '+func_dict['ret']['var'];
        return str
    def affect_temp_conv(self,arg):
        if 'nomap' in self.mappers[arg['name']]:
            str=arg['var']+'_tmp=*'+arg['var']+';'
        else:
            if arg['arg_dep'] !='':
                mula='1'
                mulr='1'
                if 'status_size' in self.mappers[arg['name']]:
                    mula='A_f_MPI_STATUS_SIZE'
                    mulr='R_f_MPI_STATUS_SIZE'
                str= 'for(int i=0;i<*'+arg['arg_dep']+';i++)\n' + self.mappers[arg['name']]['a2r']+'(&'+arg['var']+'[i*'+mula+'],&'+arg['var']+'_tmp[i*'+mulr+']);'
            else:
                if 'status_size' in self.mappers[arg['name']]:
                    str= self.mappers[arg['name']]['a2r']+'('+arg['var']+','+arg['var']+'_tmp);'
                else:
                    if self.mappers[arg['name']]['type']!= 'void ':
                        if arg['name'] == 'weight_converter':
                           str= self.mappers[arg['name']]['a2r']+'(&'+arg['var']+',&'+arg['var']+'_tmp);'
                        else:
                           str= self.mappers[arg['name']]['a2r']+'('+arg['var']+',&'+arg['var']+'_tmp);'
                    else:
                        str= self.mappers[arg['name']]['a2r']+'(&'+arg['var']+',&'+arg['var']+'_tmp);'
        return str

    def affect_val_conv(self,arg):
        str=''
        mula='1'
        mulr='1'
        if arg['arg_dep'] !='':
            if 'status_size' in self.mappers[arg['name']]:
                mula='A_f_MPI_STATUS_SIZE'
                mulr='R_f_MPI_STATUS_SIZE'
                str='if ('+arg['var']+'!=A_f_MPI_STATUSES_IGNORE)\n'
            str=str+ 'for(int i=0;i<*'+arg['arg_dep']+';i++)\n' + self.mappers[arg['name']]['r2a']+'(&'+arg['var']+'[i*'+mula+'],&'+arg['var']+'_tmp[i*'+mulr+']);'
        else:
            if 'status_size' in self.mappers[arg['name']]:
                str=str+'if ('+arg['var']+'!=A_f_MPI_STATUS_IGNORE)\n'+ self.mappers[arg['name']]['r2a']+'('+arg['var']+','+arg['var']+'_tmp);'
            else:
                if self.mappers[arg['name']]['type']!= 'void ':
                    if arg['name'] == 'weight_converter':
                        str= self.mappers[arg['name']]['r2a']+'(&'+arg['var']+',&'+arg['var']+'_tmp);'
                    else:
                        str= self.mappers[arg['name']]['r2a']+'('+arg['var']+',&'+arg['var']+'_tmp);'
                else:
                    str= self.mappers[arg['name']]['r2a']+'(&'+arg['var']+',&'+arg['var']+'_tmp);'
        return str
    def print_temporary_decl(self,arg,prefix=''):
        str=''
        size='1'
        if 'status_size' in self.mappers[arg['name']]:
            size='(R_f_MPI_STATUS_SIZE+1)'
            if 'arg_dep' in arg and arg['arg_dep']!='':
                str=self.mappers[arg['name']]['type']+'*'+arg['var']+'_tmp=('+arg['var']+'==A_f_MPI_STATUSES_IGNORE?R_f_MPI_STATUSES_IGNORE:('+self.mappers[arg['name']]['type']+'*) malloc((*'+arg['arg_dep']+')*'+size+'*sizeof('+self.mappers[arg['name']]['type']+')));'
            else:
                    str=self.mappers[arg['name']]['type']+arg['var']+'_tmp1'
                    str=str+'[R_f_MPI_STATUS_SIZE+1]'
                    str=str+';'
                    str=str+'\n'+self.mappers[arg['name']]['type']+'*'+arg['var']+'_tmp=('+arg['var']+'==A_f_MPI_STATUS_IGNORE?R_f_MPI_STATUS_IGNORE:'+arg['var']+'_tmp1);'
        else:
            if 'arg_dep' in arg and arg['arg_dep']!='':
                str=self.mappers[arg['name']]['type']+'*'+arg['var']+'_tmp=('+self.mappers[arg['name']]['type']+'*) malloc((*'+arg['arg_dep']+')*'+size+'*sizeof('+self.mappers[arg['name']]['type']+'));'
            else:
                if self.mappers[arg['name']]['type'] != 'void ':
                    if arg['name'] == 'weight_converter':
                        str='int *'+arg['var']+'_tmp='+arg['var']+';'
                    else:
                        str=self.mappers[arg['name']]['type']+arg['var']+'_tmp'
                        str=str+';'
                else:
                    str='void *'+arg['var']+'_tmp='+arg['var']+';'
        return str        
    def load_symbol(self,func_dict,handle_name,postfix=''):
        return '_LOCAL_'+func_dict['name']+'=dlsym('+handle_name+',"p'+func_dict['name'].lower()+'_'+postfix+'");'
#___________________________________________________________________________________________________________________________#

#------------------------------------------------CLASS c--------------------------------------------------------------------#

class generator:
      def __init__(self,mapper_list,funtions_list):
            self.mappers=mapper_list
            self.functions=funtions_list

      # Function generating A_MPI_... in test_generation_wrapper.c 
      def generate_func(self,func_dict, init_conf):
            count_loop=0
            str=self.print_symbol(func_dict,prefix='A_',name_arg=True,retval_name=False,app_side=True)
            str=str+'\n{'
            str=str+'\n#ifdef DEBUG'
            str=str+'\nprintf(\"entre : A_'+func_dict['name']+'\\n\");'
            str=str+'\n#endif'
            str=str+'\nin_w=1;\n'             
            if func_dict['name'] == "MPI_Alltoallw" or func_dict['name'] == "MPI_Ialltoallw":
                  str=str+'R_MPI_Comm comm_tmp1;\ncomm_conv_a2r(&comm,&comm_tmp1);\nint Comm_size;\nLOCAL_MPI_Comm_size(comm_tmp1, &Comm_size);'
            elif func_dict['name'] == "MPI_Ineighbor_alltoallw" or func_dict['name'] == "MPI_Neighbor_alltoallw":
                  str=str+'R_MPI_Comm comm_tmp1;\ncomm_conv_a2r(&comm,&comm_tmp1);\nint indegree, outdegree, weighted;\nLOCAL_MPI_Dist_graph_neighbors_count(comm_tmp1, &indegree,&outdegree, &weighted);'
            for arg in func_dict['args']:
                  if arg['In'] or arg['Out']:
                        str=str+'\n'+self.print_temporary_decl(arg,'R_')
                  if arg['In']:
                        if arg["arg_dep"] != '':
                              count_loop=count_loop+1
                        str=str+'\n'+self.affect_temp_conv(arg,count_loop)
            str=str+'\n'+self.print_symbol(func_dict,prefix='LOCAL_',name_arg_postfix='_tmp',name_arg=True,retval_name=True,app_side=False,call=True, type_prefix='R_')+';'
            for arg in func_dict['args']:
                  if arg['Out']:
                        if arg["arg_dep"] != '':
                              count_loop=count_loop+1
                        str=str+'\n'+self.affect_val_conv(arg,count_loop,func_dict['name'])
            for arg in func_dict['args']:
                  if arg['arg_dep'] and "no_map" not in self.mappers[arg['name']]:
                        if arg['var'].split('[')[0] == 'array_of_statuses':
                           str=str+'\nif (array_of_statuses!=A_MPI_STATUSES_IGNORE)'
                           str=str+'\n'+'free('+arg['var'].split('[')[0]+'_tmp'+');'
                        else:
                           str=str+'\n'+'free('+arg['var'].split('[')[0]+'_tmp'+');'
            str=str+'\nin_w=0;\n'             
            str=str+'#ifdef DEBUG'
            str=str+'\nprintf(\"sort : A_'+func_dict['name']+'\\n\");'
            str=str+'\n#endif'
            str=str+'\n'+self.print_return_conv(func_dict)
            str=str+'\n'+'}'
            return str
      
      # Function generating R_MPI_... in test_generation_wrapper.c 
      def generate_func_r(self,func_dict):
            str=self.print_symbol(func_dict,prefix='R_',name_arg=True,retval_name=False,app_side=False,run_side=True)
            str=str+'\n{'
            str=str+'\n#ifdef DEBUG'
            str=str+'\nprintf(\"entre : R_'+func_dict['name']+'\\n\");'
            str=str+'\n#endif'
            str=str+'\n'+self.print_symbol(func_dict,prefix='LOCAL_',name_arg=True,retval_name=True,app_side=False,call=True, r_func=True,type_prefix='R_')+';\n'
            str=str+'#ifdef DEBUG'
            str=str+'\nprintf(\"sort : R_'+func_dict['name']+'\\n\");'
            str=str+'\n#endif\n'
            str=str+'return '+func_dict['ret']['var']+'_tmp;'
            str=str+'\n}'
            return str


      #### gg.print_symbol(i,func_ptr=True,prefix='INTERFACE_LOCAL_',type_prefix='',interface=True)+';\n'
      #### creer une fonction print symbol2 
      def generate_func_interface(self, func_dict):
            #str=self.print_symbol(func_dict,prefix='P',name_arg=True,retval_name=False,app_side=False,run_side=False,interface=False)
            str=self.print_symbol(func_dict,prefix='P',name_arg=True,retval_name=False,app_side=False,run_side=False,inter_side=True)
            str=str+'\n{'
            str=str+'\n#ifdef DEBUG'
            str=str+'\nprintf(\"entre : P'+func_dict['name']+' (interface) \\n\");'
            str=str+'\n#endif'
            str=str+'\n'+self.print_symbol(func_dict,prefix='INTERFACE_LOCAL_',name_arg=True,retval_name=True,app_side=False,call=True, r_func=False,type_prefix='',interface=True)+';\n'
            str=str+'#ifdef DEBUG'
            str=str+'\nprintf(\"sort : P'+func_dict['name']+' (interface)\\n\");'
            str=str+'\n#endif\n'
            str=str+'return '+func_dict['ret']['var']+'_tmp;'
            str=str+'\n}'

            return str

      # Function generating the code chooser asm
      def generate_func_asmK(self, func_dict):
            count_arg=2
            count_hexa=0
            rbp_bis=8
            nb_args_supp = 0
            nb_args=len(func_dict['args']);
            if(nb_args > 6):
                  nb_args_supp = nb_args - 6
            for i in range(nb_args_supp):
                  count_hexa = count_hexa+8
            rbp = count_hexa+8
            str_reg=""
            str=''
            str=str+'__asm__(\n'
            str=str+'\".global P'+func_dict['name']+'\\n\"\n'
            str=str+'\".weak '+func_dict['name']+'\\n\"\n'
            str=str+'\".set '+func_dict['name']+',P'+func_dict['name']+'\\n\"\n'
            str=str+'\".extern in_w\\n\"\n'
            str=str+'\".extern A_'+func_dict['name']+'\\n\"\n'
            str=str+'\".extern R_'+func_dict['name']+'\\n\"\n'
            #str=str+'\".align 4,0x90\\n\"\n'
            str=str+'\".type P'+func_dict['name']+',@function\\n\"\n'
            str=str+'\".text\\n\"\n'
            str=str+'\"P'+func_dict['name']+':\\n\"\n'
            str=str+'\"mov in_w@GOTPCREL(%rip),%rax\\n\"\n'
            str=str+'\"cmpl $0x0, 0x0(%rax)\\n\"\n'
            str=str+'\"jne inwrap_'+func_dict['name']+'\\n\"\n'
            str=str+'\"jmp *A_'+func_dict['name']+'@GOTPCREL(%rip)\\n\"\n'
            str=str+'\"inwrap_'+func_dict['name']+':\\n\"\n'
            str=str+'\"jmp *R_'+func_dict['name']+'@GOTPCREL(%rip)\\n\"\n'
            str=str+'\".size P'+func_dict['name']+',.-P'+func_dict['name']+'\\n\"\n'
            str=str+'\n);\n'
            return str
      
      # Function generating the code chooser asm with Thread Local Storage support
      def generate_func_asmK_tls(self, func_dict):
            count_hexa=0
            nb_args = len(func_dict['args'])
            str_reg=''
            str=''
            str=str+'__asm__(\n'
            str=str+'\".global P'+func_dict['name']+'\\n\"\n'
            str=str+'\".weak '+func_dict['name']+'\\n\"\n'
            str=str+'\".set '+func_dict['name']+',P'+func_dict['name']+'\\n\"\n'
            str=str+'\".extern in_w\\n\"\n'
            str=str+'\".extern A_'+func_dict['name']+'\\n\"\n'
            str=str+'\".extern R_'+func_dict['name']+'\\n\"\n'
            str=str+'\".type P'+func_dict['name']+',@function\\n\"\n'
            str=str+'\".text\\n\"\n'
            str=str+'\"P'+func_dict['name']+':\\n\"\n'
            for i in range(nb_args):
                  if i < 6:
                        count_hexa=count_hexa+8
                        #print 'count_hexa '+count_hexa.__str__()
            #if count_hexa % 32 != 0: #16 without __m256 | 32 with __m256
            while count_hexa % 16 != 0: #16 without __m256 | 32 with __m256
                  count_hexa=count_hexa+8
            str=str+'\"push %rbp\\n\"\n'
            str=str+'\"mov %rsp, %rbp\\n\"\n'
            if nb_args > 0 and func_dict['args'][0]['var'] != "":
                  str=str+'\"sub $'+count_hexa.__hex__()+', %rsp\\n\"\n'
            if nb_args > 0 and func_dict['args'][0]['var'] != "" :
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
            if nb_args > 0 and func_dict['args'][0]['var'] != "":
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
            str=str+'\"jne inwrap_'+func_dict['name']+'\\n\"\n'
            str=str+'\"jmp *A_'+func_dict['name']+'@GOTPCREL(%rip)\\n\"\n'
            str=str+'\"inwrap_'+func_dict['name']+':\\n\"\n'
            str=str+'\"jmp *R_'+func_dict['name']+'@GOTPCREL(%rip)\\n\"\n'
            str=str+'\".size P'+func_dict['name']+',.-P'+func_dict['name']+'\\n\"\n'
            str=str+'\n);\n'
            return str
      
      def generate_func_asmK_tls_updated_for_interface(self, func_dict):
            count_hexa=0
            nb_args = len(func_dict['args'])
            str_reg=''
            str=''
            str=str+'__asm__(\n'
            str=str+'\".global CC'+func_dict['name']+'\\n\"\n'
            str=str+'\".weak '+func_dict['name']+'\\n\"\n'
            str=str+'\".set '+func_dict['name']+',CC'+func_dict['name']+'\\n\"\n'
            str=str+'\".extern in_w\\n\"\n'
            str=str+'\".extern A_'+func_dict['name']+'\\n\"\n'
            str=str+'\".extern R_'+func_dict['name']+'\\n\"\n'
            str=str+'\".type CC'+func_dict['name']+',@function\\n\"\n'
            str=str+'\".text\\n\"\n'
            str=str+'\"CC'+func_dict['name']+':\\n\"\n'
            for i in range(nb_args):
                  if i < 6:
                        count_hexa=count_hexa+8
                        #print 'count_hexa '+count_hexa.__str__()
            #if count_hexa % 32 != 0: #16 without __m256 | 32 with __m256
            while count_hexa % 16 != 0: #16 without __m256 | 32 with __m256
                  count_hexa=count_hexa+8
            str=str+'\"push %rbp\\n\"\n'
            str=str+'\"mov %rsp, %rbp\\n\"\n'
            if nb_args > 0 and func_dict['args'][0]['var'] != "":
                  str=str+'\"sub $'+count_hexa.__hex__()+', %rsp\\n\"\n'
            if nb_args > 0 and func_dict['args'][0]['var'] != "" :
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
            if nb_args > 0 and func_dict['args'][0]['var'] != "":
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
            str=str+'\"jne inwrap_'+func_dict['name']+'\\n\"\n'
            str=str+'\"jmp *A_'+func_dict['name']+'@GOTPCREL(%rip)\\n\"\n'
            str=str+'\"inwrap_'+func_dict['name']+':\\n\"\n'
            str=str+'\"jmp *R_'+func_dict['name']+'@GOTPCREL(%rip)\\n\"\n'
            #str=str+'\".size P'+func_dict['name']+',.-P'+func_dict['name']+'\\n\"\n'
            str=str+'\n);\n'
            return str
 
      # Function generating the code chooser asm with stack gestion
      def generate_func_asm(self, func_dict):
            count_arg=2
            count_hexa=0
            rbp_bis=8
            nb_args_supp = 0
            nb_args=len(func_dict['args']);
            if(nb_args > 6):
                  nb_args_supp = nb_args - 6
            for i in range(nb_args_supp):
                  count_hexa = count_hexa+8
            rbp = count_hexa+8
            str_reg=""
            str=''
            str=str+'__asm__(\n'
            str=str+'\".global P'+func_dict['name']+'\\n\"\n'
            str=str+'\".weak '+func_dict['name']+'\\n\"\n'
            str=str+'\".set '+func_dict['name']+',P'+func_dict['name']+'\\n\"\n'
            str=str+'\".extern in_w\\n\"\n'
            str=str+'\".extern A_'+func_dict['name']+'\\n\"\n'
            str=str+'\".extern R_'+func_dict['name']+'\\n\"\n'
            str=str+'\".type P'+func_dict['name']+',@function\\n\"\n'
            str=str+'\".text\\n\"\n'
            str=str+'\"P'+func_dict['name']+':\\n\"\n'
            str=str+'\"push %rbp\\n\"\n'
            str=str+'\"mov %rsp,%rbp\\n\"\n'
            if(nb_args > 6):
                 str=str+'\"sub $'+count_hexa.__hex__()+',%rsp\\n\"\n'
                 for i in range(nb_args_supp):
                        str=str+'\"mov '+rbp.__hex__()+'(%rbp), %r11\\n\"\n'
                        str=str+'\"mov %r11, -'+rbp_bis.__hex__()+'(%rbp)\\n\"\n'
                        rbp = rbp-8
                        rbp_bis = rbp_bis + 8
            str=str+'\"mov in_w@GOTPCREL(%rip),%rax\\n\"\n'
            str=str+'\"cmp $0x0, 0x0(%rax)\\n\"\n'
            str=str+'\"jne inwrap_'+func_dict['name']+'\\n\"\n'
            str=str+'\"callq *A_'+func_dict['name']+'@GOTPCREL(%rip)\\n\"\n'
            str=str+'\"jmp End_'+func_dict['name']+'\\n\"\n'
            str=str+'\"inwrap_'+func_dict['name']+':\\n\"\n'
            str=str+'\"callq *R_'+func_dict['name']+'@GOTPCREL(%rip)\\n\"\n'
            str=str+'\"End_'+func_dict['name']+':\\n\"\n'
            if(nb_args > 6):
                  str=str+'\"add $'+count_hexa.__hex__()+',%rsp\\n\"\n'
            str=str+'\"leave\\n\"\n'
            str=str+'\"ret\\n\"\n'
            str=str+'\".size P'+func_dict['name']+',.-P'+func_dict['name']+'\\n\"\n'
            str=str+'\n);\n'
            return str
      
      
      def add_prefix(self,type,prefix):
            str=type.split('MPI_')
            if len(str) > 1:
                  return str[0]+prefix+'MPI_'+str[1]
            else:
                  return type
      # Function generating functions call (ret_tmp = LOCAL_MPI_...(...,...,...)), and function declaration ((A/R)_MPI_...(...,...,...))

      # print_symbol(func_dict,prefix='P',name_arg=True,retval_name=False,app_side=False,run_side=False,inter_side=True)

      def print_symbol(self,func_dict,type_prefix='',prefix='',name_arg=False,retval_name=False,app_side=False,run_side=False,name_arg_postfix='',call=False,func_ptr=False,r_func=False,interface=False,inter_side=False):
            #Set type function
            if app_side or run_side:
                  str=self.add_prefix(self.mappers[func_dict['ret']['name']]['type'],prefix)
            else:
                  str=self.add_prefix(self.mappers[func_dict['ret']['name']]['type'],type_prefix)
            #If function call
            if retval_name:
                  str=str+' '+'ret_tmp='
            #If function pointer
            if func_ptr:
                  str=str+' (*'+prefix+func_dict['name']+')('
            else:
                  str=str+' '+prefix+func_dict['name']+'('
            
            #Loop on the arguments of the function set the appropriate prefix to the type 
            for arg in func_dict['args']:
                  if retval_name== False: 
                        if app_side or run_side or inter_side: 
                              if prefix == "ASM_":
                                    prefix_use="A_"
                              else:
                                    #Testing which prefix to use for the MPI type:(R_ for generate_func_r ; A_ for generate_func, or none)
                                    if app_side:
                                          prefix_use="A_"
                                    elif run_side:
                                          prefix_use="R_"
                                    else:
                                          prefix_use=""
                              str=str+self.add_prefix(self.mappers[arg['name']]['type'],prefix_use)
                        #elif interface: # useful to make the pointer declaration interface #Ne pas spprimer toujours en test
                        #      str_test=arg['var']
                        #      str_type=self.mappers[arg['name']]['type']
                        #      if len(str_test.split('[')) > 1 and len(str_type.split('MPI_')) > 1:
                        #         str=str+''+self.mappers[arg['name']]['type']+' *'
                        #      elif len(str_test.split('[')) > 1 and len(str_test.split('[][3]')) == 1:
                        #            str=str+self.mappers[arg['name']]['type']+' *'
                        #      else:
                        #            if func_ptr:
                        #                  if len(str_test.split('[][3]')) > 1:
                        #                        str=str+self.mappers[arg['name']]['type']+'[][3]'
                        #                  else:
                        #                        str=str+self.add_prefix(self.mappers[arg['name']]['type'],type_prefix)
                        #            else:
                        #                  str=str+self.add_prefix(self.mappers[arg['name']]['type'],type_prefix)
                        else:
                              #Testing the kind of arguments for function pointer: example (MPI_Status array_of_statuses[] -> MPI_Status * )
                              str_test=arg['var']
                              str_type=self.mappers[arg['name']]['type']
                              if len(str_test.split('[')) > 1 and len(str_type.split('MPI_')) > 1: #MPI_args
                                 if interface: #if else toujours en test: voir si repercution sur la generation de test_generation_wrapper
                                    if func_ptr:
                                       str=str+''+self.mappers[arg['name']]['type']+' *'
                                    else:
                                       str=str+''+self.mappers[arg['name']]['type']
                                 else:
                                    str=str+'R_'+self.mappers[arg['name']]['type']+' *'
                              elif len(str_test.split('[')) > 1 and len(str_test.split('[][3]')) == 1:
                                    if func_ptr:
                                       str=str+self.mappers[arg['name']]['type']+' *'
                                    else:
                                       str=str+self.mappers[arg['name']]['type']
                              else:
                                    if func_ptr:
                                          if len(str_test.split('[][3]')) > 1:
                                                str=str+self.mappers[arg['name']]['type']+'[][3]'
                                          else:
                                                str=str+self.add_prefix(self.mappers[arg['name']]['type'],type_prefix)
                                    else:
                                          str=str+self.add_prefix(self.mappers[arg['name']]['type'],type_prefix)
                  
                  if name_arg:
                        #If function call
                        if call:
                              if arg['In'] or arg['Out']:
                                    if interface: # if still in test
                                       str_test=arg['var']
                                       if len(str_test.split('[')) > 1:
                                             str=str+' '+arg['var'].split('[')[0]+name_arg_postfix
                                       else:
                                             str=str+' '+arg['var']+name_arg_postfix
                                    else:
                                       if 'no_map' in self.mappers[arg['name']] or 'set' in self.mappers[arg['name']]:
                                             str_test=arg['var']
                                             if len(str_test.split('[')) > 1:
                                                   str=str+' '+arg['var'].split('[')[0]
                                             else:
                                                   str=str+' '+arg['var']
                                       elif 'wrapped' in self.mappers[arg['name']]:
                                             if not r_func:
                                                   str=str+' '+'(R_'+self.mappers[arg['name']]['type']+')'+self.mappers[arg['name']]['wrapped']
                                             else:
                                                   str=str+' '+arg['var']
                                       else:
                                             str_test=arg['var']
                                             if len(str_test.split('[')) > 1:
                                                   str=str+' '+arg['var'].split('[')[0]+name_arg_postfix
                                             else:
                                                   str=str+' '+arg['var']+name_arg_postfix
                              else:
                                    str=str+' '+arg['var']
                        #If function declaration
                        else:
                              str=str+' '+arg['var']+name_arg_postfix
                  str=str+','
            str=str[:-1]
            str=str+')'
            return str
      
      #Function which define the return convention
      def print_return_conv(self,func_dict):
            if self.mappers[func_dict['ret']['name']]['r2a'] == 'fint_conv_r2a' or self.mappers[func_dict['ret']['name']]['r2a'] == 'aint_conv_r2a' : 
                  return 'return (A_'+self.mappers[func_dict['ret']['name']]['type']+')'+func_dict['ret']['var']+'_tmp;'
            elif self.mappers[func_dict['ret']['name']]['r2a'] != 'double_conv_r2a':
                  return 'return '+self.mappers[func_dict['ret']['name']]['r2a']+'('+func_dict['ret']['var']+'_tmp);'
            else:
                  return 'return '+func_dict['ret']['var']+'_tmp;'

      #Function which define the affectation of temporary variable ( A -> R)
      def affect_temp_conv(self,arg,count_loop):
            #no need to convert
            if 'no_map' in self.mappers[arg['name']]:
                  str=''                             
            #particular arguments like MPI_Copy_function copy_fn, ... 
            elif 'wrap' in self.mappers[arg['name']]:
                  str=self.mappers[arg['name']]['wrap']+'=('+'A_'+self.mappers[arg['name']]['type']+')'+arg['var']+';'
            #particular case, where just a cast is needed (MPI_Aint, MPI_Offset)
            elif 'assign' in self.mappers[arg['name']]:
                  #testing if the argument is an array
                  if arg['arg_dep'] != '':
                        str_split=self.mappers[arg['name']]['type']
                        str='int i'+count_loop.__str__()+';\n'
                        str=str+'for(i'+count_loop.__str__()+'=0; i'+count_loop.__str__()+' < '+arg['arg_dep']+';i'+count_loop.__str__()+'++){\n'
                        str=str+arg['var'].split('[')[0]+'_tmp[i'+count_loop.__str__()+']= (R_'+str_split.split('*')[0]+')'+arg['var'].split('[')[0]+'[i'+count_loop.__str__()+'];\n}'
                  else:
                        str_split=self.mappers[arg['name']]['type']
                        str=arg['var']+'_tmp = (R_'+str_split.split('*')[0]+')'+arg['var']+';'
            elif 'set' in self.mappers[arg['name']]:
                  str=''
            else:
                  if arg['arg_dep'] !='':
                        str='int i'+count_loop.__str__()+';\n'
                        str=str+'for(i'+count_loop.__str__()+'=0; i'+count_loop.__str__()+' < '+arg['arg_dep']+';i'+count_loop.__str__()+'++){\n'
                        str=str+self.mappers[arg['name']]['a2r']+'(&'+arg['var'].split('[')[0]+'[i'+count_loop.__str__()+'],&'+arg['var'].split('[')[0]+'_tmp[i'+count_loop.__str__()+']);\n}'
                  else:
                        str_cmp= self.mappers[arg['name']]['type']
                        if len(str_cmp.split('*')) > 1 and self.mappers[arg['name']]['a2r'] != "status_prt_conv_a2r" and self.mappers[arg['name']]['a2r'] != "const_buffer_conv_a2r" and self.mappers[arg['name']]['a2r'] != "buffer_conv_a2r" and self.mappers[arg['name']]['a2r'] != "request_ptr_conv_a2r" and self.mappers[arg['name']]['a2r'] != "request_pers_ptr_conv_a2r" and self.mappers[arg['name']]['a2r'] !=  "weight_conv_a2r" and self.mappers[arg['name']]['a2r'] !=  "reduce_user_fn_a2r":
                              str= self.mappers[arg['name']]['a2r']+'('+arg['var']+','+arg['var']+'_tmp);'
                        else:
                              if self.mappers[arg['name']]['a2r'] == 'error_code_conv_a2r':
                                 str= arg['var']+'_tmp ='+self.mappers[arg['name']]['a2r']+'('+arg['var']+');'
                              else: 
                                 str= self.mappers[arg['name']]['a2r']+'(&'+arg['var']+',&'+arg['var']+'_tmp);'
            return str
      
      #Function which define the affectation of variable (R -> A)
      def affect_val_conv(self,arg,count_loop,name_func):
            str=''
            if 'no_map' in self.mappers[arg['name']]:
                  str=''
            elif 'assign' in self.mappers[arg['name']]:
                  str_cmp=self.mappers[arg['name']]['type']
                  if arg['arg_dep'] != '':
                        str_split=self.mappers[arg['name']]['type']
                        str='int i'+count_loop.__str__()+';\n'
                        str=str+'for(i'+count_loop.__str__()+'=0; i'+count_loop.__str__()+' < '+arg['arg_dep']+';i'+count_loop.__str__()+'++){\n'
                        str=str+arg['var'].split('[')[0]+'[i'+count_loop.__str__()+']= (A_'+str_split.split('*')[0]+')'+arg['var'].split('[')[0]+'_tmp[i'+count_loop.__str__()+'];\n}'
                  else :
                     if len(str_cmp.split('*')) > 1:
                           str='*'+arg['var']+'= (A_'+str_cmp.split('*')[0]+') *'+arg['var']+'_tmp;'
                     else:
                           str=arg['var']+'= (A_'+self.mappers[arg['name']]['type']+') '+arg['var']+'_tmp;'
            elif 'set' in self.mappers[arg['name']]:
                  str=self.mappers[arg['name']]['r2a']
            else:
                  #Testing in which circonstances the value is set (cf Developer documentation)
                  if arg['arg_dep'] !='' and 'if' not in arg :
                        if 'if_status_ignore' in arg:
                           str= 'int i'+count_loop.__str__()+';\n'
                           str=str+'if (array_of_statuses!=A_MPI_STATUSES_IGNORE)\n{\n'
                           str=str+'for(i'+count_loop.__str__()+'=0; i'+count_loop.__str__()+' < '+arg['arg_dep']+';i'+count_loop.__str__()+'++){\n'
                           str=str+self.mappers[arg['name']]['r2a']+'(&'+arg['var'].split('[')[0]+'[i'+count_loop.__str__()+'],&'+arg['var'].split('[')[0]+'_tmp[i'+count_loop.__str__()+']);\n}\n}'
                        else:
                           str= 'int i'+count_loop.__str__()+';\n'
                           str=str+'for(i'+count_loop.__str__()+'=0; i'+count_loop.__str__()+' < '+arg['arg_dep']+';i'+count_loop.__str__()+'++){\n'
                           str=str+self.mappers[arg['name']]['r2a']+'(&'+arg['var'].split('[')[0]+'[i'+count_loop.__str__()+'],&'+arg['var'].split('[')[0]+'_tmp[i'+count_loop.__str__()+']);\n}'
                  elif 'if' in arg:
                        if 'if_dep' in arg:
                              str='int i'+count_loop.__str__()+';\n'
                        str= str+'if(ret_tmp == '+arg['if']+'){\n'
                        if 'if_null' in arg and 'if_dep' not in arg:
                              if 'if_null_dep' in arg:
                                    if len(name_func.split('Test')) > 1:
                                          str=str+'if(*flag)\n'
                                    str=str+' if('+arg['var'].split('[')[0]+'_tmp[*'+arg['if_null_dep']+'] == '+arg['if_null']+'){\n'
                                    str=str+arg['del']+'(&'+arg['var'].split('[')[0]+'[*'+arg['if_null_dep']+'],&'+arg['var'].split('[')[0]+'_tmp[*'+arg['if_null_dep']+']);\n}\n'
                                    str=str+'}'
                              else:
                                    if len(name_func.split('Test')) > 1:
                                          str=str+'if(*flag)\n'
                                    str=str+' if(*'+arg['var']+'_tmp == '+arg['if_null']+'){\n'
                                    str=str+arg['del']+'(&'+arg['var']+',&'+arg['var']+'_tmp);\n}\n'
                                    str=str+'}'
                        elif 'if_null' in arg and 'if_dep' in arg:
                              if len(name_func.split('Test')) > 1 and len(name_func.split('Testsome')) == 1:
                                    str=str+'if(*flag)\n'
                              str=str+'for(i'+count_loop.__str__()+' = 0; i'+count_loop.__str__()+' < '+arg['if_dep']+'; i'+count_loop.__str__()+'++){\n'
                              if 'if_null_dep' in arg:
                                    str=str+'if('+arg['var'].split('[')[0]+'_tmp['+arg['if_null_dep'].split('[')[0]+'[i'+count_loop.__str__()+']]'+'=='+arg['if_null']+'){\n'
                                    str=str+arg['del']+'(&'+arg['var'].split('[')[0]+'['+arg['if_null_dep'].split('[')[0]+'[i'+count_loop.__str__()+']],&'+arg['var'].split('[')[0]+'_tmp['+arg['if_null_dep'].split('[')[0]+'[i'+count_loop.__str__()+']]);\n}\n}\n}'
                              else:
                                    str=str+'if('+arg['var'].split('[')[0]+'_tmp[i'+count_loop.__str__()+']'+'=='+arg['if_null']+'){\n'
                                    str=str+arg['del']+'(&'+arg['var'].split('[')[0]+'[i'+count_loop.__str__()+'],&'+arg['var'].split('[')[0]+'_tmp[i'+count_loop.__str__()+']);\n}\n}\n}'
                        else:
                              if 'del' in arg and 'del2' in arg:
                                    str=str+arg['del']+'(&'+arg['var']+',&'+arg['var']+'_tmp);\n'
                                    str=str+arg['del2']+'(&'+arg['var']+',&'+arg['var']+'_tmp);\n}'
                              elif 'del' in arg:
                                    if arg['del'] == 'errhandler_del':
                                          str=str+arg['del']+'('+arg['var']+','+arg['var']+'_tmp);\n}'
                                    elif arg['del'] == 'communicator_translation_del(comm)':
                                          #str=str+arg['del']+';'+'\n'+'comm_conv_r2a(comm,comm_tmp);\n}'
                                          str=str+'comm_conv_r2a(comm,comm_tmp);\n'+arg['del']+';'+'\n}'
                                    else:
                                          str=str+arg['del']+'(&'+arg['var']+',&'+arg['var']+'_tmp);\n}'
                              elif name_func == "MPI_Comm_get_errhandler" or name_func == "MPI_Errhandler_get":
                                    if name_func == "MPI_Comm_get_errhandler": 
                                          str=str+'A_MPI_Comm_errhandler_fn* ptr_err_handler_func;\n'
                                          str=str+'communicator_fn_translation_get(comm, &ptr_err_handler_func);\n'
                                          str=str+'errhandler_fn_translation_update(*errhandler, ptr_err_handler_func);\n}'
                                    elif name_func == "MPI_Errhandler_get":
                                          str=str+'errhandler_translation_get_key_from_value(*errhandler_tmp,errhandler);\n}'
                              else:
                                    str=str+self.mappers[arg['name']]['r2a']+'(&'+arg['var']+',&'+arg['var']+'_tmp);\n}' 
                  elif 'if_err' in arg:
                        str='if('+arg['if_err']+'){\n'
                        if name_func == 'MPI_Comm_set_errhandler':
                              str=str+'A_MPI_Comm_errhandler_fn* ptr_errhandler_func;\n'
                        elif name_func == 'MPI_Errhandler_set':
                              str=str+'A_MPI_Handler_function* ptr_errhandler_func;\n'
                        str=str+'errhandler_fn_translation_get(errhandler, &ptr_errhandler_func);\n'
                        str=str+'communicator_fn_translation_update(comm, ptr_errhandler_func);\n}'
                  else:
                        str_tmp=self.mappers[arg['name']]['type']
                        if len(str_tmp.split('*')) > 1 and self.mappers[arg['name']]['r2a'] != "status_prt_conv_r2a" and self.mappers[arg['name']]['r2a'] !=  "request_pers_ptr_conv_r2a" and self.mappers[arg['name']]['r2a'] != "errhandler_ptr_conv_r2a" and self.mappers[arg['name']]['r2a'] != "buffer_conv_r2a" and self.mappers[arg['name']]['r2a'] != "weight_conv_r2a":
                              str= self.mappers[arg['name']]['r2a']+'('+arg['var']+','+arg['var']+'_tmp);'
                        else:
                              str= self.mappers[arg['name']]['r2a']+'(&'+arg['var']+',&'+arg['var']+'_tmp);'
            return str

      #Function which define the declaration of temporary variable
      def print_temporary_decl(self,arg,prefix=''):
            str=''
            if 'no_map' in self.mappers[arg['name']] or 'wrap' in self.mappers[arg['name']] or 'set' in self.mappers[arg['name']] : 
                  str=''
            else:     
                  if self.mappers[arg['name']]['local_alloc'] == 1 :
                        str=self.add_prefix(self.mappers[arg['name']]['type'][:-1],prefix)+' '+arg['var']+'_ltmp;\n'+self.add_prefix(self.mappers[arg['name']]['type'],prefix)+' '+arg['var']+'_tmp=&'+arg['var']+'_ltmp;'
                  elif 'init_alloc' in self.mappers[arg['name']]:
                        str=self.mappers[arg['name']]['type']+' '+arg['var']+'_tmp ='+self.mappers[arg['name']]['init_alloc']+';'
                  elif arg['arg_dep'] != '':
                        str_test=self.mappers[arg['name']]['type']
                        str_test_out=arg['arg_dep']
                        if str_test_out == '*outcount':
                              str_test_out='incount'
                        if len(str_test.split('*')) > 1:
                           str='R_'+str_test.split('*')[0]+' *'+arg['var'].split('[')[0]+'_tmp = malloc(sizeof(R_'+str_test.split('*')[0]+')*'+str_test_out+');'
                        else:
                           if str_test == 'MPI_Status': #special case: where MPI_STATUSES_IGNORE is use as an argument for array_of_statuses in MPI_Waitall/Waitsome and MPI_Testall/Testsome
                              str='R_MPI_Status *array_of_statuses_tmp=(array_of_statuses==A_MPI_STATUSES_IGNORE?R_MPI_STATUSES_IGNORE:(R_MPI_Status *) malloc(sizeof(R_'+self.mappers[arg['name']]['type']+')*'+str_test_out+'));'
                           else:
                              str='R_'+str_test+' *'+arg['var'].split('[')[0]+'_tmp = malloc(sizeof(R_'+self.mappers[arg['name']]['type']+')*'+str_test_out+');'
                  else:
                        str=self.add_prefix(self.mappers[arg['name']]['type'],prefix)+' '+arg['var']+'_tmp;'
            return str        

      #Function generating the call to dlsym 
      def load_symbol(self,func_dict,handle_name):
            return 'LOCAL_'+func_dict['name']+'=dlsym('+handle_name+',"P'+func_dict['name']+'");'

#______________________________________________________________________________________________________________________________#


if __name__ == '__main__':


      c=''
      fortran=''
      interface=''
      wrapper=''
      C_file=''
      F_file=''

      if len(sys.argv) < 2:
         print 'Language needed: (FORTRAN|C [INTERFACE] [WRAPPER])'
      else:
         if sys.argv[1] == 'FORTRAN':
            fortran='true'
         elif sys.argv[1] == 'C':
            c='true'
         if len(sys.argv) > 2 :
            if sys.argv[2] == 'INTERFACE':
                interface='true'
            elif sys.argv[2] == 'WRAPPER':
                wrapper='true'

# C function list files : func_list_interface_c.txt func_list_preload_c.txt func_list_interface_c_interface.txt

      if c=='true' and wrapper=='true':
         C_file='C/func_list_preload_c.txt'
      elif c=='true' and interface=='true':
         C_file='C/func_list_interface_c_interface.txt'
      else:      
      #elif C=='true' and wrapper !='true' and interface !='true':
         C_file='C/func_list_interface_c.txt'

#FORTRAN functions list files : func_list_interface.txt func_list_interface_interface.text func_list_preload.txt
      
      if fortran=='true' and wrapper=='true':
         F_file='FORTRAN/func_list_preload.txt'
      elif fortran=='true' and interface=='true':
         F_file='FORTRAN/func_list_interface_interface.text'
      else:      
      #elif FORTRAN=='true' and wrapper !='true' and interface !='true':
         F_file='FORTRAN/func_list_interface.txt'

#-----------------------------Configuration files-----------------------------#
      #File containing all functions dictionnary
      with open('./C/functions.json') as data_file:    
            data = json.load(data_file)
      with open('./FORTRAN/functions.json') as data_file_f:    
      #with open('./C/functions.json') as data_file_f:    
            data_f = json.load(data_file_f)
      #File containing all mappers dictionnary
      with open('./C/mappers.json') as mapper_file:
            mappers=json.load(mapper_file)
      with open('./FORTRAN/mappers_f.json') as mapper_f_file:
            mappers_f=json.load(mapper_f_file)
      #File containing the function list  
      #with open('./C/func_list.txt') as fl:
      with open(C_file) as fl:
            def_list=fl.read().splitlines()
      #with open('./FORTRAN/func_list.txt') as fl_f:
      with open(F_file) as fl_f:
            def_list_f=fl_f.read().splitlines()
      with open('./FORTRAN/functions_fort_overide.json') as data_file:    
            data2 = json.load(data_file)
      #File containing all pre-requisites in __attribute__((constructor)) void wrapper_init()
      init_conf =  open('./C/init_conf.txt','r')
      #File containing all the functions not generated (included code chooser asm)
      if wrapper == 'true' :
         not_generated = open('./C/not_generated_asmK_tls.txt','r')
      else:
         not_generated = open('./C/not_generated_asmK_tls_updated_for_interface.txt','r')
      #File containing the list of not_generated function
      not_generated_ptr = open('./C/not_generated_pointer.txt','r')
      #File containing the list of pre_requisites for interop C-Fortran
      with open('./C/c2f_f2c_list.txt') as c2f:
            c2f_list=c2f.read().splitlines()
      ompi_const=open('./C/ompi_const_set.txt','r')
      interface_key_gen=open('./C/not_generated_interface_KEYVAL.txt','r')
#-----------------------------------------------------------------------------#

#      c=''
#      fortran=''
#      interface=''
#
#      if len(sys.argv) < 2:
#         print 'Language needed: (FORTRAN|C [INTERFACE] )'
#      else:
#         if sys.argv[1] == 'FORTRAN':
#            fortran='true'
#         elif sys.argv[1] == 'C':
#            c='true'
#         if len(sys.argv) > 2 :
#            if sys.argv[2] == 'INTERFACE':
#                interface='true'

#------------------------------------C----------------------------------------#
      if c == 'true' and interface != 'true':
         gg=generator(mappers,data)
         print '//############################# Wi4MPI License ###########################' 
         print '//# `04/04/2016`                                                         #'
         print '//# Copyright or (C) or Copr. Commissariat a l\'Energie Atomique         #'
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

         print '/*'
         print ' * This code is full generated'
         print ' */'
         print '#define _GNU_SOURCE'
         print '#include <stdio.h>'
         print '#include <dlfcn.h>'
         print "/*ompi constante*/"
         if wrapper != 'true':
            print '#if defined(OMPI_OMPI)'
            for i in ompi_const:
                  str_ompi_cste = i.split('\n')[0]
                  print 'extern '+str_ompi_cste.split('[')[0]+';'
            print '#endif'
         ompi_const.seek(0,0)
         print '#if defined(OMPI_INTEL)'
         for i in ompi_const:
               print i.split('\n')[0]
         print '#endif\n'
         print '#define EXTERN_ALLOCATED 1'
         print '#include "mappers.h"\n'
         print '__thread int in_w=0;'
         for i in not_generated:
               print i.split('\n')[0]
         for i in data:
               if i['name'] in def_list:
                     print gg.print_symbol(i,name_arg=True,retval_name=False,type_prefix='A_')+';'
                     print gg.print_symbol(i,func_ptr=True,prefix='LOCAL_',type_prefix='R_')+';\n'
                    #Code chooser
                    ### ASM_Stack ###
                     #print gg.generate_func_asm(i)
                    ### asmK ###
                     #print gg.generate_func_asmK(i)
                    ### asmK_tls ###
                     ## For preload version ##
                     if wrapper == 'true':
                        print gg.generate_func_asmK_tls(i)
                     ## For interface version ##
                     else:
                        print gg.generate_func_asmK_tls_updated_for_interface(i)
                     #A_MPI_
                     print gg.generate_func(i,init_conf)
                     #R_MPI_
                     print gg.generate_func_r(i)
         print '#ifdef OMPI_OMPI'
         for list_other in data:
                     if list_other['name'] in c2f_list:
                           print gg.print_symbol(list_other,name_arg=True,retval_name=False,type_prefix='A_')+';'
                           print gg.print_symbol(list_other,func_ptr=True,prefix='LOCAL_',type_prefix='R_')+';\n'
                           print gg.generate_func_asmK_tls(list_other)
                           print gg.generate_func(list_other,init_conf)
                           print gg.generate_func_r(list_other)
         print '#endif'
         #Construction of the lib_init
         print '__attribute__((constructor)) void wrapper_init(void) {'
         print 'void *lib_handle=dlopen(getenv(\"TRUE_MPI_LIB\"),RTLD_NOW|RTLD_GLOBAL);'
         for i in not_generated_ptr:
               print i.split('\n')[0]
         for i in data:
               if i['name'] in def_list or i['name'] in c2f_list:
                     print gg.load_symbol(i,'lib_handle')
         print '#if defined(INTEL_OMPI) || defined(OMPI_INTEL)'           
         print 'local_MPIR_Dup_fn=dlsym(lib_handle,"MPIR_Dup_fn");'
         print '#endif'
         if wrapper == 'true' :
            print '#if defined(INTEL_INTEL) || defined(OMPI_INTEL)'
            print 'R_MPI_UNWEIGHTED=dlsym(lib_handle,"MPI_UNWEIGHTED");'
            print 'R_MPI_WEIGHTS_EMPTY=dlsym(lib_handle,"MPI_WEIGHTS_EMPTY");'
            print '#endif'
            print '#if defined(INTEL_INTEL) || defined(INTEL_OMPI)'
            print 'A_MPI_UNWEIGHTED=dlsym(lib_handle,"MPI_UNWEIGHTED");'
            print 'A_MPI_WEIGHTS_EMPTY=dlsym(lib_handle,"MPI_WEIGHTS_EMPTY");'
            print '#endif'
            print '//#ifdef OMPI_OMPI'
            print '//init_global(lib_handle);'
            print '//#endif'
         else:
            print '#ifdef OMPI_OMPI'
            print 'init_global(lib_handle);'
            print '#elif OMPI_INTEL'
            print 'R_MPI_UNWEIGHTED=dlsym(lib_handle,"MPI_UNWEIGHTED");'
            print 'R_MPI_WEIGHTS_EMPTY=dlsym(lib_handle,"MPI_WEIGHTS_EMPTY");'
            print 'MPI_UNWEIGHTED=dlsym(lib_handle,"MPI_UNWEIGHTED");'
            print 'MPI_WEIGHTS_EMPTY=dlsym(lib_handle,"MPI_WEIGHTS_EMPTY");'
            print '#endif'
         for conf in init_conf:
               print conf.split('\n')[0]
         print '}'
      
#---------------------------------FORTRAN-------------------------------------#
      elif fortran == 'true' and interface != 'true':
         for idx,j in enumerate(data_f):
            for i in data2:
               if i['name'] == j['name']:
                   data_f[idx]=i  
         gg=generator_f(mappers_f)
         print '//############################# Wi4MPI License ###########################' 
         print '//# `04/04/2016`                                                         #'
         print '//# Copyright or (C) or Copr. Commissariat a l\'Energie Atomique         #'
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

         print ' #include <stdlib.h>'
         print ' #include <stdio.h>'
         print '#include <dlfcn.h>'
         print '#include "wrapper_f.h"'
         if wrapper!='true':
            print '//extern void *local_mpi_null_delete_fn_;'
            print '//extern void *local_mpi_null_copy_fn_;'
            print '//extern void *local_mpi_dup_fn_;'        
         print 'extern __thread int in_w;'
         for i in data_f:
            for j in def_list_f: 
               if i['name'].lstrip().rstrip() == j.lstrip().rstrip():
                  print gg.print_symbol(i,app_side=True,func_ptr=False,prefix='',postfix='_',type_prefix='R_',lower=True)+';\n'
                  print gg.print_symbol(i,app_side=True,func_ptr=False,prefix='',postfix='__',type_prefix='R_',lower=True)+';\n'
                  print gg.print_symbol(i,app_side=True,func_ptr=False,prefix='p',postfix='_',type_prefix='R_',lower=True)+';\n'
                  print gg.print_symbol(i,app_side=True,func_ptr=False,prefix='p',postfix='__',type_prefix='R_',lower=True)+';\n'
                  print gg.print_symbol(i,app_side=True,func_ptr=False,prefix='p',postfix='_',type_prefix='R_',lower=True)+';\n'
                  if wrapper=='true':
                     print '#define A_f_'+i['name'] +' _P'+i['name']
                  else:
                     print '//#define A_f_'+i['name'] +' _P'+i['name']
                  print '#pragma weak '+i['name'].lower()+'_=_P'+i['name']
                  print '#pragma weak '+i['name'].lower()+'__=_P'+i['name']
                  print '#pragma weak p'+i['name'].lower()+'__=_P'+i['name']
                  print gg.print_symbol(i,app_side=True,func_ptr=True,prefix='_LOCAL_',type_prefix='R_')+';\n'
                  print gg.generate_func(i)
         print '__attribute__((constructor)) void wrapper_init_f(void) {'
         if wrapper!='true':
            print 'void *lib_handle_f=dlopen(getenv(\"TRUE_MPI_F_LIB\"),RTLD_NOW|RTLD_GLOBAL);'
         for i in data_f:
            for j in def_list_f: 
               if i['name'].lstrip().rstrip() == j.lstrip().rstrip():
                  if wrapper=='true':
                     print gg.load_symbol(i,'RTLD_NEXT')
                  else:
                     print gg.load_symbol(i,'lib_handle_f')
         if wrapper=='true':
            print gg.load_symbol({'name':'MPI_Error_string'},'RTLD_NEXT')
            print gg.load_symbol({'name':'MPI_Get_processor_name'},'RTLD_NEXT')
            print gg.load_symbol({'name':'MPI_File_open'},'RTLD_NEXT')
            print gg.load_symbol({'name':'MPI_File_set_view'},'RTLD_NEXT')
            print gg.load_symbol({'name':'MPI_File_get_view'},'RTLD_NEXT')
            print gg.load_symbol({'name':'MPI_File_delete'},'RTLD_NEXT')
            print gg.load_symbol({'name':'MPI_Info_delete'},'RTLD_NEXT')
            print gg.load_symbol({'name':'MPI_Info_get'},'RTLD_NEXT')
            print gg.load_symbol({'name':'MPI_Info_get_nthkey'},'RTLD_NEXT')
            print gg.load_symbol({'name':'MPI_Info_get_valuelen'},'RTLD_NEXT')
            print gg.load_symbol({'name':'MPI_Info_set'},'RTLD_NEXT')
            print gg.load_symbol({'name':'MPI_Win_get_name'},'RTLD_NEXT')
            print gg.load_symbol({'name':'MPI_Win_set_name'},'RTLD_NEXT')
            print gg.load_symbol({'name':'MPI_Comm_get_name'},'RTLD_NEXT')
            print gg.load_symbol({'name':'MPI_Comm_set_name'},'RTLD_NEXT')
            print gg.load_symbol({'name':'MPI_Comm_spawn'},'RTLD_NEXT')
            #print gg.load_symbol({'name':'MPI_Comm_spawn_multiple'},'RTLD_NEXT')
            print gg.load_symbol({'name':'MPI_Type_get_name'},'RTLD_NEXT')
            print gg.load_symbol({'name':'MPI_Type_set_name'},'RTLD_NEXT')
            print gg.load_symbol({'name':'MPI_Add_error_string'},'RTLD_NEXT')
            print gg.load_symbol({'name':'MPI_Close_port'},'RTLD_NEXT')
            print gg.load_symbol({'name':'MPI_Get_library_version'},'RTLD_NEXT')
            print gg.load_symbol({'name':'MPI_Open_port'},'RTLD_NEXT')
            print gg.load_symbol({'name':'MPI_Publish_name'},'RTLD_NEXT')
            print gg.load_symbol({'name':'MPI_Unpublish_name'},'RTLD_NEXT')
            print gg.load_symbol({'name':'MPI_Lookup_name'},'RTLD_NEXT')
            print gg.load_symbol({'name':'MPI_Pack_external'},'RTLD_NEXT')
            print gg.load_symbol({'name':'MPI_Pack_external_size'},'RTLD_NEXT')
            print gg.load_symbol({'name':'MPI_Unpack_external'},'RTLD_NEXT')
         else :
            print gg.load_symbol({'name':'MPI_Error_string'},'lib_handle_f')
            print gg.load_symbol({'name':'MPI_Get_processor_name'},'lib_handle_f')
            print gg.load_symbol({'name':'MPI_File_open'},'lib_handle_f')
            print gg.load_symbol({'name':'MPI_File_set_view'},'lib_handle_f')
            print gg.load_symbol({'name':'MPI_File_get_view'},'lib_handle_f')
            print gg.load_symbol({'name':'MPI_File_delete'},'lib_handle_f')
            print gg.load_symbol({'name':'MPI_Info_delete'},'lib_handle_f')
            print gg.load_symbol({'name':'MPI_Info_get'},'lib_handle_f')
            print gg.load_symbol({'name':'MPI_Info_get_nthkey'},'lib_handle_f')
            print gg.load_symbol({'name':'MPI_Info_get_valuelen'},'lib_handle_f')
            print gg.load_symbol({'name':'MPI_Info_set'},'lib_handle_f')
            print gg.load_symbol({'name':'MPI_Win_get_name'},'lib_handle_f')
            print gg.load_symbol({'name':'MPI_Win_set_name'},'lib_handle_f')
            print gg.load_symbol({'name':'MPI_Comm_get_name'},'lib_handle_f')
            print gg.load_symbol({'name':'MPI_Comm_set_name'},'lib_handle_f')
            print gg.load_symbol({'name':'MPI_Comm_spawn'},'lib_handle_f')
            #print gg.load_symbol({'name':'MPI_Comm_spawn_multiple'},'lib_handle_f')
            print gg.load_symbol({'name':'MPI_Type_get_name'},'lib_handle_f')
            print gg.load_symbol({'name':'MPI_Type_set_name'},'lib_handle_f')
            print gg.load_symbol({'name':'MPI_Add_error_string'},'lib_handle_f')
            print gg.load_symbol({'name':'MPI_Close_port'},'lib_handle_f')
            print gg.load_symbol({'name':'MPI_Get_library_version'},'lib_handle_f')
            print gg.load_symbol({'name':'MPI_Open_port'},'lib_handle_f')
            print gg.load_symbol({'name':'MPI_Publish_name'},'lib_handle_f')
            print gg.load_symbol({'name':'MPI_Unpublish_name'},'lib_handle_f')
            print gg.load_symbol({'name':'MPI_Lookup_name'},'lib_handle_f')
            print gg.load_symbol({'name':'MPI_Pack_external'},'lib_handle_f')
            print gg.load_symbol({'name':'MPI_Pack_external_size'},'lib_handle_f')
            print gg.load_symbol({'name':'MPI_Unpack_external'},'lib_handle_f')
            
            print '#ifdef ompi_ompi'
            print 'ccc_mpi_fortran_bottom_=dlsym(lib_handle_f,"mpi_fortran_bottom_");'
            print 'ccc_mpi_fortran_in_place_=dlsym(lib_handle_f,"mpi_fortran_in_place_");'
            print 'ccc_mpi_fortran_argv_null_=dlsym(lib_handle_f,"mpi_fortran_argv_null_");'
            print 'ccc_mpi_fortran_argvs_null_=dlsym(lib_handle_f,"mpi_fortran_argvs_null_");'
            print 'ccc_mpi_fortran_errcodes_ignore_=dlsym(lib_handle_f,"mpi_fortran_errcodes_ignore_");'
            print 'ccc_mpi_fortran_status_ignore_=dlsym(lib_handle_f,"mpi_fortran_status_ignore_");'
            print 'ccc_mpi_fortran_statuses_ignore_=dlsym(lib_handle_f,"mpi_fortran_statuses_ignore_");'
            print 'ccc_mpi_fortran_unweighted_=dlsym(lib_handle_f,"mpi_fortran_unweighted_");'
            print 'ccc_mpi_fortran_weights_empty_=dlsym(lib_handle_f,"mpi_fortran_weights_empty_");'
            print '////mpi_null_delete_fn_;'
            print '////mpi_null_copy_fn_;'
            print '////mpi_null_delete_fn_;'
            print '#endif'
            print '#ifdef ompi_mpich'
            print 'ccc_mpi_fortran_bottom_=dlsym(lib_handle_f,"mpipriv1_");'
            print 'ccc_mpi_fortran_in_place_=((int *)dlsym(lib_handle_f,"mpipriv1_")+1);'
            print 'ccc_mpi_fortran_argv_null_=((int*)dlsym(lib_handle_f,"mpiprivc_")+1);'
            print 'ccc_mpi_fortran_argvs_null_=dlsym(lib_handle_f,"mpiprivc_");'
            print 'ccc_mpi_fortran_errcodes_ignore_=((int *)dlsym(lib_handle_f,"mpipriv2_")+1);'
            print 'ccc_mpi_fortran_status_ignore_=((int *)dlsym(lib_handle_f,"mpipriv1_")+2);'
            print 'ccc_mpi_fortran_statuses_ignore_=dlsym(lib_handle_f,"mpipriv2_");'
            print 'ccc_mpi_fortran_unweighted_=dlsym(lib_handle_f,"mpifcmb5_");'
            print 'ccc_mpi_fortran_weights_empty_=dlsym(lib_handle_f,"mpifcmb9_");'
            print '#endif'
            print '//local_mpi_null_delete_fn_=dlsym(lib_handle_f,"mpi_null_delete_fn_");'
            print '//local_mpi_null_copy_fn_=dlsym(lib_handle_f,"mpi_null_copy_fn_");'
            print '//local_mpi_dup_fn_=dlsym(lib_handle_f,"mpi_dup_fn_");'

         print '}'
   
      elif interface == 'true' and c== 'true':
         gg=generator(mappers,data)
         print '//############################# Wi4MPI License ###########################' 
         print '//# `04/04/2016`                                                         #'
         print '//# Copyright or (C) or Copr. Commissariat a l\'Energie Atomique         #'
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

         print '/*'
         print ' * This code is full generated'
         print ' */'
         print '#define _GNU_SOURCE'
         print '#include <stdio.h>'
         print '#include <dlfcn.h>'
         print '#include \"mpi.h\"'
         print "/*ompi constante*/"
         for i in interface_key_gen:
              print i.split('\n')[0]
         for i in data:
            if i['name'] in def_list:
              print gg.print_symbol(i,name_arg=True,retval_name=False,type_prefix='',interface=True)+';'
              print '#define '+i['name']+' P'+i['name']
              print '#pragma weak '+i['name']+'=P'+i['name']
              print gg.print_symbol(i,func_ptr=True,prefix='INTERFACE_LOCAL_',type_prefix='',interface=True)+';\n'
              #print gg.print_symbol(i,func_ptr=True,prefix='INTERFACE_LOCAL_',type_prefix='')+';\n'
              print gg.generate_func_interface(i)
         print '__attribute__((constructor)) void wrapper_interface(void) {'
         print 'void *interface_handle=dlopen(getenv(\"WRAPPER_WI4MPI\"),RTLD_NOW|RTLD_GLOBAL);'
         print 'if(!interface_handle)'
         print '{'                                      
         print 'printf("no true IC lib defined\\nerror :%s\\n",dlerror());'
         print 'exit(1);'
         print '}'                                                    
 
         #KEYVAL
         #for i in not_generated_ptr:
         #   #print i.split('\n')[0]
         #   str_tmp=i.split('\n')[0]
         #   if str_tmp != '':
         #      str_tmp2=str_tmp.split('LOCAL_')[1] 
         #      print 'INTERFACE_LOCAL_'+str_tmp2.split('lib_handle')[0]+'interface_handle'+str_tmp2.split('lib_handle')[1]
         
         print 'INTERFACE_LOCAL_MPI_Keyval_create=dlsym(interface_handle,"CCMPI_Keyval_create");'
         print 'INTERFACE_LOCAL_MPI_Keyval_free=dlsym(interface_handle,"CCMPI_Keyval_free");' 
         print 'INTERFACE_LOCAL_MPI_Comm_create_keyval=dlsym(interface_handle,"CCMPI_Comm_create_keyval");'
         print 'INTERFACE_LOCAL_MPI_Comm_free_keyval=dlsym(interface_handle,"CCMPI_Comm_free_keyval");'
         print 'INTERFACE_LOCAL_MPI_Win_get_attr=dlsym(interface_handle,"CCMPI_Win_get_attr");'
         print 'INTERFACE_LOCAL_MPI_Win_set_attr=dlsym(interface_handle,"CCMPI_Win_set_attr");'

         for i in data:
            if i['name'] in def_list or i['name'] in c2f_list:
               #print gg.load_symbol(i,'lib_handle')
               print'INTERFACE_LOCAL_'+i['name']+'=dlsym(interface_handle,\"CC'+i['name']+'\");'
         print '}'
      elif  interface == 'true' and fortran == 'true':
         for idx,j in enumerate(data_f):
            for i in data2:
               if i['name'] == j['name']:
                   data_f[idx]=i  
         gg=generator_f(mappers_f)
         print '//############################# Wi4MPI License ###########################'
         print '//# `04/04/2016`                                                         #'
         print '//# Copyright or (C) or Copr. Commissariat a l\'Energie Atomique         #'
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

         print '/*'
         print ' * This code is full generated'
         print ' */'
         print '#define _GNU_SOURCE'
         print '#include <stdio.h>'
         print '#include <dlfcn.h>'
         print '#include \"manual_interface.h\"'
         print 'void *mpi_comm_null_copy_fn_=NULL;'
         print 'void *mpi_win_dup_fn_=NULL;'
         print 'void *mpi_null_copy_fn_=NULL;'
         print 'void *mpi_comm_null_delete_fn_=NULL;'
         print 'void *mpi_comm_dup_fn_=NULL;'
         print 'void *mpi_type_null_copy_fn_=NULL;'
         print 'void *mpi_null_delete_fn_=NULL;'
         print 'void *mpi_dup_fn_=NULL;'
         print 'void *mpi_conversion_fn_null_=NULL;'
         print 'void *mpi_win_null_delete_fn_=NULL;'
         print 'void *mpi_type_null_delete_fn_=NULL;'
         print 'void *mpi_type_dup_fn_=NULL;'
         print 'void *mpi_win_null_copy_fn_=NULL;'
         print "/*ompi constante*/"
         for i in data_f:
            for j in def_list_f: 
               if i['name'].lstrip().rstrip() == j.lstrip().rstrip():
                    print 'void '+gg.print_symbol(i,name_arg=True,postfix='_',retval_name=False,type_prefix='',lower=True)+';'
                    print '#pragma weak '+i['name'].lower()+'_=p'+i['name'].lower()+'_'
                    print 'void '+gg.print_symbol(i,func_ptr=True,prefix='INTERFACE_F_LOCAL_',type_prefix='')+';\n'
                    print 'void p'+gg.print_symbol(i,name_arg=True,retval_name=False,type_prefix='',lower=True,postfix='_').lstrip()+'{\n'
                    print 'return '+gg.print_symbol(i,prefix='INTERFACE_F_LOCAL_',type_prefix='',call=True,name_arg=True,direct=True)+';\n}\n'
         print '__attribute__((constructor)) void wrapper_interface_f(void) {'
         print 'void *interface_handle_f=dlopen(getenv(\"WRAPPER_WI4MPI\"),RTLD_NOW|RTLD_GLOBAL);'
         print 'if(!interface_handle_f)' 
         print '{'                                    
         print 'printf("no true if lib defined\\nerror :%s\\n",dlerror());'
         print 'exit(1);'
         print '}'                                                   


         #KEYVAL
         #for i in not_generated_ptr:
         #   #print i.split('\n')[0]
         #   str_tmp=i.split('\n')[0]
         #   if str_tmp != '':
         #      str_tmp2=str_tmp.split('LOCAL_')[1] 
         #      print 'INTERFACE_LOCAL_'+str_tmp2.split('lib_handle')[0]+'interface_handle'+str_tmp2.split('lib_handle')[1]


         for i in data_f:
            for j in def_list_f: 
               if i['name'].lstrip().rstrip() == j.lstrip().rstrip():
                    print'INTERFACE_F_LOCAL_'+i['name']+'=dlsym(interface_handle_f,\"A_f_'+i['name']+'\");'
         print 'INTERFACE_F_LOCAL_MPI_Error_string=dlsym(interface_handle_f, \"A_f_MPI_Error_string\");'
         print 'INTERFACE_F_LOCAL_MPI_Get_processor_name=dlsym(interface_handle_f, \"A_f_MPI_Get_processor_name\");'
         print 'INTERFACE_F_LOCAL_MPI_File_open=dlsym(interface_handle_f, \"A_f_MPI_File_open\");'
         print 'INTERFACE_F_LOCAL_MPI_File_set_view=dlsym(interface_handle_f, \"A_f_MPI_File_set_view\");'
         print 'INTERFACE_F_LOCAL_MPI_File_get_view=dlsym(interface_handle_f, \"A_f_MPI_File_get_view\");'
         print 'INTERFACE_F_LOCAL_MPI_File_delete=dlsym(interface_handle_f, \"A_f_MPI_File_delete\");'
         print 'INTERFACE_F_LOCAL_MPI_Info_delete=dlsym(interface_handle_f, \"A_f_MPI_Info_delete\");'
         print 'INTERFACE_F_LOCAL_MPI_Info_get=dlsym(interface_handle_f, \"A_f_MPI_Info_get\");'
         print 'INTERFACE_F_LOCAL_MPI_Info_get_nthkey=dlsym(interface_handle_f, \"A_f_MPI_Info_get_nthkey\");'
         print 'INTERFACE_F_LOCAL_MPI_Info_get_valuelen=dlsym(interface_handle_f, \"A_f_MPI_Info_get_valuelen\");'
         print 'INTERFACE_F_LOCAL_MPI_Info_set=dlsym(interface_handle_f, \"A_f_MPI_Info_set\");'
         print 'INTERFACE_F_LOCAL_MPI_Win_get_name=dlsym(interface_handle_f, \"A_f_MPI_Win_get_name\");'
         print 'INTERFACE_F_LOCAL_MPI_Win_set_name=dlsym(interface_handle_f, \"A_f_MPI_Win_set_name\");'
         print 'INTERFACE_F_LOCAL_MPI_Comm_get_name=dlsym(interface_handle_f, \"A_f_MPI_Comm_get_name\");'
         print 'INTERFACE_F_LOCAL_MPI_Comm_set_name=dlsym(interface_handle_f, \"A_f_MPI_Comm_set_name\");'
         print 'INTERFACE_F_LOCAL_MPI_Comm_spawn=dlsym(interface_handle_f, \"A_f_MPI_Comm_spawn\");'
         #print 'INTERFACE_F_LOCAL_MPI_Comm_spawn_multiple=dlsym(interface_handle_f, \"A_f_MPI_Comm_spawn_multiple\");'
         print 'INTERFACE_F_LOCAL_MPI_Type_get_name=dlsym(interface_handle_f, \"A_f_MPI_Type_get_name\");'
         print 'INTERFACE_F_LOCAL_MPI_Type_set_name=dlsym(interface_handle_f, \"A_f_MPI_Type_set_name\");'
         print 'INTERFACE_F_LOCAL_MPI_Add_error_string=dlsym(interface_handle_f, \"A_f_MPI_Add_error_string\");'
         print 'INTERFACE_F_LOCAL_MPI_Close_port=dlsym(interface_handle_f, \"A_f_MPI_Close_port\");'
         print 'INTERFACE_F_LOCAL_MPI_Get_library_version=dlsym(interface_handle_f, \"A_f_MPI_Get_library_version\");'
         print 'INTERFACE_F_LOCAL_MPI_Open_port=dlsym(interface_handle_f, \"A_f_MPI_Open_port\");'
         print 'INTERFACE_F_LOCAL_MPI_Publish_name=dlsym(interface_handle_f, \"A_f_MPI_Publish_name\");'
         print 'INTERFACE_F_LOCAL_MPI_Unpublish_name=dlsym(interface_handle_f, \"A_f_MPI_Unpublish_name\");'
         print 'INTERFACE_F_LOCAL_MPI_Lookup_name=dlsym(interface_handle_f, \"A_f_MPI_Lookup_name\");'
         print 'INTERFACE_F_LOCAL_MPI_Pack_external=dlsym(interface_handle_f, \"A_f_MPI_Pack_external\");'
         print 'INTERFACE_F_LOCAL_MPI_Pack_external_size=dlsym(interface_handle_f, \"A_f_MPI_Pack_external_size\");'
         print 'INTERFACE_F_LOCAL_MPI_Unpack_external=dlsym(interface_handle_f, \"A_f_MPI_Unpack_external\");'
         print '}'


#!/bin/python
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

# __ Different possible generator name __
#Wrapper_Preload_C Wrapper_Preload_Fortran 
#Wrapper_Interface_C Wrapper_Interface_Fortran
#Interface_C Interface_Fortran

class generator:
    def __init__(self, name, mapper_list, funtions_list):
        self.name=name
        self.mappers=mapper_list
        self.functions=funtions_list
###                     ###
#   create debug string   #
###                     ###
# use mapper info to create a debug string available to par by an ad-hoc function
    def debug_string(self,func_dict): 
        out_str=func_dict['name']+" : \\n{\\n"
        out_arg_list=""
        for i in func_dict['args']:
            if('debug_type' in self.mappers[i['name']]):
                out_str=out_str+i['var']+" : "+self.mappers[i['name']]['debug_type']+",\\n"
                out_arg_list=out_arg_list+i['var']+","
        out_arg_list=out_arg_list+"ret_tmp"
        out_str=out_str+"return : "+self.mappers[func_dict['ret']['name']]['debug_type']+"}\\n"
        return [out_str,out_arg_list] 


###           ###
#  Header_func  # 
###           ###
    def header_func(self, func_dict, app_side=True):
        string='\n{'
        string=string+'\n#ifdef DEBUG'
        if self.name == 'Wrapper_Preload_C' or self.name=='Wrapper_Interface_C':
            if app_side:
                string=string+'\nprintf(\"entre : A_'+func_dict['name']+'\\n\");'
            else:
                string=string+'\nprintf(\"entre : R_'+func_dict['name']+'\\n\");'
        elif self.name == 'Wrapper_Preload_Fortran' or self.name == 'Wrapper_Interface_Fortran':
            string=string+'\nprintf(\"entre : A_f_'+func_dict['name']+'\\n\");'
        elif self.name == 'Interface_C':
            string=string+'\nprintf(\"entre : P'+func_dict['name']+' (interface) \\n\");'
        string=string+'\n#endif'
        string=string+'\n#ifdef TIMEOUT_SUPPORT'
        if app_side:
                string=string+'\nwi4mpi_set_timeout(WI4'+func_dict['name']+'_timeout);'
        string=string+'\n#endif'
        #handle reentrency only if in Wrapper_Preload_C or Wrapper_Interface_C Wrapper_Preload_Fortran Wrapper_Interface_Fortran
        if self.name == 'Wrapper_Preload_C' or self.name == 'Wrapper_Interface_C' or self.name == 'Wrapper_Preload_Fortran' or self.name == 'Wrapper_Interface_Fortran':
            if app_side:
                string=string+'\nin_w=1;\n'
        return string

###           ###
#  Footer_func  # 
###           ###
    def footer_func(self, func_dict, app_side=True):
        #handle reentrency only if in Wrapper_Preload_C or Wrapper_Interface_C Wrapper_Preload_Fortran Wrapper_Interface_Fortran
        string=''
        if self.name == 'Wrapper_Preload_C' or self.name == 'Wrapper_Interface_C' or self.name == 'Wrapper_Preload_Fortran' or self.name == 'Wrapper_Interface_Fortran':
            if app_side:
                string=string+'\nin_w=0;\n'
        string=string+'#ifdef DEBUG'
        if self.name == 'Wrapper_Preload_C' or self.name=='Wrapper_Interface_C':
            if app_side:
                string=string+'\nprintf(\"sort : A_'+func_dict['name']+'\\n\");'
                string=string+'debug_printer(\"'+self.debug_string(func_dict)[0]+'\",'+self.debug_string(func_dict)[1]+');'
            else:
                string=string+'\nprintf(\"sort : R_'+func_dict['name']+'\\n\");'
        elif self.name == 'Wrapper_Preload_Fortran' or self.name == 'Wrapper_Interface_Fortran':
            string=string+'\nprintf(\"sort : A_f_'+func_dict['name']+'\\n\");'
        elif self.name == 'Interface_C':
            string=string+'\nprintf(\"sort : P'+func_dict['name']+' (interface)\\n\");'
        string=string+'\n#endif\n'
        string=string+'#ifdef TIMEOUT_SUPPORT'
        if app_side:
                string=string+'\nwi4mpi_unset_timeout();'
        string=string+'\n#endif'
        if self.name == 'Wrapper_Preload_C' or self.name == 'Wrapper_Interface_C':
            if app_side:
                string=string+'\n'+self.print_return_conv_c(func_dict)
            else:
                string=string+'\nreturn '+func_dict['ret']['var']+'_tmp;'
        elif self.name == 'Interface_C':
                string=string+'\nreturn '+func_dict['ret']['var']+'_tmp;'
        if self.name == 'Wrapper_Preload_C' or self.name=='Wrapper_Interface_C':
            string=string+'\n}'
        else:
            string=string+'\n}'
        return string

###          ###
#  add_prefix  # 
###          ###
    def add_prefix(self,type,prefix):
        if self.name == 'Wrapper_Preload_Fortran' or self.name == 'Wrapper_Interface_Fortran' or self.name =='Interface_Fortran':
            return '' #Specifique a la generation Fortran
        str=type.split('MPI_')
        if len(str) > 1:
            return str[0]+prefix+'MPI_'+str[1]
        else:
            return type 
###               ###
#   Print_symbol_c  #
###               ###
#Print symbol generate a function call or declaration or a function pointer declaration as follow : (we decide to separate both C and Fortran Version)
##.First generate the return type of the function
##.Second print the name
##.Third print all different arguments of the function with or without the type according if it's a function call or if it's a declaration function 
#object_gen.print_symbol_c(i,name_arg=True,retval_name=False,type_prefix='',interface=True)
    def print_symbol_c(self,func_dict,type_prefix='',prefix='',name_arg=False,retval_name=False,app_side=False,run_side=False,name_arg_postfix='',call=False,func_ptr=False,r_func=False,interface=False,inter_side=False,interF=False):
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
                    #Testing if the arguments are in a called function or a declaration function ( in other word if the type of the argument needs to be printed
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
                    str_type_tmp=self.mappers[arg['name']]['type']
                    str_type=str_type_tmp.split('const ')[-1]
                    str=str+self.add_prefix(str_type,prefix_use)
                else:
                    #Testing the kind of arguments for function pointer: example (MPI_Status array_of_statuses[] -> MPI_Status * )
                    str_test=arg['var']
                    str_type_tmp=self.mappers[arg['name']]['type']
                    str_type=str_type_tmp.split('const ')[-1]
                    if len(str_test.split('[')) > 1 and len(str_type.split('MPI_')) > 1: #MPI_args []
                        if interface: #if else toujours en test: voir si repercution sur la generation de test_generation_wrapper
                            if func_ptr or interF:
                                str=str+''+self.mappers[arg['name']]['type']+' *'
                            else:
                                str=str+''+self.mappers[arg['name']]['type']
                        else:
                            str=str+'R_'+self.mappers[arg['name']]['type']+' *'
                    elif len(str_test.split('[')) > 1 and len(str_test.split('[][3]')) == 1: #Non MPI_Args with []
                        if func_ptr or interF:
                            str=str+self.mappers[arg['name']]['type']+' *'
                        else:
                            str=str+self.mappers[arg['name']]['type']
                    else:
                        if func_ptr or interF:
                            if len(str_test.split('[][3]')) > 1: #args with [][3]
                                str=str+self.mappers[arg['name']]['type']+'[][3]'
                            else:
                                str=str+self.add_prefix(self.mappers[arg['name']]['type'],type_prefix)
                        else:
                            str=str+self.add_prefix(self.mappers[arg['name']]['type'],type_prefix)
            #If the argument name needs to be print (Example in declaration function or function call) 
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

###                    ###
#  print_symbol_fortran  #
###                    ###
    def print_symbol_f(self,func_dict,type_prefix='',prefix='',postfix='',name_arg=False,retval_name=False,app_side=False,name_arg_postfix='',call=False,func_ptr=False,lower=False,direct =False):
        arg_len=0; 
        if ('as_ret' in func_dict['ret'] and not retval_name):
            if app_side : 
                str=self.add_prefix(self.mappers[func_dict['ret']['name']]['type'],prefix)
            else:
                str=self.add_prefix(self.mappers[func_dict['ret']['name']]['type'],type_prefix)
        else: #Setting return type
            if app_side:
                str='void '
            else:
                str=''
        if retval_name :
            if 'as_ret' in self.mappers[func_dict['ret']['name']]:
                str=str+' '+'ret_tmp='
        if func_ptr:#If function pointer 
            str=str+' (*'+prefix+func_dict['name']+postfix+')('
        else: #Setting function name
            if not lower: #if declaration function or function call
                str=str+' '+prefix+func_dict['name']+postfix+'('
            else: #if creating different MPI function declaration
                str=str+' '+prefix+func_dict['name'].lower()+postfix+'('
        #Dealing with arguments
        if len(func_dict['args']) !=0 :
            for arg in func_dict['args']:
                if self.mappers[arg['name']]['type']!='':
                    if call != True: #if it's a declaration then, the type needs to be printed
                        if app_side:
                            str=str+self.mappers[arg['name']]['type']+'*'
                        else:
                            str=str+self.mappers[arg['name']]['type']+'*'
                    if name_arg: # if the arguments need to be printed (Function declaration or function call) 
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
###                      ###
#  print_temporary_decl_c  #
###                      ###
    def print_temporary_decl_c(self,arg,prefix=''):
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
                       str='R_'+str_test.split('*')[0]+' *'+arg['var'].split('[')[0]+'_tmp = wi4mpi_alloc(sizeof(R_'+str_test.split('*')[0]+')*'+str_test_out+');'
                    else:
                       if str_test == 'MPI_Status': #special case: where MPI_STATUSES_IGNORE is use as an argument for array_of_statuses in MPI_Waitall/Waitsome and MPI_Testall/Testsome
                          str='R_MPI_Status *array_of_statuses_tmp=(array_of_statuses==A_MPI_STATUSES_IGNORE?R_MPI_STATUSES_IGNORE:(R_MPI_Status *) wi4mpi_alloc(sizeof(R_'+self.mappers[arg['name']]['type']+')*'+str_test_out+'));'
                       else:
                          str='R_'+str_test+' *'+arg['var'].split('[')[0]+'_tmp = wi4mpi_alloc(sizeof(R_'+self.mappers[arg['name']]['type']+')*'+str_test_out+');'
              else:
                    str=self.add_prefix(self.mappers[arg['name']]['type'],prefix)+' '+arg['var']+'_tmp;'
        return str

###                      ###
#  print_temporary_decl_f  #
###                      ###
    def print_temporary_decl_f(self, arg, prefix=''):
        str=''
        size='1'
        if 'status_size' in self.mappers[arg['name']]:
            size='(R_f_MPI_STATUS_SIZE+1)'
            if 'arg_dep' in arg and arg['arg_dep']!='':
                str=self.mappers[arg['name']]['type']+'*'+arg['var']+'_tmp=('+arg['var']+'==A_f_MPI_STATUSES_IGNORE?R_f_MPI_STATUSES_IGNORE:('+self.mappers[arg['name']]['type']+'*) wi4mpi_alloc((*'+arg['arg_dep']+')*'+size+'*sizeof('+self.mappers[arg['name']]['type']+')));'
            else:
                str=self.mappers[arg['name']]['type']+arg['var']+'_tmp1'
                str=str+'[R_f_MPI_STATUS_SIZE+1]'
                str=str+';'
                str=str+'\n'+self.mappers[arg['name']]['type']+'*'+arg['var']+'_tmp=('+arg['var']+'==A_f_MPI_STATUS_IGNORE?R_f_MPI_STATUS_IGNORE:'+arg['var']+'_tmp1);'
        else:
            if 'arg_dep' in arg and arg['arg_dep']!='':
                str=self.mappers[arg['name']]['type']+'*'+arg['var']+'_tmp=('+self.mappers[arg['name']]['type']+'*) wi4mpi_alloc((*'+arg['arg_dep']+')*'+size+'*sizeof('+self.mappers[arg['name']]['type']+'));'
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

###                  ###
#  affect_temp_conv_c  #
###                  ###
    def affect_temp_conv_c(self,arg,count_loop):
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
                if len(str_cmp.split('*')) > 1 and self.mappers[arg['name']]['a2r'] != "status_prt_conv_a2r" and self.mappers[arg['name']]['a2r'] != "const_buffer_conv_a2r" and self.mappers[arg['name']]['a2r'] != "buffer_conv_a2r" and self.mappers[arg['name']]['a2r'] != "request_ptr_conv_a2r" and self.mappers[arg['name']]['a2r'] != "request_pers_ptr_conv_a2r" and self.mappers[arg['name']]['a2r'] !=  "weight_conv_a2r" and self.mappers[arg['name']]['a2r'] !=  "reduce_user_fn_a2r" and self.mappers[arg['name']]['a2r'] != "datarep_conversion_function_a2r" and self.mappers[arg['name']]['a2r'] != "datarep_extent_function_converter_a2r" and self.mappers[arg['name']]['a2r'] != "grequest_query_fn_a2r":
                    str= self.mappers[arg['name']]['a2r']+'('+arg['var']+','+arg['var']+'_tmp);'
                else:
                    if self.mappers[arg['name']]['a2r'] == 'error_code_conv_a2r':
                        str= arg['var']+'_tmp ='+self.mappers[arg['name']]['a2r']+'('+arg['var']+');'
                    else:
                        str= self.mappers[arg['name']]['a2r']+'(&'+arg['var']+',&'+arg['var']+'_tmp);'
        return str

###                  ###
#  affect_temp_conv_f  #
###                  ###

    def affect_temp_conv_f(self,arg):
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

###                 ###
# affect_val_conv_c #
###                 ###
    def affect_val_conv_c(self,arg,count_loop,name_func):
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

###                 ###
# affect_val_conv_f #
###                 ###
    def affect_val_conv_f(self,arg):
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

###                ###
#  affect_temp_conv  #
###                ###

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
###               ###
#  generate_func_c  #
###               ###
#Generate C interface, wrapper_preload_c, wrapper_interface_c
    def generate_func_c(self,func_dict, init_conf, app_side=True):
        count_loop=0
        str=''
        if self.name == 'Wrapper_Preload_C' or self.name == 'Wrapper_Interface_C':
            if app_side:#Generate wrapped function on the app side
                str = '#ifndef ' + func_dict['name'].upper() + '_OVERRIDE\n' # ifdef OVERRIDE
                str+=self.print_symbol_c(func_dict,prefix='A_',name_arg=True,retval_name=False,app_side=True)
                str=str+self.header_func(func_dict, app_side=True)
                if func_dict['name'] == "MPI_Alltoallw" or func_dict['name'] == "MPI_Ialltoallw":
                    str=str+'R_MPI_Comm comm_tmp1;\ncomm_conv_a2r(&comm,&comm_tmp1);\nint Comm_size;\nLOCAL_MPI_Comm_size(comm_tmp1, &Comm_size);'
                elif func_dict['name'] == "MPI_Ineighbor_alltoallw" or func_dict['name'] == "MPI_Neighbor_alltoallw":
                    str=str+'R_MPI_Comm comm_tmp1;\ncomm_conv_a2r(&comm,&comm_tmp1);\nint indegree, outdegree, weighted;\nLOCAL_MPI_Dist_graph_neighbors_count(comm_tmp1, &indegree,&outdegree, &weighted);'
                elif func_dict['name'] == 'MPI_Errhandler_create' and self.name == 'Wrapper_Interface_C':
                    str=str+'errhandler_locks_ac();'
                for arg in func_dict['args']:
                    if arg['In'] or arg['Out']:
                        str=str+'\n'+self.print_temporary_decl_c(arg,'R_')
                    if arg['In']:
                        if arg["arg_dep"] != '':
                            count_loop=count_loop+1
                        str=str+'\n'+self.affect_temp_conv_c(arg,count_loop)
                if func_dict['name'] == 'MPI_Attr_put' and self.name == 'Wrapper_Interface_C':
                    str=str+'myKeyval_functions_t *tt;\nif(tt=myKeyval_translation_get(keyval)) tt->ref++;'
                str=str+'\n'+self.print_symbol_c(func_dict,prefix='LOCAL_',name_arg_postfix='_tmp',name_arg=True,retval_name=True,app_side=False,call=True, type_prefix='R_')+';'
                if func_dict['name'] == 'MPI_Init':
                    str=str+"\nint wi4mpi_rank;\n"
                    str=str+"R_MPI_Comm_rank(R_MPI_COMM_WORLD,&wi4mpi_rank);\n"
                    str=str+"if(wi4mpi_rank==0)\n"
                    if self.name == 'Wrapper_Interface_C':
                        str=str+"\tfprintf(stdout,\"You are using Wi4MPI-%s with the mode interface From Interface To %s\\n\", getenv(\"WI4MPI_VERSION\"), getenv(\"WI4MPI_TO\"));"
                    else:
                        str=str+"\tfprintf(stdout,\"You are using Wi4MPI-%s with the mode preload From %s To %s\\n\", getenv(\"WI4MPI_VERSION\"), getenv(\"WI4MPI_FROM\"), getenv(\"WI4MPI_TO\"));"
                for arg in func_dict['args']:
                    if arg['Out']:
                        if arg["arg_dep"] != '':
                            count_loop=count_loop+1
                        str=str+'\n'+self.affect_val_conv_c(arg,count_loop,func_dict['name'])
                for arg in func_dict['args']:
                    if arg['arg_dep'] and "no_map" not in self.mappers[arg['name']]:
                        if arg['var'].split('[')[0] == 'array_of_statuses':
                            str=str+'\nif (array_of_statuses!=A_MPI_STATUSES_IGNORE)'
                            str=str+'\n'+'wi4mpi_free('+arg['var'].split('[')[0]+'_tmp'+');'
                        else:
                            str=str+'\n'+'wi4mpi_free('+arg['var'].split('[')[0]+'_tmp'+');'
                if func_dict['name'] == 'MPI_Errhandler_create' and self.name == 'Wrapper_Interface_C':
                    str=str+'errhandler_locks_re();'
                str=str+self.footer_func(func_dict, app_side=True)  
                str += '\n#endif\n' # endif OVERRIDE
            else :#Generate wrapped function on the run side
                str=self.print_symbol_c(func_dict,prefix='R_',name_arg=True,retval_name=False,app_side=False,run_side=True)
                str=str+self.header_func(func_dict, app_side=False)
                str=str+'\n'+self.print_symbol_c(func_dict,prefix='LOCAL_',name_arg=True,retval_name=True,app_side=False,call=True, r_func=True,type_prefix='R_')+';\n'
                str=str+self.footer_func(func_dict, app_side=False)
        elif self.name == 'Interface_C':#Generate the C interface
                str=self.print_symbol(func_dict,prefix='P',name_arg=True,retval_name=False,app_side=False,run_side=False,inter_side=True)
                str=str+'\n'+self.header_func(func_dict)
                str=str+'\n'+self.print_symbol_c(func_dict,prefix='INTERFACE_LOCAL_',name_arg=True,retval_name=True,app_side=False,call=True, r_func=False,type_prefix='',interface=True)+';\n'
                str=str+'\n'+self.footer_func(func_dict)
        return str

###               ###
#  generate_func_f  #
###               ###
    def generate_func_f(self,func_dict):
        string=self.print_symbol_f(func_dict,prefix='A_f_',name_arg=True,retval_name=False,app_side=True)
        string=string+self.header_func(func_dict)
        string=string+self.mappers[func_dict['ret']['name']]['type']+' ret_tmp=0;\n'
        if func_dict['name'] == "MPI_Alltoallw" or func_dict['name'] == "MPI_Ialltoallw":
            string=string+'int comm_tmp1, ierr;\ncomm_a2r(comm,&comm_tmp1);\nint *Comm_size;\n_LOCAL_MPI_Comm_size(&comm_tmp1, Comm_size, &ierr);'
        elif func_dict['name'] == "MPI_Ineighbor_alltoallw" or func_dict['name'] == "MPI_Neighbor_alltoallw":
            string=string+'int comm_tmp1;\ncomm_a2r(comm,&comm_tmp1);\nint *indegree, *outdegree, *weighted, ierr;\n_LOCAL_MPI_Dist_graph_neighbors_count(&comm_tmp1, indegree,outdegree, weighted, &ierr);'
        for arg in func_dict['args']:
            if (arg['In'] or arg['Out']) and not 'nomap' in self.mappers[arg['name']]:
                string=string+'\n'+self.print_temporary_decl_f(arg,'R_')
        for arg in func_dict['args']:
            if arg['In'] and not 'nomap' in self.mappers[arg['name']]:
                string=string+'\n'+self.affect_temp_conv_f(arg)
        if 'assoc' in func_dict:
            for assoc in func_dict['assoc']:
                if  assoc['func'].find('_del')!=-1:
                    string=string+'\n'+assoc['func']+'('
                    string=string+assoc['key']
                    if 'value' in assoc:
                        string=string+','+assoc['value']
                    string=string+');'
        string=string+'\n'+self.print_symbol_f(func_dict,prefix='_LOCAL_',name_arg_postfix='_tmp',name_arg=True,retval_name=True,app_side=False,call=True)+';'
        for arg in func_dict['args']:
            if arg['Out'] and not 'nomap' in self.mappers[arg['name']] or arg['Out'] and func_dict['name'] == 'MPI_Keyval_free':
                if not 'nomap' in self.mappers[arg['name']]:
                    if func_dict['name']=='MPI_Errhandler_free':
                        string=string+'\nif(ret_tmp==R_f_MPI_SUCCESS){\n'
                        string=string+'errhandler_f_fn_translation_del(errhandler_tmp);\n'
                        string=string+'errhandler_converter_r2a(errhandler,&errhandler_tmp);\n'
                        string=string+'}'
                    elif func_dict['name']=='MPI_Error_class':
                        string=string+'\n'+self.affect_val_conv_f(arg)
                    else:
                        if self.name=='Wrapper_Interface_Fortran' and func_dict['name']=='MPI_Comm_free':
                            string=string+'if (ret_tmp == R_f_MPI_SUCCESS)\n\tcomm_r2au(comm, &comm_tmp);'
                        else:
                            string=string+'\nif(ret_tmp==R_f_MPI_SUCCESS)'+self.affect_val_conv_f(arg)
                else:
                    string=string+'\nif(ret_tmp==R_f_MPI_SUCCESS)\n'
                    string=string+'{\n'
                    string=string+'\t*keyval=A_MPI_KEYVAL_INVALID;\n'
                    string=string+'}\n'
            if 'arg_dep' in arg and arg['arg_dep']!='' and (arg['In'] or arg['Out'])  and not 'nomap' in self.mappers[arg['name']]:
                if arg['var'] == 'array_of_statuses':
                    string=string+'\nif (array_of_statuses!=A_f_MPI_STATUSES_IGNORE)'
                    string=string+'\n'+' wi4mpi_free('+arg['var']+'_tmp);'
                else:
                    string=string+'\n'+' wi4mpi_free('+arg['var']+'_tmp);'
        if 'assoc' in func_dict:
            for assoc in func_dict['assoc']:
                if  assoc['func'].find('_del')==-1:
                    string=string+'\n'+assoc['func']+'('
                    string=string+assoc['key']
                    if 'value' in assoc:
                        string=string+','+assoc['value']
                    string=string+');'
        string=string+'\n'+self.print_return_conv_f(func_dict)
        string=string+self.footer_func(func_dict)
        return string
    
###                      ###
#  generate_func_asmK_tls  #
###                      ###
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

###                                              ###
#   generate_func_asmK_tls_updated_for_interface   #
###                                              ###
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
        str=str+'\n);\n'
        return str

###                   ###
#  print_return_conv_c  #
###                   ###
    def print_return_conv_c(self,func_dict):
        if self.mappers[func_dict['ret']['name']]['r2a'] == 'fint_conv_r2a' or self.mappers[func_dict['ret']['name']]['r2a'] == 'aint_conv_r2a' :
            return 'return (A_'+self.mappers[func_dict['ret']['name']]['type']+')'+func_dict['ret']['var']+'_tmp;'
        elif self.mappers[func_dict['ret']['name']]['r2a'] != 'double_conv_r2a':
            return 'return '+self.mappers[func_dict['ret']['name']]['r2a']+'('+func_dict['ret']['var']+'_tmp);'
        else:
            return 'return '+func_dict['ret']['var']+'_tmp;'
###                   ###
#  print_return_conv_f  #
###                   ###

    def print_return_conv_f(self,func_dict):
        str=''
        if not 'nomap' in  self.mappers[func_dict['ret']['name']]:
            if 'as_ret' in func_dict['ret'] :
                str=self.mappers[func_dict['ret']['name']]['type'] +' '+func_dict['ret']['var']+';\n'
            str=str+ self.mappers[func_dict['ret']['name']]['r2a']+'('+func_dict['ret']['var']+',&'+func_dict['ret']['var']+'_tmp);\n'
        if 'as_ret' in func_dict['ret']:
            str=str+'return '+func_dict['ret']['var'];
        return str

###           ###
#  load_symbol  #
###           ###
    def load_symbol(self,func_dict,handle_name,postfix=''):
        if self.name=='Wrapper_Preload_C' or self.name=='Wrapper_Interface_C' or self.name=='Interface_C':
            return 'LOCAL_'+func_dict['name']+'=dlsym('+handle_name+',"P'+func_dict['name']+'");'
        else:
            return '_LOCAL_'+func_dict['name']+'=dlsym('+handle_name+',"p'+func_dict['name'].lower()+'_'+postfix+'");'

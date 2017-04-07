import json
import string
import os, sys
from pprint import pprint
from generator import generator

def header_license_file():
	string='//############################# Wi4MPI License ###########################'+'\n'
	string=string+'//# `04/04/2016`                                                         #'+'\n'
	string=string+'//# Copyright or (C) or Copr. Commissariat a l\'Energie Atomique         #'+'\n'
	string=string+'//#                                                                      #'+'\n'
	string=string+'//# IDDN.FR.001.210022.000.S.P.2014.000.10800                            #'+'\n'
	string=string+'//# This file is part of the Wi4MPI library.                             #'+'\n'
	string=string+'//#                                                                      #'+'\n'
	string=string+'//# This software is governed by the CeCILL-C license under French law   #'+'\n'
	string=string+'//# and abiding by the rules of distribution of free software. You can   #'+'\n'
	string=string+'//# use, modify and/ or redistribute the software under the terms of     #'+'\n'
	string=string+'//# the CeCILL-C license as circulated by CEA, CNRS and INRIA at the     #'+'\n'
	string=string+'//# following URL http://www.cecill.info.                                #'+'\n'
	string=string+'//#                                                                      #'+'\n'
	string=string+'//# The fact that you are presently reading this means that you have     #'+'\n'
	string=string+'//# had knowledge of the CeCILL-C license and that you accept its        #'+'\n'
	string=string+'//# terms.                                                               #'+'\n'
	string=string+'//#                                                                      #'+'\n'
	string=string+'//# Authors:                                                             #'+'\n'
	string=string+'//#   - Delforge Tony <tony.delforge.tgcc@cea.fr>                        #'+'\n'
	string=string+'//#   - Ducrot Vincent <vincent.ducrot.tgcc@cea.fr>                      #'+'\n'
	string=string+'//#                                                                      #'+'\n'
	string=string+'//########################################################################'+'\n'
	
	string=string+'/*'+'\n'
	string=string+' * This code is full generated'+'\n'
	string=string+' */'+'\n'
	return string

def generate_wrapper_c(object_gen, wrapper, ompi_const, not_generated, def_list, data, init_conf,not_generated_ptr):
	string=header_license_file()
	string=string+'#define _GNU_SOURCE'+'\n'
	string=string+'#include <stdio.h>'+'\n'
	string=string+'#include <dlfcn.h>'+'\n'
	string=string+"/*ompi constante*/"+'\n'
	if not wrapper:
		string=string+ '#if defined(OMPI_OMPI)'+'\n'
		for i in ompi_const:
			string=string+ 'extern '+i.split('[')[0]+';'+'\n'
		string=string+ '#endif'+'\n'	
	ompi_const.seek(0,0)
	string=string+ '#if defined(OMPI_INTEL)'+'\n'
	for i in ompi_const:
		string=string+ i
	string=string+ '#endif'+'\n\n'
	string=string+ '#define EXTERN_ALLOCATED 1\n'
	string=string+ '#include "mappers.h"\n\n'
	string=string+ '__thread int in_w=0;\n'
	for i in not_generated:
		string=string+ i
	for i in data:
		if i['name'] in def_list:
			string=string+object_gen.print_symbol_c(i,name_arg=True,retval_name=False,type_prefix='A_')+';\n'
			string=string+object_gen.print_symbol_c(i,func_ptr=True,prefix='LOCAL_',type_prefix='R_')+';\n\n'
			if wrapper:
				string=string+object_gen.generate_func_asmK_tls(i)+'\n'
			else:
				string=string+object_gen.generate_func_asmK_tls_updated_for_interface(i)+'\n'
			string=string+object_gen.generate_func_c(i, init_conf, app_side=True)+'\n'
			string=string+object_gen.generate_func_c(i, init_conf, app_side=False)+'\n'
	string=string+'#ifdef OMPI_OMPI\n'	
	for list_other in data:
		if list_other['name'] in c2f_list:
			string=string+object_gen.print_symbol(list_other,name_arg=True,retval_name=False,type_prefix='A_')+';'
			string=string+object_gen.print_symbol(list_other,func_ptr=True,prefix='LOCAL_',type_prefix='R_')+';\n'
			string=string+object_gen.generate_func_asmK_tls(list_other)
			string=string+object_gen.generate_func(list_other,init_conf)
			string=string+object_gen.generate_func_r(list_other)
	string=string+'#endif\n'
	string=string+'__attribute__((constructor)) void wrapper_init(void) {\n'
	string=string+'void *lib_handle=dlopen(getenv(\"TRUE_MPI_LIB\"),RTLD_NOW|RTLD_GLOBAL);\n'
	for i in not_generated_ptr:
		string=string+i
	for i in data:
		if i['name'] in def_list or i['name'] in c2f_list:
			string=string+object_gen.load_symbol(i,'lib_handle')+'\n'
	string=string+'#if defined(INTEL_OMPI) || defined(OMPI_INTEL)\n'
	string=string+'local_MPIR_Dup_fn=dlsym(lib_handle,"MPIR_Dup_fn");\n'
	string=string+'#endif\n'
	if wrapper:
		string=string+'#if defined(INTEL_INTEL) || defined(OMPI_INTEL)\n'
		string=string+'R_MPI_UNWEIGHTED=dlsym(lib_handle,"MPI_UNWEIGHTED");\n'
		string=string+'R_MPI_WEIGHTS_EMPTY=dlsym(lib_handle,"MPI_WEIGHTS_EMPTY");\n'
		string=string+'#endif\n'
		string=string+'#if defined(INTEL_INTEL) || defined(INTEL_OMPI)\n'
		string=string+'A_MPI_UNWEIGHTED=dlsym(lib_handle,"MPI_UNWEIGHTED");\n'
		string=string+'A_MPI_WEIGHTS_EMPTY=dlsym(lib_handle,"MPI_WEIGHTS_EMPTY");\n'
		string=string+'#endif\n'
		string=string+'//#ifdef OMPI_OMPI\n'
		string=string+'//init_global(lib_handle);\n'
		string=string+'//#endif\n'
	else:
		string=string+'#ifdef OMPI_OMPI\n'
		string=string+'init_global(lib_handle);\n'
		string=string+'#elif OMPI_INTEL\n'
		string=string+'R_MPI_UNWEIGHTED=dlsym(lib_handle,"MPI_UNWEIGHTED");\n'
		string=string+'R_MPI_WEIGHTS_EMPTY=dlsym(lib_handle,"MPI_WEIGHTS_EMPTY");\n'
		string=string+'MPI_UNWEIGHTED=dlsym(lib_handle,"MPI_UNWEIGHTED");\n'
		string=string+'MPI_WEIGHTS_EMPTY=dlsym(lib_handle,"MPI_WEIGHTS_EMPTY");\n'
		string=string+'#endif\n'
	for conf in init_conf:
		string=string+conf
	string=string+'}'
	return string

	

if __name__ == '__main__':
	interface_directory="./interface/gen"
	if not os.path.exists(interface_directory):
		os.makedirs(interface_directory)

	preload_directory="./preload/gen"
	if not os.path.exists(preload_directory):
		os.makedirs(preload_directory)

	root = os.getcwd()	

	#Common
	#Opening C and Fortran function dictionary
	#-----------------------------------------
	with open('./C/functions.json') as data_file:
	      data_c = json.load(data_file)
	with open('./FORTRAN/functions.json') as data_file_f:
	      data_f = json.load(data_file_f)
	#Opening C and Fortran mapper dictionary
	#---------------------------------------
	with open('./C/mappers.json') as mapper_file:
	      mappers_c=json.load(mapper_file)
	with open('./FORTRAN/mappers_f.json') as mapper_f_file:
	      mappers_f=json.load(mapper_f_file)
	
	#File containing all pre-requisites in __attribute__((constructor)) void wrapper_init()
	init_conf =  open('./C/init_conf.txt','r')
	
	not_generated_ptr = open('./C/not_generated_pointer.txt','r')
	ompi_const=open('./C/ompi_const_set.txt','r')

	#File containing the list of pre_requisites for interop C-Fortran
	with open('./C/c2f_f2c_list.txt') as c2f:
		c2f_list=c2f.read().splitlines()

	#Generating Preload file
	#File containing all the functions not generated (included code chooser asm)
	print " >>>>> Generating preload/gen/test_generation_wrapper.c"
	wrapper=True
	not_generated = open('./C/not_generated_asmK_tls.txt','r')
	
	C_file='C/func_list_preload_c.txt'
	F_file='FORTRAN/func_list_preload.txt'
	with open(C_file) as fl:
		def_list_c=fl.read().splitlines()
	with open(F_file) as fl_f:
		def_list_f=fl_f.read().splitlines()

	wrapper_preload_c=generator("Wrapper_Preload_C",mappers_c,data_c)
	os.chdir(preload_directory)
	preload_wrapper_c = open("test_generation_wrapper.c", "w")
	string=generate_wrapper_c(wrapper_preload_c, wrapper, ompi_const, not_generated, def_list_c, data_c,init_conf,not_generated_ptr)
	preload_wrapper_c.write(string)
	preload_wrapper_c.close()
	fl.close()
	fl_f.close()
	not_generated.close()
	print "        Done."
	os.chdir(root)
	#print " >>>>> Generating preload/gen/wrapper.c"
	wrapper_preload_fortran=generator("Wrapper_Preload_Fortran",mappers_f,data_f)

	#Generating Interface file
	print " >>>>> Generating interface/gen/test_generation_wrapper.c"
	wrapper=False
	not_generated = open('./C/not_generated_asmK_tls_updated_for_interface.txt','r')
	
	C_file='C/func_list_interface_c.txt'
	F_file='FORTRAN/func_list_interface.txt'
	with open(C_file) as fl:
		def_list_c=fl.read().splitlines()
	with open(F_file) as fl_f:
		def_list_f=fl_f.read().splitlines()

	ompi_const.seek(0,0)
	init_conf.seek(0,0)
 	not_generated_ptr.seek(0,0)
	wrapper_interface_c=generator("Wrapper_Interface_C", mappers_c,data_c)
	os.chdir(interface_directory)
	interface_wrapper_c =open("test_generation_wrapper.c", "w")
	string=generate_wrapper_c(wrapper_interface_c, wrapper, ompi_const, not_generated, def_list_c, data_c,init_conf,not_generated_ptr)
	interface_wrapper_c.write(string)
	interface_wrapper_c.close()
	fl.close()
	fl_f.close()
	not_generated.close()
	print "        Done."
	os.chdir(root)
	
	#print " >>>>> Generating preload/gen/wrapper.c"
	#wrapper_preload_fortran=generator("Wrapper_Preload_Fortran",mappers_f,data_f)









#	#Opening C and Fortran function list
#	#-----------------------------------  
#	with open(C_file) as fl:
#	      def_list_c=fl.read().splitlines()
#	with open(F_file) as fl_f:
#	      def_list_f=fl_f.read().splitlines()
#	
#	with open('./FORTRAN/functions_fort_overide.json') as data_file:
#	      data2 = json.load(data_file)
#	#File containing all pre-requisites in __attribute__((constructor)) void wrapper_init()
#	init_conf =  open('./C/init_conf.txt','r')
#	#File containing all the functions not generated (included code chooser asm)
#	#File containing the list of not_generated function
#	not_generated_ptr = open('./C/not_generated_pointer.txt','r')
#	#File containing the list of pre_requisites for interop C-Fortran
#	with open('./C/c2f_f2c_list.txt') as c2f:
#	      c2f_list=c2f.read().splitlines()
#	
#	interface_key_gen=open('./C/not_generated_interface_KEYVAL.txt','r')	

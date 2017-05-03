#!/usr/bin/python

import os
import subprocess as sub
import csv
import sys
import json
from pprint import pprint


def lisence_header():
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

def generate_header_f(mpi_root1,mpi_root2,header_path,fd_output):
	lisence_header()
	print '#ifndef __wrapper__h__\n#define __wrapper__h__\n'
	print '#include "utils.h"\n'
	p = sub.call(['./FORTRAN/utils/gen_common.sh',mpi_root1,'A_f_'],stdout=fd_output)
	pp = sub.call(['./FORTRAN/utils/gen_common.sh',mpi_root2,'R_f_'],stdout=fd_output)
	with open('./FORTRAN/utils/lists') as aa:
		vals=csv.reader(aa,delimiter=' ',quotechar='\'')	
		for r in vals:
			out=open('test.f90','w')
			out.write('\t\tprogram test\ninclude \'mpif.h\'\n')
			for i in range(4,len(r)):
				out.write('\t\tprint *,\''+r[i]+' \','+r[i]+'\n')
			out.write('\t\tend program')
			out.close()
			p = sub.call([mpi_root1+'/bin/mpif90','-I'+mpi_root1+'/include','-L'+mpi_root1+'/lib','test.f90'])
			ldp=os.getenv('LD_LIBRARY_PATH')
			os.environ['LD_LIBRARY_PATH']=mpi_root1+'/lib'+':'+ldp
			pp=sub.Popen('./a.out',stdout=sub.PIPE,stderr=sub.PIPE)
			output,err=pp.communicate()
			bb=csv.reader(output.split('\n'),delimiter=' ',skipinitialspace=True)
			os.environ['LD_LIBRARY_PATH']=mpi_root2+'/lib'+':'+ldp
			p = sub.call([mpi_root2+'/bin/mpif90','-I'+mpi_root2+'/include','-L'+mpi_root2+'/lib','test.f90'])
			pp=sub.Popen('./a.out',stdout=sub.PIPE,stderr=sub.PIPE)
			output,err=pp.communicate()
			cc=csv.reader(output.split('\n'),delimiter=' ',skipinitialspace=True)
			tab={}
			for rr in bb:
				if len(rr):
					tab[rr[-1]]=['','']
					tab[rr[-1]][0]=(rr[0])   
			for rr in cc:
				if len(rr):
					if rr[-1] in tab:
						tab[rr[-1]][1]=(rr[0])
					else:
						tab[rr[-1]]=['']
						tab[rr[-1]].append(rr[0])
			
			a2r='static inline void '+r[0]+'_a2r('+r[1]+'*ca,'+r[1]+'*cr){\n'  
			r2a='static inline void '+r[0]+'_r2a('+r[1]+'*ca,'+r[1]+'*cr){\n' 
			ii=0    
			jj=0    
			rnv={}  
			cnv={}  
			for i in tab: 
				if(tab[i][0]!=''):
					if (r[1].split(' ')[1]!="*"):
						print '#define A_f_'+tab[i][0]+' '+i+'\n'
					a2r=a2r+'if(A_f_'+tab[i][0]+'==*ca){\n'+'*cr=('+r[1]+')R_f_'+tab[i][0]+';return;}\nelse\n'
				if tab[i][1]=='':
					rnv[ii]=tab[i][0]
					ii=ii+1
				else:   
					if tab[i][0]=='':
						cnv[tab[i][1]]=jj
						jj=jj+1
				
				if(tab[i][1]!=''):
					if (r[1].split(' ')[1]!="*"):
						print '#define R_f_'+tab[i][1]+' '+i+'\n'
					r2a=r2a+'if(R_f_'+tab[i][1]+'==*cr){\n'+'*ca=('+r[1]+')A_f_'+tab[i][1]+';return;}\nelse\n'
			for i in tab:           
				if(tab[i][0]==''):
					a2r=a2r+'if(R_f_'+tab[i][1]+'==*ca)\n'+'*cr=('+r[1]+')A_f_'+rnv[cnv[tab[i][1]]]+';\nelse\n'
					r2a=r2a+'if(A_f_'+rnv[cnv[tab[i][1]]]+'==*cr)\n'+'*ca=('+r[1]+')R_f_'+tab[i][1]+';\nelse\n'
			a2r=a2r+'*cr=*ca;\n'
			if r[2]!='':
				a2r=a2r+r[2]+'(*cr);\n'
			a2r=a2r+'}\n'
			r2a=r2a+'*ca=*cr;\n'
			if r[3]!='':
				r2a=r2a+r[3]+'(*cr);\n'
			r2a=r2a+'\n}'
			
			print a2r
			print r2a
	out=open('test.f90','w')
	out.write('program test\ninclude \'mpif.h\'\n')
	out.write('print *,\'#define A_f_MPI_STATUS_SIZE\',MPI_STATUS_SIZE\n')
	out.write('print *,\'#define A_f_MPI_SOURCE\',MPI_SOURCE\n')          
	out.write('print *,\'#define A_f_MPI_TAG\',MPI_TAG\n')                
	out.write('print *,\'#define A_f_MPI_ERROR\',MPI_ERROR\n')            
	out.write('end program')
	out.close()
	p = sub.call([mpi_root1+'/bin/mpif90','-I'+mpi_root1+'/include','-L'+mpi_root1+'/lib','test.f90'])
	ldp=os.getenv('LD_LIBRARY_PATH')
	os.environ['LD_LIBRARY_PATH']=mpi_root1+'/lib'+':'+ldp
	pp=sub.Popen('./a.out',stdout=sub.PIPE,stderr=sub.PIPE)
	output,err=pp.communicate()
	print output
	out=open('test.f90','w')
	out.write('program test\ninclude \'mpif.h\'\n')
	out.write('print *,\'#define R_f_MPI_STATUS_SIZE\',MPI_STATUS_SIZE\n')
	out.write('print *,\'#define R_f_MPI_SOURCE\',MPI_SOURCE\n')          
	out.write('print *,\'#define R_f_MPI_TAG\',MPI_TAG\n')                
	out.write('print *,\'#define R_f_MPI_ERROR\',MPI_ERROR\n')            
	out.write('end program')
	out.close()
	os.environ['LD_LIBRARY_PATH']=mpi_root2+'/lib'+':'+ldp
	p = sub.call([mpi_root2+'/bin/mpif90','-I'+mpi_root2+'/include','-L'+mpi_root2+'/lib','test.f90'])
	pp=sub.Popen('./a.out',stdout=sub.PIPE,stderr=sub.PIPE)
	output,err=pp.communicate()
	print output
	print '#include "manual_wrapper.h"'
	print '#endif'

if __name__ == '__main__':

	preload_directory="./preload/header"
	if not os.path.exists(preload_directory):
		os.makedirs(preload_directory)

	with open('./FORTRAN/utils/conversion.json') as conversion:
		conv_list = json.load(conversion)
	for i in conv_list:
		mpi_root1=i["FROM"]
		mpi_root2=i["TO"]
		header_path=os.path.join(preload_directory, i['CONVERSION'])
		if not os.path.exists(header_path):
			os.makedirs(header_path)
		sys.stdout=open(header_path+"/wrapper_f.h","w")
		generate_header_f(mpi_root1,mpi_root2,header_path+"/wrapper_f.h",sys.stdout)
	os.remove("./a.out")
	os.remove("./test.f90")

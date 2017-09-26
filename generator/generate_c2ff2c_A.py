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

def generate_header_f():
    lisence_header()
    print '#ifndef __A_C2FF2C__h__\n#define __A_C2FF2C__h__\n'
    with open('c2flist') as aa:
        vals=csv.reader(aa,delimiter=' ',quotechar='\'')
        for r in vals:
            strc2f=r[1]+' A_'+r[2]+'_c2f(A_'+r[0]+' op){\n'
            strf2c='A_'+r[0]+' A_'+r[2]+'_f2c('+r[1]+' op){\n'
            for j in range(3,len(r)):
                strc2f=strc2f+'if(A_'+r[j]+'==op){return A_f_'+r[j]+';}\n'
                strf2c=strf2c+'if(A_f_'+r[j]+'==op){return A_'+r[j]+';}\n'
            strc2f=strc2f+'return ('+r[1]+')(op);\n}'
            strf2c=strf2c+'return (A_'+r[0]+')(op);\n}'
            print strf2c
            print strc2f
    print '#endif'
if __name__ == '__main__':

		generate_header_f()

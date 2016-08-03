#!/usr/bin/python
############################# Wi4MPI License ###########################
# `04/04/2016`                                                         #
# Copyright or (C) or Copr. Commissariat a l'Energie Atomique          #
#                                                                      #
# IDDN.FR.001.210022.001.S.P.2014.000.10800                            #
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
#   - Delforge Tony <tony.delforge.tgccAcea.fr>                        #
#   - Ducrot Vincent <vincent.ducrot.tgccAcea.fr>                      #
#                                                                      #
########################################################################


if __name__ =='__main__':
     ompi_const = open('ompi_const.txt','r')
     print '#include <stdio.h>'
     print 'int main(int argc, char** argv)'
     print '#define ompi_predefined_communicator_t 1024'
     print '#define ompi_predefined_datatype_t 512'
     print '#define ompi_predefined_errhandler_t 1024'
     print '#define ompi_predefined_file_t 1536'
     print '#define ompi_predefined_op_t 2048'
     print '#define ompi_predefined_group_t 256'
     print '#define ompi_predefined_info_t 256'
     print '#define ompi_predefined_request_t 256'
     print '#define ompi_predefined_win_t 512'
     print '{'
     for i in ompi_const:
            tmp_str=i.split(' ')
            print 'printf(\"char '+tmp_str[1].split('\n')[0].split(';')[0]+'[%d];\\n\",'+tmp_str[0]+');'
     print '}'

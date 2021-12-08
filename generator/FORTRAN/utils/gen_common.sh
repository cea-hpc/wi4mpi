#!/bin/bash
############################# Wi4MPI License ###########################
# `04/04/2016`                                                         #
# Copyright or (C) or Copr. Commissariat a l'Energie Atomique          #
#                                                                      #
# IDDN.FR.001.210022.000.S.P.2014.000.10800                            #
# This file is part of the Wi4MPI library.                             #
#                                                                      #
# SPDX-License-Identifier: BSD-3-Clause OR CeCILL-B                    #
#                                                                      #
#                                                                      #
# Authors:                                                             #
#   - Delforge Tony <tony.delforge.tgccAcea.fr>                        #
#   - Ducrot Vincent <vincent.ducrot.tgccAcea.fr>                      #
#   - Cotte Adrien <adrien.cotte.tgccAcea.fr>                          #
#                                                                      #
########################################################################

cat $1/include/mpif* |grep -i 'common\ */' |sed /\\,/s//\\//g |awk -F '/' -v prefix=$2 'begin{gsub(/ /,"",prefix)}{ i=3;if ($4!="") {while($i!="") {gsub(/ /,"",$i);print "#define "prefix$i" (((int*)&"tolower($2)"_["i-3"]))";i=i+1 }}else {gsub(/ /,"",$3);print "#define "prefix$3" (((int*)&"tolower($2)"_))";} gsub(/[ \t]/,"",$2);if ($2!="") {if (prefix!="A_f_") {if (i!=3) print "extern int "tolower($2)"_["i-3"];";else print "extern int "tolower($2)"_;";}else {if (i!=3) print str"int "tolower($2)"_["i-3"];";else print str"int "tolower($2)"_;";}}}'

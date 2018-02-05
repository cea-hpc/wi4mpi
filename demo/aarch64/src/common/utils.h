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


#ifndef UTILS_H
#define UTILS_H

#include "engine_fn.h"
void *User_fct_g_ptr;
static inline  void *get_user_fct(int op)
{
    void *ret;
     operator_fn_translation_get(op,&ret);
    return ret;
}
static inline void add_user_fct(int op)
{
  operator_fn_translation_update(op,User_fct_g_ptr);
}
static inline void del_usr_fct(int op)
{
    operator_fn_translation_del(op);
}

#endif /*UTILS_H*/

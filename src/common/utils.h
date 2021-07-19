//############################# Wi4MPI License ###########################
//# `04/04/2016`                                                         #
//# Copyright or (C) or Copr. Commissariat a l'Energie Atomique          #
//#                                                                      #
//# IDDN.FR.001.210022.000.S.P.2014.000.10800                            #
//# This file is part of the Wi4MPI library.                             #
//#                                                                      #
//# SPDX-License-Identifier: BSD-3-Clause OR CeCILL-B                    #
//#                                                                      #
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

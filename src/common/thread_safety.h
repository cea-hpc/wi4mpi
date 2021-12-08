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

#include <pthread.h>

#ifndef WI4MPI_THREAD_SAFETY_H
#define  WI4MPI_THREAD_SAFETY_H


#define lock_dest(a) pthread_spin_destroy(a)
#define lock_init(a) pthread_spin_init(a,PTHREAD_PROCESS_PRIVATE)
#define lock(a)  pthread_spin_lock(a)
#define unlock(a) pthread_spin_unlock(a)
typedef  pthread_spinlock_t *table_lock_t;

//#define lock_dest(a) 
//#define lock_init(a) 
//#define lock(a)  
//#define unlock(a) 
//typedef  pthread_spinlock_t *table_lock_t;


#endif

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
//#   - Juilly Kevin <kevin.juilly.tgcc@cea.fr>                          #
//#                                                                      #
//########################################################################


#ifndef MANUAL_INTERFACE_H
#define MANUAL_INTERFACE_H
void mpi_init_(int *);

void mpi_init__(int *);

void pmpi_init__(int *);

void pmpi_init_(int *);
#define IF_MPI_Init pmpi_init_
#pragma weak mpi_init_=pmpi_init_
#pragma weak mpi_init__=pmpi_init_
#pragma weak pmpi_init__=pmpi_init_
void (*INTERFACE_F_LOCAL_MPI_Init)(int *);
void  IF_MPI_Init(int *ret)
{
#ifdef DEBUG
printf("input: f_MPI_Init (interface) \n");
#endif
INTERFACE_F_LOCAL_MPI_Init(ret);
#ifdef DEBUG
printf("output: f_MPI_Init (interface) \n");
#endif
}
void mpi_init_thread_(int *);

void mpi_init_thread__(int *);

void pmpi_init_thread__(int *);

void pmpi_init_thread_(int *);
#define IF_MPI_Init_thread pmpi_init_thread_
#pragma weak mpi_init_thread_=pmpi_init_thread_
#pragma weak mpi_init_thread__=pmpi_init_thread_
#pragma weak pmpi_init_thread__=pmpi_init_thread_
void (*INTERFACE_F_LOCAL_MPI_Init_thread)(int *);
void  IF_MPI_Init_thread(int *ret)
{
#ifdef DEBUG
printf("input: f_MPI_Init_thread (interface) \n");
#endif
INTERFACE_F_LOCAL_MPI_Init_thread(ret);
#ifdef DEBUG
printf("output: f_MPI_Init_thread (interface) \n");
#endif
}
#endif /*MANUAL_WRAPPER_H*/

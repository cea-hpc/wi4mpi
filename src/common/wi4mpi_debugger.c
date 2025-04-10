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


#include "engine.h"
#include <stdio.h>
/*
static void dump(void * src, size_t size) {
    unsigned char * tab = (unsigned char*) malloc(size);
    memcpy(tab, src, size);
    size_t i=0;
    for(;i<size;i++)
      fprintf(stderr, "%02X ", tab[i]);
    fprintf(stderr, "\n");
    free(tab);
}
*/

/*  Memcpy if application structure is large enough */
size_t __wi4mpi__temporary__allocated__size;
void *wi4mpi_alloc(size_t size)
{
    size_t *tmp;
    __sync_add_and_fetch(&__wi4mpi__temporary__allocated__size,size);
    tmp=(size_t*)malloc(size+sizeof(size_t));
    tmp[0]=size;
    tmp++;
    return tmp;
}
void wi4mpi_free(void *ptr)
{
    size_t *tmp=(size_t*)ptr;
    tmp--;
    __sync_sub_and_fetch(&__wi4mpi__temporary__allocated__size,tmp[0]);
    return free(tmp);
}
__attribute__((constructor))
void wi4mpi_debug_init(void)
{
    printf("wi4mpi debug/stat mode\n");
    __wi4mpi__temporary__allocated__size=0;
}
int *p_req;
int *counter_request;
int req_size;
#define decl(type, varname)   \
int *counter_##varname=NULL;\
int *p_##varname;\
int varname##_size;
#define stat_string_builder(type,varname) wi4mpi leaked:%d \n /* ## type: %d \n*/
#define str(x) strh(x)
#define strh(x) #x
#define stat_string_printer_inter(type,varname,string) printf(str(string), varname##_size-(p_##varname-counter_##varname+1))
#define  stat_string_printer(type,varname) stat_string_printer_inter(type,varname,stat_string_builder(type,varname))
decl(MPI_Type,datatype);

/* Errhandler */
decl(MPI_Errhandler,errhandler);

/* Op */
decl(MPI_Op,operation);

/* Group */
decl(MPI_Group,group);

/* Win */
decl(MPI_Win,win);

/* Message */
decl(MPI_Message,message);

__attribute__((destructor))
void wi4mpi_debug_finalize(void)
{
    printf("wi4mpi leaked temporary %ld byte \n",__wi4mpi__temporary__allocated__size);
    printf("wi4mpi leaked requests: %d requests not waited, not tested (non bloquing request) or released (presistent request)\n",req_size-(p_req-counter_request+1));
stat_string_printer(MPI_Type,datatype);

/* Errhandler */
stat_string_printer(MPI_Errhandler,errhandler);

/* Op */
stat_string_printer(MPI_Op,operation);

/* Group */
stat_string_printer(MPI_Group,group);

/* Win */
stat_string_printer(MPI_Win,win);

/* Message */
stat_string_printer(MPI_Message,message);
}

/*   True hashtables  */

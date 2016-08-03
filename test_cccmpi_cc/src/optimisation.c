//############################# Wi4MPI License ###########################
//# `04/04/2016`                                                         #
//# Copyright or (C) or Copr. Commissariat a l'Energie Atomique          #
//#                                                                      #
//# IDDN.FR.001.210022.001.S.P.2014.000.10800                            #
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


/*
 *    This program will generate a C header file
 *    containing HASHTABLE_(NO_)OPTI_(mpi structure).
 *    It will check if application MPI structures
 *    have enough place to contain OpenMPI corresponding
 *    structure data.
 *    If it has enough place, it will set OPTI define,
 *    else, it will set NO_OPTI define
 */


#include "app/run_mpi.h"
#include "app/app_mpi.h"
//#include <config.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

    FILE* file;

    //MPI_Init(&argc, &argv);
    if (argc != 2) {
        fprintf(stderr,"Usage: mpirun optimisation <file.h>\n");
        return 1;
    }

    file = fopen(argv[1],"w+");

    fprintf(file, "/**************************************\n");
    fprintf(file, " **** File automatically generated ****\n");
    fprintf(file, " ****        Do not modify         ****\n");
    fprintf(file, " *************************************/\n\n");


    fprintf(file, "#ifndef OPTIMISATION_H\n");
    fprintf(file, "#define OPTIMISATION_H\n\n");

    fprintf(file, "#define HASHTABLE_OPTI_COMMUNICATOR %d\n",
            sizeof(A_MPI_Comm) >= sizeof(R_MPI_Comm) );

    fprintf(file, "#define HASHTABLE_OPTI_DATATYPE %d\n",
            sizeof(A_MPI_Datatype) >= sizeof(R_MPI_Datatype) );

    fprintf(file, "#define HASHTABLE_OPTI_ERRHANDLER %d\n",
            sizeof(A_MPI_Errhandler) >= sizeof(R_MPI_Errhandler) );

    fprintf(file, "#define HASHTABLE_OPTI_GROUP %d\n",
            sizeof(A_MPI_Group) >= sizeof(R_MPI_Group) );

    fprintf(file, "#define HASHTABLE_OPTI_OP %d\n",
            sizeof(A_MPI_Op) >= sizeof(R_MPI_Op) );

    fprintf(file, "#define HASHTABLE_OPTI_REQUEST %d\n",
            sizeof(A_MPI_Request) >= sizeof(R_MPI_Request) );

//#if WRAPPER_MPI_VERSION > 21
    fprintf(file, "#define HASHTABLE_OPTI_FILE %d\n",
            sizeof(A_MPI_File) >= sizeof(R_MPI_File) );

    fprintf(file, "#define HASHTABLE_OPTI_INFO %d\n",
            sizeof(A_MPI_Info) >= sizeof(R_MPI_Info) );
//#endif

    fprintf(file, "\n#endif\n");

    fclose(file);

    //MPI_Finalize();

    return 0;
}

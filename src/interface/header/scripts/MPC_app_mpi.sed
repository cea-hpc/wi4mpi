######################################################
# Apply exceptions for _MPC header app_mpi.          #
#                                                    #
# USAGE : sed -i -f MPC_app_mpi.sed app_mpi.h        #
#                                                    #
# Written by Adrien Cotte <adrien.cotte@eolen.com>   #
######################################################

# Replace missing MPI_ERR_RMA_XXX values by A_MPI_ERR_UNKNOWN
s/\(#define.*A_MPI_ERR_RMA_RANGE\).*/\1             A_MPI_ERR_UNKNOWN/
s/\(#define.*A_MPI_ERR_RMA_ATTACH\).*/\1            A_MPI_ERR_UNKNOWN/
s/\(#define.*A_MPI_ERR_RMA_SHARED\).*/\1            A_MPI_ERR_UNKNOWN/

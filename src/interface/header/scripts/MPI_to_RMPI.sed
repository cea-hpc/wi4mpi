######################################################
# Transform MPI headers to WI4MPI runtime header.    #
#                                                    #
# USAGE : sed -f MPI_to_RMPI.sed mpi.h > run_mpi.h   #
#         sed -f MPI_to_RMPI.sed mpio.h > run_mpio.h #
#                                                    #
# Written by Adrien Cotte <adrien.cotte@eolen.com>   #
######################################################

# MPI to R_MPI
s@\([ \t(*,]\)MPI_@\1R_MPI_@g
s@^MPI_@R_MPI_@g

# MPIX to R_MPIX
s@\([ \t(*,]\)MPIX_@\1R_MPIX_@g
s@^MPIX_@R_MPIX_@g

# MPIO to R_MPIO
s@\([ \t(*,]\)MPIO_@\1R_MPIO_@g
s@^MPIO_@R_MPIO_@g

# PMPI to R_PMPI
s@\([ \t(*,]\)PMPI_@\1R_PMPI_@g
s@^PMPI_@R_PMPI_@g

# PMPIX to R_PMPIX
s@\([ \t(*,]\)PMPIX_@\1R_PMPIX_@g
s@^PMPIX_@R_PMPIX_@g

# Set include "mpi.h" to "run_mpi.h"
s@#include "mpi.h"@#include "run_mpi.h"@

program get_MPI_XXX
  use mpi
  print *, '#define MPI_HOST', MPI_HOST 
  print *, '#define MPI_WTIME_IS_GLOBAL', MPI_WTIME_IS_GLOBAL 
  print *, '#define MPI_IO', MPI_IO 
  print *, '#define MPI_BOTTOM', MPI_BOTTOM 
  print *, '#define MPI_IN_PLACE', MPI_IN_PLACE 
  print *, '#define MPI_UNWEIGHTED', MPI_UNWEIGHTED 
  print *, '#define MPI_WEIGHTS_EMPTY', MPI_WEIGHTS_EMPTY 
  print *, '#define MPI_STATUS_IGNORE', MPI_STATUS_IGNORE 
  print *, '#define MPI_STATUSES_IGNORE', MPI_STATUSES_IGNORE 
end program

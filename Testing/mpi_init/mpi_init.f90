program main
  use mpi
  integer error
  call MPI_Init(error)
  call MPI_Finalize(error)
end program

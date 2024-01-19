program port_client
    use mpi
    implicit none
    integer, parameter :: MAX_DATA = 1
    integer :: server
    double precision:: buf(MAX_DATA)
    integer :: ierr
  character(len=MPI_MAX_PORT_NAME) :: port_name

    buf(1) = 3.14
  call MPI_Init(ierr);
  write(*,*) "starting client"
    call MPI_Barrier(MPI_COMM_WORLD, ierr);
  call MPI_Lookup_name("wii", MPI_INFO_NULL, port_name, ierr);
  call MPI_Comm_connect(port_name, MPI_INFO_NULL, 0, MPI_COMM_SELF, server, ierr);
  call MPI_Send(buf, 1, MPI_DOUBLE_PRECISION, 0, 1, server, ierr);
  call MPI_Comm_disconnect(server, ierr);
  call MPI_Finalize(ierr);
end

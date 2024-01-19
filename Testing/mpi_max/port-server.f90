program port_server
    use mpi
    implicit none
    integer, parameter :: MAX_DATA = 1
    integer :: client
    double precision:: buf(MAX_DATA)
    integer :: ierr
    character(len=MPI_MAX_PORT_NAME) :: port_name
    integer :: statuss(mpi_status_size);

    call MPI_Init(ierr);
    call MPI_Open_port(MPI_INFO_NULL, port_name, ierr);
    write(*,*) "server available at ", trim(port_name)
    call MPI_Publish_name("wii", MPI_INFO_NULL, port_name, ierr);
    call MPI_Barrier(MPI_COMM_WORLD, ierr);
    call MPI_Comm_accept(port_name, MPI_INFO_NULL, 0, MPI_COMM_SELF, client, ierr);
    call MPI_Recv(buf, MAX_DATA, MPI_DOUBLE_PRECISION, MPI_ANY_SOURCE, MPI_ANY_TAG, client, statuss, ierr);
    write(*,*) "server received ", buf(1)
    call MPI_Comm_disconnect(client, ierr);
    call MPI_Unpublish_name("wii", MPI_INFO_NULL, port_name, ierr);
    call MPI_Close_port(port_name, ierr);
    call MPI_Finalize(ierr);
    end

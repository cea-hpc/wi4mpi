program fileview
    use mpi
    implicit none
    integer :: ierr
    integer :: testfile;
    integer(kind=mpi_offset_kind) :: disp
    integer :: etype, ftype
    character(len=MPI_MAX_DATAREP_STRING) :: datarep;

    call MPI_Init(ierr);

    call MPI_File_open(MPI_COMM_WORLD, "test", ior(MPI_MODE_RDWR,MPI_MODE_CREATE), MPI_INFO_NULL, testfile, ierr);
    call MPI_File_get_view(testfile, disp, etype, ftype, datarep, ierr);
    write(*,*) "get view ", trim(datarep);
    call MPI_File_set_view(testfile, disp, etype, ftype, "external32", MPI_INFO_NULL, ierr);
    call MPI_File_get_view(testfile, disp, etype, ftype, datarep, ierr);
    write(*,*) "get view ", trim(datarep);
    call MPI_File_close(testfile, ierr);

    call MPI_Finalize(ierr);
end

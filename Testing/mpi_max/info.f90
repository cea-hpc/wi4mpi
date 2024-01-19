program infokey
    use mpi
    implicit none
    integer :: ierr
    integer :: info
    character(len=249) :: val
    character(len=MPI_MAX_INFO_KEY) :: key
    integer :: vallen
    logical :: flag

    call MPI_Init(ierr);
    call MPI_Info_create(info, ierr);
    call MPI_Info_set(info, "   mama   ", "  mia   ", ierr);
    call MPI_Info_get_nthkey(info, 0, key, ierr);
    write(*,*) "get nth: ", trim(key)
    call MPI_Info_get_valuelen(info, "   mama   ", vallen, flag, ierr);
    write(*,*) "get valuelen: ", vallen
    call MPI_Info_get(info, "   mama   ", 249, val, flag, ierr);
    write(*,*) "get: ", trim(val)
    call MPI_Info_delete(info, "      mama    ", ierr);
    call MPI_Finalize(ierr);
end

program main_calls
    use mpi
    implicit none
    integer :: ierr, leng, errcode
    integer :: testerrclass, testerrcode
    integer :: testcomm
    integer :: testtype
    integer :: mywin
    integer(kind=mpi_address_kind) :: ssize
    character(len=MPI_MAX_PROCESSOR_NAME) :: proc_name
    character(len=MPI_MAX_LIBRARY_VERSION_STRING) :: lib_ver
    character(len=MPI_MAX_ERROR_STRING) :: error_string
    character(len=MPI_MAX_OBJECT_NAME) :: comm_string
    character(len=MPI_MAX_OBJECT_NAME) :: type_string
    character(len=MPI_MAX_OBJECT_NAME) :: win_string

    call MPI_Init(ierr)

    errcode = MPI_ERR_NAME;


    call MPI_Get_processor_name(proc_name, leng, ierr);
    write(*,*) "procname: ", leng, trim(proc_name)
    call MPI_Get_library_version(lib_ver, leng, ierr);
    write(*,*) "libver: ", leng, trim(lib_ver)

    call MPI_Error_string(errcode, error_string, leng, ierr);
    write(*,*) "error: ", errcode, leng, trim(error_string)
    call MPI_Add_error_class(testerrclass, ierr);
    call MPI_Add_error_code(testerrclass, testerrcode, ierr);
    call MPI_Add_error_string(testerrcode, "mouhaha", ierr);
    call MPI_Error_string(testerrcode, error_string, leng, ierr);
    write(*,*) "custom error: ", leng, trim(error_string)

    call MPI_Comm_dup(MPI_COMM_WORLD, testcomm, ierr);
    call MPI_Comm_set_name(testcomm, "my comm", ierr);
    call MPI_Comm_get_name(testcomm, comm_string, leng, ierr);
    write(*,*) "comm name: ", leng, trim(comm_string)
    call MPI_Comm_free(testcomm, ierr);

    call MPI_Type_contiguous(3, MPI_INTEGER, testtype, ierr);
    call MPI_Type_commit(testtype, ierr);
    call MPI_Type_set_name(testtype, "3 integer", ierr);
    call MPI_Type_get_name(testtype, type_string, leng, ierr);
    write(*,*) "type name: ", leng, trim(type_string)
    call MPI_Type_free(testtype, ierr);

    ssize = 3
    call MPI_Win_create(lib_ver, ssize, 1, MPI_INFO_NULL, MPI_COMM_WORLD, mywin, ierr);
    call MPI_Win_set_name(mywin, "test window", ierr);
    call MPI_Win_get_name(mywin, win_string, leng, ierr);
    write(*,*) "win name: ", leng, trim(win_string)
    call MPI_Win_free(mywin, ierr);

    call MPI_Finalize(ierr);
end

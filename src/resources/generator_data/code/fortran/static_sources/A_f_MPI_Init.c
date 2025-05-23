void mpi_init_(int *);

void mpi_init__(int *);

void pmpi_init_(int *);

void pmpi_init__(int *);

void pmpi_init_(int *);

#define A_f_MPI_Init _MPI_Init
#pragma weak mpi_init_ = _MPI_Init
#pragma weak mpi_init__ = _MPI_Init
#pragma weak pmpi_init__ = _MPI_Init
extern unsigned long long WI4MPI_Init_timeout;
extern unsigned int WI4MPI_Init_print;
void (*LOCAL_f_MPI_Init)(int *);

void A_f_MPI_Init(int *ret) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Init_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  LOCAL_f_MPI_Init(&ret_tmp);
  error_r2a(ret, &ret_tmp);

  int wi4mpi_rank;
  R_MPI_Comm_rank(R_MPI_COMM_WORLD, &wi4mpi_rank);
  if (wi4mpi_rank == 0)
#if  defined(_MPC) || defined(_OMPI) || defined(_INTEL)
    fprintf(
        stdout, "You are using Wi4MPI-%s in the interface mode to %s\n",
        getenv("WI4MPI_VERSION"), getenv("WI4MPI_TO"));
#else
    fprintf(
        stdout, "You are using Wi4MPI-%s in the preload mode from %s to %s\n",
        getenv("WI4MPI_VERSION"), getenv("WI4MPI_FROM"), getenv("WI4MPI_TO"));
#endif
  in_w = 0;
#ifdef DEBUG
  if (WI4MPI_Init_print)
    debug_printer("MPI_Init: \n{\nerror/return: %*d\n}\n", ret);
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}


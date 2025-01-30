void mpi_pcontrol_(int *);

void mpi_pcontrol__(int *);

void pmpi_pcontrol_(int *);

void pmpi_pcontrol__(int *);

void pmpi_pcontrol_(int *);

#define A_f_MPI_Pcontrol _PMPI_Pcontrol
#pragma weak mpi_pcontrol_ = _PMPI_Pcontrol
#pragma weak mpi_pcontrol__ = _PMPI_Pcontrol
#pragma weak pmpi_pcontrol__ = _PMPI_Pcontrol
extern unsigned long long WI4MPI_Pcontrol_timeout;
extern unsigned int WI4MPI_Pcontrol_print;
void (*LOCAL_f_MPI_Pcontrol)(int *);

void A_f_MPI_Pcontrol(int *ret) {
#ifdef TIMEOUT_SUPPORT
  wi4mpi_set_timeout(WI4MPI_Pcontrol_timeout);
#endif
  in_w = 1;
  int ret_tmp = 0;

  LOCAL_f_MPI_Pcontrol(&ret_tmp);
  error_r2a(ret, &ret_tmp);

#ifdef DEBUG
  if (WI4MPI_Pcontrol_print)
    debug_printer("MPI_Pcontrol : \n{\nerror/return : %*d\n}\n", ret);
#endif
#ifdef TIMEOUT_SUPPORT
  wi4mpi_unset_timeout();
#endif
}


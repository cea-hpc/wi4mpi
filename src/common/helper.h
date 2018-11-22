#define WI4MPI_MAX_TIME (((long)1)<<63)
#define WI4MPI_TIME_PREC 100
#define helper_sleep usleep(WI4MPI_TIME_PREC)
void wi4mpi_set_timeout(size_t);
void wi4mpi_unset_timeout(void);
void timeout_config_file(void);

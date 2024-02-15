#ifndef __TIMEOUT_HELPER_H__ 
#define __TIMEOUT_HELPER_H__ 1
#define WI4MPI_MAX_TIME (0xffffffffffffffffull)
#define WI4MPI_TIME_PREC 100
#define helper_sleep usleep(WI4MPI_TIME_PREC)
void wi4mpi_set_timeout(unsigned long long);
void wi4mpi_unset_timeout(void);
long long get_freq_multiplier(void);
void timeout_config_file(void);
#endif

/* helper thread for timeout :
 timout is done by comparing current rtdsc value and the addition of rtdsc at
 timeout set + timeout_val the necessary information are stored in a chained
 list managed in a lock free manner

 */
#define _GNU_SOURCE
#include <dlfcn.h>
#include "helper.h"
#include <pthread.h>
#include <signal.h>
#include <stdarg.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sched.h>
#include <stdio.h>
#include <sys/syscall.h>
#include <errno.h>
int gettid(void) { return syscall(SYS_gettid); }
/* data structure to keep information on timeout for each thread, the linked
 * list property is use only by controler thread*/
typedef struct thdat {
  int tid;
  unsigned long long timeout;
  struct thdat *next;
  int active;
} th_reg_list;
int timeout_thread_end;

void* wi4mpi_timeout_main_loop(void *);
void wi4mpi_timeout_thread_register(int th);
unsigned long long gettimestamp(void) {
#ifdef __aarch64__
  int64_t t;
  __asm__ volatile("mrs %0, cntvct_el0" : "=r"(t));
  return t;
#else
  int a, d;
  __asm__ volatile("rdtsc" : "=a"(a), "=d"(d));
  return ((unsigned long long)a) | (((long long)d) << 32);
#endif
}
th_reg_list *last_elt;
/* each thread has a pointer on is own control structure*/
__thread th_reg_list *my_elt;
static pthread_mutex_t mutex_list_lock = PTHREAD_MUTEX_INITIALIZER;
void* wi4mpi_timeout_main_loop(void *felement) {
  int mi, rank;
  /*first list element is the application main thread*/
  pthread_mutex_lock(&mutex_list_lock);
  my_elt = (th_reg_list *)felement;
  pthread_mutex_unlock(&mutex_list_lock);
  unsigned long long next_check = gettimestamp() + 0xfffffu;
  while (!timeout_thread_end) {
    unsigned long long ts = gettimestamp();
    th_reg_list *otmp;
    for (th_reg_list *tmp = my_elt; tmp != NULL; tmp = tmp->next) {
      // check if the thread still exist, for unregistration
      int kret = kill(tmp->tid, 0);
      if (kret == -1 && errno == ESRCH) {
          tmp->active = 0;
      }
      if (tmp->active) {
        if (ts >= tmp->timeout) {
          /* effective timeout kill the responsible thread*/
          char hostname[2048];
          gethostname(hostname, 2048);
          fprintf(stderr, "Wi4MPI error: processus %d on host %s has reached a timeout!\n",
                  getpid(), hostname);

          fflush(stderr);
          kill(tmp->tid, SIGABRT);
          return NULL;
        } else {
          /*this elt reference a thread who had released the slot*/
          /* last position is protected to avoid a data corruption in case of
           * thread register occuring at the same time, if in last position the
           * elt will be released after a new thread registration or at end of
           * this thread */
          if (tmp != last_elt && tmp != my_elt) {
            otmp->next = tmp->next;
            free(tmp);
            tmp = otmp;
          }
        }
        otmp = tmp;
      }
    }
    helper_sleep;
  }
  return NULL;
}

void wi4mpi_set_timeout(unsigned long long timeout_val) {
  // First time the thread does a call to MPI, register it
  if (!my_elt) {
    wi4mpi_timeout_thread_register(gettid());
  }
  /* may need a memfence to ensure that compiler doen't do timeout =
   ts;timeout+=timeout_val; or in the reverse order*/
  unsigned long long ts = gettimestamp();
  unsigned long long ret = ts + timeout_val;
  if (ret <= ts)
    ret = WI4MPI_MAX_TIME;
  my_elt->timeout = ret;
}
void wi4mpi_unset_timeout() { my_elt->timeout = WI4MPI_MAX_TIME; }
void wi4mpi_timeout_thread_register(int th) {
  th_reg_list *tmp;
  my_elt = malloc(sizeof(th_reg_list));
  my_elt->active = 1;
  my_elt->timeout = WI4MPI_MAX_TIME;
  my_elt->tid = th;
  my_elt->next = NULL;
  /* do the insertion in lock free manner the overhead price is paid only once
   * per thread */
  pthread_mutex_lock(&mutex_list_lock);
  tmp = last_elt;
  last_elt = my_elt;
  pthread_mutex_unlock(&mutex_list_lock);
  tmp->next = my_elt;
}
__attribute__((constructor)) void timeout_init(void) {
  pthread_t timeout_thread;
  /*register the main thread */
  pthread_mutex_lock(&mutex_list_lock);
  my_elt = malloc(sizeof(th_reg_list));
  my_elt->active = 1;
  my_elt->next = NULL;
  my_elt->tid = gettid();
  my_elt->timeout = WI4MPI_MAX_TIME;
  last_elt = my_elt;
  /*launch the helper thread*/
  pthread_create(&timeout_thread, NULL, &wi4mpi_timeout_main_loop,
                 (void *)my_elt);
  pthread_mutex_unlock(&mutex_list_lock);
}
double
sctk_atomics_get_timestamp_gettimeofday ()
{
  struct timeval tp;
  gettimeofday (&tp, NULL);
  return tp.tv_usec + tp.tv_sec * 1000000;
}
long long get_freq_multiplier(void)
{
    char *env;
    if(env=getenv("WI4MPI_FREQ_MULT"))
    {   
        return strtoll(env,NULL,10);
    }
    else
    {
    //while(1)
    {
        double dt=sctk_atomics_get_timestamp_gettimeofday();
        long long val=gettimestamp();
        for(int i=0;i<100000;i++)
            rand();
        val=(gettimestamp()-val);
        dt=sctk_atomics_get_timestamp_gettimeofday()-dt;
        val/=dt;
        if(val<6000&&val>100) 
         return val;
    }
    }
}
void timeout_config_file(void) {
  FILE *ff;
  char *buff = (char *)malloc(1024 * sizeof(char));
  long long *vv;
  size_t n = 1024;
  char *fname = getenv("WI4MPI_TIMEOUT_CONFIG_FILE");
  if (!fname)
    return;
  ff = fopen(fname, "r");
  if (!ff)
    return;
  while (getline(&buff, &n, ff) > 0) {
    char *split = &(buff[0]);
    while (*split != '=')
      split++;
    *split = '\0';
    if (vv = dlsym(RTLD_DEFAULT, buff))
      *vv = strtoll(split + 1, NULL, 10);
  }
}

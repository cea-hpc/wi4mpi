/* helper thread for timeout :
 timout is done by comparing current rtdsc value and the addition of rtdsc at timeout set + timeout_val
 the necessary information are stored in a chained list managed in a lock free manner

 */
#include <pthread.h>
#include<stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdarg.h>
#define _GNU_SOURCE
#include <sys/syscall.h>    
#include <sched.h>
#include <stdio.h>
#include "helper.h"
#include <sched.h>
#include <dlfcn.h>
int gettid(void)
{
    return syscall(SYS_gettid);
}
/* data structure to keep information on timeout for each thread, the linked list property is use only by controler thread*/
typedef struct thdat {
    int tid;
    unsigned long long timeout;
    struct thdat *next;
    int active;
} th_reg_list;
int timeout_thread_end;

int wi4mpi_timeout_main_loop(void*);
void wi4mpi_timeout_thread_register(int th);
void wi4mpi_timeout_thread_unregister();
unsigned long long gettimestamp(void)
{
    int a,d;
    __asm__ volatile ("rdtsc":"=a"(a),"=d"(d));
    return ((unsigned long long)a)|(((long long)d)<<32);
}
/*libc clone is a weak symbol of __clone, we use a wrapper function to clone in order to do the registration/unregistration of the threads*/
struct clone_arg
{
    int (*fn)(void *arg);
    void *arg;
};
/*registation wrapper*/
int clone_wrap_fn(void* arg)
{
    int ret;
    struct clone_arg *casted_arg=( struct clone_arg *) arg;
    int (*fn)(void *arg)= casted_arg->fn;
    void *rarg=casted_arg->arg;
    /* can be freed here */
    free(arg);
    /* to avoid registation of timout control thread*/
    if(fn!=(int (*)(void *arg))wi4mpi_timeout_main_loop)
        wi4mpi_timeout_thread_register(gettid());
    ret=fn(rarg);
    /* to avoid unregistation of timout control thread*/
    if(fn!=(int (*)(void *arg))wi4mpi_timeout_main_loop)
        wi4mpi_timeout_thread_unregister();
    return ret;
}
int __clone(int (*fn)(void *arg), void *child_stack, int flags, void *arg,...);
int clone(int (*fn)(void *arg), void *child_stack, int flags, void *arg,...)
{
    int ret;
    pid_t *ptid;
    void *tls;
    pid_t *ctid;
va_list va;
   va_start (va, arg);
    ptid=va_arg(va,pid_t*);
    tls=va_arg(va,void*);
    ctid=va_arg(va,pid_t*);
    /* will be freed in the created thread */
    struct clone_arg *warg=malloc(sizeof(struct clone_arg));
    warg->fn=fn;
    warg->arg=arg;
    ret=__clone(clone_wrap_fn,child_stack,flags,warg,ptid,tls,ctid);
    if(ret==-1)
    {
        /* clone didn't work so wrag hasn't be freed */
        free(warg);
    }
    return ret;
}
th_reg_list *last_elt;
/* each thread has a pointer on is own control structure*/
__thread th_reg_list *my_elt;
static pthread_mutex_t mutex_list_lock = PTHREAD_MUTEX_INITIALIZER;
#include <app_mpi.h>
int wi4mpi_timeout_main_loop(void *felement)
{
    int mi,rank;
    /*first list element is the application main thread*/
    pthread_mutex_lock(&mutex_list_lock);
    my_elt=(th_reg_list*)felement;
    pthread_mutex_unlock(&mutex_list_lock);
    while(!timeout_thread_end){
        unsigned long long ts=gettimestamp();
        th_reg_list *otmp;
        for (th_reg_list *tmp=my_elt;tmp!=NULL;tmp=tmp->next)
        {
            if(tmp->active)
            {
                if (ts>=tmp->timeout){
                    /* effective timeout kill the responsible thread*/
                        char hostname[2048];
                        gethostname(hostname,2048);
                        fprintf(stderr,"processus %d on host %s has reached a timeout\n",getpid(),hostname);
                    
                    fflush(stderr);
                     kill(tmp->tid,SIGABRT);
                    return;
                }
                else
                {
                    /*this elt reference a thread who had released the slot*/
                    /* last position is protected to avoid a data corruption in case of thread register occuring at the same time, if in last position the elt will be released after a new thread registration or at end of this thread */
                    if(tmp!=last_elt&&tmp!=my_elt)
                    {
                        otmp->next=tmp->next;
                        free(tmp);
                        tmp=otmp;
                    }
                }
                otmp=tmp;
            }
        }
        helper_sleep;
    }
    return 0;
}

void wi4mpi_set_timeout(unsigned long long  timeout_val)
{
    /* may need a memfence to ensure that compiler doen't do timeout = ts;timeout+=timeout_val; or
     in the reverse order*/
    unsigned long long ts=gettimestamp();
    unsigned long long ret=ts+timeout_val;
    if(ret<=ts)
        ret=WI4MPI_MAX_TIME;
    my_elt->timeout=ret;
}
void wi4mpi_unset_timeout()
{
    my_elt->timeout=WI4MPI_MAX_TIME;
}
void wi4mpi_timeout_thread_register(int th)
{
    th_reg_list *tmp;
    my_elt=malloc(sizeof(th_reg_list));
    my_elt->active=1;
    my_elt->timeout=WI4MPI_MAX_TIME;
    my_elt->tid=th;
    my_elt->next=NULL;
    /* do the insertion in lock free manner the overhead price is paid only once per thread */
    pthread_mutex_lock(&mutex_list_lock);
    tmp=last_elt;
    last_elt=my_elt;
    pthread_mutex_unlock(&mutex_list_lock);
    tmp->next=my_elt;
}
void wi4mpi_timeout_thread_unregister()
{
    /*effective destruction is done in helper thread to avoid list corruption*/
    my_elt->active=0;
}
__attribute__((constructor)) void timeout_init(void)
{
    pthread_t timeout_thread;
    /*register the main thread */
    pthread_mutex_lock(&mutex_list_lock);
    my_elt=malloc(sizeof(th_reg_list));
    my_elt->active=1;
    my_elt->next=NULL;
    my_elt->tid=gettid();
    my_elt->timeout=WI4MPI_MAX_TIME;
    last_elt=my_elt;
    /*launch the helper thread*/
    pthread_create(&timeout_thread,NULL,&wi4mpi_timeout_main_loop, (void*)my_elt);
    pthread_mutex_unlock(&mutex_list_lock);
}
void timeout_config_file(void)
{   
    FILE *ff;
    char *buff=(char*)malloc(1024*sizeof(char));
    long long *vv;
    int *n;
    char *fname=getenv("WI4MPI_TIMEOUT_CONFIG_FILE");
    if(!fname)
        return;
    ff=fopen(fname,"r");
    if(!ff)
        return;
    while(getline(&buff,&n,ff)>0){
        char *split=&(buff[0]);
        while(*split!='=') split++;
        *split='\0';
        if(vv=dlsym(RTLD_DEFAULT,buff)) *vv=strtoll(split+1,NULL,10);
    }
}

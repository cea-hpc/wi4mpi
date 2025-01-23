void  (*_LOCAL_MPI_Errhandler_create)(void *,int *,int *);
extern int WI4MPI_errhandler_key;
#include "mappers.h"
static void wrapper_handler_function_f(R_MPI_Comm* comm, int* err, ...)
{
    void (*hf)(int *,int *,...);
    A_MPI_Comm comm_tmp;
    int ct;
    int flags;
    
    comm_conv_r2a_static(&comm_tmp,comm);
    //communicator_fn_translation_get(comm_tmp, &hf);
    R_MPI_Comm_get_attr(*comm,WI4MPI_errhandler_key,&hf,&flags);
    printf("coucou errhandler %d %p\n",comm_tmp,comm);
    ct=A_MPI_Comm_c2f(comm_tmp);
if(hf)
    (*hf)(&ct, err, "", NULL);
}
extern int (*LOCAL_MPI_Errhandler_create)(R_MPI_Handler_function*,R_MPI_Errhandler*);
void  A_f_MPI_Errhandler_create(void * function,int * errhandler,int * ret)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Errhandler_create\n");
#endif
//in_w=1;

void *function_tmp=function;
//handler_fct_ptr_conv_a2r(&function,&function_tmp);
in_w=1;                                                                                                              
                                                                                                                     
A_MPI_Errhandler aerrhandler;                                                                                                        
A_MPI_Errhandler *paerrhandler=&aerrhandler;                                                                                                        
ptr_handler_fn=(A_MPI_Handler_function *)function;                                                                   
R_MPI_Errhandler  errhandler_ltmp;                                                                                   
R_MPI_Errhandler * errhandler_tmp=&errhandler_ltmp;                                                                  
int ret_tmp= LOCAL_MPI_Errhandler_create( (R_MPI_Handler_function *)&wrapper_handler_function_f, errhandler_tmp);       
errhandler_ptr_conv_r2a(&(paerrhandler),&errhandler_tmp);
//*errhandler=(int)aerrhandler;
*errhandler=A_MPI_Errhandler_c2f(aerrhandler);
in_w=0;                                                                                                              

/*A_MPI_Errhandler errhandler_tmp;
*ret=A_MPI_Errhandler_create(function,&errhandler_tmp);
*errhandler=(int)errhandler_tmp;
*///in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Errhandler_create %d\n",*errhandler);
#endif
}

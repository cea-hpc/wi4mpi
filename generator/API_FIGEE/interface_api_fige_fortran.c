void  mpi_win_free_keyval_(int *,int *);

void  mpi_win_free_keyval__(int *,int *);

void  pmpi_win_free_keyval_(int *,int *);

void  pmpi_win_free_keyval__(int *,int *);

void  pmpi_win_free_keyval_(int *,int *);

//#define A_f_MPI_Win_free_keyval _PMPI_Win_free_keyval
//#pragma weak mpi_win_free_keyval_=_PMPI_Win_free_keyval
//#pragma weak mpi_win_free_keyval__=_PMPI_Win_free_keyval
//#pragma weak pmpi_win_free_keyval__=_PMPI_Win_free_keyval
void  (*_LOCAL_MPI_Win_free_keyval)(int *,int *);

void  A_f_MPI_Win_free_keyval(int * win_keyval,int * ret)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Win_free_keyval\n");
#endif
in_w=1;
int ret_tmp=0;
int comm=R_f_MPI_COMM_WORLD;
int errorcode=7;
fprintf(stderr, "A_f_MPI_Win_free_keyval Not implemented yet\n");
_LOCAL_MPI_Abort( &comm, &errorcode, &ret_tmp);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Win_free_keyval\n");
#endif
}
void  mpi_win_delete_attr_(int *,int *,int *);

void  mpi_win_delete_attr__(int *,int *,int *);

void  pmpi_win_delete_attr_(int *,int *,int *);

void  pmpi_win_delete_attr__(int *,int *,int *);

void  pmpi_win_delete_attr_(int *,int *,int *);

//#define A_f_MPI_Win_delete_attr _PMPI_Win_delete_attr
//#pragma weak mpi_win_delete_attr_=_PMPI_Win_delete_attr
//#pragma weak mpi_win_delete_attr__=_PMPI_Win_delete_attr
//#pragma weak pmpi_win_delete_attr__=_PMPI_Win_delete_attr
void  (*_LOCAL_MPI_Win_delete_attr)(int *,int *,int *);

void  A_f_MPI_Win_delete_attr(int * win,int * win_keyval,int * ret)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Win_delete_attr\n");
#endif
in_w=1;
int ret_tmp=0;
int comm=R_f_MPI_COMM_WORLD;
int errorcode=7;
fprintf(stderr, "A_f_MPI_Win_delete_attr Not implemented yet\n");
_LOCAL_MPI_Abort( &comm, &errorcode, &ret_tmp);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Win_delete_attr\n");
#endif
}
void  mpi_win_get_attr_(int *,int *,void *,int *,int *);

void  mpi_win_get_attr__(int *,int *,void *,int *,int *);

void  pmpi_win_get_attr_(int *,int *,void *,int *,int *);

void  pmpi_win_get_attr__(int *,int *,void *,int *,int *);

void  pmpi_win_get_attr_(int *,int *,void *,int *,int *);

//#define A_f_MPI_Win_get_attr _PMPI_Win_get_attr
//#pragma weak mpi_win_get_attr_=_PMPI_Win_get_attr
//#pragma weak mpi_win_get_attr__=_PMPI_Win_get_attr
//#pragma weak pmpi_win_get_attr__=_PMPI_Win_get_attr
void  (*_LOCAL_MPI_Win_get_attr)(int *,int *,void *,int *,int *);

void  A_f_MPI_Win_get_attr(int * win,int * win_keyval,void * attribute_val,int * flag,int * ret)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Win_get_attr\n");
#endif
in_w=1;
int ret_tmp=0;
int comm=R_f_MPI_COMM_WORLD;
int errorcode=7;
fprintf(stderr, "A_f_MPI_Win_get_attr Not implemented yet\n");
_LOCAL_MPI_Abort( &comm, &errorcode, &ret_tmp);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Win_get_attr\n");
#endif
}
void  mpi_win_set_attr_(int *,int *,void *,int *);

void  mpi_win_set_attr__(int *,int *,void *,int *);

void  pmpi_win_set_attr_(int *,int *,void *,int *);

void  pmpi_win_set_attr__(int *,int *,void *,int *);

void  pmpi_win_set_attr_(int *,int *,void *,int *);

//#define A_f_MPI_Win_set_attr _PMPI_Win_set_attr
//#pragma weak mpi_win_set_attr_=_PMPI_Win_set_attr
//#pragma weak mpi_win_set_attr__=_PMPI_Win_set_attr
//#pragma weak pmpi_win_set_attr__=_PMPI_Win_set_attr
void  (*_LOCAL_MPI_Win_set_attr)(int *,int *,void *,int *);

void  A_f_MPI_Win_set_attr(int * win,int * win_keyval,void * attribute_val,int * ret)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Win_set_attr\n");
#endif
in_w=1;
int ret_tmp=0;
int comm=R_f_MPI_COMM_WORLD;
int errorcode=7;
fprintf(stderr, "A_f_MPI_Win_set_attr Not implemented yet\n");
_LOCAL_MPI_Abort( &comm, &errorcode, &ret_tmp);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Win_set_attr\n");
#endif
}
void  mpi_win_create_keyval_(void*,void*,int *,void *,int *);

void  mpi_win_create_keyval__(void*,void*,int *,void *,int *);

void  pmpi_win_create_keyval_(void*,void*,int *,void *,int *);

void  pmpi_win_create_keyval__(void*,void*,int *,void *,int *);

void  pmpi_win_create_keyval_(void*,void*,int *,void *,int *);

//#define A_f_MPI_Win_create_keyval _PMPI_Win_create_keyval
//#pragma weak mpi_win_create_keyval_=_PMPI_Win_create_keyval
//#pragma weak mpi_win_create_keyval__=_PMPI_Win_create_keyval
//#pragma weak pmpi_win_create_keyval__=_PMPI_Win_create_keyval
void  (*_LOCAL_MPI_Win_create_keyval)(void*,void*,int *,void *,int *);

void  A_f_MPI_Win_create_keyval(void* win_copy_attr_fn,void* win_delete_attr_fn,int * win_keyval,void * extra_state,int * ret)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Win_create_keyval\n");
#endif
in_w=1;
int ret_tmp=0;
int comm=R_f_MPI_COMM_WORLD;
int errorcode=7;
fprintf(stderr, "A_f_MPI_Win_create_keyval Not implemented yet\n");
_LOCAL_MPI_Abort( &comm, &errorcode, &ret_tmp);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Win_create_keyval\n");
#endif
}
void  mpi_win_create_errhandler_(void*,int *,int *);

void  mpi_win_create_errhandler__(void*,int *,int *);

void  pmpi_win_create_errhandler_(void*,int *,int *);

void  pmpi_win_create_errhandler__(void*,int *,int *);

void  pmpi_win_create_errhandler_(void*,int *,int *);

//#define A_f_MPI_Win_create_errhandler _PMPI_Win_create_errhandler
//#pragma weak mpi_win_create_errhandler_=_PMPI_Win_create_errhandler
//#pragma weak mpi_win_create_errhandler__=_PMPI_Win_create_errhandler
//#pragma weak pmpi_win_create_errhandler__=_PMPI_Win_create_errhandler
void  (*_LOCAL_MPI_Win_create_errhandler)(void*,int *,int *);

void  A_f_MPI_Win_create_errhandler(void* win_errhandler_fn,int * errhandler,int * ret)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Win_create_errhandler\n");
#endif
in_w=1;
int ret_tmp=0;
int comm=R_f_MPI_COMM_WORLD;
int errorcode=7;
fprintf(stderr, "A_f_MPI_Win_create_errhandler Not implemented yet\n");
_LOCAL_MPI_Abort( &comm, &errorcode, &ret_tmp);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Win_create_errhandler\n");
#endif
}
void  mpi_win_call_errhandler_(int *,int *,int *);

void  mpi_win_call_errhandler__(int *,int *,int *);

void  pmpi_win_call_errhandler_(int *,int *,int *);

void  pmpi_win_call_errhandler__(int *,int *,int *);

void  pmpi_win_call_errhandler_(int *,int *,int *);

//#define A_f_MPI_Win_call_errhandler _PMPI_Win_call_errhandler
//#pragma weak mpi_win_call_errhandler_=_PMPI_Win_call_errhandler
//#pragma weak mpi_win_call_errhandler__=_PMPI_Win_call_errhandler
//#pragma weak pmpi_win_call_errhandler__=_PMPI_Win_call_errhandler
void  (*_LOCAL_MPI_Win_call_errhandler)(int *,int *,int *);

void  A_f_MPI_Win_call_errhandler(int * win,int * errorcode,int * ret)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Win_call_errhandler\n");
#endif
in_w=1;
int ret_tmp=0;
int comm=R_f_MPI_COMM_WORLD;
int errorcode_tmp=7;
fprintf(stderr, "A_f_MPI_Win_call_errhandler Not implemented yet\n");
_LOCAL_MPI_Abort( &comm, &errorcode_tmp, &ret_tmp);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Win_call_errhandler\n");
#endif
}
void  mpi_win_set_errhandler_(int *,int *,int *);

void  mpi_win_set_errhandler__(int *,int *,int *);

void  pmpi_win_set_errhandler_(int *,int *,int *);

void  pmpi_win_set_errhandler__(int *,int *,int *);

void  pmpi_win_set_errhandler_(int *,int *,int *);

//#define A_f_MPI_Win_set_errhandler _PMPI_Win_set_errhandler
//#pragma weak mpi_win_set_errhandler_=_PMPI_Win_set_errhandler
//#pragma weak mpi_win_set_errhandler__=_PMPI_Win_set_errhandler
//#pragma weak pmpi_win_set_errhandler__=_PMPI_Win_set_errhandler
void  (*_LOCAL_MPI_Win_set_errhandler)(int *,int *,int *);

void  A_f_MPI_Win_set_errhandler(int * win,int * errhandler,int * ret)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Win_set_errhandler\n");
#endif
in_w=1;
int ret_tmp=0;
int comm_tmp=R_f_MPI_COMM_WORLD;
int errorcode_tmp=7;
fprintf(stderr, "A_f_MPI_Win_set_errhandler Not implemented yet\n");
_LOCAL_MPI_Abort( &comm_tmp, &errorcode_tmp, &ret_tmp);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Win_set_errhandler\n");
#endif
}
void  mpi_win_get_errhandler_(int *,int *,int *);                     
                                                                      
void  mpi_win_get_errhandler__(int *,int *,int *);                    
                                                                      
void  pmpi_win_get_errhandler_(int *,int *,int *);                    
                                                                      
void  pmpi_win_get_errhandler__(int *,int *,int *);                   
                                                                      
void  pmpi_win_get_errhandler_(int *,int *,int *);                    
                                                                      
//#define A_f_MPI_Win_get_errhandler _PMPI_Win_get_errhandler           
//#pragma weak mpi_win_get_errhandler_=_PMPI_Win_get_errhandler         
//#pragma weak mpi_win_get_errhandler__=_PMPI_Win_get_errhandler        
//#pragma weak pmpi_win_get_errhandler__=_PMPI_Win_get_errhandler       
void  (*_LOCAL_MPI_Win_get_errhandler)(int *,int *,int *);            
                                                                      
void  A_f_MPI_Win_get_errhandler(int * win,int * errhandler,int * ret)
{                                                                     
#ifdef DEBUG                                                          
printf("entre : A_f_MPI_Win_get_errhandler\n");                       
#endif                                                                
in_w=1;                                                               
int ret_tmp=0;                                                        
int comm=R_f_MPI_COMM_WORLD;                                          
int errorcode=7;                                                      
fprintf(stderr, "A_f_MPI_Win_get_errhandler Not implemented yet\n");                             
_LOCAL_MPI_Abort( &comm, &errorcode, &ret_tmp);                       
error_r2a(ret,&ret_tmp);                                              
in_w=0;                                                               
#ifdef DEBUG                                                          
printf("sort : A_f_MPI_Win_get_errhandler\n");                        
#endif                                                                
}                                                                     

void  mpi_file_call_errhandler_(int *,int *,int *);

void  mpi_file_call_errhandler__(int *,int *,int *);

void  pmpi_file_call_errhandler_(int *,int *,int *);

void  pmpi_file_call_errhandler__(int *,int *,int *);

void  pmpi_file_call_errhandler_(int *,int *,int *);

//#define A_f_MPI_File_call_errhandler _PMPI_File_call_errhandler
//#pragma weak mpi_file_call_errhandler_=_PMPI_File_call_errhandler
//#pragma weak mpi_file_call_errhandler__=_PMPI_File_call_errhandler
//#pragma weak pmpi_file_call_errhandler__=_PMPI_File_call_errhandler
void  (*_LOCAL_MPI_File_call_errhandler)(int *,int *,int *);

void  A_f_MPI_File_call_errhandler(int * fh,int * errorcode,int * ret)
{
#ifdef DEBUG
printf("entre : A_f_MPI_File_call_errhandler\n");
#endif
in_w=1;
int ret_tmp=0;
int comm=R_f_MPI_COMM_WORLD;
int errorcode_tmp=7;
fprintf(stderr, "A_f_MPI_File_call_errhandler Not implemented yet\n");
_LOCAL_MPI_Abort( &comm, &errorcode_tmp, &ret_tmp);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_File_call_errhandler\n");
#endif
}
void  mpi_file_create_errhandler_(void *,int *,int *);

void  mpi_file_create_errhandler__(void *,int *,int *);

void  pmpi_file_create_errhandler_(void *,int *,int *);

void  pmpi_file_create_errhandler__(void *,int *,int *);

void  pmpi_file_create_errhandler_(void *,int *,int *);

//#define A_f_MPI_File_create_errhandler _PMPI_File_create_errhandler
//#pragma weak mpi_file_create_errhandler_=_PMPI_File_create_errhandler
//#pragma weak mpi_file_create_errhandler__=_PMPI_File_create_errhandler
//#pragma weak pmpi_file_create_errhandler__=_PMPI_File_create_errhandler
void  (*_LOCAL_MPI_File_create_errhandler)(void *,int *,int *);

void  A_f_MPI_File_create_errhandler(void * file_errhandler_fn,int * errhandler,int * ret)
{
#ifdef DEBUG
printf("entre : A_f_MPI_File_create_errhandler\n");
#endif
in_w=1;
int ret_tmp=0;
int comm=R_f_MPI_COMM_WORLD;
int errorcode=7;
fprintf(stderr, "A_f_MPI_File_create_errhandler Not implemented yet\n");
_LOCAL_MPI_Abort( &comm, &errorcode, &ret_tmp);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_File_create_errhandler\n");
#endif
}
void  mpi_type_create_keyval_(void **,void*,int *,void *,int *);

void  mpi_type_create_keyval__(void **,void*,int *,void *,int *);

void  pmpi_type_create_keyval_(void **,void*,int *,void *,int *);

void  pmpi_type_create_keyval__(void **,void*,int *,void *,int *);

void  pmpi_type_create_keyval_(void **,void*,int *,void *,int *);

//#define A_f_MPI_Type_create_keyval _PMPI_Type_create_keyval
//#pragma weak mpi_type_create_keyval_=_PMPI_Type_create_keyval
//#pragma weak mpi_type_create_keyval__=_PMPI_Type_create_keyval
//#pragma weak pmpi_type_create_keyval__=_PMPI_Type_create_keyval
void  (*_LOCAL_MPI_Type_create_keyval)(void **,void*,int *,void *,int *);

void  A_f_MPI_Type_create_keyval(void ** type_copy_attr_fn,void* type_delete_attr_fn,int * type_keyval,void * extra_state,int * ret)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Type_create_keyval\n");
#endif
in_w=1;
int ret_tmp=0;
int comm=R_f_MPI_COMM_WORLD;
int errorcode=7;
fprintf(stderr, "A_f_MPI_Type_create_keyval Not implemented yet\n");
_LOCAL_MPI_Abort( &comm, &errorcode, &ret_tmp);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Type_create_keyval\n");
#endif
}
void  mpi_grequest_complete_(int *,int *);

void  mpi_grequest_complete__(int *,int *);

void  pmpi_grequest_complete_(int *,int *);

void  pmpi_grequest_complete__(int *,int *);

void  pmpi_grequest_complete_(int *,int *);

//#define A_f_MPI_Grequest_complete _PMPI_Grequest_complete
//#pragma weak mpi_grequest_complete_=_PMPI_Grequest_complete
//#pragma weak mpi_grequest_complete__=_PMPI_Grequest_complete
//#pragma weak pmpi_grequest_complete__=_PMPI_Grequest_complete
void  (*_LOCAL_MPI_Grequest_complete)(int *,int *);

void  A_f_MPI_Grequest_complete(int * request,int * ret)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Grequest_complete\n");
#endif
in_w=1;
int ret_tmp=0;
int comm=R_f_MPI_COMM_WORLD;
int errorcode=7;
fprintf(stderr, "A_f_MPI_Grequest_complete Not implemented yet\n");
_LOCAL_MPI_Abort( &comm, &errorcode, &ret_tmp);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Grequest_complete\n");
#endif
}
void  mpi_grequest_start_(void*,void*,void*,void *,int *,int *);

void  mpi_grequest_start__(void*,void*,void*,void *,int *,int *);

void  pmpi_grequest_start_(void*,void*,void*,void *,int *,int *);

void  pmpi_grequest_start__(void*,void*,void*,void *,int *,int *);

void  pmpi_grequest_start_(void*,void*,void*,void *,int *,int *);

//#define A_f_MPI_Grequest_start _PMPI_Grequest_start
//#pragma weak mpi_grequest_start_=_PMPI_Grequest_start
//#pragma weak mpi_grequest_start__=_PMPI_Grequest_start
//#pragma weak pmpi_grequest_start__=_PMPI_Grequest_start
void  (*_LOCAL_MPI_Grequest_start)(void*,void*,void*,void *,int *,int *);

void  A_f_MPI_Grequest_start(void* query_fn,void* free_fn,void* cancel_fn,void * extra_state,int * request,int * ret)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Grequest_start\n");
#endif
in_w=1;
int ret_tmp=0;
int comm=R_f_MPI_COMM_WORLD;
int errorcode=7;
fprintf(stderr, "A_f_MPI_Grequest_start Not implemented yet\n");
_LOCAL_MPI_Abort( &comm, &errorcode, &ret_tmp);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Grequest_start\n");
#endif
}
void  mpi_comm_create_keyval_(void *,void *,int *,void *,int *);

void  mpi_comm_create_keyval__(void *,void *,int *,void *,int *);

void  pmpi_comm_create_keyval_(void *,void *,int *,void *,int *);

void  pmpi_comm_create_keyval__(void *,void *,int *,void *,int *);

void  pmpi_comm_create_keyval_(void *,void *,int *,void *,int *);

//#define A_f_MPI_Comm_create_keyval _PMPI_Comm_create_keyval
//#pragma weak mpi_comm_create_keyval_=_PMPI_Comm_create_keyval
//#pragma weak mpi_comm_create_keyval__=_PMPI_Comm_create_keyval
//#pragma weak pmpi_comm_create_keyval__=_PMPI_Comm_create_keyval
void  (*_LOCAL_MPI_Comm_create_keyval)(void *,void *,int *,void *,int *);

void  A_f_MPI_Comm_create_keyval(void * comm_copy_attr_fn,void * comm_delete_attr_fn,int * comm_keyval,void * extra_state,int * ret)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Comm_create_keyval\n");
#endif
in_w=1;
int ret_tmp=0;
int comm=R_f_MPI_COMM_WORLD;
int errorcode=7;
fprintf(stderr, "A_f_MPI_Comm_create_keyval Not implemented yet\n");
_LOCAL_MPI_Abort( &comm, &errorcode, &ret_tmp);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Comm_create_keyval\n");
#endif
}
void  mpi_comm_free_keyval_(int *,int *);

void  mpi_comm_free_keyval__(int *,int *);

void  pmpi_comm_free_keyval_(int *,int *);

void  pmpi_comm_free_keyval__(int *,int *);

void  pmpi_comm_free_keyval_(int *,int *);

//#define A_f_MPI_Comm_free_keyval _PMPI_Comm_free_keyval
//#pragma weak mpi_comm_free_keyval_=_PMPI_Comm_free_keyval
//#pragma weak mpi_comm_free_keyval__=_PMPI_Comm_free_keyval
//#pragma weak pmpi_comm_free_keyval__=_PMPI_Comm_free_keyval
void  (*_LOCAL_MPI_Comm_free_keyval)(int *,int *);

void  A_f_MPI_Comm_free_keyval(int * comm_keyval,int * ret)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Comm_free_keyval\n");
#endif
in_w=1;
//int ret_tmp=0;
//int comm=R_f_MPI_COMM_WORLD;
//int errorcode=7;
//fprintf(stderr, "Not implemented yet\n");
//_LOCAL_MPI_Abort( &comm, &errorcode, &ret_tmp);
//error_r2a(ret,&ret_tmp);
int  ret_tmp=0;

 //_LOCAL_MPI_Keyval_free( keyval, &ret_tmp);
 _LOCAL_MPI_Comm_free_keyval( comm_keyval, &ret_tmp);
if(ret_tmp==R_f_MPI_SUCCESS)
{
	*comm_keyval=A_MPI_KEYVAL_INVALID;
}

error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Comm_free_keyval\n");
#endif
}
void  mpi_pcontrol_(int *,int *);

void  mpi_pcontrol__(int *,int *);

void  pmpi_pcontrol_(int *,int *);

void  pmpi_pcontrol__(int *,int *);

void  pmpi_pcontrol_(int *,int *);

//#define A_f_MPI_Pcontrol _PMPI_Pcontrol
//#pragma weak mpi_pcontrol_=_PMPI_Pcontrol
//#pragma weak mpi_pcontrol__=_PMPI_Pcontrol
//#pragma weak pmpi_pcontrol__=_PMPI_Pcontrol
void  (*_LOCAL_MPI_Pcontrol)(int *,int *);

void  A_f_MPI_Pcontrol(int * level,int * ret)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Pcontrol\n");
#endif
in_w=1;
//int ret_tmp=0;
//int comm_tmp=R_f_MPI_COMM_WORLD;
//int errorcode_tmp=7;
//fprintf(stderr, "Not implemented yet\n");
//_LOCAL_MPI_Abort( &comm_tmp, &errorcode_tmp, &ret_tmp);
//error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Pcontrol\n");
#endif
*ret = A_MPI_SUCCESS;
return;
}

void  mpi_register_datarep_(char **,void*,void*,void*,void *,int *,int );

void  mpi_register_datarep__(char **,void*,void*,void*,void *,int *, int );

void  pmpi_register_datarep_(char **,void*,void*,void*,void *,int *, int );

void  pmpi_register_datarep__(char **,void*,void*,void*,void *,int *, int );

void  pmpi_register_datarep_(char **,void*,void*,void*,void *,int *, int );

//#define A_f_MPI_Register_datarep _PMPI_Register_datarep
//#pragma weak mpi_register_datarep_=_PMPI_Register_datarep
//#pragma weak mpi_register_datarep__=_PMPI_Register_datarep
//#pragma weak pmpi_register_datarep__=_PMPI_Register_datarep
void  (*_LOCAL_MPI_Register_datarep)(char **,void*,void*,void*,void *,int *, int);

void  A_f_MPI_Register_datarep(char ** datarep,void* read_conversion_fn,void* write_conversion_fn,void* dtype_file_extent_fn,void * extra_state,int * ret, int datarep_len )
{
#ifdef DEBUG
printf("entre : A_f_MPI_Register_datarep\n");
#endif
in_w=1;
int ret_tmp=0;
int comm=R_f_MPI_COMM_WORLD;
int errorcode=7;
fprintf(stderr, "A_f_MPI_Register_datarep Not implemented yet\n");
_LOCAL_MPI_Abort( &comm, &errorcode, &ret_tmp);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Register_datarep\n");
#endif
}

void  mpi_comm_spawn_multiple_(int, char **, char ***, int *, int *, int, int, int *, int *, int *, int, int);

void  mpi_comm_spawn_multiple__(int, char **, char ***, int *, int *, int, int, int *, int *, int *, int, int);

void  pmpi_comm_spawn_multiple_(int, char **, char ***, int *, int *, int, int, int *, int *, int *, int, int);

void  pmpi_comm_spawn_multiple__(int, char **, char ***, int *, int *, int, int, int *, int *, int *, int, int);

void  pmpi_comm_spawn_multiple_(int, char **, char ***, int *, int *, int, int, int *, int *, int *, int, int);

//#define A_f_MPI_Comm_spawn_multiple _PMPI_Comm_spawn_multiple
//#pragma weak mpi_comm_spawn_multiple_=_PMPI_Comm_spawn_multiple
//#pragma weak mpi_comm_spawn_multiple__=_PMPI_Comm_spawn_multiple
//#pragma weak pmpi_comm_spawn_multiple__=_PMPI_Comm_spawn_multiple
void  (*_LOCAL_MPI_Comm_spawn_multiple)(int, char **, char ***, int *, int *, int, int, int *, int *, int *, int, int);

void  A_f_MPI_Comm_spawn_multiple(int count,char **command, char ***argv, int *maxprocs, int *info, int *root, int *comm, int *intercomm, int *array_of_errcodes, int *ret,int command_len, int argv_len)
{
#ifdef DEBUG
printf("entre : A_f_MPI_Comm_spawn_multiple\n");
#endif
in_w=1;
int ret_tmp=0;
int comm_tmp=R_f_MPI_COMM_WORLD;
int errorcode=7;
fprintf(stderr, "A_f_MPI_Comm_spawn_multiple Not implemented yet\n");
_LOCAL_MPI_Abort( &comm_tmp, &errorcode, &ret_tmp);
error_r2a(ret,&ret_tmp);
in_w=0;
#ifdef DEBUG
printf("sort : A_f_MPI_Comm_spawn_multiple\n");
#endif
}

#ifdef WI4MPI_STATIC
#define WATTR
#else
#define WATTR __attribute__((constructor)) 
#endif
WATTR void wrapper_init_f(void) {

char *filename = getenv("WI4MPI_RUN_MPI_F_LIB");
if (!filename) {
   fprintf(stderr , "WI4MPI_RUN_MPI_F_LIB error: undefined variable!\n");
   exit(1);
}

void *lib_handle_f=dlopen(filename,RTLD_NOW|RTLD_GLOBAL);
if (!lib_handle_f) {
   fprintf(stderr , "WI4MPI_RUN_MPI_F_LIB error: %s\n", dlerror());
   exit(1);
}

filename = getenv("WI4MPI_RUN_MPIIO_F_LIB");
if (!filename) {
   fprintf(stderr , "WI4MPI_RUN_MPIIO_F_LIB error: undefined variable!\n");
   exit(1);
}

void *lib_handle_io_f=dlopen(filename,RTLD_NOW|RTLD_GLOBAL);
if (!lib_handle_io_f) {
   fprintf(stderr , "WI4MPI_RUN_MPIIO_F_LIB error: %s\n", dlerror());
   exit(1);
}

/* ABI FIGE */
_LOCAL_MPI_Win_free_keyval=dlsym(lib_handle_f,"pmpi_win_free_keyval_");
_LOCAL_MPI_Win_delete_attr=dlsym(lib_handle_f,"pmpi_win_delete_attr_");
_LOCAL_MPI_Win_get_attr=dlsym(lib_handle_f,"pmpi_win_get_attr_");
_LOCAL_MPI_Win_set_attr=dlsym(lib_handle_f,"pmpi_win_set_attr_");
_LOCAL_MPI_Win_create_keyval=dlsym(lib_handle_f,"pmpi_win_create_keyval_");
_LOCAL_MPI_Win_create_errhandler=dlsym(lib_handle_f,"pmpi_win_create_errhandler_");
_LOCAL_MPI_Win_call_errhandler=dlsym(lib_handle_f,"pmpi_win_call_errhandler_");
_LOCAL_MPI_Win_set_errhandler=dlsym(lib_handle_f,"pmpi_win_set_errhandler_");
_LOCAL_MPI_Win_get_errhandler=dlsym(lib_handle_f,"pmpi_win_get_errhandler_");
_LOCAL_MPI_File_call_errhandler=dlsym(lib_handle_io_f,"pmpi_file_call_errhandler_");
_LOCAL_MPI_File_create_errhandler=dlsym(lib_handle_io_f,"pmpi_file_create_errhandler_");
_LOCAL_MPI_Type_create_keyval=dlsym(lib_handle_f,"pmpi_type_create_keyval_");
_LOCAL_MPI_Grequest_complete=dlsym(lib_handle_f,"pmpi_grequest_complete_");
_LOCAL_MPI_Grequest_start=dlsym(lib_handle_f,"pmpi_grequest_start_");
_LOCAL_MPI_Comm_create_keyval=dlsym(lib_handle_f,"pmpi_comm_create_keyval_");
_LOCAL_MPI_Comm_free_keyval=dlsym(lib_handle_f,"pmpi_comm_free_keyval_");
_LOCAL_MPI_Register_datarep=dlsym(lib_handle_f,"pmpi_register_datarep_");
_LOCAL_MPI_Comm_spawn_multiple=dlsym(lib_handle_f,"pmpi_comm_spawn_multiple_");
_LOCAL_MPI_Pcontrol=dlsym(lib_handle_f,"pmpi_pcontrol_");
/* --- */

#include <stdio.h>
#include <string.h>
#include "app_mpi.h"
#include <stdarg.h>
int debug_act;

void debug_printer(const char *ctr_str,...)
{
    if(debug_act!=0)
{
    int len=strlen(ctr_str);
    char print_str[4096];
    
    va_list ap;
    int it,i;
    va_start(ap,ctr_str);
    int pointer_disp;
    it=0;i=0;
    while(ctr_str[it]!='\0')
    {
        print_str[i]=ctr_str[it];
        if(ctr_str[it]=='%')
        {
            int to_dec;
            print_str[i]='\0';
            printf("%s",print_str);
            pointer_disp=0;
            to_dec=1;
            void *parg;
            while(to_dec)
            {
                    char cname[2048];int namelen;
                it++;
                to_dec=0;
                nb_elt=1;
            switch (ctr_str[it]){
                case '*':
                    pointer_disp++;
                    to_dec=1;    
                    break;
                case 'n':
                    if(nb_elt==1)
                    print_status(pointer_disp?*va_arg(ap,A_MPI_Status *):va_arg(ap,A_MPI_Status));
                    else
                    {
                    A_MPI_Status *s=pointer_disp?*va_arg(ap,A_MPI_Status **):va_arg(ap,A_MPI_Status*);
                    printf("[\n");
                    for(ii=0;ii<nb_elt;ii++)
                    {if(!ii) printf(",");print_status(s[ii]);}
                    printf("]\n");
                    }
                    break;
                case 'd':
                    if(nb_elt==1)
                    printf("%d",pointer_disp?*(va_arg(ap,int*)):(va_arg(ap,int)));
                    else
                    {
                    int *s=pointer_disp?*va_arg(int **):va_arg(ap,int*);
                    printf("[\n");
                    for(ii=0;ii<nb_elt;ii++)
                    {if(ii) printf(",\n%d",s[ii]);else printf("%d",s[ii]);}
                    printf("]\n");
                    }
                    break;
                case 'D':
                     A_MPI_Datatype dat=pointer_disp?*(va_arg(ap,A_MPI_Datatype*)):(va_arg(ap,A_MPI_Datatype));
                    debug_act=0;
                    A_MPI_Type_get_name(dat,&cname[0],&namelen);
                    debug_act=1;
                    printf("{ \nvalue :%p ,\n name: %s\n}",dat,cname);
                    break; 
                case 'a':
                    nb_elt=va_arg(ap,int);
                    
                    break;
                //case 's':
                //    printf("%s",pointer_disp?*(va_arg(ap,char **)):va_arg(ap,char*));
                //    break;
                case 'C':
                    A_MPI_Comm cc=pointer_disp?*(va_arg(ap,A_MPI_Comm*)):(va_arg(ap,A_MPI_Comm));
                    debug_act=0;
                    A_MPI_Comm_get_name(cc,&cname[0],&namelen);
                    debug_act=1;
                    printf("{ \nvalue :%p ,\n name: %s\n}",cc,cname);
                    break; 
               default:
                    va_arg(ap,void*);
                    break;
            }
            }
            i=-1;
        }
        i++;
        it++;
    } 
    print_str[i]='\0';
    printf("%s",print_str);
    va_end(ap);       
    
}}
__attribute__((constructor)) void init_debug(void)
{
    debug_act=1;
}
void print_status(A_MPI_Status stat)
{
    printf("{ source :%d, tag : %d ,error :%d}",stat.A_MPI_SOURCE,stat.A_MPI_TAG,stat.A_MPI_ERROR);
}

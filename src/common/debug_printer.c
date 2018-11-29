#include <stdio.h>
#include <string.h>
#include "app_mpi.h"
#include <stdarg.h>
void debug_printer(const char *ctr_str,...)
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
                it++;
                to_dec=0;
            switch (ctr_str[it]){
                case '*':
                    pointer_disp++;
                    to_dec=1;    
                    break;
                case 'n':
                    print_status(pointer_disp?*va_arg(ap,A_MPI_Status *):va_arg(ap,A_MPI_Status));
                    break;
                case 'd':
                    printf("%d",pointer_disp?*(va_arg(ap,int*)):(va_arg(ap,int)));
                    break;
                //case 's':
                //    printf("%s",pointer_disp?*(va_arg(ap,char **)):va_arg(ap,char*));
                //    break;
                case C:
                    A_MPI_Comm cc=pointer_disp?*(va_arg(ap,A_MPI_Comm*)):(va_arg(ap,A_MPI_Comm));
                    char cname[2048];int namelen;
                    A_MPI_Comm_get_name(cc,&cname[0],&namelen);
                    printf("%p : %s",cc,cname);
                default:
                    va_arg(ap,void*);
                    it++;
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
    
}
void print_status(A_MPI_Status stat)
{
    printf("{ source :%d, tag : %d ,error :%d}",stat.A_MPI_SOURCE,stat.A_MPI_TAG,stat.A_MPI_ERROR);
}

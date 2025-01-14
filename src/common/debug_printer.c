#define __mpi_interface_removed__(a,b) /* __mpi_interface_removed__(a,b) */
#include "app_mpi.h"
#include "wrapper_f.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
__thread int debug_act;
unsigned int WI4MPI_debug_max_array_elt;
void A_f_MPI_Type_get_name(int *,char *,int *,int *);
void A_f_MPI_Comm_get_name(int *,char *,int *,int *);
void print_status(A_MPI_Status);
void print_status_f(int *stat);
#define min(a, b) ((a) < (b) ? (a) : (b))
#define eprintf(...) printf(__VA_ARGS__)
#define print_array(nb_elt, print_function)                                    \
  eprintf("[\n");                                                              \
  for (ii = 0; ii < min(nb_elt, WI4MPI_debug_max_array_elt); ii++) {           \
    if (ii)                                                                    \
      eprintf(",");                                                            \
    print_function;                                                            \
  }                                                                            \
  if (ii == WI4MPI_debug_max_array_elt)                                        \
    eprintf(",...");                                                           \
  for (ii = nb_elt - WI4MPI_debug_max_array_elt; ii < nb_elt; ii++) {          \
    eprintf(",");                                                              \
    print_function;                                                            \
  }                                                                            \
  eprintf("\n]\n");

#define print_named(elt, name_function, print_str)                             \
  name_function(elt, cname, &namelen);                                         \
  eprintf("{ value: " #print_str ",name :%s}", elt, cname);
#define print_named_f(elt, name_function, print_str)                           \
  name_function(&elt, cname, &namelen, &err);                             \
  cname[namelen] = '\0';                                                       \
  eprintf("{ value: " #print_str ",name :%s}", elt, cname);

#define print_type(type, printf_string)                                        \
  if (nb_elt == 0)                                                             \
    eprintf(#printf_string,                                                    \
            pointer_disp ? *(va_arg(ap, type *)) : (va_arg(ap, type)));        \
  else {                                                                       \
    type *s = pointer_disp ? *va_arg(ap, type **) : va_arg(ap, type *);        \
    print_array(nb_elt, eprintf(#printf_string, s[ii]))                        \
  }

#define print_named_type(type, printf_string, func)                            \
  debug_act = 0;                                                               \
  if (nb_elt == 0) {                                                           \
    type dat = pointer_disp ? *(va_arg(ap, type *)) : (va_arg(ap, type));      \
    print_named(dat, func, printf_string);                                     \
  } else {                                                                     \
    type *s = pointer_disp ? *va_arg(ap, type **) : va_arg(ap, type *);        \
    print_array(nb_elt, print_named(s[ii], func, printf_string));              \
  }                                                                            \
  debug_act = 1;

#define print_named_type_f(type, printf_string, func)                          \
  debug_act = 0;                                                               \
  if (nb_elt == 0) {                                                           \
    int err;                                                                   \
    type dat = pointer_disp ? *(va_arg(ap, type *)) : (va_arg(ap, type));      \
    print_named_f(dat, func, printf_string);                                   \
  } else {                                                                     \
    type *s = pointer_disp ? *va_arg(ap, type **) : va_arg(ap, type *);        \
    print_array(nb_elt, print_named_f(s[ii], func, printf_string));            \
  }                                                                            \
  debug_act = 1;
void debug_printer(const char *ctr_str, ...) {
  if (debug_act != 0) {
    int len = strlen(ctr_str);
    char print_str[4096];

    va_list ap;
    int it, i, ii;
    va_start(ap, ctr_str);
    int pointer_disp;
    it = 0;
    i = 0;
    while (ctr_str[it] != '\0') {
      int nb_elt = 0;
      print_str[i] = ctr_str[it];
      if (ctr_str[it] == '%') {
        int to_dec;
        print_str[i] = '\0';
        eprintf("%s", print_str);
        pointer_disp = 0;
        to_dec = 1;
        void *parg;
        while (to_dec) {
          char cname[2048];
          int namelen;
          it++;
          to_dec = 0;
          switch (ctr_str[it]) {
          case '*':
            pointer_disp++;
            to_dec = 1;
            break;
          case 'n':
            if (nb_elt == 0)
              print_status(pointer_disp ? *va_arg(ap, A_MPI_Status *)
                                        : va_arg(ap, A_MPI_Status));
            else {
              A_MPI_Status *s = pointer_disp ? *va_arg(ap, A_MPI_Status **)
                                             : va_arg(ap, A_MPI_Status *);
              print_array(nb_elt, print_status(s[ii]));
            }
            break;
          case 'd':
            if (nb_elt == 0)
              eprintf("%d",
                      pointer_disp ? *(va_arg(ap, int *)) : (va_arg(ap, int)));
            else {
              int *s = pointer_disp ? *va_arg(ap, int **) : va_arg(ap, int *);
              print_array(nb_elt, eprintf("%d", s[ii]))
            }
            break;
          case 'D':
            print_named_type(A_MPI_Datatype, % p, A_MPI_Type_get_name) break;
          case 'a':
            nb_elt = va_arg(ap, int);
            to_dec = 1;
            break;
          case 's':
            print_type(char *, % s) break;
          case 'C':
            print_named_type(A_MPI_Comm, % p, A_MPI_Comm_get_name) break;
          case 'p':
            print_type(void *, % p) break;
          default:
            va_arg(ap, void *);
            break;
          }
        }
        i = -1;
      }
      i++;
      it++;
    }
    print_str[i] = '\0';
    printf("%s", print_str);
    va_end(ap);
  }
}
void debug_printer_f(const char *ctr_str, ...) {
  if (debug_act != 0) {
    int len = strlen(ctr_str);
    char print_str[4096];

    va_list ap;
    int it, i, ii, err;
    va_start(ap, ctr_str);
    int pointer_disp;
    it = 0;
    i = 0;

    while (ctr_str[it] != '\0') {
      int nb_elt = 0;
      print_str[i] = ctr_str[it];
      if (ctr_str[it] == '%') {
        int to_dec;
        print_str[i] = '\0';
        eprintf("%s", print_str);
        pointer_disp = 0;
        to_dec = 1;
        void *parg;
        while (to_dec) {
          char cname[2048];
          int namelen;
          it++;
          to_dec = 0;
          switch (ctr_str[it]) {
          case '*':
            pointer_disp++;
            to_dec = 1;
            break;
          case 'n':
            if (nb_elt == 0)
              print_status_f(pointer_disp ? *va_arg(ap, int **)
                                          : va_arg(ap, int *));
            else {
              int *s = pointer_disp ? *va_arg(ap, int **) : va_arg(ap, int *);
              eprintf("[\n");
              for (ii = 0; ii < nb_elt; ii++) {
                if (!ii)
                  eprintf(",");
                print_status_f(&s[ii * A_f_MPI_STATUS_SIZE]);
              }
              eprintf("]\n");
            }
            break;
          case 'd':
            if (nb_elt == 0)
              eprintf("%d",
                      pointer_disp ? *(va_arg(ap, int *)) : (va_arg(ap, int)));
            else {
              int *s = pointer_disp ? *va_arg(ap, int **) : va_arg(ap, int *);
              eprintf("[\n");
              for (ii = 0; ii < nb_elt; ii++) {
                if (ii)
                  eprintf(",\n%d", s[ii]);
                else
                  eprintf("%d", s[ii]);
              }
              eprintf("]\n");
            }

            // print_type(int,%d)
            break;
          case 'D':
            print_named_type_f(int, % d, A_f_MPI_Type_get_name);
            break;
          case 'a':
            nb_elt = va_arg(ap, int);
            to_dec = 1;
            break;
          case 's':
            print_type(char *, % s) break;
          case 'C':
            print_named_type_f(int, % d, A_f_MPI_Comm_get_name) break;
          case 'p':
            print_type(void *, % p) break;
          default:
            va_arg(ap, void *);
            break;
          }
        }
        i = -1;
      }
      i++;
      it++;
    }
    print_str[i] = '\0';
    eprintf("%s", print_str);
    va_end(ap);
  }
}

__attribute__((constructor)) void init_debug(void) {
  char *tmp;
  debug_act = 1;
  WI4MPI_debug_max_array_elt = 0xFFFFFFFF;
  if (tmp = getenv("WI4MPI_DEBUG_MAX_ARRAY"))
    WI4MPI_debug_max_array_elt = strtol(tmp, NULL, 10);
}
void print_status(A_MPI_Status stat) {
  eprintf("{ source :%d, tag : %d ,error :%d}", stat.A_MPI_SOURCE,
          stat.A_MPI_TAG, stat.A_MPI_ERROR);
}

void print_status_f(int *stat) {

  eprintf("{ source :%d, tag : %d ,error :%d}", stat[A_f_MPI_SOURCE],
          stat[A_f_MPI_TAG], stat[A_f_MPI_ERROR]);
}

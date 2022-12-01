.. role:: raw-latex(raw)
   :format: latex
..

Developer Guide
***************

Introduction
============

MPI is a standard in HPC community which allows a simple use of
clusters. Nowadays, there are several implementation (OpenMPI, BullxMPI,
MPT, IntelMPI, MPC, ...) each of which involves a specific ABI
(Application Binary Interface) for an application compiled with a
specific MPI implementation. With wi4mpi, an application compiled with
an alpha MPI implementation can be run under a beta MPI implementation
without any compilation protocol and any concern about the ABI (Preload
version). WI4MPI can also be seen as a dedicated MPI implementation;
This time, the application is compiled against the wi4mpi library
(libmpi.so) with the dedicated wrapper (mpicc,mpif90...) meant for that
purpose, and can be run under any other MPI implementation (Interface
Version).

Library
=======

How it works
------------

Before performing any translation we need to distinguish the application
side from the runtime side. To do that, any MPI object from the
application side are prefixed by A\_ and those from the application are
prefixed by R\_. To perform a translation, all original MPI call from
the application is intercepted by WI4MPI and replaced by the same call
prefixed by A\_. For example, with an OpenMPI ---> IntelMPI conversion.

.. code-block::

    Application: MPI_Init (OpenMPI)                         MPI_Init (IntelMPI)
                                  \                         ^
                          Phase 1  \                       /  Phase 3
                                    v                     /
                                    |--------------------|
                                    | WI4MPI: A_MPI_Init |
                                    |--------------------|
                                              ^
                                              | Phase 2 
                                              v 
                                          Translation

Implementation
--------------

Library settings
~~~~~~~~~~~~~~~~

The library is set during its loading time, when the program start. All
runtime MPI routines are saved in function pointer via dlsym call to
make phase 3 possible, all the table are created and set with MPI
constant object, and the spinlocks are initialized. To do so, we used
the following syntax:

.. code-block:: c++

    void **attribute** ((constructor)) wrapper_init {

        void (*)lib_handle=dlopen(getenv("WI4MPI_RUN_MPI_C_LIB"),RTLD_NOW); 
        LOCAL_MPI_Function=dlsym(lib_handle,"PMPI_Function") 
        ....
    }

The library contain three constructor:

-  wrapper\_init in test\_generation\_wrapper.c (API C) (preload and
   interface)
-  wrapper\_init\_f in wrapper.c (API Fortran) (preload and interface)
-  wrapper\_init\_c2ff2c in c2f\_f2c.c (API c2f/f2c)

Symbol overload
~~~~~~~~~~~~~~~

The mpi called are intercept thanks to the following rerouting:

-  #define A\_MPI\_Send PMPI\_Send
-  #pragma weak MPI\_Send=PMPI\_Send

(See interface\_test.c in src/interface/gen/interface\_test.c and
src/interface/gen/interface\_fort.c) This syntax is also present but
hidden in test\_generation\_wrapper.c (src/{preload,interface}/gen/)
within an asm code chooser for the next reason.

The MPI-IO implementation (ROMIO) present within the most MPI
implementation trigger some call to the MPI user interface that WI4MPI
intercept thanks to its symbols overload protocol. It means that during
the runtime (phase 3 above), some MPI calls are made, forcing WI4MPI to
intercept them and so making the application to crash. The crash is die
to the fact that WI4MPI MPI is trying to convert runtime argument to
runtime version.

Example:

.. code-block::

    Application:MPI_File_open (OpenMPI)                           MPI_File_open(IntelMPI)
                                 \                               ^                      \
                  Phase 1         \                             /         Phase 3        \
                                   v                           /                          v
                                    |-------------------------|                      |----------------------------------------------------|
                                    | WI4MPI: A_MPI_File_open |                      | WI4MPI: A_MPI_Allreduce but with runtime arguments |
                                    |-------------------------|                      | instead of application arguments (R_ instead of A_)|
                                                ^                                    |----------------------------------------------------|
                                                |   Phase 2                                                     |
                                                v                                                               v
                                           Translation                                                     Translation ----> Crash

To overcome this issue, we used an ASM code chooser.

Code chooser ASM
~~~~~~~~~~~~~~~~

The ASM code chooser does the simple following things:

If we already are in the wrapper:

-  The arguments are passed without any translation protocol to the
   underlying MPI runtime call (LOCAL\_MPI\_function)

Otherwise:

-  The arguments are translated and passed to the underlying MPI runtime
   call (LOCAL\_MPI\_function)

To know which state the process is, we defined the in\_w variable:

-  in\_w=1 : in the wrapper
-  in\_w=0 : in the application

Since the implementation of MPI objects are developer dependent, some of
these may have different size among the different one. To make sure that
there is no side effect, the code chooser analyze the stack itself.

ASM Code chooser implementation (generated for each function):

.. code-block:: asm

    .global PMPI_Function                   # Define global PMPI_Function symbol
    .weak MPI_Function                      # Define a weak MPI_Function symbol
    .set MPI_function,PMPI_Function         # Set contents of MPI_function to PMPI_Function
    .extern in_w
    .extern A_MPI_Function
    .extern R_MPI_Function
    .type PMPI_Function,@function           # Set PMPI_Function type to function
    .text
    PMPI_Function:
    push %rbp
    mov %rsp, %rbp
    ; ------------- Put arguments on stack for safekeeping
    sub $0x20, %rsp
    mov %rdi, -0x8(%rbp)
    mov %rsi, -0x10(%rbp)
    mov %rdx, -0x18(%rbp)
    mov %rcx, -0x20(%rbp)
    ; ------------- Access thread-local variable in_w
    .byte 0x66
    leaq in_w@tlsgd(%rip), %rdi             # Load address of in_w into %rdi
    .value 0x6666
    rex64
    call __tls_get_addr@PLT                 # Get contents of address in %rdi into %rax
    ; ------------- Put arguments back where we found them
    mov -0x8(%rbp), %rdi
    mov -0x10(%rbp), %rsi
    mov -0x18(%rbp), %rdx
    mov -0x20(%rbp), %rcx
    leave                                   # Set %rsp to %rbp, then pop top of stack into %rbp
    ; ------------ Jump to the target function
    cmpl $0x0, 0x0(%rax)
    jne inwrap_MPI_Function
    jmp (*)A_MPI_Function@GOTPCREL(%rip)    # If not in wrapper call application method
    inwrap_MPI_Function:
    jmp (*)R_MPI_Function@GOTPCREL(%rip)    # If in wrapper call run method
    ; ------------ Calculate symbol size
    .size PMPI_Function,.-PMPI_Function     # Declares symbol size to be the size of the above

.. code-block::

    Application:MPI_File_open (OpenMPI)                           MPI_File_open(IntelMPI)
                                 \                               ^                      \
                  Phase 1         \                             /         Phase 3        \
                                   v                           /                          v
                                    |-------------------------|                     |-------------------------|
                                    | WI4MPI: PMPI_File_open  |                     | WI4MPI: PMPI_Allreduce  |
                                    | Testing in_w: in_w=0    |                     | Testing in_w: in_w=1    |
                                    |-------------------------|                     | ------------------------|
                                               ^    Phase 2                                      |
                                               |                                                 |
                                               v                                                 v
                                    A_MPI_File_open:Translation                     R_MPI_Allreduce:No Translation

A\_MPI\_Function
~~~~~~~~~~~~~~~~

All translations are executed thanks to some mappers defined within
mappers.h using an underlying hash table mechanism named uthash
(https://troydhanson.github.io/uthash/) The mappers (see example below)
always have the same syntax :

-  mapper\_name\_a2r/r2a(&buf, &buf\_tmp);

In case of an a2r translation, buf\_tmp represent the translation of buf
and vice versa for an r2a translation.

Example:

.. code-block:: c++

    A_MPI_Send(void * buf,int count,A_MPI_Datatype datatype,int dest,int tag,A_MPI_Comm comm)
    {
        void * buf_tmp;
        const_buffer_conv_a2r(&buf,&buf_tmp); **mapper**
        R_MPI_Datatype datatype_tmp;
        datatype_conv_a2r(&datatype,&datatype_tmp); **mapper**
        int dest_tmp;
        dest_conv_a2r(&dest,&dest_tmp); **mapper**
        int tag_tmp;
        tag_conv_a2r(&tag,&tag_tmp); **mapper**
        R_MPI_Comm comm_tmp;
        comm_conv_a2r(&comm,&comm_tmp); **mapper**
        int ret_tmp= LOCAL_MPI_Send( buf_tmp, count, datatype_tmp, dest_tmp, tag_tmp, comm_tmp); **Runtime MPI_Send call**
        return error_code_conv_r2a(ret_tmp); 
    }

R\_MPI\_Function
~~~~~~~~~~~~~~~~

R\_MPI\_Function, the arguments are directly passed to the MPI runtime
call

.. code-block:: c++

    int R_MPI_Send(void * buf,int count,R_MPI_Datatype datatype,int dest,int tag,R_MPI_Comm comm) {

        int ret_tmp= LOCAL_MPI_Send( buf, count, datatype, dest, tag, comm);

        return ret_tmp;
    }

Hash table
~~~~~~~~~~

The underlying hash table mechanism presented earlier are contained in
the new\_utils.\*, new\_utils\_fn.\* and utash.h. For each MPI objects,
two tables are created. One for the constants, and one for the MPI\_Type
created by the application.

The different type being:

-  MPI\_Comm
-  MPI\_Datatype
-  MPI\_Errhandler
-  MPI\_Group
-  MPI\_Op
-  MPI\_Request **Split en 2 tables, in order to dissociate the requests
   blocking from requests non-blocking**
-  MPI\_File

The table within new\_utils\_fn.\* contain the following translation:

-  MPI\_Handler\_function
-  MPI\_Comm\_copy\_attr\_function
-  MPI\_Comm\_delete\_function
-  MPI\_Type\_delete\_function
-  MPI\_Comm\_errhandler\_function
-  MPI\_File\_errhandler\_function

Thread safety
~~~~~~~~~~~~~

To make WI4MPI usable in a multithread environment, the in\_w (see above) variable is TLS protected.

-  \_\_thread int in\_w=0; (test\_wrapper\_generation.c:118)
-  extern \_\_thread int in\_w; (wrapper.c:7)
-  extern \_\_thread int in\_w; (c2f\_f2c.c:6) \|\| (c2f\_f2c.c:1149)

The table are spinlock protected. (cf :thread\_safety.h):

-  #define lock\_dest(a) pthread\_spin\_destroy(a)
-  #define lock\_init(a) pthread\_spin\_init(a,PTHREAD\_PROCESS\_PRIVATE)
-  #define lock(a) pthread\_spin\_lock(a)
-  #define unlock(a) pthread\_spin\_unlock(a)
-  typedef pthread\_spinlock\_t (\*)table\_lock\_t;

Interface
---------

The interface version of WI4MPI propose the promise as the preload
version (one compilation, several run over different MPI
implementation), but this time WI4MPI had to be seen as a fully MPI
Library. All the previously section are still relevant for the
interface, the only things that changed is the new level name INTERFACE
(see the schema below). This level has to be considered as a "libmpi.so"
which is linked to the user application.

.. code-block::

              dlopen|----------|  dlopen       |---------|
                   /| Lib_OMPI | ----------- > | OpenMPI |
                  / |----------|               |---------|
   |-----------| /
   |           |/
   | INTERFACE |
   | libmpi.so |\
   |-----------| \
                  \
                   \|----------|  dlopen       |----------|
                    | Lib_IMPI | ----------- > | IntelMPI |
              dlopen|----------|               |----------|


The files interface\_test.c and interface\_fort.c, deal with the
overload symbol mechanism see earlier for respectively the C and Fortran
API, then according the conversion a dlopen is made to the appropriate
library (WI4MPI\_WRAPPER\_LIB) responsible for the translation (ASM code
chooser + A\_MPI\_Function + R\_MPI\_Function).

MPI\_Init example

.. code-block:: c++

    int MPI_Init(int * argc,char *** argv);
    #define MPI_Init PMPI_Init
    #pragma weak MPI_Init=PMPI_Init
    int (*INTERFACE_LOCAL_MPI_Init)(int *,char ***);
    
    int PMPI_Init(int * argc,char *** argv)
    {
    int ret_tmp= INTERFACE_LOCAL_MPI_Init( argc, argv);
    return ret_tmp;
    }
    __attribute__((constructor)) void wrapper_interface(void) {
    void *interface_handle=dlopen(getenv("WI4MPI_WRAPPER_LIB"),RTLD_NOW|RTLD_GLOBAL);
    if(!interface_handle)
    {
        printf("no true IC lib defined\nerror :%s\n",dlerror());
        exit(1);
    }
    INTERFACE_LOCAL_MPI_Init=dlsym(interface_handle,"CCMPI_MPI_Init");
    }

#*

Static mode
-----------

The static mode builds an executable with every targets translation. To
avoid conflicts, symbols are renamed as follow:
INTERF2\_{TARGET}\_{Symbol\_name}. No more dlopen is needed (cf.
Interface), functions pointer are choosen by 2 variables:
WI4MPI\_STATIC\_TARGET\_TYPE\_F and WI4MPI\_STATIC\_TARGET\_TYPE. Static
sections are controlled by directives: #if(n)def WI4MPI\_STATIC / #endif

Common files for both version of WI4MPI:

- func_char_fort.*:

    Contain all Fortran MPI functions that deal with some character arguments.
    Since in Fortran a character argument always reference is len (character(len=*) :: dark_side) and since the len argument is not the same size according to the compiler (Intel/GNU < 8 or GNU >= 8) used,
    WI4MPI had to implement both.

    Example:

.. code-block:: c++

           #ifdef IFORT_CALL
                  void  A_f_MPI_Get_processor_name(char * name,int * resultlen,int * ret,int namelen) **The character length is of type int**
           #elif GFORT_CALL
                  void  A_f_MPI_Get_processor_name(char * name,int * resultlen,int * ret,size_t namelen) **The character length is of type size_t**
           #endif

- manual_wrapper.h: Contain some manual mappers for Fortran translation
- mappers.h: Contain the a2r/r2a mappers for C translation
- engine.*, engine_fn.*, and uthash.h: Contain all table routines
- thread_safety.h: Contain the spinlock protection

Preload files:

-  bin/{wi4mpi,mpirun}: see User\_Guide
-  etc/wi4mpi.cfg: see User\_Guide
-  gen:

   -  c2f\_f2c.c:
   -  lib\_empty.c: Empty file to create empty Libraries made to
      replace the one from MPI use for the compilation
   -  test\_generation\_wrapper.c: contain all C MPI function within
      WI4MPI which deal with the translation
   -  wrapper.c: contain all the Fortran MPI function within WI4MPI
      which deal with the translation

-  header:

   -  INTEL\_INTEL: app\_mpi.h app\_mpio.h run\_mpi.h run\_mpio.h
      wrapper\_f.h
   -  INTEL\_OMPI: app\_mpi.h app\_mpio.h run\_mpi.h wrapper\_f.h
   -  OMPI\_INTEL: app\_mpi.h run\_mpi.h run\_mpio.h wrapper\_f.h
   -  OMPI\_OMPI: app\_mpi.h run\_mpi.h wrapper\_f.h

Interface files:

-  gen:

   -  c2f\_f2c.c:
   -  test\_generation\_wrapper.c: Same as the preload version
   -  wrapper.c: Same as the preload version
   -  interface\_fort.c: Contain the overload symbol mechanism for
      Fortran MPI Function
   -  interface\_test.c: Contain the overload symbol mechanism for C MPI
      Function and rerouting to CodeChooser

-  header:

   -  OMPI\_INTEL: app\_mpi.h run\_mpi.h run\_mpio.h wrapper\_f.h
   -  OMPI\_OMPI: pp\_mpi.h run\_mpi.h wrapper\_f.h

-  interface\_utils:

   -  bin: Contain all mpi wrapper for compilation
   -  include: Contain all include exposed to users

-  manual:

   -  dlsym\_global.c : Get runtime MPI constants

-  module: Contain all elements to create a descent module

Get involved in WI4MPI
======================

Generator Guide is prerequisites to this part

Expand MPI cover of WI4MPI
--------------------------

On the generator side
~~~~~~~~~~~~~~~~~~~~~

-  Add the function name to the func\_list\_....txt files
-  Add the function description in the dictionary functions.json
-  Add the new mappers (if needed) to convert the arguments in the
   dictionary mappers.json
-  Get involved in the generator code if some special case have to be
   handled
-  Generate the new Fortran header for both interface and preload
   version

On the library side
~~~~~~~~~~~~~~~~~~~

-  Code the new mappers in mappers.h, new\_utils\*
-  Update app\_mpi.h app\_mpio.h run\_mpi.h run\_mpio.h for all
   conversion of both version
-  Update headers within src/interface/interface\_utils/include
-  Make sure to respect the MPI norm

Expand WI4MPI conversion capability
-----------------------------------

-  In mappers.h, you have to make sure that the status mapper translate
   the MPI\_Status.count in the right way since its implementation is
   developer dependent.
-  Generate the associated app\_mpi.h and run\_mpi.h to new conversion

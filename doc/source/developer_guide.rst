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
application side are prefixed by :code:`A_` and those from the runtime side are
prefixed by :code:`R_`. To perform a translation, all original MPI calls from
the application are intercepted by WI4MPI and replaced by the same call
prefixed by :code:`A_`. For example, with an OpenMPI ---> IntelMPI conversion.

.. graphviz:: developer_guide/how_it_works.dot
    :caption: How it works
    :name: how_it_works

..
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
the runtime MPI routines are saved to function pointers using a :code:`dlsym`
call to be called later on, all the tables are created and set with MPI
constant objects, and the spinlocks are initialized. To do so, we use
the following syntax:

.. code-block:: c++

    void **attribute** ((constructor)) wrapper_init {
      void(*) lib_handle = dlopen(getenv("WI4MPI_RUN_MPI_C_LIB"), RTLD_NOW);
      LOCAL_MPI_Function = dlsym(lib_handle, "PMPI_Function")
      ....
    }

The library contains three constructors:

-  :code:`wrapper_init` in :code:`test_generation_wrapper.c` (API C) (preload and
   interface)
-  :code:`wrapper_init_f` in :code:`wrapper.c` (API Fortran) (preload and interface)
-  :code:`wrapper_init_c2ff2c` in :code:`c2f_f2c.c` (API c2f/f2c)

Symbol overload
~~~~~~~~~~~~~~~

The mpi calls are intercepted thanks to the following rerouting:

-  :code:`#define A_MPI_Send PMPI_Send`
-  :code:`#pragma weak MPI_Send=PMPI_Send`

(See :code:`interface_test.c` in :code:`src/interface/gen/interface_test.c` and
:code:`src/interface/gen/interface_fort.c`) This syntax is also present but
hidden in :code:`test_generation_wrapper.c` (:code:`src/{preload,interface}/gen/`)
within an asm code chooser for the next reason.

The MPI-IO implementation (ROMIO) present within most MPI implementations
triggers some calls to the MPI user interface that WI4MPI intercepted using
the symbols overload protocol. This implies that during the runtime (phase
3 and above), some MPI calls are made triggering WI4MPI to re-intercept them
and crash the application. The crash is the result of WI4MPI trying to convert
arguments from the runtime version to the runtime version.
An :ref:`example <symbol_overload_example>` is illustrated below.

.. graphviz:: developer_guide/symbol_overload.dot
    :caption: Example: symbol overload
    :name: symbol_overload_example

..
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

To overcome this issue, we used an assembly code router.

Code chooser assembly
~~~~~~~~~~~~~~~~~~~~~~~

The ASM code chooser does the simple following things:

If we already are in the wrapper:

-  The arguments are passed without any translation protocol to the
   underlying MPI runtime call (:code:`LOCAL_MPI_function`)

Otherwise:

-  The arguments are translated and passed to the underlying MPI runtime
   call (:code:`LOCAL_MPI_function`)

To know which state the process is, we check the value of the :code:`in_w` variable:

-  :code:`in_w=1` : in the wrapper
-  :code:`in_w=0` : in the application

Since the implementation of MPI objects is developer dependent, some of them
may vary in size. To make sure that there is no side effect, the code chooser
analyzes the stack itself.

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

.. graphviz:: developer_guide/asm_code_chooser.dot
    :caption: ASM Code chooser
    :name: asm_code_chooser

..
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

:code:`A_MPI_Function`
~~~~~~~~~~~~~~~~~~~~~~~~~~

All translations are executed thanks to some mappers defined within
:code:`mappers.h` using an underlying hash table mechanism named :code:`uthash`
(https://troydhanson.github.io/uthash/) The mappers (see example below)
always have the same syntax :

.. code-block:: c++

    mapper_name_a2r(&buf, &buf_tmp);
    mapper_name_r2a(&buf, &buf_tmp);

In case of an a2r translation, :code:`buf_tmp` represent the translation of
:code:`buf` and vice versa for an r2a translation.

Example:

.. code-block:: c++

    A_MPI_Send(void *buf, int count, A_MPI_Datatype datatype, int dest, int tag,
               A_MPI_Comm comm) {
      void *buf_tmp;
      const_buffer_conv_a2r(&buf, &buf_tmp); // mapper
      R_MPI_Datatype datatype_tmp;
      datatype_conv_a2r(&datatype, &datatype_tmp); // mapper
      int dest_tmp;
      dest_conv_a2r(&dest, &dest_tmp); // mapper
      int tag_tmp;
      tag_conv_a2r(&tag, &tag_tmp); // mapper
      R_MPI_Comm comm_tmp;
      comm_conv_a2r(&comm, &comm_tmp); // mapper
      int ret_tmp = LOCAL_MPI_Send(buf_tmp, count, datatype_tmp, dest_tmp, tag_tmp,
                                   comm_tmp); // Runtime MPI_Send call
      return error_code_conv_r2a(ret_tmp);
    }

:code:`R_MPI_Function`
~~~~~~~~~~~~~~~~~~~~~~~

In :code:`R_MPI_Function`, the arguments are directly passed to the MPI runtime
call

.. code-block:: c++

    int R_MPI_Send(void *buf, int count, R_MPI_Datatype datatype, int dest, int tag,
                   R_MPI_Comm comm) {

      int ret_tmp = LOCAL_MPI_Send(buf, count, datatype, dest, tag, comm);

      return ret_tmp;
    }

Hash table
~~~~~~~~~~

The underlying hash table mechanism presented earlier is contained in
:code:`engine.*`, :code:`engine_fn.*` and :code:`utash.h`. For each
MPI objects, two tables are created. One for the constants, and one for the
:code:`MPI_Type` created by the application.

The different types being:

- :code:`MPI_Comm`
- :code:`MPI_Datatype`
- :code:`MPI_Errhandler`
- :code:`MPI_Group`
- :code:`MPI_Op`
- :code:`MPI_Request` (Split en 2 tables, in order to dissociate blocking
  requests from asynchronous requests)
- :code:`MPI_File`

The table within :code:`engine_fn.*` contains the following translation:

- :code:`MPI_Handler_function`
- :code:`MPI_Comm_copy_attr_function`
- :code:`MPI_Comm_delete_function`
- :code:`MPI_Type_delete_function`
- :code:`MPI_Comm_errhandler_function`
- :code:`MPI_File_errhandler_function`

Thread safety
~~~~~~~~~~~~~

To make WI4MPI usable in a multithread environment, the :code:`in_w` (see above) variable is TLS protected.

-  :code:`__thread int in_w=0;` (:code:`test_wrapper_generation.c:118`)
-  :code:`extern __thread int in_w;` (:code:`wrapper.c:7`)
-  :code:`extern __thread int in_w;` (:code:`c2f_f2c.c:6 || c2f_f2c.c:1149`)

The table are spinlock protected. (cf ::code:`thread_safety.h`):

-  :code:`#define lock_dest(a) pthread_spin_destroy(a)`
-  :code:`#define lock_init(a) pthread_spin_init(a, PTHREAD_PROCESS_PRIVATE)`
-  :code:`#define lock(a) pthread_spin_lock(a)`
-  :code:`#define unlock(a) pthread_spin_unlock(a)`
-  :code:`typedef pthread_spinlock_t (*)table_lock_t`

Interface
=========

The interface version of WI4MPI propose the promise as the preload
version (one compilation, several run over different MPI
implementation), but this time WI4MPI had to be seen as a fully MPI
Library. All the previously section are still relevant for the
interface, the only things that changed is the new level name INTERFACE
(see the :ref:`schema below <developer_guide_interface>`). This level has to be considered as a "libmpi.so"
which is linked to the user application.

.. graphviz:: developer_guide/interface.dot
    :caption: Interface
    :name: developer_guide_interface

..
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


The files :code:`interface_test.c` and :code:`interface_fort.c`, deal with the
overload symbol mechanism see earlier for respectively the C and Fortran
API, then according the conversion a dlopen is made to the appropriate
library (:code:`WI4MPI_WRAPPER_LIB`) responsible for the translation (ASM code
chooser + :code:`A_MPI_Function` + :code:`R_MPI_Function`).

:code:`MPI_Init` example

.. code-block:: c++

    int MPI_Init(int *argc, char ***argv);
    #define MPI_Init PMPI_Init
    #pragma weak MPI_Init = PMPI_Init
    int (*INTERFACE_LOCAL_MPI_Init)(int *, char ***);

    int PMPI_Init(int *argc, char ***argv) {
      int ret_tmp = INTERFACE_LOCAL_MPI_Init(argc, argv);
      return ret_tmp;
    }
    __attribute__((constructor)) void wrapper_interface(void) {
      void *interface_handle =
          dlopen(getenv("WI4MPI_WRAPPER_LIB"), RTLD_NOW | RTLD_GLOBAL);
      if (!interface_handle) {
        printf("no true IC lib defined\nerror :%s\n", dlerror());
        exit(1);
      }
      INTERFACE_LOCAL_MPI_Init = dlsym(interface_handle, "CCMPI_MPI_Init");
    }

Static mode
-----------

The static mode builds an executable with every targets translation. To
avoid conflicts, symbols are renamed as follow:
:code:`INTERF2_{TARGET}_{Symbol_name}`. No more dlopen is needed (cf.
Interface), functions pointer are chosen by 2 variables:
:code:`WI4MPI_STATIC_TARGET_TYPE_F` and :code:`WI4MPI_STATIC_TARGET_TYPE`. Static
sections are controlled by directives: :code:`#if(n)def WI4MPI_STATIC` / :code:`#endif`

Common files for both version of WI4MPI:

- :code:`func_char_fort.*`:

    Contain all Fortran MPI functions that deal with some character arguments.
    Since in Fortran a character argument always reference is len (character(len=*) :: dark_side) and since the len argument is not the same size according to the compiler (Intel/GNU < 8 or GNU >= 8) used,
    WI4MPI had to implement both.

    Example:

.. code-block:: c++

           #ifdef IFORT_CALL
                  void  A_f_MPI_Get_processor_name(char * name,int * resultlen,int * ret,int namelen) // The character length is of type int
           #elif GFORT_CALL
                  void  A_f_MPI_Get_processor_name(char * name,int * resultlen,int * ret,size_t namelen) // The character length is of type size_t
           #endif

- :code:`manual_wrapper.h`: Contain some manual mappers for Fortran translation
- :code:`mappers.h`: Contain the a2r/r2a mappers for C translation
- :code:`engine.*, engine_fn.*, uthash.h`: Contain all table routines
- :code:`thread_safety.h`: Contain the spinlock protection

Preload files:

-  bin/{wi4mpi,mpirun}: see User\_Guide
-  etc/wi4mpi.cfg: see User\_Guide
-  gen:

   -  :code:`c2f_f2c.c`:
   -  :code:`lib_empty.c`: Empty file to create empty Libraries made to
      replace the one from MPI use for the compilation
   -  :code:`test_generation_wrapper.c`: contain all C MPI function within
      WI4MPI which deal with the translation
   -  :code:`wrapper.c`: contain all the Fortran MPI function within WI4MPI
      which deal with the translation

-  header:

   -  :code:`INTEL_INTEL`: :code:`app_mpi.h app_mpio.h run_mpi.h run_mpio.h wrapper_f.h`
   -  :code:`INTEL_OMPI`: :code:`app_mpi.h app_mpio.h run_mpi.h wrapper_f.h`
   -  :code:`OMPI_INTEL`: :code:`app_mpi.h run_mpi.h run_mpio.h wrapper_f.h`
   -  :code:`OMPI_OMPI`: :code:`app_mpi.h run_mpi.h wrapper_f.h`

Interface files:

-  gen:

   -  :code:`c2f_f2c.c`:
   -  :code:`test_generation_wrapper.c`: Same as the preload version
   -  :code:`wrapper.c`: Same as the preload version
   -  :code:`interface_fort.c`: Contain the overload symbol mechanism for
      Fortran MPI Function
   -  :code:`interface_test.c`: Contain the overload symbol mechanism for C MPI
      Function and rerouting to CodeChooser

-  header:

   -  :code:`OMPI_INTEL`: :code:`app_mpi.h run_mpi.h run_mpio.h wrapper_f.h`
   -  :code:`OMPI_OMPI`: :code:`app_mpi.h run_mpi.h wrapper_f.h`

-  :code:`interface_utils`:

   -  :code:`bin`: Contain all mpi wrapper for compilation
   -  :code:`include`: Contain all include exposed to users

-  manual:

   -  :code:`dlsym_global.c` : Get runtime MPI constants

-  module: Contain all elements to create a descent module

Get involved in WI4MPI
======================

Generator Guide is prerequisites to this part

Expand MPI cover of WI4MPI
--------------------------

On the generator side
~~~~~~~~~~~~~~~~~~~~~

-  Add the function name to the :code:`func_list_....txt` files
-  Add the function description in the dictionary functions.json
-  Add the new mappers (if needed) to convert the arguments in the
   dictionary :code:`mappers.json`
-  Get involved in the generator code if some special case have to be
   handled
-  Generate the new Fortran header for both interface and preload
   version

On the library side
~~~~~~~~~~~~~~~~~~~

-  Code the new mappers in :code:`mappers.h, engine*`
-  Update :code:`app_mpi.h app_mpio.h run_mpi.h run_mpio.h` for all
   conversion of both version
-  Update headers within :code:`src/interface/interface_utils/include`
-  Make sure to respect the MPI norm

Expand WI4MPI conversion capability
-----------------------------------

-  In mappers.h, you have to make sure that the status mapper translate
   the :code:`MPI_Status.count` in the right way since its implementation is
   developer dependent.
-  Generate the associated :code:`app_mpi.h` and :code:`run_mpi.h` to new conversion

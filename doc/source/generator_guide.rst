Generator Guide
***************

Introduction to the generators
==============================

The main generator within WI4MPI is responsible of the MPI functions generation used to pass the appropriate arguments to the underlying runtime MPI function. It handle the generation of MPI C and Fortran routines for the interface and preload version of WI4MPI, performed by both python script generator.py (which contain the class) and generate.py (which contain the generation pattern).

Since all Fortran MPI object are constant or int type, most of the translation from an MPI implementation to another one are handle by some switch case statements, which can then be easily generated. To do so, there is generated_header_f.py which generate the Fortran header file for each available conversion.

The last generator was made for handling c2f/f2c function. Since the underlying translation system is under a rework mechanism, any use of this generator would lead to some deprecated file.

Some functions are not implemented yet due to their complexity, but in order to have a frozen API, they have to be added to the generated files (see the section below). Those functions trigger an MPI_Abort when they are used.

Generation template
-------------------

File template handling C MPI routines for interface and preload version:

#. Non generated function integration
#. Normal MPI\_... declaration
#. Function pointer to the underlying runtime MPI routine declaration
#. ASM code chooser
#. A_MPI\_...  declaration + function construction

    #. Header
    #. Temporary variable assignment, and translation
    #. Call to the MPI runtime function
    #. Footer
    #. return

#. R_MPI\_... declaration + function construction

    #. Header
    #. Call to the MPI runtime function
    #. Footer
    #. return

#. Attribute constructor init generation

Generating function connection:

#. print_symbol_c
#. print_symbol_c
#. object_gen.generate_func_asmK_tls / generate_func_asmK_tls_updated_for_interface
#. generate_func_c

    #. header_func
    #. print_temporary_decl_c + affect_temp_conv_c
    #. print_symbol_c + affect_val_conv_c
    #. footer_func

#. generate_func_r
    
    #. header_func
    #. print_symbol_c
    #. footer_func

The Fortran MPI routines template is quite similar. The step 6 and 4 are specific to this version.

Function and mappers dictionaries
---------------------------------

functions.json -- C
~~~~~~~~~~~~~~~~~~~

Example:

.. code-block:: c++

    MPI_Init(int *, char***);
    {
    "args": [
    { **1st argument**
    
        "var": "argc", **name**
    
        "arg_dep": "", **dependency**
    
        "In": 1, **The argument need to be converted before any call to the underlying MPI runtime call**
    
        "name": "int_ptr_mapper", **name of the mapper corresponding to that argument (mappers are responsible for the translation)**
    
        "Out": 0 **The argument do not need to be converted after the MPI runtime call**
    
    },
    { **2nd argument**
    
        "var": "argv",
    
        "arg_dep": "",
    
        "In": 1,
    
        "name": "char_ppp_converter",
    
        "Out": 0
    
    }
    
    ],
    
      "name": "MPI_Init",
    
      "ret":
    
      {
    
            "var": "ret",
    
            "arg_dep": "",
    
            "In": 0,
    
            "name": "error_converter",
    
            "Out": 1
    
      }
    
    }

Some additional key words to deal with some special cases:

- if : Tell to the generating process that the argument needs to be translated only if the condition within the if statements is true.
- if_dep : If provided, then the generator automatically understand that the argument tested in the "if" condition is an array, and so a loop is generated from 0 to "if_dep" ('if_dep' works hand in hand with 'if').
- if_null : Same as 'if' keyword but dedicated to NULL constants.
- if_null_dep : Same as 'if_dep' but works with 'if_null'
- if_err: Handle special case MPI_Errhandler_set.
- del : The argument needs to be deleted from the mechanism managing the database (hashtable)
- del2 : Same as 'del'.
- arg_dep: Same as 'if_dep' but works on its own.

Association keywords:

+---------------------+---------------------+----------------------+---------------------+---------------------+
|                     | Wait & Test         | Waitany & Waitany    | Waitsome & Testsome | Waitall & Testall   |
+=====================+=====================+======================+=====================+=====================+
| if                  | R_MPI_SUCCESS       | R_MPI_SUCCESS        | R_MPI_SUCCESS       |  R_MPI_SUCCESS      |
+---------------------+---------------------+----------------------+---------------------+---------------------+
| if_dep              |        NONE         |        NONE          | (*)outcount         |    count            |
+---------------------+---------------------+----------------------+---------------------+---------------------+
| if_null             | R_MPI_REQUEST_NULL  |  R_MPI_REQUEST_NULL  | R_MPI_REQUEST_NULL  | R_MPI_REQUEST_NULL  |
+---------------------+---------------------+----------------------+---------------------+---------------------+
| if_null_dep         |        NONE         |        NONE          | array_of_indices    |       NONE          |
+---------------------+---------------------+----------------------+---------------------+---------------------+
| del                 | request_ptr_delete  | request_array_delete | request_array_delete| request_array_delete|
+---------------------+---------------------+----------------------+---------------------+---------------------+
| del2                |        NONE         |        NONE          |       NONE          |       NONE          |
+---------------------+---------------------+----------------------+---------------------+---------------------+

mappers.json -- C
~~~~~~~~~~~~~~~~~

This file contains all different metadata about mappers that needs to be called to performed any conversion.
Each entry is corresponding to the mappers name which is referenced in the function.json "name" keywords within any arguments function. Those entries provide metadata relevant for the generator as represented bellow:

.. code-block::

    "int_ptr_mapper": {     **name**
    
        "local_alloc": 0, **Does the variable needs to be allocated locally. 0=no; 1=yes**
    
        "a2r": "int_ptr_conv_a2r", **If 'in=1' from functions.json is set, then this function needs to be called**
    
        "type": "int (*)", **type of the argument**
    
        "r2a": "int_ptr_conv_r2a", **If 'out=1' from functions.json is set, then this function needs to be called**
    
        "no_map": "TRUE" **The argument does not need to be converted if 'TRUE'**
    
    }

All relevent keywords that a mappers can contain are:

- no_map : indicate if the argument needs to be converted
- assign : indicate that the arguments simply needs a cast
- local_alloc : indicate that the variable needs to be allocated locally
- wrap : Special case where the argument 'wrap' is a function pointer. (example MPI_Op_create)
- wrapped : 'wrapped' contain the function name which is called to translate the arguments of the function referenced by 'wrap'.

Example of "wrap" and "wrapped": "wrapper_user_function"

When a call to  A_MPI_Op_create(A_MPI_User_function * user_fn,int commute,A_MPI_Op * op);, the **user_fn** et op arguments needs to be converted

.. code-block:: c++

    int A_MPI_Op_create(A_MPI_User_function * user_fn,int commute,A_MPI_Op * op)
    {
    
        in_w=1;
    
        ptr_user_func=(A_MPI_User_function * )user_fn;
    
        R_MPI_Op  op_ltmp;
    
        R_MPI_Op * op_tmp=&op_ltmp;
    
        int ret_tmp= LOCAL_MPI_Op_create( (R_MPI_User_function * ) wrapper_user_function, commute, op_tmp);
    
        op_conv_r2a(op,op_tmp); **conversion de op**
    
        in_w=0;
    
        return error_code_conv_r2a(ret_tmp);
    
    }

**user_fn** is a function pointer where (MPI_Datatype * ) is referenced:

**typedef void (MPI_User_function) (void * , void * , int * , MPI_Datatype * );**

**Conversion de user_fn :**

.. code-block:: c++

    void wrapper_user_function(void * invec, void * inoutvec, int * len,R_MPI_Datatype * type)
    {
        A_MPI_Datatype datatype_tmp;
        datatype_conv_r2a( &datatype_tmp,type);
        (ptr_user_func)(invec, inoutvec, len, & datatype_tmp);
    }

The following keywords are set for user_fn in MPI_Op_create:

- "wrap" : **"user_fn"**
- "wrapped" : **"wrapper_user_function"**

functions.json -- Fortran special case
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Some special cases are handle thanks to the "assoc" field which allow to make some bounds between the hash table and both of the following parameters.

Exemple:

.. code-block::

    "assoc":[
        {
            "func":"Keyval_translation_del",
            "key":"keyval_tmp"
        }
    ]


mappers.json -- Fortran special cases
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

The fields 'nomap' and 'argdep' got the same goal as 'no_map' and 'arg_dep' of C mappers.

Frozen API
----------

In order to get the frozen API proceed as follow:

Just copy the contents of ``A`` the file into the ``B`` file:

+----------------------------------------+-----+-----------------------------------------+
|                     A                  |     |                     B                   |
+----------------------------------------+-----+-----------------------------------------+
| interface_api_fige.c                   |<--->| interface/gen/test_wrapper_generation.c |
+----------------------------------------+-----+-----------------------------------------+
| interface_api_fige_fortran.c           |<--->| interface/gen/wrapper.c                 |
+----------------------------------------+-----+-----------------------------------------+
| interface_api_fige_fortran_interface.c |<--->| interface/gen/interface_fort.c          |
+----------------------------------------+-----+-----------------------------------------+
| preload_api_fige.c                     |<--->| preload/gen/test_wrapper_generation.c   |
+----------------------------------------+-----+-----------------------------------------+
| preload_api_fige_fortran.c             |<--->| preload/gen/wrapper.c                   |
+----------------------------------------+-----+-----------------------------------------+

Quick generation
================

python generate.py will generate the following files:

.. code-block:: console

    >>>>> Generating preload/gen/test_generation_wrapper.c
            Done.
    >>>>> Generating preload/gen/wrapper.c
            Done.
    >>>>> Generating interface/gen/test_generation_wrapper.c
            Done.
    >>>>> Generating interface/gen/wrapper.c
            Done.
    >>>>> Generating interface/gen/interface_test.c
            Done.
    >>>>> Generating interface/gen/interface_fort.c

python generate_header_f.py will generate the following files:
preload/header/INTEL_INTEL:
wrapper_f.h

preload/header/INTEL_OMPI:
wrapper_f.h

preload/header/OMPI_INTEL:
wrapper_f.h

preload/header/OMPI_OMPI:
wrapper_f.h

In order to generate the interface version of the Fortran header please use following 'sed' command for generator directory:

.. code-block:: console

    mkdir -p interface/header/OMPI_OMPI && sed -e '1,18 s/mpi/a_mpi/g' -e '19,36 s/extern int mpi/int \*ccc_mpi/g' -e '19,36 s/&mpi_/ccc_mpi_/g' preload/header/OMPI_OMPI/wrapper_f.h > interface/header/OMPI_OMPI/wrapper_f.h
    
    mkdir -p interface/header/OMPI_INTEL && sed -e '19,32d' -e '18 r ./FORTRAN/utils/wrapper_f_h_O_I_add' preload/header/OMPI_INTEL/wrapper_f.h > interface/header/OMPI_INTEL/wrapper_f.h

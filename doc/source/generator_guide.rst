Generator Guide
***************

Introduction to the generators
##############################

.. todo: Re write introduction

The main generator within WI4MPI is responsible of the MPI functions generation used to pass the appropriate arguments to the underlying runtime MPI function.
It handle the generation of MPI C routines for the interface and preload version of WI4MPI.

These file generations are driven by the python command :file:`<wi4mpi_dir>/src/generator/generator.py`.
This contains the :code:`Generator` class that will generate the C code files and headers.
The different generation tasks have been organized in several python modules and submodules all present in the 'src/generator' folder.
The python command has several options such as target versions of OpenMPI, MPICH and IntelMPI or the target MPI norm.

Some functions are not implemented yet due to their complexity, but in order to have a :ref:`frozen_api`, they have to be added to the generated files. Those functions trigger an MPI_Abort when they are used.



Quick generation
################

Requirements
============

- Prepend :file:`{wi4mpi_dir}/src/generator` in your :envvar:`PYTHONPATH`
- The generator uses ``clang-format -style=LLVM`` to format C files. So you must have ``clang-format`` in your :envvar:`PATH`
- The generator needs following python modules: ``docopt jsonschema logging jinja2``

Execution
=========

:file:`{wi4mpi_dir}/src/generator/generate.py` will print in the standard output the following lines:

.. code-block:: console

    generator_logger - INFO - Starting to generate.
    header_logger - INFO - MpcHeaderGenerator in progress.
    header_logger - WARNING - The generation of 'src/interface/header/_MPC/wrapper_f.h' have to be done locally.
            A MPC program has to be executed in order to catch MPI_MODE_XXX values.
            Have a look to generator/FORTRAN/MPI_XXX_generator/MPC/gen_MPC_vars.sh
    header_logger - INFO - IntelHeaderGenerator in progress.
    header_logger - INFO - MpichHeaderGenerator in progress.
    header_logger - INFO - OmpiHeaderGenerator in progress.
    header_logger - INFO - IntelIntelHeaderGenerator in progress.
    header_logger - INFO - IntelMpichHeaderGenerator in progress.
    header_logger - INFO - MpichIntelHeaderGenerator in progress.
    header_logger - INFO - MpichMpichHeaderGenerator in progress.
    header_logger - INFO - IntelOmpiHeaderGenerator in progress.
    header_logger - INFO - MpichOmpiHeaderGenerator in progress.
    header_logger - INFO - OmpiIntelHeaderGenerator in progress.
    header_logger - INFO - OmpiMpichHeaderGenerator in progress.
    header_logger - INFO - OmpiOmpiHeaderGenerator in progress.
    code_logger - INFO - Generation of preload C file.
    code_logger - INFO - Generation of interface C file.
    generator_logger - INFO - End

All log messages are written in :file:`generator.log`.

Without any options, the generator will overwrite the header files in directories

- :file:`<wi4mpi_dir>/src/interface/header/_*`
- :file:`<wi4mpi_dir>/src/preload/header/*_*`

and generated code files in directories

- :file:`<wi4mpi_dir>/src/interface/gen/`
- :file:`<wi4mpi_dir>/src/preload/gen/`


Header generator
################


Dedicated settings
==================

The following options are dedicated to the header generator:

.. code-block::

      --interface_header_dir=<interface_header_dir>                      Path to header interface generation folder.
      --preload_header_dir=<preload_header_dir>                          Path to header preload generation folder.
      --openmpi_version=<openmpi_version>                                Version of the target OpenMPI
      --mpich_version=<mpich_version>                                    Version of the target MPICH
      --intelmpi_version=<intelmpi_version>                              Version of the target IntelMPI

The options for defining the paths of the generation folders are detailed in :ref:`header_generator_output_directories`.

Options for defining versions of MPI implementations are detailed in :ref:`header_generator_version_numbers`

.. _header_generator_output_directories:

Output directories
------------------

The paths to the directories where the interface and preload headers are written are configurable by the following options:

- :code:`--interface_header_dir` set the Generator class attribute :code:`interface_header_dir`. Default value: :file:`src/interface/header`
- :code:`--preload_header_dir` set the Generator class attribute :code:`preload_header_dir`. Default value: :file:`src/preload/header`

The subfolders in which the headers are actually written follow the nomenclature :code:`<APP_side_name>_<RUN_side_name>`.

:numref:`interface-header` and :numref:`preload-header` can be consulted for an overview of the distribution of headers in the subfolders of :code:`interface_header_dir` and :code:`preload_header_dir`.

.. _header_generator_version_numbers:

Version numbers
---------------

The version numbers of the MPI implementations whose headers are used as the basis for producing the wi4mpi headers are configurable by the following options:

- :code:`--openmpi_version` set :code:`openmpi_version`, the version of the target OpenMPI. Default value: 5.0.3
- :code:`--mpich_version` set :code:`mpich_version`, the version of the target MPICH. Default value: 4.2.0
- :code:`--intelmpi_version` set :code:`intelmpi_version`, the version of the target IntelMPI. Default value: 24.0.0

For each of the previous options, if defined, the value of the dictionary :code:`mpi_target_version` (attribute of the Generator class)  corresponding to the name of the implementation will be updated

.. topic:: Example with :code:`--openmpi_version=4.1.6`

    Default settings:

    .. code-block:: python

        mpi_target_version = {
    	"openmpi": "5.0.3",
    	"mpich": "4.2.0",
    	"intelmpi": "24.0.0",
        }

    Update:

    .. code-block:: python

        mpi_target_version = {
    	"openmpi": "4.1.6",
    	"mpich": "4.2.0",
    	"intelmpi": "24.0.0",
        }

The version number of each implementation will then be retrieved in the following way within the Generator class and its subclasses:
:code:`self.mpi_target_version["<implementation_name>"]`

.. warning::

    A check for version support for each implementation is performed in the initialization of the Generator class.
    If the number is not in the :code:`mpi_availabe_target_version` dictionary (attribute of the Generator class) then it will return an error and stop the generation.

    Currently supported versions are:

    - OpenMPI: 1.8.8, 2.1.6, 4.1.6, 5.0.3
    - MPICH: 3.1.2, 3.4.3, 4.2.0
    - IntelMPI: 20.0.0, 24.0.0


Aliases
-------

    An alias system has been implemented in the :file:`generator.py` file and allows only the major number of the MPI implementation version to be passed in argument.
    Concretely, this involves associating the major number with the highest supported version number.
    For this the :code:`alias_<implementation_name>` dictionaries are used:

.. code-block:: python

    alias_openmpi = {
        "1": "1.8.8",
        "2": "2.1.6",
        "4": "4.1.6",
        "5": "5.0.3",
    }
    alias_mpich = {
        "3": "3.4.3",
        "4": "4.2.0",
    }
    alias_intelmpi = {
        "20": "20.0.0",
        "24": "24.0.0",
    }

.. topic:: Example

    The option :code:`--openmpi_version=4.1.6` is equivalent to :code:`--openmpi_version=4`.

.. todo:: Worflow header input and output

Workflow
========


As can be seen in :ref:`the graph below <graph_header_dir_workflow_init>`, the :code:`--interface_header_dir` and :code:`--preload_header_dir` options pass the prefixes of the writing directories of the preload and interface headers to the generator when initializing an object of the :code:`Generator` class.
Their value is stored in the :code:`interface_header_dir` and :code:`preload_header_dir` class attributes when calling the :code:`set_directories` method.

.. graphviz:: generator_guide/header_dir_workflow_init.dot
    :caption: Set header directories prefix
    :name: graph_header_dir_workflow_init

.. tip::

    Default values are :file:`src/interface/header` and :file:`src/preload/header`

Then, the creation of these folders is done during the initialization of each header generation class during the execution of the :code:`Generator.generate()` method.
We can see for example the case of the generation of Intel-Intel preload headers on the graph :ref:`graph_header_dir_workflow_create`.
The value of :code:`preload_header_dir` previously defined during the initialization step of the :code:`Generator` class is transmitted to the :code:`set_directories` method of the main :code:`HeaderGenerator` class which then calls the :code:`os.makedirs` builtin to create the :code:`<preload_header_dir>/INTEL_INTEL` subfolder.

.. graphviz:: generator_guide/header_dir_workflow_create.dot
    :caption: Create header directories prefix
    :name: graph_header_dir_workflow_create

Once the folders are created, it is the turn of the header files.
The actions concerning them, illustrated on the graph :ref:``, are also triggered by the :code:`generate` method of each generation class.
The basic headers are first copied from :code:`<dir_input>` to :code:`<dir_output>`.
To do this, the :code:`app` and :code:`run` attributes are used to form the strings of the file names to be copied.
This excerpt from the code of the :code:`copy_files` method illustrates the Intel-Intel case:

.. code-block:: python

    input_file_name = f"{self.app}-{self.mpi_target_version[f'{self.app}']}_mpio.h"
    self.copy_file(input_file_name, "app_mpio.h")
    input_file_name = f"{self.app}-{self.mpi_target_version[f'{self.app}']}_mpi.h"
    self.copy_file(input_file_name, "app_mpi.h")

    input_file_name = f"{self.run}-{self.mpi_target_version[f'{self.run}']}_mpio.h"
    self.copy_file(input_file_name, "run_mpio.h")
    input_file_name = f"{self.run}-{self.mpi_target_version[f'{self.run}']}_mpi.h"
    self.copy_file(input_file_name, "run_mpi.h")

The names and paths of the files to be copied and their destination are passed one by one to the :code:`copy_file` method.

.. tip::

    The names of the final files are defined in the :code:`HeaderGenerator` class.

    .. code-block:: python

            _run_mpi_header_file = "run_mpi.h"
            _run_mpio_header_file = "run_mpio.h"
            _app_mpi_header_file = "app_mpi.h"
            _app_mpio_header_file = "app_mpio.h"
            _wrapper_f_header_file = "wrapper_f.h"
            _run_mpi_proto_header_file = "run_mpi_proto.h"
            _app_mpi_proto_header_file = "app_mpi_proto.h"


.. graphviz:: generator_guide/header_files_workflow_copy.dot
    :caption: Copy header files
    :name: graph_header_files_workflow_copy

Then the copied files are modified by the following methods:

.. code-block:: python

    _generate_run_mpih
    _generate_run_mpioh
    _generate_app_mpih
    _generate_app_mpioh
    _generate_run_mpi_protoh
    _generate_app_mpi_protoh
    _generate_wrapper_fh

..
    Toutes ces méthodes sont définies dans la classe principale :code:`HeaderGenerator`.
    Elles peuvent ensuite être surchargées dans les sous-classes dédiées à chaque combinaisons :code:`<APP>-<RUN>` d'implémentation MPI.
    Diverses méthodes sont utilisées afin de mutualiser les modifications de fichier.
    Ainsi, la description complète du workflow de la génération de chaque header peut s'avérer complexe.

All these methods are defined in the main class :code:`HeaderGenerator`.
They can then be overridden in subclasses dedicated to each combination :code:`<APP>-<RUN>` of MPI implementation.
Various methods are used to pool file modifications.
Thus, the complete description of the workflow for generating each header can be complex.

Preload mode: IntelMPI application side -- IntelMPI runtime side
----------------------------------------------------------------

:file:`run_mpi.h`
~~~~~~~~~~~~~~~~

..
    La génération du header :file:`run_mpi.h` dans le cas Intel-Intel est illustré dans le graphique :ref:`graph_header_files_workflow_generate_intel_intel_run_mpi`.
    Un objet de la classe :code:`IntelIntelHeaderGenerator` est initialisé dans la méthode :code:`generate_header` de la classe :code:`Generator`.
    La méthode :code:`generate` de :code:`IntelIntelHeaderGenerator` est héritée de la classe :code:`HeaderGenerator` par la classe :code:`IntelHeaderGenerator`.
    On y trouve l'appel à la méthode dédiée à la génération du fichier :file:`run_mpi.h`: :code:`_generate_run_mpih`.
    Celle-ci va successivement appeler :code:`intel_generate_run_mpih` (de la classe :code:`IntelHeaderGenerator`) et :code:`intel_preload_exception_header_run_mpih`.
    La première méthode applique les modifications communes apportées par :code:`_replace_mpi_with_rmpi` de la classe :code:`HeaderGenerator` et celles de :code:`intel_exceptions_run_mpih`.
    Les modifications sont ensuite enregistrés dans :file:`run_mpi.h`.
    Enfin, :code:`intel_preload_exception_header_run_mpih` applique les dernières modifications. Pour cela, un fichier de :file:`etc/header` contenant des instructions de substitution est passé à la fonction :code:`replacement_from_conf_file` et des lignes sont supprimées par la fonction :code:`delete_lines`. Ces deux fonctions appartiennent au module :code:`textoperator`.

The generation of the header :file:`run_mpi.h` in the Intel-Intel case is illustrated in the :ref:`graph below <graph_header_files_workflow_generate_intel_intel_run_mpi>`.
An object of the class :code:`IntelIntelHeaderGenerator` is initialized in the method :code:`generate_header` of the class :code:`Generator`.
The method :code:`generate` of :code:`IntelIntelHeaderGenerator` is inherited from the class :code:`HeaderGenerator` by the class :code:`IntelHeaderGenerator`.
We find there the call to the method dedicated to the generation of the file :file:`run_mpi.h`: :code:`_generate_run_mpih`.
This will successively call :code:`intel_generate_run_mpih` (from the :code:`IntelHeaderGenerator` class) and :code:`intel_preload_exception_header_run_mpih`.
The first method applies the common modifications made by :code:`_replace_mpi_with_rmpi` from the :code:`HeaderGenerator` class and those of :code:`intel_exceptions_run_mpih`.
The modifications are then saved in :file:`run_mpi.h`.
Finally, :code:`intel_preload_exception_header_run_mpih` applies the latest modifications. To do this, a file from :file:`etc/header` containing substitution instructions is passed to the :code:`replacement_from_conf_file` function and lines are deleted by the :code:`delete_lines` function. These two functions belong to the :code:`textoperator` module.


.. graphviz:: generator_guide/header_files_workflow_generate_intel_intel_run_mpi.dot
    :caption: Generating ``run_mpi.h`` for IntelMPI application side -- IntelMPI runtime side
    :name: graph_header_files_workflow_generate_intel_intel_run_mpi

:file:`app_mpi.h`
~~~~~~~~~~~~~~~~

.. graphviz:: generator_guide/header_files_workflow_generate_intel_intel_app_mpi.dot
    :caption: Generating ``app_mpi.h`` for IntelMPI application side -- IntelMPI runtime side
    :name: graph_header_files_workflow_generate_intel_intel_app_mpi

:file:`run_mpio.h`
~~~~~~~~~~~~~~~~~

.. graphviz:: generator_guide/header_files_workflow_generate_intel_intel_run_mpio.dot
    :caption: Generating ``run_mpio.h`` for IntelMPI application side -- IntelMPI runtime side
    :name: graph_header_files_workflow_generate_intel_intel_run_mpio

:file:`app_mpio.h`
~~~~~~~~~~~~~~~~~

.. graphviz:: generator_guide/header_files_workflow_generate_intel_intel_app_mpio__short.dot
    :caption: Generating ``app_mpio.h`` for IntelMPI application side -- IntelMPI runtime side (short workflow)
    :name: graph_header_files_workflow_generate_intel_intel_app_mpio__short

.. graphviz:: generator_guide/header_files_workflow_generate_intel_intel_app_mpio.dot
    :caption: Generating ``app_mpio.h`` for IntelMPI application side -- IntelMPI runtime side
    :name: graph_header_files_workflow_generate_intel_intel_app_mpio

IntelMPI interface mode
-----------------------

:file:`run_mpi.h`
~~~~~~~~~~~~~~~~

.. graphviz:: generator_guide/header_files_workflow_generate_intel_run_mpi.dot
    :caption: Generating ``run_mpi.h`` for IntelMPI
    :name: graph_header_files_workflow_generate_intel_run_mpi

:file:`app_mpi.h`
~~~~~~~~~~~~~~~~

.. graphviz:: generator_guide/header_files_workflow_generate_intel_app_mpi.dot
    :caption: Generating ``app_mpi.h`` for IntelMPI
    :name: graph_header_files_workflow_generate_intel_app_mpi

:file:`run_mpio.h`
~~~~~~~~~~~~~~~~~

.. graphviz:: generator_guide/header_files_workflow_generate_intel_run_mpio.dot
    :caption: Generating ``run_mpio.h`` for IntelMPI
    :name: graph_header_files_workflow_generate_intel_run_mpio

OpenMPI interface mode
----------------------

:file:`run_mpi.h`
~~~~~~~~~~~~~~~~

.. graphviz:: generator_guide/header_files_workflow_generate_ompi_run_mpi.dot
    :caption: Generating ``run_mpi.h`` for OpenMPI
    :name: graph_header_files_workflow_generate_ompi_run_mpi

:file:`app_mpi.h`
~~~~~~~~~~~~~~~~

.. graphviz:: generator_guide/header_files_workflow_generate_ompi_app_mpi.dot
    :caption: Generating ``app_mpi.h`` for OpenMPI
    :name: graph_header_files_workflow_generate_ompi_app_mpi

MPICH interface mode
--------------------

:file:`run_mpi.h`
~~~~~~~~~~~~~~~~

.. graphviz:: generator_guide/header_files_workflow_generate_mpich_run_mpi.dot
    :caption: Generating ``run_mpi.h`` for MPICH
    :name: graph_header_files_workflow_generate_mpich_run_mpi

Code generator
##############

Dedicated settings
==================

The following options are dedicated to the code generator:

.. code-block::

      --c_preload_gen_dir=<c_preload_gen_dir>                            Path to C preload generation folder.
      --c_interface_gen_dir=<c_interface_gen_dir>                        Path to C interface generation folder.
      --mpi_norm=<mpi_norm>                                              Version of MPI norm to use


The options for defining the paths of the generation folders are detailed in :ref:`code_generator_output_directories`.

Options for defining version of MPI norm are detailed in :ref:`code_generator_mpi_norm`

.. _code_generator_output_directories:

Output directories
------------------

The paths to the directories where the interface and preload generated C code are written are configurable by the following options:

- :code:`--c_interface_header_dir` set the Generator class attribute :code:`c_interface_header_dir`. Default value: :file:`src/interface/gen`
- :code:`--c_preload_header_dir` set the Generator class attribute :code:`c_preload_header_dir`. Default value: :file:`src/preload/gen`


.. _code_generator_mpi_norm:

MPI norm
--------

The version number of the MPI standard in which the user wants to generate the C code (see :ref:`output_files_c_files`) can be set by the :code:`--mpi_norm` option.
This option set the Generator class attribute :code:`mpi_norm` which transmits the version through the generator.
By default its value is 3.1

The list of supported versions is contained in :code:`mpi_available_norm`:

.. code-block::

    mpi_availabe_norm = [ "1.0", "1.1", "1.2", "2.0", "2.1", "2.2", "3.0", "3.1", "4.0"]

This value is used to select the functions implemented in the chosen standard.

To do this, :code:`mpi_norm` traverses the generator following the path of :numref:`graph_mpi_norm`.
Its value is transmitted to the header and code generator at the initialisation of a `Generator` object.
It is compared to the :code:`MPImin` and :code:`MPImax` values of each object of the  JSON file
:file:`<wi4mpi_dir>/lib/etc/code/common/jsons/functions.json` (see :ref:`functions_json_example`)
This comparison is performed when the JSON is loaded in :code:`load_json_file`.
The result is a dictionary :code:`data["function"]` containing all the functions of the standard.


.. graphviz:: generator_guide/mpi_norm_workflow.dot
    :caption: Worflow of ``mpi_norm``
    :name: graph_mpi_norm


.. note::

   If a json schema is given as an argument to the :code:`load_json_file` function then the python :code:`jsonschema` module will be used to validate the json file given for reading.

   Currently the schema used to validate the previous :file:`functions.json` is
   :file:`<wi4mpi_dir>/lib/etc/code/common/jsons/schemas/schema_functions.json`
   In particular, it requires the presence of the keyword :code:`MPImin`.



Generation template
===================

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
=================================

.. _functions_json_example:

functions.json -- C
-------------------

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
    
      },

      "MPImin": 1.0,

      "MPImax": 4.0
    
    }

Some additional key words to deal with some special cases:

- if : Tell to the generating process that the argument needs to be translated only if the condition within the if statements is true.
- if_null : Same as 'if' keyword but dedicated to NULL constants.
- if_dep : If provided, then the generator automatically understand that the argument tested in the "if" condition is an array, and so a loop is generated from 0 to "if_dep" ('if_dep' works hand in hand with 'if').
- if_null_dep : Same as 'if_dep' but works with 'if_null'
- if_err: Handle special case MPI_Errhandler_set.
- del : The argument needs to be deleted from the mechanism managing the database (hashtable)
- del2 : Same as 'del'.
- arg_dep: Same as 'if_dep' but works on its own.

See :numref:`association-keywords` to overview the association keywords.

.. _association-keywords:

.. table:: Association keywords
    :align: center
    :widths: auto

    +---------------------+---------------------+----------------------+---------------------+---------------------+
    |                     | Wait & Test         | Waitany & Waitany    | Waitsome & Testsome | Waitall & Testall   |
    +=====================+=====================+======================+=====================+=====================+
    |                   if| R_MPI_SUCCESS                                                                          |
    +---------------------+---------------------+----------------------+---------------------+---------------------+
    | if_null             | R_MPI_REQUEST_NULL                                                                     |
    +---------------------+---------------------+----------------------+---------------------+---------------------+
    | if_dep              |        NONE         |        NONE          | (*)outcount         |    count            |
    +---------------------+---------------------+----------------------+---------------------+---------------------+
    | if_null_dep         |        NONE         |        NONE          | array_of_indices    |       NONE          |
    +---------------------+---------------------+----------------------+---------------------+---------------------+
    | del                 | request_ptr_delete                                                                     |
    +---------------------+---------------------+----------------------+---------------------+---------------------+
    | del2                | NONE                                                                                   |
    +---------------------+---------------------+----------------------+---------------------+---------------------+

mappers.json -- C
-----------------

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
--------------------------------------

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
-------------------------------------

The fields 'nomap' and 'argdep' got the same goal as 'no_map' and 'arg_dep' of C mappers.

.. _frozen_api:

Frozen API
==========

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

Input files
###########

.. todo: Input files in proper section or split inside Header generator and Code generator ?

The generator will open several files during the proccess:

- C header
- JSON
- jinja
- raw text

Headers generator inputs
========================

.. _base_headers:

Base headers
------------

The headers of each supported implementation are in :file:`<wi4mpi_dir>/src/common` folder.
Here is an overview of the tree structure:

.. code-block::

   <implementation_name>/
   └── <version>
       └── mpi.h

with :code:`<implementation_name>` equal to :code:`openmpi`, :code:`mpich` or :code:`intelmpi`.

These files are used as a base from which Wi4MPI's own headers will be generated.
However, the generator will not open them directly in :file:`<wi4mpi_dir>/src/common`.
Instead, symbolic links will be opened.
They are placed in the :file:`<wi4mpi_dir>/src/interface/header/scripts/` tree for interface mode and in :file:`<wi4mpi_dir>/src/preload/header/scripts/` tree for preload mode.

.. topic:: Example in preload mode with MPICH in application side and OpenMPI in runtime side:

   The command :code:`<wi4mpi_dir>/src/generator/generator.py --openmpi_version=2 --mpich_version=3` will take in input the following files:

   - :file:`<wi4mpi_dir>/src/preload/header/scripts/mpich_ompi_headers/ompi-2.1.6_mpi.h`
   - :file:`<wi4mpi_dir>/src/preload/header/scripts/mpich_ompi_headers/mpich-3.4.3_mpi.h`
   - :file:`<wi4mpi_dir>/src/preload/header/scripts/mpich_ompi_headers/mpich-3.4.3_mpio.h`

   :file:`mpich_ompi_headers` tree:

   .. code-block::

      src/preload/header/scripts/mpich_ompi_headers/
      ├── mpich-3.1.2_mpi.h -> ../../../../../src/common/mpich/3.1.2/mpi.h
      ├── mpich-3.1.2_mpio.h -> ../../../../../src/common/mpich/3.1.2/mpio.h
      ├── mpich-3.4.3_mpi.h -> ../../../../../src/common/mpich/3.4.3/mpi.h
      ├── mpich-3.4.3_mpio.h -> ../../../../../src/common/mpich/3.4.3/mpio.h
      ├── mpich-4.2.0_mpi.h -> ../../../../../src/common/mpich/4.2.0/mpi.h
      ├── mpich-4.2.0_mpio.h -> ../../../../../src/common/mpich/4.2.0/mpio.h
      ├── mpich-4.2.0_mpi_proto.h -> ../../../../../src/common/mpich/4.2.0/mpi_proto.h
      ├── ompi-1.8.8_mpi.h -> ../../../../../src/common/openmpi/1.8.8/mpi.h
      ├── ompi-2.1.6_mpi.h -> ../../../../../src/common/openmpi/2.1.6/mpi.h
      ├── ompi-4.1.6_mpi.h -> ../../../../../src/common/openmpi/4.1.6/mpi.h
      ├── ompi-5.0.3_mpi.h -> ../../../../../src/common/openmpi/5.0.3/mpi.h
      └── wrapper_f.h

How to add a new base header
----------------------------

Below is the procedure to follow to add a base header for the implementation <implementation_name> in the version <version>.

#. **[global]**: Create the folder :file:`src/common/<implementation_name>/<version>`
#. **[global]**: Copy the headers inside the previous folder. The existing names are:

    - :file:`mpi.h`
    - :file:`mpio.h` (IntelMPI, MPICH)
    - :file:`mpi_proto.h` (MPICH since 4.2.2)

#. [:file:`src/generator/generator.py`]: Add the :code:`<version>` into the available versions dictionary: :code:`mpi_availabe_target_version`
#. [:file:`src/generator/generator.py`]: Update the default version of the implementation by editing the dictionary :code:`mpi_target_version`.
#. [:file:`src/generator/generator.py`]: Complete the helpers in the module description and in the docopt strings (below the :code:`__main__` check)
#. **[global]**: Go to the :file:`src/interface/header/scripts/<implementation_name>_headers` directory
#. **[global]**: Create a symbolic link from the new header in :file:`../../../../../src/common/<implementation_name>/<version>`. The current nomenclature for link naming is as follows:

    - OpenMPI: :file:`ompi-<version>_mpi.h`
    - IntelMPI: :file:`intelmpi-<version>_mpi.h`
    - MPICH: :file:`mpich-<version>_mpi.h`

#. **[global]**: Repeat the previous step for each subdirectories inside :file:`src/preload/header/scripts` which match with the :code:`<implementation_name>`

Now the new header is ready to be processed by the generator.


.. topic::  Example with IntelMPI 24.0.0

    Installing header files:

    .. code-block:: bash

        wi4mpi_dir=$(pwd)
        #
        # New folder
        #
        mkdir -p src/common/intelmpi/24.0.0
        #
        # Copy files
        #
        cp <path_to>/mpi.h src/common/intelmpi/24.0.0/.
        cp <path_to>/mpio.h src/common/intelmpi/24.0.0/.
        #
        # Interface links
        #
        cd src/interface/header/scripts/intel_headers
        ln -s ../../../../../src/common/intelmpi/24.0.0/mpi.h intelmpi-24.0.0_mpi.h
        ln -s ../../../../../src/common/intelmpi/24.0.0/mpio.h intelmpi-24.0.0_mpio.h
        cd ${wi4mpi_dir}
        #
        # Preload links
        #
        cd src/preload/header/scripts/intel_intel_headers
        ln -s ../../../../../src/common/intelmpi/24.0.0/mpi.h intelmpi-24.0.0_mpi.h
        ln -s ../../../../../src/common/intelmpi/24.0.0/mpio.h intelmpi-24.0.0_mpio.h
        cd ..
        cd src/preload/header/scripts/intel_mpich_headers
        ln -s ../../../../../src/common/intelmpi/24.0.0/mpi.h intelmpi-24.0.0_mpi.h
        ln -s ../../../../../src/common/intelmpi/24.0.0/mpio.h intelmpi-24.0.0_mpio.h
        cd ..
        cd src/preload/header/scripts/intel_ompi_headers
        ln -s ../../../../../src/common/intelmpi/24.0.0/mpi.h intelmpi-24.0.0_mpi.h
        ln -s ../../../../../src/common/intelmpi/24.0.0/mpio.h intelmpi-24.0.0_mpio.h
        cd ..
        cd src/preload/header/scripts/mpich_intel_headers
        ln -s ../../../../../src/common/intelmpi/24.0.0/mpi.h intelmpi-24.0.0_mpi.h
        ln -s ../../../../../src/common/intelmpi/24.0.0/mpio.h intelmpi-24.0.0_mpio.h
        cd ..
        cd src/preload/header/scripts/ompi_intel_headers
        ln -s ../../../../../src/common/intelmpi/24.0.0/mpi.h intelmpi-24.0.0_mpi.h
        ln -s ../../../../../src/common/intelmpi/24.0.0/mpio.h intelmpi-24.0.0_mpio.h
        cd ${wi4mpi_dir}

    Updating module description and helper in :file:`generator.py`:

    .. code-block:: python

          intelmpi_version      Version of the target Intel MPI
                                Supported versions:
                                    * 20.0.0 (alias: 20)
                                    * 24.0.0 (alias: 24)

    Updating default version of intelmpi in :file:`generator.py`:

    .. code-block:: python

            mpi_target_version = {
                "openmpi": "5.0.3",
                "mpich": "4.2.0",
                "intelmpi": "24.0.0",
            }

    Adding version 24.0.0 in :file:`generator.py`:

    .. code-block:: python

            mpi_availabe_target_version = {
                "openmpi": ["1.8.8", "2.1.6", "4.1.6", "5.0.3"],
                "mpich": ["3.1.2", "3.4.3", "4.2.0"],
                "intelmpi": ["20.0.0", "24.0.0"],
            }

    Adding alias 24 in :file:`generator.py` if necessary:

    .. code-block:: python

            alias_intelmpi = {
                "20": "20.0.0",
                "24": "24.0.0",
            }

Files for regular expression
----------------------------

The :code:`re` module is used to perform line-by-line or block-by-block replacements.
The :code:`re.sub` command is used directly in the code for small replacements.

For larger replacements, lists of commands are written in files placed in `src/resources/generator_data/headers`.
Here is the exhaustive list of these files:

- :file:`header._common_generate_app_mpih.replace`
- :file:`intelintelheader.__aux_generate_run_mpioh.replace`
- :file:`intelintelheader._common_generate_app_mpih.replace`
- :file:`intelintelheader._common_generate_app_mpioh.replace`
- :file:`intelintelheader._preload_exception_header_run_mpih.replace`
- :file:`intelompiheader.ompi_replace_mpi_with_rmpi.replace`
- :file:`mpcheader._mpc_exceptions_run_mpih.replace`
- :file:`ompiheader._replace_mpi_with_rmpi.ompiompi.replace`
- :file:`ompiheader._replace_mpi_with_rmpi.replace`
- :file:`ompiintelheader._app_to_run.replace`
- :file:`ompiintelheader._run_to_app.bloc_p0.replace`
- :file:`ompiintelheader._run_to_app.bloc_r0.replace`
- :file:`ompiintelheader._run_to_app.replace`

They are the inputs to the :code:`textoperator.replacement_from_conf_file` command.

.. note::

    The separator used in replacement is ``@``.


It is also possible to perform block replacements. For this, blocks of text to be searched and replaced are written in separate files.
The following files are the inputs to the :code:`textoperator.replace_bloc_from_conf_file` command:

- :file:`header._common_generate_app_mpih.bloc_00.pattern`
- :file:`header._common_generate_app_mpih.bloc_00.replace`
- :file:`header._common_generate_app_mpih.bloc_01.pattern`
- :file:`header._common_generate_app_mpih.bloc_01.replace`
- :file:`header._common_generate_app_mpih.bloc_02.pattern`
- :file:`header._common_generate_app_mpih.bloc_02.replace`
- :file:`header._common_generate_app_mpih.bloc_06.pattern`
- :file:`header._common_generate_app_mpih.bloc_06.replace`
- :file:`header._common_generate_app_mpih.bloc_08a.pattern`
- :file:`header._common_generate_app_mpih.bloc_08.pattern`
- :file:`header._common_generate_app_mpih.bloc_08.replace`
- :file:`header._common_generate_app_mpih.bloc_09.pattern`
- :file:`header._common_generate_app_mpih.bloc_09.replace`

Finally, the :code:`textoperator.delete_bloc_from_conf_file` command, which is a special case of the previous command, allows you to search for and delete blocks of lines.
The following files are used for this purpose:

- :file:`header._common_generate_app_mpih.bloc_03.delete`
- :file:`header._common_generate_app_mpih.bloc_04.delete`
- :file:`header._common_generate_app_mpih.bloc_05.delete`
- :file:`header._common_generate_app_mpih.bloc_06.delete`
- :file:`header._common_generate_app_mpih.bloc_07.delete`
- :file:`header._common_generate_app_mpih.bloc_10.delete`

Output files
############

.. todo: Ooutput Input files in proper section or split inside Header generator and Code generator ?

The generator writes several files:

- headers files 
- C files
- log file

Header files
============
The concerned header files are

- :file:`app_mpi.h`: application side MPI header
- :file:`run_mpi.h`: runtime side MPI header
- :file:`wrapper_f.h`: interface version of the Fortran header

and, if applicable,

- :file:`run_mpio.h`
- :file:`mpcmp.h`: dedicated to MPC
- :file:`sctk_types.h`: dedicated to MPC
- :file:`app_mpio.h`
- :file:`app_mpi_proto.h`: additional file for MPICH from version 4.2.2
- :file:`run_mpio.h`
- :file:`run_mpi_proto.h`: additional file for MPICH from version 4.2.2

see  :numref:`interface-header` and :numref:`preload-header` for an overview.

.. _interface-header:

.. table:: Files in :file:`<wi4mpi_dir>/src/interface/header/<Folder>`
    :align: center
    :widths: auto


    +-----------+------------------+---------------+-------------+--------------+------------+-----------------+
    | Folder    | app_mpi.h        | run_mpi.h     | wrapper_f.h | run_mpio.h   |  mpcmp.h   |  sctk_types.h   |
    +===========+==================+===============+=============+==============+============+=================+
    | _INTEL    |       `✓`        |    `✓`        |     `✓`     |    `✓`       |            |                 |
    +-----------+------------------+---------------+-------------+--------------+------------+-----------------+
    | _MPC      |       `✓`        |    `✓`        |     `✓`     |    `✓`       |    `✓`     |       `✓`       |
    +-----------+------------------+---------------+-------------+--------------+------------+-----------------+
    | _MPICH    |       `✓`        |    `✓` `(*)`  |     `✓`     |    `✓`       |            |                 |
    +-----------+------------------+---------------+-------------+--------------+------------+-----------------+
    | _OMPI     |       `✓`        |    `✓`        |     `✓`     |              |            |                 |
    +-----------+------------------+---------------+-------------+--------------+------------+-----------------+

.. note::

    - (*) additional file :file:`run_mpi_proto.h` for MPICH from version 4.2.2

.. _preload-header:

.. table:: Files in :file:`<wi4mpi_dir>/src/preload/header/<Folder>`.
    :align: center
    :widths: auto

    +-------------+------------------+-----------------+-------------+------------+------------+
    | Folder      | app_mpi.h        | run_mpi.h       | wrapper_f.h | app_mpio.h | run_mpio.h |
    +=============+==================+=================+=============+============+============+
    | INTEL_INTEL |       `✓`        |    `✓`          |     `✓`     |    `✓`     |   `✓`      |
    +-------------+------------------+-----------------+-------------+------------+------------+
    | INTEL_MPICH |       `✓`        |    `✓` `(*)`    |     `✓`     |    `✓`     |   `✓`      |
    +-------------+------------------+-----------------+-------------+------------+------------+
    | INTEL_OMPI  |       `✓`        |    `✓`          |     `✓`     |    `✓`     |            |
    +-------------+------------------+-----------------+-------------+------------+------------+
    | MPICH_INTEL |       `✓` `(**)` |    `✓`          |     `✓`     |    `✓`     |   `✓`      |
    +-------------+------------------+-----------------+-------------+------------+------------+
    | MPICH_MPICH |       `✓` `(**)` |    `✓` `(*)`    |     `✓`     |    `✓`     |   `✓`      |
    +-------------+------------------+-----------------+-------------+------------+------------+
    | MPICH_OMPI  |       `✓` `(**)` |    `✓`          |     `✓`     |    `✓`     |            |
    +-------------+------------------+-----------------+-------------+------------+------------+
    | OMPI_INTEL  |       `✓`        |    `✓`          |     `✓`     |            |   `✓`      |
    +-------------+------------------+-----------------+-------------+------------+------------+
    | OMPI_MPICH  |       `✓`        |    `✓` `(*)`    |     `✓`     |            |   `✓`      |
    +-------------+------------------+-----------------+-------------+------------+------------+
    | OMPI_OMPI   |       `✓`        |    `✓`          |     `✓`     |            |            |
    +-------------+------------------+-----------------+-------------+------------+------------+

.. note::

    - (*) additional file  :file:`run_mpi_proto.h` for MPICH from version 4.2.2
    - (**) additional file  :file:`app_mpi_proto.h` for MPICH from version 4.2.2

.. _output_files_c_files:

C files
=======

The concerned code files are

- :file:`<wi4mpi_dir>/src/preload/gen/mpi_translation_c.c`
- :file:`<wi4mpi_dir>/src/interface/gen/mpi_translation_c.c`
- :file:`<wi4mpi_dir>/src/interface/gen/interface_c.c`

Log file
========

Warning, debug, info, error messages are written in file :file:`generator.log`.
They are managed by the python module :code:`logging` and configured by :file:`<wi4mpi_dir>/src/generator/logging.conf`.


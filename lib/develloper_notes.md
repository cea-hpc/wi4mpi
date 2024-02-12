# Code Generation and Templating Choice
## Code Generation Approach

The decision to use code generation for Wi4MPI is driven by the need to efficiently handle a large number of MPI functions. Manually writing and maintaining the code for each function could be error-prone, time-consuming, and challenging to scale.

By adopting a code generation approach, the Wi4MPI project can automate the generation of repetitive code structures, ensuring consistency and reducing the likelihood of errors. This becomes particularly advantageous when dealing with a comprehensive set of MPI functions, where the majority of the code follows a similar pattern.

## Templating with Jinja

Jinja was chosen as the templating engine for Wi4MPI due to its flexibility, ease of use, and compatibility with Python. Here are some key reasons for selecting Jinja:

* Expressive Syntax: Jinja provides a concise and expressive syntax that allows for the creation of dynamic templates. This is crucial when generating complex code structures with conditional logic and loops.

* Logic Control: Jinja supports if statements, loops, and other control structures, enabling the generation of code based on specific conditions. This is essential when handling variations in MPI functions.

* Separation of Concerns: Templating with Jinja allows for a clear separation of concerns between the template logic and the data. This separation enhances maintainability and makes it easier to update or modify the template without affecting the underlying data.

* Extensibility: Jinja supports the use of macros and includes, facilitating the organization of templates into modular components. This extensibility is beneficial when dealing with a diverse set of MPI functions.

* Integration with Python: Since Jinja is written in Python, it integrates seamlessly with the Python scripting language. This integration is advantageous for the Wi4MPI project, which uses Python scripts to manage and automate the code generation process.

Overall, the combination of code generation and Jinja templating streamlines the development process, allowing the Wi4MPI project to efficiently handle a large number of MPI functions while maintaining code quality and consistency.

## Generator programation rules

### Linter

The generator is coded in Python and a linter is used.
Linter usage: 
    
    $ <wi4mpi_root>/scripts/python_linter/linter.sh lib

To use it you need:

  * black >= 23
  * pylint
  * flake8

### Non-regression test

A non regression test is inside `<wi4mpi_root>/dev` it will check that all generated header files are the same as reference files in `<wi4mpi_root>/src/preload/header` and `<wi4mpi_root>/src/interface/header`.
This test will also copy the generated  file `translation_mpi_c.c` inside `<wi4mpi_root>/src/preload/gen` and run a build.

### Logger

The configuration of the logger is in `<wi4mpi_root>/lib/logging.conf`.
During the run of the generator, info and warning will be printed in the standard output. Additionnal messages will be printed inside `<wi4mpi_root>/generator.log`.

# Generator Structure

The generator files are in directory `lib`.
The input of code generator are inside `<wi4mpi_root>lib/code_generation_input/C`

## Generator organization

### Generator

The command `<wi4mpi_root>/lib/generator.py` launch the generation of header and code files.
Example of use:

    $ dir_gen_interface=$(mktemp -d)
    $ dir_gen_preload=$(mktemp -d)
    $ dir_gen_c_preload=$(mktemp -d)
    $ ./lib/generator.py --interface_header_dir=$dir_gen_interface --preload_header_dir=$dir_gen_preload --c_preload_gen_dir=$dir_gen_c_preload

It will instantiate a Generator object which will launch the `generate` method associated to each file.

### Headers generation

`header.py` contains the meta-class HeaderGenerator. All others classes which generate header files are in separate modules:

* intelheader.py
* intelintelheader.py
* intelmpichheader.py
* intelompiheader.py
* mpcheader.py
* mpichheader.py
* mpichintelheader.py
* mpichmpichheader.py
* mpichompiheader.py
* ompiheader.py
* ompiintelheader.py
* ompimpichheader.py
* ompiompiheader.py

They all inherit directly or indirectly from HeaderGenerator.

The following methods have to be overridden:

  * `_generate_wrapper_fh`: Generate wrapper F header file.
  * `_generate_run_mpih`: Generate run MPI header file.
  * `_generate_app_mpih`: Generate app MPI header file.
  * `_generate_run_mpioh`: Generate run MPIO header file.
  * `generate`: Generate MPI header files.

### Patching files

Some functions used to manipulate strings are in `textoperator.py`

The files `<wi4mpi_root>/lib/etc/*.replace` are used to patch header files
They are used by the following methods of `textoperator.py`:

  * `replacement_from_conf_file`
  * `delete_bloc_from_conf_file`

### Code Generation

`codegen.py` contains the meta-class CodeGenerator and the sub-class CPreloadGenerator.
The following methods have to be overridden:

  * `_generate_static_side`: Generate the static side of the output file using Jinja templates.
  * `_generate_declarations_side`: Generate the declarations side of the output file using Jinja template
  * `_generate_function`: Generate the function part (asm/app/run) using Jinja templates.
  * `_generate_dlsym_side`: Generate the dlsym side of the output file using Jinja templates.
  * `generate`: Generate the output file

The output file is processed by `clang-format`, so you need it in your PATH.

## Template Files

### in_functions.jinja
This file houses functions responsible for declaring and allocating temporary variables used in translations. It defines the following macros:

- `type_prefix(prefix, type)`: Tests if the type name begins with "MPI" and adds the specified prefix if true.
- `tmp_decl(map, arg)`: Creates corresponding temporary variables based on the definitions in the provided dictionaries. It can also handle array allocations.
- `convert_in(arg, map, idx)`: Generates the conversion from application to runtime for a given argument, with an optional index for array iterations.
- `handle_local_var(local_var)`: Takes a dictionary as input, describing how to compute local variables. It generates the declaration of local variables and calls the initialization function specified in the dictionary.

### out_function.jinja
This file contains a complex Jinja macro responsible for managing translations from runtime to application. The main function is `convert_out(arg, map, idx)`, which generates the appropriate translation call. The `idx` parameter is used for naming iteration variables if needed.

### template_A.jinja
Code generation for one A_MPI_Xxxx function. It includes a test to determine if the function needs generation or can be taken from an existing file. For function generation, it calls functions from `in_functions.jinja` and `out_function.jinja`.

### template_R.jinja
Similar to `template_A.jinja`, but for R_MPI_Xxxx functions.

### template_asm.jinja
Generates the assembly code chooser for one function, with a test to determine if generation is needed.

### template_declarations.jinja
Generates global variables for debug prints and timeouts for all functions.

### template_dlsym.jinja
Generates the `dlopen`/`dlsym` initialization function and timeout/debug initialization functions.

### template_static.jinja
Contains all static code, including constants and includes, used by the generated code. Includes two other files defining OMPI constants and Intel MPI constants.

## JSON Files

### exceptions.json
Describes non-generated functions in Wi4MPI. The structure includes information about the function's generation status and, if not generated, a path to an existing file.

### Types.json
Describes translated types and their constant values as defined in the MPI norm. Used for initializing translation tables in library initialization functions.

### mappers.json
Describes each translation mapper, controlling code generation and translation of MPI function parameters.

### functions.json
Describes all MPI functions as defined in the MPI norm, including function name, arguments, local variables, and return values.

## Non-generated Code

Functions or parts of Wi4MPI code that do not fit the generator template are provided in static files under the `not_generated` directory. These files are organized by language, type (A, R, asm), and MPI function name.

# Extending the Generated Code

## Add a New Generated Function

1. Read the MPI norm and write the entry in `functions.json`.
2. Choose mappers for each parameter and define variable dictionaries.
3. If a new mapper is needed, update `mappers.json` and write the a2r/r2a function in `mappers.h`.
4. Update `functions.json` with the new mapper's name for the corresponding variable.
5. Test the new function.

## Add a New Non-generated Function

1. Attempt to add it as a generated function by describing it in `functions.json`.
2. For non-generated code, add a file at the appropriate location (as described in the document) and an entry in `exceptions.json`. Non-generated parts often concern A_MPI_Xxx functions.

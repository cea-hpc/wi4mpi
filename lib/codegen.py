#!/usr/bin/env python3
"""
This module provides classes and methods for generating MPI translation code files.

"""

import os
import re
from subprocess import call
import json
from logging import getLogger
from logging.config import fileConfig
import jinja2

fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)), "logging.conf"))
log = getLogger("code_logger")


class CodeGenerator:
    """
    Class for generating MPI translation code files.

    This class contains methods for generating MPI translation code files.

    Attributes:
        _functions_definitions_json_file (str): Name of the json file which describes all MPI functions as defined in the MPI norm, including function name, arguments, local variables, and return values.
        _functions_mappers_json (str): Name of the json file which describes each translation mapper, controlling code generation and translation of MPI function parameters.
        _types_json (str): Name of the json which describes translated types and their constant values as defined in the MPI norm.
        _exceptions_json (str): Name of the json file which describes non-generated functions in Wi4MPI.
        _declarations_side_template_file (str): Name of jinja file which generates global variables for debug prints and timeouts for all functions.
        _static_side_template_file (str): Name of jinja file which contains all static code, including constants and includes, used by the generated code.
        _asm_side_template_file (str): Name of jinja file which generates the assembly code chooser for one function, with a test to determine if generation is needed.
        _app_side_template_file (str): Name of jinja file which generates code for one A_MPI_Xxxx function.
        _run_side_template_file (str): Name of jinja file which generates code for one R_MPI_Xxxx function.
        _dlsym_side_template_file (str): Name of jinja file which generates the dlopen/dlsym initialization function and timeout/debug initialization functions.
        output_file (str): Output file path.
        dir_input (str): Input directory path.

    Methods:
        set_directories: Set input and output directories for header generation.
        __init__: Initialize the CodeGenerator object.
        clang_format: Format code.
        write_file_append: Add lines at the end of the input file.
        typevar:

    """  # noqa: E501

    _functions_definitions_json_file = "functions.json"
    _functions_mappers_json = "mappers.json"
    _declarations_side_template_file = "template_declarations.jinja"
    _static_side_template_file = "template_static.jinja"
    _asm_side_template_file = "template_asm.jinja"
    _app_side_template_file = "template_A.jinja"
    _run_side_template_file = "template_R.jinja"
    _types_json = "types.json"
    _exceptions_json = "exceptions.json"
    _dlsym_side_template_file = "template_dlsym.jinja"
    output_file = ""
    dir_input = ""
    dir_output = ""

    def clang_format(self, file_to_format):
        """
        Format code with LLVM style.

        Args:
            file_to_format (str): Path of the file to format.

        Returns:
            None
        """
        call(["clang-format", "-style=LLVM", "-i", file_to_format])

    def write_file_append(self, file_to_edit, content):
        """
        Write lines at the end of the file.

        Args:
            file_to_edit (str): Path of the file to edit.
            content (str): Strings to append to the file.

        Returns:
            None
        """
        with open(file_to_edit, "a", encoding="utf-8") as file_descriptor:
            file_descriptor.write(content)

    def set_directories(self, dir_input, dir_output):
        """
        Set input and output directories for header generation.

        Args:
            dir_input (str, optional): The input directory path. Defaults to "".
            dir_output (str, optional): The output directory path. Defaults to "".

        Returns:
            None
        """
        self.dir_input = dir_input
        self.dir_output = dir_output
        os.makedirs(self.dir_output, exist_ok=True)
        self.output_file = os.path.join(dir_output, self.output_file)
        self._functions_definitions_json_file = os.path.join(
            dir_input, self._functions_definitions_json_file
        )
        self._functions_mappers_json = os.path.join(dir_input, self._functions_mappers_json)
        self._types_json = os.path.join(dir_input, self._types_json)
        self._exceptions_json = os.path.join(dir_input, self._exceptions_json)

    def __getattr__(self, name):
        if name == "set_directories":
            return self.set_directories
        if name == "clang_format":
            return self.clang_format
        if name == "write_file_append":
            return self.write_file_append
        raise AttributeError(f"{self.__name__} does not have attribute '{name}'")

    def _generate_static_side(self):
        """
        Generate the static side of the output file using Jinja templates.

        This method renders the static side template file using Jinja2
        and appends the rendered content to the output file.

        Example:
            >>> obj = YourClassName()
            >>> obj._generate_static_side()
        """

    def _generate_declarations_side(self):
        """
        Generate the declarations side of the output file using Jinja templates.

        This method renders the declarations side template file using Jinja2
        and appends the rendered content to the output file.

        Example:
            >>> obj = YourClassName()
            >>> obj._generate_declarations_side()
        """

    def _generate_function(self, function, template_file):
        """
        Generate the function using Jinja templates.

        This method could render the ASM, application or run side template file using Jinja2
        and appends the rendered content to the output file.

        Example:
            >>> obj = YourClassName()
            >>> obj._generate_function("MPI_Abort", "template.jinja")
        """

    def _generate_dlsym_side(self):
        """
        Generate the dlsym side of the output file using Jinja templates.

        This method renders the dlsym side template file using Jinja2
        and appends the rendered content to the output file.

        Example:
            >>> obj = YourClassName()
            >>> obj._generate_dlsym_side()
        """

    def generate(self):
        """
        Generate output_file.
        """

    def __init__(self):
        """
        Initialization
        """


class CPreloadGenerator(CodeGenerator):
    """
    CPreloadGenerator class for generating MPI translation C file.
    """

    output_file = "test_c_gen_preload.c"
    data_functions = None
    data_mappers = None
    data_types = None
    data_exceptions = None

    def __init__(self, dir_input="lib/code_generation_input/C", dir_output="src/preload/new_gen"):
        log.info("Generation of preload C file.")
        self.set_directories(dir_input, dir_output)
        with open(self._functions_definitions_json_file, "r", encoding="utf-8") as file_descriptor:
            self.data_functions = json.load(file_descriptor)
        with open(self._functions_mappers_json, "r", encoding="utf-8") as file_descriptor:
            self.data_mappers = json.load(file_descriptor)
        with open(self._types_json, "r", encoding="utf-8") as file_descriptor:
            self.data_types = json.load(file_descriptor)
        with open(self._exceptions_json, "r", encoding="utf-8") as file_descriptor:
            self.data_exceptions = json.load(file_descriptor)

    def typevar(self, var, typename):
        """
        Generate a type declaration string based on the variable name and type.

        Args:
            var (str): The variable name with potential array brackets.
            typename (str): The type name.

        Returns:
            str: The type declaration string.

        Example:
            >>> obj = YourClassName()
            >>> obj.typevar("arr[10]", "int")
            'int **********arr'
        """
        pattern = r"\[[0-9]*\]"
        sub = re.split(pattern, var)
        ret = typename + " " + "*" * len(sub[1:]) + sub[0]
        return ret

    def _generate_static_side(self):
        """
        Generate the static side of the output file using Jinja templates.

        This method renders the static side template file using Jinja2
        and appends the rendered content to the output file.

        Example:
            >>> obj = YourClassName()
            >>> obj._generate_static_side()
        """
        log.debug("Run _generate_static_side")
        jinja_env = jinja2.Environment(
            loader=jinja2.FileSystemLoader(self.dir_input), trim_blocks=True
        )
        jinja_template = jinja_env.get_template(self._static_side_template_file)
        rendered_template = jinja_template.render({})
        self.write_file_append(self.output_file, rendered_template + "\n")

    def _generate_declarations_side(self):
        """
        Generate the declarations side of the output file using Jinja templates.

        This method renders the declarations side template file using Jinja2
        and appends the rendered content to the output file.

        Example:
            >>> obj = YourClassName()
            >>> obj._generate_declarations_side()
        """
        log.debug("Run _generate_declaration_side")
        jinja_env = jinja2.Environment(
            loader=jinja2.FileSystemLoader(self.dir_input), trim_blocks=True
        )
        jinja_env.filters["typevar"] = self.typevar
        jinja_template = jinja_env.get_template(self._declarations_side_template_file)
        rendered_template = jinja_template.render({
            "funcs": self.data_functions, "mappers": self.data_mappers
        })
        self.write_file_append(self.output_file, rendered_template + "\n")

    def _generate_function(self, function, template_file):
        """
        Generate the function using Jinja templates.

        This method could render the ASM, application or run side template file using Jinja2
        and appends the rendered content to the output file.

        Example:
            >>> obj = YourClassName()
            >>> obj._generate_function("MPI_Abort", "template.jinja")
        """

        def _msg(function, template_file):
            return f"Run _generate_function: {function} {template_file}"

        log.debug(_msg(function, template_file))
        rendered_template = ""
        jinja_env = jinja2.Environment(
            loader=jinja2.FileSystemLoader(self.dir_input), trim_blocks=True
        )
        jinja_env.filters["typevar"] = self.typevar
        jinja_template = jinja_env.get_template(template_file)
        rendered_template += jinja_template.render({
            "func": function, "mappers": self.data_mappers, "conf": self.data_exceptions
        })
        self.write_file_append(self.output_file, rendered_template + "\n")

    def _generate_dlsym_side(self):
        """
        Generate the dlsym side of the output file using Jinja templates.

        This method renders the dlsym side template file using Jinja2
        and appends the rendered content to the output file.

        Example:
            >>> obj = YourClassName()
            >>> obj._generate_dlsym_side()
        """
        log.debug("Run _generate_dlsym_side")
        jinja_env = jinja2.Environment(
            loader=jinja2.FileSystemLoader(self.dir_input), trim_blocks=True
        )
        jinja_template = jinja_env.get_template(self._dlsym_side_template_file)
        rendered_template = jinja_template.render({
            "funcs": self.data_functions, "types": self.data_types
        })
        self.write_file_append(self.output_file, rendered_template + "\n")

    def generate(self):
        self._generate_static_side()
        self._generate_declarations_side()
        for function in self.data_functions:
            self._generate_function(function, self._asm_side_template_file)
            self._generate_function(function, self._app_side_template_file)
            self._generate_function(function, self._run_side_template_file)
        self._generate_dlsym_side()
        self.clang_format(self.output_file)

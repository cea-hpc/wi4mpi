#!/usr/bin/env python3
"""
This module provides classes and methods for generating MPI translation code files.

"""

import os
import re
from abc import abstractmethod
from subprocess import call
from logging import getLogger
from logging.config import fileConfig
import jinja2
from textoperator import load_json_file

fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)), "logging.conf"))
log = getLogger("code_logger")


class CodeGenerator:
    """
    Class for generating MPI translation code files.

    This class contains methods for generating MPI translation code files.

    Attributes:
        json_files (dict): json file path.
        jinja_files (dict): Template file path.
        data (dict): Load of json file.
        output_file (str): Output file path.
        dir_input (str): Input directory path.

    Methods:
        set_directories: Set input and output directories for code generation.
        __init__: Initialize the CodeGenerator object.
        clang_format: Format code.
        write_file_append: Add lines at the end of the input file.
        typevar:

    """  # noqa: E501

    json_files = {}
    jinja_files = {}
    data = {}
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

    @abstractmethod
    def _generate_static_side(self):
        """
        Abstract method, must be implemented by a subclass.
        Generate the static side of the output file using Jinja templates.
        """

    @abstractmethod
    def _generate_declarations_side(self):
        """
        Abstract method, must be implemented by a subclass.
        Generate the declarations side of the output file using Jinja templates.
        """

    @abstractmethod
    def _generate_function(self, function, template_file):
        """
        Abstract method, must be implemented by a subclass.
        Generate the function using Jinja templates.
        """

    @abstractmethod
    def _generate_dlsym_side(self):
        """
        Abstract method, must be implemented by a subclass.
        Generate the dlsym side of the output file using Jinja templates.
        """

    @abstractmethod
    def generate(self):
        """
        Abstract method, must be implemented by a subclass.
        Generate output_file.
        """

    @abstractmethod
    def __init__(self):
        """
        Initialization
        """


class CPreloadGenerator(CodeGenerator):
    """
    CPreloadGenerator class for generating MPI translation C file.
    """

    def __init__(self, dir_input="lib/code_generation_input/C", dir_output="src/preload/new_gen"):
        """
        json_files:
            functions_definitions (str): Name of the json file which describes all MPI functions as
            defined in the MPI norm, including function name, arguments, local variables, and retur
            n values.
            functions_mappers_json (str): Name of the json file which describes each translation ma
            pper, controlling code generation and translation of MPI function parameters.
            types (str): Name of the json which describes translated types and their constant value
            s as defined in the MPI norm.
            exceptions (str): Name of the json which describes non-generated functions in Wi4MPI.
        """
        log.info("Generation of preload C file.")
        self.output_file = "test_c_gen_preload.c"
        self.set_directories(dir_input, dir_output)
        self.json_files = {
            "functions_definitions": os.path.join(dir_input, "functions.json"),
            "functions_mappers": os.path.join(dir_input, "mappers.json"),
            "types": os.path.join(dir_input, "types.json"),
            "exceptions": os.path.join(dir_input, "exceptions.json"),
        }
        self.jinja_files = {
            "declarations": "template_declarations.jinja",
            "static": "template_static.jinja",
            "asm": "template_asm.jinja",
            "app": "template_A.jinja",
            "run": "template_R.jinja",
            "dlsym": "template_dlsym.jinja",
        }
        self.data = {
            "functions": load_json_file(self.json_files["functions_definitions"]),
            "mappers": load_json_file(self.json_files["functions_mappers"]),
            "types": load_json_file(self.json_files["types"]),
            "exceptions": load_json_file(self.json_files["exceptions"]),
        }

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
        jinja_template = jinja_env.get_template(self.jinja_files["static"])
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
        jinja_template = jinja_env.get_template(self.jinja_files["declarations"])
        rendered_template = jinja_template.render({
            "funcs": self.data["functions"], "mappers": self.data["mappers"]
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
            "func": function, "mappers": self.data["mappers"], "conf": self.data["exceptions"]
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
        jinja_template = jinja_env.get_template(self.jinja_files["dlsym"])
        rendered_template = jinja_template.render({
            "funcs": self.data["functions"], "types": self.data["types"]
        })
        self.write_file_append(self.output_file, rendered_template + "\n")

    def generate(self):
        self._generate_static_side()
        self._generate_declarations_side()
        for function in self.data["functions"]:
            self._generate_function(function, self.jinja_files["asm"])
            self._generate_function(function, self.jinja_files["app"])
            self._generate_function(function, self.jinja_files["run"])
        self._generate_dlsym_side()
        self.clang_format(self.output_file)

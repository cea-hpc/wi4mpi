#!/usr/bin/env python3
"""
This module provides the abstract classe and methods for generating MPI translation code files.

"""

import os
import re
from abc import abstractmethod
from logging import getLogger
from logging.config import fileConfig
import jinja2
from textoperator import load_json_file
from codegenerator import CodeGenerator
fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)), "logging.conf"))
log = getLogger("code_logger")

class CPreloadGenerator(CodeGenerator):
    """
    CPreloadGenerator class for generating MPI translation C file.
    """

    def __init__(self, dir_input="lib/etc/code", dir_output="src/preload/new_gen"):
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
            "functions_definitions": os.path.join(dir_input, "common/jsons/functions.json"),
            "functions_mappers": os.path.join(dir_input, "C/jsons/mappers.json"),
            "types": os.path.join(dir_input, "common/jsons/types.json"),
            "exceptions": os.path.join(dir_input, "C/jsons/exceptions.json"),
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
        self.jinja_dir=os.path.join(dir_input,"C/templates/")
        self.static_sources_dir=os.path.join(dir_input,"C/static_sources/")

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
            loader=jinja2.FileSystemLoader([self.jinja_dir,self.static_sources_dir]), trim_blocks=True
        )
        jinja_template = jinja_env.get_template(self.jinja_files["static"])
        rendered_template = jinja_template.render()
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
            loader=jinja2.FileSystemLoader([self.jinja_dir, self.static_sources_dir]), trim_blocks=True
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
            loader=jinja2.FileSystemLoader([self.jinja_dir, self.static_sources_dir]), trim_blocks=True
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
            loader=jinja2.FileSystemLoader([self.jinja_dir,self.static_sources_dir]), trim_blocks=True
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

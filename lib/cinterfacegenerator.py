#!/usr/bin/env python3
"""
This module provides the abstract classe and methods for generating MPI translation code files.

"""

import os
import re
from logging import getLogger
from logging.config import fileConfig
import jinja2
from textoperator import (
    load_json_file,
    clang_format,
    write_file_append,
)
from codegenerator import CodeGenerator

fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)), "logging.conf"))
log = getLogger("code_logger")


class CInterfaceGenerator(CodeGenerator):
    """
    CPreloadGenerator class for generating MPI translation C file.
    """

    def __init__(self, dir_input="lib/etc/code", dir_output="src/interface/new_gen"):
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
        log.info("Generation of interface C file.")
        self.output_file = "test_c_gen_interface.c"
        self.interface_file = "interface_c.c"
        self.set_directories(dir_input, dir_output)
        self.interface_file = os.path.join(dir_output, self.interface_file)
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
            "dlsym_interface": "template_dlsym_interface.jinja",
            "interface": "template_interface.jinja",
            "interface_entry": "template_interface_entry.jinja",
        }
        self.data = {
            "functions": load_json_file(self.json_files["functions_definitions"]),
            "mappers": load_json_file(self.json_files["functions_mappers"]),
            "types": load_json_file(self.json_files["types"]),
            "exceptions": load_json_file(self.json_files["exceptions"]),
        }
        self.jinja_dir = os.path.join(dir_input, "C/templates/")
        self.static_sources_dir = os.path.join(dir_input, "C/static_sources/")

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

    def _apply_jinja(self, jinja_name, param_dict):
        """
        generate the code correponding to the application of the dictionnary
        on a jinja template
        """
        _msg = f"Run generate {jinja_name}"
        log.debug(_msg)
        jinja_env = jinja2.Environment(
            loader=jinja2.FileSystemLoader([self.jinja_dir, self.static_sources_dir]),
            trim_blocks=True,
        )
        jinja_env.filters["typevar"] = self.typevar
        jinja_template = jinja_env.get_template(self.jinja_files[jinja_name])
        rendered_template = jinja_template.render(param_dict)
        return rendered_template + "\n"

    def generate(self):
        content = ""
        content += self._apply_jinja("static", {})
        content += self._apply_jinja(
            "declarations", {"funcs": self.data["functions"], "mappers": self.data["mappers"]}
        )
        for function in self.data["functions"]:
            content += self._apply_jinja("asm",{"func": function, "mappers": self.data["mappers"], "conf": self.data["exceptions"],"caller_prefix":"INTERF"})
            content += self._apply_jinja("app",{"func": function, "mappers": self.data["mappers"], "conf": self.data["exceptions"],"decl_ext":"extern"})
            content += self._apply_jinja("run",{"func": function, "mappers": self.data["mappers"], "conf": self.data["exceptions"]})
        content += self._apply_jinja("dlsym",{"funcs": self.data["functions"], "types": self.data["types"],"mpi_libraries":["OMPI","INTEL"]})
        write_file_append(self.output_file, content)
        clang_format(self.output_file)
        content = ""
        content += self._apply_jinja("interface_entry", {"funcs": self.data["functions"]})
        for function in self.data["functions"]:
            content += self._apply_jinja(
                "interface",
                {
                    "func": function,
                    "mappers": self.data["mappers"],
                    "conf": self.data["exceptions"],
                    "mpi_libraries": ["OMPI", "INTEL"],
                },
            )
        content += self._apply_jinja(
            "dlsym_interface", {"funcs": self.data["functions"], "conf": self.data["exceptions"]}
        )
        write_file_append(self.interface_file, content)
        clang_format(self.interface_file)

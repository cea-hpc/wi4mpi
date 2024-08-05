#!/usr/bin/env python3
"""
This module provides the abstract classe and methods for generating MPI translation code files.

"""

import os
from logging import getLogger
from logging.config import fileConfig
from textoperator import (
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
        self.jinja_files["dlsym_interface"] = "template_dlsym_interface.jinja"
        self.jinja_files["interface"] = "template_interface.jinja"
        self.jinja_files["interface_entry"] = "template_interface_entry.jinja"

    def generate(self):
        content = ""
        content += self.apply_jinja("static", {})
        content += self.apply_jinja(
            "declarations", {"funcs": self.data["functions"], "mappers": self.data["mappers"]}
        )
        for function in self.data["functions"]:
            content += self.apply_jinja(
                "asm",
                {
                    "func": function,
                    "mappers": self.data["mappers"],
                    "conf": self.data["exceptions"],
                    "caller_prefix": "INTERF",
                },
            )
            content += self.apply_jinja(
                "app",
                {
                    "func": function,
                    "mappers": self.data["mappers"],
                    "conf": self.data["exceptions"],
                    "decl_ext": "extern",
                },
            )
            content += self.apply_jinja(
                "run",
                {
                    "func": function,
                    "mappers": self.data["mappers"],
                    "conf": self.data["exceptions"],
                },
            )
        content += self.apply_jinja(
            "dlsym",
            {
                "funcs": self.data["functions"],
                "types": self.data["types"],
                "mpi_libraries": ["OMPI", "INTEL"],
            },
        )
        write_file_append(self.output_file, content)
        clang_format(self.output_file)
        content = ""
        content += self.apply_jinja("interface_entry", {"funcs": self.data["functions"]})
        for function in self.data["functions"]:
            content += self.apply_jinja(
                "interface",
                {
                    "func": function,
                    "mappers": self.data["mappers"],
                    "conf": self.data["exceptions"],
                    "mpi_libraries": ["OMPI", "INTEL"],
                },
            )
        content += self.apply_jinja(
            "dlsym_interface", {"funcs": self.data["functions"], "conf": self.data["exceptions"]}
        )
        write_file_append(self.interface_file, content)
        clang_format(self.interface_file)

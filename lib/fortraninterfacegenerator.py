#!/usr/bin/env python3
"""
This module provides the abstract classe and methods for generating MPI translation code files.

"""

import os
from logging import getLogger
from logging.config import fileConfig
from textoperator import (
    clang_format,
    remove_file,
    write_file_append,
)
from codegenerator import CodeGenerator

fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)), "logging.conf"))
log = getLogger("code_logger")


class FortranInterfaceGenerator(CodeGenerator):
    """
    FortranInterfaceGenerator class for generating MPI translation Fortran file.
    """

    def __init__(self, dir_input="lib/etc/code/fortran", dir_output="src/preload/new_gen"):
        """
        json_files:
            functions_definitions (str): Name of the json file which describes all MPI functions as
            defined in the MPI norm, including function name, arguments, local variables, and 
            return values.
            functions_mappers_json (str): Name of the json file which describes each translation 
            mapper, controlling code generation and translation of MPI function parameters.
            types (str): Name of the json which describes translated types and their constant 
            values as defined in the MPI norm.
            exceptions (str): Name of the json which describes non-generated functions in Wi4MPI.
        """
        log.info("Generation of interface Fortran files.")
        self.output_file = "mpi_translation_fort.c"
        self.interface_file = "interface_fort.c"
        self.set_directories(dir_input, dir_output)

    def generate(self):
        self.apply_jinja_dict["asm_dict"]["caller_prefix"] = "CC"
        self.apply_jinja_dict["app_dict"]["caller_prefix"] = "extern"
        self.apply_jinja_dict["dlsym_dict"]["mpi_libraries"] = ["OMPI","INTEL"]
        super().generate()
        remove_file(self.interface_file)
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


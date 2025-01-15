#!/usr/bin/env python3
"""
This module provides the abstract class and methods for generating MPI translation code files.

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


class CInterfaceGenerator(CodeGenerator):
    """
    CPreloadGenerator class for generating MPI translation C file.
    """

    def __init__(self, dir_input="lib/etc/code", dir_output="src/interface/new_gen"):
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
        log.info("Generation of interface C files.")
        self.output_file = "mpi_translation_c.c"
        self.interface_file = "interface_c.c"
        self.set_directories(dir_input, dir_output)
        self.interface_file = os.path.join(dir_output, self.interface_file)

    def generate(self):
        self.apply_jinja_dict["asm_dict"]["caller_prefix"] = "CC"
        self.apply_jinja_dict["app_dict"]["decl_ext"] = ""
        self.apply_jinja_dict["dlsym_dict"]["mpi_libraries"] = ["OMPI", "INTEL"]
        # Warning: Do not use 'apply_jinja' before 'super().generate()'.
        #          dico_jinja_env is a prerequisite that is defined in
        #          'generate()' by the call to 'init_jinja()'
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

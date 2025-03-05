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
    CInterfaceGenerator class for generating MPI translation C file.
    """

    def __init__(self, dir_input="lib/etc/code", dir_output="src/interface/new_gen", mpi_norm=None):
        """
        Initialization of the code generator for interface mode.

        Here is the structure of the input folder tree:
        <dir_input>
        ├── C
        │   ├── jsons
        │   │   ├── exceptions.json
        │   │   └── mappers.json
        │   ├── static_sources: C files
        │   └── templates: jinja templates
        └── common
            └── jsons
                ├── functions.json
                └── types.json

        Args:
            dir_input (str, optional): Path to the input directory. Defaults to "lib/etc/code".
            dir_output (str, optional): Path to the output directory. Defaults to "src/interface/new_gen".
            mpi_norm (str, optional): Version of the selected MPI standard.
        """

        log.info("Generation of interface C file.")
        self.output_file = "mpi_translation_c.c"
        self.interface_file = "interface_c.c"
        self.mpi_norm = mpi_norm
        self.set_directories(dir_input, dir_output)
        self.interface_file = os.path.join(dir_output, self.interface_file)

    def generate(self):
        """
        Generates mpi_translation_c.c and interface_c.c
        """
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

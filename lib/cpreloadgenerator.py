#!/usr/bin/env python3
"""
This module provides the abstract classe and methods for generating MPI translation code files.

"""

import os
from logging import getLogger
from logging.config import fileConfig
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
        self.output_file = "mpi_translation_c.c"
        self.set_directories(dir_input, dir_output)

    def generate(self):
        self.apply_jinja_dict["asm_dict"]["caller_prefix"] = "P"
        self.apply_jinja_dict["app_dict"]["caller_prefix"] = "P"
        self.apply_jinja_dict["run_dict"]["caller_prefix"] = "P"
        super().generate()

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

    def __init__(self, dir_input="lib/etc/code", dir_output="src/preload/new_gen", mpi_norm=None):
        """
        Initialization of the code generator for preload mode.

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

        log.info("Generation of preload C file.")
        self.output_file = "mpi_translation_c.c"
        self.mpi_norm = mpi_norm
        self.set_directories(dir_input, dir_output)

    def generate(self):
        self.apply_jinja_dict["asm_dict"]["caller_prefix"] = "P"
        self.apply_jinja_dict["app_dict"]["caller_prefix"] = "P"
        self.apply_jinja_dict["run_dict"]["caller_prefix"] = "P"
        # Warning: Do not use 'apply_jinja' before 'super().generate()'.
        #          dico_jinja_env is a prerequisite that is defined in
        #          'generate()' by the call to 'init_jinja()'
        super().generate()

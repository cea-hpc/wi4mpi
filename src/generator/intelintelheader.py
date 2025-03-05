#!/usr/bin/env python3
"""
IntelIntelHeader module for generating Intel-Intel preload header files.
"""

import os
import re
from logging import getLogger
from logging.config import fileConfig
from intelheader import IntelHeaderGenerator
from textoperator import (
    delete_lines,
    replacement_from_conf_file,
)

fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)), "logging.conf"))
log = getLogger("header_logger")


class IntelIntelHeaderGenerator(IntelHeaderGenerator):
    """
    IntelIntelHeader class for generating Intel-Intel preload header files.

    Attributes:
        app (str): Used in copy_files to select file names to copy.
        run (str): Used in copy_files to select file names to copy.

    Methods:
        intel_preload_exception_header_run_mpih: Exception dedicated to Intel run_mpi.h
        _generate_run_mpih: Generates the run_mpi.h file.
        _common_generate_app_mpih: Applies MPICH-specific exceptions for run_mpioh file.
        _generate_app_mpih: Generates the app_mpi.h file.
        _common_generate_app_mpioh: Applies IntelIntel exceptions for app_mpioh file.
        _generate_app_mpioh: Generates the app_mpio.h file.
        _generate_run_mpioh: Generates the run_mpio.h file.
    """

    app = "intelmpi"
    run = "intelmpi"

    def intel_preload_exception_header_run_mpih(self, text):
        """
        Exception dedicated to Intel run_mpi.h

        Args:
            text (str): The content of the file.

        Returns:
            str: The modified content.
        """
        log.debug("Running intel_preload_exception_header_run_mpih (IntelIntelHeaderGenerator).")
        _conf_file = os.path.join(
            self.etc_dir,
            "intelintelheader._preload_exception_header_run_mpih.replace",
        )
        text = replacement_from_conf_file(_conf_file, text)

        text = delete_lines(
            [
                "//extern MPIU_DLL_SPEC int * R_MPI_UNWEIGHTED;",
                "//extern MPIU_DLL_SPEC int * R_MPI_WEIGHTS_EMPTY;",
            ],
            text,
        )
        # Lines modified during generation of interface headers
        _pattern_block = """
int R_MPI_DUP_FN(R_MPI_Comm oldcomm, int keyval, void *extra_state, void *attribute_val_in,
               void *attribute_val_out, int *flag);
"""

        _replacement_block = """
"""
        text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)

        # Lines modified during generation of interface headers
        _pattern_block = """
int R_MPI_DUP_FN(R_MPI_Comm oldcomm, int keyval, void *extra_state, void *attribute_val_in,
               void *attribute_val_out, int *flag) MPICH_API_PUBLIC;
"""

        _replacement_block = """
"""
        text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)
        text = re.sub(r"MPIX_Iov", "R_MPIX_Iov", text)
        text = re.sub(r"([^_])MPIX_", r"\1R_MPIX_", text)
        return text

    def _generate_run_mpih(self, gen_file):
        """
        Generates the run_mpi.h file.

        Args:
            gen_file (str): The path to the generated file.
        """
        log.debug("Running _generate_run_mpih (IntelIntelHeaderGenerator).")
        self.intel_generate_run_mpih(gen_file)
        with open(gen_file, "r", encoding="utf-8") as _file:
            _content = _file.read()

        _new_content = self.intel_preload_exception_header_run_mpih(_content)
        with open(gen_file, "w", encoding="utf-8") as _file:
            _file.write(_new_content)

    def _common_generate_app_mpih(self, text):
        """
        Applies MPICH-specific exceptions for run_mpioh file.

        Args:
            text (str): The content of the file.

        Returns:
            str: The modified content.
        """
        log.debug("Running _common_generate_app_mpih (IntelIntelHeaderGenerator).")
        text = replacement_from_conf_file(
            os.path.join(
                self.etc_dir,
                "intelintelheader._common_generate_app_mpih.replace",
            ),
            text,
        )
        _pattern_block = """
/* Note that we may need to define a @PCONTROL_LIST@ depending on whether
   stdargs are supported */
int A_MPI_Pcontrol(int level, ...);
"""
        _replacement_block = """
/* Note that we may need to define a @PCONTROL_LIST@ depending on whether
   stdargs are supported */
int A_MPI_Pcontrol(int level, ...);
int A_MPI_DUP_FN(A_MPI_Comm oldcomm, int keyval, void *extra_state, void *attribute_val_in,
               void *attribute_val_out, int *flag);
"""
        text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)
        _pattern_block = """
#define A_MPI_MAX_OBJECT_NAME    128
"""
        _replacement_block = """
#define A_MPI_MAX_OBJECT_NAME    128
#define A_MPI_MAX_DATAREP_STRING 128
"""
        text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)
        text = re.sub(r"R_MPI", r"A_MPI", text)

        return text

    def _generate_app_mpih(self, gen_file):
        """
        Generates the app_mpi.h file.

        Args:
            gen_file (str): The path to the generated file.
        """
        log.debug("Running _generate_app_mpih (IntelIntelHeaderGenerator).")
        self._generate_run_mpih(gen_file)
        with open(gen_file, "r", encoding="utf-8") as _file:
            _content = _file.read()

        _new_content = self._common_generate_app_mpih(_content)
        with open(gen_file, "w", encoding="utf-8") as _file:
            _file.write(_new_content)

    def _common_generate_app_mpioh(self, text):
        """
        Applies IntelIntel exceptions for app_mpioh file.

        Args:
            text (str): The content of the file.

        Returns:
            str: The modified content.
        """
        log.debug("Running _common_generate_app_mpioh (IntelIntelHeaderGenerator).")
        text = replacement_from_conf_file(
            os.path.join(
                self.etc_dir,
                "intelintelheader._common_generate_app_mpioh.replace",
            ),
            text,
        )

        # Commented lines to remove
        text = delete_lines(
            [
                "/* Also rename the MPIO routines to get the MPI versions */",
                "#define MPIO_Wait A_MPI_Wait",
                "#define MPIO_Test A_MPI_Test",
                "#define PMPIO_Wait A_PMPI_Wait",
                "#define PMPIO_Test A_PMPI_Test",
            ],
            text,
        )

        return text

    def _generate_app_mpioh(self, gen_file):
        """
        Generates the app_mpio.h file.

        Args:
            gen_file (str): The path to the generated file.
        """
        log.debug("Running _generate_app_mpioh (IntelIntelHeaderGenerator).")
        self._generate_run_mpioh(gen_file)
        with open(gen_file, "r", encoding="utf-8") as _file:
            _content = _file.read()

        _new_content = self._common_generate_app_mpioh(_content)
        with open(gen_file, "w", encoding="utf-8") as _file:
            _file.write(_new_content)

    def _generate_run_mpioh(self, gen_file):
        """
        Generates the run_mpio.h file.

        Args:
            gen_file (str): The path to the generated file.
        """
        log.debug("Running _generate_run_mpioh (IntelIntelGenerator)")
        super()._generate_run_mpioh(gen_file)

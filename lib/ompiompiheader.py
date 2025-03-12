#!/usr/bin/env python3
"""
OmpiOmpiHeader module for generating Ompi-Ompi preload header files.
"""

import os
import re
from logging import getLogger
from logging.config import fileConfig
from ompiheader import OmpiHeaderGenerator
from textoperator import (
    delete_line_from_pattern,
)

fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)), "logging.conf"))
log = getLogger("header_logger")


class OmpiOmpiHeaderGenerator(OmpiHeaderGenerator):
    """
    OmpiOmpiHeader class for generating Ompi-Ompi preload header files.

    Attributes:
        app (str): Used in copy_files to select file names to copy.
        run (str): Used in copy_files to select file names to copy.

    Methods:
        _ompi_ompi_run_exception: Applies exceptions for run_mpi.h file.
        _generate_run_mpih: Generate the run_mpi.h header file.
        _run_to_app: Helper function involved in converting run_mpi.h to app_mpi.h
        ompi_generate_app_mpih: Generate the app_mpi.h header file.
        _generate_app_mpih: Generate the app_mpi.h header file.
    """

    app = "openmpi"
    run = "openmpi"

    def _ompi_ompi_run_exception(self, text):
        """
        Applies exceptions for run_mpi.h file.

        Args:
            text (str): The content of the file.

        Returns:
            str: The modified content.
        """
        pattern = []
        replacement = []
        decalage = 0
        pattern.append(r"//(#define OPAL_MAX_*)")
        replacement.append(r"\1")
        pattern.append(r"\(ccc_##")
        replacement.append("&(")
        pattern.append(r"\(\*ccc_(\w+)\)")
        replacement.append(r"\1")
        pattern.append(r"OMPI_C_R_MPI")
        replacement.append(r"OMPI_C_MPI")
        for _pattern, _replacement in zip(pattern, replacement):
            decalage += len(_replacement.split("\n")) - len(_pattern.split("\n"))
            text = re.sub(_pattern, _replacement, text, flags=re.MULTILINE)
        text = delete_line_from_pattern(r"  OMPI_COMM_TYPE_", text)

        # Lines to delete because they are missing from the reference header
        _pattern_block = """
#ifdef OMPI_PREDEFINED_GLOBAL
#undef OMPI_PREDEFINED_GLOBAL
#endif
"""
        _replacement_block = """
"""
        text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)
        _pattern_block = """
#if OMPI_LOAD_SYM
#define OMPI_PREDEFINED_GLOBAL(type, global) global
#endif
"""
        text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)
        if "5.0.3" == self.mpi_target_version["openmpi"]:
            text = re.sub(
                r"struct ompi_f08_status_public_t {",
                "struct r_ompi_f08_status_public_t {",
                text,
            )
            text = re.sub(
                r"typedef struct ompi_f08_status_public_t ompi_f08_status_public_t;",
                "typedef struct r_ompi_f08_status_public_t R_MPI_F08_status;",
                text,
            )
            text = re.sub(
                r"typedef struct r_ompi_status_public_t r_ompi_status_public_t;",
                "typedef struct r_ompi_status_public_t R_MPI_Status;",
                text,
            )
        text = delete_line_from_pattern("#define R_MPI_Errhandler_get(...)", text)
        text = delete_line_from_pattern("#define R_MPI_Errhandler_set(...)", text)

        return text

    def _generate_run_mpih(self, gen_file: str) -> None:
        """
        Generate the run_mpi.h header file.

        Args:
            gen_file (str): The path to the generated file.
        """
        super()._generate_run_mpih(gen_file)
        with open(gen_file, "r", encoding="utf-8") as _file:
            _content = _file.read()

        _new_content = self._ompi_ompi_run_exception(_content)
        with open(gen_file, "w", encoding="utf-8") as _file:
            _file.write(_new_content)

    def _run_to_app(self, text: str) -> str:
        """
        Helper function involved in converting run_mpi.h to app_mpi.h

        Args:
            text (str): The content of the file.

        Returns:
            str: The modified content.
        """
        pattern = []
        replacement = []
        decalage = 0
        if "5.0.3" == self.mpi_target_version["openmpi"]:
            text = re.sub(
                r"struct ompi_f08_status_public_t {", "struct r_ompi_f08_status_public_t {", text
            )
            text = re.sub(
                r"typedef struct ompi_f08_status_public_t ompi_f08_status_public_t;",
                "typedef struct r_ompi_f08_status_public_t R_MPI_F08_status;",
                text,
            )
            text = re.sub(
                r"typedef struct ompi_status_public_t ompi_status_public_t;",
                "typedef struct r_ompi_status_public_t R_MPI_Status;",
                text,
            )
        pattern.append(r'([ \t(*,)_"])R_')
        replacement.append(r"\1A_")
        pattern.append(r"A_MPIO")
        replacement.append("MPIO")
        pattern.append(r"r_ompi_status")
        replacement.append("a_ompi_status")
        pattern.append(r"r_ompi_f08_status")
        replacement.append("a_ompi_f08_status")
        pattern.append(r"IR_MPI_")
        replacement.append("IA_MPI_")
        for _pattern, _replacement in zip(pattern, replacement):
            decalage += len(_replacement.split("\n")) - len(_pattern.split("\n"))
            log.debug(_pattern + " => " + _replacement)
            text = re.sub(_pattern, _replacement, text, flags=re.MULTILINE)
        return text

    def ompi_generate_app_mpih(self, gen_file: str) -> None:
        """
        Generate the app_mpi.h header file.

        Args:
            gen_file (str): The path to the generated file.
        """
        self._generate_run_mpih(gen_file)
        with open(gen_file, "r", encoding="utf-8") as _file:
            _content = _file.read()

        _new_content = self._run_to_app(_content)
        with open(gen_file, "w", encoding="utf-8") as _file:
            _file.write(_new_content)

    def _generate_app_mpih(self, gen_file: str) -> None:
        """
        Generate the app_mpi.h header file.

        Args:
            gen_file (str): The path to the generated file.
        """
        self.ompi_generate_app_mpih(gen_file)

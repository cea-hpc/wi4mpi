#!/usr/bin/env python3
"""
IntelOmpiHeader module for generating Intel-Ompi preload header files.
"""

import os
import re
from logging import getLogger
from logging.config import fileConfig
from intelheader import IntelHeaderGenerator
from textoperator import (
    delete_lines,
    delete_line_from_pattern,
    replacement_from_conf_file,
)

fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)), "logging.conf"))
log = getLogger("header_logger")


class IntelOmpiHeaderGenerator(IntelHeaderGenerator):
    """
    IntelOmpiHeader class for generating Intel-Ompi preload header files.
    """

    app = "intelmpi"
    run = "openmpi"

    def _common_generate_app_mpih(self, text):
        """
        Applies exceptions for app_mpi.h file.

        Args:
            text (str): The content of the file.

        Returns:
            str: The modified content.
        """
        log.debug("Running _common_generate_app_mpih (IntelOmpiHeaderGenerator).")
        pattern = []
        replacement = []
        decalage = 0

        pattern.append(r"([ ()*_$\t])R_")
        replacement.append(r"\1A_")
        pattern.append(r"//#define A_MPI_DUP_FN         MPIR_Dup_fn")
        replacement.append("#define A_MPI_DUP_FN         MPIR_Dup_fn")
        pattern.append(r'#include "run_mpio.h"')
        replacement.append(r'#include "app_mpio.h"')
        for _pattern, _replacement in zip(pattern, replacement):
            decalage += len(_replacement.split("\n")) - len(_pattern.split("\n"))
            text = re.sub(_pattern, _replacement, text, flags=re.MULTILINE)

        # Lines to be deleted because commented in the reference header
        text = delete_lines(
            [
                "/* Programs that need to convert types used in MPICH should use these */",
                "#define A_MPI_Comm_c2f(comm) (A_MPI_Fint)(comm)",
                "#define A_MPI_Comm_f2c(comm) (A_MPI_Comm)(comm)",
                "#define A_MPI_Type_c2f(datatype) (A_MPI_Fint)(datatype)",
                "#define A_MPI_Type_f2c(datatype) (A_MPI_Datatype)(datatype)",
                "#define A_MPI_Group_c2f(group) (A_MPI_Fint)(group)",
                "#define A_MPI_Group_f2c(group) (A_MPI_Group)(group)",
                "#define A_MPI_Info_c2f(info) (A_MPI_Fint)(info)",
                "#define A_MPI_Info_f2c(info) (A_MPI_Info)(info)",
                "#define A_MPI_Request_f2c(request) (A_MPI_Request)(request)",
                "#define A_MPI_Request_c2f(request) (A_MPI_Fint)(request)",
                "#define A_MPI_Op_c2f(op) (A_MPI_Fint)(op)",
                "#define A_MPI_Op_f2c(op) (A_MPI_Op)(op)",
                "#define A_MPI_Errhandler_c2f(errhandler) (A_MPI_Fint)(errhandler)",
                "#define A_MPI_Errhandler_f2c(errhandler) (A_MPI_Errhandler)(errhandler)",
                "#define A_MPI_Win_c2f(win)   (A_MPI_Fint)(win)",
                "#define A_MPI_Win_f2c(win)   (A_MPI_Win)(win)",
                "#define A_MPI_Message_c2f(msg) ((A_MPI_Fint)(msg))",
                "#define A_MPI_Message_f2c(msg) ((A_MPI_Message)(msg))",
                "//extern MPIU_DLL_SPEC int * A_MPI_UNWEIGHTED;",
                "//extern MPIU_DLL_SPEC int * A_MPI_WEIGHTS_EMPTY;",
            ],
            text,
        )

        # Lines to delete because they are missing from the reference header
        text = delete_lines(
            [
                "int * MPI_UNWEIGHTED;",
                "int * MPI_WEIGHTS_EMPTY;",
                "#define A_MPI_Comm_c2f(comm) (A_MPI_Fint)(comm)",
                "#define A_MPI_Comm_f2c(comm) (A_MPI_Comm)(comm)",
                "#define A_MPI_Type_c2f(datatype) (A_MPI_Fint)(datatype)",
                "#define A_MPI_Type_f2c(datatype) (A_MPI_Datatype)(datatype)",
                "#define A_MPI_Group_c2f(group) (A_MPI_Fint)(group)",
                "#define A_MPI_Group_f2c(group) (A_MPI_Group)(group)",
                "#define A_MPI_Info_c2f(info) (A_MPI_Fint)(info)",
                "#define A_MPI_Info_f2c(info) (A_MPI_Info)(info)",
                "#define A_MPI_Request_f2c(request) (A_MPI_Request)(request)",
                "#define A_MPI_Request_c2f(request) (A_MPI_Fint)(request)",
                "#define A_MPI_Op_c2f(op) (A_MPI_Fint)(op)",
                "#define A_MPI_Op_f2c(op) (A_MPI_Op)(op)",
                "#define A_MPI_Errhandler_c2f(errhandler) (A_MPI_Fint)(errhandler)",
                "#define A_MPI_Errhandler_f2c(errhandler) (A_MPI_Errhandler)(errhandler)",
                "#define A_MPI_Win_c2f(win)   (A_MPI_Fint)(win)",
                "#define A_MPI_Win_f2c(win)   (A_MPI_Win)(win)",
                "#define A_MPI_Message_c2f(msg) ((A_MPI_Fint)(msg))",
                "#define A_MPI_Message_f2c(msg) ((A_MPI_Message)(msg))",
            ],
            text,
        )
        text = re.sub(r"R_MPI", r"A_MPI", text)
        if "4.2.0" == self.mpi_target_version["mpich"] and "Mpich" in self.__class__.__name__:
            text = re.sub(r"#include <run_mpi_proto.h>", r"#include <app_mpi_proto.h>", text)
            text = re.sub(r"([ \t(*,)])MPIX_", r"\1A_MPIX_", text)

        return text

    def _generate_app_mpih(self, gen_file):
        """
        Generates the app_mpi.h file.
        To do this, applies intel_generate_run_mpih and _common_generate_app_mpih.

        Args:
            gen_file (str): The path to the generated file.
        """
        log.debug(
            lambda: f"Running __generate_app_mpih (IntelOmpiHeaderGenerator). File: {gen_file}."
        )
        self.intel_generate_run_mpih(gen_file)
        with open(gen_file, "r", encoding="utf-8") as _file:
            _content = _file.read()

        _new_content = self._common_generate_app_mpih(_content)
        with open(gen_file, "w", encoding="utf-8") as _file:
            _file.write(_new_content)

    def ompi_replace_mpi_with_rmpi(self, text: str) -> str:
        """
        Replace occurrences of MPI with RMPI in the given text.

        Args:
            text (str): The input text where MPI occurrences will be replaced.

        Returns:
            str: The modified text with MPI replaced by RMPI.
        """
        _conf_file = os.path.join(
            self.etc_dir, "intelompiheader.ompi_replace_mpi_with_rmpi.replace"
        )
        text = replacement_from_conf_file(_conf_file, text)

        _pattern = """
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_packed;
"""
        _replacement = """
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_packed;

#define R_MPI_T_ERR_INVALID_NAME      73  /* Name doesn't match */
#define R_MPI_T_ERR_INVALID           74  /* Generic error code for MPI_T added in MPI-3.1 */"""
        text = re.sub(re.escape(_pattern), _replacement, text, flags=re.DOTALL)
        text = delete_line_from_pattern("#define R_MPI_Errhandler_get(...)", text)
        text = delete_line_from_pattern("#define R_MPI_Errhandler_set(...)", text)
        text = re.sub(r"#define OMPI_BUILDING 0", "#define OMPI_BUILDING 1", text)

        return text

    def _generate_run_mpih(self, gen_file: str) -> None:
        """
        Generate a the header file run_mpi.h by replacing MPI_ with R_MPI_ in the input file content and save it in place.

        This method reads the content of the input file, replaces all occurrences of MPI_ with R_MPI_,
        and then saves the modified content to the same file. If the input file does not exist or if there
        is an error during the file I/O operations, appropriate error messages are displayed.

        Args:
            gen_file (str): The path to the generated file.
        """# noqa: E501
        log.debug("Running _generate_run_mpih (HeaderGenerator).")
        try:
            with open(gen_file, "r", encoding="utf-8") as _file:
                _content = _file.read()
                _new_content = self.ompi_replace_mpi_with_rmpi(_content)
            with open(gen_file, "w", encoding="utf-8") as _file:
                _file.write(_new_content)
        except FileNotFoundError:
            log.error(lambda: f"The file '{gen_file}' does not exist.")
        except Exception:
            log.error("An error occurred in _generate_run_mpih.")

    def _common_generate_app_mpioh(self, text):
        """
        Applies exceptions for app_mpio.h file.

        Args:
            text (str): The content of the file.

        Returns:
            str: The modified content.
        """
        log.debug("Running _common_generate_app_mpioh (IntelIntelHeaderGenerator).")
        pattern = []
        replacement = []
        decalage = 0

        pattern.append(r"([ ()*_$\t])R_")
        replacement.append(r"\1A_")
        pattern.append(r"^R_")
        replacement.append(r"A_")

        for _pattern, _replacement in zip(pattern, replacement):
            decalage += len(_replacement.split("\n")) - len(_pattern.split("\n"))
            text = re.sub(_pattern, _replacement, text, flags=re.MULTILINE)

        return text

    def _generate_app_mpioh(self, gen_file):
        """
        Generates the app_mpio.h file.
        To do this, applies IntelHeaderGenerator._generate_run_mpioh and _common_generate_app_mpioh.

        Args:
            gen_file (str): The path to the generated file.
        """
        log.debug(
            lambda: f"Running _generate_app_mpioh (IntelOmpiHeaderGenerator). File: {gen_file}."
        )
        super()._generate_run_mpioh(gen_file)
        with open(gen_file, "r", encoding="utf-8") as _file:
            _content = _file.read()

        _new_content = self._common_generate_app_mpioh(_content)
        with open(gen_file, "w", encoding="utf-8") as _file:
            _file.write(_new_content)

    def _generate_run_mpioh(self, gen_file):
        """
        Override this method to prevent generation of the run_mpio.h file.
        Indeed, there is no run_mpio.h with Open MPI on the runtime side.

        Args:
            gen_file (str): The path to the generated file.
        """
        pass

#!/usr/bin/env python3
"""
IntelOmpiHeader module for generating Intel-Ompi preload header files.
"""

import os
import shutil
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

    def __init__(
        self,
        dir_input="src/preload/header/scripts/intel_ompi_headers",
        dir_output="src/preload/header/_INTEL_OMPI_gen",
        mpi_target_version=None,
    ):
        log.info("Generation of INTEL_OMPI headers in progress.")
        super().__init__(
            dir_input=dir_input, dir_output=dir_output, mpi_target_version=mpi_target_version
        )

    def _common_generate_app_mpih(self, text):
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

        # lignes à supprimer car commentées dans le header de référence
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

        # lignes à supprimer car absente du header de référence
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
        if "4.2.0" == self.mpi_target_version["mpich"]:
            text = re.sub(r"#include <run_mpi_proto.h>", r"#include <app_mpi_proto.h>", text)
            text = re.sub(r"([ \t(*,)])MPIX_", r"\1A_MPIX_", text)

        return text

    def __generate_app_mpih(self, gen_file):
        log.debug(
            lambda: f"Running __generate_app_mpih (IntelOmpiHeaderGenerator). File: {gen_file}."
        )
        self._intel_generate_run_mpih(gen_file)
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

        :param gen_file: A string representing the path to the input file.
        :type gen_file: str
        :return: None
        """  # noqa: E501
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
        log.debug(
            lambda: f"Running _generate_app_mpioh (IntelOmpiHeaderGenerator). File: {gen_file}."
        )
        self._generate_run_mpioh(gen_file)
        with open(gen_file, "r", encoding="utf-8") as _file:
            _content = _file.read()

        _new_content = self._common_generate_app_mpioh(_content)
        with open(gen_file, "w", encoding="utf-8") as _file:
            _file.write(_new_content)

    def _preload_exception_header_app_mpi_protoh(self, text):
        text = re.sub(r"R_MPI", r"A_MPI", text)
        text = re.sub(r"R_QMPI", r"A_QMPI", text)
        text = re.sub(r"R_PMPIX", r"A_PMPIX", text)
        text = re.sub(r"R_PMPI", r"A_PMPI", text)
        text = re.sub(r"([^_])MPIX_", r"\1A_MPIX_", text)
        return text

    def _generate_app_mpi_protoh(self, gen_file):
        super()._generate_run_mpi_protoh(gen_file)
        if "4.2.0" == self.mpi_target_version["mpich"]:
            log.debug("Running _generate_app_mpi_protoh (IntelIntelGenerator)")
            with open(gen_file, "r", encoding="utf-8") as _file:
                _content = _file.read()

            _new_content = self._preload_exception_header_app_mpi_protoh(_content)
            with open(gen_file, "w", encoding="utf-8") as _file:
                _file.write(_new_content)
        else:
            pass

    def generate(self):
        shutil.copy2(
            os.path.join(self.dir_input, f"mpich-{self.mpi_target_version['mpich']}_mpi.h"),
            os.path.join(self.dir_output, self._app_mpi_header_file),
        )
        shutil.copy2(
            os.path.join(self.dir_input, f"mpich-{self.mpi_target_version['mpich']}_mpio.h"),
            os.path.join(self.dir_output, self._app_mpio_header_file),
        )
        shutil.copy2(
            os.path.join(self.dir_input, f"ompi-{self.mpi_target_version['openmpi']}_mpi.h"),
            os.path.join(self.dir_output, self._run_mpi_header_file),
        )
        self._generate_run_mpih(os.path.join(self.dir_output, self._run_mpi_header_file))
        self.__generate_app_mpih(os.path.join(self.dir_output, self._app_mpi_header_file))
        self._generate_app_mpioh(os.path.join(self.dir_output, self._app_mpio_header_file))
        self._generate_wrapper_fh(os.path.join(self.dir_output, self._wrapper_f_header_file))
        if "4.2.0" == self.mpi_target_version["mpich"]:
            shutil.copy2(
                os.path.join(
                    self.dir_input, f"mpich-{self.mpi_target_version['mpich']}_mpi_proto.h"
                ),
                os.path.join(self.dir_output, self._app_mpi_proto_header_file),
            )
        self._generate_app_mpi_protoh(
            os.path.join(self.dir_output, self._app_mpi_proto_header_file)
        )
        log.debug("INTEL_OMPI header has been generated.")

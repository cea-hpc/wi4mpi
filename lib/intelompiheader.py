#!/usr/bin/env python3

import os
import shutil
import re
from logging import getLogger
from logging.config import fileConfig
from intelheader import IntelHeaderGenerator
from textoperator import delete_lines

fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)), "logging.conf"))
log = getLogger("header_logger")


class IntelOmpiHeaderGenerator(IntelHeaderGenerator):
    def __init__(
        self,
        dir_input="src/preload/header/scripts/intel_ompi_headers",
        dir_output="src/preload/header/_INTEL_OMPI_gen",
    ):
        log.info("Generation of INTEL_OMPI headers in progress.")
        super().__init__(dir_input=dir_input, dir_output=dir_output)

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

        return text

    def __generate_app_mpih(self, gen_file):
        log.debug(
            "Running __generate_app_mpih (IntelOmpiHeaderGenerator). File: {}.".format(gen_file)
        )
        self._intel_generate_run_mpih(gen_file)
        with open(gen_file, "r") as _file:
            _content = _file.read()

        _new_content = self._common_generate_app_mpih(_content)
        with open(gen_file, "w") as _file:
            _file.write(_new_content)

    def ompi_replace_mpi_with_rmpi(self, text: str) -> str:
        pattern = []
        replacement = []
        decalage = 0

        pattern.append(r"MPI_")
        replacement.append(r"R_MPI_")
        pattern.append(r"OR_MPI_")
        replacement.append(r"OMPI_")
        pattern.append(r"PR_MPI_")
        replacement.append(r"R_PMPI_")
        pattern.append(r'#    include "mpi_portable_platform.h"')
        replacement.append(r'//#    include "mpi_portable_platform.h"')
        pattern.append(r"MPIO")
        replacement.append(r"R_MPIO")
        pattern.append(r"#define R_MPI_NULL_DELETE_FN OMPI_C_R_MPI_NULL_DELETE_FN")
        replacement.append(r"#define R_MPI_NULL_DELETE_FN OMPI_C_MPI_NULL_DELETE_FN")
        pattern.append(r"#define R_MPI_NULL_COPY_FN OMPI_C_R_MPI_NULL_COPY_FN")
        replacement.append(r"#define R_MPI_NULL_COPY_FN OMPI_C_MPI_NULL_COPY_FN")
        pattern.append(r"const ")
        replacement.append(r"")
        pattern.append(r"#define OPAL_BUILD_PLATFORM_COMPILER_FAMILYID .*")
        replacement.append(r"#define OPAL_BUILD_PLATFORM_COMPILER_FAMILYID 2")
        pattern.append(r"#define OPAL_BUILD_PLATFORM_COMPILER_VERSION .*")
        replacement.append(r"#define OPAL_BUILD_PLATFORM_COMPILER_VERSION 1474738278")
        pattern.append(r"#define OPAL_HAVE_ATTRIBUTE_DEPRECATED_ARGUMENT .*")
        replacement.append(r"#define OPAL_HAVE_ATTRIBUTE_DEPRECATED_ARGUMENT 0")
        pattern.append(r"#define R_MPI_TYPE_NULL_DELETE_FN OMPI_C_R_MPI_TYPE_NULL_DELETE_FN")
        replacement.append(r"#define R_MPI_TYPE_NULL_DELETE_FN OMPI_C_MPI_TYPE_NULL_DELETE_FN")
        pattern.append(r"#define R_MPI_TYPE_NULL_COPY_FN OMPI_C_R_MPI_TYPE_NULL_COPY_FN")
        replacement.append(r"#define R_MPI_TYPE_NULL_COPY_FN OMPI_C_MPI_TYPE_NULL_COPY_FN")
        pattern.append(r"#define R_MPI_TYPE_DUP_FN OMPI_C_R_MPI_TYPE_DUP_FN")
        replacement.append(r"#define R_MPI_TYPE_DUP_FN OMPI_C_MPI_TYPE_DUP_FN")
        pattern.append(r"#define R_MPI_COMM_NULL_DELETE_FN OMPI_C_R_MPI_COMM_NULL_DELETE_FN")
        replacement.append(r"#define R_MPI_COMM_NULL_DELETE_FN OMPI_C_MPI_COMM_NULL_DELETE_FN")
        pattern.append(r"#define R_MPI_COMM_NULL_COPY_FN OMPI_C_R_MPI_COMM_NULL_COPY_FN")
        replacement.append(r"#define R_MPI_COMM_NULL_COPY_FN OMPI_C_MPI_COMM_NULL_COPY_FN")
        pattern.append(r"#define R_MPI_WIN_NULL_DELETE_FN OMPI_C_R_MPI_WIN_NULL_DELETE_FN")
        replacement.append(r"#define R_MPI_WIN_NULL_DELETE_FN OMPI_C_MPI_WIN_NULL_DELETE_FN")
        pattern.append(r"#define R_MPI_WIN_NULL_COPY_FN OMPI_C_R_MPI_WIN_NULL_COPY_FN")
        replacement.append(r"#define R_MPI_WIN_NULL_COPY_FN OMPI_C_MPI_WIN_NULL_COPY_FN")
        pattern.append(r"#define R_MPI_WIN_DUP_FN OMPI_C_R_MPI_WIN_DUP_FN")
        replacement.append(r"#define R_MPI_WIN_DUP_FN OMPI_C_MPI_WIN_DUP_FN")
        pattern.append(r"OMPI_C_R_MPI")
        replacement.append("OMPI_C_MPI")

        for _pattern, _replacement in zip(pattern, replacement):
            decalage += len(_replacement.split("\n")) - len(_pattern.split("\n"))
            log.debug(_pattern + " => " + _replacement)
            text = re.sub(_pattern, _replacement, text, flags=re.MULTILINE)

        _pattern = """
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_packed;
"""
        _replacement = """
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_packed;

#define R_MPI_T_ERR_INVALID_NAME      73  /* Name doesn't match */
#define R_MPI_T_ERR_INVALID           74  /* Generic error code for MPI_T added in MPI-3.1 */"""
        text = re.sub(re.escape(_pattern), _replacement, text, flags=re.DOTALL)
        decalage = len(_replacement.split("\n")) - len(_pattern.split("\n"))

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
            with open(gen_file, "r") as _file:
                _content = _file.read()
                _new_content = self.ompi_replace_mpi_with_rmpi(_content)
            with open(gen_file, "w") as _file:
                _file.write(_new_content)
        except FileNotFoundError:
            log.error(f"The file '{gen_file}' does not exist.")
        except Exception as e:
            log.error(f"An error occurred: {str(e)}")

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
            "Running _generate_app_mpioh (IntelOmpiHeaderGenerator). File: {}.".format(gen_file)
        )
        self._generate_run_mpioh(gen_file)
        with open(gen_file, "r") as _file:
            _content = _file.read()

        _new_content = self._common_generate_app_mpioh(_content)
        with open(gen_file, "w") as _file:
            _file.write(_new_content)

    def generate(self):
        shutil.copy2(
            os.path.join(self.dir_input, "mpich-3.1.2_mpi.h"),
            os.path.join(self.dir_output, self._app_mpi_header_file),
        )
        shutil.copy2(
            os.path.join(self.dir_input, "mpich-3.1.2_mpio.h"),
            os.path.join(self.dir_output, self._app_mpio_header_file),
        )
        shutil.copy2(
            os.path.join(self.dir_input, "ompi-1.8.8_mpi.h"),
            os.path.join(self.dir_output, self._run_mpi_header_file),
        )
        self._generate_run_mpih(os.path.join(self.dir_output, self._run_mpi_header_file))
        self.__generate_app_mpih(os.path.join(self.dir_output, self._app_mpi_header_file))
        self._generate_app_mpioh(os.path.join(self.dir_output, self._app_mpio_header_file))
        self._generate_wrapper_fh(os.path.join(self.dir_output, self._wrapper_f_header_file))
        log.debug("INTEL_OMPI header has been generated.")

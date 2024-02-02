#!/usr/bin/env python3

import os
import shutil
import re
from logging import getLogger
from logging.config import fileConfig
from intelompiheader import IntelOmpiHeaderGenerator
from textoperator import delete_lines, delete_line_from_pattern, function_to_delete

fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)), "logging.conf"))
log = getLogger("header_logger")


class OmpiIntelHeaderGenerator(IntelOmpiHeaderGenerator):
    def __init__(
        self,
        dir_input="src/preload/header/scripts/ompi_intel_headers",
        dir_output="src/preload/header/_OMPI_INTEL_gen",
    ):
        log.info("Generation of OMPI_INTEL headers in progress.")
        self.dir_input = dir_input
        self.dir_output = dir_output
        os.makedirs(self.dir_output, exist_ok=True)

    def _run_to_app(self, text: str) -> str:
        text = delete_line_from_pattern("OMPI_DECLSPEC extern", text)
        pattern = []
        replacement = []
        decalage = 0

        pattern.append(r'([ \t(*,)_"])R_')
        replacement.append(r"\1A_")
        pattern.append(r"#define OMPI_OFFSET_DATATYPE A_MPI_LONG_LONG")
        replacement.append("#define A_OMPI_OFFSET_DATATYPE A_MPI_LONG_LONG")
        pattern.append(r"A_MPIO")
        replacement.append(r"MPIO")
        pattern.append(r"IR_MPI")
        replacement.append("IA_MPI")

        for _pattern, _replacement in zip(pattern, replacement):
            decalage += len(_replacement.split("\n")) - len(_pattern.split("\n"))
            log.debug(_pattern + " => " + _replacement)
            text = re.sub(_pattern, _replacement, text, flags=re.MULTILINE)

        text = function_to_delete(text, "OMPI_DECLSPEC int OMPI_C_MPI_TYPE_NULL_DELETE_FN")
        text = function_to_delete(text, "OMPI_DECLSPEC int OMPI_C_MPI_TYPE_NULL_COPY_FN")
        text = function_to_delete(text, "OMPI_DECLSPEC int OMPI_C_MPI_TYPE_DUP_FN")
        text = function_to_delete(text, "OMPI_DECLSPEC int OMPI_C_MPI_COMM_NULL_DELETE_FN")
        text = function_to_delete(text, "OMPI_DECLSPEC int OMPI_C_MPI_COMM_NULL_COPY_FN")
        text = function_to_delete(text, "OMPI_DECLSPEC int OMPI_C_MPI_COMM_DUP_FN")
        text = function_to_delete(text, "OMPI_DECLSPEC int OMPI_C_MPI_NULL_DELETE_FN")
        text = function_to_delete(text, "OMPI_DECLSPEC int OMPI_C_MPI_NULL_COPY_FN")
        text = function_to_delete(text, "OMPI_DECLSPEC int OMPI_C_MPI_DUP_FN")
        text = function_to_delete(text, "OMPI_DECLSPEC int OMPI_C_MPI_WIN_NULL_DELETE_FN")
        text = function_to_delete(text, "OMPI_DECLSPEC int OMPI_C_MPI_WIN_NULL_COPY_FN")
        text = function_to_delete(text, "OMPI_DECLSPEC int OMPI_C_MPI_WIN_DUP_FN")

        _pattern_block = """#define A_MPI_CONVERSION_FN_NULL ((A_MPI_Datarep_conversion_function*) 0)
#endif"""
        _replacement_block = """#define A_MPI_CONVERSION_FN_NULL ((A_MPI_Datarep_conversion_function*) 0)
#endif

void * OMPI_C_MPI_TYPE_NULL_DELETE_FN;
void * OMPI_C_MPI_TYPE_NULL_COPY_FN;
void * OMPI_C_MPI_TYPE_DUP_FN;
void * OMPI_C_MPI_COMM_NULL_DELETE_FN;
void * OMPI_C_MPI_COMM_NULL_COPY_FN;
void * OMPI_C_MPI_COMM_DUP_FN;
void * OMPI_C_MPI_NULL_DELETE_FN;
void * OMPI_C_MPI_NULL_COPY_FN;
void * OMPI_C_MPI_DUP_FN;
void * OMPI_C_MPI_WIN_NULL_DELETE_FN;
void * OMPI_C_MPI_WIN_NULL_COPY_FN;
void * OMPI_C_MPI_WIN_DUP_FN;
"""
        text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)
        return text

    def _generate_app_mpih(self, gen_file):
        log.debug(
            "Running _generate_app_mpih (OmpiIntelHeaderGenerator). File: {}.".format(gen_file)
        )
        self._generate_run_mpih(gen_file)
        with open(gen_file, "r") as _file:
            _content = _file.read()

        _new_content = self._run_to_app(_content)
        with open(gen_file, "w") as _file:
            _file.write(_new_content)

    def _app_to_run(self, text):
        log.debug("Running _app_to_run (OmpiIntelHeaderGenerator).")
        pattern = []
        replacement = []
        decalage = 0
        pattern.append(r"([ *(),_])A_")
        replacement.append(r"\1R_")
        pattern.append(r"^A_")
        replacement.append(r"R_")
        pattern.append(r" MPIO")
        replacement.append(r" R_MPIO")
        pattern.append(r"//#define R_MPI_DUP_FN         MPIR_Dup_fn")
        replacement.append("#define R_MPI_DUP_FN         MPIR_Dup_fn")
        for _pattern, _replacement in zip(pattern, replacement):
            decalage += len(_replacement.split("\n")) - len(_pattern.split("\n"))
            text = re.sub(_pattern, _replacement, text, flags=re.MULTILINE)

        # lignes à supprimer car absente du header de référence
        text = delete_lines(
            [
                "int * MPI_UNWEIGHTED;",
                "int * MPI_WEIGHTS_EMPTY;",
            ],
            text,
        )
        text = function_to_delete(text, "int R_MPI_DUP_FN")
        return text

    def __generate_run_mpih(self, gen_file):
        log.debug(
            "Running _generate_run_mpih (OmpiIntelHeaderGenerator). File: {}.".format(gen_file)
        )
        self._intel_generate_run_mpih(gen_file)

        with open(gen_file, "r") as _file:
            _content = _file.read()

        _new_content = self._app_to_run(_content)
        with open(gen_file, "w") as _file:
            _file.write(_new_content)

    def __generate_run_mpioh(self, gen_file):
        log.debug(
            "Running _generate_run_mpih (OmpiIntelHeaderGenerator). File: {}.".format(gen_file)
        )
        self._generate_app_mpioh(gen_file)

        with open(gen_file, "r") as _file:
            _content = _file.read()

        _new_content = self._app_to_run(_content)
        with open(gen_file, "w") as _file:
            _file.write(_new_content)

    def generate(self):
        shutil.copy2(
            os.path.join(self.dir_input, "mpich-3.1.2_mpi.h"),
            os.path.join(self.dir_output, self._run_mpi_header_file),
        )

        shutil.copy2(
            os.path.join(self.dir_input, "mpich-3.1.2_mpio.h"),
            os.path.join(self.dir_output, self._run_mpio_header_file),
        )

        shutil.copy2(
            os.path.join(self.dir_input, "ompi-1.8.8_mpi.h"),
            os.path.join(self.dir_output, self._app_mpi_header_file),
        )
        self.__generate_run_mpih(os.path.join(self.dir_output, self._run_mpi_header_file))
        self._generate_app_mpih(os.path.join(self.dir_output, self._app_mpi_header_file))
        self.__generate_run_mpioh(os.path.join(self.dir_output, self._run_mpio_header_file))
        self._generate_wrapper_fh(os.path.join(self.dir_output, self._wrapper_f_header_file))
        log.debug("OMPI_INTEL header has been generated.")

#!/usr/bin/env python3
"""
OmpiIntelHeader module for generating Ompi-Intel preload header files.
"""

import os
import re
import shutil
from logging import getLogger
from logging.config import fileConfig
from intelompiheader import IntelOmpiHeaderGenerator
from textoperator import (
    delete_lines,
    delete_line_from_pattern,
    function_to_delete,
    replacement_from_conf_file,
)

fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)), "logging.conf"))
log = getLogger("header_logger")


class OmpiIntelHeaderGenerator(IntelOmpiHeaderGenerator):
    """
    OmpiIntelHeader class for generating Ompi-Intel preload header files.
    """

    def __init__(
        self,
        dir_input="src/preload/header/scripts/ompi_intel_headers",
        dir_output="src/preload/header/_OMPI_INTEL_gen",
        mpi_target_version={},
    ):
        log.info("Generation of OMPI_INTEL headers in progress.")
        super().__init__(
                dir_input=dir_input,
                dir_output=dir_output,
                mpi_target_version=mpi_target_version
        )

    def _run_to_app(self, text: str) -> str:
        text = delete_line_from_pattern("OMPI_DECLSPEC extern", text)
        _conf_file = os.path.join(self.etc_dir, "ompiintelheader._run_to_app.replace")
        text = replacement_from_conf_file(_conf_file, text)
        list_of_functions_to_delete = [
            "OMPI_DECLSPEC int OMPI_C_MPI_TYPE_NULL_DELETE_FN",
            "OMPI_DECLSPEC int OMPI_C_MPI_TYPE_NULL_COPY_FN",
            "OMPI_DECLSPEC int OMPI_C_MPI_TYPE_DUP_FN",
            "OMPI_DECLSPEC int OMPI_C_MPI_COMM_NULL_DELETE_FN",
            "OMPI_DECLSPEC int OMPI_C_MPI_COMM_NULL_COPY_FN",
            "OMPI_DECLSPEC int OMPI_C_MPI_COMM_DUP_FN",
            "OMPI_DECLSPEC int OMPI_C_MPI_NULL_DELETE_FN",
            "OMPI_DECLSPEC int OMPI_C_MPI_NULL_COPY_FN",
            "OMPI_DECLSPEC int OMPI_C_MPI_DUP_FN",
            "OMPI_DECLSPEC int OMPI_C_MPI_WIN_NULL_DELETE_FN",
            "OMPI_DECLSPEC int OMPI_C_MPI_WIN_NULL_COPY_FN",
            "OMPI_DECLSPEC int OMPI_C_MPI_WIN_DUP_FN",
        ]
        for _function in list_of_functions_to_delete:
            text = function_to_delete(text, _function)

        _pattern_conf_file = os.path.join(
            self.etc_dir, "ompiintelheader._run_to_app.bloc_p0.replace"
        )
        _replacement_conf_file = os.path.join(
            self.etc_dir, "ompiintelheader._run_to_app.bloc_r0.replace"
        )
        text = replacement_from_conf_file(
            _pattern_conf_file, text, replacement_file=_replacement_conf_file
        )
        return text

    def _generate_app_mpih(self, gen_file):
        log.debug(
            lambda: f"Running _generate_app_mpih (OmpiIntelHeaderGenerator). File: {gen_file}."
        )
        self._generate_run_mpih(gen_file)
        with open(gen_file, "r", encoding="utf-8") as _file:
            _content = _file.read()

        _new_content = self._run_to_app(_content)
        with open(gen_file, "w", encoding="utf-8") as _file:
            _file.write(_new_content)

    def _app_to_run(self, text):
        log.debug("Running _app_to_run (OmpiIntelHeaderGenerator).")
        _conf_file = os.path.join(self.etc_dir, "ompiintelheader._app_to_run.replace")
        text = replacement_from_conf_file(_conf_file, text)

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
            lambda: f"Running _generate_run_mpih (OmpiIntelHeaderGenerator). File: {gen_file}."
        )
        self._intel_generate_run_mpih(gen_file)

        with open(gen_file, "r", encoding="utf-8") as _file:
            _content = _file.read()

        _new_content = self._app_to_run(_content)
        with open(gen_file, "w", encoding="utf-8") as _file:
            _file.write(_new_content)

    def __generate_run_mpioh(self, gen_file):
        log.debug(
            lambda: f"Running _generate_run_mpih (OmpiIntelHeaderGenerator). File: {gen_file}."
        )
        self._generate_app_mpioh(gen_file)

        with open(gen_file, "r", encoding="utf-8") as _file:
            _content = _file.read()

        _new_content = self._app_to_run(_content)
        with open(gen_file, "w", encoding="utf-8") as _file:
            _file.write(_new_content)

    def _preload_exception_header_run_mpi_protoh(self, text):
        text = re.sub(r'([^_])MPIX_', r'\1R_MPIX_', text)
        text = function_to_delete(text, "int R_MPI_DUP_FN")
        text = re.sub(r"const ", "", text)
        text = re.sub(r"R_MPIX_Iov", "MPIX_Iov", text)
        text = re.sub(r"R_MPIX_Stream", "MPIX_Stream", text)
        text = re.sub(r"R_MPIX_Grequest_poll_function", "MPIX_Grequest_poll_function", text)
        text = re.sub(r"R_MPIX_Grequest_class", "MPIX_Grequest_class", text)
        text = re.sub(r"R_MPIX_Grequest_wait_function", "MPIX_Grequest_wait_function", text)
        text = re.sub(r"R_MPIX_Grequest_class", "MPIX_Grequest_class", text)
        text = re.sub(r"R_MPIX_Grequest_poll_function", "MPIX_Grequest_poll_function", text)
        text = re.sub(r"R_MPIX_Grequest_wait_function", "MPIX_Grequest_wait_function", text)
        text = re.sub(r"R_MPIX_Grequest_class", "MPIX_Grequest_class", text)
        text = re.sub(r"QMPIX_", "R_QMPIX_", text)
        return text

    def _generate_run_mpi_protoh(self, gen_file):
        super()._generate_run_mpi_protoh(gen_file)
        if "4.2.0" == self.mpi_target_version["mpich"]:
            log.debug("Running _generate_run_mpi_protoh (IntelIntelGenerator)")
            with open(gen_file, "r", encoding="utf-8") as _file:
                _content = _file.read()
            _new_content = self._preload_exception_header_run_mpi_protoh(_content)
            with open(gen_file, "w", encoding="utf-8") as _file:
                _file.write(_new_content)
        else:
            pass

    def generate(self):
        shutil.copy2(
            os.path.join(self.dir_input, f"mpich-{self.mpi_target_version['mpich']}_mpi.h"),
            os.path.join(self.dir_output, self._run_mpi_header_file),
        )

        shutil.copy2(
            os.path.join(self.dir_input, f"mpich-{self.mpi_target_version['mpich']}_mpio.h"),
            os.path.join(self.dir_output, self._run_mpio_header_file),
        )

        shutil.copy2(
            os.path.join(self.dir_input, f"ompi-{self.mpi_target_version['openmpi']}_mpi.h"),
            os.path.join(self.dir_output, self._app_mpi_header_file),
        )
        self.__generate_run_mpih(os.path.join(self.dir_output, self._run_mpi_header_file))
        self._generate_app_mpih(os.path.join(self.dir_output, self._app_mpi_header_file))
        self.__generate_run_mpioh(os.path.join(self.dir_output, self._run_mpio_header_file))
        self._generate_wrapper_fh(os.path.join(self.dir_output, self._wrapper_f_header_file))
        if "4.2.0" == self.mpi_target_version['mpich']:
            shutil.copy2(
                os.path.join(self.dir_input, f"mpich-{self.mpi_target_version['mpich']}_mpi_proto.h"),
                os.path.join(self.dir_output, self._run_mpi_proto_header_file),
            )
        self._generate_run_mpi_protoh(os.path.join(self.dir_output, self._run_mpi_proto_header_file))
        log.debug("OMPI_INTEL header has been generated.")

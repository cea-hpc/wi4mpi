#!/usr/bin/env python3
"""
MpichMpichHeader module for generating Mpich-Mpich preload header files.
"""

import os
import re
from logging import getLogger
from logging.config import fileConfig
from mpichheader import MpichHeaderGenerator
from intelintelheader import IntelIntelHeaderGenerator
from textoperator import (
    delete_line_from_pattern,
    function_to_delete,
    replacement_from_conf_file,
)

fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)), "logging.conf"))
log = getLogger("header_logger")


class MpichMpichHeaderGenerator(IntelIntelHeaderGenerator, MpichHeaderGenerator):
    """
    MpichMpichHeaderGenerator class for generating Mpich-Mpich preload header files.
    """

    app = "mpich"
    run = "mpich"

    def _generate_run_mpih(self, gen_file):
        log.debug("Running _generate_run_mpih (MpichMpichHeaderGenerator).")
        self.intel_generate_run_mpih(gen_file)
        with open(gen_file, "r", encoding="utf-8") as _file:
            _content = _file.read()

        _content = self.mpich_copyright(_content)
        _new_content = self.intel_preload_exception_header_run_mpih(_content)
        with open(gen_file, "w", encoding="utf-8") as _file:
            _file.write(_new_content)

    def _common_generate_app_mpih(self, text):
        log.debug("Running _common_generate_app_mpih (MpichMpichHeaderGenerator).")
        text = super()._common_generate_app_mpih(text)
        # MPICH 4.2.0
        if "4.2.0" == self.mpi_target_version["mpich"]:
            text = re.sub(r"([ \t(*,)])MPIX_", r"\1A_MPIX_", text)
            text = re.sub(r"#include <run_mpi_proto.h>", r"#include <app_mpi_proto.h>", text)

        return text

    def _generate_app_mpioh(self, gen_file):
        log.debug(
            lambda: f"Running _generate_app_mpioh (MpichMpichHeaderGenerator). File: {gen_file}."
        )
        super()._generate_run_mpioh(gen_file)
        with open(gen_file, "r", encoding="utf-8") as _file:
            _content = _file.read()

        _new_content = self._common_generate_app_mpioh(_content)
        with open(gen_file, "w", encoding="utf-8") as _file:
            _file.write(_new_content)

    def __aux_generate_run_mpioh(self, text):
        log.debug("Running __aux_generate_run_mpioh (MpichMpichHeaderGenerator).")
        text = delete_line_from_pattern(
            "/* Also rename the MPIO routines to get the MPI versions */", text
        )
        text = delete_line_from_pattern("#define MPIO_Wait R_MPI_Wait", text)
        text = delete_line_from_pattern("#define MPIO_Test R_MPI_Test", text)
        text = delete_line_from_pattern("#define PMPIO_Wait R_PMPI_Wait", text)
        text = delete_line_from_pattern("#define PMPIO_Test R_PMPI_Test", text)
        text = replacement_from_conf_file(
            os.path.join(
                self.etc_dir,
                "intelintelheader.__aux_generate_run_mpioh.replace",
            ),
            text,
        )

        return text

    def _generate_run_mpioh(self, gen_file):
        log.debug(
            lambda: f"Running __generate_run_mpioh (MpichMpichHeaderGenerator). File: {gen_file}."
        )
        super()._generate_run_mpioh(gen_file)
        with open(gen_file, "r", encoding="utf-8") as _file:
            _content = _file.read()

        _new_content = self.__aux_generate_run_mpioh(_content)
        with open(gen_file, "w", encoding="utf-8") as _file:
            _file.write(_new_content)

    def _preload_exception_header_app_mpi_protoh(self, text):
        text = re.sub(r"R_MPI", r"A_MPI", text)
        text = re.sub(r"R_QMPI", r"A_QMPI", text)
        text = re.sub(r"R_PMPIX", r"A_PMPIX", text)
        text = re.sub(r"R_PMPI", r"A_PMPI", text)
        text = re.sub(r"([^_])MPIX_", r"\1A_MPIX_", text)
        text = function_to_delete(text, "int A_MPI_DUP_FN")
        return text

    def _generate_app_mpi_protoh(self, gen_file):
        if "4.2.0" == self.mpi_target_version["mpich"]:
            log.debug("Running _generate_app_mpi_protoh (IntelIntelGenerator)")
            with open(gen_file, "r", encoding="utf-8") as _file:
                _content = _file.read()
            _content = self._replace_mpi_with_rmpi(_content)
            _content = self._mpich_exception_run_mpi_protoh(_content)
            _new_content = self._preload_exception_header_app_mpi_protoh(_content)
            with open(gen_file, "w", encoding="utf-8") as _file:
                _file.write(_new_content)
        else:
            pass

    def _preload_exception_header_run_mpi_protoh(self, text):
        text = re.sub(r"A_MPI", r"R_MPI", text)
        text = re.sub(r"A_QMPI", r"R_QMPI", text)
        text = re.sub(r"A_PMPI", r"R_PMPI", text)
        text = function_to_delete(text, "int R_MPI_DUP_FN")
        return text

    def _generate_run_mpi_protoh(self, gen_file):
        if "4.2.0" == self.mpi_target_version["mpich"]:
            log.debug("Running _generate_run_mpi_protoh (MpichMpichGenerator)")
            with open(gen_file, "r", encoding="utf-8") as _file:
                _content = _file.read()

            _content = self._replace_mpi_with_rmpi(_content)
            _content = self._mpich_exception_run_mpi_protoh(_content)
            _new_content = self._preload_exception_header_app_mpi_protoh(_content)
            _new_content = self._preload_exception_header_run_mpi_protoh(_new_content)
            with open(gen_file, "w", encoding="utf-8") as _file:
                _file.write(_new_content)
        else:
            pass

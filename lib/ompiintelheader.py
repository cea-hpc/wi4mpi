#!/usr/bin/env python3
"""
OmpiIntelHeader module for generating Ompi-Intel preload header files.
"""

import os
from logging import getLogger
from logging.config import fileConfig
from intelintelheader import IntelIntelHeaderGenerator
from ompiheader import OmpiHeaderGenerator
from textoperator import (
    delete_lines,
    delete_line_from_pattern,
    function_to_delete,
    replacement_from_conf_file,
)

fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)), "logging.conf"))
log = getLogger("header_logger")


class OmpiIntelHeaderGenerator(IntelIntelHeaderGenerator, OmpiHeaderGenerator):
    """
    OmpiIntelHeader class for generating Ompi-Intel preload header files.
    """

    app = "openmpi"
    run = "intelmpi"

    def _run_to_app(self, text: str) -> str:
        log.debug("Running _run_to_app (OmpiIntelGenerator)")
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
        return text

    def _generate_app_mpih(self, gen_file):
        """
        Ompi app_mpi.h
        """
        log.debug("Running _generate_app_mpih (OmpiIntelHeaderGenerator)")
        with open(gen_file, "r", encoding="utf-8") as _file:
            _content = _file.read()
            _new_content = self.ompi_replace_mpi_with_rmpi(_content)
            _new_content = self._run_to_app(_new_content)
        with open(gen_file, "w", encoding="utf-8") as _file:
            _file.write(_new_content)

    def _generate_run_mpioh(self, gen_file):
        log.debug("Running _generate_run_mpioh (OmpiIntelGenerator)")
        super()._generate_run_mpioh(gen_file)

    def _generate_app_mpioh(self, _):
        log.debug("Running _generate_app_mpioh (OmpiIntelGenerator)")

    def _generate_app_mpi_protoh(self, _):
        log.debug("Running _generate_app_mpi_protoh (OmpiIntelGenerator)")

    def _generate_run_mpi_protoh(self, _):
        log.debug("Running _generate_run_mpi_protoh (OmpiIntelGenerator)")

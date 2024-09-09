#!/usr/bin/env python3
"""
IntelIntelHeader module for generating Intel-Intel preload header files.
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
    function_to_delete,
    replacement_from_conf_file,
)

fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)), "logging.conf"))
log = getLogger("header_logger")


class IntelIntelHeaderGenerator(IntelHeaderGenerator):
    """
    IntelIntelHeader class for generating Intel-Intel preload header files.
    """

    def __init__(
        self,
        dir_input="src/preload/header/scripts/intel_intel_headers",
        dir_output="src/preload/header/_INTEL_INTEL_gen",
        mpi_target_version=None,
    ):
        log.info("Generation of INTEL_INTEL headers in progress.")
        super().__init__(
            dir_input=dir_input, dir_output=dir_output, mpi_target_version=mpi_target_version
        )

    def _preload_exception_header_run_mpih(self, text):
        log.debug("Running _preload_exception_header_run_mpih (IntelIntelHeaderGenerator).")
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
        # Lignes modifiées durant la génération des header de l'interface
        _pattern_block = """
/* Note that we may need to define a @PCONTROL_LIST@ depending on whether
   stdargs are supported */
int R_MPI_Pcontrol(int level, ...);
int R_MPI_DUP_FN(R_MPI_Comm oldcomm, int keyval, void *extra_state, void *attribute_val_in,
               void *attribute_val_out, int *flag);
"""
        _replacement_block = """
/* Note that we may need to define a @PCONTROL_LIST@ depending on whether
   stdargs are supported */
int R_MPI_Pcontrol(int level, ...);
"""
        text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)
        text = re.sub(r"MPIX_Iov", "R_MPIX_Iov", text)
        text = re.sub(r"([^_])MPIX_", r"\1R_MPIX_", text)

        return text

    def _generate_run_mpih(self, gen_file):
        log.debug("Running _generate_run_mpih (IntelIntelHeaderGenerator).")
        super()._generate_run_mpih(gen_file)
        with open(gen_file, "r", encoding="utf-8") as _file:
            _content = _file.read()

        _new_content = self._preload_exception_header_run_mpih(_content)
        with open(gen_file, "w", encoding="utf-8") as _file:
            _file.write(_new_content)

    def _common_generate_app_mpih(self, text):
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
        # MPICH 4.2.0
        if "4.2.0" == self.mpi_target_version["mpich"]:
            text = re.sub(r"#include <run_mpi_proto.h>", r"#include <app_mpi_proto.h>", text)
            text = re.sub(r"([ \t(*,)])MPIX_", r"\1A_MPIX_", text)

        return text

    def _generate_app_mpih(self, gen_file):
        log.debug(
            lambda: f"Running _generate_app_mpih (IntelIntelHeaderGenerator). File: {gen_file}."
        )
        self._generate_run_mpih(gen_file)
        with open(gen_file, "r", encoding="utf-8") as _file:
            _content = _file.read()

        _new_content = self._common_generate_app_mpih(_content)
        with open(gen_file, "w", encoding="utf-8") as _file:
            _file.write(_new_content)

    def _common_generate_app_mpioh(self, text):
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
        log.debug(
            lambda: f"Running _generate_app_mpioh (IntelIntelHeaderGenerator). File: {gen_file}."
        )
        self._generate_run_mpioh(gen_file)
        with open(gen_file, "r", encoding="utf-8") as _file:
            _content = _file.read()

        _new_content = self._common_generate_app_mpioh(_content)
        with open(gen_file, "w", encoding="utf-8") as _file:
            _file.write(_new_content)

    def __aux_generate_run_mpioh(self, text):
        log.debug("Running __aux_generate_run_mpioh (IntelIntelHeaderGenerator).")
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

    def __generate_run_mpioh(self, gen_file):
        log.debug(
            lambda: f"Running __generate_run_mpioh (IntelIntelHeaderGenerator). File: {gen_file}."
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

    def _preload_exception_header_run_mpi_protoh(self, text):
        text = re.sub(r"A_MPI", r"R_MPI", text)
        text = re.sub(r"A_QMPI", r"R_QMPI", text)
        text = re.sub(r"A_PMPI", r"R_PMPI", text)
        text = function_to_delete(text, "int R_MPI_DUP_FN")
        return text

    def _generate_run_mpi_protoh(self, gen_file):
        self._generate_app_mpi_protoh(gen_file)
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
        log.debug("Running generate (IntelIntelHeaderGenerator).")
        shutil.copy2(
            os.path.join(self.dir_input, f"mpich-{self.mpi_target_version['mpich']}_mpi.h"),
            os.path.join(self.dir_output, self._run_mpi_header_file),
        )
        shutil.copy2(
            os.path.join(self.dir_input, f"mpich-{self.mpi_target_version['mpich']}_mpi.h"),
            os.path.join(self.dir_output, self._app_mpi_header_file),
        )
        shutil.copy2(
            os.path.join(self.dir_input, f"mpich-{self.mpi_target_version['mpich']}_mpio.h"),
            os.path.join(self.dir_output, self._run_mpio_header_file),
        )
        shutil.copy2(
            os.path.join(self.dir_input, f"mpich-{self.mpi_target_version['mpich']}_mpio.h"),
            os.path.join(self.dir_output, self._app_mpio_header_file),
        )
        if "4.2.0" == self.mpi_target_version["mpich"]:
            shutil.copy2(
                os.path.join(
                    self.dir_input, f"mpich-{self.mpi_target_version['mpich']}_mpi_proto.h"
                ),
                os.path.join(self.dir_output, self._run_mpi_proto_header_file),
            )
            shutil.copy2(
                os.path.join(
                    self.dir_input, f"mpich-{self.mpi_target_version['mpich']}_mpi_proto.h"
                ),
                os.path.join(self.dir_output, self._app_mpi_proto_header_file),
            )
        self._generate_run_mpih(os.path.join(self.dir_output, self._run_mpi_header_file))
        self.__generate_run_mpioh(os.path.join(self.dir_output, self._run_mpio_header_file))
        self._generate_app_mpih(os.path.join(self.dir_output, self._app_mpi_header_file))
        self._generate_app_mpioh(os.path.join(self.dir_output, self._app_mpio_header_file))
        self._generate_wrapper_fh(os.path.join(self.dir_output, self._wrapper_f_header_file))
        self._generate_run_mpi_protoh(
            os.path.join(self.dir_output, self._run_mpi_proto_header_file)
        )
        self._generate_app_mpi_protoh(
            os.path.join(self.dir_output, self._app_mpi_proto_header_file)
        )
        log.debug("INTEL_INTEL header has been generated.")

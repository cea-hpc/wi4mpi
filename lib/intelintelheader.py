#!/usr/bin/env python3

import os
import shutil
import re
from logging import getLogger
from logging.config import fileConfig
from intelheader import IntelHeaderGenerator
from textoperator import delete_lines, delete_line_from_pattern

fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)), "logging.conf"))
log = getLogger("header_logger")


class IntelIntelHeaderGenerator(IntelHeaderGenerator):
    def __init__(
        self,
        dir_input="src/preload/header/scripts/intel_intel_headers",
        dir_output="src/preload/header/_INTEL_INTEL_gen",
    ):
        log.info("Generation of INTEL_INTEL headers in progress.")
        self.dir_input = dir_input
        self.dir_output = dir_output
        os.makedirs(self.dir_output, exist_ok=True)

    def _preload_exception_header_run_mpih(self, text):
        log.debug("Running _preload_exception_header_run_mpih (IntelIntelHeaderGenerator).")
        pattern = []
        replacement = []
        decalage = 0
        pattern.append(r"MPIR_Win_flavor")
        replacement.append(r"R_MPIR_Win_flavor")
        pattern.append(r"MPIR_Win_model")
        replacement.append(r"R_MPIR_Win_model")
        pattern.append(r"MPIR_Topo_type")
        replacement.append(r"R_MPIR_Topo_type")
        pattern.append(r"MPIR_ERRORS_THROW_EXCEPTIONS")
        replacement.append(r"R_MPIR_ERRORS_THROW_EXCEPTIONS")
        pattern.append(r"MPIR_Combiner_enum")
        replacement.append(r"R_MPIR_Combiner_enum")
        pattern.append(r"MPIR_T_verbosity_t")
        replacement.append(r"R_MPIR_T_verbosity_t")
        pattern.append(r"MPIX_T_VERBOSITY_INVALID")
        replacement.append(r"R_MPIX_T_VERBOSITY_INVALID")
        pattern.append(r"MPIR_T_bind_t")
        replacement.append(r"R_MPIR_T_bind_t")
        pattern.append(r"MPIR_T_scope_t")
        replacement.append(r"R_MPIR_T_scope_t")
        pattern.append(r"MPIX_T_SCOPE_INVALID")
        replacement.append(r"R_MPIX_T_SCOPE_INVALID")
        pattern.append(r"MPIR_T_pvar_class_t")
        replacement.append(r"R_MPIR_T_pvar_class_t")
        pattern.append(r"MPIX_T_PVAR_CLASS_INVALID")
        replacement.append(r"R_MPIX_T_PVAR_CLASS_INVALID")
        pattern.append(r"MPIR_T_PVAR_CLASS_FIRST")
        replacement.append(r"R_MPIR_T_PVAR_CLASS_FIRST")
        pattern.append(r"MPIR_T_PVAR_CLASS_LAST")
        replacement.append(r"R_MPIR_T_PVAR_CLASS_LAST")
        pattern.append(r"MPIR_T_PVAR_CLASS_NUMBER")
        replacement.append(r"R_MPIR_T_PVAR_CLASS_NUMBER")
        pattern.append(r"MPIX_Grequest_poll_function")
        replacement.append(r"R_MPIX_Grequest_poll_function")
        pattern.append(r"MPIX_Grequest_wait_function")
        replacement.append(r"R_MPIX_Grequest_wait_function")
        pattern.append(r" MPIX_Grequest_class_create")
        # L'espace est nécessaire pour ne pas modifier PMPIX_Grequest_.*
        replacement.append(r" R_MPIX_Grequest_class_create")
        pattern.append(r" MPIX_Grequest_class_allocate")
        replacement.append(r" R_MPIX_Grequest_class_allocate")
        pattern.append(r" MPIX_Grequest_start")
        replacement.append(r" R_MPIX_Grequest_start")
        #
        pattern.append(r"PMPIX_Grequest_class_create")
        replacement.append(r"R_PMPIX_Grequest_class_create")
        pattern.append(r"PMPIX_Grequest_class_allocate")
        replacement.append(r"R_PMPIX_Grequest_class_allocate")
        pattern.append(r"PMPIX_Grequest_start")
        replacement.append(r"R_PMPIX_Grequest_start")
        pattern.append(r"PMPIX_Mutex_create")
        replacement.append(r"R_PMPIX_Mutex_create")
        pattern.append(r"PMPIX_Mutex_free")
        replacement.append(r"R_PMPIX_Mutex_free")
        pattern.append(r"PMPIX_Mutex_lock")
        replacement.append(r"R_PMPIX_Mutex_lock")
        pattern.append(r"PMPIX_Mutex_unlock")
        replacement.append(r"R_PMPIX_Mutex_unlock")
        # Ligne modifiée durant la génération des header de l'interface
        pattern.append(r"//(#define R_MPI_DUP_FN.*)")
        replacement.append(r"\1")
        for _pattern, _replacement in zip(pattern, replacement):
            decalage += len(_replacement.split("\n")) - len(_pattern.split("\n"))
            text = re.sub(_pattern, _replacement, text, flags=re.MULTILINE)
        # Lignes modifiées durant la génération des header de l'interface
        _pattern_block = """
/* See 4.12.5 for R_MPI_F_STATUS(ES)_IGNORE */
#define MPIU_DLL_SPEC
extern MPIU_DLL_SPEC R_MPI_Fint * R_MPI_F_STATUS_IGNORE;
extern MPIU_DLL_SPEC R_MPI_Fint * R_MPI_F_STATUSES_IGNORE;
"""
        _replacement_block = """
/* See 4.12.5 for R_MPI_F_STATUS(ES)_IGNORE */
#define MPIU_DLL_SPEC
extern MPIU_DLL_SPEC R_MPI_Fint * R_MPI_F_STATUS_IGNORE;
extern MPIU_DLL_SPEC R_MPI_Fint * R_MPI_F_STATUSES_IGNORE;
int * R_MPI_UNWEIGHTED;
int * R_MPI_WEIGHTS_EMPTY;

"""
        text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)
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

        return text

    def _generate_run_mpih(self, gen_file):
        log.debug("Running _generate_run_mpih (IntelIntelHeaderGenerator).")
        super()._generate_run_mpih(gen_file)
        with open(gen_file, "r") as _file:
            _content = _file.read()

        _new_content = self._preload_exception_header_run_mpih(_content)
        with open(gen_file, "w") as _file:
            _file.write(_new_content)

    def _common_generate_app_mpih(self, text):
        log.debug("Running _common_generate_app_mpih (IntelIntelHeaderGenerator).")
        pattern = []
        replacement = []
        decalage = 0

        pattern.append(r"([ ()*_$\t])R_")
        replacement.append(r"\1A_")
        pattern.append(r"MPIX_T_BIND_INVALID")
        replacement.append(r"A_MPIX_T_BIND_INVALID")
        pattern.append(r"A_MPIX_Grequest_")
        replacement.append(r"MPIX_Grequest_")
        pattern.append(r"mpich_")
        replacement.append(r"a_mpich_")
        pattern.append(r"\( void")
        replacement.append(r"(void")
        pattern.append(r"A_PMPIX_")
        replacement.append(r"PMPIX_")
        pattern.append(r'#include "run_mpio.h"')
        replacement.append(r'#include "app_mpio.h"')

        for _pattern, _replacement in zip(pattern, replacement):
            decalage += len(_replacement.split("\n")) - len(_pattern.split("\n"))
            text = re.sub(_pattern, _replacement, text, flags=re.MULTILINE)
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

        return text

    def _generate_app_mpih(self, gen_file):
        log.debug(
            "Running _generate_app_mpih (IntelIntelHeaderGenerator). File: {}.".format(gen_file)
        )
        self._generate_run_mpih(gen_file)
        with open(gen_file, "r") as _file:
            _content = _file.read()

        _new_content = self._common_generate_app_mpih(_content)
        with open(gen_file, "w") as _file:
            _file.write(_new_content)

    def _common_generate_app_mpioh(self, text):
        log.debug("Running _common_generate_app_mpioh (IntelIntelHeaderGenerator).")
        pattern = []
        replacement = []
        decalage = 0

        pattern.append(r"([ ()*_$\t])R_")
        replacement.append(r"\1A_")
        pattern.append(r"MPIO_INCLUDE")
        replacement.append(r"A_MPIO_INCLUDE")
        pattern.append(r"^R_")
        replacement.append(r"A_")
        pattern.append(r'#include "run_mpi.h"')
        replacement.append(r'#include "app_mpi.h"')

        for _pattern, _replacement in zip(pattern, replacement):
            decalage += len(_replacement.split("\n")) - len(_pattern.split("\n"))
            text = re.sub(_pattern, _replacement, text, flags=re.MULTILINE)

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
            "Running _generate_app_mpioh (IntelIntelHeaderGenerator). File: {}.".format(gen_file)
        )
        self._generate_run_mpioh(gen_file)
        with open(gen_file, "r") as _file:
            _content = _file.read()

        _new_content = self._common_generate_app_mpioh(_content)
        with open(gen_file, "w") as _file:
            _file.write(_new_content)

    def __aux_generate_run_mpioh(self, text):
        log.debug("Running __aux_generate_run_mpioh (IntelIntelHeaderGenerator).")
        pattern = []
        replacement = []
        decalage = 0
        # Commented lines to remove
        text = delete_line_from_pattern(
            "/* Also rename the MPIO routines to get the MPI versions */", text
        )
        text = delete_line_from_pattern("#define MPIO_Wait R_MPI_Wait", text)
        text = delete_line_from_pattern("#define MPIO_Test R_MPI_Test", text)
        text = delete_line_from_pattern("#define PMPIO_Wait R_PMPI_Wait", text)
        text = delete_line_from_pattern("#define PMPIO_Test R_PMPI_Test", text)

        pattern.append(r" MPIO_")
        replacement.append(r" R_MPIO_")

        for _pattern, _replacement in zip(pattern, replacement):
            decalage += len(_replacement.split("\n")) - len(_pattern.split("\n"))
            text = re.sub(_pattern, _replacement, text, flags=re.MULTILINE)

        return text

    def __generate_run_mpioh(self, gen_file):
        log.debug(
            "Running __generate_run_mpioh (IntelIntelHeaderGenerator). File: {}.".format(gen_file)
        )
        super()._generate_run_mpioh(gen_file)
        with open(gen_file, "r") as _file:
            _content = _file.read()

        _new_content = self.__aux_generate_run_mpioh(_content)
        with open(gen_file, "w") as _file:
            _file.write(_new_content)

    def generate(self):
        log.debug("Running generate (IntelIntelHeaderGenerator).")
        shutil.copy2(
            os.path.join(self.dir_input, "mpich-3.1.2_mpi.h"),
            os.path.join(self.dir_output, self._run_mpi_header_file),
        )
        shutil.copy2(
            os.path.join(self.dir_input, "mpich-3.1.2_mpi.h"),
            os.path.join(self.dir_output, self._app_mpi_header_file),
        )
        shutil.copy2(
            os.path.join(self.dir_input, "mpich-3.1.2_mpio.h"),
            os.path.join(self.dir_output, self._run_mpio_header_file),
        )
        shutil.copy2(
            os.path.join(self.dir_input, "mpich-3.1.2_mpio.h"),
            os.path.join(self.dir_output, self._app_mpio_header_file),
        )
        self._generate_run_mpih(os.path.join(self.dir_output, self._run_mpi_header_file))
        self.__generate_run_mpioh(os.path.join(self.dir_output, self._run_mpio_header_file))
        self._generate_app_mpih(os.path.join(self.dir_output, self._app_mpi_header_file))
        self._generate_app_mpioh(os.path.join(self.dir_output, self._app_mpio_header_file))
        self._generate_wrapper_fh(os.path.join(self.dir_output, self._wrapper_f_header_file))
        log.debug("INTEL_INTEL header has been generated.")

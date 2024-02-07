#!/usr/bin/env python3
"""
OmpiOmpiHeader module for generating Ompi-Ompi preload header files.
"""

import os
import shutil
import re
from logging import getLogger
from logging.config import fileConfig
from ompiheader import OmpiHeaderGenerator

fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)), "logging.conf"))
log = getLogger("header_logger")


class OmpiOmpiHeaderGenerator(OmpiHeaderGenerator):
    """
    OmpiOmpiHeader class for generating Ompi-Ompi preload header files.
    """

    def __init__(
        self,
        dir_input="src/preload/header/scripts/ompi_ompi_headers",
        dir_output="src/preload/header/_OMPI_OMPI_gen",
    ):
        log.info("Generation of OMPI_OMPI headers in progress.")
        super().__init__(dir_input=dir_input, dir_output=dir_output)

    def _ompi_ompi_run_exception(self, text):
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

        # lignes à supprimer car absente du header de référence
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

        return text

    def _generate_run_mpih(self, gen_file: str) -> None:
        super()._generate_run_mpih(gen_file)
        with open(gen_file, "r", encoding="utf-8") as _file:
            _content = _file.read()

        _new_content = self._ompi_ompi_run_exception(_content)
        with open(gen_file, "w", encoding="utf-8") as _file:
            _file.write(_new_content)

    def _run_to_app(self, text: str) -> str:
        pattern = []
        replacement = []
        decalage = 0

        pattern.append(r'([ \t(*,)_"])R_')
        replacement.append(r"\1A_")
        pattern.append(r"A_MPIO")
        replacement.append("MPIO")
        pattern.append(r"r_ompi_status")
        replacement.append("a_ompi_status")
        pattern.append(r"IR_MPI_")
        replacement.append("IA_MPI_")
        for _pattern, _replacement in zip(pattern, replacement):
            decalage += len(_replacement.split("\n")) - len(_pattern.split("\n"))
            log.debug(_pattern + " => " + _replacement)
            text = re.sub(_pattern, _replacement, text, flags=re.MULTILINE)
        return text

    def _generate_app_mpih(self, gen_file: str) -> None:
        self._generate_run_mpih(gen_file)
        with open(gen_file, "r", encoding="utf-8") as _file:
            _content = _file.read()

        _new_content = self._run_to_app(_content)
        with open(gen_file, "w", encoding="utf-8") as _file:
            _file.write(_new_content)

    def generate(self):
        shutil.copy2(
            os.path.join(self.dir_input, "ompi-1.8.8_mpi.h"),
            os.path.join(self.dir_output, self._run_mpi_header_file),
        )
        shutil.copy2(
            os.path.join(self.dir_input, "ompi-1.8.8_mpi.h"),
            os.path.join(self.dir_output, self._app_mpi_header_file),
        )
        super().generate()
        log.debug("OMPI header has been generated.")

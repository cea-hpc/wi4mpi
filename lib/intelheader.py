#!/usr/bin/env python3
"""
IntelHeader module for generating Intel-specific header files.
"""

import os
import shutil
import re
from logging import getLogger
from logging.config import fileConfig
from header import HeaderGenerator
from textoperator import (
    delete_lines,
    delete_line_from_pattern,
    replacement_from_conf_file,
)

fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)), "logging.conf"))
log = getLogger("header_logger")


class IntelHeaderGenerator(HeaderGenerator):
    """
    IntelHeaderGenerator class for generating Intel-specific header files.
    """

    app = None
    run = "intelmpi"

    def _generate_wrapper_fh(self, gen_file):
        """
        Generates the wrapper_f.h file.

        Args:
            gen_file (str): The path to the generated file.
        """
        log.debug("Running _generate_wrapper_fh (IntelHeaderGenerator).")

        def _msg(wrapper_f):
            return f"Using {wrapper_f}"

        if not os.path.exists(gen_file):
            wrapper_f = os.path.join(self.dir_input, "wrapper_f.h")
            log.warning(_msg(wrapper_f))
            shutil.copy2(os.path.join(self.dir_input, "wrapper_f.h"), gen_file)

    def intel_exceptions_run_mpih(self, text):
        """
        Applies MPICH-specific exceptions for run_mpih file.

        Args:
            text (str): The content of the file.

        Returns:
            str: The modified content.
        """
        log.debug("Running intel_exceptions_run_mpih (IntelHeaderGenerator).")
        text = re.sub(r"const ", "", text, flags=re.MULTILINE)

        _pattern_block = """
/* user include file for MPI programs */
"""
        _replacement_block = """
/* user include file for MPI programs */
#if !defined(_WIN32) && !defined(_WIN64)  /* Linux only */
#    include <stdint.h> /* for __WORDSIZE definition */
#   ifdef __WORDSIZE
#        if __WORDSIZE != 8*8 /* 32 or 64 */
#            error A wrong version of mpi.h file was included. Check include path.
#        endif
#    endif
#endif
"""
        text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)

        _pattern_block = """
#ifdef MPICH_DEFINE_2COMPLEX
"""
        _replacement_block = """
#define MPICH_DEFINE_2COMPLEX
#ifdef MPICH_DEFINE_2COMPLEX
"""
        text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)

        _pattern_block = """
/* Pre-defined constants */
#define R_MPI_UNDEFINED      (-32766)
#define R_MPI_KEYVAL_INVALID 0x24000000
"""
        _replacement_block = """
/* Pre-defined constants */
#define R_MPI_UNDEFINED      (-32766)
#define R_MPI_UNDEFINED_RANK R_MPI_UNDEFINED
#define R_MPI_KEYVAL_INVALID 0x24000000
"""
        text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)

        text = re.sub(
            r"#define R_MPI_BSEND_OVERHEAD.*",
            "#define R_MPI_BSEND_OVERHEAD 95",
            text,
            flags=re.MULTILINE,
        )

        lines_to_delete = ["extern int * R_MPI_UNWEIGHTED;", "extern int * R_MPI_WEIGHTS_EMPTY;"]
        text = delete_lines(lines_to_delete, text)
        text = re.sub(r"(#define R_MPI_DUP_FN.*)", r"//\1", text, flags=re.MULTILINE)
        text = re.sub(r"([ \t$])MPI_", r"\1R_MPI_", text, flags=re.MULTILINE)
        text = re.sub(r"HAVE_MPI", "HAVE_R_MPI", text, re.MULTILINE)
        text = re.sub(r"BIND_MPI", "BIND_R_MPI", text, re.MULTILINE)
        text = re.sub(r"BIND_MPI", "BIND_R_MPI", text, re.MULTILINE)
        text = re.sub(r"R_MPIX", "MPIX", text, re.MULTILINE)
        text = re.sub(r"F08_MPI", "F08_R_MPI", text, flags=re.MULTILINE)

        _pattern_block = """
/* See 4.12.5 for R_MPI_F_STATUS(ES)_IGNORE */
extern MPIU_DLL_SPEC R_MPI_Fint * R_MPI_F_STATUS_IGNORE MPICH_API_PUBLIC;
extern MPIU_DLL_SPEC R_MPI_Fint * R_MPI_F_STATUSES_IGNORE MPICH_API_PUBLIC;
/* The annotation MPIU_DLL_SPEC to the extern statements is used 
   as a hook for systems that require C extensions to correctly construct
   DLLs, and is defined as an empty string otherwise
 */
"""
        _replacement_block = """
/* See 4.12.5 for R_MPI_F_STATUS(ES)_IGNORE */
#define MPIU_DLL_SPEC
extern MPIU_DLL_SPEC R_MPI_Fint * R_MPI_F_STATUS_IGNORE;
extern MPIU_DLL_SPEC R_MPI_Fint * R_MPI_F_STATUSES_IGNORE;
//extern MPIU_DLL_SPEC int * R_MPI_UNWEIGHTED;
//extern MPIU_DLL_SPEC int * R_MPI_WEIGHTS_EMPTY;
int * R_MPI_UNWEIGHTED;
int * R_MPI_WEIGHTS_EMPTY;
int * MPI_UNWEIGHTED;
int * MPI_WEIGHTS_EMPTY;

/* The annotation MPIU_DLL_SPEC to the extern statements is used 
   as a hook for systems that require C extensions to correctly construct
   DLLs, and is defined as an empty string otherwise
 */
"""
        text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)

        _pattern_block = """
#define R_MPI_T_ERR_PVAR_NO_ATOMIC    72  /* Pvar can't be R/W atomically */
"""
        _replacement_block = """
#define R_MPI_T_ERR_PVAR_NO_ATOMIC    72  /* Pvar can't be R/W atomically */
#define R_MPI_T_ERR_INVALID_NAME      73  /* Name doesn't match */
#define R_MPI_T_ERR_INVALID           74  /* Generic error code for MPI_T added in MPI-3.1 */
"""
        text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)

        text = re.sub(
            r"(#define MPICH_ERR_LAST_CLASS) [0-9][0-9](.*)", r"\1 74\2", text, re.MULTILINE
        )
        text = re.sub(r"R_MPIX", "MPIX", text, re.MULTILINE)
        text = re.sub(r"R_PMPIX_Comm", "PMPIX_Comm", text, re.MULTILINE)
        text = re.sub(r"R_MPIX_Grequest", "MPIX_Grequest", text)
        text = re.sub(r"R_MPIX_Mutex", "MPIX_Mutex", text)
        text = re.sub(r"R_PMPIX_Grequest", "PMPIX_Grequest", text)
        text = re.sub(r"R_PMPIX_Mutex", "PMPIX_Mutex", text)
        text = re.sub(r"R_MPIX_Iov", "MPIX_Iov", text)

        return text

    def intel_generate_run_mpih(self, gen_file):
        """
        Generates the run_mpi.h file with Intel-specific modifications.

        Args:
            gen_file (str): The path to the generated file.
        """
        log.debug("Running intel_generate_run_mpih (IntelHeaderGenerator).")
        with open(gen_file, "r", encoding="utf-8") as _file:
            _content = _file.read()
        _new_content = self._replace_mpi_with_rmpi(_content)
        _new_content = self.intel_exceptions_run_mpih(_new_content)
        with open(gen_file, "w", encoding="utf-8") as _file:
            _file.write(_new_content)

    def _generate_run_mpih(self, gen_file):
        """
        Generates the run_mpi.h file.

        Args:
            gen_file (str): The path to the generated file.
        """
        log.debug("Running _generate_run_mpih (IntelHeaderGenerator).")
        self.intel_generate_run_mpih(gen_file)

    def intel_exceptions_run_mpioh(self, text):
        """
        Applies MPICH-specific exceptions for run_mpioh file.

        Args:
            text (str): The content of the file.

        Returns:
            str: The modified content.
        """
        log.debug("Running intel_exceptions_run_mpioh (IntelHeaderGenerator).")

        text = re.sub(r"const", "", text)
        text = re.sub(r"R_MPIO", "MPIO", text)
        text = re.sub(r"([^RN])_MPI", r"\1_R_MPI", text)
        #
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
        log.debug("Running _generate_run_mpioh (IntelHeaderGenerator)")
        super()._generate_run_mpioh(gen_file)

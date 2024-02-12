#!/usr/bin/env python3
"""
Module for generating MPI header files.

This module provides classes and methods for generating MPI header files.

"""


import os
import re
from abc import abstractmethod,ABC
from logging import getLogger
from logging.config import fileConfig
from textoperator import (
    delete_lines,
    delete_line_from_pattern,
    insert_lines,
    function_to_delete,
    replacement_from_conf_file,
    delete_bloc_from_conf_file,
)

fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)), "logging.conf"))
log = getLogger("header_logger")

# Absolute path of this script
wi4mpi_root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


class HeaderGenerator(ABC):
    """
    Class for generating MPI header files.

    This class contains methods for generating MPI header files with specific modifications.

    Attributes:
        wi4mpi_root (str): Absolute path of the root directory.
        _run_mpi_header_file (str): Name of the run MPI header file.
        _run_mpio_header_file (str): Name of the run MPIO header file.
        _app_mpi_header_file (str): Name of the app MPI header file.
        _app_mpio_header_file (str): Name of the app MPIO header file.
        _wrapper_f_header_file (str): Name of the wrapper F header file.
        dir_output (str): Output directory path.
        dir_input (str): Input directory path.

    Methods:
        set_directories: Set input and output directories for header generation.
        __init__: Initialize the HeaderGenerator object.
        _generate_wrapper_fh: Generate wrapper F header file.
        _replace_mpi_with_rmpi: Replace occurrences of MPI_ with R_MPI_ in text.
        _generate_run_mpih: Generate run MPI header file.
        _common_generate_app_mpih: Generate common app MPI header content.
        _generate_app_mpih: Generate app MPI header file.
        _generate_run_mpioh: Generate run MPIO header file.
        generate: Generate MPI header files.

    """

    wi4mpi_root = wi4mpi_root
    _run_mpi_header_file = "run_mpi.h"
    _run_mpio_header_file = "run_mpio.h"
    _app_mpi_header_file = "app_mpi.h"
    _app_mpio_header_file = "app_mpio.h"
    _wrapper_f_header_file = "wrapper_f.h"
    dir_output = ""
    dir_input = ""

    def set_directories(self, dir_input="", dir_output=""):
        """
        Set input and output directories for header generation.

        Args:
            dir_input (str, optional): The input directory path. Defaults to "".
            dir_output (str, optional): The output directory path. Defaults to "".

        Returns:
            None
        """
        self.dir_input = dir_input
        self.dir_output = dir_output
        os.makedirs(self.dir_output, exist_ok=True)

    def __init__(self, dir_input="", dir_output=""):
        # Prevent instantiation of this class directly
        if type(self) is HeaderGenerator:
            raise Exception("HeaderGenerator is an abstract class and cannot be instantiated directly.")
        self.set_directories(dir_input=dir_input, dir_output=dir_output)

    @abstractmethod
    def _generate_wrapper_fh(self, gen_file):
        """
        Abstract method, must be implemented by a subclass.
        
        Generate the wrapper_f.h header file.
        """
        pass

    def _replace_mpi_with_rmpi(self, text: str) -> str:
        """
        Replace occurrences of MPI_ with R_MPI_ in the given text.

        This method replaces all occurrences of MPI_ with R_MPI_ in the provided text.
        It's typically used to modify the content of a file.

        :param text: A string, typically the content of a file, in which MPI_ should be replaced.
        :return: A modified string with MPI_ replaced by R_MPI_.
        """
        log.debug("Running _replace_mpi_with_rmpi (HeaderGenerator)")
        # Replace MPI with R_MPI
        text = re.sub(r"([ \t(*,)])MPI_", r"\1R_MPI_", text, flags=re.MULTILINE)
        text = re.sub(r"^MPI_", r"R_MPI_", text, flags=re.MULTILINE)

        # Replace MPIX with R_MPIX
        text = re.sub(r"([ \t(*,)])MPIX_", r"\1R_MPIX_", text, flags=re.MULTILINE)
        text = re.sub(r"^MPIX_", r"R_MPIX_", text, flags=re.MULTILINE)

        # Replace MPIO with R_MPIO
        text = re.sub(r"([ \t(*,)])MPIO_", r"\1R_MPIO_", text, flags=re.MULTILINE)
        text = re.sub(r"^MPIO_", r"R_MPIO_", text, flags=re.MULTILINE)

        # Replace PMPI with R_PMPI
        text = re.sub(r"([ \t(*,)])PMPI_", r"\1R_PMPI_", text, flags=re.MULTILINE)
        text = re.sub(r"^PMPI_", r"R_PMPI_", text, flags=re.MULTILINE)

        # Replace PMPIX with R_PMPIX
        text = re.sub(r"([ \t(*,)])PMPIX_", r"\1R_PMPIX_", text, flags=re.MULTILINE)
        text = re.sub(r"^PMPIX_", r"R_PMPIX_", text, flags=re.MULTILINE)

        text = re.sub(r'#include "mpi.h"', r'#include "run_mpi.h"', text)
        text = re.sub(r'#include "mpio.h"', r'#include "run_mpio.h"', text)
        _pattern_block = """
#define R_MPI_MAX_OBJECT_NAME    128
"""
        _replacement_block = """
#define R_MPI_MAX_OBJECT_NAME    128
#define R_MPI_MAX_DATAREP_STRING 128
"""
        text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)

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
                _new_content = self._replace_mpi_with_rmpi(_content)
            with open(gen_file, "w", encoding="utf-8") as _file:
                _file.write(_new_content)
        except FileNotFoundError:
            log.error(lambda: f"The file '{gen_file}' does not exist.")
        except ValueError:
            log.error("An error occurred during _generate_run_mpih.")

    def _common_generate_app_mpih(self, text):
        log.debug("Running _common_generate_app_mpih (HeaderGenerator)")
        # Suppression des lignes du début du fichiers
        idx = text.index("\ntypedef ")
        line_idx = len(text[:idx].split("\n"))
        text = delete_lines(range(0, line_idx + 1), text)

        # Suppression des lignes contenant #if et #endif
        lines_to_delete = []
        for line in text.split("\n"):
            if "#if" in line or "#endif" in line or "#else" in line:
                lines_to_delete.append(line)
        text = delete_lines(lines_to_delete, text)
        text = delete_line_from_pattern(r"__mpi_interface_deprecated__(", text)
        _conf_file = os.path.join(
            self.wi4mpi_root, "lib/etc/header._common_generate_app_mpih.replace"
        )
        text = replacement_from_conf_file(_conf_file, text)
        _pattern_block = """
#define A_MPI_T_ERR_INVALID             72
#define A_MPI_T_ERR_INVALID_NAME        73

/* Per MPI-3 p349 47, A_MPI_ERR_LASTCODE must be >= the last predefined
   A_MPI_ERR_<foo> code. Set the last code to allow some room for adding
   error codes without breaking ABI. */
#define A_MPI_ERR_LASTCODE              92
"""
        _replacement_block = """

/* for 1.8 these intentially overlap other error codes because A_MPI_ERR_LASTCODE
   can not be changed in a release series*/
#define A_MPI_T_ERR_INVALID             70
#define A_MPI_T_ERR_INVALID_NAME        71

/* Per MPI-3 p349 47, A_MPI_ERR_LASTCODE must be >= the last predefined
   A_MPI_ERR_<foo> code.  So just set it equal to the last code --
   A_MPI_ERR_RMA_SHARED, in this case. */
#define A_MPI_ERR_LASTCODE              A_MPI_ERR_RMA_SHARED
"""
        text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)
        _pattern_block = """
/* MPI-2 specifies that the name "A_MPI_TYPE_NULL_DELETE_FN" (and all
   related friends) must be accessible in C, C++, and Fortran. This is
   unworkable if the back-end Fortran compiler uses all caps for its
   linker symbol convention -- it results in two functions with
   different signatures that have the same name (i.e., both C and
   Fortran use the symbol A_MPI_TYPE_NULL_DELETE_FN).  So we have to
   #define the C names to be something else, so that they names are
   *accessed* through A_MPI_TYPE_NULL_DELETE_FN, but their actual symbol
   name is different.

   However, this file is included when the fortran wrapper functions
   are compiled in Open MPI, so we do *not* want these #defines in
   this case (i.e., we need the Fortran wrapper function to be
   protection for this case. */
"""
        _replacement_block = """
"""
        text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)
        list_of_functions_to_delete = [
            "int OA_MPI_C_A_MPI_TYPE_NULL_DELETE_FN",
            "int OA_MPI_C_A_MPI_TYPE_NULL_COPY_FN",
            "int OA_MPI_C_A_MPI_TYPE_DUP_FN",
            "int OA_MPI_C_A_MPI_COMM_NULL_DELETE_FN",
            "int OA_MPI_C_A_MPI_COMM_NULL_COPY_F",
            "int OA_MPI_C_A_MPI_COMM_DUP_FN",
            "int OA_MPI_C_A_MPI_NULL_DELETE_FN",
            "int OA_MPI_C_A_MPI_NULL_COPY_FN",
            "int OA_MPI_C_A_MPI_DUP_FN",
            "int OA_MPI_C_A_MPI_WIN_NULL_DELETE_FN",
            "int OA_MPI_C_A_MPI_WIN_NULL_COPY_FN",
            "int OA_MPI_C_A_MPI_WIN_DUP_FN",
        ]
        for _function in list_of_functions_to_delete:
            text = function_to_delete(text, _function)
        _conf_file = os.path.join(
            self.wi4mpi_root, "lib/etc/header._common_generate_app_mpih.bloc_0.replace"
        )
        text = delete_bloc_from_conf_file(_conf_file, text)
        _conf_file = os.path.join(
            self.wi4mpi_root, "lib/etc/header._common_generate_app_mpih.bloc_1.replace"
        )
        text = delete_bloc_from_conf_file(_conf_file, text)
        _conf_file = os.path.join(
            self.wi4mpi_root, "lib/etc/header._common_generate_app_mpih.bloc_2.replace"
        )
        text = delete_bloc_from_conf_file(_conf_file, text)
        text = delete_line_from_pattern(r"extern struct ompi_predefined_", text)
        text = delete_line_from_pattern(r"extern A_MPI_Fint *A_MPI_F_STATUS_IGNORE;", text)
        text = delete_line_from_pattern(r"extern A_MPI_Fint *A_MPI_F_STATUSES_IGNORE;", text)
        text = delete_line_from_pattern(r"/* Aggregate struct datatypes are not */", text)
        text = delete_line_from_pattern(
            r'/* Optional MPI2 datatypes, always declared and defined, but not "exported" as'
            r" A_MPI_LOGICAL1 */",
            text,
        )
        _conf_file = os.path.join(
            self.wi4mpi_root, "lib/etc/header._common_generate_app_mpih.bloc_3.replace"
        )
        text = delete_bloc_from_conf_file(_conf_file, text)
        _conf_file = os.path.join(
            self.wi4mpi_root, "lib/etc/header._common_generate_app_mpih.bloc_4.replace"
        )
        text = delete_bloc_from_conf_file(_conf_file, text)

        _pattern_block = """
}

/*
 * Conditional MPI 2 C++ bindings support.  Include if:
 *   - The user does not explicitly request us to skip it (when a C++ compiler
 *       is used to compile C code).
 *   - We want C++ bindings support
 *   - We are not building OMPI itself
 *   - We are using a C++ compiler
 */
#include "openmpi/ompi/mpi/cxx/mpicxx.h"

/* ROMIO requires MPI implementations to set this to 1 if they provide
   A_MPI_OFFSET.  We need to provide it because its used throughout the
   DDT engine */
#define HAVE_A_MPI_OFFSET 1
"""
        _replacement_block = """
#endif /*CCC_MPI*/"""
        text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)

        _pattern_block = """
  int A_MPI_Irecv(void *buf, int count, A_MPI_Datatype datatype, int source,
                             int tag, A_MPI_Comm comm, A_MPI_Request *request);
"""
        _replacement_block = """
  int A_MPI_Irecv(void *buf, int count, A_MPI_Datatype datatype, int source,
                             int tag, A_MPI_Comm comm, A_MPI_Request *request);
#define A_MPI_T_ERR_INVALID_NAME      73  /* Name doesn't match */
#define A_MPI_T_ERR_INVALID           74  /* Generic error code for MPI_T added in MPI-3.1 */
"""
        text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)
        lines_to_delete = [
            "typedef A_MPI_File_errhandler_fn A_MPI_File_errhandler_fn",
            "struct ompi_file_t;",
            "typedef void (A_MPI_File_errhandler_fn)(struct ompi_file_t**, int *, ...);",
        ]
        text = delete_lines(lines_to_delete, text)
        _conf_file = os.path.join(
            self.wi4mpi_root, "lib/etc/header._common_generate_app_mpih.bloc_5.replace"
        )
        text = delete_bloc_from_conf_file(_conf_file, text)
        text = insert_lines(
            [
                r"#ifndef CCC_MPI",
                r"#define CCC_MPI",
                r"",
                r"#ifndef __MPI__COMPILE__",
                r"#define A_MPI_ MPI_",
                r"#define A_PMPI_ PMPI_",
                r"#endif",
                r"typedef unsigned long size_t;",
            ],
            1,
            text,
        )
        _pattern_block = """
#define A_MPI_MAX_OBJECT_NAME   1024    /* max object name length */
"""
        _replacement_block = """
#define A_MPI_MAX_OBJECT_NAME    128
#define A_MPI_MAX_DATAREP_STRING 128
"""
        text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)

        return text

    def _generate_app_mpih(self, gen_file):
        log.debug("Running _generate_app_mpih (HeaderGenerator)")
        with open(gen_file, "r", encoding="utf-8") as _file:
            _content = _file.read()

        _new_content = self._common_generate_app_mpih(_content)
        with open(gen_file, "w", encoding="utf-8") as _file:
            _file.write(_new_content)

    def _generate_run_mpioh(self, gen_file):
        log.debug("Running _generate_run_mpioh (HeaderGenerator)")
        with open(gen_file, "r", encoding="utf-8") as _file:
            _content = _file.read()

        _new_content = self._replace_mpi_with_rmpi(_content)
        with open(gen_file, "w", encoding="utf-8") as _file:
            _file.write(_new_content)

    def generate(self):
        """
        Generate MPI header files.

        This method generates MPI header files by calling specific methods.

        Returns:
            None

        """
        log.debug("Running generate (HeaderGenerator)")
        self._generate_run_mpih(os.path.join(self.dir_output, self._run_mpi_header_file))
        self._generate_run_mpioh(os.path.join(self.dir_output, self._run_mpio_header_file))
        self._generate_app_mpih(os.path.join(self.dir_output, self._app_mpi_header_file))
        self._generate_wrapper_fh(os.path.join(self.dir_output, self._wrapper_f_header_file))

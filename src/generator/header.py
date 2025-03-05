#!/usr/bin/env python3
"""
Module for generating MPI header files.

This module provides classes and methods for generating MPI header files.
"""


import os
import re
import shutil
from abc import abstractmethod, ABC
from logging import getLogger
from logging.config import fileConfig
from textoperator import (
    delete_lines,
    delete_line_from_pattern,
    insert_lines,
    function_to_delete,
    replacement_from_conf_file,
    replace_bloc_from_conf_file,
    delete_bloc_from_conf_file,
)

fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)), "logging.conf"))
log = getLogger("header_logger")

# Absolute path of this script
wi4mpi_root = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))


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
        _run_mpi_proto_header_file (str): Name of the run MPI proto header file (MPICH).
        app_mpi_proto_header_file (str): Name of the app MPI proto header file (MPICH).
        dir_output (str): Output directory path.
        dir_input (str): Input directory path.
        etc_dir (str): Configuration files directory path.
        mpi_target_version (str): Version of the selected MPI standard.
        app (str): Used in copy_files to select file names to copy.
        run (str): Used in copy_files to select file names to copy.

    Methods:
        set_directories: Set input and output directories for header generation.
        __init__: Initialize the HeaderGenerator object.
        _generate_wrapper_fh: Generate wrapper F header file.
        _replace_mpi_with_rmpi: Replace occurrences of MPI_ with R_MPI_ in text.
        _generate_run_mpih: Generate run MPI header file.
        _common_generate_app_mpih: Generate common app MPI header content.
        _generate_app_mpih: Generate app MPI header file.
        intel_exceptions_run_mpioh:
        _generate_run_mpioh: Generate run MPIO header file.
        copy_file: Performs the copy from dir_input to dir_output.
        copy_files: Copy target headers
        _generate_app_mpioh: Method to be defined in subclasse.
        _generate_run_mpi_protoh: Method to be defined in subclasse.
        _generate_app_mpi_protoh: Method to be defined in subclasse.
        generate: Generate MPI header files.
    """

    wi4mpi_root = wi4mpi_root
    _run_mpi_header_file = "run_mpi.h"
    _run_mpio_header_file = "run_mpio.h"
    _app_mpi_header_file = "app_mpi.h"
    _app_mpio_header_file = "app_mpio.h"
    _wrapper_f_header_file = "wrapper_f.h"
    _run_mpi_proto_header_file = "run_mpi_proto.h"
    _app_mpi_proto_header_file = "app_mpi_proto.h"
    dir_output = ""
    dir_input = ""
    etc_dir = ""
    mpi_target_version = None
    app = None
    run = None

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
        print(self.wi4mpi_root)
        self.etc_dir = os.path.join(self.wi4mpi_root, "src/resources/generator_data/headers")

    def __init__(self, dir_input="", dir_output="", mpi_target_version=None):
        _msg = f"{self.__class__.__name__} in progress."
        log.info(_msg)
        self.set_directories(dir_input=dir_input, dir_output=dir_output)
        self.mpi_target_version = mpi_target_version

    @abstractmethod
    def _generate_wrapper_fh(self, gen_file):
        """
        Abstract method, must be implemented by a subclass.

        Generate the wrapper_f.h header file.

        Args:
            gen_file (str): The path to the generated file.
        """

    def _replace_mpi_with_rmpi(self, text: str) -> str:
        """
        Replace occurrences of MPI_ with R_MPI_ in the given text.

        This method replaces all occurrences of MPI_ with R_MPI_ in the provided text.
        It's typically used to modify the content of a file.

        Args:
            text (str): A string, typically the content of a file, in which MPI_ should be replaced.
        
        Returns:
            str: A modified string with MPI_ replaced by R_MPI_.
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

        # Replace QMPI with R_QMPI
        text = re.sub(r"([ \t(*,)])QMPI_", r"\1R_QMPI_", text, flags=re.MULTILINE)
        text = re.sub(r"^QMPI_", r"R_QMPI_", text, flags=re.MULTILINE)

        text = re.sub(r'#include "mpi.h"', r'#include "run_mpi.h"', text)
        text = re.sub(r'#include "mpio.h"', r'#include "run_mpio.h"', text)
        text = re.sub(r"#include <mpi_proto.h>", r"#include <run_mpi_proto.h>", text)
        _pattern_block = """
#define R_MPI_MAX_OBJECT_NAME    128
"""
        _replacement_block = """
#define R_MPI_MAX_OBJECT_NAME    128
#define R_MPI_MAX_DATAREP_STRING 128
"""
        text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)

        return text

    def _generate_run_mpih(self, gen_file):
        """
        Generates the 'run_mpi.h' file.

        Args:
            gen_file (str): The path to the generated file.
        """
        pass

    def _common_generate_app_mpih(self, text):
        """
        Manage common generation for app_mpi.h.

        Args:
            text (str): Text to be processed.

        Returns:
            str: The processed text.
        """
        log.debug("Running _common_generate_app_mpih (HeaderGenerator)")
        # Delete lines from the beginning of the file
        line_idx = len(text[: text.index("\ntypedef ")].split("\n"))
        text = delete_lines(range(0, line_idx + 1), text)
        # End of file for openmpi 5.0.3
        if "5.0.3" == self.mpi_target_version["openmpi"]:
            text = replace_bloc_from_conf_file(
                os.path.join(
                    self.etc_dir,
                    "header._common_generate_app_mpih.bloc_00.pattern",
                ),
                os.path.join(
                    self.etc_dir,
                    "header._common_generate_app_mpih.bloc_00.replace",
                ),
                text,
            )
        # Delete lines whichcontains #if et #endif
        lines_to_delete = []
        for line in text.split("\n"):
            if "#if" in line or "#endif" in line or "#else" in line:
                lines_to_delete.append(line)
        text = delete_lines(lines_to_delete, text)
        text = replacement_from_conf_file(
            os.path.join(self.etc_dir, "header._common_generate_app_mpih.replace"),
            text,
        )
        text = replace_bloc_from_conf_file(
            os.path.join(
                self.etc_dir,
                "header._common_generate_app_mpih.bloc_01.pattern",
            ),
            os.path.join(
                self.etc_dir,
                "header._common_generate_app_mpih.bloc_01.replace",
            ),
            text,
        )
        text = replace_bloc_from_conf_file(
            os.path.join(
                self.etc_dir,
                "header._common_generate_app_mpih.bloc_02.pattern",
            ),
            os.path.join(
                self.etc_dir,
                "header._common_generate_app_mpih.bloc_02.replace",
            ),
            text,
        )
        list_of_functions_to_delete = [
            "int A_OMPI_C_A_MPI_TYPE_NULL_DELETE_FN",
            "int A_OMPI_C_A_MPI_TYPE_NULL_COPY_FN",
            "int A_OMPI_C_A_MPI_TYPE_DUP_FN",
            "int A_OMPI_C_A_MPI_COMM_NULL_DELETE_FN",
            "int A_OMPI_C_A_MPI_COMM_NULL_COPY_F",
            "int A_OMPI_C_A_MPI_COMM_DUP_FN",
            "int A_OMPI_C_A_MPI_NULL_DELETE_FN",
            "int A_OMPI_C_A_MPI_NULL_COPY_FN",
            "int A_OMPI_C_A_MPI_DUP_FN",
            "int A_OMPI_C_A_MPI_WIN_NULL_DELETE_FN",
            "int A_OMPI_C_A_MPI_WIN_NULL_COPY_FN",
            "int A_OMPI_C_A_MPI_WIN_DUP_FN",
        ]
        for _function in list_of_functions_to_delete:
            text = function_to_delete(text, _function)
        text = re.sub(r"^.*__mpi_interface_deprecated__.*;$", ";", text, flags=re.MULTILINE)
        text = delete_bloc_from_conf_file(
            os.path.join(self.etc_dir, "header._common_generate_app_mpih.bloc_03.delete"),
            text,
        )
        text = delete_bloc_from_conf_file(
            os.path.join(self.etc_dir, "header._common_generate_app_mpih.bloc_04.delete"),
            text,
        )
        text = delete_bloc_from_conf_file(
            os.path.join(self.etc_dir, "header._common_generate_app_mpih.bloc_05.delete"),
            text,
        )
        text = delete_line_from_pattern(r"extern struct ompi_predefined_", text)
        text = delete_line_from_pattern(r"extern A_MPI_Fint *A_MPI_F_STATUS_IGNORE;", text)
        text = delete_line_from_pattern(r"extern A_MPI_Fint *A_MPI_F_STATUSES_IGNORE;", text)
        text = delete_line_from_pattern(r"/* Aggregate struct datatypes are not */", text)
        text = delete_line_from_pattern(
            r'/* Optional MPI2 datatypes, always declared and defined, but not "exported" as'
            r" A_MPI_LOGICAL1 */",
            text,
        )
        text = delete_bloc_from_conf_file(
            os.path.join(self.etc_dir, "header._common_generate_app_mpih.bloc_06.delete"),
            text,
        )
        text = delete_bloc_from_conf_file(
            os.path.join(self.etc_dir, "header._common_generate_app_mpih.bloc_07.delete"),
            text,
        )

        if "4.1.6" == self.mpi_target_version["openmpi"]:
            text = replace_bloc_from_conf_file(
                os.path.join(
                    self.etc_dir,
                    "header._common_generate_app_mpih.bloc_08a.pattern",
                ),
                os.path.join(
                    self.etc_dir,
                    "header._common_generate_app_mpih.bloc_08.replace",
                ),
                text,
            )
        else:
            text = replace_bloc_from_conf_file(
                os.path.join(
                    self.etc_dir,
                    "header._common_generate_app_mpih.bloc_08.pattern",
                ),
                os.path.join(
                    self.etc_dir,
                    "header._common_generate_app_mpih.bloc_08.replace",
                ),
                text,
            )
        text = replace_bloc_from_conf_file(
            os.path.join(
                self.etc_dir,
                "header._common_generate_app_mpih.bloc_09.pattern",
            ),
            os.path.join(
                self.etc_dir,
                "header._common_generate_app_mpih.bloc_09.replace",
            ),
            text,
        )
        lines_to_delete = [
            "typedef A_MPI_File_errhandler_fn A_MPI_File_errhandler_fn",
            "struct ompi_file_t;",
            "typedef void (A_MPI_File_errhandler_fn)(struct ompi_file_t**, int *, ...);",
        ]
        text = delete_lines(lines_to_delete, text)
        text = delete_bloc_from_conf_file(
            os.path.join(self.etc_dir, "header._common_generate_app_mpih.bloc_10.delete"),
            text,
        )
        # Insert lines at the top of app_mpi.h file
        lines_to_insert = [
            "#ifndef CCC_MPI",
            "#define CCC_MPI",
            "",
            "#ifndef __MPI__COMPILE__",
            "#define A_MPI_ MPI_",
            "#define A_PMPI_ PMPI_",
            "#endif",
            "typedef unsigned long size_t;",
        ]
        if "5.0.3" == self.mpi_target_version["openmpi"]:
            lines_to_insert.append("/* The number or Fortran INTEGER in MPI Status */")
            lines_to_insert.append("#define A_OMPI_FORTRAN_STATUS_SIZE 6")
        text = insert_lines(lines_to_insert, 1, text)
        #
        text = replace_bloc_from_conf_file(
            os.path.join(
                self.etc_dir,
                "header._common_generate_app_mpih.bloc_06.pattern",
            ),
            os.path.join(
                self.etc_dir,
                "header._common_generate_app_mpih.bloc_06.replace",
            ),
            text,
        )
        if (
            "4.1.6" == self.mpi_target_version["openmpi"]
            or "5.0.3" == self.mpi_target_version["openmpi"]
        ):
            text = delete_line_from_pattern("  define A_MPI_UB", text)
            text = delete_line_from_pattern("  define A_MPI_LB", text)
            line_idx = len(text[: text.index("\n#define A_MPI_2INT 20")].split("\n"))
            lines_to_insert = [
                "#define A_MPI_UB 21 ",
                "#define A_MPI_LB 22 ",
            ]
            text = insert_lines(lines_to_insert, line_idx, text)
            text = delete_line_from_pattern("#define A_MPI_Errhandler_set(...)", text)
            text = delete_line_from_pattern("#define A_MPI_Errhandler_get(...)", text)
            text = delete_line_from_pattern("THIS_FUNCTION_WAS_REMOVED_IN_MPI30", text)

        return text

    def _generate_app_mpih(self, gen_file):
        """
        Generates the 'app_mpi.h' file.

        Args:
            gen_file (str): The path to the generated file.
        """
        log.debug("Running _generate_app_mpih (HeaderGenerator)")
        with open(gen_file, "r", encoding="utf-8") as _file:
            _content = _file.read()

        _new_content = self._common_generate_app_mpih(_content)
        with open(gen_file, "w", encoding="utf-8") as _file:
            _file.write(_new_content)

    def intel_exceptions_run_mpioh(self, text):
        """
        Manage execptions for intel run_mpio.h.
        This function is overloaded inside subclasses.

        Args:
            text (str): Text to be processed.

        Returns:
            str: The processed text.
        """
        return text

    def _generate_run_mpioh(self, gen_file):
        """
        Generates the 'run_mpio.h' file.

        Args:
            gen_file (str): The path to the generated file.
        """
        log.debug("Running _generate_run_mpioh (HeaderGenerator)")
        with open(gen_file, "r", encoding="utf-8") as _file:
            _content = _file.read()

        _new_content = self._replace_mpi_with_rmpi(_content)
        _new_content = self.intel_exceptions_run_mpioh(_new_content)
        with open(gen_file, "w", encoding="utf-8") as _file:
            _file.write(_new_content)

    def copy_file(self, input_file_name, output_file_name):
        """
        Performs the copy from dir_input to dir_output.

        Args:
            input_file_name (str): Name of the file to copy.
            output_file_name (str): Name of the copied file.
        """
        shutil.copy2(
            os.path.join(self.dir_input, input_file_name),
            os.path.join(self.dir_output, output_file_name),
        )

    def copy_files(self):
        """
        Copy target headers.
	This method mutualizes the copying of the product header files.
        """
        log.debug("Running copy_files (HeaderGenerator)")
        if self.app in (None, "openmpi"):
            input_file_name = f"openmpi/{self.mpi_target_version['openmpi']}/mpi.h"
            self.copy_file(input_file_name, "app_mpi.h")

        if self.app in ("intelmpi", "mpich"):
            input_file_name = f"{self.app}/{self.mpi_target_version[f'{self.app}']}/mpio.h"
            self.copy_file(input_file_name, "app_mpio.h")
            input_file_name = f"{self.app}/{self.mpi_target_version[f'{self.app}']}/mpi.h"
            self.copy_file(input_file_name, "app_mpi.h")

        if self.app == "mpich" and "4.2.0" == self.mpi_target_version["mpich"]:
            input_file_name = f"{self.app}/{self.mpi_target_version[f'{self.app}']}/mpi_proto.h"
            self.copy_file(input_file_name, "app_mpi_proto.h")

        input_file_name = f"{self.run}/{self.mpi_target_version[f'{self.run}']}/mpi.h"
        self.copy_file(input_file_name, "run_mpi.h")

        if self.run in ("intelmpi", "mpich"):
            input_file_name = f"{self.run}/{self.mpi_target_version[f'{self.run}']}/mpio.h"
            self.copy_file(input_file_name, "run_mpio.h")
            input_file_name = f"{self.run}/{self.mpi_target_version[f'{self.run}']}/mpi.h"
            self.copy_file(input_file_name, "run_mpi.h")

        if self.run == "mpich" and "4.2.0" == self.mpi_target_version["mpich"]:
            input_file_name = f"{self.run}/{self.mpi_target_version[f'{self.run}']}/mpi_proto.h"
            self.copy_file(input_file_name, "run_mpi_proto.h")

    def _generate_app_mpioh(self, _):
        """
        Method to be defined in subclasse.
        """
        log.debug("Running copy_files (HeaderGenerator)")

    def _generate_run_mpi_protoh(self, _):
        """
        Method to be defined in subclasse.
        """
        log.debug("Running _generate_run_mpi_protoh (HeaderGenerator)")

    def _generate_app_mpi_protoh(self, _):
        """
        Method to be defined in subclasse.
        """
        log.debug("Running _generate_app_mpi_protoh (HeaderGenerator)")

    def generate(self):
        """
        Generate MPI header files.

        This method generates MPI header files by calling specific methods.

        Returns:
            None

        """
        log.debug("Running generate (HeaderGenerator)")
        self.copy_files()
        self._generate_run_mpih(os.path.join(self.dir_output, self._run_mpi_header_file))
        self._generate_run_mpioh(os.path.join(self.dir_output, self._run_mpio_header_file))
        self._generate_app_mpih(os.path.join(self.dir_output, self._app_mpi_header_file))
        self._generate_app_mpioh(os.path.join(self.dir_output, self._app_mpio_header_file))
        self._generate_run_mpi_protoh(
            os.path.join(self.dir_output, self._run_mpi_proto_header_file)
        )
        self._generate_app_mpi_protoh(
            os.path.join(self.dir_output, self._app_mpi_proto_header_file)
        )
        self._generate_wrapper_fh(os.path.join(self.dir_output, self._wrapper_f_header_file))

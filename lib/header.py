#!/usr/bin/env python3

import os
import re
from logging import getLogger
from logging.config import fileConfig
from textoperator import delete_lines, delete_line_from_pattern, insert_lines, function_to_delete

fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)), "logging.conf"))
log = getLogger("header_logger")

# Absolute path of this script
wi4mpi_root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


class HeaderGenerator:
    _run_mpi_header_file = "run_mpi.h"
    _run_mpio_header_file = "run_mpio.h"
    _app_mpi_header_file = "app_mpi.h"
    _app_mpio_header_file = "app_mpio.h"
    _wrapper_f_header_file = "wrapper_f.h"
    dir_output = ""

    def _generate_wrapper_fh(self, gen_file):
        log.warning(
            "The generation of wrapper_f.h have to be done locally.\n\tA MPC program has to be"
            " executed in order to catch MPI_MODE_XXX values.\n\tHave a look to"
            " generator/FORTRAN/MPI_XXX_generator/MPC/gen_MPC_vars.sh"
        )

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
            with open(gen_file, "r") as _file:
                _content = _file.read()
                _new_content = self._replace_mpi_with_rmpi(_content)
            with open(gen_file, "w") as _file:
                _file.write(_new_content)
        except FileNotFoundError:
            log.error(f"The file '{gen_file}' does not exist.")
        except Exception as e:
            log.error(f"An error occurred: {str(e)}")

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

        pattern = []
        replacement = []
        decalage = 0

        pattern.append(r"MPI_")
        replacement.append(r"A_MPI_")
        pattern.append(r"PA_MPI_")
        replacement.append(r"A_PMPI_")

        pattern.append(r"typedef OPAL.*A_")
        replacement.append(r"typedef size_t A_")
        pattern.append(r"typedef OA_MPI.*A_")
        replacement.append(r"typedef size_t A_")
        pattern.append(r"typedef struct.*A_")
        replacement.append(r"typedef size_t A_")
        pattern.append(r"typedef size_t A_MPI_Count;")
        replacement.append(r"//typedef size_t A_MPI_Count;\ntypedef long long A_MPI_Count;")
        pattern.append(r"typedef size_t A_MPI_Status;")
        replacement.append(r"//typedef size_t A_MPI_Status;")
        pattern.append(r"typedef size_t A_MPI_T_pvar_session;\n")
        replacement.append(r"typedef size_t A_MPI_T_pvar_session;\n\ntypedef int A_MPI_Fint;")
        pattern.append(r"struct ompi_status_public_t {")
        replacement.append("struct CCC_mpi_status_struct {")
        pattern.append(r"struct ompi_status_public_t {")
        replacement.append("struct CCC_mpi_status_struct {")
        pattern.append(r"typedef struct ompi_status_public_t ompi_status_public_t;")
        replacement.append("typedef struct CCC_mpi_status_struct A_MPI_Status;")
        pattern.append(r"OA_MPI_DECLSPEC")
        replacement.append("")
        pattern.append(r"const ")
        replacement.append("")
        pattern.append(r"A_MPI_MAX_PROCESSOR_NAME OPAL_MAX_PROCESSOR_NAME")
        replacement.append("OPAL_MAX_PROCESSOR_NAME 512")
        pattern.append(r"A_MPI_MAX_ERROR_STRING   OPAL_MAX_ERROR_STRING")
        replacement.append("OPAL_MAX_ERROR_STRING  2048")
        pattern.append(r"A_MPI_MAX_OBJECT_NAME    OPAL_MAX_OBJECT_NAME")
        replacement.append("OPAL_MAX_OBJECT_NAME   1024")
        pattern.append(r"A_MPI_MAX_INFO_KEY         OPAL_MAX_INFO_KEY")
        replacement.append("A_MPI_MAX_INFO_KEY 256")
        pattern.append(r"A_MPI_MAX_INFO_VAL         OPAL_MAX_INFO_VAL")
        replacement.append("A_MPI_MAX_INFO_VAL 512")
        pattern.append(r"A_MPI_MAX_PORT_NAME        OPAL_MAX_PORT_NAME")
        replacement.append("A_MPI_MAX_PORT_NAME 512")
        pattern.append(r"A_MPI_MAX_DATAREP_STRING OPAL_MAX_DATAREP_STRING\n")
        replacement.append("A_MPI_MAX_DATAREP_STRING 512")
        pattern.append(r"#define A_MPI_GROUP_NULL .*")
        replacement.append(r"#define A_MPI_GROUP_NULL 0x0")
        pattern.append(r"#define A_MPI_COMM_NULL .*")
        replacement.append(r"#define A_MPI_COMM_NULL 0x0")
        pattern.append(r"#define A_MPI_REQUEST_NULL .*")
        replacement.append(r"#define A_MPI_REQUEST_NULL 0x0")
        pattern.append(r"#define A_MPI_MESSAGE_NULL .*")
        replacement.append(r"#define A_MPI_MESSAGE_NULL 0x0")

        pattern.append(r"#define A_MPI_OP_NULL .*")
        pattern.append(r"#define A_MPI_ERRHANDLER_NULL .*")
        pattern.append(r"#define A_MPI_INFO_NULL .*")
        pattern.append(r"#define A_MPI_WIN_NULL .*")
        pattern.append(r"#define A_MPI_FILE_NULL .*")
        pattern.append(r"#define A_MPI_T_ENUM_NULL .*")
        pattern.append(r"#define A_MPI_INFO_ENV .*")
        pattern.append(r"#define A_MPI_STATUS_IGNORE .*")
        pattern.append(r"#define A_MPI_STATUSES_IGNORE .*")
        pattern.append(r"#define A_MPI_NULL_DELETE_FN .*")
        pattern.append(r"#define A_MPI_NULL_COPY_FN .*")
        pattern.append(r"#define A_MPI_TYPE_NULL_DELETE_FN .*")
        pattern.append(r"#define A_MPI_TYPE_NULL_COPY_FN .*")
        pattern.append(r"#define A_MPI_COMM_NULL_DELETE_FN .*")
        pattern.append(r"#define A_MPI_COMM_NULL_COPY_FN .*")
        pattern.append(r"#define A_MPI_WIN_NULL_DELETE_FN .*")
        pattern.append(r"#define A_MPI_WIN_NULL_COPY_FN .*")
        replacement.append(r"#define A_MPI_OP_NULL 0x0")
        replacement.append(r"#define A_MPI_ERRHANDLER_NULL 0x0")
        replacement.append(r"#define A_MPI_INFO_NULL 0x0")
        replacement.append(r"#define A_MPI_WIN_NULL 0x0")
        replacement.append(r"#define A_MPI_FILE_NULL 0x0")
        replacement.append(r"#define A_MPI_T_ENUM_NULL 0x0")
        replacement.append(r"#define A_MPI_INFO_ENV 0x0 ")
        replacement.append(r"#define A_MPI_STATUS_IGNORE 0x0")
        replacement.append(r"#define A_MPI_STATUSES_IGNORE 0x0")
        replacement.append(r"#define A_MPI_NULL_DELETE_FN  0x0")
        replacement.append(r"#define A_MPI_NULL_COPY_FN  0x0")
        replacement.append(r"#define A_MPI_TYPE_NULL_DELETE_FN  0x0")
        replacement.append(r"#define A_MPI_TYPE_NULL_COPY_FN  0x0")
        replacement.append(r"#define A_MPI_COMM_NULL_DELETE_FN  0x0")
        replacement.append(r"#define A_MPI_COMM_NULL_COPY_FN  0x0")
        replacement.append(r"#define A_MPI_WIN_NULL_DELETE_FN  0x0")
        replacement.append(r"#define A_MPI_WIN_NULL_COPY_FN  0x0")

        pattern.append(
            r"A_MPI_COMM_WORLD OA_MPI_PREDEFINED_GLOBAL\( A_MPI_Comm, ompi_mpi_comm_world\)"
        )
        replacement.append("A_MPI_COMM_WORLD 0x1")
        pattern.append(
            r"A_MPI_COMM_SELF OA_MPI_PREDEFINED_GLOBAL\(A_MPI_Comm, ompi_mpi_comm_self\)"
        )
        replacement.append("A_MPI_COMM_SELF 0x2")
        pattern.append(
            r"#define A_MPI_GROUP_EMPTY OA_MPI_PREDEFINED_GLOBAL\(A_MPI_Group,"
            r" ompi_mpi_group_empty\)"
        )
        replacement.append("#define A_MPI_GROUP_EMPTY 0x1")
        pattern.append(
            r"A_MPI_MESSAGE_NO_PROC OA_MPI_PREDEFINED_GLOBAL\(A_MPI_Message, ompi_message_no_proc\)"
        )
        replacement.append("A_MPI_MESSAGE_NO_PROC 0x1")

        for _pattern, _replacement in zip(pattern, replacement):
            decalage += len(_replacement.split("\n")) - len(_pattern.split("\n"))
            text = re.sub(_pattern, _replacement, text, flags=re.MULTILINE)
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
#define OPAL_MAX_PROCESSOR_NAME 512 /* max proc. name length */
#define OPAL_MAX_ERROR_STRING  2048   /* max error message length */
#define OPAL_MAX_OBJECT_NAME   1024    /* max object name length */
"""
        _replacement_block = """
#define A_MPI_MAX_PROCESSOR_NAME 512 /* max proc. name length */
#define A_MPI_MAX_ERROR_STRING  2048   /* max error message length */
#define A_MPI_MAX_OBJECT_NAME   1024    /* max object name length */
"""
        text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)
        ##
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

        pattern = []
        replacement = []

        pattern.append(r"(^#define A_MPI_MAX) .*")
        pattern.append(r"(^#define A_MPI_MIN) .*")
        pattern.append(r"(^#define A_MPI_SUM) .*")
        pattern.append(r"(^#define A_MPI_PROD) .*")
        pattern.append(r"(^#define A_MPI_LAND) .*")
        pattern.append(r"(^#define A_MPI_BAND) .*")
        pattern.append(r"(^#define A_MPI_LOR) .*")
        pattern.append(r"(^#define A_MPI_BOR) .*")
        pattern.append(r"(^#define A_MPI_LXOR) .*")
        pattern.append(r"(^#define A_MPI_BXOR) .*")
        pattern.append(r"(^#define A_MPI_MAXLOC) .*")
        pattern.append(r"(^#define A_MPI_MINLOC) .*")
        pattern.append(r"(^#define A_MPI_REPLACE) .*")
        pattern.append(r"(^#define A_MPI_NO_OP) .*")
        for value in range(1, 15):
            replacement.append(r"\1 " + f"{value}")

        # /* C datatypes */
        pattern.append(r"(^#define A_MPI_DATATYPE_NULL) .*")
        pattern.append(r"(^#define A_MPI_BYTE) .*")
        pattern.append(r"(^#define A_MPI_PACKED) .*")
        pattern.append(r"(^#define A_MPI_CHAR) .*")
        pattern.append(r"(^#define A_MPI_SHORT) .*")
        pattern.append(r"(^#define A_MPI_INT) .*")
        pattern.append(r"(^#define A_MPI_LONG) .*")
        pattern.append(r"(^#define A_MPI_FLOAT) .*")
        pattern.append(r"(^#define A_MPI_DOUBLE) .*")
        pattern.append(r"(^#define A_MPI_LONG_DOUBLE) .*")
        pattern.append(r"(^#define A_MPI_UNSIGNED_CHAR) .*")
        pattern.append(r"(^#define A_MPI_SIGNED_CHAR) .*")
        pattern.append(r"(^#define A_MPI_UNSIGNED_SHORT) .*")
        pattern.append(r"(^#define A_MPI_UNSIGNED_LONG) .*")
        pattern.append(r"(^#define A_MPI_UNSIGNED) .*")
        pattern.append(r"(^#define A_MPI_FLOAT_INT) .*")
        pattern.append(r"(^#define A_MPI_DOUBLE_INT) .*")
        pattern.append(r"(^#define A_MPI_LONG_DOUBLE_INT) .*")
        pattern.append(r"(^#define A_MPI_LONG_INT) .*")
        pattern.append(r"(^#define A_MPI_SHORT_INT) .*")
        pattern.append(r"(^#define A_MPI_2INT) .*")
        pattern.append(r"(^#define A_MPI_UB) .*")
        pattern.append(r"(^#define A_MPI_LB) .*")
        pattern.append(r"(^#define A_MPI_WCHAR) .*")
        pattern.append(r"(^#define A_MPI_LONG_LONG_INT) .*")
        pattern.append(r"(^#define A_MPI_LONG_LONG) .*")
        pattern.append(r"(^#define A_MPI_UNSIGNED_LONG_LONG) .*")
        pattern.append(r"(^#define A_MPI_2COMPLEX) .*")
        pattern.append(r"(^#define A_MPI_2DOUBLE_COMPLEX) .*")
        # /* Fortran datatype bindings */
        pattern.append(r"(^#define A_MPI_CHARACTER) .*")
        pattern.append(r"(^#define A_MPI_LOGICAL) .*")
        pattern.append(r"(^#define A_MPI_LOGICAL1) .*")
        pattern.append(r"(^#define A_MPI_LOGICAL2) .*")
        pattern.append(r"(^#define A_MPI_LOGICAL4) .*")
        pattern.append(r"(^#define A_MPI_LOGICAL8) .*")
        pattern.append(r"(^#define A_MPI_INTEGER) .*")
        pattern.append(r"(^#define A_MPI_INTEGER1) .*")
        pattern.append(r"(^#define A_MPI_INTEGER2) .*")
        pattern.append(r"(^#define A_MPI_INTEGER4) .*")
        pattern.append(r"(^#define A_MPI_INTEGER8) .*")
        pattern.append(r"(^#define A_MPI_INTEGER16) .*")
        pattern.append(r"(^#define A_MPI_REAL) .*")
        pattern.append(r"(^#define A_MPI_REAL4) .*")
        pattern.append(r"(^#define A_MPI_REAL8) .*")
        pattern.append(r"(^#define A_MPI_REAL16) .*")
        pattern.append(r"(^#define A_MPI_DOUBLE_PRECISION) .*")
        pattern.append(r"(^#define A_MPI_COMPLEX) .*")
        pattern.append(r"(^#define A_MPI_COMPLEX8) .*")
        pattern.append(r"(^#define A_MPI_COMPLEX16) .*")
        pattern.append(r"(^#define A_MPI_COMPLEX32) .*")
        pattern.append(r"(^#define A_MPI_DOUBLE_COMPLEX) .*")
        pattern.append(r"(^#define A_MPI_2REAL) .*")
        pattern.append(r"(^#define A_MPI_2DOUBLE_PRECISION) .*")
        pattern.append(r"(^#define A_MPI_2INTEGER) .*")
        for value in range(54):
            replacement.append(r"\1 " + f"{value}")
        # /* New datatypes from the MPI 2.2 standard */
        pattern.append(r"^#define A_MPI_INT8_T .*")
        value = 54
        padding = 36
        replacement.append("#define A_MPI_INT8_T".ljust(padding) + f"{value}")
        pattern.append(r"^#define A_MPI_UINT8_T .*")
        value += 1
        replacement.append("#define A_MPI_UINT8_T".ljust(padding) + f"{value}")
        pattern.append(r"^#define A_MPI_INT16_T .*")
        value += 1
        replacement.append("#define A_MPI_INT16_T".ljust(padding) + f"{value}")
        pattern.append(r"^#define A_MPI_UINT16_T .*")
        value += 1
        replacement.append("#define A_MPI_UINT16_T".ljust(padding) + f"{value}")
        pattern.append(r"^#define A_MPI_INT32_T .*")
        value += 1
        replacement.append("#define A_MPI_INT32_T".ljust(padding) + f"{value}")
        pattern.append(r"^#define A_MPI_UINT32_T .*")
        value += 1
        replacement.append("#define A_MPI_UINT32_T".ljust(padding) + f"{value}")
        pattern.append(r"^#define A_MPI_INT64_T .*")
        value += 1
        replacement.append("#define A_MPI_INT64_T".ljust(padding) + f"{value}")
        pattern.append(r"^#define A_MPI_UINT64_T .*")
        value += 1
        replacement.append("#define A_MPI_UINT64_T".ljust(padding) + f"{value}")
        pattern.append(r"^#define A_MPI_AINT .*")
        value += 1
        replacement.append("#define A_MPI_AINT".ljust(padding) + f"{value}")
        pattern.append(r"^#define A_MPI_OFFSET .*")
        value += 1
        replacement.append("#define A_MPI_OFFSET".ljust(padding) + f"{value}")
        pattern.append(r"^#define A_MPI_C_BOOL .*")
        value += 1
        replacement.append("#define A_MPI_C_BOOL".ljust(padding) + f"{value}")
        pattern.append(r"^#define A_MPI_C_COMPLEX .*")
        value += 1
        replacement.append("#define A_MPI_C_COMPLEX".ljust(padding) + f"{value}")
        pattern.append(r"^#define A_MPI_C_FLOAT_COMPLEX .*")
        value += 1
        replacement.append("#define A_MPI_C_FLOAT_COMPLEX".ljust(padding) + f"{value}")
        pattern.append(r"^#define A_MPI_C_DOUBLE_COMPLEX .*")
        value += 1
        replacement.append("#define A_MPI_C_DOUBLE_COMPLEX".ljust(padding) + f"{value}")
        pattern.append(r"^#define A_MPI_C_LONG_DOUBLE_COMPLEX .*")
        value += 1
        replacement.append("#define A_MPI_C_LONG_DOUBLE_COMPLEX".ljust(padding) + f"{value}")
        pattern.append(r"^#define A_MPI_CXX_BOOL .*")
        value += 1
        replacement.append("#define A_MPI_CXX_BOOL".ljust(padding) + f"{value}")
        pattern.append(r"^#define A_MPI_CXX_FLOAT_COMPLEX .*")
        value += 1
        replacement.append("#define A_MPI_CXX_FLOAT_COMPLEX".ljust(padding) + f"{value}")
        pattern.append(r"^#define A_MPI_CXX_DOUBLE_COMPLEX .*")
        value += 1
        replacement.append("#define A_MPI_CXX_DOUBLE_COMPLEX".ljust(padding) + f"{value}")
        pattern.append(r"^#define A_MPI_CXX_LONG_DOUBLE_COMPLEX .*")
        value += 1
        padding += 2
        replacement.append("#define A_MPI_CXX_LONG_DOUBLE_COMPLEX".ljust(padding) + f"{value}")
        # /* New datatypes from the 3.0 standard */
        pattern.append(r"^#define A_MPI_COUNT .*")
        value += 1
        replacement.append(f"#define A_MPI_COUNT {value} ")

        pattern.append(r"(^#define A_MPI_ERRORS_ARE_FATAL) .*")
        value = 1
        replacement.append(r"\1 " + f"{value}")
        pattern.append(r"(^#define A_MPI_ERRORS_RETURN) .*")
        value += 1
        replacement.append(r"\1 " + f"{value} ")

        pattern.append(r"struct mca_base_pvar_session_t \*")
        replacement.append(r"")

        pattern.append(r"OA_MPI_C_A_MPI_DUP_FN\n")
        pattern.append(r"OA_MPI_C_A_MPI_TYPE_DUP_FN\n")
        pattern.append(r"OA_MPI_C_A_MPI_COMM_DUP_FN\n")
        pattern.append(r"OA_MPI_C_A_MPI_WIN_DUP_FN\n")
        replacement.append(r" 0x1\n")
        replacement.append(r" 0x1\n")
        replacement.append(r" 0x1\n")
        replacement.append(r" 0x1\n")

        for _pattern, _replacement in zip(pattern, replacement):
            decalage += len(_replacement.split("\n")) - len(_pattern.split("\n"))
            text = re.sub(_pattern, _replacement, text, flags=re.MULTILINE)

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
        text = function_to_delete(text, "int OA_MPI_C_A_MPI_TYPE_NULL_DELETE_FN")
        text = function_to_delete(text, "int OA_MPI_C_A_MPI_TYPE_NULL_COPY_FN")
        text = function_to_delete(text, "int OA_MPI_C_A_MPI_TYPE_DUP_FN")
        text = function_to_delete(text, "int OA_MPI_C_A_MPI_COMM_NULL_DELETE_FN")
        text = function_to_delete(text, "int OA_MPI_C_A_MPI_COMM_NULL_COPY_F")
        text = function_to_delete(text, "int OA_MPI_C_A_MPI_COMM_DUP_FN")
        text = function_to_delete(text, "int OA_MPI_C_A_MPI_NULL_DELETE_FN")
        text = function_to_delete(text, "int OA_MPI_C_A_MPI_NULL_COPY_FN")
        text = function_to_delete(text, "int OA_MPI_C_A_MPI_DUP_FN")
        text = function_to_delete(text, "int OA_MPI_C_A_MPI_WIN_NULL_DELETE_FN")
        text = function_to_delete(text, "int OA_MPI_C_A_MPI_WIN_NULL_COPY_FN")
        text = function_to_delete(text, "int OA_MPI_C_A_MPI_WIN_DUP_FN")

        _pattern_block = """
/*
 * External variables
 *
 * The below externs use the ompi_predefined_xxx_t structures to maintain
 * back compatibility between MPI library versions.
 * See ompi/communicator/communicator.h comments with struct ompi_communicator_t
 * for full explanation why we chose to use the ompi_predefined_xxx_t structure.
 */
"""
        _replacement_block = """"""
        text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)
        _pattern_block = """
/*
 * Following are the C++/C99 datatypes
 */
"""
        _replacement_block = """"""
        text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)
        _pattern_block = """
/*
 * Following are the Fortran datatypes
 */
"""
        _replacement_block = """"""
        text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)

        text = delete_line_from_pattern(r"extern struct ompi_predefined_", text)
        text = delete_line_from_pattern(r"extern A_MPI_Fint *A_MPI_F_STATUS_IGNORE;", text)
        text = delete_line_from_pattern(r"extern A_MPI_Fint *A_MPI_F_STATUSES_IGNORE;", text)
        text = delete_line_from_pattern(r"/* Aggregate struct datatypes are not */", text)
        text = delete_line_from_pattern(
            r'/* Optional MPI2 datatypes, always declared and defined, but not "exported" as'
            r" A_MPI_LOGICAL1 */",
            text,
        )

        _pattern_block = """
    /* A_MPI_Handler_function is deprecated, but we don't mark it as
       such because otherwise the A_MPI_Errhandler_create() declaration
       would cause a warning to be issued */
"""
        _replacement_block = """
"""
        text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)

        text = delete_line_from_pattern(r"__mpi_interface_deprecated__(", text)

        _pattern_block = """
    /* This is a little hackish, but errhandler.h needs space for a
       A_MPI_File_errhandler_fn.  While it could just be removed, this
       allows us to maintain a stable ABI within OMPI, at least for
       apps that don't use MPI I/O. */
"""
        _replacement_block = """
"""
        text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)

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

        pattern = []
        replacement = []
        pattern.append(r"typedef A_MPI_Comm_errhandler_function A_MPI_Comm_errhandler_fn\n")
        replacement.append("typedef A_MPI_Comm_errhandler_function A_MPI_Comm_errhandler_fn;")
        pattern.append(r"ompi_file_errhandler_fn")
        replacement.append(r"A_MPI_File_errhandler_fn")

        pattern.append(r"^typedef A_MPI_Win_errhandler_function A_MPI_Win_errhandler_fn")
        pattern.append(r"^  int A_MPI_Address\(void \*location, A_MPI_Aint \*address\)")
        pattern.append(r"^  int A_MPI_Attr_delete\(A_MPI_Comm comm, int keyval\)")
        pattern.append(
            r"^  int A_MPI_Attr_get\(A_MPI_Comm comm, int keyval, void \*attribute_val, int"
            r" \*flag\)"
        )
        pattern.append(
            r"^  int A_MPI_Attr_put\(A_MPI_Comm comm, int keyval, void \*attribute_val\)"
        )
        pattern.append(r"A_MPI_Errhandler \*errhandler\)$")
        pattern.append(r"A_MPI_Errhandler errhandler\)$")
        pattern.append(r"^                                     int \*keyval, void \*extra_state\)")
        pattern.append(r"^  int A_MPI_Keyval_free\(int \*keyval\)")
        pattern.append(r"^  int A_MPI_Type_extent\(A_MPI_Datatype type, A_MPI_Aint \*extent\)")
        pattern.append(r"^  int A_MPI_Type_lb\(A_MPI_Datatype type, A_MPI_Aint \*lb\)")
        pattern.append(r"^                                   A_MPI_Datatype \*newtype\)")
        pattern.append(r"^  int A_MPI_Type_ub\(A_MPI_Datatype mtype, A_MPI_Aint \*ub\)")
        pattern.append(r"^  int A_PMPI_Address\(void \*location, A_MPI_Aint \*address\)")
        pattern.append(r"^  int A_PMPI_Attr_delete\(A_MPI_Comm comm, int keyval\)")
        pattern.append(
            r"^  int A_PMPI_Attr_get\(A_MPI_Comm comm, int keyval, void \*attribute_val, int"
            r" \*flag\)"
        )
        pattern.append(
            r"^  int A_PMPI_Attr_put\(A_MPI_Comm comm, int keyval, void \*attribute_val\)"
        )
        pattern.append(r"^                                      int \*keyval, void \*extra_state\)")
        pattern.append(r"^  int A_PMPI_Keyval_free\(int \*keyval\)")
        pattern.append(
            r"^                                      A_MPI_Datatype oldtype, A_MPI_Datatype"
            r" \*newtype\)"
        )
        pattern.append(r"^  int A_PMPI_Type_lb\(A_MPI_Datatype type, A_MPI_Aint \*lb\)")
        pattern.append(r"^                                    A_MPI_Datatype \*newtype\)")
        pattern.append(r"^  int A_PMPI_Type_ub\(A_MPI_Datatype mtype, A_MPI_Aint \*ub\)")
        pattern.append(r"int A_PMPI_Type_extent\(A_MPI_Datatype type, A_MPI_Aint \*extent\)$")
        pattern.append(r"A_MPI_Datatype oldtype, A_MPI_Datatype \*newtype\)$")

        replacement.append("typedef A_MPI_Win_errhandler_function A_MPI_Win_errhandler_fn;")
        replacement.append("  int A_MPI_Address(void *location, A_MPI_Aint *address);")
        replacement.append("  int A_MPI_Attr_delete(A_MPI_Comm comm, int keyval);")
        replacement.append(
            "  int A_MPI_Attr_get(A_MPI_Comm comm, int keyval, void *attribute_val, int *flag);"
        )
        replacement.append(
            "  int A_MPI_Attr_put(A_MPI_Comm comm, int keyval, void *attribute_val);"
        )
        replacement.append("A_MPI_Errhandler *errhandler);")
        replacement.append("A_MPI_Errhandler errhandler);")
        replacement.append("                                     int *keyval, void *extra_state);")
        replacement.append("  int A_MPI_Keyval_free(int *keyval);")
        replacement.append("  int A_MPI_Type_extent(A_MPI_Datatype type, A_MPI_Aint *extent);")
        replacement.append("  int A_MPI_Type_lb(A_MPI_Datatype type, A_MPI_Aint *lb);")
        replacement.append("                                   A_MPI_Datatype *newtype);")
        replacement.append("  int A_MPI_Type_ub(A_MPI_Datatype mtype, A_MPI_Aint *ub);")
        replacement.append("  int A_PMPI_Address(void *location, A_MPI_Aint *address);")
        replacement.append("  int A_PMPI_Attr_delete(A_MPI_Comm comm, int keyval);")
        replacement.append(
            "  int A_PMPI_Attr_get(A_MPI_Comm comm, int keyval, void *attribute_val, int *flag);"
        )
        replacement.append(
            "  int A_PMPI_Attr_put(A_MPI_Comm comm, int keyval, void *attribute_val);"
        )
        replacement.append("                                      int *keyval, void *extra_state);")
        replacement.append("  int A_PMPI_Keyval_free(int *keyval);")
        replacement.append(
            "                                      A_MPI_Datatype oldtype, A_MPI_Datatype"
            " *newtype);"
        )
        replacement.append("  int A_PMPI_Type_lb(A_MPI_Datatype type, A_MPI_Aint *lb);")
        replacement.append("                                    A_MPI_Datatype *newtype);")
        replacement.append("  int A_PMPI_Type_ub(A_MPI_Datatype mtype, A_MPI_Aint *ub);")
        replacement.append(r"int A_PMPI_Type_extent(A_MPI_Datatype type, A_MPI_Aint *extent);")
        replacement.append("A_MPI_Datatype oldtype, A_MPI_Datatype *newtype);")

        for _pattern, _replacement in zip(pattern, replacement):
            decalage += len(_replacement.split("\n")) - len(_pattern.split("\n"))
            text = re.sub(_pattern, _replacement, text, flags=re.MULTILINE)

        lines_to_delete = [
            "typedef A_MPI_File_errhandler_fn A_MPI_File_errhandler_fn",
            "struct ompi_file_t;",
            "typedef void (A_MPI_File_errhandler_fn)(struct ompi_file_t**, int *, ...);",
        ]
        text = delete_lines(lines_to_delete, text)
        _pattern_block = """












/* New datatypes from the MPI 2.2 standard */




"""
        _replacement_block = """"""
        text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)
        return text

    def _generate_app_mpih(self, gen_file):
        log.debug("Running _generate_app_mpih (HeaderGenerator)")
        with open(gen_file, "r") as _file:
            _content = _file.read()

        _new_content = self._common_generate_app_mpih(_content)
        with open(gen_file, "w") as _file:
            _file.write(_new_content)

    def _generate_run_mpioh(self, gen_file):
        log.debug("Running _generate_run_mpioh (HeaderGenerator)")
        with open(gen_file, "r") as _file:
            _content = _file.read()

        _new_content = self._replace_mpi_with_rmpi(_content)
        with open(gen_file, "w") as _file:
            _file.write(_new_content)

    def generate(self):
        log.debug("Running generate (HeaderGenerator)")
        self._generate_run_mpih(os.path.join(self.dir_output, self._run_mpi_header_file))
        self._generate_run_mpioh(os.path.join(self.dir_output, self._run_mpio_header_file))
        self._generate_app_mpih(os.path.join(self.dir_output, self._app_mpi_header_file))
        self._generate_wrapper_fh(os.path.join(self.dir_output, self._wrapper_f_header_file))

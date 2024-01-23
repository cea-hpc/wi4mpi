#!/usr/bin/env python3

import os
import shutil
import re
from logging import getLogger
from logging.config import fileConfig


COPYRIGHT_MPICH_MPIH = """
//############################# Wi4MPI License ###########################
//# Copyright or (C) or Copr. Commissariat a l'Energie Atomique          #
//#                                                                      #
//# IDDN.FR.001.210022.000.S.P.2014.000.10800                            #
//# This file is part of the Wi4MPI library.                             #
//#                                                                      #
//# SPDX-License-Identifier: BSD-3-Clause OR CeCILL-B                    #
//#                                                                      #
//########################################################################
/*  
 *  (C) 2001 by Argonne National Laboratory.
    
    				  MPICH2 COPYRIGHT
    
    The following is a notice of limited availability of the code, and disclaimer
    which must be included in the prologue of the code and in all source listings
    of the code.
    
    Copyright Notice
     + 2002 University of Chicago
    
    Permission is hereby granted to use, reproduce, prepare derivative works, and
    to redistribute to others.  This software was authored by:
    
    Mathematics and Computer Science Division
    Argonne National Laboratory, Argonne IL 60439
    
    (and)
    
    Department of Computer Science
    University of Illinois at Urbana-Champaign
    
    
    			      GOVERNMENT LICENSE
    
    Portions of this material resulted from work developed under a U.S.
    Government Contract and are subject to the following license: the Government
    is granted for itself and others acting on its behalf a paid-up, nonexclusive,
    irrevocable worldwide license in this computer software to reproduce, prepare
    derivative works, and perform publicly and display publicly.
    
    				  DISCLAIMER
    
    This computer code material was prepared, in part, as an account of work
    sponsored by an agency of the United States Government.  Neither the United
    States, nor the University of Chicago, nor any of their employees, makes any
    warranty express or implied, or assumes any legal liability or responsibility
    for the accuracy, completeness, or usefulness of any information, apparatus,
    product, or process disclosed, or represents that its use would not infringe
    privately owned rights.
    
 *      
 */
"""

COPYRIGHT_MPICH_MPIOH = """
//############################# Wi4MPI License ###########################
//# Copyright or (C) or Copr. Commissariat a l'Energie Atomique          #
//#                                                                      #
//# IDDN.FR.001.210022.000.S.P.2014.000.10800                            #
//# This file is part of the Wi4MPI library.                             #
//#                                                                      #
//# SPDX-License-Identifier: BSD-3-Clause OR CeCILL-B                    #
//#                                                                      #
//########################################################################
/* 
 *
 *   Copyright (C) 1997 University of Chicago. 
    
    				  MPICH2 COPYRIGHT
    
    The following is a notice of limited availability of the code, and disclaimer
    which must be included in the prologue of the code and in all source listings
    of the code.
    
    Copyright Notice
     + 2002 University of Chicago
    
    Permission is hereby granted to use, reproduce, prepare derivative works, and
    to redistribute to others.  This software was authored by:
    
    Mathematics and Computer Science Division
    Argonne National Laboratory, Argonne IL 60439
    
    (and)
    
    Department of Computer Science
    University of Illinois at Urbana-Champaign
    
    
    			      GOVERNMENT LICENSE
    
    Portions of this material resulted from work developed under a U.S.
    Government Contract and are subject to the following license: the Government
    is granted for itself and others acting on its behalf a paid-up, nonexclusive,
    irrevocable worldwide license in this computer software to reproduce, prepare
    derivative works, and perform publicly and display publicly.
    
    				  DISCLAIMER
    
    This computer code material was prepared, in part, as an account of work
    sponsored by an agency of the United States Government.  Neither the United
    States, nor the University of Chicago, nor any of their employees, makes any
    warranty express or implied, or assumes any legal liability or responsibility
    for the accuracy, completeness, or usefulness of any information, apparatus,
    product, or process disclosed, or represents that its use would not infringe
    privately owned rights.
    
 *   
 */
"""

fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)),"logging.conf"))
log = getLogger("header_logger")

# Absolute path of this script
wi4mpi_root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

def delete_lines(lines_to_delete, text):
    """
    Delete specified lines from the given text.

    Parameters:
    - lines_to_delete (int, str, list): Line numbers (int), line content (str), or a list
      of line numbers or contents to be deleted from the text.
    - text (str): The input text from which lines are to be deleted.

    Returns:
    str: The modified text after deleting the specified lines.

    Example:
    >>> original_text = "Line 1\nLine 2\nLine 3\nLine 4\n"
    >>> delete_lines([2, "Line 4"], original_text)
    'Line 1\nLine 3\n'
    """
    lines = text.split('\n')
    if isinstance(lines_to_delete, int) or isinstance(lines_to_delete, str):
        lines_to_delete = [lines_to_delete]
    if isinstance(lines_to_delete[0], int):
        for line_number_to_delete in sorted(lines_to_delete, reverse=True):
            if 1 <= line_number_to_delete <= len(lines):
                del lines[line_number_to_delete - 1]
    elif isinstance(lines_to_delete[0], str):
        for line in lines_to_delete:
            try:
                del lines[lines.index(line)]
            except:
                continue
    return '\n'.join(lines)

def delete_line_from_pattern(pattern, text):
    """
    Delete lines containing the specified pattern from the given text.

    Parameters:
    - pattern (str): The pattern to match for deleting lines.
    - text (str): The input text from which lines are to be deleted.

    Returns:
    str: The modified text after deleting lines containing the specified pattern.

    Example:
    >>> original_text = "Line 1\nLine with pattern ABC\nLine 3\n"
    >>> delete_line_from_pattern("ABC", original_text)
    'Line 1\nLine 3\n'
    """
    lines = text.split('\n')
    if isinstance(pattern, str):
        lines_to_delete = []
        for line in lines:
            if pattern in line:
                lines_to_delete.append(line)
        if lines_to_delete:
            text = delete_lines(lines_to_delete, text)
    return text

def insert_lines(lines_to_insert, line_number, text):
    """
    Inserts the specified lines at the given position in the text.
    
    Args:
        text (str): The original text.
        lines_to_insert (list): List of lines to insert.
        line_number (int): The line number where to insert the new lines.

    Returns:
        str: The modified text with the new lines inserted.
    """
    lines = text.split('\n')
    if 1 <= line_number <= len(lines):
        lines[line_number-1:line_number-1] = lines_to_insert
    return '\n'.join(lines)

def function_to_delete(text, function_to_delete):
    """
    Removes function prototypes containing the specified function name from the given text.

    Args:
        text (str): The original text.
        function_to_delete (str): The name of the function whose prototypes are to be removed.

    Returns:
        str: The modified text with function prototypes removed.
    """
    lines = text.split('\n')
  
    new_lines = []
    function_started = False
    function_ended = False
  
    for line in lines:
        if function_to_delete in line and "(" in line:
            function_started = True
            function_ended = False
        if function_started and line.strip() == ";":
            function_started = False
            function_ended = True
        if function_started:
            if ";" in line:
              function_ended = True
        if not function_started and not function_ended:
            new_lines.append(line)
        if function_ended:
            function_started = False
            function_ended = False
  
    return '\n'.join(new_lines)


class HeaderGenerator():

    _run_mpi_header_file = "run_mpi.h"
    _run_mpio_header_file = "run_mpio.h"
    _app_mpi_header_file = "app_mpi.h"
    _app_mpio_header_file = "app_mpio.h"
    _wrapper_f_header_file = "wrapper_f.h"
    dir_output = ""

    def _generate_wrapper_fh(self, gen_file):
        log.warning("The generation of wrapper_f.h have to be done locally.\n\tA MPC program has to be executed in order to catch MPI_MODE_XXX values.\n\tHave a look to generator/FORTRAN/MPI_XXX_generator/MPC/gen_MPC_vars.sh")

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
        text = re.sub(r'([ \t(*,)])MPI_', r'\1R_MPI_', text, flags=re.MULTILINE)
        text = re.sub(r'^MPI_', r'R_MPI_', text, flags=re.MULTILINE)

        # Replace MPIX with R_MPIX
        text = re.sub(r'([ \t(*,)])MPIX_', r'\1R_MPIX_', text, flags=re.MULTILINE)
        text = re.sub(r'^MPIX_', r'R_MPIX_', text, flags=re.MULTILINE)

        # Replace MPIO with R_MPIO
        text = re.sub(r'([ \t(*,)])MPIO_', r'\1R_MPIO_', text, flags=re.MULTILINE)
        text = re.sub(r'^MPIO_', r'R_MPIO_', text, flags=re.MULTILINE)

        # Replace PMPI with R_PMPI
        text = re.sub(r'([ \t(*,)])PMPI_', r'\1R_PMPI_', text, flags=re.MULTILINE)
        text = re.sub(r'^PMPI_', r'R_PMPI_', text, flags=re.MULTILINE)

        # Replace PMPIX with R_PMPIX
        text = re.sub(r'([ \t(*,)])PMPIX_', r'\1R_PMPIX_', text, flags=re.MULTILINE)
        text = re.sub(r'^PMPIX_', r'R_PMPIX_', text, flags=re.MULTILINE)

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
        """
        log.debug("Running _generate_run_mpih (HeaderGenerator).")
        try:
            with open(gen_file, "r") as _file:
                _content = _file.read()
                _new_content = self._replace_mpi_with_rmpi(_content)
            with open(gen_file, 'w') as _file:
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
      text = delete_lines(range(0,line_idx+1), text)

      # Suppression des lignes contenant #if et #endif
      lines_to_delete = []
      for line in text.split("\n"):
        if "#if" in line or "#endif" in line or "#else" in line:
          lines_to_delete.append(line)
      text = delete_lines(lines_to_delete, text)

      pattern = []
      replacement = []
      decalage = 0

      pattern.append(r'MPI_')
      replacement.append(r'A_MPI_')
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

      pattern.append(r"#define A_MPI_OP_NULL .*"            )
      pattern.append(r"#define A_MPI_ERRHANDLER_NULL .*"    )
      pattern.append(r"#define A_MPI_INFO_NULL .*"          )
      pattern.append(r"#define A_MPI_WIN_NULL .*"           )
      pattern.append(r"#define A_MPI_FILE_NULL .*"          )
      pattern.append(r"#define A_MPI_T_ENUM_NULL .*"        )
      pattern.append(r"#define A_MPI_INFO_ENV .*"           )
      pattern.append(r"#define A_MPI_STATUS_IGNORE .*"      )
      pattern.append(r"#define A_MPI_STATUSES_IGNORE .*"    )
      pattern.append(r"#define A_MPI_NULL_DELETE_FN .*"     )
      pattern.append(r"#define A_MPI_NULL_COPY_FN .*"       )
      pattern.append(r"#define A_MPI_TYPE_NULL_DELETE_FN .*")
      pattern.append(r"#define A_MPI_TYPE_NULL_COPY_FN .*"  )
      pattern.append(r"#define A_MPI_COMM_NULL_DELETE_FN .*")
      pattern.append(r"#define A_MPI_COMM_NULL_COPY_FN .*"  )
      pattern.append(r"#define A_MPI_WIN_NULL_DELETE_FN .*" )
      pattern.append(r"#define A_MPI_WIN_NULL_COPY_FN .*"   )
      replacement.append(r"#define A_MPI_OP_NULL 0x0"             )
      replacement.append(r"#define A_MPI_ERRHANDLER_NULL 0x0"     )
      replacement.append(r"#define A_MPI_INFO_NULL 0x0"           )
      replacement.append(r"#define A_MPI_WIN_NULL 0x0"            )
      replacement.append(r"#define A_MPI_FILE_NULL 0x0"           )
      replacement.append(r"#define A_MPI_T_ENUM_NULL 0x0"         )
      replacement.append(r"#define A_MPI_INFO_ENV 0x0 "           )
      replacement.append(r"#define A_MPI_STATUS_IGNORE 0x0"       )
      replacement.append(r"#define A_MPI_STATUSES_IGNORE 0x0"     )
      replacement.append(r"#define A_MPI_NULL_DELETE_FN  0x0"     )
      replacement.append(r"#define A_MPI_NULL_COPY_FN  0x0"       )
      replacement.append(r"#define A_MPI_TYPE_NULL_DELETE_FN  0x0")
      replacement.append(r"#define A_MPI_TYPE_NULL_COPY_FN  0x0"  )
      replacement.append(r"#define A_MPI_COMM_NULL_DELETE_FN  0x0")
      replacement.append(r"#define A_MPI_COMM_NULL_COPY_FN  0x0"  )
      replacement.append(r"#define A_MPI_WIN_NULL_DELETE_FN  0x0" )
      replacement.append(r"#define A_MPI_WIN_NULL_COPY_FN  0x0"   )
    
      pattern.append(r"A_MPI_COMM_WORLD OA_MPI_PREDEFINED_GLOBAL\( A_MPI_Comm, ompi_mpi_comm_world\)")
      replacement.append("A_MPI_COMM_WORLD 0x1")
      pattern.append(r"A_MPI_COMM_SELF OA_MPI_PREDEFINED_GLOBAL\(A_MPI_Comm, ompi_mpi_comm_self\)")
      replacement.append("A_MPI_COMM_SELF 0x2")
      pattern.append(r"#define A_MPI_GROUP_EMPTY OA_MPI_PREDEFINED_GLOBAL\(A_MPI_Group, ompi_mpi_group_empty\)")
      replacement.append("#define A_MPI_GROUP_EMPTY 0x1")
      pattern.append(r"A_MPI_MESSAGE_NO_PROC OA_MPI_PREDEFINED_GLOBAL\(A_MPI_Message, ompi_message_no_proc\)")
      replacement.append("A_MPI_MESSAGE_NO_PROC 0x1")
    
      for _pattern, _replacement in zip(pattern, replacement):
        decalage += len(_replacement.split('\n')) - len(_pattern.split('\n'))
        text = re.sub(_pattern, _replacement, text, flags=re.MULTILINE)
      text = insert_lines([
        r"#ifndef CCC_MPI",
        r"#define CCC_MPI",
        r"",
        r"#ifndef __MPI__COMPILE__",
        r"#define A_MPI_ MPI_",
        r"#define A_PMPI_ PMPI_",
        r"#endif",
        r"typedef unsigned long size_t;"
      ],
      1,
      text)
    
    
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
      for value in range(1,15):
        replacement.append(r"\1 "+f"{value}")
    
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
        replacement.append(r"\1 "+f"{value}")
      # /* New datatypes from the MPI 2.2 standard */
      pattern.append(r"^#define A_MPI_INT8_T .*")
      value = 54
      padding = 36
      replacement.append("#define A_MPI_INT8_T".ljust(padding)+f"{value}")
      pattern.append(r"^#define A_MPI_UINT8_T .*")
      value += 1
      replacement.append("#define A_MPI_UINT8_T".ljust(padding)+f"{value}")
      pattern.append(r"^#define A_MPI_INT16_T .*")
      value += 1
      replacement.append("#define A_MPI_INT16_T".ljust(padding)+f"{value}")
      pattern.append(r"^#define A_MPI_UINT16_T .*")
      value += 1
      replacement.append("#define A_MPI_UINT16_T".ljust(padding)+f"{value}")
      pattern.append(r"^#define A_MPI_INT32_T .*")
      value += 1
      replacement.append("#define A_MPI_INT32_T".ljust(padding)+f"{value}")
      pattern.append(r"^#define A_MPI_UINT32_T .*")
      value += 1
      replacement.append("#define A_MPI_UINT32_T".ljust(padding)+f"{value}")
      pattern.append(r"^#define A_MPI_INT64_T .*")
      value += 1
      replacement.append("#define A_MPI_INT64_T".ljust(padding)+f"{value}")
      pattern.append(r"^#define A_MPI_UINT64_T .*")
      value += 1
      replacement.append("#define A_MPI_UINT64_T".ljust(padding)+f"{value}")
      pattern.append(r"^#define A_MPI_AINT .*")
      value += 1
      replacement.append("#define A_MPI_AINT".ljust(padding)+f"{value}")
      pattern.append(r"^#define A_MPI_OFFSET .*")
      value += 1
      replacement.append("#define A_MPI_OFFSET".ljust(padding)+f"{value}")
      pattern.append(r"^#define A_MPI_C_BOOL .*")
      value += 1
      replacement.append("#define A_MPI_C_BOOL".ljust(padding)+f"{value}")
      pattern.append(r"^#define A_MPI_C_COMPLEX .*")
      value += 1
      replacement.append("#define A_MPI_C_COMPLEX".ljust(padding)+f"{value}")
      pattern.append(r"^#define A_MPI_C_FLOAT_COMPLEX .*")
      value += 1
      replacement.append("#define A_MPI_C_FLOAT_COMPLEX".ljust(padding)+f"{value}")
      pattern.append(r"^#define A_MPI_C_DOUBLE_COMPLEX .*")
      value += 1
      replacement.append("#define A_MPI_C_DOUBLE_COMPLEX".ljust(padding)+f"{value}")
      pattern.append(r"^#define A_MPI_C_LONG_DOUBLE_COMPLEX .*")
      value += 1
      replacement.append("#define A_MPI_C_LONG_DOUBLE_COMPLEX".ljust(padding)+f"{value}")
      pattern.append(r"^#define A_MPI_CXX_BOOL .*")
      value += 1
      replacement.append("#define A_MPI_CXX_BOOL".ljust(padding)+f"{value}")
      pattern.append(r"^#define A_MPI_CXX_FLOAT_COMPLEX .*")
      value += 1
      replacement.append("#define A_MPI_CXX_FLOAT_COMPLEX".ljust(padding)+f"{value}")
      pattern.append(r"^#define A_MPI_CXX_DOUBLE_COMPLEX .*")
      value += 1
      replacement.append("#define A_MPI_CXX_DOUBLE_COMPLEX".ljust(padding)+f"{value}")
      pattern.append(r"^#define A_MPI_CXX_LONG_DOUBLE_COMPLEX .*")
      value += 1
      padding += 2
      replacement.append("#define A_MPI_CXX_LONG_DOUBLE_COMPLEX".ljust(padding)+f"{value}")
      # /* New datatypes from the 3.0 standard */
      pattern.append(r"^#define A_MPI_COUNT .*")
      value += 1
      replacement.append(f"#define A_MPI_COUNT {value} ")
    
      pattern.append(r"(^#define A_MPI_ERRORS_ARE_FATAL) .*")
      value = 1
      replacement.append(r"\1 "+f"{value}")
      pattern.append(r"(^#define A_MPI_ERRORS_RETURN) .*")
      value += 1
      replacement.append(r"\1 "+f"{value} ")
    
      pattern.append(r"struct mca_base_pvar_session_t \*")
      replacement.append(r"")
    
      pattern.append(r"OA_MPI_C_A_MPI_DUP_FN\n"               )
      pattern.append(r"OA_MPI_C_A_MPI_TYPE_DUP_FN\n"          )
      pattern.append(r"OA_MPI_C_A_MPI_COMM_DUP_FN\n"          )
      pattern.append(r"OA_MPI_C_A_MPI_WIN_DUP_FN\n"           )
      replacement.append(r" 0x1\n"                                  )
      replacement.append(r" 0x1\n"                                  )
      replacement.append(r" 0x1\n"                                  )
      replacement.append(r" 0x1\n"                                  )
    
      for _pattern, _replacement in zip(pattern, replacement):
        decalage += len(_replacement.split('\n')) - len(_pattern.split('\n'))
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
      text = delete_line_from_pattern(r'/* Aggregate struct datatypes are not */', text)
      text = delete_line_from_pattern(r'/* Optional MPI2 datatypes, always declared and defined, but not "exported" as A_MPI_LOGICAL1 */', text)

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
      pattern.append(r"^  int A_MPI_Attr_get\(A_MPI_Comm comm, int keyval, void \*attribute_val, int \*flag\)")
      pattern.append(r"^  int A_MPI_Attr_put\(A_MPI_Comm comm, int keyval, void \*attribute_val\)")
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
      pattern.append(r"^  int A_PMPI_Attr_get\(A_MPI_Comm comm, int keyval, void \*attribute_val, int \*flag\)")
      pattern.append(r"^  int A_PMPI_Attr_put\(A_MPI_Comm comm, int keyval, void \*attribute_val\)")
      pattern.append(r"^                                      int \*keyval, void \*extra_state\)")
      pattern.append(r"^  int A_PMPI_Keyval_free\(int \*keyval\)")
      pattern.append(r"^                                      A_MPI_Datatype oldtype, A_MPI_Datatype \*newtype\)")
      pattern.append(r"^  int A_PMPI_Type_lb\(A_MPI_Datatype type, A_MPI_Aint \*lb\)")
      pattern.append(r"^                                    A_MPI_Datatype \*newtype\)")
      pattern.append(r"^  int A_PMPI_Type_ub\(A_MPI_Datatype mtype, A_MPI_Aint \*ub\)")
      pattern.append(r"int A_PMPI_Type_extent\(A_MPI_Datatype type, A_MPI_Aint \*extent\)$")
      pattern.append(r"A_MPI_Datatype oldtype, A_MPI_Datatype \*newtype\)$")
    
      replacement.append("typedef A_MPI_Win_errhandler_function A_MPI_Win_errhandler_fn;")
      replacement.append("  int A_MPI_Address(void *location, A_MPI_Aint *address);")
      replacement.append("  int A_MPI_Attr_delete(A_MPI_Comm comm, int keyval);")
      replacement.append("  int A_MPI_Attr_get(A_MPI_Comm comm, int keyval, void *attribute_val, int *flag);")
      replacement.append("  int A_MPI_Attr_put(A_MPI_Comm comm, int keyval, void *attribute_val);")
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
      replacement.append("  int A_PMPI_Attr_get(A_MPI_Comm comm, int keyval, void *attribute_val, int *flag);")
      replacement.append("  int A_PMPI_Attr_put(A_MPI_Comm comm, int keyval, void *attribute_val);")
      replacement.append("                                      int *keyval, void *extra_state);")
      replacement.append("  int A_PMPI_Keyval_free(int *keyval);")
      replacement.append("                                      A_MPI_Datatype oldtype, A_MPI_Datatype *newtype);")
      replacement.append("  int A_PMPI_Type_lb(A_MPI_Datatype type, A_MPI_Aint *lb);")
      replacement.append("                                    A_MPI_Datatype *newtype);")
      replacement.append("  int A_PMPI_Type_ub(A_MPI_Datatype mtype, A_MPI_Aint *ub);")
      replacement.append(r"int A_PMPI_Type_extent(A_MPI_Datatype type, A_MPI_Aint *extent);")
      replacement.append("A_MPI_Datatype oldtype, A_MPI_Datatype *newtype);")
    
      for _pattern, _replacement in zip(pattern, replacement):
        decalage += len(_replacement.split('\n')) - len(_pattern.split('\n'))
        text = re.sub(_pattern, _replacement, text, flags=re.MULTILINE)
    
      lines_to_delete = [
        "typedef A_MPI_File_errhandler_fn A_MPI_File_errhandler_fn",
        "struct ompi_file_t;",
        "typedef void (A_MPI_File_errhandler_fn)(struct ompi_file_t**, int *, ...);"
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
        with open(gen_file, 'w') as _file:
            _file.write(_new_content)
    
    def _generate_run_mpioh(self, gen_file):
        log.debug("Running _generate_run_mpioh (HeaderGenerator)")
        with open(gen_file, "r") as _file:
            _content = _file.read()

        _new_content = self._replace_mpi_with_rmpi(_content)
        with open(gen_file, 'w') as _file:
            _file.write(_new_content)

    def generate(self):
        log.debug("Running generate (HeaderGenerator)")
        self._generate_run_mpih(os.path.join(self.dir_output, self._run_mpi_header_file))
        self._generate_run_mpioh(os.path.join(self.dir_output, self._run_mpio_header_file))
        self._generate_app_mpih(os.path.join(self.dir_output, self._app_mpi_header_file))
        self._generate_wrapper_fh(os.path.join(self.dir_output, self._wrapper_f_header_file))


class MpcHeaderGenerator(HeaderGenerator):

    dir_output = ""
    dir_input = ""
    
    
    def __init__(self,
                 dir_input = "src/interface/header/scripts/mpc_headers",
                 dir_output = "src/interface/header/_MPC"
                 ):
        log.info("Generation of MPC headers in progress.")
        self.dir_input = dir_input 
        self.dir_output = dir_output
        os.makedirs(self.dir_output, exist_ok=True)

    def _generate_wrapper_fh(self, gen_file):
        super()._generate_wrapper_fh(gen_file)
        if not os.path.exists(os.path.join(self.dir_output, "wrapper_f.h")):
            log.warning("Using {}".format(os.path.join(self.dir_input, "wrapper_f.h")))
            shutil.copy2(os.path.join(self.dir_input, "wrapper_f.h"), self.dir_output)

    def _mpc_exceptions_run_mpih(self, text):
        log.debug("Running _mpc_exceptions_run_mpih")

        # Définir les lignes à insérer
        lines_to_insert = [
            "#define R_MPI_ERR_RMA_RANGE 74",
            "#define R_MPI_ERR_RMA_ATTACH 75",
            "#define R_MPI_ERR_RMA_SHARED 76",
        ]
        # Utiliser une expression régulière pour insérer les lignes avant "#define R_MPI_ERR_RMA_CONFLICT"
        pattern = r'(#define R_MPI_ERR_RMA_CONFLICT)'
        replacement = '\n'.join(lines_to_insert) + r'\n\1'
        text = re.sub(pattern, replacement, text)      

        # Add line at the end of the file
        text = re.sub(r'(\n+$)', r'\n#include "run_mpio.h"\n', text)

        # Ajout supplémentaires
        lines_to_insert = [
            "#define R_MPI_T_ERR_INVALID_NAME      73  /* Name doesn't match */",
            "#define R_MPI_T_ERR_INVALID           74  /* Generic error code for MPI_T added in MPI-3.1 */",
        ]
        # Utiliser une expression régulière pour insérer les lignes après "/** Initialization and Finalization */"
        pattern = r'(/\*\* Initialization and Finalization \*/)'
        # Effectuer la substitution en utilisant re.sub()
        replacement = r'\1\n' + '\n'.join(lines_to_insert)
        text = re.sub(pattern, replacement, text)

        # Expression régulière pour correspondre aux lignes à supprimer
        pattern = r'/\* Error handling \*/\nint R_MPI_File_create_errhandler\(R_MPI_File_errhandler_function \*, R_MPI_Errhandler \*\);\nint R_PMPI_File_create_errhandler\(R_MPI_File_errhandler_function \*file_errhandler_fn, R_MPI_Errhandler \*errhandler\);\nint R_MPI_File_call_errhandler\(void \* , int \);'
        # Effectuer la substitution pour supprimer les lignes
        text = re.sub(pattern, '', text)
        
        # Add lines at the end of the file
        lines_to_insert = [
            "#ifndef R_MPI_FILE_DEFINED",
            "typedef struct ADIOI_FileD *R_MPI_File;",
            "#endif",
            "/* Error handling */",
            "int R_MPI_File_create_errhandler(R_MPI_File_errhandler_function *, R_MPI_Errhandler *);",
            "int R_PMPI_File_create_errhandler(R_MPI_File_errhandler_function *file_errhandler_fn, R_MPI_Errhandler *errhandler);",
            "int R_MPI_File_call_errhandler(R_MPI_File fh , int );",
        ]
        replacement = r'\1\n' + '\n'.join(lines_to_insert)
        text = re.sub(r'(\n+$)', replacement, text)

        # Remove const
        pattern = []
        replacement = []
        pattern.append(r"typedef void \(R_MPI_File_errhandler_function\)\(void \*, int \*, ...\);")
        replacement.append(r"typedef void (R_MPI_File_errhandler_function)(void*, int *, ...);")
        pattern.append(r"int R_MPI_Info_set\( R_MPI_Info, const char \*, const char \* \);")
        replacement.append(r"int R_MPI_Info_set( R_MPI_Info, char *, char * );")
        pattern.append(r"int R_MPI_Info_delete\( R_MPI_Info , const char \* \);")
        pattern.append(r"int R_MPI_Info_get\(R_MPI_Info , const char \*, int , char \*, int \*\);")
        replacement.append(r"int R_MPI_Info_delete( R_MPI_Info , char * );")
        replacement.append(r"int R_MPI_Info_get(R_MPI_Info , char *, int , char *, int *);")
        pattern.append(r"int R_MPI_Win_set_name\(R_MPI_Win, const char \*\);")
        replacement.append(r"int R_MPI_Win_set_name(R_MPI_Win, char *);")
        pattern.append(r"int R_MPI_Win_detach\(R_MPI_Win, const void \*\);")
        replacement.append(r"int R_MPI_Win_detach(R_MPI_Win, void *);")
        pattern.append(r"int R_MPI_Get_accumulate\(const void \*, int, R_MPI_Datatype, void \*, int,")
        replacement.append(r"int R_MPI_Get_accumulate(void *, int, R_MPI_Datatype, void *, int,")
        pattern.append(r"int R_MPI_Fetch_and_op\(const void \*, void \*, R_MPI_Datatype, int, R_MPI_Aint, R_MPI_Op,")
        replacement.append(r"int R_MPI_Fetch_and_op(void *, void *, R_MPI_Datatype, int, R_MPI_Aint, R_MPI_Op,")
        pattern.append(r"int R_MPI_Compare_and_swap\(const void \*, const void \*, void \*, R_MPI_Datatype, int,")
        replacement.append(r"int R_MPI_Compare_and_swap(void *, void *, void *, R_MPI_Datatype, int,")
        pattern.append(r"int R_MPI_Rput\(const void \*, int, R_MPI_Datatype, int, R_MPI_Aint, int, R_MPI_Datatype,")
        replacement.append(r"int R_MPI_Rput(void *, int, R_MPI_Datatype, int, R_MPI_Aint, int, R_MPI_Datatype,")
        pattern.append(r"int R_MPI_Raccumulate\(const void \*, int, R_MPI_Datatype, int, R_MPI_Aint, int,")
        replacement.append(r"int R_MPI_Raccumulate(void *, int, R_MPI_Datatype, int, R_MPI_Aint, int,")
        pattern.append(r"int R_MPI_Rget_accumulate\(const void \*, int, R_MPI_Datatype, void \*, int,")
        replacement.append(r"int R_MPI_Rget_accumulate(void *, int, R_MPI_Datatype, void *, int,")
        pattern.append(r"int R_MPI_T_cvar_get_index\(const char \*name, int \*cvar_index\);")
        replacement.append(r"int R_MPI_T_cvar_get_index(char *name, int *cvar_index);")
        pattern.append(r"int R_MPI_T_cvar_write\(R_MPI_T_cvar_handle handle, const void \*buff\);")
        replacement.append(r"int R_MPI_T_cvar_write(R_MPI_T_cvar_handle handle, void *buff);")
        pattern.append(r"int R_MPI_T_pvar_get_index\(char \*name, int \*pvar_class, int \*pvar_index\);")
        replacement.append(r"int R_MPI_T_pvar_get_index(char *name, int var_class, int *pvar_index);")
        pattern.append(r"int R_MPI_Comm_connect\(const char \*, R_MPI_Info , int , R_MPI_Comm , R_MPI_Comm \*\);")
        replacement.append(r"int R_MPI_Comm_connect(char *, R_MPI_Info , int , R_MPI_Comm , R_MPI_Comm *);")
        pattern.append(r"int R_MPI_Lookup_name\(const char \*, R_MPI_Info , char \*\);")
        replacement.append(r"int R_MPI_Lookup_name(char *, R_MPI_Info , char *);")
        pattern.append(r"int R_MPI_Reduce_local\(const void \*, void \*, int, R_MPI_Datatype, R_MPI_Op\);")
        replacement.append(r"int R_MPI_Reduce_local(void *, void *, int, R_MPI_Datatype, R_MPI_Op);")
        pattern.append(r"int R_MPI_Dist_graph_create\(R_MPI_Comm , int , const int \[\],const int \[\], const int \[\],const int \[\],R_MPI_Info , int , R_MPI_Comm \*\);")
        pattern.append(r"int R_MPI_Dist_graph_create_adjacent\(R_MPI_Comm ,int , const int \[\],const int \[\],int , const int \[\],const int \[\],R_MPI_Info , int , R_MPI_Comm \*\);")
        replacement.append(r"int R_MPI_Dist_graph_create(R_MPI_Comm , int , int [], int [], int [],int [],R_MPI_Info , int , R_MPI_Comm *);")
        replacement.append(r"int R_MPI_Dist_graph_create_adjacent(R_MPI_Comm ,int , int [], int [],int , int [], int [],R_MPI_Info , int , R_MPI_Comm *);")
        pattern.append(r"^[^\S]{21}const void \*buff\);")
        replacement.append(r"                     void *buff);")

        for _pattern, _replacement in zip(pattern, replacement):
            log.debug(_pattern+" => "+_replacement)
            text = re.sub(_pattern, _replacement, text, flags=re.MULTILINE)

        return text

    def _generate_run_mpih(self, gen_file):
        super()._generate_run_mpih(gen_file)
        with open(gen_file, "r") as _file:
            _content = _file.read()

        _new_content = self._mpc_exceptions_run_mpih(_content)
        with open(gen_file, 'w') as _file:
            _file.write(_new_content)

    def _mpc_exceptions_app_mpih(self, text):
            log.debug("Running _mpc_exceptions_app_mpih")
            # Remplacer les valeurs manquantes par A_MPI_ERR_UNKNOWN
            pattern = r'(#define.*A_MPI_ERR_RMA_RANGE).*'
            text = re.sub(pattern, r'\1             74', text)
            pattern = r'(#define.*A_MPI_ERR_RMA_ATTACH).*'
            text = re.sub(pattern, r'\1            75', text)
            pattern = r'(#define.*A_MPI_ERR_RMA_SHARED).*'
            text = re.sub(pattern, r'\1            76', text)

            return text

    def _generate_app_mpih(self, gen_file):
        super()._generate_app_mpih(gen_file)
        with open(gen_file, "r") as _file:
            _content = _file.read()

        _new_content = self._mpc_exceptions_app_mpih(_content)
        with open(gen_file, 'w') as _file:
            _file.write(_new_content)

    def _mpc_exceptions_run_mpioh(self, text):
        log.debug("Running _mpc_exceptions_run_mpio")
        pattern = []
        replacement = []
        pattern.append(r"int R_MPI_File_open\(R_MPI_Comm comm, const char \*filename, int amode, R_MPI_Info info, R_MPI_File \*fh\);")
        replacement.append(r"int R_MPI_File_open(R_MPI_Comm comm, char *filename, int amode, R_MPI_Info info, R_MPI_File *fh);")
        pattern.append(r"int R_MPI_File_delete\(const char \*filename, R_MPI_Info info\);")
        replacement.append(r"int R_MPI_File_delete(char *filename, R_MPI_Info info);")
        pattern.append(r"                      const char \*datarep, R_MPI_Info info\);")
        replacement.append(r"                      char *datarep, R_MPI_Info info);")
        pattern.append(r"int R_MPI_File_write_at\(R_MPI_File fh, R_MPI_Offset offset, const void \* buf, int count,")
        replacement.append(r"int R_MPI_File_write_at(R_MPI_File fh, R_MPI_Offset offset, void * buf, int count,")
        pattern.append(r"int R_MPI_File_write_at_all\(R_MPI_File fh, R_MPI_Offset offset, const void \*buf, int count,")
        replacement.append(r"int R_MPI_File_write_at_all(R_MPI_File fh, R_MPI_Offset offset, void *buf, int count,")
        pattern.append(r"int R_MPI_File_iwrite_at\(R_MPI_File fh, R_MPI_Offset offset, const void \*buf, int count,")
        replacement.append(r"int R_MPI_File_iwrite_at(R_MPI_File fh, R_MPI_Offset offset, void *buf, int count,")
        pattern.append(r"int R_MPI_File_write\(R_MPI_File fh, const void \*buf, int count, R_MPI_Datatype datatype,")
        replacement.append(r"int R_MPI_File_write(R_MPI_File fh, void *buf, int count, R_MPI_Datatype datatype,")
        pattern.append(r"int R_MPI_File_write_all\(R_MPI_File fh, const void \*buf, int count, R_MPI_Datatype datatype,")
        replacement.append(r"int R_MPI_File_write_all(R_MPI_File fh, void *buf, int count, R_MPI_Datatype datatype,")
        pattern.append(r"int R_MPI_File_iwrite\(R_MPI_File fh, const void \*buf, int count, R_MPI_Datatype datatype,")
        replacement.append(r"int R_MPI_File_iwrite(R_MPI_File fh, void *buf, int count, R_MPI_Datatype datatype,")
        pattern.append(r"int R_MPI_File_write_shared\(R_MPI_File fh, const void \*buf, int count, R_MPI_Datatype datatype,")
        replacement.append(r"int R_MPI_File_write_shared(R_MPI_File fh, void *buf, int count, R_MPI_Datatype datatype,")
        pattern.append(r"int R_MPI_File_iwrite_shared\(R_MPI_File fh, const void \*buf, int count, R_MPI_Datatype datatype,")
        replacement.append(r"int R_MPI_File_iwrite_shared(R_MPI_File fh, void *buf, int count, R_MPI_Datatype datatype,")
        pattern.append(r"int R_MPI_File_write_ordered\(R_MPI_File fh, const void \*buf, int count, R_MPI_Datatype datatype,")
        replacement.append(r"int R_MPI_File_write_ordered(R_MPI_File fh, void *buf, int count, R_MPI_Datatype datatype,")
        pattern.append(r"int R_MPI_File_write_at_all_begin\(R_MPI_File fh, R_MPI_Offset offset, const void \*buf, int count,")
        replacement.append(r"int R_MPI_File_write_at_all_begin(R_MPI_File fh, R_MPI_Offset offset, void *buf, int count,")
        pattern.append(r"int R_MPI_File_write_at_all_end\(R_MPI_File fh, const void \*buf, R_MPI_Status \*status\);")
        replacement.append(r"int R_MPI_File_write_at_all_end(R_MPI_File fh, void *buf, R_MPI_Status *status);")
        pattern.append(r"int R_MPI_File_write_all_begin\(R_MPI_File fh, const void \*buf, int count, R_MPI_Datatype datatype\)")
        pattern.append(r"int R_MPI_File_write_all_end\(R_MPI_File fh, const void \*buf, R_MPI_Status \*status\);")
        replacement.append(r"int R_MPI_File_write_all_begin(R_MPI_File fh, void *buf, int count, R_MPI_Datatype datatype)")
        replacement.append(r"int R_MPI_File_write_all_end(R_MPI_File fh, void *buf, R_MPI_Status *status);")
        pattern.append(r"int R_MPI_File_write_ordered_begin\(R_MPI_File fh, const void \*buf, int count, R_MPI_Datatype datatype\)")
        pattern.append(r"int R_MPI_File_write_ordered_end\(R_MPI_File fh, const void \*buf, R_MPI_Status \*status\);")
        replacement.append(r"int R_MPI_File_write_ordered_begin(R_MPI_File fh, void *buf, int count, R_MPI_Datatype datatype)")
        replacement.append(r"int R_MPI_File_write_ordered_end(R_MPI_File fh, void *buf, R_MPI_Status *status);")
        pattern.append(r"int R_MPI_Register_datarep\(const char \*datarep, R_MPI_Datarep_conversion_function \*read_conversion_fn,")
        replacement.append(r"int R_MPI_Register_datarep(char *datarep, R_MPI_Datarep_conversion_function *read_conversion_fn,")
        pattern.append(r"int R_MPI_File_iwrite_at_all\(R_MPI_File fh, R_MPI_Offset offset, const void \*buf, int count,")
        replacement.append(r"int R_MPI_File_iwrite_at_all(R_MPI_File fh, R_MPI_Offset offset, void *buf, int count,")
        pattern.append(r"int R_MPI_File_iwrite_all\(R_MPI_File fh, const void \*buf, int count, R_MPI_Datatype datatype,")
        replacement.append(r"int R_MPI_File_iwrite_all(R_MPI_File fh, void *buf, int count, R_MPI_Datatype datatype,")

        for _pattern, _replacement in zip(pattern, replacement):
            log.debug(_pattern+" => "+_replacement)
            text = re.sub(_pattern, _replacement, text, flags=re.MULTILINE)

        return text

    def _generate_run_mpioh(self, gen_file):
        super()._generate_run_mpioh(gen_file)
        with open(gen_file, "r") as _file:
            _content = _file.read()

        _new_content = self._mpc_exceptions_run_mpioh(_content)
        with open(gen_file, 'w') as _file:
            _file.write(_new_content)

    def generate(self):      
        shutil.copy2(os.path.join(self.dir_input, "ompi-1.8.8_mpi.h"), os.path.join(self.dir_output, self._app_mpi_header_file))
        shutil.copy2(os.path.join(self.dir_input, "mpc_mpi.h"), os.path.join(self.dir_output, self._run_mpi_header_file))
        shutil.copy2(os.path.join(self.dir_input, "mpio.h"), os.path.join(self.dir_output, self._run_mpio_header_file))
        shutil.copy2(os.path.join(self.dir_input, "mpcmp.h"), self.dir_output)
        shutil.copy2(os.path.join(self.dir_input, "sctk_types.h"), self.dir_output)
        super().generate()
        log.debug("MPC header has been generated.")


class IntelHeaderGenerator(HeaderGenerator):

    dir_output = ""
    dir_input = ""
    
    def __init__(self,
                 dir_input = "src/interface/header/scripts/mpc_headers",
                 dir_output = "src/interface/header/_INTEL_gen"
                 ):
        log.info("Generation of INTEL headers in progress.")
        self.dir_input = dir_input 
        self.dir_output = dir_output
        os.makedirs(self.dir_output, exist_ok=True)

    def _generate_wrapper_fh(self, gen_file):
        log.debug("Running _generate_wrapper_fh (IntelHeaderGenerator).")
        super()._generate_wrapper_fh(gen_file)
        if not os.path.exists(os.path.join(self.dir_output, "wrapper_f.h")):
            log.warning("Using {}".format(os.path.join(self.dir_input, "wrapper_f.h")))
            shutil.copy2(os.path.join(self.dir_input, "wrapper_f.h"), self.dir_output)

    def _mpich_exceptions_run_mpih(self, text):
        log.debug("Running _mpich_exceptions_run_mpih (IntelHeaderGenerator).")
        text = re.sub(r"const ", "", text, flags=re.MULTILINE)
        _pattern_block = """
/*  
 *  (C) 2001 by Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */
"""
        _replacement_block = COPYRIGHT_MPICH_MPIH
        text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)

        _pattern_block = """
/* user include file for MPI programs */
"""
        _replacement_block = """
/* user include file for MPI programs */
#if !defined(_WIN32) && !defined(_WIN64)  /* Linux only */
#	include <stdint.h> /* for __WORDSIZE definition */
#   ifdef __WORDSIZE
#	    if __WORDSIZE != 8*8 /* 32 or 64 */
#		    error A wrong version of mpi.h file was included. Check include path.
#	    endif
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

        text = re.sub(r"#define R_MPI_BSEND_OVERHEAD.*", "#define R_MPI_BSEND_OVERHEAD 95", text, flags=re.MULTILINE)

        lines_to_delete = [
            "extern int * R_MPI_UNWEIGHTED;",
            "extern int * R_MPI_WEIGHTS_EMPTY;"
        ]
        text = delete_lines(lines_to_delete, text)     
        text = re.sub(r"(#define R_MPI_DUP_FN.*)", r"//\1", text, flags=re.MULTILINE)
        text = re.sub(r'([ \t$])MPI_', r'\1R_MPI_', text, flags=re.MULTILINE)
        text = re.sub(r"HAVE_MPI", "HAVE_R_MPI", text, re.MULTILINE)
        text = re.sub(r"BIND_MPI", "BIND_R_MPI", text, re.MULTILINE)
        text = re.sub(r"BIND_MPI", "BIND_R_MPI", text, re.MULTILINE)
        text = re.sub(r"R_MPIX", "MPIX", text, re.MULTILINE)
        text = re.sub(r"F08_MPI", "F08_R_MPI", text, flags=re.MULTILINE)

        _pattern_block = """
/* See 4.12.5 for R_MPI_F_STATUS(ES)_IGNORE */
#define MPIU_DLL_SPEC
extern MPIU_DLL_SPEC R_MPI_Fint * R_MPI_F_STATUS_IGNORE;
extern MPIU_DLL_SPEC R_MPI_Fint * R_MPI_F_STATUSES_IGNORE;
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

        text = re.sub(r"(#define MPICH_ERR_LAST_CLASS) [0-9][0-9](.*)", r"\1 74\2", text, re.MULTILINE)
        text = re.sub(r"R_MPIX", "MPIX", text, re.MULTILINE)
        text = re.sub(r"R_PMPIX_Comm", "PMPIX_Comm", text, re.MULTILINE)
        text = re.sub(r"R_MPIX_Grequest", "MPIX_Grequest", text)
        text = re.sub(r"R_MPIX_Mutex", "MPIX_Mutex", text)
        text = re.sub(r"R_PMPIX_Grequest", "PMPIX_Grequest", text)       
        text = re.sub(r"R_PMPIX_Mutex", "PMPIX_Mutex", text)

        return text

    def _intel_generate_run_mpih(self, gen_file):
        log.debug("Running _generate_run_mpih (IntelHeaderGenerator).")
        super()._generate_run_mpih(gen_file)
        with open(gen_file, "r") as _file:
            _content = _file.read()

        _new_content = self._mpich_exceptions_run_mpih(_content)
        with open(gen_file, 'w') as _file:
            _file.write(_new_content)

    def _generate_run_mpih(self, gen_file):
        self._intel_generate_run_mpih(gen_file)

    def _mpich_exceptions_run_mpioh(self, text):
        log.debug("Running _mpich_exceptions_run_mpioh (IntelHeaderGenerator).")
        _pattern_block = """
/* 
 *
 *   Copyright (C) 1997 University of Chicago. 
 *   See COPYRIGHT notice in top-level directory.
 */
"""
        _replacement_block = COPYRIGHT_MPICH_MPIOH
        text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)
        
        text = re.sub(r"const", "", text)
        text = re.sub(r"R_MPIO", "MPIO", text)
        text = re.sub(r"([^RN])_MPI", r"\1_R_MPI", text)

        return text

    def _generate_run_mpioh(self, gen_file):
        log.debug("Running _generate_run_mpioh (IntelHeaderGenerator).")
        super()._generate_run_mpioh(gen_file)
        with open(gen_file, "r") as _file:
            _content = _file.read()

        _new_content = self._mpich_exceptions_run_mpioh(_content)
        with open(gen_file, 'w') as _file:
            _file.write(_new_content)

    def generate(self):
        shutil.copy2(
            os.path.join(self.dir_input, "mpich-3.1.2_mpi.h"),
            os.path.join(self.dir_output, self._run_mpi_header_file)
            )
        shutil.copy2(
            os.path.join(self.dir_input, "ompi-1.8.8_mpi.h"),
            os.path.join(self.dir_output, self._app_mpi_header_file)
            )
        shutil.copy2(
            os.path.join(self.dir_input, "mpich-3.1.2_mpio.h"),
            os.path.join(self.dir_output, self._run_mpio_header_file)
            )
        super().generate()
        log.debug("INTEL header has been generated.")


class OmpiHeaderGenerator(HeaderGenerator):

    def __init__(self,
                 dir_input = "src/interface/header/scripts/ompi_headers",
                 dir_output = "src/interface/header/_OMPI_test"
                 ):
        log.info("Generation of OMPI headers in progress.")
        self.dir_input = dir_input 
        self.dir_output = dir_output
        os.makedirs(self.dir_output, exist_ok=True)

    def _generate_wrapper_fh(self, gen_file):
        super()._generate_wrapper_fh(gen_file)
        if not os.path.exists(os.path.join(self.dir_output, "wrapper_f.h")):
            log.warning("Using {}".format(os.path.join(self.dir_input, "wrapper_f.h")))
            shutil.copy2(os.path.join(self.dir_input, "wrapper_f.h"), self.dir_output)

    def _replace_mpi_with_rmpi(self, text: str) -> str:
        pattern = []
        replacement = []
        decalage = 0
        
        pattern.append(r'MPI_')
        replacement.append(r'R_MPI_')
        pattern.append(r'OR_MPI_')
        replacement.append(r'OMPI_')
        pattern.append(r'PR_MPI_')
        replacement.append(r'R_PMPI_')
        pattern.append(r'#define OMPI_OFFSET_DATATYPE R_MPI_LONG_LONG')
        replacement.append(r'#define R_OMPI_OFFSET_DATATYPE R_MPI_LONG_LONG')
        pattern.append(r'#    include "mpi_portable_platform.h"')
        replacement.append(r'//#    include "mpi_portable_platform.h"')
        pattern.append(r'MPIO')
        replacement.append(r'R_MPIO')
        pattern.append(r'ompi_status_public_t')
        replacement.append(r'r_ompi_status_public_t')
        pattern.append(r'#define R_MPI_NULL_DELETE_FN OMPI_C_R_MPI_NULL_DELETE_FN')
        replacement.append(r'#define R_MPI_NULL_DELETE_FN (*ccc_OMPI_C_MPI_NULL_DELETE_FN)')
        pattern.append(r'#define R_MPI_NULL_COPY_FN OMPI_C_R_MPI_NULL_COPY_FN')
        replacement.append(r'#define R_MPI_NULL_COPY_FN (*ccc_OMPI_C_MPI_NULL_COPY_FN)')
        pattern.append(r'#define R_MPI_DUP_FN OMPI_C_R_MPI_DUP_FN')
        replacement.append(r'#define R_MPI_DUP_FN (*ccc_OMPI_C_MPI_DUP_FN)')
        if self.__class__.__name__ != "OmpiOmpiHeaderGenerator":
            pattern.append(r'^OMPI_DECLSPEC extern struct ompi_predefined_.*ompi')
            replacement.append(r'ccc_linkage void *ccc_ompi')
            pattern.append(r'__mpi_interface_deprecated__\("R_MPI_LB is deprecated in MPI-2.0"\);')
            replacement.append(r';')
            pattern.append(r'__mpi_interface_deprecated__\("R_MPI_UB is deprecated in MPI-2.0"\);')
            replacement.append(r';')
        pattern.append(r'const ')
        replacement.append(r'')
        pattern.append(r'#define OPAL_BUILD_PLATFORM_COMPILER_FAMILYID .*')
        replacement.append(r'#define OPAL_BUILD_PLATFORM_COMPILER_FAMILYID 2')
        pattern.append(r'#define OPAL_BUILD_PLATFORM_COMPILER_VERSION .*')
        replacement.append(r'#define OPAL_BUILD_PLATFORM_COMPILER_VERSION 1474738278')
        pattern.append(r'#define OPAL_HAVE_ATTRIBUTE_DEPRECATED_ARGUMENT .*')
        replacement.append(r'#define OPAL_HAVE_ATTRIBUTE_DEPRECATED_ARGUMENT 0')
        pattern.append(r'#define OPAL_MAX_OBJECT_NAME 64')
        replacement.append(r'//#define OPAL_MAX_OBJECT_NAME 64')
        pattern.append(r'#define OPAL_MAX_PROCESSOR_NAME 256')
        replacement.append(r'//#define OPAL_MAX_PROCESSOR_NAME 256')
        pattern.append(r'#define R_MPI_COMM_DUP_FN OMPI_C_MPI_COMM_DUP_FN')
        replacement.append(r'#define R_MPI_COMM_DUP_FN (*ccc_OMPI_C_MPI_COMM_DUP_FN)')
        pattern.append(r'#define R_MPI_TYPE_NULL_DELETE_FN OMPI_C_R_MPI_TYPE_NULL_DELETE_FN')
        replacement.append(r'#define R_MPI_TYPE_NULL_DELETE_FN OMPI_C_MPI_TYPE_NULL_DELETE_FN')
        pattern.append(r'#define R_MPI_TYPE_NULL_COPY_FN OMPI_C_R_MPI_TYPE_NULL_COPY_FN')
        replacement.append(r'#define R_MPI_TYPE_NULL_COPY_FN OMPI_C_MPI_TYPE_NULL_COPY_FN')
        pattern.append(r'#define R_MPI_TYPE_DUP_FN OMPI_C_R_MPI_TYPE_DUP_FN')
        replacement.append(r'#define R_MPI_TYPE_DUP_FN OMPI_C_MPI_TYPE_DUP_FN')
        pattern.append(r'#define R_MPI_COMM_NULL_DELETE_FN OMPI_C_R_MPI_COMM_NULL_DELETE_FN')
        replacement.append(r'#define R_MPI_COMM_NULL_DELETE_FN OMPI_C_MPI_COMM_NULL_DELETE_FN')
        pattern.append(r'#define R_MPI_COMM_NULL_COPY_FN OMPI_C_R_MPI_COMM_NULL_COPY_FN')
        replacement.append(r'#define R_MPI_COMM_NULL_COPY_FN OMPI_C_MPI_COMM_NULL_COPY_FN')
        pattern.append(r'#define R_MPI_COMM_DUP_FN OMPI_C_R_MPI_COMM_DUP_FN')
        replacement.append(r'#define R_MPI_COMM_DUP_FN (*ccc_OMPI_C_MPI_COMM_DUP_FN)')
        pattern.append(r'#define R_MPI_WIN_NULL_DELETE_FN OMPI_C_R_MPI_WIN_NULL_DELETE_FN')
        replacement.append(r'#define R_MPI_WIN_NULL_DELETE_FN OMPI_C_MPI_WIN_NULL_DELETE_FN')
        pattern.append(r'#define R_MPI_WIN_NULL_COPY_FN OMPI_C_R_MPI_WIN_NULL_COPY_FN')
        replacement.append(r'#define R_MPI_WIN_NULL_COPY_FN OMPI_C_MPI_WIN_NULL_COPY_FN')
        pattern.append(r'#define R_MPI_WIN_DUP_FN OMPI_C_R_MPI_WIN_DUP_FN')
        replacement.append(r'#define R_MPI_WIN_DUP_FN OMPI_C_MPI_WIN_DUP_FN')

        for _pattern, _replacement in zip(pattern, replacement):
            decalage += len(_replacement.split('\n')) - len(_pattern.split('\n'))
            log.debug(_pattern+" => "+_replacement)
            text = re.sub(_pattern, _replacement, text, flags=re.MULTILINE)
        
        _pattern = """
#if !OMPI_BUILDING
#define OMPI_PREDEFINED_GLOBAL(type, global) ((type) ((void *) &(global)))
#else
#define OMPI_PREDEFINED_GLOBAL(type, global) ((type) &(global))
#endif
"""
        _replacement = """
#ifdef OMPI_PREDEFINED_GLOBAL
#undef OMPI_PREDEFINED_GLOBAL
#endif
#if !OMPI_BUILDING
#define OMPI_PREDEFINED_GLOBAL(type, global) ((type) ((void *) (ccc_##global)))
#else
#define OMPI_PREDEFINED_GLOBAL(type, global) ((type) &(global))
#endif
#if OMPI_LOAD_SYM
#define OMPI_PREDEFINED_GLOBAL(type, global) global
#endif
"""
        text = re.sub(re.escape(_pattern), _replacement, text, flags=re.DOTALL)
        decalage = len(_replacement.split('\n')) - len(_pattern.split('\n'))

        if self.__class__.__name__ != "OmpiOmpiHeaderGenerator":
            lines_to_insert = [
                r'int (*ccc_OMPI_C_MPI_NULL_DELETE_FN)( R_MPI_Comm comm, int comm_keyval,',
                r'                                           void* attribute_val_out,',
                r'                                           void* extra_state );',
                r'int (*ccc_OMPI_C_MPI_DUP_FN)( R_MPI_Comm comm, int comm_keyval,',
                r'                                   void* extra_state,',
                r'                                   void* attribute_val_in,',
                r'                                   void* attribute_val_out,',
                r'                                   int* flag );',
                r'int (*ccc_OMPI_C_MPI_NULL_COPY_FN)( R_MPI_Comm comm, int comm_keyval,',
                r'                                         void* extra_state,',
                r'                                         void* attribute_val_in,',
                r'                                         void* attribute_val_out,',
                r'                                         int* flag );',
                r'int (*ccc_OMPI_C_MPI_COMM_DUP_FN)( R_MPI_Comm comm, int comm_keyval,',
                r'                                        void* extra_state,',
                r'                                        void* attribute_val_in,',
                r'                                        void* attribute_val_out,',
                r'                                        int* flag );',
                r''
            ]
            text = insert_lines(lines_to_insert, 875 + decalage, text)
            decalage += len(lines_to_insert)
            lines_to_insert = [
                r'#if !allocate_global',
                r'#define ccc_linkage extern',
                r'#else',
                r'#define ccc_linkage',
                r'#endif'
            ]
            text = insert_lines(lines_to_insert, 883 + decalage, text)
            decalage += len(lines_to_insert)

        _pattern_block = """
#define R_MPI_T_ERR_INVALID_NAME        71
"""
        _replacement_block = """
#define R_MPI_T_ERR_INVALID_NAME        71
#define R_MPI_T_ERR_INVALID_NAME      73  /* Name doesn't match */
#define R_MPI_T_ERR_INVALID           74  /* Generic error code for MPI_T added in MPI-3.1 */
"""
        text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)
        
        if self.__class__.__name__ != "OmpiOmpiHeaderGenerator":
            text = delete_lines([
            r'OMPI_DECLSPEC extern R_MPI_Fint *R_MPI_F_STATUS_IGNORE;',
            r'OMPI_DECLSPEC extern R_MPI_Fint *R_MPI_F_STATUSES_IGNORE;'
            ]
            , text)
            text = function_to_delete(text, 'OMPI_DECLSPEC int OMPI_C_R_MPI_TYPE_NULL_DELETE_FN')
            text = function_to_delete(text, 'OMPI_DECLSPEC int OMPI_C_R_MPI_TYPE_NULL_COPY_FN')
            text = function_to_delete(text, 'OMPI_DECLSPEC int OMPI_C_R_MPI_TYPE_DUP_FN')
            text = function_to_delete(text, 'OMPI_DECLSPEC int OMPI_C_R_MPI_COMM_NULL_DELETE_FN')
            text = function_to_delete(text, 'OMPI_DECLSPEC int OMPI_C_R_MPI_COMM_NULL_COPY_FN')
            text = function_to_delete(text, 'OMPI_DECLSPEC int OMPI_C_R_MPI_COMM_DUP_FN')
            text = function_to_delete(text, 'OMPI_DECLSPEC int OMPI_C_R_MPI_NULL_DELETE_FN')
            text = function_to_delete(text, 'OMPI_DECLSPEC int OMPI_C_R_MPI_NULL_COPY_FN')
            text = function_to_delete(text, 'OMPI_DECLSPEC int OMPI_C_R_MPI_DUP_FN')
            text = function_to_delete(text, 'OMPI_DECLSPEC int OMPI_C_R_MPI_WIN_NULL_DELETE_FN')
            text = function_to_delete(text, 'OMPI_DECLSPEC int OMPI_C_R_MPI_WIN_NULL_COPY_FN')
            text = function_to_delete(text, 'OMPI_DECLSPEC int OMPI_C_R_MPI_WIN_DUP_FN')

        return text

    def _generate_run_mpioh(self, gen_file):
        pass

    def generate(self):
        shutil.copy2(os.path.join(self.dir_input, "ompi-1.8.8_mpi.h"), os.path.join(self.dir_output, self._run_mpi_header_file))
        shutil.copy2(os.path.join(self.dir_input, "ompi-1.8.8_mpi.h"), os.path.join(self.dir_output, self._app_mpi_header_file))
        super().generate()
        log.debug("OMPI header has been generated.")

class MpichHeaderGenerator(IntelHeaderGenerator):
    def __init__(self,
                dir_input = "src/interface/header/scripts/mpich_headers",
                dir_output = "src/interface/header/_MPICH_test"
                ):
        log.info("Generation of MPICH headers in progress.")
        self.dir_input = dir_input 
        self.dir_output = dir_output
        os.makedirs(self.dir_output, exist_ok=True)


#----------------------- GROUPE A -------------------------
class IntelIntelHeaderGenerator(IntelHeaderGenerator):

    def __init__(self,
                 dir_input = "src/preload/header/scripts/intel_intel_headers",
                 dir_output = "src/preload/header/_INTEL_INTEL_gen"
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
        pattern.append(r'MPIR_Win_flavor')
        replacement.append(r'R_MPIR_Win_flavor')
        pattern.append(r'MPIR_Win_model')
        replacement.append(r'R_MPIR_Win_model')
        pattern.append(r'MPIR_Topo_type')
        replacement.append(r'R_MPIR_Topo_type')
        pattern.append(r'MPIR_ERRORS_THROW_EXCEPTIONS')
        replacement.append(r'R_MPIR_ERRORS_THROW_EXCEPTIONS')
        pattern.append(r'MPIR_Combiner_enum')
        replacement.append(r'R_MPIR_Combiner_enum')
        pattern.append(r'MPIR_T_verbosity_t')
        replacement.append(r'R_MPIR_T_verbosity_t')
        pattern.append(r'MPIX_T_VERBOSITY_INVALID')
        replacement.append(r'R_MPIX_T_VERBOSITY_INVALID')
        pattern.append(r'MPIR_T_bind_t')
        replacement.append(r'R_MPIR_T_bind_t')
        pattern.append(r'MPIR_T_scope_t')
        replacement.append(r'R_MPIR_T_scope_t')
        pattern.append(r'MPIX_T_SCOPE_INVALID')
        replacement.append(r'R_MPIX_T_SCOPE_INVALID')
        pattern.append(r'MPIR_T_pvar_class_t')
        replacement.append(r'R_MPIR_T_pvar_class_t')
        pattern.append(r'MPIX_T_PVAR_CLASS_INVALID')
        replacement.append(r'R_MPIX_T_PVAR_CLASS_INVALID')
        pattern.append(r'MPIR_T_PVAR_CLASS_FIRST')
        replacement.append(r'R_MPIR_T_PVAR_CLASS_FIRST')
        pattern.append(r'MPIR_T_PVAR_CLASS_LAST')
        replacement.append(r'R_MPIR_T_PVAR_CLASS_LAST')
        pattern.append(r'MPIR_T_PVAR_CLASS_NUMBER')
        replacement.append(r'R_MPIR_T_PVAR_CLASS_NUMBER')
        pattern.append(r'MPIX_Grequest_poll_function')
        replacement.append(r'R_MPIX_Grequest_poll_function')
        pattern.append(r'MPIX_Grequest_wait_function')
        replacement.append(r'R_MPIX_Grequest_wait_function')
        pattern.append(r' MPIX_Grequest_class_create')
        # L'espace est nécessaire pour ne pas modifier PMPIX_Grequest_.*
        replacement.append(r' R_MPIX_Grequest_class_create')
        pattern.append(r' MPIX_Grequest_class_allocate')
        replacement.append(r' R_MPIX_Grequest_class_allocate')
        pattern.append(r' MPIX_Grequest_start')
        replacement.append(r' R_MPIX_Grequest_start')
        #
        pattern.append(r'PMPIX_Grequest_class_create')
        replacement.append(r'R_PMPIX_Grequest_class_create')
        pattern.append(r'PMPIX_Grequest_class_allocate')
        replacement.append(r'R_PMPIX_Grequest_class_allocate')
        pattern.append(r'PMPIX_Grequest_start')
        replacement.append(r'R_PMPIX_Grequest_start')
        pattern.append(r'PMPIX_Mutex_create')
        replacement.append(r'R_PMPIX_Mutex_create')
        pattern.append(r'PMPIX_Mutex_free')
        replacement.append(r'R_PMPIX_Mutex_free')
        pattern.append(r'PMPIX_Mutex_lock')
        replacement.append(r'R_PMPIX_Mutex_lock')
        pattern.append(r'PMPIX_Mutex_unlock')
        replacement.append(r'R_PMPIX_Mutex_unlock')
        # Ligne modifiée durant la génération des header de l'interface
        pattern.append(r'//(#define R_MPI_DUP_FN.*)')
        replacement.append(r'\1')
        for _pattern, _replacement in zip(pattern, replacement):
            decalage += len(_replacement.split('\n')) - len(_pattern.split('\n'))
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
        with open(gen_file, 'w') as _file:
            _file.write(_new_content)

    def _common_generate_app_mpih(self, text):
        log.debug("Running _common_generate_app_mpih (IntelIntelHeaderGenerator).")
        pattern = []
        replacement = []
        decalage = 0

        pattern.append(r'([ ()*_$\t])R_')
        replacement.append(r'\1A_')
        pattern.append(r'MPIX_T_BIND_INVALID')
        replacement.append(r'A_MPIX_T_BIND_INVALID')
        pattern.append(r'A_MPIX_Grequest_')
        replacement.append(r'MPIX_Grequest_')
        pattern.append(r'mpich_')
        replacement.append(r'a_mpich_')
        pattern.append(r'\( void')
        replacement.append(r'(void')
        pattern.append(r'A_PMPIX_')
        replacement.append(r'PMPIX_')
        pattern.append(r'#include "run_mpio.h"')
        replacement.append(r'#include "app_mpio.h"')

        for _pattern, _replacement in zip(pattern, replacement):
            decalage += len(_replacement.split('\n')) - len(_pattern.split('\n'))
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
        log.debug("Running _generate_app_mpih (IntelIntelHeaderGenerator). File: {}.".format(gen_file))
        self._generate_run_mpih(gen_file)
        with open(gen_file, "r") as _file:
            _content = _file.read()

        _new_content = self._common_generate_app_mpih(_content)
        with open(gen_file, 'w') as _file:
            _file.write(_new_content)

    def _common_generate_app_mpioh(self, text):
        log.debug("Running _common_generate_app_mpioh (IntelIntelHeaderGenerator).")
        pattern = []
        replacement = []
        decalage = 0      

        pattern.append(r'([ ()*_$\t])R_')
        replacement.append(r'\1A_')
        pattern.append(r'MPIO_INCLUDE')
        replacement.append(r'A_MPIO_INCLUDE')
        pattern.append(r'^R_')
        replacement.append(r'A_')
        pattern.append(r'#include "run_mpi.h"')
        replacement.append(r'#include "app_mpi.h"')

        for _pattern, _replacement in zip(pattern, replacement):
            decalage += len(_replacement.split('\n')) - len(_pattern.split('\n'))
            text = re.sub(_pattern, _replacement, text, flags=re.MULTILINE)        

        # Commented lines to remove
        text = delete_lines([
            '/* Also rename the MPIO routines to get the MPI versions */',
            '#define MPIO_Wait A_MPI_Wait',
            '#define MPIO_Test A_MPI_Test',
            '#define PMPIO_Wait A_PMPI_Wait',
            '#define PMPIO_Test A_PMPI_Test',
        ], text)

        return text

    def _generate_app_mpioh(self, gen_file):
        log.debug("Running _generate_app_mpioh (IntelIntelHeaderGenerator). File: {}.".format(gen_file))
        self._generate_run_mpioh(gen_file)
        with open(gen_file, "r") as _file:
            _content = _file.read()

        _new_content = self._common_generate_app_mpioh(_content)
        with open(gen_file, 'w') as _file:
            _file.write(_new_content)

    def __aux_generate_run_mpioh(self, text):
        log.debug("Running __aux_generate_run_mpioh (IntelIntelHeaderGenerator).")
        pattern = []
        replacement = []
        decalage = 0      
        # Commented lines to remove
        text = delete_line_from_pattern('/* Also rename the MPIO routines to get the MPI versions */', text)
        text = delete_line_from_pattern('#define MPIO_Wait R_MPI_Wait', text)
        text = delete_line_from_pattern('#define MPIO_Test R_MPI_Test', text)
        text = delete_line_from_pattern('#define PMPIO_Wait R_PMPI_Wait', text)
        text = delete_line_from_pattern('#define PMPIO_Test R_PMPI_Test', text)

        pattern.append(r' MPIO_')
        replacement.append(r' R_MPIO_')
        
        
        for _pattern, _replacement in zip(pattern, replacement):
            decalage += len(_replacement.split('\n')) - len(_pattern.split('\n'))
            text = re.sub(_pattern, _replacement, text, flags=re.MULTILINE)        
        
        
        return text

    def __generate_run_mpioh(self, gen_file):
        log.debug("Running __generate_run_mpioh (IntelIntelHeaderGenerator). File: {}.".format(gen_file))
        super()._generate_run_mpioh(gen_file)
        with open(gen_file, "r") as _file:
            _content = _file.read()

        _new_content = self.__aux_generate_run_mpioh(_content)
        with open(gen_file, 'w') as _file:
            _file.write(_new_content)

    def generate(self):
        log.debug("Running generate (IntelIntelHeaderGenerator).")
        shutil.copy2(
            os.path.join(self.dir_input, "mpich-3.1.2_mpi.h"),
            os.path.join(self.dir_output, self._run_mpi_header_file)
            )
        shutil.copy2(
            os.path.join(self.dir_input, "mpich-3.1.2_mpi.h"),
            os.path.join(self.dir_output, self._app_mpi_header_file)
            )
        shutil.copy2(
            os.path.join(self.dir_input, "mpich-3.1.2_mpio.h"),
            os.path.join(self.dir_output, self._run_mpio_header_file)
            )
        shutil.copy2(
            os.path.join(self.dir_input, "mpich-3.1.2_mpio.h"),
            os.path.join(self.dir_output, self._app_mpio_header_file)
            )
        self._generate_run_mpih(os.path.join(self.dir_output, self._run_mpi_header_file))
        self.__generate_run_mpioh(os.path.join(self.dir_output, self._run_mpio_header_file))
        self._generate_app_mpih(os.path.join(self.dir_output, self._app_mpi_header_file))
        self._generate_app_mpioh(os.path.join(self.dir_output, self._app_mpio_header_file))
        self._generate_wrapper_fh(os.path.join(self.dir_output, self._wrapper_f_header_file))
        log.debug("INTEL_INTEL header has been generated.")


class IntelMpichHeaderGenerator(IntelIntelHeaderGenerator):

    def __init__(self,
                 dir_input = "src/preload/header/scripts/intel_intel_headers",
                 dir_output = "src/preload/header/_INTEL_MPICH_gen"
                 ):
        log.info("Generation of INTEL_MPICH headers in progress.")
        self.dir_input = dir_input 
        self.dir_output = dir_output
        os.makedirs(self.dir_output, exist_ok=True)
    
    
class MpichIntelHeaderGenerator(IntelIntelHeaderGenerator):

    def __init__(self,
                 dir_input = "src/preload/header/scripts/intel_intel_headers",
                 dir_output = "src/preload/header/_MPICH_INTEL_gen"
                 ):
        log.info("Generation of MPICH_INTEL headers in progress.")
        self.dir_input = dir_input 
        self.dir_output = dir_output
        os.makedirs(self.dir_output, exist_ok=True)
    

class MpichMpichHeaderGenerator(IntelIntelHeaderGenerator):

    def __init__(self,
                 dir_input = "src/preload/header/scripts/intel_intel_headers",
                 dir_output = "src/preload/header/_MPICH_MPICH_gen"
                 ):
        log.info("Generation of MPICH_MPICH headers in progress.")
        self.dir_input = dir_input 
        self.dir_output = dir_output
        os.makedirs(self.dir_output, exist_ok=True)
    

#----------------------- GROUPE B -------------------------
class IntelOmpiHeaderGenerator(IntelHeaderGenerator):

    def __init__(self,
                 dir_input = "src/preload/header/scripts/intel_ompi_headers",
                 dir_output = "src/preload/header/_INTEL_OMPI_gen"
                 ):
        log.info("Generation of INTEL_OMPI headers in progress.")
        self.dir_input = dir_input 
        self.dir_output = dir_output
        os.makedirs(self.dir_output, exist_ok=True)
    
    def _common_generate_app_mpih(self, text):
        log.debug("Running _common_generate_app_mpih (IntelOmpiHeaderGenerator).")
        pattern = []
        replacement = []
        decalage = 0

        pattern.append(r'([ ()*_$\t])R_')
        replacement.append(r'\1A_')
        pattern.append(r'//#define A_MPI_DUP_FN         MPIR_Dup_fn')
        replacement.append('#define A_MPI_DUP_FN         MPIR_Dup_fn')
        pattern.append(r'#include "run_mpio.h"')
        replacement.append(r'#include "app_mpio.h"')
        for _pattern, _replacement in zip(pattern, replacement):
            decalage += len(_replacement.split('\n')) - len(_pattern.split('\n'))
            text = re.sub(_pattern, _replacement, text, flags=re.MULTILINE)        

        # lignes à supprimer car commentées dans le header de référence
        text = delete_lines([
            '/* Programs that need to convert types used in MPICH should use these */',
            '#define A_MPI_Comm_c2f(comm) (A_MPI_Fint)(comm)',
            '#define A_MPI_Comm_f2c(comm) (A_MPI_Comm)(comm)',
            '#define A_MPI_Type_c2f(datatype) (A_MPI_Fint)(datatype)',
            '#define A_MPI_Type_f2c(datatype) (A_MPI_Datatype)(datatype)',
            '#define A_MPI_Group_c2f(group) (A_MPI_Fint)(group)',
            '#define A_MPI_Group_f2c(group) (A_MPI_Group)(group)',
            '#define A_MPI_Info_c2f(info) (A_MPI_Fint)(info)',
            '#define A_MPI_Info_f2c(info) (A_MPI_Info)(info)',
            '#define A_MPI_Request_f2c(request) (A_MPI_Request)(request)',
            '#define A_MPI_Request_c2f(request) (A_MPI_Fint)(request)',
            '#define A_MPI_Op_c2f(op) (A_MPI_Fint)(op)',
            '#define A_MPI_Op_f2c(op) (A_MPI_Op)(op)',
            '#define A_MPI_Errhandler_c2f(errhandler) (A_MPI_Fint)(errhandler)',
            '#define A_MPI_Errhandler_f2c(errhandler) (A_MPI_Errhandler)(errhandler)',
            '#define A_MPI_Win_c2f(win)   (A_MPI_Fint)(win)',
            '#define A_MPI_Win_f2c(win)   (A_MPI_Win)(win)',
            '#define A_MPI_Message_c2f(msg) ((A_MPI_Fint)(msg))',
            '#define A_MPI_Message_f2c(msg) ((A_MPI_Message)(msg))',
            '//extern MPIU_DLL_SPEC int * A_MPI_UNWEIGHTED;',
            '//extern MPIU_DLL_SPEC int * A_MPI_WEIGHTS_EMPTY;'
        ], text)

        # lignes à supprimer car absente du header de référence
        text = delete_lines([
            'int * MPI_UNWEIGHTED;',
            'int * MPI_WEIGHTS_EMPTY;',
            '#define A_MPI_Comm_c2f(comm) (A_MPI_Fint)(comm)',
            '#define A_MPI_Comm_f2c(comm) (A_MPI_Comm)(comm)',
            '#define A_MPI_Type_c2f(datatype) (A_MPI_Fint)(datatype)',
            '#define A_MPI_Type_f2c(datatype) (A_MPI_Datatype)(datatype)',
            '#define A_MPI_Group_c2f(group) (A_MPI_Fint)(group)',
            '#define A_MPI_Group_f2c(group) (A_MPI_Group)(group)',
            '#define A_MPI_Info_c2f(info) (A_MPI_Fint)(info)',
            '#define A_MPI_Info_f2c(info) (A_MPI_Info)(info)',
            '#define A_MPI_Request_f2c(request) (A_MPI_Request)(request)',
            '#define A_MPI_Request_c2f(request) (A_MPI_Fint)(request)',
            '#define A_MPI_Op_c2f(op) (A_MPI_Fint)(op)',
            '#define A_MPI_Op_f2c(op) (A_MPI_Op)(op)',
            '#define A_MPI_Errhandler_c2f(errhandler) (A_MPI_Fint)(errhandler)',
            '#define A_MPI_Errhandler_f2c(errhandler) (A_MPI_Errhandler)(errhandler)',
            '#define A_MPI_Win_c2f(win)   (A_MPI_Fint)(win)',
            '#define A_MPI_Win_f2c(win)   (A_MPI_Win)(win)',
            '#define A_MPI_Message_c2f(msg) ((A_MPI_Fint)(msg))',
            '#define A_MPI_Message_f2c(msg) ((A_MPI_Message)(msg))',
        ], text)

        return text

    def __generate_app_mpih(self, gen_file):
        log.debug("Running __generate_app_mpih (IntelOmpiHeaderGenerator). File: {}.".format(gen_file))
        self._intel_generate_run_mpih(gen_file)
        with open(gen_file, "r") as _file:
            _content = _file.read()

        _new_content = self._common_generate_app_mpih(_content)
        with open(gen_file, 'w') as _file:
            _file.write(_new_content)

    def ompi_replace_mpi_with_rmpi(self, text: str) -> str:
        pattern = []
        replacement = []
        decalage = 0
        
        pattern.append(r'MPI_')
        replacement.append(r'R_MPI_')
        pattern.append(r'OR_MPI_')
        replacement.append(r'OMPI_')
        pattern.append(r'PR_MPI_')
        replacement.append(r'R_PMPI_')
        pattern.append(r'#    include "mpi_portable_platform.h"')
        replacement.append(r'//#    include "mpi_portable_platform.h"')
        pattern.append(r'MPIO')
        replacement.append(r'R_MPIO')
        pattern.append(r'#define R_MPI_NULL_DELETE_FN OMPI_C_R_MPI_NULL_DELETE_FN')
        replacement.append(r'#define R_MPI_NULL_DELETE_FN OMPI_C_MPI_NULL_DELETE_FN')
        pattern.append(r'#define R_MPI_NULL_COPY_FN OMPI_C_R_MPI_NULL_COPY_FN')
        replacement.append(r'#define R_MPI_NULL_COPY_FN OMPI_C_MPI_NULL_COPY_FN')
        pattern.append(r'const ')
        replacement.append(r'')
        pattern.append(r'#define OPAL_BUILD_PLATFORM_COMPILER_FAMILYID .*')
        replacement.append(r'#define OPAL_BUILD_PLATFORM_COMPILER_FAMILYID 2')
        pattern.append(r'#define OPAL_BUILD_PLATFORM_COMPILER_VERSION .*')
        replacement.append(r'#define OPAL_BUILD_PLATFORM_COMPILER_VERSION 1474738278')
        pattern.append(r'#define OPAL_HAVE_ATTRIBUTE_DEPRECATED_ARGUMENT .*')
        replacement.append(r'#define OPAL_HAVE_ATTRIBUTE_DEPRECATED_ARGUMENT 0')
        pattern.append(r'#define R_MPI_TYPE_NULL_DELETE_FN OMPI_C_R_MPI_TYPE_NULL_DELETE_FN')
        replacement.append(r'#define R_MPI_TYPE_NULL_DELETE_FN OMPI_C_MPI_TYPE_NULL_DELETE_FN')
        pattern.append(r'#define R_MPI_TYPE_NULL_COPY_FN OMPI_C_R_MPI_TYPE_NULL_COPY_FN')
        replacement.append(r'#define R_MPI_TYPE_NULL_COPY_FN OMPI_C_MPI_TYPE_NULL_COPY_FN')
        pattern.append(r'#define R_MPI_TYPE_DUP_FN OMPI_C_R_MPI_TYPE_DUP_FN')
        replacement.append(r'#define R_MPI_TYPE_DUP_FN OMPI_C_MPI_TYPE_DUP_FN')
        pattern.append(r'#define R_MPI_COMM_NULL_DELETE_FN OMPI_C_R_MPI_COMM_NULL_DELETE_FN')
        replacement.append(r'#define R_MPI_COMM_NULL_DELETE_FN OMPI_C_MPI_COMM_NULL_DELETE_FN')
        pattern.append(r'#define R_MPI_COMM_NULL_COPY_FN OMPI_C_R_MPI_COMM_NULL_COPY_FN')
        replacement.append(r'#define R_MPI_COMM_NULL_COPY_FN OMPI_C_MPI_COMM_NULL_COPY_FN')
        pattern.append(r'#define R_MPI_WIN_NULL_DELETE_FN OMPI_C_R_MPI_WIN_NULL_DELETE_FN')
        replacement.append(r'#define R_MPI_WIN_NULL_DELETE_FN OMPI_C_MPI_WIN_NULL_DELETE_FN')
        pattern.append(r'#define R_MPI_WIN_NULL_COPY_FN OMPI_C_R_MPI_WIN_NULL_COPY_FN')
        replacement.append(r'#define R_MPI_WIN_NULL_COPY_FN OMPI_C_MPI_WIN_NULL_COPY_FN')
        pattern.append(r'#define R_MPI_WIN_DUP_FN OMPI_C_R_MPI_WIN_DUP_FN')
        replacement.append(r'#define R_MPI_WIN_DUP_FN OMPI_C_MPI_WIN_DUP_FN')
        pattern.append(r'OMPI_C_R_MPI')
        replacement.append('OMPI_C_MPI')

        for _pattern, _replacement in zip(pattern, replacement):
            decalage += len(_replacement.split('\n')) - len(_pattern.split('\n'))
            log.debug(_pattern+" => "+_replacement)
            text = re.sub(_pattern, _replacement, text, flags=re.MULTILINE)
        
        _pattern = """
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_packed;
"""
        _replacement = """
OMPI_DECLSPEC extern struct ompi_predefined_datatype_t ompi_mpi_packed;

#define R_MPI_T_ERR_INVALID_NAME      73  /* Name doesn't match */
#define R_MPI_T_ERR_INVALID           74  /* Generic error code for MPI_T added in MPI-3.1 */"""
        text = re.sub(re.escape(_pattern), _replacement, text, flags=re.DOTALL)
        decalage = len(_replacement.split('\n')) - len(_pattern.split('\n'))

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
        """
        log.debug("Running _generate_run_mpih (HeaderGenerator).")
        try:
            with open(gen_file, "r") as _file:
                _content = _file.read()
                _new_content = self.ompi_replace_mpi_with_rmpi(_content)
            with open(gen_file, 'w') as _file:
                _file.write(_new_content)
        except FileNotFoundError:
            log.error(f"The file '{gen_file}' does not exist.")
        except Exception as e:
            log.error(f"An error occurred: {str(e)}")

    def _common_generate_app_mpioh(self, text):
        log.debug("Running _common_generate_app_mpioh (IntelIntelHeaderGenerator).")
        pattern = []
        replacement = []
        decalage = 0      

        pattern.append(r'([ ()*_$\t])R_')
        replacement.append(r'\1A_')
        pattern.append(r'^R_')
        replacement.append(r'A_')

        for _pattern, _replacement in zip(pattern, replacement):
            decalage += len(_replacement.split('\n')) - len(_pattern.split('\n'))
            text = re.sub(_pattern, _replacement, text, flags=re.MULTILINE)        

        return text

    def _generate_app_mpioh(self, gen_file):
        log.debug("Running _generate_app_mpioh (IntelOmpiHeaderGenerator). File: {}.".format(gen_file))
        self._generate_run_mpioh(gen_file)
        with open(gen_file, "r") as _file:
            _content = _file.read()

        _new_content = self._common_generate_app_mpioh(_content)
        with open(gen_file, 'w') as _file:
            _file.write(_new_content)

    def generate(self):
        shutil.copy2(
            os.path.join(self.dir_input, "mpich-3.1.2_mpi.h"),
            os.path.join(self.dir_output, self._app_mpi_header_file)
        )
        shutil.copy2(
            os.path.join(self.dir_input, "mpich-3.1.2_mpio.h"),
            os.path.join(self.dir_output, self._app_mpio_header_file)
        )
        shutil.copy2(
            os.path.join(self.dir_input, "ompi-1.8.8_mpi.h"),
            os.path.join(self.dir_output, self._run_mpi_header_file)
        )
        self._generate_run_mpih(os.path.join(self.dir_output, self._run_mpi_header_file))
        self.__generate_app_mpih(os.path.join(self.dir_output, self._app_mpi_header_file))
        self._generate_app_mpioh(os.path.join(self.dir_output, self._app_mpio_header_file))
        self._generate_wrapper_fh(os.path.join(self.dir_output, self._wrapper_f_header_file))
        log.debug("INTEL_OMPI header has been generated.")


class MpichOmpiHeaderGenerator(IntelOmpiHeaderGenerator):

    def __init__(self,
                 dir_input = "src/preload/header/scripts/intel_ompi_headers",
                 dir_output = "src/preload/header/_MPICH_OMPI_gen"
                 ):
        log.info("Generation of MPICH_OMPI headers in progress.")
        self.dir_input = dir_input 
        self.dir_output = dir_output
        os.makedirs(self.dir_output, exist_ok=True)

#----------------------- GROUPE C -------------------------
class OmpiIntelHeaderGenerator(IntelOmpiHeaderGenerator):

    def __init__(self,
                 dir_input = "src/preload/header/scripts/ompi_intel_headers",
                 dir_output = "src/preload/header/_OMPI_INTEL_gen"
                 ):
        log.info("Generation of OMPI_INTEL headers in progress.")
        self.dir_input = dir_input 
        self.dir_output = dir_output
        os.makedirs(self.dir_output, exist_ok=True)

    def _run_to_app(self, text: str) -> str:
        text = delete_line_from_pattern('OMPI_DECLSPEC extern', text)
        pattern = []
        replacement = []
        decalage = 0

        pattern.append(r'([ \t(*,)_"])R_')
        replacement.append(r'\1A_')
        pattern.append(r'#define OMPI_OFFSET_DATATYPE A_MPI_LONG_LONG')
        replacement.append('#define A_OMPI_OFFSET_DATATYPE A_MPI_LONG_LONG')
        pattern.append(r'A_MPIO')
        replacement.append(r'MPIO')
        pattern.append(r'IR_MPI')
        replacement.append('IA_MPI')      
        
        for _pattern, _replacement in zip(pattern, replacement):
            decalage += len(_replacement.split('\n')) - len(_pattern.split('\n'))
            log.debug(_pattern+" => "+_replacement)
            text = re.sub(_pattern, _replacement, text, flags=re.MULTILINE)        
        
        text = function_to_delete(text, 'OMPI_DECLSPEC int OMPI_C_MPI_TYPE_NULL_DELETE_FN')
        text = function_to_delete(text, 'OMPI_DECLSPEC int OMPI_C_MPI_TYPE_NULL_COPY_FN')
        text = function_to_delete(text, 'OMPI_DECLSPEC int OMPI_C_MPI_TYPE_DUP_FN')
        text = function_to_delete(text, 'OMPI_DECLSPEC int OMPI_C_MPI_COMM_NULL_DELETE_FN')
        text = function_to_delete(text, 'OMPI_DECLSPEC int OMPI_C_MPI_COMM_NULL_COPY_FN')
        text = function_to_delete(text, 'OMPI_DECLSPEC int OMPI_C_MPI_COMM_DUP_FN')
        text = function_to_delete(text, 'OMPI_DECLSPEC int OMPI_C_MPI_NULL_DELETE_FN')
        text = function_to_delete(text, 'OMPI_DECLSPEC int OMPI_C_MPI_NULL_COPY_FN')
        text = function_to_delete(text, 'OMPI_DECLSPEC int OMPI_C_MPI_DUP_FN')
        text = function_to_delete(text, 'OMPI_DECLSPEC int OMPI_C_MPI_WIN_NULL_DELETE_FN')
        text = function_to_delete(text, 'OMPI_DECLSPEC int OMPI_C_MPI_WIN_NULL_COPY_FN')
        text = function_to_delete(text, 'OMPI_DECLSPEC int OMPI_C_MPI_WIN_DUP_FN')

        _pattern_block = """#define A_MPI_CONVERSION_FN_NULL ((A_MPI_Datarep_conversion_function*) 0)
#endif"""
        _replacement_block = """#define A_MPI_CONVERSION_FN_NULL ((A_MPI_Datarep_conversion_function*) 0)
#endif

void * OMPI_C_MPI_TYPE_NULL_DELETE_FN;
void * OMPI_C_MPI_TYPE_NULL_COPY_FN;
void * OMPI_C_MPI_TYPE_DUP_FN;
void * OMPI_C_MPI_COMM_NULL_DELETE_FN;
void * OMPI_C_MPI_COMM_NULL_COPY_FN;
void * OMPI_C_MPI_COMM_DUP_FN;
void * OMPI_C_MPI_NULL_DELETE_FN;
void * OMPI_C_MPI_NULL_COPY_FN;
void * OMPI_C_MPI_DUP_FN;
void * OMPI_C_MPI_WIN_NULL_DELETE_FN;
void * OMPI_C_MPI_WIN_NULL_COPY_FN;
void * OMPI_C_MPI_WIN_DUP_FN;
"""
        text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)
        return text

    def _generate_app_mpih(self, gen_file):
        log.debug("Running _generate_app_mpih (OmpiIntelHeaderGenerator). File: {}.".format(gen_file))
        self._generate_run_mpih(gen_file)
        with open(gen_file, "r") as _file:
            _content = _file.read()

        _new_content = self._run_to_app(_content)
        with open(gen_file, 'w') as _file:
            _file.write(_new_content)

    def _app_to_run(self, text):
        log.debug("Running _app_to_run (OmpiIntelHeaderGenerator).")
        pattern = []
        replacement = []
        decalage = 0
        pattern.append(r'([ *(),_])A_')
        replacement.append(r'\1R_')
        pattern.append(r'^A_')
        replacement.append(r'R_')
        pattern.append(r' MPIO')
        replacement.append(r' R_MPIO')
        pattern.append(r'//#define R_MPI_DUP_FN         MPIR_Dup_fn')
        replacement.append('#define R_MPI_DUP_FN         MPIR_Dup_fn')
        for _pattern, _replacement in zip(pattern, replacement):
            decalage += len(_replacement.split('\n')) - len(_pattern.split('\n'))
            text = re.sub(_pattern, _replacement, text, flags=re.MULTILINE)        

        # lignes à supprimer car absente du header de référence
        text = delete_lines([
            'int * MPI_UNWEIGHTED;',
            'int * MPI_WEIGHTS_EMPTY;',
        ], text)
        text = function_to_delete(text, 'int R_MPI_DUP_FN')
        return text

    def __generate_run_mpih(self, gen_file):
        log.debug("Running _generate_run_mpih (OmpiIntelHeaderGenerator). File: {}.".format(gen_file))
        self._intel_generate_run_mpih(gen_file)
        
        with open(gen_file, "r") as _file:
            _content = _file.read()

        _new_content = self._app_to_run(_content)
        with open(gen_file, 'w') as _file:
            _file.write(_new_content)

    def __generate_run_mpioh(self, gen_file):
        log.debug("Running _generate_run_mpih (OmpiIntelHeaderGenerator). File: {}.".format(gen_file))
        self._generate_app_mpioh(gen_file)
        
        with open(gen_file, "r") as _file:
            _content = _file.read()

        _new_content = self._app_to_run(_content)
        with open(gen_file, 'w') as _file:
            _file.write(_new_content)

    def generate(self):
        
        shutil.copy2(
            os.path.join(self.dir_input, "mpich-3.1.2_mpi.h"),
            os.path.join(self.dir_output, self._run_mpi_header_file)
        )
        
        shutil.copy2(
            os.path.join(self.dir_input, "mpich-3.1.2_mpio.h"),
            os.path.join(self.dir_output, self._run_mpio_header_file)
        )
        
        shutil.copy2(
            os.path.join(self.dir_input, "ompi-1.8.8_mpi.h"),
            os.path.join(self.dir_output, self._app_mpi_header_file)
        )
        self.__generate_run_mpih(os.path.join(self.dir_output, self._run_mpi_header_file))
        self._generate_app_mpih(os.path.join(self.dir_output, self._app_mpi_header_file))
        self.__generate_run_mpioh(os.path.join(self.dir_output, self._run_mpio_header_file))
        self._generate_wrapper_fh(os.path.join(self.dir_output, self._wrapper_f_header_file))
        log.debug("OMPI_INTEL header has been generated.")

class OmpiMpichHeaderGenerator(OmpiIntelHeaderGenerator):

    def __init__(self,
                 dir_input = "src/preload/header/scripts/ompi_mpich_headers",
                 dir_output = "src/preload/header/_OMPI_MPICH_gen"
                 ):
        log.info("Generation of OMPI_MPICH headers in progress.")
        self.dir_input = dir_input 
        self.dir_output = dir_output
        os.makedirs(self.dir_output, exist_ok=True)

#----------------------- GROUPE X -------------------------
class OmpiOmpiHeaderGenerator(OmpiHeaderGenerator):

    def __init__(self,
                 dir_input = "src/preload/header/scripts/ompi_ompi_headers",
                 dir_output = "src/preload/header/_OMPI_OMPI_gen"
                 ):
        log.info("Generation of OMPI_OMPI headers in progress.")
        self.dir_input = dir_input 
        self.dir_output = dir_output
        os.makedirs(self.dir_output, exist_ok=True)
    
    def _ompi_ompi_run_exception(self, text):
        pattern = []
        replacement = []
        decalage = 0
        pattern.append(r'//(#define OPAL_MAX_*)')
        replacement.append(r'\1')
        pattern.append(r'\(ccc_##')
        replacement.append('&(')
        pattern.append(r'\(\*ccc_(\w+)\)')
        replacement.append(r'\1')
        pattern.append(r'OMPI_C_R_MPI')
        replacement.append(r'OMPI_C_MPI')
        for _pattern, _replacement in zip(pattern, replacement):
            decalage += len(_replacement.split('\n')) - len(_pattern.split('\n'))
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
        with open(gen_file, "r") as _file:
            _content = _file.read()

        _new_content = self._ompi_ompi_run_exception(_content)
        with open(gen_file, 'w') as _file:
            _file.write(_new_content)

    def _run_to_app(self, text: str) -> str:
        pattern = []
        replacement = []
        decalage = 0

        pattern.append(r'([ \t(*,)_"])R_')
        replacement.append(r'\1A_')
        pattern.append(r'A_MPIO')
        replacement.append('MPIO')
        pattern.append(r'r_ompi_status')
        replacement.append('a_ompi_status')
        pattern.append(r'IR_MPI_')
        replacement.append('IA_MPI_')
        for _pattern, _replacement in zip(pattern, replacement):
            decalage += len(_replacement.split('\n')) - len(_pattern.split('\n'))
            log.debug(_pattern+" => "+_replacement)
            text = re.sub(_pattern, _replacement, text, flags=re.MULTILINE)    
        return text

    def _generate_app_mpih(self, gen_file: str) -> None:
        self._generate_run_mpih(gen_file)
        with open(gen_file, "r") as _file:
            _content = _file.read()

        _new_content = self._run_to_app(_content)
        with open(gen_file, 'w') as _file:
            _file.write(_new_content)

    def generate(self):
        shutil.copy2(os.path.join(self.dir_input, "ompi-1.8.8_mpi.h"), os.path.join(self.dir_output, self._run_mpi_header_file))
        shutil.copy2(os.path.join(self.dir_input, "ompi-1.8.8_mpi.h"), os.path.join(self.dir_output, self._app_mpi_header_file))
        super().generate()
        log.debug("OMPI header has been generated.")

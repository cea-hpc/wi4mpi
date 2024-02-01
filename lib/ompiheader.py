#!/usr/bin/env python3

import os
import shutil
import re
from logging import getLogger
from logging.config import fileConfig
from header import HeaderGenerator
from textoperator import delete_lines, delete_line_from_pattern, insert_lines, function_to_delete

fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)),"logging.conf"))
log = getLogger("header_logger")

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

#!/usr/bin/env python3
"""
OmpiHeader module for generating Ompi-specific header files.
"""

import os
import shutil
import re
from logging import getLogger
from logging.config import fileConfig
from header import HeaderGenerator
from textoperator import (
    delete_lines,
    insert_lines,
    function_to_delete,
    replacement_from_conf_file,
)

fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)), "logging.conf"))
log = getLogger("header_logger")


class OmpiHeaderGenerator(HeaderGenerator):
    """
    OmpiHeaderGenerator class for generating Ompi-specific header files.
    """

    def __init__(
        self,
        dir_input="src/interface/header/scripts/ompi_headers",
        dir_output="src/interface/header/_OMPI_test",
    ):
        log.info("Generation of OMPI headers in progress.")
        super().__init__(dir_input=dir_input, dir_output=dir_output)

    def _generate_wrapper_fh(self, gen_file):
        super()._generate_wrapper_fh(gen_file)
        if not os.path.exists(os.path.join(self.dir_output, "wrapper_f.h")):
            log.warning(lambda: f'Using {os.path.join(self.dir_input, "wrapper_f.h")}')
            shutil.copy2(os.path.join(self.dir_input, "wrapper_f.h"), self.dir_output)

    def _replace_mpi_with_rmpi(self, text: str) -> str:

        if self.__class__.__name__ != "OmpiOmpiHeaderGenerator":
            text, decalage = replacement_from_conf_file(
                os.path.join(self.wi4mpi_root, "lib/etc/ompiheader._replace_mpi_with_rmpi.replace"),
                text,
                shift=True,
            )
        else:
            text, decalage = replacement_from_conf_file(
                os.path.join(
                    self.wi4mpi_root, "lib/etc/ompiheader._replace_mpi_with_rmpi.ompiompi.replace"
                ),
                text,
                shift=True,
            )

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
        decalage = len(_replacement.split("\n")) - len(_pattern.split("\n"))

        if self.__class__.__name__ != "OmpiOmpiHeaderGenerator":
            lines_to_insert = [
                r"int (*ccc_OMPI_C_MPI_NULL_DELETE_FN)( R_MPI_Comm comm, int comm_keyval,",
                r"                                           void* attribute_val_out,",
                r"                                           void* extra_state );",
                r"int (*ccc_OMPI_C_MPI_DUP_FN)( R_MPI_Comm comm, int comm_keyval,",
                r"                                   void* extra_state,",
                r"                                   void* attribute_val_in,",
                r"                                   void* attribute_val_out,",
                r"                                   int* flag );",
                r"int (*ccc_OMPI_C_MPI_NULL_COPY_FN)( R_MPI_Comm comm, int comm_keyval,",
                r"                                         void* extra_state,",
                r"                                         void* attribute_val_in,",
                r"                                         void* attribute_val_out,",
                r"                                         int* flag );",
                r"int (*ccc_OMPI_C_MPI_COMM_DUP_FN)( R_MPI_Comm comm, int comm_keyval,",
                r"                                        void* extra_state,",
                r"                                        void* attribute_val_in,",
                r"                                        void* attribute_val_out,",
                r"                                        int* flag );",
                r"",
            ]
            text = insert_lines(lines_to_insert, 875 + decalage, text)
            decalage += len(lines_to_insert)
            lines_to_insert = [
                r"#if !allocate_global",
                r"#define ccc_linkage extern",
                r"#else",
                r"#define ccc_linkage",
                r"#endif",
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
            text = delete_lines(
                [
                    r"OMPI_DECLSPEC extern R_MPI_Fint *R_MPI_F_STATUS_IGNORE;",
                    r"OMPI_DECLSPEC extern R_MPI_Fint *R_MPI_F_STATUSES_IGNORE;",
                ],
                text,
            )
            list_of_functions_to_delete = [
                "OMPI_DECLSPEC int OMPI_C_R_MPI_TYPE_NULL_DELETE_FN",
                "OMPI_DECLSPEC int OMPI_C_R_MPI_TYPE_NULL_COPY_FN",
                "OMPI_DECLSPEC int OMPI_C_R_MPI_TYPE_DUP_FN",
                "OMPI_DECLSPEC int OMPI_C_R_MPI_COMM_NULL_DELETE_FN",
                "OMPI_DECLSPEC int OMPI_C_R_MPI_COMM_NULL_COPY_FN",
                "OMPI_DECLSPEC int OMPI_C_R_MPI_COMM_DUP_FN",
                "OMPI_DECLSPEC int OMPI_C_R_MPI_NULL_DELETE_FN",
                "OMPI_DECLSPEC int OMPI_C_R_MPI_NULL_COPY_FN",
                "OMPI_DECLSPEC int OMPI_C_R_MPI_DUP_FN",
                "OMPI_DECLSPEC int OMPI_C_R_MPI_WIN_NULL_DELETE_FN",
                "OMPI_DECLSPEC int OMPI_C_R_MPI_WIN_NULL_COPY_FN",
                "OMPI_DECLSPEC int OMPI_C_R_MPI_WIN_DUP_FN",
            ]
            for _function in list_of_functions_to_delete:
                text = function_to_delete(text, _function)

        return text

    def _generate_run_mpioh(self, gen_file):
        pass

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

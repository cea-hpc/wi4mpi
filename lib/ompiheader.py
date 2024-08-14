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
        mpi_target_version={},
    ):
        log.info("Generation of OMPI headers in progress.")
        super().__init__(
                dir_input=dir_input,
                dir_output=dir_output,
                mpi_target_version=mpi_target_version
        )

    def _generate_wrapper_fh(self, gen_file):
        def _msg(wrapper_f):
            return f"Using {wrapper_f} (OmpiHeaderGenerator)"

        if not os.path.exists(os.path.join(self.dir_output, "wrapper_f.h")):
            wrapper_f = os.path.join(self.dir_input, "wrapper_f.h")
            log.warning(_msg(wrapper_f))
            shutil.copy2(os.path.join(self.dir_input, "wrapper_f.h"), self.dir_output)

    def _replace_mpi_with_rmpi(self, text: str) -> str:

        if self.__class__.__name__ != "OmpiOmpiHeaderGenerator":
            text, decalage = replacement_from_conf_file(
                os.path.join(self.etc_dir, "ompiheader._replace_mpi_with_rmpi.replace"),
                text,
                shift=True,
            )
        else:
            text, decalage = replacement_from_conf_file(
                os.path.join(self.etc_dir, "ompiheader._replace_mpi_with_rmpi.ompiompi.replace"),
                text,
                shift=True,
            )

        if "4.1.6" == self.mpi_target_version["openmpi"]:
            _pattern = """
#if !OMPI_BUILDING
#if defined(c_plusplus) || defined(__cplusplus)
#define OMPI_PREDEFINED_GLOBAL(type, global) (static_cast<type> (static_cast<void *> (&(global))))
#else
#define OMPI_PREDEFINED_GLOBAL(type, global) ((type) ((void *) &(global)))
#endif
#else
#define OMPI_PREDEFINED_GLOBAL(type, global) ((type) &(global))
#endif
"""
        else:
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
            _pattern_block = """
#define R_MPI_CONVERSION_FN_NULL ((R_MPI_Datarep_conversion_function*) 0)
#endif
"""
            _replacement_block = """
#define R_MPI_CONVERSION_FN_NULL ((R_MPI_Datarep_conversion_function*) 0)
#endif
int (*ccc_OMPI_C_MPI_NULL_DELETE_FN)( R_MPI_Comm comm, int comm_keyval,
                                           void* attribute_val_out,
                                           void* extra_state );
int (*ccc_OMPI_C_MPI_DUP_FN)( R_MPI_Comm comm, int comm_keyval,
                                   void* extra_state,
                                   void* attribute_val_in,
                                   void* attribute_val_out,
                                   int* flag );
int (*ccc_OMPI_C_MPI_NULL_COPY_FN)( R_MPI_Comm comm, int comm_keyval,
                                         void* extra_state,
                                         void* attribute_val_in,
                                         void* attribute_val_out,
                                         int* flag );
int (*ccc_OMPI_C_MPI_COMM_DUP_FN)( R_MPI_Comm comm, int comm_keyval,
                                        void* extra_state,
                                        void* attribute_val_in,
                                        void* attribute_val_out,
                                        int* flag );
"""
            text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)
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
            _replacement_block = """
/*
 * External variables
 *
 * The below externs use the ompi_predefined_xxx_t structures to maintain
 * back compatibility between MPI library versions.
 * See ompi/communicator/communicator.h comments with struct ompi_communicator_t
 * for full explanation why we chose to use the ompi_predefined_xxx_t structure.
 */
#if !allocate_global
#define ccc_linkage extern
#else
#define ccc_linkage
#endif
"""
            text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)

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
            os.path.join(self.dir_input, f"ompi-{self.mpi_target_version['openmpi']}_mpi.h"),
            os.path.join(self.dir_output, self._run_mpi_header_file),
        )
        shutil.copy2(
            os.path.join(self.dir_input, f"ompi-{self.mpi_target_version['openmpi']}_mpi.h"),
            os.path.join(self.dir_output, self._app_mpi_header_file),
        )
        super().generate()
        log.debug("OMPI header has been generated.")

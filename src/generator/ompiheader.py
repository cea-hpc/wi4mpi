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
    function_to_delete,
    replacement_from_conf_file,
)

fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)), "logging.conf"))
log = getLogger("header_logger")


class OmpiHeaderGenerator(HeaderGenerator):
    """
    OmpiHeaderGenerator class for generating Ompi-specific header files.

    Attributes:
        app (str): Used in copy_files to select file names to copy.
        run (str): Used in copy_files to select file names to copy.

    Methods:
        _generate_wrapper_fh: Generates the wrapper_f.h file.
        ompi_replace_mpi_with_rmpi: Manage exceptions for openmpi header.
        _generate_run_mpih: Generate the run_mpi.h header file.
        _generate_run_mpioh: Generate the run_mpio.h header file.
        _generate_run_mpi_protoh: Override this method to prevent generation of the run_mpi_proto.h file.
        _generate_app_mpi_protoh: Override this method to prevent generation of the app_mpi_proto.h file.
    """

    app = None
    run = "openmpi"

    def _generate_wrapper_fh(self, gen_file):
        """
        Generates the wrapper_f.h file.

        Args:
            gen_file (str): The path to the generated file.
        """
        def _msg(wrapper_f):
            return f"Using {wrapper_f} (OmpiHeaderGenerator)"

        if not os.path.exists(os.path.join(self.dir_output, "wrapper_f.h")):
            wrapper_f = os.path.join(self.dir_input, "wrapper_f.h")
            log.warning(_msg(wrapper_f))
            shutil.copy2(os.path.join(self.dir_input, "wrapper_f.h"), self.dir_output)

    def ompi_replace_mpi_with_rmpi(self, text: str) -> str:
        """
        Manage exceptions for openmpi header.

        Args:
            text (str): The content of the file.

        Returns:
            str: The modified content.
        """
        log.debug("Running ompi_replace_mpi_with_rmpi (OmpiHeaderGenerator).")
        if "5.0.3" == self.mpi_target_version["openmpi"]:
            lines_to_delete = [
                "typedef struct ompi_f08_status_public_t MPI_F08_status;",
                "typedef struct ompi_status_public_t MPI_Status;",
            ]
            text = delete_lines(lines_to_delete, text)
        if self.__class__.__name__ != "OmpiOmpiHeaderGenerator":
            text, _ = replacement_from_conf_file(
                os.path.join(self.etc_dir, "ompiheader._replace_mpi_with_rmpi.replace"),
                text,
                shift=True,
            )
        else:
            text, _ = replacement_from_conf_file(
                os.path.join(self.etc_dir, "ompiheader._replace_mpi_with_rmpi.ompiompi.replace"),
                text,
                shift=True,
            )

        if (
            "4.1.6" == self.mpi_target_version["openmpi"]
            or "5.0.3" == self.mpi_target_version["openmpi"]
        ):
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
#ifdef _OMPI
#define OMPI_PREDEFINED_GLOBAL(type, global) ((type) ((void *) (ccc_##global)))
#else
#define OMPI_PREDEFINED_GLOBAL(type, global) ((type) ((void *) &(global)))
#endif

#else
#define OMPI_PREDEFINED_GLOBAL(type, global) ((type) &(global))
#endif
#if OMPI_LOAD_SYM
#define OMPI_PREDEFINED_GLOBAL(type, global) global
#endif
"""
        text = re.sub(re.escape(_pattern), _replacement, text, flags=re.DOTALL)

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
#ifdef _OMPI
#if !allocate_global 
#define ccc_linkage(a) extern a;
#else
#define ccc_linkage(a) a;
#endif
#else
#define ccc_linkage(a) /*a*/
#endif
"""
            text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)
            if "5.0.3" == self.mpi_target_version["openmpi"]:
                text = re.sub(
                    r"struct ompi_f08_status_public_t {",
                    "struct r_ompi_f08_status_public_t {",
                    text,
                )
                text = re.sub(
                    r"typedef struct ompi_f08_status_public_t ompi_f08_status_public_t;",
                    "typedef struct r_ompi_f08_status_public_t R_MPI_F08_status;",
                    text,
                )
                text = re.sub(
                    r"typedef struct r_ompi_status_public_t r_ompi_status_public_t;",
                    "typedef struct r_ompi_status_public_t R_MPI_Status;",
                    text,
                )

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

    def _generate_run_mpih(self, gen_file: str) -> None:
        """
        Generate the run_mpi.h header file.

        Args:
            gen_file (str): The path to the generated file.
        """
        log.debug("Running _generate_run_mpih (OmpiHeaderGenerator).")
        try:
            with open(gen_file, "r", encoding="utf-8") as _file:
                _content = _file.read()
                _new_content = self.ompi_replace_mpi_with_rmpi(_content)
            with open(gen_file, "w", encoding="utf-8") as _file:
                _file.write(_new_content)
        except FileNotFoundError:
            log.error(lambda: f"The file '{gen_file}' does not exist.")
        except ValueError:
            log.error("An error occurred during _generate_run_mpih.")

    def _generate_run_mpioh(self, gen_file):
        """
        Generate the run_mpio.h header file.

        Args:
            gen_file (str): The path to the generated file.
        """
        log.debug("Running _generate_run_mpioh (OmpiHeaderGenerator).")
        if self.__class__.__name__ in ("OmpiIntelHeaderGenerator", "OmpiMpichHeaderGenerator"):
            super()._generate_run_mpioh(gen_file)

    def _generate_run_mpi_protoh(self, _):
        """
        Override this method to prevent generation of the run_mpi_proto.h file.
        """
        log.debug("Running _generate_run_mpi_protoh (OmpiHeaderGenerator).")

    def _generate_app_mpi_protoh(self, _):
        """
        Override this method to prevent generation of the app_mpi_proto.h file.
        """
        log.debug("Running _generate_app_mpi_protoh (OmpiHeaderGenerator).")

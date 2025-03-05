#!/usr/bin/env python3
"""
MpcHeader module for generating Mpc-specific header files.
"""

import os
import shutil
import re
from logging import getLogger
from logging.config import fileConfig
from header import HeaderGenerator
from textoperator import (
    replacement_from_conf_file,
    delete_bloc_from_conf_file,
)

fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)), "logging.conf"))
log = getLogger("header_logger")


class MpcHeaderGenerator(HeaderGenerator):
    """
    MpcHeaderGenerator class for generating Mpc-specific header files.

    Methods:
        _generate_wrapper_fh: Generate the wrapper_f.h header file.
        _mpc_exceptions_run_mpih: Applies exceptions for MPC's run_mpi.h file.
        _generate_run_mpih: Generate the run_mpi.h header file.
        _mpc_exceptions_app_mpih: Applies exceptions for MPC's run_mpi.h file.
        _generate_app_mpih: Generate the app_mpi.h header file.
        _mpc_exceptions_run_mpioh: Applies MPC-specific exceptions for run_mpio.h file.
        _generate_run_mpioh: Generate the run_mpio.h header file.
        _generate_run_mpi_protoh: Generate the run_mpi_proto.h header file.
        _generate_app_mpi_protoh: Generate the app_mpi_proto.h header file.
        copy_files: Copy target headers.
    """

    def _generate_wrapper_fh(self, gen_file):
        """
        Generate the wrapper_f.h header file.

        Args:
            gen_file (str): The path to the generated file.

        Returns:
            str: Message indicating the wrapper.h file used.
        """
        wrapper_warning = (
            f"The generation of '{gen_file}' have to be done locally.\n\tA MPC program has to be e"
            "xecuted in order to catch MPI_MODE_XXX values.\n\tHave a look to generator/FORTRAN/MP"
            "I_XXX_generator/MPC/gen_MPC_vars.sh"
        )
        log.warning(wrapper_warning)

        def _msg(wrapper_f):
            return f"Using {wrapper_f} (MpcHeaderGenerator)"

        if not os.path.exists(os.path.join(self.dir_output, "wrapper_f.h")):
            wrapper_f = os.path.join(self.dir_input, "wrapperf/interface_mpc.h")
            log.warning(_msg(wrapper_f))
            shutil.copy2(wrapper_f, gen_file)

    def _mpc_exceptions_run_mpih(self, text):
        """
        Applies exceptions for MPC's run_mpi.h file.

        Args:
            text (str): The content of the file.

        Returns:
            str: The modified content.
        """
        log.debug("Running _mpc_exceptions_run_mpih")

        # Define the lines to insert
        lines_to_insert = [
            "#define R_MPI_ERR_RMA_RANGE 74",
            "#define R_MPI_ERR_RMA_ATTACH 75",
            "#define R_MPI_ERR_RMA_SHARED 76",
        ]
        # Use a regular expression to insert the lines before #define R_MPI_ERR_RMA_CONFLICT
        pattern = r"(#define R_MPI_ERR_RMA_CONFLICT)"
        replacement = "\n".join(lines_to_insert) + r"\n\1"
        text = re.sub(pattern, replacement, text)

        # Add line at the end of the file
        text = re.sub(r"(\n+$)", r'\n#include "run_mpio.h"\n', text)

        # Use a regular expression to insert the lines after /** Initialization and Finalization */
        # and perform the substitution using re.sub()
        pattern = r"(/\*\* Initialization and Finalization \*/)"
        lines_to_insert = [
            "#define R_MPI_T_ERR_INVALID_NAME      73  /* Name doesn't match */",
            (
                "#define R_MPI_T_ERR_INVALID           74  /* Generic error code for MPI_T added in"
                " MPI-3.1 */"
            ),
        ]
        replacement = r"\1\n" + "\n".join(lines_to_insert)
        text = re.sub(pattern, replacement, text)

        # Regular expression to match the lines to delete
        pattern = (
            r"/\* Error handling \*/\nint"
            r" R_MPI_File_create_errhandler\(R_MPI_File_errhandler_function \*, R_MPI_Errhandler"
            r" \*\);\nint R_PMPI_File_create_errhandler\(R_MPI_File_errhandler_function"
            r" \*file_errhandler_fn, R_MPI_Errhandler \*errhandler\);\nint"
            r" R_MPI_File_call_errhandler\(void \* , int \);"
        )
        text = re.sub(pattern, "", text)

        # Add lines at the end of the file
        lines_to_insert = [
            "#ifndef R_MPI_FILE_DEFINED",
            "typedef struct ADIOI_FileD *R_MPI_File;",
            "#endif",
            "/* Error handling */",
            (
                "int R_MPI_File_create_errhandler(R_MPI_File_errhandler_function *,"
                " R_MPI_Errhandler *);"
            ),
            (
                "int R_PMPI_File_create_errhandler(R_MPI_File_errhandler_function"
                " *file_errhandler_fn, R_MPI_Errhandler *errhandler);"
            ),
            "int R_MPI_File_call_errhandler(R_MPI_File fh , int );",
        ]
        replacement = r"\1\n" + "\n".join(lines_to_insert)
        text = re.sub(r"(\n+$)", replacement, text)
        print(self.etc_dir)

        _conf_file = os.path.join(self.etc_dir, "mpcheader._mpc_exceptions_run_mpih.replace")
        text = replacement_from_conf_file(_conf_file, text)
        text = delete_bloc_from_conf_file(_conf_file, text)

        return text

    def _generate_run_mpih(self, gen_file):
        """
        Generate the run_mpi.h header file.

        Args:
            gen_file (str): The path to the generated file.
        """
        with open(gen_file, "r", encoding="utf-8") as _file:
            _content = _file.read()

        _new_content = self._replace_mpi_with_rmpi(_content)
        _new_content = self._mpc_exceptions_run_mpih(_new_content)
        with open(gen_file, "w", encoding="utf-8") as _file:
            _file.write(_new_content)

    def _mpc_exceptions_app_mpih(self, text):
        """
        Applies MPC-specific exceptions for app_mpi.h file.

        Args:
            text (str): The content of the file.

        Returns:
            str: The modified content.
        """
        log.debug("Running _mpc_exceptions_app_mpih")
        # Replace missing values with A_MPI_ERR_UNKNOWN
        pattern = r"(#define.*A_MPI_ERR_RMA_RANGE).*"
        text = re.sub(pattern, r"\1             74", text)
        pattern = r"(#define.*A_MPI_ERR_RMA_ATTACH).*"
        text = re.sub(pattern, r"\1            75", text)
        pattern = r"(#define.*A_MPI_ERR_RMA_SHARED).*"
        text = re.sub(pattern, r"\1            76", text)

        return text

    def _generate_app_mpih(self, gen_file):
        """
        Generate the app_mpi.h header file.

        Args:
            gen_file (str): The path to the generated file.
        """
        super()._generate_app_mpih(gen_file)
        with open(gen_file, "r", encoding="utf-8") as _file:
            _content = _file.read()

        _new_content = self._mpc_exceptions_app_mpih(_content)
        with open(gen_file, "w", encoding="utf-8") as _file:
            _file.write(_new_content)

    def _mpc_exceptions_run_mpioh(self, text):
        """
        Applies MPC-specific exceptions for run_mpio.h file.

        Args:
            text (str): The content of the file.

        Returns:
            str: The modified content.
        """
        log.debug("Running _mpc_exceptions_run_mpio")
        pattern = []
        replacement = []
        pattern.append(
            r"int R_MPI_File_open\(R_MPI_Comm comm, const char \*filename, int amode, R_MPI_Info"
            r" info, R_MPI_File \*fh\);"
        )
        replacement.append(
            r"int R_MPI_File_open(R_MPI_Comm comm, char *filename, int amode, R_MPI_Info info,"
            r" R_MPI_File *fh);"
        )
        pattern.append(r"int R_MPI_File_delete\(const char \*filename, R_MPI_Info info\);")
        replacement.append(r"int R_MPI_File_delete(char *filename, R_MPI_Info info);")
        pattern.append(r"                      const char \*datarep, R_MPI_Info info\);")
        replacement.append(r"                      char *datarep, R_MPI_Info info);")
        pattern.append(
            r"int R_MPI_File_write_at\(R_MPI_File fh, R_MPI_Offset offset, const void \* buf, int"
            r" count,"
        )
        replacement.append(
            r"int R_MPI_File_write_at(R_MPI_File fh, R_MPI_Offset offset, void * buf, int count,"
        )
        pattern.append(
            r"int R_MPI_File_write_at_all\(R_MPI_File fh, R_MPI_Offset offset, const void \*buf,"
            r" int count,"
        )
        replacement.append(
            r"int R_MPI_File_write_at_all(R_MPI_File fh, R_MPI_Offset offset, void *buf, int count,"
        )
        pattern.append(
            r"int R_MPI_File_iwrite_at\(R_MPI_File fh, R_MPI_Offset offset, const void \*buf, int"
            r" count,"
        )
        replacement.append(
            r"int R_MPI_File_iwrite_at(R_MPI_File fh, R_MPI_Offset offset, void *buf, int count,"
        )
        pattern.append(
            r"int R_MPI_File_write\(R_MPI_File fh, const void \*buf, int count, R_MPI_Datatype"
            r" datatype,"
        )
        replacement.append(
            r"int R_MPI_File_write(R_MPI_File fh, void *buf, int count, R_MPI_Datatype datatype,"
        )
        pattern.append(
            r"int R_MPI_File_write_all\(R_MPI_File fh, const void \*buf, int count, R_MPI_Datatype"
            r" datatype,"
        )
        replacement.append(
            r"int R_MPI_File_write_all(R_MPI_File fh, void *buf, int count, R_MPI_Datatype"
            r" datatype,"
        )
        pattern.append(
            r"int R_MPI_File_iwrite\(R_MPI_File fh, const void \*buf, int count, R_MPI_Datatype"
            r" datatype,"
        )
        replacement.append(
            r"int R_MPI_File_iwrite(R_MPI_File fh, void *buf, int count, R_MPI_Datatype datatype,"
        )
        pattern.append(
            r"int R_MPI_File_write_shared\(R_MPI_File fh, const void \*buf, int count,"
            r" R_MPI_Datatype datatype,"
        )
        replacement.append(
            r"int R_MPI_File_write_shared(R_MPI_File fh, void *buf, int count, R_MPI_Datatype"
            r" datatype,"
        )
        pattern.append(
            r"int R_MPI_File_iwrite_shared\(R_MPI_File fh, const void \*buf, int count,"
            r" R_MPI_Datatype datatype,"
        )
        replacement.append(
            r"int R_MPI_File_iwrite_shared(R_MPI_File fh, void *buf, int count, R_MPI_Datatype"
            r" datatype,"
        )
        pattern.append(
            r"int R_MPI_File_write_ordered\(R_MPI_File fh, const void \*buf, int count,"
            r" R_MPI_Datatype datatype,"
        )
        replacement.append(
            r"int R_MPI_File_write_ordered(R_MPI_File fh, void *buf, int count, R_MPI_Datatype"
            r" datatype,"
        )
        pattern.append(
            r"int R_MPI_File_write_at_all_begin\(R_MPI_File fh, R_MPI_Offset offset, const void"
            r" \*buf, int count,"
        )
        replacement.append(
            r"int R_MPI_File_write_at_all_begin(R_MPI_File fh, R_MPI_Offset offset, void *buf, int"
            r" count,"
        )
        pattern.append(
            r"int R_MPI_File_write_at_all_end\(R_MPI_File fh, const void \*buf, R_MPI_Status"
            r" \*status\);"
        )
        replacement.append(
            r"int R_MPI_File_write_at_all_end(R_MPI_File fh, void *buf, R_MPI_Status *status);"
        )
        pattern.append(
            r"int R_MPI_File_write_all_begin\(R_MPI_File fh, const void \*buf, int count,"
            r" R_MPI_Datatype datatype\)"
        )
        pattern.append(
            r"int R_MPI_File_write_all_end\(R_MPI_File fh, const void \*buf, R_MPI_Status"
            r" \*status\);"
        )
        replacement.append(
            r"int R_MPI_File_write_all_begin(R_MPI_File fh, void *buf, int count, R_MPI_Datatype"
            r" datatype)"
        )
        replacement.append(
            r"int R_MPI_File_write_all_end(R_MPI_File fh, void *buf, R_MPI_Status *status);"
        )
        pattern.append(
            r"int R_MPI_File_write_ordered_begin\(R_MPI_File fh, const void \*buf, int count,"
            r" R_MPI_Datatype datatype\)"
        )
        pattern.append(
            r"int R_MPI_File_write_ordered_end\(R_MPI_File fh, const void \*buf, R_MPI_Status"
            r" \*status\);"
        )
        replacement.append(
            r"int R_MPI_File_write_ordered_begin(R_MPI_File fh, void *buf, int count,"
            r" R_MPI_Datatype datatype)"
        )
        replacement.append(
            r"int R_MPI_File_write_ordered_end(R_MPI_File fh, void *buf, R_MPI_Status *status);"
        )
        pattern.append(
            r"int R_MPI_Register_datarep\(const char \*datarep, R_MPI_Datarep_conversion_function"
            r" \*read_conversion_fn,"
        )
        replacement.append(
            r"int R_MPI_Register_datarep(char *datarep, R_MPI_Datarep_conversion_function"
            r" *read_conversion_fn,"
        )
        pattern.append(
            r"int R_MPI_File_iwrite_at_all\(R_MPI_File fh, R_MPI_Offset offset, const void \*buf,"
            r" int count,"
        )
        replacement.append(
            r"int R_MPI_File_iwrite_at_all(R_MPI_File fh, R_MPI_Offset offset, void *buf, int"
            r" count,"
        )
        pattern.append(
            r"int R_MPI_File_iwrite_all\(R_MPI_File fh, const void \*buf, int count, R_MPI_Datatype"
            r" datatype,"
        )
        replacement.append(
            r"int R_MPI_File_iwrite_all(R_MPI_File fh, void *buf, int count, R_MPI_Datatype"
            r" datatype,"
        )

        for _pattern, _replacement in zip(pattern, replacement):
            log.debug(_pattern + " => " + _replacement)
            text = re.sub(_pattern, _replacement, text, flags=re.MULTILINE)

        return text

    def _generate_run_mpioh(self, gen_file):
        """
        Generate the run_mpio.h header file.

        Args:
            gen_file (str): The path to the generated file.
        """
        super()._generate_run_mpioh(gen_file)
        with open(gen_file, "r", encoding="utf-8") as _file:
            _content = _file.read()

        _new_content = self._mpc_exceptions_run_mpioh(_content)
        with open(gen_file, "w", encoding="utf-8") as _file:
            _file.write(_new_content)

    def _generate_run_mpi_protoh(self, gen_file):
        """
        Override this method to prevent generation of the run_mpi_proto.h file.
        Indeed, there is no run_mpi_proto.h with MPC.

        Args:
            gen_file (str): The path to the generated file.
        """
        pass

    def _generate_app_mpi_protoh(self, gen_file):
        """
        Override this method to prevent generation of the run_mpi_proto.h file.
        Indeed, there is no app_mpi_proto.h with MPC.

        Args:
            gen_file (str): The path to the generated file.
        """
        pass

    def copy_files(self):
        """
        Copy target headers.
        Override of the copy_files function to copy MPC-specific headers.
        """
        list_of_files_to_copy = [
            (
                os.path.join(self.dir_input, f"openmpi/{self.mpi_target_version['openmpi']}/mpi.h"),
                os.path.join(self.dir_output, self._app_mpi_header_file),
            ),
            (
                os.path.join(self.dir_input, "mpc/mpc_mpi.h"),
                os.path.join(self.dir_output, self._run_mpi_header_file),
            ),
            (
                os.path.join(self.dir_input, "mpc/mpio.h"),
                os.path.join(self.dir_output, self._run_mpio_header_file),
            ),
            (os.path.join(self.dir_input, "mpc/mpcmp.h"), self.dir_output),
            (os.path.join(self.dir_input, "mpc/sctk_types.h"), self.dir_output),
        ]
        for input_file, output_file in list_of_files_to_copy:
            shutil.copy2(input_file, output_file)

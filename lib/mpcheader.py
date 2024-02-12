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
    """

    dir_output = ""
    dir_input = ""

    def __init__(
        self,
        dir_input="src/interface/header/scripts/mpc_headers",
        dir_output="src/interface/header/_MPC",
    ):
        log.info("Generation of MPC headers in progress.")
        super().__init__(dir_input=dir_input, dir_output=dir_output)

    def _generate_wrapper_fh(self, gen_file):
        super()._generate_wrapper_fh(gen_file)

        def _msg(wrapper_f):
            return f"Using {wrapper_f} (MpcHeaderGenerator)"

        if not os.path.exists(os.path.join(self.dir_output, "wrapper_f.h")):
            wrapper_f = os.path.join(self.dir_input, "wrapper_f.h")
            log.warning(_msg(wrapper_f))
            shutil.copy2(os.path.join(self.dir_input, "wrapper_f.h"), gen_file)

    def _mpc_exceptions_run_mpih(self, text):
        log.debug("Running _mpc_exceptions_run_mpih")

        # Définir les lignes à insérer
        lines_to_insert = [
            "#define R_MPI_ERR_RMA_RANGE 74",
            "#define R_MPI_ERR_RMA_ATTACH 75",
            "#define R_MPI_ERR_RMA_SHARED 76",
        ]
        # Utiliser une expression régulière pour insérer les lignes
        # avant "#define R_MPI_ERR_RMA_CONFLICT"
        pattern = r"(#define R_MPI_ERR_RMA_CONFLICT)"
        replacement = "\n".join(lines_to_insert) + r"\n\1"
        text = re.sub(pattern, replacement, text)

        # Add line at the end of the file
        text = re.sub(r"(\n+$)", r'\n#include "run_mpio.h"\n', text)

        # Ajout supplémentaires
        lines_to_insert = [
            "#define R_MPI_T_ERR_INVALID_NAME      73  /* Name doesn't match */",
            (
                "#define R_MPI_T_ERR_INVALID           74  /* Generic error code for MPI_T added in"
                " MPI-3.1 */"
            ),
        ]
        # Utiliser une expression régulière pour insérer les lignes
        # après "/** Initialization and Finalization */"
        pattern = r"(/\*\* Initialization and Finalization \*/)"
        # Effectuer la substitution en utilisant re.sub()
        replacement = r"\1\n" + "\n".join(lines_to_insert)
        text = re.sub(pattern, replacement, text)

        # Expression régulière pour correspondre aux lignes à supprimer
        pattern = (
            r"/\* Error handling \*/\nint"
            r" R_MPI_File_create_errhandler\(R_MPI_File_errhandler_function \*, R_MPI_Errhandler"
            r" \*\);\nint R_PMPI_File_create_errhandler\(R_MPI_File_errhandler_function"
            r" \*file_errhandler_fn, R_MPI_Errhandler \*errhandler\);\nint"
            r" R_MPI_File_call_errhandler\(void \* , int \);"
        )
        # Effectuer la substitution pour supprimer les lignes
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

        _conf_file = os.path.join(
            self.wi4mpi_root, "lib/etc/mpcheader._mpc_exceptions_run_mpih.replace"
        )
        text = replacement_from_conf_file(_conf_file, text)
        text = delete_bloc_from_conf_file(_conf_file, text)

        return text

    def _generate_run_mpih(self, gen_file):
        super()._generate_run_mpih(gen_file)
        with open(gen_file, "r", encoding="utf-8") as _file:
            _content = _file.read()

        _new_content = self._mpc_exceptions_run_mpih(_content)
        with open(gen_file, "w", encoding="utf-8") as _file:
            _file.write(_new_content)

    def _mpc_exceptions_app_mpih(self, text):
        log.debug("Running _mpc_exceptions_app_mpih")
        # Remplacer les valeurs manquantes par A_MPI_ERR_UNKNOWN
        pattern = r"(#define.*A_MPI_ERR_RMA_RANGE).*"
        text = re.sub(pattern, r"\1             74", text)
        pattern = r"(#define.*A_MPI_ERR_RMA_ATTACH).*"
        text = re.sub(pattern, r"\1            75", text)
        pattern = r"(#define.*A_MPI_ERR_RMA_SHARED).*"
        text = re.sub(pattern, r"\1            76", text)

        return text

    def _generate_app_mpih(self, gen_file):
        super()._generate_app_mpih(gen_file)
        with open(gen_file, "r", encoding="utf-8") as _file:
            _content = _file.read()

        _new_content = self._mpc_exceptions_app_mpih(_content)
        with open(gen_file, "w", encoding="utf-8") as _file:
            _file.write(_new_content)

    def _mpc_exceptions_run_mpioh(self, text):
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
        super()._generate_run_mpioh(gen_file)
        with open(gen_file, "r", encoding="utf-8") as _file:
            _content = _file.read()

        _new_content = self._mpc_exceptions_run_mpioh(_content)
        with open(gen_file, "w", encoding="utf-8") as _file:
            _file.write(_new_content)

    def generate(self):
        shutil.copy2(
            os.path.join(self.dir_input, "ompi-1.8.8_mpi.h"),
            os.path.join(self.dir_output, self._app_mpi_header_file),
        )
        shutil.copy2(
            os.path.join(self.dir_input, "mpc_mpi.h"),
            os.path.join(self.dir_output, self._run_mpi_header_file),
        )
        shutil.copy2(
            os.path.join(self.dir_input, "mpio.h"),
            os.path.join(self.dir_output, self._run_mpio_header_file),
        )
        shutil.copy2(os.path.join(self.dir_input, "mpcmp.h"), self.dir_output)
        shutil.copy2(os.path.join(self.dir_input, "sctk_types.h"), self.dir_output)
        super().generate()
        log.debug("MPC header has been generated.")

#!/usr/bin/env python3
"""
IntelMpichHeader module for generating Intel-Mpich preload header files.
"""

import os
from logging import getLogger
from logging.config import fileConfig
from mpichmpichheader import MpichMpichHeaderGenerator

fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)), "logging.conf"))
log = getLogger("header_logger")


class IntelMpichHeaderGenerator(MpichMpichHeaderGenerator):
    """
    IntelMpichHeaderGenerator class for generating Intel-Mpich preload header files.

    Attributes:
        app (str): Used in copy_files to select file names to copy.
        run (str): Used in copy_files to select file names to copy.

    Methods:
        _generate_app_mpi_protoh: Generates the app_mpi_proto.h file.
    """

    app = "intelmpi"
    run = "mpich"

    def _generate_app_mpi_protoh(self, gen_file):
        """
        Override this method to prevent generation of the mpi_proto.h file.
        Indeed, there is no mpi_proto.h with Intel on the Application side.

        Args:
            gen_file (str): The path to the generated file.
        """
        pass

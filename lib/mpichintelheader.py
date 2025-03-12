#!/usr/bin/env python3
"""
MpichIntelHeaderGenerator class for generating Mpich-Intel preload header files.
"""

import os
from logging import getLogger
from logging.config import fileConfig
from mpichmpichheader import MpichMpichHeaderGenerator

fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)), "logging.conf"))
log = getLogger("header_logger")


class MpichIntelHeaderGenerator(MpichMpichHeaderGenerator):
    """
    MpichIntelHeaderGenerator class for generating Mpich-Intel preload header files.

    Attributes:
        app (str): Used in copy_files to select file names to copy.
        run (str): Used in copy_files to select file names to copy.

    Methods:
        _generate_run_mpi_protoh: Override this method to prevent generation of the run_mpi_proto.h file.
    """

    app = "mpich"
    run = "intelmpi"

    def _generate_run_mpi_protoh(self, gen_file):
        """
        Override this method to prevent generation of the run_mpi_proto.h file.
        Indeed, there is no run_mpi_proto.h with Intel MPI on the runtime side.
        """
        pass

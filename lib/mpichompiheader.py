#!/usr/bin/env python3
"""
MpichOmpiHeader module for generating Mpich-Ompi preload header files.
"""

import os
from logging import getLogger
from logging.config import fileConfig
from intelompiheader import IntelOmpiHeaderGenerator
from mpichmpichheader import MpichMpichHeaderGenerator

fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)), "logging.conf"))
log = getLogger("header_logger")


class MpichOmpiHeaderGenerator(IntelOmpiHeaderGenerator, MpichMpichHeaderGenerator):
    """
    MpichOmpiHeaderGenerator class for generating Mpich-Ompi preload header files.
    """

    app = "mpich"
    run = "openmpi"

    def _generate_run_mpioh(self, gen_file):
        pass

    def _generate_run_mpi_protoh(self, gen_file):
        pass

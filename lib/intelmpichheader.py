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
    """

    app = "intelmpi"
    run = "mpich"

    def _generate_app_mpi_protoh(self, gen_file):
        pass

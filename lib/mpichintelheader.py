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
    """

    app = "mpich"
    run = "intelmpi"

    def _generate_run_mpi_protoh(self, gen_file):
        pass

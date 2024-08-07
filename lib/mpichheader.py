#!/usr/bin/env python3
"""
MpichHeader module for generating Mpich interface header files.
"""

import os
from logging import getLogger
from logging.config import fileConfig
from intelheader import IntelHeaderGenerator

fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)), "logging.conf"))
log = getLogger("header_logger")


class MpichHeaderGenerator(IntelHeaderGenerator):
    """
    MpichHeaderGenerator class for generating Mpich interface header files.
    """

    def __init__(
        self,
        dir_input="src/interface/header/scripts/mpich_headers",
        dir_output="src/interface/header/_MPICH_test",
        mpi_target_version={},
    ):
        log.info("Generation of MPICH headers in progress.")
        super().__init__(
                dir_input=dir_input,
                dir_output=dir_output,
                mpi_target_version=mpi_target_version
        )

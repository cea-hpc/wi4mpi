#!/usr/bin/env python3
"""
OmpiMpichHeader module for generating Ompi-Mpich preload header files.
"""

import os
from logging import getLogger
from logging.config import fileConfig
from ompiintelheader import OmpiIntelHeaderGenerator

fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)), "logging.conf"))
log = getLogger("header_logger")


class OmpiMpichHeaderGenerator(OmpiIntelHeaderGenerator):
    """
    OmpiMpichHeaderGenerator class for generating Ompi-Mpich preload header files.
    """

    def __init__(
        self,
        dir_input="src/preload/header/scripts/ompi_mpich_headers",
        dir_output="src/preload/header/_OMPI_MPICH_gen",
        mpi_target_version=None,
    ):
        log.info("Generation of OMPI_MPICH headers in progress.")
        super().__init__(
            dir_input=dir_input, dir_output=dir_output, mpi_target_version=mpi_target_version
        )

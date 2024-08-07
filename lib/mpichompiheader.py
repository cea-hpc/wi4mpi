#!/usr/bin/env python3
"""
MpichOmpiHeader module for generating Mpich-Ompi preload header files.
"""

import os
from logging import getLogger
from logging.config import fileConfig
from intelompiheader import IntelOmpiHeaderGenerator

fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)), "logging.conf"))
log = getLogger("header_logger")


class MpichOmpiHeaderGenerator(IntelOmpiHeaderGenerator):
    """
    MpichOmpiHeaderGenerator class for generating Mpich-Ompi preload header files.
    """

    def __init__(
        self,
        dir_input="src/preload/header/scripts/intel_ompi_headers",
        dir_output="src/preload/header/_MPICH_OMPI_gen",
        mpi_target_version={},
    ):
        log.info("Generation of MPICH_OMPI headers in progress.")
        super().__init__(
                dir_input=dir_input,
                dir_output=dir_output,
                mpi_target_version=mpi_target_version
        )

#!/usr/bin/env python3
"""
MpichIntelHeaderGenerator class for generating Mpich-Intel preload header files.
"""

import os
from logging import getLogger
from logging.config import fileConfig
from intelintelheader import IntelIntelHeaderGenerator

fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)), "logging.conf"))
log = getLogger("header_logger")


class MpichIntelHeaderGenerator(IntelIntelHeaderGenerator):
    """
    MpichIntelHeaderGenerator class for generating Mpich-Intel preload header files.
    """

    def __init__(
        self,
        dir_input="src/preload/header/scripts/intel_intel_headers",
        dir_output="src/preload/header/_MPICH_INTEL_gen",
    ):
        log.info("Generation of MPICH_INTEL headers in progress.")
        super().__init__(dir_input=dir_input, dir_output=dir_output)

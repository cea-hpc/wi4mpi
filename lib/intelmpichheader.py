#!/usr/bin/env python3

import os
from logging import getLogger
from logging.config import fileConfig
from intelintelheader import IntelIntelHeaderGenerator

fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)), "logging.conf"))
log = getLogger("header_logger")


class IntelMpichHeaderGenerator(IntelIntelHeaderGenerator):
    def __init__(
        self,
        dir_input="src/preload/header/scripts/intel_intel_headers",
        dir_output="src/preload/header/_INTEL_MPICH_gen",
    ):
        log.info("Generation of INTEL_MPICH headers in progress.")
        self.dir_input = dir_input
        self.dir_output = dir_output
        os.makedirs(self.dir_output, exist_ok=True)

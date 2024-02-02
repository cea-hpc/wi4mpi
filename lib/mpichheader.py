#!/usr/bin/env python3

import os
from logging import getLogger
from logging.config import fileConfig
from intelheader import IntelHeaderGenerator

fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)), "logging.conf"))
log = getLogger("header_logger")


class MpichHeaderGenerator(IntelHeaderGenerator):
    def __init__(
        self,
        dir_input="src/interface/header/scripts/mpich_headers",
        dir_output="src/interface/header/_MPICH_test",
    ):
        log.info("Generation of MPICH headers in progress.")
        self.dir_input = dir_input
        self.dir_output = dir_output
        os.makedirs(self.dir_output, exist_ok=True)

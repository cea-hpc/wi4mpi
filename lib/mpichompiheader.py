#!/usr/bin/env python3

import os
import shutil
import re
from logging import getLogger
from logging.config import fileConfig
from intelompiheader import IntelOmpiHeaderGenerator

fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)),"logging.conf"))
log = getLogger("header_logger")


class MpichOmpiHeaderGenerator(IntelOmpiHeaderGenerator):

    def __init__(self,
                 dir_input = "src/preload/header/scripts/intel_ompi_headers",
                 dir_output = "src/preload/header/_MPICH_OMPI_gen"
                 ):
        log.info("Generation of MPICH_OMPI headers in progress.")
        self.dir_input = dir_input 
        self.dir_output = dir_output
        os.makedirs(self.dir_output, exist_ok=True)

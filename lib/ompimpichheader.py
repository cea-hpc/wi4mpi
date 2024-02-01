#!/usr/bin/env python3

import os
import shutil
import re
from logging import getLogger
from logging.config import fileConfig
from ompiintelheader import OmpiIntelHeaderGenerator

fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)),"logging.conf"))
log = getLogger("header_logger")


class OmpiMpichHeaderGenerator(OmpiIntelHeaderGenerator):

    def __init__(self,
                 dir_input = "src/preload/header/scripts/ompi_mpich_headers",
                 dir_output = "src/preload/header/_OMPI_MPICH_gen"
                 ):
        log.info("Generation of OMPI_MPICH headers in progress.")
        self.dir_input = dir_input 
        self.dir_output = dir_output
        os.makedirs(self.dir_output, exist_ok=True)

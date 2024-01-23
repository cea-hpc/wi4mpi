#!/usr/bin/env python3

import os
from header import MpcHeaderGenerator, IntelHeaderGenerator, MpichHeaderGenerator, OmpiHeaderGenerator
from header import IntelIntelHeaderGenerator, IntelMpichHeaderGenerator, MpichIntelHeaderGenerator, MpichMpichHeaderGenerator
from header import IntelOmpiHeaderGenerator, MpichOmpiHeaderGenerator
from header import OmpiIntelHeaderGenerator, OmpiMpichHeaderGenerator
from header import OmpiOmpiHeaderGenerator
from logging import getLogger
from logging.config import fileConfig
from docopt import docopt

fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)),"logging.conf"))
log = getLogger("generator_logger")

# Absolute path of this script
wi4mpi_root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


class Generator():
    """
    Initializes the Generator with optional directory parameters.

    Args:
        interface_header_dir (str, optional): Directory for interface headers.
        preload_header_dir (str, optional): Directory for preload headers.
        MPC_interface_header_dir (str, optional): Directory for MPC interface headers.
        INTEL_interface_header_dir (str, optional): Directory for Intel interface headers.
        MPICH_interface_header_dir (str, optional): Directory for MPICH interface headers.
        OMPI_interface_header_dir (str, optional): Directory for Open MPI interface headers.
        INTEL_INTEL_preload_header_dir (str, optional): Directory for Intel-Intel preload headers.
        INTEL_MPICH_preload_header_dir (str, optional): Directory for Intel-MPICH preload headers.
        INTEL_OMPI_preload_header_dir (str, optional): Directory for Intel-OpenMPI preload headers.
        MPICH_INTEL_preload_header_dir (str, optional): Directory for MPICH-Intel preload headers.
        MPICH_MPICH_preload_header_dir (str, optional): Directory for MPICH-MPICH preload headers.
        MPICH_OMPI_preload_header_dir (str, optional): Directory for MPICH-OpenMPI preload headers.
        OMPI_INTEL_preload_header_dir (str, optional): Directory for OpenMPI-Intel preload headers.
        OMPI_MPICH_preload_header_dir (str, optional): Directory for OpenMPI-MPICH preload headers.
        OMPI_OMPI_preload_header_dir (str, optional): Directory for OpenMPI-OpenMPI preload headers.
    """
    interface_header_dir       = "src/interface/header"
    preload_header_dir         = "src/preload/header"
    MPC_interface_header_dir   = os.path.join(interface_header_dir, "_MPC")
    INTEL_interface_header_dir = os.path.join(interface_header_dir, "_INTEL")
    MPICH_interface_header_dir = os.path.join(interface_header_dir, "_MPICH")
    OMPI_interface_header_dir  = os.path.join(interface_header_dir, "_OMPI")
    INTEL_INTEL_preload_header_dir    = os.path.join(preload_header_dir,   "INTEL_INTEL")
    INTEL_MPICH_preload_header_dir    = os.path.join(preload_header_dir,   "INTEL_MPICH")
    INTEL_OMPI_preload_header_dir     = os.path.join(preload_header_dir,   "INTEL_OMPI")
    MPICH_INTEL_preload_header_dir    = os.path.join(preload_header_dir,   "MPICH_INTEL")
    MPICH_MPICH_preload_header_dir    = os.path.join(preload_header_dir,   "MPICH_MPICH")
    MPICH_OMPI_preload_header_dir     = os.path.join(preload_header_dir,   "MPICH_OMPI")
    OMPI_INTEL_preload_header_dir     = os.path.join(preload_header_dir,   "OMPI_INTEL")
    OMPI_MPICH_preload_header_dir     = os.path.join(preload_header_dir,   "OMPI_MPICH")
    OMPI_OMPI_preload_header_dir      = os.path.join(preload_header_dir,   "OMPI_OMPI")

    def __init__(self,
                  interface_header_dir       = None,
                  preload_header_dir         = None,
                  MPC_interface_header_dir   = None,
                  INTEL_interface_header_dir = None,
                  MPICH_interface_header_dir = None,
                  OMPI_interface_header_dir  = None,
                  INTEL_INTEL_preload_header_dir    = None,
                  INTEL_MPICH_preload_header_dir    = None,
                  INTEL_OMPI_preload_header_dir     = None,
                  MPICH_INTEL_preload_header_dir    = None,
                  MPICH_MPICH_preload_header_dir    = None,
                  MPICH_OMPI_preload_header_dir     = None,
                  OMPI_INTEL_preload_header_dir     = None,
                  OMPI_MPICH_preload_header_dir     = None,
                  OMPI_OMPI_preload_header_dir      = None,
        ):
        if interface_header_dir:
            self.interface_header_dir       = interface_header_dir
            self.MPC_interface_header_dir   = os.path.join(interface_header_dir, "_MPC")
            self.INTEL_interface_header_dir = os.path.join(interface_header_dir, "_INTEL")
            self.MPICH_interface_header_dir = os.path.join(interface_header_dir, "_MPICH")
            self.OMPI_interface_header_dir  = os.path.join(interface_header_dir, "_OMPI")
        else:
            self.interface_header_dir = self.interface_header_dir
        if preload_header_dir:
            self.preload_header_dir = preload_header_dir
            self.INTEL_INTEL_preload_header_dir    = os.path.join(preload_header_dir,   "INTEL_INTEL")
            self.INTEL_MPICH_preload_header_dir    = os.path.join(preload_header_dir,   "INTEL_MPICH")
            self.INTEL_OMPI_preload_header_dir     = os.path.join(preload_header_dir,   "INTEL_OMPI")
            self.MPICH_INTEL_preload_header_dir    = os.path.join(preload_header_dir,   "MPICH_INTEL")
            self.MPICH_MPICH_preload_header_dir    = os.path.join(preload_header_dir,   "MPICH_MPICH")
            self.MPICH_OMPI_preload_header_dir     = os.path.join(preload_header_dir,   "MPICH_OMPI")
            self.OMPI_INTEL_preload_header_dir     = os.path.join(preload_header_dir,   "OMPI_INTEL")
            self.OMPI_MPICH_preload_header_dir     = os.path.join(preload_header_dir,   "OMPI_MPICH")
            self.OMPI_OMPI_preload_header_dir      = os.path.join(preload_header_dir,   "OMPI_OMPI")
        else:
            self.preload_header_dir = self.preload_header_dir
        self.MPC_interface_header_dir   = MPC_interface_header_dir   if MPC_interface_header_dir   else self.MPC_interface_header_dir
        self.INTEL_interface_header_dir = INTEL_interface_header_dir if INTEL_interface_header_dir else self.INTEL_interface_header_dir
        self.OMPI_interface_header_dir  = OMPI_interface_header_dir  if OMPI_interface_header_dir  else self.OMPI_interface_header_dir
        self.MPICH_interface_header_dir = MPICH_interface_header_dir if MPICH_interface_header_dir else self.MPICH_interface_header_dir
        self.INTEL_INTEL_preload_header_dir    = INTEL_INTEL_preload_header_dir    if INTEL_INTEL_preload_header_dir    else self.INTEL_INTEL_preload_header_dir
        self.INTEL_MPICH_preload_header_dir    = INTEL_MPICH_preload_header_dir    if INTEL_MPICH_preload_header_dir    else self.INTEL_MPICH_preload_header_dir
        self.INTEL_OMPI_preload_header_dir     = INTEL_OMPI_preload_header_dir     if INTEL_OMPI_preload_header_dir     else self.INTEL_OMPI_preload_header_dir
        self.MPICH_INTEL_preload_header_dir    = MPICH_INTEL_preload_header_dir    if MPICH_INTEL_preload_header_dir    else self.MPICH_INTEL_preload_header_dir
        self.MPICH_MPICH_preload_header_dir    = MPICH_MPICH_preload_header_dir    if MPICH_MPICH_preload_header_dir    else self.MPICH_MPICH_preload_header_dir
        self.MPICH_OMPI_preload_header_dir     = MPICH_OMPI_preload_header_dir     if MPICH_OMPI_preload_header_dir     else self.MPICH_OMPI_preload_header_dir
        self.OMPI_INTEL_preload_header_dir     = OMPI_INTEL_preload_header_dir     if OMPI_INTEL_preload_header_dir     else self.OMPI_INTEL_preload_header_dir
        self.OMPI_MPICH_preload_header_dir     = OMPI_MPICH_preload_header_dir     if OMPI_MPICH_preload_header_dir     else self.OMPI_MPICH_preload_header_dir
        self.OMPI_OMPI_preload_header_dir      = OMPI_OMPI_preload_header_dir      if OMPI_OMPI_preload_header_dir      else self.OMPI_OMPI_preload_header_dir

        log.info("Init generator:\n{}\n{}\n{}\n{}\n{}\n{}\n{}\n{}\n{}\n{}\n{}\n{}\n{}".format(
        self.MPC_interface_header_dir   ,
        self.INTEL_interface_header_dir ,
        self.OMPI_interface_header_dir  ,
        self.MPICH_interface_header_dir ,
        self.INTEL_INTEL_preload_header_dir    ,
        self.INTEL_MPICH_preload_header_dir    ,
        self.INTEL_OMPI_preload_header_dir     ,
        self.MPICH_INTEL_preload_header_dir    ,
        self.MPICH_MPICH_preload_header_dir    ,
        self.MPICH_OMPI_preload_header_dir     ,
        self.OMPI_INTEL_preload_header_dir     ,
        self.OMPI_MPICH_preload_header_dir     ,
        self.OMPI_OMPI_preload_header_dir      ,
        ))

    def generate(self):
        """
        Launches the generation process for various header files.
        """
        log.debug("Launching the MPC header generator.")
        genmpc = MpcHeaderGenerator(
            dir_input = os.path.join(wi4mpi_root, "src/interface/header/scripts/mpc_headers"),
            dir_output = self.MPC_interface_header_dir
            )
        genmpc.generate()

        genintel = IntelHeaderGenerator(
            dir_input = os.path.join(wi4mpi_root, "src/interface/header/scripts/intel_headers"),
            dir_output = self.INTEL_interface_header_dir
        )
        genintel.generate()

        genmpich = MpichHeaderGenerator(
            dir_input = os.path.join(wi4mpi_root, "src/interface/header/scripts/mpich_headers"),
            dir_output = self.MPICH_interface_header_dir
        )
        genmpich.generate()

        genompi = OmpiHeaderGenerator(
            dir_input = os.path.join(wi4mpi_root, "src/interface/header/scripts/ompi_headers"),
            dir_output = self.OMPI_interface_header_dir
        )
        genompi.generate()

        genintelintel = IntelIntelHeaderGenerator(
            dir_input = os.path.join(wi4mpi_root, "src/preload/header/scripts/intel_intel_headers"),
            dir_output = self.INTEL_INTEL_preload_header_dir
        )
        genintelintel.generate()

        genintelmpich = IntelMpichHeaderGenerator(
            dir_input = os.path.join(wi4mpi_root, "src/preload/header/scripts/intel_intel_headers"),
            dir_output = self.INTEL_MPICH_preload_header_dir
        )
        genintelmpich.generate()

        genmpichintel = MpichIntelHeaderGenerator(
            dir_input = os.path.join(wi4mpi_root, "src/preload/header/scripts/intel_intel_headers"),
            dir_output = self.MPICH_INTEL_preload_header_dir
        )
        genmpichintel.generate()

        genmpichmpich = MpichMpichHeaderGenerator(
            dir_input = os.path.join(wi4mpi_root, "src/preload/header/scripts/intel_intel_headers"),
            dir_output = self.MPICH_MPICH_preload_header_dir
        )
        genmpichmpich.generate()

        genintelompi = IntelOmpiHeaderGenerator(
            dir_input = os.path.join(wi4mpi_root, "src/preload/header/scripts/intel_ompi_headers"),
            dir_output = self.INTEL_OMPI_preload_header_dir
        )
        genintelompi.generate()

        genmpichompi = MpichOmpiHeaderGenerator(
            dir_input = os.path.join(wi4mpi_root, "src/preload/header/scripts/intel_ompi_headers"),
            dir_output = self.MPICH_OMPI_preload_header_dir
        )
        genmpichompi.generate()

        genompiintel = OmpiIntelHeaderGenerator(
            dir_input = os.path.join(wi4mpi_root, "src/preload/header/scripts/ompi_intel_headers"),
            dir_output = self.OMPI_INTEL_preload_header_dir
        )
        genompiintel.generate()

        genompimpich = OmpiMpichHeaderGenerator(
            dir_input = os.path.join(wi4mpi_root, "src/preload/header/scripts/ompi_intel_headers"),
            dir_output = self.OMPI_MPICH_preload_header_dir
        )
        genompimpich.generate()

        genompiompi = OmpiOmpiHeaderGenerator(
            dir_input = os.path.join(wi4mpi_root, "src/preload/header/scripts/ompi_ompi_headers"),
            dir_output = self.OMPI_OMPI_preload_header_dir
        )
        genompiompi.generate()


if "__main__" == __name__:
    usage = """
    Generate Wi4MPI's headers frome OpenMPI 1.8.8 and MPICH 3.1.2 headers.
    The default directories of generated files are:

      * interface_header_dir = "src/interface/header"
      * preload_header_dir = "src/preload/header"

    Here is an example of use if you do not want to overwrite the files already present:

      ```
      ./generator.py --interface_header_dir=interface_header_gen --preload_header_dir=preload_header_gen
      ```

    This will create two folders inplace, interface_header_gen and preload_header_gen, with generated headers inside.

    Usage:
      generator.py [--interface_header_dir=<interface_header_dir>]
                   [--preload_header_dir=<preload_header_dir>]
                   [--MPC_interface_header_dir=<MPC_interface_header_dir>]
                   [--INTEL_interface_header_dir=<INTEL_interface_header_dir>]
                   [--OMPI_interface_header_dir=<OMPI_interface_header_dir>]
                   [--MPICH_interface_header_dir=<MPICH_interface_header_dir>]
                   [--INTEL_INTEL_preload_header_dir=<INTEL_INTEL_preload_header_dir>]
                   [--INTEL_MPICH_preload_header_dir=<INTEL_MPICH_preload_header_dir>]
                   [--INTEL_OMPI_preload_header_dir=<INTEL_OMPI_preload_header_dir>]
                   [--MPICH_INTEL_preload_header_dir=<MPICH_INTEL_preload_header_dir>]
                   [--MPICH_MPICH_preload_header_dir=<MPICH_MPICH_preload_header_dir>]
                   [--MPICH_OMPI_preload_header_dir=<MPICH_OMPI_preload_header_dir>]
                   [--OMPI_INTEL_preload_header_dir=<OMPI_INTEL_preload_header_dir>]
                   [--OMPI_MPICH_preload_header_dir=<OMPI_MPICH_preload_header_dir>]
                   [--OMPI_OMPI_preload_header_dir=<OMPI_OMPI_preload_header_dir>]
      generator.py (-h | --help)

    Options:
      -h --help                                                          Show this helper.
      --interface_header_dir=<interface_header_dir>                      Path to header interface generation folder.
      --preload_header_dir=<preload_header_dir>                          Path to header preload generation folder.
      --MPC_interface_header_dir=<MPC_interface_header_dir>              Path to MPC header interface generation folder.
      --OMPI_interface_header_dir=<OMPI_interface_header_dir>            Path to OpenMPI header interface generation folder.
      --INTEL_interface_header_dir=<INTEL_interface_header_dir>          Path to INTEL header interface generation folder.
      --MPICH_interface_header_dir=<MPICH_interface_header_dir>          Path to MPICH header interface generation folder.
      --INTEL_INTEL_preload_header_dir=<INTEL_INTEL_preload_header_dir>  Path to INTEL_INTEL header preload generation folder.
      --INTEL_MPICH_preload_header_dir=<INTEL_MPICH_preload_header_dir>  Path to INTEL_MPICH header preload generation folder.
      --INTEL_OMPI_preload_header_dir=<INTEL_OMPI_preload_header_dir>    Path to INTEL_OMPI header preload generation folder.
      --MPICH_INTEL_preload_header_dir=<MPICH_INTEL_preload_header_dir>  Path to MPICH_INTEL header preload generation folder.
      --MPICH_MPICH_preload_header_dir=<MPICH_MPICH_preload_header_dir>  Path to MPICH_MPICH header preload generation folder.
      --MPICH_OMPI_preload_header_dir=<MPICH_OMPI_preload_header_dir>    Path to MPICH_OMPI header preload generation folder.
      --OMPI_INTEL_preload_header_dir=<OMPI_INTEL_preload_header_dir>    Path to OMPI_INTEL header preload generation folder.
      --OMPI_MPICH_preload_header_dir=<OMPI_MPICH_preload_header_dir>    Path to OMPI_MPICH header preload generation folder.
      --OMPI_OMPI_preload_header_dir=<OMPI_OMPI_preload_header_dir>      Path to OMPI_OMPI header preload generation folder.
    """
    arguments = docopt(usage)
    log.info("Starting to generate.")

    run = Generator(
        interface_header_dir              = arguments["--interface_header_dir"],
        preload_header_dir                = arguments["--preload_header_dir"],
        MPC_interface_header_dir   = arguments["--MPC_interface_header_dir"],
        MPICH_interface_header_dir = arguments["--MPICH_interface_header_dir"],
        OMPI_interface_header_dir  = arguments["--OMPI_interface_header_dir"],
        INTEL_interface_header_dir = arguments["--INTEL_interface_header_dir"],
        INTEL_INTEL_preload_header_dir    = arguments["--INTEL_INTEL_preload_header_dir"],
        INTEL_MPICH_preload_header_dir    = arguments["--INTEL_MPICH_preload_header_dir"],
        INTEL_OMPI_preload_header_dir     = arguments["--INTEL_OMPI_preload_header_dir"],
        MPICH_INTEL_preload_header_dir    = arguments["--MPICH_INTEL_preload_header_dir"],
        MPICH_MPICH_preload_header_dir    = arguments["--MPICH_MPICH_preload_header_dir"],
        MPICH_OMPI_preload_header_dir     = arguments["--MPICH_OMPI_preload_header_dir"],
        OMPI_INTEL_preload_header_dir     = arguments["--OMPI_INTEL_preload_header_dir"],
        OMPI_MPICH_preload_header_dir     = arguments["--OMPI_MPICH_preload_header_dir"],
        OMPI_OMPI_preload_header_dir      = arguments["--OMPI_OMPI_preload_header_dir"],
        )
    run.generate()
    log.info("End")

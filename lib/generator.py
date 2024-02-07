#!/usr/bin/env python3
"""
Wi4MPI Header Generator

This script generates Wi4MPI's headers from OpenMPI 1.8.8 and MPICH 3.1.2 headers.

Usage:
  generator.py [--interface_header_dir=<interface_header_dir>]
               [--preload_header_dir=<preload_header_dir>]
  generator.py (-h | --help)

Options:
  -h --help                             Show this help message.
  --interface_header_dir=<interface_header_dir>   Path to header interface generation folder.
  --preload_header_dir=<preload_header_dir>       Path to header preload generation folder.

Examples:
  1. Generate headers using default directories:
      ```
      ./generator.py
      ```
  2. Specify custom directories for generated files:
      ```
      ./generator.py --interface_header_dir=interface_header_gen \
                     --preload_header_dir=preload_header_gen
      ```

Description:
  This script initializes the Wi4MPI Header Generator with optional directory parameters.
  It launches the generation process for various header files by instantiating specific generators.

  Default directories for generated files:
  - interface_header_dir: "src/interface/header"
  - preload_header_dir: "src/preload/header"

  The generated headers are placed in subdirectories starting with underscores, such as "_MPC",
  "_INTEL", etc.

  The script can be run from the command line, and options can be provided to specify custom genera
  tion directories.

Authors:
  Cotte Adrien - Alliance Service Plus - adrien.cotte.tgcc@cea.fr
  Debusschère Lydéric - Alliance Service Plus - lyderic.debusschere.tgcc.@cea.fr
  Ducrot Vincent - Alliance Service Plus - vincent.ducrot.tgcc@cea.fr
  Joos Marc - CEA - marc.joos@cea.fr
"""

import os
from logging import getLogger
from logging.config import fileConfig
from docopt import docopt
from mpcheader import MpcHeaderGenerator
from intelheader import IntelHeaderGenerator
from mpichheader import MpichHeaderGenerator
from ompiheader import OmpiHeaderGenerator
from intelintelheader import IntelIntelHeaderGenerator
from intelmpichheader import IntelMpichHeaderGenerator
from mpichintelheader import MpichIntelHeaderGenerator
from mpichmpichheader import MpichMpichHeaderGenerator
from intelompiheader import IntelOmpiHeaderGenerator
from mpichompiheader import MpichOmpiHeaderGenerator
from ompiintelheader import OmpiIntelHeaderGenerator
from ompimpichheader import OmpiMpichHeaderGenerator
from ompiompiheader import OmpiOmpiHeaderGenerator

fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)), "logging.conf"))
log = getLogger("generator_logger")

# Absolute path of this script
wi4mpi_root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


class Generator:
    """
    Initializes the Generator with optional directory parameters.

    Args:
        interface_header_dir (str, optional): Directory for interface headers.
        preload_header_dir (str, optional): Directory for preload headers.
    """

    interface_header_dir = "src/interface/header"
    preload_header_dir = "src/preload/header"

    def __init__(self, **kwargs):
        self.set_directories(**kwargs)

    def set_directories(self, **kwargs):
        """
        Sets the directory parameters for the Generator.

        Args:
            **kwargs (dict): A dictionary containing optional parameters.
                - "interface_header_dir" (str, optional): Directory for interface headers.
                - "preload_header_dir" (str, optional): Directory for preload headers.

        Returns:
            None

        Example:
            >>> my_generator = Generator()
            >>> my_generator.set_directories(interface_header_dir="new_interface_dir",
                    preload_header_dir="new_preload_dir")
        """
        self.interface_header_dir = kwargs.get("interface_header_dir", self.interface_header_dir)
        self.preload_header_dir = kwargs.get("preload_header_dir", self.preload_header_dir)

    def generate(self):
        """
        Launches the generation process for various header files.
        """
        log.debug("Launching the MPC header generator.")
        genmpc = MpcHeaderGenerator(
            dir_input=os.path.join(wi4mpi_root, "src/interface/header/scripts/mpc_headers"),
            dir_output=os.path.join(self.interface_header_dir, "_MPC"),
        )
        genmpc.generate()

        genintel = IntelHeaderGenerator(
            dir_input=os.path.join(wi4mpi_root, "src/interface/header/scripts/intel_headers"),
            dir_output=os.path.join(self.interface_header_dir, "_INTEL"),
        )
        genintel.generate()

        genmpich = MpichHeaderGenerator(
            dir_input=os.path.join(wi4mpi_root, "src/interface/header/scripts/mpich_headers"),
            dir_output=os.path.join(self.interface_header_dir, "_MPICH"),
        )
        genmpich.generate()

        genompi = OmpiHeaderGenerator(
            dir_input=os.path.join(wi4mpi_root, "src/interface/header/scripts/ompi_headers"),
            dir_output=os.path.join(self.interface_header_dir, "_OMPI"),
        )
        genompi.generate()

        genintelintel = IntelIntelHeaderGenerator(
            dir_input=os.path.join(wi4mpi_root, "src/preload/header/scripts/intel_intel_headers"),
            dir_output=os.path.join(self.preload_header_dir, "INTEL_INTEL"),
        )
        genintelintel.generate()

        genintelmpich = IntelMpichHeaderGenerator(
            dir_input=os.path.join(wi4mpi_root, "src/preload/header/scripts/intel_intel_headers"),
            dir_output=os.path.join(self.preload_header_dir, "INTEL_MPICH"),
        )
        genintelmpich.generate()

        genmpichintel = MpichIntelHeaderGenerator(
            dir_input=os.path.join(wi4mpi_root, "src/preload/header/scripts/intel_intel_headers"),
            dir_output=os.path.join(self.preload_header_dir, "MPICH_INTEL"),
        )
        genmpichintel.generate()

        genmpichmpich = MpichMpichHeaderGenerator(
            dir_input=os.path.join(wi4mpi_root, "src/preload/header/scripts/intel_intel_headers"),
            dir_output=os.path.join(self.preload_header_dir, "MPICH_MPICH"),
        )
        genmpichmpich.generate()

        genintelompi = IntelOmpiHeaderGenerator(
            dir_input=os.path.join(wi4mpi_root, "src/preload/header/scripts/intel_ompi_headers"),
            dir_output=os.path.join(self.preload_header_dir, "INTEL_OMPI"),
        )
        genintelompi.generate()

        genmpichompi = MpichOmpiHeaderGenerator(
            dir_input=os.path.join(wi4mpi_root, "src/preload/header/scripts/intel_ompi_headers"),
            dir_output=os.path.join(self.preload_header_dir, "MPICH_OMPI"),
        )
        genmpichompi.generate()

        genompiintel = OmpiIntelHeaderGenerator(
            dir_input=os.path.join(wi4mpi_root, "src/preload/header/scripts/ompi_intel_headers"),
            dir_output=os.path.join(self.preload_header_dir, "OMPI_INTEL"),
        )
        genompiintel.generate()

        genompimpich = OmpiMpichHeaderGenerator(
            dir_input=os.path.join(wi4mpi_root, "src/preload/header/scripts/ompi_intel_headers"),
            dir_output=os.path.join(self.preload_header_dir, "OMPI_MPICH"),
        )
        genompimpich.generate()

        genompiompi = OmpiOmpiHeaderGenerator(
            dir_input=os.path.join(wi4mpi_root, "src/preload/header/scripts/ompi_ompi_headers"),
            dir_output=os.path.join(self.preload_header_dir, "OMPI_OMPI"),
        )
        genompiompi.generate()


if "__main__" == __name__:
    USAGE = """
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
      generator.py (-h | --help)

    Options:
      -h --help                                                          Show this helper.
      --interface_header_dir=<interface_header_dir>                      Path to header interface generation folder.
      --preload_header_dir=<preload_header_dir>                          Path to header preload generation folder.
    """  # noqa: E501
    arguments = docopt(USAGE)
    log.info("Starting to generate.")
    args = {
        "interface_header_dir": arguments["--interface_header_dir"],
        "preload_header_dir": arguments["--preload_header_dir"],
    }
    run = Generator(**args)
    run.generate()
    log.info("End")

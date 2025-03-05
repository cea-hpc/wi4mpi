#!/usr/bin/env python3
"""
Wi4MPI Header Generator

This script generates Wi4MPI's headers from OpenMPI, MPICH, IntelMPI and MPC headers.

Usage:
  generator.py [--interface_header_dir=<interface_header_dir>]
               [--preload_header_dir=<preload_header_dir>]
               [--c_preload_gen_dir=<c_preload_gen_dir>]
               [--c_interface_gen_dir=<c_interface_gen_dir>]
               [--openmpi_version=<openmpi_version>]
               [--mpich_version=<mpich_version>]
               [--intelmpi_version=<intelmpi_version>]
  generator.py (-h | --help)

Arguments:
  interface_header_dir  Path to header interface generation folder.
  preload_header_dir    Path to header preload generation folder.
  c_preload_gen_dir     Path to C preload generation folder.
  c_interface_gen_dir   Path to C interface generation folder.
  openmpi_version       Version of the target Open MPI
                        Supported versions:
                            * 1.8.8 (alias: 1)
                            * 2.1.6 (alias: 2)
                            * 4.1.6 (alias: 4)
                            * 5.0.3 (alias: 5)
  mpich_version         Version of the target MPICH
                        Supported versions:
                            * 3.1.2
                            * 3.4.3 (alias: 3)
                            * 4.2.0 (alias: 4)
  intelmpi_version      Version of the target Intel MPI
                        Supported versions:
                            * 20.0.0 (alias: 20)
                            * 24.0.0 (alias: 24)

Options:
  -h --help                                                          Show this helper.
  --interface_header_dir=<interface_header_dir>                      Set interface_header_dir
  --preload_header_dir=<preload_header_dir>                          Set preload_header_dir
  --c_preload_gen_dir=<c_preload_gen_dir>                            Set c_preload_gen_dir
  --c_interface_gen_dir=<c_interface_gen_dir>                        Set c_interface_gen_dir
  --openmpi_version=<openmpi_version>                                Set openmpi_version
  --mpich_version=<mpich_version>                                    Set mpich_version
  --intelmpi_version=<intelmpi_version>                              Set intelmpi_version

Examples:
  1. Generate headers using default directories:
      ```
      ./generator.py
      ```
  2. Specify custom directories for generated files:
      ```
      ./generator.py --interface_header_dir=interface_header_gen \
                     --preload_header_dir=preload_header_gen \
                     --c_preload_gen_dir=c_preload_gen_dir
      ```
  3. Sprecifiy custom versions for base headers:
      ```
      ./generator.py --openmpi_version=2 \
                     --mpich_version=3.1.2 \
                     --intelmpi_version=24
      ```

Description:
  This script initializes the Wi4MPI Header Generator with optional directory parameters.
  It launches the generation process for various header files by instantiating specific generators.

  Default directories for generated files:
  - interface_header_dir: "src/interface/header"
  - preload_header_dir: "src/preload/header"
  - c_preload_gen_dir: "src/preload/gen"
  - c_interface_gen_dir: "src/interface/gen"

  The generated headers are placed in subdirectories starting with underscores, such as "_MPC",
  "_INTEL", etc.

  The script can be run from the command line, and options can be provided to specify custom 
  generation directories.

Authors:
  Cotte Adrien - Alliance Service Plus - adrien.cotte.tgcc@cea.fr
  Debusschère Lydéric - Alliance Service Plus - lyderic.debusschere.tgcc.@cea.fr
  Ducrot Vincent - Alliance Service Plus - vincent.ducrot.tgcc@cea.fr
  Joos Marc - CEA - marc.joos@cea.fr
"""

import os
import re
import sys
from logging import getLogger
from logging.config import fileConfig
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
from cpreloadgenerator import CPreloadGenerator
from cinterfacegenerator import CInterfaceGenerator
from fortranpreloadgenerator import FortranPreloadGenerator
from fortraninterfacegenerator import FortranInterfaceGenerator
from docopt import docopt

fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)), "logging.conf"))
log = getLogger("generator_logger")

# Absolute path of this script
wi4mpi_root = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))


class Generator:
    """
    Initializes the Generator with optional directory parameters.

    Args:
        interface_header_dir (str, optional): Directory for interface headers.
        preload_header_dir (str, optional): Directory for preload headers.
        c_preload_gen_dir (str, optional): Directory for preload C code.
        c_interface_gen_dir (str,optional): Directory for interface C code.
        mpi_target_version (dict): Contains selected versions of MPI implementations.
        mpi_available_target_version (dict): Contains available versions of MPI implementations.
        alias_openmpi (dict): Contains available aliases for Open MPI
        alias_mpich (dict): Contains available aliases for MPIC
        alias_intelmpi (dict): Contains available aliases for Intel MPI

    Methods:
        __init__: Call set_directories and set mpi_target_version
        set_directories: Sets the directory parameters for the Generator.
        generate_header: Launches the generation process for various header files.
        generate_code: Launches the generation process for various code files.
        generate: Launches the generation process for header and code files.
    """

    interface_header_dir = "src/interface/header"
    preload_header_dir = "src/preload/header"
    c_preload_gen_dir = "src/preload/gen"
    c_interface_gen_dir = "src/interface/gen"
    mpi_target_version = {
        "openmpi": "5.0.3",
        "mpich": "4.2.0",
        "intelmpi": "24.0.0",
    }
    mpi_availabe_target_version = {
        "openmpi": ["1.8.8", "2.1.6", "4.1.6", "5.0.3"],
        "mpich": ["3.1.2", "3.4.3", "4.2.0"],
        "intelmpi": ["20.0.0", "24.0.0"],
    }
    alias_openmpi = {
        "1": "1.8.8",
        "2": "2.1.6",
        "4": "4.1.6",
        "5": "5.0.3",
    }
    alias_mpich = {
        "3": "3.4.3",
        "4": "4.2.0",
    }
    alias_intelmpi = {
        "20": "20.0.0",
        "24": "24.0.0",
    }
    mpi_norm = "3.1"
    mpi_availabe_norm = [ "1.0", "1.1", "1.2", "2.0", "2.1", "2.2", "3.0", "3.1", "4.0"]

    def __init__(self, **kwargs):
        self.set_directories(**kwargs)
        bool_openmpi_version = False
        bool_mpich_version = False
        bool_intelmpi_version = False
        bool_mpi_norm = False
        self.mpi_norm = kwargs.get("mpi_norm", self.mpi_norm)
        self.mpi_target_version["openmpi"] = kwargs.get(
            "openmpi_version",
            self.mpi_target_version["openmpi"],
        )
        if self.mpi_target_version["openmpi"] in (list(self.alias_openmpi.keys()) + self.mpi_availabe_target_version["openmpi"]):
           if self.mpi_target_version["openmpi"] in self.alias_openmpi.keys():
              self.mpi_target_version["openmpi"] = self.alias_openmpi[self.mpi_target_version["openmpi"]]
           bool_openmpi_version = True
        else:
            _msg = f"Open MPI {self.mpi_target_version['openmpi']} is not available."
            log.error(_msg)
        self.mpi_target_version["mpich"] = kwargs.get(
            "mpich_version",
            self.mpi_target_version["mpich"],
        )
        if self.mpi_target_version["mpich"] in (list(self.alias_mpich.keys()) + self.mpi_availabe_target_version["mpich"]):
           if self.mpi_target_version["mpich"] in self.alias_mpich.keys():
              self.mpi_target_version["mpich"] = self.alias_mpich[self.mpi_target_version["mpich"]]
           bool_mpich_version = True
        else:
            _msg = f"MPICH {self.mpi_target_version['mpich']} is not available."
            log.error(_msg)
        self.mpi_target_version["intelmpi"] = kwargs.get(
            "intelmpi_version",
            self.mpi_target_version["intelmpi"],
        )
        if self.mpi_target_version["intelmpi"] in (list(self.alias_intelmpi.keys()) + self.mpi_availabe_target_version["intelmpi"]):
           if self.mpi_target_version["intelmpi"] in self.alias_intelmpi.keys():
              self.mpi_target_version["intelmpi"] = self.alias_intelmpi[self.mpi_target_version["intelmpi"]]
           bool_intelmpi_version = True
        else:
            _msg = f"Intel MPI {self.mpi_target_version['intelmpi']} is not available."
            log.error(_msg)
        if self.mpi_norm in self.mpi_availabe_norm:
            bool_mpi_norm = True
        else:
            _msg = f"MPI {self.mpi_norm} is not supported."
            log.error(_msg)
        bool_exit = True
        bool_exit &= bool_openmpi_version
        bool_exit &= bool_mpich_version
        bool_exit &= bool_intelmpi_version
        bool_exit &= bool_mpi_norm
        if not (bool_exit):
            log.error("MPI configuration not available.")
            sys.exit(1)

    def set_directories(self, **kwargs):
        """
        Sets the directory parameters for the Generator.

        Args:
            **kwargs (dict): A dictionary containing optional parameters.
                - "interface_header_dir" (str, optional): Directory for interface headers.
                - "preload_header_dir" (str, optional): Directory for preload headers.
                - "c_preload_gen_dir" (str, optional): Directory for preload C code.

        Returns:
            None

        Example:
            >>> my_generator = Generator()
            >>> my_generator.set_directories(interface_header_dir="new_interface_dir",
                    preload_header_dir="new_preload_dir")
        """
        self.interface_header_dir = kwargs.get("interface_header_dir", self.interface_header_dir)
        self.preload_header_dir = kwargs.get("preload_header_dir", self.preload_header_dir)
        self.c_preload_gen_dir = kwargs.get("c_preload_gen_dir", self.c_preload_gen_dir)
        self.c_interface_gen_dir = kwargs.get("c_interface_gen_dir", self.c_interface_gen_dir)

    def generate_header(self):
        """
        Launches the generation process for various header files.
        """
        log.debug("Launching the MPC header generator.")
        genmpc = MpcHeaderGenerator(
            dir_input=os.path.join(wi4mpi_root, "src/interface/header/scripts/mpc_headers"),
            dir_output=os.path.join(self.interface_header_dir, "_MPC"),
            mpi_target_version=self.mpi_target_version,
        )
        genmpc.generate()

        genintel = IntelHeaderGenerator(
            dir_input=os.path.join(wi4mpi_root, "src/interface/header/scripts/intel_headers"),
            dir_output=os.path.join(self.interface_header_dir, "_INTEL"),
            mpi_target_version=self.mpi_target_version,
        )
        genintel.generate()

        genmpich = MpichHeaderGenerator(
            dir_input=os.path.join(wi4mpi_root, "src/interface/header/scripts/mpich_headers"),
            dir_output=os.path.join(self.interface_header_dir, "_MPICH"),
            mpi_target_version=self.mpi_target_version,
        )
        genmpich.generate()

        genompi = OmpiHeaderGenerator(
            dir_input=os.path.join(wi4mpi_root, "src/interface/header/scripts/ompi_headers"),
            dir_output=os.path.join(self.interface_header_dir, "_OMPI"),
            mpi_target_version=self.mpi_target_version,
        )
        genompi.generate()

        genintelintel = IntelIntelHeaderGenerator(
            dir_input=os.path.join(wi4mpi_root, "src/preload/header/scripts/intel_intel_headers"),
            dir_output=os.path.join(self.preload_header_dir, "INTEL_INTEL"),
            mpi_target_version=self.mpi_target_version,
        )
        genintelintel.generate()

        genintelmpich = IntelMpichHeaderGenerator(
            dir_input=os.path.join(wi4mpi_root, "src/preload/header/scripts/intel_mpich_headers"),
            dir_output=os.path.join(self.preload_header_dir, "INTEL_MPICH"),
            mpi_target_version=self.mpi_target_version,
        )
        genintelmpich.generate()

        genmpichintel = MpichIntelHeaderGenerator(
            dir_input=os.path.join(wi4mpi_root, "src/preload/header/scripts/mpich_intel_headers"),
            dir_output=os.path.join(self.preload_header_dir, "MPICH_INTEL"),
            mpi_target_version=self.mpi_target_version,
        )
        genmpichintel.generate()

        genmpichmpich = MpichMpichHeaderGenerator(
            dir_input=os.path.join(wi4mpi_root, "src/preload/header/scripts/mpich_mpich_headers"),
            dir_output=os.path.join(self.preload_header_dir, "MPICH_MPICH"),
            mpi_target_version=self.mpi_target_version,
        )
        genmpichmpich.generate()

        genintelompi = IntelOmpiHeaderGenerator(
            dir_input=os.path.join(wi4mpi_root, "src/preload/header/scripts/intel_ompi_headers"),
            dir_output=os.path.join(self.preload_header_dir, "INTEL_OMPI"),
            mpi_target_version=self.mpi_target_version,
        )
        genintelompi.generate()

        genmpichompi = MpichOmpiHeaderGenerator(
            dir_input=os.path.join(wi4mpi_root, "src/preload/header/scripts/mpich_ompi_headers"),
            dir_output=os.path.join(self.preload_header_dir, "MPICH_OMPI"),
            mpi_target_version=self.mpi_target_version,
        )
        genmpichompi.generate()

        genompiintel = OmpiIntelHeaderGenerator(
            dir_input=os.path.join(wi4mpi_root, "src/preload/header/scripts/ompi_intel_headers"),
            dir_output=os.path.join(self.preload_header_dir, "OMPI_INTEL"),
            mpi_target_version=self.mpi_target_version,
        )
        genompiintel.generate()

        genompimpich = OmpiMpichHeaderGenerator(
            dir_input=os.path.join(wi4mpi_root, "src/preload/header/scripts/ompi_mpich_headers"),
            dir_output=os.path.join(self.preload_header_dir, "OMPI_MPICH"),
            mpi_target_version=self.mpi_target_version,
        )
        genompimpich.generate()

        genompiompi = OmpiOmpiHeaderGenerator(
            dir_input=os.path.join(wi4mpi_root, "src/preload/header/scripts/ompi_ompi_headers"),
            dir_output=os.path.join(self.preload_header_dir, "OMPI_OMPI"),
            mpi_target_version=self.mpi_target_version,
        )
        genompiompi.generate()

    def generate_code(self):
        """
        Launches the generation process for various code files.
        """
        gencpreload = CPreloadGenerator(
            dir_input=os.path.join(wi4mpi_root, "src/generator/etc/code/C"),
            dir_output=self.c_preload_gen_dir,
            mpi_norm=self.mpi_norm,
        )
        gencpreload.generate()
        gencinterface = CInterfaceGenerator(
            dir_input=os.path.join(wi4mpi_root, "src/generator/etc/code/C"),
            dir_output=self.c_interface_gen_dir,
            mpi_norm=self.mpi_norm,
        )
        gencinterface.generate()
        genfortpreload = FortranPreloadGenerator(
            dir_input=os.path.join(wi4mpi_root, "src/generator/etc/code/fortran"),
            dir_output=self.c_preload_gen_dir,
        )
        genfortpreload.generate()
        genfortinterface = FortranInterfaceGenerator(
            dir_input=os.path.join(wi4mpi_root, "src/generator/etc/code/fortran"),
            dir_output=self.c_interface_gen_dir,
        )
        genfortinterface.generate()

    def generate(self):
        """
        Launches the generation process for header and code files.
        """
        self.generate_header()
        self.generate_code()


if "__main__" == __name__:
    # Remark: Docopt scans for lines that start with '-' when searching for description of options.
    #         That is why if one of the lines in usage starts with dash it is misinterpreted as
    #         being a separate description of an option.
    #         cf. https://github.com/docopt/docopt/issues/130
    #         This is the reason why there are '$' in 'Examples' section. This behaviour could
    #         change in recent version.
    #
    USAGE = """
    Generate Wi4MPI's headers from user defined headers.
    The default directories of generated files are:

      * interface_header_dir = "src/interface/header"
      * preload_header_dir = "src/preload/header"

    Usage:
      generator.py [--interface_header_dir=<interface_header_dir>]
                   [--preload_header_dir=<preload_header_dir>]
                   [--c_preload_gen_dir=<c_preload_gen_dir>]
                   [--c_interface_gen_dir=<c_interface_gen_dir>]
                   [--openmpi_version=<openmpi_version>]
                   [--mpich_version=<mpich_version>]
                   [--intelmpi_version=<intelmpi_version>]
                   [--mpi_norm=<mpi_norm>]
      generator.py (-h | --help)

    Examples:
        Here is an example of use if you do not want to overwrite the files already present:
        $ ./src/generator/generator.py --interface_header_dir=interface_header_gen
        $                    --preload_header_dir=preload_header_gen
        $                    --c_preload_gen_dir=c_preload_gen_dir

        This will create two folders inplace, interface_header_gen and preload_header_gen, with 
        generated headers inside.

    Arguments:
      interface_header_dir  Path to header interface generation folder.
      preload_header_dir    Path to header preload generation folder.
      c_preload_gen_dir     Path to C preload generation folder.
      c_interface_gen_dir   Path to C interface generation folder.
      openmpi_version       Version of the target Open MPI
                            Supported versions:
                                * 1.8.8 (alias: 1)
                                * 2.1.6 (alias: 2)
                                * 4.1.6 (alias: 4)
                                * 5.0.3 (alias: 5)
      mpich_version         Version of the target MPICH
                            Supported versions:
                                * 3.1.2
                                * 3.4.3 (alias: 3)
                                * 4.2.0 (alias: 4)
      intelmpi_version      Version of the target Intel MPI
                            Supported versions:
                                * 20.0.0 (alias: 20)
                                * 24.0.0 (alias: 24)
      mpi_norm              Version of the MPI norm to use
                            Supported versions:
                                * 1.0 1.1
                                * 2.0 2.1 2.2
                                * 3.0 3.1
                                * 4.0

    Options:
      -h --help                                                          Show this helper.
      --interface_header_dir=<interface_header_dir>                      Path to header interface generation folder.
      --preload_header_dir=<preload_header_dir>                          Path to header preload generation folder.
      --c_preload_gen_dir=<c_preload_gen_dir>                            Path to C preload generation folder.
      --c_interface_gen_dir=<c_interface_gen_dir>                        Path to C interface generation folder.
      --openmpi_version=<openmpi_version>                                Version of the target OpenMPI
      --mpich_version=<mpich_version>                                    Version of the target MPICH
      --intelmpi_version=<intelmpi_version>                              Version of the target IntelMPI
      --mpi_norm=<mpi_norm>                                              Version of MPI norm to use
    """  # noqa: E501
    arguments = docopt(USAGE)
    log.info("Starting to generate.")
    args = {
        "interface_header_dir": arguments["--interface_header_dir"],
        "preload_header_dir": arguments["--preload_header_dir"],
        "c_preload_gen_dir": arguments["--c_preload_gen_dir"],
        "c_interface_gen_dir": arguments["--c_interface_gen_dir"],
        "openmpi_version": arguments["--openmpi_version"],
        "mpich_version": arguments["--mpich_version"],
        "intelmpi_version": arguments["--intelmpi_version"],
        "mpi_norm": arguments["--mpi_norm"],
    }
    # Delete keys that have a value of None
    none_list = []
    for key, value in args.items():
        if value is None:
            none_list.append(key)
        elif isinstance(value, str):
            args[key] = re.sub(r"['\"]", "", value)
    for key in none_list:
        args.pop(key)

    run = Generator(**args)
    run.generate()
    log.info("End")
    sys.exit(0)

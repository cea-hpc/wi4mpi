#!/usr/bin/env python3
"""
MpichHeader module for generating Mpich interface header files.
"""

import os
import re
import shutil
from logging import getLogger
from logging.config import fileConfig
from intelheader import IntelHeaderGenerator

fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)), "logging.conf"))
log = getLogger("header_logger")

COPYRIGHT_MPICH_MPIH = """
//############################# Wi4MPI License ###########################
//# Copyright or (C) or Copr. Commissariat a l'Energie Atomique          #
//#                                                                      #
//# IDDN.FR.001.210022.000.S.P.2014.000.10800                            #
//# This file is part of the Wi4MPI library.                             #
//#                                                                      #
//# SPDX-License-Identifier: BSD-3-Clause OR CeCILL-B                    #
//#                                                                      #
//########################################################################
/*
 *  (C) 2001 by Argonne National Laboratory.

              MPICH2 COPYRIGHT

    The following is a notice of limited availability of the code, and disclaimer
    which must be included in the prologue of the code and in all source listings
    of the code.

    Copyright Notice
     + 2002 University of Chicago

    Permission is hereby granted to use, reproduce, prepare derivative works, and
    to redistribute to others.  This software was authored by:

    Mathematics and Computer Science Division
    Argonne National Laboratory, Argonne IL 60439

    (and)

    Department of Computer Science
    University of Illinois at Urbana-Champaign


             GOVERNMENT LICENSE

    Portions of this material resulted from work developed under a U.S.
    Government Contract and are subject to the following license: the Government
    is granted for itself and others acting on its behalf a paid-up, nonexclusive,
    irrevocable worldwide license in this computer software to reproduce, prepare
    derivative works, and perform publicly and display publicly.

             DISCLAIMER

    This computer code material was prepared, in part, as an account of work
    sponsored by an agency of the United States Government.  Neither the United
    States, nor the University of Chicago, nor any of their employees, makes any
    warranty express or implied, or assumes any legal liability or responsibility
    for the accuracy, completeness, or usefulness of any information, apparatus,
    product, or process disclosed, or represents that its use would not infringe
    privately owned rights.

 *
 */
"""

COPYRIGHT_MPICH_MPIOH = """
//############################# Wi4MPI License ###########################
//# Copyright or (C) or Copr. Commissariat a l'Energie Atomique          #
//#                                                                      #
//# IDDN.FR.001.210022.000.S.P.2014.000.10800                            #
//# This file is part of the Wi4MPI library.                             #
//#                                                                      #
//# SPDX-License-Identifier: BSD-3-Clause OR CeCILL-B                    #
//#                                                                      #
//########################################################################
/*
 *
 *   Copyright (C) 1997 University of Chicago.

             MPICH2 COPYRIGHT

    The following is a notice of limited availability of the code, and disclaimer
    which must be included in the prologue of the code and in all source listings
    of the code.

    Copyright Notice
     + 2002 University of Chicago

    Permission is hereby granted to use, reproduce, prepare derivative works, and
    to redistribute to others.  This software was authored by:

    Mathematics and Computer Science Division
    Argonne National Laboratory, Argonne IL 60439

    (and)

    Department of Computer Science
    University of Illinois at Urbana-Champaign


             GOVERNMENT LICENSE

    Portions of this material resulted from work developed under a U.S.
    Government Contract and are subject to the following license: the Government
    is granted for itself and others acting on its behalf a paid-up, nonexclusive,
    irrevocable worldwide license in this computer software to reproduce, prepare
    derivative works, and perform publicly and display publicly.

             DISCLAIMER

    This computer code material was prepared, in part, as an account of work
    sponsored by an agency of the United States Government.  Neither the United
    States, nor the University of Chicago, nor any of their employees, makes any
    warranty express or implied, or assumes any legal liability or responsibility
    for the accuracy, completeness, or usefulness of any information, apparatus,
    product, or process disclosed, or represents that its use would not infringe
    privately owned rights.

 *
 */
"""


class MpichHeaderGenerator(IntelHeaderGenerator):
    """
    MpichHeaderGenerator class for generating Mpich interface header files.
    """

    app = None
    run = "mpich"

    def _generate_wrapper_fh(self, gen_file):
        """
        Generates the wrapper_f.h file.

        Args:
            gen_file (str): The path to the generated file.
        """
        log.debug("Running _generate_wrapper_fh (MpichHeaderGenerator).")

        def _msg(wrapper_f):
            return f"Using {wrapper_f}"

        if not os.path.exists(gen_file):
            wrapper_f = os.path.join(self.dir_input, "wrapper_f.h")
            log.warning(_msg(wrapper_f))
            shutil.copy2(os.path.join(self.dir_input, "wrapper_f.h"), gen_file)

    def mpich_copyright(self, text):
        """
        Add the copyright in Mpich header.
        """
        _pattern_block = """
/*  
 *  (C) 2001 by Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */
"""
        _replacement_block = COPYRIGHT_MPICH_MPIH
        text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)
        return text

    def mpich_generate_run_mpih(self, gen_file):
        """
        Generates the run_mpi.h file with Intel-specific modifications.

        Args:
            gen_file (str): The path to the generated file.
        """
        log.debug("Running _generate_run_mpih (IntelHeaderGenerator).")
        super()._generate_run_mpih(gen_file)
        with open(gen_file, "r", encoding="utf-8") as _file:
            _content = _file.read()
        _new_content = self.mpich_copyright(_content)
        with open(gen_file, "w", encoding="utf-8") as _file:
            _file.write(_new_content)

    def _generate_run_mpih(self, gen_file):
        """
        Generates the run_mpi.h file.

        Args:
            gen_file (str): The path to the generated file.
        """
        self.mpich_generate_run_mpih(gen_file)

    def mpich_exceptions_run_mpioh(self, text):
        """
        Applies MPICH-specific exceptions for run_mpioh file.

        Args:
            text (str): The content of the file.

        Returns:
            str: The modified content.
        """
        log.debug("Running mpich_exceptions_run_mpioh (IntelHeaderGenerator).")
        _pattern_block = """
/* 
 *
 *   Copyright (C) 1997 University of Chicago. 
 *   See COPYRIGHT notice in top-level directory.
 */
"""
        _replacement_block = COPYRIGHT_MPICH_MPIOH
        text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)
        return text

    def _generate_run_mpioh(self, gen_file):
        """
        Generates the run_mpio.h file with Intel-specific modifications.

        Args:
            gen_file (str): The path to the generated file.
        """
        log.debug("Running _generate_run_mpioh (IntelHeaderGenerator).")
        super()._generate_run_mpioh(gen_file)
        with open(gen_file, "r", encoding="utf-8") as _file:
            _content = _file.read()

        _new_content = self.mpich_exceptions_run_mpioh(_content)
        with open(gen_file, "w", encoding="utf-8") as _file:
            _file.write(_new_content)

    def _mpich_exception_run_mpi_protoh(self, text):
        log.debug("Running _mpich_exception_run_mpi_protoh (IntelHeaderGenerator).")
        text = re.sub(r"const ", "", text)
        text = re.sub(r"R_MPIX_Iov", "MPIX_Iov", text)
        text = re.sub(r"R_MPIX_Stream", "MPIX_Stream", text)
        text = re.sub(r"R_MPIX_Grequest_poll_function", "MPIX_Grequest_poll_function", text)
        text = re.sub(r"R_MPIX_Grequest_class", "MPIX_Grequest_class", text)
        text = re.sub(r"R_MPIX_Grequest_wait_function", "MPIX_Grequest_wait_function", text)
        text = re.sub(r"R_MPIX_Grequest_class", "MPIX_Grequest_class", text)
        text = re.sub(r"R_MPIX_Grequest_poll_function", "MPIX_Grequest_poll_function", text)
        text = re.sub(r"R_MPIX_Grequest_wait_function", "MPIX_Grequest_wait_function", text)
        text = re.sub(r"R_MPIX_Grequest_class", "MPIX_Grequest_class", text)
        text = re.sub(r"QMPIX_", "R_QMPIX_", text)
        return text

    def _generate_run_mpi_protoh(self, gen_file):
        if "4.2.0" == self.mpi_target_version["mpich"]:
            log.debug("Running _generate_run_mpi_protoh (IntelGenerator)")
            with open(gen_file, "r", encoding="utf-8") as _file:
                _content = _file.read()

            _new_content = self._replace_mpi_with_rmpi(_content)
            _new_content = self._mpich_exception_run_mpi_protoh(_new_content)
            with open(gen_file, "w", encoding="utf-8") as _file:
                _file.write(_new_content)
        else:
            pass

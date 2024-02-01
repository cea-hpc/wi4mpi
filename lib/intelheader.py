#!/usr/bin/env python3

import os
import shutil
import re
from logging import getLogger
from logging.config import fileConfig
from header import HeaderGenerator
from textoperator import delete_lines, delete_line_from_pattern, insert_lines, function_to_delete

fileConfig(os.path.join(os.path.dirname(os.path.abspath(__file__)),"logging.conf"))
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

class IntelHeaderGenerator(HeaderGenerator):

    dir_output = ""
    dir_input = ""
    
    def __init__(self,
                 dir_input = "src/interface/header/scripts/mpc_headers",
                 dir_output = "src/interface/header/_INTEL_gen"
                 ):
        log.info("Generation of INTEL headers in progress.")
        self.dir_input = dir_input 
        self.dir_output = dir_output
        os.makedirs(self.dir_output, exist_ok=True)

    def _generate_wrapper_fh(self, gen_file):
        log.debug("Running _generate_wrapper_fh (IntelHeaderGenerator).")
        super()._generate_wrapper_fh(gen_file)
        if not os.path.exists(os.path.join(self.dir_output, "wrapper_f.h")):
            log.warning("Using {}".format(os.path.join(self.dir_input, "wrapper_f.h")))
            shutil.copy2(os.path.join(self.dir_input, "wrapper_f.h"), self.dir_output)

    def _mpich_exceptions_run_mpih(self, text):
        log.debug("Running _mpich_exceptions_run_mpih (IntelHeaderGenerator).")
        text = re.sub(r"const ", "", text, flags=re.MULTILINE)
        _pattern_block = """
/*  
 *  (C) 2001 by Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */
"""
        _replacement_block = COPYRIGHT_MPICH_MPIH
        text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)

        _pattern_block = """
/* user include file for MPI programs */
"""
        _replacement_block = """
/* user include file for MPI programs */
#if !defined(_WIN32) && !defined(_WIN64)  /* Linux only */
#	include <stdint.h> /* for __WORDSIZE definition */
#   ifdef __WORDSIZE
#	    if __WORDSIZE != 8*8 /* 32 or 64 */
#		    error A wrong version of mpi.h file was included. Check include path.
#	    endif
#    endif
#endif
"""
        text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)

        _pattern_block = """
#ifdef MPICH_DEFINE_2COMPLEX
"""
        _replacement_block = """
#define MPICH_DEFINE_2COMPLEX
#ifdef MPICH_DEFINE_2COMPLEX
"""
        text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)

        _pattern_block = """
/* Pre-defined constants */
#define R_MPI_UNDEFINED      (-32766)
#define R_MPI_KEYVAL_INVALID 0x24000000
"""
        _replacement_block = """
/* Pre-defined constants */
#define R_MPI_UNDEFINED      (-32766)
#define R_MPI_UNDEFINED_RANK R_MPI_UNDEFINED
#define R_MPI_KEYVAL_INVALID 0x24000000
"""
        text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)

        text = re.sub(r"#define R_MPI_BSEND_OVERHEAD.*", "#define R_MPI_BSEND_OVERHEAD 95", text, flags=re.MULTILINE)

        lines_to_delete = [
            "extern int * R_MPI_UNWEIGHTED;",
            "extern int * R_MPI_WEIGHTS_EMPTY;"
        ]
        text = delete_lines(lines_to_delete, text)     
        text = re.sub(r"(#define R_MPI_DUP_FN.*)", r"//\1", text, flags=re.MULTILINE)
        text = re.sub(r'([ \t$])MPI_', r'\1R_MPI_', text, flags=re.MULTILINE)
        text = re.sub(r"HAVE_MPI", "HAVE_R_MPI", text, re.MULTILINE)
        text = re.sub(r"BIND_MPI", "BIND_R_MPI", text, re.MULTILINE)
        text = re.sub(r"BIND_MPI", "BIND_R_MPI", text, re.MULTILINE)
        text = re.sub(r"R_MPIX", "MPIX", text, re.MULTILINE)
        text = re.sub(r"F08_MPI", "F08_R_MPI", text, flags=re.MULTILINE)

        _pattern_block = """
/* See 4.12.5 for R_MPI_F_STATUS(ES)_IGNORE */
#define MPIU_DLL_SPEC
extern MPIU_DLL_SPEC R_MPI_Fint * R_MPI_F_STATUS_IGNORE;
extern MPIU_DLL_SPEC R_MPI_Fint * R_MPI_F_STATUSES_IGNORE;
/* The annotation MPIU_DLL_SPEC to the extern statements is used 
   as a hook for systems that require C extensions to correctly construct
   DLLs, and is defined as an empty string otherwise
 */
"""
        _replacement_block = """
/* See 4.12.5 for R_MPI_F_STATUS(ES)_IGNORE */
#define MPIU_DLL_SPEC
extern MPIU_DLL_SPEC R_MPI_Fint * R_MPI_F_STATUS_IGNORE;
extern MPIU_DLL_SPEC R_MPI_Fint * R_MPI_F_STATUSES_IGNORE;
//extern MPIU_DLL_SPEC int * R_MPI_UNWEIGHTED;
//extern MPIU_DLL_SPEC int * R_MPI_WEIGHTS_EMPTY;
int * R_MPI_UNWEIGHTED;
int * R_MPI_WEIGHTS_EMPTY;
int * MPI_UNWEIGHTED;
int * MPI_WEIGHTS_EMPTY;

/* The annotation MPIU_DLL_SPEC to the extern statements is used 
   as a hook for systems that require C extensions to correctly construct
   DLLs, and is defined as an empty string otherwise
 */
"""
        text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)

        _pattern_block = """
#define R_MPI_T_ERR_PVAR_NO_ATOMIC    72  /* Pvar can't be R/W atomically */
"""
        _replacement_block = """
#define R_MPI_T_ERR_PVAR_NO_ATOMIC    72  /* Pvar can't be R/W atomically */
#define R_MPI_T_ERR_INVALID_NAME      73  /* Name doesn't match */
#define R_MPI_T_ERR_INVALID           74  /* Generic error code for MPI_T added in MPI-3.1 */
"""
        text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)

        text = re.sub(r"(#define MPICH_ERR_LAST_CLASS) [0-9][0-9](.*)", r"\1 74\2", text, re.MULTILINE)
        text = re.sub(r"R_MPIX", "MPIX", text, re.MULTILINE)
        text = re.sub(r"R_PMPIX_Comm", "PMPIX_Comm", text, re.MULTILINE)
        text = re.sub(r"R_MPIX_Grequest", "MPIX_Grequest", text)
        text = re.sub(r"R_MPIX_Mutex", "MPIX_Mutex", text)
        text = re.sub(r"R_PMPIX_Grequest", "PMPIX_Grequest", text)       
        text = re.sub(r"R_PMPIX_Mutex", "PMPIX_Mutex", text)

        return text

    def _intel_generate_run_mpih(self, gen_file):
        log.debug("Running _generate_run_mpih (IntelHeaderGenerator).")
        super()._generate_run_mpih(gen_file)
        with open(gen_file, "r") as _file:
            _content = _file.read()

        _new_content = self._mpich_exceptions_run_mpih(_content)
        with open(gen_file, 'w') as _file:
            _file.write(_new_content)

    def _generate_run_mpih(self, gen_file):
        self._intel_generate_run_mpih(gen_file)

    def _mpich_exceptions_run_mpioh(self, text):
        log.debug("Running _mpich_exceptions_run_mpioh (IntelHeaderGenerator).")
        _pattern_block = """
/* 
 *
 *   Copyright (C) 1997 University of Chicago. 
 *   See COPYRIGHT notice in top-level directory.
 */
"""
        _replacement_block = COPYRIGHT_MPICH_MPIOH
        text = re.sub(re.escape(_pattern_block), _replacement_block, text, flags=re.DOTALL)
        
        text = re.sub(r"const", "", text)
        text = re.sub(r"R_MPIO", "MPIO", text)
        text = re.sub(r"([^RN])_MPI", r"\1_R_MPI", text)

        return text

    def _generate_run_mpioh(self, gen_file):
        log.debug("Running _generate_run_mpioh (IntelHeaderGenerator).")
        super()._generate_run_mpioh(gen_file)
        with open(gen_file, "r") as _file:
            _content = _file.read()

        _new_content = self._mpich_exceptions_run_mpioh(_content)
        with open(gen_file, 'w') as _file:
            _file.write(_new_content)

    def generate(self):
        shutil.copy2(
            os.path.join(self.dir_input, "mpich-3.1.2_mpi.h"),
            os.path.join(self.dir_output, self._run_mpi_header_file)
            )
        shutil.copy2(
            os.path.join(self.dir_input, "ompi-1.8.8_mpi.h"),
            os.path.join(self.dir_output, self._app_mpi_header_file)
            )
        shutil.copy2(
            os.path.join(self.dir_input, "mpich-3.1.2_mpio.h"),
            os.path.join(self.dir_output, self._run_mpio_header_file)
            )
        super().generate()
        log.debug("INTEL header has been generated.")

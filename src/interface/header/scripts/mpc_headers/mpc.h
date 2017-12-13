/* ############################# MPC License ############################## */
/* # Wed Nov 19 15:19:19 CET 2008                                         # */
/* # Copyright or (C) or Copr. Commissariat a l'Energie Atomique          # */
/* #                                                                      # */
/* # IDDN.FR.001.230040.000.S.P.2007.000.10000                            # */
/* # This file is part of the MPC Runtime.                                # */
/* #                                                                      # */
/* # This software is governed by the CeCILL-C license under French law   # */
/* # and abiding by the rules of distribution of free software.  You can  # */
/* # use, modify and/ or redistribute the software under the terms of     # */
/* # the CeCILL-C license as circulated by CEA, CNRS and INRIA at the     # */
/* # following URL http://www.cecill.info.                                # */
/* #                                                                      # */
/* # The fact that you are presently reading this means that you have     # */
/* # had knowledge of the CeCILL-C license and that you accept its        # */
/* # terms.                                                               # */
/* #                                                                      # */
/* # Authors:                                                             # */
/* #   - PERACHE Marc marc.perache@cea.fr                                 # */
/* #   - CARRIBAULT Patrick patrick.carribault@cea.fr                     # */
/* #                                                                      # */
/* ######################################################################## */
#ifndef ___MPC___GLOBAL___HEADER___FILE___
#define ___MPC___GLOBAL___HEADER___FILE___
#include <sctk_config.h>
#include <mpc_main.h>
#include <mpcalloc.h>
#include <mpcmicrothread.h>
#include <mpcomp.h>
#include <mpcthread.h>
#include <mpcmp.h>
int MPC_check_compatibility_lib(int major, int minor, char* pre);
void MPC_printf (const char *fmt, ...);
#define MPC_check_compatibility() MPC_check_compatibility_lib(SCTK_VERSION_MAJOR,SCTK_VERSION_MINOR,SCTK_VERSION_PRE)
#endif

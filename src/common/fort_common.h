//############################# Wi4MPI License ###########################
//# `04/04/2016`                                                         #
//# Copyright or (C) or Copr. Commissariat a l'Energie Atomique          #
//#                                                                      #
//# IDDN.FR.001.210022.000.S.P.2014.000.10800                            #
//# This file is part of the Wi4MPI library.                             #
//#                                                                      #
//# SPDX-License-Identifier: BSD-3-Clause OR CeCILL-B                    #
//#                                                                      #
//#                                                                      #
//# Authors:                                                             #
//#   - Juilly Kevin <kevin.juilly.tgcc@cea.fr>                          #
//#                                                                      #
//########################################################################
#ifndef FORT_COMMON
#define FORT_COMMON

#if defined(IFORT_CALL) || defined(PGI_CALL) || defined(FLANG_CALL) || (defined(GFORT_CALL) && __GNUC__ < 8)
typedef int fort_string_length;
#elif defined(GFORT_CALL) && __GNUC__ >= 8
typedef size_t fort_string_length;
#endif

#endif /* ifndef FORT_COMMON */

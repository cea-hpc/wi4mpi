# Copyright 2013-2019 Lawrence Livermore National Security, LLC and other
# Spack Project Developers. See the top-level COPYRIGHT file for details.
#
# SPDX-License-Identifier: (Apache-2.0 OR MIT)

# ----------------------------------------------------------------------------
# If you submit this package back to Spack as a pull request,
# please first remove this boilerplate and all FIXME comments.
#
# This is a template package file for Spack.  We've put "FIXME"
# next to all the things you'll want to change. Once you've handled
# them, you can save this file and test your package like this:
#
#     spack install wi4mpi
#
# You can edit this file again by typing:
#
#     spack edit wi4mpi
#
# See the Spack documentation for more information on packaging.
# ----------------------------------------------------------------------------

from spack import *
from spack.util.environment import set_env
import os


class Wi4mpi(CMakePackage):
    """WI4MPI: Wrapper Interface For MPI performing a light translation between MPI constants and MPI objects from an MPI implementation to another one"""

    homepage = "https://github.com/cea-hpc/wi4mpi"
    url      = "https://github.com/cea-hpc/wi4mpi/archive/v3.3.0.tar.gz"

    version('3.3.0', sha256='fb7fb3b591144e90b3d688cf844c2246eb185f54e1da6baef857e035ef730d96')
    version('3.2.2', sha256='23ac69740577d66a68ddd5360670f0a344e3c47a5d146033c63a67e54e56c66f')
    version('3.2.1', sha256='0d928cb930b6cb1ae648eca241db59812ee0e5c041faf2f57728bbb6ee4e36df')
    version('3.2.0', sha256='3322f6823dbec1d58a1fcf163b2bcdd7b9cd75dc6c7f78865fc6cb0a91bf6f94')
    variant('build_type', default='Release',
        description='The build type to build',
        values=('Debug', 'Release', 'RelWithDebInfo'))

    depends_on('mpi')

    def cmake_args(self):
        if '%gcc' in self.spec:
            compiler = "GNU"
        elif '%intel' in self.spec:
            compiler = "INTEL"
        elif '%clang' in self.spec:
            compiler = "LLVM"
        elif '%pgi' in self.spec:
            compiler = "PGI"
        else:
            tty.error("Could not determine compiler used")
        wi4mpi_build_type = 'RELEASE'
        if self.spec.variants["build_type"].value == "RelWithDebInfo":
            wi4mpi_build_type = 'NORMAL'
        elif self.spec.variants["build_type"].value == "Debug":
            wi4mpi_build_type = 'DEBUG'
        args = ["-DWI4MPI_REALEASE="+wi4mpi_build_type, "-DWI4MPI_COMPILER="+compiler]
        return args

    def setup_run_environment(self, env):
        env.set('WI4MPI_ROOT', self.prefix)
        if '%gcc' in self.spec:
            env.set('WI4MPI_CC', "gcc")
            env.set('WI4MPI_CXX', "g++")
            env.set('WI4MPI_FC', "gfortran")
        elif '%intel' in self.spec:
            env.set('WI4MPI_CC', "icc")
            env.set('WI4MPI_CXX', "icpc")
            env.set('WI4MPI_FC', "ifort")
        elif '%clang' in self.spec:
            env.set('WI4MPI_CC', "clang")
            env.set('WI4MPI_CXX', "clang++")
            env.set('WI4MPI_FC', "flang")
        elif '%pgi' in self.spec:
            env.set('WI4MPI_CC', "pgcc")
            env.set('WI4MPI_CXX', "pgc++")
            env.set('WI4MPI_FC', "pgfortran")


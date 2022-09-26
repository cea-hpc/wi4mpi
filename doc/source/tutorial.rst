Tutorial
********

During this tutorial, you just have to copy/paste boxed lines in a `bash` terminal.

Installation
============

Install wi4mpi with Spack PM

.. code-block:: console

 git clone https://github.com/spack/spack
 source spack/share/spack/setup-env.sh
 spack compiler find    # /!\ gfortran is required for this tuto (openmpi dep)
 spack install wi4mpi
 spack install mpich
 spack install openmpi

Configuration
=============

.. note::

    Here, we load mpich and openmpi before wi4mpi in order to detect their root path via dirname

Add MPICH path to wi4mpi config file

.. code-block:: console

 spack unload -a
 spack load wi4mpi
 spack load mpich
 echo "MPICH_DEFAULT_ROOT=\"$(dirname $(dirname $(which mpirun)))\"" >> $WI4MPI_ROOT/etc/wi4mpi.cfg

Add Open MPI path to wi4mpi config file

.. code-block:: console

 spack unload -a
 spack load wi4mpi
 spack load openmpi
 dirname $(dirname $(which mpirun))
 echo "OPENMPI_DEFAULT_ROOT=\"$(dirname $(dirname $(which mpirun)))\"" >> $WI4MPI_ROOT/etc/wi4mpi.cfg

Running
=======
 
Run codes linked with Open MPI through Wi4MPI to run on MPICH runtime and vice versa.

From MPICH to Open MPI
----------------------

Compiling OSU-MB with MPICH
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: console

 spack unload -a
 wget https://mvapich.cse.ohio-state.edu/download/mvapich/osu-micro-benchmarks-5.9.tar.gz
 tar xf osu-micro-benchmarks-5.9.tar.gz
 spack load mpich
 cd osu-micro-benchmarks-5.9
 ./configure CC=mpicc CXX=mpicxx
 make -j
 
Running OSU-MB with MPICH
~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: console
 
 spack unload -a
 spack load mpich
 mpirun -n 4 mpi/collective/osu_allreduce

Running OSU-MB with Open MPI from MPICH
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. warning::

    Load wi4mpi after openmpi to get mpirun PATH priority

.. code-block:: console

 spack unload -a
 spack load openmpi
 spack load wi4mpi
 mpirun -F mpich -T openmpi -n 4 mpi/collective/osu_allreduce

If everything work fine, you should get someting like this:

.. note::

 You are using Wi4MPI-3.6.0 with the mode preload From **MPICH** To **OMPI**

.. code-block:: console

 You are using Wi4MPI-3.6.0 with the mode preload From MPICH To OMPI
 
 # OSU MPI Allreduce Latency Test v5.9
 # Size       Avg Latency(us)
 4                       0.93
 8                       0.93
 16                      0.94
 32                      0.94
 64                      0.94
 128                     1.06
 256                     1.10
 512                     1.69
 1024                    1.91
 2048                    2.47
 4096                    5.24
 8192                    7.92
 16384                  13.77
 32768                  18.52
 65536                  29.44
 131072                 56.47
 262144                116.91
 524288                318.04
 1048576              1465.73

From Open MPI to MPICH
----------------------

Compiling OSU-MB with Open MPI
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: console

 spack unload -a
 wget https://mvapich.cse.ohio-state.edu/download/mvapich/osu-micro-benchmarks-5.9.tar.gz
 tar xf osu-micro-benchmarks-5.9.tar.gz
 spack load openmpi
 cd osu-micro-benchmarks-5.9
 ./configure CC=mpicc CXX=mpicxx
 make -j
 
Running OSU-MB with Open MPI
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: console

 spack unload -a
 spack load openmpi
 mpirun -n 4 mpi/collective/osu_allreduce

Running OSU-MB with MPICH from Open MPI
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. warning::

    Load wi4mpi after mpich to get mpirun PATH priority

.. code-block:: console

 spack unload -a
 spack load mpich
 spack load wi4mpi
 mpirun -F openmpi -T mpich -n 4 mpi/collective/osu_allreduce

If everything work fine, you should get someting like this:

.. note::

 You are using Wi4MPI-3.6.0 with the mode preload From **OMPI** To **MPICH**

.. code-block:: console

 You are using Wi4MPI-3.6.0 with the mode preload From OMPI To MPICH
 
 # OSU MPI Allreduce Latency Test v5.9
 # Size       Avg Latency(us)
 4                       1.23
 8                       1.21
 16                      1.26
 32                      1.22
 64                      1.24
 128                     1.39
 256                     1.41
 512                     1.82
 1024                    1.78
 2048                    2.23
 4096                    3.40
 8192                    6.67
 16384                  11.69
 32768                  23.53
 65536                  42.82
 131072                 90.53
 262144                184.57
 524288                387.81
 1048576               957.58

Tutorial
********

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

Add MPICH path to wi4mpi config file

.. code-block:: console

 spack load wi4mpi
 echo 'MPICH_DEFAULT_ROOT="/path/to/mpich/root"' >> $WI4MPI_ROOT/etc/wi4mpi.cfg

Running examples from Open MPI to MPICH
=======================================
 
Run codes linked with Open MPI through Wi4MPI to run on MPICH runtime

From MPICH to Open MPI
----------------------

Compiling OSU-MB with MPICH
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: console

 spack unload -a  # to be sure
 wget https://mvapich.cse.ohio-state.edu/download/mvapich/osu-micro-benchmarks-5.9.tar.gz
 tar xf osu-micro-benchmarks-5.9.tar.gz
 spack load mpich
 cd osu-micro-benchmarks-5.9
 ./configure CC=mpicc CXX=mpicxx
 make -j
 
Running OSU-MB with MPICH
~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: console

 spack load mpich
 mpirun -n 4 mpi/collective/osu_allreduce

Running OSU-MB with Open MPI from MPICH
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: console

 spack unload mpich
 spack load wi4mpi
 spack load openmpi
 mpirun -F mpich -T openmpi -n 4 mpi/collective/osu_allreduce

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

 spack load openmpi
 mpirun -n 4 mpi/collective/osu_allreduce

Running OSU-MB with MPICH from Open MPI
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: console

 spack unload openmpi
 spack load wi4mpi
 spack load mpich
 mpirun -F openmpi -T mpich -n 4 mpi/collective/osu_allreduce


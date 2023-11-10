Running GROMACS with Wi4MPI
===========================

Learning objectives
-------------------

With these hands-on exercises, participants will learn:

- How to switch between MPI implementation at runtime thanks to Wi4MPI on a real HPC application.
- How to execute a benchmark and measure performance with a common HPC benchmark.

What is GROMACS?
-----------------

`GROMACS <https://www.gromacs.org/>`_ is a versatile package to perform molecular dynamics, i.e., simulate the Newtonian equations of motion for systems with hundreds to millions of particles. It is primarily designed for biochemical molecules like proteins, lipids, and nucleic acids that have a lot of complicated bonded interactions. Still, since GROMACS is extremely fast at calculating the nonbonded interactions (that usually dominate simulations), it is also used for research on non-biological systems, e.g., polymers and fluid dynamics.

GROMACS is a molecular dynamics application designed to simulate Newtonian equations of motion for systems with hundreds to millions of particles. GROMACS is designed to simulate biochemical molecules like proteins, lipids, and nucleic acids that have a lot of complicated bonded interactions.

Obtaining the benchmark
-----------------------

.. code-block:: bash

   wget https://www.mpibpc.mpg.de/15101317/benchMEM.zip
   unzip benchMEM.zip

This benchmark simulates a membrane channel protein embedded in a lipid bilayer surrounded by water and ions. With its size of ~80,000 atoms, it serves as a prototypical example for a large class of setups used to study all kinds of membrane-embedded proteins. For some more information, see `here <https://www.mpinat.mpg.de/grubmueller/bench>`_.

First execution
---------------

You can load the default GROMACS version installed in your environment and launch it:

- Load GROMACS:

.. code-block:: bash

   spack load gromacs

- Launch the test case:

.. code-block:: bash

   export OMP_NUM_THREADS=2
   srun -n 32 -c 2 gmx_mpi mdrun -v -resethway -nsteps 10000 -ntomp ${OMP_NUM_THREADS} -s benchMEM.tpr

There are some parameters that can be modified when launching GROMACS:

- ``-nsteps`` specifies the number of steps and can be used to run a more or less long benchmark.
- ``-resethway`` resets the performance timers halfway through the run, removing the overhead of initialization and load balancing from the timings.
- ``-ntomp`` defines the number of OpenMP threads used.

You can expect an output that looks like this:

.. code-block:: bash

   10000 steps,     20.0 ps.
   step 0
   step 100, remaining wall clock time:    25 s
   ...
   step 9800, remaining wall clock time:     0 s
   step 9900, remaining wall clock time:     0 s
   vol 0.70  imb F  1% pme/F 0.70 
   step 10000, remaining wall clock time:     0 s

   Core t (s)   Wall t (s)        (%)
   Time:      721.804       11.279     6399.6
   (ns/day)    (hour/ns)
   Performance:       76.618        0.313

You can note the performance obtained, in ns/day.

Switching MPI with Wi4MPI
-------------------------

You can now easily switch between MPI versions with Wi4MPI, for example, switching to Open MPI:

.. code-block:: bash

   spack unload -a
   spack load openmpi
   spack load wi4mpi
   spack load gromacs

   export LD_LIBRARY_PATH=${WI4MPI_ROOT}/lib:${LD_LIBRARY_PATH}
   export WI4MPI_TO=OMPI
   export WI4MPI_RUN_MPI_C_LIB=/path/to/openmpi/lib/libmpi.so
   export WI4MPI_RUN_MPI_F_LIB=/path/to/openmpi/lib/libmpi_mpifh.so
   export WI4MPI_RUN_MPIIO_C_LIB=${WI4MPI_RUN_MPI_C_LIB}
   export WI4MPI_RUN_MPIIO_F_LIB=${WI4MPI_RUN_MPI_F_LIB}
   export WI4MPI_WRAPPER_LIB=/path/to/wi4mpi/lib_${WI4MPI_TO}/libwi4mpi_${WI4MPI_TO}.so

And then run the app:

.. code-block:: bash

   export OMP_NUM_THREADS=2
   srun -n 32 -c 2 gmx_mpi mdrun -v -resethway -nsteps 10000 -ntomp ${OMP_NUM_THREADS} -s benchMEM.tpr

You can note the performance, in ns/day.


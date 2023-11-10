Applying Wi4MPI to distributed Python
=====================================

Learning objectives
-------------------

With these hands-on exercises, attendees will learn:

- how to circumvent MPI ABI incompatibility in Python without recompiling a whole Python distribution
- how to launch simple Python MPI programs using Wi4MPI
- how to assess Wi4MPI performance in Python

Once attendees complete these exercises, they will be able to efficiently use Python in combination with Wi4MPI in their own environments.

Python, MPI & ABI incompatibility
---------------------------------

``mpi4py`` is a powerful Python package to leverage the full power of parallel architecture using Python. However, ``mpi4py`` has to be built using a specific MPI implementation, raising ABI-compatibility issues if one wishes to switch from MPI implementation without rebuilding a full Python stack (that may be time consuming).

Starting with Wi4MPI 3.4.2, it is possible to run any ``mpi4py`` version built with any MPI implementation with any other one.

Hello world
-----------

This first test is simply initializing MPI and checking the number of processes used in the communication:

.. code-block:: python

    from mpi4py import MPI

    comm = MPI.COMM_WORLD
    rank = comm.Get_rank()
    size = comm.Get_size()

    if rank == 0:
        print("There are {} processes".format(size))
    print("Rank: {}".format(rank))

Execution
^^^^^^^^^

1. Launch the previous script using ``mpi4py``, built with OpenMPI:

.. code-block:: bash

    mpirun -n 4 -- python3 init.py

2. Load another MPI implementation, relaunch the script and check that it fails:

.. code-block:: bash

    mpirun -n 4 -- python3 init.py

3. Load Wi4MPI with a different MPI implementation, relaunch the script to check that the init script is still running:

.. code-block:: bash

    mpirun -n 4 -F openmpi -T mpich -- python3 init.py

Ring communication of heterogenous data
---------------------------------------

The following example script uses ``mpi4py`` to exchange a heterogenous data dict on a ring of processes:

.. code-block:: python

    from mpi4py import MPI

    # Initialize MPI
    comm = MPI.COMM_WORLD
    rank = comm.Get_rank()
    size = comm.Get_size()

    # Define source and destination for pt2pt comm
    dest = (rank+1)%size
    source = (rank-1)%size

    # Define data
    data = {'rank': rank, 'rank x answer': 42*rank, 'rank x pi': 3.141592*rank}

    # MPI comm
    comm.send(data, dest=dest)
    data = comm.recv(source=source)

    print('On process {}, data is {}'.format(rank, data))

Execution
^^^^^^^^^

1. Launch the previous script using ``mpi4py``, built with OpenMPI:

.. code-block:: bash

    $ mpirun -n 4 -- python3 ring.py

2. Load another MPI implementation, relaunch the script and check that it fails:

.. code-block:: bash

    $ mpirun -n 4 -- python3 ring.py

3. Load Wi4MPI with a different MPI implementation, relaunch the script to check that the ring script is still running:

.. code-block:: bash

    $ mpirun -n 4 -F openmpi -T mpich -- python3 ring.py

Performance: bandwidth
----------------------

This last example measures the bandwidth of MPI communication using ``mpi4py``:

.. code-block:: python

    import sys
    import random
    from mpi4py import MPI

    comm = MPI.COMM_WORLD
    rank = comm.Get_rank()
    size = comm.Get_size()

    try:
        assert(size <= 2)
    except AssertionError:
        raise ValueError("This example runs with 2 processes; {} used".format(size))

    dst = 1
    src = 0

    min_xp = 0
    max_xp = 20

    warmup = 10
    itermax = 100

    buffer = [random.random() for i in range(2**max_xp)]

    if rank == 0:
        print("# Msg size\tComm time [s]\tBandwidth [MB/s]")
    for xp in range(min_xp, max_xp):
        length = 2**xp
        # warm-up
        for iter in range(warmup):
            if rank == 0:
                comm.send(buffer[0:length], dest=dst)
            elif rank == 1:
                rcv_buffer = comm.recv(source=src)

        # bandwidth measure
        t0 = MPI.Wtime()
        for iter in range(itermax):
            if rank == 0:
                comm.send(buffer[0:length], dest=dst)
            elif rank == 1:
                rcv_buffer = comm.recv(source=src)
        t1 = MPI.Wtime()

        if rank == 0:
            bw = 2*sys.getsizeof(buffer[0:length])/(t1 - t0)/itermax/1e6
            print(f"{length:d}\t\t{(t1-t0)/itermax:f}\t{bw:f}")

Execution
^^^^^^^^^

1. Launch the previous script using ``mpi4py``, built with OpenMPI:

.. code-block:: bash

    $ mpirun -n 4 -- python3 bandwidth.py

2. Load another MPI implementation, relaunch the script and check that it fails:

.. code-block:: bash

    $ mpirun -n 4 -- python3 bandwidth.py

3. Load Wi4MPI with a different MPI implementation, relaunch the script to check that the bandwidth script is still running and compare the performance with the execution running without Wi4MPI:

.. code-block:: bash

    $ mpirun -n 4 -F openmpi -T mpich -- python3 bandwidth.py



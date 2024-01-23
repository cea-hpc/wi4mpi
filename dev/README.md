# Tools for developing

## Headers generation

The command `<wi4mpi_root>/lib/generator.py` generate interface and preload headers inside `<wi4mpi_root>/src/interface/header` and `<wi4mpi_root>/src/preload/header`.
If you want to validate your developement about the headers generation, launch the script `headers_comparison.sh`.
It compare existing headers with generated headers. 
If all headers are the same, it will build wi4mpi with GNU inside this folder (`<wi4mpi_root>/dev`)

**WARNING** You will need mpicc in your *PATH* and the python modules inside `./lib/requirement.txt` in you *PYTHONPATH*

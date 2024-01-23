# How to start

The generator is coded in python.
First, add the python library path in your environment:
```
export PYTHONPATH $(realpath <wi4mpi_root>/lib)
export PATH=
```

You also need to install requirement from the file `requirements.txt`.

Then, print the helper of the generator:
```
<wi4mpi_root>/lib/generator.py -h
```

If you launch the generator without any option, the headers will be generated
in `src/interface/header` and `src/preload/header`.

Example:
```
<wi4mpi_root>/lib/generator.py --interface_header_dir=src/interface/header_gen --preload_header_dir=src/preload/header_gen
```

# How to start

The generator is coded in Python.
First, add the Python library path in your environment:
```
export PYTHONPATH=$(realpath <wi4mpi_root>/src/generator)
export PATH=
```

You also need to install requirements from `requirements.txt` file.

Then, print the generator helper:
```
<wi4mpi_root>/src/generator/generator.py -h
```

If you launch the generator without any option, the headers will be generated
in `src/interface/header` and `src/preload/header`.

Example:
```
<wi4mpi_root>/src/generator/generator.py --interface_header_dir=src/interface/header_gen --preload_header_dir=src/preload/header_gen
```

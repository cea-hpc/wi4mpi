# Tools for developing

The script `launcher.sh` drive the testing.
Type `launcher.sh -h` to show the helper.

By default, it triggers all the following scripts:

1. `run_generator.sh`
2. `run_test_headers.sh`
3. `run_build.sh`


## Generator

`launcher.sh -g 1`

The script `run_generator.sh` executes `<wi4mpi_root>/lib/generator.py` to generate headers and code for interface and preload.
Files are written in temporary directories.

## Comparison of headers

`launcher.sh -d 1`

The script `run_test_headers.sh` compares generated headers to references.

If the generator is not activate (`launcher.sh -g 0`) you have to define interactively directories that contain preload and interface headers.
For example:

Interface headers:
```
$ tree /tmp/tmp.k6shaUXsCj
/tmp/tmp.k6shaUXsCj
├── _INTEL
│   ├── app_mpi.h
│   ├── run_mpi.h
│   ├── run_mpio.h
│   └── wrapper_f.h
├── _MPC
│   ├── app_mpi.h
│   ├── mpcmp.h
│   ├── run_mpi.h
│   ├── run_mpio.h
│   ├── sctk_types.h
│   └── wrapper_f.h
├── _MPICH
│   ├── app_mpi.h
│   ├── run_mpi.h
│   ├── run_mpio.h
│   └── wrapper_f.h
└── _OMPI
    ├── app_mpi.h
    ├── run_mpi.h
    └── wrapper_f.h
```

Preload headers:
```
$ tree /tmp/tmp.RhYegT1HGr
/tmp/tmp.RhYegT1HGr
├── INTEL_INTEL
│   ├── app_mpi.h
│   ├── app_mpio.h
│   ├── run_mpi.h
│   ├── run_mpio.h
│   └── wrapper_f.h
├── INTEL_MPICH
│   ├── app_mpi.h
│   ├── app_mpio.h
│   ├── run_mpi.h
│   ├── run_mpio.h
│   └── wrapper_f.h
├── INTEL_OMPI
│   ├── app_mpi.h
│   ├── app_mpio.h
│   ├── run_mpi.h
│   └── wrapper_f.h
├── MPICH_INTEL
│   ├── app_mpi.h
│   ├── app_mpio.h
│   ├── run_mpi.h
│   ├── run_mpio.h
│   └── wrapper_f.h
├── MPICH_MPICH
│   ├── app_mpi.h
│   ├── app_mpio.h
│   ├── run_mpi.h
│   ├── run_mpio.h
│   └── wrapper_f.h
├── MPICH_OMPI
│   ├── app_mpi.h
│   ├── app_mpio.h
│   ├── run_mpi.h
│   └── wrapper_f.h
├── OMPI_INTEL
│   ├── app_mpi.h
│   ├── run_mpi.h
│   ├── run_mpio.h
│   └── wrapper_f.h
├── OMPI_MPICH
│   ├── app_mpi.h
│   ├── run_mpi.h
│   ├── run_mpio.h
│   └── wrapper_f.h
└── OMPI_OMPI
    ├── app_mpi.h
    ├── run_mpi.h
    └── wrapper_f.h
```

## Build

`launcher.sh -b 1`

The script `run_build.sh` build Wi4MPI in a temporary directory.
If preload and interface code is not generated (`launcher.sh -g 0`) you have to define interactively directories that contain the preload and interface code.
For example:

C code for preload:
```
$ tree /tmp/tmp.gMsxpPUgsr
/tmp/tmp.gMsxpPUgsr
└── mpi_translation_c.c
```

C code for interface:
```
$ tree /tmp/tmp.HVdYvafPuH
/tmp/tmp.HVdYvafPuH
├── interface_c.c
└── mpi_translation_c.c
```

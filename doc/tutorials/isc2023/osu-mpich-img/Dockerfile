from ubuntu:18.04
env TZ=Europe/Paris
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
run apt update --fix-missing
run apt install -y build-essential wget mpich file
run wget https://mvapich.cse.ohio-state.edu/download/mvapich/osu-micro-benchmarks-5.9.tar.gz
run tar xf osu-micro-benchmarks-5.9.tar.gz
run cd osu-micro-benchmarks-5.9 && ./configure CC=mpicc CXX=mpicxx && make -j

## SSH is needed to fix this:
# --------------------------------------------------------------------------
# The value of the MCA parameter "plm_rsh_agent" was set to a path
# that could not be found:
# 
#   plm_rsh_agent: ssh : rsh
# 
# Please either unset the parameter, or check that the path is correct
# --------------------------------------------------------------------------
run apt install -y ssh

## One must avoid launching MPI with root user
run useradd osu
user osu

# EXAMPLES:
#
# podman run osu-mpich mpirun -n 2 /osu-micro-benchmarks-5.9/mpi/collective/osu_allreduce
# pcocc run -s -I osu-mpich -- mpirun -n 2 /osu-micro-benchmarks-5.9/mpi/collective/osu_allreduce
# sudo docker run osu-mpich mpirun -n 2 /osu-micro-benchmarks-5.9/mpi/collective/osu_allreduce


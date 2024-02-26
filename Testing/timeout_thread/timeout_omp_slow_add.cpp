#include <mpi.h>
#include <unistd.h>
#include <thread>

void caller_mpi(int rank, MPI_Op slow_op) {
    int srank;
    MPI_Reduce(&rank, &srank, 1, MPI_INT, slow_op, 0, MPI_COMM_WORLD);
}
void slow_add(void *in, void *out, int *len, MPI_Datatype *dat) {
  int i;
  int *iin = (int *)in;
  int *iout = (int *)out;
  (*iout) = 0;
  for (i = 0; i < *len; i++) {
    (*iout) += iin[i];
    if (*iin == 0)
      sleep(10);
  }
}
int main(int argc, char **argv) {
  int rank;
  MPI_Op slow_op;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Op_create(&slow_add, 1, &slow_op);
  std::thread t1{caller_mpi, rank, slow_op};
  t1.join();
  MPI_Finalize();
}

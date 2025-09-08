// Punto 4: Work-sharing con #pragma omp parallel for
// Compile: g++ p4_parallel_for.cpp -fopenmp -o p4_parallel_for
// Ejecución: ./p4_parallel_for [nthreads]  (opcional)
#include <omp.h>
#include <cstdio>
#include <cstdlib>
int main(int argc, char** argv) {
    int nthreads = 2;
    if (argc > 1) nthreads = std::atoi(argv[1]);
    omp_set_num_threads(nthreads);

    const int N = 16;
    #pragma omp parallel for
    for (int i = 0; i < N; ++i) {
        int tid = omp_get_thread_num();
        printf("Iteration %2d handled by thread %2d\n", i, tid);
    }
    return 0;
}

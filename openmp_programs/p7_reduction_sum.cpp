// Punto 7: Usar reduction(+:sum) para corregir la suma
// Compile: g++ p7_reduction_sum.cpp -fopenmp -o p7_reduction
// Ejecución: ./p7_reduction [NTHREADS] [COUNT]
#include <omp.h>
#include <cstdio>
#include <cstdlib>

int main(int argc, char** argv) {
    int NTHREADS = 4;
    long COUNT = 1000;
    if (argc > 1) NTHREADS = std::atoi(argv[1]);
    if (argc > 2) COUNT = std::atol(argv[2]);
    omp_set_num_threads(NTHREADS);

    long sum = 0;
    double start_time = omp_get_wtime();
    #pragma omp parallel for reduction(+:sum)
    for (long i = 0; i < COUNT; ++i) {
        sum += i;
    }

    long expected = (COUNT - 1) * COUNT / 2;
    double end_time = omp_get_wtime();
    double cpu_time = end_time - start_time;
    
    std::printf("Threads=%d COUNT=%ld -> sum=%ld (expected=%ld)\n",
                NTHREADS, COUNT, sum, expected);
    std::printf("Tiempo de CPU: %.6f segundos\n", cpu_time);
    return 0;
}

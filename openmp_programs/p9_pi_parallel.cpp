// Punto 9: Cálculo de PI en paralelo con OpenMP
// Compile: g++ p9_pi_parallel.cpp -O2 -fopenmp -o p9_pi_omp
// Ejecución: ./p9_pi_omp [NUM_STEPS] [NTHREADS]
#include <omp.h>
#include <cstdio>
#include <cstdlib>

int main(int argc, char** argv) {
    long long NUM_STEPS = 100000000; // 1e8 por defecto
    int NTHREADS = 128;              // como sugiere el enunciado
    if (argc > 1) NUM_STEPS = std::atoll(argv[1]);
    if (argc > 2) NTHREADS = std::atoi(argv[2]);

    omp_set_num_threads(NTHREADS);

    double step = 1.0 / (double) NUM_STEPS;
    double sum = 0.0;
    
    double start_time = omp_get_wtime();
    #pragma omp parallel for reduction(+:sum)
    for (long long i = 0; i < NUM_STEPS; ++i) {
        double x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x * x);
    }
    double pi = step * sum;
    double end_time = omp_get_wtime();
    double cpu_time = end_time - start_time;
    
    std::printf("PI (paralelo) = %.15f  | steps=%lld threads=%d\n", pi, NUM_STEPS, NTHREADS);
    std::printf("Tiempo de CPU: %.6f segundos\n", cpu_time);
    return 0;
}

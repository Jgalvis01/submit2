// Punto 8: Cálculo de PI (secuencial) por método del rectángulo
// Compile: g++ p8_pi_sequential.cpp -O2 -o p8_pi_seq
// Ejecución: ./p8_pi_seq [NUM_STEPS]
#include <cstdio>
#include <cstdlib>
#include <omp.h>

int main(int argc, char** argv) {
    long long NUM_STEPS = 100000000; // 1e8 por defecto; ajusta según equipo
    if (argc > 1) NUM_STEPS = std::atoll(argv[1]);

    double step = 1.0 / (double) NUM_STEPS;
    double sum = 0.0;
    
    double start_time = omp_get_wtime();
    for (long long i = 0; i < NUM_STEPS; ++i) {
        double x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x * x);
    }
    double pi = step * sum;
    double end_time = omp_get_wtime();
    double cpu_time = end_time - start_time;
    
    std::printf("PI (secuencial) = %.15f\n", pi);
    std::printf("Tiempo de CPU: %.6f segundos\n", cpu_time);
    return 0;
}

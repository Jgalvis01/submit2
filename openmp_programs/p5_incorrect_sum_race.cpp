// Punto 5: Suma incorrecta con condición de carrera (demostración)
// Compile: g++ p5_incorrect_sum_race.cpp -fopenmp -o p5_bad
// Ejecución: ./p5_bad [NTHREADS] [COUNT]
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
    #pragma omp parallel for
    for (long i = 0; i < COUNT; ++i) {
        // ACCESO COMPARTIDO SIN SINCRONIZACIÓN -> RACE CONDITION
        sum += i;
    }
    long expected = (COUNT - 1) * COUNT / 2; // suma aritmética 0..COUNT-1
    std::printf("Threads=%d COUNT=%ld -> sum=%ld (expected=%ld)\n",
                NTHREADS, COUNT, sum, expected);
    return 0;
}

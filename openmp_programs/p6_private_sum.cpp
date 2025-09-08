// Punto 6: Declarar 'sum' como private (no corrige el total global)
// Compile: g++ p6_private_sum.cpp -fopenmp -o p6_private
// Ejecución: ./p6_private [NTHREADS] [COUNT]
#include <omp.h>
#include <cstdio>
#include <cstdlib>

int main(int argc, char** argv) {
    int NTHREADS = 4;
    long COUNT = 1000;
    if (argc > 1) NTHREADS = std::atoi(argv[1]);
    if (argc > 2) COUNT = std::atol(argv[2]);
    omp_set_num_threads(NTHREADS);

    long global_sum = 0;

    #pragma omp parallel for private(global_sum)
    for (long i = 0; i < COUNT; ++i) {
        // Cada hilo tiene su propia copia de global_sum (no inicializada a 0 garantizado),
        // y NO se combina al final -> resultado global incorrecto.
        global_sum += i;
    }

    long expected = (COUNT - 1) * COUNT / 2;
    std::printf("Threads=%d COUNT=%ld -> global_sum=%ld (expected=%ld)\n",
                NTHREADS, COUNT, global_sum, expected);
    return 0;
}

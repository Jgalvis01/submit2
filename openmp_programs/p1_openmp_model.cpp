// Punto 1: OpenMP Model
// Compile (secuencial): g++ p1_openmp_model.cpp -o p1_seq
// Compile (paralelo):   g++ p1_openmp_model.cpp -fopenmp -o p1_omp
#include <cstdio>
int main() {
    #pragma omp parallel
    printf("Hello ");
    printf("\nGoodBye -PUJPP- Exiting Program\n");
    return 0;
}

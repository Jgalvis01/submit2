// Punto 2: The team (omp_set_num_threads)
// Compile: g++ p2_team.cpp -fopenmp -o p2_team
#include <omp.h>
#include <cstdio>
int main() {
    omp_set_num_threads(2); // cambia a 2, 4, 8 para probar
    #pragma omp parallel
    printf("Hello ");
    printf("\nGoodBye -PUJPP- Exiting Program\n");
    return 0;
}

// Punto 3: Thread identifier (omp_get_thread_num)
// Compile: g++ p3_thread_id.cpp -fopenmp -o p3_thread_id
#include <omp.h>
#include <cstdio>
int main() {
    omp_set_num_threads(2); // cambia el valor para experimentar
    #pragma omp parallel
    {
        printf("Hello thread = %d\n", omp_get_thread_num());
    }
    printf("GoodBye -PUJPP- Exiting Program\n");
    return 0;
}

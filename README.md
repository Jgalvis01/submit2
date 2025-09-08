g++ p1_openmp_model.cpp -o p1_seq
g++ p1_openmp_model.cpp -fopenmp -o p1_omp
./p1_seq

Hello
GoodBye -PUJPP- Exiting Program

./p1_omp
Hello Hello Hello Hello Hello Hello Hello Hello
GoodBye -PUJPP- Exiting Program

g++ p2_team.cpp -fopenmp -o p2_team
./p2_team
Hello Hello
GoodBye -PUJPP- Exiting Program


g++ p3_thread_id.cpp -fopenmp -o p3_thread_id
./p3_thread_id
Hello thread = 1
Hello thread = 0
GoodBye -PUJPP- Exiting Program


g++ p4_parallel_for.cpp -fopenmp -o p4_parallel_for
./p4_parallel_for 2     # probar con 2 hilos
Iteration  8 handled by thread  1
Iteration  0 handled by thread  0
Iteration  1 handled by thread  0
Iteration  2 handled by thread  0
Iteration  3 handled by thread  0
Iteration  4 handled by thread  0
Iteration  5 handled by thread  0
Iteration  6 handled by thread  0
Iteration  7 handled by thread  0
Iteration  9 handled by thread  1
./p4_parallel_for 4     # probar con 4 hilos
Iteration  8 handled by thread  2
Iteration  9 handled by thread  2
Iteration 10 handled by thread  2
Iteration 11 handled by thread  2
Iteration 12 handled by thread  3
Iteration 13 handled by thread  3
Iteration 14 handled by thread  3
Iteration 15 handled by thread  3
Iteration  0 handled by thread  0

g++ p5_incorrect_sum_race.cpp -fopenmp -o p5_bad
./p5_bad 4 1000
Threads=4 COUNT=1000 -> sum=499500 (expected=499500)
./p5_bad 8 100000
Threads=8 COUNT=100000 -> sum=1159113774 (expected=4999950000)

g++ p6_private_sum.cpp -fopenmp -o p6_private
./p6_private 4 1000
Threads=4 COUNT=1000 -> global_sum=0 (expected=499500)

g++ p7_reduction_sum.cpp -fopenmp -o p7_reduction
./p7_reduction 4 1000
Threads=4 COUNT=1000 -> sum=499500 (expected=499500)
Tiempo de CPU: 0.016041 segundos
./p7_reduction 8 100000
Threads=8 COUNT=100000 -> sum=4999950000 (expected=4999950000)
Tiempo de CPU: 0.026004 segundos

g++ p8_pi_sequential.cpp -O2 -fopenmp -o p8_pi_seq
./p8_pi_seq 100000000   
PI (secuencial) = 3.141592653590426
Tiempo de CPU: 4.022207 segundos

g++ p9_pi_parallel.cpp -O2 -fopenmp -o p9_pi_omp
./p9_pi_omp 100000000 128   # 1e8 pasos con 128 hilos
PI (paralelo) = 3.141592653589792  | steps=100000000 threads=128
Tiempo de CPU: 1.646595 segundos



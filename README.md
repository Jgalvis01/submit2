# 📝 Submit – Laboratorio OpenMP

Este documento contiene la compilación, ejecución y resultados de los programas solicitados en el laboratorio de **Programación en Memoria Compartida con OpenMP**.

---

## 🔹 Ejercicio 1 – OpenMP Model

**Compilación y ejecución secuencial:**
```bash
g++ p1_openmp_model.cpp -o p1_seq
./p1_seq
```

**Salida:**
```
Hello
GoodBye -PUJPP- Exiting Program
```

**Compilación y ejecución paralela:**
```bash
g++ p1_openmp_model.cpp -fopenmp -o p1_omp
./p1_omp
```

**Salida:**
```
Hello Hello Hello Hello Hello Hello Hello Hello
GoodBye -PUJPP- Exiting Program
```

---

## 🔹 Ejercicio 2 – Team de hilos

```bash
g++ p2_team.cpp -fopenmp -o p2_team
./p2_team
```

**Salida:**
```
Hello Hello
GoodBye -PUJPP- Exiting Program
```

---

## 🔹 Ejercicio 3 – Identificador de hilo

```bash
g++ p3_thread_id.cpp -fopenmp -o p3_thread_id
./p3_thread_id
```

**Salida:**
```
Hello thread = 1
Hello thread = 0
GoodBye -PUJPP- Exiting Program
```

---

## 🔹 Ejercicio 4 – Parallel For

**Compilación:**
```bash
g++ p4_parallel_for.cpp -fopenmp -o p4_parallel_for
```

**Ejecución con 2 hilos:**
```bash
./p4_parallel_for 2
```

**Salida (ejemplo):**
```
Iteration  0 handled by thread  0
Iteration  1 handled by thread  0
Iteration  2 handled by thread  0
Iteration  3 handled by thread  0
Iteration  4 handled by thread  0
Iteration  5 handled by thread  0
Iteration  6 handled by thread  0
Iteration  7 handled by thread  0
Iteration  8 handled by thread  1
Iteration  9 handled by thread  1
```

**Ejecución con 4 hilos:**
```bash
./p4_parallel_for 4
```

**Salida (ejemplo):**
```
Iteration  0 handled by thread  0
Iteration  8 handled by thread  2
Iteration  9 handled by thread  2
Iteration 10 handled by thread  2
Iteration 11 handled by thread  2
Iteration 12 handled by thread  3
Iteration 13 handled by thread  3
Iteration 14 handled by thread  3
Iteration 15 handled by thread  3
```

---

## 🔹 Ejercicio 5 – Suma incorrecta (condición de carrera)

```bash
g++ p5_incorrect_sum_race.cpp -fopenmp -o p5_bad
./p5_bad 4 1000
./p5_bad 8 100000
```

**Salida:**
```
Threads=4 COUNT=1000   -> sum=499500     (expected=499500)
Threads=8 COUNT=100000 -> sum=1159113774 (expected=4999950000)
```

---

## 🔹 Ejercicio 6 – Variable privada

```bash
g++ p6_private_sum.cpp -fopenmp -o p6_private
./p6_private 4 1000
```

**Salida:**
```
Threads=4 COUNT=1000 -> global_sum=0 (expected=499500)
```

---

## 🔹 Ejercicio 7 – Reducción

```bash
g++ p7_reduction_sum.cpp -fopenmp -o p7_reduction
./p7_reduction 4 1000
./p7_reduction 8 100000
```

**Salida:**
```
Threads=4 COUNT=1000   -> sum=499500     (expected=499500)
Tiempo de CPU: 0.016041 segundos

Threads=8 COUNT=100000 -> sum=4999950000 (expected=4

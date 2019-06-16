## Goal:

The goal is to analyze the performance of different memory allocation techniches.

## Environment:
A Core i7 computer with 16 GHz of RAM.

Compiler: g++ (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0

## Build instructions:
None optimization:
```bash
g++ memory.cpp && ./a.out
```
O1 Optimization:
```bash
g++ memory.cpp -O1 && ./a.out
```
O2 Optimization:
```bash
g++ memory.cpp -O2 && ./a.out
```
O3 Optimization:
```bash
g++ memory.cpp -O3 && ./a.out
```

## Results:

| Memory allocation / Optimization | None |  O1  |  O2  |  O3  |
| ---------------------------------|-----:|-----:|-----:|-----:|
| Raw Pointer                      | 1.19s| 1.20s| 1.08s| 1.08s|
| Shared Pointer with new          | 8.31s| 2.64s| 2.35s| 2.42s|
| Shared Pointer with make_shared  |24.22s| 1.59s| 1.19s| 1.23s|
| Unique Pointer with new          | 7.22s| 1.20s| 1.10s| 1.09s|
| Unique Pointer with make_unique  | 7.56s| 1.14s| 1.11s| 1.09s|

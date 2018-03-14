#!/bin/bash

omp_threads=4

export OMP_NUM_THREADS=$omp_threads

echo "threads:" $omp_threads
echo "╔═══════════════════════════════════════════════════════╗"
echo "║ dim   init            mul             runtime         ║"
echo "╟───────────────────────────────────────────────────────╢"
./main 200
./main 400
./main 1000
echo "╚═══════════════════════════════════════════════════════╝"
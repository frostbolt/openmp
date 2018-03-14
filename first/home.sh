#!/bin/bash
for var in 1 2 4
do 

export OMP_NUM_THREADS=$var

echo "threads:" $var
echo "╔═══════════════════════════════════════════════════════╗"
echo "║ dim   init            mul             runtime         ║"
echo "╟───────────────────────────────────────────────────────╢"
./main 200
./main 400
./main 1000
./main 1500
echo "╚═══════════════════════════════════════════════════════╝"

done
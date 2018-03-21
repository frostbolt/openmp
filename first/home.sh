#!/bin/bash

touch result.csv

num_for_repeat=5

echo "NumThreads,Dim,InitTime,MulTime,Runtime" > result.csv
for omp_threads in 1 2 3 4
do

export OMP_NUM_THREADS=$omp_threads

for dim in 500 1000 1500 2000
do
	for ((i=0; i < $num_for_repeat; i++))
	do
	./main $dim >> result.csv
	done
done

done
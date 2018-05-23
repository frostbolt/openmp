#!/bin/bash
#SBATCH --job-name=mulMatrix
#SBATCH --output=result.csv
#SBATCH --ntasks=1
#
#SBATCH --cpus-per-task=20
#
#SBATCH --time=30:00
#SBATCH --mem-per-cpu=100

num_for_repeat=5

rm -rf ./lab2_results/
mkdir ./lab2_results/

for omp_threads in 1 2 4 6 8 10 12 14 16 18 20
do

	export OMP_NUM_THREADS=$omp_threads

	for dim in 100 300 600 900 1000 
	do
		for ((i=0; i < $num_for_repeat; i++))
		do
		./main $dim > ./lab2_results/surface_${omp_threads}_${dim}_${num_for_repeat}.csv
		done
	done

done
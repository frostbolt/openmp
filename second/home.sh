rm -rf ../utils/lab2_results/
mkdir ../utils/lab2_results/

for omp_threads in 1 2 3 4 
do

export OMP_NUM_THREADS=$omp_threads

for dim in 100 300 600 900 
do
	./main -n $dim
done

done
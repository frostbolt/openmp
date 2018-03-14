#include <iostream>
#include <sstream>
#include <chrono>
#include <stdexcept>
#include <omp.h>

#include "functions.h"

int main(int argc, char* argv[]){

	auto startTime = std::chrono::steady_clock::now();

	size_t rows=10;
	size_t cols=10;
	if (argc > 1){
		std::istringstream ss(argv[1]);
		int dim;
		if (!(ss >> dim)){
			throw std::invalid_argument("Wrong ARGV");
		} else {
			rows = dim;
			cols = dim;
		}
	}


	Matrix A = Matrix::rand(rows, cols);
	Matrix B = Matrix::rand(rows, cols);
	Matrix C(rows, cols);

	auto initTime = std::chrono::steady_clock::now();

	// // eye
	// for (size_t i = 0; i < A.rows(); ++i) {
	// 	for (size_t j = 0; j < A.cols(); ++j) {
	// 			if (i==j) 
	// 				A(i, j) = 1;
	// 			else
	// 				A(i, j) = 0;
	// 	}
	// }

	C = A * B;

	auto mulTime = std::chrono::steady_clock::now(); //end

	auto initDuration = std::chrono::duration_cast<std::chrono::duration<double>>(initTime - startTime);
	auto mulDuration = std::chrono::duration_cast<std::chrono::duration<double>>(mulTime - initTime);
	auto runtimeDuration = std::chrono::duration_cast<std::chrono::duration<double>>(mulTime - startTime);

	printCSV(omp_get_max_threads(), rows, initDuration.count(), mulDuration.count(), runtimeDuration.count());

	return 0;
}
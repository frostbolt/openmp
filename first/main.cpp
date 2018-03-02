#include <iostream>

#include "functions.h"

int main(){
	constexpr size_t rows = 50;
	constexpr size_t cols = 50;

	Matrix A(rows, cols);
	Matrix B = Matrix::rand(rows, cols);
	Matrix C(rows, cols);

	for (size_t i = 0; i < A.rows(); ++i) {
		for (size_t j = 0; j < A.cols(); ++j) {
				if (i==j) 
					A(i, j) = 1;
				else
					A(i, j) = 0;
		}
	}


	std::cout << toString(A) << std::endl<< std::endl<< std::endl;
	std::cout << toString(B) << std::endl<< std::endl<< std::endl;
	C = A * B;
	std::cout << toString(C) << std::endl;

	return 0;
}
#include "Matrix.h"

#include <omp.h>
#include <random>
#include <chrono>
#include <stdexcept>
#include <sstream>

Matrix mulSerial(const Matrix &first, const Matrix &second) {
	Matrix result(first.rows(),second.cols());

	if (first.cols() == second.rows())
		for (int i = 0; i < result.rows(); ++i)
			for (int j = 0; j < result.cols(); ++j)
				for (int k = 0; k < result.rows(); ++k)
					result(i,j) += first(i,k) * second(k,j);
	else
		throw std::invalid_argument("Wrong dimensions");

  return result;
}

std::string toString(const Matrix& matrix) {
	std::stringstream ss;
	for (size_t i = 0; i < matrix.rows(); ++i) {
		for (size_t j = 0; j < matrix.cols(); ++j) {
			ss << matrix(i, j) << " ";
		}
		ss << std::endl;
	}
	return ss.str();
}

static Matrix randMatrix(size_t rows, size_t cols) {
	result = Matrix(rows, cols);
	#pragma omp parallel shared(result) {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<double> dis(0, 1); // linear distr ???
		#pragma omp for schedule(static)
			for (size_t i = 0; i < result.rows(); ++i)
				for (size_t j = 0; j < result.cols(); ++j)
					result(i, j)=dis(gen);
	}
	return result;
}


Matrix Matrix::operator*(const Matrix& matrix) {
	return mulSerial((*this), matrix);
}
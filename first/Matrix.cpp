#include "Matrix.h"

#include <omp.h>
#include <random>
#include <chrono>
#include <stdexcept>
#include <sstream>

//

#ifndef MATRIX_MUL
#define MATRIX_MUL 2
#endif

// 

Matrix mulSerial(const Matrix& first, const Matrix& second) {
	Matrix result(first.rows(),second.cols());

	if (first.cols() == second.rows())
		for (size_t i = 0; i < result.rows(); ++i)
			for (size_t j = 0; j < result.cols(); ++j)
				for (size_t k = 0; k < result.rows(); ++k)
					result(i,j) += first(i, k) * second(k, j);
	else
		throw std::invalid_argument("Wrong dimensions");

	return result;
}

Matrix mulParallel(const Matrix& first, const Matrix& second) {
	Matrix result(first.rows(), second.cols());
	if (first.cols() == second.rows())
		#pragma omp parallel for shared(result, first, second)
		for (size_t i = 0; i < result.rows(); ++i) 
			for (size_t j = 0; j < result.cols(); ++j) {
				result(i, j) = 0;
				for (size_t k = 0; k < result.rows(); ++k) 
					result(i, j) += first(i, k) * second(k, j);
			}
	else
		throw std::invalid_argument("Wrong dimensions");

	return result;
}

Matrix mulParallel2(const Matrix& first, const Matrix& second) {
	Matrix result(first.rows(), second.cols());
	if (first.cols() == second.rows()) {
		Matrix secT = transpose(second);
		#pragma omp parallel for shared(result, first, secT)
		for (size_t i = 0; i < result.rows(); ++i) 
			for (size_t j = 0; j < result.cols(); ++j) {
				result(i, j) = 0;
				for (size_t k = 0; k < result.rows(); ++k) 
					result(i, j) += first(i, k) * secT(j, k);
			}
	}
	else
		throw std::invalid_argument("Wrong dimensions");

	return result;
}

std::string Matrix::toString() {
	std::stringstream ss;
	for (size_t i = 0; i < (*this).rows(); ++i) {
		for (size_t j = 0; j < (*this).cols(); ++j) {
			ss << (*this)(i, j) << " ";
		}
		ss << std::endl;
	}
	return ss.str();
}

Matrix Matrix::operator*(const Matrix& matrix) {
	#if MATRTIX_MUL==0
		return mulSerial((*this), matrix);
	#elif MATRTIX_MUL==1
		return mulParallel((*this), matrix);
	#elif MATRTIX_MUL==2
		return mulParallel2((*this), matrix);
	#else
		#error INVALID ARGUMENT MATRTIX_MUL
	#endif
}

std::vector<double> randVector(size_t size) {
	std::vector<double> result(size);
	#pragma omp parallel shared(result)
	{
		std::random_device rd;
		std::mt19937_64 gen(rd());
		std::uniform_real_distribution<double> dis(1.0, 2.0);

		#pragma omp for schedule(static)
		for (size_t i = 0; i < size; i++)
			result[i] = dis(gen);
	}
  return result;
}

Matrix transpose(const Matrix& matrix) {
	Matrix result(matrix.cols(), matrix.rows());
	#pragma omp parallel for shared(result)
	for (size_t i = 0; i < matrix.rows(); ++i)
		for (size_t j = 0; j < matrix.cols(); ++j) 
			result(i, j) = matrix(j, i);
		
  return result;
}

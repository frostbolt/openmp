#include "Matrix.h"
#include <stdexcept>

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

Matrix Matrix::operator*(const Matrix& matrix) {
	return mulSerial((*this), matrix);
}
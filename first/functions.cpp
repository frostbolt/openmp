#include "functions.h"

#include <sstream>

std::string toString(const Matrix& matrix)
{
	std::stringstream ss;
	for (size_t i = 0; i < matrix.rows(); ++i) {
		for (size_t j = 0; j < matrix.cols(); ++j) {
			ss << matrix(i, j) << " ";
		}
		ss << std::endl;
	}
	return ss.str();
}

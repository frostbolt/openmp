#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <vector>
#include <iostream>

class Matrix {
public:
	Matrix(size_t rows, size_t cols);
	size_t rows() const;
	size_t cols() const;
	double& operator()(size_t row, size_t col);
	Matrix operator * (const Matrix& matrix);
	const double &operator()(size_t row, size_t col) const;
private:
	size_t m_rows;
	size_t m_cols;
	std::vector<double> m_data;
};


#endif // __MATRIX_H__

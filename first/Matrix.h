#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <vector>
#include <iostream>
#include <string>

class Matrix {
public:
	Matrix(size_t rows, size_t cols)
		: m_rows(rows)
		, m_cols(cols)
		, m_data(rows * cols)
	{}

	inline size_t rows() const { return m_rows; }

	inline size_t cols() const { return m_cols;	}

	inline double& operator()(size_t row, size_t col) { return m_data[row * m_cols + col]; }

	const double& operator()(size_t row, size_t col) const { return m_data[row * m_cols + col]; }

	Matrix operator * (const Matrix& matrix);

private:
	size_t m_rows;
	size_t m_cols;
	std::vector<double> m_data;
};

Matrix mulSerial(const Matrix &first, const Matrix &second);
std::string toString(const Matrix& matrix);
static Matrix randMatrix(size_t rows, size_t cols);

#endif // __MATRIX_H__

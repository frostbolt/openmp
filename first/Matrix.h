#pragma once
#include <vector>
#include <iostream>

#ifndef __MATRIX_H__
#define __MATRIX_H__

class Matrix {
public:
	Matrix(size_t rows, size_t cols);
	size_t rows();
	size_t cols();
	double &operator()(size_t row, size_t col);
	// const double &operator()(size_t row, size_t col) const;
private:
	size_t m_rows;
	size_t m_cols;
	std::vector<double> m_data;
};


#endif // __MATRIX_H__
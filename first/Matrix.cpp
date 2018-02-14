#include "Matrix.h"

Matrix::Matrix(size_t rows, size_t cols)
	: m_rows(rows)
	, m_cols(cols)
	, m_data(rows * cols)
{}

size_t Matrix::rows(){
	return m_rows;
}

size_t Matrix::cols(){
	return m_cols;
}

double &Matrix::operator()(size_t row, size_t col){
	return m_data[row * m_cols + col];
}
// const double &Matrix::operator()(size_t row, size_t col) const {
// 	return m_data[row * m_cols + col];
// }
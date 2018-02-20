#include "Matrix.h"

Matrix::Matrix(size_t rows, size_t cols)
    : m_rows(rows)
    , m_cols(cols)
    , m_data(rows * cols)
{}

size_t Matrix::rows() const {
    return m_rows;
}

size_t Matrix::cols() const {
    return m_cols;
}

double& Matrix::operator()(size_t row, size_t col) {
    return m_data[row * m_cols + col];
}

Matrix Matrix::operator*(const Matrix& matrix) {
    Matrix res(m_rows, matrix.m_cols);

    if (m_cols == matrix.m_rows) {
        for (int i = 0; i < res.m_rows; ++i)
            for (int j = 0; j < res.m_cols; ++j)
                for (int k = 0; k < m_rows; ++k)
                    res.m_data[i * m_rows + j] += m_data[i * m_rows + k] * matrix.m_data[k * m_rows + j];
    }
    else
        std::cout << "\nWrong dimensions\n";

    return res;
}

const double& Matrix::operator()(size_t row, size_t col) const {
    return m_data[row * m_cols + col];
}

#include <iostream>
#include <vector>

#include "Matrix.h"

int main()
{
  constexpr size_t rows = 4;
  constexpr size_t cols = 4;
  Matrix A(rows, cols);

  for(size_t i = 0; i < A.rows(); ++i) {
    for(size_t j = 0; j < A.cols(); ++j) {
      A(i, j) = i * 10 + j;
    }
  }

  for(size_t i = 0; i < A.rows(); ++i) {
    for(size_t j = 0; j < A.cols(); ++j) {
      std::cout << A(i, j) << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
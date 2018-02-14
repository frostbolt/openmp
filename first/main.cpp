#include <iostream>
#include <vector>

#include "functions.h"

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

  std::cout << toString(A);

  return 0;
}
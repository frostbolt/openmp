#include <iostream>

#include "functions.h"

int main()
{
  constexpr size_t rows = 4;
  constexpr size_t cols = 4;

  Matrix A(rows, cols);
  Matrix B(rows, cols);
  Matrix C(rows, cols);

  for(size_t i = 0; i < A.rows(); ++i) {
    for(size_t j = 0; j < A.cols(); ++j) {
       A(i,j) = 1;
       B(i,j)=1;
       C(i,j)=0;
    }
  }

  std::cout<<toString(A)<<std::endl;
  std::cout<<toString(B)<<std::endl;
  C=A*B;
  std::cout<<toString(C)<<std::endl;


  return 0;
}
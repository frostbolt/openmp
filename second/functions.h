#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include "functions.h"
#include "../first/Matrix.h"

Matrix solveDirichletSerial(int N=99, double eps=0.000001);
Matrix solveDirichlet(int N=99, double eps=0.0001);

#endif // __FUNCTIONS_H__

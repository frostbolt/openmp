#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include <sstream>
#include "functions.h"
#include "../first/Matrix.h"

struct DirichletResult {
	Matrix surface;
	size_t iterations;
	double runtime;

	DirichletResult(Matrix s, size_t i, double r) : surface(s), iterations(i), runtime(r) {}

	std::string toString() {
		std::stringstream ss;

		ss << surface.toString() << iterations << "," << runtime;
		return surface.toString() + ss.str();
	}
};

Matrix solveDirichletSerial(int N=99, double eps=0.01);
DirichletResult solveDirichlet(int N=99, double eps=0.01);

#endif // __FUNCTIONS_H__

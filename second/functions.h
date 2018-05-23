#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include <sstream>
#include "../first/Matrix.h"

struct DirichletResult {
	size_t num_threads;
	Matrix surface;
	size_t iterations;
	double runtime;

	DirichletResult(size_t nt, Matrix s, size_t i, double r) : num_threads(nt), surface(s), iterations(i), runtime(r) {}

	std::string toString() {
		std::stringstream ss;

		ss << surface.toString() << num_threads << "," << iterations << "," << runtime << std::endl;
		return ss.str();
	}
};

Matrix solveDirichletSerial(size_t N=99, double eps=0.01);
DirichletResult solveDirichlet(size_t N=99, double eps=0.01);

#endif // __FUNCTIONS_H__

#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include <sstream>
#include "../first/Matrix.h"

struct DirichletResult {
	size_t num_threads;
	Matrix surface;
	size_t iterations;
	double runtime;
	double eps;

	DirichletResult(size_t nt, Matrix s, size_t i, double r, double e) : num_threads(nt), surface(s), iterations(i), runtime(r), eps(e) {}

	std::string toString() {
		std::stringstream ss;
		ss << surface.toString() << num_threads << "," << iterations << "," << runtime << "," << surface.cols() << "," << eps << std::endl;
		return ss.str();
	}
	std::string benchmark() {
		std::stringstream ss;
		ss << num_threads << "," << iterations << "," << runtime << "," << surface.cols() << "," << eps << std::endl;
		return ss.str();
	}
};

Matrix solveDirichletSerial(size_t N=98, double eps=0.01);
DirichletResult solveDirichlet(size_t N=98, double eps=0.01);

#endif // __FUNCTIONS_H__

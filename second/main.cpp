#include <iostream>
#include <stdexcept>
#include "functions.h"

int main(int argc, char *argv[]) {
	size_t N = 99;
	double eps = 0.001;
	if (argc > 1){
		std::istringstream ss(argv[1]);
		int dim;
		if (!(ss >> dim)){
			throw std::invalid_argument("INVALID ARGV");
		} else {
			N = dim;
		}
	}

	std::cout << solveDirichlet(N-2, eps).benchmark();
	return 0;
}
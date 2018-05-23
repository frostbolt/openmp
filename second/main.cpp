#include <iostream>
#include <omp.h>

#include "functions.h"

int main() {	
	std::cout << solveDirichlet(1000).toString();
	return 0;
}
#include <iostream>
#include <sstream>
#include <chrono>
#include <stdexcept>
#include <omp.h>

#include "functions.h"

int main() {
	auto startTime = std::chrono::steady_clock::now();

	
	std::cout << solveDirichlet(99, 0.0001).toString();

	auto runtime = std::chrono::steady_clock::now();
	auto runtimeDuration = std::chrono::duration_cast<std::chrono::duration<double>>(runtime - startTime);
	return 0;
}
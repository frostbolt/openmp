#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include "Matrix.h"

void printBenchmark(size_t dim, double initDuration, double mulDuration, double runtimeDuration);
inline void printCSV(int threads, size_t dim, double initDuration, double mulDuration, double runtimeDuration) {
	std::cout << threads << "," << dim << "," << initDuration << "," << mulDuration << "," << runtimeDuration << std::endl;
}

#endif // __FUNCTIONS_H__

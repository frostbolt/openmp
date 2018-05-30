#include <iostream>
#include <stdexcept>
#include <unistd.h>
#include "functions.h"

int main(int argc, char *argv[]) {	
	size_t N = 100;
	double eps = 0.001;
	int opt;

	while((opt = getopt(argc, argv, "n:e:")) != -1) {
		switch(opt) { 
			case 'n':
				N = atoi(optarg);
				break;
			case 'e':
				eps = atof(optarg);
				break;
		}
	}

	std::cout << solveDirichlet(N - 2, eps).toString();
	return 0;
}
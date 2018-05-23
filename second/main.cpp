#include <iostream>
#include <unistd.h>

#include "functions.h"

int main(int argc, char *argv[]) {

	char *opts = "dim:eps"; 

	size_t n = 99;
	double eps = 0.001;
	int opt;
	while((opt = getopt(argc, argv, opts)) != -1) {
		switch(opt) {
			case 'dim':
				n = atoi(optarg);
				break;
			case 'eps':
				eps = atoi(optarg);
				break;
		}
	}

	std::cout << solveDirichlet(n, eps).toString();
	return 0;
}
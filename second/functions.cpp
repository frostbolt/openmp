#include "functions.h"
#include "condition.h"
#include <omp.h>
#include <cmath>

Matrix solveDirichletSerial(int N,  double eps) {
	Matrix u_mat(N+2,  N+2);
	Matrix f_mat(N,  N);
	double h = 1.0 / (N + 1);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			f_mat(i,  j) = f((i + 1) * h,  (j + 1) * h);
	}

	for (int i = 1; i < N + 1; i++) {
		u_mat(i,  0) = g(i * h,  0);
		u_mat(i,  N + 1) = g(i * h,  (N + 1) * h);
	}

	for (int j = 0; j < N + 2; j++) {
		u_mat(0,  j) = g(0,  j * h);
		u_mat(N + 1,  j) = g((N + 1) * h,  j * h);
	}

	double max;
	int IterCnt = 0;
	do {
		IterCnt++;
		max = 0;
		for (int i = 1; i < N + 1; i++)
			for (int j = 1; j < N + 1; j++) {
				double u0 = u_mat(i,  j);
				double t = 0.25 * (u_mat(i-1,  j) + u_mat(i+1,  j) + u_mat(i,  j-1) + u_mat(i,  j+1) - h*h*f_mat(i - 1,  j - 1));
				u_mat(i,  j) = t;
				double d = std::fabs(t - u0);
				if (d >	max) max = d;
			}
	} while (max > eps);
	//std::cout << "IterCnt = " << IterCnt << std::endl;
	return u_mat;
}

Matrix solveDirichlet(int N,  double eps) {
	Matrix u_mat(N+2,  N+2);
	Matrix f_mat(N,  N);

	double h = 1.0 / (N + 1);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			f_mat(i,  j) = f((i + 1) * h,  (j + 1) * h);
	}

	for (int i = 1; i < N + 1; i++) {
		u_mat(i,  0) = g(i * h,  0);
		u_mat(i,  N + 1) = g(i * h,  (N + 1) * h);
	}

	for (int j = 0; j < N + 2; j++) {
		u_mat(0,  j) = g(0,  j * h);
		u_mat(N + 1,  j) = g((N + 1) * h,  j * h);
	}

	double max, u0, d;
	int j, IterCnt = 0;
	std::vector<double> mx(N);
	do
	{
		IterCnt++;
		// нарастание волны (k - длина фронта волны)
		for (int k = 1; k < N+1; k++) {
			mx[k] = 0;
			#pragma omp parallel for shared(u_mat, N, max) private(j, u0, d) schedule(static, 1)
			for (int i = 1; i < k+1; i++) {
				j = k + 1 - i;
				u0 = u_mat(i, j);
				u_mat(i, j) = 0.25 * (u_mat(i-1, j) +u_mat(i+1, j) + u_mat(i, j-1) + u_mat(i, j+1) - h*h*f_mat(i-1, j-1));
				d = fabs(u_mat(i, j) - u0);
				if (d > mx[i]) mx[i] = d;
			}
		}
		for (int k = N-1; k > 0; k--) {
			#pragma omp parallel for shared(u_mat, N, max) private(j, u0, d) schedule(static, 1)
			for (int i = N-k+1; i < N+1; i++){
				j = 2*N - k - i + 1;
				u0 = u_mat(i, j);
				u_mat(i, j) = 0.25 * (u_mat(i-1, j) +u_mat(i+1, j) + u_mat(i, j-1) + u_mat(i, j+1) - h*h*f_mat(i-1, j-1));
				d = std::fabs(u_mat(i, j) - u0);
				if (d > mx[i]) mx[i] = d;				
			}
		}
		max = 0;
		for (int i = 1; i < N+1; i++) {
			if (mx[i] > max) max = mx[i];
		}
	} while (max > eps);
	return u_mat;
}
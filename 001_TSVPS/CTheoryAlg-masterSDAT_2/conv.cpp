#include "Complex.h"
#include "DFT.h"

double* convCrealoc(double* mas, int oldN, int N) {
	double* a = new double[N];
	for (int i = 0; i < N; i++) {
		if (i < oldN) a[i] = mas[i];
			else a[i] = 0.0;
	}
	return a;
}

double* conv(double* a, int Na, double* b, int Nb, Complex* (*F)(double*, int), double* (*invF)(Complex*, int)) {
	int N;
	if (Na < Nb) N = Nb;
		else N = Na;
	
	double* A = convCrealoc(a, Na, 2 * N);
	double* B = convCrealoc(b, Nb, 2 * N);
	
	Complex* transformedA = F(A, 2 * N);
	Complex* transformedB = F(B, 2 * N);
	for (int i = 0; i < 2 * N; i++) {
		transformedA[i] = transformedA[i] * transformedB[i];
		Complex* X = &(transformedA[i]);
		transformedA[i] = X->multByRealNumber(2.0 * N);
	}
	delete[] transformedB;
	
	double* c = new double[2 * N];
	c = invF(transformedA, 2 * N);
	return c;
}

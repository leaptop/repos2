//#include "pch.h"
#include "Complex.h"
#include "DFT.h"
#include <cmath>
#include <iostream>
int cntdigi = 0;
Complex * discreteFourierTransform(double* mas, int N) {
	Complex* transformed = new Complex[N];

	for (int k = 0; k < N; k++) {
		Complex X;
		for (int n = 0; n < N; n++) {
			double realPower = -(2 * atan(1) * 4) * k * n / N;
			Complex e = Complex::expZ(Complex(0.0, realPower));
			e = e.multByRealNumber(mas[n]);
			X = X + e;
			cntdigi+=5;
		}
		X = X.divideByRealNumber(N);
		//X.ImZ(-X.ImZ());
		transformed[k] = X;
	}

	return transformed;
}
void printDiscrTrud() {
    printf("Трудоёмкость дискретного: %d\n",cntdigi);
    cntdigi=0;
    }


double * invDiscreteFourierTransform(Complex* transformed, int N) {
	double* mas = new double[N];

	for (int k = 0; k < N; k++) {
		Complex x;
		for (int n = 0; n < N; n++) {
			double realPower = (2 * atan(1) * 4) * k * n / N;
			Complex e = Complex::expZ(Complex(0.0, realPower));
			e = transformed[n] * e;
			x = x + e;
		}
		mas[k] = (double)x.ReZ();
	}
	return mas;
}

int nPowerTwo(int N) {
	int newN = 1;
	while (newN < N) {
		newN *= 2;
	}
	return newN;
}

double * crealoc(double* mas, int oldN, int newN) {
	double* newMas = new double[newN];
	for (int i = 0; i < newN; i++) {
		if (i < oldN) {
			newMas[i] = mas[i];
		} else {
			newMas[i] = (double)0;
		}
	}
	return newMas;
}

Complex * crealoc(Complex* mas, int oldN, int newN) {
	Complex* newMas = new Complex[newN];
	for (int i = 0; i < newN; i++) {
		if (i < oldN) {
			newMas[i] = mas[i];
		} else {
			newMas[i] = Complex(0.0, 0.0);
		}
	}
	return newMas;
}

int getP1(int N) {
	int p1 = (int)sqrt((double)N);
	while (N % p1) {
		p1--;
	}
	return p1;
}

void splitArray(double* mas, int N, double** a0, double** a1) {
	int n = N / 2;
	if (mas) {
		*a0 = new double[n];
		*a1 = new double[n];
		for (int i = 0; i < N; i++) {
			if (i % 2) {
				(*a1)[i / 2] = mas[i];
			} else {
				(*a0)[i / 2] = mas[i];
			}
		}
	}
}

void splitArray(Complex* mas, int N, Complex** a0, Complex** a1) {
	int n = N / 2;
	if (mas) {
		*a0 = new Complex[n];
		*a1 = new Complex[n];
		for (int i = 0; i < N; i++) {
			if (i % 2) {
				(*a1)[i / 2] = mas[i];
			} else {
				(*a0)[i / 2] = mas[i];
			}
		}
	}
}

Complex* fastFourierTransform(double* mas, int N) {
	if (N > 1) {
		int n = nPowerTwo(N);
		double* newMas = crealoc(mas, N, n);
		
		double* a0;
		double* a1;
		splitArray(newMas, n, &a0, &a1);
		
		Complex* y0 = fastFourierTransform(a0, n / 2);
		Complex* y1 = fastFourierTransform(a1, n / 2);
		
		Complex* Y = new Complex[n];
		for (int i = 0; i < n / 2; i++) {
			double realPower = ((2 * atan(1) * 4) * i) / n;
			Complex e = Complex::expZ(Complex(0.0, realPower));
			Y[i] = y0[i] + e * y1[i];
			Y[i] = Y[i].divideByRealNumber(2.0);
			Y[i + (n / 2)] = y0[i] - e * y1[i];
			Y[i + (n / 2)] = Y[i + (n / 2)].divideByRealNumber(2.0);

		}
		return Y;
		
	} else {
		Complex* X = new Complex(*mas, 0.0);
		return X;
	}
}


Complex* fastFourierTransform(double* mas, int N, int* Plus, int* Mult) {
	if (N > 1) {
		int n = nPowerTwo(N);
		double* newMas = crealoc(mas, N, n);
		
		double* a0;
		double* a1;
		splitArray(newMas, n, &a0, &a1);
		
		Complex* y0 = fastFourierTransform(a0, n / 2, Plus, Mult);
		Complex* y1 = fastFourierTransform(a1, n / 2, Plus, Mult);
		
		Complex* Y = new Complex[n];
		for (int i = 0; i < n / 2; i++) {
			double realPower = ((2 * atan(1) * 4) * i) / n;
			Complex e = Complex::expZ(Complex(0.0, realPower));
			Y[i] = y0[i] + e * y1[i];
			Y[i] = Y[i].divideByRealNumber(2.0);
			Y[i + (n / 2)] = y0[i] - e * y1[i];
			Y[i + (n / 2)] = Y[i + (n / 2)].divideByRealNumber(2.0);
			*Plus += 2;
			*Mult += 3;
		}
		return Y;
		
	} else {
		Complex* X = new Complex(*mas, 0.0);
		return X;
	}
}

Complex* invFastFourierTransform(Complex* transformed, int N) {
	if (N > 1) {
		int n = nPowerTwo(N);
		Complex* newMas = crealoc(transformed, N, n);
		
		Complex* y0;
		Complex* y1;
		splitArray(newMas, n, &y0, &y1);
		
		Complex* a0 = invFastFourierTransform(y0, n / 2);
		Complex* a1 = invFastFourierTransform(y1, n / 2);
		
		Complex* A = new Complex[n];
		
		for (int i = 0; i < n / 2; i++) {
			double realPower = (-(2 * atan(1) * 4) * i) / n;
			Complex e = Complex::expZ(Complex(0.0, realPower));
			A[i] = a0[i] + e * a1[i];
			A[i + (n / 2)] = a0[i] - e * a1[i];
		}
		
		/*for (int i = 0; i < n; i++) {
			std::cout << A[i] << " ";
		}
		std::cout << "\n";*/
		return A;
		
	} else {
		return transformed;
	}
}

double* invFFT(Complex* transformed, int N) {
	Complex* c = invFastFourierTransform(transformed, N);
	double* a = new double[N];
	for (int i = 0; i < N; i++) {
		Complex X = c[i];
		a[i] = X.ReZ();
	}
	return a;
}

#include "DFT.h"
//#include "pch.h"
#include <iostream>
#include <math.h>
#include "Complex.h"

int powerTwo(int N) {
	int number = 1;
	for (int i = 0; i < N; i++) {
		number *= 2;
	}
	return number;
}

void printRealMas(double* mas, int N) {
	for (int i = 0; i < N; i++) {
		std::cout << mas[i] << ", ";
	}
	std::cout << "\n";
}

int main() {
    double a[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    std::cout << "Input: ", printRealMas(a, 8);
	Complex* dft = digitalFourierTransform(a, 8);
	std::cout << "\nDigital Fourier Transform:\n";
	printComplexMas(dft, 8);
	double* b = invDigitalFourierTransform(dft, 8);
	std::cout << "InvDFT: ";
	printRealMas(b, 8);
	std::cout << "\n\n";
	
	double a1[4] = {1, 2, 3, 4};
	double b1[2] = {5, 6};
	
	std::cout << "Mas a: ", printRealMas(a, 4), std::cout << "\n";
	std::cout << "Mas b: ", printRealMas(b, 2), std::cout << "\n";
	std::cout << "Conv with Digital Fourier Transform: \n";
	double* c1 = conv(a1, 4, b1, 2, digitalFourierTransform, invDigitalFourierTransform);
	printRealMas(c1, 4 * 2);
	
	std::cout << "\n\nSemi Fast Transform\n";
	Complex* sfft = semiFastFourierTransform(a, 8);
	printComplexMas(sfft, 8);
	
	std::cout << "\nInv Semi Fast:\n";
	double* sf = invSemiFastFourierTransform(dft, 8);
	printRealMas(sf, 8);
	
	std::cout << "Conv with Semi Fast Fourier Transform: \n";
	c1 = conv(a1, 4, b1, 2, semiFastFourierTransform, invSemiFastFourierTransform);
	printRealMas(c1, 4 * 2);
	
	std::cout << "\nFast:\n";
	Complex* fft = fastFourierTransform(a, 8);
	printComplexMas(fft, 8);
	
	std::cout << "\n\nInv:\n";
	double* c = invFFT(fft, 8);
	printRealMas(c, 8);
	
	std::cout << "\nFast conv:\n";
	c1 = conv(a1, 4, b1, 2, fastFourierTransform, invFFT);
	printRealMas(c1, 8);
	
	double* A = new double[100];
	for (int i = 0; i < 100; i++) {
		A[i] = i;
	}
	std::cout << "\nProb 100 semi fast\n";
	Complex* S = semiFastFourierTransform(A, 100);
	
	delete[] A;
	delete[] S;
	
	A = new double[400];
	for (int i = 0; i < 400; i++) {
		A[i] = i;
	}
	std::cout << "\nProb 400 semi fast\n";
	S = semiFastFourierTransform(A, 400);
	delete[] A;
	delete[] S;
	
	A = new double[powerTwo(12)];
	for (int i = 0; i < powerTwo(12); i++) {
		A[i] = i;
	}
	std::cout << "\nProb 12 fast\n";
	int* P = new int;
	int* M = new int;
	*P = 0;
	*M = 0;
	S = fastFourierTransform(A, powerTwo(12), P, M);
	int p = *P;
	int m = *M;
	std::cout << "\n" << p << " " << m << " " << p + m << "\n";
	
	delete[] A;
	delete[] S;
	
	A = new double[powerTwo(13)];
	for (int i = 0; i < powerTwo(13); i++) {
		A[i] = i;
	}
	std::cout << "\nProb 13 fast\n";
	*P = 0;
	*M = 0;
	S = fastFourierTransform(A, powerTwo(13), P, M);
	p = *P;
	m = *M;
	std::cout << "\n" << p << " " << m << " " << p + m << "\n";
	
	delete[] A;
	delete[] S;
	
	A = new double[powerTwo(14)];
	for (int i = 0; i < powerTwo(14); i++) {
		A[i] = i;
	}
	std::cout << "\nProb 14 fast\n";
	*P = 0;
	*M = 0;
	S = fastFourierTransform(A, powerTwo(14), P, M);
	p = *P;
	m = *M;
	std::cout << "\n" << p << " " << m << " " << p + m << "\n";
	
	return 0;
}


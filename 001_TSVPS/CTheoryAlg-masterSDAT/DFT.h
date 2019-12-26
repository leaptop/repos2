#ifndef DFT
#define DFT

#include "Complex.h"



Complex * discreteFourierTransform(double* mas, int N);

double * invDiscreteFourierTransform(Complex* transformed, int N);

Complex* fastFourierTransform(double* mas, int N);

Complex* invFastFourierTransform(Complex* transformed, int N);

double* invFFT(Complex* transformed, int N);

Complex* semiFastFourierTransform(double* mas, int N);

Complex* fastFourierTransform(double* mas, int N, int* Plus, int* Mult);

double* invSemiFastFourierTransform(Complex* transformed, int N);

double* conv(double* a, int Na, double* b, int Nb, Complex* (*F)(double*, int), double* (*invF)(Complex*, int));

void  printDiscrTrud();
#endif

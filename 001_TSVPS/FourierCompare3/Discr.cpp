/*

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define _USE_MATH_DEFINES
#define M_PI 3.14159265358979323846

//const int n = 10;
const int n = 4;
int count = 0;

struct complex {
	double real;
	double image;
};

complex multiple_complex(complex a, complex b) {//функци¤ дл¤ умножени¤ двух комплексных чисел
	complex result;// вычисление произведени¤ двух комплексных чисел
  //  result.real = 0, result.image = 0;// необ¤зательно было
	result.real = a.real * b.real - a.image * b.image;
	result.image = a.real * b.image + a.image * b.real;
	return result;
}

void direct_transform_fourier(double* array, complex* result) {
	complex A, sum;
	sum.real = 0, sum.image = 0;
	for (int k = 0; k < n; k++) {
		for (int j = 0; j < n; j++) {
			count += 5;
			A.real = cos((-2 * M_PI * k * j) / n) * array[j];//экспонент нет, т.к. сразу применили ф-лу Ёйлера
			A.image = sin((-2 * M_PI * k * j) / n) * array[j];
			sum.real += A.real;
			sum.image += A.image;
		}
		sum.real /= n;
		sum.image /= n;
		result[k].real = sum.real;
		result[k].image = sum.image;
		sum.real = 0, sum.image = 0;
	}
}

void back_transform_fourier(complex* direct_fourier, complex* result) {
	complex A, sum, res_mul;
	sum.real = 0, sum.image = 0;
	for (int k = 0; k < n; k++) {
		for (int j = 0; j < n; j++) {
			A.real = cos((2 * M_PI * k * j) / n);
			A.image = sin((2 * M_PI * k * j) / n);
			res_mul = multiple_complex(A, direct_fourier[j]);
			sum.real += res_mul.real;
			sum.image += res_mul.image;
		}
		result[k].real = sum.real;
		result[k].image = sum.image;
		if (result[k].image < 10e-10) result[k].image = 0;
		sum.real = 0, sum.image = 0;
	}
}

int main() {
	double array[n];
	complex res[n], source[n];
	srand(time(NULL));
	printf("Source massive: ");
	//for (int i = 0; i < n; i++) {
	//	array[i] = i;
	//	printf("%lf ", array[i]);
	//}
	array[0] = 1;
	array[1] = 0;
	array[2] = 0;
	array[3] = 1;
	//array[4] = 0;
	//array[5] = 0;
   // array[6] = 0;
   // array[7] = 0;
   // array[8] = 0;
   // array[9] = 0;
	printf("\n\n");
	direct_transform_fourier(array, res);
	printf("Real part of direct transform: ");
	for (int i = 0; i < n; i++) {
		printf("%lf ", res[i].real);
	}
	printf("\n");
	printf("Image part of direct transform: ");
	for (int i = 0; i < n; i++) {
		printf("%lf ", res[i].image);
	}
	printf("\n\n");
	back_transform_fourier(res, source);
	printf("Real part of back transform: ");
	for (int i = 0; i < n; i++) {
		printf("%lf ", source[i].real);
	}
	printf("\n");
	printf("Image part of back transform: ");
	for (int i = 0; i < n; i++) {
		printf("%lf ", source[i].image);
	}
	printf("\n\n");
	printf("Trudoemkost': %d\n\n", count);
	system("pause");
}
*/
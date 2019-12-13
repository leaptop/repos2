#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#define M_PI 3.14159265358979323846
using namespace std;
//1024 elems
int kaef_one = 32, kaef_two = 32;

struct complexx {
	double real = 0;
	double image;
};

complexx multiple_complex(complexx a, complexx b) {
	complexx result;
	result.real = 0, result.image = 0;
	result.real = a.real * b.real - a.image * b.image;
	result.image = a.real * b.image + a.image * b.real;
	return result;
}

int count01 = 0;
int count_1 = 0, count_2 = 0;
//const int n = kaef_one * kaef_two;
const int n = 1024;

void direct_transform_fourier(double* array, complexx* result) {
	complexx A; complexx sum;
	sum.real = 0; sum.image = 0; A.real = 0; A.image = 0;
	for (int k = 0; k < n; k++) {
		for (int j = 0; j < n; j++) {
			count01 += 5;
			A.real = cos((-2 * M_PI * k * j) / n) * array[j];
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

void back_transform_fourier(complexx* direct_fourier, complexx* result) {
	complexx A, sum, res_mul;
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

complexx first_transform(double* array, int k_1, int j_2) {
	double coef;
	complexx sum, temp;
	sum.real = 0, sum.image = 0;
	for (int j_1 = 0; j_1 < kaef_one; j_1++) {
		count_1 += 5;
		coef = (double)(j_1 * k_1) / kaef_one;
		temp.real = cos(-2 * M_PI * coef) * array[j_2 + kaef_two * j_1];
		temp.image = sin(-2 * M_PI * coef) * array[j_2 + kaef_two * j_1];
		sum.real += temp.real;
		sum.image += temp.image;
	}
	sum.real /= kaef_one;
	sum.image /= kaef_one;
	return sum;
}

complexx second_transform(complexx** array, int k_1, int k_2) {
	int k;
	double coef;
	complexx sum, temp, res_mul;
	sum.real = 0, sum.image = 0;
	for (int j_2 = 0; ¸	j_2 < kaef_two; j_2++) {
		count_2 += 4;
		k = k_1 + kaef_one * k_2;
		coef = (double)(j_2 * k) / (kaef_one * kaef_two);
		temp.real = cos(-2 * M_PI * coef);
		temp.image = sin(-2 * M_PI * coef);
		res_mul = multiple_complex(array[k_1][j_2], temp);
		sum.real += res_mul.real;
		sum.image += res_mul.image;
	}
	sum.real /= kaef_two;
	sum.image /= kaef_two;
	return sum;
}

complexx back_first_transform(complexx* array, int k_1, int j_2) {
	double coef;
	complexx sum, temp, res_mul;
	sum.real = 0, sum.image = 0;
	for (int j_1 = 0; j_1 < kaef_one; j_1++) {
		coef = (double)(j_1 * k_1) / kaef_one;
		temp.real = cos(2 * M_PI * coef);
		temp.image = sin(2 * M_PI * coef);
		res_mul = multiple_complex(temp, array[j_2 + kaef_two * j_1]);
		sum.real += res_mul.real;
		sum.image += res_mul.image;
	}
	return sum;
}

complexx back_second_transform(complexx* array, int k_1, int k_2) {
	int k;
	double coef;
	complexx sum, temp, res_mul, a_1;
	sum.real = 0, sum.image = 0;
	for (int j_2 = 0; j_2 < kaef_two; j_2++) {
		a_1 = back_first_transform(array, k_1, j_2);
		k = k_1 + kaef_one * k_2;
		coef = (double)(j_2 * k) / (kaef_one * kaef_two);
		temp.real = cos(2 * M_PI * coef);
		temp.image = sin(2 * M_PI * coef);
		res_mul = multiple_complex(a_1, temp);
		sum.real += res_mul.real;
		sum.image += res_mul.image;
	}
	return sum;
}

void half_quick_transform(double* source, complexx* result) {
	int i = 0;
	complexx** a1;
	a1 = new complexx * [n];
	for (int i = 0; i < n; i++) {
		a1[i] = new complexx[n];
	}
	for (int j_2 = 0; j_2 < kaef_two; j_2++) {
		for (int k_1 = 0; k_1 < kaef_one; k_1++) {
			a1[k_1][j_2].real = 0;
			a1[k_1][j_2].image = 0;
			a1[k_1][j_2] = first_transform(source, k_1, j_2);
		}
	}
	for (int k_2 = 0; k_2 < kaef_two; k_2++) {
		for (int k_1 = 0; k_1 < kaef_one; k_1++) {
			result[i] = second_transform(a1, k_1, k_2);
			i++;
		}
	}
}

void back_half_quick_transform(complexx* source, complexx* result) {
	int i = 0;
	for (int k_2 = 0; k_2 < kaef_two; k_2++) {
		for (int k_1 = 0; k_1 < kaef_one; k_1++) {
			result[i] = back_second_transform(source, k_1, k_2);
			i++;
		}
	}
}

int main() {
	double array[n];
	complexx res[n], source[n],
		res1[n], back[n];
	srand(time(NULL));
	cout << fixed << "Source array: ";
	for (int i = 0; i < n; i++) {
		array[i] = rand();
		//cout << fixed << array[i]<< "  ";
	}
	direct_transform_fourier(array, res);
	half_quick_transform(array, res1);
	array[0] = 1;
	array[1] = 0;
	array[2] = 1;
	array[3] = 0;
	array[4] = 1;
	array[5] = 0;
	array[6] = 0;
	array[7] = 0;
	array[8] = 0;
	//array[9] = 0;
	cout.setf(ios::showpos);//shows the plus sign before positive numbers 
	//cout.setf(ios::);
	cout.setf(ios::fixed);
	for (int i = 0; i < n; i++) {		
		cout << fixed << array[i]<< "  ";
	}
	cout << "\n";
	// Discrete is on
	direct_transform_fourier(array, res);
	cout << fixed << "\n       Re Discrete: ";
	for (int i = 0; i < n; i++) {
		cout << fixed << res[i].real<<"  ";
	}
	cout << fixed << "\n       Im Discrete: ";
	for (int i = 0; i < n; i++) {
		cout << fixed << res[i].image << "  ";
	}
	cout << fixed << "\n\n";
	back_transform_fourier(res, source);
	cout << fixed << "  Re Discrete back: ";
	for (int i = 0; i < n; i++) {
		cout << fixed << source[i].real << "  ";
	}
	cout << fixed << "\n";
	cout << fixed << "  Im Discrete back: ";
	for (int i = 0; i < n; i++) {
		cout << fixed << source[i].image << "  ";
	}
	cout << fixed << "\n\n";
	// Discrete is off


	// Half quick is on
	half_quick_transform(array, res1);
	cout << fixed << "     Re half-quick: ";
	for (int i = 0; i < n; i++) {
		cout << fixed << res1[i].real << "  ";
	}
	cout << fixed << "\n";
	cout << fixed << "     Im half-quick: ";
	for (int i = 0; i < n; i++) {
		cout << fixed << res1[i].image << "  ";
	}
	back_half_quick_transform(res1, back);
	cout << fixed << "\n\nRe half-quick back: ";
	for (int i = 0; i < n; i++) {
		cout << fixed << back[i].real << "  ";
	}
	cout << fixed << "\nIm half-quick back: ";
	for (int i = 0; i < n; i++) {
		cout << fixed << back[i].image << "  ";
	}
	cout << "\n\ndisVeshPram  disMnimPram disVeshObr disMnimObr poluVeshPram poluMnimPram poluVeshObr poluMnimObr\n";

	int wi = 10;
	for (int i = 0; i < n; i++) {
	cout <<setw(wi)<< res[i].real << "  " << setw(wi) << res[i].image << "  " << setw(wi) << source[i].real << "  " << setw(wi) << source[i].image << "  " << setw(wi) << res1[i].real << "  " << setw(wi) << res1[i].image << "  " << setw(wi) << back[i].real << "  " << setw(wi) << back[i].image << "\n";
	}
	cout << fixed << endl << endl;
	
	cout << fixed << "\nDiscrete operations: " << count01;
	cout << fixed << "\nHalf-quick operations: " << count_1 + count_2 << endl;
	// Half quick is off

	return 0;
}

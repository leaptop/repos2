#include "stdafx.h"
#include <stdio.h>
#include <clocale>
#include <conio.h>
#include <stdlib.h> //для генерации случайных чисел
const int m = 10, n = 5;

int main() {
	setlocale(LC_ALL, "Russian");
	int i, j;
	float p = 0, v = 10, a[n][n], tmp=0;
	system("CLS");
	srand(11); //инициализация датчика случайных чисел
	for (i = 0; i<n; i++)
		for (j = 0; j<n; j++)
			a[i][j] = (float)rand()*(v - p) / RAND_MAX + p;
	for (i = 0; i<n; i++) {
		printf("\n");
		for (j = 0; j<n; j++) printf("%6.4f ", a[i][j]);
	}

	printf("\n----------------------\n");

	for (i = 0; i<n; i++) {
		for (j = 0; j<n; j++) {
			tmp += a[i][j];
		}
		for (int k = 0; k<n; k++) a[i][k] /= tmp;
		tmp = 0;
	}


	for (i = 0; i<n; i++) {
		printf("\n");
		for (j = 0; j<n; j++) printf("%6.4f ", a[i][j]);
	}


	puts("\n");
	system("PAUSE");
}
// laba94011217.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <stdio.h>
#include <clocale>
#include <conio.h>
#include <stdlib.h> //для генерации случайных чисел
const int m = 10, n = 3;
int random(int r) {
	return rand() % r;
}
int main() {
	setlocale(LC_ALL, "Russian");
	int i, j;
	int p = 0, v = 10, a[n][n], cnt = 2;
	bool bl = true;
	system("CLS");
	srand(11); //инициализация датчика случайных чисел
	while (bl) {
		for (i = 0; i<n; i++)
			for (j = 0; j<n; j++)
				a[i][j] = random(cnt);
		if ((a[0][0] + a[0][1] + a[0][2]) == (a[1][0] + a[1][1] + a[1][2]) && (a[1][0] + a[1][1] + a[1][2]) == (a[2][0] + a[2][1] + a[2][2])
			&& (a[2][0] + a[2][1] + a[2][2]) == (a[0][0] + a[1][0] + a[2][0]) && (a[0][0] + a[1][0] + a[2][0]) == (a[0][1] + a[1][1] + a[2][1]) && (a[0][1] + a[1][1] + a[2][1]) == (a[0][2] + a[1][2] + a[2][2])
			) bl = false;
		cnt++;
	}


	for (i = 0; i<n; i++) {
		printf("\n");
		for (j = 0; j<n; j++) printf("%6d ", a[i][j]);
	}

	printf("\n----------------------\n");

	printf("cnt = %d", cnt);





	puts("\n");
	system("PAUSE");
}


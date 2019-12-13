// laba91011217.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <stdio.h>
#include <clocale>
#include <conio.h>
#include <stdlib.h> //для генерации случайных чиселв
const int m = 10, n = 20;
int random(int r)
{
	return rand() % r;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int i, j, a[m][n];
	system("CLS");
	srand(11); //инициализация датчика случайных чисел
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			a[i][j] = random(20);
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++) printf("%4d", a[i][j]);
	printf("\n----------------------\n");
	for (j = 0; j < m - 1; j = j + 2)
	{
		for (i = 0; i < n; i++)

		{
			int temp = a[j][i];
			a[j][i] = a[j + 1][i];
			a[j + 1][i] = temp;
		}

	}

	for (i = 0; i < m; i++) {
		printf("\n"); for (j = 0; j < n; j++) printf("%4d", a[i][j]);
	}


	puts("\n");
	system("PAUSE");
}


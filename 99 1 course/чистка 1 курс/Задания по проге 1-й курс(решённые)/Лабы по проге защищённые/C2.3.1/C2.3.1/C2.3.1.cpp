// C2.3.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdlib.h>
#include<stdio.h>
#pragma warning( disable : 4996 ) 
#include <clocale>
#include <string>
int random(int N) { return rand() % N; }
int main() {
	setlocale(LC_ALL, "Russian");
	int n, x = -50, y = 50, m = 0, k = 0;
	int *b, *c, *d;
	printf("Введите n(длина массива b)\n");
	scanf("%d", &n);
	b = (int *)malloc(n * sizeof(int));
	c = (int *)malloc(sizeof(int));
	d = (int *)malloc(sizeof(int));
	printf("Исходный массив\n");
	for (int i = 0; i < n; i++)
	{
		b[i] = random(y - x + 1) + x;
		printf("%d\n", b[i]);
		if (b[i] >= 0) { c[m] = b[i]; m++; }
		else { d[k] = b[i]; k++; }

	}
	printf("Положительные\n");
	for (int i = 0; i < m; i++)
	{
		printf("%d\n", c[i]);
	}
	printf("Отрицательные\n");
	for (int i = 0; i < k; i++)
	{
		printf("%d\n", d[i]);
	}

	std::getchar();
	std::getchar();
	return 0;
}


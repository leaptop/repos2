// C2.4.1.cpp : Defines the entry point for the console application.
//Выполнить следующие задания, используя оператор new и функцию malloc().
//1.Задан двумерный динамический массив B  размерности m x n. (n = 5, m вводить с клавиатуры).
//Заполнить её случайными числами.Получить новую динамическую матрицу С[m - 1][n - 1]  
//путем удаления из В строки и столбца, в которых содержится максимальный элемент исходной матрицы.

#include "stdafx.h"
#include<conio.h>
#include<iostream>
#include<time.h>
#include<clocale>
using namespace std;
const int n = 5;
typedef int rown[n];//зачем это вообще нужно, если rown всё равно делается в итоге любых размеров при инициализации?
typedef int rownc[n - 1];
typedef int rownp[n];
int random(int N) { return rand() % N; }
int x = 10, y = 99;
int main()
{
	srand(time(NULL));
	int m;
	cout << "Enter m\n";
	cin >> m;

	rown *b;
	b = new rown[m];
	//int *max ;
	int im, jn, mx = 1;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[i][j] = //pow((i + j),pow(-1,j));
				random(y - x + 1) + x;
			printf("%d ", b[i][j]);
			if (b[i][j] >= mx) { im = i; jn = j; mx = b[i][j]; }
			//max = &b[i][j];
		}
		printf("\n");
	}
	printf("im = %d; jn = %d\n", im, jn);
	printf("------------------------\n");
	rownp *p;//промежуточная матрица
	p = new rownp[m - 1];
	for (int i = 0; i < m - 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i >= im) { p[i][j] = b[i + 1][j]; }
			else { p[i][j] = b[i][j]; }
		}
	}
	rownc *c;
	c = new rownc[m - 1];
	for (int i = 0; i < m - 1; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (j < jn)c[i][j] = p[i][j]; else
				c[i][j] = p[i][j + 1];
		}
	}
	printf("------------------------\n");
	for (int i = 0; i < m - 1; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			printf("%d ", c[i][j]);
		}printf("\n");
	}

	//for (int i = 0; i < m - 1; i++)
	//{
	//	for (int j = 0; j < n - 1; j++)
	//	{
	//		if (j >= jn && i >= im) { c[i][j] = b[i][j + 1]; }
	//		//if (i >= im) { c[i][j] = b[i + 1][j]; }
	//		if (j >= jn) {
	//			for (int q = 0; q < n-1; q++)
	//			{
	//				c[i][j] = b[i][j + 1];
	//			}
	//		}
	//		else { c[i][j] = b[i][j]; }

	//		

	//		printf("%d ", c[i][j]);
	//	}
	//	printf("\n");
	//}
	_getch();
	return 0;
}


//#include <stdio.h>
//#include <stdlib.h>
//const int n = 5; // количество элементов в строке
//typedef int rown[n];//rown - новый тип: массив (строка) из n целых чисел
//
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	int i, j, m;
//	rown *a; // указатель на строку
//	int *b;   // указатель на целое
//	printf("Число строк?  ");
//	scanf_s("%d", &m);
//	a = new rown[m]; // выделяем память под матрицу по адресу a, m строк
//					 // по n элементов в строке 
//	if (a == NULL)
//	{
//		printf("Не удалось выделить память");
//		return 1; // выход по ошибке, код ошибки 1
//	}
//	b = new int[m]; // выделяем память под массив сумм строк (m строк)
//	if (b == NULL)
//	{
//		printf("Не удалось выделить память");
//		return 1; // выход по ошибке, код ошибки 1
//	}
//	// заполняем матрицу случайными числами
//	for (i = 0; i<m; i++)
//	{
//		for (j = 0; j<n; j++)
//		{
//			a[i][j] = rand() % 11;
//			printf("%4d", a[i][j]);
//		}
//		puts("\n");
//	}
//	// записываем в массив b суммы строк матрицы
//	for (i = 0; i<m; i++)
//	{
//		b[i] = 0;
//		for (j = 0; j<n; j++)
//			b[i] += a[i][j];
//	}
//	puts("\n");
//	for (j = 0; j<n; j++)
//		printf("%4d", b[j]);
//	delete a; // освобождаем память, занятую под матрицу a
//	delete b; // освобождаем память, занятую под массив b  
//	puts("\n");
//	system("PAUSE");
//	return 0;
//}
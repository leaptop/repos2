// SaodLab5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"//insert sort
#include <stdlib.h>//for srand
#include <iostream>//  for cout
#include<conio.h>// for _getch()
using namespace std;// for cout

int l = 0, z = 99;
int random(int N) { return rand() % N; }
void FillRand(int *a, int n) {
	for (int i = 0; i < n; i++)
	{
		a[i] = random(z - l + 1) + l;
	}
}
void insertSort(int * a, int n) {//my first code based on pseudo language from a lection
	for (int i = 1; i < n; i++)
	{
		int temp = a[i];
		int j = i - 1;
		for (; j > 0, temp < a[j]; j--)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = temp;
	}

}

void PrintMas(int*a, int n) {
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}
int main()
{
	int *a;
	for (int i = 100; i <= 100; i += 100)
	{
		a = new int[i];
		FillRand(a, i);
		cout << " original ";
		PrintMas(a, i);
		cout << " original " << endl << endl;
		insertSort(a, i);
		cout << " sorted ";
		PrintMas(a, i);
		cout << " sorted " << endl << endl;




	}
	_getch();
	return 0;
}


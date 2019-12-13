// SaodLab6QuicSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
void swap(int & a, int & b) {
	int temp = a;
	a = b;
	b = temp;
}
void QuickSort(int L, int R, int a[]) {
	//int x = a[(L + R) / 2];
	int x = a[L];
	int i = L;
	int j = R;
	while (i <= j) {
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;
		if (i <= j) {
			//swap(a[i], a[j]);
			int tmp = a[i];// самый простой способ
			a[i] = a[j];
			a[j] = tmp;
			i++;
			j--;
			
			for (int z = 1; z < 10; z++)
			{
				printf("%3d ", a[z]);
			}
			printf("L = %3d, R = %3d, x = %3d, a[L] = %3d, j = %3d, a[i] = %3d, a[j] = %3d", L, R, x, a[L], j, a[i], a[j]);
			printf("\n");
		}
	}
	if (L < j)QuickSort(L, j, a);
	if (i < R)QuickSort(i, R, a);
}

int main()
{
	int a[10] = { 0,19,-3,0,54,130,15,1,11, -50 };
	for (int i = 1; i < 10; i++)
	{
		printf("%3d ", a[i]);
	}printf("\n");
	QuickSort(1, 9, a);
	for (int i = 1; i < 10; i++)
	{
		printf("%3d ", a[i]);
	}
	_getch();
	return 0;
}


#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
//#pragma warning( disable : 4507 34; once : 4385; error : 164; error : 4430 ) 
const int N = 100;//laba 7.2
int random(int N) { return rand() % N; }
int main()

{

	system("CLS");
	int a = 0, b = 50, temp = 0;
	int A[N];
	for (int i = 0; i < N; i++)
	{
		A[i] = random(b - a + 1) + a; printf("  A[i] = %d\n", A[i]);
	}
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N; j++)if (A[i] = A[j]) {
			for (int k = j; k < N - 1; k++)A[k] = A[k + 1];
		}
	}
	printf("-------------------\n");
	for (int i = 0; i < N; i++)printf("%d\n", A[i]);
	system("PAUSE");
	return 0;
}
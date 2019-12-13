#include <stdlib.h>
#include <stdio.h>
const int N = 100;
int random(int N) { return rand() % N; }
main()
{
	printf("-------------------");
	system("CLS");
	int i, A[N], a = 0, b = 50, temp;
	float X[N];
	for (i = 0; i < N; i++)
	{
		A[i] = random(b - a + 1) + a; printf("  A[i] = %d\n", A[i]);
	}
	for (int i = 0; i<N - 1; i++) {
		for (int j = i + 1; j<N; j++)if (A[i] = A[j]) {
			for (int k = j; k<N - 1; k++)A[k] = A[k + 1];
		}
	}
	printf("-------------------");
	for (int i = 0; i<N; i++)printf("%d\n", A[i]);
	system("PAUSE");
	return 0;
}
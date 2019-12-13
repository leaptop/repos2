#include <stdio.h>
#include <stdlib.h>
#include <clocale>
#include  <math.h>
float f(int a, int b, int c, int x) { return a*x*x*sin(x) + b*x + c; }

int main()


{
	setlocale(LC_ALL, "Russian");
	system("CLS");
	float a = 2.14, b = -4.21, c = 3.25, xn = -4.5, xk = -33.5, h = 0.5, A[58], x, tmp, o;
	for (int i = 0; i*h >= -33.5; i++) {
		A[i] = f(a, b, c, xn - i*h);
	}

	for (int j = 0; j<sizeof(A) / sizeof(int) - 1; j++) {
		for (int i = j; i<sizeof(A) / sizeof(int) - 1; i++) if (A[j]<A[i]) {
			tmp = A[i]; A[i] = A[j]; A[j] = tmp;
		}
	}

}


system("PAUSE");
return 0;
}
#include "func.h"
//#include "func.cpp"
#pragma warning(disable : 4996)

using namespace std;
int random(int n) { return rand() % n; }
int main() {

	int g = 0;
	const int r = 100;
	int *a = new int[r];
	int *b = new int[r];
	float *p; // указатель на вещественные числа 
	p = (float *)malloc(r * sizeof(float));// ¬ыдел€ем  пам€ть под n вещественных чисел;
	srand(NULL);

	int m = -100, n = 100, time = 0;
	for (int i = 0; i < r; i++) {
		a[i] = (random(n - m + 1) + m);
		b[i] = a[i];
	}
	
	for (int i = 0; i < r; i++)
	{
		p[i] = (float)rand()*(n - m) / RAND_MAX + m;
	}
	cout << "A number of comarasments + movements" << endl;
	time = timer(a, r, bubbleSort);
	cout << "Bubble:   " << time << endl;
	time = 0;

	for (int i = 0; i < r; i++)
	{
		a[i] = b[i];
	}
	time = timer(a, r, CocktailSort);
	cout << "Shaker:   " << time << endl;
	time = 0;

	for (int i = 0; i < r; i++)
	{
		a[i] = b[i];
	}
	time = timer(a, r, shellSort);
	cout << "Shell:    " << time << endl;
	time = 0;

	_getch();
}
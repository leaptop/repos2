#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

int main()
{
	int i, j, n = 3, m;

	setlocale(LC_ALL, "RUS");
	m = n + 1;
	//double matrix[4][5] = {{2,5,4,1,20},{1,3,2,1,11},{2,9,10,7,40},{3,8,9,2,37}};
	double matrix[3][4] = { {-1, 1, 1, 2}, {-1, 2, -1, 0},{3, 1, -2, -3} };
	system("cls");

	cout << "\nМатрица: " << endl;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			cout << setw(2) << matrix[i][j] << "  ";
		cout << endl;
	}
	cout << endl;

	double  tmp, tmp1, del, ref;
	int k, key;
	double *xx = new double[m];
	cout << "Классический - 1/Модифицированный - 2 " << endl; cin >> key;

	switch (key) {
	case 1: {
		cout << "Processing :" << endl;
		for (i = 0; i < n; i++) {
			tmp = matrix[i][i];

			cout << "Берем число " << matrix[i][i] << endl;

			for (j = n; j >= i; j--) {
				cout << "и делим  " << j << "- й элемент " << i + 1 << " - й строки на " << matrix[i][i] << endl;
				matrix[i][j] /= tmp;
			}
			for (j = i + 1; j < n; j++) {
				tmp = matrix[j][i];
				for (k = i; k <= n; k++) {
					cout << "Отнимаем : " << matrix[j][k] << "-" << tmp << "*" << matrix[i][k] << endl;
					matrix[j][k] -= tmp * matrix[i][k];
				}
			}

		}
		break;
	}
	case 2: {

		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 1; j < n; j++)
			{
				if (fabs(matrix[i][i]) < fabs(matrix[j][i]))
				{
					for (int n = 0; n < m; n++)
					{
						ref = matrix[i][n];
						matrix[i][n] = matrix[j][n];
						matrix[j][n] = ref;
					}
				}
			}

			del = matrix[i][i];
			for (int j = n; j >= i; j--)
				matrix[i][j] /= del;
			for (int q = i + 1; q < n; q++)
			{
				del = matrix[q][i];
				for (int k = i; k <= n; k++)
					matrix[q][k] -= del * matrix[i][k];
			}
		}
	}break;
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			cout << setw(6) << matrix[i][j] << "  ";
		cout << endl;
	}
	cout << endl;



	xx[n - 1] = matrix[n - 1][n];
	for (i = n - 2; i >= 0; i--) {
		xx[i] = matrix[i][n];
		for (j = i + 1; j < n; j++)
			xx[i] -= matrix[i][j] * xx[j];
	}

	cout << endl;

	cout << "Answers  : " << endl;
	char  a[12] = { 'x','y','z','k','l','m','n','o','p','q','r','s' };

	for (i = 0; i < n; i++)
		cout << a[i] << " = " << setw(5) << xx[i] << " " << endl;


	//delete[] matrix, xx;
	system("PAUSE");
	return 0;
}

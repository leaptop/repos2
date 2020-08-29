#include "fractions.h"
#include "stdc++.h"
using namespace std;


using namespace std;

void fill(Fraction* arr, int n, Fraction c)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = c;
	}
}

bool in(int* basis, int n, int num)
{
	for (int i = 0; i < n; i++)
		if (basis[i] == num)
			return true;

	return false;
}

void print_simplex(Fraction** arr, int n, int m, Fraction* simplex_var, int* basis, bool isLast)
{
	cout << "basic var. |  " << 1 << "  | ";

	for (int i = 0; i < n - 1; i++)
	{
		cout << "X[" << i + 1 << "]    ";
	}

	if (!isLast)
		cout << "  | s.r.";
	cout << endl;

	for (int i = 0; i < m; i++)
	{
		cout << "X[" << basis[i] + 1 << "]          ";

		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << "      ";
		}

		if (!isLast)
		{
			if (simplex_var[i] > Fraction(0, 1))
				cout << simplex_var[i];
			else
				cout << "  -  ";
		}
		cout << endl;
	}

	cout << "Z             ";

	for (int j = 0; j < n; j++)
	{
		cout << arr[m][j] << "      ";
	}


}


void read(Fraction** arr, int n, int m)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
}

void scan(int n, int m, Fraction* Z, bool& mx, Fraction** arr)
{
	string str;

	for (int i = 0; i < n; i++)
		cin >> Z[i];

	cin >> str;

	if (str == "max")
		mx = true;
	else
		mx = false;

	read(arr, n, m);
}


void print(Fraction** arr, int n, int m)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			cout << arr[i][j] << " ";
		}

		cout << "| " << arr[i][n - 1] << endl;
	}

	cout << endl;
}

void swap(Fraction** arr, int n, int from, int to)
{
	Fraction c;
	for (int i = 0; i < n; i++)
	{
		c = arr[from][i];
		arr[from][i] = arr[to][i];
		arr[to][i] = c;
	}
}

void JordanGauss(Fraction** arr, Fraction* Z, bool maximum, int n, int m)
{
	int i, j, y = 0, mx_ind = 0, zz = 0;
	bool check;
	Fraction mx;
	int solution_num = 1;
	bool minimize = maximum;
	for (int i = 0; i < m; i++)

		for (i = 0; i < n; i++)
		{
			if (y > m - 1 || i == n - 1)
				break;

			check = false;
			mx_ind = y;
			mx = Fraction(0, 1);

			for (j = y; j < m; j++)
			{
				if (Fraction::Abs(arr[j][i]) > mx)
				{
					mx = Fraction::Abs(arr[j][i]);
					mx_ind = j;
					check = true;
				}
			}

			swap(arr, n, y, mx_ind);

			if (!check)
				continue;

			print(arr, n, m);

			for (j = i + 1; j < n; j++)
			{
				for (int l = 0; l < m; l++)
				{
					if (l != y)
					{
						arr[l][j] = arr[l][j] - (arr[y][j] * arr[l][i]) / arr[y][i];
					}
				}
			}


			for (j = i + 1; j < n; j++)
			{
				arr[y][j] = arr[y][j] / arr[y][i];
			}

			arr[y][i] = arr[y][i] / arr[y][i];

			for (j = 0; j < m; j++)
			{
				if (j != y)
					arr[j][i] = Fraction(0, 1);
			}

			print(arr, n, m);


			y++;
		}
	//SIMPLEX METHOD
	Fraction** simplex_table = new Fraction * [m + 1];
	Fraction* solution = new Fraction[n - 1];
	Fraction* simplex_var = new Fraction[m];

	fill(solution, n - 1, Fraction(0, 1));

	int* basis = new int[m];

	for (i = 0; i < m; i++)
		basis[i] = i;

	Fraction* Z_tmp = new Fraction[n];

	for (int i = 0; i < n; i++)
		Z_tmp[i] = Fraction(0, 1);

	cout << endl;

	if (!maximum)
	{
		for (i = 0; i < n; i++)
			Z[i] = Z[i] * Fraction(-1, 1);
	}

	for (i = 0; i < m; i++)
	{
		for (int j = m; j <= n - 1; j++)
		{
			//		cout<<"i="<<i<<", j="<<j<<"  "<<Z_tmp[j]<<"   "<<Z[i]<<"    "<<arr[i][j]; 
			if (j == n - 1)
				Z_tmp[j] = Z_tmp[j] + Z[i] * arr[i][j];
			else
				Z_tmp[j] = Z_tmp[j] + Z[i] * Fraction(-1, 1) * arr[i][j];

			//		cout<<"    Result is "<<Z_tmp[j]<<endl;
		}
	}
	cout << endl << "Z = ";

	for (i = 0; i < n - 1; i++)
	{
		if (!(Z_tmp[i] == Fraction(0, 1)))
		{
			cout << " " << Z_tmp[i] << " X[" << i + 1 << "]";
			if (Z_tmp[i + 1] > Fraction(0, 1))
				cout << "+";
		}
	}
	cout << Z_tmp[n - 1] << "  -> max" << endl << endl;


	for (i = 0; i < m + 1; i++)
	{
		simplex_table[i] = new Fraction[n];
	}

	for (i = 0; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			simplex_table[i][j] = arr[i][j - 1];
		}
	}

	for (i = 0; i < m; i++)
		simplex_table[i][0] = arr[i][n - 1];

	for (i = 1; i < n - 1; i++)
		simplex_table[m][i + 1] = Z_tmp[i] * Fraction(-1, 1);

	simplex_table[m][0] = Fraction(0, 1);

	for (i = 0; i < m; i++)
		solution[basis[i]] = simplex_table[i][0];

	for (i = 0; i < n - 1; i++)
		simplex_table[m][0] = simplex_table[m][0] + solution[i] * Z_tmp[i];

	simplex_table[m][0] = simplex_table[m][0] + Z_tmp[n - 1];

	Fraction minimum(0, 1);

	int min_ind = 0, min_row = 0;


	bool optimal_solution = false;

	while (1)
	{
		minimum = Fraction(0, 1);

		for (i = 1; i < n; i++)
		{
			if (minimum > simplex_table[m][i])
			{
				minimum = simplex_table[m][i];
				min_ind = i;
			}
		}


		minimum = Fraction(10000, 1);

		for (i = 0; i < m; i++)
		{
			if (simplex_table[i][min_ind] > Fraction(0, 1))
			{
				simplex_var[i] = simplex_table[i][0] / simplex_table[i][min_ind];
				if (minimum > simplex_var[i])
				{
					minimum = simplex_var[i];
					min_row = i;
				}
			}
			else
				simplex_var[i] = Fraction(-1, 1);
		}

		optimal_solution = true;


		for (i = 1; i < n; i++)
		{
			if (!(simplex_table[m][i] > Fraction(0, 1)) && !(simplex_table[m][i] == Fraction(0, 1)))
			{
				optimal_solution = false;
			}
		}


		print_simplex(simplex_table, n, m, simplex_var, basis, optimal_solution);
		cout << endl << endl;

		fill(solution, m, Fraction(0, 1));

		for (i = 0; i < m; i++)
			solution[basis[i]] = simplex_table[i][0];

		cout << "X[" << solution_num << "] = (";

		for (i = 0; i < n - 1; i++)
		{
			cout << solution[i];
			if (i < n - 2)
				cout << ";";
		}

		cout << "),  Z(X[" << solution_num << "]) = " << simplex_table[m][0] << endl << endl;
		solution_num++;

		if (optimal_solution)
			break;


		for (i = 0; i < n; i++)
		{
			for (int j = 0; j <= m; j++)
			{
				if (i != min_ind && j != min_row)
				{
					/*		cout<<simplex_table[j][i]<< "      "<<
							simplex_table[j][min_ind]<<"             "<<
							simplex_table[min_row][i]<<endl;
					*/		simplex_table[j][i] = simplex_table[j][i] - (simplex_table[j][min_ind] * simplex_table[min_row][i]) / simplex_table[min_row][min_ind];

				}
			}

		}

		for (i = 0; i < n; i++)
		{
			if (i != min_ind)
				simplex_table[min_row][i] = simplex_table[min_row][i] / simplex_table[min_row][min_ind];
		}

		simplex_table[min_row][min_ind] = Fraction(1, 1);

		for (i = 0; i <= m; i++)
		{
			if (i != min_row)
				simplex_table[i][min_ind] = Fraction(0, 1);
		}

		for (i = 0; i < m; i++)
		{
			if (basis[i] == min_row)
			{
				basis[i] = min_ind - 1;
				break;
			}
		}


	}

	cout << "Z";

	if (!minimize)
		cout << "min";
	else
		cout << "max";

	cout << " =  ";

	Fraction simplex_res(0, 1);

	for (i = 0; i < n - 1; i++)
	{
		simplex_res = simplex_res + Z_tmp[i] * solution[i];
	}

	simplex_res = simplex_res + Z_tmp[n - 1];

	if (!maximum)
		cout << simplex_res * Fraction(-1, 1);
	else
		cout << simplex_res;

	cout << endl;
}


int main()
{
	/*int n, m;
	bool mx = true;

	cin >> n >> m;


	Fraction* Z = new Fraction[n];
	Fraction** arr = new Fraction * [m];

	for (int i = 0; i < m; i++)
	{
		arr[i] = new Fraction[n];
	}

	scan(n, m, Z, mx, arr);
	print(arr, n, m);*/
	int n = 6, m = 4;
	Fraction** masBumaga = new Fraction * [m];//m - число строк
	for (int i = 0; i < m; i++)
	{
		masBumaga[i] = new Fraction[n];//число столбцов
	}
	masBumaga[0][0] = 4;/*Fraction(4,1);*/ masBumaga[0][1] = -11; masBumaga[0][2] = 13; masBumaga[0][3] = -6; masBumaga[0][4] = 8; masBumaga[0][5] = 8;
	masBumaga[1][0] = 7; masBumaga[1][1] = 12; masBumaga[1][2] = 5; masBumaga[1][3] = -3; masBumaga[1][4] = 9; masBumaga[1][5] = 54;
	masBumaga[2][0] = -6; masBumaga[2][1] = 9; masBumaga[2][2] = -17; masBumaga[2][3] = 13; masBumaga[2][4] = -7; masBumaga[2][5] = -16;
	masBumaga[3][0] = -17; masBumaga[3][1] = -7; masBumaga[3][2] = -30; masBumaga[3][3] = 30; masBumaga[3][4] = -14; masBumaga[3][5] = -86;
	Fraction* Z = new Fraction[n];
	print(masBumaga, n, m);
	bool mx = true;
	JordanGauss(masBumaga, Z, mx, n, m);

	return 0;
}

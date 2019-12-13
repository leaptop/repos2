//#include "func.h"

#pragma warning(disable : 4996)
//using namespace std;// for cout(for C++ only)

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// A function to implement bubble sort
int bubbleSort(int arr[], int n)
{
	int i, j, cnt = 0;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place   
		for (j = 0; j < n - i - 1; j++) {
			cnt++;
			if (arr[j] > arr[j + 1]) {
				cnt += 3;
				swap(&arr[j], &arr[j + 1]);
			}
		}

	return cnt;
}

int timer(int a[], int n, int(*f) (int[], int)) {

	return f(a, n);;
}


int CocktailSort(int a[], int n)
{
	bool swapped = true;
	int start = 0;
	int end = n - 1;
	int c = 0;
	int m = 0;

	while (swapped)
	{
		swapped = false;

		for (int i = start; i < end; ++i)
		{
			c++;
			if (a[i] > a[i + 1])
			{
				m += 3;
				swap(&a[i], &a[i + 1]);
				swapped = true;
			}
		}

		if (!swapped)
			break;
		swapped = false;
		--end;

		for (int i = end - 1; i >= start; --i)
		{
			c++;
			if (a[i] > a[i + 1])
			{
				m += 3;
				swap(&a[i], &a[i + 1]);
				swapped = true;
			}
		}

		++start;
	}
	return c + m;
}
void iswap(int &n1, int &n2) {
	int temp = n1;
	n1 = n2;
	n2 = temp;
}
int HeapSort(int a[], int n) {
	unsigned sh = 0u; // Смещение
	bool b;
	int c = 0, m = 0;
	do {
		b = false;
		for (unsigned i = 0u; i < n; ++i) {
			c++;
			if (i * 2 + 2 + sh < n) {
				c++;
				if ((a[i + sh] > /*<*/ a[i * 2 + 1 + sh]) || (a[i + sh] > /*<*/ a[i * 2 + 2 + sh])) {
					c++;
					if (a[i * 2 + 1 + sh] < /*>*/ a[i * 2 + 2 + sh]) {
						m += 3;
						iswap(a[i + sh], a[i * 2 + 1 + sh]);
						b = true;
					}
					else {
						c++;
						if (a[i * 2 + 2 + sh] < /*>*/ a[i * 2 + 1 + sh]) {
							m += 3;
							iswap(a[i + sh], a[i * 2 + 2 + sh]);
							b = true;
						}
					}
				}
				// Дополнительная проверка для последних двух элементов;
				// с её помощью можно отсортировать пирамиду
				// состоящую всего лишь из трёх элементов
				c++;
				if (a[i * 2 + 2 + sh] < /*>*/ a[i * 2 + 1 + sh]) {
					m += 3;
					iswap(a[i * 2 + 1 + sh], a[i * 2 + 2 + sh]);
					b = true;
				}
			}
			else {
				c++;
				if (i * 2 + 1 + sh < n) {
					c++;
					if (a[i + sh] > /*<*/ a[i * 2 + 1 + sh]) {

						m += 3;
						iswap(a[i + sh], a[i * 2 + 1 + sh]);
						b = true;
					}
				}
			}
		}c++;
		if (!b) {

			++sh; // Смещение увеличивается, когда на текущем этапе сортировать больше нечего
		}
	} while (sh + 2 < n); // Конец сортировки


	return c + m;
}
int quickSort(int arr[], int left, int right) {
	int i = left, j = right;
	int tmp, c = 0, m = 0;
	int pivot = arr[(left + right) / 2];

	/* partition */

	while (i <= j) {
		c++;
		while (arr[i] < pivot) {
			c++;
			i++;
		}
		while (arr[j] > pivot) {
			c++;
			j--;
		}c++;
		if (i <= j) {
			m += 3;
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	};

	/* recursion */
	if (left < j) {
		c++;
		quickSort(arr, left, j);
	}
	if (i < right) {
		c++;
		quickSort(arr, i, right);
	}
	return c + m;
}
int increment(int inc[], int size)
{
	int p1, p2, p3, s, c;
	p1 = p2 = p3 = 1;
	s = -1;
	do
	{

		if (++s % 2)
		{
			inc[s] = 8 * p1 - 6 * p2 + 1;
		}
		else
		{
			inc[s] = 9 * p1 - 9 * p3 + 1;
			p2 *= 2;
			p3 *= 2;
		}
		p1 *= 2;
	} while (3 * inc[s] < size);

	return s > 0 ? --s : 0;
}
int shellSort(int a[], int size)
{
	int inc, i, j, seq[40];
	int s, c = 0;

	c += 2;
	s = increment(seq, size); // вычисление последовательности приращений
	while (s >= 0)  // сортировка вставками с инкрементами inc[] 
	{
		c++;
		inc = seq[s--];
		for (i = inc; i < size; ++i)
		{
			c++;
			int temp = a[i];
			for (j = i; (j >= inc) && (temp < a[j - inc]); j -= inc) {
				c += 4;
				a[j] = a[j - inc];
			}
			c++;
			a[j] = temp;
		}
	}
	return c;
}

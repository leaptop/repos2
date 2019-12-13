#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex>
#include <bitset>
#include <stack>
#include <iostream>
#define _USE_MATH_DEFINES
#define M_PI 3.14159265358979323846
#define n 16
#define r 4// log2(n)

using namespace std;

//const int n = 16;
int count = 0;

void create_A_0(complex <double>* array, complex <double>* result) {//что такое complex <double>* array?// похоже просто указатели на начало массивов
	int index = 0;//типа complex(ДА)
	unsigned long long sum = 0;
	//const int r = log2(n);
	/*bool test( size_t pos ) const; Возвращает значение бита, который находится в позиции pos.*/
	bitset <r> set_bits;//что эта функция делает? Зачем здесь эта странная штука bitset?
	for (int loop = 0; loop < n; loop++) {
		for (size_t i = 0, j = r - 1; i < r; i++) {
			index += pow(2, i) * set_bits.test(j--);
		}
		result[loop] = array[index];
		index = 0;
		sum = set_bits.to_ulong();
		sum++;
		set_bits = sum;
	}
}

void FFT(complex <double>* array, complex <double>* a_0) {
	create_A_0(array, a_0);
	complex <double> rotate_multiplier = exp(complex <double>(0, (-2 * M_PI) / n));
	stack < complex <double> > W;
	int step = 0;
	for (step = n; step != 1; step /= 2) {
		W.push(rotate_multiplier);
		rotate_multiplier *= rotate_multiplier;
	}
	for (step = 2; step <= n; step *= 2) {
		rotate_multiplier = W.top();
		W.pop();
		for (int i = 0; i < n; i += step) {
			complex <double> w(1, 0);
			for (int k = 0; k < step / 2; k++) {
				complex <double> temp = a_0[k + i];
				a_0[k + i] = temp + a_0[k + i + step / 2] * w;
				a_0[k + i + step / 2] = temp - a_0[k + i + step / 2] * w;
				w *= rotate_multiplier;
				::count += 5;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		a_0[i] /= n;
		::count++;
	}
}

void back_FFT(complex <double>* array) {
	complex <double>* result = new complex <double>[n];
	for (int i = 0; i < n; i++) {
		array[i] = conj(array[i]);
	}
	FFT(array, result);
	for (int i = 0; i < n; i++) {
		array[i] = conj(result[i]);
		array[i] *= n;
	}
}

int main() {
	complex <double> source[n];//тип: std::complex<double>[6]
	/*массив из 16-ти элементов с именем source. Каждый элемент имеет тип std::complex<double>
	//при этом в каждом элементе есть какое-то "базовое представление" типа std::complex<double>
	c массивом из двух чисел. Видимо, это просто внутренние дела встроенного класса и числа эти просто нужны
	для хранения значений real и imag. Ну да, так и происходит, туда тоже назанчаются значения, равные основным real & imag*/
	
	complex <double>* result = new complex <double>[n];//тип: std::complex<double>*
	/*Здесь, видимо, указатель result теперь указывает на начало массива элементов типа complex.(Да)
	Почему-то создаются они по-разному, а функция FFT всё равно принимает их как два одинаковых типа complex <double>* array(array - имя указателя).
	Вот за это я не люблю си. За возможность писать один и тот же код по-разному. Ведь начинаешь думать, что это что-то сложное и важное...
	Вспоминая 1-й курс, кажется доходит - первый случай - статическая инициализация и source больше не расширится, а вот result может 
	расшириться новыми элементами. */
	printf("Source massive: ");
	for (int i = 0; i < n; i++) {
		if ((i + 1) % 2 == 0) source[i] = 1.0;
		else source[i] = 0.0;
		cout << fixed << source[i].real() << " ";
	}
	cout.precision(5);
	FFT(source, result);
	cout << fixed << "\n\nRe part: ";
	for (int i = 0; i < n; i++) {
		cout << fixed << result[i].real() << " ";
	}
	cout << fixed << "\nIm part: ";
	for (int i = 0; i < n; i++) {
		cout << fixed << result[i].imag() << " ";
	}

	back_FFT(result);
	cout << fixed << "\n\nRe part: ";
	for (int i = 0; i < n; i++) {
		cout << fixed << result[i].real() << " ";
	}
	cout << fixed << "\nIm part: ";
	for (int i = 0; i < n; i++) {
		cout << fixed << result[i].imag() << " ";
	}
	cout << fixed << endl << endl << "Operations:" << ::count / 2 << endl;

	return 0;
}
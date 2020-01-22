#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <complex>
#include <bitset>
#include <stack>
#include <iostream>
#define _USE_MATH_DEFINES
#define M_PI 3.14159265358979323846
//nlogn = 16384 одна из полубыстрой или дискретной или быстрой
//p1, p2 неправильно считаются. надо чтобы они были близки друг другу и к корню из n. Здесь при n = 1024, это 32
using namespace std;
int count = 0, count_dp = 0, count_pb_1 = 0, count_pb_2 = 0, count_pb_3 = 0, count_b_1 = 0, count_b_2 = 0;
int size = 1024;//n*n
const int r = 4;
int p_1, p_2;

void direct_transform_fourier(vector <int> array, complex <double> *result) {
    complex <double> sum(0, 0);
    double coef_real, coef_image;
    for (int k = 0; k < array.size(); k++) {
        for (int j = 0; j < array.size(); j++) {
            count_dp += 5;
            coef_real = cos((-2 * M_PI * k * j) / array.size()) * array[j];
            coef_image = sin((-2 * M_PI * k * j) / array.size()) * array[j];
            complex <double> A(coef_real, coef_image);
            sum += A;
        }
        sum /= array.size();
        result[k] = sum;
        sum = 0;
    }
}

void back_transform_fourier(complex <double> *array, int size, complex <double> *result) {
    complex <double> sum, res_mul;
    double coef_real, coef_image;
    for (int k = 0; k < size; k++) {
        for (int j = 0; j < size; j++) {
            count_dp += 5;
            coef_real = cos((2 * M_PI * k * j) / size);
            coef_image = sin((2 * M_PI * k * j) / size);
            complex <double> A(coef_real, coef_image);
            res_mul = A * array[j];
            sum += res_mul;
        }
        result[k] = sum;
        sum = 0;
    }
}

complex <double> first_transform(vector <int> array, int k_1, int j_2) {
    double coef, coef_real, coef_image;
    complex <double> sum;
    for (int j_1 = 0; j_1 < p_1; j_1++) {
        count_pb_1 += 4;                            //first trudo
        coef = (double) (j_1 * k_1) / p_1;
        coef_real = cos(-2 * M_PI * coef) * array[j_2 + p_2 * j_1];
        coef_image = sin(-2 * M_PI * coef) * array[j_2 + p_2 * j_1];
        complex <double> temp(coef_real, coef_image);
        sum += temp;
    }
    sum /= p_1;
    return sum;
}

complex <double> second_transform(complex <double> **array, int k_1, int k_2) {
    int k;
    double coef, coef_real, coef_image;
    complex <double> sum, res_mul;
    for (int j_2 = 0; j_2 < p_2; j_2++) {
        count_pb_2 += 7;                        //second trudo
        k = k_1 + p_1 * k_2;
        coef = (double) (j_2 * k) / (p_1 * p_2);
        coef_real = cos(-2 * M_PI * coef);
        coef_image = sin(-2 * M_PI * coef);
        complex <double> temp(coef_real, coef_image);
        res_mul = array[k_1][j_2] * temp;
        sum += res_mul;
    }
    sum /= p_2;
    return sum;
}

complex <double> back_first_transform(complex <double> *array, int k_1, int j_2) {
    double coef, coef_real, coef_image;
    complex <double> sum, res_mul;
    for (int j_1 = 0; j_1 < p_1; j_1++) {
        count_pb_1 += 4;
        coef = (double) (j_1 * k_1) / p_1;
        coef_real = cos(2 * M_PI * coef);
        coef_image = sin(2 * M_PI * coef);
        complex <double> temp(coef_real, coef_image);
        res_mul = temp * array[j_2 + p_2 * j_1];
        sum += res_mul;
    }
    return sum;
}

complex <double> back_second_transform(complex <double> *array, int k_1, int k_2) {//is called from back_half_quick_transform(not in my case)
    int k;
    double coef, coef_real, coef_image;
    complex <double> sum, res_mul, a_1;
    for (int j_2 = 0; j_2 < p_2; j_2++) {
        count_pb_2 += 7;
        a_1 = back_first_transform(array, k_1, j_2);
        k = k_1 + p_1 * k_2;
        coef = (double) (j_2 * k) / (p_1 * p_2);
        coef_real = cos(2 * M_PI * coef);
        coef_image = sin(2 * M_PI * coef);
        complex <double> temp(coef_real, coef_image);
        res_mul = a_1 * temp;
        sum += res_mul;
    }
    return sum;
}

void half_quick_transform(vector <int> source, complex <double> *result) {//half quick consists of these two transforms
    int i = 0;
    complex <double> **a1;
    a1 = new complex <double> *[size];
    for (int i = 0; i < size; i++) {
        a1[i] = new complex <double> [size];
    }
    for (int j_2 = 0; j_2 < p_2; j_2++) {
        for (int k_1 = 0; k_1 < p_1; k_1++) {
            a1[k_1][j_2] = first_transform(source, k_1, j_2);// 1
        }
    }
    for (int k_2 = 0; k_2 < p_2; k_2++) {
        for (int k_1 = 0; k_1 < p_1; k_1++) {
            result[i] = second_transform(a1, k_1, k_2);// 2
            i++;
        }
    }
}

void back_half_quick_transform(complex <double> *source, complex <double> *result) {
    int i = 0;
    for (int k_2 = 0; k_2 < p_2; k_2++) {
        for (int k_1 = 0; k_1 < p_1; k_1++) {
            result[i] = back_second_transform(source, k_1, k_2);
            i++;
        }
    }
}

void normal_svertka(vector <int> a, vector <int> b, vector <int> &result) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            result[i + j] += a[i] * b[j];
            count += 2;
        }
    }
}
void svertka_DPF(vector <int> a, vector <int> b, complex <double> *result) {
    size_t size = a.size();
    complex <double> res[size];
    complex <double> a_dpf[size];
    complex <double> b_dpf[size];
    direct_transform_fourier(a, a_dpf);
    direct_transform_fourier(b, b_dpf);
    for (int i = 0; i < size; i++) {
        res[i] = a_dpf[i] * b_dpf[i];
        res[i] *= size;
        count_dp += 2;
    }
   // back_transform_fourier(res, size, result);
}

void svertka_PBPF(vector <int> a, vector <int> b, complex <double> *result) {
    size_t size = a.size();
  //  for (int i = size - 1; i > 1; i--) {
   //     if (size % i == 0) {
    //        p_1 = i;
    //        p_2 = size / p_1;
    //        break;
  //      }
 //   }
 p_1 = 32; p_2 = 64;
    complex <double> res[size];
    complex <double> a_pbpf[size];
    complex <double> b_pbpf[size];
    half_quick_transform(a, a_pbpf);
    half_quick_transform(b, b_pbpf);
    for (int i = 0; i < size; i++) {
        res[i] = a_pbpf[i] * b_pbpf[i];
        res[i] *= size;
        count_pb_3 += 2;                    //3-hr for half quick
    }
    //back_half_quick_transform(res, result);
}
int main() {
    srand(time(NULL));
    //printf("1) Normal svertka\n2) Svertka DPF\n3) Svertka PBDF\n4) Svertka BPF\n\n");
  //  int size_1, size_2;
    int size_1 = 1024, size_2 = 1024;
   // printf("Vvedite razmer massiva A: ");
  //  scanf("%d", &size_1);
  //  printf("Vvedite razmer massiva B: ");
  //  scanf("%d", &size_2);
    vector <int> a(size_1);
    vector <int> b(size_2);
    vector <int> c(size_1 + size_2 - 1);
   // printf("\n\nMassiv A: ");
    for (int i = 0; i < size_1; i++) {
        a[i] =  (rand() ) ;
       // printf("%d ", a[i]);
    }
  //  printf("\nMassiv B: ");

    for (int i = 0; i < size_2; i++) {
        b[i] = (rand() );
       // printf("%d ", b[i]);
    }
    printf("Resultat normal svertka: ");
    normal_svertka(a, b, c);
    //for (int i = 0; i < size_1 + size_2 - 1; i++) //printf("%d ", c[i]);
    //printf("\n\n");
    printf(" Operations: %d\n", count);

    // DPF
    //printf("Vvedite razmer massiva DPF: ");
    //scanf("%d", &size);
    vector <int> arr_1(2 * size);//arr_1 здесь имя вектора. Он объявлен с именем arr_1 и типом vector<int>
    vector <int> arr_2(2 * size);
    complex <double> result[2 * size - 1];
 //   printf("\n\nMassiv A: ");
    for (int i = 0; i < size; i++) {
        arr_1[i] = (rand() );
   //     printf("%d ", arr_1[i]);
    }
   // printf("\nMassiv B: ");
    for (int i = 0; i < size; i++) {
        arr_2[i] = (rand() );
      //  printf("%d ", arr_2[i]);
    }
    svertka_DPF(arr_1, arr_2, result);
  //  printf("\n\nReal part: ");
    for (int i = 0; i < 2 * size - 1; i++) {
     //   printf("%lf ", result[i].real());
    }
   // printf("\nImage part: ");
    for (int i = 0; i < 2 * size - 1; i++) {
    //    printf("%lf ", result[i].imag());
    }
   // printf("\n\n");
    printf("Discrete Operations: %d\n", count_dp);

    // PBPF
    //printf("Vvedite razmer massiva PBPF: ");
   // scanf("%d", &size);
   // vector <int> arr_1_PBPF(2 * size);//зачем умножать на 2???
    //vector <int> arr_2_PBPF(2 * size);
    vector <int> arr_1_PBPF( size);
    vector <int> arr_2_PBPF( size);
    complex <double> result_PBPF[2 * size - 1];
  //  printf("\n\nArray A: ");
    for (int i = 0; i < size; i++) {
        arr_1_PBPF[i] = (rand() );
       // printf("%d ", arr_1_PBPF[i]);
    }
    //printf("\nArray B: ");
    for (int i = 0; i < size; i++) {
        arr_2_PBPF[i] = (rand());
      //  printf("%d ", arr_2_PBPF[i]);
    }
    svertka_PBPF(arr_1_PBPF, arr_2_PBPF, result_PBPF);
  //  printf("\n\nReal part: ");
 //   for (int i = 0; i < 2 * size - 1; i++) {
  //      printf("%lf ", result_PBPF[i].real());
   // }
   // printf("\nImage part: ");
   // for (int i = 0; i < 2 * size - 1; i++) {
//    }
  //  printf("\n\n");
   printf("Half-quick Operations: %d\n\n", count_pb_1 + count_pb_2 + count_pb_3);
    //printf("Half-quick Operations: %d\n\n", count_pb_3);
    int size_bpf;

    //printf("\n\n");
  //  printf("Quick Operations: %d\n\n", count_b_1 + count_b_2);
    /*
char ch = getchar();
switch (ch) {
case '1': {
    system("cls");
    system("pause");
    exit(1);
}
case '2': {
    system("cls");
    system("pause");
    exit(1);
}
case '3': {
    system("cls");
    system("pause");
    exit(1);
}
case '4': {
    system("cls");
    system("pause");
    exit(1);
}
}*/

    return 0;
//razmer massiva 1024, vvod s klavi ubiraem, zapolniaem sluchainimi
}

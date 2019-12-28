#include "DFT.h"//ТРУДОЁМКОСТЬ ДОПИСАТЬ
//#include "pch.h"
#include <iostream>
#include <math.h>
#include "Complex.h"

void printComplexMasDisc(Complex *pComplex, const int nn);

int powerTwo(int N) {
    int number = 1;
    for (int i = 0; i < N; i++) {
        number *= 2;
    }
    return number;
}

void printRealMas(double *mas, int N) {
    for (int i = 0; i < N; i++) {
        if(fabs(mas[i])<0.00000001) mas[i]=0;
        std::cout << mas[i] << ", ";
    }
    std::cout << "\n";
}

int main() {
    system("chcp 65001");
    printf("\n");
    const int nn = 1024;
    double a[nn] = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < nn; ++i) {
        a[i] = 3;
    }
    //std::cout << "Ввод: ", printRealMas(a, nn);
    //Complex *dft = discreteFourierTransform(a, nn);
    //std::cout << "\nДискретное преобразование Фурье:\n";
    //printComplexMasDisc(dft, nn);
    //printDiscrTrud();
    //double *b = invDiscreteFourierTransform(dft, nn);
    //std::cout << "Обратное дискретное преобразовние: ";
    //printRealMas(b, nn);
    //std::cout << "\n";

    // 9 'элтов вещ часть 1010101' мнимая нули все три случая одинаковый результат потом 1024 вывод убираем смотрим трудоемкость

    const int n1 = 1024, n2 = 1024;
    double a1[n1] = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0};//только для свёртки дискретным и быстрым
    double b1[n2] = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 1024; ++i) {
        a1[i] = 3;
        b1[i] = 3;
    }

   // std::cout << "Свёртка дискретным преобразованием: \n";
    int cntdd = 0;
    int *cntD = &cntdd;
    double *c1 = conv(a1, n1, b1, n2, discreteFourierTransform, invDiscreteFourierTransform, cntD);
   // printRealMas(c1, n1 + n2);
    printf("Трудоёмкость свёртки дискретным преобразованием Фурье: %d\n\n", (n1*n2));

   // std::cout << "Свёртка полубыстрым преобразованием Фурье: \n";
    int cnth = 0;
    int *cntH = &cnth;
    c1 = conv(a1, n1, b1, n2, semiFastFourierTransform, invSemiFastFourierTransform, cntH);
    //printRealMas(c1, n1+n2);
    int ng = sqrt((double)nn) +5;
    int trHalf = ng*nn;
    printf("Трудоёмкость свёртки полубыстрым Фурье: %d\n\n", (trHalf));


    int pm = 0, mm = 0;
    int *pl = &pm;
    int *ml = &mm;
    // std::cout << "\nБыстрое преобразование фурье:\n";
    Complex *fft = fastFourierTransform(a, nn, pl, ml);
    // printComplexMas(fft, nn);
    printf("\nТрудоёмкость быстрого = %d\n", (*pl + *ml));

    //std::cout << "\n\nОбратное быстрое преобразование:\n";
    //double *c = invFFT(fft, nn);
    // printRealMas(c, nn);

    int cntf = 0;
    int *cntF = &cntf;
    //std::cout << "\nСвёртка быстрым преобразованием Фурье:\n";
    c1 = conv(a1, n1, b1, n2, fastFourierTransform, invFFT, cntF);
    //printRealMas(c1, nn * 2);
    printf("Трудоёмкость свёртки быстрым Фурье: %d\n", (cntf)+(*pl+*ml)*2);

    /*
    double *A = new double[100];
    for (int i = 0; i < 100; i++) {
        A[i] = i;
    }
    std::cout << "\nProb 100 semi fast\n";
    Complex *S = semiFastFourierTransform(A, 100);

    delete[] A;
    delete[] S;

    A = new double[400];
    for (int i = 0; i < 400; i++) {
        A[i] = i;
    }
    std::cout << "\nProb 400 semi fast\n";
    S = semiFastFourierTransform(A, 400);
    delete[] A;
    delete[] S;

    A = new double[powerTwo(12)];
    for (int i = 0; i < powerTwo(12); i++) {
        A[i] = i;
    }
    std::cout << "\nProb 12 fast\n";
    int *P = new int;
    int *M = new int;
    *P = 0;
    *M = 0;
    S = fastFourierTransform(A, powerTwo(12), P, M);
    int p = *P;
    int m = *M;
    std::cout << "\n" << p << " " << m << " " << p + m << "\n";

    delete[] A;
    delete[] S;

    A = new double[powerTwo(13)];
    for (int i = 0; i < powerTwo(13); i++) {
        A[i] = i;
    }
    std::cout << "\nProb 13 fast\n";
    *P = 0;
    *M = 0;
    S = fastFourierTransform(A, powerTwo(13), P, M);
    p = *P;
    m = *M;
    std::cout << "\n" << p << " " << m << " " << p + m << "\n";

    delete[] A;
    delete[] S;

    A = new double[powerTwo(14)];
    for (int i = 0; i < powerTwo(14); i++) {
        A[i] = i;
    }
    std::cout << "\nProb 14 fast\n";
    *P = 0;
    *M = 0;
    S = fastFourierTransform(A, powerTwo(14), P, M);
    p = *P;
    m = *M;
    std::cout << "\n" << p << " " << m << " " << p + m << "\n";
     */

    return 0;

}






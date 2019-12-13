#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <intrin.h>
#include <Windows.h>

unsigned long long rdtsc() {
    return __rdtsc();
}

unsigned long long factorial(unsigned int x) {
    unsigned int z = 1;

    for ( ; x > 1; --x) {
        z *= x;
    }

    return z;
}

double exp(float x) {
    double z = 1;

    for (int i = 1; i < 21; ++i) {
        z += pow(x, i) / factorial(i);
    }

    return z;
}

int main() {
    unsigned long long timeT1[5], T1 = 0, T21 = 0, t1, timeT2[5], T2 = 0, T22 = 0, t2, ticksps, tactsps, min1 = 1e+18, min2 = 1e+18;
    double x, answer;

    printf("e^x\nEnter x: ");
    scanf_s("%lf", &x);

    for (int i = 0; i < 5; ++i) {
        T1 = 0;
        T2 = 0;
        T21 = 0;
        T22 = 0;

//		for (int j = 0; j < 10; ++j) {
        t1 = clock();
        t2 = rdtsc();

        for (int k = 0; k < 1e+6; ++k) {
            answer = exp(x);
        }

        t1 = clock() - t1;
        t2 = rdtsc() - t2;
        T1 += t1;
        T2 += t2;
//		}

        timeT1[i] = T1;
        timeT2[i] = T2;

        if (min1 > T1) {
            min1 = T1;
        }

        if (min2 > T2) {
            min2 = T2;
        }
    }

    ticksps = clock();
    tactsps = rdtsc();
    Sleep(1000);
    ticksps = clock() - ticksps;
    tactsps = rdtsc() - tactsps;

    unsigned long long dif = 0;
    printf("answer: %lf\nclock:\n", answer);
    for (int i = 0; i < 5; ++i) {
        int j;
        for (j = 0; j < (double(timeT1[i]) / 10 / ticksps) * 500; ++j) {
            printf("|");
        }
        for ( ; j < 25; ++j) {
            printf(" ");
        }

        printf("%u starts | %15.5lf ticks %15.5lf seconds\n",
               unsigned int(1e+5), double(timeT1[i]) / 10,
               double(timeT1[i]) / 10 / ticksps);

        dif += timeT1[i] - min1;
    }
    printf("dif: %lf\n", double(dif) / 5 / ticksps);

    dif = 0;
    printf("TSC:\n");
    for (int i = 0; i < 5; ++i) {
        int j;
        for (j = 0; j < (double(timeT2[i]) / 10 / tactsps) * 500; ++j) {
            printf("|");
        }
        for (; j < 25; ++j) {
            printf(" ");
        }

        printf("%u starts | %15.5lf tacts %15.5lf seconds\n",
               unsigned int(1e+5), double(timeT2[i]) / 10,
               double(timeT2[i]) / 10 / tactsps);

        dif += timeT2[i] - min2;
    }
    printf("dif: %lf\n", double(dif) / 5 / tactsps);

    system("PAUSE");
}
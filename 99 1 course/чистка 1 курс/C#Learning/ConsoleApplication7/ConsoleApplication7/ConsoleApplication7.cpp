// ConsoleApplication7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <math.h>
#include<clocale>
#include <stdlib.h>
//#include <stdio.h>
float cosinus(float x) {

	float Cos = 1., eps; int i;
	for (i = 1, eps = 1; (eps>0.0001) || (eps<-0.0001); i++) {
		eps = 1; //printf("eps1 = %f\n", eps);
		for (int f = 1; f <= i * 2; f++) {
			eps *= x / f;
			//printf("eps2 = %f\n", eps);
		}
		if (i % 2) eps *= (-1.); //printf("eps3 = %f\n", eps); 
		Cos += eps; //printf("cosP = %f\n", Cos);
	}
	return Cos;
}
int main() {
	setlocale(LC_ALL, "Russian");
	float x, y; printf("Введите x");
	scanf_s("%f", &x);
	y = cos(x); printf("cos x = %f \n", y);
	y = cosinus(x); printf("cosinus x = %f \n", y);
	system("PAUSE");
}
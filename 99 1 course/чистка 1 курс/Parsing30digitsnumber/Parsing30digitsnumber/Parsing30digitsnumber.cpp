#include "stdafx.h"
#include <iostream>//  for cout(for C++ only)
using namespace std;// for cout(for C++ only)
#include<stdlib.h>// for srand
#include<conio.h>//for _getch()
#include <cstdio>
#include <stdio.h>
#include <cstdlib>


int main() {
	setlocale(LC_ALL, "Rus");
	char *chislo1;
	char *chislo2;
	int *ch1;
	int *ch2;
	int m, n, i;
	cout<<"Введите разрядность 1го числа";
	cin>>n;
	cout<<"Введите разрядность 2го числа";
	cin>>m;
	chislo1 = (char *)malloc(n * sizeof(int));
	chislo2 = (char *)malloc(m * sizeof(int));
	ch1 = (int *)malloc(n * sizeof(int));
	ch2 = (int *)malloc(m * sizeof(int));
	if (chislo1 == NULL)
	{
		printf(" Не удалось выделить память ");
		return 1;
	}
	if (chislo2 == NULL)
	{
		printf(" Не удалось выделить память ");
		return 1;
	}
	cout<<"Введите первое число";
	fgets(chislo1, n, stdin);
	if (strlen(chislo1)>n) {
		cout<<"Слишком длинное число. Введите число с разрядностью не больше 30:";
		fgets(chislo1, n, stdin);
	}
	for (i = 0; i<n; i++) ch1[i] = atoi(&chislo1[i]);
	for (i = 0; i<m; i++) ch2[i] = atoi(&chislo2[i]);
	//summm(m, n);
	//for(i=0;i<n;i++) cout<<chislo1[i]<<endl; 
	//for(i=0;i<m;i++) cout<<chislo2[i]; 
	printf("%d\n", ch1);
	free(chislo1);
	chislo1 = NULL;
	free(chislo2);
	chislo2 = NULL;
	free(ch1);
	ch1 = NULL;
	free(ch2);
	ch2 = NULL;
	_getch();
	return 0;

}

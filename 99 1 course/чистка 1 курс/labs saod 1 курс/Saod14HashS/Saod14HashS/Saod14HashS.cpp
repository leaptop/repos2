// Saod14HashS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<time.h>
#include<stdlib.h>
#include <conio.h>
#include <cstring>
#include <cstdio>
#include <locale.h> 
#pragma warning(disable : 4996)
using namespace std;
typedef struct st { char *x; struct st *next; } str;
char cha[10][15] = { "Alekseev", "Ivanov", "Sergeev", "Ivanova", "Pavlova", "Stepanova", "Hodges", "Smith", "Svenson", "Stevenson" };

void Fill(char** arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 7; j++)
			arr[i][j] = rand() % 25 + 97;

		arr[i][rand() % 4 + 4] = '\0';
	}
}
void Fill1(char** arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 7; j++)
			arr[i] = cha[i];
	}
}

void arrPrint(char**arr, int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
}
int Hash1(char**arr, int n)
{
	char *key = new char[8];
	str *HashTable[n];
	for (int i = 0; i<n; i++) {
		HashTable[i] = new str;
		HashTable[i] = NULL;
	}
	for (int i = 0; i<n; i++)
		HashInsert(&HashTable[HashAdress(arr[i], n)], arr[i]);
	for (int i = 0; i<n; i++)
	{
		printf("Hash=%d: ", i);
		Print(HashTable[i]);

	}
	printf("Enter key: ");
	scanf("%s", key);
	if (!HashSearch(HashTable[HashAdress(key, n)], key))
	{
		printf("Done! H=");
		printf("%d\n", HashAdress(key, n));
	}
	else printf("Not found");
}

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	int n, h, a, j, key, i;
	cout << "Введите колличество строк: ";
	cin >> n;
	char ** arr;
	arr = (char**)malloc(n * sizeof(char*));
	for (i = 0; i < n; i++)
	{
		arr[i] = new char[8];
	}
	Fill1(arr, n);
	arrPrint(arr, n);

	_getch();
	return 0;
}


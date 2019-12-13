#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h> 

extern void swap(int *xp, int *yp);
extern int bubbleSort(int arr[], int n);
extern int timer(int a[], int n, int(*f) (int[], int));
extern int CocktailSort(int a[], int n);
extern void iswap(int &n1, int &n2);
extern int HeapSort(int a[], int n);
extern int  quickSort(int arr[], int left, int right);
extern int shellSort(int a[], int size);
//void swap(int &x, int &y);
//void sort(int *x);
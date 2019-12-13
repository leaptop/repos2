#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>

int M, C;

int CountLog (int n)
{
    double a=log2 (n);
    int b=floor (a);
    return b;
}

void PrintMas(int n, int *A)
{
     printf ("\nPrintMas: ");
  for (int i = 0; i<n; i++)
  {
    printf("%d ",A[i]);
  }
}

void FillInc(int n, int *A)
{
  for (int i = 0; i<n; i++ )
    A[i]=i;
}

void FillDec(int n, int *A)
{
  for (int i = 0; i<n; i++ )
    A[i]=n-1-i;
}

void FillRand(int n, int *A)
{
    for (int i=0; i<n; i++)
        A[i] = rand()%101;
}

int QuickSort(int *A, int L, int R)
{
    int x=A[L], i=L, j=R, temp;
    while (i<=j)
    {
        while (A[i]<x)
        {
            i=i+1;
            C++;
        }
        while (A[j]>x)
        {
            j=j-1;
            C++;
        }
        if (i<=j)
        {
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            i=i+1;
            j=j-1;

            M+=3;
            C++;
        }
        C++;
    }

    if (L<j)
    {
        C++;
        QuickSort (A, L, j);
    }

    if (i<R)
    {
        C++;
        QuickSort (A, i, R);
    }
    return M+C;
}

main()
{
    srand (time(NULL));
    int n=100;
    int L=0, R=n-1;
    
    printf ("+----+-----------------------------------+\n");
    printf ("   N              QuickSort\n");
    printf ("+----+--------+--------+--------+--------+\n");
    printf ("       Theory    inc      dec     rand    \n");
    printf ("+----+--------+--------+--------+--------+  ");
    for (n=100; n<=500; n+=100)
    {
        int A[n];
        printf ("\n %4d ", n);
        
        printf ("%8d ",n*CountLog(n));
        
        L=0, R=n-1;
        M=0; C=0;
        FillInc (n, A);
        printf ("%8d ", QuickSort (A, L, R));
        
        L=0, R=n-1;
        M=0; C=0;
        FillDec(n, A);
        printf ("%8d ", QuickSort (A, L, R));
        
        L=0, R=n-1;
        M=0; C=0;
        FillRand(n, A);
        printf ("%8d ", QuickSort (A, L, R));
    }
    getch();
}

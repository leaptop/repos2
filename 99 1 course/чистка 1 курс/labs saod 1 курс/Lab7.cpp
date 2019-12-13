#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int FillRand (int n, int *A)
{
    for (int i=0;i<n;i++)
    A[i]=rand()%101;
}

int InsertSort (int n, int *A)
{
    int i, j, t;
    for (i=1; i<n; i++)
    {
        t=A[i];
        j=i-1;
        while (j>=0 && t < A[j])
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=t;
    }
}

int BSearch1 (int n, int *A, int x)
{
    int L=0, R=n-1, m, C=0;
    while (L<=R)
    {
        m=(L+R)/2;
        C++;
        if (A[m]==x)
            return C;
        C++;
        if (A[m]<x)
            L=m+1;
        else R=m-1;
    }
    printf ("Nope!");
    return C;
}

int BSearch2 (int n, int *A, int x)
{
    int L=0, R=n-1, m, C=0;
    while (L<R)
    {
        m=(L+R)/2;
        C++;
        if (A[m]<x)
            L=m+1;
        else R=m;
    }
    if (A[R]!=x) printf ("Nope!");
    return C;
}

int main()
{
    int n, x;
    printf ("Enter your number:");
    scanf ("%d",&x);
    printf ("-------+------+-------\n");
    printf ("   n   + Iver + IIver \n");
    printf ("-------+------+-------");
    for (n=100; n<=1000; n+=100)
    {
        printf ("\n");
        int A[n];
        FillRand (n,A);
        InsertSort (n,A);
        printf (" %4d ",n);
        printf (" %4d ",BSearch1(n,A,x));
        printf (" %4d ",BSearch2(n,A,x));
    }
    printf ("\n-------+------+-------");
    getch();
}

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void FillRand (int n, int *A)
{
    for (int i=0; i<n; i++)
        A[i] = rand()%101;
}

void FillInc (int n, int *A)
{
  for (int i = 0; i<n; i++)
    A[i]=i;
}

void FillDec (int n, int *A)
{
    for (int i = 0; i<n; i++)
        A[i]=n-1-i;
}

int PyramidBuild (int L, int R, int *A)
{
    int x=A[L], i=L;
    int j, M=1, C=0;
    while (1)
    {
        j=2*i;
        if (j>R) break;
        C++;
        if ((j<R) && (A[j+1]<A[j])) j=j+1;
        C++;
        if (x<=A[j]) break;
        M++;
        A[i]=A[j];
        i=j;
    }
    M++;
    A[i]=x;
    return M+C;
}

int HeapSort (int n, int *A)
{
    int temp,T1=0, T2=0, M=0, C=0;
    int L=n/2;
    int R=n-1;
    while (L>=0)
    {
        T1+=PyramidBuild (L, n-1, A);
        L=L-1;
    }
    R=n-1;
    while (R>=1)
    {
        temp=A[0];
        A[0]=A[R];
        A[R]=temp;
        M+=3;
        R=R-1;
        T2+=PyramidBuild (0, R, A);
    }
    return M+C+T1+T2;
}

main()
{
    srand(time(NULL));
    int i, n=100;
    printf ("+----+--------------------------+\n");
    printf ("   N           HeapSort\n");
    printf ("+----+--------+--------+--------+\n");
    printf ("         inc      dec     rand \n");
    printf ("+----+--------+--------+--------+");
    for (n=100; n<=1000; n+=100)
    {
        int A[n];
        printf ("\n %4d ",n);
        FillInc (n, A);
        printf ("%8d ",HeapSort(n, A));
        FillDec (n, A);
        printf ("%8d ",HeapSort (n, A));
        FillRand(n, A);
        printf ("%8d",HeapSort (n, A));
    }
    getch();
}

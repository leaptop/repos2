#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int FillRand (int n, int *A)
{   srand(time(NULL));
     for (int i=0;i<n;i++)
     A[i]=rand()%101;
}

int ShellSort (int n, int *A)
{
    int k, t, j, C=0, M=0, i, p, h;

	p=log2(n)-1;
	h=1;
	for (i=1;i<=p;i++)
		h=(h<<1)|1;
	k=h;

	for (k;k>0;k=(k-1)/2)
        {
            for (i=k+1; i<n+1; i++)
                {
                    t=A[i];
                    M++;
                    j=i-k;
                    C++;
                    while (j>0 && A[j]>t)
                        {
                            C++;
                            A[j+k]=A[j];
                            j=j-k;
                            M++;
                        }
                    A[j+k]=t;
                    M++;
                }
        }
return C+M;
}

int InsertSort (int n, int *A)
{
    int i, j, t, C=0,M=0;
    for (i=1; i<n; i++)
    {
        t=A[i];
        j=i-1;
        C++;
        M++;
        while (j>=0 && t < A[j])
        {
            C++;
            A[j+1]=A[j];
            M++;
            j--;
        }
        M++;
        A[j+1]=t;
    }
return M+C;
}

main ()
{
    srand(time(NULL));
     int i, n=100, K;
     printf ("  N   Knuth   Insert   Shell  ");
     for (n=100; n<=500; n+=100)
     {   int A[n];
         printf ("\n");
         printf ("%3d ",n);
         printf ("%7d",K=log2(n)-1);
         FillRand (n, A);
         printf ("%8d ", InsertSort (n,A));
         FillRand (n,A);
         printf ("%8d ", ShellSort (n,A));
     }
     getch();
}

#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int FillRand (int n, int *A)
{
     for (int i=0;i<n;i++)
     A[i]=rand()%101;
}

int SelectSort(int n, int *A)
{
int i,k,t,M=0,C=0;
for (i=1; i<n; i++)
    {
        k=i;
        for (int j=i+1;j<=n;j++)
            {
                C++;
                if (A[j]<A[k]) k=j;
            }
 t=A[i];
 A[i]=A[k];
 A[k]=t;
 M+=3;
    }
return M+C;
}

int BubbleSort(int n, int *A)
{
int i, j, t, M=0, C=0;
for (i=0; i<n;i++)
    for (j=n-1; j>i; j--)
    {
      if (A[j]<A[j-1])
      {
        t=A[j];
        A[j]=A[j-1];
        A[j-1]=t;
        M+=3;
      }
      C++;
      }
return M+C;
}

int ShakerSort(int n, int *A)
{
int j, t, M=0, C=0, L=1, R=n, K=n;
do{
    for (j=R; j>=L+1; j--){
        if (A[j]<A[j-1])
        {
           t=A[j]; 
           A[j]=A[j-1]; 
           A[j-1]=t; 
           M+=3; 
           K=j;
        }
    C++;
    }
    L=K;
    for (j=L; j<=R-1; j++) {
        if (A[j]>A[j+1]) 
        {
           t=A[j]; 
           A[j]=A[j+1]; 
           A[j+1]=t; 
           M+=3; 
           K=j;
        }
    C++;}
    R=K;
}
while (L<R);

return M+C;
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

int main()
{
     int i,M,C,n=100;
     printf ("  N  Select  Bubble  Shaker  Insert  ");
     for (n=100;n<=500;n+=100)
     {
         int A[n];
         printf ("\n");
         printf ("%3d",n);
         FillRand (n,A);
         printf ("%8d",SelectSort(n,A));
         FillRand (n,A);
         printf ("%8d",BubbleSort(n,A));
         FillRand (n,A);
         printf ("%8d",ShakerSort(n,A));
         FillRand (n,A);
         printf ("%8d",InsertSort(n,A));
     }

getch();
}

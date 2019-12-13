#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int FillRand (int n, int *A)
{
 for (int i=0;i<n;i++) 
     A[i]=rand()%101;   
}

int FillInc(int n, int *A)
{
  for (int i = 0; i<n; i++ )
    A[i]=i;
}

int FillDec(int n, int *A)
{
  for (int i = 0; i<n; i++ )
    A[i]=n-1-i;
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
        {t=A[j]; A[j]=A[j-1]; A[j-1]=t; M+=3; K=j;}
    C++;} 
    L=K; 
    for (j=L; j<=R-1; j++) {
        if (A[j]>A[j+1]) {t=A[j]; A[j]=A[j+1]; A[j+1]=t; M+=3; K=j;}
    C++;} 
    R=K;
}
while (L<R);

return M+C;
}

int main()
{
srand(time(NULL));
 int i,M,C,n=100;
printf (" N        M+C Bubble                 M+C Shaker");
printf ("\n      Decr.    Rand.  Incr.    Decr.    Rand.   Incr.");

for (n=100;n<=500;n+=100) //bubble
{
 int A[n];
printf ("\n");
printf ("%d",n);
 FillDec (n,A);
 printf ("%8d",BubbleSort(n,A));
 FillDec (n,A);
 printf ("%9d",ShakerSort(n,A));
 FillRand (n,A);
 printf ("%8d",BubbleSort(n,A));
 FillRand (n,A);
 printf ("%8d",ShakerSort(n,A));
 FillInc (n,A);
 printf ("%8d",BubbleSort(n,A));
 FillInc (n,A);
 printf ("%8d",ShakerSort(n,A));
}

getch();
}

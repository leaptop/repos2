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

int main()
{
srand(time(NULL));
 int i,M,C,n;

printf (" N\tM+C Theory\t\tM+C Fact");
printf ("\n\t          \tDecr.\tRand.\tIncr.");
 
for (n=100;n<=500;n+=100)
{
 int A[n];
 C=((n*n)-n)/2; M=(3*C)/2;
 FillDec (n,A);
 printf ("\n%d\t%d\t\t%d",n,C+M,BubbleSort(n,A));
 FillRand (n,A);
 printf ("\t%d",BubbleSort(n,A));
 FillInc (n,A);
 printf ("\t%d",BubbleSort(n,A));
}
getch();
}

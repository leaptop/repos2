#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

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

void CheckSum(int n, int *A)
{
  int sum = 0;
      for (int i=0; i<n;i++)
    {
        sum+=A[i];
    }
    printf("\nCheckSum: %d",sum);
}

void RunNumber(int n, int *A)
{
  int s=1;
  for (int i=1;i<n;i++)
  {
    if (A[i]<A[i-1]) s=s+1;
  }
  printf("\nRunNumber: %d",s);
}

void PrintMas(int n, int *A)
{
     printf ("\nPrintMas: ");
  for (int i = 0; i<n; i++)
  {
    printf("%d ",A[i]);
  }
}


int main()
{
int n;
  printf ("Enter n: ");
  scanf ("%d",&n);
  printf ("\n");
  int A[n];

  FillInc(n,A);
  FillDec (n,A);
  FillRand (n,A);
  CheckSum (n,A);
  RunNumber(n,A);
  PrintMas(n,A);
getch();
}

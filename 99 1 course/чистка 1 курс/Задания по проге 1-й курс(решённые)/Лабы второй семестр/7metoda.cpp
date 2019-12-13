#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <clocale>
 int Sum ( int A[], int N ) 
 { 
   int i, sum;
   sum = 0;
   for ( i = 0; i < N; i ++ )
     sum += A[i];
   return sum;
 }

main(){ setlocale( LC_ALL, "Russian" );
  const int n=20,m=30;
   int i, s, A[n], B[m];
   printf(" Массив A \n");
   for (i=0; i<n; i++)
   {  A[i]=rand()%10;
      printf("%5d",A[i]);
   }
   printf("\n\n Массив B \n");   
   for (i=0; i<m; i++)
   {  B[i]=rand()%20;
      printf("%5d",B[i]);
   }
   s = Sum(A,n); 
   printf("\n\nСумма массива A %d,  массива B %d", s, Sum(B,m) ); 
   getch();
   return 0;
}

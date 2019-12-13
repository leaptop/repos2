#include <stdio.h>
#include <conio.h>
void quart(int n, float * x)  
{ int i;
  for (i=0;i<n;i++)
     x[i]=x[i]*x[i];
}
main()
{  float z[]={1,2,3,4,5}; 
   int j; int n=sizeof(z)/sizeof(z[0]);
   for (j=0; j<n; j++)
   printf(" %6.2f",z[j]);
   quart(n,z);
   putchar('\n');
   for (j=0; j<n; j++)
       printf("\n %6.2f",z[j]);
   getch();
}

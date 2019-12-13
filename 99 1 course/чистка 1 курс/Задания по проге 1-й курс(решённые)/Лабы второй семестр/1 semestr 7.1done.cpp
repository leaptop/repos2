#include <stdio.h>
#include <stdlib.h>

#include  <math.h>
float f(int a, int b, int c, int x){return a*x*x*sin(x)+b*x+c;}

#include <clocale>
main(){ setlocale( LC_ALL, "Russian" );


 system("CLS"); 
 int N = 59;
 float a = 2.14, b = -4.21, c = 3.25, xn =-4.5, xk = -33.5, h =0.5, A[N]//={3452,76,-55,0,33,76,-1,-10,1}
 , x, tmp, o;
 for(int i = 0; i<N; i++) {
 A[i]=f(a, b, c, xn - i*h);printf("A[%d] = %f\n",i,A[i]);}
 

 for(int j = 0; j<N-1;j++){
 	for(int i = j; i<N-1; i++) 
	 if(A[j]<A[i]){tmp = A[i]; A[i] = A[j]; A[j] = tmp;
	 }
 }
 printf("\n--------\n");
 for(int i = 0; i<N; i++)printf("%f\n",A[i]);

 system("PAUSE");
 return 0;
}

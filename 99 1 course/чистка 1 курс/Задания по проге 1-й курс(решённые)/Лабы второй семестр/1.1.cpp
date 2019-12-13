#include <math.h>
#include <stdio.h>
#include <clocale>
float cosinus(float x) {
	float Cos=1., eps; int i;
	for (i=1,eps=1;(eps>0.0001)||(eps<-0.0001); i++){ eps=1; //printf("eps1 = %f\n", eps);
		for (int f=1;f<=i*2;f++) {eps*=x/f;
			 //printf("eps2 = %f\n", eps);
		}
		if (i%2) eps*=(-1.); //printf("eps3 = %f\n", eps); 
		Cos+=eps;//printf("cosP = %f\n", Cos);
	}
	return Cos;
}
int main(){setlocale( LC_ALL, "Russian" );
	float x,y; printf("ведите х");
	scanf("%f",&x);
	y=cos(x); printf("cos x= %f \n",y);
	y=cosinus(x); printf("cosinus x= %f \n",y);
}

#include <stdio.h>
#include <clocale>
float multi(float x, int n){
	int i; float y;
	if (n>0)
	{for (y=1,i=1;i<=n;i++) y*=x;}
	else if (n) for (n=-n,y=1.,i=1; i<=n;i++) y/=x; else y=1;
	return y; 
}
int main(){setlocale( LC_ALL, "Russian" );
	float y,x; int n; printf("введите x и n:");
	scanf("%f%d",&x,&n);
	y=multi(x,n); printf("%8.4f",y);
}

#include <stdio.h>
#include <math.h>
int Function(int *a,int *b, int *c){ int f,g,h;
	f=*a; g=*b; h=*c;
	if ((f+g>h)and(f+h>g)and(g+h>f)) {
			int P=f+g+h;
			printf("Периметр равен %d \n",P);
			float p=P/2.;
			float S=sqrt(p*(p-g)*(p-f)*(p-h)); printf("Площадь равна %f",S);
			return 1;	
	}
	else return 0;
}
#include <clocale>
main(){ setlocale( LC_ALL, "Russian" );

	int a,b,c;
	printf("Введите размеры сторон\n");
	scanf("%d%d%d",&a,&b,&c);
	//printf("\n");
	Function(&a,&b,&c);
}

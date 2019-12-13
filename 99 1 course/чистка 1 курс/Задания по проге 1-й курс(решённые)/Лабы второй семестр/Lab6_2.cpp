#include <stdio.h>
#include <clocale>
int Func(int m, int n, float &pd, float &pm){
	if (m&&n&&(n>m)){
		int j; float c=1.;
		for(j=0; j<n-m; c*=float(n-j)/(j+1), j++ );
		int i; float p=0.45, q=0.55; float r=0.45,t=0.55;
		for (i=0; i<m; i++) p*=0.45,t*=0.55;
		for (i=0; i<n-m; i++) q*=0.55,r*=0.45;
		pd=c*p*q; pm=c*r*t;
	}
	else return 0;
}

main(){ setlocale( LC_ALL, "Russian" );

	int m,n; float pm,pd;
	printf("m,n: \n");
	scanf("%d%d",&m,&n);
	Func(m,n,pd,pm);
	printf("Pd %f ",pd); printf("Pm %f ",pm); 
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <clocale>
main(){ setlocale( LC_ALL, "Russian" );
	int i,j,n;
	printf("<100 n:"); scanf("%d",&n); printf("\n");
	int **a;
	a=(int**)malloc(n*sizeof(int *));
	for (i=0; i<n; i++) a[i]=(int *)malloc(n*sizeof(int));
	for (i=0; i<n; i++) a[0][i]=i, printf("%4d",a[0][i]); printf("\n");
	int k=2;
	printf("sizeof(int *) = %d", sizeof(int *));
	for (i=1; i<n; i++){
		a[i][0]=i,printf("%4d",a[i][0]);
		for (j=1; j<k; j++) a[i][j]=a[i][0]*a[0][j], printf("%4d",a[i][j]); 
		printf("\n"); k++;
	}
}

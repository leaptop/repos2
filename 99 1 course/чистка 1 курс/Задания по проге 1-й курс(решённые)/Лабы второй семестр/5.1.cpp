#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <clocale>
main(){ setlocale( LC_ALL, "Russian" );
	int *a, **b; int i,j,m,k;
	printf("M,k:");
	scanf("%d%d",&m,&k);
	a=(int *)malloc(m*sizeof(int));
	b=(int **)malloc((m-1)*sizeof(int *));
	int n=(m-m%k)/k;
	if (m%k) n++;
	for (i=0; i<m-1;i++) b[i]=(int *)malloc((k)*sizeof(int));
	srand(time(NULL));printf("\nИсходный массив: \n");
	for (i=0;i<m;i++) a[i]=rand()%12-1, printf("%3d",a[i]);
	printf("\nМатрица: \n");
	for (i=0;i<n;i++){
		for (j=0;j<k;j++) { if (k*i+j<m) b[i][j]=a[i*k+j]; else b[i][j]=0; printf("%3d",b[i][j]);
	}	printf("\n");
}}

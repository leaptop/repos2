#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <clocale>
const int n=5;
int random(int n){ return rand()%n;
}
main()
{ 
setlocale( LC_ALL, "Russian" );
	int i,j,m; int **a, **b;
	printf("¬ведите число строк\n");
	scanf("%d",&m); printf("\n");
		a=(int **)malloc(m*sizeof(int *));
	b=(int **)malloc((m-1)*sizeof(int *));
	for (i=0; i<m;i++) a[i]=(int *)malloc(n*sizeof(int));
	for (i=0; i<m-1;i++) b[i]=(int *)malloc((n-1)*sizeof(int));
	srand(time(NULL)); int min,max=-1,u,y;
	for (i=0;i<m;i++) {
		for (j=0;j<n;j++) { a[i][j]=random(201)-100; min=a[i][j]; if (min>max) {max=min;u=i,y=j;} printf("%4d",a[i][j]);}
		printf("\n");
	}int o =0,p=0; printf("max = %d [%d] [%d]\n",max,u,y);
	for (i=0; i<m;i++){ p=0;
	if (i!=u) {
	for (j=0;j<n;j++){
		if ((j!=y)) b[o][p]=a[i][j], printf("%4d",b[o][p]),p++;
	}
	o++; printf("\n");}
}
for (i=0; i<m;i++) free(a[i]); free(a);
for (i=0; i<m-1;i++) free(b[i]); free(b);}




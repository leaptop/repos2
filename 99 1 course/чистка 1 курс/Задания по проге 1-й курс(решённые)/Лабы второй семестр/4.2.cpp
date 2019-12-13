#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <clocale>
main(){ 
    setlocale( LC_ALL, "Russian" );
	int **a,**b; int i,j,m,n;
	printf("¬ведите размер матрицы m, n \n");
	scanf("%d%d",&m,&n);
	a=(int **)malloc(m*sizeof(int *));
	b=(int **)malloc((m+1)*sizeof(int *));
	
	for (i=0; i<n;i++) a[i]=(int *)malloc(m*sizeof(int));
	for (i=0; i<n+1;i++) b[i]=(int *)malloc((m+1)*sizeof(int));
	srand(time(NULL));
	for (i=0; i<m;i++) {for (j=0; j<n; j++) a[i][j]=b[i][j]=rand()%10, printf("%4d",a[i][j]); printf("\n");}
	int k=0;
	printf("---------------\n");
	for (i=0; i<m;i++){
		for (j=0;j<n;j++) b[i][j]=a[i][j], k+=a[i][j],printf("%4d",b[i][j]);
		b[i][n]=k; printf("%4d \n",b[i][n]); k=0;
	}
	for (j=0; j<n;j++) {
		for (i=0;i<m;i++) b[i][j]=a[i][j], k+=a[i][j];
		b[m][j]=k; printf("%4d",b[m][j]); k=0;
	}
	int u=0;
	for (i=0; i<m;i++) u+=b[i][n];
	for (j=0; j<n;j++) u+=b[m][j];
	b[m][n]=u;
	printf("%4d",b[m][n]);
	for (i=0; i<m;i++) free(a[i]); free(a);
for (i=0; i<m-1;i++) free(b[i]); free(b);
}

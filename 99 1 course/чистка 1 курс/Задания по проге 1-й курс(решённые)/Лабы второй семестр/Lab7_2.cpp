#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int Func(int i, int m, int **a ){
	int k,S=0; for(k=0; k<m; k++) S+=a[i][k];
	printf("String %d %d \n",i,S); 
}
main(){
	srand(time(NULL)); 
	char i,n,m,j; int **a;
	printf("Strings:"); scanf("%d",&n); printf("\n");
	a=new int*[n];
	for (i=0; i<n; i++){
		m=rand()%11-1;
		a[i]=new int[m], a[i][0]=m; printf("%d ",a[i][0]);
		for (j=1; j<m; j++) a[i][j]=rand()%11, printf("%d ",a[i][j]);
		printf("\n");
	}
	for (i=0; i<n; i++) Func(i,a[i][0], a);
	for (i=0; i<n; i++) free(a[i]);
	free(a);
}

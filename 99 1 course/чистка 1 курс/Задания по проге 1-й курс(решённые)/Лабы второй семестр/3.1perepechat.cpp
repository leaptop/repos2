#include<stdlib.h>
#include<stdio.h>
int random(int N){return rand()%N;
}
int main(){
	int * p; int i, n;
	scanf("%d", &n); printf("\n");
	p = (int *)malloc(n*sizeof(int));
	int m =0, k =0;
	for(i = 0; i<n; i++){p[i]=random(101)-50; if(p[i]>=0) m++; else k++;}
	int *c;
	c = (int*)malloc(m*sizeof(int));
	int*d;
	d=(int*)malloc(k*sizeof(int)); k =m =0;
	for(i=0;i<n;i++){if(p[i]>=0) c[m]=p[i], m++; else d[k]=p[i], k++; printf("%d ", p[i]);
	}printf("\n");
	for(int f = 0; f<m; f++) printf("%d ", c[f]); printf("\n");
	for(int f = 0; f<k; f++)printf("%d ", d[f]);
	free(p); free(c); free(d);
	}


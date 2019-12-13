#include<stdlib.h>
#include<stdio.h>
#include<time.h>
 int main(){
	float *a; int i, n; float **b;
	scanf("%d", &n); printf("\n");
	a = new float[n]; b = new  float*[n];
	srand(time(NULL));
	for (i = 0; i<n; i++){
		a[i]=rand()*(100.0)/RAND_MAX-100;
		b[i] = a+i; printf("%f ", a[i]);
	}int k = 0;
	while(k!=n){
		for(i=n-1; i>k; i--)
		if(*(b[i])<*(b[i]-1)){float t; t = *(b[i]), *(b[i])=*(b[i]-1), *(b[i]-1)=t;
		}k ++;
	}printf("\n");
	for(i = 0;i<n; i++) printf("%f ", a[i]);
	free(a); free(b);
}

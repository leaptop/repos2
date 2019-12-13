#include <stdio.h>
#include <stdlib.h>
int main(){
	int *S; int i,n,j;
	scanf("%d",&n); printf("\n");
	S=new int[n];
	for ( i=1; i<n;i++) S[i]=1;
	for (i=1; i<n;i++) {
		if (S[i]) {printf(" %d",i+1); for (j=i+1;j<n;j++) if (!((j+1)%(i+1))) S[j]=0;
	}
	
}
printf("\n!(0) = %d", !(0));
printf("\n!(-199) = %d", !(-199));
printf("\n!(1) = %d", !(1));
printf("\n!(8.7) = %f", !(8.7));
printf("\n!(3/5) = %f", !(3/5));
printf("\n!(0.00000001) = %d", !(0.00000001));
printf("\n!(0.00000001) = %f", !(0.00000001));
}

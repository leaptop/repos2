#include <stdio.h>
#include<stdlib.h>
int main(){
	int *S; int i, n, j;
	scanf("%d", &n); printf("\n");
	S = new int[n];
	for(i=1; i<n;i++)S[i]=1;
	for(i =1;i<n;i++){if(S[i]){printf(" %d", i+1); for (j = i+1; j<n;j++) if(!((j+1)%(i+1))) S[j]=0;
	}
	}
}

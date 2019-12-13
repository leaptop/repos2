#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char n,d,t=1;
int random(int b){return rand()%b;
}
int Rekurs(int *A, int n){
	if (t) if ((n)&&(A[n-1]>0)) {printf("%d ",A[n-1]); return Rekurs(A,n-1);}
								else {
									if (!n) { t=0; n=d; printf("\n"); return Rekurs(A,n);}
									return Rekurs(A,n-1);
									}
		else if ((n)&&(A[n-1]<0)) 	{printf("%d ",A[n-1]); return Rekurs(A,n-1);}	
						else {if (!n) return t++; return Rekurs(A,n-1); }									
	}
int main(){
	srand(time(NULL));
	int A[256];
	char i;
	scanf("%d",&n);
	for (i=0; i<n;i++) {
		A[i]=random(21)-10;if (A[i]) printf("%d ",A[i]); else A[i]+=1, printf("%d ",A[i]);
	}
	printf("\n");
	d=n;
	Rekurs(A,d);
}

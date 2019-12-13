#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
int Func(int A[],int n){
	int b=n-1; int i,C;
	while (b>0){
		for (i=0; i<b; i++) if (A[i]<A[i+1])  C=A[i], A[i]=A[i+1], A[i+1]=C;
		b--;
	}
}
int Number(int a, int b){
	if ((a+b)%2) return (a+b+1)/2;
	else return (a+b)/2;
}
int Binar(int A[], int d){
	int i,t=0; int a=0, b=999,c; c=500;
	while (1){
		if (A[c]>d) { a=c; c=Number(a,b); t=t+3;} t++;
		if (A[c]<d) { b=c; c=Number(a,b); t=t+3;} t++;
		if (A[c]==d) { return printf("Yes %d",++t);}
		else  if (b-a==1)return printf("Net %d",++t);
	}
}
int Pere(int A[], int d){ int i, t=0;
	for (i=0; i<1000; i++) { t++; if (A[i]==d) return printf("Yes %d \n\n",t);
	}
	printf("Net 1000 \n\n");
}
main(){
	int A[1000];
	int i; srand(time(NULL));
	for (i=0; i<1000; i++) A[i]=rand()%10001, printf("%d ",A[i]); printf("\n\n\n\n");
	Func(A,100);
	for(i=0; i<100; i++) printf("%d ",A[i]); printf("\n\n"); int d; 
	 Func(A,1000);
	 for(i=0; i<1000; i++) printf("%d ",A[i]); printf("\n\n");
	 scanf("%d",&d); printf("\n\n");
	 Pere(A,d);
	Binar(A,d); 
}

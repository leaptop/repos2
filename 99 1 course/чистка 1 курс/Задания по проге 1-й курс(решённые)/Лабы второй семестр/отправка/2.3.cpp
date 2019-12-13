#include <stdio.h>
long int t, n, j = 1;
int Ds (int n){
	if(n){
		if(n%2) return printf("%d", 1, Ds((n-1)/2));
		else return printf("%d", 0, Ds(n/2));
	}
}
int main(){
scanf("%d", &n);
Ds(n);
}

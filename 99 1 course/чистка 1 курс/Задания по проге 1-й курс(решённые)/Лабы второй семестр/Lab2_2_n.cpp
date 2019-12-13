#include <stdio.h>

int Rekurs(){
	char i; 
	scanf("%d",&i);
	if (i){if (i>0) return printf("%d ",i,Rekurs());
	       else return Rekurs();}
}
int main(){
	Rekurs();
}



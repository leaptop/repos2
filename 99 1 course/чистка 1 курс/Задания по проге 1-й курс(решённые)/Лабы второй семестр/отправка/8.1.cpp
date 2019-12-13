#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
struct School { 
 int n;
 int Fin;
 int Uni;
 float Pro;
} sch;
main(){
	int m=100;
	int index[100];
	int i,j,p;
	for (i=0; i<m; i++) index[i]=i;
	struct School mass[100];
	for (i=0; i<m; i++){
		mass[i].n=i;
		p=mass[i].Fin=rand()%101+60;
		j=mass[i].Uni=rand()%61+41;
		mass[i].Pro=j*(1./p);
	} int k=99; int g;
	while (k>0){
		for (i=0; i<k; i++) 
			if (mass[index[i]].Uni<mass[index[i+1]].Uni) g=index[i], index[i]=index[i+1], index[i+1]=g;
			k--;
	}
	for (i=0; i<100; i++) printf(" %d %d %d %f \n" ,mass[index[i]].n, mass[index[i]].Fin, mass[index[i]].Uni, mass[index[i]].Pro);
}


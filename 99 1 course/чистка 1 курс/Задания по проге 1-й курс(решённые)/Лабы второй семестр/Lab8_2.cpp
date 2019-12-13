#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <clocale>
#include <windows.h>
using namespace std;
struct Obs{ int n; float S; char Fakult[5]; int Man;
} Home;
struct Fac { char F[5]; int Rooms; int Students; float Sr; float su;} 
hh;
main(){
	struct Obs Obzchaga[100];
	struct Fac Result[10];
	int i=0,j,m,k; char Dictionary[10][5]; char bufer[40];
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); 
	printf("Вводите названия факультетов (4 символа), закончить отдельной точкой \n");
	gets(bufer);
	printf("Номер  Площадь  Факультет Жители /n");
	for (i=0, j=0, k=0; bufer[i]; i++) {
		if (bufer[i]==' ' && bufer[i+1]!=' ') {
			Dictionary[k][j]='\0';
			k++;
			j=0;
		}
		else Dictionary[k][j++]=bufer[i];
	}
	Dictionary[k++][j]='\0';
	for (i=0; i<k; i++){
		Result[i].Rooms=0;
		Result[i].Sr=0;
		Result[i].Students=0;
		Result[i].su=0;
	}
	for (i=0; i<100;i++){
		m=rand()%k;
		strcpy(Obzchaga[i].Fakult, Dictionary[m]); Obzchaga[i].S=rand()%10+3;
		Obzchaga[i].n=rand()%102+1; Obzchaga[i].Man=rand()%5+1;
		printf(" %4d %4.0f %s %4d \n",Obzchaga[i].n,Obzchaga[i].S,Obzchaga[i].Fakult,Obzchaga[i].Man);
		strcpy(Result[m].F, Dictionary[m]); Result[m].Rooms+=Obzchaga[i].n; Result[m].Students+=Obzchaga[i].Man;
		Result[m].su+=Obzchaga[i].S;
	}
	puts("Факультет Комнаты Жители Ср. Площадь");
	for (i=0; i<k; i++){
		Result[i].Sr=Result[i].Students/Result[i].su;
		printf(" %s %4d %4d %6f \n", Result[i].F, Result[i].Rooms,Result[i].Students, Result[i].Sr);
	}
}

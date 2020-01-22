#include <windows.h>
#include <process.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <iostream>

char sh[6];

bool readyFlags[2];
int turn;

void EnterCriticalRegion(int threadId)//дано Малковым - самопальная функция для распараллеливания
{
	readyFlags[threadId] = true; // Флаг текущего потока
	turn=1 - threadId; // Флаг очереди исполнения
	while(turn == 1-threadId && readyFlags [1-threadId]);
}

void LeaveCriticalRegion(int threadId)
{
	readyFlags[threadId] = false; // Сброс флага текущего потока
}


void Thread( void* pParams ){
	int counter = 0;
	while ( 1 ){
	EnterCriticalRegion(0);
	if(counter%2){
		sh[0]='H';sh[1]='e';sh[2]='l';sh[3]='l';sh[4]='o';sh[5]='\0';
	}else{
		sh[0]='B';sh[1]='y';sh[2]='e';sh[3]='_';sh[4]='u';sh[5]='\0';
	}
	LeaveCriticalRegion(0);
	counter++;
	}
}

int main( void ){
	_beginthread( Thread, 0, NULL );
	FILE *f;
	f=fopen("b.txt","w");
	int i=0;
	int start_ticks;
	int end_ticks;
	int diff_ticks;
	start_ticks=clock();
	while( i<1000000 ){
		EnterCriticalRegion(1);
		fprintf(f,"%s\n",sh);
	//	getchar();
		LeaveCriticalRegion(1);
		i++;
	}
	end_ticks=clock();
	diff_ticks=end_ticks-start_ticks;
	printf("%.4f/\n",(double)diff_ticks/CLOCKS_PER_SEC);
	getchar();
	return 0;
}
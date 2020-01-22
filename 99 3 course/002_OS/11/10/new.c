//#include <windows.h>
//#include <process.h>
#include <pthread.h>
#include <stdio.h>

//HANDLE hMutex;
pthread_mutex_t Mutex;//=PTHREAD_MUTEX_INITIALIZER;
char sh[6];
void* Thread( void* pParams );

int main( void ) {
	 pthread_t thread_id;
	 //hMutex=CreateMutex(NULL,FALSE,NULL);
	 pthread_mutex_init(&Mutex, NULL);

	 //_beginthread( Thread, 0, NULL );
	 pthread_create(&thread_id, NULL, &Thread, NULL);
	 
	while( 1 ){
		//WaitForSingleObject(hMutex, INFINITE);//захват
		pthread_mutex_lock(&Mutex);
		printf("%s\n",sh);
		//ReleaseMutex(hMutex);//освобождение
		pthread_mutex_unlock(&Mutex);
	 }
	 return 0;
 }
 
void* Thread( void* pParams ){
	 int counter = 0;
	 while ( 1 ){
		 //WaitForSingleObject(hMutex, INFINITE);//захват мьютекса
		 pthread_mutex_lock(&Mutex);
		 if(counter%2){
		 sh[0]='H';sh[1]='e';sh[2]='l';sh[3]='l';sh[4]='o';sh[5]='\0';
	 }
	 else{
		sh[0]='B';sh[1]='y';sh[2]='e';sh[3]='_';sh[4]='u';sh[5]='\0';
	 }
	 //ReleaseMutex(hMutex); //освобождение мьютекса
	 pthread_mutex_unlock(&Mutex);
	 counter++;
	 }
	 return NULL;
 }
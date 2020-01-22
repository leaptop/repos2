#include <windows.h>//просто копия лекции с небольшим изменением
#include <process.h>
#include <stdio.h>
HANDLE hMutex1, hMutex2;
double sh1=0.0;
int sh2=0;

void Thread( void* pParams );

int main( void ) {
	 hMutex1=CreateMutex(NULL,FALSE,NULL);
	 hMutex2=CreateMutex(NULL,FALSE,NULL);

	 _beginthread( Thread, 0, NULL );

	 while( 1 ){
		 WaitForSingleObject(hMutex2, INFINITE);//захват//WaitForSingleObject Waits until the specified object is in the signaled state or the time-out interval elapses.
		 printf("%g\n",sh1);
		 WaitForSingleObject(hMutex1, INFINITE);//захват
		 printf("%d\n",sh2);
		 ReleaseMutex(hMutex2);//освобождение(1раз освобождает)
		 ReleaseMutex(hMutex1);//освобождение
	 }
	 return 0;
 }

void Thread( void* pParams ){
	 while ( 1 ){
		 WaitForSingleObject(hMutex1, INFINITE);//захват мьютекса. Поменял местами Мьютексы(в лекции hMutex1)
		 sh2++;
		 WaitForSingleObject(hMutex2, INFINITE);//захват мьютекса. Поменял местами Мьютексы(в лекции hMutex2). В варианте лекции просто выводился 0 один раз и всё.
		 sh1+=0.1;
		 ReleaseMutex(hMutex1); //освобождение мьютекса//Releases ownership of the specified mutex object.
		 ReleaseMutex(hMutex2); //освобождение мьютекса
	 }
 }
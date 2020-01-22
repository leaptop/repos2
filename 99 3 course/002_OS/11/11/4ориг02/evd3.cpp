#include <windows.h>
#include <process.h>
#include <stdio.h>
#pragma comment(lib, "libevd1" )
HANDLE hSemaphore;//, hEvent2;
extern __declspec(dllimport)

char sh[6];


int main(void) {
	 hSemaphore=CreateSemaphore(NULL,1,1,"MyTestEvent1");
	/* hEvent1 = CreateEvent(NULL, FALSE,	TRUE, "MyTestEvent1");
	 hEvent2 = CreateEvent(NULL, FALSE,	FALSE, "MyTestEvent2");*/
	 while (1) {
		// WaitForSingleObject(hEvent1,		 INFINITE);
		WaitForSingleObject(hSemaphore, INFINITE);
		printf("sh: %s\n", sh);
		ReleaseSemaphore(hSemaphore,1,NULL);
	//	ReleaseMutex(hMutex);
	//	SetEvent(hEvent2);
	 }
	// CloseHandle(hEvent1);
	// CloseHandle(hEvent2);
	 return 0;
}

#include <windows.h>
#include <process.h>
#include <stdio.h>
#pragma comment(lib, "libevd1" )
HANDLE hMutex;//, hEvent2;
extern __declspec(dllimport)

char sh[6];


int main(void) {
	hMutex=CreateMutex(NULL,FALSE,"MyTestEvent1");
	/* hEvent1 = CreateEvent(NULL, FALSE,	TRUE, "MyTestEvent1");
	 hEvent2 = CreateEvent(NULL, FALSE,	FALSE, "MyTestEvent2");*/
	 while (1) {
		// WaitForSingleObject(hEvent1,		 INFINITE);
		WaitForSingleObject(hMutex, INFINITE);
		printf("sh: %s\n", sh);
		ReleaseMutex(hMutex);
	//	SetEvent(hEvent2);
	 }
	// CloseHandle(hEvent1);
	// CloseHandle(hEvent2);
	 return 0;
}

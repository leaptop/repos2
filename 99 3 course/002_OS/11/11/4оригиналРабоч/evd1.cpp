#include <windows.h>
//#include <process.h>
#include <stdio.h>
#pragma comment(lib, "libevd1" )
HANDLE hEvent1, hEvent2;
extern __declspec(dllimport)
char sh[6];
int main(void) {
 hEvent1 = CreateEvent(NULL, FALSE, TRUE, "MyTestEvent1");//CreateEvent создает или открывает объект события. NULL событие получает дескриптор безопасности по умолчанию. FALSE созд объект события с автобросом. "MyTestEvent1" 
 hEvent2 = CreateEvent(NULL, FALSE, FALSE, "MyTestEvent2");
 while (1) {
 WaitForSingleObject(hEvent1, INFINITE);//ожидание пока указанный объект не окажется в сигнальном состоянии или пока не истечет интервал времени ожидания
printf("sh: %s\n", sh);
SetEvent(hEvent2);//устанавливает указанный объект события в сигнальное состояние
 }
 CloseHandle(hEvent1);
 CloseHandle(hEvent2);
 return 0;
}

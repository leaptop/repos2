#include <windows.h>
#include <iostream>

int main(){
	HANDLE hFileMap;//дескриптор объекта
	LPVOID lpMapView;//указатель на любой тип
	HANDLE hFile;
	char* buff="Hello,students!";
	hFile=CreateFile("tests.txt", GENERIC_READ | GENERIC_WRITE,	  FILE_SHARE_READ |	FILE_SHARE_WRITE, NULL,OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);//файл создает 
	
	hFileMap=CreateFileMapping(hFile,NULL,PAGE_READWRITE,0,256,"MyCommonRegion");//создаёт именованный или неименованный объект в памяти файла для заданного файла 256 байт
	
	lpMapView=MapViewOfFile(hFileMap,FILE_MAP_WRITE,0,0,256);//это предст
	//отображает сопоставленное представление файла в  адресное пространство вызывающего процесса
	
	CopyMemory(lpMapView,buff, sizeof("Hello,students!!"));//копирует блок памяти из одного места в другое
	//из buff в  lmapview
	getchar();
	UnmapViewOfFile(lpMapView);//отображает сопоставленное представление файла из адресного пространства вызывающего процесса
	CloseHandle(hFileMap);
	CloseHandle(hFile);
	return 0;
}


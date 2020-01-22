#include <windows.h>
#include <iostream>

int main(){
	HANDLE hFileMap;
	LPVOID lpMapView;//указатель на любой тип
	char buff[80];
	hFileMap=OpenFileMapping(FILE_MAP_READ,TRUE,"MyCommonRegion");
	//открывает именованный объект сопоставления файлов
	lpMapView=MapViewOfFile(hFileMap,FILE_MAP_READ,0,0,256);
	//отображает сопоставленное представление файла в  адресное пространство вызывающего процесса
	CopyMemory(buff,lpMapView, 80);
	//копирует блок памяти из одного места в другое
	printf("%s\n",buff);
	UnmapViewOfFile(lpMapView);
	//отображает сопоставленное представление файла из адресного пространства вызывающего процесса
	CloseHandle(hFileMap);
	return 0;
}

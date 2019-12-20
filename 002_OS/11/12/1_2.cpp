#include <windows.h>
#include <stdio.h>
#include <conio.h>
#define N 80

int main(int argc, char* argv[]) {
	HANDLE hFile;
	char buff[N] = { '\0' };
	DWORD n;
	hFile = CreateFile("test.txt",	GENERIC_READ | //креат создает или открывает файл, принмает название файла, режим доступа (писать, читать), 
GENERIC_WRITE,	FILE_SHARE_READ | FILE_SHARE_WRITE, NULL,	
OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE) {
		printf("Could not open file.");
		return -1;
	}
	do{
		ReadFile(hFile, buff, sizeof(buff), &n, NULL);//читает данные из файла
		printf("%s\n", buff);
	} while (getchar() != 'q');
	CloseHandle(hFile);
	return 0;
}

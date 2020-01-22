#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#define N 80

using namespace std;

int main(int argc, char* argv[]) {
	HANDLE hFile;
	char buff[N] = { '\0' };
	DWORD n;
	hFile = CreateFile("test.txt", GENERIC_WRITE, FILE_SHARE_READ |	FILE_SHARE_WRITE, NULL, OPEN_ALWAYS,	FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE) {
		printf("Could not open file.");
		return -1;
	}
	do {
	//	cout<<endl<<"?"<<endl;
		scanf("%s",buff);
	//	cout<<endl<<"!"<<endl;
		WriteFile(hFile, buff, sizeof(buff), &n, NULL);
		//cout<<endl<<"&"<<endl;
	} while (getchar() != 27);
	CloseHandle(hFile);
	return 0;
}

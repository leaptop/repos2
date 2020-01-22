#include <windows.h>
#include <psapi.h>
#include <iostream>
#include <string.h>

HINSTANCE hInst;//дескриптор модуля DLL

int main(){
	DWORD pID;//работа с битами(набор битов)
	HANDLE pHndl;//дескриптор, число с пом к-рого можно идентифицировать ресурс
	HMODULE* modHndls;//
	DWORD b_alloc=8, b_needed;
	char modName[MAX_PATH];
	int i;//
	printf("Load lib\n");
	hInst=LoadLibrary("td1.dll");//загружаем библиотеку
	pID=GetCurrentProcessId();//получсет идентификатор процесса вызывающего процесса
	pHndl=OpenProcess(PROCESS_ALL_ACCESS,FALSE,pID);//открывает существующий объект процесса
	while(1){
		 modHndls=(HMODULE*)malloc(b_alloc);

		EnumProcessModules(pHndl,modHndls,b_alloc,&b_needed);//перечисляет модули текущего процесса для определения какой из них использует DLL
		 printf("%u %u\n",pID,pHndl);
		 printf("%u %u\n",b_alloc, b_needed);
		 if(b_alloc>=b_needed)
		 break;
		 else{
		free(modHndls);
		b_alloc=b_needed;
		 }
	 }
	for(i=0;i<b_needed/sizeof(DWORD);i++){
		GetModuleBaseName(pHndl, modHndls[i],(LPSTR)modName, sizeof(modName));//получает базовое имя указанного модуля
		printf("%u\t%s", modHndls[i],modName);
		GetModuleFileName(modHndls[i], (LPSTR)modName, sizeof(modName));//получает полный путь к файлу, содержащему указанный модуль
		printf("\t%s\n",modName);
	}
	 printf("\n free lib\n");
	 FreeLibrary(hInst);//процессы которые явно связываются с библиотекой DLL  вызывают функцию FreeLibrary, если модуль DLL больше не нужен.
	while(1){//надо ещё раз обратиться к процессу, т.к. библиотеку отключили
		 modHndls=(HMODULE*)malloc(b_alloc);//типа ещё раз считывает процесс в переменную
		EnumProcessModules(pHndl,modHndls,b_alloc,&b_needed);//перечисляет модули текущего процесса для определения какой из них использует DLL
		 printf("%u %u\n",pID,pHndl);
		 printf("%u %u\n",b_alloc, b_needed);
		 if(b_alloc>=b_needed)
		 break;
		 else{
		free(modHndls);
		b_alloc=b_needed;
		 }
	 }
	for(i=0;i<b_needed/sizeof(DWORD);i++){
		GetModuleBaseName(pHndl, modHndls[i],(LPSTR)modName, sizeof(modName));//получает базовое имя указанного модуля
		printf("%u\t%s", modHndls[i],modName);
		GetModuleFileName(modHndls[i], (LPSTR)modName, sizeof(modName));
		printf("\t%s\n",modName);
	}
	getchar();
	return 0;
}

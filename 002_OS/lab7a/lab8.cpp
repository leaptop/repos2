#include <windows.h>
#include <psapi.h>
#include <imagehlp.h>
#include <iostream>
//показывает импортированные функции из dll
//перейти в папку через командную строку, lab8.exe td1.dll
int main(int argc, char* argv[]){
	LOADED_IMAGE LoadedImage;//содержит информацию об изображении
	PUCHAR BaseAddress;//указатель на учар, а учар - ансигнед чар
	DWORD RVAExpDir, VAExpAddress;//работа с битами(набор битов) ;RVA - относительный виртуальный адрес, VA - виртуальный адрес
	IMAGE_EXPORT_DIRECTORY* ExpTable;
	char* sName;
	DWORD nNames;
	char* pName;
	char** pNames;
	DWORD i;
	//Загружаем PE-файл
	if(!MapAndLoad(argv[1], NULL, &LoadedImage, TRUE,TRUE)){
		printf("Something's wrong!\n");
		getchar();
		exit(1);
	}
	//Считываем базовый адрес загрузочного модуля
	BaseAddress=LoadedImage.MappedAddress;
	printf("0x%lx - Base Address\n",BaseAddress);
	//Определяем относительный виртуальный адрес - RVA,таблицы экспорта
	RVAExpDir= LoadedImage.FileHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
	printf("0x%lx -RVA\n", RVAExpDir);
	//Определяем виртуальный адрес массива строк по его RVA
	VAExpAddress=(DWORD)ImageRvaToVa(LoadedImage.FileHeader, BaseAddress, RVAExpDir,NULL);
	printf("0x%lx -VA\n",VAExpAddress);
	ExpTable=(IMAGE_EXPORT_DIRECTORY*)VAExpAddress;
	//Определяем виртуальный адрес строки - имени PE-файла,
	//по его RVA
	sName=(char*)ImageRvaToVa(LoadedImage.FileHeader,BaseAddress, ExpTable->Name,NULL);
	printf("Name of PEF: %s\n",sName);
	//Определяем виртуальный адрес массива строк по его RVA
	pNames=(char**)ImageRvaToVa(LoadedImage.FileHeader,BaseAddress, ExpTable->AddressOfNames,NULL);
	//Считываем количество экспортируемых имен из таблицы
	//экспорта
	nNames=ExpTable->NumberOfNames;
	printf("Exported data:\n");
	for(i=0;i<nNames;i++){
		//Определяем виртуальный адрес i-ого имени по его RVA
		pName=(char*)ImageRvaToVa(LoadedImage.FileHeader, BaseAddress, (DWORD)*pNames,NULL);
		printf("%s\n",pName);
		*pNames++; //переходим к следующей строке
	}
	UnMapAndLoad(&LoadedImage);
	getchar();
	return 0;
}
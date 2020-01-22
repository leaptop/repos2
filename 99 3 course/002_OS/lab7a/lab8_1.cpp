#include <windows.h>
#include <imagehlp.h>
#include <iostream>
//берёт экзешник и смотрит в нём импортированные данные
//lab8_1.exe notepad.exe
//сюда можно любой(почти) экзешник отправить чтобы посмотреть импортированные данные
int main(int argc, char* argv[]){
	LOADED_IMAGE LoadedImage;
	PUCHAR BaseAddress;
	DWORD RVAImpDir, VAImpAddress;
	IMAGE_IMPORT_DESCRIPTOR* ImpTable;//изменен тип по сравнению с 8 лабой
	char* sName;
	DWORD nNames;
	char* pName;
	char** pNames;
	DWORD i;
	//Загружаем PE-файл
	if(!MapAndLoad(argv[1], NULL, &LoadedImage, FALSE,TRUE)){
		printf("Something's wrong!\n");
		getchar();
		exit(1);
	}
	//Считываем базовый адрес загрузочного модуля
	BaseAddress=LoadedImage.MappedAddress;
	printf("0x%lx - Base Address\n",BaseAddress);
	//Определяем относительный виртуальный адрес - RVA,таблицы импорта
	RVAImpDir= LoadedImage.FileHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress;//имадждиректори... изменилась и мы переходим на след строку в массиве
	printf("0x%lx -RVA\n", RVAImpDir);
	//Определяем виртуальный адрес массива строк по его RVA
	VAImpAddress=(DWORD)ImageRvaToVa(LoadedImage.FileHeader, BaseAddress, RVAImpDir,NULL);
	printf("0x%lx -VA\n",VAImpAddress);
	ImpTable=(IMAGE_IMPORT_DESCRIPTOR*)VAImpAddress;
	//Определяем виртуальный адрес строки - имени PE-файла,
	//по его RVA
	sName=(char*)ImageRvaToVa(LoadedImage.FileHeader,BaseAddress, ImpTable->Name,NULL);
	printf("Name of PEF: %s\n",sName);
	//Определяем виртуальный адрес массива строк по его RVA
	pNames=(char**)ImageRvaToVa(LoadedImage.FileHeader,BaseAddress, ImpTable->FirstThunk,NULL);//эта штука изменилась
	//Считываем количество экспортируемых имен из таблицы
	//экспорта
	//nNames=ImpTable->NumberOfNames;
	printf("Imported data:\n");
	while(1){
		//Определяем виртуальный адрес i-ого имени по его RVA
		pName=(char*)ImageRvaToVa(LoadedImage.FileHeader, BaseAddress, (DWORD)*pNames,NULL);
		if(pName==NULL)break;
		printf("%s\n",pName);
		*pNames++; //переходим к следующей строке
	}
	UnMapAndLoad(&LoadedImage);
	getchar();
	return 0;
}
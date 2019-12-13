#include <stdio.h>


  
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h> 
#pragma warning(disable : 4996)


struct tov { char name[10]; int nLuggage; int weight; float c; int kol; }t1;
void input(FILE *); // создание нового файла// то же, что и app, просто текст разный немного выводится
void print(FILE *); // просмотр файла
void app(FILE *); // добавление в файл
void find(FILE *); // поиск и изменение 
void NAddition(FILE*);//создание N записей
void del(FILE *);//удаление записей о пассажирах, общий вес вещей которых меньше, чем 10 кг.
int main(int argc, char *argv[])
{

	setlocale(LC_ALL, "RUS");
	char c;
	int n;
	FILE *tf = NULL;
	while (1)
	{
		system("CLS");
		puts("  1 – новый файл");
		puts("  2 – просмотр файла");
		puts("  3 – добавление в файл");
		//puts("  4 – поиск ");
		puts("  5 - удаление пассажиров с весом багажа меньше 10");
		puts("  6 - добавление n записей");
		puts("  0 - выход");
		c = getch();
		switch (c)
		{
		case '1':input(tf); break;
		case '2':print(tf); break;
		case '3':app(tf); break;
			//case '4':find(tf); break;
		case '5':del(tf); break;
		case '6':NAddition(tf); break;
		case '0':return 0;
		default: puts(" неверный режим");
		}
	}
}
void find(FILE *tf)
{
	char c, tov[10];
	tf = fopen("file1.dat", "rb+"); // открытие бинарного файла для чтения и записи
	system("CLS");
	puts(" Название искомого товара: ");
	gets(tov);
	fread(&t1, sizeof(t1), 1, tf);
	while (!feof(tf))
	{
		if (strcmp(t1.name, tov) == 0)
		{
			printf(" tovar %10s cena %6.2f kolic %d", t1.name, t1.c, t1.kol);
			_getch();
		}
		fread(&t1, sizeof(t1), 1, tf);
	}
	fclose(tf);
}
void del(FILE* tf) {
	FILE *tf2;
	tf = fopen("file1.dat", "rb+"); // открытие бинарного файла для чтения и записи
	tf2 = fopen("file2.dat", "wb");
	fread(&t1, sizeof(t1), 1, tf);
	while (!feof(tf)) {
		if (t1.weight >= 10) {
			fwrite(&t1, sizeof(t1), 1, tf2);
		}
		fread(&t1, sizeof(t1), 1, tf);
	}
	fclose(tf);
	fclose(tf2);
	remove("file1.dat");
	rename("file2.dat", "file1.dat");
}
void NAddition(FILE *tf) {
	int n = 0;
	system("CLS");
	printf("Сколько записей создать? ");
	scanf("%d", &n);

	char ch;
	tf = fopen("file1.dat", "ab"); // открытие бинарного файла для добавления
	system("CLS");
	printf("\n  Ввод пассажиров\n");
	do
	{
		printf("\n name: "); scanf("%s", &t1.name);
		printf(" вес багажа: "); scanf("%d", &t1.weight);
		printf(" количество мест багажа: "); scanf("%d", &t1.nLuggage);
		fwrite(&t1, sizeof(t1), 1, tf);
		//printf(" Закончить?  y/n ");
		//ch = getch();
		n--;
	} while (//ch != 'y'&& 
		n > 0);
	fclose(tf);
}
void app(FILE *tf)
{
	char ch;
	tf = fopen("file1.dat", "ab"); // открытие бинарного файла для добавления
	system("CLS");
	printf("\n  Ввод пассажиров\n");
	do
	{
		printf("\n name: "); scanf("%s", &t1.name);
		printf(" вес багажа: "); scanf("%d", &t1.weight);
		printf(" количество мест багажа: "); scanf("%d", &t1.nLuggage);
		fwrite(&t1, sizeof(t1), 1, tf);
		printf(" Закончить?  y/n ");
		ch = getch();
	} while (ch != 'y');
	fclose(tf);
}
void input(FILE *tf)
{
	char ch;
	tf = fopen("file1.dat", "wb"); // открытие бинарного файла для записи
	system("CLS");
	printf("\n Ввод ФИО\n");
	do
	{
		printf("\n Введите ФИО латиницей: "); scanf("%s", &t1.name);
		printf(" вес багажа: "); scanf("%d", &t1.weight);
		printf(" количество мест занимаемых багажом: "); scanf("%d", &t1.nLuggage);
		fwrite(&t1, sizeof(t1), 1, tf); // запись в файл одной структуры t1
		printf("\n Закончить?  y/n  ");
		ch = getch();
	} while (ch != 'y');
	fclose(tf);
}

void print(FILE *tf)
{
	int i;
	system("CLS");
	tf = fopen("file1.dat", "rb"); // открытие бинарного файла для чтения
	i = 1;
	fread(&t1, sizeof(t1), 1, tf); // чтение из файла одной структуры t1
	while (!feof(tf))
	{
		printf("\n Name: %10s   weight: %3d   Kolichestvo mest: %d", t1.name, t1.weight, t1.nLuggage);
		fread(&t1, sizeof(t1), 1, tf);
		i++;
	}
	getch();
}





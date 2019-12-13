#pragma once
#pragma warning(disable : 4996)
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
char** readFile(char **text, char chr[][20]) {//Возвращает указатель на массив массивов чаров
	setlocale(LC_ALL, "RUS");
	const int nteams = 10;
	char ch = ' ', sl[20];

	FILE *tsopen, *pr;
	if (tsopen = fopen("teams.txt", "rt"));
	else perror("Error");
	for (int i = 0; i < nteams; i++) {
		text[i] = fgets(chr[i], sizeof(sl), tsopen);
	//	text[i] = &chr[i][0];//Даже с этим незакомментированным кодом работает... Надеюсь он правильный))
		printf("%s", text[i]);
	}

	return **text;
}
//int main()
//{
//	char chr[10][20];
//	char **c;
//	c = (char  **)malloc(10 * sizeof(char *));
//	readFile(c, chr);
//	printf("\n%s", c[4]);
//
//	_getch();
//	return 0;
//}
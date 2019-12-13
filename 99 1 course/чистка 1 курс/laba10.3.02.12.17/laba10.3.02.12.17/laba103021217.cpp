#include "stdafx.h"
#include <stdio.h>
#include <clocale>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	setlocale(LC_ALL, "Russian");
	system("CLS");
	char gwords[20][30], text[80], textn[80], nol[30];
	int i = 0, j = 0, l = 0, c = 0, count = 1;
	printf("введите фамилии через запятую с пробелом");
	gets_s(text);

	while (text[i] != '\0')
	{
		if (text[i] != ' ' && text[i] != ',') {
			

			gwords[l][c] = text[i];
			c++;
			if (text[i + 1] == '\0')  gwords[l][c] = '\0';
		}
		else {
			gwords[l][c] = '\0';
			l++; c = 0;
				
			}

		i++;
	}

	for (i = 0; i <= l; i++)
		for (j = i; j <l; j++)
		{
			//	printf("strcmp(%s, %s) = %d\n", gwords[i], gwords[j], strcmp(gwords[i], gwords[j]));
			if (strcmp(gwords[i], gwords[j]) >0)
			{
				strcpy_s(nol, gwords[i]); strcpy_s(gwords[i], gwords[j]); strcpy_s(gwords[j], nol);
			}
		}
	
	for (int z = 0; z <= l; z++) {

		printf("%s\n", gwords[z]);
	}
	system("PAUSE");
	return 0;

}
//just, a, number, of, words, of, freaking, words
//just a number of words
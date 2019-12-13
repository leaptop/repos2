#include "stdafx.h"
#include <stdio.h>
#include <clocale>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	setlocale(LC_ALL, "Russian");
	system("CLS");
	char gwords[20][30], text[80], nol[] = "";
	int i = 0, j = 0, l = 0, c = 0, count = 1;

	printf("¬ведите текст");
	gets_s(text);
	while (text[i] != '\0') {
		if (text[i] != ' ') {
			gwords[l][c] = text[i];
			c++;
		}
		else {
			gwords[l][c] = '\0';
			l++; c = 0;
		}
		i++;
	}
	for (int z = 0; z < l; z++) {

		printf("Check %s\n", gwords[z]);
	}
	for (int z = 0; z < l; z++) {

		for (int f = z + 1; f < l; f++) {

			if (strcmp(gwords[z], gwords[f]) == 0 && strcmp(gwords[z], nol) != 0) {
				if (strncmp(gwords[z], nol, 3) == 0) break;
				count++; strcpy_s(gwords[f], nol);
			}
		}
		printf("%s %d\n", gwords[z], count); count = 1;
	}
	system("PAUSE");
	return 0;
}// just a number of words of freaking words
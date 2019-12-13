#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** board;

void FillBoard() {


	board[0] = "hello";
	board[1] = "bye";
	}

void InitNames() {
	int i, j;
	board = (char**)malloc(8 * sizeof(char*));
	for (i = 0; i < 8; i++) {
		board[i] = (char*)malloc(8 * sizeof(char));
		for (j = 0; j < 8; j++) {
			board[i][j] = ' ';
		}
	}
	FillBoard();
}

void SetPrint(char** names, int m) {

	int i, j, l;

	char lines[] = "--------------------";

	for (i = 0; i < m; i++) {
		if (i % 2 == 1) {
			printf("%c", names[i]);
			for (j = 0; j < (20 - strlen(names[i])); j++)
				printf("-");
			for (l = 0; l < 5; l++)
				printf("\n                       I");
		}


	}
}
int main() {

	InitNames();
	SetPirnt(board, 1);
}
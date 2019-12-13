#include "MyBigChar.h"

int bc_printA(char *STR) {
	printf("\E(0%s\E(B", STR);

	return 0;
}

int bc_box(int X1, int Y1, int X2, int Y2) {
	int tmp;
	int max_x, max_y;
	int i;

	if (X1 > X2) {
		tmp = X1;
		X1 = X2;
		X2 = tmp;
	}

	if (Y1 > Y2) {
		tmp = Y1;
		Y1 = Y2;
		Y2 = tmp;
	}

	if (X1 < 0 || Y1 < 0 || X2 - X1 < 2 || Y2 - Y1 < 2) {
		return ERROR;
	}
	else {
		mt_getscreensize(&max_y, &max_x);

		if (X2 > max_x || Y2 > max_y) {
			return ERROR;
		}
	}

	mt_gotoXY(X1, Y1);
	bc_printA(BOXCHAR_UP_LEFT);
	
	for (i = X1 + 1; i < X2 - 1; ++i) {
		bc_printA(BOXCHAR_HORIZONTAL);
	}

	mt_gotoXY(X2 - 1, Y1);
	bc_printA(BOXCHAR_UP_RIGHT);

	for (i = Y1 + 1; i < Y2; ++i) {
		mt_gotoXY(X2 - 1, i);
		bc_printA(BOXCHAR_VERTICAL);
	}

	for (i = Y1 + 1; i < Y2; ++i) {
		mt_gotoXY(X1, i);
		bc_printA(BOXCHAR_VERTICAL);
	}

	mt_gotoXY(X1, Y2);
	bc_printA(BOXCHAR_DOWN_LEFT);
	
	for (i = X1 + 1; i < X2 - 1; ++i) {
		bc_printA(BOXCHAR_HORIZONTAL);
	}
	bc_printA(BOXCHAR_DOWN_RIGHT);

	return 0;
}

int bc_printbigchar(unsigned int *BIG, int X, int Y, enum Color FG, enum Color BG) {
	int maxx, maxy;
	unsigned int bit;
	int i, j, k;
	char string[9];
	string[8] = '\0';

	if (X < 0 || Y < 0) {
		return ERROR;
	}
	else {
		mt_getscreensize(&maxy, &maxx);

		if (X > maxx || Y > maxy) {
			return ERROR;
		}
	}

	mt_setfgcolor(FG);
	mt_setbgcolor(BG);

	for (i = 1; i >= 0; --i) {
		bit = BIG[i];

		for (j = 3; j >= 0; --j) {
			mt_gotoXY(X, Y + i * 4 + j);

			for (k = 7; k >= 0; --k) {
				if (bit & 1) {
					string[k] = BOXCHAR_FULL;
				}
				else {
					string[k] = ' ';
				}

				bit >>= 1;
			}

			bc_printA(string);
		}
	}
	mt_setfgcolor(Default);
	mt_setbgcolor(Default);

	return 0;
}

int bc_setbigcharpos(int *BIG, int X, int Y, int VALUE) {
	int position;

	if (X < 0 || Y < 0 || X > 7 || Y > 7 || VALUE < 0 || VALUE > 1) {
		return ERROR;
	}

	if (Y <= 3) {
		position = 0;
	}
	else {
		position = 1;
	}

	Y = Y % 4;
	if (VALUE) {
		BIG[position] |= 1 << (Y * 8 + X);
	}
	else {
		BIG[position] &= ~(1 << (Y * 8 + X));
	}

	return 0;
}

int bc_getbigcharpos(int *BIG, int X, int Y, int *VALUE) {
	int position;

	if (X < 0 || Y < 0 || X > 7 || Y > 7) {
		return ERROR;
	}

	if (Y <= 3) {
		position = 0;
	}
	else {
		position = 1;
	}

	Y = Y % 4;
	*VALUE = (BIG[position] >> (Y * 8 + X)) & 1;

	return 0;
}

int bc_bigcharwrite(int FD, int *BIG, int COUNT) {
	if (write(FD, &COUNT, sizeof(COUNT)) == -1) {
		return ERROR;
	}

	if (write(FD, BIG, COUNT * (sizeof(int)) * 2) == -1) {
		return ERROR;
	}

	return 0;
}

int bc_bigcharread(int FD, int *BIG, int NEED_COUNT, int *COUNT) {
	int n, outcome;

	outcome = read(FD, &n, sizeof(n));
	if (outcome == -1 || (outcome != sizeof(n))) {
		return ERROR;
	}

	outcome = read(FD, BIG, NEED_COUNT * sizeof(int) * 2);
	if (outcome == -1) {
		return ERROR;
	}

	*COUNT = outcome / (sizeof(int) * 2);

	return 0;
}
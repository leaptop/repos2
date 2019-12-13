#include "MyTerm.h"

int mt_clrscr() {
	printf("\E[H\E[2J");

	return 0;
}

int mt_gotoXY(int X, int Y) {
	int max_x, max_y;

	mt_getscreensize(&max_y, &max_x);
	if ((Y >= max_y) || (X >= max_x) || (X < 0) || (Y < 0)) {
		return ERROR;
	}

	printf("\E[%d;%dH", Y, X);

	return 0;
}

int mt_getscreensize(int *MAX_ROWS, int *MAX_COLUMNS) {
	struct winsize buffer;

	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &buffer)) {
		return ERROR;
	}

	*MAX_ROWS = buffer.ws_row;
	*MAX_COLUMNS = buffer.ws_col;

	return 0;
}

int mt_setfgcolor(enum Color COLOR) {
	switch (COLOR) {
	case Black:
		printf("\E[30m");
		break;

	case Red:
		printf("\E[31m");
		break;

	case Green:
		printf("\E[32m");
		break;

	case Brown:
		printf("\E[33m");
		break;

	case Blue:
		printf("\E[34m");
		break;

	case Magneta:
		printf("\E[35m");
		break;

	case Cyan:
		printf("\E[36m");
		break;

	case LGray:
		printf("\E[37m");
		break;

	case Default:
		printf("\E[39m");
		break;

	default:
		return ERROR;
	}

	return 0;
}

int mt_setbgcolor(enum Color COLOR) {
	switch (COLOR) {
	case Black:
		printf("\E[40m");
		break;

	case Red:
		printf("\E[41m");
		break;

	case Green:
		printf("\E[42m");
		break;

	case Brown:
		printf("\E[43m");
		break;

	case Blue:
		printf("\E[44m");
		break;

	case Magneta:
		printf("\E[45m");
		break;

	case Cyan:
		printf("\E[46m");
		break;

	case LGray:
		printf("\E[47m");
		break;

	case Default:
		printf("\E[49m");
		break;

	default:
		return ERROR;
	}

	return 0;
}
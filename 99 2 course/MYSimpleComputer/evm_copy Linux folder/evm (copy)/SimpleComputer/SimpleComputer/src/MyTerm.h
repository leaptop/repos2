#pragma once

#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

#include "MySimpleComputer.h"

enum Color {
	Black,
	Red,
	Green,
	Brown,
	Blue,
	Magneta,
	Cyan,
	LGray,
	Default
};

int mt_clrscr();
int mt_gotoXY(int X, int Y);
int mt_getscreensize(int *ROWS, int *COLUMNS);
int mt_setfgcolor(enum Color COLOR);
int mt_setbgcolor(enum Color COLOR);
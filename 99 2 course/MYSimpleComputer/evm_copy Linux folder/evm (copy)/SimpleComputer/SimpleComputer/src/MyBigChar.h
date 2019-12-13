#pragma once

#include "MyTerm.h"

#define BOXCHAR_FULL 'a'
#define BOXCHAR_DOWN_RIGHT "j"
#define BOXCHAR_DOWN_LEFT "m"
#define BOXCHAR_UP_RIGHT "k"
#define BOXCHAR_UP_LEFT "l"
#define BOXCHAR_VERTICAL "x"
#define BOXCHAR_HORIZONTAL "q"

int bc_printA(char *STR);
int bc_box(int X1, int Y1, int X2, int Y2);
int bc_printbigchar(unsigned int *BIG, int X, int Y, enum Color FG, enum Color BG);
int bc_setbigcharpos(int *BIG, int X, int Y, int VALUE);
int bc_getbigcharpos(int *BIG, int X, int Y, int *VALUE);
int bc_bigcharwrite(int FD, int *BIG, int COUNT);
int bc_bigcharread(int FD, int *BIG, int NEED_COUNT, int *COUNT);
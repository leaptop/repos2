#pragma once

#include <math.h>
#include <signal.h>
#include <sys/time.h>

#include "MySimpleComputer.h"
#include "MyBigChar.h"
#include "MyReadKeys.h"

extern unsigned int Plus[2];
extern unsigned int Minus[2];
extern unsigned int Zero[2];
extern unsigned int One[2];
extern unsigned int Two[2];
extern unsigned int Three[2];
extern unsigned int Four[2];
extern unsigned int Five[2];
extern unsigned int Six[2];
extern unsigned int Seven[2];
extern unsigned int Eight[2];
extern unsigned int Nine[2];

extern int instructionCounter;

void print_simbol(int X, int Y, int SIMBOL, enum Color FG, enum Color BG);
void print_big_char(int X, int Y, int NUMBER, enum Color FG, enum Color BG);
void sc_interface();
void info();
void instrcnt2xy();
int control();
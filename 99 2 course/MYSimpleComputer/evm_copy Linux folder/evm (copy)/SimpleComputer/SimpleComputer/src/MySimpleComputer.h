#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "MyTerm.h"
#include "Interface.h"

#define MEMORY_SIZE 100

#define FLAG_WRONG_ADDRESS 1
#define FLAG_OPEN_FILE 2
#define FLAG_FILE_SIZE 4
#define FLAG_WRONG_COMMAND 8
#define FLAG_WRONG_OPERAND 16
#define FLAG_PARITY 32
#define FLAG_IGNORE_SYSTEM_TIMER 64
#define FLAG_HALT 128

#define ERROR -1

extern int sc_memory[MEMORY_SIZE];
extern int sc_reg_flags;
extern int *correct_ops;
extern int ops_num;
extern int instructionCounter;
extern unsigned int x, y, printcount;
extern int accumulator;

int reset();
int sc_memoryInit();
int sc_memorySet(int ADDRESS, int VALUE);
int sc_memoryGet(int ADDRESS, int *VALUE);
int sc_memorySave(char *FILENAME);
int sc_memoryLoad(char *FILENAME);
int sc_regInit();
int sc_regSet(int REGISTER, int VALUE);
int sc_regGet(int REGISTER, int *VALUE);
int sc_commandEncode(int COMMAND, int OPERAND, int *VALUE);
int sc_commandDecode(int VALUE, int *COMMAND, int *OPERAND);
int ALU(int command, int operand);
void CU();
#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MEMORY_SIZE 100

int command_check(char COMMAND);
int sc_commandEncode(int COMMAND, int OPERAND, int *VALUE);
int str2command(char *str);
int pars_line(char *str, int *addr, int *value);
int asm2bin(char *filename1, char *filename2);
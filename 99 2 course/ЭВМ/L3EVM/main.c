#include "bc.h"
#include "mt.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int *alph = NULL;

void print_mem()
{
    bc_box(1, 1, 61, 12);
    mt_gotoXY(30, 0);
    char tmp[] = " Memory ";
    write(1, tmp, sizeof(tmp));
    for (int i = 0; i < 100; i++) {
        mt_gotoXY(2 + 6 * (i / 10), 2 + (i % 10));
        char tmp1[] = "+0000";
        write(1, tmp1, sizeof(tmp1));
    }
}

void print_accum()
{
    bc_box(62, 1, 22, 3);
    mt_gotoXY(66, 1);
    char tmp[] = " accumulator ";
    write(1, tmp, sizeof(tmp));
    mt_gotoXY(71, 2);
    char tmp1[] = "+9999";
    write(1, tmp1, sizeof(tmp1));
}

void print_instcnt()
{
    bc_box(62, 4, 22, 3);
    mt_gotoXY(63, 4);
    char tmp[] = " instructionCounter ";
    write(1, tmp, sizeof(tmp));
    mt_gotoXY(71, 5);
    char tmp1[] = "+0000";
    write(1, tmp1, sizeof(tmp1));
}

void print_operation()
{
    bc_box(62, 7, 22, 3);
    mt_gotoXY(68, 7);
    char tmp[] = " Operation ";
    write(1, tmp, sizeof(tmp));
    char tmp1[] = "+00 : 00";
    mt_gotoXY(69, 8);
    write(1, tmp1, sizeof(tmp1));
}

void print_flg()
{
    bc_box(62, 10, 22, 3);
    mt_gotoXY(69, 10);
    char tmp[] = " Flags ";
    write(1, tmp, strlen(tmp));
    char tmp1[] = "O Z M F C";
    mt_gotoXY(67, 11);
    write(1, tmp1, strlen(tmp1));
}

void print_membc()
{
    bc_box(1, 13, 50, 10);
    int big[] = {alph[16 * 2], alph[16 * 2 + 1]};
    bc_printbigchar(big, 2, 14, deflt, deflt);
    int big1[] = {alph[9 * 2], alph[9 * 2 + 1]};
    for (int i = 0; i < 4; i++)
        bc_printbigchar(big1, 2 + 10 * (i + 1), 14, deflt, deflt);
}

void print_keys()
{
    bc_box(51, 13, 33, 10);
    mt_gotoXY(52, 13);
    char tmp[] = " Keys: ";
    write(1, tmp, strlen(tmp));
    char *tmp1[] = {"l - load", "s - save", "r - run", "t - step", "i - reset",
        "F5 - accumulator", "F6 - instructionCounter"};
    for (int i = 0; i < 7; i++) {
        mt_gotoXY(52, 14 + i);
        write(1, tmp1[i], strlen(tmp1[i]));
    }
}

int main()
{
    int fd = open("font", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    int cnt = 0;
    alph = (int*) malloc(sizeof(int) * 2 * 17);
    if (bc_bigcharread(fd, alph, 17, &cnt) == -1)
        return -1;
    mt_clrscr();
    print_mem();
    print_accum();
    print_instcnt();
    print_operation();
    print_flg();
    print_membc();
    print_keys();
    printf("\n");
    printf("\n");
    printf("\n");
    mt_setfgcolor(deflt);
    return 0;
}

//bc.h
#ifndef BC_H
#define BC_H

#include "mt.h"

int bc_printA(char *str);
int bc_box(int x1, int y1, int x2, int y2);
int bc_printbigchar(int *bit, int x, int y, enum colors fgcolor, enum colors bgcolor);
int bc_setbigcharpos(int *big, int x, int y, int value);
int bc_getbigcharpos(int *big, int x, int y, int *value);
int bc_bigcharwrite(int fd, int *big, int count);
int bc_bigcharread(int fd, int *big, int need_count, int *count);

#endif

//bc.c
#include "bc.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int bc_printA(char *str)
{
    write(1, "\E(0", 3);
    write(1, str, sizeof(char) * strlen(str));
    write(1, "\E(B", 3);
    return 0;
}

int bc_box(int x1, int y1, int x2, int y2)
{
    for (int i = 0; i < y2; i++)
        for (int j = 0; j < x2; j++) {
            mt_gotoXY(x1 + j, y1 + i);
            if (i == 0 && j == 0)
                bc_printA("l");
            else if (i == 0 && j == x2 - 1)
                bc_printA("k\n");
            else if (i == y2 - 1 && j == 0)
                bc_printA("m");
            else if (i == y2 - 1 && j == x2 - 1)
                bc_printA("j");
            else if ((i == 0 || i == y2 - 1) && j > 0 && j < x2 - 1)
                bc_printA("q");
            else if (i > 0 && i < y2 - 1 && j == 0)
                bc_printA("x");
            else if (i > 0 && i < y2 - 1 && j == x2 - 1)
                bc_printA("x\n");
            else
                write(1, " ", sizeof(char));
        }
}

int bc_printbigchar(int *big, int x, int y, enum colors fgcolor, enum colors bgcolor)
{
    mt_setfgcolor(fgcolor);
    mt_setbgcolor(bgcolor);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            mt_gotoXY(x + j, y + i);
            int value;
            bc_getbigcharpos(big, j, i, &value);
            if (!value)
                write(1, " ", 1);
            else
                bc_printA("a");
        }
        write(1, "\n", 1);
    }
    mt_setbgcolor(deflt);
    mt_setfgcolor(deflt);
    return 0;
}

int bc_setbigcharpos(int *big, int x, int y, int value)
{
    if (x < 0 || x > 7 || y < 0 || y > 7 || value > 1 || value < 1)
        return -1;
    int pos = (y > 3) ? 1 : 0;
    y %= 4;
    if (!value)
        big[pos] &= ~(1 << (y * 8 + x));
    if (value)
        big[pos] |= 1 << (y * 8 + x);
    return 0;
}

int bc_getbigcharpos(int *big, int x, int y, int *value)
{
    if (x < 0 || x > 7 || y < 0 || y > 7)
        return -1;
    int pos = y / 4;
    y %= 4;
    if (big[pos] & (1 << (y * 8 + x)))
        *value = 1;
    else
        *value = 0;
    return 0;
}

int bc_bigcharwrite(int fd, int *big, int count)
{
    for (int i = 0; i < count * 2; i++)
        if (write(fd, &big[i], sizeof(int)) == -1)
            return -1;
    return 0;
}

int bc_bigcharread(int fd, int *big, int need_count, int *count)
{
    for (*count = 0; (*count < need_count * 2); *count += 1) 
        if (read(fd, &big[*count], sizeof(int)) == -1)
            return -1;
    return 0;
}
// trpo1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <time.h>
#include<stdlib.h>// for srand
#include <iostream>
#include<conio.h>//for _getch()
#include<clocale>
#include <stdio.h>
//include "CC.c"
void ClearChess();
void Chess(char Q[][8]);
int main()
{
	char Q[8][8] = {
	{ 'R','N','B','Q','K','B','N','R' },
	{ 'P','P','P','P','P','P','P','P' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ' },
	{ 'p','p','p','p','p','p','p','p' },
	{ 'r','n','b','q','k','b','n','r' }
	};

	Chess(Q);
	ClearChess();
	_getch();
	return 0;
}


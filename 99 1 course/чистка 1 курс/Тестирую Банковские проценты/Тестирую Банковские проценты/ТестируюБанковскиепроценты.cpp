// ТестируюБанковскиепроценты.cpp : Defines the entry point for the console application.
//
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "stdafx.h"
double  y = 1, m;
double prc = 0.05, c = 0, s = 0;

int main()
{
	m = y * 12;
	s = 10000;
	c = prc / 12;
	for (size_t i = 0; i < m; i++)
	{
		s += s*c;

	}
	printf("s = %f", s);
	system("PAUSE");
    return 0;

}


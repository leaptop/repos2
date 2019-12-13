#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>

#include "MySimpleComputer.h"
#include "MyTerm.h"
#include "Interface.h"

int sc_reg_flags;
int *correct_ops;
int ops_num;
int instructionCounter;
int unsigned x, y, printcount;
int accumulator;

unsigned int Plus[2] = { 404232447, 4279769112 };
unsigned int Minus[2] = { 255, 4278190080 };
unsigned int Zero[2] = { 2118535762, 1382179454 };
unsigned int One[2] = { 236863102, 235802126 };
unsigned int Two[2] = { 1014908422, 202931838 };
unsigned int Three[2] = { 1013319228, 1007052348 };
unsigned int Four[2] = { 1717986942, 2114323974 };
unsigned int Five[2] = { 2122211452, 503717500 };
unsigned int Six[2] = { 236728416, 2120640126 };
unsigned int Seven[2] = { 2114061320, 2082488320 };
unsigned int Eight[2] = { 1010975292, 1111638588 };
unsigned int Nine[2] = { 2118271614, 33686142 };

void signalhandler1() {
	reset();
}

void signalhandler2() {
	int flag;

	CU();

	if (instructionCounter < 99) {
		++instructionCounter;
	}

	sc_regGet(FLAG_HALT, &flag);

	if (flag) {
		struct itimerval nval;

		nval.it_interval.tv_sec = 0;
		nval.it_interval.tv_usec = 0;
		nval.it_value.tv_sec = 0;
		nval.it_value.tv_usec = 0;

		setitimer(ITIMER_REAL, &nval, NULL);

		sc_regSet(FLAG_IGNORE_SYSTEM_TIMER, 1);
	}

	info();
}

int main() {
	int flag;

	reset();

	signal(SIGUSR1, signalhandler1);
	signal(SIGALRM, signalhandler2);

	mt_clrscr();
	sc_interface();

	while (1) {
		sc_regGet(FLAG_IGNORE_SYSTEM_TIMER, &flag);

		if (flag) {
			info();

			if (control()) {
				break;
			}
		}
	}

	mt_clrscr();

	return 0;
}
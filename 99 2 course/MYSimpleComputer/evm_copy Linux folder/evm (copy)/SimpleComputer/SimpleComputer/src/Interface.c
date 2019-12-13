#include "Interface.h"

void print_simbol(int X, int Y, int SIMBOL, enum Color FG, enum Color BG) {
	switch (SIMBOL) {
	case 0:
		bc_printbigchar(Zero, X, Y, FG, BG);

		break;

	case 1:
		bc_printbigchar(One, X, Y, FG, BG);

		break;

	case 2:
		bc_printbigchar(Two, X, Y, FG, BG);

		break;

	case 3:
		bc_printbigchar(Three, X, Y, FG, BG);

		break;

	case 4:
		bc_printbigchar(Four, X, Y, FG, BG);

		break;

	case 5:
		bc_printbigchar(Five, X, Y, FG, BG);

		break;

	case 6:
		bc_printbigchar(Six, X, Y, FG, BG);

		break;

	case 7:
		bc_printbigchar(Seven, X, Y, FG, BG);

		break;

	case 8:
		bc_printbigchar(Eight, X, Y, FG, BG);

		break;

	case 9:
		bc_printbigchar(Nine, X, Y, FG, BG);

		break;
	}
}

void print_big_char(int X, int Y, int NUMBER, enum Color FG, enum Color BG) {
	mt_gotoXY(X, Y);

	if (NUMBER < 0) {
		bc_printbigchar(Minus, X, Y, FG, BG);
	}
	else {
		bc_printbigchar(Plus, X, Y, FG, BG);
	}

	X += 8;

	unsigned short int i = 9, n;
	do {
		mt_gotoXY(X, Y);

		n = abs(NUMBER) / (int)pow(10, i) % 10;

		print_simbol(X, Y, n, FG, BG);

		X += 8;

		--i;
	} while (i > 0);

	n = abs(NUMBER) % 10;

	print_simbol(X, Y, n, FG, BG);
}


void sc_interface() {
	int max_rows, max_columns;

	mt_getscreensize(&max_rows, &max_columns);

	bc_box(1, 1, max_columns - 1, 12);
	bc_box(1, 13, 21, 26);
	bc_box(22, 13, max_columns - 1, 22);
	bc_box(22, 23, max_columns - 1, 26);

	mt_gotoXY(2, 14);
	printf("Enter. Set value");
	mt_gotoXY(2, 15);
	printf("l. Load memory");
	mt_gotoXY(2, 16);
	printf("s. Save memory");
	mt_gotoXY(2, 17);
	printf("r. Run");
	mt_gotoXY(2, 18);
	printf("t. Step");
	mt_gotoXY(2, 19);
	printf("i. Reset");
	mt_gotoXY(2, 20);
	printf("F5. Accumulator");
	mt_gotoXY(2, 21);
	printf("F6. Instr Counter");
	mt_gotoXY(2, 22);
	printf("q. Quit");

	mt_gotoXY(0, 27);
	printf("Size of window: %d x %d\n\n\n", max_columns, max_rows);
	printf("Input/Output\n");
}

void instrcnt2xy() {
	x = instructionCounter % 10;
	y = instructionCounter / 10;
}

void info() {
	int flag;

	instrcnt2xy();

	for (unsigned int i = 0; i < MEMORY_SIZE / 10; ++i) {
		mt_gotoXY(2, i + 2);
		for (unsigned int j = 0; j < 10; ++j) {
			mt_setbgcolor(Magneta);
			printf("%3d. ", i * 10 + j);
			mt_setbgcolor(Default);

			if (i == y && j == x) {
				mt_setbgcolor(Green);
				printf("%10d ", sc_memory[i * 10 + j]);
				mt_setbgcolor(Default);
			}
			else {
				printf("%10d ", sc_memory[i * 10 + j]);
			}
		}
	}

	print_big_char(24, 14, sc_memory[x + y * 10], Green, Default);

	mt_gotoXY(23, 24);
	printf("                                                                                ");
	mt_gotoXY(23, 24);

	sc_regGet(FLAG_WRONG_ADDRESS, &flag);

	if (flag) {
		mt_setfgcolor(Red);
		printf("WRONG_ADDRESS ");
		printf("NOT_OK");
	}
	else {
		printf("WRONG_ADDRESS ");

		sc_regGet(FLAG_OPEN_FILE, &flag);

		if (flag) {
			mt_setfgcolor(Red);
			printf("CAN'T_OPEN_FILE ");
			printf("NOT_OK");
		}
		else {
			printf("CAN'T_OPEN_FILE ");

			sc_regGet(FLAG_FILE_SIZE, &flag);

			if (flag) {
				mt_setfgcolor(Red);
				printf("WRONG_FILE_SIZE ");
				printf("NOT_OK");
			}
			else {
				printf("WRONG_FILE_SIZE ");

				sc_regGet(FLAG_IGNORE_SYSTEM_TIMER, &flag);

				if (flag) {
					mt_setfgcolor(Green);
					printf("IGNORE_SYSTEM_TIMER ");
				}
				else {
					mt_setfgcolor(Default);
					printf("NOT_IGNORE_SYSTEM_TIMER ");
				}

				mt_setfgcolor(Green);
				printf("OK");
			}
		}
	}
	mt_setfgcolor(Default);

	mt_gotoXY(0, 28);
	printf("                                                            ");
	mt_gotoXY(0, 28);
	printf("instructionCounter %d | accumulator %d\n", instructionCounter, accumulator);
}

int control() {
	char filename[21] = { "operative_memory.dat" };
	int value, flag;
	enum Key KEY;

	mt_gotoXY(0, 30);
	while (flag) {
		rk_readkey(&KEY);
		flag = 0;

		switch (KEY) {
		case KEY_l:
			sc_memoryLoad(filename);

			break;

		case KEY_s:
			sc_memorySave(filename);

			break;

		case KEY_r:
			sc_regSet(FLAG_IGNORE_SYSTEM_TIMER, 0);

			x = 0;
			y = 0;

			struct itimerval nval;

			nval.it_interval.tv_sec = 0;
			nval.it_interval.tv_usec = 100;
			nval.it_value.tv_sec = 0;
			nval.it_value.tv_usec = 100;

			setitimer(ITIMER_REAL, &nval, NULL);

			break;

		case KEY_t:
			sc_regGet(FLAG_IGNORE_SYSTEM_TIMER, &flag);

			if (flag) {
				sc_regGet(FLAG_HALT, &flag);

				if (flag == 0) {
					CU();

					if (instructionCounter < 99) {
						++instructionCounter;
					}
					else {
						instructionCounter = 99;
						sc_regSet(FLAG_HALT, 1);
					}
				}
			}

			flag = 0;

			break;

		case KEY_i:
			raise(SIGUSR1);

			break;

		case KEY_q:
			return 1;

			break;

		case KEY_f5:
			mt_gotoXY(0, printcount);
			printf("Enter accumulator:");
			scanf("%d", &accumulator);

			break;


		case KEY_f6: //NOT функция варианта 1!!!
			mt_gotoXY(0, printcount);
			mt_setfgcolor(Default);
			mt_setbgcolor(Default);
			printf("Read: ");
			unsigned int operand;
			scanf("%u", &operand);
			++printcount;

			if (operand > 100 || operand < 0) {
			printf("Wrong addres\n");
			++printcount;
			break;
			}
			sc_memorySet(operand, ~accumulator);

			break;

		case KEY_up:
			if (y > 0) {
				--y;
			}

			break;

		case KEY_down:
			if (y < 9) {
				++y;
			}

			break;

		case KEY_left:
			if (x > 0) {
				--x;
			}

			break;

		case KEY_right:
			if (x < 9) {
				++x;
			}

			break;

		case KEY_enter:
			mt_gotoXY(0, printcount);
			printf("Enter value:");
			scanf("%d", &value);

			sc_memorySet(x + y * 10, value);

			break;

		case KEY_other:
			flag = 1;

			break;
		}
	}

	return 0;
}
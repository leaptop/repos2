#include "MySimpleComputer.h"

int sc_memory[MEMORY_SIZE];

int reset() {
	x = 0;
	y = 0;

	mt_clrscr();
	sc_interface();

	sc_memoryInit();
	sc_regInit();
	instructionCounter = 0;
	accumulator = 0;
	printcount = 31;

	return 0;
}

int sc_memoryInit() {
	for (unsigned int i = 0; i < MEMORY_SIZE; ++i) {
		sc_memory[i] = 0;
	}

	return 0;
}

int sc_memorySet(int ADDRESS, int VALUE) {
	if ((ADDRESS < 0) || (ADDRESS >= MEMORY_SIZE)) {
		sc_regSet(FLAG_WRONG_ADDRESS, 1);

		return ERROR;
	}

	sc_memory[ADDRESS] = VALUE;

	return 0;
}

int sc_memoryGet(int ADDRESS, int *VALUE) {
	if ((ADDRESS < 0) || (ADDRESS >= MEMORY_SIZE)) {	
		sc_regSet(FLAG_WRONG_ADDRESS, 1);

		return ERROR;
	}

	*VALUE = sc_memory[ADDRESS];
	
	return 0;
}

int sc_memorySave(char *FILENAME) {
	FILE *file;

	if ((file = fopen(FILENAME, "wb")) == NULL) {
		sc_regSet(FLAG_OPEN_FILE, 1);

		return ERROR;
	}

	if (fwrite(sc_memory, MEMORY_SIZE * sizeof(*sc_memory), 1, file) != 1) {
		fclose(file);

		sc_regSet(FLAG_FILE_SIZE, 1);

		return ERROR;
	}

	fclose(file);

	return 0;
}

int sc_memoryLoad(char *FILENAME) {
	FILE *file;

	if ((file = fopen(FILENAME, "rb")) == NULL) {
		sc_regSet(FLAG_OPEN_FILE, 1);

		return ERROR;
	}

	if (fread(sc_memory, sizeof(*sc_memory) * MEMORY_SIZE, 1, file) != 1) {
		fclose(file);

		sc_regSet(FLAG_FILE_SIZE, 1);

		return ERROR;
	}

	fclose(file);

	return 0;
}

int sc_regInit() {
	sc_reg_flags = FLAG_IGNORE_SYSTEM_TIMER;

	return 0;
}

int sc_regSet(int REGISTER, int VALUE) {
	if ((REGISTER < 0) || (REGISTER > 256)) {
		return ERROR;
	}

	if (VALUE) {
		sc_reg_flags |= REGISTER;
	}
	else {
		sc_reg_flags &= ~REGISTER;
	}

	return 0;
}

int sc_regGet(int REGISTER, int *VALUE) {
	if ((REGISTER < 0) || (REGISTER > 256)) {
		return ERROR;
	}
	
	*VALUE = sc_reg_flags & REGISTER;

	return 0;
}

int command_check(char COMMAND) {
	switch (COMMAND) {
	case 10: /*READ*/
		break;

	case 11: /*WRITE*/
		break;

	case 20: /*LOAD*/
		break;

	case 21: /*STORE*/
		break;

	case 30: /*ADD*/
		break;

	case 31: /*SUB*/
		break;

	case 32: /*DIVIDE*/
		break;

	case 33: /*MUL*/
		break;

	case 40: /*JUMP*/
		break;

	case 41: /*JNEG*/
		break;

	case 42: /*JZ*/
		break;

	case 43: /*HALT*/
		break;

	case 51: /*NOT*/
		break;

	default:
		return ERROR;
		break;
	}

	return 0;
}

int sc_commandEncode(int COMMAND, int OPERAND, int *VALUE) {
	if (OPERAND >= 128 || OPERAND < 0) {
		sc_regSet(FLAG_WRONG_COMMAND, 1);

		return ERROR;
	}

	if (command_check(COMMAND)) {
		sc_regSet(FLAG_WRONG_COMMAND, 1);

		return ERROR;
	}

	*VALUE = COMMAND;
	
	*VALUE <<= 7;
	
	*VALUE |= OPERAND & 127;

	return 0;
}

int sc_commandDecode(int VALUE, int *COMMAND, int *OPERAND) {
	*OPERAND = VALUE & 127;

	if (*OPERAND >= 128 || *OPERAND < 0) {
		sc_regSet(FLAG_WRONG_COMMAND, 1);

		return ERROR;
	}

	VALUE >>= 7;

	*COMMAND = VALUE;

	if (command_check(*COMMAND)) {
		sc_regSet(FLAG_WRONG_COMMAND, 1);

		return ERROR;
	}

	return 0;
}

int ALU(int command, int operand) {
	switch (command) {
	case 30: /* ADD */
		if (sc_memory[operand] > 0) {
			if (accumulator + sc_memory[operand] < 2147483648) {
				accumulator += sc_memory[operand];
			}
			else {
				accumulator = 2147483647;
			}
		}
		else {
			if (accumulator + sc_memory[operand] > -2147483649) {
				accumulator += sc_memory[operand];
			}
			else {
				accumulator = -2147483648;
			}
		}

		sc_regSet(FLAG_PARITY, ~(accumulator & 1));

		break;

	case 31: /* SUB */
		if (sc_memory[operand] > 0) {
			if (accumulator - sc_memory[operand] > -2147483649) {
				accumulator -= sc_memory[operand];
			}
			else {
				accumulator = -2147483648;
			}
		}
		else {
			if (accumulator - sc_memory[operand] < 2147483648) {
				accumulator -= sc_memory[operand];
			}
			else {
				accumulator = 2147483647;
			}
		}

		sc_regSet(FLAG_PARITY, ~(accumulator & 1));

		break;

	case 33: /* MUL */
		if (sc_memory[operand] > 0) {
			if (accumulator > 0) {
				if (accumulator * sc_memory[operand] < 2147483648) {
					accumulator *= sc_memory[operand];
				}
				else {
					accumulator = 2147483647;
				}
			}
			else {
				if (accumulator * sc_memory[operand] > -2147483649) {
					accumulator *= sc_memory[operand];
				}
				else {
					accumulator = -2147483648;
				}
			}
		}
		else {
			if (accumulator > 0) {
				if (accumulator * sc_memory[operand] > -2147483649) {
					accumulator *= sc_memory[operand];
				}
				else {
					accumulator = -2147483648;
				}
			}
			else {
				if (accumulator * sc_memory[operand] < 2147483648) {
					accumulator *= sc_memory[operand];
				}
				else {
					accumulator = 2147483647;
				}
			}
		}

		sc_regSet(FLAG_PARITY, ~(accumulator & 1));

		break;

	case 32: /* DIV */
		if (sc_memory[operand] != 0) {
			accumulator /= sc_memory[operand];

			sc_regSet(FLAG_PARITY, ~(accumulator & 1));
		}
		else {
			sc_regSet(FLAG_WRONG_OPERAND, 1);

			return ERROR;
		}

		break;
	}

	return 0;
}

void CU() {
	int command, operand;
	long long int value;

	if (instructionCounter >= MEMORY_SIZE) {
		sc_regSet(FLAG_WRONG_ADDRESS, 1);
		
		return;
	}

	if (sc_commandDecode(sc_memory[instructionCounter], &command, &operand)) {
		sc_regSet(FLAG_WRONG_COMMAND, 1);
		
		return;
	}

	if ((operand < 0) && (operand >= MEMORY_SIZE)) {
		sc_regSet(FLAG_WRONG_COMMAND, 1);

		return;
	}

	if ((command >= 30) && (command <= 33)) {
		if (ALU(command, operand) != 0) {
			sc_regSet(FLAG_WRONG_COMMAND, 1);
		}
	}
	else {
		switch (command) {
		case 10: /* READ */
			mt_gotoXY(0, printcount);
			mt_setfgcolor(Default);
			mt_setbgcolor(Default);
			printf("Read: ");
			scanf("%lld", &value);
			++printcount;

			if (value > 2147483647 || value < -2147483648) {
				value = 0;
			}

			sc_memorySet(operand, value);

			break;

		case 11: /* WRITE */
			mt_gotoXY(0, printcount);
			mt_setfgcolor(Default);
			mt_setbgcolor(Default);
			printf("Write: %d\n", sc_memory[operand]);
			++printcount;

			break;

		case 20: /* LOAD */
			accumulator = sc_memory[operand];

			break;

		case 21: /* STORE */
			sc_memory[operand] = accumulator;

			break;

		case 40: /* JUMP */
			instructionCounter = operand - 1;

			break;

		case 41: /* JNEG */
			if (accumulator < 0) {
				instructionCounter = operand - 1;
			}

			break;

		case 42: /* JZ */
			if (accumulator == 0) {
				instructionCounter = operand - 1;
			}
			break;

		case 43: /* HALT */
			sc_regSet(FLAG_HALT, 1);
			mt_setfgcolor(Default);
			mt_setbgcolor(Default);
			mt_gotoXY(0, printcount);
			printf("Program is over\n");

			break;

		case 51: /* NOT */
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
		}
	}
}
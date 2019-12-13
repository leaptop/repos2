#include "Asm2Bin.h"

int command_check(char COMMAND) {
	switch (COMMAND) {
	case 10: //READ
		break;

	case 11: //WRITE
		break;

	case 20: //LOAD
		break;

	case 21: //STORE
		break;

	case 30: //ADD
		break;

	case 31: //SUB
		break;

	case 32: //DIVIDE
		break;

	case 33: //MUL
		break;

	case 40: // JUMP
		break;

	case 41: //JNEG 
		break;

	case 42: //JZ
		break;

	case 43: // HALT
		break;

	case 57: // JNC
		break;

	default:
		return 1;
		break;
	}

	return 0;
}

int sc_commandEncode(int COMMAND, int OPERAND, int *VALUE) {
	if (OPERAND >= 128 || OPERAND < 0) {//операнд у нас может быть 7 бит максимум
		return 1;
	}

	if (command_check(COMMAND)) {//ещё проверка команды
		return 1;
	}

	*VALUE = COMMAND;//в VALUE заносим команду

	*VALUE <<= 7;//смещаем биты влево на 7. Командные биты также смещаются

	*VALUE |= OPERAND & 127;//вносим операнд в VALUE. В итоге имеем полноценную  
	//ячейку для оперативки симпл компьютера
	return 0;
}

int str2command(char *str) {
	int result;

	if (strcmp(str, "READ") == 0) {
		result = 10;
	}
	else {
		if (strcmp(str, "WRITE") == 0) {
			result = 11;
		}
		else {
			if (strcmp(str, "LOAD") == 0) {
				result = 20;
			}
			else {
				if (strcmp(str, "STORE") == 0) {
					result = 21;
				}
				else {
					if (strcmp(str, "ADD") == 0) {
						result = 30;
					}
					else {
						if (strcmp(str, "SUB") == 0) {
							result = 31;
						}
						else {
							if (strcmp(str, "DIVIDE") == 0) {
								result = 32;
							}
							else {
								if (strcmp(str, "MUL") == 0) {
									result = 33;
								}
								else {
									if (strcmp(str, "JUMP") == 0) {
										result = 40;
									}
									else {
										if (strcmp(str, "JNEG") == 0) {
											result = 41;
										}
										else {
											if (strcmp(str, "JZ") == 0) {
												result = 42;
											}
											else {
												if (strcmp(str, "HALT") == 0) {
													result = 43;
												}
												else {
													if (strcmp(str, "JNC") == 0) {
														result = 57;
													}
													else {
														result = -1;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	return result;
}

int pars_line(char *str, int *addr, int *value) {//переводим сначала в десятичные строку
	char *ptr;
	int operand, command;
	int flag_assign = 0;

	ptr = strchr(str, ';');//strchr ищет первое вхождение символа в строку
	if (ptr != NULL) {
		*ptr = '\0';
	}
	else {
		ptr = strchr(str, '\n');
		if (ptr != NULL) {
			*ptr = '\0';
		}//заменяем точки с запятой и переносы строки на символ конца строки
	}

	ptr = strtok(str, " \t");//если не нашли ничего в строке, то pars_line завершает работу
	if (ptr == NULL) {
		return 1;
	}

	if (sscanf(ptr, "%d", addr) != 1) {//Если первое слово в строке - не число, то pars_line завершает работу
		return 1;
	}
	if ((*addr < 0) || (*addr >= MEMORY_SIZE)) {//если это число не в отрезке [0,99](размер оперативки)
		//, т.е. пытаются указать на несуществующую ячейку оперативной памяти, то pars_line завершает работу
		return 1;
	}

	ptr = strtok(NULL, " \t");//Ф-ция strtok была запущена в строке 159. Теперь
	if (ptr == NULL) {//для дальнейшего разбора строки нужно указывать NULL как аргумент
		return 1;//Здесь если не нашли больше слов в строке, то pars_line завершает работу
	}//(кроме номера ячейки должны быть уазаны команда и операнд)

	if (strcmp(ptr, "=") == 0) {//если след. слово - "=", то это явное назначение ячейке значения в формате вывода
		ptr = strtok(NULL, " \t");//на экран консоли, например "+1397". Теперь назначим в ptr след. слово,
		*value = atoi(ptr);//которое и есть это новое, назначаемое значение ячейки памяти
		//Ascii TO Integer
		return 0;//в случае "=" это должно быть концном строки, так что pars_line успешно завершает работу
	}
	else {//если это не "=", то это д.б. командой
		command = str2command(ptr);//превращаем  слово в команду: READ - 10, WRITE - 11 и т.д. по заданию
		if (command == -1) {//если слова нет в словаре, то  завершаем функцию с ошибкой
			return 1;
		}
	}

	ptr = strtok(NULL, " \t");//переходим к следующему слову. Это должен быть адрес какой-либо ячейки памяти
	if (ptr == NULL) {
		return 1;
	}

	if (sscanf(ptr, "%d", &operand) != 1) {//если получили не число, то код неправильный. Завершаем с ошибкой
		return 1;
	}

	if ((operand < 0) || (operand >= MEMORY_SIZE)) {//если обращаются за пределы адресов ячеек, 
		return 1;//то завершаем с ошибкой
	}

	ptr = strtok(NULL, " \t");
	if (ptr != NULL) {//если дальше есть что-то ещё, то код ассемблера неверный. Завершаем с ошибкой
		return 1;//конец строки strtok не воспринимает как слово, поэтому наши концы строк им не воспринимаются
	}

	sc_commandEncode(command, operand, value);//если не было "=", то value - просто адрес строки(в ней ничего нет)
	//здесь команду мы уже превратили в 10, 11 или что-то из списка. Операнд тоже считали из строки
	return 0;//здесь в value уже полноценная команда для симпл компьютера
}

int asm2bin(char *filename1, char *filename2) {
	char Str[100];

	int value, addr;
	int sc_memory[MEMORY_SIZE];//создали заготовку оперативки симпл компьютера

	FILE *fin, *fout;

	if ((fin = fopen(filename1, "r")) == NULL) {
		return 1;
	}

	if ((fout = fopen(filename2, "wb")) == NULL) {
		return 1;
	}

	for (int i = 0; i < MEMORY_SIZE; ++i) {//задали всем ячейкам оперативки нулевые значения
		sc_memory[i] = 0;
	}

	while (fgets(Str, 100, fin)) {//прочитали первую строку ассемблерной команды. Здесь они все распарсятся
		if (pars_line(Str, &addr, &value) == 0) {
			sc_memory[addr] = value;//очередная ячейка оперативки получает своё значение
		}
		else {//если команда на ассемблере была кривая, то цикл завершаем
			break;
		}
	}
	
	fwrite(sc_memory, 1, MEMORY_SIZE * sizeof(int), fout);

	fclose(fin);
	fclose(fout);

	return 0;
}
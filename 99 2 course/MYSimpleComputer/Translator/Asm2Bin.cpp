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
	if (OPERAND >= 128 || OPERAND < 0) {//������� � ��� ����� ���� 7 ��� ��������
		return 1;
	}

	if (command_check(COMMAND)) {//��� �������� �������
		return 1;
	}

	*VALUE = COMMAND;//� VALUE ������� �������

	*VALUE <<= 7;//������� ���� ����� �� 7. ��������� ���� ����� ���������

	*VALUE |= OPERAND & 127;//������ ������� � VALUE. � ����� ����� �����������  
	//������ ��� ���������� ����� ����������
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

int pars_line(char *str, int *addr, int *value) {//��������� ������� � ���������� ������
	char *ptr;
	int operand, command;
	int flag_assign = 0;

	ptr = strchr(str, ';');//strchr ���� ������ ��������� ������� � ������
	if (ptr != NULL) {
		*ptr = '\0';
	}
	else {
		ptr = strchr(str, '\n');
		if (ptr != NULL) {
			*ptr = '\0';
		}//�������� ����� � ������� � �������� ������ �� ������ ����� ������
	}

	ptr = strtok(str, " \t");//���� �� ����� ������ � ������, �� pars_line ��������� ������
	if (ptr == NULL) {
		return 1;
	}

	if (sscanf(ptr, "%d", addr) != 1) {//���� ������ ����� � ������ - �� �����, �� pars_line ��������� ������
		return 1;
	}
	if ((*addr < 0) || (*addr >= MEMORY_SIZE)) {//���� ��� ����� �� � ������� [0,99](������ ����������)
		//, �.�. �������� ������� �� �������������� ������ ����������� ������, �� pars_line ��������� ������
		return 1;
	}

	ptr = strtok(NULL, " \t");//�-��� strtok ���� �������� � ������ 159. ������
	if (ptr == NULL) {//��� ����������� ������� ������ ����� ��������� NULL ��� ��������
		return 1;//����� ���� �� ����� ������ ���� � ������, �� pars_line ��������� ������
	}//(����� ������ ������ ������ ���� ������ ������� � �������)

	if (strcmp(ptr, "=") == 0) {//���� ����. ����� - "=", �� ��� ����� ���������� ������ �������� � ������� ������
		ptr = strtok(NULL, " \t");//�� ����� �������, �������� "+1397". ������ �������� � ptr ����. �����,
		*value = atoi(ptr);//������� � ���� ��� �����, ����������� �������� ������ ������
		//Ascii TO Integer
		return 0;//� ������ "=" ��� ������ ���� ������� ������, ��� ��� pars_line ������� ��������� ������
	}
	else {//���� ��� �� "=", �� ��� �.�. ��������
		command = str2command(ptr);//����������  ����� � �������: READ - 10, WRITE - 11 � �.�. �� �������
		if (command == -1) {//���� ����� ��� � �������, ��  ��������� ������� � �������
			return 1;
		}
	}

	ptr = strtok(NULL, " \t");//��������� � ���������� �����. ��� ������ ���� ����� �����-���� ������ ������
	if (ptr == NULL) {
		return 1;
	}

	if (sscanf(ptr, "%d", &operand) != 1) {//���� �������� �� �����, �� ��� ������������. ��������� � �������
		return 1;
	}

	if ((operand < 0) || (operand >= MEMORY_SIZE)) {//���� ���������� �� ������� ������� �����, 
		return 1;//�� ��������� � �������
	}

	ptr = strtok(NULL, " \t");
	if (ptr != NULL) {//���� ������ ���� ���-�� ���, �� ��� ���������� ��������. ��������� � �������
		return 1;//����� ������ strtok �� ������������ ��� �����, ������� ���� ����� ����� �� �� ��������������
	}

	sc_commandEncode(command, operand, value);//���� �� ���� "=", �� value - ������ ����� ������(� ��� ������ ���)
	//����� ������� �� ��� ���������� � 10, 11 ��� ���-�� �� ������. ������� ���� ������� �� ������
	return 0;//����� � value ��� ����������� ������� ��� ����� ����������
}

int asm2bin(char *filename1, char *filename2) {
	char Str[100];

	int value, addr;
	int sc_memory[MEMORY_SIZE];//������� ��������� ���������� ����� ����������

	FILE *fin, *fout;

	if ((fin = fopen(filename1, "r")) == NULL) {
		return 1;
	}

	if ((fout = fopen(filename2, "wb")) == NULL) {
		return 1;
	}

	for (int i = 0; i < MEMORY_SIZE; ++i) {//������ ���� ������� ���������� ������� ��������
		sc_memory[i] = 0;
	}

	while (fgets(Str, 100, fin)) {//��������� ������ ������ ������������ �������. ����� ��� ��� �����������
		if (pars_line(Str, &addr, &value) == 0) {
			sc_memory[addr] = value;//��������� ������ ���������� �������� ��� ��������
		}
		else {//���� ������� �� ���������� ���� ������, �� ���� ���������
			break;
		}
	}
	
	fwrite(sc_memory, 1, MEMORY_SIZE * sizeof(int), fout);

	fclose(fin);
	fclose(fout);

	return 0;
}
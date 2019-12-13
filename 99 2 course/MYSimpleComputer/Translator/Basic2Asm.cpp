#include "Basic2Asm.h"

int chk_command(enum BasicComand *key, char *Comm) {
	if (strcmp(Comm, "REM") == 0) {
		*key = REM;
	}
	else {
		if (strcmp(Comm, "INPUT") == 0) {
			*key = INPUT;
		}
		else {
			if (strcmp(Comm, "PRINT") == 0) {
				*key = PRINT;
			}
			else {
				if (strcmp(Comm, "GOTO") == 0) {
					*key = GOTO;
				}
				else {
					if (strcmp(Comm, "IF") == 0) {
						*key = IF;
					}
					else {
						if (strcmp(Comm, "LET") == 0) {
							*key = LET;
						}
						else {
							if (strcmp(Comm, "END") == 0) {
								*key = END;
							}
							else {
								return -1;
							}
						}
					}
				}
			}
		}
	}

	return 0;
}

int print(FILE *fout, std::list<Variable> varList,
	std::list<Constant> &constList, char *Variables, int *Constants,
	int &StrCounter) {
	int number_buff;
	char *ptr;

	ptr = strtok(NULL, " \t");//HTTP://CPPSTUDIO.COM/POST/747/ ������ 
	//���� �� ���������� �� ��������� ������ � ���������� ��������� �� ����, 
	//� ����� ����� ����� �������� ��������� ������, �� �������� ���� ������ ��������� ������
	if (ptr == NULL) {//���� ������� NULL, �� ��� � ����� � �������� ������� �������
		return 1;
	}

	if (is_var(*ptr)) {//���������, �������� �� ��� ����� �� ���� �� A �� Z//���� ��������, �� is_var ���������� 1, ���� true
		if (!chk_var(*ptr, varList)) {//�������� �� ������� � varList ���� ����������
			return 1;
		}

		Variables[StrCounter] = *ptr;//���� ���������� ���� ��� � varList, �� ������� ������� � � Variables
		//� VARIABLES ������� CHAR � ������ ��������������� ������ �� ������� ���� 
		//���������� ���� ���������� � �� ����� ���� ��� ���������� � VARLIST ��� ���
	}
	else {//���� ��� �� �������� ����� �� ���� �� A �� Z
		if (sscanf(ptr, "%d", &number_buff) != 1) {//���� ���������� ����� � ptr �� ����� 1, �� print() ��������� ������
			return 1;//����� �� �������� ������� ���������� ���
		}

		if (!chk_const(number_buff, constList)) {//���������, ���� �� ����� number_buff � ���������� constList
			add_const(number_buff, constList);//���� ����� ��� � constList, �� ��������� ���
		}

		Constants[StrCounter] = number_buff;//���������� �� �� �����  � ������ ��������
	}

	fprintf(fout, "%d WRITE  \n", StrCounter);//� ������������ ���� ����� ����� ������ StrCounter, ����� WRITE, ������, ������ �������� ������
	++StrCounter;//�������������� ���������� ����� ����� ������������� �����

	return 0;
}

int input(FILE *fout, std::list<Variable> &varList, char *Variables, int &StrCounter) {
	char *ptr;

	ptr = strtok(NULL, " \t");// ��� ������ ������� ����� A
	if (ptr == NULL) {
		return 1;
	}

	if (!chk_var(*ptr, varList)) {
		add_var(*ptr, varList);
	}

	Variables[StrCounter] = *ptr;// ������� ���������� *ptr � Variables.
	//��� �������� ��������� ��� ��� ��� ��� ��������

	fprintf(fout, "%d READ  \n", StrCounter);
	++StrCounter;

	return 0;
}

int let(FILE *fout, std::list<Variable> &varList,
	std::list<Constant> &constList, int *Constants, char *Variables,
	int &StrCounter, int &max_tmp_num) {
	char* ptr;
	char rpn_str[100];// ������ � ������� ����� �������� ���������� �������� �������� ������ ��� ������ ��������� ���������� � LET
					  

	ptr = strtok(NULL, " \t");
	if (ptr == NULL) {
		return 1;
	}

	if (!chk_var(*ptr, varList)) {
		add_var(*ptr, varList);
	}

	if (rpn(rpn_str, constList)) {//��� ������������ ����� rpn()
		return 1;
	}

	if (rpn_pars(fout, Constants, Variables, StrCounter, rpn_str, max_tmp_num)) {
		return 1;
	}

	fprintf(fout, "%d STORE  \n", StrCounter);
	Variables[StrCounter] = *ptr;
	++StrCounter;
	//for (int i = 0; i < 40; i++)printf("%c", rpn_str[i]); printf("\n");
	return 0;
}

int go_to(FILE *fout, std::list<Address> &addrList, int &StrCounter) {
	int number_buff;
	char *ptr;

	ptr = strtok(NULL, " \t");
	if (ptr == NULL) {
		return 1;
	}

	if (sscanf(ptr, "%d", &number_buff) != 1) {//� number_buff ����������� �����(��� �� �����, �-���
		return 1;//������ ����� ������� GOTO �� �������)
	}

	add_addr(number_buff, StrCounter, addrList);//number_buff ���������� ����� Addr ���������� ������� 
	//� ������ addrList. � ����� ������ Addr ������������� ������ �� �������, � str_num-� ������������� ������ 
	fprintf(fout, "%d JUMP  \n", StrCounter);//�� ����������
	++StrCounter;

	return 0;
}

void add_var(char variable, std::list<Variable> &varList) {//������ ��������� ����� ��������� � ������ ����������
	Variable buff;
	buff.Var = variable;

	varList.push_back(buff);
}

void add_const(int Const, std::list<Constant> &constList) {//������ ��������� ����� ����������
	Constant buff;
	buff.Const = Const;

	constList.push_back(buff);
}

void add_addr(int Addr, int str_num, std::list<Address> &addrList) {//����� ���� ������������ ����� ������
	Address buff;//
	buff.Addr = Addr;//������ �� �������(���� ��������� GOTO)
	buff.str_num = str_num;//������ �� ����������

	addrList.push_back(buff);
}

int chk_var(int Var, std::list<Variable> varList) {//���������, ���� �� ����������(� ���� ������� Var)� �����  
	for (auto &element : varList) {//�� �������� varList
		if (element.Var == Var) {//���� ����, �� chk_var ���������� 1
			return 1;
		}
	}

	return 0;
}

int chk_const(int Const, std::list<Constant> constList) {//���������, ���� �� ����� number_buff �  
	for (auto &element : constList) {//���������� constList
		if (element.Const == Const) {
			return 1;//���� ����, ���������� 1
		}
	}
	
	return 0;
}

int is_var(char simbol) {//���������, �������� �� ��� ����� �� ���� �� A �� Z
	if (simbol >= 'A' && simbol <= 'Z') {
		return 1;//���� ��������, �� ���������� 1, ���� true
	}

	return 0;
}

int get_prior(char c) {// ��� ����������� ���������� ��������, ����� � �������� ��������
	
	switch (c) {
	case '*':
		return 3;
	case '/':
		return 3;
	case '-':
		return 2;
	case '+':
		return 2;
	case '(':
		return 1;
	}

	return 0;
}

int rpn(char *rpn_str, std::list<Constant> &constList) {
	int str_pos = 0, rpn_pos = 0, number_buff;
	char *ptr;

	std::stack<char> rpn_stack;//���� ��� ������ � ���. ������. �������

	ptr = strtok(NULL, " \t");
	if (ptr == NULL) {
		return 1;
	}

	while (ptr = strtok(NULL, " \t")) {//������ ������ ���� ��� �� ����������(�� ����� ������� �� ���)
		if (*ptr == ')') {//���� ����� �� ����������� ������
			while (rpn_stack.top() != '(') {//����������� �� �� ����� �� ����������� ������
				rpn_str[rpn_pos++] = rpn_stack.top();//����������� � ��� ������ �������� � �������� ��� �����
				rpn_str[rpn_pos++] = ' ';//���������� � ��� ������ ������
				rpn_stack.pop();//������� �������� �����
			}
			rpn_stack.pop();//������� �������� ����� (���� ����������� ������)
		}
		else {
			if (is_var(*ptr)) {//�����, ���� ptr - ����������//���������� ����� ������� � ������
				rpn_str[rpn_pos++] = *ptr;//����������� � � ��� ������
				rpn_str[rpn_pos++] = ' ';//����������� ������ � ��� ������
			}
			else {
				if (*ptr == '(') {//�����, ���� ptr - ����������� ������
					rpn_stack.push('(');//���������� � � ����
				}
				else {//�����, ���� ��� �������������� �����
					if (*ptr == '+' || *ptr == '-' || *ptr == '/' || *ptr == '*') {
						if (rpn_stack.empty()) {//� ���� ���� ������
							rpn_stack.push(*ptr);//����� ���� ptr(����� ����)
						}
						else {//���� �� ������, get_prior ���������� ���������� ����� ��������
							//(����� rpn_stack.top() - ����� ��������) ����� ������� ��������� - 3.
							if (get_prior(rpn_stack.top()) < get_prior(*ptr) || rpn_stack.top() == '(') {
								// ���� ��������� ������� ����� ������ ���������� ptr ��� ������� ����� - ����������� ������
								rpn_stack.push(*ptr);//, �� � ������� ����� ������������� ptr 
							}
							else {//����� ���� ���� �� ������ � ��������� ������� >= ���������� ptr
								while (!rpn_stack.empty() && (get_prior(rpn_stack.top()) >= get_prior(*ptr))) {
									rpn_str[rpn_pos++] = rpn_stack.top();//� rpn_str ����������� ������� ����� 
									rpn_str[rpn_pos++] = ' ';//��������� ��������
									rpn_stack.pop();//������� ������� �����
								}
								rpn_stack.push(*ptr);//����������� ptr �� �������
							}
						}
					}//�����, ���� ��� �� �������������� �����, ��
					else {
						if (sscanf(ptr, "%d", &number_buff) != 1) {
							// ���� SSCANF �� ������ ������� ����� ����� ��������� ������
							return 1;
						}

						if (!chk_const(number_buff, constList)) {
							add_const(number_buff, constList);
						}

						while (*ptr != '\0' && *ptr != '\n') {//���������� �� �� ptr � rpn_str �� ����� ����� ������ ��� ������
							rpn_str[rpn_pos++] = *ptr;
							//STRTOK ����� ���� ��� �������� ������ ��� ������ ��� ��������� ������ 
							//�� ��� ����� ���� ��������� ������
							++ptr;
						}

						rpn_str[rpn_pos++] = ' ';//� ����� ����������� ������ � rpn_str.
						//����� ���������� � ������ ���������
					}
				}
			}
		}
	}
	//����� ���� ������� ����� ������� � ������
	while (!rpn_stack.empty()) {//������������ �� �� ����� � rpn_str
		rpn_str[rpn_pos++] = rpn_stack.top();
		rpn_str[rpn_pos++] = ' ';
		rpn_stack.pop();//������� ����
	}

	rpn_str[rpn_pos] = '\0';
	//�� ������������� ������� ��������� � �������� ��������, ��� ���� ����� ��������� �� 
	//������ � ���� �������� ����������� ���������� � ���������� �����������
	// HTTPS://HABR.COM/RU/POST/282379/
	return 0;
}

int rpn_pars(FILE *fout, int *Constants, char *Variables, int &StrCounter,
	//�� �������� �������� ������ � ������ �� �� ������ �� ����� ���������� � ���� � ������������ 
	//����� ������� ��� ����� ���������� ��������� �������������� ��������
	char *rpn, int &max_tmp_num) {
	char *ptr;
	int tmp_num = 0;
	int buff_number;
	bool is_accum_full = false;

	struct operand {
		bool is_var;

		union {
			char variable;
			int constant;
		};
	};
	operand buff, second_operand;//��������� ��� ��������� ���� operand

	std::stack<operand> rpn_stack;//������ ���� ���������

	ptr = strtok(rpn, " \t");//��������� ������ �������(����� ��������, ��������� �� ������ �������� ��� ����������)
	if (ptr == NULL) {
		return 1;
	}

	if (is_var(*ptr)) {//���� ������� ���������
		buff.is_var = true;//� ��������� buff �������� is_var ������ true
		buff.variable = *ptr;//������� ��� ���� ���������� � variable ���������
		rpn_stack.push(buff);//������� ��������� buff � ������ ��������
	}
	else {//���� ��� ���� �� ����������
		if (sscanf(ptr, "%d", &buff_number) != 1) {//���� �� ������ ������� ����� � ptr �� ��������� �-��� � �������
			return 1;//��������, ��� ���, ����� ����, ���������
		}

		buff.is_var = false;//������� buff ������ ������� �� ����������
		buff.constant = buff_number;//� �������������� ����������
		rpn_stack.push(buff);//������� ��������� � ����
	}

	while (ptr = strtok(NULL, " \t")) {//��������� ��������� �������
		if (ptr == NULL) {
			break;
		}
		
		if (is_var(*ptr)) {//���� ����������, �� ����� � ����
			buff.is_var = true;
			buff.variable = *ptr;
			rpn_stack.push(buff);//�� �� �� �����, ��� � �� �����
		}
		else {//�����, ���� �����. ������
			if ((*ptr == '+') || (*ptr == '-') || (*ptr == '*') || (*ptr == '/')) {
				if (is_accum_full) {//���� � ������������ ���� ������
					if ((*ptr == '-' || *ptr == '/')) {
						//��� ��� �� �������� ���� ������� � ���������� ����� ���-�� ����������, 
						//�� ��� �������� ��������� �����������
						fprintf(fout, "%d STORE  \n", StrCounter);//�����: ��������� ��-�� �� ����� � ������ StrCounter
						Variables[StrCounter] = tmp_num;//� ������ StrCounter ������ ������ �� tmp_num... � ��� ���� �������
						++StrCounter;

						if (rpn_stack.top().is_var) {//���� �� ������� ����� ����������
							second_operand.variable = rpn_stack.top().variable;//������ � � second_operand
							second_operand.is_var = true;//����������, ��� ��� ����������
						}
						else {//����� ���� ������
							second_operand.constant = rpn_stack.top().constant;//������ �� ���� ��� � �������� int, � �� char
							second_operand.is_var = false;//����������, ��� ��� ���������
						}

						rpn_stack.pop();//���������� ������� �����

						fprintf(fout, "%d LOAD  \n", StrCounter);//����� � ����: StrCounter ��������� � ����������...

						if (rpn_stack.top().is_var) {//...
							Variables[StrCounter] = rpn_stack.top().variable;
						}
						else {
							Constants[StrCounter] = rpn_stack.top().constant;
						}

						++StrCounter;
					}
					else {//���� ��� �������� � ���������, �� � ��� ��������� ����� ����
						rpn_stack.pop();

						if (rpn_stack.top().is_var) {
							second_operand.variable = rpn_stack.top().variable;
							second_operand.is_var = true;
						}
						else {
							second_operand.constant = rpn_stack.top().constant;
							second_operand.is_var = false;
						}
					}
				}
				else {//���� ������ � ����������� ���, �� ��� ������ ���������
					if (rpn_stack.top().is_var) {
						second_operand.variable = rpn_stack.top().variable;
						second_operand.is_var = true;
					}
					else {
						second_operand.constant = rpn_stack.top().constant;
						second_operand.is_var = false;
					}

					rpn_stack.pop();

					is_accum_full = true;
					fprintf(fout, "%d LOAD  \n", StrCounter);

					if (rpn_stack.top().is_var) {
						Variables[StrCounter] = rpn_stack.top().variable;
					}
					else {
						Constants[StrCounter] = rpn_stack.top().constant;
					}

					++StrCounter;
				}

				rpn_stack.pop();

				tmp_num = rpn_stack.size() - 2;

				if (tmp_num > max_tmp_num) {
					max_tmp_num = tmp_num;
				}

				switch (*ptr) {//��� ���-�� �� � ����� ������� � ������������ ���
				case '+':
					fprintf(fout, "%d ADD  \n", StrCounter);
					break;

				case '-':					
					fprintf(fout, "%d SUB  \n", StrCounter);
					break;

				case '/':					
					fprintf(fout, "%d DIVIDE  \n", StrCounter);
					break;

				case '*':					
					fprintf(fout, "%d MUL  \n", StrCounter);
					break;
				}

				if (second_operand.is_var) {
					Variables[StrCounter] = second_operand.variable;
				}
				else {
					Constants[StrCounter] = second_operand.constant;
				}
				
				++StrCounter;
				
				buff.variable = tmp_num;
				buff.is_var = true;

				rpn_stack.push(buff);
			}
			else {//���� ���������, �� ����� � ����
				if (sscanf(ptr, "%d", &buff_number) != 1) {
					return 1;
				}

				buff.constant = buff_number;
				buff.is_var = false;

				rpn_stack.push(buff);
			}
		}
	}

	if (!is_accum_full) {
		fprintf(fout, "%d LOAD  \n", StrCounter);

		if (rpn_stack.top().is_var) {
			Variables[StrCounter] = rpn_stack.top().variable;
		}
		else {
			Constants[StrCounter] = rpn_stack.top().constant;
		}

		++StrCounter;
		rpn_stack.pop();
	}

	return 0;
}

void initialization(FILE *fout, std::list<Variable> &varList,
	//����� ��������� ������ ������ � ������� ����������� ������ � ���� �� ���������� ��� ���� ������ ������ ������
	std::list<Constant> &constList, int max_tmp_num, int &StrCounter) {
	for (auto &element : constList) {
		//���� �� ������������ ��������� � ���������, �� �� ������� ��� ��� ����� � ����� �� ������� ���� �� �������� 
		fprintf(fout, "%d = %d\n", StrCounter, element.Const);//16 = 1
		element.str_num = StrCounter;
		++StrCounter;
	}

	for (auto &element : varList) {
		element.str_num = StrCounter;
		++StrCounter;
	}

	for (int i = 0; i <= max_tmp_num; ++i) {
		add_var(i, varList);
		varList.back().str_num = StrCounter;
		++StrCounter;
	}
}

void linking(std::list<Link> &lnkList, std::list<Variable> varList,
	//������� ��������� ������ ������ � ����� ������ ���� ��������� � �����-�� ������, 
	//���� ������ ����� ����������� ��� ������ ������� � ������ � ������ ������� �����
	std::list<Constant> constList, std::list<Address> addrList,
	char *Variables, int *Constants, int *Bas_str_nums) {
	int i;
	
	Link buff;

	for (auto &element : varList) {
		buff.Lnk = element.str_num;

		for (i = 0; i < 100; ++i) {
			if (element.Var == Variables[i]) {
				buff.str_num = i;
				lnkList.push_back(buff);
			}
		}
	}

	for (auto &element : constList) {
		buff.Lnk = element.str_num;

		for (i = 0; i < 100; ++i) {
			if (element.Const == Constants[i]) {
				buff.str_num = i;
				lnkList.push_back(buff);
			}
		}
	}

	for (auto &element : addrList) {
		buff.str_num = element.str_num;

		for (i = 0; i < 100; ++i) {
			if (element.Addr == Bas_str_nums[i]) {
				buff.Lnk = i;
				lnkList.push_back(buff);
			}
		}
	}
}

void second_run(FILE *fout, std::list<Link> &lnkList) {
	//������ � ������ ��� ���������� � ������� ������ ������� ���� �����
	int StrCounter = -1;
	char link[2];//����� ��� �������������� ������ ������ � �����
	char Str[100];//������ ��� ���������� ������


	std::list<Link>::iterator it = lnkList.begin();

	while (fgets(Str, 100, fout) && it != lnkList.end()) {
		++StrCounter;

		if (StrCounter == it->str_num) {
			fseek(fout, -3, SEEK_CUR);//SEEK_CUR ���� ���� ��� �������� ���������� �� ������� ������� �������

			link[0] = (it->Lnk / 10) + '0';//����� ������ ������ ������ ��������,
			link[1] = (it->Lnk % 10) + '0';//����� ������

			fprintf(fout, "%c", link[0]);
			fprintf(fout, "%c", link[1]);
			fseek(fout, 1, SEEK_CUR);//����� 1 - ������� �������(0 ���� �� ������ �����, 2 - ����� �����) 
			//������� ������������� ��������� ��������� � �����, ��������� � fout

			++it;
		}
	}
}

bool lnk_sort_pred(Link FIRST, Link SECOND) {//���������� ��������� ��������� str_num � ���� ���������� Link
	return FIRST.str_num < SECOND.str_num;//���� ������ ������, �� true
}

int basic2asm(char *filename1, char *filename2) {
	int StrCounter = 0;//StrCounter ���������� ����� ��������� �� ����������
	int ifjmp = -1; //��� ������������� IF ����� ��� ������������ ������� ������������� 
	//������� ��������� � IF, ��� ��� �� �� ����� ����� ������� ����� ������ ��� ������ �������, 
	//�� �� ����� ������ ������ ��� ��������� ������ ������ �������
	int Bas_str_nums[100];// ����� �� ��������� �� �������, ������ ��, ������� ���������� ������ �����
	int Constants[100];//��� ���������� �������� �
	//������������ ����, ��������� ��� � ����������  ������ ��������� � 
	//������, ����, �������� CONSTANTS[1] = 1, �� �� ������ ������ ���������� � ��������� 1, 
	//��������� ����� ���� ������ ��������������
	int basic_str_num; // ���������� ��� ��� ������ �����, 
	//������������ ������ � ��������� �� �������
	int i;
	int number_buff;//������ ��� ���������� ����� �� ������, ��� ���������� ��������
	int max_tmp_num = 0;//������������ ���������� �������������� �� 
	//��� ����� ��� �������� ��������� ��������, ����� �������� ��� ��� ������
	char Str[100], *ptr;//������ ������ ����� � ��������� �� ���. � Str ����������� ���� ������ �� ��������� �� �������
	char Variables[100];//������ ������� ���������� � ��������������� �������, 
	//���� ������ �������� ' ', �� � ���� ������ � ��������� �� ����������
	

	std::list<Variable> varList;//struct Variable {char Var; int str_num;};//������ �������� ��� �������� ����� ���������� � � ��������
	std::list<Constant> constList;//struct Constant {int Const;	int str_num;};//������ �������� ��� �������� �������� � �� ��������
	std::list<Address> addrList;//struct Address {int Addr;	int str_num;};//������������� ������ ������ � ������� � ����������
	

	std::list<Link> lnkList;/*struct Link {	int str_num;	int Lnk;};*/
	//������ ����� � ����� � ������� ���������� � ���� �������, ��������� � ������������ ��� ��� ������ �������

	FILE* fin;//����, �� �������� ���� ��� �� ������
	FILE* fout;//����, � ������� ����� ������� ��� �� ����������

	enum BasicComand Comm;//��������� ��� �������� ������ �����, �-��� ��� ����� �� ������ /*INPUT,PRINT,LET,IF,GOTO,REM,END*/

	if ((fin = fopen(filename1, "r")) == NULL) {//���� ������ �� ����������� ��� ������, ���������� 1, � ���� �����������, �� ��������� fin ��� ���
		return 1;
	}

	if ((fout = fopen(filename2, "w+")) == NULL) {//���� ��������� �� ����������� ��� ������, ���������� 1
		return 1;
	}

	for (i = 0; i < 100; ++i) {
		Variables[i] = ' ';//���� ���������� ����������� �������� �������
	}

	for (i = 0; i < 100; ++i) {
		Constants[i] = -1;//��������� ����� ���� ������ �������������, ������� ������������ -1 ��� ������� ���������� ��������
	}
//Str ��� ������ ���������� - 10 INPUT A, ptr - "10", ��� ������ ��������� ������ �� �������, ptr = "20"
	while (fgets(Str, 100, fin)) {//��������� 100-1 �������� �� ����� fin, � �������� �� � ������ ��������, �� ������� ��������� Str. ������� ����������� �� ��� ���, ���� �� ���������� ������ "����� ������", EOF ��� �� ���������� ���������� �������
		ptr = strtok(Str, " \t\n");//��������� ptr �������� ��������� �� ������ ������ Str//STRTOK 
		//���������� ��������� �� ������ ������ �� �������� ��� ��� �������� � ����� ����� ��������� ������ ������ 
		//��������� ������ �� ������ ������� ���������� ��� ��� ��������
		if (ptr == NULL) {//���� ptr == NULL �� �������� ��������� ����
			continue;
		}

		if (sscanf(ptr, "%d", &basic_str_num) != 1) {//�� ptr ��������� ���������� ����� � &basic_str_num
			return 1;//���� �� ������ ������� �����, ������� basic2asm ����������� ������
		}

		Bas_str_nums[StrCounter] = basic_str_num;//������ ����� �� ��������� �� ������� ������� � ������
		//����� � ������� ����� basic_str_num(������ ������ �� �������) ���������� ������������ ������ �� ����������
		//� ���� ������� ���� ������ �� ����������(StrCounter)
		if (ifjmp != -1) {
			add_addr(basic_str_num, ifjmp, addrList);//��������� ������ ������ �� �������-������ �� ����������

			ifjmp = -1;
		}

		ptr = strtok(NULL, " \t");
		if (ptr == NULL) {
			return 1;
		}

		chk_command(&Comm, ptr);//��������� enum � ptr. ���� ������ ���������(���� ����� enum, ������������, 
		//��� ���������� ����� ptr), �� �� enum ���������� ���, ��� �������� ��������� � ptr

		switch (Comm) {//������ ��� ������ � ���������� ��������
		case REM:
		{
			continue;
		}
		break;

		case PRINT:
		{
			if (print(fout, varList, constList, Variables, Constants,//����������� � ������������ ���� 
				StrCounter)) {// ����� ������, WRITE, ������, \n. ������� ��������� varList, constList, ������� ���� ��������
				return 1;
			}
		}
		break;

		case INPUT:
		{//����� � ������������ ����: ����� ������������ ������, READ, ������, \n
			if (input(fout, varList, Variables, StrCounter)) {
				return 1;
			}
		}
		break;

		case LET:
		{
			if (let(fout, varList, constList, Constants, Variables,
				StrCounter, max_tmp_num)) {
				return 1;
			}
		}
		break;

		case END:
		{
			fprintf(fout, "%d HALT 00\n", StrCounter);
			++StrCounter;
		}
		break;

		case GOTO:
		{
			if (go_to(fout, addrList, StrCounter)) {
				return 1;
			}
		}
		break;

		case IF:
		{
			ptr = strtok(NULL, " \t");
			if (ptr == NULL) {
				return 1;
			}
			char *first_var = ptr;

			ptr = strtok(NULL, " \t");
			if (ptr == NULL) {
				return 1;
			}

			switch (*ptr) {//����� ���� ��� ��������� ������ ������-������-����� 
			case '<':
			{
				ptr = strtok(NULL, " \t");
				if (ptr == NULL) {
					return 1;
				}

				if (is_var(*ptr)) {
					if (!chk_var(*ptr, varList)) {
						return 1;
					}

					Variables[StrCounter] = *ptr;
				}
				else {
					if (sscanf(ptr, "%d", &number_buff) != 1) {
						return 1;
					}

					if (!chk_const(number_buff, constList)) {
						add_const(number_buff, constList);
					}

					Constants[StrCounter] = number_buff;
				}

				fprintf(fout, "%d LOAD  \n", StrCounter);
				++StrCounter;

				if (is_var(*first_var)) {
					if (!chk_var(*first_var, varList)) {
						return 1;
					}

					Variables[StrCounter] = *first_var;
				}
				else {
					if (sscanf(first_var, "%d", &number_buff) != 1) {
						return 1;
					}

					if (!chk_const(number_buff, constList)) {
						add_const(number_buff, constList);
					}

					Constants[StrCounter] = number_buff;
				}

				fprintf(fout, "%d SUB  \n", StrCounter);
				++StrCounter;

				if (!chk_const(1, constList)) {
					add_const(1, constList);
				}

				Constants[StrCounter] = 1;

				fprintf(fout, "%d SUB  \n", StrCounter);
				++StrCounter;

				ifjmp = StrCounter;//��� ������

				fprintf(fout, "%d JNEG  \n", StrCounter);//���� ������� ��������������(���� SF) ����������, 
				++StrCounter;//�� ��������� �� ������ StrCounter
			}
			break;

			case '>':
			{
				if (is_var(*first_var)) {
					if (!chk_var(*first_var, varList)) {
						return 1;
					}

					Variables[StrCounter] = *first_var;
				}
				else {
					if (sscanf(first_var, "%d", &number_buff) != 1) {
						return 1;
					}
					
					if (!chk_const(number_buff, constList)) {
						add_const(number_buff, constList);
					}

					Constants[StrCounter] = number_buff;
				}

				fprintf(fout, "%d LOAD  \n", StrCounter);
				++StrCounter;

				ptr = strtok(NULL, " \t");
				if (ptr == NULL) {
					return 1;
				}

				if (is_var(*ptr)) {
					if (!chk_var(*ptr, varList)) {
						return 1;
					}

					Variables[StrCounter] = *ptr;
				}
				else {
					if (sscanf(ptr, "%d", &number_buff) != 1) {
						return 1;
					}
					
					if (!chk_const(number_buff, constList)) {
						add_const(number_buff, constList);
					}

					Constants[StrCounter] = number_buff;
				}

				fprintf(fout, "%d SUB  \n", StrCounter);
				++StrCounter;

				if (!chk_const(1, constList)) {
					add_const(1, constList);
				}

				Constants[StrCounter] = 1;

				fprintf(fout, "%d SUB  \n", StrCounter);
				++StrCounter;

				ifjmp = StrCounter;

				fprintf(fout, "%d JNEG  \n", StrCounter);
				++StrCounter;
			}
			break;

			case '=':
			{
				if (is_var(*first_var)) {
					if (!chk_var(*first_var, varList)) {
						return 1;
					}

					Variables[StrCounter] = *first_var;
				}
				else {
					if (sscanf(first_var, "%d", &number_buff) != 1) {
						return 1;
					}

					if (!chk_const(number_buff, constList)) {
						add_const(number_buff, constList);
					}

					Constants[StrCounter] = number_buff;
				}

				fprintf(fout, "%d LOAD  \n", StrCounter);
				++StrCounter;

				ptr = strtok(NULL, " \t");
				if (ptr == NULL) {
					return 1;
				}

				if (is_var(*ptr)) {
					if (!chk_var(*ptr, varList)) {
						return 1;
					}

					Variables[StrCounter] = *ptr;
				}
				else {
					if (sscanf(ptr, "%d", &number_buff) != 1) {
						return 1;
					}

					if (!chk_const(number_buff, constList)) {
						add_const(number_buff, constList);
					}

					Constants[StrCounter] = number_buff;
				}

				fprintf(fout, "%d SUB  \n", StrCounter);
				++StrCounter;

				fprintf(fout, "%d JZ %d\n", StrCounter, StrCounter + 2);
				++StrCounter;

				ifjmp = StrCounter;

				fprintf(fout, "%d JUMP  \n", StrCounter);
				++StrCounter;
			}
			break;

			}

			ptr = strtok(NULL, " \t");
			if (ptr == NULL) {
				return 1;
			}

			chk_command(&Comm, ptr);

			switch (Comm) {//��� ���� ���� ��� ������� ����, ��� ������ ����������� � ����������� �� ���������� �������� IF
			case PRINT:
			{
				if (print(fout, varList, constList, Variables, Constants,
					StrCounter)) {
					return 1;
				}
			}
			break;

			case INPUT:
			{
				if (input(fout, varList, Variables, StrCounter)) {
					return 1;
				}
			}
			break;

			case LET:
			{
				if (let(fout, varList, constList, Constants, Variables,
					StrCounter, max_tmp_num)) {
					return 1;
				}
			}
			break;

			case END:
			{
				fprintf(fout, "%d HALT 00\n", StrCounter);
				++StrCounter;
			}
			break;

			case GOTO:
			{
				if (go_to(fout, addrList, StrCounter)) {
					return 1;
				}
			}
			break;

			}
		}
		break;

		}
		
	}
	
		
	initialization(fout, varList, constList, max_tmp_num, StrCounter);

	if (StrCounter >= 100) {//���� ����� ����� ������������ ��������� ������ ���, �� ��������� basic2asm
		return 1;
	}

	fclose(fin);
	rewind(fout);//���������� ��������� ��������� � ����� �� ������ ���������� ������

	linking(lnkList, varList, constList, addrList, Variables, Constants, Bas_str_nums);//�������� ������ �� ������� ���� ������-����� ������
	
	lnkList.sort(lnk_sort_pred); //(sort - ���������� ������� list-�)//���������� �� ������� ������

	second_run(fout, lnkList);//������ ������� ����� � ������ ������� ���������� � ����������, ���������� ��� �������  

	fclose(fout);

	return 0;
}
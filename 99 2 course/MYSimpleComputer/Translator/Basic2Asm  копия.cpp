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

	ptr = strtok(NULL, " \t");//что здесь происходит?
	if (ptr == NULL) {//и здесь?
		return 1;
	}

	if (is_var(*ptr)) {//проверяет, является ли чар одной из букв от A до Z//если является, то is_var возвращает 1, типа true
		if (!chk_var(*ptr, varList)) {//проверка на наличие в varList этой переменной
			return 1;
		}

		Variables[StrCounter] = *ptr;//если переменной пока нет в varList, то сначала заносим её в Variables
	}
	else {//если чар не является одной из букв от A до Z
		if (sscanf(ptr, "%d", &number_buff) != 1) {//если количество чисел в ptr не равно 1, то print() завершает работу
			return 1;
		}

		if (!chk_const(number_buff, constList)) {//проверяет, есть ли число number_buff в структурах constList
			add_const(number_buff, constList);//если числа нет в constList, то добавляем его
		}

		Constants[StrCounter] = number_buff;//записываем то же число  в список констант
	}

	fprintf(fout, "%d WRITE  \n", StrCounter);//в ассемблерный файл пишем номер строки StrCounter, слово WRITE, пробел, символ переноса строки
	++StrCounter;//инкрементируем переменную числа строк ассемблерного файла

	return 0;
}

int input(FILE *fout, std::list<Variable> &varList, char *Variables, int &StrCounter) {
	char *ptr;

	ptr = strtok(NULL, " \t");
	if (ptr == NULL) {
		return 1;
	}

	if (!chk_var(*ptr, varList)) {
		add_var(*ptr, varList);
	}

	Variables[StrCounter] = *ptr;// заносим переменную *ptr в Variables. Она полюбому заносится, т.к. INPUT это подразумевает

	fprintf(fout, "%d READ  \n", StrCounter);
	++StrCounter;

	return 0;
}

int let(FILE *fout, std::list<Variable> &varList,
	std::list<Constant> &constList, int *Constants, char *Variables,
	int &StrCounter, int &max_tmp_num) {
	char* ptr;
	char rpn_str[100];//что это? Строка обратной польской записи для одной какой-то строчки? Какой? Только той, где LET?

	ptr = strtok(NULL, " \t");
	if (ptr == NULL) {
		return 1;
	}

	if (!chk_var(*ptr, varList)) {
		add_var(*ptr, varList);
	}

	if (rpn(rpn_str, constList)) {
		return 1;
	}

	if (rpn_pars(fout, Constants, Variables, StrCounter, rpn_str, max_tmp_num)) {
		return 1;
	}

	fprintf(fout, "%d STORE  \n", StrCounter);
	Variables[StrCounter] = *ptr;
	++StrCounter;

	return 0;
}

int go_to(FILE *fout, std::list<Address> &addrList, int &StrCounter) {
	int number_buff;
	char *ptr;

	ptr = strtok(NULL, " \t");
	if (ptr == NULL) {
		return 1;
	}

	if (sscanf(ptr, "%d", &number_buff) != 1) {
		return 1;
	}

	add_addr(number_buff, StrCounter, addrList);

	fprintf(fout, "%d JUMP  \n", StrCounter);
	++StrCounter;

	return 0;
}

void add_var(char variable, std::list<Variable> &varList) {//просто добавляем новую перменную?
	Variable buff;
	buff.Var = variable;

	varList.push_back(buff);
}

void add_const(int Const, std::list<Constant> &constList) {//просто добавляем новую структурку
	Constant buff;
	buff.Const = Const;

	constList.push_back(buff);
}

void add_addr(int Addr, int str_num, std::list<Address> &addrList) {//для чего эта функция?
	Address buff;
	buff.Addr = Addr;
	buff.str_num = str_num;

	addrList.push_back(buff);
}

int chk_var(int Var, std::list<Variable> varList) {//проверяет, есть ли переменная(с аски номером Var)в одной  
	for (auto &element : varList) {//из структур varList
		if (element.Var == Var) {//если есть, то chk_var возвращает 1
			return 1;
		}
	}

	return 0;
}

int chk_const(int Const, std::list<Constant> constList) {//проверяет, есть ли число number_buff в  
	for (auto &element : constList) {//структурах constList
		if (element.Const == Const) {
			return 1;//если есть, возвращает 1
		}
	}

	return 0;
}

int is_var(char simbol) {//проверяет, является ли чар одной из букв от A до Z
	if (simbol >= 'A' && simbol <= 'Z') {
		return 1;//если является, то возвращаем 1, типа true
	}

	return 0;
}

int get_prior(char c) {//для чего это?
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

	std::stack<char> rpn_stack;//тот самый стек для работы с обр. польск. записью?

	ptr = strtok(NULL, " \t");
	if (ptr == NULL) {
		return 1;
	}

	while (ptr = strtok(NULL, " \t")) {//в нашем бейсике ведь нет скобок... Зачем тогда эта проверка?
		if (*ptr == ')') {//если дошли до закрывающей скобки
			while (rpn_stack.top() != '(') {//вытаскиваем всё из стека до открывающей скобки
				rpn_str[rpn_pos++] = rpn_stack.top();//прописываем в рпн строку значение с верхушки рпн стека
				rpn_str[rpn_pos++] = ' ';//прописывем в рпн строку пробел
				rpn_stack.pop();//удаляем верхушку стека
			}
			rpn_stack.pop();//удаляем верхушку стека (саму закрывающую скобку)
		}
		else {
			if (is_var(*ptr)) {//иначе, если ptr - переменная
				rpn_str[rpn_pos++] = *ptr;//прописываем её в рпн строку
				rpn_str[rpn_pos++] = ' ';//прописываем пробел в рпн строку
			}
			else {
				if (*ptr == '(') {//иначе, если ptr - открывающая скобка
					rpn_stack.push('(');//засовываем её в стек
				}
				else {//иначе, если это арифметические знаки
					if (*ptr == '+' || *ptr == '-' || *ptr == '/' || *ptr == '*') {
						if (rpn_stack.empty()) {//и если стек пустой
							rpn_stack.push(*ptr);//пишем туда ptr
						}
						else {//если не пустой, get_prior определяет приоритеты арифм операций(здесь rpn_stack.top() - арифм операция) самый высокий приоритет - 3.
							if (get_prior(rpn_stack.top()) < get_prior(*ptr) || rpn_stack.top() == '(') {// если приоритет вершины стека меньше приоритета ptr или вершина стека - открывающая скобка
								rpn_stack.push(*ptr);//, то в вершину стека устанавливаем ptr 
							}
							else {//иначе пока стек не пустой и приортиет вершины >= приоритета ptr
								while (!rpn_stack.empty() && (get_prior(rpn_stack.top()) >= get_prior(*ptr))) {
									rpn_str[rpn_pos++] = rpn_stack.top();//в rpn_str прописываем вершину стека 
									rpn_str[rpn_pos++] = ' ';//доплоняем пробелом
									rpn_stack.pop();//удаляем вершину стека
								}
								rpn_stack.push(*ptr);//прописываем ptr на вершину
							}
						}
					}//иначе, если это не арифметические знаки, то
					else {
						if (sscanf(ptr, "%d", &number_buff) != 1) {//если ptr - не одно число, то rpn завершает работу???
							return 1;
						}

						if (!chk_const(number_buff, constList)) {
							add_const(number_buff, constList);
						}

						while (*ptr != '\0' && *ptr != '\n') {//записываем всё из ptr в rpn_str до знака конца строки или абзаца
							rpn_str[rpn_pos++] = *ptr;//а что здесь осталось в итоге для добавления?
							++ptr;
						}

						rpn_str[rpn_pos++] = ' ';//в конце приписываем пробел в rpn_str. Что мы имеем к этому моменту?
					}
				}
			}
		}
	}

	while (!rpn_stack.empty()) {//переписываем всё из стека в rpn_str
		rpn_str[rpn_pos++] = rpn_stack.top();
		rpn_str[rpn_pos++] = ' ';
		rpn_stack.pop();
	}

	rpn_str[rpn_pos] = '\0';
	//где мы находимся и что сделали в итоге? Я имею ввиду, что хочу понять, как вообще эта 
	//польская запись реализована и почему я не вижу глобальной какой-то переменной для 
	//всей строки польской записи. Пока я тренировался только в тетради, и хочу понять, как это сделано здесь.
	//у меня ведь могут это спросить, как польская запись реализована, в каком порядке, что происходит?
	return 0;
}

int rpn_pars(FILE *fout, int *Constants, char *Variables, int &StrCounter,//что здесь происходит?
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
	operand buff, second_operand;

	std::stack<operand> rpn_stack;

	ptr = strtok(rpn, " \t");
	if (ptr == NULL) {
		return 1;
	}

	if (is_var(*ptr)) {
		buff.is_var = true;
		buff.variable = *ptr;
		rpn_stack.push(buff);
	}
	else {
		if (sscanf(ptr, "%d", &buff_number) != 1) {
			return 1;
		}

		buff.is_var = false;
		buff.constant = buff_number;
		rpn_stack.push(buff);
	}

	while (ptr = strtok(NULL, " \t")) {
		if (ptr == NULL) {
			break;
		}
		
		if (is_var(*ptr)) {
			buff.is_var = true;
			buff.variable = *ptr;
			rpn_stack.push(buff);
		}
		else {
			if ((*ptr == '+') || (*ptr == '-') || (*ptr == '*') || (*ptr == '/')) {
				if (is_accum_full) {
					if ((*ptr == '-' || *ptr == '/')) {
						fprintf(fout, "%d STORE  \n", StrCounter);
						Variables[StrCounter] = tmp_num;
						++StrCounter;

						if (rpn_stack.top().is_var) {
							second_operand.variable = rpn_stack.top().variable;
							second_operand.is_var = true;
						}
						else {
							second_operand.constant = rpn_stack.top().constant;
							second_operand.is_var = false;
						}

						rpn_stack.pop();

						fprintf(fout, "%d LOAD  \n", StrCounter);

						if (rpn_stack.top().is_var) {
							Variables[StrCounter] = rpn_stack.top().variable;
						}
						else {
							Constants[StrCounter] = rpn_stack.top().constant;
						}

						++StrCounter;
					}
					else {
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
				else {
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

				switch (*ptr) {
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
			else {
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

void initialization(FILE *fout, std::list<Variable> &varList,//что здесь происходит?
	std::list<Constant> &constList, int max_tmp_num, int &StrCounter) {
	for (auto &element : constList) {
		fprintf(fout, "%d = %d\n", StrCounter, element.Const);
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

void linking(std::list<Link> &lnkList, std::list<Variable> varList,//что здесь происходит?
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

void second_run(FILE *fout, std::list<Link> &lnkList) {//что здесь происходит?
	int StrCounter = -1;
	char link[2];//что это?
	char Str[100];//что это?

	std::list<Link>::iterator it = lnkList.begin();

	while (fgets(Str, 100, fout) && it != lnkList.end()) {
		++StrCounter;

		if (StrCounter == it->str_num) {
			fseek(fout, -3, SEEK_CUR);

			link[0] = (it->Lnk / 10) + '0';
			link[1] = (it->Lnk % 10) + '0';

			fprintf(fout, "%c", link[0]);
			fprintf(fout, "%c", link[1]);
			fseek(fout, 1, SEEK_CUR);

			++it;
		}
	}
}

bool lnk_sort_pred(Link FIRST, Link SECOND) {//возвращает результат сравнения str_num в двух структурах Link
	return FIRST.str_num < SECOND.str_num;//если первый меньше, то true
}

int basic2asm(char *filename1, char *filename2) {
	int StrCounter = 0;//StrCounter количество строк программы на ассемблере?
	int ifjmp = -1; //ifjmp - что это?
	int Bas_str_nums[100];// Числа из программы на бейсике? да, Именно те, которые обозначают номера строк
	int Constants[100];//что это? Значения констант? Зачем они нам?
	int basic_str_num; //число строк программы на бейсике? Нет. Похоже это переменная для тех первых чисел, обозначающих строки в программе на бейсике
	int i;//что это?
	int number_buff;//что это?
	int max_tmp_num = 0;//что это?
	char Str[100], *ptr;//просто массив чаров и указатель на чар. В Str считывается одна строка из программы на бейсике
	char Variables[100];//Массив для имён переменных? Походу да

	std::list<Variable> varList;//struct Variable {char Var; int str_num;};//Список структур для хранения имени переменной и её значения
	std::list<Constant> constList;//struct Constant {int Const;	int str_num;};//список структур для хранения констант и их значений
	std::list<Address> addrList;//struct Address {int Addr;	int str_num;};//Что это за адреса? список структур для хранения адресов. 
	std::list<Link> lnkList;/*struct Link {	int str_num;	int Lnk;};*///Что это?

	FILE* fin;//файл, из которого берём код на бейсик
	FILE* fout;//файл, в который будет записан код на ассемблере

	enum BasicComand Comm;//перменная для хранения одного энама, к-рый явл одной из команд /*INPUT,PRINT,LET,IF,GOTO,REM,END*/

	if ((fin = fopen(filename1, "r")) == NULL) {//если бейсик не открывается для чтения, возвращаем 1, а если открывается, то назначаем fin его имя
		return 1;
	}

	if ((fout = fopen(filename2, "w+")) == NULL) {//если ассемблер не открывается для записи, возвращаем 1
		return 1;
	}

	for (i = 0; i < 100; ++i) {
		Variables[i] = ' ';//всем переменным присваиваем значение пробела
	}

	for (i = 0; i < 100; ++i) {
		Constants[i] = -1;//это зачем?
	}
//Str при первом считывании - 10 INPUT A
	while (fgets(Str, 100, fin)) {//считываем 100-1 символов из файла fin, и помещаем их в массив символов, на который указывает Str. Символы считываются до тех пор, пока не встретится символ "новая строка", EOF или до достижения указанного предела
		ptr = strtok(Str, " \t\n");//указатель ptr начинает указывать на первый символ Str...Что здесь происходит?
		if (ptr == NULL) {//если ptr == NULL то начинаем следующий цикл
			continue;
		}

		if (sscanf(ptr, "%d", &basic_str_num) != 1) {//из ptr считываем десятичное число в &basic_str_num
			return 1;//если не смогли считать число, функция basic2asm заканчивает работу
		}

		Bas_str_nums[StrCounter] = basic_str_num;//первое чсило из программы на бейсике заносим в массив

		if (ifjmp != -1) {
			add_addr(basic_str_num, ifjmp, addrList);//что эта функция делает?

			ifjmp = -1;
		}

		ptr = strtok(NULL, " \t");//что здесь происходит?
		if (ptr == NULL) {//что здесь происходит?
			return 1;
		}

		chk_command(&Comm, ptr);//сравнение enum и ptr. Если строки совпадают(есть такой enum, записываемый, 
		//как полученный ранее ptr), то из enum выбирается тот, чьё название освпадает с ptr

		switch (Comm) {//думаем что делать с полученной командой
		case REM://почему пропускаем?
		{
			continue;
		}
		break;

		case PRINT:
		{
			if (print(fout, varList, constList, Variables, Constants,//прописываем в ассемблерный файл 
				StrCounter)) {// номер строки, WRITE, пробел, \n. Попутно проверяем varList, constList, заносим туда значения
				return 1;
			}
		}
		break;

		case INPUT:
		{//пишем в ассемблерный файл: Номер ассемблерной строки, READ, пробел, \n
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
			fprintf(fout, "%d HALT 00\n", StrCounter);//зачем два нуля?
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

			switch (*ptr) {//новый свич для обработки знаков больше-меньше-равно 
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

				ifjmp = StrCounter;

				fprintf(fout, "%d JNEG  \n", StrCounter);
				++StrCounter;
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

			ptr = strtok(NULL, " \t");//типа переключение на слеующую подстроку? Чем она тогда определяется? Пробелом и табуляцией одновременно?
			if (ptr == NULL) {
				return 1;//типа если конец файла, то завершение функции??
			}

			chk_command(&Comm, ptr);

			switch (Comm) {//ещё один свич для разбора того, что должно происходить в зависимости от результата проверки IF
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

	if (StrCounter >= 100) {//если число строк ассемблерной программы больше ста, то завершаем basic2asm
		return 1;
	}

	fclose(fin);
	rewind(fout);//перемещает указатель положения в файле на начало указанного потока

	linking(lnkList, varList, constList, addrList, Variables, Constants, Bas_str_nums);//что здесь происходит?

	lnkList.sort(lnk_sort_pred); //(sort - встроенная функция list-а) что тут сортируется?

	second_run(fout, lnkList);//здесь во втором проходе чт-то ещё происходит. Что?

	fclose(fout);

	return 0;
}
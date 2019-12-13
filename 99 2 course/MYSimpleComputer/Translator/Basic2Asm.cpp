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

	ptr = strtok(NULL, " \t");//HTTP://CPPSTUDIO.COM/POST/747/ ЧИТАЕТ 
	//ПОКА НЕ ВСТРЕТИТСЯ НЕ УКАЗАННЫЙ СИМВОЛ И ВОЗВРАЩАЕТ УКАЗАТЕЛЬ НА НЕГО, 
	//И КОГДА ПОСЛЕ ЭТОГО ВСТРЕТИТ УКАЗАННЫЙ СИМВОЛ, ТО ПОСТАВИТ ТУДА СИМВОЛ ОКОНЧАНИЯ СТРОКИ
	if (ptr == NULL) {//ЕСЛИ ВЕРНУЛО NULL, ТО КОД В ФАЙЛЕ С БЕЙСИКОМ НАПИСАН НЕВЕРНО
		return 1;
	}

	if (is_var(*ptr)) {//проверяет, является ли чар одной из букв от A до Z//если является, то is_var возвращает 1, типа true
		if (!chk_var(*ptr, varList)) {//проверка на наличие в varList этой переменной
			return 1;
		}

		Variables[StrCounter] = *ptr;//если переменной пока нет в varList, то сначала заносим её в Variables
		//В VARIABLES ПИШЕТСЯ CHAR В ЯЧЕЙКУ СООТВЕТСТВУЮЩЕЙ СТРОКЕ НА КОТОРОЙ БЫЛО 
		//УПОМИНАНИЕ ЭТОЙ ПЕРЕМЕННОЙ И НЕ ВАЖНО ЕСТЬ ЭТА ПЕРЕМЕННАЯ В VARLIST ИЛИ НЕТ
	}
	else {//если чар не является одной из букв от A до Z
		if (sscanf(ptr, "%d", &number_buff) != 1) {//если количество чисел в ptr не равно 1, то print() завершает работу
			return 1;//ОПЯТЬ ЖЕ ОЗНАЧАЕТ НЕВЕРНО НАПИСАННЫЙ КОД
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

	ptr = strtok(NULL, " \t");// При первом проходе здесь A
	if (ptr == NULL) {
		return 1;
	}

	if (!chk_var(*ptr, varList)) {
		add_var(*ptr, varList);
	}

	Variables[StrCounter] = *ptr;// заносим переменную *ptr в Variables.
	//ОНА ПОЛЮБОМУ ЗАНОСИТСЯ ТАК КАК ОНА ТАМ НАПИСАНА

	fprintf(fout, "%d READ  \n", StrCounter);
	++StrCounter;

	return 0;
}

int let(FILE *fout, std::list<Variable> &varList,
	std::list<Constant> &constList, int *Constants, char *Variables,
	int &StrCounter, int &max_tmp_num) {
	char* ptr;
	char rpn_str[100];// СТРОКА В КОТОРОЙ БУДЕТ ХРАНИТСЯ ПОЛУЧЕННАЯ ОБРАТНАЯ ПОЛЬСКАЯ ЗАПИСЬ ДЛЯ СТРОКИ ВЫРАЖЕНИЯ НАПИСАННОЙ В LET
					  

	ptr = strtok(NULL, " \t");
	if (ptr == NULL) {
		return 1;
	}

	if (!chk_var(*ptr, varList)) {
		add_var(*ptr, varList);
	}

	if (rpn(rpn_str, constList)) {//это единственный вызов rpn()
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

	if (sscanf(ptr, "%d", &number_buff) != 1) {//в number_buff назначается число(это то число, к-рое
		return 1;//стояло после команды GOTO на бейсике)
	}

	add_addr(number_buff, StrCounter, addrList);//number_buff становится полем Addr струтктуры адресов 
	//в списке addrList. В итоге номеру Addr соответствует строка на бейсике, а str_num-у соовтетствует строка 
	fprintf(fout, "%d JUMP  \n", StrCounter);//на ассемблере
	++StrCounter;

	return 0;
}

void add_var(char variable, std::list<Variable> &varList) {//просто добавляем новую перменную В СПИСОК ПЕРЕМЕННЫХ
	Variable buff;
	buff.Var = variable;

	varList.push_back(buff);
}

void add_const(int Const, std::list<Constant> &constList) {//просто добавляем новую структурку
	Constant buff;
	buff.Const = Const;

	constList.push_back(buff);
}

void add_addr(int Addr, int str_num, std::list<Address> &addrList) {//здесь тупо объединяются номер строки
	Address buff;//
	buff.Addr = Addr;//строка на бейсике(куда направлял GOTO)
	buff.str_num = str_num;//строка на ассемблере

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

int get_prior(char c) {// ДЛЯ ОПРЕДЕЛЕНИЯ ПРИОРИТЕТА ОПЕРАЦИИ, НУЖНО В ОБРАТНОЙ ПОЛЬСКОЙ
	
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

	std::stack<char> rpn_stack;//стек для работы с обр. польск. записью

	ptr = strtok(NULL, " \t");
	if (ptr == NULL) {
		return 1;
	}

	while (ptr = strtok(NULL, " \t")) {//ЧИТАЕМ СТРОКУ ПОКА ОНА НЕ ЗАКОНЧИТСЯ(по одной лексеме за раз)
		if (*ptr == ')') {//если дошли до закрывающей скобки
			while (rpn_stack.top() != '(') {//вытаскиваем всё из стека до открывающей скобки
				rpn_str[rpn_pos++] = rpn_stack.top();//прописываем в рпн строку значение с верхушки рпн стека
				rpn_str[rpn_pos++] = ' ';//прописывем в рпн строку пробел
				rpn_stack.pop();//удаляем верхушку стека
			}
			rpn_stack.pop();//удаляем верхушку стека (саму ОТКРЫВАЮЩУЮ скобку)
		}
		else {
			if (is_var(*ptr)) {//иначе, если ptr - переменная//ПЕРЕМЕННЫЕ СРАЗУ ПИШУТСЯ В СТРОКУ
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
							rpn_stack.push(*ptr);//пишем туда ptr(арифм знак)
						}
						else {//если не пустой, get_prior определяет приоритеты арифм операций
							//(здесь rpn_stack.top() - арифм операция) самый высокий приоритет - 3.
							if (get_prior(rpn_stack.top()) < get_prior(*ptr) || rpn_stack.top() == '(') {
								// если приоритет вершины стека меньше приоритета ptr или вершина стека - открывающая скобка
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
						if (sscanf(ptr, "%d", &number_buff) != 1) {
							// ЕСЛИ SSCANF НЕ СМОЖЕТ СЧИТАТЬ ЧИСЛО ТОГДА ЗАВЕРШАЕТ РАБОТУ
							return 1;
						}

						if (!chk_const(number_buff, constList)) {
							add_const(number_buff, constList);
						}

						while (*ptr != '\0' && *ptr != '\n') {//записываем всё из ptr в rpn_str до знака конца строки или абзаца
							rpn_str[rpn_pos++] = *ptr;
							//STRTOK ПОСЛЕ ТОГО КАК ВСТРЕТИЛ ВТОРОЙ РАЗ ПРОБЕЛ ИЛИ ТАБУЛЯЦИЮ СТАВИТ 
							//НА ЭТО МЕСТО ЗНАК ОКОНЧАНИЯ СТРОКИ
							++ptr;
						}

						rpn_str[rpn_pos++] = ' ';//в конце приписываем пробел в rpn_str.
						//ИМЕЕМ ЗАПИСАННУЮ В СТРОКУ КОНСТАНТУ
					}
				}
			}
		}
	}
	//ПОСЛЕ ВЕСЬ ОСТАТОК СТЕКА ПИШЕТСЯ В СТРОКУ
	while (!rpn_stack.empty()) {//переписываем всё из стека в rpn_str
		rpn_str[rpn_pos++] = rpn_stack.top();
		rpn_str[rpn_pos++] = ' ';
		rpn_stack.pop();//очищаем стек
	}

	rpn_str[rpn_pos] = '\0';
	//МЫ ПРЕОБРАЗОВАЛИ ОБЫЧНОЕ ВЫРАЖЕНИЕ В ОБРАТНУЮ ПОЛЬСКУЮ, ЭТО НАДО ЧТОБЫ ИЗБАВИТСЯ ОТ 
	//СКОБОК И БЫЛО ВОЗМОЖНО РЕАЛИЗОВАТЬ ВЫЧИСЛЕНИЯ С ВРЕМЕННЫМИ ПЕРЕМЕННЫМИ
	// HTTPS://HABR.COM/RU/POST/282379/
	return 0;
}

int rpn_pars(FILE *fout, int *Constants, char *Variables, int &StrCounter,
	//МЫ ПОЛУЧИЛИ ПОЛЬСКУЮ ЗАПИСЬ И ТЕПЕРЬ НА ЕЕ ОСНОВЕ МЫ БУДЕМ ЗАПИСЫВАТЬ В ФАЙЛ С АССЕМБЛЕРНЫМ 
	//КОДОМ КОМАНДЫ ТАК ЧТОБЫ СОХРАНЯЛСЯ ПРИОРИТЕТ АРИФМЕТИЧЕСКИХ ОПЕРАЦИЙ
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
	operand buff, second_operand;//объявляем две структуры типа operand

	std::stack<operand> rpn_stack;//создаём стек операндов

	ptr = strtok(rpn, " \t");//считываем первую лексему(набор символов, отделённый от других пробелом или табуляцией)
	if (ptr == NULL) {
		return 1;
	}

	if (is_var(*ptr)) {//если считали перемнную
		buff.is_var = true;//в структуре buff значение is_var делаем true
		buff.variable = *ptr;//заносим имя этой переменной в variable структуры
		rpn_stack.push(buff);//заносим структуру buff в список структур
	}
	else {//если это была не переменная
		if (sscanf(ptr, "%d", &buff_number) != 1) {//если не смогли считать число в ptr то завершаем ф-цию с ошибкой
			return 1;//проверка, что это, может быть, константа
		}

		buff.is_var = false;//операнд buff теперь считаем не переменной
		buff.constant = buff_number;//а соответственно константой
		rpn_stack.push(buff);//заносим структуру в стек
	}

	while (ptr = strtok(NULL, " \t")) {//считываем следующую лексему
		if (ptr == NULL) {
			break;
		}
		
		if (is_var(*ptr)) {//ЕСЛИ ПЕРЕМЕННАЯ, ТО ПИШЕМ В СТЕК
			buff.is_var = true;
			buff.variable = *ptr;
			rpn_stack.push(buff);//всё то же самое, что и до этого
		}
		else {//иначе, если арифм. символ
			if ((*ptr == '+') || (*ptr == '-') || (*ptr == '*') || (*ptr == '/')) {
				if (is_accum_full) {//ЕСЛИ В АККУМУЛЯТОРЕ ЕСТЬ ДАННЫЕ
					if ((*ptr == '-' || *ptr == '/')) {
						//ТАК КАК ОТ ПЕРЕМЕНЫ МЕСТ ДЕЛИМЫХ И ВЫЧИТАЕМЫХ МОЖЕТ ЧТО-ТО ПОМЕНЯТЬСЯ, 
						//ТО НАМ ПРИДЕТСЯ ВЫГРУЗИТЬ АККУМУЛЯТОР
						fprintf(fout, "%d STORE  \n", StrCounter);//пишем: выгрузить зн-ие из акума в ячейку StrCounter
						Variables[StrCounter] = tmp_num;//в ячейке StrCounter теперь ссылка на tmp_num... а это ноль вначале
						++StrCounter;

						if (rpn_stack.top().is_var) {//если на вершине стека переменная
							second_operand.variable = rpn_stack.top().variable;//пихаем её в second_operand
							second_operand.is_var = true;//обозначаем, что это переменная
						}
						else {//иначе тоже пихаем
							second_operand.constant = rpn_stack.top().constant;//только на этот раз в значение int, а не char
							second_operand.is_var = false;//обозначаем, что это константа
						}

						rpn_stack.pop();//выкидываем вершину стека

						fprintf(fout, "%d LOAD  \n", StrCounter);//пишем в файл: StrCounter загрузить в акумулятор...

						if (rpn_stack.top().is_var) {//...
							Variables[StrCounter] = rpn_stack.top().variable;
						}
						else {
							Constants[StrCounter] = rpn_stack.top().constant;
						}

						++StrCounter;
					}
					else {//ЕСЛИ ЭТО СЛОЖЕНИЕ И УМНОЖЕНИЕ, ТО И ТАК РЕЗУЛЬТАТ БУДЕТ ОДИН
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
				else {//ЕСЛИ ДАННЫХ В АККУУЛЯТОРЕ НЕТ, ТО ЭТО НАЧАЛО ВЫРАЖЕНИЯ
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

				switch (*ptr) {//ВОТ ТУТ-ТО МЫ И ПИШЕМ КОМАНДЫ В АССЕМБЛЕРНЫЙ КОД
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
			else {//ЕСЛИ КОНСТАНТА, ТО ПИШЕМ В СТЕК
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
	//СИМПЛ КОМПЬЮТЕР ХРАНИТ ДАННЫЕ В МАССИВЕ ОПЕРАТИВНОЙ ПАМЯТИ И НАДО БЫ ОЗАБОТИТСЯ ЧТО ЭТОЙ ПАМЯТИ ВООБЩЕ ХВАТИТ
	std::list<Constant> &constList, int max_tmp_num, int &StrCounter) {
	for (auto &element : constList) {
		//ЕСЛИ МЫ ИСПОЛЬЗОВАЛИ КОНСТАНТЫ В ПРОГРАММЕ, ТО МЫ ВЫДЕЛИМ ПОД НИХ МЕСТО И СРАЗУ ЖЕ ЗАПИШЕМ ТУДА ИХ ЗНАЧЕНИЕ 
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
	//ФУНКЦИЯ ФОРМИРУЕТ СПИСОК СВЯЗЕЙ В КАКОЙ СТРОКЕ БЫЛО ОБРАЩЕНИЕ К ТАКОЙ-ТО ЯЧЕЙКЕ, 
	//ЭТОТ СПИСОК БУДЕТ ИСПОЛЬЗОВАН ПРИ ВТОРОМ ПРОХОДЕ И ЗАПИСИ В СТРОКИ НОМЕРОВ ЯЧЕЕК
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
	//ЗАПИСЬ В СТРОКИ ГДЕ ОБРАЩАЛИСЬ К ЯЧЕЙКАМ ПАМЯТИ АДРЕСОВ ЭТИХ ЯЧЕЕК
	int StrCounter = -1;
	char link[2];//БУФЕР ДЛЯ ПРЕОБРАЗОВАНИЯ НОМЕРА ЯЧЕЙКИ В ТЕКСТ
	char Str[100];//БУФФЕР ДЛЯ СЧИТЫВАНИЯ СТРОКИ


	std::list<Link>::iterator it = lnkList.begin();

	while (fgets(Str, 100, fout) && it != lnkList.end()) {
		++StrCounter;

		if (StrCounter == it->str_num) {
			fseek(fout, -3, SEEK_CUR);//SEEK_CUR ФЛАГ ТОГО ЧТО СМЕЩЕНИЕ ПРОИСХОДИТ ОТ ТЕКУЩИЙ ПОЗИЦИИ КАРЕТКИ

			link[0] = (it->Lnk / 10) + '0';//здесь сачала второй разряд получаем,
			link[1] = (it->Lnk % 10) + '0';//потом первый

			fprintf(fout, "%c", link[0]);
			fprintf(fout, "%c", link[1]);
			fseek(fout, 1, SEEK_CUR);//здесь 1 - текущая позиция(0 было бы начало файла, 2 - конец файла) 
			//Функция устанавливает указатель положения в файле, связанном с fout

			++it;
		}
	}
}

bool lnk_sort_pred(Link FIRST, Link SECOND) {//возвращает результат сравнения str_num в двух структурах Link
	return FIRST.str_num < SECOND.str_num;//если первый меньше, то true
}

int basic2asm(char *filename1, char *filename2) {
	int StrCounter = 0;//StrCounter количество строк программы на ассемблере
	int ifjmp = -1; //ПРИ ИСПОЛЬЗОВАНИИ IF НУЖНО ПРИ НЕИСПОЛНЕНИИ УСЛОВИЯ ПЕРЕПРЫГИВАТЬ 
	//КОМАНДУ УКАЗАННУЮ В IF, ТАК КАК МЫ НЕ МОЖЕМ ЗНАТЬ СКОЛЬКО СТРОК ЗАЙМЕТ ЭТО СТРОКА ЗАРАНЕЕ, 
	//ТО МЫ ПИШЕМ АДРЕСС ПРЫЖКА ПРИ СЛЕДУЮЩЕМ ЧТЕНИИ СТРОКИ БЕЙСИКА
	int Bas_str_nums[100];// Числа из программы на бейсике, именно те, которые обозначают номера строк
	int Constants[100];//ЭТО УПОМИНАНИЯ КОНСТАНТ В
	//АССЕМБЛЕРНОМ КОДЕ, КОНСТАНТЫ КАК И ПЕРЕМЕННЫЕ  ДОЛЖНЫ ХРАНИТЬСЯ В 
	//ПАМЯТИ, ЕСЛИ, НАПРИМЕР CONSTANTS[1] = 1, ТО ВО ВТОРОЙ СТРОКЕ ОБРАТИЛИСЬ К КОНСТАНТЕ 1, 
	//КОНСТАНТЫ МОГУТ БЫТЬ ТОЛЬКО ПОЛОЖИТЕЛЬНЫМИ
	int basic_str_num; // переменная для тех первых чисел, 
	//обозначающих строки в программе на бейсике
	int i;
	int number_buff;//БУФФЕР ДЛЯ СЧИТЫВАНИЯ ЧИСЛА ИЗ СТРОКИ, ДЛЯ СЧИТЫВАНИЯ КОНСТАНТ
	int max_tmp_num = 0;//МАКСИМАЛЬНОЕ КОЛИЧЕСТВО ИСПОЛЬЗОВАННЫХ ЗА 
	//РАЗ ЯЧЕЕК ДЛЯ ХРАНЕНИЯ ВРЕМЕННЫХ ЗНАЧЕНИЙ, НУЖНО ВЫДЕЛИТЬ ПОД НИХ ПАМЯТЬ
	char Str[100], *ptr;//просто массив чаров и указатель на чар. В Str считывается одна строка из программы на бейсике
	char Variables[100];//МАССИВ ВЫЗОВОВ ПЕРЕМЕННЫХ В СООТВЕТСТВУЮЩИХ СТРОКАХ, 
	//ЕСЛИ ХРАНИТ ЗНАЧЕНИЕ ' ', ТО В ЭТОЙ СТРОКЕ К ПЕРЕЕННЫМ НЕ ОБРАЩАЛИСЬ
	

	std::list<Variable> varList;//struct Variable {char Var; int str_num;};//Список структур для хранения имени переменной и её значения
	std::list<Constant> constList;//struct Constant {int Const;	int str_num;};//список структур для хранения констант и их значений
	std::list<Address> addrList;//struct Address {int Addr;	int str_num;};//СОПОСТАВЛЕНИЕ НОМЕРА СТРОКИ В БЕЙСИКЕ И АССЕМБЛЕРЕ
	

	std::list<Link> lnkList;/*struct Link {	int str_num;	int Lnk;};*/
	//СПИСОК СТРОК И ЯЧЕЕК К КОТОРЫМ ОБРАЩАЛИСЬ В ЭТИХ СТРОКАХ, ЗАПИШУТСЯ В АССЕМБЛЕРНЫЙ КОД ПРИ ВТОРОМ ПРОХОДЕ

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
		Constants[i] = -1;//КОНСТАНТЫ МОГУТ БЫТЬ ТОЛЬКО ПОЛОЖИТЕЛЬНЫЕ, ПОЭТОМУ ИСПОЛЬЗУЕТСЯ -1 КАК ПРИЗНАК ОТСУТСТВИЯ ЗНАЧЕНИЯ
	}
//Str при первом считывании - 10 INPUT A, ptr - "10", При втором следующая строка на бейсике, ptr = "20"
	while (fgets(Str, 100, fin)) {//считываем 100-1 символов из файла fin, и помещаем их в массив символов, на который указывает Str. Символы считываются до тех пор, пока не встретится символ "новая строка", EOF или до достижения указанного предела
		ptr = strtok(Str, " \t\n");//указатель ptr начинает указывать на первый символ Str//STRTOK 
		//ВОЗВРАЩАЕТ УКАЗАТЕЛЬ НА ПЕРВЫЙ СИМВОЛ НЕ УКАЗАННЫ КАК ЕГО ПАРАМЕТР И ПОСЛЕ ЭТОГО УКАЗАТЕЛЯ СТАВИТ СИМВОЛ 
		//ОКОНЧАНИЯ СТРОКИ НА ПЕРВОМ СИМВОЛЕ ПЕРЕДАННОМ ЕМУ КАК ПАРАМЕТР
		if (ptr == NULL) {//если ptr == NULL то начинаем следующий цикл
			continue;
		}

		if (sscanf(ptr, "%d", &basic_str_num) != 1) {//из ptr считываем десятичное число в &basic_str_num
			return 1;//если не смогли считать число, функция basic2asm заканчивает работу
		}

		Bas_str_nums[StrCounter] = basic_str_num;//первое чсило из программы на бейсике заносим в массив
		//здесь у каждого числа basic_str_num(номера строки на бейсике) появляется соотвтетсвие строке на Ассемблере
		//в виде индекса этой строки на ассемблере(StrCounter)
		if (ifjmp != -1) {
			add_addr(basic_str_num, ifjmp, addrList);//ДОБАВЛЯЕТ СВЯЗКУ СТРОКА НА БЕЙСИКЕ-СТРОКА НА АССЕМБЛЕРЕ

			ifjmp = -1;
		}

		ptr = strtok(NULL, " \t");
		if (ptr == NULL) {
			return 1;
		}

		chk_command(&Comm, ptr);//сравнение enum и ptr. Если строки совпадают(есть такой enum, записываемый, 
		//как полученный ранее ptr), то из enum выбирается тот, чьё название освпадает с ptr

		switch (Comm) {//думаем что делать с полученной командой
		case REM:
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

				ifjmp = StrCounter;//вот прыжок

				fprintf(fout, "%d JNEG  \n", StrCounter);//если регистр отрицательного(типа SF) включается, 
				++StrCounter;//то переходим на ячейку StrCounter
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

	linking(lnkList, varList, constList, addrList, Variables, Constants, Bas_str_nums);//СОЗДАНИЕ СПИСКА СО ВСЯЗЯМИ ТИПА СТРОКА-НОМЕР ЯЧЕЙКИ
	
	lnkList.sort(lnk_sort_pred); //(sort - встроенная функция list-а)//СОРТИРОВКА ПО НОМЕРАМ СТРОКИ

	second_run(fout, lnkList);//ЗАПИСЬ НОМЕРОВ ЯЧЕЕК В СТРОКИ КОТОРЫЕ ОБРАЩАЛИСЬ К ПЕРЕМЕННЫМ, КОНСТАНТАМ ИЛИ СТРОКАМ  

	fclose(fout);

	return 0;
}
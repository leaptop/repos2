#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <list>
#include <stack>
#include <iterator>

enum BasicComand {
	INPUT,
	PRINT,
	LET,
	IF,
	GOTO,
	REM,
	END
};

struct Variable {
	char Var;
	int str_num;
};

struct Constant {
	int Const;
	int str_num;
};

struct Address {
	int Addr;
	int str_num;
};

struct Link {//здесь два инта: str_num и Lnk
	int str_num;
	int Lnk;
};

int chk_command(enum BasicComand *key, char *Comm);
int print(FILE * fout, std::list<Variable> varList,
	std::list<Constant>& constList, char * Variables, int * Constants,
	int & StrCounter);
int input(FILE * fout, std::list<Variable> &varList, char * Variables,
	int & StrCounter);
int let(FILE * fout, std::list<Variable>& varList,
	std::list<Constant>& constList, int * Constants, char * Variables,
	int & StrCounter, int & max_tmp_num);
int go_to(FILE * fout, std::list<Address>& addrList, int & StrCounter);
int basic2asm(char *filename1, char *filename2);
void add_var(char variable, std::list<Variable> &varList);
void add_const(int Const, std::list<Constant> &constList);
void add_addr(int Addr, int str_num, std::list<Address> &addrList);
int chk_var(int Var, std::list<Variable> varList);
int chk_const(int Const, std::list<Constant> constList);
int is_var(char simbol);
int get_prior(char c);
int rpn(char *rpn_str, std::list<Constant> &constList);
int rpn_pars(FILE *fout, int *Constants, char *Variables, int &StrCounter,
	char *rpn, int &max_tmp_num);
void initialization(FILE *fout, std::list<Variable> &varList,
	std::list<Constant> &constList, int max_tmp_num, int &StrCounter);
void linking(std::list<Link> &lnkList, std::list<Variable> varList,
	std::list<Constant> constList, std::list<Address> addrList,
	char *Variables, int *Constants, int *Bas_str_nums);
void second_run(FILE *fout, std::list<Link> &lnkList);
bool lnk_sort_pred(Link FIRST, Link SECOND);
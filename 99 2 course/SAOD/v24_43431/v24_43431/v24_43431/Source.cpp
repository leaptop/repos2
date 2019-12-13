#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <vector>
#include <iterator>
#include <algorithm>

#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define ESCAPE 27

struct record {
	char fio[32];
	char street[18];
	unsigned short int house_number;
	unsigned short int apartment_number;
	char date[10];
};

struct spis {
	spis *next;
	union {
		char data[24];
		unsigned char Digit[sizeof(char) * 24];
	};
	int index;
} *head;

struct queue {
	spis *head;
	spis *tail;
}Q;

int control(int &I) {
	char key;
	bool flag = true;

	while (flag) {
		key = _getch();
		switch (key) {
		case LEFT_ARROW:
			if (I >= 40) {
				I -= 40;
				flag = false;
				system("CLS");
			}
			else {
				flag = true;
			};
			break;
		case RIGHT_ARROW:
			if (I >= 4000) {
				flag = true;
			}
			else {
				flag = false;
				system("CLS");
			}
			break;
		case ESCAPE:
			system("CLS");
			return 1;
			break;
		default:
			flag = true;
			break;
		}
	}
	return 0;
}

bool original(record *Array) {
	int i, j;
	for (i = 0; true;) {
		printf("Database \"Settlement\"\n");
		printf("Number               FIO                     Street       House number Appartment number    Date\n");
		for (j = 0; j < 20; ++j, ++i) {
			printf("%5d. %32s %18s %6d %11d            %10s\n", i + 1, Array[i].fio,
				Array[i].street, Array[i].house_number,
				Array[i].apartment_number, Array[i].date);
		}

		switch (control(i)) {
		case 1:
			return 0;
			break;
		case 2:
			return 1;
			break;
		}
	}
}

bool sorted(record *Array, unsigned int *Sort) {
	int i, j;
	for (i = 0; true;) {
		printf("Database \"Settlement\"\n");
		printf("Number               FIO                     Street       House number Appartment number    Date\n");
		for (j = 0; j < 20; ++j, ++i) {
			printf("%5d. %32s %18s %6d %11d            %10s\n", i + 1, Array[Sort[i]].fio,
				Array[Sort[i]].street, Array[Sort[i]].house_number,
				Array[Sort[i]].apartment_number, Array[Sort[i]].date);
		}

		switch (control(i)) {
		case 1:
			return 0;
			break;
		case 2:
			return 1;
			break;
		}
	}
}

void found(std::vector<record*> Array) {
	unsigned int i, j, c;
	char key;
	bool flag;

	std::vector<record*>::iterator it;
	for (i = 0; true;) {
		printf("Database \"Settlement\"\n");
		printf("Number               FIO                     Street       House number Appartment number    Date\n");
		c = 0;
		for (j = 0; j < 20; ++j) {
			if (i < Array.size()) {
				printf("%5d. %32s %18s %6d %11d            %10s\n", i + 1, Array[i]->fio,
					Array[i]->street, Array[i]->house_number,
					Array[i]->apartment_number, Array[i]->date);
				++i;
			}
			else {
				++c;
			}
			puts("");
		}

		flag = true;

		while (flag) {
			key = _getch();
			switch (key) {
			case LEFT_ARROW:
				if (i >= 40 - c) {
					i -= 40 - c;
					flag = false;
					system("CLS");
				}
				else {
					flag = true;
				};
				break;
			case RIGHT_ARROW:
				if (i >= Array.size()) {
					flag = true;
				}
				else {
					flag = false;
					system("CLS");
				}
				break;
			case ESCAPE:
				return;
				break;
			default:
				flag = true;
				break;
			}
		}
	}
}

void DigitalSort(spis *&S) {
	queue Q[256];
	spis *p;
	int i, j, d;
	for (j = 24; j >= 0; --j) {
		for (i = 0; i < 256; ++i) {
			Q[i].tail = (spis*)&(Q[i].head);
		}
		p = S;
		while (p) {
			d = p->Digit[j];
			Q[d].tail->next = p;
			Q[d].tail = p;
			p = p->next;
		}
		p = (spis*)&S;

		for (i = 0; i < 256; ++i) {
			if (Q[i].tail != (spis*)&(Q[i].head)) {
				p->next = Q[i].head;
				p = Q[i].tail;
			}
		}

		p->next = NULL;
	}
}

void data_to_sort(char *DATE, char *STREET, char *DESTINATION) {
	*DESTINATION++ = DATE[6];
	*DESTINATION++ = DATE[7];
	*DESTINATION++ = DATE[3];
	*DESTINATION++ = DATE[4];
	*DESTINATION++ = DATE[0];
	*DESTINATION++ = DATE[1];

	for (unsigned short int i = 0; i < 18; ++i) {
		*DESTINATION++ = STREET[i];
	}
}

struct tree_vertex {
	std::vector<record*> *data;
	bool balance;
	tree_vertex *left;
	tree_vertex *right;
};

struct weight_element {
	std::vector<record*> *data;
	int weight;
};

void add_accurate_tree(tree_vertex **POINTER, weight_element *A) {
	while (*POINTER != nullptr) {
		if (strncmp((*A->data).front()->street, (*POINTER)->data->front()->street, 3) < 0) {
			POINTER = &((*POINTER)->left);
		}
		else {
			if (strncmp((*A->data).front()->street, (*POINTER)->data->front()->street, 3) > 0) {
				POINTER = &((*POINTER)->right);
			}
			else {
				break;
			}
		}
	}
	(*POINTER) = new tree_vertex;
	(*POINTER)->data = A->data;

	(*POINTER)->left = nullptr;
	(*POINTER)->right = nullptr;
}

void AW_building(std::vector<weight_element> &ELEMENTS_ARRAY, unsigned int **WEIGHT_MATRIX,
	unsigned int N) {
	unsigned int i, j;
	for (i = 0; i <= N; ++i) {
		for (j = i + 1; j <= N; ++j) {
			WEIGHT_MATRIX[i][j] = WEIGHT_MATRIX[i][j - 1]
				+ ELEMENTS_ARRAY[j - 1].weight;
		}
	}
}

void AP_and_AR(unsigned int **AP, unsigned int **AR, unsigned int **AW, unsigned int N) {
	unsigned int i, j, h, m, min, k;

	for (i = 0; i < N; ++i) {
		AP[i][i + 1] = AW[i][i + 1];
		AR[i][i + 1] = i + 1;
	}
	for (h = 2; h <= N; ++h) {
		for (i = 0; i <= N - h; ++i) {
			j = i + h;
			m = AR[i][j - 1];
			min = AP[i][m - 1] + AP[m][j];

			for (k = m + 1; k <= AR[i + 1][j]; ++k) {
				unsigned int x = AP[i][k - 1] + AP[k][j];
				if (x < min) {
					m = k;
					min = x;
				}
			}

			AP[i][j] = min + AW[i][j];
			AR[i][j] = m;
		}
	}
}

bool comparation(const weight_element FIRST, const weight_element SECOND) {
	if (strncmp(FIRST.data->front()->street, SECOND.data->front()->street, 3) > 0) {
		return 1;
	}

	return 0;
}

void dictionary_building(std::vector<weight_element> &DICTIONARY, std::vector<record*> ARRAY) {
	int i;
	bool new_element;
	std::vector<weight_element>::iterator it;

	for (i = 0; i < ARRAY.size(); ++i) {
		new_element = true;
		it = DICTIONARY.begin();
		while (it != DICTIONARY.end()) {
			if (strncmp((*it->data).front()->street, ARRAY[i]->street, 3) == 0) {
				it->data->push_back(ARRAY[i]);
				++it->weight;
				new_element = false;

				break;
			}
			++it;
		}
		if (new_element) {
			weight_element t;
			t.data = new std::vector<record*>;
			t.data->push_back(ARRAY[i]);
			t.weight = 1;
			DICTIONARY.push_back(t);
		}
	}

	std::stable_sort(DICTIONARY.begin(), DICTIONARY.end(), comparation);
}

void accurate_tree_building(tree_vertex *&ROOT,
	std::vector<weight_element> &ARRAY, unsigned int L, unsigned int R,
	unsigned int **AR) {
	unsigned int k;

	if (L < R) {
		k = AR[L][R];
		add_accurate_tree(&ROOT, &ARRAY[k - 1]);
		accurate_tree_building(ROOT, ARRAY, L, k - 1, AR);
		accurate_tree_building(ROOT, ARRAY, k, R, AR);
	}
}

void delete_tree(tree_vertex *&POINTER) {
	if (POINTER != nullptr) {
		delete_tree(POINTER->left);

		delete_tree(POINTER->right);

		delete POINTER;
	}
}

std::vector<record*> b_search(record *ARRAY, unsigned int *SORT, char *KEY_STRING) {
	unsigned int l = 0, r = 3999, m;

	while (l < r) {
		m = (l + r) / 2;

		if (ARRAY[SORT[m]].date[6] == KEY_STRING[0] && ARRAY[SORT[m]].date[7] == KEY_STRING[1]) {
			while (m > 0 && ARRAY[SORT[m - 1]].date[6] == KEY_STRING[0] && ARRAY[SORT[m - 1]].date[7] == KEY_STRING[1]) {
				--m;
			}

			std::vector<record*> founded;
			do {
				founded.push_back(&ARRAY[SORT[m]]);

				++m;
			} while (m < 4000 && ARRAY[SORT[m]].date[6] == KEY_STRING[0] && ARRAY[SORT[m]].date[7] == KEY_STRING[1]);
			return founded;
		}
		if (ARRAY[SORT[m]].date[6] > KEY_STRING[0]) {
			r = m;
		}
		else {
			if (ARRAY[SORT[m]].date[6] < KEY_STRING[0]) {
				l = m + 1;
			}
			else {
				if (ARRAY[SORT[m]].date[7] > KEY_STRING[1]) {
					r = m;
				}
				else {
					if (ARRAY[SORT[m]].date[7] < KEY_STRING[1]) {
						l = m + 1;
					}
				}
			}
		}
	}

	std::vector<record*> nullvector;
	record *nullst;
	nullst = new record;
	strcpy_s(nullst->fio, "Nothing found");
	nullst->apartment_number = 0;
	strcpy_s(nullst->date, "");
	strcpy_s(nullst->street, "");
	nullst->house_number = 0;
	nullvector.push_back(nullst);
	return nullvector;
}

std::vector<record*> tree_search(tree_vertex *VERTEX_POINTER, char *KEY_STRING) {
	if (VERTEX_POINTER == nullptr) {
		std::vector<record*> nullvector;
		record *nullst;
		nullst = new record;
		strcpy_s(nullst->fio, "Nothing found");
		nullst->apartment_number = 0;
		strcpy_s(nullst->date, "");
		strcpy_s(nullst->street, "");
		nullst->house_number = 0;
		nullvector.push_back(nullst);
		return nullvector;
	}
	else {
		if (strncmp(KEY_STRING, VERTEX_POINTER->data->front()->street, 3) < 0) {
			return tree_search(VERTEX_POINTER->left, KEY_STRING);
		}
		else {
			if (strncmp(KEY_STRING, VERTEX_POINTER->data->front()->street, 3) > 0) {
				return tree_search(VERTEX_POINTER->right, KEY_STRING);
			}
			else {
				return *VERTEX_POINTER->data;
			}
		}
	}
}

typedef unsigned char bit;

struct uncoding_tree_vertex {
	char simbol;
	unsigned short int weight;
	uncoding_tree_vertex *left;
	uncoding_tree_vertex *right;
};

struct coding_tree_vertex {
	char simbol;
	unsigned short int weight;
	std::vector<bool> code;
	coding_tree_vertex *left;
	coding_tree_vertex *right;
};

void delete_tree(coding_tree_vertex *&POINTER) {
	if (POINTER != nullptr) {
		delete_tree(POINTER->left);

		delete_tree(POINTER->right);

		delete POINTER;
	}
}

void delete_tree(uncoding_tree_vertex *&POINTER) {
	if (POINTER != nullptr) {
		delete_tree(POINTER->left);

		delete_tree(POINTER->right);

		delete POINTER;
	}
}

bool weight_comparation(const uncoding_tree_vertex *FIRST,
	const uncoding_tree_vertex *SECOND) {
	return FIRST->weight > SECOND->weight;
}

void dictionary_building(std::vector<uncoding_tree_vertex*> &DICTIONARY,
	std::vector<char> STRING) {
	bool new_element;
	std::vector<uncoding_tree_vertex*>::iterator it_dictionary;
	std::vector<char>::iterator it_string;
	uncoding_tree_vertex *tmp;

	for (it_string = STRING.begin(); it_string != STRING.end(); ++it_string) {
		new_element = true;

		for (it_dictionary = DICTIONARY.begin(); it_dictionary != DICTIONARY.end(); ++it_dictionary) {
			if ((*it_dictionary)->simbol == *it_string) {
				++(*it_dictionary)->weight;
				new_element = false;

				break;
			}
		}
		if (new_element) {
			tmp = new uncoding_tree_vertex;
			tmp->simbol = *it_string;
			tmp->weight = 1;
			tmp->left = nullptr;
			tmp->right = nullptr;
			DICTIONARY.push_back(tmp);
		}
	}

	std::stable_sort(DICTIONARY.begin(), DICTIONARY.end(), weight_comparation);
}

void HUFFMAN(uncoding_tree_vertex *&ROOT,
	std::vector<uncoding_tree_vertex*> DICTIONARY) {
	uncoding_tree_vertex *l, *r, *n;
	std::vector<uncoding_tree_vertex*>::iterator it;
	int m_weight;

	while (DICTIONARY.size() > 1) {
		l = DICTIONARY.back();
		m_weight = DICTIONARY.back()->weight;

		DICTIONARY.pop_back();

		r = DICTIONARY.back();
		m_weight += DICTIONARY.back()->weight;

		DICTIONARY.pop_back();

		it = DICTIONARY.begin();
		while (it != DICTIONARY.end() && (*it)->weight >= m_weight) {
			++it;
		}

		n = new uncoding_tree_vertex;
		n->weight = m_weight;
		n->left = l;
		n->right = r;
		n->simbol = NULL;

		DICTIONARY.emplace(it, n);
	}

	ROOT = DICTIONARY.back();
	DICTIONARY.pop_back();
}

void coding_list_building(uncoding_tree_vertex *POINTER,
	std::vector<coding_tree_vertex> &LIST, std::vector<bool> CODE) {
	if (POINTER) {
		CODE.push_back(0);
		coding_list_building(POINTER->left, LIST, CODE);
		CODE.pop_back();

		if (!POINTER->left && !POINTER->right) {
			coding_tree_vertex tmp;
			tmp.code = CODE;
			tmp.simbol = POINTER->simbol;
			tmp.weight = POINTER->weight;
			tmp.left = nullptr;
			tmp.right = nullptr;

			std::vector<coding_tree_vertex>::iterator it_list;
			it_list = LIST.begin();

			while (it_list != LIST.end() && tmp.simbol > it_list->simbol) {
				++it_list;
			}
			LIST.emplace(it_list, tmp);
		}

		CODE.push_back(1);
		coding_list_building(POINTER->right, LIST, CODE);
	}
}

void dictionary_writing(std::vector<uncoding_tree_vertex*> DICTIONARY,
	unsigned int &DICTIONARY_SIZE) {
	FILE *destination_file;
	if (fopen_s(&destination_file, "Coded.dat", "wb")) {
		puts("cannot open file\n");
		system("pause");
		return;
	}

	DICTIONARY_SIZE = DICTIONARY.size() * (sizeof(char) + sizeof(unsigned short int));
	fwrite(&DICTIONARY_SIZE, sizeof(unsigned int), 1, destination_file);

	std::vector<uncoding_tree_vertex*>::iterator it_dictionary;

	for (it_dictionary = DICTIONARY.begin(); it_dictionary != DICTIONARY.end();
		++it_dictionary) {

		fwrite(&(*it_dictionary)->simbol, sizeof(char), 1, destination_file);
		fwrite(&(*it_dictionary)->weight, sizeof(unsigned short int), 1,
			destination_file);
	}

	fclose(destination_file);
}

void dictionary_reading(std::vector<uncoding_tree_vertex*> &DICTIONARY,
	unsigned int &DICTIONARY_SIZE) {
	FILE *source_file;

	if (fopen_s(&source_file, "Coded.dat", "rb")) {
		puts("cannot open file\n");
		system("pause");
		return;
	}

	fread(&DICTIONARY_SIZE, sizeof(unsigned int), 1, source_file);

	DICTIONARY_SIZE = DICTIONARY_SIZE / (sizeof(char) + sizeof(unsigned short int));

	uncoding_tree_vertex *tmp_vertex;

	for (unsigned int i = 0; i < DICTIONARY_SIZE; ++i) {
		tmp_vertex = new uncoding_tree_vertex;

		fread(&tmp_vertex->simbol, sizeof(char), 1, source_file);
		fread(&tmp_vertex->weight, sizeof(unsigned short int), 1, source_file);

		tmp_vertex->left = nullptr;
		tmp_vertex->right = nullptr;

		DICTIONARY.push_back(tmp_vertex);
	}

	DICTIONARY_SIZE = DICTIONARY_SIZE * (sizeof(char) + sizeof(unsigned short int));
}

void byte_pack(std::vector<bool> CODED_STRING,
	std::vector<char> &CHAR_CODED_STRING, unsigned int &CODED_STRING_SIZE) {
	unsigned int i, size;
	unsigned short int j;
	std::vector<bool>::iterator it = CODED_STRING.begin();
	CODED_STRING_SIZE = CODED_STRING.size();
	size = CODED_STRING_SIZE / 8;
	if (CODED_STRING_SIZE % 8 != 0) {
		++size;
	}

	for (i = 0; i < size; ++i) {
		unsigned char byte = 0;
		for (j = 8; j; --j) {
			byte <<= 1;

			if (it != CODED_STRING.end()) {
				byte |= bit(*it);

				++it;
			}
		}

		CHAR_CODED_STRING.push_back(byte);
	}
	CHAR_CODED_STRING.shrink_to_fit();
}

void byte_unpack(std::vector<char> CHAR_CODED_STRING,
	std::vector<bool> &CODED_STRING, unsigned int CODED_STRING_SIZE) {
	std::vector<char>::iterator it = CHAR_CODED_STRING.begin();
	unsigned int i = 0;

	while (it != CHAR_CODED_STRING.end()) {
		unsigned char byte = *it;

		for (unsigned short int j = 8; j; --j, ++i) {
			if (i < CODED_STRING_SIZE) {
				if ((byte & 128) != 0) {
					CODED_STRING.push_back(1);
				}
				else {
					CODED_STRING.push_back(0);
				}
			}
			else {
				return;
			}
			byte <<= 1;
		}

		++it;
	}
}

void archiving_efficiency(std::vector<coding_tree_vertex> CODING_LIST) {
	std::vector<coding_tree_vertex>::iterator it_coding_list;
	float entropy = 0, average_length_of_code_word = 0;

	for (it_coding_list = CODING_LIST.begin(); it_coding_list != CODING_LIST.end();
		++it_coding_list) {

		entropy -= (float(it_coding_list->weight) / 256000)
			* log2(float(it_coding_list->weight) / 256000);
		average_length_of_code_word += it_coding_list->code.size()
			* float(it_coding_list->weight) / 256000;
	}

	printf("Entropy: %4.3f\n", entropy);
	printf("Avarage length of code word: %4.3f\n", average_length_of_code_word);
	printf("Redundancy: %4.3f\n", average_length_of_code_word - entropy);
}

void coding(std::vector<coding_tree_vertex> DICTIONARY, std::vector<char> STRING,
	std::vector<bool> &CODED_STRING) {
	std::vector<coding_tree_vertex>::iterator it_dictionary;
	std::vector<bool>::iterator it_code;
	std::vector<char>::iterator it_string;

	for (it_string = STRING.begin(); it_string != STRING.end(); ++it_string) {
		for (it_dictionary = DICTIONARY.begin();
			it_dictionary != DICTIONARY.end(); ++it_dictionary) {

			if (it_dictionary->simbol == *it_string) {
				for (it_code = it_dictionary->code.begin(); it_code
					!= it_dictionary->code.end(); ++it_code) {

					CODED_STRING.push_back(*it_code);
				}

				break;
			}
		}
	}
}

void uncoding(uncoding_tree_vertex *ROOT, std::vector<bool> CODED_STRING,
	std::vector<char> &UNCODED_STRING) {
	uncoding_tree_vertex *POINTER;
	std::vector<bool>::iterator it_bool;

	for (it_bool = CODED_STRING.begin(); it_bool != CODED_STRING.end(); ) {
		POINTER = ROOT;
		while (it_bool != CODED_STRING.end()) {
			if (!POINTER) {
				return;
			}
			if (!POINTER->left && !POINTER->right) {
				UNCODED_STRING.push_back(POINTER->simbol);
				break;
			}
			if (*it_bool) {
				POINTER = POINTER->right;
			}
			else {
				POINTER = POINTER->left;
			}
			++it_bool;
		}
	}
}

void file_pack() {
	system("CLS");

	FILE *file;
	unsigned int dictionary_size, coded_string_size;

	uncoding_tree_vertex *uncoding_tree = nullptr;

	std::vector<uncoding_tree_vertex*> Dictionary;
	std::vector<coding_tree_vertex> coding_list;
	std::vector<bool> code;

	std::vector<char> String;
	std::vector<bool> Coded_string;
	std::vector<char> Char_coded_string;

	std::vector<char>::iterator it_char;

	if (fopen_s(&file, "testBase4.dat", "rb")) {
		printf("file didn't exist\n");
		system("PAUSE");
		return;
	}

	char tmp;
	while (fread(&tmp, sizeof(char), 1, file)) {
		String.push_back(tmp);
	}

	String.shrink_to_fit();

	fclose(file);

	dictionary_building(Dictionary, String);

	dictionary_writing(Dictionary, dictionary_size);

	HUFFMAN(uncoding_tree, Dictionary);

	coding_list_building(uncoding_tree, coding_list, code);

	std::vector<coding_tree_vertex>::iterator it;
	for (it = coding_list.begin(); it != coding_list.end();
		++it) {
		printf("\"%1c\" %5d ", it->simbol, it->weight);
		copy(it->code.begin(), it->code.end(),
			std::ostream_iterator<bool>(std::cout, ""));
		puts("");
	}

	printf("\ncoding...\n");
	coding(coding_list, String, Coded_string);

	printf("\nbyte packing...\n");
	byte_pack(Coded_string, Char_coded_string, coded_string_size);

	if (fopen_s(&file, "Coded.dat", "rb+")) {
		puts("cannot open file\n");
		system("pause");
		return;
	}

	fseek(file, dictionary_size + sizeof(unsigned int), 1);

	fwrite(&coded_string_size, sizeof(unsigned int), 1, file);

	printf("\nwriting in file...\n\n");
	for (it_char = Char_coded_string.begin(); it_char
		!= Char_coded_string.end(); ++it_char) {
		fwrite(&(*it_char), sizeof(char), 1, file);
	}

	fclose(file);

	printf("Base size: %d bytes\n", String.size());
	printf("Coded string size: %d bites\n", Coded_string.size());
	printf("Coded Base size: %d bytes\n", Char_coded_string.size());
	printf("Compression ratio: %4.3f\n", 1.0 - float(Char_coded_string.size())
		/ String.size());

	archiving_efficiency(coding_list);

	system("PAUSE");

	delete_tree(uncoding_tree);
}

void file_unpack() {
	system("CLS");
	unsigned int dictionary_size = 0, coded_string_size;

	uncoding_tree_vertex *uncoding_tree = nullptr;

	FILE *file;
	std::vector<uncoding_tree_vertex*> Dictionary;
	std::vector<char> Char_coded_string;
	std::vector<bool> Coded_string;
	std::vector<char> Uncoded_string;

	std::vector<bool>::iterator it_bool;
	std::vector<char>::iterator it_char;

	record *Array;

	Array = new record[4000];

	dictionary_reading(Dictionary, dictionary_size);

	HUFFMAN(uncoding_tree, Dictionary);

	if (fopen_s(&file, "Coded.dat", "rb")) {
		printf("file didn't exist\n");
		system("PAUSE");
		return;
	}

	fseek(file, dictionary_size + sizeof(unsigned int), 1);

	fread(&coded_string_size, sizeof(unsigned int), 1, file);

	char tmp;
	while (fread(&tmp, sizeof(char), 1, file)) {
		Char_coded_string.push_back(tmp);
	}

	fclose(file);

	printf("unpack bytes...\n");
	byte_unpack(Char_coded_string, Coded_string, coded_string_size);

	printf("\nuncoding...\n");
	uncoding(uncoding_tree, Coded_string, Uncoded_string);

	if (fopen_s(&file, "Uncoded.dat", "wb+")) {
		puts("cannot open file\n");
		system("pause");
		return;
	}

	printf("\nwriting file...\n");
	for (it_char = Uncoded_string.begin(); it_char != Uncoded_string.end(); ++it_char) {
		fwrite(&(*it_char), sizeof(char), 1, file);
	}

	char end = '\0';
	fwrite(&end, sizeof(char), 1, file);

	rewind(file);

	printf("\nreading file...\n");
	for (int i = 0; i < 4000; ++i) {
		fread(&Array[i], sizeof(record), 1, file);
	}

	fclose(file);

	system("PAUSE");

	original(Array);
}

void show(record *Array, unsigned int *Sort) {
	char menu_key;

	while (true) {
		system("CLS");
		printf("1. Original\n2. Sorted\n3. Search\n4. Coding\n5. File Uncoding\nESC. Exit");

		menu_key = _getch();
		if (menu_key == '1') {
			original(Array);
		}

		if (menu_key == '2') {
			system("CLS");
			sorted(Array, Sort);
		}

		if (menu_key == '3') {
			system("CLS");
			char search_key[3];

			printf("Enter year\n");
			std::cin >> search_key;

			tree_vertex *search_tree = nullptr;

			std::vector<record*> founded_list = b_search(Array, Sort, search_key);
			std::vector<weight_element> dictionary;

			system("CLS");
			printf("1. Print\n2. Search in tree\nESC Exit\n");

			menu_key = _getch();

			while (true) {
				if (menu_key == '1') {
					system("CLS");
					found(founded_list);

					break;
				}

				if (menu_key == '2') {
					char tree_search_key[4];

					system("CLS");

					unsigned int i, j, **AW, **AP, **AR;

					dictionary_building(dictionary, founded_list);

					AW = new unsigned int*[dictionary.size() + 1];
					for (i = 0; i <= dictionary.size(); ++i) {
						AW[i] = new unsigned int[dictionary.size() + 1];
					}

					AP = new unsigned int*[dictionary.size() + 1];
					for (i = 0; i <= dictionary.size(); ++i) {
						AP[i] = new unsigned int[dictionary.size() + 1];
					}

					AR = new unsigned int*[dictionary.size() + 1];
					for (i = 0; i <= dictionary.size(); ++i) {
						AR[i] = new unsigned int[dictionary.size() + 1];
					}

					for (i = 0; i <= dictionary.size(); ++i) {
						for (j = 0; j <= dictionary.size(); ++j) {
							AW[i][j] = 0;
							AP[i][j] = 0;
							AR[i][j] = 0;
						}
					}

					AW_building(dictionary, AW, dictionary.size());

					AP_and_AR(AP, AR, AW, dictionary.size());

					accurate_tree_building(search_tree, dictionary, 0, dictionary.size(), AR);

					printf("Enter street\n");

					std::cin >> tree_search_key;

					founded_list = tree_search(search_tree, tree_search_key);

					system("CLS");
					found(founded_list);

					break;
				}

				if (menu_key == ESCAPE) {
					break;
				}
			}

			founded_list.clear();

			delete_tree(search_tree);
		}

		if (menu_key == '4') {
			file_pack();
		}

		if (menu_key == '5') {
			file_unpack();
		}

		if (menu_key == ESCAPE) {
			break;
		}
	}
}

int main() {
	unsigned int i, *Sort;
	FILE *file;
	record *Array;

	std::vector<weight_element> Weight_array;

	tree_vertex *root = nullptr;

	Array = new record[4000];
	Sort = new unsigned int[4000];

	if (fopen_s(&file, "testBase4.dat", "rb")) {
		printf("File doesn't exist\n");
		system("PAUSE");
		return 1;
	}

	for (i = 0; i < 4000; ++i) {
		fread(&Array[i], sizeof(record), 1, file);
	}

	fclose(file);

	spis *p, *pp;

	head = new spis;
	pp = head;
	for (i = 0; i < 4000; ++i) {
		p = new spis;
		pp->next = p;
		pp = p;

		p->index = i;
		data_to_sort(Array[i].date, Array[i].street, p->data);
	}

	p->next = NULL;

	DigitalSort(head);

	p = head;
	for (i = 0; i < 4000; ++i) {
		Sort[i] = p->index;
		p = p->next;
	}

	show(Array, Sort);

	return 0;
}
#include <string>
#include <iostream>
#include <fstream>
#include<vector>
#include <limits>
#include <cstdio>
/*
Лабораторная работа №2
Темы: знакомство с классами в C++
1. Реализовать класс Меню, который запрашивает выбор пользователя и выполняет
соответствующие действия.
2. Пусть Меню является интерфейсом для некоего текстового терминала, который позволяет
вводить слова и добавляет их в общий текст.
3. Терминал должен быть реализован в виде класса, имеющего следующие методы:
Метод		Описание
Открыть
файл Получает текст для терминала из файла
Ввести
строку
Пользователь вводит строку, которая добавляется к
текущему тексту
Показать
текст
Показывает весь текст, который хранит терминал


Поиск слова Поиск слова во всем тексте
Удаление
слова
Удаление всех случаев встречи слова из текста
Очистить
терминал
Очищает текст, хранимый терминалом
Сохранить
файл
Сохраняет изменения в открытый ранее файл или создает
новый файл с заданным именем
4. В работе рекомендуется использовать класс string:
#include <string>
*/
using std::string;//or you can write "using namespace std;"
using std::cout;
using std::cin;
using std::endl;
//using std::vector;

using namespace std;

class terminal {

public:
	FILE * f;
	string path;
	int x = 1000;
	string text;

	//terminal():x(100), buffer(x) {	}// как инициализировать буфер иксом?
	void openFile() {//Получает текст для терминала из файла
		const int MAX_LENGTH = 100;
		char line[MAX_LENGTH];

	   // FILE *pFile;
		char buffer[1000], ch;
		int k = 0;
		fopen_s(&f,"myfile.txt", "r");
		if (f == NULL) perror("\nError opening file");
		else
		{
		    cout << "\nopening\n";
		    while (!feof(f))
			{
				f.getline( text, f);
		   	 /*if (fgets(buffer, 100, f) == NULL) break;
		   	 fputs(text, stdout);*/
				/*ch = getc(f);
				buffer[k++] += ch;*/
		    }
			/*while ((ch = getc(f)) != EOF )
				printf("%c", ch);*/
		   
		}
		printf("%s", buffer);
	   //cout << "Введите имя файла для открытия\n";
	   //cin >> buffer;
	   //fopen_s(&f, buffer, "rb");
	   //if (f==NULL) {
	   //	cout << "Ошибка открытия файла(или его пришлось создавать)" << endl;
	   //}
	   //else {
	   //	cout << "Файл открыт" << endl;
	   //	/*char ch;
	   //	while (fin.get(ch)) {
	   //	cout << ch;
	   //	}*/
	   //}
	   // system("PAUSE");
	   // fclose(f);
	}
	void insertAString() {//Пользователь вводит строку, которая добавляется к текущему тексту
						  //это всё походу сложно будет запускать с потоками... Нужно открывать объект типа файл...
		//fout.open(path, std::ios::app);//app - append
		fopen_s(&f, "myfile.txt", "a");
		cout << "\n Введите текст:\n" << endl;
		char str[256];
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		fgets(str, 255, stdin);
		//fputs( str, f);
		fprintf(f, "\n");
		for (int i = 0; i < 255, str[i] != '\n'; i++)
		{
			fprintf(f, "%c", str[i]);
		}

		//fprintf(f, "\n");
		fclose(f);
		//getchar();
	}


	void showText() {//Показывает весь текст, который хранит терминал
		system("CLS");
		char buffer[1000];
		fopen_s(&f, "myfile.txt", "r+");

		if (f == NULL) perror("Error opening file");
		else
		{
			while (!feof(f))
			{
				if (fgets(buffer, x, f) == NULL) break;
				fputs(buffer, stdout);
			}
			cout << "\n";
			fclose(f);
			system("PAUSE"); system("CLS");
		}
		//for (int i = 0; i < x, fgets(buffer, 5, f) != NULL; i++)
		//{
		//	//while (fgets(buffer, 5, f) != NULL)//проверка чтобы не вывело последнюю строку дважды
		//	cout << buffer[i];
		//}
	}


	void wordSearch() {//Поиск слова во всем тексте
		ifstream input;
		size_t pos;
		string line;
		char str[30];
		int sn = 0;
		int se = 0;

		input.open("myfile.txt");
		//fopen_s(&input, "myfile.txt", "r");
		if (input.is_open())
		{
			while (getline(input, line))
			{
				se--;
				sn++;
				pos = line.find("A");
				if (pos != string::npos) // string::npos is returned if string is not found
				{
					cout << "Found at line №" << sn;
					break;
				}

			}
		//else cout << "Couldn't find";
		}

		system("pause");
		system("CLS");
	}
	void deleteAWord() {//Удаление всех случаев встречи слова из текста

	}
	void clearTerminal() {//Очищает текст, хранимый терминалом

	}
	void saveFile() {//Сохраняет изменения в открытый ранее файл или создает новый файл с заданным именем

	}

};
class menu : public terminal {
	//terminal::openFile();
public: void showMenu() {
	//system("CLS");
	int num = 0;
	cout << "\nВведите команду:\n 0 открыть файл\n 1 ввести строку в файл\n 2 показать текст файла\n 3 Найти слово\n";
	//system("PAUSE");
	//fflush(stdin);
	//_flushall();
	//cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	scanf_s("%d", &num);
	//system("CLS");
	switch (num) {
	case 0: {openFile();   break; }
	case 1: {insertAString();  break; }
	case 2: {showText();  break; }
	case 3: {wordSearch(); break; }
	default: system("CLS");
		//system("PAUSE");

	}
}
};

int main() {
	setlocale(LC_ALL, "ru");
	menu a;
	//system("PAUSE");
	while (true) {

		a.showMenu();

	}
	getchar();
	std::vector <int> v1(3);
	vector<int> myVector;
	return 0;
}

/*
Лабораторная работа №2
Темы: знакомство с классами в C++
1. Реализовать класс Меню, который запрашивает выбор пользователя и выполняет
соответствующие действия.
2. Пусть Меню является интерфейсом для некоего текстового терминала, который позволяет
вводить слова и добавляет их в общий текст.
3. Терминал должен быть реализован в виде класса, имеющего следующие методы:
Метод		Описание
Открыть
файл Получает текст для терминала из файла
Ввести
строку
Пользователь вводит строку, которая добавляется к
текущему тексту
Показать
текст
Показывает весь текст, который хранит терминал
Поиск слова Поиск слова во всем тексте
Удаление
слова
Удаление всех случаев встречи слова из текста
Очистить
терминал
Очищает текст, хранимый терминалом
Сохранить
файл
Сохраняет изменения в открытый ранее файл или создает
новый файл с заданным именем
4. В работе рекомендуется использовать класс string:
#include <string>
*/
class terminal_00 {

public:
	string path;
	ifstream fin;
	ofstream fout;
public: void openFile() {//Получает текст для терминала из файла


	cout << "Введите имя файла для открытия\n";
	cin >> path;
	fin.open(path, std::ios::out);
	if (!fin.is_open()) {
		cout << "Ошибка открытия файла(или его пришлось создавать)" << endl;
	}
	else {
		cout << "Файл открыт" << endl;
		/*char ch;
		while (fin.get(ch)) {
		cout << ch;
		}*/
	}
	fin.close();
	getchar();
}
		void insertAString() {//Пользователь вводит строку, которая добавляется к текущему тексту
							  //это всё походу сложно будет запускать с потоками... Нужно открывать объект типа файл...
			fout.open(path, std::ios::app);//app - append
			cout << "\n Введите текст:\n" << endl;
			string str;
			cin >> str;
			fout << str;
			fout.close();
			getchar();
		}


		void showText() {//Показывает весь текст, который хранит терминал
			fin.open(path, std::ios::out);
			char ch;
			while (fin.get(ch)) {
				cout << ch;
			}

			fin.close();
			getchar();
		}


		void wordSearch() {//Поиск слова во всем тексте

		}
		void deleteAWord() {//Удаление всех случаев встречи слова из текста

		}
		void clearTerminal() {//Очищает текст, хранимый терминалом

		}
		void saveFile() {//Сохраняет изменения в открытый ранее файл или создает новый файл с заданным именем

		}

};
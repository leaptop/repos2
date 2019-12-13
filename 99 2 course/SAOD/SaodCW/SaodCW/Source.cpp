#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*
B = 4         (файл testBase4.dat)
База данных "Населенный пункт"

Стpуктуpа записи:
ФИО гражданина: текстовое поле 32 символа
фоpмат <Фамилия>_<Имя>_<Отчество>
Название улицы: текстовое поле 18 символов
Номер дома:     целое число
Номер квартиры: целое число
Дата поселения: текстовое поле 10 символов
фоpмат дд-мм-гг

Пpимеp записи из БД:
Петpов_Иван_Федоpович___________
Ленина______________
10
67
29-02-65

Ваpианты условий упоpядочения и ключи поиска (К):
С = 3 - по дате поселения и названию улицы, К = год поселения.

S = 4   Цифpовая соpтиpовка
В качестве ключа для упоpядочения нужно взять всего по нескольку 
(обычно не менее тpех) байт из соответствующих полей. 
Файл базы данных загpужается в динамическую память в виде списка, 
который соpтиpуется цифpовым  методом. Затем, для  проведения  
быстрого поиска, по отсортированному списку строится индексный массив.

Типы деревьев поиска
D = 3   Дерево оптимального поиска (приближеный алгоритм)

Методы кодирования
E = 1   Код	 Хаффмена

FILE *fp;
fopen_s(&fp,"testBase4.dat", "rb");
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int const N = 4000;

using namespace std;

struct info {
	char FIO[32];
	char street[18];
	short int number_home;
	short int number_door;
	char data[10];
};
struct info *p;

void readBase(info *&p) {
	int d;
	FILE *fp;
	fopen_s(&fp,"testBase4.dat", "rb");
	p = new struct info[N];
	d = fread((info*)p, sizeof(info), N, fp);
	fclose(fp);
	if (d == 0) { // if not memory
		printf(" Have not memory ");
		system("PAUSE");
		return; // Exit, Error 1;
	}
}

/*
int Years(char *data, int i,int j) {
int number = 0;
number = data[i]%46*10+data[j]%46;
return number;
}
*/
bool Less(info base1, info base2) {
	if (strcmp(base1.data, base2.data) < 0) return 1;
	else if (strcmp(base1.data, base2.data) == 0) {
		if (strcmp(base1.street, base2.street) < 0) return 1;
	}
	return 0;
}

void Heap(info *index, int L, int R) {
	int i, j;
	struct info x;
	x = index[L];
	i = L;
	while (1) {
		j = 2 * i;
		if (j>R) break;
		if (j<R && Less(index[j + 1], index[j])) j++;
		if (Less(x, index[j])) break;
		index[i] = index[j];
		i = j;
	}
	index[i] = x;
}

void HeapSort(struct info *index, int N) {
	int L, R;
	struct info t;
	L = (N / 2) + 1;
	while (L>0) {
		Heap(index, L, N);
		L = L - 1;
	}
	R = N;
	while (R>1) {
		t = index[1];
		index[1] = index[R];
		index[R] = t;
		R = R - 1;
		Heap(index, 1, R);
	}
}

void Create_Index_Massive(info *index, info *p, int N) {
	int i = 1;
	while (i != N + 1) {
		index[i] = *p;
		p++;
		i++;
	}
}
/*
void Key_Search(info *index, info *p){
bool found;
char q;
cout<<"Enter your key";
cin>>q;
for(int i = 0; i < N;){
if(q == index.data){
cout<<"Man found \n";
cout<<i+1<<")\t"<<index[i].FIO;
cout<<"\t"<<index[i].street;
cout<<"\t"<<index[i].number_home;
cout<<"\t"<<index[i].number_door;
cout<<"\t"<<index[i].data<<"\n";
i++;
}
else i++;
}
}
*/

void read20(info *index, info *p) {
	int flag = 0, k;
	for (int i = 1; i<N + 1;) {
		while (flag<20) {
			cout << i << ")\t" << index[i].FIO;
			cout << "\t" << index[i].street;
			cout << "\t" << index[i].number_home;
			cout << "\t" << index[i].number_door;
			cout << "\t" << index[i].data << "\n";
			flag++;
			i++;
		}
		cout << "\n Do you want to see the next 20 persones?  1 or 0  ";
		cin >> k;
		//system("CLS");
		if (k == 1) {
			flag = 0;
		}
		else {
			break;
		}
	}
	//delete p;
}

int main() {
	int ch = 0, q;
	struct info *p = new info;
	struct info *index = new info[N];
	while (ch != 5) {
		system("CLS");
		cout << "1) Print Base\n";
		cout << "2) HeapSort -> PrintBase\n";
		cout << "3) Key search\n";
		cout << "4) Exit\n";
		cin >> ch;
		system("CLS");
		switch (ch) {

		case 1:
			readBase(p);
			Create_Index_Massive(index, p, N);
			read20(index, p);
			break;

		case 2:
			//readBase(p);
			//Create_Index_Massive(index,p,N);
			HeapSort(index, N);
			read20(index, p);
			break;

		case 3:
			return 0;
			/*				readBase(p);
			Create_Index_Massive(index,p,N);
			Key_Search(index,p);
			delete(p);
			delete(index);*/
			break;
		case 4:
			exit(0);
			break;
		}
	}
	delete(p);
	delete(index);
	return 0;
}

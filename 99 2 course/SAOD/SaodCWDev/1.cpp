#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
int const n=4000;
using namespace std;
struct info{
	char fio[32];
	char street[18];
	short int number_home;
	short int number_door;
	char data[10];
}; 
struct info *base;

struct spisok{
	info place;
	struct info *base;
	struct	spisok *next;
	struct	spisok *prev;
};
struct spisok *s;

struct spisok * init(info *base){// init - function; struct spisok - to, kuda vozvrashaetsa obrabotannie znachenia //startoviy uzel
	struct spisok *list;
	list = (struct spisok *)malloc(sizeof(struct spisok));
	list->place = *base;
	list->next = NULL;
	list->prev = NULL;
	return(list);
}

struct spisok * addelem(spisok *list) //dobavlenie elementov
{ 
struct spisok *temp, *p; 
temp = (struct spisok*)malloc(sizeof(spisok)); 
p = list->next; //
list->next = temp; // 
temp->place =*base; // 
temp->next = p; // 
temp->prev = list; // 
if (p != NULL) 
p->prev = temp; 
return(temp); 
}

struct spisok * deletelem(spisok *list) //udalenie elementov
{ 
struct spisok *prev, *next; 
prev = list->prev; // uzel predshestvuyushiy listu
next = list->next; // uzel sleduyushiy za listom
if (prev != NULL) 
prev->next = list->next; // perestavlenie ukazatelia
if (next != NULL) 
next->prev = list->prev; // perestavlenie ukazateley
free(list); // osvobozhdaem pamiat
return(prev); 
}

struct spisok * deletehead(spisok *root) 
{ 
struct spisok *temp; 
temp = root->next; 
temp->prev = NULL; 
free(root); //  
return(temp); // 
}

void listprint(spisok *list) 
{ 
struct spisok *p; 
p = list; 
do { 
printf("%d ", p->place); // 
p = p->next; // 
} while (p != NULL); // 
}



void readBase(info *&base) { //
int d; 
FILE *fp; 
fp=fopen("testBase4.dat", "rb"); 
base=new struct info[n]; 
d = fread( ( info* ) base, sizeof ( info ) , n, fp); //d = 0 no memory; d = 1 ok// an array is filled with data here
fclose(fp); 
if ( d == 0 ) { // if not memory 
printf(" Have not memory "); 
system("PAUSE"); 
//return; // Exit, Error 1; 
} 
}

int main(){
	int ch;
	struct info *base;
	struct spisok *s, *list;
	
	while(ch!=5){
		system("CLS");
		cout<<"1) Print Base\n"; 
		cout<<"2) DigitalSort -> PrintBase\n"; 
cout<<"3) Key search\n"; 
cout<<"4) Exit\n"; 
cin>>ch; 
system("CLS"); 
switch(ch) { 

case 1: 
readBase(base); 
init(base);
addelem(list);
listprint(list) ;

//Create_Index_Massive(index,p,N); 
//read20(index,p); 
break; 
/*
case 2: 
readBase(p); 
Create_Index_Massive(index,p,N); 
DigitalSort(index,N); 
read20(index,p); 
break; 

case 3: 
readBase(p); 
Create_Index_Massive(index,p,N); 
HeapSort(index,N); 
BSearch(index,N,years); 
system("PAUSE"); 
break; 
*/
case 4: 
exit(0); 
break; 
} 
	}
}


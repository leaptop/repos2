#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

using namespace std;
struct da
{
	char	fam[20];
	int 	a, b, c, d;
} data;
typedef struct stud
{
	struct da data;
	struct stud *next;	
} list;
list *creat(void);
void freeList(list *);
void getList(list *);
void insertList(list *&, list *&, list  *&);
void pousk(list *&);

main()
{ 
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	list *head;
	
	head=creat();
	getList(head);
	
	pousk(head);
	getList(head);
	
	freeList(head);
	
    getch(); 
} 

void freeList(list *head)
{
	list *p, *q;
	q=head;
	p=q;
	cout << "\n";
	if (head) {
		while (p) {
			q=p;
			p=p->next;
			delete q;
		}
		head=NULL;
		return;
	}
	else return;
}

void getList(list *head)
{
	list *p;
	p=head;
	cout << "\n";
	printf("Name     1  2  3  4 \n");
	while (p) {
		printf("%9s%3d%3d%3d%3d\n", p->data.fam, p->data.a, p->data.b, p->data.c, p->data.d);
		p=p->next;
	}
}

list *creat(void)
{
	list *h, *j, *i;
	int l=-1, r=10;
	h=NULL; cout << "\nÈìÿ(íàæàòü s è enter äëÿ îêîí÷àíèÿ): ";
	do {
		i=new list;
		 gets(i->data.fam);
		i->data.a=rand()%5+1;
		i->data.b=rand()%5+1;
		i->data.c=rand()%5+1;
		i->data.d=rand()%5+1;
		insertList(h, j, i);
	} while (getch()!='s');
	puts("\n");
	return h;
}
/* */

void insertList (list *&h, list *&j, list *&i)
{
	list *p, *old;
	p=h;
	if (!h) {
		h=i;
		j=i;
		i->next=NULL;
	}
	old=NULL;
	while (p) {
		if (strcmp(p->data.fam, i->data.fam)<0) {
			old=p;
			p=p->next;
		}
		else {
			/*ÂÑÒÀÂÊÀ Â ÑÅÐÅÄÈÍÓ*/
			if (old) { 
				old->next=i;
				i->next=p;
				return;
			}
		
			i->next=p;
			h=i;
			return;
		}
	}
	j->next=i;
	i->next=NULL;
	j=i;
}

void pousk(list *&head)
{
	list *p, *old;
	p=head;
	old=NULL;
	/*ÏÎÊÀ ÍÅ ÊÎÍÅÖ ÑÏÈÑÊÀ*/
	while (p) {
		/*ÅÑËÈ ÃÓÄ ÈÄÅÌ ÄÀËÜØÅ*/
		if (p->data.a>=2 && p->data.b>=2 && p->data.c>=2 && p->data.d>=2) {
			old=p;
			p=p->next;
		}
		else {
			/*ÓÄÀËÅÍÈÅ Â ÑÅÐÅÄÈÍÅ*/
			if (old) {
				old->next=p->next;
				delete p;
				p=old->next;
			}
			/*ÓÄÀËÅÍÈÅ Â ÍÀ×ÀËÅ*/
			else {
				old=p;
				p=p->next;
				delete old;
				old=NULL;
				head=p;
			}
		}
	}
}






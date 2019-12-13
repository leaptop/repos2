#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <graphics.h>
#define N 100
/*Лабораторная работа №6

1). Разработать процедуру построения двоичного Б-дерева.
2). Построить двоичное Б-дерево из 100 вершин, распечатать обход дерева слева направо.
3). Для построенного двоичного Б-дерева вычислить размер, контрольную сумму, 
высоту и среднюю высоту, сравнить их с аналогичными характеристиками АВЛ-дерева поиска, построить таблицу вида:

n=100    Размер  Контр. сумма   Высота Средн.высота
АВЛ
ДБД
*/

struct vertex {
	int data;
	int bal;
	vertex *left;
	vertex *right;
} *root, *root1, *q;

int VR, HR;
int rost;

int B[N];
void mass() {
	int j;
	for (j = 0; j<N; j++)
		B[j] = rand() % 8000;
}

void obhod(vertex *p) {
	if (!p) return;
	obhod(p->left);
	printf("%8d", p->data);
	obhod(p->right);
}

void B2Insert(int D, vertex *&p) {
	if (p == NULL) {
		p = new vertex;
		p->data = D;
		p->left = p->right = NULL;
		p->bal = 0;
		VR = 1;
	}
	else if (p->data>D) {
		B2Insert(D, p->left);
		if (VR == 1) {
			if (p->bal == 0) {
				q = p->left;
				p->left = q->right;
				q->right = p;
				p = q;
				p->bal = 1;
				VR = 0;
				HR = 1;
			}
			else {
				p->bal = 0;
				VR = 1;
				HR = 0;
			}
		}
		else HR = 0;
	}
	else if (p->data<D) {
		B2Insert(D, p->right);
		if (VR == 1) {
			p->bal = 1;
			HR = 1;
			VR = 0;
		}
		else if (HR == 1) {
			if (p->bal == 1) {
				q = p->right;
				p->right = q->left;
				p->bal = 0;
				q->bal = 0;
				q->left = p;
				p = q;
				VR = 1;
				HR = 0;
			}
			else HR = 0;
		}
	}
}

void LL(vertex *&p) {
	vertex *q;
	q = p->left;
	q->bal = 0;
	p->bal = 0;
	p->left = q->right;
	q->right = p;
	p = q;
}

void LR(vertex *&p) {
	vertex *q, *r;
	q = p->left;
	r = q->right;
	if (r->bal<0) p->bal = 1;
	else p->bal = 0;
	if (r->bal>0) q->bal = -1;
	else q->bal = 0;
	r->bal = 0;
	p->left = r->right;
	q->right = r->left;
	r->left = q;
	r->right = p;
	p = r;
}

void RR(vertex *&p) {
	vertex *q;
	q = p->right;
	q->bal = 0;
	p->bal = 0;
	p->right = q->left;
	q->left = p;
	p = q;
}

void RL(vertex *&p) {
	vertex *q, *r;
	q = p->right;
	r = q->left;
	if (r->bal>0) p->bal = -1;
	else p->bal = 0;
	if (r->bal<0) q->bal = 1;
	else q->bal = 0;
	r->bal = 0;
	p->right = r->left;
	q->left = r->right;
	r->left = p;
	r->right = q;
	p = r;
}

void AddAVL(int D, vertex *&p) {
	if (p == NULL) {
		p = new vertex;
		p->data = D;
		p->left = p->right = NULL;
		p->bal = 0;
		rost = 1;
	}
	else if (p->data>D) {
		AddAVL(D, p->left);
		if (rost == 1) {
			if (p->bal>0) { p->bal = 0; rost = 0; }
			else if (p->bal == 0) p->bal = -1;
			else if (p->left->bal<0) { LL(p); rost = 0; }
			else if (p->left->bal>0) { LR(p); rost = 0; }
		}
	}
	else if (p->data<D) {
		AddAVL(D, p->right);
		if (rost == 1) {
			if (p->bal<0) { p->bal = 0; rost = 0; }
			else if (p->bal == 0) p->bal = 1;
			else if (p->right->bal>0) { RR(p); rost = 0; }
			else if (p->right->bal<0) { RL(p); rost = 0; }
		}
	}
	else;
}

//int PaintTree(vertex *p, int Level, int xl, int xr) {
//	int X, Y = 0;
//	char temp[5];
//	if (Level == 0) Y = 35;
//	if (p != NULL) {
//		Y = 35 + 55 * Level;
//		sprintf(temp, "%d", p->data);
//		X = ((xr - xl) / 2) + xl;
//		setcolor(15);
//		outtextxy(X, Y, temp);
//		circle(X + 8, Y + 7, 11);
//		setcolor(15);
//		if (p->left != NULL) {
//			line(X + 8, Y + 18, ((X + 8 - xl) / 2) + xl + 2, Y + 50);
//			PaintTree(p->left, Level + 1, xl, X);
//		}
//		if (p->right != NULL) {
//			if (p->bal == 0) {
//				line(X + 8, Y + 18, ((xr - X + 8) / 2) + X + 8 - 2, Y + 50);
//				PaintTree(p->right, Level + 1, X, xr);
//			}
//			else {
//				line(X + 19, Y + 9, ((xr - X + 19) / 2) + X - 13, Y + 9);
//				PaintTree(p->right, Level, X, xr);
//			}
//		}
//	}
//}

int max(int a, int b) {
	if (a>b) return a;
	else return b;
}

int SizeTree(vertex *p) {
	if (!p) return 0;
	else return 1 + SizeTree(p->left) + SizeTree(p->right);
}

float MediumHeight(vertex *p, int L) {
	if (!p) return 0;
	else return L + MediumHeight(p->left, L + 1) + MediumHeight(p->right, L + 1);
}

int SumTree(vertex *p) {
	if (!p) return 0;
	else return p->data + SumTree(p->left) + SumTree(p->right);
}

int Height(vertex *p) {
	if (!p) return 0;
	else return 1 + max(Height(p->left), Height(p->right));
}

int main() {
	int h, h1, s, s1, k, k1;
	float sh, sh1;
	root = NULL;
	root1 = NULL;
	srand((unsigned)time(NULL));
	//mass = (int*)malloc(sizeof(int) * n);
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		B[i] = rand() % 999 + 1;
		//printf("%8d", B[i]);
	}
	//printf("\n====================\n");
	//mass();//filling B[N]
	for (int i = 0; i<N; i++) { B2Insert(B[i], root); AddAVL(B[i], root1); }
	obhod(root);

	k = SizeTree(root);
	s = SumTree(root);
	h = Height(root);
	sh = MediumHeight(root, 1) / k;
	k1 = SizeTree(root1);
	s1 = SumTree(root1);
	h1 = Height(root1);
	sh1 = MediumHeight(root1, 1) / k1;
	printf("--------------------------------------------------\n");
	printf(" n=100 |  Size  |  Summ  | Height | Medium Height \n");
	printf("--------------------------------------------------\n");
	printf("  AVL  |%8d|%8d|%8d|%13.2f\n", k1, s1, h1, sh1);
	printf("--------------------------------------------------\n");
	printf("  DBD  |%8d|%8d|%8d|%13.2f\n", k, s, h, sh);
	printf("--------------------------------------------------\n");

	puts("\n");
	system("pause");
}

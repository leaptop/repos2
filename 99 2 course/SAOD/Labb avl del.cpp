#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int a[1000],c,b,AddPov=0,DelPov=0,Rost = 0;

struct Vertex
{
	int Data;
	int Bal;
	Vertex *Left;
	Vertex *Right;
};
Vertex *Root;
Vertex *Root1;

void Obhod1 (Vertex *p)
{
	if (p!=NULL)
	{
	    Obhod1(p->Left);
	    printf("%d ",p->Data);
	    Obhod1(p->Right);
    }
}

void FillRand(int a[], int n)
{
	for (int i=1; i<=n; i++)
		a[i]=rand()%(b-c+1)+c;

}

void PrintMas(int a[], int n)
{
	for(int i=1; i<=n; i++) 
		printf(" %d ",a[i]);
	printf("\n");
}

void InsertSort(int a[], int n)
{
    int j,i,t;
    for(i=2; i<=n; i++) 
		{
        t=a[i];
        j=i-1;
        while(j>-1 && t<a[j]) 
		{
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=t;
    }
}

int Size(Vertex *p)
{
	int n;
	if (p==NULL)
	    n=0;
	else
	    n=1+Size(p->Left)+Size(p->Right);
	return n;
}

int Summa(Vertex *p)
{
	int s;
	if (p==NULL)
	    s=0;
	else s=p->Data+Summa(p->Left)+Summa(p->Right);
	return s;
}

int Max(int L, int R)
{
	if (L>R)
	    return L;
	return R;
}

int Hight(Vertex *p)
{
	int h;
	if (p==NULL)
	    h=0;
	else
	    h=1+Max(Hight(p->Left), Hight(p->Right));
	return h;
}

int SDP(Vertex *p, int L)
{
	int s;
	if (p==NULL)
	    s=0;
	else
	    s=L+SDP(p->Left, L+1)+SDP(p->Right, L+1);
	return s;
}

float SredHight(Vertex *p)
{
	return (float)SDP(Root,1)/Size(Root);
}

float SredHight1(Vertex *p)
{
	return (float)SDP(Root1,1)/Size(Root1);
}

void LL(Vertex *&p)
{
	Vertex* q;
	q = p->Left;
    p->Bal = 0;
    q->Bal = 0;
    p->Left = q->Right;
    q->Right = p;
    p = q;
}

void RR(Vertex *&p)
{
	Vertex* q;
	q = p->Right;
    p->Bal = 0;
    q->Bal = 0;
    p->Right = q->Left;
    q->Left = p;
    p = q;
}

void LR(Vertex *&p)
{
	Vertex* r;
	Vertex* q;
	q = p->Left;
    r = q->Right;
    if (r->Bal < 0)
        p->Bal = 1;
    else
	    p->Bal = 0;
    if (r->Bal > 0)
        q->Bal = -1;
    else
	    q->Bal = 0;
	r->Bal = 0;
    q->Right = r->Left;
    p->Left = r->Right;
    r->Left = q;
    r->Right = p;
    p = r;
}

void RL(Vertex *&p)
{
	Vertex* r;
	Vertex* q;
	q = p->Right;
    r = q->Left;
    if (r->Bal < 0)
        q->Bal = 1;
    else
	    q->Bal = 0;
    if (r->Bal > 0)
        p->Bal = -1;
    else
	    p->Bal = 0;
	r->Bal = 0;
    q->Left = r->Right;
    p->Right = r->Left;
    r->Right = q;
    r->Left = p;
    p = r;
}

void create_AVL(int D, Vertex* &p)
{
	//int Rost=0;
	if (p == NULL)
	{
	    p = new Vertex;
        p->Data = D;
	    p->Left = NULL;
        p->Right = NULL;
	    p->Bal = 0;
	    Rost = 1;
    }
    else 
	    if (D < p->Data)
	    {
            create_AVL(D, p->Left);
            if (Rost == 1)
			{ //выросла левая ветка
                if (p->Bal > 0)
                {
		            p->Bal = 0;
			        Rost = 0;
		        }
                else if (p->Bal == 0)
                {
			        p->Bal = -1;
			        Rost = 1;
		        }
                else 
                {
			        if (p->Left->Bal < 0)
                    {
			            LL(p);
			            AddPov++;
			            Rost = 0;
                    }
		            else
		            {
		    	        LR(p);
		    	        AddPov++;
		    	        Rost = 0;
		            }
		        }
		    }
        }
        else if (D > p->Data)
	    {
            create_AVL(D, p->Right);
            if (Rost == 1)
            {
                if (p->Bal < 0)
	            {
		            p->Bal = 0;
			        Rost = 0;
	            }
                else if (p->Bal == 0)
	            {
		            p->Bal = 1;
		            Rost = 1;
                }
                else 
                {
				    if (p->Right->Bal > 0)
	                {
		                RR(p);
		                AddPov++;
		                Rost = 0;
	                }
                    else
	                {
	                    RL(p);
	                    AddPov++;
	    	            Rost = 0;
	                }
	            }
	        }
	    }
    //else
	  //  printf("Вершина есть в дереве\n");
}

void table_AVL_SDP(int SizeSDP, int SummaSDP, int HightSDP, float SredHightSDP, int SizeAVL, int SummaAVL, int HightAVL, float SredHightAVL)
{
	printf("\n               Таблица сравнения СДП и АВЛ деревьев\n");
	printf("  --------------------------------------------------------------------\n");
    printf("  |  n=100  |  Размер  |  Контр. сумма  |  Высота  |  Средн. высота  |\n");
    printf("  --------------------------------------------------------------------\n");
	printf("  |   СДП   |  %5d   |    %8d    |  %5d   |      %6.3f     |\n",SizeSDP,SummaSDP,HightSDP,SredHightSDP);
	printf("  --------------------------------------------------------------------\n");
	printf("  |   АВЛ   |  %5d   |    %8d    |  %5d   |      %6.3f     |\n",SizeAVL,SummaAVL,HightAVL,SredHightAVL);
    printf("  --------------------------------------------------------------------\n");
}

void RR1(Vertex *&p)
{
	Vertex* q;
//	Vertex* p;
	Rost=0;
	q = p->Right;
    if (q->Bal == 0) 
    {
	    q->Bal = 1;  
		p->Bal = -1; 
		Rost = 0;
    }
    else
    {
        q->Bal = 0;
		p->Bal = 0;
	}
    p->Right = q->Left;
    q->Left = p;
    p = q;
}

void LL1(Vertex *&p)
{
	Vertex* q;
//	Vertex* p;
	Rost=0;
	q = p->Left;
    if (q->Bal == 0) 
    {
	    q->Bal = 1;  
		p->Bal = -1; 
		Rost = 0;
    }
    else
    {
        q->Bal = 0;
		p->Bal = 0;
	}
    p->Left = q->Right;
    q->Right = p;
    p = q;
}

void BL(Vertex *&p)
{
	if (p->Bal == -1) 
	{
	    p->Bal = 0;
        //Rost=0;
    }
	else if (p->Bal == 0) 
	{
	    p->Bal = 1;
		Rost=0;
    }
	else if (p->Bal == 1) 
        if (p->Right->Bal >= 0) 
        {
		    RR1(p);
		    DelPov++;
		}
        else
        {
		    RL(p);
            DelPov++;
        }
}

void BR(Vertex *&p)
{
	if (p->Bal == 1) 
	{
	    p->Bal = 0;
        //Rost=0;//
    }
	else if (p->Bal == 0) 
    {
	    p->Bal = -1;
		Rost=0;
    }
	else if (p->Bal == -1) 
        if (p->Left->Bal <= 0) 
		{
		    LL1(p);
            DelPov++;
        }
		else
		{
		    LR(p);
            DelPov++;
        }
}

void del(Vertex *&r, Vertex *&q)//для 2 поддеревьев
{
	if (r->Right != NULL)
	{
	    del(r->Right, q);
        if (Rost == 1) 
	        BR(r);
    }
    else
	{ 
	    q->Data = r->Data;
        q = r;
        r = r->Left;
        Rost = 1; 
    }
}
void DeleteAVL(int D, Vertex *&p)
{
    //Rost=0;
	Vertex* r;
	Vertex* q;
	if (p == NULL)
	    printf("Такой вершины в дереве нет\n");
	else if (D < p->Data)
    {
        DeleteAVL(D,p->Left);
        if (Rost == 1)
            BL(p);
    }
    else if (D > p->Data)
    {
        DeleteAVL(D,p->Right);
        if (Rost == 1)
            BR(p);
    }    
	else if (D == p->Data)
    {
        q = p;
		if (q->Left == NULL) 
		{
		    p = q->Right;  
			Rost = 1;
		}
        else if (q->Right == NULL) 
        {
		    p = q->Left;  
			Rost = 1;
        }
		else if ((q->Left != NULL) && (q->Right != NULL))
		{ 
		    del(q->Left,q);
            if (Rost == 1)  
			    BL(p); 
        }
    free(q);
    }
}

int main()
{
	setlocale(LC_ALL,"Russian");
	int n,x;
	printf("Введите количество вершин в дереве: n = ");
	scanf("%d",&n);
	printf("Введите диапазон значений вершин в дереве: \nот c = ");
	scanf("%d",&c);
	printf("до b = ");
	scanf("%d",&b);

	printf("Рандомный массив: \n");
	FillRand(a,n);
	PrintMas(a,n);

	printf("\n                 АВЛ\n");
	for (int i=1; i<=n; i++)
        create_AVL(a[i], Root);
	printf("Обход дерева слева направо: \n");
	Obhod1(Root);
	printf("\n");
	
//	   printf("\n  Количество поворотов при добавлении в АВЛ = %d",AddPov);

  //  printf("\n  Количество поворотов при добавлении в АВЛ = %d",AddPov);

	printf("\n               Характеристики АВЛ-дерева:\n");
	printf("  Размер дерева = %d\n",Size(Root));
	int sizeAVL=Size(Root);
	printf("  Контрольная сумма дерева = %d\n",Summa(Root));
	int sumAVL=Summa(Root);
	printf("  Высота дерева = %d\n",Hight(Root));
	int hightAVL=Hight(Root);
	printf("  Средняя высота дерева = %4.2f\n",SredHight(Root));
	float sredAVL=SredHight(Root);

    printf("\n               Удаление вершин из дерева\n");
	for (int i=1; i<=10; i++)
	{
	    printf("Введите вершину, которую необходимо удалить: D = ");
	    int D;
	    scanf("%d",&D);
	    DeleteAVL(D,Root);
	    printf("Обход дерева слева направо: \n");
	    Obhod1(Root);
	    printf("\n");
    }
    if (Size(Root) == 0)
        printf("  Все вершины удалены из дерева!\n");
    else
        printf("Что-то пошло не так...\n");

 /*   printf("%d\n",Size(Root));
    for (int i=1; i<=Size(Root); i++)
    {
    	DeleteAVL(a[i],Root);
	}
	Obhod1(Root);*/
  //  printf("\n  Количество поворотов при добавлении в АВЛ = %d",AddPov);
   // printf("\n  Количество поворотов при удалении из АВЛ = %d\n",DelPov);

	system("PAUSE");
	return 0;
}

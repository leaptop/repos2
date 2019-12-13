#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

typedef struct tLE
{
    tLE *next;
    int data;
}st;

tLE * FillRand(int n)
{
    st *p, *next, *h;
    h = new tLE;
    h -> next = 0;
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        p = new tLE;
        p -> data = rand()%101;
        p -> next = h -> next;
        h -> next = p;
    }
    return h;
}

tLE * FillInc (int n)
{
    st *p, *next, *h;
    h = new tLE;
    h -> next = 0;
    for (int i = 0; i < n; i++)
    {
        p = new tLE;
        p -> data = n - i;
        p -> next = h -> next;
        h -> next = p;
    }
    return h;
}

tLE * FillDec (int n)
{
    st *p, *next, *h;
    h = new tLE;
    h -> next = 0;
    for (int i = 0; i < n; i++)
    {
        p = new tLE;
        p -> data = i + 1;
        p -> next = h -> next;
        h -> next = p;
    }
    return h;
}

tLE * CheckSum (st *h)
{
    st *p, *next;
    int sum = 0;
    for (p = h -> next; p; p = p -> next)
        sum += p -> data;

    printf ("%d", sum);
}

tLE * RunNumber (st *h)
{
    st *p, *next;
    int ser = 1;
    for (p = h -> next; p -> next; p = p -> next)
    {
        if (p -> data > (p -> next -> data))
            ser++;
    }
    printf ("%d", ser);
}

tLE * PrintSpis(st *h)
{
    st *p, *next;
    for (p = h -> next; p; p = p -> next)
        printf("%d ", p -> data);
}

main()
{
    int n;
    st *head;

    printf ("Enter number of N-elements: ");
    scanf ("%d", &n);

    head = FillInc (n);
    printf ("\n%d increasing elements: ", n);
    PrintSpis (head);

    head = FillDec (n);
    printf ("\n%d decreasing elements: ", n);
    PrintSpis (head);

    head = FillRand (n);
    printf ("\n%d random elements: ", n);
    PrintSpis (head);

    printf ("\nMassive Sum: ");
    CheckSum (head);

    printf ("\nNumeric Range: ");
    RunNumber (head);

    getch();
}

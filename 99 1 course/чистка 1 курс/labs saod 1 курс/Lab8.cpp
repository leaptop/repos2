#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

struct PhoneBook
{
    int Pnum;
    char FName[40];
    char Gender[10];
    int Number;
};

int SortNumber (int n, struct PhoneBook*PB, int *C)
{
    int i, j, t;
    for (i=1; i<n; i++)
    {
        t=C[i];
        j=i-1;
        while (j>=0 && (PB[C[j]].Number > PB[t].Number))
        {
            C[j+1]=C[j];
            j--;
        }
        C[j+1]=t;
    }
}

int SortGender (int n, struct PhoneBook*PB, int *B)
{
    int i, j, t;
    for (i=1; i<n; i++)
    {
        t=B[i];
        j=i-1;
        while (j>=0 && strcmp(PB[B[j]].Gender, PB[t].Gender) >0)
        {
            B[j+1]=B[j];
            j--;
        }
        B[j+1]=t;
    }
}

int SortName (int n, struct PhoneBook*PB, int *A)
{
    int i, j, t;
    for (i=1; i<n; i++)
    {
        t=A[i];
        j=i-1;
        while (j>=0 && strcmp(PB[A[j]].FName, PB[t].FName) > 0)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=t;
    }
}

int FillStruct(struct PhoneBook*PB, int n)
{
    for (int i=0; i<n; i++)
        PB[i].Pnum=i+1;

    strcpy(PB[0].FName, "IvanovIvan");
    strcpy(PB[1].FName, "PetrovaElizaveta");
    strcpy(PB[2].FName, "SemyonovSemyon");
    strcpy(PB[3].FName, "CvetkovaAnastasiya");
    strcpy(PB[4].FName, "ZaharovZahar");

    strcpy(PB[0].Gender, "Male");
    strcpy(PB[1].Gender, "Female");
    strcpy(PB[2].Gender, "Male");
    strcpy(PB[3].Gender, "Female");
    strcpy(PB[4].Gender, "Male");

    PB[0].Number=2205436;
    PB[1].Number=2203283;
    PB[2].Number=2203489;
    PB[3].Number=2204482;
    PB[4].Number=2202020;
}

main()
{
    int i, n=5;
    int A[n], B[n], C[n];
    for (i=0; i<n; i++)
    {
        A[i]=i;
        B[i]=i;
        C[i]=i;
    }
    struct PhoneBook PB[n];
    FillStruct(PB, n);

    puts ("Origin Phone Book:");
    for (int i=0; i<n; i++)
    printf ("%d %18s %6s %d\n", PB[i].Pnum, PB[i].FName, PB[i].Gender, PB[i].Number);

    SortName (n, PB, A);
    puts ("\nSorted Mass by Name:");
    for (i=0; i<n; i++)
    printf ("%d %18s %6s %d\n", PB[i].Pnum, PB[A[i]].FName, PB[A[i]].Gender, PB[A[i]].Number);

    SortGender (n, PB, B);
    puts ("\nSorted Mass by Gender:");
    for (i=0; i<n; i++)
    printf ("%d %18s %6s %d\n", PB[i].Pnum, PB[B[i]].FName, PB[B[i]].Gender, PB[B[i]].Number);
    
    SortNumber (n, PB, C);
    puts ("\nSorted Mass by Number:");
    for (i=0; i<n; i++)
    printf ("%d %18s %6s %d\n", PB[i].Pnum, PB[C[i]].FName, PB[C[i]].Gender, PB[C[i]].Number);
    getch();
}

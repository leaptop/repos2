#include "headers.h"
//int m = 0;
//int ls = 0;
//char **c;
//char **odd;//couldn't find anywhere
int ii = 0;
//char **losers;
//int q = -1;

void InitNames(char **c)
{
    int i;
    c = (char **)malloc(30 * sizeof(char *));
    for (i = 0; i < 30; i++) {
        c[i] = (char *)malloc(30 * sizeof(char));
    }
}

void InitLosers(char **losers)
{
    int i;
    losers = (char **)malloc(30 * sizeof(char *));
    for (i = 0; i < 30; i++) {
        losers[i] = (char *)malloc(30 * sizeof(char));
    }
}

int SetPrint(char **names, int m)
{
    int i, j, k;
    // printf("m is equal to %d \n",m);
    k = m;
    if (m % 2 == 1) {
        k = m - 1;
    }
    if (m != 1) {
        printf("Winners bracket: \n \n \n");
    }
    // if (m != 1){
    for (i = 0; i < k; i++) {
        if (i % 2 == 0) {
            printf("%s", names[i]);
            for (j = 0; j < (15 - strlen(names[i])); j++) {
                printf("-");
            }
            printf("|");
            printf("\n               |");
            printf("\n               |---");
        }
        if (i % 2 == 1) {
            printf("\n               |");
            printf("\n");
            printf("%s", names[i]);
            for (j = 0; j < (15 - strlen(names[i])); j++) {
                printf("-");
            }
            printf("|");
            printf("\n");
            printf("\n");
        }
    }
    if (m % 2 == 1) {
        printf("%s", names[m - 1]);
        for (j = 0; j < (15 - strlen(names[m - 1])); j++)
            printf("-");
    }
    // if (m==1) printf("%s is the winner!!!",names[0]);
    printf("\n");
    return 0;
}

int SetPrintL(char **names, int m)
{
    int i, j, l = 0, k;
    if (m == 1) {
        m++, l = 1;
    }
    k = m;
    if (m % 2 == 1) {
        k = m - 1;
    }
    printf("Losers bracket: \n \n \n");
    for (i = 0; i < k; i++) {
        if (i % 2 == 0) {
            printf("%s", names[i]);
            for (j = 0; j < (15 - strlen(names[i])); j++) {
                printf("-");
            }
            printf("|");
            printf("\n               |");
            printf("\n               |---");
        }
        if (i % 2 == 1) {
            printf("\n               |");
            printf("\n");
            printf("%s", names[i]);
            for (j = 0; j < (15 - strlen(names[i])); j++) {
                printf("-");
            }
            printf("|");
            printf("\n");
            printf("\n");
        }
    }
    if (m % 2 == 1) {
        printf("%s", names[m - 1]);
        for (j = 0; j < (15 - strlen(names[m - 1])); j++) {
            printf("-");
        }
    }
    if (l == 1) {
        m--, l--;
    }
    printf("\n");
    return 0;
}

void Winners(char **c, char **losers, int *m, int *ls, int *q)
{
    int i;
    int *n = (int *)malloc((*m/2) * sizeof(int));
   // int n[*m / 2];
    int l[20];
    if (*q == -1) {
        printf("Will there be lower bracket? 1 for yes 0 for no. (Note: If "
               "lower bracket will be enabled, number of competitors being not "
               "power of 2 will be impossible, so the teams will automatically "
               "be removed to correspond to closest lower power of 2!) \n");
        scanf("%d", q);//what will happen here? Will it need access more than (int q) in parameters? 
    }
    if (*q == 1) {
        if (*m >= 2 && *m < 4)
            *m = 2;
        if (*m >= 4 && *m < 8)
            *m = 4;
        if (*m >= 8 && *m < 16)
            *m = 8;
        if (*m >= 16 && *m < 32)
            *m = 16;
    }
    printf("Choose winners in each pair! (input 1 if team 1 won, input 2 if "
           "team 2 won) \n");
    for (i = 1; i < (*m / 2) + 1; i++) {
        printf("Winner of pair %d: \n", i);
        scanf("%d", &n[i - 1]);
        if (n[i - 1] == 1) {
            l[i - 1] = 2;
        } else {
            l[i - 1] = 1;
        }
    }
    int mul = 0;
    for (i = 0; i < *m / 2; i++) {
        c[i] = c[n[i] - 1 + mul];
        losers[i] = c[l[i] - 1 + mul];
        mul += 2;
    }
    if (*m % 2 == 1) {
        c[i] = c[*m - 1];
    }
    *ls = *m / 2;
    if (*m % 2 == 0) {
        *m = *m / 2;
    } else {
        *m = *m / 2 + 1;
    }
}

void WinnersLL(char **losers, int m, int *ls)
{
    int i;
    // int n[m/2];
   // int l[20];//unused
    int p[20];
    if (m != 1) {
        printf("Additional round needed in lower bracket!\n");
    }
    printf("Choose winners in each pair! (input 1 if team 1 won, input 2 if "
           "team 2 won) \n");
    SetPrintL(losers, *ls);
    for (i = 1; i < (*ls / 2) + 1; i++) {
        printf("Winner of pair %d: \n", i);
        scanf("%d", &p[i - 1]);
        if (p[i - 1] == 1) {
           // l[i - 1] = 2;//unused
        } else {
           // l[i - 1] = 1;//unused
        }
    }
    int mul = 0;
    for (i = 0; i < *ls / 2; i++) {
        // c[i]=c[n[i] - 1 + mul];
        losers[i] = losers[p[i] - 1 + mul];
        mul += 2;
    }
    *ls = *ls / 2;
    // printf("%s, %s \n\n",losers[0],losers[1]);
}

void WinnersL(char **c, char **losers, int m, int *ls)
{
    int i;
    int *n = (int *)malloc((m / 2) * sizeof(int));
    //int n[m / 2];
    int l[20];
    int p[20];
    if (m != 1) {
        printf("Choose winners in each pair of losers bracket! (input 1 if "
               "team 1 won, input 2 if team 2 won) \n");
    }
    for (i = 1; i < (m / 2) + 1; i++) {
        printf("Winner of pair %d: \n", i);
        scanf("%d", &p[i - 1]);
        if (p[i - 1] == 1) {
            l[i - 1] = 2;
        } else {
            l[i - 1] = 1;
        }
    }
    int mul = 0;
    for (i = 0; i < m / 2; i++) {
        // c[i]=c[n[i] - 1 + mul];
        losers[i + mul] = losers[p[i] - 1 + mul];
        mul += 2;
    }
    if (m != 1)
        printf("Choose winners in each pair of winners bracket! (input 1 if "
               "team 1 won, input 2 if team 2 won) \n");
    for (i = 1; i < (m / 2) + 1; i++) {
        printf("Winner of pair %d: \n", i);
        scanf("%d", &n[i - 1]);
        if (n[i - 1] == 1)
            l[i - 1] = 2;
        else
            l[i - 1] = 1;
    }
    mul = 0;
    for (i = 0; i < *ls; i++) {
        if (p[i] == 1)
            losers[mul + 1] = c[l[i] - 1 + mul];
        if (p[i] == 2)
            losers[mul] = c[l[i] - 1 + mul];
        mul += 2;
    }
    mul = 0;
    for (i = 0; i < m / 2; i++) {
        c[i] = c[n[i] - 1 + mul];
        mul += 2;
    }
    if (m == 1) {
        printf("Winner of the lower finals: %d\n", i);
        scanf("%d", &p[0]);
        losers[0] = losers[p[i] - 1];
        printf("The moment we all came here for! Choose the winner of grand "
               "finals between %s(1) and %s(2)! \n",
                c[0],
                losers[0]);
        scanf("%d", &n[0]);
        if (n[0] == 1)
            printf("%s is the winner of the tournament!\n", c[0]);
        if (n[0] == 2)
            printf("%s is the winner of the tournament!\n", losers[0]);
    }
    m = m / 2;
    if (*ls > m && *ls != 2) {
        WinnersLL(c, m, ls);//will &ls work?
    }
    // printf("%s, %s \n\n",losers[0],losers[1]);
}


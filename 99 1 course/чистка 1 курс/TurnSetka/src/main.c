#include "Funcs_2.h"
#include "Funcs.h"
#include "headers.h"

int m = 0;
int ls = 0;
char **c;
char **losers;
int q = -1;

void InitNames()
{
    int i;
    c = (char **)malloc(30 * sizeof(char *));
    for (i = 0; i < 30; i++) {
        c[i] = (char *)malloc(30 * sizeof(char));
    }
}

void InitLosers()
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
    k = m;
    if (m % 2 == 1) {
        k = m - 1;
    }
    if (m != 1) {
        printf("Winners bracket: \n \n \n");
    }
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

void Winners()
{
    int i;
    int n[m / 2];
    int l[20];
    char str[20];
    if (q == -1) {
        yy: printf("Will there be lower bracket? 1 for yes 0 for no. (Note: If "
               "lower bracket will be enabled, number of competitors being not "
               "power of 2 will be impossible, so the teams will automatically "
               "be removed to correspond to closest lower power of 2!) \n");        
        scanf("%s", str);
        if (checkIns(str)) {
            goto yy;
        }
        switch (str[0]) {
        case 49:
            q = 1;
            break;
        case 50:
            goto yy;
            break;
        case 48:
            q = 0;
            break;
        }
    }
    if (q == 1) {
        if (m >= 2 && m < 4)
            m = 2;
        if (m >= 4 && m < 8)
            m = 4;
        if (m >= 8 && m < 16)
            m = 8;
        if (m >= 16 && m < 32)
            m = 16;
    }
    printf("Choose winners in each pair! (input 1 if team 1 won, input 2 if "
           "team 2 won) \n");
    for (i = 1; i < (m / 2) + 1; i++) {
        mm: printf("Winner of pair %d: \n", i);    
        scanf("%s", str);
        if (checkIns(str)) {
            goto mm;
        }
        switch (str[0]) {
        case 49:
            n[i - 1] = 1;
            break;
        case 50:
            n[i - 1] = 2;
            break;
        case 48:
            goto mm;
            break;
        }
        if (n[i - 1] == 1) {
            l[i - 1] = 2;
        } else {
            l[i - 1] = 1;
        }
    }
    int mul = 0;
    for (i = 0; i < m / 2; i++) {
        c[i] = c[n[i] - 1 + mul];
        losers[i] = c[l[i] - 1 + mul];
        mul += 2;
    }
    if (m % 2 == 1) {
        c[i] = c[m - 1];
    }
    ls = m / 2;
    if (m % 2 == 0) {
        m = m / 2;
    } else {
        m = m / 2 + 1;
    }
}

void WinnersL()
{
    int i;
    int n[m / 2];
    int l[20];
    int p[20];
    char str[20];
    if (m != 1) {
        printf("Choose winners in each pair of losers bracket! (input 1 if "
               "team 1 won, input 2 if team 2 won) \n");
    }
    for (i = 1; i < (m / 2) + 1; i++) {
        kk: printf("Winner of pair %d: \n", i); 
        scanf("%s", str);
        if (checkIns(str)) {
                goto kk;
        }
        switch (str[0]) {
        case 49:
            p[i - 1] = 1;        
            break;
        case 50:
            p[i - 1] = 2;
            break;
        case 48:
            goto kk;
            break;
        }
        if (p[i - 1] == 1) {
            l[i - 1] = 2;
        } else {
            l[i - 1] = 1;
        }
    }
    int mul = 0;
    for (i = 0; i < m / 2; i++) {        
        losers[i + mul] = losers[p[i] - 1 + mul];
        mul += 2;
    }
    if (m != 1)
        printf("Choose winners in each pair of winners bracket! (input 1 if "
               "team 1 won, input 2 if team 2 won) \n");
    for (i = 1; i < (m / 2) + 1; i++) {
        bb: printf("Winner of pair %d: \n", i);     
        scanf("%s", str);
        if (checkIns(str)) {
            goto bb;
        }
        switch (str[0]) {
        case 49:
            n[i - 1] = 1;        
            break;
        case 50:
            n[i - 1] = 2;
            break;
        case 48:
            goto bb;
            break;
        }
        if (n[i - 1] == 1) {
            l[i - 1] = 2;
        }
        else {
            l[i - 1] = 1;
        }
    }
    mul = 0;
    for (i = 0; i < ls; i++) {
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
        d: printf("Winner of the lower finals: \n");
        scanf("%s", str);
        if (checkIns(str)) {
            goto d;
        }
        switch (str[0]) {
        case 49:
            p[0] = 1;
            break;
        case 50:
            p[0] = 2;
            break;
        case 48:
            goto d;
            break;
        }
        losers[0] = losers[p[i] - 1];
        printf("The moment we all came here for! Choose the winner of grand "
               "finals between %s(1) and %s(2)! \n",
                c[0],
                losers[0]);    
        aa: scanf("%s", str);
        if (checkIns(str)) {
            goto aa;
        }
        switch (str[0]) {
        case 49:
            n[0] = 1;
            break;
        case 50:
            n[0] = 2;
            break;
        case 48:
            goto aa;
            break;
        }
        if (n[0] == 1)
            printf("%s is the winner of the tournament!\n", c[0]);
        if (n[0] == 2)
            printf("%s is the winner of the tournament!\n", losers[0]);
    }
    m = m / 2;
    if (ls > m && ls != 2) {
        WinnersLL();
    }   
}

void WinnersLL()
{
    int i;
    char str[20];
    int p[20];
    if (m != 1) {
        printf("Additional round needed in lower bracket!\n");
    }
    printf("Choose winners in each pair! (input 1 if team 1 won, input 2 if "
           "team 2 won) \n");
    SetPrintL(losers, ls);
    for (i = 1; i < (ls / 2) + 1; i++) {
        e: printf("Winner of pair %d: \n", i);     
        scanf("%s", str);
        if (checkIns(str)) {
            goto e;
        }
        switch (str[0]) {
            case 49:
                p[i-1] = 1;
                break;
            case 50:
                p[i-1] = 2;
                break;
           case 48:
                goto e;
                break;
        }    
    }
    int mul = 0;
    for (i = 0; i < ls / 2; i++) {
        losers[i] = losers[p[i] - 1 + mul];
        mul += 2;
    }
    ls = ls / 2;
}

int main()
{
    char str[20];
    int s;
    int ch = 1;
    InitNames();
    InitLosers();
    char chr[30][20];
    readFile(c, chr, &m);
    for (s = 0; s < m; s++) {
        c[s][strlen(c[s]) - 1] = '\0';
    }
    while (ch) {
        if (q <= 0) {
            b: printf("1 - show grid \n");
            printf("2 - choose winners \n");           
            scanf("%s", str);
            if (checkIns(str)) {
                continue;
            }
            switch (str[0]) {
            case 49:
                SetPrint(c, m);
                break;
            case 50:
                if (m != 1) {
                    Winners();
                    SetPrint(c, m);
                }
                if (m == 1) {
                    printf("%s is the winner of the tournament!\n", c[0]),
                            ch = 0;
                }
                break;
            case 48:
                goto b;
            }
        }
        if (q == 1) {
         a: printf("1 - show grid \n");
            printf("2 - choose winners \n");           
            scanf("%s", str);
            if (checkIns(str)) {
                goto a;
            }
            switch (str[0]) {
            case 49:
                SetPrint(c, m);
                SetPrintL(losers, m);
                break;
            case 50:
                WinnersL();
                if (m != 0) {
                    SetPrint(c, m);
                    SetPrintL(losers, ls);
                }
                if (m == 0)
                    ch = 0;
                break;
            case 48:
                goto a;         
            }
        }
    }
}

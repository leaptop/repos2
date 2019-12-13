#include "Funcs.h"
#include "Funcs_2.h"
#include "headers.h"

int main()
{
    int q = -1;
    int ls = 0;
    int m = 0;
    char **c = NULL;
    int x, s;
    int ch = 1;
    char **losers = NULL;
    // InitNames();
    InitNames(c);
    InitLosers();
    char chr[30][20];
    readFile(c, chr, &m);
    for (s = 0; s < m; s++) {
        c[s][strlen(c[s]) - 1] = '\0';
    }
    while (ch) {
        if (q <= 0) {
            printf("1 - show grid \n");
            printf("2 - choose winners \n");
            scanf("%d", &x);
            switch (x) {
            case 1:
                SetPrint(c, m);
                break;
            case 2:
                if (m != 1) {
                    Winners(c, losers, &m, &ls, &q);
                    SetPrint(c, m);
                }
                if (m == 1)
                    printf("%s is the winner of the tournament!\n", c[0]),
                            ch = 0;
                break;
            }
        }
        if (q == 1) {
            printf("1 - show grid \n");
            printf("2 - choose winners \n");
            scanf("%d", &x);
            switch (x) {
            case 1:
                SetPrint(c, m);
                SetPrintL(losers, m);
                break;
            case 2:
                WinnersL(c, losers, m, &ls);
                if (m != 0) {
                    SetPrint(c, m);
                    SetPrintL(losers, ls);
                }
                if (m == 0)
                    ch = 0;
                break;
            }
        }
    }
}

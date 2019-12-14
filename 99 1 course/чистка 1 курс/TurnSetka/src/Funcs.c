#ifndef FUNCS
#define FUNCS

int checkIns(char ins[] ){
if((ins[0] != 48 && ins[0] != 49 && ins[0] != 50) || ins[1]) {
    return 1;
    } else {
        return 0;
    }
}
#endif
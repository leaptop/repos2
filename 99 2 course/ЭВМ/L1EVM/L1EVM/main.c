#define _CRT_SECURE_NO_WARNINGS
#include "vm.h"

void check_mem()
{
    printf("--MEMTEST START--\n");
    int tmp = 0;
    sc_memoryInit();
    if (!sc_memorySet(0, 1)) {
        printf("Set passed\n");
        if (!sc_memoryGet(0, &tmp) && tmp == 1) {
            printf("Get passed\n");
            if (!sc_memorySave("testFile")) {
                printf("Save passed\n");
                if (!sc_memoryLoad("testFile") && memory[0] == 1) {
                    printf("Load passed\n**MEMTEST DONE**\n");
                } else
                    printf("Wrong loaded value\n");
            }
        } else
            printf("Wrong get value\n");
    }
    return;
}

void check_reg()
{
    printf("\n--REGISTER CHECK--\n");
    sc_regInit();
    int tmp = 0;
    if (!sc_regSet(FREQ_ERR, 1)) {
        printf("Set passed\n");
        printf("%d\n", reg_flag);
        if (!sc_regGet(FREQ_ERR, &tmp) && tmp == 1) {
            printf("%d\n", tmp);
            printf("Get passed\n");
            printf("**REGISTER OK\n");
        }
    }
    return;
}

void check_command()
{
    printf("\n--ENCODE/DECODE CHECK--\n");
    int value = 0, command = 15, operand = 24;
    printf("encode: command %d, operand %d\n", command, operand);
    if (!sc_commandEncode(command, operand, &value)) {
        command = operand = 0;
            if (!sc_commandDecode(value, &command, &operand)) {
                printf("decoded: command = %d, operand = %d\n", command, operand);
                if (command == 15 && operand == 24)
                    printf("**ENCODE/DECODE OK**\n");
            }
    }
    return;
}

int main()
{
    check_mem();
    check_reg();
    check_command();
	system("PAUSE");
    return 0;
	
}



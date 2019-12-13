#include "Basic2Asm.h"
#include "Asm2Bin.h"

int main() {
	char filename1[] = { "program.bas" };
	char filename2[] = { "program.asm" };
	char filename3[] = { "operative_memory.dat" };

	basic2asm(filename1, filename2);
	asm2bin(filename2, filename3);

	system("PAUSE");

	return 0;
}
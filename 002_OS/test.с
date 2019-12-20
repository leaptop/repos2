#include <stdio.h>
#include <string.h>
#include <process.h>

int main() {
	while (1) {
		printf("> ");
		char command[100];
		scanf("%s", command);
		if (strcmp(command, "ls") == 0) {
			_spawnlp(_P_WAIT, "cmd", "/c", "dir", NULL);
		}
		else if (strcmp(command, "clear") == 0){
			_spawnlp(_P_WAIT, "cmd", "/c", "CLS", NULL);
		}
		else if (strcmp(command, "man") == 0){
			_spawnlp(_P_WAIT, "cmd", "/c", "HELP", NULL);
		}
		else {
			printf("command not found\n");
		}
	}
}
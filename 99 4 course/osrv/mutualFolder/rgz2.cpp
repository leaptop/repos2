#include <process.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <sys/mman.h>

inline void info(const char *print_prefix, int *addr) {
	off64_t offset;

	mem_offset64((void*)addr, NOFD, 1, &offset, 0);

	printf("[%s]\tAddress of x (pid: %d): %llu\n", print_prefix, getpid(), offset);

}

int main() {

	printf("\n");

	int *x = (int*)mmap(0, 1, PROT_WRITE, MAP_PRIVATE | MAP_ANON, NOFD, 0);

	info("Before fork() call", x);

	if (fork() == 0) {
		info("Child before change", x);
		usleep(100);
		*x = 20;
		info("Child after change", x);
	}

	else {
		info("Parent before change", x);
		usleep(100);
		*x = 30;
		info("Parent after change", x);
	}

	return 0;

}
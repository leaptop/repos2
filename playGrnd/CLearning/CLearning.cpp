#include <stdio.h>
#include <string.h>

int main (void)
{
	char *ptr = "A";
  puts ("Hello, World!");
  int Var = *ptr;
		printf("%d", Var);
		// Var = &ptr;
			printf("%d", Var);
  
  	ptr = strtok(NULL, " \t");//
  	printf("c", ptr);
		if (ptr == NULL) {
			return 1;
		}
		
  
  return 0;
}

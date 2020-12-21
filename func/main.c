#include <stdio.h>


int main(int argc, char *argv[])
{
	printf("Hello World!\n");

	printf("argc = %d\n", argc);

//	for(int i = 0; i < argc; i++)
	for(int i = 0; argv[i] != NULL; i++)
	{
		printf("%s ", argv[i]);
	}
	printf("\n");
	
	return 0;
}

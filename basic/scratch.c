#include <stdlib.h>
#include <stdio.h>


int main(void)
{	
	int *p = NULL;
	//int i;
		
	p = malloc(sizeof(int));
	if (p == NULL)
		exit(1);	
		//return -1;
	
	printf("Hello World!\n");

	exit(0);
	//return 0;
}

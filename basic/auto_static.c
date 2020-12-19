#include <stdio.h>
#include <stdlib.h>

void func()
{
	static int x = 0;
	x ++;
	printf("%p -> x = %d\n", &x, x);
	
}


int main(void)

{
	auto int i;

	static int j;
	
	printf("j = %d\n", j);	
	
	printf("i = %d\n", i);

	func();
	func();
	func();

	exit(0);
}

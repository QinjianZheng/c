#include <stdio.h>

int i = 100;

void func(int i)
{
	printf("i = %d\n", i);
}


void print_star(void)
{
	for (i = 0; i < 5; i++)
		printf("*");
	printf("[%s]i = %d\n", __FUNCTION__, i);
	printf("\n");
}

int main()
{
/*	
	// int i = 2;	
	int i = 3;
	// i的作用范围在main函数里面
	func(i);
		{	
			// int i = 5;
			printf("i = %d\n", i);
		}
*/
	for (i = 0; i < 5; i++)
	{	
		printf("i before print_star() = %d\n", i);
		print_star();
		printf("[%s]i = %d\n", __FUNCTION__, i);
		printf("i after print_star() = %d\n", i);
	}
	return 0;


}

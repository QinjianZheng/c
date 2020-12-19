#include <stdio.h>
#include <stdlib.h>
#define STRSIZE 32
#define SEC_YEAR (60LL*60LL*24LL*365LL)

int main()
{
	int a = 65;
	float f = 123.45678;
	char str[STRSIZE] = "helloworld";	
	int i = 0;
	
	printf("There is %lld seconds in a year\n", SEC_YEAR);

	printf("[%s:%d]before while().\n", __FUNCTION__, __LINE__);
	while (i < 10)
	{
		printf("in while\n");
		i++;
	}
	printf("[%s:%d]after while().\n", __FUNCTION__, __LINE__);
	printf("i(16) = %#x\n", i);
	printf("i(8) = %#o\n", i);
	printf("a(%%c) = %c\n", a);
	printf("a(%%d) = %07d\n", a);
	printf("f = %.3f\n", f);
	printf("str = %.5s\n", str);

	printf("Hello World!\n");
	printf("%d %e\n", i, f);	
/*
	格式：printf("%[修饰符]格式字符", 输出表项); 
	printf("Hello World!\n");
	printf("a = %d, b = %d\n", a, b);
*/

	exit(0);
}


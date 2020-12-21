#include <stdio.h>

union
{

	struct
	{
		char a:1;
		char b:2;
		char c:1;
	
	} x;
	char y; // 1 byte = 8bits

} u;

int main()
{
	printf("%lu\n", sizeof(u));
	// 1

	u.y = 2;

	printf("a = %u, b = %u, c = %u\n", u.x.a, u.x.b, u.x.c);
	printf("a = %d, b = %d, c = %d\n", u.x.a, u.x.b, u.x.c);
	
	return 0;
}

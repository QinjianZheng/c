#include <stdio.h>

int fib(int n)
{
	if(n < 0)
		return -1;

	if(n == 0)
		return 0;

	if(n == 1)
		return 1;

	return fib(n-1) + fib(n-2);

}


int main(void)
{
	int n;
	int res;
	int i;

	scanf("%d", &n);

	for(i = 1; i <= n; i++)
	{
		res = fib(i);
		printf("%d ", res);
	}
	printf("\n");
	return 0;

}

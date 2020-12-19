#include <stdio.h>

static void find_prime(void)
{
	char prime[1001] = {0};
	int i,j;

	for(i = 2; i < 1001; i++)
	{
		if(prime[i] == 0)
		{
			for(j = i*2; j < 1001 ; j += i)
			{
				prime[j] = 1;
			}
		}

	}
	for(i = 2; i < 1001; i++)
		if(prime[i] == 0)
			printf("%d ", i); 
}


int main()
{
	find_prime();
	return 0;	
}

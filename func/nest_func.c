#include <stdio.h>

int max(int a, int b, int c)
{
	int temp;

	temp = a > b ? a : b;
	return temp > c ? temp : c;

}

int min(int a, int b, int c)
{
	int temp;

	temp = a < b ? a : b;
	return temp < c ? temp : c;

}

int dist(int a, int b, int c)
{
	return max(a,b,c) - min(a,b,c);
	
}

int main()
{
	int a = 3, b = 5, c = 10;
	int res;

	res = dist(a,b,c);

	printf("Max - Min = %d\n", res);
	return 0;
}

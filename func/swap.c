#include <stdio.h>


// 值传递
int print_value(int a, int b)
{
	printf("%d %d\n",a ,b);
	return 0;
}

// 地址传递

void swap(int *p, int *q)
{
	int temp;
	
	temp = *p;
	*p = *q;
	*q = temp;

}

int main()
{
	int i = 3, j = 5;
	
	print_value(i, j);
	
	swap(&i, &j);

	print_value(i, j);

	return 0;
}

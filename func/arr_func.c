#include <stdio.h>


// void print_array(int *p, int n)
void print_array(int p[], int n) //p[]在形参中与指针相同
{

	for(int i = 0; i < n ; i++)
		printf("%d ", p[i]);
	printf("\n");

}

void reverse(int *p, int n)
{
#if 0
	int b[n];
	for(int i = 0; i < n; i++)
	{
		b[n-i-1] = p[i];
	}

	for(int i = 0; i < n; i++)
	{
		p[i] = b[i];
	}
#endif

// 头尾互换，到中间为止
	int i = 0, j, m, temp;
	m = (n-1)/2;
	printf("m = %d\n", m);
	for(; i <= m; i++)
	{
		j = n-1-i;
		temp = p[i];
		p[i] = p[j];
		p[j] = temp;
	
	}
}


int main()
{
	int a[] = {1,3,4,5,6,8};
	int n = sizeof(a)/sizeof(*a);

// 传递了一维数组的数组名只是传递了起始位置的地址
// 没有办法获取数组的长度
	print_array(a, n);

	reverse(a, n);

	print_array(a, n);
	return 0;
}

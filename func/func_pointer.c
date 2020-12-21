#include <stdio.h>

int add(int a, int b)
{
	return a+b;
}

int sub(int a, int b)
{
	return a-b;
}


int main()
{
	int a = 3, b = 5;
	// 函数指针 抽象函数定义
	int (*p) (int, int);
	int (*q) (int, int);

	// 函数指针数组
	int (*func[2])(int, int) = {p, q};
	int ret;
	
	p = add;
	q = sub;

	func[0] = add;
	func[1] = sub;

	printf("使用add函数本身:\n");
	printf("%d\n", add(a,b));

	printf("使用指针p引用函数add:\n");
	printf("%d\n", p(a,b));

	printf("使用函数指针数组调用函数:\n");
	for(int i = 0; i < 2; i++)
	{
		ret = func[i](a,b);
		printf("%d ", ret);
	}
	printf("\n");


	printf("使用指针q引用函数sub:\n");
	printf("%d\n", q(a,b));
	
	return 0;
}

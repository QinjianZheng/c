#include <stdio.h>


int main()
{
	int i = 255;
	int *p = &i;
	int **q = &p;

	printf("sizeof(int) is %lu\n", sizeof(i));
	printf("sizeof(pointer) is %lu\n", sizeof(p));

	printf("i的地址是 %p\n", &i);
	printf("i的值是%d\n", i);

	printf("p的地址是 %p\n", &p);
	printf("p的值是%p\n", p);
	printf("*p的值是%d\n", *p);

	printf("q的地址是 %p\n", &q);
	printf("q的值是%p\n", q);
	printf("**q的值是%d\n", **q);
	printf("\n");

// 非法访问（野指针）
#if 0	
	int *p1;
	printf("%p -> %d\n", p1, *p1);
#endif
//空类型

	void *p2 = NULL; 


	return 0;

}

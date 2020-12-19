#include <stdio.h>


int main()
{
#if 0
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
#endif

// 非法访问（野指针）
#if 0	
	int *p1;
	printf("%p -> %d\n", p1, *p1);
#endif
//空类型

	void *p2 = NULL;
 
//指针与数组

	int a[3] = {1,2,3};
	int *p3 = a;
	int i;
//	for(i = 0; i < sizeof(a)/sizeof(a[0]); i++)
// 取数组中的第一个元素（a[0] = *(a+0) = *a = *p）
	for(i = 0; i < sizeof(a)/sizeof(*a); i++)
//		printf("%p -> %d\n", a+i,  a[i]);
		printf("%p -> %d\n", p3+i, p3[i]);
//	printf("\n");

	printf("a = %p, a+1 = %p\n", a, a+1);
	printf("p3 = %p, p3+1 = %p\n", p3, p3+1);
	printf("*p3 = %d, *(p3+1) = %d\n", *p3, *(p3+1));	

	printf("p3++之后\n");
	p3++;

    printf("a = %p, a+1 = %p\n", a, a+1);
    printf("p3 = %p, p3+1 = %p\n", p3, p3+1);
	printf("*p3 = %d, *(p3+1) = %d\n", *p3, *(p3+1));


// 临时的数组变量

	int *p4 = (int [3]){1,2,3};
	for(int i = 0; i < 3; i++)
		printf("%p -> %d\n", &p4[i], p4[i]);

//指针的运算

	int a1[] = {5,1,7,2,8,3};
	int y;
	int *p = &a1[1];

	y = (*--p)++;
	// p先自减得到&a[0]，取*得5，先将5赋值给y，再自增，即a[0] = a[0]+1 = 6
	printf("y = %d\n", y);
	printf("a1[0] = %d\n", a1[0]);
	// y = 5
	
	return 0;

}

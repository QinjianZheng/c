#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926
#define ADD (2+3)
#define MAX(a,b)  \
		({typeof(a) A=a, B=b; ((A) > (B) ? (A) : (B));}) //带参宏
//#的内容都在预编译的内容解决掉了
//函数运行时间算在运行
//用户层稳定与时间的内容

#if 0
int max(int a, int b)
{
	return a > b ? a : b;
}
#endif

int main()
{

	int radius;
	float area;

	int i = 5, j = 3;

	radius = 100;
	area = 2 * PI * radius;

	printf("The area is %f\n", area);
	
	printf("%d\n", ADD * ADD);
	
	printf("i = %d\tj = %d\n", i, j);

	printf("The max of %d and %d is %d\n", i, j,  MAX(i++, j++));

	printf("i = %d\tj = %d\n", i, j);	
}





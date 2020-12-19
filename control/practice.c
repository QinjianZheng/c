#include <stdio.h>
#include <math.h>

#define PI 3.14

static void test6(void)
{

	puts("begin!");

	int i,j,k;

	for(i = 0; i < 100/5; i++)
	{
		for(j = 0; j < 100/3; j++)
		{
			k = 100 - i - j;
			if(k % 3 == 0 && 5*i + 3*j + k/3  == 100)
			{
				printf("鸡翁：%d, 鸡母：%d, 鸡雏：%d\n", i, j, k);
			}
		}
		
	}
	puts("end!");
	
}

static void test8(void)
{
	int i,j,mark;

	for(i = 2; i < 1000; i++)
	{	
		mark = 1;
		for(j = 2; j < sqrt(i); j++)
		{
			if(i % j == 0)
			{
				mark = 0;
			}
		}
		if(mark)
			printf("%d ", i); 
	}

}

static void test10(void)
{	

	int i,j,k;
	int half = 4;
	for(i = 1; i <= half; i ++)
	{
		for(j = 1; j <= half-i; j++)
		{
			printf(" ");
		}
		for(k = 0; k <2*i-1; k++)
		{
			printf("*");

		}
		printf("\n");
	}

	for(i = 1; i < half; i++)
	{
		for(j = 1; j <= i; j++)
		{
			printf(" ");	
		}
		for(k = 1 ; k <2*half - 2 * i; k++)
		{
			printf("*");
		}
		printf("\n");

	}

}

static void test11()
{
	int num;
	int sum = 0;

	printf("Please enter the first integer(q to quit): ");
	while(scanf("%d", &num) == 1)
	{
		sum += num;
		printf("Please enter the next integer(q to quit): ");
	}
	printf("sum = %d\n", sum);

}

static void test12()
{
	int r;
	float area = 0;
	
	
	for(r = 1; ;r++)
	{
		area = PI * r * r;
		if(area > 100)
			break;
		printf("area = %f\n", area);

	}
}


int main()
{

//	test6();
//	test8();
//	test10();
//	test11();
	test12();
	return 0;
}

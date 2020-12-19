/*

const int a;
int const a;

常量指针
const int *p;
int const *p;

指针常量
int *const p;

既是常量指针又是指针常量
const int *const p;

*/


#include <stdio.h>


int main()
{
	const float pi = 3.14;
// 定义指针指向const常量，也需要加const
	const float *p = &pi;
	
//	*p = 3.14159;
	
	printf("pi = %f\n", pi);


	int i = 1;
	const int *p1 = &i;

// i 还是常量
//T	i = 10;
//F *p = 10;
	

	int j = 100;
// 常量指针的指向可以发生变化
	p1 = &j;

	printf("*p1 = %d\n", *p1);

//指针常量

	int * const p2 = &i;

//T	*p2 = 100;
// 指针的指向不能发生变化
//F	p2 = &j; 
	printf("*p2 = %d\n", *p2);

// const int * const p

	const int * const p3 = &i;

//常量指针常量 -- 指向不能发生变化，指向的内容也不能发生变化
//F	*p3 = 100;
//F	p3 = &j;
	printf("*p3 = %d\n", *p3);


	return 0;

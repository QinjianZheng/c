#include <stdio.h>
#define ROW 2
#define COL 3

int main()
{
	int a[ROW][COL] = {1,2,3,4,5,6};
	
	int *p = *a; // a是指向第一行的指针，*a是指向第一行第一列元素的指针
	// *p =&a[0][0];
	
	int (*q)[COL] = a; // 数组指针定义的[下标]应与二维数组的第二维的大小相等

	printf("a = %p, a+1 = %p\n", a, a+1);	
	printf("q = %p, q+1 = %p\n", q, q+1);
	for(int i = 0; i < ROW; i++)
	{
		
		for(int j = 0; j < COL; j++)
		{
			printf("&a[i][j]: %p -> %d\n", &a[i][j], a[i][j]);
			printf("p+j: %p -> %d\n", p+j, p[j]);
			printf("*(q+i)+j: %p -> %d\n", *(q+i)+j, *(*(q+i)+j));
			printf("\n");
		}
	printf("\n");
	p = *(a+1);
	}

	

	return 0;
}

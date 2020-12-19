#include <stdio.h>
#define M		2
#define N		3


static void transpose()
{
    int a[M][N] = {1,2,3,4,5,6}, b[N][M];
    int i,j;


	printf("a数组：\n");
    for(i = 0; i < M; i++)
    {
        for(j = 0; j < N; j++)
        {
            printf("%d ", a[i][j]);
			b[j][i] = a[i][j];
        }
        printf("\n");
    }
	printf("b数组：\n");
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < M; j++)
			printf("%d ", b[i][j]);
		printf("\n");
	}
}

static void max(void)
{
	int a[M][N]  = {234,3,35,6532,1,2322};
	int i,j;
	int max = a[0][0], row = 0, column = 0;
	
	for(i = 0; i < M; i++)
	{
		for(j = 0; j < N; j++)
		{
			if(max < a[i][j])
			{
				max = a[i][j];
				row = i;
				column = j;
			}
		}
	}
	
	printf("max: a[%d][%d] = %d\n", i, j, max);

}
// 求各行各列的和
static void sum(void)
{
	const int row = 5;
	const int col = 4;

	int a[row][col] = {{1,1,1},{1,1,1},{1,1,1},{1,1,1}};
	int i,j;

	for(i = 0; i < row - 1; i++)
	{		

		for(j = 0; j < col - 1; j++)
		{
			a[row-1][col-1] += a[i][j];
			a[row-1][j] += a[i][j];
			a[i][col-1] += a[i][j];
		
		} 

	}
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}


}

static void matrix_mul(void)
{
	const int a_row = 2;
	const int a_col = 3;
	const int b_row = 3;
	const int b_col = 2;

	int a[a_row][a_col] = {1,2,3,4,5,6};
	int b[b_row][b_col] = {1,0,0,1,1,0};
	int c[a_row][b_col] = {0};

	int i,j,k;
	
	for(i = 0; i < a_row; i++)
	{
		for(j = 0; j < b_col; j++)
		{
			for(k = 0; k < a_col; k++)
				c[i][j] += a[i][k] * b[k][j];
		}
	
	}
	for(i = 0; i < a_row; i++)
	{
		for(j = 0; j < b_col; j++)
			printf("%d ", c[i][j]);

		printf("\n");
	}

}


int main()
{

	int a[M][N] = {1,2,3,4,5,6};
	int i,j;

	printf("a = %p\n", a);
	printf("a[0]: %p\n", a[0]);
	printf("a + 1 = %p\n", a+1);
	printf("a[1] = %p\n", a[1]);


#if 0
	for(i = 0; i < M; i++)
		for(j = 0; j < N; j++)
			scanf("%d", &a[i][j]);
	printf("a = %p\n", a);
#endif

#if 0
	for(i = 0; i < M; i++)
	{
		for(j = 0; j < N; j++)
		{
			printf("%d ", a[i][j]); 
		}
		printf("\n");
	}
#endif


//	transpose();
//	max();	
//	sum();
//	matrix_mul();

	return 0;
}



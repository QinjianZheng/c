#include <stdio.h>
#define M 3
#define N 4

//void print_douarr(int (*p)[N], int m, int n)
void print_douarr(int p[][N], int m, int n)
{
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		//	printf("%4d", p[i][j]);
			printf("%4d", *(*(p+i)+j));
		printf("\n");
	}

}

void print_singlearr(int *p, int n)
{
	for(int i = 0; i < n; i++)
		printf("%d ", p[i]);
	printf("\n");

}

// find the average value
float find_avearge(int *p, int n)
{
	int sum = 0;
	float average;

	for(int i = 0; i < n; i++)
		sum += p[i];
	
	average = sum / n;

	return average;
}
// find the values in a specified row and print the row

void print_row(int (*p)[N], int row)
{
	for(int i = 0; i < N; i++)
	{
		printf("%d ", *(*(p+row)+i)); 
	}
	printf("\n");
}

// find the row 

int * find_row(int (*p)[N], int row)
{
	if(row > M - 1)
		return NULL;
	return *(p+row);
}


int main()
{
	int a[M][N] = {1,2,3,4,5,6,7,8,9,10,11,12};
	int row = 3;
	int *res;
	printf("Print the grid as a single array:\n");
	print_singlearr(*a, M*N);
	
	printf("Print the grid as a 2-dimension array:\n");
	print_douarr(a, M, N);

	printf("The average value is %.2f\n", find_avearge(*a, M*N));

	res = find_row(a, row);
	if(res != NULL)
	{
		print_singlearr(res, N);
	}
	else
		printf("Not found!\n");
	return 0;
}

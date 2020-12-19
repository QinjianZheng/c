#include <stdio.h>
#define M 3
#define MONTHS 12
#define FIBSIZE 10

static void bubbleSort(void)
{
	int a[] = {5,7,6,8,9,2,1,4,3};
	int i,j,k,temp,flag;

	printf("Before the sort\n");
    for(i = 0; i < sizeof(a)/sizeof(a[0]); i++)
        printf("%d ", a[i]);
    printf("\n");

	printf("Start sorting\n");	

	for(i = 0; i < sizeof(a)/sizeof(a[0]) - 1; i++)
	{
		flag = 0;		
//		printf("Carry %d for sorting\n", a[0]);
		printf("\nSorting time: %d\n", i);

		for(j = 0; j < sizeof(a)/sizeof(a[0])- 1 - i; j++)
		{	
			printf("\n");
			printf("Comparing %d and %d\n", a[j], a[j+1]);
			
			if(a[j] > a[j+1])
			{

				printf("%d is greater than %d\n", a[j], a[j+1]);
                printf("Exchange the positions of %d and %d\n", a[j], a[j+1]);
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				flag = 1;				
			} else
			{
				printf("%d is not greater than %d\n", a[j], a[j+1]);
				printf("Keep the order.\n");
			}

        	printf("Current list is: ");
        	for(k = 0; k < sizeof(a)/sizeof(a[0]); k++)
           	{	
				printf("%d ", a[k]);
			}
    	    printf("\n");

		}
		if(flag == 0)
        {	
            printf("We have finished the bubble sort.\n");
            break;
        }
	}
	printf("After the sort\n");
	for(i = 0; i < sizeof(a)/sizeof(a[0]); i++)
		printf("%d ", a[i]);
	printf("\n");

}

static void fib(void)
{
	int i,j,temp;
	int fib[FIBSIZE] = {1,1};
	
	for(i = 2; i < FIBSIZE; i++)
	{
		fib[i] = fib[i-1] + fib[i-2];

	}

	printf("Fibonacci List:\n");

	for(i = 0; i < FIBSIZE; i++)
	{
		printf("%d ", fib[i]);
	}
	printf("\n");	

	i = 0;
	j = FIBSIZE - 1;

	while(i < j)
	{
		temp = fib[i];
		fib[i] = fib[j];
		fib[j] = temp;
		i ++;
		j --;
	}

	printf("FIbonacci Reversed List:\n");

    for(i = 0; i < FIBSIZE; i++)
    {
        printf("%d ", fib[i]);
    }
	printf("\n");
}



int main()

{
	bubbleSort();
/*
	fib();
	int i;
	int days[MONTHS] = {31, 28, [4]=31, 30, 31, [1] = 29};
	int arr[M];
	int arr2[] = {1,2,3,4,5,6,[10]=10};	
	

	printf("%lu\n", sizeof(arr));
	printf("arr = %p\n", arr);	

	for(i = 0; i < sizeof(arr2)/sizeof(arr2[0]); i++)
		printf("%d ", arr2[i]); 
	printf("\n");

	for(i = 0; i < M; i++)
	{
		scanf("%d", &arr[i]);
	}	

	for(i = 0; i < MONTHS; i++)
	{
		printf("%2d %d\n", i+1, days[i]);
	}


	for(i = 0; i < M; i++)
	{
		printf("%p -> %d\n", &arr[i], arr[i]);

	}	
*/
	return 0;
}

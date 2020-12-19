#include <stdio.h>

static void selectionSort(int a[], int n)
{
	int i,j,k,temp;

	printf("Before the sort\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    printf("Start sorting\n");
    for(i = 0; i < n - 1; i++)
    {
        printf("\nSorting time: %d\n", i+1);

		int lowindex = i;

        for(j = i + 1; j < n; j++)
        {
            printf("\n");
            printf("Comparing %d and %d\n", a[j], a[lowindex]);

            if(a[j] < a[lowindex])
            {

                printf("%d is less than %d\n", a[j], a[lowindex]);
                printf("Let %d be the local minimum instead of %d\n", a[j], a[lowindex]);
                lowindex = j;
            } else
            {
                printf("%d is not less than %d\n", a[j], a[lowindex]);
                printf("%d is still the local minimum.\n", a[lowindex]);
            }
		}
		if(i != lowindex)
		{
			printf("%d is the minimum, move it to position %d.\n", a[lowindex],i);
			temp = a[i];
			a[i] = a[lowindex];
			a[lowindex] = temp;
		} else
		{
			printf("%d is already the minimum, keep the order.\n", a[i]);
		}
		printf("Current list is: ");
		for(k = 0; k < n; k++)
		{
				printf("%d ", a[k]);
		}
		printf("\n");
	}
	printf("After the sort\n");
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}


int main()
{
	int a[] = {5,7,6,8,9,2,1,4,3};
	selectionSort(a, sizeof(a)/sizeof(a[0]));

}

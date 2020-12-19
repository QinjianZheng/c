#include <stdio.h>

static void bubbleSort(int a[], int n)
{
   int i,j,k,temp,flag;

    printf("Before the sort\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    printf("Start sorting\n");

    for(i = 0; i < n - 1; i++)
    {
        flag = 0;
//      printf("Carry %d for sorting\n", a[0]);
        printf("\nSorting time: %d\n", i+1);

        for(j = 0; j < n - 1 - i; j++)
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
            for(k = 0; k < n; k++)
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
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

}

int main()
{
//	This is the bubble sort method

	int a[] = {5,7,6,8,9,2,1,4,3};
	bubbleSort(a, sizeof(a)/sizeof(a[0]));

}

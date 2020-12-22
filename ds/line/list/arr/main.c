#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"

int main(int argc, char const *argv[])
{
    sqlist *list = NULL, *list1 = NULL;
    datatype arr[] = {1,2,3,4,5};
    datatype arr1[] = {8,9,3,4,5,6,7};
    int i, err;
    // list = sqlist_create();
    sqlist_create1(&list);
    if(list == NULL)
    {
        fprintf(stderr, "sqlist_create1() failed!\n");
        exit(1);
    }

    for(i = 0; i < sizeof(arr)/sizeof(*arr); i++)
    {
        if((err = sqlist_insert(list, i, &arr[i])) != 0)
        {
            if(err == -1)
                fprintf(stderr, "The array is full.\n");
                else if (err == -2)
                    fprintf(stderr, "The position is inaccessible.\n");
                        else
                            fprintf(stderr, "Error!\n");
            exit(1);
        }

    }

    sqlist_display(list);

    printf("where is 4: %d\n", sqlist_find(list, &arr[3]));

    sqlist_delete(list, 0);

    sqlist_display(list);

    printf("where is 4: %d\n", sqlist_find(list, &arr[3]));

    list1 = sqlist_create();
    if(list1 == NULL)
    {
        fprintf(stderr, "sqlist_create() failed!\n");
        exit(1);
    }

    for(i = 0; i < sizeof(arr1)/sizeof(*arr1); i++)
    {
        if((err = sqlist_insert(list1, i, &arr1[i])) != 0)
        {
            if(err == -1)
                fprintf(stderr, "The array is full.\n");
                else if (err == -2)
                    fprintf(stderr, "The position is inaccessible.\n");
                        else
                            fprintf(stderr, "Error!\n");
            exit(1);
        }
    }
    sqlist_display(list1);

    sqlist_union(list, list1);
    
    sqlist_display(list);

    sqlist_destroy(list);
    sqlist_destroy(list1);

    return 0;
}


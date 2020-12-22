#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char const *argv[])
{
    link_node *list;
    datatype arr[] = {1,3,4,7,2,5};
    
    list = list_create();
    int value = 3;
    int err;
    int value2 = 5;
    if(list == NULL)
        exit(1);
    
    for(int i = 0; i < sizeof(arr)/ sizeof(*arr); i++)
    {
        //if(list_insert_at(list, i, &arr[i]))
        if(list_insert_order(list, &arr[i]))
            exit(1);
    }

    list_display(list);


    list_delete(list, &value);

    list_display(list);

    datatype deleted_value;
    
    err = list_delete_at(list, 2, &deleted_value);

    if(err != 0)
    {
        exit(1);
    }
    list_display(list);
    printf("delete: %d\n", deleted_value);

    list_isinlist(list, &value2);

    list_isinlist(list, &value);

    printf("detroying...\n");
    list_destroy(list);

    return 0;
}
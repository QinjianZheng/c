#include <stdio.h>
#include <stdlib.h>
#include "nohead_linklist.h"

int main(int argc, char const *argv[])
{
    int i;
    nhlist *nh_list = NULL;
    score temp;
    int ret;
    score *ret_find;

    for(i = 0; i < 7; i++)
    {
        temp.id = i;
        snprintf(temp.name, NAMESIZE, "stu%d", i);
        temp.math = rand() % 100;
        temp.chinese = rand() % 100;

        ret = nhlist_insert(&nh_list, &temp);
        if(ret != 0)
            return -1;
    }
    nhlist_display(nh_list);
    printf("Deleting the first element\n");
    nhlist_delete(&nh_list);
    nhlist_display(nh_list);
    
    ret_find = nhlist_find(nh_list, 3);

    if(ret_find == NULL)
    {
        printf("Not found!\n");
    }
    else
    {
        printf("student %d info:\n", (*ret_find).id);
        printf("id = %d\n", (*ret_find).id);
        printf("name = %s\n", (*ret_find).name);
        printf("math = %d\n", (*ret_find).math);
        printf("chinese = %d\n", (*ret_find).chinese);
    }

    nhlist_destroy(nh_list);
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "nohead_linklist.h"

//从头部插入
// nhlist * nhlist_insert(nhlist *me, score *data)
//使用二级指针传参，
int nhlist_insert(nhlist **me, score *data)
{
    nhlist *node;
    node = malloc(sizeof(*node));
    if(node == NULL)
        // return NULL;
        return -1;
    node->data = *data;
    // node->next = NULL;

    node->next = *me;
    *me = node;

    // return me;
    return 0;
}

void nhlist_display(nhlist *me)
{
    nhlist *node;
    for(node = me; node != NULL; node = node->next)
    {
        printf("%d %s %d %d\n", node->data.id, node->data.name, node->data.math, node->data.chinese);
    }
    printf("\n");
}

//从第一个结点开始删除

int nhlist_delete(nhlist **me)
{
    nhlist *node;
    if(*me == NULL)
        return -1;
    node = *me;
    *me = (*me)->next;
    free(node);
    return 0;
}

// int nhlist_find(nhlist *me, int id)
score * nhlist_find(nhlist *me, int id)
{
    nhlist *node;
    for(node = me; node != NULL; node = node->next)
    {
        if(node->data.id == id)
            return &node->data;
    }
    return NULL;
}

void nhlist_destroy(nhlist *me)
{
    nhlist *node = me;
    if(me == NULL)
        return;
    // for(node = me; node != NULL; node = me)
    // {
    //     me = node->next;
    //     free(node);
    // }
    while(node != NULL)
    {
        me = node->next;
        free(node);
        node = me;
    }
}
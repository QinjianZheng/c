#include <stdio.h>
#include <stdlib.h>
#define JOSE_NR 8
/*
无头单向环链例子展示，约瑟夫算法
*/
struct node_st
{
    int data;
    struct node_st *next;
};

struct node_st * jose_create(int n)
{
    int i = 1;
    struct node_st *me, *new_node, *cur;
    // 初始化第一个结点
    me = malloc(sizeof(*me));
    if(me == NULL)
        return NULL;
    me->data = i;
    me->next = me;
    cur = me;
    i++;

    for(; i <= n; i++)
    {
        new_node = malloc(sizeof(*new_node));
        if(new_node == NULL)
            return NULL;
        new_node->data = i;
        new_node->next = me;
        cur->next = new_node;
        // cur = new_node;
        cur = cur->next;

    }
    return me;
}

void jose_show(struct node_st *me)
{
    struct node_st *cur;
    for(cur = me; cur->next != me; cur = cur->next)
    {
        printf("%d ", cur->data);
    }
    printf("%d\n", cur->data);
}

void jose_kill(struct node_st **me, int n)
{
    struct node_st *cur = *me, *node;
    int i = 1;
    while(cur != cur->next)
    {
        while(i < n)
        {
            node = cur;
            cur = cur->next;
            i++;
        }
        node->next = cur->next;
        printf("delete: %d\n", cur->data);
        free(cur);
        cur = node->next;
        i = 1;
    }
    *me = cur;
}

int main(int argc, char const *argv[])
{
    struct node_st *list;
    int n = 3;
    list = jose_create(JOSE_NR);
    jose_show(list);
    jose_kill(&list, n);
    jose_show(list);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

link_node *list_create()
{
    link_node *me;
    me = malloc(sizeof(*me));
    if(me == NULL)
        return NULL;
    
    me->next = NULL;

    return me;
}

int list_isempty(link_node *me)
{
    if(me->next == NULL)
        return 0;
    return -1;
}

void list_destroy(link_node *me)
{
    link_node *node, *next;
    for(node = me->next; node != NULL; node = next)
    {
        next = node->next;
        free(node);
    }
    free(me);
    return;
}

int list_isinlist(link_node *me, datatype *data)
{
    link_node *node;
    if(list_isempty(me) == 0)
    {
        fprintf(stderr, "Linked list is empty!\n");
        return -1;
    }
    for(node = me; node->next && node->next->data != *data; node = node->next)
        ;
    if(node->next)
    {
        printf("%d is in the list.\n", *data);
        return 0;
    }
    else
    {
        fprintf(stderr, "%d not found!\n", *data);
        return -2;
    }    
}

int list_insert_at(link_node *me, int i, datatype *data)
{
    int j;
    link_node *node = me, *new_node;
    if(i < 0)
    {
        return -1;
        // return -EINVAL;
    }
    for(j = 0; j < i && node != NULL; j++)
    {
        node = node->next;
    }
    if(node)
    {
        new_node = malloc(sizeof(*new_node));
        if(new_node == NULL)
            return -2;
        new_node->data = *data;
        // new_node->next = NULL;
        new_node->next = node->next;
        node->next = new_node;
        return 0;
    }
    else
        return -3;

}

int list_insert_order(link_node *me, datatype *data)
{
    link_node *p = me, *q;
    
    while(p->next && p->next->data < *data)
    {
        p = p->next;
    }
    q = malloc(sizeof(*q));
    if(q == NULL)
        return -1;
    
    q->data = *data;
    q->next = p->next;
    p->next = q;
    return 0;
}

int list_delete_at(link_node *me, int i, datatype *data)
{
    int j = 0;
    if(i < 0)
        return -1;
    link_node *p = me, *q;
    *data = -1;
    while(j < i && p)
    {
        p = p->next;
        j++;
    }
    if(p)
    {
        q = p->next;
        p->next = q->next;
        *data = q->data;
        free(q);
        q = NULL;
        return 0;
    }
    else
    {
        return -2;
    }
    
}

int list_delete(link_node *me, datatype *data)
{
    link_node *p, *q;
    for(p = me->next; p->next && p->next->data != *data; p = p->next)
        ;
    if(p->next == NULL)
        return -1;
    else
    {
        q = p->next;
        p->next = q->next;
        free(q);
        q = NULL;
        return 0;
    }
}




void list_display(link_node *me)
{
    link_node *node = me->next;
    if(list_isempty(me) == 0)
    {
        fprintf(stderr, "Linked list is empty.\n");
        return;
    }
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    return;
}

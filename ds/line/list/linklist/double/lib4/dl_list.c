#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dl_list.h"

typedef struct dl_list_node_st
{
    struct dl_list_node_st *prev;
    struct dl_list_node_st *next;
    char data[0];
} NODE;

struct dl_list_head_st
{
    int size;
    struct dl_list_node_st head;
};

DL_LIST * dl_list_create(int init_size)
{
    struct dl_list_head_st *new;
    new = malloc(sizeof(*new));
    if(new == NULL)
        return NULL;
    new->size = init_size;
    new->head.prev = &new->head;
    new->head.next = &new->head;
    return new;
}

int dl_list_insert(DL_LIST *ptr, const void *data, int mode)
{
    NODE *new_node;
    struct dl_list_head_st *me = ptr;
    new_node = malloc(sizeof(*new_node)+me->size);
    if(new_node == NULL)
        return -1;
    memcpy(new_node->data, data, me->size);

    if(mode == DL_LIST_FORWARD)
    {
        new_node->prev = &me->head;
        new_node->next = me->head.next;
    }
    else if(mode == DL_LIST_BACKWARD)
    {
        new_node->prev = me->head.prev;
        new_node->next = &me->head;
    }
    else // error
        return -3;
    new_node->prev->next = new_node;
    new_node->next->prev = new_node;
    return 0;
}


static NODE * find_(struct dl_list_head_st *me, const void *key, dl_list_cmp *cmp)
{
    NODE *cur;
    for(cur = me->head.next; cur != &me->head; cur = cur->next)
    {
        if(cmp(key, cur->data) == 0)
            break;
    }
    // 如果没有找到，那么就返回头结点
    return cur;
}

void *dl_list_find(DL_LIST *ptr, const void *key, dl_list_cmp *cmp)
{
    NODE *node;
    struct dl_list_head_st *me = ptr;
    node = find_(me, key, cmp);
    if(node == &me->head)
        return NULL;
    return node->data;
}

int dl_list_fetch(DL_LIST *ptr, const void *key, dl_list_cmp *cmp, void *data)
{
    NODE *node;
    struct dl_list_head_st *me = ptr;
    node = find_(me, key, cmp);
    if(node == &me->head)
    {
        return -1;
    }
    node->prev->next = node->next;
    node->next->prev = node->prev;
    if(data != NULL)
        memcpy(data, node->data, me->size);
    free(node);
    return 0;
}

int dl_list_delete(DL_LIST *ptr, const void *key, dl_list_cmp *cmp)
{
    NODE *node;
    struct dl_list_head_st *me = ptr;
    node = find_(me, key, cmp);
    if(node == &me->head)
    {
        return -1;
    }
    node->prev->next = node->next;
    node->next->prev = node->prev;
    free(node);
    return 0;
}


void dl_list_display(DL_LIST *ptr, dl_list_op *op)
{
    NODE *cur;
    struct dl_list_head_st *me = ptr;
    for(cur = me->head.next; cur != &me->head; cur = cur->next)
    {
        op(cur->data);
    }
}

void dl_list_destroy(DL_LIST *ptr)
{
    NODE *cur, *next;
    struct dl_list_head_st *me = ptr;
    for(cur = me->head.next; cur != &me->head; cur = next)
    {
        next = cur->next;
        free(cur);
    }
    free(me);
}
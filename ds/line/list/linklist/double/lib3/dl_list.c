#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dl_list.h"

int dl_list_insert(DL_LIST *, const void *, int);
void * dl_list_find(DL_LIST *, const void *key, dl_list_cmp *);
int dl_list_fetch(DL_LIST *, const void *key, dl_list_cmp *, void *);
int dl_list_delete(DL_LIST *, const void *key, dl_list_cmp *);
void dl_list_display(DL_LIST *, dl_list_op *);

// 使用回调函数传入函数

DL_LIST * dl_list_create(int init_size)
{
    DL_LIST *new;
    new = malloc(sizeof(*new));
    if(new == NULL)
        return NULL;
    new->size = init_size;
    new->head.prev = &new->head;
    new->head.next = &new->head;
    new->insert = dl_list_insert;
    new->delele = dl_list_delete;
    new->find = dl_list_find;
    new->fetch = dl_list_fetch;
    new->display = dl_list_display;
    return new;
}

int dl_list_insert(DL_LIST *me, const void *data, int mode)
{
    NODE *new_node;
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


static NODE * find_(DL_LIST *me, const void *key, dl_list_cmp *cmp)
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

void *dl_list_find(DL_LIST *me, const void *key, dl_list_cmp *cmp)
{
    NODE *node;
    node = find_(me, key, cmp);
    if(node == &me->head)
        return NULL;
    return node->data;
}

int dl_list_fetch(DL_LIST *me, const void *key, dl_list_cmp *cmp, void *data)
{
    NODE *node;
    
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

int dl_list_delete(DL_LIST *me, const void *key, dl_list_cmp *cmp)
{
    NODE *node;
    
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


void dl_list_display(DL_LIST *me, dl_list_op *op)
{
    NODE *cur;
    for(cur = me->head.next; cur != &me->head; cur = cur->next)
    {
        op(cur->data);
    }
}

void dl_list_destroy(DL_LIST *me)
{
    NODE *cur, *next;
    for(cur = me->head.next; cur != &me->head; cur = next)
    {
        next = cur->next;
        free(cur);
    }
    free(me);
}
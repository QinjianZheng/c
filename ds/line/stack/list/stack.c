#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "dl_list.h"

STACK * stack_create(int init_size)
{
   return dl_list_create(init_size);
}

int stack_push(STACK *ptr, const void *data)
{
    return dl_list_insert(ptr, data, DL_LIST_FORWARD);
}

static int always_match(const void *p1, const void *p2)
{
    return 0;
}

int stack_pop(STACK *ptr, void *data)
{

    return dl_list_fetch(ptr, (void *)0, always_match, data);
}

void stack_destroy(STACK *ptr)
{
    dl_list_destroy(ptr);
}
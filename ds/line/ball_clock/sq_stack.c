#include <stdio.h>
#include <stdlib.h>
#include "sq_stack.h"

STACK *st_create(void)
{
    STACK *st;
    st = malloc(sizeof(*st));
    if(st == NULL)
        return NULL;
    
    st->top = -1;
    return st;
}

int st_isempty(STACK *st)
{
    return (st->top == -1);
}

int st_push(STACK *st, datatype_stack *data)
{
    if(st->top == (MAXSIZE_STACK-1))
        return -1;
    
    st->data[++st->top] = *data;
    return 0;
}

int st_pop(STACK *st, datatype_stack *data)
{
    if(st_isempty(st))
        return -1;

    *data = st->data[st->top];
    st->top--;
    return 0;
}

int st_top(STACK *st, datatype_stack *data)
{
    if(st_isempty(st))
        return -1;
    *data = st->data[st->top];
    return 0;
}

void st_display(STACK *st)
{
    if(st_isempty(st))
        return;
    for(int i = 0; i <= st->top; i++)
    {
        printf("%d ", st->data[i]);
    }
    printf("\n");
}

void st_destroy(STACK *st)
{
    free(st);
}
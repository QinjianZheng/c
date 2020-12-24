#include <stdio.h>
#include <stdlib.h>
#include "sq_stack.h"

sq_stack *st_create(void)
{
    sq_stack *st;
    st = malloc(sizeof(*st));
    if(st == NULL)
        return NULL;
    
    st->top = -1;
    return st;
}

int st_isempty(sq_stack *st)
{
    return (st->top == -1);
}

int st_push(sq_stack *st, datatype *data)
{
    if(st->top == (MAXSIZE-1))
        return -1;
    
    st->data[++st->top] = *data;
    return 0;
}

int st_pop(sq_stack *st, datatype *data)
{
    if(st_isempty(st))
        return -1;

    *data = st->data[st->top];
    st->top--;
    return 0;
}

int st_top(sq_stack *st, datatype *data)
{
    if(st_isempty(st))
        return -1;
    *data = st->data[st->top];
    return 0;
}

void st_display(sq_stack *st)
{
    if(st_isempty(st))
        return;
    for(int i = 0; i <= st->top; i++)
    {
        printf("%d ", st->data[i]);
    }
    printf("\n");
}

void st_destroy(sq_stack *st)
{
    free(st);
}
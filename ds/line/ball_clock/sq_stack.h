#ifndef STACK_H__
#define STACK_H__

#define MAXSIZE_STACK 11
typedef int datatype_stack;

typedef struct
{
    datatype_stack data[MAXSIZE_STACK];
    int top;
} STACK;

STACK *st_create(void);

int st_isempty(STACK *);

int st_push(STACK *, datatype_stack *);

int st_pop(STACK *, datatype_stack *);

int st_top(STACK *, datatype_stack *);

void st_display(STACK *);

void st_destroy(STACK *);

#endif
#ifndef SQ_STACK_H__
#define SQ_STACK_H__

#define MAXSIZE 32

typedef int datatype;

typedef struct
{
    datatype data[MAXSIZE];
    int top;
} sq_stack;

sq_stack *st_create(void);

int st_isempty(sq_stack *);

int st_push(sq_stack *, datatype *);

int st_pop(sq_stack *, datatype *);

int st_top(sq_stack *, datatype *);

void st_display(sq_stack *);

void st_destroy(sq_stack *);

#endif
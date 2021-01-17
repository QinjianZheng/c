#ifndef STACK_H__
#define STACK_H__
#include <stdbool.h>
#include "dl_list.h"


typedef DL_LIST STACK;


STACK * stack_create(int);

int stack_push(STACK *, const void *);

int stack_pop(STACK *, void *);

void stack_destroy(STACK *);

bool stack_isempty(STACK *);

#endif
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define NAMESIZE 32

typedef struct score_st
{
    int id;
    char name[NAMESIZE];
    int math;
    int chinese;
} SCORE;

static void print_score(void *record)
{
    SCORE *r = record;
    printf("%d %s %d %d\n", r->id, r->name, r->math, r->chinese);
}

int main(int argc, char const *argv[])
{
    STACK *st;
    SCORE data;

    st = stack_create(sizeof(SCORE));
    if(st == NULL)
        exit(1);

    for(int i = 0; i < 7; i++)
    {
        data.id = i;
        snprintf(data.name, NAMESIZE, "std%d", i);
        data.math = rand()%100;
        data.chinese = rand()%100;
        if(stack_push(st, &data))
            exit(1);
    }
    while(stack_pop(st, &data) == 0)
    {
        print_score(&data);
    }

    stack_destroy(st);
    return 0;
}

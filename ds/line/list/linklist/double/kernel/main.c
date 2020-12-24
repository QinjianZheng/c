#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#define NAMESIZE    32

struct score_st
{
    int id;
    char name[NAMESIZE];
    struct list_head node;
    int math;
    int chinese;

};

static void print_score(struct score_st *d)
{
    printf("%d %s %d %d\n", d->id, d->name, d->math, d->chinese);
}

int main(int argc, char const *argv[])
{
    struct score_st *datap;
    struct list_head *cur;

    LIST_HEAD(head);
    
    // struct list_head head = LIST_HEAD_INIT(head);
    // struct list_head head = {&(head), &(head)};
    for(int i = 0; i < 7; i++)
    {
        datap = malloc(sizeof(*datap));
        if(datap == NULL)
            exit(1);
        datap->id = i;
        snprintf(datap->name, NAMESIZE, "std%d", i);
        datap->math = rand() % 100;
        datap->chinese = rand() % 100;

        list_add(&datap->node, &head);
    }

    list_for_each(cur, &head)
    {
        datap = list_entry(cur, struct score_st, node);
        print_score(datap);
    }

    list_for_each(cur, &head)
    {
        datap = list_entry(cur, struct score_st, node);
        if(datap->id == 15)
            break;
    }
    if(cur == &head)
        printf("Not found!\n");
    else
        print_score(datap);


    return 0;
}

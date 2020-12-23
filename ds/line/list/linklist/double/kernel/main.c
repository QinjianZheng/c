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

int main(int argc, char const *argv[])
{
    struct score_st *datap;
    LIST_HEAD(head);
    for(int i = 0; i < 7; i++)
    {
        datap = malloc(sizeof(*datap));
        if(datap == NULL)
            exit(1);
        datap->id = i;
        snprintf(datap->name, NAMESIZE, "std%d", i);
        datap->math = rand() % 100;
        datap->chinese = rand() % 100;
    }

    return 0;
}

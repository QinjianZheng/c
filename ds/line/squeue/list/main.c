#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

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
    QUEUE *qu;
    SCORE *data;
    int i;
    qu = queue_create(sizeof(SCORE));
    if(qu == NULL)
        exit(1);
    for(i = 0; i < 7; i++)
    {
        data = malloc(sizeof(*data));
        data->id = i;
        snprintf(data->name, NAMESIZE, "std%d", i);
        data->math = rand()%100;
        data->chinese = rand()%100;
        if(queue_enqueue(qu, data) != 0)
        {
            printf("Trying to enter %dth element to the queue.\n", i);
            break;
        }
    }
    while(queue_dequeue(qu, data) == 0)
    {
        print_score(data);
    }
    
    queue_destroy(qu);
  

    return 0;
}

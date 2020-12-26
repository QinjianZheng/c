#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

QUEUE * q_create(void)
{
    QUEUE *qu;
    qu = malloc(sizeof(*qu));
    if(qu == NULL)
        return NULL;
    qu->head = 0;
    qu->tail = 0;
    return qu;
}

int q_isempty(QUEUE *qu)
{
    return (qu->head == qu->tail);
}


int q_enqueue(QUEUE *qu,datatype_queue *data)
{
    if((qu->tail+1)%MAXSIZE_QUEUE == qu->head)
        return -1;
    qu->tail = (qu->tail + 1) % MAXSIZE_QUEUE;
    qu->data[qu->tail] = *data;
    return 0;
}

int q_dequeue(QUEUE *qu, datatype_queue *data)
{
    if(q_isempty(qu))
        return -1;
    qu->head = (qu->head + 1) % MAXSIZE_QUEUE;
    *data = qu->data[qu->head];
    return 0;

}

void q_display(QUEUE *qu)
{
    int i;
    if(q_isempty(qu))
        return;
    for(i = (qu->head + 1) % MAXSIZE_QUEUE; i != qu->tail; )
    {
        printf("%d ", qu->data[i]);
        i = (i + 1) % MAXSIZE_QUEUE;
    }
    printf("%d\n", qu->data[i]);
}

int q_issame(QUEUE *qu_1, QUEUE *qu_2)
{
    int i;
    if((qu_1->head != qu_2->head) || (qu_1->tail != qu_2->tail))
        return 0;
    else
    {
        for(i = (qu_1->head + 1) % MAXSIZE_QUEUE; i != qu_1->tail; )
        {
            if(qu_1->data[i] != qu_2->data[i])
                return 0;
            i = (i + 1) % MAXSIZE_QUEUE;
            
        }
    }
    return 1;
}

void q_clear(QUEUE *qu)
{
    qu->head = qu->tail;
}

void q_destroy(QUEUE *qu)
{
    free(qu);
}
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


int q_enqueue(QUEUE *qu,datatype *data)
{
    if((qu->tail+1)%MAXSIZE == qu->head)
        return -1;
    qu->tail = (qu->tail + 1) % MAXSIZE;
    qu->data[qu->tail] = *data;
    return 0;
}

int q_dequeue(QUEUE *qu, datatype *data)
{
    if(q_isempty(qu))
        return -1;
    qu->head = (qu->head + 1) % MAXSIZE;
    *data = qu->data[qu->head];
    return 0;

}

void q_display(QUEUE *qu)
{
    int i;
    if(q_isempty(qu))
        return;
    for(i = (qu->head + 1) % MAXSIZE; i != qu->tail; )
    {
        printf("%d ", qu->data[i]);
        i = (i + 1) % MAXSIZE;
    }
    printf("%d\n", qu->data[i]);
}

void q_clear(QUEUE *qu)
{
    qu->head = qu->tail;
}

void q_destroy(QUEUE *qu)
{
    free(qu);
}
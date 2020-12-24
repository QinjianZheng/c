#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


QUEUE * queue_create(int init_size)
{
    return dl_list_create(init_size);
}

int queue_enqueue(QUEUE *qu, void *data)
{
    return dl_list_insert(qu, data, DL_LIST_BACKWARD);
}

int always_match(const void *p1, const void *p2)
{
    return 0;
}

int queue_dequeue(QUEUE *qu, void *data)
{
    return dl_list_fetch(qu, (void *)0, always_match, data);
}

void queue_destroy(QUEUE *qu)
{
    dl_list_destroy(qu);
}
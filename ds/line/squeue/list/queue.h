#ifndef QUEUE_H__
#define QUEUE_H__

#include "dl_list.h"

typedef DL_LIST QUEUE;

QUEUE * queue_create(int);

int queue_enqueue(QUEUE *, void *);

int queue_dequeue(QUEUE *, void *);

void queue_destroy(QUEUE *);




#endif
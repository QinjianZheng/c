#ifndef QUEUE_H__
#define QUEUE_H__

#define MAXSIZE_QUEUE 32
typedef int datatype_queue;


typedef struct 
{
    datatype_queue data[MAXSIZE_QUEUE];
    int head, tail;
} QUEUE;


QUEUE * q_create(void);

int q_isempty(QUEUE *);

int q_enqueue(QUEUE *,datatype_queue *);

int q_dequeue(QUEUE *, datatype_queue *);

void q_display(QUEUE *);

int q_issame(QUEUE *, QUEUE *);

void q_clear(QUEUE *);

void q_destroy(QUEUE *);



#endif
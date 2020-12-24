#ifndef QUEUE_H__
#define QUEUE_H__

#define MAXSIZE 5
typedef int datatype;


typedef struct 
{
    datatype data[MAXSIZE];
    int head, tail;
} QUEUE;


QUEUE * q_create(void);

int q_isempty(QUEUE *);

int q_enqueue(QUEUE *,datatype *);

int q_dequeue(QUEUE *, datatype *);

void q_display(QUEUE *);

void q_clear(QUEUE *);

void q_destroy(QUEUE *);



#endif
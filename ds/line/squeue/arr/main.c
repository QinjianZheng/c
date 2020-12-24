#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(int argc, char const *argv[])
{
    QUEUE *qu;
    datatype *data;
    int i;

    qu = q_create();

    for(i = 0; i < MAXSIZE; i++)
    {
        if(q_enqueue(qu, &i) == 0)
            printf("Enter %d\n", i);
        else
            printf("Queue is full!\n");
            // exit(1);
    }

    q_display(qu);
    
    data = malloc(sizeof(*data));
    q_dequeue(qu, data);
    printf("Dequeue %d\n", *data);

    for(i = 0 ; i < MAXSIZE; i++)
    {
        if(q_dequeue(qu, data) == 0)
            printf("Dequeue %d\n", *data);
        else
        {
            printf("Trying to dequeue %dth element\n", i);
            printf("Queue is empty\n");
        }       
    }

    for(i = 0; i < MAXSIZE; i++)
    {
        if(q_enqueue(qu, &i) == 0)
            printf("Enter %d\n", i);
        else
        {   
            printf("Trying to enter %d\n", i);
            printf("Queue is full!\n");
        }   // exit(1);
    }
    q_display(qu);
    q_dequeue(qu, data);
    q_enqueue(qu, &i);
    q_display(qu);


    q_destroy(qu);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "sq_stack.h"
#include "queue.h"

#define NR_BALL 27
#define MINUTE_PER_HOUR 60

int main(int argc, char const *argv[])
{
    STACK *st_min, *st_fivemin, *st_hour;
    QUEUE *qu, *qu_init;
    int ball, ball_temp;
    int time_minute = 0;
    int hour = 0, minute = 0, day = 0;
    qu = q_create();
    if(qu == NULL)
        exit(1);
    qu_init = q_create();
    if(qu_init == NULL)
        exit(1);
    st_min = st_create();
    if(st_min == NULL)
        exit(1);
    st_fivemin = st_create();
    if(st_fivemin == NULL)
        exit(1);
    st_hour = st_create();
    if(st_hour == NULL)
        exit(1);


    for(int i = 1; i <= NR_BALL; i++)
    {
        q_enqueue(qu_init, &i);
        q_enqueue(qu, &i);
    }
    q_display(qu);
    
    while(1)
    {
        
        q_dequeue(qu, &ball);
        time_minute++;
        hour = time_minute / MINUTE_PER_HOUR;
        minute = time_minute % MINUTE_PER_HOUR;

        if(st_min->top != 3)
        {
            st_push(st_min, &ball);
        }
        else
        {
            while(!st_isempty(st_min))
            {
                st_pop(st_min, &ball_temp);
                q_enqueue(qu, &ball_temp);
            }
            if (st_fivemin->top != 10)
            {
                st_push(st_fivemin, &ball);
            }
            else
            {
                while(!st_isempty(st_fivemin))
                {
                    st_pop(st_fivemin, &ball_temp);
                    q_enqueue(qu, &ball_temp);
                }
                if (st_hour->top != 10)
                {
                    st_push(st_hour, &ball);
                }
                else
                {
                    while (!st_isempty(st_hour))
                    {
                        st_pop(st_hour, &ball_temp);
                        q_enqueue(qu, &ball_temp);
                    }
                    q_enqueue(qu, &ball);
                    q_display(qu);
                    if(st_isempty(st_min) && st_isempty(st_fivemin) && st_isempty(st_hour))
                    {
                        printf("The time elapses 12:0\n");
                        printf("A day passed!\n");
                        time_minute = 0;
                        day++;
                    }
                    if(q_issame(qu, qu_init))
                    {
                        printf("The queue is back to start!\n");
                        break;
                    }
                }                
            }            
        }
        if(hour != 12)
            printf("The time elapses %d:%d\n", hour, minute);
    }
    printf("%d days have passed!\n", day/2);
    q_destroy(qu);
    st_destroy(st_min);
    st_destroy(st_fivemin);
    st_destroy(st_hour);

    return 0;
}
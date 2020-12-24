#include <stdio.h>
#include <stdlib.h>
#include "sq_stack.h"

int main(int argc, char const *argv[])
{
    int data;

    sq_stack *stack;

    stack = st_create();

    for(int i = 0; i < 5; i++)
    {
        st_push(stack, &i);
    }
    st_display(stack);

    while(st_pop(stack, &data)==0)
    {
        printf("%d\n", data);
    }

    if(st_top(stack, &data) == 0)
        printf("top: %d\n", data);

    if(st_pop(stack, &data) == 0)
        printf("pop: %d\n", data);

    if(st_top(stack, &data) == 0)
        printf("top: %d\n", data);

    st_display(stack);

    st_destroy(stack);


    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int *p = NULL;

    p = malloc(sizeof(int));

    if(p == NULL)
    {
        printf("malloc() error!\n");
        exit(1);
    }
    *p = 10;

    printf("%p -> %d\n", p, *p);
    free(p);

// 在free指针指向的内存空间后，直接用p会导致p变成野指针
    // *p = 123;
    p = NULL;
    
    printf("%p -> %d\n", p, *p);

    return 0;
}

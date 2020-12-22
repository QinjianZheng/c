#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
// 变长数组的实现
    int *p;
    int num = 5;
    int i;
    p = malloc(sizeof(int) *num);

    for (i = 0; i < num; i++)
    {
        scanf("%d", &p[i]);
    }
    for (i = 0; i < num; i++)
    {
        printf("%d ", p[i]);
    }
    printf("\n");
    free(p);
    return 0;
}

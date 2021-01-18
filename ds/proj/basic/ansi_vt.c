#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    printf("\033[2J\033[1;1H\033[41m  \033[0;36m world\n");
    return 0;
}
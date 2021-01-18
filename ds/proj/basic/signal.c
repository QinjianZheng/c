#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <termios.h>


void alrm_handler(int s)
{
    alarm(1);
    printf("Get SIGALRM\n");
}


void int_handler (int s)
{
    printf("Get SIGINT\n");
}

int main(int argc, char const *argv[])
{
    struct termios new, old;
    // signal(SIGINT, &int_handler);
    
    signal(SIGALRM, alrm_handler);
    alarm(5);

    tcgetattr(0, &old);
    /*if error*/
    tcgetattr(0, &new);
    /*if error*/
    // 取消终端回显
    new.c_lflag = new.c_lflag & ~(ICANON | ECHO);
    new.c_cc[VMIN] = 1;
    new.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &new);

    while(1)
    {
        printf("while(1)\n");
        sleep(1);
    }
    tcsetattr(0, TCSANOW, &old);
    return 0;
}

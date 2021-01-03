#include <stdio.h>
#include <stdlib.h>
#include <termios.h>

int main(int argc, char const *argv[])
{
    int ch;
    struct termios new, old;

    // 0:标准输入
    // 将终端标准输入的设置存放在old和new变量的指针中
    tcgetattr(0, &old);
    /*if error*/
    tcgetattr(0, &new);
    /*if error*/
    // 取消终端回显
    new.c_lflag = new.c_lflag & ~(ICANON | ECHO);
    new.c_cc[VMIN] = 1;
    new.c_cc[VTIME] = 0;
    // 确认设置
    tcsetattr(0, TCSANOW, &new);

    while(1)
    {
        ch = getchar();
        if(ch == 'Q')
            break;
        printf("%x ", ch);
        fflush(NULL);
    }
    // 恢复设置
    tcsetattr(0, TCSANOW, &old);

    return 0;
}

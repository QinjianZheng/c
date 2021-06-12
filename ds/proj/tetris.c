#include <stdio.h>
#include <unistd.h>
#include <termios.h>

void printTetromino(char arr[][4][9], int n, int x, int y) {
    int i;
    int color;
    switch (n)
    {
    case 0:
        color = 31;
        break;
    case 1:
        color = 32;
        break;
    case 2:
        color = 33;
        break;
    case 3:
        color = 34;
        break;
    case 4:
        color = 35;
        break;
    case 5:
        color = 36;
        break;
    case 6:
        color = 37;
        break;
    default:
        break;
    }
    for(i = 0; i < 4; i++, x++) {
        printf("\033[?25l\033[%d;%dH\033[0;%dm%s\n", x, y, color, arr[n][i]);
    }
}

void earase(int x, int y) {
    printf("\033[%d;%dH        \n", x, y);
}

// 小的二维数组在大的二维数组里移动
// 判断到底
// 判断碰撞
// 判断消除



int main(int argc, char const *argv[])
{
    int x = 10, y = 5;
    int i;
    struct termios new, old;
    // assets (Tetrominos)
    char tetrominos[7][4][9] = {
        {"[]######","[]######","[]######","[]######"}, 
        {"##[]####","##[][][]","########","########"},
        {"######[]","##[][][]","########","########"},
        {"########","##[][]##","##[][]##","########"},
        {"####[]##","##[][][]","########","########"},
        {"####[][]","##[][]##","########","########"},
        {"##[][]##","####[][]","########","########"}
    };

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
    printf("\033[2J"); // 清屏

    char frame[20][41];
    for(i = 0; i < 40; i++) {
        frame[0][i] = '=';
        frame[19][i] = '=';
    }
    frame[0][i] = '\0';
    frame[19][i] = '\0';
    for(i = 1; i < 19; i++) {
        frame[i][0] = '|';
        frame[i][1] = '|';
        for(int j = 2; j < 38; j++) {
            frame[i][j] = ' ';
        }
        frame[i][38] = '|';
        frame[i][39] = '|';
        frame[i][40] = '\0';
    }
    for(i = 0; i < 20; i++,x++) {
            printf("\033[%d;%dH%s\n", x, y, frame[i]);
    }




    // while(1) {
    //     earase(x, y);
    //     x++;
        
        
    //     printTetromino(tetrominos, 1, x, y);
        
    //     sleep(1);
    // }

    // 恢复设置
    tcsetattr(0, TCSANOW, &old);

    return 0;
}

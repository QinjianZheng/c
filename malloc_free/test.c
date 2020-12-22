#include <stdio.h>
#include <stdlib.h>


#if 0
// 这个函数中的p所获取的内存空间在函数返回时已经丢失地址
// 存在内存泄漏
void func(int *p, int n)
{
    p = malloc(n);
    if(p == NULL)
        exit(1); 
    return;
}
#endif

// 修改方法1
// 传入参数为指针

void func1(int **p, int n)
{
    p = malloc(n);
    if(p == NULL)
        exit(1);
    return;
}

// 修改方法2
// 函数返回值为指针

void *func2(int *p, int n)
{
    p = malloc(n);
    if(p == NULL)
        exit(1); 
    return p;
} 

int main(int argc, char const *argv[])
{
    int num = 100;
    int *p = NULL;
//    func(p, num);
    func1(&p, num);
    func2(p, num);
    free(p);
    return 0;
}

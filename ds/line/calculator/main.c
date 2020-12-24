#include <stdio.h>
#include <stdlib.h>
#include "sq_stack.h"

void compute(sq_stack *s_num, datatype *op)
{
    datatype n1, n2, n;
    st_pop(s_num, &n2);
    st_pop(s_num, &n1);
    switch (*op)
    {
        case '+':
            n = n1 + n2;
            break;
        case '-':
            n = n1 - n2;
            break;
        case '*':
            n = n1 * n2;
            break;
        case '/':
            n = n1 / n2;
            break;
        default:
            exit(1);
    }
    st_push(s_num, &n);
}

static void deal_bracket(sq_stack *s_num, sq_stack *s_op)
{
    datatype old_op;

    st_top(s_op, &old_op);
    while(old_op != '(')
    {
        st_pop(s_op, &old_op);
        compute(s_num, &old_op);
        st_top(s_op, &old_op);
    }
    st_pop(s_op, &old_op);
}

static int get_priority(int op)
{
    switch (op)
    {
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return -1;
            exit(1);
    }
}

static void deal_op(sq_stack *s_num, sq_stack *s_op, int op)
{
    datatype old_op;
    if(st_isempty(s_op) || op == '(')
    {
        st_push(s_op, &op);
        return ;
    }
    st_top(s_op, &old_op);
    if(get_priority(op) > get_priority(old_op))
    {
        st_push(s_op, &op);
        return;
    }
    while(get_priority(op) <= get_priority(old_op))
    {
        st_pop(s_op, &old_op);
        compute(s_num, &old_op);
        if(st_isempty(s_op))
            break;
        st_top(s_op, &old_op);
    }
    st_push(s_op, &op);
    
}

int main(int argc, char const *argv[])
{
    int i;
    char str[] = "(11+3)*2-5";
    int value = 0;
    int flag = 0;
    sq_stack *s_num, *s_op;
    datatype old_op;
    
    s_num = st_create();
    if(s_num == NULL)
        exit(1);
    s_op = st_create();
    if(s_op == NULL)
        exit(1);

    while(str[i] != '\0')
    {
        if(str[i] > '0' && str[i] < '9') // is a number
        {
            value = value * 10 + (str[i] - '0'); // 累加数字
            flag = 1;
        }
        else // is a operator
        {
            if(flag)
            {
                st_push(s_num, &value);
                flag = 0;
                value = 0;
            }

            if(str[i] == ')')
            {
                deal_bracket(s_num, s_op);
            }
            else // + - * / (
            {
                deal_op(s_num, s_op, str[i]);
            }
        }
        i++;
    }
    if(flag)
        st_push(s_num, &value);
    while(!st_isempty(s_op))
    {
        st_pop(s_op, &old_op);
        compute(s_num, &old_op);
    }

    st_display(s_num);
    
    st_destroy(s_num);
    st_destroy(s_op);

    return 0;
}

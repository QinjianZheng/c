#include <stdio.h>
#include <stdlib.h>

typedef struct poly_node_st
{
    int coef;
    int exp;
    struct poly_node_st *next;
} poly;

poly * poly_create(int a[][2], int n)
{
    poly *head;
    poly *new_node, *cur;
    int i;
    
    head = malloc(sizeof(*head));
    if(head == NULL)
        return NULL;
    head->next = NULL;
    cur = head;
    for(i = 0; i < n; i++)
    {
        new_node = malloc(sizeof(*new_node));
        if(new_node == NULL)
            return NULL;
        new_node->coef = a[i][0];
        new_node->exp = a[i][1];
        new_node->next = NULL;
        cur->next = new_node;
        cur = new_node;
    }

    return head;
}

void poly_show(poly *me)
{
    poly *cur;
    for(cur = me->next; cur != NULL; cur = cur->next)
    {
        printf("(%d %d) ", cur->coef, cur->exp);
    }
    printf("\n");
}

void poly_union(poly *p1, poly *p2)
{
    poly *node1;
    poly *node2;
    poly *cur;
    node1 = p1->next;
    node2 = p2->next;
    cur = p1;

    while(node1 && node2)
    {
        if(node1->exp < node2->exp)
        {
            cur->next = node1;
            cur = node1;
            node1 = node1->next;   
        }
        else if(node1->exp > node2->exp)
        {
            cur->next = node2;
            cur = node2;
            node2 = node2->next;
        }
        else
        {
            node1->coef += node2->coef;
            if(node1->coef)
            {
                cur->next = node1;
                cur = node1;
            }
            node1 = node1->next;
            node2 = node2->next;
        }
    }
    if(node1 == NULL)
        cur->next = node2;
    else
        cur->next = node1;
}

int main(int argc, char const *argv[])
{
    poly *p1;
    poly *p2;
    int a[][2] = {{5,0},{2,1},{8,8},{3,16}};
    int b[][2] = {{6,1}, {16,6}, {-8,8}};
    
    p1 = poly_create(a, sizeof(a)/sizeof(*a));
    if(p1 == NULL)
        exit(1);
    p2 = poly_create(b, sizeof(b)/sizeof(*b));
    if(p2 == NULL)
        exit(1);
    poly_show(p1);
    poly_show(p2);
    poly_union(p1,p2);
    poly_show(p1);    
    return 0;
}

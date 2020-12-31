#include <stdio.h>
#include <stdlib.h>

#define FNAME "./out"


typedef struct node_st
{
    struct node_st *left;
    struct node_st *right;
    char data;
} TREE;

static TREE *tree = NULL;

int insert(TREE **root, int data)
{
    TREE *node;
    if(*root == NULL)
    {
        node = malloc(sizeof(*node));
        if(node == NULL)
            return -1;
        node->data = data;
        node->left = NULL;
        node->right = NULL;

        *root = node;
        return 0;
    }
    if(data <= (*root)->data)
        return insert(&((*root)->left), data);
    return insert(&((*root)->right), data);
}

static void draw_(TREE *root, int level)
{
    int i;
    if(root == NULL)
        return ;
    draw_(root->right, level+1);

    for(i = 0; i < level; i++)
        printf("    ");
    printf("%c\n", root->data);

    draw_(root->left, level+1);
}

void draw(TREE *root)
{
    draw_(root, 0);
    printf("-----------------------------\n");
    // getchar();
}
static int get_nodenum(TREE *root)
{
    if(root == NULL)
        return 0;
    
    return get_nodenum(root->left) + 1 + get_nodenum(root->right);
}

static TREE * find_min(TREE *root)
{
    if(root->left == NULL)
        return root;

    return find_min(root->left);
}

static TREE * find_max(TREE *root)
{
    if(root->right == NULL)
        return root;

    return find_max(root->right);
}

static void turn_left(TREE **root)
{
    TREE *cur = *root;
    *root = cur->right;
    cur->right = NULL;

    find_min(*root)->left = cur;
    // draw(tree);
}

static void turn_right(TREE **root)
{
    TREE *cur = *root;
    *root = cur->left;
    cur->left = NULL;

    find_max(*root)->right = cur;
    // draw(tree);
}


void balance(TREE **root)
{
    int sub;
    if(*root == NULL)
        return ;
    while(1)
    {
        sub = get_nodenum((*root)->left) - get_nodenum((*root)->right);
        if(sub >= -1 && sub <= 1)
            break;
        if(sub < -1) // right tree has more nodes
            turn_left(root);
        else        // left tree has more nodes
            turn_right(root);
    }

    balance(&(*root)->left);
    balance(&(*root)->right);
}

int save_(TREE *root, FILE *fp)
{
    fputc('(', fp);
    /*if error*/
    if(root == NULL)
    {
        fputc(')', fp);
        return 0;
    }

    fputc(root->data, fp);

    save_(root->left, fp);
    save_(root->right, fp);

    fputc(')', fp);
    return 0;
}

int save(TREE *root, const char *path)
{
    FILE *fp;

    fp = fopen(path, "w");
    if(fp == NULL)
    {
        printf("Something went wrong!\n");
        return -1;
    }
    save_(tree, fp);
    fclose(fp);
    return 0;
}
int main(int argc, char const *argv[])
{
    int i;
    char arr[] = "acebdfjh";

    for(i = 0; i < sizeof(arr)/sizeof(*arr)-1; i++)
    {
        
        insert(&tree, arr[i]);
    }  
    draw(tree);

    // balance(&tree);

    // draw(tree);

    save(tree, FNAME);

    return 0;
}

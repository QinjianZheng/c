#include <stdio.h>
#include <stdlib.h>
#define FNAME "./out"

typedef struct node_st
{
    struct node_st *left;
    struct node_st *right;
    char data;
} TREE;

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

TREE * load_(FILE *fp)
{
    int c;
    TREE *root;
    c = fgetc(fp);

    if(c != '(')
    {
        fprintf(stderr, "fgetc() failed.\n");
        exit(1);
    }

    c = fgetc(fp);
    if(c == ')')
        return NULL;
    
    root = malloc(sizeof(*root));
    if(root == NULL)
        exit(1);
    
    root->data = c;
    root->left = load_(fp);
    root->right = load_(fp);

    c = fgetc(fp);
    if(c != ')')
    {
        fprintf(stderr, "fgetc() failed.\n");
        exit(1);
    }
    return root;
}

TREE * load(const char *path)
{
    FILE *fp;
    TREE *root;

    fp = fopen(path, "r");
    if(fp == NULL)
        return NULL;

    root = load_(fp);

    fclose(fp);

    return root;
}


int main(int argc, char const *argv[])
{
    TREE *tree;
    
    tree = load(FNAME);
    
    draw(tree);

    return 0;
}

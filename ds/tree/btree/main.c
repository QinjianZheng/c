#include <stdio.h>
#include <stdlib.h>
#include <queue.h>

#define NAMESIZE 32
#define REPLACE_BY_LEFT_CHILD 1
#define REPLACE_BY_RIGHT_CHILD 2

typedef struct score_st
{
    int id;
    char name[NAMESIZE];
    int math;
} SCORE;

typedef struct node_st
{
    struct node_st *left;
    struct node_st *right;
    SCORE data;
} TREE;

static TREE *tree = NULL;


void print_score(SCORE *data)
{
    printf("%d %s %d\n", data->id, data->name, data->math);
}

int insert(TREE **root, SCORE *data)
{
    TREE *node;
    if(*root == NULL)
    {
        node = malloc(sizeof(*node));
        if(node == NULL)
            return -1;
        node->data = *data;
        node->left = NULL;
        node->right = NULL;

        *root = node;
        return 0;
    }
    if(data->id <= (*root)->data.id)
        return insert(&((*root)->left), data);
    return insert(&((*root)->right), data);
}

SCORE * find(TREE *root, int id)
{
    if(root == NULL)
        return NULL;
    if(id == root->data.id)
        return &root->data;
    else 
    {
        if(id < root->data.id)
            return find(root->left, id);
        else
            return find(root->right, id);
    }
}

static void draw_(TREE *root, int level)
{
    int i;
    if(root == NULL)
        return ;
    draw_(root->right, level+1);

    for(i = 0; i < level; i++)
        printf("    ");
    printf("%d\n", root->data.id);

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

void delete_replace_by_left(TREE **root, int id)
{
    TREE **cur = root;
    TREE *node_del = NULL;

    while((*cur) != NULL && (*cur)->data.id != id)
    {
        if(id < (*cur)->data.id)
            cur = &(*cur)->left;
        else
            cur = &(*cur)->right;
    }
    if(*cur == NULL)
        return ;
    
    node_del = *cur;

    if(node_del->left == NULL)
        *cur = node_del->right;
    else
    {
        *cur = node_del->left;
        find_max(node_del->left)->right = node_del->right;
    }
    free(node_del);
}

void delete_replace_by_right(TREE **root, int id)
{
    TREE **cur = root;
    TREE *node_del = NULL;

    while((*cur) != NULL && (*cur)->data.id != id)
    {
        if(id < (*cur)->data.id)
            cur = &(*cur)->left;
        else
            cur = &(*cur)->right;
    }
    if(*cur == NULL)
        return ;
    
    node_del = *cur;

    if(node_del->right == NULL)
        *cur = node_del->left;
    else
    {
        *cur = node_del->right;
        find_min(node_del->right)->left = node_del->left;
    }
    free(node_del);
    
}

void delete(TREE **root, int id, int mode)
{
    switch (mode)
    {
    case 1:
        delete_replace_by_left(root, id);
        break;
    case 2:
        delete_replace_by_right(root, id);
        break;
    default:
        printf("Incorrect mode!\n");
        break;
    }
}

void traverse_preorder(TREE *root)
{
    if(root == NULL)
        return;
    print_score(&root->data);
    traverse_preorder(root->left);
    traverse_preorder(root->right);

}

void traverse_inorder(TREE *root)
{
    if(root == NULL)
        return;
    
    traverse_inorder(root->left);
    print_score(&root->data);
    traverse_inorder(root->right);

}

void traverse_postorder(TREE *root)
{
    if(root == NULL)
        return;
    
    traverse_postorder(root->left);
    traverse_postorder(root->right);
    print_score(&root->data);

}

void traverse_byline(TREE *root)
{
    QUEUE *qu;
    TREE *cur;
    int ret;
    qu = queue_create(sizeof(TREE *));
    if(qu == NULL)
        return;

    queue_enqueue(qu, &root);
    /*if error*/
    while(1)
    {
        ret = queue_dequeue(qu, &cur);
        if(ret == -1)
            break;
        print_score(&cur->data);
        if(cur->left != NULL)
            queue_enqueue(qu, &cur->left);
        if(cur->right != NULL)
            queue_enqueue(qu, &cur->right);
    }
    queue_destroy(qu);
}

int main(int argc, char const *argv[])
{
    int i;
    int arr[] = {1,2,3,7,6,5,9,8,4};
    SCORE data, *data_find;
    int del_id = 5;
    for(i = 0; i < sizeof(arr)/sizeof(*arr); i++)
    {
        data.id = arr[i];
        snprintf(data.name, NAMESIZE, "stu%d", arr[i]);
        data.math = rand() % 100;
        
        insert(&tree, &data);
    }
#if 0
    int id_find = 10;
    data_find = find(tree, id_find);
    if(data_find == NULL)
        printf("Can not find id %d\n", id_find);
    else
        print_score(data_find);
#endif
    draw(tree);

    balance(&tree);

    draw(tree);
#if 0
    // delete(&tree, del_id, REPLACE_BY_LEFT_CHILD);
    delete(&tree, del_id, REPLACE_BY_RIGHT_CHILD);
    
    draw(tree);

    balance(&tree);
    
    draw(tree);
#endif

    traverse_byline(tree);

    return 0;
}

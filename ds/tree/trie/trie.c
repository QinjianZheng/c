#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DESC_SIZE   256
#define KEY_SIZE    256
#define BUF_SIZE    512
#define FNAME       "log"

struct node_st
{
    struct node_st *ch[26];
    char desc[DESC_SIZE];
};

//从文件中读取一行，分隔单词和描述
int get_word(FILE *fp, char *key, char *desc)
{
    char buffer[BUF_SIZE];
    char *retp;
    int i, j;

    retp = fgets(buffer, BUF_SIZE, fp);
    if(retp == NULL)
        return -1;
    
    for (i = 0; i < KEY_SIZE - 1 && buffer[i] != ':'; i++)
    {
        key[i] = buffer[i];
    }
    key[i] = '\0';

    i++;

    for(j = 0; j < DESC_SIZE - 1 && buffer[i] != '\0'; j++, i++)
        desc[j] = buffer[i];
    desc[j] = '\0';
    return 0;
}

struct node_st * new_node(void)
{
    struct node_st *node;
    int i;
    node = malloc(sizeof(*node));
    if(node == NULL)
        return NULL;
    
    node->desc[0] = '\0';
    
    for(i = 0; i < 26; i++)
        node->ch[i] = NULL;

    return node;
}

int insert(struct node_st **root, char *key, char *desc)
{
    if(*root == NULL)
    {
        *root = new_node();
        if(*root == NULL)
            return -1; 
    }
    if(*key == '\0')
    {
        strcpy((*root)->desc, desc);
        return 0;
    }

    return insert((*root)->ch+ *key - 'a', key+1, desc);
}

char * find(struct node_st *root, char *key)
{
    if(root == NULL)
        return NULL;
    
    if(*key == '\0')
        return root->desc;
    return find(root->ch[*key-'a'], key+1);
}

int main(int argc, char const *argv[])
{
    struct node_st *tree = NULL;
    char *datap;
    FILE *fp;
    char desc[DESC_SIZE], key[KEY_SIZE];
    int ret;
    char word[] = "ant";
    fp = fopen(FNAME, "r");
    if(fp == NULL)
    {
        fprintf(stderr, "fopen() failed.\n");
        exit(1);
    }
    
    while(1)
    {
        ret = get_word(fp,key,desc);
        if(ret == -1)
            break;
        insert(&tree, key, desc);
    }

    datap = find(tree, word);
    if(datap == NULL)
        printf("Not found %s!\n", word);
    else
        puts(datap);

    fclose(fp);

    return 0;
}

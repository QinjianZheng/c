#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dl_list.h"
#define NAMESIZE    32

struct score_st
{
    int id;
    char name[NAMESIZE];
    int math;
    int chinese;
};

static void print_score(const void *record)
{
    const struct score_st *r = record;
    printf("%d %s %d %d\n", r->id, r->name, r->math, r->chinese);
}

static int id_cmp(const void * key, const void * record)
{
    const int *k = key;
    const struct score_st *r = record;

    return (*k - r->id);
}

static int name_cmp(const void *key, const void * record)
{
    const char *k = key;
    const struct score_st *r = record;
    return strcmp(k, r->name);
}

int main(int argc, char const *argv[])
{
    DL_LIST *handler;
    struct score_st data, *data_find, *data_fetch;
    int ret, ret_del, ret_fetch;
    int id = 30;
    char *fetch_name = "std1";
    char *del_name = "std6";

//创建双向环链并插入数据
    handler = dl_list_create(sizeof(struct score_st));

    for(int i = 0; i < 7; i++)
    {
        data.id = i;
        snprintf(data.name, NAMESIZE, "std%d", i);
        data.math = rand() % 100;
        data.chinese = rand() % 100;

    ret = handler->insert(handler, &data, DL_LIST_BACKWARD);
    if(ret)
        exit(1);
    }
    handler->display(handler, print_score);


//销毁双向环链
    dl_list_destroy(handler);
    return 0;
}

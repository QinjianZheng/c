#ifndef DL_LIST_H__
#define DL_LIST_H__
#define DL_LIST_FORWARD     1
#define DL_LIST_BACKWARD    2

typedef void dl_list_op (const void *);
typedef int dl_list_cmp (const void *, const void *);

typedef struct dl_list_node_st
{
    struct dl_list_node_st *prev;
    struct dl_list_node_st *next;
    char data[0];
} NODE;
typedef struct
{
    int size;
    struct dl_list_node_st head;
} DL_LIST;

// 只有头结点的双向环链
DL_LIST * dl_list_create(int);

int dl_list_insert(DL_LIST *, const void *, int);

void * dl_list_find(DL_LIST *, const void *key, dl_list_cmp *);

int dl_list_fetch(DL_LIST *, const void *key, dl_list_cmp *, void *);

int dl_list_delete(DL_LIST *, const void *key, dl_list_cmp *);

// 使用回调函数传入函数
void dl_list_display(DL_LIST *, dl_list_op *);

void dl_list_destroy(DL_LIST *);


#endif
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
typedef struct dl_list_head
{
    int size;
    struct dl_list_node_st head;
    int (*insert) (struct dl_list_head *, const void *, int);
    void * (*find) (struct dl_list_head *, const void *key, dl_list_cmp *);
    int (*delele) (struct dl_list_head *, const void *key, dl_list_cmp *);
    int (*fetch) (struct dl_list_head *, const void *key, dl_list_cmp *, void *);
    void (*display) (struct dl_list_head *, dl_list_op *);
} DL_LIST;

// 只有头结点的双向环链
DL_LIST * dl_list_create(int);

void dl_list_destroy(DL_LIST *);


#endif
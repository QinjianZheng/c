#ifndef LIST_H__
#define LIST_H__

typedef int datatype;

typedef struct node_st
{
    datatype data;
    struct node_st *next;
    
} link_node;

link_node *list_create();

void list_destroy(link_node *);

int list_isinlist(link_node *me, datatype *data);

int list_insert_at(link_node *, int i, datatype *);

int list_insert_order(link_node *, datatype *);

int list_delete_at(link_node *, int i, datatype *);

int list_delete(link_node *, datatype *);

void list_display(link_node *);

int list_isempty(link_node *);

#endif
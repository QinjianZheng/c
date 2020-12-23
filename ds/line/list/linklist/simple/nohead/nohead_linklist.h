#ifndef NOHEAD_LINKLIST_H__
#define NOHEAD_LINKLIST_H__

#define NAMESIZE    32

typedef struct score_st
{
    int id;
    char name[NAMESIZE];
    int math;
    int chinese;
} score;

typedef struct node_st
{
    struct score_st data;
    struct node_st *next;
} nhlist;

// nhlist * nhlist_insert(nhlist *, score *);
int nhlist_insert(nhlist **, score *);

void nhlist_display(nhlist *);

int nhlist_delete(nhlist **);

// int nhlist_find(nhlist *, int);
score * nhlist_find(nhlist *, int);

void nhlist_destroy(nhlist *);

#endif
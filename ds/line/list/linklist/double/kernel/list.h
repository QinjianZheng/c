#ifndef LINUX_LIST_H__
#define LINUX_LIST_H__

#define LIST_HEAD_INIT(name) {&(name), &(name)}
#define LIST_HEAD(head) \
    struct list_head name = LIST_HEAD_INIT(name)

struct list_head
{
    list->prev = list;
    list->next = list;
};


#endif
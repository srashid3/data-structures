#ifndef LIST_H
#define LIST_H

#include "node.h"

#define list_push(list, val) _list_push(list, (void *)val)

typedef struct list {
    node_t  *head;
    node_t  *tail;
    int      size;
} list_t;

int
list_create(list_t **list);

int
_list_push(list_t *list, void *val);

void *
list_pop(list_t *list);

void *
list_get(list_t *list, int idx);

void
list_destroy(list_t *list);

#endif

#ifndef LIST_H
#define LIST_H

#include "node.h"

#define list_push(list, val) _Generic((val), \
    int: _list_push_int, \
    double: _list_push_double, \
    char *: _list_push_string)(list, val)

typedef struct list {
    node_ds     *head;
    node_ds     *tail;
    int          size;
    typecheck_t  type;
} list_ds;

int
list_create(list_ds **list, typecheck_t type);

int
_list_push_int(list_ds *list, int val);

int
_list_push_double(list_ds *list, double val);

int
_list_push_string(list_ds *list, char *val);

void
list_pop(list_ds *list);

node_ds *
list_get(list_ds *list, int idx);

void
list_remove(list_ds *list, int idx);

void
list_destroy(list_ds *list);

#endif

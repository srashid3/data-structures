#ifndef LIST_H
#define LIST_H

#include "node.h"

#define list_push(list, val) _Generic((val), \
    int: _list_push_int, \
    double: _list_push_double, \
    char *: _list_push_string)(list, val)

typedef struct list {
    node_t      *head;
    node_t      *tail;
    int          size;
    typecheck_t  type;
} list_t;

int
list_create(list_t **list, typecheck_t type);

int
_list_push_int(list_t *list, int val);

int
_list_push_double(list_t *list, double val);

int
_list_push_string(list_t *list, char *val);

void
list_pop(list_t *list);

node_t *
list_get(list_t *list, int idx);

void
list_remove(list_t *list, int idx);

void
list_destroy(list_t *list);

#endif
